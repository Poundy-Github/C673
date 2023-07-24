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
# LAST CHANGE:      $Date: 2021/12/14 03:42:58CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/14 03:42:58CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/03_Workspace/Component_Workspace/LCF_sim/lcf_evm_hil/vme/evm_hil_projects/CortexA8Only/project.pj
# CHANGES:                   Revision 1.2 2017/06/27 14:01:33CEST Asong, Wedndah Asaha (uidj2187) 
# CHANGES:                   Modified scons config scripts for Mainstream SIL-Build
# CHANGES:                   Revision 1.1 2017/06/13 16:06:34CEST Berendes, Ignacius (uid41806) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/03_Workspace/Component_Workspace/LCF_sim/lcf_evm_hil/vme/evm_hil_projects/CortexA8Only/project.pj
# CHANGES:                   Revision 1.0 2016/07/01 12:20:17CEST Prajescu, Claudia (uidl9533) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/03_Workspace/algo/lcf_sim/lcf_evm_hil/vme/evm_hil_projects/CortexA8Only/project.pj
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

if profile:
    execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('3')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/ti_cortex_a8_sim_hil_config.scfg")
# get common scons config containing tool paths
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper file
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

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