/* kern-startupcheckscounter.c
 *
 * This file contains the OS_StartupChecksCounter function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-startupcheckscounter.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Condition is always true.
 *
 * Reason: This warning depends on the number of configured cores.
 *   Only in case of a single core configuration, this comparison can be evaluated at compile time.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_panic.h>

#include <memmap/Os_mm_code_begin.h>

/* OS_StartupChecksCounter
 *
 * This function performs a variety of checks of the counter configuration
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_StartupChecksCounter(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_coreid_t const myCoreId = OS_GetMyCoreId();
	os_result_t result = OS_E_OK;
	os_unsigned_t i;

	for ( i = 0; i < OS_nCounters; i++ )
	{
		os_counter_t const* const ctr = &OS_counterTableBase[i];
		os_appcontext_t const* const app = OS_GET_APP(ctr->app);

		if ( OS_AppIsNull(app) )
		{
			result = OS_PANIC(OS_PANIC_SCHK_NoOwningApplication);
		}

		/* COVPT-1 +2 */
		/* Possible diagnostic TOOLDIAG-1 <1> */
		if (OS_GetCounterCoreId(ctr) == myCoreId)
		{
			os_permission_t const perms = OS_GET_APP(ctr->permissions);

			if ( !OS_HasPermission(app, perms) )
			{
				result = OS_PANIC(OS_PANIC_SCHK_OwningApplicationHasNoPermission);
			}

			if ( ctr->hwt != OS_NULL )
			{
				/* For hardware counters, the counter's range must be at least the timer's range,
				 * because the modulo arithmetic to permit otherwise is not implemented and would be costly.
				 *
				 * !LINKSTO Kernel.Autosar.Counter.Types.HARDWARE.ExtendedValue.Range, 1
				*/
				if ( ctr->maxallowedvalue < ctr->hwt->wrapMask )
				{
					result = OS_PANIC(OS_PANIC_SCHK_CounterRangeLowerThanHardwareTimer);
				}
			}
		}
	}

	return result;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_startupcheckscounter_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
