/* board_tool_diab.c
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board_tool_diab.c 29552 2018-11-29 08:53:43Z sash270423 $
*/

#include <Os_defs.h>

#if (OS_TOOL == OS_diab)

#include <Os_cpu.h>
#include <Os_tool.h>
#include <TRICORE/Os_TRICORE_stm.h>
#include <board_tool.h>

#ifndef OS_N_CORES_MAX
#error "This file needs to know the number of cores available."
#endif

#ifndef OS_TRICOREARCH
#error "This file needs to know the tricore architecture."
#endif

#define BOARD_DIAB_STACKPROT (__VERSION_NUMBER__ >= BOARD_TOOL_STACKPROT_MINVERSION)

#if (OS_TRICOREARCH == OS_TRICOREARCH_16EP)
/* On TC2 A0 and A1 usage is currently not supported by the linker script. */
#define BOARD_DIAB_A0A1 0
#else /* OS_TRICOREARCH */
#define BOARD_DIAB_A0A1 1
#endif /* OS_TRICOREARCH */

#if (BOARD_DIAB_STACKPROT)
/* Include integer types for Diab's stack protection (-Xstack-protection*). */
#define _ILONG              1   /* int is long */
#define _SIZE_T_LONG_LONG   0   /* size_t isn't long long */
#include <stdint.h>
#endif /* BOARD_DIAB_STACKPROT */

#if (BOARD_DIAB_STACKPROT)
/* If you switch on Diab's stack protection (-Xstack-protection*),
 * you have to define __stack_chk_guard and __stack_chk_fail.
 * Implement __stack_chk_fail with care, because it might be called in kernel context.
 *
 * Here is an example implementation:
*/
#if (BOARD_STACKPROTGUARD_IS_RODATA)

const uintptr_t __stack_chk_guard = 0xeb15c001u;
void BoardInitCompilerStackProtectionDiab(void) {
	/* Nothing to do. */
}

#else /* #if (BOARD_STACKPROTGUARD_IS_RODATA) */

uintptr_t __stack_chk_guard;

/* Note that security is not considered in AutoCore OS in any way.
 * The following pseudo-random numbers have insufficient entropy and are predictable.
*/
static os_uint32_t BoardPseudoRandHw(void)
{
	os_reg32_t *t = &(((os_tricorestm_t *)OS_STM0_BASE)->stm_tim0);
	return *t ^ (*t << 16);
}
static os_uint32_t BoardPseudoRand(void)
{
	os_uint32_t val, i, n;

	val = BoardPseudoRandHw();
	n = 42u + (BoardPseudoRandHw() & 0x7fu);
	for (i = 0u; i < n; i++) {
		val = (31u * val) + BoardPseudoRandHw();
	}
	return val;
}

BOARD_NO_STACKPROT_PREFIX
void BoardInitCompilerStackProtectionDiab(void)
{
	__stack_chk_guard = BoardPseudoRand();
}

#endif /* #if (BOARD_STACKPROTGUARD_IS_RODATA) */

/* __stack_chk_fail just goes to an endless loop waiting for a time-out.
 * It reads __stack_chk_guard to prevent linkers from merging its code with another endless loop,
 * so the __stack_chk_fail label gets a unique address, which is useful for debugging.
 * Typically all valid memory is readable from all contexts in AutoCore OS.
*/
__attribute__((noreturn)) void __stack_chk_fail(void)
{
	register const volatile uintptr_t *pguard0 = &__stack_chk_guard;
	register const volatile uintptr_t *pguard1 = &__stack_chk_guard;

	while ((*pguard0) == (*pguard1)) {
		/* wait here ... */
	}
	for (;;); /* make sure that this function really won't return. */
}
#else /* BOARD_DIAB_STACKPROT */
void BoardInitCompilerStackProtectionDiab(void) {
	/* Nothing to do. */
}
#endif /* BOARD_DIAB_STACKPROT */


/* Declare base for small constant area (-Xsmall-const). */
#if (BOARD_DIAB_A0A1)
extern const os_uint32_t _LITERAL_DATA_;
BOARD_LINKERSYMBOL_BSS(_SMALL_DATA_);
BOARD_LINKERSYMBOL_BSS(_SDA_BASE_);
BOARD_LINKERSYMBOL_BSS(__SDA_BASE_);
#endif
void BoardSetOtherCoresA0A1Diab(void) {
#if (BOARD_DIAB_A0A1)
	os_uint32_t coreId;
	os_uint32_t a0, a1;

	a0 = (os_uint32_t)&_SMALL_DATA_;
	a1 = (os_uint32_t)&_LITERAL_DATA_;

	/* Do some sanity checks concerning the linker script.
	 * This also makes sure that these symbols are references somewhere in code.
	*/
	while (a0 != (os_uint32_t)&_SDA_BASE_);
	while (a0 != (os_uint32_t)&__SDA_BASE_);

	/* We assume that this is core0. */
	for (coreId = 1; coreId < OS_N_CORES_MAX; coreId++)
	{
		os_uint32_t cfsrBase = OS_CPUCSFR(coreId);

		/* Initialize A0 to _SMALL_DATA_. */
		OS_MTCCR(cfsrBase, OS_A0, a0);

		/* Initialize A1 to _LITERAL_DATA_. */
		OS_MTCCR(cfsrBase, OS_A1, a1);
	}
#endif
}


#else /* OS_TOOL */
const char boardNoDiab = 'X';
#endif /* OS_TOOL */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
