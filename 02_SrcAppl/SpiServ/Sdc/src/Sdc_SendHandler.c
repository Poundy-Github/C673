/* ==================[Includes]=============================================== */
#include "Sdc_Core.h"
#include "Sdc_Core_Type.h"
#include "Sdc_Cfg.h"
#include "SpiTpMaster.h"
#include "Sdc_Lcfg.h"
#include "Sdc_Misc.h"
#include "Sdc_SendHandler.h"
#include "SpiSync_Type.h"

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/


/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

static s_Sdc_SpiMsgPayload_t Sdc_SpiMsgPayload_Tx;
static s_Sdc_SpiMsgPayloadConti_t Sdc_SpiMsgPayloadConti_Tx;
static s_Sdc_MsgTimesync_st msg_time_sync;
static s_Sdc_MsgTimesync_st msg_time_sync_utc;
static s_Sdc_MsgSendHandleState_Cycle_st Sdc_MsgSendHandleState_Cycle[SDC_SENDHANDLER_CYCLEMSG_SIZE];

static s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_EventData_evt;

s_SdcSendEventMsgPoolType_st SdcSendEventMsgPoolType;   /*event msg pool*/

Sdc_MsgSHandshake_st msg_handshake;


#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[internal constants]====================================*/


/*==================[macros]=================================================*/
#define SDC_SENDHANDLER_CYCLE_PERIOD_TIME   5

/*==================[internal function declarations]========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

static void Sdc_SendHandler_Cycle_MainFunction(void);
static void Sdc_SendHandler_Event_MainFunction(void);

static uint8 Sdc_SendHandler_SpiMsg(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
static uint8 Sdc_SendHandler_SpiMsgAddedTimestamp(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
static uint8 Sdc_SendHandler_SpiMsgAddedTimestamp_Sub(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
static uint8 Sdc_SendHandler_SpiMsgSubFunction(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
static uint8 Sdc_SendHandler_SpiMsgSubFunction_Horizon(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
uint8 Sdc_SendHandler_TimeSyncMsg_New(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
uint8 Sdc_SendHandler_svcAPTimeSyncUtc_New(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
uint8 Sdc_SendHandler_SpiMsg_Handshake(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);
static uint8 Sdc_SendHandler_SpiMsgSubFunction_Conti(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length);

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

/*==================[.const]==============================*/
#define SDC_START_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"

const s_Sdc_MsgSendHandle_CycleFunction_st Sdc_MsgSendHandle_CycleFunc[SDC_SENDHANDLER_CYCLEMSG_SIZE] = 
{
    {Sdc_SendHandler_SpiMsgAddedTimestamp},
    {Sdc_SendHandler_SpiMsgAddedTimestamp},
    {Sdc_SendHandler_SpiMsgAddedTimestamp},
    {Sdc_SendHandler_SpiMsg},
};

const s_Sdc_MsgSendHandle_EventFunction_st Sdc_MsgSendHandle_EventFunc[] = 
{
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0203_ReplyMcuCmdResult, e_Sdc_SpiMsgSubType_SetCalibration_Result, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0203_ReplyMcuCmdResult, e_Sdc_SpiMsgSubType_SetEOL_Calib_Result, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd, e_Sdc_SpiMsgSubType_RequestCaliValue, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd, e_Sdc_SpiMsgSubType_ReadSocDiag, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd, e_Sdc_SpiMsgSubType_RequestCalibration, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0204_ReplyHandshake, e_Sdc_SpiMsgSubType_NULL, Sdc_SendHandler_SpiMsg_Handshake},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd, e_Sdc_SpiMsgSubType_SocTimeSync, Sdc_SendHandler_TimeSyncMsg_New},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0604_UtcTime, e_Sdc_SpiMsgSubType_UTCSync, Sdc_SendHandler_svcAPTimeSyncUtc_New},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0602_WorkingMode, e_Sdc_SpiMsgSubType_WorkMode, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0603_WorkingMode_Reserve, e_Sdc_SpiMsgSubType_WorkMode_Req, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0606_HardwareNumAck, e_Sdc_SpiMsgSubType_HardwareNumAck, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0605_SocSoftNumReq, e_Sdc_SpiMsgSubType_J3SoftwareNumReq, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest, e_Sdc_SpiMsgSubType_ETH_Normal, Sdc_SendHandler_SpiMsgSubFunction_Horizon},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0803_UdsRequest, e_Sdc_SpiMsgSubType_NULL, Sdc_SendHandler_SpiMsgAddedTimestamp_Sub},
    {e_Sdc_SpiMsgType_Evt_Mcu2J3_0802_UdsResponse, e_Sdc_SpiMsgSubType_Uds_J3Request, Sdc_SendHandler_SpiMsgSubFunction_Conti}

};
#define EVENT_MSGTABLE_SIZE  (sizeof(Sdc_MsgSendHandle_EventFunc) / sizeof(Sdc_MsgSendHandle_EventFunc[0]))

