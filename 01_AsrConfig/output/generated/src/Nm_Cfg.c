/**
 * \file
 *
 * \brief AUTOSAR Nm
 *
 * This file contains the implementation of the AUTOSAR
 * module Nm.
 *
 * \version 5.12.9
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Nm247_Refine,1 */

/*==================[inclusions]============================================*/



#include <Nm_Cfg.h>
#include <Nm.h>                 /* Nm public API (own interface) */
#include <Nm_Int.h>             /* Nm internal symbols (own interface) */


#include <SchM_Nm.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#define NM_START_SEC_CONST_UNSPECIFIED
#include <Nm_MemMap.h>



#define NM_STOP_SEC_CONST_UNSPECIFIED
#include <Nm_MemMap.h>

#define NM_START_SEC_CONST_8
#include <Nm_MemMap.h>

/* Array which translates between the NetworkHandle and the Nm channel index  */
CONST(uint8, NM_CONST) Nm_ChanIdxFromNetworkHandle[NM_MAX_CHANNELID + 1U] =
{
  0U, /* Nm channel index of NetworkHandle 0 */
};


#define NM_STOP_SEC_CONST_8
#include <Nm_MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
