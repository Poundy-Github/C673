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
#include <Rte_StbM.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define StbM_START_SEC_CODE
#include <StbM_MemMap.h>
FUNC(void, RTE_CODE) StbM_MainFunction (void)
{

} /* FUNC(void, RTE_CODE) StbM_MainFunction (void) */

#define StbM_STOP_SEC_CODE
#include <StbM_MemMap.h>

#define StbM_START_SEC_CODE
#include <StbM_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) StbM_GetCurrentTime (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_TimeStampType, AUTOMATIC, RTE_APPL_DATA) timeStampPtr, P2VAR(StbM_UserDataType, AUTOMATIC, RTE_APPL_DATA) userDataPtr)
{
  /* suppress compiler warnings about unused arguments */
  (void)pdav0;
  (void)*timeStampPtr;
  (void)*userDataPtr;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) StbM_GetCurrentTime (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_TimeStampType, AUTOMATIC, RTE_APPL_DATA) timeStampPtr, P2VAR(StbM_UserDataType, AUTOMATIC, RTE_APPL_DATA) userDataPtr) */

#define StbM_STOP_SEC_CODE
#include <StbM_MemMap.h>

#define StbM_START_SEC_CODE
#include <StbM_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) StbM_GetRateDeviation (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_RateDeviationType, AUTOMATIC, RTE_APPL_DATA) rateDeviation)
{
  /* suppress compiler warnings about unused arguments */
  (void)pdav0;
  (void)*rateDeviation;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) StbM_GetRateDeviation (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_RateDeviationType, AUTOMATIC, RTE_APPL_DATA) rateDeviation) */

#define StbM_STOP_SEC_CODE
#include <StbM_MemMap.h>

#define StbM_START_SEC_CODE
#include <StbM_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) StbM_GetTimeBaseStatus (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, RTE_APPL_DATA) syncTimeBaseStatusPtr, P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, RTE_APPL_DATA) offsetTimeBaseStatusPtr)
{
  /* suppress compiler warnings about unused arguments */
  (void)pdav0;
  (void)*syncTimeBaseStatusPtr;
  (void)*offsetTimeBaseStatusPtr;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) StbM_GetTimeBaseStatus (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, RTE_APPL_DATA) syncTimeBaseStatusPtr, P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, RTE_APPL_DATA) offsetTimeBaseStatusPtr) */

#define StbM_STOP_SEC_CODE
#include <StbM_MemMap.h>

#define StbM_START_SEC_CODE
#include <StbM_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) StbM_GetTimeLeap (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_TimeDiffType, AUTOMATIC, RTE_APPL_DATA) timeJump)
{
  /* suppress compiler warnings about unused arguments */
  (void)pdav0;
  (void)*timeJump;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) StbM_GetTimeLeap (StbM_SynchronizedTimeBaseType pdav0, P2VAR(StbM_TimeDiffType, AUTOMATIC, RTE_APPL_DATA) timeJump) */

#define StbM_STOP_SEC_CODE
#include <StbM_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */