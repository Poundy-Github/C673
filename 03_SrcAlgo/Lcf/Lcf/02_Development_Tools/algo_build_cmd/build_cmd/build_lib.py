###########
#MKS Scripting tool for building with msbuild, vcbuild and scons
#:org:           Continental AG
#
###########
print "%s" % (__file__)

import os
import sys
import subprocess
import re
import codecs
import mmap
import shutil

# adding import folder of mks_tools
PYLIB = os.path.join(os.getcwd(), "..\mks_tools")
if PYLIB not in sys.path:
    sys.path.append(PYLIB)

from mks_config_tools import xml_obj, logging_obj
from datetime import datetime, date, time, timedelta

class Node_obj():
    NOTM = "NOTM"
    TEMP = "TEMP"
    PERM = "PERM"
    def __init__(self, node_name, cfg_file=""):
        self.node_name = node_name
        self.cfg_file = [cfg_file]
        self.incoming_edges = {}
        self.marker = self.NOTM
    def GetCfgFile(self):
        return self.cfg_file
    def AppendCfgFile(self, file):
        self.cfg_file.append(file)
    def GetNodeName(self):
        return self.node_name
    def AddIncomingEdge(self, Node, NodeName):
        self.incoming_edges[NodeName] = Node
    def DelIncomingEdge(self, NodeName):
        del self.incoming_edges[NodeName]
    def GetEdges(self):
        return self.incoming_edges
    def HasEdges(self):
        if len(self.incoming_edges) == 0:
            return False
        else:
            return True
    def HasEdgeFrom(self, node):
        for i_node in self.incoming_edges:
            if self.incoming_edges[i_node].GetNodeName() == node.GetNodeName():
                return True
        return False
    def IsTempMarked(self):
        if self.marker == self.TEMP:
            return True
        else:
            return False
    def IsPermMarked(self):
        if self.marker == self.PERM:
            return True
        else:
            return False
    def IsUnmarked(self):
        if self.marker == self.NOTM:
            return True
        else:
            return False
    def MarkTemp(self):
        self.marker = self.TEMP
    def MarkPerm(self):
        self.marker = self.PERM

class ManageDependanyies_obj():
    def __init__(self):
        self.NodeList = {}
        pass

    def AddDependancy(self, CompName, DependancyName, cfg_file):
        if CompName not in self.NodeList:
            self.NodeList[CompName] = Node_obj(CompName, cfg_file)
        elif not (cfg_file in  self.NodeList[CompName].GetCfgFile()):
            self.NodeList[CompName].AppendCfgFile(cfg_file)
        if DependancyName is not None and len(DependancyName) > 0:
            if DependancyName not in self.NodeList:
                self.NodeList[DependancyName] = Node_obj(DependancyName)

            self.NodeList[DependancyName].AddIncomingEdge(self.NodeList[CompName], CompName)

    def GetNodesWithoutIncomingeEdges(self):
        ret_list = []
        for node in sorted(self.NodeList.keys()):
            if self.NodeList[node].HasEdges() == False:
                ret_list.append(self.NodeList[node])
        return ret_list

    def HasGraphEdges(self):
        for node in self.NodeList:
            if self.NodeList[node].HasEdges() == True:
                return True

    def GetSortedPopNode(self, NodesWithoutIncomingEdges):
        node_dict = {}
        for node_num in range(len(NodesWithoutIncomingEdges)):
            node_dict[NodesWithoutIncomingEdges[node_num].GetNodeName()] = node_num

        return node_dict[sorted(node_dict.keys())[0]]

    def IsAnyNodeUnmaked(self):
        ret_value = False
        for node in sorted(self.NodeList.keys()):
            if self.NodeList[node].IsUnmarked():
                ret_value = True
        return ret_value

    def GetUnmakedNode(self):
        temp_list = []
        for node in sorted(self.NodeList.keys()):
            if self.NodeList[node].IsUnmarked():
                temp_list.append(self.NodeList[node])
        return temp_list

    def visit(self, node, sorted_nodes_L):
        if node.IsTempMarked():
            print "not a DAG"
            return
        if node.IsUnmarked():
            node.MarkTemp()
            edges = node.GetEdges()
            edges_names = sorted(edges.keys())
            for node_m in edges_names:
                self.visit(edges[node_m], sorted_nodes_L)
            node.MarkPerm()
            sorted_nodes_L.insert(0, node)

    def GetOrderTarjan(self):
        # http://en.wikipedia.org/wiki/Topological_sorting  Tarjan(1976)
        cfg_file_list = []
        sorted_nodes_L = []
        comp_order = []
        while self.IsAnyNodeUnmaked():
            node_n = self.GetUnmakedNode()[0]
            self.visit(node_n, sorted_nodes_L)

        for node in sorted_nodes_L:
            cfg_file = node.GetCfgFile()
            for file in cfg_file:
                if len(file) > 0:
                    comp_name = node.GetNodeName()
                    # print comp_name
                    comp_order.append(comp_name)
                    cfg_file_list.append(file)
        return (cfg_file_list, comp_order)


    def GetOrderKahn(self):
        # http://en.wikipedia.org/wiki/Topological_sorting  Kahn(1962)
        cfg_file_list = []
        sorted_nodes_L = []
        comp_order = []
        NodesWithoutIncomingEdges = self.GetNodesWithoutIncomingeEdges()
        while len(NodesWithoutIncomingEdges) > 0:
            node_n = NodesWithoutIncomingEdges.pop(self.GetSortedPopNode(NodesWithoutIncomingEdges))
            sorted_nodes_L.insert(0, node_n)
            for node_m in sorted(self.NodeList.keys()):
                if self.NodeList[node_m].HasEdges() and (self.NodeList[node_m].HasEdgeFrom(node_n)):
                    self.NodeList[node_m].DelIncomingEdge(node_n.GetNodeName())
                    if self.NodeList[node_m].HasEdges() == False:
                        NodesWithoutIncomingEdges.append(self.NodeList[node_m])

        if self.HasGraphEdges():
            print "graph has at least one cycle"
            return None
        else:
            for node in sorted_nodes_L:
                comp_name = node.GetNodeName()
                # print comp_name
                comp_order.append(comp_name)
                for file in node.GetCfgFile():
                    cfg_file_list.append(file)
            return (cfg_file_list, comp_order)

    def GetOrder(self):
        return self.GetOrderTarjan()
        # return self.GetOrderKahn()

class BuildLibV2_obj(xml_obj, logging_obj):
    TARGET_NAME = "name"
    TARGET_FILTER = "filter"
    TARGET_DESC = "desc"
    TARGET_PRJ_FILTER = "prj_filter"

    TARGET_EXECUTE = "execute"
    TARGET_ATTRIBUTE = "attrib"
    TARGET_VCPROJ_FILE = "vcproj"
    TARGET_BUILD_LOG = "build_log"
    TARGET_SCONSTRUCT_DIR = "sconstruct_dir"

    XMLMAKE_BUILD_LOG = "build_log_dir"

    BUILD_SYSTEM_SCONS = "scons"
    BUILD_SYSTEM_MSBUILD = "msbuild"
    BUILD_SYSTEM_VCBUILD = "vcbuild"

    BUILD_TYPE_WILDCARD = "*"

    BUILD_REPORT_STATE = "State"
    BUILD_REPORT_NAME = "Name"
    BUILD_REPORT_LOG = "BuildLog"

    BUILD_STATE_OK = "OK"
    BUILD_STATE_ERROR = "ERROR"
    BUILD_STATE_SCONS_ERROR = "SCONS_ERROR"

    ###########
    #Description: Config shared sup projects class
    ###########
    def __init__(self):
        xml_obj.__init__(self)
        logging_obj.__init__(self)

        self.WorkingDir = ""
        self._BuildReport = {}
        self._BuildReportToDB = {}
        self._error_warning_dict = {}

    def DoBuildParseXmlCfg(self, make_all_xml_file):
        ###########
        #DoBuildParseXmlCfg(self, make_all_xml_file)
        #
        #Description: make_all_xml_file reads in the make all
        #
        #return the xml stuct, in case of error None
        ###########

        # first get all component make files
        base_path_all = os.path.dirname(make_all_xml_file)
        build_cfg_files = []
        dependancies = {}
        dep_class = ManageDependanyies_obj()
        if (os.path.isfile(make_all_xml_file) == 1):
            # load an existing make all cfg file
            Config = self.get_a_document(make_all_xml_file)
            BuildConfig = Config.getElementsByTagName("BuildConfig").item(0)
            BuildConfig.normalize()
            for BuildConfigs in BuildConfig.childNodes:
                if (BuildConfigs.nodeType == BuildConfigs.ELEMENT_NODE):
                    if BuildConfigs.nodeName == "BuildCfgFile":
                        cfg_file = BuildConfigs.getAttribute("file")
                        dependancies[os.path.join(base_path_all, cfg_file)] = BuildConfigs.getAttribute("dep").split(',')
                        build_cfg_files.append(os.path.join(base_path_all, cfg_file))

        # check dependancies
        for cfg_file in build_cfg_files:
            if (os.path.isfile(cfg_file) == 1):
                self.Log("Info", "cfg_file: %s" % (cfg_file))
                # load the make file
                Config = self.get_a_document(cfg_file)
                BuildComponentCfg = Config.getElementsByTagName("BuildComponentCfg").item(0)
                component = BuildComponentCfg.getAttribute("Component")
                for dep in dependancies[cfg_file]:
                    dep_class.AddDependancy(component, dep, cfg_file)

        build_cfg_files, comp_order = dep_class.GetOrder()
        self.Log("Info", "--------------- Components are build in following order, depending on the dep attribute -----------------------------------------")
        self.Log("Info", '--- Dependancy could be set in the config xml file by adding the dep attr e.g <BuildCfgFile file=".\em\make.xml" dep="cct" /> ---')
        for comp_n in comp_order:
            self.Log("Info", "Component %s " % (comp_n))
        self.Log("Info", "---------------------------------------------------------------------------------------------------------------------------------")

        # print build_cfg_files

        # read all component make files
        build_cfg_list = []
        for cfg_file in build_cfg_files:
            if (os.path.isfile(cfg_file) == 1):
                base_path = os.path.dirname(cfg_file)
                # load the make file
                Config = self.get_a_document(cfg_file)
                BuildComponentCfg = Config.getElementsByTagName("BuildComponentCfg").item(0)
                component = BuildComponentCfg.getAttribute("Component")
                BuildComponentCfg.normalize()
                for BuildTargtets in BuildComponentCfg.childNodes:
                    build_cfg = {}
                    if component not in build_cfg:
                        build_cfg[component] = {}
                    if (BuildTargtets.nodeType == BuildTargtets.ELEMENT_NODE):
                        TargetName = BuildTargtets.getAttribute("name")
                        target_cfg = {}  # build_cfg[component][BuildType][TargetName]
                        target_cfg[self.TARGET_DESC] = BuildTargtets.getAttribute("desc")
                        target_cfg[self.TARGET_EXECUTE] = BuildTargtets.getAttribute("execute")
                        if (target_cfg[self.TARGET_EXECUTE] == self.BUILD_SYSTEM_MSBUILD):
                            BuildLogName = "BuildLog.log"
                        elif (target_cfg[self.TARGET_EXECUTE] == self.BUILD_SYSTEM_SCONS):
                            BuildLogName = "sconsbuild.log"
                        else:
                            BuildLogName = "BuildLog.htm"
                        target_cfg[self.TARGET_ATTRIBUTE] = BuildTargtets.getAttribute("attrib")
                        if target_cfg[self.TARGET_EXECUTE] != self.BUILD_SYSTEM_SCONS:
                            # vcbuild & msbuild: get vcproj location
                            target_cfg[self.TARGET_VCPROJ_FILE] = os.path.join(base_path, BuildTargtets.getAttribute("vcproj"))

                        target_cfg[self.TARGET_FILTER] = BuildTargtets.getAttribute(self.TARGET_FILTER)
                        if  target_cfg[self.TARGET_FILTER] == "":
                            target_cfg[self.TARGET_FILTER] = self.BUILD_TYPE_WILDCARD

                        target_cfg[self.TARGET_PRJ_FILTER] = BuildTargtets.getAttribute(self.TARGET_PRJ_FILTER)

                        for BuildTypes in BuildTargtets.childNodes:
                            if (BuildTypes.nodeType == BuildTypes.ELEMENT_NODE):
                                if (BuildTypes.nodeName == "BuildType"):
                                    BuildType = BuildTypes.getAttribute("type").lower()
                                    if TargetName not in build_cfg[component]:
                                        build_cfg[component][TargetName] = {}
                                    if BuildType not in build_cfg[component][TargetName]:
                                        if BuildType == self.BUILD_TYPE_WILDCARD:
                                            BuildType_ext = "wildcard"
                                        else:
                                            BuildType_ext = BuildType.lower()

                                        if target_cfg[self.TARGET_EXECUTE] == self.BUILD_SYSTEM_SCONS:
                                            target_cfg[self.TARGET_BUILD_LOG] = os.path.abspath(os.path.join(base_path, "..", "_temp_sconslog", TargetName + "_" + BuildType_ext + "_" + BuildLogName))
                                            target_cfg[self.TARGET_SCONSTRUCT_DIR] = os.path.abspath(os.path.join(base_path, "..", component))
                                        else:
                                            # vcbuild & msbuild
                                            if len(BuildTargtets.getAttribute(self.XMLMAKE_BUILD_LOG)) > 0:
                                                # UseCase: logging path specified in the component xml file
                                                # Example: build_log_dir="..\..\..\..\04_Build\temp"
                                                # deprecated: BuildLogPath = os.path.join(base_path, os.path.dirname(BuildTargtets.getAttribute("vcproj")), BuildTargtets.getAttribute(self.XMLMAKE_BUILD_LOG), BuildType_ext , BuildLogName)
                                                BuildLogPath = os.path.join(base_path, os.path.dirname(BuildTargtets.getAttribute("vcproj")), BuildTargtets.getAttribute(self.XMLMAKE_BUILD_LOG), TargetName + "_" + BuildType_ext , BuildLogName)
                                                # print "BuildLogPath=%s" % os.path.abspath(BuildLogPath)
                                                target_cfg[self.TARGET_BUILD_LOG] = os.path.abspath(BuildLogPath)
                                            else:
                                                # UseCase: no logging path specified in the component xml file
                                                # Similar to Scons we create a vcbuild/msbuild logging directory "_temp_vclog" with a file for each component
                                                # target_cfg[self.TARGET_BUILD_LOG] = os.path.abspath(os.path.join(base_path, os.path.dirname(BuildTargtets.getAttribute("vcproj")), BuildType_ext, BuildLogName))
                                                target_cfg[self.TARGET_BUILD_LOG] = os.path.abspath(os.path.join(base_path_all, "_temp_vclog", TargetName + "_" + BuildType_ext + "_" + BuildLogName))
                                        build_cfg[component][TargetName][BuildType] = target_cfg.copy()
                        build_cfg_list.append(build_cfg)
                            # print BuildTypes.nodeName

        if len(build_cfg_list) > 0:
            return build_cfg_list
        else:
            return None

    def CheckProjectFilter(self, ProjectFilter, FilterAttributes):
        ###########
        #CheckProjectFilter(self, ProjectFilter, FilterAttributes)
        #
        #Description: Checks the project filter
        #
        #return True in case filter is matching or filter not set, otherwise false
        ###########
        if ProjectFilter == None:
            return True
        else:
            if len(FilterAttributes) == 0:
                return True
            else:
                ProjectFilterAttributes = FilterAttributes.lower().split(',')
                ProjectFilters = ProjectFilter.lower().split(',')
                for prj_filt in ProjectFilters:
                    for attr_filt in ProjectFilterAttributes:
                        if attr_filt == prj_filt:
                            return True

                return False

    def DetermineUsedNumberOfCores(self, NumberOfCores=None):
        # Determine the available Cores to compute on from the environment variable (is set by Windows itself)
        number_of_available_processors = os.environ['NUMBER_OF_PROCESSORS']
        if number_of_available_processors:
            # if read of environment variable NUMBER_OF_PROCESSORS is set, set the threads parameter to that value.
            return number_of_available_processors
        else:
            return NumberOfCores
    
    def ConstructTargetAttribute(self, NumberOfCores, target_cfg):
        attribute = target_cfg[self.TARGET_ATTRIBUTE]

        # replace the -j x attribute with the number of cores
        if NumberOfCores:
            # define RegEx for the -j option
            # -j (1)
            # -j (4)
            # -j (40)
            # -j %NumberOfCores%
            regex_j_option = r'-j\s*?([0-9|%NUMBER_OF_PROCESSORS%|%number_of_processors%|%Number_Of_Processors%]+)'
            # search number of threads
            match = re.search(regex_j_option, attribute)
            if match:
                # now we check if the number of cores is set to 0
                if match.group(1) == "0":
                    self.Log("Warn", "NUMBER_OF_PROCESSORS set to 0 -> -j option adapted to available cores")
                # now we check if the number of cores is set to 1
                # this setting must not be overwritten
                # sdlcompiler needs only single thread build.
                if match.group(1) != "1":
                    # if there is a thread specification, we will override it by the available
                    # processors to improve buildspeed.
                    # forced thread specification - replace with global thread specification
                    attribute = re.sub(regex_j_option, "-j %s" % NumberOfCores, attribute)
            else:
                # no threads specification - enter global one
                attribute += " -j %s" % NumberOfCores
                attribute = attribute.strip()
        else:
            self.Log("Error", "NumberOfCores not set. -> -j option not adapted to available cores")

        return attribute

    def PrepareBuilds(self, Type, NameFilter, SetupVcvars, build_cfg_list, NumberOfCores=None, ProjectFilter=None):
        ###########
        #PrepareBuilds(self,Type,NameFilter,SetupVcvars,build_cfg_list,NumberOfCores=None, ProjectFilter = None )
        #
        #Type    Release or Debug  (must be case sensitive because msbuild is aware of this)
        #
        #Description: PrepareBuilds prepairs the build commands
        #
        #return None in case of error
        ###########

        NumberOfCores = self.DetermineUsedNumberOfCores(NumberOfCores)

        commands = []
        dType = Type.lower()  # dictionary key is lower case
        for build_cfg in build_cfg_list:
            for component in build_cfg:
                for TargetName in build_cfg[component]:
                    BuildTargets = build_cfg[component][TargetName]
                    if (dType in BuildTargets) or (self.BUILD_TYPE_WILDCARD in BuildTargets):
                        if dType in BuildTargets:
                            target_cfg = BuildTargets[dType]
                            if Type == self.BUILD_TYPE_WILDCARD:
                                command_ext = ""
                            else:
                                command_ext = "_" + Type.lower()
                        else:
                            target_cfg = BuildTargets[self.BUILD_TYPE_WILDCARD]
                            command_ext = ""

                        temp_command = {}

                        build_type = target_cfg[self.TARGET_EXECUTE]
                        if (build_type == self.BUILD_SYSTEM_SCONS):
                            if  ((os.path.isfile(os.path.join(target_cfg[self.TARGET_SCONSTRUCT_DIR], "scons.bat")) == 1)
                                 and ((NameFilter == self.BUILD_TYPE_WILDCARD) or (NameFilter in target_cfg[self.TARGET_FILTER] and len(NameFilter) == len(target_cfg[self.TARGET_FILTER])))
                                 and (self.CheckProjectFilter(ProjectFilter, target_cfg[self.TARGET_PRJ_FILTER]))):
                                # cmdline_info = "scons %s"%(TargetName + command_ext + " " + target_cfg[self.TARGET_ATTRIBUTE])

                                attribute = self.ConstructTargetAttribute(NumberOfCores, target_cfg)
                                
                                cmdline_info_pre = r"set component=%s& ..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons_adas_extensions\sconscript_setup.py" % (component)
                                cmdline_info_clean = r"..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons\scons.py %s -c 2>&1" % ((TargetName + command_ext + " " + attribute))
                                cmdline_info = r"..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons\scons.py %s 2>&1" % ((TargetName + command_ext + " " + attribute))
                                cmd_type = self.BUILD_SYSTEM_SCONS
                                temp_command[TargetName] = (cmdline_info, target_cfg[self.TARGET_DESC], target_cfg[self.TARGET_BUILD_LOG], cmd_type, target_cfg[self.TARGET_SCONSTRUCT_DIR], cmdline_info_pre, cmdline_info_clean)
                                commands.append(temp_command)
                        else:
                            if (os.path.isfile(target_cfg[self.TARGET_VCPROJ_FILE]) == 1):
                                build_type = target_cfg[self.TARGET_EXECUTE]
                                if (build_type in SetupVcvars):
                                    build_environment = SetupVcvars[build_type]
                                    if (os.path.isfile(build_environment)):

                                        if ((self.TARGET_FILTER not in target_cfg) or (NameFilter == self.BUILD_TYPE_WILDCARD) or (NameFilter in target_cfg[self.TARGET_FILTER] and len(NameFilter) == len(target_cfg[self.TARGET_FILTER]))
                                            and (self.CheckProjectFilter(ProjectFilter, target_cfg[self.TARGET_PRJ_FILTER]))):
                                            if (build_type == self.BUILD_SYSTEM_MSBUILD):
                                                LogFileName = target_cfg[self.TARGET_BUILD_LOG]
                                                cmdline_info = "call %s & %s /fileLogger /flp:Verbosity=n;LogFile=%s %s %s /p:Configuration=%s" % (build_environment, target_cfg[self.TARGET_EXECUTE], LogFileName, target_cfg[self.TARGET_ATTRIBUTE], target_cfg[self.TARGET_VCPROJ_FILE], Type)
                                                cmd_type = self.BUILD_SYSTEM_MSBUILD
                                            elif (build_type == self.BUILD_SYSTEM_VCBUILD):
                                                cmdline_info = "call %s & %s %s %s %s" % (build_environment, target_cfg[self.TARGET_EXECUTE], target_cfg[self.TARGET_ATTRIBUTE], target_cfg[self.TARGET_VCPROJ_FILE], Type)
                                                cmd_type = self.BUILD_SYSTEM_VCBUILD
                                            else:
                                                self.Log("Error", "Unsupported build type %s for vcproj projects" % build_type)
                                                return None
                                            temp_command[TargetName] = (cmdline_info, target_cfg[self.TARGET_DESC], target_cfg[self.TARGET_BUILD_LOG], cmd_type)
                                            commands.append(temp_command)
                                        else:
                                            self.Log("Debug", "(self.TARGET_FILTER not in target_cfg) = %s" % (self.TARGET_FILTER not in target_cfg))
                                            self.Log("Debug", "(NameFilter == self.BUILD_TYPE_WILDCARD) = %s" % (NameFilter == self.BUILD_TYPE_WILDCARD))
                                            self.Log("Debug", "(NameFilter in target_cfg[self.TARGET_FILTER]) = %s" % (NameFilter in target_cfg[self.TARGET_FILTER]))
                                            self.Log("Debug", "(len(NameFilter) == len(target_cfg[self.TARGET_FILTER])) = %s" % (len(NameFilter) == len(target_cfg[self.TARGET_FILTER])))

                                    else:
                                        self.Log("Error", "%s does not exist for build type %s" % build_environment, build_type)
                                        return None
                                else:
                                    self.Log("Error", "%s does not specify a build environment file" % build_type)
                                    return None

                        # print build information
                        if TargetName in temp_command:
                            self.Log("Debug", "target name:                       " + TargetName)
                            self.Log("Debug", "cmdline_info:                      " + temp_command[TargetName][0])
                            self.Log("Debug", "target_cfg[self.TARGET_DESC]:      " + temp_command[TargetName][1])
                            self.Log("Debug", "target_cfg[self.TARGET_BUILD_LOG]: " + temp_command[TargetName][2])
                            self.Log("Debug", "cmd_type:                          " + temp_command[TargetName][3])
                            if temp_command[TargetName][3] == self.BUILD_SYSTEM_SCONS:
                                self.Log("Debug", "target_cfg[self.TARGET_SCONSTRUCT_DIR]: " + temp_command[TargetName][4])
                                self.Log("Debug", "cmdline_info_pre                      : " + temp_command[TargetName][5])
                                self.Log("Debug", "cmdline_info_clean                    : " + temp_command[TargetName][6])
        if len(commands) > 0:
            return commands
        else:
            return None

    def relpath(self, path, start=os.path.curdir):
        # copy from ntpath.py """
        # Return a relative version of a path"""
        sep = '\\'
        pardir = '..'
        if not path:
            raise ValueError("no path specified")
        start_list = os.path.abspath(start).split(sep)
        path_list = os.path.abspath(path).split(sep)
        if start_list[0].lower() != path_list[0].lower():
            unc_path, rest = os.path.splitunc(path)
            unc_start, rest = os.path.splitunc(start)
            if bool(unc_path) ^ bool(unc_start):
                raise ValueError("Cannot mix UNC and non-UNC paths (%s and %s)"
                                                                    % (path, start))
            else:
                raise ValueError("path is on drive %s, start on drive %s"
                                                    % (path_list[0], start_list[0]))
        # Work out how much of the filepath is shared by start and path.
        for i in range(min(len(start_list), len(path_list))):
            if start_list[i].lower() != path_list[i].lower():
                break
            else:
                i += 1

            rel_list = [pardir] * (len(start_list) - i) + path_list[i:]
        if not rel_list:
            return os.path.curdir
        return os.path.join(*rel_list)

    def ExecuteBuilds(self, build_cmds_list, Rebuild):
        ###########
        #ExecuteBuilds(self,Type,SetupVcvars,build_cfg)
        #
        #Description: ExecuteBuilds prepairs the build commands
        #
        #return None in case of error, otherwise the BuildReport struct
        ###########
        unzip_flag = False
        BuildReport = {}
        BuildReportToDB = {}
        for build_cmds in build_cmds_list:
            for TargetName in sorted(build_cmds.keys()):
                self.Log("Info", "Compiling %s" % TargetName)
                build_successful = True
                scons_build_successful = True

                # check directory where all the logs are stored
                log_dir = os.path.dirname(build_cmds[TargetName][2])

                try:
                    if build_cmds[TargetName][3] == self.BUILD_SYSTEM_SCONS:
                        scons_dir = build_cmds[TargetName][4]
                        # go to directory containing scons.bat
                        os.chdir(scons_dir)

                        # call the unzip only once
                        if unzip_flag == False:
                            self.Log("Info", "Start extracting compilers")
                            cmdline_info = r"..\..\..\02_Development_Tools\ti_tools\unzip_tools\unzip_tools.bat"
                            proc = subprocess.Popen(cmdline_info, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                            out, err = proc.communicate()
                            if proc.returncode != 0:
                                build_successful = False
                                if len(stderr_str) > 0:
                                    self.Log("Error", "Failed to extract compilers")
                                    self.Log("Error", stderr_str.replace('\r\n', ""))
                            unzip_flag = True
                            self.Log("Info", "Stop extracting compilers")

                        # setup component scons environment
                        self.Log("Info", "Setup scons environment")
                        cmdline_info = build_cmds[TargetName][5]
                        proc = subprocess.Popen(cmdline_info, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                        stdout_str, stderr_str = proc.communicate()
                        if proc.returncode != 0:
                            build_successful = False
                            if len(stderr_str) > 0:
                                self.Log("Error", "bad exitcode during: " + cmdline_info )
                                self.Log("Error", stderr_str.replace('\r\n', ""))

                        if Rebuild == True:
                            self.Log("Info", "Full Rebuild running clean")
                            cmdline_info = build_cmds[TargetName][6]
                            proc = subprocess.Popen(cmdline_info, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                            stdout_str, stderr_str = proc.communicate()
                            if proc.returncode != 0:
                                build_successful = False
                                self.Log("Error", "bad exitcode during: " + cmdline_info)
                                if len(stderr_str) > 0:
                                    self.Log("Error", stderr_str.replace('\r\n', ""))

                        self.Log("Info", "Starting build")
                        cmdline_info = build_cmds[TargetName][0]
                        if self.verbose == True:
                            cmdline_info += ' ' + "verbose=1"
                        proc = subprocess.Popen(cmdline_info, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                        stdout_str, stderr_str = proc.communicate()
                        if proc.returncode != 0:
                            build_successful = False
                            scons_build_successful = False
                            self.Log("Error", "bad exitcode during: " + cmdline_info)
                            if len(stderr_str) > 0:
                                self.Log("Error", stderr_str.replace('\r\n', ""))
                        # self.Log("Info","After build1")

                        try:
                            # write log file
                            f = open("sconsbuild.log", 'w')
                            f.write(stdout_str)
                            f.close()

                            if os.path.isdir(log_dir) == False:
                                os.mkdir(log_dir, 0755)

                            # copy sconsbuild.log to prevent being overwritten
                            shutil.copyfile(os.path.join(os.getcwd(), "sconsbuild.log"), build_cmds[TargetName][2])
                            # check the build result
                            # self.Log("Info","After build2")
                            f = open(build_cmds[TargetName][2])
                            s = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
                            if s.find("Build FAILED!!!!") != -1:
                                build_successful = False
                                scons_build_successful = True
                            # self.Log("Info","After log pharse")
                        except:
                            self.Log("Error", "Major error when checking the return from scons scripting")
                    else:
                        # vcbuild & msbuild
                        # WORKAROUND because msbuild don't create missing directory for BuildLog.Log
                        if os.path.isdir(log_dir) == False:
                            os.makedirs(log_dir)

                        cmdline_info = build_cmds[TargetName][0]
                        print "ExecuteBuilds: cmdline_info=%s" % (cmdline_info)
                        proc = subprocess.Popen(cmdline_info, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                        stdout_str, stderr_str = proc.communicate()
                        if proc.returncode != 0:
                            if len(stderr_str) > 0:
                                self.Log("Error", stderr_str.replace('\r\n', ""))
                            build_successful = False
                except (OSError, ValueError), e:
                    self.Log("Error", e)
                    build_successful = False

                # set build report and data base state
                if not TargetName in BuildReport:
                    BuildReport[TargetName] = {}
                BuildReport[TargetName][self.BUILD_REPORT_NAME] = TargetName + " " + build_cmds[TargetName][1]
                BuildReport[TargetName][self.BUILD_REPORT_STATE] = self.BUILD_STATE_OK
                BuildReportToDB[TargetName] = 1

                # if build failed set error state and link to build report
                if build_successful == False:
                    self.Log("Error", "%s compiling error" % TargetName)
                    BuildReport[TargetName][self.BUILD_REPORT_STATE] = self.BUILD_STATE_ERROR
                    # get Build_Report_Path from build_cmds
                    BuildReport[TargetName][self.BUILD_REPORT_LOG] = build_cmds[TargetName][2]
                    # TODO wrong path concat : find better solution perhaps from build_cmds: LogPath is in build_cfg.
                    print "ExecuteBuilds: BuildReport[TargetName][self.BUILD_REPORT_LOG] = %s" % (BuildReport[TargetName][self.BUILD_REPORT_LOG])
                    BuildReportToDB[TargetName] = 0

                if scons_build_successful == False:
                    self.Log("Error", "%s scons scripting error" % TargetName)
                    BuildReport[TargetName][self.BUILD_REPORT_STATE] = self.BUILD_STATE_SCONS_ERROR
                    # get Build_Report_Path from build_cmds
                    BuildReport[TargetName][self.BUILD_REPORT_LOG] = build_cmds[TargetName][2]
                    BuildReportToDB[TargetName] = 0

        if len(BuildReport) > 0:
            return (BuildReport, BuildReportToDB)
        else:
            return None

    def ParseBuildLog(self, build_cmds_list):
        ###########
        #ParseBuildLog(self,build_cmds_list)
        #
        #Description: ParseBuildLog parse the build log file for number of errors and warnings
        #
        #return False in case of error, otherwise True, the eror_warning dict is a class member var
        #return # of errors detected
        ###########
        self._error_warning_dict = {}
        err_cnt = 0
        for build_cmds in build_cmds_list:
            for TargetName in build_cmds:
                # self.Log("Debug",TargetName)
                if (build_cmds[TargetName][3] == self.BUILD_SYSTEM_MSBUILD):
                    #"looking for:     N Warning(s) \n   M Error(s)"
                    error_c = re.compile("\s*(?P<errors>\d+)\sError\(s\)", re.U)
                    warning_c = re.compile("\s*(?P<warnings>\d+)\sWarning\(s\)", re.U)
                elif (build_cmds[TargetName][3] == self.BUILD_SYSTEM_SCONS):
                    #"looking for:     : warning"
                    #"looking for:     : error"
                    error_c = re.compile("(:)\s+(error)", re.U)
                    warning_c = re.compile("(:)\s+(warning)", re.U)
                else:
                    #" looking for:  - N error(s), M warning(s)"
                    error_warning_c = re.compile(".*\s\-\s(?P<errors>\d+)\serror\(s\),\s(?P<warnings>\d+)\swarning\(s\)", re.U)

                if os.path.isfile(build_cmds[TargetName][2]):
                    errors = 0
                    warnings = 0
                    if (build_cmds[TargetName][3] == self.BUILD_SYSTEM_MSBUILD):
                        fp = codecs.open(build_cmds[TargetName][2])
                        str_ = fp.read()
                        error_warnings = re.search(error_c, str_)
                        if error_warnings:
                            errors = error_warnings.group("errors")
                        error_warnings = re.search(warning_c, str_)
                        if error_warnings:
                            warnings = error_warnings.group("warnings")
                    elif (build_cmds[TargetName][3] == self.BUILD_SYSTEM_SCONS):
                        fp = codecs.open(build_cmds[TargetName][2])
                        str_ = fp.readlines()
                        for line_ in str_:
                            # self.Log("Debug",line_)
                            # search for warning and increemnt number of warning if it is found
                            error_warnings = re.search(error_c, line_)
                            if error_warnings:
                                errors += 1
                            # search for error and increemnt number of error if it is found
                            error_warnings = re.search(warning_c, line_)
                            if error_warnings:
                                warnings += 1
                    else:
                        fp = codecs.open(build_cmds[TargetName][2], encoding='utf-16')
                        str_ = fp.read()
                        error_warnings = re.search(error_warning_c, str_)
                        if error_warnings:
                            errors = error_warnings.group("errors")
                            warnings = error_warnings.group("warnings")

                    self.Log("Info", "-------errors & warnings-------")
                    self.Log("Info", build_cmds[TargetName][2])
                    point_to_log_string = None
                    if self._BuildReport[TargetName][self.BUILD_REPORT_STATE] == self.BUILD_STATE_ERROR:
                        self.Log("Info", "!!!COMPILE ERROR!!!")
                        point_to_log_string = "Component %s does not compile, see log %s \n" % ( TargetName,
                                              self._BuildReport[TargetName][self.BUILD_REPORT_LOG])
                        err_cnt += 1

                    elif self._BuildReport[TargetName][self.BUILD_REPORT_STATE] == self.BUILD_STATE_SCONS_ERROR:
                        self.Log("Info", "!!!SCONS SCRIPTING ERROR!!!")
                        point_to_log_string = "Component %s does not compile, see log %s \n" % ( TargetName,
                                              os.path.abspath(os.path.join(self.WorkingDir,
                                              self._BuildReport[TargetName][self.BUILD_REPORT_LOG].replace("..\\", ""))))
                        err_cnt += 1
                    elif self._BuildReport[TargetName][self.BUILD_REPORT_STATE] == self.BUILD_STATE_OK:
                        self.Log("Info", "!!!No Error found!!!")
                    else:
                        self.Log("ERROR", "!!!Unknown Build_Report_State!!!")
                        err_cnt += 1

                    self.Log("Info", "errors = " + str(errors))
                    self.Log("Info", "warnings = " + str(warnings))
                    if point_to_log_string is not None:
                        self.Log("Info", point_to_log_string)

                    if TargetName not in self._error_warning_dict:
                        self._error_warning_dict["%s errors" % TargetName] = errors
                        self._error_warning_dict["%s warnings" % TargetName] = warnings

                    fp.close()
                else:
                    self.Log("Error", "ParseBuildLog: File %s does not exist" % build_cmds[TargetName][2])

        return err_cnt

    def DoBuild(self, MainXmlFilePath, BuildType, SetupVcvars, WorkingDir, NameFilter="*", Rebuild=True, NumberOfCores=None, ProjectFilter=None, verbose=False):
        ###########
        #DoBuild(self)
        #
        #Description: DoBuild compiles all the vs build defined in the build xml files
        #
        #return StartTime, 0 in case of no error
        #return StartTime, error count
        ###########
        self.verbose = verbose
        # debug info vc build environment
        for buildName in SetupVcvars.keys():
            self.Log("Debug", "vc build environment %s: %s" % (buildName, SetupVcvars[buildName]))

        StartTime = 0
        self.WorkingDir = WorkingDir
        # self.Log("Info", "Do build with type %s and filter %s" % (BuildType.lower(), NameFilter))
        self.Log("Info", "Do build with type %s and filter %s" % (BuildType, NameFilter))
        build_cfg = self.DoBuildParseXmlCfg(MainXmlFilePath)
        errors = 0
        if build_cfg is not None:
            # build_cmds = self.PrepareBuilds(BuildType.lower(), NameFilter, SetupVcvars, build_cfg, NumberOfCores, ProjectFilter)
            # msbuild is case sensitive for BuildType: lower() removed
            build_cmds = self.PrepareBuilds(BuildType, NameFilter, SetupVcvars, build_cfg, NumberOfCores, ProjectFilter)
            if build_cmds is not None:
                # print build_cmds
                try:
                    BuildReportToDB = {}
                    StartTime = datetime.today().strftime("%H:%M:%S")
                    self._BuildReport, self._BuildReportToDB = self.ExecuteBuilds(build_cmds, Rebuild)
                    # self.Log("Info","After Build")
                    # parse for compile errors and warnings
                    errors = self.ParseBuildLog(build_cmds)
                    # self.Log("Info","Log Parse")
                    for target in self._BuildReport:
                        if (self._BuildReport[target][self.BUILD_REPORT_STATE] == self.BUILD_STATE_ERROR):
                            self.Log("Error", "Target %s State %s ParseBuildError %i  StartTime=%s" % (
                                target,self.BUILD_STATE_ERROR,errors, StartTime))
                            return (StartTime, 1)
                        elif (self._BuildReport[target][self.BUILD_REPORT_STATE] == self.BUILD_STATE_SCONS_ERROR):
                            self.Log("Error", "Target %s State %s ParseBuildError %i  StartTime=%s" % (
                                target,self.BUILD_STATE_ERROR, errors, StartTime))
                            return (StartTime, 1)

                except (OSError, ValueError), e:
                    self.Log("Error", e)
                    return (StartTime, 1)
        self.Log("Info", "ParseBuildError %i   StartTime=%s" % (errors, StartTime))
        return (StartTime, errors)

    def GetBuildReport(self):
        return (self._BuildReport, self._BuildReportToDB)

    def GetErrorWarinigDict(self):
        return self._error_warning_dict
