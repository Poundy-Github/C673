"""
@author: Nassim Ibrouchene
@summary: Compares the contents of two checkpoints and checks if the changes are all expected
@design: Provide two CPs and a release item as arguments. Diff the CPs and obtain a list of change packages.
Make sure all change packages are coming from the release items.
"""

import os
import sys
import subprocess
import re
import optparse
import numpy as np

PRJ = r"/ADAS/SW/Components/<COMPNAME>/project.pj"
BLACKLIST = ["GA", "CML", "JOINT", "02_Development_Tools"]

class IMSConnection():

    def __init__(self, hostname='ims-adas', user=os.environ.get('USERNAME'), pwd=''):
        self.hostname = hostname
        self.user = user
        self.pwd = pwd
        self.si = False
        self.im = False
        self.__SIConnect()
        self.__IMConnect()

    def __SIConnect(self):
        """ Connects to SI
        """
        try:
            if(self.pwd == ''):
                # use gui to get password
                command = 'si connect --hostname=' + self.hostname + ' --port=7001' + ' --user=' + self.user + ' --forceConfirm=yes -g'
            else:
                # stay in batch mode and use provided password
                command = 'si connect --hostname=' + self.hostname + ' --port=7001' + ' --user=' + self.user + ' --password=' + self.pwd + ' --batch --forceConfirm=yes'

            proc = subprocess.Popen(command, shell=True)
            proc.wait()
        except:
            print "MKS-SI login not possible"
            raise
        else:
            self.si = True
#             print "SI connection is live"

    def __IMConnect(self):
        """ Connects to IM
        """
        try:
            if(self.pwd == ''):
                # use gui to get password
                command = 'im connect --hostname=' + self.hostname + ' --port=7002' + ' --user=' + self.user + ' --forceConfirm=yes -g'
            else:
                # stay in batch mode and use provided password
                command = 'im connect --hostname=' + self.hostname + ' --port=7002' + ' --user=' + self.user + ' --password=' + self.pwd + ' --batch --forceConfirm=yes'

            proc = subprocess.Popen(command, shell=True)
            proc.wait()
        except:
            print "MKS-SI login not possible"
            raise
        else:
            self.im = True
