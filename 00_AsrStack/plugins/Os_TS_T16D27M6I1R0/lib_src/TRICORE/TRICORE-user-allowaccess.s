/* TRICORE-user-allowaccess.s
 *
 * This file contains the system function OS_UserAllowAccess()
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
	_GLOBAL	OS_UserAllowAccess
	_GTYPE(OS_UserAllowAccess,@function)
	_GLOBAL	__callee.OS_UserAllowAccess.da.i.v
	_GTYPE(__callee.OS_UserAllowAccess.da.i.v,@function)

/*!
 *	OS_UserAllowAccess()
 *
 *	This routine makes the system call to OS_SC_AllowAccess
*/

_TTYPE(OS_UserAllowAccess,FUNC)
_TTYPE(__callee.OS_UserAllowAccess.da.i.v,FUNC)

	syscall	_IMM(#,OS_SC_AllowAccess)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
