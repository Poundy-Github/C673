/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \version 6.4.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <TSAutosar.h>     /* EB specific standard types, TS_PARAM_UNUSED() */

#include <Dem_Cfg.h>                             /* declaration of callouts */

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

  /* Implement the mechanism to synchronously trigger memory stack main functions
   * within this callout function.
   *
   * There are multiple possibilities for integration of ECU Startup/Shutdown and memory stack main functions.
   * The project-specific integration requirements usually limit the solution space.
   *
   * EB recommends the following integration approach which serves as basis:
   * + This approach MUST be extended according to all additional integration requirements!
   *   Consider the "Integration Note" in the configuration parameter description
   *   of DemCallbackMemStackMainFuncTrigger.
   * + Provide one single memory stack task, e.g. SchMMemTask_<NN>ms, which shall:
   *   - have HIGHER PRIORITY than the task which triggers BswM_MainFunction(), to avoid preemption
   *   - have the number of activation set to 2, to allow activation from BswM_MainFunction()
   *   - contain only the memory stack main functions
   * + Allow triggering of the memory stack task from the following contexts:
   *   - NvM ReadAll/WriteAll and this callout during ECU Startup/Shutdown via BswM_MainFunction():
   *     -- Set BswMModeRequestPort's for NvM_ReadAll() and NvM_WriteAll() to 'BSWM_DEFERRED'
   *     -- Set BswMModeRequestPort's for Dem_Init() and Dem_Shutdown() to 'BSWM_DEFERRED'
   *     -- Use ActivateTask()
   *   - Cyclic activation as required by NvM/Fee/Fls/Ea/Eep via Rte (SchM)
   *
   * Related EB Integration requirements:
   * - lim.NvM.EB_INTREQ_NvM_0001 / lim.Fee.EB_INTREQ_Fee_0001:
   *   call NvM/Ea/Fee main functions only from same task context
   *
   * Code EXAMPLE for indirectly triggering the memory stack from the Dem:
   *
   *  FUNC(void, DEM_APPL_CODE) Appl_TriggerMemoryStack(NvM_BlockIdType BlockId)
   *  {
   *    NvM_RequestResultType Result;
   *
   *    do
   *    {
   *      ActivateTask(SchMMemTask_<NN>ms);
   *      NvM_GetErrorStatus(BlockId, &Result);
   *    }
   *    while (Result == NVM_REQ_PENDING);
   *
   *    // In case an error occurs, the Dem module will handle it internally.
   *    // Optionally, inform the application to let it perform some generic
   *    // error handling:
   *    if (Result != NVM_REQ_OK)
   *    {
   *      // perform customized error handling
   *    }
   *  }
   *
   */
}

#define DEM_STOP_SEC_APPL_TRIGGERMEMORYSTACK_CODE
#include <Dem_MemMap.h>


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
