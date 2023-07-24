/**
 * \file
 *
 * \brief AUTOSAR WdgM
 *
 * This file contains the implementation of the AUTOSAR
 * module WdgM.
 *
 * \version 6.2.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * MISRA-C:2012 Deviations:
 *
 * MISRAC2012-1) Deviated Rule: 20.7
 * Expressions resulting from the expansion of macro parameters shall be
 * enclosed in parentheses.
 *
 * Reason:
 * The AUTOSAR compiler abstraction requires these definitions in this way
 * and the arguments cannot be enclosed in parentheses due to C syntax.

 * MISRAC2012-2) Deviated Rule: 8.9 (advisory)
 * An object should be defined at block scope if its identifier only appears
 * in a single function.
 *
 * Reason:
 * The object is defined in this way because the values that are stored
 * in them are required for the next call of this function and should be
 * hold in the data segment memory.
 */

/*==================[inclusions]=================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,3 */
#include <WdgM_Lcfg.h>                               /* Module internal BSW declarations and API */
#include <Det.h>                                    /* For Defensive programming reporting */

/*------------------[macros for EB Defensive Programming if not provided by Det]-----------------*/
#if (WDGM_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON)
#ifndef DET_UNREACHABLE_CODE_ASSERT
/** \brief Report a unreachable code assertion (if not already defined by Det)
 **
 ** Use this macro in BSW modules to mark unreachable code as part of
 ** defensive programming.
 **
 ** \param[in] ModuleId The id of the reporting module
 ** \param[in] InstanceId The instance Id of the reporting module
 ** \param[in] ApiId The Api function where the check failed */
#define DET_UNREACHABLE_CODE_ASSERT(ModuleId, InstanceId, ApiId)        \
  do                                                                    \
  {                                                                     \
    WDGM_EB_DET((ApiId), DET_E_UNREACHABLE_CODE_ASSERT_FAILED);         \
  }                                                                     \
  while (0)
#endif
#endif /* (WDGM_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON) */
/*==================[macros]=====================================================================*/


/*==================[type definitions]===========================================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal data]==============================================================*/

/*==================[external data]==============================================================*/

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_START_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable3,1,WDGM.EB.DesignDecision.InternalVariable5,1,
 WDGM.EB.DesignDecision.InternalVariable8,1 */
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_AS_HM[1];
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_SWC_MONITOR[1];
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_CameraTemp[1];
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_ConfigReg[1];
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_FS_MAIN[1];
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_FS_ADC[1];



#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
#if (WDGM_EB_DM_NUM > 0)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable4,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable11,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable9,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable24,1 */
VAR(WdgM_EB_DMDataType,WDGM_VAR) WdgM_EB_DMData[WDGM_EB_DM_NUM];
#else
VAR(WdgM_EB_DMDataType,WDGM_VAR) WdgM_EB_DMData[1];
#endif
#endif

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_STOP_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

/*==================[internal constants]=========================================================*/

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_CONST_16BIT
#else
#define WDGM_START_SEC_CONST_ASIL_D_16
#endif
#include <WdgM_MemMap.h>


#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_CONST_16BIT
#else
#define WDGM_STOP_SEC_CONST_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

#define WDGM_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

/*------------------[trigger and watchdog configuration]--------------------*/

/* trigger configuration for mode WDGM_NORMAL_OPERATION */
static CONST(WdgM_EB_TriggerCfgType,WDGM_CONST) WdgM_EB_TrigCfg_M0[1] =
{
  { /* WdgMTrigger_Normal */
    WDGIF_FAST_MODE, /* watchdog trigger mode */
    64U, /* TriggerCondition */
    0U, /* watchdog device index */
  },
};

/* trigger configuration for mode WDGM_SLEEP */
static CONST(WdgM_EB_TriggerCfgType,WDGM_CONST) WdgM_EB_TrigCfg_M1[1] =
{
  { /* WdgMTrigger_0 */
    WDGIF_OFF_MODE, /* watchdog trigger mode */
    256U, /* TriggerCondition */
    0U, /* watchdog device index */
  },
};


