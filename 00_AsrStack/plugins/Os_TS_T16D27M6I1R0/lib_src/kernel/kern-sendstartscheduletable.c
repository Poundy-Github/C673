/* kern-sendstartscheduletable.c
 *
 * This file contains the OS_SendStartScheduleTable() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-sendstartscheduletable.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_SendStartScheduleTable
 *
 * Sends the request to start schedule table 's' to the core on which that table resides.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_SendStartScheduleTable
(	os_scheduleid_t s,
	const os_schedule_t *ss,
	os_tick_t offset,
	os_boolean_t rel
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_paramtype_t msgParam[OS_MAXPARAM];

	msgParam[0] = (os_paramtype_t)s;
	msgParam[1] = (os_paramtype_t)offset;
	msgParam[2] = (os_paramtype_t)rel;

	return OS_SendMessageWait(OS_GetScheduleTableCoreId(ss), OS_XC_OP_StartScheduleTable, msgParam);
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_sendstartscheduletable_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
