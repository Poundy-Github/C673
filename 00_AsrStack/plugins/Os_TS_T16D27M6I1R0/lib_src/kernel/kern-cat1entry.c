/* kern-cat1entry.c
 *
 * This file contains the Cat1 interrupt handler wrapper.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-cat1entry.c 34824 2021-08-05 13:57:39Z ache271795 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   Variable is set but never used.
 *
 * Reason: On targets where the inKernel flag is handled by the assembly wrappers,
 * the variable is not used.
 */

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/* OS_Cat1Entry() - call a Category 1 ISR.
 *
 * This function calls a category 1 ISR.
 *
 * The previous value of inFunction is saved, then inFunction is set
 * to INCAT1.
 * The previous value of inKernel is saved, then inKernel is set to 1
 * (unless OS_USE_IRQ_ATOMIC_INKERNEL==1).
 * The previous value of isrCurrent is saved, then isrCurrent is set
 * to the isr ID (parameter)
 *
 * Then the ISR itself is called directly. The pre- and post-ISR
 * hooks are NOT called.
 * Finally, the saved values of isrCurrent, inKernel and inFunction
 * are restored, and the saved value of inKernel is returned.
 *
 * Interrupts remain at the BISR priority throughout. The run priority
 * is not used for category 1 interrupts.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_uint8_t OS_Cat1Entry(os_isrid_t iid)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	const os_isr_t *isr;
	os_isrfunc_t f;
	/* Possible diagnostic TOOLDIAG-1 <1> */
	os_uint8_t inKernel;
	os_uint8_t inFunction;
	os_isrid_t oldIsr;

	isr = &OS_isrTableBase[iid];
	f = isr->func;

	/* Save and set inKernel, inFunction and isrCurrent
	*/
	inKernel = kernel_data->inKernel;
	OS_SetIsrinKernel();

	inFunction = kernel_data->inFunction;
	kernel_data->inFunction = OS_INCAT1;

	oldIsr = kernel_data->isrCurrent;
	kernel_data->isrCurrent = iid;

	OS_HW_TRACE_ISR(iid);
	(*f)();

	/* Restore previous values of isrCurrent, inFunction and inKernel.
	 * Then exit.
	*/
	kernel_data->isrCurrent = oldIsr;
	kernel_data->inFunction = inFunction;
	OS_RestoreIsrinKernel(inKernel);
	/* Signal the possibly interrupt ISR (or NO_ISR). Must be after
	 * restoring isrCurrent to avoid a race condition when another
	 * category 1 ISR is nested.
	 */
	OS_HW_TRACE_ISR(oldIsr);

	return inKernel;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_cat1entry_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
