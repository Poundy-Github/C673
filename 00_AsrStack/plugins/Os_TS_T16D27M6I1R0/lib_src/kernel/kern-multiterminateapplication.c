/* kern-multiterminateapplication.c
 *
 * This file contains the OS_MultiTerminateApplication function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-multiterminateapplication.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_messagequeue.h>


#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_MultiTerminateApplication terminates an application in a multi-core system.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_errorresult_t OS_MultiTerminateApplication(
	os_applicationid_t appid,
	const os_appcontext_t *app,
	os_restart_t restart)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_errorresult_t e;

	if ( OS_GetAppCoreId(app) == OS_GetMyCoreId() )
	{
		e = OS_LocalTerminateApplication(app, restart);
	}
	else
	{
		e = OS_SendTerminateApplication(appid, app, restart);
	}

	return e;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_multiterminateapplication_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
