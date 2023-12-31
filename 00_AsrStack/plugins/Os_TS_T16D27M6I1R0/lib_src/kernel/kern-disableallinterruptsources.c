/* kern-disableallinterruptsources.c
 *
 * This file contains the implementation of the function to disable all ISRs on current core.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-disableallinterruptsources.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_DisableAllInterruptSources()
 *
 * This function disables all the interrupt sources configured for this core
 * except those with flags specified in the 'mask'.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_DisableAllInterruptSources(os_uint8_t mask)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_isrid_t i;
	os_isr_t const * isr;
	os_coreid_t const myCoreId = OS_GetMyCoreId();

	/* Disable all interrupts on current core except for interrupt type listed in mask */
	for (i = 0; i < OS_nInterrupts; i++)
	{
		isr = &OS_isrTableBase[i];
		if (OS_GetIsrCoreId(isr) == myCoreId)
		{
			if((isr->flags & mask) == 0u)
			{
				OS_DisableIsr(isr);
			}
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_disableallinterruptsource_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
