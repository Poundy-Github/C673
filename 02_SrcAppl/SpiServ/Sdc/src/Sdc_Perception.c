/* ==================[Includes]=============================================== */
#include "Sdc_Perception.h"
#include "Sdc_Perception_Type.h"
#include "Rte_type.h"
#include "Com.h"
#include "Time.h"
#include "Sdc_Core_Type.h"
#include "SpiSync_Core.h"
#include "Sdc_Can_SignalGroup_Variable_Perception.h"
#include "Sdc_Diag.h"
#include "Rte_Sdc.h"
#include <math.h>

/*==================[external data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"




#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
static sint16 Sdc_Len_to_Left_Lane = 0;
static sint16 Sdc_Len_to_Right_Lane = 0;
static uint8 Sdc_HostLane_Left_flag = 0;
static uint8 Sdc_HostLane_Right_flag = 0;

static volatile e_Sdc_UpdatedFlag_t Sdc_Perception_UpdateFlag = e_Sdc_UpdatedFlag_None;
static s_Sdc_Perception_Data_t Sdc_J3_PerceptionData;
static t_CamLaneInputData Sdc_Perception_CamLaneInputData;
static AbdOutputData_t Sdc_Perception_AbdOutputData;
static s_Sdc_uSpeedLimitblacklistData_t Sdc_Speedlimitblacklist;
s_Time_RunCycleMeas_t debug_Perception_CycleTime;
#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfLineType(uint8 data);
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfMeasureType(uint8 data);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Sync2CAN(void);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Obstance2CAN(void);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Lane2CAN(void);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_TSRTFL2CAN(void);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_AEB2CAN(void);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Obstance2Rte(void);
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Lane2Rte(void);

#if DBG_FCUSDC_CORE_CHANGE_ENABLE == STD_ON
FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData(void);
#endif
#if DBG_FCUSDC_CORE_CHANGE_ENABLE == STD_OFF
	static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData(void);
#endif

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

/**
 * \functions Sdc_Perception_InitFunction
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Perception_InitFunction(void)
{
	memset(&Sdc_J3_PerceptionData, 0x00, sizeof(s_Sdc_Perception_Data_t));
	memset(&Sdc_Perception_CamLaneInputData, 0x00, sizeof(t_CamLaneInputData));
	memset(&Sdc_Perception_AbdOutputData, 0x00, sizeof(AbdOutputData_t));
	Sdc_Perception_UpdateFlag = e_Sdc_UpdatedFlag_None;
}

/**
 * \functions Sdc_Perception_DeInitFunction
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Perception_DeInitFunction(void)
{
	//TODO
}

/**
 * \functions Sdc_Perception_MainFunction
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Perception_MainFunction(void)
{
	Sdc_DataProcess_RxJ3PerceptionData();
}

/**
 * \functions Sdc_Perception_RcvPerceptionDataFromJ3
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Perception_RcvPerceptionDataFromJ3(const uint8 *data, uint16 length)
{
	Time_MeasRunCycleTimeMs(&debug_Perception_CycleTime);
	if (Sdc_Perception_UpdateFlag != e_Sdc_UpdatedFlag_Mapping) // Updated
	{
		memcpy(&Sdc_J3_PerceptionData, data, length);
		Sdc_Perception_UpdateFlag = e_Sdc_UpdatedFlag_Updated;
	}
}

FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_J3_PerceptionData_Read(void* perceptionData, uint16 length)	//called by Fcu_Hla.c
{
	memcpy(perceptionData, &Sdc_J3_PerceptionData, sizeof(s_Sdc_Perception_Data_t));
}
FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_Len_to_Left_Lane_Read(sint16 *wigth)	//called by Fcu_Lcf.c
{
	*wigth = Sdc_Len_to_Left_Lane;
}
FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_Len_to_Right_Lane_Read(sint16 *wigth)//called by Fcu_Lcf.c
{
    *wigth = Sdc_Len_to_Right_Lane;
}
FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_HostLane_Left_flag_Read(uint16 *flag)//called by Fcu_Lcf.c
{
    *flag = Sdc_HostLane_Left_flag;
}
FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_HostLane_Right_flag_Read(uint16 *flag)//called by Fcu_Lcf.c
{
    *flag = Sdc_HostLane_Right_flag;
}
/**
 * \functions Sdc_Perception_DataCovert_LaneMarkerType
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Perception_DataCovert_LaneMarkerType(uint8 index, uint8 *type)
{
	uint8 LaneTypeClass = 0x00;
	uint8 LaneMeasuringStatus = 0x00;

	if(0x00 == index)/*Left*/
	{
		LaneTypeClass = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
		LaneMeasuringStatus = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
		if((0x00 == LaneTypeClass) /*solid*/
				|| (0x03 == LaneTypeClass)/*double_dashed_solid*/
				|| (0x13 == LaneTypeClass)/*fishbone*/)
		{
			*type = 0x00;/*Solid*/
		}
		else if((0x1 == LaneTypeClass) /*dashed*/
				|| (0x2 == LaneTypeClass)/*double_dashed_dashed*/
				|| (0x4 == LaneTypeClass)/*double_solid_dashed*/)
		{
			*type = 0x01;/*dashed*/
		}
		else if((0xB == LaneTypeClass) /*road_edge*/
				|| (0xD == LaneTypeClass)/*curbstone*/)
		{
			*type = 0x0B;/*road_edge*/
		}
		else if((0x5 == LaneTypeClass) /*solid_solid*/)
		{
			*type = 0x05;/*double_ solid_ solid*/
		}
		else
		{
			*type = 0xF;/*unknow*/
		}

		if((0x01 == LaneMeasuringStatus)/*virtual_paral*/
				|| (0x3 == LaneMeasuringStatus))/*virtual*/
		{
			/*TODO : TBD,Shall check the Dbc*/
//			*type = ;/*Virtual margin*/
		}
		else
		{
			/*TODO : Doing nothing*/
		}
	}
	else if(0x01 == index)/*Right*/
	{
		LaneTypeClass = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
		LaneMeasuringStatus = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
		if((0x00 == LaneTypeClass) /*solid*/
				|| (0x03 == LaneTypeClass)/*double_dashed_solid*/
				|| (0x13 == LaneTypeClass)/*fishbone*/)
		{
			*type = 0x00;/*Solid*/
		}
		else if((0x1 == LaneTypeClass) /*dashed*/
				|| (0x2 == LaneTypeClass)/*double_dashed_dashed*/
				|| (0x4 == LaneTypeClass)/*double_solid_dashed*/)
		{
			*type = 0x01;/*dashed*/
		}
		else if((0xB == LaneTypeClass) /*road_edge*/
				|| (0xD == LaneTypeClass)/*curbstone*/)
		{
			*type = 0x0B;/*road_edge*/
		}
		else if((0x5 == LaneTypeClass) /*solid_solid*/)
		{
			*type = 0x05;/*double_ solid_ solid*/
		}
		else
		{
			*type = 0xF;/*unknow*/
		}

		if((0x01 == LaneMeasuringStatus)/*virtual_paral*/
				|| (0x3 == LaneMeasuringStatus))/*virtual*/
		{
			/*TODO : TBD,Shall check the Dbc*/
//			*type = ;/*Virtual margin*/
		}
		else
		{
			/*TODO : Doing nothing*/
		}
	}
	else
	{
		/*TODO : Doing nothing*/
	}
}

/**
 * \functions Sdc_Perception_DataCovert_LaneDistanceFus
 *
 * \brief
 *
 * \parameters-in
 *
 * \parameters-out
 *
 * \return 	none
 *
 * \comments
 */
FUNC(void, RTE_CODE) Sdc_Perception_DataCovert_LaneDistanceFus(uint8 index, float32 *dist)
{
	if(0x00 == index)/*Left*/
	{
		*dist = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	}
	else if(0x01 == index)/*Right*/
	{
		*dist = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	}
	else
	{
		/*TODO : Doing nothing*/
	}
}

/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData
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
#if DBG_FCUSDC_CORE_CHANGE_ENABLE == STD_ON
FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData(void)
#endif
#if DBG_FCUSDC_CORE_CHANGE_ENABLE == STD_OFF
	static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData(void)
#endif
{
	/*TODO : When the Perception Data updated,the Sdc shall start process of perception data*/
	if (e_Sdc_UpdatedFlag_Updated == Sdc_Perception_UpdateFlag)
	{
		Sdc_Perception_UpdateFlag = e_Sdc_UpdatedFlag_Mapping;
		/*TODO : Send Percpetion data to CAN*/
		Sdc_DataProcess_RxJ3PerceptionData_Sync2CAN();
		Sdc_DataProcess_RxJ3PerceptionData_Obstance2CAN();
		Sdc_DataProcess_RxJ3PerceptionData_Lane2CAN();
#if (SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE == STD_ON)
		Sdc_DataProcess_RxJ3PerceptionData_TSRTFL2CAN();
#endif
#if (SDC_PERCEPTION_AEB_FLAG_STRUCT_ENABLE == STD_ON)
		Sdc_DataProcess_RxJ3PerceptionData_AEB2CAN();
#endif

		/*TODO : Send Perception data to Rte,use for other components*/
		Sdc_DataProcess_RxJ3PerceptionData_Obstance2Rte();
		Sdc_DataProcess_RxJ3PerceptionData_Lane2Rte();
		Sdc_Perception_UpdateFlag = e_Sdc_UpdatedFlag_NotUpdated;
	}
	else if (e_Sdc_UpdatedFlag_None == Sdc_Perception_UpdateFlag)
	{
		Sdc_DataProcess_RxJ3PerceptionData_Sync2CAN(); // Updated the time stamp
	}
	else
	{
		/*TODO : doing nothing*/
	}

	/*TODO : Updated the Signal Group*/
	// SuspendAllInterrupts();
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x150_Group_336T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x151_Group_337T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x152_Group_338T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x153_Group_339T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x154_Group_340T);
	for (uint8 i = 0x00; i < SDC_TX_FC_OBJECT_NUMBER; i++)
	{
		/*TODO: Update once and send it in groups*/
		Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x160_Group_352T + i);
	}
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x180_Group_384T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x181_Group_385T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x190_Group_400T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x193_Group_403T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x195_Group_405T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x196_Group_406T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x197_Group_407T);
	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x198_Group_408T);
	// ResumeAllInterrupts();
}

