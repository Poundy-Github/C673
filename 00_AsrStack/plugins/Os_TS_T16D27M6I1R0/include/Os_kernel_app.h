/* Os_kernel_app.h
 *
 * Kernel data structures - architecture-independent. For OS-application management
 *
 * This file is only eve included in Os_kernel.h, therefore it does not include
 * the header files that it needs. Including this file directly into
 * a source file will result in error messages, so DON'T DO IT!
 *
 * The reason for all this is to work around a stupid MISRA rule.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_kernel_app.h 30064 2019-04-01 03:01:24Z sash270423 $
 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.7 (required)
 * Expressions resulting from the expansion of macro parameters shall be
 * enclosed in parentheses.
 *
 * Reason:
 * Macro parameter is used in a way that doesn't allow the use of parentheses,
 * e.g. for designating struct members or initializers.
 */

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: DuplicatedIfCondition
 *   Duplicated 'if' condition regarding OS_IS_WITHIN_APP_REGION().
 *
 * Reason:
 *   In case of function call kernels or architectures with no support for
 *   memory protection the use of the macro OS_IS_WITHIN_APP_REGION may
 *   provoke duplicated 'if' conditions, when used in combination with similar
 *   macros (e.g., OS_IS_WITHIN_TASK_REGION) in a if-else cascade. This doesn't
 *   pose a problem, because this warning appears only in common-code owing to
 *   the goal of covering all cases, and hence is intentional.
 */

#ifndef OS_KERNEL_APP_H
#define OS_KERNEL_APP_H

#include <Os_defs.h>

/* Application flags
 */
#define OS_APP_TRUSTED			OS_U(0x01)		/* Application is trusted */

/*!
 * os_permission_t
 *
 * Application access permissions - only if not already defined
 */
#ifndef OS_ARCH_PERMISSION_T
#ifndef OS_ASM
typedef os_uint32_t os_permission_t;
#endif
#define OS_SIZEOF_PERMISSION	4
#endif

/*!
 * os_entry_t
 *
 * This data type is used for task and ISR entry and return addresses
 */
#ifndef OS_ASM
typedef void (*os_entry_t)(void);
#endif

/*!
 * os_startuphook_t, os_pretaskhook_t, os_posttaskhook_t,
 * os_preisrhook_t, os_postisrhook_t, os_errorhook_t, os_shutdownhook_t, os_protectionhook_t
 *
 * These data types are for pointers to hook functions. They are used for the global hook functions
 * and for the application-specific hooks.
 */
#ifndef OS_ASM
typedef void (*os_startuphook_t)(void);
typedef void (*os_pretaskhook_t)(void);
typedef void (*os_posttaskhook_t)(void);

typedef void (*os_preisrhook_t)(os_isrid_t);
typedef void (*os_postisrhook_t)(os_isrid_t);
typedef void (*os_errorhook_t)(os_result_t);
typedef void (*os_shutdownhook_t)(os_result_t);

typedef os_erroraction_t (*os_protectionhook_t)(os_result_t);
#endif

/*!
 * os_appcontext_s
 *
 * This is the data structure for the application context generated by the
 * generator. It defines exactly what environment application tasks and ISRs
 * must run in.
 *
 * An application's data/bss section is separate from the rest of the
 * system's data and bss. It must therefore be initialised separately.
 * This will be done during StartOS, which means that an application
 * cannot use its data section before that time, but has the advantage
 * that we can offer a feature to restart a (non-trusted) application
 * later if required.
 * Each application has its combined data/bss section at a specific
 * location specified by dataStart. The end of this section (actually,
 * the address of the next location AFTER the section) is in dataEnd.
 * The location of the initialisation data for the data section is at
 * idataStart, and its limit (one after, as above) is in idataEnd.
 * The initialisation code must therefore copy bytes from idataStart to
 * dataStart until idataEnd is reached (strictly less than), and then
 * zero-fill the remainder up to but not including dataEnd.
 */

