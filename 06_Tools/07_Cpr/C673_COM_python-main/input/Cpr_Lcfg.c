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
/*const definition: Signal Range*/

/*TODO : Signal Phy Data definition*/
float32 Cpr_SignalPhyData_EspVehSpd;
float32 Cpr_SignalPhyData_EspYawRate;
float32 Cpr_SignalPhyData_EspLongAccel;
float32 Cpr_SignalPhyData_EspLatAccel;
float32 Cpr_SignalPhyData_ElkObj1_Dx;
float32 Cpr_SignalPhyData_ElkObj2_Dx;
float32 Cpr_SignalPhyData_ElkObj3_Dx;
float32 Cpr_SignalPhyData_ElkObj4_Dx;
float32 Cpr_SignalPhyData_ElkObj1_RelVx;
float32 Cpr_SignalPhyData_ElkObj2_RelVx;
float32 Cpr_SignalPhyData_ElkObj3_RelVx;
float32 Cpr_SignalPhyData_ElkObj4_RelVx;
float32 Cpr_SignalPhyData_ElkObj1_RelAx;
float32 Cpr_SignalPhyData_ElkObj2_RelAx;
float32 Cpr_SignalPhyData_ElkObj3_RelAx;
float32 Cpr_SignalPhyData_ElkObj4_RelAx;
float32 Cpr_SignalPhyData_ElkObj1_Dy;
float32 Cpr_SignalPhyData_ElkObj2_Dy;
float32 Cpr_SignalPhyData_ElkObj3_Dy;
float32 Cpr_SignalPhyData_ElkObj4_Dy;
float32 Cpr_SignalPhyData_ElkObj1_RelVy;
float32 Cpr_SignalPhyData_ElkObj2_RelVy;
float32 Cpr_SignalPhyData_ElkObj3_RelVy;
float32 Cpr_SignalPhyData_ElkObj4_RelVy;
float32 Cpr_SignalPhyData_ElkObj1_Length;
float32 Cpr_SignalPhyData_ElkObj2_Length;
float32 Cpr_SignalPhyData_ElkObj3_Length;
float32 Cpr_SignalPhyData_ElkObj4_Length;
float32 Cpr_SignalPhyData_ElkObj1_Width;
float32 Cpr_SignalPhyData_ElkObj2_Width;
float32 Cpr_SignalPhyData_ElkObj3_Width;
float32 Cpr_SignalPhyData_ElkObj4_Width;
uint8   Cpr_SignalPhyData_BcmPwrStsFb;

//WhlSpdData
float32 Cpr_SignalPhyData_WhlSpdLeFrntData;
float32 Cpr_SignalPhyData_WhlSpdLeReData;
float32 Cpr_SignalPhyData_WhlSpdRiFrntData;
float32 Cpr_SignalPhyData_WhlSpdRiReData;

//GW_2C2
float32 Cpr_SignalPhyData_IBCU_PlungerBrakePressure;
float32 Cpr_SignalPhyData_IBCU_PFSBrakePressure;

float32 Cpr_SignalPhyData_EPS_MeasuredTorsionBarTorque;
// GW_17E/382R
float32 Cpr_SignalPhyData_EPS_Pinionang;
// GW_180/384R
float32 Cpr_SignalPhyData_EpsSasSteerAg;

boolean Cpr_SignalPhyData_BcmDrvrDoorSts;
boolean Cpr_SignalPhyData_BcmLeReDoorSts;
boolean Cpr_SignalPhyData_BcmPassDoorSts;
boolean Cpr_SignalPhyData_BcmRiReDoorSts;
boolean Cpr_SignalPhyData_EspEbdFailr;
boolean Cpr_SignalPhyData_EspAbsActv;
boolean Cpr_SignalPhyData_EspAbsFailr;
boolean Cpr_SignalPhyData_EspActvSts;
boolean Cpr_SignalPhyData_EspTcsFailr;
boolean Cpr_SignalPhyData_ESP_AEBdecActive;
boolean Cpr_SignalPhyData_EspTcsActvSts;
boolean Cpr_SignalPhyData_EPS_LatCtrlActive;
uint8 Cpr_SignalPhyData_BcmAutHeadLiSts;
uint8 Cpr_SignalPhyData_BcmFrntWiperSts;
uint8 Cpr_SignalPhyData_BcmHiBeamSts;
uint8 Cpr_SignalPhyData_BcmLoBeamSts;
uint8 Cpr_SignalPhyData_BcmTurnLightSwitchStst;
uint8 Cpr_SignalPhyData_BcmTurnIndcrLe;
uint8 Cpr_SignalPhyData_BcmTurnIndcrRi;
uint8 Cpr_SignalPhyData_VcuGearPosn;
uint8 Cpr_SignalPhyData_ElkObj1_ExistProb;
uint8 Cpr_SignalPhyData_ElkObj2_ExistProb;
uint8 Cpr_SignalPhyData_ElkObj3_ExistProb;
uint8 Cpr_SignalPhyData_ElkObj4_ExistProb;
uint8 Cpr_SignalPhyData_ElkObj1_Measured;
uint8 Cpr_SignalPhyData_ElkObj2_Measured;
uint8 Cpr_SignalPhyData_ElkObj3_Measured;
uint8 Cpr_SignalPhyData_ElkObj4_Measured;
uint8 Cpr_SignalPhyData_ElkObj1_Location;
uint8 Cpr_SignalPhyData_ElkObj2_Location;
uint8 Cpr_SignalPhyData_ElkObj3_Location;
uint8 Cpr_SignalPhyData_ElkObj4_Location;
uint8 Cpr_SignalPhyData_SrsDrvrBucSwtSts;
uint8 Cpr_SignalPhyData_SrsPassBucSwtSts;
uint8 Cpr_SignalPhyData_EPS_ConcussAvailabilityStatus;
uint8 Cpr_SignalPhyData_EPS_LatCtrlAvailabilityStatus;
uint8 Cpr_SignalPhyData_EPS_IACC_abortreason;
// GW_180/384R
uint16 Cpr_SignalPhyData_EpsSteerAgRate;
uint8 Cpr_SignalPhyData_IP_QDashACCFail;
uint8 Cpr_SignalPhyData_BcmEmgyLiSts;
uint8 Cpr_SignalPhyData_BcmFrntFogLmpSts;
uint8 Cpr_SignalPhyData_BcmReFoglmpSts;
uint8 Cpr_SignalPhyData_ADS_UDLCStatus;

/*20220725 AEB Code Review Add*/
float32 Cpr_SignalPhyData_VcuAccrPedlPosn;

uint8 Cpr_SignalPhyData_ESP_AEBAvailable;
uint8 Cpr_SignalPhyData_ESP_AWBavailable;
uint8 Cpr_SignalPhyData_ESP_ABAavailable;
uint8 Cpr_SignalPhyData_ESP_PrefillAvailable;


/*Replenish VDY signal mapping*/

uint8 Cpr_SignalPhyData_WhlSpdLeFrntDir;
uint8 Cpr_SignalPhyData_WhlSpdRiFrntDir;
uint8 Cpr_SignalPhyData_WhlSpdLeReDir;
uint8 Cpr_SignalPhyData_WhlSpdRiReDir;

//HMI
boolean Cpr_SignalPhyData_HU_AutoBrakeEnable;
uint8 Cpr_SignalPhyData_HU_FCWSetting;
boolean Cpr_SignalPhyData_HU_HMAEnable;
uint8 Cpr_SignalPhyData_HU_LASModeSelection;
uint8 Cpr_SignalPhyData_HU_LASWarningModeSelection;
uint8 Cpr_SignalPhyData_HU_ELKEnable;
uint8 Cpr_SignalPhyData_ACC_ACCMode;
uint8 Cpr_SignalPhyData_ACC_IACCHWAMode;

//GW_2C2
uint8 Cpr_SignalPhyData_IbBrkPedlStsGb;


//GW_1C2
uint8 Cpr_SignalPhyData_EspVdcActvSts;


// GW_17E/382R
boolean Cpr_SignalPhyData_EPS_Pinionang_Valid;
boolean Cpr_SignalPhyData_EPS_MeasuredTorsionBarTorqValid;

//GW_2C2
uint8 Cpr_SignalPhyData_IBCU_PFSBrakePressureValid;
uint8 Cpr_SignalPhyData_IbBrkPedlStsGbVld;
// GW_180/384R
boolean Cpr_SignalPhyData_EpsSasSteerAgVld;

// GW_17A/378R
uint8 Cpr_SignalPhyData_EspVehSpdVld;

// GW_278/632R
uint8 Cpr_SignalPhyData_ESP_YawRateValid;
uint8 Cpr_SignalPhyData_ESP_LongAccelValid;
uint8 Cpr_SignalPhyData_ESP_LatAccelValid;

// VCU_161/353R
uint8 Cpr_SignalPhyData_VcuAccrPedlPosnVld;
uint8 Cpr_SignalPhyData_VcuVehGearPosnVld;
// GW_20B/523R
uint8 Cpr_SignalPhyData_WhlSpdLeFrntDataVld;
uint8 Cpr_SignalPhyData_WhlSpdRiFrntDataVld;
uint8 Cpr_SignalPhyData_WhlSpdLeReDataVld;
uint8 Cpr_SignalPhyData_WhlSpdRiReDataVld;
#if 0
// GW_17E/382R
static boolean Cpr_SignalPhyData_EPS_Pinionang_Valid;
static boolean Cpr_SignalPhyData_EPS_MeasuredTorsionBarTorqValid;
//GW_2C2
static uint8 Cpr_SignalPhyData_IBCU_PFSBrakePressureValid;
static uint8 Cpr_SignalPhyData_IbBrkPedlStsGbVld;
// GW_180/384R
static boolean Cpr_SignalPhyData_EpsSasSteerAgVld;
// GW_17A/378R
static uint8 Cpr_SignalPhyData_EspVehSpdVld;
// GW_278/632R
static uint8 Cpr_SignalPhyData_ESP_YawRateValid;
static uint8 Cpr_SignalPhyData_ESP_LongAccelValid;
static uint8 Cpr_SignalPhyData_ESP_LatAccelValid;
// VCU_161/353R
static uint8 Cpr_SignalPhyData_VcuAccrPedlPosnVld;
static uint8 Cpr_SignalPhyData_VcuVehGearPosnVld;
// GW_20B/523R
static uint8 Cpr_SignalPhyData_WhlSpdLeFrntDataVld;
static uint8 Cpr_SignalPhyData_WhlSpdRiFrntDataVld;
static uint8 Cpr_SignalPhyData_WhlSpdLeReDataVld;
static uint8 Cpr_SignalPhyData_WhlSpdRiReDataVld;
#endif
//GW_24F
uint8 Cpr_SignalFrom_USER_EpsConcussAvailabilityStatus_Status;
// GW_17E/382R
uint8 Cpr_SignalFrom_USER_EpsLatCtrlAvailabilityStatus_Status;

/*==================[external data]=========================================*/

/*==================[external constants]====================================*/

const s_Cpr_SignalStatusUpdated_t Cpr_SignalStatus_ConfigTable[CPR_CHECK_SIGNALSTAUTS_NUMBER] =
{
	{
        ComConf_ComSignal_SGEspVehSpd_378R    /*Vlaue_SignalId*/
		,GW_17A		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_EspVehSpdVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGEpsSasSteerAg_384R    /*Vlaue_SignalId*/
		,GW_180		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_EpsSasSteerAgVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGESP_YawRate_632R    /*Vlaue_SignalId*/
		,GW_278		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_ESP_YawRateValid    /*SignalPhyData*/
		,1      /*SignalPhyData_Valid*/
		,2      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EspYawRate_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGESP_LongAccel_632R    /*Vlaue_SignalId*/
		,GW_278		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_ESP_LongAccelValid    /*SignalPhyData*/
		,1      /*SignalPhyData_Valid*/
		,2      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel_Status      /*Rte_Write_PP_Signal_State*/
	}  
    ,{
        ComConf_ComSignal_SGESP_LatAccel_632R    /*Vlaue_SignalId*/
		,GW_278		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_ESP_LatAccelValid    /*SignalPhyData*/
		,1      /*SignalPhyData_Valid*/
		,2      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel_Status      /*Rte_Write_PP_Signal_State*/
	}  
    ,{
        ComConf_ComSignal_SGEPS_MeasuredTorsionBarTorque_382R    /*Vlaue_SignalId*/
		,GW_17E		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_EPS_MeasuredTorsionBarTorqValid    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGIBCU_PFSBrakePressure_706R    /*Vlaue_SignalId*/
		,GW_2C2		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_IBCU_PFSBrakePressureValid    /*SignalPhyData*/
		,1      /*SignalPhyData_Valid*/
		,0      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGVcuAccrPedlPosn_353R    /*Vlaue_SignalId*/
		,VCU_161		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_VcuAccrPedlPosnVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGVcuGearPosn_353R    /*Vlaue_SignalId*/
		,VCU_161		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_VcuVehGearPosnVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGWhlSpdLeFrntData_523R    /*Vlaue_SignalId*/
		,GW_20B		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_WhlSpdLeFrntDataVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGWhlSpdRiFrntData_523R    /*Vlaue_SignalId*/
		,GW_20B		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_WhlSpdRiFrntDataVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGWhlSpdLeReData_523R    /*Vlaue_SignalId*/
		,GW_20B		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_WhlSpdLeReDataVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGEPS_Pinionang_382R    /*Vlaue_SignalId*/
		,GW_17E		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_EPS_Pinionang_Valid    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGWhlSpdRiReData_523R    /*Vlaue_SignalId*/
		,GW_20B		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_WhlSpdRiReDataVld    /*SignalPhyData*/
		,0      /*SignalPhyData_Valid*/
		,1      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData_Status      /*Rte_Write_PP_Signal_State*/
	}
    ,{
        ComConf_ComSignal_SGIbBrkPedlStsGb_706R    /*Vlaue_SignalId*/
		,GW_2C2		/*RxMsgID*/
        ,Cpr_SignalFrom_DBC     /*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_IbBrkPedlStsGbVld    /*SignalPhyData*/
		,1      /*SignalPhyData_Valid*/
		,2      /*SignalPhyData_Invalid*/
		,Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb_Status      /*Rte_Write_PP_Signal_State*/
	}
};


/*==================[internal constants]====================================*/
const s_Cpr_ReceiveSignalConfig_t Cpr_ReceiveSignalConfigTable[CPR_REVEIVE_SIGNAL_NUMBER] =
{
    {
		ComConf_ComSignal_SGHU_HMAEnable_1287R /*SignalId*/
		,10 /*SignalMonitorCycle*/
		,1000 /*SignalTimeoutCycle*/
		,NULL_PTR /*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_None /*SignalDataConversionMode*/
		,Cpr_SigDataType_Boolean /*SignalRawDataType*/
		,Cpr_SigDataType_Boolean /*SignalPhyDataType*/
		,1.0f /*LinearMode_Factor*/
		,0 /*LinearMode_Offset*/
		,NULL_PTR /*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var /*SignalPhyDataStoredType*/
		,(boolean*)&Cpr_SignalPhyData_HU_HMAEnable /*SignalPhyData*/
		,NULL_PTR /*Op_WriteSignalPhyData*/
	}
    ,{
        ComConf_ComSignal_SGHU_AutoBrakeEnable_1287R	/*SignalId*/
        ,25	/*SignalMonitorCycle*/
        ,1000	/*SignalTimeoutCycle*/
        ,NULL_PTR	/*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None	/*SignalDataConversionMode*/
        ,Cpr_SigDataType_Boolean	/*SignalRawDataType*/
        ,Cpr_SigDataType_Boolean	/*SignalPhyDataType*/
        ,1.0f	/*LinearMode_Factor*/
        ,0	/*LinearMode_Offset*/
        ,NULL_PTR	/*Op_UserConvertMode*/
        ,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
        ,(boolean*)&Cpr_SignalPhyData_HU_AutoBrakeEnable	/*SignalPhyData*/
        ,NULL_PTR	/*Op_WriteSignalPhyData*/
    }
	,{
		ComConf_ComSignal_SGHU_ELKEnable_957R	/*SignalId*/
		,100	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_None	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Uint8	/*SignalPhyDataType*/
		,1.0f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_HU_ELKEnable	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
	}
	,{
		ComConf_ComSignal_SGHU_LASWarningModeSelection_1287R	/*SignalId*/
		,50	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_None	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Uint8	/*SignalPhyDataType*/
		,1.0f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_HU_LASWarningModeSelection	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
	}
	,{
		ComConf_ComSignal_SGHU_LASModeSelection_1287R	/*SignalId*/
		,50	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_None	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Uint8	/*SignalPhyDataType*/
		,1.0f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_HU_LASModeSelection	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
	}
    ,{
        ComConf_ComSignal_SGHU_FCWSetting_1287R	/*SignalId*/
        ,25	/*SignalMonitorCycle*/
        ,1000	/*SignalTimeoutCycle*/
        ,NULL_PTR	/*Op_IsUpdatedOfSignal*/
        ,Cpr_SigDataConv_None	/*SignalDataConversionMode*/
        ,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
        ,Cpr_SigDataType_Uint8	/*SignalPhyDataType*/
        ,1.0f	/*LinearMode_Factor*/
        ,0	/*LinearMode_Offset*/
        ,NULL_PTR	/*Op_UserConvertMode*/
        ,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_HU_FCWSetting	/*SignalPhyData*/
        ,NULL_PTR	/*Op_WriteSignalPhyData*/
    }
    ,{
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(boolean*)&Cpr_SignalPhyData_EpsSasSteerAgVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(boolean*)&Cpr_SignalPhyData_EPS_MeasuredTorsionBarTorqValid    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(boolean*)&Cpr_SignalPhyData_EPS_Pinionang_Valid    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_EspVehSpdVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_ESP_YawRateValid    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_ESP_LongAccelValid    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_ESP_LatAccelValid    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_IBCU_PFSBrakePressureValid    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_VcuAccrPedlPosnVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_VcuVehGearPosnVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_WhlSpdLeFrntDataVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_WhlSpdRiFrntDataVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_WhlSpdLeReDataVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_WhlSpdRiReDataVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Var    /*SignalPhyDataStoredType*/
        ,(uint8*)&Cpr_SignalPhyData_IbBrkPedlStsGbVld    /*SignalPhyData*/
        ,NULL_PTR    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmDrvrDoorSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmLeReDoorSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmPassDoorSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmRiReDoorSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspEbdFailr    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsActv    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsFailr    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspActvSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsFailr    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBdecActive    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsActvSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlActive    /*Op_WriteSignalPhyData*/
    }
	,{
		ComConf_ComSignal_SGBcmPwrStsFb_648R	/*SignalId*/
		,40	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_None	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Uint8	/*SignalPhyDataType*/
		,1.0f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(uint8*)&Cpr_SignalPhyData_BcmPwrStsFb	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_IP_QDashACCFail    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmAutHeadLiSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntWiperSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmHiBeamSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmLoBeamSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BCM_TurnLightSwitchSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrLe    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrRi    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_ExistProb    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_ExistProb    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_ExistProb    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_ExistProb    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Measured    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Measured    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Measured    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Measured    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Location    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Location    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Location    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Location    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_SrsDrvrBucSwtSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_SrsPassBucSwtSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Rte_Write_Cpr_PP_Cpr_Chassis_Data_EpsConcussAvailabilityStatus    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsIACCabortreason    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlAvailabilityStatus    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBAvailable    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAWBavailable    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspABAavailable    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EsprefillAvailable    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDir    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDir    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDir    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDir    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_ACCMode    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_AccIaccHWAMode    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmEmgyLiSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVdcActvSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntFogLmpSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Body_Data_BcmReFoglmpSts    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_AdsUDLCStatus    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSteerAgRate    /*Op_WriteSignalPhyData*/
    }
	,{
		ComConf_ComSignal_SGRLR_ElkOBJ1_Width_837R	/*SignalId*/
		,50	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_Linear	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Float32	/*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(float32*)&Cpr_SignalPhyData_ElkObj1_Width	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
	}
	,{
		ComConf_ComSignal_SGRLR_ElkOBJ2_Width_837R	/*SignalId*/
		,50	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_Linear	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Float32	/*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(float32*)&Cpr_SignalPhyData_ElkObj2_Width	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
	}
	,{
		ComConf_ComSignal_SGRLR_ElkOBJ3_Width_838R	/*SignalId*/
		,50	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_Linear	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Float32	/*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(float32*)&Cpr_SignalPhyData_ElkObj3_Width	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
	}
	,{
		ComConf_ComSignal_SGRLR_ElkOBJ4_Width_838R	/*SignalId*/
		,50	/*SignalMonitorCycle*/
		,1000	/*SignalTimeoutCycle*/
		,NULL_PTR	/*Op_IsUpdatedOfSignal*/
		,Cpr_SigDataConv_Linear	/*SignalDataConversionMode*/
		,Cpr_SigDataType_Uint8	/*SignalRawDataType*/
		,Cpr_SigDataType_Float32	/*SignalPhyDataType*/
		,0.01f	/*LinearMode_Factor*/
		,0	/*LinearMode_Offset*/
		,NULL_PTR	/*Op_UserConvertMode*/
		,Cpr_SignalPhyStoredType_Var	/*SignalPhyDataStoredType*/
		,(float32*)&Cpr_SignalPhyData_ElkObj4_Width	/*SignalPhyData*/
		,NULL_PTR	/*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspYawRate    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelAx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelAx    /*Op_WriteSignalPhyData*/    
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelAx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelAx    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVy    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_BrakePressureSimulator    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Length    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Length    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Length    /*Op_WriteSignalPhyData*/
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
        ,Cpr_SignalPhyStoredType_Func    /*SignalPhyDataStoredType*/
        ,NULL_PTR    /*SignalPhyData*/
        ,Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Length    /*Op_WriteSignalPhyData*/
    }
};