/*==================[internal function definitions]=========================*/

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfLineType
 *
 * \brief	Convert the Line Type from SPI to Can
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfLineType(uint8 data)
{
	uint8 ret = 0x00;
 
	switch (data)
	{
		// case 0x0:ret = 0x14;break;//Unknown
		case 0x1:/*Solid*/ret = 0x00;break;
		// case 0x2:/*//Road Edge---20220620 delete for req*/ret = 0x0B;break;
		case 0x3:/*Dashed*/ret = 0x01;break;
		case 0x4:/*Double Lane(Left Dashed, Right Solid)*/ret = 0x03;break;
		case 0x5:/*Double Lane(Left Solid, Right Dashed)*/ret = 0x04;break;
		case 0x6:/*Double Lane(Double Dashed)*/ret = 0x02;break;
		case 0x7:/*Double Lane(Double Solid)*/ret = 0x05;break;
		// case 0x8:/*Barrier*/ret = 0x14;break;//Unknown
		case 0x9:/*Line Ramp*/ret = 0x17;break;
		case 0xA:/*ShadedArea*/ret = 0x15;break;//line_diversion_inside
		case 0xB:/*DecelerationSolidLine*/ret = 0x13;break;/*0x13=fishbone_solid  , 11=DecelerationSolidLine*/
		case 0xC:/*DecelerationDashedLine*/ret = 0x18;break;/*0x18=fishbone_dashed  ,12=DecelerationDashedLine*/
		default: ret = 0x14;break;//Unknown
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfLineColor
 *
 * \brief	Convert the Line Color from SPI to Can
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfLineColor(uint8 data)
{
	uint8 ret = 0x00;
 
	switch (data)
	{
		case 0x0:/*Unknown*/ret = 0x04;break;
		case 0x1:/*White*/ret = 0x01;break;
		case 0x2:/*Yellow_Orange_Red*/ret = 0x02;break;
		case 0x3:/*Blue_Green*/ret = 0x04;break;
		default: ret = 0x00;break;//Unknown
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfMeasureType
 *
 * \brief	Convert the Measure Type from SPI to Can
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfMeasureType(uint8 data)
{
	uint8 ret = 0x00;

	switch (data)
	{
		case 0x0:/*Unknown*/ret = 0x00;break;
		case 0x1:/*New*//*TODO : not mapping*/break;
		case 0x2:/*Measured_Parallel*/ret = 0x02;break;
		case 0x3:/*Predicted_Parallel*/ret = 0x01;break;
		case 0x4:/*Predicted_Unparallel*/ret = 0x04;break;
		case 0x5:/*Measured_Unparallel*/ret = 0x03;break;
		default: ret = 0x00;break;
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfObstacleClass
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfObstacleClass(uint8 data1 , uint8 data2)
{
	uint8 ret = 0x00;

	switch (data1)
	{
		case 0x0:/*INVALID*/ret = 0x00;break;//Not Detected	
		case 0x1:/*VEHICLE*/
			switch (data2)
			{
				case 0x1:ret = 0x08;break;//Bus									
				case 0x2:
				case 0x6:
				case 0x8:ret = 0x01;break;//Car
				case 0x3:
				case 0x5:
				case 0x7:ret = 0x02;break;//Trucks
				case 0x4:ret = 0x03;break;//cyclist/tricycle
				default: ret = 0x07;break;//uncertain
			}
		break;
		case 0x2:/*PEDESTRIAN*/ret = 0x04;break;//Pedestrain
		case 0x3:/*CYCLIST*/ret = 0x03;	break;//cyclist/tricycle
		case 0x4:/*BICYCLE*/ret = 0x05;	break;//bicycle/motorbike		
		default: ret = 0x00;break;//Not Detected
	}

	return ret;
}

//change by yf at 22.10.12
/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfPedOrientation
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	ret
 *
 * \comments
 *
 */
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfPedOrientation(uint8 data)
{
	uint8 ret = 0x00;

	switch(data)
	{
		case 0x00 :ret = 0x00u; break; //Unknown
		case 0x01 :ret = 0x05u; break; //back
		case 0x02 :ret = 0x01u; break; //front
		case 0x03 :ret = 0x03u; break; //left
		case 0x04 :ret = 0x02u; break; //left_front
		case 0x05 :ret = 0x04u; break; //left_back
		case 0x06 :ret = 0x07u; break; //right
		case 0x07 :ret = 0x08u; break; //right_front
		case 0x08 :ret = 0x06u; break; //right_back
		default:/*TODO : doing nothing*/break;
	}

	return ret;
}

//add by yf at 22.10.12
/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfPedOrientation2HeadingAngle
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	ret
 *
 * \comments
 *
 */
static FUNC(uint16, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfPedOrientation2HeadingAngle(uint8 data)
{
	uint16 ret = 0;

	switch(data)
	{
		case 0x00 :ret = 0x00; break; 
		case 0x01 :ret = 0x274; break; 
		case 0x02 :ret = 0x13A; break; 	 
		case 0x03 :ret = 0x1D7; break; 
		case 0x04 :ret = 0x189; break;
		case 0x05 :ret = 0x225; break; 			
		case 0x06 :ret = 0x9D; break; 
		case 0x07 :ret = 0xEB; break; 
		case 0x08 :ret = 0x4F; break; 
		default:/*TODO : doing nothing*/break;
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfCutInFlag
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfCutInFlag(uint8 data)
{
	uint8 ret = 0x00;

	switch(data)
	{
		case 0x00 :/*Not cut in*/ret = 0x00u; break; //Invalid
		case 0x01 :/*cut in*/ret = 0x01u; break; //Cut in
		case 0x02 :/*Close cut in*/ret = 0x02u; break; //Cut in fov
		default:ret = 0x00u;break;
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfMarkerType
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfMarkerType(uint8 data)
{
	uint8 ret = 0x00;

	switch (data)
	{
		case 0x00:/*Unknown*/ret = 5;break;
		case 0x01:/*Solid*/ret = 0;break;
		case 0x02:/*Road Edge*/ret = 11;break;
		case 0x03:/*Dashed*/ret = 1;break;
		case 0x04:/*Double Lane(Left Dashed, Right Solid)*/
		case 0x05:/*Double Lane(Left Solid, Right Dashed)*/ret = 0x00;break;
		case 0x06:/*Double Lane(Double Dashed)*/ret = 1;break;
		case 0x07:/*Double Lane(Double Solid)*/ret = 0x00;break;
		case 0x08:/*Barrier*/ret = 12;break;
		case 0x09:/*Line Ramp*/
		case 0x0A:/*ShadedArea*/
		case 0x0B:/*DecelerationSolidLine*/
		case 0x0C:/*DecelerationDashedLine*/
		case 0x0F:/*Invalid*/ret = 15;break;
		default: ret = 15;break;
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(uint8 data)
{
	uint8 ret = 0x00;

	switch (data)
	{
		case 0x00:/*Unknown*/ret = 0x00;break;
		case 0x01:/*white*/ret = 0x01;break;
		case 0x02:/*Yellow_orange red*/ret = 0x02;break;
		case 0x03:/*Blue Green*/ret = 0x04;break;
		default:/*Unknown*/ret = 0x00;break;
	}

	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfLaneQuality
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
static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(uint8 data)
{
	uint8 ret = 0x00;

	switch (data)
	{
		case 0x00:/*Unknown*/ret = 0x00;break;
		case 0x01:/*low*/ret = 33;break;
		case 0x02:/*high*/ret = 66;break;
		case 0x03:/*very high*/ret = 100;break;
		default: ret = 0x00;break;
	}
	return ret;
}

/**
 * \functions Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass
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
 *enum LineMarking {
  LineMarking_Unknown = 0; // 0 << 0
  LineMarking_SolidLine = 2; // 1 << 1
  LineMarking_DashedLine = 4; // 1 << 2
  LineMarking_ShortDashedLine = 8; // 1 << 3
  LineMarking_DoubleSolidLine = 16; // 1 << 4
  LineMarking_DoubleDashedLine = 32; // 1 << 5
  LineMarking_LeftSolidRightDashed = 64; // 1 << 6
  LineMarking_RightSolidLeftDashed = 128; // 1 << 7
  LineMarking_ShadedArea = 256;    // 1 << 8, diversion line
  LineMarking_LaneVirtualMarking = 512; // 1 << 9, virtual line of lane center
  LineMarking_IntersectionVirualMarking = 1024; // 1 << 10,virtual line at intersection
  LineMarking_CurbVirtualMarking = 2048;  // 1 << 11, virtual line of road edge
  LineMarking_UnclosedRoad = 4096;  // 1 << 12, line for non-closure road
  LineMarking_RoadVirtualLine = 8192;  // 1 << 13, virtual line of road
}
 */

/*! Req by LCF
 *	Decribes the type of a lane marker (e.g. continuous, dashed, road edge,). \n
 *	ABD_MT_NO_LINE= 0 \n
 *	ABD_MT_PAINTED_CONTINUOUS = 1 \n
 *	ABD_MT_PAINTED_DASHED = 2 \n
 *	ABD_MT_PAINTED_DECORATIVE = 3 \n
 *	ABD_MT_DOTTED_CONTINUOUS = 4 \n
 *	ABD_MT_DOTTED_DASHED = 5  \n
 *	ABD_MT_ELEVATED_CONTINUOUS=6 \n
 *	ABD_MT_ELEVATED_DISCRETE = 7 \n
 *	ABD_MT_CURBSTONE =8 \n
 *	ABD_MT_ROADEDGE =9 \n
 *	ABD_MT_UNKNOWN = 100
 */

static FUNC(uint8, RTE_CODE) Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(uint8 index,uint8 data)
{
	uint8 ret = 0x00;

	switch (data)
	{
		case 0x00:/*Unknown*/ret = 100;break;
		case 0x01:/*Solid*/ret = 1;break;
		case 0x02:/*Road Edge*/ret = 9;break;
		case 0x03:/*Dashed*/ret = 2;break;
		case 0x04:/*Double Lane(Left Dashed, Right Solid)*/		
			/*
			* notes:
			* when index = 1,2,8, the asLaneBoundary[i] = 1
			* when index = 3,4,9, the asLaneBoundary[i] = 2
			* */
			switch (index)
			{
				case 0x01:
				case 0x02:
				case 0x08:/*Unknown*/ret = 0x01;break;
				case 0x03:
				case 0x04:
				case 0x09:/*low*/ret = 0x02;break;
				default: ret = 0x01;break;// Luhui 2022.08.27,  0x00 == index || 0x05 == index roadedge will be solid
			}
			break;
		case 0x5:/*Double Lane(Left Solid, Right Dashed)*/
			/*
			* notes:
			* when index = 3,4,9, the asLaneBoundary[i] = 1
			* when index = 1,2,8, the asLaneBoundary[i] = 2
			* */
			switch (index)
			{
				case 0x01:
				case 0x02:
				case 0x08:/*Unknown*/ret = 0x02;break;
				case 0x03:
				case 0x04:
				case 0x09:/*low*/ret = 0x01;break;
				default: ret = 0x01;break;// Luhui 2022.08.27,  0x00 == index || 0x05 == index roadedge will be solid
			}
			break;
		case 0x06:/*Double Lane(Double Dashed)*/ret = 2;break;
		case 0x07:/*Double Lane(Double Solid)*/ret = 1;break;
		case 0x08:/*Barrier*/ret = 6;break;
		case 0x09:/*Line Ramp*/
		case 0x0A:/*ShadedArea*/
		case 0x0B:/*DecelerationSolidLine*/
		case 0x0C:/*DecelerationDashedLine*/ret = 100;break;
		case 0x0F:/*Invalid*/ret = 0;break;
		default: ret = 100;break;
	}


	return ret;
}

/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_Sync2CAN
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
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Sync2CAN(void)
{
	uint8 can_tsyn_state_TiBas = 0x00;
	uint8 can_tsyn_state_TiLeap = 0x00;
	uint8 can_tsyn_state_TiOut = 0x00;
	uint32 signal_value_u32 = 0x00;
	uint8 temp_Debug_Delat_us = 0x00;
    uint8 global_time_status = 0x00;
    uint64 timestamp_offset = 0x00;
    uint64 timestamp = 0x00;

	/*TODO : get the globa time for StbM*/
    Time_GetGlobalTimeStatus(&global_time_status);

	/*TODO : Frame Id*/
//	Com_SendSignal(ComConf_ComGroupSignal_FC_FrameID_400T,&Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex); //need to confirm ComConf_ComSignal_SGFC_FrameID_400T

	/*TODO : Updated the status of TiBas*/
	if( (global_time_status & 0x8) == 0x8)
	{
		can_tsyn_state_TiBas = 0x1u;
	}
	else
	{
		can_tsyn_state_TiBas = 0x0u;
	}
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LineTiBas_340T, &can_tsyn_state_TiBas);

	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_ObjTiBas_403T, &can_tsyn_state_TiBas);
	//Com_SendSignal(ComConf_ComSignal_SGFC_RoadSignTiBas_408T, &can_tsyn_state_TiBas);
	//Com_SendSignal(ComConf_ComSignal_SGFC_SignBoardTiBas_407T, &can_tsyn_state_TiBas);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TFLTiBas_406T, &can_tsyn_state_TiBas);

	/*TODO : Updated the status of TiLeap*/
	if( ((global_time_status & 0x10u) == 0x10u) || ( (global_time_status & 0x20) == 0x20u) )//TIMELEAP_FUTURE or TIMELEAP_PAST
	{
		can_tsyn_state_TiLeap = 0x1u;
	}
	else
	{
		can_tsyn_state_TiLeap = 0x0u;
	}
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_ObjTiLeap_403T, &can_tsyn_state_TiLeap);
	//Com_SendSignal(ComConf_ComSignal_SGFC_RoadSignTiLeap_408T, &can_tsyn_state_TiLeap);
	//Com_SendSignal(ComConf_ComSignal_SGFC_SignBoardTiLeap_407T, &can_tsyn_state_TiLeap);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TFLTiLeap_406T, &can_tsyn_state_TiLeap);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LineTiLeap_340T, &can_tsyn_state_TiLeap);

	/*TODO : Updated the status of TiOut*/
	if((global_time_status & 0x1u)== 0x1U)
	{
		can_tsyn_state_TiOut =0x1u;
	}
	else
	{
		can_tsyn_state_TiOut = 0x0u;
	}
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LineTiOut_340T, &can_tsyn_state_TiOut);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_ObjTiOut_403T, &can_tsyn_state_TiOut);
	//Com_SendSignal(ComConf_ComSignal_SGFC_RoadSignTiOut_408T, &can_tsyn_state_TiOut);
	//Com_SendSignal(ComConf_ComSignal_SGFC_SignBoardTiOut_407T, &can_tsyn_state_TiOut);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TFLTiOut_406T, &can_tsyn_state_TiOut);



	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_ObjMCUTiStamp_403T, &temp_Debug_Delat_us);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LineMCUTiStamp_340T, &temp_Debug_Delat_us);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TFLMCUTiStamp_406T, &temp_Debug_Delat_us);
	//Com_SendSignal(ComConf_ComSignal_SGFC_SignBoardMCUTiStamp_407T, &temp_Debug_Delat_us);
	//Com_SendSignal(ComConf_ComSignal_SGFC_RoadSignMCUTiStamp_406T, &temp_Debug_Delat_us);

    SpiSync_Core_GetTimestampOffset(&timestamp_offset);
	/*TODO : Updated the time stamp*/
	if( can_tsyn_state_TiBas == 0x0)//Shall check the J3 sync status
	{
        Time_GetTimeStampMs(&timestamp);
		signal_value_u32 = (uint32)(timestamp * 10);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TFLTiStamp_406T, &signal_value_u32);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LineTiStamp_340T, &signal_value_u32);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_ObjTiStamp_403T, &signal_value_u32);
		//Com_SendSignal(ComConf_ComSignal_SGFC_SignBoardTiStamp_407T, &signal_value_u32);
		//Com_SendSignal(ComConf_ComSignal_SGFC_RoadSignTiStamp_408T, &signal_value_u32);
	}
	else if(Sdc_J3_PerceptionData.Sync.data.SyncMsg1.ImageTimestamp != 0x0)
	{
		signal_value_u32 = (uint32)((uint64)Sdc_J3_PerceptionData.Sync.data.SyncMsg1.ImageTimestamp * 10 - timestamp_offset / 100000);//0.1ms
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TFLTiStamp_406T, &signal_value_u32);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LineTiStamp_340T, &signal_value_u32);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_ObjTiStamp_403T, &signal_value_u32);
		//Com_SendSignal(ComConf_ComSignal_SGFC_SignBoardTiStamp_407T, &signal_value_u32);
		//Com_SendSignal(ComConf_ComSignal_SGFC_RoadSignTiStamp_408T, &signal_value_u32);
#if (DBG_MCU_SW_DV_TEST_ENABLE !=STD_ON)
	}
	else
	{
		/*TODO : doing nothing*/
	}
#endif

}

