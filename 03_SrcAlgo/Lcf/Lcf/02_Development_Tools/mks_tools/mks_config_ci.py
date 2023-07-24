"""
MKS Scripting toolbox: class CheckInMembers_obj


:org:           Continental AG
"""

MEMBER_VERSION = "$Revision: 1.1 $"
print "%s %s" % (__file__, MEMBER_VERSION)

import os
# import copy
# import stat
import sys
import subprocess
import traceback
# import xml.dom.minidom
# import posixpath as posixpath



# import win32com.client
from optparse import OptionParser
# from datetime import datetime, time
# from mks_utils import ProgressBar_obj
from mks_config_tools import mks_obj, logging_obj, xml_obj

def formatExceptionInfo(maxTBlevel=5):
    cla, exc, trbk = sys.exc_info()
    excName = cla.__name__
    try:
        excArgs = exc.__dict__["args"]
    except KeyError:
        excArgs = "<no args>"
    excTb = traceback.format_tb(trbk, maxTBlevel)
    return (excName, excArgs, excTb)


class CheckInMembers_obj(mks_obj, logging_obj, xml_obj):

    """
    Description: Class for automated check-in members
    """

    def __init__(self):
        mks_obj.__init__(self)
        logging_obj.__init__(self)
        xml_obj.__init__(self)
        self.Host = ""
        self.Port = ""
        self.ProjectType = "project"
        self.cpid = ""
        # Flag used for  dryrun of MKS commands e.g. ConfigureSharedSubproject
        self.dryrun = False


    def CheckWorkingFileStatus(self, MemberPath):
        """
        Description:    Compare working revision status with member revision
                      4 possibilities considered:
                      i) WorkingRev same as MemberRev(yes-no)    ii) WorkingFile does not exist(yes-no)    iii) WorkingRev/File Modified (yes-no)   iv)Member Revision is locked (yes-no)
                      If the working revision is different from Member revision , we dont care if it is locked (We intend both revisions to be same)

        Parameters:     MemberPath - Absolute member path in sandbox (path should have '\\' for path separation - to be updated for '\' in future)

        Author: Saad Azam
      
        """
        working_not_member = 'no'  # WorkingRev same as MemberRev, default = no (means working revision is same as member revision)
        member_nonexistant = 'no'  # WorkingFile does not exist, default = no (means working file exists)
        member_modified = 'no'  # WorkingRev/File Modified, default = no (means Member not modified)
        member_locked = 'no'  # MemberRev already locked, default = no (means MemberRev not locked)

        working_rev = ''

        cmdline_info = 'si viewsandbox --fields=name,memberrev,workingrev,wfdelta,lockrecord,workingcpid ' + MemberPath  # Returns the member names, MemberRevision and details if working file is different from MemberRevision

        error = 0

        try:
            base_path = MemberPath[:MemberPath.rfind('\\')]
            workingDir = os.getcwd()
            os.chdir(base_path)
            # print "New working directory %s" % workingDir
            proc = subprocess.Popen(cmdline_info, shell=True, bufsize=-1, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            # self.Log("Info", stdout_str)
            if len(stderr_str) != 0:
                self.Log("Debug", cmdline_info)
                self.Log("Info", stderr_str.rstrip('\r\n'))
            os.chdir(workingDir)

        except OSError, ValueError:
            self.Log("Error", "Exception: %s\n%s\n%s" % formatExceptionInfo())
            error = 1
            return error

        lockcpid = ''
        memstatus = stdout_str

        # MemberPath  = memstatus.split()[0]
        member_rev = memstatus.split()[1]
        if len(memstatus.split()) > 2:
            working_rev = memstatus.split()[2]

        if member_rev != working_rev:
            working_not_member = 'yes'
            # print memstatus
        if memstatus.find('No working') != -1:
            member_nonexistant = 'yes'
            # print memstatus
        if memstatus.find('newer') != -1 or memstatus.find('older') != -1:
            member_modified = 'yes'
            # print memstatus
        if memstatus.find('exclusive') != -1:
            member_locked = 'yes'
            lockcpid = memstatus[memstatus.rfind(' ') + 1:-1]
            # print memstatus
        status_list = [member_rev, working_rev, working_not_member, member_nonexistant, member_modified, member_locked, lockcpid]
        MemberStatus = {MemberPath:status_list}
        return MemberStatus


    def GetMemberRevisionCfg(self, SandboxPath):
        """
        GetMemberRevisionCfg(self, SandboxPath)
        
        Description: Return a string containing names and member revisions of the config xml files at the input SandboxPath
                     (This will later be used as a description for the libs, dlls and sdls to be checked in)
        
        Parameter: SandboxPath - Path for the base sandbox directory
        
        return 0, if the path does not exist
        
        Author: Saad Azam
        """
        error = 0
        cfg_files = []
        description = ''
        ConfigFileName = 'shared_project_config_files.xml'
        base_cfg_file_path = os.path.join(SandboxPath, ConfigFileName)
        if os.path.isfile(base_cfg_file_path) == False:
            self.Log("Error", "Config file %s does not exist" % ConfigFileName)
            error = 1
            return  error

        CfgFile = self.get_a_document(base_cfg_file_path)
        FileNodes = CfgFile.getElementsByTagName("ConfigSharedProjectsFiles").item(0)

        counter = 0
        for FileCfg in FileNodes.childNodes:
            if (FileCfg.nodeType == FileCfg.ELEMENT_NODE):
                cfg_file = FileCfg.getAttribute("File")
                cfg_files.append(cfg_file)
                cfg_file_path = os.path.join(SandboxPath, cfg_file)
                if os.path.isfile(cfg_file_path) == False:
                    self.Log("Error", "Config file %s does not exist" % ConfigFileName)
                    error = 1
                    return  error
                member_revision = self.GetMemberRevisionSandbox (cfg_file_path)
                cfg_files[counter] = cfg_files[counter] + ' Revision: ' + member_revision + ', '
                counter = counter + 1
        description = ''.join(cfg_files)
        return description


    def LockCheckinUpdate (self, SandboxPath, MemberPath, CpId, label, description, DescEnabled, DescIntegration, addlabel):
        """
        LockCheckinUpdate (self, SandboxPath, MemberPath, change_package_id, label, description, DescEnabled, DescIntegration, addlabel)
        
        Description: The function locks, checks in the member in sandbox and update it to the member revision in mks
        
        Parameter: SandboxPath       - Base path of the sandbox (particularly useful when the function is used in function 'CheckinMembers' to add special description)
                   MemberPath        - Sandbox path to the member to be checked in
                   CpId              - Change package id
                   label             - label (label of th member to be checked in, if label = '', then check the flag -> addlabel -> if true prompt user to enter label
                                       else check in with the empty label)
                   addlabel          - True\False, if True user is prompted to enter the label (original label shall be overwritten)
                   description       - description of the member to be checked in 
                   DescEnabled       - True\False, if True user is prompted to enter the description (original description shall be overwritten)
                   DescIntegration   - True\False, Flag to determine if we intend to check in members for algo integration,
                                       if True description shall be automatically entered as the name and member revisions of the shared config xml
                                       files, this is only intended for algo integration and is used in 'CheckinMembers' function
        Author: Saad Azam
        """
        error = 0
        self.Log("Info", "-"*80)
        ############################## Lock Member ##############################
        lock = self.LockMemberSandbox (MemberPath, CpId, self.Host, self.Port)
        if lock == 1:
            # error log from LockMemberSandbox()
            error = 1
            return error
        else:
            if addlabel == True:
                label = raw_input("Please Enter the Label: ")
                self.Log("Info", "\n")

            if DescEnabled == True and DescIntegration == False:
                description = raw_input("Please Enter the Description: ")
                self.Log("Info", "\n")
            elif DescEnabled == True and DescIntegration == True:
                description = self.GetMemberRevisionCfg(SandboxPath)
                if description == 1:
                    # error log from GetMemberRevisionCfg()
                    error = 1
                    return  error
        #########################################################################
        
        ############################ Check-in member ############################
            checkin, output_str = self.CheckIn(MemberPath, CpId, label, description, self.Host, self.Port)
            unlock = 0
            if checkin == 1:
                self.Log("Error", "Could not checkin the member %s , the member will now be unlocked ..." % MemberPath)
                unlock = self.UnlockMember(MemberPath)  # Unlock if the checkin fails
                error = 1
                return error
            else:
                # Check whether the member is still locked after the checkin returns 0 (success), this means the member was not really modified to checkin did nothing
                MemberStatus = self.CheckWorkingFileStatus(MemberPath)
                if MemberStatus == 1:
                    self.Log("Error", "Please check if the member path %s is valid" % MemberPath)
                    return MemberStatus
                for Path in MemberStatus:
                    if output_str.find('Checked in revision') == -1:
                        self.Log("Info", "Could not checkin the member %s because mks shows it as modified while its actually not, mks bug, the member will now be unlocked ..." % MemberPath)
                        unlock = self.UnlockMember(MemberPath)
                        self.member_not_modified_list.append(Path)
                        checkin = 1
        #########################################################################
        
        ######################### Update Member revision ########################
                if checkin == 0:
                    update_member_revision = self.UpdateWorkingToMember(MemberPath, CpId, self.Host, self.Port)
                    if checkin == 1:
                        self.Log("Error", "Could not update the working to member revision ")
                        error = 1
                        return error
                    self.Log("Info", "-"*80)
        #########################################################################
        if lock == 0 and checkin == 0 and update_member_revision == 0 and unlock == 0:
            return error
        else:
            error = 1
            return error


    def CheckInMembers(self, argu):
        """
        CheckinMembers(self, argu)
        Description:    Check in and update to the member revision all the members provided with the command line options, two types of inputs are acceptable
                        1) A comma seperated list of sandbox projects provided using -s (relative path, see the help for option -s)
                           All members belonging to the sandboxpath including subsandboxes (only non build and non shared) shall be checked in
                        2) A comma seperated list of individual member sandbox locations provided using -f (relative path, see the help for option -f)
                        
                        For both 1 and 2, only members fulfilling following conditions would be checked in:
                            a) Working revision = Member revision
                            b) Working revision not locked already 
                            c) Working revision does exist in the sandbox
                            d) Working revision modified

        Options:        See the options defined below

        Author:         Saad Azam, 01.06.2015
        
        """
        usage = """usage : %prog CheckinMembers [options] Example: python %prog CheckinMembers -p MFL420TA46_2.1.10 -s D:/mks/MFL420TA36_R2.1.0/ -r 06_Algorithm/04_Engineering/05_Deliverables/lib/project.pj,06_Algorithm/04_Engineering/05_Deliverables/dll/project.pj -f 06_Algorithm\04_Engineering\05_Deliverables\dll\algo\vodca_sim\sim_swc_vodca.dll"""
        parser = OptionParser(usage)
        parser.add_option("--scantype", dest="ScanType", default="variant-nonshared",
                  help="scantype to select what kind of subprojects in the sandbox be scanned, should have only one of these 2 values 'variant-nonshared' or 'all'")
        parser.add_option("-s", "--sandbox", dest="Sandbox", default="",
                  help="sandbox(the direcory of the sandbox which should be configured with the starting project.pj file) (mandatory or project)")
        parser.add_option("-r", "--RelSubProjectList", dest="RelSubProjectList", default="",
                  help="Comma seperated list of SubProject paths in project\sandbox whose members need to be checked in e.g 06_Algorithm//04_Engineering//05_Deliverables//lib//")
        parser.add_option("-f", "--MemberList", dest="MemberList", default="",
                  help="Comma seperated list of file\member paths in sandbox whose members need to be checked in e.g 06_Algorithm//04_Engineering//05_Deliverables//dll//algo//ped_sim//sim_swc_ped.dll")
        parser.add_option("-y", "--dryrun", dest="dryrun", action="store_true", default=False,
                  help="Switch to control if the function should perform only a dryrun(default-no lock-checkIn-update in mks) or the actual lock-checkIn-update operation (dryrun=False)")
        parser.add_option("-H", "--Host", dest="Host",
                  help="e.g. mks-psad (mandatory)", metavar="mks-psad")
        parser.add_option("-P", "--Portconfig", dest="Port",
                  help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-C", "--ChangePackage", dest="CpId", default="",
                  help="changePackeageID e.g. 33131:1 (mandatory)")
        parser.add_option("--addlabel", dest="addlabel", action="store_true", default=False,
                  help="Flag to determine if it is desired to add a common label to all the members to be checked in")
        parser.add_option("-e", "--descriptionenabled", dest="DescriptionEnabled", action="store_true", default=False,
                  help="Ask for separate checkpoint/member description (on/off)")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                  help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir", default='.\\',
                  help="logging outputfolder")
        parser.add_option("--logfile", dest="LogFileName", default='logging_CheckinMembers',
                  help="logging file name")
        parser.add_option("--desc", dest="Description", default='Same as Label',
                  help="Description of the member to be checked in, will be overwritten unless DescriptionEnabled and DescriptionIntegration are both 'False' ")
        # Special option specific to algo integration
        parser.add_option("--descInt", dest="DescriptionIntegration", action="store_true", default=False,
                  help="To be used with DescriptionEnabled == True, if True the description would be the member revisions of all the config xml files ")
        parser.add_option("--checklib", dest="CheckLibModified", action="store_true", default=False,
                  help="If True an error will be thrown if a non modified lib or dll is found during checkin, this is to be used with clean build option durining integration as we expect all libs and dlls to be rebuilt otherwise we suspect a build failure or a lib not built at all")
        # add user/password option (same as MKS si commandline)
        parser.add_option("--user", dest="User", default="",
                  help="e.g. uidx1234 (optional)")
        parser.add_option("--password", dest="Password", default="",
                  help=" e.g. x12234x (optional)")


        (options, args) = parser.parse_args(argu)
        self.Host = options.Host
        self.Port = options.Port
        self.LogDir = options.LogDir
        self.Logging = options.Logging
        self.LogFileName = options.LogFileName
        self.dryrun = options.dryrun
        change_package_id = options.CpId
        addlabel = options.addlabel
        SandboxPath = options.Sandbox
        SubProjectList = options.RelSubProjectList
        MemberList = options.MemberList
        ScanType = options.ScanType
        DescEnabled = options.DescriptionEnabled
        DescIntegration = options.DescriptionIntegration
        CheckLibModified = options.CheckLibModified
        label = ''
        description = options.Description
        # user/password is stored in the class mks_obj
        self.SetUidPw(options.User, options.Password)
        print "options.User=%s" % (options.User)
        print "options.Password=%s" % (options.Password)


        self.LogType["Info"] = 1
        self.LogType["Debug"] = 1

        error = 0
        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            self.Log("Error", "log directory does not exist e.g. -o c:\temp \n")
            error = 1
            return error
        else:
            logTypes = {}
            logTypes["Info"] = 1
