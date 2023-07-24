# SConscript to build component specific algo sdl-file via env.PDO instead of env.PdoFile

# ----------------------------------------------------------------------------------------
# Note: 
# 1. Define required sdl-files in sdl_names
# 2. adapt virtual address in vaddr
# 3. adapt PDO_TOOLS_OPTIONS in line with project (NN stands for task id)
# 4. Fill in input for PDP-tool
# ----------------------------------------------------------------------------------------

#-------------------------
# import
#-------------------------
Import("env", "core", "component_name", "algo_name", "bld_dir")
import os

# get common scons config containing tool paths
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper file
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

#-------------------------
# sdl to be generated
# ------------------------
sdl_name = ["file.sdl"]

sdl_file = []


vaddr = "0x07100000"

# generate sdl-files

# ------------------------
# define pdo environment with pdo flags
# ------------------------

pdo_env = env.Clone(PDO_TOOL_OPTIONS = "-f sdl2.0 --disable normalobj --enable virtualobj --cycleinfo default," + 
                       algo_name.upper() + "_ENV_PVT " + algo_name.upper() + " NN -v 0x00000000-0xFFFFFFFF --checkvirtrange 0x00000000-0xFFFFFFFF")

					   
sdl_file += pdo_env.Pdo(bld_dir + "/01_Source_Code/algo/" + component_name + "/" + sdl_name[0], """
#include "srif_outputdebug.h"
SRIFMeasOutputA_t SRIFMeasOutputA; /*!< sr @vaddr: %(vaddrA)s */
\n
""" % locals())

# copy SDL file to 05_Deliverables folder
if "release" in pdo_env["variant"]:
    sdl_file += pdo_env.Install((deliverables_dir + "/sdl/" + core + "/algo/" + algo_name + "/"), bld_dir + "/01_Source_Code/algo/" + component_name "/" + sdl_name[0])
    
# in case of a simulation target, in general also a .cdl-file is required    
if "SIM" in env["_BUILD_TARGET"]:
    # compile SDL file
    sdl_file += pdo_env.SdlCompiler("sim_swc_" + algo_name + ".cdl", sdl_name[0])
                                
    # copy CDL file to sim_swc_(component) in 04_Build folder
    sdl_file += pdo_env.Install((build_dir + "/algo/" + algo_name + 
                                "_sim/pc/sim_swc_" + algo_name + "/" + env["variant"]), 
                                "sim_swc_" + algo_name + ".cdl")
								 
Return("sdl_file")