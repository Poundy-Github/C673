/**
 * \file   Esh_EnableCondition.c
 *
 * \brief  Set Enable condition of Dem Event to inhibited report DTC.
 *
 * \version refer the Rte_Esh.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Esh.h>
#include "Esh_Main.h"
//#include "Med_Stubs.h"
#include "Cdd_EvAdc.h"


/*==================[external constants definition]=========================*/
#if (ESH_ENABLECONDITION_ENABLED == STD_ON)
static s_Esh_EnableCondition_t s_Esh_EnableCondition;
#endif


/*==================[internal constants definition]=========================*/
const volatile uint16 c_Esh_EC_Poweron30000ms = 30000u; //30S= 30000ms

const volatile uint16 c_Esh_EC_Poweron15000ms = 15000u; //15S= 15000ms

const volatile uint16 c_Esh_EC_Poweron3000ms = 3000u; //3S= 3000ms

const volatile uint16 c_Esh_EC_BusOffRecoverTimer = 1000u; //1s= 1000ms

const volatile uint16 c_Esh_EC_PowerModeTimer = 3000u;//3000ms

const volatile float c_Esh_EC_LowVoltThsld = 8.5f;

const volatile float c_Esh_EC_HighVoltThsld = 16.5f;

const volatile uint8 c_Esh_EC_PowerModeState = 0x02u; //ON

const volatile uint8 c_Esh_EC_EspVehSpdThsld = 0x01u; //1km/h



/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/
static FUNC(void, RTE_CODE) Esh_Core_EnableConitionMainLogic(void);
#if ((defined ESH_FEAT_EnableCond_PowerOnTimer_ENABLE) && (ESH_FEAT_EnableCond_PowerOnTimer_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_PowerOnTimer(void);
#endif
#if ((defined ESH_FEAT_EnableCond_BattVoltage_ENABLE) && (ESH_FEAT_EnableCond_BattVoltage_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_BattVoltage(void);
#endif
#if ((defined ESH_FEAT_EnableCond_PublicBusoff_ENABLE) && (ESH_FEAT_EnableCond_PublicBusoff_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_PublicBusoff(void);
#endif
#if ((defined ESH_FEAT_EnableCond_PrivateBusoff_ENABLE) && (ESH_FEAT_EnableCond_PrivateBusoff_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_PrivateBusoff(void);
#endif
#if ((defined ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE) && (ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_BCMPowerModeState(void);
#endif
#if ((defined ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE) && (ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_ESPVehicleSpeed(void);
#endif
#if ((defined ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE) && (ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_PowerOn15000ms(void);
#endif
#if ((defined ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE) && (ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_PowerOn30000ms(void);
#endif



