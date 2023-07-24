#include "..\..\..\..\output\generated\include\Os_config.h"
#include "rta_os.h"
#include "Platform_Types.h"


// static TaskType PreviousTaskiD;
static TaskType CurrentTaskId[4];
void PreTaskHook(void)
{
    (void)GetTaskID(&CurrentTaskId[(uint32)GetCoreID()]);
    RTA_v_PreTaskHook((uint32)CurrentTaskId[(uint32)GetCoreID()]);

}

void PreIsrHook(os_isrid_t Isr_Id) 
{
    RTA_v_PreIsrHook((uint32)Isr_Id);
}

void PostIsrHook(os_isrid_t arg)
{
    RTA_v_PreTaskHook((uint32)CurrentTaskId[(uint32)GetCoreID()]);

}

void PostTaskHook(void)
{
    
}