/* kern-multienableinterruptsource.c
 *
 * This file contains the OS_MultiEnableInterruptSource function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multienableinterruptsource.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiEnableInterruptSource Enables an interrupt source on a remote core.
*/

OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiEnableInterruptSource(os_isrid_t i, const os_isr_t *isr, os_boolean_t clearPending)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e = OS_ERRORCODE_NOCHECK(OS_ERROR_NoError);
	if (OS_GetIsrCoreId(isr) == OS_GetMyCoreId())
	{
		e = OS_LocalEnableInterruptSource(isr, clearPending);
	}
	else
	{
		/* !LINKSTO Kernel.Autosar.Multicore.EnableInterruptSource.CrossCore, 1
		 * !LINKSTO Kernel.Autosar.Multicore.EnableInterruptSource.Synchronous, 1
		*/
		e = OS_SendEnableInterruptSource(i, isr, clearPending);
	}
	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multienableinterruptsource_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
