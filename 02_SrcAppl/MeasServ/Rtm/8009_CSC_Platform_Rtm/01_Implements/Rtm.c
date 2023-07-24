#include "Rtm.h"
#if(RTM_SEND_LOGGING_ENABLE == STD_ON)
#include "LoggingType.h"
#endif
/*******************************************************************************************
 *                                  Macro definition
*******************************************************************************************/
#define RTM_ERR_TP_NOERR                0x00
#define RTM_ERR_TP_THREAD_STAREDNOTEND  0x01
#define RTM_ERR_TP_LASTTHREAD_NOT_FOUND 0x02

#define RTM_ERR_CPULOAD_NOERR           0x00
#define RTM_ERR_CPULOAD_OVER99PERCENT   0x01
#define RTM_ERR_CPULOAD_TSKPRIONOTLOW   0x02

/*******************************************************************************************
 *                                  Function declaration
*******************************************************************************************/
void Rtm_StartThread(uint8 CoreId, RtmThreadType_t threadtype, uint16 threadid);
void Rtm_EndThread(uint8 CoreId, RtmThreadType_t threadtype, uint16 threadid);

static Rtm_ThreadPool_t* const GetThreadsPool(uint8 CoreId);
static Rtm_CpuLoad_t* GetCpuLoadTable(uint8 CoreId);
static Rtm_TaskIsrTable_t* GetTaskIsrTable(void);
static uint8 GetTaskIsrIndex(RtmThreadType_t threadtype, uint16 threadid);
static void Rtm_initFunc(void);
static void Rtm_UpdateMaxPreemptedTime(uint8 PreemptedCnt,RtmThread_t* thread);
static void RtmThread_IndexDec(uint8 CoreId, uint16* index);
static void RtmThread_IndexInc(uint8 CoreId);
static void Rtm_UpdateCntCycleCpuload(uint8 CoreId, uint32 timestamp);
static void Rtm_UpdateExecutionTime(uint8 CoreId);
static void Rtm_CheckAndUpdateCpuLoad(uint8 CoreId, uint32 CycleTime);

/*******************************************************************************************
 *                                  Internal Variable declaration
*******************************************************************************************/
uint16 debug_DeltaLastEndLastStart[4];
uint8 InitOnce = FALSE;
/*******************************************************************************************
 *                                  External Variable declaration
*******************************************************************************************/
extern Rtm_ThreadHandler_t Rtm_Handler ;
/*******************************************************************************************
 *                                  Function definition
*******************************************************************************************/
static void Rtm_initFunc(void)
{
    Rtm_TaskIsrTable_t* TIT_p;
    uint8 index;

    TIT_p = GetTaskIsrTable();

    for(index = 0 ; index < RTM_ISR_NUMBER; index ++ )
    {
        TIT_p->TaskIsr[index].Type = RTM_ISR;
        TIT_p->TaskIsr[index].Id = index;
    }
    for(index = RTM_ISR_NUMBER; index < (RTM_ISR_NUMBER + RTM_TASK_NUMBER); index ++)
    {
        TIT_p->TaskIsr[index].Type = RTM_TSK;
        TIT_p->TaskIsr[index].Id = index - RTM_ISR_NUMBER;
    }
    InitOnce = TRUE;
}

