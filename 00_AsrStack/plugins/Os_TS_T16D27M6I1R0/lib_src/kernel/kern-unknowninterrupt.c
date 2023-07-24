/* kern-unknowninterrupt.c
 *
 * This file contains the OS_UnknownInterrupt function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-unknowninterrupt.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#define OS_SID	OS_SID_TrapHandler
#define OS_SIF	OS_svc_TrapHandler

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_tool.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_UnknownInterrupt
 *
 * This function is called when an unconfigured interrupt occurs
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_uint8_t OS_UnknownInterrupt(os_isrid_t iid)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint8_t inKernel;
	OS_PARAM_UNUSED(iid);

	inKernel = OS_GetKernelData()->inKernel;
	/* can't propagate the return value of OS_ERROR -> ignore it */
	(void) OS_ERROR(OS_ERROR_UnknownInterrupt, OS_NULL);

	return inKernel;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_unknowninterrupt_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
