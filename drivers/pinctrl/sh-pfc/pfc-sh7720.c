/*
 * SH7720 Pinmux
 *
 *  Copyright (C) 2008  Magnus Damm
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 */

#include <linux/kernel.h>
#include <linux/gpio.h>
#include <cpu/sh7720.h>

#include "sh_pfc.h"

enum {
	PINMUX_RESERVED = 0,

	PINMUX_DATA_BEGIN,
	PTA7_DATA, PTA6_DATA, PTA5_DATA, PTA4_DATA,
	PTA3_DATA, PTA2_DATA, PTA1_DATA, PTA0_DATA,
	PTB7_DATA, PTB6_DATA, PTB5_DATA, PTB4_DATA,
	PTB3_DATA, PTB2_DATA, PTB1_DATA, PTB0_DATA,
	PTC7_DATA, PTC6_DATA, PTC5_DATA, PTC4_DATA,
	PTC3_DATA, PTC2_DATA, PTC1_DATA, PTC0_DATA,
	PTD7_DATA, PTD6_DATA, PTD5_DATA, PTD4_DATA,
	PTD3_DATA, PTD2_DATA, PTD1_DATA, PTD0_DATA,
	PTE6_DATA, PTE5_DATA, PTE4_DATA,
	PTE3_DATA, PTE2_DATA, PTE1_DATA, PTE0_DATA,
	PTF6_DATA, PTF5_DATA, PTF4_DATA,
	PTF3_DATA, PTF2_DATA, PTF1_DATA, PTF0_DATA,
	PTG6_DATA, PTG5_DATA, PTG4_DATA,
	PTG3_DATA, PTG2_DATA, PTG1_DATA, PTG0_DATA,
	PTH6_DATA, PTH5_DATA, PTH4_DATA,
	PTH3_DATA, PTH2_DATA, PTH1_DATA, PTH0_DATA,
	PTJ6_DATA, PTJ5_DATA, PTJ4_DATA,
	PTJ3_DATA, PTJ2_DATA, PTJ1_DATA, PTJ0_DATA,
	PTK3_DATA, PTK2_DATA, PTK1_DATA, PTK0_DATA,
	PTL7_DATA, PTL6_DATA, PTL5_DATA, PTL4_DATA, PTL3_DATA,
	PTM7_DATA, PTM6_DATA, PTM5_DATA, PTM4_DATA,
	PTM3_DATA, PTM2_DATA, PTM1_DATA, PTM0_DATA,
	PTP4_DATA, PTP3_DATA, PTP2_DATA, PTP1_DATA, PTP0_DATA,
	PTR7_DATA, PTR6_DATA, PTR5_DATA, PTR4_DATA,
	PTR3_DATA, PTR2_DATA, PTR1_DATA, PTR0_DATA,
	PTS4_DATA, PTS3_DATA, PTS2_DATA, PTS1_DATA, PTS0_DATA,
	PTT4_DATA, PTT3_DATA, PTT2_DATA, PTT1_DATA, PTT0_DATA,
	PTU4_DATA, PTU3_DATA, PTU2_DATA, PTU1_DATA, PTU0_DATA,
	PTV4_DATA, PTV3_DATA, PTV2_DATA, PTV1_DATA, PTV0_DATA,
	PINMUX_DATA_END,

	PINMUX_INPUT_BEGIN,
	PTA7_IN, PTA6_IN, PTA5_IN, PTA4_IN,
	PTA3_IN, PTA2_IN, PTA1_IN, PTA0_IN,
	PTB7_IN, PTB6_IN, PTB5_IN, PTB4_IN,
	PTB3_IN, PTB2_IN, PTB1_IN, PTB0_IN,
	PTC7_IN, PTC6_IN, PTC5_IN, PTC4_IN,
	PTC3_IN, PTC2_IN, PTC1_IN, PTC0_IN,
	PTD7_IN, PTD6_IN, PTD5_IN, PTD4_IN,
	PTD3_IN, PTD2_IN, PTD1_IN, PTD0_IN,
	PTE6_IN, PTE5_IN, PTE4_IN,
	PTE3_IN, PTE2_IN, PTE1_IN, PTE0_IN,
	PTF6_IN, PTF5_IN, PTF4_IN,
	PTF3_IN, PTF2_IN, PTF1_IN, PTF0_IN,
	PTG6_IN, PTG5_IN, PTG4_IN,
	PTG3_IN, PTG2_IN, PTG1_IN, PTG0_IN,
	PTH6_IN, PTH5_IN, PTH4_IN,
	PTH3_IN, PTH2_IN, PTH1_IN, PTH0_IN,
	PTJ6_IN, PTJ5_IN, PTJ4_IN,
	PTJ3_IN, PTJ2_IN, PTJ1_IN, PTJ0_IN,
	PTK3_IN, PTK2_IN, PTK1_IN, PTK0_IN,
	PTL7_IN, PTL6_IN, PTL5_IN, PTL4_IN, PTL3_IN,
	PTM7_IN, PTM6_IN, PTM5_IN, PTM4_IN,
	PTM3_IN, PTM2_IN, PTM1_IN, PTM0_IN,
	PTP4_IN, PTP3_IN, PTP2_IN, PTP1_IN, PTP0_IN,
	PTR7_IN, PTR6_IN, PTR5_IN, PTR4_IN,
	PTR3_IN, PTR2_IN, PTR1_IN, PTR0_IN,
	PTS4_IN, PTS3_IN, PTS2_IN, PTS1_IN, PTS0_IN,
	PTT4_IN, PTT3_IN, PTT2_IN, PTT1_IN, PTT0_IN,
	PTU4_IN, PTU3_IN, PTU2_IN, PTU1_IN, PTU0_IN,
	PTV4_IN, PTV3_IN, PTV2_IN, PTV1_IN, PTV0_IN,
	PINMUX_INPUT_END,

	PINMUX_OUTPUT_BEGIN,
	PTA7_OUT, PTA6_OUT, PTA5_OUT, PTA4_OUT,
	PTA3_OUT, PTA2_OUT, PTA1_OUT, PTA0_OUT,
	PTB7_OUT, PTB6_OUT, PTB5_OUT, PTB4_OUT,
	PTB3_OUT, PTB2_OUT, PTB1_OUT, PTB0_OUT,
	PTC7_OUT, PTC6_OUT, PTC5_OUT, PTC4_OUT,
	PTC3_OUT, PTC2_OUT, PTC1_OUT, PTC0_OUT,
	PTD7_OUT, PTD6_OUT, PTD5_OUT, PTD4_OUT,
	PTD3_OUT, PTD2_OUT, PTD1_OUT, PTD0_OUT,
	PTE4_OUT, PTE3_OUT, PTE2_OUT, PTE1_OUT, PTE0_OUT,
	PTF0_OUT,
	PTG6_OUT, PTG5_OUT, PTG4_OUT,
	PTG3_OUT, PTG2_OUT, PTG1_OUT, PTG0_OUT,
	PTH6_OUT, PTH5_OUT, PTH4_OUT,
	PTH3_OUT, PTH2_OUT, PTH1_OUT, PTH0_OUT,
	PTJ6_OUT, PTJ5_OUT, PTJ4_OUT,
	PTJ3_OUT, PTJ2_OUT, PTJ1_OUT, PTJ0_OUT,
	PTK3_OUT, PTK2_OUT, PTK1_OUT, PTK0_OUT,
	PTL7_OUT, PTL6_OUT, PTL5_OUT, PTL4_OUT, PTL3_OUT,
	PTM7_OUT, PTM6_OUT, PTM5_OUT, PTM4_OUT,
	PTM3_OUT, PTM2_OUT, PTM1_OUT, PTM0_OUT,
	PTP4_OUT, PTP3_OUT, PTP2_OUT, PTP1_OUT, PTP0_OUT,
	PTR7_OUT, PTR6_OUT, PTR5_OUT, PTR4_OUT,
	PTR3_OUT, PTR2_OUT, PTR1_OUT, PTR0_OUT,
	PTS4_OUT, PTS3_OUT, PTS2_OUT, PTS1_OUT, PTS0_OUT,
	PTT4_OUT, PTT3_OUT, PTT2_OUT, PTT1_OUT, PTT0_OUT,
	PTU4_OUT, PTU3_OUT, PTU2_OUT, PTU1_OUT, PTU0_OUT,
	PTV4_OUT, PTV3_OUT, PTV2_OUT, PTV1_OUT, PTV0_OUT,
	PINMUX_OUTPUT_END,

