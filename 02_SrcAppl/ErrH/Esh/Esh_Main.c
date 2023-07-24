/**
 * \file   Esh_Main.c
 *
 * \brief  The inintial and main function of Esh component.
 *
 * \version refer the Rte_ErrH.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Esh.h>
#include "Esh_Main.h"




/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/
static boolean Esh_Initialized = FALSE;


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
 

/*==================[internal function declarations]========================*/
static FUNC(void, RTE_CODE) Esh_Core_MainFunction(void);



/*==================[external function definitions]=========================*/
/**
 * \functions Esh_InitFunction
 *
 * \brief   The initial function of Esh.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esh_InitFunction (void)
{
    Esh_Initialized = TRUE;
}  /* FUNC(void, RTE_CODE) Esh_InitFunction (void) */


/**
 * \functions Esh_MainFunction
 *
 * \brief   The main function of Esh call in Task_Appl_10ms.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esh_MainFunction (void)
{
    if(TRUE == Esh_Initialized)
    {
        Esh_Core_MainFunction();
	}
	else
	{/*Do nothing*/}

} /* FUNC(void, RTE_CODE) Esh_MainFunction (void) */



/*==================[internal function definitions]=========================*/
/**
 * \functions Esh_Core_MainFunction
 *
 * \brief   The core function of Esh call in Esh_MainFunction.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return , 
 * \comments
 *
 */
static FUNC(void, RTE_CODE) Esh_Core_MainFunction(void)
{
    Esh_Core_OperationCycleMainFunction();
    Esh_Core_EnableConditionMainFunction();
	Esh_Core_FunctionInhibitionMainFunction();
}






