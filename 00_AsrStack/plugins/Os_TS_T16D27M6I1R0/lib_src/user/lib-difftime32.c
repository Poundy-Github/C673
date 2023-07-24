/* lib-difftime32.h - Implementation of OS_DiffTime32().
 *
 * This file contains the implementation of the public API OS_DiffTime32().
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: lib-difftime32.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_api.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_tool.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_DiffTime32()
 *
 * Saturated 32-bit difference of two timestamps.
 *
 * This function calculates the 32-bit difference Of two timestamps.
 * If the result would not fit in a 32-bit value, the maximum 32-bit
 * value is returned.
 *
 * !LINKSTO	Kernel.Feature.TimeStamp.API.DiffTime32, 2
 * !doctype SRC
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_uint32_t OS_DiffTime32(const os_timestamp_t *newTime, const os_timestamp_t *oldTime)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_timestamp_t diffTime;

	OS_TimeSub64(&diffTime, newTime, oldTime);

	if ( OS_TimeGetHi(diffTime) != 0 )
	{
		OS_TimeSetLo(diffTime,0xffffffffu);
	}

	return OS_TimeGetLo(diffTime);
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_lib_difftime32_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
