#ifndef SCHM_NVM_H
#define SCHM_NVM_H
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
#include <SchM_NvMType.h>

/* ==================[Declaration of functions with external linkage]========= */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
extern FUNC(void, RTE_CODE) SchM_Enter_NvM_SCHM_NVM_EXCLUSIVE_AREA_0 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_NvM_SCHM_NVM_EXCLUSIVE_AREA_0 (void);
#define RTE_STOP_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
#define NVM_START_SEC_CODE
#include <NvM_MemMap.h>
#ifndef RTE_SCHM_SWCBSW_NVM_MAINFUNCTION
#define RTE_SCHM_SWCBSW_NVM_MAINFUNCTION
extern FUNC(void, NVM_CODE) NvM_MainFunction (void);
#endif

#define NVM_STOP_SEC_CODE
#include <NvM_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
