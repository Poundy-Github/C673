/**
 * \file Cpr_Lcfg.c
 *
 * \brief Implement Can communication process of recevied
 *
 * \version refer the Cpr_Core.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Cpr_Lcfg.h"
#include"Cpr_DataProcess.h"
/*==================[internal data]=========================================*/
/*TODO : Signal Range definition*/
const uint16 Cpr_Min_VcuAccrPedlPosn = 0;
const uint16 Cpr_Max_VcuAccrPedlPosn = 1023;

const uint8 Cpr_Min_VcuAccrPedlPosnVld = 0;
const uint8 Cpr_Max_VcuAccrPedlPosnVld = 1;

const uint8 Cpr_Min_VcuGearPosn = 0;
const uint8 Cpr_Max_VcuGearPosn = 7;

const uint8 Cpr_Min_VcuVehGearPosnVld = 0;
const uint8 Cpr_Max_VcuVehGearPosnVld = 1;

const uint8 Cpr_Min_BcmAutHeadLiSts = 0;
const uint8 Cpr_Max_BcmAutHeadLiSts = 1;

const boolean Cpr_Min_BcmDrvrDoorSts = 0;
const boolean Cpr_Max_BcmDrvrDoorSts = 1;

const uint8 Cpr_Min_BcmFrntFogLmpSts = 0;
const uint8 Cpr_Max_BcmFrntFogLmpSts = 3;

const uint8 Cpr_Min_BcmFrntWiperSts = 0;
const uint8 Cpr_Max_BcmFrntWiperSts = 3;

const uint8 Cpr_Min_BcmHiBeamSts = 0;
const uint8 Cpr_Max_BcmHiBeamSts = 3;

const boolean Cpr_Min_BcmLeReDoorSts = 0;
const boolean Cpr_Max_BcmLeReDoorSts = 1;

const uint8 Cpr_Min_BcmLoBeamSts = 0;
const uint8 Cpr_Max_BcmLoBeamSts = 3;

const boolean Cpr_Min_BcmPassDoorSts = 0;
const boolean Cpr_Max_BcmPassDoorSts = 1;

const uint8 Cpr_Min_BcmReFoglmpSts = 0;
const uint8 Cpr_Max_BcmReFoglmpSts = 3;

const boolean Cpr_Min_BcmRiReDoorSts = 0;
const boolean Cpr_Max_BcmRiReDoorSts = 1;

const uint8 Cpr_Min_BcmTurnIndcrLe = 0;
const uint8 Cpr_Max_BcmTurnIndcrLe = 3;

const uint8 Cpr_Min_BcmTurnIndcrRi = 0;
const uint8 Cpr_Max_BcmTurnIndcrRi = 3;

const uint8 Cpr_Min_IP_DISFail = 0;
const uint8 Cpr_Max_IP_DISFail = 1;

const uint8 Cpr_Min_IP_QDashACCFail = 0;
const uint8 Cpr_Max_IP_QDashACCFail = 3;

const uint8 Cpr_Min_EspVehSpdVld = 0;
const uint8 Cpr_Max_EspVehSpdVld = 1;

const boolean Cpr_Min_EspEbdFailr = 0;
const boolean Cpr_Max_EspEbdFailr = 1;

const boolean Cpr_Min_EspAbsActv = 0;
const boolean Cpr_Max_EspAbsActv = 1;

const boolean Cpr_Min_EspAbsFailr = 0;
const boolean Cpr_Max_EspAbsFailr = 1;

const boolean Cpr_Min_EspActvSts = 0;
const boolean Cpr_Max_EspActvSts = 1;

const boolean Cpr_Min_EspTcsFailr = 0;
const boolean Cpr_Max_EspTcsFailr = 1;

const uint8 Cpr_Min_ESP_PrefillAvailable = 0;
const uint8 Cpr_Max_ESP_PrefillAvailable = 1;

const uint8 Cpr_Min_ESP_ABAavailable = 0;
const uint8 Cpr_Max_ESP_ABAavailable = 1;

const uint8 Cpr_Min_ESP_AEBAvailable = 0;
const uint8 Cpr_Max_ESP_AEBAvailable = 1;

const boolean Cpr_Min_ESP_AEBdecActive = 0;
const boolean Cpr_Max_ESP_AEBdecActive = 1;

const uint8 Cpr_Min_ESP_AWBavailable = 0;
const uint8 Cpr_Max_ESP_AWBavailable = 1;

const uint8 Cpr_Min_WhlSpdFrntLePls = 0;
const uint8 Cpr_Max_WhlSpdFrntLePls = 254;

const uint8 Cpr_Min_WhlSpdFrntRiPls = 0;
const uint8 Cpr_Max_WhlSpdFrntRiPls = 254;

const uint8 Cpr_Min_WhlSpdReLePls = 0;
const uint8 Cpr_Max_WhlSpdReLePls = 254;

const uint8 Cpr_Min_WhlSpdReRiPls = 0;
const uint8 Cpr_Max_WhlSpdReRiPls = 254;

const uint8 Cpr_Min_WhlSpdLeFrntDir = 0;
const uint8 Cpr_Max_WhlSpdLeFrntDir = 3;

const uint8 Cpr_Min_WhlSpdLeReDir = 0;
const uint8 Cpr_Max_WhlSpdLeReDir = 3;

const uint8 Cpr_Min_WhlSpdRiFrntDir = 0;
const uint8 Cpr_Max_WhlSpdRiFrntDir = 3;

