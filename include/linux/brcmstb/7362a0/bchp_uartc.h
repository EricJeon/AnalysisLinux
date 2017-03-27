/***************************************************************************
 *     Copyright (c) 1999-2013, Broadcom Corporation
 *
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
 *
 * Module Description:
 *                     DO NOT EDIT THIS FILE DIRECTLY
 *
 * This module was generated magically with RDB from a source description
 * file. You must edit the source file for changes to be made to this file.
 *
 *
 * Date:           Generated on         Wed Apr 24 17:25:42 2013
 *                 MD5 Checksum         d41d8cd98f00b204e9800998ecf8427e
 *
 * Compiled with:  RDB Utility          combo_header.pl
 *                 RDB Parser           3.0
 *                 unknown              unknown
 *                 Perl Interpreter     5.008005
 *                 Operating System     linux
 *
 * Revision History:
 *
 * $brcm_Log: $
 *
 ***************************************************************************/

#ifndef BCHP_UARTC_H__
#define BCHP_UARTC_H__

/***************************************************************************
 *UARTC - UART C
 ***************************************************************************/
#define BCHP_UARTC_RBR                           0x00406880 /* Receive Buffer Register */
#define BCHP_UARTC_THR                           0x00406880 /* Transmit Holding Register */
#define BCHP_UARTC_DLH                           0x00406884 /* Divisor Latch High */
#define BCHP_UARTC_DLL                           0x00406880 /* Divisor Latch Low */
#define BCHP_UARTC_IER                           0x00406884 /* Interrupt Enable Register */
#define BCHP_UARTC_IIR                           0x00406888 /* Interrupt Identity Register */
#define BCHP_UARTC_FCR                           0x00406888 /* FIFO Control Register */
#define BCHP_UARTC_LCR                           0x0040688c /* Line Control Register */
#define BCHP_UARTC_MCR                           0x00406890 /* Modem Control Register */
#define BCHP_UARTC_LSR                           0x00406894 /* Line Status Register */
#define BCHP_UARTC_MSR                           0x00406898 /* Modem Status Register */
#define BCHP_UARTC_SCR                           0x0040689c /* Scratchpad Register */

/***************************************************************************
 *RBR - Receive Buffer Register
 ***************************************************************************/
/* UARTC :: RBR :: reserved0 [31:08] */
#define BCHP_UARTC_RBR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_RBR_reserved0_SHIFT                             8

/* UARTC :: RBR :: RBR [07:00] */
#define BCHP_UARTC_RBR_RBR_MASK                                    0x000000ff
#define BCHP_UARTC_RBR_RBR_SHIFT                                   0
#define BCHP_UARTC_RBR_RBR_DEFAULT                                 0x00000000

/***************************************************************************
 *THR - Transmit Holding Register
 ***************************************************************************/
/* UARTC :: THR :: reserved0 [31:08] */
#define BCHP_UARTC_THR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_THR_reserved0_SHIFT                             8

/* UARTC :: THR :: THR [07:00] */
#define BCHP_UARTC_THR_THR_MASK                                    0x000000ff
#define BCHP_UARTC_THR_THR_SHIFT                                   0
#define BCHP_UARTC_THR_THR_DEFAULT                                 0x00000000

/***************************************************************************
 *DLH - Divisor Latch High
 ***************************************************************************/
/* UARTC :: DLH :: reserved0 [31:08] */
#define BCHP_UARTC_DLH_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_DLH_reserved0_SHIFT                             8

/* UARTC :: DLH :: DLH [07:00] */
#define BCHP_UARTC_DLH_DLH_MASK                                    0x000000ff
#define BCHP_UARTC_DLH_DLH_SHIFT                                   0
#define BCHP_UARTC_DLH_DLH_DEFAULT                                 0x00000000

/***************************************************************************
 *DLL - Divisor Latch Low
 ***************************************************************************/
/* UARTC :: DLL :: reserved0 [31:08] */
#define BCHP_UARTC_DLL_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_DLL_reserved0_SHIFT                             8