	PINMUX_FUNCTION_BEGIN,
	PTA7_FN, PTA6_FN, PTA5_FN, PTA4_FN,
	PTA3_FN, PTA2_FN, PTA1_FN, PTA0_FN,
	PTB7_FN, PTB6_FN, PTB5_FN, PTB4_FN,
	PTB3_FN, PTB2_FN, PTB1_FN, PTB0_FN,
	PTC7_FN, PTC6_FN, PTC5_FN, PTC4_FN,
	PTC3_FN, PTC2_FN, PTC1_FN, PTC0_FN,
	PTD7_FN, PTD6_FN, PTD5_FN, PTD4_FN,
	PTD3_FN, PTD2_FN, PTD1_FN, PTD0_FN,
	PTE6_FN, PTE5_FN, PTE4_FN,
	PTE3_FN, PTE2_FN, PTE1_FN, PTE0_FN,
	PTF6_FN, PTF5_FN, PTF4_FN,
	PTF3_FN, PTF2_FN, PTF1_FN, PTF0_FN,
	PTG6_FN, PTG5_FN, PTG4_FN,
	PTG3_FN, PTG2_FN, PTG1_FN, PTG0_FN,
	PTH6_FN, PTH5_FN, PTH4_FN,
	PTH3_FN, PTH2_FN, PTH1_FN, PTH0_FN,
	PTJ6_FN, PTJ5_FN, PTJ4_FN,
	PTJ3_FN, PTJ2_FN, PTJ1_FN, PTJ0_FN,
	PTK3_FN, PTK2_FN, PTK1_FN, PTK0_FN,
	PTL7_FN, PTL6_FN, PTL5_FN, PTL4_FN, PTL3_FN,
	PTM7_FN, PTM6_FN, PTM5_FN, PTM4_FN,
	PTM3_FN, PTM2_FN, PTM1_FN, PTM0_FN,
	PTP4_FN, PTP3_FN, PTP2_FN, PTP1_FN, PTP0_FN,
	PTR7_FN, PTR6_FN, PTR5_FN, PTR4_FN,
	PTR3_FN, PTR2_FN, PTR1_FN, PTR0_FN,
	PTS4_FN, PTS3_FN, PTS2_FN, PTS1_FN, PTS0_FN,
	PTT4_FN, PTT3_FN, PTT2_FN, PTT1_FN, PTT0_FN,
	PTU4_FN, PTU3_FN, PTU2_FN, PTU1_FN, PTU0_FN,
	PTV4_FN, PTV3_FN, PTV2_FN, PTV1_FN, PTV0_FN,

	PSELA_1_0_00, PSELA_1_0_01, PSELA_1_0_10,
	PSELA_3_2_00, PSELA_3_2_01, PSELA_3_2_10, PSELA_3_2_11,
	PSELA_5_4_00, PSELA_5_4_01, PSELA_5_4_10, PSELA_5_4_11,
	PSELA_7_6_00, PSELA_7_6_01, PSELA_7_6_10,
	PSELA_9_8_00, PSELA_9_8_01, PSELA_9_8_10,
	PSELA_11_10_00, PSELA_11_10_01, PSELA_11_10_10,
	PSELA_13_12_00, PSELA_13_12_10,
	PSELA_15_14_00, PSELA_15_14_10,
	PSELB_9_8_00, PSELB_9_8_11,
	PSELB_11_10_00, PSELB_11_10_01, PSELB_11_10_10, PSELB_11_10_11,
	PSELB_13_12_00, PSELB_13_12_01, PSELB_13_12_10, PSELB_13_12_11,
	PSELB_15_14_00, PSELB_15_14_11,
	PSELC_9_8_00, PSELC_9_8_10,
	PSELC_11_10_00, PSELC_11_10_10,
	PSELC_13_12_00,	PSELC_13_12_01,	PSELC_13_12_10,
	PSELC_15_14_00,	PSELC_15_14_01,	PSELC_15_14_10,
	PSELD_1_0_00, PSELD_1_0_10,
	PSELD_11_10_00,	PSELD_11_10_01,
	PSELD_15_14_00,	PSELD_15_14_01,	PSELD_15_14_10,
	PINMUX_FUNCTION_END,

	PINMUX_MARK_BEGIN,
	D31_MARK, D30_MARK, D29_MARK, D28_MARK,
	D27_MARK, D26_MARK, D25_MARK, D24_MARK,
	D23_MARK, D22_MARK, D21_MARK, D20_MARK,
	D19_MARK, D18_MARK, D17_MARK, D16_MARK,
	IOIS16_MARK, RAS_MARK, CAS_MARK, CKE_MARK,
	CS5B_CE1A_MARK, CS6B_CE1B_MARK,
	A25_MARK, A24_MARK, A23_MARK, A22_MARK,
	A21_MARK, A20_MARK, A19_MARK, A0_MARK,
	REFOUT_MARK, IRQOUT_MARK,
	LCD_DATA15_MARK, LCD_DATA14_MARK,
	LCD_DATA13_MARK, LCD_DATA12_MARK,
	LCD_DATA11_MARK, LCD_DATA10_MARK,
	LCD_DATA9_MARK, LCD_DATA8_MARK,
	LCD_DATA7_MARK, LCD_DATA6_MARK,
	LCD_DATA5_MARK, LCD_DATA4_MARK,
	LCD_DATA3_MARK, LCD_DATA2_MARK,
	LCD_DATA1_MARK, LCD_DATA0_MARK,
	LCD_M_DISP_MARK,
	LCD_CL1_MARK, LCD_CL2_MARK,
	LCD_DON_MARK, LCD_FLM_MARK,
	LCD_VEPWC_MARK, LCD_VCPWC_MARK,
	AFE_RXIN_MARK, AFE_RDET_MARK,
	AFE_FS_MARK, AFE_TXOUT_MARK,
	AFE_SCLK_MARK, AFE_RLYCNT_MARK,
	AFE_HC1_MARK,
	IIC_SCL_MARK, IIC_SDA_MARK,
	DA1_MARK, DA0_MARK,
	AN3_MARK, AN2_MARK, AN1_MARK, AN0_MARK, ADTRG_MARK,
	USB1D_RCV_MARK, USB1D_TXSE0_MARK,
	USB1D_TXDPLS_MARK, USB1D_DMNS_MARK,
	USB1D_DPLS_MARK, USB1D_SPEED_MARK,
	USB1D_TXENL_MARK,
	USB2_PWR_EN_MARK, USB1_PWR_EN_USBF_UPLUP_MARK, USB1D_SUSPEND_MARK,
	IRQ5_MARK, IRQ4_MARK,
	IRQ3_IRL3_MARK, IRQ2_IRL2_MARK,
	IRQ1_IRL1_MARK, IRQ0_IRL0_MARK,
	PCC_REG_MARK, PCC_DRV_MARK,
	PCC_BVD2_MARK, PCC_BVD1_MARK,
	PCC_CD2_MARK, PCC_CD1_MARK,
	PCC_RESET_MARK, PCC_RDY_MARK,
	PCC_VS2_MARK, PCC_VS1_MARK,
	AUDATA3_MARK, AUDATA2_MARK, AUDATA1_MARK, AUDATA0_MARK,
	AUDCK_MARK, AUDSYNC_MARK, ASEBRKAK_MARK, TRST_MARK,
	TMS_MARK, TDO_MARK, TDI_MARK, TCK_MARK,
	DACK1_MARK, DREQ1_MARK, DACK0_MARK, DREQ0_MARK,
	TEND1_MARK, TEND0_MARK,
	SIOF0_SYNC_MARK, SIOF0_MCLK_MARK,
	SIOF0_TXD_MARK, SIOF0_RXD_MARK,
	SIOF0_SCK_MARK,
	SIOF1_SYNC_MARK, SIOF1_MCLK_MARK,
	SIOF1_TXD_MARK, SIOF1_RXD_MARK,
	SIOF1_SCK_MARK,
	SCIF0_TXD_MARK, SCIF0_RXD_MARK,
	SCIF0_RTS_MARK, SCIF0_CTS_MARK, SCIF0_SCK_MARK,
	SCIF1_TXD_MARK, SCIF1_RXD_MARK,
	SCIF1_RTS_MARK, SCIF1_CTS_MARK, SCIF1_SCK_MARK,
	TPU_TO1_MARK, TPU_TO0_MARK,
	TPU_TI3B_MARK, TPU_TI3A_MARK,
	TPU_TI2B_MARK, TPU_TI2A_MARK,
	TPU_TO3_MARK, TPU_TO2_MARK,
	SIM_D_MARK, SIM_CLK_MARK, SIM_RST_MARK,
	MMC_DAT_MARK, MMC_CMD_MARK,
	MMC_CLK_MARK, MMC_VDDON_MARK,
	MMC_ODMOD_MARK,
	STATUS0_MARK, STATUS1_MARK,
	PINMUX_MARK_END,
};

static const u16 pinmux_data[] = {
	/* PTA GPIO */
	PINMUX_DATA(PTA7_DATA, PTA7_IN, PTA7_OUT),
	PINMUX_DATA(PTA6_DATA, PTA6_IN, PTA6_OUT),
	PINMUX_DATA(PTA5_DATA, PTA5_IN, PTA5_OUT),
	PINMUX_DATA(PTA4_DATA, PTA4_IN, PTA4_OUT),
	PINMUX_DATA(PTA3_DATA, PTA3_IN, PTA3_OUT),
	PINMUX_DATA(PTA2_DATA, PTA2_IN, PTA2_OUT),
	PINMUX_DATA(PTA1_DATA, PTA1_IN, PTA1_OUT),
	PINMUX_DATA(PTA0_DATA, PTA0_IN, PTA0_OUT),

	/* PTB GPIO */
	PINMUX_DATA(PTB7_DATA, PTB7_IN, PTB7_OUT),
	PINMUX_DATA(PTB6_DATA, PTB6_IN, PTB6_OUT),
	PINMUX_DATA(PTB5_DATA, PTB5_IN, PTB5_OUT),
	PINMUX_DATA(PTB4_DATA, PTB4_IN, PTB4_OUT),
	PINMUX_DATA(PTB3_DATA, PTB3_IN, PTB3_OUT),
	PINMUX_DATA(PTB2_DATA, PTB2_IN, PTB2_OUT),
	PINMUX_DATA(PTB1_DATA, PTB1_IN, PTB1_OUT),
	PINMUX_DATA(PTB0_DATA, PTB0_IN, PTB0_OUT),

	/* PTC GPIO */
	PINMUX_DATA(PTC7_DATA, PTC7_IN, PTC7_OUT),
	PINMUX_DATA(PTC6_DATA, PTC6_IN, PTC6_OUT),
	PINMUX_DATA(PTC5_DATA, PTC5_IN, PTC5_OUT),
	PINMUX_DATA(PTC4_DATA, PTC4_IN, PTC4_OUT),
	PINMUX_DATA(PTC3_DATA, PTC3_IN, PTC3_OUT),
	PINMUX_DATA(PTC2_DATA, PTC2_IN, PTC2_OUT),
	PINMUX_DATA(PTC1_DATA, PTC1_IN, PTC1_OUT),
	PINMUX_DATA(PTC0_DATA, PTC0_IN, PTC0_OUT),

	/* PTD GPIO */
	PINMUX_DATA(PTD7_DATA, PTD7_IN, PTD7_OUT),
	PINMUX_DATA(PTD6_DATA, PTD6_IN, PTD6_OUT),
	PINMUX_DATA(PTD5_DATA, PTD5_IN, PTD5_OUT),
	PINMUX_DATA(PTD4_DATA, PTD4_IN, PTD4_OUT),
	PINMUX_DATA(PTD3_DATA, PTD3_IN, PTD3_OUT),
	PINMUX_DATA(PTD2_DATA, PTD2_IN, PTD2_OUT),
	PINMUX_DATA(PTD1_DATA, PTD1_IN, PTD1_OUT),
	PINMUX_DATA(PTD0_DATA, PTD0_IN, PTD0_OUT),

	/* PTE GPIO */
	PINMUX_DATA(PTE6_DATA, PTE6_IN),
	PINMUX_DATA(PTE5_DATA, PTE5_IN),
	PINMUX_DATA(PTE4_DATA, PTE4_IN, PTE4_OUT),
	PINMUX_DATA(PTE3_DATA, PTE3_IN, PTE3_OUT),
	PINMUX_DATA(PTE2_DATA, PTE2_IN, PTE2_OUT),
	PINMUX_DATA(PTE1_DATA, PTE1_IN, PTE1_OUT),
	PINMUX_DATA(PTE0_DATA, PTE0_IN, PTE0_OUT),

	/* PTF GPIO */
	PINMUX_DATA(PTF6_DATA, PTF6_IN),
	PINMUX_DATA(PTF5_DATA, PTF5_IN),
	PINMUX_DATA(PTF4_DATA, PTF4_IN),
	PINMUX_DATA(PTF3_DATA, PTF3_IN),
	PINMUX_DATA(PTF2_DATA, PTF2_IN),
	PINMUX_DATA(PTF1_DATA, PTF1_IN),
	PINMUX_DATA(PTF0_DATA, PTF0_IN, PTF0_OUT),

	/* PTG GPIO */
	PINMUX_DATA(PTG6_DATA, PTG6_IN, PTG6_OUT),
	PINMUX_DATA(PTG5_DATA, PTG5_IN, PTG5_OUT),
	PINMUX_DATA(PTG4_DATA, PTG4_IN, PTG4_OUT),
	PINMUX_DATA(PTG3_DATA, PTG3_IN, PTG3_OUT),
	PINMUX_DATA(PTG2_DATA, PTG2_IN, PTG2_OUT),
	PINMUX_DATA(PTG1_DATA, PTG1_IN, PTG1_OUT),
	PINMUX_DATA(PTG0_DATA, PTG0_IN, PTG0_OUT),

	/* PTH GPIO */
	PINMUX_DATA(PTH6_DATA, PTH6_IN, PTH6_OUT),
	PINMUX_DATA(PTH5_DATA, PTH5_IN, PTH5_OUT),
	PINMUX_DATA(PTH4_DATA, PTH4_IN, PTH4_OUT),
	PINMUX_DATA(PTH3_DATA, PTH3_IN, PTH3_OUT),
	PINMUX_DATA(PTH2_DATA, PTH2_IN, PTH2_OUT),
	PINMUX_DATA(PTH1_DATA, PTH1_IN, PTH1_OUT),
	PINMUX_DATA(PTH0_DATA, PTH0_IN, PTH0_OUT),

	/* PTJ GPIO */
	PINMUX_DATA(PTJ6_DATA, PTJ6_IN, PTJ6_OUT),
	PINMUX_DATA(PTJ5_DATA, PTJ5_IN, PTJ5_OUT),
	PINMUX_DATA(PTJ4_DATA, PTJ4_IN, PTJ4_OUT),
	PINMUX_DATA(PTJ3_DATA, PTJ3_IN, PTJ3_OUT),
	PINMUX_DATA(PTJ2_DATA, PTJ2_IN, PTJ2_OUT),
	PINMUX_DATA(PTJ1_DATA, PTJ1_IN, PTJ1_OUT),
	PINMUX_DATA(PTJ0_DATA, PTJ0_IN, PTJ0_OUT),

	/* PTK GPIO */
	PINMUX_DATA(PTK3_DATA, PTK3_IN, PTK3_OUT),
	PINMUX_DATA(PTK2_DATA, PTK2_IN, PTK2_OUT),
	PINMUX_DATA(PTK1_DATA, PTK1_IN, PTK1_OUT),
	PINMUX_DATA(PTK0_DATA, PTK0_IN, PTK0_OUT),

	/* PTL GPIO */
	PINMUX_DATA(PTL7_DATA, PTL7_IN, PTL7_OUT),
	PINMUX_DATA(PTL6_DATA, PTL6_IN, PTL6_OUT),
	PINMUX_DATA(PTL5_DATA, PTL5_IN, PTL5_OUT),
	PINMUX_DATA(PTL4_DATA, PTL4_IN, PTL4_OUT),
	PINMUX_DATA(PTL3_DATA, PTL3_IN, PTL3_OUT),

	/* PTM GPIO */
	PINMUX_DATA(PTM7_DATA, PTM7_IN, PTM7_OUT),
	PINMUX_DATA(PTM6_DATA, PTM6_IN, PTM6_OUT),
	PINMUX_DATA(PTM5_DATA, PTM5_IN, PTM5_OUT),
	PINMUX_DATA(PTM4_DATA, PTM4_IN, PTM4_OUT),
	PINMUX_DATA(PTM3_DATA, PTM3_IN, PTM3_OUT),
	PINMUX_DATA(PTM2_DATA, PTM2_IN, PTM2_OUT),
	PINMUX_DATA(PTM1_DATA, PTM1_IN, PTM1_OUT),
	PINMUX_DATA(PTM0_DATA, PTM0_IN, PTM0_OUT),

	/* PTP GPIO */
	PINMUX_DATA(PTP4_DATA, PTP4_IN, PTP4_OUT),
	PINMUX_DATA(PTP3_DATA, PTP3_IN, PTP3_OUT),
	PINMUX_DATA(PTP2_DATA, PTP2_IN, PTP2_OUT),
	PINMUX_DATA(PTP1_DATA, PTP1_IN, PTP1_OUT),
	PINMUX_DATA(PTP0_DATA, PTP0_IN, PTP0_OUT),

	/* PTR GPIO */
	PINMUX_DATA(PTR7_DATA, PTR7_IN, PTR7_OUT),
	PINMUX_DATA(PTR6_DATA, PTR6_IN, PTR6_OUT),
	PINMUX_DATA(PTR5_DATA, PTR5_IN, PTR5_OUT),
	PINMUX_DATA(PTR4_DATA, PTR4_IN, PTR4_OUT),
	PINMUX_DATA(PTR3_DATA, PTR3_IN, PTR3_OUT),
	PINMUX_DATA(PTR2_DATA, PTR2_IN, PTR2_OUT),
	PINMUX_DATA(PTR1_DATA, PTR1_IN, PTR1_OUT),
	PINMUX_DATA(PTR0_DATA, PTR0_IN, PTR0_OUT),

	/* PTS GPIO */
	PINMUX_DATA(PTS4_DATA, PTS4_IN, PTS4_OUT),
	PINMUX_DATA(PTS3_DATA, PTS3_IN, PTS3_OUT),
	PINMUX_DATA(PTS2_DATA, PTS2_IN, PTS2_OUT),
	PINMUX_DATA(PTS1_DATA, PTS1_IN, PTS1_OUT),
	PINMUX_DATA(PTS0_DATA, PTS0_IN, PTS0_OUT),

	/* PTT GPIO */
	PINMUX_DATA(PTT4_DATA, PTT4_IN, PTT4_OUT),
	PINMUX_DATA(PTT3_DATA, PTT3_IN, PTT3_OUT),
	PINMUX_DATA(PTT2_DATA, PTT2_IN, PTT2_OUT),
	PINMUX_DATA(PTT1_DATA, PTT1_IN, PTT1_OUT),
	PINMUX_DATA(PTT0_DATA, PTT0_IN, PTT0_OUT),

	/* PTU GPIO */
	PINMUX_DATA(PTU4_DATA, PTU4_IN, PTU4_OUT),
	PINMUX_DATA(PTU3_DATA, PTU3_IN, PTU3_OUT),
	PINMUX_DATA(PTU2_DATA, PTU2_IN, PTU2_OUT),
	PINMUX_DATA(PTU1_DATA, PTU1_IN, PTU1_OUT),
	PINMUX_DATA(PTU0_DATA, PTU0_IN, PTU0_OUT),

	/* PTV GPIO */
	PINMUX_DATA(PTV4_DATA, PTV4_IN, PTV4_OUT),
	PINMUX_DATA(PTV3_DATA, PTV3_IN, PTV3_OUT),
	PINMUX_DATA(PTV2_DATA, PTV2_IN, PTV2_OUT),
	PINMUX_DATA(PTV1_DATA, PTV1_IN, PTV1_OUT),
	PINMUX_DATA(PTV0_DATA, PTV0_IN, PTV0_OUT),

	/* PTA FN */
	PINMUX_DATA(D23_MARK, PTA7_FN),
	PINMUX_DATA(D22_MARK, PTA6_FN),
	PINMUX_DATA(D21_MARK, PTA5_FN),
	PINMUX_DATA(D20_MARK, PTA4_FN),
	PINMUX_DATA(D19_MARK, PTA3_FN),
	PINMUX_DATA(D18_MARK, PTA2_FN),
	PINMUX_DATA(D17_MARK, PTA1_FN),
	PINMUX_DATA(D16_MARK, PTA0_FN),

	/* PTB FN */
	PINMUX_DATA(D31_MARK, PTB7_FN),
	PINMUX_DATA(D30_MARK, PTB6_FN),
	PINMUX_DATA(D29_MARK, PTB5_FN),
	PINMUX_DATA(D28_MARK, PTB4_FN),
	PINMUX_DATA(D27_MARK, PTB3_FN),
	PINMUX_DATA(D26_MARK, PTB2_FN),
	PINMUX_DATA(D25_MARK, PTB1_FN),
	PINMUX_DATA(D24_MARK, PTB0_FN),

	/* PTC FN */
	PINMUX_DATA(LCD_DATA7_MARK, PTC7_FN),
	PINMUX_DATA(LCD_DATA6_MARK, PTC6_FN),
	PINMUX_DATA(LCD_DATA5_MARK, PTC5_FN),
	PINMUX_DATA(LCD_DATA4_MARK, PTC4_FN),
	PINMUX_DATA(LCD_DATA3_MARK, PTC3_FN),
	PINMUX_DATA(LCD_DATA2_MARK, PTC2_FN),
	PINMUX_DATA(LCD_DATA1_MARK, PTC1_FN),
	PINMUX_DATA(LCD_DATA0_MARK, PTC0_FN),

	/* PTD FN */
	PINMUX_DATA(LCD_DATA15_MARK, PTD7_FN),
	PINMUX_DATA(LCD_DATA14_MARK, PTD6_FN),
	PINMUX_DATA(LCD_DATA13_MARK, PTD5_FN),
	PINMUX_DATA(LCD_DATA12_MARK, PTD4_FN),
	PINMUX_DATA(LCD_DATA11_MARK, PTD3_FN),
	PINMUX_DATA(LCD_DATA10_MARK, PTD2_FN),
	PINMUX_DATA(LCD_DATA9_MARK, PTD1_FN),
	PINMUX_DATA(LCD_DATA8_MARK, PTD0_FN),

	/* PTE FN */
	PINMUX_DATA(IIC_SCL_MARK, PSELB_9_8_00, PTE6_FN),
	PINMUX_DATA(AFE_RXIN_MARK, PSELB_9_8_11, PTE6_FN),
	PINMUX_DATA(IIC_SDA_MARK, PSELB_9_8_00, PTE5_FN),
	PINMUX_DATA(AFE_RDET_MARK, PSELB_9_8_11, PTE5_FN),
	PINMUX_DATA(LCD_M_DISP_MARK, PTE4_FN),
	PINMUX_DATA(LCD_CL1_MARK, PTE3_FN),
	PINMUX_DATA(LCD_CL2_MARK, PTE2_FN),
	PINMUX_DATA(LCD_DON_MARK, PTE1_FN),
	PINMUX_DATA(LCD_FLM_MARK, PTE0_FN),

	/* PTF FN */
	PINMUX_DATA(DA1_MARK, PTF6_FN),
	PINMUX_DATA(DA0_MARK, PTF5_FN),
	PINMUX_DATA(AN3_MARK, PTF4_FN),
	PINMUX_DATA(AN2_MARK, PTF3_FN),
	PINMUX_DATA(AN1_MARK, PTF2_FN),
	PINMUX_DATA(AN0_MARK, PTF1_FN),
	PINMUX_DATA(ADTRG_MARK, PTF0_FN),

	/* PTG FN */
	PINMUX_DATA(USB1D_RCV_MARK, PSELA_3_2_00, PTG6_FN),
	PINMUX_DATA(AFE_FS_MARK, PSELA_3_2_01, PTG6_FN),
	PINMUX_DATA(PCC_REG_MARK, PSELA_3_2_10, PTG6_FN),
	PINMUX_DATA(IRQ5_MARK, PSELA_3_2_11, PTG6_FN),
	PINMUX_DATA(USB1D_TXSE0_MARK, PSELA_5_4_00, PTG5_FN),
	PINMUX_DATA(AFE_TXOUT_MARK, PSELA_5_4_01, PTG5_FN),
	PINMUX_DATA(PCC_DRV_MARK, PSELA_5_4_10, PTG5_FN),
	PINMUX_DATA(IRQ4_MARK, PSELA_5_4_11, PTG5_FN),
	PINMUX_DATA(USB1D_TXDPLS_MARK, PSELA_7_6_00, PTG4_FN),
	PINMUX_DATA(AFE_SCLK_MARK, PSELA_7_6_01, PTG4_FN),
	PINMUX_DATA(IOIS16_MARK, PSELA_7_6_10, PTG4_FN),
	PINMUX_DATA(USB1D_DMNS_MARK, PSELA_9_8_00, PTG3_FN),
	PINMUX_DATA(AFE_RLYCNT_MARK, PSELA_9_8_01, PTG3_FN),
	PINMUX_DATA(PCC_BVD2_MARK, PSELA_9_8_10, PTG3_FN),
	PINMUX_DATA(USB1D_DPLS_MARK, PSELA_11_10_00, PTG2_FN),
	PINMUX_DATA(AFE_HC1_MARK, PSELA_11_10_01, PTG2_FN),
	PINMUX_DATA(PCC_BVD1_MARK, PSELA_11_10_10, PTG2_FN),
	PINMUX_DATA(USB1D_SPEED_MARK, PSELA_13_12_00, PTG1_FN),
	PINMUX_DATA(PCC_CD2_MARK, PSELA_13_12_10, PTG1_FN),
	PINMUX_DATA(USB1D_TXENL_MARK, PSELA_15_14_00, PTG0_FN),
	PINMUX_DATA(PCC_CD1_MARK, PSELA_15_14_10, PTG0_FN),

	/* PTH FN */
	PINMUX_DATA(RAS_MARK, PTH6_FN),
	PINMUX_DATA(CAS_MARK, PTH5_FN),
	PINMUX_DATA(CKE_MARK, PTH4_FN),
	PINMUX_DATA(STATUS1_MARK, PTH3_FN),
	PINMUX_DATA(STATUS0_MARK, PTH2_FN),
	PINMUX_DATA(USB2_PWR_EN_MARK, PTH1_FN),
	PINMUX_DATA(USB1_PWR_EN_USBF_UPLUP_MARK, PTH0_FN),

	/* PTJ FN */
	PINMUX_DATA(AUDCK_MARK, PTJ6_FN),
	PINMUX_DATA(ASEBRKAK_MARK, PTJ5_FN),
	PINMUX_DATA(AUDATA3_MARK, PTJ4_FN),
	PINMUX_DATA(AUDATA2_MARK, PTJ3_FN),
	PINMUX_DATA(AUDATA1_MARK, PTJ2_FN),
	PINMUX_DATA(AUDATA0_MARK, PTJ1_FN),
	PINMUX_DATA(AUDSYNC_MARK, PTJ0_FN),

	/* PTK FN */
	PINMUX_DATA(PCC_RESET_MARK, PTK3_FN),
	PINMUX_DATA(PCC_RDY_MARK, PTK2_FN),
	PINMUX_DATA(PCC_VS2_MARK, PTK1_FN),
	PINMUX_DATA(PCC_VS1_MARK, PTK0_FN),

	/* PTL FN */
	PINMUX_DATA(TRST_MARK, PTL7_FN),
	PINMUX_DATA(TMS_MARK, PTL6_FN),
	PINMUX_DATA(TDO_MARK, PTL5_FN),
	PINMUX_DATA(TDI_MARK, PTL4_FN),
	PINMUX_DATA(TCK_MARK, PTL3_FN),

	/* PTM FN */
	PINMUX_DATA(DREQ1_MARK, PTM7_FN),
	PINMUX_DATA(DREQ0_MARK, PTM6_FN),
	PINMUX_DATA(DACK1_MARK, PTM5_FN),
	PINMUX_DATA(DACK0_MARK, PTM4_FN),
	PINMUX_DATA(TEND1_MARK, PTM3_FN),
	PINMUX_DATA(TEND0_MARK, PTM2_FN),
	PINMUX_DATA(CS5B_CE1A_MARK, PTM1_FN),
	PINMUX_DATA(CS6B_CE1B_MARK, PTM0_FN),

	/* PTP FN */
	PINMUX_DATA(USB1D_SUSPEND_MARK, PSELA_1_0_00, PTP4_FN),
	PINMUX_DATA(REFOUT_MARK, PSELA_1_0_01, PTP4_FN),
	PINMUX_DATA(IRQOUT_MARK, PSELA_1_0_10, PTP4_FN),
	PINMUX_DATA(IRQ3_IRL3_MARK, PTP3_FN),
	PINMUX_DATA(IRQ2_IRL2_MARK, PTP2_FN),
	PINMUX_DATA(IRQ1_IRL1_MARK, PTP1_FN),
	PINMUX_DATA(IRQ0_IRL0_MARK, PTP0_FN),

	/* PTR FN */
	PINMUX_DATA(A25_MARK, PTR7_FN),
	PINMUX_DATA(A24_MARK, PTR6_FN),
	PINMUX_DATA(A23_MARK, PTR5_FN),
	PINMUX_DATA(A22_MARK, PTR4_FN),
	PINMUX_DATA(A21_MARK, PTR3_FN),
	PINMUX_DATA(A20_MARK, PTR2_FN),
	PINMUX_DATA(A19_MARK, PTR1_FN),
	PINMUX_DATA(A0_MARK, PTR0_FN),

	/* PTS FN */
	PINMUX_DATA(SIOF0_SYNC_MARK, PTS4_FN),
	PINMUX_DATA(SIOF0_MCLK_MARK, PTS3_FN),
	PINMUX_DATA(SIOF0_TXD_MARK, PTS2_FN),
	PINMUX_DATA(SIOF0_RXD_MARK, PTS1_FN),
	PINMUX_DATA(SIOF0_SCK_MARK, PTS0_FN),

	/* PTT FN */
	PINMUX_DATA(SCIF0_CTS_MARK, PSELB_15_14_00, PTT4_FN),
	PINMUX_DATA(TPU_TO1_MARK, PSELB_15_14_11, PTT4_FN),
	PINMUX_DATA(SCIF0_RTS_MARK, PSELB_15_14_00, PTT3_FN),
	PINMUX_DATA(TPU_TO0_MARK, PSELB_15_14_11, PTT3_FN),
	PINMUX_DATA(SCIF0_TXD_MARK, PTT2_FN),
	PINMUX_DATA(SCIF0_RXD_MARK, PTT1_FN),
	PINMUX_DATA(SCIF0_SCK_MARK, PTT0_FN),

	/* PTU FN */
	PINMUX_DATA(SIOF1_SYNC_MARK, PTU4_FN),
	PINMUX_DATA(SIOF1_MCLK_MARK, PSELD_11_10_00, PTU3_FN),
	PINMUX_DATA(TPU_TI3B_MARK, PSELD_11_10_01, PTU3_FN),
	PINMUX_DATA(SIOF1_TXD_MARK, PSELD_15_14_00, PTU2_FN),
	PINMUX_DATA(TPU_TI3A_MARK, PSELD_15_14_01, PTU2_FN),
	PINMUX_DATA(MMC_DAT_MARK, PSELD_15_14_10, PTU2_FN),
	PINMUX_DATA(SIOF1_RXD_MARK, PSELC_13_12_00, PTU1_FN),
	PINMUX_DATA(TPU_TI2B_MARK, PSELC_13_12_01, PTU1_FN),
	PINMUX_DATA(MMC_CMD_MARK, PSELC_13_12_10, PTU1_FN),
	PINMUX_DATA(SIOF1_SCK_MARK, PSELC_15_14_00, PTU0_FN),
	PINMUX_DATA(TPU_TI2A_MARK, PSELC_15_14_01, PTU0_FN),
	PINMUX_DATA(MMC_CLK_MARK, PSELC_15_14_10, PTU0_FN),

	/* PTV FN */
	PINMUX_DATA(SCIF1_CTS_MARK, PSELB_11_10_00, PTV4_FN),
	PINMUX_DATA(TPU_TO3_MARK, PSELB_11_10_01, PTV4_FN),
	PINMUX_DATA(MMC_VDDON_MARK, PSELB_11_10_10, PTV4_FN),
	PINMUX_DATA(LCD_VEPWC_MARK, PSELB_11_10_11, PTV4_FN),
	PINMUX_DATA(SCIF1_RTS_MARK, PSELB_13_12_00, PTV3_FN),
	PINMUX_DATA(TPU_TO2_MARK, PSELB_13_12_01, PTV3_FN),
	PINMUX_DATA(MMC_ODMOD_MARK, PSELB_13_12_10, PTV3_FN),
	PINMUX_DATA(LCD_VCPWC_MARK, PSELB_13_12_11, PTV3_FN),
	PINMUX_DATA(SCIF1_TXD_MARK, PSELC_9_8_00, PTV2_FN),
	PINMUX_DATA(SIM_D_MARK, PSELC_9_8_10, PTV2_FN),
	PINMUX_DATA(SCIF1_RXD_MARK, PSELC_11_10_00, PTV1_FN),
	PINMUX_DATA(SIM_RST_MARK, PSELC_11_10_10, PTV1_FN),
	PINMUX_DATA(SCIF1_SCK_MARK, PSELD_1_0_00, PTV0_FN),
	PINMUX_DATA(SIM_CLK_MARK, PSELD_1_0_10, PTV0_FN),
};

