/* ==================[Includes]=============================================== */
#include "Sdc_Chassis.h"
#include "Sdc_Chassis_Type.h"
#include "Sdc_Core.h"
#include "Rte_Sdc.h"

/*==================[external data]=========================================*/
/*TODO : following data from Cpr*/
extern float32 Cpr_SignalPhyData_EspVehSpd;
extern float32 Cpr_SignalPhyData_EpsSasSteerAg;
extern float32 Cpr_SignalPhyData_EspYawRate;
extern float32 Cpr_SignalPhyData_EspLongAccel;

extern uint8 Cpr_SignalPhyData_EspVehSpdVld;
extern uint8 Cpr_SignalPhyData_ESP_YawRateValid;
extern uint8 Cpr_SignalPhyData_ESP_LongAccelValid;
extern uint8 Cpr_SignalPhyData_BcmFrntWiperSts;
extern uint8 Cpr_SignalPhyData_BcmHiBeamSts;
extern uint8 Cpr_SignalPhyData_BcmTurnLightSwitchStst;
extern uint8 Cpr_SignalPhyData_VcuGearPosn;
extern boolean Cpr_SignalPhyData_EpsSasSteerAgVld;

/*==================[internal data]=========================================*/

/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

s_Sdc_ChassisData_t Sdc_ChassisData;

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