/* UARTC :: DLL :: DLL [07:00] */
#define BCHP_UARTC_DLL_DLL_MASK                                    0x000000ff
#define BCHP_UARTC_DLL_DLL_SHIFT                                   0
#define BCHP_UARTC_DLL_DLL_DEFAULT                                 0x00000000

/***************************************************************************
 *IER - Interrupt Enable Register
 ***************************************************************************/
/* UARTC :: IER :: reserved0 [31:08] */
#define BCHP_UARTC_IER_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_IER_reserved0_SHIFT                             8

/* UARTC :: IER :: PTIME [07:07] */
#define BCHP_UARTC_IER_PTIME_MASK                                  0x00000080
#define BCHP_UARTC_IER_PTIME_SHIFT                                 7
#define BCHP_UARTC_IER_PTIME_DEFAULT                               0x00000000

/* UARTC :: IER :: reserved1 [06:04] */
#define BCHP_UARTC_IER_reserved1_MASK                              0x00000070
#define BCHP_UARTC_IER_reserved1_SHIFT                             4

/* UARTC :: IER :: EDSSI [03:03] */
#define BCHP_UARTC_IER_EDSSI_MASK                                  0x00000008
#define BCHP_UARTC_IER_EDSSI_SHIFT                                 3
#define BCHP_UARTC_IER_EDSSI_DEFAULT                               0x00000000

/* UARTC :: IER :: ELSI [02:02] */
#define BCHP_UARTC_IER_ELSI_MASK                                   0x00000004
#define BCHP_UARTC_IER_ELSI_SHIFT                                  2
#define BCHP_UARTC_IER_ELSI_DEFAULT                                0x00000000

/* UARTC :: IER :: ETBEI [01:01] */
#define BCHP_UARTC_IER_ETBEI_MASK                                  0x00000002
#define BCHP_UARTC_IER_ETBEI_SHIFT                                 1
#define BCHP_UARTC_IER_ETBEI_DEFAULT                               0x00000000

/* UARTC :: IER :: ERBFI [00:00] */
#define BCHP_UARTC_IER_ERBFI_MASK                                  0x00000001
#define BCHP_UARTC_IER_ERBFI_SHIFT                                 0
#define BCHP_UARTC_IER_ERBFI_DEFAULT                               0x00000000

/***************************************************************************
 *IIR - Interrupt Identity Register
 ***************************************************************************/
/* UARTC :: IIR :: reserved0 [31:08] */
#define BCHP_UARTC_IIR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_IIR_reserved0_SHIFT                             8

/* UARTC :: IIR :: FIFOSE [07:06] */
#define BCHP_UARTC_IIR_FIFOSE_MASK                                 0x000000c0
#define BCHP_UARTC_IIR_FIFOSE_SHIFT                                6
#define BCHP_UARTC_IIR_FIFOSE_DEFAULT                              0x00000000

/* UARTC :: IIR :: reserved1 [05:04] */
#define BCHP_UARTC_IIR_reserved1_MASK                              0x00000030
#define BCHP_UARTC_IIR_reserved1_SHIFT                             4

/* UARTC :: IIR :: IID [03:00] */
#define BCHP_UARTC_IIR_IID_MASK                                    0x0000000f
#define BCHP_UARTC_IIR_IID_SHIFT                                   0
#define BCHP_UARTC_IIR_IID_DEFAULT                                 0x00000001

/***************************************************************************
 *FCR - FIFO Control Register
 ***************************************************************************/
/* UARTC :: FCR :: reserved0 [31:08] */
#define BCHP_UARTC_FCR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_FCR_reserved0_SHIFT                             8

/* UARTC :: FCR :: RT [07:06] */
#define BCHP_UARTC_FCR_RT_MASK                                     0x000000c0
#define BCHP_UARTC_FCR_RT_SHIFT                                    6
#define BCHP_UARTC_FCR_RT_DEFAULT                                  0x00000000

/* UARTC :: FCR :: TET [05:04] */
#define BCHP_UARTC_FCR_TET_MASK                                    0x00000030
#define BCHP_UARTC_FCR_TET_SHIFT                                   4
#define BCHP_UARTC_FCR_TET_DEFAULT                                 0x00000000

