/* lib-getlogicalcoreid.c
 *
 * This file contains the OS_GetLogicalCoreId function.
 * It returns the logical ID of the given physical ID
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: lib-getlogicalcoreid.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_alci.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_USE_LOGICAL_CORE_IDS == 1))

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_GetLogicalCoreId returns the logical ID of the given physical ID
 *
 * !LINKSTO Kernel.Misc.OS_GetLogicalCoreId, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_coreid_t OS_GetLogicalCoreId(os_coreid_t core)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	if (core >= OS_N_CORES_MAX)
	{
		return core;
	}
	else
	{
		return OS_alciPhyToLog[core];
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_USE_LOGICAL_CORE_IDS == 1))) */
const os_uint8_t OS_dummy_lib_getlogicalcoreid_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_USE_LOGICAL_CORE_IDS == 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/

