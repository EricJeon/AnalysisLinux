/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/mtd.h>

/***********************************************************************
 * FLASH configuration
 ***********************************************************************/

struct mtd_partition dtv_fixed_nor_partition_map[] = {
        {
                .name = "loader",
                .size = 0x00120000,
                .offset = 0x00000000,
                .mask_flags = 0,  /* read-write, necessary for BIST */
        },
        {
                .name = "kernel",
                .size =   0x002A0000,
                .offset = 0x00120000,
                .mask_flags = MTD_WRITEABLE,  /* read-only */
        },
        {
                .name = "rootfs",
                .size = 0x02200000,
                .offset = 0x003C0000,
                .mask_flags = MTD_WRITEABLE  /* read-only */
        },
        {
                .name = "ssd",
                .size = MTDPART_SIZ_FULL,
                .offset = 0x025C0000,
                .mask_flags = 0  /* read-write */
        },
	{
		.name = "all",
		.size = MTDPART_SIZ_FULL,
		.offset = 0x00000000,
               .mask_flags = 0  /* read-write */
	},
};

/*
 * Use the partition map defined at compile time
 */
int __init dtv_get_partition_map(struct mtd_partition **p)
{
	*p = dtv_fixed_nor_partition_map;
	return ARRAY_SIZE(dtv_fixed_nor_partition_map);
}

int __init board_get_partition_map(struct mtd_partition **p)
{
       return dtv_get_partition_map(p);
}
