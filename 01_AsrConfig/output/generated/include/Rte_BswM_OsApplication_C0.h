#ifndef RTE_BSWM_OSAPPLICATION_C0_H
#define RTE_BSWM_OSAPPLICATION_C0_H
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
 * This file contains Rte component declarations for component type BswM_OsApplication_C0
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Thu Apr 13 13:33:29 CST 2023. !!!IGNORE-LINE!!!
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
#include <Rte_BswM_OsApplication_C0_Type.h>
#include <Rte_BswM_OsApplication_C0_Hook.h>
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
#if (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_TxReq)) && (!defined(RTE_RUNNABLEAPI_RES_MainFunction))
#define Rte_Mode_ModeNotificationPort_BswMSwcModeNotification_Comco_RxReq_proto_MDG_IPduGroupSwitch Rte_Mode_BswM_OsApplication_C0_ModeNotificationPort_BswMSwcModeNotification_Comco_RxReq_proto_MDG_IPduGroupSwitch
#endif
#if (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_RxReq)) && (!defined(RTE_RUNNABLEAPI_RES_MainFunction))
#define Rte_Mode_ModeNotificationPort_BswMSwcModeNotification_Comco_TxReq_proto_MDG_IPduGroupSwitch Rte_Mode_BswM_OsApplication_C0_ModeNotificationPort_BswMSwcModeNotification_Comco_TxReq_proto_MDG_IPduGroupSwitch
#endif
#if (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_RxReq)) && (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_TxReq))
#define Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode
#define Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup
#define Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup
#define Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl
#endif
#endif

/* ------------------[port handle API mapping]-------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
#ifndef RTE_CORE /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_BswM_OsApplication_C0, TYPEDEF, RTE_CONST) Rte_Instance;
#endif

/* ==================[Definition of variables with external linkage]========== */
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
extern CONST(Rte_CDS_BswM_OsApplication_C0, RTE_CONST) Rte_Instance_BswM_OsApplication_C0;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_8
#include <Rte_MemMap.h>
#define RTE_START_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>
extern CONSTP2CONST(Rte_CDS_BswM_OsApplication_C0, RTE_CONST, RTE_CONST) Rte_Inst_BswM_OsApplication_C0;
#define RTE_STOP_SEC_OSAPPLICATION_C0_CONST_UNSPECIFIED
#include <Rte_MemMap.h>

/* ==================[Declaration of functions with external linkage]========= */
/* ------------------[declaration of runnable entities]----------------------- */
#define BswM_OsApplication_C0_START_SEC_CODE
#include <BswM_OsApplication_C0_MemMap.h>
extern FUNC(void, RTE_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_RxReq (void);

extern FUNC(void, RTE_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_TxReq (void);

#define BswM_OsApplication_C0_STOP_SEC_CODE
#include <BswM_OsApplication_C0_MemMap.h>

/* ------------------[declaration of API functions provided by Rte]----------- */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
#if (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_TxReq)) && (!defined(RTE_RUNNABLEAPI_RES_MainFunction))
extern FUNC(uint8, RTE_CODE) Rte_Mode_BswM_OsApplication_C0_ModeNotificationPort_BswMSwcModeNotification_Comco_RxReq_proto_MDG_IPduGroupSwitch (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) previousMode, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) nextMode);
#endif
#if (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_RxReq)) && (!defined(RTE_RUNNABLEAPI_RES_MainFunction))
extern FUNC(uint8, RTE_CODE) Rte_Mode_BswM_OsApplication_C0_ModeNotificationPort_BswMSwcModeNotification_Comco_TxReq_proto_MDG_IPduGroupSwitch (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) previousMode, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) nextMode);
#endif
#if (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_RxReq)) && (!defined(RTE_RUNNABLEAPI_RE_BswMSwcModeNotification_Comco_TxReq))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode (uint8 mode);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup (uint8 mode);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup (uint8 mode);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl (uint8 mode);
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
