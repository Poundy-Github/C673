#include "Platform_Types.h"
#include "Time.h"
/****************************
 * Function enable switch
****************************/
#define RTM_FUNCTION_ENABLE     STD_ON
#define RTM_FUNC_TASK_MONITOR   STD_ON
#define RTM_FUNC_ISR_MONIOTR    STD_OFF

#define RTM_SEND_LOGGING_ENABLE STD_ON
#define RTM_SEND_LOGGING_INFO_THRESHOLD 50u
#define RTM_SEND_LOGGING_WARN_THRESHOLD 85u
/****************************
 * RTM parameter configuration
****************************/
#define RTM_THREAD_NUM_C0 100u
#define RTM_THREAD_NUM_C1 10u
#define RTM_THREAD_NUM_C2 10u
#define RTM_THREAD_NUM_C3 15u

/****************************
 * OS related configuration
****************************/
#define RTM_CORE_NUMBER 4
#define RTM_ISR_NUMBER  OS_NINTERRUPTS
#define RTM_TASK_NUMBER OS_NTASKS
#define RTM_LOWEST_PRIO_TASK_ID_CORE0 Core0_OsTask_Appl_60ms
#define RTM_LOWEST_PRIO_TASK_ID_CORE1 Core1_OsTask_Appl_60ms
#define RTM_LOWEST_PRIO_TASK_ID_CORE2 Core2_OsTask_Bsw_20ms
#define RTM_LOWEST_PRIO_TASK_ID_CORE3 Core3_OsTask_Appl_50ms

#define CASE_RTM_LOWEST_PRIO_TASK   \
case RTM_LOWEST_PRIO_TASK_ID_CORE0: \
case RTM_LOWEST_PRIO_TASK_ID_CORE1: \
case RTM_LOWEST_PRIO_TASK_ID_CORE2: \
case RTM_LOWEST_PRIO_TASK_ID_CORE3:

#define RTM_THREADS_NUMBER_CFG \
case 0: \
    thread_numb = RTM_THREAD_NUM_C0;    \
    break;  \
case 1: \
    thread_numb = RTM_THREAD_NUM_C1;    \
    break;  \
case 2: \
    thread_numb = RTM_THREAD_NUM_C2;    \
    break;  \
case 3: \
    thread_numb = RTM_THREAD_NUM_C3;    \
    break;  \

/****************************
 * External used function
****************************/
extern uint32 Rtm_GetLocalTimeUs(uint8 CoreId);

#if(RTM_SEND_LOGGING_ENABLE == STD_ON)
#define LOGGING_SEND    Logging_SendData
#endif

