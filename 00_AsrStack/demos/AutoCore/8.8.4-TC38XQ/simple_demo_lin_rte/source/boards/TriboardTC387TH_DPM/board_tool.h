/* board_tool.h
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board_tool.h 29552 2018-11-29 08:53:43Z sash270423 $
*/

#ifndef BOARD_TOOL_H
#define BOARD_TOOL_H 1

#include <Os_defs.h>
#include <Os_types.h>

#if (OS_TOOL == OS_diab)
#include <board_tool_diab.h>
#elif (OS_TOOL == OS_tasking)
/* Currently there's nothing to include. */
#elif (OS_TOOL == OS_gnu)
/* Currently there's nothing to include. */
#else
#error "Unsupported toolchain"
#endif

/* We explicitly set sections for these symbols, in case customers want to use the "small data area" (SDA)
 * feature of their compiler. This way the compiler won't try to access them via the SDA base address.
*/
#define BOARD_LINKERSYMBOL_BSS(id) \
	extern os_char_t \
		OS_SECTION_ATTRIB_PRE_DECL(.bss.id) \
		id \
		OS_SECTION_ATTRIB_POST_DECL(.bss.id)
#define BOARD_LINKERSYMBOL_DATA(id) \
	extern os_char_t \
		OS_SECTION_ATTRIB_PRE_DECL(.data.id) \
		id \
		OS_SECTION_ATTRIB_POST_DECL(.data.id)

/* BOARD_NO_STACKPROT_PREFIX prevents that stack checks are injected into a function.
 * If the stack protection guard value is a variable (e.g. in .bss section)
 * instead of a constant (e.g. .rodata section), we have to switch off stack protection
 * for the function which initialize the guard value variable and for those which call this function,
 * because otherwise the stack check in these functions would fail.
*/
#ifndef BOARD_NO_STACKPROT_PREFIX
#define BOARD_NO_STACKPROT_PREFIX
#endif

/* Global address registers A0 and A1 are reserved for the compiler.
 * Depending on compiler and compiler options these registers need to be initialized.
 * boardSetOtherCoresA0A1 initializes them on all cores except core 0.
 * These cores must not be running.
 * This function must be called on core 0.
*/
#ifndef BoardSetOtherCoresA0A1
#define BoardSetOtherCoresA0A1() do { } while (0)
#endif

/* BoardInitCompilerStackProtection initializes the stack protection environment of a compiler,
 * if necessary and supported.
*/
#ifndef BoardInitCompilerStackProtection
#define BoardInitCompilerStackProtection() do { } while (0)
#endif

#endif /* BOARD_TOOL_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