/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_Obstance2CAN
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
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Obstance2CAN(void)
{
	uint8 signal_value_u8 = 0x0;
	uint16 signal_value_u16 = 0x00;
	uint8 i = 0x00;


	/*TODO : Brake Light Info*/
	//FC_obj1_Brakelight_Info
	for(i = 0x00 ; i < SDC_TX_FC_OBJECT_NUMBER; i++)
	{

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Brakelight_Info[i])
			{
				signal_value_u8 = Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataC.data.ObstacleBrakeLights;
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Brakelight_Info[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Center Angle*/
		//FC_Obj1_CenterAngle

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_CenterAngle[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataC.data.ObstacleCenterAngle * 3.14159 / 180.0 + 1.57) * 100);//
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_CenterAngle[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Corner Pointer X*/
		//FC_Obj1_CornerPoint_x

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_CornerPoint_x[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataL.data.ObjCornerPointPoxX) * 100);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_CornerPoint_x[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Corner Pointer Y*/
		//FC_Obj1_CornerPoint_y

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_CornerPoint_y[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataM.data.ObjCornerPointPoxY + 80) * 100);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_CornerPoint_y[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
			

		/*TODO : Cut In Type*/
		/*TODO : this signal mapping to ObstacleClass,shall be confirmed*/
		//FC_Obj1_CutInType

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_CutInType[i])
			{
				/*TODO : Not mapping*/
				signal_value_u8 = 0x00;
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_CutInType[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Dist in Lane*/
		//FC_Obj1_DistInLane

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_DistInLane[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataL.data.CutInDistance + 10) * 100);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_DistInLane[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Object Dx*/
		//FC_Obj1_Dx
			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Dx[i])
			{
				if(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataD.data.ObstaclePosX >= 204.7)
				{
					signal_value_u16 = 0xfff;
				}
				else if(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataD.data.ObstaclePosX <= 0)
				{
					signal_value_u16 = 0x0;
				}
				else
				{
					signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataD.data.ObstaclePosX * 20);
				}
				
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Dx[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Object Dx Vnce*/
		//FC_Obj1_Dx_Vnce

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Dx_Vnce[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataG.data.ObstaclePosXSTD * 20 * Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataG.data.ObstaclePosXSTD );
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Dx_Vnce[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Object Dy*/
		//FC_Obj1_Dy

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Dy[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataE.data.ObstaclePosY + 80) * 100);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Dy[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Object Dy Vnce*/
		//FC_Obj1_Dy_Vnce

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Dy_Vnce[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataG.data.ObstaclePosYSTD) * 50 *  (Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataG.data.ObstaclePosYSTD) );
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Dy_Vnce[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Object Exist Prob*/
		//FC_Obj1_ExistProb

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_ExistProb[i])
			{
				signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleConfidence / 2);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_ExistProb[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

			/*TODO : Object Vehicle Direction*/
		//FC_Obj1_VehicleDir

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_VehicleDir[i])
			{
				if(13 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleMotionCategory)
				{
					signal_value_u8 = 0x2;
				}
				else
				{
					signal_value_u8 = 0x0;					
				}				
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_VehicleDir[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Heading Angle*/
		//FC_Obj1_HeadingAngle

			// if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_HeadingAngle[i])
			// {
				if( (0x1 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass)
					||(0x3 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass) ) //Fixed issue which Vehicle and CycleList heading angle = yaw
				{
					signal_value_u16 =  (uint16)((((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataI.data.ObstacleAngle * 3.14159) / 180.0) + 3.14) * 100);
				}
				else if(0x2 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass)
				{
					signal_value_u16 = Sdc_DataProcess_PerceptionDataConvetOfPedOrientation2HeadingAngle(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataB.data.PedOrientation);
				}
				else
				{
					/*TODO : doing nothing*/
				}
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_HeadingAngle[i], &signal_value_u16);
			// }
			// else
			// {
			// 	/*TODO : doing nothing*/
			// }
		

		/*TODO : HeadOrientation*/
		//FC_Obj1_HeadOrientation

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_HeadOrientation[i])
			{
				signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfPedOrientation(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataB.data.PedOrientation);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_HeadOrientation[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Object Height*/
		//FC_Obj1_Height

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Height[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataC.data.ObstacleHeight );
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Height[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Img 2D Box Left Top*/
		//FC_Obj1_Img2dBox_LeftTop_U

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_LeftTop_U[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataP.data.Img2dBox_Left);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_LeftTop_U[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		


		/*TODO : Img 2D Box Left Top V*/
		//FC_Obj1_Img2dBox_LeftTop_V

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_LeftTop_V[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataP.data.Img2dBox_Top);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_LeftTop_V[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Img 2D Box Right Down U*/
		//FC_Obj1_Img2dBox_RightDown_U

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_RightDown_U[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataP.data.Img2dBox_Right);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_RightDown_U[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Img2D Box Right Down V*/
		//FC_Obj1_Img2dBox_RightDown_V

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_RightDown_V[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataP.data.Img2dBox_Button);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Img2dBox_RightDown_V[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Lane Assignment*/
		//FC_Obj1_LaneAssignment

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_LaneAssignment[i])
			{
				signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataB.data.ObstacleLaneAssignment);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_LaneAssignment[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object Length*/
		//FC_Obj1_Length

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Length[i])
			{
				signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataB.data.ObstacleLength /5);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Length[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Motion Type*/
		//FC_Obj1_MotionType

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_MotionType[i])
			{
				if(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleMotionStatus >= 1)
				{
					signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleMotionStatus - 1);
				}
				else
				{
					signal_value_u8 = 0x00;
				}
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_MotionType[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object Cut in Flag*/
		//FC_Obj1_objCutInFlag

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_objCutInFlag[i])
			{
				signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfCutInFlag(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataN.data.CutInFlag);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_objCutInFlag[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object Cut in Lane*/
		//FC_Obj1_objCutInLane

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_objCutInLane[i])
			{
				signal_value_u8 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataN.data.CutInLane);
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_objCutInLane[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

			/*TODO : Object Left Door*/
		//FC_Obj1LeDoorSts

			if(0x00 != Sdc_ConsigIdList_Tx_FC_ObjxLeDoorSts[i])
			{
				signal_value_u8 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataN.data.LeftDoor);
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_ObjxLeDoorSts[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Object Right Door*/
		//FC_Obj1RiDoorSts

			if(0x00 != Sdc_ConsigIdList_Tx_FC_ObjxRiDoorSts[i])
			{
				signal_value_u8 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataN.data.RightDoor);
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_ObjxRiDoorSts[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Object Trunk Door*/
		//FC_Obj1ReDoorSts

			if(0x00 != Sdc_ConsigIdList_Tx_FC_ObjxReDoorSts[i])
			{
				signal_value_u8 = (uint16)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataN.data.TrunkDoor);
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_ObjxReDoorSts[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

		/*TODO : Object RelAx*/
		//FC_Obj1_RelAx

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_RelAx[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataO.data.ObstacleAccRefX + 16) * 10);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_RelAx[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object RelAy*/
		//FC_Obj1_RelAy

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_RelAy[i])
			{
				signal_value_u8 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataO.data.ObstacleAccRefY + 12) * 10);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_RelAy[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object RelVx*/
		//FC_Obj1_RelVx

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_RelVx[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataE.data.ObstacleVelX + 154) * 10);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_RelVx[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object RelVy*/
		//FC_Obj1_RelVy

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_RelVy[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataF.data.ObstacleVelY + 50) * 10);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_RelVy[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Taillight Info*/
		//FC_obj1_Taillight_Info

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Taillight_Info[i])
			{
				/*TODO : Not Mapping*/
				signal_value_u8 = 0x00;
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Taillight_Info[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object Track Age*/
		//FC_Obj1_Track_Age

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Track_Age[i])
			{
				signal_value_u16 = Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleAge;
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Track_Age[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Object Track ID*/
		//FC_Obj1_Track_ID

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Track_ID[i])
			{
				signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleID);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Track_ID[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Turn Light*/
		//FC_Obj1_TurnLight,the Dbc not definition the signal value description

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TurnLight[i])
			{
				if(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataC.data.ObstacleBlinkerInfo >= 1)
				{
					signal_value_u8 = Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataC.data.ObstacleBlinkerInfo - 1;
				}
				else
				{
					signal_value_u8 = 0x00;
				}
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TurnLight[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
	

		/*TODO : Object Type*/
		//FC_Obj1_Type

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Type[i])
			{
				signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfObstacleClass(Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass,Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.VehicleSubType);
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Type[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
	

		/*TODO : Object Type Prob*/
		//FC_Obj1_TypeProb

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TypeProb[i])
			{
				if((0x01 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass)
				 ||(0x02 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass)
				 ||(0x03 == Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleClass))
				{
					signal_value_u8 = 50; //MFC5J3CN15-473 FC_Obj1_TypeProb factor == 2, so signal_value_u8/2
				}
				else
				{
					signal_value_u8 = 0x00;
				}
				Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TypeProb[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}
	

		/*TODO : Object Valid*/
		//FC_Obj1_valid
#if 0
			if(FS_FSState() == SDC_FS_NORMAL_COMMINUCATION)
			{
				if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_valid[i])
				{
					signal_value_u8 = (Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleValid >= 1)?0:1;
					(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_valid[i], &signal_value_u8);
				}
				else
				{
					/*TODO : doing nothing*/
				}
			}
			else
			{
				signal_value_u8 = 0x00; //Initial Value 
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_valid[i], &signal_value_u8);
			}
#endif 
			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_valid[i])
			{
				signal_value_u8 = (Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleValid >= 1)?0:1;
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_valid[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Object Vx Vnce*/
		//FC_Obj1_Vx_Vnce

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Vx_Vnce[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataH.data.ObstacleVelXSTD 
											* Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataH.data.ObstacleVelXSTD + 128) * 16);// / 0.0625
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Vx_Vnce[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}


		/*TODO : Object Vy Vnce*/
		//FC_Obj1_Vy_Vnce

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Vy_Vnce[i])
			{
				signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataH.data.ObstacleVelYSTD
											* Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataH.data.ObstacleVelYSTD + 64) * 8);// /0.125
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Vy_Vnce[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
	

		/*TODO : Object Width*/
		//FC_Obj1_Width

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_Width[i])
			{
				signal_value_u16 = Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataB.data.ObstacleWidth  ;
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_Width[i], &signal_value_u16);
			}
			else
			{
				/*TODO : doing nothing*/
			}
		

		/*TODO : Pos type*/
		//FC_Obj1WSInfoPosType

			if(0x00 != Sdc_ConsigIdList_Tx_FC_Obj1WSInfoPosType[i])
			{
				signal_value_u8 = (Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataD.data.ObstaclePositionType > 0x09) ? 0x00:Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataD.data.ObstaclePositionType;
				(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Obj1WSInfoPosType[i], &signal_value_u8);
			}
			else
			{
				/*TODO : doing nothing*/
			}

            /*FC_Obj1_valid*/
            if(0x00 != Sdc_ConsigIdList_Tx_FC_ObstacleData[i])
            {
                signal_value_u8 = (Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataA.data.ObstacleValid > 0x00) ? 0u:1u;
                (void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_ObstacleData[i], &signal_value_u8);
            }
            else
            {
                /*TODO : doing nothing*/
            }

            
				
	}

     /*FC_CIPVFlag*/
    signal_value_u8 = 0u;
    for(i=0;i<SDC_TX_FC_OBJECT_NUMBER;i++)
    {
        signal_value_u8 |= (Sdc_J3_PerceptionData.Obstance.ObstacleData[i].data.ObstacleDataC.data.CIPVFlag==1u)?1u:0u;
    }
    (void)Com_UpdateShadowSignal( ComConf_ComGroupSignal_FC_CIPVFlag_400T, &signal_value_u8);

	/*TODO : Head Information*/

	//FC_CIPV_ID
	signal_value_u8 = Sdc_J3_PerceptionData.Obstance.ObstacleHeader1.data.ID_CIPV;
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_CIPV_ID_400T, &signal_value_u8);

	/*TODO : Frame Id*/
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_FrameID_400T,&Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex);

	//FC_SenceMode
	switch(Sdc_J3_PerceptionData.Lane.Road_Information.data.RoadType)
	{
		case 0: signal_value_u8=0u; break; /**/
		case 1:
		case 2:
		case 3: 
		case 4:
		case 5: signal_value_u8=2u; break; /**/
		case 6: signal_value_u8=1u; break; /**/
		default:
		{
			signal_value_u8 = 0u;
			break;
		}
	}
//	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_SenceMode_400T, &signal_value_u8);

}

/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_Lane2CAN
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

static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Lane2CAN(void)
{
	uint8 signal_value_u8;
	uint16 signal_value_u16;

	/*LaneTypeClass*/	//OK
	//FC_Line_1_Type
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_Type_336T, &signal_value_u8);
	//FC_Line_2_Type
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_Type_336T, &signal_value_u8);
	//FC_Line_3_Type
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_Type_337T, &signal_value_u8);
	//FC_Line_4_Type
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_Type_337T, &signal_value_u8);

	//FC_Line_5_Type  
    if(1u == Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.RoadEdgeTypeClass)
    {
	    signal_value_u8 = 0xDu;
    }
	else if(2u == Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.RoadEdgeTypeClass)
	{
		signal_value_u8 = 0xBu;
	}
    else
    {
        signal_value_u8 = 0x14u;/*Unknown*/
    }
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_Type_338T, &signal_value_u8);
	//FC_Line_6_Type
    if(1u == Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.RoadEdgeTypeClass)
    {
	    signal_value_u8 = 0xDu;
    }
	else if(2u == Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.RoadEdgeTypeClass)
    {
	    signal_value_u8 = 0xBu;
    }
    else
    {
        signal_value_u8 = 0x14u;/*Unknown*/
    }
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_Type_338T, &signal_value_u8);

    #if 0
	//Matching ramp
    //FC_Line_7_Type
    if(1u == Sdc_J3_PerceptionData.Lane.Left_Cone_Road_Edge.data.ConeRoadEdge_A.data.LaneTypeClass)
    {
        signal_value_u8 = 0xFu;
    }
    else
    {
        signal_value_u8 = 0x14u;/*Unknown*/
    }
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_Type_339T, &signal_value_u8);

    //FC_Line_8_Type
    if(1u == Sdc_J3_PerceptionData.Lane.Left_Cone_Road_Edge.data.ConeRoadEdge_A.data.LaneTypeClass)
    {
        signal_value_u8 = 0xFu;
    }
    else
    {
        signal_value_u8 = 0x14u;/*Unknown*/
    }
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_Type_339T, &signal_value_u8);
    #endif

    //Match the diversion line bifurcation
	//FC_Line_7_Type
    signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneTypeClass);
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_Type_339T, &signal_value_u8);
    //FC_Line_8_Type
    signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineType(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneTypeClass);
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_Type_339T, &signal_value_u8);

	/*Line TypeConfidence*/ 	//OK
	//FC_Line_1_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_TypeConfidence_336T, &signal_value_u8);
	//FC_Line_2_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_TypeConfidence_336T, &signal_value_u8);
	//FC_Line_3_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_TypeConfidence_337T, &signal_value_u8);
	//FC_Line_4_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_TypeConfidence_337T, &signal_value_u8);

    //FC_Line_5_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_TypeConfidence_338T, &signal_value_u8);
	//FC_Line_6_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_TypeConfidence_338T, &signal_value_u8);
	//FC_Line_7_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_TypeConfidence_339T, &signal_value_u8);
	//FC_Line_8_TypeConfidence
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_TypeConfidence_339T, &signal_value_u8);


	/*Line color*/	//OK
	//FC_Line_1_color
	if(0 != Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTrackID)	
		signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineColor(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneMarkColor);
	else
		signal_value_u8 = 0;//Not Detected
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_color_336T, &signal_value_u8);
	//FC_Line_2_color
	if(0 != Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTrackID)
		signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineColor(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneMarkColor);
	else
		signal_value_u8 = 0;//Not Detected
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_color_336T, &signal_value_u8);
	//FC_Line_3_color
	if(0 != Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneTrackID)
		signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineColor(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneMarkColor);
	else
		signal_value_u8 = 0;//Not Detected
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_color_337T, &signal_value_u8);
	//FC_Line_4_color
	if(0 != Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneTrackID)
		signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineColor(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneMarkColor);
	else
		signal_value_u8 = 0;//Not Detected
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_color_337T, &signal_value_u8);
    //FC_Line_5_color
	signal_value_u8 = 0;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_color_338T, &signal_value_u8);
	//FC_Line_6_color
	signal_value_u8 = 0;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_color_338T, &signal_value_u8);
	//FC_Line_7_color
	if(0 != Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneTrackID)
		signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineColor(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneMarkColor);
	else
		signal_value_u8 = 0;//Not Detected
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_color_339T, &signal_value_u8);
	//FC_Line_8_color
	if(0 != Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneTrackID)
		signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfLineColor(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneMarkColor);
	else
		signal_value_u8 = 0;//Not Detected
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_color_339T, &signal_value_u8);

	/*Line Id*/		//OK
	//FC_Line_1_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_Id_336T, &signal_value_u8);
	//FC_Line_2_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_Id_336T, &signal_value_u8);
	//FC_Line_3_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_Id_337T, &signal_value_u8);
	//FC_Line_4_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_Id_337T, &signal_value_u8);
	//FC_Line_5_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_Id_338T, &signal_value_u8);
	//FC_Line_6_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_Id_338T, &signal_value_u8);
	//FC_Line_7_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_Id_339T, &signal_value_u8);
	//FC_Line_8_Id
	signal_value_u8 = Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneTrackID % 255 + 1;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_Id_339T, &signal_value_u8);


	/*Line Width*/	//OK
	//FC_Line_1_Width
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_Width_336T, &Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneWidthMarking);
	//FC_Line_2_Width
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_Width_336T, &Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneWidthMarking);
	//FC_Line_3_Width
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_Width_337T, &Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneWidthMarking);
	//FC_Line_4_Width
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_Width_337T, &Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneWidthMarking);
    //FC_Line_5_Width
    signal_value_u8 = 0;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_Width_338T, &signal_value_u8);
	//FC_Line_6_Width
    signal_value_u8 = 0;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_Width_338T, &signal_value_u8);
	//FC_Line_7_Width
    signal_value_u8 = 0;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_Width_339T, &Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneWidthMarking);
	//FC_Line_8_Width
    signal_value_u8 = 0;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_Width_339T, &Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneWidthMarking);

	/*Line dx start pointer*/	//OK
	//FC_Line_1_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_dx_Start_336T, &signal_value_u16);
	//FC_Line_2_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_dx_Start_336T, &signal_value_u16);
	//FC_Line_3_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_dx_Start_337T, &signal_value_u16);
	//FC_Line_4_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_dx_Start_337T, &signal_value_u16);
	//FC_Line_5_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.RoadEdgeViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_dx_Start_338T, &signal_value_u16);
	//FC_Line_6_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.RoadEdgeViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_dx_Start_338T, &signal_value_u16);
	//FC_Line_7_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneB.data.LaneViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_dx_Start_339T, &signal_value_u16);
	//FC_Line_8_dx_Start
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneB.data.LaneViewRangeStart * 0.4);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_dx_Start_339T, &signal_value_u16);



	/*Line dx start std*/
	//FC_Line_1_dx_Start_std
	//The signal not mapping,because not source to mapping

	/*Line dx end pointer*/  //OK
	//FC_Line_1_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_dx_End_336T, &signal_value_u16);
	//FC_Line_2_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_dx_End_336T, &signal_value_u16);
	//FC_Line_3_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_dx_End_337T, &signal_value_u16);
	//FC_Line_4_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_dx_End_337T, &signal_value_u16);
	//FC_Line_5_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_dx_End_338T, &signal_value_u16);
	//FC_Line_6_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_dx_End_338T, &signal_value_u16);
	//FC_Line_7_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneB.data.LaneViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_dx_End_339T, &signal_value_u16);
	//FC_Line_8_dx_End
	signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneB.data.LaneViewRangeEnd * 0.04);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_dx_End_339T, &signal_value_u16);

	/*Line dx end std*/
	//FC_Line_1_dx_End_std
	//The signal not mapping,because not source to mapping

	/*Line ModelC0*/	//OK
	//FC_Line_1_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0 + 32) / 0.015625);//*64
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_ModelC0_336T, &signal_value_u16);
	//FC_Line_2_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_ModelC0_336T, &signal_value_u16);
	//FC_Line_3_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_ModelC0_337T, &signal_value_u16);
	//FC_Line_4_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_ModelC0_337T, &signal_value_u16);
    //FC_Line_5_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_ModelC0_338T, &signal_value_u16);
	//FC_Line_6_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_ModelC0_338T, &signal_value_u16);
	//FC_Line_7_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_ModelC0_339T, &signal_value_u16);
	//FC_Line_8_ModelC0
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0 + 32) / 0.015625);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_ModelC0_339T, &signal_value_u16);

	/*Line ModelC1*/
	//FC_Line_1_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC1 + 1.6) / 0.000488281);//*2048
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_ModelC1_336T, &signal_value_u16);
	//FC_Line_2_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_ModelC1_336T, &signal_value_u16);
	//FC_Line_3_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_ModelC1_337T, &signal_value_u16);
	//FC_Line_4_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_ModelC1_337T, &signal_value_u16);
    //FC_Line_5_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_ModelC1_338T, &signal_value_u16);
	//FC_Line_6_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_ModelC1_338T, &signal_value_u16);
	//FC_Line_7_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneC.data.LaneModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_ModelC1_339T, &signal_value_u16);
	//FC_Line_8_ModelC1
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneC.data.LaneModelC1 + 1.6) / 0.000488281);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_ModelC1_339T, &signal_value_u16);


	/*Line ModelC2*/	//OK
	//FC_Line_1_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_ModelC2_336T, &signal_value_u16);
	//FC_Line_2_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_ModelC2_336T, &signal_value_u16);
	//FC_Line_3_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_ModelC2_337T, &signal_value_u16);
	//FC_Line_4_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_ModelC2_337T, &signal_value_u16);
    //FC_Line_5_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_ModelC2_338T, &signal_value_u16);
	//FC_Line_6_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_ModelC2_338T, &signal_value_u16);
	//FC_Line_7_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneC.data.LaneModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_ModelC2_339T, &signal_value_u16);
	//FC_Line_8_ModelC2
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneC.data.LaneModelC2 + 0.032)*1000000);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_ModelC2_339T, &signal_value_u16);


	/*Line Measure Type*/	//OK
	//FC_Line_1_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_MeasureType_336T, &signal_value_u8);
	//FC_Line_2_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_MeasureType_336T, &signal_value_u8);
	//FC_Line_3_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_MeasureType_337T, &signal_value_u8);
	//FC_Line_4_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_MeasureType_337T, &signal_value_u8);
    //FC_Line_5_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_MeasureType_338T, &signal_value_u8);
	//FC_Line_6_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_MeasureType_338T, &signal_value_u8);
	//FC_Line_7_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_MeasureType_339T, &signal_value_u8);
	//FC_Line_8_MeasureType
	signal_value_u8 = Sdc_DataProcess_PerceptionDataConvetOfMeasureType(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneMeasuringStatus);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_MeasureType_339T, &signal_value_u8);

	/*Line ModelC3*/	//OK
	//FC_Line_1_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_ModelC3_336T, &signal_value_u16);
	//FC_Line_2_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_ModelC3_336T, &signal_value_u16);
	//FC_Line_3_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneD.data.LaneModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_ModelC3_337T, &signal_value_u16);
	//FC_Line_4_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneD.data.LaneModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_ModelC3_337T, &signal_value_u16);
    //FC_Line_5_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_ModelC3_338T, &signal_value_u16);
	//FC_Line_6_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_ModelC3_338T, &signal_value_u16);
	//FC_Line_7_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneD.data.LaneModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_ModelC3_339T, &signal_value_u16);
	//FC_Line_8_ModelC3
	signal_value_u16 = (uint16)((Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneD.data.LaneModelC3 + 0.00026042) / 0.0000001272);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_ModelC3_339T, &signal_value_u16);


	/*Line ParseConf*/	//OK
	//FC_Line_1_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_ParseConf_336T, &Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence);
	//FC_Line_2_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_ParseConf_336T, &Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence);
	//FC_Line_3_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_ParseConf_337T, &Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence);
	//FC_Line_4_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_ParseConf_337T, &Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence);
    //FC_Line_5_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_ParseConf_338T, &Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.RoadEdgeParsingConfidence);
	//FC_Line_6_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_ParseConf_338T, &Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.RoadEdgeParsingConfidence);
	//FC_Line_7_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_ParseConf_339T, &Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneE.data.LaneParsingConfidence);
	//FC_Line_8_ParseConf
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_ParseConf_339T, &Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneE.data.LaneParsingConfidence);



	/*Line Obstacle Flg*/	//OK
	/*Notes : The Dbc not definition the value descriptions, Shall be confirmed~~~*/
	//FC_Line_1_ObstacleFlg
	// signal_value_u8 = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.ObstacleFlag;
	// Com_SendSignal(ComConf_ComSignal_SGFC_Line_1_ObstacleFlg_336T, &signal_value_u8);
	// //FC_Line_2_ObstacleFlg
	// signal_value_u8 = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.ObstacleFlag;
	// Com_SendSignal(ComConf_ComSignal_SGFC_Line_2_ObstacleFlg_336T, &signal_value_u8);
	// //FC_Line_3_ObstacleFlg
	// signal_value_u8 = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneD.data.ObstacleFlag;
	// Com_SendSignal(ComConf_ComSignal_SGFC_Line_3_ObstacleFlg_337T, &signal_value_u8);
	// //FC_Line_4_ObstacleFlg
	// signal_value_u8 = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneD.data.ObstacleFlag;
	// Com_SendSignal(ComConf_ComSignal_SGFC_Line_4_ObstacleFlg_337T, &signal_value_u8);

	/*Line RMSE*/
    //FC_Line_1_RMSE
    signal_value_u8 = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LineRmse;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_RMSE_336T, &signal_value_u8);
	//FC_Line_2_RMSE
    signal_value_u8 = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LineRmse;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_RMSE_336T, &signal_value_u8);
	//FC_Line_3_RMSE
    signal_value_u8 = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneE.data.LineRmse;;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_RMSE_337T, &signal_value_u8);
	//FC_Line_4_RMSE
    signal_value_u8 = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneE.data.LineRmse;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_RMSE_337T, &signal_value_u8);
	//The signal 5-6 not mapping,because not source to mapping
	//FC_Line_7_RMSE
    signal_value_u8 = Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneE.data.LineRmse;;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_RMSE_339T, &signal_value_u8);
	//FC_Line_8_RMSE
    signal_value_u8 = Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneE.data.LineRmse;
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_RMSE_339T, &signal_value_u8);

	/*Line exist prob*/		//OK
	//FC_Line_1_exist_prob
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_1_exist_prob_336T, &signal_value_u8);
	//FC_Line_2_exist_prob
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_2_exist_prob_336T, &signal_value_u8);
	//FC_Line_3_exist_prob
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_3_exist_prob_337T, &signal_value_u8);
	//FC_Line_4_exist_prob
	signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneConfidence / 2);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_4_exist_prob_337T, &signal_value_u8);
    //FC_Line_5_exist_prob
    signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.LaneConfidence/2.0f);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_5_exist_prob_338T, &signal_value_u8);
	//FC_Line_6_exist_prob
    signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.LaneConfidence/2.0f);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_6_exist_prob_338T, &signal_value_u8);
	//FC_Line_7_exist_prob
    signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Left_Outer_Lane.data.LKA_LaneA.data.LaneConfidence/2.0f);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_7_exist_prob_339T, &signal_value_u8);
	//FC_Line_8_exist_prob
    signal_value_u8 = (uint8)(Sdc_J3_PerceptionData.Lane.Right_Outer_Lane.data.LKA_LaneA.data.LaneConfidence/2.0f);
	Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Line_8_exist_prob_339T, &signal_value_u8);

	/*Line Block Ctr*/
	//The signal not mapping,because not source to mapping
	//FC_Line1_BlockCtr

    /*FC_LCrossPiont_DivMer*/
    signal_value_u8 = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneExtraNearPointType<=2u)?\
                      Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneExtraNearPointType:0u;
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LCrossPiont_DivMer_340T, &signal_value_u8);

    /*FC_LCrossPoint_DX         */
    signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosX / 10.0f);
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LCrossPoint_DX_340T, &signal_value_u16);

    /*FC_LCrossPiont_Dy*/
    signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosY/100.0f+50u)*10u;
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LCrossPiont_Dy_340T, &signal_value_u16);
    
    /*FC_LCrossPiont_ExistProb*/
    signal_value_u8 = ( (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneExtraNearPointType==1u) || \
                     (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneExtraNearPointType==2u) )?50u:0u;/*factor:2*/
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LCrossPiont_ExistProb_340T, &signal_value_u8);
    
    /*FC_LCrossPiont_StartEnd*/
    signal_value_u8 = 0u;
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_LCrossPiont_StartEnd_340T, &signal_value_u8);


    /*FC_RCrossPiont_DivMer*/
    signal_value_u8 = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneExtraNearPointType<=2u)?\
                      Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneExtraNearPointType:0u;
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_RCrossPiont_DivMer_340T, &signal_value_u8);

    /*FC_RCrossPoint_DX         */
    signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosX / 10.0f);
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_RCrossPoint_DX_340T, &signal_value_u16);

    /*FC_RCrossPiont_Dy*/
    signal_value_u16 = (uint16)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosY/100.0f+50u)*10u;
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_RCrossPiont_Dy_340T, &signal_value_u16);

    /*FC_RCrossPiont_ExistProb*/
    signal_value_u8 = ( (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneExtraNearPointType==1u) || \
                     (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneExtraNearPointType==2u) )?50u:0u;/*factor:2*/
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_RCrossPiont_ExistProb_340T, &signal_value_u8);

    /*FC_RCrossPiont_StartEnd*/
    signal_value_u8 = 0u;
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_RCrossPiont_StartEnd_340T, &signal_value_u8);


    /*FC_WeatherType*/
    if((Sdc_J3_PerceptionData.Lane.Road_Information.data.CurrentWeather>=1) && \
       (Sdc_J3_PerceptionData.Lane.Road_Information.data.CurrentWeather<=5) )
    {
        signal_value_u8 = Sdc_J3_PerceptionData.Lane.Road_Information.data.CurrentWeather-1u;
    }
   else
    {
        signal_value_u8 = 5u;/*other*/
    }
    Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_WeatherType_340T, &signal_value_u8);

}

