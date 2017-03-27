/***************************************************************************
 *     Copyright (c) 1999-2012, Broadcom Corporation
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
 * Date:           Generated on         Sat May  5 03:07:17 2012
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

#ifndef BCHP_SATA_TOP_CTRL_H__
#define BCHP_SATA_TOP_CTRL_H__

/***************************************************************************
 *SATA_TOP_CTRL - SATA3 MISC Control Registers
 ***************************************************************************/
#define BCHP_SATA_TOP_CTRL_Version               0x00180020 /* SATA3 Version Register */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL              0x00180024 /* SATA3 System Bus Access Control Register */
#define BCHP_SATA_TOP_CTRL_TP_CTRL               0x00180028 /* SATA3 Test Port Control register */
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_1            0x0018002c /* SATA3 phy interface control 1 */
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_2            0x00180030 /* SATA3 phy interface control 2 */
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_3            0x00180034 /* SATA3 phy interface control 3 */
#define BCHP_SATA_TOP_CTRL_SATA_TP_OUT           0x00180038 /* SATA3 TP OUT */

/***************************************************************************
 *Version - SATA3 Version Register
 ***************************************************************************/
/* SATA_TOP_CTRL :: Version :: reserved0 [31:08] */
#define BCHP_SATA_TOP_CTRL_Version_reserved0_MASK                  0xffffff00
#define BCHP_SATA_TOP_CTRL_Version_reserved0_SHIFT                 8

/* SATA_TOP_CTRL :: Version :: major_version [07:04] */
#define BCHP_SATA_TOP_CTRL_Version_major_version_MASK              0x000000f0
#define BCHP_SATA_TOP_CTRL_Version_major_version_SHIFT             4
#define BCHP_SATA_TOP_CTRL_Version_major_version_DEFAULT           0x00000000

/* SATA_TOP_CTRL :: Version :: minor_version [03:00] */
#define BCHP_SATA_TOP_CTRL_Version_minor_version_MASK              0x0000000f
#define BCHP_SATA_TOP_CTRL_Version_minor_version_SHIFT             0
#define BCHP_SATA_TOP_CTRL_Version_minor_version_DEFAULT           0x00000001

/***************************************************************************
 *BUS_CTRL - SATA3 System Bus Access Control Register
 ***************************************************************************/
/* SATA_TOP_CTRL :: BUS_CTRL :: bus_ctrl_31_17 [31:17] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_bus_ctrl_31_17_MASK            0xfffe0000
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_bus_ctrl_31_17_SHIFT           17
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_bus_ctrl_31_17_DEFAULT         0x00000000

/* SATA_TOP_CTRL :: BUS_CTRL :: overide_hwinit_registers [16:16] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_overide_hwinit_registers_MASK  0x00010000
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_overide_hwinit_registers_SHIFT 16
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_overide_hwinit_registers_DEFAULT 0x00000000

/* SATA_TOP_CTRL :: BUS_CTRL :: bus_ctrl_15_8 [15:08] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_bus_ctrl_15_8_MASK             0x0000ff00
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_bus_ctrl_15_8_SHIFT            8
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_bus_ctrl_15_8_DEFAULT          0x00000000

/* SATA_TOP_CTRL :: BUS_CTRL :: piodata_endian_ctrl [07:06] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_piodata_endian_ctrl_MASK       0x000000c0
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_piodata_endian_ctrl_SHIFT      6
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_piodata_endian_ctrl_DEFAULT    0x00000000
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_piodata_endian_ctrl_SwapEndianess 2
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_piodata_endian_ctrl_HalfWordSwap 1
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_piodata_endian_ctrl_NoSwap     0

/* SATA_TOP_CTRL :: BUS_CTRL :: dmadata_endian_ctrl [05:04] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadata_endian_ctrl_MASK       0x00000030
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadata_endian_ctrl_SHIFT      4
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadata_endian_ctrl_DEFAULT    0x00000000
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadata_endian_ctrl_SwapEndianess 2
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadata_endian_ctrl_HalfWordSwap 1
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadata_endian_ctrl_NoSwap     0

/* SATA_TOP_CTRL :: BUS_CTRL :: dmadesc_endian_ctrl [03:02] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadesc_endian_ctrl_MASK       0x0000000c
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadesc_endian_ctrl_SHIFT      2
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadesc_endian_ctrl_DEFAULT    0x00000000
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadesc_endian_ctrl_SwapEndianess 2
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadesc_endian_ctrl_HalfWordSwap 1
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_dmadesc_endian_ctrl_NoSwap     0

/* SATA_TOP_CTRL :: BUS_CTRL :: reg_endian_ctrl [01:00] */
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_reg_endian_ctrl_MASK           0x00000003
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_reg_endian_ctrl_SHIFT          0
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_reg_endian_ctrl_DEFAULT        0x00000000
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_reg_endian_ctrl_SwapEndianess  2
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_reg_endian_ctrl_HalfWordSwap   1
#define BCHP_SATA_TOP_CTRL_BUS_CTRL_reg_endian_ctrl_NoSwap         0

/***************************************************************************
 *TP_CTRL - SATA3 Test Port Control register
 ***************************************************************************/
/* SATA_TOP_CTRL :: TP_CTRL :: tp_ctrl [31:00] */
#define BCHP_SATA_TOP_CTRL_TP_CTRL_tp_ctrl_MASK                    0xffffffff
#define BCHP_SATA_TOP_CTRL_TP_CTRL_tp_ctrl_SHIFT                   0
#define BCHP_SATA_TOP_CTRL_TP_CTRL_tp_ctrl_DEFAULT                 0x00000000

/***************************************************************************
 *PHY_CTRL_1 - SATA3 phy interface control 1
 ***************************************************************************/
/* SATA_TOP_CTRL :: PHY_CTRL_1 :: phy_ctrl [31:00] */
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_1_phy_ctrl_MASK                0xffffffff
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_1_phy_ctrl_SHIFT               0
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_1_phy_ctrl_DEFAULT             0x00000000

/***************************************************************************
 *PHY_CTRL_2 - SATA3 phy interface control 2
 ***************************************************************************/
/* SATA_TOP_CTRL :: PHY_CTRL_2 :: phy_ctrl [31:00] */
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_2_phy_ctrl_MASK                0xffffffff
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_2_phy_ctrl_SHIFT               0
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_2_phy_ctrl_DEFAULT             0x00000000

/***************************************************************************
 *PHY_CTRL_3 - SATA3 phy interface control 3
 ***************************************************************************/
/* SATA_TOP_CTRL :: PHY_CTRL_3 :: phy_ctrl [31:00] */
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_3_phy_ctrl_MASK                0xffffffff
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_3_phy_ctrl_SHIFT               0
#define BCHP_SATA_TOP_CTRL_PHY_CTRL_3_phy_ctrl_DEFAULT             0x00000000

/***************************************************************************
 *SATA_TP_OUT - SATA3 TP OUT
 ***************************************************************************/
/* SATA_TOP_CTRL :: SATA_TP_OUT :: TP_OUT [31:00] */
#define BCHP_SATA_TOP_CTRL_SATA_TP_OUT_TP_OUT_MASK                 0xffffffff
#define BCHP_SATA_TOP_CTRL_SATA_TP_OUT_TP_OUT_SHIFT                0

#endif /* #ifndef BCHP_SATA_TOP_CTRL_H__ */

/* End of File */
