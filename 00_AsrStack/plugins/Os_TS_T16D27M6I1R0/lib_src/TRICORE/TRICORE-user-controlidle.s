/* TRICORE-user-controlidle.s
 *
 * This file contains the system function OS_UserControlIdle()
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
	_GLOBAL	OS_UserControlIdle
	_GTYPE(OS_UserControlIdle,@function)
	_GLOBAL	__callee.OS_UserControlIdle.da.i.ii
	_GTYPE(__callee.OS_UserControlIdle.da.i.ii,@function)

/*!
 *	OS_UserControlIdle()
 *
 *	This routine makes the system call to OS_SC_ControlIdle
*/

_TTYPE(OS_UserControlIdle,FUNC)
_TTYPE(__callee.OS_UserControlIdle.da.i.ii,FUNC)

	syscall	_IMM(#,OS_SC_ControlIdle)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
