/* kern-recvsetabsalarm.c
 *
 * This file contains the function OS_RecvSetAbsAlarm().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-recvsetabsalarm.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>
#include <Os_panic.h>

/*!
 * OS_RecvSetAbsAlarm()
 *
 * Handles cross-core SetAbsAlarm() calls.
 */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_RecvSetAbsAlarm(os_message_t * msg)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_alarmid_t const a = (os_alarmid_t)msg->parameter[0];
	/* COVPT-1 */
	if (OS_IsValidAlarmId(a) && (msg->result != OS_NULL))
	{
		os_paramtype_t replyParams[OS_MAXPARAM];
		os_tick_t const start 			= (os_tick_t)msg->parameter[1];
		os_tick_t const cyc 			= (os_tick_t)msg->parameter[2];
		os_alarm_t const * const as 	= &OS_alarmTableBase[a];
		os_counter_t const * const cs 	= &OS_counterTableBase[as->counter];

		replyParams[0] = (os_paramtype_t)OS_LocalSetAlarm(a, as, cs, start, cyc, OS_FALSE);

#if OS_XC_REPLY_DIRECTLY
		OS_WriteMessageResult(msg, replyParams[0]);
#else
		OS_SendMessage(msg->from, OS_XC_OP_ReturnResult, msg->result, replyParams);
#endif
	}
	else
	{
		(void)OS_PANIC(OS_PANIC_CrosscoreCommunicationError);
	}
}

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_recvsetabsalarm_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
