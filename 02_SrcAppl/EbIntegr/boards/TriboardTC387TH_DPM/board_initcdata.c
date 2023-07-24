/* board_initcdata.c
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board_initcdata.c 29552 2018-11-29 08:53:43Z sash270423 $
*/

#include <Os_cpu.h>
#include <Os_tool.h>
#include <Os_config.h>
#include <board_initcdata.h>
#include <board_tool.h>

#ifndef OS_N_CORES_MAX
#error "This file needs to know the number of cores available on the used TRICORE derivative"
#endif

#ifndef OS_PROPERTIES_CORE0
#error "This file needs to know the core properties."
#endif

/* USE_TASKING_INIT is currently provided via -D command line options,
 * if necessary.
*/
#ifndef USE_TASKING_INIT
#define USE_TASKING_INIT	0
#endif

#if (OS_TOOL == OS_tasking)
#if USE_TASKING_INIT
extern void _c_init(void);	/* tasking C initialization function */
#endif
#endif /* OS_TOOL==OS_tasking */

/* We explicitly set sections for these symbols, in case customers want to use the "small data area" (SDA)
 * feature of their compiler. This way the compiler won't try to access them via the SDA base address.
*/
#define BOARD_LINKERSYMBOLS_BSS(id) \
	BOARD_LINKERSYMBOL_BSS(__STARTBSS##id); \
	BOARD_LINKERSYMBOL_BSS(__ENDBSS##id)
#define BOARD_LINKERSYMBOLS_DATA(id) \
	BOARD_LINKERSYMBOL_DATA(__STARTDATA##id); \
	BOARD_LINKERSYMBOL_DATA(__ENDDATA##id); \
	extern const os_char_t __INITDATA##id
#define BOARD_LINKERSYMBOLS_BSS_DATA(id) \
	BOARD_LINKERSYMBOLS_BSS(id); \
	BOARD_LINKERSYMBOLS_DATA(id)

/* These "variables" are actually markers set up by the linker.
 * CHECK: SAVE
 * CHECK: RULE 401 OFF (not variables)
*/

BOARD_LINKERSYMBOLS_BSS_DATA(_ANON);

#if ((OS_PROPERTIES_CORE0 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
BOARD_LINKERSYMBOLS_BSS_DATA(_C0);
#endif /* OS_PROPERTIES_COREX */

#if OS_N_CORES_MAX > 1u
#if ((OS_PROPERTIES_CORE1 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
BOARD_LINKERSYMBOLS_BSS_DATA(_C1);
#endif /* OS_PROPERTIES_COREX */
#endif /* OS_N_CORES_MAX */

#if OS_N_CORES_MAX > 2u
#if ((OS_PROPERTIES_CORE2 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
BOARD_LINKERSYMBOLS_BSS_DATA(_C2);
#endif /* OS_PROPERTIES_COREX */
#endif /* OS_N_CORES_MAX */

#if OS_N_CORES_MAX > 3u
#if ((OS_PROPERTIES_CORE3 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
BOARD_LINKERSYMBOLS_BSS_DATA(_C3);
#endif /* OS_PROPERTIES_COREX */
#endif /* OS_N_CORES_MAX */

#if OS_N_CORES_MAX > 4u
#if ((OS_PROPERTIES_CORE4 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
BOARD_LINKERSYMBOLS_BSS_DATA(_C4);
#endif /* OS_PROPERTIES_COREX */
#endif /* OS_N_CORES_MAX */

#if OS_N_CORES_MAX > 5u
#if ((OS_PROPERTIES_CORE5 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
BOARD_LINKERSYMBOLS_BSS_DATA(_C5);
#endif /* OS_PROPERTIES_COREX */
#endif /* OS_N_CORES_MAX */

BOARD_LINKERSYMBOLS_BSS_DATA(_SHARED_OS);

/* CHECK: RESTORE
 * CHECK: NEXT RULE 402 OFF (main() is C convention)
*/

#if (OS_TOOL!=OS_tasking) || (!USE_TASKING_INIT)
BOARD_NO_STACKPROT_PREFIX
static void boardMemcpy(os_char_t *start, const os_char_t *init, os_char_t *end)
{
	register const os_char_t *src;
	register os_char_t *dst;

	for (dst = start, src = init; dst < end; ++dst, ++src)
	{
		*dst = *src;
	}
}
BOARD_NO_STACKPROT_PREFIX
static void boardZeromem(os_char_t *start, os_char_t *end)
{
	register os_char_t *dst;

	for (dst = start; dst < end; ++dst)
	{
		*dst = 0;
	}
}
#endif

BOARD_NO_STACKPROT_PREFIX
extern os_char_t __START_DSPR_Core0_QM_Bss;
extern os_char_t __END_DSPR_Core0_QM_Bss;
extern os_char_t __START_DSPR_Core0_ASIL_Bss;
extern os_char_t __END_DSPR_Core0_ASIL_Bss;
extern os_char_t __START_DSPR_Core1_QM_Bss;
extern os_char_t __END_DSPR_Core1_QM_Bss;
extern os_char_t __START_DSPR_Core1_ASIL_Bss;
extern os_char_t __END_DSPR_Core1_ASIL_Bss;
extern os_char_t __START_DSPR_Core2_QM_Bss;
extern os_char_t __END_DSPR_Core2_QM_Bss;
extern os_char_t __START_DSPR_Core2_ASIL_Bss;
extern os_char_t __END_DSPR_Core2_ASIL_Bss;
extern os_char_t __START_DSPR_Core3_QM_Bss;
extern os_char_t __END_DSPR_Core3_QM_Bss;
extern os_char_t __START_DSPR_Core3_ASIL_Bss;
extern os_char_t __END_DSPR_Core3_ASIL_Bss;

extern os_char_t __START_PSPR_Core0_QM_Bss;
extern os_char_t __END_PSPR_Core0_QM_Bss;
extern os_char_t __START_PSPR_Core0_ASIL_Bss;
extern os_char_t __END_PSPR_Core0_ASIL_Bss;
extern os_char_t __START_PSPR_Core1_QM_Bss;
extern os_char_t __END_PSPR_Core1_QM_Bss;
extern os_char_t __START_PSPR_Core1_ASIL_Bss;
extern os_char_t __END_PSPR_Core1_ASIL_Bss;
extern os_char_t __START_PSPR_Core2_QM_Bss;
extern os_char_t __END_PSPR_Core2_QM_Bss;
extern os_char_t __START_PSPR_Core2_ASIL_Bss;
extern os_char_t __END_PSPR_Core2_ASIL_Bss;
extern os_char_t __START_PSPR_Core3_QM_Bss;
extern os_char_t __END_PSPR_Core3_QM_Bss;
extern os_char_t __START_PSPR_Core3_ASIL_Bss;
extern os_char_t __END_PSPR_Core3_ASIL_Bss;

extern os_char_t __START_DSPR_Core0_QM_Data;
extern os_char_t __END_DSPR_Core0_QM_Data;
extern os_char_t __START_DSPR_Core0_ASIL_Data;
extern os_char_t __END_DSPR_Core0_ASIL_Data;
extern os_char_t __START_DSPR_Core1_QM_Data;
extern os_char_t __END_DSPR_Core1_QM_Data;
extern os_char_t __START_DSPR_Core1_ASIL_Data;
extern os_char_t __END_DSPR_Core1_ASIL_Data;
extern os_char_t __START_DSPR_Core2_QM_Data;
extern os_char_t __END_DSPR_Core2_QM_Data;
extern os_char_t __START_DSPR_Core2_ASIL_Data;
extern os_char_t __END_DSPR_Core2_ASIL_Data;
extern os_char_t __START_DSPR_Core3_QM_Data;
extern os_char_t __END_DSPR_Core3_QM_Data;
extern os_char_t __START_DSPR_Core3_ASIL_Data;
extern os_char_t __END_DSPR_Core3_ASIL_Data;

extern os_char_t __START_DSPR_Core0_QM_Init_Data;
extern os_char_t __START_DSPR_Core0_ASIL_Init_Data;
extern os_char_t __START_DSPR_Core1_QM_Init_Data;
extern os_char_t __START_DSPR_Core1_ASIL_Init_Data;
extern os_char_t __START_DSPR_Core2_QM_Init_Data;
extern os_char_t __START_DSPR_Core2_ASIL_Init_Data;
extern os_char_t __START_DSPR_Core3_QM_Init_Data;
extern os_char_t __START_DSPR_Core3_ASIL_Init_Data;

extern os_char_t __START_PSPR_Core0_QM_Data;
extern os_char_t __END_PSPR_Core0_QM_Data;
extern os_char_t __START_PSPR_Core0_ASIL_Data;
extern os_char_t __END_PSPR_Core0_ASIL_Data;
extern os_char_t __START_PSPR_Core1_QM_Data;
extern os_char_t __END_PSPR_Core1_QM_Data;
extern os_char_t __START_PSPR_Core1_ASIL_Data;
extern os_char_t __END_PSPR_Core1_ASIL_Data;
extern os_char_t __START_PSPR_Core2_QM_Data;
extern os_char_t __END_PSPR_Core2_QM_Data;
extern os_char_t __START_PSPR_Core2_ASIL_Data;
extern os_char_t __END_PSPR_Core2_ASIL_Data;
extern os_char_t __START_PSPR_Core3_QM_Data;
extern os_char_t __END_PSPR_Core3_QM_Data;
extern os_char_t __START_PSPR_Core3_ASIL_Data;
extern os_char_t __END_PSPR_Core3_ASIL_Data;

extern os_char_t __START_PSPR_Core0_QM_Init_Data;
extern os_char_t __START_PSPR_Core0_ASIL_Init_Data;
extern os_char_t __START_PSPR_Core1_QM_Init_Data;
extern os_char_t __START_PSPR_Core1_ASIL_Init_Data;
extern os_char_t __START_PSPR_Core2_QM_Init_Data;
extern os_char_t __START_PSPR_Core2_ASIL_Init_Data;
extern os_char_t __START_PSPR_Core3_QM_Init_Data;
extern os_char_t __START_PSPR_Core3_ASIL_Init_Data;

BOARD_NO_STACKPROT_PREFIX
void boardInitCData(void)
{
#if (OS_TOOL==OS_tasking) && (USE_TASKING_INIT)
	_c_init();
#else
	boardZeromem(&__START_DSPR_Core0_QM_Bss, &__END_DSPR_Core0_QM_Bss);
	boardZeromem(&__START_DSPR_Core0_ASIL_Bss, &__END_DSPR_Core0_ASIL_Bss);
	boardZeromem(&__START_DSPR_Core1_QM_Bss, &__END_DSPR_Core1_QM_Bss);
	boardZeromem(&__START_DSPR_Core1_ASIL_Bss, &__END_DSPR_Core1_ASIL_Bss);
	boardZeromem(&__START_DSPR_Core2_QM_Bss, &__END_DSPR_Core2_QM_Bss);
	boardZeromem(&__START_DSPR_Core2_ASIL_Bss, &__END_DSPR_Core2_ASIL_Bss);
	boardZeromem(&__START_DSPR_Core3_QM_Bss, &__END_DSPR_Core3_QM_Bss);
	boardZeromem(&__START_DSPR_Core3_ASIL_Bss, &__END_DSPR_Core3_ASIL_Bss);
	boardZeromem(&__START_PSPR_Core0_QM_Bss, &__END_PSPR_Core0_QM_Bss);
	boardZeromem(&__START_PSPR_Core0_ASIL_Bss, &__END_PSPR_Core0_ASIL_Bss);
	boardZeromem(&__START_PSPR_Core1_QM_Bss, &__END_PSPR_Core1_QM_Bss);
	boardZeromem(&__START_PSPR_Core1_ASIL_Bss, &__END_PSPR_Core1_ASIL_Bss);
	boardZeromem(&__START_PSPR_Core2_QM_Bss, &__END_PSPR_Core2_QM_Bss);
	boardZeromem(&__START_PSPR_Core2_ASIL_Bss, &__END_PSPR_Core2_ASIL_Bss);
	boardZeromem(&__START_PSPR_Core3_QM_Bss, &__END_PSPR_Core3_QM_Bss);
	boardZeromem(&__START_PSPR_Core3_ASIL_Bss, &__END_PSPR_Core3_ASIL_Bss);

	boardMemcpy(&__START_DSPR_Core0_QM_Data, 		&__START_DSPR_Core0_QM_Init_Data, 			&__END_DSPR_Core0_QM_Data);
	boardMemcpy(&__START_DSPR_Core0_ASIL_Data, 		&__START_DSPR_Core0_ASIL_Init_Data, 		&__END_DSPR_Core0_ASIL_Data);
	boardMemcpy(&__START_DSPR_Core1_QM_Data,		&__START_DSPR_Core1_QM_Init_Data,		 	&__END_DSPR_Core1_QM_Data);
	boardMemcpy(&__START_DSPR_Core1_ASIL_Data,	 	&__START_DSPR_Core1_ASIL_Init_Data, 		&__END_DSPR_Core1_ASIL_Data);
	boardMemcpy(&__START_DSPR_Core2_QM_Data,		&__START_DSPR_Core2_QM_Init_Data,		 	&__END_DSPR_Core2_QM_Data);
	boardMemcpy(&__START_DSPR_Core2_ASIL_Data,	 	&__START_DSPR_Core2_ASIL_Init_Data, 		&__END_DSPR_Core2_ASIL_Data);
	boardMemcpy(&__START_DSPR_Core3_QM_Data,		&__START_DSPR_Core3_QM_Init_Data,		 	&__END_DSPR_Core3_QM_Data);
	boardMemcpy(&__START_DSPR_Core3_ASIL_Data,	 	&__START_DSPR_Core3_ASIL_Init_Data, 		&__END_DSPR_Core3_ASIL_Data);

	boardMemcpy(&__START_PSPR_Core0_QM_Data, 		&__START_PSPR_Core0_QM_Init_Data, 			&__END_PSPR_Core0_QM_Data);
	boardMemcpy(&__START_PSPR_Core0_ASIL_Data, 		&__START_PSPR_Core0_ASIL_Init_Data, 		&__END_PSPR_Core0_ASIL_Data);
	boardMemcpy(&__START_PSPR_Core1_QM_Data,		&__START_PSPR_Core1_QM_Init_Data,		 	&__END_PSPR_Core1_QM_Data);
	boardMemcpy(&__START_PSPR_Core1_ASIL_Data,	 	&__START_PSPR_Core1_ASIL_Init_Data, 		&__END_PSPR_Core1_ASIL_Data);
	boardMemcpy(&__START_PSPR_Core2_QM_Data,		&__START_PSPR_Core2_QM_Init_Data,		 	&__END_PSPR_Core2_QM_Data);
	boardMemcpy(&__START_PSPR_Core2_ASIL_Data,	 	&__START_PSPR_Core2_ASIL_Init_Data, 		&__END_PSPR_Core2_ASIL_Data);
	boardMemcpy(&__START_PSPR_Core3_QM_Data,		&__START_PSPR_Core3_QM_Init_Data,		 	&__END_PSPR_Core3_QM_Data);
	boardMemcpy(&__START_PSPR_Core3_ASIL_Data,	 	&__START_PSPR_Core3_ASIL_Init_Data, 		&__END_PSPR_Core3_ASIL_Data);



	boardMemcpy(&__STARTDATA_ANON, &__INITDATA_ANON, &__ENDDATA_ANON);
	boardZeromem(&__STARTBSS_ANON, &__ENDBSS_ANON);

#if ((OS_PROPERTIES_CORE0 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	boardMemcpy(&__STARTDATA_C0, &__INITDATA_C0, &__ENDDATA_C0);
	boardZeromem(&__STARTBSS_C0, &__ENDBSS_C0);
#endif

#if OS_N_CORES_MAX >= 2u
#if ((OS_PROPERTIES_CORE1 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	boardMemcpy(&__STARTDATA_C1, &__INITDATA_C1, &__ENDDATA_C1);
	boardZeromem(&__STARTBSS_C1, &__ENDBSS_C1);
#endif
#endif

#if OS_N_CORES_MAX >= 3u
#if ((OS_PROPERTIES_CORE2 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	boardMemcpy(&__STARTDATA_C2, &__INITDATA_C2, &__ENDDATA_C2);
	boardZeromem(&__STARTBSS_C2, &__ENDBSS_C2);
#endif
#endif

#if OS_N_CORES_MAX >= 4u
#if ((OS_PROPERTIES_CORE3 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	boardMemcpy(&__STARTDATA_C3, &__INITDATA_C3, &__ENDDATA_C3);
	boardZeromem(&__STARTBSS_C3, &__ENDBSS_C3);
	//Add by uif07958
	// extern signed char	__START_DSPR_Core3_QM_Data;
	// extern signed char	__START_DSPR_Core3_QM_Init_Data;
	// extern signed char	__END_DSPR_Core3_QM_Init_Data;
	// boardMemcpy(&__START_DSPR_Core3_QM_Data, &__START_DSPR_Core3_QM_Init_Data, &__END_DSPR_Core3_QM_Init_Data);


#endif
#endif

#if OS_N_CORES_MAX >= 5u
#if ((OS_PROPERTIES_CORE4 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	boardMemcpy(&__STARTDATA_C4, &__INITDATA_C4, &__ENDDATA_C4);
	boardZeromem(&__STARTBSS_C4, &__ENDBSS_C4);
#endif
#endif

#if OS_N_CORES_MAX >= 6u
#if ((OS_PROPERTIES_CORE5 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)
	boardMemcpy(&__STARTDATA_C5, &__INITDATA_C5, &__ENDDATA_C5);
	boardZeromem(&__STARTBSS_C5, &__ENDBSS_C5);
#endif
#endif

	boardMemcpy(&__STARTDATA_SHARED_OS, &__INITDATA_SHARED_OS, &__ENDDATA_SHARED_OS);
	boardZeromem(&__STARTBSS_SHARED_OS, &__ENDBSS_SHARED_OS);

#endif

	/* Initialize stack protection variables, after variable initialization,
	 * so they are not overwritten again.
	*/
	BoardInitCompilerStackProtection();
}

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
