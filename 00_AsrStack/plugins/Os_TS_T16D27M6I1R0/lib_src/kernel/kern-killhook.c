/* kern-killhook.c
 *
 * This file contains OS_KillHook
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-killhook.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KillHook
 *
 * The hook is killed by calling the architecture specific function
 * or macro OS_KillCalledContext() with the hook's saved
 * context as parameter.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KillHook(os_hookcontext_t *hc)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	return OS_KillCalledContext(&hc->c);
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_killhook_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
