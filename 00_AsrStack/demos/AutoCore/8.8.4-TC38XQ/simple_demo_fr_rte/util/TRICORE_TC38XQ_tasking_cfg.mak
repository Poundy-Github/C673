# \file
#
# \brief AUTOSAR Os
#
# This file contains the implementation of the AUTOSAR
# module Os.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 1998 - 2018 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# Toolchain settings
#################################################################
# TOOLPATH_COMPILER:
# Path to the tasking compiler and linker.
# It is checked, if an environment variable
# $(SSC_TRICORE_277_TOOLPATH_COMPILER) exists.
# If so, this variable is taken for TOOLPATH_COMPILER
# If it doesn't exist, TOOLPATH_COMPILER must be set by user
# (modify command in line following the ifeq).
#
# For example:
TOOLPATH_COMPILER ?= 


#################################################################
# TASKING_MODE:
#
# To compile a C source file the C compiler and the assembler must
# be called. This can be done by one call of the control program cctc
# or by a call of the compiler ctc and the assembler astc. The variable
# TASKING_MODE allows to select the kind of the tool chain call.
# Valid values are CONTROL_PROGRAM and COMPILER_ASSEMBLER.
TASKING_MODE = CONTROL_PROGRAM

#################################################################
# Define the options for the compiler.
#

CC_OPT += --core=tc1.6.2
CC_OPT += --iso=99
CC_OPT += -O2
CC_OPT += --eabi=BCFHNSW
CC_OPT += -AGKpvX
CC_OPT += --tradeoff=2
CC_OPT += --fp-model=1 
CC_OPT += --switch=auto
CC_OPT += --integer-enumeration
CC_OPT += --default-near-size=0
CC_OPT += --global-type-checking
CC_OPT += -DUSE_TASKING_INIT=1
CC_OPT += -DOSB_TOOL=OSB_tasking
#################################################################

# Define the default options for the assembler.

ASM_OPT += --core=tc1.6.2
ASM_OPT += --list-format=1
ASM_OPT += --optimize=gs


#################################################################
# Define the options for the linker

LINK_OPT += -OcLtXY
LINK_OPT += --core=mpe:vtc
LINK_OPT += --global-type-checking
LINK_OPT += -lc
 
#################################################################
# General path setup

# Path where the map file should get generated
MAP_FILE = $(BIN_OUTPUT_PATH)\$(PROJECT).map

# Path where the output file should get generated
OUT_FILE = $(BUILD_DIR)\$(PROJECT).out


# Linker archive options: insert-replace/create/update
AR_OPT += -rcu