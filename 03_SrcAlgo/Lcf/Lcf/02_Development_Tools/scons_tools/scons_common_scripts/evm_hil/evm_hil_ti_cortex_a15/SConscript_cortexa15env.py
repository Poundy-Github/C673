"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_ti_cortex_a15\SConscript_cortexa15env.py
Description               : SConscript to create build environment for ARM CortexA15 out file.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_ti_cortex_a15\SConscript_cortexa15env.py
#
# DESCRIPTION: SConscript to create build environment for ARM CortexA15 out file.
#
# INITIAL AUTHOR: Stark-EXT, Roland (uidw1169)
#
# CREATION DATE: 2014/05/07
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:37CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_cortexa15env.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:37CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_ti_cortex_a15/project.pj
# CHANGES:                   Revision 1.24 2017/05/30 13:42:29CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.23 2017/04/27 16:17:50CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.22 2016/07/12 06:19:44CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons
# CHANGES:                   Revision 1.21 2016/07/01 06:00:50CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.20 2016/05/30 14:52:00CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.19 2016/05/12 14:09:54CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Introduced alias for VME and VH28 libsize calculation
# CHANGES:                   Revision 1.18 2016/02/02 14:41:03CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Missing dependencies in ECU-lib generation
# CHANGES:                   Revision 1.17 2015/09/23 16:18:41CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between ccs project and relevant ti-tools
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:18:42 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.16 2015/07/13 15:30:03CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add lcf-files to ccs-projects
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 13, 2015 3:30:03 PM CEST]
# CHANGES:                   Change Package : 356572:1 http://mks-psad:7002/im/viewissue?selection=356572
# CHANGES:                   Revision 1.15 2015/06/26 11:11:12CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 11:11:12 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


#-------------------------
# import
#-------------------------
Import("skip_ide_generation","exception_handler_file_list", "exception_handler", "scons_arguments", "component_name", "eve_used", "thread_number", "define_list", "algo_name", "help_dict", "profile", "SconscriptTimesTable")
import os

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('2')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/hil_env_config.scfg")
# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

# read gscons_exception_handler
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)

# get relative path of a file	
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+"\hil_env_config.scfg"

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

# ========================
# Cortex A15 out file
# ========================
arm_env = Environment(# list of scons extensions used
                      tools = ["arm_gcc", "eclipse_cdt_ccs5", "msvc-addon"], 
                      # path to scons extensions
                      toolpath = [scons_adas_extensions_path],
                      # path to ARM compiler
                      # ARM_GCC_CODE_GEN_VERSION = get_arm_gcc_codegen_version(Dir(arm_gcc_code_gen_tool_dir).abspath),
                      ARM_GCC_CODE_GEN_TOOL_PATH = arm_gcc_code_gen_tool_dir,
                      ARM_FASTRTS_PATH = arm_fastrts_dir,
                      # specify ARM CPU version
                      ARM_CPU_VERSION = "7A15", 
                      # path to BIOS
                      DSP_BIOS_PATH = ti_bios_dir, 
                      # path to XDCTOOLS
                      DSP_XDCTOOLS_PATH = ti_xdctools_dir, 
                      # path to XDC packages
                      XDC_PACKAGE_PATH = (Dir(ti_bios_package_dir).abspath + ";" + 
                                          Dir(ti_xdctools_package_dir).abspath + ";" + 
                                          Dir("#../" + component_name + "_sim/" + component_name +
                                          "_evm_hil/vh28/platform/").abspath + ";"), 
                      # XDC target name
                      XDC_TARGET = "gnu.targets.arm.A15F", 
                      # XDC target platform
                      XDC_PLATFORM = "vh28_evm_hil_ca15") 

#-------------------------
# setup environment
#-------------------------
# create env for all variants
ca15x_env_list = []
for variant in variant_list:
    new_variant = arm_env.Clone(variant=variant[0])
    new_variant.Append(CCFLAGS = Split(variant[1]))
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
    new_variant.Append(LINKFLAGS = Split(variant[3]))
    new_variant.Append(LIBPATH = map(lambda x: Dir(x).abspath, Split(variant[4])))
    new_variant.Append(LIBS = Split(variant[5]))
    new_variant.Append(ARM_LCF_FILE = map(lambda x: File(x).abspath, Split(variant[6])))
    ca15x_env_list.append(new_variant)

#-------------------------
# build out files
#-------------------------
try:
    outfile_name
