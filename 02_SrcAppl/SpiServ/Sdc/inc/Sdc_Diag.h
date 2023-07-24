/*
 * Sdc_Diag.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_DIAG_H_
#define _SDC_DIAG_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Sdc_Core_Type.h"
/*==================[type definitions]======================================*/
#define MAX_SOCDTCGROUP_NUMBER 5U
#define MAXCAMERANUMBERS 16U

typedef enum
{
	UDSTYPE_DID  		= 0U,
	UDSTYPE_RID_START   = 1U,
	UDSTYPE_RID_STOP    = 2U,
	UDSTYPE_RID_RESULT  = 3U
}DID_RID_TYPE;


typedef struct
{
	/* data */
	uint8 DTC_D28987;
	uint8 DTC_D28A87;
	uint8 DTC_D28C87;
	uint8 DTC_D28D87;
}s_DTC_ETH_V;

typedef struct
{
	/* data */
	uint8 RID_0301;
	uint8 RID_0302;
	uint8 RID_0303[3];
	uint8 RID_0305;
	uint8 RID_0306;
	uint8 RID_0307;
	uint8 RID_0308;
	uint8 RID_0309;
	uint8 RID_030A;
}s_RID_ETH_V;


/*SysMgr state machine*/
enum{
	STATE_SYSMGR_INIT = 0X00,
	STATE_SYSMGR_NORMAL = 0X01,
	STATE_SYSMGR_AFTER_RUN = 0X02,
	STATE_SYSMGR_STOP = 0X03,
	STATE_SYSMGR_CAMERA_ONL_CALIB = 0X04,
	STATE_SYSMGR_CAMERA_EOL_CALIB = 0X06,
	STATE_SYSMGR_OTA_PREPARE = 0X07,
	STATE_SYSMGR_CAMERA_EOL_CALIB_FINISH = 0X08,
	STATE_SYSMGR_CAMERA_ONL_CALIB_FINISH = 0X09,
	STATE_SYSMGR_OTA = 0X0A,
	STATE_SYSMGR_DOTA = 0X0B,
	STATE_SYSMGR_SYSFAULT = 0X0C
};

enum CameraDirection
{
	undefined = 0,
	front,
	back,
	left,
	right,
	front_left,
	front_right,
	back_left,
	back_right,
	AVM_FrontLeft,
	AVM_FrontRight,
	AVM_RearLeft,
	AVM_RearRight
};

typedef enum 
{
	e_Sdc_DiagUds_GroupEth = 0x0001,
	e_Sdc_DiagUds_GroupVersion = 0x0002,
	e_Sdc_DiagUds_GroupControl = 0x0003
}e_Sdc_Diag_Uds_Group;

typedef enum 
{
	e_Sdc_Diag_Uds_EthEvent_CRC = 0x0001,	//ETH CRC error event id
	e_Sdc_Diag_Uds_EthEvent_SQI = 0x0002,	//ETH link quality low event id
	e_Sdc_Diag_Uds_EthEvent_Cable = 0x0003,	//ETH cable error event id
	e_Sdc_Diag_Uds_EthEvent_ICMP = 0x0004	//ETH ICMP error event id

}e_Sdc_Diag_Uds_EthEventId;

typedef enum 
{
	e_Sdc_Diag_Uds_VerEvent_ReqMcuHw = 0x0001,		//J3 request MCUhardware event id
	e_Sdc_Diag_Uds_VerEvent_ReqMcuSw = 0x0002,		//J3 request MCUsoftware event id
}e_Sdc_Diag_Uds_VersionEventId;

typedef enum 
{
	e_Sdc_Diag_Uds_VerEvent_J3ReqRstJ3_Warm = 0x0001,		//J3 request MCU warm reset J3 event id
	e_Sdc_Diag_Uds_VerEvent_J3ReqRstJ3_Cold = 0x0002		//J3 request MCU cold reset J3 event id
}e_Sdc_Diag_Uds_ResetEventId;

typedef struct
{
    uint8 FaultDataLength;
    uint8 FaultData[20];
} s_Sdc_SocDiagInfo_Type;

typedef struct
{
    uint32 camera_index;
	enum CameraDirection direction;//default should be 0
	uint32 detail;//0=calibration success, 0x01 = calibration failed
}CameraCaliResult_Type;


typedef struct
{
	uint16 SubFuncId;
	uint16 unused;
	uint32 real_camera_amount;
	CameraCaliResult_Type CameraCaliResult[MAXCAMERANUMBERS];
}TotalCaliResult_Type;

typedef struct
{
    uint16 camera_index;
    uint16 yaw;
    uint16 roll;
    uint16 pitch;
}CameraValue_Type;

typedef struct
{
    uint8 Calib_flag; /*
                       * 0x00 - Calibration is not done
                       * 0x02 -static calibration is done
                       * 0x05 - Intial_online_Calibration is  done
                       * 0x0E -  calibration is not finished
                       */
    uint16 SubFuncId;
    sint64 timestamp; /*time when latest valid cali result received*/
    CameraCaliResult_Type CameraCaliResult;
    CameraValue_Type cali_value;
    uint8 progress_rate;
} s_Sdc_CaliResult_Type;

typedef struct 
{
    float cpu_load;
	int cpu_temp;	/*unit is 0.001C*/
	float cpu_mem;
	int bpu0_load;
	int bpu1_load;
	//sint32 sensor_temp;//not used
	//sint16 cam_temp;
	//sint16 phy_temp;
	int sensor_temp; 
}s_Sdc_SocSystemInfo_t;

/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

FUNC(void, RTE_CODE) Sdc_Diag_InitFunction(void);
FUNC(void, RTE_CODE) Sdc_Diag_MainFunction(void);

void Sdc_Diag_SocReplyInfo(const uint8 *data, uint16 length);
void Sdc_Diag_SocReqToMcu_0x0905(const uint8 *data, uint16 length);
void Sdc_Diag_SocResToMcu_0x0904(const uint8 *data, uint16 length);
void Sdc_Diag_DrivemodeChangeReq(const uint8 *data, uint16 length);
void Sdc_Diag_DrivemodeChangeAck(const uint8 *data, uint16 length);

extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestEOLCalibration(void);				//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestSDACalibration(void);	            //called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EOLCalResult_Read(void);			//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_CameraCaliresultDetails_Read(uint8 *data, uint16 length);	//called by Dsm_ReadDataByIdentifier.c and Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_CameraValue_Read(void *data, uint16 length);		//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_CalibrationFlag_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c and Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestCalibrationValue(void);	//called by Esh Module --Esh_MainFunction

//3
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocSysState_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c and Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_UdsRequest(uint8_t ServerType,uint16 Did,const void *Inparameter,uint8 InparameterLength,const void *OutParam1,uint8 OutparameterLength); //called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocDiagInfo_Read(uint8 group_id, void* socDiagInfo);	//called by Esh_SnapshotExtendData.c and Sed_Stubs.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_ClearSocDiagInfo(void);
//  -- Esh_u_DataElementClass_SOCErrMap  
//  -- Sed_MainFunction
 
//9
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestSocSupplierSoftwarenumber(void); 	//called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocSupplierSoftwarenumber_Read(uint8 *data, uint16 length);//called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestOMSN(void);						//called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocOMSN_Read(uint8 *data, uint16 length);//called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_RequestBootSensor(void);					//called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocBootSensor_Read(uint8 *data, uint16 length);//called by Dsm_ReadDataByIdentifier.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocCpuInfo_Read(void* socSystemInfo, uint16 length);	//called by Dsm_ReadDataByIdentifier.c
// extern s_Sdc_SocSystemInfo_t* Sdc_Diag_SocCpuInfo_Read(void);	//called by Dsm_ReadDataByIdentifier.c

extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_SocShutdownReuqest(void);	//called by Esm.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_PWMState_Read(void);//called by Esm.c
 
//24
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableLengthDiagnostic_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthSetPortConfiguration_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetPortConfiguration_StartRoutine(void);	//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthReadPhyRegister_StartRoutine(uint8 *data, uint16 length);		//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableDiagnostic_StartRoutine(uint8 u_InputData);	//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthEnableTestMode_StartRoutine(uint8 *data, uint16 length);		//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthEnableTestMode_StopRoutine(void);			//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthPhyLoopBackTest_StartRoutine(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACAddress_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACLayerStatistic_StartRoutine(uint8 u_InputData);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthPhyLoopBackTest_StopRoutine(void);		//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthSetPortConfigurationInfo_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthReadPhyRegisterInfo_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACAddressInfo_Read(uint8 *data, uint16 length);	//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetPortConfigurationInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableDiagnosticInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthResetMACLayerStatisticInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthEnableTestModeInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthPhyLoopBackTestInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableLengthDiagnosticInfo_Read(uint8 *data, uint16 length);//called by Dsm_RoutineControl.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCrcError_Read(uint8 *data, uint16 length); 	//called by Sed_Stubs.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthSQI_Read(uint8 *data, uint16 length);			//called by Sed_Stubs.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthCableFault_Read(uint8 *data, uint16 length);	//called by Sed_Stubs.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Diag_EthIcmpError_Read(uint8 *data, uint16 length);	//called by Sed_Stubs.c

extern uint8 Sdc_Diag_svcRequestDiagData(sint64 ts, const void *data, uint16 length);
extern FUNC(void, RTE_CODE) Sdc_Diag_TxVersionData(void);


extern uint8 Sdc_Diag_GetWorkmode(void);

extern uint8 Sdc_Diag_Sence_Mode(void);

extern void Sdc_Diag_SocSysInfo(const uint8 *data, uint16 length);

extern void Sdc_Diag_SetCaliResult_Flag(uint8 flag);
extern void Sdc_Diag_SetCalibrationResult(const uint8 *data, uint16 length);
extern void Sdc_Diag_SocSysState_Set(uint16 value);
extern s_Sdc_CaliResult_Type* Sdc_Diag_GetCalibrationResult();



extern uint8 Sdc_Diag_SocDiag_vInfoUnpack(const uint8 *data, uint16 length);
extern uint8 Sdc_Diag_SocDiag_CaliInfoUnpack(const uint8 *data, uint16 length);





#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
#endif /* _SDC_DIAG_H_ */

