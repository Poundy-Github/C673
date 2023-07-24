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
 * on Thu May 25 10:40:45 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_ModM.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define ModM_START_SEC_CODE
#include <ModM_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) ModM_GetCurrentOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode)
{
  /* suppress compiler warnings about unused arguments */
  (void)*mode;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) ModM_GetCurrentOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode) */

#define ModM_STOP_SEC_CODE
#include <ModM_MemMap.h>

#define ModM_START_SEC_CODE
#include <ModM_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) ModM_GetNextOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode)
{
  /* suppress compiler warnings about unused arguments */
  (void)*mode;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) ModM_GetNextOperationMode (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) mode) */

#define ModM_STOP_SEC_CODE
#include <ModM_MemMap.h>

#define ModM_START_SEC_CODE
#include <ModM_MemMap.h>
FUNC(void, RTE_CODE) ModM_MainFunction (void)
{

} /* FUNC(void, RTE_CODE) ModM_MainFunction (void) */

#define ModM_STOP_SEC_CODE
#include <ModM_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
