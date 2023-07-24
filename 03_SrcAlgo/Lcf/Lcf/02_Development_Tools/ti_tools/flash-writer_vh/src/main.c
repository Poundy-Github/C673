/* ======================================================================
 *   Copyright (C) 2013 Texas Instruments Incorporated
 *
 *   All rights reserved. Property of Texas Instruments Incorporated.
 *   Restricted rights to use, duplicate or disclose this code are
 *   granted through contract.
 *
 *   The program may not be used without the written permission
 *   of Texas Instruments Incorporated or against the terms and conditions
 *   stipulated in the agreement under which this program has been
 *   supplied.
 * ==================================================================== */

/*
 * main.c
 */
#include "stdint.h"
#include "stdio.h"
#include "qspi.h"
#include "qspiflash_driver.h"
#include "edma.h"
#include "soc.h"

#define QSPI_SPI_CMD_REG_CMD_INVALID 0  /* invalid command for spi command register to reset spi state machine */

                    /******************************************************************************/
#define DTRSPEEDUP  /* CONTI_CHANGE: DiskToRAMSpeedup ---- set define to switch over to new code -*/
                    /*                                -------- define on comment  for   old code--*/
#ifdef  DTRSPEEDUP
#include "DiskToRamSpeedup.h"
#endif              /******************************************************************************/


#ifdef BUILD_M4
uint32_t SOC_EDMA_TPCC_BASE = 0xA0000000;
#endif

void HAL_CTRL_UnlockMMR(void);
void HAL_CTRL_ConfigurePadsQspi(void);
uint32_t qspiwriter(void);
uint32_t edma_ch_num   = 1;
uint32_t edma_tcc_num  = 1;
uint32_t edma_evtq_num = 0;
// #define QSPIFLASH_BLOCKSIZE    (64*1024)
uint32_t EDMAVersionGet(void)
{
    return EDMA_REVID_AM335X;
}

#ifndef  DTRSPEEDUP
/* CONTI_CHANGE: Make the load address of the application a #define as it is used in more than one place */
#define APP_ADDRESS 0x82000000
#else
#define APP_ADDRESS &SPIWRITER_uSdfBufferWr[0] /* CONTI_CHANGE: DiskToRAMSpeedup */
#endif

/* CONTI_CHANGE: Buffer for reloading flashed data for verification */
static unsigned char buffer[QSPIFLASH_BLOCKSIZE];

/* CONTI_CHANGE: Endianness reversing function taken from the SBL for verification */
/* Convenience function that will iterate through a block of data and will reverse the endianness */
/* of all words contained therein.  The block passed in must be a multiple of 4 bytes in size */
/* Passed: p_Buffer Ptr to the buffer to have its endianness changed */
/*         s_Size   Size of the buffer in bytes.  Must be a multiple of 4 */

void OSD_v_ReverseEndianness(void *p_Buffer, int s_Size)
{
  int s_Index, s_NumEntries;
  unsigned char *p_Ptr, p_Temp;

  /* Determine the number of words to be converted and the start address */

  s_NumEntries = (s_Size / sizeof(int));
  p_Ptr = (unsigned char *) p_Buffer;

  /* Iterate through all of the words in the buffer and reverse their endianness */

  for (s_Index = 0; s_Index < s_NumEntries; ++s_Index)
  {
    p_Temp = p_Ptr[0];
    p_Ptr[0] = p_Ptr[3];
    p_Ptr[3] = p_Temp;

    p_Temp = p_Ptr[1];
    p_Ptr[1] = p_Ptr[2];
    p_Ptr[2] = p_Temp;

    p_Ptr += sizeof(int);
  }
}


int32_t main(void) {
    qspi_DeviceType_e DeviceType = DEVICE_TYPE_MICRON_QSPI4;
    volatile uint32_t dstAddr, srcOffsetAddr;
    volatile uint32_t srcAddr, dstOffsetAddr;
    volatile uint32_t length = 10;
	uint32_t device_Id;

	/* CONTI_CHANGE: EDMA is not used by the flasher so don't initialise it */
    /* Global variables not initialized RVCT startup issue for A15 */
    /*EDMA3Init(SOC_EDMA_TPCC_BASE, 0);
    EDMA3RequestChannel(SOC_EDMA_TPCC_BASE, EDMA3_CHANNEL_TYPE_DMA, edma_ch_num,
                        edma_tcc_num,
                        edma_evtq_num);*/

    printf("\nQSPI Flash writer application");

    HAL_CTRL_UnlockMMR();

	/* Configure PADs. */
	cntrl_core_qspi_pad_config();    

    QSPI_Initialize(DeviceType);

    /* write invalid command to register to reset the SPI state machine */
    /* in some cases this is necessary to get into a known state and prevents */
    /* from problems with flashing SDF */
    /* please refer to issue #222642 */
    QSPIsetCommandReg(SOC_QSPI_ADDRSP0_BASE, QSPI_SPI_CMD_REG_CMD_INVALID );


    device_Id = QSPI_GetDeviceId();

    printf("\nMID - ");
    printf("%x",(device_Id & 0xFF));
    printf("\nDID - ");
    printf("%x",(device_Id & 0xFF0000) >> 16);

    qspiwriter();
}

uint32_t qspiwriter(void)
{
    uint32_t offset;
    uint32_t eraseWhole;
    uint8_t *tmp, *srcAddr;
    uint32_t blkno;
	/* CONTI_CHANGE. fileSize must be signed or it cannot go to -ve */
    int32_t eraseSize, fileSize;

    /* CONTI_CHANGE: Extra variables for verification */
    uint32_t compareOffset, savedOffset;
    int32_t readSize, savedFileSize;

    /**********************************************************************************************************/
#ifndef DTRSPEEDUP /* CONTI_CHANGE: DiskToRAMSpeedup -------- start disable code to be replaced --------------*/
    /**********************************************************************************************************/

    char     fileName[256];
    FILE    *fPtr;

    // Read the file from host
    printf("\nEnter the File Name");    
	scanf("%s",fileName);
    fflush(stdin);

    /********************************************************************************************************/
#else /* CONTI_CHANGE: DiskToRAMSpeedup -------- end disabled code, start replacment code ------------------*/
    /********************************************************************************************************/

    srcAddr = tmp = &SPIWRITER_uSdfBufferWr[0];

    fileSize = savedFileSize = loadDiskToRAM(); // see "DiskToRamSpeedup.c"

    savedOffset = offset = 0;  /*-- standard with DiskToRAMSpeedup, don't ask for!  */

    /********************************************************************************************************/
#endif /* CONTI_CHANGE: DiskToRAMSpeedup -------- end replacment code --------------------------------------*/
    /********************************************************************************************************/


    /**********************************************************************************************************/
#ifndef DTRSPEEDUP /* CONTI_CHANGE: DiskToRAMSpeedup -------- start disable code -----------------------------*/
                   /* offset = 0 as standard with DiskToRAMSpeedup, don't ask for!
                    * Reason: always flash complete image (App+Bootloader) by java script
                    */
    /**********************************************************************************************************/

    // Read the offset from user
    printf("Enter the Offset in bytes (decimal)");
    scanf("%u",&offset);
	/* CONTI_CHANGE: Save offset for later use */
    savedOffset = offset;
    fflush(stdin);

    /********************************************************************************************************/
#endif /* CONTI_CHANGE: DiskToRAMSpeedup -------- end disabled code ----------------------------------------*/
    /********************************************************************************************************/

    /* CONTI_CHANGE: We don't support erasing the whole flash and skipping the erase step doesn't make sense, so */
    /* we always use the "Erase Only Required Region" option */
    eraseWhole = 0;
    /*printf("Erase Options:\n---------------\n");
    printf("          0 -> Erase Only Required Region\n");
    printf("          1 -> Erase Whole Flash\n");
    printf("          2 -> Skip Erase \n");
    printf("Enter Erase Option:\n");
    scanf("%u",&eraseWhole);*/

    /**********************************************************************************************************/
#ifndef DTRSPEEDUP /* CONTI_CHANGE: DiskToRAMSpeedup -------- start disable code -----------------------------*/
    /**********************************************************************************************************/

    fPtr = fopen(fileName, "rb");
    if (fPtr == NULL)
    {
        printf("\tERROR: File ");
        printf(fileName);
        printf(" open failed.\r\n");
        return 0;
    }
    // Read file size
    fseek(fPtr, 0, SEEK_END);
	/* CONTI_CHANGE: Save file size for later use */
    fileSize = savedFileSize = ftell(fPtr);
    if (fileSize == 0)
    {
        printf("\tERROR: File read failed.. Closing program.\r\n");
        fclose(fPtr);
        return 0;
    }

    fseek(fPtr, 0, SEEK_SET);
    printf("Reading");
    printf(" %u ",fileSize);
    printf("bytes from file...");
    fflush(stdout);
    /* CONTI_CHANGE: Use a #define as it is used in more than one place */
    srcAddr = tmp = (uint8_t *) APP_ADDRESS;

    if (fileSize != fread(tmp, 1, fileSize, fPtr))  /* read filecontent to memory startadress tmp, nrofbytes=filesize */
    {
        printf("\tWARNING: File Size mismatch.\r\n");
    }
    printf("Done.\n");

    fclose(fPtr);

    /********************************************************************************************************/
#endif /* CONTI_CHANGE: DiskToRAMSpeedup -------- end disabled code ----------------------------------------*/
    /********************************************************************************************************/

    blkno = offset / QSPIFLASH_BLOCKSIZE;

    QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                      QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT);
    QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT,QSPI_MMR);

    /* Erase the flash as required */

    /* CONTI_CHANGE: We don't support erasing the whole flash and skipping the erase step doesn't make sense, so */
    /* we always use the "Erase Only Required Region" option */