void Rtm_StartThread(uint8 CoreId, RtmThreadType_t threadtype, uint16 threadid)
{
    uint32 timestamp;
    Rtm_ThreadPool_t* const TP_p = GetThreadsPool(CoreId);

    if(TRUE != InitOnce)
    {
        Rtm_initFunc();
    }

    timestamp = Rtm_GetLocalTimeUs(CoreId);
    if(NULL_PTR != TP_p)
    {
        RtmThread_IndexInc(CoreId);

        TP_p->Threads_p[TP_p->LastStart].Type           = threadtype;
        TP_p->Threads_p[TP_p->LastStart].ThreadId       = threadid;
        Rtm_UpdateCntCycleCpuload(CoreId,timestamp);

        TP_p->Threads_p[TP_p->LastStart].TStampUs_start = timestamp;
        TP_p->Threads_p[TP_p->LastStart].ExecTimeUs_Net = 0;
        TP_p->Threads_p[TP_p->LastStart].TStampUs_end   = 0;
    }

}
//test
uint32 Cycletime_View;
uint32 prev_tstamp;
uint32 curr_tstamp;
uint16 target_threadid = RTM_ISR_NUMBER + 16;
volatile uint8 dummy;
void Rtm_EndThread(uint8 CoreId, RtmThreadType_t threadtype, uint16 threadid)
{
    Rtm_ThreadPool_t* TP_p = NULL_PTR;
    Rtm_CpuLoad_t* Cpuload_p = NULL_PTR;
    uint32 timestamp;
    uint16 index;
    uint8 PreemptedCnt = 0;
    uint32 PreemptedTimeSum = 0;
    uint8 FoundFlag = FALSE;

    timestamp = Rtm_GetLocalTimeUs(CoreId);
    TP_p = GetThreadsPool(CoreId);
    Cpuload_p = GetCpuLoadTable(CoreId);

    //test
    if(((target_threadid - RTM_ISR_NUMBER) == threadid)&&(RTM_TSK == threadtype))
    {
        dummy++;
    }
    if((NULL_PTR != TP_p)&&(NULL_PTR != Cpuload_p))
    {
        index = TP_p->LastStart;
        do{
            if((threadtype == TP_p->Threads_p[index].Type)
            &&(threadid == TP_p->Threads_p[index].ThreadId))
            {
                TP_p->Threads_p[index].TStampUs_end = timestamp;
                FoundFlag = TRUE;
                break;
            }
            else
            {
                PreemptedTimeSum += TP_p->Threads_p[index].ExecTimeUs_Net;
                PreemptedCnt ++;
            }
            RtmThread_IndexDec(CoreId,&index);

        }while(index != TP_p->LastStart);
        
        if(TRUE == FoundFlag)
        {
            //update thread execution time net
            TP_p->Threads_p[index].ExecTimeUs_Net  = TP_p->Threads_p[index].TStampUs_end - 
                                                    TP_p->Threads_p[index].TStampUs_start - 
                                                    PreemptedTimeSum;

            //update sum of execution time net in each core
            Cpuload_p->ExecTimeNetSum_Us += TP_p->Threads_p[index].ExecTimeUs_Net;

            TP_p->LastEnd = index;

            /*Update TaskIsrTable*/
            Rtm_UpdateMaxPreemptedTime(PreemptedCnt,&(TP_p->Threads_p[TP_p->LastEnd]));
            Rtm_UpdateExecutionTime(CoreId);
        }
        else
        {
            TP_p->Err |= RTM_ERR_TP_THREAD_STAREDNOTEND;
        }
        //debug
        sint16 delta;
        delta = TP_p->LastStart - TP_p->LastEnd;
        if((delta > 0)&&(delta > debug_DeltaLastEndLastStart[CoreId]))
        {
            debug_DeltaLastEndLastStart[CoreId] = (uint16)delta;
        }
    }
}

static void Rtm_UpdateMaxPreemptedTime(uint8 PreemptedCnt,RtmThread_t* thread)
{
    Rtm_TaskIsrTable_t* TIT_p;
    uint16 TIT_index;

    TIT_p = GetTaskIsrTable();
    TIT_index = GetTaskIsrIndex(thread->Type,thread->ThreadId);

    if(PreemptedCnt > TIT_p->TaskIsr[TIT_index].PreemptedCntMax)
    {
        TIT_p->TaskIsr[TIT_index].PreemptedCntMax = PreemptedCnt;
    }
}

