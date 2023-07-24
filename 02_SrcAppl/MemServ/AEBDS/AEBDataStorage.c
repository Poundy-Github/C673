
/**
 * \file AEBDataStorage.c
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.11.09			Zhang Jianzhou			Init version
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */

#include "AEBDataStorage.h"
#include <Rte_AebDs.h>
#include "string.h"
#include "Cdm.h"
#include "NvM_Cfg.h"
#include "Cps_Cfg.h"
#include "Rte_type.h"
#include "Com_PBcfg.h"
#include "Com.h"
#include "Ioc_gen.h"
#include <NvM.h>
typedef unsigned long long aebuint64;
//begin 0 - 6
typedef struct 
{
	aebuint64   reserved1 : 8;
	aebuint64   pBrake : 8;
	aebuint64   gpPosition  : 8;
	aebuint64   reserved : 3;
	aebuint64   objectState : 3;
	aebuint64   second : 6;
	aebuint64   minute : 6;
	aebuint64   hour   : 5;
	aebuint64   year   : 8;
	aebuint64   month  : 4;
	aebuint64	day    : 5;
}AEBDS_Data0_t;
#if 1
/*begin: byte7*/
typedef struct 
{

uint8   reserve;
sint8	ayvRef; 
sint8	axvRef; 
sint8	vxvRef; 
sint16	alpDtSteeringWheel; 
sint16	alpSteeringWheel; 
	
	
}AEBDS_Data1_t;
//begin: byte14
typedef struct 
{
sint8	vxvMax; 
sint8	vxvRefDiff; 
uint16	tEventDuration; 
sint8	ayvRefMin; 
sint8	ayvRefMax; 
sint8	axvRefMin; 
sint8	axvRefMax; 
sint16	alpDtSteeringWheelMin; 
sint16	alpSteeringWheelMin; 
uint8	pBrakeMin; 
uint8	GPPosMin; 
sint16	alpDtSteeringWheelMax; 
sint16	alpSteeringWheelMax; 
uint8	pBrakeMax; 
uint8	GPPosMax; 
sint8	ayv; 
sint8	axv; 
sint8	vyv; 
sint8	vxv; 
sint8	dyv; 
sint8	dxv; 
sint16	alp64Misalign; //=========================
}AEBDS_Data2_t;
#endif
//begin byte42

typedef struct 
{
uint32  reserved1  : 8; 
uint32	Mileage : 20; 	
uint32  reserved : 2; //
uint32	EspAutomatedBrakingActive : 1;  
uint32	EspBrakeJerkActive  : 1; 
}AEBDS_Data3_t;
//begin byte 45


typedef struct
{
uint16	tEventDurationAtdxvMin; 
sint8	dyvAtdxvMin; 
sint8   dxvMin ; 
	
}AEBDS_Data4_t;
typedef struct 
{
	float32 f32Av;
	float32 f32Min;
	float32 f32Max;
	float32 f32delta;
	float32 f32MinValue1;
	uint32 u32MinValue2;
	uint32 u32Dutime;
	float32* pfValue1;
	float32* pfValue2;
	float32* pf32Sinal;
	uint8 u8State; // 0:idle 1:progress 2:end
}AEBDS_MathInfo_t;
typedef enum
{
	AEBDS_MathSignal_EMS_AccPeda = 0,
	AEBDS_MathSignal_MasCylBrakePressure ,
	AEBDS_MathSignal_SteeringAngle,
	AEBDS_MathSignal_SteeringAngleSpeed,
	AEBDS_MathSignal_LongAccel,
	AEBDS_MathSignal_LatAccel,
	AEBDS_MathSignal_VehicleSpeed,
	AEBDS_MathSignal_AEBTargetRelSpeed,
	AEBDS_MathSignal_AEBTargetLngRange,
	AEBDS_MathSignal_Num,
}AEBDS_MathSignal_e;

typedef struct 
{
	uint8* pu8LastStorage;
	uint8* pu8Storage;
	uint16 u16LastStorageHandle;
	uint16 u16StorageHandle;
	uint8 u8NvmSta;
}AEBDS_StorageInfo_t;

typedef enum
{
	AEBDS_StorageInfoEvent_FCW = 0,
	AEBDS_StorageInfoEvent_AWB ,
	AEBDS_StorageInfoEvent_ATB,
	AEBDS_StorageInfoEvent_Num ,
}AEBDS_StorageInfoEvent_e;


#define AEBDS_MAIN_FUNC_PERIOD_MS  5U


typedef struct 
{
	/* data */
	AEBDS_Data0_t tStorageData0; // 0-6
	AEBDS_Data1_t tStorageData1; // 7-13
	AEBDS_Data2_t tStorageData2; // 14-41
	AEBDS_Data3_t tStorageData3; // 42-44
	AEBDS_Data4_t tStorageData4; // 45-49
}AEBDS_AllData_t;
typedef struct 
{
	boolean blPreviousStatus;
	boolean blStatus;
}AEBDS_EventActiveSta_t;
typedef struct 
{
	AEBDS_MathInfo_t* ptMathSignalTable;
	uint8 u8SingnalLen;
}AEBDS_EventSignalConfig_t;

