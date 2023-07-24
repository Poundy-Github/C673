/* ==================[Includes]=============================================== */
#include "Sdc_Fusion.h"
#include "Sdc_Fusion_Type.h"
#include "Sdc_Core_Type.h"
#include "Time.h"
#include "Rte_Type.h"
#include "Rte_Sdc.h"
#include "Rte_Algo_Type.h"
#include "sfl_ext.h"
/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

static e_Sdc_UpdatedFlag_t Sdc_Cemout_UpdatedFlag = e_Sdc_UpdatedFlag_None;
static List_Object_Reduced_t Sdc_Cemdata;
static EM_t_GenObjectList Sdc_GenObjectList;
static EM_t_ARSObjectList Sdc_ARSObjectList;
static EM_t_FusionObjectList Sdc_FusionObjectList;

#if (SDC_DEBUG_ENABLE == STD_ON)
static s_Time_RunCycleMeas_t Debug_Sdc_CemOut_ReceivedCycleTime;
#endif

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[macros]=================================================*/
#define SDC_CEMOUT_COORDINATECONVERSION_ENABLE

#ifndef EM_GEN_OBJ_N_SHAPE_AXIS
#define EM_GEN_OBJ_N_SHAPE_AXIS EM_GEN_OBJ_N_SHAPE_POINTS
#endif

#ifndef EGO_REAR_BUMPER_TO_FRONT
#define EGO_REAR_BUMPER_TO_FRONT 3.636f
#endif

/*==================[internal function declarations]========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

static FUNC(void, RTE_CODE) Sdc_Fusion_DataProcess_RxCemData2Rte(void);

#ifdef SDC_CEMOUT_COORDINATECONVERSION_ENABLE
static FUNC(void, RTE_CODE) Sdc_Fusion_CoordinateConversion(EM_t_GenObjectList *const GenObjList);
#endif /* SDC_CEMOUT_COORDINATECONVERSION_ENABLE */

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"


/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

/**
 * \functions Sdc_Fusion_InitFunction
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
FUNC(void, RTE_CODE) Sdc_Fusion_InitFunction(void)
{
    memset(&Sdc_Cemdata, 0, sizeof(List_Object_Reduced_t));
    memset(&Sdc_GenObjectList, 0, sizeof(EM_t_GenObjectList));
    memset(&Sdc_ARSObjectList, 0, sizeof(EM_t_ARSObjectList));
    memset(&Sdc_FusionObjectList, 0, sizeof(EM_t_FusionObjectList));
    Sdc_Cemout_UpdatedFlag = e_Sdc_UpdatedFlag_None;
}

/**
 * \functions Sdc_Fusion_DeInitFunction
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
FUNC(void, RTE_CODE) Sdc_Fusion_DeInitFunction(void)
{
    //TODO
}
/**
 * \functions Sdc_Fusion_MainFunction
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
FUNC(void, RTE_CODE) Sdc_Fusion_MainFunction(void)
{
    if(e_Sdc_UpdatedFlag_Updated == Sdc_Cemout_UpdatedFlag)
	{
		Sdc_Cemout_UpdatedFlag = e_Sdc_UpdatedFlag_NotUpdated;
		Sdc_Fusion_DataProcess_RxCemData2Rte();

		// (void)MTSI_DriverStartTaskCycle(110);

		// AS_t_MeasInfo meas_info;
		// meas_info.VirtualAddress = SDC_MEAS_ADDR_CEM_OUT;
		// meas_info.Length = sizeof(List_Object_Reduced_t);
		// meas_info.FuncID = 110;

		// MEASFreezeDataMTS(&meas_info, &Sdc_Cemdata, NULL_PTR);

		// meas_info.VirtualAddress = SDC_MEAS_ADDR_GENOBJLIST;
		// meas_info.Length = sizeof(EM_t_GenObjectList);
		// meas_info.FuncID = 110;

		// MEASFreezeDataMTS(&meas_info, &Sdc_GenObjectList, NULL_PTR);
	}
	else
	{
		/*TODO : Doing nothing*/
	}
}


