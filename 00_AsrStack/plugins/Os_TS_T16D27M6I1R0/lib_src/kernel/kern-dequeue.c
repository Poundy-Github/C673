/* kern-dequeue.c
 *
 * This file contains the OS_Dequeue function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-dequeue.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_Dequeue
 *
 * The specified task activation is removed from the task queue. The task
 * can be anywhere in the queue.
 *
 * OS_Dequeue() must be called with interrupts locked
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_Dequeue(os_tasklink_t tAct)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_tasklink_t * const taskActivations = OS_GetTaskActivations();
	os_tasklink_t qAct = taskActivations[0];

	if ( tAct == qAct )
	{
		/* Task is at head of queue
		*/
		taskActivations[0] = taskActivations[tAct];
		OS_GetKernelData()->taskQueueHead = OS_GetTaskPtrs(taskActivations[0]);
		taskActivations[tAct] = 0;
	}
	else
	{
		/* Task is not at head. Might be somewhere further along.
		 * This can happen if a higher priority task gets activated by an
		 * interrupt while we're in the kernel TerminateTask routine with
		 * interrupts enabled. It also covers the case for killing a task
		 * that is READY. (Autosar, protection violation etc.)
		*/
		/* COVPT-1 */
		while ( (taskActivations[qAct] != tAct) && (qAct != 0) )
		{
			qAct = taskActivations[qAct];
		}

		/* COVPT-2 */
		if ( qAct == 0 )
		{
			/* Task is not in the queue - nothing to do */
		}
		else
		{
			taskActivations[qAct] = taskActivations[tAct];
			taskActivations[tAct] = 0;
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_dequeue_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
