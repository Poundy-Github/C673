import sys
import os

sys.path.append(os.path.dirname(os.path.realpath(__file__)) + os.sep + os.pardir)
from CLI_tools import cli_proc_handler


class drop_sandbox:
    # Parameter deleteOption:
    # - Value 'None' if sandbox is registered in MKS on local node but not available on local filesystem
    # - Use value 'members' in case of dropping sandbox which is available on local MKS and local filesystem
    def __init__(self, mksConnectionUser, mksConnectionUserPassword, mksHost, mksPort, sandboxToDrop, deleteOption):
        self.cliProcHandler = cli_proc_handler()
        self.mksConnectionUser = mksConnectionUser
        self.mksConnectionUserPassword = mksConnectionUserPassword
        self.mksHost = mksHost
        self.mksPort = mksPort
        self.sandboxToDrop = sandboxToDrop
        self.deleteOption = deleteOption

    def dropSandbox(self):
        print("Drop for user '%s' the sandbox '%s' " % (self.mksConnectionUser, self.sandboxToDrop))

        commandLine = "si dropsandbox --batch --hostname=%s --port=%s --user=%s --password=%s -f --yes --delete=%s %s" \
                      % (self.mksHost, self.mksPort, self.mksConnectionUser, self.mksConnectionUserPassword,
                         self.deleteOption, self.sandboxToDrop)

        return self.cliProcHandler.SiCLIHandler_wait(commandLine, self.cliProcHandler.MODE_RETURN)

def main():
    mksConnectionUser = str(sys.argv[1])
    mksConnectionUserPassword = str(sys.argv[2])
    mksHost = str(sys.argv[3])
    mksPort = str(sys.argv[4])
    sboxDirectory = str(sys.argv[5])
    deleteOption = str(sys.argv[6])

    if len(sys.argv) != 7:
        return 1

    sandboxMksDrop = drop_sandbox(mksConnectionUser, mksConnectionUserPassword, mksHost, mksPort, sboxDirectory,
                                  deleteOption)
    return sandboxMksDrop.dropSandbox()


if __name__ == "__main__":
    sys.exit(main())
