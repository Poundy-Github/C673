/**
 * \file   Esh_SnapshotExtendData.c
 *
 * \brief  Fill in snapshot data and extend data of Dem event.
 *
 * \version refer the Rte_Esh.h.
 * 
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_Esh.h>
#include "Sdc_Core.h" /* PRQA S 0380,2 # 2023-06-13 Z.J.L: 0380: Number of macro definitions exceeds 4095 - program does not conform strictly to ISO:C99. 0380: accept */
#include "fs_adc.h"

/*==================[external constants definition]=========================*/



/*==================[internal constants definition]=========================*/



/*==================[external data definition]==============================*/



/*==================[internal data definition]==============================*/




/*==================[internal function declarations]========================*/



/*==================[external function definitions]=========================*/
/**
 * \functions Esh_u_DataElementClass_Odometer
 *
 * \brief The snapshot data of Odometer.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B1.
 *  Total Size: 4 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_Odometer (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) /* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    uint32 ui32_Odometer = 0;

    /*The receive is raw value from CAN bus.*/
    (void)Rte_Read_RP_Com_SRI_CdcTotMilg_DE_CdcTotMilg(&ui32_Odometer);
	
	Data[0] = (uint8_t)((ui32_Odometer >> 24) & ((uint8_t)0xFF)); //PRQA S 2985
	Data[1] = (uint8_t)((ui32_Odometer >> 16) & ((uint8_t)0xFF));
    Data[2] = (uint8_t)((ui32_Odometer >> 8) & ((uint8_t)0xFF));
	Data[3] = (uint8_t)(ui32_Odometer & ((uint8_t)0xFF));

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_Odometer (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_Voltage
 *
 * \brief The snapshot data of voltage.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B5.
 *  Total Size: 1 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_Voltage (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
	Std_ReturnType u_Retval = RTE_E_OK;

	float32_t f32_BattVolt = 0.0f;

    (void)Rte_Call_RP_EvAdc_GetValue_VMON_BATT_GetPhyValue(&f32_BattVolt);
	
    Data[0] = (uint8_t)((float32_t)((f32_BattVolt * 100.0f) / 8.0f)); //phy = xx*0.08
	
    return u_Retval;
	
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_Voltage (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_VehicleSpeed
 *
 * \brief The snapshot data of vehicle speed.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B4.
 *  Total Size: 2 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_VehicleSpeed (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
	uint16_t ui16_EspVehSpd = 0;
		
    (void)Rte_Read_RP_Com_SRI_EspVehSpd_DE_EspVehSpd(&ui16_EspVehSpd);

	Data[0] = (uint8_t)(((uint16)ui16_EspVehSpd >> 8) & (uint8_t)0xFF); //PRQA S 2985
	Data[1] = (uint8_t)((uint16)ui16_EspVehSpd & (uint8_t)0xFF);
	
    return u_Retval;
	
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_VehicleSpeed (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_LocalTime
 *
 * \brief The snapshot data of local time.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B0.
 *  Total Size: 6 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_LocalTime (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    uint8_t ui8_second = 0;
    uint8_t ui8_minute = 0;
    uint8_t ui8_hour = 0;
    uint8_t ui8_day = 0;
    uint8_t ui8_month = 0;
    uint8_t ui8_year = 0;

    (void)Rte_Read_RP_Com_SRI_TboxLocalTiDate_DE_TboxLocalTiDate(&ui8_day);
    (void)Rte_Read_RP_Com_SRI_TboxLocalTiHr_DE_TboxLocalTiHr(&ui8_hour);
    (void)Rte_Read_RP_Com_SRI_TboxLocalTiMins_DE_TboxLocalTiMins(&ui8_minute);
    (void)Rte_Read_RP_Com_SRI_TboxLocalTiMth_DE_TboxLocalTiMth(&ui8_month);
    (void)Rte_Read_RP_Com_SRI_TboxLocalTiSec_DE_TboxLocalTiSec(&ui8_second);
    (void)Rte_Read_RP_Com_SRI_TboxLocalTiYear_DE_TboxLocalTiYear(&ui8_year);
	
	Data[0] = (uint8_t)(ui8_year);
	Data[1] = (uint8_t)(ui8_month);
	Data[2] = (uint8_t)(ui8_day);
    Data[3] = (uint8_t)(ui8_hour);
    Data[4] = (uint8_t)(ui8_minute);
    Data[5] = (uint8_t)(ui8_second);	

	return u_Retval;
	
}/* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_LocalTime (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_ECUTemperature
 *
 * \brief The snapshot data of ECU temperature.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B7.
 *  Total Size: 2 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_ECUTemperature (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    float32_t f32_SocTemp,f32_ECUTemp;
    uint16_t ui16_ECUTemperature;

	(void)FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_MCU_EXT, &f32_ECUTemp);
    (void)FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_SOC_EXT, &f32_SocTemp);

    ui16_ECUTemperature = (uint16_t)((float32_t)((f32_SocTemp + f32_ECUTemp)/2.0f));
    
	Data[0] = (uint8_t)((ui16_ECUTemperature >> 8) & (uint8_t)0xFF);//PRQA S 2985
	Data[1] = (uint8_t)(ui16_ECUTemperature & (uint8_t)0xFF);

    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_ECUTemperature (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_YawRate
 *
 * \brief The snapshot data of Yaw Rate.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B8.
 *  Total Size: 2 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_YawRate (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    uint16_t ui16_YawRate = 0;
	
    (void)Rte_Read_RP_Com_SRI_ESP_YawRate_DE_ESP_YawRate(&ui16_YawRate);

	Data[0] = (uint8_t)((ui16_YawRate >> 8) & (uint8_t)0xFF); //PRQA S 2985
	Data[1] = (uint8_t)(ui16_YawRate & (uint8_t)0xFF);
		
    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_YawRate (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_EngineSpeed
 *
 * \brief The snapshot data of Engine speed.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11B9.
 *  Total Size: 2 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_EngineSpeed (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    uint16_t ui16_EngineSpeed;
	
    #if 0
    u_EngineSpeed = (uint16)((u_EngineSpeed *100) / 25);
    #else
	ui16_EngineSpeed = 0xFFFF; //invalid: The C385/C673 is electric car, so do not have engine speed.
	#endif
	
    Data[0] = (uint8_t)((ui16_EngineSpeed >> 8) & (uint8_t)0xFF);
    Data[1] = (uint8_t)(ui16_EngineSpeed & (uint8_t)0xFF);
		  
    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_EngineSpeed (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_ActualGearPosition
 *
 * \brief The snapshot data of actual gear position.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11BA.
 *  Total Size: 1 byte
 * The gear position define as below:
 * 0x00: invallid 0x01:P 0x02: R 0x03: N 0x04: D
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_ActualGearPosition (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    uint8_t ui8_GearPosition;
  
    (void)Rte_Read_RP_Com_SRI_VcuGearPosn_DE_VcuGearPosn(&ui8_GearPosition);
    
    Data[0] = (uint8_t)ui8_GearPosition;
    
    return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_ActualGearPosition (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_SteeringAngle
 *
 * \brief The snapshot data of steering angle.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and DID is 11BB.
 *  Total Size: 2 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_SteeringAngle (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    TS_PARAM_UNUSED(EventId);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */
    Std_ReturnType u_Retval = RTE_E_OK;
    sint16_t si16_SteeringAngle = 0;
	
    (void)Rte_Read_RP_Com_SRI_EpsSasSteerAg_DE_EpsSasSteerAg(&si16_SteeringAngle);

	Data[0] = (uint8_t)(((uint16_t)si16_SteeringAngle >> 8) & (uint8_t)0xFF); //PRQA S 2985
	Data[1] = (uint8_t)((uint16_t)si16_SteeringAngle & (uint8_t)0xFF);
		
    return u_Retval;

} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_SteeringAngle (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */

/**
 * \functions Esh_u_DataElementClass_SOCErrMap
 *
 * \brief The freeze frame data of SOC Error map.
 *
 ** \param[in] EventId, not used.
 *
 ** \param[out] Data, Send data store to buffer.
 *
 ** \return RTE_E_OK, 
 * \comments  The snapshot number is 1 to 3,and data identifier is 11BC.
 *  Total Size: 10 byte
 */
FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_SOCErrMap (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId)/* PRQA S 3432,2 # 2023-06-13 Z.J.L: 3432: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses. 3432: accept */
{
    /* suppress compiler warnings about unused arguments */
    Std_ReturnType u_Retval = RTE_E_OK;
	s_Sdc_SocDiagInfo_Type p_ReadData;

	switch (EventId)
	{
	    case DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW:
		case DemConf_DemEventParameter_DEM_DTC_J3_SoC_ETH_IP_Ubnormal:
	    	{
				(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(0, &p_ReadData);	
				Data[0] = 0x00u;
				Data[1] = 0x00u;
                Data[2] = p_ReadData.FaultData[0];
				Data[3] = p_ReadData.FaultData[1];
				Data[4] = p_ReadData.FaultData[2];
				Data[5] = p_ReadData.FaultData[3];
				Data[6] = p_ReadData.FaultData[4];
				Data[7] = p_ReadData.FaultData[5];
				Data[8] = p_ReadData.FaultData[6];
				Data[9] = p_ReadData.FaultData[7];			
			}
		    break;
		case DemConf_DemEventParameter_DEM_DTC_Ethernet_Unexpected_Link_Down:
		case DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error:
		case DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error:
		case DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE:
		    {
				(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(1, &p_ReadData);

				TS_MemCpy(Data, &p_ReadData.FaultData, 10);		/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */		
		    }
		    break;        
		case DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE:
		case DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage:
		case DemConf_DemEventParameter_DEM_DTC_J3_Heavy_Rain_Detected:
		case DemConf_DemEventParameter_DEM_DTC_J3_Snow_Detected:
		case DemConf_DemEventParameter_DEM_DTC_J3_Low_Sun_Detected:
		case DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error:
		    {
				(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(2, &p_ReadData);
					   
			    Data[0] = 0x00u;
			    Data[1] = 0x00u;
			    Data[2] = 0x00u;	
			    Data[3] = p_ReadData.FaultData[0];
			    Data[4] = p_ReadData.FaultData[1];
			    Data[5] = p_ReadData.FaultData[2];
			    Data[6] = p_ReadData.FaultData[3];
			    Data[7] = p_ReadData.FaultData[4];
			    Data[8] = p_ReadData.FaultData[5];
				Data[9] = p_ReadData.FaultData[6];		
		    }
		    break;
		case DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error:
			{
				(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(3, &p_ReadData);

				(void)TS_MemCpy(Data, &p_ReadData.FaultData[2], 10);/* PRQA S 3469,2 # 2023-06-13 Z.J.L: 3469: A function should be used in preference to a function-like macro where they are interchangeable. 3469: accept */		
		    }
		    break;
	    case DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH:
		case DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error:
	    	{
				(void)Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(4, &p_ReadData);

			    Data[0] = 0x00u;
		        Data[1] = 0x00u;
		        Data[2] = 0x00u;
		        Data[3] = 0x00u;
		        Data[4] = 0x00u;
		        Data[5] = 0x00u;
		        Data[6] = p_ReadData.FaultData[0];
		        Data[7] = p_ReadData.FaultData[1];
		        Data[8] = p_ReadData.FaultData[2];
		        Data[9] = p_ReadData.FaultData[3];
		    }
			break;		
		default:
			{
                for(int i =0; i < 10; i++)
                {
                    Data[i] = 0x00u;
				}
		    }
		    break;
	}

	return u_Retval;
} /* FUNC(Std_ReturnType, RTE_CODE) Esh_u_DataElementClass_SOCErrMap (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dem_EventIdType EventId) */


/*==================[internal function definitions]=========================*/






























