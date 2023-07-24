"""
Filename                  : scons_common_scripts\utils\autorel\SConscript.py
Description               : SConscript to execute automatic release sequence and generate code handover script. 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: utils\autorel\SConscript.py
#
# DESCRIPTION: SConscript to execute automatic release sequence and generate code handover script. 
#
# INITIAL AUTHOR: Stark-EXT, Roland (uidw1169)
#
# CREATION DATE: 2014/04/17
#
# LAST CHANGE:      $Date: 2021/12/13 19:07:16CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:07:16CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/utils/autorel/project.pj
# CHANGES:                   Revision 1.11 2017/05/30 14:04:45CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.10 2017/04/27 16:06:38CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.9 2016/07/01 06:56:22CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.8 2015/06/26 08:34:44CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:44 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#--------------------------
# imports
#--------------------------
Import("component_name", "help_dict");

execfile(File("#../GSCons_project_config.scfg").abspath)
#--------------------------
# read configuration files
#--------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath);
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath);

#--------------------------
# read auto release script
#--------------------------
execfile("autorel_handover.scfg");
execfile(File(scons_adas_extensions_path + "autorel_main.py").abspath);

#----------------------------------------------------------
# The builder callback function. This is the SCons wrapper
# for auto release Python script.
#
# PARAM   target  the build targets (ignored)
#         source  the build sources (ignored)
#         target  the build environment (ignored)
#
# RETURN  None
#----------------------------------------------------------
def autorelease_builder(target, source, env):
  return autorelease(File(target[0]).abspath);

# create the builder and attach it to an environment
bld = Builder(action = autorelease_builder)
env = Environment(BUILDERS = {'MakeAutoRelease' : bld})

# create the build target
txt_file = build_dir + "algo/" + component_name + "/" + component_name.upper() + "_AlgorithmCodeHandover_AutoRelease.txt"
autorel_script = env.MakeAutoRelease([txt_file], ["autorel_handover.scfg"])
generate_alias("autorel", autorel_script, "zzz", ['automatic release process'])

# execute the script - even if the input file (configuration) hasn't changed!!
AlwaysBuild(autorel_script)
