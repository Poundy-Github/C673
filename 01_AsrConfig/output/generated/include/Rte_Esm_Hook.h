#ifndef RTE_ESM_HOOK_H
#define RTE_ESM_HOOK_H
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
 * This file contains Rte hook declarations for the software component type Esm
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Tue Jun 20 15:43:20 CST 2023. !!!IGNORE-LINE!!!
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
#if (defined(Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Start
#endif
#if defined(Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Start)
#undef Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Start (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Start(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Return
#endif
#if defined(Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Return)
#undef Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Return (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_Esm_RP_Dsm_SRI_SocResetControlState_DE_SocRersetControlState_Return(data) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Start
#endif
#if defined(Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Start)
#undef Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Start (P2VAR(uint64_t, AUTOMATIC, RTE_APPL_DATA) ts_ms);
#else
#define Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Start(ts_ms) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Return
#endif
#if defined(Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Return)
#undef Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Return (P2VAR(uint64_t, AUTOMATIC, RTE_APPL_DATA) ts_ms);
#else
#define Rte_CallHook_Esm_RP_Time_GlobalTime_GetTimeStampMs_Return(ts_ms) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Start
#endif
#if defined(Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Start)
#undef Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Start (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag);
#else
#define Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Start(u_WakeupFlag) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Return
#endif
#if defined(Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Return)
#undef Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Return (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag);
#else
#define Rte_CallHook_Esm_RP_Comco_CSI_NMWakupFlag_NMWakupFlag_Return(u_WakeupFlag) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Start
#endif
#if defined(Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Start)
#undef Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Start (EcuM_StateType target, uint8 mode);
#else
#define Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Start(target, mode) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Return
#endif
#if defined(Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Return)
#undef Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Return (EcuM_StateType target, uint8 mode);
#else
#define Rte_CallHook_Esm_RP_EcuM_ShutdownTarget_Switchoff_SelectShutdownTarget_Return(target, mode) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Start
#endif
#if defined(Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Start)
#undef Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Start (void);
#else
#define Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Start() ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Return
#endif
#if defined(Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Return)
#undef Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Return (void);
#else
#define Rte_CallHook_Esm_RP_Sdc_SendInterface_SocInfo_SocShutdownReuqest_Return() ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Start
#endif
#if defined(Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Start)
#undef Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Start (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState);
#else
#define Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Start(u_CurNmState) ((void)0)
#endif
#if (defined(Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Return
#endif
#if defined(Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Return)
#undef Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Return (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState);
#else
#define Rte_CallHook_Esm_RP_Comco_CSI_nmCurrentState_nmCurrentState_Return(u_CurNmState) ((void)0)
#endif
#if (defined(Rte_Runnable_Esm_Esm_InitFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Esm_Esm_InitFunction_Start
#endif
#if defined(Rte_Runnable_Esm_Esm_InitFunction_Start)
#undef Rte_Runnable_Esm_Esm_InitFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Esm_InitFunction_Start (void);
#else
#define Rte_Runnable_Esm_Esm_InitFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Esm_Esm_InitFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Esm_Esm_InitFunction_Return
#endif
#if defined(Rte_Runnable_Esm_Esm_InitFunction_Return)
#undef Rte_Runnable_Esm_Esm_InitFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Esm_InitFunction_Return (void);
#else
#define Rte_Runnable_Esm_Esm_InitFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Esm_Esm_MainFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Esm_Esm_MainFunction_Start
#endif
#if defined(Rte_Runnable_Esm_Esm_MainFunction_Start)
#undef Rte_Runnable_Esm_Esm_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Esm_MainFunction_Start (void);
#else
#define Rte_Runnable_Esm_Esm_MainFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Esm_Esm_MainFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Esm_Esm_MainFunction_Return
#endif
#if defined(Rte_Runnable_Esm_Esm_MainFunction_Return)
#undef Rte_Runnable_Esm_Esm_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Esm_Esm_MainFunction_Return (void);
#else
#define Rte_Runnable_Esm_Esm_MainFunction_Return() ((void)0)
#endif
#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
