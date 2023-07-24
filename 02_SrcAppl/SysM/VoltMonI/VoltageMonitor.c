/**
 * \file VoltageMonitor.c
 *
 * \brief 
 *
 * \version refer the VoltageMonitor.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Platform_Types.h> /* Autosar platform specific type declarations */
#include <Compiler.h>       /* Autosar compiler specific declarations */
#include <TSAutosar.h>      /* EB specific standard types */
#include <Rte_VoltMonI.h>
#include "VoltageMonitor.h"


/*==================[internal data definition]==============================*/
#define VoltMonI_START_SEC_VAR_CLEARED_LOCAL
#include <VoltMonI_MemMap.h>

static s_VoltMonI_voltmonitor_t s_VoltMonitor;

#define VoltMonI_STOP_SEC_VAR_CLEARED_LOCAL
#include <VoltMonI_MemMap.h>

/*==================[external constants definition]=========================*/

/*==================[internal constants definition]=========================*/
#define VoltMonI_START_SEC_VAR_INIT_LOCAL
#include <VoltMonI_MemMap.h>

/** \brief Intialization information of VoltMonI module */
static boolean VoltMonI_Initialized = (Boolean)FALSE;
/** \brief The internal volatge state of VoltMonI module */
static e_VoltMonI_voltageState_t e_InternalVoltState = VoltMonI_VoltageInit;
/** \brief The internal previous volatge state of VoltMonI module */
static e_VoltMonI_voltageState_t e_LastInternalVoltState = VoltMonI_VoltageInit;

#define VoltMonI_STOP_SEC_VAR_INIT_LOCAL
#include <VoltMonI_MemMap.h>


/*==================[external data definition]==============================*/

/*==================[internal function declarations]========================*/
#define VoltMonI_START_SEC_CODE_LOCAL
#include <VoltMonI_MemMap.h>

#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageInit(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageNormal(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageLow(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageUnderLow(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageHigh(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageOverHigh(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageMin(void);
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageMax(void);
static FUNC(void, RTE_CODE) VoltMonI_v_VoltageStateMachine(void);
#endif

#define VoltMonI_STOP_SEC_CODE_LOCAL
#include <VoltMonI_MemMap.h>

/*==================[external function definitions]=========================*/
#define VoltMonI_START_SEC_CODE
#include <VoltMonI_MemMap.h>
/**
 ** \functions VoltMonI_InitFunction
 **
 ** \brief  This is the initization of VoltMonitor component,
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
FUNC(void, RTE_CODE) VoltMonI_InitFunction (void)
{
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
     
    VoltMonI_Initialized = (Boolean)TRUE;

    s_VoltMonitor.inputVolt = VOLTAGEMONITOR_VOLTAGE_INITVAL;
    s_VoltMonitor.Volt_Timer = 0;
    s_VoltMonitor.Volt_Recover_Timer = 0;
    s_VoltMonitor.globalVoltState = VoltMonI_VoltageInit;
    s_VoltMonitor.Action.Disablecommunication = (Boolean)FALSE;
    s_VoltMonitor.Action.DisableSoc = (Boolean)FALSE;
    s_VoltMonitor.Action.DisableECU = (Boolean)FALSE;
    s_VoltMonitor.Min.DelayTime_Thsld = s_VoltMonI_Config.Min.Volt_FreezeTime_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Min.DelayTime_Recover_Thsld = s_VoltMonI_Config.Min.Volt_FreezeTime_Recover_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Under_Low.DelayTime_Thsld = s_VoltMonI_Config.Under_Low.Volt_FreezeTime_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Under_Low.DelayTime_Recover_Thsld = s_VoltMonI_Config.Under_Low.Volt_FreezeTime_Recover_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Low.DelayTime_Thsld = s_VoltMonI_Config.Low.Volt_FreezeTime_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Low.DelayTime_Recover_Thsld = s_VoltMonI_Config.Low.Volt_FreezeTime_Recover_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.High.DelayTime_Thsld = s_VoltMonI_Config.High.Volt_FreezeTime_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.High.DelayTime_Recover_Thsld = s_VoltMonI_Config.High.Volt_FreezeTime_Recover_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Over_High.DelayTime_Thsld = s_VoltMonI_Config.Over_High.Volt_FreezeTime_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Over_High.DelayTime_Recover_Thsld = s_VoltMonI_Config.Over_High.Volt_FreezeTime_Recover_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Max.DelayTime_Thsld = s_VoltMonI_Config.Max.Volt_FreezeTime_Thsld / VOLTAGEMONITOR_TASK_TIME;
    s_VoltMonitor.Max.DelayTime_Recover_Thsld = s_VoltMonI_Config.Max.Volt_FreezeTime_Recover_Thsld / VOLTAGEMONITOR_TASK_TIME;

#endif
}

/**
 ** \functions VoltMonI_MainFunction
 **
 ** \brief  This is the Main function of VoltMonitor component,
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
FUNC(void, RTE_CODE) VoltMonI_MainFunction (void)
{  
	static boolean b_State = (Boolean)FALSE;

    b_State = s_VoltMonI_Config.VoltMonI_StartupPrecondition();
	
    if(((Boolean)TRUE == VoltMonI_Initialized) && ((Boolean)TRUE == b_State))
    {
        s_VoltMonI_Config.VoltMonI_Input();

        #if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON)    
        VoltMonI_v_VoltageStateMachine();
        #endif  

        s_VoltMonI_Config.VoltMonI_Output();
    }
	else
	{/*Do nothing.*/}
}