static const struct sh_pfc_pin pinmux_pins[] = {
	/* PTA */
	PINMUX_GPIO(PTA7),
	PINMUX_GPIO(PTA6),
	PINMUX_GPIO(PTA5),
	PINMUX_GPIO(PTA4),
	PINMUX_GPIO(PTA3),
	PINMUX_GPIO(PTA2),
	PINMUX_GPIO(PTA1),
	PINMUX_GPIO(PTA0),

	/* PTB */
	PINMUX_GPIO(PTB7),
	PINMUX_GPIO(PTB6),
	PINMUX_GPIO(PTB5),
	PINMUX_GPIO(PTB4),
	PINMUX_GPIO(PTB3),
	PINMUX_GPIO(PTB2),
	PINMUX_GPIO(PTB1),
	PINMUX_GPIO(PTB0),

	/* PTC */
	PINMUX_GPIO(PTC7),
	PINMUX_GPIO(PTC6),
	PINMUX_GPIO(PTC5),
	PINMUX_GPIO(PTC4),
	PINMUX_GPIO(PTC3),
	PINMUX_GPIO(PTC2),
	PINMUX_GPIO(PTC1),
	PINMUX_GPIO(PTC0),

	/* PTD */
	PINMUX_GPIO(PTD7),
	PINMUX_GPIO(PTD6),
	PINMUX_GPIO(PTD5),
	PINMUX_GPIO(PTD4),
	PINMUX_GPIO(PTD3),
	PINMUX_GPIO(PTD2),
	PINMUX_GPIO(PTD1),
	PINMUX_GPIO(PTD0),

	/* PTE */
	PINMUX_GPIO(PTE6),
	PINMUX_GPIO(PTE5),
	PINMUX_GPIO(PTE4),
	PINMUX_GPIO(PTE3),
	PINMUX_GPIO(PTE2),
	PINMUX_GPIO(PTE1),
	PINMUX_GPIO(PTE0),

	/* PTF */
	PINMUX_GPIO(PTF6),
	PINMUX_GPIO(PTF5),
	PINMUX_GPIO(PTF4),
	PINMUX_GPIO(PTF3),
	PINMUX_GPIO(PTF2),
	PINMUX_GPIO(PTF1),
	PINMUX_GPIO(PTF0),

	/* PTG */
	PINMUX_GPIO(PTG6),
	PINMUX_GPIO(PTG5),
	PINMUX_GPIO(PTG4),
	PINMUX_GPIO(PTG3),
	PINMUX_GPIO(PTG2),
	PINMUX_GPIO(PTG1),
	PINMUX_GPIO(PTG0),

	/* PTH */
	PINMUX_GPIO(PTH6),
	PINMUX_GPIO(PTH5),
	PINMUX_GPIO(PTH4),
	PINMUX_GPIO(PTH3),
	PINMUX_GPIO(PTH2),
	PINMUX_GPIO(PTH1),
	PINMUX_GPIO(PTH0),

	/* PTJ */
	PINMUX_GPIO(PTJ6),
	PINMUX_GPIO(PTJ5),
	PINMUX_GPIO(PTJ4),
	PINMUX_GPIO(PTJ3),
	PINMUX_GPIO(PTJ2),
	PINMUX_GPIO(PTJ1),
	PINMUX_GPIO(PTJ0),

	/* PTK */
	PINMUX_GPIO(PTK3),
	PINMUX_GPIO(PTK2),
	PINMUX_GPIO(PTK1),
	PINMUX_GPIO(PTK0),

	/* PTL */
	PINMUX_GPIO(PTL7),
	PINMUX_GPIO(PTL6),
	PINMUX_GPIO(PTL5),
	PINMUX_GPIO(PTL4),
	PINMUX_GPIO(PTL3),

	/* PTM */
	PINMUX_GPIO(PTM7),
	PINMUX_GPIO(PTM6),
	PINMUX_GPIO(PTM5),
	PINMUX_GPIO(PTM4),
	PINMUX_GPIO(PTM3),
	PINMUX_GPIO(PTM2),
	PINMUX_GPIO(PTM1),
	PINMUX_GPIO(PTM0),

	/* PTP */
	PINMUX_GPIO(PTP4),
	PINMUX_GPIO(PTP3),
	PINMUX_GPIO(PTP2),
	PINMUX_GPIO(PTP1),
	PINMUX_GPIO(PTP0),

	/* PTR */
	PINMUX_GPIO(PTR7),
	PINMUX_GPIO(PTR6),
	PINMUX_GPIO(PTR5),
	PINMUX_GPIO(PTR4),
	PINMUX_GPIO(PTR3),
	PINMUX_GPIO(PTR2),
	PINMUX_GPIO(PTR1),
	PINMUX_GPIO(PTR0),

	/* PTS */
	PINMUX_GPIO(PTS4),
	PINMUX_GPIO(PTS3),
	PINMUX_GPIO(PTS2),
	PINMUX_GPIO(PTS1),
	PINMUX_GPIO(PTS0),

	/* PTT */
	PINMUX_GPIO(PTT4),
	PINMUX_GPIO(PTT3),
	PINMUX_GPIO(PTT2),
	PINMUX_GPIO(PTT1),
	PINMUX_GPIO(PTT0),

	/* PTU */
	PINMUX_GPIO(PTU4),
	PINMUX_GPIO(PTU3),
	PINMUX_GPIO(PTU2),
	PINMUX_GPIO(PTU1),
	PINMUX_GPIO(PTU0),

	/* PTV */
	PINMUX_GPIO(PTV4),
	PINMUX_GPIO(PTV3),
	PINMUX_GPIO(PTV2),
	PINMUX_GPIO(PTV1),
	PINMUX_GPIO(PTV0),
};

