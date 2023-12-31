#ifndef RTE_SED_H
#define RTE_SED_H
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
 * This file contains Rte component declarations for component type Sed
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Wed Jun 07 14:41:23 CST 2023. !!!IGNORE-LINE!!!
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
#include <Rte_Sed_Type.h>
#include <Rte_Sed_Hook.h>
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
#if !defined(RTE_RUNNABLEAPI_Sed_InitFunction)
#define Rte_Call_RP_Sdc_SendInterface_Eth_EthCableFault_Read Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthCableFault_Read
#define Rte_Call_RP_Sdc_SendInterface_Eth_EthCrcError_Read Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthCrcError_Read
#define Rte_Call_RP_Sdc_SendInterface_Eth_EthIcmpError_Read Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthIcmpError_Read
#define Rte_Call_RP_Sdc_SendInterface_Eth_EthSQI_Read Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthSQI_Read
#define Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read Rte_Call_Sed_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read
#endif
#endif

/* ------------------[port handle API mapping]-------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#define RTE_E_CSI_Sdc_SendInterface_Diag_E_OK 0U
#define RTE_E_CSI_Sdc_SendInterface_Eth_E_OK 0U
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
#ifndef RTE_CORE /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_Sed, TYPEDEF, RTE_CONST) Rte_Instance;
#endif

/* ==================[Definition of variables with external linkage]========== */
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
extern CONST(Rte_CDS_Sed, RTE_CONST) Rte_Instance_Sed;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>
extern CONSTP2CONST(Rte_CDS_Sed, RTE_CONST, RTE_CONST) Rte_Inst_Sed;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>

/* ==================[Declaration of functions with external linkage]========= */
/* ------------------[declaration of runnable entities]----------------------- */
#define Sed_START_SEC_CODE
#include <Sed_MemMap.h>
extern FUNC(void, RTE_CODE) Sed_InitFunction (void);

extern FUNC(void, RTE_CODE) Sed_MainFunction (void);

#define Sed_STOP_SEC_CODE
#include <Sed_MemMap.h>

/* ------------------[declaration of API functions provided by Rte]----------- */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
#if !defined(RTE_RUNNABLEAPI_Sed_InitFunction)
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthCableFault_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthCrcError_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthIcmpError_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sed_RP_Sdc_SendInterface_Eth_EthSQI_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) data, uint16_t length);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sed_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read (uint8_t group_id, P2VAR(void_t, AUTOMATIC, RTE_APPL_DATA) socDiagInfo);
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
