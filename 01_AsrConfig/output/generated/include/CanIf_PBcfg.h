


/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANIF_PBCFG_H
#define CANIF_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanIf_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanIf_Types_Int.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanIf_Config) /* To prevent double definition */
#error CanIf_Config already defined
#endif /* (defined CanIf_Config) */

#define CanIf_Config (CanIf_ConfigLayout.RootCfg)


#if (defined CanIfInitCfg) /* To prevent double definition */
#error CanIfInitCfg already defined
#endif /* (defined CanIfInitCfg) */

#define CanIfInitCfg (CanIf_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanIf_ConfigLayoutType */ {
    VAR( CanIf_ConfigType, TYPEDEF ) RootCfg;
    VAR( CanIf_TxLPduConfigType, TYPEDEF ) txLPduConfig[53];
    VAR( CanIf_RxLPduConfigType, TYPEDEF ) rxLPduConfig[54];
    VAR( CanIf_HthConfigType, TYPEDEF ) driverHthConfig[2];
    VAR( CanIf_HrhConfigType, TYPEDEF ) driverHrhConfig[52];
    VAR( uint16, TYPEDEF ) hohIdToCanIfIdx[54];
    VAR( CanIf_CanControllerConfigType, TYPEDEF ) canControllerConfig[2];
    VAR( CanIf_CanDriverConfigType, TYPEDEF ) canDriverConfig[1];
    VAR( CanIf_SortedRxLPduConfigType, TYPEDEF ) sortedRxLPduConfig[55];
    VAR( CanIf_CanTrcvChnlConfigType, TYPEDEF ) canTrcvChnlConfig[1];
} CanIf_ConfigLayoutType;

typedef CONST( CanIf_ConfigLayoutType, CANIF_APPL_CONST ) CanIf_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

extern CanIf_ConstConfigLayoutType CanIf_ConfigLayout;

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANIF_PBCFG_H */

/*==================[end of file]============================================*/

