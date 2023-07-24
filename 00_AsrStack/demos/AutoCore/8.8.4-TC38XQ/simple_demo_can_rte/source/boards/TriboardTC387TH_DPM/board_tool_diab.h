/* board_tool_diab.h
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: board_tool_diab.h 29552 2018-11-29 08:53:43Z sash270423 $
*/

#ifndef BOARD_TOOL_DIAB_H
#define BOARD_TOOL_DIAB_H 1

/* __VERSION_NUMBER__ is the version of the compiler as integer.
 * E.g. 5.9.6.3 is 5963
*/
#ifndef __VERSION_NUMBER__
#define __VERSION_NUMBER__ 0
#endif

#define BOARD_TOOL_STACKPROT_MINVERSION 5960

#if __VERSION_NUMBER__ >= BOARD_TOOL_STACKPROT_MINVERSION
#define BOARD_NO_STACKPROT_PREFIX __attribute__((stack_protect(0) ))
#endif

/* Mapping the stack protection guard to RODATA may avoid some trouble during initialization.
 * Be aware the this interferes with the -Xsmall-data option,
 * because the compiler will assume that the guard is part of the SDA, if there's a SDA.
*/
#ifndef BOARD_STACKPROTGUARD_IS_RODATA
#define BOARD_STACKPROTGUARD_IS_RODATA 0
#endif

#define BoardSetOtherCoresA0A1 BoardSetOtherCoresA0A1Diab
void BoardSetOtherCoresA0A1Diab(void);

#define BoardInitCompilerStackProtection BoardInitCompilerStackProtectionDiab
void BoardInitCompilerStackProtectionDiab(void);

#endif /* BOARD_TOOL_DIAB_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
