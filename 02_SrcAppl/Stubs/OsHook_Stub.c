#include "OsHook_Stub.h"
#include "Cdd_Pmc.h"
#if (!FS_EXEC_DISABLED)
#include "function_safety.h"
#endif
#include "fs_pdo.h"
#include "fs_config.h"

s_OSErrorType_t OSErrorType;

s_OSProtectionType_t OSProtectionType;



 void StartupHook(void) 
 {
	(void)0;
 }

void ShutdownHook(StatusType errorID)
{
  /*endless loop*/
  TS_PARAM_UNUSED(errorID);
  EcuM_Shutdown();
}

ProtectionReturnType ProtectionHook(StatusType errorID)
{
	os_stackinfo_t stackInfo;
	//volatile uint32 curPc;
	volatile uint32 *curStackStart;
	volatile uint32 *curStackEnd;
	volatile os_taskid_t taskId;
	volatile CoreIdType coreId;

	/* TODO */
	if(0 != OS_StackCheck())
	{
		OS_GetCurrentStackArea(&curStackStart,&curStackEnd);
		OS_UserGetStackInfo(OS_TaskToTOI(OS_NULLTASK), &stackInfo);
	}
	/*Stack size inject test case*/
	(void)OS_UserGetTaskId(&taskId);

   OSProtectionType.ErrorId = errorID;
   OSProtectionType.CoreId = GetCoreID();
   OSProtectionType.taskId = taskId;
   OSProtectionType.curStackStart = curStackStart;
   OSProtectionType.curStackEnd = curStackEnd;
   OSProtectionType.StackInfo = stackInfo;
	
   #if (!FS_EXEC_DISABLED)
        #if FS_PDO_ENABLED
        g_fs_debug_status.reset_source_fs[g_fs_debug_status.reset_source_fs_count]=FS_RS_PROTECTION_HOOK;
        g_fs_debug_status.protection_info[g_fs_debug_status.reset_source_fs_count].coreid = (uint16)OSProtectionType.CoreId;
        g_fs_debug_status.protection_info[g_fs_debug_status.reset_source_fs_count].taskid = (uint16)OSProtectionType.taskId;
        g_fs_debug_status.reset_source_fs_count = (g_fs_debug_status.reset_source_fs_count + 1)% 32;
        #endif /** FS_PDO_ENABLED */	
       FS_MCUReset(FS_RESET_SOURCE_APP);
   #else
       Cdd_Pmc_McuSoftReset();
   #endif
	
   return PRO_IGNORE;
}

void ErrorHook(StatusType error)
{
   volatile os_taskid_t taskId;

   (void)OS_UserGetTaskId(&taskId);

   OSErrorType.ErrorId = error;
   OSErrorType.CoreId = GetCoreID();
   OSErrorType.taskId = taskId;
} /* void ErrorHook(StatusType error) */
















