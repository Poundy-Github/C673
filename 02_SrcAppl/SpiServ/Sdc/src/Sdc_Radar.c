/* ==================[Includes]=============================================== */
#include "Sdc_Radar.h"
#include "Sdc_Radar_Type.h"
#include "Sdc_Core.h"
#include "Com.h"
#include "Sdc_Can_SignalGroup_Variable_Radar.h"
#include "SpiSync_Core.h"
#include "algo_service_types.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

u_Sdc_Radar_ObjectList_t	Sdc_Radar_ObjectList;

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[macros]=================================================*/
#define SDC_MEAS_ADDR_RADAR_OBJECT			(0xB0000000u)
#define __PDO__

#ifdef __PDO__
/****** Sdc ******/
/*! @VADDR: SDC_MEAS_ADDR_RADAR_OBJECT 		@CYCLEID: CycleId_110 */
typedef u_Sdc_Radar_ObjectList_t Sdc_Radar_Object;

#endif

/*==================[internal function declarations]========================*/



/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

/**
 * \functions Sdc_Radar_InitFunction
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
FUNC(void, RTE_CODE) Sdc_Radar_InitFunction(void)
{
    memset(&Sdc_Radar_ObjectList, 0, sizeof(u_Sdc_Radar_ObjectList_t));
}

/**
 * \functions Sdc_Radar_DeInitFunction
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
FUNC(void, RTE_CODE) Sdc_Radar_DeInitFunction(void)
{
    //TODO
}

/**
 * \functions Sdc_Radar_MainFunction
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
FUNC(void, RTE_CODE) Sdc_Radar_MainFunction(void)
{
	uint64 time_stamp = 0;
	uint8 i = 0x00;
	uint8 signal_value_u8 = 0x00;
	uint16 signal_value_u16 = 0x00;
	uint32 signal_value_u32 = 0x00;
    uint64 timestamp_offset = 0x00;

	/*TODO : get time stamp*/
	Time_GetTimeStampMs(&time_stamp);

	/*TODO : Read radar data from Cpr*/
#if 0
	//Use for Test
	Sdc_Radar_ObjectList.raw[0] = 0x00;
	Sdc_Radar_ObjectList.raw[1] = 0x01;
	Sdc_Radar_ObjectList.raw[2] = 0x02;
	Sdc_Radar_ObjectList.raw[3] = 0x03;
	Sdc_Radar_ObjectList.raw[4] = 0x04;
	Sdc_Radar_ObjectList.raw[5] = 0x05;
	Sdc_Radar_ObjectList.raw[6] = 0x06;
	Sdc_Radar_ObjectList.raw[7] = 0x07;
	Sdc_Radar_ObjectList.raw[8] = 0x08;
	Sdc_Radar_ObjectList.raw[9] = 0x09;

	Sdc_Radar_ObjectList.raw[1805] = 0x55;
	Sdc_Radar_ObjectList.raw[1806] = 0x55;
	Sdc_Radar_ObjectList.raw[1807] = 0x55;
