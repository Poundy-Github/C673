import sys
import os
from check_sandbox import check_sandbox
from drop_sandbox import drop_sandbox
from resync_sandbox import resync_sandbox
from create_sandbox import create_sandbox

sys.path.append(os.path.dirname(os.path.realpath(__file__)) + os.sep + os.pardir)
from CLI_tools import cli_proc_handler

class createOrResync_sandbox:

    PROJECT_FILENAME = "project.pj"

    def __init__(self, mksConnectionUser, mksConnectionUserPassword, mksDevPath, mksHost, mksPort, projectWorkspace,
                 sboxDirectory):
        self.cliProcHandler = cli_proc_handler()
        self.mksConnectionUser = mksConnectionUser
        self.mksConnectionUserPassword = mksConnectionUserPassword
        self.mksDevPath = mksDevPath
        self.mksHost = mksHost
        self.mksPort = mksPort
        self.projectWorkspace = projectWorkspace
        self.sboxDirectory = sboxDirectory

    def createOrResyncSandbox(self):
        print("Going to check if project '%s' exists in MKS" % self.mksDevPath)
        commandLine = "si projectinfo --batch --hostname=%s --port=%s --user=%s --password=%s --project=%s --noacl --noattributes --nodevpaths --noshowCheckpointDescription --noassociatedIssues" %\
                      (self.mksHost, self.mksPort, self.mksConnectionUser, self.mksConnectionUserPassword,
                       self.mksDevPath)

        self.cliProcHandler.SiCLIHandler_wait(commandLine)
        print("MKS project exists")

        sandboxToCheck = self.projectWorkspace + os.sep + self.sboxDirectory
        sandboxToHandle = sandboxToCheck + os.sep + self.PROJECT_FILENAME

        print("Going to check, if sandbox '%s' already exists on local system" % sandboxToHandle)
        sandboxMKSCheck = check_sandbox(self.mksConnectionUser, self.mksHost, self.mksPort, sandboxToCheck,
                                        self.PROJECT_FILENAME)

        statusSB = sandboxMKSCheck.checkSandbox()

        # We have to contact MKS to get information if sandbox is already available on local disk
        # Checking for local folder is not sufficient because information is still "stored" in Integrity Client
        # If sandbox is not available, it will throw an error and we are able to deal with it
        # (Yes, this is not the best solution but it is a working solution)
        # Moreover, we don't want to display error message, because it is 'ok' if no sandbox will be found
        if statusSB == sandboxMKSCheck.RESYNC:
            print("Sandbox already exists on local system. Will update it.")
            # Sandbox is already available, update local one
            sandboxMKSResync = resync_sandbox(self.mksConnectionUser, self.mksConnectionUserPassword, self.mksHost,
                                              self.mksPort, self.projectWorkspace, self.sboxDirectory)
            return sandboxMKSResync.resyncSandbox()
        if statusSB == sandboxMKSCheck.EXISTINGMKS:
            print("Sandbox only exists in MKS but not on local system. Will drop it.")
            # Sandbox is already available, update local one
            deleteOption = "None"
            sandboxMKSDrop = drop_sandbox(self.mksConnectionUser, self.mksConnectionUserPassword, self.mksHost,
                                              self.mksPort, sandboxToHandle, deleteOption)
            if sandboxMKSDrop.dropSandbox() != 0:
                print("Failed to drop sandbox")
                return 1
        if statusSB == sandboxMKSCheck.NA or statusSB == sandboxMKSCheck.EXISTINGMKS:
            print("Sandbox does not yet exist on local system. Will create it.")
            # Sandbox is not yet available, have to create it
            sandboxMKSCreate = create_sandbox(self.mksConnectionUser, self.mksDevPath, self.mksHost, self.mksPort,
                                              self.projectWorkspace, self.sboxDirectory)
            return sandboxMKSCreate.createSandbox()
        else:
            raise RuntimeError("not expected return code")


def main():
    mksConnectionUser = str(sys.argv[1])
    mksConnectionUserPassword = str(sys.argv[2])
    mksDevPath = str(sys.argv[3])
    imsHost = str(sys.argv[4])
    imsPort = str(sys.argv[5])
    projectWorkspace = str(sys.argv[6])
    sboxDirectory = str(sys.argv[7])

    if len(sys.argv) != 8:
        return 1

    createOrResyncSandbox = createOrResync_sandbox(mksConnectionUser, mksConnectionUserPassword, mksDevPath, imsHost,
                                                   imsPort, projectWorkspace, sboxDirectory)
    return createOrResyncSandbox.createOrResyncSandbox()

if __name__ == "__main__":
    sys.exit(main())
