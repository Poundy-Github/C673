/**
 * \file   Fcu_Lcf.c
 *
 * \brief  Get the signal from CAN and Soc ,then send it to Lcf Algo.
 *
 * \version refer the Fcu_Lcf.h.
 *
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/* ==================[Includes]=============================================== */
#include "Fcu_Lcf.h"
#include "Fcu_Common.h"
#include "Esh_Main.h"
#include "Cps_Lcfg.h"
#include <Rte_Fcu.h>

/*==================[internal data]=========================================*/
/*==================[.rodata]==============================*/
Fcu_const Fcu_volatile uint16 FCU_CALC_OBSTACLE_TTC_EXIST =	70u;
Fcu_const Fcu_volatile sint16 FCU_LDP_VoiceInfo_DlcThresholdLeft_met = -15;
Fcu_const Fcu_volatile sint16 FCU_LDP_VoiceInfo_DlcThresholdRight_met = 15;
Fcu_const Fcu_volatile float32 FCU_LDP_VoiceInfo_DebounceTimeThres_sec = 0.9f; // customer require 900ms
Fcu_const Fcu_volatile float32 FCU_MAX_ACTIVE_DIST_ELKOT = 30.000001f;		 
Fcu_const Fcu_volatile float32 FCU_MINI_SAFETY_DIST_ELKOT = 1.000001f;		 
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_TTC_REAR_OVERHANG = 1.200001f;
Fcu_const Fcu_volatile float32 FCU_ELK_OT_BS_MAX_DELTA_VEL_TRIGGER = 2.78f;
Fcu_const Fcu_volatile float32 FCU_ELK_OT_BS_MIN_DELTA_VEL_TRIGGER = -0.56f;
Fcu_const Fcu_volatile float32 FCU_ELK_OT_BS_MAX_DELTA_VEL_NOT_TRIGGER = -1.39f;
Fcu_const Fcu_volatile float32 FCU_ELK_OT_LATERAL_B2B_DISTANCE_THRESHOLD = 1.0f; // meter
Fcu_const Fcu_volatile float32 FCU_SYSTEM_CYCLETIME_SEC = 0.01f;
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_TTC_MINIMUN = 0.000001f;
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_TTC_TTC_MAX = 40.0f;
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_LOCATION_FLAG_TTC_THRESHOLD1 =	1.0f;//s
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_LOCATION_FLAG_TTC_THRESHOLD2 =	1.5f;//s
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_LOCATION_FLAG_LATERAL_DISTANCE = 4.5f;//m
Fcu_const Fcu_volatile float32 FCU_CALC_OBSTACLE_LOCATION_FLAG_LATERAL_SPEED = 0.001f;//m/s
Fcu_const Fcu_volatile float32 FCU_MOTORTOTQUE_MAXLIMIT_REQ = 20.0f;
Fcu_const Fcu_volatile float32 FCU_MOTORTOTQUE_MIMLIMIT_REQ = -20.0f;

/*==================[.data]==============================*/
Fcu_Static float32 FCU_LDP_VoiceInfo_DebounceTimeLeft = 0.0f;
Fcu_Static float32 FCU_LDP_VoiceInfo_DebounceTimeRight = 0.0f;

/*==================[.bss]==============================*/
Fcu_Static uint8 Fcu_ElkObj1_LocationFlag;
Fcu_Static uint8 Fcu_ElkObj2_LocationFlag;
Fcu_Static uint8 Fcu_ElkObj3_LocationFlag;
Fcu_Static uint8 Fcu_ElkObj4_LocationFlag;
Fcu_Static LCF_GenericInputs_t Fcu_LcfGenericInputData;
Fcu_Static LCF_SenGenericOutputs_t Fcu_LcfSenGenericOutputData;
Fcu_Static LCF_VehGenericOutputs_t Fcu_LcfVehGenericOutputData;

/*==================[external data]=========================================*/
static sint16 Fcu_Len_to_Left_Lane;
static sint16 Fcu_Len_to_Right_Lane;

