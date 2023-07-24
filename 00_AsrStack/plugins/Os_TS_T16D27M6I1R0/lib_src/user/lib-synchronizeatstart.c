/* lib-synchronizeatstart.c
 *
 * Synchronize CPU cores before AUTOSAR startup
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: lib-synchronizeatstart.c 34824 2021-08-05 13:57:39Z ache271795 $
 */

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_api.h>

#include <memmap/Os_mm_code_begin.h>

/* OS_SynchronizeAtStart
 *
 * This function can be called by the startup code BEFORE main is called. It is used to synchronize
 * a multi-core system that already has all its cores running before the OS startup code is executed.
 *
 * All cores wait here till all other cores have arrived. Then the master proceeds immediately, but
 * the other cores wait until OS_StartCore is called.
 *
 * Note: This function depends on the OS_syncArray and OS_coreStarted being initialized to
 *       zero before it is called by any core
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_SynchronizeAtStart(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_coreid_t me = OS_GetMyCoreId();

	/* Wait here until all other cores get here */
	OS_SyncHere();

	if (me != OS_INITCORE)
	{
		/* Master continues, all others wait until they are explicitly started
		 * by some other core. */
		do {
			/* Wait here until told to start */
			OS_CacheInvalidate(&(OS_coreStarted[me]), sizeof(OS_coreStarted[0]));
		} while ( OS_coreStarted[me] != OS_TRUE );
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_lib_synchronizeatstart_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
