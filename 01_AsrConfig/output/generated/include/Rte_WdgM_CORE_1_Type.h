#ifndef RTE_WDGM_CORE_1_TYPE_H
#define RTE_WDGM_CORE_1_TYPE_H
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
 * This file contains the application-specific types for component type WdgM_CORE_1
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
#include <Rte_Type.h>

/* ==================[Macros]================================================= */
/* ------------------[enumeration constants]---------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#ifndef WdgMConf_WdgMCheckpoint_WdgMCheckpoint_AS_HM
#define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_AS_HM 0U
#endif
#ifndef WdgMConf_WdgMCheckpoint_WdgMCheckpoint_SWC_MONITOR
#define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_SWC_MONITOR 0U
#endif
#ifndef WdgMConf_WdgMCheckpoint_WdgMCheckpoint_CameraTemp
#define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_CameraTemp 0U
#endif
#ifndef WdgMConf_WdgMCheckpoint_WdgMCheckpoint_ConfigReg
#define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_ConfigReg 0U
#endif
#ifndef WdgMConf_WdgMCheckpoint_WdgMCheckpoint_FS_MAIN
#define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_FS_MAIN 0U
#endif
#ifndef WdgMConf_WdgMCheckpoint_WdgMCheckpoint_FS_ADC
#define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_FS_ADC 0U
#endif
#endif

/* ------------------[range definitions]-------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ------------------[invalid values]----------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ------------------[mode declarations]-------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#ifndef RTE_TRANSITION_WdgMMode
#define RTE_TRANSITION_WdgMMode 5U
#endif
#ifndef RTE_MODE_WdgMMode_SUPERVISION_DEACTIVATED
#define RTE_MODE_WdgMMode_SUPERVISION_DEACTIVATED 0U
#endif
#ifndef RTE_MODE_WdgMMode_SUPERVISION_EXPIRED
#define RTE_MODE_WdgMMode_SUPERVISION_EXPIRED 1U
#endif
#ifndef RTE_MODE_WdgMMode_SUPERVISION_FAILED
#define RTE_MODE_WdgMMode_SUPERVISION_FAILED 2U
#endif
#ifndef RTE_MODE_WdgMMode_SUPERVISION_OK
#define RTE_MODE_WdgMMode_SUPERVISION_OK 3U
#endif
#ifndef RTE_MODE_WdgMMode_SUPERVISION_STOPPED
#define RTE_MODE_WdgMMode_SUPERVISION_STOPPED 4U
#endif
#endif

/* ------------------[API]---------------------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
/* ------------------[mode declaration group types]--------------------------- */
#ifndef RTE_CORE /* if included by software component */
#ifndef RTE_MODETYPE_WdgMMode
#define RTE_MODETYPE_WdgMMode
typedef VAR(uint8, TYPEDEF) Rte_ModeType_WdgMMode;
#endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */