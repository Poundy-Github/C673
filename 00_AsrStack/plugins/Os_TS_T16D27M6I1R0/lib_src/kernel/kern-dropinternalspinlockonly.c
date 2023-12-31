/* kern-dropinternalspinlock.c
 *
 * This file contains the function OS_DropInternalSpinlockOnly().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-dropinternalspinlockonly.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 17.2 (required)
 *   Functions shall not call themselves, either directly or indirectly.
 *
 * Reason:
 *   OS_DropInternalSpinlockOnly() might call itself indirectly via OS_Panic().
 *   OS_Panic() detects recursive calls by means of the core-local variable
 *   panicCode. If OS_Panic() is entered a second time, it calls
 *   OS_ShutdownNoHooks() which doesn't call OS_Panic() again. Instead, it
 *   stops the system, and, therefore, the maximum nesting level is two calls.
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_spinlock.h>
#include <Os_panic.h>

/*!
 * OS_DropInternalSpinlockOnly()
 *
 * Drops the internal spinlock identified by 'lockId'.
 *
 * The macro OS_NHARDWARELOCKS denotes the number of locks implemented in hardware, if provided by a processor.
 * Any remaining locks are implemented by first taking a special hardware lockId to protect the array
 * of software locks. Besides this, the macro OS_HAS_ARCHSPINLOCK allows the use of a completely architecture-dependent
 * way of locking, e.g. atomic compare-and-swap instructions.
 */
/* Deviation MISRAC2012-1 <1> */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_DropInternalSpinlockOnly(os_lockid_t lockId)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_lockid_t lockIndex;

#if (OS_NHARDWARELOCKS != 0)
	if (lockId < OS_NHARDWARELOCKS)
	{
		OS_ArchDropHardwareLock(lockId);
	}
	else
#endif
	{
		lockIndex = lockId - OS_NHARDWARELOCKS;
		if (OS_DEVSANITYCHECK(lockIndex >= OS_nSoftwareLocks))
		{
			(void) OS_PANIC(OS_PANIC_InvalidInternalSpinlockConfig);
		}
#if (OS_HAS_ARCHSPINLOCK == 1)
		OS_ArchDropSpinlock(&OS_softwareLock[lockIndex]);
#else
		OS_CacheInvalidate(&OS_softwareLock[lockIndex], sizeof(OS_softwareLock[lockIndex]));
		OS_softwareLock[lockIndex] = 0;
		OS_CacheFlush(&OS_softwareLock[lockIndex], sizeof(OS_softwareLock[lockIndex]));
#endif /* OS_HAS_ARCHSPINLOCK == 1 */
	}
}

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_kern_dropinternalspinlockonly_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
