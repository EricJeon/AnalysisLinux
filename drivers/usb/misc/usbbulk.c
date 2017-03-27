#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/scatterlist.h>
#include <linux/mutex.h>

#include <linux/usb.h>

/*-------------------------------------------------------------------------*/

struct usbtest_info {
	const char		*name;
	u8			ep_in;		/* bulk/intr source */
	u8			ep_out;		/* bulk/intr sink */
};

/* this is accessed only through usbfs ioctl calls.
 * one ioctl to issue a test ... one lock per device.
 * tests create other threads if they need them.
 * urbs and buffers are allocated dynamically,
 * and data generated deterministically.
 */
struct usbtest_dev {
	struct usb_interface	*intf;
	struct usbtest_info	*info;
	int			in_pipe;
	int			out_pipe;
	struct mutex		lock;

#define TBUF_SIZE	256
	u8			*buf;
};

static struct usb_device *testdev_to_usbdev (struct usbtest_dev *test)
{
	return interface_to_usbdev (test->intf);
}

/* set up all urbs so they can be used with either bulk or interrupt */
#define	INTERRUPT_RATE		1	/* msec/transfer */

//#define USBBULK_DEBUG

#ifdef USBBULK_DEBUG
#define ERROR(tdev, fmt, args...) \
	dev_err(tdev, fmt , ## args)
#define WARNING(tdev, fmt, args...) \
	dev_warn(tdev, fmt , ## args)
#define INFO(tdev, fmt, args...) \
   dev_info(tdev, fmt, ## args)
#else
#define ERROR(tdev, fmt, args...)
#define WARNING(tdev, fmt, args...)
#define INFO(tdev, fmt, args...)
#endif

/* bulk test numbers */
#define USB_BULK_OUT 1
#define USB_BULK_IN  0

/*-------------------------------------------------------------------------*/

/* Support for testing basic non-queued I/O streams.
 *
 * These just package urbs as requests that can be easily canceled.
 * Each urb's data buffer is dynamically allocated; callers can fill
 * them with non-zero test data (or test for it) when appropriate.
 */

static void simple_callback (struct urb *urb)
{
	complete(urb->context);
}

static struct urb *simple_alloc_urb (
	struct usb_device	*udev,
	int			pipe,
	unsigned long		bytes
)
{
	struct urb		*urb;

	urb = usb_alloc_urb (0, GFP_KERNEL);
	if (!urb)
		return urb;
	usb_fill_bulk_urb (urb, udev, pipe, NULL, bytes, simple_callback, NULL);
	urb->interval = (udev->speed == USB_SPEED_HIGH)
			? (INTERRUPT_RATE << 3)
			: INTERRUPT_RATE;
	urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
	if (usb_pipein (pipe))
		urb->transfer_flags |= URB_SHORT_NOT_OK;
	urb->transfer_buffer = usb_alloc_coherent(udev, bytes, GFP_KERNEL,
			&urb->transfer_dma);
	if (!urb->transfer_buffer) {
		usb_free_urb (urb);
		urb = NULL;
	} else
		memset (urb->transfer_buffer, 0, bytes);
	return urb;
}

static inline void simple_fill_buf (struct urb *urb)
{
	unsigned	i;
	u8		*buf = urb->transfer_buffer;
	unsigned	len = urb->transfer_buffer_length;

	for (i = 0; i < len; i++)
      *buf++ = (u8) (i % 63);
}

static void simple_free_urb (struct urb *urb)
{
	usb_free_coherent(urb->dev, urb->transfer_buffer_length,
			urb->transfer_buffer, urb->transfer_dma);
	usb_free_urb (urb);
}

static int simple_io (
	struct usbtest_dev  *tdev,
	struct urb		     *urb,
	unsigned long	     iterations,
	const char		     *label
)
{
	struct usb_device	*udev = urb->dev;
	int			max = urb->transfer_buffer_length;
	struct completion	completion;
	int			retval = 0;
	cputime_t pstime;
	cputime_t cstime;
   unsigned long lastJiffies;
   int errors = 0;

   /* we only need to fill the buffer once */
   if (usb_pipeout (urb->pipe))
      simple_fill_buf (urb);

   /* make our jiffies/stime clock start at 0 before the loop */
   lastJiffies = jiffies;
   pstime = current->stime;

	urb->context = &completion;
	while (retval == 0 && (iterations-- > 0) )
	{
	   /* we get an average over all loops by just using the whole time period */
	   cstime = current->stime;
	   ((uint8_t*)urb->transfer_buffer)[0] = (cputime_to_jiffies(cstime - pstime)*100) / ((jiffies-lastJiffies) + cputime_to_jiffies(cstime - pstime));

		init_completion (&completion);

		if ((retval = usb_submit_urb (urb, GFP_KERNEL)) != 0)
			break;

		/* NOTE:  no timeouts; can't be broken out of by interrupt */
		wait_for_completion (&completion);

		/* Read could fail the first few times */
		if (urb->status)
		{
		   errors++;
		   if (errors == 10)
		   {
		      retval = urb->status;
		   }
		}
		urb->dev = udev;
	}
	urb->transfer_buffer_length = max;

	return retval;
}

/*-------------------------------------------------------------------------*/

/* We only have this one interface to user space, through usbfs.
 * User mode code can scan usbfs to find N different devices (maybe on
 * different busses) to use when testing, and allocate one thread per
 * test.  So discovery is simplified, and we have no device naming issues.
 *
 * Don't use these only as stress/load tests.  Use them along with with
 * other USB bus activity:  plugging, unplugging, mousing, mp3 playback,
 * video capture, and so on.  Run different tests at different times, in
 * different sequences.  Nothing here should interact with other devices,
 * except indirectly by consuming USB bandwidth and CPU resources for test
 * threads and request completion.  But the only way to know that for sure
 * is to test when HC queues are in use by many devices.
 *
 * WARNING:  Because usbfs grabs udev->dev.sem before calling this ioctl(),
 * it locks out usbcore in certain code paths.  Notably, if you disconnect
 * the device-under-test, khubd will wait block forever waiting for the
 * ioctl to complete ... so that usb_disconnect() can abort the pending
 * urbs and then call usbtest_disconnect().  To abort a test, you're best
 * off just killing the userspace task and waiting for it to exit.
 */

static int
usbtest_ioctl (struct usb_interface *intf, unsigned int code, void *buf)
{
	struct usbtest_dev	*dev = usb_get_intfdata (intf);
	struct usb_device	*udev = testdev_to_usbdev (dev);
	int retval = -EFAULT;
	struct urb *urb;

	if (mutex_lock_interruptible(&dev->lock))
		return -ERESTARTSYS;

	switch (code)
	{
      /* DIRECTV bulk I/O tests */
      case USB_BULK_OUT:
         if (dev->out_pipe == 0)
            break;
         INFO(&intf->dev,
               "Bulk OUT Test:  write %u bytes %u times\n",
               0xFF00, 0x1000);
         urb = simple_alloc_urb (udev, dev->out_pipe, 0xFF00);
         if (!urb) {
            retval = -ENOMEM;
            break;
         }
         // FIRMWARE:  bulk sink (maybe accepts short writes)
         retval = simple_io(dev, urb, 0x1000, "BULK OUT");
         simple_free_urb (urb);
         break;
      case USB_BULK_IN:
         if (dev->in_pipe == 0)
            break;
         INFO(&intf->dev,
               "Bulk IN Test:  read %u bytes %u times\n",
               0xFF00, 0x1000);
         urb = simple_alloc_urb (udev, dev->in_pipe, 0xFF00);
         if (!urb) {
            retval = -ENOMEM;
            break;
         }
         // FIRMWARE:  bulk source (maybe generates short writes)
         retval = simple_io(dev, urb, 0x1000, "BULK IN");
         simple_free_urb (urb);
         break;
      default:
         ERROR(&intf->dev, "Test %d is invalid\n", code);
         retval = -EOPNOTSUPP;
	}

	mutex_unlock(&dev->lock);
	return retval;
}

/*-------------------------------------------------------------------------*/

static int
usbtest_probe (struct usb_interface *intf, const struct usb_device_id *id)
{
	struct usb_device	*udev;
	struct usbtest_dev	*dev;
	struct usbtest_info	*info;
	char			*rtest, *wtest;
	char			*irtest, *iwtest;

	udev = interface_to_usbdev (intf);

	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;
	info = (struct usbtest_info *) id->driver_info;
	dev->info = info;
	mutex_init(&dev->lock);

	dev->intf = intf;

	/* cacheline-aligned scratch for i/o */
	if ((dev->buf = kmalloc (TBUF_SIZE, GFP_KERNEL)) == NULL) {
		kfree (dev);
		return -ENOMEM;
	}

	/* NOTE this doesn't yet test the handful of difference that are
	 * visible with high speed interrupts:  bigger maxpacket (1K) and
	 * "high bandwidth" modes (up to 3 packets/uframe).
	 */
	rtest = wtest = "";
	irtest = iwtest = "";

   if (info->ep_in)
      dev->in_pipe = usb_rcvbulkpipe (udev,
               info->ep_in);
   if (info->ep_out)
      dev->out_pipe = usb_sndbulkpipe (udev,
               info->ep_out);
   if (dev->in_pipe)
      rtest = " bulk-in";
   if (dev->out_pipe)
      wtest = " bulk-out";

	usb_set_intfdata (intf, dev);
	INFO (&intf->dev, "%s\n", info->name);
	INFO (&intf->dev, "%s speed {control%s%s%s%s}\n",
			({ char *tmp;
			switch (udev->speed) {
			case USB_SPEED_LOW: tmp = "low"; break;
			case USB_SPEED_FULL: tmp = "full"; break;
			case USB_SPEED_HIGH: tmp = "high"; break;
			default: tmp = "unknown"; break;
			}; tmp; }),
			rtest, wtest,
			irtest, iwtest);
	return 0;
}

static int usbtest_suspend (struct usb_interface *intf, pm_message_t message)
{
	return 0;
}

static int usbtest_resume (struct usb_interface *intf)
{
	return 0;
}

static void usbtest_disconnect (struct usb_interface *intf)
{
	struct usbtest_dev	*dev = usb_get_intfdata (intf);

	usb_set_intfdata (intf, NULL);
	INFO(&intf->dev, "disconnect\n");
	kfree (dev);
}

/* we can use any device to test control traffic */
static struct usbtest_info net2280_info = {
   .name     = "PLX NET2280 BULK TEST",
   .ep_in    = 0x82,
   .ep_out   = 0x01
};

static struct usb_device_id id_table [] = {

   /* PLX NET2280 for DIRECTV Bulk Tests */
   { USB_DEVICE (0x0525, 0x1000),
      .driver_info = (unsigned long) &net2280_info,
      },

   {}
};
MODULE_DEVICE_TABLE (usb, id_table);

static struct usb_driver usbtest_driver = {
	.name =		"usbbulk",
	.id_table =	id_table,
	.probe =	usbtest_probe,
	.unlocked_ioctl = usbtest_ioctl,
	.disconnect =	usbtest_disconnect,
	.suspend =	usbtest_suspend,
	.resume =	usbtest_resume,
};

/*-------------------------------------------------------------------------*/

static int __init usbtest_init (void)
{
	return usb_register (&usbtest_driver);
}
module_init (usbtest_init);

static void __exit usbtest_exit (void)
{
	usb_deregister (&usbtest_driver);
}
module_exit (usbtest_exit);

MODULE_DESCRIPTION ("DIRECTV USB Bulk Testing Driver");
MODULE_LICENSE ("GPL");