#if OS_HAVE_ARCHAPP_T
/* Deviation MISRAC2012-1 */
#define OS_AppCfg_arch_decl(x)		x;
#else
#define OS_AppCfg_arch_decl(x)
#endif

#if (OS_KERNEL_TYPE==OS_SYSTEM_CALL) && (OS_HASMEMPROT == 1)
#define OS_APP_DATA_START					((os_address_t)app->dataStart)
#define OS_APP_DATA_END						((os_address_t)app->dataEnd)
#define OS_IS_WITHIN_APP_REGION(first,last)	(((first) >= OS_APP_DATA_START) && ((last) <= OS_APP_DATA_END))
#else
/* Deactivating application data region check for a non system call kernel */
#define OS_APP_DATA_START					OS_U(0)
#define OS_APP_DATA_END						OS_U(0)
/* Possible diagnostic TOOLDIAG-1 <1> */
#define OS_IS_WITHIN_APP_REGION(first,last)	((last) == OS_APP_DATA_END)
#endif

/* Multicore configuration (needless to override in Os_optimize.h) */
#if (OS_N_CORES == 1)
#define OS_Cfg_multicore_decl(x)
#define OS_Cfg_multicore_init(x)
#else	/* OS_N_CORES != 1 */
/* Deviation MISRAC2012-1 */
#define OS_Cfg_multicore_decl(x) x;
#define OS_Cfg_multicore_init(x) (x),
#endif	/* OS_N_CORES == 1 */

#ifndef OS_ASM

/*!
 * os_appdynamic_t
 *
 * There is no architecture-independent app-dynamic at the moment, so we only define the
 * data types if the architecture has some dynamic app data.
 */
typedef struct os_appdynamic_s os_appdynamic_t;

struct os_appdynamic_s
{
#ifdef OS_ARCH_HAS_APPDYNAMIC
	os_archappdynamic_t arch;
#endif

	/* The current state of an application, which is one of the OS_APP_* constants. */
	os_appstate_t appstate;
};

/*!
 * os_appcontext_t
 *
 */
typedef struct os_appcontext_s os_appcontext_t;

struct os_appcontext_s
{
	const os_uint32_t *buildId;					/* App's build ID (in app-gen.c) */
	os_startuphook_t startupHook;				/* App's own startup hook */
	os_shutdownhook_t shutdownHook;				/* App's own shutdown hook */
	os_errorhook_t errorHook;					/* App's own error hook */
	/* Deviation MISRAC2012-1 <4> */
	OS_Cfg_mp_decl(os_uint8_t *dataStart)		/* Application's data/bss segment */
	OS_Cfg_mp_decl(os_uint8_t *dataEnd)			/* Application's data/bss segment */
	OS_Cfg_mp_decl(os_uint8_t const *idataStart)	/* For initialisation of data */
	OS_Cfg_mp_decl(os_uint8_t const *idataEnd)		/* For initialisation of data */

	/* The permission bit is used to determine access to an OS object. This could be *another* OS application,
	 * an alarm, a counter, etc.
	 * Exactly one bit in this mask is set, unless this is a SYSTEM application, in which case all bits are set.
	 * Each OS application uses a different bit to identify itself.
	 * Whether an OS application is granted or refused access to an OS object is determined by OS_HasPermission().
	 */
	os_permission_t permissionBit;

	/* Contains a set of bits designating all other OS applications, which are thereby granted access to this
	 * application. This set is a superposition of 'permissionBit' of all those OS applications. See also
	 * OS_HasPermission().
	 */
	os_permission_t permissions;

	os_stacklen_t startupHookStack;				/* Stack required for startup hook */
	os_stacklen_t shutdownHookStack;			/* Stack required for shutdown hook */
	os_stacklen_t errorHookStack;				/* Stack required for error hook */
	os_taskid_t restartTask;					/* Specified restart task */
	os_uint8_t flags;							/* Flags (see below) */
	os_applicationid_t appId;					/* Id of this app */
	os_appdynamic_t *dynamic;					/* Points to the dynamic part of an application. */
	/* Deviation MISRAC2012-1 <2> */
	OS_Cfg_multicore_decl(os_coreid_t core)		/* Core on which this application runs */
	OS_AppCfg_arch_decl(os_archapp_t archapp)	/* Architecture-specific */
};

