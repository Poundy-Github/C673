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
#include "Rte_Cpr.h"
#include "Cpr_Stubs.h"
#include "Cpr_Cfg.h"
#include "Cpr_Core.h"

/*==================[macros definitions]====================================*/
/*
 * \brief 	TEMPLATE_MODULE_ID,
 * */


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_Cpr_SignalStatusType_t,
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef enum
{
	Cpr_SignalFrom_DBC 	= 0x00,
	Cpr_SignalFrom_USER	= 0x01,
}e_Cpr_SignalStatusType_t;

/*
 * \brief 	s_Cpr_SignalStatusUpdated_t,
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef struct 
{
    uint16 Vlaue_SignalId;      /*Vlaue_SignalId*/
    uint8  RxMsgID;     /*RxMsgID*/
    e_Cpr_SignalStatusType_t SignalFromTpye;        /*SignalPhyDataStoredType*/
    void*   SignalPhyData;  /*SignalPhyData*/
    uint8   SignalPhyData_Valid;/*SignalPhyData_Valid*/
    uint8   SignalPhyData_Invalid;/*SignalPhyData_Invalid*/
	void    (*Rte_Write_PP_Signal_State)(uint8 data);/*Rte_Write_PP_Signal_State*/
}s_Cpr_SignalStatusUpdated_t;

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/

extern void Cpr_Notify_SignalStatusUpdated(uint8 state, uint16 SignalId);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAgVld(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_MeasuredTorsionBarTorqValid(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_Pinionang_Valid(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpdVld(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_YawRateValid(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_LongAccelValid(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_LatAccelValid(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IBCU_PFSBrakePressureValid(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosnVld(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuVehGearPosnVld(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvr(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvrVld(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDataVld(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDataVld(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDataVld(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDataVld(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGbVld(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmDrvrDoorSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmLeReDoorSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmPassDoorSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmRiReDoorSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspEbdFailr(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsActv(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsFailr(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspActvSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsFailr(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBdecActive(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsActvSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlActive(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_IP_QDashACCFail(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmAutHeadLiSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntWiperSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmHiBeamSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmLoBeamSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BCM_TurnLightSwitchSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrLe(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrRi(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_ExistProb(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_ExistProb(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_ExistProb(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_ExistProb(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Measured(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Measured(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Measured(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Measured(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Location(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Location(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Location(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Location(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_SrsDrvrBucSwtSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_SrsPassBucSwtSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsConcussAvailabilityStatus(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsIACCabortreason(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlAvailabilityStatus(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBAvailable(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAWBavailable(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspABAavailable(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspPrefillAvailable(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDir(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDir(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDir(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDir(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_ACCMode(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_AccIaccHWAMode(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmEmgyLiSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVdcActvSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntFogLmpSts(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmReFoglmpSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_AdsUDLCStatus(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSteerAgRate(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspYawRate(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelAx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelAx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelAx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelAx(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVy(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Width(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Width(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Width(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Width(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_BrakePressureSimulator(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Length(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Length(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Length(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Length(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntLePls(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntRiPls(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReLePls(void *data);

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReRiPls(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasCalSts(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_fault_state(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualTorsionBarTorq(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualMotorTorq(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsFaild(void *data);

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_APA_EpasFAILED(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_IP_DISFail(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_FRadarCalibrationStatus(void *data);

void Ext_Rte_Write_PP_Cpr_Adas_Data_FR_RadarFailureStatus(void *data);

void Ext_Rte_Write_PP_Cpr_Body_Data_BCM_BrakeLampError(void *data);



#endif /* __CPR_DATA_PROCCESS_H_ */