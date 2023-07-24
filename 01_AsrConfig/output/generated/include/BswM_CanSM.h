
#ifndef BSWM_CANSM_H
#define BSWM_CANSM_H

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

#include <CanSM_BswM.h>      /* Include CanSM public API  */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

/** \brief Indicates current state (Called by CanSM).
 **
 ** This function is called by CanSM to indicate its current state.
 **
 ** Precondition: None
 **
 ** \param[in]    Network      - The CAN channel that the indicated state
 **                              corresponds to.
 **               CurrentState - The current state of the CAN channel.
 ** \param[inout] None.
 ** \param[out]   None.
 **
 ** \ServiceID{5}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */

extern FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState
(
NetworkHandleType Network,
CanSM_BswMCurrentStateType CurrentState
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
#endif /* ifndef BSWM_CANSM_H */
/*==================[end of file]============================================*/

/*==================[end of file]============================================*/

