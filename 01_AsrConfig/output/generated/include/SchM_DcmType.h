#ifndef SCHM_DCMTYPE_H
#define SCHM_DCMTYPE_H
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
 * This file is the Module Interlink Types Header which contains the data types relevant for the instance of a basic software module.
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Tue Feb 28 15:54:31 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ==================[Includes]=============================================== */
#include <Rte_Type.h>

/* ==================[Macros]================================================= */
/* ------------------[enumeration constants]---------------------------------- */
#ifndef RTE_CORE /* if included by basic software module */
#endif

/* ------------------[mode declarations]-------------------------------------- */
#ifndef RTE_CORE /* if included by basic software module */
#ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#define RTE_TRANSITION_DcmDiagnosticSessionControl 0U
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_ALL_SESSION_LEVEL
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_ALL_SESSION_LEVEL 255U
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION 1U
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_SESSION 3U
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_PROGRAMMING_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_PROGRAMMING_SESSION 2U
#endif
#ifndef RTE_TRANSITION_DcmEcuReset
#define RTE_TRANSITION_DcmEcuReset 7U
#endif
#ifndef RTE_MODE_DcmEcuReset_EXECUTE
#define RTE_MODE_DcmEcuReset_EXECUTE 0U
#endif
#ifndef RTE_MODE_DcmEcuReset_HARD
#define RTE_MODE_DcmEcuReset_HARD 1U
#endif
#ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER 2U
#endif
#ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER 3U
#endif
#ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#define RTE_MODE_DcmEcuReset_KEYONOFF 4U
#endif
#ifndef RTE_MODE_DcmEcuReset_NONE
#define RTE_MODE_DcmEcuReset_NONE 5U
#endif
#ifndef RTE_MODE_DcmEcuReset_SOFT
#define RTE_MODE_DcmEcuReset_SOFT 6U
#endif
#ifndef RTE_TRANSITION_DcmRapidPowerShutdown
#define RTE_TRANSITION_DcmRapidPowerShutdown 2U
#endif
#ifndef RTE_MODE_DcmRapidPowerShutdown_DISABLE_RAPIDPOWERSHUTDOWN
#define RTE_MODE_DcmRapidPowerShutdown_DISABLE_RAPIDPOWERSHUTDOWN 0U
#endif
#ifndef RTE_MODE_DcmRapidPowerShutdown_ENABLE_RAPIDPOWERSHUTDOWN
#define RTE_MODE_DcmRapidPowerShutdown_ENABLE_RAPIDPOWERSHUTDOWN 1U
#endif
#ifndef RTE_TRANSITION_DcmCommunicationControl
#define RTE_TRANSITION_DcmCommunicationControl 12U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM 6U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM 2U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM 10U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM 7U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM 3U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM 11U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM 5U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM 1U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM 9U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM 4U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM 0U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM 8U
#endif
#ifndef RTE_TRANSITION_DcmControlDTCSetting
#define RTE_TRANSITION_DcmControlDTCSetting 2U
#endif
#ifndef RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING
#define RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING 0U
#endif
#ifndef RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING
#define RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING 1U
#endif
#endif

/* ==================[Types]================================================== */
/* ------------------[mode declaration group types]--------------------------- */
#ifndef RTE_CORE /* if included by basic software module */
#ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmDiagnosticSessionControl;
#endif
#ifndef RTE_MODETYPE_DcmEcuReset
#define RTE_MODETYPE_DcmEcuReset
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmEcuReset;
#endif
#ifndef RTE_MODETYPE_DcmRapidPowerShutdown
#define RTE_MODETYPE_DcmRapidPowerShutdown
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmRapidPowerShutdown;
#endif
#ifndef RTE_MODETYPE_DcmCommunicationControl
#define RTE_MODETYPE_DcmCommunicationControl
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmCommunicationControl;
#endif
#ifndef RTE_MODETYPE_DcmControlDTCSetting
#define RTE_MODETYPE_DcmControlDTCSetting
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmControlDTCSetting;
#endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
