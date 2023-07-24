/* kern-getcurrentstackarea.c
 *
 * This file contains the OS_GetCurrentStackArea function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-getcurrentstackarea.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Condition is always true.
 *
 * Reason: Some targets don't use a separate ISR stack, but use the kernel stack instead.
 *  Only in these cases OS_GetIsrStackBase returns NULL.
*/

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.6 (required)
 * A cast shall not be performed between pointer to void and an arithmetic type.
 *
 * Reason:
 * The cast is required, because the relevant values stored by the kernel
 * need adjustments prior to returning them. These adjustments use integers,
 * which are finally turned into pointers.
 */

#include <Os_api.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>		/* For OS_GetCurrentSp(), os_task_t etc. */

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_GetCurrentStackArea() returns base and limit addresses for the stack area of the current executing thread
 *
 * !LINKSTO Kernel.Feature.GetCurrentStackArea, 1
 * !LINKSTO Kernel.Feature.GetCurrentStackArea.ValidContexts, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_GetCurrentStackArea(void **begin, void **end)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_address_t rBegin = 0;
	os_address_t rEnd = 0;
	const os_isr_t *isr;

	if ( kernel_data->inFunction == OS_INTASK )
	{
		/* COVPT-1 */
		if ( kernel_data->taskCurrent != OS_NULL )			/* Should always be true ... */
		{
			rBegin = (os_address_t)(kernel_data->taskCurrent->stackBase);
			rEnd = rBegin + kernel_data->taskCurrent->stackLen;
		}
	}
	else
	if ( kernel_data->inFunction == OS_INCAT2 )
	{
		/* COVPT-2 */
		if ( kernel_data->isrCurrent < OS_nInterrupts )		/* Should always be true ... */
		{
			isr = &OS_isrTableBase[kernel_data->isrCurrent];

			rBegin = (os_address_t)(OS_GetIsrStackBase(isr));

			/* Possible diagnostic TOOLDIAG-1 <1> */
			if ( rBegin == 0u )
			{
				rBegin = (os_address_t)kernel_data->iStackBase;
				rEnd = rBegin + kernel_data->iStackLen;
			}
			else
			{
				rEnd = rBegin + isr->stackLen;
			}
		}
	}
	else
	{
		/* MISRA-C */
	}

	if ( begin != OS_NULL )
	{
		/* Deviation MISRAC2012-1 <1> */
		*begin = (void *) rBegin;
	}

	if ( end != OS_NULL )
	{
		/* Deviation MISRAC2012-1 <1> */
		*end = (void *) rEnd;
	}
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_getcurrentstackarea_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
