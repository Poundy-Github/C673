/* kern-localsetevent.c
 *
 * This file contains the OS_LocalSetEvent() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-localsetevent.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 13.5 (required)
 * The right hand operand of a logical && or || operator shall not contain
 * persistent side effects.
 *
 * Reason:
 * The rate monitoring function has to modify the gobal system state.
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   This statement can be reached if rate monitoring is used.
*/

#define OS_SID	OS_SID_SetEvent
#define OS_SIF	OS_svc_SetEvent

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_LocalSetEvent
 *
 * If the specified task is not suspended (or quarantined. whihc is equivalent) the specifed events are
 * set for the task. If the task is waiting for any of the pending events and has not reached its
 * arrival rate limit it is placed in the ready state and enqueued.
 *
 * !LINKSTO Kernel.API.EventControl.SetEvent.API, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_LocalSetEvent(const os_task_t *ts, os_eventmask_t e)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t result = OS_ERRORCODE_NOCHECK(OS_ERROR_NoError);
	os_taskdynamic_t *td = ts->dynamic;
	os_intstatus_t is;

	is = OS_IntDisable();

	if ( !OS_APPISACCESSIBLE(ts->app) )
	{
		result = OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible);
	}
	else
	if ( (td->state == OS_TS_SUSPENDED) || (td->state == OS_TS_QUARANTINED) )
	{
		/* !LINKSTO Kernel.API.EventControl.SetEvent.InvalidState, 1
		*/
		result = OS_ERRORCODE_CHECK(OS_ERROR_TaskSuspended);
	}
	else
	{
		td->pEvents |= e;

		if ( (td->state == OS_TS_WAITING) && ((td->pEvents & td->wEvents) != 0) )
		{
			/* Check rate monitor before making the task ready
			 *
			 * !LINKSTO Kernel.Autosar.Protection.TimingProtection.RateLimit.Tasks, 2
			*/
			/* Deviation MISRAC2012-1 */
			if ( OS_RATEMONITORCHECK(ts->rateMonitor) )
			{
				/* Possible diagnostic TOOLDIAG-1 <+1> */
				result = OS_ERRORCODE_CHECK(OS_ERROR_RateLimitExceeded);
			}
			else
			{
				/* Task is waiting for one or more of the pending
				 * events, so we make it ready to run.
				 * Extended tasks can't have multiple activations,
				 * so we always use the first link slot.
				 *
				 * !LINKSTO Kernel.API.EventControl.SetEvent.StateChange, 1
				 * !LINKSTO Kernel.TaskManagement.Scheduling.WaitToReady, 1
				 * !LINKSTO Kernel.TaskManagement.Scheduling, 1
				 * !LINKSTO Kernel.TaskManagement, 1
				*/
				OS_TRACE_STATE_TASK( ts->taskId, td->state, OS_TS_READY_SYNC );
				td->state = OS_TS_READY_SYNC;
				td->prio = ts->queuePrio;

				/* Reset the task's execution time measurement
				 *
				 * !LINKSTO Kernel.Autosar.Protection.TimingProtection.ExecutionTime.Measurement.Task, 1
				*/
				OS_InitTaskEtb(ts);

				OS_Enqueue(ts);

			}
		}
		else
		{
			/* Task is not waiting for any of the events,
			 * so no change
			*/
		}
	}

	OS_IntRestore(is);

	return result;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_localsetevent_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
