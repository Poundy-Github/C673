/* kern-taskspoutofbounds.c
 *
 * This file contains the OS_TaskSpOutOfBounds function. It returns TRUE if the
 * task's SP lies outside the permitted boundary.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-taskspoutofbounds.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/* OS_TaskSpOutOfBounds
 *
 * This function returns TRUE if the task's stack pointer lies outside the
 * permitted boundaries.
 *
 * The code here assumes that (in the case of STACKGROWSDOWN at least) the
 * stack model is "decrement before store", so that a stack pointer that is
 * pointing just outside the stack at the top is perfectly OK.
 *
 * If the stack pointer provided is OS_NULL we return FALSE (==OK) because
 * on some architectures a stack-pointer might not be available sometimes.
 * (see TRICORE)
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_boolean_t OS_TaskSpOutOfBounds(os_address_t sp, const os_task_t *tp)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_address_t base;

	base = (os_address_t)tp->stackBase;

	return ( sp != 0 ) && ( (sp < base) || (sp > (base + tp->stackLen)) );
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_taskspoutofbounds_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
