/*
 * Sdc_Radar_Type.h
 *
 *  Created on: May 16, 2023
 *      Author: uif69946
 */

#ifndef _SDC_RADAR_TYPE_H_
#define _SDC_RADAR_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/**
 * @brief configuration the Radar object number
 * 
 */
#define SDC_RX_RADAR_OBJECT_NUMBER 	32


/*==================[type definitions]======================================*/

/*TODO : Radar related data struct*/
typedef struct
{
	uint8 Object_TrackId;
	uint8 Object_TrackAge;
	uint8 Object_ClassConf;
	uint8 Object_Class	:	4;
	uint8 Object_Valid	:	4;
	sint32 Object_Dx;
	float32 Object_Dx_Vnce;
	sint16 Object_Dy;
	uint16 Object_Height;
	float32 Object_Dy_Vnce;
	float32 Object_HeadingAngle;
	uint8 Object_ExistProb;
	uint8 Object_ObstacleProb;
	uint16 Object_Length;
	uint8 Object_Location		:	2;
	uint8 Object_Measured		:	2;
	uint8 Object_MotionStatus	:	4;
	uint8 Object_MotionStatusConf;
	uint16 Object_Width;
	float32 Object_RelAx;
	float32 Object_RelAy;
	float32 Object_RelVx;
	float32 Object_RelVx_std;
	float32 Object_RelVy;
	float32 Object_RelVy_std;

	/* Add dbc V3.4.1 */
	uint8 Object_FeaturePoint;
	uint8 Object_Reserve_0;
	uint16 Object_Reserve_1;
	float32 Object_Vx;
	float32 Object_Vy;
	float32 Object_Ax;
	float32 Object_Ay;
}s_Sdc_Radar_ObjectDataData_t;

typedef union
{
	uint8 raw[76];	//Add dbc V3.4.1 
	s_Sdc_Radar_ObjectDataData_t data;
}u_Sdc_Radar_ObjectData_t;

typedef struct
{
	float32 Object_FrameTime;
	uint8 Object_Counter;
	uint8 Radar_CalibrationStatus	:	2;
	uint8 Radar_WorkMode			:	2;
	uint8 reserved_0				:	4;
	uint8 Radar_FailureStatus		:	4;
	uint8 MisAlignment				:	4;
	uint8 Frame_Counter;
}s_Sdc_Radar_ObjectInformationA_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Radar_ObjectInformationA_Data_t data;
}u_Sdc_Radar_ObjectInformationA_t;

typedef struct
{
	uint64 time_stamp;//unit is ms
}s_Sdc_Radar_ObjectInformationB_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Radar_ObjectInformationB_Data_t data;
}u_Sdc_Radar_ObjectInformationB_t;

typedef struct
{
	u_Sdc_Radar_ObjectInformationA_t ObjectInfo_A;
	u_Sdc_Radar_ObjectInformationB_t ObjectInfo_B;
}s_Sdc_Radar_ObjectInformationData_t;

typedef struct
{
	uint8 RollingCounter_Object;
	uint8 radar_mode;
	uint8 KidRushoutFlag;	//Add dbc V3.4.1 
	uint8 reserved_0;
	uint32 CRCChecksum_Object;
}s_Sdc_Radar_ObjectCRCData_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Radar_ObjectCRCData_t data;
}u_Sdc_Radar_ObjectCRC_t;

typedef struct
{
	u_Sdc_Radar_ObjectData_t 		ObjectData[32];
	s_Sdc_Radar_ObjectInformationData_t ObjectInfomation;
	u_Sdc_Radar_ObjectCRC_t		ObjectCrc;
}s_Sdc_Radar_Object_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_Radar_ObjectData_t)*32 + sizeof(s_Sdc_Radar_ObjectInformationData_t) + sizeof(u_Sdc_Radar_ObjectCRC_t)];
	s_Sdc_Radar_Object_t data;
}u_Sdc_Radar_ObjectList_t;



#endif /* _SDC_RADAR_TYPE_H_ */