const uint8 Cpr_Min_WhlSpdRiReDir = 0;
const uint8 Cpr_Max_WhlSpdRiReDir = 3;

const uint16 Cpr_Min_WhlSpdLeFrntData = 0;
const uint16 Cpr_Max_WhlSpdLeFrntData = 6400;

const uint8 Cpr_Min_WhlSpdLeFrntDataVld = 0;
const uint8 Cpr_Max_WhlSpdLeFrntDataVld = 1;

const uint16 Cpr_Min_WhlSpdLeReData = 0;
const uint16 Cpr_Max_WhlSpdLeReData = 6400;

const uint8 Cpr_Min_WhlSpdLeReDataVld = 0;
const uint8 Cpr_Max_WhlSpdLeReDataVld = 1;

const uint16 Cpr_Min_WhlSpdRiFrntData = 0;
const uint16 Cpr_Max_WhlSpdRiFrntData = 6400;

const uint8 Cpr_Min_WhlSpdRiFrntDataVld = 0;
const uint8 Cpr_Max_WhlSpdRiFrntDataVld = 1;

const uint16 Cpr_Min_WhlSpdRiReData = 0;
const uint16 Cpr_Max_WhlSpdRiReData = 6400;

const uint8 Cpr_Min_WhlSpdRiReDataVld = 0;
const uint8 Cpr_Max_WhlSpdRiReDataVld = 1;

const uint16 Cpr_Min_EPS_ActualTorsionBarTorq = 0;
const uint16 Cpr_Max_EPS_ActualTorsionBarTorq = 2046;

const uint16 Cpr_Min_EPS_ActualMotorTorq = 0;
const uint16 Cpr_Max_EPS_ActualMotorTorq = 4094;

const boolean Cpr_Min_EpsSasCalSts = 0;
const boolean Cpr_Max_EpsSasCalSts = 1;

const sint16 Cpr_Min_EpsSasSteerAg = -7800;
const sint16 Cpr_Max_EpsSasSteerAg = 7800;

const boolean Cpr_Min_EpsSasSteerAgVld = 0;
const boolean Cpr_Max_EpsSasSteerAgVld = 1;

const uint8 Cpr_Min_EpsSteerAgRate = 0;
const uint8 Cpr_Max_EpsSteerAgRate = 254;

const boolean Cpr_Min_EPS_LatCtrlActive = 0;
const boolean Cpr_Max_EPS_LatCtrlActive = 1;

const uint8 Cpr_Min_EPS_LatCtrlAvailabilityStatus = 0;
const uint8 Cpr_Max_EPS_LatCtrlAvailabilityStatus = 3;

const uint16 Cpr_Min_EPS_MeasuredTorsionBarTorque = 0;
const uint16 Cpr_Max_EPS_MeasuredTorsionBarTorque = 4094;

const boolean Cpr_Min_EPS_MeasuredTorsionBarTorqValid = 0;
const boolean Cpr_Max_EPS_MeasuredTorsionBarTorqValid = 1;

const uint16 Cpr_Min_EPS_Pinionang = 0;
const uint16 Cpr_Max_EPS_Pinionang = 14400;

const uint8 Cpr_Min_EPS_ConcussAvailabilityStatus = 0;
const uint8 Cpr_Max_EPS_ConcussAvailabilityStatus = 3;

const uint8 Cpr_Min_EPS_IACC_abortreason = 0;
const uint8 Cpr_Max_EPS_IACC_abortreason = 7;

const uint8 Cpr_Min_SrsDrvrBucSwtSts = 0;
const uint8 Cpr_Max_SrsDrvrBucSwtSts = 3;

const uint8 Cpr_Min_SrsPassBucSwtSts = 0;
const uint8 Cpr_Max_SrsPassBucSwtSts = 3;

const uint16 Cpr_Min_EspVehSpd = 0;
const uint16 Cpr_Max_EspVehSpd = 8191;

const boolean Cpr_Min_EPS_Pinionang_Valid = 0;
const boolean Cpr_Max_EPS_Pinionang_Valid = 1;

const uint8 Cpr_Min_EpsFaild = 0;
const uint8 Cpr_Max_EpsFaild = 7;

const uint8 Cpr_Min_ACC_IACCHWAMode = 0;
const uint8 Cpr_Max_ACC_IACCHWAMode = 7;

const uint8 Cpr_Min_ACC_ACCMode = 0;
const uint8 Cpr_Max_ACC_ACCMode = 7;

const uint8 Cpr_Min_EPS_fault_state = 0;
const uint8 Cpr_Max_EPS_fault_state = 15;

const uint8 Cpr_Min_EPS_APA_EpasFAILED = 0;
const uint8 Cpr_Max_EPS_APA_EpasFAILED = 1;

const uint8 Cpr_Min_EspVdcActvSts = 0;
const uint8 Cpr_Max_EspVdcActvSts = 1;

const boolean Cpr_Min_EspTcsActvSts = 0;
const boolean Cpr_Max_EspTcsActvSts = 1;

const uint8 Cpr_Min_BcmEmgyLiSts = 0;
const uint8 Cpr_Max_BcmEmgyLiSts = 3;

const uint8 Cpr_Min_BCM_TurnLightSwitchSts = 0;
const uint8 Cpr_Max_BCM_TurnLightSwitchSts = 3;

