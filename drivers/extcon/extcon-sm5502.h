/*
 * sm5502.h
 *
 * Copyright (c) 2014 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#ifndef __LINUX_EXTCON_SM5502_H
#define __LINUX_EXTCON_SM5502_H

enum sm5502_types {
	TYPE_SM5502,
};

/* SM5502 registers */
enum sm5502_reg {
	SM5502_REG_DEVICE_ID = 0x01,
	SM5502_REG_CONTROL,
	SM5502_REG_INT1,
	SM5502_REG_INT2,
	SM5502_REG_INTMASK1,
	SM5502_REG_INTMASK2,
	SM5502_REG_ADC,
	SM5502_REG_TIMING_SET1,
	SM5502_REG_TIMING_SET2,
	SM5502_REG_DEV_TYPE1,
	SM5502_REG_DEV_TYPE2,
	SM5502_REG_BUTTON1,
	SM5502_REG_BUTTON2,
	SM5502_REG_CAR_KIT_STATUS,
	SM5502_REG_RSVD1,
	SM5502_REG_RSVD2,
	SM5502_REG_RSVD3,
	SM5502_REG_RSVD4,
	SM5502_REG_MANUAL_SW1,
	SM5502_REG_MANUAL_SW2,
	SM5502_REG_DEV_TYPE3,
	SM5502_REG_RSVD5,
	SM5502_REG_RSVD6,
	SM5502_REG_RSVD7,
	SM5502_REG_RSVD8,
	SM5502_REG_RSVD9,
	SM5502_REG_RESET,
	SM5502_REG_RSVD10,
	SM5502_REG_RESERVED_ID1,
	SM5502_REG_RSVD11,
	SM5502_REG_RSVD12,
	SM5502_REG_RESERVED_ID2,
	SM5502_REG_RSVD13,
	SM5502_REG_OCP,
	SM5502_REG_RSVD14,
	SM5502_REG_RSVD15,
	SM5502_REG_RSVD16,
	SM5502_REG_RSVD17,
	SM5502_REG_RSVD18,
	SM5502_REG_RSVD19,
	SM5502_REG_RSVD20,
	SM5502_REG_RSVD21,
	SM5502_REG_RSVD22,
	SM5502_REG_RSVD23,
	SM5502_REG_RSVD24,
	SM5502_REG_RSVD25,
	SM5502_REG_RSVD26,
	SM5502_REG_RSVD27,
	SM5502_REG_RSVD28,
	SM5502_REG_RSVD29,
	SM5502_REG_RSVD30,
	SM5502_REG_RSVD31,
	SM5502_REG_RSVD32,
	SM5502_REG_RSVD33,
	SM5502_REG_RSVD34,
	SM5502_REG_RSVD35,
	SM5502_REG_RSVD36,
	SM5502_REG_RESERVED_ID3,

	SM5502_REG_END,
};

/* Define SM5502 MASK/SHIFT constant */
#define SM5502_REG_DEVICE_ID_VENDOR_SHIFT	0
#define SM5502_REG_DEVICE_ID_VERSION_SHIFT	3
#define SM5502_REG_DEVICE_ID_VENDOR_MASK	(0x3 << SM5502_REG_DEVICE_ID_VENDOR_SHIFT)
#define SM5502_REG_DEVICE_ID_VERSION_MASK	(0x1f << SM5502_REG_DEVICE_ID_VERSION_SHIFT)

#define SM5502_REG_CONTROL_MASK_INT_SHIFT	0
#define SM5502_REG_CONTROL_WAIT_SHIFT		1
#define SM5502_REG_CONTROL_MANUAL_SW_SHIFT	2
#define SM5502_REG_CONTROL_RAW_DATA_SHIFT	3
#define SM5502_REG_CONTROL_SW_OPEN_SHIFT	4
#define SM5502_REG_CONTROL_MASK_INT_MASK	(0x1 << SM5502_REG_CONTROL_MASK_INT_SHIFT)
#define SM5502_REG_CONTROL_WAIT_MASK		(0x1 << SM5502_REG_CONTROL_WAIT_SHIFT)
#define SM5502_REG_CONTROL_MANUAL_SW_MASK	(0x1 << SM5502_REG_CONTROL_MANUAL_SW_SHIFT)
#define SM5502_REG_CONTROL_RAW_DATA_MASK	(0x1 << SM5502_REG_CONTROL_RAW_DATA_SHIFT)
#define SM5502_REG_CONTROL_SW_OPEN_MASK		(0x1 << SM5502_REG_CONTROL_SW_OPEN_SHIFT)

#define SM5502_REG_INTM1_ATTACH_SHIFT		0
#define SM5502_REG_INTM1_DETACH_SHIFT		1
#define SM5502_REG_INTM1_KP_SHIFT		2
#define SM5502_REG_INTM1_LKP_SHIFT		3
#define SM5502_REG_INTM1_LKR_SHIFT		4
#define SM5502_REG_INTM1_OVP_EVENT_SHIFT	5
#define SM5502_REG_INTM1_OCP_EVENT_SHIFT	6
#define SM5502_REG_INTM1_OVP_OCP_DIS_SHIFT	7
#define SM5502_REG_INTM1_ATTACH_MASK		(0x1 << SM5502_REG_INTM1_ATTACH_SHIFT)
#define SM5502_REG_INTM1_DETACH_MASK		(0x1 << SM5502_REG_INTM1_DETACH_SHIFT)
#define SM5502_REG_INTM1_KP_MASK		(0x1 << SM5502_REG_INTM1_KP_SHIFT)
#define SM5502_REG_INTM1_LKP_MASK		(0x1 << SM5502_REG_INTM1_LKP_SHIFT)
#define SM5502_REG_INTM1_LKR_MASK		(0x1 << SM5502_REG_INTM1_LKR_SHIFT)
#define SM5502_REG_INTM1_OVP_EVENT_MASK		(0x1 << SM5502_REG_INTM1_OVP_EVENT_SHIFT)
#define SM5502_REG_INTM1_OCP_EVENT_MASK		(0x1 << SM5502_REG_INTM1_OCP_EVENT_SHIFT)
#define SM5502_REG_INTM1_OVP_OCP_DIS_MASK	(0x1 << SM5502_REG_INTM1_OVP_OCP_DIS_SHIFT)

#define SM5502_REG_INTM2_VBUS_DET_SHIFT		0
#define SM5502_REG_INTM2_REV_ACCE_SHIFT		1
#define SM5502_REG_INTM2_ADC_CHG_SHIFT		2
#define SM5502_REG_INTM2_STUCK_KEY_SHIFT	3
#define SM5502_REG_INTM2_STUCK_KEY_RCV_SHIFT	4
#define SM5502_REG_INTM2_MHL_SHIFT		5
#define SM5502_REG_INTM2_VBUS_DET_MASK		(0x1 << SM5502_REG_INTM2_VBUS_DET_SHIFT)
#define SM5502_REG_INTM2_REV_ACCE_MASK		(0x1 << SM5502_REG_INTM2_REV_ACCE_SHIFT)
#define SM5502_REG_INTM2_ADC_CHG_MASK		(0x1 << SM5502_REG_INTM2_ADC_CHG_SHIFT)
#define SM5502_REG_INTM2_STUCK_KEY_MASK		(0x1 << SM5502_REG_INTM2_STUCK_KEY_SHIFT)
#define SM5502_REG_INTM2_STUCK_KEY_RCV_MASK	(0x1 << SM5502_REG_INTM2_STUCK_KEY_RCV_SHIFT)
#define SM5502_REG_INTM2_MHL_MASK		(0x1 << SM5502_REG_INTM2_MHL_SHIFT)

#define SM5502_REG_ADC_SHIFT			0
#define SM5502_REG_ADC_MASK			(0x1f << SM5502_REG_ADC_SHIFT)

#define SM5502_REG_TIMING_SET1_KEY_PRESS_SHIFT	4
#define SM5502_REG_TIMING_SET1_KEY_PRESS_MASK	(0xf << SM5502_REG_TIMING_SET1_KEY_PRESS_SHIFT)
#define TIMING_KEY_PRESS_100MS			0x0
#define TIMING_KEY_PRESS_200MS			0x1
#define TIMING_KEY_PRESS_300MS			0x2
#define TIMING_KEY_PRESS_400MS			0x3
#define TIMING_KEY_PRESS_500MS			0x4
#define TIMING_KEY_PRESS_600MS			0x5
#define TIMING_KEY_PRESS_700MS			0x6
#define TIMING_KEY_PRESS_800MS			0x7
#define TIMING_KEY_PRESS_900MS			0x8
#define TIMING_KEY_PRESS_1000MS			0x9
#define SM5502_REG_TIMING_SET1_ADC_DET_SHIFT	0
#define SM5502_REG_TIMING_SET1_ADC_DET_MASK	(0xf << SM5502_REG_TIMING_SET1_ADC_DET_SHIFT)
#define TIMING_ADC_DET_50MS			0x0
#define TIMING_ADC_DET_100MS			0x1
#define TIMING_ADC_DET_150MS			0x2
#define TIMING_ADC_DET_200MS			0x3
#define TIMING_ADC_DET_300MS			0x4
#define TIMING_ADC_DET_400MS			0x5
#define TIMING_ADC_DET_500MS			0x6
#define TIMING_ADC_DET_600MS			0x7
#define TIMING_ADC_DET_700MS			0x8
#define TIMING_ADC_DET_800MS			0x9
#define TIMING_ADC_DET_900MS			0xA
#define TIMING_ADC_DET_1000MS			0xB

#define SM5502_REG_TIMING_SET2_SW_WAIT_SHIFT	4
#define SM5502_REG_TIMING_SET2_SW_WAIT_MASK	(0xf << SM5502_REG_TIMING_SET2_SW_WAIT_SHIFT)
#define TIMING_SW_WAIT_10MS			0x0
#define TIMING_SW_WAIT_30MS			0x1
#define TIMING_SW_WAIT_50MS			0x2
#define TIMING_SW_WAIT_70MS			0x3
#define TIMING_SW_WAIT_90MS			0x4
#define TIMING_SW_WAIT_110MS			0x5
#define TIMING_SW_WAIT_130MS			0x6
#define TIMING_SW_WAIT_150MS			0x7
#define TIMING_SW_WAIT_170MS			0x8
#define TIMING_SW_WAIT_190MS			0x9
#define TIMING_SW_WAIT_210MS			0xA
#define SM5502_REG_TIMING_SET2_LONG_KEY_SHIFT	0
#define SM5502_REG_TIMING_SET2_LONG_KEY_MASK	(0xf << SM5502_REG_TIMING_SET2_LONG_KEY_SHIFT)
#define TIMING_LONG_KEY_300MS			0x0
#define TIMING_LONG_KEY_400MS			0x1
#define TIMING_LONG_KEY_500MS			0x2
#define TIMING_LONG_KEY_600MS			0x3
#define TIMING_LONG_KEY_700MS			0x4
#define TIMING_LONG_KEY_800MS			0x5
#define TIMING_LONG_KEY_900MS			0x6
#define TIMING_LONG_KEY_1000MS			0x7
#define TIMING_LONG_KEY_1100MS			0x8
#define TIMING_LONG_KEY_1200MS			0x9
#define TIMING_LONG_KEY_1300MS			0xA
#define TIMING_LONG_KEY_1400MS			0xB
#define TIMING_LONG_KEY_1500MS			0xC

