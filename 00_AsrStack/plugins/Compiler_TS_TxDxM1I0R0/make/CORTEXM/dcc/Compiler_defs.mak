#
# \file
#
# \brief AUTOSAR Compiler
#
# This file contains the implementation of the AUTOSAR
# module Compiler.
#
# \version 1.0.9
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2017 - 2021 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


ABS_FILE_SUFFIX   =elf
MAP_FILE_SUFFIX   =map
HEX_FILE_SUFFIX   =mot

PROJECT_BINARY  = $(BIN_OUTPUT_PATH)/$(PROJECT).$(ABS_FILE_SUFFIX)
MAPFILE         = $(BIN_OUTPUT_PATH)/$(PROJECT).$(MAP_FILE_SUFFIX)
HEXFILE         = $(BIN_OUTPUT_PATH)/$(PROJECT).$(HEX_FILE_SUFFIX)

# override globale make default suffixes
ASM_FILE_SUFFIX   =s

# ------ general files (used in common rules)
COMPILER_DIR    = $(TOOLPATH_COMPILER)/Win64/bin
CC              = $(COMPILER_DIR)/dcc.exe
CCLIB           = $(COMPILER_DIR)/dar.exe
ASM             = $(COMPILER_DIR)/dcc.exe
LINK            = $(COMPILER_DIR)/dld.exe
HEX             = $(COMPILER_DIR)/ddump.exe
GCC             = $(PLUGINS_BASE)/Make_$(Make_VARIANT)/tools/gcc/bin/cpp.exe
