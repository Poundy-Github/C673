/**
 * \file   ModM.c
 *
 * \brief  
 *
 * \version refer the ModM_Cfg.h.
 * 
 * \copyright  2021 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_ModM.h>
#include "Qsm_Lcfg.h" 
#include "ModM.h"

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
#define ModM_START_SEC_VAR_INIT_LOCAL
#include <ModM_MemMap.h>

static boolean ModM_InitOnce = (Boolean)FALSE;

#define ModM_STOP_SEC_VAR_INIT_LOCAL
#include <ModM_MemMap.h>

#define ModM_START_SEC_VAR_CLEARED_LOCAL
#include <ModM_MemMap.h>

static s_ModM_InstStruct_t s_ModM_handle;

#define ModM_STOP_SEC_VAR_CLEARED_LOCAL
#include <ModM_MemMap.h>


/*==================[internal function declarations]========================*/



/*==================[external function definitions]=========================*/
#define ModM_START_SEC_CODE
#include <ModM_MemMap.h>
/**
 * \functions ModM_InitFunction
 *
 * \brief This is the initial function of ModM.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments  The below initial function shall be call in Action list "BswM_ActLst_StartupTwoB",
 * after Qsm_ReadAll().
 */
FUNC(void, RTE_CODE) ModM_InitFunction(const s_ModM_Config_t * const ConfigPtr)  //Run in start up sequence.
{
    static e_ModM_Operationmode_t Localmode = ModM_Normal;

	if((Boolean)TRUE != ModM_InitOnce)
	{
	    /*SWRS_MFC5J3_SysM_24: Only the Ecu Startup,The software shall implement Ecu Mode Switch according the stored EcuOperationMode from MemServ. */
        Localmode = (e_ModM_Operationmode_t)GET_QSM_EcuOperationMode();/* PRQA S 3469,4342,2 # 2023-07-17 Z.J.L:not any affect: accept */
		
        if((Localmode >= ModM_Normal) && (Localmode <= ModM_Factory))
        {
            SET_ModM_CurrentState(Localmode);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:not any affect: accept */
	    }
	    else //If the Operation mode is invalid, shall be set deafult mode is normalmode.
	    {
            SET_ModM_CurrentState(ModM_Normal);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:not any affect: accept */
	    }
	
		for(uint8 i = 0; i < (uint8)(MODM_MODEINDEX); i++)
		{
		    /*SWRS_MFC5J3_SysM_19: The software shall implement the Ecu Operation Mode switch according the Mode Switch Request.*/
		    e_ModM_Operationmode_t currentmode = GET_ModM_CurrentState();/* PRQA S 3469,4342,2 # 2023-07-17 Z.J.L:not any affect: accept */
			
			if(ConfigPtr != NULL_PTR)
			{
                if(ConfigPtr[i].State == currentmode)
                {
                    ConfigPtr[i].SetOp();
                }
				else
				{
				    MODM_DET_REPORTERROR(MODM_API_ID_INIT, MODM_ERROR_CODE_STATE_ERR);
				}
			}
			else
			{
                MODM_DET_REPORTERROR(MODM_API_ID_INIT, MODM_ERROR_CODE_NULL_PTR);
			}
		}
		
		ModM_InitOnce = (Boolean)TRUE;
	}
}

/**
 * \functions ModM_MainExec
 *
 * \brief This is the main function of ModM.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments
 */
FUNC(void, RTE_CODE) ModM_MainExec(void) //Core0_10ms
{  
    static e_ModM_Operationmode_t Nextmode = ModM_Normal;
	
	if((Boolean)FALSE != ModM_InitOnce)
	{
        /* SWRS_MFC5J3_SysM_23: When Ecu is running,the external Mode Switch Request not immediate switch. */
	    Nextmode = (e_ModM_Operationmode_t)GET_QSM_EcuOperationMode();/* PRQA S 3469,4342,2 # 2023-07-17 Z.J.L:not any affect: accept */
		
		e_ModM_Operationmode_t currentmode = GET_ModM_CurrentState();/* PRQA S 3469,2 # 2023-07-17 Z.J.L:not any affect: accept */

		if((Nextmode >= ModM_Normal) && (Nextmode <= ModM_Factory))	
        {
            SET_ModM_NextState(Nextmode);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:not any affect: accept */
		}
		else
		{
		    SET_ModM_NextState(ModM_Normal);/* PRQA S 3432,2 # 2023-07-17 Z.J.L:not any affect: accept */
		}
		/*Note: if need send opertion mode to Soc ,suuggest the requests as trigger event.*/
	    /* If Mcu received the Ecu Operation Mode,the Mcu shall sent the Ecu Operation Mode(Next mode) requirement to J3 via SPI.*/
        RTE_CALL_SENDOPMODE(currentmode, Nextmode);
	    /* When Ecu start up and the mcu and J3 has been handshake,Mcu shall sent the Current Ecu Operation Mode(Current) to J3. */
	}
	else
	{
        MODM_DET_REPORTERROR(MODM_API_ID_MAIN, MODM_ERROR_CODE_UNINIT);
	}
}

/**
 * \functions ModM_u_GetCurrentMode
 *
 * \brief This is the function to get current operation mode.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments
 */
FUNC(Std_ReturnType, RTE_CODE) ModM_u_GetCurrentMode(uint8 * const mode)
{
    Std_ReturnType u_Retval = E_OK;

    *mode = (uint8)GET_ModM_CurrentState();/* PRQA S 3469,2 # 2023-07-17 Z.J.L:not any affect: accept */

	return u_Retval;
}

/**
 * \functions ModM_u_GetNextMode
 *
 * \brief This is the function to get next operation mode.
 *
 ** \param[in] none, 
 *
 ** \param[out] none,
 **                
 ** \return RTE_E_OK, 
 * \comments
 */
FUNC(Std_ReturnType, RTE_CODE) ModM_u_GetNextMode(uint8 * const mode)
{
    Std_ReturnType u_Retval = E_OK;

    *mode = (uint8)GET_ModM_NextState();/* PRQA S 3469,2 # 2023-07-17 Z.J.L:not any affect: accept */

	return u_Retval;
}

#define ModM_STOP_SEC_CODE
#include <ModM_MemMap.h>

/*==================[internal function definitions]=========================*/





