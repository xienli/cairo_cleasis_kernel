/* Include file for the EP93XX GPIO controller machine specifics */

#ifndef __GPIO_EP93XX_H
#define __GPIO_EP93XX_H

#include <mach/ep93xx-regs.h>

#define EP93XX_GPIO_PHYS_BASE		EP93XX_APB_PHYS(0x00040000)
#define EP93XX_GPIO_BASE		EP93XX_APB_IOMEM(0x00040000)
#define EP93XX_GPIO_REG(x)		(EP93XX_GPIO_BASE + (x))
#define EP93XX_GPIO_F_INT_STATUS	EP93XX_GPIO_REG(0x5c)
#define EP93XX_GPIO_A_INT_STATUS	EP93XX_GPIO_REG(0xa0)
#define EP93XX_GPIO_B_INT_STATUS	EP93XX_GPIO_REG(0xbc)
#define EP93XX_GPIO_EEDRIVE		EP93XX_GPIO_REG(0xc8)

/* GPIO port A.  */
#define EP93XX_GPIO_LINE_A(x)		((x) + 0)
#define EP93XX_GPIO_LINE_EGPIO0		EP93XX_GPIO_LINE_A(0)
#define EP93XX_GPIO_LINE_EGPIO1		EP93XX_GPIO_LINE_A(1)
#define EP93XX_GPIO_LINE_EGPIO2		EP93XX_GPIO_LINE_A(2)
#define EP93XX_GPIO_LINE_EGPIO3		EP93XX_GPIO_LINE_A(3)
#define EP93XX_GPIO_LINE_EGPIO4		EP93XX_GPIO_LINE_A(4)
#define EP93XX_GPIO_LINE_EGPIO5		EP93XX_GPIO_LINE_A(5)
#define EP93XX_GPIO_LINE_EGPIO6		EP93XX_GPIO_LINE_A(6)
#define EP93XX_GPIO_LINE_EGPIO7		EP93XX_GPIO_LINE_A(7)

/* GPIO port B.  */
#define EP93XX_GPIO_LINE_B(x)		((x) + 8)
#define EP93XX_GPIO_LINE_EGPIO8		EP93XX_GPIO_LINE_B(0)
#define EP93XX_GPIO_LINE_EGPIO9		EP93XX_GPIO_LINE_B(1)
#define EP93XX_GPIO_LINE_EGPIO10	EP93XX_GPIO_LINE_B(2)
#define EP93XX_GPIO_LINE_EGPIO11	EP93XX_GPIO_LINE_B(3)
#define EP93XX_GPIO_LINE_EGPIO12	EP93XX_GPIO_LINE_B(4)
#define EP93XX_GPIO_LINE_EGPIO13	EP93XX_GPIO_LINE_B(5)
#define EP93XX_GPIO_LINE_EGPIO14	EP93XX_GPIO_LINE_B(6)
#define EP93XX_GPIO_LINE_EGPIO15	EP93XX_GPIO_LINE_B(7)

/* GPIO port C.  */
#define EP93XX_GPIO_LINE_C(x)		((x) + 40)
#define EP93XX_GPIO_LINE_ROW0		EP93XX_GPIO_LINE_C(0)
#define EP93XX_GPIO_LINE_ROW1		EP93XX_GPIO_LINE_C(1)
#define EP93XX_GPIO_LINE_ROW2		EP93XX_GPIO_LINE_C(2)
#define EP93XX_GPIO_LINE_ROW3		EP93XX_GPIO_LINE_C(3)
#define EP93XX_GPIO_LINE_ROW4		EP93XX_GPIO_LINE_C(4)
#define EP93XX_GPIO_LINE_ROW5		EP93XX_GPIO_LINE_C(5)
#define EP93XX_GPIO_LINE_ROW6		EP93XX_GPIO_LINE_C(6)
#define EP93XX_GPIO_LINE_ROW7		EP93XX_GPIO_LINE_C(7)

/* GPIO port D.  */
#define EP93XX_GPIO_LINE_D(x)		((x) + 24)
#define EP93XX_GPIO_LINE_COL0		EP93XX_GPIO_LINE_D(0)
#define EP93XX_GPIO_LINE_COL1		EP93XX_GPIO_LINE_D(1)
#define EP93XX_GPIO_LINE_COL2		EP93XX_GPIO_LINE_D(2)
#define EP93XX_GPIO_LINE_COL3		EP93XX_GPIO_LINE_D(3)
#define EP93XX_GPIO_LINE_COL4		EP93XX_GPIO_LINE_D(4)
#define EP93XX_GPIO_LINE_COL5		EP93XX_GPIO_LINE_D(5)
#define EP93XX_GPIO_LINE_COL6		EP93XX_GPIO_LINE_D(6)
#define EP93XX_GPIO_LINE_COL7		EP93XX_GPIO_LINE_D(7)

