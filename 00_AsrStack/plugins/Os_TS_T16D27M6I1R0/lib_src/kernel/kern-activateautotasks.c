/* kern-activateautotasks.c
 *
 * This file contains the OS_ActivateAutoTasks function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-activateautotasks.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Comparison with constant compile-time result
 *
 * Reason: In single-core configurations, the result is compile-time constant.
 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 14.3 (required)
 * Controlling expressions shall not be invariant.
 *
 * Reason:
 * The invariance depends on the configuration and may be constant.
*/

#include <Os_kernel.h>

#include <memmap/Os_mm_code_begin.h>

/* OS_ActivateAutoTasks()
 *
 * Activate all tasks that are specified for the requested mode
 *
 * !LINKSTO Kernel.Autosar.Autostart, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_ActivateAutoTasks(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint16_t idx;
	os_coreid_t const myCoreId = OS_GetMyCoreId();

	idx = OS_startModeTasks[OS_GetAppMode()];

	while ( OS_autoStartTasks[idx] < OS_GetNTasks() )
	{
		os_taskid_t tid = OS_autoStartTasks[idx];

		/* COVPT-1 +3 */
		/* Possible diagnostic TOOLDIAG-1 */
		/* Deviation MISRAC2012-1 */
		if (OS_GetCoreIdFromTaskId(tid) == myCoreId)
		{
			/* no way to propagate errors -> ignore return value */
			(void) OS_InternalActivateTask(tid);
		}
		idx++;
	}
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
