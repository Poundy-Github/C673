/* kern-seteventasyn.c
 *
 * This file contains the OS_KernSetEventAsyn function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-seteventasyn.c 35018 2021-08-23 09:29:21Z saga272975 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   Variable is set but never used.
 *
 * Reason: Not an issue, variable will be used if at least one application exists.
 *
 * TOOLDIAG-2) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if context checks are enabled.
 *
 * TOOLDIAG-3) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if interrupt enable checks are enabled.
 *
 * TOOLDIAG-4) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if status is EXTENDED.
*/

#define OS_SID	OS_SID_SetEventAsyn
#define OS_SIF	OS_svc_SetEventAsyn

/* Note: these comments are needed by asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERROR_ApplicationNotAccessible, OS_ERROR_TaskSuspended, 
 * OS_ERROR_RateLimitExceeded will not be returned, instead will be reported by error hook. 
 * OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible)
 * OS_ERRORCODE_CHECK(OS_ERROR_TaskSuspended)
 * OS_ERRORCODE_CHECK(OS_ERROR_RateLimitExceeded)
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernSetEventAsyn
 *
 * Sets the event for the current task asynchronously, If the task is waiting for
 * one or more of the events, it will be reawakened and queued for execution.
 *
 * !LINKSTO Kernel.API.EventControl.SetEventAsyn.API, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernSetEventAsyn(os_taskid_t t, os_eventmask_t evt)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_result_t r = OS_E_OK;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)t);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)evt);

	OS_TRACE_SETEVENTASYN_ENTRY(t,evt);

	if ( !OS_CallingContextCheck() )
	{
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		r = OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
	}
	else
	if ( !OS_InterruptEnableCheck(OS_IEC_OSEKEXTRA) )
	{
		/* Possible diagnostic TOOLDIAG-3 <+1> */
		r = OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
	}
	else
	if ( !OS_IsValidTaskId(t) )
	{
		/* !LINKSTO Kernel.API.EventControl.SetEventAsyn.InvalidTask, 1
		*/
		/* Possible diagnostic TOOLDIAG-4 <+1> */
		r = OS_ERROR(OS_ERROR_InvalidTaskId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		const os_task_t * const ts = &OS_taskTableBase[t];
		/* Possible diagnostic TOOLDIAG-1 <1> */
		const os_appcontext_t * const app = OS_CurrentApp();

		if ( !OS_HasPermission(app, ts->permissions) )
		{
			r = OS_ERROR(OS_ERROR_Permission, OS_GET_PARAMETER_VAR());
		}
		else if ( (ts->flags & OS_TF_EXTENDED) == 0 )
		{
			/* !LINKSTO Kernel.API.EventControl.SetEvent.BasicTask, 1
			*/
			r = OS_ERROR(OS_ERROR_TaskNotExtended, OS_GET_PARAMETER_VAR());
		}
		else
		{
			os_errorresult_t e;

			e = OS_DoSetEventAsyn(t, ts, evt);
			if ( e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError) )
			{
				/* !LINKSTO Kernel.Autosar.Multicore.SetEventAsyn.Errorhandling, 1
				*/
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}

		}
	}

	OS_TRACE_SETEVENTASYN_EXIT_P(r,t,evt);
	return r;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_seteventasyn_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
