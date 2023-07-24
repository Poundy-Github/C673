


/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANSM_PBCFG_H
#define CANSM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanSM_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanSM_Types_Int.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_OFF
#define TS_PB_CFG_PTR_CLASS CANSM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanSM_Config_0) /* To prevent double definition */
#error CanSM_Config_0 already defined
#endif /* (defined CanSM_Config_0) */

#define CanSM_Config_0 (CanSM_ConfigLayout.RootCfg)


#if (defined CanSMConfiguration) /* To prevent double definition */
#error CanSMConfiguration already defined
#endif /* (defined CanSMConfiguration) */

#define CanSMConfiguration (CanSM_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanSM_ConfigLayoutType */ {
    VAR( CanSM_ConfigType, TYPEDEF ) RootCfg;
    VAR( CanSMNetworkType, TYPEDEF ) CanSM_Net[2];
    VAR( CanSMControllerType, TYPEDEF ) CanSM_Ctrl[2];
} CanSM_ConfigLayoutType;

typedef CONST( CanSM_ConfigLayoutType, CANSM_APPL_CONST ) CanSM_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>

extern CanSM_ConstConfigLayoutType CanSM_ConfigLayout;

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANSM_PBCFG_H */

/*==================[end of file]============================================*/

