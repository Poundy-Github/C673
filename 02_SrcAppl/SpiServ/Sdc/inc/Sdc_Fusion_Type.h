/*
 * Sdc_Fusion_Type.h
 *
 *  Created on: May 16, 2023
 *      Author: uif69946
 */

#ifndef _SDC_FUSION_TYPE_H_
#define _SDC_FUSION_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/

/****************************CEM Struct Start****************************/
#define SDC_CEMOUT_OBJECT_NUMBER        (25u)
//16byte
//16字节
typedef struct 
{
    
    float32 fLifeTime;
    uint16  uiLifeCycles;
	uint8 eMaintenanceState;	
	uint8 sensorBitfield;//eSensorSource			
	uint8 eSplitMergeState  : 2;
	uint8 aShape01  :3;
	uint8 aShape02  :3;
	uint8 aShape03  :3;
	uint8 aShape04  :3;
	uint8 reserve_0 :2;

	uint8 uiID;	
	uint8 childID;
	uint8 eClassification  : 4;
	uint8 eDynamicProperty : 4;	

	uint8 uiClassConfidence;
	uint8 uiDynConfidence;
	uint8 uiProbabilityOfExistence;

	float32 	fYaw;
    float32 	fYawStd;

	uint8 eAssociatedLane[4];
}General_t;

typedef union
{
	uint8 	raw[24u];
	General_t 	data;
}union_General;

typedef struct 
{
	float fDistX;
	float fDistXStd;
	float fDistY;
	float fDistYStd;
	float fVrelX;
	float fVrelXStd;
	float fVrelY;
	float fVrelYStd;
	float fArelX;
	float fArelXStd;
	float fArelY;
	float fArelYStd;
	float fVabsX;
	float fVabsXStd;
	float fVabsY;
	float fVabsYStd;
	float fAabsX;
	float fAabsXStd;
	float fAabsY;
	float fAabsYStd;
}Kinematics_t; 

typedef union
{
	uint8 	raw[80u];
	Kinematics_t 	data;
}union_Kinematics;

typedef struct 
{
	float32 	 Coordinates_fPosX;
	float32 	 Coordinates_fPosY;
}ShapePoint_t;

typedef union
{
	uint8 		raw[32u];
	ShapePoint_t 	data[4];
}union_ShapePoints;


typedef struct
{
    union_General  			General; //20 byte
    union_Kinematics		kinematic;	//80 byte
    union_ShapePoints		shapePoints;   //48 byte
}Object_Reduced_t;



/*20220725 AEB Code Review Add*/
typedef uint8 CEM_ObjNumber_t;
typedef struct
{
    signed char iNumOfUsedObjects;
    signed char iSortedObjectList[25];
	uint16 sMeasurementCounter;
	uint8 reserve[4];
	uint64 lTimeStamp;
}SdcCemOut_Object_Reduced_Header_t;

typedef union
{
	uint8                               raw[40u];
	SdcCemOut_Object_Reduced_Header_t 	data;
}union_SdcCemOut_Object_Reduced_Header_t;


typedef struct 
{
	uint8					                SubFunc_id[4]; 
    union_SdcCemOut_Object_Reduced_Header_t header;
    Object_Reduced_t		                data[SDC_CEMOUT_OBJECT_NUMBER];	
}List_Object_Reduced_t;


#endif /* _SDC_FUSION_TYPE_H_ */
