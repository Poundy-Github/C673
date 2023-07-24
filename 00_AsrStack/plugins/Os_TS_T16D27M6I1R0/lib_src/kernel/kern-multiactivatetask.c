/* kern-multiactivatetask.c
 *
 * This file contains the OS_MultiActivateTask function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multiactivatetask.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiActivateTask activates a task in a multi-core system.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiActivateTask(const os_task_t *tp)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e;

	if (OS_GetTaskCoreId(tp) == OS_GetMyCoreId())
	{
		e = OS_LocalActivateTask(tp);
	}
	else
	{
		/* !LINKSTO Kernel.Autosar.Multicore.ActivateTask.CrossCore, 1
		 * !LINKSTO Kernel.Autosar.Multicore.ChainTask.CrossCore, 1
		*/
		e = OS_SendActivateTask(tp);
	}

	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multiactivatetask_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
