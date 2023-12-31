/* lib-getspinlock.c
 *
 * This file contains the function OS_GetSpinlock().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: lib-getspinlock.c 35018 2021-08-23 09:29:21Z saga272975 $
*/

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 12.3 (required)
 * The comma operator shall not be used.
 *
 * Reason:
 * The OS uses macros to abstract APIs in the function call kernel case to improve maintainability.
 * These macros must return values and therefore use the comma operator to do this.
 *
 * MISRAC2012-2) Deviated Rule: 13.3 (advisory)
 * The increment (++) and decrement (--) operators should not be mixed with other operators in an
 * expression.
 *
 * Reason:
 * The OS uses macros to abstract APIs in the function call kernel case to improve maintainability.
 * These macros result in the combination of an increment operator with a comma operator.
*/

#include <Os_kernel.h>

#if ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))

#include <Os_api.h>

/*!
 * OS_GetSpinlock()
 *
 * Implements AUTOSAR GetSpinlock() in terms of OS_UserTryToGetSpinlock().
 * This is done to permit scheduling while spinning in user-mode.
 *
 * !LINKSTO Kernel.Autosar.API.SystemServices.GetSpinlock, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_GetSpinlock(os_autosarspinlockid_t lockId)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_tryspinlock_t flag;
	os_result_t result;

	do
	{
		/* Deviation MISRAC2012-1, MISRAC2012-2 <1> */
		result = OS_UserTryToGetSpinlock(lockId, &flag);
	}
	while ((result == OS_E_OK) && (flag == OS_TRYTOGETSPINLOCK_NOSUCCESS));

	return result;
}

#else /* (!((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1))) */
const os_uint8_t OS_dummy_lib_getspinlock_c = 0xeb;
#endif /* ((OS_KERNEL_TYPE != OS_MICROKERNEL) && (OS_N_CORES != 1)) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
