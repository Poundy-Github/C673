/**
 * \file Cps_Lcfg.h
 *
 * \brief This file contains related data types of Cps.
 *
 * \version refer the Cps_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "Cps_Lcfg.h"
#include "Com.h"
#include"Cps_DataProcess.h"

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/
uint8 Cps_SignalPhyData_FC_LKAStatus_Current;
uint8 Cps_SignalPhyData_FC_AEBTargetStatus;//define for temp solution
uint8 Cps_SignalPhyData_FC_LDWStatus_Current;//define for temp solution

/***********   begin  ***********/
boolean Cps_SignalPhyData_FC_AEBActive;
boolean Cps_SubsititutionValue_FC_AEBActive = 0;
const boolean Cps_Min_FC_AEBActive = 0.0000000000;
const boolean Cps_Max_FC_AEBActive = 1.0000000000;

uint8 Cps_SignalPhyData_FC_AEBCtrlType;
uint8 Cps_SubsititutionValue_FC_AEBCtrlType = 0;
const uint8 Cps_Min_FC_AEBCtrlType = 0.0000000000;
const uint8 Cps_Max_FC_AEBCtrlType = 15.0000000000;

boolean Cps_SignalPhyData_FC_AEBEnable;
boolean Cps_SubsititutionValue_FC_AEBEnable = 0;
const boolean Cps_Min_FC_AEBEnable = 0.0000000000;
const boolean Cps_Max_FC_AEBEnable = 1.0000000000;

boolean Cps_SignalPhyData_FC_AEBVehilceHoldReq;
boolean Cps_SubsititutionValue_FC_AEBVehilceHoldReq = 0;
const boolean Cps_Min_FC_AEBVehilceHoldReq = 0.0000000000;
const boolean Cps_Max_FC_AEBVehilceHoldReq = 1.0000000000;

boolean Cps_SignalPhyData_FC_PrefillActive;
boolean Cps_SubsititutionValue_FC_PrefillActive = 0;
const boolean Cps_Min_FC_PrefillActive = 0.0000000000;
const boolean Cps_Max_FC_PrefillActive = 1.0000000000;

uint8 Cps_SignalPhyData_FC_AWBlevel;
uint8 Cps_SubsititutionValue_FC_AWBlevel = 0;
const uint8 Cps_Min_FC_AWBlevel = 0.0000000000;
const uint8 Cps_Max_FC_AWBlevel = 15.0000000000;

boolean Cps_SignalPhyData_FC_AWBActive;
boolean Cps_SubsititutionValue_FC_AWBActive = 0;
const boolean Cps_Min_FC_AWBActive = 0.0000000000;
const boolean Cps_Max_FC_AWBActive = 1.0000000000;

boolean Cps_SignalPhyData_FC_FCWActive;
boolean Cps_SubsititutionValue_FC_FCWActive = 0;
const boolean Cps_Min_FC_FCWActive = 0.0000000000;
const boolean Cps_Max_FC_FCWActive = 1.0000000000;

uint8 Cps_SignalPhyData_FC_ABAlevel;
uint8 Cps_SubsititutionValue_FC_ABAlevel = 0;
const uint8 Cps_Min_FC_ABAlevel = 0.0000000000;
const uint8 Cps_Max_FC_ABAlevel = 3.0000000000;

boolean Cps_SignalPhyData_FC_ABAActive;
boolean Cps_SubsititutionValue_FC_ABAActive = 0;
const boolean Cps_Min_FC_ABAActive = 0.0000000000;
const boolean Cps_Max_FC_ABAActive = 1.0000000000;

boolean Cps_SignalPhyData_FC_FCWPreWarning;
boolean Cps_SubsititutionValue_FC_FCWPreWarning = 0;
const boolean Cps_Min_FC_FCWPreWarning = 0.0000000000;
const boolean Cps_Max_FC_FCWPreWarning = 1.0000000000;

float32 Cps_SignalPhyData_FC_AEBTargetDeceleration;
float32 Cps_SubsititutionValue_FC_AEBTargetDeceleration = 0;
const float32 Cps_Min_FC_AEBTargetDeceleration = -16.0000000000;
const float32 Cps_Max_FC_AEBTargetDeceleration = 16.0000000000;

uint8 Cps_SignalPhyData_FC_OBJ_AEB_ID;
uint8 Cps_SubsititutionValue_FC_OBJ_AEB_ID = 0;
const uint8 Cps_Min_FC_OBJ_AEB_ID = 0.0000000000;
const uint8 Cps_Max_FC_OBJ_AEB_ID = 255.0000000000;

uint8 Cps_SignalPhyData_FC_AEBTargetType;
uint8 Cps_SubsititutionValue_FC_AEBTargetType = 0;
const uint8 Cps_Min_FC_AEBTargetType = 0.0000000000;
const uint8 Cps_Max_FC_AEBTargetType = 15.0000000000;

boolean Cps_SignalPhyData_FC_AEBTargetDetection;
boolean Cps_SubsititutionValue_FC_AEBTargetDetection = 0;
const boolean Cps_Min_FC_AEBTargetDetection = 0.0000000000;
const boolean Cps_Max_FC_AEBTargetDetection = 1.0000000000;

float32 Cps_SignalPhyData_FC_AEBTargetLngRange;
float32 Cps_SubsititutionValue_FC_AEBTargetLngRange = 0;
const float32 Cps_Min_FC_AEBTargetLngRange = -70.0000000000;
const float32 Cps_Max_FC_AEBTargetLngRange = 180.0000000000;

uint8 Cps_SignalPhyData_FC_AEBTargetmode;
uint8 Cps_SubsititutionValue_FC_AEBTargetmode = 0;
const uint8 Cps_Min_FC_AEBTargetmode = 0.0000000000;
const uint8 Cps_Max_FC_AEBTargetmode = 3.0000000000;

uint8 Cps_SignalPhyData_FC_AEBTextInfo;
uint8 Cps_SubsititutionValue_FC_AEBTextInfo = 0;
const uint8 Cps_Min_FC_AEBTextInfo = 0.0000000000;
const uint8 Cps_Max_FC_AEBTextInfo = 15.0000000000;

float32 Cps_SignalPhyData_FC_AEBTargetLatRange;
float32 Cps_SubsititutionValue_FC_AEBTargetLatRange = 0;
const float32 Cps_Min_FC_AEBTargetLatRange = -50.0000000000;
const float32 Cps_Max_FC_AEBTargetLatRange = 50.0000000000;

sint16 Cps_SignalPhyData_FC_AEBTargetRelSpeed;
sint16 Cps_SubsititutionValue_FC_AEBTargetRelSpeed = 0;
const sint16 Cps_Min_FC_AEBTargetRelSpeed = -250.0000000000;
const sint16 Cps_Max_FC_AEBTargetRelSpeed = 250.0000000000;

float32 Cps_SignalPhyData_FC_LLaneDistanceFus;
float32 Cps_SubsititutionValue_FC_LLaneDistanceFus = 0;
const float32 Cps_Min_FC_LLaneDistanceFus = -1.0000000000;
const float32 Cps_Max_FC_LLaneDistanceFus = 5.0000000000;

float32 Cps_SignalPhyData_FC_RLaneDistanceFus;
float32 Cps_SubsititutionValue_FC_RLaneDistanceFus = 0;
const float32 Cps_Min_FC_RLaneDistanceFus = -5.0000000000;
const float32 Cps_Max_FC_RLaneDistanceFus = 1.0000000000;

uint8 Cps_SignalPhyData_FC_LLaneMarkerType;
uint8 Cps_SubsititutionValue_FC_LLaneMarkerType = 0;
const uint8 Cps_Min_FC_LLaneMarkerType = 0.0000000000;
const uint8 Cps_Max_FC_LLaneMarkerType = 7.0000000000;

uint8 Cps_SignalPhyData_FC_RLaneMarkerType;
uint8 Cps_SubsititutionValue_FC_RLaneMarkerType = 0;
const uint8 Cps_Min_FC_RLaneMarkerType = 0.0000000000;
const uint8 Cps_Max_FC_RLaneMarkerType = 7.0000000000;

uint8 Cps_SignalPhyData_ACC_HostLaneLeftStatus;
uint8 Cps_SubsititutionValue_ACC_HostLaneLeftStatus = 0;
const uint8 Cps_Min_ACC_HostLaneLeftStatus = 0;
const uint8 Cps_Max_ACC_HostLaneLeftStatus = 15;

uint8 Cps_SignalPhyData_ACC_HostLaneRightStatus;
uint8 Cps_SubsititutionValue_ACC_HostLaneRightStatus = 0;
const uint8 Cps_Min_ACC_HostLaneRightStatus = 0;
const uint8 Cps_Max_ACC_HostLaneRightStatus = 15;

uint8 Cps_SignalPhyData_FC_HostLaneLeftStatus;
uint8 Cps_SubsititutionValue_FC_HostLaneLeftStatus = 0;
const uint8 Cps_Min_FC_HostLaneLeftStatus = 0.0000000000;
const uint8 Cps_Max_FC_HostLaneLeftStatus = 15.0000000000;

uint8 Cps_SignalPhyData_FC_HostLaneRightStatus;
uint8 Cps_SubsititutionValue_FC_HostLaneRightStatus = 0;
const uint8 Cps_Min_FC_HostLaneRightStatus = 0.0000000000;
const uint8 Cps_Max_FC_HostLaneRightStatus = 15.0000000000;

uint8 Cps_SignalPhyData_FC_LDWStatus;
uint8 Cps_SubsititutionValue_FC_LDWStatus = 0;
const uint8 Cps_Min_FC_LDWStatus = 0.0000000000;
const uint8 Cps_Max_FC_LDWStatus = 3.0000000000;

uint8 Cps_SignalPhyData_FC_LDWVibrationWarningReq;
uint8 Cps_SubsititutionValue_FC_LDWVibrationWarningReq = 0;
const uint8 Cps_Min_FC_LDWVibrationWarningReq = 0.0000000000;
const uint8 Cps_Max_FC_LDWVibrationWarningReq = 3.0000000000;

uint8 Cps_SignalPhyData_FC_LKAStatus;
uint8 Cps_SubsititutionValue_FC_LKAStatus = 0;
const uint8 Cps_Min_FC_LKAStatus = 0.0000000000;
const uint8 Cps_Max_FC_LKAStatus = 3.0000000000;

boolean Cps_SignalPhyData_FC_LKATakeoverReq;
boolean Cps_SubsititutionValue_FC_LKATakeoverReq = 0;
const boolean Cps_Min_FC_LKATakeoverReq = 0.0000000000;
const boolean Cps_Max_FC_LKATakeoverReq = 1.0000000000;

uint8 Cps_SignalPhyData_FC_LASModeSelectionStatus;
uint8 Cps_SubsititutionValue_FC_LASModeSelectionStatus = 0;
const uint8 Cps_Min_FC_LASModeSelectionStatus = 0.0000000000;
const uint8 Cps_Max_FC_LASModeSelectionStatus = 7.0000000000;

uint8 Cps_SignalPhyData_FC_LASWarningModeSelectionSts;
uint8 Cps_SubsititutionValue_FC_LASWarningModeSelectionSts = 0;
const uint8 Cps_Min_FC_LASWarningModeSelectionSts = 0.0000000000;
const uint8 Cps_Max_FC_LASWarningModeSelectionSts = 7.0000000000;

uint8 Cps_SignalPhyData_FC_LDWShakeLevStatus;
uint8 Cps_SubsititutionValue_FC_LDWShakeLevStatus = 0;
const uint8 Cps_Min_FC_LDWShakeLevStatus = 0.0000000000;
const uint8 Cps_Max_FC_LDWShakeLevStatus = 3.0000000000;

uint8 Cps_SignalPhyData_FC_ELKMode;
uint8 Cps_SubsititutionValue_FC_ELKMode = 0;
const uint8 Cps_Min_FC_ELKMode = 0.0000000000;
const uint8 Cps_Max_FC_ELKMode = 7.0000000000;

uint8 Cps_SignalPhyData_FC_ELKInterventionMode;
uint8 Cps_SubsititutionValue_FC_ELKInterventionMode = 0;
const uint8 Cps_Min_FC_ELKInterventionMode = 0.0000000000;
const uint8 Cps_Max_FC_ELKInterventionMode = 3.0000000000;

boolean Cps_SignalPhyData_FC_ELKEnableStatus;
boolean Cps_SubsititutionValue_FC_ELKEnableStatus = 0;
const boolean Cps_Min_FC_ELKEnableStatus = 0.0000000000;
const boolean Cps_Max_FC_ELKEnableStatus = 1.0000000000;

uint8 Cps_SignalPhyData_FC_AEBStatus;
uint8 Cps_SubsititutionValue_FC_AEBStatus = 0;
const uint8 Cps_Min_FC_AEBStatus = 0.0000000000;
const uint8 Cps_Max_FC_AEBStatus = 3.0000000000;

boolean Cps_SignalPhyData_ACC_LatAngReqActive;
boolean Cps_SubsititutionValue_ACC_LatAngReqActive = 0;
const boolean Cps_Min_ACC_LatAngReqActive = 0;
const boolean Cps_Max_ACC_LatAngReqActive = 1;

boolean Cps_SignalPhyData_FC_FCWLatentWarning;
boolean Cps_SubsititutionValue_FC_FCWLatentWarning = 0;
const boolean Cps_Min_FC_FCWLatentWarning = 0.0000000000;
const boolean Cps_Max_FC_FCWLatentWarning = 1.0000000000;

boolean Cps_SignalPhyData_FC_LatAngReqActive;
boolean Cps_SubsititutionValue_FC_LatAngReqActive = 0;
const boolean Cps_Min_FC_LatAngReqActive = 0.0000000000;
const boolean Cps_Max_FC_LatAngReqActive = 1.0000000000;

float32 Cps_SignalPhyData_FC_LatAngReq;
float32 Cps_SubsititutionValue_FC_LatAngReq = 0;
const float32 Cps_Min_FC_LatAngReq = -720.0000000000;
const float32 Cps_Max_FC_LatAngReq = 720.0000000000;

float32 Cps_SignalPhyData_ACC_LatAngReq;
float32 Cps_SubsititutionValue_ACC_LatAngReq = 0;
const float32 Cps_Min_ACC_LatAngReq = -720;
const float32 Cps_Max_ACC_LatAngReq = 720;

float32 Cps_SignalPhyData_FC_MotorTorqueMaxLimitRequest;
float32 Cps_SubsititutionValue_FC_MotorTorqueMaxLimitRequest = 0;
const float32 Cps_Min_FC_MotorTorqueMaxLimitRequest = -20.4800000000;
const float32 Cps_Max_FC_MotorTorqueMaxLimitRequest = 20.4600000000;

float32 Cps_SignalPhyData_FC_MotorTorqueMinLimitRequest;
float32 Cps_SubsititutionValue_FC_MotorTorqueMinLimitRequest = 0;
const float32 Cps_Min_FC_MotorTorqueMinLimitRequest = -20.4800000000;
const float32 Cps_Max_FC_MotorTorqueMinLimitRequest = 20.4600000000;

boolean Cps_SignalPhyData_FC_HMALightDistribution;
boolean Cps_SubsititutionValue_FC_HMALightDistribution = 0;
const boolean Cps_Min_FC_HMALightDistribution = 0.0000000000;
const boolean Cps_Max_FC_HMALightDistribution = 1.0000000000;

boolean Cps_SignalPhyData_FC_HMAEnableStatus;
boolean Cps_SubsititutionValue_FC_HMAEnableStatus = 0;
const boolean Cps_Min_FC_HMAEnableStatus = 0.0000000000;
const boolean Cps_Max_FC_HMAEnableStatus = 1.0000000000;

uint8 Cps_SignalPhyData_FC_HMAStatus;
uint8 Cps_SubsititutionValue_FC_HMAStatus = 0;
const uint8 Cps_Min_FC_HMAStatus = 0.0000000000;
const uint8 Cps_Max_FC_HMAStatus = 3.0000000000;

uint8 Cps_SignalPhyData_FC_Voiceinfo;
uint8 Cps_SubsititutionValue_FC_Voiceinfo = 0;
const uint8 Cps_Min_FC_Voiceinfo = 0.0000000000;
const uint8 Cps_Max_FC_Voiceinfo = 31.0000000000;

uint8 Cps_SignalPhyData_FC_FCWSettingStatus;
uint8 Cps_SubsititutionValue_FC_FCWSettingStatus = 0;
const uint8 Cps_Min_FC_FCWSettingStatus = 0.0000000000;
const uint8 Cps_Max_FC_FCWSettingStatus = 7.0000000000;

uint8 Cps_SignalPhyData_FC_FCWStatus;
uint8 Cps_SubsititutionValue_FC_FCWStatus = 0;
const uint8 Cps_Min_FC_FCWStatus = 0.0000000000;
const uint8 Cps_Max_FC_FCWStatus = 3.0000000000;

float32 Cps_SignalPhyData_FC_AEBTargetAy;
float32 Cps_SubsititutionValue_FC_AEBTargetAy = 0;
const float32 Cps_Min_FC_AEBTargetAy = -12.0000000000;
const float32 Cps_Max_FC_AEBTargetAy = 12.0000000000;

float32 Cps_SignalPhyData_FC_AEBTargetAx;
float32 Cps_SubsititutionValue_FC_AEBTargetAx = 0;
const float32 Cps_Min_FC_AEBTargetAx = -16.0000000000;
const float32 Cps_Max_FC_AEBTargetAx = 16.0000000000;

uint8 Cps_SignalPhyData_FC_AEBTargetProb;
uint8 Cps_SubsititutionValue_FC_AEBTargetProb = 0;
const uint8 Cps_Min_FC_AEBTargetProb = 0.0000000000;
const uint8 Cps_Max_FC_AEBTargetProb = 100.0000000000;

float32 Cps_SignalPhyData_FC_AEBTargetLatRelSpeed;
float32 Cps_SubsititutionValue_FC_AEBTargetLatRelSpeed = 0;
const float32 Cps_Min_FC_AEBTargetLatRelSpeed = -64.0000000000;
const float32 Cps_Max_FC_AEBTargetLatRelSpeed = 63.8750000000;

const s_Cps_SendSignalConfig_t Cps_SendSignalConfigTable[CPS_SEND_SIGNAL_NUMBER] = {
{
ComConf_ComSignal_SGFC_AEBActive_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_AEBActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_AEBActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_AEBActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_AEBActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBCtrlType_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AEBCtrlType     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AEBCtrlType     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AEBCtrlType     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AEBCtrlType     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBCtrlType    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBEnable_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_AEBEnable     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_AEBEnable     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_AEBEnable     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_AEBEnable     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBEnable    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBVehilceHoldReq_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_AEBVehilceHoldReq     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_AEBVehilceHoldReq     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_AEBVehilceHoldReq     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_AEBVehilceHoldReq     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBVehilceHoldReq    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_PrefillActive_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_PrefillActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_PrefillActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_PrefillActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_PrefillActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_PrefillActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AWBlevel_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AWBlevel     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AWBlevel     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AWBlevel     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AWBlevel     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AWBlevel    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AWBActive_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_AWBActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_AWBActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_AWBActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_AWBActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AWBActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_FCWActive_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_FCWActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_FCWActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_FCWActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_FCWActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_ABAlevel_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_ABAlevel     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_ABAlevel     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_ABAlevel     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_ABAlevel     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_ABAlevel    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_ABAActive_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_ABAActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_ABAActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_ABAActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_ABAActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_ABAActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_FCWPreWarning_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_FCWPreWarning     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_FCWPreWarning     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_FCWPreWarning     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_FCWPreWarning     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWPreWarning    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetDeceleration_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.0005000000  /*Factor*/
,-16.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_AEBTargetDeceleration     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_AEBTargetDeceleration     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_AEBTargetDeceleration     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_AEBTargetDeceleration     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetDeceleration    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_OBJ_AEB_ID_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_OBJ_AEB_ID     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_OBJ_AEB_ID     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_OBJ_AEB_ID     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_OBJ_AEB_ID     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_OBJ_AEB_ID    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetType_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AEBTargetType     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AEBTargetType     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AEBTargetType     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AEBTargetType     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetType    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetDetection_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_AEBTargetDetection     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_AEBTargetDetection     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_AEBTargetDetection     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_AEBTargetDetection     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetDetection    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetLngRange_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.5000000000  /*Factor*/
,-70.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_AEBTargetLngRange     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_AEBTargetLngRange     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_AEBTargetLngRange     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_AEBTargetLngRange     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLngRange    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetmode_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AEBTargetmode     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AEBTargetmode     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AEBTargetmode     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AEBTargetmode     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetmode    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTextInfo_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AEBTextInfo     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AEBTextInfo     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AEBTextInfo     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AEBTextInfo     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTextInfo    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetLatRange_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.1000000000  /*Factor*/
,-50.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_AEBTargetLatRange     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_AEBTargetLatRange     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_AEBTargetLatRange     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_AEBTargetLatRange     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLatRange    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetRelSpeed_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Sint16  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,-250.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(sint16*)&Cps_Min_FC_AEBTargetRelSpeed     /*SignalPhyData_Lower*/
,(sint16*)&Cps_Max_FC_AEBTargetRelSpeed     /*SignalPhyData_Upper*/
,(sint16*)&Cps_SubsititutionValue_FC_AEBTargetRelSpeed     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(sint16*)&Cps_SignalPhyData_FC_AEBTargetRelSpeed     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetRelSpeed    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LLaneDistanceFus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.0500000000  /*Factor*/
,-1.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_LLaneDistanceFus     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_LLaneDistanceFus     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_LLaneDistanceFus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_LLaneDistanceFus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_LLaneDistanceFus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_RLaneDistanceFus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.0500000000  /*Factor*/
,-5.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_RLaneDistanceFus     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_RLaneDistanceFus     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_RLaneDistanceFus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_RLaneDistanceFus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_RLaneDistanceFus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LLaneMarkerType_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LLaneMarkerType     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LLaneMarkerType     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LLaneMarkerType     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LLaneMarkerType     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_LLaneMarkerType    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_RLaneMarkerType_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_RLaneMarkerType     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_RLaneMarkerType     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_RLaneMarkerType     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_RLaneMarkerType     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_RLaneMarkerType    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGACC_HostLaneLeftStatus_794T /*SignalId*/
,100 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1  /*Factor*/
,0  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_ACC_HostLaneLeftStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_ACC_HostLaneLeftStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_ACC_HostLaneLeftStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_ACC_HostLaneLeftStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_HostLaneLeftStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGACC_HostLaneRightStatus_794T /*SignalId*/
,100 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1  /*Factor*/
,0  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_ACC_HostLaneRightStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_ACC_HostLaneRightStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_ACC_HostLaneRightStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_ACC_HostLaneRightStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_HostLaneRightStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_HostLaneLeftStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_HostLaneLeftStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_HostLaneLeftStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_HostLaneLeftStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_HostLaneLeftStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_HostLaneLeftStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_HostLaneRightStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_HostLaneRightStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_HostLaneRightStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_HostLaneRightStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_HostLaneRightStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_HostLaneRightStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LDWStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LDWStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LDWStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LDWStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LDWStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LDWVibrationWarningReq_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LDWVibrationWarningReq     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LDWVibrationWarningReq     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LDWVibrationWarningReq     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LDWVibrationWarningReq     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWVibrationWarningReq    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LKAStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LKAStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LKAStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LKAStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LKAStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LKAStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LKATakeoverReq_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_LKATakeoverReq     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_LKATakeoverReq     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_LKATakeoverReq     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_LKATakeoverReq     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LKATakeoverReq    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LASModeSelectionStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LASModeSelectionStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LASModeSelectionStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LASModeSelectionStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LASModeSelectionStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LASModeSelectionStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LASWarningModeSelectionSts_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LASWarningModeSelectionSts     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LASWarningModeSelectionSts     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LASWarningModeSelectionSts     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LASWarningModeSelectionSts     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LASWarningModeSelectionSts    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LDWShakeLevStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_LDWShakeLevStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_LDWShakeLevStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_LDWShakeLevStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_LDWShakeLevStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWShakeLevStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_ELKMode_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_ELKMode     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_ELKMode     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_ELKMode     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_ELKMode     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKMode    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_ELKInterventionMode_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_ELKInterventionMode     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_ELKInterventionMode     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_ELKInterventionMode     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_ELKInterventionMode     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKInterventionMode    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_ELKEnableStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_ELKEnableStatus     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_ELKEnableStatus     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_ELKEnableStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_ELKEnableStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKEnableStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AEBStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AEBStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AEBStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AEBStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGACC_LatAngReqActive_442T /*SignalId*/
,10 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1  /*Factor*/
,0  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_ACC_LatAngReqActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_ACC_LatAngReqActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_ACC_LatAngReqActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_ACC_LatAngReqActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_LatAngReqActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_FCWLatentWarning_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_FCWLatentWarning     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_FCWLatentWarning     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_FCWLatentWarning     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_FCWLatentWarning     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWLatentWarning    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LatAngReqActive_263T /*SignalId*/
,10 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_LatAngReqActive     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_LatAngReqActive     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_LatAngReqActive     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_LatAngReqActive     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LatAngReqActive    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_LatAngReq_263T /*SignalId*/
,10 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.1000000000  /*Factor*/
,-720.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_LatAngReq     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_LatAngReq     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_LatAngReq     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_LatAngReq     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LatAngReq    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGACC_LatAngReq_442T /*SignalId*/
,10 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.1  /*Factor*/
,-720  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_ACC_LatAngReq     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_ACC_LatAngReq     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_ACC_LatAngReq     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_ACC_LatAngReq     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_LatAngReq    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_MotorTorqueMaxLimitRequest_263T /*SignalId*/
,10 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.0200000000  /*Factor*/
,-20.4800000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_MotorTorqueMaxLimitRequest     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_MotorTorqueMaxLimitRequest     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_MotorTorqueMaxLimitRequest     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_MotorTorqueMaxLimitRequest     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_MotorTorqueMaxLimitRequest    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_MotorTorqueMinLimitRequest_263T /*SignalId*/
,10 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.0200000000  /*Factor*/
,-20.4800000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_MotorTorqueMinLimitRequest     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_MotorTorqueMinLimitRequest     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_MotorTorqueMinLimitRequest     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_MotorTorqueMinLimitRequest     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_MotorTorqueMinLimitRequest    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_HMALightDistribution_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_HMALightDistribution     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_HMALightDistribution     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_HMALightDistribution     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_HMALightDistribution     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMALightDistribution    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_HMAEnableStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Boolean /*SignalRawDataType*/
,Cps_SigDataType_Boolean  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(boolean*)&Cps_Min_FC_HMAEnableStatus     /*SignalPhyData_Lower*/
,(boolean*)&Cps_Max_FC_HMAEnableStatus     /*SignalPhyData_Upper*/
,(boolean*)&Cps_SubsititutionValue_FC_HMAEnableStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(boolean*)&Cps_SignalPhyData_FC_HMAEnableStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMAEnableStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_HMAStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_HMAStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_HMAStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_HMAStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_HMAStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMAStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_Voiceinfo_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_Voiceinfo     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_Voiceinfo     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_Voiceinfo     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_Voiceinfo     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_Voiceinfo    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_FCWSettingStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_FCWSettingStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_FCWSettingStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_FCWSettingStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_FCWSettingStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWSettingStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_FCWStatus_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_FCWStatus     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_FCWStatus     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_FCWStatus     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_FCWStatus     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWStatus    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetAy_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.1000000000  /*Factor*/
,-12.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_AEBTargetAy     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_AEBTargetAy     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_AEBTargetAy     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_AEBTargetAy     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetAy    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetAx_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.1000000000  /*Factor*/
,-16.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_AEBTargetAx     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_AEBTargetAx     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_AEBTargetAx     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_AEBTargetAx     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetAx    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetProb_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_None /*SignalDataConversionMode*/
,Cps_SigDataType_Uint8 /*SignalRawDataType*/
,Cps_SigDataType_Uint8  /*SignalPhyDataType*/
,1.0000000000  /*Factor*/
,0.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(uint8*)&Cps_Min_FC_AEBTargetProb     /*SignalPhyData_Lower*/
,(uint8*)&Cps_Max_FC_AEBTargetProb     /*SignalPhyData_Upper*/
,(uint8*)&Cps_SubsititutionValue_FC_AEBTargetProb     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(uint8*)&Cps_SignalPhyData_FC_AEBTargetProb     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetProb    /*Op_ReadSignalPhyData*/
}
,{
ComConf_ComSignal_SGFC_AEBTargetLatRelSpeed_264T /*SignalId*/
,20 /*SignalSendCycle*/
,Cps_SigDataConv_DeLinear /*SignalDataConversionMode*/
,Cps_SigDataType_Uint16 /*SignalRawDataType*/
,Cps_SigDataType_Float32  /*SignalPhyDataType*/
,0.1250000000  /*Factor*/
,-64.0000000000  /*Offset*/
,NULL_PTR  /*Op_UserConvertMode*/
,Cps_SigDataValRangeCheck_Range	/*SignalValueRangeCheckMode*/
,(float32*)&Cps_Min_FC_AEBTargetLatRelSpeed     /*SignalPhyData_Lower*/
,(float32*)&Cps_Max_FC_AEBTargetLatRelSpeed     /*SignalPhyData_Upper*/
,(float32*)&Cps_SubsititutionValue_FC_AEBTargetLatRelSpeed     /*SignalErrSubsititutionValue*/
,NULL_PTR  /*Op_UserValueRangeCheck*/
,Cps_SignalPhyGetType_Func  /*SignalPhyDataGetType*/
,(float32*)&Cps_SignalPhyData_FC_AEBTargetLatRelSpeed     /*SignalPhyData*/
,Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLatRelSpeed    /*Op_ReadSignalPhyData*/
}
};
/***********  end  ***********/




/*==================[internal function declarations]========================*/
/**
 * \functions Cpr_DataProcessFunction
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
FUNC(void, RTE_CODE) Cps_DataProcessFunction (void)
{
    //memset(&s_Cps_Data_FC_1BA, 0, sizeof(ComSend_FC_1BA_t));
    //Rte_Read_Cps_PR_ComSend_Data_FC_1BA_ComSend_Data_FC1BA(&s_Cps_Data_FC_1BA);
    
}





