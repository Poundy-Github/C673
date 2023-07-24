"""
Filename                  : scons_common_scripts\sim\sim_swc\SConscript.py
Description               : SConscript to build Sim HIL wrapper (SWC-Plugin: dll, sdl, cdl, res-file). 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: sim\sim_swc\SConscript.py
#
# DESCRIPTION: SConscript to build Sim HIL wrapper (SWC-Plugin: dll, sdl, cdl, res-file). 
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:07:05CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:07:05CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/sim/sim_swc/project.pj
# CHANGES:                   Revision 1.27 2017/11/15 07:51:38CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   [Mainstream]Scons issues fixed with the version of VS
# CHANGES:                   Revision 1.26 2017/09/07 12:05:29CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   *.rc file path in current gscons for Mainstream is hardcoded
# CHANGES:                   Revision 1.25 2017/09/07 11:59:20CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   *.rc file path in current gscons for Mainstream is hardcoded
# CHANGES:                   Revision 1.24 2017/09/07 11:34:02CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Command line too long error
# CHANGES:                   Revision 1.23 2017/05/30 14:03:54CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.22 2017/04/27 16:05:12CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Support Mainstream adaptation
# CHANGES:                   Revision 1.21 2016/08/16 10:48:04CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   RTA_ID_xxx.xml generation - last entry of enum is missing
# CHANGES:                   Revision 1.20 2016/08/16 07:43:14CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   RTA_ID_xxx.xml generation - last entry of enum is missing
# CHANGES:                   Revision 1.19 2016/08/11 06:37:32CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   RTA_ID_xxx.xml generation - last entry of enum is missing
# CHANGES:                   Revision 1.18 2016/07/12 07:07:37CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons.
# CHANGES:                   Revision 1.17 2016/07/01 06:55:05CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.16 2015/09/24 12:31:19CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Modify the RTA xml file to xml format when opened in notepad
# CHANGES:                   - Added comments -  uidr2134 [Sep 24, 2015 12:31:20 PM CEST]
# CHANGES:                   Change Package : 380152:1 http://mks-psad:7002/im/viewissue?selection=380152
# CHANGES:                   Revision 1.15 2015/08/28 07:43:56CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   updated from version 1.14
# CHANGES:                   --- Added comments ---  uidr2134 [Aug 28, 2015 7:43:57 AM CEST]
# CHANGES:                   Change Package : 371281:1 http://mks-psad:7002/im/viewissue?selection=371281
# CHANGES:                   Revision 1.14 2015/08/27 12:41:16CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   New Feature:Generate RTA-xml file from enum definitions
# CHANGES:                   --- Added comments ---  uidr2134 [Aug 27, 2015 12:41:16 PM CEST]
# CHANGES:                   Change Package : 371281:1 http://mks-psad:7002/im/viewissue?selection=371281
# CHANGES:                   Revision 1.13 2015/06/26 08:34:45CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 8:34:45 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build Sim HIL wrapper

#-------------------------
# import
#-------------------------
Import("env", "target","exception_handler_file_list", "exception_handler", "component_name", "vc_project_name", "folder_name", "build_folder_name", "component_name_for_sim_folder", "scons_target_name", "algo_name", "algo_name_for_build_folder", "help_dict", "profile", "SconscriptTimesTable", "generate_vs2010")
import os
import re
from xml.dom.minidom import Document

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('3')

#-------------------------
# read configuration file
#-------------------------
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/sim_swc_config.scfg")
execfile(sconscript_dir + "/simenv_config.scfg")
# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/spawn_custom.py").abspath)

# read gscons_exception_handler
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)

try:
    analyse_rta
except Exception,e:
    exception_warning(e,exception_handler,"but set as False")
    analyse_rta = False

# get relative path of a file
relpath = os.path.relpath(sconscript_dir,os.path.dirname(os.path.dirname(os.path.dirname(sconscript_dir))))
msg="in "+relpath+r"\simenv_config.scfg"

#-------------------------
# setup environment
#-------------------------
local_env = env.Clone()

# add include file paths
cpp_path = sim_swc_cpp_path + [testing_path_from_sconstruct + "06_Test_Tools/mts/include/"]
local_env.Append(CPPPATH = cpp_path)

# add library paths
lib_path = [Dir(x).abspath for x in Split(external_lib_paths)]
local_env.Append(LIBPATH = lib_path)

# add library
local_env.Append(LIBS = external_lib)

# add source files
src = sim_swc_src

#-------------------------
# generate SDL file
#-------------------------
if generate_sdl:
    # get PDO source file
    pdo_src = abspath_filenames(pdo_src_list)

    # generate SDL file using pdo extension
    sdl_file = []

    # setup pdo environment
    pdo_env = local_env.Clone(# list of scons extensions used
                tools = ["pdo"], 
                # path to scons extensions
                toolpath = [scons_adas_extensions_path],
                # path to Pdo tools executable
                PDO_TOOLS = pdo_dir, 
                # path to PDO scan configuration
                PDO_SCAN_CONFIG = pdo_scan_config, 
                # PDO tool options
                PDO_TOOL_OPTIONS = PDO_TOOL_OPTIONS_SIM,
                # path to SDL compiler
                SDL_COMPILER = sdl_compiler_dir)

    # add include path for standard library
    pdo_env.Append(CPPPATH = Split(compiler_include_paths))
    pdo_env['PDOSCANCOM'] = '${TEMPFILE("pdo_scan.exe -c $_PDO_SCAN_CONFIG $_CPPINCFLAGS $_CPPDEFFLAGS -o $TARGET $SOURCES")}'
    # generate SDL file
    sdl_file += pdo_env.PdoFile(vc_project_name + ".sdl", pdo_src)

    # compile SDL file
    sdl_file += pdo_env.SdlCompiler(vc_project_name + ".cdl", vc_project_name + ".sdl")
                                
    # copy CDL file to sim_swc_(component) in 04_Build folder
    sdl_file += pdo_env.Install((build_dir + "/algo/" + algo_name_for_build_folder + 
                                "_sim/pc/" + build_folder_name + "/" + env["variant"]), 
                                vc_project_name + ".cdl")

    if algo_name != component_name:
        generate_alias(algo_name + "_" + scons_target_name + "_" + env["variant"], sdl_file)
        generate_alias(algo_name + "_" + scons_target_name, sdl_file)
        generate_alias(algo_name + "_sim_pc_" + env["variant"], sdl_file)
        generate_alias(algo_name + "_sim_pc", sdl_file)
        generate_alias(algo_name + "_sim_" + env["variant"], sdl_file)
        generate_alias(algo_name + "_sim", sdl_file)
        generate_alias(algo_name + "_sdl", sdl_file)
    
    generate_alias(component_name + "_" + scons_target_name + "_" + env["variant"], sdl_file)
    generate_alias(component_name + "_" + scons_target_name, sdl_file)
    generate_alias(component_name + "_sim_pc_" + env["variant"], sdl_file)
    generate_alias(component_name + "_sim_pc", sdl_file)
    generate_alias(component_name + "_sim_" + env["variant"], sdl_file)
    generate_alias(component_name + "_sim", sdl_file)
    generate_alias(component_name + "_sdl", sdl_file)    
    generate_alias(env["variant"], sdl_file)
    generate_alias("all_" + env["variant"], sdl_file)
    generate_alias("all", sdl_file)

#-------------------------
# generate res file
#-------------------------
if generate_vs2010:
    local_env['SHELL'] = File(sh_exec).abspath
    local_env['SPAWN'] = spawn

try:
    rc_file_dir
except NameError,e:
    exception_warning(e,exception_handler,msg)
    rc_file_dir = ("#../" + component_name_for_sim_folder + "_sim/" + folder_name + "/")
	
if patch_rc_file:
    patched_rc_file_dir = (build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" + 
                       build_folder_name + "/" + local_env["variant"] + "/")
else:
    copied_rc_file_dir = (build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" + 
                       build_folder_name + "/" + local_env["variant"] + "/")

# setup vsscript environment
res_env = local_env.Clone(# list of scons extensions used
                          tools = ["vsscript"], 
                          # path to scons extensions
                          toolpath = [scons_adas_extensions_path], 
                          # path to vb script folder
                          VS_SCRIPT_DIR = visual_studio_script_dir)
if patch_rc_file:
    patched_rc_file = res_env.ResPatch((patched_rc_file_dir + vc_project_name + ".rc"), 
                                   algo_version_file)
    res_env.AddPreAction(patched_rc_file, Copy(Dir(patched_rc_file_dir).abspath, 
                     File(rc_file_dir + vc_project_name + ".rc").abspath))
    res_file = local_env.RES([File(patched_rc_file[0]).abspath])
else:
    copied_rc_file = res_env.Command(File(copied_rc_file_dir + vc_project_name + ".rc").abspath, File(rc_file_dir + vc_project_name + ".rc").abspath, Copy("$TARGET", "$SOURCE"))
    res_file = local_env.RES([copied_rc_file])

local_env.Append(LIBS = res_file)
Depends(res_file, build_dir + "/algo/" + algo_name_for_build_folder + "_sim/pc/" + 
                       build_folder_name + "/" + local_env["variant"] + "/" + vc_project_name + ".cdl")

					   
#--------------------------------------------				   
# Action to read rta signals from header file
#--------------------------------------------
def read_rta_signal(target, source, env):
    fileList = []
    for i in xrange(len(source)):
        fileList.append((File(source[i])).abspath)
    destFile = (File(target[0])).abspath
    fileOne_enum_name_list = []
    fileOne_enum_value_list = []
    try:
        enumList
    except NameError,e:
        exception_warning(e,exception_handler,"in the configuration file hence RTA signal xml doc cannot be generated")
        return None
    try:
        patternList
    except NameError,e:
        exception_warning(e,exception_handler,"in the configuration file hence RTA signal xml doc cannot be generated")
        return None
    if len(source) == 0:
        print "====================="
        print "List of source file are not defined in the configuration file hence RTA signal xml doc cannot be generated"
        print "====================="
        return None
    if len(enumList) == 0:
        print "====================="
        print "List of Enum's are not defined in the configuration file hence RTA signal xml doc cannot be generated"
        print "====================="
        return None
    if len(patternList) == 0:
        print "====================="
        print "List of pattern are not defined in the configuration file hence RTA signal xml doc cannot be generated"
        print "====================="
        return None
    for file in fileList:
        fileOne = open(file, 'r')
        fileOneContent = fileOne.read()

        enum_var_name = re.findall('enum\s+\s*{[^{}]*}\s*(\w+)\s*;', fileOneContent)

        fileOneEnum = re.findall('enum\s*{\s*([^}]*)', fileOneContent)
        # To remove the comments in the header file		
		
        for i_value1 in xrange(len(enum_var_name)):
            if enum_var_name[i_value1] in enumList:
                noncomments = removeComments(''.join(fileOneEnum[i_value1]))
                contentListOne = noncomments.split(',')
                for i in contentListOne:
                    if re.search(r'=',i):
                        if i.split('=')[1].strip().isdigit():                            
                            fileOne_enum_value_list.append(i.split('=')[1].strip())
                            fileOne_enum_name_list.append(i.split('=')[0].strip())                 
        for pattern in patternList:
            for i_value3 in xrange(len(fileOne_enum_name_list)):
                if re.search(pattern, fileOne_enum_name_list[i_value3]):			
                    sub = re.sub(pattern, "", fileOne_enum_name_list[i_value3])
                    fileOne_enum_name_list[i_value3] = sub
        doc = Document()
        base = doc.createElement('Events')
        doc.appendChild(base)

        for i_value4 in range(len(fileOne_enum_value_list)):
            child = doc.createElement('Event')
            child.setAttribute('name', fileOne_enum_name_list[i_value4])
            child.setAttribute('localID', fileOne_enum_value_list[i_value4])
            base.appendChild(child)
        doc.writexml(open(destFile, 'w'),
             indent = "",
             addindent = "  ",
             newl = '\n')
        doc.unlink()
        fileOne.close()
    return None
	
#--------------------------------------------				   
# Action to remove the comments from header file
#--------------------------------------------
def removeComments(string):
    string = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,string) # remove all occurrence streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile("//.*?\n" ) ,"" ,string) # remove all occurrence single line comments (//COMMENT\n ) from string
    return string
	
	
#------------------------------
# Generate RTA signal xml file
#------------------------------	
if analyse_rta and local_env['variant'] == "release":
    try:
        rta_target_algo_name
    except NameError,e:
        exception_warning(e,exception_handler,"hence component_name is used as rta_target_algo_name")
        rta_target_algo_name = component_name

    if algo_name == rta_target_algo_name:
    	# Action to read RTA signals from header file
        local_env['BUILDERS']['readSignalRTA'] = Builder(action = read_rta_signal)
        xmlFileName = "RTA_ID_" + component_name.upper() + ".xml"
        try:
            xmlDestinationPath
        except NameError,e:
            exception_warning(e,exception_handler,"in sim_swc_config.scfg")
            xmlDestinationPath = deliverables_path_from_sconstruct + "cfg/algo/" + component_name
        xmlPath = Dir(xmlDestinationPath).abspath
        try:
            actionReadRTA = local_env.readSignalRTA([xmlFileName], sourceList)
            actionReadRTA += env.Install([xmlPath], actionReadRTA)
		
            # Generate aliases containing the variant's name
            Alias(rta_target_algo_name + "_" + scons_target_name + "_" + env['variant'], actionReadRTA)
            Alias(rta_target_algo_name + "_sim_pc_" + env['variant'], actionReadRTA)
            Alias(rta_target_algo_name + "_sim_" + env['variant'], actionReadRTA)
            Alias("all_" + env["variant"], actionReadRTA)
            if algo_name != component_name:
                Alias(component_name + '_' + scons_target_name + "_" + env['variant'], actionReadRTA)
                Alias(component_name + "_sim_pc_" + env['variant'], actionReadRTA)
                Alias(component_name + "_sim_" + env['variant'], actionReadRTA)
                        					
            # Generate aliases NOT containing the variant's name
            Alias(rta_target_algo_name + "_" + scons_target_name, actionReadRTA)
            Alias(rta_target_algo_name + "_sim_pc", actionReadRTA)
            Alias(rta_target_algo_name + "_sim", actionReadRTA)
            Alias("all", actionReadRTA)
            if algo_name != component_name:
                Alias(component_name + "_" + scons_target_name, actionReadRTA)
                Alias(component_name + "_sim_pc", actionReadRTA)
                Alias(component_name + "_sim", actionReadRTA)

        except NameError,e:
            exception_warning(e,exception_handler,"in sim_swc_config.scfg hence RTA signal xml doc cannot be generated")
					   
#-------------------------
# build DLL
#-------------------------
lib = local_env.SharedLibrary(target, src)

#-------------------------
# return result
#-------------------------

# get absolute file path
cpp_src = abspath_filenames(src)

# get absolute include path
cpp_path = map(lambda x: str(Dir(x).srcnode().abspath), cpp_path)

# get libpath
lib_path = local_env["LIBPATH"]

# get defines
cppdefs = local_env["CPPDEFINES"]

if profile:
    FinishSconscriptEntry() 

# return library, source files and include paths
Return(["lib", "cpp_src", "cpp_path", "lib_path", "cppdefs"])