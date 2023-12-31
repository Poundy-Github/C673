/* kern-taskreturn.c
 *
 * This file contains the OS_KernTaskReturn function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-taskreturn.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#define OS_SID	OS_SID_TaskReturn
#define OS_SIF	OS_svc_TaskReturn

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernTaskReturn
 *
 * This function is called in the kernel when a task returns from its main
 * function without calling TerminateTask() or ChainTask(), for example
 * from the exception handler that detects this error.
 *
 * The Autosar spec requires that the error hook be called with
 * E_OS_MISSINGEND, and that the task be cleanly terminated (resources
 * released, etc.).
 * There are two possibilities:
 * 1. the error handler will do everything needed for us
 * 2. error actions have been disabled, so we have to do the killing
 *    ourselves
 *
 * Further error handling will be done by the user space function
 * OS_MissingTerminateTask.
 *
 * The error handler calls the error hook and kills the task ...
 * !LINKSTO Kernel.Autosar.ServiceErrors.Miscellaneous.TaskReturn.ErrorHook, 1
 * !LINKSTO Kernel.Autosar.ServiceErrors.Miscellaneous.TaskReturn, 1
 *
 * The kernel manages interrupts itself - each task has its own interrupt status, as does the idle loop ...
 * !LINKSTO Kernel.Autosar.ServiceErrors.Miscellaneous.TaskReturn.Interrupts, 1
 *
 * Killing the task takes care of any resources still held...
 * !LINKSTO Kernel.Autosar.ServiceErrors.Miscellaneous.TaskReturn.Resources, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_KernTaskReturn(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* can't propagate the return value of OS_ERROR -> ignore it */
	(void) OS_ERROR(OS_ERROR_ReturnFromTask, OS_NULL);
#ifdef OS_EXCLUDE_ERRORACTION
	/* just a sanity check if we actually have a task left */
	/* COVPT-1 */
	if (OS_GetKernelData()->taskCurrent != OS_NULL)
	{
		(*OS_killTaskFunc)(OS_GetKernelData()->taskCurrent, OS_TS_SUSPENDED);
	}
#endif
	/* in case something went wrong, OS_MissingTerminateTask will clean up the rest. */
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_taskreturn_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
