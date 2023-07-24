


/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ECUM_PBCFG_H
#define ECUM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <EcuM_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <EcuM_PbCfgTypes.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS ECUM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined EcuM_Config_0) /* To prevent double definition */
#error EcuM_Config_0 already defined
#endif /* (defined EcuM_Config_0) */

#define EcuM_Config_0 (EcuM_Configuration.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* EcuM_ConfigLayoutType */ {
    VAR( EcuM_ConfigType, TYPEDEF ) RootCfg;
    VAR( uint8, TYPEDEF ) DriverInitListOne[14]; /* Configured Drivers List in Init Block 1 */
} EcuM_ConfigLayoutType;

typedef CONST( EcuM_ConfigLayoutType, ECUM_APPL_CONST ) EcuM_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <EcuM_MemMap.h>

extern EcuM_ConstConfigLayoutType EcuM_Configuration;

#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <EcuM_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* ECUM_PBCFG_H */

/*==================[end of file]============================================*/

