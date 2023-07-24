/**
 * \file Med_Lcfg.c
 *
 * \brief
 *
 * \version refer the Med_Core.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Med_Lcfg.h"
#include "Med_Core.h"
#include "Dem_IntEvtId.h"

/*==================[external constants]====================================*/
/*==================[internal constants]====================================*/
extern const s_Med_ErrorDetectionConfig_t Med_ErrorDetectionConfigTable[MED_ERROR_DETECTION_NUMBER] =
{/*						EventId,													MonitorCycle,	DebounceEnable,				Mode,						Op_CheckPreCond,								Op_TestFailed,								Op_TestPassed*/
	/* 0*/ {DemConf_DemEventParameter_DEM_VMON_BATT_LOW, 								10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PowerOn3000ms, 		Med_TestFailed_HwStatus_BattVoltTooLow, 				            NULL_PTR }
	/* 1*/,{DemConf_DemEventParameter_DEM_VMON_BATT_HIGH, 								10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PowerOn3000ms, 		Med_TestFailed_HwStatus_BattVoltTooHigh, 				            NULL_PTR }
	/* 2*/,{DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PowerOn3000ms, 		Med_TestFailed_HwStatus_McuExtTempTooLow, 				            NULL_PTR }
	/* 3*/,{DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PowerOn3000ms, 		Med_TestFailed_HwStatus_McuExtTempTooHigh, 				            NULL_PTR }
	/* 4*/,{DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld, 				10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUvcu, 				Med_TestFailed_CAN_SigalStatus_VCUAccrPedlPosnInvld, 	            NULL_PTR }  /*U1790F0*/
	/* 5*/,{DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUvcu, 				Med_TestFailed_CAN_SigalStatus_VCUGearPosnInvld,                    NULL_PTR }  /*U1791F0*/
	/* 6*/,{DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault, 				10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUbcm, 				Med_TestFailed_CAN_SigalStatus_BCMTurnIndcrLightFault, 	            NULL_PTR }  /*U1790F1*/
	/* 7*/,{DemConf_DemEventParameter_DEM_DTC_BCM_Frnt_Wiper_Sts_Fault, 				10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUbcm, 				Med_TestFailed_CAN_SigalStatus_BCMFrntWiperStsFault, 	            NULL_PTR }  /*U1791F1*/
	/* 8*/,{DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_ESPVehSpdInvld, 			            NULL_PTR }  /*U1792F0*/
	/* 9*/,{DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUSesp, 			Med_TestFailed_CAN_SigalStatus_WhlSpdPlsInvld, 			            NULL_PTR }  /*U1793F0*/
	/*10*/,{DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUSesp, 			Med_TestFailed_CAN_SigalStatus_WhlSpdDirInvld, 			            NULL_PTR }  /*U1794F0*/
	/*11*/,{DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUSesp, 			Med_TestFailed_CAN_SigalStatus_WhlSpdDataInvld, 		            NULL_PTR }  /*U1795F0*/
	/*12*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSSasNOTCal, 						NULL_PTR }  /*U179010*/
	/*13*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld, 				10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSActualMotorTorqInvld, 			NULL_PTR }  /*U1799F0*/
	/*14*/,{DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_Esp_GW278, 			Med_TestFailed_CAN_SigalStatus_ESPLatAccelInvld, 					NULL_PTR }  /*U179DF0*/
	/*15*/,{DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_Esp_GW278, 			Med_TestFailed_CAN_SigalStatus_ESPLongAccelInvld, 					NULL_PTR }  /*U179EF0*/
	/*16*/,{DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_Esp_GW278, 			Med_TestFailed_CAN_SigalStatus_ESPYawRateInvld, 					NULL_PTR }  /*U179FF0*/
	/*17*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Fault, 								10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSFault, 							NULL_PTR }  /*U1795F1*/
	/*18*/,{DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_VCU_NodeMissing, 					    NULL_PTR }  /*U178587*/
	/*19*/,{DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_ESP_NodeMissing, 					    NULL_PTR }  /*U178387*/
	/*20*/,{DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_EPS_NodeMissing, 					    NULL_PTR }  /*U178287*/
	/*21*/,{DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 			    Med_TestFailed_CAN_PduStatus_VCU_AliveCounterError, 		        NULL_PTR }  /*U178586*/
	/*22*/,{DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError, 		        NULL_PTR }  /*U178386*/
	/*23*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms, 	10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_10ms, 	        NULL_PTR }  /*U179086*/
	/*24*/,{DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPR, 				Med_TestFailed_CAN_PduStatus_FR_AliveCounterError, 		            NULL_PTR }  /*U178986*/
	/*25*/,{DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_ESPABSFault, 						NULL_PTR }  /*U1792F1*/
	/*26*/,{DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_ESPTCSFault, 						NULL_PTR }  /*U1793F1*/
	/*27*/,{DemConf_DemEventParameter_DEM_DTC_ESP_ABA_NOT_Available, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_ESPABANOTAvailable, 					NULL_PTR }  /*U1790F2*/
	/*28*/,{DemConf_DemEventParameter_DEM_DTC_ESP_AEB_NOT_Available, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_ESPAEBNOTAvailable, 					NULL_PTR }  /*U1791F2*/
	/*29*/,{DemConf_DemEventParameter_DEM_DTC_ESP_AWB_NOT_Available, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_ESPAWBNOTAvailable, 					NULL_PTR }  /*U1792F2*/
	/*30*/,{DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_IBBrkPedlInvld, 						NULL_PTR }  /*U1796F0*/
	/*31*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSActualTorsionTorqInvld, 			NULL_PTR }  /*U1797F0*/
	/*32*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSActualMotorInvld, 				NULL_PTR }  /*U1798F0*/
	/*33*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSSteerAgSensFault, 				NULL_PTR }  /*U179AF0*/
	/*34*/,{DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUsrs, 				Med_TestFailed_CAN_SigalStatus_SRSDrvrBucSwtInvld, 					NULL_PTR }  /*U179BF0*/
	/*35*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSPinionangInvld, 					NULL_PTR }  /*U179CF0*/
	/*36*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSPinionangFault, 					NULL_PTR }  /*U1794F1*/
	/*37*/,{DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_EPSAPAEpasFault, 					NULL_PTR }  /*U1796F1*/
	/*38*/,{DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUbcm, 				Med_TestFailed_CAN_SigalStatus_BCMEmgyLiFault, 						NULL_PTR }  /*U17A0F0*/
	/*39*/,{DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_BCM, 				    Med_TestFailed_CAN_PduStatus_BCM_NodeMissing, 					    NULL_PTR }  /*U178487*/
	/*40*/,{DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms, 	10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_BCM, 				    Med_TestFailed_CAN_PduStatus_BCM_AliveCounterError, 		        NULL_PTR }  /*U178786*/
	/*41*/,{DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PowerOn3000ms, 		Med_TestFailed_HwStatus_McuInitialTempTooHigh, 				        NULL_PTR }  /**/
	/*42*/,{DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms, 	10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_ESP_AliveCounterError_100ms, 	        NULL_PTR }  /*U178386*/
	/*43*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Steering_wheel_vibration_failure, 	10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_SteeringWheelVibrationFailure, 		NULL_PTR }  /*U17A1F0*/
	/*44*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUeps, 				Med_TestFailed_CAN_SigalStatus_DriverHandTorqueInvalid, 			NULL_PTR }  /*U17A2F0*/
	/*45*/,{DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage, 		10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_FR_136, 				Med_TestFailed_CAN_SigalStatus_FradarNotCalibrationOrBlockage, 		NULL_PTR }  /*U178910*/
	/*46*/,{DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_FR_136, 			    Med_TestFailed_CAN_SigalStatus_FradarHardwareError, 				NULL_PTR }  /*U1789E0*/
	/*47*/,{DemConf_DemEventParameter_DEM_DTC_IP_message_alive_counter_error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_IP_AliveCounterError, 			        NULL_PTR }  /*U17A486*/
	/*48*/,{DemConf_DemEventParameter_DEM_DTC_IP_node_missing, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_IP_NodeMissing, 						NULL_PTR }  /*U17A487*/
	/*49*/,{DemConf_DemEventParameter_DEM_DTC_IP_warning_invalid, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUip, 				Med_TestFailed_CAN_SigalStatus_IPWarningInvalid, 					NULL_PTR }  /*U17A3F0*/ 
	/*50*/,{DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms, 	10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_EPS_AliveCounterError_20ms, 	        NULL_PTR }  /*U179086*/
	/*51*/,{DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_SRS_NodeMissing, 					    NULL_PTR }  /*U17A987*/
	/*52*/,{DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPR, 				Med_TestFailed_CAN_PduStatus_ADC_AliveCounterError, 		        NULL_PTR }  /*U17A686*/
	/*53*/,{DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_SRS_AliveCounterError, 		        NULL_PTR }  /*U17A986*/
	/*54*/,{DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PV, 					Med_TestFailed_HwStatus_SpiDriverFault, 						    NULL_PTR }  //UNUSED
	/*55*/,{DemConf_DemEventParameter_DEM_DTC_DFLASH_ERROR, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PV, 					Med_TestFailed_HwStatus_Dflash_Error, 						        NULL_PTR }  //UNUSED
	/*56*/,{DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUbcm, 				Med_TestFailed_CAN_SigalStatus_BCMBrakeLampError, 					NULL_PTR }  /*U1794F2*/
	/*57*/,{DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr, 							10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPUesp, 				Med_TestFailed_CAN_SigalStatus_EspEbdFailr, 						NULL_PTR }  /*U1793F2*/
	/*58*/,{DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing, 						10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_FR_NodeMissing, 					    NULL_PTR }  /*U17AA87*/
	/*59*/,{DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing, 					10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPU, 				Med_TestFailed_CAN_PduStatus_ADC_NodeMissing, 					    NULL_PTR }  /*U17AB87*/
	/*60*/,{DemConf_DemEventParameter_DEM_DTC_RLR_Message_Alive_Counter_Error, 			10, 			STD_OFF, 		Med_ErrDetMode_Mutex, 		Med_EnableCondition_Group_PVPR, 				Med_TestFailed_CAN_PduStatus_RLR_AliveCounterError, 		        NULL_PTR }  /*U17A786*/
};
/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
