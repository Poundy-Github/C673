/* kern-inittasks.c
 *
 * This file contains the OS_InitTasks() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-inittasks.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Condition is always true.
 *
 * Reason: This warning depends on the number of configured cores.
 *   Only in case of a single core configuration, this comparison can be evaluated at compile time.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_InitTasks
 *
 * The head of each task's last resource queue needs to be set to NULLRESOURCE.
 * This is because the default bss value (0) is a valid resource id.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_InitTasks(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_coreid_t const myCoreId = OS_GetMyCoreId();
	os_taskid_t tid;

	for (tid = 0; tid < OS_nTasks; tid++)
	{
		os_task_t const * const tp = &OS_taskTableBase[tid];
		/* COVPT-1 +2 */
		/* Possible diagnostic TOOLDIAG-1 <1> */
		if (OS_GetTaskCoreId(tp) == myCoreId)
		{
			tp->dynamic->lastLock = OS_NULLOBJECT;
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_inittasks_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
