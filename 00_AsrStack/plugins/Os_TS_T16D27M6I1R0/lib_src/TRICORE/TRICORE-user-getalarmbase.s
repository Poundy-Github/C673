/* TRICORE-user-getalarmbase.s
 *
 * This file contains the system function OS_UserGetAlarmBase()
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
	_GLOBAL	OS_UserGetAlarmBase
	_GTYPE(OS_UserGetAlarmBase,@function)
	_GLOBAL	__callee.OS_UserGetAlarmBase.da.i.ip
	_GTYPE(__callee.OS_UserGetAlarmBase.da.i.ip,@function)

/*!
 *	OS_UserGetAlarmBase()
 *
 *	This routine makes the system call to OS_SC_GetAlarmBase
*/

_TTYPE(OS_UserGetAlarmBase,FUNC)
_TTYPE(__callee.OS_UserGetAlarmBase.da.i.ip,FUNC)

	syscall	_IMM(#,OS_SC_GetAlarmBase)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
