/* ==================[Includes]=============================================== */
#include "Sdc_Core.h"
#include "Sdc_Core_Type.h"
#include "Sdc_Diag.h"
#include "SpiTpMaster.h"
#include "Sdc_ReceiveHandler.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

static e_Sdc_HandShakeState_t ServiceHdl_handshake = e_Sdc_HandShakeStatus_None;
static s_Sdc_QaMonitorStateInfo_t Sdc_QaMonitorStateInfo;

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[.const]==============================*/
#define SDC_START_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"

const s_Sdc_QaMonitorSeedKey_t Sdc_QaMonitorSeedKey[SDC_QAMONITOR_SEED_KEY_NUMBER] = 
{
    {0, 27},
    {1, 31},
    {2, 13},
    {3, 9},
    {4, 12},
    {5, 6},
    {6, 71},
    {7, 44}
};

#define SDC_STOP_SEC_CONST_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

 uint8 QA_Seed;


#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

static void Sdc_Core_OtaSendHandler_Main(void);
static void Sdc_Core_QaMonitorHandler_UpdatedState(void);
static void Sdc_Core_QaMonitorHandler_SendSeed(void);
static FUNC(void, RTE_CODE) Sdc_Core_Handshake_Init(void);
static FUNC(void, RTE_CODE)  Sdc_Core_QaMonitorHandler_Init(void);
static FUNC(void, RTE_CODE) Sdc_Core_QaMonitorHandler_Main(void);

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

void Sdc_Core_InitFunction(void)
{   
    Sdc_Core_Handshake_Init();
    Sdc_ReceiveHandler_InitFunction();
    Sdc_Core_QaMonitorHandler_Init();
    Sdc_SendHandler_InitFunction();
}
void Sdc_Core_DeInitFunction(void)
{   
    //TODO
}

void Sdc_Core_MainFunction(void)
{
    Sdc_Diag_Sence_Mode();
    Sdc_ReceiveHandler_MainFunction();
    Sdc_Core_QaMonitorHandler_Main();
    Sdc_Core_OtaSendHandler_Main();
}

/*******************************************Handshake*************************************************************/
/**
 * \functions Sdc_Core_Handshake_Init
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
static FUNC(void, RTE_CODE) Sdc_Core_Handshake_Init(void)
{
    ServiceHdl_handshake = e_Sdc_HandShakeStatus_None;
}

e_Sdc_HandShakeState_t Sdc_Core_Handshake_GetStatus(void)
{
    return ServiceHdl_handshake;
}
uint8 Sdc_Core_Handshake_Request(uint8 sync)
{
    Sdc_MsgSHandshake_st msg_handshake;
    s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo;
    SpiTp_RetType status;
    uint8 retVal;

    retVal = E_OK;

    if (sync == SDC_HANDSHAKE_SYNC)
    {
        Sdc_eventMsgInfo.msgId = e_Sdc_SpiMsgType_Evt_Mcu2J3_0204_ReplyHandshake;
        Sdc_eventMsgInfo.subId = 0xFFFF;
        Sdc_eventMsgInfo.data[0] = sync;
        Sdc_eventMsgInfo.data[1] = SDC_HANDSHAKE_ACK;

        Sdc_eventMsgInfo.len = 2;
        Sdc_SendHandler_SendEventMsg(Sdc_eventMsgInfo);
        ServiceHdl_handshake = e_Sdc_HandShakeStatus_Sync;

        // msg_handshake.header.MsgType = e_Sdc_SpiMsgType_Evt_Mcu2J3_0204_ReplyHandshake;
        // msg_handshake.header.DataLength = 2;
        // msg_handshake.sync = sync;
        // // SpiTp_MasterInit();
        // msg_handshake.ack = SDC_HANDSHAKE_ACK;
        // status = SpiTp_masterSend((const uint8 *)&msg_handshake, sizeof(Sdc_MsgSHandshake_st));
        // if (status != SPITP_E_OK)
        // {
        //     retVal = E_NOT_OK;
        // }
        // else
        // {
        //     ServiceHdl_handshake = e_Sdc_HandShakeStatus_Sync;
        // }
    }
    else if (ServiceHdl_handshake == e_Sdc_HandShakeStatus_Sync)
    {
        if (sync == SDC_HANDSHAKE_ACK + 1)
        {
            ServiceHdl_handshake = e_Sdc_HandShakeStatus_Est;
            //  hb_McuSyncJx_RequestStart(TRUE, 0);
        }
        else
        {
            ServiceHdl_handshake = e_Sdc_HandShakeStatus_None;
        }
    }
    return retVal;
}

/*******************************************QA*************************************************************/