/*==================[external function definitions]=========================*/
/**
 * \functions Esh_Core_EnableConditionMainFunction
 *
 * \brief   This is the main function for used to process enable condition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
FUNC(void, RTE_CODE) Esh_Core_EnableConditionMainFunction(void)
{
    Esh_Core_EnableConitionMainLogic();
}

/**
 * \functions Esh_u_EnableCondition_Read
 *
 * \brief  Read enable condition to provide other component.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
FUNC(Std_ReturnType, RTE_CODE) Esh_u_EnableCondition_Read(s_Esh_EnableCondition_t * EnableCondition)
{
   *EnableCondition = s_Esh_EnableCondition;

   return RTE_E_OK; 
}
#endif

/*==================[internal function definitions]=========================*/
/**
 * \functions Esh_Core_EnableConitionMainLogic
 *
 * \brief   This is the main logic of enable condition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
static FUNC(void, RTE_CODE) Esh_Core_EnableConitionMainLogic(void)
{
    #if ((defined ESH_FEAT_EnableCond_PowerOnTimer_ENABLE) && (ESH_FEAT_EnableCond_PowerOnTimer_ENABLE == STD_ON))
	    Esh_u_EC_PowerOnTimer();
    #endif
    #if ((defined ESH_FEAT_EnableCond_BattVoltage_ENABLE) && (ESH_FEAT_EnableCond_BattVoltage_ENABLE == STD_ON))
	    Esh_u_EC_BattVoltage();
    #endif
    #if ((defined ESH_FEAT_EnableCond_PublicBusoff_ENABLE) && (ESH_FEAT_EnableCond_PublicBusoff_ENABLE == STD_ON))
	    Esh_u_EC_PublicBusoff();
    #endif
    #if ((defined ESH_FEAT_EnableCond_PrivateBusoff_ENABLE) && (ESH_FEAT_EnableCond_PrivateBusoff_ENABLE == STD_ON))
	    Esh_u_EC_PrivateBusoff();
    #endif
    #if ((defined ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE) && (ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE == STD_ON))
	    Esh_u_EC_BCMPowerModeState();
    #endif
    #if ((defined ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE) && (ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE == STD_ON))
	    Esh_u_EC_ESPVehicleSpeed();
    #endif
	#if ((defined ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE) && (ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE == STD_ON))
        Esh_u_EC_PowerOn15000ms();
    #endif
	#if ((defined ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE) && (ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE == STD_ON))
        Esh_u_EC_PowerOn30000ms();
    #endif
}

/**
 * \functions Esh_u_EC_PowerOn15000ms
 *
 * \brief   When the power on after 15s, shall be active enablecondition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
 #if ((defined ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE) && (ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_PowerOn15000ms(void)
{
	static uint8 u_ErrHState = ESH_STATE_INIT;
    uint8 ui8_NMwakeupFlag = 0x00;
	static uint64 ui64_ErrH_PoweronStartTime = 0;
	uint64 ui64_ErrH_CurrentTime = 0;
	
    /*Read the NM wakeup flag from SWC Comcoordinator. */
    (void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_NMwakeupFlag);
	
	if(ESH_STATE_INIT == u_ErrHState)
	{  
	   /*When the get valid wakeup source ,shall be start record start time of power on.*/
	   if(0x01U == ui8_NMwakeupFlag)
	   {
	       (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_ErrH_PoweronStartTime);
	       u_ErrHState = ESH_STATE_INACTIVE;   
	   }
	   else
	   {/*Do nothing*/}
	}
	else if(ESH_STATE_INACTIVE == u_ErrHState)  	
	{  
	    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_ErrH_CurrentTime);

		if((ui64_ErrH_CurrentTime - ui64_ErrH_PoweronStartTime) >= (c_Esh_EC_Poweron15000ms - ESH_MAINFUNCTION_TASK_CYCLE))
        {
            ui64_ErrH_PoweronStartTime = 0;
            u_ErrHState = ESH_STATE_ACTIVE;
		}
		else
		{			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
                s_Esh_EnableCondition.Poweron15000ms = 0x00U;
			#endif
		}
	}
	else if(ESH_STATE_ACTIVE == u_ErrHState)
	{
	    /*In C673 project, we should check all wakeup source ,include KL15 and NM Flag.*/
	    if(0x01U == ui8_NMwakeupFlag)
	    {			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
                s_Esh_EnableCondition.Poweron15000ms = 0x01U;
			#endif
		}
		else
		{/*Do nothing*/}  
	}

	return RTE_E_OK;

}
#endif

/**
 * \functions Esh_u_EC_PowerOn30000ms
 *
 * \brief   When the power on after 30s, shall be active enablecondition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
 #if ((defined ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE) && (ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_PowerOn30000ms(void)
{
	static uint8 u_ErrHState = ESH_STATE_INIT;
    uint8 ui8_NMwakeupFlag = 0x00;
	static uint64 ui64_ErrH_PoweronStartTime = 0;
	uint64 ui64_ErrH_CurrentTime = 0;
	
    /*Read the NM wakeup flag from SWC Comcoordinator. */
    (void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_NMwakeupFlag);
	
	if(ESH_STATE_INIT == u_ErrHState)
	{  
	   /*When the get valid wakeup source ,shall be start record start time of power on.*/
	   if(0x01U == ui8_NMwakeupFlag)
	   {
	       (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_ErrH_PoweronStartTime);
	       u_ErrHState = ESH_STATE_INACTIVE;   
	   }
	   else
	   {/*Do nothing*/}
	}
	else if(ESH_STATE_INACTIVE == u_ErrHState)  	
	{  
	    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_ErrH_CurrentTime);

		if((ui64_ErrH_CurrentTime - ui64_ErrH_PoweronStartTime) >= (c_Esh_EC_Poweron30000ms - ESH_MAINFUNCTION_TASK_CYCLE))
        {
            ui64_ErrH_PoweronStartTime = 0;
            u_ErrHState = ESH_STATE_ACTIVE;
		}
		else
		{			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
                s_Esh_EnableCondition.Poweron30000ms = 0x00U;
			#endif
		}
	}
	else if(ESH_STATE_ACTIVE == u_ErrHState)
	{
	    /*In C673 project, we should check all wakeup source ,include KL15 and NM Flag.*/
	    if(0x01U == ui8_NMwakeupFlag)
	    {			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
                s_Esh_EnableCondition.Poweron30000ms = 0x01U;
			#endif
		    /*Only request once after start up 30s.*/
            (void)Rte_Call_RP_Sdc_SendInterface_Calibration_RequestCalibrationValue();
			u_ErrHState = ESH_STATE_STOP;
		}
		else
		{/*Do nothing*/}  
	}

	return RTE_E_OK;

}
#endif

