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
 * Misra-C:2012 Deviations:
 *
 * MISRAC2012-1) Deviated Rule: 8.3 (required)
 * All declarations of an object or function shall use the same names and type qualifiers.
 *
 * Reason:
 * AUTOSAR provides the specification of a PortDefinedArgumentValue via
 * a RunnableEntityArgument only till version 4.0.3. In older versions,
 * this specification was not possible leading to the generation
 * of vendor-specific argument names which may differ to the argument names
 * defined in the BSW.
 *
 * MISRAC2012-2) Deviated Rule: 5.6 (required)
 * A typedef name shall be a unique identifier.
 *
 * Reason:
 * Rte_ModeType_WdgMMode are needed for the WdgM_RteSwitchFunc type in all core WdgM_Rte_Lcfg_Core_X.c files
 * because RTE only allows one inclusion of the service header file, where Rte_ModeType_WdgMMode is available.
 * Because AUTOSAR deny inclusion of c files, the type is only once defined per each c file and it is unique.
 */
/*==================[inclusions]=================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,3 */
/* !LINKSTO WDGM.EB.Dbg3,1 */
#include <WdgM_Trace_Stc.h>
#include <WdgM_Rte_Lcfg.h>                           /* Module internal Rte declarations and API */
#include <Rte_WdgM_CORE_1.h>
/*==================[macros]=====================================================================*/

#if (defined WDGM_EB_RTE_NUM_STATUS)
#error WDGM_EB_RTE_NUM_STATUS already defined
#endif
/* \brief number of status mappings */
#define WDGM_EB_RTE_NUM_STATUS  5U

/* Internal sanity check  that WdgM Global/Local Status values are correctly
 * mapped to Rte status values */
#if ((WDGM_LOCAL_STATUS_OK != 0U) || (WDGM_GLOBAL_STATUS_OK != 0U))
#error WDGM_LOCAL_STATUS_OK/WDGM_GLOBAL_STATUS_OK must equal 0U
#endif
#if ((WDGM_LOCAL_STATUS_FAILED != 1U) || (WDGM_GLOBAL_STATUS_FAILED != 1U))
#error WDGM_LOCAL_STATUS_FAILED/WDGM_GLOBAL_STATUS_FAILED must equal 1U
#endif
#if ((WDGM_LOCAL_STATUS_EXPIRED != 2U) || (WDGM_GLOBAL_STATUS_EXPIRED != 2U))
#error WDGM_LOCAL_STATUS_EXPIRED/WDGM_GLOBAL_STATUS_EXPIRED must equal 2U
#endif
#if (WDGM_GLOBAL_STATUS_STOPPED != 3U) /* There is no WDGM_LOCAL_STATUS_STOPPED */
#error WDGM_GLOBAL_STATUS_STOPPED must equal 3U
#endif
#if ((WDGM_LOCAL_STATUS_DEACTIVATED != 4U) || (WDGM_GLOBAL_STATUS_DEACTIVATED != 4U))
#error WDGM_LOCAL_STATUS_DEACTIVATED/WDGM_GLOBAL_STATUS_DEACTIVATED must equal 4U
#endif

/*==================[type definitions]===========================================================*/

/** \brief Default function pointer type for mode switch request functions of the
 * RTE */
/* Deviation MISRAC2012-2 */
typedef P2FUNC(Std_ReturnType, RTE_APPL_CODE, WdgM_RteSwitchFunc)(
    Rte_ModeType_WdgMMode mode);

/*==================[internal function declarations]=============================================*/

/*==================[internal data]==============================================================*/

/*==================[external data]==============================================================*/

/*==================[internal constants]=========================================================*/

#define WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_8
#include <WdgM_1_CORE_1_MemMap.h>

/* \brief map WdgM global supervision status to the AUTOSAR 4.0 specific
 *  Rte_ModeType_WdgMMode if default service API is set to AUTOSAR 4.0.
 *
 * This mapping table is needed as RTE mode type is generated in alphabetical
 * order whereas the WdgM state has "logical" order */
