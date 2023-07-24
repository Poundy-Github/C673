#include "Platform_Types.h"
#include "Time.h"
#include "Rtm_Config.h"
#include "Rtm_Types.h"
#include "IfxStm_reg.h"

/*********************************************************************************************************
 * Variable definition : 
 * 
 * The variables defined below are distributed in cores.
 * For even more cores situation, additional similar variables should be added.
 * 
*********************************************************************************************************/
/** @brief      Thread queue of core x.
       Size of queue has to be defined in Rtm_Config.h.
       Overflow of queue shall generate error flag in correspond Thread Pool
*/
RtmThread_t ThreadC0[RTM_THREAD_NUM_C0] = {{0,0,0,0,0}};
RtmThread_t ThreadC1[RTM_THREAD_NUM_C1] = {{0,0,0,0,0}};
RtmThread_t ThreadC2[RTM_THREAD_NUM_C2] = {{0,0,0,0,0}};
RtmThread_t ThreadC3[RTM_THREAD_NUM_C3] = {{0,0,0,0,0}};

/** @brief      Thread pool structure of core x.
       Head and tail of related thread queue are handled by Thread Pool
*/
Rtm_ThreadPool_t ThreadPoolC0 = {0,0,0,&ThreadC0[0]};
Rtm_ThreadPool_t ThreadPoolC1 = {0,0,0,&ThreadC1[0]};
Rtm_ThreadPool_t ThreadPoolC2 = {0,0,0,&ThreadC2[0]};
Rtm_ThreadPool_t ThreadPoolC3 = {0,0,0,&ThreadC3[0]};

/** @brief      Rtm handler,
       Which contains all information need in Run-Time Monitoring
       including thread pool, task/isr table and cpu load
*/
Rtm_ThreadHandler_t Rtm_Handler = {
    {   {&ThreadPoolC0},
        {&ThreadPoolC1},
        {&ThreadPoolC2},
        {&ThreadPoolC3},},
    {   0               },
    {   {0},{0},{0},{0} }
};

/*********************************************************************************************************
 * Notification : 
 * 
 * The hardware time counter used for each core should be the same configured 
 * from OsApplication/OsAppCounterRef in EB Tresos
 * 
*********************************************************************************************************/
uint32 Rtm_GetLocalTimeUs(uint8 CoreId)
{
    uint32 ts_us;
    static uint32 ts_prev_us[RTM_CORE_NUMBER];
    static uint16 ts_ovf_cnt[RTM_CORE_NUMBER];

    SuspendAllInterrupts();
    switch (CoreId)
    {
    case 0:
        ts_us = ((STM0_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000000ul;//use STM0 as timestamp  
        break;
    case 1:
        ts_us = ((STM1_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000000ul;//use STM1 as timestamp  
        break;
    case 2:
        ts_us = ((STM2_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000000ul;//use STM2 as timestamp  
        break;
    case 3:
        ts_us = ((STM3_TIM0.U)/(TIME_STM0_CLK_FREQ * 1.0)) * 1000000ul;//use STM3 as timestamp  
    default:
        break;
    }
    ResumeAllInterrupts();

    if(ts_us < ts_prev_us[CoreId])//STMx over flow, manually add 42 949 672 950ns `= 42 949 673us
    {
        ts_ovf_cnt[CoreId] ++;
    }
    ts_prev_us[CoreId] = ts_us;

    return (uint32)(ts_us + ts_ovf_cnt[CoreId] * 42949673ul);//trans to us
}