/* kern-chainscheduletable.c
 *
 * This file contains the OS_KernChainScheduleTable function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-chainscheduletable.c 34824 2021-08-05 13:57:39Z ache271795 $
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
 *   This statement can be reached if context checks are enabled.
 *
 * TOOLDIAG-3) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   This statement can be reached if interrupt enable checks are enabled.
*/

#define OS_SID OS_SID_ChainScheduleTable
#define OS_SIF OS_svc_ChainScheduleTable

/* Note: this comment is needed for asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERRORCODE_CHECK(OS_ERROR_CoreIsDown)
 * OS_ERRORCODE_CHECK(OS_ERROR_ApplicationNotAccessible)
 * OS_ERRORCODE_CHECK(OS_ERROR_NotRunning)
 * OS_ERRORCODE_CHECK(OS_ERROR_NotStopped)
*/

#include <Os_kernel.h>


/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernChainScheduleTable implements the API ChainScheduleTable
 *
 * The specified "next" schedule table is chained to be started when the
 * specified "current" schedule table's current period finishes.
 *
 * Checks:
 * - both tables must exist and be accessible by the current app
 * - both tables must be driven by the same counter
 * - next table to chain must be stopped
 * - current table must be running
 *
 * !LINKSTO Kernel.Autosar.ScheduleTable.Chain, 2
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernChainScheduleTable
(	os_scheduleid_t sc,
	os_scheduleid_t sn
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_result_t r = OS_E_OK;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)sc);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)sn);

	OS_TRACE_NEXTSCHEDULETABLE_ENTRY(sc,sn);

	if ( !OS_CallingContextCheck() )
	{
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		r = OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
	}
	else
	if ( !OS_InterruptEnableCheck(OS_IEC_AUTOSAR) )
	{
		/* Possible diagnostic TOOLDIAG-3 <+1> */
		r = OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
	}
	else
	if ( (sc >= OS_nSchedules) || (sn >= OS_nSchedules) )
	{
		/* One or both of the specified tables is invalid
		 *
		 * !LINKSTO Kernel.Autosar.API.SystemServices.ChainScheduleTable.Invalid, 1
		*/
		r = OS_ERROR(OS_ERROR_InvalidScheduleId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		/* Possible diagnostic TOOLDIAG-1 <1> */
		const os_appcontext_t * const app = OS_CurrentApp();
		const os_schedule_t * const scs = &OS_scheduleTableBase[sc];
		const os_schedule_t * const sns = &OS_scheduleTableBase[sn];

		if ( (!OS_HasPermission(app, scs->permissions)) ||
			 (!OS_HasPermission(app, sns->permissions)) )
		{
			/* No permission for one or both of the tables
			*/
			r = OS_ERROR(OS_ERROR_Permission, OS_GET_PARAMETER_VAR());
		}
		else
		if ( OS_alarmTableBase[scs->alarm].counter != OS_alarmTableBase[sns->alarm].counter )
		{
			/* The schedule tables are driven by different counters
			 *
			 * !LINKSTO Kernel.Autosar.API.SystemServices.ChainScheduleTable.DifferentCounter, 2
			*/
			r = OS_ERROR(OS_ERROR_DifferentCounters, OS_GET_PARAMETER_VAR());
		}
		else
		{
			os_errorresult_t e;

			e = OS_DoChainScheduleTable(sc, sn, scs);
			if (e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError))
			{
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}
		}
	}

	OS_TRACE_NEXTSCHEDULETABLE_EXIT_P(r,sc,sn);
	return r;
}


#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
