/*
 * arch/arm/mach-at91/include/mach/debug-macro.S
 *
 *  Copyright (C) 2003-2005 SAN People
 *
 * Debugging macro include header
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
*/

#include <mach/hardware.h>
#include <mach/at91_dbgu.h>

#if defined(CONFIG_AT91_DEBUG_LL_DBGU0)
#define AT91_DBGU AT91_BASE_DBGU0
#elif defined(CONFIG_AT91_DEBUG_LL_DBGU1)
#define AT91_DBGU AT91_BASE_DBGU1
#else
/* On sama5d4, use USART3 as low level serial console */
#define AT91_DBGU SAMA5D4_BASE_USART3
#endif

	.macro	addruart, rp, rv, tmp
	ldr	\rp, =AT91_DBGU				@ System peripherals (phys address)
	ldr	\rv, =AT91_IO_P2V(AT91_DBGU)		@ System peripherals (virt address)
	.endm

	.macro	senduart,rd,rx
	strb	\rd, [\rx, #(AT91_DBGU_THR)]		@ Write to Transmitter Holding Register
	.endm

	.macro	waituart,rd,rx
1001:	ldr	\rd, [\rx, #(AT91_DBGU_SR)]		@ Read Status Register
	tst	\rd, #AT91_DBGU_TXRDY			@ DBGU_TXRDY = 1 when ready to transmit
	beq	1001b
	.endm

	.macro	busyuart,rd,rx
1001:	ldr	\rd, [\rx, #(AT91_DBGU_SR)]		@ Read Status Register
	tst	\rd, #AT91_DBGU_TXEMPTY			@ DBGU_TXEMPTY = 1 when transmission complete
	beq	1001b
	.endm

