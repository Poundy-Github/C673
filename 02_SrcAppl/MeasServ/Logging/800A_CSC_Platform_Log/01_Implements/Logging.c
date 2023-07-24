/***
 * Concept:
 * Provide Interfaces to SWCs
 * Main function shall cyclically call transferring interface such as MTSI/COM/CDM to send debug data
 * 
*/
#include <Rte_Logging.h>
#include "Logging.h"
#include "Logging_Cfg.h"

/**********************************************************************************************************
 *                                      Variable Definition
**********************************************************************************************************/
LogRecord_t LogRecord[LOGGING_QUEUE_SIZE];
LogHandler_t LogHandler = {0,0,0,0,{&LogRecord[0]}};
static uint8   ExecutionCounter_LogMain;


/**********************************************************************************************************
 *                                      Function Declaration
**********************************************************************************************************/
Log_ReturnType_t Logging_SendDataWritingToQueue(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp);
Log_ReturnType_t Logging_SendDataImmediately(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp);
uint16 Logging_IndexDecrement(uint16 Index);
Log_ReturnType_t Logging_ConditionChcek(Log_Cfg_t Cfg, uint8 const * const Data_p);
/**********************************************************************************************************
 *                                      Function Definition
**********************************************************************************************************/
Log_ReturnType_t Logging_SendData(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp)
{
    Log_ReturnType_t ret;

    if((NULL_PTR != Data_p)&&                                       /*Refuse invalid pointer*/
    (LogHandler.Tail != Logging_IndexDecrement(LogHandler.Head)))   /*Refuse since queue overflow*/
    {
        if(LOGGING_RET_CONDITION_ACCEPT == Logging_ConditionChcek(Cfg, Data_p))  /*Refuse invalid Module id, Mask or data length*/
        {
            if(TRUE == Cfg.ImmediateSend)
            {
                // ret = Logging_SendDataImmediately(Cfg,Data_p,Cbk_fp);
            }
            else
            {
                ret = Logging_SendDataWritingToQueue(Cfg,Data_p,Cbk_fp);
            }
        }
    }
    else{
        ret = LOGGING_RET_GENERALREJECT;
    }
    return ret;
}
FUNC(void, RTE_CODE) Logging_InitFunction(void)
{

}

FUNC(void, RTE_CODE) Logging_MainFunction(void)//to be implemented in 5ms task
{
    /*  EP:   00 05 10 15 20 25 30 35 40 45 50 55 00 05 10    */
    /*  CAN      |     |     |     |     |     |     |        */    /*10ms*/
    /*  MTSI  |                 |                 |           */    /*30ms*/
    /*  CDM         |        |        |        |        |     */    /*15ms*/
    /*  J3    |        |        |        |        |           */    /*15ms*/
    /*  UART     |        |        |        |        |        */    /*15ms*/
    /*  ETH            |                 |                    */    /*30ms*/
    
    //TODO: //should defined in LoggingIF
    if(1u == (ExecutionCounter_LogMain % 2))
    {
        LoggingIF_SendData_ViaCAN();
    }
    if(0u == (ExecutionCounter_LogMain % 6))
    {
        LoggingIF_SendData_ViaMTSI();
    }
    if(2u == (ExecutionCounter_LogMain % 3))
    {
        //LoggingIF_StoreData_ToCDM();
    }
    if(0u == (ExecutionCounter_LogMain % 3))
    {
        //LoggingIF_StoreData_ToJ3();
    }
    //Not implemented
    //LoggingIF_SendData_ViaETH();
    //LoggingIF_SendData_ViaUART();

    ExecutionCounter_LogMain = (ExecutionCounter_LogMain + 1) % LOGGING_SCHEDULE_CNT_MAX;

}

Log_ReturnType_t Logging_ConditionChcek(Log_Cfg_t Cfg, uint8 const * const Data_p)
{
    Log_ReturnType_t ret;

    if((LOGGING_MODEMASK_ETH == (Cfg.Mode & LOGGING_MODEMASK_ETH))||
    (LOGGING_MODEMASK_UART == (Cfg.Mode & LOGGING_MODEMASK_UART))||
    (LOGGING_MODEMASK_CDM == (Cfg.Mode & LOGGING_MODEMASK_CDM))||
    (LOGGING_MODEMASK_J3 == (Cfg.Mode & LOGGING_MODEMASK_J3)))
    {
        ret = LOGGING_RET_MASK_NOTSUPPORT;
    }
    else if((LOGGING_DATALENTH_THRESHOLD_LOW > Cfg.DataLength)||
    (LOGGING_DATALENTH_THRESHOLD_HIGH < Cfg.DataLength))
    {
        ret = LOGGING_RET_DATALENTH_NOTACCEPT;
    }
    else
    {
        ret = LOGGING_RET_CONDITION_ACCEPT;
    }
    return ret;
}

uint16 Logging_IndexDecrement(uint16 Index)
{
    uint16 RetIndex;
    if(0 != Index)
    {
        RetIndex = Index - 1;
    }
    else
    {
        RetIndex = LOGGING_QUEUE_SIZE - 1;
    }
    return RetIndex;
}

Log_ReturnType_t Logging_SendDataImmediately(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp)
{
    Log_ReturnType_t ret;
    ret = LoggingIF_SendDataImmediately(Cfg,Data_p,Cbk_fp);
    return ret;
}

Log_ReturnType_t Logging_SendDataWritingToQueue(Log_Cfg_t Cfg, uint8 const * const Data_p, const Log_Cbk_t Cbk_fp)
{
    Log_ReturnType_t  ret;
    uint64 Sec;
    uint64 Nanosec;

    (void)Time_GetTimeStampSec(&Sec);
    (void)Time_GetTimeStampNs(&Nanosec);

    LogHandler.LogQueue_p[LogHandler.Head].Cfg   = Cfg;
    LogHandler.LogQueue_p[LogHandler.Head].Data_p = Data_p;
    LogHandler.LogQueue_p[LogHandler.Head].Cbk_fp = Cbk_fp;
    LogHandler.LogQueue_p[LogHandler.Head].TimestampS = (uint32)Sec;
    LogHandler.LogQueue_p[LogHandler.Head].TimestampUS = (uint32)((Nanosec - (Sec * 1000000000ull))*0.001);

    LogHandler.Head = (LogHandler.Head + 1) % LOGGING_QUEUE_SIZE;

    ret = LOGGING_RET_ASYNCJOB_ACCEPT;
    return ret;
}
