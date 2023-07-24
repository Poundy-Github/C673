#################################################################
#
# NAME:     $Id: TriboardTC2X7.mak 23469 2016-01-29 12:33:01Z mist8519 $
#
# FUNCTION: This file is part of the Autosar SC build environment.
#
# Copyright Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#
##################################################################

##################################################################
#
# DEFINITIONS
#
ifeq ($(OS_BOARD_DIR), )
OS_BOARD_DIR=$(BOARD_PROJECT_PATH)
endif

CC_INCLUDE_PATH      += $(OS_BOARD_DIR)
CPP_INCLUDE_PATH     += $(OS_BOARD_DIR)
ASM_INCLUDE_PATH     += $(OS_BOARD_DIR)

##################################################################
#
# Defines for Linker file generation for Memory protected systems
#

OS_GENLD = $(AutosarOS_CORE_PATH)/bin/genld$(OS_HYPHEN)$(CPU).pl
OS_GENLD_OPT += -backend $(OS_TOOLCHAIN)


ifeq ($(OS_TOOLCHAIN),tasking)
OS_GENLD_OPT += -include $(PROJECT_BASE)\04_Script\03_Link\$(DERIVATE)-tasking.ldscript
ifneq ($(filter $(CC_OPT),-DUSE_TASKING_INIT=1),)
OS_GENLD_OPT += -use-tasking-init
endif
endif


ifeq ($(OS_TOOLCHAIN),diab)

# If we need to use an SDA in our demo, we map all user specific data and bss variables to core 0.
# This behaviour is not recommended for real-world applications.
CC_OPT_SMALL_DATA = $(filter -Xsmall-data=%, $(CC_OPT))
ifneq ($(CC_OPT_SMALL_DATA),)
ifneq ($(CC_OPT_SMALL_DATA),-Xsmall-data=0)
OS_GENLD_OPT += -map-all-user-ram-to-core 0 -mix-in-sda
endif	# ifneq ($(CC_OPT_SMALL_DATA),-Xsmall-data=0)
endif	# ifneq ($(CC_OPT_SMALL_DATA),)

endif	# ifeq ($(OS_TOOLCHAIN),diab)


# OS_GENLD_OPT += -include $(OS_BOARD_DIR)\board-$(OS_TOOLCHAIN).ldscript
OS_GENLD_OPT += -include $(PROJECT_BASE)\04_Script\03_Link\board-$(OS_TOOLCHAIN).ldscript

LOC_FILE= $(PROJECT_ROOT)/output/generated/$(OS_ARCH)$(OS_HYPHEN)$(OS_TOOLCHAIN).ldscript

OS_APP_SPECS = \
$(foreach app,$(APPLICATIONS),-app $(app) -core $(OS_CORE_$(app)) $(app)_gen.$(OBJ_FILE_SUFFIX) $(OBJS_$(app)) \
  $(foreach task,$(TASKS_$(app)),-task $(task) $(OBJS_$(task))) \
  $(foreach isr,$(ISRS_$(app)),-isr $(isr) $(OBJS_$(isr))) \
)

$(LOC_FILE): $(OS_GENLD) $(wildcard $(AutosarOS_CORE_PATH)/bin/Genld*.pm)
	$(AutosarOS_CORE_PATH)\bin\cygtools\perl $(OS_GENLD) -o $@ $(OS_GENLD_OPT) $(OS_APP_SPECS) -numcores $(OS_N_CORES_MAX) -corecsas $(OS_TRICORE_NCSA_LIST)