#define SM5502_REG_DEV_TYPE1_AUDIO_TYPE1_SHIFT		0
#define SM5502_REG_DEV_TYPE1_AUDIO_TYPE2_SHIFT		1
#define SM5502_REG_DEV_TYPE1_USB_SDP_SHIFT		2
#define SM5502_REG_DEV_TYPE1_UART_SHIFT			3
#define SM5502_REG_DEV_TYPE1_CAR_KIT_CHARGER_SHIFT	4
#define SM5502_REG_DEV_TYPE1_USB_CHG_SHIFT		5
#define SM5502_REG_DEV_TYPE1_DEDICATED_CHG_SHIFT	6
#define SM5502_REG_DEV_TYPE1_USB_OTG_SHIFT		7
#define SM5502_REG_DEV_TYPE1_AUDIO_TYPE1_MASK		(0x1 << SM5502_REG_DEV_TYPE1_AUDIO_TYPE1_SHIFT)
#define SM5502_REG_DEV_TYPE1_AUDIO_TYPE1__MASK		(0x1 << SM5502_REG_DEV_TYPE1_AUDIO_TYPE2_SHIFT)
#define SM5502_REG_DEV_TYPE1_USB_SDP_MASK		(0x1 << SM5502_REG_DEV_TYPE1_USB_SDP_SHIFT)
#define SM5502_REG_DEV_TYPE1_UART_MASK			(0x1 << SM5502_REG_DEV_TYPE1_UART_SHIFT)
#define SM5502_REG_DEV_TYPE1_CAR_KIT_CHARGER_MASK	(0x1 << SM5502_REG_DEV_TYPE1_CAR_KIT_CHARGER_SHIFT)
#define SM5502_REG_DEV_TYPE1_USB_CHG_MASK		(0x1 << SM5502_REG_DEV_TYPE1_USB_CHG_SHIFT)
#define SM5502_REG_DEV_TYPE1_DEDICATED_CHG_MASK		(0x1 << SM5502_REG_DEV_TYPE1_DEDICATED_CHG_SHIFT)
#define SM5502_REG_DEV_TYPE1_USB_OTG_MASK		(0x1 << SM5502_REG_DEV_TYPE1_USB_OTG_SHIFT)

#define SM5502_REG_DEV_TYPE2_JIG_USB_ON_SHIFT		0
#define SM5502_REG_DEV_TYPE2_JIG_USB_OFF_SHIFT		1
#define SM5502_REG_DEV_TYPE2_JIG_UART_ON_SHIFT		2
#define SM5502_REG_DEV_TYPE2_JIG_UART_OFF_SHIFT		3
#define SM5502_REG_DEV_TYPE2_PPD_SHIFT			4
#define SM5502_REG_DEV_TYPE2_TTY_SHIFT			5
#define SM5502_REG_DEV_TYPE2_AV_CABLE_SHIFT		6
#define SM5502_REG_DEV_TYPE2_JIG_USB_ON_MASK		(0x1 << SM5502_REG_DEV_TYPE2_JIG_USB_ON_SHIFT)
#define SM5502_REG_DEV_TYPE2_JIG_USB_OFF_MASK		(0x1 << SM5502_REG_DEV_TYPE2_JIG_USB_OFF_SHIFT)
#define SM5502_REG_DEV_TYPE2_JIG_UART_ON_MASK		(0x1 << SM5502_REG_DEV_TYPE2_JIG_UART_ON_SHIFT)
#define SM5502_REG_DEV_TYPE2_JIG_UART_OFF_MASK		(0x1 << SM5502_REG_DEV_TYPE2_JIG_UART_OFF_SHIFT)
#define SM5502_REG_DEV_TYPE2_PPD_MASK			(0x1 << SM5502_REG_DEV_TYPE2_PPD_SHIFT)
#define SM5502_REG_DEV_TYPE2_TTY_MASK			(0x1 << SM5502_REG_DEV_TYPE2_TTY_SHIFT)
#define SM5502_REG_DEV_TYPE2_AV_CABLE_MASK		(0x1 << SM5502_REG_DEV_TYPE2_AV_CABLE_SHIFT)

