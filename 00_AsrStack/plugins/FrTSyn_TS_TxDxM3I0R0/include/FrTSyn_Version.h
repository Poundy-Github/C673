#ifndef FRTSYN_VERSION_H
#define FRTSYN_VERSION_H
/**
 * \file
 *
 * \brief AUTOSAR FrTSyn
 *
 * This file contains the implementation of the AUTOSAR
 * module FrTSyn.
 *
 * \version 3.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined FRTSYN_VENDOR_ID)
#error FRTSYN_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define FRTSYN_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined FRTSYN_MODULE_ID)
#error FRTSYN_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define FRTSYN_MODULE_ID         163U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined FRTSYN_AR_RELEASE_MAJOR_VERSION)
#error FRTSYN_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define FRTSYN_AR_RELEASE_MAJOR_VERSION     4U

#if (defined FRTSYN_AR_RELEASE_MINOR_VERSION)
#error FRTSYN_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define FRTSYN_AR_RELEASE_MINOR_VERSION     6U

#if (defined FRTSYN_AR_RELEASE_REVISION_VERSION)
#error FRTSYN_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define FRTSYN_AR_RELEASE_REVISION_VERSION  0U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined FRTSYN_SW_MAJOR_VERSION)
#error FRTSYN_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define FRTSYN_SW_MAJOR_VERSION             3U

#if (defined FRTSYN_SW_MINOR_VERSION)
#error FRTSYN_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define FRTSYN_SW_MINOR_VERSION             0U

#if (defined FRTSYN_SW_PATCH_VERSION)
#error FRTSYN_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define FRTSYN_SW_PATCH_VERSION             0U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef FRTSYN_VERSION_H */
/*==================[end of file]============================================*/
