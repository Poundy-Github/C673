/*
 * Sdc_Vdy_type.h
 *
 *  Created on: May 16, 2023
 *      Author: uif69946
 */

#ifndef _SDC_VDY_TYPE_H_
#define _SDC_VDY_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/
/*TODO : Common data strcut of Sdc components*/

typedef enum
{
  e_UNKONWN		    = 0, // unknown.
  e_LEFTCROSSING	= 1, // lane change, left crossing.
  e_RIGHTCROSSING	= 2,  // lane change, right crossing.
  e_NOCHANGE        = 3 // no lane change.
}e_Sdc_LaneChange_t;

/*TODO : VdyDyn related data struct*/
typedef struct
{
	uint64 TimeStampe;
	uint8 eSignalStatus;
	uint8 flag_changing;
	uint16 reseve_1;
}s_Sdc_VdyDyn_SigHeaderData_t;

typedef union
{
	uint8 raw[12];
	s_Sdc_VdyDyn_SigHeaderData_t data;
}u_Sdc_VdyDyn_SigHeader_t;


typedef struct
{
	float32 Velocity;
	float32 varVelocity;
	float32 Accel;
	float32 varAccel;
	uint8 VelocityCorrectionQuality;
	uint8 VeloCorr_corrQual;
	uint16 reserve_0;
	float32 VeloCorr_corrFact;
	float32 VeloCorr_corrVar;
	float32 VeloCorr_corrVelo;
	float32 VeloCorr_corrVeloVar;
	float32 VeloCorr_minVelo;
	float32 VeloCorr_maxVelo;
	float32 AccelCorr_corrAccel;
	float32 AccelCorr_corrAccelVar;
}s_Sdc_VdyDyn_LongitudinalData_t;

typedef union
{
	uint8 raw[52];
	s_Sdc_VdyDyn_LongitudinalData_t data;
}u_Sdc_VdyDyn_Longitudinal_t;

typedef struct
{
	float32 YawRateVehDyn_YawRate;
	float32 YawRateVehDyn_YawRateRaw;
	float32 YawRateVehDyn_YawAngle;
	float32 YawRateVehDyn_Variance;
	float32 YawRateVehDyn_Quality;
	float32 OffCompStWheelAngle;
	float32 CurveVehDyn_Curve;
	float32 CurveVehDyn_C1;
	float32 CurveVehDyn_Gradient;
	float32 CurveVehDyn_varC0;
	float32 CurveVehDyn_varC1;
	float32 CurveVehDyn_CurveQuality;
	float32 CurveVehDyn_CrvError;
	uint32 CurveVehDyn_CrvConf	: 8;
	uint32 reserve_0			: 24;
	float32 CurveVehDyn_VarCurve;
	float32 DrvIntCurveVehDyn_Curve;
	float32 DrvIntCurveVehDyn_Variance;
	float32 DrvIntCurveVehDyn_Gradient;
	float32 LatAccelVehDyn_LatAccel;
	float32 LatAccelVehDyn_Variance;
	float32 SideSlipVehDyn_SideSlipAngle;
	float32 SideSlipVehDyn_Variance;
	float32 SelfSteerVehDyn_RoadBankAngle;
	float32 SelfSteerVehDyn_QuRoadBankAngle;
	float32 SelfSteerVehDyn_SelfSteerGradEst;
	float32 SelfSteerVehDyn_QuSelfSteerGradEst;
}s_Sdc_VdyDyn_LateralData_t;

typedef union
{
	uint8 raw[100];
	s_Sdc_VdyDyn_LateralData_t data;
}u_Sdc_VdyDyn_Lateral_t;

typedef struct
{
	uint8 MotState;
	uint8 bRollerTestBench;
	uint16 reserve_3;
	float32 Confidence;
}s_Sdc_VdyDyn_MotionStateData_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_VdyDyn_MotionStateData_t data;
}u_Sdc_VdyDyn_MotionState_t;

typedef struct
{
	float32 YawRateMaxJitter;
	uint32 bStandStill 	:	8;
	uint32 reserve_4	:	24;
}s_Sdc_VdyDyn_LegacyData_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_VdyDyn_LegacyData_t data;
}u_Sdc_VdyDyn_Legacy_t;

typedef struct
{
	uint8 State[12];
}s_Sdc_VdyDyn_State_t;

typedef struct
{
	u_Sdc_VdyDyn_SigHeader_t SigHeader;
	u_Sdc_VdyDyn_Longitudinal_t Longitudinal;
	u_Sdc_VdyDyn_Lateral_t Lateral;
	u_Sdc_VdyDyn_MotionState_t MotionState;
	u_Sdc_VdyDyn_Legacy_t Legacy;
	s_Sdc_VdyDyn_State_t State;
}s_Sdc_VdyDyn_Data_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_VdyDyn_SigHeader_t)+sizeof(u_Sdc_VdyDyn_Longitudinal_t)+sizeof(u_Sdc_VdyDyn_Lateral_t)+sizeof(u_Sdc_VdyDyn_MotionState_t)+sizeof(u_Sdc_VdyDyn_Legacy_t)+sizeof(s_Sdc_VdyDyn_State_t)];
	s_Sdc_VdyDyn_Data_t data;
}u_Sdc_VdyDyn_t;



#endif /* _SDC_VDY_TYPE_H_ */
