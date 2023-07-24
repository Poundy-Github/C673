"""
stk/mks/si
----------

Module SI (Source Integrity) provides a Interface to the Source Integrity client of MKS.

:undocumented: MksSIException
:undocumented: MksSISingleton
:undocumented: MksSI
:undocumented: MksSIMember
:undocumented: MksSIProject
:undocumented: MksSISandbox

:org:           Continental AG
:author:        Robert Hecker

:creation date: 26.04.2013

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:16CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
import subprocess
import time

# Import STK Modules --------------------------------------------------------------------------------------------------

# Defines -------------------------------------------------------------------------------------------------------------
DEBUG = 0

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class SiException(Exception):
    """
    Si Exception class which prints the Error Code and the message
    from the cli call.

    :author:        Robert Hecker
    :date:          26.04.2013
    """
    def __init__(self, error, message):
        Exception.__init__(self)
        self.error = error
        self.message = message

    def __str__(self):
        return "ErrorCode %d \n %s" % (self.error, self.message)


class Si(object):
    """
    The Si-class provides a Interface to the CommandLine Interface of the
    MKS Source-Integrity.
    With this class you are able to connect to the mks-server, and do some
    actions like CreateSandbox, CheckOutMember, Checkpoint,.....

    This class is a wrapper over the CLI which can normaly used in a cmd-prompt.

    :note:      usage: See two examples below.

    :author:    Robert Hecker
    :date:      26.04.2013

Example 1: (Uses a existing mks server connection)
--------------------------------------------------
.. python::

    #Create Instance of Source Integrity
    si = stk.mks.si.Si()

    # Create Directory for the Sandbox
    sandboxdir = os.path.join(os.path.split(__file__)[0], "MySandbox")

    # Create Sandbox
    si.createsandbox(MKSPROJECT, sandboxdir)

    # Drop MKS Sandbox, but don't delete the files
    si.dropsandbox(sandboxdir)


