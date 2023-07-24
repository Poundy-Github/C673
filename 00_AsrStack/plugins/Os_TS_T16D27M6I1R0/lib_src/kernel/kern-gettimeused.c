/* kern-gettimeused.c
 *
 * This file contains the OS_GetTimeUsed function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-gettimeused.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_GetTimeUsed
 *
 * This function returns the amount of time used since it was last called.
 * It uses the global accounting structure, so it guarantees that the
 * global frc location holds the time of the last call and can therefore
 * be used as the baseline when setting the execution-timer interrupt.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_tick_t OS_GetTimeUsed(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_timervalue_t frc = OS_ReadExecTimer();
	os_tick_t used = (os_tick_t)OS_ExecTimerSub(frc, kernel_data->accounting.frc);
	kernel_data->accounting.frc = frc;

	return used;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_gettimeused_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
