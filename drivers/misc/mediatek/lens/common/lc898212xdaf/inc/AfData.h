/* ******************************************************************************** */
/*  */
/* LC89821x Initialize Data Table */
/*  */
/* Program Name        : AfData.h */
/* Modify for TVC-820                2015.1.10 ziyu jiang */
/* Description             : AF Initialize Table Defination */
/* ******************************************************************************** */

#define	WAIT				0xFF	/* Wait command */

/*----------------------------------------------------------
		Initial data table
-----------------------------------------------------------*/
struct INIDATA {
	unsigned short addr;
	unsigned short data;
} IniData;

const struct INIDATA Init_Table[] = {
	/* Addr,   Data */

	/* TDK_CL-ACT_ 212_SPtype_Ini_130114 */
	{0x0080, 0x34},		/* CLKSEL 1/1, CLKON */
	{0x0081, 0x20},		/* AD 4Time */
	{0x0084, 0xE0},		/* STBY   AD ON,DA ON,OP ON */
	{0x0087, 0x05},		/* PIDSW OFF,AF ON,MS2 ON */
	{0x00A4, 0x24},		/* Internal OSC Setup (No01=24.18MHz) */

	{0x003A, 0x0000},	/* OFFSET Clear */
	{0x0004, 0x0000},	/* RZ Clear(Target Value) */
	{0x0002, 0x0000},	/* PIDZO Clear */
	{0x0018, 0x0000},	/* MS1Z22 Clear(STMV Target Value) */
/* { WAIT, 5 },                // Wait 5 ms */

	/* Filter Setting: ST140911-1.h For TVC-820 */
	{0x0088, 0x68},
	{0x0028, 0x8080},
	{0x004C, 0x4000},
	{0x0083, 0x2C},
	{0x0085, 0xC0},
	{WAIT, 1},		/* Wait 1 ms */

        {0x0085, 0x00},
	{0x0084, 0xE3},
	{0x0097, 0x00},
	{0x0098, 0x42},
	{0x0099, 0x00},
	{0x009A, 0x00},

	{0x0086, 0x40},
	{0x0040, 0x4030},
	{0x0042, 0x7150},
	{0x0044, 0x8F90},
	{0x0046, 0x61B0},
	{0x0048, 0x7FF0},
	{0x004A, 0x3930},
	{0x004C, 0x4030},
	//{0x004E, 0x7FF0}, // depend on hw setting
	{ 0x004E, 0x8010 },
	{0x0050, 0x04f0},
	{0x0052, 0x7610},
	{0x0054, 0x2030},
	{0x0056, 0x0000},
	{0x0058, 0x7FF0},
	{0x005A, 0x0680},
	{0x005C, 0x72f0},
	{0x005E, 0x7f70},
	{0x0060, 0x7ed0},
	{0x0062, 0x7ff0},
	{0x0064, 0x0000},
	{0x0066, 0x0000},
	{0x0068, 0x5130},
	{0x006A, 0x72f0},
	{0x006C, 0x8010},
	{0x006E, 0x0000},
	{0x0070, 0x0000},
	{0x0072, 0x18e0},
	{0x0074, 0x4e30},
	{0x0030, 0x0000},
	{0x0076, 0x0C50},
	{0x0078, 0x4000},
	{WAIT, 5},		/* Wait 5 ms */

	{0x0086, 0x60},


	{0x0087, 0x85}

};
