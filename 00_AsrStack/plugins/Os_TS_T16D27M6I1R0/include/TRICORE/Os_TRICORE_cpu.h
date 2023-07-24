/* Os_TRICORE_cpu.h - Tricore CPU header file
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_TRICORE_cpu.h 34521 2021-07-15 08:08:43Z dypa272654 $
*/

#ifndef OS_TRICORE_CPU_H
#define OS_TRICORE_CPU_H

#include <Os_defs.h>
#include <TRICORE/Os_defs_TRICORE.h>

/* Include the appropriate header file for the derivative.
*/
#if (OS_CPU == OS_TC1798)
#include <TRICORE/TC1798/Os_tc1798.h>
#elif (OS_CPU == OS_TC1791)
#include <TRICORE/TC1791/Os_tc1791.h>
#elif (OS_CPU == OS_TC1793)
#include <TRICORE/TC1793/Os_tc1793.h>
#elif (OS_CPU == OS_TC27XT)
#include <TRICORE/TC27XT/Os_tc27xt.h>
#elif (OS_CPU == OS_TC23XL)
#include <TRICORE/TC23XL/Os_tc23xl.h>
#elif (OS_CPU == OS_TC22XL)
#include <TRICORE/TC22XL/Os_tc22xl.h>
#elif (OS_CPU == OS_TC29XT)
#include <TRICORE/TC29XT/Os_tc29xt.h>
#elif (OS_CPU == OS_TC39XX)
#include <TRICORE/TC39XX/Os_tc39xx.h>
#elif (OS_CPU == OS_TC38XQ)
#include <TRICORE/TC38XQ/Os_tc38xq.h>
#elif (OS_CPU == OS_TC37XT)
#include <TRICORE/TC37XT/Os_tc37xt.h>
#elif (OS_CPU == OS_TC36XD)
#include <TRICORE/TC36XD/Os_tc36xd.h>
#elif (OS_CPU == OS_TC33XL)
#include <TRICORE/TC33XL/Os_tc33xl.h>
#elif (OS_CPU == OS_TC49XXVDK)
#include <TRICORE/TC49XXVDK/Os_tc49xxvdk.h>
#elif (OS_CPU == OS_TC32XL)
#include <TRICORE/TC32XL/Os_tc32xl.h>
#else
#error "OS_CPU is not properly defined. Check your makefiles!"
#endif

/* The actual implementation of OS_GetMyCoreId reads CSFR CORE_ID,
 * that is comparable to reading a constant.
*/
#ifdef EB_STATIC_CHECK
#define OS_GetMyCoreId()			((os_coreid_t)0)
#endif

/* Fallbacks if a specific derivative doesn't set an expected macro */

/* Fallback for start adress of physical address space */
#ifndef OS_PHYS_ADDR_SPACE_START
#define OS_PHYS_ADDR_SPACE_START	OS_U(0x80000000)
#endif

#if (OS_N_CORES_MAX > 1)

/* Proactively clear the interrupt-disable flag in case shutdown is called from
 * an exception handler.
*/
#define OS_IntEnableXcoreFromShutdown()		\
	do {									\
		(void) OS_IntEnableXcore();			\
		OS_ENABLE();						\
	} while(0)

#endif

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