const uint8 Cpr_Min_BCM_BrakeLampError = 0;
const uint8 Cpr_Max_BCM_BrakeLampError = 1;

const uint16 Cpr_Min_ESP_LatAccel = 0;
const uint16 Cpr_Max_ESP_LatAccel = 8191;

const uint16 Cpr_Min_ESP_LongAccel = 0;
const uint16 Cpr_Max_ESP_LongAccel = 8191;

const uint8 Cpr_Min_ESP_YawRateValid = 0;
const uint8 Cpr_Max_ESP_YawRateValid = 3;

const uint16 Cpr_Min_ESP_YawRate = 0;
const uint16 Cpr_Max_ESP_YawRate = 16383;

const uint8 Cpr_Min_ESP_LatAccelValid = 0;
const uint8 Cpr_Max_ESP_LatAccelValid = 3;

const uint8 Cpr_Min_ESP_LongAccelValid = 0;
const uint8 Cpr_Max_ESP_LongAccelValid = 3;

const uint16 Cpr_Min_IBCU_PFSBrakePressure = 0;
const uint16 Cpr_Max_IBCU_PFSBrakePressure = 2500;

const uint16 Cpr_Min_IBCU_PlungerBrakePressure = 0;
const uint16 Cpr_Max_IBCU_PlungerBrakePressure = 2500;

const uint8 Cpr_Min_IbBrkPedlStsGb = 0;
const uint8 Cpr_Max_IbBrkPedlStsGb = 255;

const uint8 Cpr_Min_IbBrkPedlStsGbVld = 0;
const uint8 Cpr_Max_IbBrkPedlStsGbVld = 2;

const uint8 Cpr_Min_IBCU_PFSBrakePressureValid = 0;
const uint8 Cpr_Max_IBCU_PFSBrakePressureValid = 1;

const uint8 Cpr_Min_FR_FRadarCalibrationStatus = 0;
const uint8 Cpr_Max_FR_FRadarCalibrationStatus = 3;

const uint8 Cpr_Min_FR_RadarFailureStatus = 0;
const uint8 Cpr_Max_FR_RadarFailureStatus = 7;

const uint8 Cpr_Min_ADS_UDLCStatus = 0;
const uint8 Cpr_Max_ADS_UDLCStatus = 15;

const uint16 Cpr_Min_RLR_ElkOBJ1_Length = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_Length = 510;

const uint16 Cpr_Min_RLR_ElkOBJ1_Dy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_Dy = 2047;

const uint16 Cpr_Min_RLR_ElkOBJ1_Dx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_Dx = 8191;

const uint16 Cpr_Min_RLR_ElkOBJ1_RelVy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_RelVy = 1023;

const uint16 Cpr_Min_RLR_ElkOBJ1_RelVx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_RelVx = 4095;

const uint16 Cpr_Min_RLR_ElkOBJ1_RelAx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_RelAx = 511;

const uint8 Cpr_Min_RLR_ElkOBJ1_Location = 0;
const uint8 Cpr_Max_RLR_ElkOBJ1_Location = 3;

const uint8 Cpr_Min_RLR_ElkOBJ1_ExistProb = 0;
const uint8 Cpr_Max_RLR_ElkOBJ1_ExistProb = 50;

const uint8 Cpr_Min_RLR_ElkOBJ1_Measured = 0;
const uint8 Cpr_Max_RLR_ElkOBJ1_Measured = 3;

const uint16 Cpr_Min_RLR_ElkOBJ2_Length = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_Length = 510;

const uint16 Cpr_Min_RLR_ElkOBJ2_Dy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_Dy = 2047;

const uint16 Cpr_Min_RLR_ElkOBJ2_Dx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_Dx = 8191;

const uint16 Cpr_Min_RLR_ElkOBJ2_RelVy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_RelVy = 1023;

const uint16 Cpr_Min_RLR_ElkOBJ2_RelVx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_RelVx = 4095;

const uint16 Cpr_Min_RLR_ElkOBJ2_RelAx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_RelAx = 511;

const uint8 Cpr_Min_RLR_ElkOBJ2_Location = 0;
const uint8 Cpr_Max_RLR_ElkOBJ2_Location = 3;

const uint8 Cpr_Min_RLR_ElkOBJ2_ExistProb = 0;
const uint8 Cpr_Max_RLR_ElkOBJ2_ExistProb = 50;

const uint8 Cpr_Min_RLR_ElkOBJ2_Measured = 0;
const uint8 Cpr_Max_RLR_ElkOBJ2_Measured = 3;

const uint16 Cpr_Min_RLR_ElkOBJ3_Length = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_Length = 510;

const uint16 Cpr_Min_RLR_ElkOBJ3_Dy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_Dy = 2047;

const uint16 Cpr_Min_RLR_ElkOBJ3_Dx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_Dx = 8191;

const uint16 Cpr_Min_RLR_ElkOBJ3_RelVy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_RelVy = 1023;

const uint16 Cpr_Min_RLR_ElkOBJ3_RelVx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_RelVx = 4095;

const uint16 Cpr_Min_RLR_ElkOBJ3_RelAx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_RelAx = 511;

const uint8 Cpr_Min_RLR_ElkOBJ3_Location = 0;
const uint8 Cpr_Max_RLR_ElkOBJ3_Location = 3;

const uint8 Cpr_Min_RLR_ElkOBJ3_ExistProb = 0;
const uint8 Cpr_Max_RLR_ElkOBJ3_ExistProb = 50;

