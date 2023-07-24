/* boardAsm.s
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: boardAsm.s 25632 2016-12-22 10:08:09Z mist9353 $
 */

#ifndef OS_ASM
#define OS_ASM
#endif

#include <board.h>

	_TEXT

	_EXTERN	OS_InitSp
	_EXTERN	OS_InitCsaList
	_EXTERN BoardStart
#if (OS_TOOL==OS_diab)
	_EXTERN _LITERAL_DATA_
	_EXTERN _SMALL_DATA_
#endif

	_GLOBAL	boardAsm_start
	_GLOBAL boot

#if (OS_TOOL==OS_tasking)
        .sdecl  "TMPL_Startup",code
        .sect   "TMPL_Startup"
#else
        .section    "TMPL_Startup","a"
#endif

boardAsm_start:
boot:
	disable

/* If all our symbols are mapped to cached addresses (0x8 segment), we won't see our
 * source code in the debugger because all symbols are in a different segment than
 * our start address. We fix this by jumping to the symbol in the respective segment.
*/
	movh.a	a15, _IMM(#,_hiword(_realaddr))
	lea		a15, [a15] _loword(_realaddr)
	ji		a15

_realaddr:

/* We need the PSW set up right! This might get changed later.
 */
	movh	d0,_IMM(#,_hiword(OS_INITIAL_PSW))
	addi	d0,d0,_IMM(#,_loword(OS_INITIAL_PSW))
	_mtcr	_IMM(#,OS_PSW),d0

#if (OS_TOOL==OS_diab)
	/* Unlock global registers. */
	or		d1, d0, _IMM(#,OS_PSW_GW)
	_mtcr	_IMM(#,OS_PSW),d1
	/* Setup global register A0 for diab's -Xsmall-data. */
	movh.a	a0, _IMM(#,_hiword(_SMALL_DATA_))
	lea		a0, [a0] _loword(_SMALL_DATA_)
	/* Setup global register A1 for diab's -Xsmall-const. */
	movh.a	a1, _IMM(#,_hiword(_LITERAL_DATA_))
	lea		a1, [a1] _loword(_LITERAL_DATA_)
	/* Lock global registers. */
	_mtcr	_IMM(#,OS_PSW),d0
#endif

/* Can't use CALL --- no CSAs!
 */
	jl		OS_InitSp
	jl		OS_InitCsaList

	j		BoardStart


/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
