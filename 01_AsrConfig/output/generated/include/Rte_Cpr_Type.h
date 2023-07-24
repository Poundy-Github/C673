#ifndef RTE_CPR_TYPE_H
#define RTE_CPR_TYPE_H
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
 * This file contains the application-specific types for component type Cpr
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Wed Mar 29 10:30:45 CST 2023. !!!IGNORE-LINE!!!
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
#ifndef E_SIG_STATUS_NONE
#define E_SIG_STATUS_NONE 0U
#endif
#ifndef E_SIG_STATUS_VALID
#define E_SIG_STATUS_VALID 1U
#endif
#ifndef E_SIG_STATUS_INVALID
#define E_SIG_STATUS_INVALID 16U
#endif
#ifndef E_SIG_STATUS_TOUT
#define E_SIG_STATUS_TOUT 17U
#endif
#ifndef E_SIG_STATUS_OUTOFRANGE
#define E_SIG_STATUS_OUTOFRANGE 19U
#endif
#ifndef E_SIG_STATUS_CRC
#define E_SIG_STATUS_CRC 18U
#endif
#ifndef E_SIG_STATUS_ROLLINGCNT
#define E_SIG_STATUS_ROLLINGCNT 20U
#endif
#ifndef E_SIG_STATUS_CRC_AND_ROLLINGCNT
#define E_SIG_STATUS_CRC_AND_ROLLINGCNT 21U
#endif
#ifndef E_SIG_STATUS_MAX
#define E_SIG_STATUS_MAX 255U
#endif
#ifndef E_CPR_MSG_ID_START
#define E_CPR_MSG_ID_START 0U
#endif
#ifndef E_CPR_MSG_ID_GW_50
#define E_CPR_MSG_ID_GW_50 1U
#endif
#ifndef E_CPR_MSG_ID_GW_170
#define E_CPR_MSG_ID_GW_170 2U
#endif
#ifndef E_CPR_MSG_ID_GW_17A
#define E_CPR_MSG_ID_GW_17A 3U
#endif
#ifndef E_CPR_MSG_ID_GW_17E
#define E_CPR_MSG_ID_GW_17E 4U
#endif
#ifndef E_CPR_MSG_ID_GW_180
#define E_CPR_MSG_ID_GW_180 5U
#endif
#ifndef E_CPR_MSG_ID_GW_1C2
#define E_CPR_MSG_ID_GW_1C2 6U
#endif
#ifndef E_CPR_MSG_ID_GW_20B
#define E_CPR_MSG_ID_GW_20B 7U
#endif
#ifndef E_CPR_MSG_ID_GW_24F
#define E_CPR_MSG_ID_GW_24F 8U
#endif
#ifndef E_CPR_MSG_ID_GW_278
#define E_CPR_MSG_ID_GW_278 9U
#endif
#ifndef E_CPR_MSG_ID_GW_288
#define E_CPR_MSG_ID_GW_288 10U
#endif
#ifndef E_CPR_MSG_ID_GW_28B
#define E_CPR_MSG_ID_GW_28B 11U
#endif
#ifndef E_CPR_MSG_ID_GW_2A8
#define E_CPR_MSG_ID_GW_2A8 12U
#endif
#ifndef E_CPR_MSG_ID_GW_2C2
#define E_CPR_MSG_ID_GW_2C2 13U
#endif
#ifndef E_CPR_MSG_ID_GW_2DE
#define E_CPR_MSG_ID_GW_2DE 14U
#endif
#ifndef E_CPR_MSG_ID_GW_3C2
#define E_CPR_MSG_ID_GW_3C2 15U
#endif
#ifndef E_CPR_MSG_ID_VCU_161
#define E_CPR_MSG_ID_VCU_161 16U
#endif
#ifndef E_CPR_MSG_ID_VCU_38A
#define E_CPR_MSG_ID_VCU_38A 17U
#endif
#ifndef E_CPR_MSG_ID_FR_111
#define E_CPR_MSG_ID_FR_111 18U
#endif
#ifndef E_CPR_MSG_ID_FR_112
#define E_CPR_MSG_ID_FR_112 19U
#endif
#ifndef E_CPR_MSG_ID_FR_113
#define E_CPR_MSG_ID_FR_113 20U
#endif
#ifndef E_CPR_MSG_ID_FR_114
#define E_CPR_MSG_ID_FR_114 21U
#endif
#ifndef E_CPR_MSG_ID_FR_115
#define E_CPR_MSG_ID_FR_115 22U
#endif
#ifndef E_CPR_MSG_ID_FR_116
#define E_CPR_MSG_ID_FR_116 23U
#endif
#ifndef E_CPR_MSG_ID_FR_117
#define E_CPR_MSG_ID_FR_117 24U
#endif
#ifndef E_CPR_MSG_ID_FR_118
#define E_CPR_MSG_ID_FR_118 25U
#endif
#ifndef E_CPR_MSG_ID_FR_119
#define E_CPR_MSG_ID_FR_119 26U
#endif
#ifndef E_CPR_MSG_ID_FR_11A
#define E_CPR_MSG_ID_FR_11A 27U
#endif
#ifndef E_CPR_MSG_ID_FR_11B
#define E_CPR_MSG_ID_FR_11B 28U
#endif
#ifndef E_CPR_MSG_ID_FR_11C
#define E_CPR_MSG_ID_FR_11C 29U
#endif
#ifndef E_CPR_MSG_ID_FR_11D
#define E_CPR_MSG_ID_FR_11D 30U
#endif
#ifndef E_CPR_MSG_ID_FR_11E
#define E_CPR_MSG_ID_FR_11E 31U
#endif
#ifndef E_CPR_MSG_ID_FR_11F
#define E_CPR_MSG_ID_FR_11F 32U
#endif
#ifndef E_CPR_MSG_ID_FR_120
#define E_CPR_MSG_ID_FR_120 33U
#endif
#ifndef E_CPR_MSG_ID_FR_136
#define E_CPR_MSG_ID_FR_136 34U
#endif
#ifndef E_CPR_MSG_ID_FR_138
#define E_CPR_MSG_ID_FR_138 35U
#endif
#ifndef E_CPR_MSG_ID_ADC_19B
#define E_CPR_MSG_ID_ADC_19B 36U
#endif
#ifndef E_CPR_MSG_ID_ADC_200
#define E_CPR_MSG_ID_ADC_200 37U
#endif
#ifndef E_CPR_MSG_ID_ADC_345
#define E_CPR_MSG_ID_ADC_345 38U
#endif
#ifndef E_CPR_MSG_ID_ADC_346
#define E_CPR_MSG_ID_ADC_346 39U
#endif
#ifndef E_Cpr_Rx_MsgID_MAX
#define E_Cpr_Rx_MsgID_MAX 255U
#endif
#ifndef E_MSG_STATUS_NONE
#define E_MSG_STATUS_NONE 0U
#endif
#ifndef E_MSG_STATUS_VALID
#define E_MSG_STATUS_VALID 1U
#endif
#ifndef E_MSG_STATUS_INVALID
#define E_MSG_STATUS_INVALID 16U
#endif
#ifndef E_MSG_STATUS_TOUT
#define E_MSG_STATUS_TOUT 17U
#endif
#ifndef E_MSG_STATUS_CRC
#define E_MSG_STATUS_CRC 18U
#endif
#ifndef E_MSG_STATUS_ROLLINGCNT
#define E_MSG_STATUS_ROLLINGCNT 19U
#endif
#ifndef E_MSG_STATUS_CRC_AND_ROLLINGCNT
#define E_MSG_STATUS_CRC_AND_ROLLINGCNT 20U
#endif
#ifndef E_MSG_STATUS_OUTID_RANGE
#define E_MSG_STATUS_OUTID_RANGE 21U
#endif
#ifndef E_MSG_STATUS_MAX
#define E_MSG_STATUS_MAX 255U
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
#endif

/* ------------------[API]---------------------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
/* ------------------[mode declaration group types]--------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
