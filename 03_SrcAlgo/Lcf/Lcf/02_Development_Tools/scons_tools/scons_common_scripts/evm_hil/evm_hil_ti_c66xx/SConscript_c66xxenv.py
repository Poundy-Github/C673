"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_ti_c66xx\SConscript_c66xxenv.py
Description               : SConscript to create build environment for C66xx out file.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_ti_arp32\SConscript_c66xxenv.py
#
# DESCRIPTION: SConscript to create build environment for C66xx out file.
#
# INITIAL AUTHOR: Stark-EXT, Roland (uidw1169)
#
# CREATION DATE: 2014/03/19
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:23CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_c66xxenv.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:23CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_ti_c66xx/project.pj
# CHANGES:                   Revision 1.27 2017/05/30 13:37:36CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.26 2017/04/27 16:21:54CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.25 2016/07/12 06:15:03CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons
# CHANGES:                   Revision 1.24 2016/07/01 05:55:02CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.23 2016/05/31 06:38:07CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for  VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.22 2016/05/30 14:51:17CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.21 2016/05/12 14:08:28CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Introduced alias for VME and VH28 libsize calculation
# CHANGES:                   Revision 1.20 2015/09/23 16:19:26CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between ccs project and relevant ti-tools
# CHANGES:                   --- Added comments ---  uidg5297 [Sep 23, 2015 4:19:27 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.19 2015/07/22 10:57:12CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   replace resolve_contradicting_ccflags by resolve_incompatible_ccflags due to renaming function
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 22, 2015 10:57:12 AM CEST]
# CHANGES:                   Change Package : 359738:1 http://mks-psad:7002/im/viewissue?selection=359738
# CHANGES:                   Revision 1.18 2015/07/13 15:30:34CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add lcf-files to ccs-projects
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 13, 2015 3:30:34 PM CEST]
# CHANGES:                   Change Package : 356572:1 http://mks-psad:7002/im/viewissue?selection=356572
# CHANGES:                   Revision 1.17 2015/07/06 10:03:22CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   update handling of optimization flags
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 6, 2015 10:03:22 AM CEST]
# CHANGES:                   Change Package : 353994:1 http://mks-psad:7002/im/viewissue?selection=353994
# CHANGES:                   Revision 1.16 2015/06/26 11:11:16CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 11:11:16 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "exception_handler_file_list","exception_handler", "scons_arguments", "component_name", "eve_used", "thread_number", "define_list", "algo_name", "verbose", "help_dict", "profile", "SconscriptTimesTable")
import os, re

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

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

# read gscons_exception_handler 
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)	

# get relative path of a file
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+"\hil_env_config.scfg"

# ========================
# DSP out file
# ========================
dsp_env = Environment(# list of scons extensions used
                      tools = ["tms320dm6000", "eclipse_cdt_ccs5", "msvc-addon"], 
                      # path to scons extensions
                      toolpath = [scons_adas_extensions_path],
                      # path to C6000 compiler
                      C6000_CODE_GEN_TOOL_PATH = c6000_code_gen_tool_dir, 
                      # path to BIOS
                      DSP_BIOS_PATH = ti_bios_dir, 
                      # path to XDCTOOLS
                      DSP_XDCTOOLS_PATH = ti_xdctools_dir, 
                      # specify DSP CPU version
                      DSP_CPU_VERSION = "6600", 
                      # path to XDC packages
                      XDC_PACKAGE_PATH = (Dir(ti_bios_package_dir).abspath + ";" + 
                                          Dir("#../" + component_name + "_sim/" + component_name +
                                          "_evm_hil/vh28/platform/").abspath + ";" + 
                                          Dir(edma3_drv_dir + "packages/").abspath + ";"), 
                      # XDC target name
                      XDC_TARGET = "ti.targets.elf.C66", 
                      # XDC target platform
                      XDC_PLATFORM = "vh28_evm_hil_c66xx")
                      
if not verbose:
    dsp_env['CCCOMSTR'] = "\nCompiling hil vh28 c66xx $variant\n[$SOURCE]"
    dsp_env['CXXCOMSTR'] = "\nCompiling hil vh28 c66xx $variant\n[$SOURCE]"
    dsp_env['LINKCOMSTR'] = "\nLinking hil vh28 c66xx $variant\n[$TARGET]"                         

