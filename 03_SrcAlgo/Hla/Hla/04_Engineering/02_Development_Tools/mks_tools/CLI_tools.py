###########
# CLI Scripting toolbox
# This class is dealing with cmdline interface.
# it provides a wrapper to get rid of errorhandling
###########

import time
import subprocess


class cli_proc_handler(object):
    stdout = None
    stderr = None
    PID = None
    cmdline = None
    MODE_ASSERT = "ASSERT"
    MODE_RETURN = "RETURN"

    def getstdout_split(self):
        return [item.strip() for item in self.stdout.splitlines()]

    def getcommunicate (self):
        if self.PID is None:
            stdout = ""
            stderr = ""
            if self.stdout is not None:
                stdout = self.stdout
            if self.stderr is not None:
                stderr = self.stderr
            return stdout,stderr
        return (self.stdout, self.stderr)

    def setcommunicate (self, stdout_str, stderr_str):
        if isinstance(stdout_str,basestring) and isinstance(stderr_str,basestring):
            self.stdout = stdout_str
            self.stderr = stderr_str
            return 0
        return 1

    def SiCLIHandler_poll (self, cmdline, mode=MODE_ASSERT, ignoreErrorMessage=False):
        ###########
        # This method calls a subprocess and returns the
        # PID of the called process.
        # It polls in a given framerate the return of the
        # subprocess.
        ###########
        if not isinstance(cmdline,basestring):
            if mode == self.MODE_ASSERT:
                raise RuntimeError("CLI error: cmdline parameter is not a string")
            elif mode == self.MODE_RETURN:
                return 1
        if ignoreErrorMessage not in [True,False]:
            if mode == self.MODE_ASSERT:
                raise RuntimeError("CLI error: ignoreErrorMessage parameter is not a boolean")
            elif mode == self.MODE_RETURN:
                return 1
        self.cmdline = cmdline
        try:
            self.PID = subprocess.Popen(
                cmdline,
                shell=True,
                bufsize=0,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                # TODO: have a look at this, if this is needed
                creationflags=0x08000000)
            #print ("executing %s" % self.cmdline)
            while self.PID.poll() is None:
                print (".")
                time.sleep(0.200)
            (stdout_str, stderr_str) = self.PID.communicate()
            self.setcommunicate(stdout_str, stderr_str)
            self.mks_error_printer(self.cmdline, self.PID)
            return self.error_handler_CLI(mode, ignoreErrorMessage)
        except OSError, e:
            print ("OSError [%d]: %s" % e.errno, e.stderror)

    def SiCLIHandler_wait (self, cmdline, mode=MODE_ASSERT, ignoreErrorMessage=False):
        ###########
        # This method calls a subprocess and returns the
        # PID of the called process.
        # It waits for the subprocess to finish.
        ###########
        if not isinstance(cmdline,basestring):
            if mode == self.MODE_ASSERT:
                raise RuntimeError("CLI error: cmdline parameter is not a string")
            elif mode == self.MODE_RETURN:
                return 1
        if ignoreErrorMessage not in [True,False]:
            if mode == self.MODE_ASSERT:
                raise RuntimeError("CLI error: ignoreErrorMessage parameter is not a boolean")
            elif mode == self.MODE_RETURN:
                return 1
        self.cmdline = cmdline
        try:
            self.PID = subprocess.Popen(
                cmdline,
                shell=True,
                bufsize=0,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                # TODO: have a look at this, if this is needed
                creationflags=0x08000000)
            #print ("executing %s" % self.cmdline)
            (stdout_str, stderr_str) = self.PID.communicate()
            self.setcommunicate(stdout_str, stderr_str)
            if not ignoreErrorMessage:
                self.mks_error_printer(self.cmdline, self.PID)
            return self.error_handler_CLI(mode, ignoreErrorMessage)
        except OSError, e:
            print ("OSError [%d]: %s" % e.errno, e.stderror)

    def error_handler_CLI (self, mode=MODE_ASSERT, ignoreErrorMessage=False):
        ###########
        # This method provides the errorhandling
        # of the subprocess. It deals with the stdout and stderr
        ###########
        stderr_str_unformat = ""
        if isinstance(self.stderr,basestring):
            stderr_str_unformat = self.stderr.replace('\r\n', "")
        if self.PID.returncode != 0:
            if not ignoreErrorMessage:
                if len(stderr_str_unformat) != 0:
                    print ("ERROR(%s): %s" % (self.PID.returncode, stderr_str_unformat))
                else:
                    print ("ERROR(%s):" % self.PID.returncode)
            if mode == self.MODE_ASSERT:
                raise RuntimeError("CLI error: The returncode of CLI process was unequal to 0")
            elif mode == self.MODE_RETURN:
                return 1
        else:
            if len(stderr_str_unformat) != 0:
                print ("WARNING: %s" % stderr_str_unformat)
            return 0

    def mks_error_printer(self,cmdline=cmdline,PID=PID):
        premessage = "MKS_IMS message: "
        if cmdline is None:
            raise RuntimeError("no cmdline provided")
        if PID is None:
            raise RuntimeError("no PID provided")
        elif PID.returncode is None:
            raise RuntimeError("PID is not containing a returncode")
        exitcode = PID.returncode
        if not isinstance(cmdline,basestring):
            raise RuntimeError("cmdline is not a string")
        if not isinstance(exitcode,int):
            raise RuntimeError("exitcode is not a int")
        if not (cmdline.startswith("si ") or cmdline.startswith("im ")):
            print ("no si command")
            return
        if exitcode == 1:
            print ("%sCommand usage error." % premessage)
        elif exitcode == 2:
            print ("""%sCommand was canceled by user.This does not include cancellationsusing CTRL - c, which overrides this exit
        status value.In those cases, the return code will be 130.""" % premessage)
        elif exitcode == 3:
            print ("%sInvalid element in the selection for the command." % premessage)
        elif exitcode == 4:
            print ("%sSandbox specified was ambiguous(using an si command).Command not executed." % premessage)
        elif exitcode == 5:
            print ("%sUnable to create or utilize the selection for the command." % premessage)
        elif exitcode == 6:
            print ("%sUnable to continue with the selection for the command because the program cannot find the next element." % premessage)
        elif exitcode == 10:
            print ("%sConnection failed: a network error caused the command to terminate." % premessage)
        elif exitcode == 16:
            print ("%sdiff compared the files and found them to be different(using si diff)." % premessage)
        elif exitcode == 17:
            print ("""%sFailure due to any of the following(using si diff):
                      * invalid command line argument
                      * cannot open one of the input files
                      * out of memory
                      * read error on one of the input files
                      * more than LINE_MAX characters between newlines""" % premessage)
        elif exitcode == 19:
            print ("%sAt least one of the files is a binary file containing embedded NUL(\0) bytes(using si diff)." % premessage)
        elif exitcode == 128:
            print ("%sGeneral command failure." % premessage)
        elif exitcode == 130:
            print ("%sCommand was canceled by the user using CTRL - c." % premessage)
        elif exitcode == 255:
            print ("%sUnknown exception or error code." % premessage)
        return
