#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_ti_c674x\SConscript_c674xenv.py
#
# DESCRIPTION: SConscript to create build environment for c674x out file.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/08/01
#
# LAST CHANGE:      $Date: 2021/12/14 03:42:45CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_c674xenv.py  $
# CHANGES:                   Revision 1.1 2021/12/14 03:42:45CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/03_Workspace/Component_Workspace/LCF_sim/lcf_evm_hil/vme/evm_hil_projects/C674x/project.pj
# CHANGES:                   Revision 1.2 2017/06/27 14:01:30CEST Asong, Wedndah Asaha (uidj2187) 
# CHANGES:                   Modified scons config scripts for Mainstream SIL-Build
# CHANGES:                   Revision 1.1 2017/06/13 16:06:23CEST Berendes, Ignacius (uid41806) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/03_Workspace/Component_Workspace/LCF_sim/lcf_evm_hil/vme/evm_hil_projects/C674x/project.pj
# CHANGES:                   Revision 1.0 2016/07/01 12:20:03CEST Prajescu, Claudia (uidl9533) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/03_Workspace/algo/lcf_sim/lcf_evm_hil/vme/evm_hil_projects/C674x/project.pj
# CHANGES:                   Revision 1.24 2015/09/23 16:19:02CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between ccs project and relevant ti-tools
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:19:03 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.23 2015/07/22 10:57:49CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   replace resolve_contradicting_ccflags by resolve_incompatible_ccflags due to renaming function
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 22, 2015 10:57:49 AM CEST]
# CHANGES:                   Change Package : 359738:1 http://mks-psad:7002/im/viewissue?selection=359738
# CHANGES:                   Revision 1.22 2015/07/13 15:30:59CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add lcf-files to ccs-projects
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 13, 2015 3:30:59 PM CEST]
# CHANGES:                   Change Package : 356572:1 http://mks-psad:7002/im/viewissue?selection=356572
# CHANGES:                   Revision 1.21 2015/07/06 10:04:32CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   update handling of optimization flags
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 6, 2015 10:04:32 AM CEST]
# CHANGES:                   Change Package : 353994:1 http://mks-psad:7002/im/viewissue?selection=353994
# CHANGES:                   Revision 1.20 2015/06/26 11:11:17CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 11:11:17 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "scons_arguments", "component_name", "eve_used", "thread_number", "define_list", "algo_name", "verbose", "help_dict", "profile", "SconscriptTimesTable")
import os, re

if profile:
    execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('2')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/hil_env_config.scfg")
# get common scons config containing tool paths
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/help_menu.py").abspath)

# ========================
# DSP out file
# ========================
dsp_env = Environment(# list of scons extensions used
                      tools = ["tms320dm6000", "eclipse_cdt_ccs5","msvc-addon"], 
                      # path to scons extensions
                      toolpath = [scons_adas_extensions_path],
                      # path to C6000 compiler
                      C6000_CODE_GEN_TOOL_PATH = c6000_code_gen_tool_dir, 
                      # path to BIOS
                      DSP_BIOS_PATH = ti_bios_dir, 
                      # path to XDCTOOLS
                      DSP_XDCTOOLS_PATH = ti_xdctools_dir, 
                      # specify DSP CPU version
                      DSP_CPU_VERSION = "6740", 
                      # path to XDC packages
                      XDC_PACKAGE_PATH = (Dir(ti_bios_package_dir).abspath + ";" + 
                                          Dir("#../" + component_name + "_sim/" + component_name +
                                          "_evm_hil/vme/generic/evm_sw/platform/").abspath + ";"+ 
                                          Dir("#../" + component_name + "_sim/" + component_name +
                                          "_evm_hil/vme/platform/").abspath + ";" + 
                                          Dir(edma3_drv_dir + "packages/").abspath + ";"), 
                      # XDC target name
                      XDC_TARGET = "ti.targets.elf.C674", 
                      # XDC target platform
                      XDC_PLATFORM = "vme_evm_hil_c674x")
                      
if not verbose:
    dsp_env['CCCOMSTR'] = "\nCompiling hil vme c674x $variant\n[$SOURCE]"
    dsp_env['CXXCOMSTR'] = "\nCompiling hil vme c674x $variant\n[$SOURCE]"
    dsp_env['LINKCOMSTR'] = "\nLinking hil vme c674x $variant\n[$TARGET]"                     

#-------------------------
# setup environment
#-------------------------
# create env for all variants
c674x_env_list = []
for variant in variant_list:
    new_variant = dsp_env.Clone(variant=variant[0])
    new_variant.Append(CCFLAGS = Split(variant[1]))
    if variant[0] == "release":
        for flag in c674x_rel_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    elif variant[0] == "debug":
        for flag in c674x_dbg_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)
    else:
        for flag in c674x_common_ccflags.split():
            new_variant.PrependUnique(CCFLAGS = flag)       
    new_variant.Append(CPPDEFINES = Split(variant[2]) + define_list)
    new_variant.Append(LINKFLAGS = Split(variant[3]))
    new_variant.Append(LIBPATH = map(lambda x: Dir(x).abspath, Split(variant[4])))
    new_variant.Append(LIBS = Split(variant[5]))
    new_variant.Append(DSP_LCF_FILE = map(lambda x: File(x).abspath, Split(variant[6])))
    # choose possibly contradicting ccflags, see common_config.scfg
    new_variant['CCFLAGS'] = resolve_incompatible_ccflags(new_variant['CCFLAGS'], c674x_common_ccflags_to_check, variant[1])
    # add to environment lists
    c674x_env_list.append(new_variant)
    
