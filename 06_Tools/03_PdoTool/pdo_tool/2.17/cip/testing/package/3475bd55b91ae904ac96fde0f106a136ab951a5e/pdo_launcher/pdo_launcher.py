import multiprocessing
import sys
import os

# implemented modules
import Logger
import Generator
import Utility
import Container

# used as an equivalent for the #define used in C
# the 'global' keyword is not needed as this is treated as a reference to a 'static' class
LauncherData = Container.LauncherData
OperatingMode = Container.OperatingMode


# definition of the main function
def main():
    initLauncher()
    if LauncherData.Flags.conditions_OK:
        generatePDOcommands()
        callPDOToolSet()
    endExecutionCleanup()


# function used to initialize all the variables required for the PDO Launcher
def initLauncher():
    Utility.setConfigFilePath(sys.argv)
    Utility.processStartupConfigFile()
    Utility.processCommandLine(sys.argv)
    Generator.initGenerator()

    if LauncherData.Flags.conditions_OK:
        Logger.logInitParams()

        # if we do not already have a temp folder, this will create one
        # here is where PDO_Launcher will put all the files it generated that are required for running the PDO process
        if not os.path.exists(LauncherData.Paths.temp_folder_path):
            os.makedirs(LauncherData.Paths.temp_folder_path)
            Logger.logEvent("Temp folder created at : {}".format(LauncherData.Paths.temp_folder_path))
        else:
            Logger.logEvent("Temp folder already exists at : {}".format(LauncherData.Paths.temp_folder_path))


# function used to cleanup (close opened files etc.) before terminating the script
def endExecutionCleanup():
    if LauncherData.Flags.conditions_OK:
        Logger.printLauncherErrorsAndWarningsCount()
        Logger.logEvent("Preparing to finish Launcher execution")
        Logger.closeLogFile()


# function that generates the PDO Scan and Tool scripts, depending on the user input
def generatePDOcommands():
    if LauncherData.current_operating_mode == OperatingMode.scanMode:
        core_count = multiprocessing.cpu_count()
        Generator.generatePDOScanCommandArray(core_count)
    else:
        if LauncherData.current_operating_mode == OperatingMode.mergeMode:
            Generator.generatePDOToolCommandArray()


# function that will call either PDO Scan or Tool, depending on the operating mode
def callPDOToolSet():
    if LauncherData.current_operating_mode == OperatingMode.scanMode:
        Utility.callPDOScan()
    else:
        if LauncherData.current_operating_mode == OperatingMode.mergeMode:
            Utility.callPDOTool()


# call of the main function
main()