#             print "IM connection is live"

    def ExecuteCommand(self, Cmd):
        """ Executes the cmd given
        @param Cmd: A PTC command.
        @return: Standard output string after executing the command.
        """
        stderr_str = ''
        try:
            proc = subprocess.Popen(Cmd, shell=True, bufsize=-1, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            stdout_str = stdout_str.strip("\r\n")
            stderr_str = stderr_str.strip("\r\n")
            return stdout_str, stderr_str
        except:
            print 'Command ' + Cmd + 'could not be executed : ' + stderr_str


    def DoesCheckpointExist(self, cp):
        if self.si is True:
            command = "si viewproject --project=" + PRJ + " --projectrevision=" + cp + " -N"
            return self.ExecuteCommand(command)[1]

    def CheckItemType(self, id):
        if self.im is True:
            command = 'im issues --fields=Type %d' % id
            return self.ExecuteCommand(command)[0]

    def ViewCheckpointDifferences(self, cp1, cp2):
        if self.si is True:
            command = "si mods --project=" + PRJ + " -r" + cp1 + " -r" + cp2 + " --noshowChangePackages --showMemberChanges --recurse"
            return self.ExecuteCommand(command)[0]

    def ViewRevisionInformation(self, proj, file, rev):
        if self.si is True:
            command = "si revisioninfo --project=" + proj + " -r" + rev + " " + " --changePackage --nolabels --nolocate " + file
            return self.ExecuteCommand(command)[0]

    def GetReleasePlannedItems(self, release_id):
        if self.im is True:
            command = 'im issues --fields="Planned Items" %d' % release_id
            return self.ExecuteCommand(command)[0]

    def GetReleaseStructureElement(self, release_id):
        if self.im is True:
            command = 'im issues --fields="Structure Element" %d' % release_id
            return self.ExecuteCommand(command)[0]

def SetProject(structure_element):
    """ Sets the global variable PRJ to the correct project using the structure element.
    @param structure_element: The structure element from the release.
    """
    match_se = re.findall("(\w+_\w+)", structure_element)
    if len(match_se) == 0 or len(match_se) > 1:
        print "Invalid structure element (%s) or non existant ID" % structure_element
        sys.exit(1)
    global PRJ  # Global declaration needed in python
    PRJ = PRJ.replace("<COMPNAME>", match_se[0])

def ParseCheckpointDifferences(input_string):
    """ Parses the output of the si mods command and stores the necessary information into an output structure
    @param input_string: The string output of the command 'si mods'
    @return: A List of tuples where each tuple contains three entries: project path, filename and revision
    @attention: Does not handle drop events like member dropped.
    """
    changes = []
    last_subprj = ""
    for line in input_string.splitlines():
        if ("Subproject" in line) or ("subproject" in line):  # Used to find the path to the member
            match_prj = re.findall("(/ADAS[^\s]+)", line)
            if len(match_prj) == 0:
                print line
            last_subprj = match_prj[0]
            continue
        else:
            match_add = re.findall("Added member:\s*(\w+\.\w+)\s*now\s*at\s*revision\s*(\d+.\d+)", line)
            if len(match_add) > 0:
                changes.append((last_subprj, match_add[0][0], match_add[0][1]))
                continue
            match_drp = re.findall("Dropped member:\s*(\w+\.\w+)\s*at\s*revision\s*(\d+.\d+)", line)
            if len(match_drp) > 0:
                changes.append((last_subprj, match_drp[0][0], match_drp[0][1]))
                continue
            match_mod = re.findall("Member revision changed:\s*(\w+\.\w+)\s*from\s*(\d+.\d+)\s*to\s*(\d+.\d+)", line)
            if len(match_mod) > 0:
                source_rev = float(match_mod[0][1])
                target_rev = float(match_mod[0][2])
                rev = target_rev
                while rev > source_rev:
                    changes.append((last_subprj, match_mod[0][0], str(rev)))
                    rev = rev - 0.1
    return changes

def ParseROandCPIDs(input_string):
    """ Catches, from the revisioninfo, the change package information (RO:CP).
    @param input_string: The string output of the command 'si revisioninfo'
    @return: RO ID, Change package number
    """
    match_cp = re.findall("(?:ID:\s*)(\d+):(\d+)", input_string)
    try:
        return match_cp[0][0], match_cp[0][1]
    except:
        print "oh oh, exception not handled. Could not find change package information for %s" % input_string

def FindAllDiffROs(ims, checkpoint1, checkpoint2):
    """ Given two checkpoints, lists all changes between them.
    @param ims: An initialised instance of class IMSConnection.
    @param checkpoint1: The "old" checkpoint to be used as a reference. Can either be given by label or by "bubble" ID.
    @param checkpoint2: The checkpoint intended to be done using the release item.
    @return: A dictionary with ROs as keys and change packages as values in a list.
    @note:   Changes happening in the blacklisted subprojects are ignored.
    """
    cp_differences = ims.ViewCheckpointDifferences(checkpoint1, checkpoint2)
    data = {}
    for change in ParseCheckpointDifferences(cp_differences):
        exclude = False
        for bli in BLACKLIST:
            if bli in change[0]:
                exclude = True
        if exclude is False:
        # if ("02_Development_Tools" not in change[0]) and ("GA" not in change[0]):
            ret = ims.ViewRevisionInformation(change[0], change[1], change[2])
            if len(ret) > 0:
                ro, cp = ParseROandCPIDs(ret)
                if ro not in data:
                    data[ro] = []
                data[ro].append(cp)
                l = data[ro]
                data[ro] = list(set(l))
            else:
                print "WARNING: Not able to find revision information for %s in project %s: maybe the archive has been dropped in the current working project?" % (change[1], change[0])
    return data

def ListAllReleaseROs(ims, release_ID):
    """
    @param ims: An initialised instance of class IMSConnection.
    @param release_ID: The ID of the release containing all the planned items for the checkpoint.
    @return: The list of RO IDs (of type string) that can be found in the release's Planned items field.
    """
    planned_items = ims.GetReleasePlannedItems(release_ID)
    planned_items = planned_items.split(", ")
    return planned_items


def InputCheck(ims, releaseID, cp1, cp2):
    """ Checks if the inputs are ok: Is the given release ID really from a release item? do the checkpoint exist?
    @param ims: An initialised instance of class IMSConnection.
    @param release: The release item ID
    @param cp1-cp2: The checkpoints' labels or IDs
    @return: True if inputs are OK, false otherwise.
    """
    ret = ims.CheckItemType(releaseID)
    if ret != "Release":
        print "The ID you provided does not correspond to an item of type 'Release'"
        return False

    SetProject(ims.GetReleaseStructureElement(releaseID))

    # Check the checkpoints
    ret = ims.DoesCheckpointExist(cp1)
    if len(ret) > 0:  # Just check if the standard error output is not empty
        print "Something is wrong with the provided -p argument. Either the checkpoint does not exist at all, or you provided a checkpoint that does not correspond to the structure element of the release item."
        print "Error message: \n %s" % ret
        return False
    ret = ims.DoesCheckpointExist(cp2)
    if len(ret) > 0:  # Just check if the standard error output is not empty
        print "Something is wrong with the provided -c argument. Either the checkpoint does not exist at all, or you provided a checkpoint that does not correspond to the structure element of the release item."
        print "Error message: \n %s" % ret
        return False
    return True

if __name__ == '__main__':
    # Parse input arguments
    opt_parser = optparse.OptionParser()
    opt_parser.add_option("-r", "--rel", dest="release", help="Release ID", default=None)
    opt_parser.add_option("-p", "--cp1", dest="oldcp", help="Previous checkpoint to be compared to, either label or bubble ID", default=None)
    opt_parser.add_option("-c", "--cp2", dest="newcp", help="Current checkpoint for comparison, either label or bubble ID", default=None)
    (options, args) = opt_parser.parse_args()

#     options.release = 965498
#     options.oldcp = "1.53.1.3"
#     options.newcp = "1.68.1.3"

    if (options.release is None or options.oldcp is None or options.newcp is None):
        sys.exit(1)

    try:
        ReleaseID = int(options.release)  # 877366
    except ValueError:
        print "an ID is expected for the release item (e.g. 877283) "
        sys.exit()
    previous_checkpoint = options.oldcp  # "1.19.1.2"
    current_checkpoint = options.newcp  # "1.27.1.2"


    # Create connection to IMS
    IMS = IMSConnection()
    if InputCheck(IMS, ReleaseID, previous_checkpoint, current_checkpoint) is True:
        ro_list = FindAllDiffROs(IMS, previous_checkpoint, current_checkpoint)  # Returns all the RO IDs that commited changes in the project
        release_items = ListAllReleaseROs(IMS, ReleaseID)  # Returns the RO IDs of the planned items for the release

    #     print list(ro_list.keys()) # All ROs that made changes to your project
    #     print release_items # All ROs that were planned for the release

        # Look for undocumented changes. The lookup is only done in one direction.
        undocumented_changes = []
        for ro in list(ro_list.keys()):
            if ro not in release_items:
                undocumented_changes.append(ro)

        if len(undocumented_changes) > 0:
            print "The following RO(s) commited changes but are not part of the Release's planned items", undocumented_changes
        else:
            print "No suspicious activities detected"

#     print ims.test()
