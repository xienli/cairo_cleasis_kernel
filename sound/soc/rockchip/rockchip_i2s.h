/*
 * sound/soc/rockchip/rockchip_i2s.h
 *
 * ALSA SoC Audio Layer - Rockchip I2S Controller driver
 *
 * Copyright (c) 2014 Rockchip Electronics Co. Ltd.
 * Author: Jianqun xu <jay.xu@rock-chips.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _ROCKCHIP_IIS_H
#define _ROCKCHIP_IIS_H

/*
 * TXCR
 * transmit operation control register
*/
#define I2S_TXCR_RCNT_SHIFT	17
#define I2S_TXCR_RCNT_MASK	(0x3f << I2S_TXCR_RCNT_SHIFT)
#define I2S_TXCR_CSR_SHIFT	15
#define I2S_TXCR_CSR(x)		(x << I2S_TXCR_CSR_SHIFT)
#define I2S_TXCR_CSR_MASK	(3 << I2S_TXCR_CSR_SHIFT)
#define I2S_TXCR_HWT		BIT(14)
#define I2S_TXCR_SJM_SHIFT	12
#define I2S_TXCR_SJM_R		(0 << I2S_TXCR_SJM_SHIFT)
#define I2S_TXCR_SJM_L		(1 << I2S_TXCR_SJM_SHIFT)
#define I2S_TXCR_FBM_SHIFT	11
#define I2S_TXCR_FBM_MSB	(0 << I2S_TXCR_FBM_SHIFT)
#define I2S_TXCR_FBM_LSB	(1 << I2S_TXCR_FBM_SHIFT)
#define I2S_TXCR_IBM_SHIFT	9
#define I2S_TXCR_IBM_NORMAL	(0 << I2S_TXCR_IBM_SHIFT)
#define I2S_TXCR_IBM_LSJM	(1 << I2S_TXCR_IBM_SHIFT)
#define I2S_TXCR_IBM_RSJM	(2 << I2S_TXCR_IBM_SHIFT)
#define I2S_TXCR_IBM_MASK	(3 << I2S_TXCR_IBM_SHIFT)
#define I2S_TXCR_PBM_SHIFT	7
#define I2S_TXCR_PBM_MODE(x)	(x << I2S_TXCR_PBM_SHIFT)
#define I2S_TXCR_PBM_MASK	(3 << I2S_TXCR_PBM_SHIFT)
#define I2S_TXCR_TFS_SHIFT	5
#define I2S_TXCR_TFS_I2S	(0 << I2S_TXCR_TFS_SHIFT)
#define I2S_TXCR_TFS_PCM	(1 << I2S_TXCR_TFS_SHIFT)
#define I2S_TXCR_VDW_SHIFT	0
#define I2S_TXCR_VDW(x)		((x - 1) << I2S_TXCR_VDW_SHIFT)
#define I2S_TXCR_VDW_MASK	(0x1f << I2S_TXCR_VDW_SHIFT)

/*
 * RXCR
 * receive operation control register
*/
#define I2S_RXCR_HWT		BIT(14)
#define I2S_RXCR_SJM_SHIFT	12
#define I2S_RXCR_SJM_R		(0 << I2S_RXCR_SJM_SHIFT)
#define I2S_RXCR_SJM_L		(1 << I2S_RXCR_SJM_SHIFT)
#define I2S_RXCR_FBM_SHIFT	11
#define I2S_RXCR_FBM_MSB	(0 << I2S_RXCR_FBM_SHIFT)
#define I2S_RXCR_FBM_LSB	(1 << I2S_RXCR_FBM_SHIFT)
#define I2S_RXCR_IBM_SHIFT	9
#define I2S_RXCR_IBM_NORMAL	(0 << I2S_RXCR_IBM_SHIFT)
#define I2S_RXCR_IBM_LSJM	(1 << I2S_RXCR_IBM_SHIFT)
#define I2S_RXCR_IBM_RSJM	(2 << I2S_RXCR_IBM_SHIFT)
#define I2S_RXCR_IBM_MASK	(3 << I2S_RXCR_IBM_SHIFT)
#define I2S_RXCR_PBM_SHIFT	7
#define I2S_RXCR_PBM_MODE(x)	(x << I2S_RXCR_PBM_SHIFT)
#define I2S_RXCR_PBM_MASK	(3 << I2S_RXCR_PBM_SHIFT)
#define I2S_RXCR_TFS_SHIFT	5
#define I2S_RXCR_TFS_I2S	(0 << I2S_RXCR_TFS_SHIFT)
#define I2S_RXCR_TFS_PCM	(1 << I2S_RXCR_TFS_SHIFT)
#define I2S_RXCR_VDW_SHIFT	0
#define I2S_RXCR_VDW(x)		((x - 1) << I2S_RXCR_VDW_SHIFT)
#define I2S_RXCR_VDW_MASK	(0x1f << I2S_RXCR_VDW_SHIFT)

