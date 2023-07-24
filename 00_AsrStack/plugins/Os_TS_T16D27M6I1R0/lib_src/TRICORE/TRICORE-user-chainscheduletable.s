/* TRICORE-user-chainscheduletable.s
 *
 * This file contains the system function OS_UserChainScheduleTable()
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
	_GLOBAL	OS_UserChainScheduleTable
	_GTYPE(OS_UserChainScheduleTable,@function)
	_GLOBAL	__callee.OS_UserChainScheduleTable.da.i.ii
	_GTYPE(__callee.OS_UserChainScheduleTable.da.i.ii,@function)

/*!
 *	OS_UserChainScheduleTable()
 *
 *	This routine makes the system call to OS_SC_ChainScheduleTable
*/

_TTYPE(OS_UserChainScheduleTable,FUNC)
_TTYPE(__callee.OS_UserChainScheduleTable.da.i.ii,FUNC)

	syscall	_IMM(#,OS_SC_ChainScheduleTable)
	ret

#endif /* (OS_KERNEL_TYPE == OS_SYSTEM_CALL) */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/