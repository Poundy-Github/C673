"""
Filename                  :  scons_adas_extensions\qac.py
Description               :  Script that controls the generation of QAC analysis and reports.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: qac.py
#
# DESCRIPTION: Script that controls the generation of QAC analysis and reports.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/10/09
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:59CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: qac.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:59CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.36 2017/05/30 11:26:24CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.35 2017/04/27 15:55:43CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.34 2016/05/27 12:03:03CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.33 2016/01/21 07:26:55CET Singh, Vishal (uidj9083) 
# CHANGES:                   Single file analysis is working with visual studio, updated qac.py
# CHANGES:                   Revision 1.32 2015/11/19 11:57:04CET Singh, Vishal (uidj9083) 
# CHANGES:                   Updated scons_adas_extensions\qac.py for generating correct .prj for EM
# CHANGES:                   Revision 1.31 2015/11/05 12:09:47CET Singh, Vishal (uidj9083) 
# CHANGES:                   Modified after Jenkin Server no_target test
# CHANGES:                   --- Added comments ---  uidj9083 [Nov 5, 2015 12:09:48 PM CET]
# CHANGES:                   Change Package : 393389:1 http://mks-psad:7002/im/viewissue?selection=393389
# CHANGES:                   Revision 1.30 2015/11/05 08:40:51CET Singh, Vishal (uidj9083) 
# CHANGES:                   updated file for issue QAC on arp32: generated header files (from .k files) are not found by QAC
# CHANGES:                   and issue QAC analysis results for the files is missing for QAC GUI, in current QAC analysis implementation in GSCons
# CHANGES:                   --- Added comments ---  uidj9083 [Nov 5, 2015 8:40:51 AM CET]
# CHANGES:                   Change Package : 393389:1 http://mks-psad:7002/im/viewissue?selection=393389
# CHANGES:                   Revision 1.29 2015/08/04 05:59:30CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Modified scons_adas_extensions\qac.py and scons_common_scripts\algo\lib\SConscript.py in GenericScons to make QAC build fully constructed based on the source-generates-target paradigm and to support multi-threading for QAC targets
# CHANGES:                   --- Added comments ---  uidj9083 [Aug 4, 2015 5:59:31 AM CEST]
# CHANGES:                   Change Package : 361687:1 http://mks-psad:7002/im/viewissue?selection=361687
# CHANGES:                   Revision 1.28 2015/08/03 14:07:30CEST Singh-EXT, Vishal (uidj9083) 
# CHANGES:                   Modified scons_adas_extensions\qac.py and scons_common_scripts\algo\lib\SConscript.py in GenericScons to make QAC build fully constructed based on the source-generates-target paradigm and to support multi-threading for QAC targets
# CHANGES:                   --- Added comments ---  uidj9083 [Aug 3, 2015 2:07:30 PM CEST]
# CHANGES:                   Change Package : 361687:1 http://mks-psad:7002/im/viewissue?selection=361687
# CHANGES:                   Revision 1.27 2015/06/26 05:17:25CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:25 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

#---------------------
# Imports
#---------------------

import os, errno, re, shutil, stat, fnmatch
from SCons.Script import *

import SCons.Tool
import SCons.Tool.cc
import SCons.Tool.link
import SCons.Scanner
import SCons.Util
import re, os.path, string, errno
cplusplus = __import__('SCons.Tool.cpp', globals(), locals(), ["SCons.Tool"])

execfile(File("#../GSCons_project_config.scfg").abspath)
modtest_dir = testing_path_from_sconstruct + "05_Test_Environment/algo/modtests"
Analysis_dir = build_path_from_sconstruct + "algo"
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)


# read text file and return the content of the file
def ReadTextFile(file_name, return_list=False):
    """
    Function                 :  ReadTextFile
    Description              :  
    file_name                :  
    return_list              :  
    Returns                  :  
    """
    try:
        f = open(os.path.abspath(file_name), "r")
        if return_list == True:
            file_content = f.readlines()
        else:
            file_content = f.read()
        f.close()
        return file_content
    except IOError:
        print "Error: can\'t find template file or read data"
    except:
        print "Error: Unexpected error"
        
def _WriteTextFile(target_dir, file_name, content):
    """
    Function               :  _WriteTextFile
    Description            :  
    target_dir             :  
    file_name              :  
    content                :  
    Returns                :  
    """
    f = open(File(os.path.join(target_dir, file_name)).abspath, "w+")
    f.write(content)
    f.close()

WriteTextFile = \
    SCons.Action.ActionFactory(_WriteTextFile,
                               lambda target_dir, file_name, content:
                               "Writing file %s to %s" % (file_name, target_dir))
    
def generate_files(env, destination_dir, report_destination_dir,sources, includes, defines, source_type, component_name, algo_name, source_code_dir, personalities_file, qac_mode):
    """
    Function                            :  generate_files
    Description                         :  
    env                                 :  
    destination_dir                     :  
    report_destination_dir              :  
    sources                             :  
    includes                            :  
    defines                             :  
    source_type                         :  
    component_name                      :  
    algo_name                           :  
    source_code_dir                     :  
    personalities_file                  :  
    qac_mode                            :  
    Returns                             :  
    """
    # make sure that the destination directory exists
    try:
        os.makedirs(Dir(destination_dir).abspath)
        os.makedirs(Dir(report_destination_dir).abspath)		
    except OSError, e:
        if e.errno != errno.EEXIST:
            raise
    
    # -------------------
    # initial definitions of paths/files
    # -------------------    
    source_code_dir_path = "#../../../" + source_code_dir + "/" + component_name + "/"
    source_code_dir_rel_path = "algo"	
    algo_lib_file_list = File(source_code_dir_path + "algo_lib_file_list.scfg").abspath
    algo_config = File(source_code_dir_path + "algo_config.scfg").abspath
    qac_depend = [algo_lib_file_list, algo_config]
    
    if source_type == "c":
        qac_tests_dir = os.path.join(modtest_dir, "qac_tests")
    else:
        qac_tests_dir = os.path.join(modtest_dir, "qacpp_tests")
        # use the compiler personality file for cpp
        personalities_file = personalities_file[:personalities_file.find(".p_c")] + "_" + source_type.upper() + personalities_file[personalities_file.find(".p_c"):]
			
    template_dir = os.path.join(qac_tests_dir, "common/qac_python_tools")
    algo_qac_dir = os.path.join(qac_tests_dir, algo_name)
 
    # -------------------
    # define project file names
    # ------------------- 
    if qac_mode == "file":
        prj_file_name = algo_name.upper() + "_" + source_type.upper() + "_" + env["_BUILD_TARGET"].lower() + "_debug.prj"
        env['QAC_PROJECT_TEMPLATE_FILE_NAME'] = prj_file_name		
        pa_file_name = algo_name.upper() + "_AnalyserPers_" + source_type.upper() + "_" + env["_BUILD_TARGET"].lower() + "_debug.p_a"
        filelist_name = "filelist_" + env["_BUILD_TARGET"].lower() + "_debug.lst"
        settings_name = "settings" + "_" + env["_BUILD_TARGET"].lower() + "_debug.via"
    else:
        prj_file_name = algo_name.upper() + "_" + source_type.upper() + "_" + env["_BUILD_TARGET"].lower() + ".prj"
        env['QAC_PROJECT_TEMPLATE_FILE_NAME'] = prj_file_name		
        pa_file_name = algo_name.upper() + "_AnalyserPers_" + source_type.upper() + "_" + env["_BUILD_TARGET"].lower() + ".p_a"
        filelist_name = "filelist_" + env["_BUILD_TARGET"].lower() + ".lst"
        settings_name = "settings" + "_" + env["_BUILD_TARGET"].lower() + ".via"
	
    # -------------------
    # create QAC prj file
    # -------------------
    # read prj template file
    qac_scons_prj_template_src = os.path.join(template_dir, "QAC_scons_prj_template.txt")
    qac_prj_template_src = os.path.join(template_dir, "QAC_prj_template.txt")
    if os.path.isfile(File(qac_scons_prj_template_src).abspath):
        qac_scons_prj_template = ReadTextFile(File(qac_scons_prj_template_src).abspath, False)
        output_path = '.\\..\\' + algo_name + '\\output'
    elif os.path.isfile(File(qac_prj_template_src).abspath):
        qac_prj_template = ReadTextFile(File(qac_prj_template_src).abspath, False)
    else:
        print "Error: prj template is not found"
        print "No QA%s project is generated!!" %source_type.upper()
        # Usage of Command in order to display a build error at build time
        qac_prj = Command(destination_dir + "/" + prj_file_name, File(qac_prj_template_src).abspath, "$SOURCE")
        return [qac_prj]
        
    # get source files with relative paths    
    # get information on which analyzer personality to be used
    if qac_mode == "project":
        p_a_path = './../' + algo_name + '/' + algo_name.upper()
        p_a_addon = source_type.upper() + "_" + env["_BUILD_TARGET"].lower()
    elif qac_mode == "file":
        p_a_path = './../' + algo_name + '_debug/' + algo_name.upper()
        p_a_addon = source_type.upper() + "_" + env["_BUILD_TARGET"].lower() + "_debug"
	
    new_prj_content = []							   
    def recursive_function(folder_name, source_list, previous_folder):
        """
        Function                     :  recursive_function
        Description                  :  
        folder_name                  :  
        source_list                  :  
        previous_folder              :  
        Returns                      :  
        """
        recursive_level_dir = []
        end_of_loop = 1
        for x in source_list:
            head, sep, tail = x.partition('\\'+folder_name+'\\')				
            if "\\" not in tail:
                head_content, sep_content, tail_content = x.partition("04_Engineering")			
                new_prj_content.append(".\\..\\..\\..\\..\\..\\..\\04_Engineering"+tail_content)			
            else:		
                head, sep, tail = x.partition('\\'+folder_name+'\\')
                head, sep, tail = tail.partition('\\')				
                if head not in recursive_level_dir:
                    head, sep, tail = head.partition('\\')				
                    recursive_level_dir.append(head)
                recursive_level_dir.sort()
                previous_folder = folder_name				
                end_of_loop = 0	
        new_prj_content.append("EndContainedFilesMarker")
        
        if end_of_loop == 0:		
            for x in recursive_level_dir:				
                if previous_folder == folder_name:		
                    new_prj_content.append("StartSubProjectMarker")
                    new_prj_content.append("StartProjectMarker")
                    new_prj_content.append("FolderName="+x)
                    source_output_dir = []
                    for z in source_list:
                        if "\\"+x+"\\" in z:
                            source_output_dir = z
                            break							
                    head, sep, tail = source_output_dir.partition("\\algo"+'\\')
                    head, sep, tail = tail.partition("\\"+x+"\\")			
                    if head == "":
                        new_prj_content.append("SourcePath=.\\..\\..\\..\\..\\..\\..\\04_Engineering\\01_Source_Code\\algo\\"+x)
                        new_prj_content.append("OutputPath=.\..\..\..\..\..\..\\04_Engineering\\04_Build\\algo\\"+algo_name.lower()+"_qa"+source_type.lower()+"\\"+env["_BUILD_TARGET"].lower()+"\\01_Source_Code\\algo\\"+x)						
                    else:
                        new_prj_content.append("SourcePath=.\\..\\..\\..\\..\\..\\..\\04_Engineering\\01_Source_Code\\algo\\"+head+"\\"+x)
                        new_prj_content.append("OutputPath=.\..\..\..\..\..\..\\04_Engineering\\04_Build\\algo\\"+algo_name.lower()+"_qa"+source_type.lower()+"\\"+env["_BUILD_TARGET"].lower()+"\\01_Source_Code\\algo\\"+head+"\\"+x)
                    new_prj_content.append("SubsPers=.\..\common\MessagePers\ADAS_"+source_type.upper()+".p_s")
                    new_prj_content.append("AnalPers="+p_a_path+"_AnalyserPers_"+p_a_addon+".p_a")
                    new_prj_content.append("CompPers="+personalities_file)
                    second_level_uniquie_dir = []
                    for y in source_list:		
                        if "\\04_Engineering\\01_Source_Code\\algo\\"+head+"\\"+x+"\\" in y:
                            second_level_uniquie_dir.append(y)
                    folder_name = x					
                    recursive_function(x, second_level_uniquie_dir, previous_folder)					
                else:
                    new_prj_content.append("StartProjectMarker")
                    new_prj_content.append("FolderName="+x)
                    for z in source_list:
                        if "\\"+x+"\\" in z:
                            source_output_dir = z
                            break							
                    head, sep, tail = source_output_dir.partition("\\algo"+'\\')					
                    head, sep, tail = tail.partition("\\"+x+"\\")					
                    if head == "":
                        new_prj_content.append("SourcePath=.\\..\\..\\..\\..\\..\\..\\04_Engineering\\01_Source_Code\\algo\\"+x)
                        new_prj_content.append("OutputPath=.\..\..\..\..\..\..\\04_Engineering\\04_Build\\algo\\"+algo_name.lower()+"_qa"+source_type.lower()+"\\"+env["_BUILD_TARGET"].lower()+"\\01_Source_Code\\algo\\"+x)						
                    else:
                        new_prj_content.append("SourcePath=.\\..\\..\\..\\..\\..\\..\\04_Engineering\\01_Source_Code\\algo\\"+head+"\\"+x)
                        new_prj_content.append("OutputPath=.\..\..\..\..\..\..\\04_Engineering\\04_Build\\algo\\"+algo_name.lower()+"_qa"+source_type.lower()+"\\"+env["_BUILD_TARGET"].lower()+"\\01_Source_Code\\algo\\"+head+"\\"+x)					
                    new_prj_content.append("SubsPers=.\..\common\MessagePers\ADAS_"+source_type.upper()+".p_s")
                    new_prj_content.append("AnalPers="+p_a_path+"_AnalyserPers_"+p_a_addon+".p_a")
                    new_prj_content.append("CompPers="+personalities_file)
                    second_level_uniquie_dir = []					
                    for y in source_list:		
                        if "\\04_Engineering\\01_Source_Code\\algo\\"+head+"\\"+x+"\\" in y:
                            second_level_uniquie_dir.append(y)
                    folder_name = x					
                    recursive_function(x, second_level_uniquie_dir, previous_folder)					
            new_prj_content.append("EndSubProjectMarker")
        return	
	
    first_level_uniquie_dir = []		
    source_list = sources		
    for files in source_list:	
        head, sep_, tail = files.partition('\\algo\\')
        head, sep, tail = tail.partition('\\')			
        if head not in first_level_uniquie_dir:
            first_level_uniquie_dir.append(head)
    first_level_uniquie_dir.sort()
    new_prj_content.append("EndContainedFilesMarker\n")
    new_prj_content.append("StartSubProjectMarker")	
    for x in first_level_uniquie_dir:
        new_prj_content.append("StartProjectMarker")
        new_prj_content.append("FolderName="+x)
        new_prj_content.append("SourcePath=.\\..\\..\\..\\..\\..\\..\\04_Engineering\\01_Source_Code\\algo\\"+x)
        new_prj_content.append("OutputPath=.\..\..\..\..\..\..\\04_Engineering\\04_Build\\algo\\"+algo_name.lower()+"_qa"+source_type.lower()+"\\"+env["_BUILD_TARGET"].lower()+"\\01_Source_Code\\algo\\"+x)			
        new_prj_content.append("SubsPers=.\..\common\MessagePers\ADAS_"+source_type.upper()+".p_s")
        new_prj_content.append("AnalPers="+p_a_path+"_AnalyserPers_"+p_a_addon+".p_a")
        new_prj_content.append("CompPers="+personalities_file)
        second_level_uniquie_dir = []			
        for y in source_list:		
            if "\\04_Engineering\\01_Source_Code\\algo\\"+x+"\\" in y:
                second_level_uniquie_dir.append(y)
        recursive_function(x, second_level_uniquie_dir, "algo")
    new_prj_content.append("EndSubProjectMarker")
    source_files_prj = []
    if qac_mode == "file":
        source_files_prj = (map(lambda x: x.split("04_Engineering")[1], sources))
        source_files_prj = (map(lambda x: ".\\..\\..\\..\\..\\..\\..\\04_Engineering" + x, source_files_prj))
        source_files_prj = "\n".join(source_files_prj).strip()
    else:
        source_files_prj = new_prj_content
		
    source_files = "\n".join(source_files_prj).strip()	
    # generate .prj file
    try:
        prj_file_content = (qac_scons_prj_template % (algo_name.upper(), source_code_dir_rel_path, output_path, source_type.upper(), p_a_path, p_a_addon, personalities_file, source_files))
    except UnboundLocalError:
        prj_file_content = (qac_prj_template % (algo_name.upper(), source_code_dir_rel_path, source_type.upper(), p_a_path, p_a_addon, personalities_file, source_files))
    # algo_lib_file_list is used as a source for this command for the following reason: 
    # Essentially all information being written to the qac files comes from this file. 
    # So if this file is updated, GenericScons notices that also the qac-files require a rebuild.
    qac_prj = Command(destination_dir + "/" + prj_file_name,
                      qac_depend, WriteTextFile(destination_dir, prj_file_name, prj_file_content))
    
    # -------------------
    # create QAC p_a file
    # -------------------
	
	# get include and exclude paths
	
    # compiler include paths: those paths have to be included in the includes list AND the exclude list for qac
    # remark: when executing this script, includes for source code have not been added to env['CPPPATH'] yet
    compiler_includes = env['CPPPATH']
    regex = re.compile(".*(04_Engineering).*")
    compiler_includes = [m.group(0) for p in compiler_includes for m in [regex.search(p)] if m]
    compiler_includes = (map(lambda x: x.replace('/','\\').split("04_Engineering")[1], compiler_includes))
    incl_excl_paths = (map(lambda x: "-i \".\\..\\..\\..\\..\\..\\..\\04_Engineering" + x.strip() + "\"\n", compiler_includes))
    incl_excl_paths += (map(lambda x: "-q \".\\..\\..\\..\\..\\..\\..\\04_Engineering" + x.strip() + "\"\n", compiler_includes))
    incl_excl_paths = "".join(incl_excl_paths).strip()

    if env["_BUILD_TARGET"] == "TI_ARP32":
        matches = []
        for root, dirnames, filenames in os.walk(Dir('#../../../01_Source_Code/algo/' + env['ALGO'].lower()).abspath):
            for filename in fnmatch.filter(filenames, '*.k'):
                matches.append(os.path.join(root, filename))
        dir_matched = []		
        for file in matches:
            dir_split, filename = os.path.split(os.path.abspath(file))		
            dir_matched.append(dir_split)
        uniquie_dir = list(set(dir_matched))
		
        uniquie_dir = [w.replace('01_Source_Code', '04_Build\\algo\\'+env['ALGO'].lower()+'\\ti_arp32\\release\\01_Source_Code') for w in uniquie_dir]
        		
        include_paths = (map(lambda x: x.split("04_Engineering")[1], uniquie_dir))
        include_paths += (map(lambda x: x.split("04_Engineering")[1], includes))		
    # get include paths for source code
    	
    else:
        include_paths = (map(lambda x: x.split("04_Engineering")[1], includes))
		
    include_paths = (map(lambda x: "-i \".\\..\\..\\..\\..\\..\\..\\04_Engineering" + x.strip() + "\"\n", include_paths))
    include_paths = "".join(include_paths).strip()
    
	# get exclude paths	for source code: read common includes --> those paths are to be excluded from QA testing
    execfile(algo_lib_file_list)
    try:
        exclude_paths = Split(locals()['qac_exclude_paths'])
    except KeyError:
        exclude_path_variable = component_name.lower() + '_algo_common_include_paths'
        exclude_paths = Split(locals()[exclude_path_variable])
    exclude_paths = (map(lambda x: Dir(x).abspath.split("04_Engineering")[1], exclude_paths))
    exclude_paths = (map(lambda x: "-q \".\\..\\..\\..\\..\\..\\..\\04_Engineering" + x.strip() + "\"\n", exclude_paths))
    exclude_paths = "".join(exclude_paths).strip()
	
    # add include/exclude paths to include paths
    p_a_content = include_paths + "\n" + exclude_paths + "\n" + incl_excl_paths
    
    # get defines
    formatted_defines = []
    if not defines == ['']:
        for define in defines:
            if define != "":
                formatted_defines.append("-d \"" + define + "\"")
        defines = "\n".join(formatted_defines).strip()
        p_a_content = p_a_content + '\n' + defines
        
    # read pa template file
	# Search for component-specific template file
    filePath  = algo_qac_dir + "/QA" + source_type.upper() + "_p_a_template.txt"
    
    if os.path.isfile(File(filePath).abspath):
       qac_depend += [File(filePath).abspath]
       qac_p_a_template = ReadTextFile(File(filePath).abspath, False)
    else:
       filePath = os.path.join(template_dir, "QA" + source_type.upper() + "_p_a_template.txt")
       if os.path.isfile(File(filePath).abspath):
          qac_p_a_template = ReadTextFile(File(filePath).abspath, False)
       else:
          print "Error: p_a template is not found"
          print "No QA%s analyser personality is generated!!" %source_type.upper()
          # Usage of Command in order to display a build error at build time
          qac_pa = Command(pa_file_name, filePath, "$SOURCE")
          return [qac_pa]
    
    # generate .p_a file
    # because in one component, there can be more than one lib, create separate .p_a file for each processor
    pa_file_content = (qac_p_a_template % (p_a_content))
    # see above for an explanation for usage of algo_lib_file_list here
    qac_pa = Command(destination_dir + "/" + pa_file_name,
                     qac_depend, WriteTextFile(destination_dir, pa_file_name, pa_file_content))

    # -----------------------
    # create QAC filelist.lst
    # -----------------------
    # generate filelist.lst for command line processing
    # because in one component, there can be more than one lib, create separate .lst file for each processor
    # Modified QAC Filelist.lst content for GenericScons the QAC build to fully constructed based on the source-generates-target paradigm	
	
    fileContent = ""
    Old_Check_File_Dir = ""
    New_Check_File_Dir = ""			
    for line in sources:
        Op_line = line
        if qac_mode != "file":		
            head, sep , tail = Op_line.partition("04_Engineering")
            op_index_file_list = tail.rfind("\\")		
            New_Check_File_Dir = tail[1:op_index_file_list]
            if Old_Check_File_Dir == New_Check_File_Dir:
                fileContent += ("\"")
                fileContent += (line.strip())
                fileContent += ("\"\n")			
            else:
                op_index = report_destination_dir+"\\"+New_Check_File_Dir
                fileContent += ("-op \"")
                fileContent += (op_index)
                fileContent += ("\"\n")
                fileContent += ("\"")
                fileContent += (line.strip())
                fileContent += ("\"\n")
                Old_Check_File_Dir = New_Check_File_Dir			
        if qac_mode == "file":		
            head, sep , tail = Op_line.partition("04_Engineering")
            op_index_file_list = tail.rfind("\\")		
            New_Check_File_Dir = tail[1:op_index_file_list]		
            op_index = report_destination_dir+"\\"+New_Check_File_Dir
            fileContent += ("-op \"")
            fileContent += (op_index)
            fileContent += ("\"\n")
            fileContent += ("\"")
            fileContent += (line.strip())
            fileContent += ("\"\n")
            Old_Check_File_Dir = New_Check_File_Dir			

    if qac_mode != "file":		
        fileContent += "-cmaf \"" + report_destination_dir +"\\" + algo_name.upper() + "\""	
        fileContent += ("\n")
    if qac_mode == "file":		
        fileContent += "-cmaf \"" + destination_dir +"\\output\\" + env["_BUILD_TARGET"].lower() + "\\" + algo_name.upper() + "\""	
        fileContent += ("\n")	
    # see above for an explanation for usage of algo_lib_file_list here
    qac_filelist = Command(destination_dir + "/" + filelist_name,
                           qac_depend, WriteTextFile(destination_dir, filelist_name, fileContent))
                    
    # -----------------------
    # create QAC settings.via
    # -----------------------
    # generate settings.via for command line processing
    # because in one component, there can be more than one lib, create separate .via file for each processor
    settingsContent = ""

    # XXX_AnalyserPers_C.p_a file might not be created by scons, use pa_file_content
    if pa_file_content != "":
        pa_file_content_list = pa_file_content.split("\n")
        for line in pa_file_content_list:
            if line.find("\".\\") != -1:
                lineStrToWrite = line[:line.find("\".\\")+1] + Dir(destination_dir).abspath + "\\" + line[line.find("\".\\")+1:]
                settingsContent += (lineStrToWrite.strip())
                settingsContent += ("\n")
            else:
                settingsContent += (line)
                settingsContent += ("\n")
    else:
        print "Error: XXX_AnalyserPers_C.p_a file is empty"
        return None
            
    # read Message Personality file
    if source_type.upper() == "CPP":
        ps_file_name = File(os.path.join(destination_dir, "..", ".\common\MessagePers\ADAS_CPP.p_s")).abspath
    else:
        ps_file_name = File(os.path.join(destination_dir, "..", ".\common\MessagePers\ADAS_C.p_s")).abspath

    if os.path.isfile(ps_file_name):
        ps_file_content_list = ReadTextFile(ps_file_name, True)
        for line in ps_file_content_list:
            if line.find("-rem") == -1:
                settingsContent += (line)
        settingsContent += ("\n")
    else:
        print "Error: Message Personality file is not found"
        # Usage of Command in order to display a build error at build time
        qac_settings = Command(destination_dir + "/" + settings_name, ps_file_name, "$SOURCE")
        return [qac_settings]
        
    # read Compiler Personality file
    pc_file_name = personalities_file
    pc_file_name = File(os.path.join(destination_dir, pc_file_name)).abspath
    if os.path.isfile(pc_file_name):
        pc_file_content = ReadTextFile(pc_file_name, True)
        for line in pc_file_content:
            if (line.find("-i \"") != -1) or (line.find("-q \"") != -1 or (line.find("-fi \"")) != -1):
                if(line.find("-fi \"") != -1):				
                    lineStrToWrite = line[:5] + Dir(destination_dir).abspath + "\\" + line[5:]
                else:					
                    lineStrToWrite = line[:4] + Dir(destination_dir).abspath + "\\" + line[4:]				
                settingsContent += (lineStrToWrite.strip())
                settingsContent += ("\n")
            elif line.find("\".\\") != -1:
                lineStrToWrite = line[:line.find("\".\\")+1] + Dir(destination_dir).abspath + "\\" + line[line.find("\".\\")+1:]
                settingsContent += (lineStrToWrite.strip())
                settingsContent += ("\n")
            else:
                settingsContent += (line)
    else:
        print "Error: Compiler Personality file is not found"
        # Usage of Command in order to display a build error at build time
        qac_settings = Command(destination_dir + "/" + settings_name, pc_file_name, "$SOURCE")
        return [qac_settings]
    
    # settingsContent += ("-ef+\n")
    # settingsContent += ("-op \"" + Dir(destination_dir).abspath + "\output\"\n")
    # see above for an explanation for usage of algo_lib_file_list here
    qac_settings = Command(destination_dir + "/" + settings_name,
                           qac_depend, WriteTextFile(destination_dir, settings_name, settingsContent))
    
    return [qac_prj, qac_pa, qac_filelist, qac_settings]
		
def qac_copy_action(QAC, qac_dir):
    """
    Function             :  qac_copy_action
    Description          :  
    QAC                  :  
    qac_dir              :  
    Returns              :  
    """
    if QAC == "QAC":	
        qac_files = [QACPATH + 'bin\\QAC.usr.Misra2004_ADAS', QACPATH + 'm2cm\\messages\\QAC.usr.Misra2004_ADAS', QACPATH + 'bin\\qacmet.txt']
        for file in qac_files:
            if os.path.isfile(file):
                os.system("del /F %s" % file) 
        try:                
            shutil.copy(qac_dir + '.\\..\\common\\UserMessageFile\\QAC.usr.Misra2004_ADAS', QACPATH + 'bin\\')	
            shutil.copy(qac_dir + '.\\..\\common\\UserMessageFile\\QAC.usr.Misra2004_ADAS', QACPATH + 'm2cm\\messages\\')
            shutil.copy(qac_dir + '.\\..\\common\\UserMessageFile\\qacmet.txt', QACPATH + 'bin\\')	
        except IOError:
            print "\nWarning: At least one of the following folders was not found:\n %sbin \n %sm2cm\\messages \n %s\\..\\common\\UserMessageFile" %(QACPATH, QACPATH, qac_dir)
            print "Please check your shares and/or your QAC installation!!" 
    elif QAC == "QACPP": 
        qacpp_files = [QACPPPATH + 'bin\\QACPP.usr.Misra2008_ADAS', QACPPPATH + 'mcpp\\messages\\QACPP.usr.Misra2008_ADAS', QACPPPATH + 'bin\\qacppmet.txt']
        for file in qacpp_files:
            if os.path.isfile(file):
                os.system("del /F %s" % file)  
        try:                
            shutil.copy(qac_dir + '.\\..\\common\\UserMessageFile\\QACPP.usr.Misra2008_ADAS', QACPPPATH + 'bin\\')	
            shutil.copy(qac_dir + '.\\..\\common\\UserMessageFile\\QACPP.usr.Misra2008_ADAS', QACPPPATH + 'mcpp\\messages\\')
            shutil.copy(qac_dir + '.\\..\\common\\UserMessageFile\\qacppmet.txt', QACPPPATH + 'bin\\')	
        except IOError:
            print "\nWarning: At least one of the following folders was not found:\n %sbin\n %smcpp\\messages\n %s\\..\\common\\UserMessageFile" %(QACPPPATH, QACPPPATH, qac_dir)
            print "Please check your shares and/or your QAC installation!!" 
    else:
        pass

    return None

def generate_qac_proj(self,
                source_list,
                include_list,
                define_list,
                source_code_dir,
                personalities_file,
                qac_mode,
				qac_source_type,
                *args,
                **kw):
    """
    Function                       :  generate_qac_proj
    Description                    :  
    source_list                    :  
    include_list                   :  
    define_list                    :  
    source_code_dir                :  
    personalities_file             :  
    qac_mode                       :  
    qac_source_type                :  
    *args                          :  
    **kw                           :  
    Returns                        :  
    """
    src_abs = map(lambda x: os.path.abspath(x), Split(source_list))
    inc_abs = map(lambda x: os.path.abspath(x), Split(include_list))
            
    qac_files = []
    qacpp_files = []
    results = []

    # Generate QAC-files, analysis and reports for .c/.cpp-code resp.
    if qac_source_type == 'cpp':	
        if not os.path.exists(self['ENV']['PATH_QACPP_PROJ']):
            os.makedirs(self['ENV']['PATH_QACPP_PROJ'])
        if not os.path.exists(self['ENV']['PATH_QACPP_REPORT']):
            os.makedirs(self['ENV']['PATH_QACPP_REPORT'])		
        if qac_mode == 'file':
            destination_dir = self['ENV']['PATH_QACPP_PROJ'] + "/../" + self['ALGO'] + "_debug"
            report_destination_dir = self['ENV']['PATH_QACPP_REPORT']			
        else:
            destination_dir = self['ENV']['PATH_QACPP_PROJ']
            report_destination_dir = self['ENV']['PATH_QACPP_REPORT']			
			
        source_type = "cpp"
        copy_action = qac_copy_action("QACPP", self['ENV']['PATH_QACPP_PROJ'])
        try:
            qacpp_files += generate_files(self, destination_dir,report_destination_dir ,src_abs, inc_abs, define_list, source_type, self['COMPONENT'], self['ALGO'], source_code_dir, personalities_file, qac_mode)
            if not os.path.exists(destination_dir + "/output"):
                os.makedirs(destination_dir + "/output")            
        except TypeError:
            qacpp_files += []
        Requires(qacpp_files, copy_action)	
    results.append(qacpp_files)

    if qac_source_type == 'c':	
        if not os.path.exists(self['ENV']['PATH_QAC_PROJ']):
            os.makedirs(self['ENV']['PATH_QAC_PROJ'])
        if not os.path.exists(self['ENV']['PATH_QAC_REPORT']):
            os.makedirs(self['ENV']['PATH_QAC_REPORT'])			
        if qac_mode == 'file':
            destination_dir = self['ENV']['PATH_QAC_PROJ'] + "/../" + self['ALGO'] + "_debug"
            report_destination_dir = self['ENV']['PATH_QAC_REPORT']			
        else:
            destination_dir = self['ENV']['PATH_QAC_PROJ']
            report_destination_dir = self['ENV']['PATH_QAC_REPORT']			
        source_type = "c"
        copy_action = qac_copy_action("QAC", self['ENV']['PATH_QAC_PROJ'])
        try:
            qac_files += generate_files(self, destination_dir, report_destination_dir,src_abs, inc_abs, define_list, source_type, self['COMPONENT'], self['ALGO'], source_code_dir, personalities_file, qac_mode)
            if not os.path.exists(destination_dir + "/output"):
                os.makedirs(destination_dir + "/output")                
        except TypeError:
            qac_files += []
        Requires(qac_files, copy_action)			
    results.append(qac_files)
    return results
  
def generate_qac_reports(self, target, source, source_type, qac_mode, **kw):

    """
    Function                 :  generate_qac_reports
    Description              :  
    target                   :  
    source                   :  
    source_type              :  
    qac_mode                 :  
    **kw                     :  
    Returns                  :  
    """
    source_file_list = []	
    QAC_Return = []	
    # Modified generate_qac_reports method for analysing one file at a time.
    if 	source_type == 'c':
        for Op_line in  source:	
            head, sep , tail = Op_line.partition("04_Engineering")
            if not os.path.exists(self['ENV']['PATH_QAC_REPORT']):
                os.makedirs(self['ENV']['PATH_QAC_REPORT'])
            QAC_file_base_path = self['ENV']['PATH_QAC_REPORT']
            source_file_list.append(QAC_file_base_path+tail)	
        self['OBJSUFFIX'] = '.c.met'		
        self['QAC_option'] = 'qac'
        if qac_mode != "file":	
            self['QAC_SWTTING_VIA'] = self['ENV']['PATH_QAC_PROJ'] + "\\settings_" + self["_BUILD_TARGET"].lower() +".via"
            self['QAC_FILELIST_LST'] = self['ENV']['PATH_QAC_PROJ'] +  "\\filelist_" + self["_BUILD_TARGET"].lower() + ".lst"
        if qac_mode == "file":	
            self['QAC_SWTTING_VIA'] = self['ENV']['PATH_QAC_PROJ'] + "/../" + self['ALGO'] + "_debug" + "\\settings_" + self["_BUILD_TARGET"].lower() + "_debug" +".via"
            self['QAC_FILELIST_LST'] = self['ENV']['PATH_QAC_PROJ'] + "/../" + self['ALGO'] + "_debug" +  "\\filelist_" + self["_BUILD_TARGET"].lower() + "_debug" + ".lst"		
        Naming_Convenations_path = 	os.path.abspath(self['ENV']['PATH_QAC_PROJ']+"\..")	
        self['NAMING_CONVENTIONS'] = Naming_Convenations_path	+ "\\common\\NamingConventions\\NamingConventions.nrf"
        self['QAC_PROJECT_TEMPLATE_FILE_NAME'] = "QAC:"+ str(self['ALGO']) + ":" + self["_BUILD_TARGET"].upper()		
        QAC_Return = self.QACANALYSIS(target, source_file_list, **kw)

    if source_type == 'cpp':
        for Op_line in  source:	
            head, sep , tail = Op_line.partition("04_Engineering")
            if not os.path.exists(self['ENV']['PATH_QACPP_REPORT']):
                os.makedirs(self['ENV']['PATH_QACPP_REPORT'])
            QACPP_file_base_path = self['ENV']['PATH_QACPP_REPORT']
            source_file_list.append(QACPP_file_base_path+tail)
        self['OBJSUFFIX'] = '.cpp.met'		
        self['QACPP_option'] = 'qacpp'
        if qac_mode != "file":		
            self['QACPP_SWTTING_VIA'] = self['ENV']['PATH_QACPP_PROJ'] + 	"\\settings_" +self["_BUILD_TARGET"].lower() +".via"
            self['QACPP_FILELIST_LST'] = self['ENV']['PATH_QACPP_PROJ'] +  "\\filelist_" + self["_BUILD_TARGET"].lower() + ".lst"
        if qac_mode == "file":
            self['QACPP_SWTTING_VIA'] = self['ENV']['PATH_QACPP_PROJ'] + "/../" + self['ALGO'] + "_debug" + "\\settings_" + self["_BUILD_TARGET"].lower() + "_debug" +".via"
            self['QACPP_FILELIST_LST'] = self['ENV']['PATH_QACPP_PROJ'] + "/../" + self['ALGO'] + "_debug" +  "\\filelist_" + self["_BUILD_TARGET"].lower() + "_debug" + ".lst"				
        Naming_Convenations_path = 	os.path.abspath(self['ENV']['PATH_QACPP_PROJ']+"\..")		
        self['NAMING_CONVENTIONS_CPP'] = Naming_Convenations_path	+ "\\common\\NamingConventions\\NamingConventions_cpp.nrf"
        self['QAC_PROJECT_TEMPLATE_FILE_NAME_CPP'] ="QACPP:" + self['ALGO'] + ":" + self["_BUILD_TARGET"].upper()			
        QAC_Return = self.QACPPANALYSIS(target, source_file_list, **kw)	
	
    return 	QAC_Return
	
def generate(env): 
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    # setup Builder device for generating files for QAC 
    env.AddMethod(generate_qac_proj, "generate_qac_proj")
    env.AddMethod(generate_qac_reports, "generate_qac_report")
	
    SCons.Tool.cc.generate(env)
    cplusplus.generate(env)		

	# ----------------------------------------	
	# Prepare directory paths
	# ----------------------------------------	
    qacpp_tests_dir = os.path.join(modtest_dir, "qacpp_tests\\", env['ALGO'])
    qacpp_tests_dir_abs = os.path.join(Dir(qacpp_tests_dir).abspath)
    qac_tests_dir = os.path.join(modtest_dir, "qac_tests\\", env['ALGO'])
    qac_tests_dir_abs = os.path.join(Dir(qac_tests_dir).abspath)
    qac_report_dir = os.path.join(Analysis_dir, env['ALGO']+"_qac\\", env["_BUILD_TARGET"].lower())
    qac_report_dir_abs = os.path.join(Dir(qac_report_dir).abspath)
    qacpp_report_dir = os.path.join(Analysis_dir, env['ALGO']+"_qacpp\\", env["_BUILD_TARGET"].lower())
    qacpp_report_dir_abs = os.path.join(Dir(qacpp_report_dir).abspath)	

	# ----------------------------------------
	# Prepare environment variables which are necessary to execute QAC/QACPP
	# ----------------------------------------
    CMNAME = 'm2cm'
    CMPPNAME = 'mcpp'	
    env['ENV']['QAWBIN'] = QAWBIN
    env['ENV']['QACPATH'] = QACPATH
    env['ENV']['QACBIN']  = env['ENV']['QACPATH'] + 'bin\\'
    env['ENV']['QACOUTPATH'] = env['ENV']['QACPATH'] + 'temp\\'
    env['ENV']['QACHELPFILES'] = env['ENV']['QACPATH'] + 'help\\'
    env['ENV']['QACTEMP'] = env['ENV']['QACPATH'] + 'temp\\'
    env['ENV']['QARBIN'] = env['ENV']['QACPATH'] + QARBIN
    env['ENV']['CMHOME'] = env['ENV']['QACPATH'] + CMNAME + '\\'
    env['ENV']['CMBIN'] = env['ENV']['CMHOME'] + 'bin\\'
    env['ENV']['PATH_QAC_PROJ'] = qac_tests_dir_abs
    env['ENV']['PATH_QAC_REPORT'] = qac_report_dir_abs 	
    env['ENV']['QACPPPATH'] = QACPPPATH
    env['ENV']['QACPPBIN']  = env['ENV']['QACPPPATH'] + 'bin\\'
    env['ENV']['QACPPOUTPATH'] = env['ENV']['QACPPPATH'] + 'temp\\'
    env['ENV']['QACPPHELPFILES'] = env['ENV']['QACPPPATH'] + 'help\\'
    env['ENV']['QACPPTEMP'] = env['ENV']['QACPPPATH'] + 'temp\\'
    env['ENV']['QARBIN_CPP'] = env['ENV']['QACPPPATH'] + QARBIN
    env['ENV']['CMPPHOME'] = env['ENV']['QACPPPATH'] + CMPPNAME + '\\'
    env['ENV']['CMPPBIN'] = env['ENV']['CMPPHOME'] + 'bin\\'
    env['ENV']['PATH_QACPP_PROJ'] = qacpp_tests_dir_abs
    env['ENV']['PATH_QACPP_REPORT'] = qacpp_report_dir_abs	
    env['ENV']['PATH'] = env['ENV']['QACBIN'] + ';' + env['ENV']['QAWBIN'] + ';' + env['ENV']['QARBIN'] + ';' + env['ENV']['QACPPBIN'] + ';' + env['ENV']['QAWBIN'] + ';' + env['ENV']['QARBIN_CPP'] + ';' + env['ENV']['PATH']
    
	
    env['NEWQAWPATH'] = 'C:\\tools\\QAW\\bin\\'
    env.PrependENVPath('PATH', env.subst('"$NEWQAWPATH"'))	

    env['CC'] = 	'qaw'

    env['MSG_FORMAT'] = '"%F(%l,%c) : warning level %g : QP%n: %t"'	

    env['CCCOM'] = '$CC $QAC_option -via $QAC_SWTTING_VIA -format=$MSG_FORMAT $QAC_OPTIONS -op ${TARGET.dir} $SOURCE && C:\\tools\\QAC\\m2cm\\bin\\qacsa_m2cm.exe qac -nrf $NAMING_CONVENTIONS -op ${TARGET.dir} $SOURCE'
    env['CCCOMSTR'] = '$CCCOM'

    env['CXX'] = '$CC'
    env['CXXCOM'] = '$CC $QACPP_option -via $QACPP_SWTTING_VIA -format=$MSG_FORMAT $QAC_OPTIONS -op ${TARGET.dir} $SOURCE && C:\\tools\\QACPP-2.5\\mcpp\\bin\\qacppsa_mcpp.exe qacpp -nrf $NAMING_CONVENTIONS_CPP -op ${TARGET.dir} $SOURCE'
    env['CXXCOMSTR'] = '$CXXCOM'	

    env['QAR']          = 'C:\\tools\\QAC\\QAR-1.1\\bin\\qar.exe'
    env['QARCMD']       = '$QAC_option -via $QAC_SWTTING_VIA  -po qar::user_reports_dir="C:\\tools\\QAC\\QAR-1.1\\standard_reports" -list $QAC_FILELIST_LST -po qar::report_type="Compliance Report" -po qar::project_name=$QAC_PROJECT_TEMPLATE_FILE_NAME -po "qar::viewing_program=none" -po qar::report_format=$QAR_FORMAT'	
    env['QARCOM']       = '$QAR $QARCMD'
    env['QARCOMSRT']       = '$QARCOM'
	
    env['QARCPP']          = 'C:\\tools\\QACPP-2.5\\QAR-1.1\\bin\\qar.exe'
    env['QARCMDCPP']       = '$QACPP_option -via $QACPP_SWTTING_VIA  -po qar::user_reports_dir="C:\\tools\\QACPP-2.5\\QAR-1.1\\standard_reports" -list $QACPP_FILELIST_LST -po qar::report_type="Compliance Report" -po qar::project_name=$QAC_PROJECT_TEMPLATE_FILE_NAME_CPP -po "qar::viewing_program=none" -po qar::report_format=$QAR_FORMAT'
    env['QARCOMCPP']       = '$QARCPP $QARCMDCPP'
    env['QARCOMSRTCPP']       = '$QARCOMCPP'	

    action_list_c = [SCons.Action.Action( '$QARCOM', '$QARCOMSRT')]
    QACBld = SCons.Builder.Builder(action = action_list_c,
                                           src_builder = 'StaticObject')
										   
										   
    action_list_cpp = [SCons.Action.Action( '$QARCOMCPP', '$QARCOMSRTCPP')]	
    QACPPBld = SCons.Builder.Builder(action = action_list_cpp,
                                           src_builder = 'StaticObject')										   
										   
	
    env['BUILDERS']['QACANALYSIS'] = QACBld
    env['BUILDERS']['QACPPANALYSIS'] = QACPPBld	
	
def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    return 1