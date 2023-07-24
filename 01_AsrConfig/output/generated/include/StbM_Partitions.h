#ifndef STBM_PARTITIONS_H
#define STBM_PARTITIONS_H

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

/* include Rte_StbM_Type.h file before the StbM_Types.h file inclusion,
   in order to assure that re-definitions of StbM types in case Non-EB Rte is used, will not happen */
/* !LINKSTO StbM.dsn.MulticoreDistribution,1 */



/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

#define STBM_START_SEC_CODE
#include <StbM_MemMap.h>

/* !LINKSTO StbM.dsn.MulticoreDistribution,1 */





#define STBM_STOP_SEC_CODE
#include <StbM_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/


#endif /* ifndef STBM_PARTITIONS_H */
