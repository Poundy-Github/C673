import ConfigParser
import datetime
import re
import os
import sys

# implemented modules
import Logger
import Container

LauncherData = Container.LauncherData
OperatingMode = Container.OperatingMode
config_parser = None


# function that extracts the config file path from the command lines
# then stores it in the corresponding variable
def setConfigFilePath(arguments):
    # 1 - the position where it expects to find the -config_path command
    if arguments[1] == "-config_path":
        # 2 - the position where it expects to find input for the -config_path command
        pattern_match = re.search(r'.*\.cfg$', arguments[2])
        if pattern_match is not None:
            LauncherData.Paths.config_file_path = pattern_match.string
        else:
            sys.exit("ERROR: no valid config file path has been provided as input")
    else:
        sys.exit("ERROR: '-config_path' command has not been requested")


# function that parses the config file and store the data in the LauncherData object
def processStartupConfigFile():
    global config_parser
    config_parser = ConfigParser.ConfigParser()
    try:
        if config_parser.read(LauncherData.Paths.config_file_path):
            # if the config parser was able to read the file, the Launcher will continue it's execution
            pass
        else:
            # if it was not able to read the file, it will raise an exception
            raise IOError("ERROR: could not open {}".format(LauncherData.Paths.config_file_path))
    except IOError, error:
        sys.exit(error)

    # store values from the PATH section
    LauncherData.Paths.temp_folder_path = getConfigOptionValue("PATH", "temp_folder")
    LauncherData.Paths.pdo_package_path = getConfigOptionValue("PATH", "pdo_package")
    LauncherData.Paths.logs_out_path = getConfigOptionValue("PATH", "logs_out")
    LauncherData.Paths.dat_out_path = getConfigOptionValue("PATH", "dat_out")
    LauncherData.Paths.a2l_sdl_out_path = getConfigOptionValue("PATH", "a2l_sdl_out")

    # store values from the INPUT section
    LauncherData.Paths.scan_input_list_path = getConfigOptionValue("INPUT", "scan_list")
    LauncherData.Paths.merge_input_list_path = getConfigOptionValue("INPUT", "merge_list")
    LauncherData.Paths.include_headers_list_path = getConfigOptionValue("INPUT", "include_headers_list")
    LauncherData.Paths.converted_map_in_path = getConfigOptionValue("INPUT", "converted_map_file")


# function that will return the value of a given section and option, from the configuration file
def getConfigOptionValue(section, option):
    try:
        option_value = config_parser.get(section, option)

        if option_value != "":
            if option == "include_headers_list":
                LauncherData.Flags.include_headers_list_path_provided = True
            pass
        else:
            if option != "include_headers_list":
                raise ValueError("Missing value for option: '{}'".format(option))
            else:
                LauncherData.Flags.include_headers_list_path_provided = False

    except ConfigParser.NoSectionError, error:
        sys.exit("ERROR: {}".format(error))
    except ConfigParser.NoOptionError, error:
        if option != "include_headers_list":
            sys.exit("ERROR: {}".format(error))
        else:
            # this needs to be done because if the option is missing, option_value will have no definition
            # and we will get an error when trying to return it
            option_value = ""
            LauncherData.Flags.include_headers_list_path_provided = False
    except ValueError, error:
        sys.exit("ERROR: {}".format(error))

    option_value = convertRelativeToRealPath(option_value)
    return option_value


# function that will convert the relative path to a real path
def convertRelativeToRealPath(path):
    return os.path.realpath(path)

# function that removes all the \n characters from a given string array
# this in necessary as we do not want any foreign characters that might cause generation to produce faulty scripts
def removeNewLine(lines):
    lines = [line.strip() for line in lines]
    return lines


# function that extracts the parameter from the command line
def processCommandLine(arguments):
    command_line = readCommandLine(arguments)

    if LauncherData.Flags.conditions_OK is True:
        command_line = setOperatingMode(command_line)
        if LauncherData.current_operating_mode == OperatingMode.scanMode:
            Logger.openLogFile("SCAN")
            Logger.logEvent("Current Operating Mode: SCAN MODE")
            storePDOScanData(command_line)
        else:
            if LauncherData.current_operating_mode == OperatingMode.mergeMode:
                Logger.openLogFile("MERGE")
                Logger.logEvent("Current Operating Mode: MERGE MODE")
                storePDOToolData(command_line)
            else:
                LauncherData.Flags.conditions_OK = False
                sys.exit("ERROR: No operating mode has been provided by user")


# extracts the project name from the .map input
def getProjectName():
    match = re.search(r'[\\|/]([\w\d_]*).map$', LauncherData.Paths.converted_map_in_path)
    name = match.group(1)
    return name


