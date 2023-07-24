/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       VH28 Core: MPU0 Cortex A15

  COMPONENT:                 qspi-flash-writer-reload2-speedup

  MODULNAME:                 DiskToRamSpeedup.h

  DESCRIPTION:               In the former Data load from harddisk to DDR-RAM needed much time.
                             It have been done by fread() which operates slowly.
                             This module uses much faster "debugger load_memory command"
                             
                             Yo have to do some modifications within main.c:
                             replace the old fopen(), fseek(), ftell(), fread() code by loadDiskToRAM()
                             example and further changes see main.c here. Changes are marked their with "CONTI_CHANGE: DiskToRAMSpeedup"

                             - complete program is to run with emulator:
                               set breakpoint within SPIWRITER_v_PreFlashHook()
                             
                             detailed sequence how loadDiskToRAM() operates:
                             - first prepares for determineImageSize(): mark Buffer with pattern 0xB6 (100 bytes each 10k block)
                             - printf() instuct user for load_memory command
                             - stop at breakpoint within SPIWRITER_v_PreFlashHook(): wait until "debugger load_memory command" finished
                             - user action: load Data from Disk with emulator load_memory command
                             - user action: continue from breakpoint
                             - determineImageSize() walks throug buffer until it finds 0xB6, than returns imageSize
                             - after some printf() loadDiskToRAM() returns imgSizeDetermined
                             ---> normal code can continue like before after fread() finished

  AUTHOR:                    Harald.Heim-Ext

  CREATION DATE:             2013/10/11

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: DiskToRAMSpeedup.h  $
  CHANGES:                   Revision 1.1 2021/12/13 19:20:45CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/ti_tools/flash-writer_vh/src/project.pj
  CHANGES:                   Revision 1.2 2017/01/17 09:17:00CET Bruch, Carsten (uidv8773) (uidv8773) 
  CHANGES:                   Increase buffer size for storage of binary to be flashed
  CHANGES:                   Revision 1.1 2016/11/29 17:10:15CET Baur, Magnus (uidr0839) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/04_Tools/DPU_Environment/04_Engineering/02_Development_Tools/ti_tools/flash-writer_vh/src/project.pj
  CHANGES:                   Revision 1.1 2013/10/25 14:18:25CEST Roberts, Michael (uidw0287) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/SW/SW_MFC4xx/SW_SMFC400_PR/04_Engineering/02_Development_Tools/ti_Tools/qspi-flash-writer-reloaded/src/project.pj
  CHANGES:                   Revision 1.xx 2013/xx/xx  Name 
  CHANGES:                   xxx

**************************************************************************** */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
extern void SPIWRITER_v_FinishedFunc();
extern int32_t loadDiskToRAM(void);

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  GLOBALE KONSTANTEN
*****************************************************************************/
#define SDF_BUFFER_SIZE (32*1024*1024)

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
extern uint8_t SPIWRITER_uSdfBufferWr[SDF_BUFFER_SIZE];


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Ulm                                              */
/* ************************************************************************* */