/**
 * \functions Esh_u_EC_PowerOnTimer
 *
 * \brief   When the power on after 3s, shall be active enablecondition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
 #if ((defined ESH_FEAT_EnableCond_PowerOnTimer_ENABLE) && (ESH_FEAT_EnableCond_PowerOnTimer_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_PowerOnTimer(void)
{
	static uint8 u_ErrHState = ESH_STATE_INIT;
    uint8 ui8_NMwakeupFlag = 0x00;
	static uint64 ui64_ErrH_PoweronStartTime = 0;
	uint64 ui64_ErrH_CurrentTime = 0;
	
    /*Read the NM wakeup flag from SWC Comcoordinator. */
    (void)Rte_Call_RP_Comco_CSI_NMWakupFlag_NMWakupFlag(&ui8_NMwakeupFlag);
	
	if(ESH_STATE_INIT == u_ErrHState)
	{  
	   /*When the get valid wakeup source ,shall be start record start time of power on.*/
	   if(0x01u == ui8_NMwakeupFlag)
	   {
	       (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_ErrH_PoweronStartTime);
	       u_ErrHState = ESH_STATE_INACTIVE;   
	   }
	   else
	   {/*Do nothing*/}
	}
	else if(ESH_STATE_INACTIVE == u_ErrHState)  	
	{  
	    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_ErrH_CurrentTime);

		if((ui64_ErrH_CurrentTime - ui64_ErrH_PoweronStartTime) >= (c_Esh_EC_Poweron3000ms - ESH_MAINFUNCTION_TASK_CYCLE))
        {
            ui64_ErrH_PoweronStartTime = 0;
            u_ErrHState = ESH_STATE_ACTIVE;
		}
		else
		{
			#if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
                (void)Rte_Call_RP_Dem_EC_PoweronTimer_SetEnableCondition(FALSE);
			#endif
			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
                s_Esh_EnableCondition.Poweron3000ms = 0x00U;
			#endif
		}
	}
	else if(ESH_STATE_ACTIVE == u_ErrHState)
	{
	    /*In C673 project, we should check all wakeup source ,include KL15 and NM Flag.*/
	    if(0x01u == ui8_NMwakeupFlag)
	    {
	        #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
                (void)Rte_Call_RP_Dem_EC_PoweronTimer_SetEnableCondition(TRUE);
			#endif
			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
                s_Esh_EnableCondition.Poweron3000ms = 0x01U;
			#endif
		}
		else
		{/*Do nothing*/}  
	}

	return RTE_E_OK;

}
#endif

