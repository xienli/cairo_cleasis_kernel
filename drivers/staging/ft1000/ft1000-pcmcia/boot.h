/*---------------------------------------------------------------------------
   FT1000 driver for Flarion Flash OFDM NIC Device

   Copyright (C) 2002 Flarion Technologies, All rights reserved.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2 of the License, or (at your option) any
   later version. This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details. You should have received a copy of the GNU General Public
   License along with this program; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place -
   Suite 330, Boston, MA 02111-1307, USA.
  ---------------------------------------------------------------------------

   File:         boot.h

   Description:    boatloader

   History:
   1/11/05    Whc                Ported to Linux.

---------------------------------------------------------------------------*/
#ifndef _BOOTH_
#define _BOOTH_

/* Official bootloader */
static unsigned char bootimage[] = {
	0x00, 0x00, 0x01, 0x5E, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x02, 0xD7,
	0x00, 0x00, 0x01, 0x5E, 0x46, 0xB3,
	0xE6, 0x02, 0x00, 0x98, 0xE6, 0x8C,
	0x00, 0x98, 0xFB, 0x92, 0xFF, 0xFF,
	0x98, 0xFB, 0x94, 0xFF, 0xFF, 0x98,
	0xFB, 0x06, 0x08, 0x00, 0x98, 0xFB,
	0x96, 0x84, 0x00, 0x98, 0xFB, 0x08,
	0x1C, 0x00, 0x98, 0xFB, 0x51, 0x25,
	0x10, 0x1C, 0x00, 0xE6, 0x51, 0x01,
	0x07, 0xFD, 0x4C, 0xFF, 0x20, 0xF5,
	0x51, 0x02, 0x20, 0x08, 0x00, 0x4C,
	0xFF, 0x20, 0x3C, 0x00, 0xC0, 0x64,
	0x98, 0xC0, 0x66, 0x98, 0xC0, 0x68,
	0x98, 0xC0, 0x6A, 0x98, 0xC0, 0x6C,
	0x98, 0x90, 0x08, 0x90, 0x09, 0x90,
	0x0A, 0x90, 0x0B, 0x90, 0x0C, 0x90,
	0x0D, 0x90, 0x0E, 0x90, 0x0F, 0x90,
	0x04, 0x90, 0x06, 0xFB, 0x51, 0x22,
	0x16, 0x08, 0x03, 0xFB, 0x51, 0x52,
	0x16, 0x08, 0x04, 0xFB, 0x51, 0x24,
	0x2B, 0x08, 0x06, 0xFB, 0x51, 0x54,
	0x2B, 0x08, 0x07, 0xFB, 0x51, 0x24,
	0x2B, 0x08, 0x09, 0xFB, 0x51, 0x54,
	0x2B, 0x08, 0x0A, 0xFB, 0x51, 0x12,
	0x16, 0x08, 0x0C, 0xFB, 0x51, 0x52,
	0x16, 0x08, 0x0D, 0x78, 0x00, 0x00,
	0x00, 0x16, 0x00, 0x00, 0xEC, 0x31,
	0xAE, 0x00, 0x00, 0x81, 0x4C, 0x0F,
	0xE6, 0x43, 0xFF, 0xEC, 0x31, 0x4E,
	0x00, 0x00, 0x91, 0xEC, 0x31, 0xAE,
	0x00, 0x00, 0x91, 0x4C, 0x0F, 0xE6,
	0x43, 0xFF, 0xEC, 0x31, 0x5E, 0x00,
	0x00, 0xA1, 0xEB, 0x31, 0x08, 0x00,
	0x00, 0xA6, 0xEB, 0x31, 0x08, 0x00,
	0x00, 0xAC, 0x3C, 0x00, 0xEB, 0x31,
	0x08, 0x00, 0x00, 0xA8, 0x76, 0xFE,
	0xFE, 0x08, 0xEB, 0x31, 0x08, 0x20,
	0x00, 0x00, 0x76, 0xFF, 0xFF, 0x18,
	0xED, 0x31, 0x08, 0x20, 0x00, 0x00,
	0x26, 0x10, 0x04, 0x10, 0xF5, 0x3C,
	0x01, 0x3C, 0x00, 0x08, 0x01, 0x12,
	0x3C, 0x11, 0x3C, 0x00, 0x08, 0x01,
	0x0B, 0x08, 0x00, 0x6D, 0xEC, 0x31,
	0xAE, 0x20, 0x00, 0x06, 0xED, 0x4D,
	0x08, 0x00, 0x00, 0x67, 0x80, 0x6F,
	0x00, 0x01, 0x0B, 0x6F, 0x00, 0x02,
	0x2E, 0x76, 0xEE, 0x01, 0x48, 0x06,
	0x01, 0x39, 0xED, 0x4D, 0x18, 0x00,
	0x02, 0xED, 0x4D, 0x08, 0x00, 0x04,
	0x14, 0x06, 0xA4, 0xED, 0x31, 0x22,
	0x00, 0x00, 0xAC, 0x76, 0xEE, 0x07,
	0x48, 0x6D, 0x22, 0x01, 0x1E, 0x08,
	0x01, 0x58, 0xEB, 0x31, 0x08, 0x00,
	0x00, 0xAC, 0x06, 0xFF, 0xBA, 0x3C,
	0x00, 0xEB, 0x31, 0x08, 0x20, 0x00,
	0x04, 0x3C, 0x30, 0xEB, 0x31, 0x08,
	0x20, 0x00, 0x02, 0x3C, 0x10, 0xEB,
	0x31, 0x08, 0x20, 0x00, 0x00, 0xED,
	0x31, 0x08, 0x20, 0x00, 0x00, 0x04,
	0x10, 0xF7, 0xED, 0x31, 0x08, 0x00,
	0x00, 0xA2, 0x91, 0x00, 0x9C, 0x3C,
	0x80, 0xEB, 0x31, 0x08, 0x20, 0x00,
	0x04, 0x3C, 0x20, 0xEB, 0x31, 0x08,
	0x20, 0x00, 0x02, 0x3C, 0x10, 0xEB,
	0x31, 0x08, 0x20, 0x00, 0x00, 0xED,
	0x31, 0x08, 0x20, 0x00, 0x00, 0x04,
	0x10, 0xF7, 0xED, 0x31, 0x08, 0x20,
	0x00, 0x04, 0x42, 0x10, 0x90, 0x08,
	0xEC, 0x31, 0xAE, 0x20, 0x00, 0x06,
	0xA4, 0x41, 0x08, 0x00, 0xB6, 0xED,
	0x41, 0x28, 0x7D, 0xFF, 0xFF, 0x22,
	0xB3, 0x40, 0x98, 0x2A, 0x32, 0xEB,
	0x41, 0x28, 0xB4, 0x43, 0xFC, 0x05,
	0xFF, 0xE6, 0xA0, 0x31, 0x20, 0x00,
	0x06, 0xEB, 0x31, 0x08, 0x20, 0x00,
	0x04, 0x3C, 0x20, 0xEB, 0x31, 0x08,
	0x20, 0x00, 0x02, 0x3C, 0x10, 0xEB,
	0x31, 0x08, 0x20, 0x00, 0x00, 0xED,
	0x31, 0x08, 0x20, 0x00, 0x00, 0x04,
	0x10, 0xF7, 0xED, 0x31, 0x08, 0x20,
	0x00, 0x04, 0x42, 0x10, 0x90, 0x08,
	0xEC, 0x31, 0xAE, 0x20, 0x00, 0x06,
	0xA4, 0x41, 0x08, 0x00, 0x68, 0xED,
	0x41, 0x28, 0x7D, 0xFF, 0xFF, 0x22,
	0xB3, 0x40, 0x98, 0x2A, 0x32, 0xEB,
	0x41, 0x28, 0xB4, 0x43, 0xFC, 0x05,
	0xFF, 0xE6, 0x48, 0x04, 0xEB, 0x31,
	0x08, 0x20, 0x00, 0x04, 0xEB, 0x31,
	0x18, 0x20, 0x00, 0x02, 0x3C, 0x11,
	0xEB, 0x31, 0x18, 0x20, 0x00, 0x00,
	0xED, 0x31, 0x08, 0x20, 0x00, 0x00,
	0x04, 0x10, 0xF7, 0xED, 0x31, 0x08,
	0x20, 0x00, 0x02, 0x66, 0x00, 0x6F,
	0x00, 0x01, 0x16, 0x76, 0xEE, 0x06,
	0x48, 0x4A, 0x1E, 0x48, 0x04, 0xED,
	0x31, 0x08, 0x20, 0x00, 0x04, 0xEB,
	0x31, 0x08, 0x00, 0x00, 0xA4, 0x48,
	0x04, 0xED, 0x31, 0x08, 0x20, 0x00,
	0x04, 0xEB, 0x31, 0x08, 0x00, 0x00,
	0xA2, 0x48, 0x04, 0x20, 0x20, 0x4A,
	0x7C, 0x46, 0x82, 0x50, 0x05, 0x50,
	0x15, 0xB5, 0x1E, 0x98, 0xED, 0x31,
	0x08, 0x00, 0x00, 0xA8, 0x10, 0x47,
	0x3B, 0x2C, 0x01, 0xDB, 0x40, 0x11,
	0x98, 0xC1, 0x1E, 0x98, 0x10, 0x07,
	0x30, 0xF9, 0x40, 0x07, 0x18, 0x98,
	0x2A, 0x10, 0xEB, 0x31, 0x08, 0x00,
	0x00, 0xA8, 0xA4, 0x1E, 0x98, 0xBB,
	0x1E, 0x98, 0x50, 0x14, 0x50, 0x04,
	0x46, 0x83, 0x48, 0x04, 0x02, 0x01,
	0x00, 0x50, 0x05, 0x50, 0x15, 0x10,
	0x87, 0x3F, 0x90, 0x2B, 0x18, 0x01,
	0x00, 0xC0, 0x31, 0x00, 0x00, 0xAE,
	0xDF, 0x41, 0x00, 0x08, 0x00, 0x1A,
	0x42, 0x11, 0x67, 0x01, 0xDF, 0x41,
	0x02, 0x08, 0x00, 0x10, 0x42, 0x11,
	0x62, 0x01, 0xB4, 0x43, 0x4A, 0x68,
	0x50, 0x14, 0x50, 0x04, 0x24, 0x10,
	0x48, 0x04, 0xF2, 0x31, 0x00, 0x01,
	0x00, 0x00, 0xAE, 0xF6, 0x31, 0x00,
	0x01, 0x00, 0x00, 0xAE, 0x62, 0xE4,
	0xE5, 0x61, 0x04, 0x48, 0x04, 0xE5,
	0x63, 0x05, 0x48, 0x04, 0x20, 0x20,
	0x00, 0x00, 0x00, 0x00
};

#endif
