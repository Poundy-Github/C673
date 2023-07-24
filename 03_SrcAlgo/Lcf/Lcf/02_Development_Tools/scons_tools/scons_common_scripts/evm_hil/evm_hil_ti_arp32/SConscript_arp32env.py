"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_ti_arp32\SConscript_arp32env.py
Description               : SConscript to create build environment for ARP32 out file.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_ti_arp32\SConscript_arp32env.py
#
# DESCRIPTION: SConscript to create build environment for ARP32 out file.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/08/01
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:19CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_arp32env.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:19CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_ti_arp32/project.pj
# CHANGES:                   Revision 1.28 2017/05/30 12:30:01CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.27 2017/04/27 16:25:34CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.26 2016/07/12 06:09:06CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons
# CHANGES:                   Revision 1.25 2016/07/01 05:51:58CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.24 2016/05/31 06:38:48CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.23 2016/05/30 14:51:04CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.22 2016/05/12 14:07:50CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Introduced alias for VME and VH28 libsize calculation
# CHANGES:                   Revision 1.21 2015/11/04 11:27:34CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Build-target for pure ARM-simulation needed
# CHANGES:                   --- Added comments ---  uidr2134 [Nov 4, 2015 11:27:34 AM CET]
# CHANGES:                   Change Package : 392739:1 http://mks-psad:7002/im/viewissue?selection=392739
# CHANGES:                   Revision 1.20 2015/09/23 16:19:10CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between ccs project and relevant ti-tools
# CHANGES:                   --- Added comments ---  uidg5297 [Sep 23, 2015 4:19:11 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.19 2015/07/13 15:30:19CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add lcf-files to ccs-projects
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 13, 2015 3:30:19 PM CEST]
# CHANGES:                   Change Package : 356572:1 http://mks-psad:7002/im/viewissue?selection=356572
# CHANGES:                   Revision 1.18 2015/06/26 11:11:18CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 11:11:19 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "exception_handler_file_list", "exception_handler","scons_arguments", "component_name", "eve_used", "thread_number", "define_list", "algo_name", "verbose", "help_dict", "profile", "SconscriptTimesTable")
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

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

# read gscons_exception_handler.py
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)

# get relative path of a file
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+"\hil_env_config.scfg"

try:
    eve_hil_miniapp
except NameError,e:
    exception_warning(e,exception_handler,msg)
    eve_hil_miniapp = False

# ========================
# ARP32 platform check
# ========================
var_platform = "vme"
if eve_hil_miniapp:
    var_core     = "arp32_miniapp"
    var_instdir  = "ti_arp32_miniapp/"
    var_blddir = "arp32_miniapp/"
else:
    var_core     = "arp32"
    var_instdir  = "ti_arp32/"
    var_blddir = "arp32/"

# check if this script runs in vh28 context
if "vh28" in sconscript_dir.lower():
    var_platform = "vh28"
    if eve_hil_miniapp:
        var_core     = "arp32_vh28e1_miniapp"
        var_instdir  = "ti_arp32_vh28e1_miniapp/"
        var_blddir = "arp32_miniapp/"
    else:
        var_core     = "arp32_vh28e1"
        var_instdir  = "ti_arp32_vh28e1/"
        var_blddir = "arp32/"

