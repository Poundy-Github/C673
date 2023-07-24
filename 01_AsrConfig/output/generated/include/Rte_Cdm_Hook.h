#ifndef RTE_CDM_HOOK_H
#define RTE_CDM_HOOK_H
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
 * This file contains Rte hook declarations for the software component type Cdm
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Sun Apr 23 14:44:01 CST 2023. !!!IGNORE-LINE!!!
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
#if (defined(Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start
#endif
#if defined(Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start)
#undef Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start (P2CONST(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return
#endif
#if defined(Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return)
#undef Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return (P2CONST(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_Cdm_PP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return(data) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Start)
#undef Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Start (P2VAR(float32_t, AUTOMATIC, RTE_APPL_DATA) value);
#else
#define Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Start(value) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Return)
#undef Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Return (P2VAR(float32_t, AUTOMATIC, RTE_APPL_DATA) value);
#else
#define Rte_CallHook_Cdm_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue_Return(value) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Start
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Start)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Start (void);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Start() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Return
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Return)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Return (void);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_GetErrorStatues_Return() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Start
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Start)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Start (void);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Start() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Return
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Return)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Return (void);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_GetErrorStatues_Return() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Start)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Start (void);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Start() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Return)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Return (void);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_GetErrorStatues_Return() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Start)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Start (void);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Start() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Return)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Return (void);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_GetErrorStatues_Return() ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Start)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Start (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Start(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Return)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Return (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_ReadBlock_Return(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Start)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Start (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Start(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Return)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Return (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_ReadBlock_Return(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Start)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Start (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Start(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Return)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Return (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_ReadBlock_Return(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Start)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Start (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Start(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Return)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Return (VoidPtr QsmDstPtr, uint16 Offset, uint16 Length);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_ReadBlock_Return(QsmDstPtr, Offset, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Start)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Start (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Start(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Return)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Return (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_SecureUpdateLogOp_Qsm_WriteBlock_Return(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Start)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Start (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Start(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Return)
#undef Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Return (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_PP_Qsm_DsmBlock_Startup_Flag_Qsm_WriteBlock_Return(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Start)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Start (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Start(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Return)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Return (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_EOLModeGateOp_Qsm_WriteBlock_Return(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Start
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Start)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Start (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Start(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Return
#endif
#if defined(Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Return)
#undef Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Return (ConstVoidPtr QsmDstPtr);
#else
#define Rte_CallHook_Cdm_RP_Qsm_DsmBlock_PartNumber_Sector_Qsm_WriteBlock_Return(QsmDstPtr) ((void)0)
#endif
#if (defined(Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start
#endif
#if defined(Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start)
#undef Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start (P2VAR(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return
#endif
#if defined(Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return)
#undef Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return (P2VAR(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_Cdm_RP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return(data) ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_GetErrorStatus_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_GetErrorStatus_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_GetErrorStatus_Start)
#undef Rte_Runnable_Cdm_Cdm_GetErrorStatus_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_GetErrorStatus_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_GetErrorStatus_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_GetErrorStatus_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_GetErrorStatus_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_GetErrorStatus_Return)
#undef Rte_Runnable_Cdm_Cdm_GetErrorStatus_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_GetErrorStatus_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_GetErrorStatus_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_InitFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_InitFunction_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_InitFunction_Start)
#undef Rte_Runnable_Cdm_Cdm_InitFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_InitFunction_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_InitFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_InitFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_InitFunction_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_InitFunction_Return)
#undef Rte_Runnable_Cdm_Cdm_InitFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_InitFunction_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_InitFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_MainFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_MainFunction_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_MainFunction_Start)
#undef Rte_Runnable_Cdm_Cdm_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_MainFunction_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_MainFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_MainFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_MainFunction_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_MainFunction_Return)
#undef Rte_Runnable_Cdm_Cdm_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_MainFunction_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_MainFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_ReadBlock_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_ReadBlock_Start)
#undef Rte_Runnable_Cdm_Cdm_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_ReadBlock_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_ReadBlock_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_ReadBlock_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_ReadBlock_Return)
#undef Rte_Runnable_Cdm_Cdm_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_ReadBlock_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_ReadBlock_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Start)
#undef Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Return)
#undef Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_VdyReadRamBlockMirror_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Start)
#undef Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Return)
#undef Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_VdyWriteBlockMirror_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_WriteBlock_Start
#endif
#if defined(Rte_Runnable_Cdm_Cdm_WriteBlock_Start)
#undef Rte_Runnable_Cdm_Cdm_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_WriteBlock_Start (void);
#else
#define Rte_Runnable_Cdm_Cdm_WriteBlock_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_Cdm_Cdm_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_Cdm_Cdm_WriteBlock_Return
#endif
#if defined(Rte_Runnable_Cdm_Cdm_WriteBlock_Return)
#undef Rte_Runnable_Cdm_Cdm_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cdm_Cdm_WriteBlock_Return (void);
#else
#define Rte_Runnable_Cdm_Cdm_WriteBlock_Return() ((void)0)
#endif
#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */