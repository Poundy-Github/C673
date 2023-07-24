/**
 * \file
 *
 * \brief AUTOSAR Platforms
 *
 * This file contains the implementation of the AUTOSAR
 * module Platforms.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef _PLATFORMS_DEFS_H_
#define _PLATFORMS_DEFS_H_

#include <Platforms_TSPlatforms.h>

#ifndef PLATFORMS_TOOLCHAIN
#error "PLATFORMS_TOOLCHAIN is not defined. Check your Makefiles!"
#endif

/*Supported Toolchains */
#define PLATFORMS_gnu       1
#define PLATFORMS_dcc       2
#define PLATFORMS_multi     3
#define PLATFORMS_tasking   4

#endif /* _PLATFORMS_DEFS_H_ */
