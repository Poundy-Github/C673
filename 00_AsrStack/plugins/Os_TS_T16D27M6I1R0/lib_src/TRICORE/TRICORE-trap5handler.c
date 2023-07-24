/* TRICORE-trap5handler.c
 *
 * This file contains the OS_Trap5Handler function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: TRICORE-trap5handler.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-2) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to void into pointer to
 * object.
 *
 * Reason:
 * A pointer is read from hardware, which doesn't provide C language type
 * information. Hence, a type cast is required.
 *
 * MISRAC2012-3) Deviated Rule: 11.6 (required)
 * A cast shall not be performed between pointer to void and an arithmetic type.
 *
 * Reason:
 * A value is read from hardware, which essentially represents a pointer.
 * The hardware, though, has no notion of C language types. Hence, the type
 * cast is required.
 */

#define OS_SID OS_SID_ArchTrapHandler
#define OS_SIF OS_svc_ArchTrapHandler

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_Trap5Handler()
 *
 * This function handles TRICORE class 5 traps.
 *
 * Class 5 traps occur when the code specifically asks the CPU to check
 * for an error condition.
 *
 * The trap is therefore handled as a non-fatal exception, which
 * causes termination/quarantine of the task that caused the error.
 *
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection.CPU.Exception, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_Trap5Handler(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uppercx_t *ucx;
	os_uint32_t pcxi;
	OS_PH_PARAMETERACCESS_DECL

	/* Ensure that the function call is complete before reading PCXI
	*/
	OS_DSYNC();

	pcxi = OS_MFCR(OS_PCXI);

	/* If either of the cx values turns out to be OS_NULL, we have a serious
	 * problem.
	*/
	/* Deviation MISRAC2012-2, MISRAC2012-3 <1> */
	ucx = OS_AddrFromCx(pcxi);

	/* The OS_TrapEntry routine places important information
	 * into the upper context, like the old values of the inKernel and
	 * inFunction flags. The trap identification number is also there.
	 * The exception PC (return address for the trap handler) is in
	 * the lower context that is the next in the list.
	*/
	/* Deviation MISRAC2012-2, MISRAC2012-3 <1> */
	OS_PH_SAVE_PARAMETER_N(0, OS_GetTrapPCFromUpperCx(ucx));
	OS_PH_SAVE_PARAMETER_N(1, 5);
	OS_PH_SAVE_PARAMETER_N(2, ucx->d15);

	switch ( ucx->d15 )
	{
	case 1:		/* Arithmetic overflow */
	case 2:		/* Sticky arithmetic overflow */
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_ArithmeticTrap, OS_PH_GET_PARAMETER_VAR());
		break;

	default:	/* Unknown - not reachable? */
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_FatalException, OS_PH_GET_PARAMETER_VAR());
		break;
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_TRICORE_trap5handler_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
