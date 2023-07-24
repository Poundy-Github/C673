"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_env\SConscript.py
Description               : SConscript to call the build of EVM Hil out builds for EVM platforms VME and VH28.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_env\SConscript.py
#
# DESCRIPTION: SConscript to call the build of EVM Hil out builds for EVM platforms VME and VH28.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:10CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:10CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_env/project.pj
# CHANGES:                   Revision 1.26 2017/05/30 11:56:57CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.25 2017/04/27 16:22:39CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.24 2016/07/08 11:41:39CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.23 2016/06/30 12:13:08CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   lFile header added
# CHANGES:                   Revision 1.22 2016/05/31 06:55:35CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.21 2016/05/30 14:50:23CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Changed Alias name for VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.20 2016/05/13 10:46:38CEST Singh, Vishal (uidj9083) 
# CHANGES:                   for # build c674x out file replaced c66xx_result with c674x_result
# CHANGES:                   Revision 1.19 2016/05/12 14:07:04CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Introduced alias for VME and VH28 libsize calculation
# CHANGES:                   Revision 1.18 2015/12/01 13:56:36CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Fix for component SEMO generates scripting error
# CHANGES:                   Revision 1.17 2015/11/05 05:58:05CET Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Reolved the issue with c674x core while writing the .js file.
# CHANGES:                   - Added comments -  uidr0826 [Nov 5, 2015 5:58:06 AM CET]
# CHANGES:                   Change Package : 393421:1 http://mks-psad:7002/im/viewissue?selection=393421
# CHANGES:                   Revision 1.16 2015/11/04 11:29:05CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Build-target for pure ARM-simulation needed
# CHANGES:                   --- Added comments ---  uidr2134 [Nov 4, 2015 11:29:06 AM CET]
# CHANGES:                   Change Package : 392739:1 http://mks-psad:7002/im/viewissue?selection=392739
# CHANGES:                   Revision 1.15 2015/06/29 13:35:42CEST Stark-EXT, Roland (uidw1169) 
# CHANGES:                   Added support for CortexM3 and M4
# CHANGES:                   --- Added comments ---  uidw1169 [Jun 29, 2015 1:35:43 PM CEST]
# CHANGES:                   Change Package : 351977:1 http://mks-psad:7002/im/viewissue?selection=351977
# CHANGES:                   Revision 1.14 2015/06/26 11:11:26CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 11:11:26 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build out files

#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "scons_arguments", "component_name", "c674x_used", "eve_used", "ca8_used", "cm3_used", "cm4_used", "gcc_used", "ca15_used", "c66xx_used", "thread_number", "define_list", "algo_name", "profile", "SconscriptTimesTable", "eve_hil_miniapp_used")

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('1')

#-------------------------
# read configuration file
#-------------------------
# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read additional helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/generate_DebugServerScripting.py").abspath)

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

#-------------------------
# export
#-------------------------
Export("skip_ide_generation", "scons_arguments", "component_name", "eve_used", "ca8_used", "thread_number", "define_list")

#-------------------------
# EVM platform check
#-------------------------
evm_platform = "vme"
# make platform VH28 if occurs in path (location of this script)
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
if "vh28" in sconscript_dir.lower():
    evm_platform = "vh28"

#-------------------------
# build arp32 out file
#-------------------------
arp32_outfile = None
arp32miniapp_outfile = None
arp32_files = []
if eve_used:
    arp32_result = SConscript("arp32/SConscript_arp32env.py", 
               exports = {"component_name" : component_name, "algo_name" : algo_name})
    arp32_outfile = arp32_result[0]
    if not skip_ide_generation:
        arp32_files+= arp32_result[2]
    else:
        arp32_files+= arp32_result[1]		
    if eve_hil_miniapp_used:
        arp32miniapp_result = SConscript("arp32_miniapp/SConscript_arp32env.py", 
               exports = {"component_name" : component_name, "algo_name" : algo_name})		
    
cortexM3_files = []
c674x_files = []
cortexA8_files = []
if (evm_platform == "vme"):
    cortexM3_outfile = None
    if cm3_used:
        #-------------------------
        # build c674x out file
        #-------------------------               
        cm3_result = SConscript("CortexM3/SConscript_cortexm3env.py", 
                   exports = {"component_name" : component_name, "algo_name" : algo_name})
        cortexM3_outfile = cm3_result[0]
		
        if not skip_ide_generation:		
            cortexM3_files+= cm3_result[3]
        else:
            cortexM3_files+= cm3_result[1]
		

    c674x_outfile = None
    if c674x_used:
        #-------------------------
        # build c674x out file
        #-------------------------               
        c674x_result = SConscript("C674x/SConscript_c674xenv.py", 
                   exports = {"component_name" : component_name, "algo_name" : algo_name})
        c674x_outfile = c674x_result[0]
        if not skip_ide_generation:		
            c674x_files+= c674x_result[2]
        else:
            c674x_files+= c674x_result[1]		

    if cm3_used or c674x_used or ca8_used:
        #-------------------------
        # build cortex A8 out file
        #-------------------------
        cortexA8_result = SConscript("CortexA8/SConscript_cortexa8env.py", 
                   exports = {"component_name" : component_name, "algo_name" : algo_name})
        
    #------------------------------
    # build cortex A8 only out file
    #(runs algo without DSP C674x)
    #------------------------------
    if ca8_used:
        script_ti  = File("CortexA8Only/SConscript_cortexa8onlyenv.py")
        script_gcc = File("CortexA8Only/SConscript_cortexa8gccenv.py")
        if script_gcc.exists():
          if script_ti.exists():
            try:
              # we are now building with gcc 
              # -> remove the obsolete TI script from local sandbox
              os.remove(script_ti.abspath)
            except:
              print "Warning: couldn't remove obsolete CortexA8Only TI build environment."

          # call the gcc based script
          cortexA8only_result = SConscript(script_gcc.abspath, 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
          if not skip_ide_generation:
            cortexA8_files+= cortexA8only_result[3]
          else:
            cortexA8_files+= cortexA8only_result[1]	
        else:
          # call the old TI compiler based evm hil wrapper
          cortexA8only_result = SConscript(script_ti.abspath, 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
          if not skip_ide_generation:
            cortexA8_files+= cortexA8only_result[3]
          else:
            cortexA8_files+= cortexA8only_result[1]		
        
c66xx_files = []
cortexA15_files = []
cortexM4_files = []
if (evm_platform == "vh28"):
    #-------------------------
    # build c66xx out file
    #-------------------------               
    c66xx_outfile = None
    if c66xx_used:
      c66xx_result = SConscript("C66xx/SConscript_c66xxenv.py", 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
      c66xx_outfile = c66xx_result[0]
	  
      if not skip_ide_generation:		
          c66xx_files+= c66xx_result[2]
      else:
          c66xx_files+= c66xx_result[1]		  

    #--------------------------
    # build cortex A15 out file
    #--------------------------
    cortexA15_outfile = None
    if ca15_used:
      cortexA15_result = SConscript("CortexA15/SConscript_cortexa15env.py", 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
      cortexA15_outfile = cortexA15_result[0]
	  
      if not skip_ide_generation:		
          cortexA15_files+= cortexA15_result[3]
      else:
          cortexA15_files+= cortexA15_result[1]  

    #-------------------------
    # build cortex M4 out file
    #-------------------------
    cortexM4_result= SConscript("CortexM4/SConscript_cortexm4env.py", 
                exports = {"component_name" : component_name, "algo_name" : algo_name})				
    if not skip_ide_generation:		
        cortexM4_files+= cortexM4_result[3]
    else:
        cortexM4_files+= cortexM4_result[1]

vme_vh28_env = Environment(# list of scons extensions used
                        tools = ["eclipse_cdt_ccs5"],
                        # path to scons extensions
                        toolpath = [scons_adas_extensions_path])
execfile(File(scons_adas_extensions_path + "ram_rom_algo_libsize.py").abspath)						
if (evm_platform == "vme"):
    file_list = []

    if eve_used:
        file_list+=arp32_files
			
    if cm3_used:
        file_list+= cortexM3_files
			
    if c674x_used:
        file_list+= c674x_files	
		
    if ca8_used:
        file_list+=cortexA8_files
    outdir = (build_dir + "/algo/" + algo_name + "_sim/")
    outfile = File(outdir+"vme_ramrom.txt")

    vme_libsize_out = generateVME_VH28LibSize(vme_vh28_env, file_list, outfile)
	
	
    generate_alias(component_name + "_sim_ramrom_vme", vme_libsize_out)
    generate_alias(component_name + "_sim_ramrom", vme_libsize_out)	
    generate_alias(component_name + "_sim", vme_libsize_out)
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_ramrom_vme", vme_libsize_out)
        generate_alias(algo_name + "sim_ramrom", vme_libsize_out)		
        generate_alias(algo_name + "_sim", vme_libsize_out)
    generate_alias("all", vme_libsize_out)	
	
elif (evm_platform == "vh28"):
    file_list = []
	
    if eve_used:
        file_list+=arp32_files
			
    if c66xx_used:
        file_list+=c66xx_files
	
    if ca15_used:
        file_list+=cortexA15_files
			
    if cm4_used:		
        file_list+=cortexM4_files

    outdir = (build_dir + "/algo/" + algo_name + "_sim/")
    outfile = File(outdir+"vh28_ramrom.txt")	

    vh28_libsize_out = generateVME_VH28LibSize(vme_vh28_env, file_list, outfile)	

    generate_alias(component_name + "_sim_ramrom_vh28", vh28_libsize_out)
    generate_alias(component_name + "_sim_ramrom", vh28_libsize_out)	
    generate_alias(component_name + "_sim", vh28_libsize_out)
    if algo_name != component_name:
        generate_alias(algo_name + "_sim_ramrom_vh28", vh28_libsize_out)
        generate_alias(algo_name + "_sim_ramrom", vh28_libsize_out)		
        generate_alias(algo_name + "_sim", vh28_libsize_out)
    generate_alias("all", vh28_libsize_out)	

	
if not skip_ide_generation:
    
    if (evm_platform == "vme"):
        # generate script files for eval board simulation
        debug_server_script_dir = build_dir + "/algo/" + algo_name + "_sim/ti_cortex_a8/"
        bat_file_name = "_CopyDSScriptLoadCmdToClipboard.bat"
        js_file_name = "DebugServerScripting.js"

        Depends(cortexA8_result[1], generate_DebugServerScripting(algo_name, debug_server_script_dir, 
                                               bat_file_name, js_file_name, cortexA8_result[2], cortexA8_result[0], 
                                               c674x_outfile, arp32_outfile, arp32miniapp_outfile, cortexM3_outfile))

        Clean(cortexA8_result[1], 
                  [debug_server_script_dir + bat_file_name, debug_server_script_dir + js_file_name])

        if ca8_used:
            Clean(cortexA8only_result[1], 
                [debug_server_script_dir + bat_file_name, debug_server_script_dir + js_file_name])
    
    if (evm_platform == "vh28"):
        # generate script files for eval board simulation
        debug_server_script_dir = build_dir + "/algo/" + algo_name + "_sim/ti_cortex_m4/"
        bat_file_name = "_CopyDSScriptLoadCmdToClipboard.bat"
        js_file_name = "DebugServerScripting.js"
        
        Depends(cortexM4_result[1], generate_DebugServerScriptingVH28(algo_name, debug_server_script_dir, 
               bat_file_name, js_file_name, cortexM4_result[2], cortexM4_result[0], cortexA15_outfile, c66xx_outfile, arp32_outfile, arp32miniapp_outfile))

        Clean(cortexM4_result[1], [debug_server_script_dir + bat_file_name, debug_server_script_dir + js_file_name])

if profile:
    FinishSconscriptEntry() 