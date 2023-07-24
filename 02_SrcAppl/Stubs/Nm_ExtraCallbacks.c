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

/*==================[inclusions]============================================*/

#include <Nm_Trace.h>
#include <TSAutosar.h>     /* EB specific standard types, TS_PARAM_UNUSED() */
#include "CanNm_Api.h"
#include <Nm_Cbk.h>        /* Extra callback functions of Nm */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/


/*----------------------[Nm_PduRxIndication]----------------------------------*/


/*----------------------[Nm_RepeatMessageIndication]--------------------------*/


/*----------------------[Nm_TxTimeoutException]-------------------------------*/
void Nm_TxTimeoutException
(
  NetworkHandleType nmNetworkHandle
)
{
	TS_PARAM_UNUSED(nmNetworkHandle);
}


/*----------------------[Nm_CoordReadyToSleepIndication]-------------------------------*/

/*----------------------[Nm_StateChangeNotificationCallout]-------------------------------*/
FUNC(void, NM_CODE) Nm_RepeatMessageIndication
(
  uint8 nmNetworkHandle
)
{
	TS_PARAM_UNUSED(nmNetworkHandle);
}


void PduR_CanNmTxConfirmation (uint8 test_num)
{
	TS_PARAM_UNUSED(test_num);
}


void PduR_CanNmTriggerTransmit(uint8 instIdx, PduInfoType *PduUserInfo)
{
	;
}



/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
