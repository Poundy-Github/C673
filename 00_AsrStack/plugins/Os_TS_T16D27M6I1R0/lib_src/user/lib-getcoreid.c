/* lib-getcoreid.c
 *
 * This file contains the OS_GetCoreID function.
 * It returns the logical ID of the current core.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: lib-getcoreid.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_api.h>
#include <Os_alci.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_GetCoreId implements the API GetCoreID
 *
 * It returns the logical ID of the current core.
 *
 * !LINKSTO Kernel.Autosar.API.SystemServices.GetCoreID, 1
 * Look! Can be called at any time!
 * !LINKSTO Kernel.Autosar.API.SystemServices.GetCoreID.BeforeStartOS, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_coreid_t OS_GetCoreId(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	return (os_coreid_t)OS_GetLogicalCoreId(OS_ArchGetCoreId());
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_lib_getcoreid_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
