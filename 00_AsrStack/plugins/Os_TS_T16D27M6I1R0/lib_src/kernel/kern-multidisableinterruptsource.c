/* kern-multidisableinterruptsource.c
 *
 * This file contains the OS_MultiDisableInterruptSource function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multidisableinterruptsource.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiDisableInterruptSource disables an interrupt source in a multi-core system.
*/

OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiDisableInterruptSource(os_isrid_t i, const os_isr_t *isr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e = OS_ERRORCODE_NOCHECK(OS_ERROR_NoError);
	if (OS_GetIsrCoreId(isr) == OS_GetMyCoreId())
	{
		e = OS_LocalDisableInterruptSource(isr);
	}
	else
	{
		/* !LINKSTO Kernel.Autosar.Multicore.DisableInterruptSource.CrossCore, 1
		 * !LINKSTO Kernel.Autosar.Multicore.DisableInterruptSource.Synchronous, 1
		*/
		e = OS_SendDisableInterruptSource(i,isr);
	}
	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multidisableinterruptsource_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
