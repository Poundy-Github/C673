/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * @file pmic_pf502x_assert.h
 * @brief Assertion macro definition, for debugging purposes.
 *
 * @author nxa22158, nxa23158
 * @version 1.0
 * @date 18-December-2020
 * @copyright Copyright (c) 2021 NXP
 */

#ifndef PMIC_PF502X_ASSERT_H_
#define PMIC_PF502X_ASSERT_H_

#include <stdbool.h>

/** @page misra_violations MISRA-C:2012 violations
 *
 * Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced.
 * The macro is defined to be used by drivers to validate input parameters and can be disabled.
 *
 * Violates MISRA 2012 Advisory Directive 4.9, Function-like macro defined.
 * The macros are used to validate input parameters to driver functions.
 *
 */

/** @page Error_detection_and_reporting Error detection and reporting

PF502X driver can use a mechanism to validate data coming from upper software layers (application code) by performing
a number of checks on input parameters' range or other invariants that can be statically checked (not dependent on
runtime conditions). A failed validation is indicative of a software bug in application code, therefore it is important
to use this mechanism during development.

The validation is performed by using FS_ASSERT macro.
A default implementation of this macro is provided in this file. However, application developers can provide their own
implementation in a custom file. This requires defining the CUSTOM_DEVASSERT symbol with the specific file name in the
project configuration (for example: -DCUSTOM_DEVASSERT="custom_devassert.h")

The default implementation accommodates two behaviors, based on DEV_ERROR_DETECT symbol:
 - When DEV_ERROR_DETECT symbol is defined in the project configuration (for example: -DDEV_ERROR_DETECT), the validation
   performed by the FS_ASSERT macro is enabled, and a failed validation triggers an infinite loop.
   This configuration is recommended for development environments, as it prevents further execution and allows investigating
   potential problems from the point of error detection.
 - When DEV_ERROR_DETECT symbol is not defined, the FS_ASSERT macro is implemented as no-op, therefore disabling all validations.
   This configuration can be used to eliminate the overhead of development-time checks.

It is the application developer's responsibility to decide the error detection strategy for production code: one can opt to
disable development-time checking altogether (by not defining DEV_ERROR_DETECT symbol), or one can opt to keep the checks
in place and implement a recovery mechanism in case of a failed validation, by defining CUSTOM_DEVASSERT to point
to the file containing the custom implementation.
*/

#if defined CUSTOM_DEVASSERT
    /* If the CUSTOM_DEVASSERT symbol is defined, then add the custom implementation */
    #include "custom_devassert.h"
#elif defined (DEV_ERROR_DETECT)
    /* Implement default assert macro */
static inline void FsDevAssert(volatile bool x)
{
    if(x) { } else { for(;;) {} }
}
    #define FS_ASSERT(x) FsDevAssert(x)
#else
    /* Assert macro does nothing */
    #define FS_ASSERT(x) ((void)0)
#endif


#endif /* PMIC_PF502X_ASSERT_H_ */