#define SM5502_REG_MANUAL_SW1_VBUSIN_SHIFT	0
#define SM5502_REG_MANUAL_SW1_DP_SHIFT		2
#define SM5502_REG_MANUAL_SW1_DM_SHIFT		5
#define SM5502_REG_MANUAL_SW1_VBUSIN_MASK	(0x3 << SM5502_REG_MANUAL_SW1_VBUSIN_SHIFT)
#define SM5502_REG_MANUAL_SW1_DP_MASK		(0x7 << SM5502_REG_MANUAL_SW1_DP_SHIFT)
#define SM5502_REG_MANUAL_SW1_DM_MASK		(0x7 << SM5502_REG_MANUAL_SW1_DM_SHIFT)
#define VBUSIN_SWITCH_OPEN			0x0
#define VBUSIN_SWITCH_VBUSOUT			0x1
#define VBUSIN_SWITCH_MIC			0x2
#define VBUSIN_SWITCH_VBUSOUT_WITH_USB		0x3
#define DM_DP_CON_SWITCH_OPEN			0x0
#define DM_DP_CON_SWITCH_USB			0x1
#define DM_DP_CON_SWITCH_AUDIO			0x2
#define DM_DP_CON_SWITCH_UART			0x3
#define DM_DP_SWITCH_OPEN			((DM_DP_CON_SWITCH_OPEN <<SM5502_REG_MANUAL_SW1_DP_SHIFT) \
						| (DM_DP_CON_SWITCH_OPEN <<SM5502_REG_MANUAL_SW1_DM_SHIFT))
#define DM_DP_SWITCH_USB			((DM_DP_CON_SWITCH_USB <<SM5502_REG_MANUAL_SW1_DP_SHIFT) \
						| (DM_DP_CON_SWITCH_USB <<SM5502_REG_MANUAL_SW1_DM_SHIFT))
#define DM_DP_SWITCH_AUDIO			((DM_DP_CON_SWITCH_AUDIO <<SM5502_REG_MANUAL_SW1_DP_SHIFT) \
						| (DM_DP_CON_SWITCH_AUDIO <<SM5502_REG_MANUAL_SW1_DM_SHIFT))
#define DM_DP_SWITCH_UART			((DM_DP_CON_SWITCH_UART <<SM5502_REG_MANUAL_SW1_DP_SHIFT) \
						| (DM_DP_CON_SWITCH_UART <<SM5502_REG_MANUAL_SW1_DM_SHIFT))

/* SM5502 Interrupts */
enum sm5502_irq {
	/* INT1 */
	SM5502_IRQ_INT1_ATTACH,
	SM5502_IRQ_INT1_DETACH,
	SM5502_IRQ_INT1_KP,
	SM5502_IRQ_INT1_LKP,
	SM5502_IRQ_INT1_LKR,
	SM5502_IRQ_INT1_OVP_EVENT,
	SM5502_IRQ_INT1_OCP_EVENT,
	SM5502_IRQ_INT1_OVP_OCP_DIS,

	/* INT2 */
	SM5502_IRQ_INT2_VBUS_DET,
	SM5502_IRQ_INT2_REV_ACCE,
	SM5502_IRQ_INT2_ADC_CHG,
	SM5502_IRQ_INT2_STUCK_KEY,
	SM5502_IRQ_INT2_STUCK_KEY_RCV,
	SM5502_IRQ_INT2_MHL,

	SM5502_IRQ_NUM,
};

#define SM5502_IRQ_INT1_ATTACH_MASK		BIT(0)
#define SM5502_IRQ_INT1_DETACH_MASK		BIT(1)
#define SM5502_IRQ_INT1_KP_MASK			BIT(2)
#define SM5502_IRQ_INT1_LKP_MASK		BIT(3)
#define SM5502_IRQ_INT1_LKR_MASK		BIT(4)
#define SM5502_IRQ_INT1_OVP_EVENT_MASK		BIT(5)
#define SM5502_IRQ_INT1_OCP_EVENT_MASK		BIT(6)
#define SM5502_IRQ_INT1_OVP_OCP_DIS_MASK	BIT(7)
#define SM5502_IRQ_INT2_VBUS_DET_MASK		BIT(0)
#define SM5502_IRQ_INT2_REV_ACCE_MASK		BIT(1)
#define SM5502_IRQ_INT2_ADC_CHG_MASK		BIT(2)
#define SM5502_IRQ_INT2_STUCK_KEY_MASK		BIT(3)
#define SM5502_IRQ_INT2_STUCK_KEY_RCV_MASK	BIT(4)
#define SM5502_IRQ_INT2_MHL_MASK		BIT(5)

#endif /*  __LINUX_EXTCON_SM5502_H */