typedef struct
{
    /* data */
    float32 Cpr_VcuAccrPedlPosn;
    uint16 Cpr_PFSBrakePressure;
    float32 Cpr_EpsSasSteerAg;
    float32 Cpr_EpsSteerAgRate;
    float32 Cpr_EspLongAccel;
    float32 Cpr_EspLatAccel;
    float32 Cpr_EspVehSpd;
    float32 Cpr_EspYawRate;

    float32 Cps_AEBTargetRelSpeed;
    float32 Cps_AEBTargetLatRange;
    float32 Cps_AEBTargetLngRange;
    boolean Cps_FCWActive;
    boolean Cps_AWBActive;
    boolean Cps_AEBActive;
	float32 Cps_AEBTargetAx;
	float32 Cps_AEBTargetLatRelSpeed;
	float32 Cps_AEBTargetAy;
}s_Aebds_SignalData_t;

float32 Cps_SignalPhyData_FC_AEBTargetRelSpeed_data;
s_Aebds_SignalData_t AEBdata;
AEBDS_EventActiveSta_t tEventActiveStatus[AEBDS_StorageInfoEvent_Num];
AEBDS_AllData_t tStorageData[AEBDS_StorageInfoEvent_Num];
static HEADOutputCustom_t AEBDS_HeadOutputCustomData;
static float32 PhyData_VehicleSpeed;
float32 f32Null = 0.0;
float32 Cpr_SignalPhyData_EpsSteerAgRate_float;
float32 Cpr_PFSBrakePressure_float;

AEBDS_MathInfo_t tMathTableFCW[AEBDS_MathSignal_Num]=
{
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_VcuAccrPedlPosn,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_PFSBrakePressure_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EpsSasSteerAg,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_SignalPhyData_EpsSteerAgRate_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLongAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLatAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&PhyData_VehicleSpeed,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cps_SignalPhyData_FC_AEBTargetRelSpeed_data,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&AEBdata.Cps_AEBTargetLatRange,&f32Null,&AEBdata.Cps_AEBTargetLngRange,0},	
	
};
AEBDS_MathInfo_t tMathTableAWB[AEBDS_MathSignal_Num]=
{
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_VcuAccrPedlPosn,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_PFSBrakePressure_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EpsSasSteerAg,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_SignalPhyData_EpsSteerAgRate_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLongAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLatAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&PhyData_VehicleSpeed,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cps_SignalPhyData_FC_AEBTargetRelSpeed_data,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&AEBdata.Cps_AEBTargetLatRange,&f32Null,&AEBdata.Cps_AEBTargetLngRange,0},	
};
AEBDS_MathInfo_t tMathTableATB[AEBDS_MathSignal_Num]=
{
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_VcuAccrPedlPosn,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_PFSBrakePressure_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EpsSasSteerAg,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_SignalPhyData_EpsSteerAgRate_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLongAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLatAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&PhyData_VehicleSpeed,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cps_SignalPhyData_FC_AEBTargetRelSpeed_data,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&AEBdata.Cps_AEBTargetLatRange,&f32Null,&AEBdata.Cps_AEBTargetLngRange,0},	
};
AEBDS_MathInfo_t tMathTableAEBP[AEBDS_MathSignal_Num]=
{
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_VcuAccrPedlPosn,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_PFSBrakePressure_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EpsSasSteerAg,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_SignalPhyData_EpsSteerAgRate_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLongAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLatAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&PhyData_VehicleSpeed,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cps_SignalPhyData_FC_AEBTargetRelSpeed_data,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&AEBdata.Cps_AEBTargetLatRange,&f32Null,&AEBdata.Cps_AEBTargetLngRange,0},	
};
AEBDS_MathInfo_t tMathTableAEBM[AEBDS_MathSignal_Num]=
{
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_VcuAccrPedlPosn,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_PFSBrakePressure_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EpsSasSteerAg,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cpr_SignalPhyData_EpsSteerAgRate_float,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLongAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&AEBdata.Cpr_EspLatAccel,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&PhyData_VehicleSpeed,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&f32Null,&f32Null,&Cps_SignalPhyData_FC_AEBTargetRelSpeed_data,0},
	{0.0,0.0,0.0,0.0,0.0,0,0,&AEBdata.Cps_AEBTargetLatRange,&f32Null,&AEBdata.Cps_AEBTargetLngRange,0},	
};
AEBDS_EventSignalConfig_t tEventSignalConfig[AEBDS_StorageInfoEvent_Num] =
{
	{tMathTableFCW,(uint8)AEBDS_MathSignal_Num},
	{tMathTableAWB,(uint8)AEBDS_MathSignal_Num},
	{tMathTableATB,(uint8)AEBDS_MathSignal_Num},
};

