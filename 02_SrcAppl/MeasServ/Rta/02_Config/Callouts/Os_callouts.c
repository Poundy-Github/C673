#include "Os_config.h"
#include "rta_os.h"
#include "Platform_Types.h"
#include "Rtm.h"

// static TaskType PreviousTaskiD;
#if (RTM_FUNCTION_ENABLE == STD_ON) //Use RTM

#else
static TaskType CurrentTaskId[4];
#endif
void PreTaskHook(void)
{
#if (RTM_FUNCTION_ENABLE == STD_ON) //Use RTM

#else   //Use RTA
    (void)GetTaskID(&CurrentTaskId[(uint32)GetCoreID()]);
    RTA_v_PreTaskHook((uint32)CurrentTaskId[(uint32)GetCoreID()]);
#endif

}

void PreIsrHook(os_isrid_t Isr_Id) 
{
#if (RTM_FUNCTION_ENABLE == STD_ON) //Use RTM
#   if(RTM_FUNC_ISR_MONIOTR == STD_ON)
    uint8 coreid;
    coreid = GetCoreID();
    Rtm_StartThread(coreid, RTM_ISR, (uint16)Isr_Id);
#   endif
#else   //Use RTA
    RTA_v_PreIsrHook((uint32)Isr_Id);
#endif
}

void PostIsrHook(os_isrid_t arg)
{
#if (RTM_FUNCTION_ENABLE == STD_ON) //Use RTM
#   if(RTM_FUNC_ISR_MONIOTR == STD_ON)
    uint8 coreid;
    coreid = GetCoreID();
    Rtm_EndThread(coreid, RTM_ISR, (uint16)arg);
#   endif
#else   //Use RTA
    RTA_v_PreTaskHook((uint32)CurrentTaskId[(uint32)GetCoreID()]);   
#endif

}

void PostTaskHook(void)
{

}