#if (SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE == STD_ON)

static FUNC(s_Sdc_TrafficSign_SortType, RTE_CODE) Sdc_DataProcess_ProssessTrafficSignType(uint16 TrafficSignType) 
{
    s_Sdc_TrafficSign_SortType stData={0u,0u};
    switch(TrafficSignType)
    {
                            /*FC_TSRMandatorySign*/
        case 178u:stData.u16_type=0x1u;stData.u16_priority=5u;break;
        case 184u:stData.u16_type=0x2u;stData.u16_priority=3u;break;
        case 171u:stData.u16_type=0x5u;stData.u16_priority=4u;break;
                            /*FC_TSRProhibitionSign*/
        case 259u:stData.u16_type=0x1u;stData.u16_priority=1u;break; /*CN_P_Noway          */
        case 229u:stData.u16_type=0x2u;stData.u16_priority=2u;break; /*CN_P_NoEntry        */
        case 244u:stData.u16_type=0x3u;stData.u16_priority=3u;break; /*CN_P_NoMotor        */
        case 239u:stData.u16_type=0x4u;stData.u16_priority=4u;break; /*CN_P_NoLeftTurn     */            
        case 252u:stData.u16_type=0x5u;stData.u16_priority=5u;break; /*CN_P_NoRightTurn    */
        case 230u:stData.u16_type=0x6u;stData.u16_priority=6u;break; /*CN_P_NoForward      */            
        case 251u:stData.u16_type=0x7u;stData.u16_priority=8u;break; /*CN_P_NoReturn       */            
        case 249u:stData.u16_type=0x8u;stData.u16_priority=7u;break; /*CN_P_NoPassing      */
        case 250u:stData.u16_type=0x9u;stData.u16_priority=12u;break; /*CN_P_NoPassingRev   */ 
        case 247u:stData.u16_type=0xAu;stData.u16_priority=15u;break; /*CN_P_NoParking      */
        case 240u:stData.u16_type=0xBu;stData.u16_priority=16u;break; /*CN_P_NoLongParking  */
        case 233u:stData.u16_type=0xCu;stData.u16_priority=13u;break; /*CN_P_NoHorning      */
        case 324u:stData.u16_type=0xDu;stData.u16_priority=10u;break; /*CN_P_StopFor        */
        case 263u:stData.u16_type=0xEu;stData.u16_priority=11u;break; /*CN_P_SlowFor        */
                            /*FC_TSRWarningSign*/
        case 407u:stData.u16_type=0x1u;stData.u16_priority=5u;break;/*CN_W_LRTurn            */
        case 384u:stData.u16_type=0x2u;stData.u16_priority=6u;break;/*CN_W_ContinuousTurn    */
        case 418u:stData.u16_type=0x3u;stData.u16_priority=4u;break;/*CN_W_Pedestrian        */
        case 381u:stData.u16_type=0x4u;stData.u16_priority=3u;break;/*CN_W_Children          */
        case 428u:stData.u16_type=0x5u;stData.u16_priority=2u;break;/*CN_W_Slip              */
        case 442u:stData.u16_type=0x6u;stData.u16_priority=7u;break;/*CN_W_Tunnel            */
        case 429u:stData.u16_type=0x7u;stData.u16_priority=1u;break;/*CN_W_Slow              */
        case 449u:stData.u16_type=0x8u;stData.u16_priority=8u;break;/*CN_W_Working           */

        default:stData.u16_type=0x0u;stData.u16_priority=0xFFu;break;
    }

    return stData;

}

