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

setUpFile = "../../../03_Workspace/Component_Workspace/setup_mainstream.scfg"
setupDir = os.getcwd() + "\\" + setUpFile
execfile(setupDir)

sourcecodeDirectory = "../../../01_Source_Code/" + component_name + "/"
templateSourcecodeDirectory = "../scons_templates/01_Source_Code/xxx/"
workspaceLibDirectory = "../../../03_Workspace/Component_Workspace/" + component_name + "/"
templateworkspaceLibDirectory = "../scons_templates/03_Workspace/Component_Workspace/xxx/"
workspaceSimDirectory = "../../../03_Workspace/Component_Workspace/" + component_name + "_sim/"
templateworkspaceSimDirectory = "../scons_templates/03_Workspace/Component_Workspace/xxx_sim/"

# Create a directory with name of the component in 01_Source_Code/
if not os.path.exists(sourcecodeDirectory):
	os.makedirs(sourcecodeDirectory)
	
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
if not os.path.exists(workspaceLibDirectory + "algo_config.scfg"):
	shutil.copy(templateworkspaceLibDirectory + "algo_config.scfg",workspaceLibDirectory)
if not os.path.exists(workspaceLibDirectory + "algo_lib_file_list.scfg"):
	shutil.copy(templateworkspaceLibDirectory + "algo_lib_file_list.scfg",workspaceLibDirectory)


# Create a directory with name of the component_sim in 03_Workspace/Component_Workspace/	
if sim:
	if not os.path.exists(workspaceSimDirectory):
		os.makedirs(workspaceSimDirectory)


# For simulation plugins
if sim:
	for sim in sim_dict:
		if sim_dict[sim] == True:
			if sim == "sim_swc":
				directory = workspaceSimDirectory + sim + "_" + component_name 
				if not os.path.exists(directory):
					os.makedirs(directory)
					if not os.path.isfile(directory + "/sim_swc_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/sim_swc_xxx/sim_swc_config.scfg", directory)
					if not os.path.isfile(directory + "/simenv_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/sim_swc_xxx/simenv_config.scfg", directory)
					if not os.path.isfile(directory + "/sim_swc_xxx_file_list.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/sim_swc_xxx/sim_swc_xxx_file_list.scfg", directory)
						os.rename(directory + "/sim_swc_xxx_file_list.scfg", directory + "/sim_swc_" + component_name + "_file_list.scfg")
			elif sim == "sim_swc_vis":
				directory = workspaceSimDirectory + "sim_swc_" + component_name + "_vis"
				if not os.path.exists(directory):
					os.makedirs(directory)
					if not os.path.isfile(directory + "/sim_swc_vis_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/sim_swc_xxx_vis/sim_swc_vis_config.scfg", directory)
					if not os.path.isfile(directory + "/simenv_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/sim_swc_xxx_vis/simenv_config.scfg", directory)
					if not os.path.isfile(directory + "/sim_swc_xxx_vis_file_list.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/sim_swc_xxx_vis/sim_swc_xxx_vis_file_list.scfg", directory)
						os.rename(directory + "/sim_swc_xxx_vis_file_list.scfg", directory + "/sim_swc_" + component_name + "_vis_file_list.scfg")
			elif sim == "sim_adapt":
				directory = workspaceSimDirectory + component_name + "_adapter" 
				if not os.path.exists(directory):
					os.makedirs(directory)
					if not os.path.isfile(directory + "/sim_adapter_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/xxx_adapter/sim_adapter_config.scfg", directory)
					if not os.path.isfile(directory + "/simenv_config.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/xxx_adapter/simenv_config.scfg", directory)
					if not os.path.isfile(directory + "/sim_adapter_file_list.scfg"):
						shutil.copy("../scons_templates/03_Workspace/Component_Workspace/xxx_sim/xxx_adapter/sim_adapter_file_list.scfg", directory)
						os.rename(directory + "/sim_adapter_file_list.scfg", directory + "/sim_adapter_file_list.scfg")
		


						