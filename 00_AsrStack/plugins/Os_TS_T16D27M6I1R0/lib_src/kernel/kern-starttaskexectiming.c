/* kern-starttaskexectiming.c
 *
 * This file contains the OS_StartTaskExecTiming function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-starttaskexectiming.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Condition is always false.
 *
 * Reason: If timing protection is switched off, OS_GET_ACCT always evaluates to OS_NULL.
 *
 * TOOLDIAG-2) Possible diagnostic: PointlessComparison
 *   Condition is always false.
 *
 * Reason: If timing protection is switched off, OS_GET_TP always evaluates to zero.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_StartTaskExecTiming
 *
 * This function gets the amount of execution time that has been used
 * by a task and stores it into the global accounting structure. It then
 * sets the limit in the global accounting structure and sets the timer
 * interrupt for the difference.
 * The function is called when a task gains or regains the CPU.
 *
 * !LINKSTO Kernel.Autosar.Protection.TimingProtection.ExecutionTime.Measurement.Task, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_StartTaskExecTiming(const os_task_t *tp)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_taskaccounting_t *acc = OS_GET_ACCT(tp->accounting);
	os_tick_t remaining;

	OS_PARAM_UNUSED(tp);

	/* Possible diagnostic TOOLDIAG-1 <1> */
	if ( acc != OS_NULL )
	{
		kernel_data->accounting.frc = OS_ReadExecTimer();
		kernel_data->accounting.inFunction = OS_INTASK;
		kernel_data->accounting.etType = acc->etType;
		kernel_data->accounting.etUsed = acc->etUsed;
		kernel_data->accounting.etLimit = OS_GET_TP(tp->execBudget);

		/* Possible diagnostic TOOLDIAG-2 <1> */
		if (kernel_data->accounting.etLimit != 0)
		{
			/* COVPT-1 */
			if (kernel_data->accounting.etUsed >= kernel_data->accounting.etLimit)
			{
				/* This should never happen.
				*/
				remaining = 1;
			}
			else
			{
				remaining = kernel_data->accounting.etLimit - kernel_data->accounting.etUsed;
			}
			OS_SetExecTimingInterrupt(kernel_data->accounting.frc, remaining);
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_starttaskexectiming_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
