###########
# MKS Scripting toolbox

# :org:           Continental AG

###########

import copy
import hashlib
import os
import posixpath as posixpath
import re
import sqlite3
import stat
import sys
import traceback
import xml.dom.minidom
from datetime import datetime, time
# import win32com.client
from optparse import OptionParser

from CLI_tools import cli_proc_handler
from mks_utils import ProgressBar_obj


def formatExceptionInfo(maxTBlevel=5):
    cla, exc, trbk = sys.exc_info()
    excName = cla.__name__
    try:
        excArgs = exc.__dict__["args"]
    except KeyError:
        excArgs = "<no args>"
    excTb = traceback.format_tb(trbk, maxTBlevel)
    return (excName, excArgs, excTb)


def dict_diff(first, second):
    ###########
    # Return a dict of keys that differ with another config object.  If a value is
    # not found in one fo the configs, it will be represented by KEYNOTFOUND.
    #     @param first:   Fist dictionary to diff.
    #     @param second:  Second dicationary to diff.
    #     @return diff:   Dict of Key => (first.val, second.val)
    #
    # TODO: add parameter check
    #
    ###########
    KEYNOTFOUND = '<KEYNOTFOUND>'  # KeyNotFound for dictDiff
    diff = {}
    # Check all keys in first dict
    for key in first.keys():
        if (not second.has_key(key)):
            diff[key] = (first[key], KEYNOTFOUND)
        elif (first[key] != second[key]):
            diff[key] = (first[key], second[key])
    # Check all keys in second dict to find missing
    for key in second.keys():
        if (not first.has_key(key)):
            diff[key] = (KEYNOTFOUND, second[key])
    return diff


def dict_equal(first, second, ckey):
    ###########
    # Return a dict of keys that equals with another config object.  If a value is
    # not found in one fo the configs, it will be represented by KEYNOTFOUND.
    #     @param first:   Fist dictionary to equal.
    #     @param second:  Second dictionary to equal.
    #     @param ckey:    optional additional compare key.
    #     @return equal:   Dict of Key => (first.val, second.val)
    #
    # TODO: add parameter check
    #
    ###########
    KEYNOTFOUND = '<KEYNOTFOUND>'  # KeyNotFound for dictDiff
    equal = {}
    # Check all keys in first dict
    for key in first.keys():
        if (second.has_key(key)) and (first[key] == second[key]):
            if (ckey != None) and (first[key][ckey] == second[key][ckey]):
                print "Key-Val: %s = %s" % (first[key][ckey], second[key][ckey])
                equal[key] = first[key]
            else:
                equal[key] = first[key]

    return equal


def dict_equal_del(first, second, ckey):
    ###########
    # Return a dict of keys that equals with another config object.  If a value is
    # not found in one fo the configs, it will be represented by KEYNOTFOUND.
    #     @param first:   Fist dictionary to equal.
    #     @param second:  Second dictionary to equal.
    #     @param ckey:    optional additional compare key.
    #     @return equal:   Dict of Key => (first.val, second.val)
    #
    # TODO: add parameter check
    #
    ###########
    KEYNOTFOUND = '<KEYNOTFOUND>'  # KeyNotFound for dictDiff
    equal = {}
    # Check all keys in first dict
    # if doubled entry found it we will deleted
    first_orig = copy.deepcopy(first)
    for key in first_orig.keys():
        if (second.has_key(key)) and (first_orig[key] == second[key]):
            if (ckey != None) and (first_orig[key][ckey] == second[key][ckey]):
                print "Deleted Key-Val: %s = %s" % (first_orig[key][ckey], second[key][ckey])
                del first[key]
            else:
                del first[key]

    return equal


def dict_equal_remove(to_be_cleaned, ref):
    ###########
    # Return a dict of keys that equals with another config object.  If a value is
    # not found in one fo the configs, it will be represented by KEYNOTFOUND.
    #     @param to_be_cleaned:   dictionary of entries which shall be removed from dict ref
    #     @param ref:  dicationary which contains .
    #     @return equal:   Dict of Key => (first.val, second.val)
    #
    # TODO: add parameter check
    #
    ###########
    KEYNOTFOUND = '<KEYNOTFOUND>'  # KeyNotFound for dictDiff
    cleaned = {}
    # Check all keys in first dict
    for key in to_be_cleaned.keys():
        if (ref.has_key(key)) and (to_be_cleaned[key] == ref[key]):
            # don't copy double entry
            pass
        else:
            cleaned[key] = to_be_cleaned[key]
    return cleaned


class xml_obj(object):
    def create_a_document(self):
        return xml.dom.minidom.Document()

    def create_a_root_document(self, Name):
        implement = xml.dom.getDOMImplementation()
        return implement.createDocument(None, Name, None)

    def get_a_document(self, name="/tmp/doc.xml"):
        return xml.dom.minidom.parse(name)


class logging_obj(object):
    ###########
    #
    # Description: A logging class write events to file or to stdout
    #
    ###########

    # TODO: Why does the Paramter got an assignment?
    def __init__(self, destination="console", LogType={}, log_file_object=0):
        self.Destination = destination
        self.LogType = LogType
        self.log_file_object = log_file_object

    def __del__(self):
        # close log file
        if (self.log_file_object != 0):
            self.log_file_object.close()

    def SetupLogging(self, FileName, Destination, LogType):
        ###########
        # TODO: add suitable description
        ###########

        # Validate LogType
        error = self.ValidateLogType(LogType)
        if error != 0:
            return error

        self.Destination = Destination
        self.LogType = LogType
        if (Destination == "file"):
            # open log file

            # Make sure that log file is only .txt or .log
            if (FileName[-4:] != '.txt' and FileName[-4:] != '.TXT' and
                        FileName[-4:] != '.log' and FileName[-4:] != '.LOG' and
                        FileName[-4:] != '.xml' and FileName[-4:] != '.XML'):
                error = 1
                print 'Error: Input file must be a .txt or .log file'
                return error
            try:
                # Open logfile, create one if non existing
                self.log_file_object = open(FileName, "w")
                # check if the file is created
                file_exist = os.path.isfile(FileName)
                if file_exist is False:
                    error = 1
            except IOError, OSError:
                print 'Error: Cannot open file, please check if the file name is correct, or if it already exists,' \
                      'it should be readable'
                error = 1
        else:
            self.Destination = ""
        return error

    def ValidateLogType(self, LogType):
        ###########
        # Description: Validate the formatting of LogType
        # Parameter: LogType, which should be in a special Dicy format
        # return either 0 in case validation fails or 1 if it succeeds
        ###########
        error = 0

        # Validate LogType
        # check if the LogType follows required dict format
        if isinstance(LogType, dict):
            for key in LogType:
                if isinstance(key, str):
                    if re.match('^\w+$', key):
                        if not isinstance(LogType[key], int):
                            error = 1
                            print 'Error:Logging Type dict not set correctly, value for each key should be an integer'
                    else:
                        error = 1
                        print 'Error:Logging Type dict not set correctly, key should be alphabetic or alphanumeric'
                else:
                    error = 1
                    print 'Error: Logging Type dict not set correctly, key should be a string'
        else:
            error = 1
            print 'Error: Type error, LogType should be a dictionary'
        return error

    def Log(self, LogTextType, LogText):
        ###########
        # TODO: add suitable description
        ###########
        if self.Destination == "file":
            if self.log_file_object == 0:
                print "Log file error"
            else:
                if ((LogTextType in self.LogType) or (LogTextType == "Error")):
                    self.log_file_object.write("%s Log type %s: %s\n" % (
                        datetime.now().strftime("%Y-%m-%d--%H-%M-%S.%f"), LogTextType, LogText))
                # allow custom logs also on commandline: added LogTextType
                if ((LogTextType in self.LogType) or ("Debug" in self.LogType) or (LogTextType == "Info") or (
                            LogTextType == "Error")):
                    print "%s Log type %s: %s" % (
                        datetime.now().strftime("%Y-%m-%d--%H-%M-%S.%f"), LogTextType, LogText)
        else:
            if ((LogTextType in self.LogType) or (LogTextType == "Error")):
                print "%sLog type %s: %s" % (datetime.now().strftime("%Y-%m-%d--%H-%M-%S.%f"), LogTextType, LogText)


class mks_obj(logging_obj, xml_obj):
    ISSUE_FIELD_TYPE = "Issue Type:"
    ISSUE_FIELD_SUMMARY = "Summary:"
    ISSUE_FIELD_PROJECT = "Project:"
    ISSUE_FIELD_DESCRIPTION = "Description:"
    ISSUE_FIELD_STATE = "State:"

    ISSUE_FIELD_URGENCY = "Urgency:"
    ISSUE_FIELD_IMPORTANCE = "Importance:"
    ISSUE_FIELD_ANALYSIS_DATE = "Analysis Due Date:"

    ISSUE_FIELD_STRUCT_ELEMENT = "Structure Element:"
    ISSUE_FIELD_ANALYSIS_SELECT = "Analysis Selection:"

    ISSUE_FIELD_PLANNED_TARGET_RELEASE = "Planned Target Release:"

    ISSUE_FIELD_CCB_COMMENT = "CCB Comment:"
    ISSUE_FIELD_RO_SELECT = "Realization Order Selection:"

    """
    Description: The mks access class
    """

    def __init__(self):
        logging_obj.__init__(self)
        xml_obj.__init__(self)
        self.Host = ""
        self.Port = ""
        self.ProjectType = "project"
        self.cpid = ""
        self.opt_user = ""
        self.opt_password = ""
        # Flag used for  dryrun of MKS commands e.g. ConfigureSharedSubproject
        self.dryrun = False

        self.cliProcHandler = cli_proc_handler()

    def SetHost(self, Host):
        self.Host = Host

    def SetPort(self, Port):
        self.Port = Port

    def SetCpId(self, CpId):
        self.CpId = CpId

    def SetProjectType(self, ProjectType):
        self.ProjectType = ProjectType

    def Setup(self, Host, Port, CpId, ProjectType, LogFileName, LogDestination, LogType):
        ###########
        # TODO: add suitable description
        ###########
        logging_obj.SetupLogging(self, LogFileName, LogDestination, LogType)
        self.Host = Host
        self.Port = Port
        self.CpId = CpId
        self.ProjectType = ProjectType

    def SetUidPw(self, user, pw):
        if (user != ""):
            self.opt_user = '--user=' + user
            self.opt_password = '--password=' + pw

    def CheckRevDevPathDict(self, rev_list, revision):
        ###########
        #
        # CheckRevDevPathDict(self, rev_list, revision)
        #
        # Description: Check if the rev is already in the dict if not add 1.1 to the revision, and double check the revision if also existing increment it to 2.1 3.1 at the end
        #
        # Parameter: -rev_list
        #            -revision
        #
        # return new revision
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = revision
        if revision in rev_list:
            next_rev = ""
            numbers = revision.split('.')
            for index in range(len(numbers) - 2):
                next_rev += "%s." % numbers[index]
            next_rev += "%d." % (int(numbers[-2]) + 1)
            next_rev += "%s" % (numbers[-1])
            ret_value = self.CheckRevDevPathDict(rev_list, next_rev)

        return ret_value

    def GetAllDevPathes(self, SharedProject, StartDevPath=None):
        ###########
        #
        # GetAllDevPathes(self, SharedProject)
        #
        # Description: Get all the DevPath for the SharedProject
        #
        # Parameter: -SharedProject the path from where the shared project is shared
        #
        # return 0 if no DevPath found in the shared project
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        if StartDevPath == None:
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --project=%s --noacl --noattributes --devpaths --noshowCheckpointDescription --noassociatedIssues' % (
                self.Host, self.Port, SharedProject)
        else:
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --project=%s --devpath=%s --noacl --noattributes --devpaths --noshowCheckpointDescription --noassociatedIssues' % (
                self.Host, self.Port, SharedProject, StartDevPath)

        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str_lines = self.cliProcHandler.getstdout_split()

        # stdout=os.popen(cmdline_info,'r')
        # print stdout.read()
        HasDevPath = 0
        DevPathDict = {}
        rev_list = []
        for line in stdout_str_lines:
            # print line
            if (len(line) > 1):
                # print line
                idx = line.find("Development Paths:")
                none = line.find("none")
                tabs = line.find("    ")
                # print idx
                if ((HasDevPath == 1) and (tabs != -1)):
                    # print line
                    argu = line.split()
                    # build a dictionary with all Defelopment pathes and revision numbers
                    if not argu[0] in DevPathDict:
                        # print SharedProject.getAttribute("CompName")
                        tmp = argu[1].rstrip(')')
                        revision = tmp.lstrip('(') + ".1.1"
                        revision = self.CheckRevDevPathDict(rev_list, revision)
                        rev_list.append(revision)
                        DevPathDict[argu[0]] = revision
                else:
                    HasDevPath = 0
                if ((idx != -1) and (none == -1)):
                    HasDevPath = 1
        if (len(DevPathDict) == 0):
            # print "project has no Development path"
            return ret_value
        else:
            # print DevPathDict[DevPath]
            return DevPathDict

    def GetCurrentDevPath(self, ProjectPath):
        ###########
        #
        # GetCurrentDevPath(self, ProjectPath)
        #
        # Description:    return the current development path from MKS
        #
        # Parameter:      ProjectPath:    Path of project file    e.g. "D:\sandbox\ARS315_01.00.00\project.pj"
        #
        # return:         "0" if fails, otherwise return the current development path or "" if Normal as string
        #
        # Author:         Ilja Hotjakov 03.02.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        DevelopmentPath = ""
        foundFlag = 0

        cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --sandbox=%s --noacl --noattributes --devpaths --noshowCheckpointDescription --noassociatedIssues' % (
            self.Host, self.Port, ProjectPath)
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str_lines = self.cliProcHandler.getstdout_split()

        PjName = 'Development Path: '
        for line in stdout_str_lines:
            # find  Development Path
            if (line.find(PjName) != -1):
                DevelopmentPath = self.extractDevelopmentPathFromStdout(line, PjName)
                foundFlag = 1
                break
            # If normal
            elif (line.find("Development Paths:") != -1):
                foundFlag = 1
                break
            # in case of build config get the dev path of this build config
            elif (line.find("Configuration Path:") != -1):
                temp = line[line.find("#d="):].lstrip("#d=")
                DevelopmentPath = temp[0:temp.find("#")]

                Revision = line[line.find("#b="):].lstrip("#b=")
                print "Revision(Build)=%s" % (Revision)

                foundFlag = 1
                break
        if foundFlag == 1:
            return DevelopmentPath
        else:
            return "0"

    def GetAllLabelsForSharedProject(self, SharedProject, DevPathFilter=None, Labeled=True):
        ###########
        #
        # GetAllLabelsForSharedProject(self, SharedProject, DevPathFilter = None, Labeled = True)
        #
        # Description: Get all the label of the shared projects
        #
        # Parameter: -SharedProject the path from where the shared project is shared
        #            -DevPathFilter filters the labels for a dedicated devpath
        #            -Labeled if true return only labeled revisions
        #
        # return 0 if no label could be found in this shared project
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = self.GetAllLabels(SharedProject, DevPathFilter, Labeled)

        return ret_value

    def GetAllLabels(self, SharedProject, DevPathFilter=None, Labeled=True):
        ###########
        #
        # GetAllLabels(self, SharedProject, DevPathFilter = None, Labeled = True)
        #
        # Description: Get all the label of the shared projects, scan all devpaths for all labels
        #
        # Parameter: -SharedProject the path from where the shared project is shared
        #            -DevPathFilter filters the labels for a dedicated devpath
        #            -Labeled if true return only labeled revisions
        #
        # return {} if no label could be found in this shared project
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = {}

        cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --project=%s --fields=labels,revision' % (
            self.Host, self.Port, SharedProject)
        if Labeled == True:
            cmdline_info += ' --rfilter=labeled'

        if DevPathFilter != None:
            cmdline_info += ' --rfilter=devpath:%s' % DevPathFilter

        # print cmdline_info
        # print SharedProject
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str_lines = self.cliProcHandler.getstdout_split()

        for line in stdout_str_lines:
            line = line.replace('\xff', '')
            # print line
            if (len(line) > 1):
                argu = line.split()
                if (len(argu) > 2):
                    argu[1] = argu[len(argu) - 1]
                    argu[0] = line.replace(argu[1], "")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n", "")
                    # print argu[0]
                    self.Log("Warn", "si viewprojecthistory fields error")
                if (len(argu) > 1):
                    # print argu[0]
                    # print argu[1]
                    ret_value[argu[0]] = argu[1]
                # print "Return value " + ret_value
                if (len(argu) == 1) and 'project.pj' not in line:
                    ret_value["NotKnown::" + argu[0]] = argu[0]
                    # print argu[0]
        # print ret_value
        return ret_value

    def GetRevisionForLabelExt(self, SharedProject, Label):
        ###########
        #
        # GetRevisionForLabelExt(self, SharedProject, Label)
        #
        # Description: Get the revision corresponding to a label scann all development paths of this project for the label
        #
        # Parameter: -SharedProject the path from where the shared project is shared
        #            -Label serach the revision to this label
        #
        # return 0 if label could not be found in this shared project
        #
        # TODO: add parameter check
        #
        ###########
        # ret_value = 0
        # first check for the trunk
        ret_value = self.GetRevisionForLabel(SharedProject, Label)
        if ret_value == 0:
            # Get all the dev pathes of this subproject
            allDevPathes = self.GetAllDevPathes(SharedProject)
            for actDevPath in allDevPathes:
                cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --project=%s --devpath=%s --fields=labels,revision --rfilter=labeled' % (
                    self.Host, self.Port, SharedProject, actDevPath)
                # print SharedProject
                self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
                stdout_str_lines = self.cliProcHandler.getstdout_split()
                # TODO: stdout_str_lines must initiated befor usage
                for line in stdout_str_lines:
                    # print line
                    if (len(line) > 1):
                        argu = line.split()
                        if (len(argu) > 2):
                            argu[1] = argu[len(argu) - 1]
                            argu[0] = line.replace(argu[1], "")
                            argu[0] = argu[0].rstrip()
                            argu[0] = argu[0].replace("\n", "")
                            # print argu[0]
                            self.Log("Warn", "si viewprojecthistory fields error")
                        if (len(argu) > 1):
                            # print argu[0]
                            # print argu[1]
                            # check if unicode
                            try:
                                argu[0].decode('ascii')
                            except UnicodeDecodeError:
                                self.Log("Info", argu[
                                    0] + " is not a ascii-encoded unicode in shared path: " + SharedProject + "! Please rename it")
                            else:
                                # an ascii-encoded unicode string
                                for singleLabel in argu[0].split(','):
                                    if singleLabel == Label:
                                        self.Log("Info", "Label found: %s" % singleLabel)
                                        ret_value = argu[1]
                                        break
        return ret_value

    def GetRevisionForLabel(self, SharedProject, Label):
        ###########
        #
        # GetRevisionForLabel(self, SharedProject, Label)
        #
        # Description: Get the revision corresponding to a label
        #
        # Parameter: -SharedProject the path from where the shared project is shared
        #            -Label serach the revision to this label
        #
        # return 0 if label could not be found in this shared project
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --project=%s --fields=labels,revision --rfilter=labeled' % (
            self.Host, self.Port, SharedProject)
        # print SharedProject
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str_lines = self.cliProcHandler.getstdout_split()
        # print Label
        # TODO: stdout_str_lines must initiated befor usage
        for line in stdout_str_lines:
            # print line
            if (len(line) > 1):
                argu = line.split()
                if (len(argu) > 2):
                    argu[1] = argu[len(argu) - 1]
                    argu[0] = line.replace(argu[1], "")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n", "")
                    # print argu[0]
                    self.Log("Warn", "si viewprojecthistory fields error")
                if (len(argu) > 1):
                    # print argu[0]
                    # print argu[1]

                    # check if unicode
                    try:
                        argu[0].decode('ascii')
                    except UnicodeDecodeError:
                        self.Log("Info", argu[
                            0] + " is not a ascii-encoded unicode in shared path: " + SharedProject + "! Please rename it")
                    else:
                        # an ascii-encoded unicode string
                        for singleLabel in argu[0].split(','):
                            if singleLabel == Label:
                                self.Log("Info", "Label found: %s" % singleLabel)
                                ret_value = argu[1]

                                break
                                # print "Return value " + ret_value
        return ret_value

    def GetLabelForRevision(self, Project, Sandbox, Revision):
        ###########
        #
        # GetLabelForRevision(Project, Revision)
        #
        # Description: Get the label corresponding to a revision
        #
        # Parameter: -Project the mks path of the project where the scan should start
        #            -Sandbox the path and file name of the sandbox pj File
        #            -Revision serach the label to this revision
        #
        # return:   0 if revision could not be found in this shared project, 1 if some error occour otherwise return Label
        #
        # TODO: add parameter check
        #
        ###########

        if (Sandbox != ""):
            cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --sandbox=%s --fields=labels,revision --rfilter=labeled' % (
                self.Host, self.Port, Sandbox)
        elif (Project != ""):
            cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --project=%s --fields=labels,revision --rfilter=labeled' % (
                self.Host, self.Port, Project)
        else:
            print "GetLabelForRevision Input Error: Projectpath: " + Project + " or Sandboxpath: " + Sandbox + "not found"
            self.Log("Info",
                     " GetLabelForRevision Input Error: Projectpath: " + Project + " or Sandboxpath: " + Sandbox + "not found")
            return 1

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        stdout_str_lines = self.cliProcHandler.getstdout_split()
        for line in stdout_str_lines:
            if (len(line) > 1):
                argu = line.split()
                if (len(argu) > 2):
                    argu[1] = argu[len(argu) - 1]
                    argu[0] = line.replace(argu[1], "")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n", "")
                    self.Log("Warn", "si viewprojecthistory fields error")
                if (len(argu) > 1):
                    if (argu[1] == Revision):
                        ret_value = argu[0]
                        self.Log("INFO", "but Label: %s could be extracted " % ret_value)
                        return ret_value
        return 0

    def GetLabelForRevisionWithAllLabelsDict(self, Project, Sandbox, Revision, retGetAllLabelsDict):
        ###########
        #
        # GetLabelForRevisionWithAllLabelsDict(self, Project, Sandbox, Revision, retGetAllLabelsDict)
        #
        # Description:  Get the label corresponding to a revision and save all labels with revision to global Dictionary(e.g. self.retGetAllLabelsDict)
        #
        # Parameter:    Project:                The mks path of the project where the scann should start
        #               Sandbox:                The path and file name of the sandbox pj File
        #               Revision:               Serach the label to this revision
        #               retGetAllLabelsDict:    Dictionary with all found Labels
        #
        # return:       0 if revision could not be found in this shared project, 1 if some error ocour otherwise return Label
        #
        # TODO: add parameter check
        #
        ###########

        ret_value = 0

        if (Sandbox != ""):
            cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --sandbox=%s --fields=labels,revision --rfilter=labeled' % (
                self.Host, self.Port, Sandbox)
        elif (Project != ""):
            cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --project=%s --fields=labels,revision --rfilter=labeled' % (
                self.Host, self.Port, Project)
        else:
            print "GetLabelForRevisionWithAllLabelsDict Input Error: Projectpath: " + Project + " or Sandboxpath: " + Sandbox + "not found"
            self.Log("Info",
                     " GetLabelForRevisionWithAllLabelsDict Input Error: Projectpath: " + Project + " or Sandboxpath: " + Sandbox + "not found")
            return 1

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        stdout_str_lines = self.cliProcHandler.getstdout_split()
        for line in stdout_str_lines:
            if (len(line) > 1):
                argu = line.split()
                if (len(argu) > 2):
                    argu[1] = argu[len(argu) - 1]
                    argu[0] = line.replace(argu[1], "")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n", "")
                    self.Log("Warn", "si viewprojecthistory fields error")
                if (len(argu) > 1):
                    label = argu[0]
                    revisionNumber = argu[1]

                    # If checkpoint has several labels, they are connected via comma in one string (e.g. label1,label2)
                    # in one entry
                    # But all(!) values of entry have to be added to dictionary
                    for singleLabel in label.split(','):
                        # save the Labels with Revision in Dictionary
                        retGetAllLabelsDict[singleLabel] = revisionNumber

                    # Whole entry in one string (e.g. 'label1,label2') has to be returned to write it into xml-file
                    if revisionNumber == Revision:
                        ret_value = label

        return ret_value

    def GetProjectView(self, ProjectPath, CheckpointRevision=None, DevPath=None):
        ###########
        #
        # GetProjectView(self, ProjectPath, CheckpointRevision)
        #
        # Description: Get the recursive project view of a project
        #
        # Parameter: -ProjectPath: the MKS path of the project
        #            -CheckpointRevision: the checkpoint of the project
        #            -DevPath: DevelopmentPath of the project
        #
        # return none if an error occures otherwise the project view
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = None
        if DevPath != None:
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --project=%s --fields=name,type,memberrev --norecurse --devpath=%s ' % (
                self.Host, self.Port, ProjectPath, DevPath)
        elif CheckpointRevision != None:
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --project=%s --fields=name,type,memberrev --norecurse --projectRevision=%s ' % (
                self.Host, self.Port, ProjectPath, CheckpointRevision)
            # print cmdline_info
        else:
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --project=%s --fields=name,type,memberrev --norecurse' % (
                self.Host, self.Port, ProjectPath)
            # print cmdline_info
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return None
        return self.cliProcHandler.getstdout_split()

    def GetProjectMemberInfo(self, ProjectPath, Member, Revision):
        ###########
        #
        # GetProjectMemberInfo(self, ProjectPath, Member, Revision)
        #
        # Description: Get the Project member revision info
        #
        # Parameter: -ProjectPath the MKS path of the project
        #            -Member the member name
        #            -Revision the member revision
        #
        # return none if no member info could be extracted, otherwise return the member info
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = None
        cmdline_info = 'si revisioninfo --batch --hostname=%s --port=%s --project=%s --nolabels --nolocate --revision=%s %s' % (
            self.Host, self.Port, ProjectPath, Revision, Member)

        # print cmdline_info
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str_lines = self.cliProcHandler.getstdout_split()
        values = {}
        line_no = 0
        for line in stdout_str_lines:
            if line.find("Change Package:") != -1:
                values["cpid"] = stdout_str_lines[line_no + 1].split(':')[1].strip()
            if line.find("Change Package :") != -1:
                values["cpid"] = line.split(':')[1].strip()
            if line.find("Summary:") != -1:
                values["summary"] = line.replace("Summary:", "").strip()
            line_no += 1
        if len(values) > 0:
            ret_value = values
        return ret_value

    def GetMemberRevisionSandbox(self, MemberPath):
        ###########
        #
        # GetMemberRevisionSandbox (self, MemberPath)
        #
        # Description: Return member revision of the sandbox member
        #
        # Parameter: MemberPath - Sanbox loacation of the member
        #
        # return 0, if the path does not exist
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        workingDir = os.getcwd()
        base_path = MemberPath[:MemberPath.rfind('\\')]
        os.chdir(base_path)
        cmdline_info = 'si viewsandbox --fields=memberrev %s' % (MemberPath)
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        output = self.cliProcHandler.getstdout_split()

        if len(output) > 0:
            MemberRevision = output[0]
            os.chdir(workingDir)
            return MemberRevision
        else:
            os.chdir(workingDir)
            return ret_value

    def CheckDevPathName(self, SharedProject, DevPath):
        ###########
        #
        # CheckDevPathName(self, SharedProject, DevPath)
        #
        # Description: Check if the DevPath exisits in the SharedProject
        #
        # Parameter: -SharedProject the path from where the shared project is shared
        #            -DevPath the name of the DevelopmentPath which should be checked
        #
        # return 0 if the DevPath does not exist in the shared project
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        # cmdline_info='si projectinfo --hostname=%s --port=%s --project=%s --noacl --noattributes --devpaths --noshowCheckpointDescription --noassociatedIssues' %(self.Host, self.Port, SharedProject)
        cmdline_info = 'si viewprojecthistory --batch --hostname=%s --port=%s --project=%s --fields=revision --rfilter=devpath:%s' % (
            self.Host, self.Port, SharedProject, DevPath)
        # print cmdline_info
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str_lines = self.cliProcHandler.getstdout_split()
        # print stdout.read()
        HasDevPath = 0
        DevPathDict = {}
        for line in stdout_str_lines:
            # print line
            if (len(line) >= 2):
                # print line
                DevPathDict[DevPath] = line
        if (len(DevPathDict) == 0):
            # print "project has no Development path"
            return ret_value
        if (DevPath in DevPathDict):
            # print DevPath
            # print DevPathDict[DevPath]
            return DevPathDict[DevPath]
        else:
            # print "Error: Development path %s does not exist for %s, check development path label" %(DevPath, SharedProject)
            return ret_value

    def GetProjectPath(self, ProjectType, SharedPath):
        ###########
        #
        # GetProjectPath(self, ProjectType, SharedPath)
        #
        # Description: Get the Project path of the shared
        #
        # Parameter: -ProjectType the type of the project, sandbox or project scan
        #            -SharedPath the path where the shared project is shared to
        #
        # return 0 if no ProjectPath found otherwise the ProjectPath
        #
        # TODO: add parameter check
        #
        ###########
        if (ProjectType == "sandbox"):
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --sandbox=%s --noacl --noattributes --nodevpaths --noshowCheckpointDescription --noassociatedIssues' % (
                self.Host, self.Port, SharedPath)
        elif (ProjectType == "project"):
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --project=%s --noacl --noattributes --nodevpaths --noshowCheckpointDescription --noassociatedIssues' % (
                self.Host, self.Port, SharedPath)

        # TODO: cmdline_info must initiated befor usage
        self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_info, stderr = self.cliProcHandler.getcommunicate()
        return self.extractProjectPathFromStdoutByProjectTypeName(stdout_info)

    def extractProjectPathFromStdoutByProjectTypeName(self, stdout_info):
        if not isinstance(stdout_info, (str, unicode)):
            return 0
        if (len(stdout_info) > 0):
            PjName = 'Variant Project Name: '
            if (stdout_info.find(PjName) != -1):
                return self.extractProjectPathFromStdout(stdout_info, PjName)

            PjName = 'Build Project Name: '
            if (stdout_info.find(PjName) != -1):
                return self.extractProjectPathFromStdout(stdout_info, PjName)

            PjName = 'Project Name: '
            if (stdout_info.find(PjName) != -1):
                return self.extractProjectPathFromStdout(stdout_info, PjName)

        # Calling function expects 0 for invalid case
        return 0

    def extractProjectPathFromStdout(self, stdout_info, ProjectTypeName):
        if not isinstance(stdout_info, (str, unicode)) or not isinstance(ProjectTypeName, (str, unicode)):
            return 1
        return stdout_info[:stdout_info.find(".pj") + 3].replace(ProjectTypeName, "")

    def extractDevelopmentPathFromStdout(self, stdout_info, ProjectTypeName):
        if not isinstance(stdout_info, (str, unicode)) or not isinstance(ProjectTypeName, (str, unicode)):
            return 1
        return stdout_info.replace(ProjectTypeName, "")

    def GetSharedFromPath(self, ProjectType, ProjectPath):
        ###########
        #
        # GetSharedFromPath(self, ProjectType, ProjectPath)
        #
        # Description: Get the path from where the shared project in ProjectPath is shared
        #
        # Parameter: -ProjectType the type of the project, sandbox or project scan
        #            -ProjectPath the path where the shared project is shared to
        #
        # return:     0 if no Path found, 1 if error occur otherwise the Path from where it is shared
        #
        # TODO: add parameter check
        #
        ###########
        if (ProjectType == "sandbox"):
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --sandbox=%s --noacl --noattributes --nodevpaths --noshowCheckpointDescription --noassociatedIssues' % (
                self.Host, self.Port, ProjectPath)
        elif (ProjectType == "project"):
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --project=%s --noacl --noattributes --nodevpaths --noshowCheckpointDescription --noassociatedIssues' % (
                self.Host, self.Port, ProjectPath)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
        if len(stderr_str) != 0:
            self.Log("Debug", cmdline_info)
            self.Log("Info", stderr_str.rstrip('\r\n'))
            if (stderr_str.find("could not be located on the server") != -1):
                self.Log("Info", " please add this project to normal of your project e.g. ARS301 or ARS400..")
                return 0
        if (len(stdout_str) > 0):
            stdout_str_lines = stdout_str.splitlines()
            SharedPath = 0
            # find  Shared From
            # Integrity 10.6: "Shared From: "  ==> "Repository Location: "
            # SharedPath = stdout_str_lines[1].replace("Shared From: ", "")
            SharedPath = stdout_str_lines[1].replace("Repository Location: ", "")
            SharedPath = SharedPath.replace('\n', "")
            return SharedPath
        else:
            return 0
        return 1

    def GetRevisionSharedAndPathFromSandboxPath(self, SandboxPath):
        ###########
        #
        # GetSharedAndPathFromSandboxPath(self, SandboxPath)
        #
        # Description:    Get the revision, projectpath and  path from where the shared project in SandboxPath is shared
        #
        # Parameter:      SharedPath:    The path where the shared project is shared to    e.g. /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnviromentModel/03_Design/01_Supporting_Documents/em/project.pj
        #
        # Return:         0 if no Path found, 1 if error occur otherwise the dictionary with projectpath and sharedpath
        #
        # Author:         Ilja Hotjakov 19.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        sharedpath = ""
        projectpath = ""
        revision = ""
        retDict = {}

        cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --sandbox=%s --noacl --noattributes --nodevpaths --noshowCheckpointDescription --noassociatedIssues' % (
            self.Host, self.Port, SandboxPath)
        # print "==> cmdline_info: %s" % (cmdline_info)
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        stdout_str_lines = self.cliProcHandler.getstdout_split()
        if (len(stdout_str_lines) > 0):
            found = 0
            for line in stdout_str_lines:
                if found == 3:
                    break
                elif (line.find("Project Name:") != -1):
                    tempprojectpath = line.split(" ")
                    projectpath = tempprojectpath[-1]
                    found += 1
                # Integrity 10.6: "Shared From: "  ==> "Repository Location: "
                # elif (line.find("Shared From:") != -1):
                elif (line.find("Repository Location:") != -1):
                    tempsharedpath = line.split(" ")
                    sharedpath = tempsharedpath[-1]
                    found += 1
                # Integrity 10.6: "Revision:"  ==> "Last Checkpoint:"
                # elif (line.find("Revision:") != -1):
                elif (line.find("Last Checkpoint:") != -1):
                    temprevision = line.split(" ")
                    revision = temprevision[-1]
                    found += 1

            if projectpath != "":
                retDict[projectpath] = {}
                retDict[projectpath]["SharedPath"] = sharedpath
                retDict[projectpath]["Revision"] = revision
                # print "==> Revision %s" % (retDict[projectpath]["Revision"])
            else:  # no projectpath found
                retDict[0] = {}
                retDict[0]["SharedPath"] = sharedpath
                retDict[0]["Revision"] = revision

        if len(retDict) > 0:
            return retDict
        else:
            return 0

    def CheckpointProject(self, ProjectType, ProjectPath, ActDevPath, Description, LabelMembers, Label):
        ###########
        #
        # CheckpointProject(self, ProjectType, ProjectPath)
        #
        # Description: Checkpoint the mks project
        #
        # Parameter: -ProjectType the type of the project, sandbox or project scan
        #            -ProjectPath the path of the project to checkpoint
        #            -ActDevPath the Development path e.g SMR200_SRR-BSD_G30_A1_V2
        #
        # return 0 if no Path found otherwise the Path from where it is shared
        #
        # TODO: add parameter check
        #
        ###########
        if (ProjectType == "sandbox"):
            cmdline_info = 'si checkpoint --checkpointUnchangedSubprojects --batch --hostname=%s --port=%s %s %s --sandbox=%s --label=%s --description=%s --forceConfirm=no --nolabelMembers' % (
                self.Host, self.Port, self.opt_user, self.opt_password, ProjectPath, Label, Description)
        if (ProjectType == "project"):
            cmdline_info = 'si checkpoint --checkpointUnchangedSubprojects --batch --hostname=%s --port=%s %s %s --project=%s --devpath=%s --label=%s --description=%s --forceConfirm=no --nolabelMembers' % (
                self.Host, self.Port, self.opt_user, self.opt_password, ProjectPath, ActDevPath, Label, Description)

        # TODO: cmdline_info must initiated befor usage
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1

        # ATTENTION: current status of checkpointing will be printed out on error-channel...
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
        self.Log("Info", stderr_str)

        if (ProjectType == "sandbox") or (ProjectType == "project"):
            if (LabelMembers == True):
                self.Log("Info", "Start Labeling members, All members shall be labelled")
                self.AddMemberLabel(ProjectType, ProjectPath, ActDevPath, Label)
                self.Log("Info", "Stop Labeling members, All members labelled")
            elif (LabelMembers == False):
                self.Log("Info", "Labeling members is skipped, because of disabled selection.")
        return 0

    def AddMemberLabel(self, ProjectType, ProjectPath, ActDevPath, Label, Recurse=True):
        ###########
        #
        # AddMemberLabel(self, ProjectType, ProjectPath, ActDevPath, Label)
        #
        # Description: Add label to all memebers of the project or sandbox
        #
        # Parameter: -ProjectType the type of the project, sandbox or project scan
        #            -ProjectPath the path of the project to checkpoint
        #            -ActDevPath the Development path e.g SMR200_SRR-BSD_G30_A1_V2
        #            -Label the name of the label, which normally is the same as the checkpoint
        #            -Recurse if the label should be added recursive.
        #
        # return 0 if no Path found otherwise the Path from where it is shared
        #
        # TODO: add parameter check
        #
        ###########
        self.Log("Info", "Labelling Members")
        if (ProjectType == "sandbox"):
            cmdline_info = 'si addlabel --batch --hostname=%s --port=%s %s %s --sandbox=%s --label=%s --forceConfirm=no ' % (
                self.Host, self.Port, self.opt_user, self.opt_password, ProjectPath, Label)
        if (ProjectType == "project"):
            cmdline_info = 'si addlabel --batch --hostname=%s --port=%s %s %s --project=%s --devpath=%s --label=%s --forceConfirm=no ' % (
                self.Host, self.Port, self.opt_user, self.opt_password, ProjectPath, ActDevPath, Label)

        if Recurse == True:
            # TODO: cmdline_info must initiated befor usage
            cmdline_info += '--recurse '

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1

        self.Log("Info", "Labelling Members was successful")
        return 0

    def CreateSandbox(self, SandboxPath, ProjectPath, ActDevPath, SharedFlag=False, BuildSBFlag=False):
        print ("Function CreateSandbox() has been wiped out. Please send email to 07_LU_MG_ADAS_FUNC_INTEGRATION "
               "if you need further assistance.")

    def CreateSandboxConfPath(self, SandboxPath, ProjectPath):
        print (
            "Function CreateSandboxConfPath() has been wiped out. Please send email to 07_LU_MG_ADAS_FUNC_INTEGRATION "
            "if you need further assistance.")

    def DropSandbox(self, SandboxPath):
        print (
            "Function DropSandbox() has been wiped out. Please send email to 07_LU_MG_ADAS_FUNC_INTEGRATION "
            "if you need further assistance.")

    def CheckOutProject(self, SandboxPath):
        print (
            "Function CheckOutProject() has been wiped out. Please send email to 07_LU_MG_ADAS_FUNC_INTEGRATION "
            "if you need further assistance.")

    def ResyncSandbox(self, SandboxPath):
        print (
            "Function ResyncSandbox() has been wiped out. Please send email to 07_LU_MG_ADAS_FUNC_INTEGRATION "
            "if you need further assistance.")

    def ConfigureSharedSubproject(self, SharedPath, ActDevPath, Type, Revision, DevPathName):
        ###########
        #
        # ConfigureSharedSubproject(self, SharedPath, Type, Revision, DevPathName )
        #
        # Description: Configures the shared sub project
        #
        # Parameter: -SharedPath the path where the shared project is shared to
        #            -ActDevPath the dev path of the project where the shared project is shared to
        #            -Type the type of the config (normal,variant or build)
        #            -Revision needed for build type
        #            -DevPathName needed for variant type
        #
        # return 0 if config was successful and 1 if configuration fails and 2 if the Error Massage "Please try again later" occur
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0

        if (Type == "variant") and (DevPathName == ""):
            self.Log("Error", "Config shared sub project error DevPathName not specified for path: " + SharedPath)
            return 1
        if (Type == "build") and (Revision == ""):
            self.Log("Error", "Config shared sub project error Revision not specified for path: " + SharedPath)
            return 1

        # go one directory back to get the base directory of the shared sub project
        slash = SharedPath.rfind('/')
        temp = SharedPath[:slash]
        slash2 = temp.rfind('/')
        # Currently it is enforced that the BaseProject ends with 'project.pj'. Previusly it was assumed that it has the same pj file as the shared path
        # TODO: Make it more general!
        BaseProject = ('%s%s') % (SharedPath[:slash2], '/project.pj')

        cmdline_info = ""
        if (ActDevPath == ""):
            if (Type == "normal"):
                cmdline_info = 'si configuresubproject --batch --hostname=%s --port=%s %s %s --cpid=%s --project=%s --type=normal --forceConfirm=no --quiet %s' % (
                    self.Host, self.Port, self.opt_user, self.opt_password, self.CpId, BaseProject, SharedPath)
            elif (Type == "variant"):
                cmdline_info = 'si configuresubproject --batch --hostname=%s --port=%s %s %s --cpid=%s --project=%s --variant=%s --type=variant --forceConfirm=no --quiet %s' % (
                    self.Host, self.Port, self.opt_user, self.opt_password, self.CpId, BaseProject, DevPathName,
                    SharedPath)
            elif (Type == "build"):
                cmdline_info = 'si configuresubproject --batch --hostname=%s --port=%s %s %s --cpid=%s --project=%s --subprojectRevision=%s --type=build --forceConfirm=no --quiet %s' % (
                    self.Host, self.Port, self.opt_user, self.opt_password, self.CpId, BaseProject, Revision,
                    SharedPath)
        else:
            if (Type == "normal"):
                cmdline_info = 'si configuresubproject --batch --hostname=%s --port=%s %s %s --cpid=%s --project=%s --type=normal --forceConfirm=no --devpath=%s --quiet %s' % (
                    self.Host, self.Port, self.opt_user, self.opt_password, self.CpId, BaseProject, ActDevPath,
                    SharedPath)
            elif (Type == "variant"):
                cmdline_info = 'si configuresubproject --batch --hostname=%s --port=%s %s %s --cpid=%s --project=%s --variant=%s --type=variant --forceConfirm=no --devpath=%s --quiet %s' % (
                    self.Host, self.Port, self.opt_user, self.opt_password, self.CpId, BaseProject, DevPathName,
                    ActDevPath,
                    SharedPath)
            elif (Type == "build"):
                cmdline_info = 'si configuresubproject --batch --hostname=%s --port=%s %s %s --cpid=%s --project=%s --subprojectRevision=%s --type=build --forceConfirm=no --devpath=%s --quiet %s' % (
                    self.Host, self.Port, self.opt_user, self.opt_password, self.CpId, BaseProject, Revision,
                    ActDevPath,
                    SharedPath)
        # print cmdline_info
        if self.dryrun:
            self.Log("Info", "Type=%s : cmdline_info=%s" % (Type, cmdline_info))
        else:
            retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
            if retval != 0:
                return 1
        return 0

    def IsSharedProjectAlreadyConfigured(self, ProjectPath, ActDevPath, Type, Revision, VariantDevPath):
        ###########
        #
        # IsSharedProjectAlreadyConfigured(self, ProjectPath, ActDevPath, Type, Revision, VariantDevPath )
        #
        # Description:    Check if the SharedProject alredy configured
        #
        # Parameter:      ProjectPath:       The path where the shared project is shared to                               e.g. /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/03_Design/01_Supporting_Documents/fct/project.pj
        #                 ActDevPath:        The development path of the project where the shared project is shared to    e.g. ARS301_01.00.00
        #                 Type:              The type of the config                                                       e.g. normal / variant / build
        #                 Revision:          The Revision which is needed for build type                                  e.g. 1.1.1.54
        #                 VariantDevPath:    The development path which is needed for variant type                        e.g. FCT_ARS301
        #
        # Return:         if fails return the "0"
        #
        # Author:         Ilja Hotjakov 03.04.2012
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = "0"

        if (Type == "variant") and (VariantDevPath == ""):
            self.Log("Error", "Config shared sub project error VariantDevPath not specified")
            return ret_value
        if (Type == "build") and (Revision == ""):
            self.Log("Error", "Config shared sub project error Revision not specified")
            return ret_value

        if (ProjectPath != ""):
            if (not ProjectPath in self.PreConfigSharedProjectDict):
                return False
            else:
                if (Type != self.PreConfigSharedProjectDict[ProjectPath]["Type"]):
                    return False
                elif (Type == "build" and Revision != self.PreConfigSharedProjectDict[ProjectPath]["Revision"]):
                    return False
                elif (Type == "variant" and VariantDevPath != self.PreConfigSharedProjectDict[ProjectPath]["Label"]):
                    return False
                else:
                    ret_value = True

        return ret_value

    def RenameCheckpoint(self, ProjectPath, OldLabel, NewLabel):
        ###########
        #
        # RenameCheckpoint(self, ProjectPath, OldLabel, NewLabel )
        #
        # Description: Configures the shared sub project
        #
        # Parameter: -ProjectPath the path of the project that should be renamed
        #            -OldLabel the old label name
        #            -NewLabel the new label name
        #
        # return 0 config was succesfull and 1 if not
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0

        if (NewLabel != ""):
            ChangeRevision = self.GetRevisionForLabel(ProjectPath, OldLabel)

        # print "Changed Revision %s"%(ChangeRevision)
        # TODO: ChangeRevision must initiated befor usage
        if (ChangeRevision == 0):
            self.Log("Error", "OldLabel not found for project %s" % (ProjectPath))
            return 1

        # delete the old label
        cmdline_info = 'si deleteprojectlabel --batch --hostname=%s --port=%s --project=%s --label=%s --forceConfirm=no --quiet' % (
            self.Host, self.Port, ProjectPath, OldLabel)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1

        if (NewLabel == ""):
            self.Log("Info", "Renamed project %s with OldLabel %s to NewLabel %s " % (ProjectPath, OldLabel, NewLabel))
            return 0

        # add new label
        cmdline_info = 'si addprojectlabel --batch --hostname=%s --port=%s --project=%s --projectRevision=%s --label=%s --forceConfirm=no --quiet' % (
            self.Host, self.Port, ProjectPath, ChangeRevision, NewLabel)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1

        self.Log("Info", "Renamed project %s with OldLabel %s and revision %s to NewLabel %s " % (
            ProjectPath, OldLabel, ChangeRevision, NewLabel))
        return 0

    def CheckStateOfIssue(self, IssueID, WithType, IssueNotInState={}):
        ###########
        #
        # GetRelationListForIssue(self,  IssueID, WithType, IssueNotInState)
        #
        # Description: Return 1 if the definition mach
        #
        # Parameter: -IssueID the id of the issue
        #            -WithType the type of the issue
        #            -IssueNotInState not wanted states of the issue
        #
        # return 0 if no match founde otherwise 1
        ###########
        cmdline_info = 'im viewissue --batch --hostname=%s --port=%s --quiet %s' % (self.Host, self.Port, IssueID)
        TypeFound = False
        IDs = None
        IssueState = None

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1

        stdout_str = self.cliProcHandler.getstdout_split()

        for line in stdout_str:
            if (line.find("Type: ") != -1) and (line.find(WithType) != -1):
                TypeFound = True
            if (line.find("State: ") != -1):
                IssueState = line.replace("State: ", "")

        if (TypeFound is False):
            self.Log("Info", "Issue type AD_Release not found")
        if (IssueState in IssueNotInState):
            self.Log("Info", "Issue state is one of this not wanted states: %s" % (IssueNotInState))

        if (TypeFound is True) and (IssueState not in IssueNotInState):
            return 1
        return 0

    def GetRelationListForIssue(self, IssueID, WithType, IssueNotInState={}):
        ###########
        #
        # GetRelationListForIssue(self,  IssueID, WithType, IssueNotInState)
        #
        # Description: Return the relations(list) for issue
        #
        # Parameter: -IssueID the id of the issue
        #            -WithType the type of the issue
        #            -IssueNotInState not wanted states of the issue
        #
        # return 0 no relations are found otherwise the relations(list) issues
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        cmdline_info = 'im viewissue --batch --hostname=%s --port=%s %s' % (self.Host, self.Port, IssueID)
        TypeFound = False
        IDs = None
        IssueState = None

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 0
        stdout_str = self.cliProcHandler.getstdout_split()

        for line in stdout_str:
            if (line.find("Type: ") != -1) and (line.find(WithType) != -1):
                TypeFound = True
            # print line
            if (line.find("AD_c.o. CR(s) / FR(s) / SR(s): ") != -1):
                removeFieldName = line.replace("AD_c.o. CR(s) / FR(s) / SR(s): ", "")
                removeFieldName = removeFieldName.replace(" ", "")
                IDs = removeFieldName.split(',')
            elif (line.find("AD_c.o. Task(s): ") != -1):
                removeFieldName = line.replace("AD_c.o. Task(s): ", "")
                removeFieldName = removeFieldName.replace(" ", "")
                IDs = removeFieldName.split(',')
            if (line.find("State: ") != -1):
                IssueState = line.replace("State: ", "")

        if (IDs == None) or (len(IDs) == 0):
            self.Log("Info", "No related isssues found for issue %s" % (IssueID))
        # if (IssueState in IssueNotInState):
        # self.Log("Info", "Issue state is one of this not wonted states: %s"%(IssueNotInState))

        if (TypeFound == True) and (len(IDs) > 0) and (IssueState not in IssueNotInState):
            ret_value = IDs

        return 0

    def GetFieldOfIssue(self, IssueID, FieldName):
        ###########
        #
        # GetRelationListForIssue(self,  IssueID, FieldName)
        #
        # Description: Return the FieldValues of the issue
        #
        # Parameter: -IssueID the id of the issue
        #            -FieldName the name of the field
        #
        # return 0 if field name not found otherwise the assigned value
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        cmdline_info = 'im viewissue --batch --hostname=%s --port=%s %s' % (self.Host, self.Port, IssueID)
        FieldFound = False

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 0
        stdout_str = self.cliProcHandler.getstdout_split()
        for line in stdout_str:
            # print line
            if (line.find(FieldName) != -1):
                removeFieldName = line.replace(FieldName, "")
                return removeFieldName

        return 0

    def UpdatedRelationOfIssue(self, IssueID, FieldName, IssueIDToAdd):
        ###########
        #
        # UpdatedRelationOfIssue(self,  IssueID, FieldName, IssueIDToAdd)
        #
        # Description: Update the relations of the defined issue
        #
        # Parameter: -IssueID the id of the issue
        #            -FieldName the name of the field that should be updated
        #            -IssueIDToAdd the issue id the shuld be added as relation to the Issue ID
        #
        # return 0 update faild otherwise 1
        #
        # TODO: add parameter check
        #
        ###########
        cmdline_info = 'im editissue --batch --hostname=%s --port=%s --addRelationships="%s:%s" --quiet %s' % (
            self.Host, self.Port, FieldName, IssueIDToAdd, IssueID)
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        # yes the return values are switched to normal logic, because of previous implementation
        if retval != 0:
            return 0
        return 1

    def GetIssueView(self, IssueID):
        ###########
        #
        # GetIssueView(self,  IssueID)
        #
        # Description: Get the issue view containing all information from the issue
        #
        # Parameter: -IssueID the id of the issue
        #
        # return 0 if fails to get it, otherwise return the issue
        #
        # TODO: add parameter check
        #
        ###########
        cmdline_info = 'im viewissue --batch --hostname=%s --port=%s %s' % (self.Host, self.Port, IssueID)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return {}
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
        return stdout_str

    def AddIssue(self, summary, project, issue_type, description):
        ###########
        #
        # AddIssue(self, summary, project, issue_type, description)
        #
        # Description: Add the issue
        #
        # Parameter: - summary: summary of the issue
        #            - project: the asigned project of the issue
        #            - issue_type: type of the issue
        #            - description: the description of the issue
        #
        # return None if fails, otherwise return the issue id
        #
        # TODO: add parameter check
        # TODO: project check for valid values
        # TODO: summary must be longer than 1 char
        # TODO: description must be longer than 1 char
        # TODO: issue_type check for "Change Request", "Feature Request", "Problem Report"
        #
        ###########
        ret_value = {}
        cmdline_info = 'im createissue --batch --hostname=%s --port=%s --type=Issue ' % (self.Host, self.Port)
        cmdline_info += '--field="Issue Type=%s" ' % issue_type
        cmdline_info += '--field="Summary=%s" ' % summary
        cmdline_info += '--field="Project=%s" ' % project
        cmdline_info += '--field="Description=%s" ' % description.replace('\n', '')

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
            ret_error = stderr_str.rstrip('\r\n')
            return ret_error[ret_error.find("Created Issue ") + len("Created Issue "):].strip()
        return None

    def UpdateIssue(self, issue_id, update_fields):
        ###########
        #
        # UpdateIssue(self, issue_id, update_fields )
        #
        # Description: Update the issue with id
        #
        # Parameter: - issue_id: the issue id
        #            - update_fields: the updated fieldes dictionary
        #
        # return None if fails, otherwise return the issue id
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = {}
        cmdline_info = 'im editissue --batch --hostname=%s --port=%s ' % (self.Host, self.Port)
        for field in update_fields:
            cmdline_info += '--field="%s=%s" ' % (field, update_fields[field])
        cmdline_info += '%s ' % issue_id

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        if (retCode != 0):
            stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
            if len(stderr_str) != 0:
                ret_error = stderr_str.rstrip('\r\n')
                return ret_error[ret_error.find("Updated Issue ") + len("Updated Issue "):].strip()
        return None

    def ChangeIssueUser(self, assigned_user, issue_id):
        ###########
        #
        # ChangeIssueUser(self, assigned_user)
        #
        # Description: Add the issue
        #
        # Parameter: - assigned_user: assigned user
        #
        # return None if fails, otherwise return the issue id
        #
        # TODO: add parameter check
        #
        ###########
        cmdline_info = 'im editissue --batch --hostname=%s --port=%s ' % (self.Host, self.Port)
        cmdline_info += '--field="Assigned User=%s" ' % assigned_user
        cmdline_info += '%s ' % issue_id

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info)
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
        if (retCode != 0):
            if len(stderr_str) != 0:
                ret_error = stderr_str.rstrip('\r\n')
                return ret_error[ret_error.find("Updated item ") + len("Updated item "):].strip()
        return stdout_str

    def ynInputCheck(self, StrInput, NumberTry):
        ###########
        #
        # ynInputCheck (self, StrInput, NumberTry)
        #
        # Description:    Check the raw_input if the input not include y,Y,n or N the user will be asked to input the Str. again.
        #
        # Parameter:      Number of input attempts
        #
        # Return:         new StrInput, if fails return the "0"
        #
        # Author:         Ilja Hotjakov 17.01.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init:
        countInput = 0

        if (NumberTry == ""):
            NumberTry = 99

        # Clrear Str.
        StrInput = StrInput.strip(' \t\n\r')
        while (countInput < NumberTry):
            if (StrInput == "y" or StrInput == "Y" or StrInput == "n" or StrInput == "N"):
                break

            StrInput = raw_input("Input not valid please type y or n:")
            # Clear input from \t \n
            StrInput = StrInput.strip(' \t\n\r')
            countInput += 1

        if (countInput >= NumberTry):
            return "0"
        else:
            return (StrInput)

    def GetAttributeFromXML(self, XmlFilePath, TagName, CompName, CompLabelName, AttributeName):
        ###########
        #
        # GetAttributeFromXML(self, XmlFilePath, TagName, CompName, AttributeName)
        #
        # Description:    return the Attribute-String from XML-File
        #
        # Parameter:      XmlFilePath      e.g. "D:\\work\\phyton\\shared_project_config.xml"
        #                 TagName          e.g. "BaseConfig"
        #                 CompName         e.g. "CompName"
        #                 CompLabelName    e.g. "ALN_Alignment"
        #                 AttributeName    e.g. "Label"
        #
        # Return:         "0" if fails, otherwise return the Attribute-String
        #
        # Author:         Ilja Hotjakov 03.02.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init:
        Label = ""
        Project = ""

        # load an existing project cfg file and find the label name
        Config = self.get_a_document(XmlFilePath)
        XmlNode = Config.getElementsByTagName(TagName).item(0)
        XmlNode.normalize()  # was macht das genau ?!!!!!!!!!!!!!!!!!!!!!!!!!!
        for BuildProjects in XmlNode.childNodes:
            if (BuildProjects.nodeType == BuildProjects.ELEMENT_NODE):
                Project = BuildProjects.getAttribute(CompName)
                # print "Project: ",Project
                if (Project == CompLabelName):
                    for BuildProject in BuildProjects.childNodes:
                        if (BuildProject.nodeType == BuildProject.ELEMENT_NODE):
                            Label = BuildProject.getAttribute(AttributeName)
                            # print "Label: ", Label
                    break

        if (Label == "" or Project != CompLabelName):
            return "0"
        else:
            return Label

    def GetProjectType(self, PjPath):
        ###########
        #
        # GetProjectType(self, PjPath)
        #
        # Description:    return the conficuration type of the project.pj from server
        #
        # Parameter:      PjPath:    Path of the project file    e.g. "D:\\work\\phyton\\project.pj" or "/nfs/projekte1/project.pj"
        #
        # Return:         "0" if fails, otherwise return the conficuration type
        #
        # Author:         Ilja Hotjakov 10.02.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        ret_value = ""
        TempPath = ""
        Project = ""
        line = ""
        templine = ""
        cmdline = ""

        if (len(PjPath) < 2):
            print("Error", " in GetProjectType the Project Path is empty: %s " % PjPath)
            return "0"
        elif PjPath.find(os.sep) != -1:
            # Da viewsandbox immer die Unterverzeichnisse von project.pj anzeigt muss der Pfad angepaast werden
            TempPath = PjPath.split(os.sep)
            Project = TempPath[-2] + '/' + TempPath[-1]  # e.g. 01_Source_folder/project.pj
            del TempPath[-2]  # das
            PjPath = os.sep.join(TempPath)  # baut wieder den pfad auf

            # viewproject is safer because of MKS Issue, sometime is viewsandbox not same as viewproject.The viewproject is the actual behavior of MKS project.
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, PjPath)
        else:  # ProjectPath
            if (self.ActDevPath == "" or self.ActDevPath == None):
                print("Error", " in GetProjectType the Development Path is empty: %s " % self.ActDevPath)
                return "0"

            # Da viewsandbox immer die Unterverzeichnisse von project.pj anzeigt muss der Pfad angepaast werden
            TempPath = PjPath.split('/')
            Project = TempPath[-2] + '/' + TempPath[-1]  # e.g. 01_Source_folder/project.pj
            del TempPath[-2]  # das
            PjPath = '/'.join(TempPath)  # baut wieder den pfad auf

            # viewproject is safer because of MKS Issue, sometime is viewsandbox not same as viewproject.The viewproject is the actual behavior of MKS project.
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --project=%s --devpath=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, PjPath, self.ActDevPath)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return "0"

        for line in self.cliProcHandler.getstdout_split():
            if (line.find(Project) != -1):
                if (line.find(" shared-subproject") != -1):
                    return "normal"
                elif (line.find(" shared-variant-subproject") != -1):
                    return "variant"
                elif (line.find(" shared-build-subproject") != -1):
                    return "build"
                elif (line.find(" subproject") != -1):
                    return "normal"
                elif (line.find(" variant-subproject") != -1):
                    return "variant"
                elif (line.find(" build-subproject") != -1):
                    return "build"
                break
        return "0"

    def GetProjectTypeDict(self, PjPath):
        ###########
        #
        # GetProjectType(self, PjPath)
        #
        # Description:    save the conficuration information of SubProjects type, revision and development path (if type variant or label)
        #                 and path (full path) in dictionary of the project.pj from server
        #
        # Parameter:      PjPath:      Path of the project file    e.g. "D:\\work\\phyton\\project.pj" or "/nfs/projekte1/project.pj"
        #
        # Return:         1 if fails, 2 if no entries found otherwise return retDict
        #
        # Author:         Ilja Hotjakov 10.02.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        # retDict["ret"] = 0
        TempPath = ""
        Project = ""
        line = ""
        templine = ""
        cmdline = ""

        if (len(PjPath) < 2):
            print("Error", " in GetProjectType the Project Path is empty: %s " % PjPath)
            return 1
        elif PjPath.find(os.sep) != -1:
            # Da viewsandbox immer die Unterverzeichnisse von project.pj anzeigt muss der Pfad angepaast werden
            TempPath = PjPath.split(os.sep)
            Project = TempPath[-2] + '/' + TempPath[-1]  # e.g. 01_Source_folder/project.pj
            del TempPath[-2]  # das
            PjPath = os.sep.join(TempPath)  # baut wieder den pfad auf

            rootProjectPath = self.GetProjectPath("sandbox", PjPath)
            if (rootProjectPath == 0):
                RootPath = ""  # e.g. 01_Source_folder/em/
            else:
                TempRootPath = rootProjectPath.split('/')
                del TempRootPath[-2]
                del TempRootPath[-1]  # project.pj
                RootPath = '/'.join(TempRootPath)  # e.g. 01_Source_folder/em/
            # viewproject is safer because of MKS Issue, sometime is viewsandbox not same as viewproject.The viewproject is the actual behavior of MKS project.
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, PjPath)
        else:  # ProjectPath
            if (self.ActDevPath == "" or self.ActDevPath == None):
                print("Error", " in GetProjectType the Development Path is empty: %s " % self.ActDevPath)
                return 1

            # Da viewsandbox immer die Unterverzeichnisse von project.pj anzeigt muss der Pfad angepaast werden
            TempPath = PjPath.split('/')
            Project = TempPath[-2] + '/' + TempPath[-1]  # e.g. 01_Source_folder/project.pj
            del TempPath[-2]  # das
            PjPath = '/'.join(TempPath)  # baut wieder den pfad auf
            del TempPath[-1]  # project.pj
            RootPath = '/'.join(TempPath)  # e.g. 01_Source_folder/em/
            # viewproject is safer because of MKS Issue, sometime is viewsandbox not same as viewproject.The viewproject is the actual behavior of MKS project.
            cmdline_info = 'si viewproject --hostname=%s --port=%s --project=%s --devpath=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, PjPath, self.ActDevPath)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                if (line.find(" shared-subproject") != -1 or line.find(" subproject") != -1):
                    TempLine = line.split(' ')
                    ProjectPath = RootPath + '/' + TempLine[0]
                    ProjectPath = ProjectPath.replace('\n', "")
                    retDict[ProjectPath] = {}
                    retDict[ProjectPath]["Type"] = "normal"
                    retDict[ProjectPath]["Label"] = ""
                    retDict[ProjectPath]["Revision"] = ""
                elif (line.find(" shared-variant-subproject") != -1 or line.find(" variant-subproject") != -1):
                    TempLine = line.split(' ')
                    ProjectPath = RootPath + '/' + TempLine[0]
                    ProjectPath = ProjectPath.replace('\n', "")
                    retDict[ProjectPath] = {}
                    retDict[ProjectPath]["Type"] = "variant"
                    retDict[ProjectPath]["Label"] = TempLine[1][1:-1]  # cut "( "")"
                    retDict[ProjectPath]["Revision"] = ""
                elif (line.find(" shared-build-subproject") != -1 or line.find(" build-subproject") != -1):
                    TempLine = line.split(' ')
                    ProjectPath = RootPath + '/' + TempLine[0]
                    ProjectPath = ProjectPath.replace('\n', "")
                    retDict[ProjectPath] = {}
                    retDict[ProjectPath]["Type"] = "build"
                    retDict[ProjectPath]["Label"] = ""
                    retDict[ProjectPath]["Revision"] = TempLine[1][1:-1]  # cut "( "")"

        if (len(retDict) > 0):  # if more then one input
            return retDict
        else:
            return 2

    def GetSharedSubSandboxTypeDict(self, SandboxPath):
        ###########
        #
        # GetSharedSubSandboxTypeDict(self,SandboxPath)
        #
        # Description:    save the conficuration information of shared subprojects type, revision and development path (if type variant or label)
        #                 and path (full path) in dictionary of the project.pj from server
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         1 if fails, 2 if no entries found otherwise return retDict
        #
        # Author:         Ilja Hotjakov 13.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        line = ""

        if (SandboxPath == "" or SandboxPath == 0):
            return 1

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet' % (
            self.Host, self.Port, SandboxPath)
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1

        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                if (line.find(" shared-build-subsandbox") != -1):
                    TempLine = line.split(' ')
                    SandboxPath = TempLine[0]
                    # print len(SandboxPath)
                    # SandboxPath = SandboxPath.replace('\n',"")
                    # print len(SandboxPath)
                    retDict[SandboxPath] = {}
                    retDict[SandboxPath]["Type"] = "build"
                    retDict[SandboxPath]["Label"] = ""
                    retDict[SandboxPath]["Revision"] = TempLine[1][1:-1]  # cut "( "")"
                elif (line.find(" shared-variant-subsandbox") != -1):
                    TempLine = line.split(' ')
                    SandboxPath = TempLine[0]
                    # SandboxPath = SandboxPath.replace('\n',"")
                    retDict[SandboxPath] = {}
                    retDict[SandboxPath]["Type"] = "variant"
                    retDict[SandboxPath]["Label"] = TempLine[1][1:-1]  # cut "( "")"
                    retDict[SandboxPath]["Revision"] = ""
                if (line.find(" shared-subsandbox") != -1):
                    TempLine = line.split(' ')
                    SandboxPath = TempLine[0]
                    # SandboxPath = SandboxPath.replace('\n',"")
                    retDict[SandboxPath] = {}
                    retDict[SandboxPath]["Type"] = "normal"
                    retDict[SandboxPath]["Label"] = ""
                    retDict[SandboxPath]["Revision"] = ""

        if (len(retDict) > 0):  # if more then one input
            return retDict
        else:
            return 2

    def GetSharedSubSandboxTypeList(self, SandboxPath):
        ###########
        #
        # GetSharedSubSandboxTypeDict(self,SandboxPath)
        #
        # Description:    save the conficuration information of shared subprojects type, revision and development path (if type variant or label)
        #                 and path (full path) in List of the project.pj from server
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         1 if fails, 2 if no entries found otherwise return retDict
        #
        # Author:         Ilja Hotjakov 13.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        SandboxPathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []

        if (SandboxPath == "" or SandboxPath == 0):
            return 1

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet' % (
            self.Host, self.Port, SandboxPath)
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                retDict = {}
                if (line.find(" shared-build-subsandbox") != -1):
                    TempLine = line.split(' ')
                    if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                        SandboxPath = TempLine[0]
                        retDict[SandboxPath] = {}
                        retDict[SandboxPath]["Type"] = "build"
                        retDict[SandboxPath]["Label"] = ""
                        retDict[SandboxPath]["Revision"] = TempLine[1][1:-1]  # cut "( "")"
                        list.append(copy.deepcopy(retDict))  # deepcopy else reference not copy
                        SandboxPathOld = SandboxPath.replace("project.pj", "")
                elif (line.find(" shared-variant-subsandbox") != -1):
                    TempLine = line.split(' ')
                    if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                        SandboxPath = TempLine[0]
                        retDict[SandboxPath] = {}
                        retDict[SandboxPath]["Type"] = "variant"
                        retDict[SandboxPath]["Label"] = TempLine[1][1:-1]  # cut "( "")"
                        retDict[SandboxPath]["Revision"] = ""
                        list.append(copy.deepcopy(retDict))  # deepcopy else reference not copy
                        SandboxPathOld = SandboxPath.replace("project.pj", "")
                elif (line.find(" shared-subsandbox") != -1):
                    TempLine = line.split(' ')
                    if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                        SandboxPath = TempLine[0]
                        retDict[SandboxPath] = {}
                        retDict[SandboxPath]["Type"] = "normal"
                        retDict[SandboxPath]["Label"] = ""
                        retDict[SandboxPath]["Revision"] = ""
                        list.append(copy.deepcopy(retDict))  # deepcopy else reference not copy
                        SandboxPathOld = SandboxPath.replace("project.pj", "")

        if (len(list) > 0):  # if more then one input
            return list
        else:
            return 2

    def GetSharedSubSandboxTypeListRec(self, SandboxPath, hash):
        ###########
        #
        # GetSharedSubSandboxTypeDictRec(self,SandboxPath, hash)
        #
        # Description:    Recursive function: save the conficuration information of shared subprojects type, revision and development path (if type variant or label)
        #                 and path (full path) in List of the project.pj from server
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #                 hash:           the hash object needed to calculate the hash over all the shares
        #
        # Return:         1 if fails, 2 if no entries found otherwise return retDict
        #
        # Author:         Ilja Hotjakov, Jochen Spruck 21.09.2013
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        SandboxPathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []

        # build the filter string of the subproject directory where traversal shall continue
        # this is done by a object variable because otherwise all functions has to be parameterized
        if len(self.BreakOut) > 0:
            break_out_filter = self.BreakOut + "\project.pj"
        else:
            break_out_filter = ""
        # print "RecursLevel=%s" % (self.RecursLevel)
        self.RecursLevel += 1

        if (SandboxPath == "" or SandboxPath == 0):
            self.RecursLevel -= 1
            return 1

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet --norecurse' % (
            self.Host, self.Port, SandboxPath)
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            self.RecursLevel -= 1
            return 1
        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                retDict = {}
                # Debug hilfe: find algo_mfl420ta46
                # Regularly the Sandbox traversing stops if a shared subsandbox is found
                # In oder to process the Algo-Project shared subsandbox in a SW-project sandbox
                # a Brake-Out depending on the Algo-Project is required
                # Break-Out-Filter e.g.  "algo_mfl420ta46" folder

                # if (line.find("algo_mfl420ta46\project.pj") != -1) or (line.find("common_mfl420ta46\project.pj") != -1):
                if ((len(break_out_filter) > 0) and line.find(break_out_filter) != -1):
                    # print "BREAK-OUT FILTER=%s %s Sandbox=" % (break_out_filter, line)
                    ret_sandbox_dict = self.GetSharedSubSandboxTypeListRec(line.split(' ')[0], hash)
                    if ret_sandbox_dict != 1 and ret_sandbox_dict != 2:
                        # print ret_sandbox_dict
                        list.extend(ret_sandbox_dict)

                elif (line.find(" shared-build-subsandbox") != -1):
                    TempLine = line.split(' ')
                    if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                        SandboxPath = TempLine[0]
                        retDict[SandboxPath] = {}
                        retDict[SandboxPath]["Type"] = "build"
                        retDict[SandboxPath]["Label"] = ""
                        retDict[SandboxPath]["Revision"] = TempLine[1][1:-1]  # cut "( "")"
                        list.append(copy.deepcopy(retDict))  # deepcopy else reference not copy
                        path = SandboxPath.split('\\')
                        # print ("%s,%s,%s,%s")%(path[-2], path[-1],, retDict[SandboxPath]["Type"], retDict[SandboxPath]["Revision"])
                        hash.update(("%s,%s,%s,%s") % (
                            path[-2], path[-1], retDict[SandboxPath]["Type"], retDict[SandboxPath]["Revision"]))
                        SandboxPathOld = SandboxPath.replace("project.pj", "")
                elif (line.find(" shared-variant-subsandbox") != -1):
                    TempLine = line.split(' ')
                    if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                        SandboxPath = TempLine[0]
                        retDict[SandboxPath] = {}
                        retDict[SandboxPath]["Type"] = "variant"
                        retDict[SandboxPath]["Label"] = TempLine[1][1:-1]  # cut "( "")"
                        retDict[SandboxPath]["Revision"] = ""
                        list.append(copy.deepcopy(retDict))  # deepcopy else reference not copy
                        path = SandboxPath.split('\\')
                        # print ("%s,%s,%s,%s")%(path[-2], path[-1],, retDict[SandboxPath]["Type"], retDict[SandboxPath]["Label"])
                        hash.update(("%s,%s,%s,%s") % (
                            path[-2], path[-1], retDict[SandboxPath]["Type"], retDict[SandboxPath]["Label"]))
                        SandboxPathOld = SandboxPath.replace("project.pj", "")
                elif (line.find(" shared-subsandbox") != -1):
                    TempLine = line.split(' ')
                    if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                        SandboxPath = TempLine[0]
                        retDict[SandboxPath] = {}
                        retDict[SandboxPath]["Type"] = "normal"
                        retDict[SandboxPath]["Label"] = ""
                        retDict[SandboxPath]["Revision"] = ""
                        list.append(copy.deepcopy(retDict))  # deepcopy else reference not copy
                        path = SandboxPath.split('\\')
                        # print ("%s,%s,%s")%(path[-2], path[-1],, retDict[SandboxPath]["Type"])
                        hash.update(("%s,%s,%s") % (path[-2], path[-1], retDict[SandboxPath]["Type"]))
                        SandboxPathOld = SandboxPath.replace("project.pj", "")
                elif (line.find(" subsandbox") != -1) or (line.find(" variant-subsandbox") != -1) or (
                            line.find(" build-subsandbox") != -1):
                    # print line.split(' ')[0]
                    # print "DEBUG-RECURS-1: %s" % (line)
                    ret_sandbox_dict = self.GetSharedSubSandboxTypeListRec(line.split(' ')[0], hash)
                    if ret_sandbox_dict != 1 and ret_sandbox_dict != 2:
                        # print ret_sandbox_dict
                        list.extend(ret_sandbox_dict)
        # for tracing of recursive traverse of sandbox
        if (len(list) > 0):  # if more then one input
            self.RecursLevel -= 1
            return list
        else:
            self.RecursLevel -= 1
            return 2

    def GetNotSharedProjectsRec(self, SandboxPath):
        ###########
        #
        # GetNotSharedProjectsRec(self,SandboxPath)
        #
        # Description:    Recursive function: to get all not shared projects for the SandboxPath
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         False if no not shared project is found otherwise return a dict with the projects
        #
        # Author:         Jochen Spruck 21.09.2013
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        SandboxPathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []

        if (SandboxPath == "" or SandboxPath == 0):
            return False

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet --norecurse' % (
            self.Host, self.Port, SandboxPath)
        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return False
        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                retDict = {}
                if (line.find(" subsandbox") != -1) or (line.find(" variant-subsandbox") != -1) or (
                            line.find(" build-subsandbox") != -1):
                    # print line.split(' ')[0]
                    SandboxPath = line.split(' ')[0]
                    list.append(SandboxPath)
                    ret_sandbox_dict = self.GetNotSharedProjectsRec(SandboxPath)
                    if ret_sandbox_dict != False:
                        # print ret_sandbox_dict
                        list.extend(ret_sandbox_dict)
        if (len(list) > 0):  # if more then one input
            return list
        return False

    def GetNotSharedProjectsRecGeneric(self, SandboxPath, ScanType):
        ###########
        #
        # GetProjectsRecGeneric(self,SandboxPath, ScanType)
        #
        # Description:    Recursive function: to get all not shared 'variant' (variant or normal), 'all' (both variant + build + shared + non-shared) subprojects for the SandboxPath
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        #                 ScanType : Subproject type, should be either of three 'variant-nonshared', 'all'
        #
        # Return:         False if no not shared project is found otherwise return a dict with the projects
        #
        # Author:         Saad Azam 01.06.2015
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        SandboxPathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []

        if (SandboxPath == "" or SandboxPath == 0):
            return False

        if ScanType != "variant-nonshared" and ScanType != "all":
            self.Log("Error", "Wrong ScanType value, it should be either 'variant-nonshared' or 'all'")
            self.exit(1)

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet --norecurse' % (
            self.Host, self.Port, SandboxPath)
        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return False
        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                retDict = {}
                if ScanType == 'variant-nonshared':
                    if (line.find(" subsandbox") != -1) or (line.find(" variant-subsandbox") != -1):
                        # print line.split(' ')[0]
                        SandboxPath = line.split(' ')[0]
                        list.append(SandboxPath)
                        ret_sandbox_dict = self.GetNotSharedProjectsRecGeneric(SandboxPath, ScanType)
                        if ret_sandbox_dict != False:
                            # print ret_sandbox_dict
                            list.extend(ret_sandbox_dict)
                elif ScanType == 'all':
                    if (line.find("shared-") != -1) or (line.find(" subsandbox") != -1) or (
                                line.find(" build-subsandbox") != -1) or (line.find(" variant-subsandbox") != -1):
                        # print line.split(' ')[0]
                        SandboxPath = line.split(' ')[0]
                        list.append(SandboxPath)
                        ret_sandbox_dict = self.GetNotSharedProjectsRecGeneric(SandboxPath, ScanType)
                        if ret_sandbox_dict != False:
                            # print ret_sandbox_dict
                            list.extend(ret_sandbox_dict)
        if (len(list) > 0):  # if more then one input
            return list
        return False

    def GetProjectsRecGeneric(self, Path, ScanType, ProjectType):
        ###########
        #
        # GetProjectsRecGeneric(self,Path, ScanType, ProjectType)
        #
        # Description:    Recursive function: to get all not-shared or shared or all subprojects for the Path
        #
        # Parameter:      Path:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #                 ScanType : Subproject type, should be either 'nonshared' or 'all' or 'shared'
        #                 ProjectType : should be either 'sandbox' or 'project' based on what is intended to be scanned
        #
        # Return:         False if no not shared project is found otherwise return a dict with the projects
        #
        # Author:         Saad Azam 01.06.2015
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        retDict = {}
        PathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []
        error = 0

        if (Path == "" or Path == 0):
            error = 1
            return error

        if ProjectType != "project" and ProjectType != "sandbox":
            self.Log("Error", "Wrong ProjectType value, it should be either 'project' or 'sandbox'")
            error = 1
            return error

        if ScanType != "nonshared" and ScanType != "all":
            self.Log("Error", "Wrong ScanType value, it should be either 'nonshared' or 'all'")
            error = 1
            return error

        if ProjectType == "project":
            cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet --recurse' % (
                self.Host, self.Port, Path)
        elif ProjectType == "sandbox":
            cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet --norecurse' % (
                self.Host, self.Port, Path)

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return False
        for line in self.cliProcHandler.getstdout_split():
            if (len(line) > 0):
                retDict = {}
                if ScanType == 'nonshared':
                    if (line.find("shared-") == -1) and (line.find(" subsandbox") != -1) or (
                                line.find(" variant-subsandbox") != -1) or (line.find(" build-subsandbox") != -1):
                        # print line.split(' ')[0]
                        Path = line.split(' ')[0]
                        list.append(Path)
                        ret_sandbox_dict = self.GetProjectsRecGeneric(Path, ScanType, ProjectType)
                        if ret_sandbox_dict != False:
                            # print ret_sandbox_dict
                            list.extend(ret_sandbox_dict)
                elif ScanType == 'all':
                    if (line.find("shared-") != -1) or (line.find(" subsandbox") != -1) or (
                                line.find(" build-subsandbox") != -1) or (line.find(" variant-subsandbox") != -1):
                        # print line.split(' ')[0]
                        Path = line.split(' ')[0]
                        list.append(Path)
                        ret_sandbox_dict = self.GetProjectsRecGeneric(Path, ScanType, ProjectType)
                        if ret_sandbox_dict != False:
                            # print ret_sandbox_dict
                            list.extend(ret_sandbox_dict)
        if (len(list) > 0):  # if more then one input
            return list
        return False

    def GetListOfNonSharedSubprojectsFromSandbox(self, SandboxPath):
        ###########
        #
        #
        # Description: Returns a list of NonShared Subprojects in a project based on the project sandbox
        #
        # Parameters: - SandboxPath: Input sandboxpath to be scanned
        #
        # Return: List of NonShared Subprojects (and additionally mks projectpath) incase of success, otherwise 1 (error) is returned
        #
        # Author: Saad Azam (uidg4889)
        #
        # TODO: add parameter check
        #
        ###########
        error = 0
        if self.ValidateSandboxPath(SandboxPath, 'dir') == 1:
            self.Log("Error", "Sandbox Path %s does not exist" % SandboxPath)
            error = 1
            return error
        ProjectPath = self.GetProjectPath("sandbox", SandboxPath)
        ProjectPath = ProjectPath[:ProjectPath.rfind('/') + 1]
        not_shared_path_list = []
        error = 0
        ProjView = self.GetProjectsRecGeneric(SandboxPath, 'nonshared', 'sandbox')  # GetNotSharedProjectsRec

        if ProjView == 1:
            error = 1
            return error
        for not_shared_path in ProjView:
            temp = SandboxPath[:SandboxPath.rfind('\\')]
            if not_shared_path.find(temp) == -1:
                self.Log("Error", "Wrong SandboxPath given")
                error = 1
                return error
            else:
                not_shared_path = not_shared_path[not_shared_path.find(temp) + len(temp) + 1:]
                not_shared_path = not_shared_path.replace('\\', '/')
                not_shared_path = ProjectPath + not_shared_path
                self.Log("Info", not_shared_path)
                not_shared_path_list.append(not_shared_path)
        return not_shared_path_list, ProjectPath, error

    def ValidateSubProjectPath(self, ProjectPath, DevPath=None):
        ###########
        #
        # Description: Validates if the subproject exists or not
        #
        # Parameters:
        #         - ProjectPath: Path of the subproject to be validated
        #
        # Return: 0 if the subproject path exists, 1 in case it doesn't exist or any error occurs
        #
        # Author: Saad Azam (uidg4889)
        #
        # TODO: add parameter check
        #
        ###########
        error = 0
        cmdline_info = ""
        if DevPath != None:
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --project=%s --devpath=%s --forceConfirm=no ' % (
                self.Host, self.Port, ProjectPath, DevPath)
        else:
            cmdline_info = 'si projectinfo --batch --hostname=%s --port=%s --project=%s --forceConfirm=no ' % (
                self.Host, self.Port, ProjectPath)

        # if DevPath != "":
        # cmdline_info += "--devpath=%s " % DevPath
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        return 0

    def CreateSubproject(self, ProjectPath, CpId, DevPath=None):
        ###########
        #
        # Description: Create new subproject in the project, in case the project to be created is a dropped subproject it would be readded
        #
        # Parameters:
        #        - ProjectPath: Path of the subproject to be created
        #
        # Return: 0 if the subproject created successfully, 1 in case of an error
        #
        # Author: Saad Azam (uidg4889)
        #
        # TODO: add parameter check
        #
        ###########
        error = 0
        BaseProjectPath = ProjectPath[:ProjectPath.rfind('/', 0, ProjectPath.rfind('/'))] + ProjectPath[
                                                                                            ProjectPath.rfind('/'):]

        if self.ValidateSubProjectPath(BaseProjectPath, DevPath) == 1:
            self.Log("Error",
                     "The BaseProjectPath %s on which the the target subproject % should be created does not exist" % (
                         BaseProjectPath, ProjectPath))
            error = 1
            return error

        if DevPath == None:  # use normal/base trunk in case no devpath specified
            cmdline_info = 'si createsubproject --batch --hostname=%s --port=%s --cpid=%s --project=%s --forceConfirm=no --reuseDroppedSubproject %s' % (
                self.Host, self.Port, CpId, BaseProjectPath, ProjectPath)
        else:
            cmdline_info = 'si createsubproject --batch --hostname=%s --port=%s --cpid=%s --project=%s --devpath=%s --forceConfirm=no --reuseDroppedSubproject %s' % (
                self.Host, self.Port, CpId, BaseProjectPath, DevPath, ProjectPath)

        # if DevPath != "":
        # cmdline_info += "--devpath=%s " % DevPath
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        return 0

    def RenameFileAndAddDateTime(self, FileNameAndPath):
        ###########
        #
        # RenameFileAndAddDateTime(self, FileNameAndPath)
        #
        # Description:    Add to an existing file the date and time. e.g. Filename_19.03.2012_10:25:34.xml
        #
        # Parameter:      FileNameAndPath:    Filename with path    e.g. D:\Folder\file.xml
        #
        # Return:         if fails return the 1 else 0
        #
        # Author:         Ilja Hotjakov 19.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init:
        listPath = []
        listFileName = []

        error = 0
        # check Input
        if (os.path.isfile(FileNameAndPath) == False):
            error = 1

        listPath = FileNameAndPath.split(os.sep)
        FileName = listPath[-1]  # e.g. project.pj
        listFileName = FileName.split(".")
        FileType = listFileName[-1]
        del listFileName[-1]
        # assemble because points may appear in names
        FileName = os.sep.join(listFileName)
        FileName = FileName + "_" + datetime.now().strftime("%Y.%m.%d_%H.%M.%S") + "." + FileType

        try:
            os.rename(FileNameAndPath, FileName)
        except:
            error = 1
        return error

    # def CompareSandboxWithProject(self, SandboxPjPath):
    # ###########
    # #
    # # ScanForNonBuildSharedProject(self, Project, Sandbox)
    # #
    # # Description: Sacn all shared projects in project if one is not set to build share print error
    # #
    # # Parameter: -Project the mks path of the project where the scann should start
    # #            -Sandbox the path of the pj file from the sandbox where the shared project scan should start
    # # return 0 if all shared sub project are build, 1 if not
    # #
    # # TODO: add parameter check
    # #
    # ###########
    # ret_value = 0
    # if (self.ProjectType == "sandbox"):
    #    # logging.Log("Debug",Sandbox)
    # cmdline='si viewsandbox --hostname=%s --port=%s --sandbox=%s --fields=name,type --norecurse' %(self.Host, self.Port, Sandbox)
    #
    # if (self.ProjectType == "project"):
    #    # logging.Log("Debug",project)
    # cmdline='si viewproject --hostname=%s --port=%s --project=%s --fields=name,type --norecurse'%(self.Host, self.Port, Project)
    #
    # stdout=os.popen(cmdline,'r')
    # # self.Log("Debug",cmdline)
    # for line in stdout.readlines():
    #    # print line
    # if (len(line) > 1):
    #                #(argu[1] != 'shared-subproject') and (argu[1] != 'shared-build-subproject') and (argu[1] != 'shared-variant-subproject') and (argu[1] != 'archived')
    # ret = self.GetPathOfSandboxOrProject(line, Project, Sandbox)
    #    # logging.Log("Debug",ret["ret"])
    #    # logging.Log("Debug","NextProject %s"%ret["project"])
    #    # logging.Log("Debug","NextSandbox %s"%ret["sandbox"])
    #
    # if (ret["ret"] != 2):
    #                    # if it is not a shared sub project go to the next directory
    # if (ret["ret"] == 1):
    #                        # go to next path directory of the project or the sandbox is no shared-subproject and no archiv
    # ret_value |= self.ScanForNonBuildSharedProject(ret["project"], ret["sandbox"])
    # else:
    # IsNotBuild = 0
    # ProjectPath = 0
    # ProjectPathSharedFrom = 0
    # if (self.ProjectType == "sandbox"):
    # if (ret["type"] != "build"):
    # ProjectPath = self.GetProjectPath("sandbox",ret["sandbox"])
    # ProjectPathSharedFrom = self.GetSharedFromPath("sandbox",ret["sandbox"])
    # IsNotBuild = 1
    # elif (self.ProjectType == "project"):
    # if (ret["type"] != "build"):
    # ProjectPath = self.GetProjectPath("project",ret["project"])
    # ProjectPathSharedFrom = self.GetSharedFromPath("project",ret["project"])
    # IsNotBuild = 1
    #
    # if (IsNotBuild == 1):
    # if ((ProjectPath != 0) and (ProjectPathSharedFrom != 0)):
    # if (self.CheckIfInternalShare(self.RootScanPath,ProjectPathSharedFrom) == 0) and (self.CheckIfPathShouldBeExcluded(ProjectPath, self.ExcludeFile)):
    # ret_value = 1
    # self.Log("Info","Shared subproject %s not configured to build!!"%(ProjectPath))
    # # exit with the return value
    # # ret_value = 0
    # return ret_value

    def AddSharedSubProject(self, SharedSource, SharedTarget, DevPath="", SubprojectDevelopmentPath=None,
                            SubprojectRevision=None, TypeOfShare="normal"):
        ###########
        #
        # AddSharedSubProject(self, SharedSource, SharedTarget, DevPath, SubprojectDevelopmentPath, SubprojectRevision, TypeOfShare = "normal")
        #
        # Description:    Add to an shared sub project
        #
        # Parameter:      -SharedSource:       mks project of shared subporject source
        #                 -SharedTarget:       mks project of target
        #                 -DevPath:            the DevPath of the target
        #                 -SubprojectDevelopmentPath the the dev path, used if TypeOfShare is variant
        #                 -SubprojectRevision: revision of share, usd if TypeOfShare is build
        #                 -TypeOfShare:        Type of share normal, variant, build or default
        #
        # Return:         return False if fails
        #
        # Author:         Jochen Spruck 04.02.2013
        #
        # TODO: add parameter check
        #
        ###########
        error = 0

        dirname, pjfile = os.path.split(SharedTarget)
        dirname, folder = os.path.split(dirname)
        FinalTargetShare = posixpath.join('./', folder, pjfile)
        FinalTargetProject = posixpath.join(dirname, pjfile)

        cmdline_info = 'si sharesubproject --batch --hostname=%s --port=%s --cpid=%s --project=%s --sharedProject=%s --forceConfirm=no ' % (
            self.Host, self.Port, self.CpId, FinalTargetProject, SharedSource)

        # si sharesubproject --batch --hostname=mks-psad-test --port=8001 --cpid=162648:22 --project=/nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/00_CodeGen/algo/project.pj --devpath=SMFC4B0 --sharedProject=/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/00_CodeGen/algo/fct/project.pj --type=normal --forceConfirm=no ./fct/project.pj
        if DevPath != "":
            cmdline_info += "--devpath=%s " % DevPath
        if TypeOfShare == "variant":
            cmdline_info += "--type=variant --variant=%s " % SubprojectDevelopmentPath
        elif TypeOfShare == "build":
            cmdline_info += "--type=build --subprojectRevision=%s " % SubprojectRevision
        else:
            cmdline_info += "--type=normal "

        cmdline_info += FinalTargetShare
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        return 0

    def DropSubProject(self, SharedTarget, DevPath=""):
        ###########
        #
        # AddSharedSubProject(self, SharedTarget, DevPath)
        #
        # Description:    Add to an shared sub project
        #
        # Parameter:      -SharedTarget:       mks project of target
        #                 -DevPath:            the DevPath of the target
        #
        # Return:         return False if fails
        #
        # Author:         Saad Azam 16.03.2017
        #
        # TODO: add parameter check
        #
        ###########
        error = 0

        dirname, pjfile = os.path.split(SharedTarget)
        dirname, folder = os.path.split(dirname)
        FinalTargetShare = posixpath.join('./', folder, pjfile)
        FinalTargetProject = posixpath.join(dirname, pjfile)

        cmdline_info = ""
        cmdline_info = 'si drop -f --hostname=%s --port=%s --cpid=%s --project=%s --forceConfirm=no ' % (
            self.Host, self.Port, self.CpId, FinalTargetProject)

        if DevPath != "":
            cmdline_info += "--devpath=%s " % DevPath

        cmdline_info += FinalTargetShare
        # print cmdline_info
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        return 0

    """
    def GetAbsolutePath(self,relpath,typeflag):
        #################### Get the absolute sandbox path from relevant sandbox path and validate its existance #########################
        string1 = relpath[:relpath.find('\\')]
        cmdline_info_sandbox='si sandboxinfo'
        #print '\n',cmdline_info_members
        stdout_viewproj_sandbox = os.popen(cmdline_info_sandbox,'r')
        sandbox_info = stdout_viewproj_sandbox.readlines()
        for line in sandbox_info:
          if line.find('Variant Sandbox Name: ')!= -1:
            temp = 'Variant Sandbox Name: '
          elif line.find('Build Sandbox Name: ')!= -1:
            temp = 'Build Sandbox Name: '
          elif line.find('Sandbox Name: ')!= -1:
            temp = 'Sandbox Name: '
          string2 = temp
          if line.find(string2) != -1:
            line = line[len(string2):]
            #print line
            if line.find(string1) != -1:
              line = line[:line.find(string1)]+relpath
              AbsPath = line
              #print 'Input Path: ', AbsPath, '\n'
            else:
              self.Log("Error", "Please make sure that the relative path provided exists in the current sandbox")
              sys.exit(1)

        if typeflag == 'dir':
          cmdline_info_sandbox='si sandboxinfo --sandbox='+AbsPath
        elif typeflag == 'file':
          cmdline_info_sandbox='si memberinfo '+AbsPath
        else:
          print '\n'
          self.Log("Error", "Wrong type flag, the type flag should either be \'file\' or \'dir\'. Please check if the correct type flag was used")
          sys.exit(1)
        #print cmdline_info_sandbox
        stdout_viewproj_sandbox = os.popen(cmdline_info_sandbox,'r')
        sandbox_info = stdout_viewproj_sandbox.readlines()
        if sandbox_info == []:
          if typeflag == 'file':
            self.Log("Error", "Please check if the input path "+AbsPath+" exists and is a valid file path")
            sys.exit(1)
          else:
            self.Log("Error", "Please check if the input path "+AbsPath+" exists and is a valid sandbox directory path")
            sys.exit(1)
        return AbsPath
    """

    def ValidateSandboxPath(self, Path, typeflag):
        ###########
        #
        # Description:    Validate the input Sandbox path of a Sanbox member directory or a file
        #
        # Parameters:     Path         -   Sandbox path of the input Folder or File to be validated
        #                 typeflag     -   flag describing if the input Path is that of a file or a directory
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        error = 0
        if typeflag == 'dir':
            cmdline_info_sandbox = 'si sandboxinfo %s %s --sandbox=%s' % (self.opt_user, self.opt_password, Path)
        elif typeflag == 'file':
            cmdline_info_sandbox = 'si memberinfo %s %s %s' % (self.opt_user, self.opt_password, Path)
        else:
            self.Log("Error",
                     "\nWrong type flag, the type flag should either be \'file\' or \'dir\'. Please check if the correct type flag was used")
            error = 1

        # self.Log("Info", "cmdline_info_sandbox=%s" % (cmdline_info_sandbox))

        self.cliProcHandler.SiCLIHandler_wait(cmdline_info_sandbox)
        sandbox_info = self.cliProcHandler.getstdout_split()
        if sandbox_info == []:
            if typeflag == 'file':
                self.Log("Error", "Please check if the input path " + Path + " exists and is a valid file path")
                error = 1
            else:
                self.Log("Error",
                         "Please check if the input path " + Path + " exists and is a valid sandbox directory path")
                error = 1
        return error

    def IsChangePackageValid(self, change_package_id, Host, Port):
        ###########
        #
        # Description:    Function to check if the input change_package_id is valid
        #
        # Parameters:     change_package_id    -   Input change package id to be validated
        #
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        cpid_exists = 0
        cmdline_info_cpid = 'si viewcps --hostname=%s --port=%s %s %s' % (Host, Port, self.opt_user, self.opt_password)
        # self.Log("Info", "cmdline_info_cpid=%s" % (cmdline_info_cpid))

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info_cpid, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return 1
        for line in self.cliProcHandler.getstdout_split():
            if line.split()[0] == change_package_id:
                cpid_exists = 1
                break
        if cpid_exists == 0:
            self.Log("Error",
                     "Invalid change package id '%s' entered. Please make sure to enter a valid change package id" % (
                         change_package_id))
            return 1
        return 0

    def GetNotSharedMemberDict(self, SandboxPath, path, ScanType):
        ###########
        #
        # Description:    Get a dictionary of all the members in the given sandbox subproject path including sub-sub-project paths
        #                (Only Non-shared Non-build can be filtered using ScanType = variant-nonshared, useful in algo integration - CheckinMembers function)
        #
        # Parameters:     SandboxPath   -   Base sandbox path
        #                 path          -   Relative subproject path in sandbox from where the scan should start (SandboxPath+path = Absolute sandbox path)
        #                 ScanType      -   What kind of projects and subprojects be scanned (currently two options available 'variant-nonshared' or 'all')
        #
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        member_dict = {}

        # Get absolute path and validate it
        typeflag = 'dir'
        AbsPath = os.path.join(SandboxPath, path)
        error = self.ValidateSandboxPath(AbsPath, typeflag)
        if error == 1:
            return error
        # AbsPath = self.GetAbsolutePath(path,typeflag)

        self.Log("Info", "-" * 135)
        self.Log("Info", "Base SandBox Directory: " + AbsPath)
        Sandbox = AbsPath.replace("\\", "/")
        # print 'Sandbox Path: ', Sandbox, '\n'
        self.Log("Info", "-" * 135)

        # NotSharedDict = self.GetProjectTypeDict(Sandbox)
        NotSharedDict = self.GetNotSharedProjectsRecGeneric(Sandbox, ScanType)

        if NotSharedDict == False:
            NotSharedDict = [Sandbox]
        else:
            NotSharedDict.append(Sandbox)

        for SubprojPath in NotSharedDict:

            # print '\n##########',SubprojPath,'#############\n'
            cmdline_info_members = 'si viewsandbox --sandbox=%s --fields=name --norecurse' % (
                SubprojPath)  # Returns the member names, MemberRevision and details if working file is different from MemberRevision
            # print cmdline_info_members
            self.cliProcHandler.SiCLIHandler_wait(cmdline_info_members)
            list_members = self.cliProcHandler.getstdout_split()
            # print list_members

            counter = 0
            for member in list_members:
                member = member[len(AbsPath) - len(AbsPath.lstrip(' ')):]
                if len(member) > 1:
                    if member.find(
                            'project.pj') == -1:  # ignore the lines containing subproject path, we are only interested in member paths here
                        end_position = member.find('\n')
                        if (end_position == -1):
                            # self.Log("Debug", "Due to no line feed, going to put unchanged member '%s' into dictionary" % member)
                            member_dict_temp = member
                        else:
                            # self.Log("Debug", "Due to line feed, going to remove last character of member '%s' and put it into dictionary" % member)
                            member_dict_temp = member[:end_position]

                        self.Log("Info", "Member to add: %s" % member)

                        if counter == 0:
                            member_dict[SubprojPath] = [member_dict_temp]
                        else:
                            member_dict[SubprojPath].append(member_dict_temp)
                        counter = 1
        return member_dict

    def LockMemberSandbox(self, MemberPath, change_package_id, Host, Port):
        ###########
        #
        # Description:    Lock a Member at the given sandbox location (Note: the function is currently non generic for project paths, only applicable to sandbox paths)
        #
        # Parameters:     MemberPath           -   Absolute member sandbox path
        #                 change_package_id    -   Change package id to be associated with the lock
        #
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        # Check if the change package id is valid
        if self.IsChangePackageValid(change_package_id, Host, Port) == 1:
            return 1

        if self.ValidateSandboxPath(MemberPath, 'file') == 1:
            return 1

        cmdline_info = 'si lock --forceConfirm=yes --changePackageId=%s %s %s %s' % (
            change_package_id, self.opt_user, self.opt_password, MemberPath)

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
            if len(stderr_str) != 0:
                if stderr_str.find('already locked') != -1:
                    self.Log("Error", "Working member revision already locked using another change package id")
            return 1
        return 0

    def UnlockMember(self, MemberPath):
        ###########
        #
        # Description:    Remove lock on a member with given memberpath
        #
        # Parameters:     MemberPath
        #
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        cmdline_info = 'si unlock --forceConfirm=yes --action=remove %s %s %s' % (
            self.opt_user, self.opt_password, MemberPath)

        if self.ValidateSandboxPath(MemberPath, 'file') == 1:
            return 1

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1
        return 0

    def CheckIn(self, MemberPath, change_package_id, label, description, Host, Port):
        ###########
        #
        # Description:    Checks in a member after validating the input change package id and if the member is locked
        #
        # Parameters:     MemberPath           -   Absolute member sandbox path
        #                 change_package_id    -   Change package id to be associated with the checkin operation
        #                 label                -   Label to be added to the checked in member
        #                 description          -   Description of the checked in member
        #
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        if (self.IsChangePackageValid(change_package_id, Host, Port) == 1) or (
                    self.ValidateSandboxPath(MemberPath, 'file') == 1):
            return 1, ''

        # Check if a member is locked (a member without lock won't be checked in)
        cmdline_info = 'si memberinfo %s' % (MemberPath)
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return 1, ''
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()

        if stdout_str.find('Locked By') == -1:
            self.Log("Error",
                     "There is no lock found on the member %s, Please make sure to lock the member first" % MemberPath)
            return 1, ''
        # CheckIn a locked member
        cmdline_info = 'si ci --forceConfirm=yes --changePackageId=' + change_package_id + ' ' + self.opt_user + ' ' + self.opt_password + ' --description="' + description
        if label != '':
            cmdline_info += ' --label="' + label

        cmdline_info += '" --nocheckinUnchanged ' + MemberPath
        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()

        # ATTENTION: Output on error-channel is neccessary, because we are looking for pattern like
        # 'Checked in revision' which is printed on error-channel (although it is not a "real" error...)
        output_str = stderr_str.rstrip('\r\n')

        self.Log("Info", "Going to return value '%s' with output-string '%s'" % (retval, output_str))
        return retval, output_str

    def UpdateWorkingToMember(self, MemberPath, change_package_id, Host, Port):
        ###########
        #
        # Description:    Updates workin revision as member revision
        #
        # Parameters:     MemberPath           -   Absolute member sandbox path of the working file
        #                 change_package_id    -   Change package id to be associated with the update member revision operation
        #
        # Author: Saad Azam
        #
        # TODO: add parameter check
        #
        ###########
        if (self.IsChangePackageValid(change_package_id, Host, Port) == 1) or (
                    self.ValidateSandboxPath(MemberPath, 'file') == 1):
            return 1

        # cmdline_info = 'si updaterevision -r:working --changePackageId=' + change_package_id + ' ' + MemberPath
        cmdline_info = 'si updaterevision -r:working --changePackageId=%s %s %s %s' % (
            change_package_id, self.opt_user, self.opt_password, MemberPath)

        return self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)


class mks_config_helper_obj(object):
    def GetPathOfSandboxOrProject(self, line, Project, Sandbox):
        ###########
        #
        # GetTypeOfSandboxOrProject(self, line, Project, Sandbox)
        #
        # Description: Return the local or mks path of the sandbox/project if it is not a shared-subproject, shared-variant-subproject or shared-build-subproject
        #
        # Parameter: -line the si viewproject sandboxview line
        #            -Project the mks path of the project
        #            -Sandbox the path of the sandbox pj file
        #
        # return a dictionary with the next mks path and return code: value 0-no subproject, 1=sharedsubproject, 2= archive or dropped subproject
        #
        # TODO: add parameter check
        #
        ###########
        ret = {}
        ret["ret"] = 0
        if (line.find(" archived") != -1):
            ret["ret"] = 2
            ret["filename"] = line[0:line.find(" archived")]
            ret["revision"] = line[(line.find(" archived") + 10):len(line)]
            return ret
        if (self.ProjectType == "sandbox"):
            # print line
            ret["project"] = ""
            if (line.find(" shared-subsandbox") != -1):
                ret["sandbox"] = line.replace(" shared-subsandbox", "")
                ret["type"] = "normal"
            elif (line.find(" shared-variant-subsandbox") != -1):
                tmp = line.replace(" shared-variant-subsandbox", "")
                ret["sandbox"] = line[0:tmp.rfind('(') - 1]
                ret["type"] = "variant"
            elif (line.find(" shared-build-subsandbox") != -1):
                tmp = line.replace(" shared-build-subsandbox", "")
                ret["sandbox"] = line[0:tmp.rfind('(') - 1]
                ret["type"] = "build"
            elif (line.find(" subsandbox") != -1):
                ret["sandbox"] = line.replace(" subsandbox", "")
                ret["ret"] = 1
            elif (line.find(" variant-subsandbox") != -1):
                tmp = line.replace(" variant-subsandbox", "")
                ret["sandbox"] = line[0:tmp.rfind('(') - 1]
                ret["ret"] = 1
            elif (line.find(" build-subsandbox") != -1):
                tmp = line.replace(" build-subsandbox", "")
                ret["sandbox"] = line[0:tmp.rfind('(') - 1]
                ret["ret"] = 1
            elif (line.find(" dropped-subproject") != -1):
                tmp = line.replace(" dropped-subproject", "")
                ret["sandbox"] = line[0:tmp.rfind('(') - 1]
                ret["ret"] = 2
            elif (line.find(" dropped") != -1):
                tmp = line.replace(" dropped", "")
                # is a dropped member archive
                ret["sandbox"] = ""
                ret["ret"] = 2
            if not "sandbox" in ret:
                print line
            ret["sandbox"] = ret["sandbox"].replace("\n", "")
        elif (self.ProjectType == "project"):
            ret["sandbox"] = ""
            if (line.find(" shared-subproject") != -1):
                ret["project"] = Project.replace("project.pj", line.replace(" shared-subproject", ""))
                ret["revision"] = line[line.rfind('(') + 1:line.rfind(')')]
                ret["type"] = "normal"
            elif (line.find(" shared-variant-subproject") != -1):
                tmp = line.replace(" shared-variant-subproject", "")
                ret["project"] = Project.replace("project.pj", line[0:tmp.rfind('(') - 1])
                ret["revision"] = line[tmp.rfind('(') + 1:tmp.rfind(')')]
                ret["type"] = "variant"
            elif (line.find(" shared-build-subproject") != -1):
                tmp = line.replace(" shared-build-subproject", "")
                ret["project"] = Project.replace("project.pj", line[0:tmp.rfind('(') - 1])
                ret["revision"] = line[tmp.rfind('(') + 1:tmp.rfind(')')]
                ret["type"] = "build"
            elif (line.find(" subproject") != -1):
                ret["project"] = Project.replace("project.pj", line.replace(" subproject", ""))
                ret["revision"] = line[line.rfind('(') + 1:line.rfind(')')]
                ret["ret"] = 1
            elif (line.find(" variant-subproject") != -1):
                tmp = line.replace(" variant-subproject", "")
                ret["project"] = Project.replace("project.pj", line[0:tmp.rfind('(') - 1])
                ret["revision"] = line[tmp.rfind('(') + 1:tmp.rfind(')')]
                ret["ret"] = 1
            elif (line.find(" build-subproject") != -1):
                tmp = line.replace(" build-subproject", "")
                ret["project"] = Project.replace("project.pj", line[0:tmp.rfind('(') - 1])
                ret["revision"] = line[tmp.rfind('(') + 1:tmp.rfind(')')]
                ret["ret"] = 1
            elif (line.find(" dropped-subproject") != -1):
                tmp = line.replace(" dropped-subproject", "")
                ret["project"] = line[0:tmp.rfind('(') - 1]
                ret["revision"] = line[tmp.rfind('(') + 1:tmp.rfind(')')]
                ret["ret"] = 2
            elif (line.find(" dropped") != -1):
                tmp = line.replace(" dropped", "")
                # is a dropped member archive
                ret["project"] = ""
                ret["revision"] = ""
                ret["ret"] = 2
            ret["project"] = ret["project"].replace("\n", "")
        return ret

    def GetNoBuildSharedSubSandboxList(self, SandboxPath):
        ###########
        #
        # GetNoBuildSharedSubSandboxList(self,SandboxPath)
        #
        # Description:    save the no build shared sandbox pathes to list starting from given SandboxPath
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         1 if fails, 2 if no entries found otherwise return list
        #
        # Author:         Ilja Hotjakov 18.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        SandboxPathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []

        if (SandboxPath == "" or SandboxPath == 0):
            return 1

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet' % (
            self.Host, self.Port, SandboxPath)
        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return 1
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
        if len(stdout_str) != 0:
            stdout_str_lines = stdout_str.splitlines()
            for line in stdout_str_lines:
                if (len(line) > 0):
                    if (line.find(" shared-variant-subsandbox") != -1):
                        TempLine = line.split(' ')
                        if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                            SandboxPath = TempLine[0]
                            list.append(copy.deepcopy(SandboxPath))  # deepcopy else reference not copy
                            SandboxPathOld = SandboxPath.replace("project.pj", "")
                    elif (line.find(" shared-subsandbox") != -1):
                        TempLine = line.split(' ')
                        if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                            SandboxPath = TempLine[0]
                            list.append(copy.deepcopy(SandboxPath))  # deepcopy else reference not copy
                            SandboxPathOld = SandboxPath.replace("project.pj", "")

            if (len(list) > 0):  # if more then one input
                return list
            return 2
        return 1

    def GetNoBuildSharedSubSandboxListRec(self, SandboxPath):
        ###########
        #
        # GetNoBuildSharedSubSandboxListRec(self,SandboxPath)
        #
        # Description:    Recursive Function: save the no build shared sandbox pathes to list starting from given SandboxPath
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         1 if fails, 2 if no entries found otherwise return list
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        SandboxPathOld = "|*#*?"  # initial *** are not to find
        line = ""
        list = []

        if (SandboxPath == "" or SandboxPath == 0):
            return 1

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --forceConfirm=yes --quiet --norecurse' % (
            self.Host, self.Port, SandboxPath)
        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return 1
        stdout_str, stderr_str = self.cliProcHandler.getcommunicate()
        if len(stdout_str) != 0:
            stdout_str_lines = stdout_str.splitlines()
            for line in stdout_str_lines:
                if (len(line) > 0):
                    if (line.find(" shared-variant-subsandbox") != -1):
                        TempLine = line.split(' ')
                        if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                            SandboxPath = TempLine[0]
                            list.append(copy.deepcopy(SandboxPath))  # deepcopy else reference not copy
                            SandboxPathOld = SandboxPath.replace("project.pj", "")
                    elif (line.find(" shared-subsandbox") != -1):
                        TempLine = line.split(' ')
                        if (TempLine[0].find(SandboxPathOld) == -1):  # filter the subfolder
                            SandboxPath = TempLine[0]
                            list.append(copy.deepcopy(SandboxPath))  # deepcopy else reference not copy
                            SandboxPathOld = SandboxPath.replace("project.pj", "")
                    elif (line.find(" subsandbox") != -1) or (line.find(" variant-subsandbox") != -1) or (
                                line.find(" build-subsandbox") != -1):
                        # print line.split(' ')[0]
                        ret_sandbox_dict = self.GetNoBuildSharedSubSandboxListRec(line.split(' ')[0])
                        if ret_sandbox_dict != 1 and ret_sandbox_dict != 2:
                            # print ret_sandbox_dict
                            list.extend(ret_sandbox_dict)

            if (len(list) > 0):  # if more then one input
                return list
            return 2
        return 1

    def CheckIfInternalShare(self, RootProject, CheckProject):
        ###########
        #
        # CheckIfInternalShare(self, RootProject, CheckProject)
        #
        # Description: Check if the share checkProject is inside of the RootProject
        #
        # Parameter: -RootProject the root Project
        #            -CheckProject the check project source of the share
        #
        # return a 0 it not InternalShare, 1 if internal share
        #
        # TODO: add parameter check
        #
        ###########
        RootProjectRaw = RootProject[0:RootProject.rfind('/')]
        CheckProjectStrip = CheckProject[0:len(RootProjectRaw)]

        # print RootProjectRaw
        # print CheckProjectStrip
        if (RootProjectRaw == CheckProjectStrip):
            return 1
        else:
            return 0

    def CheckIfPathShouldBeExcluded(self, Project, ExcludeFile):
        ###########
        #
        # CheckIfPathShouldBeExcluded(self, Project, ExcludeFile)
        #
        # Description: Return true if the Project is part of the exclude folders
        #
        # Parameter: -Project the project to check
        #            -ExcludeFile Exclude File containing the mks pathes to exclude
        #
        # return true if the Project should be excluded otherwise false
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = False
        # print Project
        if (ExcludeFile != None) and (ExcludeFile != ""):
            if os.path.isfile(ExcludeFile):
                file = open(ExcludeFile, 'r')
                MatchFound = False
                for line in file.readlines():
                    checkline = line.replace('\n', "")
                    if (checkline in Project) and len(checkline) > 0:
                        # TODO: is this really needed? THis does nothing.
                        MatchFound == True
                        break
                        # print line
                if MatchFound == True:
                    ret_value = True
            else:
                print "%s does not exist" % ExcludeFile
        return ret_value


class MksConfigDB_obj(logging_obj):
    ###########
    #
    # Description: Config shared sub projects class
    #
    ###########
    TABLE_COMPONENTS = "components"
    TABLE_SHARES = "shares"
    TABLE_MKS_PATHES = "mks_pathes"
    TABLE_HISTORY = "history"
    TABLE_SHARES_CFG = "shares_cfg"
    TABLE_SHARES_CFG_MAP = "shares_cfg_map"
    TABLE_CFG_RUN = "cfg_run"
    TABLE_LABELS = "labels"
    TABLE_DEV_PATHES = "dev_pathes"
    TABLE_DEV_PATH_REV = "dev_path_rev_map"
    TABLE_SHARE_TYPE = "share_type"
    TABLE_CFG_TYPE = "cfg_type"

    VIEW_SHARES = "view_shares"
    VIEW_SHARES_CFG = "view_shares_cfg"
    VIEW_DEV_PATHES = "view_dev_pathes"
    VIEW_PATH_HISTORY = "view_path_history"
    VIEW_SHARES_MAP = "view_shares_map"
    VIEW_HIST_PATH_COUNT = "view_hist_path_count"

    COL_NAME_MP_PATH_ID = "MKS_PATH_ID"
    COL_NAME_MP_PATH = "PATH"
    COL_NAME_MP_LAST_HSCAN = "LAST_HIST_RESCAN"
    COL_NAME_MP_COMP_ID = "COMP_ID"

    COL_NAME_CO_COMP_ID = "COMP_ID"
    COL_NAME_CO_NAME = "NAME"

    COL_NAME_SH_SHARE_ID = "SHARE_ID"
    COL_NAME_SH_FROM_PATH_ID = "FROM_MKS_PATH_ID"
    COL_NAME_SH_TO_PATH_ID = "TO_MKS_PATH_ID"
    COL_NAME_SH_SANDBOXPATH = "SANDBOXPATH"

    COL_NAME_HS_HISTORY_ID = "HISTORY_ID"
    COL_NAME_HS_MKS_PATH_ID = "MKS_PATH_ID"
    COL_NAME_HS_LABEL_ID = "LABEL_ID"
    COL_NAME_HS_REVISION = "REVISION"
    COL_NAME_HS_DEV_PATH_MAP_ID = "DEV_PATH_REV_MAP_ID"

    COL_NAME_DP_DEV_PATH_ID = "DEV_PATH_ID"
    COL_NAME_DP_NAME = "NAME"

    COL_NAME_DPR_MAP_ID = "DEV_PATH_REV_MAP_ID"
    COL_NAME_DPR_DEV_PATH_ID = "DEV_PATH_ID"
    COL_NAME_DPR_REVISION = "REVISION"

    COL_NAME_LB_LABEL_ID = "LABEL_ID"
    COL_NAME_LB_LABEL = "LABEL"

    COL_NAME_ST_TYPE_ID = "SHARE_TYPE_ID"
    COL_NAME_ST_TYPE = "TYPE"

    COL_NAME_CT_TYPE_ID = "CFG_TYPE_ID"
    COL_NAME_CT_TYPE = "TYPE"

    COL_NAME_SC_CFG_ID = "SH_CFG_ID"
    COL_NAME_SC_RUN_ID = "RUN_ID"
    COL_NAME_SC_CFG_TYPE_ID = "CFG_TYPE_ID"
    COL_NAME_SC_COMP_ID = "COMP_ID"
    COL_NAME_SC_TYPE_ID = "SHARE_TYPE_ID"
    COL_NAME_SC_DEV_PATH_ID = "DEV_PATH_ID"
    COL_NAME_SC_LABEL_ID = "LABEL_ID"
    COL_NAME_SC_SOURCE_PATH_ID = "SOURCE_MKS_PATH_ID"
    COL_NAME_SC_TARGET_PATH_ID = "TARGET_MKS_PATH_ID"

    COL_NAME_SCM_MAP_ID = "SH_MAP_ID"
    COL_NAME_SCM_CFG_ID = "SH_CFG_ID"
    COL_NAME_SCM_SHARE_ID = "SHARE_ID"
    COL_NAME_SCM_HISTORY_ID = "HISTORY_ID"

    COL_NAME_RC_RUN_ID = "RUN_ID"
    COL_NAME_RC_DATE = "DATE"
    COL_NAME_RC_PREV = "PREV_RUN_ID"

    COL_NAME_SHV_SHARE_ID = "SHARE_ID"
    COL_NAME_SHV_PATH_FROM = "PATH_FROM"
    COL_NAME_SHV_PATH_FROM_ID = "PATH_FROM_ID"
    COL_NAME_SHV_PATH_TO = "PATH_TO"
    COL_NAME_SHV_PATH_TO_ID = "PATH_TO_ID"
    COL_NAME_SHV_SANDBOX = "SANDBOXPATH"
    COL_NAME_SHV_COMP_NAME = "NAME"

    COL_NAME_DPMV_MAP_ID = "DEV_PATH_REV_MAP_ID"
    COL_NAME_DPMV_DEV_PATH_ID = "DEV_PATH_ID"
    COL_NAME_DPMV_NAME = "NAME"
    COL_NAME_DPMV_REVISION = "REVISION"

    COL_NAME_PHV_HISTORY_ID = "HISTORY_ID"
    COL_NAME_PHV_MKS_PATH = "PATH"
    COL_NAME_PHV_LABEL = "LABEL"
    COL_NAME_PHV_REVISION = "REVISION"
    COL_NAME_PHV_DP_NAME = "DEV_PATH_NAME"
    COL_NAME_PHV_DP_REVISION = "DEV_PATH_REV"

    COL_NAME_SCV_RUN_ID = "RUN_ID"
    COL_NAME_SCV_DATE = "DATE"
    COL_NAME_SCV_SH_CFG_ID = "SH_CFG_ID"
    COL_NAME_SCV_CFG_TYPE = "CFG_TYPE"
    COL_NAME_SCV_COMP_NAME = "COMP_NAME"
    COL_NAME_SCV_TYPE = "TYPE"
    COL_NAME_SCV_LABEL = "LABEL"
    COL_NAME_SCV_DP_NAME = "DEV_PATH_NAME"
    COL_NAME_SCV_SOURCE_PATH = "SOURCE_PATH"
    COL_NAME_SCV_TARGET_PATH = "TARGET_PATH"

    COL_NAME_SMV_TARGET_PATH = "TARGET_PATH"
    COL_NAME_SMV_SOURCE_PATH = "SOURCE_PATH"
    COL_NAME_SMV_CFG_TYPE = "CFG_TYPE"
    COL_NAME_SMV_COMP_NAME = "COMP_NAME"
    COL_NAME_SMV_SH_TYPE = "TYPE"
    COL_NAME_SMV_LABEL = "LABEL"
    COL_NAME_SMV_DEV_PATH_NAEM = "DEV_PATH_NAME"
    COL_NAME_SMV_CFG_SOURCE_PATH = "CFG_SOURCE_PATH"
    COL_NAME_SMV_CFG_TARGET_PATH = "CFG_TARGET_PATH"
    COL_NAME_SMV_SHARE_ID = "SHARE_ID"
    COL_NAME_SMV_MAP_ID = "SH_MAP_ID"
    COL_NAME_SMV_RUN_ID = "RUN_ID"
    COL_NAME_SMV_CFG_ID = "SH_CFG_ID"

    COL_NAME_HPC_PATH = "PATH"
    COL_NAME_HPC_COUNT = "COUNT"

    CFG_TYPE_BASE = "Base"
    CFG_TYPE_CUSTOM_V1 = "Custom"
    CFG_TYPE_CUSTOM_V2 = "CustomV2"
    CFG_TYPE_CUSTOM_V3 = "CustomV3"

    CFG_SH_TYPE_NORMAL = "normal"
    CFG_SH_TYPE_VARIANT = "variant"
    CFG_SH_TYPE_BUILD = "build"

    COMP_NOT_KNOWN = "NotKnown"
    LABEL_NOT_KNOWN = "NotKnown"

    def __init__(self, root_path, destination="console", LogType={}, log_file_object=0):
        logging_obj.__init__(self, destination, LogType, log_file_object)

        # check the the db file
        dbFile = "%s\\BuildFarmResults.db" % (root_path)
        if not os.path.isfile(dbFile):
            file_object = open(dbFile, "w")
            file_object.close()

        try:
            # connect, create cursor
            self.db_conn = sqlite3.connect(dbFile)
            self.db_cursor = self.db_conn.cursor()
            # switch on foreign keys
            query = 'pragma foreign_keys = on;'
            self.db_cursor.execute(query)
            self.db_conn.commit()
        except:
            self.Log("Error", "Could not establisch data base connection")

    def raw_query(self, sql_stmt):
        ###########
        # Exceutes raw queries
        # @param sql_stmt The sql command to execute
        # @return Returns the list of selected data if any.
        #
        # TODO: add parameter check
        #
        ###########
        stmt = str(sql_stmt)

        record_list = []
        cursor = self.db_conn.cursor()
        try:
            cursor.execute(stmt)
            try:
                rows = cursor.fetchall()
            except:
                pass

            # TODO: rows must be iniated
            for row in rows:
                colindex = 0
                columns = {}
                for column in cursor.description:
                    columns[str(column[0].upper())] = row[colindex]
                    colindex += 1
                record_list.append(columns)
        except:
            raise StandardError("Error while executing query: '%s'" % stmt)
        finally:
            cursor.close()

        # done
        return record_list

    def Commit(self):
        ###########
        #
        # Commit(self)
        #
        # Description: Commits the database
        #
        # return
        #
        # TODO: add parameter check
        #
        ###########
        self.db_conn.commit()

    def CheckDBTabels(self):
        ###########
        #
        # CheckDBTabels(self)
        #
        # Description: Check the DBTabels
        #
        # return 0 in case of no error
        #
        # TODO: add parameter check
        #
        ###########
        getAllTables = """SELECT name FROM sqlite_master
WHERE type IN ('table','view') AND name NOT LIKE 'sqlite_%'
UNION ALL
SELECT name FROM sqlite_temp_master
WHERE type IN ('table','view')
ORDER BY 1"""

        data = self.raw_query(getAllTables)
        CreateComonent = True
        CreateShares = True
        CreateMksPathes = True
        CreateHistory = True
        CreateSharesCfg = True
        CreateShareCfgMap = True
        CreateCfgRun = True
        CreateLabels = True
        CreateDevPathes = True
        CreateDevPathRev = True
        CreateShareType = True
        CreateCfgType = True

        CreateViewShare = True
        CreateViewShareCfg = True
        CreateViewDevPathes = True
        CreateViewHistory = True
        CreateViewSharesMap = True
        CreateViewHistPathCounter = True

        # print data
        for line in data:
            if line["NAME"] == self.TABLE_COMPONENTS:
                CreateComonent = False
            if line["NAME"] == self.TABLE_SHARES:
                CreateShares = False
            if line["NAME"] == self.TABLE_MKS_PATHES:
                CreateMksPathes = False
            if line["NAME"] == self.TABLE_HISTORY:
                CreateHistory = False
            if line["NAME"] == self.TABLE_SHARES_CFG:
                CreateSharesCfg = False
            if line["NAME"] == self.TABLE_SHARES_CFG_MAP:
                CreateShareCfgMap = False
            if line["NAME"] == self.TABLE_CFG_RUN:
                CreateCfgRun = False
            if line["NAME"] == self.TABLE_LABELS:
                CreateLabels = False
            if line["NAME"] == self.TABLE_DEV_PATHES:
                CreateDevPathes = False
            if line["NAME"] == self.TABLE_DEV_PATH_REV:
                CreateDevPathRev = False
            if line["NAME"] == self.TABLE_SHARE_TYPE:
                CreateShareType = False
            if line["NAME"] == self.TABLE_CFG_TYPE:
                CreateCfgType = False

            if line["NAME"] == self.VIEW_SHARES:
                CreateViewShare = False
            if line["NAME"] == self.VIEW_SHARES_CFG:
                CreateViewShareCfg = False
            if line["NAME"] == self.VIEW_DEV_PATHES:
                CreateViewDevPathes = False
            if line["NAME"] == self.VIEW_PATH_HISTORY:
                CreateViewHistory = False
            if line["NAME"] == self.VIEW_SHARES_MAP:
                CreateViewSharesMap = False
            if line["NAME"] == self.VIEW_HIST_PATH_COUNT:
                CreateViewHistPathCounter = False

        if CreateComonent == True:
            self.db_cursor.execute("""create table components
(
comp_id integer unique not null,
name varchar(25) unique not null,
primary key (comp_id autoincrement )
);
"""
                                   )
            self.Log("Info", "Create componet table")
        if CreateShares == True:
            self.db_cursor.execute("""create table shares
(
share_id integer unique not null,
from_mks_path_id integer not null,
to_mks_path_id integer not null,
sandboxpath varchar(255),
primary key (share_id autoincrement )
constraint only_one_share unique(from_mks_path_id, to_mks_path_id, sandboxpath)
constraint fk_from_mks_path_id foreign key (from_mks_path_id) references mks_pathes (mks_path_id)
constraint fk_to_mks_path_id foreign key (to_mks_path_id) references mks_pathes (mks_path_id)
);
""")
            self.Log("Info", "Create shares table")

        if CreateMksPathes == True:
            self.db_cursor.execute("""create table mks_pathes
(
mks_path_id integer unique not null,
path varchar(255) unique not null,
last_hist_rescan datetime default null,
comp_id integer default null,
primary key (mks_path_id autoincrement )
constraint fk_comp_id foreign key (comp_id) references components (comp_id)
);
""")
            self.Log("Info", "Create mks pathes table")

        if CreateHistory == True:
            self.db_cursor.execute("""create table history
(
history_id integer unique not null,
mks_path_id integer not null,
revision varchar(50),
label_id interger not null,
dev_path_rev_map_id interger,
primary key (history_id autoincrement )
constraint only_one_label unique(mks_path_id, label_id, revision)
constraint fk_mks_path_id foreign key (mks_path_id) references mks_pathes (mks_path_id)
constraint fk_label_id foreign key (label_id) references labels (label_id)
constraint fk_dev_path_rev_map_id foreign key (dev_path_rev_map_id) references dev_path_rev_map (dev_path_rev_map_id)
);
""")
            self.Log("Info", "Create history table")

        if CreateSharesCfg == True:
            self.db_cursor.execute("""create table shares_cfg
(
sh_cfg_id integer unique not null,
run_id integer not null,
cfg_type_id integer not null,
comp_id integer not null,
share_type_id integer not null,
dev_path_id integer,
label_id integer,
source_mks_path_id integer,
target_mks_path_id integer,
primary key (sh_cfg_id autoincrement )
constraint only_one_config unique(run_id, cfg_type_id, comp_id, source_mks_path_id, target_mks_path_id, share_type_id)
constraint fk_share_type_id foreign key (share_type_id) references share_type (share_type_id)
constraint fk_cfg_type_id foreign key (cfg_type_id) references cfg_type (cfg_type_id)
constraint fk_label_id foreign key (label_id) references labels (label_id)
constraint fk_dev_path_id foreign key (dev_path_id) references dev_pathes (dev_path_id)
constraint fk_run_id foreign key (run_id) references cfg_run (run_id)
constraint fk_comp_id foreign key (comp_id) references components (comp_id)
constraint fk_source_mks_path_id foreign key (source_mks_path_id) references mks_pathes (mks_path_id)
constraint fk_target_mks_path_id foreign key (target_mks_path_id) references mks_pathes (mks_path_id)
);
""")
            self.Log("Info", "Create shares cfg table")

        if CreateShareCfgMap == True:
            self.db_cursor.execute("""CREATE TABLE shares_cfg_map
(
sh_map_id INTEGER NOT NULL,
sh_cfg_id INTEGER NOT NULL,
share_id INTEGER NOT NULL,
history_id INTEGER,
primary key (sh_map_id autoincrement )
constraint fk_sh_cfg_id foreign key (sh_cfg_id) references shares_cfg (sh_cfg_id)
constraint fk_share_id foreign key (share_id) references shares (share_id)
constraint fk_history_id foreign key (history_id) references history (history_id)
)
""")
            self.Log("Info", "Create share cfg map table")

        if CreateCfgRun == True:
            self.db_cursor.execute("""create table cfg_run
(
run_id integer unique not null,
date datetime unique,
prev_run_id integer,
last_crc integer,
primary key (run_id autoincrement )
constraint fk_prev_run_id foreign key (prev_run_id) references cfg_run (run_id)
);
""")
            self.Log("Info", "Create cfg run table")

        if CreateLabels == True:
            self.db_cursor.execute("""create table labels
(
label_id INTEGER unique NOT NULL,
label TEXT NOT NULL,
primary key (label_id autoincrement )
);
""")
            self.Log("Info", "Create labels")

        if CreateDevPathes == True:
            self.db_cursor.execute("""create table dev_pathes
(
dev_path_id INTEGER unique NOT NULL,
name TEXT unique NOT NULL,
primary key (dev_path_id autoincrement )
);
""")
            self.Log("Info", "Create dev pathes")

        if CreateDevPathRev == True:
            self.db_cursor.execute("""create table dev_path_rev_map
(
dev_path_rev_map_id INTEGER unique NOT NULL,
dev_path_id INTEGER NOT NULL,
revision TEXT NOT NULL,
primary key (dev_path_rev_map_id autoincrement )
constraint fk_dev_path_id foreign key (dev_path_id) references dev_pathes (dev_path_id)
);
""")
            self.Log("Info", "Create dev pathes")

        if CreateShareType == True:
            self.db_cursor.execute("""create table share_type
(
share_type_id INTEGER NOT NULL,
type TEXT UNIQUE NOT NULL,
primary key (share_type_id autoincrement )
);
""")
            self.Log("Info", "Create share type")
            try:
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_SHARE_TYPE, self.COL_NAME_ST_TYPE, "normal")
                self.db_cursor.execute(query)
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_SHARE_TYPE, self.COL_NAME_ST_TYPE, "variant")
                self.db_cursor.execute(query)
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_SHARE_TYPE, self.COL_NAME_ST_TYPE, "build")
                self.db_cursor.execute(query)
                self.db_conn.commit()
            except ValueError:
                # TODO: query must be initiated
                print "error, could not add share %s to db" % query
                return None

        if CreateCfgType == True:
            self.db_cursor.execute("""create table cfg_type
(
cfg_type_id INTEGER NOT NULL,
type TEXT UNIQUE NOT NULL,
primary key (cfg_type_id autoincrement )
);
""")
            self.Log("Info", "Create cfg type")
            try:
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (
                    self.TABLE_CFG_TYPE, self.COL_NAME_CT_TYPE, self.CFG_TYPE_BASE)
                self.db_cursor.execute(query)
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (
                    self.TABLE_CFG_TYPE, self.COL_NAME_CT_TYPE, self.CFG_TYPE_CUSTOM_V1)
                self.db_cursor.execute(query)
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (
                    self.TABLE_CFG_TYPE, self.COL_NAME_CT_TYPE, self.CFG_TYPE_CUSTOM_V2)
                self.db_cursor.execute(query)
                query = 'INSERT INTO %s (%s) VALUES("%s");' % (
                    self.TABLE_CFG_TYPE, self.COL_NAME_CT_TYPE, self.CFG_TYPE_CUSTOM_V3)
                self.db_cursor.execute(query)
                self.db_conn.commit()
            except ValueError:
                # TODO: query must be initiated
                print "error, could not add config types %s to db" % query
                return None

        if CreateViewShare == True:
            self.db_cursor.execute("""create view view_shares as select sh.share_id as share_id, mks_f.path as path_from, mks_f.mks_path_id as path_from_id, mks_t.path as path_to, mks_t.mks_path_id as path_to_id, sh.sandboxpath, co.name
from shares sh
inner join mks_pathes mks_f on sh.from_mks_path_id = mks_f.mks_path_id
inner join mks_pathes mks_t on sh.to_mks_path_id = mks_t.mks_path_id
inner join components co on mks_f.comp_id = co.comp_id;
""")
            self.Log("Info", "Create share view")
        if CreateViewShareCfg == True:
            self.db_cursor.execute("""CREATE VIEW view_shares_cfg as select cr.run_id as run_id, cr.date, shc.sh_cfg_id as sh_cfg_id, ct.type as cfg_type, co.name as comp_name, st.type as type, lb.label as label, dp.name as dev_path_name, mp_s.path as source_path, mp_t.path as target_path
from cfg_run cr
inner join shares_cfg shc on cr.run_id = shc.run_id
inner join cfg_type ct on shc.cfg_type_id = ct.cfg_type_id
inner join components co on shc.comp_id = co.comp_id
inner join share_type st on shc.share_type_id = st.share_type_id
left outer join labels lb on shc.label_id = lb.label_id
left outer join dev_pathes dp on shc.dev_path_id = dp.dev_path_id
left outer join mks_pathes mp_s on shc.source_mks_path_id = mp_s.mks_path_id
left outer join mks_pathes mp_t on shc.target_mks_path_id = mp_t.mks_path_id
""")
            self.Log("Info", "Create share cfg view")

        if CreateViewDevPathes == True:
            self.db_cursor.execute("""CREATE VIEW view_dev_pathes as select dpm.dev_path_rev_map_id, dpm.dev_path_id, dp.name, dpm.revision
from dev_path_rev_map dpm
inner join dev_pathes dp on dpm.dev_path_id = dp.dev_path_id
""")
            self.Log("Info", "Create dev pathes view")

        if CreateViewHistory == True:
            self.db_cursor.execute("""CREATE VIEW view_path_history as select hs.history_id as history_id, hs.mks_path_id, mks.path, mks.last_hist_rescan, lb.label, hs.revision, dpv.name as dev_path_name, dpv.revision as dev_path_rev, co.name as comp_name
from history hs
inner join mks_pathes mks on hs.mks_path_id = mks.mks_path_id
inner join labels lb on hs.label_id = lb.label_id
left outer join view_dev_pathes dpv on hs.dev_path_rev_map_id = dpv.dev_path_rev_map_id
inner join components co on mks.comp_id = co.comp_id
""")
            self.Log("Info", "Create history view")

        if CreateViewSharesMap == True:
            self.db_cursor.execute("""CREATE VIEW view_shares_map as select shv.path_from as source_path, shv.path_to as target_path, shcv.cfg_type, shcv.comp_name, shcv.type, shcv.label, shcv.dev_path_name, shcv.source_path as cfg_source_path, shcv.target_path as cfg_target_path, shv.share_id, shm.sh_map_id, shcv.run_id, shcv.sh_cfg_id
from view_shares shv
inner join shares_cfg_map shm on shv.share_id = shm.share_id
inner join view_path_history phv on phv.history_id = shm.history_id
inner join view_shares_cfg shcv on shcv.sh_cfg_id = shm.sh_cfg_id
""")
            self.Log("Info", "Create Shares map view")

        if CreateViewHistPathCounter == True:
            self.db_cursor.execute("""CREATE VIEW view_hist_path_count as select path, count(mks_path_id) as count
from view_path_history group by mks_path_id
""")
            self.Log("Info", "Create Hist path counter view")

    def CheckRescan(self, mks_path_from):
        ###########
        #
        # CheckRescan(self, mks_path_from)
        #
        # Description:    Check if history resacn is needed for mks project
        #
        # Parameter:      mks_path_from
        #
        # Return:         true in case of rescan is needed
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        # if last rescan == None
        # self.Log("Info", "CheckRescann1")
        if self.GetPathRescanDate(mks_path_from) == None:
            return True

        # if history empty
        # self.Log("Info", "CheckRescann2")
        if self.GetNumOfHistoryEntry(mks_path_from) == 0:
            # if self.GetHistoryForProject(mks_path_from) == None:
            # self.Log("Info", "CheckRescann31")
            return True
        # self.Log("Info", "CheckRescann32")

        return False

    def AddShare(self, mks_path_from, mks_path_to, comp_name, sandboxpath=""):
        ###########
        #
        # AddShare(self, mks_path_from, mks_path_to, comp_name, sandboxpath="")
        #
        # Description:    add the share info to the database
        #
        # Parameter:      mks_path_from
        #                 mks_path_to
        #                 comp_name
        #                 sandboxpath
        #
        # Return:
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        share_id, from_id, to_id, comp_id = self.GetShareID(mks_path_from, mks_path_to, comp_name)

        if share_id != None:
            return share_id

        if from_id != None and to_id != None and comp_id != None:
            query = 'INSERT INTO %s (%s, %s, %s) VALUES("%s", "%s", "%s");' % (
                self.TABLE_SHARES, self.COL_NAME_SH_FROM_PATH_ID, self.COL_NAME_SH_TO_PATH_ID,
                self.COL_NAME_SH_SANDBOXPATH,
                from_id, to_id, sandboxpath)
            try:
                self.db_cursor.execute(query)
                self.db_conn.commit()
            except ValueError:
                print "error, could not add share %s to db" % query
                return None

            share_id, from_id, to_id, comp_id = self.GetShareID(mks_path_from, mks_path_to, comp_name)

            if share_id != None:
                return share_id
            else:
                return None
        else:
            print "error, Could not add share, one of the input id's if Null"
            return None

    def GetShareID(self, mks_path_from, mks_path_to, comp_name=None):
        ###########
        #
        # GetShareID(self, mks_path_from, mks_path_to, comp_name=None)
        #
        # Description:    Get the share id
        #
        # Parameter:      mks_path_from
        #                 mks_path_to
        #                 comp_name
        #
        # Return:         the share id or None, from_id or None, to_id or None, comp_id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s";' % (
            self.VIEW_SHARES, self.COL_NAME_SHV_PATH_FROM, mks_path_from,
            self.COL_NAME_SHV_PATH_TO, mks_path_to)

        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return (ret_data[0][self.COL_NAME_SHV_SHARE_ID], ret_data[0][self.COL_NAME_SHV_PATH_FROM_ID],
                    ret_data[0][self.COL_NAME_SHV_PATH_TO_ID],
                    self.GetComponentId(ret_data[0][self.COL_NAME_SHV_COMP_NAME]))
        else:
            from_id = self.AddPath(mks_path_from, comp_name)
            to_id = self.AddPath(mks_path_to)

            comp_id = None
            if comp_name != None:
                comp_id = self.AddComponent(comp_name)

            if from_id != None and to_id != None:
                query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s"' % (
                    self.VIEW_SHARES, self.COL_NAME_SHV_PATH_FROM_ID, from_id,
                    self.COL_NAME_SHV_PATH_TO_ID, to_id)

                if comp_name != None:
                    query += ' and %s="%s"' % (self.COL_NAME_SHV_COMP_NAME, comp_name)

                query += ';'
                ret_data = self.raw_query(query)
                if len(ret_data) == 1:
                    return (ret_data[0][self.COL_NAME_SH_SHARE_ID], from_id, to_id, comp_id)
                else:
                    return (None, from_id, to_id, comp_id)

            return (None, None, None, None)

    def GetShare(self, sandbox):
        ###########
        #
        # GetShare(self, sandbox)
        #
        # Description:    Get the share record for the sandbox
        #
        # Parameter:      sandbox
        #
        # Return:         share record or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.VIEW_SHARES, self.COL_NAME_SHV_SANDBOX, sandbox)

        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0]
        else:
            return None

    def AddPath(self, mks_path, comp_name=None, late_commit=False):
        ###########
        #
        # AddPath(self, mks_path)
        #
        # Description:    add the mks path
        #
        # Parameter:      mks_path
        #                 late_commit
        #
        # Return:         mks path id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        comp_id = None
        if comp_name != None:
            comp_id = self.AddComponent(comp_name)

        path_id = self.GetPathId(mks_path)
        if path_id == None:
            query = 'INSERT INTO %s (%s' % (self.TABLE_MKS_PATHES, self.COL_NAME_MP_PATH)
            if comp_name != None:
                query += ' , %s' % (self.COL_NAME_MP_COMP_ID)

            query += ') VALUES("%s"' % (mks_path)

            if comp_name != None:
                query += ', "%s"' % (comp_id)
            query += ');'
            try:
                self.db_cursor.execute(query)
                if late_commit == False:
                    self.db_conn.commit()
            except ValueError:
                print "error, could not add mks path %s to db" % query
                return None
            return self.GetPathId(mks_path)
        else:
            return path_id

    def GetPathId(self, mks_path):
        ###########
        #
        # GetPathId(self, mks_path)
        #
        # Description:    get the mks path
        #
        # Parameter:      mks_path
        #
        # Return:         mks path id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.TABLE_MKS_PATHES, self.COL_NAME_MP_PATH, mks_path)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_MP_PATH_ID]
        else:
            return None

    def UpdateRescanDate(self, mks_path):
        ###########
        #
        # UpdateRescanDate(self, mks_path)
        #
        # Description:    Update rescan date
        #
        # Parameter:      mks_path
        #
        # Return:         true if update was successfull otherwise false
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'UPDATE %s SET %s="%s" WHERE %s="%s";' % (
            self.TABLE_MKS_PATHES, self.COL_NAME_MP_LAST_HSCAN, datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            self.COL_NAME_MP_PATH, mks_path)
        try:
            self.db_cursor.execute(query)
            self.db_conn.commit()
        except:
            print "error, could not update histroy %s to db" % query
            return False

        return True

    def GetPathRescanDate(self, mks_path):
        ###########
        #
        # GetPathRescanDate(self, mks_path)
        #
        # Description:    get the mks path rescan date
        #
        # Parameter:      mks_path
        #
        # Return:         mks path rescan data
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.TABLE_MKS_PATHES, self.COL_NAME_MP_PATH, mks_path)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_MP_LAST_HSCAN]
        else:
            return None

    def CheckForTenOldesRescanCanditates(self, mks_path):
        ###########
        #
        # CheckForTenOldesRescanCanditates(self, mks_path)
        #
        # Description:    check if mks path is one of the 5 % hotest rescan candidates
        #
        # Parameter:      mks_path
        #
        # Return:         true if path should be rescaned
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM (SELECT * FROM %s WHERE %s not null ORDER BY %s ASC  LIMIT  (select round(count(%s)*0.05) from mks_pathes where %s is not null)  ) WHERE %s="%s";' % (
            self.TABLE_MKS_PATHES,
            self.COL_NAME_MP_LAST_HSCAN,
            self.COL_NAME_MP_LAST_HSCAN,
            self.COL_NAME_MP_PATH_ID,
            self.COL_NAME_MP_LAST_HSCAN,
            self.COL_NAME_MP_PATH,
            mks_path)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return True
        else:
            return False

    def GetTenOldesRescanCanditates(self):
        ###########
        #
        # CheckForTenOldesRescanCanditates(self)
        #
        # Description:    get the 5 % hotest rescan candidates
        #
        # Parameter:      -
        #
        # Return:         list with mks pathes otherwise empty list
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s not null ORDER BY %s ASC  LIMIT (select round(count(%s)*0.05) from mks_pathes where %s is not null);' % (
            self.TABLE_MKS_PATHES, self.COL_NAME_MP_LAST_HSCAN, self.COL_NAME_MP_LAST_HSCAN, self.COL_NAME_MP_PATH_ID,
            self.COL_NAME_MP_LAST_HSCAN)
        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            ret_value = []
            for item in ret_data:
                ret_value.append(item[self.COL_NAME_MP_PATH])
            return ret_value
        else:
            return []

    def AddDevPath(self, dev_path_name, revision, late_commit=False):
        ###########
        #
        # AddDevPath(self, dev_path_name)
        #
        # Description:    Add dev path name to database
        #
        # Parameter:      dev_path_name
        #                 revision
        #                 late_commit
        #
        # Return:         the dev path id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        dev_path = self.GetDevPath(dev_path_name)
        # dev pathe does not exist at all
        if dev_path == None:
            # first add the dev path name
            query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_DEV_PATHES, self.COL_NAME_DP_NAME, dev_path_name)
            try:
                self.db_cursor.execute(query)
                if late_commit == False:
                    self.db_conn.commit()
            except ValueError:
                print "error, could not add dev path %s to db" % query
                return None

            dev_path_id = self.GetDevPathId(dev_path_name)
            # scond add the dev path map entry
            query = 'INSERT INTO %s (%s,%s) VALUES("%s","%s");' % (
                self.TABLE_DEV_PATH_REV, self.COL_NAME_DPR_DEV_PATH_ID, self.COL_NAME_DPR_REVISION,
                dev_path_id, revision)
            try:
                self.db_cursor.execute(query)
                if late_commit == False:
                    self.db_conn.commit()
            except ValueError:
                print "error, could not add dev map path %s to db" % query
                return None

            return dev_path_id
        else:
            # dev path name does exist
            dev_path_map = self.GetDevPathMap(dev_path_name, revision)
            # check if revision is aleady existing if not add the new revision to the map
            if dev_path_map == None:
                query = 'INSERT INTO %s (%s,%s) VALUES("%s","%s");' % (
                    self.TABLE_DEV_PATH_REV, self.COL_NAME_DPR_DEV_PATH_ID, self.COL_NAME_DPR_REVISION,
                    dev_path[self.COL_NAME_DP_DEV_PATH_ID], revision)
                try:
                    self.db_cursor.execute(query)
                    if late_commit == False:
                        self.db_conn.commit()
                except ValueError:
                    print "error, could not add dev map path %s to db" % query
                    return None

            return dev_path[self.COL_NAME_DP_DEV_PATH_ID]

    def GetDevPathId(self, dev_path_name):
        ###########
        #
        # GetDevPathId(self, dev_path_name)
        #
        # Description:    get dev path name id
        #
        # Parameter:      dev_path_name
        #
        # Return:         comp_name id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.TABLE_DEV_PATHES, self.COL_NAME_DP_NAME, dev_path_name)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_DP_DEV_PATH_ID]
        else:
            return None

    def GetDevPath(self, dev_path_name):
        ###########
        #
        # GetDevPath(self, dev_path_name)
        #
        # Description:    get dev path record
        #
        # Parameter:      dev_path_name
        #
        # Return:         record
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.TABLE_DEV_PATHES, self.COL_NAME_DP_NAME, dev_path_name)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0]
        else:
            return None

    def GetAllDevPathes(self, shared_path, mks_path_id=None):
        ###########
        #
        # GetAllDevPathes(self, shared_path)
        #
        # Description:    get dev path dict for shared path
        #
        # Parameter:      shared_path
        #
        # Return:         dev path revision dict or empty dict
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        if mks_path_id == None:
            mks_path_id = self.GetPathId(shared_path)

        query = """SELECT m.%s, d.%s FROM %s m
                   inner join %s d  on m.%s = d.%s
                   where m.%s in (SELECT %s FROM history where %s = %s and %s is not null group by %s)
                   order by d.%s desc;""" % (
            self.COL_NAME_DPR_REVISION, self.COL_NAME_DP_NAME, self.TABLE_DEV_PATH_REV,
            self.TABLE_DEV_PATHES, self.COL_NAME_DPR_DEV_PATH_ID, self.COL_NAME_DP_DEV_PATH_ID,
            self.COL_NAME_DPR_MAP_ID,
            self.COL_NAME_HS_DEV_PATH_MAP_ID, self.COL_NAME_HS_MKS_PATH_ID, mks_path_id,
            self.COL_NAME_HS_DEV_PATH_MAP_ID, self.COL_NAME_HS_DEV_PATH_MAP_ID,
            self.COL_NAME_DP_NAME)

        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            dict = {}
            for item in ret_data:
                dict[item[self.COL_NAME_DP_NAME]] = item[self.COL_NAME_DPR_REVISION]
            return dict
        else:
            return {}

    def GetDevPathRev(self, shared_path, dev_path_name):
        ###########
        #
        # GetDevPathRev(self, shared_path, dev_path_name)
        #
        # Description:    get dev path revision
        #
        # Parameter:      shared_path
        #
        # Return:         dev path revision or none
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        # select * from dev_path_rev_map where dev_path_rev_map_id in (SELECT dev_path_rev_map_id FROM history where mks_path_id = 85 and dev_path_rev_map_id is not null group by dev_path_rev_map_id)
        # and dev_path_id = (select dev_path_id from dev_pathes where name = "AL_FCT_MFC4T0_02.15.00_R20")
        mks_path_id = self.GetPathId(shared_path)
        query = 'SELECT * FROM %s WHERE %s in (SELECT %s FROM %s WHERE %s = %s and %s is not null group by %s) and %s = (SELECT %s FROM %s WHERE %s = "%s")' % (
            self.TABLE_DEV_PATH_REV,
            self.COL_NAME_DPR_MAP_ID,
            self.COL_NAME_HS_DEV_PATH_MAP_ID, self.TABLE_HISTORY,
            self.COL_NAME_HS_MKS_PATH_ID, mks_path_id, self.COL_NAME_HS_DEV_PATH_MAP_ID,
            self.COL_NAME_HS_DEV_PATH_MAP_ID,
            self.COL_NAME_DPR_DEV_PATH_ID,
            self.COL_NAME_DP_DEV_PATH_ID, self.TABLE_DEV_PATHES, self.COL_NAME_DP_NAME, dev_path_name)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_DPR_REVISION]
        else:
            return None

    def GetDevPathsLabelRevDict(self, shared_path):
        ###########
        #
        # GetDevPathsLabelRevDict(self, shared_path)
        #
        # Description:    get dev path labels dict for shared path
        #
        # Parameter:      shared_path
        #
        # Return:         dev path labels revision dict or empty dict
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT %s, %s, %s FROM %s WHERE %s="%s";' % (
            self.COL_NAME_PHV_DP_NAME, self.COL_NAME_PHV_LABEL, self.COL_NAME_PHV_REVISION, self.VIEW_PATH_HISTORY,
            self.COL_NAME_PHV_MKS_PATH, shared_path)
        ret_data = self.raw_query(query)

        dict = {}
        if len(ret_data) > 0:
            for item in ret_data:
                path = item[self.COL_NAME_PHV_DP_NAME]
                if path not in dict:
                    dict[path] = {}
                dict[path][item[self.COL_NAME_PHV_LABEL]] = item[self.COL_NAME_PHV_REVISION]

        return dict

    def GetDevPathesDevPathsLabelRevDictAndLabels(self, shared_path):
        ###########
        #
        # GetDevPathesDevPathsLabelRevDictAndLabels(self, shared_path)
        #
        # Description:    get dev path revision dict, get the dev pathe labels dict and get the labels revsion dict for shared path
        #
        # Parameter:      shared_path
        #
        # Return:         dev path labels revision dict or empty dict
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        mks_path_id = self.GetPathId(shared_path)

        query = """SELECT dp.%s, dpr.%s as %s, lb.%s, hs.%s
                   FROM %s hs
                   INNER JOIN %s lb on hs.%s = lb.%s
                   LEFT OUTER JOIN %s dpr on hs.%s = dpr.%s
                   LEFT OUTER JOIN %s dp on dpr.%s = dp.%s
                   WHERE hs.%s = "%s"
                   ORDER BY hs.%s """ % (
            self.COL_NAME_DP_NAME, self.COL_NAME_DPR_REVISION, self.COL_NAME_PHV_DP_REVISION, self.COL_NAME_LB_LABEL,
            self.COL_NAME_HS_REVISION,
            self.TABLE_HISTORY,
            self.TABLE_LABELS, self.COL_NAME_HS_LABEL_ID, self.COL_NAME_LB_LABEL_ID,
            self.TABLE_DEV_PATH_REV, self.COL_NAME_HS_DEV_PATH_MAP_ID, self.COL_NAME_DPR_MAP_ID,
            self.TABLE_DEV_PATHES, self.COL_NAME_DPR_DEV_PATH_ID, self.COL_NAME_DP_DEV_PATH_ID,
            self.COL_NAME_HS_MKS_PATH_ID, mks_path_id,
            self.COL_NAME_HS_REVISION)

        ret_data = self.raw_query(query)

        dev_path_dict = {}
        dev_path_label_dict = {}
        label_dict = {}
        if len(ret_data) > 0:
            for item in ret_data:
                path = item[self.COL_NAME_DP_NAME]
                if path not in dev_path_dict:
                    dev_path_dict[path] = {}
                if path not in dev_path_label_dict:
                    dev_path_label_dict[path] = {}
                if path not in label_dict:
                    label_dict[path] = {}

                dev_path_dict[path] = item[self.COL_NAME_PHV_DP_REVISION]
                dev_path_label_dict[path][item[self.COL_NAME_LB_LABEL]] = item[self.COL_NAME_HS_REVISION]
                label_dict[item[self.COL_NAME_LB_LABEL]] = item[self.COL_NAME_HS_REVISION]

        return (dev_path_dict, dev_path_label_dict, label_dict)

    def GetDevPathMap(self, dev_path_name, revision):
        ###########
        #
        # GetDevPathMap(self, sdev_path_name, revision)
        #
        # Description:    get the dev path map record
        #
        # Parameter:      shared_path
        #
        # Return:         dev path map record or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s"' % (
            self.VIEW_DEV_PATHES, self.COL_NAME_DPMV_NAME, dev_path_name,
            self.COL_NAME_DPMV_REVISION, revision)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0]
        else:
            return None

    def GetAllLabels(self, shared_path):
        ###########
        #
        # GetAllLabels(self, shared_path)
        #
        # Description:    get all the labels and revisions forshared path
        #
        # Parameter:      shared_path
        #
        # Return:         label revision dict or empty dict
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT %s, %s FROM %s WHERE %s="%s" order by %s desc ' % (
            self.COL_NAME_PHV_LABEL, self.COL_NAME_PHV_REVISION, self.VIEW_PATH_HISTORY,
            self.COL_NAME_PHV_MKS_PATH, shared_path,
            self.COL_NAME_PHV_LABEL)
        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            dict = {}
            for item in ret_data:
                dict[item[self.COL_NAME_PHV_LABEL]] = item[self.COL_NAME_PHV_REVISION]
            return dict
        else:
            return {}

    def AddComponent(self, comp_name):
        ###########
        #
        # AddComponent(self, comp_name)
        #
        # Description:    add the component
        #
        # Parameter:      comp_name
        #
        # Return:         comp_name id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        comp_id = self.GetComponentId(comp_name)
        if comp_id == None:
            query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_COMPONENTS, self.COL_NAME_CO_NAME, comp_name)
            try:
                self.db_cursor.execute(query)
                self.db_conn.commit()
            except ValueError:
                print "error, could not add component %s to db" % query
                return None

            return self.GetComponentId(comp_name)
        else:
            return comp_id

    def GetComponentId(self, comp_name):
        ###########
        #
        # GetComponentId(self, comp_name)
        #
        # Description:    get component name id
        #
        # Parameter:      comp_name
        #
        # Return:         comp_name id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.TABLE_COMPONENTS, self.COL_NAME_CO_NAME, comp_name)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_CO_COMP_ID]
        else:
            return None

    def GetNumOfHistoryEntry(self, mks_path):
        ###########
        #
        # GetNumOfHistoryEntry(self, mks_path)
        #
        # Description:    get number of history entrys for mks project
        #
        # Parameter:      mks path
        #
        # Return:         the history
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        # query = 'SELECT count(%s) as COUNT FROM %s WHERE %s="%s";' % (self.COL_NAME_PHV_MKS_PATH, self.VIEW_PATH_HISTORY, self.COL_NAME_PHV_MKS_PATH, mks_path)
        query = 'SELECT count(%s) as COUNT from %s where %s = (select %s from %s where %s ="%s");' % (
            self.COL_NAME_HS_MKS_PATH_ID, self.TABLE_HISTORY, self.COL_NAME_HS_MKS_PATH_ID,
            self.COL_NAME_MP_PATH_ID, self.TABLE_MKS_PATHES, self.COL_NAME_MP_PATH, mks_path)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0]["COUNT"]
        else:
            return 0

    def GetHistoryForProject(self, mks_path):
        ###########
        #
        # GetHistoryForProject(self, mks_path)
        #
        # Description:    get history for mks project
        #
        # Parameter:      mks path
        #
        # Return:         the history
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.VIEW_PATH_HISTORY, self.COL_NAME_PHV_MKS_PATH, mks_path)
        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            return ret_data
        else:
            return None

    def GetHistoryId(self, mks_path, revision):
        ###########
        #
        # GetHistoryId(self, mks_path, revision)
        #
        # Description:    get history id for mks project
        #
        # Parameter:      mks path
        #
        # Return:         the id or none
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s= (select %s from %s where %s ="%s")' % (
            self.TABLE_HISTORY, self.COL_NAME_HS_MKS_PATH_ID,
            self.COL_NAME_MP_PATH_ID, self.TABLE_MKS_PATHES, self.COL_NAME_MP_PATH, mks_path)
        if revision != None and len(revision) > 0:
            query += ' and %s="%s"' % (self.COL_NAME_PHV_REVISION, revision)
        else:
            query += ' and %s is null' % (self.COL_NAME_HS_DEV_PATH_MAP_ID)

        query += ';'
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0]
        else:
            if len(ret_data) == 0:
                return None
            else:
                # find latest label
                number_h = 0
                found_item = {}
                for item in ret_data:
                    number = int(item[self.COL_NAME_PHV_REVISION].split('.')[1])
                    if number > number_h:
                        number_h = number
                        found_item = item
                if len(found_item) > 0:
                    return found_item
                else:
                    return None

    def AddLabelHist(self, mks_path, label, revision, late_commit=False):
        ###########
        #
        # AddLabelHist(self, mks_path, label, revision)
        #
        # Description:    Add label to history table
        #
        # Parameter:      mks path
        #                 label
        #                 revision
        #
        # Return:         -
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        # check if history entry already exists
        histo_id = None  # self.GetHistoryId(mks_path, revision)
        histo_id = self.GetHistoryId(mks_path, revision)
        if histo_id == None:
            label_id = self.AddLabel(label, late_commit)
            mks_path_id = self.GetPathId(mks_path)

            histo_id = self.GetLabelHistId(mks_path_id, label_id)
            rev_hist_id = self.GetLabelRevHistId(mks_path_id, revision)
            if histo_id != rev_hist_id:
                # move label because the label linked to the history points to a different as the revision
                self.UpdateLabelForHistory(rev_hist_id, label_id)
                return rev_hist_id
            else:
                # add the new label
                if histo_id == None:
                    if label_id != None and mks_path_id != None:
                        query = 'INSERT INTO %s (%s, %s, %s) VALUES("%s", "%s", "%s");' % (
                            self.TABLE_HISTORY, self.COL_NAME_HS_MKS_PATH_ID, self.COL_NAME_HS_LABEL_ID,
                            self.COL_NAME_HS_REVISION,
                            mks_path_id, label_id, revision)
                        try:
                            self.db_cursor.execute(query)
                            if late_commit == False:
                                self.db_conn.commit()
                        except ValueError:
                            print "error, could not add label history %s to db" % query
                            return None
                        histo_id = self.GetLabelHistId(mks_path_id, label_id)
                    else:
                        return None
                else:
                    return histo_id
        else:
            return histo_id

    def UpdateLabelForHistory(self, history_id, label_id):
        ###########
        #
        # UpdateLabelForHistory(self, history_id, label_id)
        #
        # Description:    Update the history entry with the label id
        #
        # Parameter:      history_id
        #                 label_id
        #
        # Return:         True if update succesfull otherwise False
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'UPDATE %s SET %s="%s" WHERE %s="%s";' % (self.TABLE_HISTORY, self.COL_NAME_HS_LABEL_ID, label_id,
                                                          self.COL_NAME_HS_HISTORY_ID, history_id)
        try:
            self.db_cursor.execute(query)
            self.db_conn.commit()
        except:
            print "error, could not update histroy %s to db" % query
            return False

        return True

    def UpdateDevPathForHistory(self, dev_path_name, dev_path_rev, hist_view_entry, late_commit=False):
        ###########
        #
        # UpdateDevPathForHistory(self, dev_path_name, dev_path_rev, hist_view_entry, late_commit = False)
        #
        # Description:    Update the history entry with the dev path
        #
        # Parameter:      dev_path_name
        #                 dev_path_revision
        #                 hist_view_entry
        #                 late_commit
        #
        # Return:         True if update succesfull otherwise False
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        map_record = self.GetDevPathMap(dev_path_name, dev_path_rev)
        if map_record != None:
            dev_path_rev_map_id = map_record[self.COL_NAME_DPMV_MAP_ID]
        history_id = hist_view_entry[self.COL_NAME_PHV_HISTORY_ID]
        # TODO: dev_path_rev_map_id must initiated befor usage
        query = 'UPDATE %s SET %s="%s" WHERE %s="%s";' % (
            self.TABLE_HISTORY, self.COL_NAME_HS_DEV_PATH_MAP_ID, dev_path_rev_map_id,
            self.COL_NAME_HS_HISTORY_ID, history_id)
        try:
            self.db_cursor.execute(query)
            if late_commit == False:
                self.db_conn.commit()
        except:
            print "error, could not update histroy %s to db" % query
            return False

        return True

    def GetLabelHistId(self, mks_path_id, label_id):
        ###########
        #
        # GetLabelHistId(self, mks_path_id, label_id)
        #
        # Description:    Get hist id for project with label id and comp id
        #
        # Parameter:      mks mks_path_id
        #                 label_id
        #
        #
        # Return:         hist id or none
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s";' % (
            self.TABLE_HISTORY, self.COL_NAME_HS_MKS_PATH_ID, mks_path_id,
            self.COL_NAME_HS_LABEL_ID, label_id)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_HS_HISTORY_ID]
        else:
            return None

    def GetLabelRevHistId(self, mks_path_id, revision):
        ###########
        #
        # GetLabelRevHistId(self, mks_path_id, revision)
        #
        # Description:    Get hist id for project for a dedicated revision id
        #
        # Parameter:      mks mks_path_id
        #                 revision
        #
        # Return:         hist id or none
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s";' % (
            self.TABLE_HISTORY, self.COL_NAME_HS_MKS_PATH_ID, mks_path_id,
            self.COL_NAME_HS_REVISION, revision)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_HS_HISTORY_ID]
        else:
            return None

    def GetLabelRev(self, mks_path, label):
        ###########
        #
        # GetLabelRev(self, mks_path, label)
        #
        # Description:    Get label revision for project for a dedicated label
        #
        # Parameter:      mks_path
        #                 label
        #
        # Return:         revision
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        label_id = self.GetLabelId(label)
        mks_path_id = self.GetPathId(mks_path)
        if label_id != None and mks_path_id != None:
            query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s";' % (
                self.TABLE_HISTORY, self.COL_NAME_HS_MKS_PATH_ID, mks_path_id,
                self.COL_NAME_HS_LABEL_ID, label_id)
            ret_data = self.raw_query(query)
            if len(ret_data) == 1:
                return ret_data[0][self.COL_NAME_HS_REVISION]
            else:
                return None
        else:
            return None

    def AddLabel(self, label, late_commit=False):
        ###########
        #
        # AddLabel(self, label)
        #
        # Description:    Add label table
        #
        # Parameter:      label
        #                 late_commit
        #
        # Return:         label id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        comp_id = self.GetLabelId(label)
        if comp_id == None:
            query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_LABELS, self.COL_NAME_LB_LABEL, label)
            try:
                self.db_cursor.execute(query)
                if late_commit == False:
                    self.db_conn.commit()
            except ValueError:
                print "error, could not add label %s to db" % query
                return None

            return self.GetLabelId(label)
        else:
            return comp_id

    def GetLabelId(self, label):
        ###########
        #
        # GetLabelId(self, label)
        #
        # Description:    Add label table
        #
        # Parameter:      label
        #
        # Return:         label id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.TABLE_LABELS, self.COL_NAME_LB_LABEL, label)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_LB_LABEL_ID]
        else:
            return None

    def AddCfgRun(self, late_commit=False):
        ###########
        #
        # AddCfgRun(self)
        #
        # Description:    Add config run
        #
        # Parameter:
        #
        # Return:         run id
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        prev_id = self.GetLastRunId()
        if prev_id == None:
            query = 'INSERT INTO %s (%s) VALUES("%s");' % (self.TABLE_CFG_RUN, self.COL_NAME_RC_DATE,
                                                           datetime.now().strftime("%d-%m-%Y %H:%M:%S"))
        else:
            query = 'INSERT INTO %s (%s,%s) VALUES("%s","%s");' % (
                self.TABLE_CFG_RUN, self.COL_NAME_RC_DATE, self.COL_NAME_RC_PREV,
                datetime.now().strftime("%d-%m-%Y %H:%M:%S"), prev_id)

        try:
            self.db_cursor.execute(query)
            if late_commit == False:
                self.db_conn.commit()
        except ValueError:
            print "error, could not add run cfg %s to db" % query
            return None

        return self.GetLastRunId()

    def GetLastRunId(self):
        ###########
        #
        # GetLastRunId(self)
        #
        # Description:    Get last run id
        #
        # Parameter:
        #
        # Return:         id or None if no id found
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s ORDER BY %s DESC LIMIT 1;' % (self.TABLE_CFG_RUN, self.COL_NAME_RC_RUN_ID)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_RC_RUN_ID]
        else:
            return None

    def GetPrevRunId(self):
        ###########
        #
        # GetPrevRunId(self)
        #
        # Description:    Get previsous run id
        #
        # Parameter:
        #
        # Return:         id or None if no id found
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s ORDER BY %s DESC LIMIT 2;' % (self.TABLE_CFG_RUN, self.COL_NAME_RC_RUN_ID)
        ret_data = self.raw_query(query)
        if len(ret_data) == 2:
            return ret_data[1][self.COL_NAME_RC_RUN_ID]
        else:
            return None

    def GetShareTypeId(self, type):
        ###########
        #
        # GetShareTypeId(self, type)
        #
        # Description:    Get shared type id
        #
        # Parameter:
        #
        # Return:         id or None if no id found
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s = "%s";' % (self.TABLE_SHARE_TYPE, self.COL_NAME_ST_TYPE, type)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_ST_TYPE_ID]
        else:
            return None

    def GetCfgTypeId(self, cfg_type):
        ###########
        #
        # GetCfgTypeId(self, cfg_type)
        #
        # Description:    Get cfg type id
        #
        # Parameter:
        #
        # Return:         id or None if no id found
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s = "%s";' % (self.TABLE_CFG_TYPE, self.COL_NAME_CT_TYPE, cfg_type)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_CT_TYPE_ID]
        else:
            return None

    def AddShareCfg(self, run_id, cfg_type, comp_name, share_type, label, dev_path_name, late_commit=False,
                    source_shared_path=None, target_shared_path=None):
        ###########
        #
        # AddShareCfg(self, run_id, cfg_type, comp_name, share_type, label, dev_path_name, late_commit = False, source_shared_path = None, target_shared_path = None)
        #
        # Description:    Add share config to database
        #
        # Parameter:
        #
        # Return:         share cfg id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        comp_id = self.AddComponent(comp_name)
        share_type_id = self.GetShareTypeId(share_type)
        cfg_type_id = self.GetCfgTypeId(cfg_type)
        label_id = None
        if label != None:
            label_id = self.AddLabel(label, late_commit)
        dev_path_id = None
        if dev_path_name != None:
            dev_path_id = self.AddDevPath(dev_path_name, "", late_commit)
        source_path_id = None
        if source_shared_path != None:
            source_path_id = self.AddPath(source_shared_path, late_commit)
        target_path_id = None
        if target_shared_path != None:
            target_path_id = self.AddPath(target_shared_path, late_commit)

        shared_id = self.GetShareCfgId(run_id, cfg_type, comp_name, share_type, label, dev_path_name,
                                       source_shared_path, target_shared_path)
        if shared_id == None:
            query = 'INSERT INTO %s (%s,%s,%s,%s' % (
                self.TABLE_SHARES_CFG, self.COL_NAME_SC_RUN_ID, self.COL_NAME_SC_CFG_TYPE_ID, self.COL_NAME_SC_COMP_ID,
                self.COL_NAME_SC_TYPE_ID)
            if label_id != None:
                query += ',%s' % (self.COL_NAME_SC_LABEL_ID)

            if dev_path_id != None:
                query += ',%s' % (self.COL_NAME_SC_DEV_PATH_ID)

            if source_path_id != None:
                query += ',%s' % (self.COL_NAME_SC_SOURCE_PATH_ID)

            if target_path_id != None:
                query += ',%s' % (self.COL_NAME_SC_TARGET_PATH_ID)

            query += ') VALUES("%s","%s","%s","%s"' % (run_id, cfg_type_id, comp_id, share_type_id)
            if label_id != None:
                query += ',"%s"' % label_id
            if dev_path_id != None:
                query += ',"%s"' % dev_path_id
            if source_path_id != None:
                query += ',"%s"' % source_path_id
            if target_path_id != None:
                query += ',"%s"' % target_path_id
            query += ');'

            try:
                self.db_cursor.execute(query)
                if late_commit == False:
                    self.db_conn.commit()
            except ValueError:
                print "error, could not add shared cfg %s to db" % query
                return None

            return self.GetShareCfgId(run_id, cfg_type, comp_name, share_type, label, dev_path_name, source_shared_path,
                                      target_shared_path)
        else:
            # update shareCfg
            self.UpdateShareCfg(shared_id, label_id, dev_path_id, source_path_id, target_path_id)
            return shared_id

    def GetShareCfgId(self, run_id, cfg_type, comp_name, share_type, label=None, dev_path_name=None,
                      source_shared_path=None, target_shared_path=None):
        ###########
        #
        # GetShareCfgId(self, run_id, cfg_type, comp_name, share_type, label = None, dev_path_name = None, source_shared_path = None, target_shared_path = None)
        #
        # Description:    Get the share config id
        #
        # Parameter:
        #
        # Return:         share cfg id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s = "%s" and %s="%s"  and %s="%s"' % (
            self.VIEW_SHARES_CFG, self.COL_NAME_SCV_RUN_ID, run_id,
            self.COL_NAME_SCV_CFG_TYPE, cfg_type,
            self.COL_NAME_SCV_TYPE, share_type)
        if comp_name != self.COMP_NOT_KNOWN:
            query += ' and %s="%s"' % (self.COL_NAME_SCV_COMP_NAME, comp_name)

        if label != None and len(label) > 0 and share_type == self.CFG_SH_TYPE_BUILD:
            query += ' and %s="%s"' % (self.COL_NAME_SCV_LABEL, label)

        if dev_path_name != None and len(dev_path_name) > 0 and share_type == self.CFG_SH_TYPE_VARIANT:
            query += ' and %s="%s"' % (self.COL_NAME_SCV_DP_NAME, dev_path_name)

        if source_shared_path != None and len(source_shared_path) > 0:
            query += ' and %s="%s"' % (self.COL_NAME_SCV_SOURCE_PATH, source_shared_path)

        if target_shared_path != None and len(target_shared_path) > 0:
            query += ' and %s="%s"' % (self.COL_NAME_SCV_TARGET_PATH, target_shared_path)

        query += ';'
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_SCV_SH_CFG_ID]
        else:
            return None

    def UpdateShareCfg(self, share_id, label_id, dev_path_id, source_path_id=None, target_path_id=None):
        ###########
        #
        # UpdateShareCfg(self, share_id, label_id, dev_path_id, source_path_id = None, target_path_id = None)
        #
        # Description:    Update the share config
        #
        # Parameter:
        #
        # Return:         True if update succesfull otherwise False
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        if label_id == None and dev_path_id == None:
            return False
        query = 'UPDATE %s SET' % (self.TABLE_SHARES_CFG)

        if label_id != None:
            query += ' %s="%s"' % (self.COL_NAME_SC_LABEL_ID, label_id)
        if dev_path_id != None:
            query += ' %s="%s"' % (self.COL_NAME_SC_DEV_PATH_ID, dev_path_id)
        if source_path_id != None:
            query += ' %s="%s"' % (self.COL_NAME_SC_SOURCE_PATH_ID, source_path_id)
        if target_path_id != None:
            query += ' %s="%s"' % (self.COL_NAME_SC_TARGET_PATH_ID, target_path_id)

        query += ' WHERE  %s="%s";' % (self.COL_NAME_SC_CFG_ID, share_id)
        try:
            self.db_cursor.execute(query)
            self.db_conn.commit()
        except:
            print "error, could not update histroy %s to db" % query
            return False

        return True

    def AddShareCfgMap(self, run_id, share_cfg_id, history_id, source_shared_path, target_shared_path,
                       late_commit=False):
        ###########
        #
        # AddShareCfgMap(self, run_id, share_cfg_id, history_id, source_shared_path, target_shared_path, late_commit = False)
        #
        # Description:    Add share to config map
        #
        # Parameter:
        #
        # Return:         return map id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        share_id = self.GetShareID(source_shared_path, target_shared_path)[0]
        # select * from shares_cfg_map where share_id = (select share_id from shares where to_mks_path_id = (SELECT mks_path_id FROM mks_pathes where path = "/nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/00_CodeGen/algo/cb/project.pj"))
        # cfg_map_id = self.GetShareCfgMapId(run_id, target_shared_path)
        cfg_map_id = self.GetShareCfgMapIdDetailed(share_cfg_id, history_id, share_id)
        if cfg_map_id == None:
            # map entry does not exist
            query = 'INSERT INTO %s (%s,%s,%s) VALUES("%s","%s","%s");' % (
                self.TABLE_SHARES_CFG_MAP, self.COL_NAME_SCM_CFG_ID, self.COL_NAME_SCM_HISTORY_ID,
                self.COL_NAME_SCM_SHARE_ID,
                share_cfg_id, history_id, share_id)
        else:
            # map entry exists update map
            query = 'UPDATE %s SET %s="%s",%s="%s", %s="%s"  WHERE %s="%s";' % (
                self.TABLE_SHARES_CFG_MAP, self.COL_NAME_SCM_CFG_ID, share_cfg_id,
                self.COL_NAME_SCM_HISTORY_ID, history_id,
                self.COL_NAME_SCM_SHARE_ID, share_id,
                self.COL_NAME_SCM_MAP_ID, cfg_map_id)

        try:
            self.db_cursor.execute(query)
            if late_commit == False:
                self.db_conn.commit()
        except ValueError:
            print "error, could not add run cfg %s to db" % query
            return None

        if cfg_map_id == None:
            return self.GetShareCfgMapIdDetailed(share_cfg_id, history_id, share_id)
        else:
            return cfg_map_id

    def GetShareCfgMapIdDetailed(self, share_cfg_id, history_id, share_id):
        ###########
        #
        # GetShareCfgMapIdDetailed(self, share_cfg_id, history_id, share_id)
        #
        # Description:    Get the share config map id with detaild infos
        #
        # Parameter:
        #
        # Return:         share cfg map id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s" and %s="%s";' % (
            self.TABLE_SHARES_CFG_MAP, self.COL_NAME_SCM_CFG_ID, share_cfg_id,
            self.COL_NAME_SCM_HISTORY_ID, history_id,
            self.COL_NAME_SCM_SHARE_ID, share_id)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_SCM_MAP_ID]
        else:
            return None

    def GetShareCfgMapId(self, run_id, target_shared_path):
        ###########
        #
        # GetShareCfgMapId(self, run_id, target_shared_path)
        #
        # Description:    Get the share config map id
        #
        # Parameter:
        #
        # Return:         share cfg map id or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s";' % (
            self.VIEW_SHARES_MAP, self.COL_NAME_SMV_TARGET_PATH, target_shared_path,
            self.COL_NAME_SMV_RUN_ID, run_id)
        ret_data = self.raw_query(query)
        if len(ret_data) == 1:
            return ret_data[0][self.COL_NAME_SMV_MAP_ID]
        else:
            return None

    def GetAllApplyedCfgsWithRunId(self, run_id):
        ###########
        #
        # GetAllApplyedCfgsWithRunId(self)
        #
        # Description:    Get all applyed configs with run id
        #
        # Parameter:
        #
        # Return:         config map or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.VIEW_SHARES_MAP, self.COL_NAME_SMV_RUN_ID, run_id)

        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            return ret_data
        else:
            return None

    def GetAllConfigurationsWithRunId(self, run_id):
        ###########
        #
        # GetAllConfigurationsWithRunId(self, run_id)
        #
        # Description:    Get all configurations with run id
        #
        # Parameter:
        #
        # Return:         config map or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s";' % (self.VIEW_SHARES_CFG, self.COL_NAME_SCV_RUN_ID, run_id)

        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            return ret_data
        else:
            return None

    def GetAllSharesWhereCfgIsUsed(self, run_id, share_cfg_id):
        ###########
        #
        # GetAllSharesWhereCfgIsUsed(self, run_id, share_cfg_id)
        #
        # Description:    Get all configurations with run id
        #
        # Parameter:
        #
        # Return:         config map or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        query = 'SELECT * FROM %s WHERE %s="%s" and %s="%s";' % (self.VIEW_SHARES_MAP, self.COL_NAME_SCV_RUN_ID, run_id,
                                                                 self.COL_NAME_SCV_SH_CFG_ID, share_cfg_id)

        ret_data = self.raw_query(query)
        if len(ret_data) > 0:
            return ret_data
        else:
            return None

    def GetAllSharesChangedToLastConfig(self):
        ###########
        #
        # GetAllSharesChangedToLastConfig(self)
        #
        # Description:    Get all source shared pathes that are affeced by the config change from actual to the last config
        #
        # Parameter:
        #
        # Return:         shared pathes or None
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        act_run_id = self.GetLastRunId()
        prev_run_id = self.GetPrevRunId()

        # get the applied configuration from the last config run
        applyed_cfgs = self.GetAllApplyedCfgsWithRunId(prev_run_id)
        if applyed_cfgs is not None:
            affected_source_pathes = []
            # try to find the old applied config in the new configuration if not found get all the shares where the old config applied to
            for a_cfg in applyed_cfgs:
                new_share_cfg_id = self.GetShareCfgId(act_run_id,
                                                      a_cfg[self.COL_NAME_SMV_CFG_TYPE],
                                                      a_cfg[self.COL_NAME_SMV_COMP_NAME],
                                                      a_cfg[self.COL_NAME_SMV_SH_TYPE],
                                                      a_cfg[self.COL_NAME_SMV_LABEL],
                                                      a_cfg[self.COL_NAME_SMV_DEV_PATH_NAEM],
                                                      a_cfg[self.COL_NAME_SMV_CFG_SOURCE_PATH],
                                                      a_cfg[self.COL_NAME_SMV_CFG_TARGET_PATH])
                if new_share_cfg_id == None:
                    self.Log("Info",
                             'Shared sub config was changed for cfg type "%s" comp "%s" and share type "%s" last config was: label "%s" devpath "%s" source_path "%s" target_path "%s"' % (
                                 a_cfg[self.COL_NAME_SMV_CFG_TYPE],
                                 a_cfg[self.COL_NAME_SMV_COMP_NAME],
                                 a_cfg[self.COL_NAME_SMV_SH_TYPE],
                                 a_cfg[self.COL_NAME_SMV_LABEL],
                                 a_cfg[self.COL_NAME_SMV_DEV_PATH_NAEM],
                                 a_cfg[self.COL_NAME_SMV_CFG_SOURCE_PATH],
                                 a_cfg[self.COL_NAME_SMV_CFG_TARGET_PATH]))
                    shares = self.GetAllSharesWhereCfgIsUsed(prev_run_id, a_cfg[self.COL_NAME_SMV_CFG_ID])
                    for share in shares:
                        if share[self.COL_NAME_SMV_SOURCE_PATH] not in affected_source_pathes:
                            affected_source_pathes.append(share[self.COL_NAME_SMV_SOURCE_PATH])
            # print affected_source_pathes
            return affected_source_pathes
        else:
            return None


class ConfigSharedSubProjets_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Config shared sub projects class
    #
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        xml_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.ConfigFileName = ""
        self.Project = ""
        self.Sandbox = ""
        self.ActDevPath = ""
        self.Type = "normal"

        self.Logging = False
        self.Quiet = False
        self.LogDir = ""

        self.ExcludeFile = ""

        # flag for configV2 scan if already scaned self.CostomV2ListFilledFlag == 1 else 0
        self.CostomV2ListFilledFlag = 0

        # notice that Project Shared Component e.g. ARS301 SMR200 ARS400 exist in the Project for further use in CheckSetProject(), CheckSetProjectCfg()  and ConfigureSharedProjects()
        self.ProjectShareCompName = ""
        self.ActBaseProjectPath = ""

        self.SharedProjects = xml_obj.create_a_root_document(self, 'MKSSharedProjectConfig')
        self.SetProjectsCfg = 0
        self.SharedProjectLabelsDevPathInfo = {}
        self.PreConfigSharedProjectDict = {}

        self.ChangedConfigSharedProjectDict = {}
        self.MbSharedProjectDict = {}
        # Debug: count for recursive traversal of SharedSubProjects
        self.RecursLevel = 0
        # SharedSubProject name (dir) for deeper sandbox recursive parsing in GetSharedSubSandboxTypeListRec()
        self.BreakOut = ""

    def IsBaseConfigAlreadyInCustomV2(self, SharedPath, SharedProjectLabelsDevPathInfoDict):
        ###########
        #
        # IsBaseConfigAlreadyInCustomV2(self, SharedPath, SharedProjectLabelsDevPathInfoDict)
        #
        # Description:    Check if the SharedProject is alredy in costomV2 configuration XML file
        #
        # Parameter:      SharedPath:                            The path where the shared project is shared to                             e.g. /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnviromentModel/03_Design/01_Supporting_Documents/em/project.pj
        #                 SharedProjectLabelsDevPathInfoDict:    The Dictionary with all Labels and Development Path for this SharedPath    e.g. ARS301_01.00.00
        #
        # Return:         if not in CustomV2 return the 0 else 1
        #
        # Author:         Ilja Hotjakov 17.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # fill List from CustomV2 XML
        if (self.SetProjectsCfg.getElementsByTagName("CustomConfigV2").length > 0):
            # Open read XML file
            CustomConfigV2 = self.SetProjectsCfg.getElementsByTagName("CustomConfigV2").item(0)
            CustomConfigV2.normalize()

            if self.CostomV2ListFilledFlag == 0:
                # Init
                self.LabelListCostomV2 = []
                self.DevPathListCostomV2 = []

                # Find "CustomV2" components
                for SharedProject in CustomConfigV2.childNodes:
                    if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                        configs = SharedProject.childNodes
                        Label = ""
                        DevPathName = ""

                        # read the CompName_config from shared_project_config.xml
                        for config in configs:
                            if (config.nodeType == config.ELEMENT_NODE):
                                Label = ""
                                DevPathName = ""
                                configType = config.getAttribute("Type")
                                if (configType == "build" and self.Type == "build"):  # safe only if the type is wanted
                                    Label = config.getAttribute("Label")
                                    if (len(Label) != 0):
                                        self.LabelListCostomV2.append(Label)
                                elif (configType == "variant" and self.Type == "variant"):
                                    DevPathName = config.getAttribute("DevPathName")
                                    # if the dev path name is empty the variant configuration is invalid
                                    if (len(DevPathName) != 0):
                                        self.DevPathListCostomV2.append(DevPathName)
                                elif (configType == "normal"):
                                    # normal in costom is not allowed !!! ?
                                    self.Log("Info",
                                             "normal configuration found in CostomV2 in *.XML file this is not allowed!")

                # if ((len(self.LabelListCostomV2) > 0 or len(self.DevPathListCostomV2) > 0) and (self.CostomV2ListFilledFlag == 0) ):
                self.CostomV2ListFilledFlag = 1

            # find Shared path in Dict and find the devPath or Label from ConficV2 in it
            if (SharedPath in SharedProjectLabelsDevPathInfoDict):
                if (self.Type == "build"):
                    i = 0
                    while i < len(self.LabelListCostomV2):
                        if (len(self.LabelListCostomV2[i]) > 0):
                            if (self.LabelListCostomV2[i] in SharedProjectLabelsDevPathInfoDict[SharedPath]["Build"]):
                                return 1
                        i += 1

                elif (self.Type == "variant"):
                    i = 0
                    while i < len(self.DevPathListCostomV2):
                        if ((len(self.DevPathListCostomV2[i]) > 0) and (
                                    SharedProjectLabelsDevPathInfoDict[SharedPath]["DevPath"] != 0)):
                            # print SharedPath
                            # print SharedProjectLabelsDevPathInfoDict[SharedPath]["DevPath"]
                            # print self.DevPathListCostomV2
                            if (self.DevPathListCostomV2[i] in SharedProjectLabelsDevPathInfoDict[SharedPath][
                                "DevPath"]):
                                # print "*** Found ***"
                                # print SharedPath
                                # print SharedProjectLabelsDevPathInfoDict[SharedPath]["DevPath"]
                                # print self.DevPathListCostomV2
                                # print "********************************************************************************************"
                                return 1
                        i += 1

                elif (self.Type == "normal"):
                    self.Log("Error",
                             "Script type target 'normal' is not allowed for CostomV2 configuration! Will be ignored!")

                # if not found
                return 0
            else:
                return 0

        else:  # no CustonV2 found
            return 0

    def SaveConfigXSLTAndCss(self, ConfigFileName):
        ###########
        #
        # SaveConfigXSLTAndCss(self, ConfigFileName)
        #
        # Description: Saves the xslt and css (style sheet for the configuration xml file)
        #
        # Parameter: -ConfigFileName the direcory of the config file
        #
        # TODO: add parameter check
        #
        ###########
        split = self.ConfigFileName.rfind("\\")
        XlSTName = "%sconfig.xslt" % (ConfigFileName[0:split + 1])
        CSSName = "%sconfig.css" % (ConfigFileName[0:split + 1])
        if (not (os.path.isfile(XlSTName))) or (not (os.path.isfile(CSSName))):
            self.Log("Info", "Write xslt style sheet file for the config"), ""
            f = open(XlSTName, "w")
            xslt = """<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:template match="ConfigSharedProjects">
    <html>
      <head>
        <META HTTP-EQUIV="Content-Type" content="text/html; charset=utf-8"/>
        <link rel="stylesheet" href="config.css"/>
        <title>
          Shared projects configuration
        </title>
      </head>
      <!--<body topmargin="0" leftmargin="0" rightmargin="0" onclick="outliner();">-->
      <body topmargin="0" leftmargin="0" rightmargin="0">
        <h1>
          Shared projects configuration
        </h1>

        <!--Write shared project base configs-->
        <h2>
          Shared project base configuration
        </h2>
        <table cellpadding="2" cellspacing="0" width="98%" border="1" bordercolor="white" class="infotable">
          <tr>
            <td nowrap="1" class="header">Component name</td>
            <td nowrap="1" class="header">Attribute</td>
            <td nowrap="1" class="header">Value</td>
          </tr>
          <tr class="row">
            <xsl:for-each select="BaseConfig/SharedProject">
              <tr class="row">
                <td nowrap="1" class="content">
                  <xsl:value-of select="@CompName"/>
                </td>
                <xsl:for-each select="Config">
                  <xsl:if test="@Type='variant'">
                    <td nowrap="1" class="content">
                      DevPathName
                    </td>
                    <xsl:choose>
                      <xsl:when test="@DevPathName = ''">
                        <td nowrap="1" class="content">
                          No development path label defined
                        </td>
                      </xsl:when>
                      <xsl:otherwise>
                        <td nowrap="1" class="content">
                          <xsl:value-of select="@DevPathName"/>
                        </td>
                      </xsl:otherwise>
                    </xsl:choose>
                  <tr />
                  <td />
                  </xsl:if>
                  <xsl:if test="@Type='build'">
                    <td nowrap="1" class="content">
                      Label
                    </td>
                    <xsl:choose>
                      <xsl:when test="@Label = ''">
                        <td nowrap="1" class="content">
                          No build label defined
                        </td>
                      </xsl:when>
                      <xsl:otherwise>
                        <xsl:choose>
                          <xsl:when test="@Modified='yes'">
                            <td nowrap="1" class="content_modified">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:when>
                          <xsl:otherwise>
                            <td nowrap="1" class="content">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:otherwise>
                        </xsl:choose>
                      </xsl:otherwise>
                    </xsl:choose>
                    <tr />
                    <td />
                  </xsl:if>
                </xsl:for-each>
              </tr>
            </xsl:for-each>
          </tr>
        </table>

        <xsl:for-each select="CustomConfig">
          <!--Write shared project custom configs-->
          <h2>
            Shared project custom configuration
          </h2>
          <table cellpadding="2" cellspacing="0" width="98%" border="1" bordercolor="white" class="infotable">
            <tr>
              <td nowrap="1" class="header">Source component path</td>
              <td nowrap="1" class="header">Attribute</td>
              <td nowrap="1" class="header">Value</td>
            </tr>
            <tr class="row">
              <xsl:for-each select="SharedProject">
                <tr class="row">
                  <td nowrap="1" class="content">
                    <xsl:value-of select="@SharedPath"/>
                  </td>
                  <xsl:for-each select="Config">
                    <xsl:if test="@Type='variant'">
                      <td nowrap="1" class="content">
                        DevPathName
                      </td>
                      <xsl:choose>
                        <xsl:when test="@DevPathName = ''">
                          <td nowrap="1" class="content">
                            No development path label defined
                          </td>
                        </xsl:when>
                        <xsl:otherwise>
                          <td nowrap="1" class="content">
                            <xsl:value-of select="@DevPathName"/>
                          </td>
                        </xsl:otherwise>
                      </xsl:choose>
                    <tr />
                    <td />
                    </xsl:if>
                    <xsl:if test="@Type='build'">
                      <td nowrap="1" class="content">
                        Label
                      </td>
                      <xsl:choose>
                        <xsl:when test="@Label = ''">
                          <td nowrap="1" class="content">
                            No build label defined
                          </td>
                        </xsl:when>
                        <xsl:otherwise>
                        <xsl:choose>
                          <xsl:when test="@Modified='yes'">
                            <td nowrap="1" class="content_modified">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:when>
                          <xsl:otherwise>
                            <td nowrap="1" class="content">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:otherwise>
                        </xsl:choose>
                        </xsl:otherwise>
                      </xsl:choose>
                      <tr />
                      <td />
                    </xsl:if>
                  </xsl:for-each>
                </tr>
              </xsl:for-each>
            </tr>
          </table>
        </xsl:for-each>

        <xsl:for-each select="CustomConfigV2">
          <!--Write shared project customV2 configs-->
          <h2>
            Shared project customV2 configuration
          </h2>
          <table cellpadding="2" cellspacing="0" width="98%" border="1" bordercolor="white" class="infotable">
            <tr>
              <td nowrap="1" class="header">Component name</td>
              <td nowrap="1" class="header">Attribute</td>
              <td nowrap="1" class="header">Value</td>
            </tr>
            <tr class="row">
              <xsl:for-each select="SharedProject">
                <tr class="row">
                  <td nowrap="1" class="content">
                    <xsl:value-of select="@CompName"/>
                  </td>
                  <xsl:for-each select="Config">
                    <xsl:if test="@Type='variant'">
                      <td nowrap="1" class="content">
                        DevPathName
                      </td>
                      <xsl:choose>
                        <xsl:when test="@DevPathName = ''">
                          <td nowrap="1" class="content">
                            No development path label defined
                          </td>
                        </xsl:when>
                        <xsl:otherwise>
                          <td nowrap="1" class="content">
                            <xsl:value-of select="@DevPathName"/>
                          </td>
                        </xsl:otherwise>
                      </xsl:choose>
                    <tr />
                    <td />
                    </xsl:if>
                    <xsl:if test="@Type='build'">
                      <td nowrap="1" class="content">
                        Label
                      </td>
                      <xsl:choose>
                        <xsl:when test="@Label = ''">
                          <td nowrap="1" class="content">
                            No build label defined
                          </td>
                        </xsl:when>
                        <xsl:otherwise>
                        <xsl:choose>
                          <xsl:when test="@Modified='yes'">
                            <td nowrap="1" class="content_modified">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:when>
                          <xsl:otherwise>
                            <td nowrap="1" class="content">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:otherwise>
                        </xsl:choose>
                        </xsl:otherwise>
                      </xsl:choose>
                      <tr />
                      <td />
                    </xsl:if>
                  </xsl:for-each>
                </tr>
              </xsl:for-each>
            </tr>
          </table>
        </xsl:for-each>

        <xsl:for-each select="CustomConfigV3">
          <!--Write shared project customV3 configs-->
          <h2>
            Shared project customV3 configuration
          </h2>
          <table cellpadding="2" cellspacing="0" width="98%" border="1" bordercolor="white" class="infotable">
            <tr>
              <td nowrap="1" class="header">Target path</td>
              <td nowrap="1" class="header">Attribute</td>
              <td nowrap="1" class="header">Value</td>
            </tr>
            <tr class="row">
              <xsl:for-each select="SharedProject">
                <tr class="row">
                  <td nowrap="1" class="content">
                    <xsl:value-of select="@Path"/>
                  </td>
                  <xsl:for-each select="Config">
                    <xsl:if test="@Type='variant'">
                      <td nowrap="1" class="content">
                        DevPathName
                      </td>
                      <xsl:choose>
                        <xsl:when test="@DevPathName = ''">
                          <td nowrap="1" class="content">
                            No development path label defined
                          </td>
                        </xsl:when>
                        <xsl:otherwise>
                          <td nowrap="1" class="content">
                            <xsl:value-of select="@DevPathName"/>
                          </td>
                        </xsl:otherwise>
                      </xsl:choose>
                    <tr />
                    <td />
                    </xsl:if>
                    <xsl:if test="@Type='build'">
                      <td nowrap="1" class="content">
                        Label
                      </td>
                      <xsl:choose>
                        <xsl:when test="@Label = ''">
                          <td nowrap="1" class="content">
                            No build label defined
                          </td>
                        </xsl:when>
                        <xsl:otherwise>
                        <xsl:choose>
                          <xsl:when test="@Modified='yes'">
                            <td nowrap="1" class="content_modified">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:when>
                          <xsl:otherwise>
                            <td nowrap="1" class="content">
                                <xsl:value-of select="@Label"/>
                            </td>
                          </xsl:otherwise>
                        </xsl:choose>
                        </xsl:otherwise>
                      </xsl:choose>
                      <tr />
                      <td />
                    </xsl:if>
                  </xsl:for-each>
                </tr>
              </xsl:for-each>
            </tr>
          </table>
        </xsl:for-each>

        <p></p>
        <p>
          <table class="note">
            <tr>
              <td nowrap="1">
                <script type="text/javascript">
                  var d=new Date()
                  document.write("Printed: " + Date().toLocaleString() )
                </script>
              </td>
            </tr>
          </table>
        </p>
        <hl></hl>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
"""
            f.write(xslt)
            f.close()

            f = open(CSSName, "w")
            css = """BODY
{
    BACKGROUND-COLOR: white;
    FONT-FAMILY: "Verdana", sans-serif;
    FONT-SIZE: 100%;
    MARGIN-LEFT: 0px;
    MARGIN-TOP: 0px
}
P
{
    FONT-FAMILY: "Verdana", sans-serif;
    FONT-SIZE: 70%;
    LINE-HEIGHT: 12pt;
    MARGIN-BOTTOM: 0px;
    MARGIN-LEFT: 10px;
    MARGIN-TOP: 10px
}
.note
{
    BACKGROUND-COLOR:  #ffffff;
    COLOR: #336699;
    FONT-FAMILY: "Verdana", sans-serif;
    FONT-SIZE: 100%;
    MARGIN-BOTTOM: 0px;
    MARGIN-LEFT: 0px;
    MARGIN-TOP: 0px;
    PADDING-RIGHT: 10px
}
.infotable
{
    BACKGROUND-COLOR: #ffffff;
    BORDER-BOTTOM: #ffffff 0px solid;
    BORDER-COLLAPSE: collapse;
    BORDER-LEFT: #ffffff 0px solid;
    BORDER-RIGHT: #ffffff 0px solid;
    BORDER-TOP: #ffffff 0px solid;
    FONT-SIZE: 70%;
    MARGIN-LEFT: 10px
}
.issuetable
{
    BACKGROUND-COLOR: #ffffe8;
    BORDER-COLLAPSE: collapse;
    COLOR: #000000;
    FONT-SIZE: 100%;
    MARGIN-BOTTOM: 10px;
    MARGIN-LEFT: 13px;
    MARGIN-TOP: 0px
}
.issuetitle
{
    BACKGROUND-COLOR: #ffffff;
    BORDER-BOTTOM: #dcdcdc 1px solid;
    BORDER-TOP: #dcdcdc 1px;
    COLOR: #003366;
    FONT-WEIGHT: normal
}
.header
{
    BACKGROUND-COLOR: #cecf9c;
    BORDER-BOTTOM: #ffffff 1px solid;
    BORDER-LEFT: #ffffff 1px solid;
    BORDER-RIGHT: #ffffff 1px solid;
    BORDER-TOP: #ffffff 1px solid;
    COLOR: #000000;
    FONT-WEIGHT: bold
}
.issuehdr
{
    BACKGROUND-COLOR: #E0EBF5;
    BORDER-BOTTOM: #dcdcdc 1px solid;
    BORDER-TOP: #dcdcdc 1px solid;
    COLOR: #000000;
    FONT-WEIGHT: normal
}
.issuenone
{
    BACKGROUND-COLOR: #ffffff;
    BORDER-BOTTOM: 0px;
    BORDER-LEFT: 0px;
    BORDER-RIGHT: 0px;
    BORDER-TOP: 0px;
    COLOR: #000000;
    FONT-WEIGHT: normal
}
.content
{
    BACKGROUND-COLOR: #e7e7ce;
    BORDER-BOTTOM: #ffffff 1px solid;
    BORDER-LEFT: #ffffff 1px solid;
    BORDER-RIGHT: #ffffff 1px solid;
    BORDER-TOP: #ffffff 1px solid;
    PADDING-LEFT: 3px
}
.content_modified
{
    BACKGROUND-COLOR: #00e7ce;
    BORDER-BOTTOM: #ffffff 1px solid;
    BORDER-LEFT: #ffffff 1px solid;
    BORDER-RIGHT: #ffffff 1px solid;
    BORDER-TOP: #ffffff 1px solid;
    PADDING-LEFT: 3px
}
.issuecontent
{
    BACKGROUND-COLOR: #ffffff;
    BORDER-BOTTOM: #dcdcdc 1px solid;
    BORDER-TOP: #dcdcdc 1px solid;
    PADDING-LEFT: 3px
}
A:link
{
    COLOR: #cc6633;
    TEXT-DECORATION: underline
}
A:visited
{
    COLOR: #cc6633;
}
A:active
{
    COLOR: #cc6633;
}
A:hover
{
    COLOR: #cc3300;
    TEXT-DECORATION: underline
}
H1
{
    BACKGROUND-COLOR: #003366;
    BORDER-BOTTOM: #336699 6px solid;
    COLOR: #ffffff;
    FONT-SIZE: 130%;
    FONT-WEIGHT: normal;
    MARGIN: 0em 0em 0em -20px;
    PADDING-BOTTOM: 8px;
    PADDING-LEFT: 30px;
    PADDING-TOP: 16px
}
H2
{
    COLOR: #000000;
    FONT-SIZE: 80%;
    FONT-WEIGHT: bold;
    MARGIN-BOTTOM: 3px;
    MARGIN-LEFT: 10px;
    MARGIN-TOP: 20px;
    PADDING-LEFT: 0px
}
H3
{
    COLOR: #000000;
    FONT-SIZE: 80%;
    FONT-WEIGHT: bold;
    MARGIN-BOTTOM: -5px;
    MARGIN-LEFT: 10px;
    MARGIN-TOP: 20px
}
H4
{
    COLOR: #000000;
    FONT-SIZE: 70%;
    FONT-WEIGHT: bold;
    MARGIN-BOTTOM: 0px;
    MARGIN-TOP: 15px;
    PADDING-BOTTOM: 0px
}
UL
{
    COLOR: #000000;
    FONT-SIZE: 70%;
    LIST-STYLE: square;
    MARGIN-BOTTOM: 0pt;
    MARGIN-TOP: 0pt
}
OL
{
    COLOR: #000000;
    FONT-SIZE: 70%;
    LIST-STYLE: square;
    MARGIN-BOTTOM: 0pt;
    MARGIN-TOP: 0pt
}
LI
{
    LIST-STYLE: square;
    MARGIN-LEFT: 0px
}
.expandable
{
    CURSOR: hand
}
.expanded
{
    color: black
}
.collapsed
{
    DISPLAY: none
}
.foot
{
BACKGROUND-COLOR: #ffffff;
BORDER-BOTTOM: #cecf9c 1px solid;
BORDER-TOP: #cecf9c 2px solid
}
.settings
{
MARGIN-LEFT: 25PX;
}
.help
{
TEXT-ALIGN: right;
margin-right: 10px;
}"""
            f.write(css)
            f.close()

    def CheckIfRevisionOnDevPath(self, DevPathRev, CheckRev):
        ###########
        #
        # CheckIfRevisionOnDevPath(self, evPathRev, CheckRev)
        #
        # Description:    Check if revision is on sepcified dev path
        #
        # Parameter:      DevPathRev:           the revision number array of the dev path
        #                 CheckRev:             the revision numver of the label to check
        #
        # Return:         True if on devpath False if not
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        if len(CheckRev) > 0 and len(DevPathRev) > 0:
            if len(DevPathRev) > len(CheckRev):
                return False
            if len(DevPathRev) == len(CheckRev):
                checker = True
                for i in range(len(DevPathRev) - 1):
                    if DevPathRev[i] != CheckRev[i]:
                        checker = False
                        break
                return checker
            if len(DevPathRev) + 2 == len(CheckRev):
                checker = True
                for i in range(len(DevPathRev)):
                    if DevPathRev[i] != CheckRev[i]:
                        checker = False
                        break
                return checker
        return False

    def RescanSharedPath(self, SharedPath):
        ###########
        #
        # RescanSharedPath(self, SharedPath)
        #
        # Description:    Rescan shared paht
        #
        # Parameter:      SharedPath:           the path that should be rescanned
        #
        # Return:         -
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        self.Log("Info", "Rescan needed for project %s" % (SharedPath))
        # Build/update History
        # self.Log("Info", "DevPathesStarted")
        DevPathes = self.GetAllDevPathes(SharedPath)
        # self.Log("Info", "AddDevPathesToDBStarted")
        if DevPathes != 0:
            for DevPath in DevPathes:
                self.mks_config_db.AddDevPath(DevPath, DevPathes[DevPath], True)

        # self.Log("Info", "GetLabelsStarted")
        org_all_labels = self.GetAllLabelsForSharedProject(SharedPath, Labeled=False)

        # self.Log("Info", "AddLabelsToDbStarted")
        for label_item in org_all_labels:
            self.mks_config_db.AddLabelHist(SharedPath, label_item, org_all_labels[label_item], True)

        # self.Log("Info", "UpdateDevPath")

        history = self.mks_config_db.GetHistoryForProject(SharedPath)
        if history is not None:
            for db_label in history:
                act_label_rev = db_label[self.mks_config_db.COL_NAME_PHV_REVISION].split('.')
                dev_path_rev = db_label[self.mks_config_db.COL_NAME_PHV_DP_REVISION]
                if dev_path_rev == None and DevPathes != 0:
                    for DevPath in DevPathes:
                        # print "dp %s, act %s"%(DevPathes[DevPath],act_label_rev)
                        if self.CheckIfRevisionOnDevPath(DevPathes[DevPath].split('.'), act_label_rev):
                            self.mks_config_db.UpdateDevPathForHistory(DevPath, DevPathes[DevPath], db_label, True)
                            # print "add %s to dev path %s"%(db_label[self.mks_config_db.COL_NAME_PHV_REVISION], DevPath)
        # self.Log("Info", "CommitResync")

        # Update rescan date here:
        self.mks_config_db.UpdateRescanDate(SharedPath)
        self.mks_config_db.Commit()

    def RescanSharedPathList(self, SharedPathList, SharedPathListAlreadyScanned):
        ###########
        #
        # RescanSharedPathList(self, SharedPathList, SharedPathListAlreadyScanned)
        #
        # Description:    Rescan shared path list exclude the pathes from the already scanned
        #
        # Parameter:      SharedPath:           the path that should be rescanned
        #
        # Return:         -
        #
        # Author:         Jochen Spruck
        #
        # TODO: add parameter check
        #
        ###########
        if SharedPathList is not None:
            total_pathes = len(SharedPathList)
            counter = 0
            for path in SharedPathList:
                if path not in SharedPathListAlreadyScanned:
                    self.RescanSharedPath(path)

                    dev_path_dict, dev_path_label_dict, label_dict = self.mks_config_db.GetDevPathesDevPathsLabelRevDictAndLabels(
                            path)

                    # all devapthes for this share with revision
                    self.SharedProjectLabelsDevPathInfo[path][
                        "DevPath"] = dev_path_dict  # self.mks_config_db.GetAllDevPathes(path)
                    # per path all labels with revisions
                    self.SharedProjectLabelsDevPathInfo[path][
                        "DevPaths"] = dev_path_label_dict  # self.mks_config_db.GetDevPathsLabelRevDict(path)
                    # all the labels and revision for the share
                    self.SharedProjectLabelsDevPathInfo[path][
                        "Build"] = label_dict  # self.mks_config_db.GetAllLabels(path)
                else:
                    self.Log("Debug", "Project rescan skipped because already done %s" % path)
                counter += 1
                self.Log("Info", "Getting sandbox history %s of %s shares done" % (counter, total_pathes))

    def ParseForSharedSandboxProject(self, SandboxPath, GenLabelDevPathDict, GenPreConfigSharedProjectDict):
        ###########
        #
        # ParseForSharedSandboxProject(self, SandboxPath, GenLabelDevPathDict, GenPreConfigSharedProjectDict)
        #
        # Description:    Parse for all shared projects in project or the sandbox which are found in InputFileName e.g. pre_config_shared_projects.xml
        #                 and add it to an xml struct with all shared subpojects (normal/variant/build)
        #                 This xml includes the project path and the shared project path
        #                 the revision and the corresponding label, and the type(normal/variant/build)
        #
        # Parameter:      SandboxPath:                      the path of the pj file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #                 GenLabelDevPathDict:              generate a dictionary with all labels and dev pathes of the shared sub projects
        #                 GenPreConfigSharedProjectDict:    generate a dictionary with label, revision, sharedpath, projectpath and type
        #
        # Return:         0 if ok 1 if errors occur
        #                 self.PreConfigSharedProjectDict    dict with all shared subprojects
        #
        # Author:         Ilja Hotjakov 13.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        return_val = 0
        type = ""
        revision = ""
        label = ""
        self.retGetAllLabelsDict = {}
        rescanned_pathes = []

        # create md5 hash object
        hash = hashlib.md5()

        self.Log("Info", "Start getting sandbox struct")
        retSandboxTypeList = self.GetSharedSubSandboxTypeListRec(SandboxPath, hash)
        self.SharedProjects.documentElement.setAttribute("MD5Hash", hash.hexdigest())
        self.Log("Info", "Stop getting sandbox struct")
        # fo_new = open("d:\\new.txt", "w")
        # for item in retSandboxTypeListNew:
        # item_key = item.keys()[0]
        # fo_new.write(("%s %s %s %s \n")%(item_key, item[item_key]["Type"], item[item_key]["Label"], item[item_key]["Revision"]))
        # fo_new.close()

        # self.Log("Info","Start getting sandbox struct old")
        # retSandboxTypeListOld = self.GetSharedSubSandboxTypeList(SandboxPath)
        # self.Log("Info","Stop getting sandbox struct old")
        # fo_old = open("d:\\old.txt", "w")
        # for item in retSandboxTypeListOld:
        # item_key = item.keys()[0]
        # fo_old.write(("%s %s %s %s \n")%(item_key, item[item_key]["Type"], item[item_key]["Label"], item[item_key]["Revision"]))
        # fo_old.close()

        if (retSandboxTypeList == 1):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewsandbox command failed"
            self.Log("Error", "Could not read/extract actual type from " + SandboxPath)
            return_val = 1
        elif (retSandboxTypeList == 2):
            self.Log("Info", " no entries found for " + SandboxPath)
            return_val = 1
        else:
            if self.UseDatabase == True:
                RescanCandidates = self.mks_config_db.GetTenOldesRescanCanditates()
            index = 0
            self.Log("Info", "Start getting sandbox history")
            number_of_shares = len(retSandboxTypeList)
            while index < number_of_shares:
                ret = retSandboxTypeList[index]
                SandboxPath = ret.keys()[0]
                # print SandboxPath
                # Init lokal
                type = ""
                revision = ""
                label = ""

                type = ret[SandboxPath]["Type"]
                revision = ret[SandboxPath]["Revision"]
                label = ret[SandboxPath]["Label"]

                index += 1

                if (type != ""):
                    # get SharedPath, ProjectPath and Revision
                    if self.UseDatabase == True:
                        # self.Log("Info", "GetShareStart")
                        share = self.mks_config_db.GetShare(SandboxPath)
                        if share != None:
                            retPathDict = {}
                            SourcePath = str(share[self.mks_config_db.COL_NAME_SHV_PATH_TO])
                            retPathDict[SourcePath] = {}
                            retPathDict[SourcePath]["SharedPath"] = str(
                                    share[self.mks_config_db.COL_NAME_SHV_PATH_FROM])
                            retPathDict[SourcePath]["Revision"] = "1.1"
                            # self.Log("Info", "GetShareEnd")
                        else:
                            retPathDict = self.GetRevisionSharedAndPathFromSandboxPath(SandboxPath)
                    else:
                        retPathDict = self.GetRevisionSharedAndPathFromSandboxPath(SandboxPath)

                    if (retPathDict == 1):
                        print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si projectinfo command failed"
                        self.Log("Error",
                                 "Could not read/extract actual Revision, ProjectPath and SheardPath from " + SandboxPath)
                        return_val = 1
                    elif (0 in retPathDict):
                        self.Log("Error", " no ProjectPath found for " + SandboxPath)
                        ProjectPath = ""
                        return_val = 1
                    else:

                        ProjectPath = retPathDict.keys()[0]
                        # read SharedPath
                        if (retPathDict[ProjectPath]["SharedPath"] == ""):
                            self.Log("Error", "1: no SharedPath found for projectpath: " + ProjectPath)
                            SharedPath = ""
                            return_val = 1
                        else:
                            SharedPath = retPathDict[ProjectPath]["SharedPath"]

                        if revision == "":  # if normal or variant type only then read revision
                            # read Revision
                            if (retPathDict[ProjectPath]["Revision"] == ""):
                                self.Log("Error", " no revision found for projectpath: " + ProjectPath)
                                revision = ""
                                return_val = 1
                            else:
                                revision = retPathDict[ProjectPath]["Revision"]

                        # Init and creal Dictionary
                        self.retGetAllLabelsDict = {}

                        # Find Label if Type == build
                        if (type == "build"):
                            label = ""
                            if GenLabelDevPathDict == True:
                                label = self.GetLabelForRevisionWithAllLabelsDict("", SandboxPath, revision,
                                                                                  self.retGetAllLabelsDict)
                                if (label == 1):
                                    print datetime.now().strftime(
                                            "%Y_%m_%d %H:%M:%S") + " ERROR: si viewprojecthistory command failed"
                                    self.Log("Error",
                                             " in GetLabelForRevisionWithAllLabelsDict of projectpath: " + ProjectPath)
                                    return_val = 1
                                    label = ""
                                elif (label == 0):
                                    self.Log("Info",
                                             " no label found for revision: " + revision + " of projectpath: " + ProjectPath + " and sharedpath: " + SharedPath)
                                    label = ""
                            else:
                                label = self.GetLabelForRevision("", SandboxPath, revision)
                                if (label == 1):
                                    print datetime.now().strftime(
                                            "%Y_%m_%d %H:%M:%S") + " ERROR: si viewprojecthistory command failed"
                                    self.Log("Error", " in GetLabelForRevision of projectpath: " + ProjectPath)
                                    return_val = 1
                                    label = ""
                                elif (label == 0):
                                    self.Log("Info",
                                             " no label found for revision: " + revision + " of projectpath: " + ProjectPath + " and sharedpath: " + SharedPath)
                                    label = ""
                        # create XML elements of XML File
                        elem = self.SharedProjects.createElement("SharedProjectConfig")

                        elem.setAttribute('Path', ProjectPath)

                        sub_elem = self.SharedProjects.createElement("SharedProjectLocation")
                        sub_elem.setAttribute('SharedPath', SharedPath)
                        elem.appendChild(sub_elem)

                        sub_elem = self.SharedProjects.createElement("Label")
                        sub_elem.setAttribute('Label', label)
                        elem.appendChild(sub_elem)

                        sub_elem = self.SharedProjects.createElement("Revision")
                        sub_elem.setAttribute('Revision', revision)
                        elem.appendChild(sub_elem)

                        sub_elem = self.SharedProjects.createElement("Type")
                        sub_elem.setAttribute('Type', type)
                        elem.appendChild(sub_elem)

                        # Extract CompName from shared path ATTENTION !!! RANKING is IMPORTANT!!!
                        CompName = ""

                        FindIt = '05_Algorithm/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/projekte1/tools/custom/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/projekte1/component/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        ListD = ['/nfs/projekte1/REPOSITORY/Tools/Validation_Tools/DHP_DataHandlingProcessing/',
                                 '/nfs/projekte1/REPOSITORY/Tools/Validation_Tools/CTB_CommonToolBox/',
                                 '/nfs/projekte1/REPOSITORY/Tools/Validation_Tools/Lib_Libraries/STK_ScriptingToolKit/05_Software/04_Engineering/01_Source_Code/',
                                 '/nfs/projekte1/REPOSITORY/Tools/Validation_Tools/Lib_Libraries/',
                                 '/projekte1/REPOSITORY/Tools/',
                                 '/nfs/projekte1/REPOSITORY/Function_Projects/',
                                 '/nfs/projekte1/SW/',
                                 '/nfs/projekte1/SW/SW_ARS4xx/',
                                 '/ADAS/SW/Components/ErrMgt/',
                                 '/ADAS/SW/Components/Types/',
                                 '/ADAS/SW/Components/',
                                 '/ADAS/SW/Projects/',
                                 '/ADAS/SW/Integration/',
                                 '/ADAS/SW/',
                                 '/ADAS/Projects/']
                        # '/nfs/projekte1/SW/SW_ARS4xx/' should not be used to extract CompName, instead it should be set according to '/nfs/projekte1/SW/'

                        for x in ListD:
                            FindIt = x
                            First = SharedPath.find(FindIt)
                            if (First != -1):
                                First = First + len(FindIt)
                                CompName = SharedPath[First:]
                                End = CompName.find('/')
                                CompName = CompName[:End]
                                elem.setAttribute('CompName', CompName)
                                break

                        FindIt = '/nfs/projekte1/REPOSITORY/Tools/Validation_Tools/Lib_Libraries/STK_ScriptingToolKit/05_Software/04_Engineering/01_Source_Code/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/projekte1/REPOSITORY/Base_Development/Base_CGEB/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            # First  = First + len(FindIt)
                            # CompName = SharedPath[First:]
                            # End = CompName.find('/')
                            # hard coded for CGEB
                            CompName = 'Base_CGEB'
                            elem.setAttribute('CompName', 'Base_CGEB')

                        FindIt = '/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/projekte1/REPOSITORY/Base_Development/05_Algorithm/STP_SharedToolProjects/04_Engineering/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                            # FindIt = '/projekte1/REPOSITORY/Base_Development/05_Algorithm/ACC_AdaptiveCruiseControl/05_Testing/05_Test_Environment/acc/30_BBT_BlackBoxTest/'
                            # First = SharedPath.find(FindIt)
                            # if (First != -1):
                            # First  = First + len(FindIt)
                            # CompName = SharedPath[First:]
                            # End = CompName.find('/')
                            # CompName = CompName[:End]
                            # elem.setAttribute('CompName',CompName)

                        FindIt = '/projekte1/REPOSITORY/Base_Development/05_Algorithm/ACC_AdaptiveCruiseControl/05_Testing/05_Test_Environment/acc/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                            # FindIt = '/projekte1/REPOSITORY/Base_Development/05_Algorithm/ACC_AdaptiveCruiseControl/05_Testing/05_Test_Environment/acc/30_BBT_BlackBoxTest/20_RequirementTest/'
                            # First = SharedPath.find(FindIt)
                            # if (First != -1):
                            # First  = First + len(FindIt)
                            # CompName = SharedPath[First:]
                            # End = CompName.find('/')
                            # CompName = CompName[:End]
                            # elem.setAttribute('CompName',CompName)

                        FindIt = '/projekte1/REPOSITORY/Application_Projects/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            CompName = 'Application_Projects'
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/nfs/projekte1/REPOSITORY/Base_Development/BaseDevelopment_Camera_SW/02_Engineering/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        # for ARS400 Project
                        FindIt = '/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            FindItCoreComp = '/nfs/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/05_Software/03_Design/02_Architecture/CoreMpc567/core_mpc567_rpy/'
                            FirstCoreComp = SharedPath.find(FindItCoreComp)
                            if (FirstCoreComp != -1):
                                FindItPlugin = '/nfs/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/05_Software/03_Design/02_Architecture/CoreMpc567/core_mpc567_rpy/Plugins/'
                                FirstPlugin = SharedPath.find(FindItPlugin)
                                if (FirstPlugin != -1):
                                    FindItPlugins = '/nfs/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/05_Software/03_Design/02_Architecture/CoreMpc567/core_mpc567_rpy/Plugins/project.pj'
                                    Plugins = SharedPath.find(FindItPlugin)
                                    if (Plugins != -1):
                                        CompName = "SW_Plugins"
                                        elem.setAttribute('CompName', CompName)
                                    else:
                                        FirstPlugin = FirstPlugin + len(FindItPlugin)
                                        CompName = SharedPath[FirstPlugin:]
                                        End = CompName.find('/')
                                        CompName = "SW_Plugin_%s" % CompName[:End]
                                        elem.setAttribute('CompName', CompName)
                                else:
                                    FirstCoreComp = FirstCoreComp + len(FindItCoreComp)
                                    CompName = SharedPath[FirstCoreComp:]
                                    End = CompName.find('/')
                                    CompName = "SW_CoreComp_%s" % CompName[:End]
                                    elem.setAttribute('CompName', CompName)
                            else:
                                # First  = First + len(FindIt)
                                # CompName = SharedPath[First:]
                                # End = CompName.find('/')
                                # hard coded for CGEB
                                CompName = 'Base_CoreMPC567'
                                elem.setAttribute('CompName', 'Base_CoreMPC567')

                        # Base Core project
                        FindIt = '/projekte1/REPOSITORY/Base_Development/Base_Core/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            # First  = First + len(FindIt)
                            # CompName = SharedPath[First:]
                            # End = CompName.find('/')
                            # hard coded
                            CompName = 'Base_Core'
                            elem.setAttribute('CompName', 'Base_Core')

                        FindIt = '/PROJECTS/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)
                            # notice that Project Shared Component e.g. ARS301 SMR200 ARS400 exist in the Project for further use in CheckSetProject(), CheckSetProjectCfg() and ConfigureSharedProjects()
                            if os.path.dirname(self.ActBaseProjectPath) in os.path.dirname(SharedPath):
                                self.ProjectShareCompName = CompName

                        FindIt = '/SW_MFC4xx/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            FindItTi = '/SW_MFC4xx/SW_SMFC400_PR/04_Engineering/02_Development_Tools/'
                            FirstTi = SharedPath.find(FindItTi)
                            if (FirstTi != -1):
                                FirstTi = FirstTi + len(FindItTi)
                                CompName = SharedPath[FirstTi:]
                                End = CompName.find('/')
                                CompName = CompName[:End]
                                elem.setAttribute('CompName', "SW_%s" % CompName)
                            else:
                                First = First + len(FindIt)
                                CompName = SharedPath[First:]
                                End = CompName.find('/')
                                CompName = CompName[:End]
                                elem.setAttribute('CompName', CompName)
                            # notice that Project Shared Component e.g. ARS301 SMR200 ARS400 exist in the Project for further use in CheckSetProject(), CheckSetProjectCfg() and ConfigureSharedProjects()
                            if os.path.dirname(self.ActBaseProjectPath) in os.path.dirname(SharedPath):
                                self.ProjectShareCompName = CompName

                        # added SW_MFC411 project, needed for parsing of SW SoC sandbox
                        FindIt = '/nfs/projekte1/SW/SW_MFC411x/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/nfs/projekte1/REPOSITORY/Base_Development/Generic_Software_Modules/MPC56XXK/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = "GenSwMod_MPC56XXK_%s" % CompName[:End]
                            elem.setAttribute('CompName', CompName)

                        FindIt = '/nfs/projekte1/REPOSITORY/Base_Projects/SMFC4B0_FBL/05_Software/M11_UFBL/'
                        First = SharedPath.find(FindIt)
                        if (First != -1):
                            First = First + len(FindIt)
                            CompName = SharedPath[First:]
                            End = CompName.find('/')
                            CompName = "SMFC4B0_FBL_M11_UFBL"
                            elem.setAttribute('CompName', CompName)

                        if CompName == "":
                            # print SharedPath
                            self.Log("Info", "Component name for subproject: %s not found" % (ProjectPath))

                        self.Log("Debug",
                                 "Add shared %s subproject: %s of component: %s to xml" % (type, ProjectPath, CompName))

                        # exlude Project if in exlude file
                        if self.CheckIfPathShouldBeExcluded(ProjectPath, self.ExcludeFile) == False:
                            # add Child to document
                            self.SharedProjects.documentElement.appendChild(elem)

                            if self.UseDatabase == True:
                                # -------------- new with database ---------------
                                # self.Log("Info", "TimeScann1")
                                self.mks_config_db.AddShare(SharedPath, ProjectPath, CompName, SandboxPath)
                                # self.Log("Info", "TimeScann2")
                                # TODO: RescanCandidates must initiated befor usage
                                if self.mks_config_db.CheckRescan(SharedPath) == True or SharedPath in RescanCandidates:
                                    self.RescanSharedPath(SharedPath)
                                    rescanned_pathes.append(SharedPath)
                                else:
                                    self.Log("Debug", "Project rescan skipped for %s" % SharedPath)
                                # fill dict from db
                                if not SharedPath in self.SharedProjectLabelsDevPathInfo:
                                    self.SharedProjectLabelsDevPathInfo[SharedPath] = {}

                                # self.Log("Info", "GetDevPathDict1")
                                dev_path_dict, dev_path_label_dict, label_dict = self.mks_config_db.GetDevPathesDevPathsLabelRevDictAndLabels(
                                        SharedPath)
                                # self.Log("Info", "GetDevPathDict2")

                                # all devapthes for this share with revision
                                self.SharedProjectLabelsDevPathInfo[SharedPath][
                                    "DevPath"] = dev_path_dict  # self.mks_config_db.GetAllDevPathes(SharedPath)
                                # per path all labels with revisions
                                self.SharedProjectLabelsDevPathInfo[SharedPath][
                                    "DevPaths"] = dev_path_label_dict  # self.mks_config_db.GetDevPathsLabelRevDict(SharedPath)
                                # if labels already found
                                if len(self.retGetAllLabelsDict) > 0:
                                    self.SharedProjectLabelsDevPathInfo[SharedPath]["Build"] = self.retGetAllLabelsDict
                                else:
                                    self.SharedProjectLabelsDevPathInfo[SharedPath][
                                        "Build"] = label_dict  # self.mks_config_db.GetAllLabels(SharedPath)

                            else:
                                # -------------- old --------------
                                if GenLabelDevPathDict == True:
                                    # build the label and dev path dictionalry for this shared sub project
                                    if not SharedPath in self.SharedProjectLabelsDevPathInfo:
                                        self.SharedProjectLabelsDevPathInfo[SharedPath] = {}

                                    # self.Log("Info","Getting sandbox detail history part 1")

                                    self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"] = self.GetAllDevPathes(
                                            SharedPath)
                                    self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPaths"] = {}
                                    # print self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"]
                                    # self.Log("Info","Getting sandbox detail history part 2 old")
                                    # if self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"] != 0:
                                    # for path in self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"]:
                                    # self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPaths"][path] = self.GetAllLabelsForSharedProject(SharedPath,path)

                                    # self.Log("Info","Getting sandbox detail history part 2 new")
                                    org_all_labels = self.GetAllLabelsForSharedProject(SharedPath)
                                    all_labels = copy.deepcopy(org_all_labels)
                                    test = {}
                                    if self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"] != 0:
                                        old_var_flag = {}
                                        for path in self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"]:
                                            if self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"][
                                                path] in old_var_flag:
                                                old_var_flag[self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"][
                                                    path]] = True
                                            else:
                                                old_var_flag[self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"][
                                                    path]] = False

                                        countA = 0
                                        countB = 0
                                        for path in self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"]:
                                            if old_var_flag[self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"][
                                                path]] == False:
                                                dev_path_rev = \
                                                    self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"][
                                                        path].split(
                                                            '.')
                                                temp_label_dict = {}
                                                # if path match label rev add to list
                                                for label_item in all_labels:
                                                    act_label_rev = all_labels[label_item].split('.')
                                                    if self.CheckIfRevisionOnDevPath(dev_path_rev, act_label_rev):
                                                        temp_label_dict[label_item] = all_labels[label_item]

                                                for label_item in temp_label_dict:
                                                    all_labels.pop(label_item)

                                                # test[path] = temp_label_dict
                                                self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPaths"][
                                                    path] = temp_label_dict
                                                countA += 1
                                            else:
                                                self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPaths"][
                                                    path] = self.GetAllLabelsForSharedProject(SharedPath, path)
                                                countB += 1
                                        self.Log("Debug", "Number of fast labels: %s, Number of slow labels: %s" % (
                                            countA, countB))

                                        #                                    #test code
                                        # for path in test:
                                        #     if len(test[path]) != len(self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPaths"][path]):
                                        #         self.Log("Error","Size not equal")
                                        #     for label in self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPaths"][path]:
                                        #         if label in test[path]:
                                        #             test[path].pop(label)
                                        #         else:
                                        #            self.Log("Error","Labels not found in new")
                                        #     if len(test[path])!= 0:
                                        #         self.Log("Error","Labels not equal")

                                        # self.Log("Info","Getting sandbox detail history part 3")
                                    # if labels already found
                                    if len(self.retGetAllLabelsDict) > 0:
                                        self.SharedProjectLabelsDevPathInfo[SharedPath][
                                            "Build"] = self.retGetAllLabelsDict
                                    else:
                                        self.SharedProjectLabelsDevPathInfo[SharedPath][
                                            "Build"] = org_all_labels  # self.GetAllLabelsForSharedProject(SharedPath)

                            if GenPreConfigSharedProjectDict == True:
                                # safe the current state of component
                                # build the label and dev path dictionalry for this shared sub project
                                if not ProjectPath in self.PreConfigSharedProjectDict:
                                    self.PreConfigSharedProjectDict[ProjectPath] = {}

                                self.PreConfigSharedProjectDict[ProjectPath]["CompName"] = CompName
                                self.PreConfigSharedProjectDict[ProjectPath]["SharedPath"] = SharedPath
                                self.PreConfigSharedProjectDict[ProjectPath]["Label"] = label
                                self.PreConfigSharedProjectDict[ProjectPath]["Revision"] = revision
                                self.PreConfigSharedProjectDict[ProjectPath]["Type"] = type
                        else:
                            self.Log("Info", "Project %s is excluded from configuration" % ProjectPath)
                else:
                    self.Log("Error", "Type of shared project could not be extracted")

                self.Log("Info", "Getting sandbox history %s of %s shares done" % (index, number_of_shares))

            self.Log("Info", "Stop getting sandbox history")

        return (return_val, rescanned_pathes)

    def ParseForSharedProjectfromDict(self, InputFileName, InputDictName):
        ###########
        #
        # ParseForSharedProjectfromDict(self, InputFileName, InputDictName)
        #
        # Description:    Parse for all shared projects in project or the sandbox which are found in InputFileName e.g. pre_config_shared_projects.xml
        #                 and add it to an xml stuct with all shared subpojects (normal/variant/build)
        #                 This xml includes the project path and the shared project path
        #                 the revision and the corresponding label, and the type(normal/variant/build) which is read from in InputDictName
        #
        # Parameter:      InputFileName:    the file name of the input xml file            e.g. pre_config_shared_projects.xml
        #                 InputDictName:    the dictionary name of the input dictionary    e.g. self.PreConfigSharedProjectDict
        #
        # Return:         0 if ok 1 if errors occur
        #
        # Author:         Ilja Hotjakov 05.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        InputDict = {}
        return_val = 0
        # copy for removing the components in Dict
        InputDict = copy.deepcopy(InputDictName)

        # create md5 hash object
        hash = hashlib.md5()

        # read the Project Path from InputFileName
        SharedProjects = self.get_a_document(InputFileName)
        SharedProjects.normalize()
        SharedProjectConfigs = SharedProjects.getElementsByTagName("SharedProjectConfig")
        for SharedProjectConfig in SharedProjectConfigs:
            ProjectPath = ""
            ProjectPath = SharedProjectConfig.getAttribute("Path")

            if (len(ProjectPath) > 0):
                # Init
                CompName = ""
                SharedPath = ""
                label = ""
                revision = ""
                type = ""

                # If exist
                if (ProjectPath in InputDict):
                    CompName = InputDict[ProjectPath]["CompName"]
                    SharedPath = InputDict[ProjectPath]["SharedPath"]
                    label = InputDict[ProjectPath]["Label"]
                    revision = InputDict[ProjectPath]["Revision"]
                    type = InputDict[ProjectPath]["Type"]

                    del InputDict[ProjectPath]

                    # control inputs
                    if (CompName == ""):
                        self.Log("Info", " CompNameis is empty of projectpath: " + ProjectPath)
                        return 1
                    if (SharedPath == ""):
                        self.Log("Info", " SharedPath is empty of projectpath: " + ProjectPath)
                        return 1
                    if (label == "" and type != "normal"):
                        self.Log("Info", " Label is empty of projectpath: " + ProjectPath)
                        return 1
                    if (revision == "") and ((type != "normal") and (type != "variant")):
                        self.Log("Info", " Revision is empty of projectpath: " + ProjectPath)
                        return 1
                    if (type == ""):
                        self.Log("Info", " type is empty of projectpath: " + ProjectPath)
                        return 1

                    # create XML elements of XML File
                    elem = self.SharedProjects.createElement("SharedProjectConfig")

                    elem.setAttribute('CompName', CompName)

                    elem.setAttribute('Path', ProjectPath)

                    sub_elem = self.SharedProjects.createElement("SharedProjectLocation")
                    sub_elem.setAttribute('SharedPath', SharedPath)
                    elem.appendChild(sub_elem)

                    sub_elem = self.SharedProjects.createElement("Label")
                    # if type == "normal":
                    #     sub_elem.setAttribute('Label',"")
                    # else:
                    sub_elem.setAttribute('Label', label)
                    elem.appendChild(sub_elem)

                    sub_elem = self.SharedProjects.createElement("Revision")
                    # if type == "build":
                    sub_elem.setAttribute('Revision', revision)
                    # else:
                    #     sub_elem.setAttribute('Revision',"")
                    elem.appendChild(sub_elem)

                    sub_elem = self.SharedProjects.createElement("Type")
                    sub_elem.setAttribute('Type', type)
                    elem.appendChild(sub_elem)
                    path = ProjectPath.split('/')
                    if type == "normal":
                        # print ("%s,%s,%s")%(path[-2],path[-1], type)
                        hash.update(("%s,%s,%s") % (path[-2], path[-1], type))
                    elif type == "build":
                        # print ("%s,%s,%s,%s")%(path[-2],path[-1], type, revision)
                        hash.update(("%s,%s,%s,%s") % (path[-2], path[-1], type, revision))
                    elif type == "variant":
                        # print ("%s,%s,%s,%s")%(path[-2],path[-1], type, label)
                        hash.update(("%s,%s,%s,%s") % (path[-2], path[-1], type, label))

                    # add Child to document
                    self.SharedProjects.documentElement.appendChild(elem)
                else:
                    self.Log("Debug", " projectpath: " + ProjectPath + " not found in Dict")
            else:
                self.Log("Info", " projectpath: " + ProjectPath + " is empty")

        self.SharedProjects.documentElement.setAttribute("MD5Hash", hash.hexdigest())

        return return_val

    def ParseForSharedProjectfromFile(self, InputFileName):
        ###########
        #
        # ParseForSharedProjectfromFile(self, InputFileName)
        #
        # Description:    Parse for all shared projects in project or the sandbox which are found in InputFileName e.g. pre_config_shared_projects.xml
        #                 and add it to an xml struct with all shared subpojects (normal/variant/build)
        #                 This xml includes the project path and the shared project path
        #                 the revision and the corresponding label, and the type(normal/variant/build)
        #                 This function work only with projectpath, be sicher sure that the normal in mks has all the sub-projects that the branch of this project includes, else you get an error
        #
        # Parameter:      InputFileName:    the file name of the input xml file                                                    e.g. pre_config_shared_projects.xml
        #
        # Return:         0 if ok 1 if errors occur
        #
        # Author:         Ilja Hotjakov 05.04.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        scannedProjectsDict = {}
        return_val = 0
        # read the Project Path from InputFileName
        SharedProjects = self.get_a_document(InputFileName)
        SharedProjects.normalize()
        SharedProjectConfigs = SharedProjects.getElementsByTagName("SharedProjectConfig")
        for SharedProjectConfig in SharedProjectConfigs:
            ProjectPath = ""
            CompName = ""
            ProjectPath = SharedProjectConfig.getAttribute("Path")
            CompName = SharedProjectConfig.getAttribute("CompName")

            if (len(ProjectPath) > 0):
                # Init
                type = ""
                revision = ""
                label = ""

                # If not scanned allready get the type revision and Devpath if variant
                if not (ProjectPath in scannedProjectsDict):
                    retTypeDict = self.GetProjectTypeDict(ProjectPath)
                    if (retTypeDict == 1):
                        print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewproject command failed"
                        self.Log("Error", "Could not read/extract actual type from " + ProjectPath)
                        return_val = 1
                    elif (retTypeDict == 2):
                        self.Log("Info", " no entries found for " + ProjectPath)
                    elif not (ProjectPath in retTypeDict):
                        self.Log("Error", "Could not find actual type for " + ProjectPath)
                    else:
                        i = 0
                        while i < len(retTypeDict):
                            KeyDict = retTypeDict.keys()[i]
                            if KeyDict == ProjectPath:
                                type = retTypeDict[ProjectPath]["Type"]
                                revision = retTypeDict[ProjectPath]["Revision"]
                                label = retTypeDict[ProjectPath]["Label"]
                            elif not (KeyDict in scannedProjectsDict):
                                scannedProjectsDict[KeyDict] = {}
                                scannedProjectsDict[KeyDict]["Type"] = retTypeDict[KeyDict]["Type"]
                                scannedProjectsDict[KeyDict]["Revision"] = retTypeDict[KeyDict]["Revision"]
                                scannedProjectsDict[KeyDict]["Label"] = retTypeDict[KeyDict]["Label"]
                            i += 1

                if (type == ""):
                    type = scannedProjectsDict[ProjectPath]["Type"]
                    revision = scannedProjectsDict[ProjectPath]["Revision"]
                    label = scannedProjectsDict[ProjectPath]["Label"]
                    # del the used ProjectPath from Dict for faster useage in next run
                    del scannedProjectsDict[ProjectPath]

                if (type != ""):
                    SharedPath = self.GetSharedFromPath("project", ProjectPath)
                    if (SharedPath == 1):
                        print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si projectinfo command failed"
                        self.Log("Error", " in GetSharedFromPath of projectpath: " + ProjectPath)
                        return_val = 1
                        SharedPath = ""
                    elif (SharedPath == 0):
                        self.Log("Error", "2: no SharedPath found for projectpath: " + ProjectPath)
                        return_val = 1
                        SharedPath = ""
                    else:
                        # Find Label if Type == build
                        if (type == "build"):
                            label = ""
                            label = self.GetLabelForRevision(SharedPath, "", revision)
                            # label = self.GetLabelForRevision( "/nfs/projekte1/tools/custom/mts/sw/out/deploy_portable/project.pj", "", "1.1.1.8")
                            if (label == 1):
                                print datetime.now().strftime(
                                        "%Y_%m_%d %H:%M:%S") + " ERROR: si viewprojecthistory command failed"
                                self.Log("Error", " in GetLabelForRevision of projectpath: " + ProjectPath)
                                return_val = 1
                                label = ""
                            elif (label == 0):
                                self.Log("Info",
                                         " no label found for revision: " + revision + " of projectpath: " + ProjectPath + " and sharedpath: " + SharedPath)
                                label = ""

                        # create XML elements of XML File
                        elem = self.SharedProjects.createElement("SharedProjectConfig")

                        if (len(CompName) > 0):
                            elem.setAttribute('CompName', CompName)
                        else:
                            self.Log("Error", " CompName not found for projectpath: " + ProjectPath)
                            elem.setAttribute('CompName', "")
                            return_val = 1

                        elem.setAttribute('Path', ProjectPath)

                        sub_elem = self.SharedProjects.createElement("SharedProjectLocation")
                        sub_elem.setAttribute('SharedPath', SharedPath)
                        elem.appendChild(sub_elem)

                        sub_elem = self.SharedProjects.createElement("Label")
                        sub_elem.setAttribute('Label', label)
                        elem.appendChild(sub_elem)

                        sub_elem = self.SharedProjects.createElement("Revision")
                        sub_elem.setAttribute('Revision', revision)
                        elem.appendChild(sub_elem)

                        sub_elem = self.SharedProjects.createElement("Type")
                        sub_elem.setAttribute('Type', type)
                        elem.appendChild(sub_elem)

                        # exlude Project if in exlude file
                        if self.CheckIfPathShouldBeExcluded(ProjectPath, self.ExcludeFile) == False:
                            # add Child to document
                            self.SharedProjects.documentElement.appendChild(elem)

                        else:
                            self.Log("Info", "Project %s is excluded from configuration" % ProjectPath)
        return return_val

    def CreateSharedProjectXML(self, FileName, GenLabelDevPathDict, GenPreConfigSharedProjectDict):
        ###########
        #
        # CreateSharedProjectXML(self, FileName, GenLabelDevPathDict)
        #
        # Description: Create a xml file of all shared sub projects
        #
        # Parameter: -FileName the file name of the output xml file
        #            -GenLabelDevPathDict generate also a dictionary with all labels and dev paths of the shared sub projects
        #            -GenPreConfigSharedProjectDict generate a dictionary with label, revision, sharedpath, projectpath and type
        #
        # returns the rescanned pathes
        #
        # TODO: add parameter check
        #
        ###########
        self.Log("Info", "___________________________________________")
        self.Log("Info", "Create xml struct with all shared sub projects")
        self.SharedProjects = self.create_a_root_document('MKSSharedProjectConfig')
        # parse direcory for all shared projects and add it to the xml
        ret_values = self.ParseForSharedSandboxProject(self.Sandbox, GenLabelDevPathDict, GenPreConfigSharedProjectDict)
        if (self.Logging == True):
            file_object = open(FileName, "w")
            self.SharedProjects.writexml(file_object, "  ", "  ", "\n", "utf-8")
            file_object.close()
        return ret_values

    def CreateSharedProjectXMLfromFile(self, OutputFileName, InputFileName):
        ###########
        #
        # CreateSharedProjectXMLfromFile(self, OutputFileName, InputFileName)
        #
        # Description:    Create a xml file of all shared sub projects which are found in InputFileName e.g. pre_config_shared_projects.xml, first try from dictionary if fails then from MKS
        #
        # Parameter:      OutputFileName:    the file name of the output xml file                e.g. post_config_shared_projects.xml
        #                 InputFileName:     the file name of the input xml file                 e.g. pre_config_shared_projects.xml
        #
        # Return:         nothing
        #
        # Author:         Ilja Hotjakov 05.04.2012
        #
        # TODO: add parameter check
        #
        ###########
        self.Log("Info", "___________________________________________")
        self.Log("Info", "Create xml struct with all shared sub projects")
        self.SharedProjects = self.create_a_root_document('MKSSharedProjectConfig')
        # parse direcory for all shared projects and add it to the xml
        if (len(self.PreConfigSharedProjectDict) > 0):
            if self.ParseForSharedProjectfromDict(InputFileName, self.PreConfigSharedProjectDict) != 0:
                # clear XML
                self.SharedProjects = self.create_a_root_document('MKSSharedProjectConfig')
                # If from Dict failed
                self.ParseForSharedSandboxProject(self.Sandbox, False, False)
        else:
            self.ParseForSharedSandboxProject(self.Sandbox, False, False)

        if (self.Logging == True):
            file_object = open(OutputFileName, "w")
            self.SharedProjects.writexml(file_object, "  ", "  ", "\n", "utf-8")
            file_object.close()

    def CreateSharedProjectXMLfromDict(self, OutputFileName, InputFileName):
        ###########
        #
        # CreateSharedProjectXMLfromDict(self, OutputFileName, InputFileName)
        #
        # Description:    Create a xml file of all shared sub projects which are found in InputFileName e.g. pre_config_shared_projects.xml, first try from dictionary if fails then from MKS
        #
        # Parameter:      OutputFileName:    the file name of the output xml file                e.g. post_config_shared_projects.xml
        #                 InputFileName:     the file name of the input xml file                 e.g. pre_config_shared_projects.xml
        #
        # Return:         nothing
        #
        # Author:         Wolfgang Sinnwell 04.03.2015
        #
        # TODO: add parameter check
        #
        ###########
        self.Log("Info", "___________________________________________")
        self.Log("Info", "Create xml struct with all shared sub projects")
        self.SharedProjects = self.create_a_root_document('MKSSharedProjectConfig')
        # parse direcory for all shared projects and add it to the xml
        if (len(self.ChangedConfigSharedProjectDict) > 0):
            if self.ParseForSharedProjectfromDict(InputFileName, self.ChangedConfigSharedProjectDict) != 0:
                # clean XML
                self.SharedProjects = self.create_a_root_document('MKSSharedProjectConfig')
                # If from Dict failed
                self.ParseForSharedSandboxProject(self.Sandbox, False, False)
            if (self.Logging == True):
                file_object = open(OutputFileName, "w")
                self.SharedProjects.writexml(file_object, "  ", "  ", "\n", "utf-8")
                file_object.close()

        else:
            self.Log("Info", "ChangedConfigSharedProjectDict is EMPTY")
            file_object = open(OutputFileName, "w")
            file_object.close()

    def CheckSetProjectCfg(self, IsProjectsCfgEmpty, MasterConfig):
        ###########
        #
        # CheckSetProjectCfg(self, IsProjectsCfgEmpty, MasterConfig)
        #
        # Description: Checks if for all SharedProjects a config exits in the SetProjectsCfg xml
        #              if not or the config does not exist(empty) add a default blank config to the master config
        #              for the missing SharedProjects Components exept the root "CompName" (e.g. ARS301, SMR200, ARS400)
        #
        # Parameter:  -IsProjectsCfgEmpty if the config file does not exist set it to 1 and it is created
        #             -MasterConfig the master config xml dom object
        #
        # TODO: add parameter check
        #
        ###########
        diff_found = False
        TempSharedProjectCompName = ""
        SetProjectsDict = {}
        ActProjectsDict = {}
        # if the SetProjectCfg xml file exists read the CompNames from shared_project_config.xml to dictionary
        if (IsProjectsCfgEmpty == 0):
            # build a dictionary of all actual project inside of the set project xml file e.g. shared_project_config.xml
            BaseConfigNode = self.SetProjectsCfg.getElementsByTagName("BaseConfig")
            if (BaseConfigNode.length >= 1):
                BaseConfig = BaseConfigNode.item(0)
                BaseConfig.normalize()
                for SharedProject in BaseConfig.childNodes:
                    if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                        # print SharedProject.getAttribute("CompName")
                        TempSharedProjectCompName = SharedProject.getAttribute("CompName")
                        SetProjectsDict[SharedProject.getAttribute("CompName")] = TempSharedProjectCompName
                        # check if the ProjectShareCompName exist in the xml file e.g. shared_project_config.xml if exist read it from file
                        if (TempSharedProjectCompName == self.ProjectShareCompName and TempSharedProjectCompName != ""):
                            self.ProjectShareCompName = ""  # deactivate the self.ProjectShareCompName

            else:
                # if the file exists but there is no baseConfig node
                elem = self.SetProjectsCfg.getElementsByTagName("ConfigSharedProjects")[0]
                BaseConfig = self.SetProjectsCfg.createElement("BaseConfig")
                elem.insertBefore(BaseConfig, elem.firstChild)
        else:
            # if the fiel does not exists
            elem = self.SetProjectsCfg.createElement("ConfigSharedProjects")
            BaseConfig = self.SetProjectsCfg.createElement("BaseConfig")
            elem.appendChild(BaseConfig)
            self.SetProjectsCfg.appendChild(elem)
        # print self.SetProjectsCfg.toxml()

        # build a dictionary of all configured subprojects from dictionary thats are sama as e.g. pre_config_shared_projects.xml
        SharedProjects = self.SharedProjects.getElementsByTagName("SharedProjectConfig")
        for SharedProject in SharedProjects:
            SharedProject.normalize()
            if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                # print SharedProject.getAttribute("CompName")
                if not SharedProject.getAttribute("CompName") in ActProjectsDict:
                    # print SharedProject.getAttribute("CompName")
                    ActProjectsDict[SharedProject.getAttribute("CompName")] = SharedProject.getAttribute("CompName")

        # Get the Base config from the Master config
        BaseMasterConfig = MasterConfig.getElementsByTagName("BaseConfig").item(0)
        # compare actual subprojects with the config file subprojects
        for ActProject in ActProjectsDict:
            # if ActProject == self.ProjectShareCompName ignore it
            if ((not ActProject in SetProjectsDict) and ((
                                                                         ActProject != self.ProjectShareCompName and self.ProjectShareCompName != "") or self.ProjectShareCompName == "")):
                diff_found = True
                elem = MasterConfig.createElement("SharedProject")
                elem.setAttribute("CompName", ActProject)
                elem_cfg_n = MasterConfig.createElement("Config")
                elem_cfg_n.setAttribute("Type", "normal")
                elem.appendChild(elem_cfg_n)
                elem_cfg_v = MasterConfig.createElement("Config")
                elem_cfg_v.setAttribute("DevPathName", "")
                elem_cfg_v.setAttribute("Type", "variant")
                elem.appendChild(elem_cfg_v)
                elem_cfg_b = MasterConfig.createElement("Config")
                elem_cfg_b.setAttribute("Type", "build")
                elem_cfg_b.setAttribute("Label", "")
                elem.appendChild(elem_cfg_b)
                BaseMasterConfig.appendChild(elem)
                # print ActProject
                self.Log("Error",
                         "CompName: " + ActProject + " not in the configuration (*.xml) file you can find the information about this component in pre_config_shared_projects.xml")

        # print SetProjectsCfg.toprettyxml()
        return diff_found

    def CheckSharedProjectCompName(self, SharedProjectConfig, SharedProjectPath, SharedProject, Label, DevPathName,
                                   Config_type):
        ###########
        #
        # CheckSharedProjectCompName(self,SharedProjectConfig,SharedProjectPath,SharedProject,Config_type)
        #
        # Description: Check if the shared project in the SharedProjectConfig e.g pre_config_shared_projects.xml is the actual config from SharedProject e.g. shared_project_config.xml
        #
        # Parameter: -SharedProjectConfig this line of the xml <SharedProjectConfig CompName="RSP_ARS301based_RawSignalProcessing" Path="/....
        #            -SharedProjectPath this line of the xml <SharedProjectLocation SharedPath="/nfs/p....
        #            -SharedProject this line fo the config xml <SharedProject CompName="VDY_VehicleDynamics">
        #            -Label this is the label defintion in the config xml <Config Label="SW_RTE_ARS301_09.00.01_Release" Type="build"/>
        #            -DevPathName this is the dev path name definition in the config xml <Config DevPathName="ALN_ARS301" Type="variant"/>
        #            -Config_type is base or custom
        #
        # return 0 if the config project is not found in the SharedProjectConfig
        #
        # TODO: add parameter check
        #
        ###########
        # if base und ProjectShareCompName
        if (Config_type == "Base" and SharedProject == self.ProjectShareCompName and self.ProjectShareCompName != ""):
            # print SharedProjectConfig.getAttribute("CompName")
            # print SharedProject.getAttribute("CompName")
            if (SharedProjectConfig.getAttribute("CompName") == self.ProjectShareCompName):
                return 1
            else:
                return 0
        if (Config_type == "Base"):
            # print SharedProjectConfig.getAttribute("CompName")
            # print SharedProject.getAttribute("CompName")
            if (SharedProjectConfig.getAttribute("CompName") == SharedProject.getAttribute("CompName")):
                return 1
            else:
                return 0
        if (Config_type == "Custom"):
            # print SharedProjectPath.getAttribute("SharedPath")
            # print SharedProject.getAttribute("SharedPath")
            if (SharedProjectPath.getAttribute("SharedPath") == SharedProject.getAttribute("SharedPath")):
                return 1
            else:
                return 0
        if (Config_type == "CustomV2"):
            # print SharedProjectPath.getAttribute("SharedPath")
            # print Label
            # print DevPathName
            if (SharedProjectPath.getAttribute("SharedPath") in self.SharedProjectLabelsDevPathInfo):
                ret_value = 0
                if (len(Label) > 0):
                    # print "check label"
                    # print SharedProjectPath.getAttribute("SharedPath")
                    # print Label
                    # print self.SharedProjectLabelsDevPathInfo[SharedProjectPath.getAttribute("SharedPath")]["Build"]
                    if (Label in self.SharedProjectLabelsDevPathInfo[SharedProjectPath.getAttribute("SharedPath")][
                        "Build"]):
                        ret_value = 2
                    # print Label
                    else:
                        if ((len(DevPathName) > 0) and (
                                    self.SharedProjectLabelsDevPathInfo[SharedProjectPath.getAttribute("SharedPath")][
                                        "DevPath"] != 0)):
                            if (DevPathName in
                                    self.SharedProjectLabelsDevPathInfo[SharedProjectPath.getAttribute("SharedPath")][
                                        "DevPath"]):
                                ret_value = 2
                                # print DevPathName

                if ((len(DevPathName) > 0) and (
                            self.SharedProjectLabelsDevPathInfo[SharedProjectPath.getAttribute("SharedPath")][
                                "DevPath"] != 0)):
                    if (DevPathName in
                            self.SharedProjectLabelsDevPathInfo[SharedProjectPath.getAttribute("SharedPath")][
                                "DevPath"]):
                        ret_value = 2
                        # print DevPathName
                return ret_value
            else:
                return 0
        if (Config_type == "CustomV3"):
            if (SharedProjectConfig.getAttribute("Path") == SharedProject.getAttribute("Path")):
                return 1
            else:
                return 0
        else:
            return 0

    def CheckForDoubleConfigEntries(self, Dest, AttrName, Value):
        ###########
        #
        # CheckForDoubleConfigEntries(self)
        #
        # Description: Check if in all the Dest nodes is one node where the attribut AttrName has the Value Value
        #              if found return false because this is a double entry
        #
        # Parameter: -Dest the Destination dom object
        #            -AttrName No Node with this Attribut name should be in des
        #            -Value the value of the AddrName
        #
        # return False in case of double entry found, else True
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = True
        for ChildNode in Dest.childNodes:
            if (ChildNode.nodeType == ChildNode.ELEMENT_NODE):
                if ChildNode.getAttribute(AttrName) == Value:
                    ret_value = False

        return ret_value

    def MergeCfgFiles(self, Dest, Source):
        ###########
        #
        # MergeCfgFiles(self)
        #
        # Description: Merge the config xml dom objects
        #              check if a node already exist in the dest config
        #
        # return False in case of double defined configs in two files
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = True

        Trunk = Dest.getElementsByTagName("ConfigSharedProjects")
        if (Trunk.length == 0) or (Trunk == None):
            Trunk = Dest.createElement("ConfigSharedProjects")
            Dest.appendChild(Trunk)
        else:
            Trunk = Trunk.item(0)

        BaseConfigNodesSource = Source.getElementsByTagName("BaseConfig").item(0)
        if (BaseConfigNodesSource != None):
            BaseConfigNodes = Dest.getElementsByTagName("BaseConfig").item(0)
            if BaseConfigNodes == None:
                BaseConfigNodes = Dest.createElement("BaseConfig")
                Trunk.appendChild(BaseConfigNodes)
            for ChildNode in BaseConfigNodesSource.childNodes:
                if (ChildNode.nodeType == ChildNode.ELEMENT_NODE):
                    DoubleCheck = self.CheckForDoubleConfigEntries(BaseConfigNodes, "CompName",
                                                                   ChildNode.getAttribute("CompName"))
                    if DoubleCheck == False:
                        ret_value = False
                        self.Log("Error",
                                 "Base configuration entry with CompName %s already exists in previous config file" % ChildNode.getAttribute(
                                         "CompName"))
                BaseConfigNodes.appendChild(ChildNode.cloneNode(True))
                # print BaseConfigNodes.toxml()

        CustomConfigNodesSource = Source.getElementsByTagName("CustomConfig").item(0)
        if (CustomConfigNodesSource != None):
            CustomConfigNodes = Dest.getElementsByTagName("CustomConfig").item(0)
            if CustomConfigNodes == None:
                CustomConfigNodes = Dest.createElement("CustomConfig")
                Trunk.appendChild(CustomConfigNodes)
            for ChildNode in CustomConfigNodesSource.childNodes:
                if (ChildNode.nodeType == ChildNode.ELEMENT_NODE):
                    DoubleCheck = self.CheckForDoubleConfigEntries(CustomConfigNodes, "SharedPath",
                                                                   ChildNode.getAttribute("SharedPath"))
                    if DoubleCheck == False:
                        ret_value = False
                        self.Log("Error",
                                 "Custom configuration entry with SharedPath %s already exists in previous config file" % ChildNode.getAttribute(
                                         "SharedPath"))
                CustomConfigNodes.appendChild(ChildNode.cloneNode(True))

        CustomV2ConfigNodesSource = Source.getElementsByTagName("CustomConfigV2").item(0)
        if (CustomV2ConfigNodesSource != None):
            CustomV2ConfigNodes = Dest.getElementsByTagName("CustomConfigV2").item(0)
            if CustomV2ConfigNodes == None:
                CustomV2ConfigNodes = Dest.createElement("CustomConfigV2")
                Trunk.appendChild(CustomV2ConfigNodes)
            for ChildNode in CustomV2ConfigNodesSource.childNodes:
                # custom config v2 could not be checked for double configs
                CustomV2ConfigNodes.appendChild(ChildNode.cloneNode(True))

        CustomV3ConfigNodesSource = Source.getElementsByTagName("CustomConfigV3").item(0)
        if (CustomV3ConfigNodesSource != None):
            CustomV3ConfigNodes = Dest.getElementsByTagName("CustomConfigV3").item(0)
            if CustomV3ConfigNodes == None:
                CustomV3ConfigNodes = Dest.createElement("CustomConfigV3")
                Trunk.appendChild(CustomV3ConfigNodes)
            for ChildNode in CustomV3ConfigNodesSource.childNodes:
                if (ChildNode.nodeType == ChildNode.ELEMENT_NODE):
                    DoubleCheck = self.CheckForDoubleConfigEntries(CustomV3ConfigNodes, "Path",
                                                                   ChildNode.getAttribute("Path"))
                    if DoubleCheck == False:
                        ret_value = False
                        self.Log("Error",
                                 "CustomV3 configuration entry with Path %s already exists in previous config file" % ChildNode.getAttribute(
                                         "Path"))
                CustomV3ConfigNodes.appendChild(ChildNode.cloneNode(True))

        return ret_value

    def GetConfigFileList(self, ConfigFileName):
        ###########
        #
        # GetConfigFileList(self)
        #
        # Description: Read the config xml file (e.g. shared_project_config_files.xml etc.)
        #              and check if it is a file list of shared sub project config files or not
        #              If it is a file list open all files and merge the files
        #
        # return None if the configuration is not ok, otherwise return a dictionary containing the xml dom config, the master file xml dom config and the masterfile path
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = {}
        CfgPath = os.path.split(ConfigFileName)[0]
        if os.path.isfile(ConfigFileName) == False:
            self.Log("Error", "Config file %s does not exist" % ConfigFileName)
            return None

        try:
            CfgFile = self.get_a_document(ConfigFileName)
        except Exception, e:
            # TODO: CfgFile must initiated befor usage
            self.Log("Error", "Config file %s could not be opened (xml parser message: %s)" % (CfgFile, e))
            return None

        FileNodes = CfgFile.getElementsByTagName("ConfigSharedProjectsFiles").item(0)
        if FileNodes == None:
            self.Log("Info", "Input config file is a shared project config file")
            ret_value["Masterfile"] = ConfigFileName
            ret_value["Config"] = CfgFile
            ret_value["MasterConfig"] = CfgFile
        else:
            self.Log("Info", "Input config file is a file list of shared project config files")
            SetProjectsCfg = self.create_a_document()
            SetProjectsCfg.appendChild(
                    SetProjectsCfg.createProcessingInstruction("xml-stylesheet",
                                                               "type=\"text/xsl\" href=\"Config.xslt\""))
            ret_value["Config"] = SetProjectsCfg
            for SharedProject in FileNodes.childNodes:
                if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                    ActCfgFileName = CfgPath + "\\" + SharedProject.getAttribute("File")
                    if os.path.isfile(ActCfgFileName) == False:
                        self.Log("Error", "Config file %s does not exist" % ActCfgFileName)
                        ret_value = None
                        break
                    try:
                        ActCfgFile = self.get_a_document(ActCfgFileName)
                    except Exception, e:
                        self.Log("Error",
                                 "Config file %s could not be opened (xml parser message: %s)" % (ActCfgFileName, e))
                        ret_value = None
                        break
                    self.Log("Info", "Get shared project configurations from file %s" % ActCfgFileName)
                    # if the type file type is not set in config file take the first enty as master file
                    if "Masterfile" not in ret_value:
                        ret_value["Masterfile"] = ActCfgFileName
                        ret_value["MasterConfig"] = ActCfgFile
                    # if the master type is set use this file as master
                    if (SharedProject.getAttribute("Type") == "master"):
                        ret_value["Masterfile"] = ActCfgFileName
                        ret_value["MasterConfig"] = ActCfgFile

                    if self.MergeCfgFiles(SetProjectsCfg, ActCfgFile) == False:
                        ret_value = None
                        break
                        # print SetProjectsCfg.toxml()
        return ret_value

    def ReadAndUpdateConfig(self):
        ###########
        #
        # ReadAndUpdateConfig(self)
        #
        # Description: Read the config xml file and check if all shared subprojects have
        #              a config entry in the configuration and add it if missing
        #
        # return 0 if the configuration is updated otherwise return the configuration xml struct
        #
        # TODO: add parameter check
        #
        ###########
        self.Log("Info", "___________________________________________")
        # SharedProjects = get_a_document('MKSSharedProjectCfg.xml')
        IsProjectsCfgEmpty = 1

        # save xlst and css file if it does not exits
        self.SaveConfigXSLTAndCss(self.ConfigFileName)
        Masterfile = ""
        # read set config xml file
        if (os.path.isfile(self.ConfigFileName) == 1):
            # load an existing project cfg file
            ConfigInfos = self.GetConfigFileList(self.ConfigFileName)
            if ConfigInfos != None:
                Masterfile = ConfigInfos["Masterfile"]
                self.SetProjectsCfg = ConfigInfos["Config"]
                MasterConfig = ConfigInfos["MasterConfig"]
                IsProjectsCfgEmpty = 0
            else:
                return 0
        else:
            # create a new project cfg document
            Masterfile = self.ConfigFileName
            self.SetProjectsCfg = self.create_a_document()
            self.SetProjectsCfg.appendChild(self.SetProjectsCfg.createProcessingInstruction("xml-stylesheet",
                                                                                            "type=\"text/xsl\" href=\"Config.xslt\""))
            MasterConfig = self.SetProjectsCfg
            IsProjectsCfgEmpty = 1

        # check the Set Project Cfg if all shared projects are in the config and add it if not
        if (self.CheckSetProjectCfg(IsProjectsCfgEmpty, MasterConfig)):
            self.Log("Info", "Diff found, please setup your master config file %s" % (Masterfile))
            if os.path.isfile(Masterfile) == False:
                self.Log("Error", "Config file %s does not exist" % Masterfile)
                return 0

            # File is read-only, so make it writeable
            os.chmod(Masterfile, stat.S_IWRITE)

            try:
                file_object = open(Masterfile, "w")
            except:
                self.Log("Error", "could not open masterfile: %s for writing" % (Masterfile))
                return 0
            # get the modified xml file string
            XMLstr = MasterConfig.toxml()
            # replace all new lines and all three blanks
            XMLstr1 = XMLstr.replace('\n', '')
            UpdatedMasterConfig = xml.dom.minidom.parseString(XMLstr1.replace('   ', ''))
            # write the new cfg xml file
            UpdatedMasterConfig.writexml(file_object, "   ", "   ", "\n", "UTF-8")

            file_object.close()
            return 0
        else:
            # if the config is ok
            return 1

    def GetRevisionForConfig(self, ConfigNumber, Label, DevPathName, ConfigType, SharedPath, BaseProject,
                             use_database=False):
        ###########
        #
        # GetRevisionForConfig(ConfigNumber)
        #
        # Description: Get the config type and devpath and revesion for actual configuration
        #
        # Parameter: -ConfigNumber see below
        #
        #                       |                        <-  requ config ->                                |
        # available in cfg file |        normal          |        variant         |        build           |
        #     (ConfigNumber)    |          N             |           V            |          B             |
        # --------------------------------------------------------------------------------------------------
        # 1   | - | - | B |     | B  | B label not found | B  | B label not found | B  | B label not found |
        #                       |    | E_not_Found ret 0 |    | E_not_Found ret 0 |    | E_not_Found ret 0 |
        # --------------------------------------------------------------------------------------------------
        # 2   | - | V | - |     | V  | V label not found | V  | V label not found | V  | V label not found |
        #                       |    | E_not_Found ret 0 |    | E_not_Found ret 0 |    | E_not_Found ret 0 |
        # --------------------------------------------------------------------------------------------------
        # 3   | - | V | B |     | V  | V label not found | V  | V label not found | B  | B label not found |
        #                       |    | B found |B nfound |    | B found |B nfound |    | V found |V nfound |
        #                       |    |    B    |E_not_Fo |    |    B    |E_not_Fo |    |    V    |E_not_Fo |
        # --------------------------------------------------------------------------------------------------
        # 4   | N | - | - |     |          N             |           N            |          N             |
        # --------------------------------------------------------------------------------------------------
        # 5   | N | - | B |     |          N             |           N            | B  | B label not found |
        #                       |                        |                        |    |    E_not_found    |
        # --------------------------------------------------------------------------------------------------
        # 6   | N | V | - |     |          N             | V  | V label not found | V  | V label not found |
        #                       |                        |    |      N            |    |     N             |
        # --------------------------------------------------------------------------------------------------
        # 7   | N | V | B |     |          N             | V  | V label not found | B  | B label not found |
        #                       |                        |    |      N            |    | V found |V nfound |
        #                       |                        |    |                   |    |    V    |   N     |
        # --------------------------------------------------------------------------------------------------
        #
        # return 0 in case of error
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = {}
        BuildLabelFound = False
        DevPathLabelFound = False
        BuildRevision = 0
        DevPathRevision = 0
        self.Log("List", "ConfigType=%s ConfigNumber=%s" % (ConfigType, ConfigNumber))
        # check for build Label
        if ((ConfigNumber == 1) or (ConfigNumber == 3) or (ConfigNumber == 5) or (ConfigNumber == 7)):
            if (len(Label) > 0):
                # print Label
                if (ConfigType == "CustomV2"):
                    # check if label is part of custom config V2
                    # print SharedPath
                    # print self.SharedProjectLabelsDevPathInfo[SharedPath]["Build"]
                    BuildRevision = self.GetRevisionForLabel(SharedPath, Label)
                    if (BuildRevision == 0):
                        BuildLabelFound = False
                    else:
                        BuildLabelFound = True
                else:
                    # find revision for Build label and Shard sub project source path
                    if use_database == False:
                        BuildRevision = self.GetRevisionForLabel(SharedPath, Label)
                        if (BuildRevision == 0):
                            BuildLabelFound = False
                        else:
                            BuildLabelFound = True
                    else:
                        BuildRevision = self.mks_config_db.GetLabelRev(SharedPath, Label)
                        if (BuildRevision == None):
                            BuildLabelFound = False
                        else:
                            BuildLabelFound = True

        # print "Build Revision %s for label %s"%(BuildRevision,Label)

        # check for DevPathLabel
        if ((ConfigNumber == 2) or (ConfigNumber == 3) or (ConfigNumber == 6) or (ConfigNumber == 7)):
            if (len(DevPathName) > 0):
                # print DevPathName
                if (ConfigType == "CustomV2"):
                    # check if devpathname is part of custom config V2
                    if DevPathName in self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"]:
                        DevPathRevision = self.SharedProjectLabelsDevPathInfo[SharedPath]["DevPath"][DevPathName]
                        if (DevPathRevision == 0):
                            DevPathLabelFound = False
                        else:
                            DevPathLabelFound = True
                    elif (DevPathRevision == 0):
                        DevPathLabelFound = False
                else:
                    # find revision for Devpath and Shard sub project source path
                    if use_database == False:
                        DevPathRevision = self.CheckDevPathName(SharedPath, DevPathName)
                        if (DevPathRevision == 0):
                            DevPathLabelFound = False
                        else:
                            DevPathLabelFound = True
                    else:
                        DevPathRevision = self.mks_config_db.GetDevPathRev(SharedPath, DevPathName)
                        if DevPathRevision == None:
                            DevPathLabelFound = False
                        else:
                            DevPathLabelFound = True

                            # print "DevPathRevision %s for DevPathName %s"%(DevPathRevision, DevPathName)

        if ((ConfigNumber == 1) and ((self.Type == "normal") or (self.Type == "variant") or (self.Type == "build"))):
            if (BuildLabelFound == False):
                self.Log("Error", "Error Build label %s not found, project %s not configured" % (Label, BaseProject))
            else:
                ret_value["type"] = "build"
                ret_value["revision"] = BuildRevision
        elif ((ConfigNumber == 2) and ((self.Type == "normal") or (self.Type == "variant") or (self.Type == "build"))):
            if (DevPathLabelFound == False):
                self.Log("Error",
                         "Error Variant label %s not found, project %s not configured" % (DevPathName, BaseProject))
            else:
                ret_value["type"] = "variant"
                ret_value["revision"] = DevPathRevision
        elif (ConfigNumber == 3):
            if ((self.Type == "normal") or (self.Type == "variant")):
                if (DevPathLabelFound == False):
                    if (BuildLabelFound == False):
                        self.Log("Error", "Error Build %s and Variant label %s not found, project %s not configured" % (
                            Label, DevPathName, BaseProject))
                    else:
                        ret_value["type"] = "build"
                        ret_value["revision"] = BuildRevision
                else:
                    ret_value["type"] = "variant"
                    ret_value["revision"] = DevPathRevision
            elif (self.Type == "build"):
                if (BuildLabelFound == False):
                    if (DevPathLabelFound == False):
                        self.Log("Error", "Error Build %s and Variant label %s not found, project %s not configured" % (
                            Label, DevPathName, BaseProject))
                    else:
                        ret_value["type"] = "variant"
                        ret_value["revision"] = DevPathRevision
                else:
                    ret_value["type"] = "build"
                    ret_value["revision"] = BuildRevision
        elif ((ConfigNumber == 4) and ((self.Type == "normal") or (self.Type == "variant") or (self.Type == "build"))):
            ret_value["type"] = "normal"
        elif (ConfigNumber == 5):
            if (self.Type == "normal"):
                ret_value["type"] = "normal"
            elif (self.Type == "variant"):
                ret_value["type"] = "normal"
            elif (self.Type == "build"):
                if (BuildLabelFound == False):
                    self.Log("Error",
                             "Error Build label %s not found, project %s not configured" % (Label, BaseProject))
                else:
                    ret_value["type"] = "build"
                    ret_value["revision"] = BuildRevision
        elif (ConfigNumber == 6):
            if (self.Type == "normal"):
                ret_value["type"] = "normal"
            elif ((self.Type == "variant") or (self.Type == "build")):
                if (DevPathLabelFound == False):
                    self.Log("Error",
                             "Error Variant label %s not found, project %s not configured" % (DevPathName, BaseProject))
                else:
                    ret_value["type"] = "variant"
                    ret_value["revision"] = DevPathRevision
        elif (ConfigNumber == 7):
            if (self.Type == "normal"):
                ret_value["type"] = "normal"
            elif (self.Type == "variant"):
                if (DevPathLabelFound == False):
                    ret_value["type"] = "normal"
                else:
                    ret_value["type"] = "variant"
                    ret_value["revision"] = DevPathRevision
            elif (self.Type == "build"):
                if (BuildLabelFound == False):
                    if (DevPathLabelFound == False):
                        ret_value["type"] = "normal"
                    else:
                        ret_value["type"] = "variant"
                        ret_value["revision"] = DevPathRevision
                else:
                    ret_value["type"] = "build"
                    ret_value["revision"] = BuildRevision

        return ret_value

    def AddConfigurationToDB(self, run_id, ConfigType, Config_type, CompName, Label, DevPathName, newRevNumber,
                             source_path, target_path, late_commit=False):
        ###########
        #
        # AddConfigurationToDB()
        #
        # Description: Adds the configuration to the database
        #
        # Parameter: -run_id
        #            -ConfigType
        #            -Config_type
        #            -CompName
        #            -Label
        #            -DevPathName
        #            -newRevNumber
        #            -source_path
        #            -target_path
        #
        # Return     the config map id or None
        #
        # TODO: add parameter check
        #
        ###########
        if len(ConfigType) == 0:
            if Config_type == self.mks_config_db.CFG_TYPE_BASE:
                cfg_type = self.mks_config_db.CFG_TYPE_BASE
            if Config_type == self.mks_config_db.CFG_TYPE_CUSTOM_V1:
                cfg_type = self.mks_config_db.CFG_TYPE_CUSTOM_V1
            if Config_type == self.mks_config_db.CFG_TYPE_CUSTOM_V2:
                cfg_type = self.mks_config_db.CFG_TYPE_CUSTOM_V2
            if Config_type == self.mks_config_db.CFG_TYPE_CUSTOM_V3:
                cfg_type = self.mks_config_db.CFG_TYPE_CUSTOM_V3
        else:
            cfg_type = self.mks_config_db.CFG_TYPE_CUSTOM_V2

        if "revision" in newRevNumber:
            h_revision = newRevNumber["revision"].strip('\n')
        else:
            h_revision = None

        # TODO: cfg_type must initiated befor usage
        share_cfg_id = self.mks_config_db.GetShareCfgId(run_id, cfg_type, CompName, newRevNumber["type"], Label,
                                                        DevPathName)
        history_record = self.mks_config_db.GetHistoryId(source_path, h_revision)
        if history_record != None:
            history_id = history_record[self.mks_config_db.COL_NAME_HS_HISTORY_ID]
        else:
            self.Log("Info", "No history found for path %s with revision %s" % (source_path, h_revision))
            return None

        return self.mks_config_db.AddShareCfgMap(run_id, share_cfg_id, history_id, source_path, target_path,
                                                 late_commit)

    def ConfigureSharedProjects(self, Config, Config_type):
        ###########
        #
        # ConfigureSharedProjects(Host, Config, Config_type)
        #
        # Description: Check if the shared project is in the SharedProjectConfig.
        #              If is in the config set it to the config if not already configured
        #
        # Parameter: -Config this the config xml
        #            -Config_type is base or custom
        #
        # return 0 if config was successful and errCnt if configuration fails
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Revision = ""
        Label = ""
        DevPathName = ""
        ConfigNumber = 0
        # count errors of ConfigureSharedSubproject()
        errCnt = 0
        # copy for removing the components in Dict for Base config
        TempPreConfigSharedProjectDict = copy.deepcopy(self.PreConfigSharedProjectDict)
        # if Config_type is base, remove all paths that will be configured by CustomV3
        if Config_type == 'Base':
            CustomConfigV3 = self.SetProjectsCfg.getElementsByTagName('CustomConfigV3').item(0)
            if CustomConfigV3 != None:
                for customV3Item in CustomConfigV3.childNodes:
                    if customV3Item.nodeType == customV3Item.ELEMENT_NODE:
                        path = customV3Item.getAttribute('Path')
                        if TempPreConfigSharedProjectDict.has_key(path):
                            del TempPreConfigSharedProjectDict[path]

        # Try "AmountTryConfigure" times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later occur
        AmountTryConfigure = 10
        # Delay between tries
        DelaySeconds = 1

        # One run for ProjectShareCompName
        if (self.ProjectShareCompName != "" and Config_type == "Base"):
            # init for IsBaseConfigAlreadyInCustomV2
            self.Log("List", "Config_type=%s - init for IsBaseConfigAlreadyInCustomV2" % (Config_type))
            self.CostomV2ListFilledFlag = 0

            # check if ProjectShareCompName Normal or Branche
            if (self.ActDevPath != ""):
                DevPathName = self.ActDevPath
                ConfigNumber = ConfigNumber | 0x2
            # Normal
            elif (self.ActDevPath == ""):
                ConfigNumber = ConfigNumber | 0x4

            self.Log("Info", "CompName: " + self.ProjectShareCompName)
            # find the CompName from shared_project_config.xml in pre_config_shared_project.xml and configure that
            self.Log("List",
                     "find the CompName from shared_project_config.xml in pre_config_shared_project.xml and configure that")
            SharedProjectConfigs = self.SharedProjects.getElementsByTagName("SharedProjectConfig")
            for SharedProjectConfig in SharedProjectConfigs:
                for SharedProjectPath in SharedProjectConfig.childNodes:
                    # print SharedProjectPath.nodeName
                    if (SharedProjectPath.nodeType == SharedProjectPath.ELEMENT_NODE):
                        if (
                                        SharedProjectPath.nodeName == "SharedProjectLocation" and self.IsBaseConfigAlreadyInCustomV2(
                                        SharedProjectPath.getAttribute("SharedPath"),
                                        self.SharedProjectLabelsDevPathInfo) == 0):
                            IsSharedProjectInConfig = self.CheckSharedProjectCompName(SharedProjectConfig,
                                                                                      SharedProjectPath,
                                                                                      self.ProjectShareCompName, Label,
                                                                                      DevPathName, Config_type)
                            if (IsSharedProjectInConfig >= 1):
                                BaseProject = SharedProjectConfig.getAttribute("Path")
                                ConfigType = ""
                                if (IsSharedProjectInConfig == 2):
                                    ConfigType = "CustomV2"
                                    # get revision number for build config and validate config, find alternativ if configuration is not possible
                                newRevNumber = self.GetRevisionForConfig(ConfigNumber, Label, DevPathName, ConfigType,
                                                                         SharedProjectPath.getAttribute("SharedPath"),
                                                                         BaseProject)

                                # configure the project in mks if the conifig could be found and validated
                                if (len(newRevNumber) != 0):
                                    if (newRevNumber["type"] == "build" and ("revision" in newRevNumber)):
                                        Revision = newRevNumber["revision"]

                                    IsSharedProjectAlreadyConfigured = (
                                        self.IsSharedProjectAlreadyConfigured(BaseProject, self.ActDevPath,
                                                                              newRevNumber["type"], Revision,
                                                                              DevPathName))
                                    if (IsSharedProjectAlreadyConfigured == "0"):
                                        self.Log("Error",
                                                 "Function: IsSharedProjectAlreadyConfigured() return error Project %s will be configured with type %s" % (
                                                     BaseProject, self.Type))

                                        # Try "AmountTryConfigure" times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later
                                        count = 0
                                        retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                      newRevNumber["type"], Revision,
                                                                                      DevPathName)
                                        while (retConfigure == 2 and count < AmountTryConfigure):
                                            retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                          newRevNumber["type"],
                                                                                          Revision, DevPathName)
                                            count += 1
                                            time.sleep(DelaySeconds)
                                        # If configuration sucsessful change the PreConfigSharedProjectDict for custom configuration
                                        if (retConfigure == 0):
                                            self.Log("Info", "1:BaseProject=%s" % (BaseProject))
                                            if self.dryrun:
                                                self.Log("List", "Label pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Label"], Label))
                                                self.Log("List", "Revision pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Revision"], Revision))
                                                self.Log("List", "Type pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Type"],
                                                    newRevNumber["type"]))

                                            if newRevNumber["type"] == "variant":
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = DevPathName
                                            else:
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = Label
                                            self.PreConfigSharedProjectDict[BaseProject]["Revision"] = Revision
                                            self.PreConfigSharedProjectDict[BaseProject]["Type"] = newRevNumber["type"]
                                        else:
                                            self.Log("Error", "1:Project %s could not be configured with type %s" % (
                                                BaseProject, self.Type))
                                            errCnt += 1

                                    elif (IsSharedProjectAlreadyConfigured != True):
                                        # Try 10 times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later
                                        count = 0
                                        retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                      newRevNumber["type"], Revision,
                                                                                      DevPathName)
                                        while (retConfigure == 2 and count < AmountTryConfigure):
                                            retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                          newRevNumber["type"],
                                                                                          Revision, DevPathName)
                                            count += 1
                                            time.sleep(DelaySeconds)
                                        # If configuration sucsessful change the PreConfigSharedProjectDict for custom configuration
                                        if (retConfigure == 0):
                                            self.Log("Info", "2:BaseProject=%s" % (BaseProject))
                                            if self.dryrun:
                                                self.Log("List", "Label pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Label"], Label))
                                                self.Log("List", "Revision pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Revision"], Revision))
                                                self.Log("List", "Type pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Type"],
                                                    newRevNumber["type"]))

                                            if newRevNumber["type"] == "variant":
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = DevPathName
                                            else:
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = Label
                                            self.PreConfigSharedProjectDict[BaseProject]["Revision"] = Revision
                                            self.PreConfigSharedProjectDict[BaseProject]["Type"] = newRevNumber["type"]
                                        else:
                                            self.Log("Error", "2:Project %s could not be configured with type %s" % (
                                                BaseProject, self.Type))
                                            errCnt += 1
                                    if self.UseDatabase == True:
                                        # Add config to db
                                        if self.AddConfigurationToDB(self.run_id, ConfigType, Config_type,
                                                                     self.ProjectShareCompName, Label, DevPathName,
                                                                     newRevNumber,
                                                                     SharedProjectPath.getAttribute("SharedPath"),
                                                                     BaseProject, True) == None:
                                            self.Log("Error", "Could not add config to db config map table")

                                else:
                                    self.Log("Error", "3:Project %s could not be onfigured with type %s" % (
                                        BaseProject, self.Type))
                                    errCnt += 1

        for SharedProject in Config.childNodes:
            if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                configs = SharedProject.childNodes
                Revision = ""
                Label = ""
                DevPathName = ""
                ConfigNumber = 0
                ConfigureToLableFromDevPath = SharedProject.getAttribute("DevPathName")
                if len(ConfigureToLableFromDevPath) == 0:
                    print "\n" + "CompName: " + SharedProject.getAttribute("CompName")
                else:
                    print "\n" + "CompName: " + SharedProject.getAttribute(
                            "CompName") + " with Devpath: " + ConfigureToLableFromDevPath

                # read the CompName_config from shared_project_config.xml
                for config in configs:
                    if (config.nodeType == config.ELEMENT_NODE):
                        configType = config.getAttribute("Type")
                        if (configType == "build"):
                            Label = config.getAttribute("Label")
                            # if the build label name is empty the build configuration is invalid
                            if (len(Label) != 0):
                                ConfigNumber = ConfigNumber | 0x1  # binary or for seting the flag of configuration v | n | b
                        elif (configType == "variant"):
                            DevPathName = config.getAttribute("DevPathName")
                            # if the dev path name is empty the variant configuration is invalid
                            if (len(DevPathName) != 0):
                                ConfigNumber = ConfigNumber | 0x2
                        elif (configType == "normal"):
                            ConfigNumber = ConfigNumber | 0x4

                # check for BaseConfic is the Component allready configured
                self.Log("List", "Configcheck for BaseConfic if the Component already configured: Config_type=%s" % (
                    Config_type))
                if (Config_type == "Base"):
                    CompName = SharedProject.getAttribute("CompName")
                    ToConfigureDict = {}
                    AllConfigureDict = {}
                    i = 0
                    while i < len(TempPreConfigSharedProjectDict):
                        TempDict = {}
                        KeyDict = TempPreConfigSharedProjectDict.keys()[i]
                        TempDict[KeyDict] = {}
                        TempDict[KeyDict] = TempPreConfigSharedProjectDict[KeyDict]
                        if (CompName == TempDict[KeyDict]["CompName"]):
                            if (self.Type == "build"):
                                if not (Label == TempDict[KeyDict]["Label"] and TempDict[KeyDict]["Type"] == "build"):
                                    ToConfigureDict.update(TempDict)
                                AllConfigureDict.update(TempDict)
                            elif (self.Type == "variant"):
                                if not (DevPathName == TempDict[KeyDict]["Label"] and TempDict[KeyDict][
                                    "Type"] == "variant"):
                                    ToConfigureDict.update(TempDict)
                                AllConfigureDict.update(TempDict)
                            elif (self.Type == "normal"):
                                if (TempDict[KeyDict]["Type"] != "normal"):
                                    ToConfigureDict.update(TempDict)
                                AllConfigureDict.update(TempDict)
                            # del i Dict for speed up in next search
                            TempPreConfigSharedProjectDict.pop(KeyDict)
                        else:
                            i += 1
                    temp_rev_dict = {}
                    if (len(ToConfigureDict) > 0):
                        for ProjectPath in ToConfigureDict:
                            # only if the configuration will not be done in CustonV2
                            if (self.IsBaseConfigAlreadyInCustomV2(ToConfigureDict[ProjectPath]["SharedPath"],
                                                                   self.SharedProjectLabelsDevPathInfo) == 0):
                                BaseProject = ProjectPath
                                ConfigType = ""
                                # get revision number for build config and validate config, find alternativ if configuration is not possible
                                newRevNumber = self.GetRevisionForConfig(ConfigNumber, Label, DevPathName, ConfigType,
                                                                         ToConfigureDict[ProjectPath]["SharedPath"],
                                                                         BaseProject)
                                temp_rev_dict[ProjectPath] = newRevNumber

                                # configure the project in mks if the conifig could be found and validated
                                if (len(newRevNumber) != 0):
                                    if (newRevNumber["type"] == "build" and ("revision" in newRevNumber)):
                                        Revision = newRevNumber["revision"]

                                    IsSharedProjectAlreadyConfigured = (
                                        self.IsSharedProjectAlreadyConfigured(BaseProject, self.ActDevPath,
                                                                              newRevNumber["type"], Revision,
                                                                              DevPathName))
                                    if (IsSharedProjectAlreadyConfigured == "0"):
                                        self.Log("Error",
                                                 "Function: IsSharedProjectAlreadyConfigured() returned an error Project %s will be configured with type %s" % (
                                                     BaseProject, self.Type))

                                        # Try "AmountTryConfigure" times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later
                                        count = 0
                                        retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                      newRevNumber["type"], Revision,
                                                                                      DevPathName)
                                        while (retConfigure == 2 and count < AmountTryConfigure):
                                            retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                          newRevNumber["type"],
                                                                                          Revision, DevPathName)
                                            count += 1
                                            time.sleep(DelaySeconds)
                                        # If configuration sucsessful change the PreConfigSharedProjectDict for custom configuration
                                        if (retConfigure == 0):
                                            self.Log("Info", "3:BaseProject=%s" % (BaseProject))
                                            if self.dryrun:
                                                self.Log("List", "Label pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Label"], Label))
                                                self.Log("List", "Revision pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Revision"], Revision))
                                                self.Log("List", "Type pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Type"],
                                                    newRevNumber["type"]))

                                            if newRevNumber["type"] == "variant":
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = DevPathName
                                            else:
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = Label
                                            self.PreConfigSharedProjectDict[BaseProject]["Revision"] = Revision
                                            self.PreConfigSharedProjectDict[BaseProject]["Type"] = newRevNumber["type"]
                                        else:
                                            self.Log("Error", "4:Project %s could not be configured with type %s" % (
                                                BaseProject, self.Type))
                                            errCnt += 1

                                    elif (IsSharedProjectAlreadyConfigured != True):
                                        # Try 10 times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later
                                        count = 0
                                        retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                      newRevNumber["type"], Revision,
                                                                                      DevPathName)
                                        while (retConfigure == 2 and count < AmountTryConfigure):
                                            retConfigure = self.ConfigureSharedSubproject(BaseProject, self.ActDevPath,
                                                                                          newRevNumber["type"],
                                                                                          Revision, DevPathName)
                                            count += 1
                                            time.sleep(DelaySeconds)
                                        # If configuration sucsessful change the PreConfigSharedProjectDict for custom configuration
                                        if (retConfigure == 0):
                                            self.Log("Info", "4:BaseProject=%s" % (BaseProject))
                                            if self.dryrun:
                                                self.Log("List", "Label pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Label"], Label))
                                                self.Log("List", "Revision pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Revision"], Revision))
                                                self.Log("List", "Type pre=%s new=%s" % (
                                                    self.PreConfigSharedProjectDict[BaseProject]["Type"],
                                                    newRevNumber["type"]))

                                            if newRevNumber["type"] == "variant":
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = DevPathName
                                            else:
                                                self.PreConfigSharedProjectDict[BaseProject]["Label"] = Label
                                            self.PreConfigSharedProjectDict[BaseProject]["Revision"] = Revision
                                            self.PreConfigSharedProjectDict[BaseProject]["Type"] = newRevNumber["type"]
                                            self.ChangedConfigSharedProjectDict[BaseProject] = \
                                                self.PreConfigSharedProjectDict[BaseProject]
                                        else:
                                            self.Log("Error", "5:Project %s could not be configured with type %s" % (
                                                BaseProject, self.Type))
                                            errCnt += 1

                                else:
                                    self.Log("Error", "6:Project %s could not be configured with type %s" % (
                                        BaseProject, self.Type))
                                    errCnt += 1

                    else:
                        self.Log("List", "EMPTY Dict: len(ToConfigureDict)=%s" % (len(ToConfigureDict)))
                    if self.UseDatabase == True:
                        # add all the base configs to the database
                        if (len(AllConfigureDict) > 0):
                            for ProjectPath in AllConfigureDict:
                                ConfigType = ""
                                if ProjectPath in temp_rev_dict:
                                    newRevNumber = temp_rev_dict[ProjectPath]
                                else:
                                    # get revision number for build config and validate config, find alternativ if configuration is not possible, use the local database instead of mks
                                    newRevNumber = self.GetRevisionForConfig(ConfigNumber, Label, DevPathName,
                                                                             ConfigType, AllConfigureDict[ProjectPath][
                                                                                 "SharedPath"], ProjectPath, True)

                                # if rev number found add it to the database
                                if (len(newRevNumber) != 0):
                                    if self.AddConfigurationToDB(self.run_id, ConfigType, Config_type, CompName, Label,
                                                                 DevPathName, newRevNumber,
                                                                 AllConfigureDict[ProjectPath]["SharedPath"],
                                                                 ProjectPath, True) == None:
                                        self.Log("Error", "Could not add config to db config map table")

                # print Revision
                # print Label
                # print DevPathName
                else:
                    # find the CompName from shared_project_config.xml in pre_config_shared_project.xml and configure that
                    self.Log("List",
                             "find the CompName from shared_project_config.xml in pre_config_shared_project.xml and configure that: Config_type=%s" % (
                                 Config_type))
                    SharedProjectConfigs = self.SharedProjects.getElementsByTagName("SharedProjectConfig")
                    for SharedProjectConfig in SharedProjectConfigs:
                        for SharedProjectPath in SharedProjectConfig.childNodes:
                            # print SharedProjectPath.nodeName
                            if (SharedProjectPath.nodeType == SharedProjectPath.ELEMENT_NODE):
                                if (SharedProjectPath.nodeName == "SharedProjectLocation"):
                                    IsSharedProjectInConfig = self.CheckSharedProjectCompName(SharedProjectConfig,
                                                                                              SharedProjectPath,
                                                                                              SharedProject, Label,
                                                                                              DevPathName, Config_type)
                                    if (IsSharedProjectInConfig >= 1):
                                        BaseProject = SharedProjectConfig.getAttribute("Path")
                                        ConfigType = ""
                                        if (IsSharedProjectInConfig == 2):
                                            ConfigType = "CustomV2"
                                        # get revision number for build config and validate config, find alternativ if configuration is not possible
                                        newRevNumber = self.GetRevisionForConfig(ConfigNumber, Label, DevPathName,
                                                                                 ConfigType,
                                                                                 SharedProjectPath.getAttribute(
                                                                                         "SharedPath"), BaseProject)

                                        pre_label = self.PreConfigSharedProjectDict[BaseProject]["Label"]
                                        check_sharedpath = SharedProjectPath.getAttribute("SharedPath")
                                        check_DevPathName = None
                                        for path in self.SharedProjectLabelsDevPathInfo[check_sharedpath]["DevPaths"]:
                                            if pre_label in \
                                                    self.SharedProjectLabelsDevPathInfo[check_sharedpath]["DevPaths"][
                                                        path]:
                                                check_DevPathName = path
                                        skip_config = False
                                        if len(
                                                ConfigureToLableFromDevPath) > 0 and check_DevPathName != ConfigureToLableFromDevPath:
                                            skip_config = True

                                        if skip_config == False:
                                            # configure the project in mks if the conifig could be found and validated
                                            if (len(newRevNumber) != 0):
                                                if (newRevNumber["type"] == "build" and ("revision" in newRevNumber)):
                                                    Revision = newRevNumber["revision"]

                                                IsSharedProjectAlreadyConfigured = (
                                                    self.IsSharedProjectAlreadyConfigured(BaseProject, self.ActDevPath,
                                                                                          newRevNumber["type"],
                                                                                          Revision,
                                                                                          DevPathName))
                                                if (IsSharedProjectAlreadyConfigured == "0"):
                                                    self.Log("Error",
                                                             "Function: IsSharedProjectAlreadyConfigured() returned an error Project %s will be configured with type %s" % (
                                                                 BaseProject, self.Type))
                                                    # Try 10 times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later
                                                    count = 0
                                                    retConfigure = self.ConfigureSharedSubproject(BaseProject,
                                                                                                  self.ActDevPath,
                                                                                                  newRevNumber["type"],
                                                                                                  Revision, DevPathName)
                                                    while (retConfigure == 2 and count < AmountTryConfigure):
                                                        retConfigure = self.ConfigureSharedSubproject(BaseProject,
                                                                                                      self.ActDevPath,
                                                                                                      newRevNumber[
                                                                                                          "type"],
                                                                                                      Revision,
                                                                                                      DevPathName)
                                                        count += 1
                                                        time.sleep(DelaySeconds)
                                                    # If configuration sucsessful change the PreConfigSharedProjectDict for custom configuration
                                                    if (retConfigure == 0):
                                                        self.Log("Info", "5:BaseProject=%s" % (BaseProject))
                                                        if self.dryrun:
                                                            self.Log("List", "Label pre=%s new=%s" % (
                                                                self.PreConfigSharedProjectDict[BaseProject]["Label"],
                                                                Label))
                                                            self.Log("List", "Revision pre=%s new=%s" % (
                                                                self.PreConfigSharedProjectDict[BaseProject][
                                                                    "Revision"],
                                                                Revision))
                                                            self.Log("List", "Type pre=%s new=%s" % (
                                                                self.PreConfigSharedProjectDict[BaseProject]["Type"],
                                                                newRevNumber["type"]))
                                                        if newRevNumber["type"] == "variant":
                                                            self.PreConfigSharedProjectDict[BaseProject][
                                                                "Label"] = DevPathName
                                                        else:
                                                            self.PreConfigSharedProjectDict[BaseProject][
                                                                "Label"] = Label
                                                        self.PreConfigSharedProjectDict[BaseProject][
                                                            "Revision"] = Revision
                                                        self.PreConfigSharedProjectDict[BaseProject]["Type"] = \
                                                            newRevNumber["type"]
                                                    else:
                                                        self.Log("Error",
                                                                 "7:Project %s could not be configured with type %s" % (
                                                                     BaseProject, self.Type))
                                                        errCnt += 1

                                                elif (IsSharedProjectAlreadyConfigured != True):
                                                    # Try 10 times if MKS Error accour MKS125209: The project is currently being changed by another user. Please try again later
                                                    count = 0
                                                    retConfigure = self.ConfigureSharedSubproject(BaseProject,
                                                                                                  self.ActDevPath,
                                                                                                  newRevNumber["type"],
                                                                                                  Revision, DevPathName)
                                                    while (retConfigure == 2 and count < AmountTryConfigure):
                                                        retConfigure = self.ConfigureSharedSubproject(BaseProject,
                                                                                                      self.ActDevPath,
                                                                                                      newRevNumber[
                                                                                                          "type"],
                                                                                                      Revision,
                                                                                                      DevPathName)
                                                        count += 1
                                                        time.sleep(DelaySeconds)
                                                    # If configuration sucsessful change the PreConfigSharedProjectDict for custom configuration
                                                    if (retConfigure == 0):
                                                        self.Log("Info", "6:BaseProject=%s" % (BaseProject))
                                                        if self.dryrun:
                                                            self.Log("List", "Label pre=%s new=%s" % (
                                                                self.PreConfigSharedProjectDict[BaseProject]["Label"],
                                                                Label))
                                                            self.Log("List", "Revision pre=%s new=%s" % (
                                                                self.PreConfigSharedProjectDict[BaseProject][
                                                                    "Revision"],
                                                                Revision))
                                                            self.Log("List", "Type pre=%s new=%s" % (
                                                                self.PreConfigSharedProjectDict[BaseProject]["Type"],
                                                                newRevNumber["type"]))
                                                        if newRevNumber["type"] == "variant":
                                                            self.PreConfigSharedProjectDict[BaseProject][
                                                                "Label"] = DevPathName
                                                        else:
                                                            self.PreConfigSharedProjectDict[BaseProject][
                                                                "Label"] = Label
                                                        self.PreConfigSharedProjectDict[BaseProject][
                                                            "Revision"] = Revision
                                                        self.PreConfigSharedProjectDict[BaseProject]["Type"] = \
                                                            newRevNumber["type"]
                                                        self.ChangedConfigSharedProjectDict[BaseProject] = \
                                                            self.PreConfigSharedProjectDict[BaseProject]

                                                    else:
                                                        self.Log("Error",
                                                                 "8:Project %s could not be configured with type %s" % (
                                                                     BaseProject, self.Type))
                                                        errCnt += 1

                                                # Add config to db
                                                if self.UseDatabase == True:
                                                    if self.AddConfigurationToDB(self.run_id, ConfigType, Config_type,
                                                                                 self.mks_config_db.COMP_NOT_KNOWN,
                                                                                 Label, DevPathName, newRevNumber,
                                                                                 SharedProjectPath.getAttribute(
                                                                                         "SharedPath"), BaseProject,
                                                                                 True) == None:
                                                        self.Log("Error", "Could not add config to db config map table")
                                            else:
                                                self.Log("Error",
                                                         "9:Project %s could not be configured with type %s" % (
                                                             BaseProject, self.Type))
                                                errCnt += 1
                                                # else:
                                                # self.Log("Error", "Project %s could not be configured, because act configured dev path %s is not equal to %s from the config xml or could not be found"%(BaseProject, check_DevPathName, check_DevPathName))
        if self.UseDatabase == True:
            # commit db changes
            self.mks_config_db.Commit()
        if (errCnt != 0):
            self.Log("Error", "ConfigureSharedSubproject ErrCnt=%s" % (errCnt))

        return errCnt

    def SetSharedProjectsToConfig(self):
        ###########
        #
        # SetSharedProjectsToConfig(self)
        #
        # Description: Set all the shared project to the configuration (base and custom) and type
        #
        # return 0 if config was successful and errCnt if configuration fails
        #
        # TODO: add parameter check
        #
        ###########
        errCnt = 0
        self.Log("Info", "___________________________________________")
        self.Log("Info", "Set shared projects to base config to type %s" % self.Type)
        BaseConfig = self.SetProjectsCfg.getElementsByTagName("BaseConfig").item(0)
        BaseConfig.normalize()
        errCnt += self.ConfigureSharedProjects(BaseConfig, "Base")

        # print self.SetProjectsCfg.toxml()
        if (self.SetProjectsCfg.getElementsByTagName("CustomConfigV2").length > 0):
            self.Log("Info", "___________________________________________")
            self.Log("Info", "Set shared projects to custom config V2 to type %s" % self.Type)
            CustomConfigV2 = self.SetProjectsCfg.getElementsByTagName("CustomConfigV2").item(0)
            CustomConfigV2.normalize()
            errCnt += self.ConfigureSharedProjects(CustomConfigV2, "CustomV2")

        if (self.SetProjectsCfg.getElementsByTagName("CustomConfig").length > 0):
            self.Log("Info", "___________________________________________")
            self.Log("Info", "Set shared projects to custom config to type %s" % self.Type)
            CustomConfig = self.SetProjectsCfg.getElementsByTagName("CustomConfig").item(0)
            CustomConfig.normalize()
            errCnt += self.ConfigureSharedProjects(CustomConfig, "Custom")

        if (self.SetProjectsCfg.getElementsByTagName("CustomConfigV3").length > 0):
            self.Log("Info", "___________________________________________")
            self.Log("Info", "Set shared projects to custom config V3 to type %s" % self.Type)
            CustomConfig = self.SetProjectsCfg.getElementsByTagName("CustomConfigV3").item(0)
            CustomConfig.normalize()
            errCnt += self.ConfigureSharedProjects(CustomConfig, "CustomV3")

        if (errCnt != 0):
            self.Log("Error", "SetSharedProjectsToConfig ErrCnt=%s" % (errCnt))

        return errCnt

    def AddConfigRunToForTypeDB(self, run_id, Configs, cfg_type):
        ###########
        #
        # AddConfigRunToForTypeDB(self, run_id, Configs, cfg_type)
        #
        # Description: Adds configs for a dedicated config type
        #
        # TODO: add parameter check
        #
        ###########
        # add config for cross share if is not in the config xml
        if (self.ProjectShareCompName != "" and cfg_type == self.mks_config_db.CFG_TYPE_BASE):
            # check if ProjectShareCompName Normal or Branche
            if (self.ActDevPath != ""):
                # TODO: None shall be replaced by __ne__
                self.mks_config_db.AddShareCfg(self.run_id, self.mks_config_db.CFG_TYPE_BASE, self.ProjectShareCompName,
                                               self.mks_config_db.CFG_SH_TYPE_VARIANT, None, self.ActDevPath, True)
            # Normal
            elif (self.ActDevPath == ""):
                # TODO: None shall be replaced by __ne__
                self.mks_config_db.AddShareCfg(self.run_id, self.mks_config_db.CFG_TYPE_BASE, self.ProjectShareCompName,
                                               self.mks_config_db.CFG_SH_TYPE_NORMAL, None, None, True)

        for SharedProject in Configs.childNodes:
            if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                configs = SharedProject.childNodes
                source_shared_path = SharedProject.getAttribute("SharedPath")
                target_shared_path = SharedProject.getAttribute("Path")
                comp_name = SharedProject.getAttribute("CompName")
                if len(comp_name) == 0:
                    comp_name = self.mks_config_db.COMP_NOT_KNOWN
                if len(source_shared_path) == 0:
                    source_shared_path = None
                if len(target_shared_path) == 0:
                    target_shared_path = None
                for config in configs:
                    if (config.nodeType == config.ELEMENT_NODE):
                        configType = config.getAttribute("Type")
                        configLabel = config.getAttribute("Label")
                        configDevPathName = config.getAttribute("DevPathName")
                        # print configType
                        # print configLabel
                        # print configDevPathName
                        # print comp_name
                        # print "---"
                        if len(configLabel) == 0:
                            configLabel = None
                        if len(configDevPathName) == 0:
                            configDevPathName = None
                        self.mks_config_db.AddShareCfg(run_id, cfg_type, comp_name, configType, configLabel,
                                                       configDevPathName, True, source_shared_path, target_shared_path)
        # commit database
        self.mks_config_db.Commit()

    def AddConfigRunToDB(self, SetProjectsCfg, type):
        ###########
        #
        # AddConfigRunToDB(self, SetProjectsCfg)
        #
        # Description: Adds an config runn to the database and adds also the configuration to the database
        #
        # TODO: add parameter check
        #
        ###########
        # Add Config run
        self.run_id = self.mks_config_db.AddCfgRun()

        BaseConfig = self.SetProjectsCfg.getElementsByTagName("BaseConfig").item(0)
        BaseConfig.normalize()
        self.AddConfigRunToForTypeDB(self.run_id, BaseConfig, self.mks_config_db.CFG_TYPE_BASE)

        if (self.SetProjectsCfg.getElementsByTagName("CustomConfig").length > 0):
            self.Log("Info", "___________________________________________")
            self.Log("Info", "Add custom shared projects to database")
            CustomConfig = self.SetProjectsCfg.getElementsByTagName("CustomConfig").item(0)
            CustomConfig.normalize()
            self.AddConfigRunToForTypeDB(self.run_id, CustomConfig, self.mks_config_db.CFG_TYPE_CUSTOM_V1)

        if (self.SetProjectsCfg.getElementsByTagName("CustomConfigV2").length > 0):
            self.Log("Info", "___________________________________________")
            self.Log("Info", "Add customV2 shared projects to database")
            CustomConfigV2 = self.SetProjectsCfg.getElementsByTagName("CustomConfigV2").item(0)
            CustomConfigV2.normalize()
            self.AddConfigRunToForTypeDB(self.run_id, CustomConfigV2, self.mks_config_db.CFG_TYPE_CUSTOM_V2)

        if (self.SetProjectsCfg.getElementsByTagName("CustomConfigV3").length > 0):
            self.Log("Info", "___________________________________________")
            self.Log("Info", "Add customV3 shared projects to database")
            CustomConfig = self.SetProjectsCfg.getElementsByTagName("CustomConfigV3").item(0)
            CustomConfig.normalize()
            self.AddConfigRunToForTypeDB(self.run_id, CustomConfig, self.mks_config_db.CFG_TYPE_CUSTOM_V3)

            # print "end"

    def ConfigSharedSubProjects(self, argu):
        ###########
        #
        # ConfigSharedSubProjects(self,argu)
        #
        # Description: the ConfigSharedSubProjects main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # Return:         0 if ok 1 if errors occur
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog ConfigSharedSubProjects [options]
Example: python %prog ConfigSharedSubProjects -H mks-psad -P 7001 -C 33131:2 -d SMR200_SRR-BSD_G30_A1_V2 -c c:\SW\integration\Config -t normal -s D:\SW\ARS301\ -l -o c:\SW\integration\log"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-C", "--ChangePackage", dest="CpId",
                          help="changePackeageID e.g. 33131:1 (mandatory)")
        parser.add_option("-t", "--type", dest="Type",
                          help="Type(normal/variant/build) (mandatory)", metavar="normal")
        parser.add_option("-c", "--config", dest="ConfigFileName",
                          help="configuration file name (mandatory)", metavar="FILE")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-d", "--devpath", dest="ActDevPath", default="",
                          help="Development path e.g SMR200_SRR-BSD_G30_A1_V2")
        parser.add_option("-b", "--use_database", dest="UseDatabase", action="store_true", default=False,
                          help="If set the database is used to store the share history, this mode is much faster")
        parser.add_option("-x", "--exclude", dest="ExcludeDir", default=None,
                          help="File containing mks paths to exclude from configuration")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("--quiet", dest="quiet", action="store_true", default=False,
                          help="quiet(on/off), prompt for Development Path confirmation")
        # add user/password option (same as MKS si commandline)
        parser.add_option("--user", dest="User", default="",
                          help="e.g. uidx1234 (optional)")
        parser.add_option("--password", dest="Password", default="",
                          help=" e.g. x12234x (optional)")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        self.CpId = options.CpId

        # user/password is stored in the class mks_obj
        self.SetUidPw(options.User, options.Password)
        print "options.User=%s" % (options.User)
        print "options.Password=%s" % (options.Password)

        self.ConfigFileName = options.ConfigFileName
        self.Type = options.Type

        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.ActDevPath = options.ActDevPath
        self.UseDatabase = options.UseDatabase

        self.Logging = options.Logging
        self.LogDir = options.LogDir
        self.Quiet = options.quiet

        self.ExcludeFile = options.ExcludeDir

        result = 0

        # check sqlite3 dll version
        if sqlite3.sqlite_version_info[1] < 6:  # must be above 3.6.xx.xx
            self.Log("Error",
                     "Database option is deactivated bacause sqlite dll version is to old, please use our local pyton installation or update movepy to a newer checkpoint")
            self.UseDatabase = False

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            sys.exit(1)
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            sys.exit(1)
        # check change package id
        if ((self.CpId == "") or (self.CpId == None)):
            self.Log("Error", "No setup of change package id e.g. -C 33131:1 please enter it now:")
            cpid = raw_input("Your ChangePackage id:")
            if (cpid == ""):
                self.Log("Error", "No setup of change package -> exit")
                sys.exit(1)
            else:
                self.CpId = cpid
        # check type
        if (((not self.Type == "normal") and (not self.Type == "variant") and (not self.Type == "build")) or (
                    self.Type == None)):
            self.Log("Info", "Config type wrong or does not exist (use one of normal,variant or build e.g. -t normal)")
            online_type = raw_input("Setup now config type 0=normal, 1=variant, 2=build:")
            if (online_type == ""):
                self.Log("Error", "No setup of config type -> exit")
                sys.exit(1)
            else:
                if (online_type == "0"):
                    self.Type = "normal"
                else:
                    if (online_type == "1"):
                        self.Type = "variant"
                    else:
                        if (online_type == "2"):
                            self.Type = "build"
                        else:
                            self.Log("Error", "Setup wrong type in 0, 1 or 2 -> exit")
                            sys.exit(1)

        if ((self.ConfigFileName == "") or (self.ConfigFileName == None)):
            self.Log("Error", "Config file not defined (use default file name and location at input directory )")
            self.ConfigFileName = "shared_project_config.xml"

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"

        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit(1)

        self.Sandbox = "%s\project.pj" % (self.Sandbox)
        self.Project = "%s/project.pj" % (self.Project)

        # get Development Path from project.pj
        if ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "project"):
            self.Log("Error", "No Development path is setup  e.g -d SMR200_SRR-BSD_G30_A1_V2")
            sys.exit(1)
        elif ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "sandbox"):
            self.ActDevPath = self.GetCurrentDevPath(self.Sandbox)
            self.ActBaseProjectPath = self.GetProjectPath(self.ProjectType, self.Sandbox)
            if (self.ActDevPath == "0"):
                self.Log("Error", " in GetCurrentDevPath, Development Path not found ")
                sys.exit(1)
            else:
                if (self.ActDevPath == ""):  # Normal
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Sandbox is Normal / Trunk")
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    if (self.Quiet != True):
                        input = raw_input("Attention is this correct? [y/n]: ")
                else:
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Development path is: " + self.ActDevPath)
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    if (self.Quiet != True):
                        input = raw_input("Attention is this development path correct? [y/n]: ")
                if (self.Quiet != True):
                    # TODO: input must initiated befor usage
                    input = self.ynInputCheck(input, 100)
                    if input != "0":
                        if (input == "n" or input == "N"):
                            self.Log("Error", "Wrong sandbox -> exit")
                            sys.exit(1)
                    else:
                        self.Log("Error", "Input was not y or n -> exit")
                        sys.exit(1)

        PreConfigFileName = "%s\pre_config_shared_projects.xml" % (self.LogDir)
        PostConfigFileName = "%s\post_config_shared_projects.xml" % (self.LogDir)

        # backup old config files if exist
        OldFilePath = PreConfigFileName
        if (os.path.isfile(OldFilePath) == True):
            if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                self.Log("Error", "RenameFileAndAddDateTime fails")
        OldFilePath = PostConfigFileName
        if (os.path.isfile(OldFilePath) == True):
            if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                self.Log("Error", "RenameFileAndAddDateTime fails")

        start_time = datetime.now()

        if self.UseDatabase == True:
            self.mks_config_db = MksConfigDB_obj(options.Sandbox, self.Destination, self.LogType, self.log_file_object)
            self.mks_config_db.CheckDBTabels()

        # Create actual shared project xml
        result, rescanned_pathes = self.CreateSharedProjectXML(PreConfigFileName, True, True)

        # Read and update shared project configuration

        if (self.ReadAndUpdateConfig() != 0):
            if self.UseDatabase == True:
                # add config to db
                self.AddConfigRunToDB(self.SetProjectsCfg, self.Type)
                new_rescan_pathes = self.mks_config_db.GetAllSharesChangedToLastConfig()
                self.RescanSharedPathList(new_rescan_pathes, rescanned_pathes)
            # set shared project to the config
            # SharedProjects = get_a_document('MKSSharedProjectCfg.xml')
            temp_result = self.SetSharedProjectsToConfig()
            self.CreateSharedProjectXMLfromFile(PostConfigFileName, PreConfigFileName)
            if (temp_result > 0):
                result = 1
            else:
                # self.CreateSharedProjectXML(PostConfigFileName, False)
                self.Log("Info", "Configuration successful")
        else:
            # an error occurs
            self.Log("Info",
                     "Shared project config file(s) updated or invalid -> please check/setup the config file(s)")
            result = 1

        stop_time = datetime.now()
        self.Log("Info", "Skript runtime %s" % (str(stop_time - start_time)))

        return result

    def GetPreConfigSharesProjects(self, argu):
        ###########
        #
        # GetPreConfigSharesProjects(self,argu)
        #
        # Description: the GetPreConfigSharesProjects main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # Return:         0 if ok 1 if errors occur
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog GetPreConfigSharesProjects [options]
Example: python %prog GetPreConfigSharesProjects -H mks-psad -P 7001 -C 33131:2 -d SMR200_SRR-BSD_G30_A1_V2 -c c:\SW\integration\Config -t normal -s D:\SW\ARS301\ -l -o c:\SW\integration\log"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-t", "--type", dest="Type",
                          help="Type(normal/variant/build) (mandatory)", metavar="normal")
        parser.add_option("-c", "--config", dest="ConfigFileName",
                          help="configuration file name (mandatory)", metavar="FILE")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-d", "--devpath", dest="ActDevPath", default="",
                          help="Development path e.g SMR200_SRR-BSD_G30_A1_V2")
        parser.add_option("-b", "--use_database", dest="UseDatabase", action="store_true", default=False,
                          help="If set the database is used to store the share history, this mode is much faster")
        parser.add_option("-x", "--exclude", dest="ExcludeDir", default=None,
                          help="File containing mks paths to exclude from configuration")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("--check", dest="check", action="store_true", default=False,
                          help="check if generated SharedProjectsConfig list can be read back and is identical (default=False)")
        parser.add_option("-a", "--algodir", dest="algo_proj_dir", default="",
                          help="Breakout directory in a SW sandbox (default=none)")

        (options, args) = parser.parse_args(argu)

        # Flag (located in mks_obj) needed for dryrun of ConfigureSharedSubproject():
        # don't execute the "si configuresubproject" command on server
        self.dryrun = True

        # Flag (located in ConfigSharedSubProjets_obj) needed for recursive traversal into sharedsubprojects
        # from algo inside a SW project sandbox
        # algo_mfl420ta46, algo_mfs430bw16, algo_MFC4T0, Algo
        self.BreakOut = options.algo_proj_dir

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        # CpId (-C) option removed from commandline: insert dummy id for change package
        # needed for dryrun of ConfigureSharedSubproject()
        self.CpId = "33131:2"

        self.ConfigFileName = options.ConfigFileName
        self.Type = options.Type

        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.ActDevPath = options.ActDevPath
        self.UseDatabase = options.UseDatabase

        self.Logging = options.Logging
        self.LogDir = options.LogDir
        CheckFlag = options.check

        self.ExcludeFile = options.ExcludeDir

        result = 0

        # check sqlite3 dll version
        if sqlite3.sqlite_version_info[1] < 6:  # must be above 3.6.xx.xx
            self.Log("Error",
                     "Database option is deactivated bacause sqlite dll version is to old, please use our local pyton installation or update movepy to a newer checkpoint")
            self.UseDatabase = False

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"] = 3
            # introduced custom logging in order to analyse preConfigSharedProjects
            logTypes["List"] = 4
            # self.LogType["List"] = 4
            # remove List key: del self.LogType["List"]

            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)

        # Save the current directory and change into the source directory in order to perform a recursive scan
        oldDir = os.getcwd()
        os.chdir(options.Sandbox)

        self.Log("Info", 'Sandbox=%s' % (options.Sandbox))
        self.Log("Info", 'Project=%s' % (options.Project))
        self.Log("Info", 'ActDevPath=%s' % (options.ActDevPath))
        self.Log("Info", 'LogDir=%s' % (options.LogDir))
        self.Log("Info", 'ConfigFileName=%s' % (options.ConfigFileName))
        self.Log("Info", 'oldCWD=%s' % (oldDir))
        self.Log("Info", 'newCWD=%s' % (os.getcwd()))

        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            sys.exit(1)
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            sys.exit(1)

        # check type
        if (((not self.Type == "normal") and (not self.Type == "variant") and (not self.Type == "build")) or (
                    self.Type == None)):
            self.Log("Info", "Config type wrong or does not exist (use one of normal,variant or build e.g. -t normal)")
            online_type = raw_input("Setup now config type 0=normal, 1=variant, 2=build:")
            if (online_type == ""):
                self.Log("Error", "No setup of config type -> exit")
                sys.exit(1)
            else:
                if (online_type == "0"):
                    self.Type = "normal"
                else:
                    if (online_type == "1"):
                        self.Type = "variant"
                    else:
                        if (online_type == "2"):
                            self.Type = "build"
                        else:
                            self.Log("Error", "Setup wrong type in 0, 1 or 2 -> exit")
                            sys.exit(1)

        if ((self.ConfigFileName == "") or (self.ConfigFileName == None)):
            self.Log("Error", "Config file not defined (use default file name and location at input directory )")
            self.ConfigFileName = "shared_project_config.xml"
        else:
            if (os.path.isfile(self.ConfigFileName) == False):
                self.Log("Info", "File does not exist: %s" % (self.ConfigFileName))
                sys.exit(1)

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"

        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit(1)

        self.Sandbox = "%s\project.pj" % (self.Sandbox)
        self.Project = "%s/project.pj" % (self.Project)

        # get Development Path from project.pj
        if ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "project"):
            self.Log("Error", "No Development path is setup  e.g -d SMR200_SRR-BSD_G30_A1_V2")
            sys.exit(1)
        elif ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "sandbox"):
            self.ActDevPath = self.GetCurrentDevPath(self.Sandbox)
            self.ActBaseProjectPath = self.GetProjectPath(self.ProjectType, self.Sandbox)
            if (self.ActDevPath == "0"):
                self.Log("Error", " in GetCurrentDevPath, Development Path not found ")
                sys.exit(1)
            else:
                if (self.ActDevPath == ""):  # Normal
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Sandbox is Normal / Trunk")
                    self.Log("Info", "___________________________________________")
                    print "\n"
                else:
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Development path is: " + self.ActDevPath)
                    self.Log("Info", "___________________________________________")
                    print "\n"

        PreConfigFileName = "%s\pre_config_shared_projects.xml" % (self.LogDir)
        PostConfigFileName = "%s\post_config_shared_projects.xml" % (self.LogDir)

        test = 0  # test == 1: read the sandboxconfig from a previous generated pre_config_shared_projects.xml
        if test:
            print "CWD: %s" % (os.getcwd())
            start_time = datetime.now()
            # instead of scanning the sandbox a PreConfigFileName from former scan is used
            # seems not to work full
            self.ReadConfigSharedProjectsXML2Dict(PreConfigFileName, self.PreConfigSharedProjectDict,
                                                  ["normal", "variant", "build"])
        else:

            # backup old config files if exist
            OldFilePath = PreConfigFileName
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")
            OldFilePath = PostConfigFileName
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")

            start_time = datetime.now()

            if self.UseDatabase == True:
                self.mks_config_db = MksConfigDB_obj(options.Sandbox, self.Destination, self.LogType,
                                                     self.log_file_object)
                self.mks_config_db.CheckDBTabels()

            # test reread of mb_config_shared_projects.xml
            # mbConfigFileName = "%s\mb1_config_shared_projects.xml" % (self.LogDir)
            # self.ParseForSharedProjectfromFile(mbConfigFileName)
            # self.ReadConfigSharedProjectsXML2Dict(mbConfigFileName)

            # Create actual shared project xml
            result, rescanned_pathes = self.CreateSharedProjectXML(PreConfigFileName, True, True)

        # Read and update shared project configuration

        if ((result == 0) and (self.ReadAndUpdateConfig() != 0)):
            # self.LogType["Debug"] = 3  # switch on DEBUG out
            # if self.Logging == True:
            # self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)

            # Save original PreConfigSharedProjectDict for later comparison
            # PreConfigSharedProjectDict contains the SharedProjects as configured in the sandbox
            # next step will modify PreConfigSharedProjectDict to the configuration (base and custom) and type
            # as specified by the shared_project_config_*.xml database
            PreConfigSharedProjectDictOrig = copy.deepcopy(self.PreConfigSharedProjectDict)
            if (self.SetSharedProjectsToConfig() > 0):
                result = 1
            else:
                # self.CreateSharedProjectXMLfromFile(PostConfigFileName, PreConfigFileName)

                # write list of shared projects to xml file which will be process by mbuilder.py
                # mbConfigFileName = "%s\mb_config_shared_projects.xml" % (self.LogDir)
                # self.CreateSharedProjectXMLfromDict(mbConfigFileName, PreConfigFileName)

                # compare keys of PreConfigSharedProjectDictOrig and ChangedConfigSharedProjectDict in order
                # to find non-changed SharedProjects
                # compare key: Label
                cKey = 'Label'
                equal_config_dict = dict_equal(self.ChangedConfigSharedProjectDict, PreConfigSharedProjectDictOrig,
                                               cKey)
                for key in equal_config_dict.keys():
                    print "SharedProject-Equal Label - Key: %s - %s" % (
                        equal_config_dict[key][cKey], equal_config_dict[key])

                # remove non-changed SharedProjects from ChangedConfigSharedProjectDict
                dict_equal_del(self.ChangedConfigSharedProjectDict, PreConfigSharedProjectDictOrig, cKey)

                # write list of shared projects to xml file which will be process by mbuilder.py
                mbConfigFileName = "%s\mb_config_shared_projects.xml" % (self.LogDir)
                self.CreateSharedProjectXMLfromDict(mbConfigFileName, PreConfigFileName)

                self.Log("Info", "Configuration Updated successful")
        else:
            self.Log("Error",
                     "Shared project config file(s) updated or invalid -> please check/setup the config file(s)")
            result = 1

        stop_time = datetime.now()

        self.Log("Info", "Skript runtime %s" % (str(stop_time - start_time)))

        if CheckFlag:
            # test reread of mb_config_shared_projects.xml
            mbConfigFileName = "%s\mb_config_shared_projects.xml" % (self.LogDir)
            self.Log("Info", "Read back ChangedProjectShares: %s" % (mbConfigFileName))

            if (os.path.isfile(mbConfigFileName) == True):
                # self.ParseForSharedProjectfromFile(mbConfigFileName)
                self.ReadConfigSharedProjectsXML2Dict(mbConfigFileName, self.MbSharedProjectDict)

                res = cmp(self.MbSharedProjectDict, self.ChangedConfigSharedProjectDict)
                # print "Result=%s" % (res)
                dif = dict_diff(self.MbSharedProjectDict, self.ChangedConfigSharedProjectDict)

                # print "Dict diff:"
                # print dif

            else:
                self.Log("Info", "File does not exist: %s" % (mbConfigFileName))

        return result

    # TODO: Why does the Paramter got an assignment?
    def ReadConfigSharedProjectsXML2Dict(self, XmlFilePath, SharedProjectDict, ReadFilter_TypeList=["build"]):
        ###########
        #
        # ReadConfigSharedProjectsXML2Dict(self, XmlFilePath, SharedProjectDict, ReadFilter_TypeList=["build"])
        #
        # Description:    read the SharedProjectConfig Xml file to SharedProjectDict dictionary
        #                 Only entries of type "build" are red
        #                 This function is mainly for test purpose
        #
        # Parameter:      XmlFilePath:        XML File with the Configurations    e.g. mb:config_shared_projects.xml
        #                 SharedProjectDict
        #
        #
        # Return:         1    on error
        #                 0    on success
        #
        # Author:         Wolfgang Sinnwell 04.03.2015
        #
        # TODO: add parameter check
        #
        ###########
        result = 0
        Label = ""
        Revision = ""
        Type = ""
        CompName = ""

        try:
            SharedProjects = self.get_a_document(XmlFilePath)
        except Exception, e:
            self.Log("Info", "Config file %s could not be opened (xml parser message: %s)" % (XmlFilePath, e))
            return 1

        SharedProjects.normalize()

        SharedProjectConfigs = SharedProjects.getElementsByTagName("SharedProjectConfig")
        for SharedProjectConfig in SharedProjectConfigs:
            for SharedProjectPath in SharedProjectConfig.childNodes:
                # print SharedProjectPath.nodeName
                if (SharedProjectPath.nodeType == SharedProjectPath.ELEMENT_NODE):
                    if (SharedProjectPath.nodeName == "Label"):
                        Label = SharedProjectPath.getAttribute("Label")
                        # print Label
                    elif (SharedProjectPath.nodeName == "Revision"):
                        Revision = SharedProjectPath.getAttribute("Revision")
                        # print Revision
                    elif (SharedProjectPath.nodeName == "Type"):
                        Type = SharedProjectPath.getAttribute("Type")
                    elif (SharedProjectPath.nodeName == "SharedProjectLocation"):
                        SharedPath = SharedProjectPath.getAttribute("SharedPath")
                        # print Type
            BaseProject = SharedProjectConfig.getAttribute("Path")
            CompName = SharedProjectConfig.getAttribute("CompName")

            # TODO handle read filter by parameter

            if (Type in ReadFilter_TypeList):
                SharedProjectDict[BaseProject] = {}
                SharedProjectDict[BaseProject]["SharedPath"] = SharedPath
                SharedProjectDict[BaseProject]["CompName"] = CompName
                SharedProjectDict[BaseProject]["Label"] = Label
                SharedProjectDict[BaseProject]["Revision"] = Revision
                SharedProjectDict[BaseProject]["Type"] = Type
                self.Log("Info", "Comp=%s Label=%s SharedPath=%s" % (CompName, Label, SharedPath))
            else:
                self.Log("Info", "Comp=%s Label=%s Type=%s SKIPPED" % (CompName, Label, Type))

        return result

    def ReadConfigXMLFileDict2CompDict(self, DoclistDict, ConfigCompDict):
        ###########
        #
        # ReadConfigXMLFileDict2CompDict (self, DoclistDict, CompDict)
        #
        # Description:    read the Config from a DoclistDict (from GetConfigFileXMLDocs()) into a Comp-Label dictionary
        #
        # Parameter:      DoclistDict:   XML File with the Configurations    e.g. mb:config_shared_projects.xml
        #                 CompDict:      dictionary with CompName & Label
        #
        #
        # Return:         no return
        #
        # Author:         Wolfgang Sinnwell 04.02.2016
        #
        # TODO: add parameter check
        #
        ###########
        CompName = ""
        configLabel = ""
        configRevision = ""
        configType = ""
        cnt_comp = 0

        ConfigParts = ["BaseConfig", "CustomConfigV2", "CustomConfigV3"]
        # DoclistDict can contain a list of xml files
        for XmlFileKey in DoclistDict:
            print "XmlFileKey: %s" % (XmlFileKey)
            for cfg_part in ConfigParts:
                # print "cfg_part: %s" % (cfg_part)
                ActCfg = DoclistDict[XmlFileKey]["Config"]
                Cfg = ActCfg.getElementsByTagName(cfg_part).item(0)
                if Cfg != None:
                    Cfg.normalize()
                    # traverse XML document
                    for SharedProject in Cfg.childNodes:
                        if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                            CompName = SharedProject.getAttribute("CompName")
                            configs = SharedProject.childNodes

                            for config in configs:
                                if (config.nodeType == config.ELEMENT_NODE):
                                    configType = config.getAttribute("Type")
                                    configLabel = config.getAttribute("Label")
                                    configDevPathName = config.getAttribute("DevPathName")

                            if (CompName != ""):
                                cnt_comp += 1
                                ConfigCompDict[CompName] = {}
                                ConfigCompDict[CompName]["Label"] = configLabel
                                # TODO: configDevPathName must initiated befor usage
                                ConfigCompDict[CompName]["DevPathName"] = configDevPathName
                                # ConfigCompDict[CompName]["Revision"] = configType
                                ConfigCompDict[CompName]["Type"] = configType
                                self.Log("Info", "Comp=%s Label=%s configType=%s" % (CompName, configLabel, configType))
                            else:
                                self.Log("Info", "Comp=%s invalid" % (CompName))
        self.Log("Info", "CompCnt=%s " % (cnt_comp))
        return

    def GetCompList(self, DoclistDict, Complist, PropertyFile=""):
        ###########
        #
        # GetCompList (self, DoclistDict, Complist, PropertyFile="")
        #
        # Description:    read the SharedProjectConfig Xml file to SharedProjectDict dictionary
        #                 Only entries of type "build" are red
        #                 This function is mainly for test purpose
        #
        # Parameter:      doclistDict:    dict otherwise return a dictionary  with following structure (doclistdict)
        #                                 filename          - filename as key
        #                                 ["FileName"]      - the full file path
        #                                 ["Config"]        - the config xml dom ,
        #                                 ["Modified"]      - modified flag
        #
        #
        # Return:         no return
        #
        # Author:         Wolfgang Sinnwell 04.03.2015
        #
        # TODO: add parameter check
        #
        ###########
        CompName = ""
        ConfigParts = ["BaseConfig", "CustomConfigV2", "CustomConfigV3"]
        # init empty component list
        Complist = []
        # DoclistDict can contain a list of xml files
        for XmlFileKey in DoclistDict:
            print "XmlFileKey: %s" % (XmlFileKey)
            for cfg_part in ConfigParts:
                # print "cfg_part: %s" % (cfg_part)
                ActCfg = DoclistDict[XmlFileKey]["Config"]
                Cfg = ActCfg.getElementsByTagName(cfg_part).item(0)
                if Cfg != None:
                    Cfg.normalize()
                    # traverse XML document
                    for SharedProject in Cfg.childNodes:
                        if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                            CompName = SharedProject.getAttribute("CompName")

                            comp_exist = False
                            if CompName in Complist:
                                comp_exist = True
                            else:
                                Complist.append(CompName)

                                # print "CompName(%s)=%s  exist=%s" % (cfg_part, CompName, comp_exist)

                                # TODO handle read filter by parameter
        print sorted(Complist)
        print "len(Complist) = %s" % (len(Complist))
        # if a PropertyFile name is given then the files is generated
        # The properties file contains all parameter which is needed for a parameter mask with the
        # Jenkins Extended Choice Parameter PlugIn
        if (len(PropertyFile) > 0):
            self.Log("Info", "Write Complist as properties file: %s" % (PropertyFile))
            try:
                f = open(PropertyFile, "w")
                f.write("config_part=base,customV2,iface\n")
                f.write("config_type_all=build,variant,normal\n")
                f.write("config_type_build=build\n")
                f.write("components=")
                # generate default string which is display in pull down menu
                f.write("Select...,")
                for comp in sorted(Complist):
                    f.write(comp + ",")
                f.write("\n")
                f.close()

            except Exception, e:
                # TODO: e is an unexpected argument
                self.Log("Error", "Exception: %s", e)

    def GetConfigFileXMLDocs(self, ConfigFileName):
        ###########
        #
        # GetConfigFileXMLDocs(self)
        #
        # Description: Read the config xml file (e.g. shared_project_config_files.xml etc.)
        #              and check if it is a file list of shared sub project config files or not
        #              If it is a file list open all files and merge the files
        #
        # return None if the configuration is not ok,
        #        dict otherwise return a dictionary  with following structure (doclistdict)
        #             filename          - filename as key
        #             ["FileName"]      - the full file path
        #             ["Config"]        - the config xml dom ,
        #             ["Modified"]      - modified flag
        #             the master file xml dom config and the masterfile path
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = {}
        # dict which contains list of all config XML docs
        doclistDict = {}
        CfgPath = os.path.split(ConfigFileName)[0]
        CfgFile = os.path.split(ConfigFileName)[1]
        if os.path.isfile(ConfigFileName) == False:
            self.Log("Error", "Config file %s does not exist" % ConfigFileName)
            return None

        try:
            PrjCfg = self.get_a_document(ConfigFileName)
        except Exception, e:
            self.Log("Error", "Config file %s could not be opened (xml parser message: %s)" % (CfgFile, e))
            return None

        FileNodes = PrjCfg.getElementsByTagName("ConfigSharedProjectsFiles").item(0)
        if FileNodes == None:
            # we have only one file
            self.Log("Info", "Input config file is a shared project config file")
            doclistDict[CfgFile] = {}
            doclistDict[CfgFile]["FileName"] = ConfigFileName
            doclistDict[CfgFile]["Config"] = PrjCfg
            doclistDict[CfgFile]["Modified"] = False
            doclistDict[CfgFile]["MasterConfig"] = PrjCfg
        else:
            # it is a filelist: for each file create it own
            self.Log("Info", "Input config file is a file list of shared project config files")
            masterConfigFlag = False
            for SharedProject in FileNodes.childNodes:
                if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                    CfgFile = SharedProject.getAttribute("File")
                    ActCfgFileName = CfgPath + "\\" + CfgFile

                    if os.path.isfile(ActCfgFileName) == False:
                        self.Log("Error", "Config file %s does not exist" % ActCfgFileName)
                        ret_value = None
                        break
                    try:
                        ActPrjCfg = self.get_a_document(ActCfgFileName)
                    except Exception, e:
                        self.Log("Error",
                                 "Config file %s could not be opened (xml parser message: %s)" % (ActCfgFileName, e))
                        ret_value = None
                        break
                    # entry is only created if file exist
                    doclistDict[CfgFile] = {}
                    doclistDict[CfgFile]["FileName"] = ActCfgFileName
                    doclistDict[CfgFile]["Config"] = ActPrjCfg
                    doclistDict[CfgFile]["Modified"] = False
                    self.Log("Info", "Get shared project configurations from file %s" % ActCfgFileName)
                    # if the master type is set use this file as master
                    if (SharedProject.getAttribute("Type") == "master"):
                        doclistDict[CfgFile]["MasterConfig"] = ActPrjCfg
                    # if the type file type is not set in config file take the first entry as master file
                    if not masterConfigFlag:
                        doclistDict[CfgFile]["MasterConfig"] = ActPrjCfg
                        masterConfigFlag = True

                        # print SetProjectsCfg.toxml()
        # on error reset doclistDict
        if (ret_value == None):
            doclistDict = None
        return doclistDict

    def SaveConfigXML(self, ConfigXmlDoc, XmlFileName, BackupFlag=False):
        ###########
        #
        # SaveConfigXML(self, ConfigXmlDoc, XmlFileName, BackupFlag=False)
        #
        # Description: save the ConfigXmlDoc to a file specified by XmlFileName
        #              if BackupFlag==False an existing file is overwritten.
        #              otherwise the existing XmlFileName is renamed with DateTime and
        #              new file created
        #
        # return 1 on error otherwise return 0
        #
        # TODO: add parameter check
        #
        ###########
        if os.path.isfile(XmlFileName) == False:
            self.Log("Error", "Config file %s does not exist" % XmlFileName)
            return 1

        # Only in overwrite mode: File is read-only, so make it writeable
        if not BackupFlag:
            os.chmod(XmlFileName, stat.S_IWRITE)

        else:
            # backup old config files if exist
            OldFilePath = XmlFileName
            if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                self.Log("Error", "RenameFileAndAddDateTime fails")
            else:
                self.Log("Info", "File=%s backuped" % (XmlFileName))

        try:
            file_object = open(XmlFileName, "w")
        except:
            self.Log("Error", "could not open masterfile: %s for writing" % (XmlFileName))
            return 1
        # get the modified xml file string
        XMLstr = ConfigXmlDoc.toxml()
        # replace all new lines and all three blanks
        XMLstr1 = XMLstr.replace('\n', '')
        UpdatedConfig = xml.dom.minidom.parseString(XMLstr1.replace('   ', ''))
        # write the new cfg xml file
        UpdatedConfig.writexml(file_object, "   ", "   ", "\n", "UTF-8")

        file_object.close()
        self.Log("Info", "File=%s saved" % (XmlFileName))

        return 0

    def FindReplaceCPlabel(self, ConfigDict, Comp, CompConfigDct, setModifiedFlag=False):
        ###########
        #
        # FindReplaceCPlabel(self, ConfigDict, Comp, CompConfigDct)
        #
        # Description: scan the Configs listed in the ConfigDict (the XML doc read by GetConfigFileXMLDocs())
        #              for Comp and Labels defined in LabelDct
        #
        # ConfigDict  GetConfigFileXMLDocs
        # Comp        component name
        #
        # ConfigList  dictionary  with following structure (doclistdict)
        #             {'Component': {'Rev': '', 'Part': 'Base', 'Type': 'Base'},
        #                         Component    - Component as key
        #                         ["Part"]     - ConfigPart
        #                         ["Type"]     - ConfigType
        #                         ["Rev"]      - REvision as Label, DevPath or Revision
        #
        # ConfigDict  dict otherwise return a dictionary  with following structure
        #             filename          - filename as key
        #             ["FileName"]      - the full file path
        #             ["Config"]        - the config xml dom ,
        #             ["Modified"]      - modified flag
        #             the master file xml dom config and the masterfile path
        #
        # return 1 on error otherwise return 0
        #
        # TODO: add parameter check
        #
        ###########
        comp_matched_flag = 0
        result = 0
        master = 'shared_project_config_master.xml'
        interface = 'shared_project_config_interface.xml'
        rte = 'shared_project_config_rte.xml'
        tools = 'shared_project_config_tools.xml'
        test_tools = 'shared_project_config_test_tools.xml'

        labelType = CompConfigDct["Part"]
        cfg_type = CompConfigDct["Type"]
        Label = CompConfigDct["Rev"]

        if (Label != "") or (cfg_type == 'normal'):
            for ConfigFile in ConfigDict:
                ConfigInfos = ConfigDict[ConfigFile]
                # ConfigInfos = self.GetConfigFileList(ConfigFileName)
                CurrentFile = ConfigInfos[
                    "FileName"]  # Name of the currently being parsed config xml file e.g shared_project_config_master.xml
                # print CurrentFile
                CurrentConfig = ConfigInfos[
                    "Config"]  # Returns config tree <ConfigSharedProjects> in current config file (BaseConfig,CustomConfigV2 etc)
                self.SetProjectsCfg = CurrentConfig

                CfgNodeBase = CurrentConfig.getElementsByTagName("BaseConfig")
                CfgNodeCustom = CurrentConfig.getElementsByTagName("CustomConfigV2")

                # If label type is 'Base', only BaseConfig in each xml file is parsed,
                # If label type is 'Custom', all files except interface are parsed since component names and config type (custom) overlap in master and interface file,
                # If label type is 'Iface', all files except master file are parsed (for the same logic above)
                if labelType == 'Base':
                    if CfgNodeBase == []:
                        Cfg = None
                    else:
                        Cfg = CfgNodeBase.item(0)
                        Cfg.normalize()
                        # print Cfg

                if labelType == 'CustomV2':
                    if ConfigFile == interface or CfgNodeCustom == []:
                        Cfg = None
                    else:
                        Cfg = CfgNodeCustom.item(0)
                        Cfg.normalize()
                        # print Cfg

                if labelType == 'Iface':
                    if ConfigFile == master or CfgNodeCustom == []:
                        Cfg = None
                    else:
                        Cfg = CfgNodeCustom.item(0)
                        Cfg.normalize()
                        # print Cfg

                # Config found
                if Cfg != None:
                    for SharedProject in Cfg.childNodes:
                        if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):
                            SharedProjectCompName = SharedProject.getAttribute("CompName")
                            if SharedProjectCompName == Comp:
                                comp_matched_flag = 1
                                # print CompName
                                """
                                #Check if the label exists, if yes update Master config file
                                #------------------------------Shared Path definition to be added here------------------#
                                base_label_path = '#p=/nfs/projekte1/REPOSITORY/REPOSITORY.pj#Base_Development/05_Algorithm/'+CompName
                                if Cfg == BaseConfig:
                                  SharedPath = base_label_path
                                  LabelExist = self.GetRevisionForLabel(SharedPath, Label)
                                  Cfg = BaseConfig
                                elif Cfg == CustomConfigV2:
                                  SharedPath = base_label_path+'/04_Engineering/01_Source_Code/algo/00_Custom/'
                                  if self.GetRevisionForLabel(SharedPath, Label) == 0:
                                    SharedPath = base_label_path+'/04_Engineering/01_Source_Code/algo/00_Custom/'+CompNameInLabel.lower()
                                  #---------Exceptional logic for Wrapper, SWSUP to be added here--------------#
                                  if Label.find('SWSUP')!= -1:
                                    SharedPath = base_label_path+'/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/'+CompNameInLabel.lower()
                                  #----------------------------------------------------------------------------#
                                  LabelExist = self.GetRevisionForLabel(SharedPath, Label)
                                  Cfg = CustomConfigV2
                                #---------------------------------------------------------------------------------------#
                                #print SharedProjectCompName
                                if LabelExist != 0:
                                """
                                for SharedProjectCfg in SharedProject.childNodes:
                                    if (SharedProjectCfg.nodeType == SharedProjectCfg.ELEMENT_NODE):
                                        CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute("Label")
                                        CurrentSharedProjectCompType = SharedProjectCfg.getAttribute("Type")

                                    if (SharedProjectCfg.nodeType == SharedProjectCfg.ELEMENT_NODE):
                                        label_string_pre = ""
                                        if cfg_type == 'normal':
                                            label_string_post = ""
                                            if SharedProjectCfg.hasAttribute("Label") == True:
                                                label_string_pre = "Label"
                                                CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute("Label")
                                                SharedProjectCfg.removeAttribute("Label")
                                            if SharedProjectCfg.hasAttribute("DevPathName") == True:
                                                label_string_pre = "DevPathName"
                                                CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute(
                                                        "DevPathName")
                                                SharedProjectCfg.removeAttribute("DevPathName")

                                        elif cfg_type == 'variant':
                                            label_string_post = "DevPathName"
                                            if SharedProjectCfg.hasAttribute("Label") == True:
                                                label_string_pre = "Label"
                                                CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute("Label")
                                                SharedProjectCfg.removeAttribute("Label")
                                            elif SharedProjectCfg.hasAttribute("DevPathName") == True:
                                                label_string_pre = "DevPathName"
                                                CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute(
                                                        "DevPathName")

                                        elif cfg_type == 'build':
                                            label_string_post = "Label"
                                            if SharedProjectCfg.hasAttribute("DevPathName") == True:
                                                label_string_pre = "DevPathName"
                                                CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute(
                                                        "DevPathName")
                                                SharedProjectCfg.removeAttribute("DevPathName")
                                            elif SharedProjectCfg.hasAttribute("Label") == True:
                                                label_string_pre = "Label"
                                                CurrentSharedProjectCompLabel = SharedProjectCfg.getAttribute("Label")
                                        else:
                                            self.Log("Error",
                                                     "Wrong cfg_type %s chosen, please make sure cfg_type must be one of 'normal','variant' or 'build'" % cfg_type)
                                            result = 1
                                            break

                                        CurrentSharedProjectCompType = SharedProjectCfg.getAttribute("Type")
                                        #
                                        #
                                        #
                                        # Workaround to differentiate the repetition of TSA and SR component names in CustomConfigV2 in master xml for wrapper and swsup cp
                                        if labelType == 'CustomV2' and (
                                                        Comp[:Comp.find('_')] == 'TSA' or Comp[
                                                                                          :Comp.find('_')] == 'SR'):
                                            if (CurrentSharedProjectCompLabel.find('SWSUP') != -1 and Label.find(
                                                    'SWSUP') != -1) or (
                                                            CurrentSharedProjectCompLabel.find(
                                                                    'WRP') != -1 and Label.find(
                                                            'WRP') != -1):
                                                if cfg_type != 'normal':
                                                    SharedProjectCfg.setAttribute(label_string_post, Label)
                                                SharedProjectCfg.setAttribute("Type", cfg_type)
                                                # generate "Modified=yes" entry in the *.xml files
                                                if (setModifiedFlag == True):
                                                    SharedProjectCfg.setAttribute("Modified", "yes")
                                        else:
                                            # change the Config with Label
                                            if cfg_type != 'normal':
                                                SharedProjectCfg.setAttribute(label_string_post, Label)
                                            SharedProjectCfg.setAttribute("Type", cfg_type)
                                            # generate "Modified=yes" entry in the *.xml files
                                            if (setModifiedFlag == True):
                                                SharedProjectCfg.setAttribute("Modified", "yes")

                                        if cfg_type != 'normal':
                                            UpdatedSharedProjectCompLabel = SharedProjectCfg.getAttribute(
                                                    label_string_post)
                                        else:
                                            UpdatedSharedProjectCompLabel = "No label update, component configured to normal"
                                        UpdatedSharedProjectCompType = SharedProjectCfg.getAttribute("Type")

                                        if CurrentSharedProjectCompType == cfg_type:
                                            if CurrentSharedProjectCompLabel == UpdatedSharedProjectCompLabel:
                                                updStatus = "NOT CHANGED"
                                            else:
                                                # Label found and updated: set ModifiedFlag
                                                ConfigDict[ConfigFile]["Modified"] = True
                                                updStatus = "UPDATED"
                                        else:
                                            ConfigDict[ConfigFile]["Modified"] = True
                                            updStatus = "UPDATED"

                                        self.Log("Info", "---------------------------------------------------------")
                                        self.Log("Info", "Component=%s (%s) %s: " % (Comp, labelType, updStatus))

                                        if label_string_pre == "":
                                            self.Log("Info",
                                                     "Pre-ConfigUpdate Type=%s" % (CurrentSharedProjectCompType))
                                        else:
                                            self.Log("Info", "Pre-ConfigUpdate  %s=%s Type=%s" % (
                                                label_string_pre, CurrentSharedProjectCompLabel,
                                                CurrentSharedProjectCompType))

                                        if label_string_post == "":
                                            self.Log("Info",
                                                     "Post-ConfigUpdate Type=%s" % (UpdatedSharedProjectCompType))
                                        else:
                                            self.Log("Info", "Post-ConfigUpdate %s=%s Type=%s" % (
                                                label_string_post, UpdatedSharedProjectCompLabel,
                                                UpdatedSharedProjectCompType))

                                        self.Log("Info", "---------------------------------------------------------")
                                        # self.SaveConfigXML(CurrentConfig, CurrentFile, BackupFlag=True)

                                        # else:
                                        # print '\n'
                                        # print 'Error: The label ',Label,' for the component ',CompName,' does not exist on the given sharedpath ',SharedPath
                                        # return 0
            if comp_matched_flag == 0:
                self.Log("Error",
                         "Component name: %s labelType=%s NOT FOUND, please verify if the correct component is specified" % (
                             Comp, labelType))
                result = 1

        return result

    def ReadConfigQuadList2Dict(self, ConfigQuadList):
        ###########
        #
        # ReadConfiglist2Dict(self, ConfigQuadList, ConfigDict)
        #
        # Description:    read the ConfigQuadList into Component Config dictionary
        #
        # Parameter:      ConfigQuadList:        list of quadrupels
        #                 <comp_name>      component name
        #                 <config_part>    b[ase] | c[ustomV]2 | c[ustomV]3  | i[face]
        #                 <config_type>    b[uild] | v[ariant] | n[ormal]
        #                 <version>        <label>|<devpath>
        #
        # Return:         ConfigDict    on success
        #                 None          on error (parsing)
        #
        # Author:         Wolfgang Sinnwell 09.07.2015
        #
        # TODO: add parameter check
        #
        ###########
        ConfigPartMap = {'b':  'Base', 'base': 'Base',
                         'c2': 'CustomV2', 'customV2': 'CustomV2',
                         'c3': 'CustomV3', 'customV3': 'CustomV2',
                         'i':  'Iface', 'iface': 'Iface'}
        ConfigTypeMap = {'b': 'build', 'v': 'variant', 'n': 'normal'}
        ConfigDict = {}
        entry = 0
        for quad in ConfigQuadList:
            entry += 1
            print "Comp_quad=%s" % (quad)
            tokens = quad.split(':')
            # Make sure the quadrupel passed in contains the correct number of subparts
            # if quadrupel missed tokens[] an empty element is added for consistent processing

            if (len(tokens) == 3):
                tokens.append('')
            if (len(tokens) == 4):
                comp = tokens[0]
                part = tokens[1]
                type = tokens[2][0]
                rev = tokens[3]
                # rev : Revision, Labal or DevPath string

                # Check: ConfigPart must be base, customv2, customv3 or iface
                if part in ConfigPartMap:
                    ConfigDict[entry] = {}
                    ConfigDict[entry]["CompName"] = comp
                    ConfigDict[entry]["Part"] = ConfigPartMap[part]
                else:
                    self.Log("Error", "Invalid Quad=%s ConfigPart=%s" % (quad, part))
                    break
                # Check: ConfigType must be build, variant, normal
                if type in ConfigTypeMap:
                    ConfigDict[entry]["Type"] = ConfigTypeMap[type]
                    ConfigDict[entry]["Rev"] = rev

                else:
                    self.Log("Error", "Invalid Quad=%s ConfigType=%s" % (quad, type))
                    break
                    # no parsing error: create Comp Config entry

            elif (len(tokens) == 1):
                # empty quadrupel is valid :
                self.Log("Info", "EMPTY quad -  number of tokens=%s" % (len(tokens)))
            else:
                self.Log("Error", "Invalid number of tokens=%s" % (quad))
                ConfigDict = None
                break

        return ConfigDict

    def UpdateConfig(self, argu):
        ###########
        #
        # UpdateConfig(self,argu)
        #
        # Description: UpdateConfig  --configlist <component_quadrupel_list> [--addlist <component_quadrupel_list>] -s <sandbox> -c <config xml> -l -o <out dir> [--backup]
        #     <component_quadrupel_list>     <comp_name>:<config_part>:<config_type>:<version>[,<comp_name>:<config_part>:<config_type>:<label>|<devpath>]
        #             The configuration components of the list must exist. In order to add new components use -addlist
        #     where the parts of the quadrupels are
        #         <comp_name>      component name
        #         <config_part>    b[ase] | c[ustomV]2 | c[ustomV]3  | i[face]
        #         <config_type>    b[uild] | v[ariant] | n[ormal]
        #         <version>        <label>|<devpath>
        #
        #     -s <sandbox>            folder where sandbox is loaded
        #     -c <config xml>         shared_project_config_files.xml (containing multiple config file references) or a single
        #     -l                          logging on/off (default=False)
        #     -o <out dir>            logging output folder
        #     --backup                save the original file with timestamp before overwrite (default=False)
        #     --propfile            generate a Jenkins properties file for extended choice usage
        #
        # Description: UpdateConfig -u <comp_name> --base <Label> --custom <Label>  --iface  <Label>  --baselist <list_of_tuples> --backup
        #     -u <comp_name>      unit (component) name [not implemented: or biunique prefix (e.g. PED_)]
        #     --base <Label>      Label to be updated in the "<BaseConfig>" of shared_project_config_master.xml, shared_project_config_rte.xml,
        #                         shared_project_config_sim_bundle.xml or shared_project_config_tools.xml
        #     --custom <Label>    Label to be updated in the "<CustomConfigV2>" of shared_project_config_master.xml
        #     --iface  <Label>    Label to be updated in the "<CustomConfigV2>" of shared_project_config_interface.xml
        #     -s <sandbox>        folder where sandbox is loaded
        #     -c <config xml>     shared_project_config_files.xml (containing multiple config file references) or a single
        #     -l                  logging on/off (default=False)
        #     -o <out dir>        logging output folder
        #     --backup            save the original file with timestamp before overwrite (default=False)
        #     --baselist          List of Labels to be updated in the <BaseConfig>, form <comp>:<label>[,<comp>:<label>]
        #     Implicit interface requirements:
        #
        # Parameter:    -argu the command line options and arguments
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog UpdateConfig [options]
Example: python %prog UpdateConfig -u OFC_OpticalFlowComputation --iface AL_PFC_04.07_INTERFACE_INT-2 -c .\shared_project_config_files.xml -s D:\BuildFarmStk\MFL420TA36_210 -l -o .\log """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-c", "--config", dest="ConfigFileName",
                          help="configuration file name (mandatory)", metavar="FILE")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("--backup", dest="backup", action="store_true", default=False,
                          help="backup config xml files before overwrite(default=False)")
        parser.add_option("--configlist", dest="ConfigList", default="",
                          help="List of quadrupals to be updated in the shared_project_config_*.xml (optional), form <comp_name>:<config_part>:<config_type>:<version>")
        parser.add_option("--propfile", dest="prop_file", action="store_true", default=False,
                          help="Jenkins properties file of components (optional)(default=False)")

        (options, args) = parser.parse_args(argu)
        result = 0
        self.ConfigFileName = options.ConfigFileName
        self.Sandbox = options.Sandbox

        self.Logging = options.Logging
        self.LogDir = options.LogDir
        # backup config xml files
        BackupFlag = options.backup

        # if flag propfile=True is set a Jenkins compatible file with a list of all commponents is generated
        if (options.prop_file == True):
            # normalize path: if path = cwd then extend to abspath
            propDir = os.path.normpath(self.LogDir)
            # print "normpath=%s len=%s" % (propDir, len(propDir))
            # print "len(dirname(normpath))=%s" % (len(os.path.dirname(propDir)))
            if (len(os.path.dirname(propDir)) == 0):
                propDir = os.getcwd()
            PropFileName = os.path.join(propDir, "components.properties")
            print "PropFileName=%s" % (PropFileName)
        else:
            # disable PropFile generation
            PropFileName = ""

        ConfigQuadList = []
        if len(options.ConfigList) > 0:
            ConfigQuadList = options.ConfigList.split(',')
            print "ConfigQuadList: %s" % (ConfigQuadList)

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\updatecp.log" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\updatecp.log" % (self.LogDir), "console", logTypes)

        # Save the current directory and change into the source directory in order to perform a recursive scan
        oldDir = os.getcwd()
        os.chdir(options.Sandbox)

        self.Log("Info", 'Sandbox=%s' % (options.Sandbox))
        self.Log("Info", 'LogDir=%s' % (options.LogDir))
        self.Log("Info", 'ConfigFileName=%s' % (options.ConfigFileName))
        self.Log("Info", 'oldCWD=%s' % (oldDir))
        self.Log("Info", 'newCWD=%s' % (os.getcwd()))
        self.Log("Info", 'ConfigList=%s' % (options.ConfigList))

        if ((self.ConfigFileName == "") or (self.ConfigFileName == None)):
            self.Log("Error", "Config file not defined (use default file name and location at input directory )")
            self.ConfigFileName = "shared_project_config.xml"
        else:
            if (os.path.isfile(self.ConfigFileName) == False):
                self.Log("Info", "File does not exist: %s" % (self.ConfigFileName))
                sys.exit(1)

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.Log("Error", "No sandbox is specified e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        # check input directory
        if ((not os.path.isdir(self.Sandbox))):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        start_time = datetime.now()

        # read a set shared_project_config  xml files
        if (os.path.isfile(self.ConfigFileName) == 1):
            # load existing shared_project_config_*.xml files into a dict which holds the xml doc
            AlgoConfigDict = self.GetConfigFileXMLDocs(self.ConfigFileName)

            # because of a bug with minidom deepcopy we have to read the documents twice
            AlgoConfigDict2 = self.GetConfigFileXMLDocs(self.ConfigFileName)
            if (AlgoConfigDict != None) and (AlgoConfigDict2 != None):
                # option: generate a properties file of all components for Jenkins Extended Choice Parameter Plugin
                CompList = []
                self.GetCompList(AlgoConfigDict, CompList, PropFileName)
            else:
                result = 1

        # process QuadrupelList only if given
        ConfigListDict = None
        if (result == 0) and (len(ConfigQuadList) >= 0):
            ConfigListDict = self.ReadConfigQuadList2Dict(ConfigQuadList)
            print "configDict=%s" % (ConfigListDict)
            if (ConfigListDict == None):
                result = 1

        # ---------------------------------------------------------------------
        # FIND & REPLACE Label
        #
        # Convert the ConfigList quadrupels to a dictionary with Count as key
        # CompName:     <component name e.g. EM_EnvironmentModel>
        # ConfigType:   build | variant | normal
        # ConfigPart:   Base  | CustomV2 | CustomV3 | Iface
        # Version:      Label | DevPath
        #
        # pass Labels in a dict

        if (ConfigListDict != None):
            # first run: modify the the existing XML shared_project_config_files
            # save AlgoConfigDict for second run where the "Modified=yes" tag is added to a _mod.xml file

            # AlgoConfigDict2 = copy.deepcopy(AlgoConfigDict) DON'T WORK because of a bug in minidom

            # save xlst and css file if it does not exits
            # attention: you have to remove the files in order to get changes with new files
            self.SaveConfigXSLTAndCss(self.ConfigFileName)

            # find and replace the Component Label
            for comp in ConfigListDict:
                # TODO: AlgoConfigDict must initiated befor usage
                result |= self.FindReplaceCPlabel(AlgoConfigDict, ConfigListDict[comp]["CompName"],
                                                  ConfigListDict[comp])
            # write  ConfigInfosDict back to the XML files
            for XmlFileKey in AlgoConfigDict:
                # check if Config was modified by
                if AlgoConfigDict[XmlFileKey]["Modified"]:
                    self.Log("Info",
                             "Updated File=%s  Modified=%s" % (XmlFileKey, AlgoConfigDict[XmlFileKey]["Modified"]))
                    self.SaveConfigXML(AlgoConfigDict[XmlFileKey]["Config"], AlgoConfigDict[XmlFileKey]["FileName"],
                                       BackupFlag)

            # ---------------------------------------------------------------------
            # second run: generate _mod  XML shared_project_config_files in parallel to the existing
            print "Generate _mod.xml files..."
            for comp in ConfigListDict:
                # TODO: AlgoConfigDict2 must initiated befor usage
                result |= self.FindReplaceCPlabel(AlgoConfigDict2, ConfigListDict[comp]["CompName"],
                                                  ConfigListDict[comp], setModifiedFlag=True)

            # write  ConfigInfosDict back to the XML files
            for XmlFileKey in AlgoConfigDict2:
                # check if Config was modified by
                if AlgoConfigDict2[XmlFileKey]["Modified"]:
                    # generate _mod.xml file
                    fname, fext = os.path.splitext(AlgoConfigDict2[XmlFileKey]["FileName"])
                    fname = fname + "_mod" + fext
                    # be sure that file exist
                    open(fname, 'a').close()
                    self.Log("Info", "Updated File=%s  Modified=%s" % (fname, AlgoConfigDict2[XmlFileKey]["Modified"]))
                    self.SaveConfigXML(AlgoConfigDict2[XmlFileKey]["Config"], fname, False)

            # Example to read out ConfigInfosDict
            """
            for XmlFileKey in AlgoConfigDict:
                print "\n\nXmlFileKey=%s  Modified=%s" % (XmlFileKey, AlgoConfigDict[XmlFileKey]["Modified"])
                print "XmlFileKey=%s" % (AlgoConfigDict[XmlFileKey]["FileName"])
                PrjCFg = AlgoConfigDict[XmlFileKey]["Config"]
                print PrjCFg.toxml()
            """
            stop_time = datetime.now()

            self.Log("Info", "Skript runtime %s" % (str(stop_time - start_time)))

        return result

    def CheckPostConfig(self, argu):
        ###########
        #
        # CheckPostConfig(self,argu)
        #
        # Description: CheckPostConfig  --labellist <labell_list> --postxml <post_config xml> -l -o <out dir>
        #     <component_quadrupel_list>     <comp_name>:<config_part>:<config_type>:<version>[,<comp_name>:<config_part>:<config_type>:<label>|<devpath>]
        #             The configuration components of the list must exist. In order to add new components use -addlist
        #     where the parts of the quadrupels are
        #         <comp_name>      component name
        #         <config_part>    b[ase] | c[ustomV]2 | c[ustomV]3  | i[face]
        #         <config_type>    b[uild] | v[ariant] | n[ormal]
        #         <version>        <label>|<devpath>
        #
        #     -p <post_config xml>    List of comma separated Labels which should be found in the post_shared_project_config_*.xml (optional)
        #     -c <config xml>    shared_project_config_files.xml containing the SharedSubProject configuration of a sandbox e.g. from CreateSharedProjectXMLfromFile()
        #     -l                      logging on/off (default=False)
        #     -o <out dir>            logging output folder
        #     Implicit interface requirements:
        #
        # Parameter:    -argu the command line options and arguments
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog CheckPostConfig [options]
Example: python %prog CheckPostConfig --labellist VT_SVT_01.00.06_INT-2,AL_LD_MFC430TA16_05.12.111_INT-1,AL_VDY_MFC430TA16_03.01.04_INT-1 -c .\shared_project_config_files.xml  -l -o .\log """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("--labellist", dest="LabelList", default="",
                          help="List of comma separated Labels which should be found in the post_shared_project_config.xml (optional), form <label1>,<label2>,<label3>,...")

        parser.add_option("-c", "--config", dest="ConfigFileName",
                          help="shared_project_config_files.xml containing the SharedSubProject configuration of a sandbox (optional) which should be checked with ",
                          metavar="FILE")

        parser.add_option("-p", "--postxml", dest="PostConfigFile",
                          help="configuration file name (mandatory)", metavar="FILE")

        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        result = 1

        self.Logging = options.Logging
        self.LogDir = options.LogDir

        # check output log directory exist
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\updatecp.log" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\updatecp.log" % (self.LogDir), "console", logTypes)

        self.ConfigFileName = options.ConfigFileName
        # check that only one input parameter is provided
        if ((self.ConfigFileName == "") or (self.ConfigFileName == None)):
            if ((options.LabelList == "") or (options.LabelList == None)):
                self.Log("Error",
                         "Config file (-c, --config) or LabelList (--labellist) has to be defined as parameter")
                sys.exit(1)

        elif (options.LabelList != ""):
            self.Log("Error", "Only one parameter is allowed: Config file (-c, --config) or LabelList (--labellist)")
            sys.exit(1)

        if (options.LabelList != ""):
            result = self.CheckLabellist2PostConfig(options.LabelList, options.PostConfigFile)
        else:
            self.Log("Info", "Config file is processed: %s" % (self.ConfigFileName))
            result = self.CheckConfigXML2PostConfig(self.ConfigFileName, options.PostConfigFile)

        return result

    def CheckLabellist2PostConfig(self, LabelList, PostConfigFile):
        ###########
        #
        # ReadConfiglist2Dict(self, LabelList, PostConfigFile)
        #
        # Description:    check the labels of LabelList against PostConfigFile
        #
        # Parameter:      LabelList:       list of labels (could be empty)
        #                 PostConfigFile   file post_shared_project_config.xml, generated by ConfigSharedSubProjects
        #
        # Return:         0    on success (all labels found)
        #                 1    on error
        #
        # Author:         Wolfgang Sinnwell 03.02.2016
        #
        # TODO: add parameter check
        #
        ###########
        result = 1
        labelList = []
        PostConfigDict = {}
        cnt_found = -1

        # check if LabelList is not empty
        cnt_label = 0
        if (len(LabelList) > 0):
            # labellist found
            labelList = LabelList.split(',')
            for s in labelList:
                if (len(s) > 0):
                    cnt_label += 1

        if (cnt_label > 0):
            # list from comma seperated list
            # labelList = options.LabelList.split(',')
            self.Log("Info", "LabelList: %s" % (labelList))

            # read XML file to Dict
            # TODO: missed error handling
            self.ReadConfigSharedProjectsXML2Dict(PostConfigFile, PostConfigDict)

            # loop through the given labels - all labels must be found
            # that meams that len(labelList) == cnt_found
            cnt_found = 0
            for label in labelList:
                if (len(label) == 0):
                    # no valid LABEL string
                    continue
                # check if label exist in PostConfig
                cnt_save = cnt_found
                for XmlFileKey in PostConfigDict:
                    if PostConfigDict[XmlFileKey]["Label"] == label:
                        cnt_found += 1
                        break
                if (cnt_save == cnt_found):
                    # if the Label is missed cnt_found is not incremented
                    self.Log("Error", "Label: %s MISSED" % (label))

        else:
            # If no labellist is provided no check takes place and therefore no error shall be returned
            self.Log("Info", "NO LabelList provided: %s NOT CHECKED" % (PostConfigFile))
            result = 0
        # checking takes place
        if (cnt_label == cnt_found):
            self.Log("Info", "All LABELs are found")
            result = 0

        return result

    def CheckConfigXML2PostConfig(self, ConfigFileName, PostConfigFile):
        ###########
        #
        # ReadConfiglist2Dict(self, LabelList, PostConfigFile)
        #
        # Description:    check the labels of LabelList against PostConfigFile
        #
        # Parameter:      LabelList:       list of labels (could be empty)
        #                 PostConfigFile   file post_shared_project_config.xml, generated by ConfigSharedSubProjects
        #
        # Return:         0    on success (all labels found)
        #                 1    on error
        #
        # Author:         Wolfgang Sinnwell 03.02.2016
        #
        # TODO: add parameter check
        #
        ###########
        result = 1

        PostConfigDict = {}
        cnt_found = -1

        # check if LabelList is not empty
        cnt_label = 0

        # read a set shared_project_config  xml files
        if (os.path.isfile(self.ConfigFileName) == 1):
            # load existing shared_project_config_*.xml files into a dict which holds the xml doc

            AlgoConfigDict = self.GetConfigFileXMLDocs(self.ConfigFileName)
            ConfigCompDict = {}
            if (AlgoConfigDict != None):
                # read ConfigXML file to Dict
                self.ReadConfigXMLFileDict2CompDict(AlgoConfigDict, ConfigCompDict)
                # read PostConfigXML file to Dict
                result = self.ReadConfigSharedProjectsXML2Dict(PostConfigFile, PostConfigDict,
                                                               ReadFilter_TypeList=["build", "variant"])

            if (result == 0):
                # search for all Components of ConfigcompDict in the PostConfigDict
                # error: if not all Labels/DevPath are found
                for comp in ConfigCompDict:
                    CONFIG_LABEL = "Label"
                    if ((ConfigCompDict[comp]["Type"]) == "variant"):
                        # MasterXML format differentiate between "DevPathName" or "Label" dependend of "Type"
                        label = CONFIG_LABEL = "DevPathName"
                    label = ConfigCompDict[comp][CONFIG_LABEL]

                    # check if label exist in PostConfig
                    cnt_save = cnt_found
                    for XmlFileKey in PostConfigDict:
                        # in PostConfigXml DevpathName and Label uses same key "Label"
                        if PostConfigDict[XmlFileKey]["Label"] == label:
                            cnt_found += 1
                            break
                    if (cnt_save == cnt_found):
                        # if the Label is missed cnt_found is not incremented
                        self.Log("Error", "Component=%s Label: %s MISSED" % (comp, label))
                        result = 1

        print "RESULT=%s" % (result)
        return result


class CheckIfAllBuild_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Check if all shared project are configured to build
    #
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.Project = ""
        self.Sandbox = ""

        self.ActDevPath = ""
        self.Type = "normal"

        self.RootScanPath = ""

        self.StartingPjName = "project.pj"

        self.Logging = False
        self.LogDir = ""

        self.ExcludeFile = ""

        self.DoCheckpoint = False
        self.CheckpointLabel = ''
        self.CheckpointDescription = ''
        self.AddLabelToAllMembers = False

    def IsSharedSubSubsandboxBuild(self, SandboxPath):
        ###########
        #
        # IsSharedSubSubsandboxBuild(self,SandboxPath)
        #
        # Description:    check are all shared sub project of the sandbox build
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         Return True/False or 0 if fails and List of pathes of sub project which are not build
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        NoBuildSharesList = ""

        if (SandboxPath == "" or SandboxPath == 0):
            return 0

        # self.Log("Info", "Start getting not shared sub projects not set to build")
        # NoBuildSharesList2 = self.GetNoBuildSharedSubSandboxList(SandboxPath)
        # self.Log("Info", "Stop getting not shared sub projects not set to build")
        self.Log("Info", "Start getting not shared sub projects not set to build")
        NoBuildSharesList = self.GetNoBuildSharedSubSandboxListRec(SandboxPath)
        self.Log("Info", "Stop getting not shared sub projects not set to build")

        #        # test code
        # for path in NoBuildSharesList:
        # NoBuildSharesList2.remove(path)
        # if len(NoBuildSharesList2)> 0:
        # self.Log("Error", "Recursive and normal function are notequal")

        if (NoBuildSharesList == 1):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewsandbox command failed"
            self.Log("Error", "Could not read/extract actual type from " + SandboxPath)
            return 0
        elif (NoBuildSharesList == 2):
            return True

        # check if Internal share
        if (len(NoBuildSharesList) != 0):
            rootProjectPath = self.GetProjectPath("sandbox", SandboxPath)
            if (rootProjectPath == 0):
                return 0

            index = 0
            while index < len(NoBuildSharesList):
                retSandboxPath = NoBuildSharesList[index]

                # get SharedPath, ProjectPath
                retPathDict = self.GetRevisionSharedAndPathFromSandboxPath(retSandboxPath)
                if (retPathDict == 1):
                    print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si projectinfo command failed"
                    self.Log("Error",
                             "Could not read/extract actual Revision, ProjectPath and SheardPath from " + retSandboxPath)
                    return 0
                elif (0 in retPathDict):
                    self.Log("Error", " no ProjectPath found for " + retSandboxPath)
                    return 0
                else:
                    ProjectPath = retPathDict.keys()[0]
                    # read SharedPath
                    if (retPathDict[ProjectPath]["SharedPath"] == ""):
                        self.Log("Error", "3: no SharedPath found for projectpath: " + ProjectPath)
                        return 0
                    else:
                        retSharedPath = retPathDict[ProjectPath]["SharedPath"]

                    # If internal share or schuold Excludet then drop the entry
                    if (self.CheckIfInternalShare(rootProjectPath,
                                                  retSharedPath) == 1 or self.CheckIfPathShouldBeExcluded(ProjectPath,
                                                                                                          self.ExcludeFile) == True):
                        NoBuildSharesList.pop(index)
                    else:
                        # replase sndboxpath with projectpath
                        NoBuildSharesList[index] = ProjectPath
                        # increase index
                        index += 1

        # Return list if not empty
        lenList = len(NoBuildSharesList)
        if lenList != 0:
            return NoBuildSharesList
        else:
            return True

    def ScanForNonBuildSharedProject(self, Project, Sandbox):
        ###########
        #
        # ScanForNonBuildSharedProject(self, Project, Sandbox)
        #
        # Description: Scan all shared projects in project if one is not set to build share print error
        #
        # Parameter: -Project the mks path of the project where the scann should start
        #            -Sandbox the path of the pj file from the sandbox where the shared project scan should start
        # return 0 if all shared sub project are build, 1 if not and 2 if an error occure
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        ret_value = 0
        BuildList = ""

        if (self.ProjectType == "sandbox"):
            BuildList = self.IsSharedSubSubsandboxBuild(Sandbox)
            if (BuildList == "" or BuildList == 0):
                print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewsandbox command failed"
                self.Log("Error", "si viewsandbox command failed in IsSharedSubSubsandboxBuild")
                ret_value = 2
            elif (BuildList != True):
                index = 0
                lenList = len(BuildList)
                while index < lenList:
                    ret = BuildList[index]
                    self.Log("Info", "Shared subproject %s is not configured to build!!" % (ret))
                    index += 1

                ret_value = 1
            else:
                return 0

        elif (self.ProjectType == "project"):
            # logging.Log("Debug",project)
            cmdline = 'si viewproject --batch --hostname=%s --port=%s --project=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, Project)
            self.cliProcHandler.SiCLIHandler_wait(cmdline)
            # print os.popen(cmdline,'r').readlines()
            # stdout.seek(0)
            # self.Log("Debug",cmdline)
            for line in self.cliProcHandler.getstdout_split():
                # print stdout
                # stdout.seek(0)
                # print line
                if (len(line) > 1):
                    # (argu[1] != 'shared-subproject') and (argu[1] != 'shared-build-subproject') and (argu[1] != 'shared-variant-subproject') and (argu[1] != 'archived')
                    ret = self.GetPathOfSandboxOrProject(line, Project, Sandbox)
                    # logging.Log("Debug",ret["ret"])
                    # logging.Log("Debug","NextProject %s"%ret["project"])
                    # logging.Log("Debug","NextSandbox %s"%ret["sandbox"])

                    if (ret["ret"] != 2):
                        # if it is not a shared sub project go to the next directory
                        if (ret["ret"] == 1):
                            # go to next path directory of the project or the sandbox is no shared-subproject and no archiv
                            ret_value |= self.ScanForNonBuildSharedProject(ret["project"], ret["sandbox"])
                        else:
                            IsNotBuild = 0
                            ProjectPath = 0
                            ProjectPathSharedFrom = 0
                            if (self.ProjectType == "sandbox"):
                                if (ret["type"] != "build"):
                                    ProjectPath = self.GetProjectPath("sandbox", ret["sandbox"])
                                    ProjectPathSharedFrom = self.GetSharedFromPath("sandbox", ret["sandbox"])
                                    IsNotBuild = 1
                            elif (self.ProjectType == "project"):
                                if (ret["type"] != "build"):
                                    ProjectPath = self.GetProjectPath("project", ret["project"])
                                    ProjectPathSharedFrom = self.GetSharedFromPath("project", ret["project"])
                                    IsNotBuild = 1

                            if (IsNotBuild == 1):
                                if ((ProjectPath != 0) and (ProjectPathSharedFrom != 0)):
                                    if (self.CheckIfInternalShare(self.RootScanPath, ProjectPathSharedFrom) == 0) and (
                                                self.CheckIfPathShouldBeExcluded(ProjectPath,
                                                                                 self.ExcludeFile) == False):
                                        ret_value = 1
                                        self.Log("Info",
                                                 "Shared subproject %s is not configured to build!!" % (ProjectPath))
        # exit with the return value
        # ret_value = 0
        return ret_value

    def MakeCheckPoint(self):
        ###########
        #
        # MakeCheckPoint(self)
        #
        # Description: MakeCheckPoint checkpoints the actual project/sandbox
        #
        # return 1 if checkpoint not possible, otherwise 0
        #
        # TODO: add parameter check
        #
        ###########
        error = 0
        if (self.CheckpointLabel != ""):
            if (self.ProjectType == "sandbox"):
                Labels = {}
                # get project path of sandbox
                ProjectPath = self.GetProjectPath(self.ProjectType, self.Sandbox)
                if ProjectPath != 0:
                    # get all labels of this project
                    Labels = self.GetAllLabelsForSharedProject(ProjectPath)
                if self.CheckpointLabel not in Labels:
                    self.Log("Info", "Checkpointing sandbox %s" % (self.Sandbox))
                    # checkpointing the sandbox
                    error = self.CheckpointProject(self.ProjectType, self.Sandbox, "", self.CheckpointDescription,
                                                   self.AddLabelToAllMembers, self.CheckpointLabel)
                else:
                    self.Log("Error", "Label already exists, checkpointing of sandbox %s failed" % (self.Sandbox))
                    error = 1
                    return error
            else:
                # get all labels of this project
                # TODO: ProjectPath must initiated befor usage
                Labels = self.GetAllLabelsForSharedProject(ProjectPath)
                if self.CheckpointLabel not in Labels:
                    self.Log("Info", "Checkpointing project %s" % (self.Project))
                    # checkpointing the project
                    error = self.CheckpointProject(self.ProjectType, self.Project, self.ActDevPath,
                                                   self.CheckpointDescription, self.AddLabelToAllMembers,
                                                   self.CheckpointLabel)
                else:
                    self.Log("Error", "Label already exists, checkpointing of project %s failed" % (self.Project))
                    error = 1
                    return error
            self.Log("Info", "Checkpointing successful")
            return error

        else:
            self.Log("Info", "Please enter checkpoint description -> exit")
            error = 1
            return error

    def CheckIfAllBuild(self, argu):
        ###########
        #
        # CheckIfAllBuild(self,argu)
        #
        # Description: the CheckIfAllBuild main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # return 1 if not all shared sub projects are configured to build, otherwise 0
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog CheckIfAllBuild [options]
Example: python %prog CheckIfAllBuild -H mks-psad -P 7001 -d SMR200_SRR-BSD_G30_A1_V2 -s D:\SW\ARS301\ -l -o c:\SW\integration\log"""

        error = 0

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-d", "--devpath", dest="ActDevPath", default="",
                          help="Development path e.g SMR200_SRR-BSD_G30_A1_V2")
        parser.add_option("-x", "--exclude", dest="ExcludeDir", default=None,
                          help="File containing mtk pathes to exclude from configuration check, and from adding labels to members")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify is here, e.g ARS301.pj")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("-c", "--docheckpoint", dest="DoCheckpoint", action="store_true", default=False,
                          help="Ask for checkpointing if the test was successful (on/off)")
        parser.add_option("-n", "--checkpointlabel", dest="CheckpointLabel", default="",
                          help="Checkpointing label(name = n), if this argument is not empty you will not be asked for a label ")
        parser.add_option("-e", "--descriptionenabled", dest="DescriptionEnabled", action="store_true", default=False,
                          help="Ask for separate checkpoint description (on/off)")
        parser.add_option("-m", "--addlabeltoallmembers", dest="AddLabelToAllMembers", action="store_true",
                          default=False,
                          help="If True add checkpoint label to all the members in the checkpoint including those belonging to shared build subprojects")
        # add user/password option (same as MKS si commandline)
        parser.add_option("--user", dest="User", default="",
                          help="e.g. uidx1234 (optional)")
        parser.add_option("--password", dest="Password", default="",
                          help=" e.g. x12234x (optional)")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        # user/password is stored in the class mks_obj
        self.SetUidPw(options.User, options.Password)
        print "options.User=%s" % (options.User)
        print "options.Password=%s" % (options.Password)

        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.ActDevPath = options.ActDevPath

        self.Logging = options.Logging
        self.LogDir = options.LogDir

        self.DoCheckpoint = options.DoCheckpoint
        self.CheckpointLabel = options.CheckpointLabel
        self.DescriptionEnabled = options.DescriptionEnabled

        self.StartingPjName = options.StartPjName

        self.ExcludeFile = options.ExcludeDir
        self.AddLabelToAllMembers = options.AddLabelToAllMembers

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            error = 1
            return error
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            error = 1
            return error
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            error = 1
            return error

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            error = 1
            return error

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            error = 1
            return error

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)
        self.Project = "%s/%s" % (self.Project, self.StartingPjName)

        # get Development Path from project.pj
        if ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "project"):
            self.Log("Error", "No Development path is setup  e.g -d SMR200_SRR-BSD_G30_A1_V2")
            error = 1
            return error
        elif ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "sandbox"):
            self.ActDevPath = self.GetCurrentDevPath(self.Sandbox)
            if (self.ActDevPath == "0"):
                self.Log("Error", " in GetCurrentDevPath, Development Path not found ")
                error = 1
                return error
            else:
                if (self.ActDevPath == ""):  # Normal
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Sandbox is Normal / Trunk")
                    self.Log("Info", "___________________________________________")
                    print "\n"
                else:
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Development path is: " + self.ActDevPath)
                    self.Log("Info", "___________________________________________")
                    print "\n"

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)
        elif (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)

        if (self.RootScanPath != 0):
            retScanForNonBuildSharedProject = self.ScanForNonBuildSharedProject(self.Project, self.Sandbox)
            if (retScanForNonBuildSharedProject == 2):
                self.Log("Error", " ScanForNonBuildSharedProject() failed")
                error = 1
                return error
            elif (retScanForNonBuildSharedProject == 1):
                self.Log("Info", "Check logging, one or more shared sub project are not configured to build")
                error = 1
                return error
            else:
                self.Log("Info", "All shared sub projects are configured to build")
                if (self.DoCheckpoint == True):
                    if (self.CheckpointLabel != ""):
                        # if the checkpoint label name option argument was set use this argument/label to check point the project
                        self.CheckpointDescription = self.CheckpointLabel
                        if (self.MakeCheckPoint() == 1):
                            # if checkpointing was not possible abort the script
                            error = 1
                            return error
                        # --------------------- Optional labelling of the members in a checkpoint ---------------
                        if (
                                    self.AddLabelToAllMembers == False):  # Selected members from selected subprojects be labelled (if option -m not specified in check_for_build_and_cp.cmd)
                            self.Log("Info", "Start Labeling members, only not shared folders are labeled")
                            NotSharedSandboxProjects = self.GetNotSharedProjectsRec(self.Sandbox)
                            for SandboxToLabel in NotSharedSandboxProjects:
                                if self.CheckIfPathShouldBeExcluded(SandboxToLabel, self.ExcludeFile) == False:
                                    self.Log("Info", "Add member labels to %s" % SandboxToLabel)
                                    error = self.AddMemberLabel(self.ProjectType, SandboxToLabel, self.ActDevPath,
                                                                self.CheckpointLabel, False)
                            self.Log("Info", "Stop Labeling members, only not shared folders are labeled")
                    else:
                        # ask if the project should be checkpointed
                        checkpoint = raw_input("Should this project be Checkpointed? [y/n]:")

                        # Input control
                        checkpoint = self.ynInputCheck(checkpoint, 100)
                        if checkpoint != "0":
                            if (checkpoint == "y" or checkpoint == "Y"):
                                # propmt for the checkpoint label and description
                                if self.DescriptionEnabled:
                                    self.CheckpointLabel = raw_input("Please enter checkpoint label:")
                                    self.CheckpointDescription = raw_input("Please enter checkpoint description:")
                                else:
                                    self.CheckpointLabel = raw_input("Please enter checkpoint label/description:")
                                    self.CheckpointDescription = self.CheckpointLabel

                                if (self.MakeCheckPoint() == 1):
                                    # if checkpointing was not possible abort the script
                                    error = 1
                                    return error
                                # --------------------- Optional labelling of the members in a checkpoint ---------------
                                if (
                                            self.AddLabelToAllMembers == False):  # Selected members from selected subprojects be labelled (if option -m not specified in check_for_build_and_cp.cmd)
                                    self.Log("Info", "Start Labeling members, only not shared folders are labeled")
                                    NotSharedSandboxProjects = self.GetNotSharedProjectsRec(self.Sandbox)
                                    for SandboxToLabel in NotSharedSandboxProjects:
                                        if self.CheckIfPathShouldBeExcluded(SandboxToLabel, self.ExcludeFile) == False:
                                            self.Log("Info", "Add member labels to %s" % SandboxToLabel)
                                            error = self.AddMemberLabel(self.ProjectType, SandboxToLabel,
                                                                        self.ActDevPath, self.CheckpointLabel, False)
                                    self.Log("Info", "Stop Labeling members, only not shared folders are labeled")
                            else:
                                self.Log("Info", "Aborted -> exit")
                                error = 1
                                return error
                        else:
                            self.Log("Error", "Input was not y or n -> exit")
                            error = 1
                            return error
                else:
                    self.Log("Info", "Shared project build check finished")
        return error


class RenameAllCheckpointLabels_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Rename all checkpoint labels with an old label to an new label
    # Find it delete it and add the new label to this revision
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.Project = ""
        self.Sandbox = ""
        self.StartingPjName = "project.pj"

        self.ActDevPath = ""

        self.RootScanPath = ""

        self.Logging = False
        self.LogDir = ""

        self.OldLabel = ""
        self.NewLabel = ""

    def GoThrouProjects(self, Project, Sandbox):
        ###########
        #
        # GoThrouProjects(self, Project, Sandbox)
        #
        # Description: Go throu all projects and rename each project checkpoint
        #
        # Parameter: -Project the mks path of the project where the scann should start
        #            -Sandbox the path of the pj file from the sandbox where the shared project scan should start
        # return 0 if all shared sub project are build, 1 if not
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0
        if (self.ProjectType == "sandbox"):
            # logging.Log("Debug",Sandbox)
            cmdline = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, Sandbox)

        if (self.ProjectType == "project"):
            # logging.Log("Debug",project)
            cmdline = 'si viewproject --batch --hostname=%s --port=%s --project=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, Project)

        self.cliProcHandler.SiCLIHandler_wait(cmdline)
        # self.Log("Debug",cmdline)
        for line in self.cliProcHandler.getstdout_split():
            # print line
            if (len(line) > 1):
                # (argu[1] != 'shared-subproject') and (argu[1] != 'shared-build-subproject') and (argu[1] != 'shared-variant-subproject') and (argu[1] != 'archived')
                ret = self.GetPathOfSandboxOrProject(line, Project, Sandbox)
                # logging.Log("Debug",ret["ret"])
                # logging.Log("Debug","NextProject %s"%ret["project"])
                # logging.Log("Debug","NextSandbox %s"%ret["sandbox"])

                if (ret["ret"] != 2):
                    # if it is not a shared sub project go to the next directory
                    if (ret["ret"] == 1):
                        # go to next path directory of the project or the sandbox is no shared-subproject and no archiv
                        ret_value |= self.GoThrouProjects(ret["project"], ret["sandbox"])

                        if (self.ProjectType == "sandbox"):
                            ProjectPathSharedFrom = self.GetProjectPath("sandbox", ret["sandbox"])
                            if (ProjectPathSharedFrom != 0):
                                if (self.RenameCheckpoint(ProjectPathSharedFrom, self.OldLabel, self.NewLabel) != 0):
                                    self.Log("Error", "Could not rename project %s with OldLabel %s to NewLabel %s" % (
                                        Project, self.OldLabel, self.NewLabel))
                            else:
                                self.Log("Error", "MKS path not found for sandbox %s" % (Sandbox))
                        if (self.ProjectType == "project"):
                            ProjectPathSharedFrom = self.GetProjectPath("project", ret["project"])
                            if (ProjectPathSharedFrom != 0):
                                if (self.RenameCheckpoint(ProjectPathSharedFrom, self.OldLabel, self.NewLabel) != 0):
                                    self.Log("Error", "Could not rename project %s with OldLabel %s to NewLabel %s" % (
                                        Project, self.OldLabel, self.NewLabel))
                            else:
                                self.Log("Error", "MKS path not found for project %s" % (Project))

        # exit with the return value
        # ret_value = 0
        return ret_value

    def RenameAllCheckpointLabels(self, argu):
        ###########
        #
        # RenameAllCheckpointLabels(self,argu)
        #
        # Description: Rename all checkpoint labels with an old label to an new label
        #              Find it delete it and add the new label to this revision
        #
        # Parameter:    -argu the command line options and arguments
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog CheckIfAllBuild [options]
Example: python %prog RenameAllCheckpointLabels -H mks-psad -P 7001 -d SMR200_SRR-BSD_G30_A1_V2 -s D:\SW\ARS301\ -O OldLabel -N NewLabel -l -o c:\SW\integration\log """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-d", "--devpath", dest="ActDevPath", default="",
                          help="Development path e.g SMR200_SRR-BSD_G30_A1_V2")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify is here, e.g ARS301.pj")
        parser.add_option("-O", "--OldLabel", dest="OldLabel", default="",
                          help="The old label that should be removed")
        parser.add_option("-N", "--NewLabel", dest="NewLabel", default="",
                          help="The new label that should be used")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port

        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.ActDevPath = options.ActDevPath

        self.Logging = options.Logging
        self.LogDir = options.LogDir

        self.OldLabel = options.OldLabel
        self.NewLabel = options.NewLabel

        self.StartingPjName = options.StartPjName

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            sys.exit(1)
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            sys.exit(1)

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit(1)

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)
        self.Project = "%s/%s" % (self.Project, self.StartingPjName)

        # get Development Path from project.pj
        if ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "project"):
            self.Log("Error", "No Development path is setup  e.g -d SMR200_SRR-BSD_G30_A1_V2")
            sys.exit(1)
        elif ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "sandbox"):
            self.ActDevPath = self.GetCurrentDevPath(self.Sandbox)
            if (self.ActDevPath == "0"):
                self.Log("Error", " in GetCurrentDevPath, Development Path not found ")
                sys.exit(1)
            else:
                if (self.ActDevPath == ""):  # Normal
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Sandbox is Normal / Trunk")
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    input = raw_input("Attention is this correct? [y/n]: ")
                else:
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Development path is: " + self.ActDevPath)
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    input = raw_input("Attention is this development path correct? [y/n]: ")
                input = self.ynInputCheck(input, 100)
                if input != "0":
                    if (input == "n" or input == "N"):
                        self.Log("Error", "Wrong sandbox -> exit")
                        sys.exit(1)
                else:
                    self.Log("Error", "Input was not y or n -> exit")
                    sys.exit(1)

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)
        elif (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)

        if (self.RootScanPath != 0):
            if (self.GoThrouProjects(self.Project, self.Sandbox) == 1):
                self.Log("Info", "Not all labels could be renamed, check logging.txt")
                sys.exit(1)
            else:
                self.Log("Info", "Renaming finished successfully")


class AddPreIntCheckpoint_obj(ConfigSharedSubProjets_obj, CheckIfAllBuild_obj):
    ###########
    #
    # Description: Add Pre Integration Checkpoint, save act config, configure project to build,
    #              checkpoint it, restore config
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        xml_obj.__init__(self)
        mks_config_helper_obj.__init__(self)
        ConfigSharedSubProjets_obj.__init__(self)
        CheckIfAllBuild_obj.__init__(self)

        self.Project = ""
        self.Sandbox = ""

        self.ActDevPath = ""
        self.Type = "normal"

        self.Logging = False
        self.LogDir = ""

        self.RootScanPath = ""

        self.DoCheckpoint = False
        self.UseDatabase = False

        self.StartingPjName = "project.pj"

        self.RestoreTo = {}

    def ConfigureAllToBuild(self):
        ###########
        #
        # ConfigureAllToBuild(self)
        #
        # Description: Configures all shared sub projects that are not configured to build
        #
        # Parameter: -None
        # return 0 if all shared sub project are build, 1 if not
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0

        Label = ""
        Revision = ""
        Type = ""

        self.Log("Info", "___________________________________________")
        self.Log("Info", "Configure all shared sub projects to build (actual build label)")

        SharedProjectConfigs = self.SharedProjects.getElementsByTagName("SharedProjectConfig")
        for SharedProjectConfig in SharedProjectConfigs:
            for SharedProjectPath in SharedProjectConfig.childNodes:
                # print SharedProjectPath.nodeName
                if (SharedProjectPath.nodeType == SharedProjectPath.ELEMENT_NODE):
                    if (SharedProjectPath.nodeName == "Label"):
                        Label = SharedProjectPath.getAttribute("Label")
                    # print Label
                    if (SharedProjectPath.nodeName == "Revision"):
                        Revision = SharedProjectPath.getAttribute("Revision")
                    # print Revision
                    if (SharedProjectPath.nodeName == "Type"):
                        Type = SharedProjectPath.getAttribute("Type")
                        # print Type
            BaseProject = SharedProjectConfig.getAttribute("Path")
            if (Type == "variant") or (Type == "normal"):
                self.RestoreTo[BaseProject] = {}
                self.RestoreTo[BaseProject][Type] = Label
                if self.ConfigureSharedSubproject(BaseProject, self.ActDevPath, "build", Revision, "") > 0:
                    ret_value = 1
        # print self.RestoreTo
        return ret_value

    def ReadConfigSharedProjectsPreintXML2Dict(self, XmlFilePath):
        ###########
        #
        # ReadConfigSharedProjectsPreintXML2Dict(self, XmlFilePath)
        #
        # Description:    read the Xml file to self.RestoreTo dictionary
        #
        # Parameter:      XmlFilePath:    XML File with the Configurations    e.g. pre_config_shared_projects_preint.xml
        #
        # Return:         no return
        #
        # Author:         Ilja Hotjakov 15.03.2012
        #
        # TODO: add parameter check
        #
        ###########
        Label = ""
        Revision = ""
        Type = ""

        SharedProjects = self.get_a_document(XmlFilePath)
        SharedProjects.normalize()

        SharedProjectConfigs = SharedProjects.getElementsByTagName("SharedProjectConfig")
        for SharedProjectConfig in SharedProjectConfigs:
            for SharedProjectPath in SharedProjectConfig.childNodes:
                # print SharedProjectPath.nodeName
                if (SharedProjectPath.nodeType == SharedProjectPath.ELEMENT_NODE):
                    if (SharedProjectPath.nodeName == "Label"):
                        Label = SharedProjectPath.getAttribute("Label")
                    # print Label
                    elif (SharedProjectPath.nodeName == "Revision"):
                        Revision = SharedProjectPath.getAttribute("Revision")
                    # print Revision
                    elif (SharedProjectPath.nodeName == "Type"):
                        Type = SharedProjectPath.getAttribute("Type")

                        # print Type
            BaseProject = SharedProjectConfig.getAttribute("Path")
            if (Type == "variant") or (Type == "normal"):
                self.RestoreTo[BaseProject] = {}
                self.RestoreTo[BaseProject][Type] = Label

    def RestoreConfig(self):
        ###########
        #
        # RestoreConfig(self)
        #
        # Description: Restores the shares sub project config to the configuration befor preInt checkpoint
        #
        # Parameter: -None
        # return 0 if configuration was done succesfully, 1 if not
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = 0

        self.Log("Info", "Should the projects be reconfigured now?, !! if you press 'n' there is no return!!")

        # ask if the project should be reconfigured
        doReconfigure = raw_input("Should the projects be reconfigured now? [y,n]:")
        doReconfigure = self.ynInputCheck(doReconfigure, 100)
        if doReconfigure != "0":
            if (doReconfigure == "y" or doReconfigure == "Y"):
                for SharedPath in self.RestoreTo:
                    # print SharedPath
                    if "variant" in self.RestoreTo[SharedPath]:
                        DevPathName = self.RestoreTo[SharedPath]["variant"]
                        if self.ConfigureSharedSubproject(SharedPath, self.ActDevPath, "variant", "", DevPathName) != 0:
                            ret_value = 1
                    elif "normal" in self.RestoreTo[SharedPath]:
                        if self.ConfigureSharedSubproject(SharedPath, self.ActDevPath, "normal", "", "") != 0:
                            ret_value = 1
            else:
                # ask if project should not be reconfigured
                Reconfigure = raw_input("Sure? [y,n]:")
                Reconfigure = self.ynInputCheck(Reconfigure, 100)
                if Reconfigure != "0":
                    if (Reconfigure == "n" or Reconfigure == "N"):
                        for SharedPath in self.RestoreTo:
                            # print SharedPath
                            if "variant" in self.RestoreTo[SharedPath]:
                                DevPathName = self.RestoreTo[SharedPath]["variant"]
                                if self.ConfigureSharedSubproject(SharedPath, self.ActDevPath, "variant", "",
                                                                  DevPathName) != 0:
                                    ret_value = 1
                            elif "normal" in self.RestoreTo[SharedPath]:
                                if self.ConfigureSharedSubproject(SharedPath, self.ActDevPath, "normal", "", "") != 0:
                                    ret_value = 1
                else:
                    self.Log("Error", "Input was not y or n -> exit")
                    ret_value = 1
        else:
            self.Log("Error", "Input was not y or n -> exit")
            ret_value = 1

        return ret_value

    def AddPreIntCheckpoint(self, argu):
        ###########
        #
        # AddPreIntCheckpoint(self,argu)
        #
        # Description: the AddPreIntCheckpoint main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog AddPreIntCheckpoint [options]
Example: python %prog AddPreIntCheckpoint -H mks-psad -P 7001 -d SMR200_SRR-BSD_G30_A1_V2 -s D:\SW\ARS301\ -l -o c:\SW\integration\log"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-C", "--ChangePackage", dest="CpId",
                          help="changePackeageID e.g. 33131:1 (mandatory)")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-d", "--devpath", dest="ActDevPath", default="",
                          help="Development path e.g SMR200_SRR-BSD_G30_A1_V2")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify it here, e.g ARS301.pj")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("-c", "--docheckpoint", dest="DoCheckpoint", action="store_true", default=False,
                          help="Ask for checkpointing if the test was successful (on/off)")
        # add user/password option (same as MKS si commandline)
        parser.add_option("--user", dest="User", default="",
                          help="e.g. uidx1234 (optional)")
        parser.add_option("--password", dest="Password", default="",
                          help=" e.g. x12234x (optional)")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        self.CpId = options.CpId
        # user/password is stored in the class mks_obj
        self.SetUidPw(options.User, options.Password)
        print "options.User=%s" % (options.User)
        print "options.Password=%s" % (options.Password)

        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.ActDevPath = options.ActDevPath

        self.Logging = options.Logging
        self.LogDir = options.LogDir

        self.DoCheckpoint = options.DoCheckpoint

        self.StartingPjName = options.StartPjName

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            sys.exit(1)
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            sys.exit(1)
        # check change package id
        if ((self.CpId == "") or (self.CpId == None)):
            self.Log("Error", "No setup of change package id e.g. -C 33131:1 please enter it now:")
            cpid = raw_input("Your ChangePackage id:")
            if (cpid == ""):
                self.Log("Error", "No setup of change package -> exit")
                sys.exit(1)
            else:
                self.CpId = cpid

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit(1)

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)
        self.Project = "%s/%s" % (self.Project, self.StartingPjName)

        # get Development Path from project.pj
        if ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "project"):
            self.Log("Error", "No Development path is setup  e.g -d SMR200_SRR-BSD_G30_A1_V2")
            sys.exit(1)
        elif ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "sandbox"):
            self.ActDevPath = self.GetCurrentDevPath(self.Sandbox)
            if (self.ActDevPath == "0"):
                self.Log("Error", " in GetCurrentDevPath, Development Path not found ")
                sys.exit(1)
            else:
                if (self.ActDevPath == ""):  # Normal
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Sandbox is Normal / Trunk")
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    input = raw_input("Attention is this correct? [y/n]: ")
                else:
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Development path is: " + self.ActDevPath)
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    input = raw_input("Attention is this development path correct? [y/n]: ")
                input = self.ynInputCheck(input, 100)
                if input != "0":
                    if (input == "n" or input == "N"):
                        self.Log("Error", "Wrong sandbox -> exit")
                        sys.exit(1)
                else:
                    self.Log("Error", "Input was not y or n -> exit")
                    sys.exit(1)

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)
        elif (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)

        if (self.RootScanPath != 0):
            PreConfigFileNamePreInt = "%s\pre_config_shared_projects_preint.xml" % (self.LogDir)
            CPConfigFileNamePreInt = "%s\cp_config_shared_projects_preint.xml" % (self.LogDir)
            PostConfigFileNamePreInt = "%s\post_config_shared_projects_preint.xml" % (self.LogDir)

            # backup old config files if exist
            OldFilePath = PreConfigFileNamePreInt
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")
            OldFilePath = CPConfigFileNamePreInt
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")
            OldFilePath = PostConfigFileNamePreInt
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")

            # Create actual shared project xml
            self.CreateSharedProjectXML(PreConfigFileNamePreInt, False, False)
            # self.SharedProjects = self.get_a_document(PreConfigFileNamePreInt)
            # try to configure all shared sub projects to a build checkpoint
            if (self.ConfigureAllToBuild() == 0):
                # save the shared sup project config that should be checkpointed
                self.CreateSharedProjectXML(CPConfigFileNamePreInt, False, False)
                if (self.ScanForNonBuildSharedProject(self.Project, self.Sandbox) == 1):
                    self.Log("Info", "Check logging, one or more shared sub project are not configured to build")
                    # restore the shared sup project config
                    self.Log("Info", "Restoring shared project")
                    self.RestoreConfig()
                    self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
                    sys.exit(1)
                else:
                    self.Log("Info", "All shared sub projects are configured to build")
                    if (self.DoCheckpoint == True):
                        # ask if the project should be checkpointed
                        checkpoint = raw_input("Should this project be Checkpointed now? [y/n]:")

                        # Input control
                        checkpoint = self.ynInputCheck(checkpoint, 100)
                        if checkpoint != "0":
                            if (checkpoint == "y" or checkpoint == "Y"):
                                description = raw_input("Please enter checkpoint label/description:")
                                if (description != ""):
                                    if (self.ProjectType == "sandbox"):
                                        # checkpointing the sandbox
                                        LabelMembers = raw_input("Should this label added to all members? [y/n]:")
                                        LabelMembers = self.ynInputCheck(LabelMembers, 100)
                                        if LabelMembers != "0":
                                            if (LabelMembers == "y" or LabelMembers == "Y"):
                                                self.Log("Info", "Checkpointing and label members of sandbox %s" % (
                                                    self.Sandbox))
                                                error = self.CheckpointProject(self.ProjectType, self.Sandbox, "",
                                                                               description, True, description)
                                                if error == 1:
                                                    return error
                                            else:
                                                self.Log("Info", "Checkpointing sandbox %s" % (self.Sandbox))
                                                error = self.CheckpointProject(self.ProjectType, self.Sandbox, "",
                                                                               description, False, description)
                                                if error == 1:
                                                    return error
                                        else:
                                            self.Log("Error", "Input was not y or n -> exit")
                                            sys.exit(1)
                                    else:
                                        # checkpointing the project
                                        LabelMembers = raw_input("Should this label added to all members? [y/n]:")
                                        # Input control
                                        LabelMembers = self.ynInputCheck(LabelMembers, 100)
                                        if LabelMembers != "0":
                                            if (LabelMembers == "y" or LabelMembers == "Y"):
                                                self.Log("Info", "Checkpointing and label members of project %s" % (
                                                    self.Sandbox))
                                                error = self.CheckpointProject(self.ProjectType, self.Project,
                                                                               self.ActDevPath, description, True,
                                                                               description)
                                                if error == 1:
                                                    return error
                                            else:
                                                self.Log("Info", "Checkpointing sandbox %s" % (self.Sandbox))
                                                error = self.CheckpointProject(self.ProjectType, self.Project,
                                                                               self.ActDevPath, description, False,
                                                                               description)
                                                if error == 1:
                                                    return error
                                        else:
                                            self.Log("Error", "Input was not y or n -> exit")
                                            sys.exit(1)

                                    self.Log("Info", "Checkpointing successful")
                                else:
                                    self.Log("Info", "Please enter a valid checkpoint label/description -> exit")
                                    # restore the shared sup project config
                                    self.Log("Info", "Restoring shared project")
                                    self.RestoreConfig()
                                    self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
                                    sys.exit(1)
                            else:
                                self.Log("Info", "Aborted -> exit")
                                # restore the shared sup project config
                                self.Log("Info", "Restoring shared project")
                                self.RestoreConfig()
                                self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
                                sys.exit(1)
                        else:
                            self.Log("Error", "Input was not y or n -> exit")
                            # restore the shared sup project config
                            self.Log("Info", "Restoring shared project")
                            self.RestoreConfig()
                            self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
                            sys.exit(1)
                    else:
                        self.Log("Info", "Shared project build check finished")

                self.Log("Info", "Restoring shared project")
                # restore the shared sup project config
                self.RestoreConfig()
                self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
                self.Log("Info", "AddPreIntCheckpoint successful finished")
            else:
                self.Log("Info", "Configure all shared sub projects to build faild")
                self.Log("Info", "Restoring shared project")
                # restore the shared sub project config
                self.RestoreConfig()
                self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
        else:
            self.Log("Error", "Starting project name for sandbox/project not correct")
            self.Log("Info", "Aborted -> exit")

    def RestorePreIntCheckpointFromXML(self, argu):
        ###########
        #
        # RestorePreIntCheckpointFromXML(self,argu)
        #
        # Description:    If AddPreIntCheckpoint fails you can restore the old configuration from pre_config_shared_project_preint.xml
        #
        # Parameter:      -H/--Host:            Server                                                       e.g. mks-psad
        #                 -P/--Portconfig:      Port                                                         e.g. 7001
        #                 -C/--ChangePackage    Change Packeage ID                                           e.g. 33131:1
        #                 -s/--sandbox          the direcory of the sandbox which should be configured       e.g. D:\sandbox\ARS3N0_dev
        #                 -p/--project          the mks direcory of the project                              e.g. /nfs/projekte1/PROJECTS/ARS301/05_Software/project.pj
        #                 -d/--devpath          Development path only if -p/--project                        e.g. SMR200_SRR-BSD_G30_A1_V2
        #                 -S/--startPjName      If the starting project is not project.pj specify is here    e.g. ARS301.pj
        #                 -l/--log              Enable / disable logging                                     e.g. True / False
        #                 -o/--output           Logging outputfolder                                         e.g. .\
        #                 -x/--XmlPath:         Path of the XML file                                         e.g. .\pre_config_shared_project_preint.xml
        #
        # Return:         ERRORLEVEL 1 if fails
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog RestorePreIntCheckpointFromXML [options]
Example: python %prog RestorePreIntCheckpointFromXML -H mks-psad -P 7001 -s D:\sandbox\ARS3N0_dev -S ARS301.pj -x .\pre_config_shared_project_preint.xml -l -o .\ """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-C", "--ChangePackage", dest="CpId",
                          help="changePackeageID e.g. 33131:1 (mandatory)")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-d", "--devpath", dest="ActDevPath", default="",
                          help="Development path e.g SMR200_SRR-BSD_G30_A1_V2")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify it here, e.g ARS301.pj")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("-x", "--XmlPath", dest="XmlPath",
                          help="e.g. -x .\pre_config_shared_project_preint.xml")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        self.CpId = options.CpId
        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.ActDevPath = options.ActDevPath
        self.Logging = options.Logging
        self.LogDir = options.LogDir
        self.StartingPjName = options.StartPjName
        XmlPath = options.XmlPath

        path1 = os.path.join(os.getcwd(), XmlPath)

        absXmlPath = os.path.abspath(path1)

        # File existenz ueberpruefen sonst exit systhem
        if (os.path.isfile(absXmlPath) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -x/--XmlPath, " + absXmlPath + " file not exist or path is wrong"
            sys.exit(1)

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            sys.exit(1)
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            sys.exit(1)
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            sys.exit(1)
        # check change package id
        if ((self.CpId == "") or (self.CpId == None)):
            self.Log("Error", "No setup of change package id e.g. -C 33131:1 please enter it now:")
            cpid = raw_input("Your ChangePackage id:")
            if (cpid == ""):
                self.Log("Error", "No setup of change package -> exit")
                sys.exit(1)
            else:
                self.CpId = cpid

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit(1)

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit(1)

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)
        self.Project = "%s/%s" % (self.Project, self.StartingPjName)

        # get Development Path from project.pj
        if ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "project"):
            self.Log("Error", "No Development path is setup  e.g -d SMR200_SRR-BSD_G30_A1_V2")
            sys.exit(1)
        elif ((self.ActDevPath == "" or self.ActDevPath == None) and self.ProjectType == "sandbox"):
            self.ActDevPath = self.GetCurrentDevPath(self.Sandbox)
            if (self.ActDevPath == "0"):
                self.Log("Error", " in GetCurrentDevPath, Development Path not found ")
                sys.exit(1)
            else:
                if (self.ActDevPath == ""):  # Normal
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Sandbox is Normal / Trunk")
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    input = raw_input("Attention is this correct? [y/n]: ")
                else:
                    self.Log("Info", "___________________________________________")
                    self.Log("Info", "Development path is: " + self.ActDevPath)
                    self.Log("Info", "___________________________________________")
                    print "\n"
                    input = raw_input("Attention is this development path correct? [y/n]: ")
                input = self.ynInputCheck(input, 100)
                if input != "0":
                    if (input == "n" or input == "N"):
                        self.Log("Error", "Wrong sandbox -> exit")
                        sys.exit(1)
                else:
                    self.Log("Error", "Input was not y or n -> exit")
                    sys.exit(1)

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)

        elif (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)

        if (self.RootScanPath != 0):
            # backup old config files if exist
            OldFilePath = "%s\cp_config_shared_projects_preint.xml" % (self.LogDir)
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")
            OldFilePath = "%s\post_config_shared_projects_preint.xml" % (self.LogDir)
            if (os.path.isfile(OldFilePath) == True):
                if (self.RenameFileAndAddDateTime(OldFilePath) != 0):
                    self.Log("Error", "RenameFileAndAddDateTime fails")

            PostConfigFileNamePreInt = "%s\post_config_shared_projects_preint.xml" % (self.LogDir)

            self.Log("Info", "Restoring shared project")
            # restore the shared sup project config
            self.ReadConfigSharedProjectsPreintXML2Dict(absXmlPath)
            self.RestoreConfig()
            self.CreateSharedProjectXML(PostConfigFileNamePreInt, False, False)
            self.Log("Info", "Reconfiguration finished successfully")
        else:
            self.Log("Error", "Starting project name for sandbox/project is not correct")
            self.Log("Info", "Aborted -> exit")


class CheckAlgoIntegration_obj(CheckIfAllBuild_obj):
    ###########
    #
    # Description: Check Algo Integration class
    #
    ###########
    def __init__(self):
        logging_obj.__init__(self)
        CheckIfAllBuild_obj.__init__(self)

        self.ActDevPath = ""
        self.BuildConfigurations = {}
        self.ProjectList = []

        self.Destination = ""

        self.Logging = False
        self.LogDir = ""

        self.ExcludeFile = ""

    def __del__(self):
        pass

    def getFileSize(self, filename):
        return os.path.getsize(filename)

    def get_version_number(self, filename):
        ###########
        #
        # get_version_number(self,label)
        #
        # Description:    Extract the version from file.
        #
        # Parameter:      filename:    Path of the file     e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll
        #
        # Return:         Return number (e.g. 01), return "0" if fails or no version attribute exist
        #
        # TODO: add parameter check
        #
        ###########
        from win32api import GetFileVersionInfo, LOWORD, HIWORD

        try:
            info = GetFileVersionInfo(filename, "\\")
        except:
            return "0"

        ms = info['FileVersionMS']
        ls = info['FileVersionLS']

        return HIWORD(ms), LOWORD(ms), HIWORD(ls), LOWORD(ls)

    def getVersionFromLabel(self, label):
        ###########
        #
        # getVersionFromLabel(self,label)
        #
        # Description:    Extract the version from component label.
        #                 Some minimum requirements are expected:
        #                 1.    "_" is excepted at beginning             e.g. _01.02.00
        #                 2.    minimum 6 marks                          e.g. 1.2.0
        #                 3.    at least two points between the marks    e.g. 1.2.0
        #
        # Parameter:      label:    Label of the component label    e.g. AL_ALN_ARS315_11.01.01_INT-1
        #
        # Return:         Return version (e.g. 01.02.03) and "0" if minimum requirements not achieved
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        i = 0
        StrVersion = ""
        StrVersion1 = ""
        StrVersion2 = ""
        Version = ""
        FlagFirst = 0
        CountZweiPunkte = 0

        while (i < len(label) and len(label) >= 6):  # mindestens 6 zeichen sonst glaich abbruch
            if (label[i] == '_' and FlagFirst == 0):
                FlagFirst = 1
                i += 1
            elif (FlagFirst == 1):  # nur wenn erstes _ gefunden fange an zahlen zu extrahieren
                if (label[i] == '_' and label[i - 1] != '_'):  # zweites gefunden
                    if (CountZweiPunkte < 2):  # noch keine zweipunkte gefunden -> weiter sucehn
                        # FlagFirst = 0
                        StrVersion = ""
                        StrVersion1 = ""
                        StrVersion2 = ""
                        CountZweiPunkte = 0
                        i += 1
                    else:
                        break
                elif (label[i] == '_' and label[i - 1] == '_'):  # nichts machen einfach weiter '_''_'
                    i += 1
                else:
                    if (label[i] == '0' or label[i] == '1' or label[i] == '2' or label[i] == '3' or label[i] == '4' or
                                label[i] == '5' or label[i] == '6' or label[i] == '7' or label[i] == '8' or label[
                        i] == '9'):
                        if (CountZweiPunkte == 0):
                            StrVersion = StrVersion + label[i]
                        elif (CountZweiPunkte == 1):
                            StrVersion1 = StrVersion1 + label[i]
                        elif (CountZweiPunkte == 2):
                            StrVersion2 = StrVersion2 + label[i]
                        i += 1
                    elif (label[i] == '.' and CountZweiPunkte < 2):
                        CountZweiPunkte += 1
                        i += 1
                    elif (CountZweiPunkte < 2):
                        i += 1
                    else:  # CountZweiPunkte == 2 anf find somthing != nummber
                        break
            else:  # Flagfirst == 0 um forderen buchstaben zu ignorieren
                i += 1

        # return
        if (CountZweiPunkte < 2 or StrVersion == "" or StrVersion1 == "" or StrVersion2 == ""):  # ERROR
            return "0"
        else:
            Version = StrVersion + '.' + StrVersion1 + '.' + StrVersion2
            # print "Version: ", Version
            return Version

    def IsFileContentEqual(self, File1, File2):
        ###########
        #
        # IsFileContentEqual(self,File1,File2)
        #
        # Description:    check are the files same on the binary level
        #
        # Parameter:      File1:    Path of the first file     e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll
        #                 File2:    Path of the second file    e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll
        #
        # Return:         Return True/False and "0" if filenames are wrong or opening fails
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########
        if (File1 == "" or File2 == "" or File1 == 0 or File2 == 0):
            return "0"

        # Init
        NotEqual = 0

        try:
            datei1 = open(File1, "rb")
        except:
            return "0"

        try:
            datei2 = open(File2, "rb")
        except:
            return "0"

        block1 = datei1.read()
        block2 = datei2.read()

        # Aufraeumen
        datei1.close()
        datei2.close()

        # vergleichen
        if (block1 != block2):
            NotEqual = 1

        # Ausgabe
        if (NotEqual == 1):
            return False
        else:
            return True

    def IsStrVersionEqual(self, str, str1):
        ###########
        #
        # IsStrVersionEqual(self,File1,File2)
        #
        # Description:    check are the versions of files equal.Comparing the first three numbers to the last point.
        #                 Zeros before the numbers will be ignored
        #
        # Parameter:      File1:    Path of the first file     e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll
        #                 File2:    Path of the second file    e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll
        #
        # Return:         Return True/False and "0" if filenames are wrong
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########
        if (str == "" or str1 == "" or str == 0 or str1 == 0):
            return "0"

        # #Unicode to Str
        # str = str.decode('utf_8').encode('latin_1')
        # str1 = str1.decode('utf_8').encode('latin_1')

        # Init
        StrZahl = ""
        StrZahl1 = ""
        n = 0
        i = 0
        i1 = 0
        NotEqual = 0

        while n < 3:
            # read StrZahl for first String
            StrZahl = ""
            while ((i < len(str)) and (str[i] == '0' or str[i] == '1' or str[i] == '2' or str[i] == '3' or str[
                i] == '4' or str[i] == '5' or str[i] == '6' or str[i] == '7' or str[i] == '8' or str[i] == '9')):
                StrZahl = StrZahl + str[i]
                i += 1

            # read StrZahl1 for first String
            StrZahl1 = ""
            while ((i1 < len(str1)) and (str1[i1] == '0' or str1[i1] == '1' or str1[i1] == '2' or str1[i1] == '3' or
                                                 str1[i1] == '4' or str1[i1] == '5' or str1[i1] == '6' or str1[
                i1] == '7' or str1[i1] == '8' or str1[i1] == '9')):
                StrZahl1 = StrZahl1 + str1[i1]
                i1 += 1

            if (StrZahl == StrZahl1 and StrZahl1 == ""):  # wenn beide nichts dann nichts machen
                i += 1
                i1 += 1
            else:

                if (StrZahl != "") and (
                            StrZahl1 == ""):  # wenn kein gueltiger string oder ein Str ohne zahlen uebergeben wurde
                    NotEqual = 1
                elif (StrZahl == "") and (StrZahl1 != ""):
                    NotEqual = 1
                elif (StrZahl != "") and (StrZahl1 != ""):
                    # Str von vorstehenden Nullen bereinigen
                    if (int(StrZahl) != 0):  # wenn die zahl nur aus nullen bestent z.b. 1.0.0.0 dann vergleichen
                        j = 0
                        while j < len(StrZahl):
                            if StrZahl[0] == '0':
                                StrZahl = StrZahl[1:]  # loescht den ersten index
                                j += 1
                            else:
                                break
                                # print int.Parse(StrZahl1)
                    if (int(StrZahl1) != 0):
                        j = 0
                        while j < len(StrZahl1):  # wenn die zahl nur aus nullen bestent z.b. 1.0.0.0 dann vergleichen
                            if StrZahl1[0] == '0':
                                StrZahl1 = StrZahl1[1:]
                                j += 1
                            else:
                                break

                    if (int(StrZahl) != int(StrZahl1)):  # int weil wenn 00 und 0 ohen int wuerden nicht gleich sein
                        NotEqual = 1
                        break

                n += 1

        # Return
        if (NotEqual == 1):
            return False
        else:
            return True

    def IsSandboxEqualProject(self, SandboxPath):
        ###########
        #
        # IsSandboxEqualProject(self,SandboxPath)
        #
        # Description:    compare all sub projects and members in sandbox with project on server
        #
        # Parameter:      SandboxPath:    the path of the project file from the sandbox where the shared project scan should start    e.g. .\project.pj
        #
        # Return:         Return True/False and "0" if viewsandbox or viewproject call gone wrong
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########
        if (SandboxPath == "" or SandboxPath == 0):
            return "0"

        cmdline_info = 'si viewsandbox --batch --hostname=%s --port=%s --sandbox=%s --fields=type,memberarchive,memberrev --forceConfirm=yes --quiet' % (
            self.Host, self.Port, SandboxPath)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return "0"

        stdout_str, stderr_str = self.cliProcHandler.communicate()
        sandboxinfo = stdout_str
        sandboxinfo = sandboxinfo.replace("sandbox", "project")

        cmdline_info = 'si viewproject --batch --hostname=%s --port=%s --sandbox=%s --fields=type,memberarchive,memberrev --forceConfirm=yes --quiet' % (
            self.Host, self.Port, SandboxPath)

        retval = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return "0"
        stdout_str, stderr_str = self.cliProcHandler.communicate()
        projectinfo = stdout_str

        # compare sandbox with project
        if (sandboxinfo != projectinfo):  # Configuration Path:
            return False
        else:
            return True

    def CheckCurrentDevPathWithXmlPath(self, argu):
        ###########
        #
        # CheckCurrentDevPathWithXmlPath(self,argu)
        #
        # Description:    check is the development path of sandbox same as development path in xml-file (e.g. shared_project_config.xml) if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      -H/--Host:           Server                                                      e.g. mks-psad
        #                 -P/--Portconfig:     Port                                                        e.g. 7001
        #                 -x/--XmlPath:        Path of the xml-file                                        e.g. .\shared_project_config.xml
        #                 -c/--CompLabel:      Component label in xml-file where the dev. path is saved    e.g. ARS301
        #                 -p/--ProjectPath:    Path of the project file                                    e.g. .\project.pj
        #
        # Return:         ERRORLEVEL 1 if fails or the result is not same as expected
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Path1 = ""
        Path2 = ""
        filename1 = ""
        filename2 = ""
        version1 = ""
        version2 = ""
        Label = ""

        usage = """usage : %prog CheckCurrentDevPathWithXmlPath [options]
                Example: python %prog CheckCurrentDevPathWithXmlPath -H mks-psad -P 7001 -x .\shared_project_config.xml -c ARS301 -p .\project.pj"""

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-x", "--XmlPath", dest="XmlPath",
                          help="e.g. .\shared_project_config.xml")
        parser.add_option("-c", "--CompLabel", dest="CompLabel",
                          help="e.g. ARS301")
        parser.add_option("-p", "--ProjectPath", dest="ProjectPath",
                          help="e.g. .\project.pj")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        XmlPath = options.XmlPath
        CompLabelName = options.CompLabel
        ProjectPath = options.ProjectPath

        # print "ProjectPath:" , ProjectPath

        # print "Aufrufposition:", os.getcwd()
        path1 = os.path.join(os.getcwd(), XmlPath)
        # path1 = "D:\\work\\phyton\\mks_tool\\src\\shared_project_config.xml"
        path2 = os.path.join(os.getcwd(), ProjectPath)
        # path2 = "D:\\sandbox\\ARS353_04.04.00_INT\\project.pj"

        abspath1 = os.path.abspath(path1)
        abspath2 = os.path.abspath(path2)

        # Input check
        if (self.Host == ""):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Input -H/--Host, is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (self.Port.isdigit() == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -P/--Portconfig, " + self.Port + " is not a number"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        if (os.path.isfile(abspath1) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -x/--XmlPath, " + abspath1 + " file not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(abspath2) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -p/--ProjectPath, " + abspath2 + " file not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (CompLabelName == ""):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -c/--CompLabel, " + CompLabelName + " Label name is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        Label = mks_obj.GetAttributeFromXML(self, abspath1, "BaseConfig", "CompName", CompLabelName, "DevPathName")
        if (Label == None or Label == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -c/--CompLabel, " + CompLabelName + " do not exist in the XML file\n")
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        DevPath = mks_obj.GetCurrentDevPath(self, ProjectPath)
        if (DevPath == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Development Path not found, please check your MKS Settings" + '\n')
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (DevPath != Label):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Development Path " + Label + ' != ' + DevPath + ' not equal, please check the XML-File or sandbox directory' + '\n')
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

    def CheckDLLVersionP1NotSmallerP2(self, argu):
        ###########
        #
        # CheckDLLVersionP1NotSmallerP2(self,argu)
        #
        # Description:    check if file version --P1 smaller file version --P2 ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      --P1:           Path of the first file              e.g. .\sim_swc_simctrl.dll
        #                 --P2:           Path of the second file             e.g. .\sim_swc_simctrl_ref.dll
        #                 --LogFile:      Logfilename                         e.g. error.txt
        #                 -o/--output:    Path of logfile output directory    e.g. .\
        #
        # Return:         ERRORLEVEL 1 if fails
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Path1 = ""
        Path2 = ""
        filename1 = ""
        filename2 = ""
        version1 = ""
        version2 = ""
        Label = ""
        smaller = ""

        usage = """usage : %prog CheckDLLVersionP1NotSmallerP2 [options]
                Example: python %prog CheckDLLVersionP1NotSmallerP2 --P1 .\sim_swc_simctrl.dll --P2 .\sim_swc_simctrl_ref.dll --LogFile error.txt -o .\ """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("--P1", dest="Path1",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll ")
        parser.add_option("--P2", dest="Path2",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll ")
        parser.add_option("--LogFile", dest="LogFile",
                          help="e.g. error.txt ")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder e.g. ..\..\04_Build\algo\ ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        Path1 = options.Path1
        Path2 = options.Path2
        LogFile = options.LogFile
        LogDir = options.LogDir

        # print "Aufrufposition:", os.getcwd()
        path1 = os.path.join(os.getcwd(), Path1)
        path2 = os.path.join(os.getcwd(), Path2)
        logdir = os.path.join(os.getcwd(), LogDir)

        filename1 = os.path.abspath(path1)
        filename2 = os.path.abspath(path2)
        foldername3 = os.path.abspath(logdir)

        # LogFile path construction
        seqTemp = (foldername3, LogFile)  # This is sequence of strings.
        LogFilePath = os.sep.join(seqTemp)

        # File existenz ueberpruefen sonst exit systhem
        if (os.path.isfile(filename1) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -x/--XmlPath, " + filename1 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(filename2) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -p/--DllPath, " + filename2 + " file not does exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isdir(logdir) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --LogDir, " + LogDir + "  folder not does exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (LogFile == ""):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --LogFile, " + LogFile + "  Log-File name is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        # print filename1
        # print filename2

        version1 = ".".join([str(i) for i in self.get_version_number(filename1)])
        if (version1 == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename1 + " file has no version attribute\n")
            input = raw_input("Attention file has no version attribute. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    f = open(LogFilePath, 'a')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename1 + " file has no version attribute\n")
                    f.write('\n')
                    f.close()
                    sys.exit()
                else:
                    sys.exit(1)

        version2 = ".".join([str(i) for i in self.get_version_number(filename2)])
        if (version2 == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename2 + " file has no version attribute\n")
            input = raw_input("Attention file has no version attribute. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    f = open(LogFilePath, 'a')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename2 + " file has no version attribute\n")
                    f.write('\n')
                    f.close()
                    sys.exit()
                else:
                    sys.exit(1)

        version1List = version1.split(".")
        version2List = version2.split(".")

        i = 0
        while i < 3:  # check only the firs 3 nummbers
            if (int(version1List[i]) > int(version2List[i])):
                smaller = False
                break
            elif (int(version1List[i]) < int(version2List[i])):
                smaller = True
                break
            else:
                i += 1

        # wenn nicht bigger dan abfragen ob gleich wenn nciht dann erst kleiner
        if (smaller == True):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Version1 smaller Version2: " + version1 + " < " + version2 + '\n')
            input = raw_input("ERROR: Attention Version1 smaller Version2. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    f = open(LogFilePath, 'a')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: " + version1 + ' -> ' + filename1 + ' smaller\n')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: " + version2 + ' -> ' + filename2 + '\n')
                    f.write('\n')
                    f.close()
                else:
                    sys.exit(1)

    def CheckDLLVersionWithXmlLabel(self, argu):
        ###########
        #
        # CheckDLLVersionWithXmlLabel(self,argu)
        #
        # Description:    check is the verion of the file same as the version in label from xml-file (e.g. shared_project_config.xml) if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      -x/--XmlPath:      Path of the xml-file                                        e.g. .\shared_project_config.xml
        #                 -c/--CompLabel:    Component label in xml-file where the dev. path is saved    e.g. ALN_Alignment
        #                 -p/--DllPath:      Path of the file (e.g. DLL)                                 e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll
        #                 --LogFile:         Logfilename                                                 e.g. error.txt
        #                 -o/--output:       Path of logfile output directory                            e.g. .\
        #
        # Return:         ERRORLEVEL 1 if fails or the result is not same as expected
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Path1 = ""
        Path2 = ""
        filename1 = ""
        filename2 = ""
        version1 = ""
        version2 = ""
        Label = ""

        usage = """usage : %prog CheckDLLVersionWithXmlLabel [options]
                Example: python %prog CheckDLLVersionWithXmlLabel -x .\shared_project_config.xml -c EM_EnvironmentModel -p .\test\sim_swc_em.dll --LogFile error.txt -o ..\..\04_Build\algo\ """

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("-x", "--XmlPath", dest="XmlPath",
                          help="e.g. .\shared_project_config.xml")
        parser.add_option("-c", "--CompLabel", dest="CompLabel",
                          help="e.g. ALN_Alignment")
        parser.add_option("-p", "--DllPath", dest="DllPath",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll")
        parser.add_option("--LogFile", dest="LogFile",
                          help="e.g. error.txt ")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder e.g. ..\..\04_Build\algo\ ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        XmlPath = options.XmlPath
        CompLabel = options.CompLabel
        # CompLabel = "ALN_Alignment"
        DllPath = options.DllPath
        LogDir = options.LogDir
        LogFile = options.LogFile

        # print "DLLPath:" , DllPath

        # print "Aufrufposition:", os.getcwd()
        path1 = os.path.join(os.getcwd(), XmlPath)
        # path1 = "D:\\work\\phyton\\mks_tool\\src\\shared_project_config.xml"
        path2 = os.path.join(os.getcwd(), DllPath)
        # path2 = "D:\\work\\phyton\\mks_tool\\src\\test\\sim_swc_fct.dll"
        logdir = os.path.join(os.getcwd(), LogDir)

        filename1 = os.path.abspath(path1)
        filename2 = os.path.abspath(path2)
        foldername3 = os.path.abspath(logdir)
        # print "filename2:" , filename2

        # LogFile path construction
        seqTemp = (foldername3, LogFile)  # This is sequence of strings.
        LogFilePath = os.sep.join(seqTemp)

        # File existenz ueberpruefen sonst exit systhem
        if (os.path.isfile(filename1) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -x/--XmlPath, " + filename1 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(filename2) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -p/--DllPath, " + filename2 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (CompLabel == ""):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -c/--CompLabel, " + CompLabel + " Label name is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isdir(logdir) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --LogDir, " + LogDir + "  folder does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (LogFile == ""):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --LogFile, " + LogFile + "  Log-File name is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        # print filename1
        # print filename2

        Label = mks_obj.GetAttributeFromXML(self, filename1, "BaseConfig", "CompName", CompLabel, "Label")
        if (Label == "" or Label == "0"):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -c/--CompLabel, " + CompLabel + " does not exist in the XML file\n"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        version1 = self.getVersionFromLabel(Label)
        if (version1 == "0"):
            print (
                datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: " + Label + " includes no valid version nummber\n")
            input = raw_input("Attention comp. label includes no valid version nummber. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    f = open(LogFilePath, 'a')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: " + Label + " includes no valid version nummber\n")
                    f.write('\n')
                    f.close()
                else:
                    sys.exit(1)
        else:
            version2 = ".".join([str(i) for i in self.get_version_number(filename2)])
            if (version2 == "0"):
                print (datetime.now().strftime(
                        "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename2 + " file has no version attribute\n")
                input = raw_input("Attention file file has no version attribute. Abort? [y/n]:")
                input = self.ynInputCheck(input, 100)
                if input != "0":
                    if (input == "n" or input == "N"):
                        f = open(LogFilePath, 'a')
                        f.write(datetime.now().strftime(
                                "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename2 + " file has no version attribute\n")
                        f.write('\n')
                        f.close()
                    else:
                        sys.exit(1)
            else:
                # wenn gleich dann warnen und fragen obs weiter gehen soll
                equal = self.IsStrVersionEqual(version1, version2)
                if (equal == "0"):
                    print (datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: IsStrVersionEqual: " + version1 + " or " + version2 + " includes no valid version nummber\n")
                    input = raw_input("Attention comp. label includes no valid version nummber. Abort? [y/n]:")
                    input = self.ynInputCheck(input, 100)
                    if input != "0":
                        if (input == "n" or input == "N"):
                            f = open(LogFilePath, 'a')
                            f.write(datetime.now().strftime(
                                    "%Y_%m_%d %H:%M:%S") + " ERROR: IsStrVersionEqual" + version1 + " or " + version2 + " includes no valid version nummber\n")
                            f.write('\n')
                            f.close()
                        else:
                            sys.exit(1)
                elif (equal == False):
                    print (datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: Versions are not equal: " + Label + ' -> ' + version1 + " != " + version2 + '\n')
                    input = raw_input("ERROR: Attention Versions are not equal. Abort? [y/n]:")
                    input = self.ynInputCheck(input, 100)
                    if input != "0":
                        if (input == "n" or input == "N"):
                            f = open(LogFilePath, 'a')
                            f.write(datetime.now().strftime(
                                    "%Y_%m_%d %H:%M:%S") + " ERROR: " + version1 + ' -> ' + Label + ' not equal' + '\n')
                            f.write(datetime.now().strftime(
                                    "%Y_%m_%d %H:%M:%S") + " ERROR: " + version2 + ' -> ' + filename2 + ' not equal' + '\n')
                            f.write('\n')
                            f.close()
                        else:
                            sys.exit(1)

    def CheckIfSharedSubSubsandboxBuild(self, argu):
        ###########
        #
        # CheckIfSharedSubSubsandboxBuild(self,argu)
        #
        # Description:    check are the Shared-Sub-Subsandbox(es) build if not the shared projects that are not bild will be displayed and ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      -H/--Host:           Server                      e.g. mks-psad
        #                 -P/--Portconfig:     Port                        e.g. 7001
        #                 -p/--ProjectPath:    Path of the project file    e.g. ..\..\01_Source_Code\project.pj
        #
        # Return:         ERRORLEVEL 1 if fails
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        BuildList = ""

        usage = """usage : %prog CheckIfSharedSubSubsandboxBuild [options]
                Example: CheckIfSharedSubSubsandboxBuild -H mks-psad -P 7001 -p ..\..\01_Source_Code\project.pj"""

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-p", "--ProjectPath", dest="ProjectPath",
                          help="e.g. .\project.pj")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        ProjectPath = options.ProjectPath

        path = os.path.join(os.getcwd(), ProjectPath)

        abspath = os.path.abspath(path)

        # Input check
        if (self.Host == ""):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Input -H/--Host, is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (self.Port.isdigit() == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -P/--Portconfig, " + self.Port + " is not a number"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isdir(abspath) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -p/--ProjectPath, " + abspath + " dir does not exist or path is wrong e.g. -p ..\..\\01_Source_Code\project.pj"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        BuildList = self.IsSharedSubSubsandboxBuild(abspath)
        if (BuildList == "" or BuildList == 0):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewsandbox command fail"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (BuildList != True):
            # print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Shared subproject(s) not configured to build" + "\n"
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " INFO: Shared subproject(s) is not configured to build in: " + '\n')
            print "please check the configuration of Shared subproject(s) listed below" + "\n"
            print " " + '\n'

            index = 0
            lenList = len(BuildList)
            while index < lenList:
                ret = BuildList[index]
                print  ret
                index += 1

            input = raw_input("Attention shared subproject(s) not configured to build. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    sys.exit()
                else:
                    sys.exit(1)

    def CheckIsInputyn(self, argu):
        ###########
        #
        # CheckIsInputyn(self,argu)
        #
        # Description:    for input query in DOS, if the expected input occur the specified ERRORLEVEL number will be generated on exit
        #
        # Parameter:      --Input:               The expected input                               e.g. y
        #                 --ErrorLevelOutput:    Specified ERRORLEVEL number generated on exit    e.g. 2
        #
        # Return:         ERRORLEVEL 1 if fails
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init

        usage = """usage : %prog CheckIsInputyn [options]
                Example: python %prog CheckIsInputyn --Input n --ErrorLevelOutput 2 """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("--Input", dest="Input",
                          help="e.g. n ")
        parser.add_option("--ErrorLevelOutput", dest="ErrorLevelOutput",
                          help="e.g. 2 ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        Input = options.Input
        ErrorLevelOutput = options.ErrorLevelOutput

        # Input check
        if (ErrorLevelOutput.isdigit() == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -ErrorLevelOutput, " + ErrorLevelOutput + " is not a number"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (ErrorLevelOutput == "1"):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -ErrorLevelOutput, " + ErrorLevelOutput + " should not be used, it is reserved for programmers"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (Input == ""):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Input -Input, " + Input + " is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        StrInput = raw_input("Please type [y] for yes and [n] for not:")
        StrInput = self.ynInputCheck(StrInput, 99)
        if StrInput != "0":
            if (Input.islower() == True):
                if (StrInput.islower() != True):
                    StrInput = StrInput.lower()
            else:
                if (StrInput.isupper() != True):
                    StrInput = StrInput.upper()

                    # print StrInput +" Input: " + Input
            if (StrInput == Input):
                sys.exit(int(ErrorLevelOutput))

    def CheckProjectType(self, argu):
        ###########
        #
        # CheckProjectType(self,argu)
        #
        # Description:    check is the Project type same as expected if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      -H/--Host:           Server                      e.g. mks-psad
        #                 -P/--Portconfig:     Port                        e.g. 7001
        #                 -p/--ProjectPath:    Path of the project file    e.g. .\project.pj
        #                 -t/--ProjectType:    Expected project type       e.g. normal/variant/build"
        #
        # Return:         ERRORLEVEL 1 if fails or the result is not same as expected
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Path1 = ""
        Path2 = ""
        filename1 = ""
        filename2 = ""
        version1 = ""
        version2 = ""
        Label = ""

        usage = """usage : %prog CheckProjectType [options]
                Example: python %prog CheckProjectType -H mks-psad -P 7001 -p .\project.pj -t variant """

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-p", "--ProjectPath", dest="ProjectPath",
                          help="e.g. .\project.pj")
        parser.add_option("-t", "--ProjectType", dest="ProjectType",
                          help="e.g. normal/variant/build")
        # parser.add_option("--LogFile", dest="LogFile",
        # help="e.g. errorCompile_ref.txt ")
        # parser.add_option("-o", "--output", dest="LogDir",
        # help="logging outputfolder e.g. ..\..\04_Build\algo\ ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        ProjectPath = options.ProjectPath
        ProjectType = options.ProjectType
        # LogDir          = options.LogDir
        # LogFile         = options.LogFile

        # print "Aufrufposition:", os.getcwd()
        path = os.path.join(os.getcwd(), ProjectPath)
        # logdir = os.path.join(os.getcwd(), ProjectPath )
        # path = "D:\\sandbox\\ARS353_04.04.00_INT\\project.pj"

        abspath = os.path.abspath(path)
        # foldername3 = os.path.abspath(logdir)

        # seqTemp = (foldername3, LogFile); # This is sequence of strings.
        # LogFilePath = os.sep.join(seqTemp)

        # Input check
        if (self.Host == ""):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Input -H/--Host, is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (self.Port.isdigit() == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -P/--Portconfig, " + self.Port + " is not a number"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif not (ProjectType == "normal" or ProjectType == "variant" or ProjectType == "build"):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -t/--ProjectType, " + ProjectType + " does not match with normal/variant/build or n/v/b"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        # elif (os.path.isdir(logdir) == False):
        # print "ERROR: Input --LogDir, " + LogDir + "  folder not exist or path is wrong"
        # raw_input("Please for confirmation press enter:")
        # print "Info","Aborted -> exit"
        # sys.exit(1)
        # elif (LogFile == ""):
        # print "ERROR: Input --LogFile, " + LogFile + "  Log-File name is empty"
        # raw_input("Please for confirmation press enter:")
        # print "Info","Aborted -> exit"
        # sys.exit(1)

        CurrentType = mks_obj.GetProjectType(self, abspath)
        if (CurrentType == "" or CurrentType == "0"):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewproject command fail"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (CurrentType != ProjectType):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Types not equal. " + CurrentType + " != " + ProjectType + " not equal" + "\n"
            print "please check the configuration of " + abspath + " in MKS " + "and set it to " + ProjectType + "\n"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

    def CheckSameFile(self, argu):
        ###########
        #
        # CheckSameFile(self,argu)
        #
        # Description:    check are the files same as expected on the binary level if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      --P1:       Path of the first file                                 e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll
        #                 --P2:       Path of the second file                                e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll
        #                 --equal:    Expected behavior, should the fiels be equal or not    e.g. True/true or False/false
        #
        # Return:         ERRORLEVEL 1 if fails or the result is not same as expected
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Path1 = ""
        Path2 = ""
        filename1 = ""
        filename2 = ""

        usage = """usage : %prog CheckSameFile [options]
                Example: python %prog CheckSameFile --P1 .\File_1.dll --P2 .\File_2.dll --equal true"""

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("--P1", dest="Path1",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll")
        parser.add_option("--P2", dest="Path2",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll")
        parser.add_option("--equal", dest="equal",
                          help="e.g. True/true od False/false ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        Path1 = options.Path1
        Path2 = options.Path2
        equal = options.equal

        # print "Aufrufposition:", os.getcwd()
        path1 = os.path.join(os.getcwd(), Path1)
        path2 = os.path.join(os.getcwd(), Path2)

        filename1 = os.path.abspath(path1)
        filename2 = os.path.abspath(path2)

        # Input check
        if not (equal == "True" or equal == "true" or equal == "False" or equal == "false"):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --equal, " + equal + " do not match with True/true od False/false"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(filename1) == False):
            print  datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --P1, " + Path1 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(filename2) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --P2, " + Path2 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        retFileEqual = self.IsFileContentEqual(filename1, filename2)
        if (retFileEqual == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: IsFileContentEqual, " + filename1 + " or " + filename2 + 'could not be opened\n')
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        else:
            if (equal == "True" or equal == "true"):  # if the Files shluld be equal
                if (retFileEqual == False):
                    print (datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: files not equal " + Path1 + " != " + Path2 + '\n')
                    raw_input("Please for confirmation press enter:")
                    sys.exit(1)
            else:
                if (retFileEqual == True):
                    print (datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: files equal " + Path1 + " == " + Path2 + '\n')
                    raw_input("Please for confirmation press enter:")
                    sys.exit(1)

    def CheckSameFolder(self, argu):
        ###########
        #
        # CheckSameFolder(self,argu)
        #
        # Description:    check are the folders same as expected on the binary level if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      --P1:       Path of the first Folder                                 e.g. ..\..\01_Source_Code\
        #                 --P2:       Path of the second Folder                                e.g. ..\..\01_Source_Code_tmp\
        #                 --equal:    Expected behavior, should the folders be equal or not    e.g. True/true or False/false
        #
        # Return:         ERRORLEVEL 1 if fails or the result is not same as expected
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########
        import filecmp
        import StringIO

        # Init
        count = 0
        count1 = 0
        countClip = 0
        foldername1 = ""
        foldername2 = ""
        Path1 = ""
        Path2 = ""
        outputStr = ""
        output = StringIO.StringIO()

        usage = """usage : %prog CheckSameFolder [options]
                Example: python %prog CheckSameFolder --P1 ..\..\01_Source_Code\ --P2 ..\..\01_Source_Code_tmp\ --equal true """

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("--P1", dest="Path1",
                          help="e.g. ..\..\04_Build\algo\aln_sim\ ")
        parser.add_option("--P2", dest="Path2",
                          help="e.g. ..\..\04_Build\algo\aln_sim_tmp\ ")
        parser.add_option("--equal", dest="equal",
                          help="e.g. True/true or False/false ")
        # parser.add_option("--LogFile", dest="LogFile",
        # help="e.g. errorCompile_ref.txt ")
        # parser.add_option("-o", "--output", dest="LogDir",
        # help="logging outputfolder e.g. ..\..\04_Build\algo\ ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        Path1 = options.Path1
        Path2 = options.Path2
        equal = options.equal
        # LogDir = options.LogDir
        # LogFile = options.LogFile

        # print "Aufrufposition:", os.getcwd()
        path1 = os.path.join(os.getcwd(), Path1)
        path2 = os.path.join(os.getcwd(), Path2)
        # logdir = os.path.join(os.getcwd(), LogDir)

        foldername1 = os.path.abspath(path1)
        foldername2 = os.path.abspath(path2)
        # foldername3 = os.path.abspath(logdir)
        #
        #        #LogFile path construction
        # seqTemp = (foldername3, LogFile); # This is sequence of strings.
        # LogFilePath = os.sep.join(seqTemp)

        # Input check
        if not (equal == "True" or equal == "true" or equal == "False" or equal == "false"):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --equal, " + equal + " do not match with True/true od False/false"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isdir(path1) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --P1, " + Path1 + " folder does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isdir(path2) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --P2, " + Path2 + "  folder does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        # elif (os.path.isdir(logdir) == False):
        # print "ERROR: Input --LogDir, " + LogDir + "  folder not exist or path is wrong"
        # raw_input("Please for confirmation press enter:")
        # print "Info","Aborted -> exit"
        # sys.exit(1)
        # elif (LogFile == ""):
        # print "ERROR: Input --LogFile, " + LogFile + "  Log-File name is empty"
        # raw_input("Please for confirmation press enter:")
        # print "Info","Aborted -> exit"
        # sys.exit(1)
        # print foldername1
        # print foldername2

        old_stdout = sys.stdout

        # stdout umleiten
        sys.stdout = output

        # underortner nach diffs duchsuchen project.pj dateien werden ignoriert
        compare = filecmp.dircmp(foldername1, foldername2, ignore=['project.pj'])
        compare.report_full_closure()
        # print compare.report_full_closure()
        # alten stdout wiederherstellen
        sys.stdout = old_stdout

        output.seek(0)
        outputStr = output.getvalue()
        count = outputStr.find("Differing files")
        if (count == -1):
            output.seek(0)
            count1 = outputStr.find("Only in")

        if (equal == "True" or equal == "true"):  # if the Folders should be equal
            if (count != -1):  # wenn diffs gefunden
                countClip = outputStr.find(']', count + 19, len(outputStr))
                print (datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Differences exist in: " + outputStr[
                                                                                                         count + 19:countClip] + '\n')
                raw_input("Please for confirmation press enter:")
                sys.exit(1)
            elif (count1 != -1):
                countClip = outputStr.find(']', count1, len(outputStr))
                print (datetime.now().strftime(
                        "%Y_%m_%d %H:%M:%S") + " ERROR: Differences exist in some file/s found: " + outputStr[
                                                                                                    count1 - 1:countClip + 1] + '\n')
                raw_input("Please for confirmation press enter:")
                sys.exit(1)
        else:  # if the Folders should not be equal
            if (count == -1 and count1 == -1):
                print (datetime.now().strftime(
                        "%Y_%m_%d %H:%M:%S") + " ERROR: folders " + foldername1 + " == " + foldername2 + " are equal, except should not be equal" + '\n')
                raw_input("Please for confirmation press enter:")
                sys.exit(1)

    def CompareDLLVersion(self, argu):
        ###########
        #
        # CheckSameFile(self,argu)
        #
        # Description:    check are the versions of files same as expected if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      --P1:           Path of the first file                                 e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll
        #                 --P2:           Path of the second file                                e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll
        #                 --equal:        Expected behavior, should the fiels be equal or not    e.g. True/true or False/false
        #                 --LogFile:      Logfilename                                            e.g. error.txt
        #                 -o/--output:    Path of logfile output directory                       e.g. .\
        #
        # Return:         ERRORLEVEL 1 if fails or the result is not same as expected
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        Path1 = ""
        Path2 = ""
        filename1 = ""
        filename2 = ""
        version1 = ""
        version2 = ""

        usage = """usage : %prog CompareDLLVersion [options]
                Example: python %prog CompareDLLVersion --P1 ..\..\04_Build\algo\aln_sim\sim_swc_align.dll --P2 ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll --equal true --LogFile error.txt -o ..\..\04_Build\algo\ """

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("--P1", dest="Path1",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align.dll")
        parser.add_option("--P2", dest="Path2",
                          help="e.g. ..\..\04_Build\algo\aln_sim\sim_swc_align_ref.dll")
        parser.add_option("--equal", dest="equal",
                          help="e.g. True/true od False/false ")
        parser.add_option("--LogFile", dest="LogFile",
                          help="e.g. errorCompile_ref.txt ")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder e.g. ..\..\04_Build\algo\ ")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        Path1 = options.Path1
        Path2 = options.Path2
        equal = options.equal
        LogDir = options.LogDir
        LogFile = options.LogFile

        # print "Aufrufposition:", os.getcwd()
        path1 = os.path.join(os.getcwd(), Path1)
        path2 = os.path.join(os.getcwd(), Path2)
        logdir = os.path.join(os.getcwd(), LogDir)

        filename1 = os.path.abspath(path1)
        filename2 = os.path.abspath(path2)
        foldername3 = os.path.abspath(logdir)

        # LogFile path construction
        seqTemp = (foldername3, LogFile)  # This is sequence of strings.
        LogFilePath = os.sep.join(seqTemp)

        # Type existenz ueberpruefen sonst exit systhem
        if not (equal == "True" or equal == "true" or equal == "False" or equal == "false"):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --equal, " + equal + " do not match with True/true od False/false"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        # File existenz ueberpruefen sonst exit systhem
        elif (os.path.isfile(filename1) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --P1, " + filename1 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(filename2) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --P2, " + filename2 + " file does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isdir(logdir) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --LogDir, " + LogDir + "  folder does not exist or path is wrong"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (LogFile == ""):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input --LogFile, " + LogFile + "  Log-File name is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        version1 = ".".join([str(i) for i in self.get_version_number(filename1)])
        if (version1 == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename1 + " file has no version attribute\n")
            input = raw_input("Attention file has no version attribute. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    f = open(LogFilePath, 'a')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename1 + " file has no version attribute\n")
                    f.write('\n')
                    f.close()
                    sys.exit()
                else:
                    sys.exit(1)

        version2 = ".".join([str(i) for i in self.get_version_number(filename2)])
        if (version2 == "0"):
            print (datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename2 + " file has no version attribute\n")
            input = raw_input("Attention file has no version attribute. Abort? [y/n]:")
            input = self.ynInputCheck(input, 100)
            if input != "0":
                if (input == "n" or input == "N"):
                    f = open(LogFilePath, 'a')
                    f.write(datetime.now().strftime(
                            "%Y_%m_%d %H:%M:%S") + " ERROR: get_version_number: " + filename2 + " file has no version attribute\n")
                    f.write('\n')
                    f.close()
                    sys.exit()
                else:
                    sys.exit(1)
        print "version info"
        print "%s: %s   %s: %s" % (filename1, version1, filename2, version2)
        egualret = self.IsStrVersionEqual(version1, version2)
        if (egualret == "0"):  # Fehler abfrage
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " Error: IsStrVersionEqual() failed"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        elif (equal == "True" or equal == "true"):  # if the Folders shluld be equal
            if (egualret == False):
                print (datetime.now().strftime(
                        "%Y_%m_%d %H:%M:%S") + " ERROR: files not equal " + Path1 + ' -> ' + version1 + " != " + Path2 + ' -> ' + version2 + '\n')
                input = raw_input("Attention Versiones are not equal. Abort? [y/n]:")
                input = self.ynInputCheck(input, 100)
                if input != "0":
                    if (input == "n" or input == "N"):
                        f = open(LogFilePath, 'a')
                        f.write(datetime.now().strftime(
                                "%Y_%m_%d %H:%M:%S") + " ERROR: files not equal " + version1 + ' -> ' + filename1 + '\n')
                        f.write(datetime.now().strftime(
                                "%Y_%m_%d %H:%M:%S") + " ERROR: files not equal " + version2 + ' -> ' + filename2 + '\n')
                        f.write('\n')
                        f.close()
                    else:
                        sys.exit(1)
        elif (equal == "False" or equal == "false"):  # if the Folders shluld be not equal
            if (egualret == True):
                print (datetime.now().strftime(
                        "%Y_%m_%d %H:%M:%S") + " ERROR: files equal " + Path1 + ' -> ' + version1 + " == " + Path2 + ' -> ' + version2 + '\n')
                input = raw_input("Attention Versiones are equal. Abort? [y/n]:")
                input = self.ynInputCheck(input, 100)
                if input != "0":
                    if (input == "n" or input == "N"):
                        f = open(LogFilePath, 'a')
                        f.write(datetime.now().strftime(
                                "%Y_%m_%d %H:%M:%S") + " ERROR: files equal " + version1 + ' -> ' + filename1 + '\n')
                        f.write(datetime.now().strftime(
                                "%Y_%m_%d %H:%M:%S") + " ERROR: files equal " + version2 + ' -> ' + filename2 + '\n')
                        f.write('\n')
                        f.close()
                    else:
                        sys.exit(1)

    def CompareSandboxWithProject(self, argu):
        ###########
        #
        # CompareSandboxWithProject(self,argu)
        #
        # Description:    check are the Sanbox configuration equal with Project configuration if not the ERRORLEVEL 1 will be generated on exit
        #
        # Parameter:      -H/--Host:           Server                      e.g. mks-psad
        #                 -P/--Portconfig:     Port                        e.g. 7001
        #                 -p/--ProjectPath:    Path of the project file    e.g. ..\..\01_Source_Code\project.pj
        #
        # Return:         ERRORLEVEL 1 if fails
        #
        # Author:         Ilja Hotjakov 08.03.2012
        #
        # TODO: add parameter check
        #
        ###########

        # Init

        usage = """usage : %prog CompareSandboxWithProject [options]
                Example: CompareSandboxWithProject -H mks-psad -P 7001 -p ..\..\01_Source_Code\project.pj"""

        # parse the arguments
        parser = OptionParser(usage)

        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-p", "--ProjectPath", dest="ProjectPath",
                          help="e.g. .\project.pj")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        ProjectPath = options.ProjectPath

        path = os.path.join(os.getcwd(), ProjectPath)

        abspath = os.path.abspath(path)

        # Input check
        if (self.Host == ""):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: Input -H/--Host, is empty"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (self.Port.isdigit() == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -P/--Portconfig, " + self.Port + " is not a number"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (os.path.isfile(abspath) == False):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Input -p/--ProjectPath, " + abspath + " file does not exist or path is wrong e.g. -p ..\..\01_Source_Code\project.pj"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)

        Equal = CheckAlgoIntegration_obj.IsSandboxEqualProject(self, abspath)
        if (Equal == "" or Equal == "0"):
            print datetime.now().strftime("%Y_%m_%d %H:%M:%S") + " ERROR: si viewsandbox or viewproject command failed"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)
        elif (Equal != True):
            print datetime.now().strftime(
                    "%Y_%m_%d %H:%M:%S") + " ERROR: Sanbox configuration is not equal with Project. " + "\n"
            print "please check the configuration of " + abspath + " in MKS " + "and contact the MKS support" + "\n"
            raw_input("Please for confirmation press enter:")
            sys.exit(1)


class CompareCheckpoints_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Compare 2 checkpoints to Release
    #
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.Project = ""
        self.Sandbox = ""

        self.ActDevPath = ""
        self.Type = "normal"

        self.Logging = False
        self.LogDir = ""

        self.OldCheckpoint = ""
        self.NewCheckpoint = ""
        self.ReleaseID = ""

        self.RootScanPath = ""

        self.StartingPjName = "project.pj"

    def GoThrouProjects(self, Project, Revision):
        ###########
        #
        # GoThrouProjects(self, Project)
        #
        # Description: Go throu all projects and create a file folder structure
        #
        # Parameter: -Project the mks path of the project where the scann should start
        # return 0 if all shared sub project are build, 1 if not
        #
        # TODO: add parameter check
        #
        ###########
        ProjectView = self.GetProjectView(Project, Revision)
        ret_value = {"dir": {}, "files": {}}
        files = {}
        for line in ProjectView:
            # print line
            if (len(line) > 1):
                # (argu[1] != 'shared-subproject') and (argu[1] != 'shared-build-subproject') and (argu[1] != 'shared-variant-subproject') and (argu[1] != 'archived')
                ret = self.GetPathOfSandboxOrProject(line, Project, "")
                # logging.Log("Debug",ret["ret"])
                # logging.Log("Debug","NextProject %s"%ret["project"])
                # logging.Log("Debug","NextSandbox %s"%ret["sandbox"])

                if (ret["ret"] != 2):
                    # if it is not a shared sub project go to the next directory
                    # go to next path directory of the project or the sandbox is no shared-subproject and no archiv
                    ret_value["dir"][ret["project"]] = self.GoThrouProjects(ret["project"], ret["revision"])
                else:
                    files[ret["filename"]] = ret["revision"]
        ret_value["files"] = files
        return ret_value

    def GoThrouDelta(self, CurrentDir, OldDirFileList, NewDirFileList):
        ###########
        #
        # GoThrouProjects(self, OldDirFileList, NewDirFileList)
        #
        # Description: Go throu all dir and files and find differences
        #
        # Parameter: -OldDirFileList the old dir and file list
        #            -NewDirFileList the new dir and file list
        # return None in case of no difference otherwise retur a list with the file differences
        #
        # TODO: add parameter check
        #
        ###########
        ret_value = None
        Differences = []
        for Dir in NewDirFileList["dir"]:
            # print Dir
            if Dir in OldDirFileList["dir"]:
                toappend = self.GoThrouDelta(Dir, OldDirFileList["dir"][Dir], NewDirFileList["dir"][Dir])
                if (toappend != None) and (len(toappend) > 0):
                    Differences.extend(toappend)
            else:
                self.Log("Info", "Directory %s is new in new checkpoint" % Dir)
        OldFiles = OldDirFileList["files"]
        NewFiles = NewDirFileList["files"]
        for file in NewFiles:
            if file in OldFiles:
                if OldFiles[file] != NewFiles[file]:
                    Differences.append((CurrentDir, file, [OldFiles[file], NewFiles[file]]))
                    # print "%s is differnt"%file
            else:
                self.Log("Info", "File %s is new in new checkpoint" % file)
        if len(Differences) > 0:
            ret_value = Differences
        return ret_value

    def ExpandRev(self, StartLevel, revision):
        # print revision
        base = revision[0:StartLevel + 1]
        ret_value = []
        for i in range(StartLevel + 1, len(revision)):
            # print revision[i]
            if (i % 2 == 1):
                for v in range(1, int(revision[i]) + 1):
                    # print v
                    local = []
                    local.extend(base)
                    local.append(str(v))
                    ret_value.append(local)
                base.append(revision[i])
            else:
                base.append(revision[i])

                # base = local
        return ret_value

    def Expander(self, oldRev, newRev):
        A = oldRev.split('.')
        B = newRev.split('.')

        max = 0
        if (len(A) > len(B)):
            max = len(A)
        else:
            max = len(B)

        base = []
        local = []
        ret_value = []
        for i in range(max):
            if i >= len(A):
                local = []
                local.extend(base)
                ret_value.append(local)
                ret_value.extend(self.ExpandRev(i, B))
                break
            elif i >= len(B):
                local = []
                local.extend(base)
                ret_value.append(local)
                ret_value.extend(self.ExpandRev(i, A))
                break
            elif (A[i] != B[i]):
                # expand the revisions between the difference
                for v in range(abs(int(B[i]) - int(A[i])) + 1):
                    local = []
                    local.extend(base)
                    if int(A[i]) > int(B[i]):
                        local.append(str(int(B[i]) + v))
                    else:
                        local.append(str(int(A[i]) + v))
                    ret_value.append(local)
                # expand the revisions from starting index i
                ret_value.extend(self.ExpandRev(i, A))
                ret_value.extend(self.ExpandRev(i, B))
                # print i
                # if all is expanded leaf the loop
                break
            else:
                base.append(str(A[i]))

        # Convert revision arrays to stringlist with string revisions
        stringlist = []
        for i in ret_value:
            rev = "%s" % i[0]
            for v in range(len(i) - 1):
                rev = "%s.%s" % (rev, i[v + 1])
            # do not add the old revisions to the list
            if rev != oldRev:
                stringlist.append(rev)
        return stringlist

    def ExpandMemberHistory(self, DifferencesList):
        ###########
        #
        # ExpandMemberHistory(self, DifferencesList)
        #
        # Description: Expand the member history for all diff files
        #
        # Parameter: -DifferencesList Differences List
        # return the expanded Differnces List
        #
        # TODO: add parameter check
        #
        ###########
        ExpandedList = []
        NrOfRevision = 0
        for differ in DifferencesList:
            revisions = self.Expander(differ[2][0], differ[2][1])
            ExpandedList.append((differ[0], differ[1], revisions))
            NrOfRevision += len(revisions)
        return (NrOfRevision, ExpandedList)

    def GetRelatedIssuesOfRelease(self, ReleaseID):
        ###########
        #
        # GetRelatedIssuesOfRelease(self, ReleaseID)
        #
        # Description: Get all the related issues of the selected release
        #
        # Parameter: -ReleaseID The ReleaseID
        #
        # return empty dict if no issues found otherwise return the open issues
        #
        # TODO: add parameter check
        #
        ###########
        # return all open issues
        Issues = {}

        # setup the not wanted issue states
        dict = {"AD_released": 1}  # ,"AD_test":1
        # get related issues
        self.Log("Info", "Get all related issues of release %s" % (ReleaseID))
        related_issues = self.GetRelationListForIssue(ReleaseID, "AD_Release", dict)
        start = 0
        prog = ProgressBar_obj(0, len(related_issues), 60, mode='fixed')
        oldprog = str(prog)
        for issue in related_issues:

            Task_issues = self.GetRelationListForIssue(issue, "AD_FR")
            if Task_issues == 0:
                Task_issues = self.GetRelationListForIssue(issue, "AD_CR")

            if (Task_issues == 0) or (len(Task_issues) == 0):
                self.Log("Info", "No open Task(s) found for issue %s" % (issue))
            else:
                if issue not in Issues:
                    Issues[issue] = {}
                for Task in Task_issues:
                    Issues[issue][Task] = Task

            prog.update_amount(start)
            if oldprog != str(prog):
                print prog, "\r",
                sys.stdout.flush()
                oldprog = str(prog)
            start += 1

        return Issues

    def GetTaskListOfReleaseIDs(self, ReleaseIDs):
        ###########
        #
        # GetRelatedIssuesOfRelease(self, ReleaseIDs)
        #
        # Description: Get all the related task issues of the selected releases
        #
        # Parameter: -ReleaseID The ReleaseIDs
        #
        # return empty dict if no task found otherwise return the tasklist
        #
        # TODO: add parameter check
        #
        ###########
        TasksList = {}
        old = self.Port
        self.Port = self.IMPort
        self.Log("Info", "Get tasks related to Releases, please wait")
        file_object = open("c:\\revisions2.txt", "w")
        for ReleaseID in ReleaseIDs:
            Issues = self.GetRelatedIssuesOfRelease(ReleaseID)
            for issue in Issues:
                for task in Issues[issue]:
                    if (task != "") and (task not in TasksList):
                        TasksList[task] = task
                        file_object.write("%s\n" % task)
        file_object.close()
        # print TasksList
        self.Port = old

        # file_object = open("c:\\revisions.txt", "r")
        # TasksList = {}
        # for line in file_object.readlines():
        # task = line.replace('\n','')
        # TasksList[task] = task
        # file_object.close()

        return TasksList

    def CompareCheckpoints(self, argu):
        ###########
        #
        # CompareCheckpoints(self,argu)
        #
        # Description: the CompareCheckpoints main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog CompareCheckpoints [options]
Example: python %prog CompareCheckpoints -H mks-psad -P 7001 -C1 AL_..-INT-1 -C2 AL_..-INT-1 -s D:\SW\ARS301\ -l -o c:\SW\integration\log"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-I", "--IMPortconfig", dest="IMPort",
                          help=" e.g. 7001 (mandatory)", metavar="6002")
        parser.add_option("-O", "--OldCheckpoint", dest="OldCheckpoint",
                          help="checkpoint label e.g. AL_VDY_BASE_INT-1 (mandatory)")
        parser.add_option("-N", "--NewCheckpoint", dest="NewCheckpoint",
                          help="checkpoint label e.g. AL_VDY_BASE_INT-2 (mandatory)")
        parser.add_option("-R", "--Release", dest="ReleaseID",
                          help="Release ID e.g. 12345 (mandatory)")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify it here, e.g ARS301.pj")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        self.IMPort = options.IMPort

        self.Sandbox = options.Sandbox
        self.Project = options.Project

        self.Logging = options.Logging
        self.LogDir = options.LogDir

        self.OldCheckpoint = options.OldCheckpoint
        self.NewCheckpoint = options.NewCheckpoint
        self.ReleaseID = options.ReleaseID

        self.StartingPjName = options.StartPjName

        # print self.Expander("1.4","1.4.1.8")
        # print self.Expander("1.4.1.8","1.4")
        # print self.Expander("1.2","1.4.1.8")
        # print self.Expander("1.4.1.8","1.6")
        # print self.Expander("1.2","1.4.1.2.1.4")
        # print self.Expander("1.4.1.2","1.4.1.3")
        # print self.Expander("1.13.1.3","1.16")
        # print self.Expander("1.16","1.13.1.3")
        # print self.Expander("1.13.1.1","1.16.1.3")
        # print self.Expander("1.16.1.3","1.13.1.1")

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -oc:\temp"
            sys.exit()
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -Hmks-psad")
            sys.exit()
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P7001")
            sys.exit()
        if ((self.IMPort == "") or (self.IMPort == None)):
            self.Log("Error", "setup host e.g. -I7002")
            sys.exit()

        if ((self.OldCheckpoint == "") or (self.OldCheckpoint == None)):
            self.Log("Error", "setup OldCheckpoint e.g. -O AL_VDY...INT-1")
            sys.exit()
        if ((self.NewCheckpoint == "") or (self.NewCheckpoint == None)):
            self.Log("Error", "setup NewCheckpoint e.g. -N AL_VDY...INT-2")
            sys.exit()
        if ((self.ReleaseID == "") or (self.ReleaseID == None)):
            self.Log("Error", "setup ReleaseID e.g. -R 12345")
            sys.exit()

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit()

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit()

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)
        self.Project = "%s/%s" % (self.Project, self.StartingPjName)

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)

        if (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)

        if (self.RootScanPath != 0):
            TasksList = {}
            # get the task list of this release
            TasksList = self.GetTaskListOfReleaseIDs(self.ReleaseID.split(','))

            # get the differences of the two checkpoints
            oldProjectType = self.ProjectType
            self.ProjectType = "project"
            self.Log("Info", "Get member revision infos for old checkpoint, please wait")
            self.OldRevision = self.GetRevisionForLabel(self.RootScanPath, self.OldCheckpoint)
            OldDirFiles = self.GoThrouProjects(self.RootScanPath, self.OldRevision)
            self.Log("Info", "Get member revision infos for new checkpoint, please wait")
            self.NewRevision = self.GetRevisionForLabel(self.RootScanPath, self.NewCheckpoint)
            NewDirFiles = self.GoThrouProjects(self.RootScanPath, self.NewRevision)
            self.DifferencesList = self.GoThrouDelta(NewDirFiles["dir"], OldDirFiles, NewDirFiles)
            self.ProjectType = oldProjectType

            # print self.DifferencesList
            self.Log("Info", "Expand the Member history")
            NrOfRevision, self.ExpDifferencesList = self.ExpandMemberHistory(self.DifferencesList)
            # print self.ExpDifferencesList
            self.CpidDiffList = []

            self.Log("Info", "Get member revision info, could take some time")
            start = 0
            prog = ProgressBar_obj(0, NrOfRevision, 60, mode='fixed')
            oldprog = str(prog)

            for file in self.ExpDifferencesList:
                # print file[1]
                for revision in file[2]:
                    # print revision
                    # print file[0]
                    MemberInfo = self.GetProjectMemberInfo(file[0], file[1], revision)
                    if MemberInfo == None:
                        self.Log("Error", "Could not get member history of file %s in project %s" % (file[1], file[0]))
                    else:
                        if ("cpid" in MemberInfo) and ("summary" in MemberInfo):
                            self.CpidDiffList.append(
                                    (MemberInfo["cpid"], MemberInfo["summary"], file[0], file[1], revision))
                        else:
                            self.Log("Error", "File %s in project %s has no revision %s" % (file[1], file[0], revision))

                    prog.update_amount(start)
                    if oldprog != str(prog):
                        print prog, "\r",
                        sys.stdout.flush()
                        oldprog = str(prog)
                    start += 1
                    # print self.CpidDiffList

            # check revision checkpointlist

            file_object = open("c:\\ReleaseCheckPointDiff.txt", "w")
            self.Log("Info", "Check differences")
            file_object.write(
                    "The following changes are not part of the Release %s, but are changed between %s and %s\n" % (
                        self.ReleaseID, self.OldCheckpoint, self.NewCheckpoint))
            NotAssignedTasks = {}
            NotAssignedTasksList = []
            for CpidDiff in self.CpidDiffList:  # if CpidDiff[0] not in TasksList:
                if CpidDiff[0] not in TasksList:
                    file_object.write(
                            "File %s changed in rev %s with Cpid %s , summary: %s is not part of the checkpoint\n" % (
                                CpidDiff[3], CpidDiff[4], CpidDiff[0], CpidDiff[1]))
                    if CpidDiff[0] not in NotAssignedTasks:
                        NotAssignedTasks[CpidDiff[0]] = CpidDiff[0]
                        NotAssignedTasksList.append(CpidDiff)
            file_object.write("---Summary---\n")
            for NotAssTask in NotAssignedTasksList:
                file_object.write("With Cpid %s where made changes, summary: %s is not part of the checkpoint\n" % (
                    NotAssTask[0], NotAssTask[1]))
            file_object.close()

            self.Log("Info", "CompareCheckpoints successful finished")
        else:
            self.Log("Info", "Aborted -> exit")


class SyncMksPathes_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Sync's the shared sub poject for two mks pathes, e.g normal and dev path
    #
    ###########
    FROM = "FROM"
    TO = "TO"
    DEFAULT_PATH = "normal"

    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.Project = ""
        self.Sandbox = ""

        self.ActDevPath = ""
        self.Type = "normal"

        self.Logging = False
        self.LogDir = ""

        self.FromPath = "normal"
        self.ToPath = ""

        self.StartingPjName = "project.pj"

    def ScanForSharedProject(self, Project, Sandbox, SharesDict, ProjectDict, DevPath):
        ###########
        #
        # ScanForSharedProject(self, Project, Shares, SharesDict, ProjectDict, DevPath)
        #
        # Description: Scan for all shared projects in project
        #
        # Parameter: -Project the mks path of the project where the scann should start
        #            -Sandbox the path of the pj file from the sandbox where the shared project scan should start
        #            -SharesDict a dict with all the shares, (From, and To)
        #            -DevPath the development path if "" the trunc is used
        # return 0 if no share is found, otherwise a list with the shares, and the location of the share
        #
        # TODO: add parameter check
        #
        ###########

        # Init
        ret_value = 0
        BuildList = ""
        if (self.ProjectType == "sandbox"):
            self.Log("Error", "Sandbox is not supported")
        elif (self.ProjectType == "project"):
            # logging.Log("Debug",project)
            cmdline = 'si viewproject --batch --hostname=%s --port=%s --project=%s --fields=name,type --norecurse' % (
                self.Host, self.Port, Project)
            if DevPath != self.DEFAULT_PATH:
                cmdline += " --devpath=%s" % DevPath

            self.cliProcHandler.SiCLIHandler_wait(cmdline)
            for line in self.cliProcHandler.getstdout_split():
                # print stdout
                if (len(line) > 1):
                    if Project not in ProjectDict:
                        ProjectDict.append(Project)
                    ret = self.GetPathOfSandboxOrProject(line, Project, Sandbox)

                    if (ret["ret"] != 2):
                        # if it is not a shared sub project go to the next directory
                        if (ret["ret"] == 1):
                            # go to next path directory of the project or the sandbox is no shared-subproject and no archiv
                            ret_value |= self.ScanForSharedProject(ret["project"], ret["sandbox"], SharesDict,
                                                                   ProjectDict, DevPath)
                        else:
                            IsNotBuild = 0
                            ProjectPath = 0
                            ProjectPathSharedFrom = 0
                            if (self.ProjectType == "sandbox"):
                                ProjectPath = self.GetProjectPath("sandbox", ret["sandbox"])
                                ProjectPathSharedFrom = self.GetSharedFromPath("sandbox", ret["sandbox"])
                                SharesDict.append({self.FROM: ProjectPathSharedFrom, self.TO: ProjectPath})
                            elif (self.ProjectType == "project"):
                                ProjectPath = self.GetProjectPath("project", ret["project"])
                                ProjectPathSharedFrom = self.GetSharedFromPath("project", ret["project"])
                                SharesDict.append({self.FROM: ProjectPathSharedFrom, self.TO: ProjectPath})

        # exit with the return value
        # ret_value = 0
        return ret_value

    def SyncMksPathes(self, argu):
        ###########
        #
        # SyncMksPathes(self,argu)
        #
        # Description: the SyncMksPathes main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog SyncMksPathes [options]
Example: python %prog SyncMksPathes -H mks-psad -P 7001 -f AL_..-INT-1 -t AL_..-INT-1 -s D:\SW\ARS301\ -l -o c:\SW\integration\log"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-C", "--ChangePackage", dest="CpId",
                          help="changePackeageID e.g. 33131:1 (mandatory)")
        parser.add_option("-f", "--FromPath", dest="FromPath",
                          help="checkpoint label e.g. AL_VDY_BASE_INT-1 (mandatory)")
        parser.add_option("-t", "--ToPath", dest="ToPath",
                          help="checkpoint label e.g. AL_VDY_BASE_INT-2 (mandatory)")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify it here, e.g ARS301.pj")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port
        self.CpId = options.CpId

        self.Sandbox = options.Sandbox
        self.Project = options.Project

        self.Logging = options.Logging
        self.LogDir = options.LogDir

        self.FromPath = options.FromPath
        self.ToPath = options.ToPath

        self.StartingPjName = options.StartPjName

        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            print "Error: log directory does not exist e.g. -oc:\temp"
            sys.exit()
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3
            if self.Logging is True:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt" % (self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -Hmks-psad")
            sys.exit()
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P7001")
            sys.exit()
        if ((self.CpId == "") or (self.CpId == None)):
            self.Log("Error", "No setup of change package id e.g. -C 33131:1 please enter it now:")
            cpid = raw_input("Your ChangePackage id:")
            if (cpid == ""):
                self.Log("Error", "No setup of change package -> exit")
                sys.exit(1)
            else:
                self.CpId = cpid

        if ((self.FromPath == "") or (self.FromPath == None)):
            self.Log("Info",
                     "Use default ""normal"" as from, or setup FromPath e.g. -f normal, or devpathname -f SMFC4B0_02.00.00")
            self.FromPath = self.DEFAULT_PATH
        if ((self.ToPath == "") or (self.ToPath == None)):
            self.Log("Error", "setup ToPath e.g. -t normal, or devpathname -f SMFC4B0_02.00.00")
            sys.exit()

        if ((self.Sandbox == "") or (self.Sandbox == None)):
            self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
        # check input directory
        if ((not os.path.isdir(self.Sandbox)) and (self.Project == "")):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\SWProjects\ARS301\06_Algorithm")
            sys.exit()

        # check input project and sandbox
        if (((self.Sandbox == "") or (self.Sandbox == None)) and ((self.Project == "") or (self.Project == None))):
            self.Log("Error",
                     "No sandbox or project path is setup e.g. -s D:\SWProjects\ARS301\06_Algorithm or -p /nfs/projekte1/PROJECTS/ARS301/06_Algorithm")
            sys.exit()

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)
        self.Project = "%s/%s" % (self.Project, self.StartingPjName)

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)

        if (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)

        if (self.RootScanPath != 0):
            # get the add the shares and the projects of the source (from) path
            FromSharesDict = []
            FromProjectDict = []
            self.Log("Info", "Scanning source (from) path")
            self.ScanForSharedProject(self.Project, self.Sandbox, FromSharesDict, FromProjectDict, self.FromPath)
            # print FromProjectDict

            # get the add the shares and the projects of the source (from) path
            ToSharesDict = []
            ToProjectDict = []
            self.Log("Info", "Scanning target (to) path")
            self.ScanForSharedProject(self.Project, self.Sandbox, ToSharesDict, ToProjectDict, self.ToPath)

            # compare ProjectDict

            # check for missing pathes
            # and find most important pathes
            MissingProjects = []
            ImportantWantedProjects = []
            add_share_sub_projects = True
            while len(FromProjectDict) > 0:
                ActProject = FromProjectDict.pop()
                if ActProject not in ToProjectDict:
                    MissingProjects.append(ActProject)
                    ActProjectDirName = os.path.dirname(ActProject)
                    if ActProject not in ImportantWantedProjects:
                        for Share in FromSharesDict:
                            if Share[self.TO] != 0:
                                if ActProjectDirName in Share[self.TO]:
                                    if ActProject not in ImportantWantedProjects:
                                        if len(Share[self.TO].replace(ActProjectDirName, "").strip("/").split("/")) > 2:
                                            ImportantWantedProjects.append(ActProject)
                                            add_share_sub_projects = False
                                            break

            for missing in sorted(MissingProjects):
                if missing in ImportantWantedProjects:
                    self.Log("Error",
                             "Important Project %s is missing in target (to) path %s, please add it to the tareget path" % (
                                 missing, self.ToPath))
                elif add_share_sub_projects == True:
                    self.Log("Info",
                             "Project %s is missing in target (to) path %s or has no shared sub projects, first try to resart the script or add the project to the tareget path" % (
                                 missing, self.ToPath))

            TargetPathes = []
            for Share in ToSharesDict:
                if Share[self.TO] not in TargetPathes:
                    TargetPathes.append(Share[self.TO])

            if (add_share_sub_projects == True):
                for Share in FromSharesDict:
                    if Share[self.TO] not in TargetPathes:
                        self.Log("Info", "Add from project %s to project %s at devpath %s" % (
                            Share[self.FROM], Share[self.TO], self.ToPath))
                        self.AddSharedSubProject(Share[self.FROM], Share[self.TO], self.ToPath)

                self.Log("Info", "SyncMksPathes successful finished")
            else:
                self.Log("Error",
                         "Important Project(s) missing, please add this projects first to the targer (to) path")

        else:
            self.Log("Error", "Starting project name for sandbox/project not correct")
            self.Log("Info", "Aborted -> exit")


class AddProjectLabelRecursive_obj(mks_obj, xml_obj, mks_config_helper_obj):
    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.Host = "mks-psad"
        self.Port = "7001"
        self.Sandbox = ".\\"
        self.Project = ""
        self.CheckpointLabel = ""
        self.DescriptionEnabled = False
        self.ProjectRevision = ""
        self.Logging = False
        self.LogDir = ".\\"
        self.StartingPjName = "project.pj"

        self.ProjectType = ""
        self.subprojects = {}

    def isInvalidString(self, _str):
        return ((_str == "") or (_str == None))

    def joinMksPath(self, root, path):
        if (root[-10:] == 'project.pj'):
            if (path[-10:] == 'project.pj'):
                return root[:-10] + path
            else:
                print "Error: path is wrong: " + path
        else:
            print "Error: root is wrong: " + root

    def isRevisionValid(self):
        cmd = "si viewprojecthistory --batch --hostname=" + self.Host + " --port=" + self.Port + " --project=" + self.RootScanPath + " --projectRevision=" + self.ProjectRevision
        retval = self.cliProcHandler.SiCLIHandler_wait(cmd, self.cliProcHandler.MODE_RETURN)
        if retval != 0:
            return False

        for line in self.cliProcHandler.getstdout_split():
            content = line.split('\t')
            if len(content) != 1 and len(content) != 7:
                print "Error: something is not correct in"
                print content
                return False

            elif content[0] == self.ProjectRevision:
                if ((content[5] == '') and (content[6] == '')):
                    return True
                else:
                    print "Revision has already at least one label: " + content[5]
                    if self.CheckpointLabel in content[5:]:
                        print "Warning: Checkpoint Label already exists!"
                    bRet = raw_input("Do you still want to add a the new label " + self.CheckpointLabel + "? ")
                    if bRet in ['1', 'true', 'y', 'j', 'ja', 'yes']:
                        return True
                    else:
                        return False

        return False

    def addProjectLabelRecursive(self, projects):
        for project, revision in projects.iteritems():
            cmd = "si addprojectlabel --batch --hostname=" + self.Host + " --port=" + self.Port + " --project=" + project + " --projectRevision=" + revision + " --label=" + self.CheckpointLabel
            self.cliProcHandler.SiCLIHandler_wait(cmd)

            cmd = "si viewproject --batch --hostname=" + self.Host + " --port=" + self.Port + " -N --filter=file:*.pj --project=" + project + " --projectrevision=" + revision
            self.cliProcHandler.SiCLIHandler_wait(cmd)
            localSubprojects = {}
            for line in self.cliProcHandler.getstdout_split():
                lnsplt = line.split()
                if (len(lnsplt) == 4):
                    if lnsplt[2] == 'build-subproject':
                        localSubprojects[self.joinMksPath(project, lnsplt[0])] = lnsplt[3]
                else:
                    print "Warning: something was wrong with " + "".join(lnsplt)

            self.addProjectLabelRecursive(localSubprojects)
            self.subprojects.update(localSubprojects)

    def AddProjectLabel(self, argu):
        ###########
        #
        # AddProjectLabel(self,argu)
        #
        # Description: the AddProjectLabel main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # return false if not all shared sub projects are configured to build, otherwise true
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog AddProjectLabelRecursive [options]
    Example: python %prog AddProjectLabelRecursive -H mks-psad -P 7001 -n AL_..._xx.xx.xx_INT-1 -s .\ -l"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-p", "--project", dest="Project", default="",
                          help="project(the mks direcory of the project) (mandatory or sandbox)")
        parser.add_option("-S", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify is here, e.g ARS301.pj")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                          help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                          help="logging outputfolder")
        parser.add_option("-n", "--checkpointlabel", dest="CheckpointLabel", default="",
                          help="Checkpointing label(name = n), if this argument is not empty you will not be asked for a label ")
        parser.add_option("-d", "--descriptionenabled", dest="DescriptionEnabled", action="store_true", default=False,
                          help="Ask for separate checkpoint description (on/off)")
        parser.add_option("-r", "--projectrevision", dest="ProjectRevision", default="",
                          help="Revision of project to be labelled (mandatory)")

        (options, args) = parser.parse_args(argu)

        self.Host = options.Host
        self.Port = options.Port
        self.Sandbox = options.Sandbox
        self.Project = options.Project
        self.StartPjName = options.StartPjName
        self.Logging = options.Logging
        self.LogDir = options.LogDir
        self.CheckpointLabel = options.CheckpointLabel
        self.DescriptionEnabled = options.DescriptionEnabled
        self.ProjectRevision = options.ProjectRevision

        if (self.isInvalidString(self.ProjectRevision)):
            print "No project revision given."
            self.ProjectRevision = raw_input("Please enter project revision: ")
            if (self.isInvalidString(self.ProjectRevision)):
                print "Aborting."
                sys.exit(1)

        if (self.isInvalidString(self.CheckpointLabel)):
            print "No Label given."
            self.CheckpointLabel = raw_input("Please enter checkpoint label: ")
            if (self.isInvalidString(self.CheckpointLabel)):
                print "Aborting."
                sys.exit(1)

        if (self.isInvalidString(self.Host) or self.isInvalidString(self.Port)):
            print "Host or Port invalid."
            sys.exit(1)

        if (self.isInvalidString(self.Sandbox)):
            if (self.isInvalidString(self.Project)):
                print "Neither sandbox nor project is valid. Aborting."
                sys.exit(1)
            else:
                self.ProjectType = "project"
        else:
            self.ProjectType = "sandbox"
            if not os.path.isdir(self.Sandbox):
                print "Sandbox directory does not exist. Aborting."
                sys.exit(1)

        self.Sandbox = os.path.join(self.Sandbox, self.StartPjName)
        self.Project = os.path.join(self.Project, self.StartPjName)

        self.RootScanPath = 0
        if (self.ProjectType == "sandbox"):
            self.RootScanPath = self.GetProjectPath("sandbox", self.Sandbox)
        elif (self.ProjectType == "project"):
            self.RootScanPath = self.GetProjectPath("project", self.Project)
        else:
            print "ProjectType not found. Aborting."
            sys.exit(1)

        if self.RootScanPath == 0:
            print "Could not find MKS project path. Aborting."
            sys.exit(1)

        if (self.isRevisionValid()):
            self.addProjectLabelRecursive({self.RootScanPath: self.ProjectRevision})

        if self.Logging:
            if len(self.subprojects) == 0:
                print "Nothing was done."
            else:
                print "subprojects labelled with " + self.CheckpointLabel + ":"
                print self.subprojects


class RetargetAndResynchSbx_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Retarget and resynchronize sandbox
    #
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

        self.Project = ""
        self.Sandbox = ""
        self.Revision = ""
        self.StartingPjName = "project.pj"

    def RetargetAndResynchSbxCore(self, Sandbox, CheckpointLabel, StartingPjName="project.pj", Host="mks-psad",
                                  Port="7001"):
        self.Sandbox = Sandbox
        self.CheckpointLabel = CheckpointLabel
        self.StartingPjName = StartingPjName
        self.Host = Host
        self.Port = Port

        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error", "setup host e.g. -H mks-psad")
            return 1
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error", "setup host e.g. -P 7001")
            return 1

        if (not os.path.isdir(self.Sandbox)):
            self.Log("Error", "sandbox directory does not exist e.g. -s D:\\SWProjects\\ARS301\\06_Algorithm")
            return 1

        self.Sandbox = "%s\%s" % (self.Sandbox, self.StartingPjName)

        self.Project = self.GetProjectPath("sandbox", self.Sandbox)
        if (self.Project == 0):
            self.Log("Error", "Could not get project path from sandbox %s" % self.Sandbox)
            return 1

        self.Revision = self.GetRevisionForLabel(self.Project, self.CheckpointLabel)
        if (self.Revision == 0):
            self.Log("Error", "Could not get revision for label %s" % self.CheckpointLabel)
            return 1

        doRetarget = True
        sbxInfo = self.GetRevisionSharedAndPathFromSandboxPath(self.Sandbox)
        curRev = sbxInfo[self.Project]['Revision']
        print "Current revision : %s" % curRev
        print "Target  revision : %s" % self.Revision
        if (curRev == self.Revision):
            self.Log("Error", "Target revision is identical to current revision, no need to retarget, continuing...")
            doRetarget = False

        if (doRetarget):
            print "Telling MKS to retarget sandbox: "
            cmdline_info = 'si retargetsandbox --projectRevision=%s %s' % (self.Revision, self.Sandbox)

            retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
            if (retCode != 0):
                self.Log("Error", "Retarget of sandbox has failed")
                return 1
            print "Retarget done!"

        # now start with resynch
        print "Telling MKS to resynch sandbox: "
        cmdline_info = 'si resync --overwriteChanged --overwriteIfPending --overwriteDeferred --includeDropped -S %s' % (
            self.Sandbox)

        retCode = self.cliProcHandler.SiCLIHandler_poll(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            self.Log("Error", "Resynch of sandbox has failed")
            return 1
        print "Resynch done!"
        return 0

    def RetargetAndResynchSbx(self, argu):
        ###########
        #
        # RetargetAndResynchSbx(self,argu)
        #
        # Description: the RetargetAndResynchSbx main function
        #
        # Parameter:    -argu the command line options and arguments
        #
        # return 0 if ok, != 0 if failed
        #
        # TODO: add parameter check
        #
        ###########
        usage = """usage : %prog RetargetAndResynchSbx [options]"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host", default="mks-psad",
                          help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port", default="7001",
                          help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                          help="sandbox(the direcory of the sandbox which should be retargeted) (mandatory)")
        parser.add_option("-z", "--startPjName", dest="StartPjName", default="project.pj",
                          help="If the starting project is not project.pj specify is here, e.g ARS301.pj")
        parser.add_option("-c", "--checkpointlabel", dest="CheckpointLabel", default="",
                          help="Checkpointing label(name = n), if this argument is not empty you will not be asked for a label ")

        (options, args) = parser.parse_args(argu)

        return self.RetargetAndResynchSbxCore(options.Sandbox, options.CheckpointLabel, options.StartPjName,
                                              options.Host, options.Port)


class CheckoutSubProjectByLabel_obj(mks_obj, xml_obj, mks_config_helper_obj):
    ###########
    #
    # Description: Checkout members of sandbox projects to a given label
    #
    ###########
    def __init__(self):
        mks_obj.__init__(self)
        mks_config_helper_obj.__init__(self)

    def CheckoutSubProjectByLabel(self, projectInSbx, label):
        if (not os.path.isfile(projectInSbx)):
            self.Log("Error",
                     "Sandbox project file '%s' does not exist, enter a valid project file path e.g. 'D:\SWProjects\ARS301\06_Algorithm\project.prj'" % projectInSbx)
            return 1

        # now start with checkout
        print "Telling MKS to checkout label '%s' for subproject '%s':" % (label, projectInSbx)
        cmdline_info = 'si co --noupdate --overwriteChanged --overwriteDeferred -r %s -S %s' % (label, projectInSbx)

        retCode = self.cliProcHandler.SiCLIHandler_wait(cmdline_info, self.cliProcHandler.MODE_RETURN)
        if (retCode != 0):
            return 1
        print "Checkout done!"
        return 0
