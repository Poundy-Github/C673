#ifndef RTE_WDGM_CORE_0_HOOK_H
#define RTE_WDGM_CORE_0_HOOK_H
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
 * This file contains Rte hook declarations for the software component type WdgM_CORE_0
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Wed Jun 07 09:38:12 CST 2023. !!!IGNORE-LINE!!!
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
#if (defined(Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Start
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Start)
#undef Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Start (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Start(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Return
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Return)
#undef Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Return (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_globalMode_currentMode_Return(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start(mode) ((void)0)
#endif
#if (defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return
#endif
#if defined(Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return)
#undef Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return (uint8 mode);
#else
#define Rte_SwitchHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return(mode) ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Start
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Start)
#undef Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Start (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Start() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Return
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Return)
#undef Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Return (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_globalMode_currentMode_Return() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Start() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_AS_HM_currentMode_Return() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Start() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_CameraTemp_currentMode_Return() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Start() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_ConfigReg_currentMode_Return() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Start() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_MAIN_currentMode_Return() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Start() ((void)0)
#endif
#if (defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return
#endif
#if defined(Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return)
#undef Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return (void);
#else
#define Rte_ModeHook_WdgM_CORE_0_mode_WdgM_SE_FS_ADC_currentMode_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_WdgM_CORE_0_RE_Main_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_WdgM_CORE_0_RE_Main_Start
#endif
#if defined(Rte_Runnable_WdgM_CORE_0_RE_Main_Start)
#undef Rte_Runnable_WdgM_CORE_0_RE_Main_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CORE_0_RE_Main_Start (void);
#else
#define Rte_Runnable_WdgM_CORE_0_RE_Main_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_WdgM_CORE_0_RE_Main_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_WdgM_CORE_0_RE_Main_Return
#endif
#if defined(Rte_Runnable_WdgM_CORE_0_RE_Main_Return)
#undef Rte_Runnable_WdgM_CORE_0_RE_Main_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CORE_0_RE_Main_Return (void);
#else
#define Rte_Runnable_WdgM_CORE_0_RE_Main_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Start
#endif
#if defined(Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Start)
#undef Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Start (void);
#else
#define Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Return
#endif
#if defined(Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Return)
#undef Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Return (void);
#else
#define Rte_Runnable_WdgM_CORE_0_RE_UpdateAliveCounter_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Start
#endif
#if defined(Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Start)
#undef Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Start (void);
#else
#define Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Return
#endif
#if defined(Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Return)
#undef Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Return (void);
#else
#define Rte_Runnable_WdgM_CORE_0_RE_CheckpointReached_Return() ((void)0)
#endif
#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