#define SDC_STOP_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"
void Sdc_SendHandler_InitFunction(void)
{
    memset(&Sdc_SpiMsgPayload_Tx, 0, sizeof(s_Sdc_SpiMsgPayload_t));
    memset(&msg_time_sync, 0, sizeof(s_Sdc_MsgTimesync_st));
}
void Sdc_SendHandler_DeInitFunction(void)
{
   //TODO
}

//run cycle 5ms
void Sdc_SendHandler_MainFunction(void)
{
    Sdc_SendHandler_Cycle_MainFunction();
    Sdc_SendHandler_Event_MainFunction();
}

//run cycle 5ms
static void Sdc_SendHandler_Cycle_MainFunction(void)
{
    uint8 i;
    Sdc_MsgIDInfo_st msgIdInfo_Temp = {0, 0};
    if(e_Sdc_HandShakeStatus_Est == Sdc_Core_Handshake_GetStatus())
    {
        for ( i = 0; i < SDC_SENDHANDLER_CYCLEMSG_SIZE; i++)
        {
            Sdc_MsgSendHandleState_Cycle[i].msgCycleCnt++;
            if(Sdc_MsgSendHandleState_Cycle[i].sendSta)
                Sdc_MsgSendHandleState_Cycle[i].sendSta = 0;
            if(Sdc_MsgSendHandleState_Cycle[i].msgCycleCnt >= (Sdc_MsgSendHandleTable_Cycle[i].msgCycle / SDC_SENDHANDLER_CYCLE_PERIOD_TIME))
            {
                Sdc_MsgSendHandleState_Cycle[i].msgCycleCnt = 0;
                
                //TODO : send spi data
                if(Sdc_MsgSendHandle_CycleFunc[i].HandlerFunction != NULL_PTR)
                {
                    msgIdInfo_Temp.msgId = Sdc_MsgSendHandleTable_Cycle[i].msgId;
                    msgIdInfo_Temp.subId = Sdc_MsgSendHandleTable_Cycle[i].subId;
                    Sdc_MsgSendHandleState_Cycle[i].sendSta = 1;
                    Sdc_MsgSendHandle_CycleFunc[i].HandlerFunction(msgIdInfo_Temp, Sdc_MsgSendHandleTable_Cycle[i].pData, Sdc_MsgSendHandleTable_Cycle[i].len);
                }
            }
        }
    }
    else
    {
        //handshake err 
    }
    
}
u_SpiSync_TimeStamp_t tsync_TimeStamp_raw;
static sint64 tSync_Time_s_raw;
static sint64 tSync_Time_s_list_raw[10];
static uint8 tSync_Time_index_raw = 0;

static void Sdc_SendHandler_Event_MainFunction(void)
{
    boolean empty;
    uint8 i;
    
    Sdc_MsgIDInfo_st msgIdInfo;
    empty = Sdc_Misc_EventSendMsg_poolIsEmpty(&SdcSendEventMsgPoolType);
    if(empty == FALSE)
    {
        Sdc_Misc_EventSendMsg_poolPop(&SdcSendEventMsgPoolType, &Sdc_EventData_evt);
        msgIdInfo.msgId = Sdc_EventData_evt.msgId;
        msgIdInfo.subId = Sdc_EventData_evt.subId;
        for ( i = 0; i < EVENT_MSGTABLE_SIZE; i++)
        {
            if(Sdc_EventData_evt.msgId == Sdc_MsgSendHandle_EventFunc[i].msgId && Sdc_EventData_evt.subId == Sdc_MsgSendHandle_EventFunc[i].subId)
            {
                Sdc_MsgSendHandle_EventFunc[i].HandlerFunction(msgIdInfo, Sdc_EventData_evt.data, Sdc_EventData_evt.len);
                if(i == 6)
                {
                    memcpy(&tsync_TimeStamp_raw.raw[0], &Sdc_EventData_evt.data[0], 8);
                    tSync_Time_s_raw = tsync_TimeStamp_raw.data / 1000000000;
                    tSync_Time_s_list_raw[tSync_Time_index_raw++] = tSync_Time_s_raw;
                    if(tSync_Time_index_raw >= 10)
                        tSync_Time_index_raw = 0;
                    tSync_Time_s_list_raw[tSync_Time_index_raw] = 0;
                }
            }
            
        }
        
    }

}

void Sdc_SendHandler_SendEventMsg(const s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo)
{
    Sdc_Misc_EventSendMsg_poolPush(&SdcSendEventMsgPoolType, &Sdc_eventMsgInfo);
}







/**
 * \functions Sdc_SendHandler_SpiMsg_Handshake
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
 */
uint8 Sdc_SendHandler_SpiMsg_Handshake(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;
    const uint8 *tmp = data;
    if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > 2)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        msg_handshake.header.MsgType = MsgIDInfo.msgId;
        msg_handshake.header.DataLength = 2;
        msg_handshake.sync = *tmp;
        // SpiTp_MasterInit();
        tmp++;
        msg_handshake.ack = *tmp;
        status = SpiTp_masterSend((const uint8 *)&msg_handshake, sizeof(Sdc_MsgSHandshake_st));
        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}




/**
 * \functions Sdc_SendHandler_TimeSyncMsg
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
 */
uint8 Sdc_SendHandler_TimeSyncMsg(const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        msg_time_sync.header.MsgType = e_Sdc_SpiMsgType_Evt_Mcu2J3_0202_RequestSocCmd;
        msg_time_sync.header.DataLength = sizeof(s_Sdc_Timesync_st) + 4; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        msg_time_sync.header.ProtocolId = SDC_PROTOCOL_TYPE;
        msg_time_sync.sub = e_Sdc_SpiMsgSubType_SocTimeSync;

        memcpy(&msg_time_sync.ts_info, data, length);

        status = SpiTp_masterSend((uint8 *)&msg_time_sync, length + sizeof(s_Sdc_MsgTimesync_st)); 

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}
uint32 tSync_cnt = 0;
uint8 Sdc_SendHandler_TimeSyncMsg_New(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        msg_time_sync.header.MsgType = MsgIDInfo.msgId;
        msg_time_sync.header.DataLength = sizeof(s_Sdc_Timesync_st) + 4; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        msg_time_sync.header.ProtocolId = SDC_PROTOCOL_TYPE;
        msg_time_sync.sub = (uint8)MsgIDInfo.subId;

        memcpy(&msg_time_sync.ts_info, data, length);

        status = SpiTp_masterSend((uint8 *)&msg_time_sync, length + sizeof(s_Sdc_MsgTimesync_st)); 
        tSync_cnt++;
        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}
uint8 Sdc_Core_SendHandler_svcAPTimeSyncUtc(const s_Sdc_Timesync_st *ts_info)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else
    {
        msg_time_sync.header.MsgType = e_Sdc_SpiMsgType_Evt_Mcu2J3_0604_UtcTime;
        msg_time_sync.header.DataLength = sizeof(s_Sdc_Timesync_st) + 4; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        msg_time_sync.header.ProtocolId = SDC_PROTOCOL_TYPE;
        msg_time_sync.sub = e_Sdc_SpiMsgSubType_UTCSync;

        msg_time_sync.ts_info = *ts_info;

        status = SpiTp_masterSend((uint8 *)&msg_time_sync, sizeof(s_Sdc_MsgTimesync_st)); 

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}
uint8 Sdc_SendHandler_svcAPTimeSyncUtc_New(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else
    {
        msg_time_sync_utc.header.MsgType = MsgIDInfo.msgId;
        msg_time_sync_utc.header.DataLength = sizeof(s_Sdc_Timesync_st) + 4; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        msg_time_sync_utc.header.ProtocolId = SDC_PROTOCOL_TYPE;
        msg_time_sync_utc.sub = (uint8)MsgIDInfo.subId;

        // msg_time_sync.ts_info = (s_Sdc_Timesync_st )(*data);   //(s_Sdc_Timesync_st *)
        memcpy(&msg_time_sync_utc.ts_info, data, length);
        
        status = SpiTp_masterSend((uint8 *)&msg_time_sync_utc, sizeof(s_Sdc_MsgTimesync_st)); 

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}





/*==================[internal function definitions]=========================*/

static uint8 Sdc_SendHandler_SpiMsg(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Sdc_SpiMsgPayload_Tx.Header.MsgType = MsgIDInfo.msgId;
        Sdc_SpiMsgPayload_Tx.Header.DataLength = length;
        Sdc_SpiMsgPayload_Tx.Header.ProtocolId = SDC_PROTOCOL_TYPE;

        memcpy(Sdc_SpiMsgPayload_Tx.Data, data, length);

        status = SpiTp_masterSend((uint8 *)&Sdc_SpiMsgPayload_Tx, length + sizeof(s_Sdc_SpiMsgHeader_t));

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}


static uint8 Sdc_SendHandler_SpiMsgAddedTimestamp(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;
    uint64 time_stamp = 0x00;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Time_GetTimeStampMs(&time_stamp);

        Sdc_SpiMsgPayload_Tx.Header.MsgType = MsgIDInfo.msgId;
        Sdc_SpiMsgPayload_Tx.Header.DataLength = length + 8; /*TODO : 8 byte is timestamp length*/
        Sdc_SpiMsgPayload_Tx.Header.ProtocolId = SDC_PROTOCOL_TYPE;

        *(uint64 *)Sdc_SpiMsgPayload_Tx.Data = time_stamp;

        memcpy(Sdc_SpiMsgPayload_Tx.Data + 8, data, length);

        status = SpiTp_masterSend((uint8 *)&Sdc_SpiMsgPayload_Tx, Sdc_SpiMsgPayload_Tx.Header.DataLength + sizeof(s_Sdc_SpiMsgHeader_t));

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}


static uint8 Sdc_SendHandler_SpiMsgAddedTimestamp_Sub(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;
    uint64 time_stamp = 0x00;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Time_GetTimeStampMs(&time_stamp);

        Sdc_SpiMsgPayloadConti_Tx.Header.MsgType = MsgIDInfo.msgId;
        Sdc_SpiMsgPayloadConti_Tx.Header.DataLength = length + 8; /*TODO : 8 byte is timestamp length*/
        Sdc_SpiMsgPayloadConti_Tx.Header.ProtocolId = SDC_PROTOCOL_TYPE;
        *(uint64 *)Sdc_SpiMsgPayloadConti_Tx.Header.Timestamp = time_stamp;
        Sdc_SpiMsgPayloadConti_Tx.sub = 0x0001;

        // *(uint64 *)Sdc_SpiMsgPayloadConti_Tx.Data = time_stamp;

        memcpy(Sdc_SpiMsgPayloadConti_Tx.Data + 8, data, length);

        status = SpiTp_masterSend((uint8 *)&Sdc_SpiMsgPayloadConti_Tx, Sdc_SpiMsgPayloadConti_Tx.Header.DataLength + sizeof(s_Sdc_SpiMsgHeader_t) + 8);

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}

static uint8 Sdc_SendHandler_SpiMsgSubFunction(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Sdc_SpiMsgPayload_Tx.Header.MsgType = MsgIDInfo.msgId;
        Sdc_SpiMsgPayload_Tx.Header.DataLength = length + 4; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        Sdc_SpiMsgPayload_Tx.Header.ProtocolId = SDC_PROTOCOL_TYPE;

        memcpy(Sdc_SpiMsgPayload_Tx.Data, &MsgIDInfo.subId, 2); /*Set the SubId*/
        memcpy(Sdc_SpiMsgPayload_Tx.Data + 4, data, length);

        status = SpiTp_masterSend((uint8 *)&Sdc_SpiMsgPayload_Tx, length + sizeof(s_Sdc_SpiMsgHeader_t) + 8); /*TODO : Why here added 8,When not added 8,the time sync failed*/

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}

//used for Horizon msg id
static uint8 Sdc_SendHandler_SpiMsgSubFunction_Horizon(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (SDC_PAYLOAD_MAX_LENGTH - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Sdc_SpiMsgPayload_Tx.Header.MsgType = MsgIDInfo.msgId;
        Sdc_SpiMsgPayload_Tx.Header.DataLength = length + 2; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        Sdc_SpiMsgPayload_Tx.Header.ProtocolId = SDC_PROTOCOL_TYPE;

        memcpy(Sdc_SpiMsgPayload_Tx.Data, (uint8*)&MsgIDInfo.subId, 2); /*Set the SubId*/
        memcpy(Sdc_SpiMsgPayload_Tx.Data + 2, data, length);

        status = SpiTp_masterSend((uint8 *)&Sdc_SpiMsgPayload_Tx, Sdc_SpiMsgPayload_Tx.Header.DataLength + sizeof(s_Sdc_SpiMsgHeader_t)); /*TODO : Why here added 8,When not added 8,the time sync failed*/

        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}

static uint8 Sdc_SendHandler_SpiMsgSubFunction_Conti(Sdc_MsgIDInfo_st MsgIDInfo, const void *data, uint16 length)
{
    SpiTp_RetType status;
    uint8 retVal = E_NOT_OK;

    if (e_Sdc_HandShakeStatus_Est != Sdc_Core_Handshake_GetStatus())
    {
        retVal = E_NOT_OK;
    }
    else if (data == NULL_PTR)
    {
        retVal = E_NOT_OK;
    }
    else if (length > (228 - sizeof(s_Sdc_SpiMsgHeader_t)))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Sdc_SpiMsgPayloadConti_Tx.Header.MsgType = MsgIDInfo.msgId;
        Sdc_SpiMsgPayloadConti_Tx.Header.DataLength = length + 4; /*TODO : 4 byte is sub function 2 byte and 2 byte unused*/
        Sdc_SpiMsgPayloadConti_Tx.Header.ProtocolId = SDC_PROTOCOL_TYPE;
        Sdc_SpiMsgPayloadConti_Tx.sub = MsgIDInfo.subId;

        memcpy(Sdc_SpiMsgPayloadConti_Tx.Data, data, length);

        status = SpiTp_masterSend((uint8 *)&Sdc_SpiMsgPayloadConti_Tx, Sdc_SpiMsgPayloadConti_Tx.Header.DataLength + sizeof(s_Sdc_SpiMsgHeader_t)); /*TODO : Why here added 8,When not added 8,the time sync failed*/
        if (status != SPITP_E_OK)
        {
            retVal = E_NOT_OK;
        }
        else
        {
            retVal = E_OK;
        }
    }

    return retVal;
}

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