static FUNC(void, RTE_CODE) Sdc_DataProcess_MappingTrafficSignType(void) 
{
    uint16 u16_SignalValue = 0u;
    uint8  i=0u;
    uint16 u16_TrafficSignType_Mandatory   = 0u;
    uint16 u16_Sign_Position_X_Mandatory   = 0xFFFFu;
    uint16 u16_TrafficSignType_OutPut_Mandatory   = 0u;
    uint16 u16_TrafficSignType_Prohibition = 0u;
    uint16 u16_Sign_Position_X_Prohibition = 0xFFFFu;
    uint16 u16_TrafficSignType_OutPut_Prohibition = 0u;
    uint16 u16_TrafficSignType_Warning = 0u;
    uint16 u16_Sign_Position_X_Warning = 0xFFFFu;
    uint16 u16_TrafficSignType_OutPut_Warning = 0u;
    s_Sdc_TrafficSign_SortType stData1={0u,0u};
    s_Sdc_TrafficSign_SortType stData2={0u,0u};

    for(i=0;i<16u;i++)
    {
        switch(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType)
        {
            /*FC_TSRMandatorySign*/
            case 178u:
            case 184u:
            case 171u:
            {
                stData1=Sdc_DataProcess_ProssessTrafficSignType(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType);
                stData2=Sdc_DataProcess_ProssessTrafficSignType(u16_TrafficSignType_Mandatory);
                if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X == u16_Sign_Position_X_Mandatory )
                {
                    if(stData1.u16_priority < stData2.u16_priority )
                    {
                        u16_TrafficSignType_Mandatory = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
                        u16_Sign_Position_X_Mandatory = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
                        u16_TrafficSignType_OutPut_Mandatory = stData1.u16_type;
                    }
                    else
                    {
                        u16_TrafficSignType_OutPut_Mandatory = stData2.u16_type;
                    }
                   
                }
                else if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X < u16_Sign_Position_X_Mandatory )
                {
                    u16_TrafficSignType_Mandatory = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
                    u16_Sign_Position_X_Mandatory = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
                    u16_TrafficSignType_OutPut_Mandatory = stData1.u16_type;
                }
                else
                {
                    u16_TrafficSignType_OutPut_Mandatory = stData2.u16_type;
                }
            }
            break;
            /*FC_TSRProhibitionSign*/
            case 259u: /*CN_P_Noway          */
            case 229u: /*CN_P_NoEntry        */
            case 244u: /*CN_P_NoMotor        */
            case 239u: /*CN_P_NoLeftTurn     */            
            case 252u: /*CN_P_NoRightTurn    */
            case 230u: /*CN_P_NoForward      */            
            case 251u: /*CN_P_NoReturn       */            
            case 249u: /*CN_P_NoPassing      */
            case 250u: /*CN_P_NoPassingRev   */ 
            case 247u: /*CN_P_NoParking      */
            case 240u: /*CN_P_NoLongParking  */
            case 233u: /*CN_P_NoHorning      */
            case 324u: /*CN_P_StopFor        */
            case 263u: /*CN_P_SlowFor        */
            {
                stData1=Sdc_DataProcess_ProssessTrafficSignType(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType);
                stData2=Sdc_DataProcess_ProssessTrafficSignType(u16_TrafficSignType_Prohibition);
                if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X == u16_Sign_Position_X_Prohibition )
                {
                    if(stData1.u16_priority < stData2.u16_priority )
                    {
                        u16_TrafficSignType_Prohibition = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
                        u16_Sign_Position_X_Prohibition = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
                        u16_TrafficSignType_OutPut_Prohibition = stData1.u16_type;
                    }
                    else
                    {
                        u16_TrafficSignType_OutPut_Prohibition = stData2.u16_type;
                    }
                   
                }                    
                else if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X < u16_Sign_Position_X_Prohibition )
                {
                    u16_TrafficSignType_Prohibition = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
                    u16_Sign_Position_X_Prohibition = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
                    u16_TrafficSignType_OutPut_Prohibition = stData1.u16_type;
                }
                else
                {
                    u16_TrafficSignType_OutPut_Prohibition = stData2.u16_type;
                }

            }
            break;
            /*FC_TSRWarningSign*/
            case 407u: /*CN_W_LRTurn            */
            case 384u: /*CN_W_ContinuousTurn    */
            case 418u: /*CN_W_Pedestrian        */
            case 381u: /*CN_W_Children          */
            case 428u: /*CN_W_Slip              */
            case 442u: /*CN_W_Tunnel            */
            case 429u: /*CN_W_Slow              */
            case 449u: /*CN_W_Working           */
            {
                stData1=Sdc_DataProcess_ProssessTrafficSignType(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType);
                stData2=Sdc_DataProcess_ProssessTrafficSignType(u16_TrafficSignType_Warning);
                if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X == u16_Sign_Position_X_Warning )
                {
                    if(stData1.u16_priority < stData2.u16_priority )
                    {
                        u16_TrafficSignType_Warning = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
                        u16_Sign_Position_X_Warning = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
                        u16_TrafficSignType_OutPut_Warning = stData1.u16_type;
                    }
                    else
                    {
                        u16_TrafficSignType_OutPut_Warning = stData2.u16_type;
                    }
                }
                else if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X < u16_Sign_Position_X_Warning )
                {
                    u16_TrafficSignType_Warning = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
                    u16_Sign_Position_X_Warning = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
                    u16_TrafficSignType_OutPut_Warning = stData1.u16_type;
                }
                else
                {
                    u16_TrafficSignType_OutPut_Warning = stData2.u16_type;
                }
            }
            break;
            default:/*do nothing*/break;           
        }

    }

    u16_SignalValue = u16_TrafficSignType_OutPut_Mandatory;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TSRMandatorySign_407T         , &u16_SignalValue);

    u16_SignalValue =u16_TrafficSignType_OutPut_Prohibition;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TSRProhibitionSign_407T         , &u16_SignalValue);

    u16_SignalValue = u16_TrafficSignType_OutPut_Warning;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TSRWarningSign_407T         , &u16_SignalValue);
    
}

static FUNC(uint8, RTE_CODE) Sdc_DataProcess_ArrayMatch(uint8 index)
{
	uint8 match_flag = 0;
	
	match_flag = 0;
	for(uint8 i=0u;i<5u;i++)
    {
		if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[index].data.TSR_Internal_ID == Sdc_Speedlimitblacklist.slblacklist[i])
			match_flag = 1;
	}
	return match_flag;
}