/*==================[internal function declarations]========================*/
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_LcfGenericInputData(LCF_GenericInputs_t *const ptr_LcfGenericInputData, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_TxProcess_LcfSenGenericOutputData(LCF_SenGenericOutputs_t *const ptr_LcfSenGenericOutputData, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_TxProcess_LcfVehGenericOutputData(LCF_VehGenericOutputs_t *const ptr_LcfVehGenericOutputData, s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal);
Fcu_Static FUNC(void, RTE_CODE) Fcu_ELK_CalcuateTTCFlag(LCF_GenericInputs_t *const ptr_LcfGenericInputData, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal);
Fcu_Static FUNC(float32, RTE_CODE) Fcu_ELK_DataProcess_CalcObstacleTTC(uint8 exist_prob, uint8 measured, float32 dx, float32 dy, float32 rel_vx, float32 rel_ax, float32 Length, float32 Width, uint8 *ttcMode);
Fcu_Static FUNC(uint8, RTE_CODE) Fcu_ELK_DataProcess_CalcObstacleLocationFlag(uint8 location, uint8 light, float32 ttc, float32 lat_dis, float32 lat_spd, float32 obj_width);

/*==================[external function definitions]=========================*/
/**
 * \functions Fcu_Lcf_InitFunction
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
FUNC(void, RTE_CODE) Fcu_Lcf_InitFunction(void)
{
	/*TODO : Clean the local variable*/
	(void)TS_MemBZero(&Fcu_LcfGenericInputData, sizeof(LCF_GenericInputs_t));
	(void)TS_MemBZero(&Fcu_LcfSenGenericOutputData, sizeof(LCF_SenGenericOutputs_t));
	(void)TS_MemBZero(&Fcu_LcfVehGenericOutputData, sizeof(LCF_VehGenericOutputs_t));
}

/**
 * \functions Fcu_Lcf_MainFunction
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
FUNC(void, RTE_CODE) Fcu_Lcf_MainFunction(const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal)
{
	Fcu_RxProcess_LcfGenericInputData(&Fcu_LcfGenericInputData, ptr_Fcu_Rte_input_Signal);
	Fcu_TxProcess_LcfSenGenericOutputData(&Fcu_LcfSenGenericOutputData, ptr_Fcu_Rte_input_Signal,ptr_Fcu_Rte_Output_Signal);
	Fcu_TxProcess_LcfVehGenericOutputData(&Fcu_LcfVehGenericOutputData, ptr_Fcu_Rte_Output_Signal);
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Fcu_RxProcess_LcfGenericInputData
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 *
 * \comments
 *
 */
Fcu_Static FUNC(void, RTE_CODE) Fcu_RxProcess_LcfGenericInputData(LCF_GenericInputs_t *const ptr_LcfGenericInputData, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal)
{
	sint64 s64_Time_Stamp = 0; // TODO : get time stamp

	(void)Time_GetTimeStampMs(&s64_Time_Stamp);
	// Calcuate TTC Flag
	Fcu_ELK_CalcuateTTCFlag(ptr_LcfGenericInputData, ptr_Fcu_Rte_input_Signal);

	ptr_LcfGenericInputData->uiVersionNumber = (AlgoInterfaceVersionNumber_t)LCF_INPUT_INTFVER; // defined from Bench test
	ptr_LcfGenericInputData->sSigHeader.eSigStatus = 0x01;
	ptr_LcfGenericInputData->sSigHeader.uiTimeStamp = (uint32)s64_Time_Stamp;
	ptr_LcfGenericInputData->sSigHeader.uiCycleCounter++;
	ptr_LcfGenericInputData->sSigHeader.uiMeasurementCounter++;
	// EpsSasSteerAg mapped to ps_IPC_e_CL_LCF_GENERIC_INPUT->SteerHandWheelAngle_rad
	ptr_LcfGenericInputData->SteerHandWheelAngle_rad = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSasSteerAg /* factor[* 0.1f] */ * (3.141592653589793f / 180.0f);
	ptr_LcfGenericInputData->DeltaFSteerAngle_deg = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSasSteerAg;
	// EpsSteerAgRate mapped to ps_IPC_e_CL_LCF_GENERIC_INPUT->SteerHandWheelAngleRate_rps
	ptr_LcfGenericInputData->SteerHandWheelAngleRate_rps = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSteerAgRate /* factor[* 4] */ * (3.141592653589793f / 180.0f);
	ptr_LcfGenericInputData->DeltaFSteerAngleRate_degps = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsSteerAgRate;
	// EPS_Pinionang_Valid & EPS_Pinionang mapped to ps_IPC_e_CL_LCF_GENERIC_INPUT->DeltaFSteerAngle_deg
	ptr_LcfGenericInputData->DeltaFSteerAngle_deg = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsPinionang /* factor[* 0.1 -720] */;

	/*TODO : Left*/
	if (((0x01u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[0]) && (0x01u == Fcu_ElkObj1_LocationFlag)) ||
		((0x01u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[1]) && (0x01u == Fcu_ElkObj2_LocationFlag)) ||
		((0x01u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[2]) && (0x01u == Fcu_ElkObj3_LocationFlag)) ||
		((0x01u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[3]) && (0x01u == Fcu_ElkObj4_LocationFlag)))
	{
		ptr_LcfGenericInputData->BSD_Active_Left_nu = 0x01u;
		ptr_LcfGenericInputData->LCA_Active_Left_nu = 0x01u;
	}
	else
	{
		ptr_LcfGenericInputData->BSD_Active_Left_nu = 0x00u;
		ptr_LcfGenericInputData->LCA_Active_Left_nu = 0x00u;
	}

	/*TODO : Right*/
	if (((0x02u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[0]) && (0x01u == Fcu_ElkObj1_LocationFlag)) ||
		((0x02u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[1]) && (0x01u == Fcu_ElkObj2_LocationFlag)) ||
		((0x02u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[2]) && (0x01u == Fcu_ElkObj3_LocationFlag)) ||
		((0x02u == ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[3]) && (0x01u == Fcu_ElkObj4_LocationFlag)))
	{
		ptr_LcfGenericInputData->BSD_Active_Right_nu = 0x01u;
		ptr_LcfGenericInputData->LCA_Active_Right_nu = 0x01u;
	}
	else
	{
		ptr_LcfGenericInputData->BSD_Active_Right_nu = 0x00u;
		ptr_LcfGenericInputData->LCA_Active_Right_nu = 0x00u;
	}

	// The Algorithm requires writing dead
	ptr_LcfGenericInputData->LCA_Warning_Left_nu = 1u;
	ptr_LcfGenericInputData->LCA_Warning_Right_nu = 1u;
	ptr_LcfGenericInputData->BSD_Warning_Left_nu = 1u;
	ptr_LcfGenericInputData->BSD_Warning_Right_nu = 1u;
	// The Algorithm requires writing dead

	if ((0x00u == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmDrvrDoorSts) &&
		(0x00u == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmLeReDoorSts) &&
		(0x00u == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmPassDoorSts) &&
		(0x00u == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmRiReDoorSts))
	{
		ptr_LcfGenericInputData->DoorOpen_nu = 0x00u;
	}
	else
	{
		ptr_LcfGenericInputData->DoorOpen_nu = 0x01u;
	}

	if (((0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspEbdFailr) && (0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAbsFailr)))
	{
		ptr_LcfGenericInputData->ABS_SystemState_nu = 0x0u;
	}
	else
	{
		ptr_LcfGenericInputData->ABS_SystemState_nu = 0x2u;
	}

	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAbsActv)
	{
		ptr_LcfGenericInputData->ABS_ActiveState_nu = 0x1u;
	}
	else
	{
		ptr_LcfGenericInputData->ABS_ActiveState_nu = 0x0u;
	}

	if ((0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspActvSts) || (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspVdcActvSts))
	{
		ptr_LcfGenericInputData->ESC_ActiveState_nu = 0x1u;
	}
	else
	{
		ptr_LcfGenericInputData->ESC_ActiveState_nu = 0x0u;
	}

	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAbsFailr)
	{
		ptr_LcfGenericInputData->TCS_SystemState_nu = 0x02u;
		ptr_LcfGenericInputData->ESC_SystemState_nu = 0x02u;
	}
	else
	{
		ptr_LcfGenericInputData->TCS_SystemState_nu = 0x00u;
		ptr_LcfGenericInputData->ESC_SystemState_nu = 0x00u;
	}

	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspAEBdecActive)
	{
		ptr_LcfGenericInputData->EBA_ActiveState_nu = 0x01u;
	}
	else
	{
		ptr_LcfGenericInputData->EBA_ActiveState_nu = 0x00u;
	}

	if (0x00u == ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_SrsDrvrBucSwtSts)
	{
		ptr_LcfGenericInputData->DriverNotBuckledUp_nu = 0x00u;
	}
	else
	{
		ptr_LcfGenericInputData->DriverNotBuckledUp_nu = 0x01u;
	}

	if (0x02u == GET_FCU_HMI_COMMAND(FUNC_ELK)) // On
	{
		if (TRUE == GET_FCU_FIMSTATE_ELK())
		{
			ptr_LcfGenericInputData->RDPSwitch_nu = 0x01u;
			ptr_LcfGenericInputData->ALCASwitch_nu = 0x01u;
		}
		else
		{
			ptr_LcfGenericInputData->RDPSwitch_nu = 0x00u;
			ptr_LcfGenericInputData->ALCASwitch_nu = 0x00u;
		}
	}
	else if (0x01u == GET_FCU_HMI_COMMAND(FUNC_ELK)) // off
	{
		ptr_LcfGenericInputData->RDPSwitch_nu = 0x00u;
		ptr_LcfGenericInputData->ALCASwitch_nu = 0x00u;
	}
	else // Inactive
	{	 /*Do nothing.*/
	}

	if (0x01u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // LDW On
	{
		/**When the below condtions are full satisfied,shall be active LDW Algo.
		 *Case1: The all degradation DTC(inlcude DTC_D7A1F0) not trigger .OR
		 *Case2: Only trigger DTC_D7A1F0.
		 * <1>Only Trigger DTC_D7A1F0(Indicate the Can signal(Eps_ConcussAvailabilityStatus)) is invalid. AND
		 * <2>The LDw wanring mode not in sound and vibration(0x04) and vibration(0x03). AND
		 * <3>Not other degradation DTC tigger.
		 */
		uint8 u8_HU_LASWarningModeSelection = GET_FCU_HMI_COMMAND(FUNC_LDW_Warning);

		if (((TRUE == GET_FCU_FIMSTATE_LDW()) && (GET_Esh_FIMSts_U17A1F0_NOT_ACTIVED())) ||
			((GET_Esh_FIMSts_U17A1F0_ACTIVED()) && (0x04u != u8_HU_LASWarningModeSelection) && (0x03u != u8_HU_LASWarningModeSelection) && (TRUE == GET_FCU_FIMSTATE_LDW())))
		{
			ptr_LcfGenericInputData->LDWSwitch_nu = 0x01u; // On
			ptr_LcfGenericInputData->LDPSwitch_nu = 0x00u;
		}
		else
		{
			ptr_LcfGenericInputData->LDWSwitch_nu = 0x00u; // Off
			ptr_LcfGenericInputData->LDPSwitch_nu = 0x00u;
		}
	}
	else if (0x02u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // LKA On
	{
		if (TRUE == GET_FCU_FIMSTATE_LKA())
		{
			ptr_LcfGenericInputData->LDWSwitch_nu = 0x00u;
			ptr_LcfGenericInputData->LDPSwitch_nu = 0x01u;
		}
		else // The DTC trigger, shall be inacitve algo.
		{
			ptr_LcfGenericInputData->LDWSwitch_nu = 0x00u;
			ptr_LcfGenericInputData->LDPSwitch_nu = 0x00u;
		}
	}
	else if (0x07u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // Off
	{
		ptr_LcfGenericInputData->LDWSwitch_nu = 0x00u;
		ptr_LcfGenericInputData->LDPSwitch_nu = 0x00u;
	}
	else // Inactive
	{
	}

	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EspTcsActvSts)
	{
		ptr_LcfGenericInputData->TCS_ActiveState_nu = 0x01u;
	}
	else
	{
		ptr_LcfGenericInputData->TCS_ActiveState_nu = 0x00u;
	}

	/*TODO: EPS LCF control activate*/
	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlActive)
	{
		ptr_LcfGenericInputData->EPS_Toi_Active_nu = 0x01u;
	}
	else
	{
		ptr_LcfGenericInputData->EPS_Toi_Active_nu = 0x00u;
	}

	if (0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlAvailabilityStatus)
	{
		ptr_LcfGenericInputData->EPS_Toi_Flt_nu = 0x00u;
		ptr_LcfGenericInputData->EPS_Toi_Unavail_nu = 0x01u;
	}
	else if ((0x00u != ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsIACCabortreason) || (0x02u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlAvailabilityStatus))
	{
		ptr_LcfGenericInputData->EPS_Toi_Flt_nu = 0x01u;
		ptr_LcfGenericInputData->EPS_Toi_Unavail_nu = 0x00u;
	}
	else if ((0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlAvailabilityStatus) && (0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsIACCabortreason))
	{
		ptr_LcfGenericInputData->EPS_Toi_Flt_nu = 0x00u;
		ptr_LcfGenericInputData->EPS_Toi_Unavail_nu = 0x00u;
	}
	else
	{
		ptr_LcfGenericInputData->EPS_Toi_Flt_nu = 0x01u;
		ptr_LcfGenericInputData->EPS_Toi_Unavail_nu = 0x01u;
	}

	if (0x00u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EPS_MeasuredTorsionBarTorqValid)
	{
		ptr_LcfGenericInputData->State_nu[5] = LCF_IO_STATE_VALID;
		ptr_LcfGenericInputData->DrvSteerWheelTrq_nm = ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EpsMeasuredTorsionBarTorque;
	}
	else if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EPS_MeasuredTorsionBarTorqValid)
	{
		ptr_LcfGenericInputData->State_nu[5] = LCF_IO_STATE_INVALID;
	}

	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IBCU_PFSBrakePressureValid) // IBCU_PFSBrakePressure
	{
		ptr_LcfGenericInputData->MainCylPressure_pa = (float32)ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_BrakePressureSimulator * 100000.f; // IBCU_PFSBrakePressure
	}
	else
	{
		ptr_LcfGenericInputData->MainCylPressure_pa = 0.0f;
	}

	ptr_LcfGenericInputData->IACCHWAMode_nu = ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_AccIaccHWAMode;

	if (0x01u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_IbBrkPedlTrvlDrvrVld) // BrakePedalPostion_mm
	{
		ptr_LcfGenericInputData->BrakePedalPostion_mm = min(max(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_IbBrkPedlTrvlDrvr,-5),47); // BrakePedalPostion_mm
	}
	else
	{
		ptr_LcfGenericInputData->BrakePedalPostion_mm = 0.0f;
	}
	

	(void)Rte_Write_PP_Fcu_LcfGenericInputData_LcfGenericInputData(ptr_LcfGenericInputData);
}