#define AEBDS_SignalMathpT(n) tEventSignalConfig[n].ptMathSignalTable
AEBDS_StorageInfo_t tStorageEventData[AEBDS_StorageInfoEvent_Num] =
{
	{
		RAM_NVM_BLOCK_FCWLastbutoneappearedFD14,
		RAM_NVM_BLOCK_FCWLastappearFD17,
		NvMConf_NvMBlockDescriptor_NVM_BLOCK_FCWLastbutoneappearedFD14,
		NvMConf_NvMBlockDescriptor_NVM_BLOCK_FCWLastappearFD17,	
		0,
	},
	{
		RAM_NVM_BLOCK_AWBLastbutoneappearFD15,
		RAM_NVM_BLOCK_AWBLasteappearFD18,
		NvMConf_NvMBlockDescriptor_NVM_BLOCK_AWBLastbutoneappearFD15,
		NvMConf_NvMBlockDescriptor_NVM_BLOCK_AWBLasteappearFD18,
		0,
	},
	{
		RAM_NVM_BLOCK_AEBLastbutoneappearFD16,
		RAM_NVM_BLOCK_AEBLastappearFD19,
		NvMConf_NvMBlockDescriptor_NVM_BLOCK_AEBLastbutoneappearFD16,
		NvMConf_NvMBlockDescriptor_NVM_BLOCK_AEBLastappearFD19,
		0,
	}
};




static boolean EventCheckActiveFCW(void);
static boolean EventCheckActiveAWB(void);
static boolean EventCheckActiveATB(void);
static boolean EventCheckActiveAEBP(void);
static boolean EventCheckActiveAEBM(void);
static void EventCheckHandle(AEBDS_StorageInfoEvent_e eEventType);
static void EventSignalSnapShot(AEBDS_StorageInfoEvent_e eEventType,uint8 u8Stype);
static void EventDataSotorage(AEBDS_StorageInfoEvent_e eEventType);
static void SetSignalState(AEBDS_StorageInfoEvent_e eEventType, uint8 u8State);
static void MathCalculate(AEBDS_StorageInfoEvent_e eEventType);
static void EventDataRead(AEBDS_StorageInfoEvent_e eEventType,uint8 u8index);
static void EventDataWrite(AEBDS_StorageInfoEvent_e eEventType,uint8 u8index);
#define AEBDS_SetActiveSta(n,m) {tEventActiveStatus[n].blPreviousStatus = tEventActiveStatus[n].blStatus;\
								tEventActiveStatus[n].blStatus = m;}
#define AEBDS_GetActiveSta(n)  	(tEventActiveStatus[n].blStatus)	
#define AEBDS_GetPreActiveSta(n)  	(tEventActiveStatus[n].blPreviousStatus)	
#define IsActiveFCW EventCheckActiveFCW()
#define IsActiveAWB EventCheckActiveAWB()
#define IsActiveATB EventCheckActiveATB()
#define IsActiveAEBP EventCheckActiveATB()
#define IsActiveAEBM EventCheckActiveATB()
#define AEBDS_V12V2(n) (n>5.0 ? (n/0.98 + 2): n)
#define AEBDS_Ang2Rad(n) (n*0.0174532925)
#define AEBDS_Ang2RadSig(n) (n*17.873315)
boolean bltest = FALSE;
static uint8 u8event = 0;
static uint8 u8ReadAll =0;
static void NvmProcess(void)
{

	// if(tStorageEventData[u8event].u8NvmSta == 0)
	// {
	// 	EventDataRead(u8event,0);
	// 	tStorageEventData[u8event].u8NvmSta = 1;
	// }
	// else if (tStorageEventData[u8event].u8NvmSta == 1)
	// {
	// 	EventDataRead(u8event,1);
	// 	tStorageEventData[u8event].u8NvmSta = 2;
				
	// }else if (tStorageEventData[u8event].u8NvmSta == 2)
	// {
	// 	u8event = (u8event+1)%AEBDS_StorageInfoEvent_Num;
	// }
	
	// else if(tStorageEventData[u8event].u8NvmSta == 4)
	// {
	// 	EventDataWrite(u8event,0);
	// 	tStorageEventData[u8event].u8NvmSta = 5;
	// }
	// else if (tStorageEventData[u8event].u8NvmSta == 5)
	// {
	// 	EventDataWrite(u8event,1);
	// 	tStorageEventData[u8event].u8NvmSta = 6;
	// }
	// else if (tStorageEventData[u8event].u8NvmSta == 6)
	// {		
	// 	tStorageEventData[u8event].u8NvmSta = 0;
	// 	u8event = (u8event+1)%AEBDS_StorageInfoEvent_Num;
	// }
}


static void SignalConHandle(void)
{
	PhyData_VehicleSpeed = AEBDS_V12V2(AEBdata.Cpr_EspVehSpd);
	Cps_SignalPhyData_FC_AEBTargetRelSpeed_data = 0 - (AEBdata.Cps_AEBTargetRelSpeed + 0.0001);
}
/**
 * @brief Check FCW active
 * 
 * @return boolean 
 */
