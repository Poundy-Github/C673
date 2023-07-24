import sys
import os
import shutil

sys.path.append(os.path.dirname(os.path.realpath(__file__)) + os.sep + os.pardir)
from CLI_tools import cli_proc_handler

class check_sandbox:
    RESYNC = 1
    EXISTINGMKS = 2
    NA = 0

    def __init__(self, mksConnectionUser, mksHost, mksPort, sandboxToCheck, projectFilename):
        self.cliProcHandler = cli_proc_handler()
        self.mksConnectionUser = mksConnectionUser
        self.mksHost = mksHost
        self.mksPort = mksPort
        self.sandboxToCheck = sandboxToCheck
        self.projectFilename = projectFilename

    def checkSandbox(self):
        sandboxToFind = self.sandboxToCheck + os.sep + self.projectFilename

        print("Check the sandbox if it exists on system with IMS-Host '%s', IMS-Port '%s' and user '%s' at local folder '%s" %
              (self.mksHost, self.mksPort, self.mksConnectionUser, sandboxToFind))

        commandLine = "si sandboxinfo --sandbox=%s --noattributes --noshowCheckpointDescription --noassociatedIssues" % \
                      sandboxToFind

        if self.cliProcHandler.SiCLIHandler_wait(commandLine, self.cliProcHandler.MODE_RETURN, True) == 0:
            return self.RESYNC
        else:
            commandLine = "si sandboxes --nodisplaySubs --batch --yes"

            self.cliProcHandler.SiCLIHandler_wait(commandLine, self.cliProcHandler.MODE_RETURN, True)
            projects_stdout = self.cliProcHandler.getstdout_split()

            for prj in projects_stdout:
                # Because sandbox path comes with \\ from MKS, we have to remove the duplicates
                prj = prj.replace('\\\\', '\\')
                if prj.lower().startswith(sandboxToFind.lower()):
                    print("Sandbox found")
                    return self.EXISTINGMKS

            self.removeLocalSandboxDirectoryIfNeccessary()
            return self.NA

        print("Sandbox not found")
        return self.NA

    def removeLocalSandboxDirectoryIfNeccessary(self):
        # Check for _DP-folder and not for SBOX/project.pj
        if os.path.exists(self.sandboxToCheck):
            print(
            "Sandbox exists in local directory but it is not registered in MKS. Will remove local sandbox directory '%s'." %
            self.sandboxToCheck)
            # Be careful, code removes directory without asking!!!
            shutil.rmtree(self.sandboxToCheck, True)

def main():
    mksConnectionUser = str(sys.argv[1])
    mksHost = str(sys.argv[2])
    mksPort = str(sys.argv[3])
    sandboxToCheck = str(sys.argv[4])
    projectFilename = str(sys.argv[5])

    if len(sys.argv) != 6:
        return 1

    sandboxMksCheck = check_sandbox(mksConnectionUser, mksHost, mksPort, sandboxToCheck, projectFilename)
    return sandboxMksCheck.checkSandbox()

if __name__ == "__main__":
    sys.exit(main())
