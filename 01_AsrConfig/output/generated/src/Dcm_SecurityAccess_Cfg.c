/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Dcm.Dsn.File.SecurityAccess.ConfigC,1 */

/*==================[inclusions]=================================================================*/
#include <Dcm_Int.h>
#include <Dcm_API_Cfg.h>                                  /*  Configurable function declarations */
#include <Dcm_DspExternal.h>                          /* Callbacks provided by Central Diag SwC  */

#include <Dcm_SecurityAccess_Cfg.h>
/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Array of configuration information for diagnostic security levels */
CONST(Dcm_SecurityLevelEntryConfigType, DCM_CONST) Dcm_SecurityLevelEntryConfig[1] =
{
/* !LINKSTO Dcm.EB.ServiceAPI.SecurityAccess,1 */
  {
    1000U, /* Delay time */
    0U, /* Delay on boot */
    4U, /* Seed size */
    4U, /* Key size */
    0U,
    /* !LINKSTO SWS_Dcm_91003.Port.NO_ADR.USE_SYNCH_FNC,1 */
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    &Rte_Call_SecurityAccess_SA_Level1_GetSeed,
    NULL_PTR,
    NULL_PTR,
    /* !LINKSTO SWS_Dcm_91004.AS_40.Port.USE_ASYNCH_CS,1 */
    &Rte_Call_SecurityAccess_SA_Level1_CompareKey,
    NULL_PTR,
    /* !LINKSTO SWS_Dcm_01041.Port.USE_SYNCH_INTERFACE,1 */
    /* !LINKSTO SWS_Dcm_00685.Interface.USE_SYNCH_INTERFACE,1 */
    NULL_PTR,
    &Rte_Call_SecurityAccess_SA_Level1_GetSecurityAttemptCounter,
    NULL_PTR,
    &Rte_Call_SecurityAccess_SA_Level1_SetSecurityAttemptCounter,
    3U, /* Attempts until delay */
    /* !LINKSTO SWS_Dcm_00685.Interface.AttemptCounterDisabled.USE_ASYNCH_INTERFACE,1 */
    TRUE, /* Ext. handling of attempt counter */
    FALSE, /* Do not force delay on boot */
    FALSE, /* Do not force infinite delay time */
    DCM_USE_SECURITY_ASYNCH_CLIENT_SERVER,
    DCM_USE_AUTOSAR_40,
    1U, /* Security level */
  },
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