#-------------------------
# build out files
#-------------------------
c674x_outfile = outfile_name

for e in c674x_env_list:
    env = e.Clone()
    
    # setup output folder
    c674x_sim_build_dir = (build_dir + "/algo/" + algo_name + "_sim/ti_c674x/" + env["variant"] + "/")
                           
    # src_dir (2nd parameter of VariantDir) is the location of the source dir 
    # relative to the location of this SConscript.py
    env.VariantDir(c674x_sim_build_dir, "../../../../../../../", duplicate = 0)            
    result = SConscript((c674x_sim_build_dir + "/03_Workspace/algo/" + component_name + 
                        "_sim/" + component_name + "_evm_hil/vme/evm_hil_projects/C674x/SConscript.py"), 
                        exports = {
                            "env" : env, 
                            "target" : c674x_outfile, 
                            "component_name" : component_name,
                            "algo_name" : algo_name
                        })
                        
    # result[0] contains lib, result[1] contains src, result[2] contains include path
    ti_c674x_sim_out = env.Install(c674x_sim_build_dir, result[0])
    
    # generate aliases containing the variant's name    
    generate_alias(component_name + "_sim_hil_out_ti_c674x_" + env["variant"], ti_c674x_sim_out)
    generate_alias(component_name + "_sim_hil_ecu_out_" + env["variant"], ti_c674x_sim_out)
    generate_alias(component_name + "_sim_" + env["variant"], ti_c674x_sim_out)
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_hil_out_ti_c674x_" + env["variant"], ti_c674x_sim_out)
        generate_alias(algo_name + "_sim_hil_ecu_out_" + env["variant"], ti_c674x_sim_out)
        generate_alias(algo_name + "_sim_" + env["variant"], ti_c674x_sim_out)
    generate_alias(env["variant"], ti_c674x_sim_out)
    generate_alias("all_" + env["variant"], ti_c674x_sim_out)
    # generate aliases NOT containing the variant's name    
    generate_alias(component_name + "_sim_hil_out_ti_c674x", ti_c674x_sim_out, component_name + ':sim:hil:ti_c674x', ['VME-HIL: C674x'])
    generate_alias(component_name + "_sim_hil_ecu_out", ti_c674x_sim_out, component_name + ':sim:hil')
    generate_alias(component_name + "_sim", ti_c674x_sim_out, component_name + ':sim')
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_hil_out_ti_c674x", ti_c674x_sim_out, component_name + ':' + algo_name + '_sim:hil:ti_c674x', ['VME-HIL: C674x'])
        generate_alias(algo_name + "_sim_hil_ecu_out", ti_c674x_sim_out, component_name + ':' + algo_name + '_sim:hil')
        generate_alias(algo_name + "_sim", ti_c674x_sim_out, component_name + ':' + algo_name + '_sim')
    generate_alias("all", ti_c674x_sim_out, component_name)
    # Prepare cleaning of build directories
    dirsToClean = map(lambda x : c674x_sim_build_dir + x, src_dirs)
    Clean(ti_c674x_sim_out, dirsToClean)

    #-------------------------
    # library ram/rom usage
    #-------------------------
    if env["variant"] == "release":
      # involved files
      mapfile = File(c674x_sim_build_dir + "03_Workspace/algo/" + component_name + "_sim/" + component_name + "_evm_hil/vme/evm_hil_projects/C674x/" + (c674x_outfile.replace(".out", ".map")))
      outfile = File(c674x_sim_build_dir + component_name + "_c674x_libsize.txt")
      libfile = File(release_libpaths[0] + "/" + env["LIBS"][0])

      # create the libsize builder
      execfile(File(scons_adas_extensions_path + "ram_rom_algo_libsize.py").abspath)
      c674x_libsize_out = generateLibSize(env, libfile, mapfile, outfile)
      
      # generate aliases containing the variant's name
      generate_alias(component_name + "_sim_hil_out_ti_c674x_" + env["variant"], c674x_libsize_out)
      generate_alias(component_name + "_sim_hil_ecu_out_" + env["variant"], c674x_libsize_out)
      generate_alias(component_name + "_sim_" + env["variant"], c674x_libsize_out)
      if algo_name != component_name:
          generate_alias(algo_name + "_sim_hil_out_ti_c674x_" + env["variant"], c674x_libsize_out)
          generate_alias(algo_name + "_sim_hil_ecu_out_" + env["variant"], c674x_libsize_out)
          generate_alias(algo_name + "_sim_" + env["variant"], c674x_libsize_out)
      generate_alias(env["variant"], c674x_libsize_out)
      generate_alias("all_" + env["variant"], c674x_libsize_out)
      # generate aliases NOT containing the variant's name 
      generate_alias(component_name + "_sim_hil_out_ti_c674x_libsize", c674x_libsize_out, component_name + ':sim:hil:ti_c674x:libsize', ['VME-HIL: ram/rom for C674x'])
      generate_alias(component_name + "_sim_hil_out_ti_c674x", c674x_libsize_out, component_name + ':sim:hil:ti_c674x')
      generate_alias(component_name + "_sim_hil_ecu_out", c674x_libsize_out, component_name + ':sim:hil')
      generate_alias(component_name + "_sim", c674x_libsize_out, component_name + ':sim')
      if algo_name != component_name:
          generate_alias(algo_name + "_sim_hil_out_ti_c674x_libsize", c674x_libsize_out, component_name + ':' + algo_name + '_sim:hil:ti_c674x:libsize', ['VME-HIL: ram/rom for C674x'])
          generate_alias(algo_name + "_sim_hil_out_ti_c674x", c674x_libsize_out, component_name + ':' + algo_name + '_sim:hil:ti_c674x')
          generate_alias(algo_name + "_sim_hil_ecu_out", c674x_libsize_out, component_name + ':' + algo_name + '_sim:hil')
          generate_alias(algo_name + "_sim", c674x_libsize_out, component_name + ':' + algo_name + '_sim')
      generate_alias("all", c674x_libsize_out, component_name)
      
      # this ensures that outfile is generated and map file is available
      SideEffect(File(mapfile).abspath, ti_c674x_sim_out)
      Depends(c674x_libsize_out, ti_c674x_sim_out)
    
#-------------------------
# build ccs 5.3 project
#-------------------------
c674x_sim_project = ccs_project_name

# recover and define variants for ccs projects
variant_names = [variant[0] for variant in variant_list]
# recover and define lcf-files to be added to linked resources in ccs project
lcf_files     = map(lambda x: File(x).abspath, Split(variant_list[0][6]))

if not skip_ide_generation:
    # add include paths
    dsp_env.Append(CPPPATH = result[2])
    ide_ccs_ti_c674x = dsp_env.EclipseProject(
                       # specify project name
                       target_name = c674x_sim_project, 
                       # specify folder for storing the project
                       target_dir = (build_dir + "/algo/" + algo_name + "_sim/ti_c674x/"), 
                       # specify build variants
                       variants = variant_names, 
                       # specify preprocessor defines
                       defines = [define_list + variant[2] for variant in variant_list], 
                       # target_type : "lib" or "out"
                       target_type = "out", 
                       # core : "C6000" or "TMS470"
                       core = "C6000", 
                       # specify compiler directory
                       code_gen_dir = c6000_code_gen_tool_dir,
                       # list of target variants (use the same order as in variants)
                       scons_target = [algo_name + "_sim_hil_out_ti_c674x_" + variant[0] for variant in variant_list], 
                       # specify additional argument when running scons
                       scons_argument = "-j" + str(thread_number) + " " + "skip_ide_generation=1" + " " + "build_from_ccs=1" + " " + scons_arguments, 
                       # add build target node (for recovering headers included)
                       Build_target = result[0],
                       # add files to be displayed in ccs project (result[1]=source files, lcf_files=linker scripts)
                       linked_resources = result[1] + lcf_files, 
                       use_rtsc = True,
                       additional_natures = "")

    # Make sure that compilers are extracted before generation of CCS project
    Requires(ide_ccs_ti_c674x, Dir(c6000_code_gen_tool_dir).abspath)

    generate_alias(component_name + "_ide_ccs_hil_ti_c674x", ide_ccs_ti_c674x, component_name + ':ide:ccs:hil_ti_c674x', ['CCS 5: C674x VME-HIL wrapper'])
    generate_alias(component_name + "_ide_ccs", ide_ccs_ti_c674x, component_name + ':ide:ccs')
    generate_alias(component_name + "_ide", ide_ccs_ti_c674x, component_name + ':ide')
    if algo_name != component_name:
        generate_alias(algo_name + "_ide_ccs_hil_ti_c674x", ide_ccs_ti_c674x, component_name + ':' + algo_name + '_ide:ccs:hil_ti_c674x', ['CCS 5: C674x VME-HIL wrapper'])
        generate_alias(algo_name + "_ide_ccs", ide_ccs_ti_c674x, component_name + ':' + algo_name + '_ide:ccs')
        generate_alias(algo_name + "_ide", ide_ccs_ti_c674x, component_name + ':' + algo_name + '_ide')
    generate_alias("all", ide_ccs_ti_c674x, component_name)
    
if profile:
    FinishSconscriptEntry()
    
if not skip_ide_generation:
    Return(["c674x_outfile", "ide_ccs_ti_c674x"])
else:
    Return(["c674x_outfile"])
