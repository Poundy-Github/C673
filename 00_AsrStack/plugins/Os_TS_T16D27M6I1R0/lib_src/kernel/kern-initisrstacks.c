/* kern-initisrstacks.c
 *
 * This file contains the OS_InitIsrStacks() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-initisrstacks.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Condition is always true.
 *
 * Reason: Some targets don't use a separate ISR stack, but use the kernel stack instead.
 *  Only in these cases OS_GetIsrStackBase returns NULL.
 *
 * TOOLDIAG-2) Possible diagnostic: PointlessComparison
 *   Condition is always true.
 *
 * Reason: This warning depends on the number of configured cores.
 *   Only in case of a single core configuration, this comparison can be evaluated at compile time.
 *
 * TOOLDIAG-3) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason: See TOOLDIAG-1.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_InitIsrStacks()
 *
 * Sets all ISR stack's content to OS_STACKFILL.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_InitIsrStacks(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_coreid_t const myCoreId = OS_GetMyCoreId();
	os_isrid_t isrId;

	for (isrId = 0; isrId < OS_nInterrupts; isrId++)
	{
		os_isr_t const * const is = &OS_isrTableBase[isrId];
		/* COVPT-1 +2 */
		/* Possible diagnostic TOOLDIAG-2 <1> */
		if (OS_GetIsrCoreId(is) == myCoreId)
		{
			/* Depending on the architecture, stacks may reside on the
			 * interrupt/kernel stack. In that case OS_GetIsrStackBase()
			 * returns OS_NULL. These stacks are already initialized by
			 * OS_InitKernStack().
			 */
			os_stackelement_t * const p = OS_GetIsrStackBase(is);
			/* Possible diagnostic TOOLDIAG-1 <1> */
			if (p != OS_NULL)
			{
				os_size_t k;
				/* Possible diagnostic TOOLDIAG-3 <1> */
				for (k = 0; k < (is->stackLen / sizeof(os_stackelement_t)); k++)
				{
					p[k] = OS_STACKFILL;
				}
			}
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_initisrstacks_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
