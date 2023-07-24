"""
Filename                  :  scons_adas_extensions\polyspace.py
Description               :  Script that controls the generation of Polyspace Projects.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: Polyspace.py
#
# DESCRIPTION: Script that controls the generation of Polyspace Projects.
#
# INITIAL AUTHOR: Lenin.Palanisamy-EXT (uidr0826)
#
# CREATION DATE: 2015/05/18
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:59CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: polyspace.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:59CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.9 2017/05/30 11:24:29CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.8 2017/04/27 16:00:02CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.7 2016/11/30 10:14:34CET Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for Polyspace 2016a
# CHANGES:                   Revision 1.6 2016/06/08 06:01:59CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Updated to resolve the issue 464422
# CHANGES:                   Revision 1.5 2016/05/27 11:59:29CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.4 2016/03/25 08:16:18CET Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Polyspace integration for all cores C66xx, ARP32, A15, A8, M3 and M4
# CHANGES:                   Revision 1.3 2015/07/31 12:06:19CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Improvement on polyspace project creation based on version. Updated module path and exception handling
# CHANGES:                   - Added comments -  uidr0826 [Jul 31, 2015 12:06:20 PM CEST]
# CHANGES:                   Change Package : 362983:1 http://mks-psad:7002/im/viewissue?selection=362983
# CHANGES:                   Revision 1.2 2015/06/04 07:19:31CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Initial polyspace integration with c674x
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 4, 2015 7:19:31 AM CEST]
# CHANGES:                   Change Package : 344851:1 http://mks-psad:7002/im/viewissue?selection=344851
# CHANGES:                   Revision 1.1 2015/06/03 13:04:54CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/SCT_Sconstools/scons_adas_extensions/project.pj

#***************************************************************************************************


#---------------------
# Imports
#---------------------

import sys, os, errno, re, shutil, stat
import time
from SCons.Script import *
from xml.dom.minidom import Document

execfile(File("#../GSCons_project_config.scfg").abspath)
modtest_dir = testing_path_from_sconstruct + "05_Test_Environment/algo/modtests"
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)
  

def _WriteXmlToProjectFile(xmlDoc, fileName):
    """
    Function              :  _WriteXmlToProjectFile
    Description           :  Writes the given XML document to the given file.
    xmlDoc                :  Reference of XML document object
    fileName              :  Polyspace project file name.
    Returns               :  Returns false
    """
    projectFile = open(fileName, 'w+')

    # The standard prettyprintting provided by xmlDoc.toprettyxml(), eg:
    #
    #     <dictionary>
    #         <key>
    #             org.eclipse.cdt.make.core.enableFullBuild
    #         </key>
    #         <value>
    #             true
    #         </value>
    #     </dictionary>
    #
    # does not appear to get on with Eclipse very well - strange things
    # happen like not being able to clean the current project by right
    # clicking on the project in the browser and selecting clean.
    #
    # However, the following style appears to work better:
    # 
    #     <dictionary>
    #         <key>org.eclipse.cdt.make.core.enableFullBuild</key>
    #         <value>true</value>
    #     </dictionary>
    #
    # Unforunately the regex below doesn't maintain indentation - TBD!

    out = xmlDoc.toprettyxml(indent="  ", encoding="UTF-8")
    niceOut = re.sub(r'><', r'><', re.sub(r'(<\/.*?>)', r'\1', out))
    projectFile.write(niceOut)
    projectFile.close()
    return 0


def _WritePolyspaceProjectFile(ps_name,
                         author,
						 ps_module_data,
                         target_options,
						 destination_dir, ps_version, filename):

    """
    Function                        :  _WritePolyspaceProjectFile
    Description                     :  1.) Writes project data to XML document
                                       2.) Writes this XML document to project file.
    ps_name                         :  Polyspace project name
    author                          :  Author of project file (here "Generic SCons")
    ps_module_data                  :  Module source list, include list, macro list
    target_options                  :  Polyspace target options
    destination_dir                 :  Destination directory for project 
    ps_version                      :  Polyspace project version used
    filename                        :  Polyspace project file name
    Returns                         :  Returns false
    """
	# Create XML content for a Polyspace project
    xmlPSPrjDoc = create_polyspace_project(ps_name,
                         author,
						 ps_module_data,
                         target_options,
						 destination_dir, ps_version, filename)

    # write xml-content to project file
    _WriteXmlToProjectFile(xmlPSPrjDoc, filename)
    temp_file = destination_dir + "/" + ps_name + "_temp.txt"
    delete_temp_file(temp_file)
	
    return 0
    
########################################################
# Actions
# SCons actions created for the _WriteXmlToProjectFile
# function.
########################################################

WriteXmlToProjectFile = \
    SCons.Action.ActionFactory(_WriteXmlToProjectFile,
                               lambda xmlDoc, fileName:
                               'Writing XML to %s' % fileName)							   
	
WritePolyspaceProjectFile = \
    SCons.Action.ActionFactory(_WritePolyspaceProjectFile, 
	                           lambda ps_name, author, ps_module_data, target_options, destination_dir, ps_version,
                               fileName: 'Writing XML to %s' % fileName)
	
							   
							   
def setAttributes(node, attrs):
    """
    Function           :  setAttributes
    Description        :  Sets attributes for the given XML node.
    node               :  Reference of XML node
    attrs              :  Attributes to be set
    Returns            :  None
    """
    for key, value in attrs.items():
        node.setAttribute(key, value)

							   
def addXMLValue(doc, parent, tag, value = None):
    """
    Function            :  addXMLValue
    Description         :  Method to add the given XML tag, value pair to the project file, under the given parent.
    doc                 :  Reference of XML document object
    parent              :  Reference of parent tag
    tag                 :  XML tag to be added
    value               :  Value to be added if any
    Returns             :  Returns added element object
    """
    element = doc.createElement(tag)
    if (value):
        if type(value) == type(str()):
            element.appendChild(doc.createTextNode(value))
        elif type(value) == type(dict()):
            setAttributes(element, value)
    parent.appendChild(element)
    return element

def create_option_set(doc,
                      module_parent,
					  option_set_name,
					  option_include_list,
					  macro_list,
					  target_options, ps_version):


    """
    Function                        :  create_option_set
    Description                     :  Method to create module set part of Polyspace project
    doc                             :  Reference of XML document object
    module_parent                   :  Reference of module parent tag
    option_set_name                 :  Name for option set as per guideline
    option_include_list             :  List of include paths in tag "optionset"
    macro_list                      :  List of cc defines
    target_options                  :  Polyspace target options
    ps_version                      :  Polyspace project version used
    Returns                         :  Returns option_set_tag object
    """

    # Create options into option set
    option_set_tag = addXMLValue(doc, module_parent, 'optionset', {'name': option_set_name, 'isactive': "true"})

    # Polyspace excel export option depends on version
    if ps_version == "2016a":
        excel = "-excel-with-rte"
        option_item = addXMLValue(doc, option_set_tag, 'option', {'flagname': "-lang"})
        option_content = doc.createTextNode("CPP")
        option_item.appendChild(option_content)

    option_item = addXMLValue(doc, option_set_tag, 'option', {'flagname': "*_other"})
    option_content = doc.createTextNode(excel)
    option_item.appendChild(option_content)

    # Create macro list ("-D") into into module set
    macro_tag = addXMLValue(doc, option_set_tag, 'option', {'flagname': "-D"})
    for macro_item in macro_list:
        element = addXMLValue(doc, macro_tag, 'element', macro_item)
	
    # Create include list ("-I") into into module set
    inc_tag = addXMLValue(doc, option_set_tag, 'option', {'flagname': "-I"})
    option_include_list = [inc.strip().replace("\\","/") for inc in option_include_list]
    for inc_item in option_include_list:
        element = addXMLValue(doc, inc_tag, 'element', "file:/" + inc_item)

    for key in target_options:
        option_item = addXMLValue(doc, option_set_tag, 'option', {"flagname" : key})
        option_content = doc.createTextNode(target_options[key])
        option_item.appendChild(option_content)

    return option_set_tag
	
def create_module_set(doc,
                      ps_prj_parent,
					  module_name,
					  module_path,
					  module_source_list,
					  ps_version):


    """
    Function                        :  create_module_set
    Description                     :  Method to create module set part of Polyspace project
    doc                             :  Reference of XML document object
    ps_prj_parent                   :  Reference of parent tag of XML document object
    module_name                     :  Name for module as per guideline
    module_path                     :  Module absolute path
    module_source_list              :  List of module source files
    option_include_list             :  List of include paths in tag "optionset"
    ps_version                      :  Polyspace project version used
    Returns                         :  Returns module_parent object
    """
	# create module set in polyspace project
    module_parent = addXMLValue(doc, ps_prj_parent, 'module', {'name': module_name, 'path': "file:/" + module_path.replace("\\","/"), 'isactive': "true" })

    module_source_list = [src.strip().replace("\\","/") for src in module_source_list]
    # Create source list into module set
    src_tag = addXMLValue(doc, module_parent, 'source')
    for src_item in module_source_list:
        addXMLValue(doc, src_tag, 'file', {'path': "file:/" + src_item})

    return module_parent

def remove_duplicates(list_with_duplicate):
    """
    Function                        :  remove_duplicates
    Description                     :  Method to create module set part of Polyspace project
    list_with_duplicate             :  Reference of XML document object
    Returns                         :  None
    """

    duplicates_removed = []
    for list_item in list_with_duplicate:
        if list_item not in duplicates_removed:
            duplicates_removed.append(list_item)

    return duplicates_removed
		
def get_all_source_include_list(ps_module_data):
    """
    Function                        :  get_all_source_include_list
    Description                     :  Method to create module set part of Polyspace project
    ps_module_data                  :  Module source list, include list, macro list
    """

    all_sources = []
    all_includes = []
    for arch in ps_module_data.keys():
        source_list = ps_module_data[arch][0]
        include_list = ps_module_data[arch][1]
        src_abs = map(lambda x: os.path.abspath(x), Split(source_list))
        inc_abs = map(lambda x: os.path.abspath(x), Split(include_list))
        all_sources = all_sources + src_abs
        all_includes = all_includes + inc_abs

    all_sources = [src.strip().replace("\\","/") for src in all_sources]
    all_includes = [inc.strip().replace("\\","/") for inc in all_includes]
	
    src_duplicates_removed = remove_duplicates(all_sources)
    inc_duplicates_removed = remove_duplicates(all_includes)

    # get only cpp files
    cpp_source_files = [elem for elem in src_duplicates_removed if elem.endswith(".cpp")]
    # get only c files
    c_source_files = [elem for elem in src_duplicates_removed if elem.endswith(".c")]	

    return cpp_source_files, c_source_files, inc_duplicates_removed 	


def delete_temp_file(filename):
    try:
        os.remove(filename)
    except OSError:
        pass	

def get_core_macro_include_list(cc_define_include_file):
    """
    Function                        :  get_core_macro_include_list
    Description                     :  Method to get the list of macros and include list
    cc_define_include_file          :  filename which contains preproc_macros output
    Returns                         :  Returns list of cc_defines and additional includes
    """

    file = open(cc_define_include_file, 'r')
    file_line = file.readlines()
    list_cc_defines = []
    list_include_path = []
    for count in range(len(file_line)):
        line = file_line[count]
        if ("/* Predefined */" in line ):
            if ("__DATE__" not in line and "__TIME__" not in line):
                str1=''
                line = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,line) 
                line_content_list = re.split('\s', line)
                for i in range(len(line_content_list)):
                    if i == 1:
                        str1 += line_content_list[i]
                        str1 += "="
                    elif line_content_list[i] != "" and i != 0:
                        str1 += " " + line_content_list[i]
                list_cc_defines.append(str1)
            
        else:
            comments = re.findall("/\*.*?\*/", line)
            line_content_list = re.split('\s', ''.join(comments))
            for count1 in range(len(line_content_list)):
                if ("/*" in line_content_list[count1]):
                    if "\\" in line_content_list[count1+1]:
                        new = line_content_list[count1+1].rfind("\\")
                        new_string = line_content_list[count1+1][:new]
                    else:
                        new_string = line_content_list[count1+1]                    
                    abspath = os.path.abspath(new_string)                
                    if abspath not in list_include_path:
                        list_include_path.append(abspath)

    #print "\n file name \n", cc_define_include_file
    #print "\n===================== MACRO ==================\n", list_cc_defines, "\n===================== MACRO ==================\n"
    #print "===================== INCLUDE PATH ==================\n", list_include_path, "\n===================== INCLUDE PATH ==================\n"
    file.close()
    delete_temp_file(cc_define_include_file)
	
    return list_cc_defines, list_include_path

	
def get_A8A15_macro_include_list(cc_define_file):
    """
    Function                        :  get_A8A15_macro_include_list
    Description                     :  Method to get the list of macros and include list
    cc_define_file                  :  filename which contains preproc_macros output
    Returns                         :  Returns list of cc_defines and additional includes
    """

    file = open(cc_define_file, 'r')
    file_line = file.readlines()
    list_cc_defines = []
    for count in range(len(file_line)):
        line = file_line[count]
        if ("#define " in line ):
            if ("__DATE__" not in line and "__TIME__" not in line):
                str1=''
                line = re.sub(re.compile("#define",re.DOTALL ) ,"" ,line) 
                line_content_list = re.split('\s', line)
                for i in range(len(line_content_list)):
                    if i == 1:
                        str1 += line_content_list[i]
                        str1 += "="
                    elif line_content_list[i] != "" and i != 0:
                        str1 += " " + line_content_list[i]
                list_cc_defines.append(str1)
            
    file.close()
    #print "\n file name \n", cc_define_file
    delete_temp_file(cc_define_file)
    #print "\n===================== MACRO ==================\n", list_cc_defines, "\n===================== MACRO ==================\n"
    
    return list_cc_defines


def add_main_source_include_list(doc,
                      ps_prj_parent,
                      ps_module_data):
    """
    Function                        :  add_main_source_include_list
    Description                     :  Method to create module set part of Polyspace project
    doc                             :  Reference of XML document object
    ps_prj_parent                   :  Reference of parent tag of XML document object
    ps_module_data                  :  Module source list, include list, macro list
    Returns                         :  None
    """

    cpp_files, c_files, all_includes  = get_all_source_include_list(ps_module_data)

    # Create source list into polyspace project
    src_tag = addXMLValue(doc, ps_prj_parent, 'source')
    for src_item in cpp_files + c_files:
        addXMLValue(doc, src_tag, 'file', {'path': "file:/" + src_item})

    # Create include list into polyspace project
    inc_tag = addXMLValue(doc, ps_prj_parent, 'include')
    for inc_item in all_includes:
        addXMLValue(doc, inc_tag, 'file', {'path': "file:/" + inc_item, 'order': str(all_includes.index(inc_item))})

    return cpp_files, c_files, all_includes

def set_polyspace_project_attributes(ps_prj_parent,
                      ps_name,
                      author,
                      ps_version,
                      filename):


    """
    Function                        :  set_polyspace_project_attributes
    Description                     :  Method to create module set part of Polyspace project
    doc                             :  Reference of XML document object
    ps_prj_parent                   :  Reference of parent tag of XML document object
    module_name                     :  Name for module as per guideline
    module_path                     :  Module absolute path
    module_source_list              :  List of module source files
    option_include_list             :  List of include paths in tag "optionset"
    macro_list                      :  List of macros
    target_options                  :  Polyspace target options
    ps_version                      :  Polyspace project version used
    Returns                         :  None
    """

    filename = filename.replace("\\","/")
    # Set Polyspace attributes depends on version
    if ps_version == "2016a":
        rev = "1.6"
        setAttributes(ps_prj_parent, {'name': ps_name, 'product': "Polyspace Code Prover", 'author': author, 'version': "1.0", 'date': time.strftime("%d/%m/%Y"), 'path': "file:/" + filename, 'source': "Code Prover", 'rev': rev })



def create_polyspace_project(ps_name,
                         author,
						 ps_module_data,
                         target_options,
						 destination_dir, ps_version, filename):

    """
    Function                        :  create_polyspace_project
    Description                     :  Method to create a polyspace (C/CPP) project
    ps_name                         :  Polyspace project name
    language                        :  Selected language 
    author                          :  Author of project file (here "Generic SCons")
    ps_module_data                  :  Module source list, include list, macro list
    target_options                  :  Polyspace target options
    result_path                     :  Result path 
    ps_version                      :  Polyspace project version used
    filename                        :  Polyspace project file name
    Returns                         :  returns generated XML document object
    """
	# create XML document
    doc = Document()

	# Create polyspace project and it's attributes
    ps_prj_parent = doc.createElement('polyspace_project')

    # Set Polyspace attributes depends on version
    set_polyspace_project_attributes(ps_prj_parent, ps_name, author, ps_version, filename)

    # Create main source list and include list into polyspace project
    cpp_files, c_files, all_includes = add_main_source_include_list(doc, ps_prj_parent, ps_module_data)
    
    if ps_version == "2016a":
        module_name = "AllFiles"
        module_source_list = cpp_files + c_files
        module_include_list = all_includes

    module_path = destination_dir + "/" + module_name + "/"
	
    result_path = module_path + "Result/"
    if not os.path.exists(result_path):
        os.makedirs(result_path)

    # Create module set tags into polyspace project
    module_parent = create_module_set(doc, ps_prj_parent, module_name, module_path, module_source_list, ps_version)
    for arch in ps_module_data.keys():
        option_include_list = module_include_list
        macro_list = ps_module_data[arch][2]
        cc_defines_includes_file = ps_module_data[arch][3]

        if ps_module_data[arch][4] != None:
            list_cc_defines = get_A8A15_macro_include_list(cc_defines_includes_file)
            list_include_path = ps_module_data[arch][4]
        else:
            list_cc_defines, list_include_path = get_core_macro_include_list(cc_defines_includes_file)

        list_include_path = [inc.strip().replace("\\","/") for inc in list_include_path]
        inc_duplicates_removed = remove_duplicates(option_include_list + list_include_path)
        defines_duplicates_removed = remove_duplicates(list_cc_defines + macro_list)
		# Set module attributes depends on version
        option_name = "OfficialRelease_" + arch.upper()
        # Create option set tags into polyspace project
        option_set_parent = create_option_set(doc, module_parent, option_name, inc_duplicates_removed, defines_duplicates_removed, target_options, ps_version)

    # Create result path tag into polyspace project	
    result_parent = addXMLValue(doc, ps_prj_parent, 'result')
    addXMLValue(doc, result_parent, 'file', {'path': "file:/" + result_path.replace("\\","/"), 'isactive': "true"})
	
    doc.appendChild(ps_prj_parent)	
	
    return doc	

def generate_ps2016_proj(self,
                ps_module_data,
                target_options,
                ps_version, ps_prj_name,
                *args,
                **kw):

    """
    Function                        :  generate_ps2016_proj
    Description                     :  Environment method to generate polyspace project (C/CPP) file(s)
    ps_module_data                  :  Module source list, include list, macro list
    target_options                  :  Polyspace target options
    ps_version                      :  Polyspace project version used
    ps_prj_name                     :  Polyspace project file name
    *args                           :  Reference of object arguments 
    **kw                            :  
    Returns                         :  returns list of generated polyspace project file(s)
    """
    # List the dependencies of the polyspace project files
    list_depend = source_code_path_from_sconstruct + self['COMPONENT'] + "/algo_lib_file_list.scfg"
    config_depend = source_code_path_from_sconstruct + self['COMPONENT'] + "/algo_config.scfg"
    ps_depend	= [list_depend, config_depend]
    	
    # construct the polyspace project files
    component_name = self['COMPONENT']
    if self['COMPONENT'] != self['ALGO']:
        component_name = self['COMPONENT'] + "_" + self['ALGO']

    component_name = component_name.upper()	
    
    # Author of the polyspace project file
    author = self['ENV']['PS_PROJ_AUTHOR']

    destination_dir = self['ENV']['PATH_PS2016_PROJ']
    ps_name = component_name

    projectTarget = Command(ps_prj_name,
                         ps_depend,
                         WritePolyspaceProjectFile(ps_name,
                                           author,
                                           ps_module_data,
                                           target_options, 
                                           destination_dir, 
                                           ps_version,
                                           ps_prj_name
                                           ))		

    ps_project = []
    ps_project.append(projectTarget)

    # return ps_project as [Polyspace 2016 project file]
    return ps_project

def generate_PS_MACRO(self, source, target):

    #print "========SDMACRO =============  ", self['SDMACRO']
    #print "\n========source, target ============= ", source, target
		
    PS_Return = self.PSMACROS(source, target)

    return 	PS_Return

def generate_PS_INCLUDE(self, source, target):

    #print "========SDINCLUDE ============= ", self['SDINCLUDE']
		
    PS_Return = self.PSINCLUDES(source, target)


	
    return 	PS_Return	
	
	
	
def generate(env): 
    """
    Function        :  generate
    Description     :  Define the Builders and construction variables for Polyspace environment for generating polyspace projects
    env             :  Environment for Polyspace project file generation
    Returns         :  None
    """
    # setup Builder device for generating files for Polyspace 
    env.AddMethod(generate_ps2016_proj, "generate_ps2016_proj")
    env.AddMethod(generate_PS_MACRO, "generate_PS_MACRO")
    env.AddMethod(generate_PS_INCLUDE, "generate_PS_INCLUDE")		
	
	# ----------------------------------------	
	# Prepare directory paths
	# ----------------------------------------	
    # Polyspace 2016a test path
    ps2016_test_dir = os.path.join(modtest_dir, "polyspace", env['ALGO'])
    src_tests_dir_abs = os.path.join(Dir(ps2016_test_dir).abspath)

    env['ENV']['PATH_PS2016_PROJ'] = src_tests_dir_abs		
    env['ENV']['PS_PROJ_AUTHOR'] = "GenericSCons"		
    env['ENV']['PS2016a_PROJ_EXT'] = '.psprj'
	
    env['_ARM_GCC_CODE_GEN_TOOL_PATH'] = Dir(env.subst('$ARM_GCC_CODE_GEN_TOOL_PATH')).abspath	
    env.PrependENVPath('PATH', env.subst("$_ARM_GCC_CODE_GEN_TOOL_PATH/bin"))	
    env['CC'] = 'arm-none-eabi-gcc'


    env['SDMACRO'] = " -E -dM "
    env['DMACRO']       = '$CC $SDMACRO $SOURCE > $TARGET'
    env['DMACROSTR']       = '$DMACRO'
	
    env['SDINCLUDE'] = " -E -dI "
    env['DINCLUDE']       = '$CC $SDINCLUDE $SOURCE >> $TARGET'
    env['DINCLUDESTR']       = '$DINCLUDE'	
	
    env['DINCLUDES']       = '$CC $CFLAGS'
    env['ARMDINCLUDES']       = '$DINCLUDES'	


    #action_list_c = [SCons.Action.Action( '$DMACRO', '$ARMDMACRO')]
    #PSDEFINEBld = SCons.Builder.Builder(action = action_list_c)
    PSDEFINEBld	= Builder(action = Action('$DMACRO', '$DMACROSTR'))						   
	
    PSINCLUDEBld	= Builder(action = Action('$DINCLUDE', '$DINCLUDESTR'))			
										   
    #action_list_cpp = [SCons.Action.Action( '$DINCLUDES', '$ARMDINCLUDES')]	
    #PSINCLUDEBld = SCons.Builder.Builder(action = action_list_cpp,
     #                                      src_builder = 'StaticObject')										   
										   
	
    env['BUILDERS']['PSMACROS'] = PSDEFINEBld
    env['BUILDERS']['PSINCLUDES'] = PSINCLUDEBld	

	
def exists(env):
    """
    Function        :  exists
    Description     :  Methods to get that polyspace environment exists
    env             :  Environment for Polyspace project file generation 
    Returns         :  returns the environment exists
    """
    return 1