static void Rtm_UpdateCntCycleCpuload(uint8 CoreId, uint32 timestamp)
{
    Rtm_ThreadPool_t* TP_p = NULL_PTR;
    Rtm_TaskIsrTable_t* TIT_p = NULL_PTR;
    
    uint16  TIT_index;
    uint32  CycleTime;
    
    TP_p = GetThreadsPool(CoreId);
    TIT_p = GetTaskIsrTable();


    if((NULL_PTR != TP_p)&&(NULL_PTR != TIT_p))
    {
        
        TIT_index = GetTaskIsrIndex(TP_p->Threads_p[TP_p->LastStart].Type, 
                                    TP_p->Threads_p[TP_p->LastStart].ThreadId);
        CycleTime = timestamp - TIT_p->TaskIsr[TIT_index].CycleTimestampUs;
        if(target_threadid == TIT_index)//test 
        {
            Cycletime_View = CycleTime;
            prev_tstamp = TIT_p->TaskIsr[TIT_index].CycleTimestampUs;
            curr_tstamp = timestamp;
        }
        
        //update cycle time but skip 1st time
        if(TIT_p->TaskIsr[TIT_index].ExecCnt != 0)
        {
            TIT_p->TaskIsr[TIT_index].CycleUs_Ave = (CycleTime + TIT_p->TaskIsr[TIT_index].CycleUs_Ave * (TIT_p->TaskIsr[TIT_index].ExecCnt - 1)) 
                                                    / TIT_p->TaskIsr[TIT_index].ExecCnt;
            //Update max cycle time
            if(TIT_p->TaskIsr[TIT_index].CycleUs_Max < CycleTime)
            {
                TIT_p->TaskIsr[TIT_index].CycleUs_Max = CycleTime;
            }
            //check and update Cpu load
            Rtm_CheckAndUpdateCpuLoad(CoreId, CycleTime);
        }
        //update cycle timestamp
        TIT_p->TaskIsr[TIT_index].CycleTimestampUs = timestamp;
        //Update execution counter
        //Maximum ExecCnt 65535 (uint16), larger size will cause CycleUs_Ave overflow
        TIT_p->TaskIsr[TIT_index].ExecCnt ++;
    }
}
static void Rtm_CheckAndUpdateCpuLoad(uint8 CoreId, uint32 CycleTime)
{
    Rtm_ThreadPool_t* TP_p = NULL_PTR;
    Rtm_TaskIsrTable_t* TIT_p;
    Rtm_CpuLoad_t* Cpuload_p;

    uint16 TIT_index;
    uint16 TP_index;

    
    TP_p = GetThreadsPool(CoreId);
    TIT_p = GetTaskIsrTable();
    Cpuload_p = GetCpuLoadTable(CoreId);

    TIT_index = GetTaskIsrIndex(TP_p->Threads_p[TP_p->LastStart].Type, 
                                TP_p->Threads_p[TP_p->LastStart].ThreadId);

    if((NULL_PTR != TP_p)&&(NULL_PTR != TIT_p)&&(NULL_PTR != Cpuload_p)&&
    (RTM_TSK == TP_p->Threads_p[TP_p->LastStart].Type)&&
    (0 != CycleTime))
    {

        switch (TP_p->Threads_p[TP_p->LastStart].ThreadId)
        {
        CASE_RTM_LOWEST_PRIO_TASK

            if(TIT_p->TaskIsr[TIT_index].ExecCnt > 1)
            {
                //Check last thread.
                //If lowest priority task configured in RTM matched with the actual lowest priority task, 
                //last thread should always finished when lowest priority task starts to run.
                TP_index = TP_p->LastStart;
                RtmThread_IndexDec(CoreId,&TP_index);
                if(0 == TP_p->Threads_p[TP_index].TStampUs_end)
                {
                    Cpuload_p->Err |= RTM_ERR_CPULOAD_TSKPRIONOTLOW;
                }
                else
                {
                    Cpuload_p->CoreLoad = (uint8)(Cpuload_p->ExecTimeNetSum_Us * 100 / CycleTime);
                    
#                   if(RTM_SEND_LOGGING_ENABLE == STD_ON)
                    Log_Cfg_t Cfg;
                    static uint8 CoreLoad[4];
                    Cfg.ModuleId = RTM_MODULE_ID;
                    Cfg.Mode = LOGGING_MODEMASK_CAN;
                    Cfg.DataLength = 4u;
                    CoreLoad[CoreId] = Cpuload_p->CoreLoad;
                    if(Cpuload_p->CoreLoad > RTM_SEND_LOGGING_WARN_THRESHOLD)
                    {
                        Cfg.Level = LOGGING_LEVEL_WARNING;
                        (void)LOGGING_SEND(Cfg,&CoreLoad,NULL_PTR);
                    }
                    else if(Cpuload_p->CoreLoad > RTM_SEND_LOGGING_INFO_THRESHOLD)
                    {
                        Cfg.Level = LOGGING_LEVEL_INFO;
                        (void)LOGGING_SEND(Cfg,&CoreLoad,NULL_PTR);
                    }
#                   endif/*RTM_SEND_LOGGING_ENABLE*/

                    if(Cpuload_p->CoreLoad > 99u)
                    {
                        Cpuload_p->Err |= RTM_ERR_CPULOAD_OVER99PERCENT;
                    }
                    Cpuload_p->ExecTimeNetSum_Us = 0;
                    if(Cpuload_p->CoreLoad > Cpuload_p->CoreLoad_Max )
                    {
                        Cpuload_p->CoreLoad_Max = Cpuload_p->CoreLoad;
                    } 

                    Cpuload_p->CoreLoad_Ave = (uint8)((Cpuload_p->CoreLoad_Ave * (TIT_p->TaskIsr[TIT_index].ExecCnt - 1) 
                                                    + Cpuload_p->CoreLoad) / TIT_p->TaskIsr[TIT_index].ExecCnt);
                }
            }
            else
            {
                //Ignore the CPU consumption analysis at the very beginning 
                //since The lowest priority task has no earlier thread to calculate cycle time at 1st time. 
                //Reset the summarize of execution time net
                Cpuload_p->ExecTimeNetSum_Us = 0;
            }
            break;

        default:
            //Not the task with the lowest priority, do nothing
            break;
        }
    }
}


