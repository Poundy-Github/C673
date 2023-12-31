#ifndef RTE_HWABS_HOOK_H
#define RTE_HWABS_HOOK_H
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
 * This file contains Rte hook declarations for the software component type HwAbs
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Tue Feb 28 15:54:30 CST 2023. !!!IGNORE-LINE!!!
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
#if (defined(Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Start
#endif
#if defined(Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Start)
#undef Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Start (P2CONST(s_AdcValue_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Return
#endif
#if defined(Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Return)
#undef Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Return (P2CONST(s_AdcValue_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_HwAbs_PP_HwAbs_AdcValue_AdcValue_Return(data) ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Start
#endif
#if defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Start)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Start (void);
#else
#define Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Return
#endif
#if defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Return)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Return (void);
#else
#define Rte_Runnable_HwAbs_Cdd_HeartbeatDet_InitFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Start
#endif
#if defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Start)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Start (void);
#else
#define Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Return
#endif
#if defined(Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Return)
#undef Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Return (void);
#else
#define Rte_Runnable_HwAbs_Cdd_HeartbeatDet_MainFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_PWR_2V9_PG_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_RST_B_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Om_VMERRB_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_FS0B_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_INTB_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_FS84_PG_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5024_RST_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG1_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF5204_PG3_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_EWARN_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_FS0B_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_INTB_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_PG_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Start)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Return)
#undef Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_GetIoLevel_Pmic_PF8200_RST_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_InitFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_InitFunction_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_InitFunction_Start)
#undef Rte_Runnable_HwAbs_HwAbs_InitFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_InitFunction_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_InitFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_InitFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_InitFunction_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_InitFunction_Return)
#undef Rte_Runnable_HwAbs_HwAbs_InitFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_InitFunction_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_InitFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_MainFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_MainFunction_Start
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_MainFunction_Start)
#undef Rte_Runnable_HwAbs_HwAbs_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_MainFunction_Start (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_MainFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_HwAbs_HwAbs_MainFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_HwAbs_HwAbs_MainFunction_Return
#endif
#if defined(Rte_Runnable_HwAbs_HwAbs_MainFunction_Return)
#undef Rte_Runnable_HwAbs_HwAbs_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_HwAbs_HwAbs_MainFunction_Return (void);
#else
#define Rte_Runnable_HwAbs_HwAbs_MainFunction_Return() ((void)0)
#endif
#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
