/**
 * \file   Fcu_Hla.c
 *
 * \brief  Get the signal from CAN and Soc ,then send it to HLA Algo.
 *
 * \version refer the Fcu_Hla.h.
 *
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "Fcu_Hla.h"
#include "Fcu_Common.h"
#include "Dbg.h"

/*==================[internal data]=========================================*/
/*==================[.rodata]==============================*/
Fcu_const Fcu_volatile float32 c_HLA_IHBCHighLowBeam_Calluxupthsld = 5.5f;
Fcu_const Fcu_volatile float32 c_HLA_Espvehspdminthsld = 5.0f;
Fcu_const Fcu_volatile float32 c_HLA_Standby_SpdThsld = 10.0f;
Fcu_const Fcu_volatile float32 c_HLA_Active_SpdThsld = 30.0f;       //30km/h
Fcu_const Fcu_volatile float32 c_HLA_Yawrate_Inhibit = 0.19f;		  // YAWRATE > 0.19 rad/s
Fcu_const Fcu_volatile float32 c_HLA_Perception_ObstaclePosX_MaxThsld = 150.0f;
Fcu_const Fcu_volatile float32 c_HLA_Perception_ObstaclePosY_MaxThsld = 6.0f;
Fcu_const Fcu_volatile uint16 c_HLA_Highwiper_Time_Inhibit = 60000; // 60S
Fcu_const Fcu_volatile uint16 c_HLA_Fog_Time_Inhibit = 20000;		  // 20S
Fcu_const Fcu_volatile uint16 c_HLA_Lataccel_Inhibit = 3;			  // EspLatAccel > 3 m/s2
/*==================[.data]==============================*/

/*==================[.bss]===============================*/
#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
Fcu_Static Hla_InputSignals_t Fcu_HlaInputSignals;
Fcu_Static Hla_OutputSignals_t Fcu_HlaOutputSignals;
#endif
Fcu_Static s_Fcu_HlaInhibitCond_t Fcu_HlaAlgoInhbitCondition;
Fcu_Static s_Sdc_Perception_Data_t Fcu_HlaPerceptionData;

/*==================[external data]=========================================*/


/*==================[internal function declarations]========================*/
Fcu_Static FUNC(uint8, RTE_CODE) Fcu_Hla_InhibitcondtionCheck(uint8 HMALightDistribution, sint64 timestamp, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal, s_Fcu_HlaInhibitCond_t *const ptr_HlaInhibitCond);
Fcu_Static FUNC(void, RTE_CODE)  Fcu_Hla_DataProcess(const s_Fcu_Rte_Input_SignalData_t * const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t* const ptr_Fcu_Rte_Output_Signal);
/*==================[external function definitions]=========================*/
/**
 * \functions Fcu_Hla_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_Hla_InitFunction(void)
{
	/*TODO : Clean the local variable*/
	#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
	(void)TS_MemBZero(&Fcu_HlaInputSignals, sizeof(Hla_InputSignals_t));
	(void)TS_MemBZero(&Fcu_HlaOutputSignals, sizeof(Hla_OutputSignals_t));
    #endif
	(void)TS_MemBZero(&Fcu_HlaAlgoInhbitCondition, sizeof(s_Fcu_HlaInhibitCond_t));
	(void)TS_MemBZero(&Fcu_HlaPerceptionData, sizeof(s_Sdc_Perception_Data_t));
}


/**
 * \functions Fcu_Hla_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(void, RTE_CODE) Fcu_Hla_MainFunction(const s_Fcu_Rte_Input_SignalData_t * const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal) // 
{
	Fcu_Hla_DataProcess(ptr_Fcu_Rte_input_Signal,ptr_Fcu_Rte_Output_Signal);
}

/**
 * \functions Fcu_Hla_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
static FUNC(void, RTE_CODE) Fcu_Hla_DataProcess(const s_Fcu_Rte_Input_SignalData_t * const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal) // Core0_10ms
{
	sint64 s64_time_stamp = 0;
	float32 f32_HlaVehiceSpeed = 0;
	uint8_t u8_HU_HMAEnable = 0;
	static boolean b_EntryActivemode = FALSE;
	/**************************************************************Signal capture****************************************************************************/
	u8_HU_HMAEnable = GET_FCU_HMI_COMMAND(FUNC_FAB);

	#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON)
    (void)Rte_Read_RP_HlaAdapter_OutputData_Hla_OutputSignals_t(&Fcu_HlaOutputSignals);
    #endif

	(void)Rte_Call_RP_Sdc_SendInterface_Perception_J3_PerceptionData_Read(&Fcu_HlaPerceptionData, sizeof(s_Sdc_Perception_Data_t));

	(void)Time_GetTimeStampMs(&s64_time_stamp);

	if (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd <= c_HLA_Espvehspdminthsld)
	{
		f32_HlaVehiceSpeed = (float32)((uint32)ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd);
	}
	else
	{
		f32_HlaVehiceSpeed = (float32)((uint32)((ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd / HLA_ESPVEHSPD_FACTOR) + HLA_ESPVEHSPD_OFFSET));
	}
	/*******************************************************HLA Signal Input *********************************************************************************/
	#if (DBG_HLAADAPTER_ALGO_ENABLE == STD_ON) //For cover customer spec,not used HLA global algo code in ChangAn_C673.
	if ((0x04u == Fcu_HlaPerceptionData.Lane.Road_Information.data.CurrentWeather) || (0x05u == Fcu_HlaPerceptionData.Lane.Road_Information.data.CurrentWeather))
	{
		Fcu_HlaInputSignals.u8_WeatherCondition = GB_HEAVY_RAIN_SNOW;
	}
	else if (0x06u == Fcu_HlaPerceptionData.Lane.Road_Information.data.CurrentWeather)
	{
		Fcu_HlaInputSignals.u8_WeatherCondition = GB_FOG;
	}
	else if (0x03u == Fcu_HlaPerceptionData.Lane.Road_Information.data.CurrentWeather)
	{
		Fcu_HlaInputSignals.u8_WeatherCondition = GB_RAIN;
	}
	else if ((0x01u == Fcu_HlaPerceptionData.Lane.Road_Information.data.CurrentWeather) || (0x02u == Fcu_HlaPerceptionData.Lane.Road_Information.data.CurrentWeather))
	{
		Fcu_HlaInputSignals.u8_WeatherCondition = GB_HEAVY_GLARING_SUN;
	}
	else
	{
		Fcu_HlaInputSignals.u8_WeatherCondition = 0x00u;
	}
    
	Fcu_HlaInputSignals.u8_headLightState = Fcu_HlaPerceptionData.IHBC.HighLowBeam_msg.IHBC_HighLowBeam_Layout.IHBC_Decision + 1;

	if ((0x03u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode) || (0x04u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode))
	{
		/*When the IACCmode in Active or suspend, shall ative HLA，but if inhibit DTC exists shall be deactive function.*/
		if (TRUE == GET_FCU_FIMSTATE_FAB()) /*DTC not Exists*/
		{
			Fcu_HlaInputSignals.u8_hlaRequest = 0x02u; // On
		}
		else
		{
			Fcu_HlaInputSignals.u8_hlaRequest = 0x01u; // off
		}
	}
	else
	{
		if (0x01u == u8_HU_HMAEnable) /*FCU_SwitchData[1] is read FAB_Switch from RAM, 1 == FUNC_FAB*/
		{
			if (TRUE == GET_FCU_FIMSTATE_FAB()) /*DTC not Exists*/
			{
				Fcu_HlaInputSignals.u8_hlaRequest = 0x02u; // On
			}
			else
			{
				Fcu_HlaInputSignals.u8_hlaRequest = 0x01u; // off
			}
		}
		else
		{
			Fcu_HlaInputSignals.u8_hlaRequest = 0x01u; // Off
		}
	}
    
	(void)Rte_Write_PP_Fcu_HlaInputData_Hla_InputSignals_t(&Fcu_HlaInputSignals);
	#endif

	/*******************************************************HLA Signal Output *********************************************************************************/
	// Condition of inhibition process
	(void)Fcu_Hla_InhibitcondtionCheck(ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMALightDistribution , s64_time_stamp, ptr_Fcu_Rte_input_Signal, &Fcu_HlaAlgoInhbitCondition);
    
	/*HLA Active Condtion: HMI send Active command(include memory function) and IACC active or Passive*/
	/*MFC5J3CN15-446: Judgment FAB u8_HU_HMAEnable or IACC mode(0x3,0x4)*/
	if ((0x01u == u8_HU_HMAEnable) || (0x03u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode) || (0x04u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode))
	{   
		if (TRUE == GET_FCU_FIMSTATE_FAB())
		{
			/*Off->Standby: The BCM Auto light state is not actived or vhicle speed less than 10 km/h.*/
			if ((0x00u /*Actived*/== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmAutHeadLiSts) || (f32_HlaVehiceSpeed < c_HLA_Standby_SpdThsld))
			{
				ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus = 0x01u; // Standby
				b_EntryActivemode = FALSE;
			}
			else
			{
				if ((0x01u/*Actived*/== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmAutHeadLiSts) && (f32_HlaVehiceSpeed > c_HLA_Active_SpdThsld)) /*standby->Active: <1> not happen any Fault,<2>.BCM Auto light Status shall be Actived,<3>vehislce speed more than 30km/h*/
				{
					ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus = 0x02u; // Active
					b_EntryActivemode = TRUE;
				}
				/*Active->Standby: If the 10.0f <= vehice speed <=30.0f. shall be keep  in active mode.*/
				else if ((TRUE == b_EntryActivemode) && (f32_HlaVehiceSpeed >= c_HLA_Standby_SpdThsld) && (f32_HlaVehiceSpeed <= c_HLA_Active_SpdThsld))
				{ 
					ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus = 0x02u; // Active
				}
				else if ((f32_HlaVehiceSpeed >= c_HLA_Standby_SpdThsld) && (f32_HlaVehiceSpeed <= c_HLA_Active_SpdThsld)) /*Standby->Active(10km/h~30km/h): If the vehice speed <=30.0f. shall be keep in standby mode.*/
				{
					ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus = 0x01u; // Standby
				}
				else
				{ /*Do nothing.*/
				}
			}
		}
		else
		{
			ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus = 0x03u; // Failure
		}
	}
	else 
	{
		ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus = 0x00u;// Off
	}

	if ((0x01u/*Active*/ != ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAbsActv) &&
		(0x01u/*Active*/ != ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspActvSts) &&
		(0x01u != Fcu_HlaAlgoInhbitCondition.u8_HlaWiperStage) &&
		(0x01u != Fcu_HlaAlgoInhbitCondition.u8_HlaFogFlag) &&
		(0x01u != Fcu_HlaAlgoInhbitCondition.u8_HlaEspLatAccelFlag) &&
		(0x01u != Fcu_HlaAlgoInhbitCondition.u8_HlaYawRateFlag) &&
		(0x01u != Fcu_HlaAlgoInhbitCondition.u8_HlaBcmHiBeamStsFlag))
	{
		if (0x02u/*Active*/ == ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAStatus)
		{
			if ((0x01u /*Actived*/== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmAutHeadLiSts) &&
				(0x01u == Fcu_HlaPerceptionData.IHBC.HighLowBeam_msg.IHBC_HighLowBeam_Layout.IHBC_Decision))
			{
				ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMALightDistribution = 0x01u; //High Beam recommended
			}
			else
			{
				if ((0x01u /*Actived*/== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmAutHeadLiSts) &&
				    (0x01u /*Not Inhibit*/== Fcu_HlaAlgoInhbitCondition.u8_HlaVehicleObjFlag) &&
					(Fcu_HlaPerceptionData.IHBC.HighLowBeam_msg.IHBC_HighLowBeam_Layout.Cal_lux_up <= c_HLA_IHBCHighLowBeam_Calluxupthsld))
				{
					ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMALightDistribution = 0x01u;
				}
				else
				{
					ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMALightDistribution = 0x00u;//High Beam not recommended
				}
			}
		}
		else
		{
			ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMALightDistribution = 0x00u;
		}
	}
	else
	{ /*Do nothing.*/
	}	

	/*MFC5J3CN15-446: Judgment FAB u8_HU_HMAEnable or IACC mode(0x3,0x4)*/
	if((0x01u == u8_HU_HMAEnable) || (0x03u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode) || (0x04u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode))
	{
		/*HU_HMAEnable(GW507) -> FC_HMAEnableStatus(FC_108)*/
		ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAEnableStatus = 0x01u; // on
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Hla_Data.u8_FC_HMAEnableStatus = 0x00u; // off
	}
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Fcu_Hla_InhibitcondtionCheck
 *
 * \brief   
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
Fcu_Static FUNC(uint8, RTE_CODE) Fcu_Hla_InhibitcondtionCheck(uint8 HMALightDistribution, sint64 timestamp, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal, s_Fcu_HlaInhibitCond_t *const ptr_HlaInhibitCond)
{
	//f:High-speed wiper: At high speed and continuous 60s (can be calibrated)
	if ((0x00u == HMALightDistribution) && (0x02u/*High*/ == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmFrntWiperSts)) 
	{
		if (0 == ptr_HlaInhibitCond->s64_HlaWiperTime)
		{
			ptr_HlaInhibitCond->s64_HlaWiperTime = timestamp;
		}
		else if ((timestamp - ptr_HlaInhibitCond->s64_HlaWiperTime) > c_HLA_Highwiper_Time_Inhibit) // 60s
		{
			ptr_HlaInhibitCond->s64_HlaWiperTime = 0;
			ptr_HlaInhibitCond->u8_HlaWiperStage = 0x01u;
		}
		else
		{ /*Do nothing.*/
		}
	}
	else
	{
		ptr_HlaInhibitCond->u8_HlaWiperStage = 0x00u;
	}
    //b. Fog: fog lights are turned on and the camera detects the presence of fog (currently determined by self-blinding) and the duration exceeds xxs(measurable)
	if ((0x00u == HMALightDistribution) && (( /*On*/0x01u == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmFrntFogLmpSts) || (0x01u/*On*/ == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmReFoglmpSts)))
	{
		if (0 == ptr_HlaInhibitCond->s64_HlaFogTime)
		{
			ptr_HlaInhibitCond->s64_HlaFogTime = timestamp;
		}
		else if ((timestamp - ptr_HlaInhibitCond->s64_HlaFogTime) > c_HLA_Fog_Time_Inhibit) // 20s
		{
			ptr_HlaInhibitCond->s64_HlaFogTime = 0;
			ptr_HlaInhibitCond->u8_HlaFogFlag = 0x01u;
		}
		else
		{ /*Do nothing.*/
		}
	}
	else
	{
		ptr_HlaInhibitCond->u8_HlaFogFlag = 0x00u;
	}

	// d. The lateral acceleration of the vehicle is too high (> 3 m/s2, can be calibrated)
	if ((0x00u == HMALightDistribution) && (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspLatAccel > c_HLA_Lataccel_Inhibit))
	{
		ptr_HlaInhibitCond->u8_HlaEspLatAccelFlag = 0x01u;
	}
	else
	{
		ptr_HlaInhibitCond->u8_HlaEspLatAccelFlag = 0x00u;
	}

	//e. The vehicle yaw Angle rate is too high (> 0.19rad /s, can be calibrated)
	if ((0x00u == HMALightDistribution) && (FD_FABS((ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspYawRate * HLA_PI) / 180.0f) > c_HLA_Yawrate_Inhibit))
	{
		ptr_HlaInhibitCond->u8_HlaYawRateFlag = 0x01u;
	}
	else
	{
		ptr_HlaInhibitCond->u8_HlaYawRateFlag = 0x00u;
	}

	/*When driving at night, the system is in the process of automatic lane change activation, that is, 
	*when the working state of the high beam is ON = 0x1=ON, if the Active lane change state is =0x2: 
	*Active during the lane change activation process, in order to better improve the lane change 
	*performance, do not cut the high beam to the near light*/
	if ((0x01u == HMALightDistribution) && (0x01u /*ON*/== ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmHiBeamSts) && (0x02u/*Active*/== ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_ADS_UDLCStatus))
	{
		ptr_HlaInhibitCond->u8_HlaBcmHiBeamStsFlag = 0x01u;
	}
	else
	{
		ptr_HlaInhibitCond->u8_HlaBcmHiBeamStsFlag = 0x00u;
	}

	// Inhibit switch off when the vehicle is far enough.
	if (0x01u == HMALightDistribution)
	{
		ptr_HlaInhibitCond->u8_HlaVehicleObjFlag = 0x01u;

		for (int i = 0; i < 20; i++)
		{
			if (0x01u == Fcu_HlaPerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass)
			{
				if ((Fcu_HlaPerceptionData.Obstance.ObstacleData[i].data.ObstacleDataD.data.ObstaclePosX <= c_HLA_Perception_ObstaclePosX_MaxThsld) &&
					(CML_f_Abs(Fcu_HlaPerceptionData.Obstance.ObstacleData[i].data.ObstacleDataE.data.ObstaclePosY <= c_HLA_Perception_ObstaclePosY_MaxThsld)))
				{
					ptr_HlaInhibitCond->u8_HlaVehicleObjFlag = 0x00u;
					break;
				}
				else
				{ /*Do nothing.*/
				}
			}
		}
	}
	else 
	{
		ptr_HlaInhibitCond->u8_HlaVehicleObjFlag = 0x00u;
	}

	return 0;
}