static boolean EventCheckActiveFCW(void)
{
	//return bltest>0 ? TRUE:FALSE;
	return AEBdata.Cps_FCWActive>0 ? TRUE:FALSE;
}

/**
 * @brief Check AWB active
 * 
 * @return boolean 
 */
static boolean EventCheckActiveAWB(void)
{
	return AEBdata.Cps_AWBActive>0 ? TRUE:FALSE;
}

static boolean EventCheckActiveATB(void)
{
	return AEBdata.Cps_AEBActive>0 ? TRUE:FALSE;
	//return FALSE;
}
/**
 * @brief Check AEB-P
 * 
 * @return boolean 
 */
static boolean EventCheckActiveAEBP(void)
{
	boolean blRtv = FALSE ;
	IocRead_Ioc_HeadOutputCustom(&AEBDS_HeadOutputCustomData);
	if (AEBdata.Cps_AEBActive == TRUE &&
		(AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 1
	||AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 4
	||AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 6))
	{
		blRtv = TRUE;
	}
	else
	{
		blRtv = FALSE;
	}	
	return blRtv;
}

/**
 * @brief Check AEB-M
 * 
 * @return boolean 
 */
static boolean EventCheckActiveAEBM(void)
{
	boolean blRtv = FALSE ;
	IocRead_Ioc_HeadOutputCustom(&AEBDS_HeadOutputCustomData);
	if (AEBdata.Cps_AEBActive == TRUE &&
		(AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 2
	||AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 3
	||AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 5
	||AEBDS_HeadOutputCustomData.sPreBrake.uPreBrakeLevel == 7))
	{
		blRtv = TRUE;
	}
	else
	{
		blRtv = FALSE;
	}	
	return blRtv;
}


/**
 * @brief Set handle
 * 
 */
static void SetActiveStaHandle(void)
{
	AEBDS_SetActiveSta(AEBDS_StorageInfoEvent_FCW,IsActiveFCW);
	AEBDS_SetActiveSta(AEBDS_StorageInfoEvent_AWB,IsActiveAWB);
	AEBDS_SetActiveSta(AEBDS_StorageInfoEvent_ATB,IsActiveATB);

}

/**
 * @brief Check process
 * 
 * @param eEventType 
 */
static void EventCheckHandle(AEBDS_StorageInfoEvent_e eEventType)
{
	uint8 i;
	static uint16 u16Sta = 0;
	i = (uint8)eEventType;
 	if(	tStorageEventData[eEventType].u8NvmSta == 0)
	{
		if (u16Sta >= 1000)
		{
			/* code */
			//EventDataRead(eEventType,0);
			tStorageEventData[eEventType].u8NvmSta  = 1;
			u16Sta = 0;
		}		
		u16Sta ++;
		
	}
	
	if(AEBDS_GetActiveSta(i) == TRUE 
	&& AEBDS_GetPreActiveSta(i)== FALSE)
	{
		SetSignalState(i,3);
		MathCalculate(i);
		EventSignalSnapShot(i,1);
	}
	else if (AEBDS_GetActiveSta(i) == FALSE 
	&& AEBDS_GetPreActiveSta(i)== TRUE)
	{
	
		SetSignalState(i,2);
		MathCalculate(i);
		EventSignalSnapShot(i,2);
		EventDataSotorage(i);
	}
	else if (AEBDS_GetActiveSta(i) == TRUE 
	&& AEBDS_GetPreActiveSta(i)== TRUE)
	{
		SetSignalState(i,1);
		MathCalculate(i);
	}
	else if (AEBDS_GetActiveSta(i) == FALSE 
	&& AEBDS_GetPreActiveSta(i)== FALSE)
	{
		SetSignalState(i,0);
		MathCalculate(i);	
	}
	else
	{}	
}

void get(void)
{


}

static EM_t_GenObjectList tGenObjectList;
/**
 * @brief 
 * 
 * @param eEventType 
 * @param u8Stype 1:im  2:cal
 */
