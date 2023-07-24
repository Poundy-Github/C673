"""
Filename                  :  setup\setup.py
Description               :  Script that copies config files(.scfg) from scons_tools\scons_templates to 03_Workspace.
"""

#***************************************************************************************************
# COMPANY: Continental Automotive Components, ADAS
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: sconscript_setup.py
#
# DESCRIPTION: Script that setup shared scons scripts to a project and copy them into folder structure.
#
# INITIAL AUTHOR: Bhagawati, Tridip (uidr2134) $
#
# CREATION DATE: - 2016/12/12
#
# LAST CHANGE:      $Date: 2021/12/13 19:09:01CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################

import re, os    
import shutil                           

setUpFile = "../../../03_Workspace/algo/setup.scfg"
setupDir = os.getcwd() + "\\" + setUpFile
execfile(setupDir)

sourcecodeDirectory = "../../../01_Source_Code/algo/" + component_name + "/"
templateSourcecodeDirectory = "../scons_templates/01_Source_Code/algo/xxx/"
workspaceLibDirectory = "../../../03_Workspace/algo/" + component_name + "/"
templateworkspaceLibDirectory = "../scons_templates/03_Workspace/algo/xxx/"
workspaceSimDirectory = "../../../03_Workspace/algo/" + component_name + "_sim/"
templateworkspaceSimDirectory = "../scons_templates/03_Workspace/algo/xxx_sim/"

# Create a directory with name of the component in 01_Source_Code/algo/
if not os.path.exists(sourcecodeDirectory):
	os.makedirs(sourcecodeDirectory)
	
# Copy the necessary configuration files in 01_Source_Code/algo/
if not os.path.exists(sourcecodeDirectory + "algo_config.scfg"):
	shutil.copy(templateSourcecodeDirectory + "algo_config.scfg",sourcecodeDirectory)
if not os.path.exists(sourcecodeDirectory + "algo_lib_file_list.scfg"):
	shutil.copy(templateSourcecodeDirectory + "algo_lib_file_list.scfg",sourcecodeDirectory)
	
# Create a directory with name of the component in 03_Workspace/algo/
if not os.path.exists(workspaceLibDirectory):
	os.makedirs(workspaceLibDirectory)

# Copy the necessary configuration files in 03_Workspace/algo/
if not os.path.exists(workspaceLibDirectory + "scons.bat"):
	shutil.copy(templateworkspaceLibDirectory + "scons.bat",workspaceLibDirectory)
if not os.path.exists(workspaceLibDirectory + "sconscript_setup_config.scfg"):
	shutil.copy(templateworkspaceLibDirectory + "sconscript_setup_config.scfg",workspaceLibDirectory)
if not os.path.exists(workspaceLibDirectory + "sconstruct_config.scfg"):
	shutil.copy(templateworkspaceLibDirectory + "sconstruct_config.scfg",workspaceLibDirectory)

# Create a directory with name of the component_sim in 03_Workspace/algo/	
if sim:
	if not os.path.exists(workspaceSimDirectory):
		os.makedirs(workspaceSimDirectory)


# For lib
if dsp:
	for core in dsp_core_dict:
		if dsp_core_dict[core] == True:
			directory = workspaceLibDirectory + "ti_dsp_" + core 
			if not os.path.exists(directory):
				os.makedirs(directory)
				if not os.path.isfile(directory + "/ti_" + core + "_lib_config.scfg"):
					shutil.copy("../scons_templates/03_Workspace/algo/xxx/ti_dsp_" + core + "/ti_" + core + "_lib_config.scfg", directory)

if eve:
	for core in eve_core_dict:
		if eve_core_dict[core] == True:
			directory = workspaceLibDirectory + "ti_eve_" + core 
			if not os.path.exists(directory):
				os.makedirs(directory)
				if not os.path.isfile(directory + "/ti_" + core + "_lib_config.scfg"):
					shutil.copy("../scons_templates/03_Workspace/algo/xxx/ti_eve_" + core + "/ti_" + core + "_lib_config.scfg", directory)				

if arm:
	for core in arm_core_dict:
		if arm_core_dict[core] == True:
			directory = workspaceLibDirectory + "ti_arm_" + core 
			if not os.path.exists(directory):
				os.makedirs(directory)
				if (core == "cortex_m3") | (core == "cortex_m4"):
					if not os.path.isfile(workspaceLibDirectory + "/ti_arm_cortex_mx/ti_arm_cortex_mx_lib_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx/ti_arm_cortex_mx/ti_arm_cortex_mx_lib_config.scfg", directory)
						os.rename(directory + "/ti_arm_cortex_mx_lib_config.scfg", directory + "/ti_arm_" + core + "_lib_config.scfg")
				else:
					if not os.path.isfile(directory + "/ti_arm_" + core + "_lib_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx/ti_arm_" + core + "/ti_arm_" + core + "_lib_config.scfg", directory)

# For simulation plugins
if sim:
	for sim in sim_dict:
		if sim_dict[sim] == True:
			if sim == "sim_swc":
				directory = workspaceSimDirectory + sim + "_" + component_name 
				if not os.path.exists(directory):
					os.makedirs(directory)
					if not os.path.isfile(directory + "/sim_swc_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/sim_swc_xxx/sim_swc_config.scfg", directory)
					if not os.path.isfile(directory + "/simenv_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/sim_swc_xxx/simenv_config.scfg", directory)
					if not os.path.isfile(directory + "/sim_swc_xxx_file_list.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/sim_swc_xxx/sim_swc_xxx_file_list.scfg", directory)
						os.rename(directory + "/sim_swc_xxx_file_list.scfg", directory + "/sim_swc_" + component_name + "_file_list.scfg")
			elif sim == "sim_swc_vis":
				directory = workspaceSimDirectory + "sim_swc_" + component_name + "_vis"
				if not os.path.exists(directory):
					os.makedirs(directory)
					if not os.path.isfile(directory + "/sim_swc_vis_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/sim_swc_xxx_vis/sim_swc_vis_config.scfg", directory)
					if not os.path.isfile(directory + "/simenv_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/sim_swc_xxx_vis/simenv_config.scfg", directory)
					if not os.path.isfile(directory + "/sim_swc_xxx_vis_file_list.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/sim_swc_xxx_vis/sim_swc_xxx_vis_file_list.scfg", directory)
						os.rename(directory + "/sim_swc_xxx_vis_file_list.scfg", directory + "/sim_swc_" + component_name + "_vis_file_list.scfg")
			elif sim == "sim_adapt":
				directory = workspaceSimDirectory + component_name + "_adapter" 
				if not os.path.exists(directory):
					os.makedirs(directory)
					if not os.path.isfile(directory + "/sim_adapter_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_adapter/sim_adapter_config.scfg", directory)
					if not os.path.isfile(directory + "/simenv_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_adapter/simenv_config.scfg", directory)
					if not os.path.isfile(directory + "/sim_adapter_file_list.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_adapter/sim_adapter_file_list.scfg", directory)
						os.rename(directory + "/sim_adapter_file_list.scfg", directory + "/sim_adapter_file_list.scfg")
		
# For evm hil targets
if sim:
	if evm_hil:
		directory = workspaceSimDirectory + component_name + "_evm_hil/"
		if not os.path.exists(directory):
			os.makedirs(directory)
		# For VME
		if vme:
			directory_vme = directory + "vme/"
			if not os.path.exists(directory):
				os.makedirs(directory)
			directory_evm_hil_projects = directory_vme + "evm_hil_projects/"
			if not os.path.exists(directory + ""):
				os.makedirs(directory_evm_hil_projects)
			for core in vme_dict:
				if vme_dict[core] == True:
					directory_core = directory_evm_hil_projects + core 
					if not os.path.exists(directory_core):
						os.makedirs(directory_core)
					if not os.path.isfile(directory_core + "/hil_env_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_evm_hil/vme/evm_hil_projects/" + core + "/hil_env_config.scfg", directory_core)
					if (core == "CortexA8") | (core == "CortexA8Only"):
						if not os.path.isfile(directory_core + "/ti_cortex_a8_sim_hil_config.scfg"):
							shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_evm_hil/vme/evm_hil_projects/" + core + "/ti_cortex_a8_sim_hil_config.scfg", directory_core)
						if not os.path.isfile(directory_core + "/ti_cortex_a8_sim_hil_file_list.scfg"):
							shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_evm_hil/vme/evm_hil_projects/" + core + "/ti_cortex_a8_sim_hil_file_list.scfg", directory_core)
					else:
						if not os.path.isfile(directory_core + "/ti_" + core +"_sim_hil_config.scfg"):
							shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_evm_hil/vme/evm_hil_projects/" + core + "/ti_" + core +"_sim_hil_config.scfg", directory_core)
						if not os.path.isfile(directory_core + "/ti_" + core +"_sim_hil_file_list.scfg"):
							shutil.copy("../scons_templates/03_Workspace/algo/xxx_sim/xxx_evm_hil/vme/evm_hil_projects/" + core + "/ti_" + core +"_sim_hil_file_list.scfg", directory_core)



						