Example 2: (Creates a new mks server connection)
------------------------------------------------
.. python::

    si = stk.mks.si.Si()

    # Setup a new MKS Connection
    si.connect("heckerr", "Password")

    si.setChangePackageId("106870:1")

    # Create Directory for the Sandbox
    sandboxdir = os.path.join(os.path.split(__file__)[0], "MySandbox")

    # Create Sandbox
    si.createsandbox(MKSPROJECT, sandboxdir)

    # Checkout the file
    mks.co(path)

    # Update a member file
    # Put your code here !!!!

    # Checkin file
    mks.ci(path, "BugFix for wrong KPI calc")

    # Set Member Version of File
    mks.updaterevision(path)

    si.dropsandbox(sandboxdir, "all")

    si.disconnect()
    """
    def __init__(self):
        """
        In the constructor all common needed parameters for all methods
        are initialized.
        """
        self._cpid = ""

    def setChangePackageId(self, changePackageId):
        """
        For some commands a ChangePackageId is needed.
        The ChangePackage Id is a string, and is build from
        the Task Id and the ChangePackageId, separated with
        a doubledot.
        Example: 107998:0

        :param cpid: ChangePackageId
        :type cpid:  string
        :return:     -

        :author:        Robert Hecker
        :date:          26.04.2013
        """
        self._cpid = changePackageId

    def _exeCmd(self, arg):
        """
        Executes the command with the given parameters, and returns
        when executon is finished.

        :param arg: Arguments for cli call
        :type arg:  list of strings
        :return:    Error Code from cli call

        :author:        Robert Hecker
        :date:          26.04.2013
        """

        if(DEBUG):
            temp = ""
            for el in arg:
                temp += el
                temp += " "
            print temp

        # Execute the command
        cli = subprocess.Popen(arg, shell=True, stdin=subprocess.PIPE,
                               stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

        # Wait till cmd is finished
        while(cli.poll() is None):
            time.sleep(1)

        error = cli.returncode

        if(error != 0):
            # Create cli string
            # callstring = ""
            # for el in arg:
            #     callstring += el
            #     callstring += " "

            # Get Return String
            raise SiException(error, cli.stdout.read())

        return error

    def connect(self, user, pwd, hostname="mks-psad", port=7001):
        """
        establishes a connection to an Integrity Server.

        This connection will be used for all other commands till a disconnect is done.
        When the connect method is not used, the cli interface try to use a existing connection
        to the mks server. For example over the GUI Interface.
        Multiple Connections for different Servers are not supported, you must use disconnect
        to disconnect from one host before establishing a connection to another.

        :param user:     MKS-USerName
        :type user:      string
        :param pwd:      Password for MKS-Server
        :type pwd:       string
        :param hostname: Name, of server used for connection
        :type hostname:  string
        :param port:     Port
        :type port:      int
        :return:         -

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("connect")
        arg.append("--hostname=" + hostname)
        arg.append("--port=" + str(port))
        arg.append("--password=" + pwd)
        arg.append("--user=" + user)
        arg.append("--quiet")
        arg.append("--batch")  # without prompting for responses.

        # Execute Command
        return self._exeCmd(arg)

    def disconnect(self):
        """
        disconnects the client connection to the host Integrity Server.

        The disconnect call will disconnect all client connections to the Server,
        also the GUI based connections.

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("disconnect")
        arg.append("--forceConfirm=yes")
        arg.append("--quiet")
        arg.append("--batch")  # without prompting for responses.

        # Execute Command
        return self._exeCmd(arg)

    def createsandbox(self, project, sandboxdir):
        """
        Creates a new sandbox on your local machine.
        The sandbox will be created from the Project specified
        by the project parameter to the path given by the sandboxdir.

        :param project:    mks project path
        :type project:     string
        :param sandboxdir: local dir for sandbox
        :type sandboxdir:  string
        :return:           Error Code
        :note:             The project parameter must start with /nfs/... and
                           end with "/project.pj"
                           Example:
                           "/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/project.pj"

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("createsandbox")
        arg.append("--project=" + project)
        arg.append("--cwd=" + sandboxdir)
        arg.append("--quiet")
        arg.append("--yes")  # Recursive
        arg.append("--batch")  # without prompting for responses.

        # Execute Command
        return self._exeCmd(arg)

    def dropsandbox(self, sandboxdir, delete="none"):
        """
        drops a sandbox

        Following options for delete are possible:
        - "none"
        - "members"
        - "all"

        :param sandboxdir: local dir for sanbox
        :type sandboxdir:  string
        :param delete:     [none|members|all]
        :type delete:      string
        :return:           Error Code

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("dropsandbox")
        arg.append("--forceconfirm=yes")
        arg.append("--batch")  # without prompting for responses.
        arg.append("--delete=" + delete)
        arg.append(sandboxdir + "\\project.pj")

        # Execute Command
        return self._exeCmd(arg)

    def co(self, memberpath, lock=True):
        """
        checks out members into working files in a sandbox

        :param memberpath: sandboxpath to member
        :type memberpath:  string
        :param lock:       lock member
        :type lock:        bool
        :return:           Error Code

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("co")
        if(lock):
            arg.append("-l")
        else:
            arg.append("-u")
        arg.append("--changePackageId=" + self._cpid)
        arg.append(memberpath)

        return self._exeCmd(arg)

    def ci(self, memberpath, desc):
        """
        checks in members of a sandbox

        :param memberpath: sandboxpath to member
        :type memberpath:  string
        :param desc:       check in description
        :type desc:        string
        :return:           Error Code

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("ci")
        arg.append("--changePackageId=" + self._cpid)
        arg.append("--description=" + desc)
        arg.append("--unlock")
        arg.append(memberpath)

        return self._exeCmd(arg)

    def updaterevision(self, memberpath, rev=":head"):
        """
        updates a project member revision to a specified revision

        Following options for rev are possible:
        - Revision Number      1.35
        - Label                Label string to use
        - :head                identifies the head revision.
        - :member              identifies the member revision.
        - :memberbranchtip    identifies the tip revision on the member revision branch.
        - :trunktip           identifies the tip revision on the trunk.

        :param memberpath: local path to member.
        :type memberpath:  string
        :param rev:        [RevNum|Label|:head|...]
        :type rev:         string
        :return:           Error Code

        :author:           Robert Hecker
        :date:             26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("updaterevision")
        arg.append("--changePackageId=" + self._cpid)
        arg.append("--revision=" + rev)
        arg.append("--quiet")
        arg.append("--no")
        arg.append(memberpath)

        return self._exeCmd(arg)

    def checkpoint(self, sandbox, desc, label, labelMembers=False):
        """
        checkpoint archives in a project

        :param sandbox:      local path sandbox.
        :type sandbox:       string
        :param desc:         Checkpoint Description.
        :type desc:          string
        :param label:        Checkpoint Label.
        :type label:         string
        :param labelMembers: Label Members (true/false)
        :type labelMembers:  bool
        :return:             Error Code

        :author:             Robert Hecker
        :date:               26.04.2013
        """
        if(sandbox.endswith(r"\project.pj") is False):
            lsandbox = sandbox + r"\project.pj"
        else:
            lsandbox = sandbox
        arg = []
        arg.append("si")
        arg.append("checkpoint")
        # arg.append("--changePackageId=" + self._cpid)
        arg.append("--quiet")
        arg.append("--description=" + desc)
        if(labelMembers):
            arg.append("--labelMembers")
        else:
            arg.append("--nolabelMembers")
        arg.append("--label=" + label)
        arg.append("--sandbox=" + lsandbox)

        return self._exeCmd(arg)

    def resync(self, path):
        """
        updates a Sandbox, SubSandbox or member file with the member revision

        :param path:      either path to a sanbox (including *.pj file) or
                          path to sandbox subfolder (including *.pj) or
                          path to sandbox member.
        :type path:       string
        :return:          Error Code

        :author:          Robert Hecker
        :date:            26.04.2013
        """
        arg = []
        arg.append("si")
        arg.append("resync")
        arg.append("--quiet")
        arg.append("--batch")  # without prompting for responses.
        arg.append("--recurse")
        arg.append("--forceConfirm=yes")
        arg.append(str(path))

        return self._exeCmd(arg)


#======================================================================================================================
# Imports
#======================================================================================================================
from Queue import Queue
from os import path, environ, makedirs, sep
from re import compile, VERBOSE, IGNORECASE, match
from subprocess import Popen, PIPE, call
import stk.util.logger as log
import win32api
import win32event
import winerror
import warnings

#======================================================================================================================
# Constants declarations
#======================================================================================================================
RET_VAL_OK = 0
RET_VAL_ERROR = -1

#======================================================================================================================
# stkMKSException Class Implementation
#======================================================================================================================


