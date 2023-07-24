# SConscript to create build env for simulation target

#-------------------------
# import
#-------------------------
import os
Import("skip_ide_generation", "scons_arguments", "component_name", "build_from_ide", "env", "thread_number", "define_list", "algo_name", "verbose", "use_shared_sconscript", "help_dict", "profile", "SconscriptTimesTable","install_to_deliverables_dir")

if profile:
    execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('2')

#-------------------------
# read configuration
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/common_config.scfg").abspath)
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/help_menu.py").abspath)
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/simenv_config.scfg")

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
except NameError:
    target_ext = ".dll"

try:
    target_name
except NameError:
    target_name = target_dll_name

try:
    special_copy_operation
except NameError:
    special_copy_operation = False

try:
    special_copy_dict
except NameError:
    special_copy_dict = []
#-------------------------
# read helper
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

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
        pc_algo_deliverables_dir = (deliverables_dir + "/lib/pc/algo/" + algo_name + "/")
        env["CCPDBFLAGS"] = "/Zi /Fd${TARGET}.pdb"

        # src_dir (2nd parameter of VariantDir) is the location of the source dir
        # relative to the location of this SConscript.py
        # case switch necessary because of different folder levels for utilities and non-utilities in sr and tsa
        if not build_utils:
            env.VariantDir(pc_algo_build_dir, "../../../", duplicate = 0)
        else:
            env.VariantDir(pc_algo_build_dir, "../../", duplicate = 0)
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