static void EventSignalSnapShot(AEBDS_StorageInfoEvent_e eEventType,uint8 u8Stype)
{	
	uint8 SnapshotYear = 0;
	uint8 SnapshotMonth = 0;
	uint8 SnapshotDate = 0;
	uint8 SnapshotHour = 0;
	uint8 SnapshotMinute = 0;
	uint8 SnapshotSecond = 0;
	uint8 gpPostion = 0;
	uint8 MasCylBrakePressure = 0;
	sint16 SteeringWheel = 0;
	uint16 SteeringWheelSpeed = 0;
	uint8 u8Index = 0;

  	Std_ReturnType ret_Read;
  	// static HEADOutputCustom_t tOutputCustom;
  	Std_ReturnType ret_Read_0;
	memset(&tGenObjectList,0,sizeof(tGenObjectList));
	// memset(&tOutputCustom,0,sizeof(tOutputCustom));
  	(void)ret_Read;
  	ret_Read = Rte_Read_RP_Sdc_Cem_GenObjectList_GenObjectList(&tGenObjectList);
  	//(void)ret_Read_0;
  	// ret_Read_0 = Rte_Read_RP_FctAdapter_HeadOutputCustomData_HeadOutputCustomData(&tOutputCustom);

	u8Index = AEBDS_HeadOutputCustomData.EDROutput.ObjID;



	if (u8Stype == 1)
	{
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGTboxLocalTiYear_759R,&SnapshotYear);
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGTboxLocalTiMth_759R,&SnapshotMonth);
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGTboxLocalTiDate_759R,&SnapshotDate);
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGTboxLocalTiHr_759R,&SnapshotHour);
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGTboxLocalTiMins_759R,&SnapshotMinute);
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGTboxLocalTiSec_759R,&SnapshotSecond);
		(void)Com_ReceiveSignal(ComConf_ComSignal_SGEpsSasSteerAg_384R,&SteeringWheel);

		//(void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_MasCylBrakePressure_523R,&MasCylBrakePressure);
		MasCylBrakePressure = (uint8)(AEBdata.Cpr_PFSBrakePressure);
		//(void)Com_ReceiveSignal(ComConf_ComSignal_SGEMS_AccPedal_398R,&gpPostion);
		//(void)Com_ReceiveSignal(ComConf_ComSignal_SGSAS_SteeringAngleSpeed_384R,&SteeringWheelSpeed);	
		tStorageData[eEventType].tStorageData0.day     = SnapshotDate;
		tStorageData[eEventType].tStorageData0.month   = SnapshotMonth;
		tStorageData[eEventType].tStorageData0.year    = SnapshotYear - 13;
		tStorageData[eEventType].tStorageData0.hour    = SnapshotHour;
		tStorageData[eEventType].tStorageData0.minute  = SnapshotMinute;
		tStorageData[eEventType].tStorageData0.second  = SnapshotSecond;
		//todo Waiting for system clarification
		switch (tGenObjectList.aObject[u8Index].Attributes.eDynamicProperty)
		{

        // #define EM_GEN_OBJECT_DYN_PROPERTY_MOVING 0U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY 1U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING 2U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT 3U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT 4U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN 5U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_STOPPED 6U
        // #define EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES 7U

			case 0: 
				tStorageData[eEventType].tStorageData0.objectState = 1;// OBJECT_STATE_PRECEDING - 1  need to be classfied
			break;
			case 1:
				tStorageData[eEventType].tStorageData0.objectState = 2;// OBJECT_STATE_STATIONARY - 2
			break;
			case 6:
				tStorageData[eEventType].tStorageData0.objectState = 3;// OBJECT_STATE_STOPPED - 3
			break;
			case 2:
				tStorageData[eEventType].tStorageData0.objectState = 4;// OBJECT_STATE_ONCOMING - 4"
			break;
			default:
				tStorageData[eEventType].tStorageData0.objectState = 0;// OBJECT_STATE_UNDEFINED - 0
			break;
		}

		//todoend
		tStorageData[eEventType].tStorageData0.reserved  = 0;
		tStorageData[eEventType].tStorageData0.gpPosition   = (uint8)(AEBdata.Cpr_VcuAccrPedlPosn);
		tStorageData[eEventType].tStorageData0.pBrake  = MasCylBrakePressure;
		tStorageData[eEventType].tStorageData0.reserved1  = 0;

		tStorageData[eEventType].tStorageData1.alpSteeringWheel =(sint16)(AEBDS_Ang2RadSig(AEBdata.Cpr_EpsSasSteerAg)) ; 	
		tStorageData[eEventType].tStorageData1.alpDtSteeringWheel = (sint16)(AEBDS_Ang2RadSig(AEBdata.Cpr_EpsSteerAgRate)); 
		sint8 VehicleSpeed = 0;
		VehicleSpeed = (sint8)(PhyData_VehicleSpeed/3.6 + 0.1);
		tStorageData[eEventType].tStorageData1.vxvRef = VehicleSpeed; 

		// uint8 axvRef = 0;
		// (void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_LongAccel_632R,&axvRef);
		if(AEBdata.Cpr_EspLongAccel >= 0)
		{
			tStorageData[eEventType].tStorageData1.axvRef = (sint8)(AEBdata.Cpr_EspLongAccel*5 + 0.1); //本车纵向加速度
		}
		else
		{
			tStorageData[eEventType].tStorageData1.axvRef = (sint8)(AEBdata.Cpr_EspLongAccel*5 - 0.1); //本车纵向加速度
		}
		
		// uint8 ayv = 0;
		// (void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_LatAccel_632R,&ayv);
		if(AEBdata.Cpr_EspLatAccel >= 0)
		{
			tStorageData[eEventType].tStorageData1.ayvRef = (sint8)(AEBdata.Cpr_EspLatAccel*5 + 0.1); //本车横向加速度
		}
		else
		{
			tStorageData[eEventType].tStorageData1.ayvRef = (sint8)(AEBdata.Cpr_EpsSasSteerAg*5 - 0.1); //本车横向加速度
		}
		

		// uint16 yawRate = 0;
		// (void)Com_ReceiveSignal(ComConf_ComSignal_SGESP_YawRate_632R,&yawRate);
		tStorageData[eEventType].tStorageData2.alp64Misalign= (sint16)(AEBDS_Ang2Rad(AEBdata.Cpr_EspYawRate)*4) ;//偏差角度

		// uint8 dxv = (uint8)((AEBdata.Cps_AEBTargetLngRange + 70)*2);
		tStorageData[eEventType].tStorageData2.dxv= (sint8)(AEBdata.Cps_AEBTargetLngRange*2);
		// uint8 dyv = (AEBdata.Cps_AEBTargetLatRange+50)*10;
		tStorageData[eEventType].tStorageData2.dyv= (sint8)(AEBdata.Cps_AEBTargetLatRange/0.15);
		//uint8 vxv = (uint8)(Cps_SignalPhyData_FC_AEBTargetRelSpeed + 250);	
		tStorageData[eEventType].tStorageData2.vxv= (sint8)(AEBdata.Cps_AEBTargetRelSpeed/3.6);
		//todo Waiting for system clarification ---finish
		// tStorageData[eEventType].tStorageData2.vyv = tGenObjectList.aObject[u8Index].Kinematic.fVrelY;
		// tGenObjectList.aObject[u8Index].Kinematic.fArelX;
		// tGenObjectList.aObject[u8Index].Kinematic.fArelY;
		
		tStorageData[eEventType].tStorageData2.vyv= (sint8)(AEBdata.Cps_AEBTargetLatRelSpeed);
	
		tStorageData[eEventType].tStorageData2.axv= (sint8)(AEBdata.Cps_AEBTargetAx*10);
		tStorageData[eEventType].tStorageData2.ayv= (sint8)(AEBdata.Cps_AEBTargetAy/0.16);
		//todo_end
	}
	if (u8Stype == 2)
	{
		tStorageData[eEventType].tStorageData2.GPPosMax= (uint8)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_EMS_AccPeda].f32Max);
		tStorageData[eEventType].tStorageData2.pBrakeMax= (uint8)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_MasCylBrakePressure].f32Max);
		tStorageData[eEventType].tStorageData2.alpSteeringWheelMax= (sint16)(AEBDS_Ang2RadSig(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_SteeringAngle].f32Max));
		tStorageData[eEventType].tStorageData2.alpDtSteeringWheelMax= (sint16)(AEBDS_Ang2RadSig(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_SteeringAngleSpeed].f32Max));
		tStorageData[eEventType].tStorageData2.GPPosMin= (uint8)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_EMS_AccPeda].f32Min);
		tStorageData[eEventType].tStorageData2.pBrakeMin= (uint8)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_MasCylBrakePressure].f32Min);
		tStorageData[eEventType].tStorageData2.alpSteeringWheelMin= (sint16)(AEBDS_Ang2RadSig(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_SteeringAngle].f32Min));
		tStorageData[eEventType].tStorageData2.alpDtSteeringWheelMin= (uint16)(AEBDS_Ang2RadSig(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_SteeringAngleSpeed].f32Min));
		tStorageData[eEventType].tStorageData2.tEventDuration= (uint16)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].u32Dutime/20);
		tStorageData[eEventType].tStorageData2.vxvRefDiff= (sint8)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_VehicleSpeed].f32delta*0.925926);
		tStorageData[eEventType].tStorageData2.vxvMax= (sint8)(0 - tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_AEBTargetRelSpeed].f32Max / 3.6);
		
		if(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LongAccel].f32Max >= 0)
		{
			tStorageData[eEventType].tStorageData2.axvRefMax= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LongAccel].f32Max)*5 + 0.1);
		}
		else
		{
			tStorageData[eEventType].tStorageData2.axvRefMax= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LongAccel].f32Max)*5 - 0.1);
		}
		if(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LongAccel].f32Min >= 0)
		{
			tStorageData[eEventType].tStorageData2.axvRefMin= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LongAccel].f32Min)*5 + 0.1);
		}
		else
		{
			tStorageData[eEventType].tStorageData2.axvRefMin= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LongAccel].f32Min)*5 - 0.1);
		}
		if(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].f32Max >= 0)
		{
			tStorageData[eEventType].tStorageData2.ayvRefMax= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].f32Max)*5 + 0.1);
		}
		else
		{
			tStorageData[eEventType].tStorageData2.ayvRefMax= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].f32Max)*5 - 0.1);
		}
		if(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].f32Min >= 0)
		{
			tStorageData[eEventType].tStorageData2.ayvRefMin= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].f32Min)*5 + 0.1);
		}
		else
		{
			tStorageData[eEventType].tStorageData2.ayvRefMin= (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_LatAccel].f32Min)*5 - 0.1);
		}

	}
	if (u8Stype == 1)
	{
		/* code */
		boolean AWBactive = 0;
		Com_ReceiveSignal(ComConf_ComSignal_SGESP_AWBactive_523R,&AWBactive);
		tStorageData[eEventType].tStorageData3.EspBrakeJerkActive  = AWBactive;
		boolean AEBdecActive = 0;
		Com_ReceiveSignal(ComConf_ComSignal_SGESP_AEBdecActive_523R,&AEBdecActive);
		tStorageData[eEventType].tStorageData3.EspAutomatedBrakingActive = AEBdecActive; 
		tStorageData[eEventType].tStorageData3.reserved = 0;//
		uint32 TotalOdometer = 0;
		Com_ReceiveSignal(ComConf_ComSignal_SGCdcTotMilg_722R,&TotalOdometer);
		tStorageData[eEventType].tStorageData3.Mileage = (uint32)(TotalOdometer*0.1);	
		tStorageData[eEventType].tStorageData3.reserved1 = 0;
	}
	
	if (u8Stype == 2)
	{
		/* code */
		tStorageData[eEventType].tStorageData4.dxvMin = (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_AEBTargetLngRange].f32Min)*5); 
		tStorageData[eEventType].tStorageData4.dyvAtdxvMin = (sint8)((tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_AEBTargetLngRange].f32MinValue1)/0.15); 
		tStorageData[eEventType].tStorageData4.tEventDurationAtdxvMin = (uint16)(tEventSignalConfig[eEventType].ptMathSignalTable[AEBDS_MathSignal_AEBTargetLngRange].u32MinValue2/20); 
	}
}
static void EventDataMem(uint8* pdata, uint8* sdata, uint16 u16size )
{
	uint8 i;
	for ( i = 0; i < u16size; i++)
	{
		pdata[i] = sdata[u16size-i-1];
	}
	
}

