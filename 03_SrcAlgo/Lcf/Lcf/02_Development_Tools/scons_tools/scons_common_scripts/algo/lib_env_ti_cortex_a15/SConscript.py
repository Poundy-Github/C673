"""
Filename                  : scons_common_scripts\algo\lib_env_ti_cortex_a15\SConscript.py
Description               : SConscript to set up the build environment for the build of ARM Cortex A15 Libraries. 
							It also generates IDE'S for ECU Libraries.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: lib_env_ti_cortex_a15\SConscript.py
#
# DESCRIPTION: SConscript to set up the build environment for the build of ARM Cortex A15 Libraries. 
#              It also generates IDE'S for ECU Libraries.
#
# INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
#
# CREATION DATE: - 2014/03/18
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:37CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:37CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/algo/lib_env_ti_cortex_a15/project.pj
# CHANGES:                   Revision 1.39 2017/05/30 11:49:43CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.38 2017/04/27 16:18:17CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.37 2016/06/30 08:34:41CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.36 2015/09/23 16:11:13CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between ccs project generation and ti compiler-directory
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:11:13 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.35 2015/06/26 07:06:19CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 7:06:19 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build ARM Cortex A15 library and CCS 5.3 project

#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "scons_arguments", "component_name", "thread_number", "define_list", "algo_name", "gcc_used", "verbose", "help_dict", "profile", "SconscriptTimesTable","install_to_deliverables_dir")
import os, re

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('1')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/ti_arm_cortex_a15_lib_config.scfg")
# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper file
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

#-------------------------
# setup environment
#-------------------------
arm_env = Environment(# list of scons ADAS extensions used
                      tools = ["arm_gcc", "eclipse_cdt_ccs5", "fingerprint",
                               "msvs-patched","msvc-addon"],
                      # path to scons ADAS extensions
                      toolpath = [scons_adas_extensions_path],
                      # path to C6000 compiler
                      # ARM_GCC_CODE_GEN_VERSION = get_arm_gcc_codegen_version(Dir(arm_gcc_code_gen_tool_dir).abspath),
                      ARM_GCC_CODE_GEN_TOOL_PATH = arm_gcc_code_gen_tool_dir,
                      ARM_FASTRTS_PATH = arm_fastrts_dir,
                      # # specify DSP CPU version
                      # ARM_CPU_VERSION = "7A15",
                      # specify processor for scons build
                      BUILD_TARGET = "TI_CORTEX_A15",
                      # use Visual Studio 2005
                      MSVS_VERSION = "8.0",
                      MSVC_VERSION = "8.0")

if not verbose:
    arm_env['CCCOMSTR'] = "\nCompiling ecu cortex a15 $variant \n[$SOURCE]"
    arm_env['CXXCOMSTR'] = "\nCompiling ecu cortex a15 $variant \n[$SOURCE]"
    arm_env['LINKCOMSTR'] = "\nLinking ecu cortex a15 $variant \n[$TARGET]"
    arm_env['PREPROCESSCCCOMSTR'] = '\n$CC -ppc $SOURCES\n-o $TARGETS'
    arm_env['PREPROCESSCXXCOMSTR'] = '\n$CC -ppc $SOURCES\n-o $TARGETS'


# create env for all variants
arm_env_list = []
for variant in variant_list:
    new_variant = arm_env.Clone(variant=variant[0])
    new_variant.Append(CCFLAGS = Split(variant[1]))
    # add common compile options
    if variant[0] == "release":
        for flag in cortex_a15_gcc_rel_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    elif variant[0] == "debug":
        for flag in cortex_a15_gcc_dbg_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    else:
        for flag in cortex_a15_gcc_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    new_variant.Append(CPPDEFINES = Split(variant[2]) + define_list)
    arm_env_list.append(new_variant)

#-------------------------
# build libraries
#-------------------------

# create list which contains the build result, source code and include paths for each variant
ecu_build = {}
ecu_srcs = {}
ecu_cppp = {}
ecu_cppdefs = {}
for variant in variant_list:
    ecu_build[variant[0]] = []
    ecu_srcs[variant[0]] = []
    ecu_cppp[variant[0]] = []
    ecu_cppdefs[variant[0]] = []

for e in arm_env_list:
    env = e.Clone()
    # setup output folder
    arm_algo_build_dir = (build_dir + "/algo/" + algo_name +
                         "/ti_cortex_a15/" + env["variant"])
    arm_algo_deliverables_dir = (deliverables_dir + "/lib/ti_cortex_a15/algo/" +
                         algo_name + "/")

    # src_dir (2nd parameter of VariantDir) is the location of the source dir
    # relative to the location of this SConscript.py
    env.VariantDir(arm_algo_build_dir,
                   "../../../../",
                   duplicate = 0)
    result = SConscript(arm_algo_build_dir + "/01_Source_Code/algo/" + component_name + "/SConscript.py",
                        exports = {
                            "env" : env,
                            "target" : ("lib" + target_name + "_" + env["variant"] + ".a"),
                            "component_name" : component_name,
                            "algo_name" : algo_name
                        })
    # result[0] contains lib, result[1] contains src, result[2] contains include path
    ecu_build[env["variant"]].extend(result[0]) # store build result
    ecu_srcs[env["variant"]].extend(result[1]) # store source files
    ecu_cppp[env["variant"]].extend(result[2]) # store include paths
    ecu_cppdefs[env["variant"]].extend(result[3]) # store defines

    # copy algo lib to 04_Build and 05_Deliverables folders
    # install algo lib to 04_Build and 05_Deliverables folders for selected variant
    if install_to_deliverables_dir in env["variant"]:
        algo_ti_arm_cortex_a15_lib = env.Install([arm_algo_build_dir, arm_algo_deliverables_dir],
                                    result[0][0])
    else:
        algo_ti_arm_cortex_a15_lib = env.Install([arm_algo_build_dir],
                                    result[0][0])

    # generate aliases containing the variant's name
    generate_alias(component_name + "_algo_ti_cortex_a15_" + env["variant"], algo_ti_arm_cortex_a15_lib)
    generate_alias(component_name + "_algo_ecu_" + env["variant"], algo_ti_arm_cortex_a15_lib)
    generate_alias(component_name + "_algo_" + env["variant"], algo_ti_arm_cortex_a15_lib)
    if algo_name != component_name:
        generate_alias(algo_name + "_algo_ti_cortex_a15_" + env["variant"], algo_ti_arm_cortex_a15_lib)
        generate_alias(algo_name + "_algo_ecu_" + env["variant"], algo_ti_arm_cortex_a15_lib)
        generate_alias(algo_name + "_algo_" + env["variant"], algo_ti_arm_cortex_a15_lib)
    generate_alias(env["variant"], algo_ti_arm_cortex_a15_lib)
    generate_alias("all_" + env["variant"], algo_ti_arm_cortex_a15_lib)
    # generate aliases NOT containing the variant's name
    generate_alias(component_name + "_algo_ti_cortex_a15", algo_ti_arm_cortex_a15_lib, component_name + ':algo:ecu:ti_cortex_a15', ['algo lib: Cortex A15'])
    generate_alias(component_name + "_algo_ecu", algo_ti_arm_cortex_a15_lib, component_name + ':algo:ecu')
    generate_alias(component_name + "_algo", algo_ti_arm_cortex_a15_lib, component_name + ':algo')
    if algo_name != component_name:
        generate_alias(algo_name + "_algo_ti_cortex_a15", algo_ti_arm_cortex_a15_lib, component_name + ':' + algo_name + '_algo:ecu:ti_cortex_a15', ['algo lib: Cortex A15'])
        generate_alias(algo_name + "_algo_ecu", algo_ti_arm_cortex_a15_lib, component_name + ':' + algo_name + '_algo:ecu')
        generate_alias(algo_name + "_algo", algo_ti_arm_cortex_a15_lib, component_name + ':' + algo_name + '_algo')
    generate_alias("all", algo_ti_arm_cortex_a15_lib, component_name)
    # Prepare cleaning of build directories
    dirsToClean = map(lambda x : arm_algo_build_dir + "/" + x, src_dirs)
	
    # Issue 298092: If HIL targets are cleaned, stop cleaning of .lib and other output files else clean them.
    
    if COMMAND_LINE_TARGETS:
        for command in COMMAND_LINE_TARGETS:
            if((re.search(algo_name + "_sim", command)) or (re.search(component_name + "_sim", command))):    
                NoClean([algo_ti_arm_cortex_a15_lib, dirsToClean])
            else:
			    Clean(algo_ti_arm_cortex_a15_lib, dirsToClean)
    else:
        Clean(algo_ti_arm_cortex_a15_lib, dirsToClean)
		
#-------------------------
# generate ccs 5.3 project
#-------------------------
variant_names = [variant[0] for variant in variant_list]

if not skip_ide_generation:
    # add include paths
    arm_env.Append(CPPPATH=result[2])

    # workaround: _TMS470_CODE_GEN_TOOL_PATH environment variable is needed to generate CCS Project,
    # but it does not exist when GCC compile is used.
    if gcc_used:
        arm_env["_TMS470_CODE_GEN_TOOL_PATH"] = Dir(tms470_code_gen_tool_dir).abspath
    ide_ccs_algo_ti_cortex_a15 = arm_env.EclipseProject(
                        # specify project name
                        target_name = algo_name.upper() + "_TI_CortexA15_Lib",
                        # specify folder for storing the project
                        target_dir = build_dir + "/algo/" + algo_name + "/ti_cortex_a15/",
                        # specify build variants
                        variants = variant_names,
                        # specify preprocessor defines
                        defines = [define_list + variant[2] for variant in variant_list],
                        # target_type : "lib" or "out"
                        target_type = "lib",
                        # core : "C6000" or "TMS470"
                        core = "TMS470",
                        # specify compiler directory
                        code_gen_dir = tms470_code_gen_tool_dir,
                        # list of target variants (use the same order as in variants)
                        scons_target = [algo_name + "_algo_ti_cortex_a15_" + variant[0] for variant in variant_list],
                        # specify additional argument when running scons
                        scons_argument = "-j" + str(thread_number) + " " + "skip_ide_generation=1" + " " + "build_from_ccs=1" + " " + scons_arguments,
                        # add source files
                        Build_target = result[0],
                        linked_resources = result[1],
                        additional_natures = "")

    # Make sure that compilers are extracted before generation of CCS project
    Requires(ide_ccs_algo_ti_cortex_a15, Dir(tms470_code_gen_tool_dir).abspath)

    generate_alias(component_name + "_ide_ccs_algo_ti_cortex_a15", ide_ccs_algo_ti_cortex_a15, component_name + ':ide:ccs:ti_cortex_a15', ['CCS 5: CortexA15 algo lib'])
    generate_alias(component_name + "_ide_ccs", ide_ccs_algo_ti_cortex_a15, component_name + ':ide:ccs')
    generate_alias(component_name + "_ide", ide_ccs_algo_ti_cortex_a15, component_name + ':ide')
    if algo_name != component_name:
        generate_alias(algo_name + "_ide_ccs_algo_ti_cortex_a15", ide_ccs_algo_ti_cortex_a15, component_name + ':' + algo_name + '_ide:ccs:ti_cortex_a15', ['CCS 5: CortexA15 algo lib'])
        generate_alias(algo_name + "_ide_ccs", ide_ccs_algo_ti_cortex_a15, component_name + ':' + algo_name + '_ide:ccs')
        generate_alias(algo_name + "_ide", ide_ccs_algo_ti_cortex_a15, component_name + ':' + algo_name + '_ide')
    generate_alias("all", ide_ccs_algo_ti_cortex_a15, component_name)

#-------------------------
# prepare visual studio project
#-------------------------

if not skip_ide_generation:

    # get source codes, build result, cpppath from all variants
    tsrcs = []
    tbld = []
    tcpppath = []
    tcppdefs = []
	
	# add built in defines for vs project
    if 'arm_gcc' not in arm_env.Clone()['TOOLS']:
        for index, variant in enumerate(variant_list):
            map(lambda x : ecu_cppdefs[variant[0]].append(x), cortex_a15_built_in_defines_list)
            if "--abi=eabi" in arm_env_list[index].Clone(variant=variant[0])['CCFLAGS']:
		        map(lambda x : ecu_cppdefs[variant[0]].append(x), cortex_a15_built_in_eabi_defines_list)		

    for variant in variant_list:
        tsrcs.extend(ecu_srcs[variant[0]])
        tbld.extend(ecu_build[variant[0]])
        tcpppath.extend(ecu_cppp[variant[0]])
        tcppdefs.append(ecu_cppdefs[variant[0]])

    tsrcs = unique(map(lambda x: "" + x, tsrcs))

    talias = [algo_name + "_algo_ti_cortex_a15_" + variant[0] for variant in variant_list]
    talias += [algo_name + "_qac_ti_cortex_a15"]
    tcppdefs.append([])
    if profile:
        FinishSconscriptEntry()
    Return(["tbld", "tsrcs", "tcpppath", "talias", "tcppdefs"])

if profile:
    FinishSconscriptEntry()