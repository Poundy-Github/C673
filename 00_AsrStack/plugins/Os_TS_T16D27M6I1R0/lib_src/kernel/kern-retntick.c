/* kern-retntick.c
 *
 * This file contains the function OS_RetnTick().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-retntick.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_RetnTick()
 *
 * This function is run by the core to complete the call of GetAlarm() or GetCounterValue(). It returns the
 * reply and the result code to the original caller of GetAlarm() or GetCounterValue(), after another core
 * retrieved it.
 */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_RetnTick(os_message_t * msg)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e;
	os_tick_t *tickp;

	/* If the error code in msg->parameter[0] indicates success, store the tick value in
	 * msg->parameter[2] into the memory location pointed to by msg->parameter[1].
	 */
	e = (os_errorresult_t)msg->parameter[0];
	if (e == OS_ERROR_NoError)
	{
		tickp = (os_tick_t *)msg->parameter[1];
		*tickp = (os_tick_t)msg->parameter[2];

#if OS_XC_REPLY_DIRECTLY
		OS_CacheFlush(tickp, sizeof(*tickp));
#endif
	}

	*(msg->result) = (os_paramtype_t)e;

#if OS_XC_REPLY_DIRECTLY
	OS_CacheFlush(msg->result, sizeof(os_paramtype_t));
#endif
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_retntick_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