class MksSIException(StandardError):
    """
    MKS exceptions class constructor
    """
    def __init__(self, description):
        self.__description = str(description)

    def __str__(self):
        return str(self.__description)

#======================================================================================================================
# MksSiSingleton Class Implementation
#======================================================================================================================


class MksSISingleton(object):
    """Singleton interface
    @todo Sorin to check usage of the singleton class
    """
    @classmethod
    def __init__(cls, name, bases, bdict):
        super(log.Singleton, cls).__init__(name, bases, bdict)
        cls.instance = None

    @classmethod
    def __call__(cls, *args, **kwargs):
        if cls.instance is None:
            cls.instance = super(log.Singleton, cls).__call__(*args, **kwargs)

        return cls.instance
#======================================================================================================================
# MksSI Class Implementation
#======================================================================================================================


class MksSI(MksSISingleton):
    """MKS Source Integrity class implementation"""
    DEFAULT_SOURCE_INTEGRITY_NAME = "C:\\Program Files\\MKS\\IntegrityClient2009\\bin\\si.exe"
    DEFAULT_HOSTNAME = "mks-psad"
    DEFAULT_PORTNAME = "7001"
    CMD_CONNECT = "connect"
    CMD_DISCONNECT = "disconnect"
    CMD_EXIT = "exit"
    CMD_VIEW_PROJECT = "viewproject"
    CMD_PROJECT_INFO = "projectinfo"
    CMD_PROJECT_CO = "projectco"
    CMD_SANDBOXES = "sandboxes"
    CMD_CREATE_SANDBOX = "createsandbox"
    CMD_DROP_SADNBOX = "dropsandbox"
    CMD_SANDBOX_INFO = "sandboxinfo"
    CMD_VIEW_SANDBOX = "viewsandbox"
    CMD_MEMBER_INFO = "memberinfo"
    CMD_RESYNC = "resync"
    CMD_CHECKOUT = "co"
    CMD_CHECKIN = "ci"

    def __init__(self, hostname, port, psw, siPath=None, username=environ["USERNAME"], confirm="yes",
                 quiet=True, batchMode=True):

        warnings.warn('MksSI() is deprecated, use Si() instead', stacklevel=2)
        self._hostname = hostname
        self._port = port
        self._psw = psw
        if siPath is None:
            self._mks_si_path = self.DEFAULT_SOURCE_INTEGRITY_NAME
        else:
            self._mks_si_path = siPath

        self._force_confirm = confirm
        self._quiet = quiet
        self._batch_mode = batchMode
        self._is_connected = False
        self._err_msg = None
        self._ret_code = None

        self._username = username

        self._mutex = None
        self._lasterror = None

        self._logger = log.Logger(self.__class__.__name__, log.INFO)

        self._aquireMutex()

    def __del__(self):
        self.exit()
        self._releaseMutex()

    def getRequestResult(self):
        """ Return the result of a MKS request (projectinfo)
        """
        return self._ret_code

    def getRequestErrorMessage(self):
        """ Return the error message of a MKS request (projectinfo)
        """
        return self._err_msg

    def _aquireMutex(self):
        """ Aquire the Mutex
        """
        self._mutex = win32event.CreateMutex(None, True, self.__class__.__name__)
        self._lasterror = win32api.GetLastError()
        if self._mutex and self._lasterror == winerror.ERROR_ALREADY_EXISTS:
            win32event.WaitForSingleObject(self._mutex, win32event.INFINITE)

    def _releaseMutex(self):
        """ Release the Mutex
        """
        if self._mutex:
            win32event.ReleaseMutex(self._mutex)
            win32api.CloseHandle(self._mutex)

    def setPort(self, port):
        """Sets the MKS port
        """
        self._port = port

    def setHostname(self, hostname):
        """Sets the MKS hostname.
        """
        self._hostname = hostname

    def executeCommand(self, cmd_arg_list, stdout=None, stderr=None):
        """Executes MKS command.
        @todo: Sorin to check the return code
        """
        ret_code = 0

        if stdout is None and stderr is None:
            p = Popen(cmd_arg_list, stdout=PIPE, stderr=PIPE)
            (_, errmsg) = p.communicate()
            if p.returncode != RET_VAL_OK:
                if len(errmsg):
                    self._logger.error(str(errmsg).split("\r\n")[-2])
                    return RET_VAL_ERROR
            else:
                ret_code = RET_VAL_OK
        else:
            ret_code = call(cmd_arg_list, stdout=stdout, stderr=stderr)

        return ret_code

    def connect(self):
        """ Establishes a connection to an Integrity Server host.
        """
        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_CONNECT]
        si_arg_list += ["--hostname=%s" % self._hostname]

        si_arg_list += ["--user=%s" % self._username]
        si_arg_list += ["--port=%s" % self._port]

        si_arg_list += ["--password=%s" % self._psw]
        if self._batch_mode is True:
            si_arg_list += ["--batch"]

        self._logger.info("Connecting to %s:%s as %s..." % (self._hostname, self._port, self._username))
        ret_code = self.executeCommand(si_arg_list)
        if ret_code:
            ret_code = False

        self._logger.info("Connection to %s:%s as %s successfully done." %
                          (self._hostname, self._port, self._username))

        self._is_connected = True

        return True

    def disconnect(self):
        """ Disconnects the client connection to the host Integrity Server.
        @todo: Sorin to check the return code
        """
        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_DISCONNECT]

        return self.executeCommand(si_arg_list)

    def closeSession(self):
        """ Exits the current MKS Source client session.
        """

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_EXIT]
        si_arg_list += ["--forceConfirm=%s" % self._force_confirm]

        ret_code = self.executeCommand(si_arg_list)

        self._is_connected = False

        return ret_code

    def exit(self):
        """ Exits the current MKS Source client session.
        """
        ret_code = 0

        if self._is_connected:
            self.closeSession()

            self._is_connected = False

        return ret_code

    def isConnected(self):
        """ Is the Class connected to MKS
        """
        return self._is_connected

