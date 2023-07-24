#ifndef SCHM_BSWMTYPE_H
#define SCHM_BSWMTYPE_H
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
 * on Wed Mar 01 16:47:59 CST 2023. !!!IGNORE-LINE!!!
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
#ifndef RTE_TRANSITION_BSWM_ModeGroupCrossCore
#define RTE_TRANSITION_BSWM_ModeGroupCrossCore 4U
#endif
#ifndef RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_GO_OFF_ONE_D
#define RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_GO_OFF_ONE_D 0U
#endif
#ifndef RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_B
#define RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_B 1U
#endif
#ifndef RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_D
#define RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_D 2U
#endif
#ifndef RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_SWC_CYCLIC_SHUTDOWN_C1
#define RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_SWC_CYCLIC_SHUTDOWN_C1 3U
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
#endif

/* ==================[Types]================================================== */
/* ------------------[mode declaration group types]--------------------------- */
#ifndef RTE_CORE /* if included by basic software module */
#ifndef RTE_MODETYPE_BSWM_ModeGroupCrossCore
#define RTE_MODETYPE_BSWM_ModeGroupCrossCore
typedef VAR(uint8, TYPEDEF) Rte_ModeType_BSWM_ModeGroupCrossCore;
#endif
#ifndef RTE_MODETYPE_DcmEcuReset
#define RTE_MODETYPE_DcmEcuReset
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmEcuReset;
#endif
#ifndef RTE_MODETYPE_DcmCommunicationControl
#define RTE_MODETYPE_DcmCommunicationControl
typedef VAR(uint8, TYPEDEF) Rte_ModeType_DcmCommunicationControl;
#endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
