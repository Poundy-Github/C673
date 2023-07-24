/* kern-startisrexectiming.c
 *
 * This file contains the OS_StartIsrExecTiming function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-startisrexectiming.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_StartIsrExecTiming
 *
 * This function is called from the category 2 interrupt entry routine.
 * It returns a value to be stored and passed to OS_StopIsrExecTiming
 * after the  ISR returns.
 * The entry/exit routines are responsible for saving/restoring the
 * returned time remainig AND the inFunction flag from the accounting
 * structure.
 *
 * !LINKSTO Kernel.Autosar.Protection.TimingProtection.ExecutionTime.Measurement.ISR, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_StartIsrExecTiming(os_tick_t budget)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();

	kernel_data->accounting.etUsed = 0;
	kernel_data->accounting.etLimit = budget;
	kernel_data->accounting.inFunction = OS_INCAT2;
	kernel_data->accounting.etType = OS_ACC_BUDGET;
	kernel_data->accounting.frc = OS_ReadExecTimer();

	if (budget != 0)
	{
		OS_SetExecTimingInterrupt(kernel_data->accounting.frc, budget);
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_startisrexectiming_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
