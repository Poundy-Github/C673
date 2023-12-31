/* kern-activatetaskasyn.c
 *
 * This file contains the OS_KernActivateTaskAsyn function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-activatetaskasyn.c 35018 2021-08-23 09:29:21Z saga272975 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   Variable is set but never used.
 *
 * Reason: Not an issue, variable will be used if at least one application exists.
 *
 * TOOLDIAG-2) Possible diagnostic: StatementIsUnreachable
 *   statement not reached
 *
 * Reason:
 *  This warning depends on the OS configuration and library optimization.
 *  The statement can be reached, if "calling context checks" are not excluded.
 *
 * TOOLDIAG-3) Possible diagnostic: StatementIsUnreachable
 *   statement not reached
 *
 * Reason:
 *  This warning depends on the OS configuration and library optimization.
 *  The statement can be reached, if "interrupt enable checks" are not excluded.
 *
 * TOOLDIAG-4) Possible diagnostic: StatementIsUnreachable
 *   statement not reached
 *
 * Reason:
 *  This warning depends on the OS configuration and library optimization.
 *  The statement can be reached, if EXTENDED status is used.
*/

#define OS_SID OS_SID_ActivateTaskAsyn
#define OS_SIF OS_svc_ActivateTaskAsyn

/* Note: these comments are needed by asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERROR_ApplicationNotAccessible, OS_ERROR_MaxActivations, OS_ERROR_Quarantined, 
 * OS_ERROR_RateLimitExceeded will not be returned, instead will be reported by error hook. 
 * OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible)
 * OS_ERRORCODE_CHECK(OS_ERROR_MaxActivations)
 * OS_ERRORCODE_CHECK(OS_ERROR_Quarantined)
 * OS_ERRORCODE_CHECK(OS_ERROR_RateLimitExceeded)
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernActivateTaskAsyn implements the API ActivateTaskAsyn
 *
 * The specified task is activated. If it is already active, the
 * pending activation counter is incremented (up to the maximum).
 * Otherwise the task state is set to NEW and it is enqueued.
 *
 * !LINKSTO Kernel.API.TaskManagement.ActivateTaskAsyn.API, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernActivateTaskAsyn(os_taskid_t t)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_result_t r = OS_E_OK;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)t);

	OS_TRACE_ACTIVATETASKASYN_ENTRY(t);

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
		/* !LINKSTO Kernel.API.TaskManagement.ActivateTaskAsyn.InvalidTask, 1
		*/
		/* Possible diagnostic TOOLDIAG-4 <+1> */
		r = OS_ERROR(OS_ERROR_InvalidTaskId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		const os_task_t * const tp = &OS_taskTableBase[t];
		/* Possible diagnostic TOOLDIAG-1 <1> */
		const os_appcontext_t * const app = OS_CurrentApp();
		if ( !OS_HasPermission(app, tp->permissions) )
		{
			r = OS_ERROR(OS_ERROR_Permission, OS_GET_PARAMETER_VAR());
		}
		else
		{
			os_errorresult_t e;

			e = OS_DoActivateTaskAsyn(tp);
			if ( e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError) )
			{
				/* !LINKSTO Kernel.Autosar.Multicore.ActivateTaskAsyn.Errorhandling, 1
 				*/ 
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}

		}

	}

	OS_TRACE_ACTIVATETASKASYN_EXIT_P(r,t);
	return r;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_activatetaskasyn_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
