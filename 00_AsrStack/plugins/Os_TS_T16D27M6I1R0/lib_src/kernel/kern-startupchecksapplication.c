/* kern-startupchecksapplication.c
 *
 * This file contains the OS_StartupChecksApplication function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-startupchecksapplication.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_panic.h>

#include <memmap/Os_mm_code_begin.h>

OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_StartupChecksApplication(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_result_t result = OS_E_OK;

	/* COVPT-1 */
	if (OS_GetMyCoreId() == (os_coreid_t)OS_INITCORE)
	{
		os_unsigned_t i;
		os_permission_t permBits = 0;

		for ( i = 0; i < OS_nApps; i++ )
		{
			os_appcontext_t const* const app = &OS_appTableBase[i];

			if (  app->appId != i )
			{
				result = OS_PANIC(OS_PANIC_SCHK_AppIdIsNotIndexInAppTable);
			}

			if (  *app->buildId != OS_configurationId )
			{
				result = OS_PANIC(OS_PANIC_SCHK_AppConfigurationIdMismatch);
			}

			if ( app->restartTask != OS_NULLTASK )
			{
				if ( OS_GET_APP(OS_taskTableBase[app->restartTask].app) != app )
				{
					result = OS_PANIC(OS_PANIC_SCHK_AppRestartTaskNotMemberOfApp);
				}
			}

			if ( app->permissionBit == 0 )
			{
				result = OS_PANIC(OS_PANIC_SCHK_AppHasNoPermissions);
			}

			/* System applications have all bits set in their permissionBit field, because they
			 * may access any object. Hence, their permission identification value, i.e. 'permissionBit',
			 * is not unique.
			 */
			if ( !OS_AppIsSystemApp(app) )
			{
				if ( (permBits & app->permissionBit) != 0 )
				{
					result = OS_PANIC(OS_PANIC_SCHK_AppPermissionBitNotUnique);
				}

				permBits |= app->permissionBit;
			}
		}
	}

	return result;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_startupchecksapplication_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