#            logTypes["Warn"]=2
#            logTypes["Debug"]=3
            if self.Logging == True:
                logfile = os.path.join(self.LogDir, self.LogFileName)
                print "logfile=%s" % (logfile)
                if (os.path.isfile(logfile) is True):
                    if (self.RenameFileAndAddDateTime(logfile) != 0):
                        self.Log("Error", "RenameFileAndAddDateTime fails")

                self.SetupLogging(logfile, "file", self.LogType)
            else:
                self.SetupLogging(logfile, "console", self.LogType)


        no_subproject_input = 0
        no_member_input = 0

        # check dryrun
        if ((self.dryrun != True) and (self.dryrun != False)):
            self.Log("Error", "Wrong value for the 'dryrun', it should either be logical True or False")
            error = 1
            return error
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

        WorkingPath = os.path.join(SandboxPath, 'project.pj')
        error = self.ValidateSandboxPath(WorkingPath, 'dir')
        if error == 1:
            self.Log("Error", 'Input sandbox path %s could not be validated' % WorkingPath)
            return error
        ActDevPath = self.GetCurrentDevPath(WorkingPath)

        self.Log("Info", "Working development path will be: " + ActDevPath)
        if ActDevPath == 0:
            self.Log("Error", "Please check if the mks-server is connected and running")
            error = 1
            return error
        # self.Log("Info", 'Development path is: %s' % (ActDevPath))


        if self.dryrun == False:
            if change_package_id == "":
                change_package_id = raw_input("Please Enter your change package id: ")
                self.Log("Info", "Change Package used: %s\n" % change_package_id)
                error = self.IsChangePackageValid(change_package_id, self.Host, self.Port)
                if error == 1:
                    return error
            else:
                error = self.IsChangePackageValid(change_package_id, self.Host, self.Port)
                if error == 1:
                    return error


        self.working_not_member_list = []
        self.member_nonexistant_list = []
        self.member_modified_list = []
        self.member_not_modified_list = []
        self.member_locked_list = []
        self.lock_ci_update_failure_list = []
        self.locked_checkedin_updated_list = []

        ############## Validate the subproject paths first ###########################
        '''
        With this validation will be done twice because ValidateSandboxPath is also called within GetNotSharedMemberDict
        but this is needed for CheckInMembers function to validate all subprojects paths before starting validation of individual
        members and performing lock-checkin-update.
        '''
        for SubProjPath in SubProjectList.split(','):
            # Check validity of the MemberList and SubProjectList (atleast one of these input options should be valid)
            if ((SubProjPath == "") or (SubProjectList == None)):
                no_subproject_input = 1
                if no_subproject_input == 1 and no_member_input == 1:
                    self.Log("Error", "At least a valid subproject path or a member path or a comma seperated list of subproject/member paths should be given e.g -f 06_Algorithm\\04_Engineering\\05_Deliverables\\dll\\algo\\ped_sim\\sim_swc_ped.dll -s 06_Algorithm\\04_Engineering\\05_Deliverables\\lib\\project.pj")
                    error = 1
                    return error
            else:
                no_subproject_input = 0
                complete_path = os.path.join(SandboxPath, SubProjPath)
                error = self.ValidateSandboxPath(complete_path, 'dir')
                if error == 1:
                    self.Log("Error", 'Input sandbox path %s could not be validated' % WorkingPath)
                    return error
        ##############################################################################


        ################# Validate and CheckIn Members from the relative path (or path list) provided using option -f #################
        self.Log("Info", "Member status info: MemberStatus = {MemberPath:member_rev, working_rev, working_not_member,member_nonexistant,member_modified, member_locked}")
        AbsMemberPathList = ''
        for InputMemberPath in MemberList.split(','):
            if ((InputMemberPath == "") or (InputMemberPath == None)):
                no_member_input = 1
            else:
                # Get absolute path and validate it
                typeflag = 'file'
                ActMemberPath = os.path.join(SandboxPath, InputMemberPath)
                error = self.ValidateSandboxPath(ActMemberPath, typeflag)
                if error == 1:
                    self.Log("Error", 'Input sandbox path %s could not be validated' % ActMemberPath)
                    return error
                # ActMemberPath = self.GetAbsolutePath(InputMemberPath,typeflag)
                MemberStatus = self.CheckWorkingFileStatus(ActMemberPath)
                if MemberStatus == 1:
                    self.Log("Error", "Please check if the member path %s is valid" % ActMemberPath)
                    return MemberStatus
                # Not a real list, just a concatination of all Absolute Memberpaths to be compared with Subproject Memberlist, to avoid double operation
                AbsMemberPathList = AbsMemberPathList + ' ' + ActMemberPath
                for Path in MemberStatus:
                    if MemberStatus[Path][2] == 'yes':
                        self.working_not_member_list.append(Path)
                    if MemberStatus[Path][3] == 'yes':
                        self.member_nonexistant_list.append(Path)
                    if MemberStatus[Path][4] == 'yes':
                        self.member_modified_list.append(Path)
                    elif MemberStatus[Path][4] == 'no':
                        self.member_not_modified_list.append(Path)
                    if MemberStatus[Path][5] == 'yes':
                        lockcpid = MemberStatus[Path][6]
                        # only append the member in 'already locked' list if the member is locked with a different change package id as compared to the input change package id
                        if lockcpid != change_package_id:
                            self.member_locked_list.append(Path)

                # print '\n'
                # print MemberStatus
                # LockCheckinUpdate (SandboxPath, MemberPath, change_package_id, label, description, DescEnabled, DescIntegration)
                if ''.join(self.working_not_member_list).find(Path) == -1 and ''.join(self.member_nonexistant_list).find(Path) == -1 and ''.join(self.member_not_modified_list).find(Path) == -1 and ''.join(self.member_locked_list).find(Path) == -1:
                    Revision = self.CheckWorkingFileStatus(ActMemberPath)[ActMemberPath][1]
                    if self.dryrun == False:
                        Lock_Checkin_Update = self.LockCheckinUpdate (SandboxPath, ActMemberPath, change_package_id, label, description, DescEnabled, DescIntegration, addlabel)
                        if Lock_Checkin_Update == 0:
                            self.locked_checkedin_updated_list.append(Path)
                        else:
                            if ''.join(self.member_not_modified_list).find(Path) == -1:
                                self.lock_ci_update_failure_list.append(Path)


        self.Log("Info", "\n")


        ############################ Validate and CheckIn Members from the relative subproject path (or path list) provided using option -s #################################
        if no_subproject_input == 0:
            for SubProjPath in SubProjectList.split(','):
                # Get a dictionary of members belonging to the non shared non build subprojects from the input subproject path
                member_dict = self.GetNotSharedMemberDict(SandboxPath, SubProjPath, ScanType)
                if member_dict == 1:
                    full_path = os.path.join(SandboxPath, SubProjPath)
                    self.Log("Could not get the member dictionary for sandbox path %s" % full_path)
                # print member_dict
                self.Log("Info", "Member status info: MemberStatus = {MemberPath:member_rev, working_rev, working_not_member, member_nonexistant, member_modified, member_locked}\n")
                for SubprojectPath in member_dict:
                    for MemberPath in member_dict[SubprojectPath]:
                        if AbsMemberPathList.find(MemberPath) == -1:
                            MemberStatus = self.CheckWorkingFileStatus(MemberPath)
                            if MemberStatus == 1:
                                self.Log("Error", "Please check if the member path %s is valid" % ActMemberPath)
                                return MemberStatus
                            for Path in MemberStatus:
                                if MemberStatus[Path][2] == 'yes':
                                    self.working_not_member_list.append(Path)
                                if MemberStatus[Path][3] == 'yes':
                                    self.member_nonexistant_list.append(Path)
                                if MemberStatus[Path][4] == 'yes':
                                    self.member_modified_list.append(Path)
                                elif MemberStatus[Path][4] == 'no':
                                    self.member_not_modified_list.append(Path)
                                if MemberStatus[Path][5] == 'yes':
                                    lockcpid = MemberStatus[Path][6]
                                    # only append the member in 'already locked' list if the member is locked with a different change package id as compared to the input change package id
                                    if lockcpid != change_package_id:
                                        self.member_locked_list.append(Path)
                            # print MemberStatus

                            if ''.join(self.working_not_member_list).find(Path) == -1 and ''.join(self.member_nonexistant_list).find(Path) == -1 and ''.join(self.member_not_modified_list).find(Path) == -1 and ''.join(self.member_locked_list).find(Path) == -1:
                                Revision = self.CheckWorkingFileStatus(MemberPath)[MemberPath][1]
                                if self.dryrun == False:
                                    Lock_Checkin_Update = self.LockCheckinUpdate (SandboxPath, MemberPath, change_package_id, label, description, DescEnabled, DescIntegration, addlabel)
                                    if Lock_Checkin_Update == 0:
                                        self.locked_checkedin_updated_list.append(Path)
                                    else:
                                        if ''.join(self.member_not_modified_list).find(Path) == -1:
                                            self.lock_ci_update_failure_list.append(Path)
                self.Log("Info", "\n")


        if self.dryrun == False:
            if len(self.locked_checkedin_updated_list) > 0:
                self.Log("Info", "-"*80)
                self.Log("Info", "List of Members Locked-CheckedIn-Updated(Member to Working Revision): ")
                self.Log("Info", "-"*80)
                for mem in self.locked_checkedin_updated_list:
                    self.Log("Info", " " + mem + "\n")
        else:
            if len(self.member_modified_list) > 0:
                self.Log("Info", "-"*80)
                self.Log("Info", "List of Members with modified Working Revision: ")
                self.Log("Info", "-"*80)
                for mem in self.member_modified_list:
                    self.Log("Info", " " + mem + "\n")


        if self.dryrun == False:
            self.Log("Info", "Following members couldnot be locked and checked in due to the following reasons: \n")
        if len(self.working_not_member_list) > 0:
            error = 1
            self.Log("Info", "-"*60)
            self.Log("Error", "List of Members with Working Revision != Member Revision: ")
            self.Log("Info", "-"*60)
            for mem in self.working_not_member_list:
                self.Log("Info", " " + mem + "\n")

        if len(self.member_nonexistant_list) > 0:
            error = 1
            self.Log("Info", "-"*60)
            self.Log("Error", "List of Members with non-existent Working Revision: ")
            self.Log("Info", "-"*60)
            for mem in self.member_nonexistant_list:
                self.Log("Info", " " + mem + "\n")

        if len(self.member_locked_list) > 0:
            error = 1
            self.Log("Info", "-"*60)
            self.Log("Error", "List of Members with already locked (with a different change package id) Working Revision: ")
            self.Log("Info", "-"*60)
            for mem in self.member_locked_list:
                self.Log("Info", " " + mem + "\n")

        if len(self.lock_ci_update_failure_list) > 0:
            error = 1
            self.Log("Info", "-"*60)
            self.Log("Error", "List of Members with lock - checkin - update member revision failures: ")
            self.Log("Info", "-"*60)
            for mem in self.lock_ci_update_failure_list:
                self.Log("Info", " " + mem + "\n")

        checklib_error = 0
        if len(self.member_not_modified_list) > 0:
            self.Log("Info", "-"*60)
            self.Log("Info", "List of Members with non-modified Working Revision: ")
            self.Log("Info", "-"*60)
            for mem in self.member_not_modified_list:
                self.Log("Info", " " + mem + "\n")
                if CheckLibModified == True:  # Only to be used with the checklib option in case of algo integrations
                    if mem.find(".dll") != -1 or mem.find(".lib") != -1 or mem.find(".a") != -1 or mem.find(".pdb") != -1:
                        checklib_error = 1

        if checklib_error == 1:
            error = 1
            self.Log("Info", "-----------------------------------------------------------------------------------------------------------------------------------------------------------------")
            self.Log("Error", "!!!!!!!!!!!! Some of the libs and dlls are still not modified despite a clean build, please check List of Members with non-modified Working Revision !!!!!!!!!!!!")
            self.Log("Info", "-----------------------------------------------------------------------------------------------------------------------------------------------------------------")

        return error
