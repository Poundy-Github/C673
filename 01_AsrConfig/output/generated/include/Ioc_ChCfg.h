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
 * Date         : 2/28/23 3:54 PM           !!!IGNORE-LINE!!!
 */

#ifndef IOC_CHCFG_H
#define IOC_CHCFG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 5.1 (required)
 * External identifiers shall be unique.
 *
 * Reason:
 * These identifiers depend on the channel names chosen by the user.
 *
 * MISRAC2012-2) Deviated Rule: 8.6 (required)
 * An identifier with external linkage shall have exactly one
 * external definition.
 *
 * Reason:
 * False positive.
 * There are generated C files for each channel, which define these symbols.
 *
 * MISRAC2012-3) Deviated Rule: 20.1 (advisory)
 * #include directives should only be preceded by preprocessor directives
 * or comments.
 *
 * Reason:
 * The C++ guards allow usage of the OS with a C++-compiler.
 *
 * MISRAC2012-4) Deviated Rule: 11.9 (required)
 * The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 * Reason:
 * The macro IOC_OFFSETOF uses the literal constant 0 as a pointer to an imaginary object
 * with structure type, which allows to determine the offset of one of its fields.
 * The value 0 is necessary to make this offset relative to the start address of an
 * object with that structure type. Furthermore, the null pointer is never dereferenced
 * in the calculation.
*/

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <*> */

#include <private/Ioc_tool.h>
#include <private/Ioc_configinterface.h>
#include <Ioc_BufferTypes.h>
#include <Os_config.h>

#define IOC_CFG_NCHANNELS 0

/*===================================================================
 * Configuration Initializer
 *==================================================================*/

#define IOC_CHANNEL_CONFIGURATIONS {  \
}
#ifdef __cplusplus
}
#endif
#endif  /* IOC_CHCFG_H */
