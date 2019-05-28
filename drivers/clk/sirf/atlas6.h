#define SIRFSOC_CLKC_CLK_EN0    0x0000
#define SIRFSOC_CLKC_CLK_EN1    0x0004
#define SIRFSOC_CLKC_REF_CFG    0x0020
#define SIRFSOC_CLKC_CPU_CFG    0x0024
#define SIRFSOC_CLKC_MEM_CFG    0x0028
#define SIRFSOC_CLKC_MEMDIV_CFG 0x002C
#define SIRFSOC_CLKC_SYS_CFG    0x0030
#define SIRFSOC_CLKC_IO_CFG     0x0034
#define SIRFSOC_CLKC_DSP_CFG    0x0038
#define SIRFSOC_CLKC_GFX_CFG    0x003c
#define SIRFSOC_CLKC_MM_CFG     0x0040
#define SIRFSOC_CLKC_GFX2D_CFG  0x0040
#define SIRFSOC_CLKC_LCD_CFG    0x0044
#define SIRFSOC_CLKC_MMC01_CFG  0x0048
#define SIRFSOC_CLKC_MMC23_CFG  0x004C
#define SIRFSOC_CLKC_MMC45_CFG  0x0050
#define SIRFSOC_CLKC_NAND_CFG	0x0054
#define SIRFSOC_CLKC_NANDDIV_CFG	0x0058
#define SIRFSOC_CLKC_PLL1_CFG0  0x0080
#define SIRFSOC_CLKC_PLL2_CFG0  0x0084
#define SIRFSOC_CLKC_PLL3_CFG0  0x0088
#define SIRFSOC_CLKC_PLL1_CFG1  0x008c
#define SIRFSOC_CLKC_PLL2_CFG1  0x0090
#define SIRFSOC_CLKC_PLL3_CFG1  0x0094
#define SIRFSOC_CLKC_PLL1_CFG2  0x0098
#define SIRFSOC_CLKC_PLL2_CFG2  0x009c
#define SIRFSOC_CLKC_PLL3_CFG2  0x00A0
#define SIRFSOC_USBPHY_PLL_CTRL 0x0008
#define SIRFSOC_USBPHY_PLL_POWERDOWN  BIT(1)
#define SIRFSOC_USBPHY_PLL_BYPASS     BIT(2)
#define SIRFSOC_USBPHY_PLL_LOCK       BIT(3)