/**
 ** \functions VoltMonI_SetInputVoltage
 **
 ** \brief  ,
 **
 ** \param[in] f_InputVolt 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetInputVoltage(const float f_InputVolt)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
		
    s_VoltMonitor.inputVolt = f_InputVolt;

	return u_RetVal;
}

/**
 ** \functions VoltMonI_GetCurrentVoltageState
 **
 ** \brief  ,
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
FUNC(e_VoltMonI_voltageState_t, RTE_CODE) VoltMonI_u_GetCurrentVoltageState(void)
{
    return (s_VoltMonitor.globalVoltState);
}

/**
 ** \functions VoltMonI_GetAction_Disablecommunication
 **
 ** \brief  ,
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
FUNC(boolean, RTE_CODE) VoltMonI_u_GetAction_Disablecommunication(void)
{
    return (s_VoltMonitor.Action.Disablecommunication);
}

/**
 ** \functions VoltMonI_SetAction_Disablecommunication
 **
 ** \brief  ,
 **
 ** \param[in] b_State 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetAction_Disablecommunication(const boolean b_State)
{
   Std_ReturnType u_RetVal = RTE_E_OK;

   s_VoltMonitor.Action.Disablecommunication = b_State;

   return u_RetVal;
}

/**
 ** \functions VoltMonI_GetAction_DisableECU
 **
 ** \brief  ,
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
FUNC(boolean, RTE_CODE) VoltMonI_u_GetAction_DisableECU(void)
{
    return (s_VoltMonitor.Action.DisableECU);
}

/**
 ** \functions VoltMonI_SetAction_DisableECU
 **
 ** \brief  ,
 **
 ** \param[in] b_State 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetAction_DisableECU(const boolean b_State)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	   
    s_VoltMonitor.Action.DisableECU = b_State;

	return u_RetVal;
}

/**
 ** \functions VoltMonI_GetAction_DisableSoc
 **
 ** \brief  ,
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
FUNC(boolean, RTE_CODE) VoltMonI_u_GetAction_DisableSoc(void)
{
    return (s_VoltMonitor.Action.DisableSoc);
}

/**
 ** \functions VoltMonI_SetAction_DisableSoc
 **
 ** \brief  ,
 **
 ** \param[in] b_State 
 **
 ** \param[in] none
 **
 ** \return none
 **
 ** \comments 
 **
 **/
FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetAction_DisableSoc(const boolean b_State)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
		
    s_VoltMonitor.Action.DisableSoc = b_State;

    return u_RetVal;
}

