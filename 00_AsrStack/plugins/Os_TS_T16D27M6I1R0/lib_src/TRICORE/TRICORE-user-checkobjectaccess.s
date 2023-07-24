/* TRICORE-user-checkobjectaccess.s
 *
 * This file contains the system function OS_UserCheckObjectAccess()
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
	_GLOBAL	OS_UserCheckObjectAccess
	_GTYPE(OS_UserCheckObjectAccess,@function)
	_GLOBAL	__callee.OS_UserCheckObjectAccess.da.i.iii
	_GTYPE(__callee.OS_UserCheckObjectAccess.da.i.iii,@function)

/*!
 *	OS_UserCheckObjectAccess()
 *
 *	This routine makes the system call to OS_SC_CheckObjectAccess
*/

_TTYPE(OS_UserCheckObjectAccess,FUNC)
_TTYPE(__callee.OS_UserCheckObjectAccess.da.i.iii,FUNC)

	syscall	_IMM(#,OS_SC_CheckObjectAccess)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