#define PINMUX_FN_BASE	ARRAY_SIZE(pinmux_pins)

static const struct pinmux_func pinmux_func_gpios[] = {
	/* BSC */
	GPIO_FN(D31),
	GPIO_FN(D30),
	GPIO_FN(D29),
	GPIO_FN(D28),
	GPIO_FN(D27),
	GPIO_FN(D26),
	GPIO_FN(D25),
	GPIO_FN(D24),
	GPIO_FN(D23),
	GPIO_FN(D22),
	GPIO_FN(D21),
	GPIO_FN(D20),
	GPIO_FN(D19),
	GPIO_FN(D18),
	GPIO_FN(D17),
	GPIO_FN(D16),
	GPIO_FN(IOIS16),
	GPIO_FN(RAS),
	GPIO_FN(CAS),
	GPIO_FN(CKE),
	GPIO_FN(CS5B_CE1A),
	GPIO_FN(CS6B_CE1B),
	GPIO_FN(A25),
	GPIO_FN(A24),
	GPIO_FN(A23),
	GPIO_FN(A22),
	GPIO_FN(A21),
	GPIO_FN(A20),
	GPIO_FN(A19),
	GPIO_FN(A0),
	GPIO_FN(REFOUT),
	GPIO_FN(IRQOUT),

	/* LCDC */
	GPIO_FN(LCD_DATA15),
	GPIO_FN(LCD_DATA14),
	GPIO_FN(LCD_DATA13),
	GPIO_FN(LCD_DATA12),
	GPIO_FN(LCD_DATA11),
	GPIO_FN(LCD_DATA10),
	GPIO_FN(LCD_DATA9),
	GPIO_FN(LCD_DATA8),
	GPIO_FN(LCD_DATA7),
	GPIO_FN(LCD_DATA6),
	GPIO_FN(LCD_DATA5),
	GPIO_FN(LCD_DATA4),
	GPIO_FN(LCD_DATA3),
	GPIO_FN(LCD_DATA2),
	GPIO_FN(LCD_DATA1),
	GPIO_FN(LCD_DATA0),
	GPIO_FN(LCD_M_DISP),
	GPIO_FN(LCD_CL1),
	GPIO_FN(LCD_CL2),
	GPIO_FN(LCD_DON),
	GPIO_FN(LCD_FLM),
	GPIO_FN(LCD_VEPWC),
	GPIO_FN(LCD_VCPWC),

	/* AFEIF */
	GPIO_FN(AFE_RXIN),
	GPIO_FN(AFE_RDET),
	GPIO_FN(AFE_FS),
	GPIO_FN(AFE_TXOUT),
	GPIO_FN(AFE_SCLK),
	GPIO_FN(AFE_RLYCNT),
	GPIO_FN(AFE_HC1),

	/* IIC */
	GPIO_FN(IIC_SCL),
	GPIO_FN(IIC_SDA),

	/* DAC */
	GPIO_FN(DA1),
	GPIO_FN(DA0),

	/* ADC */
	GPIO_FN(AN3),
	GPIO_FN(AN2),
	GPIO_FN(AN1),
	GPIO_FN(AN0),
	GPIO_FN(ADTRG),

	/* USB */
	GPIO_FN(USB1D_RCV),
	GPIO_FN(USB1D_TXSE0),
	GPIO_FN(USB1D_TXDPLS),
	GPIO_FN(USB1D_DMNS),
	GPIO_FN(USB1D_DPLS),
	GPIO_FN(USB1D_SPEED),
	GPIO_FN(USB1D_TXENL),

	GPIO_FN(USB2_PWR_EN),
	GPIO_FN(USB1_PWR_EN_USBF_UPLUP),
	GPIO_FN(USB1D_SUSPEND),

	/* INTC */
	GPIO_FN(IRQ5),
	GPIO_FN(IRQ4),
	GPIO_FN(IRQ3_IRL3),
	GPIO_FN(IRQ2_IRL2),
	GPIO_FN(IRQ1_IRL1),
	GPIO_FN(IRQ0_IRL0),

	/* PCC */
	GPIO_FN(PCC_REG),
	GPIO_FN(PCC_DRV),
	GPIO_FN(PCC_BVD2),
	GPIO_FN(PCC_BVD1),
	GPIO_FN(PCC_CD2),
	GPIO_FN(PCC_CD1),
	GPIO_FN(PCC_RESET),
	GPIO_FN(PCC_RDY),
	GPIO_FN(PCC_VS2),
	GPIO_FN(PCC_VS1),

	/* HUDI */
	GPIO_FN(AUDATA3),
	GPIO_FN(AUDATA2),
	GPIO_FN(AUDATA1),
	GPIO_FN(AUDATA0),
	GPIO_FN(AUDCK),
	GPIO_FN(AUDSYNC),
	GPIO_FN(ASEBRKAK),
	GPIO_FN(TRST),
	GPIO_FN(TMS),
	GPIO_FN(TDO),
	GPIO_FN(TDI),
	GPIO_FN(TCK),

	/* DMAC */
	GPIO_FN(DACK1),
	GPIO_FN(DREQ1),
	GPIO_FN(DACK0),
	GPIO_FN(DREQ0),
	GPIO_FN(TEND1),
	GPIO_FN(TEND0),

	/* SIOF0 */
	GPIO_FN(SIOF0_SYNC),
	GPIO_FN(SIOF0_MCLK),
	GPIO_FN(SIOF0_TXD),
	GPIO_FN(SIOF0_RXD),
	GPIO_FN(SIOF0_SCK),

	/* SIOF1 */
	GPIO_FN(SIOF1_SYNC),
	GPIO_FN(SIOF1_MCLK),
	GPIO_FN(SIOF1_TXD),
	GPIO_FN(SIOF1_RXD),
	GPIO_FN(SIOF1_SCK),

	/* SCIF0 */
	GPIO_FN(SCIF0_TXD),
	GPIO_FN(SCIF0_RXD),
	GPIO_FN(SCIF0_RTS),
	GPIO_FN(SCIF0_CTS),
	GPIO_FN(SCIF0_SCK),

	/* SCIF1 */
	GPIO_FN(SCIF1_TXD),
	GPIO_FN(SCIF1_RXD),
	GPIO_FN(SCIF1_RTS),
	GPIO_FN(SCIF1_CTS),
	GPIO_FN(SCIF1_SCK),

	/* TPU */
	GPIO_FN(TPU_TO1),
	GPIO_FN(TPU_TO0),
	GPIO_FN(TPU_TI3B),
	GPIO_FN(TPU_TI3A),
	GPIO_FN(TPU_TI2B),
	GPIO_FN(TPU_TI2A),
	GPIO_FN(TPU_TO3),
	GPIO_FN(TPU_TO2),

	/* SIM */
	GPIO_FN(SIM_D),
	GPIO_FN(SIM_CLK),
	GPIO_FN(SIM_RST),

	/* MMC */
	GPIO_FN(MMC_DAT),
	GPIO_FN(MMC_CMD),
	GPIO_FN(MMC_CLK),
	GPIO_FN(MMC_VDDON),
	GPIO_FN(MMC_ODMOD),

	/* SYSC */
	GPIO_FN(STATUS0),
	GPIO_FN(STATUS1),
};

