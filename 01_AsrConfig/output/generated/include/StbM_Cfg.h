#ifndef STBM_CFG_H
#define STBM_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR StbM
 *
 * This file contains the implementation of the AUTOSAR
 * module StbM.
 *
 * \version 4.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/** \addtogroup Synchronized Time Base Manager
 ** @{ */

/*==[Includes]================================================================*/

#include <StbM_Gen_Common.h>

/*==[Macros]==================================================================*/

#if (defined STBM_VERSION_INFO_API)
#error STBM_VERSION_INFO_API is already defined.
#endif
/** \brief Enables/Disables the StbM_GetVersionInfo API. */
#define STBM_VERSION_INFO_API                     STD_OFF
/** \brief Definitions of symbolic names for all the synchronized (time base id < 16) and offset
 ** (time base id >= 16) time base identifiers */
#define StbMConf_StbMSynchronizedTimeBase_StbMSynchronizedTimeBase_0  0U

/** \brief Definitions of symbolic names for all the Notification Customers */

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/


#endif /* ifndef STBM_CFG_H */
