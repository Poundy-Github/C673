#
# \file
#
# \brief AUTOSAR simple_demo_can_rte
#
# This file contains the implementation of the AUTOSAR
# module simple_demo_can_rte.
#
# \version 1.0.0
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2020 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# Disclaimer:
# >>>  Use of an alternative build environment may  <<<
# >>> lead to non-executable or non-compilable code <<<
# 
# Use the build environment delivered with EB tresos AutoCore to
# execute and compile code. If you use an alternative build
# environment, your EB tresos AutoCore version may generate
# non-executable or non-compilable code.
#################################################################

# provide a default target, if nobody else does
.PHONY: default all

default: all
all:

#################################################################
# path sanitation & sensible default project name if none is specified (predefined or overridden later)
WORK_BASE	:= $(subst \,/,$(WORK_BASE))
TEST_BASE	:= $(subst \,/,$(TEST_BASE))
PROJECT_ROOT	:= $(subst \,/,$(PROJECT_ROOT))
PROJECT_NAME	?= $(lastword $(subst /, ,$(PROJECT_ROOT)))
GEN_OUTPUT_PATH	?= $(PROJECT_ROOT)/output/generated
CUSTOMER_OUTPUT_PATH = $(PROJECT_BASE)/05_Output

# $(info PROJECT_BASE = $(PROJECT_BASE))
# $(info PROJECT_ROOT = $(PROJECT_ROOT))
# $(info PROJECT_NAME = $(PROJECT_NAME))
# $(info GEN_OUTPUT_PATH = $(GEN_OUTPUT_PATH))
# $(info CUSTOMER_OUTPUT_PATH = $(CUSTOMER_OUTPUT_PATH))

#################################################################
# include merged makefile if they exist
-include $(PROJECT_BASE)/04_Script/02_Make/project_settings.mak
-include $(PROJECT_BASE)/04_Script/02_Make/Merged_Makefile.mak
-include $(PROJECT_BASE)/04_Script/02_Make/makefile_header.mak
-include $(PROJECT_BASE)/04_Script/02_Make/makefile_source.mak
#-include $(PROJECT_BASE)/04_Script/02_Make/TriboardTC387TH_DPM.mak
-include $(PROJECT_BASE)/04_Script/02_Make/TRICORE_TC38XQ_Makefile.mak
-include $(PROJECT_BASE)/04_Script/02_Make/TRICORE_TC38XQ_tasking_cfg.mak
-include  $(PROJECT_BASE)/04_Script/02_Make/common.mak

LIBRARIES_LINK_ONLY += $(TOOLPATH_COMPILER)\lib\tc162\libc_fpu.a

#################################################################
# tresos settings
#################################################################
TRESOS2_WORKSPACE_DIR = $(abspath $(PROJECT_ROOT)/..)
TRESOS2_USER_OPTIONS += -data $(TRESOS2_WORKSPACE_DIR)
TRESOS2_PROJECT_NAME = $(PROJECT_NAME)
TRESOS2_USER_OPTIONS += -Dinfo=false
TRESOS2_USER_OPTIONS += -DmergeConfigs=true

# We want project mode, not legacy.
USE_LEGACY_MAKECFG := false