/* UARTC :: FCR :: DMAM [03:03] */
#define BCHP_UARTC_FCR_DMAM_MASK                                   0x00000008
#define BCHP_UARTC_FCR_DMAM_SHIFT                                  3
#define BCHP_UARTC_FCR_DMAM_DEFAULT                                0x00000000

/* UARTC :: FCR :: XFIFOR [02:02] */
#define BCHP_UARTC_FCR_XFIFOR_MASK                                 0x00000004
#define BCHP_UARTC_FCR_XFIFOR_SHIFT                                2
#define BCHP_UARTC_FCR_XFIFOR_DEFAULT                              0x00000000

/* UARTC :: FCR :: RFIFOR [01:01] */
#define BCHP_UARTC_FCR_RFIFOR_MASK                                 0x00000002
#define BCHP_UARTC_FCR_RFIFOR_SHIFT                                1
#define BCHP_UARTC_FCR_RFIFOR_DEFAULT                              0x00000000

/* UARTC :: FCR :: FIFOE [00:00] */
#define BCHP_UARTC_FCR_FIFOE_MASK                                  0x00000001
#define BCHP_UARTC_FCR_FIFOE_SHIFT                                 0
#define BCHP_UARTC_FCR_FIFOE_DEFAULT                               0x00000000

/***************************************************************************
 *LCR - Line Control Register
 ***************************************************************************/
/* UARTC :: LCR :: reserved0 [31:08] */
#define BCHP_UARTC_LCR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_LCR_reserved0_SHIFT                             8

/* UARTC :: LCR :: DLAB [07:07] */
#define BCHP_UARTC_LCR_DLAB_MASK                                   0x00000080
#define BCHP_UARTC_LCR_DLAB_SHIFT                                  7
#define BCHP_UARTC_LCR_DLAB_DEFAULT                                0x00000000

/* UARTC :: LCR :: BC [06:06] */
#define BCHP_UARTC_LCR_BC_MASK                                     0x00000040
#define BCHP_UARTC_LCR_BC_SHIFT                                    6
#define BCHP_UARTC_LCR_BC_DEFAULT                                  0x00000000

/* UARTC :: LCR :: reserved1 [05:05] */
#define BCHP_UARTC_LCR_reserved1_MASK                              0x00000020
#define BCHP_UARTC_LCR_reserved1_SHIFT                             5

/* UARTC :: LCR :: EPS [04:04] */
#define BCHP_UARTC_LCR_EPS_MASK                                    0x00000010
#define BCHP_UARTC_LCR_EPS_SHIFT                                   4
#define BCHP_UARTC_LCR_EPS_DEFAULT                                 0x00000000

/* UARTC :: LCR :: PEN [03:03] */
#define BCHP_UARTC_LCR_PEN_MASK                                    0x00000008
#define BCHP_UARTC_LCR_PEN_SHIFT                                   3
#define BCHP_UARTC_LCR_PEN_DEFAULT                                 0x00000000

/* UARTC :: LCR :: STOP [02:02] */
#define BCHP_UARTC_LCR_STOP_MASK                                   0x00000004
#define BCHP_UARTC_LCR_STOP_SHIFT                                  2
#define BCHP_UARTC_LCR_STOP_DEFAULT                                0x00000000

/* UARTC :: LCR :: DLS [01:00] */
#define BCHP_UARTC_LCR_DLS_MASK                                    0x00000003
#define BCHP_UARTC_LCR_DLS_SHIFT                                   0
#define BCHP_UARTC_LCR_DLS_DEFAULT                                 0x00000000

/***************************************************************************
 *MCR - Modem Control Register
 ***************************************************************************/
/* UARTC :: MCR :: reserved0 [31:07] */
#define BCHP_UARTC_MCR_reserved0_MASK                              0xffffff80
#define BCHP_UARTC_MCR_reserved0_SHIFT                             7

