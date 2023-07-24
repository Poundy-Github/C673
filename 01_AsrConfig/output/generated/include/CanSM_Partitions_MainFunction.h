/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 3.7.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


#ifndef CANSM_PARTITIONS_MINFUNCTION_H
#define CANSM_PARTITIONS_MINFUNCTION_H

 /* mgcc62 Deviation List
 *
 * MGCC62-1) Deviated Rule: redundant-decls
 * warning: redundant redeclaration of 'CanSM_MainFunction' [-Wredundant-decls]
 *
 * Reason:
 * MainFunction needs to be exported through <module>_SchM.h for Rte usage.
 * Rte also exports the function in SchM_<module>.h, redeclaring the function.
 */

/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */

/*==================[macros]================================================*/
/* !LINKSTO CanSM.EB.CanSMDistributedChannels_MainFunctions,1 */

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/



#endif 
/*==================[end of file]===========================================*/