/* Deviation MISRAC2012-1 <START> */
#define OS_APPCONFIG_INIT( id, startupHook, shutdownHook, errorHook,			\
			dataStart, dataEnd, idataStart, idataEnd, permissionBit, permissions,\
			startupHookStack, shutdownHookStack, errorHookStack,				\
			restartTask, flags, appId, dyn, core, archapp )						\
	{																			\
		id,																		\
		startupHook,															\
		shutdownHook,															\
		errorHook,																\
		OS_Cfg_mp_init(dataStart)												\
		OS_Cfg_mp_init(dataEnd)													\
		OS_Cfg_mp_init(idataStart)												\
		OS_Cfg_mp_init(idataEnd)												\
		permissionBit,															\
		permissions,															\
		startupHookStack,														\
		shutdownHookStack,														\
		errorHookStack,															\
		restartTask,															\
		flags,																	\
		appId,																	\
		dyn,																	\
		OS_Cfg_multicore_init(core)												\
		archapp																	\
	}
/* Deviation MISRAC2012-1 <STOP> */

extern const os_applicationid_t OS_nApps;
extern const os_appcontext_t * const OS_appTableBase;

#endif /* OS_ASM */

/*!
 * Application accessibility check.
 */
#ifndef OS_APPISACCESSIBLE
#define OS_APPISACCESSIBLE(app)		OS_AppIsAccessible(app)
#endif

#ifndef OS_ASM
extern os_boolean_t OS_AppIsAccessible(const os_appcontext_t *);
#endif

/*!
 * Application flags
 */
#define OS_APP_TRUSTED	OS_U(0x01)		/* Application is trusted */
#define OS_APP_SYSTEM	OS_U(0x02)		/* Application is system application */

/*!
 * OS_CurrentApp()
 *
 * Returns pointer to current application's data structure, or OS_NULL
 *
 * If in a task: OS_GetKernelData()->taskCurrent->app
 * If in a cat2 ISR: OS_isrTableBase[OS_isrCurrent].app
 * If in a hook: hookApp
 * Otherwise: OS_NULL
 */
#ifndef OS_CurrentApp
#define OS_CurrentApp()	\
	( (os_appcontext_t const *) ( (OS_GetKernelData()->inFunction == OS_INTASK)\
       ? (OS_GetKernelData()->taskCurrent->app)								\
       : ( OS_IS_INCAT2(OS_GetKernelData()->inFunction)						\
           ? (OS_isrTableBase[OS_GetKernelData()->isrCurrent].app)			\
		   : ( ( OS_IS_INERRORHOOK(OS_GetKernelData()->inFunction) ||		\
			     OS_IS_INSTARTUPHOOK(OS_GetKernelData()->inFunction) ||		\
				 OS_IS_INSHUTDOWNHOOK(OS_GetKernelData()->inFunction) )		\
			   ? OS_GetKernelData()->hookApp								\
			   : OS_NULL ) ) ) )
#endif

#ifndef OS_AppIsNull
#define OS_AppIsNull(a)		( (a) == OS_NULL )
#endif

#define OS_AppIsSystemApp(a)	( ((a)->flags & OS_APP_SYSTEM) != 0U )

/*!
 * OS_IsValidApplicationId
 *
 * Checks if a given OS application ID is valid.
 */
#define OS_IsValidApplicationId(a)		OS_DoExtendedStatusTrue((a) < OS_nApps)