/* UARTC :: MCR :: SIRE [06:06] */
#define BCHP_UARTC_MCR_SIRE_MASK                                   0x00000040
#define BCHP_UARTC_MCR_SIRE_SHIFT                                  6
#define BCHP_UARTC_MCR_SIRE_DEFAULT                                0x00000000

/* UARTC :: MCR :: AFCE [05:05] */
#define BCHP_UARTC_MCR_AFCE_MASK                                   0x00000020
#define BCHP_UARTC_MCR_AFCE_SHIFT                                  5
#define BCHP_UARTC_MCR_AFCE_DEFAULT                                0x00000000

/* UARTC :: MCR :: LB [04:04] */
#define BCHP_UARTC_MCR_LB_MASK                                     0x00000010
#define BCHP_UARTC_MCR_LB_SHIFT                                    4
#define BCHP_UARTC_MCR_LB_DEFAULT                                  0x00000000

/* UARTC :: MCR :: OUT2 [03:03] */
#define BCHP_UARTC_MCR_OUT2_MASK                                   0x00000008
#define BCHP_UARTC_MCR_OUT2_SHIFT                                  3
#define BCHP_UARTC_MCR_OUT2_DEFAULT                                0x00000000

/* UARTC :: MCR :: OUT1 [02:02] */
#define BCHP_UARTC_MCR_OUT1_MASK                                   0x00000004
#define BCHP_UARTC_MCR_OUT1_SHIFT                                  2
#define BCHP_UARTC_MCR_OUT1_DEFAULT                                0x00000000

/* UARTC :: MCR :: RTS [01:01] */
#define BCHP_UARTC_MCR_RTS_MASK                                    0x00000002
#define BCHP_UARTC_MCR_RTS_SHIFT                                   1
#define BCHP_UARTC_MCR_RTS_DEFAULT                                 0x00000000

/* UARTC :: MCR :: DTR [00:00] */
#define BCHP_UARTC_MCR_DTR_MASK                                    0x00000001
#define BCHP_UARTC_MCR_DTR_SHIFT                                   0
#define BCHP_UARTC_MCR_DTR_DEFAULT                                 0x00000000

/***************************************************************************
 *LSR - Line Status Register
 ***************************************************************************/
/* UARTC :: LSR :: reserved0 [31:08] */
#define BCHP_UARTC_LSR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_LSR_reserved0_SHIFT                             8

/* UARTC :: LSR :: RFE [07:07] */
#define BCHP_UARTC_LSR_RFE_MASK                                    0x00000080
#define BCHP_UARTC_LSR_RFE_SHIFT                                   7
#define BCHP_UARTC_LSR_RFE_DEFAULT                                 0x00000000

/* UARTC :: LSR :: TEMT [06:06] */
#define BCHP_UARTC_LSR_TEMT_MASK                                   0x00000040
#define BCHP_UARTC_LSR_TEMT_SHIFT                                  6
#define BCHP_UARTC_LSR_TEMT_DEFAULT                                0x00000001

/* UARTC :: LSR :: THRE [05:05] */
#define BCHP_UARTC_LSR_THRE_MASK                                   0x00000020
#define BCHP_UARTC_LSR_THRE_SHIFT                                  5
#define BCHP_UARTC_LSR_THRE_DEFAULT                                0x00000001

/* UARTC :: LSR :: BI [04:04] */
#define BCHP_UARTC_LSR_BI_MASK                                     0x00000010
#define BCHP_UARTC_LSR_BI_SHIFT                                    4
#define BCHP_UARTC_LSR_BI_DEFAULT                                  0x00000000

/* UARTC :: LSR :: FE [03:03] */
#define BCHP_UARTC_LSR_FE_MASK                                     0x00000008
#define BCHP_UARTC_LSR_FE_SHIFT                                    3
#define BCHP_UARTC_LSR_FE_DEFAULT                                  0x00000000

/* UARTC :: LSR :: PE [02:02] */
#define BCHP_UARTC_LSR_PE_MASK                                     0x00000004
#define BCHP_UARTC_LSR_PE_SHIFT                                    2
#define BCHP_UARTC_LSR_PE_DEFAULT                                  0x00000000