static FUNC(void, RTE_CODE) Sdc_DataProcess_MappingSpeedLimit(void)
{
   uint8  i=0u;
    uint8  u8_SignalValue_TSR_AttrValue[16u]    = {0u};
	uint16 u16_SignalValue_TrafficSignType[16u]  = {0u};
	uint16 u16_SignalValue_TrafficSign_ChildType[16u]  = {0u};
    uint16 u16_SignalValue_Sign_Position_X[16u] = {0u};
    sint16 s16_SignalValue_Sign_Position_Y[16u] = {0};
    uint8  u8_SpeedLimitValue1 = 0u;
    uint8  u8_SpeedLimitValue2 = 0u;
    uint8  u8_SpeedLimitValue1_Flag = 0u;
    uint8  u8_SpeedLimitValue2_Flag = 0u;
    uint8  u8_SignalValue_Index_Flag = 0u;
    uint8  u8_TSR_AttrValue     = 0u;
    uint16 u16_TrafficSignType   = 0u;
    uint16 u16_Sign_Position_X  = 0u;
    sint16 s16_Sign_Position_Y  = 0u;
    uint8  u8_TSRHostSpdLimitUnits = 0u;
    uint8  u8_SignalValue = 0u;
    uint16 u16_SignalValue = 0u;
	uint16  u16_SpeedLimitValue1_ID = 0u; 
	uint8 match_flag = 0;
	uint16 u16_Sign_Position_X_Buf = 0u;

	for(uint8 i=0u;i<5u;i++)//clear Internal_ID per 3000 frameID
    {
		if((Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex - Sdc_Speedlimitblacklist.slblacklist_frameID[i]) > 3000)
		{
			Sdc_Speedlimitblacklist.slblacklist_frameID[i] = 0;
			Sdc_Speedlimitblacklist.slblacklist[i] = 0;
		}	
	}

    for(i=0u;i<16u;i++)
    {
		/*TSR_AttrValue*/
		if((0u == (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.TSR_AttrValue%5u)) && //Speed Limit
            (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.TSR_AttrValue >=5u  )    && 
            (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.TSR_AttrValue <=160u)    &&  
			((Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType == 264u) 
            || (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType == 265u)))
		{
			match_flag = Sdc_DataProcess_ArrayMatch(i);
			if(match_flag == 0)//FrameIndex not in the blacklist
			{
				u8_SignalValue_TSR_AttrValue[i] = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.TSR_AttrValue/5u;

				if(u8_SignalValue_TSR_AttrValue[i] >= u8_SpeedLimitValue1) 
				{
					if(((u16_Sign_Position_X_Buf != 0) && (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X < u16_Sign_Position_X_Buf)) || (u16_Sign_Position_X_Buf == 0))
					{
						if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X >= (u16_Sign_Position_X_Buf - 500))
						{
							u8_SpeedLimitValue1 = u8_SignalValue_TSR_AttrValue[i];
							u8_SpeedLimitValue1_Flag = i;

							Sdc_Speedlimitblacklist.slblacklist[Sdc_Speedlimitblacklist.slblacklistnumber] = u16_SpeedLimitValue1_ID; 
							Sdc_Speedlimitblacklist.slblacklist_frameID[Sdc_Speedlimitblacklist.slblacklistnumber] = Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex;//record frameID
							Sdc_Speedlimitblacklist.slblacklistnumber++;
							if(Sdc_Speedlimitblacklist.slblacklistnumber == 5)
								Sdc_Speedlimitblacklist.slblacklistnumber = 0;					
							u16_SpeedLimitValue1_ID = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TSR_Internal_ID; 
						}
						else
						{
							u8_SpeedLimitValue1 = u8_SignalValue_TSR_AttrValue[i];
							u8_SpeedLimitValue1_Flag = i;
						}
					}
					if(((u16_Sign_Position_X_Buf != 0) && (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X > u16_Sign_Position_X_Buf)) || (u16_Sign_Position_X_Buf == 0))
					{
						if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X <= (u16_Sign_Position_X_Buf + 500))
						{	
							u8_SpeedLimitValue1 = u8_SignalValue_TSR_AttrValue[i];
							u8_SpeedLimitValue1_Flag = i;

							Sdc_Speedlimitblacklist.slblacklist[Sdc_Speedlimitblacklist.slblacklistnumber] = u16_SpeedLimitValue1_ID; 
							Sdc_Speedlimitblacklist.slblacklist_frameID[Sdc_Speedlimitblacklist.slblacklistnumber] = Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex;//record frameID
							Sdc_Speedlimitblacklist.slblacklistnumber++;
							if(Sdc_Speedlimitblacklist.slblacklistnumber == 5)
								Sdc_Speedlimitblacklist.slblacklistnumber = 0;					
							u16_SpeedLimitValue1_ID = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TSR_Internal_ID; 
						}
					}				
				}
				else
				{
					if((u16_Sign_Position_X_Buf != 0) && (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X < u16_Sign_Position_X_Buf))
					{
						if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X >= (u16_Sign_Position_X_Buf - 500))
						{
							Sdc_Speedlimitblacklist.slblacklist[Sdc_Speedlimitblacklist.slblacklistnumber]= Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TSR_Internal_ID; 
							Sdc_Speedlimitblacklist.slblacklist_frameID[Sdc_Speedlimitblacklist.slblacklistnumber] = Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex;//record frameID
							Sdc_Speedlimitblacklist.slblacklistnumber++;
							if(Sdc_Speedlimitblacklist.slblacklistnumber == 5)
								Sdc_Speedlimitblacklist.slblacklistnumber = 0;
						}
						else
						{
							u8_SpeedLimitValue1 = u8_SignalValue_TSR_AttrValue[i];
							u8_SpeedLimitValue1_Flag = i;
						}
					}
					if((u16_Sign_Position_X_Buf != 0) && (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X > u16_Sign_Position_X_Buf))
					{
						if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X <= (u16_Sign_Position_X_Buf + 500))
						{
							/*keep last value*/
							Sdc_Speedlimitblacklist.slblacklist[Sdc_Speedlimitblacklist.slblacklistnumber]= Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TSR_Internal_ID; 
							Sdc_Speedlimitblacklist.slblacklist_frameID[Sdc_Speedlimitblacklist.slblacklistnumber] = Sdc_J3_PerceptionData.Sync.data.SyncMsg3.data.FrameIndex;//record frameID
							Sdc_Speedlimitblacklist.slblacklistnumber++;
							if(Sdc_Speedlimitblacklist.slblacklistnumber == 5)
								Sdc_Speedlimitblacklist.slblacklistnumber = 0;
						}
					}					
				}
			}
			u16_Sign_Position_X_Buf = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;	
		}
        else if(Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType == 300u)//Unlimited
        {
            u8_SignalValue_TSR_AttrValue[i] = 0xFEu;
            u8_SpeedLimitValue2 = 0xFEu;  
            u8_SpeedLimitValue2_Flag = i;
            
        }
		else//no speed limit detected
		{
			u8_SignalValue_TSR_AttrValue[i] = 0u;
		}

        // u16_SignalValue_TrafficSignType[i] = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSignType;
		u16_SignalValue_TrafficSignType[i] = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TrafficSign_ChildType;
        u16_SignalValue_Sign_Position_X[i] = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X;
        s16_SignalValue_Sign_Position_Y[i] = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_Y;

    }

    if( u8_SpeedLimitValue2 == 0xFEu)//Unlimited priority
    {
        u8_TSR_AttrValue = u8_SpeedLimitValue2;
        u8_SignalValue_Index_Flag = u8_SpeedLimitValue2_Flag;
        u16_Sign_Position_X = u16_SignalValue_Sign_Position_X[u8_SignalValue_Index_Flag];
        s16_Sign_Position_Y = s16_SignalValue_Sign_Position_Y[u8_SignalValue_Index_Flag];
        u8_TSRHostSpdLimitUnits = 0u;
        u16_TrafficSignType = 0u;
    }
	else if(u8_SpeedLimitValue1 != 0u)
    {
        u8_TSR_AttrValue = u8_SpeedLimitValue1;
        u8_SignalValue_Index_Flag = u8_SpeedLimitValue1_Flag;
        u16_Sign_Position_X = u16_SignalValue_Sign_Position_X[u8_SignalValue_Index_Flag];
        s16_Sign_Position_Y = s16_SignalValue_Sign_Position_Y[u8_SignalValue_Index_Flag];
        u8_TSRHostSpdLimitUnits = 1u;
        u16_TrafficSignType = (u16_SignalValue_TrafficSignType[u8_SignalValue_Index_Flag] == 1u)?1u:0u;//TrafficSignType=109=CN_IR_Ramp 
    }
    else
    {
        u8_TSR_AttrValue = 0;
        u8_SignalValue_Index_Flag=0xFFu;
        u16_Sign_Position_X = 0;
        s16_Sign_Position_Y = 0;
        u8_TSRHostSpdLimitUnits = 0u;
        u16_TrafficSignType = 0u;
    }
    /* FC_SpeedLimit_1 */
    u8_SignalValue = (uint8)u8_TSR_AttrValue;
	(void)Com_UpdateShadowSignal( ComConf_ComGroupSignal_FC_SpeedLimit_1_407T , &u8_SignalValue);

    /* FC_SpeedLimitType */
    u8_SignalValue = (uint8)u16_TrafficSignType;
    (void)Com_UpdateShadowSignal( ComConf_ComGroupSignal_FC_SpeedLimitType_1_407T, &u8_SignalValue);
    
    /*FC_speedLimitSign_Dx*/
    u16_SignalValue = (uint16)(u16_Sign_Position_X/10.0f);
    (void)Com_UpdateShadowSignal( ComConf_ComGroupSignal_FC_speedLimitSign_Dx_407T , &u16_SignalValue);
    
    /*FC_speedLimitSign_Dy*/
    u16_SignalValue = (uint16)(s16_Sign_Position_Y/100.0f + 50u)*10u;
    (void)Com_UpdateShadowSignal( ComConf_ComGroupSignal_FC_speedLimitSign_Dy_407T , &u16_SignalValue);

    /*FC_TSRHostSpdLimitUnits*/
    u8_SignalValue = u8_TSRHostSpdLimitUnits;
    (void)Com_UpdateShadowSignal( ComConf_ComGroupSignal_FC_TSRHostSpdLimitUnits_407T,&u8_SignalValue);
}


