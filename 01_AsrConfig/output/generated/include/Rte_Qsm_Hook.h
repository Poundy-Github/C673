#ifndef RTE_QSM_HOOK_H
#define RTE_QSM_HOOK_H
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
 * This file contains Rte hook declarations for the software component type Qsm
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Wed Mar 15 13:10:49 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ==================[Includes]=============================================== */
#include <Rte_Cfg.h>
#include <Rte_Type.h>

/* ==================[Macros]================================================= */
#ifndef RTE_CORE
#ifndef RTE_VFB_TRACE
#define RTE_VFB_TRACE 0
#endif
#endif
#define RTE_START_SEC_CODE
#include <Rte_MemMap.h>
#if (defined(Rte_Runnable_Qsm_Qsm_GetErrorStatues_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_GetErrorStatues_Start
#endif
#if defined(Rte_Runnable_Qsm_Qsm_GetErrorStatues_Start)
#undef Rte_Runnable_Qsm_Qsm_GetErrorStatues_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_GetErrorStatues_Start (void);
#else
#define Rte_Runnable_Qsm_Qsm_GetErrorStatues_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_GetErrorStatues_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_GetErrorStatues_Return
#endif
#if defined(Rte_Runnable_Qsm_Qsm_GetErrorStatues_Return)
#undef Rte_Runnable_Qsm_Qsm_GetErrorStatues_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_GetErrorStatues_Return (void);
#else
#define Rte_Runnable_Qsm_Qsm_GetErrorStatues_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_InitFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_InitFunction_Start
#endif
#if defined(Rte_Runnable_Qsm_Qsm_InitFunction_Start)
#undef Rte_Runnable_Qsm_Qsm_InitFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_InitFunction_Start (void);
#else
#define Rte_Runnable_Qsm_Qsm_InitFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_InitFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_InitFunction_Return
#endif
#if defined(Rte_Runnable_Qsm_Qsm_InitFunction_Return)
#undef Rte_Runnable_Qsm_Qsm_InitFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_InitFunction_Return (void);
#else
#define Rte_Runnable_Qsm_Qsm_InitFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_MainFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_MainFunction_Start
#endif
#if defined(Rte_Runnable_Qsm_Qsm_MainFunction_Start)
#undef Rte_Runnable_Qsm_Qsm_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_MainFunction_Start (void);
#else
#define Rte_Runnable_Qsm_Qsm_MainFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_MainFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_MainFunction_Return
#endif
#if defined(Rte_Runnable_Qsm_Qsm_MainFunction_Return)
#undef Rte_Runnable_Qsm_Qsm_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_MainFunction_Return (void);
#else
#define Rte_Runnable_Qsm_Qsm_MainFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_ReadBlock_Start
#endif
#if defined(Rte_Runnable_Qsm_Qsm_ReadBlock_Start)
#undef Rte_Runnable_Qsm_Qsm_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_ReadBlock_Start (void);
#else
#define Rte_Runnable_Qsm_Qsm_ReadBlock_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_ReadBlock_Return
#endif
#if defined(Rte_Runnable_Qsm_Qsm_ReadBlock_Return)
#undef Rte_Runnable_Qsm_Qsm_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_ReadBlock_Return (void);
#else
#define Rte_Runnable_Qsm_Qsm_ReadBlock_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_WriteBlock_Start
#endif
#if defined(Rte_Runnable_Qsm_Qsm_WriteBlock_Start)
#undef Rte_Runnable_Qsm_Qsm_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_WriteBlock_Start (void);
#else
#define Rte_Runnable_Qsm_Qsm_WriteBlock_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Qsm_Qsm_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Qsm_Qsm_WriteBlock_Return
#endif
#if defined(Rte_Runnable_Qsm_Qsm_WriteBlock_Return)
#undef Rte_Runnable_Qsm_Qsm_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Qsm_Qsm_WriteBlock_Return (void);
#else
#define Rte_Runnable_Qsm_Qsm_WriteBlock_Return() ((void)0)
#endif
#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