# function that reads all input from the command line and returns an array with the relevant parameters
def readCommandLine(arguments):
    command_line = []
    index = 1
    sufficient_params = False

    if len(arguments) <= 1:
        sufficient_params = False
        sys.exit("ERROR: Insufficient number of parameters")
    else:
        sufficient_params = True

    while index < len(arguments):
        command_line.append(arguments[index])
        index += 1

    LauncherData.Flags.conditions_OK = sufficient_params

    return command_line


# function that will clone the folder structure of the target input file and replace the extension .c with .dat
# will return an array containing the structure list
def createDATOutFileStructure(path_array):
    Logger.logEvent("Creating .dat output folder structure array...")
    index = 0
    path_length = len(path_array)
    new_path_array = []

    if path_length != 0:
        while index < path_length:
            folder_structure_array = path_array[index].split("\\")
            folder_structure_length = len(folder_structure_array)
            # generic counter variable that will be used multiple times during the execution of this function
            counter = 1
            new_path = ""

            while counter < folder_structure_length:
                new_path = "{}/{}".format(new_path, folder_structure_array[counter])
                counter += 1

            new_path = "{}{}".format(LauncherData.Paths.dat_out_path, new_path)
            # will remove the extension 'c' from the file path
            new_path = new_path[:-1]
            new_path = "{}dat".format(new_path)
            new_path_array.append(new_path)

            index += 1

        Logger.logEvent("Finished creating .dat output folder structure array")
    else:
        Logger.logError("there were no paths given")

    return new_path_array


# function that will create a folder structure from a given parameter
def createOutFolderStructure(path_array):
    Logger.logEvent("Creating folder structure...")
    created_folders_structures = 0
    duplicate_folder_structures = 0
    # variable used to store the number of warning for paths that go over the 256 MAX_PATH limitation
    warnings = 0

    for path in path_array:
        path_length = len(path)
        if path_length >= 256:
            warnings += 1
            Logger.logWarning("path - {} has {}. 256 character limitation has been exceeded".format(path, path_length))

        tmp_array = path.split("/")
        tmp_array_length = len(tmp_array)
        index = 0
        folder_structure = ""

        while index < tmp_array_length - 1:
            folder_structure = "{}/{}".format(folder_structure, tmp_array[index])
            index += 1
        # remove the '/' character that will be added at the beginning of the path
        folder_structure = folder_structure[1:]

        if not os.path.isdir(folder_structure):
            os.makedirs(folder_structure)
            created_folders_structures += 1
            Logger.logEvent("PATH CREATED: {}".format(folder_structure))
        else:
            duplicate_folder_structures += 1
            Logger.logEvent("PATH EXISTS: {}".format(folder_structure))

    Logger.logEvent("Number of created folder structures: {}".format(created_folders_structures))
    Logger.logEvent("Number of duplicate folder structures found: {}".format(duplicate_folder_structures))
    Logger.logEvent("Number of exceeded path character limitation WARNINGS: {}".format(warnings))
    Logger.logEvent("Creation of folder structure completed")


# function that will extract every path from the given command file and return it in the form of an array
def getScanFilesPathArray():
    try:
        command_file = open(LauncherData.Paths.scan_input_list_path, 'r')
        command_files_path_array = command_file.readlines()
        command_file.close()
        command_files_path_array = removeNewLine(command_files_path_array)
    except IOError:
        Logger.logError("could not open file: {}".format(LauncherData.Paths.scan_input_list_path))
        sys.exit()

    return command_files_path_array


# function that will extract every path from the given command file and return it in the form of an array
def getMergeFilesPathArray():
    command_file = open(LauncherData.Paths.merge_input_list_path, 'r')
    command_file_path_array = command_file.readlines()
    command_file.close()
    command_file_path_array = removeNewLine(command_file_path_array)

    return command_file_path_array


# function that will return the current operating mode
# will also remove the -..._mode from the command line and return that as well
def setOperatingMode(command_line):
    operating_mode = None
    # remove the first 2 elements from the list (-config_path and the path itself)
    command_line = command_line[2:]
    if command_line[0] == "-scan_mode":
        operating_mode = OperatingMode.scanMode
        command_line.pop(0)
    else:
        if command_line[0] == "-merge_mode":
            operating_mode = OperatingMode.mergeMode
            command_line.pop(0)

    LauncherData.current_operating_mode = operating_mode

    return command_line


# function that stores the PDO Scan params from the command line
def storePDOScanData(command_line):
    sc_command_array = []

    index = 0
    number_of_params = len(command_line)
    while index < number_of_params:
        sc_command_array.append(command_line[index])
        index += 1

    index = 0
    # rearranging the parameter list in such a way that the -c commands will be the first
    # this is a countermeasure in case the user specifies the file for parsing before the configuration
    command_array = []
    while index < number_of_params:
        if sc_command_array[index] == "-c":
            command_array.append(sc_command_array[index])
            command_array.append(sc_command_array[index + 1])
        index += 1

    for item in command_array:
        sc_command_array.remove(item)
    size = len(command_array)
    index = size - 1
    while index >= 0:
        sc_command_array.insert(0, command_array[index])
        index -= 1

    if LauncherData.Flags.include_headers_list_path_provided:
        sc_command_array.append("-c")
        sc_command_array.append(LauncherData.Paths.include_headers_list_path)

    sc_command_array.insert(0, "-s")
    for item in sc_command_array:
        Logger.logEvent("PDO Scan param:{}".format(item))

    LauncherData.Arrays.sc_parameters_array = sc_command_array


