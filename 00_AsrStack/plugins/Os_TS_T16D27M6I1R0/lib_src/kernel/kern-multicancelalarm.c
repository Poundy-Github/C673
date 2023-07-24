/* kern-multicancelalarm.c
 *
 * This file contains the OS_MultiCancelAlarm function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multicancelalarm.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiCancelAlarm cancels an alarm in a multi-core system.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiCancelAlarm(os_alarmid_t a, const os_alarm_t *as)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e;

	if (OS_GetAlarmCoreId(as) == OS_GetMyCoreId())
	{
		e = OS_LocalCancelAlarm(a, as);
	}
	else
	{
		/* !LINKSTO Kernel.Autosar.Multicore.CancelAlarm.CrossCore, 1
		*/
		e = OS_SendCancelAlarm(a, as);
	}

	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multicancelalarm_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
