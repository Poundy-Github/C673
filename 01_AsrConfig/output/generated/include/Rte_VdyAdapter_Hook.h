#ifndef RTE_VDYADAPTER_HOOK_H
#define RTE_VDYADAPTER_HOOK_H
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
 * This file contains Rte hook declarations for the software component type VdyAdapter
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Thu Mar 16 15:33:14 CST 2023. !!!IGNORE-LINE!!!
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
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Start
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Start)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Start (P2CONST(AlgoCompState_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Return
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Return)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Return (P2CONST(AlgoCompState_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_AlgoCompState_AlgoCompState_Return(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Start
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Start)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Start (P2CONST(VDYErrors_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Return
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Return)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Return (P2CONST(VDYErrors_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyErrors_VdyErrors_Return(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Start
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Start)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Start (P2CONST(VDYEstCurves_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Return
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Return)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Return (P2CONST(VDYEstCurves_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyEstCurves_VdyEstCurves_Return(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start (P2CONST(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return (P2CONST(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData_Return(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Start
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Start)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Start (P2CONST(VDYOffsets_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Return
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Return)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Return (P2CONST(VDYOffsets_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VdyOffsets_VdyOffsets_Return(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Start
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Start)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Start
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Start (P2CONST(VehDyn_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Start(data) ((void)0)
#endif
#if (defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Return
#endif
#if defined(Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Return)
#undef Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Return
extern FUNC(void, RTE_APPL_CODE) Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Return (P2CONST(VehDyn_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_WriteHook_VdyAdapter_PP_VdyAdapter_VehDyn_VehDyn_Return(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Start
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Start)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Start (P2VAR(BaseCtrlData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Start(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Return
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Return)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Return (P2VAR(BaseCtrlData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Fcu_BaseCtrlData_BaseCtrlData_Return(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start)
#undef Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start (P2VAR(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Start(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return)
#undef Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return (P2VAR(VDYNvIoData_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Cdm_VdyInputNvMData_VdyNvMInOutData_Return(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Start
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Start)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Start (P2VAR(VehPar_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Start(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Return
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Return)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Return (P2VAR(VehPar_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Fcu_VehPar_VehPar_Return(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Start
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Start)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Start
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Start (P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Start(data) ((void)0)
#endif
#if (defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Return
#endif
#if defined(Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Return)
#undef Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Return
extern FUNC(void, RTE_APPL_CODE) Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Return (P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA) data);
#else
#define Rte_ReadHook_VdyAdapter_RP_Fcu_VehSig_VehSig_Return(data) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Start
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Start)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Start (P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_APPL_DATA) RequestResultPtr);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Start(RequestResultPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Return
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Return)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Return (P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_APPL_DATA) RequestResultPtr);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_GetErrorStatus_Return(RequestResultPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Start
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Start)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Start (NvM_DstPtrType DstPtr);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Start(DstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Return
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Return)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Return (NvM_DstPtrType DstPtr);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_ReadBlock_Return(DstPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Start
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Start)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Start (boolean BlockChanged);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Start(BlockChanged) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Return
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Return)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Return (boolean BlockChanged);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_SetRamBlockStatus_Return(BlockChanged) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Start
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Start)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Start (NvM_SrcPtrType SrcPtr);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Start(SrcPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Return
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Return)
#undef Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Return (NvM_SrcPtrType SrcPtr);
#else
#define Rte_CallHook_VdyAdapter_RP_NvM_VdyBlockOperation_WriteBlock_Return(SrcPtr) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Start
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Start)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Start (uint32_t VirtualAddress, uint32_t FunctionId, VoidPtr_t Data, uint32_t Length);
#else
#define Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Start(VirtualAddress, FunctionId, Data, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Return
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Return)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Return (uint32_t VirtualAddress, uint32_t FunctionId, VoidPtr_t Data, uint32_t Length);
#else
#define Rte_CallHook_VdyAdapter_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData_Return(VirtualAddress, FunctionId, Data, Length) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Start
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Start)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Start
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Start (uint16_t TaskId);
#else
#define Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Start(TaskId) ((void)0)
#endif
#if (defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Return
#endif
#if defined(Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Return)
#undef Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Return
extern FUNC(void, RTE_APPL_CODE) Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Return (uint16_t TaskId);
#else
#define Rte_CallHook_VdyAdapter_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle_Return(TaskId) ((void)0)
#endif
#if (defined(Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Start
#endif
#if defined(Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Start)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Start (void);
#else
#define Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Return
#endif
#if defined(Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Return)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Return (void);
#else
#define Rte_Runnable_VdyAdapter_VdyAdapter_InitFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Start
#endif
#if defined(Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Start)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Start (void);
#else
#define Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Return
#endif
#if defined(Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Return)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Return (void);
#else
#define Rte_Runnable_VdyAdapter_VdyAdapter_MainFunction_Return() ((void)0)
#endif
#if (defined(Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Start)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Start
#endif
#if defined(Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Start)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Start
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Start (void);
#else
#define Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Start() ((void)0)
#endif
#if (defined(Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Return)) && (RTE_VFB_TRACE == FALSE)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Return
#endif
#if defined(Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Return)
#undef Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Return
extern FUNC(void, RTE_APPL_CODE) Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Return (void);
#else
#define Rte_Runnable_VdyAdapter_VdyAdapter_VdyExec_Return() ((void)0)
#endif
#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
