import threading  # needed for ScanThread class
import os

# implemented modules
import Logger

Compiler_Converter_Dictionary = {'DIAB': 'diab_mapconv.pl',
                                 'GHS': 'ghs_mapconv.pl',
                                 'MWCW': 'mwcw_mapconv.pl'}


# class definition that contains all the essential data required by the Launcher
class LauncherData:
    # variable that will store the number of threads that will be used to perform the Scan
    # by default it's 0, but the number will be changed when the PDO Scan scripts are being generated
    number_of_threads = 0
    # variable used to store the current operation mode that the script is in. It can be in either "Scan Mode"
    # or "Merge Mode"
    current_operating_mode = None

    class Paths:
        # variables in which to store mandatory paths
        config_file_path = ""
        temp_folder_path = ""
        # variable used to store the path to the PDO release folder
        pdo_package_path = ""
        logs_out_path = ""
        dat_out_path = ""
        a2l_sdl_out_path = ""
        converted_map_in_path = ""
        # variable used to store the location of the command file containing the paths to the .c files
        # that need to be scanned
        scan_input_list_path = ""
        # variable used to store the location of the command file containing the paths to the .c files
        # that need to be merged
        merge_input_list_path = ""
        # variable used to store the location of the file containing the list of all the headers that
        # need to be scanned
        include_headers_list_path = ""

    class Arrays:
        # arrays in which all specific parameters shall be stored
        sc_parameters_array = []
        xmldat10_parameters_array = []
        sdl20_parameters_array = []
        asap2_parameters_array = []
        textdat_parameters_array = []
        # array used to store the paths of all the .dat files that need to be created by PDO Scan
        scan_out_dat_array = []
        # array used to store the paths of all the .dat files that need to be merged by PDO Tool
        merge_in_dat_array = []
        # array used to store all the commands that will invoke the PDO Scan
        scan_command_array = []
        # array used to store all the commands that will invoke the PDO Tool
        tool_command_array = []

    class Flags:
        # generic flag used to see if several condition are OK, enough params, user has given mandatory input and so on
        # if not, the PDO will end it's execution at the first FALSE value hit
        conditions_OK = False
        # flag used to see if the user has provided the path to a list with headers files that need to be scanned
        include_headers_list_path_provided = False


# class used to define the operating modes available to the Launcher
class OperatingMode:
    scanMode = 0
    mergeMode = 1


# definition of the Thread class required for the usage of threading, introduced in Python 2.4
class ScanThread(threading.Thread):
    def __init__(self, id):
        threading.Thread.__init__(self)
        self.id = id

    def run(self):
        runScan(self.id)


# function that starts the PDO scan script, for each id it starts the corresponding script
def runScan(id):
    Logger.logEvent("Calling PDO Scan on thread: {} ".format(id))
    os.system(LauncherData.Arrays.scan_command_array[id-1])