/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_TSRTFL2CAN
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
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_TSRTFL2CAN(void)
{
    uint8   i                 = 0u; 
    uint8   u8_SignalValue    = 0u;
    uint16  u16_SignalValue   = 0u;
	uint8 fc_workMode = 1;

    /*TFLObjectsNumber*/
    u8_SignalValue = Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_Header.data.TFLObjectsNumber;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TLAObjectsNumber_406T         , &u8_SignalValue);
    
    /*TFLMainObjectID*/
    u8_SignalValue = Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_Header.data.TFLMainObjectID;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_TLAMainObjectID_406T          , &u8_SignalValue);

    /*StopLine_Detected*/
    u8_SignalValue = Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.StopLine_Flag;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_StopLine_Detected_407T    , &u8_SignalValue);

    /*Crosswalk_Detect*/
    u8_SignalValue = Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.CrossWalk_Flag;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Crosswalk_Detect_407T    , &u8_SignalValue);

    /*SpeedBump Detect*/
    u8_SignalValue = Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.SpeedBump_Flag;
    (void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_SpeedBump_Detect_407T    , &u8_SignalValue);

    /*StopLine_Distance*/
    u16_SignalValue = (uint16) Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.StopLine_Distance / 10.0f; /* x/100/0.1 */
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_StopLine_Dist_407T    , &u16_SignalValue);
    
    /*CrossWalk_Distance*/
    u16_SignalValue = (uint16) Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.CrossWalk_Distance / 10.0f; /* x/100/0.1 */
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Crosswalk_Dist_407T   , &u16_SignalValue);

    /*SpeedBump_Distance*/
    u16_SignalValue = (uint16) Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.SpeedBump_Distance / 10.0f; /* x/100/0.1 */
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_SpeedBump_Dist_407T    , &u16_SignalValue);

    /*TrafficSignType：FC_TSRMandatorySign,FC_TSRProhibitionSign,FC_TSRWarningSign*/
    Sdc_DataProcess_MappingTrafficSignType();
    
	/*FC_Brightness*/
	if(Sdc_J3_PerceptionData.IHBC.HighLowBeam_msg_01.IHBC_HighLowBeam_Layout_01.Cal_lux < 100.0f)
	{
		u16_SignalValue = (uint16) Sdc_J3_PerceptionData.IHBC.HighLowBeam_msg_01.IHBC_HighLowBeam_Layout_01.Cal_lux * 10.0f; /* x/0.1 */
	}
    else if(Sdc_J3_PerceptionData.IHBC.HighLowBeam_msg_01.IHBC_HighLowBeam_Layout_01.Cal_lux > 100.0f)
	{
		u16_SignalValue = 0x3FE;
	}
	else
	{
		u16_SignalValue = 0x3FF;
	}
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Brightness_407T, &u16_SignalValue);
	
    /*FC_SpeedLimit_1 and FC_SpeedLimitType_1 */
    Sdc_DataProcess_MappingSpeedLimit();

    
    for(i=0;i<SDC_J3_TSR_TFL_TRAFFICSIGN_NUM;i++)
    {
        /*******************************************traffic light******************************************/
        /*TFL_Type*/
        switch( Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_ClassificationType_1)
        {
            //case 0 :u8_SignalValue=0u; break; /*Unknown            */
            case 1 :u8_SignalValue=1u; break; /*L_Circle           */
            case 2 : 						  /*L_Forward          */
            case 3 :						  /*L_Left             */
            case 4 :u8_SignalValue=2u; break; /*L_Right            */
            case 5 :u8_SignalValue=4u; break; /*L_Return           */
            //case 6 :u8_SignalValue=9u; break; /*L_Pedestrian       */
            //case 7 :u8_SignalValue=0u; break; /*L_Non_Motor        */
            //case 8 :u8_SignalValue=0u; break; /*L_Time             */
            case 9 :u8_SignalValue=6u; break; /*L_Other            */
            case 10:u8_SignalValue=5u; break; /*L_left_and_return  */
            case 11:						  /*L_Forward_and_Left */
            case 12:u8_SignalValue=2u; break; /*L_Forward_and_Right*/
            case 13:u8_SignalValue=3u; break; /*L_No_Drive_into    */
            default:
            {
                u8_SignalValue = 0u;
                break;
            }
        }
 
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_ClassificationType[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_ClassificationType[i]               , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}

        /*TFL_Color*/        
        if(4u == Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_Bulb_Color_1)
        {
            u8_SignalValue = 5u;
        }
        else if(5u == Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_Bulb_Color_1)
        {
            u8_SignalValue = 4u;
        }
        else
        {
            u8_SignalValue = Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_Bulb_Color_1;
        }

		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_Color[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_Color[i]               , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
        
        /*TFL_direction*/
        switch(Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_ClassificationType_1)
        {
            //case 0 :u8_SignalValue=0u; break; /*Unknown            */
            //case 1 :u8_SignalValue=0u; break; /*L_Circle           */
            case 2 :u8_SignalValue=1u; break; /*L_Forward          */
            case 3 :u8_SignalValue=2u; break; /*L_Left             */
            case 4 :u8_SignalValue=4u; break; /*L_Right            */
            case 5 :u8_SignalValue=2u; break; /*L_Return           */
            //case 6 :u8_SignalValue=0u; break; /*L_Pedestrian       */
            //case 7 :u8_SignalValue=0u; break; /*L_Non_Motor        */
            //case 8 :u8_SignalValue=0u; break; /*L_Time             */
            //case 9 :u8_SignalValue=0u; break; /*L_Other            */
            case 10:u8_SignalValue=2u; break; /*L_left_and_return  */
            case 11:u8_SignalValue=3u; break; /*L_Forward_and_Left */
            case 12:u8_SignalValue=5u; break; /*L_Forward_and_Right*/
            //case 13:u8_SignalValue=0u; break; /*L_No_Drive_into    */
            //case 14:u8_SignalValue=0u; break; /*L_Allow_Drive_into */
            //case 15:u8_SignalValue=0u; break; /*text_of_allow_ped  */
            //case 16:u8_SignalValue=0u; break; /*sign_of_allow_ped  */
            //case 17:u8_SignalValue=0u; break; /*text_of_forbid_ped */
            //case 18:u8_SignalValue=0u; break; /*sign_of_forbid_ped */
            default:
            {
                u8_SignalValue = 0u;
                break;
            }
        }
        
        if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_direction[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_direction[i], &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}

        /*TFL_Blinking*/
        if((1u == Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_Bulb_Color_1)
		 ||(2u == Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_Bulb_Color_1)
		 ||(3u == Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_Bulb_Color_1))
        {
            u8_SignalValue = 1u;
        }
        else if(1u == Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.is_TFL_Blinking_1)//Unsupported
        {
            u8_SignalValue = 2u;
        }
        else
        {
            u8_SignalValue=0u;
        }

        if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_BlindingStatus[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_BlindingStatus[i]               , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}

        /*TFL_ShapeType*/
        switch(Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_ShapeType)
        {
            //case 0: u8_SignalValue=0u; break; /*Unknown/Unsupported */
            case 1: u8_SignalValue=1u; break; /*HorizontalVertical 1-light */
            case 2: u8_SignalValue=2u; break; /*Horizontal 2-light         */
            case 3: u8_SignalValue=1u; break; /*Vertical 2-light           */
            case 4: u8_SignalValue=2u; break; /*Horizontal 3-light         */
            case 5: u8_SignalValue=1u; break; /*Vertical 3-light           */
            case 6: u8_SignalValue=2u; break; /*Horizontal 4-light         */
            case 7: u8_SignalValue=1u; break; /*Vertical 4-light           */
            case 8: u8_SignalValue=2u; break; /*Horizontal 5-light         */
            case 9: u8_SignalValue=1u; break; /*Vertical 5-light           */
            default:
            {
                u8_SignalValue = 0u;
                break;
            }
        }
        
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_ShapeType[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_ShapeType[i]           , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}


        /*TFL_PosX*/
        u16_SignalValue = (Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataA[i].data.TFL_PosX / 100.0) / 0.1;
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_PosX[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_PosX[i]                , &u16_SignalValue); 
		}
		else
		{
			/*TODO : Doing nothing*/
		}
        
        /*TFL_PosY*/
        u16_SignalValue = ((Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataA[i].data.TFL_PosY / 100.0) + 20u)/0.01;
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_PosY[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_PosY[i]                , &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
         
        /*TFL_PosZ*/
        u16_SignalValue = (Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataB[i].data.TFL_PosZ / 100.0) / 0.1;
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_PosZ[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_PosZ[i]                , &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
        
        /*TFL_Confidence*/
        u8_SignalValue = Sdc_J3_PerceptionData.TSR_TFL.TFL_Data.TFL_DataA[i].data.TFL_Confidence;
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_Confidence[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_Confidence[i]          , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
        
        
        /*******************************************Traffic Sign******************************************/         
		#if 0 	/*dbc v2.3 delete*/
		/*Sign_Position_X*/
		u16_SignalValue = (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_X / 100.0)  / 0.1f;
		if(u16_SignalValue >= 0x1F4u)
		{
			u16_SignalValue = 0x1f4u;
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardCenterLngRange[i])
		{
			(void)Com_SendSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardCenterLngRange[i], &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		
		/*Sign_Position_Y*/
		u16_SignalValue = ((Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_Y / 100.0) + 8) / 0.05;
		if(u16_SignalValue > 0x140u)
		{
			u16_SignalValue = 0x140u;
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardCenterLngRange[i])
		{
			(void)Com_SendSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardCenterLatRange[i], &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		
		//SignBoardHeight
		u16_SignalValue = (Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataB[i].data.Sign_Position_Z / 100.0 ) / 0.5;
		if(u16_SignalValue > 0x14)
		{
			u16_SignalValue = 0x14;
		} 
		else
		{
			/*TODO : Doing nothing*/
		}
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardHeight[i])
		{
			(void)Com_SendSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardHeight[i]        , &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		#endif		

		/*TSR_Confidence*/
        #if 0   //delete dbc v2.3
		u8_SignalValue = Sdc_J3_PerceptionData.TSR_TFL.TSR_Data.TSR_DataA[i].data.TSR_Confidence;
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardConfidence[i])
		{
			(void)Com_SendSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_SignBoardConfidence[i]    , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}		       
        #endif
	}

    for(i=0;i<3u;i++)
    {
        /*********************************Lane Sign**********************************/
        /*LaneMarking*/
        switch(Sdc_J3_PerceptionData.LM.LM_DataA_Array[i].LM_DataA_Layout.LaneMarkingType)
        {
            //case 0:u8_SignalValue= 0u;break;/*Unknown 0                            */
            case 1:u8_SignalValue= 2u;break;/*Arrow_Left                           */
            case 2:u8_SignalValue= 1u;break;/*Arrow_Forward                        */
            case 3:u8_SignalValue= 3u;break;/*Arrow_Right                          */
            case 4:u8_SignalValue= 6u;break;/*Arrow_Left_And_Forward               */
            case 5:u8_SignalValue= 7u;break;/*Arrow_Right_And_Forward              */
            //case 6:u8_SignalValue= 0u;break;/*Arrow_Left_And_Right                 */
            case 7:u8_SignalValue= 4u;break;/*Arrow_U_Turn                         */
            case 8:u8_SignalValue= 8u;break;/*Arrow_U_Turn_And_Forward             */
            case 9:u8_SignalValue= 0xBu;break;/*Arrow_U_Turn_And_Left                */
            //case 10:u8_SignalValue= 0u;break;/*Arrow_Merge_Left                    */
            //case 11:u8_SignalValue= 0u;break;/*Arrow_Merge_Right                   */
            //case 12:u8_SignalValue= 0u;break;/*Crosswalk_Notice                    */
            //case 13:u8_SignalValue= 0u;break;/*Speed_Limit_Low                     */
            //case 14:u8_SignalValue= 0u;break;/*Speed_Limit_High                    */
            //case 15:u8_SignalValue= 0u;break;/*Arrow_No_Left_Turn                  */
            //case 16:u8_SignalValue= 0u;break;/*Arrow_No_Right_Turn                 */
            //case 17:u8_SignalValue= 0u;break;/*Arrow_No_U_Turn                     */
            //case 18:u8_SignalValue= 0u;break;/*Arrow_No_Forward_And_Left_And_Right */
            //case 19:u8_SignalValue= 0u;break;/*Arrow_No_Forward_And_U_Turn_And_Left*/
            //case 20:u8_SignalValue= 0u;break;/*Arrow_No_Right_And_U_Turn           */
            //case 21:u8_SignalValue= 0u;break;/*Text                                */
            //case 22:u8_SignalValue= 0u;break;/*Time                                */
            //case 23:u8_SignalValue= 0u;break;/*Check_Following_Distance            */
            //case 24:u8_SignalValue= 0u;break;/*Stop_To_Give_Way                    */
            //case 25:u8_SignalValue= 0u;break;/*Slowdown_To_Give_Way                */
            //case 26:u8_SignalValue= 0u;break;/*Stop_Mark                           */
            //case 27:u8_SignalValue= 0u;break;/*Nets                                */
            /*other case set to 0,TBD*/
            default:
            {
                u8_SignalValue = 0u;
                break;
            }
        }
        if(0u != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignType[i])
        {
            (void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignType[i]    , &u8_SignalValue);
        }
        else
		{
			/*TODO : Doing nothing*/
		}		       

        /*LM_Position_X*/
		u16_SignalValue = (Sdc_J3_PerceptionData.LM.LM_DataA_Array[i].LM_DataA_Layout.LM_Position_X / 100.0)  / 0.1f;
		if(u16_SignalValue >= 0x1F4u)
		{
			u16_SignalValue = 0x1f4;
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignCenterLngRange[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignCenterLngRange[i], &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
        
        /*Sign_Position_Y*/
		u16_SignalValue = ((Sdc_J3_PerceptionData.LM.LM_DataA_Array[i].LM_DataA_Layout.LM_Position_Y / 100.0) + 8) / 0.05;
		if(u16_SignalValue > 0x140u)
		{
			u16_SignalValue = 0x140u;
		}
		else
		{
			/*TODO : Doing nothing*/
		}
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignCenterLatRange[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignCenterLatRange[i], &u16_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}
        
        /*LM_Confidence*/
		u8_SignalValue = Sdc_J3_PerceptionData.LM.LM_DataA_Array[i].LM_DataA_Layout.LM_Confidence;
		if(0x00 != Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignConfidence[i])
		{
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_RoadSignConfidence[i]    , &u8_SignalValue);
		}
		else
		{
			/*TODO : Doing nothing*/
		}		       
        
    }
    
	/*****************************static object**********************************/
	fc_workMode = Sdc_Diag_GetWorkmode();
	for(i=0;i<20u;i++)
	{
		if((fc_workMode != 0x2)||((fc_workMode == 0x2)&&(Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_Type != 0x5)))
		{	
			// u8_SignalValue = Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_Type;
			switch(Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_Type)
			{
				case 1: u8_SignalValue=1u; break; /**/
				// case 2: u8_SignalValue=2u; break; /**/
				case 3: u8_SignalValue=3u; break; /**/
				// case 4: u8_SignalValue=2u; break; /**/
				case 5: u8_SignalValue=5u; break; /*Isolation*/
				case 6: u8_SignalValue=5u; break; /*TrafficBollard*/
				case 7: u8_SignalValue=5u; break; /*OtherBollard*/
				case 8: u8_SignalValue=6u; break; /*CrashBarrel*/
				case 9: u8_SignalValue=7u; break; /*Carton*/
				default:
				{
					u8_SignalValue = 0u;
					break;
				}
			}
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_Type[i]    , &u8_SignalValue);

			/*FC_StaticObj1_LaneAssi*/
			u8_SignalValue = Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_EgoVehile;
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_LaneAssi[i]    , &u8_SignalValue);

			if(0 != Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_TrackID)
			{
				u8_SignalValue = Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_TrackID % 255 + 1;
			}
			else
			{
				u8_SignalValue = Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_TrackID;
			}
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_TrackID[i]    , &u8_SignalValue);

			/*StaticObj_Position_X :FC_StaticObj1_Dx*/
			u16_SignalValue = (uint16) (Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_Position_X /100.0f / 0.2f);
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_Dx[i]    , &u16_SignalValue);

			/*StaticObj_Position_X :FC_StaticObj1_Dy*/
			u16_SignalValue = (uint16) ((Sdc_J3_PerceptionData.LM.StaticObj_Data[i].StaticObj_Data_Layout.StaticObj_Position_Y/100.0f + 51u) / 0.05f); 
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_Dy[i]    , &u16_SignalValue);
		}
		else
		{
			u8_SignalValue = 0x00;
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_Type[i]    , &u8_SignalValue);
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_LaneAssi[i]    , &u8_SignalValue);
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_TrackID[i]    , &u8_SignalValue);
			u16_SignalValue = 0x00;
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_Dx[i]    , &u16_SignalValue);
			(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_StaticObj_Dy[i]    , &u16_SignalValue);
		}
	}

	//add by yf at 22.10.12
	/*****************************Pole Data**********************************/
	/*Pole_Detected*/
	u8_SignalValue = Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.Pole1Detected_Flag;
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Pole1_Detected_407T   , &u8_SignalValue);

	u8_SignalValue = Sdc_J3_PerceptionData.LM.LM_BBox_DataA.LM_BBox_DataA_Layout.Pole2Detected_Flag;
	(void)Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_Pole2_Detected_407T   , &u8_SignalValue);

	for(i=0;i<2u;i++)
	{
		/*Pole_Dx*/
		u16_SignalValue = (uint16)Sdc_J3_PerceptionData.LM.Pole_Data[i].Pole_Data_Layout.Pole_Dx / 10;
		(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_Pole_Dx[i]    , &u16_SignalValue);

		/*Pole_Dy*/
		u16_SignalValue = (uint16)Sdc_J3_PerceptionData.LM.Pole_Data[i].Pole_Data_Layout.Pole_Dy + 2000;
		(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_Pole_Dy[i]    , &u16_SignalValue);

		/*Pole_LiftAng*/
		u16_SignalValue = (uint16)Sdc_J3_PerceptionData.LM.Pole_Data[i].Pole_Data_Layout.Pole_LiftAng * 100;
		(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_Pole_LiftAng[i]    , &u16_SignalValue);

		/*Pole_Type*/
		u16_SignalValue = (uint16)Sdc_J3_PerceptionData.LM.Pole_DataA[i].Pole_DataA_Layout.Pole_DataType;
		//(void)Com_UpdateShadowSignal(Sdc_ConsigIdList_Tx_FC_Objx_TSR_TFL_TLA_LM_FC_Pole_Type[i]    , &u16_SignalValue);
	}
}
#endif /* #if (SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE == STD_ON)*/

#if (SDC_PERCEPTION_AEB_FLAG_STRUCT_ENABLE == STD_ON)
/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_AEB2CAN
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
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_AEB2CAN(void)
{

}

#endif /* #if (SDC_PERCEPTION_AEB_FLAG_STRUCT_ENABLE == STD_ON)*/

/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_Lane2Rte
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
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Obstance2Rte(void)
{

}



