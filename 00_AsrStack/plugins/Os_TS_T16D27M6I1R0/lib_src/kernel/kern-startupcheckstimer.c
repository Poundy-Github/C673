/* kern-startupcheckstimer.c
 *
 * This file contains the OS_StartupChecksTimer function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-startupcheckstimer.c 34824 2021-08-05 13:57:39Z ache271795 $
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

/* OS_StartupChecksTimer
 *
 * This function performs a variety of checks of the hardware timer systems
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_StartupChecksTimer(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_coreid_t const myCoreId = OS_GetMyCoreId();
	os_result_t result = OS_E_OK;
	os_unsigned_t i;

	for ( i = 0; i < OS_nHwTimers; i++ )
	{
		os_hwt_t const* const hwt = &OS_hwTimerTableBase[i];
		/* COVPT-1 +2 */
		/* Possible diagnostic TOOLDIAG-1 <1> */
		if (OS_GetTimerCoreId(hwt) == myCoreId)
		{
#if OS_HWT_POWEROF2
			/* If the architecture only supports power-of-2 timer wrap values we must check that
			 * the wrap masks are correct.
			*/
			if ( !OS_IsPowerOf2(hwt->wrapMask+1) )
			{
				result = OS_PANIC(OS_PANIC_SCHK_NonPowerOfTwoTimerWraparoundNotSupported);
			}
#endif

			if ( (hwt->wrapMask <= hwt->maxDelta) || (hwt->maxDelta <= hwt->defDelta) )
			{
				result = OS_PANIC(OS_PANIC_SCHK_TimerMaxDeltaAndDefDeltaInconsistent);
			}
		}
	}

	return result;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_startupcheckstimer_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
