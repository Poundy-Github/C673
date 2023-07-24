/**
 * \file   Esh_FunctionInhibit.c
 *
 * \brief  Trigger FIM of Dem Event to inhibited algo function.
 *
 * \version refer the Rte_Esh.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Esh.h>
#include "Esh_Main.h"


/*==================[external constants definition]=========================*/



/*==================[internal constants definition]=========================*/




/*==================[external data definition]==============================*/



/*==================[internal data definition]==============================*/





/*==================[internal function declarations]========================*/
#if ((defined ESH_FEAT_SETOPERATIONCYCLE_ENABLE) && (ESH_FEAT_SETOPERATIONCYCLE_ENABLE == STD_ON))
static FUNC(void, RTE_CODE) Esh_Core_OperationCycleMainLogic(void);
#endif


/*==================[external function definitions]=========================*/
/**
 * \functions Esh_Core_OperationCycleMainFunction
 *
 * \brief   This is the main function of oprtation cycle.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esh_Core_OperationCycleMainFunction(void)
{
#if ((defined ESH_FEAT_SETOPERATIONCYCLE_ENABLE) && (ESH_FEAT_SETOPERATIONCYCLE_ENABLE == STD_ON))
	Esh_Core_OperationCycleMainLogic();
#endif
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Esh_Core_OperationCycleMainLogic
 *
 * \brief   This is the main logic of Operation cycle.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none, 
 * \comments
 *
 */
#if ((defined ESH_FEAT_SETOPERATIONCYCLE_ENABLE) && (ESH_FEAT_SETOPERATIONCYCLE_ENABLE == STD_ON))
static FUNC(void, RTE_CODE) Esh_Core_OperationCycleMainLogic(void)
{
    uint8 ui8_WakeupFlag = 0x00u;
	static boolean b_CycleStart = TRUE;
	static boolean b_CycleEnd = FALSE;
	
	/*Raed wakeup flag from RTE.*/
    (void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_WakeupFlag);
	
	if(0x01u == ui8_WakeupFlag)
	{
	    if(TRUE == b_CycleStart)
	    {   
	        /*Only set operation cycle is one time in startup sequence. */
	        b_CycleStart = FALSE;
			b_CycleEnd = TRUE;
	        (void)Rte_Call_RP_Dem_OpCycle_OperationCycle_IGN_SetOperationCycleState(DEM_CYCLE_STATE_START);
	    }
		else
		{/*Do nothing*/}
	}
	else/*When the network mode transmit to Bussleep,will be set wakeup flag to 0x00.*/
	{   
	    if(TRUE == b_CycleEnd)
		{
		    b_CycleEnd = FALSE;
			b_CycleStart = TRUE;
			/*If the set operation cycle to end point, shall be record any event in memory.*/
            (void)Rte_Call_RP_Dem_OpCycle_OperationCycle_IGN_SetOperationCycleState(DEM_CYCLE_STATE_END);
	    }
	}
}
#endif



