except NameError,e:
    exception_error(e,"in "+sconscript_dir+"\hil_env_config.scfg")
cortexA15_outfile = outfile_name
cortexA15_list = []
for e in ca15x_env_list:
    env = e.Clone()
	
    # setup output folder
    cortexA15_sim_build_dir = (build_dir + "/algo/" + algo_name + "_sim/ti_cortex_a15/" + env["variant"] + "/")
    
    # src_dir (2nd parameter of VariantDir) is the location of the source dir 
    # relative to the location of this SConscript.py
    env.VariantDir(cortexA15_sim_build_dir, "../../../../../../../", duplicate = 0)            
    result = SConscript((cortexA15_sim_build_dir + "/03_Workspace/algo/" + component_name + 
                        "_sim/" + component_name + "_evm_hil/vh28/evm_hil_projects/CortexA15/SConscript.py"), 
                        exports = {
                            "env" : env, 
                            "target" : cortexA15_outfile, 
                            "component_name" : component_name,
                            "algo_name" : algo_name
                        })
    
    # result[0] contains out file, result[1] contains src, result[2] contains include path
    ti_cortexA15_sim_out = env.Install(cortexA15_sim_build_dir, result[0]) 
    
    # Added dependency of ECU cortexA15 Lib
    Requires(ti_cortexA15_sim_out, File(env['LIBPATH'][0] + "/lib" + env['LIBS'][0] + ".a"))
    
    # generate aliases containing the variant's name    
    generate_alias(component_name + "_sim_hil_out_ti_cortex_a15_" + env["variant"], ti_cortexA15_sim_out)
    generate_alias(component_name + "_sim_hil_ecu_out_" + env["variant"], ti_cortexA15_sim_out)
    generate_alias(component_name + "_sim_" + env["variant"], ti_cortexA15_sim_out)
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_hil_out_ti_cortex_a15_" + env["variant"], ti_cortexA15_sim_out)
        generate_alias(algo_name + "_sim_hil_ecu_out_" + env["variant"], ti_cortexA15_sim_out)
        generate_alias(algo_name + "_sim_" + env["variant"], ti_cortexA15_sim_out)
    generate_alias(env["variant"], ti_cortexA15_sim_out)
    generate_alias("all_" + env["variant"], ti_cortexA15_sim_out)
    # generate aliases NOT containing the variant's name    
    generate_alias(component_name + "_sim_hil_out_ti_cortex_a15", ti_cortexA15_sim_out, component_name + ':sim:hil:ti_cortex_a15', ['VH28-HIL: Cortex A15'])
    generate_alias(component_name + "_sim_hil_ecu_out", ti_cortexA15_sim_out, component_name + ':sim:hil')
    generate_alias(component_name + "_sim", ti_cortexA15_sim_out, component_name + ':sim')
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_hil_out_ti_cortex_a15", ti_cortexA15_sim_out, component_name + ':' + algo_name + '_sim:hil:ti_cortex_a15', ['VH28-HIL: Cortex A15'])
        generate_alias(algo_name + "_sim_hil_ecu_out", ti_cortexA15_sim_out, component_name + ':' + algo_name + '_sim:hil')
        generate_alias(algo_name + "_sim", ti_cortexA15_sim_out, component_name + ':' + algo_name + '_sim')
    generate_alias("all", ti_cortexA15_sim_out, component_name)
    # Prepare cleaning of build directories
    dirsToClean = map(lambda x : cortexA15_sim_build_dir + x, src_dirs)
    Clean(ti_cortexA15_sim_out, dirsToClean)

    #-------------------------
    # library ram/rom usage
    #-------------------------
    if env["variant"] == "release":
      execfile(File(source_code_path_from_sconstruct + component_name + "/algo_config.scfg").abspath)
      execfile(File("ti_cortex_a15_sim_hil_config.scfg").abspath)

      Wrapper = True
      try:
          wrapper_src
      except NameError,e:
        exception_warning(e,exception_handler,msg)
        Wrapper = False
	
      # involved files
      mapfile = File(cortexA15_sim_build_dir + "03_Workspace/algo/" + component_name + "_sim/" + component_name + "_evm_hil/vh28/evm_hil_projects/CortexA15/" + (cortexA15_outfile.replace(".out", ".map")))
      outfile = File(cortexA15_sim_build_dir + component_name + "_ca15_libsize.txt")
      libfile = File(release_libpaths[0] + "/lib" + env["LIBS"][0] + ".a")

      # create the libsize builder
      execfile(File(scons_adas_extensions_path + "ram_rom_algo_libsize.py").abspath)	
      ca15_libsize_out = []	  
	  
      wrappers_in_ram_rom = False
      wrappers_in_lib = False	  
      if Wrapper == True:	
        for ca15_src_file in ca15_src:	
            for wrapper_src_file in wrapper_src:
                if wrapper_src_file in ca15_src_file:			
                    wrappers_in_lib = True
                    break
            if wrappers_in_lib == True:
                break
        if wrappers_in_lib == False:
            for ti_cortex_a15_hil_src_file in ti_cortex_a15_hil_src:		
                for wrapper_src_file in wrapper_src:
                    if wrapper_src_file in ti_cortex_a15_hil_src_file:				
                        wrappers_in_ram_rom = True
                        break
                if wrappers_in_ram_rom == True:
                    break
        if wrappers_in_ram_rom == True:
            for wrapper_src_file in wrapper_src:
                for folderName, subfolders, filenames in os.walk(Dir(source_code_path_from_sconstruct).abspath):
                    if wrapper_src_file.replace('/','\\').replace('..','') in folderName+'\\'+File(wrapper_src_file).name:
                        outfile_files = File(cortexA15_sim_build_dir + os.path.splitext(File(wrapper_src_file).name)[0]+'.txt')
                        head, sep, tail = folderName.partition('\\04_Engineering\\')
                        objfile_files = File(release_libpaths[0] + "/" + tail +"/"+ os.path.splitext(File(wrapper_src_file).name)[0]+'.obj')
                        ca15_libsize_out+= generateLibSize(env, objfile_files, mapfile, outfile_files)
                        SideEffect(File(objfile_files).abspath, ti_cortexA15_sim_out)	  
	  
      user_file_list = True
      try:
          Obj_Size_cortexA15
      except NameError,e:
          exception_warning(e,exception_handler,msg)
          user_file_list = False
      if user_file_list == True:	  
          for Obj in Obj_Size_cortexA15:		  
              outfile_files = File(cortexA15_sim_build_dir + os.path.splitext(File(Obj).name)[0]+'.txt')	  
              objfile_files = File(release_libpaths[0] + "/" + Obj)			  
              ca15_libsize_out+= generateLibSize(env, objfile_files, mapfile, outfile_files)
              SideEffect(File(objfile_files).abspath, ti_cortexA15_sim_out)
          ca15_libsize_out+= generateLibSize(env, libfile, mapfile, outfile)
      else:	  
          ca15_libsize_out+= generateLibSize(env, libfile, mapfile, outfile)
		  
      i = 0  
      for ca15_libsize_out_depend in ca15_libsize_out:
        i = i + 1
        if len(ca15_libsize_out) > i:
            Depends(ca15_libsize_out_depend, ca15_libsize_out[i:])			  		  

      cortexA15_list+=ca15_libsize_out	  

      generate_alias(component_name + "_sim_ramrom_vh28", ca15_libsize_out)
      generate_alias(component_name + "_sim_ramrom", ca15_libsize_out)	  
      generate_alias(component_name + "_sim_" + env["variant"], ca15_libsize_out)

      if algo_name != component_name:
          generate_alias(algo_name + "_sim_ramrom_vh28", ca15_libsize_out)
          generate_alias(algo_name + "_sim_ramrom", ca15_libsize_out)		  
          generate_alias(algo_name + "_sim_" + env["variant"], ca15_libsize_out)
      generate_alias(env["variant"], ca15_libsize_out)
      generate_alias("all_" + env["variant"], ca15_libsize_out)
      generate_alias(component_name + "_sim_ramrom_vh28_ti_cortex_a15", ca15_libsize_out, component_name + ':sim:ramrom:vh28:ti_cortex_a15', ['VH28-HIL: ram/rom usage for Cortex A15'])
      generate_alias(component_name + "_sim_ramrom_vh28", ca15_libsize_out, component_name + ':sim:ramrom:vh28')
      generate_alias(component_name + "_sim_ramrom", ca15_libsize_out, component_name + ':sim:ramrom')	  
      generate_alias(component_name + "_sim", ca15_libsize_out, component_name + ':sim')
      if algo_name != component_name:
          generate_alias(algo_name + "_sim_ramrom_vh28_ti_cortex_a15", ca15_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vh28:ti_cortex_a15', ['VH28-HIL: ram/rom usage for Cortex A15'])
          generate_alias(algo_name + "_sim_ramrom_vh28", ca15_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vh28')
          generate_alias(algo_name + "_sim_ramrom", ca15_libsize_out, component_name + ':' + algo_name + '_sim:ramrom')		  
          generate_alias(algo_name + "_sim", ca15_libsize_out, component_name + ':' + algo_name + '_sim')
      generate_alias("all", ca15_libsize_out, component_name)
	  
      # this ensures that outfile is generated and map file is available
      SideEffect(File(mapfile).abspath, ti_cortexA15_sim_out)
      Depends(ca15_libsize_out, ti_cortexA15_sim_out)
    
#-------------------------
# build ccs 5.3 project
#-------------------------
try:
    ccs_project_name
except NameError,e:
    exception_error(e,"in "+sconscript_dir+"\hil_env_config.scfg")
cortexA15_sim_project = ccs_project_name

# recover and define variants for ccs projects
variant_names = [variant[0] for variant in variant_list]
# recover and define lcf-files to be added to linked resources in ccs project
lcf_files     = map(lambda x: File(x).abspath, Split(variant_list[0][6]))

if not skip_ide_generation:
    # add include paths
    arm_env.Append(CPPPATH = result[2])
       
    ide_ccs_ti_cortex_a15 = arm_env.EclipseProject(
                       # specify project name
                       target_name = cortexA15_sim_project, 
                       # specify folder for storing the project
                       target_dir = (build_dir + "/algo/" + algo_name + "_sim/ti_cortex_a15/"), 
                       # specify build variants
                       variants = variant_names, 
                       # specify preprocessor defines
                       defines = [define_list + variant[2] for variant in variant_list], 
                       # target_type : "lib" or "out"
                       target_type = "out", 
                       # core : "C6000" or "TMS470" or "TMS470_GNU"
                       core = "TMS470_GNU", 
                       # specify compiler directory
                       code_gen_dir = arm_gcc_code_gen_tool_dir,
                       # list of target variants (use the same order as in variants)
                       scons_target = [algo_name + "_sim_hil_out_ti_cortex_a15_" + variant[0] for variant in variant_list], 
                       # specify additional argument when running scons
                       scons_argument = "-j" + str(thread_number) + " " + "skip_ide_generation=1" + " " + "build_from_ccs=1" + " " + scons_arguments, 
                       # add build target node (for recovering headers included)
                       Build_target = result[0],
                       # add files to be displayed in ccs project (result[1]=source files, lcf_files=linker scripts)
                       linked_resources = result[1] + lcf_files, 
                       use_rtsc = True,
                       additional_natures = "")

    # Make sure that compilers are extracted before generation of CCS project
    Requires(ide_ccs_ti_cortex_a15, Dir(arm_gcc_code_gen_tool_dir).abspath)
        
    generate_alias(component_name + "_ide_ccs_hil_ti_cortex_a15", ide_ccs_ti_cortex_a15, component_name + ':ide:ccs:hil_ti_cortex_a15', ['CCS 5: Cortex A15 VH28-HIL wrapper'])
    generate_alias(component_name + "_ide_ccs", ide_ccs_ti_cortex_a15, component_name + ':ide:ccs')
    generate_alias(component_name + "_ide", ide_ccs_ti_cortex_a15, component_name + ':ide')
    if algo_name != component_name:
        generate_alias(algo_name + "_ide_ccs_hil_ti_cortex_a15", ide_ccs_ti_cortex_a15, component_name + ':' + algo_name + '_ide:ccs:hil_ti_cortex_a15', ['CCS 5: Cortex A15 VH28-HIL wrapper'])
        generate_alias(algo_name + "_ide_ccs", ide_ccs_ti_cortex_a15, component_name + ':' + algo_name + '_ide:ccs')
        generate_alias(algo_name + "_ide", ide_ccs_ti_cortex_a15, component_name + ':' + algo_name + '_ide')
    generate_alias("all", ide_ccs_ti_cortex_a15, component_name)
    
if profile:
    FinishSconscriptEntry()

if not skip_ide_generation:
    Return(["cortexA15_outfile", "ide_ccs_ti_cortex_a15", "cortexA15_sim_project", "cortexA15_list"])
else:
    Return(["cortexA15_outfile", "cortexA15_list"])
