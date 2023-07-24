/* kern-initapp.c
 *
 * This file contains the OS_InitApp() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-initapp.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Condition is always true.
 *
 * Reason: This warning depends on the number of configured cores.
 *   Only in case of a single core configuration, this comparison is always true.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_InitApp()
 *
 * This function initialises the state of every OS-application in the system
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_InitApp(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_applicationid_t a;
	os_coreid_t const myCoreId = OS_GetMyCoreId();

	for ( a = 0; a < OS_nApps; a++ )
	{
		const os_appcontext_t *ap = &OS_appTableBase[a];

		/* COVPT-1 +2 */
		/* Possible diagnostic TOOLDIAG-1 <1> */
		if ( OS_GetAppCoreId(ap) == myCoreId )
		{
			os_appdynamic_t *ad = ap->dynamic;
			/* !LINKSTO Kernel.Autosar.OsApplication.ApplicationStates.Startup, 1
			*/
			ad->appstate = OS_APP_ACCESSIBLE;
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_initapp_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
