/* kern-recvgetcount.c
 *
 * This file contains the function OS_RecvGetCount().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-recvgetcount.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#define OS_SID OS_SID_GetCounterValue
#define OS_SIF OS_svc_GetCounterValue

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>
#include <Os_panic.h>

/*!
 * OS_RecvGetCount
 *
 * Handles cross-core GetCount() calls.
 */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_RecvGetCount(os_message_t * msg)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_counterid_t const c = (os_counterid_t)msg->parameter[0];

	/* COVPT-1 */
	if (OS_IsValidCounterId(c) && (msg->result != OS_NULL))
	{
		os_paramtype_t replyParams[OS_MAXPARAM];
		os_counter_t const * const cs = &OS_counterTableBase[c];
		os_tick_t ticks;

		ticks = OS_GetCount(cs);
		replyParams[0] = (os_paramtype_t)OS_ERRORCODE_NOCHECK(OS_ERROR_NoError);

		replyParams[1] = msg->parameter[1];		/* points to where 'ticks' shall be stored to */
		replyParams[2] = ticks;

#if OS_XC_REPLY_DIRECTLY
		msg->parameter[0] = replyParams[0];
		msg->parameter[1] = replyParams[1];
		msg->parameter[2] = replyParams[2];
		OS_RetnTick(msg);
#else
		OS_SendMessage(msg->from, OS_XC_OP_ReturnTick, msg->result, replyParams);
#endif
	}
	else
	{
		(void)OS_PANIC(OS_PANIC_CrosscoreCommunicationError);
	}
}

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_recvgetcount_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
