/* kern-multisyncscheduletable.c
 *
 * This file contains the OS_MultiSyncScheduleTable function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multisyncscheduletable.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiSyncScheduleTable is used to implement SyncScheduleTable on multi-core systems.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiSyncScheduleTable(os_scheduleid_t s, const os_schedule_t *ps, os_tick_t globalTime)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e;

	if ( OS_GetScheduleTableCoreId(ps) == OS_GetMyCoreId() )
	{
		e = OS_LocalSyncScheduleTable(ps, globalTime);
	}
	else
	{
		e = OS_SendSyncScheduleTable(s, ps, globalTime);
	}

	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multisyncscheduletable_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
