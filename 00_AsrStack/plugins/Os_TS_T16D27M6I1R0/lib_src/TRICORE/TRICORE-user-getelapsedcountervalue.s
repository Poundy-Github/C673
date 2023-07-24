/* TRICORE-user-getelapsedcountervalue.s
 *
 * This file contains the system function OS_UserGetElapsedCounterValue()
 * Generated by the makesc.pl script
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
*/
#ifndef OS_ASM
#define OS_ASM
#endif

#include <Os_asm_common.h>
#if (OS_KERNEL_TYPE == OS_SYSTEM_CALL)

#include <Os_tool.h>
#include <Os_syscalls.h>

	_TEXT
	_GLOBAL	OS_UserGetElapsedCounterValue
	_GTYPE(OS_UserGetElapsedCounterValue,@function)
	_GLOBAL	__callee.OS_UserGetElapsedCounterValue.da.i.ipp
	_GTYPE(__callee.OS_UserGetElapsedCounterValue.da.i.ipp,@function)

/*!
 *	OS_UserGetElapsedCounterValue()
 *
 *	This routine makes the system call to OS_SC_GetElapsedCounterValue
*/

_TTYPE(OS_UserGetElapsedCounterValue,FUNC)
_TTYPE(__callee.OS_UserGetElapsedCounterValue.da.i.ipp,FUNC)

	syscall	_IMM(#,OS_SC_GetElapsedCounterValue)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/