#ifndef RTE_WDGM_CORE_1_H
#define RTE_WDGM_CORE_1_H
/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.6.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains Rte component declarations for component type WdgM_CORE_1
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Tue Jun 06 13:51:54 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ==================[Includes]=============================================== */
#include <TSMem.h>
#include <Rte_WdgM_CORE_1_Type.h>
#include <Rte_WdgM_CORE_1_Hook.h>
#include <Rte_Components_Shared.h>

/* ==================[Macros]================================================= */
#ifndef RTE_CORE /* if included by software component */
#ifndef RTE_APPLICATION_HEADER_FILE_H /* prevent double inclusion */
#define RTE_APPLICATION_HEADER_FILE_H
#else
#error Multiple application header files included.
#endif
#endif
/* ------------------[API mapping]-------------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#if (!defined(RTE_RUNNABLEAPI_RE_UpdateAliveCounter)) && (!defined(RTE_RUNNABLEAPI_RE_CheckpointReached))
#define Rte_Switch_mode_WdgM_SE_SWC_MONITOR_currentMode Rte_Switch_WdgM_CORE_1_mode_WdgM_SE_SWC_MONITOR_currentMode
#define Rte_Mode_mode_WdgM_SE_SWC_MONITOR_currentMode Rte_Mode_WdgM_CORE_1_mode_WdgM_SE_SWC_MONITOR_currentMode
#endif
#endif

/* ------------------[port handle API mapping]-------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#define RTE_E_WdgM_AliveSupervision_E_NOT_OK 1U
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
#ifndef RTE_CORE /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_WdgM_CORE_1, TYPEDEF, RTE_CONST) Rte_Instance;
#endif

/* ==================[Definition of variables with external linkage]========== */
#define RTE_START_SEC_OSAPPLICATION_C1_CONST_8
#include <Rte_MemMap.h>
extern CONST(Rte_CDS_WdgM_CORE_1, RTE_CONST) Rte_Instance_WdgM_CORE_1;
#define RTE_STOP_SEC_OSAPPLICATION_C1_CONST_8
#include <Rte_MemMap.h>
#define RTE_START_SEC_OSAPPLICATION_C1_CONST_UNSPECIFIED
#include <Rte_MemMap.h>
extern CONSTP2CONST(Rte_CDS_WdgM_CORE_1, RTE_CONST, RTE_CONST) Rte_Inst_WdgM_CORE_1;
#define RTE_STOP_SEC_OSAPPLICATION_C1_CONST_UNSPECIFIED
#include <Rte_MemMap.h>

/* ==================[Declaration of functions with external linkage]========= */
/* ------------------[declaration of runnable entities]----------------------- */
#define WdgM_CORE_1_START_SEC_CODE
#include <WdgM_CORE_1_MemMap.h>
extern FUNC(Std_ReturnType, RTE_CODE) WdgM_Rte_UpdateAliveCounter_CORE_1 (WdgM_SupervisedEntityIdType SEID);

extern FUNC(Std_ReturnType, RTE_CODE) WdgM_Rte_CheckpointReached_CORE_1 (WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID);

#define WdgM_CORE_1_STOP_SEC_CODE
#include <WdgM_CORE_1_MemMap.h>

/* ------------------[declaration of API functions provided by Rte]----------- */
#define RTE_START_SEC_OSAPPLICATION_C1_CODE
#include <Rte_MemMap.h>
#if (!defined(RTE_RUNNABLEAPI_RE_UpdateAliveCounter)) && (!defined(RTE_RUNNABLEAPI_RE_CheckpointReached))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_CORE_1_mode_WdgM_SE_SWC_MONITOR_currentMode (uint8 mode);
extern FUNC(uint8, RTE_CODE) Rte_Mode_WdgM_CORE_1_mode_WdgM_SE_SWC_MONITOR_currentMode (void);
#endif

#define RTE_STOP_SEC_OSAPPLICATION_C1_CODE
#include <Rte_MemMap.h>

/* ------------------[declaration of API functions provided by other Appl]---- */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
