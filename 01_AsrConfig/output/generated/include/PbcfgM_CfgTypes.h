


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

#ifndef PBCFGM_CFGTYPES_H
#define PBCFGM_CFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS PBCFGM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef struct /* PbcfgM_ModuleConfigEntryType */ {
    TS_REF2CFG( void )  ConfigRef; /* Reference to the associated module configuration */
    VAR( uint16, TYPEDEF ) ModuleId; /* ID identifying a module */
    VAR( uint16, TYPEDEF ) InstanceId; /* ID identifying a certain instance of module */
} PbcfgM_ModuleConfigEntryType;

/** 
\brief Root configuration of the PbcfgM
 */
typedef struct /* PbcfgM_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Platform signature for validation */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Validate the post build configuration against the link time configuration */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Validate the post build configuration against the precompile time configuration */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Validate the post build configuration against the module version number */
    VAR( uint16, TYPEDEF ) numConfigEntry; /* Number of modules which are initialized by the PbcfgM module */
    TS_REF2CFG( PbcfgM_ModuleConfigEntryType )  ConfigEntryRef; /* Reference to the first module entry */
} PbcfgM_ConfigType;


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

#endif /* PBCFGM_CFGTYPES_H */

/*==================[end of file]============================================*/

