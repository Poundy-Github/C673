#ifndef RTE_COMCO_H
#define RTE_COMCO_H
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
 * This file contains Rte component declarations for component type Comco
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Sun Apr 23 14:33:46 CST 2023. !!!IGNORE-LINE!!!
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
#include <Rte_Comco_Type.h>
#include <Rte_Comco_Hook.h>
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
#if (!defined(RTE_RUNNABLEAPI_Comco_u_NMWakupFlag_Read)) && (!defined(RTE_RUNNABLEAPI_Comco_u_nmCurrentState_Read)) && (!defined(RTE_RUNNABLEAPI_Comco_u_nmPreviousState_Read))
#define Rte_Read_RP_Com_SRI_EspVehSpd_DE_EspVehSpd Rte_Read_Comco_RP_Com_SRI_EspVehSpd_DE_EspVehSpd
#define Rte_Read_RP_Com_SRI_EspVehSpdVld_DE_EspVehSpdVld Rte_Read_Comco_RP_Com_SRI_EspVehSpdVld_DE_EspVehSpdVld
#define Rte_Read_RP_VoltMonI_SRI_DisableCommunication_DE_VoltMonI_DisableCommunication Rte_Read_Comco_RP_VoltMonI_SRI_DisableCommunication_DE_VoltMonI_DisableCommunication
#define Rte_Call_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue Rte_Call_Comco_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue
#define Rte_Call_RP_ComM_UserRequest_Public_RequestComMode Rte_Call_Comco_RP_ComM_UserRequest_Public_RequestComMode
#define Rte_Call_RP_ComM_UserRequest_Private_RequestComMode Rte_Call_Comco_RP_ComM_UserRequest_Private_RequestComMode
#define Rte_Switch_PP_Comco_MSI_RxPduGroupSwitch_proto_MDG_IPduGroupSwitch Rte_Switch_Comco_PP_Comco_MSI_RxPduGroupSwitch_proto_MDG_IPduGroupSwitch
#define Rte_Switch_PP_Comco_MSI_TxPduGroupSwitch_proto_MDG_IPduGroupSwitch Rte_Switch_Comco_PP_Comco_MSI_TxPduGroupSwitch_proto_MDG_IPduGroupSwitch
#define Rte_Mode_RP_BswM_MSI_DiagComControlMode_proto_DcmCommunicationControl Rte_Mode_Comco_RP_BswM_MSI_DiagComControlMode_proto_DcmCommunicationControl
#endif
#endif

/* ------------------[port handle API mapping]-------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#define RTE_E_CSI_NMWakupFlag_E_NOT_OK 1U
#define RTE_E_CSI_NMWakupFlag_E_OK 0U
#define RTE_E_CSI_nmCurrentState_E_NOT_OK 1U
#define RTE_E_CSI_nmCurrentState_E_OK 0U
#define RTE_E_CSI_nmPreviousState_E_NOT_OK 1U
#define RTE_E_CSI_nmPreviousState_E_OK 0U
#define RTE_E_ComM_UserRequest_E_NOT_OK 1U
#define RTE_E_ComM_UserRequest_E_MODE_LIMITATION 2U
#define RTE_E_ComM_UserRequest_E_MULTIPLE_PNC_ASSIGNED 3U
#define RTE_E_ComM_UserRequest_E_NO_PNC_ASSIGNED 4U
#define RTE_E_CSI_EvAdc_GetValue_E_NOK 1U
#define RTE_E_CSI_EvAdc_GetValue_E_OK 0U
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
#ifndef RTE_CORE /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_Comco, TYPEDEF, RTE_CONST) Rte_Instance;
#endif

/* ==================[Definition of variables with external linkage]========== */
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
extern CONST(Rte_CDS_Comco, RTE_CONST) Rte_Instance_Comco;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>
extern CONSTP2CONST(Rte_CDS_Comco, RTE_CONST, RTE_CONST) Rte_Inst_Comco;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>

/* ==================[Declaration of functions with external linkage]========= */
/* ------------------[declaration of runnable entities]----------------------- */
#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
extern FUNC(void, RTE_CODE) Comco_MainFunction (void);

extern FUNC(Std_ReturnType, RTE_CODE) Comco_u_NMWakupFlag_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag);

extern FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmCurrentState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState);

extern FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmPreviousState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_PreNmState);

#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

/* ------------------[declaration of API functions provided by Rte]----------- */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
#if (!defined(RTE_RUNNABLEAPI_Comco_u_NMWakupFlag_Read)) && (!defined(RTE_RUNNABLEAPI_Comco_u_nmCurrentState_Read)) && (!defined(RTE_RUNNABLEAPI_Comco_u_nmPreviousState_Read))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Comco_RP_Com_SRI_EspVehSpd_DE_EspVehSpd (P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Comco_RP_Com_SRI_EspVehSpdVld_DE_EspVehSpdVld (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Comco_RP_VoltMonI_SRI_DisableCommunication_DE_VoltMonI_DisableCommunication (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Comco_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue (P2VAR(float32_t, AUTOMATIC, RTE_APPL_DATA) value);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Comco_RP_ComM_UserRequest_Public_RequestComMode (ComM_ModeType ComMode);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Comco_RP_ComM_UserRequest_Private_RequestComMode (ComM_ModeType ComMode);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Comco_PP_Comco_MSI_RxPduGroupSwitch_proto_MDG_IPduGroupSwitch (uint8 mode);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Comco_PP_Comco_MSI_TxPduGroupSwitch_proto_MDG_IPduGroupSwitch (uint8 mode);
extern FUNC(uint8, RTE_CODE) Rte_Mode_Comco_RP_BswM_MSI_DiagComControlMode_proto_DcmCommunicationControl (void);
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