/* GPIO port E.  */
#define EP93XX_GPIO_LINE_E(x)		((x) + 32)
#define EP93XX_GPIO_LINE_GRLED		EP93XX_GPIO_LINE_E(0)
#define EP93XX_GPIO_LINE_RDLED		EP93XX_GPIO_LINE_E(1)
#define EP93XX_GPIO_LINE_DIORn		EP93XX_GPIO_LINE_E(2)
#define EP93XX_GPIO_LINE_IDECS1n	EP93XX_GPIO_LINE_E(3)
#define EP93XX_GPIO_LINE_IDECS2n	EP93XX_GPIO_LINE_E(4)
#define EP93XX_GPIO_LINE_IDEDA0		EP93XX_GPIO_LINE_E(5)
#define EP93XX_GPIO_LINE_IDEDA1		EP93XX_GPIO_LINE_E(6)
#define EP93XX_GPIO_LINE_IDEDA2		EP93XX_GPIO_LINE_E(7)

/* GPIO port F.  */
#define EP93XX_GPIO_LINE_F(x)		((x) + 16)
#define EP93XX_GPIO_LINE_WP		EP93XX_GPIO_LINE_F(0)
#define EP93XX_GPIO_LINE_MCCD1		EP93XX_GPIO_LINE_F(1)
#define EP93XX_GPIO_LINE_MCCD2		EP93XX_GPIO_LINE_F(2)
#define EP93XX_GPIO_LINE_MCBVD1		EP93XX_GPIO_LINE_F(3)
#define EP93XX_GPIO_LINE_MCBVD2		EP93XX_GPIO_LINE_F(4)
#define EP93XX_GPIO_LINE_VS1		EP93XX_GPIO_LINE_F(5)
#define EP93XX_GPIO_LINE_READY		EP93XX_GPIO_LINE_F(6)
#define EP93XX_GPIO_LINE_VS2		EP93XX_GPIO_LINE_F(7)

/* GPIO port G.  */
#define EP93XX_GPIO_LINE_G(x)		((x) + 48)
#define EP93XX_GPIO_LINE_EECLK		EP93XX_GPIO_LINE_G(0)
#define EP93XX_GPIO_LINE_EEDAT		EP93XX_GPIO_LINE_G(1)
#define EP93XX_GPIO_LINE_SLA0		EP93XX_GPIO_LINE_G(2)
#define EP93XX_GPIO_LINE_SLA1		EP93XX_GPIO_LINE_G(3)
#define EP93XX_GPIO_LINE_DD12		EP93XX_GPIO_LINE_G(4)
#define EP93XX_GPIO_LINE_DD13		EP93XX_GPIO_LINE_G(5)
#define EP93XX_GPIO_LINE_DD14		EP93XX_GPIO_LINE_G(6)
#define EP93XX_GPIO_LINE_DD15		EP93XX_GPIO_LINE_G(7)

/* GPIO port H.  */
#define EP93XX_GPIO_LINE_H(x)		((x) + 56)
#define EP93XX_GPIO_LINE_DD0		EP93XX_GPIO_LINE_H(0)
#define EP93XX_GPIO_LINE_DD1		EP93XX_GPIO_LINE_H(1)
#define EP93XX_GPIO_LINE_DD2		EP93XX_GPIO_LINE_H(2)
#define EP93XX_GPIO_LINE_DD3		EP93XX_GPIO_LINE_H(3)
#define EP93XX_GPIO_LINE_DD4		EP93XX_GPIO_LINE_H(4)
#define EP93XX_GPIO_LINE_DD5		EP93XX_GPIO_LINE_H(5)
#define EP93XX_GPIO_LINE_DD6		EP93XX_GPIO_LINE_H(6)
#define EP93XX_GPIO_LINE_DD7		EP93XX_GPIO_LINE_H(7)

/* maximum value for gpio line identifiers */
#define EP93XX_GPIO_LINE_MAX		EP93XX_GPIO_LINE_H(7)

/* maximum value for irq capable line identifiers */
#define EP93XX_GPIO_LINE_MAX_IRQ	EP93XX_GPIO_LINE_F(7)

#endif /* __GPIO_EP93XX_H */
