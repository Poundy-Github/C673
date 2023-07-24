"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_ti_cortex_a8\SConscript.py
Description               : SConscript to build TI Cortex A8 out file.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_ti_cortex_a8\SConscript.py
#
# DESCRIPTION: SConscript to build TI Cortex A8 out file.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:44CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:44CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_ti_cortex_a8/project.pj
# CHANGES:                   Revision 1.16 2017/05/30 13:44:55CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.15 2017/04/27 16:17:56CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.14 2017/03/30 13:31:27CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Updated
# CHANGES:                   Revision 1.13 2017/02/06 08:37:23CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   [Scons]: Remove no longer existing include path from evm hil CCS projects
# CHANGES:                   Revision 1.12 2016/07/01 06:06:42CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.11 2015/09/23 16:20:33CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add dependency between sysbios generation and relevant ti-tools
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:20:34 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.10 2015/06/26 12:21:46CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 12:21:46 PM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


#-------------------------
# import
#-------------------------
Import("env", "target", "component_name", "algo_name", "profile", "SconscriptTimesTable")
import os

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('3')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/ti_cortex_a8_sim_hil_config.scfg")
# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper file
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

#-------------------------
# setup environment
#-------------------------
local_env = env.Clone()

# add source files
src = ti_cortex_a8_hil_src

# add include paths
cpp_path = (ti_cortex_a8_hil_cpp_path + 
            ["#../" + component_name + "_sim/" + component_name + "_evm_hil/vme/generic/evm_sw/platform/"] + 
            [ti_bios_dir + "packages"] + 
            [ti_xdctools_dir + "packages"] + 
            [pdk_nsp_dm814x_package_dir] +
            [pdk_nsp_dm814x_package_dir + "ti/ndk/examples_arm_a8/client/bios6/common"] +
            [pdk_nsp_dm814x_package_dir + "ti/drv/centaurus/inc"] +
            [ndk_package_dir] +
            [ndk_package_dir + "ti/ndk/inc"] + 
            [ndk_package_dir + "ti/ndk/inc/tools"])
local_env.Append(CPPPATH = cpp_path)
local_env.Prepend(CPPPATH = ti_cortex_a8_prepend_cpp_path)
cpp_path = cpp_path + ti_cortex_a8_prepend_cpp_path

# add compiler options for xdctools
local_env.Append(XS_COMP_OPTIONS = xs_compiler_options)

# add external libs
local_env.Append(LIBS = external_lib)

#-------------------------
# run xdctools
#-------------------------
sysbios_result = local_env.Xs(None, sysbios_cfg)
# This builder returns linker.cmd, compiler.opt and sysbios lib. 
# linker.cmd can be accessed from sysbios_result[1], compiler.opt from sysbios_result[2]
# and sysbios lib from sysbios_result[3].
Requires(sysbios_result, local_env['_TOOLS'])
Requires(sysbios_result, local_env['_TOOL_ADDONS'])

#-------------------------
# EVM platform check
#-------------------------
evm_platform = "vme"
# make platform VH28 if occurs in path (location of this script)
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
if "vh28" in sconscript_dir.lower():
    evm_platform = "vh28"

#-------------------------
# build out file
#-------------------------
# add generated linker file
local_env.Prepend(ARM_LCF_FILE = [File(sysbios_result[1]).abspath])

# check if the special GNU linker script for functional security is existing
if "arm_gcc" in local_env['TOOLS']:
  gcc_secure_lcf = File("#../" + component_name + "_sim/" + component_name + "_evm_hil/" + evm_platform + "/generic/CommonSoC/GnuSecureSections.lcf")
  if gcc_secure_lcf.isfile():
    local_env.Prepend(ARM_LCF_FILE = [gcc_secure_lcf.abspath])

# add generated compiler opt file
local_env.Append(CMD_OPT_FILE = [File(sysbios_result[2]).abspath])

# build object files
objects = [local_env.Object(i) for i in src]
Depends(objects, (sysbios_result[1], sysbios_result[2], sysbios_result[3], sysbios_cfg))

# build out files
out = local_env.Program(target, objects)
    
#-------------------------
# return results
#-------------------------
# get absolute include path
cpp_path = map(lambda x: str(Dir(x).srcnode().abspath), cpp_path)

# get absolute source file
cpp_src = abspath_filenames(src + [sysbios_cfg]) + target_configuration

if profile:
    FinishSconscriptEntry()

# return library, source files and include paths
Return(["out", "cpp_src", "cpp_path"])