#define VoltMonI_STOP_SEC_CODE
#include <VoltMonI_MemMap.h>

/*==================[internal function definitions]=========================*/
#define VoltMonI_START_SEC_CODE_LOCAL
#include <VoltMonI_MemMap.h>
/**
 ** \functions VoltMonI_u_SubAction_VoltageNormal
 **
 ** \brief  This is the sub function of voltageInit state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageInit(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	  
	if(s_VoltMonitor.inputVolt <= s_VoltMonI_Config.Min.Volt_Thsld)
	{
		/*Condition_1: When the current voltage is equal to less than 6V for more than 200ms, shall be transmit to state "VoltMonI_VoltageMin"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Min.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageMin;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if((s_VoltMonitor.inputVolt <= s_VoltMonI_Config.Under_Low.Volt_Thsld)&&(s_VoltMonitor.inputVolt > s_VoltMonI_Config.Min.Volt_Thsld))
	{   
		/*Condition_4: When the current voltage is equal  or less than 7.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageUnderLow"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Under_Low.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageUnderLow;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if((s_VoltMonitor.inputVolt <= s_VoltMonI_Config.Low.Volt_Thsld)&&(s_VoltMonitor.inputVolt > s_VoltMonI_Config.Under_Low.Volt_Thsld))
    {
		/*Condition_8: the current voltage is equal or less than 8.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageLow"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Low.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageLow;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if(s_VoltMonitor.inputVolt >= s_VoltMonI_Config.Max.Volt_Thsld) 
	{
		/*Condition_2: When the current voltage is equal or greater than 28V for more than 200ms, shall be transmit to state "VoltMonI_VoltageMax"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Max.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageMax;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if((s_VoltMonitor.inputVolt >= s_VoltMonI_Config.Over_High.Volt_Thsld)&&(s_VoltMonitor.inputVolt < s_VoltMonI_Config.Max.Volt_Thsld))
	{
		/*Condition_6: When the current voltage is equal or greater to 18.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageMax"*/
		if(s_VoltMonitor.Volt_Timer	> s_VoltMonitor.Over_High.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageOverHigh;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if((s_VoltMonitor.inputVolt >= s_VoltMonI_Config.High.Volt_Thsld)&&(s_VoltMonitor.inputVolt < s_VoltMonI_Config.Over_High.Volt_Thsld))
	{
		/*Condition_5: When the current voltage is equal or greater to 16.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageHigh"*/
		if(s_VoltMonitor.Volt_Timer >= s_VoltMonitor.High.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageHigh;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}			
	}
	else /*Condition_7: Normal working range: 8.5V ~ 16V */
	{
		e_InternalVoltState = VoltMonI_VoltageNormal;
		s_VoltMonitor.Volt_Timer = 0u;
		s_VoltMonitor.Volt_Recover_Timer = 0u;
	}
	
	s_VoltMonI_Config.EntryInitVolt_CallBack();

    return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageNormal
 **
 ** \brief  This is the sub function of voltageNormal state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageNormal(void)
{	
    Std_ReturnType u_RetVal = RTE_E_OK;
	
	if(s_VoltMonitor.inputVolt <= s_VoltMonI_Config.Low.Volt_Thsld)
	{
		 /*Condition_8: When the current voltage less than 8.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageLow"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Low.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageLow;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if(s_VoltMonitor.inputVolt >= s_VoltMonI_Config.High.Volt_Thsld)
	{	
		/*Condition_9: When the current voltage greater than 16.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageHigh"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.High.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageHigh;
			s_VoltMonitor.Volt_Timer = 0u;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else
	{
		s_VoltMonitor.Volt_Timer = 0u;
	}
	
	s_VoltMonI_Config.EntryNormalVolt_CallBack();

    return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageLow
 **
 ** \brief  This is the sub function of voltageLow state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageLow(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;

    if(s_VoltMonitor.inputVolt <= s_VoltMonI_Config.Under_Low.Volt_Thsld) //less than 7.5V
	{
	    /*Condition_10: When the current voltage is equal or less than 7.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageUnderLow"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Under_Low.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageUnderLow;
			s_VoltMonitor.Volt_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}else if(s_VoltMonitor.inputVolt > s_VoltMonI_Config.Low.Volt_Recover_Thsld) //greater than 9.0V
	{
		/*Condition_11: When the current voltage greather than 9V for more than 500ms, shall be transmit to state "VoltMonI_VoltageNormal"*/
	    if(s_VoltMonitor.Volt_Recover_Timer > s_VoltMonitor.Low.DelayTime_Recover_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageNormal;
			s_VoltMonitor.Volt_Recover_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Recover_Timer++;
		}
	}
	else
	{
		s_VoltMonitor.Volt_Timer = 0;
		s_VoltMonitor.Volt_Recover_Timer = 0;
	}

	s_VoltMonI_Config.EntryLowVolt_CallBack();

    return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageUnderLow
 **
 ** \brief  This is the sub function of voltageUbderLow state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageUnderLow(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;

	if(s_VoltMonitor.inputVolt <= s_VoltMonI_Config.Min.Volt_Thsld) //less than 6V
	{	
		/*Condition_12: When the current voltage less than 7V for more than 200ms, shall be transmit to state "VoltMonI_VoltageMin"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Min.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageMin;
			s_VoltMonitor.Volt_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if(s_VoltMonitor.inputVolt > s_VoltMonI_Config.Under_Low.Volt_Recover_Thsld)
	{
		/*Condition_13: When the current voltage greater than 7.9V for more than 500ms, shall be transmit to state "VoltMonI_VoltageLow"*/
		if(s_VoltMonitor.Volt_Recover_Timer > s_VoltMonitor.Under_Low.DelayTime_Recover_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageLow;
			s_VoltMonitor.Volt_Recover_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Recover_Timer++;
		}
	}
	else
	{
		s_VoltMonitor.Volt_Timer = 0;
		s_VoltMonitor.Volt_Recover_Timer = 0;
	}
	
	s_VoltMonI_Config.EntryUnderLowVolt_CallBack();

    return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageHigh
 **
 ** \brief  This is the sub function of voltageHigh state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageHigh(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	
	if(s_VoltMonitor.inputVolt >= s_VoltMonI_Config.Over_High.Volt_Thsld)
	{	
		/*Condition_14: When the current voltage is equal or greater than 18.5V for more than 500ms, shall be transmit to state "VoltMonI_VoltageOverHigh"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Over_High.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageOverHigh;
			s_VoltMonitor.Volt_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if(s_VoltMonitor.inputVolt < s_VoltMonI_Config.High.Volt_Recover_Thsld)
	{
		/*Condition_15: When the current voltage less than 16V for more than 500ms, shall be transmit to state "VoltMonI_VoltageNormal"*/
		if(s_VoltMonitor.Volt_Recover_Timer > s_VoltMonitor.High.DelayTime_Recover_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageNormal;
			s_VoltMonitor.Volt_Recover_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Recover_Timer++;
		}
	}
	else
	{
		s_VoltMonitor.Volt_Timer = 0;
		s_VoltMonitor.Volt_Recover_Timer = 0;
	}

	s_VoltMonI_Config.EntryHighVolt_CallBack();

     return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageOverHigh
 **
 ** \brief  This is the sub function of voltageOverHigh state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageOverHigh(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;

	if(s_VoltMonitor.inputVolt >= s_VoltMonI_Config.Max.Volt_Thsld)
	{  
		/*Condition_16: When the current voltage is equal or greater than 28V for more than 200ms, shall be transmit to state "VoltMonI_VoltageMax"*/
		if(s_VoltMonitor.Volt_Timer > s_VoltMonitor.Max.DelayTime_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageMax;
			s_VoltMonitor.Volt_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Timer++;
		}
	}
	else if(s_VoltMonitor.inputVolt < s_VoltMonI_Config.Over_High.Volt_Recover_Thsld) 
	{
		/*Condition_17: When the current voltage less than 18V for more than 500ms, shall be transmit to state "VoltMonI_VoltageHigh"*/
		if(s_VoltMonitor.Volt_Recover_Timer > s_VoltMonitor.Over_High.DelayTime_Recover_Thsld)
		{
			e_InternalVoltState = VoltMonI_VoltageHigh;
			s_VoltMonitor.Volt_Recover_Timer = 0;
		}
		else
		{
			s_VoltMonitor.Volt_Recover_Timer++;
		}
	}
	else
	{
		s_VoltMonitor.Volt_Timer = 0;
		s_VoltMonitor.Volt_Recover_Timer = 0;
	}
	
	s_VoltMonI_Config.EntryOverHighVolt_CallBack();
	
	return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageMin
 **
 ** \brief  This is the sub function of voltageMin state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageMin(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;
	
	s_VoltMonitor.Volt_Timer = 0;
	s_VoltMonitor.Volt_Recover_Timer = 0;
	s_VoltMonI_Config.EntryMinVolt_CallBack();

	return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_u_SubAction_VoltageMax
 **
 ** \brief  This is the sub function of voltageMax state,
 **
 ** \param[in] none 
 **
 ** \param[in] none
 **
 ** \return RTE_E_OK
 **
 ** \comments 
 **
 **/
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SubAction_VoltageMax(void)
{
    Std_ReturnType u_RetVal = RTE_E_OK;

	s_VoltMonitor.Volt_Timer = 0;
	s_VoltMonitor.Volt_Recover_Timer = 0;
	s_VoltMonI_Config.EntryMaxVolt_CallBack();

	return u_RetVal;
}
#endif

/**
 ** \functions VoltMonI_CalculateVoltageState
 **
 ** \brief  This is the Main function of VoltMonitor component,
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
#if(VOLTAGEMONITOR_FUNCTION_ENABLED == STD_ON) 
static FUNC(void, RTE_CODE) VoltMonI_v_VoltageStateMachine(void)
{
    e_LastInternalVoltState = e_InternalVoltState;

	switch (e_InternalVoltState)
	{
        case VoltMonI_VoltageInit: /*Only run in start up sequence */
            (void)VoltMonI_u_SubAction_VoltageInit();
            break;
	    case VoltMonI_VoltageNormal: /*8.5v ~ 16.5V*/	
		    (void)VoltMonI_u_SubAction_VoltageNormal();
		    break;
	    case VoltMonI_VoltageLow: /*7.5V~9.0V*/
	        (void)VoltMonI_u_SubAction_VoltageLow();
		    break;
	    case VoltMonI_VoltageUnderLow: /*7.5v ~ 7.8V*/
            (void)VoltMonI_u_SubAction_VoltageUnderLow();
		    break;
	    case VoltMonI_VoltageHigh: /*16.5v ~ 18V*/
	        (void)VoltMonI_u_SubAction_VoltageHigh();
		    break;
        case VoltMonI_VoltageOverHigh:  /*18.5V ~28V*/
            (void)VoltMonI_u_SubAction_VoltageOverHigh();
            break;
	    case VoltMonI_VoltageMin: /*< 7V */	 
            (void)VoltMonI_u_SubAction_VoltageMin();
		    break;
	    case VoltMonI_VoltageMax: /* >28V */
            (void)VoltMonI_u_SubAction_VoltageMax();
		    break;
	    default: /* PRQA S 2016,2 # 2023-07-17 Z.J.L:not other state need to process, not any affect: accept */     
		    break;
	}
    
    s_VoltMonitor.globalVoltState = e_InternalVoltState;

    #if (VOLTAGEMONITOR_STATE_CHANGE_NOTIFICATION_CALLOUT == STD_ON)
    (void)VoltMonI_u_StateChangeNotificationCallout(e_LastInternalVoltState,e_InternalVoltState);
    #endif
}
#endif

#define VoltMonI_STOP_SEC_CODE_LOCAL
#include <VoltMonI_MemMap.h>





