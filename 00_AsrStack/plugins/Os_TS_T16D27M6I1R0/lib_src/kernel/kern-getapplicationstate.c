/* kern-getapplicationstate.c
 *
 * This file contains the OS_KernGetApplicationState() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-getapplicationstate.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 14.3 (required)
 * Controlling expression shall not be invariant.
 *
 * Reason:
 * It depends on the configuration and architecture, whether or not the
 * OS_ArchCanWrite() macro is invariant.
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

#define OS_SID	OS_SID_GetApplicationState
#define OS_SIF	OS_svc_GetApplicationState

/* Note: this comment is relevant for asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERRORCODE_CHECK(OS_ERROR_CoreIsDown)
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#if (OS_N_CORES > 1)
#include <Os_messagequeue.h>
#endif
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernGetApplicationState implements the API GetApplicationState
 *
 * The state of the specified application is returned.
 *
 * It is not permitted to write to addresses specified by the
 * caller while in kernel mode without first checking that
 * the caller has permission to write there.
 *
 * Interrupts are enabled on entry and remain so throughout. The
 * state returned is therefore a snapshot of the application's state,
 * and could have changed by the time the caller actually gets it.
 * However, this could happen anyway.
 *
 * !LINKSTO Kernel.Autosar.API.SystemServices.GetApplicationState, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernGetApplicationState
(	os_applicationid_t a,
	os_appstate_t *out
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_appcontext_t *ap;
	os_appdynamic_t *ad;
	os_result_t r = OS_E_OK;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)a);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)out);

	OS_TRACE_GETAPPLICATIONSTATE_ENTRY(a, out);

	if ( !OS_CallingContextCheck() )
	{
		/* !LINKSTO Kernel.Autosar.ServiceErrors.Context.PermittedContext.GetApplicationState, 1
		*/
		/* Possible diagnostic TOOLDIAG-1 <+1> */
		r = OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
	}
	else if ( !OS_InterruptEnableCheck(OS_IEC_AUTOSAR) )
	{
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		r = OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
	}
	/* COVPT-0 +2 */
	/* Deviation MISRAC2012-1 */
	else if ( OS_ArchCanWrite(out, sizeof(*out)) == 0 )
	{
		r = OS_ERROR(OS_ERROR_WriteProtect, OS_GET_PARAMETER_VAR());
	}
	else if ( !OS_IsValidApplicationId(a) )
	{
		/* !LINKSTO Kernel.Autosar.API.SystemServices.GetApplicationState.InvalidAppId, 1
		*/
		/* Possible diagnostic TOOLDIAG-3 <+1> */
		r = OS_ERROR(OS_ERROR_InvalidApplicationId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		ap = &OS_appTableBase[a];
		ad = ap->dynamic;

#if (OS_N_CORES == 1)
		*out = ad->appstate;
#else
		/* COVPT-1 */
		if ( OS_GetAppCoreId(ap) == OS_GetMyCoreId() )
		{
			*out = ad->appstate;
		}
		else
		{
			os_errorresult_t e;
			e = OS_SendGetApplicationState(a, ap, out);

			/* COVPT-2 */
			if ( e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError) )
			{
				/* Possibly unreachable
				*/
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}
		}
#endif
	}

	OS_TRACE_GETAPPLICATIONSTATE_EXIT_P(r,a,out);
	return r;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_getapplicationstate_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
