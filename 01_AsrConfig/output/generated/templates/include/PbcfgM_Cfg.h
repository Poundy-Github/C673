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
#ifndef PBCFGM_CFG_H
#define PBCFGM_CFG_H

/* This file contains all target independent public configuration declarations
 * for the AUTOSAR module PbcfgM. */


/*==================[inclusions]============================================*/
#include <Std_Types.h>

/*==================[General]===============================================*/

#if (defined PBCFGM_DEV_ERROR_DETECT)
#error PBCFGM_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating if development error detection is activated for
 ** the PbcfgM */
#define PBCFGM_DEV_ERROR_DETECT STD_ON


#if (defined PBCFGM_RELOCATABLE_CFG_ENABLE)
#error PBCFGM_RELOCATABLE_CFG_ENABLE is already defined
#endif
/** \brief Enable the relocation feature */
#define PBCFGM_RELOCATABLE_CFG_ENABLE STD_ON

/*==================[macros]================================================*/
#if (defined PBCFGM_PUBLIC_INFO_SIGNATURE)
#error PBCFGM_PUBLIC_INFO_SIGNATURE is already defined
#endif

/** \brief Link time verification value */
#define PBCFGM_PUBLIC_INFO_SIGNATURE 3637186157U

#if (defined PBCFGM_CFG_SIGNATURE)
#error PBCFGM_CFG_SIGNATURE is already defined
#endif

/** \brief Compile time configuration signature
**
** Used to validate the post build configuration against the compile time configuration */
#define PBCFGM_CFG_SIGNATURE 2582618360U /* Compile time verification value */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PBCFGM_CFG_H */
/*==================[end of file]===========================================*/