/* UARTC :: LSR :: OE [01:01] */
#define BCHP_UARTC_LSR_OE_MASK                                     0x00000002
#define BCHP_UARTC_LSR_OE_SHIFT                                    1
#define BCHP_UARTC_LSR_OE_DEFAULT                                  0x00000000

/* UARTC :: LSR :: DR [00:00] */
#define BCHP_UARTC_LSR_DR_MASK                                     0x00000001
#define BCHP_UARTC_LSR_DR_SHIFT                                    0
#define BCHP_UARTC_LSR_DR_DEFAULT                                  0x00000000

/***************************************************************************
 *MSR - Modem Status Register
 ***************************************************************************/
/* UARTC :: MSR :: reserved0 [31:08] */
#define BCHP_UARTC_MSR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_MSR_reserved0_SHIFT                             8

/* UARTC :: MSR :: DCD [07:07] */
#define BCHP_UARTC_MSR_DCD_MASK                                    0x00000080
#define BCHP_UARTC_MSR_DCD_SHIFT                                   7
#define BCHP_UARTC_MSR_DCD_DEFAULT                                 0x00000000

/* UARTC :: MSR :: RI [06:06] */
#define BCHP_UARTC_MSR_RI_MASK                                     0x00000040
#define BCHP_UARTC_MSR_RI_SHIFT                                    6
#define BCHP_UARTC_MSR_RI_DEFAULT                                  0x00000000

/* UARTC :: MSR :: DSR [05:05] */
#define BCHP_UARTC_MSR_DSR_MASK                                    0x00000020
#define BCHP_UARTC_MSR_DSR_SHIFT                                   5
#define BCHP_UARTC_MSR_DSR_DEFAULT                                 0x00000000

/* UARTC :: MSR :: CTS [04:04] */
#define BCHP_UARTC_MSR_CTS_MASK                                    0x00000010
#define BCHP_UARTC_MSR_CTS_SHIFT                                   4
#define BCHP_UARTC_MSR_CTS_DEFAULT                                 0x00000000

/* UARTC :: MSR :: DDCD [03:03] */
#define BCHP_UARTC_MSR_DDCD_MASK                                   0x00000008
#define BCHP_UARTC_MSR_DDCD_SHIFT                                  3
#define BCHP_UARTC_MSR_DDCD_DEFAULT                                0x00000000

/* UARTC :: MSR :: TERI [02:02] */
#define BCHP_UARTC_MSR_TERI_MASK                                   0x00000004
#define BCHP_UARTC_MSR_TERI_SHIFT                                  2
#define BCHP_UARTC_MSR_TERI_DEFAULT                                0x00000000

/* UARTC :: MSR :: DDSR [01:01] */
#define BCHP_UARTC_MSR_DDSR_MASK                                   0x00000002
#define BCHP_UARTC_MSR_DDSR_SHIFT                                  1
#define BCHP_UARTC_MSR_DDSR_DEFAULT                                0x00000000

/* UARTC :: MSR :: DCTS [00:00] */
#define BCHP_UARTC_MSR_DCTS_MASK                                   0x00000001
#define BCHP_UARTC_MSR_DCTS_SHIFT                                  0
#define BCHP_UARTC_MSR_DCTS_DEFAULT                                0x00000000

/***************************************************************************
 *SCR - Scratchpad Register
 ***************************************************************************/
/* UARTC :: SCR :: reserved0 [31:08] */
#define BCHP_UARTC_SCR_reserved0_MASK                              0xffffff00
#define BCHP_UARTC_SCR_reserved0_SHIFT                             8

/* UARTC :: SCR :: SCR [07:00] */
#define BCHP_UARTC_SCR_SCR_MASK                                    0x000000ff
#define BCHP_UARTC_SCR_SCR_SHIFT                                   0
#define BCHP_UARTC_SCR_SCR_DEFAULT                                 0x00000000

#endif /* #ifndef BCHP_UARTC_H__ */

/* End of File */
