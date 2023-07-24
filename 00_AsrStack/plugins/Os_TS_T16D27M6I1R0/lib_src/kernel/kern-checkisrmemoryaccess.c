/* kern-checkisrmemoryaccess.c
 *
 * This file contains the OS_CheckIsrMemoryAccess function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-checkisrmemoryaccess.c 35018 2021-08-23 09:29:21Z saga272975 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   Variable is set but never used.
 *
 * Reason: Not an issue, variable will be used if at least one application exists.
 *
 * TOOLDIAG-2) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if "error handling for APIs returning void" is not excluded.
 *   See also OS_EXCLUDE_ERRORHANDLINGFORVOIDAPI.
*/

#define OS_SID	OS_SID_CheckIsrMemoryAccess
#define OS_SIF	OS_svc_CheckIsrMemoryAccess

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/*
 * Created helper function to reduce cyclomatic complexity of the
 * function OS_KernCheckIsrMemoryAccess
*/
static os_memoryaccess_t OS_DoCheckISRMemoryAccess
	(os_isrid_t, const void *, os_size_t);

OS_TOOL_FUNCTION_ATTRIB_PRE
static os_memoryaccess_t OS_DoCheckISRMemoryAccess
(	os_isrid_t i,
	const void *ptr,
	os_size_t len
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * kernel_data;
	os_address_t first;
	os_address_t last;
	const os_isr_t *isr;
	os_memoryaccess_t a = 0;
	/* Possible diagnostic TOOLDIAG-1 <1> */
	const os_appcontext_t *app;
	os_address_t base;
	os_address_t limit;

	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)i);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)ptr);
	OS_SAVE_PARAMETER_N(2,(os_paramtype_t)len);

	first = (os_address_t)ptr;
	last = first + len;

	if ( last > first )
	{
		isr = &OS_isrTableBase[i];
		app = OS_GET_APP(isr->app);

		if ( OS_AppIsTrusted(app) )
		{
			/* The ISR doesn't belong to an application, or the
			 * application is trusted. Either way, the ISR can write
			 * anywhere.
			 *
			 * NOTE: Just because the ISR has "permission" to
			 * access the memory doesn't mean that it will be able to
			 * do so with impunity. For example, non-existent addresses
			 * will still cause bus error traps, and writing to what is
			 * considered the stack space is not necessarily valid.
			*/
			a = OS_MA_READ | OS_MA_WRITE | OS_MA_EXEC;

			if ( OS_GetIsrStackLimit(isr->dynamic) == OS_NULL )
			{
				kernel_data = OS_GetKernelData();
				base = (os_address_t)kernel_data->iStackBase;
				limit = base + kernel_data->iStackLen;
			}
			else
			{
				limit = (os_address_t)OS_GetIsrStackLimit(isr->dynamic);
				base = limit - isr->stackLen;
			}

			if ( (first >= base) && (last <= limit) )
			{
				a |= OS_MA_STACK;
			}
		}
		else
		if ( OS_IS_WITHIN_ISR_REGION(first, last) )
		{
			/* Region lies entirely within the ISR's private data section.
			 * This region is READABLE and WRITEABLE
			*/
			a = OS_MA_READ | OS_MA_WRITE;
		}
		else
		if ( OS_IS_WITHIN_APP_REGION(first, last) )
		{
			/* Region lies entirely within the app's private data section.
			 * This region is READABLE and WRITEABLE
			*/
			a = OS_MA_READ | OS_MA_WRITE;
		}
		else
		if ( (OS_GetIsrStackLimit(isr->dynamic) != OS_NULL) &&
			 (first >= ((os_address_t)OS_GetIsrStackLimit(isr->dynamic) - isr->stackLen)) &&
			 (last <= (os_address_t)OS_GetIsrStackLimit(isr->dynamic)) )
		{
			/* MISRA non-violation above: 12.5. Read the rule carefully.
			 */
			/* Region lies entirely within the ISR's stack.
			 * WARNING: even though this is true, it does not
			 * make sense to write here blindly. The ISR will
			 * most likely not be using its full stack allocation,
			 * and the remainder might be occupied by a higher-prio
			 * ISR or a called (trusted) function.
			*/
			a = OS_MA_STACK | OS_MA_READ | OS_MA_WRITE;
		}
		else
		{
			a = (os_memoryaccess_t)OS_IsrMemoryAccess(isr, first, last);
		}
	}
	else
	if ( OS_ErrorHandlingForVoidApi() )
	{
		/* can't propagate the return value of OS_ERROR -> ignore it */
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		(void) OS_ERROR(OS_ERROR_InvalidMemoryRegion, OS_GET_PARAMETER_VAR());
	}
	else
	{
		/* MISRA-C */
	}

	return a;
}

/*!
 * OS_KernCheckIsrMemoryAccess implements the API CheckIsrMemoryAccess
 *
 * !LINKSTO Kernel.Autosar.API.SystemServices.CheckISRMemoryAccess, 2
 *
 * There is no permission check here ...
 * !LINKSTO Kernel.Autosar.OsApplication.Permissions.Exceptions, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_memoryaccess_t OS_KernCheckIsrMemoryAccess
(	os_isrid_t i,
	const void *ptr,
	os_size_t len
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_memoryaccess_t a = 0;

	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)i);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)ptr);
	OS_SAVE_PARAMETER_N(2,(os_paramtype_t)len);

	OS_TRACE_CHECKISRMEMORYACCESS_ENTRY(i);

	if ( !OS_CallingContextCheck() )
	{
		if ( OS_ErrorHandlingForVoidApi() )
		{
			/* can't propagate the return value of OS_ERROR -> ignore it */
			/* Possible diagnostic TOOLDIAG-2 <+1> */
			(void) OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
		}
	}
	else
	if ( !OS_InterruptEnableCheck(OS_IEC_AUTOSAR) )
	{
		if ( OS_ErrorHandlingForVoidApi() )
		{
			/* can't propagate the return value of OS_ERROR -> ignore it */
			/* Possible diagnostic TOOLDIAG-2 <+1> */
			(void) OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
		}
	}
	else
	if ( i < OS_nInterrupts )
	{
		a = OS_DoCheckISRMemoryAccess(i, ptr, len);
	}
	else
	if ( OS_ErrorHandlingForVoidApi() )
	{
		/* can't propagate the return value of OS_ERROR -> ignore it */
		/* Possible diagnostic TOOLDIAG-2 <+1> */
		(void) OS_ERROR(OS_ERROR_InvalidIsrId, OS_GET_PARAMETER_VAR());
	}
	else
	{
		/* MISRA-C */
	}

	OS_TRACE_CHECKISRMEMORYACCESS_EXIT_P(a,i);
	return a;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_checkisrmemoryaccess_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
