/**
 * \file Sed_Stubs.c
 *
 * \brief
 *
 * \version refer the Sed_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "Sed_Stubs.h"
#include "Rte_Sed.h"

/*==================[internal variables definitions]=========================*/
#if(SED_USERFUNCTION_ENABLE == STD_ON)
/**
 * \functions Sed_UserInitFunction
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
FUNC(void, RTE_CODE) Sed_UserInitFunction (void)
{

} 

/**
 * \functions Sed_UserMainFunction
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
FUNC(void, RTE_CODE) Sed_UserMainFunction (void)
{

} 
#endif

/*==================[external function definitions]=========================*/
boolean Sed_Cot_TestFailed_BattVoltTooLow(void)
{
	boolean ret = FALSE;
	
	return ret;
}

boolean Sed_Cot_TestFailed_BattVoltTooHigh(void)
{
	boolean ret = FALSE;
	
	return ret;
}

