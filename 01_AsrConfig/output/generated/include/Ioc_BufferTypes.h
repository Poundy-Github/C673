#ifndef IOC_BUFFERTYPES_H
#define IOC_BUFFERTYPES_H
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
 * MISRAC2012-2) Deviated Rule: 20.1 (advisory)
 * #include directives should only be preceded by preprocessor directives
 * or comments.
 *
 * Reason:
 * The C++ guards allow usage of the OS with a C++-compiler.
*/

/* Deviation MISRAC2012-1, MISRAC2012-2 <*> */

#include <public/Ioc_public_api.h>

#ifdef __cplusplus
}
#endif
#endif  /* IOC_BUFFERTYPES_H */