/**
 * \functions Esh_u_EC_BattVoltage
 *
 * \brief   When the voltage is in 8.5~16.5V, shall be active enablecondition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined ESH_FEAT_EnableCond_BattVoltage_ENABLE) && (ESH_FEAT_EnableCond_BattVoltage_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE) Esh_u_EC_BattVoltage(void)
{
	float32 f32_BattVolt = 0;

	(void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f32_BattVolt);

	if((f32_BattVolt >= c_Esh_EC_LowVoltThsld) && (f32_BattVolt <= c_Esh_EC_HighVoltThsld))
	{
	    #if (ESH_FEAT_EnableCond_RTE_USED == STD_ON)
            (void)Rte_Call_RP_Dem_EC_BattVoltInNormalScope_SetEnableCondition(TRUE);
        #endif
		
		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.VoltageNormal = 0x01U;
		#endif		
	}
	else
	{
	    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
            (void)Rte_Call_RP_Dem_EC_BattVoltInNormalScope_SetEnableCondition(FALSE);
        #endif

		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.VoltageNormal = 0x00U;
		#endif
	}

    return RTE_E_OK;
}
#endif

/**
 * \functions Esh_u_EC_PublicBusoff
 *
 * \brief When not trigger bus off event or recover after 1s, shall be active enablecondition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined ESH_FEAT_EnableCond_PublicBusoff_ENABLE) && (ESH_FEAT_EnableCond_PublicBusoff_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_PublicBusoff(void)
{
	uint8 ui8_CurrentPublicCanSMMode = RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION;
	static uint8 ui8_LastpublicCanSMMode = RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION;	
    static uint64 ui64_BusoffStartTime = 0;
	uint64 ui64_BusoffEndTime = 0;
	
    ui8_CurrentPublicCanSMMode = Rte_Mode_RP_BswM_CanSMState_PublicCan_proto_CANSM_ModeGroup();

	if(RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF == ui8_CurrentPublicCanSMMode)
	{   
	    ui8_LastpublicCanSMMode = ui8_CurrentPublicCanSMMode;
		
	    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_BusoffStartTime);	
        /*when trigger busoff event, shall be inactive enable condition.*/
		#if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
		    (void)Rte_Call_RP_Dem_EC_PublicBusoffEventCheck_SetEnableCondition(FALSE);
        #endif
		
		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.NoBusOffPublicCAN = 0x00U;
		#endif		
	}
	else if(RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_FULL_COMMUNICATION == ui8_CurrentPublicCanSMMode)
	{
	    if(RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF == ui8_LastpublicCanSMMode)//When the last state is in bus off state,shall be recover after 1S.
	    {			
	        
			(void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_BusoffEndTime);
		
		    if((ui64_BusoffEndTime - ui64_BusoffStartTime) >= (c_Esh_EC_BusOffRecoverTimer-ESH_MAINFUNCTION_TASK_CYCLE))
		    {
		        ui64_BusoffStartTime = 0;
                ui8_LastpublicCanSMMode = ui8_CurrentPublicCanSMMode;

				#if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
                    (void)Rte_Call_RP_Dem_EC_PublicBusoffEventCheck_SetEnableCondition(TRUE);
                #endif
				
				#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		            s_Esh_EnableCondition.NoBusOffPublicCAN = 0x01U;
		        #endif
		    }
			else
			{
			    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
			        (void)Rte_Call_RP_Dem_EC_PublicBusoffEventCheck_SetEnableCondition(FALSE);
                #endif
				
				#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		            s_Esh_EnableCondition.NoBusOffPublicCAN = 0x00U;
		        #endif
			}
	    }
		else //No busoff event trigger ,shall be active enable condition.
		{
		    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
                (void)Rte_Call_RP_Dem_EC_PublicBusoffEventCheck_SetEnableCondition(TRUE);
            #endif
			
			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		        s_Esh_EnableCondition.NoBusOffPublicCAN = 0x01U;
		    #endif
		}        	   
	}
	else
	{/*Do nothing.*/}

	return RTE_E_OK;
}
#endif

/**
 * \functions Esh_u_EC_PrivateBusoffEventCheck
 *
 * \brief When not trigger bus off event or recover after 5s, shall be active enablecondition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined ESH_FEAT_EnableCond_PrivateBusoff_ENABLE) && (ESH_FEAT_EnableCond_PrivateBusoff_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_PrivateBusoff(void)
{
	uint8 ui8_CurrentPrivateCanSMMode = RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION;
	static uint8 ui8_LastprivateCanSMMode = RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION;	
    static uint64 ui64_BusoffStartTime = 0;
	uint64 ui64_BusoffEndTime = 0;
	
    ui8_CurrentPrivateCanSMMode = Rte_Mode_RP_BswM_CanSMState_PrivateCan_proto_CANSM_ModeGroup();
	
	if(RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF == ui8_CurrentPrivateCanSMMode)
	{   
	    ui8_LastprivateCanSMMode = ui8_CurrentPrivateCanSMMode;
		
	    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_BusoffStartTime);	
        /*when trigger busoff event, shall be inactive enable condition.*/

		#if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
		    (void)Rte_Call_RP_Dem_EC_PrivateBusoffEventCheck_SetEnableCondition(FALSE);		
        #endif
		
		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.NoBusOffPrivateCAN = 0x00U;
		#endif
	}
	else if(RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_FULL_COMMUNICATION == ui8_CurrentPrivateCanSMMode)
	{
	    if(RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF == ui8_LastprivateCanSMMode)//When the last state is in bus off state,shall be recover after 1S.
	    {			
			(void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_BusoffEndTime);
		
		    if((ui64_BusoffEndTime - ui64_BusoffStartTime) >= (c_Esh_EC_BusOffRecoverTimer - ESH_MAINFUNCTION_TASK_CYCLE))
		    {
		        ui64_BusoffStartTime = 0;
                ui8_LastprivateCanSMMode = ui8_CurrentPrivateCanSMMode;
				
				#if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
                    (void)Rte_Call_RP_Dem_EC_PrivateBusoffEventCheck_SetEnableCondition(TRUE);
				#endif

				#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		            s_Esh_EnableCondition.NoBusOffPrivateCAN = 0x01U;
		        #endif		
		    }
			else
			{
			    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
			        (void)Rte_Call_RP_Dem_EC_PrivateBusoffEventCheck_SetEnableCondition(FALSE);	
				#endif

				#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		            s_Esh_EnableCondition.NoBusOffPrivateCAN = 0x00U;
		        #endif
				
			}
	    }
		else //No busoff event trigger ,shall be active enable condition.
		{
		    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
                (void)Rte_Call_RP_Dem_EC_PrivateBusoffEventCheck_SetEnableCondition(TRUE);
			#endif

			#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		        s_Esh_EnableCondition.NoBusOffPrivateCAN = 0x01U;
		    #endif		
		}        	   
	}
	else
	{/*Do nothing.*/}

	return RTE_E_OK;
}
#endif

/**
 * \functions Esh_u_EC_BCMPowerModeStateCheck
 *
 * \brief When BCM power mode state is ON(0x02), shall be active enable condition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE) && (ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_BCMPowerModeState(void)
{	
    uint8 ui8_PowerModeState = 0;
	static boolean b_Entrying = FALSE;
    static uint64 ui64_PowerModeStartTime = 0;
	uint64 ui64_PowerModeCurrentTime = 0;
	(void)Rte_Read_RP_Com_SRI_BcmPwrStsFbON_DE_BcmPwrStsFbON(&ui8_PowerModeState);
	
    if(c_Esh_EC_PowerModeState == ui8_PowerModeState)//0x02: ON
    {
		if(FALSE == b_Entrying)
		{
		    (void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_PowerModeStartTime);
			b_Entrying = TRUE;	
		}
		else
		{
			(void)Rte_Call_RP_Time_GlobalTime_GetTimeStampMs((uint64*)&ui64_PowerModeCurrentTime);

			if((ui64_PowerModeCurrentTime - ui64_PowerModeStartTime) >= (c_Esh_EC_PowerModeTimer - ESH_MAINFUNCTION_TASK_CYCLE))
			{
				#if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
					(void)Rte_Call_RP_Dem_EC_BCMPowerModeState_SetEnableCondition(TRUE);
				#endif

				#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
					s_Esh_EnableCondition.BCMPowerModeState = 0x01U;
				#endif	
				ui64_PowerModeStartTime = 0;
			}
			else
			{
				/*nothing*/
			}
		}
		
	
	}
    else
    {
        #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
            (void)Rte_Call_RP_Dem_EC_BCMPowerModeState_SetEnableCondition(FALSE);
		#endif

		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.BCMPowerModeState = 0x00U;
		#endif
		/*When the powermode is off,it shall be renable power on*/
		b_Entrying = FALSE;
	}

    return RTE_E_OK;
}
#endif

/**
 * \functions Esh_u_EC_ESPVehicleSpeedCheck
 *
 * \brief When the vehicle speed more than 1km/h, shall be active enable condition.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return RTE_E_OK, 
 * \comments
 *
 */
#if ((defined ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE) && (ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE == STD_ON))
static FUNC(Std_ReturnType, RTE_CODE)Esh_u_EC_ESPVehicleSpeed(void)
{	
    uint16 ui16_EspVehSpd = 0;
	float f_EspVehSpd = 0;

	(void)Rte_Read_RP_Com_SRI_EspVehSpd_DE_EspVehSpd(&ui16_EspVehSpd);

	f_EspVehSpd = ((float)ui16_EspVehSpd * 5625) / 100000; //phy = raw* 0.05625;
	
	if(f_EspVehSpd > c_Esh_EC_EspVehSpdThsld)
	{
	    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
            (void)Rte_Call_RP_Dem_EC_EspVehSpd_SetEnableCondition(TRUE);
		#endif

		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.VehicleSpeedNot0 = 0x01U;
		#endif
	}
	else
	{
	    #if ((defined ESH_FEAT_EnableCond_RTE_USED) && (ESH_FEAT_EnableCond_RTE_USED == STD_ON))
            (void)Rte_Call_RP_Dem_EC_EspVehSpd_SetEnableCondition(FALSE);
		#endif

		#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
		    s_Esh_EnableCondition.VehicleSpeedNot0 = 0x00U;
		#endif		
	}

	return RTE_E_OK;
}
#endif




