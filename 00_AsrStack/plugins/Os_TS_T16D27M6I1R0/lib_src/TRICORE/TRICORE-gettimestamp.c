/* TRICORE-gettimestamp.c
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: TRICORE-gettimestamp.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <TRICORE/Os_TRICORE_core.h>
#include <TRICORE/Os_TRICORE_stm.h>

#include <memmap/Os_mm_code_begin.h>

/* OS_TricoreGetTimestamp
 *
 * Places the current value of the STM (56/64 bits) into the indicated os_timestamp_t (64-bit) location
 *
 * Assumptions:
 *  - None. In particular, no assumption is made about interrupts being disabled.
 *
 * Parameters: currentTime points to the os_timestamp_t output location
 *
 * In this function, the loop terminates when the lower-part of the STM counter is read between two
 * identical values from the upper part.
 *
 * Termination: in theory, the loop might never terminate. However, this would require a very carefully-crafted
 * interrupt, or an interrupt load so high that in practice whatever called this function would never do
 * any processing anyway.
 *
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_TricoreGetTimestamp(os_timestamp_t *currentTime)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint32_t high1;
	os_uint32_t high2;
	os_uint32_t low;

	do
	{
		high1 = OS_timestampStm->stm_tim6;
		low = OS_timestampStm->stm_tim0;
		high2 = OS_timestampStm->stm_tim6;
	} while ( high1 != high2 );

	currentTime->tsLo = low;
	currentTime->tsHi = high1;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_TRICORE_gettimestamp_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
