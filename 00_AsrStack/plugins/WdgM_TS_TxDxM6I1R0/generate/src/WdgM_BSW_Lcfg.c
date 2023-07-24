/**
 * \file
 *
 * \brief AUTOSAR WdgM
 *
 * This file contains the implementation of the AUTOSAR
 * module WdgM.
 *
 * \version 6.1.40
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
[!INCLUDE "../include/WdgM_Cfg.m"!][!//
[!INCLUDE "../include/WdgM_Macros.m"!][!//
[!INCLUDE "../include/WdgM_Checks.m"!][!//
[!CODE!][!//

/*==================[inclusions]=================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,2 */
#include <WdgM_Lcfg.h>                               /* Module internal BSW declarations and API */
[!IF "$WdgMMulticoreEnabled = 'true'"!]
    [!IF "$DefaultServiceAPI = 'NONE'"!][!//
#include <WdgM.h>                                   /* For WdgM_MainFunction() */
    [!ENDIF!][!//
    [!IF "$DevErrorDetectEnabled"!][!//
#include <Det.h>                                    /* For Defensive programming reporting */
    [!ENDIF!][!//
[!VAR "MULTICORE_NUM_CORES" = "node:value(as:modconf('WdgM')[1]/WdgMGeneral/WdgMGeneralMulticore/WdgMNumberOfCores)"!]
[!ELSE!][!//
[!VAR "MULTICORE_NUM_CORES" = "1"!]
[!ENDIF!][!//
[!IF "node:exists(as:modconf('WdgM')[1]/WdgMGeneral/WdgMGeneralMulticore/WdgMMasterCoreId)"!][!//
[!VAR "WDGM_MASTER_CORE_ID" = "node:value(as:modconf('WdgM')[1]/WdgMGeneral/WdgMGeneralMulticore/WdgMMasterCoreId)"!][!//
[!ELSE!][!//
[!VAR "WDGM_MASTER_CORE_ID" = "'0'"!][!//
[!ENDIF!][!//

/*==================[macros]=====================================================================*/

[!AUTOSPACING!][!//
[!//

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
[!LOOP "WdgMGeneral/WdgMSupervisedEntity/*"!][!//
/* Checkpoint individual run-time data for each SE */
VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_[!"@name"!][[!"num:i(count(WdgMCheckpoint/*))"!]];
[!ENDLOOP!][!//



#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
#if (WDGM_EB_DM_NUM > 0)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable4,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable10,2 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable11,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable9,1 */
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

[!IF "$WdgMPartitionResetEnabled = 'true'"!]
#define WDGM_START_SEC_VAR_INIT_ASIL_D_8
#include <WdgM_MemMap.h>
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
[!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!][!//

/** \brief
 **  Status of WdgM partitions configured by mapped SEs to OS applications of Core [!"num:i($index_i)"!].
 **/
STATIC VAR(uint8, WDGM_VAR) WdgM_EB_Core[!"num:i($index_i)"!]_PartitionStatus[[!"num:i($WdgMNumOfPartitionsPerCore)"!]U] = 
{
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
  WDGM_EB_PARTITION_ACTIVE, /* [!"name(as:ref(./WdgMOsApplicationRef))"!] */
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
  WDGM_EB_PARTITION_ACTIVE, /* [!"name(as:ref(./WdgMOsApplicationRef))"!] */
          [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
};

[!ENDIF!][!//
[!ENDFOR!][!//
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#include <WdgM_MemMap.h>

#define WDGM_START_SEC_VAR_INIT_ASIL_D_32
#include <WdgM_MemMap.h>
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]

[!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!][!//
/** \brief
 **  Holds the supervision cycle counter for alive supervision of
 **  WdgM partitions configured by mapped SEs to OS applications of Core [!"num:i($index_i)"!].
 **/
STATIC VAR(uint32, WDGM_VAR) WdgM_EB_Core[!"num:i($index_i)"!]PartitionSupervisionCycleCnt[[!"num:i($WdgMNumOfPartitionsPerCore)"!]U] = 
{
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
            [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
              [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
  0U, /* [!"name(as:ref(./WdgMOsApplicationRef))"!] */
            [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
  0U, /* [!"name(as:ref(./WdgMOsApplicationRef))"!] */
          [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
};

[!ENDIF!][!//
[!ENDFOR!][!//
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_32
#include <WdgM_MemMap.h>

[!ENDIF!][!//
/*==================[internal constants]=========================================================*/

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_CONST_16BIT
#else
#define WDGM_START_SEC_CONST_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

[!IF "node:exists(WdgMGeneral/WdgMCallerIds) and (count(WdgMGeneral/WdgMCallerIds/WdgMCallerId/*) > 0) and $GetExpectedWdgMModeCalloutEnabled = 'false'"!][!//
/*------------------[Allowed Caller IDs]------------------------------------*/
CONST(uint16, WDGM_CONST) WdgM_EB_CallerIds[WDGM_EB_CALLERIDS_NUM] =
{
  [!LOOP "WdgMGeneral/WdgMCallerIds/WdgMCallerId/*"!][!//
  [!"node:value(.)"!]U,
  [!ENDLOOP!][!// WdgMCallerIds /*
};
[!ENDIF!][!//

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_CONST_16BIT
#else
#define WDGM_STOP_SEC_CONST_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

#define WDGM_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

/*------------------[trigger and watchdog configuration]--------------------*/

[!LOOP "node:order(WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
[!IF "count(WdgMTrigger/*) > 0"!][!//
/* trigger configuration for mode [!"name(.)"!] */
static CONST(WdgM_EB_TriggerCfgType,WDGM_CONST) WdgM_EB_TrigCfg_M[!"WdgMModeId"!][[!"num:i(count(WdgMTrigger/*))"!]] =
{
  [!LOOP "WdgMTrigger/*"!][!//
  { /* [!"@name"!] */
    [!"WdgMWatchdogMode"!], /* watchdog trigger mode */
    [!"WdgMTriggerConditionValue"!]U, /* TriggerCondition */
    [!"as:ref(as:ref(WdgMTriggerWatchdogRef)/WdgMWatchdogDeviceRef)/WdgIfDeviceIndex"!]U, /* watchdog device index */
[!IF "$WdgMTriggerWdgDriverMulticore"!]
[!IF "node:exists(as:ref(WdgMTriggerWatchdogRef)/WdgMMulticoreWdgEnable) and (node:value(as:ref(WdgMTriggerWatchdogRef)/WdgMMulticoreWdgEnable) = 'true')"!]
    TRUE, /* triggered from all cores */
[!ELSE!][!//
    FALSE, /* triggered from all cores */
[!ENDIF!][!//
[!IF "node:exists(as:ref(WdgMTriggerWatchdogRef)/WdgMMulticoreWdgCoreId)"!]
  [!VAR "WdgMCoreId" = "num:i(node:value(as:ref(WdgMTriggerWatchdogRef)/WdgMMulticoreWdgCoreId))"!]
  [!VAR "SupEntExistPerCore" = "false()"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = $WdgMCoreId"!]
      [!VAR "SupEntExistPerCore" = "true()"!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "$SupEntExistPerCore"!]
    [!"node:value(as:ref(WdgMTriggerWatchdogRef)/WdgMMulticoreWdgCoreId)"!]U /* triggered from a specific core */
  [!ELSE!][!//
      [!ERROR "The configured Core ID (WdgMMulticoreWdgCoreId) does not belong to any Supervised Entity."!]
  [!ENDIF!][!//
[!ELSE!][!//
    WDGM_EB_MASTER_INSTANCE /* triggered from a specific core - disabled default value */
[!ENDIF!][!//
[!ENDIF!][!//
  },
  [!ENDLOOP!][!// WdgM triggers /*
};
[!ELSE!][!//
/* no triggers configured for mode [!"name(.)"!] */
[!ENDIF!][!//

[!ENDLOOP!][!// WdgM modes /*

/*------------------[SE configuration]--------------------------------------*/

[!VAR "BaseIntGraphId" = "0"!][!//
[!VAR "DMId" = "0"!][!//
[!LOOP "WdgMGeneral/WdgMSupervisedEntity/*"!][!//
/*------------------Internal configuration data for SE: [!"@name"!] */

[!VAR "SEName" = "@name"!][!//
[!VAR "ExtSEId" = "num:i(WdgMSupervisedEntityId)"!][!//
[!VAR "IntSEId" = "@index"!][!//
[!LOOP "WdgMCheckpoint/*"!][!//
[!VAR "CPName" = "@name"!][!//
[!VAR "IntCPId" = "WdgMCheckpointId"!][!//
[!VAR "BaseExtGraphId" = "0"!][!//
[!LOOP "node:order(../../../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
[!VAR "IntModeId" = "WdgMModeId"!][!//
[!VAR "tempText"!][!ENDVAR!][!//
[!LOOP "WdgMAliveSupervision/*[(num:i(as:ref(WdgMAliveSupervisionCheckpointRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMAliveSupervisionCheckpointRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]"!][!//
/* alive supervision of CP [!"$CPName"!] in mode [!"$IntModeId"!] */
static CONST(WdgM_EB_CPAliveCfgType,WDGM_CONST) WdgM_EB_CPAliveCfg_[!"$IntSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!] =
{
  [!"num:i(WdgMExpectedAliveIndications)"!]U, /* ExpextedAliveIndication */
  [!"num:i(WdgMSupervisionReferenceCycle)"!]U, /* Amount of supervision reference cycles */
  [!"num:i(WdgMMaxMargin)"!]U, /* max margin */
  [!"num:i(WdgMMinMargin)"!]U /* min margin */
};

[!ENDLOOP!][!//
[!/*
Generate Configuration for external supervision graph
=====================================================
*/!][!//
[!/* Check if checkpoint is a destination node of some external transition
*/!][!//
[!VAR "NumConfiguredPredecessors" = "num:i(count(WdgMExternalLogicalSupervision/*/WdgMExternalTransition/*[(num:i(as:ref(WdgMExternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]))"!][!//
[!IF "$NumConfiguredPredecessors > 0"!][!//
[!VAR "ExtGraphIdOffset" = "num:i(WdgMExternalLogicalSupervision/*/WdgMExternalTransition/*[(num:i(as:ref(WdgMExternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)][1]/../../@index)"!][!//
/* predecessor points of CP [!"$CPName"!] in mode [!"$IntModeId"!] */
static CONST(WdgM_EB_CPType,WDGM_CONST) WdgM_EB_CPPred_[!"$ExtSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!][[!"$NumConfiguredPredecessors"!]] =
{
  [!LOOP "WdgMExternalLogicalSupervision/*/WdgMExternalTransition/*[(num:i(as:ref(WdgMExternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]"!][!//
  [!VAR "PredecessorSEID" = "num:i(as:ref(WdgMExternalTransitionSourceRef)/../../@index)"!][!//
  [!VAR "PredecessorCPID" = "num:i(as:ref(WdgMExternalTransitionSourceRef)/WdgMCheckpointId)"!][!//
  {
    [!"$PredecessorSEID"!]U, /* Internal SEId of predecessor 0 */
    [!"$PredecessorCPID"!]U /* CPId of predecessor 0 */
  },
  [!ENDLOOP!][!//
};
[!VAR "tempText"!][!"$tempText"!][!"num:i($ExtSEId)"!]-[!"num:i($IntCPId)"!]:[!"num:i($IntModeId)"!][!ENDVAR!][!//

/* External logical supervision of CP [!"$CPName"!] in mode [!"$IntModeId"!] */
static CONST(WdgM_EB_CPLogicalCfgType,WDGM_CONST) WdgM_EB_CPExtLogicalCfg_[!"$ExtSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!] =
{
  WdgM_EB_CPPred_[!"$ExtSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!], /* pointer to predecessor CPs */
  [!"num:i($BaseExtGraphId+$ExtGraphIdOffset)"!]U, /* graph id */
  [!CALL "GetSEIndexMapped", "SEIdCPIdModeId"="$tempText"!], /* checkpoint sequence */
  [!"$NumConfiguredPredecessors"!]U, /* number of predecessors */
  [!IF "count(WdgMExternalLogicalSupervision/*/WdgMExternalCheckpointFinalRef/*[(num:i(node:ref(.)/WdgMCheckpointId) = $IntCPId) and ((num:i(node:ref(.)/../../WdgMSupervisedEntityId)) = $ExtSEId)]) > 0"!]  TRUE[!ELSE!]  FALSE[!ENDIF!] /* isFinal */
};

[!ELSE!][!//
[!/* Check if the checkpoint is an initial node of some graph and not already treated before
*/!][!//
[!LOOP "WdgMExternalLogicalSupervision/*/WdgMExternalCheckpointInitialRef/*[(num:i(as:ref(.)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(.)/../../WdgMSupervisedEntityId) = $ExtSEId)]"!][!//
[!VAR "ExtGraphIdOffset" = "num:i(../../@index)"!][!//
[!VAR "tempText"!][!"$tempText"!][!"num:i($ExtSEId)"!]-[!"num:i($IntCPId)"!]:[!"num:i($IntModeId)"!][!ENDVAR!][!//
/* External logical supervision of CP [!"$CPName"!] in mode [!"$IntModeId"!] */
static CONST(WdgM_EB_CPLogicalCfgType,WDGM_CONST) WdgM_EB_CPExtLogicalCfg_[!"$ExtSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!] =
{
  NULL_PTR, /* initial node has no predecessor CPs */
  [!"num:i($BaseExtGraphId+$ExtGraphIdOffset)"!]U, /* graph id */
  [!CALL "GetSEIndexMapped", "SEIdCPIdModeId"="$tempText"!], /* checkpoint sequence */
  0U, /* number of predecessors */
  FALSE /* isFinal */
};

[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* continuously increment base graph id
*/!][!//
[!VAR "BaseExtGraphId" = "$BaseExtGraphId + num:i(count(WdgMExternalLogicalSupervision/*))"!][!//
[!ENDLOOP!][!/* WdgM modes
*/!][!//
[!/*
Generate Configuration for internal supervision graph
=====================================================
Check if internal supervision is configured at all for the CPs of actual SE
*/!][!//
[!VAR "IsInternalLogicalSupervisionConfigured" = "count(../../WdgMInternalTransition/*[((num:i(as:ref(WdgMInternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMInternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)) or ((num:i(as:ref(WdgMInternalTransitionSourceRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMInternalTransitionSourceRef)/../../WdgMSupervisedEntityId) = $ExtSEId))]) > 0"!][!//
[!IF "$IsInternalLogicalSupervisionConfigured"!][!//
[!VAR "NumConfiguredPredecessors" = "num:i(count(../../WdgMInternalTransition/*[(num:i(as:ref(WdgMInternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMInternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]))"!][!//
[!IF "$NumConfiguredPredecessors > 0"!][!//
/* predecessor points of CP [!"$CPName"!] */
static CONST(WdgM_EB_CPType,WDGM_CONST) WdgM_EB_CPPred_[!"$IntSEId"!]_[!"$IntCPId"!][[!"$NumConfiguredPredecessors"!]] =
{
  [!LOOP "../../WdgMInternalTransition/*[(num:i(as:ref(WdgMInternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMInternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]"!][!//
  [!VAR "PredecessorSEID" = "num:i(as:ref(WdgMInternalTransitionSourceRef)/../../@index)"!][!//
  [!VAR "PredecessorCPID" = "num:i(as:ref(WdgMInternalTransitionSourceRef)/WdgMCheckpointId)"!][!//
  {
    [!"$PredecessorSEID"!]U, /* Internal SEId of predecessor 0 */
    [!"$PredecessorCPID"!]U /* CPId of predecessor 0 */
  },
  [!ENDLOOP!][!//
};

/* Internal logical supervision of [!"$CPName"!] */
static CONST(WdgM_EB_CPLogicalCfgType,WDGM_CONST) WdgM_EB_CPIntLogicalCfg_[!"$IntSEId"!]_[!"$IntCPId"!] =
{
  WdgM_EB_CPPred_[!"$IntSEId"!]_[!"$IntCPId"!], /* pointer to predecessor CPs */
  [!"num:i($BaseIntGraphId)"!]U, /* graph id */
  0U, /* checkpoint sequence for internal logical supervision is not used */
  [!"$NumConfiguredPredecessors"!]U, /* number of predecessors */
  [!IF "count(../../WdgMInternallCheckpointFinalRef/*[(num:i(node:ref(.)/WdgMCheckpointId) = $IntCPId) and ((num:i(node:ref(.)/../../WdgMSupervisedEntityId)) = $ExtSEId)]) > 0"!]  TRUE[!ELSE!]
  FALSE[!ENDIF!] /* isFinal */
};

[!ELSEIF "node:refvalid(../../WdgMInternalCheckpointInitialRef) and (num:i(node:ref(../../WdgMInternalCheckpointInitialRef)/WdgMCheckpointId) = $IntCPId) and (num:i(node:ref(../../WdgMInternalCheckpointInitialRef)/../../WdgMSupervisedEntityId) = $ExtSEId)"!][!//
/* predecessor points of CP [!"$CPName"!] */
static CONST(WdgM_EB_CPType,WDGM_CONST) WdgM_EB_CPPred_[!"$IntSEId"!]_[!"$IntCPId"!][1] =
{
  {
    WDGM_EB_DUMMY_SEID, /* SEId of predecessor 0 */
    WDGM_EB_DUMMY_CPID /* CPId of predecessor 0 */
  }
};

/* Internal logical supervision of [!"$CPName"!] */
static CONST(WdgM_EB_CPLogicalCfgType,WDGM_CONST) WdgM_EB_CPIntLogicalCfg_[!"$IntSEId"!]_[!"$IntCPId"!] =
{
  WdgM_EB_CPPred_[!"$IntSEId"!]_[!"$IntCPId"!], /* pointer to predecessor CPs */
  [!"num:i($BaseIntGraphId)"!]U, /* graph id */
  0U, /* checkpoint sequence for internal logical supervision is not used */
  0U, /* number of predecessors */
  FALSE /* isFinal */
};

[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!// Checkpoints
[!/*
Generate Configuration for deadline supervision
===============================================
*/!][!//
[!LOOP "node:order(../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
[!VAR "IntModeId" = "WdgMModeId"!][!//
[!VAR "ListOfGeneratedCPIds" = "''"!][!//
[!FOR "MaxSimpleSortLoop" = "0" TO "count(../../../../WdgMGeneral/WdgMSupervisedEntity/*[WdgMSupervisedEntityId = $ExtSEId]/WdgMCheckpoint/*)"!]
[!VAR "IsContinueSimpleSortLoop" = "'false'"!][!//
[!LOOP "node:order(../../../../WdgMGeneral/WdgMSupervisedEntity/*[WdgMSupervisedEntityId = $ExtSEId]/WdgMCheckpoint/*, 'WdgMCheckpointId')"!][!//
[!VAR "CPName" = "@name"!][!//
[!VAR "IntCPId" = "WdgMCheckpointId"!][!//
[!SELECT "../../../../../WdgMConfigSet/*[1]/WdgMMode/*[WdgMModeId = $IntModeId]"!][!//
[!IF "not(text:contains( text:split($ListOfGeneratedCPIds), $IntCPId))"!][!//
[!VAR "IsDeadlineSupervisionStartConfiguration" = "count(WdgMDeadlineSupervision/*[((num:i(as:ref(WdgMDeadlineStartRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStartRef)/../../WdgMSupervisedEntityId) = $ExtSEId))]) = 1"!][!//
[!IF "$IsDeadlineSupervisionStartConfiguration"!][!//
  [!VAR "DeadlineSupervisionStartConfigurationDMMax" = "WdgMDeadlineSupervision/*[((num:i(as:ref(WdgMDeadlineStartRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStartRef)/../../WdgMSupervisedEntityId) = $ExtSEId))][1]/WdgMDeadlineMax"!][!//
  [!VAR "DeadlineSupervisionStartConfigurationDMMin" = "WdgMDeadlineSupervision/*[((num:i(as:ref(WdgMDeadlineStartRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStartRef)/../../WdgMSupervisedEntityId) = $ExtSEId))][1]/WdgMDeadlineMin"!][!//
  [!VAR "DeadlineSupervisionStartConfigurationDMStopRef" = "WdgMDeadlineSupervision/*[((num:i(as:ref(WdgMDeadlineStartRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStartRef)/../../WdgMSupervisedEntityId) = $ExtSEId))][1]/WdgMDeadlineStopRef"!][!//
  [!VAR "IsPrevDeadlineSupervisionConfiguration" = "count(WdgMDeadlineSupervision/*[((num:i(as:ref(WdgMDeadlineStopRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStopRef)/../../WdgMSupervisedEntityId) = $ExtSEId))]) > 0"!][!//
  [!VAR "DoGenerateCPId" = "'true'"!][!//
  [!IF "$IsPrevDeadlineSupervisionConfiguration"!][!//
    [!VAR "PrevDeadlineSupervisionConfiguration" = "WdgMDeadlineSupervision/*[((num:i(as:ref(WdgMDeadlineStopRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStopRef)/../../WdgMSupervisedEntityId) = $ExtSEId))][1]/WdgMDeadlineStartRef"!][!//
    [!VAR "PrevDeadlineSupervisionIntCPId" = "num:i(as:ref($PrevDeadlineSupervisionConfiguration)/WdgMCheckpointId)"!][!//
    [!VAR "PrevDeadlineSupervisionIntSEId" = "num:i(as:ref($PrevDeadlineSupervisionConfiguration)/../../@index)"!][!//
    [!VAR "IsPrevDeadlineSupervisionConfigurationNotGenerated" = "not(text:contains( text:split($ListOfGeneratedCPIds), $PrevDeadlineSupervisionIntCPId))"!][!//
    [!IF "$IsPrevDeadlineSupervisionConfigurationNotGenerated"!][!//
      [!VAR "IsContinueSimpleSortLoop" = "'true'"!][!//
      [!VAR "DoGenerateCPId" = "'false'"!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "$DoGenerateCPId = 'true'"!][!//
    [!VAR "ListOfGeneratedCPIds" = "concat($ListOfGeneratedCPIds, ' ', $IntCPId)"!][!//
/* deadline configuration for start CP [!"$CPName"!] in mode [!"$IntModeId"!] */
static CONST(WdgM_EB_CPDeadlineCfgType,WDGM_CONST) WdgM_EB_CPDeadlineCfg_[!"$IntSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!] =
{
  [!"num:i(round(num:f(num:div($DeadlineSupervisionStartConfigurationDMMax, $TimeGranularity))))"!]U, /* maximum Deadline in granularity of [!"num:i(num:mul($TimeGranularity, 1000000))"!]us */
  [!"num:i(round(num:f(num:div($DeadlineSupervisionStartConfigurationDMMin, $TimeGranularity))))"!]U, /* minimum Deadline in granularity of [!"num:i(num:mul($TimeGranularity, 1000000))"!]us */
  [!"num:i(num:div(num:i(num:i(round(num:f(num:div($DeadlineSupervisionStartConfigurationDMMax, $TimeGranularity)))) + $MainFunctionCycleTime - 1), $MainFunctionCycleTime))"!]U, /* maximum allowed main function calls until deadline violation */
  [!IF "$IsPrevDeadlineSupervisionConfiguration"!][!//
  &(WdgM_EB_CPDeadlineCfg_[!"$PrevDeadlineSupervisionIntSEId"!]_[!"$PrevDeadlineSupervisionIntCPId"!]_[!"$IntModeId"!]),
  [!ELSE!][!//
  NULL_PTR,
  [!ENDIF!][!//
  [!"num:i($DMId)"!]U, /* internal Deadline Monitoring ID for runtime data */
  [!"num:i($IntCPId)"!]U, /* Internal Checkpoint id of start checkpoint */
  [!"num:i(as:ref($DeadlineSupervisionStartConfigurationDMStopRef)/WdgMCheckpointId)"!]U, /* Internal Checkpoint id of stop checkpoint */
};
[!VAR "DMId" = "num:i($DMId + 1)"!][!//

  [!ENDIF!][!// DoGenerateCPId
[!ENDIF!][!// $IsDeadlineSupervisionStartConfiguration
[!ENDIF!][!// not(text:contains( text:split($ListOfGeneratedCPIds), $IntCPId))
[!ENDSELECT!][!//
[!ENDLOOP!][!// Checkpoints
[!IF "$IsContinueSimpleSortLoop = 'false'"!][!//
  [!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!// MaxSimpleSortLoop: Ensures that all Checkpoints are generated in worst-case
[!ENDLOOP!][!// WdgMModes

/* checkpoint configuration of SE [!"$SEName"!] */
static CONST(WdgM_EB_CPCfgType,WDGM_CONST) WdgM_EB_CPCfg_[!"$SEName"!][[!"num:i(count(WdgMCheckpoint/*))"!]] =
{
[!LOOP "WdgMCheckpoint/*"!][!//
[!VAR "IntCPId" = "WdgMCheckpointId"!][!//
[!VAR "IntSupervExists" = "WdgMCheckpointId"!][!//
[!VAR "IsInternalLogicalSupervisionConfigured" = "count(../../WdgMInternalTransition/*[((num:i(as:ref(WdgMInternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMInternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)) or ((num:i(as:ref(WdgMInternalTransitionSourceRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMInternalTransitionSourceRef)/../../WdgMSupervisedEntityId) = $ExtSEId))]) > 0"!][!//
  {
    /* CP [!"@name"!]*/
    {
      /* alive supervision per WdgM mode */
      [!LOOP "node:order(../../../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
      [!VAR "IntModeId" = "WdgMModeId"!][!//
      [!IF "count(WdgMAliveSupervision/*[(num:i(as:ref(WdgMAliveSupervisionCheckpointRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMAliveSupervisionCheckpointRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]) = 1"!][!//
      &(WdgM_EB_CPAliveCfg_[!"$IntSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!]),
      [!ELSE!][!//
      NULL_PTR,
      [!ENDIF!][!//
      [!ENDLOOP!][!// WdgMMode
    },
#if (WDGM_EB_DEADLINE_SUPERVISION_ENABLED == STD_ON)
    /* deadline monitoring per WdgM mode */
    {
      [!LOOP "node:order(../../../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
        [!VAR "IntModeId" = "WdgMModeId"!][!//
        [!VAR "IsDeadlineSupervisionStartConfiguration" = "count(WdgMDeadlineSupervision/*[(num:i(as:ref(WdgMDeadlineStartRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStartRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]) > 0"!][!//
        [!VAR "IsDeadlineSupervisionStopConfiguration" = "count(WdgMDeadlineSupervision/*[(num:i(as:ref(WdgMDeadlineStopRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStopRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]) > 0"!][!//
        [!IF "($IsDeadlineSupervisionStartConfiguration = 'true') or ($IsDeadlineSupervisionStopConfiguration = 'true')"!][!//
          [!IF "$IsDeadlineSupervisionStartConfiguration"!]
            [!VAR "IntStartCPId" = "$IntCPId"!][!//
            [!VAR "IntStartSEId" = "$IntSEId"!][!//
          [!ELSE!][!//
            [!VAR "DeadlineSupervisionConfiguration" = "WdgMDeadlineSupervision/*[(num:i(as:ref(WdgMDeadlineStopRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMDeadlineStopRef)/../../WdgMSupervisedEntityId) = $ExtSEId)]/WdgMDeadlineStartRef"!][!//
            [!VAR "IntStartCPId" = "num:i(as:ref($DeadlineSupervisionConfiguration)/WdgMCheckpointId)"!][!//
            [!VAR "IntStartSEId" = "num:i(as:ref($DeadlineSupervisionConfiguration)/../../@index)"!][!//
          [!ENDIF!][!//
      &(WdgM_EB_CPDeadlineCfg_[!"$IntStartSEId"!]_[!"$IntStartCPId"!]_[!"$IntModeId"!]),
        [!ELSE!][!//
      NULL_PTR,
        [!ENDIF!][!//
      [!ENDLOOP!][!// WdgMMode
    },
#endif
#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
    /* internal logical supervision per WdgM mode */
    {
      [!LOOP "node:order(../../../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
        [!VAR "IntModeId" = "WdgMModeId"!][!//
        [!VAR "IsExternalLogicalSupervisionConfigured" = "count(WdgMExternalLogicalSupervision/*/WdgMExternalTransition/*[((num:i(as:ref(WdgMExternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)) or ((num:i(as:ref(WdgMExternalTransitionSourceRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionSourceRef)/../../WdgMSupervisedEntityId) = $ExtSEId))]) > 0"!][!//
        [!VAR "SupervisedEntityIsReferencedInMode" = "count(WdgMLocalStatusParams/*[(num:i(as:ref(WdgMLocalStatusSupervisedEntityRef)/WdgMSupervisedEntityId)) = $ExtSEId]) > 0"!][!//
        [!IF "($IsInternalLogicalSupervisionConfigured = 'true') and ($SupervisedEntityIsReferencedInMode = 'true')"!][!//
      &(WdgM_EB_CPIntLogicalCfg_[!"$IntSEId"!]_[!"$IntCPId"!]),
        [!ELSE!][!//
      NULL_PTR,
        [!ENDIF!][!//
      [!ENDLOOP!][!// WdgMMode
    },
    /* external logical supervision per WdgM mode */
    {
      [!LOOP "node:order(../../../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!][!//
        [!VAR "IntModeId" = "WdgMModeId"!][!//
        [!VAR "IsExternalLogicalSupervisionConfigured" = "count(WdgMExternalLogicalSupervision/*/WdgMExternalTransition/*[((num:i(as:ref(WdgMExternalTransitionDestRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionDestRef)/../../WdgMSupervisedEntityId) = $ExtSEId)) or ((num:i(as:ref(WdgMExternalTransitionSourceRef)/WdgMCheckpointId) = $IntCPId) and (num:i(as:ref(WdgMExternalTransitionSourceRef)/../../WdgMSupervisedEntityId) = $ExtSEId))]) > 0"!][!//
        [!VAR "SupervisedEntityIsReferencedInMode" = "count(WdgMLocalStatusParams/*[(num:i(as:ref(WdgMLocalStatusSupervisedEntityRef)/WdgMSupervisedEntityId)) = $ExtSEId]) > 0"!][!//
        [!IF "$IsExternalLogicalSupervisionConfigured"!][!//
      &(WdgM_EB_CPExtLogicalCfg_[!"$ExtSEId"!]_[!"$IntCPId"!]_[!"$IntModeId"!]),
        [!ELSE!][!//
      NULL_PTR,
        [!ENDIF!][!//
      [!ENDLOOP!][!// WdgMMode
    },
#endif
  },
[!ENDLOOP!][!// Checkpoints
};

[!/* Supervised Entity contains an internal graph => increment counter for graph id */!][!//
[!IF "count(WdgMInternalTransition/*) > 0"!][!//
[!VAR "BaseIntGraphId" = "num:i($BaseIntGraphId + 1)"!][!//
[!ENDIF!][!//
[!//
[!ENDLOOP!][!// Supervised Entities
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
    WdgMConf_WdgMMode_[!"name(as:ref(WdgMConfigSet/*[1]/WdgMInitialMode))"!];

[!IF "$SleepModeEnabled"!][!//
CONST(WdgM_ModeType,WDGM_CONST) WdgM_EB_DeInitModeId =
    WdgMConf_WdgMMode_[!"name(as:ref(WdgMConfigSet/*[1]/WdgMSleepMode))"!];

[!ENDIF!][!//

CONST(WdgM_ModeType,WDGM_CONST) WdgM_EB_ModeCfgSize = WDGM_EB_MODE_NUM;

CONST(WdgM_EB_SEIdType, WDGM_CONST) WdgM_EB_SEIntSEId[WDGM_EB_SE_NUM] =
{
  [!LOOP "node:order(WdgMGeneral/WdgMSupervisedEntity/*, 'WdgMSupervisedEntityId')"!][!//
  [!VAR "IntSEId" = "@index"!][!//
  [!VAR "SEName" = "@name"!][!//
  [!"$IntSEId"!]U, /* Internal Id of [!"$SEName"!] */
  [!ENDLOOP!][!//
};

[!IF "$WdgMMulticoreEnabled = 'true'"!]
[!VAR "SECoreIdx"!][!ENDVAR!][!//
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!][!/*
*/!][!VAR "SupEntPerCore" = "0"!][!/*
*/!][!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!/*
   */!][!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!/*
       */!][!VAR "SECoreIdx"!][!"$SECoreIdx"!][!"num:i(@index)"!]:[!"num:i($index_i)"!]:[!"num:i($SupEntPerCore)"!];[!ENDVAR!][!/*
       */!][!VAR "SupEntPerCore" = "$SupEntPerCore + 1"!][!/*
   */!][!ENDIF!][!/*
*/!][!ENDLOOP!][!//
[!ENDFOR!][!//

CONST(WdgM_EB_SEIdType, WDGM_CONST) WdgM_EB_SELocalCoreIdx[WDGM_EB_SE_NUM] =
{
[!LOOP "node:order(WdgMGeneral/WdgMSupervisedEntity/*, '@index')"!][!//
  [!VAR "IntSEId" = "@index"!][!//
  [!VAR "SEName" = "@name"!][!//
  [!LOOP "text:split($SECoreIdx, ';')"!]
    [!VAR "SEIndex" = "text:split( ., ':' )[1]"!]
    [!VAR "CoreId" = "text:split( ., ':' )[2]"!]
    [!VAR "CoreIdx" = "text:split( ., ':' )[3]"!]
     [!IF "$SEIndex = $IntSEId"!]
  [!"$CoreIdx"!]U, /* Maps internal Id of [!"$SEName"!] to Idx in Core [!"$CoreId"!] status array*/
     [!ENDIF!][!//
  [!ENDLOOP!][!//
[!ENDLOOP!][!//

};
[!ENDIF!][!//

[!IF "$WdgMPartitionResetEnabled = 'true'"!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]

  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]

[!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!]

/** \brief
 ** Identifier of Os application of each WdgM SE with Os application
 ** mapping to Core [!"num:i($index_i)"!] .
 **/
STATIC CONST(ApplicationType, WDGM_CONST) WdgM_EB_Core[!"num:i($index_i)"!]PartitionId[[!"num:i($WdgMNumOfPartitionsPerCore)"!]U] = 
{
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
  [!"name(as:ref(./WdgMOsApplicationRef))"!], /* Os application identifier */
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
  [!"name(as:ref(./WdgMOsApplicationRef))"!], /* Os application identifier */
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
};

[!ENDIF!][!//

[!ENDFOR!][!//
[!ENDIF!][!//


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
  [!LOOP "node:order(WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!]
  { /* mode [!"name(.)"!] (id [!"WdgMModeId"!]) */
    [!CALL "getModeSpecificLCM", "modeRef" = "as:path(.)"!]U, /* least common multiple of all reference cycle values */
    [!IF "count(WdgMTrigger/*) > 0"!]
    WdgM_EB_TrigCfg_M[!"WdgMModeId"!], /* trigger configuration */
    [!ELSE!]
    NULL_PTR, /* no triggers in this mode */
    [!ENDIF!]
    [!"WdgMExpiredSupervisionCycleTol"!]U, /* number of supervision cycles in stats EXPIRED */
    [!"num:i(count(WdgMTrigger/*))"!]U /* number of watchdogs (triggers) */
  },
  [!ENDLOOP!][!// WdgMMode/*
};

/* -----------------[SE configuration]--------------------- */

CONST(WdgM_EB_SECfgType,WDGM_CONST) WdgM_EB_SECfg[WDGM_EB_SE_NUM] =
{
  [!LOOP "WdgMGeneral/WdgMSupervisedEntity/*"!]
  [!VAR "ExtSEId" = "num:i(WdgMSupervisedEntityId)"!]
  { /* SE [!"@name"!] (internal SEId: [!"@index"!]) */
    WdgM_EB_CPCfg_[!"@name"!], /* pointer to the array of checkpoints */
    WdgM_EB_CPData_[!"@name"!], /* pointer to the run-time data of the CPs */
    WdgMConf_WdgMSupervisedEntity_[!"@name"!], /* external SEId */
    [!"num:i(count(WdgMCheckpoint/*))"!]U, /* number of CPs in this SE */
    [!WS!][!WS!][!WS!][!WS!][!IF "WdgMErrorRecoveryEnabled = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* Support for Error Recovery */
    [!IF "$WdgMPartitionResetEnabled = 'true'"!]
    [!IF "node:exists(WdgMOsApplicationRef)"!]
    TRUE, /* Support for mapping the SE to an Os partition. */
    [!"name(as:ref(WdgMOsApplicationRef))"!], /* identifier of referenced Os Application */
    [!IF "$WdgMMulticoreEnabled"!]
    WdgM_EB_Core[!"WdgMSupervisedEntityCoreId"!]_PartitionStatus, /* status of WdgM partition */
    [!ELSE!]
    WdgM_EB_Core0_PartitionStatus, /* status of WdgM partition */
    [!ENDIF!]
    [!ELSE!]
    FALSE, /* Support for mapping the SE to an Os partition. */
    INVALID_OSAPPLICATION, /* identifier of referenced Os Application */
    NULL_PTR, /* status of WdgM partition (no WdgMOsApplicationRef exists for this SE entry) */
    [!ENDIF!]
    [!ENDIF!][!//
    /* number of tolerated reference cycles which are allowed to fail in each WdgM mode*/
    {
      [!LOOP "node:order(../../../WdgMConfigSet/*[1]/WdgMMode/*, 'WdgMModeId')"!]
      [!IF "count(WdgMLocalStatusParams/*[as:ref(WdgMLocalStatusSupervisedEntityRef)/WdgMSupervisedEntityId = $ExtSEId]) > 0"!]
      [!"WdgMLocalStatusParams/*[as:ref(WdgMLocalStatusSupervisedEntityRef)/WdgMSupervisedEntityId = $ExtSEId]/WdgMFailedAliveSupervisionRefCycleTol"!]U, /* WdgM mode [!"@name"!] */
      [!ELSE!]
      WDGM_EB_DUMMY_FAILEDREFCYCLETOL, /* WdgM mode [!"@name"!] */
      [!ENDIF!]
      [!ENDLOOP!][!// /*
    [!IF "$WdgMMulticoreEnabled"!]
    },
    [!"WdgMSupervisedEntityCoreId"!]U, /* the core id of a SE */
  },
    [!ELSE!]
    }
  },
    [!ENDIF!]
  [!ENDLOOP!][!//
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

[!IF "$WdgMMulticoreEnabled = 'false'"!]
/* !LINKSTO WDGM.ASR40.WDGM200,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable1,3 */
/** \brief defines the local statuses of all SE */
VAR(WdgM_LocalStatusType, WDGM_VAR) WdgM_EB_SELocalStatus[WDGM_EB_SE_NUM];
[!ENDIF!][!//

/** \brief has the expired SEId been set? */
VAR(boolean, WDGM_VAR) WdgM_EB_IsExpiredSEIdSet;

#if (WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE_ENABLED == STD_OFF)
VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_ExpectedWdgMModeId;
#endif

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

[!IF "$WdgMMulticoreEnabled = 'false'"!]
[!IF "$WdgMGetAllExpiredSEIDs = 'true'"!]
#define WDGM_START_SEC_VAR_POWER_ON_INIT_ASIL_D_8
#include <WdgM_MemMap.h>

/** \brief List of expired supervised entities */
static VAR(uint8, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEIDs[WDGM_EB_SE_NUM];

/** \brief The number of expired supervised entities */
static VAR(uint8, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEIDsCounter;

#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_ASIL_D_8
#include <WdgM_MemMap.h>
[!ENDIF!]
[!ENDIF!][!//

#define WDGM_START_SEC_VAR_POWER_ON_INIT_ASIL_D_16
#include <WdgM_MemMap.h>

/** \brief the Supervised Entity Id which first expired */
VAR(WdgM_EB_ExpiredSEIDType, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEID = 0U;

#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_ASIL_D_16
#include <WdgM_MemMap.h>

[!IF "$WdgMMulticoreEnabled"!]

[!IF "$WdgMGetAllExpiredSEIDs = 'true'"!]
[!VAR "SupEntExistPerCore" = "false()"!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_POWER_ON_INIT_ASIL_D_8
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#define WDGM_START_SEC_VAR_POWER_ON_INIT_ASIL_D_8
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]

/** \brief List of expired supervised entities on core [!"num:i($index_i)"!] */
static VAR(uint8, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEIDs_Core[!"num:i($index_i)"!][WDGM_EB_SE_NUM_CORE[!"$index_i"!]] = {
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
    0xFFU,
    [!ENDIF!]
  [!ENDLOOP!]
};

/** \brief The number of expired supervised entities on core [!"num:i($index_i)"!] */
static VAR(uint8, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEIDsCounter_Core[!"num:i($index_i)"!];

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_POWER_ON_INIT_ASIL_D_8
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_ASIL_D_8
#include <WdgM_MemMap.h>

[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]
    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]

[!ENDIF!]

[!VAR "SupEntExistPerCore" = "false()"!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]

/** \brief through this variable, the WdgM master instance announces the WdgM satellite instances that the mode switch has been performed.
* The WdgM satellite instances read the value of this variable to change and update their mode. */
VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_CoreSwitchMode_Core[!"$index_i"!];

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]
   [!ENDIF!][!/* IF $SupEntExistPerCore */!]
   [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]

[!VAR "SupEntExistPerCore" = "false()"!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_8BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_8BIT
#else
#define WDGM_START_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]

/* !LINKSTO WDGM.EB.MulticoreInit.4,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable15,2 */
/** \brief WdgM/WdgM core instance initialization status */
static VAR(WdgM_EB_InitStatusType, WDGM_VAR) WdgM_EB_InitStatus_Core[!"$index_i"!] = WDGM_EB_INIT_STATUS_DEINIT;

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_8BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>

[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_8BIT
#else
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]
    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]

[!VAR "SupEntExistPerCore" = "false()"!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable1,3 */
/* !LINKSTO WDGM.EB.MulticoreLocalStatus2,1 */
/** \brief defines the local statuses of all SE from core [!"num:i($index_i)"!] */
static VAR(WdgM_LocalStatusType, WDGM_VAR) WdgM_EB_SELocalStatus_Core[!"num:i($index_i)"!][WDGM_EB_SE_NUM_CORE[!"$index_i"!]];

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>

[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]
    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]

[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]

/** \brief Internal RAM data holding a copy of the alive counter values for each checkpoint */
static VAR(WdgM_EB_CPInternalDataType, WDGM_VAR) WdgM_EB_IntRAMData_Core[!"$index_i"!][WDGM_EB_CHECKPOINTS_NUM_CORE[!"$index_i"!]];

/* !LINKSTO WDGM.ASR40.WDGM085.3,1, WDGM.EB.DesignDecision.InternalVariable10,2 */
/** \brief failed reference cycle counter for the SE  */
static VAR(uint16, WDGM_VAR) WdgM_EB_FailedAliveSupervisionRefCycleCnt_Core[!"$index_i"!][WDGM_EB_SE_NUM_CORE[!"$index_i"!]];

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>

[!ELSE!][!//
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]
    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#define WDGM_1_CORE_[!"num:i($index_i)"!]_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>
[!ELSE!][!//
#define WDGM_START_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_MemMap.h>
[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]

  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]

/** \brief The WdgM core specific context data.
 ** This variable holds the core-specific run time data of the WdgM. */
/* Deviation MISRAC2012-2 */
static VAR(WdgM_EB_CoreContextType, WDGM_VAR) WdgM_EB_Core[!"num:i($index_i)"!]_Context =
{
  WdgM_EB_SELocalStatus_Core[!"num:i($index_i)"!],
[!IF "$WdgMGetAllExpiredSEIDs = 'true'"!]
  WdgM_EB_ExpiredSEIDs_Core[!"num:i($index_i)"!],
  WDGM_EB_SE_NUM_CORE[!"num:i($index_i)"!],
  &WdgM_EB_ExpiredSEIDsCounter_Core[!"num:i($index_i)"!],
[!ENDIF!]
  WdgM_EB_FailedAliveSupervisionRefCycleCnt_Core[!"num:i($index_i)"!],
  WdgM_EB_IntRAMData_Core[!"num:i($index_i)"!],
  &WdgM_EB_InitStatus_Core[!"num:i($index_i)"!],
  &WdgM_EB_CoreSwitchMode_Core[!"$index_i"!],
  0U,
  0U,
  FALSE,
#if (WDGM_EB_CHECK_MAINFUNCTION_TIMING == STD_ON)
  0U,
#endif
  [!"num:i($index_i)"!]U,
[!IF "$WdgMPartitionResetEnabled = 'true'"!][!//
  [!WS!][!WS!][!"num:i($WdgMNumOfPartitionsPerCore)"!]U,
[!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!][!//
  WdgM_EB_Core[!"num:i($index_i)"!]PartitionSupervisionCycleCnt
[!ELSE!][!//
  NULL_PTR
[!ENDIF!][!//
[!ENDIF!][!//
};

[!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
#define WDGM_1_CORE_[!"num:i($index_i)"!]_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_1_CORE_[!"num:i($index_i)"!]_MemMap.h>

[!ELSE!][!//
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_LOCAL_UNSPECIFIED
#include <WdgM_MemMap.h>

[!ENDIF!][!/* IF "$index_i != $WDGM_MASTER_CORE_ID" */!]
    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]

#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

/* Deviation MISRAC2012-1 */
FUNC_P2VAR(WdgM_EB_CoreContextType, WDGM_APPL_DATA, WDGM_CODE) WdgM_GetCoreInstance(void)
{
  P2VAR(WdgM_EB_CoreContextType, AUTOMATIC, WDGM_APPL_DATA) inst = NULL_PTR;

  const WdgM_EB_CoreIdType coreID = WDGM_EB_GET_CORE_ID();

  switch(coreID)
  {
    [!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
      [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
        [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
          [!VAR "SupEntExistPerCore" = "true()"!]
        [!ENDIF!]
      [!ENDLOOP!]
     [!IF "$SupEntExistPerCore"!]
    case [!"num:i($index_i)"!]:
    {
      inst = &WdgM_EB_Core[!"num:i($index_i)"!]_Context;
      break;
    }
     [!ENDIF!][!/* IF $SupEntExistPerCore */!]
     [!VAR "SupEntExistPerCore" = "false()"!]
    [!ENDFOR!]
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
  [!VAR "NextSupEntExist" = "false()"!]
  [!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
      [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
        [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
          [!VAR "SupEntExistPerCore" = "true()"!]
        [!ENDIF!]
        [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i + 1)"!][!//
          [!VAR "NextSupEntExist" = "true()"!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$SupEntExistPerCore"!]
          (WDGM_EB_INIT_STATUS_DEINIT == WdgM_EB_InitStatus_Core[!"num:i($index_i)"!])
          [!IF "$NextSupEntExist"!]
            ||
          [!ENDIF!]
      [!ENDIF!]
      [!VAR "SupEntExistPerCore" = "false()"!]
      [!VAR "NextSupEntExist" = "false()"!]
  [!ENDFOR!]
  )
  {
    GlobalInitStatus = WDGM_EB_INIT_STATUS_DEINIT;
  }

  return GlobalInitStatus;
}

/* Deviation MISRAC2012-1 */
FUNC(WdgM_EB_InitStatusType, WDGM_CODE) WdgM_EB_GetMasterInitStatus(void)
{
  return WdgM_EB_InitStatus_Core[!"$WDGM_MASTER_CORE_ID"!];
}

[!VAR "SECoreIdx"!][!ENDVAR!][!//
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!][!/*
*/!][!VAR "SupEntPerCore" = "0"!][!/*
*/!][!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!/*
   */!][!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!/*
       */!][!VAR "SECoreIdx"!][!"$SECoreIdx"!][!"num:i(@index)"!]:[!"num:i($index_i)"!][[!"num:i($SupEntPerCore)"!]];[!ENDVAR!][!/*
       */!][!VAR "SupEntPerCore" = "$SupEntPerCore + 1"!][!/*
   */!][!ENDIF!][!/*
*/!][!ENDLOOP!][!//
[!ENDFOR!][!//

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
[!LOOP "text:split($SECoreIdx, ';')"!]
 [!VAR "Index" = "text:split( ., ':' )[1]"!]
 [!VAR "CoreIdx" = "text:split( ., ':' )[2]"!]
    case [!"$Index"!]: LocalStatus = WdgM_EB_SELocalStatus_Core[!"$CoreIdx"!];
      break;
[!ENDLOOP!]
     /* CHECK: NOPARSE */
    default: WDGM_UNREACHABLE_CODE_ASSERT(ApiId);
      break;
    /* CHECK: PARSE*/
  }

  return LocalStatus;
}

[!IF "$WdgMGetAllExpiredSEIDs = 'true'"!]
/* Deviation MISRAC2012-1 */
FUNC(void, WDGM_CODE) WdgM_EB_GetAllExpiredSEIDsHelper
(
  P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) Counter,
  P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) ExpiredSEIDs
)
{
  uint8 LocalIndex;
  uint8 LocalStoreIndex = 0U;

  /* !LINKSTO WDGM.EB.GetAllExpiredSEID.CoreSpecific.Read, 1 */
  [!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]
  for (LocalIndex = 0U; LocalIndex < WdgM_EB_ExpiredSEIDsCounter_Core[!"num:i($index_i)"!]; LocalIndex++)
  {
    ExpiredSEIDs[LocalStoreIndex] = WdgM_EB_ExpiredSEIDs_Core[!"num:i($index_i)"!][LocalIndex];
    LocalStoreIndex++;
  }
    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
  [!ENDFOR!]

  /* Return the number of expired supervised entities (if any) */
  *Counter = LocalStoreIndex;
}

FUNC(void, WDGM_CODE) WdgM_EB_ResetAllExpiredSEIDs(void)
{
  uint8 LocalIndex;

  [!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SupEntExistPerCore" = "true()"!]
      [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$SupEntExistPerCore"!]
  for (LocalIndex = 0U; LocalIndex < WdgM_EB_ExpiredSEIDsCounter_Core[!"num:i($index_i)"!]; LocalIndex++)
  {
    WdgM_EB_ExpiredSEIDs_Core[!"num:i($index_i)"!][LocalIndex] = 0U;
  }
  WdgM_EB_ExpiredSEIDsCounter_Core[!"num:i($index_i)"!] = 0U;

    [!ENDIF!][!/* IF $SupEntExistPerCore */!]
    [!VAR "SupEntExistPerCore" = "false()"!]
  [!ENDFOR!]
}
[!ENDIF!]

/* Deviation MISRAC2012-1 */
FUNC(WdgM_ModeType, WDGM_CODE) WdgM_EB_GetCoreSwitchMode(WdgM_EB_CoreIdType CoreId)
{
  WdgM_ModeType LocalMode = 0xFF;

  switch(CoreId)
  {
[!VAR "SupEntExistPerCore" = "false()"!]
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
    [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
      [!VAR "SupEntExistPerCore" = "true()"!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "$SupEntExistPerCore"!]
    case [!"$index_i"!]: LocalMode = WdgM_EB_CoreSwitchMode_Core[!"$index_i"!];
      break;
  [!ENDIF!][!/* IF $SupEntExistPerCore */!]
  [!VAR "SupEntExistPerCore" = "false()"!]
[!ENDFOR!]
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

[!VAR "SlaveWdgMSE" = "false()"!][!//
[!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!][!//
  [!IF "$index_i != $WDGM_MASTER_CORE_ID"!][!//
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
        [!VAR "SlaveWdgMSE" = "true()"!][!//
      [!ENDIF!][!//
      [!ENDLOOP!][!//
  [!ENDIF!][!//
[!ENDFOR!][!//

[!IF "$SlaveWdgMSE"!]
  if(
  [!VAR "NextSupEntExist" = "false()"!]
  [!FOR "index_i" = "0" TO "num:i($WdgMNumberOfCores)-1"!]
    [!IF "$index_i != $WDGM_MASTER_CORE_ID"!]
      [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
        [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!][!//
          [!VAR "SupEntExistPerCore" = "true()"!]
        [!ENDIF!]
        [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i + 1)"!][!//
          [!VAR "NextSupEntExist" = "true()"!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$SupEntExistPerCore"!]
    (WdgM_EB_CoreSwitchMode_Core[!"$WDGM_MASTER_CORE_ID"!] != WdgM_EB_CoreSwitchMode_Core[!"num:i($index_i)"!])
        [!IF "$NextSupEntExist"!]
    ||
        [!ENDIF!]
      [!ENDIF!]
    [!VAR "SupEntExistPerCore" = "false()"!]
    [!VAR "NextSupEntExist" = "false()"!]
    [!ENDIF!]
  [!ENDFOR!]
  )
  {
    AllCoresSameMode = FALSE;
  }
[!ENDIF!]

  return AllCoresSameMode;
}

#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

[!IF "$DefaultServiceAPI = 'NONE'"!][!//
  [!FOR "Index" = "0" TO "$MULTICORE_NUM_CORES - 1"!]
    [!IF "$Index != $WDGM_MASTER_CORE_ID"!]
      [!VAR "SupEntExistPerCore" = "false()"!][!//
      [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
        [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($Index)"!][!//
          [!VAR "SupEntExistPerCore" = "true()"!][!//
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$SupEntExistPerCore"!][!//
#define WDGM_1_CORE_[!"num:i($Index)"!]_START_SEC_CODE_ASIL_D
#include <WdgM_1_CORE_[!"num:i($Index)"!]_MemMap.h>
FUNC(void, WDGM_1_CORE_[!"num:i($Index)"!]_CODE) WdgM_1_CORE_[!"num:i($Index)"!]_MainFunction(void)
{
   WdgM_MainFunction();
}
#define WDGM_1_CORE_[!"num:i($Index)"!]_STOP_SEC_CODE_ASIL_D
#include <WdgM_1_CORE_[!"num:i($Index)"!]_MemMap.h>
      [!ENDIF!]
    [!ENDIF!]
  [!ENDFOR!]
[!ENDIF!]
[!ELSE!][!/* IF $WdgMMulticoreEnabled */!]

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

/** \brief Internal RAM data holding a copy of the alive counter values for each checkpoint */
VAR(WdgM_EB_CPInternalDataType, WDGM_VAR) WdgM_EB_IntRAMData[WDGM_EB_CHECKPOINTS_NUM];

/** \brief failed reference cycle counter for the SE  */
VAR(uint16, WDGM_VAR) WdgM_EB_FailedAliveSupervisionRefCycleCnt[WDGM_EB_SE_NUM];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_8BIT
#else
#define WDGM_START_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/** \brief WdgM global initialization status */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable15,2 */
VAR(WdgM_EB_InitStatusType, WDGM_VAR) WdgM_EB_InitStatus = WDGM_EB_INIT_STATUS_DEINIT;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_8BIT
#else
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

#define WDGM_START_SEC_VAR_INIT_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]

/** \brief The WdgM specific context data.
 ** This variable holds the specific run time data of the WdgM. */
VAR(WdgM_EB_CoreContextType, WDGM_VAR) WdgM_EB_Context =
{
  WdgM_EB_SELocalStatus,
[!IF "$WdgMGetAllExpiredSEIDs = 'true'"!]
  WdgM_EB_ExpiredSEIDs,
  WDGM_EB_SE_NUM,
  &WdgM_EB_ExpiredSEIDsCounter,
[!ENDIF!]
  WdgM_EB_FailedAliveSupervisionRefCycleCnt,
  WdgM_EB_IntRAMData,
  &WdgM_EB_InitStatus,
  0U,
  0U,
  FALSE,
#if (WDGM_EB_CHECK_MAINFUNCTION_TIMING == STD_ON)
  0U,
#endif
  0U,
[!IF "$WdgMPartitionResetEnabled = 'true'"!][!//
  [!WS!][!WS!][!"num:i($WdgMNumOfPartitionsPerCore)"!]U,
  WdgM_EB_Core0PartitionSupervisionCycleCnt
[!ENDIF!][!//
};

#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

[!IF "$WdgMGetAllExpiredSEIDs = 'true'"!]
#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

/* Deviation MISRAC2012-1 */
FUNC(void, WDGM_CODE) WdgM_EB_GetAllExpiredSEIDsHelper
(
  P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) Counter,
  P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) ExpiredSEIDs
)
{
  uint8 LocalIndex;
  uint8 LocalStoreIndex = 0U;

  /* !LINKSTO WDGM.EB.GetAllExpiredSEID.CoreSpecific.Read, 1 */
  for (LocalIndex = 0U; LocalIndex < WdgM_EB_ExpiredSEIDsCounter; LocalIndex++)
  {
    ExpiredSEIDs[LocalStoreIndex] = WdgM_EB_ExpiredSEIDs[LocalIndex];
    LocalStoreIndex++;
  }

  /* Return the number of expired supervised entities (if any) */
  *Counter = LocalStoreIndex;
}

FUNC(void, WDGM_CODE) WdgM_EB_ResetAllExpiredSEIDs(void)
{
  uint8 LocalIndex;

  for (LocalIndex = 0U; LocalIndex < WdgM_EB_ExpiredSEIDsCounter; LocalIndex++)
  {
    WdgM_EB_ExpiredSEIDs[LocalIndex] = 0U;
  }

  WdgM_EB_ExpiredSEIDsCounter = 0U;
}

#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>
[!ENDIF!]

[!ENDIF!][!/* IF $WdgMMulticoreEnabled */!]

[!IF "$WdgMPartitionResetEnabled = 'true'"!]
#define WDGM_START_SEC_VAR_INIT_ASIL_D_8
#include <WdgM_MemMap.h>
[!VAR "WdgMOsAppRefNameList" = "''"!][!//
[!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
  [!IF "node:exists(./WdgMOsApplicationRef)"!][!//
    [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!][!//
    [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!][!//
/** \brief
 **  List of internal IDs for all SEs mapped to [!"$WdgMOsAppRefName"!]
 **/
STATIC VAR(WdgM_EB_SEIdType, WDGM_VAR) WdgM_EB_SE_[!"$WdgMOsAppRefName"!]_Mapping[WDGM_EB_NUM_SE_[!"$WdgMOsAppRefName"!]] = 
{
    [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!IF "name(as:ref(./WdgMOsApplicationRef)) = $WdgMOsAppRefName"!]
  [!"@index"!], /* internal SEId of the [!"@name"!] SE */
        [!ENDIF!]
      [!ENDIF!]
    [!ENDLOOP!]
};

      [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//

#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#include <WdgM_MemMap.h>

#define WDGM_START_SEC_VAR_INIT_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

[!VAR "WdgMOsAppRefNameList" = "''"!]
[!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
  [!IF "node:exists(./WdgMOsApplicationRef)"!]
    [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
    [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]

  [!VAR "WdgMNumOfSEPerPartition"="0"!][!//
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!][!//
      [!IF "node:exists(./WdgMOsApplicationRef)"!][!//
        [!IF "name(as:ref(./WdgMOsApplicationRef)) = $WdgMOsAppRefName"!][!//
            [!VAR "WdgMNumOfSEPerPartition" = "$WdgMNumOfSEPerPartition + 1"!][!//
        [!ENDIF!][!//
      [!ENDIF!][!//
  [!ENDLOOP!][!//

/** \brief
 ** Holds information about SEs mapped to [!"$WdgMOsAppRefName"!] and their total number
 **/
STATIC VAR(WdgM_EB_SE_Type, WDGM_VAR) WdgM_EB_SE_[!"$WdgMOsAppRefName"!] = 
{
  WdgM_EB_SE_[!"$WdgMOsAppRefName"!]_Mapping, /* List of SEs mapped to OsApplication */
  [!WS!][!WS!][!"num:i($WdgMNumOfSEPerPartition)"!]U  /* total number of SEs mapped to OsApplication */
};

      [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
    [!ENDIF!]
  [!ENDIF!]
[!ENDLOOP!]

#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>
[!ENDIF!]

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
[!FOR "index_i" = "0" TO "num:i($NumberOfExternalGraphs)-1"!][!//
/** \brief run-time data for each external graph to store the sequence
  *  number of checkpoint for each supervised entity */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable16,1 */
static VAR(WdgM_EB_ExtGraphDataSeqArrayType, WDGM_VAR) WdgM_EB_ExtGraphDataSeq_[!"num:i($index_i)"!][WDGM_EB_SE_NUM_GRAPHID_[!"num:i($index_i)"!]];

[!ENDFOR!][!//
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
[!FOR "index_i" = "0" TO "num:i($NumberOfExternalGraphs)-1"!][!//
 /* pointer to the run-time data for each external graph and length of the array */
 { &WdgM_EB_ExtGraphDataSeq_[!"num:i($index_i)"!][0], WDGM_EB_SE_NUM_GRAPHID_[!"num:i($index_i)"!] },
[!ENDFOR!][!//
};
#endif

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#else
#define WDGM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

/*==================[external function definitions]==============================================*/
[!IF "$WdgMPartitionResetEnabled = 'true'"!]
#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

FUNC(uint8, WDGM_CODE) WdgM_EB_GetPartitionIndex
(
  P2VAR(WdgM_EB_CoreContextType, AUTOMATIC, WDGM_APPL_CONST) CoreInstance,
  ApplicationType PartitionId
)
{
  uint8 RetVal = 0xFFU;
  uint8 CorePartitionIdx;

[!IF "$WdgMMulticoreEnabled = 'true'"!]
  CoreIdType localCoreID = CoreInstance->CoreID;

  switch(localCoreID)
  {
[!FOR "Index" = "0" TO "$MULTICORE_NUM_CORES - 1"!]
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
[!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!][!//
    case [!"num:i($Index)"!]:
    {
      for (CorePartitionIdx = 0; CorePartitionIdx < CoreInstance->NumOsPartitions; CorePartitionIdx++)
      {
        if (PartitionId == WdgM_EB_Core[!"num:i($Index)"!]PartitionId[CorePartitionIdx])
        {
          RetVal = CorePartitionIdx;
        }
      }
      break;
    }
[!ENDIF!]
[!ENDFOR!]
    /* CHECK: NOPARSE */
    default:
      WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
      break;
    /* CHECK: PARSE */
  }
[!ELSE!][!/* IF $WdgMMulticoreEnabled */!][!//
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
  [!ENDLOOP!]
[!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!][!//
    for (CorePartitionIdx = 0; CorePartitionIdx < CoreInstance->NumOsPartitions; CorePartitionIdx++)
    {
      if (PartitionId == WdgM_EB_Core0PartitionId[CorePartitionIdx])
      {
        RetVal = CorePartitionIdx;
      }
    }
[!ENDIF!]
[!ENDIF!]

  return RetVal;
}

FUNC(ApplicationType, WDGM_CODE) WdgM_EB_GetPartitionId
(
  CoreIdType CoreId,
  ApplicationType PartitionIndex
)
{
  ApplicationType ApplicationId = INVALID_OSAPPLICATION;

  switch(CoreId)
  {
  [!FOR "Index" = "0" TO "$MULTICORE_NUM_CORES - 1"!]
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!]
    case [!"num:i($Index)"!]:
    {
      ApplicationId = WdgM_EB_Core[!"num:i($Index)"!]PartitionId[PartitionIndex];
      break;
    }
  [!ENDIF!]
  [!ENDFOR!]
    /* CHECK: NOPARSE */
    default:
      WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
      break;
    /* CHECK: PARSE */
  }

  return ApplicationId;
}

FUNC(ApplicationType, WDGM_CODE) WdgM_EB_GetPartitionStatus
(
  CoreIdType CoreId,
  ApplicationType PartitionIndex
)
{
  uint8 PartitionStatus = 0xFF;

  switch(CoreId)
  {
  [!FOR "Index" = "0" TO "$MULTICORE_NUM_CORES - 1"!]
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!]
    case [!"num:i($Index)"!]:
    {
      PartitionStatus = WdgM_EB_Core[!"num:i($Index)"!]_PartitionStatus[PartitionIndex];
      break;
    }
  [!ENDIF!]
  [!ENDFOR!]
    /* CHECK: NOPARSE */
    default:
      WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
      break;
    /* CHECK: PARSE */
  }

  return PartitionStatus;
}

FUNC(void, WDGM_CODE) WdgM_EB_SetPartitionStatus
(
  CoreIdType WdgMCoreId,
  ApplicationType PartitionIndex,
  uint8 PartitionStatus
)
{
  switch(WdgMCoreId)
  {
  [!FOR "Index" = "0" TO "$MULTICORE_NUM_CORES - 1"!]
  [!VAR "WdgMOsAppRefNameList" = "''"!]
  [!VAR "WdgMNumOfPartitionsPerCore"="0"!]
  [!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
    [!IF "$WdgMMulticoreEnabled = 'true'"!]
      [!IF "num:i(node:value(WdgMSupervisedEntityCoreId)) = num:i($index_i)"!]
        [!IF "node:exists(./WdgMOsApplicationRef)"!]
          [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
          [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
            [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
            [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ELSE!]
      [!IF "node:exists(./WdgMOsApplicationRef)"!]
        [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
        [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
          [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
          [!VAR "WdgMNumOfPartitionsPerCore" = "$WdgMNumOfPartitionsPerCore + 1"!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!IF "num:i($WdgMNumOfPartitionsPerCore) != 0"!]
    case [!"num:i($Index)"!]:
    {
      WdgM_EB_Core[!"num:i($Index)"!]_PartitionStatus[PartitionIndex] = PartitionStatus;
      break;
    }
  [!ENDIF!]
  [!ENDFOR!]
    /* CHECK: NOPARSE */
    default:
      WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
      break;
    /* CHECK: PARSE */
  }
}

FUNC_P2VAR(WdgM_EB_SEIdType, WDGM_APPL_DATA, WDGM_CODE) WdgM_EB_GetSEfromOsApp
(
  ApplicationType ApplicationId,
  P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) Size
)
{
  P2VAR(WdgM_EB_SEIdType, AUTOMATIC, WDGM_APPL_CONST) SEPtr = NULL_PTR;

  switch(ApplicationId)
  {
[!VAR "WdgMOsAppRefNameList" = "''"!]
[!LOOP "as:modconf('WdgM')[1]/WdgMGeneral/WdgMSupervisedEntity/*"!]
  [!IF "node:exists(./WdgMOsApplicationRef)"!]
  [!VAR "WdgMOsAppRefName"="name(as:ref(./WdgMOsApplicationRef))"!]
    [!IF "not(contains($WdgMOsAppRefNameList,concat(' ',$WdgMOsAppRefName,' ')))"!]
    case [!"$WdgMOsAppRefName"!]:
    {
      SEPtr = &WdgM_EB_SE_[!"$WdgMOsAppRefName"!].WdgM_EB_SE[0U];
      *Size = WdgM_EB_SE_[!"$WdgMOsAppRefName"!].WdgM_EB_Size;
      break;
    }
    [!VAR "WdgMOsAppRefNameList" = "concat($WdgMOsAppRefNameList,' ',$WdgMOsAppRefName,' ')"!]
    [!ENDIF!]
  [!ENDIF!]
[!ENDLOOP!]
    /* CHECK: NOPARSE */
    default:
      WDGM_UNREACHABLE_CODE_ASSERT(WDGM_SID_MAIN_FUNCTION);
      break;
    /* CHECK: PARSE */
  }

  return SEPtr;
}

#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>
[!ENDIF!][!//
/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
[!ENDCODE!][!//
