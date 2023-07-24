/* $Id: board.h 33382 2021-03-03 08:00:10Z arla271030 $
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
*/

#ifndef BOARD_H
#define BOARD_H 1

#include <board_version_check.h>
#include <Os_timeconversion.h>
#include <TRICORE/Os_TRICORE_cpu.h>
#include <TRICORE/Os_tool_TRICORE.h>

/* The next few lines contain the initialization of the user LEDs on the board. */
/* 8 toggle LEDs connected to P33.4 ... P33.7 and P20.11 ... P20.14 defined in the board docu */
/* Addresses in the derivative docu */

#define BOARD_P20_BASE   0xf003b400U
#define BOARD_P33_BASE   0xf003c100U

#define BOARD_P20_OUT    OS_REG32(BOARD_P20_BASE+0x0U)
#define BOARD_P20_IOCR0  OS_REG32(BOARD_P20_BASE+0x10U)
#define BOARD_P20_IOCR4  OS_REG32(BOARD_P20_BASE+0x14U)
#define BOARD_P20_IOCR8  OS_REG32(BOARD_P20_BASE+0x18U)
#define BOARD_P20_IOCR12 OS_REG32(BOARD_P20_BASE+0x1cU)

#define BOARD_P33_OUT    OS_REG32(BOARD_P33_BASE+0x0U)
#define BOARD_P33_IOCR0  OS_REG32(BOARD_P33_BASE+0x10U)
#define BOARD_P33_IOCR4  OS_REG32(BOARD_P33_BASE+0x14U)
#define BOARD_P33_IOCR8  OS_REG32(BOARD_P33_BASE+0x18U)
#define BOARD_P33_IOCR12 OS_REG32(BOARD_P33_BASE+0x1cU)

#define	LEDS_SET(x)\
		do {\
			BOARD_P33_OUT = (BOARD_P33_OUT & ~0x00f0U) | (((~(x))&0x0fU) << 4U);\
			BOARD_P20_OUT = (BOARD_P20_OUT & ~0x7800U) | (((~(x))&0xf0U) << 7U);\
		}	while (0)

#define	LEDS_GET()  (((BOARD_P20_OUT>>7U) & 0xf0U) | ((BOARD_P33_OUT>>4U) & 0x0fU))

#define	LEDS_INIT()\
		do {\
			BOARD_P33_IOCR4  = 0x80808080u;\
			BOARD_P20_IOCR8  = 0x80101010u;\
			BOARD_P20_IOCR12 = 0x10808080u;\
		} while (0)

/* Select the desired SRI frequency from one of the available values
 *
 * The PLL must be programmed to achieve these frequencies.
 *
 * If any other frequency is required the correct PLL settings will need to be determined.
 * If you change the running frequency of the board, you must
 * also change the NsToTicks and TicksToNs macros below.
*/
#define BOARD_SYS_FREQ			200000000U			/* SRI clock [Hz] */
#define BOARD_CPU_FREQ_HZ		200000000			/* Just here for performance tests */

#if BOARD_SYS_FREQ <= 200000000U
#define BOARD_SPB_DIV  2u /* 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */
#define BOARD_FSI_DIV  2u /* 0 (stopped), 1, 2, 3; input fSRI*/
#define BOARD_GTM_DIV  2u /* 0 (stopped), 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */
#define BOARD_STM_DIV  2u /* 0 (stopped), 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */
#define BOARD_BBB_DIV  2u /* 0 (stopped), 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */

#else /* BOARD_SYS_FREQ <= 300 MHz */
#error "Please define clock divider macros for your chosen BOARD_SYS_FREQ"

#endif

/* By default the SCU clocks the STM modules with f_source/2, whereat f_sys is the PLL's output in
 * this configuration (see register CCUCON1 field STMDIV).
 * If the user changes this during startup, the following macro needs to be adapted.
 */
#define BOARD_Fstm_FREQ			((BOARD_SYS_FREQ)/BOARD_STM_DIV)

/* Maximum frequencies are defined in derivative's Data Sheet chpater 3.4 Operating Conditions */

#if (BOARD_SYS_FREQ) > 300000000u
#error "Maximum fPLL is 300 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_SPB_DIV) > 100000000u
#error "Maximum fSPB is 100 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_FSI_DIV) > 100000000u
#error "Maximum fFSI is 100 MHz"
#endif

#if BOARD_Fstm_FREQ > 100000000u
#error "Maximum fSTM is 100 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_GTM_DIV) > 200000000u
#error "Maximum fGTM is 200 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_BBB_DIV) > 150000000u
#error "Maximum fBBB is 150 MHz"
#endif

/*!
 * OS_BoardNsToTicks() and OS_BoardTicksToNs()
 *
 * OS_BoardNsToTicks() converts nanoseconds (nS) to ticks. This macro must
 * compute entirely in the preprocessor, because it is used to initialise time
 * tables.
 * The calculation for this board is ns * Fmod / 1000000000.
 *
*/
#if (BOARD_Fstm_FREQ == 90000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_90000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_90000000(tik)

#elif (BOARD_Fstm_FREQ == 75000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_75000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_75000000(tik)

#elif (BOARD_Fstm_FREQ == 50000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_50000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_50000000(tik)

#elif (BOARD_Fstm_FREQ == 100000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_100000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_100000000(tik)

#else
#error "You must configure the above macros for the BOARD_Fstm_FREQ frequency"
#endif


/* Note to OS_STM_PRESCALE: This value is used for initialization of STMs and calculation of times.
 * The TC38XQ derivative does not offer RMC fields in the STM's clock control registers (CLC), hence
 * all STMs use the same input frequency.
 * Therefore, this macro is set to one, to make it behave neutrally in calculations.
 */
#define OS_STM_PRESCALE		1U

#include <TRICORE/Os_TRICORE_stmconfig.h>


/* This is the initial PSW value:
 *   - call depth count disabled
 *   - supervisor mode
 *   - protection register set 0
 *   - interrupt stack (so we don't have to initialise the IS register yet)
*/
#define OS_INITIAL_PSW		(OS_PSW_CDC_DIS+OS_PSW_IO_SU+OS_PSW_PRS_0+OS_PSW_IS)

#define BOARD_TRICORE_BMI 0x0070 /* internal start from flash */
#define BOARD_TRICORE_BOOTWORD    0xa0000020

#ifndef OS_ASM
void BoardStart(void);
#endif

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