/*------------------[SE configuration]--------------------------------------*/

/*------------------Internal configuration data for SE: WdgM_SE_AS_HM */

/* alive supervision of CP WdgMCheckpoint_AS_HM in mode 0 */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_0_0_0 =
{
  3U, /* ExpextedAliveIndication */
  9U, /* Amount of supervision reference cycles */
  1U, /* max margin */
  1U /* min margin */
};


/* checkpoint configuration of SE WdgM_SE_AS_HM */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_WdgM_SE_AS_HM[1] =
{
  {
    /* CP WdgMCheckpoint_AS_HM*/
    {
      /* alive supervision per WdgM mode */
      &(WdgM_EB_CPAliveCfg_0_0_0),
      NULL_PTR,
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
    /* external logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
  },
};

/*------------------Internal configuration data for SE: WdgM_SE_SWC_MONITOR */

/* alive supervision of CP WdgMCheckpoint_SWC_MONITOR in mode 0 */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_1_0_0 =
{
  18U, /* ExpextedAliveIndication */
  216U, /* Amount of supervision reference cycles */
  12U, /* max margin */
  12U /* min margin */
};


/* checkpoint configuration of SE WdgM_SE_SWC_MONITOR */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_WdgM_SE_SWC_MONITOR[1] =
{
  {
    /* CP WdgMCheckpoint_SWC_MONITOR*/
    {
      /* alive supervision per WdgM mode */
      &(WdgM_EB_CPAliveCfg_1_0_0),
      NULL_PTR,
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
    /* external logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
  },
};

/*------------------Internal configuration data for SE: WdgM_SE_CameraTemp */

/* alive supervision of CP WdgMCheckpoint_CameraTemp in mode 0 */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_2_0_0 =
{
  8U, /* ExpextedAliveIndication */
  8U, /* Amount of supervision reference cycles */
  2U, /* max margin */
  2U /* min margin */
};


/* checkpoint configuration of SE WdgM_SE_CameraTemp */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_WdgM_SE_CameraTemp[1] =
{
  {
    /* CP WdgMCheckpoint_CameraTemp*/
    {
      /* alive supervision per WdgM mode */
      &(WdgM_EB_CPAliveCfg_2_0_0),
      NULL_PTR,
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
    /* external logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
  },
};

/*------------------Internal configuration data for SE: WdgM_SE_ConfigReg */

/* alive supervision of CP WdgMCheckpoint_ConfigReg in mode 0 */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_3_0_0 =
{
  2U, /* ExpextedAliveIndication */
  20U, /* Amount of supervision reference cycles */
  1U, /* max margin */
  1U /* min margin */
};


/* checkpoint configuration of SE WdgM_SE_ConfigReg */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_WdgM_SE_ConfigReg[1] =
{
  {
    /* CP WdgMCheckpoint_ConfigReg*/
    {
      /* alive supervision per WdgM mode */
      &(WdgM_EB_CPAliveCfg_3_0_0),
      NULL_PTR,
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
    /* external logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
  },
};

/*------------------Internal configuration data for SE: WdgM_SE_FS_MAIN */

/* alive supervision of CP WdgMCheckpoint_FS_MAIN in mode 0 */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_4_0_0 =
{
  10U, /* ExpextedAliveIndication */
  10U, /* Amount of supervision reference cycles */
  2U, /* max margin */
  3U /* min margin */
};


/* checkpoint configuration of SE WdgM_SE_FS_MAIN */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_WdgM_SE_FS_MAIN[1] =
{
  {
    /* CP WdgMCheckpoint_FS_MAIN*/
    {
      /* alive supervision per WdgM mode */
      &(WdgM_EB_CPAliveCfg_4_0_0),
      NULL_PTR,
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
    /* external logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
  },
};

/*------------------Internal configuration data for SE: WdgM_SE_FS_ADC */

/* alive supervision of CP WdgMCheckpoint_FS_ADC in mode 0 */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_5_0_0 =
{
  20U, /* ExpextedAliveIndication */
  20U, /* Amount of supervision reference cycles */
  3U, /* max margin */
  5U /* min margin */
};


/* checkpoint configuration of SE WdgM_SE_FS_ADC */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_WdgM_SE_FS_ADC[1] =
{
  {
    /* CP WdgMCheckpoint_FS_ADC*/
    {
      /* alive supervision per WdgM mode */
      &(WdgM_EB_CPAliveCfg_5_0_0),
      NULL_PTR,
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
    /* external logical supervision per WdgM mode */
    {
      NULL_PTR,
      NULL_PTR,
    },
#endif
  },
};

#define WDGM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>


/*==================[external constants]=========================================================*/

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_CONST_8BIT
#else
#define WDGM_START_SEC_CONST_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

CONST(WdgM_ModeType,WDGM_CONST) WdgM_EB_InitialModeId =
    WdgMConf_WdgMMode_WDGM_SLEEP;


CONST(WdgM_ModeType,WDGM_CONST) WdgM_EB_ModeCfgSize = WDGM_EB_MODE_NUM;

CONST(WdgM_EB_SEIdType, WDGM_CONST) WdgM_EB_SEIntSEId[WDGM_EB_SE_NUM] =
{
  0U, /* Internal Id of WdgM_SE_AS_HM */
  1U, /* Internal Id of WdgM_SE_SWC_MONITOR */
  2U, /* Internal Id of WdgM_SE_CameraTemp */
  3U, /* Internal Id of WdgM_SE_ConfigReg */
  4U, /* Internal Id of WdgM_SE_FS_MAIN */
  5U, /* Internal Id of WdgM_SE_FS_ADC */
};


CONST(WdgM_EB_SEIdType, WDGM_CONST) WdgM_EB_SELocalCoreIdx[WDGM_EB_SE_NUM] =
{
  0U, /* Maps internal Id of WdgM_SE_AS_HM to Idx in Core 0 status array*/
  0U, /* Maps internal Id of WdgM_SE_SWC_MONITOR to Idx in Core 1 status array*/
  1U, /* Maps internal Id of WdgM_SE_CameraTemp to Idx in Core 0 status array*/
  2U, /* Maps internal Id of WdgM_SE_ConfigReg to Idx in Core 0 status array*/
  3U, /* Maps internal Id of WdgM_SE_FS_MAIN to Idx in Core 0 status array*/
  4U, /* Maps internal Id of WdgM_SE_FS_ADC to Idx in Core 0 status array*/

};



#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_CONST_8BIT
#else
#define WDGM_STOP_SEC_CONST_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/*------------------[mode configuration]------------------------------------*/
#define WDGM_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

CONST(WdgM_EB_ModeCfgType, WDGM_CONST) WdgM_EB_ModeCfg[WDGM_EB_MODE_NUM] =
{
  { /* mode WDGM_NORMAL_OPERATION (id 0) */
    1080U, /* least common multiple of all reference cycle values */
    WdgM_EB_TrigCfg_M0, /* trigger configuration */
    0U, /* number of supervision cycles in stats EXPIRED */
    1U /* number of watchdogs (triggers) */
  },
  { /* mode WDGM_SLEEP (id 1) */
    1U, /* least common multiple of all reference cycle values */
    WdgM_EB_TrigCfg_M1, /* trigger configuration */
    5U, /* number of supervision cycles in stats EXPIRED */
    1U /* number of watchdogs (triggers) */
  },
};

/* -----------------[SE configuration]--------------------- */

CONST(WdgM_EB_SECfgType,WDGM_CONST) WdgM_EB_SECfg[WDGM_EB_SE_NUM] =
{
  { /* SE WdgM_SE_AS_HM (internal SEId: 0) */
    WdgM_EB_CPCfg_WdgM_SE_AS_HM, /* pointer to the array of checkpoints */
    WdgM_EB_CPData_WdgM_SE_AS_HM, /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_AS_HM, /* external SEId */
    1U, /* number of CPs in this SE */
    FALSE, /* Support for Error Recovery */
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      1U, /* WdgM mode WDGM_NORMAL_OPERATION */
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode WDGM_SLEEP */
    },
    0U, /* the core id of a SE */
  },
  { /* SE WdgM_SE_SWC_MONITOR (internal SEId: 1) */
    WdgM_EB_CPCfg_WdgM_SE_SWC_MONITOR, /* pointer to the array of checkpoints */
    WdgM_EB_CPData_WdgM_SE_SWC_MONITOR, /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_SWC_MONITOR, /* external SEId */
    1U, /* number of CPs in this SE */
    FALSE, /* Support for Error Recovery */
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      1U, /* WdgM mode WDGM_NORMAL_OPERATION */
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode WDGM_SLEEP */
    },
    1U, /* the core id of a SE */
  },
  { /* SE WdgM_SE_CameraTemp (internal SEId: 2) */
    WdgM_EB_CPCfg_WdgM_SE_CameraTemp, /* pointer to the array of checkpoints */
    WdgM_EB_CPData_WdgM_SE_CameraTemp, /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_CameraTemp, /* external SEId */
    1U, /* number of CPs in this SE */
    FALSE, /* Support for Error Recovery */
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      1U, /* WdgM mode WDGM_NORMAL_OPERATION */
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode WDGM_SLEEP */
    },
    0U, /* the core id of a SE */
  },
  { /* SE WdgM_SE_ConfigReg (internal SEId: 3) */
    WdgM_EB_CPCfg_WdgM_SE_ConfigReg, /* pointer to the array of checkpoints */
    WdgM_EB_CPData_WdgM_SE_ConfigReg, /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_ConfigReg, /* external SEId */
    1U, /* number of CPs in this SE */
    FALSE, /* Support for Error Recovery */
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      1U, /* WdgM mode WDGM_NORMAL_OPERATION */
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode WDGM_SLEEP */
    },
    0U, /* the core id of a SE */
  },
  { /* SE WdgM_SE_FS_MAIN (internal SEId: 4) */
    WdgM_EB_CPCfg_WdgM_SE_FS_MAIN, /* pointer to the array of checkpoints */
    WdgM_EB_CPData_WdgM_SE_FS_MAIN, /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_MAIN, /* external SEId */
    1U, /* number of CPs in this SE */
    FALSE, /* Support for Error Recovery */
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      1U, /* WdgM mode WDGM_NORMAL_OPERATION */
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode WDGM_SLEEP */
    },
    0U, /* the core id of a SE */
  },
  { /* SE WdgM_SE_FS_ADC (internal SEId: 5) */
    WdgM_EB_CPCfg_WdgM_SE_FS_ADC, /* pointer to the array of checkpoints */
    WdgM_EB_CPData_WdgM_SE_FS_ADC, /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_WdgM_SE_FS_ADC, /* external SEId */
    1U, /* number of CPs in this SE */
    FALSE, /* Support for Error Recovery */
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      1U, /* WdgM mode WDGM_NORMAL_OPERATION */
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode WDGM_SLEEP */
    },
    0U, /* the core id of a SE */
  },
};

/* Dummy module configuration structure*/
CONST(WdgM_ConfigType, WDGM_APPL_CONST) WDGM_CONFIG_NAME = 0;

#define WDGM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

/*============[WdgM internal data]===============*/
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_8BIT
#else
#define WDGM_START_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_EXT_GET_EXPECTED_INIT_STATE_ENABLED == STD_OFF || WDGM_EB_MULTICORE_ENABLED == STD_ON)
/* For multicore this variable is also used by the master to announce the satellites of the
 * result of the WdgMGetExpectedInitStateCallout(), so this is not under the
 * WDGM_EB_EXT_GET_EXPECTED_INIT_STATE_ENABLED == STD_OFF compiler switch. */
/** \brief Expected initialization state of the WdgM module */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable18,1 */
VAR(WdgM_EB_InitStatusType, WDGM_VAR) WdgM_EB_ExpectedInitState = WDGM_EB_INIT_STATUS_DEINIT;
#endif

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable2,1 */
/** \brief WdgM global supervision status */
VAR(WdgM_GlobalStatusType, WDGM_VAR) WdgM_EB_GlobalStatus = WDGM_GLOBAL_STATUS_DEACTIVATED;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_8BIT
#else
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>


/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable26,1 */
/** \brief has the expired SEId been set? */
VAR(boolean, WDGM_VAR) WdgM_EB_IsExpiredSEIdSet;

#if (WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE_ENABLED == STD_OFF)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable17,1 */
VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_ExpectedWdgMModeId;
#endif

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>


#define WDGM_START_SEC_VAR_POWER_ON_INIT_ASIL_D_16
#include <WdgM_MemMap.h>

/** \brief the Supervised Entity Id which first expired */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable19,1 */
VAR(WdgM_EB_ExpiredSEIDType, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEID = 0U;

#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_ASIL_D_16
#include <WdgM_MemMap.h>




#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable14,1 */
/** \brief through this variable, the WdgM master instance announces the WdgM satellite instances that the mode switch has been performed.
* The WdgM satellite instances read the value of this variable to change and update their mode. */
VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_CoreSwitchMode_Core0;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_1_MemMap.h>

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable14,1 */
/** \brief through this variable, the WdgM master instance announces the WdgM satellite instances that the mode switch has been performed.
* The WdgM satellite instances read the value of this variable to change and update their mode. */
VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_CoreSwitchMode_Core1;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_1_MemMap.h>


#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_8BIT
#else
#define WDGM_START_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.MulticoreInit.4,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable15,3 */
/** \brief WdgM/WdgM core instance initialization status */
static VAR(WdgM_EB_InitStatusType, WDGM_VAR) WdgM_EB_InitStatus_Core0 = WDGM_EB_INIT_STATUS_DEINIT;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_8BIT
#else
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>


#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_START_SEC_VAR_8BIT
#else
#define WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_1_CORE_1_MemMap.h>

/* !LINKSTO WDGM.EB.MulticoreInit.4,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable15,3 */
/** \brief WdgM/WdgM core instance initialization status */
static VAR(WdgM_EB_InitStatusType, WDGM_VAR) WdgM_EB_InitStatus_Core1 = WDGM_EB_INIT_STATUS_DEINIT;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_STOP_SEC_VAR_8BIT
#else
#define WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_1_CORE_1_MemMap.h>



#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.MulticoreLocalStatus2,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable1,4 */
/** \brief defines the local statuses of all SE from core 0 */
static VAR(WdgM_LocalStatusType, WDGM_VAR) WdgM_EB_SELocalStatus_Core0[WDGM_EB_SE_NUM_CORE0];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>


#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_1_MemMap.h>

/* !LINKSTO WDGM.EB.MulticoreLocalStatus2,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable1,4 */
/** \brief defines the local statuses of all SE from core 1 */
static VAR(WdgM_LocalStatusType, WDGM_VAR) WdgM_EB_SELocalStatus_Core1[WDGM_EB_SE_NUM_CORE1];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_1_MemMap.h>



#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable25,1 */
/** \brief Internal RAM data holding a copy of the alive counter values for each checkpoint */
static VAR(WdgM_EB_CPInternalDataType, WDGM_VAR) WdgM_EB_IntRAMData_Core0[WDGM_EB_CHECKPOINTS_NUM_CORE0];

/* !LINKSTO WDGM.ASR40.WDGM085.3,1, WDGM.EB.DesignDecision.InternalVariable10,3 */
/** \brief failed reference cycle counter for the SE  */
static VAR(uint16, WDGM_VAR) WdgM_EB_FailedAliveSupervisionRefCycleCnt_Core0[WDGM_EB_SE_NUM_CORE0];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>


#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_START_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_1_CORE_1_START_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_1_CORE_1_MemMap.h>

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable25,1 */
/** \brief Internal RAM data holding a copy of the alive counter values for each checkpoint */
static VAR(WdgM_EB_CPInternalDataType, WDGM_VAR) WdgM_EB_IntRAMData_Core1[WDGM_EB_CHECKPOINTS_NUM_CORE1];

/* !LINKSTO WDGM.ASR40.WDGM085.3,1, WDGM.EB.DesignDecision.InternalVariable10,3 */
/** \brief failed reference cycle counter for the SE  */
static VAR(uint16, WDGM_VAR) WdgM_EB_FailedAliveSupervisionRefCycleCnt_Core1[WDGM_EB_SE_NUM_CORE1];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_1_CORE_1_STOP_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_1_CORE_1_MemMap.h>


#define WDGM_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_MemMap.h>


/** \brief The WdgM core specific context data.
 ** This variable holds the core-specific run time data of the WdgM. */
/* Deviation MISRAC2012-2 */
static VAR(WdgM_EB_CoreContextType, WDGM_VAR) WdgM_EB_Core0_Context =
{
  WdgM_EB_SELocalStatus_Core0,
  WdgM_EB_FailedAliveSupervisionRefCycleCnt_Core0,
  WdgM_EB_IntRAMData_Core0,
  &WdgM_EB_InitStatus_Core0,
  &WdgM_EB_CoreSwitchMode_Core0,
  0U,
  0U,
  FALSE,
#if (WDGM_EB_CHECK_MAINFUNCTION_TIMING == STD_ON)
  0U,
#endif
  0U,
};

#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_MemMap.h>


#define WDGM_1_CORE_1_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_1_CORE_1_MemMap.h>


/** \brief The WdgM core specific context data.
 ** This variable holds the core-specific run time data of the WdgM. */
/* Deviation MISRAC2012-2 */
static VAR(WdgM_EB_CoreContextType, WDGM_VAR) WdgM_EB_Core1_Context =
{
  WdgM_EB_SELocalStatus_Core1,
  WdgM_EB_FailedAliveSupervisionRefCycleCnt_Core1,
  WdgM_EB_IntRAMData_Core1,
  &WdgM_EB_InitStatus_Core1,
  &WdgM_EB_CoreSwitchMode_Core1,
  0U,
  0U,
  FALSE,
#if (WDGM_EB_CHECK_MAINFUNCTION_TIMING == STD_ON)
  0U,
#endif
  1U,
};

#define WDGM_1_CORE_1_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_1_CORE_1_MemMap.h>


#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

/* Deviation MISRAC2012-1 */
FUNC_P2VAR(WdgM_EB_CoreContextType, WDGM_APPL_DATA, WDGM_CODE) WdgM_GetCoreInstance(void)
{
  P2VAR(WdgM_EB_CoreContextType, AUTOMATIC, WDGM_APPL_DATA) inst = NULL_PTR;

  const WdgM_EB_CoreIdType coreID = WDGM_EB_GET_CORE_ID();

  switch(coreID)
  {
    case 0:
    {
      inst = &WdgM_EB_Core0_Context;
      break;
    }
    case 1:
    {
      inst = &WdgM_EB_Core1_Context;
      break;
    }
    default:
    {
      /* No WdgM instance exists for core. */
      break;
    }
  }

  return inst;
}

/* !LINKSTO WDGM.EB.MulticoreInit.4,1 */
/* Deviation MISRAC2012-1 */
FUNC(WdgM_EB_InitStatusType, WDGM_CODE) WdgM_EB_GetGlobalInitStatus(void)
{
  WdgM_EB_InitStatusType GlobalInitStatus = WDGM_EB_INIT_STATUS_INIT;
  if(
          (WDGM_EB_INIT_STATUS_DEINIT == WdgM_EB_InitStatus_Core0)
            ||
          (WDGM_EB_INIT_STATUS_DEINIT == WdgM_EB_InitStatus_Core1)
  )
  {
    GlobalInitStatus = WDGM_EB_INIT_STATUS_DEINIT;
  }

  return GlobalInitStatus;
}

/* Deviation MISRAC2012-1 */
FUNC(WdgM_EB_InitStatusType, WDGM_CODE) WdgM_EB_GetMasterInitStatus(void)
{
  return WdgM_EB_InitStatus_Core0;
}


/* !LINKSTO WDGM.EB.MulticoreLocalStatus2,1 */
/* Deviation MISRAC2012-1 */
FUNC(WdgM_LocalStatusType, WDGM_CODE) WdgM_EB_GetSELocalStatus(WdgM_EB_SEIdType IntSEId, uint8 ApiId)
{
  WdgM_LocalStatusType LocalStatus = 0xFF;

#if (WDGM_UNREACHABLE_CODE_ASSERT_ENABLED == STD_OFF)
  WDGM_EB_PARAM_UNUSED(ApiId);
#endif

  switch(IntSEId)
  {
    case 0: LocalStatus = WdgM_EB_SELocalStatus_Core0[0];
      break;
    case 2: LocalStatus = WdgM_EB_SELocalStatus_Core0[1];
      break;
    case 3: LocalStatus = WdgM_EB_SELocalStatus_Core0[2];
      break;
    case 4: LocalStatus = WdgM_EB_SELocalStatus_Core0[3];
      break;
    case 5: LocalStatus = WdgM_EB_SELocalStatus_Core0[4];
      break;
    case 1: LocalStatus = WdgM_EB_SELocalStatus_Core1[0];
      break;
     /* CHECK: NOPARSE */
    default: WDGM_UNREACHABLE_CODE_ASSERT(ApiId);
      break;
    /* CHECK: PARSE*/
  }

  return LocalStatus;
}


/* Deviation MISRAC2012-1 */
FUNC(WdgM_ModeType, WDGM_CODE) WdgM_EB_GetCoreSwitchMode(WdgM_EB_CoreIdType CoreId)
{
  WdgM_ModeType LocalMode = 0xFF;

  switch(CoreId)
  {
    case 0: LocalMode = WdgM_EB_CoreSwitchMode_Core0;
      break;
    case 1: LocalMode = WdgM_EB_CoreSwitchMode_Core1;
      break;
     /* CHECK: NOPARSE */
    default: WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
      break;
    /* CHECK: PARSE*/
  }

  return LocalMode;
}

/* Deviation MISRAC2012-1 */
FUNC(boolean, WDGM_CODE) WdgM_EB_AllCoresSameMode(void)
{
  boolean AllCoresSameMode = TRUE;


  if(
    (WdgM_EB_CoreSwitchMode_Core0 != WdgM_EB_CoreSwitchMode_Core1)
  )
  {
    AllCoresSameMode = FALSE;
  }

  return AllCoresSameMode;
}

#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>



/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_START_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
#if (WDGM_EB_EXTERNAL_GRAPH_NUM > 0U)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable12,1,WDGM.EB.DesignDecision.InternalVariable13,1 */
VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_ExternalGraphData[WDGM_EB_EXTERNAL_GRAPH_NUM];
#else
VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_ExternalGraphData[1];
#endif

#if (WDGM_EB_INTERNAL_GRAPH_NUM > 0U)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable6,2,WDGM.EB.DesignDecision.InternalVariable7,2 */
VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_InternalGraphData[WDGM_EB_INTERNAL_GRAPH_NUM];
#else
VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_InternalGraphData[1];
#endif
#endif

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_STOP_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#else
#define WDGM_START_SEC_CONST_ASIL_D_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_EXTERNAL_GRAPH_NUM > 0U)
/** \brief array of pointers to the run-time data for each external graph and length of the pointed arrays */
CONST(WdgM_EB_ExtGraphDataSeqType,WDGM_CONST) WdgM_EB_ExtGraphDataSeqPtr[WDGM_EB_EXTERNAL_GRAPH_NUM] =
{
};
#endif

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#else
#define WDGM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

/*==================[external function definitions]==============================================*/
/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
