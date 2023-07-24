/* ==================[Includes]=============================================== */
#include "Sdc_Core.h"
#include "Sdc_Cfg.h"
#include "SpiTpMaster.h"
#include "Sdc_Core_Type.h"
#include "Sdc_Core.h"
#include "Sdc_Perception.h"
#include "Sdc_Fusion.h"
#include "Sdc_Lcfg.h"
#include "Sdc_ReceiveHandler.h"
#include "fs_check.h"


/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

static s_Sdc_SpiMsgPayload_t Sdc_SpiMsgPayload_Rx;

#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"
/*==================[macros]=================================================*/
// #define memset(d, s, n) TS_MemSet(d, s, n)
// #define memcpy(d, s, n) TS_MemCpy(d, s, n)

/*==================[internal function declarations]========================*/

/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

void Sdc_ReceiveHandler_InitFunction(void)
{
    memset(&Sdc_SpiMsgPayload_Rx, 0, sizeof(s_Sdc_SpiMsgPayload_t));
}
void Sdc_ReceiveHandler_DeInitFunction(void)
{
    //TODO
}
void Sdc_ReceiveHandler_MainFunction(void)
{
    boolean IsUpdated = FALSE;

    do
    {
        uint8 i = 0x00;
        uint16 Length = 0x00;
        IsUpdated = SpiTp_RxMsgIsUpdated();
        if (IsUpdated == TRUE)
        {
            #if !FS_EXEC_DISABLED
            FsCheck_IpcServerSetSocState(1); /*With ipc communication Set Status is TRUE */
            #endif

            /*TODO : Clear the Rx Buffer*/
            memset(&Sdc_SpiMsgPayload_Rx, 0x00, sizeof(s_Sdc_SpiMsgPayload_t));
            /*TODO : Read data from SpiTp*/
            Length = SpiTp_masterRecieve((uint8 *)&Sdc_SpiMsgPayload_Rx);
			
            /*TODO : Check the data length*/
            if (Length > 0)
            {
                for (i = 0x00; i < SDC_SPIRECEIVEHANDLERTABLE_SIZE; i++)
                {
                    /*TODO : Check the Id is same*/
                    if (Sdc_SpiMsgPayload_Rx.Header.MsgType == Sdc_SpiReceiveHandlerTable[i].Id)
                    {
                        if (NULL_PTR != Sdc_SpiReceiveHandlerTable[i].HandlerFunction)
                        {
                            Sdc_SpiReceiveHandlerTable[i].HandlerFunction((const uint8 *)&Sdc_SpiMsgPayload_Rx.Data, Sdc_SpiMsgPayload_Rx.Header.DataLength);
                        }
                        break;
                    }
                }
                break;
            }
        }
        IsUpdated = SpiTp_RxMsgIsUpdated();
    } while (IsUpdated == TRUE);
}
uint8 Sdc_ReceiveHandler_Perception(const uint8 *Data, uint16 Length)
{
    if ((NULL_PTR != Data) && (0x00 != Length))
    {
        Sdc_Perception_RcvPerceptionDataFromJ3(Data, Length);
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}
uint8 Sdc_ReceiveHandler_CemOut(const uint8 *Data, uint16 Length)
{
    if ((NULL_PTR != Data) && (0x00 != Length))
    {
        Sdc_Fusion_RcvCemDataFromJ3(Data, Length);

        // memcpy(&Sdc_Cemdata, Data, Length);//Has an issue,when not copy in here,the data not copy to Sdc_Cemdata
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}
uint8 Sdc_ReceiveHandler_QaAnswer(const uint8 *Data, uint16 Length)
{
    if ((NULL_PTR != Data) && (0x00 != Length))
    {
        uint8 Answer = Data[0];

        Sdc_Core_QaMonitorHandler_HandlerKey(Answer);
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}
uint8 Sdc_ReceiveHandler_SocReplyInfo(const uint8 *Data, uint16 Length)
{
     /*TODO : Check the null pointer*/
    if ((NULL_PTR != Data) && (Length > 2))
    {
       Sdc_Diag_SocReplyInfo(Data, Length);
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}


uint8 Sdc_ReceiveHandler_DriveModeChangeRequest(const uint8 *Data, uint16 Length)
{
    /*TODO : Check the null pointer*/
    if ((NULL_PTR != Data) && (Length >= 5))
    {
        Sdc_Diag_DrivemodeChangeReq(Data, Length);
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}
uint8 Sdc_ReceiveHandler_DriveModeChangeResponse(const uint8 *Data, uint16 Length)
{
    /*TODO : Check the null pointer*/
    if ((NULL_PTR != Data) && (Length >= 5))
    {
        Sdc_Diag_DrivemodeChangeAck(Data, Length);
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}




uint8 Sdc_ReceiveHandler_Handshake(const uint8 *Data, uint16 Length)
{
    /*TODO : Check the null pointer*/
    if ((NULL_PTR != Data) && (0x00 != Length))
    {
        uint8 Sync = Data[0];
        Sdc_Core_Handshake_Request(Sync);
    }
    else
    {
        /*TODO : Doing nothing*/
    }

    return 0;
}
uint8 Sdc_ReceiveHandler_SocSysInfo(const uint8 *Data, uint16 Length)
{
    /*TODO : Check the null pointer*/
    if ((NULL_PTR != Data) && (0x00 != Length))
    {
        Sdc_Diag_SocSysInfo(Data, Length);
    }
    else
    {
        /*TODO : Doing nothing*/
    }
    return 0;
}
#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
/*==================[internal function definitions]=========================*/
