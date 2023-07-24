/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.1.31 TRICORE/TC38XQ
 * (Build 20210823)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * Date         : 6/30/23 12:21 PM           !!!IGNORE-LINE!!!
 */

#ifndef OS_KCONFIG_H
#define OS_KCONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_KCONF_H 0xe00962e5UL

#define OS_AUTOSAROS_VER 6

#define OS_AUTOSAROS_REV 1

#define OS_AUTOSAROS_CORE_BUILD 20210823

#define OS_AUTOSAROS_ARCH_BUILD 20210823

/*===================================================================
 * Configured Modes
 *==================================================================*/

/* The OS TRACER is configured as follows: */
#define OS_USE_TRACE 0
/*===================================================================
 * Core Mapping
 *==================================================================*/

/* OS_INITCORE tells the build process which core the OS uses (singlecore). */
#define OS_INITCORE 0
/*===================================================================
 * Kernel Type
 *==================================================================*/

/* Defines which trapping mechanism the OS shall use. */
#define OS_KERNEL_TYPE OS_SYSTEM_CALL
/*===================================================================
 * Multicore
 *==================================================================*/

/* Defines the number of CPU cores assigned to EB tresos AutoCore OS. */
#define OS_N_CORES 4
#ifdef __cplusplus
}
#endif
#endif  /* OS_KCONFIG_H */
