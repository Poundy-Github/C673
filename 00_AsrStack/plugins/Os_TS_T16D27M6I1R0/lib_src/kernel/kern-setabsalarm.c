/* kern-setabsalarm.c
 *
 * This file contains the OS_KernSetAbsAlarm function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-setabsalarm.c 34824 2021-08-05 13:57:39Z ache271795 $
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

#define OS_SID OS_SID_SetAbsAlarm
#define OS_SIF OS_svc_SetAbsAlarm

#include <Os_kernel.h>

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernSetAbsAlarm
 *
 * The alarm is set to expire in the specified number of timer ticks.
 * The alarm's period is also set as specified.
 *
 * !LINKSTO Kernel.API.Alarms.SetAbsAlarm.API, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernSetAbsAlarm
(	os_alarmid_t a,
	os_tick_t start,
	os_tick_t cyc
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_result_t r = OS_E_OK;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0, (os_paramtype_t)a );
	OS_SAVE_PARAMETER_N(1, (os_paramtype_t)start );
	OS_SAVE_PARAMETER_N(2, (os_paramtype_t)cyc );

	OS_TRACE_SETABSALARM_ENTRY(a,start,cyc);

	if ( !OS_CallingContextCheck() )
	{
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		r = OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR() );
	}
	else
	if ( !OS_InterruptEnableCheck(OS_IEC_AUTOSAR) )
	{
		/* Possible diagnostic TOOLDIAG-3 <+1> */
		r = OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
	}
	else
	if ( ! OS_IsValidAlarmId( a ) )
	{
		/* !LINKSTO Kernel.API.Alarms.SetAbsAlarm.UnknownAlarm, 1
		*/
		/* Possible diagnostic TOOLDIAG-4 <+1> */
		r = OS_ERROR(OS_ERROR_InvalidAlarmId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		/* Possible diagnostic TOOLDIAG-1 <1> */
		const os_appcontext_t * const app = OS_CurrentApp();
		const os_alarm_t * const as = &OS_alarmTableBase[a];

		if ( !OS_HasPermission(app, as->permissions) )
		{
			r = OS_ERROR(OS_ERROR_Permission, OS_GET_PARAMETER_VAR());
		}
		else
		{
			const os_counter_t * const cs = &OS_counterTableBase[as->counter];

			if ( (start > cs->maxallowedvalue) ||
				 ( (cyc != 0u) &&
				   ( (cyc < cs->mincycle) || (cyc > cs->maxallowedvalue) ) ) )
			{
				/* !LINKSTO Kernel.API.Alarms.SetAbsAlarm.InvalidIncrement, 1
				 * !LINKSTO Kernel.API.Alarms.SetAbsAlarm.InvalidCycle, 1
				*/
				r = OS_ERROR(OS_ERROR_ParameterOutOfRange, OS_GET_PARAMETER_VAR());
			}
			else
			{
				os_errorresult_t e;

				/* !LINKSTO Kernel.API.Alarms.SetAbsAlarm.CyclicAlarm, 1
				 * !LINKSTO Kernel.API.Alarms.SetAbsAlarm.SingleAlarm, 1
				 * !LINKSTO Kernel.API.Alarms.SetAbsAlarm.Start, 1
				*/
				e = OS_DoSetAlarm(a, as, cs, start, cyc, OS_FALSE);
				if (e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError))
				{
					/* These errors can occur here:
					 * Note: this comment is needed for asc_Os/tools/errdb-to-c.pl
					 *
					 * OS_ERRORCODE_CHECK(OS_ERROR_CoreIsDown)
					 * OS_ERRORCODE_CHECK(OS_ERROR_Quarantined);
					 * OS_ERRORCODE_CHECK(OS_ERROR_AlarmInUse);
					 * OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible);
					*/
					r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
				}
			}
		}
	}

	OS_TRACE_SETABSALARM_EXIT_P(r,a,start,cyc);
	return r;
}


#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