FUNC(void, RTE_CODE) Sdc_Fusion_RcvCemDataFromJ3(const uint8 *data, uint16 length)
{
#if (SDC_DEBUG_ENABLE == STD_ON)
    Time_MeasRunCycleTimeMs(&Debug_Sdc_CemOut_ReceivedCycleTime);
#endif

    memcpy(&Sdc_Cemdata, data, length);
    Sdc_Cemout_UpdatedFlag = e_Sdc_UpdatedFlag_Updated;//Updated

}



/*==================[internal function definitions]=========================*/

/**
 * \functions Sdc_Fusion_DataProcess_CemDataConvetOfeSensorSource
 *
 * \brief	Convert the eSensorSource from CEM-SPI to RTE
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
static FUNC(uint8, RTE_CODE) Sdc_Fusion_DataProcess_CemDataConvetOfeSensorSource(uint8 data)
{
	uint8 ret = 0u;

	if(32u == data)
	{
		ret = 16u;
	}
	else if(33u == data)
	{
		ret = 17u;
	}
    else if(1u == data)
    {
        ret = 0x1u;
    }
	else
	{
		ret = 0x00u;
	}

	return ret;
    
}


/**
 * \functions Sdc_Fusion_DataProcess_RxCemData2Rte
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
static FUNC(void, RTE_CODE) Sdc_Fusion_DataProcess_RxCemData2Rte(void)
{
	uint64 time_stamp = 0;
	uint8 index = 0x00;
	uint8 index2 = 0x00;

	/*TODO : Updated the variable of Cem releated data to DF*/
    /*20220726 AEB Code Review Add*/
    Sdc_GenObjectList.HeaderObjList.iNumOfUsedObjects = Sdc_Cemdata.header.data.iNumOfUsedObjects;
    
	for(index=0;index < 25;index++)
	{
	    /*20220726 AEB Code Review Add*/
	    Sdc_GenObjectList.HeaderObjList.iSortedObjectList[index]=Sdc_Cemdata.header.data.iSortedObjectList[index];
        Sdc_GenObjectList.aObject[index].General.fLifeTime=Sdc_Cemdata.data[index].General.data.fLifeTime;
        Sdc_GenObjectList.aObject[index].General.uiLifeCycles=Sdc_Cemdata.data[index].General.data.uiLifeCycles;
		/*
            #define ODOBJ_MT_STATE_DELETED  (0U)
            #define ODOBJ_MT_STATE_NEW  (1U)
            #define ODOBJ_MT_STATE_MEASURED  (2U)
            #define ODOBJ_MT_STATE_PREDICTED  (3U)
            #define ODOBJ_MT_STATE_EMPTY  (4U)
        */
		Sdc_GenObjectList.aObject[index].General.eMaintenanceState = (Sdc_Cemdata.data[index].General.data.eMaintenanceState<5u)? \
		                                                             Sdc_Cemdata.data[index].General.data.eMaintenanceState:4u;
        Sdc_GenObjectList.aObject[index].General.eSensorSource = Sdc_Fusion_DataProcess_CemDataConvetOfeSensorSource(Sdc_Cemdata.data[index].General.data.sensorBitfield);
        /*TBD*/
        //Sdc_ARSObjectList.aObject[index].SensorSpecific.ucMeasuredSources = Sdc_Fusion_DataProcess_CemDataConvetOfeSensorSource(Sdc_Cemdata.data[index].General.data.sensorBitfield);
        
        /*ACC & AEB not used ,set 0*/
        Sdc_GenObjectList.aObject[index].General.eSplitMergeState = 0u;/*Sdc_Cemdata.data[index].General.data.eSplitMergeState*/

        Sdc_GenObjectList.aObject[index].Geometry.aShapePointStates[0u]=Sdc_Cemdata.data[index].General.data.aShape01;
        Sdc_GenObjectList.aObject[index].Geometry.aShapePointStates[1u]=Sdc_Cemdata.data[index].General.data.aShape02;
        Sdc_GenObjectList.aObject[index].Geometry.aShapePointStates[2u]=Sdc_Cemdata.data[index].General.data.aShape03;
        Sdc_GenObjectList.aObject[index].Geometry.aShapePointStates[3u]=Sdc_Cemdata.data[index].General.data.aShape04;

		Sdc_GenObjectList.aObject[index].General.uiMergeID = 255;
        Sdc_GenObjectList.aObject[index].General.uiSplitID = 255;
		Sdc_GenObjectList.aObject[index].General.uiID = Sdc_Cemdata.data[index].General.data.uiID;
		Sdc_GenObjectList.aObject[index].General.uiChildID = Sdc_Cemdata.data[index].General.data.childID;

        Sdc_GenObjectList.aObject[index].Attributes.eClassification=(Sdc_Cemdata.data[index].General.data.eClassification>9u)?\
                                                                11u:Sdc_Cemdata.data[index].General.data.eClassification;
        
        Sdc_ARSObjectList.aObject[index].Attributes.eClassification=(Sdc_Cemdata.data[index].General.data.eClassification>7u)?\
                                                                7u:Sdc_Cemdata.data[index].General.data.eClassification;
        
        Sdc_GenObjectList.aObject[index].Attributes.eDynamicProperty = Sdc_Cemdata.data[index].General.data.eDynamicProperty;
        Sdc_ARSObjectList.aObject[index].MotionAttributes.eDynamicProperty = (Sdc_Cemdata.data[index].General.data.eDynamicProperty<=2u)?\
                                                                            Sdc_Cemdata.data[index].General.data.eDynamicProperty:1u;
        Sdc_ARSObjectList.aObject[index].MotionAttributes.eDynamicSubProperty = ((Sdc_Cemdata.data[index].General.data.eDynamicProperty==3u)||\
                                                                                (Sdc_Cemdata.data[index].General.data.eDynamicProperty==4u))?1u:0u;

        Sdc_GenObjectList.aObject[index].Attributes.uiClassConfidence  = Sdc_Cemdata.data[index].General.data.uiClassConfidence;
        Sdc_ARSObjectList.aObject[index].Attributes.uiClassConfidence = Sdc_Cemdata.data[index].General.data.uiClassConfidence;

        Sdc_GenObjectList.aObject[index].Attributes.uiDynConfidence = Sdc_Cemdata.data[index].General.data.uiDynConfidence;
        
        Sdc_ARSObjectList.aObject[index].MotionAttributes.uiStoppedConfidence = (Sdc_Cemdata.data[index].General.data.eDynamicProperty==6u)?\
                                                                        Sdc_Cemdata.data[index].General.data.uiDynConfidence:0u;
        Sdc_GenObjectList.aObject[index].Qualifiers.uiProbabilityOfExistence = Sdc_Cemdata.data[index].General.data.uiProbabilityOfExistence;

        /*TBD*/
        Sdc_ARSObjectList.aObject[index].Geometry.fOrientation = Sdc_Cemdata.data[index].General.data.fYaw;

        Sdc_GenObjectList.aObject[index].Kinematic.fDistX    = Sdc_Cemdata.data[index].kinematic.data.fDistX    ;      
        Sdc_GenObjectList.aObject[index].Kinematic.fDistXStd = Sdc_Cemdata.data[index].kinematic.data.fDistXStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fDistY    = Sdc_Cemdata.data[index].kinematic.data.fDistY    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fDistYStd = Sdc_Cemdata.data[index].kinematic.data.fDistYStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVrelX    = Sdc_Cemdata.data[index].kinematic.data.fVrelX    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVrelXStd = Sdc_Cemdata.data[index].kinematic.data.fVrelXStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVrelY    = Sdc_Cemdata.data[index].kinematic.data.fVrelY    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVrelYStd = Sdc_Cemdata.data[index].kinematic.data.fVrelYStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fArelX    = Sdc_Cemdata.data[index].kinematic.data.fArelX    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fArelXStd = Sdc_Cemdata.data[index].kinematic.data.fArelXStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fArelY    = Sdc_Cemdata.data[index].kinematic.data.fArelY    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fArelYStd = Sdc_Cemdata.data[index].kinematic.data.fArelYStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVabsX    = Sdc_Cemdata.data[index].kinematic.data.fVabsX    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVabsXStd = Sdc_Cemdata.data[index].kinematic.data.fVabsXStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVabsY    = Sdc_Cemdata.data[index].kinematic.data.fVabsY    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fVabsYStd = Sdc_Cemdata.data[index].kinematic.data.fVabsYStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fAabsX    = Sdc_Cemdata.data[index].kinematic.data.fAabsX    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fAabsXStd = Sdc_Cemdata.data[index].kinematic.data.fAabsXStd ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fAabsY    = Sdc_Cemdata.data[index].kinematic.data.fAabsY    ;   
        Sdc_GenObjectList.aObject[index].Kinematic.fAabsYStd = Sdc_Cemdata.data[index].kinematic.data.fAabsYStd ;   


		for(index2 = 0;index2 < 4;index2++)
		{
			Sdc_GenObjectList.aObject[index].Geometry.aShapePointCoordinates[index2].fPosX = Sdc_Cemdata.data[index].shapePoints.data[index2].Coordinates_fPosX;
			Sdc_GenObjectList.aObject[index].Geometry.aShapePointCoordinates[index2].fPosY = Sdc_Cemdata.data[index].shapePoints.data[index2].Coordinates_fPosY;
		}

		/*CEM_ObjClass*/
        /*20220726 AEB Code Review delete*/
		//Sdc_GenObjectList.aObject[index].Qualifiers.eEbaObjClass = Sdc_Cemdata.data[index].General.data.eClassification;


		/*TODO : Updated FusionObjectList related  data*/
		Sdc_FusionObjectList.aObject[index].uiSensorConfirmation[0] = 100;//Confirmed by DF,set to const value


		/****************************
		if raw == 0=UNKNOWN, phys = EM_CAM_OBJ_ASSOC_LANE_UNKNOWN 0U
		if raw == 1=LEFT_LEFT, phys = EM_CAM_OBJ_ASSOC_LANE_EGO 1U
		if raw == 2=LEFT, phys = EM_CAM_OBJ_ASSOC_LANE_LEFT 2U
		if raw == 3=HOST, phys = EM_CAM_OBJ_ASSOC_LANE_RIGHT 3U
		if raw == 4=RIGHT , phys = EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT 4U
		if raw == 5=RIGHT_RIGHT, phys = EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT 5U
		****************************/
		switch(Sdc_Cemdata.data[index].General.data.eAssociatedLane[0])
		{
			case 0: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 0; break;			//0 - 0

			case 1: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 1; break;			//1 - 1

			case 2: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 2; break;			//2 - 2

			case 3: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 3; break;			//3 - 3

			case 4: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 4; break;			//4 - 4

			case 5: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 5; break;			//5 - 5

			case 255: Sdc_FusionObjectList.aObject[index].CamData.eAssociatedLane = 255; break;		//255 - 255
							
			default:	break;
		}

		/*Debug Info : Output via Can Bus*/
#if (DBG_SDC_INTEGRATION_TEST_ENABLE == STD_ON)
		//Sdc_GenObjectList.aObject[index].General.uiLifeCycles = 6;
		//Sdc_GenObjectList.aObject[index].General.fLifeTime = 100;

		if( (Sdc_GenObjectList.aObject[index].Attributes.uiClassConfidence > 80 ) && 
			(Sdc_GenObjectList.aObject[index].Qualifiers.uiProbabilityOfExistence > 20 ) &&
			// () /*uiLifeCycles check*/|| 
			((Sdc_GenObjectList.aObject[index].General.eMaintenanceState != 0) && (Sdc_GenObjectList.aObject[index].General.eMaintenanceState != 4)) && 
			(Sdc_GenObjectList.aObject[index].General.eSensorSource == 17))
		{
			Debug_AEBFlag1[index] = 0x01;
		}
		else
		{
			Debug_AEBFlag1[index] = 0x00;
		}

		//bit0
		if(Sdc_GenObjectList.aObject[index].Attributes.uiClassConfidence > 80)
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] | 0x01;
		}
		else
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] & (~0x01);
		}
		
		//bit1
		if(Sdc_GenObjectList.aObject[index].Qualifiers.uiProbabilityOfExistence > 20)
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] | 0x02;
		}
		else
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] & (~0x02);
		}

		//bit2
		if(Sdc_GenObjectList.aObject[index].General.eMaintenanceState != 0)
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] | 0x04;
		}
		else
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] & (~0x04);
		}

		//bit3
		if(Sdc_GenObjectList.aObject[index].General.eMaintenanceState != 4)
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] | 0x08;
		}
		else
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] & (~0x08);
		}

		//bit4
		if(Sdc_GenObjectList.aObject[index].General.eSensorSource == 17)
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] | 0x10;
		}
		else
		{
			Debug_AEBFlag1_BitFill[index] = Debug_AEBFlag1_BitFill[index] & (~0x10);
		}

		if( (Sdc_GenObjectList.aObject[index].Kinematic.fVabsX < 1.0) &&
			(Sdc_GenObjectList.aObject[index].Kinematic.fVabsY < 1.0) &&
			(Sdc_GenObjectList.aObject[index].Kinematic.fAabsX < 1.0) && 
			(Sdc_GenObjectList.aObject[index].Kinematic.fAabsY < 1.0) &&
			((Sdc_GenObjectList.aObject[index].Kinematic.fDistY > -1.2) && (Sdc_GenObjectList.aObject[index].Kinematic.fDistY < 1.2)) &&
			((0X01 == Sdc_GenObjectList.aObject[index].Attributes.eDynamicProperty) || (0X06 == Sdc_GenObjectList.aObject[index].Attributes.eDynamicProperty) ) && 
			(0X01 == Sdc_GenObjectList.aObject[index].Attributes.eClassification))
		{
			Debug_AEBFlag2[index] = 0x01;
		}
		else
		{
			Debug_AEBFlag2[index] = 0x00;
		}

		//bit0
		if(Sdc_GenObjectList.aObject[index].Kinematic.fVabsX < 1.0)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x01;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x01);
		}

		//bit1
		if(Sdc_GenObjectList.aObject[index].Kinematic.fVabsY < 1.0)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x02;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x02);
		}

		//bit2
		if(Sdc_GenObjectList.aObject[index].Kinematic.fAabsX < 1.0)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x04;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x04);
		}

		//bit3
		if(Sdc_GenObjectList.aObject[index].Kinematic.fAabsY < 1.0)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x08;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x08);
		}

		//bit4
		if(Sdc_GenObjectList.aObject[index].Kinematic.fDistY > -1.2)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x10;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x10);
		}

		//bit5
		if(Sdc_GenObjectList.aObject[index].Kinematic.fDistY < 1.2)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x20;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x20);
		}

		//bit6
		if((0X01 == Sdc_GenObjectList.aObject[index].Attributes.eDynamicProperty) || (0X06 == Sdc_GenObjectList.aObject[index].Attributes.eDynamicProperty))
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x40;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x40);
		}

		//bit7
		if(0X01 == Sdc_GenObjectList.aObject[index].Attributes.eClassification)
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] | 0x80;
		}
		else
		{
			Debug_AEBFlag2_BitFill[index] = Debug_AEBFlag2_BitFill[index] & (~0x80);
		}

		/*Temp Fixed : Fixed incorrect coordinate*/
		// Sdc_GenObjectList.aObject[index].Kinematic.fDistX = (Sdc_GenObjectList.aObject[index].Kinematic.fDistX - 4);

		Debug_CemOut_uiID[index] = Sdc_GenObjectList.aObject[index].General.uiID;
		Debug_CemOut_Dx[index] = (sint8)(Sdc_GenObjectList.aObject[index].Kinematic.fDistX);
