# \file
#
# \brief AUTOSAR Os
#
# This file contains the implementation of the AUTOSAR
# module Os.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 1998 - 2021 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# DEFINITIONS
ifeq ($(Os_CORE_PATH),)
  AutosarOS_CORE_PATH    = $(PLUGINS_BASE)/Os_TS_T16D27M6I1R0
  AutosarOS_LIB_PATH     = $(PLUGINS_BASE)/Os_$(Os_VARIANT)/lib
else
  AutosarOS_CORE_PATH    = $(realpath $(Os_CORE_PATH)/..)/Os_TS_T16D27M6I1R0
  AutosarOS_LIB_PATH     = $(Os_CORE_PATH)/lib
endif

OS_ARCH := TRICORE
OS_CPU := TC38XQ

include $(AutosarOS_CORE_PATH)/make/Os_definitions.mak
#########################
# Editor settings: DO NOT DELETE
# vi:set ts=4:
