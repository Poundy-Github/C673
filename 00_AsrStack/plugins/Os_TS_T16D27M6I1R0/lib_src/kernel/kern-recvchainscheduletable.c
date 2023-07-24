/* kern-recvchainscheduletable.c
 *
 * This file contains the function OS_RecvChainScheduleTable().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-recvchainscheduletable.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>
#include <Os_panic.h>

/*!
 * OS_RecvChainScheduleTable
 *
 * Handles cross-core ChainScheduleTable() calls.
 */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_RecvChainScheduleTable(os_message_t *msg)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_scheduleid_t const sc = (os_scheduleid_t)msg->parameter[0];
	os_scheduleid_t const sn = (os_scheduleid_t)msg->parameter[1];

	/* COVPT-1 */
	if (OS_IsValidScheduleId(sc) && OS_IsValidScheduleId(sn) && (msg->result != OS_NULL))
	{
		os_paramtype_t replyParams[OS_MAXPARAM];

		replyParams[0] = (os_paramtype_t)OS_LocalChainScheduleTable(sc, sn);

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
const os_uint8_t OS_dummy_kern_recvchainscheduletable_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
