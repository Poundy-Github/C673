# SConscript to build simulation DLLs

#-------------------------
# import
#-------------------------
import os
Import("skip_ide_generation", "scons_arguments", "component_name", "build_from_ide")

#-------------------------
# read configuration file
#-------------------------
# read file list containing source files and include paths
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

#-------------------------
# setup environment
#-------------------------
pc_env = Environment(# list of scons extensions used
                    tools = ["msvc", "msvs-patched", "mslib", "mslink", 
                             "msvc-addon", "doxygen", "fingerprint"], 
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path], 
                    MSVS_USE_MFC_DIRS = 1, 
                    TARGET_ARCH = "X86",
                    # path to doxygen tool
                    DOXYGEN_TOOLS = doxygen_dir,
                    # manifest files need to be included in the dlls/apps
                    WINDOWS_EMBED_MANIFEST = True, 
                    # use Visual Studio 2005
                    MSVC_VERSION = "8.0",
                    # specify processor for scons build
                    BUILD_TARGET = "SIM")

# If cantata is installed, cl.exe and link.exe will have been
# renamed to ms_cl.exe and ms_link.exe.
# Cantata outputs a banner to stdout that cannot be suppressed -
# this causes problems when preprocessing files in non-unit test
# builds. Therefore, if Cantata is installed, we set the root PC
# environment to use the original ms exe's.

try: # for scons_tools >= Release 1.3.0
    for dir in cantata_tool_dir:
        dir_abspath = Dir(dir).abspath
        if FindFile("cantpp.exe", dir_abspath):
            pc_env['CC'] = 'ms_cl'
            break
except NameError: # earlier versions of scons_tools
    catd60 = Dir( cantata_tool_dir_6_0 ).abspath
    catd62 = Dir( cantata_tool_dir_6_2 ).abspath

    if FindFile("cantpp.exe", catd62):
        pc_env['CC'] = 'ms_cl'
    else:    
        if FindFile("cantpp.exe", catd60):
            pc_env['CC'] = 'ms_cl'

Export("skip_ide_generation", "scons_arguments", "component_name", "build_from_ide")

sim_variant_list = []
#-------------------------
# call sim_swc SConscript-simenv
#-------------------------
sim_swc_ide = SConscript("sim_swc_" + component_name + "/SConscript_simenv.py", 
           exports = {"component_name" : component_name, "env" : pc_env, "algo_name" : component_name})
if not skip_ide_generation:
    sim_variant_list.extend(sim_swc_ide[1])
    
#-------------------------
# call sim_adapt SConscript-simenv
#-------------------------
# sim_adapt_ide = SConscript(component_name + "_adapter/SConscript_simenv.py", 
           # exports = {"component_name" : component_name, "env" : pc_env, "algo_name" : component_name})
# if not skip_ide_generation:
    # sim_variant_list.extend(sim_adapt_ide[1])
    
#-------------------------
# build ms visual studio solution
#-------------------------
if not skip_ide_generation:
    sim_variant_list = unique(sim_variant_list)
    
    sim_sln = pc_env.MSVSSolution(# solution name
                 target = (build_dir + "/algo/" + component_name + "_sim/pc/" + 
                           component_name + "_sim" + pc_env.subst("$MSVSSOLUTIONSUFFIX")),
                 # project list included in solution
                 projects = [sim_swc_ide[0]], 
                 # build variant
                 variant = sim_variant_list)
    Alias(component_name + "_ide_msvc", sim_sln)
    Alias(component_name + "_ide", sim_sln)
    Alias("all", sim_sln)