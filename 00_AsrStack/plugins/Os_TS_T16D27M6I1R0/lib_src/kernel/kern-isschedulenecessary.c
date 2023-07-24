/* kern-isschedulenecessary.c
 *
 * This file contains the OS_IsScheduleNecessary function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-isschedulenecessary.c 34824 2021-08-05 13:57:39Z ache271795 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   Variable is set but never used.
 *
 * Reason: Not an issue, variable will be used if multiple task activations are enabled.
 */
#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_api.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_IsScheduleNecessary implements the API Schedule
 *
 * Returns TRUE is there is no current task or there is a task of higher priority enqueued behind the current task.
 * Otherwise returns FALSE.
 *
 * !LINKSTO Kernel.Feature.FastSchedule, 1
 * !LINKSTO Kernel.Feature.FastSchedule.ErrorChecking, 1
 * !LINKSTO Kernel.Feature.FastSchedule.IsScheduleNecessary, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_boolean_t OS_IsScheduleNecessary(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_boolean_t answer = OS_TRUE;

	os_tasklink_t * const taskActivations = OS_GetTaskActivations();
	os_task_t const * const current_task = OS_GetKernelData()->taskCurrent;
	
	if ( current_task != OS_NULL )
	{
		/* Possible diagnostic TOOLDIAG-1 <1> */
		os_taskdynamic_t * const td = current_task->dynamic;
		const os_tasklink_t link = OS_CurrentLink(current_task, td);
		const os_tasklink_t next = taskActivations[link];

		answer = ( (next != 0) && (current_task->queuePrio < OS_FindPrio(next)) );
	} /* else not needed */

	return answer;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_isschedulenecessary_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
