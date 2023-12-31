/* kern-sendsetabsalarm.c
 *
 * This file contains the OS_SendSetAbsAlarm() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-sendsetabsalarm.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_SendSetAbsAlarm()
 *
 * Sends a SetAbsAlarm() call to the core on which the alarm 'a' resides.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_SendSetAbsAlarm(os_alarmid_t a, const os_alarm_t *as, os_tick_t start, os_tick_t cyc)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_paramtype_t msgParam[OS_MAXPARAM];

	msgParam[0] = (os_paramtype_t)a;
	msgParam[1] = (os_paramtype_t)start;
	msgParam[2] = (os_paramtype_t)cyc;

	return OS_SendMessageWait(OS_GetAlarmCoreId(as), OS_XC_OP_SetAbsAlarm, msgParam);
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_sendsetabsalarm_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