/**
 * \functions Fcu_TxProcess_LcfSenGenericOutputData
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
Fcu_Static FUNC(void, RTE_CODE) Fcu_TxProcess_LcfSenGenericOutputData(LCF_SenGenericOutputs_t *const ptr_LcfSenGenericOutputData, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal)
{
	uint8 u8_Vdy_ActGearPos;
	float32 f32_Vdy_SpeedoSpeed;
	uint8_t u8_FC_LASWarningModeSelectionSts = 0;
	static uint8_t u8_FC_LDWStatus_LastVal = 0;
	static uint8_t u8_FC_LKAStatus_LastVal = 0;
	static uint8_t u8_FC_HostLeft_Status= 0;
	static uint8_t u8_FC_HostRight_Status= 0;


	/*TODO : Read data from RTE*/
	(void)Rte_Read_RP_LcfAdapter_LcfSenGenericOutputData_LcfSenGenericOutputData(ptr_LcfSenGenericOutputData);

	Rte_Call_RP_Sdc_SendInterface_Perception_HostLane_Left_flag_Read(&u8_FC_HostLeft_Status);

 	Rte_Call_RP_Sdc_SendInterface_Perception_HostLane_Right_flag_Read(&u8_FC_HostRight_Status);

	/*Vdy Speed*/
	if (ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd <= 5.0f)
	{
		f32_Vdy_SpeedoSpeed = (float32)((uint32)ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd);
	}
	else
	{
		f32_Vdy_SpeedoSpeed = (float32)((uint32)(ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.f32_Rte_EspVehSpd / 0.98f + 2.0f));
	}

	/*Vdy ActGearPos*/
	if (0u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuVehGearPosnVld)
	{
		if (1u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn) // P
		{
			u8_Vdy_ActGearPos = 1u;
		}
		else if (2u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn) // R
		{
			u8_Vdy_ActGearPos = 3u;
		}
		else if (3u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn) // N
		{
			u8_Vdy_ActGearPos = 0u;
		}
		else if (4u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_VcuGearPosn) // D
		{
			u8_Vdy_ActGearPos = 2u;
		}
		else
		{ /*Do nothing.*/
		}
	}
	else
	{
		u8_Vdy_ActGearPos = 0;
	}
	
	ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWShakeLevStatus = 2u;

	/*Left*/
	if ((0x03u == ptr_LcfSenGenericOutputData->LDPSystemStateLeft_nu) ||
		(0x03u == ptr_LcfSenGenericOutputData->RDPSystemStateLeft_nu) ||
		(0x03u == ptr_LcfSenGenericOutputData->ALCASystemStateLeft_nu))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneLeftStatus = 0x02u;
	}
	else if (0x03u == ptr_LcfSenGenericOutputData->LDWSystemStateLeft_nu)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneLeftStatus = 0X03u;
	}
	else if (0x01u == u8_FC_HostLeft_Status)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneLeftStatus = 0X01u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneLeftStatus = 0x00u;
	}

	/*Right*/
	if ((0x03u == ptr_LcfSenGenericOutputData->LDPSystemStateRight_nu) ||
		(0x03u == ptr_LcfSenGenericOutputData->RDPSystemStateRight_nu) ||
		(0x03u == ptr_LcfSenGenericOutputData->ALCASystemStateRight_nu))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneRightStatus = 0x02u;
	}
	else if (0x03u == ptr_LcfSenGenericOutputData->LDWSystemStateRight_nu) /*RUNNING*/
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneRightStatus = 0X03u;
	}
	else if (0x01u == u8_FC_HostRight_Status)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneRightStatus = 0X01u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_HostLaneRightStatus = 0x00u;
	}

	/*HU_LASWarningModeSelection(GW507) -> FC_LASWarningModeSelectionSts(FC_108)*/
	if (0x02u == GET_FCU_HMI_COMMAND(FUNC_LDW_Warning)) // sound
	{
		u8_FC_LASWarningModeSelectionSts = 0x01u;
	}
	else if (0x04u == GET_FCU_HMI_COMMAND(FUNC_LDW_Warning)) // sound and vibration
	{
		u8_FC_LASWarningModeSelectionSts = 0x03u;
	}
	else if (0x03u == GET_FCU_HMI_COMMAND(FUNC_LDW_Warning)) // vibration
	{
		u8_FC_LASWarningModeSelectionSts = 0x02u;
	}
	else
	{
		/*Do nothing.*/
	}

	ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts = u8_FC_LASWarningModeSelectionSts;

	/*The function Degradation logic of LKA and LDW as Below:
	Active precondtion:
	<1> Function Acitve command of LKA from HMI(HU_LASModeSelection = 0x02(LKA on)) OR
	<2> Function Acitve command of LDW from HMI(HU_LASModeSelection = 0x01(LDW on)) OR
	<>3 Funcrion Off command from HMI(HU_LASModeSeclection = 0x07(Off)) OR
	<3> The other value not ative any algo.
	*/
	/*Note: MFC5J3CN15-270: In some time, only on function (LKA or LDW) shall be active, the other function shall be keep switch off.*/
	if (0x02u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // LKA On
	{
		if (TRUE == GET_FCU_FIMSTATE_LKA())
		{
			boolean b_Active_Condition_systemState = FALSE;
			boolean b_Active_Condition_Vehiclespeed = FALSE;
			boolean b_Active_Condition_VdyActGearPos = FALSE;

			if ((0x02u /*LCF_SYSSTATE_PASSIVE*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu) ||
				(0x03u /*LCF_SYSSTATE_REQUEST*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu) ||
				(0x04u /*LCF_SYSSTATE_CONTROLLING*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu) ||
				(0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu))
			{
				b_Active_Condition_systemState = TRUE;
			}
			else
			{
				b_Active_Condition_systemState = FALSE;
			}

			/*
			 *ConditionA: (f32_Vdy_SpeedoSpeed >= 60.0f)
			 *ConditionB: (((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LKAStatus_LastVal))
			 *ConditionC:  A || B
			 *COnditionF: (150.0f >= f32_Vdy_SpeedoSpeed)
			 *ConditionG: (((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LKAStatus_LastVal))
			 *ConditionH: F || G
			 *ConditionJ: (3U != u8_Vdy_ActGearPos)
			 *last results: C && H && J
			 */
			if ((f32_Vdy_SpeedoSpeed >= 60.0f) /*A*/ || (((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LKAStatus_LastVal))) // C:--> A||B
			{
				if ((150.0f >= f32_Vdy_SpeedoSpeed) /*F*/ || (((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LKAStatus_LastVal))) // H:--> F||G
				{
					b_Active_Condition_Vehiclespeed = TRUE;
				}
				else
				{
					b_Active_Condition_Vehiclespeed = FALSE;
				}
			}
			else
			{
				b_Active_Condition_Vehiclespeed = FALSE;
			}

			if (3U != u8_Vdy_ActGearPos) // Not in "R" postion
			{
				b_Active_Condition_VdyActGearPos = TRUE;
			}
			else
			{
				b_Active_Condition_VdyActGearPos = FALSE;
			}

			if (((0x06u /*LCF_SYSSTATE_ERROR*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu) ||
				 (0x02u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlAvailabilityStatus)) &&
				(0x01u == Fcu_LcfGenericInputData.LDPSwitch_nu))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus = 0x03u; // Failure
			}
			else if ((TRUE == b_Active_Condition_systemState) &&
					 (TRUE == b_Active_Condition_Vehiclespeed) &&
					 (TRUE == b_Active_Condition_VdyActGearPos))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus = 0x02u; // active
			}
			else if ((0x02u /*LCF_SYSSTATE_PASSIVE*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu) ||
					 (0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->LDPSystemState_nu))
			{
				/*
				ConditionA: ((55.0f > f32_Vdy_SpeedoSpeed) || (f32_Vdy_SpeedoSpeed > 155.0f))
				CondtionB:  ((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed) && (0x02u != u8_FC_LKAStatus_LastVal))
				COndtionC:  (0x02u != u8_FC_LKAStatus_LastVal)
				CondtionD -> A || (B && C)
				CondtionE: ((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed))
				ConditioF: (0x02u != u8_FC_LKAStatus_LastVal)
				ConditionG -> E && F
				ConditionH -> D || G
				CondtionI: (3U == u8_Vdy_ActGearPos)
				Last Results: H || I
				*/
				if (((55.0f > f32_Vdy_SpeedoSpeed) || (f32_Vdy_SpeedoSpeed > 155.0f)) ||
					((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed) && (0x02u != u8_FC_LKAStatus_LastVal)) /*D--> A||(B && C) */ ||
					((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed) && (0x02u != u8_FC_LKAStatus_LastVal)) /*G--> E && F*/ ||
					(3U == u8_Vdy_ActGearPos))
				{
					ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus = 0x01u; // standby
				}
				else
				{ /*Do nothing.*/
				}
			}
			else if (0x00u == ptr_LcfSenGenericOutputData->LDPSystemState_nu)
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus = 0x01u; // standby
			}
			else
			{
				/*Do nothing.*/
			}
		}
		else
		{
			ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus = 0x03u; // Failure
		}
	}
	else if(0x07u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA) || (0x01u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA))) //Switch off or LDW Func Active
	{
        ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus = 0x00u; //Off
	}
	else
	{   
	    /*0x03: Lcs 0x00,0x04: Reserved*/
        /*MFC5J3CN15-270:when get other signal value from CAN, shall be keep value as pervious.*/
	}
    
	u8_FC_LKAStatus_LastVal = ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKAStatus;

	if (0x01u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // LDW on
	{
		/**When the below condtions are full satisfied,shall be active LDW Algo.
		 *Case1: The all degradation DTC(inlcude DTC_D7A1F0) not trigger .OR
		 *Case2: Only trigger DTC_D7A1F0.
		 * <1>Only Trigger DTC_D7A1F0(Indicate the Can signal(Eps_ConcussAvailabilityStatus)) is invalid. AND
		 * <2>The LDw wanring mode not in sound and vibration(0x04) and vibration(0x03). AND
		 * <3>Not other degradation DTC tigger.
		 */
		uint8 u8_HU_LASWarningModeSelection = GET_FCU_HMI_COMMAND(FUNC_LDW_Warning);

		if (((TRUE == GET_FCU_FIMSTATE_LDW()) && (GET_Esh_FIMSts_U17A1F0_NOT_ACTIVED())) ||
			((GET_Esh_FIMSts_U17A1F0_ACTIVED()) && (0x04u != u8_HU_LASWarningModeSelection) && (0x03u != u8_HU_LASWarningModeSelection) && (TRUE == GET_FCU_FIMSTATE_LDW())))
		{
			boolean b_LDW_ActiveCondition_SystemState = FALSE;
			boolean b_LDW_ActiveCondition_VdySpeed = FALSE;
			boolean b_LDW_ActiveCondition_VdyActGearPos = FALSE;

			if ((0x02u /*LCF_SYSSTATE_PASSIVE*/ == ptr_LcfSenGenericOutputData->LDWSystemState_nu) ||
				(0x03u /*LCF_SYSSTATE_REQUEST*/ == ptr_LcfSenGenericOutputData->LDWSystemState_nu) ||
				(0x04u /*LCF_SYSSTATE_CONTROLLING*/ == ptr_LcfSenGenericOutputData->LDWSystemState_nu) ||
				(0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->LDWSystemState_nu))
			{
				b_LDW_ActiveCondition_SystemState = TRUE;
			}
			else
			{
				b_LDW_ActiveCondition_SystemState = FALSE;
			}

			/*
			ConditionA: (f32_Vdy_SpeedoSpeed >= 60.0f)
			ConditionB: (((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LDWStatus_LastVal))
			ConditionC:  A || B
			COnditionF: (150.0f >= f32_Vdy_SpeedoSpeed)
			ConditionG: (((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LDWStatus_LastVal))
			ConditionH: F || G
			ConditionJ: (3U != u8_Vdy_ActGearPos)
			last results: C && H && J
			*/
			if ((f32_Vdy_SpeedoSpeed >= 60.0f) /*A*/ || (((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LDWStatus_LastVal))) // C:--> A||B
			{
				if ((150.0f >= f32_Vdy_SpeedoSpeed) /*F*/ || (((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed)) && (0x02u == u8_FC_LDWStatus_LastVal))) // H:--> F||G
				{
					b_LDW_ActiveCondition_VdySpeed = TRUE;
				}
				else
				{
					b_LDW_ActiveCondition_VdySpeed = FALSE;
				}
			}
			else
			{
				b_LDW_ActiveCondition_VdySpeed = FALSE;
			}

			if (3U != u8_Vdy_ActGearPos)
			{
				b_LDW_ActiveCondition_VdyActGearPos = TRUE;
			}
			else
			{
				b_LDW_ActiveCondition_VdyActGearPos = FALSE;
			}

			if (((0x06u == ptr_LcfSenGenericOutputData->LDWSystemState_nu) ||
				 ((0x02u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlAvailabilityStatus) &&
				  ((0x02u == u8_FC_LASWarningModeSelectionSts) || (0x03u == u8_FC_LASWarningModeSelectionSts)))) &&
				(0x01u == Fcu_LcfGenericInputData.LDWSwitch_nu))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus = 0x03u; // Failure
			}
			else if ((TRUE == b_LDW_ActiveCondition_SystemState) &&
					 (TRUE == b_LDW_ActiveCondition_VdySpeed) &&
					 (TRUE == b_LDW_ActiveCondition_VdyActGearPos))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus = 0x02u; // active
			}
			else if (0x02 /*LCF_SYSSTATE_PASSIVE*/ == ptr_LcfSenGenericOutputData->LDWSystemState_nu)
			{
				/*
				ConditionA: ((55.0f > f32_Vdy_SpeedoSpeed) || (f32_Vdy_SpeedoSpeed > 155.0f))
				CondtionB:  ((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed) && (0x02u != u8_FC_LDWStatus_LastVal))
				COndtionC:  (0x02u != u8_FC_LDWStatus_LastVal)
				CondtionD -> A || (B && C)
				CondtionE: ((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed))
				ConditioF: (0x02u != u8_FC_LDWStatus_LastVal)
				ConditionG -> E && F
				ConditionH -> D || G
				CondtionI: (3U == u8_Vdy_ActGearPos)
				Last Results: H || I
				*/
				if (((55.0f > f32_Vdy_SpeedoSpeed) || (f32_Vdy_SpeedoSpeed > 155.0f)) ||
					((150.0f < f32_Vdy_SpeedoSpeed) && (155.0f >= f32_Vdy_SpeedoSpeed) && (0x02u != u8_FC_LDWStatus_LastVal)) /*D--> A||(B && C) */ ||
					((55.0f <= f32_Vdy_SpeedoSpeed) && (60.0f > f32_Vdy_SpeedoSpeed) && (0x02u != u8_FC_LDWStatus_LastVal)) /*G--> E && F*/ ||
					(3U == u8_Vdy_ActGearPos))
				{
					ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus = 0x01u; // standby
				}
				else
				{ /*Do nothing.*/
				}
			}
			else if (0x00u == ptr_LcfSenGenericOutputData->LDWSystemState_nu)
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus = 0x01u; // standby
			}
			else
			{
				/*Do nothing.*/
			}
		}
		else
		{
			ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus = 0x03u; // Failure
		}
	}
	else if(0x07u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA) || (0x02u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA))) // Siwtch Off or LKA Func Active
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus = 0x00u;
	}
	else
	{   
	    /*0x03: Lcs 0x00,0x04: Reserved*/
        /*MFC5J3CN15-270:when get other signal value from CAN, shall be keep value as pervious.*/
	}

	u8_FC_LDWStatus_LastVal = ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWStatus;

	/*HU_LASModeSelection(GW507) --> FC_LASModeSelectionStatus(FC_108)*/
	if (0x02u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // LKA On
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus = 0x02u; // LKA
	}
	else if (0x01u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) // LDW on
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus = 0x01u; // LDW
	}
	else if(0x07u == GET_FCU_HMI_COMMAND(FUNC_LDW_or_LKA)) //off
	{
        ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus = 0x07u;
	}
	else
	{
	    /*0x03: Lcs 0x00,0x04: Reserved*/
		/*MFC5J3CN15-270:when get other signal value from CAN, shall be keep value as pervious.*/
	}

	/*FC_LDWVibrationWarningReq*/
	if (((0x02u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts) || (0x03u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts)) &&
		(0x03u /*LCF_LAT_CONTROL_RUNNING*/ == ptr_LcfSenGenericOutputData->LDWSystemStateLeft_nu))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWVibrationWarningReq = 0x01u;
	}
	else if (((0x02u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts) || (0x03u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts)) &&
			 (0x03u /*LCF_LAT_CONTROL_RUNNING*/ == ptr_LcfSenGenericOutputData->LDWSystemStateRight_nu))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWVibrationWarningReq = 0x02u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LDWVibrationWarningReq = 0x00u;
	}

	/*ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_Voiceinfo
	canbus:
			0x0=no voice
			0x1=latentWarning voive
			0x2=FCW/AEB voice
			0x3=ACC object detect voice
			0x4=ACC object disappeared voice
			0x5=ACC/IACC takeover request voice
			0x6=Lane Left dangerous warning  voice
			0x7=Lane Right dangerous warning  voice
			0x8=reserved
			0x9=IACC Active voice
			0xA=IACC exit voice
			0xB=reserved
			0xC=reserved
			0xD=cruise unintended exit
			0x0E=TrafficWarning
			0xF~0x1F=reserved
	*/

	Rte_Call_RP_Sdc_SendInterface_Perception_Len_to_Left_Lane_Read(&Fcu_Len_to_Left_Lane);
	Rte_Call_RP_Sdc_SendInterface_Perception_Len_to_Right_Lane_Read(&Fcu_Len_to_Right_Lane);
	if ((((0x01u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts) || (0x03u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts)) && ((0x03u /*LCF_LAT_CONTROL_RUNNING*/ == Fcu_LcfSenGenericOutputData.LDWSystemStateLeft_nu))) || (0x03u /*LCF_LAT_CONTROL_RUNNING*/ == Fcu_LcfSenGenericOutputData.LDPSystemStateLeft_nu && (Fcu_Len_to_Left_Lane < FCU_LDP_VoiceInfo_DlcThresholdLeft_met && FCU_LDP_VoiceInfo_DebounceTimeLeft < FCU_LDP_VoiceInfo_DebounceTimeThres_sec))) // Lane Left
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_Voiceinfo_Lcf = 0x06u; // Lane Left dangerous warning? voice
		FCU_LDP_VoiceInfo_DebounceTimeLeft += ((float)FCU_SYSTEM_CYCLETIME_SEC);
	}
	else if ((((0x01u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts) || (0x03u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASWarningModeSelectionSts)) && ((0x03u /*LCF_LAT_CONTROL_RUNNING*/ == Fcu_LcfSenGenericOutputData.LDWSystemStateRight_nu))) || (0x03u /*LCF_LAT_CONTROL_RUNNING*/ == Fcu_LcfSenGenericOutputData.LDPSystemStateRight_nu && (Fcu_Len_to_Right_Lane > FCU_LDP_VoiceInfo_DlcThresholdRight_met && FCU_LDP_VoiceInfo_DebounceTimeRight < FCU_LDP_VoiceInfo_DebounceTimeThres_sec))) // Lane Right
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_Voiceinfo_Lcf = 0x07u; // Lane Right dangerous warning? voice
		FCU_LDP_VoiceInfo_DebounceTimeRight += ((float)FCU_SYSTEM_CYCLETIME_SEC);
	}
	else if ((ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_Voiceinfo_Lcf == 0x06) || (ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_Voiceinfo_Lcf == 0x07u))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_Voiceinfo_Lcf = 0u; // no voice
	}
	else
	{
		if (0x03u /*LCF_LAT_CONTROL_RUNNING*/ != Fcu_LcfSenGenericOutputData.LDPSystemStateLeft_nu)
		{
			FCU_LDP_VoiceInfo_DebounceTimeLeft = 0.f;
		}
		if (0x03u /*LCF_LAT_CONTROL_RUNNING*/ != Fcu_LcfSenGenericOutputData.LDPSystemStateRight_nu)
		{
			FCU_LDP_VoiceInfo_DebounceTimeRight = 0.f;
		}
	}