# function that stores the PDO Tool params from the command line in the appropriate array and returns them
# will also return the value of list_provided to the conditions_OK variable
def storePDOToolData(command_line):
    xmldat10_command_array = []
    sdl20_command_array = []
    asap2_command_array = []
    textdat_command_array = []

    # dictionary in which we store all format types
    # by default, each format type has the index -1, meaning that they are not present in the command line
    # if encountered in the command line, the value will be that of the command line index
    format_types = {'xmldat1.0': -1, 'asap2': -1, 'sdl2.0': -1, 'textdat': -1}
    format_types = getFormatTypesDictionary(command_line, format_types)
    if format_types['xmldat1.0'] is not -1:
        xmldat10_command_array = getParametersArray(command_line, format_types['xmldat1.0'])
    if format_types['asap2'] is not -1:
        asap2_command_array = getParametersArray(command_line, format_types['asap2'])
    if format_types['sdl2.0'] is not -1:
        sdl20_command_array = getParametersArray(command_line, format_types['sdl2.0'])
    if format_types['textdat'] is not -1:
        textdat_command_array = getParametersArray(command_line, format_types['textdat'])

    LauncherData.Arrays.xmldat10_parameters_array = xmldat10_command_array
    LauncherData.Arrays.sdl20_parameters_array = sdl20_command_array
    LauncherData.Arrays.asap2_parameters_array = asap2_command_array
    LauncherData.Arrays.textdat_parameters_array = textdat_command_array


# function that check for format types in the command line
# if found, the index of will be stored for the specific format type
def getFormatTypesDictionary(command_line, format_collection):
    size = len(command_line)
    index = 0
    while index < size:
        if command_line[index] == "xmldat1.0":
            format_collection['xmldat1.0'] = index
        else:
            if command_line[index] == "asap2":
                format_collection['asap2'] = index
            else:
                if command_line[index] == "sdl2.0":
                    format_collection['sdl2.0'] = index
                else:
                    if command_line[index] == "textdat":
                        format_collection['textdat'] = index
        index += 1
    return format_collection


# function that will return an array with the parameters from a specific range
def getParametersArray(command_array, index):
    parameters_array = []
    command_array_length = len(command_array)
    format_type_found = False

    # increment the index by 1, because by default it will be the index of the format type,
    # but we are interested in the values that come after
    index += 1
    while index < command_array_length and format_type_found is False:
        format_type_found = checkIfDataIsFormatType(command_array[index])
        if format_type_found is False:
            parameters_array.append(command_array[index])
        index += 1

    return parameters_array


# function that will return a flag is a the data is a format type or not
def checkIfDataIsFormatType(data):
    format_type_found = False

    if data == 'xmldat1.0':
        format_type_found = True
    else:
        if data == 'asap2':
            format_type_found = True
        else:
            if data == 'sdl2.0':
                format_type_found = True
            else:
                if data == 'textdat':
                    format_type_found = True

    return format_type_found


# function that calls the PDO Scan to either perform a single scan or threading scan, depending on the input
def callPDOScan():
    Logger.logEvent("Starting PDO Scan process...")
    createOutFolderStructure(LauncherData.Arrays.scan_out_dat_array)
    time_start = datetime.datetime.now()
    Logger.logEvent("Calling PDO Scan on {} threads".format(LauncherData.number_of_threads))
    counter = 1
    thread_list = []
    while counter <= LauncherData.number_of_threads:
        scan_thread = Container.ScanThread(counter)
        scan_thread.start()
        thread_list.append(scan_thread)
        counter += 1

    # wait for all threads to complete before moving on with the rest of the execution
    for scan_thread in thread_list:
        scan_thread.join()

    time_end = datetime.datetime.now()
    Logger.logEvent("PDO Scan process execution completed, elapsed time - {}".format(time_end - time_start))


# function that calls the PDO Tool
def callPDOTool():
    Logger.logEvent("Starting PDO Tool process...")
    time_start = datetime.datetime.now()
    number_of_commands = len(LauncherData.Arrays.tool_command_array)
    index = 0
    while index < number_of_commands:
        command = LauncherData.Arrays.tool_command_array[index]
        os.system(command)
        index += 1
    time_end = datetime.datetime.now()
    Logger.logEvent("PDO Tool process execution completed, elapsed time - {}".format(time_end - time_start))