static const struct pinmux_cfg_reg pinmux_config_regs[] = {
	{ PINMUX_CFG_REG("PACR", 0xa4050100, 16, 2) {
		PTA7_FN, PTA7_OUT, 0, PTA7_IN,
		PTA6_FN, PTA6_OUT, 0, PTA6_IN,
		PTA5_FN, PTA5_OUT, 0, PTA5_IN,
		PTA4_FN, PTA4_OUT, 0, PTA4_IN,
		PTA3_FN, PTA3_OUT, 0, PTA3_IN,
		PTA2_FN, PTA2_OUT, 0, PTA2_IN,
		PTA1_FN, PTA1_OUT, 0, PTA1_IN,
		PTA0_FN, PTA0_OUT, 0, PTA0_IN }
	},
	{ PINMUX_CFG_REG("PBCR", 0xa4050102, 16, 2) {
		PTB7_FN, PTB7_OUT, 0, PTB7_IN,
		PTB6_FN, PTB6_OUT, 0, PTB6_IN,
		PTB5_FN, PTB5_OUT, 0, PTB5_IN,
		PTB4_FN, PTB4_OUT, 0, PTB4_IN,
		PTB3_FN, PTB3_OUT, 0, PTB3_IN,
		PTB2_FN, PTB2_OUT, 0, PTB2_IN,
		PTB1_FN, PTB1_OUT, 0, PTB1_IN,
		PTB0_FN, PTB0_OUT, 0, PTB0_IN }
	},
	{ PINMUX_CFG_REG("PCCR", 0xa4050104, 16, 2) {
		PTC7_FN, PTC7_OUT, 0, PTC7_IN,
		PTC6_FN, PTC6_OUT, 0, PTC6_IN,
		PTC5_FN, PTC5_OUT, 0, PTC5_IN,
		PTC4_FN, PTC4_OUT, 0, PTC4_IN,
		PTC3_FN, PTC3_OUT, 0, PTC3_IN,
		PTC2_FN, PTC2_OUT, 0, PTC2_IN,
		PTC1_FN, PTC1_OUT, 0, PTC1_IN,
		PTC0_FN, PTC0_OUT, 0, PTC0_IN }
	},
	{ PINMUX_CFG_REG("PDCR", 0xa4050106, 16, 2) {
		PTD7_FN, PTD7_OUT, 0, PTD7_IN,
		PTD6_FN, PTD6_OUT, 0, PTD6_IN,
		PTD5_FN, PTD5_OUT, 0, PTD5_IN,
		PTD4_FN, PTD4_OUT, 0, PTD4_IN,
		PTD3_FN, PTD3_OUT, 0, PTD3_IN,
		PTD2_FN, PTD2_OUT, 0, PTD2_IN,
		PTD1_FN, PTD1_OUT, 0, PTD1_IN,
		PTD0_FN, PTD0_OUT, 0, PTD0_IN }
	},
	{ PINMUX_CFG_REG("PECR", 0xa4050108, 16, 2) {
		0, 0, 0, 0,
		PTE6_FN, 0, 0, PTE6_IN,
		PTE5_FN, 0, 0, PTE5_IN,
		PTE4_FN, PTE4_OUT, 0, PTE4_IN,
		PTE3_FN, PTE3_OUT, 0, PTE3_IN,
		PTE2_FN, PTE2_OUT, 0, PTE2_IN,
		PTE1_FN, PTE1_OUT, 0, PTE1_IN,
		PTE0_FN, PTE0_OUT, 0, PTE0_IN }
	},
	{ PINMUX_CFG_REG("PFCR", 0xa405010a, 16, 2) {
		0, 0, 0, 0,
		PTF6_FN, 0, 0, PTF6_IN,
		PTF5_FN, 0, 0, PTF5_IN,
		PTF4_FN, 0, 0, PTF4_IN,
		PTF3_FN, 0, 0, PTF3_IN,
		PTF2_FN, 0, 0, PTF2_IN,
		PTF1_FN, 0, 0, PTF1_IN,
		PTF0_FN, 0, 0, PTF0_IN }
	},
	{ PINMUX_CFG_REG("PGCR", 0xa405010c, 16, 2) {
		0, 0, 0, 0,
		PTG6_FN, PTG6_OUT, 0, PTG6_IN,
		PTG5_FN, PTG5_OUT, 0, PTG5_IN,
		PTG4_FN, PTG4_OUT, 0, PTG4_IN,
		PTG3_FN, PTG3_OUT, 0, PTG3_IN,
		PTG2_FN, PTG2_OUT, 0, PTG2_IN,
		PTG1_FN, PTG1_OUT, 0, PTG1_IN,
		PTG0_FN, PTG0_OUT, 0, PTG0_IN }
	},
	{ PINMUX_CFG_REG("PHCR", 0xa405010e, 16, 2) {
		0, 0, 0, 0,
		PTH6_FN, PTH6_OUT, 0, PTH6_IN,
		PTH5_FN, PTH5_OUT, 0, PTH5_IN,
		PTH4_FN, PTH4_OUT, 0, PTH4_IN,
		PTH3_FN, PTH3_OUT, 0, PTH3_IN,
		PTH2_FN, PTH2_OUT, 0, PTH2_IN,
		PTH1_FN, PTH1_OUT, 0, PTH1_IN,
		PTH0_FN, PTH0_OUT, 0, PTH0_IN }
	},
	{ PINMUX_CFG_REG("PJCR", 0xa4050110, 16, 2) {
		0, 0, 0, 0,
		PTJ6_FN, PTJ6_OUT, 0, PTJ6_IN,
		PTJ5_FN, PTJ5_OUT, 0, PTJ5_IN,
		PTJ4_FN, PTJ4_OUT, 0, PTJ4_IN,
		PTJ3_FN, PTJ3_OUT, 0, PTJ3_IN,
		PTJ2_FN, PTJ2_OUT, 0, PTJ2_IN,
		PTJ1_FN, PTJ1_OUT, 0, PTJ1_IN,
		PTJ0_FN, PTJ0_OUT, 0, PTJ0_IN }
	},
	{ PINMUX_CFG_REG("PKCR", 0xa4050112, 16, 2) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		PTK3_FN, PTK3_OUT, 0, PTK3_IN,
		PTK2_FN, PTK2_OUT, 0, PTK2_IN,
		PTK1_FN, PTK1_OUT, 0, PTK1_IN,
		PTK0_FN, PTK0_OUT, 0, PTK0_IN }
	},
	{ PINMUX_CFG_REG("PLCR", 0xa4050114, 16, 2) {
		PTL7_FN, PTL7_OUT, 0, PTL7_IN,
		PTL6_FN, PTL6_OUT, 0, PTL6_IN,
		PTL5_FN, PTL5_OUT, 0, PTL5_IN,
		PTL4_FN, PTL4_OUT, 0, PTL4_IN,
		PTL3_FN, PTL3_OUT, 0, PTL3_IN,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }
	},
	{ PINMUX_CFG_REG("PMCR", 0xa4050116, 16, 2) {
		PTM7_FN, PTM7_OUT, 0, PTM7_IN,
		PTM6_FN, PTM6_OUT, 0, PTM6_IN,
		PTM5_FN, PTM5_OUT, 0, PTM5_IN,
		PTM4_FN, PTM4_OUT, 0, PTM4_IN,
		PTM3_FN, PTM3_OUT, 0, PTM3_IN,
		PTM2_FN, PTM2_OUT, 0, PTM2_IN,
		PTM1_FN, PTM1_OUT, 0, PTM1_IN,
		PTM0_FN, PTM0_OUT, 0, PTM0_IN }
	},
	{ PINMUX_CFG_REG("PPCR", 0xa4050118, 16, 2) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		PTP4_FN, PTP4_OUT, 0, PTP4_IN,
		PTP3_FN, PTP3_OUT, 0, PTP3_IN,
		PTP2_FN, PTP2_OUT, 0, PTP2_IN,
		PTP1_FN, PTP1_OUT, 0, PTP1_IN,
		PTP0_FN, PTP0_OUT, 0, PTP0_IN }
	},
	{ PINMUX_CFG_REG("PRCR", 0xa405011a, 16, 2) {
		PTR7_FN, PTR7_OUT, 0, PTR7_IN,
		PTR6_FN, PTR6_OUT, 0, PTR6_IN,
		PTR5_FN, PTR5_OUT, 0, PTR5_IN,
		PTR4_FN, PTR4_OUT, 0, PTR4_IN,
		PTR3_FN, PTR3_OUT, 0, PTR3_IN,
		PTR2_FN, PTR2_OUT, 0, PTR2_IN,
		PTR1_FN, PTR1_OUT, 0, PTR1_IN,
		PTR0_FN, PTR0_OUT, 0, PTR0_IN }
	},
	{ PINMUX_CFG_REG("PSCR", 0xa405011c, 16, 2) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		PTS4_FN, PTS4_OUT, 0, PTS4_IN,
		PTS3_FN, PTS3_OUT, 0, PTS3_IN,
		PTS2_FN, PTS2_OUT, 0, PTS2_IN,
		PTS1_FN, PTS1_OUT, 0, PTS1_IN,
		PTS0_FN, PTS0_OUT, 0, PTS0_IN }
	},
	{ PINMUX_CFG_REG("PTCR", 0xa405011e, 16, 2) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		PTT4_FN, PTT4_OUT, 0, PTT4_IN,
		PTT3_FN, PTT3_OUT, 0, PTT3_IN,
		PTT2_FN, PTT2_OUT, 0, PTT2_IN,
		PTT1_FN, PTT1_OUT, 0, PTT1_IN,
		PTT0_FN, PTT0_OUT, 0, PTT0_IN }
	},
	{ PINMUX_CFG_REG("PUCR", 0xa4050120, 16, 2) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		PTU4_FN, PTU4_OUT, 0, PTU4_IN,
		PTU3_FN, PTU3_OUT, 0, PTU3_IN,
		PTU2_FN, PTU2_OUT, 0, PTU2_IN,
		PTU1_FN, PTU1_OUT, 0, PTU1_IN,
		PTU0_FN, PTU0_OUT, 0, PTU0_IN }
	},
	{ PINMUX_CFG_REG("PVCR", 0xa4050122, 16, 2) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		PTV4_FN, PTV4_OUT, 0, PTV4_IN,
		PTV3_FN, PTV3_OUT, 0, PTV3_IN,
		PTV2_FN, PTV2_OUT, 0, PTV2_IN,
		PTV1_FN, PTV1_OUT, 0, PTV1_IN,
		PTV0_FN, PTV0_OUT, 0, PTV0_IN }
	},
	{}
};

