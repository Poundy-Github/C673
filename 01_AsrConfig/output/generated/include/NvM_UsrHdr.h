/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \version 6.17.24
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef NVM_USR_HDR_H
#define NVM_USR_HDR_H

/* this just contains the inclusion directive for the user supplied header */

/*==================[inclusions]============================================*/

#include <Dem_NvMCbk.h>
#include <Dem.h>
#include <Cdm.h>
#include <Cdm_Cfg.h>

/*==================[macros]================================================*/
#if (defined NVM_CRYPTO_HOOKS)
#error NVM_CRYPTO_HOOKS is already defined
#endif
/** \brief Defines whether the Crypto hooks are enabled
 **
 **        Range:
 **        STD_ON  : Crypto Hooks are enabled
 **        STD_OFF : Crypto Hooks are disabled
 **/
#define NVM_CRYPTO_HOOKS           STD_OFF

/*==================[external function declarations]========================*/

/*==================[ end of external function declarations]================*/

#endif /* ifndef NVM_USR_HDR_H */
/*==================[end of file NvM_Cfg.h]==================================*/
