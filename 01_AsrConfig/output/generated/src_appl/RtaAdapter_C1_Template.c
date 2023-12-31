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
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Tue Feb 28 15:54:31 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_RtaAdapter_C1.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define RtaAdapter_C1_START_SEC_CODE
#include <RtaAdapter_C1_MemMap.h>
FUNC(void, RTE_CODE) RtaAdapter_C1_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) RtaAdapter_C1_InitFunction (void) */

#define RtaAdapter_C1_STOP_SEC_CODE
#include <RtaAdapter_C1_MemMap.h>

#define RtaAdapter_C1_START_SEC_CODE
#include <RtaAdapter_C1_MemMap.h>
FUNC(void, RTE_CODE) RtaAdapter_C1_MainFunction (void)
{
  uint16_t arg_Call_TaskId = 0U;
  Std_ReturnType ret_Call;

  ret_Call = Rte_Call_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle(arg_Call_TaskId);
  (void)ret_Call;

} /* FUNC(void, RTE_CODE) RtaAdapter_C1_MainFunction (void) */

#define RtaAdapter_C1_STOP_SEC_CODE
#include <RtaAdapter_C1_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
