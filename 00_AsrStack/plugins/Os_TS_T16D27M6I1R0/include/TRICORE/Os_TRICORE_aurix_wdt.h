/* Os_TRICORE_aurix_wdt.h - Tricore Aurix watchdog registers
 *
 * This file contains a representation of the watchdog modules on
 * Aurix-family processors.
 * There is typically a safety watchdog and one CPU watchdog for each CPU.
 * Each watchdog is controlled by three registers that fortunately are located
 * at consecutive addresses in the address space.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_TRICORE_aurix_wdt.h 33382 2021-03-03 08:00:10Z arla271030 $
*/
#ifndef OS_TRICORE_AURIX_WDT_H
#define OS_TRICORE_AURIX_WDT_H

#include <Os_types.h>
#include <TRICORE/Os_defs_TRICORE.h>
#include <TRICORE/Os_TRICORE_cpu.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(OS_ASM)

#if (OS_TRICOREARCH == OS_TRICOREARCH_18)
typedef struct os_tricore_aurix_wdt_s
{
	os_reg32_t		wdt_unused1[9];		/* 0x0  not used be the OS */
	os_reg32_t		wdt_con[2];			/* 0x24 WDTxxxCON0 and WDTxxxCON1 */
	os_reg32_t		wdt_sr;				/* 0x2C WDTxxxSR Status */
} os_tricore_aurix_wdt_t;
#else
typedef struct os_tricore_aurix_wdt_s
{
	os_reg32_t		wdt_con[2];		/* WDTxxxCON0 and WDTxxxCON1 */
	os_reg32_t		wdt_sr;			/* WDTxxxSR Status */
} os_tricore_aurix_wdt_t;
#endif /* OS_TRICOREARCH */

#endif /* !defined(OS_ASM) */


/* Bit fields in the WDT registers (only those that are used in the OS).
 * For a full description please refer to the Infineon documentation.
*/
#define OS_WDT_REL		0xffff0000u	/* WDTxCON0.REL */
#if (OS_TRICOREARCH == OS_TRICOREARCH_18)
#define OS_WDT_PW		0x0000fffeu	/* WDTxCON0.PW */
#define OS_WDT_PW_INV	0x000000feu	/* WDTxCON0.PW (inverted portion) */
#define OS_WDT_PW_LSB	0x00000002u	/* WDTxCON0.PW (lsb) */
#define OS_WDT_LCK		0x00000001u	/* WDTxCON0.LCK */
#else /* OS_TRICOREARCH */
#define OS_WDT_PW		0x0000fffcu	/* WDTxCON0.PW */
#define OS_WDT_PW_INV	0x000000fcu	/* WDTxCON0.PW (inverted portion) */
#define OS_WDT_PW_LSB	0x00000004u	/* WDTxCON0.PW (lsb) */
#define OS_WDT_LCK		0x00000002u	/* WDTxCON0.LCK */
#endif /* OS_TRICOREARCH */
#define OS_ENDINIT		0x00000001u	/* WDTxCON0.ENDINIT */

#define OS_WDT_PAS		0x00000080u	/* WDTxSR.PAS */
#define OS_WDT_TCS		0x00000100u	/* WDTxSR.TCS */


/* The time taken for the computation of the final password from the WDTxSR TIM field.
 * Let's take a guess: 1 tick should be enough.
*/
#define OS_WDT_TIMEGUESS	0x00010000u	/* Estimated time for password computation */


#if (OS_TRICOREARCH != OS_TRICOREARCH_18)
#if !defined(OS_ASM)

/* OS_WriteSafetyEndinit() sets the Safety ENDINIT bit to the desired value.
*/
void OS_WriteSafetyEndinit(os_uint32_t);

#endif /* !defined(OS_ASM) */
#endif /* OS_TRICOREARCH != OS_TRICOREARCH_18 */

#ifdef __cplusplus
}
#endif

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