const uint8 Cpr_Min_RLR_ElkOBJ3_Measured = 0;
const uint8 Cpr_Max_RLR_ElkOBJ3_Measured = 3;

const uint16 Cpr_Min_RLR_ElkOBJ4_Length = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_Length = 510;

const uint16 Cpr_Min_RLR_ElkOBJ4_Dy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_Dy = 2047;

const uint16 Cpr_Min_RLR_ElkOBJ4_Dx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_Dx = 8191;

const uint16 Cpr_Min_RLR_ElkOBJ4_RelVy = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_RelVy = 1023;

const uint16 Cpr_Min_RLR_ElkOBJ4_RelVx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_RelVx = 4095;

const uint16 Cpr_Min_RLR_ElkOBJ4_RelAx = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_RelAx = 511;

const uint16 Cpr_Min_RLR_ElkOBJ1_Width = 0;
const uint16 Cpr_Max_RLR_ElkOBJ1_Width = 12;

const uint16 Cpr_Min_RLR_ElkOBJ2_Width = 0;
const uint16 Cpr_Max_RLR_ElkOBJ2_Width = 12;

const uint16 Cpr_Min_RLR_ElkOBJ3_Width = 0;
const uint16 Cpr_Max_RLR_ElkOBJ3_Width = 12;

const uint16 Cpr_Min_RLR_ElkOBJ4_Width = 0;
const uint16 Cpr_Max_RLR_ElkOBJ4_Width = 12;

const uint8 Cpr_Min_RLR_ElkOBJ4_Location = 0;
const uint8 Cpr_Max_RLR_ElkOBJ4_Location = 3;

const uint8 Cpr_Min_RLR_ElkOBJ4_ExistProb = 0;
const uint8 Cpr_Max_RLR_ElkOBJ4_ExistProb = 50;

const uint8 Cpr_Min_RLR_ElkOBJ4_Measured = 0;
const uint8 Cpr_Max_RLR_ElkOBJ4_Measured = 3;

const uint16 Cpr_Min_IbBrkPedlTrvlDrvr = 0;
const uint16 Cpr_Max_IbBrkPedlTrvlDrvr = 3328;

const sint16 Cpr_Min_IbBrkPedlTrvlDrvrVld = 0;
const sint16 Cpr_Max_IbBrkPedlTrvlDrvrVld = 2;

/*TODO : Signal Phy Data definition*/


/*==================[external data]=========================================*/

