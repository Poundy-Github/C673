#include "Os_config.h"
#include "Platform_Types.h"
#include "Rtm_Config.h"

typedef enum 
{
    RTM_ISR  = 0,
    RTM_TSK = 1
}RtmThreadType_t;


typedef struct 
{
    RtmThreadType_t     Type;
    uint16              ThreadId;
    uint32              TStampUs_start;
    uint32              TStampUs_end;
    uint32              ExecTimeUs_Net;
}RtmThread_t;

typedef struct 
{
    uint16       LastStart;//indicate latest started thread
    uint16       LastEnd;//indicate latest ended thread
    uint8        Err;
    RtmThread_t* Threads_p;
}Rtm_ThreadPool_t;

typedef struct 
{
    RtmThreadType_t Type;
    uint16          Id;
    uint8           PreemptedCntMax;
    uint16          ExecCnt;
    uint32          CycleTimestampUs;
    uint32          CycleUs_Ave;
    uint32          CycleUs_Max;
    uint32          ExecTimeUs_Net_Ave;
    uint32          ExecTimeUs_Net_Max;
    uint32          ExecTimeUs_Gross_Ave;
    uint32          ExecTimeUs_Gross_Max;
}Rtm_TaskIsr_t;

typedef struct
{
    uint8           Err;
    Rtm_TaskIsr_t   TaskIsr[RTM_ISR_NUMBER + RTM_TASK_NUMBER];
}Rtm_TaskIsrTable_t;

typedef struct
{
    uint8   CoreLoad;
    uint8   CoreLoad_Ave;
    uint8   CoreLoad_Max;
    uint8   Err;
    uint32  ExecTimeNetSum_Us;
}Rtm_CpuLoad_t;

typedef struct Rtm_ThreadHandler_struct
{
    Rtm_ThreadPool_t*       Rtm_ThreadPool_p[RTM_CORE_NUMBER];//TP refers to ThreadPool
    Rtm_TaskIsrTable_t      Rtm_TaskIsrTable;//TIT refers to TaskIsrTable
    Rtm_CpuLoad_t           Rtm_CpuLoad[RTM_CORE_NUMBER];
}Rtm_ThreadHandler_t;


