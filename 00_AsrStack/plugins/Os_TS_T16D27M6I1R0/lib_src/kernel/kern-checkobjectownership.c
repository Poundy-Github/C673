/* kern-checkobjectownership.c
 *
 * This file contains the OS_CheckObjectOwnership function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-checkobjectownership.c 34824 2021-08-05 13:57:39Z ache271795 $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: StatementIsUnreachable
 *   statement not reached.
 *
 * Reason:
 *   These warnings depend on the OS configuration and library optimization.
 *   The statements can be reached, if "error handling for APIs returning void" is not excluded.
 *   See also OS_EXCLUDE_ERRORHANDLINGFORVOIDAPI.
*/

#define OS_SID	OS_SID_CheckObjectOwnership
#define OS_SIF	OS_svc_CheckObjectOwnership

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

/* Include definitions for tracing */
#include <Os_trace.h>

#include <memmap/Os_mm_code_begin.h>

/* MISRA-C checkers want prototypes for static helpers */
static os_boolean_t OS_GetOwningAppForObject
	(os_objecttype_t, os_objectid_t, const os_appcontext_t **, os_paramtype_t *);

/* Helper to actually do extract the owner of a given object.
 * If the id was valid, returns TRUE and fills the given application pointer.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
static os_boolean_t OS_GetOwningAppForObject
(	os_objecttype_t typ,
	os_objectid_t id,
	const os_appcontext_t ** app,
	os_paramtype_t *p			/* to report errors */
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_boolean_t ret = OS_FALSE;

	OS_PARAM_UNUSED(p);

	switch ( typ )
	{
	case OS_OBJ_TASK:
		if ( OS_IsValidTaskId(id) )
		{
			*app = OS_GET_APP(OS_taskTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	case OS_OBJ_ISR:
		if ( id < OS_nInterrupts )
		{
			*app = OS_GET_APP(OS_isrTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	case OS_OBJ_RESOURCE:
		if ( id < OS_nResources )
		{
			*app = OS_GET_APP(OS_resourceTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	case OS_OBJ_COUNTER:
		if ( id < OS_nCounters )
		{
			*app = OS_GET_APP(OS_counterTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	case OS_OBJ_ALARM:
		if ( id < OS_nAlarms )
		{
			*app = OS_GET_APP(OS_alarmTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	case OS_OBJ_SCHEDULETABLE:
		if ( id < OS_nSchedules )
		{
			*app = OS_GET_APP(OS_scheduleTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	case OS_OBJ_TRUSTEDFUNCTION:
		if ( id < OS_nFunctions )
		{
			*app = OS_GET_APP(OS_functionTableBase[id].app);
			ret = OS_TRUE;
		}
		break;

	default:
		ret = OS_TRUE;				/* Avoid reporting "InvalidObjectId" */
		if ( OS_ErrorHandlingForVoidApi() )
		{
			/* can't propagate the return value of OS_ERROR -> ignore it */
			/* Possible diagnostic TOOLDIAG-1 <+1> */
			(void) OS_ERROR(OS_ERROR_InvalidObjectType, p);
		}
		break;
	}

	return ret;
}

/*!
 * OS_KernCheckObjectOwnership implements the API CheckObjectOwnership
 *
 * !LINKSTO Kernel.Autosar.OsApplication.QueryObject, 1
 * !LINKSTO Kernel.Autosar.API.SystemServices.CheckObjectOwnership, 2
 *
 * There is no permission check here ...
 * !LINKSTO Kernel.Autosar.OsApplication.Permissions.Exceptions, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_applicationid_t OS_KernCheckObjectOwnership
(	os_objecttype_t typ,
	os_objectid_t id
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_boolean_t idValid;
	os_applicationid_t a = OS_NULLAPP;
	const os_appcontext_t *app = OS_NULL;
	OS_PARAMETERACCESS_DECL

	OS_SAVE_PARAMETER_N(0,(os_paramtype_t)typ);
	OS_SAVE_PARAMETER_N(1,(os_paramtype_t)id);

	OS_TRACE_CHECKOBJECTOWNERSHIP_ENTRY(typ,id);

	if ( !OS_CallingContextCheck() )
	{
		if ( OS_ErrorHandlingForVoidApi() )
		{
			/* can't propagate the return value of OS_ERROR -> ignore it */
			/* Possible diagnostic TOOLDIAG-1 <+1> */
			(void) OS_ERROR(OS_ERROR_WrongContext, OS_GET_PARAMETER_VAR());
		}
	}
	else
	if ( !OS_InterruptEnableCheck(OS_IEC_AUTOSAR) )
	{
		if ( OS_ErrorHandlingForVoidApi() )
		{
			/* can't propagate the return value of OS_ERROR -> ignore it */
			/* Possible diagnostic TOOLDIAG-1 <+1> */
			(void) OS_ERROR(OS_ERROR_InterruptDisabled, OS_GET_PARAMETER_VAR());
		}
	}
	else
	{
		idValid = OS_FALSE;

		if ( typ == OS_OBJ_APPLICATION )
		{
			if ( OS_IsValidApplicationId(id) )
			{
				a = (os_applicationid_t)id;
				idValid = OS_TRUE;
			}
		}
		else
		{
			idValid = OS_GetOwningAppForObject(typ, id, &app, OS_GET_PARAMETER_VAR());
		}

		if ( idValid )
		{
			if ( !OS_AppIsNull(app) )
			{
				/* SYSTEM-Applications are an EB concept so we do not report them as object owners */
				if ( OS_AppIsSystemApp(app) )
				{
					a = OS_NULLAPP;
				}
				else
				{
					a = app->appId;
				}
			}
		}
		else
		{
			if ( OS_ErrorHandlingForVoidApi() )
			{
				/* can't propagate the return value of OS_ERROR -> ignore it */
				/* Possible diagnostic TOOLDIAG-1 <+1> */
				(void) OS_ERROR(OS_ERROR_InvalidObjectId, OS_GET_PARAMETER_VAR());
			}
		}
	}

	OS_TRACE_CHECKOBJECTOWNERSHIP_EXIT_P(a,typ,id);
	return a;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_checkobjectownership_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
