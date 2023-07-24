import sys
import os

sys.path.append(os.path.dirname(os.path.realpath(__file__)) + os.sep + os.pardir)
from CLI_tools import cli_proc_handler


class resync_sandbox:
    def __init__(self, mksConnectionUser, mksConnectionUserPassword, mksHost, mksPort, projectWorkspace, sboxDirectory):
        self.cliProcHandler = cli_proc_handler()
        self.mksConnectionUser = mksConnectionUser
        self.mksConnectionUserPassword = mksConnectionUserPassword
        self.mksHost = mksHost
        self.mksPort = mksPort
        self.projectWorkspace = projectWorkspace
        self.sboxDirectory = sboxDirectory

    def resyncSandbox(self):
        sandboxToResync = self.projectWorkspace + os.sep + self.sboxDirectory + os.sep + "project.pj"

        print("Resync will be done on MKS-Host '%s', MKS-Port '%s' and user '%s' on Sandbox '%s'" % (
            self.mksHost, self.mksPort, self.mksConnectionUser, sandboxToResync))

        commandLine = "si resync --batch --noawaitServer --hostname=%s --port=%s --user=%s --password=%s --recurse --overwriteChanged --includeDropped -Y --filter=changed:sync,changed:working --sandbox=%s --quiet" % (
            self.mksHost, self.mksPort, self.mksConnectionUser, self.mksConnectionUserPassword, sandboxToResync)

        return self.cliProcHandler.SiCLIHandler_wait(commandLine)


def main():
    mksConnectionUser = str(sys.argv[1])
    mksConnectionUserPassword = str(sys.argv[2])
    mksHost = str(sys.argv[3])
    mksPort = str(sys.argv[4])
    projectWorkspace = str(sys.argv[5])
    sboxDirectory = str(sys.argv[6])

    if len(sys.argv) != 7:
        return 1

    sandboxMksResync = resync_sandbox(mksConnectionUser, mksConnectionUserPassword, mksHost, mksPort,
                                      projectWorkspace, sboxDirectory)
    return sandboxMksResync.resyncSandbox()


if __name__ == "__main__":
    sys.exit(main())