/*==================[external constants]====================================*/
const s_Cpr_SignalStatusUpdated_t Cpr_SignalStatus_ConfigTable[CPR_CHECK_SIGNALSTAUTS_NUMBER] =
{
    {              
	    ComConf_ComSignal_SGBcmDrvrDoorSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmDrvrDoorSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmLeReDoorSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmLeReDoorSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmPassDoorSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmPassDoorSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmRiReDoorSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmRiReDoorSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspEbdFailr_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspEbdFailr_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspAbsActv_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspAbsActv_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspAbsFailr_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspAbsFailr_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspActvSts_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspActvSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspTcsFailr_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspTcsFailr_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_AEBdecActive_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspAEBdecActive_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspTcsActvSts_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspTcsActvSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_LatCtrlActive_382R    /*Vlaue_SignalId*/
	    ,GW_17E		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlActive_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGIP_QDashACCFail_734R    /*Vlaue_SignalId*/
	    ,GW_2DE		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_IP_QDashACCFail_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmAutHeadLiSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmAutHeadLiSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmFrntWiperSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmFrntWiperSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmHiBeamSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmHiBeamSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmLoBeamSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmLoBeamSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBCM_TurnLightSwitchSts_651R    /*Vlaue_SignalId*/
	    ,GW_28B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BCM_TurnLightSwitchSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmTurnIndcrLe_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrLe_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmTurnIndcrRi_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrRi_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGVcuGearPosn_353R    /*Vlaue_SignalId*/
	    ,VCU_161		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_ExistProb_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_ExistProb_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_ExistProb_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_ExistProb_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_ExistProb_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_ExistProb_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_ExistProb_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_ExistProb_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_Measured_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Measured_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_Measured_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Measured_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_Measured_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Measured_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_Measured_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Measured_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_Location_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Location_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_Location_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Location_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_Location_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Location_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_Location_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Location_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGSrsDrvrBucSwtSts_80R    /*Vlaue_SignalId*/
	    ,GW_50		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_SrsDrvrBucSwtSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGSrsPassBucSwtSts_80R    /*Vlaue_SignalId*/
	    ,GW_50		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_SrsPassBucSwtSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_ConcussAvailabilityStatus_591R    /*Vlaue_SignalId*/
	    ,GW_24F		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsConcussAvailabilityStatus_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_IACC_abortreason_591R    /*Vlaue_SignalId*/
	    ,GW_24F		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsIACCabortreason_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_LatCtrlAvailabilityStatus_382R    /*Vlaue_SignalId*/
	    ,GW_17E		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlAvailabilityStatus_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_AEBAvailable_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspAEBAvailable_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_AWBavailable_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspAWBavailable_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_ABAavailable_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspABAavailable_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_PrefillAvailable_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspPrefillAvailable_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdLeFrntDir_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDir_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdRiFrntDir_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDir_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdLeReDir_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDir_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdRiReDir_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDir_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGACC_ACCMode_411R    /*Vlaue_SignalId*/
	    ,ADC_19B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_ACCMode_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGACC_IACCHWAMode_411R    /*Vlaue_SignalId*/
	    ,ADC_19B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_AccIaccHWAMode_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmEmgyLiSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmEmgyLiSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGIbBrkPedlStsGb_706R    /*Vlaue_SignalId*/
	    ,GW_2C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspVdcActvSts_450R    /*Vlaue_SignalId*/
	    ,GW_1C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspVdcActvSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmFrntFogLmpSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmFrntFogLmpSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBcmReFoglmpSts_648R    /*Vlaue_SignalId*/
	    ,GW_288		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BcmReFoglmpSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGADS_UDLCStatus_411R    /*Vlaue_SignalId*/
	    ,ADC_19B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_AdsUDLCStatus_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEpsSteerAgRate_384R    /*Vlaue_SignalId*/
	    ,GW_180		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsSteerAgRate_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEspVehSpd_378R    /*Vlaue_SignalId*/
	    ,GW_17A		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEpsSasSteerAg_384R    /*Vlaue_SignalId*/
	    ,GW_180		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_YawRate_632R    /*Vlaue_SignalId*/
	    ,GW_278		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspYawRate_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_LongAccel_632R    /*Vlaue_SignalId*/
	    ,GW_278		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGESP_LatAccel_632R    /*Vlaue_SignalId*/
	    ,GW_278		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_Dx_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_Dx_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_Dx_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_Dx_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_RelVx_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_RelVx_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_RelVx_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_RelVx_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_RelAx_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelAx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_RelAx_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelAx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_RelAx_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelAx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_RelAx_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelAx_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_Dy_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_Dy_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_Dy_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_Dy_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_RelVy_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_RelVy_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_RelVy_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVy_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_RelVy_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVy_Status		/*Rte_Write_PP_Signal_State*/
	}
    ,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_Width_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Width_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_Width_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Width_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_Width_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Width_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_Width_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Width_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_MeasuredTorsionBarTorque_382R    /*Vlaue_SignalId*/
	    ,GW_17E		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGIBCU_PlungerBrakePressure_706R    /*Vlaue_SignalId*/
	    ,GW_2C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGIBCU_PFSBrakePressure_706R    /*Vlaue_SignalId*/
	    ,GW_2C2		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_BrakePressureSimulator_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGVcuAccrPedlPosn_353R    /*Vlaue_SignalId*/
	    ,VCU_161		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_Pinionang_382R    /*Vlaue_SignalId*/
	    ,GW_17E		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdLeFrntData_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdLeReData_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdRiFrntData_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdRiReData_523R    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ1_Length_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Length_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ2_Length_837R    /*Vlaue_SignalId*/
	    ,ADC_345		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Length_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ3_Length_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Length_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGRLR_ElkOBJ4_Length_838R    /*Vlaue_SignalId*/
	    ,ADC_346		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Length_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdFrntLePls_523R	    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntLePls_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdFrntRiPls_523R	    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntRiPls_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdReLePls_523R	    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReLePls_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGWhlSpdReRiPls_523R	    /*Vlaue_SignalId*/
	    ,GW_20B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReRiPls_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEpsSasCalSts_384R	    /*Vlaue_SignalId*/
	    ,GW_180		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsSasCalSts_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_fault_state_368R	    /*Vlaue_SignalId*/
	    ,GW_170		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EPS_fault_state_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_ActualTorsionBarTorq_368R	    /*Vlaue_SignalId*/
	    ,GW_170		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualTorsionBarTorq_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_ActualMotorTorq_368R	    /*Vlaue_SignalId*/
	    ,GW_170		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualMotorTorq_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEpsFaild_591R	    /*Vlaue_SignalId*/
	    ,GW_24F		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EpsFaild_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGEPS_APA_EpasFAILED_591R	    /*Vlaue_SignalId*/
	    ,GW_24F		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Chassis_Data_EPS_APA_EpasFAILED_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGIP_DISFail_734R	    /*Vlaue_SignalId*/
	    ,GW_2DE		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_IP_DISFail_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGFR_FRadarCalibrationStatus_310R	    /*Vlaue_SignalId*/
	    ,FR_136		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_FRadarCalibrationStatus_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGFR_RadarFailureStatus_310R	    /*Vlaue_SignalId*/
	    ,FR_136		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Adas_Data_FR_RadarFailureStatus_Status		/*Rte_Write_PP_Signal_State*/
	}
	,{              
	    ComConf_ComSignal_SGBCM_BrakeLampError_651R	    /*Vlaue_SignalId*/
	    ,GW_28B		/*RxMsgID*/
	    ,Cpr_SignalFrom_USER     /*SignalPhyDataStoredType*/              
	    ,NULL_PTR    /*SignalPhyData*/              
	    ,E_SIG_STATUS_VALID      /*SignalPhyData_Valid*/              
	    ,E_SIG_STATUS_INVALID      /*SignalPhyData_Invalid*/
	    ,Rte_Write_PP_Cpr_Body_Data_BCM_BrakeLampError_Status		/*Rte_Write_PP_Signal_State*/
	}
};



