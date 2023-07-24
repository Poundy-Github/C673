/**
 * \file
 *
 * \brief AUTOSAR CanTSyn
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTSyn.
 *
 * \version 3.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/*==================[inclusions]============================================*/

#include <CanTSyn_Cfg.h> /* Generated pre-compile configuration. */



/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/* !LINKSTO CanTSyn.dsn.PrecompileTimeConfig,1 */


    

#define CANTSYN_START_SEC_CONST_8
#include <CanTSyn_MemMap.h>

static CONST(CanTSyn_DataIDListType, CANTSYN_APPL_CONST) CanTSyn_DataIdListSyncValues_CanTSynGlobalTimeDomain_0[16] =
{
 1U,
 2U,
 3U,
 5U,
 7U,
 11U,
 13U,
 17U,
 19U,
 23U,
 29U,
 31U,
 37U,
 41U,
 43U,
 47U,
};

#define CANTSYN_STOP_SEC_CONST_8
#include <CanTSyn_MemMap.h>

#define CANTSYN_START_SEC_CONST_8
#include <CanTSyn_MemMap.h>

static CONST(CanTSyn_DataIDListType, CANTSYN_APPL_CONST) CanTSyn_DataIdListFupValues_CanTSynGlobalTimeDomain_0[16] =
{
 2U,
 3U,
 4U,
 6U,
 8U,
 12U,
 14U,
 18U,
 20U,
 24U,
 30U,
 32U,
 38U,
 42U,
 44U,
 48U,
};

#define CANTSYN_STOP_SEC_CONST_8
#include <CanTSyn_MemMap.h>




#define CANTSYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTSyn_MemMap.h>



    
CONST(CanTSyn_TimeSlaveDomainConfigType, CANTSYN_APPL_CONST) CanTSyn_TimeSlaveConfig[1] =
{

  /* CanTSynGlobalTimeDomain_0 */
  {
    &CanTSyn_DataIdListSyncValues_CanTSynGlobalTimeDomain_0[0],
    &CanTSyn_DataIdListFupValues_CanTSynGlobalTimeDomain_0[0],
    20U, /* RxFollowUpOffsetInterval (Slave) */
    0U, /* StbMSynchronizedTimeBaseIdentifier */
    0U, /* TimeDomainId */
    CANTSYN_CRC_OPTIONAL, /* RxCrcValidated */
    6U, /* SequenceCounterJumpWidth */
    1U, /* ExtendedMessage */
  },
};

#define CANTSYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTSyn_MemMap.h>


/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/


