/* board_pll_tc3xx.h - Tricore PLL module description for the "tc3xx" variant.
 *
 * This file contains a minimal description of Tricore's clock configuration registers (the
 * variant used on the TC3xx "Aurix" processors). It is part of the SCU module.
 *
 * This file only provides the addresses and and bitmasks of the SCU
 * registers that are actually used in the PLL configuration template
 *
 * Warning: This file has not been developed in accordance with a safety standard (no ASIL)!
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: $
*/
#ifndef OS_TRICORE_BOARD_PLL_TC3XX_H
#define OS_TRICORE_BOARD_PLL_TC3XX_H

#include <Os_types.h>
#include <TRICORE/Os_TRICORE_core.h>

#include "board.h" /* BOARD_*_FREQ/DIV */

/*
 * Note: If you change TMPL_SYS_FREQ, update the NsToTicks and TicksToNs macros accordingly
*/
#ifdef BOARD_XTAL_FREQ
#define TMPL_XTAL_FREQ				BOARD_XTAL_FREQ		/* crystal frequency [Hz] */
#else
#define TMPL_XTAL_FREQ				20000000u			/* 20 MHz crystal frequency [Hz] */
#endif

#ifdef BOARD_SYS_FREQ
#define TMPL_SYS_FREQ				BOARD_SYS_FREQ		/* CPU clock [Hz] */
#else
#define TMPL_SYS_FREQ				200000000u			/* 200 MHz CPU clock [Hz] */
#endif

#ifdef BOARD_Fstm_FREQ
#define TMPL_STM_FREQ				BOARD_Fstm_FREQ		/* STM clock [Hz] */
#else
#define TMPL_STM_FREQ				100000000u			/* 100 MHz STM clock [Hz] */
#endif

/* Calclulate dividers/multipliers for setting up the PLL
 *
 * According to the formula: (f_osc * N) / (P * K2) = f_pll,
 * where f_osc = TMPL_XTAL_FREQ, and f_pll = TMPL_SYS_FREQ.
 *
 * P	- 3-bit input divider: divide 'f_osc' on PLL entance
 * N	- 7-bit feedback divider: PLL multiplication factor
 * K2	- 3-bit output divider: output to the CPUs
 * K3	- 3-bit output divider: output to some other peripherals
 *
 * check1: ((f_osc * N) / P) must be within 400MHz - 800MHz range (DCO frequency range)
*/
#if (TMPL_XTAL_FREQ==20000000u) && (TMPL_SYS_FREQ==150000000u)
/*
 * Input: f_osc = 20MHz
 * Output: f_pll = 150MHz
 * (20MHz * 30) / (1 * 4) = 150MHz
 * check1: ((20MHz * 30) / 1) = 600MHz (OK)
*/
#define TMPL_P						1u
#define TMPL_N						36u
#define TMPL_K2						4u
#define TMPL_K3						3u

#elif (TMPL_XTAL_FREQ==20000000u) && (TMPL_SYS_FREQ==160000000u)
/*
 * Input: f_osc = 20MHz
 * Output: f_pll = 160MHz
 * (20MHz * 32) / (1 * 4) = 160MHz
 * check1: ((20MHz * 32) / 1) = 640MHz (OK)
*/
#define TMPL_P						1u
#define TMPL_N						32u
#define TMPL_K2						4u
#define TMPL_K3						4u

#elif (TMPL_XTAL_FREQ==20000000u) && (TMPL_SYS_FREQ==180000000u)
/*
 * Input: f_osc = 20MHz
 * Output: f_pll = 180MHz
 * (20MHz * 36) / (1 * 4) = 180MHz
 * check1: ((20MHz * 36) / 1) = 720MHz (OK)
*/
#define TMPL_P						1u
#define TMPL_N						36u
#define TMPL_K2						4u
#define TMPL_K3						4u

#elif (TMPL_XTAL_FREQ==20000000u) && (TMPL_SYS_FREQ==200000000u)
/*
 * Input: f_osc = 20MHz
 * Output: f_pll = 200MHz
 * (20MHz * 30) / (1 * 3) = 200MHz
 * check1: ((20MHz * 30) / 1) = 600MHz (OK)
*/
#define TMPL_P						1u
#define TMPL_N						30u
#define TMPL_K2						3u
#define TMPL_K3						3u

#elif (TMPL_XTAL_FREQ==20000000u) && (TMPL_SYS_FREQ==250000000u)
/*
 * Input: f_osc = 20MHz
 * Output: f_pll = 250MHz
 * (20MHz * 25) / (1 * 2) = 250MHz
 * check1: ((20MHz * 25) / 1) = 500MHz (OK)
*/
#define TMPL_P						1u
#define TMPL_N						30u
#define TMPL_K2						2u
#define TMPL_K3						2u

/*
 * Note: 300MHz is the maximal clock speed for TC39x
*/
#elif (TMPL_XTAL_FREQ==20000000u) && (TMPL_SYS_FREQ==300000000u)
/*
 * Input:	f_osc = 20MHz
 * Output:	f_pll = 300MHz
 * (20MHz * 30) / (1 * 2) = 300MHz
 * check1: ((20MHz * 30) / 1) = 600 (OK)
*/
#define TMPL_P						1u
#define TMPL_N						30u
#define TMPL_K2						2u
#define TMPL_K3						3u

#else
#error "No dividers are specified for the given TMPL_XTAL_FREQ and TMPL_SYS_FREQ"
#endif

#define TMPL_PLL0_FREQ_HZ	((TMPL_N * TMPL_XTAL_FREQ) / (TMPL_P * TMPL_K2))

/*
 * Fields in OSCCON
*/
#define TMPL_OSCCON_PLLLV			(0x1u << 1)			/* Oscillator for PLL Low Valid			*/
#define TMPL_OSCCON_PLLHV			(0x1u << 8)			/* Oscillator for PLL High Valid 		*/
#define TMPL_CCUCON_OSCVAL			(0x3u << 16)		/* 20 MHz reference clock				*/
#define TMPL_OSCCON_MODE_MASK		(0x3u << 5)			/* 00 enables ext. osc; 11 disables 	*/
#define TMPL_OSCSTABLE				(TMPL_OSCCON_PLLLV | TMPL_OSCCON_PLLHV)

/*
 * Fields in System PLL
*/
#define TMPL_SYSPLL_SRC				(0x1u << 30)		/* Select OSC as the input clock		*/
#define TMPL_SYSPLL_PWD				(0x1u << 16)		/* Power Saving: 0 - sleep; 1 active	*/
#define TMPL_SYSPLL_P				((TMPL_P - 1) << 24)/* System PLL P divider					*/
#define TMPL_SYSPLL_N				((TMPL_N - 1) << 9)	/* System PLL N divider					*/
#define TMPL_SYSPLL_K2				(TMPL_K2 - 1)		/* System PLL K2 divider				*/

/*
 * Definitions to enable step-by-step frequency ramp-up
 * It is recommended to have an initial PLL frequency value same or slightly higher than
 * the frequency of the back-up clock, which is the initial clock source on startup.
 * For us it means setting the K2 divider to 6 (5+1) (600 MHz / 6 = 100 MHz)
 * and lower it gradually, increasing the output clock frequency.
*/
#define TMPL_FREQ_STBL_DELAY		10000u				/* Idle loop iterations per step		*/
#if (TMPL_SYSPLL_K2 > 5u)
#define TMPL_SYSPLL_K2_INIT			TMPL_SYSPLL_K2		/* No ramp-up, divider is big enough	*/
#else
#define TMPL_SYSPLL_K2_INIT			5u					/* Initial value of K2 divider			*/
#endif

/*
 * Feilds in System PLL Status Register
*/
#define TMPL_SYSPLL_RESLD			(0x1u << 18)		/* Restart lock detection				*/
#define TMPL_SYSPLL_STAT_LOCK		(0x1u << 2)			/* 1 if PLL produces stable frequency	*/

/*
 * Fields in Peripheral PLL
*/
#define TMPL_PERPLL_PWD				(0x1u << 16)		/* Power Saving: 0 - sleep; 1 active	*/
#define TMPL_PERPLL_P				((TMPL_P - 1) << 24)/* Peripheral PLL P divider				*/
#define TMPL_PERPLL_N				((TMPL_N - 1) << 9)	/* Peripheral PLL N divider				*/
#define TMPL_PERPLL_K2				(TMPL_K2 - 1)		/* Peripheral PLL K2 divider			*/
#define TMPL_PERPLL_K3				((TMPL_K3 - 1) << 8)/* Peripheral PLL K3 divider			*/

/*
 * Fields in Peripheral PLL Status Register
*/
#define TMPL_PERPLL_RESLD			(0x1u << 18)		/* Restart lock detection				*/
#define TMPL_PERPLL_STAT_LOCK		(0x1u << 2)			/* 1 if PLL produces stable frequency	*/

/* Select clock.
*/
#define TMPL_CLKSEL_BACKUP		0u
#define TMPL_CLKSEL_PLL0		1u
#define TMPL_CLKSEL				TMPL_CLKSEL_PLL0
#define TMPL_CLKSRC0_FREQ_HZ	TMPL_PLL0_FREQ_HZ

/* Choose STM divider.
*/
#define TMPL_STMDIV				(TMPL_CLKSRC0_FREQ_HZ / TMPL_STM_FREQ)
/* Assert 1 <= TMPL_STMDIV < 16. */
#if (TMPL_STMDIV < 1)
#error "STM divider must fulfil '1 <= TMPL_STMDIV < 16'. It was less than 1."
#endif
#if (TMPL_STMDIV > 15)
#error "STM divider must fulfil '1 <= TMPL_STMDIV < 16'. It was greater than 15."
#endif
/* 7, 9, 11, 13, 14 are not allowed as STM dividers. */
#if (TMPL_STMDIV == 7)
#error "TMPL_STMDIV must not be one of _7_, 9, 11, 13, 14."
#endif
#if (TMPL_STMDIV == 9)
#error "TMPL_STMDIV must not be one of 7, _9_, 11, 13, 14."
#endif
#if (TMPL_STMDIV == 11)
#error "TMPL_STMDIV must not be one of 7, 9, _11_, 13, 14."
#endif
#if (TMPL_STMDIV == 13)
#error "TMPL_STMDIV must not be one of 7, 9, 11, _13_, 14."
#endif
#if (TMPL_STMDIV == 14)
#error "TMPL_STMDIV must not be one of 7, 9, 11, 13, _14_."
#endif

/* Other dividers
*/
#define TMPL_SRIDIV				0x1u
/* Dividers that should be specified in board.h due to derivative specific frequency limitations
*/
#ifdef BOARD_SPB_DIV
#define TMPL_SPBDIV				BOARD_SPB_DIV
#else
#define TMPL_SPBDIV				0x2u
#endif
#ifdef BOARD_FSI_DIV
#define TMPL_FSIDIV				BOARD_FSI_DIV
#else
#define TMPL_FSIDIV				0x2u
#endif
#ifdef BOARD_GTM_DIV
#define TMPL_GTMDIV				BOARD_GTM_DIV
#else
#define TMPL_GTMDIV				0x2u
#endif
#ifdef BOARD_BBB_DIV
#define TMPL_BBBDIV				BOARD_BBB_DIV
#else
#define TMPL_BBBDIV				0x2u
#endif

#if TMPL_BBBDIV < TMPL_SRIDIV
#error "fBBB has to be slower or equal to fSRI"
#endif

/*
 * Fields in the Clock Control Unit (defines clock
 * distribution and frequencies of the on-chip buses)
 * CCUCON0 reset value is 0x3512_0112
 *         shift values:    2221 1
 *                          8406 2840
 * CCUCON1 reset value is 0x1010_0302
 * CCUCON2 reset value is 0x0700_0101
*/
#define TMPL_CCUCON0_LCK			(       0x1u << 31)		/* Lock status							*/
#define TMPL_CCUCON0_UPDREQ			(       0x1u << 30)		/* Request an update of the CCU			*/
#define TMPL_CCUCON0_CLKSEL			(TMPL_CLKSEL << 28)		/* Src0=PLL0, Src1=(PLL1)/2, Src2=PLL2	*/
#define TMPL_CCUCON0_SRIDIV			(TMPL_SRIDIV <<  8)		/* SRI freq. = Src0 freq.				*/
#define TMPL_CCUCON0_FSIDIV			(TMPL_FSIDIV << 24)		/* FSI freq. = SRI freq.				*/
#define TMPL_CCUCON0_FSI2DIV		(       0x1u << 26)		/* FSI2 freq. = SRI freq.				*/
#define TMPL_CCUCON0_STMDIV			(TMPL_STMDIV <<  0)		/* STM frequency = Src0 / STMDIV		*/
#define TMPL_CCUCON0_BBBDIV			(TMPL_BBBDIV << 20)		/* Back Bone Bus, BBB_f = 1/2 src_f		*/
#define TMPL_CCUCON0_SPBDIV			(TMPL_SPBDIV << 16)		/* SPB freq. = Src0 / 2					*/
#define TMPL_CCUCON0_LPDIV			(       0x0u << 12)		/* Stopped - clock gated				*/
#define TMPL_CCUCON0_GTMDIV			(TMPL_GTMDIV <<  4)		/* GTM frequency = SrcGtm / 2			*/

#define TMPL_CCUCON1_LCK			(       0x1u << 31)		/* Lock status							*/
#define TMPL_CCUCON1_CLKSELQSPI		(       0x0u << 28)		/* Stopped - clock gated				*/
#define TMPL_CCUCON1_QSPIDIV		(       0x0u << 24)		/* Stopped - clock gated				*/
#define TMPL_CCUCON1_CLKSELMSC		(       0x0u << 20)		/* Stopped - clock gated				*/
#define TMPL_CCUCON1_MSCDIV			(       0x0u << 16)		/* Stopped - clock gated				*/
#define TMPL_CCUCON1_PLL1DIVDIS		(       0x0u <<  7)		/* if 1, PLL1 divider (/2) is bypassed	*/
#define TMPL_CCUCON1_CLKSELMCAN		(       0x0u <<  4)		/* Stopped - clock gated				*/
#define TMPL_CCUCON1_MCANDIV		(       0x0u <<  0)		/* Stopped - clock gated				*/

#define TMPL_CCUCON2_LCK			(       0x1u << 31)		/* Lock status							*/
#define TMPL_CCUCON2_CLKSELASCLINS	(       0x0u << 12)		/* Stopped - clock gated				*/
#define TMPL_CCUCON2_ASCLINSDIV		(       0x0u <<  8)		/* Stopped - clock gated				*/
#define TMPL_CCUCON2_ASCLINFDIV		(       0x0u <<  0)		/* Stopped - clock gated				*/

/* Common Field for all CCUCONx registers */
#define TMPL_CCUCON_LCK_LOCKED		0x80000000u
#define TMPL_CCUCON_UP				0x40000000u

/* Fields in CCUCON0 */
#define TMPL_CCUCON0_CLKSEL_MASK	0x30000000u
#define TMPL_CCUCON0_CLKSEL_FPLL	0x10000000u

/* Fields in CCUCON1 */
#define TMPL_CCUCON1_INSEL_MASK		0x30000000u
#define TMPL_CCUCON1_INSEL_FOSC0	0x10000000u

/* Perform sanity checks.
*/
#if (TMPL_STM_FREQ != (TMPL_CLKSRC0_FREQ_HZ / TMPL_STMDIV))
#error "STM clock frequency configuration is inconsistent."
#endif
#if (TMPL_SYS_FREQ != TMPL_CLKSRC0_FREQ_HZ)
#error "System clock frequency configuration is inconsistent."
#endif

/*
 * Per CPU watch-dog timer control and status registers:
 * WDTCPUxCON0, WDTCPUxCON1, WDTCPUxSR
*/
struct os_tricore_wdt_s
{
	os_reg32_t con0;			/* base+0+i*12	: CPUi WDT Control Register 0					*/
	os_reg32_t con1;			/* base+4+i*12	: CPUi WDT Control Register 1					*/
	os_reg32_t sr;				/* base+8+i*12	: CPUi WDT Status Register						*/
};
typedef struct os_tricore_wdt_s os_tricore_wdt_t;

/*
 * TRICORE TC3xx SCU memory layout
 * All names correspond to AURIX TC3xx Target specification v.2.0.1
 * with the exceptions of:	WDTCPUxCON0, WDTCPUxCON1, WDTCPUxSR,
 * which are accessed as:	wdtcpu[i]->con0, wdtcpu[i]->con1, wdtcpu[i]->sr
*/
struct os_tricore_scu_s			/* Base address	: 0xF0036000									*/
{
	os_reg32_t padding_1[2];	/* 0xF0036000	: Reserved space								*/
	os_reg32_t id;				/* 0xF0036008	: Identification register						*/
	os_reg32_t padding_2;		/* 0xF003600C	: Reserved space								*/
	os_reg32_t osccon;			/* 0xF0036010	: OSC Control Register							*/
	os_reg32_t syspllstat;		/* 0xF0036014	: System PLL Status Register					*/
	os_reg32_t syspllcon0;		/* 0xF0036018	: System PLL Configuration Register 0			*/
	os_reg32_t syspllcon1;		/* 0xF003601C	: System PLL Configuration Register 1			*/
	os_reg32_t syspllcon2;		/* 0xF0036020	: System PLL Configuration Register 2			*/
	os_reg32_t perpllstat;		/* 0xF0036024	: Peripheral PLL Status Register				*/
	os_reg32_t perpllcon0;		/* 0xF0036028	: Peripheral PLL Configuration Register 0		*/
	os_reg32_t perpllcon1;		/* 0xF003602C	: Peripheral PLL Configuration Register 1		*/
	os_reg32_t ccucon0;			/* 0xF0036030	: CCU Clock Control Register 0					*/
	os_reg32_t ccucon1;			/* 0xF0036034	: CCU Clock Control Register 1					*/
	os_reg32_t fdr;				/* 0xF0036038	: Fractional Divider Degister					*/
	os_reg32_t extcon;			/* 0xF003603C	: External Clock Control Register				*/
	os_reg32_t ccucon2;			/* 0xF0036040	: CCU Clock Control Register 2					*/
	os_reg32_t padding_3[3];	/* 0xF0036044	: Reserved space								*/
	os_reg32_t rststat;			/* 0xF0036050	: Reset Status Register							*/
	os_reg32_t padding_4;		/* 0xF0036054	: Reserved space								*/
	os_reg32_t rstcon;			/* 0xF0036058	: Reset Configuration Register					*/
	os_reg32_t arstdis;			/* 0xF003605C	: Application Reset Disable Register			*/
	os_reg32_t swrstcon;		/* 0xF0036060	: Software Reset Configuration Register			*/
	os_reg32_t rstcon2;			/* 0xF0036064	: Reset Configuration Register 2				*/
	os_reg32_t rstcon3;			/* 0xF0036068	: Reset Configuration Register 3				*/
	os_reg32_t padding_5;		/* 0xF003606C	: Reserved space								*/
	os_reg32_t esrcfg1;			/* 0xF0036070	: ESR1 Input Configuration Register				*/
	os_reg32_t esrcfg2;			/* 0xF0036074	: ESR2 Input Configuration Register				*/
	os_reg32_t esrocfg;			/* 0xF0036078	: ESR Output Configuration Register				*/
	os_reg32_t syscon;			/* 0xF003607C	: System Control Register						*/
	os_reg32_t ccucon6;			/* 0xF0036080	: CCU Clock Control Register					*/
	os_reg32_t ccucon7;			/* 0xF0036084	: CCU Clock Control Register					*/
	os_reg32_t ccucon8;			/* 0xF0036088	: CCU Clock Control Register					*/
	os_reg32_t ccucon9;			/* 0xF003608C	: CCU Clock Control Register					*/
	os_reg32_t ccucon10;		/* 0xF0036090	: CCU Clock Control Register					*/
	os_reg32_t ccucon11;		/* 0xF0036094	: CCU Clock Control Register					*/
	os_reg32_t padding_6;		/* 0xF0036098	: Reserved space								*/
	os_reg32_t pdr;				/* 0xF003609C	: ESR Pad Driver Mode Register					*/
	os_reg32_t iocr;			/* 0xF00360A0	: Input/Output Control Register					*/
	os_reg32_t out;				/* 0xF00360A4	: ESR Output Register							*/
	os_reg32_t omr;				/* 0xF00360A8	: ESR Output Modification Register				*/
	os_reg32_t in;				/* 0xF00360AC	: ESR Input Register							*/
	os_reg32_t padding_7[4];	/* 0xF00360B0	: Reserved space								*/
	os_reg32_t ststat;			/* 0xF00360C0	: Start-up Status Register						*/
	os_reg32_t padding_8;		/* 0xF00360C4	: Reserved space								*/
	os_reg32_t pmcsr3;			/* 0xF00360C8	: Power Management Control & Status Register 3	*/
	os_reg32_t pmcsr4;			/* 0xF00360CC	: Power Management Control & Status Register 4	*/
	os_reg32_t pmcsr5;			/* 0xF00360D0	: Power Management Control & Status Register 5	*/
	os_reg32_t pmcsr0;			/* 0xF00360D4	: Power Management Control & Status Register 0	*/
	os_reg32_t pmcsr1;			/* 0xF00360D8	: Power Management Control & Status Register 1	*/
	os_reg32_t pmcsr2;			/* 0xF00360DC	: Power Management Control & Status Register 2	*/
	os_reg32_t padding_9;		/* 0xF00360E0	: Reserved space								*/
	os_reg32_t pmstat0;			/* 0xF00360E4	: Power Management Status Register 0			*/
	os_reg32_t pmswcr1;			/* 0xF00360E8	: Standby & Wake-up Control Register 1			*/
	os_reg32_t padding_10[4];	/* 0xF00360EC	: Reserved space								*/
	os_reg32_t emsr;			/* 0xF00360FC	: Emergency Stop Register						*/
	os_reg32_t padding_11[8];	/* 0xF0036100	: Reserved space								*/
	os_reg32_t trapdis1;		/* 0xF0036120	: Trap Disable Register 1						*/
	os_reg32_t trapstat;		/* 0xF0036124	: Trap Status Register							*/
	os_reg32_t trapset;			/* 0xF0036128	: Trap Set Register								*/
	os_reg32_t trapclr;			/* 0xF003612C	: Trap Clear Register							*/
	os_reg32_t trapdis0;		/* 0xF0036130	: Trap Disable Register 0						*/
	os_reg32_t lclcon0;			/* 0xF0036134	: LCL CPU0 Control Register						*/
	os_reg32_t lclcon1;			/* 0xF0036138	: LCL CPU1 Control Register						*/
	os_reg32_t lcltest;			/* 0xF003613C	: LCL Test Register								*/
	os_reg32_t chipid;			/* 0xF0036140	: Chip Identification Register					*/
	os_reg32_t manid;			/* 0xF0036144	: Manufacturer Identification Register			*/
	os_reg32_t padding_12[7];	/* 0xF0036148	: Reserved space								*/
	os_reg32_t lbistctrl0;		/* 0xF0036164	: Logic BIST Control Register 0					*/
	os_reg32_t lbistctrl1;		/* 0xF0036168	: Logic BIST Control Register 1					*/
	os_reg32_t lbistctrl2;		/* 0xF003616C	: Logic BIST Control Register 2					*/
	os_reg32_t lbistctrl3;		/* 0xF0036170	: Logic BIST Control Register 3					*/
	os_reg32_t padding_13[6];	/* 0xF0036174	: Reserved space								*/
	os_reg32_t pdisc;			/* 0xF003618C	: Pad Disable Control Register					*/
	os_reg32_t padding_14[2];	/* 0xF0036190	: Reserved space								*/
	os_reg32_t pmtrcsr0;		/* 0xF0036198	: Pow. Management Transit. Control & Status 0	*/
	os_reg32_t pmtrcsr1;		/* 0xF003619C	: Pow. Management Transit. Control & Status 1	*/
	os_reg32_t pmtrcsr2;		/* 0xF00361A0	: Pow. Management Transit. Control & Status 2	*/
	os_reg32_t pmtrcsr3;		/* 0xF00361A4	: Pow. Management Transit. Control & Status 3	*/
	os_reg32_t padding_15[14];	/* 0xF00361A8	: Reserved space								*/
	os_reg32_t ovcenable;		/* 0xF00361E0	: Overlay Enable Register						*/
	os_reg32_t ovccon;			/* 0xF00361E4	: Overlay Control Register						*/
	os_reg32_t padding_16[9];	/* 0xF00361E8	: Reserved space								*/
	os_reg32_t eifilt;			/* 0xF003620C	: External Input Filter Register				*/
	os_reg32_t eicr_0;			/* 0xF0036210	: External Input Channel Register 0				*/
	os_reg32_t eicr_1;			/* 0xF0036214	: External Input Channel Register 1				*/
	os_reg32_t eicr_2;			/* 0xF0036218	: External Input Channel Register 2				*/
	os_reg32_t eicr_3;			/* 0xF003621C	: External Input Channel Register 3				*/
	os_reg32_t eifr;			/* 0xF0036220	: External Input Flag Register					*/
	os_reg32_t fmr;				/* 0xF0036224	: Flag Modification Register					*/
	os_reg32_t pdrr;			/* 0xF0036228	: Pattern Detection Result Register				*/
	os_reg32_t igcr0;			/* 0xF003622C	: Flag Gating Register 0						*/
	os_reg32_t igcr1;			/* 0xF0036230	: Flag Gating Register 1						*/
	os_reg32_t igcr2;			/* 0xF0036234	: Flag Gating Register 2						*/
	os_reg32_t igcr3;			/* 0xF0036238	: Flag Gating Register 3						*/
	os_reg32_t padding_17[4];	/* 0xF003623C	: Reserved space								*/
	os_tricore_wdt_t wdtcpu[6];	/* 0xF003624C	: Per CPU WDT Structure	(12 byte  * 6 CPUs)		*/
	os_reg32_t padding_18[2];	/* 0xF0036294	: Reserved space								*/
	os_reg32_t eicon0;			/* 0xF003629C	: ENDINIT Global Control Register 0				*/
	os_reg32_t eicon1;			/* 0xF00362A0	: ENDINIT Global Control Register 1				*/
	os_reg32_t eisr;			/* 0xF00362A4	: ENDINIT Timeout Counter Status Register		*/
	os_reg32_t wdtscon0;		/* 0xF00362A8	: System WDT Control Register 0					*/
	os_reg32_t wdtscon1;		/* 0xF00362AC	: System WDT Control Register 1					*/
	os_reg32_t wdtssr;			/* 0xF00362B0	: System WDT Status Register					*/
	os_reg32_t seicon0;			/* 0xF00362B4	: Safety ENDINIT Control Register 0				*/
	os_reg32_t seicon1;			/* 0xF00362B8	: Safety ENDINIT Control Register 1				*/
	os_reg32_t seisr;			/* 0xF00362BC	: Safety ENDINIT Timeout Status Register		*/
	os_reg32_t padding_19[76];	/* 0xF00362C0	: Reserved space								*/
	os_reg32_t accen11;			/* 0xF00363F0	: Access Enable Register 11						*/
	os_reg32_t accen10;			/* 0xF00363F4	: Access Enable Register 10						*/
	os_reg32_t accen01;			/* 0xF00363F8	: Access Enable Register 01						*/
	os_reg32_t accen00;			/* 0xF00363FC	: Access Enable Register 00						*/
};
typedef struct os_tricore_scu_s os_tricore_scu_t;

#endif

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
