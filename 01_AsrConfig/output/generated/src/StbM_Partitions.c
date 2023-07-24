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

/*==[Includes]================================================================*/




#include <TSAutosar.h>
#include <TSAtomic_Assign.h>

#include <StbM_Trace.h>
#include <StbM.h>        /* AUTOSAR BSW scheduler */

#include <StbM_Partitions.h>

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

#define STBM_START_SEC_CODE
#include <StbM_MemMap.h>


/* !LINKSTO StbM.dsn.MulticoreDistribution,1 */






#define STBM_STOP_SEC_CODE
#include <StbM_MemMap.h>

/*==================[end of file]===========================================*/

