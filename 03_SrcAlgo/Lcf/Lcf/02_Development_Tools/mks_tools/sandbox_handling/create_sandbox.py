import sys
import os

sys.path.append(os.path.dirname(os.path.realpath(__file__)) + os.sep + os.pardir)
from CLI_tools import cli_proc_handler

class create_sandbox:
    def __init__(self, mksConnectionUser, mksDevPath, mksHost, mksPort, projectWorkspace, sboxDirectory):
        self.cliProcHandler = cli_proc_handler()
        self.mksConnectionUser = mksConnectionUser
        self.mksDevPath = mksDevPath
        self.mksHost = mksHost
        self.mksPort = mksPort
        self.projectWorkspace = projectWorkspace
        self.sboxDirectory = sboxDirectory

    def createSandbox(self):
        sandboxToCreate = self.projectWorkspace + os.sep + self.sboxDirectory

        print("Using following MKS-Devpath for creation: '%s'" % self.mksDevPath)
        print("Creation of sandbox will be done on IMS-Host '%s', IMS-Port '%s' and user '%s' to local folder '%s" %
              (self.mksHost, self.mksPort, self.mksConnectionUser, sandboxToCreate))

        commandLine = "si createsandbox --batch --noawaitServer --hostname=%s --port=%s --user=%s --recurse --populate -Y --quiet --project=%s %s" % (
            self.mksHost, self.mksPort, self.mksConnectionUser, self.mksDevPath, sandboxToCreate)

        return self.cliProcHandler.SiCLIHandler_wait(commandLine)

def main():
    mksConnectionUser = str(sys.argv[1])
    mksDevPath = str(sys.argv[2])
    mksHost = str(sys.argv[3])
    mksPort = str(sys.argv[4])
    projectWorkspace = str(sys.argv[5])
    sboxDirectory = str(sys.argv[6])

    if len(sys.argv) != 7:
        return 1

    sandboxMksCreate = create_sandbox(mksConnectionUser, mksDevPath, mksHost, mksPort, projectWorkspace, sboxDirectory)
    return sandboxMksCreate.createSandbox()

if __name__ == "__main__":
    sys.exit(main())
