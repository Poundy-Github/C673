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

#ifndef WDGM_LCFG_H
#define WDGM_LCFG_H

/*==================[inclusions]=================================================================*/
/* !LINKSTO WDGM.EB.Design.IncludeFileStructure,3 */
#include <WdgM_Cfg.h>
#include <WdgM_BSW_Lcfg.h>

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_START_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable3,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable5,1 */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable8,1 */
/* Checkpoint individual run-time data for each SE */
extern VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_AS_HM[1];
/* Checkpoint individual run-time data for each SE */
extern VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_SWC_MONITOR[1];
/* Checkpoint individual run-time data for each SE */
extern VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_CameraTemp[1];
/* Checkpoint individual run-time data for each SE */
extern VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_ConfigReg[1];
/* Checkpoint individual run-time data for each SE */
extern VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_FS_MAIN[1];
/* Checkpoint individual run-time data for each SE */
extern VAR(WdgM_EB_CPDataType,WDGM_VAR) WdgM_EB_CPData_WdgM_SE_FS_ADC[1];

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_STOP_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>


#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/** \brief through this variable, the WdgM master instance announces the WdgM satellite instances that the mode switch has been performed.
  * The WdgM satellite instances read the value of this variable to change and update their mode. */
extern VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_CoreSwitchMode[WDGM_EB_NUMBER_OF_CORES];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>


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
extern VAR(WdgM_EB_InitStatusType, WDGM_VAR) WdgM_EB_ExpectedInitState;
#endif


/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable2,1 */
/** \brief WdgM global supervision status */
extern VAR(WdgM_GlobalStatusType, WDGM_VAR) WdgM_EB_GlobalStatus;

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_8BIT
#else
#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#else
#define WDGM_START_SEC_CONST_ASIL_D_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_EXTERNAL_GRAPH_NUM > 0U)
/** \brief array of pointers to the run-time data for each external graph and length of the pointed arrays */
extern CONST(WdgM_EB_ExtGraphDataSeqType,WDGM_CONST) WdgM_EB_ExtGraphDataSeqPtr[WDGM_EB_EXTERNAL_GRAPH_NUM];
#endif

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#else
#define WDGM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
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
extern VAR(boolean, WDGM_VAR) WdgM_EB_IsExpiredSEIdSet;

#if (WDGM_EB_EXT_GET_EXPECTED_WDGM_MODE_ENABLED == STD_OFF)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable17,1 */
extern VAR(WdgM_ModeType, WDGM_VAR) WdgM_EB_ExpectedWdgMModeId;
#endif

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_8BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_8
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_START_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

/** \brief Internal RAM data holding a copy of the alive counter values for each checkpoint */
extern VAR(WdgM_EB_CPInternalDataType, WDGM_VAR) WdgM_EB_IntRAMData[WDGM_EB_CHECKPOINTS_NUM];

/** \brief failed reference cycle counter for the SE  */
extern VAR(uint16, WDGM_VAR) WdgM_EB_FailedAliveSupervisionRefCycleCnt[WDGM_EB_SE_NUM];

#if (WDGM_EB_ENABLE_ASR32_SERVICE_API == STD_ON)
#define WDGM_STOP_SEC_VAR_CLEARED_16BIT
#else
#define WDGM_STOP_SEC_VAR_CLEARED_ASIL_D_16
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_LOGICAL_SUPERVISION_ENABLED == STD_ON)
/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_START_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

#if (WDGM_EB_EXTERNAL_GRAPH_NUM > 0U)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable12,1,WDGM.EB.DesignDecision.InternalVariable13,1 */
extern VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_ExternalGraphData[WDGM_EB_EXTERNAL_GRAPH_NUM];
#else
extern VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_ExternalGraphData[1];
#endif

#if (WDGM_EB_INTERNAL_GRAPH_NUM > 0U)
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable6,2,WDGM.EB.DesignDecision.InternalVariable7,2 */
extern VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_InternalGraphData[WDGM_EB_INTERNAL_GRAPH_NUM];
#else
extern VAR(WdgM_EB_GraphDataType,WDGM_VAR) WdgM_EB_InternalGraphData[1];
#endif

/* !LINKSTO WDGM.EB.TIMEPM.WDGM020304,1 */
#if (WDGM_EB_PARTITIONING_ENABLED == STD_ON)
#define WDGM_STOP_SEC_SHARED_VAR_CLEARED_UNSPECIFIED
#else
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include <WdgM_MemMap.h>

#endif

#define WDGM_START_SEC_VAR_POWER_ON_INIT_ASIL_D_16
#include <WdgM_MemMap.h>

/** \brief the Supervised Entity Id which first expired */
/* !LINKSTO WDGM.EB.DesignDecision.InternalVariable19,1 */
extern VAR(WdgM_EB_ExpiredSEIDType, WDGM_VAR_POWER_ON_INIT) WdgM_EB_ExpiredSEID;

#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_ASIL_D_16
#include <WdgM_MemMap.h>

#define WDGM_START_SEC_VAR_INIT_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

/** \brief The WdgM specific context data.
 ** This variable holds the specific run time data of the WdgM. */
extern VAR(WdgM_EB_CoreContextType, WDGM_VAR) WdgM_EB_Context;

#define WDGM_STOP_SEC_VAR_INIT_ASIL_D_UNSPECIFIED
#include <WdgM_MemMap.h>

/*==================[external function definitions]==============================================*/

#define WDGM_START_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>


/** \brief Returns the core context data structure for the core which called the function.
 **/
extern FUNC_P2VAR(WdgM_EB_CoreContextType, WDGM_APPL_DATA, WDGM_CODE) WdgM_GetCoreInstance(void);
/** \brief Returns the global initialization status for all the cores.
 **/
extern FUNC(WdgM_EB_InitStatusType, WDGM_CODE) WdgM_EB_GetGlobalInitStatus(void);
/** \brief Returns all the expired Supervised Entities.
 **/
extern FUNC(WdgM_EB_InitStatusType, WDGM_CODE) WdgM_EB_GetMasterInitStatus(void);
/** \brief Returns the local supervision status for a Supervised Entity.
 **/
extern FUNC(WdgM_LocalStatusType, WDGM_CODE) WdgM_EB_GetSELocalStatus(WdgM_EB_SEIdType IntSEId, uint8 ApiId);
/** \brief Returns the status regarding satellite finished the switch mode operation.
 **/
extern FUNC(WdgM_ModeType, WDGM_CODE) WdgM_EB_GetCoreSwitchMode(WdgM_EB_CoreIdType CoreId);
/** \brief Returns TRUE is all core are in the same mode, otherwise FALSE
 **/
extern FUNC(boolean, WDGM_CODE) WdgM_EB_AllCoresSameMode(void);






#define WDGM_STOP_SEC_CODE_ASIL_D
#include <WdgM_MemMap.h>

#endif /* ifndef WDGM_LCFG_H */
/*==================[end of file]================================================================*/
