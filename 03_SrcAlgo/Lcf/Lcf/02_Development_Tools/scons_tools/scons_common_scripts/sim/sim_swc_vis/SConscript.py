"""
Filename                  : scons_common_scripts\sim\sim_swc_vis\SConscript.py
Description               : SConscript to build sim Visualization Plugin: dll, res-file. 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: sim\sim_swc_vis\SConscript.py
#
# DESCRIPTION: SConscript to build sim Visualization Plugin: dll, res-file. 
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:07:10CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:07:10CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/sim/sim_swc_vis/project.pj
# CHANGES:                   Revision 1.20 2017/11/15 07:51:56CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   [Mainstream]Scons issues fixed with the version of VS
# CHANGES:                   Revision 1.19 2017/09/08 14:49:51CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Error: exception_warning is not defined
# CHANGES:                   Revision 1.18 2017/09/07 12:06:39CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   *.rc file path in current gscons for Mainstream is hardcoded
# CHANGES:                   Revision 1.17 2017/09/07 11:34:30CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Command line too long error
# CHANGES:                   Revision 1.16 2017/05/30 14:03:06CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.15 2017/04/27 16:03:49CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.14 2016/07/01 06:53:28CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.13 2015/06/26 08:34:46CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:47 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build sim visualization

#-------------------------
# import
#-------------------------
Import("env", "target","exception_handler_file_list", "exception_handler", "component_name", "vc_project_name", "folder_name", "build_folder_name", "component_name_for_sim_folder", "algo_name", "algo_name_for_build_folder", "profile", "SconscriptTimesTable", "generate_vs2010")
import os

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('3')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/sim_swc_vis_config.scfg")
execfile(sconscript_dir + "/simenv_config.scfg")
# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/spawn_custom.py").abspath)

# get relative path of a file
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+r"\simenv_config.scfg"

# read gscons_exception_handler
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)
#-------------------------
# setup environment
#-------------------------
local_env = env.Clone()
    
# add include file paths
cpp_path = sim_swc_vis_cpp_path + [testing_path_from_sconstruct + "06_Test_Tools/mts/include/"]
local_env.Append(CPPPATH = cpp_path)

# add library paths
lib_path = [Dir(x).abspath for x in Split(external_lib_paths)]
local_env.Append(LIBPATH = lib_path)

# add library
local_env.Append(LIBS = external_lib)

# add source files
src = sim_swc_vis_src

#-------------------------
# generate res file
#-------------------------
if generate_vs2010:
    local_env['SHELL'] = File(sh_exec).abspath
    local_env['SPAWN'] = spawn

try:
    rc_file_dir
except NameError,e:
    exception_warning(e,exception_handler,msg)
    rc_file_dir = ("#../" + component_name_for_sim_folder + "_sim/" + folder_name + "/")
	
if patch_rc_file:
    patched_rc_file_dir = (build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" + 
                       build_folder_name + "/" + local_env["variant"] + "/")
else:
    copied_rc_file_dir = (build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" + 
                       build_folder_name + "/" + local_env["variant"] + "/")

# setup vsscript environment
res_env = local_env.Clone(# list of scons extensions used
                          tools = ["vsscript"], 
                          # path to scons extensions
                          toolpath = [scons_adas_extensions_path], 
                          # path to vb script folder
                          VS_SCRIPT_DIR = visual_studio_script_dir)
if patch_rc_file:
    patched_rc_file = res_env.ResPatch((patched_rc_file_dir + vc_project_name + ".rc"), 
                                   version_file)
    res_env.AddPreAction(patched_rc_file, Copy(Dir(patched_rc_file_dir).abspath, 
                     File(rc_file_dir + vc_project_name + ".rc").abspath))
    res_file = local_env.RES([File(patched_rc_file[0]).abspath])
else:
    copied_rc_file = res_env.Command(File(copied_rc_file_dir + vc_project_name + ".rc").abspath, File(rc_file_dir + vc_project_name + ".rc").abspath, Copy("$TARGET", "$SOURCE"))
    res_file = local_env.RES([copied_rc_file])

local_env.Append(LIBS = res_file)

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