#if FC_LKATAKEOVER_REQ 
	/*FC_LKATakeoverReq*/
	if ((0x02u == ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LASModeSelectionStatus) &&
			((0x06u /*LCF_LAT_CONTROL_CANCEL_LAT_DEVIATION*/ == ptr_LcfSenGenericOutputData->LDWSystemStateLeft_nu) && (ptr_LcfSenGenericOutputData->Visualization.AllCorridors.LeftCorridor.CorridorHeading_rad > 0.0f)) ||
		((0x06u /*LCF_LAT_CONTROL_CANCEL_LAT_DEVIATION*/ == ptr_LcfSenGenericOutputData->LDWSystemStateRight_nu) && (ptr_LcfSenGenericOutputData->Visualization.AllCorridors.LeftCorridor.CorridorHeading_rad < 0.0f)))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKATakeoverReq = 0x01u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LKATakeoverReq = 0x00u;
	}
#endif 

	/*The function Degradation logic of ELK as Below:
	Active precondtion:
	<1> Function Acitve command of ELK from HMI(HU_ELKEnable = 0x02(on))
	*/
	if (0x02u == GET_FCU_HMI_COMMAND(FUNC_ELK))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKEnableStatus = 0x01u; // on

		if (TRUE == GET_FCU_FIMSTATE_ELK())
		{
			if ((0x06u == ptr_LcfSenGenericOutputData->RDPSystemState_nu) ||
				(0x02u == ptr_Fcu_Rte_input_Signal->ChassisDomain_Data.u8_Rte_EpsLatCtrlAvailabilityStatus) ||
				(0x06u == ptr_LcfSenGenericOutputData->ALCASystemState_nu))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKMode = 0x03u;
			}
			else if ((0x03u /*LCF_SYSSTATE_REQUEST*/ == ptr_LcfSenGenericOutputData->RDPSystemState_nu) ||
					 (0x04u /*LCF_SYSSTATE_CONTROLLING*/ == ptr_LcfSenGenericOutputData->RDPSystemState_nu) ||
					 (0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->RDPSystemState_nu) ||
					 (0x03u /*LCF_SYSSTATE_REQUEST*/ == ptr_LcfSenGenericOutputData->ALCASystemState_nu) ||
					 (0x04u /*LCF_SYSSTATE_CONTROLLING*/ == ptr_LcfSenGenericOutputData->ALCASystemState_nu) ||
					 (0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->ALCASystemState_nu))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKMode = 0x02u;
			}
			else if ((0x02u /*LCF_SYSSTATE_PASSIVE*/ == ptr_LcfSenGenericOutputData->RDPSystemState_nu) &&
					 (0x02u /*LCF_SYSSTATE_PASSIVE*/ == ptr_LcfSenGenericOutputData->ALCASystemState_nu))
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKMode = 0x01u;
			}
			else
			{
				ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKMode = 0x00u;
			}
		}
		else
		{
			ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKMode = 0x03u; // Fault;
		}
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKEnableStatus = 0x00u; // Off
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKMode = 0x00u;		  // Off
	}

	/*TODO : FC_ELKInterventionMode*/
	if ((0x04u /*LCF_SYSSTATE_CONTROLLING*/ == ptr_LcfSenGenericOutputData->RDPSystemState_nu) ||
		(0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->RDPSystemState_nu))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKInterventionMode = 0x01u;
	}
	else if ((0x04u /*LCF_SYSSTATE_CONTROLLING*/ == ptr_LcfSenGenericOutputData->ALCASystemState_nu) ||
			 (0x05u /*LCF_SYSSTATE_RAMPOUT*/ == ptr_LcfSenGenericOutputData->ALCASystemState_nu))
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKInterventionMode = 0x02u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_ELKInterventionMode = 0x00u;
	}
}

