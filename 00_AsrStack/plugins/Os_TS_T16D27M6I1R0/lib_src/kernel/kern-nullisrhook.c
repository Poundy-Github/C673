/* kern-nullisrhook.c
 *
 * This file contains the OS_NullIsrHook function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-nullisrhook.c 34824 2021-08-05 13:57:39Z ache271795 $
 */

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/* OS_NullIsrHook
 *
 * This function does nothing. It is used as a replacement for
 * PreIsrHook and PostIsrHook when they are not configured.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_NullIsrHook(os_isrid_t isr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_PARAM_UNUSED(isr);
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_nullisrhook_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
