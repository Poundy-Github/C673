"""
Filename                  : scons_common_scripts\sim\sim_sconscript\SConscript_sim.py
Description               : SConscript to build simulation DLLs and Visual studio IDE. It calls all other SConscripts related 
							to PC simulation targets. Those Sconscript's are defined in sconstruct_config.scfg. 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: sim\sim_sconscript\SConscript_sim.py
#
# DESCRIPTION: SConscript to build simulation DLLs and Visual studio IDE. It calls all other SConscripts related 
#              to PC simulation targets. Those Sconscript's are defined in sconstruct_config.scfg. 
#
# INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
#
# CREATION DATE: 2014/07/29
#
# LAST CHANGE:      $Date: 2021/12/13 19:06:57CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_sim.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:06:57CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/sim/sim_sconscript/project.pj
# CHANGES:                   Revision 1.25 2017/10/10 06:45:03CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   SCONS topics to take care in next release
# CHANGES:                   Revision 1.24 2017/05/30 14:02:14CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.23 2017/04/27 16:02:24CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.22 2016/10/18 13:14:46CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Visual studio 2010 support fails
# CHANGES:                   Revision 1.21 2016/10/05 14:26:58CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   updated for the implementation visual studio 2010
# CHANGES:                   Revision 1.20 2016/07/12 06:48:40CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons.
# CHANGES:                   Revision 1.19 2016/07/01 06:51:01CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.18 2016/05/13 11:56:07CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   1.17 revision was checked in by mistake from Andreas Jhanke. 1.18 is same as 1.16
# CHANGES:                   Revision 1.17 2016/04/21 17:45:50CEST Jahnke, Andreas (uidw8971) 
# CHANGES:                   Labelconverter reads parameter Parameter.rroixoffset, Parameter.rroiyoffset to get rid off dirty hacks (defines in source code)
# CHANGES:                   Revision 1.16 2015/06/26 08:34:53CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:53 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# Note:
# 1. When there is more DLL besides sim_swc, sim_swc_vis and sim_adapter, add calling to
#    SConscript_simenv.py located inside the folder of the additional DLL.
# 2. Update the project list in the solution.
#    for example: projects = [sim_swc_ide[0], sim_swc_vis_ide[0], sim_adapt_ide[0], sim_other_ide[0]].
# ----------------------------------------------------------------------------------------

# SConscript to build simulation DLLs

#-------------------------
# import/export
#-------------------------
import os
Import("skip_ide_generation","exception_handler_file_list", "exception_handler", "scons_arguments", "component_name", "algo_name_list", "build_from_ide", "thread_number", "use_shared_sconscript", "custom_sim_copy", "help_dict", "profile", "SconscriptTimesTable", "generate_vs2010", "project_name")
if not skip_ide_generation:
    Import("tblds", "tsrcs", "tcppp", "talias", "tcppdefs")

Export("skip_ide_generation", "scons_arguments", "component_name", "build_from_ide", "use_shared_sconscript", "custom_sim_copy")

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('1')

#-------------------------
# read configuration file
#-------------------------
# read file list containing source files and include paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)
execfile(File("#sconstruct_config.scfg").abspath)

# read gscons_exception_handler
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)
msg="in sconstruct_config.scfg"
#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

if generate_vs2010:
    msvc_version = "10.0"
    msvc_tool = "msvs-patched2010"
else:
    msvc_version = "8.0"
    msvc_tool = "msvs-patched"
#-------------------------
# setup pc_env environment
#-------------------------
pc_env = Environment(# list of scons extensions used
                    tools = ["msvc", msvc_tool, "mslib", "mslink", 
                             "msvc-addon", "doxygen"], 
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path], 
                    MSVS_USE_MFC_DIRS = 1, 
                    TARGET_ARCH = "X86",
                    # path to doxygen tool
                    DOXYGEN_TOOLS = doxygen_dir,
                    # manifest files need to be included in the dlls/apps
                    WINDOWS_EMBED_MANIFEST = True, 
                    # use Visual Studio 2005
                    MSVC_VERSION = msvc_version,
                    # specify processor for scons build
                    BUILD_TARGET = "SIM")

# If cantata is installed, cl.exe and link.exe will have been
# renamed to ms_cl.exe and ms_link.exe.
# Cantata outputs a banner to stdout that cannot be suppressed -
# this causes problems when preprocessing files in non-unit test
# builds. Therefore, if Cantata is installed, we set the root PC
# environment to use the original ms exe's.

for dir in cantata_tool_dir:
    dir_abspath = Dir(dir).abspath
    if FindFile("cantpp.exe", dir_abspath):
        pc_env['CC'] = 'ms_cl'
        break
        
#---------------------------------------------------------
# setup pc_env64 environment for 64bit target architecture
#---------------------------------------------------------
pc_env64 = Environment(# list of scons extensions used
                       tools=["msvc", msvc_tool, "mslib", "mslink", 
                             "msvc-addon", "doxygen"], 
                       # path to scons extensions
                       toolpath=[scons_adas_extensions_path], 
                       MSVS_USE_MFC_DIRS=1,
                       TARGET_ARCH='x86_64',
                       # path to doxygen tool
                       DOXYGEN_TOOLS = doxygen_dir,
                       # manifest files need to be included in the dlls/apps
                       WINDOWS_EMBED_MANIFEST = True,
                       # use Visual Studio 2005
                       MSVC_VERSION = msvc_version,
                       # specify processor for scons build
                       BUILD_TARGET = 'SIM')        


#---------------------------------------------------------
# build pc sim targets
#--------------------------------------------------------- 
for algo_name in algo_name_list: 
    #-----------------------------------------------------
    # I. call all pc sim SConscript-simenv's under "#../xxx_sim" 
    #----------------------------------------------------- 
    # copy environment in order to add algo-specific defines
    local_pc_env = pc_env.Clone()
    try: 
        # check whether there are project lists depending on the algo_name
        project_list = sim_proj_list[algo_name]
        define_list = sim_proj_list_defines[algo_name]
        local_pc_env.Append(CPPDEFINES = define_list)
    except TypeError:
        project_list = sim_proj_list
    except NameError,e:
        exception_warning(e,exception_handler,"\nEither define it in xxx/sconstruct_config.scfg according to your needs or remove xxx_sim/SConscript_sim.py from your sandbox please!")
        
        project_list = []
        
    for project in project_list:
        result = SConscript(project + "/SConscript_simenv.py", 
                   exports = {"component_name" : component_name, "env" : local_pc_env, "algo_name" : algo_name})
        if result and not skip_ide_generation:
            [tblds, tsrcs, tcppp, talias, cppdefs] = update_vs_data(tblds, tsrcs, tcppp, talias, tcppdefs,
                                                           result[0], result[1], result[2], result[3], result[4])       
            
    #-----------------------------------------------------------------------------
    # II. call pc sim SConscript-simenv's which are NOT located under "#../xxx_sim" (="utilities")
    #-----------------------------------------------------------------------------
    # A) sim32 targets    
    try:
        # check whether there are project lists depending on the algo_name
        project_list_utils32 = utils_proj_list[algo_name]
    except TypeError:
        # check whether there are any utilities with single algo to be built
        project_list_utils32 = utils_proj_list
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        project_list_utils32 = None

    # check whether the folder is present
    if project_list_utils32:
        if os.path.isdir(Dir(project_list_utils32[0] + "../").abspath): 
            print "\nUtilities for " + algo_name + " found!\n"     
            for project in project_list_utils32:
                result = SConscript(project + "/SConscript_simenv.py", 
                           exports = {"component_name" : component_name, "env" : local_pc_env, "algo_name" : algo_name})
                if result and not skip_ide_generation:
                    [tblds, tsrcs, tcppp, talias, cppdefs] = update_vs_data(tblds, tsrcs, tcppp, talias, tcppdefs,
                                                                   result[0], result[1], result[2], result[3], result[4])
        else:
            print "\nNo utilities for " + algo_name + " found!\n"
        
    # 2. sim64 targets 
    try:
        # check whether there are project lists depending on the algo_name
        project_list_utils64 = utils64_proj_list[algo_name]
    except TypeError:
        # check whether there are any utilities with single algo to be built
        project_list_utils64 = utils64_proj_list
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        project_list_utils64 = None
    if project_list_utils64:
        if os.path.isdir(Dir(project_list_utils64[0] + "../").abspath):
            for project in project_list_utils64:
                result = SConscript(project + "/SConscript_simenv.py", 
                           exports = {"component_name" : component_name, "env" : pc_env64, "algo_name" : algo_name})
                if result and not skip_ide_generation:
                    [tblds, tsrcs, tcppp, talias, cppdefs] = update_vs_data(tblds, tsrcs, tcppp, talias, tcppdefs,
                                                             result[0], result[1], result[2], result[3], result[4])

    #-------------------------
    # execute private utility SConscript
    #-------------------------
    if os.path.isfile(File("#../../" + component_name + "_utils/SConscript_utils.py").abspath):
        result = SConscript("#../../" + component_name + "_utils/SConscript_utils.py", 
                           exports = {"component_name" : component_name, "algo_name" : algo_name})

#-------------------------
# build ms visual studio solution
#-------------------------
if not skip_ide_generation:
    # scons command for visual studio
    ide_scons_cmd = (r"cd $SCONS_DIR && scons.bat -Q -j " + str(thread_number) + r" $SCONS_ARGUMENTS")
    # sed filter for converting dsp/gcc diagnostic messages to VS format for easy double clicking and jumping to error
    diagnostics_sed_filter_pipe_cmd =  r" 2>&1 | ..\..\..\02_Development_Tools\scons_tools\gnutools\sed.exe -e " + '"' + r"s/:\([0-9]\+\):[0-9]\+:/(\1) : /" + '"' + " -e " + '"' + r"s/, line \([0-9]\+\):/(\1) : /" + '"'
    # Andre Fischer-Ext (uidg5297) - 2014-09-02:
    # ------------------------------------------
    # scoons.bat generates text file errorlevel.txt which provides the scons error level
    # vs needs to read this in order to report the error level/the build status correctly.
    report_error_level = r"& if exist errorlevel.txt (for /f %%A in (errorlevel.txt) do exit /b %%A)"
    
    if not custom_sim_copy:
        vc_scons_arguments = "skip_ide_generation=1" + " " + "build_from_ide=1" + " " + "build_from_vs=1" + " " + scons_arguments
    else:
        vc_scons_arguments = "skip_ide_generation=1" + " " + "build_from_ide=1" + " " + "build_from_vs=1" + " " + "custom_sim_copy=1" + " " + scons_arguments

    try:
        # add additional sim_targets possibly specified in sconstruct_config.scfg and corresponding dummy define sets
        talias = sim_target_list + talias
        tcppdefs = len(sim_target_list) * [['']] + tcppdefs
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        pass

    # add standard build targets for pc sim and ecu algo plus corr. dummy define sets
    std_alias = ['all', 
                 component_name + "_sim_pc_release", 
                 component_name + "_sim_pc_debug", 
                 component_name + "_sim_pc",
                 component_name + "_algo_release",
                 component_name + "_algo_debug",
                 component_name + "_algo"
                 ]
    talias   = talias + std_alias
    tcppdefs = tcppdefs + len(std_alias) * [['']]

    # build visual studio project  
    sln = pc_env.MSVSProject(target = (workspace_path_from_sconstruct + "/00_Projects/" + project_name + "/" + component_name.upper() + "_sim/" + 
                           component_name + pc_env.subst("$MSVSPROJECTSUFFIX")),
                           # define sources
                           srcs = tsrcs,
                           # forward nodes of targets to be built
                           blds = tblds,
                           # define buildtargets, variants, and corr. define sets
                           buildtarget = talias,
                           variant = talias,
                           cppdefs = tcppdefs,
                           # define scons command
                           MSVSSCONS = ide_scons_cmd, 
                           # folder containing SConstruct
                           SCONS_DIR = Dir("#").abspath, 
                           # scons command argument
                           SCONS_ARGUMENTS = vc_scons_arguments, 
                           # define additional cmd arguments
                           cmdargs = diagnostics_sed_filter_pipe_cmd + report_error_level,
                           # add CPPPATH
                           CPPPATH = unique(tcppp)
                           )
    
    generate_alias(component_name + "_ide_msvc", sln, component_name + ':ide:msvc', ['MSVC project'])
    generate_alias(component_name + "_ide", sln, component_name + ':ide')
    generate_alias("all", sln, component_name)
if profile:
    FinishSconscriptEntry()     