/**
 * \functions Sdc_Core_QaMonitorHandler_Init
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
static FUNC(void, RTE_CODE)  Sdc_Core_QaMonitorHandler_Init(void)
{
    memset(&Sdc_QaMonitorStateInfo, 0x00, sizeof(s_Sdc_QaMonitorStateInfo_t));
    Sdc_QaMonitorStateInfo.SeedKeyIndex_Last = 0xff;
}

/**
 * \functions Sdc_Core_QaMonitorHandler_Main
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
static FUNC(void, RTE_CODE) Sdc_Core_QaMonitorHandler_Main(void)
{
    /*TODO : Check the HandShake state*/
    if(e_Sdc_HandShakeStatus_Est == ServiceHdl_handshake)
    {
        /*TODO : Send Seed Message Control*/
        Sdc_Core_QaMonitorHandler_SendSeed();

        /*TODO : Status Updated*/
        Sdc_Core_QaMonitorHandler_UpdatedState();
    }
    else
    {
        /*TODO : Doing nothing*/
    }
}

void Sdc_Core_QaMonitorHandler_HandlerKey(uint8 Key)
{
    Sdc_QaMonitorStateInfo.RxKeyMsgCnt++;
    /*TODO : Clear the wait key flag*/
    Sdc_QaMonitorStateInfo.WaitRxKey = FALSE;
    /*TODO : When received the Key,clean the counter*/
    Sdc_QaMonitorStateInfo.ContinuousRxKeyTimeoutErrorCnt = 0x00;

    /*TODO : Check the Key is correct*/
    if(Key == Sdc_QaMonitorSeedKey[Sdc_QaMonitorStateInfo.SeedKeyIndex].Key)
    {
        Sdc_QaMonitorStateInfo.ContinuousKeyErrorCnt = 0x00;
    }
    else
    {
        Sdc_QaMonitorStateInfo.KeyErrorCnt++;
        if(Sdc_QaMonitorStateInfo.KeyErrorCnt >= 0xFF)
        {
            Sdc_QaMonitorStateInfo.KeyErrorCnt = 0xFF;
        }
        else
        {
            /*TODO : Doing nothing*/
        }

        Sdc_QaMonitorStateInfo.ContinuousKeyErrorCnt++;
        if(Sdc_QaMonitorStateInfo.ContinuousKeyErrorCnt >= SDC_QAMONITOR_CONTINUOUSKEYERROR_COUNTER_THRESHOLD)
        {
            Sdc_QaMonitorStateInfo.ContinuousKeyErrorCnt = SDC_QAMONITOR_CONTINUOUSKEYERROR_COUNTER_THRESHOLD;            
        }
        else
        {
            /*TODO : Doing nothing*/
        }
    }

    Sdc_QaMonitorStateInfo.SeedKeyIndex++;
    if(Sdc_QaMonitorStateInfo.SeedKeyIndex >= SDC_QAMONITOR_SEED_KEY_NUMBER)
    {
        Sdc_QaMonitorStateInfo.SeedKeyIndex = 0x00;
    }
    else
    {
        /*TODO : Doing nothing*/
    }
}

e_Sdc_QaMonitorErrorStatus_t Sdc_Core_QaMonitorHandler_GetErrorStatus(void)
{
    return Sdc_QaMonitorStateInfo.ErrorStatus;
}

/*==================[internal function definitions]=========================*/
static void Sdc_Core_OtaSendHandler_Main(void)
{
    // e_Sdc_HandShakeState_t HandShakeState;

    // HandShakeState = Sdc_Core_Handshake_GetStatus();
    // /*TODO : Check the HandShake state*/
    // if(e_Sdc_HandShakeStatus_Est == HandShakeState)
    // {
    //     Sdc_Core_J3_ReadDidData_0xF187_Condition();
    //     Sdc_Core_J3_ReadDIDData_0xF089_Condition();
    //     Sdc_Core_J3_ReadDIDData_0xF086_Condition();
    // }
    // else
    // {
    //     /*TODO : Doing nothing*/
    // }
}

static void Sdc_Core_QaMonitorHandler_SendSeed(void)
{
    Sdc_QaMonitorStateInfo.TxSeedCycleCounter++;
    if(Sdc_QaMonitorStateInfo.TxSeedCycleCounter >= (SDC_QAMONITOR_TXSEED_CYCLE / SDC_MAIN_FUNCTION_PERIOD_TIME))
    {
        Sdc_QaMonitorStateInfo.TxSeedCycleCounter = 0x00;
        if(Sdc_QaMonitorStateInfo.SeedKeyIndex != Sdc_QaMonitorStateInfo.SeedKeyIndex_Last)
        {
            Sdc_QaMonitorStateInfo.RxKeyTimeWindowCounter = 0x00;
            Sdc_QaMonitorStateInfo.WaitRxKey = TRUE;
            Sdc_QaMonitorStateInfo.SeedKeyIndex_Last = Sdc_QaMonitorStateInfo.SeedKeyIndex;
            Sdc_QaMonitorStateInfo.TxSeedMsgCnt++;
            QA_Seed = Sdc_QaMonitorSeedKey[Sdc_QaMonitorStateInfo.SeedKeyIndex].Seed;
            // now cycle send to j3
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

static void Sdc_Core_QaMonitorHandler_UpdatedState(void)
{
    /*TODO : Check the Timeout Error*/
    if(TRUE == Sdc_QaMonitorStateInfo.WaitRxKey)
    {
        Sdc_QaMonitorStateInfo.RxKeyTimeWindowCounter++;
        if(Sdc_QaMonitorStateInfo.RxKeyTimeWindowCounter >= (SDC_QAMONITOR_RXKEY_TIMEWINDOW_THRESHOLD / SDC_MAIN_FUNCTION_PERIOD_TIME))
        {
            Sdc_QaMonitorStateInfo.RxKeyTimeWindowCounter = 0x00;
            Sdc_QaMonitorStateInfo.RxKeyTimeoutErrorCnt++;
            if(Sdc_QaMonitorStateInfo.RxKeyTimeoutErrorCnt >= 0xFF)
            {
                Sdc_QaMonitorStateInfo.RxKeyTimeoutErrorCnt = 0xFF;
            }
            else
            {
                /*TODO : Doing nothing*/
            }

            Sdc_QaMonitorStateInfo.ContinuousRxKeyTimeoutErrorCnt++;
            if(Sdc_QaMonitorStateInfo.ContinuousRxKeyTimeoutErrorCnt >= SDC_QAMONITOR_CONTINUOUSTIMEOUTERROR_COUNTER_THRESHOLD)
            {
                Sdc_QaMonitorStateInfo.ContinuousRxKeyTimeoutErrorCnt = SDC_QAMONITOR_CONTINUOUSTIMEOUTERROR_COUNTER_THRESHOLD;
            }
            else
            {

            }

        }
        else
        {
            /*TODO : Doing nothing*/
        }
    }
    else
    {
        Sdc_QaMonitorStateInfo.RxKeyTimeWindowCounter = 0x00;
    }
    
    /*TODO : Updated the Error Status*/
    if(e_Sdc_QaMonitorErrorStatus_Error != Sdc_QaMonitorStateInfo.ErrorStatus)
    {
        Sdc_QaMonitorStateInfo.ErrorStatus = e_Sdc_QaMonitorErrorStatus_Normal;
        if(Sdc_QaMonitorStateInfo.ContinuousKeyErrorCnt >= 1)
        {
            Sdc_QaMonitorStateInfo.ErrorStatus = e_Sdc_QaMonitorErrorStatus_KeyError;
        }
        else
        {
            /*TODO : Doing nothing*/
        }

        if(Sdc_QaMonitorStateInfo.ContinuousRxKeyTimeoutErrorCnt >= 1)
        {
            Sdc_QaMonitorStateInfo.ErrorStatus = e_Sdc_QaMonitorErrorStatus_Timeout;
        }
        else
        {
            /*TODO : Doing nothing*/
        }   

        if((Sdc_QaMonitorStateInfo.ContinuousKeyErrorCnt >= SDC_QAMONITOR_CONTINUOUSKEYERROR_COUNTER_THRESHOLD) || (Sdc_QaMonitorStateInfo.ContinuousRxKeyTimeoutErrorCnt >= SDC_QAMONITOR_CONTINUOUSTIMEOUTERROR_COUNTER_THRESHOLD))
        {
            Sdc_QaMonitorStateInfo.ErrorStatus = e_Sdc_QaMonitorErrorStatus_Error;
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

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