#-------------------------
# setup environment
#-------------------------
# create env for all variants
c66xx_env_list = []
for variant in variant_list:
    new_variant = dsp_env.Clone(variant=variant[0])
    new_variant.Append(CCFLAGS = Split(variant[1]))
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
    new_variant.Append(LINKFLAGS = Split(variant[3]))
    new_variant.Append(LIBPATH = map(lambda x: Dir(x).abspath, Split(variant[4])))
    new_variant.Append(LIBS = Split(variant[5]))
    new_variant.Append(DSP_LCF_FILE = map(lambda x: File(x).abspath, Split(variant[6])))
    # choose possibly contradicting ccflags, see common_config.scfg
    new_variant['CCFLAGS'] = resolve_incompatible_ccflags(new_variant['CCFLAGS'], c66xx_common_ccflags_to_check, variant[1])
    # add to environment lists
    c66xx_env_list.append(new_variant)
    
#-------------------------
# build out files
#-------------------------
try:
    outfile_name
except NameError,e:
    exception_error(e,"in "+sconscript_dir+"\hil_env_config.scfg")

c66xx_outfile = outfile_name
c66xx_list = []

for e in c66xx_env_list:
    env = e.Clone()
    
    # setup output folder
    c66xx_sim_build_dir = (build_dir + "/algo/" + algo_name + "_sim/ti_c66xx/" + env["variant"] + "/")
                           
    # src_dir (2nd parameter of VariantDir) is the location of the source dir 
    # relative to the location of this SConscript.py
    env.VariantDir(c66xx_sim_build_dir, "../../../../../../../", duplicate = 0)            
    result = SConscript((o + "/03_Workspace/algo/" + component_name + 
                        "_sim/" + component_name + "_evm_hil/vh28/evm_hil_projects/C66xx/SConscript.py"), 
                        exports = {
                            "env" : env, 
                            "target" : c66xx_outfile, 
                            "component_name" : component_name,
                            "algo_name" : algo_name
                        })
                        
    # result[0] contains lib, result[1] contains src, result[2] contains include path
    ti_c66xx_sim_out = env.Install(c66xx_sim_build_dir, result[0])
    
    # generate aliases containing the variant's name    
    generate_alias(component_name + "_sim_hil_out_ti_c66xx_" + env["variant"], ti_c66xx_sim_out)
    generate_alias(component_name + "_sim_hil_ecu_out_" + env["variant"], ti_c66xx_sim_out)
    generate_alias(component_name + "_sim_" + env["variant"], ti_c66xx_sim_out)
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_hil_out_ti_c66xx_" + env["variant"], ti_c66xx_sim_out)
        generate_alias(algo_name + "_sim_hil_ecu_out_" + env["variant"], ti_c66xx_sim_out)
        generate_alias(algo_name + "_sim_" + env["variant"], ti_c66xx_sim_out)
    generate_alias(env["variant"], ti_c66xx_sim_out)
    generate_alias("all_" + env["variant"], ti_c66xx_sim_out)
    # generate aliases NOT containing the variant's name    
    generate_alias(component_name + "_sim_hil_out_ti_c66xx", ti_c66xx_sim_out, component_name + ':sim:hil:ti_c66xx', ['VH28-HIL: C66xx'])
    generate_alias(component_name + "_sim_hil_ecu_out", ti_c66xx_sim_out, component_name + ':sim:hil')
    generate_alias(component_name + "_sim", ti_c66xx_sim_out, component_name + ':sim')
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_hil_out_ti_c66xx", ti_c66xx_sim_out, component_name + ':' + algo_name + '_sim:hil:ti_c66xx', ['VH28-HIL: C66xx'])
        generate_alias(algo_name + "_sim_hil_ecu_out", ti_c66xx_sim_out, component_name + ':' + algo_name + '_sim:hil')
        generate_alias(algo_name + "_sim", ti_c66xx_sim_out, component_name + ':' + algo_name + '_sim')
    generate_alias("all", ti_c66xx_sim_out, component_name)
    # Prepare cleaning of build directories
    dirsToClean = map(lambda x : c66xx_sim_build_dir + x, src_dirs)
    Clean(ti_c66xx_sim_out, dirsToClean)

    #-------------------------
    # library ram/rom usage
    #-------------------------
    if env["variant"] == "release":
      execfile(File(source_code_path_from_sconstruct + component_name + "/algo_config.scfg").abspath)
      execfile(File("ti_c66xx_sim_hil_config.scfg").abspath)

      Wrapper = True
      try:
        wrapper_src
      except NameError,e:
        exception_warning(e,exception_handler,msg)
        Wrapper = False
	
      # involved files
      mapfile = File(c66xx_sim_build_dir + "03_Workspace/algo/" + component_name + "_sim/" + component_name + "_evm_hil/vh28/evm_hil_projects/C66xx/" + (c66xx_outfile.replace(".out", ".map")))
      outfile = File(c66xx_sim_build_dir + component_name + "_c66xx_libsize.txt")
      libfile = File(release_libpaths[0] + "/" + env["LIBS"][0])

      # create the libsize builder
      execfile(File(scons_adas_extensions_path + "ram_rom_algo_libsize.py").abspath)	  
      c66xx_libsize_out = []	  
	
      wrappers_in_ram_rom = False
      wrappers_in_lib = False	  
      if Wrapper == True:	
        for c674x_lib_src_file in c674x_src:	
            for wrapper_src_file in wrapper_src:
                if wrapper_src_file in c674x_lib_src_file:			
                    wrappers_in_lib = True
                    break
            if wrappers_in_lib == True:
                break
        if wrappers_in_lib == False:
            for ti_c66xx_hil_src_file in ti_c66xx_hil_src:		
                for wrapper_src_file in wrapper_src:
                    if wrapper_src_file in ti_c66xx_hil_src_file:				
                        wrappers_in_ram_rom = True
                        break
                if wrappers_in_ram_rom == True:
                    break
        if wrappers_in_ram_rom == True:
            for wrapper_src_file in wrapper_src:
                for folderName, subfolders, filenames in os.walk(Dir(source_code_path_from_sconstruct).abspath):
                    if wrapper_src_file.replace('/','\\').replace('..','') in folderName+'\\'+File(wrapper_src_file).name:
                        outfile_files = File(c66xx_sim_build_dir + os.path.splitext(File(wrapper_src_file).name)[0]+'.txt')
                        head, sep, tail = folderName.partition('\\04_Engineering\\')
                        objfile_files = File(release_libpaths[0] + "/" + tail +"/"+ os.path.splitext(File(wrapper_src_file).name)[0]+'.obj')
                        c66xx_libsize_out+= generateLibSize(env, objfile_files, mapfile, outfile_files)
                        SideEffect(File(objfile_files).abspath, ti_c66xx_sim_out)	  
	  
      user_file_list = True		
      try:		  
          Obj_Size_c66xx	  
      except NameError,e:
          exception_warning(e,exception_handler,msg)
          user_file_list = False		  
      if user_file_list == True:	  
          for Obj in Obj_Size_c66xx:		  
              outfile_files = File(c66xx_sim_build_dir + os.path.splitext(File(Obj).name)[0]+'.txt')	  
              objfile_files = File(release_libpaths[0] + "/" + Obj)			  
              c66xx_libsize_out+= generateLibSize(env, objfile_files, mapfile, outfile_files)
              SideEffect(File(objfile_files).abspath, ti_c66xx_sim_out)
          c66xx_libsize_out+= generateLibSize(env, libfile, mapfile, outfile)
      else:	  
          c66xx_libsize_out+= generateLibSize(env, libfile, mapfile, outfile)


      i = 0  
      for c66xx_libsize_out_depend in c66xx_libsize_out:
        i = i + 1
        if len(c66xx_libsize_out) > i:
            Depends(c66xx_libsize_out_depend, c66xx_libsize_out[i:])	  
	  
      c66xx_list+= c66xx_libsize_out	  	  

      generate_alias(component_name + "_sim_ramrom_vh28", c66xx_libsize_out)
      generate_alias(component_name + "_sim_ramrom", c66xx_libsize_out)  
      generate_alias(component_name + "_sim_" + env["variant"], c66xx_libsize_out)

      if algo_name != component_name:
          generate_alias(algo_name + "_sim_ramrom_vh28", c66xx_libsize_out)
          generate_alias(algo_name + "_sim_ramrom", c66xx_libsize_out)		  
          generate_alias(algo_name + "_sim_" + env["variant"], c66xx_libsize_out)
      generate_alias(env["variant"], c66xx_libsize_out)
      generate_alias("all_" + env["variant"], c66xx_libsize_out)
      generate_alias(component_name + "_sim_ramrom_vh28_ti_c66xx", c66xx_libsize_out, component_name + ':sim:ramrom:vh28:ti_c66xx', ['VH28-HIL: ram/rom usage for C66xx'])
      generate_alias(component_name + "_sim_ramrom_vh28", c66xx_libsize_out, component_name + ':sim:ramrom:vh28')
      generate_alias(component_name + "_sim_ramrom", c66xx_libsize_out, component_name + ':sim:ramrom')	  
      generate_alias(component_name + "_sim", c66xx_libsize_out, component_name + ':sim')
      if algo_name != component_name:
          generate_alias(algo_name + "_sim_ramrom_vh28_ti_c66xx", c66xx_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vh28:ti_c66xx', ['VH28-HIL: ram/rom usage for C66xx'])
          generate_alias(algo_name + "_sim_ramrom_vh28", c66xx_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vh28')
          generate_alias(algo_name + "_sim_ramrom", c66xx_libsize_out, component_name + ':' + algo_name + '_sim:ramrom')		  
          generate_alias(algo_name + "_sim", c66xx_libsize_out, component_name + ':' + algo_name + '_sim')
      generate_alias("all", c66xx_libsize_out, component_name) 	  
      
      # this ensures that outfile is generated and map file is available
      SideEffect(File(mapfile).abspath, ti_c66xx_sim_out)
      Depends(c66xx_libsize_out, ti_c66xx_sim_out)
    
#-------------------------
# build ccs 5.3 project
#-------------------------

try:
    ccs_project_name
except NameError,e:
    exception_error(e,"in "+sconscript_dir+"\hil_env_config.scfg")

c66xx_sim_project = ccs_project_name

# recover and define variants for ccs projects
variant_names = [variant[0] for variant in variant_list]
# recover and define lcf-files to be added to linked resources in ccs project
lcf_files     = map(lambda x: File(x).abspath, Split(variant_list[0][6]))
    
if not skip_ide_generation:
    # add include paths
    dsp_env.Append(CPPPATH = result[2])
    ide_ccs_ti_c66xx = dsp_env.EclipseProject(
                       # specify project name
                       target_name = c66xx_sim_project, 
                       # specify folder for storing the project
                       target_dir = (build_dir + "/algo/" + algo_name + "_sim/ti_c66xx/"), 
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
                       scons_target = [algo_name + "_sim_hil_out_ti_c66xx_" + variant[0] for variant in variant_list], 
                       # specify additional argument when running scons
                       scons_argument = "-j" + str(thread_number) + " " + "skip_ide_generation=1" + " " + "build_from_ccs=1" + " " + scons_arguments, 
                       # add build target node (for recovering headers included)
                       Build_target = result[0],
                       # add files to be displayed in ccs project (result[1]=source files, lcf_files=linker scripts)
                       linked_resources = result[1] + lcf_files, 
                       use_rtsc = True,
                       additional_natures = "")

    # Make sure that compilers are extracted before generation of CCS project
    Requires(ide_ccs_ti_c66xx, Dir(c6000_code_gen_tool_dir).abspath)
        
    generate_alias(component_name + "_ide_ccs_hil_ti_c66xx", ide_ccs_ti_c66xx, component_name + ':ide:ccs:hil_ti_c66xx', ['CCS 5: C66xx VH28-HIL wrapper'])
    generate_alias(component_name + "_ide_ccs", ide_ccs_ti_c66xx, component_name + ':ide:ccs')
    generate_alias(component_name + "_ide", ide_ccs_ti_c66xx, component_name + ':ide')
    if algo_name != component_name:
        generate_alias(algo_name + "_ide_ccs_hil_ti_c66xx", ide_ccs_ti_c66xx, component_name + ':' + algo_name + '_ide:ccs:hil_ti_c66xx', ['CCS 5: C66xx VH28-HIL wrapper'])
        generate_alias(algo_name + "_ide_ccs", ide_ccs_ti_c66xx, component_name + ':' + algo_name + '_ide:ccs')
        generate_alias(algo_name + "_ide", ide_ccs_ti_c66xx, component_name + ':' + algo_name + '_ide')
    generate_alias("all", ide_ccs_ti_c66xx, component_name)
 
if profile:
    FinishSconscriptEntry()
        
if not skip_ide_generation:
    Return(["c66xx_outfile", "ide_ccs_ti_c66xx", "c66xx_list"])
else:
    Return(["c66xx_outfile", "c66xx_list"])
