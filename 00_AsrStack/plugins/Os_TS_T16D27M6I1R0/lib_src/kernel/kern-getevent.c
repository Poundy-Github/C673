/* kern-getevent.c
 *
 * This file contains the OS_KernGetEvent function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-getevent.c 34824 2021-08-05 13:57:39Z ache271795 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if context checks are enabled.
 *
 * TOOLDIAG-2) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if interrupt enable checks are enabled.
 *
 * TOOLDIAG-3) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if status is EXTENDED.
*/

#define OS_SID	OS_SID_GetEvent
#define OS_SIF	OS_svc_GetEvent

/* Note: this comment is needed for asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERRORCODE_CHECK(OS_ERROR_CoreIsDown)
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernGetEvent
 *
 * The pending events for the specified task are copied to the specified
 * location, provided that the location is writable by the task.
 *
 * !LINKSTO Kernel.API.EventControl.GetEvent.API, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernGetEvent(os_taskid_t t, os_eventmask_t *ep)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_task_t *ts;
	os_result_t r = OS_E_OK;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)t);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)ep);

	OS_TRACE_GETEVENT_ENTRY(t);

	if ( !OS_CallingContextCheck() )
	{
		/* Possible diagnostic TOOLDIAG-1 <+1> */
		r = OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
	}
	else
	if ( !OS_InterruptEnableCheck(OS_IEC_AUTOSAR) )
	{
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		r = OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
	}
	else
	if ( !OS_IsValidTaskId(t) )
	{
		/* !LINKSTO Kernel.API.EventControl.GetEvent.InvalidTask, 1
		*/
		/* Possible diagnostic TOOLDIAG-3 <+1> */
		r = OS_ERROR(OS_ERROR_InvalidTaskId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		ts = &OS_taskTableBase[t];

		if ( (ts->flags & OS_TF_EXTENDED) == 0 )
		{
			/* !LINKSTO Kernel.API.EventControl.GetEvent.BasicTask, 1
			*/
			r = OS_ERROR(OS_ERROR_TaskNotExtended, OS_GET_PARAMETER_VAR());
		}
		else
		if ( OS_ArchCanWrite(ep, sizeof(*ep)) )
		{
			os_errorresult_t e;

			e = OS_DoGetEvent(t, ts, ep);
			if ( e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError) )
			{
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}
		}
		else
		{
			r = OS_ERROR(OS_ERROR_WriteProtect, OS_GET_PARAMETER_VAR());
		}
	}

	OS_TRACE_GETEVENT_EXIT_P(r,t);
	return r;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_getevent_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
