"""
Filename                  : scons_common_scripts\sim\sim_env\SConscript_simenv.py
Description               : SConscript to create build environment for pc simulation targets.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: sim\sim_env\SConscript_simenv.py
#
# DESCRIPTION: SConscript to create build environment for pc simulation targets.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/07/30
#
# LAST CHANGE:      $Date: 2021/12/13 19:06:33CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_simenv.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:06:33CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/sim/sim_env/project.pj
# CHANGES:                   Revision 1.44 2017/10/10 06:45:11CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   SCONS topics to take care in next release
# CHANGES:                   Revision 1.43 2017/07/19 06:51:31CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   [Mainstream] SCONS does not copy dlls to the desired location
# CHANGES:                   Revision 1.42 2017/05/30 13:59:22CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.41 2017/04/27 16:10:08CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.40 2016/07/12 06:41:20CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons.
# CHANGES:                   Revision 1.39 2016/07/01 06:18:52CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.38 2015/10/16 08:57:49CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Sconscript error if filename contains dot
# CHANGES:                   - Added comments -  uidr2134 [Oct 16, 2015 8:57:50 AM CEST]
# CHANGES:                   Change Package : 387076:1 http://mks-psad:7002/im/viewissue?selection=387076
# CHANGES:                   Revision 1.37 2015/09/23 07:50:53CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   TSA Feature request: specific copy operation of utils in build folder
# CHANGES:                   --- Added comments ---  uidr2134 [Sep 23, 2015 7:50:54 AM CEST]
# CHANGES:                   Change Package : 379400:1 http://mks-psad:7002/im/viewissue?selection=379400
# CHANGES:                   Revision 1.36 2015/07/22 12:46:31CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   remove bug from undefined variable
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 22, 2015 12:46:32 PM CEST]
# CHANGES:                   Change Package : 359738:1 http://mks-psad:7002/im/viewissue?selection=359738
# CHANGES:                   Revision 1.35 2015/07/22 10:58:24CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   replace resolve_contradicting_ccflags by resolve_incompatible_ccflags due to renaming function
# CHANGES:                   update call of that function
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 22, 2015 10:58:25 AM CEST]
# CHANGES:                   Change Package : 359738:1 http://mks-psad:7002/im/viewissue?selection=359738
# CHANGES:                   Revision 1.34 2015/07/06 10:04:52CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   update handling of warning flags
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 6, 2015 10:04:53 AM CEST]
# CHANGES:                   Change Package : 353994:1 http://mks-psad:7002/im/viewissue?selection=353994
# CHANGES:                   Revision 1.33 2015/06/26 08:34:52CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 8:34:52 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to create build env for simulation target

#-------------------------
# import
#-------------------------
import os
Import("skip_ide_generation", "exception_handler_file_list", "exception_handler","scons_arguments", "component_name", "build_from_ide", "env", "thread_number", "define_list", "algo_name", "verbose", "use_shared_sconscript", "help_dict", "profile", "SconscriptTimesTable","install_to_deliverables_dir", "project_name")

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('2')

#-------------------------
# read configuration
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/simenv_config.scfg")
# read gscons_exception_handler
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)	

# get relative path of a file
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+"\simenv_config.scfg"
#-------------------------
# read target configuration
#-------------------------
# check whether a component's utility is being built:
if component_name.lower() + "_utils" in sconscript_dir:
    build_utils = True
else:
    build_utils = False

try:
    target_ext
except NameError,e:
    exception_warning(e,exception_handler,msg)
    target_ext = ".dll"

try:
    target_dll_name
except NameError,e:
    exception_warning(e,exception_handler,msg)

try:
    target_name
except NameError,e:
    exception_warning(e,exception_handler,msg)
    target_name = target_dll_name

try:
    special_copy_operation
except NameError,e:
    exception_warning(e,exception_handler,msg)
    special_copy_operation = False
	
try:
    special_copy_dict
except NameError,e:
    exception_warning(e,exception_handler,msg)
    special_copy_dict = []
#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

#-------------------------
# mts measurement directory
#-------------------------
try:
    build_folder_name
except NameError,e:
    exception_warning(e,exception_handler,msg)
    build_folder_name = folder_name

try:
    folder_name
except NameError,e:
    exception_error(e,"in simenv_config.scfg")

try:
    component_name_for_sim_folder
except NameError,e:
    exception_error(e,"in simenv_config.scfg")

try:
    algo_name_for_build_folder
except NameError,e:
    exception_warning(e,exception_handler,msg)
    algo_name_for_build_folder = component_name_for_sim_folder

# read method to copy pc-simulation targets
Import("custom_sim_copy")

try:
    vc_project_name
except NameError,e:
    exception_error(e,"in simenv_config.scfg")

try:
    scons_target_name
except NameError,e:
    exception_error(e,"in simenv_config.scfg")

try:
    mts_measurement_dir
except NameError,e:
    mts_measurement_dir = (testing_path_from_sconstruct + "06_Test_Tools/mts_measurement/dll/algo/" + algo_name_for_build_folder + "_sim/")


#-------------------------
# setup environment
#-------------------------
# adapt mode of output in construction environment
if not verbose:
    env['CCCOMSTR'] = "\nCompiling pc $variant\n[$SOURCE]"
    env['CXXCOMSTR'] = "\nCompiling pc $variant\n[$SOURCE]"
    env['SHCCCOMSTR'] = "\nCompiling pc $variant \n[$SOURCE]"
    env['SHCXXCOMSTR'] = "\nCompiling pc $variant \n[$SOURCE]"
    env['LINKCOMSTR'] = "\nLinking pc $variant \n[$TARGET]"
    env['PREPROCESSCCCOMSTR'] = '\n$CC -ppc $SOURCES \n-o $TARGETS'
    env['PREPROCESSCXXCOMSTR'] = '\n$CC -ppc $SOURCES \n-o $TARGETS'

# create env for all variants
pc_env_list = []
for variant in variant_list:
    new_variant = env.Clone(variant=variant[0])
    new_variant.Append(CCFLAGS = Split(variant[1]))
    # add common compile options
    if variant[0] == "release" or variant[0] == "rel_exp":
        for flag in sim_rel_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    elif variant[0] == "debug" or variant[0] == "dbg_exp":
        for flag in sim_dbg_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    else:
        pass
    new_variant.Append(CPPDEFINES = Split(variant[2]) + define_list)
    new_variant.Append(LINKFLAGS = Split(variant[3]))
    # add common linker options in case a dll is built
    if target_ext == ".dll":
        if variant[0] == "release" or variant[0] == "rel_exp":
            for flag in sim_rel_common_linkflags.split():
                new_variant.PrependUnique(LINKFLAGS = flag)
        elif variant[0] == "debug" or variant[0] == "dbg_exp":
            for flag in sim_dbg_common_linkflags.split():
                new_variant.PrependUnique(LINKFLAGS = flag)
        else:
            pass
    # choose possibly contradicting ccflags, see common_config.scfg
    new_variant['CCFLAGS'] = resolve_incompatible_ccflags(ccflags = new_variant['CCFLAGS'], 
                                                          pattern_to_check = sim_common_ccflags_to_check, 
                                                          ccflags_local = variant[1], 
                                                          target_type = env['_BUILD_TARGET'], 
                                                          target = target_name)
    # add to environment lists
    pc_env_list.append(new_variant)

#-------------------------
# build doxygen documentation
#-------------------------
if generate_doxygen:
    vars()[component_name + "_" + scons_doxygen_target_name] = env.Doxygen(doxy_file_name)
    # restore image
    env.AddPostAction(vars()[component_name + "_" + scons_doxygen_target_name], Copy(Dir(os.path.join("doxygen", "html")).abspath, File(os.path.join("doxygen", "style", "conti.png")).abspath))
    convert_xml_to_doors = "cd ..\\" + component_name + "_sim\sim_swc_" + component_name + "\ && ..\..\..\..\\02_Development_Tools\movpy\movpy.exe ./convert_xml.py ./doxygen/xml ./doxygen/doors.txt && cd ../../" + component_name
    env.AddPostAction(vars()[component_name + "_" + scons_doxygen_target_name], Action(convert_xml_to_doors))
    generate_alias(component_name + "_" + scons_doxygen_target_name, vars()[component_name + "_" + scons_doxygen_target_name], component_name + ':doxy', ['doxygen docu'])
    generate_alias("all", vars()[component_name + "_" + scons_doxygen_target_name], component_name)

#-------------------------
# build algo pc library
#-------------------------
if generate_algo_lib:
# create dictionary which contains the build result, source code and include paths for each variant
    lib_build = {}
    lib_srcs = {}
    lib_cppp = {}
    lib_cppdefs = {}
    for variant in variant_list:
        lib_build[variant[0]] = []
        lib_srcs[variant[0]] = []
        lib_cppp[variant[0]] = []
        lib_cppdefs[variant[0]] = []

    for e in pc_env_list:
        env = e.Clone()

        # setup output folder
        pc_algo_build_dir = (build_dir + "/algo/" + algo_name + "/pc/" + env["variant"])
        pc_algo_deliverables_dir = (deliverables_dir + "/lib/pc/" + algo_name + "/")
        env["CCPDBFLAGS"] = "/Zi /Fd${TARGET}.pdb"

        # src_dir (2nd parameter of VariantDir) is the location of the source dir
        # relative to the location of this SConscript.py
        # case switch necessary because of different folder levels for utilities and non-utilities in sr and tsa
        if not build_utils:
            env.VariantDir(pc_algo_build_dir, "../../../../", duplicate = 0)
        else:
            env.VariantDir(pc_algo_build_dir, "../../../", duplicate = 0)
        result = SConscript(pc_algo_build_dir + "/01_Source_Code/" + component_name + "/SConscript.py",
                            exports = {
                                "env" : env,
                                "target" : algo_name + "_algo_pc_" + env["variant"] + ".lib",
                                "component_name" : component_name,
                                "algo_name" : algo_name
                            })

        lib_build[env["variant"]].extend(result[0]) # store build result
        lib_srcs[env["variant"]].extend(result[1]) # store source files
        lib_cppp[env["variant"]].extend(result[2]) # store include paths
        lib_cppdefs[env["variant"]].extend(result[3]) # store defines

        if copy_algo_lib_to_deliverables:
            # install .lib to Build and Deliverables folder for selected variant
            if install_to_deliverables_dir in env["variant"]:
                # copy .lib to Build and Deliverables folder.
                algo_pc_lib = env.Install([pc_algo_build_dir, pc_algo_deliverables_dir], result[0][0])
            else:
                # copy .lib to Build folder.
                algo_pc_lib = env.Install([pc_algo_build_dir], result[0][0])
        else:
            # copy .lib to Build folder.
            algo_pc_lib = env.Install([pc_algo_build_dir], result[0][0])


        generate_alias(component_name + "_algo_pc_" + env["variant"], algo_pc_lib)
        generate_alias(component_name + "_algo_pc", algo_pc_lib, component_name + ':algo:pc', ['algo lib: pc'])
        generate_alias(component_name + "_algo_" + env["variant"], algo_pc_lib)
        generate_alias(component_name + "_algo", algo_pc_lib, component_name + ':algo')
        if algo_name != component_name:
            generate_alias(algo_name + "_algo_pc_" + env["variant"], algo_pc_lib)
            generate_alias(algo_name + "_algo_pc", algo_pc_lib, component_name + ':' + algo_name + '_algo:pc', ['algo lib: pc'])
            generate_alias(algo_name + "_algo_" + env["variant"], algo_pc_lib)
            generate_alias(algo_name + "_algo", algo_pc_lib, component_name + ':' + algo_name + '_algo')

        if algo_name != component_name:
            generate_alias(algo_name + "_" + scons_target_name + "_" + env["variant"], algo_pc_lib)
            generate_alias(algo_name + "_" + scons_target_name, algo_pc_lib)
            if build_utils: # check whether utilities are being built
                generate_alias(algo_name + "_utils_" + env["variant"], algo_pc_lib)
                generate_alias(algo_name + "_utils", algo_pc_lib)
            else:
                generate_alias(algo_name + "_sim_pc_" + env["variant"], algo_pc_lib)
                generate_alias(algo_name + "_sim_pc", algo_pc_lib)
                generate_alias(algo_name + "_sim_" + env["variant"], algo_pc_lib)
                generate_alias(algo_name + "_sim", algo_pc_lib)

        generate_alias(component_name + "_" + scons_target_name + "_" + env["variant"], algo_pc_lib)
        generate_alias(component_name + "_" + scons_target_name, algo_pc_lib)
        if build_utils: # check whether utilities are being built
            generate_alias(component_name + "_utils_" + env["variant"], algo_pc_lib)
            generate_alias(component_name + "_utils", algo_pc_lib)
        else:
            generate_alias(component_name + "_sim_pc_" + env["variant"], algo_pc_lib)
            generate_alias(component_name + "_sim_pc", algo_pc_lib)
            generate_alias(component_name + "_sim_" + env["variant"], algo_pc_lib)
            generate_alias(component_name + "_sim", algo_pc_lib)
        generate_alias(env["variant"], algo_pc_lib)
        generate_alias("all_" + env["variant"], algo_pc_lib)
        generate_alias("all", algo_pc_lib)
        # Prepare cleaning of build directories
        dirsToClean = map(lambda x : pc_algo_build_dir + "/" + x, src_dirs)
        Clean(algo_pc_lib, dirsToClean)
        # Clean(algo_pc_lib, pc_algo_deliverables_dir)

#-------------------------
# build target
#-------------------------
# add libpath and lib to env
for variant, env in zip(variant_list, pc_env_list):
    env.Append(LIBPATH = map(lambda x: Dir(x).abspath, Split(variant[4])))
    env.Append(LIBS = Split(variant[5]))

# create list which contains the build result, source code and include paths for each variant
sim_build = {}
sim_srcs = {}
sim_cppp = {}
sim_cppdefs = {}
for variant in variant_list:
    sim_build[variant[0]] = []
    sim_srcs[variant[0]] = []
    sim_cppp[variant[0]] = []
    sim_cppdefs[variant[0]] = []

for e in pc_env_list:
    env = e.Clone()

    # setup output folder
    if not build_utils:
        pc_sim_build_dir = (build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" + build_folder_name + "/" + env["variant"])
        env.VariantDir(pc_sim_build_dir, "../../../../", duplicate = 0)
        sconscript_folder = pc_sim_build_dir + "/03_Workspace/Component_Workspace/" + component_name_for_sim_folder + "_sim/" + folder_name
    else:
        pc_sim_build_dir = (build_dir + component_name + "_utils/" + build_folder_name + "/" + env["variant"])
        env.VariantDir(pc_sim_build_dir, "../../../", duplicate = 0)
        sconscript_folder = pc_sim_build_dir + "/03_Workspace/" + component_name + "_utils/" + folder_name
    try:
        pc_sim_deliverables_dir
    except NameError,e:
        exception_warning(e,exception_handler,msg)
        pc_sim_deliverables_dir = (deliverables_dir + project_name + "/" + component_name.upper() + "_sim" + "/")

    # create pdb file in build folder
    env["CCPDBFLAGS"] = "/Zi /Fd${TARGET}.pdb"
    env["PDB"] = "${TARGET.base}.pdb"

    # src_dir (2nd parameter of VariantDir) is the location of the source dir
    # relative to the location of this SConscript.py
    result = SConscript(sconscript_folder + "/SConscript.py",
                        exports = {
                            "env" : env,
                            "target" : target_name + target_ext,
                            "component_name" : component_name,
                            "vc_project_name" : vc_project_name,
                            "folder_name" : folder_name,
                            "build_folder_name" : build_folder_name,
                            "component_name_for_sim_folder" : component_name_for_sim_folder,
                            "algo_name_for_build_folder" : algo_name_for_build_folder,
                            "scons_target_name" : scons_target_name,
                            "algo_name" : algo_name
                        })
    sim_build[env["variant"]].extend(result[0]) # store build result
    sim_srcs[env["variant"]].extend(result[1]) # store source files
    sim_cppp[env["variant"]].extend(result[2]) # store include paths
    try: # avoid clash with possible existing component-specific SConscript-files
        sim_cppdefs[env["variant"]].extend(result[4]) # store defines
    except IndexError:
        sim_cppdefs[env["variant"]].extend([''])
    Requires(result[0], algo_name + "_fingerprint")

    sim_pc_wrapper_lib = []
    # Determine targets to install in build folder
    if target_ext == '.dll':
        results_to_copy = [result[0][0], result[0][2]]
    elif target_ext == '.exe':
        if (len(result[0]) >= 3):
          results_to_copy = [result[0][0], result[0][2]]
        else:
          results_to_copy = [result[0][0], result[0][1]]
    elif target_ext == '.lib':
        results_to_copy = [result[0][0]]
    sim_pc_wrapper_lib += env.Install([pc_sim_build_dir], results_to_copy)


    if special_copy_operation:
        for dict in special_copy_dict:
            if dict.has_key('copy_only') and dict['copy_only']:
                sim_pc_wrapper_lib += env.Install(dict['dest'] + env['variant'], results_to_copy)
        for dict in special_copy_dict:
            if dict.has_key('copy_rename') and dict['copy_rename']:
                if dict.has_key('variant') and env['variant'] == dict['variant']:
                    if dict.has_key('replace_name') and dict['replace_name'] != '':
                        path, filename = os.path.split(str(result[0][0]))
                        name, extname = os.path.splitext(filename)
                        new_filename = dict['replace_name'] + extname
                    else:
                        new_filename = ''
                    sim_pc_wrapper_lib += env.InstallAs(dict['dest'] + new_filename, result[0][0])

    # In case non-utilities are built, they need to be installed to certain directories in addition to 04_Build.
    if not build_utils:
        # ----------------------------------------
        # Andre Fischer-Ext (uidg5297) 2014-07-03:
        # ----------------------------------------
        # While MTS is opened, copying dll/pdb files to mts folder fails.
        # So: the dll/pdb in use by MTS are renamed and only then the new dll/pdb files are copied.
        # Because of scons dependency handling, the way over scripting language
        # and creating an empty file dummy.file serves as a workaround.
        dll_file = Dir(mts_measurement_dir).abspath + "\\" + target_name + ".dll"
        dll_ren_file = dll_file + "_ren"
        pdb_file = Dir(mts_measurement_dir).abspath + "\\" + target_name + ".pdb"
        pdb_ren_file = pdb_file + "_ren"
        del_and_ren = ["@echo off && IF EXIST %s (echo Delete File: %s && DEL /F %s)"
                                                   % (dll_ren_file, dll_ren_file, dll_ren_file),
                           "@echo off && IF EXIST %s (echo Delete File: %s && DEL /F %s)"
                                                   % (pdb_ren_file, pdb_ren_file, pdb_ren_file),
                           "@echo off && IF EXIST %s (echo Rename File: %s to %s && MOVE %s %s >nul)"
                                                   % (dll_file, dll_file, dll_ren_file, dll_file, dll_ren_file),
                           "@echo off && IF EXIST %s (echo Rename File: %s to %s && MOVE %s %s >nul)"
                                                   % (pdb_file, pdb_file, pdb_ren_file, pdb_file, pdb_ren_file),
                           "@echo off && cd . > $TARGET"]

        if not custom_sim_copy: # default way of installing simulation targets
            del_and_ren_file = pc_sim_build_dir + "/03_Workspace/algo/" + component_name_for_sim_folder + "_sim/" + folder_name + "/dummy.file"
            # distinguish the cases when the build is performed via visual studio or via the command line
            if not build_from_ide:
                # install DLL and .pdb to Build, Deliverables and Testing folders for selected variant
                if install_to_deliverables_dir in env["variant"]:
                    # copy DLL and .pdb to Build, Deliverables and Testing folders.
                    del_and_ren_action = Command(del_and_ren_file, results_to_copy, del_and_ren)
                    sim_pc_wrapper_lib += env.Install([pc_sim_deliverables_dir, mts_measurement_dir],
                                                     results_to_copy)
                    # Prevent parallel execution of the two previous commands
                    Requires(sim_pc_wrapper_lib, del_and_ren_action)
            else:
                if env["variant"] in BUILD_TARGETS[0]:
                    del_and_ren_action = Command(del_and_ren_file, results_to_copy, del_and_ren)
                    # install DLL and .pdb to Build, Deliverables and Testing folders for selected variant
                    if install_to_deliverables_dir in env["variant"]:
                        # copy DLL and .pdb to Build, Deliverables and Testing folders.
                        sim_pc_wrapper_lib += env.Install([pc_sim_deliverables_dir, mts_measurement_dir],
                                                         results_to_copy)
                    else:
                        # copy DLL and .pdb to Build and Testing folders.
                        sim_pc_wrapper_lib += env.Install([mts_measurement_dir],
                                                     results_to_copy)
                    # Prevent parallel execution of the two previous commands
                    Requires(sim_pc_wrapper_lib, del_and_ren_action)

        else: # custom way of installing simulation targets
            # install DLL and .pdb to Build, Deliverables and Testing folders for selected variant
            if "release" in env["variant"]:
                del_and_ren_file = pc_sim_build_dir + "/03_Workspace/algo/" + component_name_for_sim_folder + "_sim/" + folder_name + "/dummy.file"
                # copy DLL and .pdb to Build, Deliverables and Testing folders.
                del_and_ren_action = Command(del_and_ren_file, results_to_copy, del_and_ren)
                sim_pc_wrapper_lib += env.Install([pc_sim_deliverables_dir, mts_measurement_dir],
                                                 results_to_copy)
                # Prevent parallel execution of the two previous commands
                Requires(sim_pc_wrapper_lib, del_and_ren_action)
            else:
                dll_file = Dir(mts_measurement_dir).abspath + "\\" + env["variant"] + "\\" + target_name + ".dll"
                dll_ren_file = dll_file + "_ren"
                pdb_file = Dir(mts_measurement_dir).abspath + "\\" + env["variant"] + "\\" + target_name + ".pdb"
                pdb_ren_file = pdb_file + "_ren"
                del_and_ren = ["@echo off && IF EXIST %s (echo Delete File: %s && DEL /F %s)"
                                                           % (dll_ren_file, dll_ren_file, dll_ren_file),
                                   "@echo off && IF EXIST %s (echo Delete File: %s && DEL /F %s)"
                                                           % (pdb_ren_file, pdb_ren_file, pdb_ren_file),
                                   "@echo off && IF EXIST %s (echo Rename File: %s to %s && MOVE %s %s >nul)"
                                                           % (dll_file, dll_file, dll_ren_file, dll_file, dll_ren_file),
                                   "@echo off && IF EXIST %s (echo Rename File: %s to %s && MOVE %s %s >nul)"
                                                           % (pdb_file, pdb_file, pdb_ren_file, pdb_file, pdb_ren_file),
                                   "@echo off && cd . > $TARGET"]
                del_and_ren_file = pc_sim_build_dir + "/03_Workspace/algo/" + component_name_for_sim_folder + "_sim/" + folder_name + "/" + env["variant"] + "/dummy.file"
                # copy DLL and .pdb to Build, Deliverables and Testing folders.
                del_and_ren_action = Command(del_and_ren_file, results_to_copy, del_and_ren)
                sim_pc_wrapper_lib += env.Install([mts_measurement_dir + "\\" + env["variant"]],
                                                 results_to_copy)
                # Prevent parallel execution of the two previous commands
                Requires(sim_pc_wrapper_lib, del_and_ren_action)
    # generate aliases containing the variant's name
    if algo_name != component_name:
        generate_alias(algo_name + "_" + scons_target_name + "_" + env["variant"], sim_pc_wrapper_lib)
        if build_utils: # check whether utilities are being built
            generate_alias(algo_name + "_utils_"+ env["variant"], sim_pc_wrapper_lib)
        else:
            generate_alias(algo_name + "_sim_pc_" + env["variant"], sim_pc_wrapper_lib)
            generate_alias(algo_name + "_sim_" + env["variant"], sim_pc_wrapper_lib)

    generate_alias(component_name + "_" + scons_target_name + "_" + env["variant"], sim_pc_wrapper_lib)
    if build_utils: # check whether utilities are being built
        generate_alias(algo_name + "_utils_" + env["variant"], sim_pc_wrapper_lib)
    else:
        generate_alias(component_name + "_sim_pc_" + env["variant"], sim_pc_wrapper_lib)
        generate_alias(component_name + "_sim_" + env["variant"], sim_pc_wrapper_lib)
    generate_alias(env["variant"], sim_pc_wrapper_lib)
    generate_alias("all_" + env["variant"], sim_pc_wrapper_lib)

    # generate aliases NOT containing the variant's name
    if algo_name != component_name:
        generate_alias(algo_name + "_" + scons_target_name, sim_pc_wrapper_lib, component_name + ':' + algo_name + '_sim:pc:' + scons_target_name, ['PC sim: ' + scons_target_name])
        if build_utils: # check whether utilities are being built
            generate_alias(algo_name + "_" + scons_target_name, sim_pc_wrapper_lib, component_name + ':' + algo_name + '_utils:' + scons_target_name, ['PC sim: ' + scons_target_name])
            generate_alias(algo_name + "_utils", sim_pc_wrapper_lib, component_name + ':' + algo_name + '_utils')
        else:
            generate_alias(algo_name + "_sim_pc", sim_pc_wrapper_lib, component_name + ':' + algo_name + '_sim:pc')
            generate_alias(algo_name + "_sim", sim_pc_wrapper_lib, component_name + ':' + algo_name + '_sim')

    generate_alias(component_name + "_" + scons_target_name, sim_pc_wrapper_lib, component_name + ':sim:pc:' + scons_target_name, ['PC sim: ' + scons_target_name])
    if build_utils: # check whether utilities are being built
        generate_alias(component_name + "_" + scons_target_name, sim_pc_wrapper_lib, component_name + ':utils:' + scons_target_name, ['PC sim: ' + scons_target_name])
        generate_alias(component_name + "_utils", sim_pc_wrapper_lib, component_name + ':utils')
    else:
        generate_alias(component_name + "_sim_pc", sim_pc_wrapper_lib, component_name + ':sim:pc')
        generate_alias(component_name + "_sim", sim_pc_wrapper_lib, component_name + ':sim')
    generate_alias("all", sim_pc_wrapper_lib, component_name)
    # Prepare cleaning of build directories
    dirsToClean = map(lambda x : pc_sim_build_dir + "/" + x, src_dirs)
    Clean(sim_pc_wrapper_lib, dirsToClean)
    # Clean(sim_pc_wrapper_lib,pc_sim_deliverables_dir)

#-------------------------
# build/prepare msvc project
#-------------------------
if not skip_ide_generation:
    # get source files, header files, build results, cpppath from all variants
    tsrcs = []
    tbld = []
    tcpppath = []
    tcppdefs = []
    talias = []
    for variant in variant_list:
        if generate_algo_lib:
            tsrcs.extend(lib_srcs[variant[0]])
            tbld.extend(lib_build[variant[0]])
            tcpppath.extend(lib_cppp[variant[0]])
            tcppdefs.append(lib_cppdefs[variant[0]])
            talias += [algo_name + "_algo_pc_" + variant[0]]
        tsrcs.extend(sim_srcs[variant[0]])
        tbld.extend(sim_build[variant[0]])
        tcpppath.extend(sim_cppp[variant[0]])
        tcppdefs.append(sim_cppdefs[variant[0]])
        talias += [algo_name + "_" + scons_target_name + "_" + variant[0]]

    tsrcs = unique(map(lambda x: "" + x, tsrcs))

    if not use_shared_sconscript:
        # in the non-generic version of xxx_sim/SConcript.py a vs solution
        # consisting of one project per simulation component is set up, which is defined here:
            # scons command for visual studio
        ide_scons_cmd = (r"cd $SCONS_DIR && scons.bat -Q -j " + str(thread_number) + r" $SCONS_ARGUMENTS")
        variant_names = [variant[0] for variant in variant_list]

        tincs = find_all_incs(env, tbld)
        tincs = unique(tincs)

        project_name = (build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" +
              build_folder_name + "/" + vc_project_name + env.subst("$MSVSPROJECTSUFFIX"))

        sim_ide = env.MSVSProject(
                            # specify project name
                            target = project_name,
                            # add source files
                            srcs = tsrcs,
                            # add include paths
                            incs = tincs,
                            # add build targets
                            buildtarget = [algo_name + "_" + scons_target_name + "_" + variant[0] for variant in variant_list],
                            # add target variant
                            variant = variant_names,
                            # don't generate .sln
                            auto_build_solution = 0,
                            # scons build command
                            MSVSSCONS = ide_scons_cmd,
                            # folder containing SConstruct
                            SCONS_DIR = Dir("#").abspath,
                            # scons command argument
                            SCONS_ARGUMENTS = "skip_ide_generation=1" + " " + "build_from_ide=1" + " " + scons_arguments,
                            # add CPPPATH
                            CPPPATH = unique(tcpppath))
        if algo_name != component_name:
            generate_alias(algo_name + "_ide_msvc_" + scons_target_name, sim_ide, component_name + ':' + algo_name + '_ide:msvc:' + scons_target_name, ['MSVC: ' + scons_target_name])
            generate_alias(algo_name + "_ide_msvc", sim_ide, component_name + ':' + algo_name + '_ide:msvc')
            generate_alias(algo_name + "_ide", sim_ide, component_name + ':' + algo_name + '_ide')

        generate_alias(component_name + "_ide_msvc_" + scons_target_name, sim_ide, component_name + ':ide:msvc:' + scons_target_name, ['MSVC: ' + scons_target_name])
        generate_alias(component_name + "_ide_msvc", sim_ide, component_name + ':ide:msvc')
        generate_alias(component_name + "_ide", sim_ide, component_name + ':ide')
        generate_alias("all", sim_ide, component_name)
        if profile:
            FinishSconscriptEntry()
        Return(["sim_ide", "variant_names"])
    else:
        if profile:
            FinishSconscriptEntry()
        # In the generic version of xxx_sim/SConscript.py, all sources, includes,... from all simulation components
        # are gathered up and put together in the generic version of that script.
        Return(["tbld", "tsrcs", "tcpppath", "talias", "tcppdefs"])

if profile:
    FinishSconscriptEntry()