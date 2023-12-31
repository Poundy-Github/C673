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


GET_LOC_FILE = $(if $(EXT_LOCATOR_FILE),$(EXT_LOCATOR_FILE),$(LOC_FILE))

####################################################################################################
# build-exe-file
#---------------------------------------------------------------------------------------------------
# Target................: $(PROJECT_BINARY)
#---------------------------------------------------------------------------------------------------
# $@....................: e.g. project.elf
# $(LNK_INC)............: generated linker option file (e.g. <PROJECT_ROOT>/output/make/link.inc)
# $(GET_LOC_FILE).......: linker locator file 
# $(LINK_OPT)...........: linker options
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the call to the linker
####################################################################################################
define build-exe-file
	$(info linking: $(notdir $@))
	$(EB_VERBOSE)$(LINK) -o$@:ELF -o$(basename $@).mot:SREC:4 -o$(basename $@).hex:IHEX:4 -f $(LNK_INC) -d $(GET_LOC_FILE) $(LINK_OPT)\
	&& echo === BUILD DONE ===
endef

####################################################################################################
# build-c-file
#---------------------------------------------------------------------------------------------------
# Target................: see obj_to_cc.mak
#---------------------------------------------------------------------------------------------------
# $@....................: full path to object file e.g. <OBJ_DIR>/Appl_Main.o
# $<....................: full path to source file e.g. <SRC_DIR>/Appl_Main.c
# $(DEPEND_DIR).........: depend directory e.g. <PROJECT_ROOT>/output/depend
# $(MAKE_INC)...........: compiler option file e.g. <PROJECT_ROOT>/output/make/compiler.inc
# $(OBJ_DIR)............: object directory e.g. <PROJECT_ROOT>/output/obj
# $(CC).................: executable for building objects defined in compiler_defs.mak
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the call to the compiler
####################################################################################################
define build-c-file
	$(info compiling: $(notdir $<) $(if $(filter $(MAKE_INC),$(MAKE_INC_DEFAULT)),,(using $(notdir $(MAKE_INC)))))
	$(file > $(DEPEND_DIR)/$(notdir $(basename $@)).d, TEST=compile error in c file $(notdir $<))
	$(EB_VERBOSE)$(CC) --pass-c --dep-file=$(DEPEND_DIR)/$(notdir $(basename $<).d)  -f $(MAKE_INC) -co $< -o $(OBJ_DIR)/$(notdir $(basename $<).o)
endef

####################################################################################################
# build-s-file
#---------------------------------------------------------------------------------------------------
# Target................: see obj_to_cc.mak
#---------------------------------------------------------------------------------------------------
# $@....................: full path to object file e.g. <OBJ_DIR>/cstartup.o
# $<....................: full path to source file e.g. <SRC_DIR>/cstartup.s
# $(DEPEND_DIR).........: depend directory e.g. <PROJECT_ROOT>/output/depend
# $(DEPEND_INC).........: option file for the gcc (contains only -D and -I options)
# $(ASM_INC)............: assembler option file e.g. <PROJECT_ROOT>/output/make/assembler.inc
# $(GCC)................: executable for building dependencies defined in compiler_defs.mak
# $(OBJ_DIR)............: object directory e.g. <PROJECT_ROOT>/output/obj
# $(ASM)................: executable for building objects from assembler source (see compiler_defs.mak)
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the call to the compiler
####################################################################################################
define build-s-file
	$(info assembling: $(notdir $<)) 
	$(file > $(DEPEND_DIR)/$(notdir $(basename $@)).d, CONVERT_MARKER=0)
	$(EB_VERBOSE)$(GCC) -MM @$(DEPEND_INC) $< -MT $(OBJ_DIR)/$(notdir $(basename $@)).o > $(DEPEND_DIR)/$(notdir $(basename $@)).d\
	 && echo. >> $(DEPEND_DIR)/$(notdir $(basename $@)).d
	$(EB_VERBOSE)$(CTC) -f $(DEPEND_INC) --preprocess=p $< > $(basename $@).s
	$(EB_VERBOSE)$(ASM) -f $(ASM_INC) -o $@ $(basename $@).s
endef

####################################################################################################
# build-lib-file
#---------------------------------------------------------------------------------------------------
# Target................: see lib_to_obj.mak
#---------------------------------------------------------------------------------------------------
# $@....................: full path to library file e.g. <LIB_DIR>/Base_src.a
# $+....................: list of object files e.g. <OBJ_DIR>/cstartup.o <OBJ_DIR>/Appl_Main.o
# $(CCLIB)..............: executable for building objects defined in compiler_defs.mak
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the call to the archiver to build a lib from a list of objects
#                       : this is a recursive call
####################################################################################################
define build-lib-file
	$(call SC_CMD_LISTPERFORM,SC_CMD_AR_HELPER,\
		$(info building lib: $(notdir $@)) \
		$(CCLIB) -r -c $@,20,21, $+)
endef

####################################################################################################
# copy-platform-files
#---------------------------------------------------------------------------------------------------
# Target................: flat_src (see flat_src.mak)
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the platform specific files which are copied into the flat build
#                       : directory as last action of the flat_src rule
####################################################################################################
define copy-platform-files
	$(info copy linker files)
	$(EB_VERBOSE)$(CP) $(BOARD_PROJECT_PATH)/*.ldscript $(FLAT_MAK_DIR) >$(DEVNULL)
endef


build-link-inc-file-PROVIDED=TRUE
define build-link-inc-file
    $(info Linking)
    $(file >$@,\
    $(subst \,/,\
    $(subst $(BLANK)-L,$(\n)-L,$(LINK_OPT))\
    $(addprefix $(\n)-L,$(LIB_INCLUDE_PATH))\
    $(addprefix $(\n),$(LINK_ONLY_OBJ) $(LIBRARIES_LINK_ONLY) $(OBJECTS_LINK_ONLY) $(OUTPUT_PATH_LIBS))))
endef

build-prep-file-PROVIDED=TRUE
define build-prep-file
	$(info preprocessing: $(notdir $<))
	$(EB_VERBOSE)$(CTC) --preprocess=p  -f $(DEPEND_INC) $< -o $(LIST_DIR)/$(notdir $(basename $@).$(PREP_FILE_SUFFIX))
endef