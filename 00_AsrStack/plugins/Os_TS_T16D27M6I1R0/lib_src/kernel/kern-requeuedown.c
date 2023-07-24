/* kern-requeuedown.c
 *
 * This file contains the OS_RequeueDown function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-requeuedown.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 13.5 (required)
 * The right hand operand of a logical && or || operator shall not contain side effects.
 *
 * Reason:
 * False positive: OS_FindPrio() does not have side effects but only reads information.
 */

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_RequeueDown
 *
 * The specified task activation is moved from its position in the task queue to somewhere
 * further down the queue because it has decreased its priority.
 *
 * OS_RequeueDown() must be called with interrupts locked
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_RequeueDown(os_tasklink_t tAct, os_prio_t prio)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_tasklink_t * const taskActivations = OS_GetTaskActivations();
	os_tasklink_t qAct = taskActivations[0];
	os_tasklink_t qOld = 0;		/* Old predecessor in queue */

	while ( (qAct != tAct) && (qAct != 0) )
	{
		qOld = qAct;
		qAct = taskActivations[qAct];
	}

	if ( qAct == tAct )
	{
		os_tasklink_t qSkip = taskActivations[tAct];	/* Old successor in queue */
		os_tasklink_t qNew = qOld;							/* New predecessor in queue */
		qAct = qSkip;

		/* Deviation MISRAC2012-1 <1> */
		while ( (qAct != 0) && (OS_FindPrio(qAct) > prio) )
		{
			qNew = qAct;
			qAct = taskActivations[qAct];
		}

		/* Now we remove the activation from its former position
		 * (after qOld) and insert it after qNew.
		*/
		if ( qOld == qNew )
		{
			/* No change */
		}
		else
		{
			/* Remove from old place in queue
			*/
			taskActivations[qOld] = qSkip;
			OS_GetKernelData()->taskQueueHead = OS_GetTaskPtrs(taskActivations[0]);

			/* Insert at new place in queue
			*/
			taskActivations[qNew] = tAct;
			taskActivations[tAct] = qAct;
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_requeuedown_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
