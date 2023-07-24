/*
 * Sdc_Chassis_Type.h
 *
 *  Created on: May 16, 2023
 *      Author: uif69946
 */

#ifndef _SDC_CHASSIS_TYPE_H_
#define _SDC_CHASSIS_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/
/*Chassis data header*/
typedef struct
{
	uint32 CanId;
	uint8 dlc;
	uint8 unused[3u];			/* used to do alignment */
}s_Sdc_Chassis_MsgHeader_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_MsgHeader_Data_t data;
}u_Sdc_Chassis_MsgHeader_t;

/*Chassis data of Veh,CAN ID is 0x100*/
typedef struct
{
	uint64 VehicleSpeedValid : 1u;
	uint64 VehicleSpeed : 15u;
	uint64 Reserved_1 : 32u;
	uint64 Reserved_2 : 16u;
}s_Sdc_Chassis_VehSpd_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_VehSpd_Data_t data;
}u_Sdc_Chassis_VehSpd_t;

/*Chassis data of YawRate,CAN ID is 0x101*/
typedef struct
{
	uint64 YawRateValid : 1u;
	uint64 YawRate : 12u;
	uint64 Reserved_1 : 32u;
	uint64 Reserved_2 : 19u;
}s_Sdc_Chassis_YawRate_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_YawRate_Data_t data;
}u_Sdc_Chassis_YawRate_t;

/*Chassis data of WheelAngle,CAN ID is 0x102*/
typedef struct
{
	uint64 WheelAngleValid : 1u;
	uint64 WheelAngle : 16u;
	uint64 Reserved_1 : 32u;
	uint64 Reserved_2 : 15u;
}s_Sdc_Chassis_WheelAngle_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_WheelAngle_Data_t data;
}u_Sdc_Chassis_WheelAngle_t;

/*Chassis data of GearPostion,CAN ID is 0x103*/
typedef struct
{
	uint64 GearPostion : 4u;
	uint64 Reserved_1 : 32u;
	uint64 Reserved_2 : 28u;
}s_Sdc_Chassis_GearPostion_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_GearPostion_Data_t data;
}u_Sdc_Chassis_GearPostion_t;

/*Chassis data of LightStatus,CAN ID is 0x104*/
typedef struct
{
	uint64 TurnSignal : 3u;
	uint64 Wiper : 2u;
	uint64 HighBeam : 2u;
	uint64 Reserved_1 : 32u;
	uint64 Reserved_2 : 25u;
}s_Sdc_Chassis_LightStatus_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_LightStatus_Data_t data;
}u_Sdc_Chassis_LightStatus_t;

/*Chassis data of LongAcc,CAN ID is 0x105*/
typedef struct
{
	uint64 LongAccValid : 1u;
	uint64 LongAcc : 15u;
	uint64 Reserved_1 : 32u;
	uint64 Reserved_2 : 16u;
}s_Sdc_Chassis_LongAcc_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Chassis_LongAcc_Data_t data;
}u_Sdc_Chassis_LongAcc_t;

/*Chassis Data,include the vehicle speed, yaw rate,Wheel angle,Gear position,Light status and Long Acc*/
typedef struct
{
	u_Sdc_Chassis_MsgHeader_t 	VehSpd_Header;
	u_Sdc_Chassis_VehSpd_t  	VehSpd;
	u_Sdc_Chassis_MsgHeader_t   YawRate_Header;
	u_Sdc_Chassis_YawRate_t  	YawRate;
	u_Sdc_Chassis_MsgHeader_t   WheelAngle_Header;
	u_Sdc_Chassis_WheelAngle_t  WheelAngle;
	u_Sdc_Chassis_MsgHeader_t   GearPostion_Header;
	u_Sdc_Chassis_GearPostion_t GearPostion;
	u_Sdc_Chassis_MsgHeader_t   LightStatus_Header;
	u_Sdc_Chassis_LightStatus_t LightStatus;
	u_Sdc_Chassis_MsgHeader_t	LongAcc_Header;
	u_Sdc_Chassis_LongAcc_t  	LongAcc;
}s_Sdc_ChassisData_t;

#endif /* _SDC_CHASSIS_TYPE_H_ */
