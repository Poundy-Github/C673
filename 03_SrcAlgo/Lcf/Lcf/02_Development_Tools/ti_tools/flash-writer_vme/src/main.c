/*
 * Copyright (C) 2008 Texas Instruments, Inc <www.ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "omap3_spi.h"

struct spi_slave *slave;
struct spi_flash *flash;


#if defined(CONFIG_TI816X_EVM) || defined(CONFIG_TI814X_EVM)
#define MAX_DSPUBL_SIZE	(0)
#define MAX_ARMUBL_SIZE	(0)
#else
#define MAX_DSPUBL_SIZE	(8*1024)
#define MAX_ARMUBL_SIZE	(24*1024)
#endif

#define JTAG_ID_BASE	0x01c14018
#define CHIPREV_ID_BASE	0x01c14024
#define DA850_PART_NUM	0xb7d1
#define DA830_PART_NUM	0xb7df

/* Bulkerase (aka chip erase) is faster on some flash chips compared to using page erase for */
/* erasing big ares of the flash. However, the break-even point is quite high, so it's only a */
/* noticeable benefit when the erase size reaches the total flash chip size. */
//#define USE_BULKERASE 1
int SPIWRITER_u_BulkErase = 0;

/* Skip verification */
int SPIWRITER_u_SkipVerify = 0;

#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#define CM_PRCM_ALWON_MCSPI_ENABLE (0x48181590)

typedef struct _SPIBOOT_HEADER_
{
    Uint32		magicNum;
    Uint32		entryPoint;
    Uint32		appSize;
    Uint32		ldAddress;	/* Starting RAM address where image is to copied - XIP Mode */
} SPIBOOT_HeaderObj;

#if !defined(CONFIG_TI816X_EVM) && !defined(CONFIG_TI814X_EVM)
/*
 * Get Device Part No. from JTAG ID register
 */
static Uint16 davinci_get_part_no(void)
{
        Uint32 dev_id, part_no;

        dev_id = *(unsigned int*) JTAG_ID_BASE;

        part_no = ((dev_id >> 12) & 0xffff);

        return part_no;
}
#endif

/* PAD register offsets for SPI lines */
static Uint32 PAD_SPI_LineOffset[] = {
    0x940  ,  /* PINCTL81 - spi0_cs0 */
    0x944  ,  /* PINCTL82 - spi0_sclk */
    0x948  ,  /* PINCTL83 - spi0_d1 */
    0x94c  ,  /* PINCTL84 - spi0_d0 */
    0xFFFFFFFF
};

/* PAD register settings for SPI lines */
static Uint32 PAD_SPI_LineData[] = {
    0x60001,  /* PINCTL81 - spi0_cs0 */
    0x40001,  /* PINCTL82 - spi0_sclk */
    0x40001,  /* PINCTL83 - spi0_d1 */
    0x60001,  /* PINCTL84 - spi0_d0 */
    0xFFFFFFFF
};

void PAD_ConfigMux(Uint32 *addr, Uint32 *val)
{
    Uint8 i;

    for (i = 0; i < 50; i++) {
        if (addr[i]== 0xFFFFFFFF)
            break;
        *(volatile Uint32 *)(CFG_MOD_BASE + addr[i]) = val[i];
    }
}

#define SDF_BUFFER_SIZE (8*1024*1024)
volatile Int32 SPIWRITER_uFileSize = 0;
volatile Int32 SPIWRITER_uSdfOffset = 0;

#pragma DATA_SECTION(SPIWRITER_uSdfBufferWr, "sdfbuff")
Uint8 SPIWRITER_uSdfBufferWr[SDF_BUFFER_SIZE];

#pragma DATA_SECTION(SPIWRITER_uSdfBufferRd, "sdfbuff")
Uint8 SPIWRITER_uSdfBufferRd[SDF_BUFFER_SIZE];
Uint8 SPIWRITER_bFinished = 0;

void SPIWRITER_v_PreFlashHook()
{
  static volatile int pleaseDoNotOptimizeMeAway = 0;
  pleaseDoNotOptimizeMeAway++;
}

void SPIWRITER_v_FinishedFunc()
{
  SPIWRITER_bFinished = 1;
}

int determineImageSize()
{
  const int blockSize = 8*1024;
  int imageSize = 0;

  // Try to find out file size by walking through the memory looking for our default pattern
  int i,j;

  for (i=0; i<sizeof(SPIWRITER_uSdfBufferWr); i += blockSize)
  {
    // Look for pattern in current block
    for (j=0; j<100; j++)
    {
      if (SPIWRITER_uSdfBufferWr[i+j] != 0xB6)
      {
        // Current block overwritten by image data -> update image size
        imageSize = (i+blockSize);
        break;
      }
    }
  }

  return imageSize;
}


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  main( )                                               		            *
 *      write to SPI flash and then verify the contents 					*
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int32 main( )
{
    Int16 i;
    Uint16 page_size;
   	Int32	fileSize = 0;
    Int32   no_of_pages;
    Int32   no_of_sectors;
    Int32	offset = -1;
    Uint8 	idcode[3];
    Uint32	ret;
    unsigned long sector_size;

    *(unsigned int*)(CM_PRCM_ALWON_MCSPI_ENABLE) = 0x2;
    PAD_ConfigMux(PAD_SPI_LineOffset, PAD_SPI_LineData);

    /* Initialize the SPI interface */
    slave = (struct spi_slave *)spi_setup_slave(0, 0, (24*1000*1000), 0);
    spi_claim_bus(slave);

    /* Read the ID codes */
    ret = spi_flash_cmd(slave, CMD_READ_ID, idcode, sizeof(idcode));
    if (ret) {
        printf ( "SF: Error in reading the idcode\n");
        exit (1);
    }

    printf("SF: Got idcode %02x %02x %02x\n", idcode[0],
            idcode[1], idcode[2]);

#if 0
    printf("Checking if STMicro flash writer can be used..\n");
    flash = (struct spi_flash *) spi_flash_probe_stmicro
            					(slave, idcode);
#else
    printf("Checking if Winbond flash writer can be used..\n");
    flash = (struct spi_flash *)spi_flash_probe_winbond (slave, idcode);
    if (!flash) {
        printf("Checking if STMicro flash writer can be used..\n");
        flash = (struct spi_flash *) spi_flash_probe_stmicro
            					(slave, idcode);
    }
#endif
    if (flash == NULL) {
        printf ("No known Serial Flash found\n");
        exit (2);
    }

    if (strstr(flash->name, "M25P")) {
        struct stmicro_spi_flash *sf = to_stmicro_spi_flash(flash);
        page_size = sf->params->page_size;
        sector_size = sf->params->page_size *
            		sf->params->pages_per_sector;
    } else if (strstr(flash->name, "W25")) {
        struct winbond_spi_flash *sf = to_winbond_spi_flash(flash);
        page_size = sf->params->page_size;
        sector_size = sf->params->page_size *
            		sf->params->pages_per_sector;
    } else {
        printf("Unsupported flash type: %s\n", flash->name);
        exit (2);
    }

    /* Print info about flash size */
    printf("Flash page size: %d bytes\n", page_size);
    printf("Flash sector size: %d bytes\n", sector_size);

    printf( "Starting SPIWriter.\r\n");

    // Write known pattern into SDF buffer, so file length can be determined automatically later.
    // To safe time, we only write 100 bytes of each 8k block:
    {
      int i,j;
      for (i=0; i<sizeof(SPIWRITER_uSdfBufferWr); i += (8*1024))
      {
        for (j=0; j<100; j++)
        {
          SPIWRITER_uSdfBufferWr[i+j] = 0xB6;
        }
      }
    }

    // Print user action hints
    printf("Please load data now into 'SPIWRITER_uSdfBufferWr' and update variable 'SPIWRITER_uFileSize' (optional)!\n");
    fflush(stdout);

    // Hook function for scripted flashing (allows setting breakpoint here)
    SPIWRITER_v_PreFlashHook();
    if (SPIWRITER_u_BulkErase == 1)
    {
      /* See comments at #define above */
      printf("Erasing entire flash ... \n");
      fflush(stdout);
      flash->erase (flash, 0, flash->size);
    }

    // Now loop and check if the user entered a specific file size to flash, or we have a valid file size
    // determined automatically by checking for our known pattern in determineImageSize().
    int imgSizeDetermined = 0;
    while ((SPIWRITER_uFileSize == 0) && (imgSizeDetermined == 0))
    {
      // Waiting for user action
      imgSizeDetermined = determineImageSize();
    }

    /* Check if image-size was auto-detected and display size */
    if (imgSizeDetermined != 0)
    {
      printf("Found image with size %u Bytes (8k rounded) in memory.\n", imgSizeDetermined);
      fflush(stdout);
      SPIWRITER_uFileSize = imgSizeDetermined;
    }

    /* Calculate numbers for flashing */
    offset = SPIWRITER_uSdfOffset;
    fileSize = SPIWRITER_uFileSize;
    no_of_pages = fileSize/page_size + ((fileSize % page_size) ? 1 : 0);
    no_of_sectors = (fileSize/sector_size + ((fileSize % sector_size) ? 1 : 0));
    (void)no_of_pages; // suppress compiler warning

    /* Erase the Serial Flash */
#if (USE_BULKERASE == 1)
    /* See comments at #define above */
    printf("Erasing entire flash ... \n");
    fflush(stdout);
    flash->erase (flash, 0, flash->size);
#else
    if (SPIWRITER_u_BulkErase != 1)
    {
      printf("Erasing flash at byte offset: %d, byte length: %d\n", (offset/sector_size)*sector_size, no_of_sectors*sector_size);
      fflush(stdout);
      flash->erase (flash, (offset/sector_size)*sector_size, no_of_sectors*sector_size);
    }
#endif

    /* Write whole flash at once */
    printf("Writing flash ...\n");
    fflush(stdout);
    i = (offset/page_size);
    flash->write (flash, i * page_size, fileSize, SPIWRITER_uSdfBufferWr);

    /* Verify flash contents */
    if (SPIWRITER_u_SkipVerify != 1)
    {
      printf("Verifying... ");
      fflush(stdout);

      i = (offset/page_size);
      flash->read (flash, i * page_size, fileSize, SPIWRITER_uSdfBufferRd);

      Uint32 *pDataWd = (Uint32*)SPIWRITER_uSdfBufferWr;
      Uint32 *pDataRd = (Uint32*)SPIWRITER_uSdfBufferRd;
      Uint32 uIndex = 0;
      Uint8 uVerifyFailed = 0;
      for (uIndex=0; uIndex<fileSize; uIndex+=4)
      {
        if (*pDataWd++ != *pDataRd++)
        {
          printf("ERROR at byte %ul!\n", uIndex);
          uVerifyFailed = 1;
          break;
        }
      }

      if (!uVerifyFailed)
      {
        printf("Success. \n");
        exit (0);
      }
      else
      {
        printf("Flashing failed!\n");
        SPIWRITER_v_FinishedFunc();
        exit(1);
      }
    }
    else
    {
      exit (0);
    }


    return 0;
}