# ========================
# ARP32 out file
# ========================
if eve_used:

    #-------------------------
    # setup environment
    #-------------------------
    arp32_env = Environment(# list of scons extensions used
                            tools = ["ti_eve_arp32", "eclipse_cdt_ccs5","msvc-addon"], 
                            # path to scons extensions
                            toolpath = [scons_adas_extensions_path],
                            # path to arp32 compiler
                            ARP32_CODE_GEN_TOOL_PATH = arp32_tool_base_dir, 
                            # path to EDMA include file
                            EVE_EDMA_CSL_PATH = eve_edma_csl_dir)
                            
    if not verbose:
        if eve_hil_miniapp:
            arp32_env['CCCOMSTR'] = "\nCompiling hil %s arp32 miniapp $variant\n[$SOURCE]" % var_platform
            arp32_env['CXXCOMSTR'] = "\nCompiling hil %s arp32 miniapp $variant\n[$SOURCE]" % var_platform
            arp32_env['LINKCOMSTR'] = "\nLinking hil %s arp32 miniapp $variant\n[$TARGET]" % var_platform
        else:
            arp32_env['CCCOMSTR'] = "\nCompiling hil %s arp32 $variant\n[$SOURCE]" % var_platform
            arp32_env['CXXCOMSTR'] = "\nCompiling hil %s arp32 $variant\n[$SOURCE]" % var_platform
            arp32_env['LINKCOMSTR'] = "\nLinking hil %s arp32 $variant\n[$TARGET]" % var_platform

    # create env for all variants
    arp32_env_list = []
    for variant in variant_list:
        new_variant = arp32_env.Clone(variant=variant[0])
        new_variant.Append(CCFLAGS = Split(variant[1]))
        new_variant.Append(CPPDEFINES = Split(variant[2]) + define_list)
        new_variant.Append(LINKFLAGS = Split(variant[3]))
        new_variant.Append(LIBPATH = map(lambda x: Dir(x).abspath, Split(variant[4])))
        new_variant.Append(LIBS = Split(variant[5]))
        new_variant.Append(ARP32_EVE_LCF_FILE = map(lambda x: File(x).abspath, Split(variant[6])))
        arp32_env_list.append(new_variant)

    #-------------------------
    # build out files
    #-------------------------

    try:
        outfile_name
    except NameError,e:
        exception_error(e,"in "+sconscript_dir+"\hil_env_config.scfg")

    arp32_outfile = outfile_name
    arp32_list = []	

    for e in arp32_env_list:
        env = e.Clone()
        # setup output folder
        arp32_sim_build_dir = (build_dir + "/algo/" + algo_name + "_sim/" + var_instdir + "/" + env["variant"] + "/")
        
        # src_dir (2nd parameter of VariantDir) is the location of the source dir 
        # relative to the location of this SConscript.py
        env.VariantDir(arp32_sim_build_dir, "../../../../../../../", duplicate = 0)            
        result = SConscript((arp32_sim_build_dir + "/03_Workspace/algo/" + component_name + 
                            "_sim/" + component_name + "_evm_hil/" + var_platform + "/evm_hil_projects/" + var_blddir + "SConscript.py"), 
                            exports = {
                                "env" : env, 
                                "target" : arp32_outfile, 
                                "component_name" : component_name,
                                "algo_name" : algo_name
                            })
        # result[0] contains lib, result[1] contains src, result[2] contains include path
        ti_arp32_sim_out = env.Install(arp32_sim_build_dir, result[0])
        
        # generate aliases containing the variant's name
        generate_alias(component_name + "_sim_hil_out_ti_" + var_core + "_" + env["variant"], ti_arp32_sim_out)
        generate_alias(component_name + "_sim_hil_ecu_out_" + env["variant"], ti_arp32_sim_out)
        generate_alias(component_name + "_sim_" + env["variant"], ti_arp32_sim_out)
        if algo_name != component_name:
            generate_alias(algo_name + "_sim_hil_out_ti_" + var_core + "_" + env["variant"], ti_arp32_sim_out)
            generate_alias(algo_name + "_sim_hil_ecu_out_" + env["variant"], ti_arp32_sim_out)
            generate_alias(algo_name + "_sim_" + env["variant"], ti_arp32_sim_out)
        generate_alias(env["variant"], ti_arp32_sim_out)
        generate_alias("all_" + env["variant"], ti_arp32_sim_out)
        # generate aliases NOT containing the variant's name    
        generate_alias(component_name + "_sim_hil_out_ti_" + var_core, ti_arp32_sim_out, component_name + ':sim:hil:' + var_core, [var_platform.upper() + '-HIL: ARP32'])
        generate_alias(component_name + "_sim_hil_ecu_out", ti_arp32_sim_out, component_name + ':sim:hil')
        generate_alias(component_name + "_sim", ti_arp32_sim_out, component_name + ':sim')
        if algo_name != component_name:
            generate_alias(algo_name + "_sim_hil_out_ti_" + var_core, ti_arp32_sim_out, component_name + ':' + algo_name + '_sim:hil:' + var_core, [var_platform.upper() + '-HIL: ARP32'])
            generate_alias(algo_name + "_sim_hil_ecu_out", ti_arp32_sim_out, component_name + ':' + algo_name + '_sim:hil:' + var_core)
            generate_alias(algo_name + "_sim", ti_arp32_sim_out, component_name + ':' + algo_name + '_sim:hil:' + var_core)
        generate_alias("all", ti_arp32_sim_out, component_name)
        # Prepare cleaning of build directories
        dirsToClean = map(lambda x : arp32_sim_build_dir + x, src_dirs)
        Clean(ti_arp32_sim_out, dirsToClean)        

        #-------------------------
        # library ram/rom usage. ARP32 miniapp dont require ram/rom usage
        #-------------------------
        if env["variant"] == "release" and not eve_hil_miniapp:		
          execfile(File(source_code_path_from_sconstruct + component_name + "/algo_config.scfg").abspath)
          execfile(File("ti_arp32_sim_hil_config.scfg").abspath)

          Wrapper = True
          try:
            wrapper_src
          except NameError,e:
            exception_warning(e,exception_handler,msg)
            Wrapper = False
			
          # involved files
          mapfile = File(arp32_sim_build_dir + "03_Workspace/algo/" + component_name + "_sim/" + component_name + "_evm_hil/" + var_platform + 
                         "/evm_hil_projects/arp32/" + (arp32_outfile.replace(".out", ".map")))
          outfile = File(arp32_sim_build_dir + component_name + "_arp32_libsize.txt")
          libfile = File(release_libpaths[0] + "/" + env["LIBS"][0])

          # create the libsize builder
          execfile(File(scons_adas_extensions_path + "ram_rom_algo_libsize.py").abspath)
          arp32_libsize_out = []		  
		  
          wrappers_in_ram_rom = False
          wrappers_in_lib = False	  
          if Wrapper == True:	
            for arp32_lib_src_file in arp32_src:	
                for wrapper_src_file in wrapper_src:
                    if wrapper_src_file in arp32_lib_src_file:			
                        wrappers_in_lib = True
                        break
                if wrappers_in_lib == True:
                    break
            if wrappers_in_lib == False:
                for ti_arp32_hil_src_file in ti_arp32_hil_src:		
                    for wrapper_src_file in wrapper_src:
                        if wrapper_src_file in ti_arp32_hil_src_file:				
                            wrappers_in_ram_rom = True
                            break
                    if wrappers_in_ram_rom == True:
                        break
            if wrappers_in_ram_rom == True:
                for wrapper_src_file in wrapper_src:
                    for folderName, subfolders, filenames in os.walk(Dir(source_code_path_from_sconstruct).abspath):
                        if wrapper_src_file.replace('/','\\').replace('..','') in folderName+'\\'+File(wrapper_src_file).name:
                            outfile_files = File(arp32_sim_build_dir + os.path.splitext(File(wrapper_src_file).name)[0]+'.txt')
                            head, sep, tail = folderName.partition('\\04_Engineering\\')
                            objfile_files = File(release_libpaths[0] + "/" + tail +"/"+ os.path.splitext(File(wrapper_src_file).name)[0]+'.obj')
                            arp32_libsize_out+= generateLibSize(env, objfile_files, mapfile, outfile_files)
                            SideEffect(File(objfile_files).abspath, ti_arp32_sim_out) 
		  
	  
          user_file_list = True		
          try:	  
              Obj_Size_arp32			  
          except NameError,e:
              exception_warning(e,exception_handler,msg)
              user_file_list = False
          if user_file_list == True:	  
              for obj in Obj_Size_arp32:	  
                  outfile_files = File(arp32_sim_build_dir + os.path.splitext(File(obj).name)[0]+'.txt')	  
                  objfile_files = File(release_libpaths[0] + "/" + obj)			  
                  arp32_libsize_out+= generateLibSize(env, objfile_files, mapfile, outfile_files)
                  SideEffect(File(objfile_files).abspath, ti_arp32_sim_out)
              arp32_libsize_out+= generateLibSize(env, libfile, mapfile, outfile)
          else:	  
              arp32_libsize_out+= generateLibSize(env, libfile, mapfile, outfile)
			  
          i = 0  
          for arp32_libsize_out_depend in arp32_libsize_out:
            i = i + 1		
            if len(arp32_libsize_out) > i:
                Depends(arp32_libsize_out_depend, arp32_libsize_out[i:])
			  
          arp32_list+= arp32_libsize_out			  
		  
          if var_platform == "vme":		  
              generate_alias(component_name + "_sim_ramrom_vme", arp32_libsize_out)
          else:
              generate_alias(component_name + "_sim_ramrom_vh28", arp32_libsize_out)
          generate_alias(component_name + "_sim_ramrom", arp32_libsize_out)			  
          generate_alias(component_name + "_sim_" + env["variant"], arp32_libsize_out)		  

          if algo_name != component_name:
              if var_platform == "vme":		  
                  generate_alias(algo_name + "_sim_ramrom_vme", arp32_libsize_out)
              else:
                  generate_alias(algo_name + "_sim_ramrom_vh28", arp32_libsize_out)
              generate_alias(algo_name + "_sim_ramrom", arp32_libsize_out)			  
              generate_alias(algo_name + "_sim_" + env["variant"], arp32_libsize_out)
			  
	  
          generate_alias(env["variant"], arp32_libsize_out)
          generate_alias("all_" + env["variant"], arp32_libsize_out)
          
          if var_platform == "vme":			  
              generate_alias(component_name + "_sim_ramrom_vme_ti_arp32", arp32_libsize_out, component_name + ':sim:ramrom:vme:ti_arp32', [var_platform.upper() + '-HIL: ram/rom usage for ARP32'])
              generate_alias(component_name + "_sim_ramrom_vme", arp32_libsize_out, component_name + ':sim:ramrom:vme')
              generate_alias(component_name + "_sim_ramrom", arp32_libsize_out, component_name + ':sim:ramrom')
          else:			  
              generate_alias(component_name + "_sim_ramrom_vh28_ti_arp32", arp32_libsize_out, component_name + ':sim:ramrom:vh28:ti_arp32', [var_platform.upper() + '-HIL: ram/rom usage for ARP32'])
              generate_alias(component_name + "_sim_ramrom_vh28", arp32_libsize_out, component_name + ':sim:ramrom:vh28')
              generate_alias(component_name + "_sim_ramrom", arp32_libsize_out, component_name + ':sim:ramrom')			  
          generate_alias(component_name + "_sim", arp32_libsize_out, component_name + ':sim')
          if algo_name != component_name:
              if var_platform == "vme":
                  generate_alias(algo_name + "_sim_ramrom_vme_ti_arp32", arp32_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vme:ti_arp32', [var_platform.upper() + '-HIL: ram/rom usage for ARP32'])
                  generate_alias(algo_name + "_sim_ramrom_vme", arp32_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vme')
                  generate_alias(algo_name + "_sim_ramrom", arp32_libsize_out, component_name + ':' + algo_name + '_sim:ramrom')
              else:
                  generate_alias(algo_name + "_sim_ramrom_vh28_ti_arp32", arp32_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vh28:ti_arp32', [var_platform.upper() + '-HIL: ram/rom usage for ARP32'])
                  generate_alias(algo_name + "_sim_ramrom_vh28", arp32_libsize_out, component_name + ':' + algo_name + '_sim:ramrom:vh28')
                  generate_alias(algo_name + "_sim_ramrom", arp32_libsize_out, component_name + ':' + algo_name + '_sim:ramrom')  
				  
              generate_alias(algo_name + "_sim", arp32_libsize_out, component_name + ':' + algo_name + '_sim')
          generate_alias("all", arp32_libsize_out, component_name)			  
          
          # this ensures that outfile is generated and map file is available
          SideEffect(File(mapfile).abspath, ti_arp32_sim_out)
          Depends(arp32_libsize_out, ti_arp32_sim_out)

    #-------------------------
    # build ccs 5.3 project
    #-------------------------
    try:
        ccs_project_name
    except NameError,e:
        exception_error(e,"in "+sconscript_dir+"\hil_env_config.scfg")
    arp32_sim_project = ccs_project_name

    # recover and define variants for ccs projects
    variant_names = [variant[0] for variant in variant_list]
    # recover and define lcf-files to be added to linked resources in ccs project
    lcf_files     = map(lambda x: File(x).abspath, Split(variant_list[0][6]))

    if not skip_ide_generation:
        # add include paths
        arp32_env.Append(CPPPATH = result[2])
        ide_ccs_ti_arp32 = arp32_env.EclipseProject(
                           # specify project name
                           target_name = arp32_sim_project, 
                           # specify folder for storing the project
                           target_dir = (build_dir + "/algo/" + algo_name + "_sim/" + var_instdir), 
                           # specify build variants
                           variants = variant_names, 
                           # specify preprocessor defines
                           defines = [define_list + variant[2] for variant in variant_list], 
                           # target_type : "lib" or "out"
                           target_type = "out", 
                           # core : "C6000" or "TMS470", 
                           core = "TMS470",
                           # specify compiler directory
                           code_gen_dir = tms470_code_gen_tool_dir, 
                           # list of target variants (use the same order as in variants)
                           scons_target = [algo_name + "_sim_hil_out_ti_" + var_core + "_" + variant[0] for variant in variant_list], 
                           # additional argument when running scons
                           scons_argument = "-j" + str(thread_number) + " " + "skip_ide_generation=1" + " " + "build_from_ccs=1" + " " + scons_arguments, 
                           # add build target node (for recovering headers included)
                           Build_target = result[0],
                           # add files to be displayed in ccs project (result[1]=source files, lcf_files=linker scripts)
                           linked_resources = result[1] + lcf_files, 
                           additional_natures = "")
                           
        # Make sure that compilers are extracted before generation of CCS project
        Requires(ide_ccs_ti_arp32, Dir(tms470_code_gen_tool_dir).abspath)
                           
        generate_alias(component_name + "_ide_ccs_hil_ti_" + var_core, ide_ccs_ti_arp32, component_name + ':ide:ccs:hil_ti_' + var_core, ['CCS 5: ARP32 ' + var_platform.upper() + '-HIL wrapper'])
        generate_alias(component_name + "_ide_ccs", ide_ccs_ti_arp32, component_name + ':ide:ccs')
        generate_alias(component_name + "_ide", ide_ccs_ti_arp32, component_name + ':ide')
        if algo_name != component_name:
            generate_alias(algo_name + "_ide_ccs_hil_ti_" + var_core, ide_ccs_ti_arp32, component_name + ':' + algo_name + '_ide:ccs:hil_ti_' + var_core, ['CCS 5: ARP32 ' + var_platform.upper() + '-HIL wrapper'])
            generate_alias(algo_name + "_ide_ccs", ide_ccs_ti_arp32, component_name + ':' + algo_name + '_ide:ccs')
            generate_alias(algo_name + "_ide", ide_ccs_ti_arp32, component_name + ':' + algo_name + '_ide')
        generate_alias("all", ide_ccs_ti_arp32, component_name)

    if profile:
        FinishSconscriptEntry()

    if not skip_ide_generation:
        Return(["arp32_outfile", "ide_ccs_ti_arp32", "arp32_list"])
    else:
        Return(["arp32_outfile", "arp32_list"])
        
if profile:
    FinishSconscriptEntry()        
