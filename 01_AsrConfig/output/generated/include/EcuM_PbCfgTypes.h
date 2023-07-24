


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

#ifndef ECUM_PBCFGTYPES_H
#define ECUM_PBCFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS ECUM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef struct /* EcuM_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information */
    VAR( uint8, TYPEDEF ) DefaultAppMode; /* The referenced OsDefaultAppMode */
    TS_REF2CFG( uint8 )  PtrDriverInitListOne; /* Reference to EcuM_ConfigLayoutType.DriverInitListOne */
    VAR( uint8, TYPEDEF ) NumDriversInitListOne; /* Number of configured drivers in Init Block 1 per variant */
    VAR( uint8, TYPEDEF ) DefaultShutdownTarget; /* The selected EcuM shutdown target */
    VAR( uint8, TYPEDEF ) DefaultMode; /* Mode of the default shutdown target (only required if DefaultShutdownState is equal to ECUM_STATE_SLEEP or ECUM_STATE_RESET). */
} EcuM_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* ECUM_PBCFGTYPES_H */

/*==================[end of file]============================================*/