#else
	/*TODO : Object_TrackId*/  //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Track_ID[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Track_ID[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_TrackId = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_TrackAge*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Track_Age[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Track_Age[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_TrackAge = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_ClassConf*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_ClassConf[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_ClassConf[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_ClassConf = signal_value_u8 * 2;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Class*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Class[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Class[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Class = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Valid*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_valid[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_valid[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Valid = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Dx*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Dx[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Dx[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Dx = (sint32)((signal_value_u16 * 0.0625 - 100) * 100);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Dx_Vnce*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Dx_Vnce[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Dx_Vnce[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Dx_Vnce = signal_value_u16 * 0.05;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Dy*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Dy[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Dy[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Dy = (sint16)((signal_value_u16 * 0.125 - 128) * 100);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object Dy_Vnce*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Dy_Vnce[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Dy_Vnce[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Dy_Vnce = (float32)((signal_value_u16 * 0.02));
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Height*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Height[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Height[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Height = signal_value_u16;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_HeadingAngle*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_HeadingAngle[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_HeadingAngle[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_HeadingAngle=(float32)(signal_value_u16*0.01-3.14);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_ExistProb*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_ExistProb[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_ExistProb[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_ExistProb = (uint8)(signal_value_u8 * 2);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_ObstacleProb*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_ObstacleProb[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_ObstacleProb[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_ObstacleProb = (uint8)(signal_value_u8 * 2);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Length*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Length[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Length[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Length = (uint16)(signal_value_u16 * 5);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Location*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Location[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Location[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Location = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Measured*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Measured[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Measured[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Measured = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_MotionStatus*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_MotionStatus[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_MotionStatus[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_MotionStatus = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_MotionStatusConf*/  //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_MotionStatusConf[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_MotionStatusConf[i], &signal_value_u8);
		    Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_MotionStatusConf = signal_value_u8*2;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Width*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Width[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Width[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Width = signal_value_u16;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_RelAx*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_RelAx[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_RelAx[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_RelAx = (float32)(signal_value_u16 * 0.03125 - 16);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_RelAy*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_RelAy[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_RelAy[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_RelAy = (float32)(signal_value_u16 * 0.0625 - 16);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_RelVx*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_RelVx[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_RelVx[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_RelVx = (float32)(signal_value_u16 * 0.0625 - 128);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_RelVx_std*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_RelVx_std[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_RelVx_std[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_RelVx_std = (float32)(signal_value_u16 * 0.0625);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_RelVy*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_RelVy[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_RelVy[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_RelVy = (float32)(signal_value_u16 * 0.125 - 64);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_RelVy_std*/ //OK
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_RelVy_std[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_RelVy_std[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_RelVy_std = (float32)(signal_value_u16 * 0.125);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_FeaturePoint*/ //OK Add dbc V3.4.1 
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_FeaturePoint[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_FeaturePoint[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_FeaturePoint = signal_value_u8;
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Vx*/ //OK  Add dbc V3.4.1 
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Vx[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Vx[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Vx = (float32)(signal_value_u16 * 0.2 - 51);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Vy*/ //OK  Add dbc V3.4.1 
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Vy[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Vy[i], &signal_value_u16);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Vy = (float32)(signal_value_u16 * 0.2 - 51);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Ax*/ //OK  Add dbc V3.4.1 
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Ax[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Ax[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Ax = (float32)(signal_value_u8 * 0.2 - 13);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}

	/*TODO : Object_Ay*/ //OK  Add dbc V3.4.1 
	for(i = 0x00 ; i < SDC_RX_RADAR_OBJECT_NUMBER; i++)
	{
		if(0x00 != Sdc_ConsigIdList_Rx_FR_OBJx_Ay[i])
		{
			(void)Com_ReceiveSignal(Sdc_ConsigIdList_Rx_FR_OBJx_Ay[i], &signal_value_u8);
			Sdc_Radar_ObjectList.data.ObjectData[i].data.Object_Ay = (float32)(signal_value_u8 * 0.2 - 13);
		}
		else
		{
			/*TODO : doing nothing*/
		}
	}
	/*TODO : Object_FrameTime*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_Frametime_310R, &signal_value_u16);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.Object_FrameTime = (float32)(signal_value_u16 * 0.01);

	/*TODO : Object_Counter*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_ObjCount_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.Object_Counter = signal_value_u8;

	/*TODO : Radar_CalibrationStatus*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_FRadarCalibrationStatus_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.Radar_CalibrationStatus = (uint8)(signal_value_u8);

	/*TODO : Radar_WorkMode*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_WorkMode_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.Radar_WorkMode = (uint8)(signal_value_u8);

	/*TODO : Radar_FailureStatus*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_RadarFailureStatus_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.Radar_FailureStatus = (uint8)(signal_value_u8);
    
	/*TODO : MisAlignment*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_MisAlignment_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.MisAlignment = (uint8)(signal_value_u8);

	/*TODO : Frame_Counter*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_FrameCount_310R, &signal_value_u32);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_A.data.Frame_Counter = (uint8)(signal_value_u32 % 256);

	/*TODO : FR_TiStamp*/
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_TiStamp_312R, &signal_value_u32);
//	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_B.data.time_stamp = (uint64)(signal_value_u32 * 0.0001 * 1000);//ms

    SpiSync_Core_GetTimestampOffset(&timestamp_offset);
	Sdc_Radar_ObjectList.data.ObjectInfomation.ObjectInfo_B.data.time_stamp = (uint64)(signal_value_u32 / 10.0) + timestamp_offset / 1000000;//ms


	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_WorkMode_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectCrc.data.radar_mode = (uint8)(signal_value_u8);

	/*TODO : KidRushoutFlag  Add dbc V3.4.1 */
	(void)Com_ReceiveSignal(ComConf_ComSignal_SGFR_KidRushoutFlag_310R, &signal_value_u8);
	Sdc_Radar_ObjectList.data.ObjectCrc.data.KidRushoutFlag = (uint8)(signal_value_u8);
	// Sdc_Write_VehDynData.data.SigHeader.data.flag_changing = (uint8)(FC_Workmode);
#endif
	/*TODO : Call API send data to SPI service*/
	// now cycle send to j3

	(void)MTSI_DriverStartTaskCycle(110);
	AS_t_MeasInfo meas_info;
	meas_info.VirtualAddress = SDC_MEAS_ADDR_RADAR_OBJECT;
	meas_info.Length = sizeof(u_Sdc_Radar_ObjectList_t);
	meas_info.FuncID = 110;
	MEASFreezeDataMTS(&meas_info, &Sdc_Radar_ObjectList, NULL_PTR);

}


#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

/*==================[internal function definitions]=========================*/


