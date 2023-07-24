/**
 * \file
 *
 * \brief AUTOSAR PbcfgM
 *
 * This file contains the implementation of the AUTOSAR
 * module PbcfgM.
 *
 * \version 1.2.22
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <TSAutosar.h>           /* EB specific standard types */
#include <Std_Types.h>           /* AUTOSAR standard types */
#include <PbcfgM_Lcfg.h>         /* Generated configuration */

/* Includes for referenced modules */
#include <BswM.h>


/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/
/* start constants section declaration */
#define PBCFGM_START_SEC_CONST_32
#include <PbcfgM_MemMap.h>

/* Constant variable used to validate post build configuration against link time configuration */
CONST(uint32, PBCFGM_CONST) PbcfgM_LcfgSignature = 3958107115U;

/* stop data section declaration */
#define PBCFGM_STOP_SEC_CONST_32
#include <PbcfgM_MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/* start data section declaration */
#define PBCFGM_START_SEC_CONST_UNSPECIFIED
#include <PbcfgM_MemMap.h>

/* These entries do consider modules which can have more than one instance */
CONSTP2VAR(PbcfgM_IsValidConfigFuncType, PBCFGM_CONST, PBCFGM_APPL_CODE) PbcfgM_IsValidCfgFuncPtr[2] =
{        &BswM_IsValidConfig,
    NULL_PTR
};

/* stop data section declaration */
#define PBCFGM_STOP_SEC_CONST_UNSPECIFIED
#include <PbcfgM_MemMap.h>

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