static void Rtm_UpdateExecutionTime(uint8 CoreId)
{
    Rtm_ThreadPool_t* TP_p = NULL_PTR;
    Rtm_TaskIsrTable_t* TIT_p;
    uint16 TIT_index;
    uint32 exectime_gross;

    TP_p = GetThreadsPool(CoreId);
    TIT_p = GetTaskIsrTable();
    if((NULL_PTR != TP_p)&&(NULL_PTR != TIT_p))
    {
        TIT_index = GetTaskIsrIndex(TP_p->Threads_p[TP_p->LastEnd].Type, 
                                    TP_p->Threads_p[TP_p->LastEnd].ThreadId);

        //update average execution time gross
        exectime_gross =    TP_p->Threads_p[TP_p->LastEnd].TStampUs_end -
                            TP_p->Threads_p[TP_p->LastEnd].TStampUs_start;

        TIT_p->TaskIsr[TIT_index].ExecTimeUs_Gross_Ave  = (TIT_p->TaskIsr[TIT_index].ExecTimeUs_Gross_Ave * (TIT_p->TaskIsr[TIT_index].ExecCnt - 1) 
                                                        + exectime_gross) / TIT_p->TaskIsr[TIT_index].ExecCnt;
        //update max execution time gross
        if(exectime_gross > TIT_p->TaskIsr[TIT_index].ExecTimeUs_Gross_Max)
        {
            TIT_p->TaskIsr[TIT_index].ExecTimeUs_Gross_Max = exectime_gross;
        }

        //update average execution time net
        TIT_p->TaskIsr[TIT_index].ExecTimeUs_Net_Ave    = (TIT_p->TaskIsr[TIT_index].ExecTimeUs_Net_Ave * (TIT_p->TaskIsr[TIT_index].ExecCnt - 1)
                                                        + TP_p->Threads_p[TP_p->LastEnd].ExecTimeUs_Net) / TIT_p->TaskIsr[TIT_index].ExecCnt;
        //update max execution time net
        if(TP_p->Threads_p[TP_p->LastEnd].ExecTimeUs_Net > TIT_p->TaskIsr[TIT_index].ExecTimeUs_Net_Max)
        {
            TIT_p->TaskIsr[TIT_index].ExecTimeUs_Net_Max = TP_p->Threads_p[TP_p->LastEnd].ExecTimeUs_Net;
        }
    }

}

static void RtmThread_IndexDec(uint8 CoreId, uint16* index)
{
    uint16 thread_numb;
    switch (CoreId)
    {
    RTM_THREADS_NUMBER_CFG
    default:
        break;
    }
    if(NULL_PTR != index)
    {
        if(0 != *index)
        {
            *index = *index - 1;
        }
        else
        {
            *index = thread_numb - 1;
        }
    }
}

static void RtmThread_IndexInc(uint8 CoreId)
{
    uint16 thread_numb;
    switch (CoreId)
    {
    RTM_THREADS_NUMBER_CFG
    default:
        break;
    }
    Rtm_Handler.Rtm_ThreadPool_p[CoreId]->LastStart = (Rtm_Handler.Rtm_ThreadPool_p[CoreId]->LastStart + 1) % thread_numb;
}

static uint8 GetTaskIsrIndex(RtmThreadType_t threadtype, uint16 threadid)
{
    return(RTM_ISR == threadtype ? threadid : (RTM_ISR_NUMBER + threadid));
}

static Rtm_TaskIsrTable_t* GetTaskIsrTable(void)
{
    Rtm_TaskIsrTable_t* TIT_p = NULL_PTR;
    TIT_p = &(Rtm_Handler.Rtm_TaskIsrTable);
    return (TIT_p);
}

static Rtm_CpuLoad_t* GetCpuLoadTable(uint8 CoreId)
{
    Rtm_CpuLoad_t* CpuLoad_p = NULL_PTR;
    CpuLoad_p = &(Rtm_Handler.Rtm_CpuLoad)[CoreId];
    return (CpuLoad_p);
}
static Rtm_ThreadPool_t* const GetThreadsPool(uint8 CoreId)
{
    return (Rtm_Handler.Rtm_ThreadPool_p[CoreId]);
}
