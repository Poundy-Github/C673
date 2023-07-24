/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \version 6.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <TSAutosar.h>     /* EB specific standard types, TS_PARAM_UNUSED() */

#include <Dem_Cfg.h>                             /* declaration of callouts */
#include <NVM.h>
#include <fls.h>
#include <Fee.h>

/* Implementation hint:
 * include necessary Memory-Stack header-files: NvM.h, Ea/Fee.h, Eep/Fls.h */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*------------------[Main callouts]-----------------------------------------*/


#define DEM_START_SEC_APPL_TRIGGERMEMORYSTACK_CODE
#include <Dem_MemMap.h>

FUNC(void, DEM_APPL_CODE) Appl_TriggerMemoryStack(NvM_BlockIdType BlockId)
{
  TS_PARAM_UNUSED(BlockId);

  NvM_RequestResultType Result;
  
  do
   {
	   /*Disable Fls timeout monitoring*/
	   /*In case, the Fls_17_Dmu_MainFunction() is called in a continuous loop*/ 
	   /*as - while(1) or at a rate faster than FlsCallCycle then unintentional*/
	   /*timeouts may occur.*/
	//    Fls_17_Dmu_ControlTimeoutDet(0U);
	   NvM_MainFunction();
	   Fee_MainFunction();
	   Fls_MainFunction();
	   /*Enable Fls timeout monitoring*/
	//    Fls_17_Dmu_ControlTimeoutDet(1U);
	   
	   (void)NvM_GetErrorStatus(BlockId, &Result);
   }
   while (Result == NVM_REQ_PENDING);
  
  /* In case an error occurs, the Dem module will handle it internally.
	* Optionally, inform the application to perform generic error handling.
	*/
   if (Result != NVM_REQ_OK)
   {
	   /* perform customized error handling */
   }
}

#define DEM_STOP_SEC_APPL_TRIGGERMEMORYSTACK_CODE
#include <Dem_MemMap.h>


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
