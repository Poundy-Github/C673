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
TOOLPATH_COMPILER ?= C:\Tasking\ctc


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
CC_OPT += -Wa-gAHLs
CC_OPT += -Wa-Ogs
CC_OPT += -Wa--error-limit=42
CC_OPT += --emit-locals=-equ,-symbols
CC_OPT += --iso=99
CC_OPT += --eabi=bchnsw
CC_OPT += --integer-enumeration
CC_OPT += --language=-comments,-gcc,+volatile,-strings
CC_OPT += --switch=auto
CC_OPT += --align=4
CC_OPT += --default-near-size=0
CC_OPT += --default-a0-size=0
CC_OPT += --default-a1-size=0
CC_OPT += -O2ROPYG
CC_OPT += --tradeoff=0
CC_OPT += -g
CC_OPT += --source
CC_OPT += -DOS_TRICOREARCH=OS_TRICOREARCH_162
CC_OPT += -DCOMPILERCFG_EXTENSION_MCAL_FILE
CC_OPT += -DUSE_TASKING_INIT=0
CC_OPT += -DOS_TOOL=OS_tasking
CC_OPT += -DOSB_TOOL=OSB_tasking
CC_OPT += -DOS_ARCH=OS_TRICORE
CC_OPT += --fp-model=cFlnrSTz
#################################################################

# Define the default options for the assembler.

ASM_OPT += --core=tc1.6.2
ASM_OPT += -gAHLs
ASM_OPT += --emit-locals=-equs,-symbols
ASM_OPT += --error-limit=42
ASM_OPT += -Ogs
ASM_OPT += -mt


#################################################################
# Define the options for the linker

LINK_OPT += -I$(PROJECT_BASE)/04_Script/03_Link
LINK_OPT += -M$(MAP_FILE)
LINK_OPT += --library=fp_fpu
LINK_OPT += --user-provided-initialization-code
LINK_OPT += --library=rt


#################################################################
# General path setup

# Path where the map file should get generated
MAP_FILE = $(BIN_OUTPUT_PATH)\$(PROJECT).map

# Path where the output file should get generated
OUT_FILE = $(BUILD_DIR)\$(PROJECT).out


# Linker archive options: insert-replace/create/update
AR_OPT += -rcu