#======================================================================================================================
# MksSIMember Class Implementation
#======================================================================================================================


class MksSIMember(object):

    # warn("class MksSi will be removed in future! Use Si class instead", DeprecationWarning, stacklevel=2)
    def __init__(self, projectPath, memberName, target_file=None, revision=None, description=None, author=None):
        """ Initialize the MKS SI Member class
        """
        warnings.warn('MksSIMember() is deprecated, use Si() instead', stacklevel=2)

        self.__memberName = memberName
        self.__projectPath = projectPath
        self.__revision = revision
        self.__target_file = target_file
        self.__revision = revision
        self.__description = description
        self.__author = author
        self.__workspace_dirname = None

        self._logger = log.Logger(self.__class__.__name__, log.INFO)

    def setWorkspaceDir(self, workspace_dirname):
        """ Set the Workspace directory
            Construct the self.__target_file based on the previously established relative path and workspace directory
        """
        self.__workspace_dirname = workspace_dirname

        if (self.__target_file[0] == "/"):
            self.__target_file = self.__target_file[1:]

        self.__target_file = path.join(workspace_dirname, self.__target_file).replace("\\", "/")

    def setRevision(self, revision):
        """ Set the revision
        """
        self.__revision = revision

    def getName(self):
        """ Get the Name of the member
        """
        return self.__memberName

    def getProjectPath(self):
        """ Get the project path of the member
        """
        return self.__projectPath

    def getTargetFile(self):
        """ Get the target file
        """
        return path.abspath(self.__target_file)

    def getRevision(self):
        """ Get the member revision
        """
        return self.__revision

    def getDescription(self):
        """ Get the member description
        """
        return self.__description

    def getAuthor(self):
        """ Get the author of the member """
        if self.__author is not None:
            return self.__author
        else:
            return "Unknown"

#======================================================================================================================
# MksSIProject Class Implementation
#======================================================================================================================


