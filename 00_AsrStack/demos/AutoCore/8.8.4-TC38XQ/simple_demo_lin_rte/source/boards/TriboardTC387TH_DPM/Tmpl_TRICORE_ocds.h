/* Tmpl_TRICORE_ocds.h
 *
 * This file declares some TRICORE OCDS macros or functions.
 * OCDS means "On-Chip Debug Support".
 *
 * (c) Elektrobit Automotive GmbH
*/
#ifndef TMPL_TRICORE_OCDS_H
#define TMPL_TRICORE_OCDS_H

#include <Os_types.h>
#include <Os_cpu.h>

#if (OS_TRICOREARCH == OS_TRICOREARCH_16EP)
/* On TC2xx (TC 1.6.1), it doesn't seem to matter whether a debugger is attached or not.
 * No adverse effects were observed when setting the STMs to debug mode although no debugger is attached.
*/
#define Tmpl_Ocds_MaySetStmsToDebugMode() OS_TRUE

#elif (OS_TRICOREARCH == OS_TRICOREARCH_162)
#define TMPL_CBS_BASE                       OS_U(0xF0000400)
#define TMPL_CBS_OSTATE_OFFS                OS_U(0x00000080) /*< Offset of the OCDS status register. */
#define TMPL_CBS_OSTATE_REG                 (*(os_reg32_t*)(TMPL_CBS_BASE + TMPL_CBS_OSTATE_OFFS))
#define TMPL_CBS_OSTATE_OEN_FLAG            OS_U(0x00000001) /*< This bit indicates whether OCDS is enabled. */

/* Tmpl_IsOcdsEnabled() - tells you whether debugging is enabled. */
#define Tmpl_IsOcdsEnabled() ((TMPL_CBS_OSTATE_REG & TMPL_CBS_OSTATE_OEN_FLAG) == TMPL_CBS_OSTATE_OEN_FLAG)

/* Tmpl_Ocds_MaySetStmsToDebugMode() - tells you whether you are allowed to set your STMs to debug mode.
 *
 * The STM.OCS register can only be written when the OCDS is enabled.
 * On TC3xx (TC 1.6.2) writing this register cause some fault which either stops the processor or the STM.
*/
#define Tmpl_Ocds_MaySetStmsToDebugMode() Tmpl_IsOcdsEnabled()


#else
#error "Unexpected OS_TRICOREARCH"
#endif


#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
