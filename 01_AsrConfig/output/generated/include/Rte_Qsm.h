#ifndef RTE_QSM_H
#define RTE_QSM_H
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
 * This file contains Rte component declarations for component type Qsm
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Fri Apr 14 09:48:30 CST 2023. !!!IGNORE-LINE!!!
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
#include <Rte_Qsm_Type.h>
#include <Rte_Qsm_Hook.h>
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
#endif

/* ------------------[port handle API mapping]-------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#define RTE_E_CSI_QsmBlockOp_E_NOT_OK 1U
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
#ifndef RTE_CORE /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_Qsm, TYPEDEF, RTE_CONST) Rte_Instance;
#endif

/* ==================[Definition of variables with external linkage]========== */
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
extern CONST(Rte_CDS_Qsm, RTE_CONST) Rte_Instance_Qsm;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>
extern CONSTP2CONST(Rte_CDS_Qsm, RTE_CONST, RTE_CONST) Rte_Inst_Qsm;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>

/* ==================[Declaration of functions with external linkage]========= */
/* ------------------[declaration of runnable entities]----------------------- */
#define Qsm_START_SEC_CODE
#include <Qsm_MemMap.h>
extern FUNC(Std_ReturnType, RTE_CODE) Qsm_GetErrorStatues (uint16 BlockId);

extern FUNC(void, RTE_CODE) Qsm_InitFunction (void);

extern FUNC(void, RTE_CODE) Qsm_MainFunction (void);

extern FUNC(Std_ReturnType, RTE_CODE) Qsm_ReadBlock (uint16 BlockId, VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);

extern FUNC(Std_ReturnType, RTE_CODE) Qsm_WriteBlock (uint16 BlockId, ConstVoidPtr QsmDstPtr);

#define Qsm_STOP_SEC_CODE
#include <Qsm_MemMap.h>

/* ------------------[declaration of API functions provided by Rte]----------- */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>

#define RTE_STOP_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>

/* ------------------[declaration of API functions provided by other Appl]---- */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
