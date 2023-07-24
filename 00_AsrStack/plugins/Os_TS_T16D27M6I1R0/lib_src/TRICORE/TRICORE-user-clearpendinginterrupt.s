/* TRICORE-user-clearpendinginterrupt.s
 *
 * This file contains the system function OS_UserClearPendingInterrupt()
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
	_GLOBAL	OS_UserClearPendingInterrupt
	_GTYPE(OS_UserClearPendingInterrupt,@function)
	_GLOBAL	__callee.OS_UserClearPendingInterrupt.da.i.i
	_GTYPE(__callee.OS_UserClearPendingInterrupt.da.i.i,@function)

/*!
 *	OS_UserClearPendingInterrupt()
 *
 *	This routine makes the system call to OS_SC_ClearPendingInterrupt
*/

_TTYPE(OS_UserClearPendingInterrupt,FUNC)
_TTYPE(__callee.OS_UserClearPendingInterrupt.da.i.i,FUNC)

	syscall	_IMM(#,OS_SC_ClearPendingInterrupt)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