/*!
 * OS_HasPermission(app, perm)
 *  app   - address of application in appTable, or OS_NULL.
 *  perms - permission bits for object being accessed.
 *
 * Permission is granted if
 *  - app is OS_NULL (system access or no applications (OSEK,SC1/2), or
 *  - app's permission bit is set in permissions word.
 * Note, that trusted OS applications have no special rights to bypass these checks. They must also be explicitly
 * granted the right otherwise access is refused in this case, too. See also [OS448] in AUTOSAR_SWS_OS V5.0.0 part
 * of AUTOSAR R4.0 Rev 3.
 *
 * !LINKSTO Kernel.Autosar.ServiceErrors.AccessRights, 1
 * !LINKSTO Kernel.Autosar.ServiceErrors.AccessRights.Check, 2
 *  (see individual services and the error database)
 *
 * The trusted/nontrusted status of the application is no longer checked, so all applications need to
 * be given their rights explicitly. However, (app == OS_NULL) is retained for "system" objects.
 * !LINKSTO Kernel.Autosar.OsApplication.Permissions, 1
 */
#if (!defined(OS_HasPermission)) && (!defined(OS_QUARANTINEAPPLICATION)) && (!defined(OS_RESTARTAPPLICATION))

#define OS_HasPermission(app, perms)	( OS_AppIsNull((app)) || (((app)->permissionBit & (perms)) != 0U) )

/* Internal kernel functions
*/
#ifndef OS_ASM
extern void OS_QuarantineApplication(const os_appcontext_t *);
extern void OS_RestartApplication(const os_appcontext_t *);
extern os_errorresult_t OS_LocalTerminateApplication(const os_appcontext_t *, os_restart_t);
extern os_applicationid_t OS_DoGetApplicationId(void);
extern os_applicationid_t OS_DoGetCurrentApplicationId(void);

#if (OS_N_CORES == 1)
#define OS_DoTerminateApplication(appid, app, restart)  OS_LocalTerminateApplication((app), (restart))
#else /* OS_N_CORES */
#define OS_DoTerminateApplication(appid, app, restart)  OS_MultiTerminateApplication((appid), (app), (restart))
extern os_errorresult_t OS_MultiTerminateApplication(os_applicationid_t, const os_appcontext_t *, os_restart_t);
#endif /* OS_N_CORES */
#endif /* OS_ASM */

#define OS_QUARANTINEAPPLICATION(app)			OS_QuarantineApplication(app)
#define OS_RESTARTAPPLICATION(app)				OS_RestartApplication(app)

#endif /* (!defined(OS_HasPermission)) && (!defined(OS_QUARANTINEAPPLICATION)) && (!defined(OS_RESTARTAPPLICATION)) */

/* OS_APPGETSUHOOKPROTSTACKSIZE(const os_appcontext_t *app)
 * Return the memory protection size of the applications specific startup
 * hook.
 *
 * This is the default implementation, it may get overridden by CPU-family
 * headers.
*/
#ifndef OS_APPGETSUHOOKPROTSTACKSIZE
#define OS_APPGETSUHOOKPROTSTACKSIZE(app)	((app)->startupHookStack)
#endif

/* OS_APPGETSDHOOKPROTSTACKSIZE(const os_appcontext_t *app)
 * Return the memory protection size of the applications specific shutdown
 * hook.
 *
 * This is the default implementation, it may get overridden by CPU-family
 * headers.
*/
#ifndef OS_APPGETSDHOOKPROTSTACKSIZE
#define OS_APPGETSDHOOKPROTSTACKSIZE(app)	((app)->shutdownHookStack)
#endif

/* OS_ARCHSETHOOKPROTECTION(app, context, stack)
 * Set the memory protection for the startup/shutdown hook.
 *
 * app: Application context of the hook.
 * context: hook context
 * stack: Memory protection size of the application specific shutdown
 *        or startup hook.
 *
 * This is the default implementation, it may get overridden by CPU-family
 * headers.
*/
#ifndef OS_ARCHSETHOOKPROTECTION
#define OS_ARCHSETHOOKPROTECTION(app, context, stack) \
	OS_SETHOOKPROTECTION((app), (context), (stack))
#endif

#endif /* OS_KERNEL_APP_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
 */