/**
 * \functions Sdc_Chassis_InitFunction
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
FUNC(void, RTE_CODE) Sdc_Chassis_InitFunction(void)
{
    memset(&Sdc_ChassisData, 0, sizeof(s_Sdc_ChassisData_t));
}

/**
 * \functions Sdc_Chassis_DeInitFunction
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
FUNC(void, RTE_CODE) Sdc_Chassis_DeInitFunction(void)
{
    //TODO
}
/**
 * \functions Sdc_Chassis_MainFunction
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
FUNC(void, RTE_CODE) Sdc_Chassis_MainFunction(void)
{
    uint64 time_stamp = 0;
	uint8 sig_status = 0;
	uint8 u8_signal = 0;
	uint8 u8_signalValid = 0;
	float32 f32_signal = 0;

	/*TODO : get time stamp*/
	Time_GetTimeStampMs(&time_stamp);
	/*
	 * notes : the convert include unit convert and can_internal.json factor and offset
	 *
	 * 			The can_internal.json from J3
	 * */
	/*TODO : fill the veh spd data,from 0x17A*/
	Sdc_ChassisData.VehSpd_Header.data.CanId = 0x100;
	Sdc_ChassisData.VehSpd_Header.data.dlc = 0x08;

	Rte_Read_RP_Sdc_Chassis_Data_EspVehSpd_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_Sdc_RP_Sdc_Chassis_Data_EspVehSpd(&f32_signal);
	}
	else
	{
		f32_signal = 0;
	}
	Sdc_ChassisData.VehSpd.data.VehicleSpeed = (f32_signal * 100);
	//Sdc_ChassisData.VehSpd.data.VehicleSpeed = (EspVehSpd * 100);

	Rte_Read_RP_Sdc_Chassis_Data_EspVehSpdVld(&u8_signalValid);
	Sdc_ChassisData.VehSpd.data.VehicleSpeedValid = u8_signalValid==0x00?1:0;
	//Sdc_ChassisData.VehSpd.data.VehicleSpeedValid = EspVehSpdVld==0x00?1:0;

	/*TODO : fill the YawRate data,from 0x278*/
	Sdc_ChassisData.YawRate_Header.data.CanId = 0x101;
	Sdc_ChassisData.YawRate_Header.data.dlc = 0x08;

	Rte_Read_RP_Sdc_Chassis_Data_EspYawRate_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_RP_Sdc_Chassis_Data_EspYawRate(&f32_signal);
	}
	else
	{
		f32_signal = 0;
	}
	Sdc_ChassisData.YawRate.data.YawRate = ((((-1.0 * f32_signal * 3.141592653589793f) / 180.0)  + 2.048) * 1000);/*has been unit convert*/
	
	Rte_Read_RP_Sdc_Chassis_Data_ESP_YawRateValid(&u8_signalValid);
	Sdc_ChassisData.YawRate.data.YawRateValid = u8_signalValid==0x01?1:0;
	//Sdc_ChassisData.YawRate.data.YawRateValid = ESP_YawRateValid==0x01?1:0;

	/*TODO : fill the WheelAngle,from 0x180*/
	Sdc_ChassisData.WheelAngle_Header.data.CanId = 0x102;
	Sdc_ChassisData.WheelAngle_Header.data.dlc = 0x08;

	Rte_Read_RP_Sdc_Chassis_Data_EpsSasSteerAg_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_Sdc_RP_Sdc_Chassis_Data_EpsSasSteerAg(&f32_signal);
	}
	else
	{
		f32_signal = 0;
	}
	Sdc_ChassisData.WheelAngle.data.WheelAngle = ((f32_signal + 819.2) / 0.025);
	//Sdc_ChassisData.WheelAngle.data.WheelAngle = ((EpsSasSteerAg + 819.2) / 0.025);
	
	Rte_Read_RP_Sdc_Chassis_Data_EpsSasSteerAgVld(&u8_signalValid);
	Sdc_ChassisData.WheelAngle.data.WheelAngleValid = u8_signalValid==0x00?1:0;
	//Sdc_ChassisData.WheelAngle.data.WheelAngleValid = EpsSasSteerAgVld==0x00?1:0;

	/*TODO : fill the gear position,from 0x161*/
	Sdc_ChassisData.GearPostion_Header.data.CanId = 0x103;
	Sdc_ChassisData.GearPostion_Header.data.dlc = 0x08;

	Rte_Read_RP_Sdc_Chassis_Data_VcuGearPosn_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_RP_Sdc_Chassis_Data_VcuGearPosn(&u8_signal);
	}
	else
	{
		u8_signal = 0;
	}
	/*VcuGearPosn*/
	if(u8_signal == 0)
	{
		Sdc_ChassisData.GearPostion.data.GearPostion = 4; //Invalid
	}
	else if(u8_signal == 1)
	{
		Sdc_ChassisData.GearPostion.data.GearPostion = 1; //P
	}
	else if(u8_signal == 2)
	{
		Sdc_ChassisData.GearPostion.data.GearPostion = 2; //R
	}
	else if(u8_signal == 3)
	{
		Sdc_ChassisData.GearPostion.data.GearPostion = 0; //N
	}
	else if(u8_signal == 4)
	{
		Sdc_ChassisData.GearPostion.data.GearPostion = 3; //D
	}
	else
	{
		Sdc_ChassisData.GearPostion.data.GearPostion = 4; //Invalid
	}

	/*TODO : fill the light status,from 0x28B and 0x288*/
	Sdc_ChassisData.LightStatus_Header.data.CanId = 0x104;
	Sdc_ChassisData.LightStatus_Header.data.dlc = 0x08;
	
	Rte_Read_RP_Sdc_Body_Data_BCM_TurnLightSwitchSts_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_RP_Sdc_Body_Data_BCM_TurnLightSwitchSts(&u8_signal);
	}
	else
	{
		u8_signal = 0;
	}
	Sdc_ChassisData.LightStatus.data.TurnSignal = u8_signal;//CBcmTurnLightSwitchStst;//0x28B

	Rte_Read_RP_Sdc_Body_Data_BcmHiBeamSts_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_RP_Sdc_Body_Data_BcmHiBeamSts(&u8_signal);
	}
	else
	{
		u8_signal = 0;
	}
	if(u8_signal == 1)/*BcmHiBeamSts*/
	{
		Sdc_ChassisData.LightStatus.data.HighBeam = 1;
	}
	else
	{
		Sdc_ChassisData.LightStatus.data.HighBeam = 0;
	}

	Rte_Read_RP_Sdc_Body_Data_BcmFrntWiperSts_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_RP_Sdc_Body_Data_BcmFrntWiperSts(&u8_signal);
	}
	else
	{
		u8_signal = 0;
	}
	if((0x01 == u8_signal) || (0x02 == u8_signal))/*BcmFrntWiperSts*/
	{
		Sdc_ChassisData.LightStatus.data.Wiper = 1;
	}
	else
	{
		Sdc_ChassisData.LightStatus.data.Wiper = 0;
	}

	/*TODO : fill the LongAcc,from 0x278*/
	Sdc_ChassisData.LongAcc_Header.data.CanId = 0x105;
	Sdc_ChassisData.LongAcc_Header.data.dlc = 0x08;

	Rte_Read_RP_Sdc_Chassis_Data_EspLongAccel_Status(&sig_status);
	if(sig_status == E_SIG_STATUS_VALID)
	{
		Rte_Read_Sdc_RP_Sdc_Chassis_Data_EspLongAccel(&f32_signal);
	}
	else
	{
		f32_signal = 0;
	}
	Sdc_ChassisData.LongAcc.data.LongAcc = ((f32_signal + 16.384) / 0.001);

	Rte_Read_RP_Sdc_Chassis_Data_ESP_LongAccelValid(&u8_signalValid);
	Sdc_ChassisData.LongAcc.data.LongAccValid = u8_signalValid==0x01?1:0;
	//Sdc_ChassisData.LongAcc.data.LongAccValid = ESP_LongAccelValid==0x01?1:0;

	/*TODO : Call API send data to SPI service*/
	// now cycle send to j3
}

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

/*==================[internal function definitions]=========================*/


