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
# LAST CHANGE:      $Date: 2021/12/14 01:43:17CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/14 01:43:17CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/03_Workspace/Component_Workspace/LCF/autorelease/project.pj
# CHANGES:                   Revision 1.2 2017/06/27 14:02:40CEST Asong, Wedndah Asaha (uidj2187) 
# CHANGES:                   Modified scons config scripts for Mainstream SIL-Build
# CHANGES:                   Revision 1.1 2017/06/13 16:13:00CEST Berendes, Ignacius (uid41806) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/03_Workspace/Component_Workspace/LCF/autorelease/project.pj
# CHANGES:                   Revision 1.0 2016/07/01 12:15:20CEST Prajescu, Claudia (uidl9533) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/03_Workspace/algo/lcf/autorelease/project.pj
# CHANGES:                   Revision 1.8 2015/06/26 08:34:44CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:44 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#--------------------------
# imports
#--------------------------
Import("component_name", "help_dict");

#--------------------------
# read configuration files
#--------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/common_config.scfg").abspath);
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/help_menu.py").abspath);

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
