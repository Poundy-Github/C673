/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Fee_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 13.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2023-06-28, 11:21:43    !!!IGNORE-LINE!!!                 **
**                                                                            **
**  GENERATOR : Build b211016-0103                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Fee.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Fee configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Fee Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef  FEE_CFG_H
#define  FEE_CFG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Typedefs Imported from Memory Abstract Interface */ 
#include "MemIf.h"

/* Callback functions imported from NvM Module */
#include "NvM_Cbk.h"

/* Callback functions imported from QsM Module */
#include "QsM_Cbk.h"

/* Functions imported from Fls Module */
#include "Fls_17_Dmu.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* FEE AS version information */
#define FEE_AS_VERSION (422)



#define FEE_AR_RELEASE_MAJOR_VERSION  (4U)
#define FEE_AR_RELEASE_MINOR_VERSION  (2U)
#define FEE_AR_RELEASE_REVISION_VERSION  (2U)
/* Vendor specific implementation version information */



#define FEE_SW_MAJOR_VERSION  (20U)
#define FEE_SW_MINOR_VERSION  (0U)
#define FEE_SW_PATCH_VERSION  (2U)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                    Static configuration parameters                         **
*******************************************************************************/

/* Development error detection enabled/disabled */
#define FEE_DEV_ERROR_DETECT       (STD_ON)


/* Enable/Disable Safety error detection and reporting*/
#define FEE_SAFETY_ENABLE         (STD_ON)

/* Enable/Disable FEE Init Check API*/
#define FEE_INITCHECK_API         (STD_ON)
/* Fee_GetVersionInfo API enabled/disabled */
#define FEE_VERSION_INFO_API       (STD_ON)

/* Fee_GetCycleCount API enabled/disabled */
#define FEE_GET_CYCLE_COUNT_API    (STD_OFF)

/* Fee_GetEccErrorInfo API enabled/disabled */

#define FEE_GET_ECC_ERROR_INFO_API         (STD_OFF)
/* Runtime Error*/

#define FEE_RUNTIME_ERROR_DETECT (STD_OFF)
/* Fee_SetMode API enabled/disabled */

#define FEE_SET_MODE_SUPPORTED     (STD_ON)


#define FEE_QSBLOCK_BEGIN_INDEX (42U)

/* Block type configured */

#define FEE_DATA_BLOCK_SUPPORTED FEE_DOUBLE_SECTOR_AND_QUASI_STATIC_DATA


#define FEE_NUM_QUASI_BLOCKS                (5U)

/* Fee_17_GetPrevData API enabled/disabled */
#define FEE_GET_PREV_DATA_API      (STD_OFF)


/* Fee_17_CancelAll  API enabled/disabled */
#define FEE_CANCELL_ALL_API      (STD_OFF)


#define FEE_MAX_BYTES_PER_CYCLE      (512U)
/* FEE programs state pages upon detection of virgin flash */
#define FEE_VIRGIN_FLASH_ILLEGAL_STATE      (STD_OFF)

/* Enable/Disable Debug support  */
#define FEE_DEBUG_SUPPORT     (STD_OFF)


/*FeeMainFunctionPeriod value in micro seconds(us)*/
#define FEE_MAIN_FUNCTION_PERIOD       10000


/* Erase suspend/resume feature supported in FLS */
#define FEE_FLS_SUPPORTS_ERASE_SUSPEND  (STD_OFF)

/* DFlash WordLine size */
#define FEE_DFLASH_WORDLINE_SIZE     (512U)

#define FEE_CONTINUE          (0U)
#define FEE_STOP_AT_GC        (1U)


#define FEE_UNCFG_BLK_OVERFLOW_HANDLE    (FEE_CONTINUE)

/* Virtual page size, i.e., DF_EEPROM page size */
#define FEE_VIRTUAL_PAGE_SIZE      (8U)


/* Logical block's overhead in bytes */
#define FEE_BLOCK_OVERHEAD         (17U)


/* Logical block's data page overhead in bytes */
#define FEE_PAGE_OVERHEAD          (1U)

/* Maximum number of configured blocks to be handled */

#define FEE_MAX_BLOCK_COUNT        (47U)

/* Number of pages to be scanned and analyzed in one Fee_Main() cycle. */

#define FEE_PAGES_PER_FEEMAIN      (65535U)

/* Symbolic names of logical blocks */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID ((uint16)16)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red ((uint16)17)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvMBlock_ConfigID_Red */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_DEFAULT_0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_DEFAULT_0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_DEFAULT_0 ((uint16)32)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_DEFAULT_0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_0 ((uint16)48)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_1 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_1 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_1 ((uint16)49)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_1 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_2 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_2 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_2 ((uint16)50)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_2 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_3 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_3 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_3 ((uint16)51)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_3 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_4 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_4 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_4 ((uint16)52)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_4 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_5 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_5 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_5 ((uint16)53)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_5 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_6 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_6 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_6 ((uint16)54)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_6 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_7 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_7 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_7 ((uint16)55)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_7 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_8 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_8 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_8 ((uint16)56)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_8 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_9 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_9 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_9 ((uint16)57)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_9 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_10 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_10 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_10 ((uint16)58)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_10 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_11 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_11 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_11 ((uint16)59)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_11 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_12 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_12 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_12 ((uint16)60)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_12 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_13 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_13 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_13 ((uint16)61)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_13 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_14 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_14 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_14 ((uint16)62)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_14 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_15 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_15 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_15 ((uint16)63)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_DEM_PRIMARY_15 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_ECUHardwareVersion 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_ECUHardwareVersion already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_ECUHardwareVersion ((uint16)80)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_ECUHardwareVersion */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_SerialNumberDataId 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_SerialNumberDataId already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_SerialNumberDataId ((uint16)96)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_SerialNumberDataId */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_FAB_switch 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_FAB_switch already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_FAB_switch ((uint16)112)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_FAB_switch */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TSR_switch 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TSR_switch already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TSR_switch ((uint16)128)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TSR_switch */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TLA_switch 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TLA_switch already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TLA_switch ((uint16)144)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_TLA_switch */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Security_AttemptCount 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Security_AttemptCount already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Security_AttemptCount ((uint16)160)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Security_AttemptCount */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_VINDataIdentifier 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_VINDataIdentifier already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_VINDataIdentifier ((uint16)64)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_VINDataIdentifier */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_EOL_Info_Input 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_EOL_Info_Input already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_EOL_Info_Input ((uint16)352)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_EOL_Info_Input */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_Block_SecureUpdateLog 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_Block_SecureUpdateLog already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_Block_SecureUpdateLog ((uint16)192)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_Block_SecureUpdateLog */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_PartNumber_Sector 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_PartNumber_Sector already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_PartNumber_Sector ((uint16)208)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_PartNumber_Sector */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_Block_Startup_Flag 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_Block_Startup_Flag already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_Block_Startup_Flag ((uint16)240)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_Block_Startup_Flag */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_Block_ABCheck 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_Block_ABCheck already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_Block_ABCheck ((uint16)224)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_Block_ABCheck */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Fingerprint 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Fingerprint already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Fingerprint ((uint16)256)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Fingerprint */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Vehicletype 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Vehicletype already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Vehicletype ((uint16)272)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NVM_BLOCK_Vehicletype */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_PCBASerialNumberDataIdentifier 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_PCBASerialNumberDataIdentifier already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_PCBASerialNumberDataIdentifier ((uint16)288)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_PCBASerialNumberDataIdentifier */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_LaneFunctionConfiguration 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_LaneFunctionConfiguration already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_LaneFunctionConfiguration ((uint16)304)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_LaneFunctionConfiguration */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_EOLCalibrationData 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_EOLCalibrationData already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_EOLCalibrationData ((uint16)320)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_EOLCalibrationData */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_SDACalibrationData 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_SDACalibrationData already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_SDACalibrationData ((uint16)336)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_SDACalibrationData */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_Block_EOLModeGate 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_Block_EOLModeGate already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_Block_EOLModeGate ((uint16)176)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_Block_EOLModeGate */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_Block_HMISwitchStatus 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_Block_HMISwitchStatus already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_Block_HMISwitchStatus ((uint16)368)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_Block_HMISwitchStatus */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD14 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD14 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD14 ((uint16)384)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD14 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD15 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD15 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD15 ((uint16)400)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD15 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD16 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD16 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD16 ((uint16)416)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD16 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD17 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD17 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD17 ((uint16)432)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD17 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD18 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD18 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD18 ((uint16)448)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD18 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD19 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD19 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD19 ((uint16)464)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_FD19 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_VDYData 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_VDYData already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_VDYData ((uint16)480)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_VDYData */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_FS_Debug_Status 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_FS_Debug_Status already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_FS_Debug_Status ((uint16)496)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Fee_NvM_BLOCK_FS_Debug_Status */


#define FEE_DISABLE_DEM_REPORT   (0U)
#define FEE_ENABLE_DEM_REPORT    (1U)

/* DEM Configurations */

#define FEE_GC_INIT_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_INIT                (DemConf_DemEventParameter_FEE_E_GC_INIT)

#define FEE_WRITE_DEM_REPORT         (FEE_ENABLE_DEM_REPORT)

#define FEE_E_WRITE                  (DemConf_DemEventParameter_FEE_E_WRITE)

#define FEE_READ_DEM_REPORT          (FEE_ENABLE_DEM_REPORT)

#define FEE_E_READ                   (DemConf_DemEventParameter_FEE_E_READ)

#define FEE_GC_WRITE_DEM_REPORT      (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_WRITE               (DemConf_DemEventParameter_FEE_E_GC_WRITE)

#define FEE_GC_READ_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_READ                (DemConf_DemEventParameter_FEE_E_GC_READ)

#define FEE_GC_ERASE_DEM_REPORT      (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_ERASE               (DemConf_DemEventParameter_FEE_E_GC_ERASE)

#define FEE_INVALIDATE_DEM_REPORT    (FEE_ENABLE_DEM_REPORT)

#define FEE_E_INVALIDATE             (DemConf_DemEventParameter_FEE_E_INVALIDATE)

#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_ENABLE_DEM_REPORT)

#define FEE_E_WRITE_CYCLES_EXHAUSTED (DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED)

#define FEE_GC_TRIG_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)

#define FEE_E_GC_TRIG                (DemConf_DemEventParameter_FEE_E_GC_TRIG)
#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_ENABLE_DEM_REPORT)

#define FEE_E_UNCONFIG_BLK_EXCEEDED  (DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED)


#define FEE_DEM_ENABLED              (STD_ON)
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#endif /* #ifndef FEE_CFG_H */
