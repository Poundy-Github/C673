/**
 * \file 
 *
 * \brief 
 *
 * \version refer the VoltageMonitor_Cfg.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "VoltageMonitor.h"
#include <Rte_VoltMonI.h>
#include "Esm.h"


/*==================[internal data definition]==============================*/


/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/

/*==================[external data definition]==============================*/
#define VoltMonI_START_SEC_CODE
#include <VoltMonI_MemMap.h>
/**
 ** \functions VoltMonI_StateChangeNotificationCallout
 **
 ** \brief  
 **
 ** \param[in] VoltMonI_PreviousState 
 **
 ** \param[in] VoltMonI_CurrentState
 **
 ** \return none
 **
 ** \comments 
 **
 **/
#if (VOLTAGEMONITOR_STATE_CHANGE_NOTIFICATION_CALLOUT == STD_ON)
FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_StateChangeNotificationCallout
(
  const e_VoltMonI_voltageState_t VoltMonI_PreviousState,
  const e_VoltMonI_voltageState_t VoltMonI_CurrentState
)
{
    TS_PARAM_UNUSED(VoltMonI_PreviousState);/* PRQA S 3119,3469,2 # 2023-07-17 Z.J.L:Do not remove if used, not any affect: accept */
    TS_PARAM_UNUSED(VoltMonI_CurrentState); /* PRQA S 3119,3469,2 # 2023-07-17 Z.J.L:Do not remove if used, not any affect: accept */

	return  0;
}
#endif

/**
 ** \functions VoltMonI_u_StartupPrecondition
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(boolean, RTE_CODE) VoltMonI_u_StartupPrecondition(void)
{
    static boolean b_State = (Boolean)FALSE;
    uint8 ui8_wakeupFlag; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */

	float32_t f32_IgnVolt = 0.0f; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
	
    (void)Rte_Call_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue(&f32_IgnVolt);

	(void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_wakeupFlag);
	
    if((0x01u == ui8_wakeupFlag) || (f32_IgnVolt > VOLTAGEMONITOR_IGN_ON_THSLD))
    {
        b_State = (Boolean)TRUE;
	}
	else
	{
        b_State = (Boolean)FALSE;
	}

	return b_State;
}

/**
 ** \functions VoltMonI_u_Input
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE)VoltMonI_u_Input(void)
{   
    float32 f32_BattVolt= 0.0f;
	
    (void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f32_BattVolt);

    (void)VoltMonI_u_SetInputVoltage(f32_BattVolt);
}


/**
 ** \functions VoltMonI_Output
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE)VoltMonI_u_Output(void)
{
    boolean b_SocState = (Boolean)FALSE;
    boolean b_ECUState = (Boolean)FALSE;
	boolean b_SocStartup = (Boolean)FALSE;/* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
    boolean b_CommunicationState = (Boolean)FALSE;/* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */
    e_VoltMonI_voltageState_t e_VoltState; /* PRQA S 2211,1 # 2023-07-17 Z.J.L:not any affect: accept */

    b_CommunicationState = VoltMonI_u_GetAction_Disablecommunication();
    b_ECUState = VoltMonI_u_GetAction_DisableECU();
    b_SocState = VoltMonI_u_GetAction_DisableSoc();
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();
	b_SocStartup = Esm_GetSocStartupFlag();

    if(((Boolean)TRUE == b_ECUState) && ((Boolean)TRUE == b_SocState))
    {
        Esm_v_System_Shutdown();        
    }
    else if(((Boolean)FALSE == b_ECUState) && ((Boolean)TRUE == b_SocState))
    {
        Esm_v_Soc_PowerOff();
    }
    else if((Boolean)TRUE == b_SocStartup) //When Soc Startup compelte, shall be active this action.
    {
        Esm_v_Soc_PowerOn();
    }
    else
    {
        /*Do nothing.*/
    }

    (void)Rte_Write_PP_VoltMonI_SRI_DisableCommunication_DE_VoltMonI_DisableCommunication(b_CommunicationState);

    (void)Rte_Write_PP_VoltMonI_SRI_VoltState_DE_VoltMonI_VoltState((uint8)e_VoltState);

}

/**
 ** \functions VoltMonI_EntryInitVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE)VoltMonI_u_EntryInitVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageInit)
    {
        /*Do nothing*/ 
    }
	else
    {}
}

/**
 ** \functions VoltMonI_EntryNormalVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE)VoltMonI_u_EntryNormalVolt_CallBack(void)
{   
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageNormal)
    {
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)FALSE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)FALSE);
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_EntryLowVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE)VoltMonI_u_EntryLowVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageLow)        
    {
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)FALSE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)TRUE);
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_EntryUnderLowVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE)VoltMonI_u_EntryUnderLowVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageUnderLow) 
    {
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)TRUE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)TRUE);
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_EntryHighVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE) VoltMonI_u_EntryHighVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageHigh) 
    {
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)FALSE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)TRUE);
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_EntryOverHighVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE) VoltMonI_u_EntryOverHighVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageOverHigh)
    {
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)TRUE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)TRUE);
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_EntryMinVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE) VoltMonI_u_EntryMinVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageMin)
    {
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)TRUE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)TRUE);
        (void)VoltMonI_u_SetAction_DisableECU((Boolean)TRUE);
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_EntryMaxVolt_CallBack
 **
 ** \brief  
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(void, RTE_CODE) VoltMonI_u_EntryMaxVolt_CallBack(void)
{
    e_VoltMonI_voltageState_t e_VoltState;
     
    e_VoltState = VoltMonI_u_GetCurrentVoltageState();

    if(e_VoltState == VoltMonI_VoltageMax)
    {  
        (void)VoltMonI_u_SetAction_Disablecommunication((Boolean)TRUE);
        (void)VoltMonI_u_SetAction_DisableSoc((Boolean)TRUE);
        (void)VoltMonI_u_SetAction_DisableECU((Boolean)TRUE);
    }
	else
	{/*Do nothing.*/}
}

#define VoltMonI_STOP_SEC_CODE
#include <VoltMonI_MemMap.h>


/*==================[internal function declarations]========================*/

