/* Mk_qmboard.h - QM-OS header for RCARM3N
 *
 * This file contains definitions which are used during early startup, for the
 * application demo and for interoperation between microkernel and QM-OS.
 *
 * (c) Elektrobit Automotive Software
 *
 * $Id: Mk_qmboard.h 35961 2019-03-15 12:07:49Z sesc270012 $
*/
#ifndef MK_QMBOARD_H
#define MK_QMBOARD_H

#include <Mk_board.h>
#include <MicroOs.h>
#include <public/Mk_timeconversion64.h>

/*!
 * OS_BoardGptimerNsToTicks() and OS_BoardGptimerTicksToNs() for the GPTIMER counters
 *
 * OS_BoardGptimerNsToTicks() converts nanoseconds (ns) to ticks.
 *
 * OS_BoardGptimerTicksToNs converts ticks to nanoseconds.
 *
 * The timer frequency can be read from CNTFRQ_EL0. This
 * register is a per core register and should be initialized
 * for all cores. This is not the case for the RCARM3N. Only
 * Core 0 of Cortex-A57 has a initialized register. Therefore
 * we use this value as a fixed one.
 *
 * The HW describes the frequency with EXTAL/2 = 16.666 MHz/2 = 8.333 MHz
 *
 * 8.333 MHz (120ns per tick)
 */
#define OS_BoardGptimerNsToTicks(ns)		MK_NsToTicks_8333333((ns))
#define OS_BoardGptimerTicksToNs(ticks)		MK_TicksToNs_8333333((ticks))

#ifndef MK_TS5_TEST
#include <ARM64/Os_ARM64_timer_gptimer_config.h>
#endif

/*
 * Macros to convert tick to nano seconds and vice versa
 * for the TMU Timer 0 (TMU00 and TMU01).
 *
 * Clock = CP = EXTAL * 1/2 (EXTAL = 16.666MHz) = 8.333 MHz
 *
 * Timer Unit input frequency = CP/4 = 2.083 Mhz
 */
#define OS_BoardTmu0NsToTicks(ns)		MK_NsToTicks_2083333((ns))
#define OS_BoardTmu0TicksToNs(ticks)	MK_TicksToNs_2083333((ticks))

/*
 * Macros to convert tick to nano seconds and vice versa
 * for the TMU Timer 1-4 (TMU10 to TMU41).
 * 
 * Clock = S3D2 = 133 1/3 MHz
 *
 * Timer Unit input frequency = S3D2/4 = 33 1/3 Mhz
 */
#define OS_BoardTmu1NsToTicks(ns)		MK_NsToTicks_33333333((ns))
#define OS_BoardTmu1TicksToNs(ticks)	MK_TicksToNs_33333333((ticks))

#define OS_BoardTmu2NsToTicks(ns)		OS_BoardTmu1NsToTicks((ns))
#define OS_BoardTmu3NsToTicks(ns)		OS_BoardTmu1NsToTicks((ns))
#define OS_BoardTmu4NsToTicks(ns)		OS_BoardTmu1NsToTicks((ns))	
#define OS_BoardTmu2TicksToNs(ticks)	OS_BoardTmu1TicksToNs((ticks))  
#define OS_BoardTmu3TicksToNs(ticks)	OS_BoardTmu1TicksToNs((ticks)) 
#define OS_BoardTmu4TicksToNs(ticks)	OS_BoardTmu1TicksToNs((ticks)) 

#ifndef MK_TS5_TEST
#include <ARM64/Os_ARM64_timer_tmu_config.h>
#endif

/* I/O-port definitions for user led */
#define BOARD_REG_32(a)	(*((os_reg32_t*)(a)))
#define BOARD_INOUTSEL6	BOARD_REG_32(0xe6055404u)
#define BOARD_OUTDT6	BOARD_REG_32(0xe6055408u)

#define BOARD_LED4_STATE	(1u << 11u)
#define BOARD_LED5_STATE	(1u << 12u)
#define BOARD_LED6_STATE	(1u << 13u)

#define BOARD_LED4_DIR	(1u << 11u)
#define BOARD_LED5_DIR	(1u << 12u)
#define BOARD_LED6_DIR	(1u << 13u)

#define BOARD_LED4_6_MASK	0x07u
#define BOARD_LED4_6_SHIFT	11u

#define LEDS_INIT()																\
do {																			\
	BOARD_OUTDT6 &= ~(BOARD_LED4_STATE | BOARD_LED5_STATE | BOARD_LED6_STATE);	\
	BOARD_INOUTSEL6 = BOARD_LED4_DIR | BOARD_LED5_DIR | BOARD_LED6_DIR;			\
} while (0)

#define LEDS_SET(x)													\
do {																\
	BOARD_OUTDT6 = ((x) & BOARD_LED4_6_MASK) << BOARD_LED4_6_SHIFT;\
} while (0)

#ifndef MK_ASM

/* This macro contains an endless loop that attempts to avoid a compiler warning on endless loops.
*/
#define TMPL_ENDLESSLOOP() \
	do \
	{ \
		mk_uint32_t confusion; \
		for(confusion=0u; confusion!=1u; confusion^=2u) \
		{ \
			/* Compiler hopefully does not recognize this as an endless loop */ \
		} \
	} while(0)

#endif /* MK_ASM */

#endif /* MK_QMBOARD_H */
