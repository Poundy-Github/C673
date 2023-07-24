#ifndef SCHM_PWM_17_GTMCCU6_H
#define SCHM_PWM_17_GTMCCU6_H
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
 * This file is the Module Interlink Header which contains the declarations relevant for that instance of a basic software module.
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
#include <SchM_Pwm_17_GtmCcu6Type.h>

/* ==================[Declaration of functions with external linkage]========= */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
extern FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_HandleNotification (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_HandleNotification (void);
extern FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_PeriodAndDutyUpdate (void);
extern FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_PeriodAndDutyUpdate (void);
#define RTE_STOP_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */