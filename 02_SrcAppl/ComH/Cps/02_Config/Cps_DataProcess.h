/**
 * \file Cpr_DataProcess.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		2022.03.07			Mingfen XIAO			Init version
 * V
 *
 *
 */
#ifndef __CPR_DATA_PROCCESS_H_
#define __CPR_DATA_PROCCESS_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Rte_Cps.h"

/*==================[external function declarations]=========================*/
/***********  begin  ***********/

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBCtrlType(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBEnable(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBVehilceHoldReq(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_PrefillActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AWBlevel(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AWBActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_ABAlevel(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_ABAActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWPreWarning(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetDeceleration(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_OBJ_AEB_ID(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetType(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetDetection(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLngRange(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetmode(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTextInfo(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLatRange(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetRelSpeed(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_LLaneDistanceFus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_RLaneDistanceFus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_LLaneMarkerType(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_RLaneMarkerType(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_HostLaneLeftStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_HostLaneRightStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_HostLaneLeftStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_HostLaneRightStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWVibrationWarningReq(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LKAStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LKATakeoverReq(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LASModeSelectionStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LASWarningModeSelectionSts(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LDWShakeLevStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKMode(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKInterventionMode(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_ELKEnableStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_LatAngReqActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWLatentWarning(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LatAngReqActive(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_LatAngReq(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_ACC_LatAngReq(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_MotorTorqueMaxLimitRequest(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_MotorTorqueMinLimitRequest(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMALightDistribution(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMAEnableStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Hla_Cps_SignalPhyData_FC_HMAStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Lcf_Cps_SignalPhyData_FC_Voiceinfo(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWSettingStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_FCWStatus(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetAy(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetAx(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetProb(void *data);

void Ext_Rte_Read_RP_Cps_SRI_TxSignal_Aeb_Cps_SignalPhyData_FC_AEBTargetLatRelSpeed(void *data);

/***********  end  ***********/
#endif /* __CPR_DATA_PROCCESS_H_ */