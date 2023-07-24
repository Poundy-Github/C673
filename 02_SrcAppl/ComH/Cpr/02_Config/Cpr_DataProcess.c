/**
 * \file Cpr_DataProcess.c
 *
 * \brief The data from CAN is processed
 *
 * \version refer the Cpr_DataProcess.c
 * 
 * \copyright  2023 Conti Smart Core
 *
 */

/* ==================[Includes]=============================================== */
#include"Cpr_DataProcess.h"

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/
//extern const s_Cpr_SignalStatusConfig_t Cpr_SignalStatus_ConfigTable[CPR_CHECK_SIGNALSTAUTS_NUMBER];
extern const s_Cpr_SignalStatusUpdated_t Cpr_SignalStatus_ConfigTable[CPR_CHECK_SIGNALSTAUTS_NUMBER];

/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/
//static uint8 Cpr_DataProcess_SignalStatusCheck(s_Cpr_SignalStatusConfig_t param);

/*==================[external function definitions]=========================*/
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
FUNC(void, RTE_CODE) Cpr_DataProcessFunction (void)
{
    return;
}

/**
 * \functions Cpr_UserInitFunction
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
void Cpr_UserInitFunction(void)
{
    return;
}
/**
 * \functions Cpr_UserMainFunction
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
void Cpr_UserMainFunction(void)
{

	return;
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAgVld(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAgVld(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_MeasuredTorsionBarTorqValid(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EPS_MeasuredTorsionBarTorqValid(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_Pinionang_Valid(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EPS_Pinionang_Valid(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpdVld(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspVehSpdVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_YawRateValid(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_ESP_YawRateValid(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_LongAccelValid(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_ESP_LongAccelValid(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_ESP_LatAccelValid(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_ESP_LatAccelValid(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IBCU_PFSBrakePressureValid(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_IBCU_PFSBrakePressureValid(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosnVld(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosnVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuVehGearPosnVld(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_VcuVehGearPosnVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDataVld(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDataVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDataVld(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDataVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDataVld(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDataVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDataVld(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDataVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGbVld(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGbVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmDrvrDoorSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmDrvrDoorSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmLeReDoorSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmLeReDoorSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmPassDoorSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmPassDoorSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmRiReDoorSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmRiReDoorSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspEbdFailr(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspEbdFailr(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsActv(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspAbsActv(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAbsFailr(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspAbsFailr(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspActvSts(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspActvSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsFailr(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspTcsFailr(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBdecActive(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspAEBdecActive(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspTcsActvSts(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspTcsActvSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlActive(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlActive(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_IP_QDashACCFail(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_IP_QDashACCFail(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmAutHeadLiSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmAutHeadLiSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntWiperSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmFrntWiperSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmHiBeamSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmHiBeamSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmLoBeamSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmLoBeamSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BCM_TurnLightSwitchSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BCM_TurnLightSwitchSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrLe(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrLe(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrRi(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmTurnIndcrRi(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_VcuGearPosn(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_ExistProb(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_ExistProb(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_ExistProb(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_ExistProb(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_ExistProb(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_ExistProb(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_ExistProb(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_ExistProb(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Measured(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Measured(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Measured(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Measured(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Measured(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Measured(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Measured(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Measured(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Location(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Location(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Location(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Location(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Location(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Location(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Location(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Location(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_SrsDrvrBucSwtSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_SrsDrvrBucSwtSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_SrsPassBucSwtSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_SrsPassBucSwtSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsConcussAvailabilityStatus(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsConcussAvailabilityStatus(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsIACCabortreason(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsIACCabortreason(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlAvailabilityStatus(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsLatCtrlAvailabilityStatus(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAEBAvailable(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspAEBAvailable(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspAWBavailable(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspAWBavailable(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspABAavailable(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspABAavailable(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspPrefillAvailable(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspPrefillAvailable(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDir(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntDir(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDir(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntDir(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDir(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReDir(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDir(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReDir(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_ACCMode(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_ACCMode(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_AccIaccHWAMode(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_AccIaccHWAMode(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmEmgyLiSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmEmgyLiSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlStsGb(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVdcActvSts(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspVdcActvSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmFrntFogLmpSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmFrntFogLmpSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BcmReFoglmpSts(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BcmReFoglmpSts(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_AdsUDLCStatus(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_AdsUDLCStatus(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSteerAgRate(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsSteerAgRate(*(uint16 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspVehSpd(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsSasSteerAg(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspYawRate(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspYawRate(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspLongAccel(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EspLatAccel(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelAx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelAx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelAx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelAx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelAx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelAx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelAx(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelAx(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Dy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Dy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Dy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Dy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_RelVy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_RelVy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_RelVy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVy(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_RelVy(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Width(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Width(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Width(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Width(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Width(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Width(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Width(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Width(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsMeasuredTorsionBarTorque(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_PlungerBrakePressure(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_BrakePressureSimulator(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_BrakePressureSimulator(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_VcuAccrPedlPosn(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsPinionang(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeFrntData(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdLeReData(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiFrntData(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdRiReData(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Length(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj1_Length(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Length(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj2_Length(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Length(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj3_Length(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Length(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_RadarObj4_Length(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntLePls(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntLePls(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntRiPls(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdFrntRiPls(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReLePls(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReLePls(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReRiPls(void *data)
{
	Rte_Write_PP_Cpr_Powertrain_Data_WhlSpdReRiPls(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsSasCalSts(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsSasCalSts(*(boolean *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_fault_state(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EPS_fault_state(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualTorsionBarTorq(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualTorsionBarTorq(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualMotorTorq(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EPS_ActualMotorTorq(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EpsFaild(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EpsFaild(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_EPS_APA_EpasFAILED(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_EPS_APA_EpasFAILED(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvr(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvr(*(float32 *)data);
}

void Ext_Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvrVld(void *data)
{
	Rte_Write_PP_Cpr_Chassis_Data_IbBrkPedlTrvlDrvrVld(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_IP_DISFail(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_IP_DISFail(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_FRadarCalibrationStatus(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_FRadarCalibrationStatus(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Adas_Data_FR_RadarFailureStatus(void *data)
{
	Rte_Write_PP_Cpr_Adas_Data_FR_RadarFailureStatus(*(uint8 *)data);
}

void Ext_Rte_Write_PP_Cpr_Body_Data_BCM_BrakeLampError(void *data)
{
	Rte_Write_PP_Cpr_Body_Data_BCM_BrakeLampError(*(uint8 *)data);
}

/*==================[internal function definitions]=========================*/
void Cpr_Notify_SignalStatusUpdated(uint8 state, uint16 SignalId)
{
	for (uint8 i = 0; i < CPR_CHECK_SIGNALSTAUTS_NUMBER; i++)
	{
		if(SignalId == Cpr_SignalStatus_ConfigTable[i].Vlaue_SignalId && 
			Cpr_SignalStatus_ConfigTable[i].Rte_Write_PP_Signal_State != NULL_PTR)
		{
			uint8 msg_status = CPR_Read_Msg_Staus(Cpr_SignalStatus_ConfigTable[i].RxMsgID);
			uint8 sig_status = E_SIG_STATUS_NONE;

			if (E_MSG_STATUS_VALID == msg_status)
			{
				if (Cpr_SignalFrom_DBC == Cpr_SignalStatus_ConfigTable[i].SignalFromTpye &&
					Cpr_SignalStatus_ConfigTable[i].SignalPhyData != NULL_PTR)
				{
					uint8 phy_data = *(uint8*)Cpr_SignalStatus_ConfigTable[i].SignalPhyData;
					sig_status = (phy_data == Cpr_SignalStatus_ConfigTable[i].SignalPhyData_Valid) ? E_SIG_STATUS_VALID :
						(phy_data == Cpr_SignalStatus_ConfigTable[i].SignalPhyData_Invalid) ? E_SIG_STATUS_INVALID : E_SIG_STATUS_NONE;
				}
				else
				{
					sig_status = E_SIG_STATUS_VALID;
				}
			}
			else if(state == Cpr_SigStatus_ValueToSmall || state == Cpr_SigStatus_ValueToBig)
			{
				sig_status = E_SIG_STATUS_OUTOFRANGE;
			}
			else
			{
				sig_status = E_SIG_STATUS_INVALID;
			}
			Cpr_SignalStatus_ConfigTable[i].Rte_Write_PP_Signal_State(sig_status);
		}
		else
		{
			//do nothing
		}
	}
}