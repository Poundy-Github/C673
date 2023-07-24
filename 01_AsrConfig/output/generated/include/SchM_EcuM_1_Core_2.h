#ifndef SCHM_ECUM_1_CORE_2_H
#define SCHM_ECUM_1_CORE_2_H
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
#include <SchM_EcuM_1_Core_2Type.h>

/* ==================[Declaration of functions with external linkage]========= */
#define RTE_START_SEC_OSAPPLICATION_C2_CODE
#include <Rte_MemMap.h>
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Send_EcuM_1_Core_2_EcuM_SlaveCoreReadyPort (uint8 data);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Receive_EcuM_1_Core_2_EcuM_MasterCoreSyncPort (P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(void, RTE_CODE) SchM_Enter_EcuM_1_Core_2_SCHM_ECUM_EXCLUSIVE_AREA_2 (void);
extern FUNC(void, RTE_CODE) SchM_Exit_EcuM_1_Core_2_SCHM_ECUM_EXCLUSIVE_AREA_2 (void);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Receive_EcuM_1_Core_2_EcuM_GetSleepMode (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data);
#define RTE_STOP_SEC_OSAPPLICATION_C2_CODE
#include <Rte_MemMap.h>
#define ECUM_1_Core_2_START_SEC_CODE
#include <EcuM_1_Core_2_MemMap.h>
#ifndef RTE_SCHM_SWCBSW_ECUM_1_CORE_2_MAINFUNCTION
#define RTE_SCHM_SWCBSW_ECUM_1_CORE_2_MAINFUNCTION
extern FUNC(void, ECUM_1_Core_2_CODE) EcuM_1_Core_2_MainFunction (void);
#endif

#ifndef RTE_SCHM_SWCBSW_ECUM_1_CORE_2_UPDATESLEEPMODE
#define RTE_SCHM_SWCBSW_ECUM_1_CORE_2_UPDATESLEEPMODE
extern FUNC(void, ECUM_1_Core_2_CODE) EcuM_1_Core_2_UpdateSleepMode (void);
#endif

#define ECUM_1_Core_2_STOP_SEC_CODE
#include <EcuM_1_Core_2_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