static CONST(Rte_ModeType_WdgMMode, WDGM_CONST) WdgM_EB_RteStatusMap[WDGM_EB_RTE_NUM_STATUS] =
{
  RTE_MODE_WdgMMode_SUPERVISION_OK,          /* WDGM_GLOBAL/LOCAL_STATUS_OK */
  RTE_MODE_WdgMMode_SUPERVISION_FAILED,      /* WDGM_GLOBAL/LOCAL_STATUS_FAILED */
  RTE_MODE_WdgMMode_SUPERVISION_EXPIRED,     /* WDGM_GLOBAL/LOCAL_STATUS_EXPIRED */
  RTE_MODE_WdgMMode_SUPERVISION_STOPPED,     /* WDGM_GLOBAL_STATUS_STOPPED */
  RTE_MODE_WdgMMode_SUPERVISION_DEACTIVATED  /* WDGM_GLOBAL/LOCAL_STATUS_DEACTIVATED */
};

#define WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_8
#include <WdgM_1_CORE_1_MemMap.h>

#define WDGM_1_CORE_1_START_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_1_CORE_1_MemMap.h>

/* \brief Array with all mode switch functions for all the Supervised Entities from this core */
static CONST(WdgM_RteSwitchFunc, WDGM_CONST) WdgM_Core_1_RteSwitch[WDGM_EB_SE_NUM_CORE1] =
{
  &Rte_Switch_mode_WdgM_SE_SWC_MONITOR_currentMode,
};

#define WDGM_1_CORE_1_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
#include <WdgM_1_CORE_1_MemMap.h>

/*==================[external constants]=========================================================*/

/*==================[external function definitions]==============================================*/
#define WDGM_1_CORE_1_START_SEC_CODE_ASIL_D
#include <WdgM_1_CORE_1_MemMap.h>
FUNC(void, RTE_CODE) WdgM_1_CORE_1_MainFunction(void)
{
   WdgM_MainFunction();
}

/* Deviation MISRAC2012-1 */
FUNC(void, WDGM_CODE) WdgM_RteIndividualModeSwitch_CORE_1
(
  WdgM_SupervisedEntityIdType       SEID,
  WdgM_LocalStatusType              LocalStatus
)
{
  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTEINDIVIDUALMODESWITCH_CORE_1_ENTRY(SEID,LocalStatus);

  /* Return value is ignored because mode switch indication to Rte is compliant to a
   * fire and forget policy from WdgM's point of view. */
  (void)WdgM_Core_1_RteSwitch[SEID](WdgM_EB_RteStatusMap[LocalStatus]);
  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTEINDIVIDUALMODESWITCH_CORE_1_EXIT(SEID,LocalStatus);
}


/* Deviation MISRAC2012-1 */
FUNC(Std_ReturnType, RTE_CODE) WdgM_Rte_UpdateAliveCounter_CORE_1
(
  WdgM_SupervisedEntityIdType SEID
)
{
  Std_ReturnType RetVal;

  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTE_UPDATEALIVECOUNTER_CORE_1_ENTRY(SEID);

  /* !LINKSTO WDGM.EB.ASR32.WDGM110,2 */
  RetVal = WdgM_UpdateAliveCounter(SEID);

  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTE_UPDATEALIVECOUNTER_CORE_1_EXIT(RetVal,SEID);
  return RetVal;
}

/* Deviation MISRAC2012-1 */
FUNC(Std_ReturnType, RTE_CODE) WdgM_Rte_CheckpointReached_CORE_1
(
  WdgM_SupervisedEntityIdType SEID,
  WdgM_CheckpointIdType       CheckpointID
)
{
  Std_ReturnType RetVal;

  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTE_CHECKPOINTREACHED_CORE_1_ENTRY(SEID,CheckpointID);

  /* !LINKSTO WDGM.EB.ASR32.WDGM110,2 */
  RetVal = WdgM_CheckpointReached(SEID, CheckpointID);

  /* !LINKSTO WDGM.EB.Dbg4,1 */
  DBG_WDGM_RTE_CHECKPOINTREACHED_CORE_1_EXIT(RetVal,SEID,CheckpointID);
  return RetVal;
}

#define WDGM_1_CORE_1_STOP_SEC_CODE_ASIL_D
#include <WdgM_1_CORE_1_MemMap.h>

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
