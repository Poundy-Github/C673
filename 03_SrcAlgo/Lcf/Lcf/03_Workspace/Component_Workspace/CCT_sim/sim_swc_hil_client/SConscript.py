# SConscript to build hil client

#-------------------------
# import
#-------------------------
Import("env", "target", "component_name")

#-------------------------
# read configuration file
#-------------------------
# read file list containing source files and include paths
execfile(File("#../../../02_Development_Tools/scons_tools/scons_common_config/externals_include_file_list.scfg").abspath)

#-------------------------
# read helper
#-------------------------
execfile(File("#../../../02_Development_Tools/scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

#-------------------------
# setup environment
#-------------------------
pc_sim_hil_client_source_files = """
sim_hil_client_dll.cpp
stdafx.cpp
algo/hil_client.cpp
"""

pc_sim_hil_client_include_paths = """
.
algo/
#../../../01_Source_Code/externals/sim/include/ctk/
#../../../01_Source_Code/externals/sim/include/sim_kernel/
#../../../01_Source_Code/externals/sim/include/sim_swc/
#../../../01_Source_Code/externals/sim/include/sim_adapter/
"""

local_env = env.Clone()

# add include file paths
cpp_path = (Split(pc_sim_hil_client_include_paths) + 
            Split(externals_include_paths))
local_env.Append(CPPPATH = cpp_path)

# add external library paths
external_lib_paths = ["#../../../01_Source_Code/externals/sim/lib/", "#../../../01_Source_Code/externals/sim/lib/ctk"]
lib_path = [Dir(x).abspath for x in Split(external_lib_paths)]
local_env.Append(LIBPATH = lib_path)

# add source files
src = Split(pc_sim_hil_client_source_files)

# external libraries
external_lib = ["Ws2_32.lib", "kernel32.lib", "user32.lib", "gdi32.lib", 
                "winspool.lib", "comdlg32.lib", "advapi32.lib", "shell32.lib", 
                "ole32.lib", "oleaut32.lib", "uuid.lib", "odbc32.lib", "odbccp32.lib"]
        
#-------------------------
# build DLL
#-------------------------
lib = local_env.SharedLibrary(target, src, LIBS = external_lib)

#-------------------------
# return result
#-------------------------
# get absolute file path
cpp_src = abspath_filenames(src)

# get absolute include path
cpp_path = map(lambda x: str(Dir(x).srcnode().abspath), cpp_path)

# return library, source files and include paths
Return(["lib", "cpp_src", "cpp_path", "lib_path"])