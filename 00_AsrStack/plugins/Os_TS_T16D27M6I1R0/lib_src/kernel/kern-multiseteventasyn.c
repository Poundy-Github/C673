/* kern-multiseteventasyn.c
 *
 * This file contains the OS_MultiSetEventAsyn function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multiseteventasyn.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiSetEventAsyn is used to implement SetEventAsyn on multi-core systems.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiSetEventAsyn(os_taskid_t t, const os_task_t *ts, os_eventmask_t evt)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e;

	if (OS_GetTaskCoreId(ts) == OS_GetMyCoreId())
	{
		e = OS_LocalSetEvent(ts, evt);
	}
	else
	{
		/* !LINKSTO Kernel.Autosar.Multicore.SetEventAsyn.CrossCore, 1
		*/
		e = OS_SendSetEventAsyn(t, ts, evt);
	}

	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multiseteventasyn_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