static const struct pinmux_data_reg pinmux_data_regs[] = {
	{ PINMUX_DATA_REG("PADR", 0xa4050140, 8) {
		PTA7_DATA, PTA6_DATA, PTA5_DATA, PTA4_DATA,
		PTA3_DATA, PTA2_DATA, PTA1_DATA, PTA0_DATA }
	},
	{ PINMUX_DATA_REG("PBDR", 0xa4050142, 8) {
		PTB7_DATA, PTB6_DATA, PTB5_DATA, PTB4_DATA,
		PTB3_DATA, PTB2_DATA, PTB1_DATA, PTB0_DATA }
	},
	{ PINMUX_DATA_REG("PCDR", 0xa4050144, 8) {
		PTC7_DATA, PTC6_DATA, PTC5_DATA, PTC4_DATA,
		PTC3_DATA, PTC2_DATA, PTC1_DATA, PTC0_DATA }
	},
	{ PINMUX_DATA_REG("PDDR", 0xa4050126, 8) {
		PTD7_DATA, PTD6_DATA, PTD5_DATA, PTD4_DATA,
		PTD3_DATA, PTD2_DATA, PTD1_DATA, PTD0_DATA }
	},
	{ PINMUX_DATA_REG("PEDR", 0xa4050148, 8) {
		0, PTE6_DATA, PTE5_DATA, PTE4_DATA,
		PTE3_DATA, PTE2_DATA, PTE1_DATA, PTE0_DATA }
	},
	{ PINMUX_DATA_REG("PFDR", 0xa405014a, 8) {
		0, PTF6_DATA, PTF5_DATA, PTF4_DATA,
		PTF3_DATA, PTF2_DATA, PTF1_DATA, PTF0_DATA }
	},
	{ PINMUX_DATA_REG("PGDR", 0xa405014c, 8) {
		0, PTG6_DATA, PTG5_DATA, PTG4_DATA,
		PTG3_DATA, PTG2_DATA, PTG1_DATA, PTG0_DATA }
	},
	{ PINMUX_DATA_REG("PHDR", 0xa405014e, 8) {
		0, PTH6_DATA, PTH5_DATA, PTH4_DATA,
		PTH3_DATA, PTH2_DATA, PTH1_DATA, PTH0_DATA }
	},
	{ PINMUX_DATA_REG("PJDR", 0xa4050150, 8) {
		0, PTJ6_DATA, PTJ5_DATA, PTJ4_DATA,
		PTJ3_DATA, PTJ2_DATA, PTJ1_DATA, PTJ0_DATA }
	},
	{ PINMUX_DATA_REG("PKDR", 0xa4050152, 8) {
		0, 0, 0, 0,
		PTK3_DATA, PTK2_DATA, PTK1_DATA, PTK0_DATA }
	},
	{ PINMUX_DATA_REG("PLDR", 0xa4050154, 8) {
		PTL7_DATA, PTL6_DATA, PTL5_DATA, PTL4_DATA,
		PTL3_DATA, 0, 0, 0 }
	},
	{ PINMUX_DATA_REG("PMDR", 0xa4050156, 8) {
		PTM7_DATA, PTM6_DATA, PTM5_DATA, PTM4_DATA,
		PTM3_DATA, PTM2_DATA, PTM1_DATA, PTM0_DATA }
	},
	{ PINMUX_DATA_REG("PPDR", 0xa4050158, 8) {
		0, 0, 0, PTP4_DATA,
		PTP3_DATA, PTP2_DATA, PTP1_DATA, PTP0_DATA }
	},
	{ PINMUX_DATA_REG("PRDR", 0xa405015a, 8) {
		PTR7_DATA, PTR6_DATA, PTR5_DATA, PTR4_DATA,
		PTR3_DATA, PTR2_DATA, PTR1_DATA, PTR0_DATA }
	},
	{ PINMUX_DATA_REG("PSDR", 0xa405015c, 8) {
		0, 0, 0, PTS4_DATA,
		PTS3_DATA, PTS2_DATA, PTS1_DATA, PTS0_DATA }
	},
	{ PINMUX_DATA_REG("PTDR", 0xa405015e, 8) {
		0, 0, 0, PTT4_DATA,
		PTT3_DATA, PTT2_DATA, PTT1_DATA, PTT0_DATA }
	},
	{ PINMUX_DATA_REG("PUDR", 0xa4050160, 8) {
		0, 0, 0, PTU4_DATA,
		PTU3_DATA, PTU2_DATA, PTU1_DATA, PTU0_DATA }
	},
	{ PINMUX_DATA_REG("PVDR", 0xa4050162, 8) {
		0, 0, 0, PTV4_DATA,
		PTV3_DATA, PTV2_DATA, PTV1_DATA, PTV0_DATA }
	},
	{ },
};

const struct sh_pfc_soc_info sh7720_pinmux_info = {
	.name = "sh7720_pfc",
	.input = { PINMUX_INPUT_BEGIN, PINMUX_INPUT_END },
	.output = { PINMUX_OUTPUT_BEGIN, PINMUX_OUTPUT_END },
	.function = { PINMUX_FUNCTION_BEGIN, PINMUX_FUNCTION_END },

	.pins = pinmux_pins,
	.nr_pins = ARRAY_SIZE(pinmux_pins),
	.func_gpios = pinmux_func_gpios,
	.nr_func_gpios = ARRAY_SIZE(pinmux_func_gpios),

	.cfg_regs = pinmux_config_regs,
	.data_regs = pinmux_data_regs,

	.gpio_data = pinmux_data,
	.gpio_data_size = ARRAY_SIZE(pinmux_data),
};