/**
 * \functions Fcu_TxProcess_LcfVehGenericOutputData
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
Fcu_Static FUNC(void, RTE_CODE) Fcu_TxProcess_LcfVehGenericOutputData(LCF_VehGenericOutputs_t *const ptr_LcfVehGenericOutputData,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal)
{
	/*TODO : Read data from RTE*/
	(void)Rte_Read_RP_LcfAdapter_LcfVehGenericOutputData_LcfVehGenricOutputData(ptr_LcfVehGenericOutputData);

	if (LCF_ACTIVATE_TOI == ptr_LcfVehGenericOutputData->Lkas_ActToi_nu)
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LatAngReqActive = 1u;
	}
	else
	{
		ptr_Fcu_Rte_Output_Signal->Lcf_Data.u8_FC_LatAngReqActive = 0u;
	}

	ptr_Fcu_Rte_Output_Signal->Lcf_Data.f32_FC_LatAngReq = ptr_LcfVehGenericOutputData->LaDMC_StrAngReq_deg /* factor[* 0.1 - 720] */;

	ptr_Fcu_Rte_Output_Signal->Lcf_Data.f32_FC_MotorTorqueMaxLimitRequest = FCU_MOTORTOTQUE_MAXLIMIT_REQ;
	ptr_Fcu_Rte_Output_Signal->Lcf_Data.f32_FC_MotorTorqueMinLimitRequest = FCU_MOTORTOTQUE_MIMLIMIT_REQ;
}

