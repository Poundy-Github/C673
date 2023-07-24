#ifndef SCHM_ECUM_H
#define SCHM_ECUM_H
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
#include <SchM_EcuMType.h>

/* ==================[Declaration of functions with external linkage]========= */
#define RTE_START_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Send_EcuM_EcuM_MasterCoreReadyPort (boolean data);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Receive_EcuM_EcuM_SlaveCoreSyncPort (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Send_EcuM_EcuM_SetSleepMode (uint8 data);
extern FUNC(void, RTE_CODE) SchM_Enter_EcuM_SCHM_ECUM_EXCLUSIVE_AREA_0 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_EcuM_SCHM_ECUM_EXCLUSIVE_AREA_0 (void);
#define RTE_STOP_SEC_OSAPPLICATION_C0_CODE
#include <Rte_MemMap.h>
#define ECUM_START_SEC_CODE
#include <EcuM_MemMap.h>
#ifndef RTE_SCHM_SWCBSW_ECUM_SELECTSHUTDOWNTARGET
#define RTE_SCHM_SWCBSW_ECUM_SELECTSHUTDOWNTARGET
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget (EcuM_StateType target, uint8 mode);
#endif

#ifndef RTE_SCHM_SWCBSW_ECUM_MAINFUNCTION
#define RTE_SCHM_SWCBSW_ECUM_MAINFUNCTION
extern FUNC(void, ECUM_CODE) EcuM_MainFunction (void);
#endif

#define ECUM_STOP_SEC_CODE
#include <EcuM_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