/*
 * CKR
 * clock generation register
*/
#define I2S_CKR_MSS_SHIFT	27
#define I2S_CKR_MSS_MASTER	(0 << I2S_CKR_MSS_SHIFT)
#define I2S_CKR_MSS_SLAVE	(1 << I2S_CKR_MSS_SHIFT)
#define I2S_CKR_MSS_MASK	(1 << I2S_CKR_MSS_SHIFT)
#define I2S_CKR_CKP_SHIFT	26
#define I2S_CKR_CKP_NEG		(0 << I2S_CKR_CKP_SHIFT)
#define I2S_CKR_CKP_POS		(1 << I2S_CKR_CKP_SHIFT)
#define I2S_CKR_RLP_SHIFT	25
#define I2S_CKR_RLP_NORMAL	(0 << I2S_CKR_RLP_SHIFT)
#define I2S_CKR_RLP_OPPSITE	(1 << I2S_CKR_RLP_SHIFT)
#define I2S_CKR_TLP_SHIFT	24
#define I2S_CKR_TLP_NORMAL	(0 << I2S_CKR_TLP_SHIFT)
#define I2S_CKR_TLP_OPPSITE	(1 << I2S_CKR_TLP_SHIFT)
#define I2S_CKR_MDIV_SHIFT	16
#define I2S_CKR_MDIV(x)		((x - 1) << I2S_CKR_MDIV_SHIFT)
#define I2S_CKR_MDIV_MASK	(0xff << I2S_CKR_MDIV_SHIFT)
#define I2S_CKR_RSD_SHIFT	8
#define I2S_CKR_RSD(x)		((x - 1) << I2S_CKR_RSD_SHIFT)
#define I2S_CKR_RSD_MASK	(0xff << I2S_CKR_RSD_SHIFT)
#define I2S_CKR_TSD_SHIFT	0
#define I2S_CKR_TSD(x)		((x - 1) << I2S_CKR_TSD_SHIFT)
#define I2S_CKR_TSD_MASK	(0xff << I2S_CKR_TSD_SHIFT)

/*
 * FIFOLR
 * FIFO level register
*/
#define I2S_FIFOLR_RFL_SHIFT	24
#define I2S_FIFOLR_RFL_MASK	(0x3f << I2S_FIFOLR_RFL_SHIFT)
#define I2S_FIFOLR_TFL3_SHIFT	18
#define I2S_FIFOLR_TFL3_MASK	(0x3f << I2S_FIFOLR_TFL3_SHIFT)
#define I2S_FIFOLR_TFL2_SHIFT	12
#define I2S_FIFOLR_TFL2_MASK	(0x3f << I2S_FIFOLR_TFL2_SHIFT)
#define I2S_FIFOLR_TFL1_SHIFT	6
#define I2S_FIFOLR_TFL1_MASK	(0x3f << I2S_FIFOLR_TFL1_SHIFT)
#define I2S_FIFOLR_TFL0_SHIFT	0
#define I2S_FIFOLR_TFL0_MASK	(0x3f << I2S_FIFOLR_TFL0_SHIFT)

/*
 * DMACR
 * DMA control register
*/
#define I2S_DMACR_RDE_SHIFT	24
#define I2S_DMACR_RDE_DISABLE	(0 << I2S_DMACR_RDE_SHIFT)
#define I2S_DMACR_RDE_ENABLE	(1 << I2S_DMACR_RDE_SHIFT)
#define I2S_DMACR_RDL_SHIFT	16
#define I2S_DMACR_RDL(x)	((x - 1) << I2S_DMACR_RDL_SHIFT)
#define I2S_DMACR_RDL_MASK	(0x1f << I2S_DMACR_RDL_SHIFT)
#define I2S_DMACR_TDE_SHIFT	8
#define I2S_DMACR_TDE_DISABLE	(0 << I2S_DMACR_TDE_SHIFT)
#define I2S_DMACR_TDE_ENABLE	(1 << I2S_DMACR_TDE_SHIFT)
#define I2S_DMACR_TDL_SHIFT	0
#define I2S_DMACR_TDL(x)	((x - 1) << I2S_DMACR_TDL_SHIFT)
#define I2S_DMACR_TDL_MASK	(0x1f << I2S_DMACR_TDL_SHIFT)

/*
 * INTCR
 * interrupt control register
*/
#define I2S_INTCR_RFT_SHIFT	20
#define I2S_INTCR_RFT(x)	((x - 1) << I2S_INTCR_RFT_SHIFT)
#define I2S_INTCR_RXOIC		BIT(18)
#define I2S_INTCR_RXOIE_SHIFT	17
#define I2S_INTCR_RXOIE_DISABLE	(0 << I2S_INTCR_RXOIE_SHIFT)
#define I2S_INTCR_RXOIE_ENABLE	(1 << I2S_INTCR_RXOIE_SHIFT)
#define I2S_INTCR_RXFIE_SHIFT	16
#define I2S_INTCR_RXFIE_DISABLE	(0 << I2S_INTCR_RXFIE_SHIFT)
#define I2S_INTCR_RXFIE_ENABLE	(1 << I2S_INTCR_RXFIE_SHIFT)
#define I2S_INTCR_TFT_SHIFT	4
#define I2S_INTCR_TFT(x)	((x - 1) << I2S_INTCR_TFT_SHIFT)
#define I2S_INTCR_TFT_MASK	(0x1f << I2S_INTCR_TFT_SHIFT)
#define I2S_INTCR_TXUIC		BIT(2)
#define I2S_INTCR_TXUIE_SHIFT	1
#define I2S_INTCR_TXUIE_DISABLE	(0 << I2S_INTCR_TXUIE_SHIFT)
#define I2S_INTCR_TXUIE_ENABLE	(1 << I2S_INTCR_TXUIE_SHIFT)

/*
 * INTSR
 * interrupt status register
*/
#define I2S_INTSR_TXEIE_SHIFT	0
#define I2S_INTSR_TXEIE_DISABLE	(0 << I2S_INTSR_TXEIE_SHIFT)
#define I2S_INTSR_TXEIE_ENABLE	(1 << I2S_INTSR_TXEIE_SHIFT)
#define I2S_INTSR_RXOI_SHIFT	17
#define I2S_INTSR_RXOI_INA	(0 << I2S_INTSR_RXOI_SHIFT)
#define I2S_INTSR_RXOI_ACT	(1 << I2S_INTSR_RXOI_SHIFT)
#define I2S_INTSR_RXFI_SHIFT	16
#define I2S_INTSR_RXFI_INA	(0 << I2S_INTSR_RXFI_SHIFT)
#define I2S_INTSR_RXFI_ACT	(1 << I2S_INTSR_RXFI_SHIFT)
#define I2S_INTSR_TXUI_SHIFT	1
#define I2S_INTSR_TXUI_INA	(0 << I2S_INTSR_TXUI_SHIFT)
#define I2S_INTSR_TXUI_ACT	(1 << I2S_INTSR_TXUI_SHIFT)
#define I2S_INTSR_TXEI_SHIFT	0
#define I2S_INTSR_TXEI_INA	(0 << I2S_INTSR_TXEI_SHIFT)
#define I2S_INTSR_TXEI_ACT	(1 << I2S_INTSR_TXEI_SHIFT)

/*
 * XFER
 * Transfer start register
*/
#define I2S_XFER_RXS_SHIFT	1
#define I2S_XFER_RXS_STOP	(0 << I2S_XFER_RXS_SHIFT)
#define I2S_XFER_RXS_START	(1 << I2S_XFER_RXS_SHIFT)
#define I2S_XFER_TXS_SHIFT	0
#define I2S_XFER_TXS_STOP	(0 << I2S_XFER_TXS_SHIFT)
#define I2S_XFER_TXS_START	(1 << I2S_XFER_TXS_SHIFT)

/*
 * CLR
 * clear SCLK domain logic register
*/
#define I2S_CLR_RXC	BIT(1)
#define I2S_CLR_TXC	BIT(0)

/*
 * TXDR
 * Transimt FIFO data register, write only.
*/
#define I2S_TXDR_MASK	(0xff)

/*
 * RXDR
 * Receive FIFO data register, write only.
*/
#define I2S_RXDR_MASK	(0xff)

/* Clock divider id */
enum {
	ROCKCHIP_DIV_MCLK = 0,
	ROCKCHIP_DIV_BCLK,
};

/* I2S REGS */
#define I2S_TXCR	(0x0000)
#define I2S_RXCR	(0x0004)
#define I2S_CKR		(0x0008)
#define I2S_FIFOLR	(0x000c)
#define I2S_DMACR	(0x0010)
#define I2S_INTCR	(0x0014)
#define I2S_INTSR	(0x0018)
#define I2S_XFER	(0x001c)
#define I2S_CLR		(0x0020)
#define I2S_TXDR	(0x0024)
#define I2S_RXDR	(0x0028)

#endif /* _ROCKCHIP_IIS_H */
