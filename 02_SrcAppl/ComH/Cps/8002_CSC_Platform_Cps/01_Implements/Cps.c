/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.4.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.4.3
 * on Sun Jan 23 05:28:49 CST 2022. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_Cps.h>
#include "Cps_Core.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
#if (DBG_CPS_DEBUG_ENABLE == STD_ON)
uint32 Debug_Cps_MainFunction_Counter = 0x00;
#endif
/*==================[internal function declarations]========================*/


/*==================[external function definitions]=========================*/
/**
 * \functions Cps_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Cps_InitFunction (void)
{
	Cps_Core_InitFunction();
}

/**
 * \functions Cps_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Cps_MainFunction (void)
{
#if (DBG_CPS_DEBUG_ENABLE == STD_ON)
    Debug_Cps_MainFunction_Counter++;
#endif
	Cps_Core_MainFunction();

#if(CPS_USER_MAIN_FUNCTION_ENABLE == STD_ON)
  Cps_UserMainFunction();
#endif
}