static uint8 Sdc_DataProcess_PerceptionDataConvetOfbAvailable(unsigned char iQuality)
{

    if( (iQuality > 0) && (iQuality <= 100) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static uint8 Sdc_DataProcess_PerceptionDataConvetOfRoadTypeClass(uint8 J3RoadEdgeType)
{
	uint8 LcfRoadEdgeType;
	if(1 == J3RoadEdgeType)
	{
       LcfRoadEdgeType = 8;
	}
	else if (2 == J3RoadEdgeType)
	{
       LcfRoadEdgeType = 9;
	}
	else
	{
	   LcfRoadEdgeType = 0;
	}
	return LcfRoadEdgeType;
}



static void Sdc_DataProcess_LaneCoefficientConvert(uint8 AbIndex,
                           sint16 LaneModelC0,
                           float32 LaneModelC1,
                           float32 LaneModelC2,
                           float32 LaneModelC3)
{
  float32 fLaneModelC0 = (float32)(LaneModelC0 / 100.0);
  float32 C0F,C1F,C2F,C3F;
  float32 fWhlBs = 2.88,fWhlBsSquare = 8.2944,fWhlBsCubic = 23.887872;
  C3F = LaneModelC3;
  C2F = LaneModelC2 + 3 * LaneModelC3 * fWhlBs;
  C1F = LaneModelC1 + 2 * LaneModelC2 * fWhlBs + 3 * LaneModelC3 * fWhlBsSquare;
  C0F = fLaneModelC0 + LaneModelC1 * fWhlBs + LaneModelC2 * fWhlBsSquare + LaneModelC3 * fWhlBsCubic;
  Sdc_Perception_AbdOutputData.asLaneBoundary[AbIndex].sGeometry.sParameters.fDistanceMeter = C0F;
  Sdc_Perception_AbdOutputData.asLaneBoundary[AbIndex].sGeometry.sParameters.fYawAngleRad = -C1F;
  Sdc_Perception_AbdOutputData.asLaneBoundary[AbIndex].sGeometry.sParameters.sClothoidNear.fCurvature = C2F * 2.0f;
  Sdc_Perception_AbdOutputData.asLaneBoundary[AbIndex].sGeometry.sParameters.sClothoidNear.fCurvatureRate = C3F * 6.0f;
}

/**
 * \functions Sdc_DataProcess_RxJ3PerceptionData_Lane2Rte
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
static FUNC(void, RTE_CODE) Sdc_DataProcess_RxJ3PerceptionData_Lane2Rte(void)
{
    uint64 timestamp_offset = 0x00;

	/********************************************Mapping Lane Info to CamLaneInputData****************************************************************/
	/********************************************Use for FctAdauter****************************************************************/
	/*TODO : LaneModelC0*/
	Sdc_Perception_CamLaneInputData.CourseInfo[0].f_Angle = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_CamLaneInputData.CourseInfo[1].f_Angle = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_CamLaneInputData.CourseInfo[2].f_Angle = (float32)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_CamLaneInputData.CourseInfo[3].f_Angle = (float32)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);

	/*TODO : LaneModelC1*/
	Sdc_Perception_CamLaneInputData.CourseInfo[0].CourseInfoSegNear.f_C0 = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC1;
	Sdc_Perception_CamLaneInputData.CourseInfo[1].CourseInfoSegNear.f_C0 = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC1;
	Sdc_Perception_CamLaneInputData.CourseInfo[2].CourseInfoSegNear.f_C0 = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC1;
	Sdc_Perception_CamLaneInputData.CourseInfo[3].CourseInfoSegNear.f_C0 = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC1;

	/*TODO : LaneModelC2*/
	Sdc_Perception_CamLaneInputData.CourseInfo[0].CourseInfoSegNear.f_C1 = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC2;
	Sdc_Perception_CamLaneInputData.CourseInfo[1].CourseInfoSegNear.f_C1 = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC2;
	Sdc_Perception_CamLaneInputData.CourseInfo[2].CourseInfoSegNear.f_C1 = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC2;
	Sdc_Perception_CamLaneInputData.CourseInfo[3].CourseInfoSegNear.f_C1 = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC2;

	/*TODO : LaneModelC3*/
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[0].f_MarkerDist = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneModelC3;
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[1].f_MarkerDist = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneModelC3;
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[2].f_MarkerDist = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneD.data.LaneModelC3;
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[3].f_MarkerDist = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneD.data.LaneModelC3;

	/*TODO : LaneTypeClass*/
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[0].MarkerType = Sdc_DataProcess_PerceptionDataConvetOfMarkerType(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[1].MarkerType = Sdc_DataProcess_PerceptionDataConvetOfMarkerType(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[2].MarkerType = Sdc_DataProcess_PerceptionDataConvetOfMarkerType(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[3].MarkerType = Sdc_DataProcess_PerceptionDataConvetOfMarkerType(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);

	/*TODO : LaneConfidence*/
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[0].u_ExistanceProbability = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[1].u_ExistanceProbability = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[2].u_ExistanceProbability = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_CamLaneInputData.LaneMarkerInfo[3].u_ExistanceProbability = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence;

	/*TODO : uiVersionNumber,Shall be confirmed by Fct*/
	Sdc_Perception_CamLaneInputData.uiVersionNumber = 0x00;

	/*TODO : sSigHeader*/
	Sdc_Perception_CamLaneInputData.sSigHeader.eSigStatus = 0x01;//The signal is valid
	Sdc_Perception_CamLaneInputData.sSigHeader.uiTimeStamp = (uint32)Sdc_J3_PerceptionData.Sync.data.SyncMsg1.ImageTimestamp;
	Sdc_Perception_CamLaneInputData.sSigHeader.uiCycleCounter++;
	Sdc_Perception_CamLaneInputData.sSigHeader.uiMeasurementCounter++;

	/*TODO : Write the Lane data to Rte,use for Fct*/
	// Rte_Write_PP_Sdc_Perception_CamLaneInputData_CamLaneInputData(&Sdc_Perception_CamLaneInputData);
    // Ioc_Write_Ioc_CamLaneInputData(Sdc_Perception_CamLaneInputData);

	/********************************************Mapping Lane Info to AbdOutputData****************************************************************/
	/********************************************Use for LcfAdauter****************************************************************/
	/*TODO : LaneCrossing*/

	/*TODO : LaneMarkColor*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneMarkColor);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneMarkColor);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneMarkColor);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneMarkColor);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneMarkColor);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneMarkColor);
//	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.Left_Cone_Road_Edge.data.LKA_LaneA.data.LaneMarkColor);
//	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sAttributes.eColor = Sdc_DataProcess_PerceptionDataConvetOfLaneMarkerColor(Sdc_J3_PerceptionData.Lane.Left_Cone_Road_Edge.data.LKA_LaneA.data.LaneMarkColor);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sAttributes.eColor = 0U;
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sAttributes.eColor = 0U;

	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sAttributes.eColor = 0U;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sAttributes.eColor = 0U;


#if (SDC_PERCEPTION_J3_LANE_COORDINATE_TRANSFORM == STD_ON)
    //Left lane
    Sdc_DataProcess_LaneCoefficientConvert(2,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC1,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC2,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneModelC3);
    Sdc_DataProcess_LaneCoefficientConvert(8,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC1,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC2,
                           Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneModelC3);
    //Right lane
    Sdc_DataProcess_LaneCoefficientConvert(3,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC1,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC2,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneModelC3);
    Sdc_DataProcess_LaneCoefficientConvert(9,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC1,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC2,
                           Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneModelC3);

    // next left lane
    Sdc_DataProcess_LaneCoefficientConvert(1,
                           Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneModelC0,
                           Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC1,
                           Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC2,
                           Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneD.data.LaneModelC3);

    // next right lane
    Sdc_DataProcess_LaneCoefficientConvert(4,
                           Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneModelC0,
                           Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC1,
                           Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC2,
                           Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneD.data.LaneModelC3);

    //left road edge
	Sdc_DataProcess_LaneCoefficientConvert(0,
                           Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC0,
                           Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC1,
                           Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC2,
                           Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC3);
	
	//right road edge
	Sdc_DataProcess_LaneCoefficientConvert(5,
                           Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC0,
                           Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC1,
                           Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC2,
                           Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC3);

	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.fDistanceMeter = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.fDistanceMeter = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.fYawAngleRad = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.fYawAngleRad = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.sClothoidNear.fCurvature = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.sClothoidNear.fCurvature = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.sClothoidNear.fCurvatureRate = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.sClothoidNear.fCurvatureRate = 0.f;

#else // SDC_PERCEPTION_J3_LANE_COORDINATE_TRANSFORM
	/*TODO : LaneModelC0*/	/*TODO : ConeRoadEdgeModelC0*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sGeometry.sParameters.fDistanceMeter = (float32)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC0 / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.fDistanceMeter = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.fDistanceMeter = 0.f;

	/*TODO : LaneModelC1*/	/*TODO : ConeRoadEdgeModelC1*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sGeometry.sParameters.fYawAngleRad = -(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sGeometry.sParameters.fYawAngleRad = -(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sGeometry.sParameters.fYawAngleRad = -(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sGeometry.sParameters.fYawAngleRad = -(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sGeometry.sParameters.fYawAngleRad = -(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sGeometry.sParameters.fYawAngleRad = -(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sGeometry.sParameters.fYawAngleRad = -(float32)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sGeometry.sParameters.fYawAngleRad = -(float32)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeModelC1);
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.fYawAngleRad = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.fYawAngleRad = 0.f;

	/*TODO : LaneModelC2*/	/*TODO : ConeRoadEdgeModelC2*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sGeometry.sParameters.sClothoidNear.fCurvature = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sGeometry.sParameters.sClothoidNear.fCurvature = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneC.data.LaneModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sGeometry.sParameters.sClothoidNear.fCurvature = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sGeometry.sParameters.sClothoidNear.fCurvature = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneC.data.LaneModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sGeometry.sParameters.sClothoidNear.fCurvature = (Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneC.data.LaneModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sGeometry.sParameters.sClothoidNear.fCurvature = (Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneC.data.LaneModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sGeometry.sParameters.sClothoidNear.fCurvature = (float32)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sGeometry.sParameters.sClothoidNear.fCurvature = (float32)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC2)*2.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.sClothoidNear.fCurvature = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.sClothoidNear.fCurvature = 0.f;

	/*TODO : LaneModelC2*/	/*TODO : ConeRoadEdgeModelC3*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneD.data.LaneModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneD.data.LaneModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneD.data.LaneModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (float32)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC3)*6.0;
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sGeometry.sParameters.sClothoidNear.fCurvatureRate = (float32)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_C.data.RoadEdgeModelC3)*6.0f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.sClothoidNear.fCurvatureRate = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.sClothoidNear.fCurvatureRate = 0.f;

#endif // SDC_PERCEPTION_J3_LANE_COORDINATE_TRANSFORM
	/*TODO : LaneQuality*/
	// Sdc_Perception_AbdOutputData.asLaneBoundary[2].sStatus.iQuality = Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneQuality);
	// Sdc_Perception_AbdOutputData.asLaneBoundary[8].sStatus.iQuality = Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneQuality);
	// Sdc_Perception_AbdOutputData.asLaneBoundary[3].sStatus.iQuality = Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneQuality);
	// Sdc_Perception_AbdOutputData.asLaneBoundary[9].sStatus.iQuality = Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneQuality);
	// Sdc_Perception_AbdOutputData.asLaneBoundary[1].sStatus.iQuality = Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneQuality);
	// Sdc_Perception_AbdOutputData.asLaneBoundary[4].sStatus.iQuality = Sdc_DataProcess_PerceptionDataConvetOfLaneQuality(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneQuality);


	Sdc_Len_to_Left_Lane = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneModelC0 - 188/2; // 188:car's len
	Sdc_Len_to_Right_Lane = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneModelC0 + 188/2; // 188:car's len
	
	Sdc_HostLane_Left_flag = (Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence > 0)?0x01:0x00;
	Sdc_HostLane_Right_flag = (Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence > 0)?0x01:0x00;

	/*****************************available fix value**************************************/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneE.data.LaneParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.RoadEdgeParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sStatus.iQuality = Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.RoadEdgeParsingConfidence;
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sStatus.iQuality = 0;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sStatus.iQuality = 0;

	/****************************TODO Update according to ********************************/
	/*available fix value*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[2].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[8].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[3].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[9].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[1].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[4].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[0].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sStatus.bAvailable = Sdc_DataProcess_PerceptionDataConvetOfbAvailable(Sdc_Perception_AbdOutputData.asLaneBoundary[5].sStatus.iQuality);
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sStatus.bAvailable = 0;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sStatus.bAvailable = 0;

	Sdc_Perception_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[0] = Sdc_Perception_AbdOutputData.asLaneBoundary[2].sStatus.bAvailable?2:-1;
	Sdc_Perception_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[1] = Sdc_Perception_AbdOutputData.asLaneBoundary[1].sStatus.bAvailable?1:-1;
	Sdc_Perception_AbdOutputData.sLaneInformation.aiLaneBoundariesLeft[2] = Sdc_Perception_AbdOutputData.asLaneBoundary[0].sStatus.bAvailable?0:-1;
	Sdc_Perception_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[0] = Sdc_Perception_AbdOutputData.asLaneBoundary[3].sStatus.bAvailable?3:-1;
	Sdc_Perception_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[1] = Sdc_Perception_AbdOutputData.asLaneBoundary[4].sStatus.bAvailable?4:-1;
	Sdc_Perception_AbdOutputData.sLaneInformation.aiLaneBoundariesRight[2] = Sdc_Perception_AbdOutputData.asLaneBoundary[5].sStatus.bAvailable?5:-1;


	if(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneD.data.LaneExtraNearPointType == 1)
		{
			Sdc_Perception_AbdOutputData.sLaneInformation.sEventRight.eLaneEventType = 1;
			Sdc_Perception_AbdOutputData.sLaneInformation.sEventRight.fEventDist =sqrt(pow(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosX,2) + pow(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosY,2));
		}
		else if (Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneD.data.LaneExtraNearPointType == 1)
		{
			Sdc_Perception_AbdOutputData.sLaneInformation.sEventRight.eLaneEventType = 1;
			Sdc_Perception_AbdOutputData.sLaneInformation.sEventRight.fEventDist =sqrt(pow(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosX,2) + pow(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneE.data.LaneExtraNearPointPosY,2));
		}
		else
		{
			//TODO Right_Outer 
		}

	/*TODO : LaneTypeClass*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(2, Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(8, Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(3, Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(9, Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(1, Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfLaneTypeClass(4, Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfRoadTypeClass(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_A.data.RoadEdgeTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sAttributes.sType.eType = Sdc_DataProcess_PerceptionDataConvetOfRoadTypeClass(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_A.data.RoadEdgeTypeClass);
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sAttributes.sType.eType = 0U;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sAttributes.sType.eType = 0U;

	/*TODO : LaneViewRangeEnd*/	/*ConeRoadEdgeViewRangeEnd*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneB.data.LaneViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneB.data.LaneViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneB.data.LaneViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneB.data.LaneViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.Left_Road_Edge.data.RoadEdge_B.data.RoadEdgeViewRangeEnd/ 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = (float32)(Sdc_J3_PerceptionData.Lane.Right_Road_Edge.data.RoadEdge_B.data.RoadEdgeViewRangeEnd / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.sClothoidNear.fValidLengthMeter = 0.f;

	/*TODO : LaneWidthMarking*/
	Sdc_Perception_AbdOutputData.asLaneBoundary[2].sGeometry.sParameters.fWidthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneWidthMarking / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[8].sGeometry.sParameters.fWidthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Left_Lane.data.LKA_LaneA.data.LaneWidthMarking / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[3].sGeometry.sParameters.fWidthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneWidthMarking / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[9].sGeometry.sParameters.fWidthMeter = (float32)(Sdc_J3_PerceptionData.Lane.LKA_Right_Lane.data.LKA_LaneA.data.LaneWidthMarking / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[1].sGeometry.sParameters.fWidthMeter = (float32)(Sdc_J3_PerceptionData.Lane.Next_Left_Lane.data.LKA_LaneA.data.LaneWidthMarking / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[4].sGeometry.sParameters.fWidthMeter = (float32)(Sdc_J3_PerceptionData.Lane.Next_Right_Lane.data.LKA_LaneA.data.LaneWidthMarking / 100.0);
	Sdc_Perception_AbdOutputData.asLaneBoundary[0].sGeometry.sParameters.fWidthMeter = 0.2f; //No input value
	Sdc_Perception_AbdOutputData.asLaneBoundary[5].sGeometry.sParameters.fWidthMeter = 0.2f; //No input value
	Sdc_Perception_AbdOutputData.asLaneBoundary[6].sGeometry.sParameters.fWidthMeter = 0.f;
	Sdc_Perception_AbdOutputData.asLaneBoundary[7].sGeometry.sParameters.fWidthMeter = 0.f;

	
	/*TODO : uiVersionNumber,Shall be confirmed by Lcf*/
	// Sdc_Perception_AbdOutputData.uiVersionNumber = 0x00;
	Sdc_Perception_AbdOutputData.uiVersionNumber = 0x02;  //defined from Bench Test
	/*TODO : sSigHeader */
	Sdc_Perception_AbdOutputData.sSigHeader.eSigStatus = 0x01;//The signal is valid

    SpiSync_Core_GetTimestampOffset(&timestamp_offset);
	Sdc_Perception_AbdOutputData.sSigHeader.uiTimeStamp = (uint32)(uint32)((uint64)Sdc_J3_PerceptionData.Sync.data.SyncMsg1.ImageTimestamp - timestamp_offset / 1000000);//ms
    
	Sdc_Perception_AbdOutputData.sSigHeader.uiCycleCounter++;
	Sdc_Perception_AbdOutputData.sSigHeader.uiMeasurementCounter++;

	/*TODO : Write the lane data to Rte,Use for Lcf*/
	Rte_Write_PP_Sdc_Perception_AbdOutputData_AbdOutputData_t(&Sdc_Perception_AbdOutputData);
}

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"




