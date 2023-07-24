"""
Filename                  : scons_common_scripts\algo\lib_env_ti_c66xx\SConscript.py
Description               : SConscript to set up the build environment for the build of TI 66xx Libraries. 
							It also generates IDE'S for ECU Libraries.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: lib_env_ti_c66xx\SConscript.py
#
# DESCRIPTION: SConscript to set up the build environment for the build of TI 66xx Libraries. 
#              It also generates IDE'S for ECU Libraries.
#
# INITIAL AUTHOR: Stark-EXT, Roland (uidw1169)
#
# CREATION DATE: - 2014/03/19
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:29CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:29CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/algo/lib_env_ti_c66xx/project.pj
# CHANGES:                   Revision 1.40 2017/05/30 11:36:05CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.39 2017/04/28 05:31:06CEST Singh, Vishal (uidj9083) 
# CHANGES:                   updated
# CHANGES:                   Revision 1.38 2017/04/27 16:15:45CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.37 2016/06/30 08:24:07CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.36 2015/09/23 16:11:28CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between ccs project generation and ti compiler-directory
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:11:28 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.35 2015/07/22 10:58:47CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   replace resolve_contradicting_ccflags by resolve_incompatible_ccflags due to renaming function
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 22, 2015 10:58:48 AM CEST]
# CHANGES:                   Change Package : 359738:1 http://mks-psad:7002/im/viewissue?selection=359738
# CHANGES:                   Revision 1.34 2015/07/06 10:05:33CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   update handling of optimization flags
# CHANGES:                   enhance non-verbose build output
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 6, 2015 10:05:34 AM CEST]
# CHANGES:                   Change Package : 353994:1 http://mks-psad:7002/im/viewissue?selection=353994
# CHANGES:                   Revision 1.33 2015/06/26 07:06:21CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 7:06:21 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build TI 66xx library and CCS 5.3 project

#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "scons_arguments", "component_name", "thread_number", "define_list", "algo_name", "verbose", "help_dict", "profile", "SconscriptTimesTable","install_to_deliverables_dir")
import os, re

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('1')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/ti_c66xx_lib_config.scfg")
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
dsp_env = Environment(# list of scons ADAS extensions used
                      tools = ["tms320dm6000", "eclipse_cdt_ccs5", "fingerprint",
                               "msvs-patched","msvc-addon"],
                      # path to scons ADAS extensions
                      toolpath = [scons_adas_extensions_path],
                      # path to C6000 compiler
                      C6000_CODE_GEN_TOOL_PATH = c6000_code_gen_tool_dir,
                      # path to EDMA driver
                      EDMA3_DRV_DIR = edma3_drv_dir,
                      # specify processor for scons build
                      BUILD_TARGET = "TI_C66XX",
                      # use Visual Studio 2005
                      MSVS_VERSION = "8.0",
                      MSVC_VERSION = "8.0")

if not verbose:
    dsp_env['CCCOMSTR'] = "\nCompiling ecu c66xx $variant\n[$SOURCE]"
    dsp_env['CXXCOMSTR'] = "\nCompiling ecu c66xx $variant\n[$SOURCE]"
    dsp_env['LINKCOMSTR'] = "\nLinking ecu c66xx $variant\n[$TARGET]"
    dsp_env['PREPROCESSCCCOMSTR'] = '\n$CC -ppc $SOURCES\n-o $TARGETS'
    dsp_env['PREPROCESSCXXCOMSTR'] = '\n$CC -ppc $SOURCES\n-o $TARGETS'

# create env for all variants
dsp_env_list = []
for variant in variant_list:
    new_variant = dsp_env.Clone(variant=variant[0])
    new_variant.Append(CCFLAGS = Split(variant[1]))
    # add common compile options
    if variant[0] == "release":
        for flag in c66xx_rel_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    elif variant[0] == "debug":
        for flag in c66xx_dbg_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    else:
        for flag in c66xx_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    new_variant.Append(CPPDEFINES = Split(variant[2]) + define_list)
    # choose possibly contradicting ccflags, see common_config.scfg
    new_variant['CCFLAGS'] = resolve_incompatible_ccflags(new_variant['CCFLAGS'], c66xx_common_ccflags_to_check, variant[1])
    # add to environment lists
    dsp_env_list.append(new_variant)

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

for e in dsp_env_list:
    env = e.Clone()
    # setup output folder
    dsp_algo_build_dir = (build_dir +"/algo/" +algo_name +
                         "/ti_c66xx/" + env["variant"])
						 
    dsp_algo_deliverables_dir = (deliverables_dir + "/lib/ti_c66xx/algo/" +
                         algo_name + "/")

    # src_dir (2nd parameter of VariantDir) is the location of the source dir
    # relative to the location of this SConscript.py
    env.VariantDir(dsp_algo_build_dir,
                   "../../../../",
                   duplicate = 0)
    result = SConscript(dsp_algo_build_dir + "/01_Source_Code/" + component_name + "/SConscript.py",
                        exports = {
                            "env" : env,
                            "target" : (target_name + "_" + env["variant"] + ".lib"),
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
        algo_ti_c66xx_lib = env.Install([dsp_algo_build_dir, dsp_algo_deliverables_dir],
                                    result[0][0])

    else:
        algo_ti_c66xx_lib = env.Install([dsp_algo_build_dir],
                                    result[0][0])
    # generate aliases containing the variant's name
    generate_alias(component_name + "_algo_ti_c66xx_" + env["variant"], algo_ti_c66xx_lib)
    generate_alias(component_name + "_algo_ecu_" + env["variant"], algo_ti_c66xx_lib)
    generate_alias(component_name + "_algo_" + env["variant"], algo_ti_c66xx_lib)
    if algo_name != component_name:
        generate_alias(algo_name + "_algo_ti_c66xx_" + env["variant"], algo_ti_c66xx_lib)
        generate_alias(algo_name + "_algo_ecu_" + env["variant"], algo_ti_c66xx_lib)
        generate_alias(algo_name + "_algo_" + env["variant"], algo_ti_c66xx_lib)
    generate_alias(env["variant"], algo_ti_c66xx_lib)
    generate_alias("all_" + env["variant"], algo_ti_c66xx_lib)
    # generate aliases NOT containing the variant's name
    generate_alias(component_name + "_algo_ti_c66xx", algo_ti_c66xx_lib, component_name + ':algo:ecu:ti_c66xx', ['algo lib: C66xx'])
    generate_alias(component_name + "_algo_ecu", algo_ti_c66xx_lib, component_name + ':algo:ecu')
    generate_alias(component_name + "_algo", algo_ti_c66xx_lib, component_name + ':algo')
    if algo_name != component_name:
        generate_alias(algo_name + "_algo_ti_c66xx", algo_ti_c66xx_lib, component_name + ':' + algo_name + '_algo:ecu:ti_c66xx', ['algo lib: C66xx'])
        generate_alias(algo_name + "_algo_ecu", algo_ti_c66xx_lib, component_name + ':' + algo_name + '_algo:ecu')
        generate_alias(algo_name + "_algo", algo_ti_c66xx_lib, component_name + ':' + algo_name + '_algo')
    generate_alias("all", algo_ti_c66xx_lib, component_name)
    # Prepare cleaning of build directories
    dirsToClean = map(lambda x : dsp_algo_build_dir + "/" + x, src_dirs)
	
    # Issue 298092: If HIL targets are cleaned, stop cleaning of .lib and other output files else clean them.
    
    if COMMAND_LINE_TARGETS:
        for command in COMMAND_LINE_TARGETS:
            if ((re.search(algo_name + "_sim", command)) or (re.search(component_name + "_sim", command))):    
                NoClean([algo_ti_c66xx_lib, dirsToClean])
            else:
			    Clean(algo_ti_c66xx_lib, dirsToClean)
    else:
	    Clean(algo_ti_c66xx_lib, dirsToClean)
		
#-------------------------
# generate ccs 5.3 project
#-------------------------
variant_names = [variant[0] for variant in variant_list]

if not skip_ide_generation:
    # add include paths
    dsp_env.Append(CPPPATH=result[2])
    ide_ccs_algo_ti_c66xx = dsp_env.EclipseProject(
                        # specify project name
                        target_name = algo_name.upper() + "_TI_C66xx_Lib",
                        # specify folder for storing the project
                        target_dir = build_dir + "/algo/" + algo_name + "/ti_c66xx/",
                        # specify build variants
                        variants = variant_names,
                        # specify preprocessor defines
                        defines = [define_list + variant[2] for variant in variant_list],
                        # target_type : "lib" or "out"
                        target_type = "lib",
                        # core : "C6000" or "TMS470"
                        core = "C6000",
                        # specify compiler directory
                        code_gen_dir = c6000_code_gen_tool_dir,
                        # list of target variants (use the same order as in variants)
                        scons_target = [algo_name + "_algo_ti_c66xx_" + variant[0] for variant in variant_list],
                        # specify additional argument when running scons
                        scons_argument = "-j" + str(thread_number) + " " + "skip_ide_generation=1" + " " + "build_from_ccs=1" + " " + scons_arguments,
                        # add source files
                        Build_target = result[0],
                        linked_resources = result[1],
                        additional_natures = "")

    # Make sure that compilers are extracted before generation of CCS project
    Requires(ide_ccs_algo_ti_c66xx, Dir(c6000_code_gen_tool_dir).abspath)

    generate_alias(component_name + "_ide_ccs_algo_ti_c66xx", ide_ccs_algo_ti_c66xx, component_name + ':ide:ccs:ti_c66xx', ['CCS 5: C66xx algo lib'])
    generate_alias(component_name + "_ide_ccs", ide_ccs_algo_ti_c66xx, component_name + ':ide:ccs')
    generate_alias(component_name + "_ide", ide_ccs_algo_ti_c66xx, component_name + ':ide')
    if algo_name != component_name:
        generate_alias(algo_name + "_ide_ccs_algo_ti_c66xx", ide_ccs_algo_ti_c66xx, component_name + ':' + algo_name + '_ide:ccs:ti_c66xx', ['CCS 5: C66xx algo lib'])
        generate_alias(algo_name + "_ide_ccs", ide_ccs_algo_ti_c66xx, component_name + ':' + algo_name + '_ide:ccs')
        generate_alias(algo_name + "_ide", ide_ccs_algo_ti_c66xx, component_name + ':' + algo_name + '_ide')
    generate_alias("all", ide_ccs_algo_ti_c66xx, component_name)

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
    for index, variant in enumerate(variant_list):
        map(lambda x : ecu_cppdefs[variant[0]].append(x), c66xx_built_in_defines_list)
        if "--abi=eabi" in dsp_env_list[index].Clone(variant=variant[0])['CCFLAGS']:
            map(lambda x : ecu_cppdefs[variant[0]].append(x), c66xx_built_in_eabi_defines_list)		

    for variant in variant_list:
        tsrcs.extend(ecu_srcs[variant[0]])
        tbld.extend(ecu_build[variant[0]])
        tcpppath.extend(ecu_cppp[variant[0]])
        tcppdefs.append(ecu_cppdefs[variant[0]])

    tsrcs = unique(map(lambda x: "" + x, tsrcs))

    talias = [algo_name + "_algo_ti_c66xx_" + variant[0] for variant in variant_list]
    talias += [algo_name + "_qac_ti_c66xx"]
    tcppdefs.append([])
    if profile:
        FinishSconscriptEntry()
    Return(["tbld", "tsrcs", "tcpppath", "talias", "tcppdefs"])

if profile:
    FinishSconscriptEntry()