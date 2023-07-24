/* board.c
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board.c 33382 2021-03-03 08:00:10Z arla271030 $
*/

#include <Os.h>
#include <board.h>
#include <Os_configuration.h>
#include <Os_kernel.h>
#include <TRICORE/Os_TRICORE_stm.h>
#include <TRICORE/Os_TRICORE_core.h>
#include <Os_configuration_decls.h>
#include <board_tool.h>
#include <board_initcdata.h>
#include <board_initpll.h>
#include "Tmpl_TRICORE_ocds.h"
#include "function_safety.h"

#ifndef OS_N_CORES_MAX
#error "This file needs to know the number of cores available on the used derivative"
#endif

#ifndef OS_N_STM
#error "This file needs to know the number of STM units available on the used derivative"
#endif

/* CHECK: RESTORE
 * CHECK: NEXT RULE 402 OFF (main() is C convention)
*/
int main(void);


#define STM_KRST0_RSTSTAT 2u

/*!
 * Initializes the given STM according to the needs of our demo application.
*/
static void boardInitStm(os_tricorestm_t *stm)
{
	/* Initialize (i.e. enable) the STM modules
	*/
	OS_InitModule(&(stm->stm_module_hdr), 0u, 0u);

	/* Reset the STM so its timer registers are set to zero.
	 *
	 * This makes absolute timing more predictable, because we don't know how long this machine was already running.
	 * Note: Better avoid using absolute timing for alarms and schedule tables.
	 *
	 * Caveat: This code causes the STMs to show different values, when read at the same time.
	 *         However, you shouldn't rely on the assumption that two STMs show the same value
	 *         when read at the same time, anyway.
	*/
	OS_WriteEndinit(0);
	stm->stm_krstclr = 1u; /*< Reset the reset status bit, so we can poll it later. */
	stm->stm_krst0 = 1u; /*< Unlock STM reset. */
	stm->stm_krst1 = 1u; /*< Trigger STM reset. */
	while ((stm->stm_krst0 & STM_KRST0_RSTSTAT) == 0u)
	{
		/* Poll the reset status bit, to wait until the STM has performed the reset.
		*/
	}
	stm->stm_krstclr = 1u; /*< Reset the reset status bit again. */
	OS_WriteEndinit(1);

	/* We just reset the STM module, so initialize it again.
	*/
	OS_InitModule(&(stm->stm_module_hdr), 0u, 0u);

	/* Stop the STM when the debugger stops program execution.
	 * Due to this if-statement, a slightly different start-up path may be executed
	 * depending on whether a debugger is attached or not.
	 * That is:
	 *  - If you start with a debugger attached, you set the STMs to debug mode.
	 *  - If you start without debugger, the STMs aren't set to debug mode.
	 * If you don't like this, feel free to remove the following compound statement (it's just demo code).
	 * Note, that if you remove this statement, the STMs won't stop,
	 * when you stop the processor using the debugger.
	*/
	if (Tmpl_Ocds_MaySetStmsToDebugMode())
	{
		stm->stm_ocs = ( stm->stm_ocs & (os_reg32_t)~((os_reg32_t)OS_STM_OCS_SUS_MASK))
						| OS_STM_OCS_SUS_WILL_STOP | OS_STM_OCS_SUS_WRITE_PROT;
	}
}

/*!
 * BoardStart is jumped to from the assembly-language startup code.
 * It performs hardware initialization, then calls main()
 * It must *NEVER* return, therefore main() must never return!
 *
 * A free CSA list and a temporary stack have already been set up.
 *
 * WARNING: on entry, the data and bss sections have not been initialized.
 * They get initialized by this function. So care must be taken not to
 * rely on memory having any particular value on entry, and beware that
 * the initialization will overwrite any memory variables, possibly
 * including the stack.
*/
BOARD_NO_STACKPROT_PREFIX
void BoardStart(void)
{
	register os_uint32_t core = OS_TricoreGetCoreId();

	while ( core >= OS_N_CORES_MAX )
	{
		/* Oops! OS_GetMyCoreId() returned a non-existent core.
		*/
	}

	if (core != 0u)
	{
		/* For the demo we assume that core 0 is always started and executes BoardStart.
		 * If it isn't used by the OS, it will start the OS's init-core.
		 * If another core comes here, it hangs.
		*/
		OS_ENDLESSLOOP();
	}
	/*
	*Function safety module will check the count of CAT2 errors.
	* When the count reaches 3,it will enter endless loop,and never returns;
	*/
    #if (!FS_EXEC_DISABLED)
	FS_Boot();
	#endif
	
	/* Clear both CPU and safety ENDINIT bits while setting up the microcontroller
	*/
	OS_WriteSafetyEndinit(0);	/* Unlock safety-endinit-protected registers (CCUCONn etc.) */
	OS_WriteEndinit(0);			/* Unlock endinit-protected registers. */

	/* Disable the CPU watchdog and the safety watchdogs
	 *
	 * We do this before the PLL setup, because the PLL setup code may be affected by time fluctuations
	 * which could trigger the watchdog.
	 * Note that this is just demo code. The PLL setup should be done by qualified software,
	 * like the MCAL or MCU module.
	*/
	OS_pwr.pwr_swdt.wdt_con[1] = 8U;
	OS_pwr.pwr_wdt[core].wdt_con[1] = 8U;

	OS_WriteEndinit(1);
	OS_WriteSafetyEndinit(1);

	/* Initialize PLL */
	/*boardInitPLL();*/ //Zhang Jinlong: For optimize startup time to comment this line.

	OS_WriteSafetyEndinit(0);	/* Unlock safety-endinit-protected registers (CCUCONn etc.) */
	OS_WriteEndinit(0);			/* Unlock endinit-protected registers. */

	/* Setup the cache */
	OS_SetupCache(OS_TRUE, OS_TRUE);

	/*	Initialize PCXI so that the context list has an end.
	*/
	OS_MTCR(OS_PCXI, 0);

	/*	Initialize the registers that point to the trap and interrupt
	 *	tables and the interrupt stack pointer.
	 *
	 *	The trap table is the startup version with endless loops, as demanded
	 *	by the AutosarOS specification.
	 *	The base interrupt vector is set to zero (which should be the reset
	 *  value anyways), so that if an interrupt occurs the CPU traps and
	 *  also ends up in an endless loop. However, all
	 *  interrupts are disabled, so this should never happen.
	 *	The interrupt stack pointer is correct for the kernel. This
	 *	must be set up before calling StartOS.
	 *
	 *	REQ: Kernel.Autosar.Protection.HardwareProtection.CPU.Exception.BeforeStartOS,SRC
	*/
	OS_MTCR(OS_BTV, (os_uint32_t)&OS_startupTrapTable);
	OS_MTCR(OS_BIV, 0);
#ifdef OS_ISTACKBASE_0
	OS_MTCR(OS_ISP, ((os_uint32_t)OS_ISTACKBASE_0)+OS_ISTACKLEN_0);
#else
	/* This is no AUTOSAR core. */
	OS_MTCR(OS_ISP, 0);
#endif

	/* Set initial PSW value.
	*/
	OS_MTCR(OS_PSW, OS_INITIAL_PSW);

	/* initialize global address register to kernel data struct
	*/
	OS_MTA8(OS_kernel_ptr[core]);

	/* Set A0 and A1 of other cores (if supported and necessary).
	*/
	BoardSetOtherCoresA0A1();

	/*	Now we must set ENDINIT, or else the watchdog will time out while
	 *	initialising the data sections. From here on, all ENDINIT-protected
	 *	systems are protected and must be unlocked before use.
	*/

	OS_WriteEndinit(1);
	OS_WriteSafetyEndinit(1);

	/* Copy the data section out from flash to RAM
	 * and clear the bss section.
	*/
	boardInitCData();

	/* Initialize (i.e. enable) the STM modules
	*/
	boardInitStm((os_tricorestm_t *)OS_STM0_BASE);
#if OS_N_STM >= 2u
	boardInitStm((os_tricorestm_t *)OS_STM1_BASE);
#endif
#if OS_N_STM >= 3u
	boardInitStm((os_tricorestm_t *)OS_STM2_BASE);
#endif
#if OS_N_STM >= 4u
	boardInitStm((os_tricorestm_t *)OS_STM3_BASE);
#endif
#if OS_N_STM >= 5u
	boardInitStm((os_tricorestm_t *)OS_STM4_BASE);
#endif
#if OS_N_STM >= 6u
	boardInitStm((os_tricorestm_t *)OS_STM5_BASE);
#endif

#if OS_N_CORES_MAX >= 2u
	/* If we are not the OS's init-core, we have to activate it.
	 * Since the init-core now won't run BoardStart, we have to do this just after everything is set up.
	*/
	if (core != OS_INITCORE)
	{
		OS_TricoreStartCore(OS_INITCORE);

		/* We don't want, that a non-AUTOSAR core enters main. */
		if (!OS_CoreIsInUse(core))
		{
			OS_ENDLESSLOOP();
		}

#if (OS_N_CORES > 1)
		/* Wait until explicitly started by some other core. */
		do {
			/* Wait here until told to start */
			OS_CacheInvalidate(&(OS_coreStarted[core]), sizeof(OS_coreStarted[0]));
		} while ( OS_coreStarted[core] != OS_TRUE );
#endif

	}
#endif

	/* When all that is done, we can start the OS
	*/
	main();
}


/* The GNU compiler generates links to some standard memory functions. */
#if (OS_TOOL == OS_gnu)
void *memcpy(void *dest, const void *src, int n);
void *memcpy(void *dest, const void *src, int n)
{
	const unsigned char * mysrc  = src;
	unsigned char * mydest = dest;

	while (n>0)
	{
		n--;
		mydest[n] = mysrc[n];
	}

	return dest;
}

/* Calls to abort() are inserted by the compiler in some cases where normal
 * continuation is impossible (e.g. null pointer dereferences).
*/
void abort(void);
void abort(void)
{
	__asm__ volatile ("debug");
	while (1);
}
#endif

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
