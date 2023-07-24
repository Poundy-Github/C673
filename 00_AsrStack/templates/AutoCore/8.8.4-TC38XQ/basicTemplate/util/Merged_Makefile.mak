
### merged from Base_BuildEnvironment
################ Permutation test support ################
# publish permutation index as PERMSUFFIX
# default to user-defined "Permutation" id, if non existent, fall back to builtin "__perm_index"
PERMSUFFIX := $(addprefix _,$(firstword $(filter-out [ ] Permutation,$(subst PM_,,$(subst @, ,PM_Permutation [@Permutation@] $(subst __perm_index,Permutation,PM___perm_index [@__perm_index@]))))))
DIFFCHECK_OTHER_REFERENCE_FOLDERS:=$(filter-out $(PROJECT_ROOT)/reference $(PROJECT_ROOT)/references $(PROJECT_ROOT)/reference$(PERMSUFFIX),$(wildcard $(PROJECT_ROOT)/reference*))
ifneq (,$(DIFFCHECK_OTHER_REFERENCE_FOLDERS))
  $(shell rm -rf $(DIFFCHECK_OTHER_REFERENCE_FOLDERS))
endif #ifneq (,$(DIFFCHECK_OTHER_REFERENCE_FOLDERS))

# Folder holding the reference files for diff checks
# path variable is required early so it can be used for dependencies within the remainder of Merged_Makefile.mak
# still can be changed by any later Merged_Makefile.mak fragment
DIFFCHECK_REF_DIR := $(firstword $(realpath $(PROJECT_ROOT)/reference$(PERMSUFFIX) $(PROJECT_ROOT)/reference))

# for permuted tests with dirmerge'd /reference directory
# automatically hard-link the files from /reference/ into the permuted /reference$(PERMSUFFIX)/ when needed
ifneq ($(PROJECT_ROOT)/reference/,$(DIFFCHECK_REF_DIR)/)
$(subst $(PROJECT_ROOT)/reference/,$(DIFFCHECK_REF_DIR)/,$(wildcard $(PROJECT_ROOT)/reference/*)): $(DIFFCHECK_REF_DIR)/% : $(PROJECT_ROOT)/reference/% ; $(info linking $< to $@)-$(CP) -lpux $< $@

endif


-include $(PROJECT_ROOT)/util/project_settings.mak

### merged from Platforms_MemMap_MCAL
#################################################################
# TRESOS2_NOGEN_PLUGINS
# name of XDM files that are merged and therefore not generated by tresos studio
TRESOS2_NOGEN_PLUGINS += MemMap_MCAL


### merged from Platforms_MemMap
#include Merged_Makefile.mak from TARGET and TARGET/DERIVATE
-include $(PROJECT_ROOT)/util/$(TARGET)/Merged_Makefile.mak
-include $(PROJECT_ROOT)/util/$(TARGET)/$(DERIVATE)/Merged_Makefile.mak

#################################################################
# CC_INCLUDE_PATH, CPP_INCLUDE_PATH and ASM_INCLUDE_PATH:
# The paths to own user include files. The paths must be preceded
# by no option . If more than one path is used, you will have
# to separate them by spaces.
#
USER_INCLUDE_PATH  += $(PROJECT_ROOT)/source/config \
                      $(PROJECT_ROOT)/source/config/$(TARGET) \
                      $(PROJECT_ROOT)/source/config/$(TARGET)/$(DERIVATE)


# don't generate code for Os_Test Os_MemoryProtection snippets
TRESOS2_NOGEN_PLUGINS += Os_Test Os_MemoryProtection

### merged from Platforms_Os/MulticoreOs
# Multicore OS has the suffix _DPM for board files
BOARD_SUFFIX := _DPM


#################################################################
# For GNU Make we must explicitly set SHELL to cmd.exe,
# since otherwise it would try to use sh.exe.
SHELL := cmd.exe

####################################################################
# On WinCore, we copy all relevant dlls to the folder containing the
# executable. This way, the dlls are always found automatically and
# the user does not have to adjust the system's %PATH% variable.

# Only on WinCore...
ifeq ($(DERIVATE), WIN32X86)

# We need the Platforms_VARIANT variable, is included from generated
# make file, but may also be overwritte by the project specific
# settings
-include $(PROJECT_ROOT)/output/generated/make/Make_cfg.mak
-include project_settings.mak

# The Platforms plugin
PLATFORMS_DIR := $(TRESOS_BASE)/plugins/Platforms_$(Platforms_VARIANT)
# The compiler binaries and dlls
COMPILER_DIR := $(PLATFORMS_DIR)/tools/mingw-gcc-6.2.0/bin
# The self-extracting compiler archive
COMPILER_ARCH := $(abspath $(COMPILER_DIR)/../MinGW.exe)

# Add the copy rule to the "all" target, so that it is executed during
# compilation (it does not matter when exactly). Specifying this as the
# first rule here also keeps the "all" target the default target.
all: copy_wincore_dlls

# Copy all dlls from the compiler and the platforms plugin to the output/bin folder;
# COMPILER_DIR is definded by makefiles of Compiler plugin
.PHONY: copy_wincore_dlls
copy_wincore_dlls: $(COMPILER_DIR)/gcc.exe
	$(MKDIR) $(BIN_OUTPUT_PATH) && $(CP) $(COMPILER_DIR)/*.dll $(COMPILER_DIR)/../lib/*.dll $(BIN_OUTPUT_PATH)

# Extract the compiler if it does not yet exist
$(COMPILER_DIR)/gcc.exe:
	$(COMPILER_ARCH)

endif

# Use generic implementation of Atomics
# Please set this to 0 if the generic implementation conflicts with
# the settings of your Os (e.g. memory protection)
ATOMICS_USE_GENERIC_IMPL ?= 1

# If ATOMICS_USER_MULTICORE_CASE not found in PREPROCESSOR_DEFINES
# add the default value for generic atomics implementation
ifeq (,$(findstring ATOMICS_USER_MULTICORE_CASE,$(PREPROCESSOR_DEFINES)))
# Assume single core case for complatibility to all targets
PREPROCESSOR_DEFINES += TS_ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_KEY = ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_VALUE ?= 0
endif