#endif

	}

#ifdef SDC_CEMOUT_COORDINATECONVERSION_ENABLE
	/*TODO : Coordinate Conversion */
	Sdc_Fusion_CoordinateConversion(&Sdc_GenObjectList);
	// Sdc_CemOut_PreProcessEBAObjectQuality(&Sdc_GenObjectList);
#endif
	Time_GetTimeStampMs(&time_stamp);

	Sdc_GenObjectList.uiVersionNumber = 131083;//The version numer from Lcf
	Sdc_GenObjectList.sSigHeader.eSigStatus = 1;
	Sdc_GenObjectList.sSigHeader.uiCycleCounter++;
	Sdc_GenObjectList.sSigHeader.uiMeasurementCounter++;
	Sdc_GenObjectList.sSigHeader.uiTimeStamp = (uint32)time_stamp;

	Sdc_ARSObjectList.uiVersionNumber = 4;
	Sdc_ARSObjectList.sSigHeader.eSigStatus = 1;
	Sdc_ARSObjectList.sSigHeader.uiCycleCounter++;
	Sdc_ARSObjectList.sSigHeader.uiMeasurementCounter++;
	Sdc_ARSObjectList.sSigHeader.uiTimeStamp = (uint32)time_stamp;

	Sdc_FusionObjectList.uiVersionNumber = 2;/*Shall confirmed by DF*/
	Sdc_FusionObjectList.sSigHeader.eSigStatus = 1;
	Sdc_FusionObjectList.sSigHeader.uiCycleCounter++;
	Sdc_FusionObjectList.sSigHeader.uiMeasurementCounter++;
	Sdc_FusionObjectList.sSigHeader.uiTimeStamp = (uint32)time_stamp;


	Rte_Write_Sdc_PP_Sdc_Cem_GenObjectList_GenObjectList(&Sdc_GenObjectList);
    //Ioc_Write_Ioc_GenObjectList(Sdc_GenObjectList);
	Rte_Write_Sdc_PP_Sdc_Cem_ARSObjectList_ARSObjectList(&Sdc_ARSObjectList);
    //Ioc_Write_Ioc_ArsObjectList(Sdc_ARSObjectList);
	Rte_Write_PP_Sdc_Cem_FusionObjectList_FusionObjectList(&Sdc_FusionObjectList);
    //Ioc_Write_Ioc_FusionObjectList(Sdc_FusionObjectList);

}