static void EventDataRead(AEBDS_StorageInfoEvent_e eEventType,uint8 u8index)
{
	uint8 u8stat1=0;
	uint8 u8stat2=0;
	NvM_GetErrorStatus(tStorageEventData[eEventType].u16LastStorageHandle,&u8stat1);
	NvM_GetErrorStatus(tStorageEventData[eEventType].u16StorageHandle,&u8stat2);
	if (u8index == 0)
	{	
		NvM_ReadBlock(tStorageEventData[eEventType].u16LastStorageHandle,
		(void*)tStorageEventData[eEventType].pu8LastStorage);
	
		NvM_ReadBlock(tStorageEventData[eEventType].u16StorageHandle,
		(void*)tStorageEventData[eEventType].pu8Storage);
	}
}

static void EventDataWrite(AEBDS_StorageInfoEvent_e eEventType,uint8 u8index)
{
	uint8 u8stat1=0;
	uint8 u8stat2=0;
	NvM_GetErrorStatus(tStorageEventData[eEventType].u16LastStorageHandle,&u8stat1);
	NvM_GetErrorStatus(tStorageEventData[eEventType].u16StorageHandle,&u8stat2);
	if (u8index = 0)
	{
		/* code */
		NvM_WriteBlock(tStorageEventData[eEventType].u16LastStorageHandle,
			(void*)tStorageEventData[eEventType].pu8LastStorage);
	
		NvM_WriteBlock(tStorageEventData[eEventType].u16StorageHandle,
			(void*)tStorageEventData[eEventType].pu8Storage);
	}
	
}

static void EventDataSotorage(AEBDS_StorageInfoEvent_e eEventType)
{
	memcpy(tStorageEventData[eEventType].pu8LastStorage,tStorageEventData[eEventType].pu8Storage,49);
	EventDataMem(&tStorageEventData[eEventType].pu8Storage[0],(uint8*)&(tStorageData[eEventType].tStorageData0),sizeof(tStorageData[eEventType].tStorageData0)); // 0-6
	EventDataMem(&tStorageEventData[eEventType].pu8Storage[7],(uint8*)&(tStorageData[eEventType].tStorageData1),sizeof(tStorageData[eEventType].tStorageData1)); // 7-13
	EventDataMem(&tStorageEventData[eEventType].pu8Storage[14],(uint8*)&(tStorageData[eEventType].tStorageData2),sizeof(tStorageData[eEventType].tStorageData2)); // 14-41
	EventDataMem(&tStorageEventData[eEventType].pu8Storage[42],(uint8*)&(tStorageData[eEventType].tStorageData3),sizeof(tStorageData[eEventType].tStorageData3)); // 42-44
	EventDataMem(&tStorageEventData[eEventType].pu8Storage[45],(uint8*)&(tStorageData[eEventType].tStorageData4),sizeof(tStorageData[eEventType].tStorageData4)); // 45-49
	NvM_WriteBlock(tStorageEventData[eEventType].u16LastStorageHandle,
	(void*)tStorageEventData[eEventType].pu8LastStorage);

	NvM_WriteBlock(tStorageEventData[eEventType].u16StorageHandle,
		(void*)tStorageEventData[eEventType].pu8Storage);

}
static void SetSignalState(AEBDS_StorageInfoEvent_e eEventType, uint8 u8State)
{
	uint8 i;
	AEBDS_MathInfo_t* tMathTable;

	tMathTable = &tEventSignalConfig[eEventType].ptMathSignalTable[0];
	for (i = 0; i < tEventSignalConfig[eEventType].u8SingnalLen; i++)
	{
		tMathTable[i].u8State = u8State;
	}
}

