/* kern-getelapsedcountervalue.c
 *
 * This file contains the OS_KernGetElapsedCounterValue function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-getelapsedcountervalue.c 34824 2021-08-05 13:57:39Z ache271795 $
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

#define OS_SID	OS_SID_GetElapsedCounterValue
#define OS_SIF	OS_svc_GetElapsedCounterValue

/* Note: this comment is needed for asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERRORCODE_CHECK(OS_ERROR_CoreIsDown)
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#if (OS_N_CORES > 1)
#include <Os_messagequeue.h>
#endif

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernGetElapsedCounterValue
 *
 * The total number of ticks of the counter that have elapsed since 'last'
 * is written to the indicated location.
 *
 * !LINKSTO Kernel.Autosar.API.SystemServices.GetElapsedCounterValue, 2
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernGetElapsedCounterValue(os_counterid_t c, os_tick_t *last, os_tick_t *out)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e = OS_ERRORCODE_NOCHECK(OS_ERROR_NoError);
	os_result_t r = OS_E_OK;
	const os_counter_t *cs;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)c);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)last);
	OS_SAVE_PARAMETER_N(2,(os_paramtype_t)out);

	OS_TRACE_GETELAPSEDCOUNTERVALUE_ENTRY(c);

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
	/* COVPT-1 +2 */
	else
	if ( OS_ArchCanWrite(last, sizeof(*last)) == 0 )
	{
		r = OS_ERROR(OS_ERROR_WriteProtect, OS_GET_PARAMETER_VAR());
	}
	/* COVPT-2 +2 */
	else
	if ( OS_ArchCanWrite(out, sizeof(*out)) == 0 )
	{
		r = OS_ERROR(OS_ERROR_WriteProtect, OS_GET_PARAMETER_VAR());
	}
	else
	if ( !OS_IsValidCounterId( c ) )
	{
		/* !LINKSTO Kernel.Autosar.API.SystemServices.GetElapsedCounterValue.Invalid, 1
		*/
		/* Possible diagnostic TOOLDIAG-3 <+1> */
		r = OS_ERROR(OS_ERROR_InvalidCounterId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		cs = &OS_counterTableBase[c];

		if ( *last > cs->maxallowedvalue )
		{
			/* !LINKSTO Kernel.Autosar.API.SystemServices.GetElapsedCounterValue.OutOfRange, 2
			*/
			r = OS_ERROR(OS_ERROR_ParameterOutOfRange, OS_GET_PARAMETER_VAR());
		}
		else
		{
			os_tick_t count = 0;

#if (OS_N_CORES == 1)
			if ( !OS_APPISACCESSIBLE(cs->app) )
			{
				e = OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible);
			}
			else
			{
				count = OS_GetCount(cs);
			}
#else
			/* COVPT-3 */
			if ( OS_GetCounterCoreId(cs) == OS_GetMyCoreId() )
			{
				/* COVPT-4 */
				if ( !OS_APPISACCESSIBLE(cs->app) )
				{
					e = OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible);
				}
				else
				{
					count = OS_GetCount(cs);
				}
			}
			else
			{
				e = OS_SendGetCount(c, cs, &count);
			}
#endif
			if ( e == OS_ERRORCODE_NOCHECK(OS_ERROR_NoError) )
			{
				*out = OS_CounterSub(count, *last, cs->maxallowedvalue);
				*last = count;
			}
			else
			{
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}
		}
	}

	OS_TRACE_GETELAPSEDCOUNTERVALUE_EXIT_P(r,c);
	return r;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_getelapsedcountervalue_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
