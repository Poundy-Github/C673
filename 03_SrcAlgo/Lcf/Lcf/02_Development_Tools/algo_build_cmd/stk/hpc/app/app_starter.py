"""
app_starter.py
--------------

Script to be used to start a CMD Line Application in a HPC task.

Features:
 - moving of task result and log data back to the server
 - app watcher checking if the application is idle
 - graceful exit of GUI applications on task cancelation
 - evaluation of MTS return code and check for crashdumps

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:08CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import sys
from optparse import OptionParser
import subprocess
import time
import shutil
import stat
import fnmatch
import traceback
import signal
import win32process
import win32gui
import win32con
import re

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------
PyLibFolder = os.getcwd()

if PyLibFolder not in sys.path:
    sys.path.append(PyLibFolder)

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------
from stk.hpc.util import cmd_cfg as CmdCfg
from stk.hpc.app import app_watcher
from stk.hpc.ifc import jobdb as db

# Defines -------------------------------------------------------------------------------------------------------------

ERR_OK = 0
ERR_USER_CANCEL_TASK_DETECTED = -100
ERR_CHRASHDUMP_FOUND = -101
ERR_APPLICATION_CPU_IDLE = -102
ERR_APPLICATION_IO_IDLE = -103
ERR_APPLICATION_ERR_DETECTED = -104
ERR_SCRIPT_MALFUNCTION = -199

EXIT_GRACE_TIME = 15

MTS_APP_EXIT_CODE_OK = 1
MTS_APP_EXIT_CODE_ERROR_LOOKUP_ERRORLOG = 2
MTS_APP_EXIT_CODE_NO_ERRORLOG = 3

# Global Variables ------------------------------------------------------------
Proc = None
Error = ERR_OK
AppWatch = None


def get_version():
    version = 0.1
    return version


def get_creation_date():
    # date_str = __date__.find("Date: ")
    formated_date = "04.07.2012"

    return formated_date


def CheckForChrashdump(log_folder):
    # Check for the Actual Job if a Chrash Dump happened or not.
    # And modify the Error Code
    path = log_folder
    pattern = '*crash*.dmp'
    found_chrash = False

    for (path, _subdirs, files) in os.walk(path):
        # Here we have one match with all subdirs and files in the current path
        # Make a for loop to generate the absolute path for all files
        filenames = fnmatch.filter(files, pattern)
        if(len(filenames) > 0):
            found_chrash = True

    return found_chrash


class CancelTaskHandler(object):
    def __init__(self, mtsstarter):
        # Remember the calling instance
        self.mtsstarter = mtsstarter

        self.handler_sigterm = signal.signal(signal.SIGTERM, self.ShutDown)
        self.handler_sigint = signal.signal(signal.SIGINT, self.ShutDown)
        self.handler_sigbreak = signal.signal(signal.SIGBREAK, self.ShutDown)

    def EnumWindowsCallback(self, hWnd, bWindowFound):
        global Proc
        _TId, pid = win32process.GetWindowThreadProcessId(hWnd)
        if pid == Proc.pid:
            win32gui.PostMessage(hWnd, win32con.WM_CLOSE, 0, 0)
            bWindowFound[0] = True
        return True

    def CheckProcReturnCode(self):
        global Proc
        if Proc.returncode != 0:
            print 'Process exited with non zero exit code.'
            print 'ReturnCode: ' + str(Proc.returncode)
            ret = Proc.returncode
            if Proc.returncode < 0:
                ret = 2 ** 32 + 1 + Proc.returncode
            print "Hex: " + hex(ret)

    def ShutDown(self, signum, frame):
        # unset signal handler
        signal.signal(signal.SIGTERM, self.handler_sigterm)
        signal.signal(signal.SIGINT, self.handler_sigint)
        signal.signal(signal.SIGBREAK, self.handler_sigbreak)

        global Proc
        global AppWatch
        global Error
        sys.stdout.flush()
        sys.stderr.flush()
        print "Shutting down ..."

        # print call stack to stderr for possible error reconstruction
        print >> sys.stderr, "Printing call stack to Shutdwon function!!!"
        traceback.print_stack()

        # terminate app watch if running
        if AppWatch and AppWatch.poll() is None:
            # the SIGBREAK is also received by the sub process
            # -> might happen we try to terminate a process which
            # is not running anymore
            try:
                AppWatch.terminate()
            except WindowsError:
                if AppWatch.poll() is None:
                    print >> sys.stderr, "App watcher not exited properly!!!"

        # terminate app process if running
        if Proc and Proc.poll() is None:
            bWindowFound = [False]
            win32gui.EnumWindows(self.EnumWindowsCallback, bWindowFound)
            if bWindowFound[0]:
                tmp = "Attempt to close process gracefully."
                tmp += "(Sent WM_CLOSE Message to GUI Application)"
                print tmp
                waittime = 0
                while(waittime < EXIT_GRACE_TIME and Proc.poll() is None):
                    time.sleep(1)
                    waittime += 1

                if Proc.poll() is None:
                    print "Failed.\nTerminating process now."
                    Proc.terminate()
                else:
                    # check return code
                    self.CheckProcReturnCode()
                    print "Exit successful."
            else:
                print "Sending termination signal to process."
                # the SIGBREAK is also received by the sub process
                # -> might happen we try to terminate a process which
                # is not running anymore
                try:
                    Proc.send_signal(signal.SIGTERM)
                except WindowsError:
                    if Proc.poll() is None:
                        print >> sys.stderr, "Process not exited properly!!!"
        else:
            print "No process running."

        # check if an error code is already set
        if Error == ERR_OK:
            Error = ERR_USER_CANCEL_TASK_DETECTED

        print "Copying results and log ..."
        self.mtsstarter.CopyDeleteData()
        print "Shutdown completed."
        # exit the script with error code
        sys.exit(Error)


class AppStarter(object):
    def __init__(self):
        # Initialize some needed Variables
        self.cmd_helper = CmdCfg.StaticCMDHelper()
        self.networkpath = ''
        self.taskfolder = ''
        self.taskname = ''
        self.jobname = ''
        self.cwd = ''
        self.datafolder = ''
        self.tempfolder = ''
        self.cancel_hdl = None
        # use one member for copy processes to prevent 2 copy jobs
        # from running simultanously
        self.copy_proc = None
        self.oracle_db_usage = False
        self.app_monitor_usage = True
        self.app_watcher_usage = True

    def __on_rm_error(self, func, path, exc_info):
        """
        Error handler for ``shutil.rmtree``.

        If the error is due to an access error (read only file)
        it attempts to add write permission and then retries.

        If the error is for another reason it re-raises the error.

        Usage : ``shutil.rmtree(path, onerror=onerror)``
        """
        if not os.access(path, os.W_OK):
            # Is the error an access error ?
            print 'access error, set write attribute & delete: ', path
            os.chmod(path, stat.S_IWUSR)
            func(path)
        else:
            raise

    def StartApplication(self, arglist):

        global Proc
        global Error
        global AppWatch

        print "AppStarter: Starting application."

        # Check if first argument is a python script
        ending = arglist[0][-3:]
        if(ending == '.py'):
            arglist.insert(0, 'python.exe')

        cmdline = ""
        for item in arglist:
            cmdline += item
            cmdline += ' '

        print "AppStarter: " + cmdline

        # start the app
        if(__debug__):
            Proc = subprocess.Popen(arglist)
        else:
            Proc = subprocess.Popen(arglist, stdout=sys.stdout, stderr=sys.stderr)

        # start app watcher
        if(self.app_watcher_usage):
            tmp = os.path.join(self.cwd, 'stk\\hpc\\app\\app_watcher.py')
            if(__debug__):
                AppWatch = subprocess.Popen(['python.exe',
                                            tmp,
                                            str(Proc.pid), '-o'])
            else:
                AppWatch = subprocess.Popen(['python.exe',
                                            tmp,
                                            str(Proc.pid), '-o'],
                                            stdout=sys.stdout,
                                            stderr=sys.stderr)
        else:
            print "Process started without AppWatcher!"

        sys.stdout.flush()
        sys.stderr.flush()

        # Start the App Monitor
        if(self.app_monitor_usage):
            tmp = os.path.join(self.cwd, 'stk\\hpc\\app\\app_monitor.py')
            monargs = ['python.exe', tmp, '-p', str(Proc.pid),
                       '-j', str(self.jobname),
                       '-t', str(self.taskname)]
            if(self.app_watcher_usage):
                monargs.append('-w')
            if(self.oracle_db_usage):
                monargs.append('-r')

            if(__debug__):
                app_monitor = subprocess.Popen(monargs)
            else:
                app_monitor = subprocess.Popen(monargs,
                                               stdout=sys.stdout,
                                               stderr=sys.stderr)

        # non blocking wait for process to finish
        if(self.app_monitor_usage and self.app_watcher_usage):
            while(Proc.poll() is None and
                  AppWatch.poll() is None and
                  app_monitor.poll() is None):
                time.sleep(1)
        elif(self.app_watcher_usage):
            while(Proc.poll() is None and AppWatch.poll() is None):
                time.sleep(1)
        else:
            while(Proc.poll() is None):
                time.sleep(1)

        # check which process ended and if app watcher detected something
        if(self.app_monitor_usage):
            if(app_monitor.poll() is None):
                app_monitor.terminate()

        if self.app_watcher_usage:
            if AppWatch.poll() is None:
                # process finished so kill also app watcher
                AppWatch.terminate()
            else:
                # app watcher finished -> check why
                if AppWatch.returncode == app_watcher.EXIT_APP_CPU_IDLE:
                    Error = ERR_APPLICATION_CPU_IDLE
                elif AppWatch.returncode == app_watcher.EXIT_APP_IO_IDLE:
                    Error = ERR_APPLICATION_IO_IDLE
                else:
                    # error in app watcher
                    Error = ERR_SCRIPT_MALFUNCTION
                # call shutdown routine
                self.cancel_hdl.ShutDown(None, None)

        # Set Error Code for Nomal Exit of Application
        # For Measapp.exe don't use returncode, because it is buggy
        if(Error == 0 and os.path.split(arglist[0])[1] != 'measapp.exe'):
            # robocopy errors below 4 are warning
            if 'robocopy' in os.path.split(arglist[0])[1]:
                if Proc.returncode > 3:
                    Error = Proc.returncode
            else:
                Error = Proc.returncode
        else:
            if(Proc.returncode == MTS_APP_EXIT_CODE_OK):
                Error = ERR_OK
            if(Proc.returncode == MTS_APP_EXIT_CODE_ERROR_LOOKUP_ERRORLOG):
                Error = ERR_APPLICATION_ERR_DETECTED
            if(Proc.returncode == MTS_APP_EXIT_CODE_NO_ERRORLOG):
                Error = ERR_APPLICATION_ERR_DETECTED
        print "ErrorCode after SubTask: %d" % Error

    def CopyDeleteResults(self, src, dest):
        """
        This Method will Move all results from the src to the dest, and wait
        until the copy process is finished. The copy itself will be done
        with "robocopy.exe".
        The Files and Folders at src will be deleted after the copy.

        :type  src:   string
        :param dest:  Source Path of the Folder to copy.
        :type  dest:  string
        :param dest:  Destination Path where to copy the Folder to.
        :rtype:  int
        :return: Return Code of robocopy.

        :author:           Robert Hecker
        """

        error = 0

        # wait for potential other copy job
        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        print 'robocopy ' + src + ' ' + dest + ' /E /MOVE /R:3 /W:10\n'
        # Start the "real" copy
        if(__debug__):
            self.copy_proc = subprocess.Popen([r"robocopy", src, dest, "/E",
                                               "/MOVE", "/R:3", "/W:10"])
        else:
            self.copy_proc = subprocess.Popen([r"robocopy", src, dest, "/E",
                                               "/MOVE", "/R:3", "/W:10"],
                                              stdout=sys.stdout, stderr=sys.stderr)

        # wait until suprocess is finished.
        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        # Filter return Code of robocopy after real Error
        if(self.copy_proc.returncode > 3):
            error = self.copy_proc.returncode

        return error

    def CopyDeleteMTSOutput(self, src, dest):
        """
        This Method will Move all MTS Output from the src to the dest, and wait
        until the copy process is finished. The copy itself will be done
        with "robocopy.exe".
        The Files and Folders at src will be deleted after the copy.

        :type  src:   string
        :param dest:  Source Path of the Folder to copy.
        :type  dest:  string
        :param dest:  Destination Path where to copy the Folder to.
        :rtype:  int
        :return: Return Code of robocopy.

        :author:           Robert Hecker
        """

        error = 0

        # wait for potential other copy job
        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        # Start the "real" copy
        if(__debug__):
            self.copy_proc = subprocess.Popen([r"robocopy",
                                               src,
                                               dest,
                                               "/E",
                                               "/MOVE",
                                               "/R:3",
                                               "/W:10"])
        else:
            self.copy_proc = subprocess.Popen([r"robocopy",
                                               src,
                                               dest,
                                               "/E",
                                               "/MOVE",
                                               "/R:3",
                                               "/W:10"],
                                              stdout=sys.stdout,
                                              stderr=sys.stderr)

        # wait until suprocess is finished.
        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        # Filter return Code of robocopy after real Error
        if(self.copy_proc.returncode > 3):
            error = self.copy_proc.returncode

        return error

    def CopyDeleteSdtOutErr(self, src, dest):
        """
        This Method will Move the stdout and stderr files from the src to
        the dest, and wait until the copy process is finished.
        The copy itself will be done with "robocopy.exe".
        The Files and Folders at src will be deleted after the copy.

        :type  src:   string
        :param dest:  Source Path of the Folder to copy.
        :type  dest:  string
        :param dest:  Destination Path where to copy the Folder to.
        :rtype:  int
        :return: Return Code of robocopy.

        :author:           Robert Hecker
        """
        error = 0

        task_id = os.path.split(dest)[1][1:]
        outfile = "stdout_" + task_id + ".txt"
        errfile = "stderr_" + task_id + ".txt"

        # wait for potential other copy job
        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        if(__debug__):
            self.copy_proc = subprocess.Popen([r"robocopy",
                                               src,
                                               dest,
                                               "/R:3",
                                               "/W:10",
                                               outfile])
        else:
            self.copy_proc = subprocess.Popen([r"robocopy",
                                               src,
                                               dest,
                                               "/R:3",
                                               "/W:10",
                                               outfile],
                                              stdout=sys.stdout,
                                              stderr=sys.stderr)

        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        # Filter return Code of robocopy after real Error
        if(self.copy_proc.returncode > 3):
            error = self.copy_proc.returncode

        # Rename File
        try:
            os.rename(os.path.join(dest, outfile),
                      os.path.join(dest, 'stdout.txt'))
        except:
            pass

        if(__debug__):
            self.copy_proc = subprocess.Popen([r"robocopy",
                                              src,
                                              dest,
                                              "/R:3",
                                              "/W:10",
                                              errfile])
        else:
            self.copy_proc = subprocess.Popen([r"robocopy",
                                              src,
                                              dest,
                                              "/R:3",
                                              "/W:10",
                                              errfile],
                                              stdout=sys.stdout,
                                              stderr=sys.stderr)

        while(self.copy_proc and self.copy_proc.poll() is None):
            time.sleep(1)

        # Filter return Code of robocopy after real Error
        if(error == 0 and self.copy_proc.returncode > 3):
            error = self.copy_proc.returncode

        # Rename File
        try:
            os.rename(os.path.join(dest, errfile),
                      os.path.join(dest, 'stderr.txt'))
        except:
            pass

        return error

    def CopyDeleteData(self):

        global CopyFromGlobal_data
        error = 0

        if(self.networkpath[0] == 'd'):
            return 0

        # first delete tmp folder to prevent copying it
        print 'deleting temp. folder: ', self.tempfolder
        shutil.rmtree(self.tempfolder, onerror=self.__on_rm_error)

        sys.stdout.flush()
        sys.stderr.flush()

        if(CopyFromGlobal_data):
            # Copy Results back to Network from
            # d:\\data\\%JobName%\\2_Output\\_data
            tmp = os.path.split(os.path.split(self.datafolder)[0])[0]
            src = os.path.join(tmp, '_data')
            dest = os.path.join(self.networkpath, '2_Output', '_data')
            error = self.CopyDeleteResults(src, dest)
        else:
            # Copy Results back to Network from
            # d:\\data\\%JobName%\\2_Output\\%TaskName%\\data
            dest = os.path.join(self.networkpath, '2_Output', '_data')
            error = self.CopyDeleteResults(self.datafolder, dest)

        # Copy MTS Log Folder Back to Network
        ret = self.CopyDeleteMTSOutput(self.taskfolder,
                                       os.path.join(self.networkpath,
                                       '2_Output',
                                       self.taskname))

        if(error == 0):
            error = ret

        # Copy StdErr and StdOut back to Network
        src = os.path.join(os.path.split(self.cwd)[0], '2_Output')
        dest = os.path.join(self.networkpath, '2_Output', self.taskname)

        # Do a flush befor copy the data, to get most data inside the file.
        sys.stdout.flush()
        sys.stderr.flush()
        ret = self.CopyDeleteSdtOutErr(src, dest)

        if(error == 0):
            error = ret

        return error

    def StartApp(self, networkpath, taskname, static_cfgfilepath, dynamic_parameter):

        global CopyFromGlobal_data
        global Error

        # Set Default Value
        CopyFromGlobal_data = False

        # Set some needed Member variables
        self.networkpath = networkpath
        self.taskname = taskname
        self.cwd = os.getcwd()

        # Create StandardFolders for the Task
        logfolder = self.CreateStdFolders()

        if(static_cfgfilepath != ''):
            self.cmd_helper.Read(static_cfgfilepath)

        self.app_watcher_usage = self.cmd_helper.AppWatcher.Get()

        folders_in = self.cmd_helper.Folders.Get()
        folders_out = []
        self.jobname = os.path.split(networkpath)[1]
        # Replace JobName in FolderList
        for el in folders_in:
            el = el.replace('%JobName%', self.jobname)
            el = el.replace('%TaskName%', taskname)
            folders_out.append(el)
            # Create all aditional Folders
            if not(os.path.exists(el)):
                os.makedirs(el)

        environmentlist = self.cmd_helper.ENVs.Get()
        for el in environmentlist:
            value = el.split('=')[1]
            value = value.replace('%JobName%', self.jobname)
            value = value.replace('%TaskName%', taskname)
            os.environ[el.split('=')[0]] = value

        # Set current Environment Variables for the real working Task
        # To be able to determine the Task and JobName
        os.environ["TaskName"] = taskname
        os.environ["JobName"] = self.jobname
        os.environ["HPCTaskDataFolder"] = self.datafolder
        os.environ["HPCTaskTmpFolder"] = self.tempfolder

        # set shutdown handler
        self.cancel_hdl = CancelTaskHandler(self)

        # Replace all Variables in CMDList
        self.cmd_helper.CMDs.replace('%JobName%', self.jobname)
        self.cmd_helper.CMDs.replace('%TaskName%', taskname)

        # Check Config File for Usage of Global '_data' Folder
        mylist = self.cmd_helper.Globs.Get()
        for el in mylist:
            if(el == 'Global_Data_Usage = True'):
                CopyFromGlobal_data = True
            if(el == 'MasterOracleDB = True'):
                self.oracle_db_usage = True

        # Change the Current Working Directory to the desired one
        if(self.cmd_helper.CWD.Get() != ''):
            self.cmd_helper.CWD.replace('%JobName%', self.jobname)
            self.cmd_helper.CWD.replace('%TaskName%', taskname)
            cwd = self.cmd_helper.CWD.Get()

            # Set the current working directory to the Tasks Data Folder
            self.cwd = os.getcwd()
            os.chdir(cwd)

        arglist = self.cmd_helper.CMDs.GetFinalArgList(dynamic_parameter)

        # Do the real Application call
        self.StartApplication(arglist)

        # Set Current Working directory back to original value
        if self.cwd != '':
            os.chdir(self.cwd)

        # Check if Chrash happend and modify Error Code if necessary
        if(Error == 0 and CheckForChrashdump(logfolder)):
            Error = ERR_CHRASHDUMP_FOUND

        # Copy and Delete Data Files
        copy_error = self.CopyDeleteData()

        if(Error == 0):
            Error = copy_error

    def CreateStdFolders(self):

        # Create the standard Folders which are available for every Application
        self.taskfolder = os.path.split(os.getcwd())[0]
        self.taskfolder = os.path.join(self.taskfolder, '2_Output')
        self.taskfolder = os.path.join(self.taskfolder, self.taskname)

        # Check if Task Folder exist
        if(os.path.exists(self.taskfolder)):
            shutil.rmtree(self.taskfolder)

        print '-----------------------------------------------'
        print self.taskfolder

        # Create Output Folder for Task
        os.makedirs(self.taskfolder)

        # Create OutputFolder for log Files
        logfolder = os.path.join(self.taskfolder, 'log')
        os.makedirs(logfolder)

        # Create OutputFolder for data Files
        self.datafolder = os.path.join(self.taskfolder, 'data')
        os.makedirs(self.datafolder)
        self.tempfolder = os.path.join(self.taskfolder, 'tmp')
        os.makedirs(self.tempfolder)

        return logfolder

    def StartAppWithDB(self, input_db, taskname):

        global CopyFromGlobal_data
        global Error

        # Set Default Value
        CopyFromGlobal_data = False

        # Set some needed Member variables

        self.taskname = taskname
        self.cwd = os.getcwd()

        # Create StandardFolders for the Task
        logfolder = self.CreateStdFolders()

        hpc_db = db.ifc.HpcDb()
        hpc_db.open(input_db)
        base_folder = hpc_db.session.base_folder
        self.jobname = hpc_db.session.job_name
        servername = re.search(r'....[0-9]+', hpc_db.session.headnode_name).group()

        self.networkpath = os.path.join(base_folder, servername, self.jobname)

        # Configure Oracle DB Usage
        self.oracle_db_usage = hpc_db.session.ora_usage

        # Get all info for one SubTask
        subtask = hpc_db.session.get_first_subtask(taskname)

        # Set current Environment Variables for the real working Task
        # To be able to determine the Task and JobName
        os.environ["TaskName"] = taskname
        os.environ["JobName"] = self.jobname
        os.environ["HPCTaskDataFolder"] = self.datafolder
        os.environ["HPCTaskTmpFolder"] = self.tempfolder

        # set shutdown handler
        self.cancel_hdl = CancelTaskHandler(self)

        # Do the completet Processing of one SubTask
        while(subtask is not None):

            # Configure Appwatcher Usage
            self.app_watcher_usage = subtask.appwatcher

            # Configure Clobal Data Folder Usage
            CopyFromGlobal_data = subtask.useglobaldata

            # Create Additional Folders if needed
            for path in subtask.nodefolders:
                path = path.replace('%JobName%', self.jobname)
                path = path.replace('%TaskName%', taskname)
                if not(os.path.exists(path)):
                    os.makedirs(path)

            # Set Needed Environment Vars
            for el in subtask.envars:
                key = el[0]
                value = el[1]
                value = value.replace('%JobName%', self.jobname)
                value = value.replace('%TaskName%', taskname)
                os.environ[key] = value

            # Change the Current Working Directory to the desired one
            if(subtask.curworkdir != ''):
                cwd = subtask.curworkdir
                cwd = cwd.replace('%JobName%', self.jobname)
                cwd = cwd.replace('%TaskName%', taskname)

                # Set the current working directory to the Tasks Data Folder
                self.cwd = os.getcwd()
                os.chdir(cwd)

            # Replace all Variables in CMDList
            arglist = []
            for item in subtask.cmdline:
                item = item.replace('%JobName%', self.jobname)
                item = item.replace('%TaskName%', taskname)
                arglist.append(item)

            arglist2 = []
            # Replace \\LIFS010 with LIFS010S if we run on HPC
            if(self.networkpath[0] != 'd'):
                replacements = (('\\\\LIFS010.', '\\\\LIFS010S.'),
                                ('\\\\LIFS010\\', '\\\\LIFS010S\\'))

                for item in arglist:
                    for repl in replacements:
                        regexp = re.compile(re.escape(repl[0]), re.IGNORECASE)
                        item = regexp.sub(repl[1].replace('\\', '\\\\'), item)
                    arglist2.append(item)
            else:
                arglist2 = arglist

            # Do the real Application call
            self.StartApplication(arglist2)

            # Set Current Working directory back to original value
            if self.cwd != '':
                os.chdir(self.cwd)

            # Get the next Subtask to run
            subtask = hpc_db.session.get_next_subtask()

        # Check if Chrash happend and modify Error Code if necessary
        if(Error == 0 and CheckForChrashdump(logfolder)):
            Error = ERR_CHRASHDUMP_FOUND

        # Copy and Delete Data Files
        copy_error = self.CopyDeleteData()

        if(Error == 0):
            Error = copy_error

if __name__ == "__main__":

    version = "\n%s " % os.path.split(sys.argv[0])[1]
    version += "Vers. %s " % get_version()
    version += "Author: Robert Hecker, Creation date: "
    version += "%s\n" % get_creation_date()

    # Parse command line parameters
    optparser = OptionParser(usage="%prog [Options] lint_file",
                             version=version)
    optparser.add_option("-i",
                         dest="InputDB",
                         default="",
                         help="InputDB for all CMDLineParameters")
    optparser.add_option("-n",
                         dest="NetworkPath",
                         default="",
                         help="NetworkPath, to copy the Results back.")
    optparser.add_option("-t",
                         dest="TaskName",
                         default='',
                         help="TaskName from the HPC")
    optparser.add_option("-c",
                         dest="StaticCfgFilePath",
                         default='',
                         help="Path to Static CMDLine Arg for Application")
    optparser.add_option("-d",
                         dest="DynamicPar",
                         action="append",
                         default=[],
                         help="Dynamic Parameters")

    cmd_options = optparser.parse_args()

    optparser.print_version()

    NetworkPath = cmd_options[0].NetworkPath
    TaskName = cmd_options[0].TaskName
    StaticCfgFilePath = cmd_options[0].StaticCfgFilePath
    DynamicPar = cmd_options[0].DynamicPar
    InputDB = cmd_options[0].InputDB

    try:
        starter = AppStarter()
        if(InputDB is ""):
            starter.StartApp(NetworkPath, TaskName, StaticCfgFilePath, DynamicPar)
        else:
            starter.StartAppWithDB(InputDB, TaskName)
    # catches all non system exiting exceptions
    except Exception:
        traceback.print_exc()
        if(starter.cancel_hdl is not None):
            Error = ERR_SCRIPT_MALFUNCTION
            starter.cancel_hdl.ShutDown(None, None)

    sys.exit(Error)

"""
CHANGE LOG:
-----------
$Log: app_starter.py  $
Revision 1.1 2021/12/13 17:57:08CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/app/project.pj
Revision 1.24 2013/11/08 12:39:39CET Hecker, Robert (heckerr) 
updated network path for copy back to new hpc share.
- Added comments -  heckerr [Nov 8, 2013 12:39:39 PM CET]
Change Package : 205360:1 http://mks-psad:7002/im/viewissue?selection=205360
Revision 1.23 2013/10/30 10:09:32CET Hecker, Robert (heckerr) 
Removed unecessary print output to console.
--- Added comments ---  heckerr [Oct 30, 2013 10:09:32 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.22 2013/09/17 14:40:10CEST Hecker, Robert (heckerr) 
updated imports
--- Added comments ---  heckerr [Sep 17, 2013 2:40:10 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.21 2013/09/12 14:23:10CEST Hecker, Robert (heckerr)
Some updates regarding pep8.
--- Added comments ---  heckerr [Sep 12, 2013 2:23:10 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.20 2013/09/11 17:57:15CEST Hecker, Robert (heckerr)
BugFix in Varnames.
--- Added comments ---  heckerr [Sep 11, 2013 5:57:15 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.18 2013/09/11 13:59:23CEST Hecker, Robert (heckerr)
- Added Docu.
- Removed some pylint Issues.
--- Added comments ---  heckerr [Sep 11, 2013 1:59:24 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.17 2013/09/06 15:01:16CEST Hecker, Robert (heckerr)
Added modifications for parallel submit possibility.
sqlite DB Filename is now the JobName.
--- Added comments ---  heckerr [Sep 6, 2013 3:01:16 PM CEST]
Change Package : 193310:1 http://mks-psad:7002/im/viewissue?selection=193310
Revision 1.16 2013/07/04 17:30:00CEST Hecker, Robert (heckerr)
Removed pep8 violations.
--- Added comments ---  heckerr [Jul 4, 2013 5:30:00 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.15 2013/07/01 08:27:31CEST Hecker, Robert (heckerr)
- Improved Debugging possibility;
- Added New _HPC FolderNAme support "_HPC066"
--- Added comments ---  heckerr [Jul 1, 2013 8:27:31 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.14 2013/05/23 16:00:12CEST Raedler, Guenther (uidt9430)
- added print messages for sub tasks
--- Added comments ---  uidt9430 [May 23, 2013 4:00:13 PM CEST]
Change Package : 180569:1 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.13 2013/05/16 08:04:49CEST Hecker, Robert (heckerr)
Added Subtask support to HPC Job Creation.
--- Added comments ---  heckerr [May 16, 2013 8:04:49 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.12 2013/03/22 09:26:08CET Hecker, Robert (heckerr)
Added Error Code handling for copy back results with robocopy.
--- Added comments ---  heckerr [Mar 22, 2013 9:26:08 AM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.11 2013/03/22 08:24:30CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
--- Added comments ---  uidv7805 [Mar 22, 2013 8:24:31 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/20 18:26:16CET Hecker, Robert (heckerr)
Removed Pep8 Message.
--- Added comments ---  heckerr [Mar 20, 2013 6:26:19 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/03/04 17:36:56CET Hospes, Gerd-Joachim (uidv8815)
add tmp folder in task output path and deletion before copying data back to filer
--- Added comments ---  uidv8815 [Mar 4, 2013 5:36:56 PM CET]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.8 2013/02/28 08:12:25CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:25 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/07 17:15:41CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:15:41 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2012/12/14 16:22:46CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:46 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/12 10:37:23CET Hecker, Robert (heckerr)
Updated Code regarding pep8.
--- Added comments ---  heckerr [Dec 12, 2012 10:37:23 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/11 14:15:32CET Hecker, Robert (heckerr)
Get OracleMasterDB support working.
--- Added comments ---  heckerr [Dec 11, 2012 2:15:33 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/10 16:39:03CET Hecker, Robert (heckerr)
Added AppMonitor into AppStarter.
--- Added comments ---  heckerr [Dec 10, 2012 4:39:05 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:51CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:45:16CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
