


/**
 * \file
 *
 * \brief AUTOSAR PbcfgM
 *
 * This file contains the implementation of the AUTOSAR
 * module PbcfgM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef PBCFGM_PBCFG_H
#define PBCFGM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <PbcfgM_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <PbcfgM_CfgTypes.h>
#include <BswM_PBcfg.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS PBCFGM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined PbcfgM_ConfigRoot) /* To prevent double definition */
#error PbcfgM_ConfigRoot already defined
#endif /* (defined PbcfgM_ConfigRoot) */

#define PbcfgM_ConfigRoot (PbcfgM_Config.PbcfgM_RootConfig)



/*==================[type definitions]=======================================*/

typedef struct /* PbcfgM_ConfigLayoutType */ {
    VAR( PbcfgM_ConfigType, TYPEDEF ) PbcfgM_RootConfig;
    VAR( PbcfgM_ModuleConfigEntryType, TYPEDEF ) ConfigEntries[1];
    VAR( BswM_ConfigLayoutType, TYPEDEF ) ConfigBswM;
} PbcfgM_ConfigLayoutType;

typedef CONST( PbcfgM_ConfigLayoutType, PBCFGM_APPL_CONST ) PbcfgM_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define PBCFGM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <PbcfgM_MemMap.h>

extern PbcfgM_ConstConfigLayoutType PbcfgM_Config;

#define PBCFGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <PbcfgM_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* PBCFGM_PBCFG_H */

/*==================[end of file]============================================*/