#if 0
    if (eraseWhole == 1)
    {
		printf("\n QSPI whole chip erase in progress\n");
		QSPI_WriteEnable();
       QSPI_FlashFullErase();
    }
	else if(eraseWhole == 0)
#endif
	{	
		printf("\n QSPI Erase started\n");
		blkno = offset / QSPIFLASH_BLOCKSIZE;
		eraseSize = fileSize;
		/* CONTI_CHANGE: Fix for a bug that results in the last block not being erased */
		while (eraseSize > 0)
		{
			if (eraseWhole == 0)
			{
				QSPI_WriteEnable();
				QSPI_FlashBlockErase(blkno++);
			}
			eraseSize -= QSPIFLASH_BLOCKSIZE;	
		}
		printf("\n QSPI Erase completed\n");
	}

    printf("\n QSPI file write started \n");
	while(fileSize >= 256) {
	
		/* Change to Memory mapped mode with given chip select */
		if(0){
                QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                      QSPI_SPI_SWITCH_REG_MMPT_S_SEL_MM_PORT);
                QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT,
                                    QSPI_CS0);
                
		        QSPI_WriteEnable();
		        QSPI_WriteSectors(offset, (uint32_t)srcAddr, 64);
		} else {
            QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                              QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT);
            QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT,
                                QSPI_MMR);
		    QSPI_WriteEnable();
		    QSPI_WriteCfgMode(offset, (uint32_t)srcAddr, 64);
		}
		fileSize -= 256;
		offset += 256;
		srcAddr += 256;
	}
	if(fileSize > 0) {
		/* Change to Memory mapped mode with given chip select */
		if(0){
            QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                              QSPI_SPI_SWITCH_REG_MMPT_S_SEL_MM_PORT);
            QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_MM_PORT,QSPI_CS0);
		    QSPI_WriteEnable();
		    QSPI_WriteSectors(offset, (uint32_t)srcAddr, fileSize);
		} else {
            QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                              QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT);
            QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT,QSPI_MMR);
		    QSPI_WriteEnable();
		    QSPI_WriteCfgMode(offset, (uint32_t)srcAddr, (fileSize/4)+1);
		}
	}

    /* Change to Memory mapped mode with given chip select */
    QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                      QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT);
    QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT,QSPI_MMR);

	printf("\n ************ QSPI flash completed sucessfully ************** \n");

	/* CONTI_CHANGE: Ensure that the data was written correctly, as the QSPI interface is not 100% reliable */
	printf("\n Verifying %d bytes...\n", savedFileSize);

	/* Get the start address in SDF and the size of the application that was just written */
	fileSize = savedFileSize;
	offset = savedOffset;
	compareOffset = 0;
	srcAddr = (uint8_t *) APP_ADDRESS;
        
    /* Change to Memory mapped mode with given chip select */
    QSPISetMAddrSpace(SOC_QSPI_ADDRSP0_BASE,
                      QSPI_SPI_SWITCH_REG_MMPT_S_SEL_MM_PORT);
    QSPI_ConfMAddrSpace(QSPI_SPI_SWITCH_REG_MMPT_S_SEL_MM_PORT, QSPI_CS0);
    
    /* Iterate through the application that was just written and read it in QSPIFLASH_BLOCKSIZE bytes at a */
	/* time, comparing it against the full image that resides in memory at srcAddr */

	while (fileSize > 0)
	{
		/* Read either an entire block or only what is remaining, if we are near the end of the file */

		readSize = (fileSize >= QSPIFLASH_BLOCKSIZE) ? QSPIFLASH_BLOCKSIZE : fileSize;
		QSPI_ReadSectors(buffer, offset, readSize);
		offset += readSize;

		/* Put the data back into big endian format to account for the loopiness of QSPI/SDF */

		OSD_v_ReverseEndianness(buffer, readSize);

		/* Ensure that the block just read matches what is in memory */

		if (memcmp(buffer, (srcAddr + compareOffset), readSize) != 0)
		{
            /*************************************************************************************/
#ifndef  DTRSPEEDUP  /* CONTI_CHANGE: DiskToRAMSpeedup ---- disable line ------------------------*/
			printf("\n *** ERROR: Verification failed!  Data read back is NOT what was written\n");
#endif      /*************************************************************************************/

			break;
		}

		/* And prepare for the next block read */

		compareOffset += QSPIFLASH_BLOCKSIZE;
		fileSize -= QSPIFLASH_BLOCKSIZE;	
	}

	/* If we read and checked all blocks, including the last one, the file was flashed successfuly */

    /**********************************************************************************************************/
#ifndef DTRSPEEDUP /* CONTI_CHANGE: DiskToRAMSpeedup -------- start disable code to be replaced --------------*/
    /**********************************************************************************************************/

	if (fileSize <= 0)
	{
		printf("\n ************ Verification successful ************** \n");
	}

	{volatile uint8_t spin=1; while(spin);}
	
    /********************************************************************************************************/
#else /* CONTI_CHANGE: DiskToRAMSpeedup -------- end disabled code, start replacment code ------------------*/
    /********************************************************************************************************/

    if (fileSize <= 0)
    {
      printf("\n ************ Verification successful ************** \n");
      exit (0);
    }
    else
    {
      printf("\n *** ERROR: Verification failed!  Data read back is NOT what was written\n");
      SPIWRITER_v_FinishedFunc();
      exit(1);
    }

    /********************************************************************************************************/
#endif /* CONTI_CHANGE: DiskToRAMSpeedup -------- end replacment code --------------------------------------*/
    /********************************************************************************************************/

     return 0;
}
