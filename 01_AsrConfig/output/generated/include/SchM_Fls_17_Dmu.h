#ifndef SCHM_FLS_17_DMU_H
#define SCHM_FLS_17_DMU_H
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
#include <SchM_Fls_17_DmuType.h>

/* ==================[Declaration of functions with external linkage]========= */
#define FLS_17_DMU_START_SEC_CODE
#include <Fls_17_Dmu_MemMap.h>
#ifndef RTE_SCHM_SWCBSW_FLS_17_DMU_MAINFUNCTION
#define RTE_SCHM_SWCBSW_FLS_17_DMU_MAINFUNCTION
extern FUNC(void, FLS_17_DMU_CODE) Fls_17_Dmu_MainFunction (void);
#endif

#define FLS_17_DMU_STOP_SEC_CODE
#include <Fls_17_Dmu_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
