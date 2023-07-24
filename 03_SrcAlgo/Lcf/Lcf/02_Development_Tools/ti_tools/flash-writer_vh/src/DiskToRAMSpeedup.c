/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       VH28 Core: MPU0 Cortex A15

  COMPONENT:                 qspi-flash-writer-reload2-speedup

  MODULNAME:                 DiskToRamSpeedup.c

  DESCRIPTION:               see DiskToRamSpeedup.h

  AUTHOR:                    Harald.Heim-Ext

  CREATION DATE:             2013/10/11

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: DiskToRAMSpeedup.c  $
  CHANGES:                   Revision 1.1 2021/12/13 19:20:45CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/ti_tools/flash-writer_vh/src/project.pj
  CHANGES:                   Revision 1.2 2017/01/10 09:34:23CET Bruch, Carsten (uidv8773) (uidv8773) 
  CHANGES:                   Use current starterware
  CHANGES:                   Revision 1.1 2016/11/30 09:32:05CET Baur, Magnus (uidr0839) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/04_Tools/DPU_Environment/04_Engineering/02_Development_Tools/ti_tools/flash-writer_vh/src/project.pj
  CHANGES:                   Revision 1.3 2014/12/14 14:25:33CET Unithrattil, Shinjith (uid23058) 
  CHANGES:                   Fixed build issues due to QSPI EDMA functionalities
  CHANGES:                   - Added comments -  uid23058 [Dec 14, 2014 2:25:33 PM CET]
  CHANGES:                   Change Package : 277362:2 http://mks-psad:7002/im/viewissue?selection=277362
  CHANGES:                   Revision 1.2 2014/11/03 13:29:34CET Unithrattil, Shinjith (uid23058) 
  CHANGES:                   QSPI writer is now adapted to new starter ware package. Flash drivers are now located at S00_ALL\04_Engineering\01_Source_Code\SW\source\drivers folder
  CHANGES:                   --- Added comments ---  uid23058 [Nov 3, 2014 1:29:34 PM CET]
  CHANGES:                   Change Package : 277362:1 http://mks-psad:7002/im/viewissue?selection=277362
  CHANGES:                   Revision 1.1 2013/10/25 14:18:22CEST Roberts, Michael (uidw0287) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/SW/SW_MFC4xx/SW_SMFC400_PR/04_Engineering/02_Development_Tools/ti_Tools/qspi-flash-writer-reloaded/src/project.pj
  CHANGES:                   Revision 1.xx 2013/xx/xx  Name 
  CHANGES:                   xxx

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stdint.h"
#include "qspiflash_driver.h"
#include "soc.h"

#include "DiskToRamSpeedup.h"

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/* global instance */
#pragma DATA_SECTION(SPIWRITER_uSdfBufferWr, "sdfbuff")  /* todo locate to APP_ADDRESS 0x82000000 */
             uint8_t SPIWRITER_uSdfBufferWr[SDF_BUFFER_SIZE];

/* module instance */
volatile int32_t SPIWRITER_uFileSize = 0;
volatile int32_t SPIWRITER_uSdfOffset = 0;
uint8_t SPIWRITER_bFinished = 0;


/*****************************************************************************
  FUNCTION PROTOTYPES (module instance)
*****************************************************************************/
void SPIWRITER_v_PreFlashHook();
void SPIWRITER_v_FinishedFunc();
int determineImageSize();

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* *****************************************************************************
  Functionname:     SPIWRITER_v_PreFlashHook                                      */ /*!
  
  @brief            loop waiting until debugger (load_memory command) finished
  
  @param[in]        -
  @param[out]       -
  
  @return           -
  
  @pre              -
  @post             -
  
  @author           Merged by Harald.Heim-Ext 2013-10-11 Vmid origin Thomas Weismueller
***************************************************************************** */
void SPIWRITER_v_PreFlashHook()
{
  static volatile int pleaseDoNotOptimizeMeAway = 0;
  pleaseDoNotOptimizeMeAway++;
}

void SPIWRITER_v_FinishedFunc()
{
  SPIWRITER_bFinished = 1;
}

/* *****************************************************************************
  Functionname:     determineImageSize                                      */ /*!
  
  @brief            fast way determining: check after big step first 100 Bytes equal to pattern 0xB6
  
  @param[in]        -
  @param[out]       -
  
  @return           imageSize
  
  @pre              -
  @post             -
  
  @author           Merged by Harald.Heim-Ext 2013-10-11 Vmid origin Thomas Weismueller
***************************************************************************** */
int determineImageSize()
{
  const int blockSize = 10*1024;
  int imageSize = 8; // default wipe_sbl value

  // Try to find out file size by walking through the memory looking for our default pattern
  int i,j;

  for (i=0, j=0; i<8; i++)
  {
    // if all 1st 8 bytes == 0 still wipe_sbl default data in memory
	if (SPIWRITER_uSdfBufferWr[i])
    {
       imageSize = 0; // no wipe_sbl, other data from load memory
    }
  }

  if (imageSize == 8)
  {
    return imageSize; // do wipe_sbl: flash 1st 8 bytes = 0
  }

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

/* *****************************************************************************
  Functionname:     loadDiskToRAM                                           */ /*!

  @brief            does complete dataload from disc to

  @param[in]        -
  @param[out]       -

  @return           filesize

  @pre              -
  @post             -

  @author           Merged by Harald.Heim-Ext 2013-10-11 Vmid origin Thomas Weismueller
***************************************************************************** */
int32_t loadDiskToRAM(void)
{
  // prepare for determineImageSize():
  // Write known pattern into SDF buffer, so file length can be determined bay determineImageSize() later.
  // To safe time, we only write 100 bytes of each 10k block:
  {
    int i,j;
    for (i=0; i<8; i++)
    {
        SPIWRITER_uSdfBufferWr[i] = 0x00; /* set wipe_sbl default data. wipe_sbl means: flash 1st 8 bytes = 0 */
    }

    for (i= (10*1024); i<sizeof(SPIWRITER_uSdfBufferWr); i += (10*1024))
    {
      for (j=0; j<100; j++)
      {
        SPIWRITER_uSdfBufferWr[i+j] = 0xB6;
      }
    }
  }

  // Print user action hints
  printf("\n\n Please load file to memory variable 'SPIWRITER_uSdfBufferWr'! Use debugger [Menu: Tool-->Load Memory]\n");
  fflush(stdout);

  // Hook function for scripted flashing (allows setting breakpoint here)
  SPIWRITER_v_PreFlashHook();

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
    printf("Found image with size %u Bytes (10k rounded) in memory.\n\n", imgSizeDetermined);
    fflush(stdout);
    SPIWRITER_uFileSize = imgSizeDetermined;

  }

  return(SPIWRITER_uFileSize);
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Ulm                                              */
/* ************************************************************************* */

