#ifndef BSWM_NM_H
#define BSWM_NM_H

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

/*==================[includes]===============================================*/

#include <ComStack_Types.h>

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

FUNC(void, BSWM_CODE) BswM_NmIf_CarWakeUpIndication
(
NetworkHandleType Network
);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_NM_H */
/*==================[end of file]============================================*/

/*==================[end of file]============================================*/
