


/**
 * \file
 *
 * \brief AUTOSAR CanNm
 *
 * This file contains the implementation of the AUTOSAR
 * module CanNm.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANNM_PBCFG_H
#define CANNM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanNm_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanNm_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANNM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanNm_Config_0) /* To prevent double definition */
#error CanNm_Config_0 already defined
#endif /* (defined CanNm_Config_0) */

#define CanNm_Config_0 (CanNm_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanNm_ConfigLayoutType */ {
    VAR( CanNm_ConfigType, TYPEDEF ) RootCfg;
} CanNm_ConfigLayoutType;

typedef CONST( CanNm_ConfigLayoutType, CANNM_APPL_CONST ) CanNm_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>

extern CanNm_ConstConfigLayoutType CanNm_ConfigLayout;

#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANNM_PBCFG_H */

/*==================[end of file]============================================*/

