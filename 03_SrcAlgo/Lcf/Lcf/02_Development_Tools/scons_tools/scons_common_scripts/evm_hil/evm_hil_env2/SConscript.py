"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_env2\SConscript.py
Description               : Sconscript to call the build of EVM Hil out builds for EVM platforms VME and VH28, 
							where VME requires Cortex_a8_Only WITHOUT C674x.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_env2\SConscript.py
#
# DESCRIPTION: Sconscript to call the build of EVM Hil out builds for EVM platforms VME and VH28, 
#              where VME requires Cortex_a8_Only WITHOUT C674x.
#
# INITIAL AUTHOR: Andre.Fischer-Ext (uidg5297)
#
# CREATION DATE: 2014/10/17
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:15CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:15CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_env2/project.pj
# CHANGES:                   Revision 1.6 2017/05/30 12:28:07CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.5 2017/04/27 16:23:36CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.4 2016/07/01 05:48:50CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.3 2015/06/26 11:11:25CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 11:11:25 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#-------------------------
# import
#-------------------------
Import("skip_ide_generation", "scons_arguments", "component_name", "c674x_used", "eve_used", "ca8_used", "gcc_used", "ca15_used", "c66xx_used", "thread_number", "define_list", "algo_name", "profile", "SconscriptTimesTable")

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
if eve_used:
    arp32_result = SConscript("arp32/SConscript_arp32env.py", 
               exports = {"component_name" : component_name, "algo_name" : algo_name})
    arp32_outfile = arp32_result[0]

if (evm_platform == "vme"):
    # if c674x_used:
        # #-------------------------
        # # build c674x out file
        # #-------------------------               
        # c674x_result = SConscript("C674x/SConscript_c674xenv.py", 
                   # exports = {"component_name" : component_name, "algo_name" : algo_name})

        # #-------------------------
        # # build cortex A8 out file
        # #-------------------------
        # cortexA8_result = SConscript("CortexA8/SConscript_cortexa8env.py", 
                   # exports = {"component_name" : component_name, "algo_name" : algo_name})
        
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
        else:
          # call the old TI compiler based evm hil wrapper
          cortexA8only_result = SConscript(script_ti.abspath, 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
        

if (evm_platform == "vh28"):
    #-------------------------
    # build c66xx out file
    #-------------------------               
    c66xx_outfile = None
    if c66xx_used:
      c66xx_result = SConscript("C66xx/SConscript_c66xxenv.py", 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
      c66xx_outfile = c66xx_result[0]

    #--------------------------
    # build cortex A15 out file
    #--------------------------
    cortexA15_outfile = None
    if ca15_used:
      cortexA15_result = SConscript("CortexA15/SConscript_cortexa15env.py", 
                exports = {"component_name" : component_name, "algo_name" : algo_name})
      cortexA15_outfile = cortexA15_result[0]

    #-------------------------
    # build cortex M4 out file
    #-------------------------
    cortexM4_result = SConscript("CortexM4/SConscript_cortexm4env.py", 
               exports = {"component_name" : component_name, "algo_name" : algo_name})

if not skip_ide_generation:
    
    if (evm_platform == "vme"):
        # generate script files for eval board simulation
        debug_server_script_dir = build_dir + "/algo/" + algo_name + "_sim/ti_cortex_a8/"
        bat_file_name = "_CopyDSScriptLoadCmdToClipboard.bat"
        js_file_name = "DebugServerScripting.js"
        
        # if c674x_used:
            # if eve_used:
                # Depends(cortexA8_result[1], generate_DebugServerScripting(algo_name, debug_server_script_dir, 
                                               # bat_file_name, js_file_name, cortexA8_result[2], cortexA8_result[0], 
                                               # c674x_result[0], arp32_result[0]))
            # else:
                # Depends(cortexA8_result[1], generate_DebugServerScripting(algo_name, debug_server_script_dir, 
                                               # bat_file_name, js_file_name, cortexA8_result[2], cortexA8_result[0], 
                                               # c674x_result[0], None))

            # Clean(cortexA8_result[1], 
                  # [debug_server_script_dir + bat_file_name, debug_server_script_dir + js_file_name])

        if ca8_used:
            Clean(cortexA8only_result[1], 
                [debug_server_script_dir + bat_file_name, debug_server_script_dir + js_file_name])
    
    if (evm_platform == "vh28"):
        # generate script files for eval board simulation
        debug_server_script_dir = build_dir + "/algo/" + algo_name + "_sim/ti_cortex_m4/"
        bat_file_name = "_CopyDSScriptLoadCmdToClipboard.bat"
        js_file_name = "DebugServerScripting.js"
        
        Depends(cortexM4_result[1], generate_DebugServerScriptingVH28(algo_name, debug_server_script_dir, 
               bat_file_name, js_file_name, cortexM4_result[2], cortexM4_result[0], cortexA15_outfile, c66xx_outfile, arp32_outfile))

        Clean(cortexM4_result[1], [debug_server_script_dir + bat_file_name, debug_server_script_dir + js_file_name])
    
if profile:
    FinishSconscriptEntry()