#ifdef SDC_CEMOUT_COORDINATECONVERSION_ENABLE

static inline FUNC(void, RTE_CODE) Sdc_ShiftShapePointSequence(ObjNumber_t const iObjectIndex,EM_t_GenObjectList *const GenObjList)
{
	EM_t_GenObjGeometry *pCurrObjGeometry =  &(GenObjList->aObject[iObjectIndex].Geometry);
	EM_t_GenObjGeometry aCurrObjGeometry_temp = *pCurrObjGeometry;
	for (uint32 uShapePointNo = 0u; uShapePointNo < (EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
	{
		//uint8  const   uPrev = (uShapePointNo + (((uint8)EM_GEN_OBJ_N_SHAPE_POINTS) - 1u)) % ((uint8)EM_GEN_OBJ_N_SHAPE_POINTS);
		uint32 const   uCurrentPoint = uShapePointNo;
		uint32 const   uNextPonit = (uShapePointNo + (1u)) % ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);

		pCurrObjGeometry->aShapePointStates[uCurrentPoint] 					= aCurrObjGeometry_temp.aShapePointStates[uNextPonit];
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosX 		= aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].fPosX;
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosY 		= aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].fPosY;
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].uiPosXStd   = aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].uiPosXStd;
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].uiPosYStd   = aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].uiPosYStd;
	}
}


static inline FUNC(SFLVector2D_t, RTE_CODE) Sdc_CalculateMinAxisDist(ObjNumber_t const iObjectIndex,EM_t_GenObjectList *const GenObjList)
{
	// float32                      fSumX = 0.f;
	// float32                      fSumY = 0.f;
	uint32                       uShapePointNo = 0u;
	// uint32                       uShapeAxisNo = 0u;
	SFLVector2D_t                sAxisMinDist = {0.f, 0.f};
	SFLVector2D_t				 sAxisDist[EM_GEN_OBJ_N_SHAPE_AXIS];

    EM_t_GenObjGeometry *pCurrObjGeometry = &(GenObjList->aObject[iObjectIndex].Geometry);

	for (uShapePointNo = 0u; uShapePointNo < (EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
	{
		uint32 const  uCurrentPoint = uShapePointNo;
		uint32 const  uNextPonit = (uShapePointNo + (1u)) % ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);

		sAxisDist[uShapePointNo].fX = (pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosX + pCurrObjGeometry->aShapePointCoordinates[uNextPonit].fPosX) / 2.0f;
		sAxisDist[uShapePointNo].fY = (pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosY + pCurrObjGeometry->aShapePointCoordinates[uNextPonit].fPosY) / 2.0f;

		if (uShapePointNo == 0u)
		{
			sAxisMinDist = sAxisDist[uShapePointNo];
		}
		else
		{
			if ((sAxisDist[uShapePointNo].fX) < (sAxisMinDist.fX))
			{
				sAxisMinDist = sAxisDist[uShapePointNo];
			}
			else if ((sAxisDist[uShapePointNo].fX) == (sAxisMinDist.fX))
			{
				if ((sAxisDist[uShapePointNo].fY) < (sAxisMinDist.fY))
				{
					sAxisMinDist = sAxisDist[uShapePointNo];
				}
			}		
		}
	}
	return sAxisMinDist;
}


static inline FUNC(void, RTE_CODE) Sdc_ShiftShapePointCoordinate(ObjNumber_t const iObjectIndex,EM_t_GenObjectList *const GenObjList,\
                                                                                     SFLVector2D_t const sMinDist)
{
	uint32                        uShapePointNo = 0u;
    EM_t_GenObjGeometry *pCurrObjGeometry =  &(GenObjList->aObject[iObjectIndex].Geometry);
	for (uShapePointNo = 0u; uShapePointNo < (EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
	{
		pCurrObjGeometry->aShapePointCoordinates[uShapePointNo].fPosX -= sMinDist.fX;
		pCurrObjGeometry->aShapePointCoordinates[uShapePointNo].fPosY -= sMinDist.fY;
	}
}

static inline FUNC(void, RTE_CODE) Sdc_ShiftObjDistToEgoFrontCenter(ObjNumber_t const iObjectIndex,EM_t_GenObjectList *const GenObjList,\
                                                                                         SFLVector2D_t const sMinDist)
{
    EM_t_GenObjKinematics * pCurrObjKinematics = &(GenObjList->aObject[iObjectIndex].Kinematic);
	pCurrObjKinematics->fDistX = pCurrObjKinematics->fDistX + sMinDist.fX - EGO_REAR_BUMPER_TO_FRONT;
	pCurrObjKinematics->fDistY = pCurrObjKinematics->fDistY + sMinDist.fY;
}

/*Shift coordinate: ego near axis to front bumper, object center to closest axis CEM and ACDC1 platform*/

static FUNC(void, RTE_CODE) Sdc_Fusion_CoordinateConversion(EM_t_GenObjectList *const GenObjList)
{
    ObjNumber_t ObjNr=0u;
	
	/*TODO : Go through all objects, checking if individual criteria pass */
    for (ObjNr = (signed char)(EM_N_OBJECTS - 1); ObjNr >= 0L; ObjNr--)
    {
		if ( !((GenObjList->aObject[ObjNr].General.eMaintenanceState == ODOBJ_MT_STATE_DELETED) || \
                (GenObjList->aObject[ObjNr].General.eMaintenanceState == ODOBJ_MT_STATE_EMPTY)))
		{
			Sdc_ShiftShapePointSequence(ObjNr,GenObjList);

			SFLVector2D_t sMinDist = Sdc_CalculateMinAxisDist(ObjNr,GenObjList);

			Sdc_ShiftShapePointCoordinate(ObjNr,GenObjList, sMinDist);

			Sdc_ShiftObjDistToEgoFrontCenter(ObjNr,GenObjList, sMinDist);
	  	}
	}
}
#endif /* SDC_CEMOUT_COORDINATECONVERSION_ENABLE */

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"