static void MathCalculate(AEBDS_StorageInfoEvent_e eEventType)
{
	uint8 i;
	uint8 len;
	AEBDS_MathInfo_t* tMathTable;

	tMathTable = &tEventSignalConfig[eEventType].ptMathSignalTable[0];
	len = tEventSignalConfig[eEventType].u8SingnalLen;
	for (i = 0; i < len; i++)
	{
		if (tMathTable[i].u8State == 1)
		{
			/* min */
			if (*tMathTable[i].pf32Sinal < tMathTable[i].f32Min )
			{
				tMathTable[i].f32Min = *tMathTable[i].pf32Sinal;
				tMathTable[i].f32MinValue1 = *tMathTable[i].pfValue1;
				tMathTable[i].u32MinValue2 = tMathTable[i].u32Dutime;		
			}

			/* max*/
			tMathTable[i].f32Max = \
				(*tMathTable[i].pf32Sinal < tMathTable[i].f32Max ) \
				? (tMathTable[i].f32Max) : (*tMathTable[i].pf32Sinal);
			/* during time*/
			tMathTable[i].u32Dutime += AEBDS_MAIN_FUNC_PERIOD_MS;
		}
		else if (tMathTable[i].u8State == 2)
		{
			tMathTable[i].f32delta = tMathTable[i].f32Max - tMathTable[i].f32Min;
		}
		else if (tMathTable[i].u8State == 3)
		{
			tMathTable[i].f32Min = *tMathTable[i].pf32Sinal;
			tMathTable[i].f32Max = *tMathTable[i].pf32Sinal;
			tMathTable[i].f32MinValue1 = *tMathTable[i].pfValue1;
			tMathTable[i].u32MinValue2 = tMathTable[i].u32Dutime;
		}
		
		else if (tMathTable[i].u8State == 0)
		{			
			tMathTable[i].f32Av = 0.0;
			tMathTable[i].f32Min = 0.0;
			tMathTable[i].f32Max = 0.0;
			tMathTable[i].f32delta = 0.0;
			tMathTable[i].u32Dutime = 0;
			tMathTable[i].f32MinValue1 = 0.0;
			tMathTable[i].u32MinValue2 = 0;
		}
		else
		{}
	}

}


// void AEBDataStorageMainFunction(void)
// {

	
	
// }




void testBlock(void);

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
FUNC(void, RTE_CODE) AebDsInitFunction (void)
{
	//reserved
	return;

} /* FUNC(void, RTE_CODE) AebDsInitFunction (void) */

FUNC(void, RTE_CODE) AebDsMainFunction (void)
{
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_FCWActive(&AEBdata.Cps_FCWActive);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AWBActive(&AEBdata.Cps_AWBActive);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBActive(&AEBdata.Cps_AEBActive);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBTargetRelSpeed(&AEBdata.Cps_AEBTargetRelSpeed);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBTargetLatRange(&AEBdata.Cps_AEBTargetLatRange);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBTargetLngRange(&AEBdata.Cps_AEBTargetLngRange);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_EpsSasSteerAg(&AEBdata.Cpr_EpsSasSteerAg);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_EpsSteerAgRate(&AEBdata.Cpr_EpsSteerAgRate);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_EspLatAccel(&AEBdata.Cpr_EspLatAccel);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_EspLongAccel(&AEBdata.Cpr_EspLongAccel);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_EspVehSpd(&AEBdata.Cpr_EspVehSpd);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_EspYawRate(&AEBdata.Cpr_EspYawRate);
	Rte_Read_Fcu_RP_Fcu_Chassis_Data_BrakePressureSimulator(&AEBdata.Cpr_PFSBrakePressure);
	Rte_Read_AebDs_RP_Cpr_Chassis_Data_VcuAccrPedlPosn(&AEBdata.Cpr_VcuAccrPedlPosn);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBTargetAx(&AEBdata.Cps_AEBTargetAx);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBTargetAy(&AEBdata.Cps_AEBTargetAy);
	Rte_Read_AebDs_RP_Fcu_Aeb_Data_Cps_SignalPhyData_FC_AEBTargetLatRelSpeed(&AEBdata.Cps_AEBTargetLatRelSpeed);

	Cpr_SignalPhyData_EpsSteerAgRate_float = (float32)AEBdata.Cpr_EpsSteerAgRate;
	Cpr_PFSBrakePressure_float = (float32)AEBdata.Cpr_PFSBrakePressure;
#if AEBDSFUNC_EN
	uint8 i;
	//NvmProcess();
	SignalConHandle();
	SetActiveStaHandle();
	for ( i = 0; i < AEBDS_StorageInfoEvent_Num; i++)
	{
		EventCheckHandle(i);
	}
#endif
} /* FUNC(void, RTE_CODE) AebDsMainFunction (void) */

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */