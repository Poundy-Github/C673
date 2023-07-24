/* kern-controlidle.c
 *
 * This file contains the OS_KernControlIdle function.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-controlidle.c 34824 2021-08-05 13:57:39Z ache271795 $
*/

#define OS_SID	OS_SID_ControlIdle
#define OS_SIF	OS_svc_ControlIdle

/* Note: this comment is needed for asc_Os/tools/errdb-to-c.pl
 *
 * OS_ERRORCODE_CHECK(OS_ERROR_CoreIsDown)
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#if (OS_N_CORES > 1)
#include <Os_messagequeue.h>
#endif

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_KernControlIdle
 *
 * !LINKSTO Kernel.Autosar.API.SystemServices.ControlIdle, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_result_t OS_KernControlIdle(os_coreid_t c, os_idlemode_t mode)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_result_t r = OS_E_OK;
	os_errorresult_t e;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)c);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)mode);

	if ( !OS_CallingContextCheck() )
	{
		/*
		 * !LINKSTO Kernel.Autosar.API.SystemServices.ControlIdle.InvalidContext, 1
		*/
		r = OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
	}
	else
	{
#if (OS_N_CORES > 1)
		/* COVPT-1 */
		if ( !(((c) < OS_N_CORES_MAX) && OS_CoreIsInUse(c)) )
		{
			/*
			 * !LINKSTO Kernel.Autosar.API.SystemServices.ControlIdle.InvalidCore, 1
			*/
			r = OS_ERROR(OS_ERROR_InvalidCoreId, OS_GET_PARAMETER_VAR());
		}
		else
#endif
		if ( mode >= OS_N_IDLE_MODES )
		{
			/*
			 * !LINKSTO Kernel.Autosar.API.SystemServices.ControlIdle.InvalidIdleMode, 1
			*/
			r = OS_ERROR(OS_ERROR_InvalidIdleMode, OS_GET_PARAMETER_VAR());
		}
		else
		{
#if (OS_N_CORES == 1)
			e = OS_DoControlIdle(mode);
#else
			/* COVPT-2 */
			if (c == OS_GetMyCoreId())
			{
				e = OS_DoControlIdle(mode);
			}
			else
			{
				e = OS_SendControlIdle(c, mode);
			}
#endif
			/* COVPT-3 */
			if ( e != OS_ERRORCODE_NOCHECK(OS_ERROR_NoError) )
			{
				r = OS_ERROR_NOCHECK(e, OS_GET_PARAMETER_VAR());
			}
		}
	}

	return r;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_controlidle_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
