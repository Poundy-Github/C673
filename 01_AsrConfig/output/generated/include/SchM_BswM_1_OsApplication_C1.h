#ifndef SCHM_BSWM_1_OSAPPLICATION_C1_H
#define SCHM_BSWM_1_OSAPPLICATION_C1_H
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
 * on Wed Mar 01 16:47:59 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ==================[Includes]=============================================== */
#include <SchM_BswM_1_OsApplication_C1Type.h>

/* ==================[Declaration of functions with external linkage]========= */
#define RTE_START_SEC_OSAPPLICATION_C1_CODE
#include <Rte_MemMap.h>
extern FUNC(uint8, RTE_CODE) SchM_Mode_BswM_1_OsApplication_C1_BswM_ModeNotificationPort_OsApplication_C1_BswMModeRequestPort_Slave (void);
extern FUNC(void, RTE_CODE) SchM_Enter_BswM_1_OsApplication_C1_SCHM_BSWM_EXCLUSIVE_AREA (void);
extern FUNC(void, RTE_CODE) SchM_Exit_BswM_1_OsApplication_C1_SCHM_BSWM_EXCLUSIVE_AREA (void);
#define RTE_STOP_SEC_OSAPPLICATION_C1_CODE
#include <Rte_MemMap.h>
#define BSWM_1_OsApplication_C1_START_SEC_CODE
#include <BswM_1_OsApplication_C1_MemMap.h>
#ifndef RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_GO_OFF_ONE_D
#define RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_GO_OFF_ONE_D
extern FUNC(void, BSWM_1_OsApplication_C1_CODE) BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D (void);
#endif

#ifndef RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_STARTUP_TWO_B
#define RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_STARTUP_TWO_B
extern FUNC(void, BSWM_1_OsApplication_C1_CODE) BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B (void);
#endif

#ifndef RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_STARTUP_TWO_D
#define RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_STARTUP_TWO_D
extern FUNC(void, BSWM_1_OsApplication_C1_CODE) BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D (void);
#endif

#ifndef RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_SWC_CYCLIC_SHUTDOWN_C1
#define RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MRPFUNC_BSWMMODEREQUESTPORT_SLAVE_BSWM_SWC_CYCLIC_SHUTDOWN_C1
extern FUNC(void, BSWM_1_OsApplication_C1_CODE) BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1 (void);
#endif

#ifndef RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MAINFUNCTION
#define RTE_SCHM_SWCBSW_BSWM_1_OSAPPLICATION_C1_MAINFUNCTION
extern FUNC(void, BSWM_1_OsApplication_C1_CODE) BswM_1_OsApplication_C1_MainFunction (void);
#endif

#define BSWM_1_OsApplication_C1_STOP_SEC_CODE
#include <BswM_1_OsApplication_C1_MemMap.h>

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */