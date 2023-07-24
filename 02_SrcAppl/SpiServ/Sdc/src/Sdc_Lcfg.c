/* ==================[Includes]=============================================== */
#include "Sdc_Lcfg.h"
#include "Sdc_Core_Type.h"
#include "Sdc_Core.h"
#include "Sdc_Chassis_Type.h"
#include "Sdc_Vdy_Type.h"
#include "Sdc_Radar_Type.h"
#include "SpiSync_Type.h"
#include "Sdc_ReceiveHandler.h"

extern uint16 FC_WorkmodeBuf[];
extern s_Sdc_ChassisData_t Sdc_ChassisData;
extern u_Sdc_VdyDyn_t Sdc_Write_VehDynData;
extern u_Sdc_Radar_ObjectList_t	Sdc_Radar_ObjectList;
extern s_SipSync_TimeSyncMessage_t SpiSync_TimeSyncMsg;
extern s_SipSync_TimeSyncMessage_t utc_time_stamp;
extern uint8 QA_Seed;

/*==================[internal constants]====================================*/
/*==================[.const]==============================*/
#define SDC_START_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"

const s_Sdc_HandlerTable_t Sdc_SpiReceiveHandlerTable[SDC_SPIRECEIVEHANDLERTABLE_SIZE] =
{
    {e_Sdc_SpiMsgType_Cy_J32Mcu_0101_Perception, Sdc_ReceiveHandler_Perception},            /*0x0101*/
    {e_Sdc_SpiMsgType_Cy_J32Mcu_0700_RecvCemOut, Sdc_ReceiveHandler_CemOut},                    /*0x0700*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0301_ReplyQaAnswer, Sdc_ReceiveHandler_QaAnswer},           /*0x0301*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0302_ReplySocCmdResult, Sdc_ReceiveHandler_SocReplyInfo},   /*0x0302*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0303_RequestMcuCmd, Sdc_ReceiveHandler_SocSysInfo},         /*0x0303*/
    {e_Sdc_SpiMsgType_Evt__J32Mcu_0304_RequestHandshake, Sdc_ReceiveHandler_Handshake},       /*0x0304*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0702_WorkingMode_State, Sdc_ReceiveHandler_DriveModeChangeRequest},  /*0x0702*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0701_WorkingMode_Ack, Sdc_ReceiveHandler_DriveModeChangeResponse},/*0x0701*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0902_UdsRequest, Sdc_Diag_ReceiveHandler_ID0902},        /*0x0902*/
    {e_Sdc_SpiMsgType_Evt_J32Mcu_0903_UdsResponse, Sdc_Diag_ReceiveHandler_ID0903}        /*0x0903*/
};

const s_Sdc_MsgSendHandleDataInfo_Cycle_st Sdc_MsgSendHandleTable_Cycle[SDC_SENDHANDLER_CYCLEMSG_SIZE] = 
{
    {
        e_Sdc_SpiMsgType_Cy_Mcu2J3_0002_Chassis,
        e_Sdc_SpiMsgSubType_NULL,
        &Sdc_ChassisData,
        sizeof(s_Sdc_ChassisData_t),
        10
    },
    {
        e_Sdc_SpiMsgType_Cy_Mcu2J3_0601_Vdy,
        e_Sdc_SpiMsgSubType_NULL,
        &Sdc_Write_VehDynData,
        sizeof(u_Sdc_VdyDyn_t),
        20
    },
    {
        e_Sdc_SpiMsgType_Cy_Mcu2J3_0600_Radar,
        e_Sdc_SpiMsgSubType_NULL,
        &Sdc_Radar_ObjectList,
        sizeof(u_Sdc_Radar_ObjectList_t),
        20
    },
    {
        e_Sdc_SpiMsgType_Evt_Mcu2J3_0201_RequestQaQuestion,
        e_Sdc_SpiMsgSubType_NULL,
        &QA_Seed,
        1,
        1000
    }
};
#define SDC_STOP_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/

/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/


/*==================[external function definitions]=========================*/



/*==================[internal function definitions]=========================*/


