#ifndef RTE_HWABS_H
#define RTE_HWABS_H
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
 * This file contains Rte component declarations for component type HwAbs
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
#include <TSMem.h>
#include <Rte_HwAbs_Type.h>
#include <Rte_HwAbs_Hook.h>
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
#if (!defined(RTE_RUNNABLEAPI_Cdd_HeartbeatDet_InitFunction)) && (!defined(RTE_RUNNABLEAPI_Cdd_HeartbeatDet_MainFunction)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Om_PWR_2V9_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Om_RST_B)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Om_VMERRB)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_FS84_FS0B)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_FS84_INTB)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_FS84_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5024_RST)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5204_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5204_PG1)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5204_PG3)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_EWARN)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_FS0B)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_INTB)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_RST)) && (!defined(RTE_RUNNABLEAPI_HwAbs_InitFunction))
#define Rte_Write_PP_HwAbs_AdcValue_AdcValue Rte_Write_HwAbs_PP_HwAbs_AdcValue_AdcValue
#endif
#endif

/* ------------------[port handle API mapping]-------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#define RTE_E_CSI_IoLevelOp_E_NOT_OK 1U
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
#ifndef RTE_CORE /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_HwAbs, TYPEDEF, RTE_CONST) Rte_Instance;
#endif

/* ==================[Definition of variables with external linkage]========== */
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
extern CONST(Rte_CDS_HwAbs, RTE_CONST) Rte_Instance_HwAbs;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>
extern CONSTP2CONST(Rte_CDS_HwAbs, RTE_CONST, RTE_CONST) Rte_Inst_HwAbs;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>

/* ==================[Declaration of functions with external linkage]========= */
/* ------------------[declaration of runnable entities]----------------------- */
#define HwAbs_START_SEC_CODE
#include <HwAbs_MemMap.h>
extern FUNC(void, RTE_CODE) Cdd_HeartbeatDet_InitFunction (void);

extern FUNC(void, RTE_CODE) Cdd_HeartbeatDet_MainFunction (void);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Om_PWR_2V9_PG (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Om_RST_B (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Om_VMERRB (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_FS84_FS0B (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_FS84_INTB (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_FS84_PG (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF5024_RST (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF5204_PG (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF5204_PG1 (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF5204_PG3 (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF8200_EWARN (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF8200_FS0B (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF8200_INTB (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF8200_PG (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(Std_ReturnType, RTE_CODE) HwAbs_GetIoLevel_Pmic_PF8200_RST (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) level);

extern FUNC(void, RTE_CODE) HwAbs_InitFunction (void);

extern FUNC(void, RTE_CODE) HwAbs_MainFunction (void);

#define HwAbs_STOP_SEC_CODE
#include <HwAbs_MemMap.h>

/* ------------------[declaration of API functions provided by Rte]----------- */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
#if (!defined(RTE_RUNNABLEAPI_Cdd_HeartbeatDet_InitFunction)) && (!defined(RTE_RUNNABLEAPI_Cdd_HeartbeatDet_MainFunction)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Om_PWR_2V9_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Om_RST_B)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Om_VMERRB)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_FS84_FS0B)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_FS84_INTB)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_FS84_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5024_RST)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5204_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5204_PG1)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF5204_PG3)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_EWARN)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_FS0B)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_INTB)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_PG)) && (!defined(RTE_RUNNABLEAPI_HwAbs_GetIoLevel_Pmic_PF8200_RST)) && (!defined(RTE_RUNNABLEAPI_HwAbs_InitFunction))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwAbs_PP_HwAbs_AdcValue_AdcValue (P2CONST(s_AdcValue_t, AUTOMATIC, RTE_APPL_DATA) data);
#endif

#define RTE_STOP_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>

/* ------------------[declaration of API functions provided by other Appl]---- */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
