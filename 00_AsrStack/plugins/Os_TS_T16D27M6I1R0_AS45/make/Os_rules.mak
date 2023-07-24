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

# redirect AS45 to common OS plugin
ifeq ($(Os_CORE_PATH),)
  include $(PLUGINS_BASE)/Os_TS_T16D27M6I1R0/make/Os_rules.mak
else
  include $(realpath $(Os_CORE_PATH)/..)/Os_TS_T16D27M6I1R0/make/Os_rules.mak
endif
