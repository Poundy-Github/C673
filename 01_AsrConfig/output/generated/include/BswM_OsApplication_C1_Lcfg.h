#ifndef BSWM_OSAPPLICATION_C1_LCFG_H
#define BSWM_OSAPPLICATION_C1_LCFG_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_h,1 */
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

#if (defined BSWM_NUM_LOGICAL_EXPRESSIONS_OSAPPLICATION_C1)
#error BSWM_NUM_LOGICAL_EXPRESSIONS_OSAPPLICATION_C1 is already defined
#endif
#define BSWM_NUM_LOGICAL_EXPRESSIONS_OSAPPLICATION_C1 6U

#if (defined BSWM_NUM_ACTIONS_OSAPPLICATION_C1)
#error BSWM_NUM_ACTIONS_OSAPPLICATION_C1 is already defined
#endif
#define BSWM_NUM_ACTIONS_OSAPPLICATION_C1 6U

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#define BSWM_1_OsApplication_C1_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C1_MemMap.h>

extern BswM_PartitionContextType BswM_OsApplication_C1_Context;

extern BswMGenericRequestPortType BswMGenericRequest_OsApplication_C1_PortTable[1];

#define BSWM_1_OsApplication_C1_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C1_MemMap.h>

/*==================[external function definitions]=========================*/

#define BSWM_1_OsApplication_C1_START_SEC_CODE
#include <BswM_1_OsApplication_C1_MemMap.h>

extern FUNC(void, BSWM_CODE) BswM_LT_OsApplication_C1_Init(void);

#define BSWM_1_OsApplication_C1_STOP_SEC_CODE
#include <BswM_1_OsApplication_C1_MemMap.h>

/*==================[internal function definitions]=========================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_OSAPPLICATION_C1_LCFG_H */
/*==================[end of file]============================================*/