class MksSIProject(MksSI):
    """ Mks Project class
    """
    def __init__(self, projectPath, hostname, port, psw, siPath=None, username=environ["USERNAME"],
                 confirm='yes', quiet=True, dev_path=None, batchMode=True):
        MksSI.__init__(self, hostname, port, psw, siPath, username, confirm, quiet, batchMode)

        warnings.warn('MksSIProject() is deprecated, use Si() instead', stacklevel=2)

        self.__projectPath = projectPath
        self.__dev_path = dev_path
        self.__member_obj_list = []
        self.__project_revision = None
        self._logger = log.Logger(self.__class__.__name__, log.INFO)

    def __del__(self):
        """ Class destructor
        """
        MksSI.__del__(self)

    def setProjectPath(self, projectPath):
        """ Set the project path
        """
        self.__projectPath = projectPath

    def getProjectInfo(self, member_list=None, project=None):
        """ Displays current project information.
        @todo: Sorin to check the arguments.
        @return: RET_VAL_OK if passed, RET_VAL_ERROR on Error
        """
        if not self.isConnected():
            if not self.connect():
                return RET_VAL_ERROR

        if member_list is not None:
            if not isinstance(member_list, list):
                member_list = [member_list]

        if project is None:
            project = self.__projectPath

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_PROJECT_INFO]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--project=%s" % project]
        if self.__project_revision is not None:
            si_arg_list += ["--projectRevision=%s" % self.__project_revision]

        if member_list is not None:
            members = " ".join(member_list)
            si_arg_list += [members]

        ret_code, err_msg = Popen(si_arg_list, shell=True, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code

        if len(err_msg) == 0:
            return RET_VAL_OK
        else:
            return RET_VAL_ERROR

    def checkoutProjectMember(self, projectPath, memberName, target_file, revision=None, lock=False, output_file=None):
        """Checks out member of a project into working file.
        """
        if not self.isConnected():
            if not self.connect():
                return RET_VAL_ERROR

        # Make sure the destination directory is created
        if target_file is not None:
            try:
                if not path.isdir(path.dirname(target_file)):
                    makedirs(path.dirname(target_file))
            except Exception, msg:
                self._logger.error(str(msg))
                return RET_VAL_ERROR

        # Build the member checkout command
        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_PROJECT_CO]
        si_arg_list += ["--user=%s" % self._username]
        si_arg_list += ["--password=%s" % self._psw]
        si_arg_list += ["--project=%s" % projectPath]
        si_arg_list += ["--targetFile=%s" % target_file]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--port=%s" % self._port]
        si_arg_list += ["--forceConfirm=%s" % self._force_confirm]
        if lock is False:
            si_arg_list += ["--nolock"]
        else:
            si_arg_list += ["--lock"]\

        if self._batch_mode:
            si_arg_list += ["--batch"]

        if revision is not None:
            si_arg_list += ["--revision=%s" % revision]

        si_arg_list += [memberName]

        # Execute project checkout command
        self._logger.debug("Executing 'si %s' for '%s/%s'." % (self.CMD_PROJECT_CO, projectPath, memberName))
        ret_code = self.executeCommand(si_arg_list, stdout=output_file, stderr=output_file)

        return ret_code

    def viewProject(self, projectPath=None, recurse=False, member_list=None):
        """Displays the contents of a project and some information about the members
        @param project The MKS project path.
        @param member_list The list of the required members or subprojects.
        @return Returns contents of a project and information about required members.
        """
        if not self.isConnected():
            if not self.connect():
                return RET_VAL_ERROR

        if member_list is not None:
            if not isinstance(member_list, list):
                member_list = [member_list]

        if projectPath is None:
            projectPath = self.__projectPath

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_VIEW_PROJECT]

        si_arg_list += ["--user=%s" % self._username]
        si_arg_list += ["--password=%s" % self._psw]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--port=%s" % self._port]
        si_arg_list += ["--project=%s" % projectPath]

        if recurse is True:
            si_arg_list += ["--%srecurse" % "confirm"]
        else:
            si_arg_list += ["--%srecurse" % "no"]

        si_arg_list += ["--fields=%s" % "name,type"]

        if member_list is not None:
            members = " ".join(member_list)
            si_arg_list += [members]

        self._logger.debug("Executing 'si %s' for '%s'." % (self.CMD_VIEW_PROJECT, projectPath))
        result, err_msg = Popen(si_arg_list, shell=True, stderr=PIPE, stdout=PIPE).communicate()

        self._err_msg = err_msg
        self._ret_code = result

        member_info_map_list = []
        for entry in str(result).split("\n"):
            entry = entry.lstrip().rstrip()
            if len(entry) == 0:
                continue
            if entry.find(" ") != -1:
                memberName = entry[0:entry.find(" ")]
                member_type = entry[entry.rfind(" "):len(entry)]
                memberName = memberName.replace("/project.pj", "")
                member_info_map_list.append({'projectPath': projectPath,
                                             'name': memberName.strip(),
                                             'type': member_type.strip()})
            else:
                self._logger.error("Invalid project member: '%s'." % entry)

        return member_info_map_list

    def _parseProject(self, projectPath):
        """ Parse the Project
        """
        project_member_queue = Queue()

        member_info_map_list = self.viewProject(projectPath)

        for member_info_map in member_info_map_list:
            project_member_queue.put(member_info_map)

        self.__member_obj_list = []

        while(not project_member_queue.empty()):
            member_info_map = project_member_queue.get()

            memberName = member_info_map['name']
            member_type = member_info_map['type']
            member_projectPath = member_info_map['projectPath']

            if member_type in ['shared-build-subproject',
                               'shared-variant-subproject',
                               'shared-subproject',
                               'build-subproject',
                               'variant-subproject',
                               'subproject']:
                member_projectPath = member_projectPath.replace("/project.pj", "")
                for member_info_map in self.viewProject(member_projectPath + "/" + memberName):
                    project_member_queue.put(member_info_map)
            elif member_type == 'archived':
                projectPath = projectPath.replace("/project.pj", "")
                idx1 = projectPath.rfind("/")
                idx2 = projectPath.rfind("#")
                if idx1 > idx2:
                    idx = idx1
                else:
                    idx = idx2

                relative_target_file = member_projectPath.replace(projectPath[0:idx + 1], "") + "/" + memberName
                try:
                    mks_member_obj = MksSIMember(member_projectPath, memberName, relative_target_file)
                    self.__member_obj_list.append(mks_member_obj)
                except Exception, msg:
                    self._logger.error(str(msg))
                    return False
            else:
                self._logger.error("Unknown project member type: '%s'." % str(member_type))

        if not len(self.__member_obj_list):
            return False

        return True

    def getProjectMembers(self):
        """ Get Project Members
        """
        if len(self.__member_obj_list):
            return self.__member_obj_list

        return None

    def checkoutProject(self, workspace_dir, revision=None, projectPath=None):
        """Displays the contents of a project and some information about the members
        @param project The MKS project path.
        @param member_list The list of the required members or subprojects.
        @return Returns contents of a project and information about required members.
        """
        if projectPath is None:
            projectPath = self.__projectPath

        projectPath = projectPath.replace("\\", "/")

        ret_code = 0

        try:
            output_filename = path.join(workspace_dir, path.basename(projectPath) + "_checkedout.log")
            if not path.isdir(path.dirname(output_filename)):
                makedirs(path.dirname(output_filename))
            output_file = open(output_filename, "w+")
        except Exception:
            output_file = None

        self._logger.info("Parsing mks project: '%s'. " % projectPath)
        self._parseProject(projectPath)
        member_obj_list = self.getProjectMembers()
        if member_obj_list is None:
            _, ext = path.splitext(projectPath)
            if len(ext):
                relative_target_file = path.join(path.basename(path.dirname(projectPath)),
                                                 path.basename(projectPath))
                mks_member_obj = MksSIMember(path.dirname(projectPath), path.basename(projectPath),
                                             relative_target_file)
                member_obj_list = [mks_member_obj]
            else:
                self._logger.info("Parsing mks project: '%s'. " % projectPath)
                self._parseProject(projectPath)
                member_obj_list = self.getProjectMembers()

        if member_obj_list and len(member_obj_list) != 0:
            self._logger.info("Checking out mks project: '%s'. " % projectPath)
            for member_obj in member_obj_list:
                member_obj.setWorkspaceDir(workspace_dir)
                member_obj.setRevision(revision)
                try:
                    ret_code |= self.checkoutProjectMember(member_obj.getProjectPath(),
                                                           member_obj.getName(),
                                                           member_obj.getTargetFile(),
                                                           member_obj.getRevision(),
                                                           lock=False,
                                                           output_file=output_file)
                except Exception, msg:
                    self._logger.error(str(msg))
                    ret_code = False

            if ret_code == 0:
                self._logger.info("Successfully checked out %d file(s)." % len(member_obj_list))
                ret_code = True
            else:
                self._logger.info("No member(s) checked out.")
                ret_code = False
        else:
            self._logger.info("No member(s) found.")
            ret_code = False

        if output_file:
            output_file.close()

        if ret_code is not False:
            return True

        return False

    def getMemberInfo(self, member_list):
        """Lists current information about a project member.
        This includes general information about the member, and specific\
        information on the member revision
        """
        if not self.isConnected():
            if not self.connect():
                return -1

        if member_list is not None:
            if not isinstance(member_list, list):
                member_list = [member_list]

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_MEMBER_INFO]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--project=%s" % self.__projectPath]
        if self.__project_revision is not None:
            si_arg_list += ["--projectRevision=%s" % self.__project_revision]

        members = " ".join(member_list)

        si_arg_list += [members]

        ret_code, err_msg = Popen(si_arg_list, shell=True, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code

        return ret_code

#======================================================================================================================
# MksSISandbox Class Implementation
#======================================================================================================================


class MksSISandbox(MksSI):
    """ MKS Sandbox """
    def __init__(self, projectPath, hostname, port, psw, siPath=None, username=environ["USERNAME"],
                 project_revision=None, devpath=None, confirm='yes', quiet=True, batchMode=True):

        MksSI.__init__(self, hostname, port, psw, siPath, username, confirm, quiet, batchMode)

        warnings.warn('MksSISandbox() is deprecated, use Si() instead', stacklevel=2)

        self.__devpath = devpath
        self.__project_revision = project_revision
        self.__sandbox_location = None
        self.__batch_mode = batchMode
        self.__file_match = None
        self.__sandboxes = None

        self.__projectPath = projectPath
        if not self.__projectPath.endswith("project.pj"):
            self.__projectPath += "/project.pj"

        self._logger = log.Logger(self.__class__.__name__, log.INFO)

    def __del__(self):
        """ Class destructor
        """
        MksSI.__del__(self)

    def setSandboxLocation(self, location):
        """ Sets sandbox location.
        @param location Specifies the location of the sandbox.
        """
        self.__sandbox_location = location

    def getSandboxLocation(self):
        """ Returns sandbox location
        """
        return self.__sandbox_location

    def GetSandboxes(self, displaysubs=False):
        """Displays sandboxes currently registered on the MKS Source client and\
         the corresponding project, server name, and port number.

         @return: Return None on errors, else a list of sandboxes
        """
        file_match = r"""
                          (?P<%s>((\w:)(\\[-\w\d]+)+\.\w+))
                          ([-\s>]+)
                          (?P<%s>(/[-\w\d]+)+\.\w+)              # project path
                        """ % ("file_path", "projectPath")

        sandbox_match = r"""
                          (?P<%s>((\w:)(\\[\-\w\d\.]+)+\.\w+))   # sandbox path
                          ( [-\s>]+ )
                          (?P<%s>(([-\w\d]+)?/[\-\w\d]+)+\.\w+)  # project path
                          ((\[)
                          (?P<%s>([\w]+:[\-\w\d\.]+))            # sandbox type( e.g. build, variant )
                          (\]))?
                           \s+
                           \(
                          (?P<%s>([\-\w\d\.]+:\d+))              # server name
                           \)
                          ($)
                           """ % ("sandbox", "project", "type", "server_name")

        self.__file_match = compile(file_match, VERBOSE | IGNORECASE)
        self.__sandboxes = compile(sandbox_match, VERBOSE | IGNORECASE)

        if not self.isConnected():
            if not self.connect():
                return -1

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_SANDBOXES]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--user=%s" % self._username]
        si_arg_list += ["--port=%s" % self._port]
        si_arg_list += ["--forceConfirm=%s" % self._force_confirm]
        if self.__batch_mode:
            si_arg_list += ["--batch"]

        if displaysubs:
            si_arg_list += ["--displaySubs"]

        if self._quiet:
            si_arg_list += ["--quiet"]

        ret_code, err_msg = Popen(si_arg_list, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code

        if len(ret_code) == 0:
            return RET_VAL_ERROR

        sandboxes_map = {}
        for sandbox in str(ret_code).split("\n"):
            sandboxes_match = match(self.__sandboxes, sandbox)
            if sandboxes_match is not None:
                sandbox_map = {}
                sandbox_map['project'] = sandboxes_match.group("project")
                if sandboxes_match.group("type") is not None:
                    sandbox_map['type'] = sandboxes_match.group("type").split(':')[0]
                    if sandbox_map['type'] == 'variant':
                        sandbox_map['devpath'] = sandboxes_match.group("type").split(':')[1]
                    elif sandbox_map['type'] == 'build':
                        sandbox_map['projectRevision'] = sandboxes_match.group("type").split(':')[1]
                    else:
                        pass
                else:
                    sandbox_map['type'] = "regular"

                sandbox_map['hostname'] = sandboxes_match.group("server_name").split(':')[0]
                sandbox_map['port'] = sandboxes_match.group("server_name").split(':')[1]

                sandboxes_map[path.dirname(sandboxes_match.group("sandbox")).lower()] = sandbox_map

        if len(sandboxes_map):
            return sandboxes_map

        return None

    def createSandbox(self, sandbox_location, populate=False, recurse=False, output_file=None):
        """Creates a new Sandbox on the client machine in a specified directory.
        """
        if not self.isConnected():
            if not self.connect():
                return False

        # save the sanbox location
        self.__sandbox_location = sandbox_location

        sandboxes = self.GetSandboxes()
        if sandboxes is not None and sandbox_location.lower() in sandboxes:
            return True

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_CREATE_SANDBOX]
        si_arg_list += ["--project=%s" % self.__projectPath]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--user=%s" % self._username]
        si_arg_list += ["--port=%s" % self._port]
        si_arg_list += ["--forceConfirm=%s" % self._force_confirm]
        if recurse:
            si_arg_list += ["--recurse"]
        else:
            si_arg_list += ["--%srecurse" % "no"]

        if self.__devpath:
            # create variant sandbox
            if self.__project_revision:
                si_arg_list += ["--devpath=%s" % self.__project_revision]
        elif self.__project_revision:
            # create build sandbox
            si_arg_list += ["--projectRevision=%s" % self.__project_revision]

        if self._quiet:
            si_arg_list += ["--quiet"]
        if populate:
            si_arg_list += ["--populate"]
        else:
            si_arg_list += ["--nopopulate"]

        si_arg_list += [sandbox_location]

        ret_code = self.executeCommand(si_arg_list, stdout=output_file, stderr=output_file)
        self._err_msg = None
        self._ret_code = ret_code

        return ret_code

    def viewSandbox(self, member_list=None, recurse="no", include_dropped="no"):
        """Displays the contents of a Sandbox
        """
        if not self.isConnected():
            if not self.connect():
                return RET_VAL_ERROR

        if member_list is not None:
            if not isinstance(member_list, list):
                member_list = [member_list]

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_VIEW_SANDBOX]
        si_arg_list += ["--fields=%s%s%s" % ("name", "memberrev", "labels")]
        si_arg_list += ["--%sincludeDropped" % include_dropped]
        si_arg_list += ["--%srecurse" % recurse]

        si_arg_list += ["--sandbox=%s" % self.__sandbox_location]

        if member_list is not None:
            members = " ".join(member_list)
            si_arg_list += [members]

        ret_code, err_msg = Popen(si_arg_list, shell=True, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code

        return ret_code

    def getSandboxInfo(self, member_list=None):
        """Displays current information about a Sandbox.
        @todo: Sorin to check the arguments
        """
        if not self.isConnected():
            if not self.connect():
                return False

        if member_list is not None:
            if not isinstance(member_list, list):
                member_list = [member_list]

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_SANDBOX_INFO]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--sandbox=%s" % self.__sandbox_location]
        if self.__batch_mode:
            si_arg_list += ["--batch"]

        members = " ".join(member_list)

        si_arg_list += [members]

        ret_code, err_msg = Popen(si_arg_list, shell=True, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code

        if len(err_msg) == 0:
            return RET_VAL_OK
        else:
            return RET_VAL_ERROR

    def dropSandbox(self, sandbox_location, delete="all"):
        """Unregisters a Sandbox from the Integrity Client.
        """
        if not self.isConnected():
            if not self.connect():
                return RET_VAL_ERROR

        if delete not in ["none", "members", "all"]:
            return RET_VAL_ERROR

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_DROP_SADNBOX]
        si_arg_list += ["--forceConfirm=%s" % self._force_confirm]
        si_arg_list += ["--delete=%s" % delete]
        si_arg_list += [sandbox_location]
        if self.__batch_mode:
            si_arg_list += ["--batch"]

        ret_code, err_msg = Popen(si_arg_list, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code

        if len(err_msg) == 0:
            return RET_VAL_OK
        else:
            return RET_VAL_ERROR

    def viewProject(self, projectPath=None, member_list=None, recurse="no"):
        """Displays the contents of a project and some information about the members.
        """
        return MksSIProject(projectPath).viewProject(member_list, recurse)

    def getProjectInfo(self, projectPath=None, member_list=None, recurse="no"):
        """Displays the contents of a project and some information about the members.
        """
        return MksSIProject(projectPath).getProjectInfo(member_list, recurse)

    def getSandboxMemberInfo(self, member_list):
        """Lists current information about a sandbox member.
        This includes general information about the member, and\
        specific information on the member revision
        """
        if not self.isConnected():
            if not self.connect():
                return RET_VAL_ERROR

        if member_list is not None:
            if not isinstance(member_list, list):
                member_list = [member_list]

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_MEMBER_INFO]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--sandbox=%s" % self.__sandbox_location]

        members = " ".join(member_list)
        si_arg_list += [members]

        ret_code, err_msg = Popen(si_arg_list, shell=True, stderr=PIPE, stdout=PIPE).communicate()
        self._err_msg = err_msg
        self._ret_code = ret_code
        return ret_code

    def getProjectMemberInfo(self, member_list, projectPath=None):
        """Lists current information about a project member.
        This includes general information about the member,
        and specific information on the member revision
        """
        return MksSIProject(projectPath).getMemberInfo(member_list)

    def resynchronizeMembers(self, member_list, output_file=None):
        """Compares the contents of project members with their corresponding
        working files in the Sandbox and replaces the working file with an exact
        copy of the member revision, if differences are detected or if no working file
        exists. If the working file is writable, you are optionally prompted for
        confirmation before it is replaced.
        """
        ret_code = RET_VAL_OK

        if not isinstance(member_list, list):
            return RET_VAL_ERROR

        for member in member_list:
            ret_code |= self.resynchronize(member)

        return ret_code

    def resynchronize(self, sandbox, member=None, output_file=None):
        """Compares the contents of project members with their corresponding
        working files in the Sandbox and replaces the working file with an exact
        copy of the member revision, if differences are detected or if no working file
        exists. If the working file is writable, you are optionally prompted for
        confirmation before it is replaced.
        """

        if not self.isConnected():
            if not self.connect():
                return -1

        if not sandbox.endswith("\project.pj"):
            sandbox += "\project.pj"

        si_arg_list = ["%s" % self._mks_si_path]
        si_arg_list += [self.CMD_RESYNC]
        si_arg_list += ["--hostname=%s" % self._hostname]
        si_arg_list += ["--port=%s" % self._port]
        si_arg_list += ["--user=%s" % self._username]
        si_arg_list += ["--forceConfirm=%s" % self._force_confirm]
        si_arg_list += ["--sandbox=%s" % sandbox]
        si_arg_list += ["--recurse"]
        if member is not None:
            si_arg_list += [member]

        if not path.exists(str(self.__sandbox_location)):
            self.__sandbox_location = sep.join([sandbox.split("\\")[0], sandbox.split("\\")[1]])
            if not path.exists(self.__sandbox_location):
                try:
                    makedirs(self.__sandbox_location)
                except Exception, msg:
                    self._logger.error("Couldn't create log file directory due to '%s'!" % (msg))

        try:
            output_filename = path.join(self.__sandbox_location, "mks.log")
            output_file = open(output_filename, "w+")
        except Exception:
            output_file = None

        ret_code = self.executeCommand(si_arg_list, output_file, output_file)

        if output_file:
            output_file.close()

        return ret_code
