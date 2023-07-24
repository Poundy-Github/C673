/*****************************************************************************
 
  COMPANY:                    Continental Automotive
 
  PROJECT:                    MFC310
    
  CPU:                        Freescale MPC5675K                            
 
  Component:                  COMMON
 
  MODULNAME:                  MFC310_glob_cfg.h
 
  DESCRIPTION:                Global system configuration
 
  VERSION:                    $Revision: 1.1 $

                  
  ---*/ /*---
  CHANGES:                    $Log: MFC310_glob_cfg.h  $
  CHANGES:                    Revision 1.1 2021/12/13 17:24:44CET Wang, David (Wangd3) 
  CHANGES:                    Initial revision
  CHANGES:                    Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                    Revision 1.0 2017/03/03 10:35:42CET Sorge, Sven (uidg3181) 
  CHANGES:                    Initial revision
  CHANGES:                    Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                    Revision 1.1 2014/03/13 15:11:11CET Sorge, Sven (uidg3181) 
  CHANGES:                    Initial revision
  CHANGES:                    Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
  CHANGES:                    Revision 1.1 2011/07/12 18:32:41CEST Achatz-EXT, Florian (uidt9222) 
  CHANGES:                    Initial revision
  CHANGES:                    Member added to project /nfs/projekte1/PROJECTS/MFC300/05_Software/MCU/04_Engineering/01_Source_Code/Common/project.pj

 
*****************************************************************************/
#ifndef MFC310_GLOB_CFG_H
#define MFC310_GLOB_CFG_H

#define CPU_MPC5675K                        1     /* 1: CPU MPC5675K >= Rev 1, 0: other */

#define GLOB_SYS_FREQUENCY               (180)    /* [MHz] system clock */
#define GLOB_EXT_RAM_ENABLED                0     /* 1: external RAM (0x3000_0000 - 0x3007_FFFF) enabled */

/****************************************************************************/
/*                 For development purpose                                  */
/****************************************************************************/
#define GLOB_DEVELOPMENT_ENVIRONMENT        1     /* 1: level of development, 0: serial production */
#define ISR_DIAGNOSIS                       1     /* 1: interrupt diagnosis enabled, 0: serial production */
#define GLOB_ISR_CONV_DATA                  0     /* 1: convert interrupt runtime ticks into 0.1µs */
#define EMV_NEXUS_PORT_DISABLE              1     /* 1: Disable ENGCLK and EBI_CLKOUT output buffer, 0: for test only */

/****************************************************************************/
/*                 For integration test purposes                            */
/****************************************************************************/
/* activates setting of Dbgpin 468: UCM_DBG4 - used to measure the startup time in integration tests */
#define GLOB_DBG_PIN_STARTUP_TIME                            0
/* activates integrity check of register config - used during integration test  */
#define GLOB_CONFIGREG_INTEGRITY_CHECK_OF_CONFIGURATION      0

/****************************************************************************/
/*                 compiler switches of algo adapters                       */
/****************************************************************************/
#define FCT_ADPT_CPY_OBJ_DATA_TO_WABCO      0     /* 1: object data of FCTSen is copied into WABCO interface */
#define VDY_ADPT_USE_INT_GYRO               0     /* 1: internal gyro is used by VDY adapter */

#endif /* #ifndef ARS301_GLOB_CFG_H */