/**
 * \functions Fcu_ELK_CalcuateTTCFlag
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
Fcu_Static FUNC(void, RTE_CODE) Fcu_ELK_CalcuateTTCFlag(LCF_GenericInputs_t *const ptr_LcfGenericInputData, const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal)
{
	uint8 u_ttcMode1 = 0;
	uint8 u_ttcMode2 = 0;
	uint8 u_ttcMode3 = 0;
	uint8 u_ttcMode4 = 0;
	float32 f_ElkObj1_TTC = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
	float32 f_ElkObj2_TTC = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
	float32 f_ElkObj3_TTC = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
	float32 f_ElkObj4_TTC = FCU_CALC_OBSTACLE_TTC_TTC_MAX;

	/*TODO : Calc ElkObj1 TTC*/
	f_ElkObj1_TTC = Fcu_ELK_DataProcess_CalcObstacleTTC(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_ExistProb[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Measured[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dx[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVx[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelAx[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Length[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[0],
		&u_ttcMode1);

	f_ElkObj2_TTC = Fcu_ELK_DataProcess_CalcObstacleTTC(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_ExistProb[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Measured[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dx[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVx[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelAx[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Length[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[1],
		&u_ttcMode2);

	f_ElkObj3_TTC = Fcu_ELK_DataProcess_CalcObstacleTTC(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_ExistProb[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Measured[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dx[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVx[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelAx[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Length[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[2],
		&u_ttcMode3);

	f_ElkObj4_TTC = Fcu_ELK_DataProcess_CalcObstacleTTC(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_ExistProb[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Measured[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dx[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVx[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelAx[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Length[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[3],
		&u_ttcMode4);

	/*TODO : Calc ElkObj1 Location Flag*/
	Fcu_ElkObj1_LocationFlag = Fcu_ELK_DataProcess_CalcObstacleLocationFlag(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[0],
		ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst,
		f_ElkObj1_TTC,
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVy[0],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[0]);

	Fcu_ElkObj2_LocationFlag = Fcu_ELK_DataProcess_CalcObstacleLocationFlag(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[1],
		ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst,
		f_ElkObj2_TTC,
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVy[1],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[1]);

	Fcu_ElkObj3_LocationFlag = Fcu_ELK_DataProcess_CalcObstacleLocationFlag(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[2],
		ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst,
		f_ElkObj3_TTC,
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVy[2],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[2]);

	Fcu_ElkObj4_LocationFlag = Fcu_ELK_DataProcess_CalcObstacleLocationFlag(
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.u8_Rte_Radar_Location[3],
		ptr_Fcu_Rte_input_Signal->BodyDomain_Data.u8_Rte_BcmTurnLightSwitchStst,
		f_ElkObj4_TTC,
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Dy[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_RelVy[3],
		ptr_Fcu_Rte_input_Signal->AdasDomain_Data.f32_Rte_Radar_Width[3]);

	ptr_LcfGenericInputData->ElkObj1_TTC = f_ElkObj1_TTC;
	ptr_LcfGenericInputData->ElkObj2_TTC = f_ElkObj2_TTC;
	ptr_LcfGenericInputData->ElkObj3_TTC = f_ElkObj3_TTC;
	ptr_LcfGenericInputData->ElkObj4_TTC = f_ElkObj4_TTC;
	ptr_LcfGenericInputData->Fcu_ElkObj1_LocationFlag = Fcu_ElkObj1_LocationFlag;
	ptr_LcfGenericInputData->Fcu_ElkObj2_LocationFlag = Fcu_ElkObj2_LocationFlag;
	ptr_LcfGenericInputData->Fcu_ElkObj3_LocationFlag = Fcu_ElkObj3_LocationFlag;
	ptr_LcfGenericInputData->Fcu_ElkObj4_LocationFlag = Fcu_ElkObj4_LocationFlag;
	ptr_LcfGenericInputData->ttcMode1 = u_ttcMode1;
	ptr_LcfGenericInputData->ttcMode2 = u_ttcMode2;
	ptr_LcfGenericInputData->ttcMode3 = u_ttcMode3;
	ptr_LcfGenericInputData->ttcMode4 = u_ttcMode4;
}

/**
 * \functions Fcu_ELK_DataProcess_CalcObstacleTTC
 *
 * \brief
 *
 * \parameters-in   exist_prob : RLR_ElkOBJ1_ExistProb
 * 					measured : RLR_ElkOBJ1_Measured
 * 					dx : RLR_ElkOBJ1_Dx
 * 					rel_vx : RLR_ElkOBJ1_RelVx
 * 					rel_ax : RLR_ElkOBJ1_RelAx
 *
 * \parameters-out TTC
 *
 * \return 	none
 *
 * \comments Calc 4 obstacle ttc
 *
 */
Fcu_Static FUNC(float32, RTE_CODE) Fcu_ELK_DataProcess_CalcObstacleTTC(uint8 exist_prob, uint8 measured, float32 dx, float32 dy, float32 rel_vx, float32 rel_ax, float32 Length, float32 Width, uint8 *ttcMode)
{
	float32 ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;

	float32 dx_b2b;
	float32 dy_b2b;
	dx_b2b = dx + Length / 2 + FCU_CALC_OBSTACLE_TTC_REAR_OVERHANG;

	if (dy > 0)
	{
		dy_b2b = dy - VDY_VEHICLEWIDTH / 2 - Width / 2; // VDY_VEHICLEWIDTH ==  1.928f Wheel outer edge distance
	}
	else
	{
		dy_b2b = -dy - VDY_VEHICLEWIDTH / 2 - Width / 2; // VDY_VEHICLEWIDTH ==  1.928f Wheel outer edge distance
	}

	if ((exist_prob > FCU_CALC_OBSTACLE_TTC_EXIST) && ((0x01 /*Measured*/ == measured) || (0x02 /*Predicted*/ == measured)))
	{

		// Xu Qiang modify 2023-01-08
		if (dx_b2b < -FCU_MAX_ACTIVE_DIST_ELKOT) // FCU_MAX_ACTIVE_DIST_ELKOT = 30.0f;
		{
			ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
			*ttcMode = 1;
		}
		else if (dx_b2b < -FCU_MINI_SAFETY_DIST_ELKOT) // FCU_MINI_SAFETY_DIST_ELKOT = 2.0f;
		{
			if (rel_vx >= 0)
			{
				ttc = (-dx_b2b) / max(rel_vx, 0.0001);
				*ttcMode = 2;
			}
			else
			{
				ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
				*ttcMode = 3;
			}
		}
		else if (dx_b2b < (4.732f + Length)) // Fcu_Vdy_VehPar->VehParAdd.VehicleLength = 4.732f;
		{
			// ttc = 0.0f;
			//*ttcMode = 4;
			if (rel_vx >= FCU_ELK_OT_BS_MAX_DELTA_VEL_TRIGGER)
			{
				ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
				*ttcMode = 4;
			}
			else if (rel_vx >= FCU_ELK_OT_BS_MIN_DELTA_VEL_TRIGGER) // Ego is slower than object desired:-2kph,FCU_ELK_OT_BS_MIN_DELTA_VEL_TRIGGER = 0.56m/s;
			{
				ttc = 0;
				*ttcMode = 5;
			}
			else if (rel_vx > FCU_ELK_OT_BS_MAX_DELTA_VEL_NOT_TRIGGER) // Ego is faster than object during 2,5kph,FCU_ELK_OT_BS_MAX_DELTA_VEL_NOT_TRIGGER = 1.39m/s
			{

				ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
				*ttcMode = 6;
			}
			else
			{
				ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
				*ttcMode = 7;
			}
		}
		else
		{
			ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
			*ttcMode = 8;
		}
	}
	else
	{
		/*TODO : doing nothing*/
		*ttcMode = 9;
	}

	if ((ttc < 0.0f) || (ttc > FCU_CALC_OBSTACLE_TTC_TTC_MAX))
	{
		ttc = FCU_CALC_OBSTACLE_TTC_TTC_MAX;
		*ttcMode = 10;
	}
	return ttc;
}

/**
 * \functions Fcu_ELK_DataProcess_CalcObstacleLocationFlag
 *
 * \brief
 *
 * \parameters-in	location :  RLR_ElkOBJ1_Location,0x00-unknown,0x01-left,0x02-right,0x03-ego lane
 * 					light : BCM_TurnLightSwitchSts
 * 					ttc : clac from Fcu_DataProcess_CalcObstacleTTC
 * 					lat_dis : RLR_ElkOBJ1_Dy,
 * 					lat_spd : RLR_ElkOBJ1_RelVy
 *
 *
 * \parameters-out  flag :
 *
 * \return 	none
 *
 * \comments
 *
 */
Fcu_Static FUNC(uint8, RTE_CODE) Fcu_ELK_DataProcess_CalcObstacleLocationFlag(uint8 location, uint8 light, float32 ttc, float32 lat_dis, float32 lat_spd, float32 obj_width)
{
	uint8 flag = 0x00;
	float32 Dy;

	if (((((0x01 /*Left actived*/ == light) && (0x01 /*Left lane*/ == location)) || ((0x02 /*right actived*/ == light) && (0x02 /*right lane*/ == location))) && (ttc < FCU_CALC_OBSTACLE_LOCATION_FLAG_TTC_THRESHOLD1)) || ((((0x01 /*Left actived*/ != light) && (0x01 /*Left lane*/ == location)) || ((0x02 /*Right actived*/ != light) && (0x02 /*right lane*/ == location))) && (ttc < FCU_CALC_OBSTACLE_LOCATION_FLAG_TTC_THRESHOLD2)))
	{

		Dy = max(0, FD_FABS(lat_dis) - (obj_width / 2 + VDY_VEHICLEWIDTH / 2)); // VDY_VEHICLEWIDTH ==  1.928f Wheel outer edge distance

		// if( Dy < FCU_CALC_OBSTACLE_LOCATION_FLAG_LATERAL_DISTANCE)
		if (Dy < FCU_ELK_OT_LATERAL_B2B_DISTANCE_THRESHOLD)
		{
			if ((0x01 /*Left lane*/ == location) || (0x02 /*right lane*/ == location))
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}
	else
	{
		/*TODO : doing nothing*/
	}

	return flag;
}