"""
CHANGE LOG:
-----------
$Log: si.py  $
Revision 1.1 2021/12/13 17:58:16CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mks/project.pj
Revision 1.9 2013/07/04 17:42:21CEST Hecker, Robert (heckerr) 
Removed some pep8 violations.
- Added comments -  heckerr [Jul 4, 2013 5:42:21 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/06/12 11:48:20CEST Hecker, Robert (heckerr)
Set Default value of Argument to False, because MKS forbid the usage of this feature.
--- Added comments ---  heckerr [Jun 12, 2013 11:48:20 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.7 2013/05/07 08:53:55CEST Hecker, Robert (heckerr)
Added resync command.
--- Added comments ---  heckerr [May 7, 2013 8:53:56 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.6 2013/04/29 10:39:55CEST Hecker, Robert (heckerr)
Added a easy to use mks si class, with two different Use case examples how to use.
--- Added comments ---  heckerr [Apr 29, 2013 10:39:56 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.5 2013/04/03 08:02:18CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:19 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/04/02 10:25:03CEST Mertens, Sven (uidv7805)
pylint: E0213, E1123, E9900, E9904, E1003, E9905, E1103
--- Added comments ---  uidv7805 [Apr 2, 2013 10:25:04 AM CEST]
Change Package : 176171:9 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.3 2013/03/27 13:51:23CET Mertens, Sven (uidv7805)
pylint: bugfixing and error reduction
Revision 1.2 2013/03/22 08:24:29CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.1 2013/03/15 11:43:06CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/mks/project.pj
------------------------------------------------------------------------------
-- From STK stk_mks_si Archive
------------------------------------------------------------------------------
Revision 1.10 2012/08/31 08:15:53CEST Mogos, Sorin(mogoss)
* improved error handling while connecting to server
--- Added comments ---  mogoss [Aug 31, 2012 8:15:57 AM CEST]
Change Package : 155168:1 http://mks-psad:7002/im/viewissue?selection=155168
Revision 1.9 2012/08/30 11:39:54CEST Mogos, Sorin(mogoss)
* improved error handling
Revision 1.8 2012/05/24 12:29:08CEST Spruck, Jochen(spruckj)
First try to parse the project
--- Added comments ---  spruckj [May 24, 2012 12:29:08 PM CEST]
Change Package : 98074:3 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.7 2012/05/21 11:27:54CEST Mogos, Sorin(mogoss)
* code improvements
--- Added comments ---  mogoss [May 21, 2012 11:27:54 AM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.3 2012/03/12 12:09:18CET Mogos, Sorin(mogoss)
* added stk_logger
* changes for MKS Integrity 2009 SP6 compatibility
--- Added comments ---  mogoss [Mar 12, 2012 12:09:19 PM CET]
Change Package : 96336:1 http://mks-psad:7002/im/viewissue?selection=96336
Revision 1.2 2012/03/11 19:57:06CET Spruck, Jochen(spruckj)
- Update skt_mks_si use parameter to the si exe
- Checkout also shared-variant-subproject and shared-subprojects
--- Added comments ---  spruckj [Mar 11, 2012 7:57:06 PM CET]
Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.1 2011/08/30 11:59:58CEST Mogos, Sorin(mogoss)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    31_PyLib/project.pj
"""
