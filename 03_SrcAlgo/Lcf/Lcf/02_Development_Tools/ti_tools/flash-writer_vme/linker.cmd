/*
 * TI Booting and Flashing Utilities
 *
 * Copyright 2007 by Spectrum Digital Incorporated.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 *  Linker command file
 *
 */
 
-stack          0x00008000      /* Stack Size */
-heap           0x00008000      /* Heap Size */

MEMORY
{
    DDR:         o = 0x80D00000  l = 0x00200000  /*  2MiB DDR */
    DDR_SDFBUFF: o = 0x80F00000  l = 0x01000000  /*  16MiB DDR */
    L3OCM0:      o = 0x40300000  l = 0x0003FFFF  /*  256 KBytes SRAM */
    L3OCM1:      o = 0x40400000  l = 0x0003FFFF  /*  256 KBytes SRAM */
}

SECTIONS
{
	sdfbuff     >   DDR_SDFBUFF, TYPE = NOINIT

    .bss        >   DDR
    .cinit      >   DDR
    .cio        >   DDR
    .const      >   DDR
    .stack      >   DDR
    .sysmem     >   DDR
    .text       >   DDR
    .DRAM       >   DDR
	.far		>	DDR
	.switch		>	DDR
	.data		>   DDR
}
