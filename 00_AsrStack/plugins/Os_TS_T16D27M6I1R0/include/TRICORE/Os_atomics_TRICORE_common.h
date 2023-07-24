/* Os_atomics_TRICORE_common.h
 *
 * This file contains the definition of the types os_atomic_t
 * and os_atomic_value_t for TRICORE.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_TRICORE_common.h 29552 2018-11-29 08:53:43Z sash270423 $
*/
#ifndef OS_ATOMICS_TRICORE_COMMON_H
#define OS_ATOMICS_TRICORE_COMMON_H 1

#include <Os_types.h>

typedef os_uint32_t os_atomic_t;
typedef os_uint32_t os_atomic_value_t;
#define OS_ATOMICS_VALUE_MAX 4294967295U

#endif /* OS_ATOMICS_TRICORE_COMMON_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
