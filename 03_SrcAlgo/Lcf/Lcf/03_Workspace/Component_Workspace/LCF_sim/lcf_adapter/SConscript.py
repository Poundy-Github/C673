"""
Filename                  : scons_common_scripts\sim\sim_adapt\SConscript.py
Description               : SConscript to build sim adapter (Adapter Plugin: dll). 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: sim\sim_adapt\SConscript.py
#
# DESCRIPTION: SConscript to build sim adapter (Adapter Plugin: dll). 
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:06:29CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:06:29CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/sim/sim_adapt/project.pj
# CHANGES:                   Revision 1.12 2017/05/30 13:58:19CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.11 2017/04/27 16:11:07CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.10 2016/07/01 06:18:05CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.9 2015/06/26 08:34:49CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:49 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build sim adapter

#-------------------------
# import
#-------------------------
Import("env", "target", "component_name", "algo_name", "profile", "SconscriptTimesTable")
import os

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('3')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/sim_adapter_config.scfg")

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

#-------------------------
# setup environment
#-------------------------
local_env = env.Clone()
    
# add include file paths
cpp_path = sim_adapter_cpp_path
local_env.Append(CPPPATH = cpp_path)

aditional_path = (Split(externals_include_paths) + 
                  [testing_path_from_sconstruct + "06_Test_Tools/mts/include/"])
local_env.Append(CPPPATH = aditional_path)

# add external library paths
lib_path = [Dir(x).abspath for x in Split(external_lib_paths)]
local_env.Append(LIBPATH = lib_path)

# add library
local_env.Append(LIBS = external_lib)

# add source files
src = sim_adapter_src

#-------------------------
# build DLL
#-------------------------
lib = local_env.SharedLibrary(target, src)

#-------------------------
# return result
#-------------------------

# get absolute file path
cpp_src = abspath_filenames(src)

# get absolute include path
cpp_path = map(lambda x: str(Dir(x).srcnode().abspath), cpp_path)

# get libpath
lib_path = local_env["LIBPATH"]

# get defines
cppdefs = local_env["CPPDEFINES"]

if profile:
    FinishSconscriptEntry()

# return library, source files and include paths
Return(["lib", "cpp_src", "cpp_path", "lib_path", "cppdefs"])