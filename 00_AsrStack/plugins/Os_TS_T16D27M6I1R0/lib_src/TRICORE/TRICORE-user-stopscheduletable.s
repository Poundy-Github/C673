/* TRICORE-user-stopscheduletable.s
 *
 * This file contains the system function OS_UserStopScheduleTable()
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
	_GLOBAL	OS_UserStopScheduleTable
	_GTYPE(OS_UserStopScheduleTable,@function)
	_GLOBAL	__callee.OS_UserStopScheduleTable.da.i.i
	_GTYPE(__callee.OS_UserStopScheduleTable.da.i.i,@function)

/*!
 *	OS_UserStopScheduleTable()
 *
 *	This routine makes the system call to OS_SC_StopScheduleTable
*/

_TTYPE(OS_UserStopScheduleTable,FUNC)
_TTYPE(__callee.OS_UserStopScheduleTable.da.i.i,FUNC)

	syscall	_IMM(#,OS_SC_StopScheduleTable)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
