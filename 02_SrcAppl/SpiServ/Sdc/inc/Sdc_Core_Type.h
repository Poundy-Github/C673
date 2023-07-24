/*
 * Sdc_Coer_Type.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_CORE_TYPE_H_
#define _SDC_CORE_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common.h"
#include "Sdc_Cfg.h"
#include "TSMem.h"

/*==================[type definitions]======================================*/
#define memset(d, s, n) TS_MemSet(d, s, n)
#define memcpy(d, s, n) TS_MemCpy(d, s, n)

typedef enum
{
    /*TODO : Mcu send to Soc message,The message type definition by Horizon Platform. and the message sent using cycle*/
    e_Sdc_SpiMsgType_Cy_Mcu2J3_0002_Chassis = 0x0002, /*TODO : Use for Perception function by Horizon*/

    /*TODO : Soc send to Mcu message,The message type definition by Horizon Platform,and the message sent using cycle*/
    e_Sdc_SpiMsgType_Cy_J32Mcu_0101_Perception = 0x0101, /*TODO : Use for Lcf and output to canbus*/

    /*TODO : Mcu send to Soc message,The message type definition by Horizon Platform,and the message sent using event(Request/Response)*/
    e_Sdc_SpiMsgType_Evt_Mcu2J3_0201_RequestQaQuestion = 0x0201, /*TODO : Use for Heartbeat detection*/
    e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd = 0x0202,     /*TODO : Mcu send command to Soc,The command please refer enum of e_Sdc_SpiMsgSubType_SocCmd_t*/
    e_Sdc_SpiMsgType_Evt_Mcu2J3_0203_ReplyMcuCmdResult = 0x0203, /*TODO : Mcu perform Soc request command,then reponse the command result to Soc*/
    e_Sdc_SpiMsgType_Evt_Mcu2J3_0204_ReplyHandshake = 0x0204,    /*TODO : Use for handshake reponse from Mcu to Soc. Notes : The handshake sequence start by Soc*/

    /*TODO : Soc send to Mcu message,The message type definition by Horizon Platform, and the message sent using event*/
    e_Sdc_SpiMsgType_Evt_J32Mcu_0301_ReplyQaAnswer = 0x0301,     /*TODO : Use for Heartbeat detection*/
    e_Sdc_SpiMsgType_Evt_J32Mcu_0302_ReplySocCmdResult = 0x0302, /*TODO : Soc perform Mcu request command,then reponse the command result to Mcu*/
    e_Sdc_SpiMsgType_Evt_J32Mcu_0303_RequestMcuCmd = 0x0303,     /*TODO : Soc send command to Mcu*/
    e_Sdc_SpiMsgType_Evt__J32Mcu_0304_RequestHandshake = 0x0304, /*TODO : Use for handshake request form Soc to Mcu. Notes : The handshake sequence start by Soc*/

    /*TODO : Mcu send to Soc message,The message type definition by Conti,and the message sent using cycle*/
    e_Sdc_SpiMsgType_Cy_Mcu2J3_0600_Radar = 0x0600, /*TODO : Use for Cem function by Conti*/
    e_Sdc_SpiMsgType_Cy_Mcu2J3_0601_Vdy = 0x0601,   /*TODO : Use for Cem function by Conti*/

    e_Sdc_SpiMsgType_Evt_Mcu2J3_0602_WorkingMode = 0x0602,         /*TODO : Shall be deleted,it combined to Uds related,use 31 service*/
    e_Sdc_SpiMsgType_Evt_Mcu2J3_0603_WorkingMode_Reserve = 0x0603, /*TODO : Shall be deleted,it combined to Uds related,use 31 service*/

    e_Sdc_SpiMsgType_Evt_Mcu2J3_0604_UtcTime = 0x0604, /*TODO : Use for sending Utc Time*/

    /*TODO : Soc send to Mcu message,The message type definition by Conti,and the message sent using cycle*/
    e_Sdc_SpiMsgType_Cy_J32Mcu_0700_RecvCemOut = 0x0700, /*TODO : Use for Fct function*/

    /*TODO : (Dirve mode)Soc send to Mcu message,The message type definition by Conti,and the message sent using event(Request/Response)*/
    e_Sdc_SpiMsgType_Evt_J32Mcu_0701_WorkingMode_Ack = 0x0701,   /*TODO : Shall be deleted,it combined to Uds related,use 31 service*/
    e_Sdc_SpiMsgType_Evt_J32Mcu_0702_WorkingMode_State = 0x0702, /*TODO : Shall be deleted,it combined to Uds related,use 31 service*/


    /*TODO : (Diag)Mcu send to Soc message,The message type definition by Conti,and the message sent using event(Request/Response)*/
    e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest = 0x0803,
    e_Sdc_SpiMsgType_Evt_J32Mcu_0903_UdsResponse = 0x0903,

    e_Sdc_SpiMsgType_Evt_Mcu2J3_0802_UdsResponse = 0x0802,
    e_Sdc_SpiMsgType_Evt_J32Mcu_0902_UdsRequest = 0x0902,

    /*TODO : (ADR)Mcu send to Soc message,The message type definition by Conti,and the message sent using event(Request/Response)*/
    e_Sdc_SpiMsgType_Event_McuRID_ADR_0806Request = 0x0806,
    e_Sdc_SpiMsgType_Evt_J32Mcu_0605_SocSoftNumReq = 0x0605,    /*TODO : Use for request j3 software number by Conti*/
    e_Sdc_SpiMsgType_Evt_J32Mcu_0606_HardwareNumAck = 0x0606,     /*TODO : Use for Ack j3 hardware number request by Conti*/


    e_Sdc_SpiMsgType_Max = 0xFFFF
} e_Sdc_SpiMsgType_t;

/*Sub Function Id*/

typedef enum
{
    e_Sdc_SpiMsgSubType_ReadSocVersion = 0x0001,     /*TODO : MCU Read Soc Version*/
    e_Sdc_SpiMsgSubType_ReadSocStatus = 0x0002,      /*TODO : MCU Read Soc Status*/
    e_Sdc_SpiMsgSubType_ReadSocDiag = 0x0003,        /*TODO : MCU Read Soc Diag*/
    e_Sdc_SpiMsgSubType_SocTimeSync = 0x0006,        /*TODO : MCU Config Soc Time Sync*/
    e_Sdc_SpiMsgSubType_SocAdasSet = 0x0007,         /*TODO : Set ADAS function control*/
    e_Sdc_SpiMsgSubType_GpsInfo = 0x0008,            /*TODO : Send GPS Data*/
    e_Sdc_SpiMsgSubType_IMUInfo = 0x0009,            /*TODO : Send IMU Data*/
    e_Sdc_SpiMsgSubType_RequestCalibration = 0x000C, /*TODO : Request EOL and SDA Calibration, request J3 power shutdown*/
    e_Sdc_SpiMsgSubType_RequestCaliValue = 0x0083,   /*TODO : Request J3 Calibration Value*/
} e_Sdc_SpiMsgSubType_ReadSocData_t; /* Msg ID: 0x0202*/



typedef enum
{
    e_Sdc_SpiMsgSubType_SetCalibration_Result   = 0x0018,     /*TODO : MCU Set Calibration_Result*/
    e_Sdc_SpiMsgSubType_SetEOL_Calib_Result     = 0x0021,     /*TODO : MCU Set EOL_Calib_Result*/
} e_Sdc_SpiMsgSubType_Calibration_t;    /* Msg ID: 0x0203*/

typedef enum
{
    e_Sdc_SpiMsgSubType_SetSoc_State_Info       = 0x001E,
    e_Sdc_SpiMsgSubType_SetSoc_CPUState_Info    = 0x001F,
    e_Sdc_SpiMsgSubType_SetBootSet_Reboot       = 0x0072,
} e_Sdc_SpiMsgSubType_RequestMCUCmd_t;    /* Msg ID: 0x0303*/
typedef enum
{
    e_Sdc_SpiMsgSubType_WorkMode        = 0x0001,     /*TODO : MCU send to j3 the sence work mode*/
    e_Sdc_SpiMsgSubType_WorkMode_Req    = 0x0002,     /*TODO : MCU work mode changed req*/
} e_Sdc_SpiMsgSubType_WorkMode_t;    /* Msg ID: 0x0602 0x0603*/
typedef enum
{
    e_Sdc_SpiMsgSubType_UTCSync   = 0x0001,     /*TODO : MCU UTC Sync*/
} e_Sdc_SpiMsgSubType_UTC_t;    /* Msg ID: 0x0604*/

typedef enum
{
    e_Sdc_SpiMsgSubType_J3SoftwareNumReq    = 0x0101,     /*TODO : MCU request j3 software number*/
    e_Sdc_SpiMsgSubType_HardwareNumAck      = 0x0102,     /*TODO : MCU ack j3 hardware number request*/
    e_Sdc_SpiMsgSubType_ReadSocSoftVersion  = 0x2001,     /*TODO : Soc send to mcu soc's soft version*/
    e_Sdc_SpiMsgSubType_ReadMcuHwVersion    = 0x2002,     /*TODO : Read Mcu Hw Version*/
} e_Sdc_SpiMsgSubType_Version_t;    /* Msg ID: 0x0605 0x0606*/

typedef enum
{
    e_Sdc_SpiMsgSubType_ETH_Normal   = 0x0001,     /*TODO : ETH Msg normal subid*/
} e_Sdc_SpiMsgSubType_ETH_t;    /* Msg ID: 0x0604*/

typedef enum
{
    e_Sdc_SpiMsgSubType_Uds_J3Request = 0x0001,      /*TODO : Soc Request mcu uds cmd or mcu response Soc*/
} e_Sdc_SpiMsgSubType_Uds_t;  
typedef enum
{
    e_Sdc_SpiMsgSubType_NULL = 0xFFFF,      /*TODO : none sub id*/
} e_Sdc_SpiMsgSubType_NULL_t;  





typedef enum
{
    e_Sdc_SocSystemStatus_Init = 0x00,
    e_Sdc_SocSystemStatus_Normal = 0x01,
    e_Sdc_SocSystemStatus_AfterRun = 0x02,
    e_Sdc_SocSystemStatus_Stop = 0x03,
    e_Sdc_SocSystemStatus_CameraOnlineCalibration = 0x04,
    e_Sdc_SocSystemStatus_CameraEolCalibration = 0x06,
    e_Sdc_SocSystemStatus_OtaPrepare = 0x07,
    e_Sdc_SocSystemStatus_CameraEolCalibrationFinish = 0x08,
    e_Sdc_SocSystemStatus_CameraOnlineCalibrationFinish = 0x09,
    e_Sdc_SocSystemStatus_Ota = 0x0A,
    e_Sdc_SocSystemStatus_Dota = 0x0B,
    e_Sdc_SocSystemStatus_SystemFault = 0x0C,
    e_Sdc_SocSystemStatus_Max = 0xFF
} e_Sdc_SocSystemStatus_t;

typedef enum
{
    e_Sdc_UpdatedFlag_None = 0x00,       /*Not Connect,Init status*/
    e_Sdc_UpdatedFlag_NotUpdated = 0x10, /*Connect,but not have data updated or the last receive data process done */
    e_Sdc_UpdatedFlag_Updated = 0x11,    /*Connect,and have data updated*/
    e_Sdc_UpdatedFlag_Mapping = 0x12,
    e_Sdc_UpdatedFlag_Max = 0xFF
} e_Sdc_UpdatedFlag_t;

typedef struct
{
    /* data */
    uint8 J3_software_version[8];
    uint8 J3_askfor_MCU_HWB;
    uint8 J3_BOOTSENSOR;
    uint8 J3_OM_SN[4];
} SocToMcu_Data;

typedef struct
{
    uint16 MsgType;    /*TODO : Spi Message Type(spi message id)*/
    uint16 DataLength; /*TODO : Spi Message Data Length*/
    uint32 ProtocolId;
    uint8 Timestamp[8];
} s_Sdc_SpiMsgHeader_t;

typedef struct
{
    s_Sdc_SpiMsgHeader_t Header;
    uint8 Data[SDC_PAYLOAD_MAX_LENGTH]; /*TODO : the struct of s_Sdc_SpiMsgPayload_t not more than SDC_PAYLOAD_MAX_LENGTH*/
} s_Sdc_SpiMsgPayload_t;


typedef struct
{
    s_Sdc_SpiMsgHeader_t Header;
    uint16 sub;
    uint8 unused[2];
    uint8 Data[228]; /*TODO : the struct of s_Sdc_SpiMsgPayload_t not more than SDC_PAYLOAD_MAX_LENGTH*/
} s_Sdc_SpiMsgPayloadConti_t;   //used for conti msg id

typedef struct
{
    uint8 ts[8];
    uint8 checksum;
    uint8 cycle;
    uint8 reserve[2];
} s_Sdc_Timesync_st;

typedef struct
{
    s_Sdc_SpiMsgHeader_t header;
    uint8 sub;
    uint8 unused[3];
    s_Sdc_Timesync_st ts_info;
} s_Sdc_MsgTimesync_st;

typedef struct
{
    uint16 Id;
    uint8 (*HandlerFunction)(const uint8 *Data, uint16 Length);
} s_Sdc_HandlerTable_t;

typedef enum
{
    e_Sdc_HandShakeStatus_None = 0x00,
    e_Sdc_HandShakeStatus_Sync = 0x01,
    e_Sdc_HandShakeStatus_Est = 0x02,
    e_Sdc_HandShakeStatus_Max = 0xFF
} e_Sdc_HandShakeState_t;

typedef enum
{
    e_Sdc_QaMonitorErrorStatus_None = 0x00,     /*TODO : Init status,before the handshake*/
    e_Sdc_QaMonitorErrorStatus_Normal = 0x01,   /*TODO : Once request and response a correct QA message,the status chanage to Normal*/
    e_Sdc_QaMonitorErrorStatus_KeyError = 0x02, /*TODO : Once the Key error,the status chanage to KeyError*/
    e_Sdc_QaMonitorErrorStatus_Timeout = 0x03,  /*TODO : Once the time window not received the answer message,the status chanage to Timeout*/
    e_Sdc_QaMonitorErrorStatus_Error = 0x04,    /*TODO : When the ContinuousKeyErrorCnt more than the KeyErrorThreshold[MACRO] or the ContinuousTimeoutCnt more than the TimeWindowThreshold[MACRO], the status chanage to Error,and the error not recover*/
    e_Sdc_QaMonitorErrorStatus_Max = 0xFF
} e_Sdc_QaMonitorErrorStatus_t;

typedef struct
{
    uint8 Seed;
    uint8 Key;
} s_Sdc_QaMonitorSeedKey_t;

typedef struct
{
    e_Sdc_QaMonitorErrorStatus_t ErrorStatus;
    uint32 TxSeedMsgCnt;
    uint32 RxKeyMsgCnt;
    uint32 TxSeedCycleCounter;     /*TODO : means the QA message cycle,the cycle configuration by MACRO*/
    uint32 RxKeyTimeWindowCounter; /*TODO : means the QA message from Quenstion to Answer time windows,and the Threshold definition by Macro*/
    boolean WaitRxKey;
    uint8 SeedKeyIndex;
    uint8 SeedKeyIndex_Last;
    uint8 KeyErrorCnt;                    /*TODO : Once detection a key error,the counter increase 1.The counter more than 255,it keep in 255.*/
    uint8 ContinuousKeyErrorCnt;          /*TODO : Once detection a key error,the counter increase 1.The counter more than 255,it keep in 255,When check the Key correct,clean this counter. */
    uint8 RxKeyTimeoutErrorCnt;           /*TODO : Once detection a timeout error,the counter increase 1.The counter more than 255,it keep in 255.*/
    uint8 ContinuousRxKeyTimeoutErrorCnt; /*TODO : Once detection a timeout error,the counter increase 1.The counter more than 255,it keep in 255,When check the time window correct,clean this counter*/
} s_Sdc_QaMonitorStateInfo_t;

typedef struct
{
    s_Sdc_SpiMsgHeader_t header;
    uint8 sync;
    uint8 ack;
    uint8 unused[2];
} Sdc_MsgSHandshake_st;

typedef enum
{
    e_Sdc_SendCycleMsg_DriveMode = 0x00,
    e_Sdc_SendCycleMsg_Chassis,
    e_Sdc_SendCycleMsg_VDY,
    e_Sdc_SendCycleMsg_Radia,
    e_Sdc_SendCycleMsg_QA,
    e_Sdc_SendCycleMsg_TimeSync,
    e_Sdc_SendCycleMsg_UTCTimeSync,
    e_Sdc_SendCycleMsg_ = 0xFF
} e_Sdc_SendMsg_Cycle_t;

typedef struct
{
    uint16 msgId;
    uint16 subId;
} Sdc_MsgIDInfo_st;

typedef struct
{
    uint16 msgId;
    uint16 subId;
    void *pData;
    uint16 len;
    uint16 msgCycle;
} s_Sdc_MsgSendHandleDataInfo_Cycle_st;

typedef struct
{
    uint16 msgCycleCnt;
    uint16 sendSta;
} s_Sdc_MsgSendHandleState_Cycle_st;

typedef struct
{
    uint8 (*HandlerFunction)(Sdc_MsgIDInfo_st msgIdInfo, const void *Data, uint16 Length);
} s_Sdc_MsgSendHandle_CycleFunction_st;
typedef struct
{
    uint16 msgId;
    uint16 subId;
    uint8 (*HandlerFunction)(Sdc_MsgIDInfo_st msgIdInfo, const void *Data, uint16 Length);
} s_Sdc_MsgSendHandle_EventFunction_st;
typedef struct
{
    uint16 msgId;
    uint16 subId;
    uint8 data[SDC_SENDHANDLER_EVENTMSG_MAXSIZE];
    uint16 len;
} s_Sdc_MsgSendHandleDataInfo_Event_st;

/*==================[function declaration]============================================*/

#endif /* _SDC_CORE_TYPE_H_ */
