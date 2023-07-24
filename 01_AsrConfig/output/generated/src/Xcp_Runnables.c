/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \version 2.12.2
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.9 (advisory)
 * An object should be defined at block scope if its identifier only appears in a single function
 *
 * Reason:
 * Using the variable at function scope would require making the variable static, which
 * would prevent allocation to a predefined memory section.
 *
 */
/*==================[inclusions]============================================*/

#include <Xcp_Trace.h>
#include <Std_Types.h>        /* AUTOSAR standard types */
#include <TSAutosar.h>        /* EB specific standard types */

#include <Xcp.h>              /* Module public API */
#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
#include <Xcp_Int.h>          /* Internal types */
#include <TSMem.h>            /* EB memory functions */
#include <Xcp_Cbk.h>          /* Callbacks and callouts of Xcp */

#if (XCP_RESOURCE_CAL_PAG == XCP_RESOURCE_CAL_PAG_MASK)
#include <Xcp_UserCallouts.h> /* User Callout Function declarations */
#endif

#include <SchM_Xcp.h>         /* Needed for exclusive area definition */
/*==================[macros]================================================*/


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define XCP_START_SEC_VAR_8
#include <Xcp_MemMap.h>



/*==================[external data]=========================================*/


#define XCP_STOP_SEC_VAR_8
#include <Xcp_MemMap.h>

/*==================[external function definitions]=========================*/





/*==================[internal function definitions]=========================*/

#endif /* ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) ) */
/*==================[end of file]===========================================*/
