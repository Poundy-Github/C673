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


####################################################################################################
# build-exe-file
#---------------------------------------------------------------------------------------------------
# Target................: $(PROJECT_BINARY)
#---------------------------------------------------------------------------------------------------
# $@....................: e.g. project.exe
# $(LINK_OPT)...........: list of linker options
# $(OUTPUT_PATH_LIBS)...: list of libraries
# $(LINK_ONLY_OBJ)......: list of objects
# $(LIBRARIES_LINK_ONLY): list of external libs (no source availabe)
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the call to the linker
####################################################################################################
define build-exe-file
	$(EB_VERBOSE)$(call runIn,$(OUTPUT_DIR)/,$(LINK) @$(LNK_INC) -o $@ -Wl$(COMMA)-( -lwinmm  $(OUTPUT_PATH_LIBS) $(LIBRARIES_LINK_ONLY) $(TOOLPATH_COMPILER)/lib/w32api/libwinmm.a $(TOOLPATH_COMPILER)/lib/gcc/i686-pc-cygwin/4.0.4/libboundscheck.a -Wl$(COMMA)-) $(LINK_OPT_POST))\
	&& echo === BUILD DONE ===
endef

define build-postbuild-file
	$(EB_VERBOSE)$(LINK) -r -nostartfiles -nodefaultlibs -nostdlib -o $(basename $@).temp $(POSTBUILD_OBJECTS_OUT)\
	&& $(OBJCOPY) -S -X -O srec $(basename $@).temp $(basename $@).srec\
	&& $(OBJCOPY) -S -X -O binary $(basename $@).temp $@\
	&& echo === POST BUILD DONE ===
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
# $(CPP)................: executable for building dependencies defined in compiler_defs.mak
# $(CC).................: executable for building objects defined in compiler_defs.mak
#---------------------------------------------------------------------------------------------------
# Desciption............: defines the call to the compiler
####################################################################################################
define	build-c-file
	$(info Compiling: $(notdir $<) $(if $(filter $(MAKE_INC),$(MAKE_INC_DEFAULT)),,(using $(notdir $(MAKE_INC)))))
	$(file > $(DEPEND_DIR)/$(notdir $(basename $@)).d, DUMMY_VAR=compile error in c file $(notdir $<))
	$(EB_VERBOSE)$(CC) -pipe @$(MAKE_INC) -MMD -MF $(DEPEND_DIR)/$(notdir $(basename $@)).d -MT $$(OBJ_DIR)/$(notdir $(basename $@)).o -c -o $(OBJ_DIR)/$(notdir $(basename $@)).o $<
endef

####################################################################################################
# build-s-file
#---------------------------------------------------------------------------------------------------
# Target................: see obj_to_cc.mak
#---------------------------------------------------------------------------------------------------
# $@....................: full path to object file e.g. <OBJ_DIR>/cstartup.o
# $<....................: full path to source file e.g. <SRC_DIR>/cstartup.s
#---------------------------------------------------------------------------------------------------
# Desciption............: for windows this is just a stub
####################################################################################################
define	build-s-file
	$(info Assembling: $(notdir $<))
	$(file > $(OBJ_DIR)/$(notdir $(basename $@)).o, dummy_file)
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
		$(EB_VERBOSE)cd $(call fixCmdPaths,$(OBJ_DIR)) && $(CCLIB) crus $@,50,51, $(subst $(OBJ_DIR)/,,$?))
endef

