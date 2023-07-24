/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.4.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.4.3
 * on Mon Mar 14 18:08:21 CST 2022. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_Esm_Core2.h>
//extern KL15_RequestShutDown_Fun_C1();
/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
FUNC(void, RTE_CODE) Esm_Core2_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) Esm_Core2_InitFunction (void) */

FUNC(void, RTE_CODE) Esm_Core2_MainFunction (void)
{
	//KL15_RequestShutDown_Fun_C1();
} /* FUNC(void, RTE_CODE) Esm_Core2_MainFunction (void) */

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
