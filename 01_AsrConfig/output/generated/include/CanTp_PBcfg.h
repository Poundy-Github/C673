


/**
 * \file
 *
 * \brief AUTOSAR CanTp
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTp.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H



/*==================[inclusions]=============================================*/

#include <CanTp_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <CanTp_Types_Int.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANTP_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined CanTp_Config) /* To prevent double definition */
#error CanTp_Config already defined
#endif /* (defined CanTp_Config) */

#define CanTp_Config (CanTp_ConfigLayout.RootCfg)


#if (defined CanTpConfig_0) /* To prevent double definition */
#error CanTpConfig_0 already defined
#endif /* (defined CanTpConfig_0) */

#define CanTpConfig_0 (CanTp_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* CanTp_ConfigLayoutType */ {
    VAR( CanTp_ConfigType, TYPEDEF ) RootCfg;
    VAR( CanTp_RxNPduLookupEntryType, TYPEDEF ) RxNPduLookupTable[5];
    VAR( CanTp_RxNPduTableType, TYPEDEF ) RxNPduTable[6];
    VAR( CanTp_RxNSduConfigType, TYPEDEF ) RxNSduConfig[4];
    VAR( CanTp_TxNSduConfigType, TYPEDEF ) TxNSduConfig[2];
    VAR( CanTp_MfCtrConfigType, TYPEDEF ) MfCtrConfig[1];
    VAR( CanTp_TxNPduToTpChannelType, TYPEDEF ) TxNPduToTpChannel[4];
} CanTp_ConfigLayoutType;

typedef CONST( CanTp_ConfigLayoutType, CANTP_APPL_CONST ) CanTp_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTp_MemMap.h>

/** 
CanTp post build config. - Static code accesses this config
 solely via the pointer of type CanTp_ConfigType passed to
 \a CanTp_Init() as parameter.
 */
extern CanTp_ConstConfigLayoutType CanTp_ConfigLayout;

#define CANTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTp_MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANTP_PBCFG_H */

/*==================[end of file]============================================*/

