"""
Filename                  : scons_common_scripts\algo\lib\SConscript.py
Description               : SConscript to build sdl files, cdl files for pc simulation and ECU and PC libraries.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: lib\SConscript.py
#
# DESCRIPTION: SConscript to build sdl files, cdl files for pc simulation and ECU and PC libraries.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:20CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:20CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/algo/lib/project.pj
# CHANGES:                   Revision 1.67 2017/09/07 11:35:31CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Command line too long error
# CHANGES:                   Revision 1.66 2017/05/30 11:30:45CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.65 2017/04/27 16:13:20CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.64 2017/03/31 08:48:53CEST Singh, Vishal (uidj9083) 
# CHANGES:                   stoped ployspace 2016a support
# CHANGES:                   Revision 1.63 2016/11/30 10:16:55CET Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for Polyspace 2016a
# CHANGES:                   Revision 1.62 2016/08/02 07:47:14CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Updated for the issue 487102 & RO 488349
# CHANGES:                   Revision 1.61 2016/07/28 10:59:07CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons
# CHANGES:                   Revision 1.60 2016/07/12 06:00:12CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and exception is handled in GSCons
# CHANGES:                   Revision 1.59 2016/06/30 08:17:54CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.58 2016/03/25 08:11:45CET Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Polyspace integration for all cores C66xx, ARP32, A15, A8, M3 and M4
# CHANGES:                   Revision 1.57 2016/01/21 06:07:20CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Updated unwanted comments
# CHANGES:                   Revision 1.56 2016/01/20 04:44:55CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Cleaning and re-building EVM HIL arp32 target also re-builds arp32 lib
# CHANGES:                   Revision 1.55 2015/11/05 08:37:07CET Singh, Vishal (uidj9083) 
# CHANGES:                   Filter list of source file for arp32 and building obj file for arp32 qac report
# CHANGES:                   - Added comments -  uidj9083 [Nov 5, 2015 8:37:08 AM CET]
# CHANGES:                   Change Package : 393389:1 http://mks-psad:7002/im/viewissue?selection=393389
# CHANGES:                   Revision 1.54 2015/09/23 16:13:44CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between obj-files for ecu lib and ti-tools
# CHANGES:                   --- Added comments ---  uidg5297 [Sep 23, 2015 4:13:44 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.53 2015/09/01 10:35:42CEST Singh-EXT, Vishal (uidj9083) 
# CHANGES:                   [ETK][SCT][QAC] QAC-integration is compatible with M3/M4-builds
# CHANGES:                   --- Added comments ---  uidj9083 [Sep 1, 2015 10:35:42 AM CEST]
# CHANGES:                   Change Package : 371591:1 http://mks-psad:7002/im/viewissue?selection=371591
# CHANGES:                   Revision 1.52 2015/09/01 05:44:14CEST Singh-EXT, Vishal (uidj9083) 
# CHANGES:                   [ETK][SCT][QAC] QAC-integration is compatible with M3/M4-builds
# CHANGES:                   --- Added comments ---  uidj9083 [Sep 1, 2015 5:44:14 AM CEST]
# CHANGES:                   Change Package : 371591:1 http://mks-psad:7002/im/viewissue?selection=371591
# CHANGES:                   Revision 1.51 2015/08/03 14:07:39CEST Singh-EXT, Vishal (uidj9083) 
# CHANGES:                   Modified scons_adas_extensions\qac.py and scons_common_scripts\algo\lib\SConscript.py in GenericScons to make QAC build fully constructed based on the source-generates-target paradigm and to support multi-threading for QAC targets
# CHANGES:                   --- Added comments ---  uidj9083 [Aug 3, 2015 2:07:40 PM CEST]
# CHANGES:                   Change Package : 361687:1 http://mks-psad:7002/im/viewissue?selection=361687
# CHANGES:                   Revision 1.50 2015/07/31 12:06:21CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Improvement on polyspace project creation based on version. Updated module path and exception handling
# CHANGES:                   --- Added comments ---  uidr0826 [Jul 31, 2015 12:06:21 PM CEST]
# CHANGES:                   Change Package : 362983:1 http://mks-psad:7002/im/viewissue?selection=362983
# CHANGES:                   Revision 1.49 2015/07/31 06:04:31CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Implement scons measfreeze size track mechanism
# CHANGES:                   --- Added comments ---  uidr2134 [Jul 31, 2015 6:04:31 AM CEST]
# CHANGES:                   Change Package : 362668:1 http://mks-psad:7002/im/viewissue?selection=362668
# CHANGES:                   Revision 1.48 2015/07/30 12:45:59CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Implemented scons measfreeze size mechanism
# CHANGES:                   --- Added comments ---  uidr2134 [Jul 30, 2015 12:46:00 PM CEST]
# CHANGES:                   Change Package : 362668:1 http://mks-psad:7002/im/viewissue?selection=362668
# CHANGES:                   Revision 1.47 2015/06/29 13:35:47CEST Stark-EXT, Roland (uidw1169) 
# CHANGES:                   Added support for CortexM3 and M4
# CHANGES:                   --- Added comments ---  uidw1169 [Jun 29, 2015 1:35:48 PM CEST]
# CHANGES:                   Change Package : 351977:1 http://mks-psad:7002/im/viewissue?selection=351977
# CHANGES:                   Revision 1.46 2015/06/26 07:06:17CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 7:06:17 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build algo library

#-------------------------
# import
#-------------------------
Import("env", "target", "exception_handler_file_list","exception_handler", "component_name", "algo_name", "build_from_ide", "verbose", "help_dict", "profile", "SconscriptTimesTable","install_to_deliverables_dir")
import os
import re
execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    hierarchy = '2'
    if "SIM" in env["_BUILD_TARGET"]:
        hierarchy = '3'
    StartSconscriptEntry(hierarchy)

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(File("#algo_config.scfg").abspath)

# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper file
#-------------------------
# read sconstruct_helpers.py
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

# read gscons_exception_handler.py
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)	

# get relative path of a file
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+r"\algo_config.scfg"

try:
    # check whether component specific sdl is generated
    generate_component_specific_sdl
except NameError,e:
	# set default value
    exception_warning(e,exception_handler,msg)    
    generate_component_specific_sdl = False

try:
	generate_sdl_when_compiling_lib
except NameError,e:
	# set default value
	exception_warning(e,exception_handler,msg)
	generate_sdl_when_compiling_lib = True
	
#-------------------------
# setup environment
#-------------------------
local_env = env.Clone()

# add source files and include file paths
if "TI_C674X" in local_env["_BUILD_TARGET"]:
    src = c674x_src
    local_env.Append(CPPPATH = c674x_cpp_path)
    local_env.Prepend(CPPPATH = c674x_prepend_cpp_path)
    cpp_path = c674x_cpp_path + c674x_prepend_cpp_path
    arch = "ti_c674x"
elif "TI_C66XX" in local_env["_BUILD_TARGET"]:
    # re-use c674x sources
    src = c674x_src
    local_env.Append(CPPPATH = c674x_cpp_path)
    local_env.Prepend(CPPPATH = c674x_prepend_cpp_path)
    cpp_path = c674x_cpp_path + c674x_prepend_cpp_path
    arch = "ti_c66xx"
elif "TI_CORTEX_MX" in local_env["_BUILD_TARGET"]:
	src = cmx_src
	local_env.Append(CPPPATH = cmx_cpp_path)
	local_env.Prepend(CPPPATH = cmx_prepend_cpp_path)
	cpp_path = cmx_cpp_path + cmx_prepend_cpp_path
	arch = "ti_cortex_mx"
elif "TI_CORTEX_A8" in local_env["_BUILD_TARGET"]:
	src = ca8_src
	local_env.Append(CPPPATH = ca8_cpp_path)
	local_env.Prepend(CPPPATH = ca8_prepend_cpp_path)
	cpp_path = ca8_cpp_path + ca8_prepend_cpp_path
	arch = "ti_cortex_a8"
elif "TI_CORTEX_A15" in local_env["_BUILD_TARGET"]:
	src = ca15_src
	local_env.Append(CPPPATH = ca15_cpp_path)
	local_env.Prepend(CPPPATH = ca15_prepend_cpp_path)
	cpp_path = ca8_cpp_path + ca15_prepend_cpp_path
	arch = "ti_cortex_a15"
elif "SIM" in local_env["_BUILD_TARGET"]:
    src = pc_sim_src
    local_env.Append(CPPPATH = pc_sim_cpp_path)
    local_env.Prepend(CPPPATH = pc_prepend_cpp_path)
    cpp_path = pc_sim_cpp_path + pc_prepend_cpp_path
    arch = "pc"
elif "TI_ARP32" in local_env["_BUILD_TARGET"]:
    src = arp32_src
    local_env.Append(CPPPATH = arp32_cpp_path)
    local_env.Prepend(CPPPATH = arp32_prepend_cpp_path)
    cpp_path = arp32_cpp_path + arp32_prepend_cpp_path
    arch = "ti_arp32"

    # separate .c- and .k-files
    k_files = filter( lambda x: x[-2:] == ".k", src)
    c_files = filter( lambda x: x[-2:] == ".c", src)
    h_files = map(lambda x : x[:-1] + 'h', k_files)
    # deduce resulting .obj-files
    k_obj_files = map(lambda x : x[:-2] + '.obj', k_files)
    c_obj_files = map(lambda x : x[:-2] + '.obj', c_files)
    # deduce absolute paths to .obj-files
    k_obj_paths = map(lambda x : File(build_dir + "algo/" + algo_name + "/ti_arp32/" + local_env['variant'] + "/01_Source_Code/algo/" + component_name + "/" + x).abspath, k_obj_files)
    c_obj_paths = map(lambda x : File(build_dir + "algo/" + algo_name + "/ti_arp32/" + local_env['variant'] + "/01_Source_Code/algo/" + component_name + "/" + x).abspath, c_obj_files)
    # force scons to compile first all .k-files and only then all .c-files
    for c_obj in c_obj_paths:
        for k_obj in k_obj_files:
            Requires(c_obj, k_obj)   

#-------------------------
# build static library
#-------------------------
if "TI_ARP32" in local_env["_BUILD_TARGET"]:
    obj_k_files = [ local_env.StaticObject(sf) for sf in k_files ]
    obj_c_files = [ local_env.StaticObject(sf) for sf in c_files ]
    Depends(obj_c_files, obj_k_files)
    for h_f in h_files:
        Ignore(obj_c_files, h_f)
    obj = obj_k_files + obj_c_files
else:
    obj = [ local_env.StaticObject(sf) for sf in src ]
if local_env.subst('$_TOOLS'):
    Requires(obj, local_env['_TOOLS'])
if local_env.subst('$_TOOL_ADDONS'):
    Requires(obj, local_env['_TOOL_ADDONS'])
lib = local_env.StaticLibrary(target, obj)

# Issue 298092: Stop cleaning of .obj and .lib files only when HIL targets are cleaned.

for command in COMMAND_LINE_TARGETS:
    if ((re.search(algo_name + "_sim", command)) or (re.search(component_name + "_sim", command))):
        local_env.NoClean([obj, lib])
        if "TI_ARP32" in local_env["_BUILD_TARGET"]:
            for h_f in h_files:
                local_env.NoClean(h_f, lib)

# initialise fingerprint alias in order to force scons to build fingerprint before lib
Alias(algo_name + "_fingerprint", [])
Requires(lib, algo_name + "_fingerprint")

#------------------------
# Calculate size from sdl
#------------------------

def readSdlFile(core, sdlFileName):
    bld_dir = (build_dir + "/algo/" + algo_name + "/" + core + "/" + env["variant"])
    srcfile = File(bld_dir + '/' + "01_Source_Code/" + component_name + '/' + str(sdlFileName))
    outfile = File(bld_dir + '/' + str(sdlFileName)[0:-4] + "_" + core + "_" + "measfreezesize.txt")
    sizeReport = action_read_sdl(env, srcfile, outfile)
    return sizeReport

try:
	id_file_path
	task_id_define
	PDO_TOOL_OPTIONS_ECU
	PDO_TOOL_OPTIONS_SIM
except NameError,e:
	exception_error(e,"in algo_config.scfg")

if generate_sdl_when_compiling_lib:
    #-------------------------
    # generate SDL file
    #-------------------------
    # generate SDL file using pdo extension
    task_id = get_define_value_from_file(id_file_path, task_id_define)
    # remove "U"
    task_id = task_id[:-1]
    sdl_files_all = []
    execfile(File(scons_adas_extensions_path + "pdo.py").abspath)    
    if "TI_C674X" in local_env["_BUILD_TARGET"]:

        # get PDO source file
        pdo_src = abspath_filenames(pdo_src_list)

        # setup pdo environment
        pdo_env = local_env.Clone(# list of scons extensions used
                    tools = ["pdo"],
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path],
                    # path to Pdo tools executable
                    PDO_TOOLS = pdo_dir,
                    # path to PDO scan configuration
                    PDO_SCAN_CONFIG = development_tools_dir + "pdo_tool/dm643x_pdo_cmt.cfg",
                    # PDO tool options
                    PDO_TOOL_OPTIONS = PDO_TOOL_OPTIONS_ECU % task_id,
                    # path to SDL compiler
                    SDL_COMPILER = sdl_compiler_dir)
        if not verbose:
            pdo_env['PDOGENCOMSTR'] = "\npdo_gen -o $TARGET"
            pdo_env['PDOSCANCOMSTR'] = '\npdo_scan $_PDO_SCAN_CONFIG\n[$SOURCES]\n-o $TARGET'
            pdo_env['PDOTOOLCOMSTR'] = "\npdo_tool $PDO_TOOL_OPTIONS\n[$SOURCES]\n-o $TARGET",


        # generate SDL file
        core = "ti_c674x"
        if not generate_component_specific_sdl:
            sdl_file = pdo_env.PdoFile(algo_name + ".sdl", pdo_src)
            if "release" in local_env["variant"]: 
                sdl_file += readSdlFile(core, sdl_file[0])            
            # copy SDL file to 05_Deliverables folder
            # install SDL file to 05_Deliverables folder for selected variant
            if install_to_deliverables_dir in local_env["variant"]:
                sdl_file += pdo_env.Install((deliverables_dir + "/sdl/" + core + "/algo/" + algo_name + "/"),
                                        algo_name + ".sdl")

        else:
            bld_dir = (build_dir + "/algo/" + algo_name + "/" + core + "/" + env["variant"])
            sdl_file = SConscript(bld_dir + "/01_Source_Code/algo/" + component_name + "/SConscript_sdl.py",
                                  exports = {
                                      "env" : pdo_env,
                                      "core" : core,
                                      "component_name" : component_name,
                                      "algo_name" : algo_name,
                                      "bld_dir" : bld_dir
                                 })

        sdl_files_all += sdl_file
        generate_alias(component_name + "_algo_ti_c674x_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ti_c674x", sdl_file)
        generate_alias(component_name + "_algo_ecu_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ecu", sdl_file)
        generate_alias(component_name + "_algo_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo", sdl_file)
        if algo_name != component_name:
            generate_alias(algo_name + "_algo_ti_c674x_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ti_c674x", sdl_file)
            generate_alias(algo_name + "_algo_ecu_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ecu", sdl_file)
            generate_alias(algo_name + "_algo_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo", sdl_file)
        generate_alias(env["variant"], sdl_file)
        generate_alias("all_" + env["variant"], sdl_file)
        generate_alias("all", sdl_file)


    if "TI_C66XX" in local_env["_BUILD_TARGET"]:

        # get PDO source file
        pdo_src = abspath_filenames(pdo_src_list)

        # setup pdo environment
        pdo_env = local_env.Clone(# list of scons extensions used
                    tools = ["pdo"],
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path],
                    # path to Pdo tools executable
                    PDO_TOOLS = pdo_dir,
                    # path to PDO scan configuration
                    PDO_SCAN_CONFIG = development_tools_dir + "pdo_tool/dm643x_pdo_cmt.cfg",
                    # PDO tool options
                    PDO_TOOL_OPTIONS = PDO_TOOL_OPTIONS_ECU % task_id,
                    # path to SDL compiler
                    SDL_COMPILER = sdl_compiler_dir)
        if not verbose:
            pdo_env['PDOGENCOMSTR'] = "\npdo_gen -o $TARGET"
            pdo_env['PDOSCANCOMSTR'] = '\npdo_scan $_PDO_SCAN_CONFIG\n[$SOURCES]\n-o $TARGET'
            pdo_env['PDOTOOLCOMSTR'] = "\npdo_tool $PDO_TOOL_OPTIONS\n[$SOURCES]\n-o $TARGET",

        # generate SDL file
        core = "ti_c66xx"
        if not generate_component_specific_sdl:
            sdl_file = pdo_env.PdoFile(algo_name + ".sdl", pdo_src)
            if "release" in local_env["variant"]: 
                sdl_file += readSdlFile(core, sdl_file[0])
            # copy SDL file to 05_Deliverables folder
            # install SDL file to 05_Deliverables folder for selected variant
            if install_to_deliverables_dir in local_env["variant"]:
                sdl_file += pdo_env.Install((deliverables_dir + "/sdl/" + core + "/algo/" + algo_name + "/"),
                                        algo_name + ".sdl")

        else:
            bld_dir = (build_dir + "/algo/" + algo_name + "/" + core + "/" + env["variant"])
            sdl_file = SConscript(bld_dir + "/01_Source_Code/algo/" + component_name + "/SConscript_sdl.py",
                                  exports = {
                                      "env" : pdo_env,
                                      "core" : core,
                                      "component_name" : component_name,
                                      "algo_name" : algo_name,
                                      "bld_dir" : bld_dir
                                 })

        sdl_files_all += sdl_file
        generate_alias(component_name + "_algo_ti_c66xx_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ti_c66xx", sdl_file)
        generate_alias(component_name + "_algo_ecu_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ecu", sdl_file)
        generate_alias(component_name + "_algo_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo", sdl_file)
        if algo_name != component_name:
            generate_alias(algo_name + "_algo_ti_c66xx_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ti_c66xx", sdl_file)
            generate_alias(algo_name + "_algo_ecu_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ecu", sdl_file)
            generate_alias(algo_name + "_algo_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo", sdl_file)
        generate_alias(env["variant"], sdl_file)
        generate_alias("all_" + env["variant"], sdl_file)
        generate_alias("all", sdl_file)

    elif "TI_CORTEX_A8" in local_env["_BUILD_TARGET"]:

        if "arm_gcc" in local_env["TOOLS"]:
            pdo_scan_config = development_tools_dir + "pdo_tool/gcc_armv7_eabi-aapcs_pdo_cmt.cfg"
        else:
            pdo_scan_config = development_tools_dir + "pdo_tool/dm643x_pdo_cmt.cfg"

        # get PDO source file
        pdo_src = abspath_filenames(pdo_src_list)

        # setup pdo environment
        pdo_env = local_env.Clone(# list of scons extensions used
                    tools = ["pdo"],
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path],
                    # path to Pdo tools executable
                    PDO_TOOLS = pdo_dir,
                    # path to PDO scan configuration
                    PDO_SCAN_CONFIG = pdo_scan_config,
                    # PDO tool options
                    PDO_TOOL_OPTIONS = PDO_TOOL_OPTIONS_ECU % task_id,
                    # path to SDL compiler
                    SDL_COMPILER = sdl_compiler_dir)
        if not verbose:
            pdo_env['PDOGENCOMSTR'] = "\npdo_gen -o $TARGET"
            pdo_env['PDOSCANCOMSTR'] = '\npdo_scan $_PDO_SCAN_CONFIG\n[$SOURCES]\n-o $TARGET'
            pdo_env['PDOTOOLCOMSTR'] = "\npdo_tool $PDO_TOOL_OPTIONS\n[$SOURCES]\n-o $TARGET",

        # generate SDL file
        core = "ti_cortex_a8"
        if not generate_component_specific_sdl:
            sdl_file = pdo_env.PdoFile(algo_name + ".sdl", pdo_src)
            if "release" in local_env["variant"]: 
                sdl_file += readSdlFile(core, sdl_file[0])
            # copy SDL file to 05_Deliverables folder
            # install SDL file to 05_Deliverables folder for selected variant
            if install_to_deliverables_dir in local_env["variant"]:
                sdl_file += pdo_env.Install((deliverables_dir + "/sdl/" + core + "/algo/" + algo_name + "/"),
                                        algo_name + ".sdl")

        else:
            bld_dir = (build_dir + "/algo/" + algo_name + "/" + core + "/" + env["variant"])
            sdl_file = SConscript(bld_dir + "/01_Source_Code/algo/" + component_name + "/SConscript_sdl.py",
                                  exports = {
                                      "env" : pdo_env,
                                      "core" : core,
                                      "component_name" : component_name,
                                      "algo_name" : algo_name,
                                      "bld_dir" : bld_dir
                                 })

        sdl_files_all += sdl_file
        generate_alias(component_name + "_algo_ti_cortex_a8_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ti_cortex_a8", sdl_file)
        generate_alias(component_name + "_algo_ecu_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ecu", sdl_file)
        generate_alias(component_name + "_algo_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo", sdl_file)
        if algo_name != component_name:
            generate_alias(algo_name + "_algo_ti_cortex_a8_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ti_cortex_a8", sdl_file)
            generate_alias(algo_name + "_algo_ecu_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ecu", sdl_file)
            generate_alias(algo_name + "_algo_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo", sdl_file)
        generate_alias(env["variant"], sdl_file)
        generate_alias("all_" + env["variant"], sdl_file)
        generate_alias("all", sdl_file)

    elif "TI_CORTEX_A15" in local_env["_BUILD_TARGET"]:

        # get PDO source file
        pdo_src = abspath_filenames(pdo_src_list)

        # setup pdo environment
        pdo_env = local_env.Clone(# list of scons extensions used
                    tools = ["pdo"],
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path],
                    # path to Pdo tools executable
                    PDO_TOOLS = pdo_dir,
                    # path to PDO scan configuration
                    PDO_SCAN_CONFIG = development_tools_dir + "pdo_tool/gcc_armv7_eabi-aapcs_pdo_cmt.cfg",
                    # PDO tool options
                    PDO_TOOL_OPTIONS = PDO_TOOL_OPTIONS_ECU % task_id,
                    # path to SDL compiler
                    SDL_COMPILER = sdl_compiler_dir)
        if not verbose:
            pdo_env['PDOGENCOMSTR'] = "\npdo_gen -o $TARGET"
            pdo_env['PDOSCANCOMSTR'] = '\npdo_scan $_PDO_SCAN_CONFIG\n[$SOURCES]\n-o $TARGET'
            pdo_env['PDOTOOLCOMSTR'] = "\npdo_tool $PDO_TOOL_OPTIONS\n[$SOURCES]\n-o $TARGET",

        # generate SDL file
        core = "ti_cortex_a15"
        if not generate_component_specific_sdl:
            sdl_file = pdo_env.PdoFile(algo_name + ".sdl", pdo_src)
            if "release" in local_env["variant"]: 
                sdl_file += readSdlFile(core, sdl_file[0])
            # copy SDL file to 05_Deliverables folder
            # install SDL file to 05_Deliverables folder for selected variant
            if install_to_deliverables_dir in local_env["variant"]:
                sdl_file += pdo_env.Install((deliverables_dir + "/sdl/" + core + "/algo/" + algo_name + "/"),
                                        algo_name + ".sdl")

        else:
            bld_dir = (build_dir + "/algo/" + algo_name + "/" + core + "/" + env["variant"])
            sdl_file = SConscript(bld_dir + "/01_Source_Code/" + component_name + "/SConscript_sdl.py",
                                  exports = {
                                      "env" : pdo_env,
                                      "core" : core,
                                      "component_name" : component_name,
                                      "algo_name" : algo_name,
                                      "bld_dir" : bld_dir
                                 })

        sdl_files_all += sdl_file
        generate_alias(component_name + "_algo_ti_cortex_a15_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ti_cortex_a15", sdl_file)
        generate_alias(component_name + "_algo_ecu_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo_ecu", sdl_file)
        generate_alias(component_name + "_algo_" + env["variant"], sdl_file)
        generate_alias(component_name + "_algo", sdl_file)
        if algo_name != component_name:
            generate_alias(algo_name + "_algo_ti_cortex_a15" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ti_cortex_a15", sdl_file)
            generate_alias(algo_name + "_algo_ecu_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo_ecu", sdl_file)
            generate_alias(algo_name + "_algo_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_algo", sdl_file)
        generate_alias(env["variant"], sdl_file)
        generate_alias("all_" + env["variant"], sdl_file)
        generate_alias("all", sdl_file)

    elif "SIM" in local_env["_BUILD_TARGET"]:

        # get PDO source file
        try:
            # check pdo_sim_src_list
            pdo_sim_src_list
        except NameError,e:
            exception_warning(e,exception_handler,msg)
            pdo_sim_src_list = pdo_src_list

        pdo_src = abspath_filenames(pdo_sim_src_list)

        # setup pdo environment
        pdo_env = local_env.Clone(# list of scons extensions used
                    tools = ["pdo"],
                    # path to scons extensions
                    toolpath = [scons_adas_extensions_path],
                    # path to Pdo tools executable
                    PDO_TOOLS = pdo_dir,
                    # path to PDO scan configuration
                    PDO_SCAN_CONFIG = pdo_scan_config,
                    # PDO tool options
                    PDO_TOOL_OPTIONS = PDO_TOOL_OPTIONS_SIM % task_id,
                    # path to SDL compiler
                    SDL_COMPILER = sdl_compiler_dir)
        if not verbose:
            pdo_env['PDOGENCOMSTR'] = "\npdo_gen -o $TARGET"
            pdo_env['PDOSCANCOMSTR'] = '\npdo_scan $_PDO_SCAN_CONFIG\n[$SOURCES]\n-o $TARGET'
            pdo_env['PDOTOOLCOMSTR'] = "\npdo_tool $PDO_TOOL_OPTIONS\n[$SOURCES]\n-o $TARGET",
        pdo_env['PDOSCANCOM'] = '${TEMPFILE("pdo_scan.exe -c $_PDO_SCAN_CONFIG $_CPPINCFLAGS $_CPPDEFFLAGS -o $TARGET $SOURCES")}'
        # add include path for standard library
        try:
            # check compiler_include_paths
            compiler_include_paths
        except NameError,e:
            compiler_include_paths = local_env["ENV"]["INCLUDE"].split(";")
            exception_warning(e,exception_handler,msg)
            
        pdo_env.Append(CPPPATH = Split(compiler_include_paths))

        # generate SDL file
        core = "pc"
        if not generate_component_specific_sdl:
            sdl_file = pdo_env.PdoFile(algo_name + ".sdl", pdo_src)
            if "release" in local_env["variant"]: 
                sdl_file += readSdlFile(core, sdl_file[0])
            # compile SDL file
            sdl_file += pdo_env.SdlCompiler("sim_swc_" + algo_name + ".cdl", algo_name + ".sdl")

            # copy CDL file to sim_swc_(component) in 04_Build folder
            sdl_file += pdo_env.Install((build_dir + "/algo/" + algo_name +
                                        "_sim/pc/sim_swc_" + algo_name + "/" + env["variant"]),
                                        "sim_swc_" + algo_name + ".cdl")
        else:
            bld_dir = (build_dir + "/algo/" + algo_name + "/" + core + "/" + env["variant"])
            sdl_file = SConscript(bld_dir + "/01_Source_Code/" + component_name + "/SConscript_sdl.py",
                                  exports = {
                                      "env" : pdo_env,
                                      "core" : core,
                                      "component_name" : component_name,
                                      "algo_name" : algo_name,
                                      "bld_dir" : bld_dir
                                 })

        sdl_files_all += sdl_file
        generate_alias(component_name + "_sim_swc_" + env["variant"], sdl_file)
        generate_alias(component_name + "_sim_swc", sdl_file)
        generate_alias(component_name + "_sim_pc_" + env["variant"], sdl_file)
        generate_alias(component_name + "_sim_pc", sdl_file)
        generate_alias(component_name + "_sim_" + env["variant"], sdl_file)
        generate_alias(component_name + "_sim", sdl_file)
        if algo_name != component_name:
            generate_alias(algo_name + "_sim_swc_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_sim_swc", sdl_file)
            generate_alias(algo_name + "_sim_pc_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_sim_pc", sdl_file)
            generate_alias(algo_name + "_sim_" + env["variant"], sdl_file)
            generate_alias(algo_name + "_sim", sdl_file)
        generate_alias(env["variant"], sdl_file)
        generate_alias("all_" + env["variant"], sdl_file)
        generate_alias("all", sdl_file)

    generate_alias(component_name + "_sdl", sdl_files_all, component_name + ':sdl', ['sdl-files'])
    if algo_name != component_name:
        generate_alias(algo_name + "_sdl", sdl_files_all, component_name  + ':sdl', ['sdl-files'])
#-------------------------
# gather results
#-------------------------
# get absolute include path
cpp_path = map(lambda x: str(Dir(x).srcnode().abspath), cpp_path)

# get absolute source file
cpp_src = abspath_filenames(src)

# get preprocessor define
defines = local_env["CPPDEFINES"]

#-------------------------
# generate qac report
#-------------------------
Import("qac_mode", "qac_source_list", "qac_temp_options", "qar_temp_format")
if "release" in local_env["variant"] and not "SIM" in local_env["_BUILD_TARGET"]:
    if "TI_CORTEX_MX" in local_env["_BUILD_TARGET"]:
        if "m3" in local_env["TARGET_CORE"]:	
            QAC_BUILD = "TI_CORTEX_M3"
        if "m4" in local_env["TARGET_CORE"]:
            QAC_BUILD = "TI_CORTEX_M4"
    else:
        QAC_BUILD = local_env["_BUILD_TARGET"]	
    QAC_CPPPATH = local_env["CPPPATH"]
    # New environment for QAC
    qac_env = Environment(tools = ["qac"],
                          toolpath = [scons_adas_extensions_path],
                          COMPONENT = component_name,
						  _BUILD_TARGET = QAC_BUILD,
						  CPPPATH = QAC_CPPPATH,
                          ALGO = algo_name)
    # prepare qac data
    qac_src_dir = "01_Source_Code/algo"
    try:
        # sources in algo_config are read with respect to folder #../../../01_Source_Code/algo/xxx
        wrapper_src = map(lambda x : File("#../../../01_Source_Code/algo/" + component_name + "/" + x).abspath, wrapper_src)
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        wrapper_src = []

    qac_incs = cpp_path
    qac_defines = defines

    #-------------------------------------------------------------------------------------
    # check with QAC mode is executed.
    # Mode "file" means only one or some files are analyzed (typically from visual studio)
    # Mode "project" means that all source files for the corr. library are analyzed
    #-------------------------------------------------------------------------------------
    if qac_mode == "file":
        qac_src = qac_source_list
    elif qac_mode == "project":
        qac_src = cpp_src
        if not "TI_ARP32" in qac_env["_BUILD_TARGET"]:
            qac_src += wrapper_src

    # read qac configuration
    try:
        qac_cmd_options
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        qac_cmd_options = ''
        
    try:
        qac_ide_options
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        try: # qac_options is the former variable name for ide options
            qac_ide_options = qac_options
        except NameError,e:
            exception_warning(e,exception_handler,msg)
            qac_ide_options = ''

    if build_from_ide:
        qac_options = qac_common_ide_options.split() + qac_ide_options.split()
    else:
        qac_options = qac_common_cmd_options.split() + qac_cmd_options.split() + qac_temp_options

    # read qar options
    try:
        qar_options = qar_common_options.split() + qar_options.split()
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        qar_options = qar_common_options.split()

    if qar_temp_format != "":
        qar_format = qar_temp_format
    else:
        qar_format = qar_default_format
    
    # set qac / qar options
    for option in qac_options:
        qac_env.Append(QAC_OPTIONS = option.split())
    # allow generation of compliance report in spite of parser errors
    if '-nostoponfail' in qac_temp_options:
        while '-stoponfail' in qac_env['QAC_OPTIONS']:
            qac_env['QAC_OPTIONS'].remove('-stoponfail')
        while '-nostoponfail' in qac_env['QAC_OPTIONS']:
            qac_env['QAC_OPTIONS'].remove('-nostoponfail')
        
    qac_env['QAR_OPTIONS'] = qar_options
        
    # transform options into strings as required for qac/qar
    qac_env['QAC_OPTIONS'] = " ".join(qac_env['QAC_OPTIONS'])
    qac_env['QAR_OPTIONS'] = " ".join(qac_env['QAR_OPTIONS'])		

    qac_env['QAR_FORMAT'] = qar_format
    build_dir = "#../../../04_Build/"
    Report_dir = "#../../../../05_Testing/02_Reports/algo/modtests/"
    modtest_dir = "#../../../../05_Testing/05_Test_Environment/algo/modtests"
    QAC_algo_build_VariantDir = (build_dir + "/algo/" + algo_name+"_qac/")
    QACPP_algo_build_VariantDir = (build_dir + "/algo/" + algo_name + "_qacpp/")	
    if qac_mode != "file":	
        QAC_algo_build_dir = (build_dir + "/algo/" + algo_name+"_qac/")
        QACPP_algo_build_dir = (build_dir + "/algo/" + algo_name + "_qacpp/")
    if qac_mode == "file":
        QAC_algo_build_dir = (modtest_dir + "/qac_tests/" + algo_name+"_debug/")
        QACPP_algo_build_dir = (modtest_dir + "/qacpp_tests/" + algo_name + "_debug/")	
	
    # define compiler personality
    if "TI_C674X" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_c674x/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_c674x/", "#../../../", duplicate = 0)		
        comp_pers = comp_pers_path + comp_pers_ti_c674x
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_c674x/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_c674x/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_c674x/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_c674x/Compliance Report."+qac_env['QAR_FORMAT']		
    elif "TI_C66XX" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_c66xx/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_c66xx/", "#../../../", duplicate = 0)	
        comp_pers = comp_pers_path + comp_pers_ti_c66xx
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_c66xx/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_c66xx/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_c66xx/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_c66xx/Compliance Report."+qac_env['QAR_FORMAT']			
    elif "TI_CORTEX_A8" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_cortex_a8/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_cortex_a8/", "#../../../", duplicate = 0)	
        comp_pers = comp_pers_path + comp_pers_ti_cortex_a8
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_cortex_a8/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_cortex_a8/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_cortex_a8/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_cortex_a8/Compliance Report."+qac_env['QAR_FORMAT']			
    elif "TI_CORTEX_A15" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_cortex_a15/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_cortex_a15/", "#../../../", duplicate = 0)	
        comp_pers = comp_pers_path + comp_pers_ti_cortex_a15
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_cortex_a15/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_cortex_a15/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_cortex_a15/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_cortex_a15/Compliance Report."+qac_env['QAR_FORMAT']

    elif "TI_CORTEX_M3" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_cortex_m3/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_cortex_m3/", "#../../../", duplicate = 0)	
        comp_pers = comp_pers_path + comp_pers_ti_cortex_mx
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_cortex_m3/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_cortex_m3/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_cortex_m3/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_cortex_m3/Compliance Report."+qac_env['QAR_FORMAT']

    elif "TI_CORTEX_M4" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_cortex_m4/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_cortex_m4/", "#../../../", duplicate = 0)	
        comp_pers = comp_pers_path + comp_pers_ti_cortex_mx
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_cortex_m4/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_cortex_m4/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_cortex_m4/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_cortex_m4/Compliance Report."+qac_env['QAR_FORMAT']			
			
    elif "TI_ARP32" in qac_env["_BUILD_TARGET"]:
        qac_env.VariantDir(QAC_algo_build_VariantDir+"/ti_arp32/", "#../../../", duplicate = 0)
        qac_env.VariantDir(QACPP_algo_build_VariantDir+"/ti_arp32/", "#../../../", duplicate = 0)	
        comp_pers = comp_pers_path + comp_pers_ti_arp32
        if qac_mode != "file":		
            qac_compliance_report = QAC_algo_build_dir+"/ti_arp32/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/ti_arp32/Compliance Report."+qac_env['QAR_FORMAT']
        if qac_mode == "file":
            qac_compliance_report = QAC_algo_build_dir+"/output/ti_arp32/Compliance Report."+qac_env['QAR_FORMAT']
            qacpp_compliance_report =  QACPP_algo_build_dir+"/output/ti_arp32/Compliance Report."+qac_env['QAR_FORMAT']			


    cpp_source_files = [elem for elem in qac_src if elem.endswith(".cpp")]
    # get only c files
    c_source_files = [elem for elem in qac_src if elem.endswith(".c")]

    algo_qac_report = ''
    algo_qacpp_report = ''
    algo_qacpp_proj	= ''
    algo_qac_proj = ''
	
    if len(cpp_source_files) != 0:
        source_type = 'cpp'
        algo_qacpp_proj = qac_env.generate_qac_proj(cpp_source_files, qac_incs, qac_defines, qac_src_dir, comp_pers, qac_mode, source_type)		
        algo_qacpp_report = qac_env.generate_qac_report(qacpp_compliance_report, cpp_source_files, source_type, qac_mode)
	
    if len(c_source_files) != 0:
        source_type = 'c'
        algo_qac_proj = qac_env.generate_qac_proj(c_source_files, qac_incs, qac_defines, qac_src_dir, comp_pers, qac_mode, source_type)		
        algo_qac_report = qac_env.generate_qac_report(qac_compliance_report, c_source_files, source_type, qac_mode)	

    Depends(algo_qac_report, algo_qac_proj)
    Depends(algo_qacpp_report, algo_qacpp_proj)
    if "TI_ARP32" in qac_env["_BUILD_TARGET"]:
        Requires(algo_qac_report, obj)
        Requires(algo_qacpp_report, obj)	
		
    
    if "TI_C674X" in qac_env["_BUILD_TARGET"] and qac_mode != "file":
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])		
			
    elif "TI_C66XX" in qac_env["_BUILD_TARGET"] and qac_mode != "file":
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])			
        
    elif "TI_CORTEX_A8" in qac_env["_BUILD_TARGET"] and qac_mode != "file":
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])		
        
    elif "TI_CORTEX_A15" in qac_env["_BUILD_TARGET"] and qac_mode != "file":
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])		

    elif "TI_CORTEX_M3" in qac_env["_BUILD_TARGET"] and qac_mode != "file":
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])

    elif "TI_CORTEX_M4" in qac_env["_BUILD_TARGET"] and qac_mode != "file":		
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])	        	        
			
    elif "TI_ARP32" in qac_env["_BUILD_TARGET"] and qac_mode != "file":
        if len(c_source_files) != 0:	
            algo_qac_report += qac_env.InstallAs([Report_dir+'/qac_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qac_report[0])
        if len(cpp_source_files) != 0:
            algo_qacpp_report += qac_env.InstallAs([Report_dir+'/qacpp_tests/Compliance_Report_'+qac_env["ALGO"]+'_'+qac_env["_BUILD_TARGET"].lower()+'.html'], algo_qacpp_report[0])			
	
        
    # Include a dummy target in order to force SCons to only generate one report at a time in case of multi-thread build		
    if qac_mode == "file":
        AlwaysBuild(algo_qac_proj)
        AlwaysBuild(algo_qacpp_proj)		
        		
    folders_remove = [Dir(QACPP_algo_build_dir+"/"+qac_env["_BUILD_TARGET"]+"/").abspath, Dir(QAC_algo_build_dir+"/"+qac_env["_BUILD_TARGET"] +"/")]
    # folders to be removed for a clean
    folders_remove += [Dir(testing_dir + "/05_Test_Environment/algo/modtests/qac_tests/" + algo_name + "/output").abspath,
                      Dir(testing_dir + "/05_Test_Environment/algo/modtests/qac_tests/debug").abspath,
                      Dir(testing_dir + "/05_Test_Environment/algo/modtests/qacpp_tests/" + algo_name + "/output").abspath,
                      Dir(testing_dir + "/05_Test_Environment/algo/modtests/qacpp_tests/debug").abspath]


    # generate QAC-Aliases:
    if "TI_C674X" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_c674x_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:ti_c674x:proj', ['QAC prj-files: C674x'])
        generate_alias(component_name + "_qac_ti_c674x", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_c674x', ['QAC compl-rep: C674x'])
        Clean(component_name + "_qac_ti_c674x", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_c674x_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_c674x:proj', ['QAC prj-files: C674x'])
            generate_alias(algo_name + "_qac_ti_c674x", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_c674x', ['QAC compl-rep: C674x'])
            Clean(algo_name + "_qac_ti_c674x", folders_remove)
    elif "TI_C66XX" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_c66xx_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:ti_c66xx:proj', ['QAC prj-files: C66xx'])
        generate_alias(component_name + "_qac_ti_c66xx", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_c66xx', ['QAC compl-rep: C66xx'])
        Clean(component_name + "_qac_ti_c66xx", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_c66xx_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_c66xx:proj', ['QAC prj-files: C66xx'])
            generate_alias(algo_name + "_qac_ti_c66xx", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_c66xx', ['QAC compl-rep: C66xx'])
            Clean(algo_name + "_qac_ti_c66xx", folders_remove)
    elif "TI_CORTEX_A8" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_cortex_a8_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:ti_cortex_a8:proj', ['QAC prj-files: Cortex A8'])
        generate_alias(component_name + "_qac_ti_cortex_a8", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_cortex_a8', ['QAC compl-rep: Cortex A8'])
        Clean(component_name + "_qac_ti_cortex_a8", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_cortex_a8_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_cortex_a8:proj', ['QAC prj-files: Cortex A8'])
            generate_alias(algo_name + "_qac_ti_cortex_a8", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_cortex_a8', ['QAC compl-rep: Cortex A8'])
            Clean(algo_name + "_qac_ti_cortex_a8", folders_remove)
    elif "TI_CORTEX_A15" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_cortex_a15_proj", [algo_qac_proj,algo_qacpp_proj], component_name + '_qac:ti_cortex_a15:proj', ['QAC prj-files: Cortex A15'])
        generate_alias(component_name + "_qac_ti_cortex_a15", [algo_qac_proj,algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_cortex_a15', ['QAC compl-rep: Cortex A15'])
        Clean(component_name + "_qac_ti_cortex_a15", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_cortex_a15_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_cortex_a15:proj', ['QAC prj-files: Cortex A15'])
            generate_alias(algo_name + "_qac_ti_cortex_a15", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_cortex_a15', ['QAC compl-rep: Cortex A15'])
            Clean(algo_name + "_qac_ti_cortex_a15", folders_remove)

    elif "TI_CORTEX_M3" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_cortex_m3_proj", [algo_qac_proj,algo_qacpp_proj], component_name + '_qac:ti_cortex_m3:proj', ['QAC prj-files: Cortex M3'])
        generate_alias(component_name + "_qac_ti_cortex_m3", [algo_qac_proj,algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_cortex_m3', ['QAC compl-rep: Cortex M3'])
        Clean(component_name + "_qac_ti_cortex_m3", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_cortex_m3_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_cortex_m3:proj', ['QAC prj-files: Cortex M3'])
            generate_alias(algo_name + "_qac_ti_cortex_m3", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_cortex_m3', ['QAC compl-rep: Cortex M3'])
            Clean(algo_name + "_qac_ti_cortex_m3", folders_remove)
		
    elif "TI_CORTEX_M4" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_cortex_m4_proj", [algo_qac_proj,algo_qacpp_proj], component_name + '_qac:ti_cortex_m4:proj', ['QAC prj-files: Cortex M4'])
        generate_alias(component_name + "_qac_ti_cortex_m4", [algo_qac_proj,algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_cortex_m4', ['QAC compl-rep: Cortex M4'])
        Clean(component_name + "_qac_ti_cortex_m4", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_cortex_m4_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_cortex_m4:proj', ['QAC prj-files: Cortex M4'])
            generate_alias(algo_name + "_qac_ti_cortex_m4", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_cortex_m4', ['QAC compl-rep: Cortex M4'])
            Clean(algo_name + "_qac_ti_cortex_m4", folders_remove)		
			
			
    elif "TI_ARP32" in qac_env["_BUILD_TARGET"]:
        generate_alias(component_name + "_qac_ti_arp32_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:ti_arp32:proj', ['QAC prj-files: ARP32'])
        generate_alias(component_name + "_qac_ti_arp32", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:ti_arp32', ['QAC compl-rep: ARP32'])
        Clean(component_name + "_qac_ti_arp32", folders_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_qac_ti_arp32_proj", [algo_qac_proj, algo_qacpp_proj], component_name + '_qac:' + algo_name + '_qac:ti_arp32:proj', ['QAC prj-files: ARP32'])
            generate_alias(algo_name + "_qac_ti_arp32", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac:ti_arp32', ['QAC compl-rep: ARP32'])
            Clean(algo_name + "_qac_ti_arp32", folders_remove)

    generate_alias(component_name + "_qac_proj", [algo_qac_proj, algo_qacpp_proj])
    generate_alias(component_name + "_qac", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac')
    if algo_name != component_name:
        generate_alias(algo_name + "_qac_proj", [algo_qac_proj, algo_qacpp_proj])
        generate_alias(algo_name + "_qac", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report], component_name + '_qac:' + algo_name + '_qac')
    Clean(component_name + "_qac", folders_remove)
    if algo_name != component_name:
        Clean(algo_name + "_qac", folders_remove)

    Clean("all", [algo_qac_proj, algo_qacpp_proj, algo_qac_report, algo_qacpp_report])
    Clean("all", folders_remove)

#-------------------------
# generate Polyspace 2016a project for DSP
#-------------------------
Import("generate_ps", "ps_module_data")
if generate_ps and "release" in local_env["variant"] and not "SIM" in local_env["_BUILD_TARGET"] and not "TI_ARP32" in local_env["_BUILD_TARGET"] and not "TI_CORTEX_A15" in local_env["_BUILD_TARGET"] and not "TI_CORTEX_A8" in local_env["_BUILD_TARGET"] and not "TI_CORTEX_M3" in local_env["_BUILD_TARGET"] and not "TI_CORTEX_M4" in local_env["_BUILD_TARGET"] and not "TI_C674X" in local_env["_BUILD_TARGET"] and not "TI_C66XX" in local_env["_BUILD_TARGET"]:

	# Polyspace project directory for algo, drivers and stubs
    ps_directory = Dir(testing_dir + "/05_Test_Environment/algo/modtests/polyspace/").abspath
    ps_algo_directory = ps_directory + "/" + algo_name
    ps_drivers_directory = ps_algo_directory + "/drivers/"
    if not os.path.exists(ps_drivers_directory):
        os.makedirs(ps_drivers_directory)
    ps_stubs_directory = ps_algo_directory + "/stubs/"
    if not os.path.exists(ps_stubs_directory):
        os.makedirs(ps_stubs_directory)

    # Create an environment for Polyspace project generation target
    ps_env = local_env.Clone(tools = ["polyspace"],
                          toolpath = [scons_adas_extensions_path],
                          COMPONENT = component_name,
						  _BUILD_TARGET = local_env["_BUILD_TARGET"],
		                  ALGO = algo_name)


    # Exception handling for Polyspace configuration 
    try:
        # check ps_version, Polyspace version for project creation
        ps_version
    except NameError,e:
        exception_warning(e,exception_handler,"in "+relpath+r"\algo_config.scfg but default version 2016a is used")
        # default value for ps_version
        ps_version = "2016a"
    if ps_version != "2016a":
        exception_warning(e,exception_handler,"::GenericSCons::Information::Given version will not be supported, hence the default version 2016a has been set")
        ps_version = "2016a"

    try:
        # check ps_macros, Polyspace macros
        ps_macros = ps_macros + defines
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        # default value for ps_macros       
        ps_macros = defines
    ps_defines = ps_macros

    try:
        # check ps_target_option, Polyspace target options
        ps_target_option
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        # default value for ps_target_option        
        ps_target_option = {}
    target_options = ps_target_option

    try:
        # check ps_additional_sources, Polyspace additional source if any
        ps_additional_sources
    except NameError,e:
		# default value for ps_additional_sources
        exception_warning(e,exception_handler,msg)        
        ps_additional_sources = []

    try:
        # check ps_additional_includes, Polyspace additional includes if any
        ps_additional_includes        
    except NameError,e:
		# default value for ps_additional_includes
        exception_warning(e,exception_handler,msg)        
        ps_additional_includes = []

    ps_additional_includes.append(ps_drivers_directory)
    ps_additional_includes.append(ps_stubs_directory)
	
    source_list = cpp_src + abspath_filenames(ps_additional_sources)
    include_list = cpp_path + map(lambda x: str(Dir(x).srcnode().abspath), ps_additional_includes)

    # generate polyspace projects
    if ps_version == "2016a":
        # Compiler defines to be generated to parse it and 
        arch_cc_defines = ps_algo_directory + "\\" + algo_name.upper() + "_" + arch.upper() + "_defines.txt"
        
        process_list = []        
        if "TI_CORTEX_A15" not in local_env["_BUILD_TARGET"] and "TI_CORTEX_A8" not in local_env["_BUILD_TARGET"]:
            local_env.Append(CCFLAGS = "--preproc_macros=" + arch_cc_defines)
            arch_cc_includes = None
            algo_ps_defines = None
        else:
            gcc_h_files = filter( lambda x: x[-2:] == ".h", gcc_files)
            arch_cc_includes =  [os.path.dirname(File(h_file).abspath) for h_file in gcc_h_files]
            algo_ps_defines = ps_env.generate_PS_MACRO(arch_cc_defines, File(gcc_h_files[10]).abspath)
            process_list = [algo_ps_defines]
			
        # module data
        ps_module_data[arch] = [source_list, include_list, ps_defines, arch_cc_defines, arch_cc_includes]
        temp_file = ps_algo_directory + "/" + algo_name + "_temp.txt"
        f = open(temp_file, "w+")
        f.write("%s\n" % (ps_module_data))
        f.close()        
        ps_prj_name = ps_algo_directory + "/" + algo_name + "_template.psprj"
        algo_ps_proj = ps_env.generate_ps2016_proj(ps_module_data, target_options, ps_version, ps_prj_name)
        SideEffect(File(temp_file), algo_ps_proj)
        process_list.append(algo_ps_proj)		
        Requires(algo_ps_proj, [obj, arch_cc_defines])		
        files_remove = [ps_prj_name, temp_file, arch_cc_defines]

        generate_alias(component_name + "_ps_2016a_proj", process_list, component_name + '_ps:_ps_2016a_proj', ['Polyspace 2016a prj-file for ' + component_name.upper()+ ' Only DSP support'])
        Clean(component_name + "_ps_2016a_proj", files_remove)
        if algo_name != component_name:
            generate_alias(algo_name + "_ps_2016a_proj", process_list, component_name + '_ps:' + algo_name + '_ps:_ps_2016a_proj', ['Polyspace 2016a prj-file for ' + algo_name.upper()+ ' Only DSP support'])
            Clean(algo_name + "_ps_2016a_proj", files_remove)
		
    generate_alias(component_name + "_ps", process_list, component_name + '_ps')
    Clean(component_name + "_ps", files_remove)
    if algo_name != component_name:
        generate_alias(algo_name + "_ps", process_list, component_name + '_ps:' + algo_name + "_ps")

    Clean("all", files_remove)

if profile:
    FinishSconscriptEntry()
# return library, source files and include paths
Return(["lib", "cpp_src", "cpp_path", "defines"])