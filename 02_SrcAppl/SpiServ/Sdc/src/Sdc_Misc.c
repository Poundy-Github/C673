/* ==================[Includes]=============================================== */
#include "Sdc_Misc.h"
#include "os.h"

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
/*==================[.bss]==============================*/
#define SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"


#define SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sdc_MemMap.h"

/*==================[macros]=================================================*/

/*==================[internal function declarations]========================*/

/*==================[external function definitions]=========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

FUNC(void, RTE_CODE)Sdc_Misc_InitFunction(void)
{

}

FUNC(void, RTE_CODE)Sdc_Misc_DeInitFunction(void)
{
    
}

FUNC(void, RTE_CODE)Sdc_Misc_MainFunction(void)
{
}

boolean Sdc_Misc_EventSendMsg_poolIsFull(s_SdcSendEventMsgPoolType_st *pool)
{
    return (pool->counter >= SDC_SENDHANDLER_EVENTMSG_TABLESIZE);
}

boolean Sdc_Misc_EventSendMsg_poolIsEmpty(s_SdcSendEventMsgPoolType_st *pool)
{
    return (pool->counter == 0);
}

uint8 Sdc_Misc_EventSendMsg_poolPush(s_SdcSendEventMsgPoolType_st *pool, const s_Sdc_MsgSendHandleDataInfo_Event_st *eventData)
{
    boolean full;
    uint8 retVal = 0;

    if(eventData->len <= SDC_SENDHANDLER_EVENTMSG_MAXSIZE)
    {
        // SPITP_MASTER_ENTER();
        GetSpinlock(OsSpinlock_EventMsgPool);
        full = Sdc_Misc_EventSendMsg_poolIsFull(pool);
        if (full != TRUE)
        {
            //len + 4 means msgid and subid of the event data
            memcpy(&pool->Sdc_MsgSendHandleDataInfo_Event[pool->tail], eventData, eventData->len + 4);
            pool->Sdc_MsgSendHandleDataInfo_Event[pool->tail].len = eventData->len;
            pool->counter++;
            pool->tail = (pool->tail + 1) % SDC_SENDHANDLER_EVENTMSG_TABLESIZE;
        }
        else
        {
            retVal = 1;
            //TODO: Errh
        }
        ReleaseSpinlock(OsSpinlock_EventMsgPool);
    }
    else    // event data large than the event pool buffer
    {
        retVal = 1;
        //TODO: Errh
    }
    // SPITP_MASTER_EXIT();
    return retVal;
}

void Sdc_Misc_EventSendMsg_poolPop(s_SdcSendEventMsgPoolType_st *pool, s_Sdc_MsgSendHandleDataInfo_Event_st *eventData)
{
    boolean empty;
    // SPITP_MASTER_ENTER();
    GetSpinlock(OsSpinlock_EventMsgPool);
    empty = Sdc_Misc_EventSendMsg_poolIsEmpty(pool);
    if (empty != TRUE)
    {
        memcpy(eventData, &pool->Sdc_MsgSendHandleDataInfo_Event[pool->head], pool->Sdc_MsgSendHandleDataInfo_Event[pool->head].len + 4);
        eventData->len = pool->Sdc_MsgSendHandleDataInfo_Event[pool->head].len;
        pool->counter--;
        pool->head = (pool->head + 1) % SDC_SENDHANDLER_EVENTMSG_TABLESIZE;
    }  
    ReleaseSpinlock(OsSpinlock_EventMsgPool);
    // SPITP_MASTER_EXIT();
    return;
}

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

/*==================[internal function definitions]=========================*/