/*==================[internal constants]====================================*/
const s_Cpr_ReceiveSignalConfig_t Cpr_ReceiveSignalConfigTable[CPR_REVEIVE_SIGNAL_NUMBER] =
{
    {
        ComConf_ComSignal_SGEpsSasSteerAgVld_384R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EpsSasSteerAgVld		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EpsSasSteerAgVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAgVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_MeasuredTorsionBarTorqValid_382R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EPS_MeasuredTorsionBarTorqValid		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EPS_MeasuredTorsionBarTorqValid		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_MeasuredTorsionBarTorqValid    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_Pinionang_Valid_382R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EPS_Pinionang_Valid		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EPS_Pinionang_Valid		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_Pinionang_Valid    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspVehSpdVld_378R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_EspVehSpdVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_EspVehSpdVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpdVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_YawRateValid_632R    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_YawRateValid		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_YawRateValid		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_YawRateValid    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_LongAccelValid_632R    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_LongAccelValid		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_LongAccelValid		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_LongAccelValid    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_LatAccelValid_632R    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_LatAccelValid		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_LatAccelValid		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_LatAccelValid    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIBCU_PFSBrakePressureValid_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_IBCU_PFSBrakePressureValid		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_IBCU_PFSBrakePressureValid		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_IBCU_PFSBrakePressureValid    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGVcuAccrPedlPosnVld_353R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_VcuAccrPedlPosnVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_VcuAccrPedlPosnVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosnVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGVcuVehGearPosnVld_353R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_VcuVehGearPosnVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_VcuVehGearPosnVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuVehGearPosnVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdLeFrntDataVld_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdLeFrntDataVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdLeFrntDataVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDataVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdRiFrntDataVld_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdRiFrntDataVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdRiFrntDataVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDataVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdLeReDataVld_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdLeReDataVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdLeReDataVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDataVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdRiReDataVld_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdRiReDataVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdRiReDataVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDataVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIbBrkPedlStsGbVld_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_IbBrkPedlStsGbVld		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_IbBrkPedlStsGbVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGbVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmDrvrDoorSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_BcmDrvrDoorSts		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_BcmDrvrDoorSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmDrvrDoorSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmLeReDoorSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_BcmLeReDoorSts		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_BcmLeReDoorSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmLeReDoorSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmPassDoorSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_BcmPassDoorSts		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_BcmPassDoorSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmPassDoorSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmRiReDoorSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_BcmRiReDoorSts		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_BcmRiReDoorSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmRiReDoorSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspEbdFailr_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EspEbdFailr		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EspEbdFailr		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspEbdFailr    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspAbsActv_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EspAbsActv		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EspAbsActv		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsActv    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspAbsFailr_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EspAbsFailr		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EspAbsFailr		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsFailr    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspActvSts_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EspActvSts		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EspActvSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspActvSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspTcsFailr_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EspTcsFailr		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EspTcsFailr		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsFailr    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_AEBdecActive_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_ESP_AEBdecActive		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_ESP_AEBdecActive		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBdecActive    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspTcsActvSts_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EspTcsActvSts		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EspTcsActvSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsActvSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_LatCtrlActive_382R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_EPS_LatCtrlActive		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_EPS_LatCtrlActive		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlActive    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIP_QDashACCFail_734R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_IP_QDashACCFail		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_IP_QDashACCFail		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_IP_QDashACCFail    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmAutHeadLiSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmAutHeadLiSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmAutHeadLiSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmAutHeadLiSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmFrntWiperSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmFrntWiperSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmFrntWiperSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntWiperSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmHiBeamSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmHiBeamSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmHiBeamSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmHiBeamSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmLoBeamSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmLoBeamSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmLoBeamSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmLoBeamSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBCM_TurnLightSwitchSts_651R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BCM_TurnLightSwitchSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BCM_TurnLightSwitchSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BCM_TurnLightSwitchSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmTurnIndcrLe_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmTurnIndcrLe		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmTurnIndcrLe		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrLe    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmTurnIndcrRi_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmTurnIndcrRi		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmTurnIndcrRi		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrRi    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGVcuGearPosn_353R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_VcuGearPosn		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_VcuGearPosn		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_ExistProb_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,2.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ1_ExistProb		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ1_ExistProb		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_ExistProb    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_ExistProb_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,2.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ2_ExistProb		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ2_ExistProb		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_ExistProb    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_ExistProb_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,2.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ3_ExistProb		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ3_ExistProb		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_ExistProb    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_ExistProb_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,2.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ4_ExistProb		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ4_ExistProb		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_ExistProb    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_Measured_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ1_Measured		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ1_Measured		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Measured    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_Measured_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ2_Measured		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ2_Measured		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Measured    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_Measured_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ3_Measured		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ3_Measured		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Measured    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_Measured_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ4_Measured		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ4_Measured		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Measured    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_Location_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ1_Location		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ1_Location		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Location    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_Location_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ2_Location		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ2_Location		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Location    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_Location_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ3_Location		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ3_Location		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Location    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_Location_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_RLR_ElkOBJ4_Location		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_RLR_ElkOBJ4_Location		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Location    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGSrsDrvrBucSwtSts_80R    /*SignalId*/
        ,250    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_SrsDrvrBucSwtSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_SrsDrvrBucSwtSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_SrsDrvrBucSwtSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGSrsPassBucSwtSts_80R    /*SignalId*/
        ,250    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_SrsPassBucSwtSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_SrsPassBucSwtSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_SrsPassBucSwtSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
	}
    ,{
        ComConf_ComSignal_SGEPS_ConcussAvailabilityStatus_591R    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_EPS_ConcussAvailabilityStatus		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_EPS_ConcussAvailabilityStatus		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsConcussAvailabilityStatus    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_IACC_abortreason_591R    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_EPS_IACC_abortreason		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_EPS_IACC_abortreason		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsIACCabortreason    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
	,{
        ComConf_ComSignal_SGEPS_LatCtrlAvailabilityStatus_382R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_EPS_LatCtrlAvailabilityStatus		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_EPS_LatCtrlAvailabilityStatus		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlAvailabilityStatus    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_AEBAvailable_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_AEBAvailable		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_AEBAvailable		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBAvailable    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_AWBavailable_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_AWBavailable		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_AWBavailable		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAWBavailable    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_ABAavailable_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_ABAavailable		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_ABAavailable		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspABAavailable    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_PrefillAvailable_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ESP_PrefillAvailable		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ESP_PrefillAvailable		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspPrefillAvailable    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdLeFrntDir_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdLeFrntDir		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdLeFrntDir		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDir    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdRiFrntDir_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdRiFrntDir		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdRiFrntDir		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDir    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdLeReDir_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdLeReDir		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdLeReDir		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDir    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdRiReDir_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_WhlSpdRiReDir		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_WhlSpdRiReDir		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDir    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
	}
    ,{
        ComConf_ComSignal_SGACC_ACCMode_411R    /*SignalId*/
        ,100    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ACC_ACCMode		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ACC_ACCMode		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_ACCMode    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGACC_IACCHWAMode_411R    /*SignalId*/
        ,100    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ACC_IACCHWAMode		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ACC_IACCHWAMode		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_AccIaccHWAMode    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmEmgyLiSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmEmgyLiSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmEmgyLiSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmEmgyLiSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIbBrkPedlStsGb_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_IbBrkPedlStsGb		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_IbBrkPedlStsGb		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspVdcActvSts_450R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_EspVdcActvSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_EspVdcActvSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVdcActvSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmFrntFogLmpSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmFrntFogLmpSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmFrntFogLmpSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntFogLmpSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBcmReFoglmpSts_648R    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_BcmReFoglmpSts		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_BcmReFoglmpSts		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmReFoglmpSts    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGADS_UDLCStatus_411R    /*SignalId*/
        ,100    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint8*)&Cpr_Min_ADS_UDLCStatus		/*SignalRawData_Lower*/
		,(uint8*)&Cpr_Max_ADS_UDLCStatus		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_AdsUDLCStatus    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEpsSteerAgRate_384R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint16    /*SignalPhyDataType*/
        ,4.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(uint16*)&Cpr_Min_EpsSteerAgRate		/*SignalRawData_Lower*/
		,(uint16*)&Cpr_Max_EpsSteerAgRate		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSteerAgRate    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEspVehSpd_378R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05625f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_EspVehSpd		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_EspVehSpd		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    } 
    ,{
        ComConf_ComSignal_SGEpsSasSteerAg_384R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Sint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.1f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_EpsSasSteerAg		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_EpsSasSteerAg		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_YawRate_632R    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.01f    /*LinearMode_Factor*/
        ,-81.91f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_ESP_YawRate		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_ESP_YawRate		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspYawRate    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_LongAccel_632R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.01f    /*LinearMode_Factor*/
        ,-32.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_ESP_LongAccel		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_ESP_LongAccel		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGESP_LatAccel_632R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.01f    /*LinearMode_Factor*/
        ,-32.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_ESP_LatAccel		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_ESP_LatAccel		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_Dx_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-256    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_Dx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_Dx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_Dx_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-256    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_Dx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_Dx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_Dx_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-256    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_Dx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_Dx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_Dx_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-256    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_Dx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_Dx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_RelVx_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_RelVx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_RelVx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_RelVx_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_RelVx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_RelVx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_RelVx_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_RelVx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_RelVx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_RelVx_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_RelVx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_RelVx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_RelAx_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_RelAx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_RelAx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelAx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_RelAx_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_RelAx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_RelAx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelAx    /*Op_WriteSignalPhyData*/    
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_RelAx_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_RelAx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_RelAx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelAx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_RelAx_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.0625f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_RelAx		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_RelAx		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelAx    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_Dy_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.125f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_Dy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_Dy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_Dy_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.125f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_Dy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_Dy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_Dy_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.125f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_Dy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_Dy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_Dy_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.125f    /*LinearMode_Factor*/
        ,-128    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_Dy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_Dy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_RelVy_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.03125f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_RelVy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_RelVy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_RelVy_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.03125f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_RelVy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_RelVy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_RelVy_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.03125f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_RelVy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_RelVy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_RelVy_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.03125f    /*LinearMode_Factor*/
        ,-16    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_RelVy		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_RelVy		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVy    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_Width_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_Width		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_Width		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Width    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_Width_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_Width		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_Width		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Width    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_Width_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_Width		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_Width		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Width    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_Width_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_Width		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_Width		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Width    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_MeasuredTorsionBarTorque_382R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.01f    /*LinearMode_Factor*/
        ,-20.48    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_EPS_MeasuredTorsionBarTorque		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_EPS_MeasuredTorsionBarTorque		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIBCU_PlungerBrakePressure_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.1f    /*LinearMode_Factor*/
        ,1.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_IBCU_PlungerBrakePressure		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_IBCU_PlungerBrakePressure		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIBCU_PFSBrakePressure_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.1f    /*LinearMode_Factor*/
        ,0.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_IBCU_PFSBrakePressure		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_IBCU_PFSBrakePressure		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_BrakePressureSimulator    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIbBrkPedlTrvlDrvr_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.015625f    /*LinearMode_Factor*/
        ,-5.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_IbBrkPedlTrvlDrvr		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_IbBrkPedlTrvlDrvr		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvr    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIbBrkPedlTrvlDrvrVld_706R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(boolean*)&Cpr_Min_IbBrkPedlTrvlDrvrVld		/*SignalRawData_Lower*/
		,(boolean*)&Cpr_Max_IbBrkPedlTrvlDrvrVld		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvrVld    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGVcuAccrPedlPosn_353R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.1f    /*LinearMode_Factor*/
        ,0.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_VcuAccrPedlPosn		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_VcuAccrPedlPosn		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_Pinionang_382R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.1f    /*LinearMode_Factor*/
        ,-720.0f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_EPS_Pinionang		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_EPS_Pinionang		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdLeFrntData_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05625f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_WhlSpdLeFrntData		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_WhlSpdLeFrntData		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdLeReData_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05625f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_WhlSpdLeReData		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_WhlSpdLeReData		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdRiFrntData_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05625f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_WhlSpdRiFrntData		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_WhlSpdRiFrntData		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdRiReData_523R    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05625f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_WhlSpdRiReData		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_WhlSpdRiReData		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ1_Length_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ1_Length		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ1_Length		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Length    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ2_Length_837R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ2_Length		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ2_Length		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Length    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ3_Length_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ3_Length		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ3_Length		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Length    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGRLR_ElkOBJ4_Length_838R    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear    /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.05f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
		,Cpr_SigDataValRangeCheck_Range		/*SignalValueRangeCheckMode*/
		,(float32*)&Cpr_Min_RLR_ElkOBJ4_Length		/*SignalRawData_Lower*/
		,(float32*)&Cpr_Max_RLR_ElkOBJ4_Length		/*SignalRawData_Upper*/
		,NULL_PTR		/*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Length    /*Op_WriteSignalPhyData*/
		,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdFrntLePls_523R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_WhlSpdFrntLePls    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_WhlSpdFrntLePls    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntLePls    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdFrntRiPls_523R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_WhlSpdFrntRiPls    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_WhlSpdFrntRiPls    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntRiPls    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdReLePls_523R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_WhlSpdReLePls    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_WhlSpdReLePls    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReLePls    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGWhlSpdReRiPls_523R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_WhlSpdReRiPls    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_WhlSpdReRiPls    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReRiPls    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEpsSasCalSts_384R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean    /*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(boolean*)&Cpr_Min_EpsSasCalSts    /*SignalRawData_Lower*/
        ,(boolean*)&Cpr_Max_EpsSasCalSts    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasCalSts    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_fault_state_368R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_EPS_fault_state    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_EPS_fault_state    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_fault_state    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_ActualTorsionBarTorq_368R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.02f    /*LinearMode_Factor*/
        ,-20.48f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(float32*)&Cpr_Min_EPS_ActualTorsionBarTorq    /*SignalRawData_Lower*/
        ,(float32*)&Cpr_Max_EPS_ActualTorsionBarTorq    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualTorsionBarTorq    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_ActualMotorTorq_368R	    /*SignalId*/
        ,10    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_Linear      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint16    /*SignalRawDataType*/
        ,Cpr_SigDataType_Float32    /*SignalPhyDataType*/
        ,0.01f    /*LinearMode_Factor*/
        ,-20.48f    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(float32*)&Cpr_Min_EPS_ActualMotorTorq    /*SignalRawData_Lower*/
        ,(float32*)&Cpr_Max_EPS_ActualMotorTorq    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualMotorTorq    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEpsFaild_591R	    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_EpsFaild    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_EpsFaild    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsFaild    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGEPS_APA_EpasFAILED_591R	    /*SignalId*/
        ,20    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_EPS_APA_EpasFAILED    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_EPS_APA_EpasFAILED    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_APA_EpasFAILED    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGIP_DISFail_734R	    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_IP_DISFail    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_IP_DISFail    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_IP_DISFail    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGFR_FRadarCalibrationStatus_310R	    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_FR_FRadarCalibrationStatus    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_FR_FRadarCalibrationStatus    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_FRadarCalibrationStatus    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGFR_RadarFailureStatus_310R	    /*SignalId*/
        ,50    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_FR_RadarFailureStatus    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_FR_RadarFailureStatus    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_FR_RadarFailureStatus    /*Op_WriteSignalPhyData*/
            ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
    ,{
        ComConf_ComSignal_SGBCM_BrakeLampError_651R	    /*SignalId*/
        ,40    /*SignalMonitorCycle*/
        ,1000    /*SignalTimeoutCycle*/
        ,NULL_PTR    /*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None      /*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8    /*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8    /*SignalPhyDataType*/
        ,1.0f    /*LinearMode_Factor*/
        ,0    /*LinearMode_Offset*/
        ,NULL_PTR    /*Op_UserConvertMode*/
        ,Cpr_SigDataValRangeCheck_Range    /*SignalValueRangeCheckMode*/
        ,(uint8*)&Cpr_Min_BCM_BrakeLampError    /*SignalRawData_Lower*/
        ,(uint8*)&Cpr_Max_BCM_BrakeLampError    /*SignalRawData_Upper*/
        ,NULL_PTR    /*Op_UserValueRangeCheck*/
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BCM_BrakeLampError    /*Op_WriteSignalPhyData*/
        ,CPR_Notify_SignalStatusUpdated		/*Notify_SignalStatusUpdated*/
    }
};