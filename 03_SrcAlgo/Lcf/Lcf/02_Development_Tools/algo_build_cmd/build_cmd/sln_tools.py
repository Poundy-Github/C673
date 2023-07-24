"""0
skript for calling visual studio sln tools


:org:           Continental AG
:author:        Jochen Spruck
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:37CET $

"""

# set to non-zero to get full flavored debuging prints
verbose_debug = 0
if verbose_debug: import pprint

import uuid
import os
import sys
import re
from optparse import OptionParser

PYLIB = os.path.join(os.path.dirname(__file__), "..\mks_tools")
if PYLIB not in sys.path: 
    sys.path.append(PYLIB)

from mks_config_tools import xml_obj,logging_obj

class MergeSlnFiles_obj(logging_obj):
    """
    Description: Merge snl files class
    """
    def __init__(self):
        logging_obj.__init__(self)
        self.OutFile = None
    
    def AddHeader(self):
        self.OutFile.write("Microsoft Visual Studio Solution File, Format Version 9.00\n")
        self.OutFile.write("# Visual Studio 2005\n")
             
    def AddProject(self, NewUUID, ProjectName, vcprojFile, vcprojUUID):
        self.OutFile.write('Project("{%s}") = "%s", "%s", "{%s}" \n'%(NewUUID, ProjectName, vcprojFile, vcprojUUID) )
        self.OutFile.write('EndProject\n')

    def AddFolder(self, NewUUID, FolderName):
        self.OutFile.write('Project("{2150E333-8FDC-42A3-9474-1A3956D46DE8}") = "%s", "%s", "{%s}" \n'%(FolderName, FolderName, NewUUID) )
        self.OutFile.write('EndProject\n')
        
    def AddOpenGlobal(self):
        self.OutFile.write('Global\n')
    
    def AddCloseGlobal(self):
        self.OutFile.write('EndGlobal\n')
        
    def AddOpenGlobalSection(self,kind,isPreSolution):
        prePostSolution = ""
        if isPreSolution:
            prePostSolution = 'preSolution'
        else:
            prePostSolution = 'postSolution'
        self.OutFile.write('\tGlobalSection(%s) = %s\n'%(kind,prePostSolution))
        
    def AddCloseGlobalSection(self):
        self.OutFile.write('\tEndGlobalSection\n')
        
    def AddSolutionConfigurationPlatforms(self):
        self.AddOpenGlobalSection('SolutionConfigurationPlatforms', True)
        self.OutFile.write('\t\tdebug|Win32 = debug|Win32\n')
        self.OutFile.write('\t\trelease|Win32 = release|Win32\n')
        self.AddCloseGlobalSection()
    
    def AddProjectConfigurationPlattforms(self,GlobalSection):
        self.AddOpenGlobalSection('ProjectConfigurationPlatforms', False);
        for line in GlobalSection:
            self.OutFile.write(line+'\n')
        self.AddCloseGlobalSection()
    
    def AddSolutionProperties(self):
        self.AddOpenGlobalSection('SolutionProperties', True)
        self.OutFile.write('\t\tHideSolutionNode = FALSE\n')
        self.AddCloseGlobalSection()
        
    def AddNestedProjects(self, nestedDict):
        self.AddOpenGlobalSection('NestedProjects', True)
        for component in nestedDict.keys():
            nodeUUID = nestedDict[component]['uuid']
            for nestedUUID in nestedDict[component]['nested']:
                self.OutFile.write('\t\t{%s} = {%s}\n'%(nestedUUID, nodeUUID))
        self.AddCloseGlobalSection()
        
    def MergeSlnFiles(self,argu):
        """
        MergeSlnFiles(self,argu)

        Description: the MergeSlnFiles main function

        Parameter:    -argu the command line options and arguments
        """

        usage = """usage : %prog MergeSlnFiles [options]
Example: python %prog MergeSlnFiles -c d:\\SWProjects\\MFC400\\06_algo\\04_eng\\03_Workspace\\xyz.xml -l -o c:\Logging"""
        
        #parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-c", "--config", dest="InputSlnFiles",
                  help="Input sln Files ", metavar="FILE")
        parser.add_option("-t", "--target_sln", dest="target",
                  help="Output Target sln", metavar="FILE", default="")
        parser.add_option("-l", "--log", dest="Logging",action="store_true", default = False,
                  help="log(on/off)")
        parser.add_option("-o", "--outputdir", dest="OutputDir",
                  help="working direcory")
        
        (options, args) = parser.parse_args(argu)
        
        # setup the local members to the arguments
        self.Logging    = options.Logging
        self.OutputDir  = options.OutputDir
        
        self.InputSlnFiles = options.InputSlnFiles
        NewUUID = uuid.uuid4()
        #print os.path.abspath(self.InputSlnFiles)
        basepath = os.path.dirname( os.path.abspath(self.InputSlnFiles))
        #print basepath
        if os.path.isfile(self.InputSlnFiles) == True:
            in_fo = open(self.InputSlnFiles)
            self.OutFile = open(options.target,'w')
            self.AddHeader()
            debug_options = []
            debug_options_dict = {}
            project_dict = {}
            folder_dict = {}

            if verbose_debug: pp = pprint.PrettyPrinter(indent=2)

            for InputSlnFile in in_fo.readlines():
                # full path to current solution
                act_sln = os.path.abspath(os.path.join(basepath, InputSlnFile.replace('\n','')))
                
                # name of the solution file as folder name
                act_sln_name = "unknown"
                match_component_name = re.search(r'\\([^\\]+).sln$', act_sln.lower())
                if match_component_name:
                    act_sln_name = match_component_name.group(1)
                # debugging
                if verbose_debug: pp.pprint('solution:           %s'%(act_sln))
                if verbose_debug: pp.pprint('extracted sln name: %s'%(act_sln_name))
                
                # add solution name as new nested node with new uuid
                if act_sln_name not in folder_dict:
                    folder_uuid = uuid.uuid4()
                    folder_dict[act_sln_name] = { 'uuid': folder_uuid, 'nested': [] }
                    self.AddFolder(folder_uuid, act_sln_name)
                    
                start_glob_section = False
                if os.path.isfile(act_sln) :
                    sln_fo = open(act_sln)
                    for line in sln_fo.readlines():
                        if line.find('Project("{') != -1:  
                            res, equ = line.split('=')
                            ProjectName, vcprojFile, vcprojUUID = equ.strip('\n').split(',')
                            if ProjectName not in project_dict:
                                # debugging
                                if verbose_debug: pp.pprint('  project name: %s'%(ProjectName.strip(' ').strip('"')))
                                if verbose_debug: pp.pprint('  project file: %s'%(vcprojFile.strip(' ').strip('"')))
                                if verbose_debug: pp.pprint('  project uuid: %s'%(vcprojUUID.strip(' ').strip('"').strip('{}')))

                                # add project to solution file
                                self.AddProject(NewUUID, ProjectName.strip(' ').strip('"'), vcprojFile.strip(' ').strip('"'), vcprojUUID.strip(' ').strip('"').strip('{}'))
                                project_dict[ProjectName] = ProjectName
                                
                                # add project to folder dictionary nest
                                folder_dict[act_sln_name]['nested'].append(vcprojUUID.strip(' ').strip('"').strip('{}'))
                                
                        if line.find('GlobalSection(ProjectConfigurationPlatforms) = postSolution') != -1:
                            start_glob_section = True
                        elif start_glob_section == True:
                            if line not in debug_options_dict:
                                debug_options.append(line.strip('\n'))
                                debug_options_dict[line] = line
                            # debug
                            if verbose_debug: pp.pprint('  debug option: %s'%(line.strip('\n')))
                        if start_glob_section == True and line.find('EndGlobalSection') != -1:
                            debug_options.pop()
                            start_glob_section = False
                else:
                    self.Log("Error","Could not open file %s"%(act_sln))
                    
            # debug
            if verbose_debug: pp.pprint(folder_dict)

            # build solution
            self.AddOpenGlobal()
            self.AddSolutionConfigurationPlatforms()
            self.AddProjectConfigurationPlattforms(debug_options)
            self.AddSolutionProperties()
            self.AddNestedProjects(folder_dict)
            self.AddCloseGlobal()
            self.OutFile.close()
            in_fo.close()
        else:
            self.Log("Error","File %s does not exist"%(self.InputSlnFiles))
def PrintHelp():
    """
    PrintHelp()

    Description: Print the Help menu 
    """
    print """Usage: 
python algo_main.py MergeSlnFiles [options e.g. -h for help]
"""

def main(argv):
    """
    main()

    Description: the main function 
    """
    
    #check for script
    if (argv[1] == "MergeSlnFiles"):
        if len(argv) < 3:
            argv.append("-h")
        MergeSlnFiles_obj().MergeSlnFiles(argv)
        sys.exit()
    else:
        PrintHelp() 
    
# check input args
if (len(sys.argv) > 1):
    main(sys.argv)
else:
    PrintHelp()
    
