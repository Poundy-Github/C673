import datetime

# implemented modules
import Container

LauncherData = Container.LauncherData

# global object used to store the launcher log file
launcher_log_file = None

# variables used to count the number of warning and errors encountered during the PDO Launcher's execution
warnings_encountered = 0
errors_encountered = 0

# function that will open the file used for logging
def openLogFile(log_name):
    global launcher_log_file
    try:
        launcher_log_file = open("{}/pdo_launcher_{}.log".format(LauncherData.Paths.logs_out_path, log_name), 'w')
    except IOError:
        print "ERROR : Could not open {}/pdo_launcher_{}.log".format(LauncherData.Paths.logs_out_path, log_name)

# function that will close the file used for logging
def closeLogFile():
    global launcher_log_file
    launcher_log_file.close()

# function that will log all the parameters as they are read from the configuration file
def logInitParams():
    # current Date Time
    current_datetime = datetime.datetime.now()

    launcher_log_file.write(
        "{}/{}/{} {}:{}:{} -- Given configuration:\n".format(current_datetime.day, current_datetime.month, current_datetime.year,
                                                             current_datetime.hour, current_datetime.minute, current_datetime.second))
    launcher_log_file.write("   [PATH] Section:\n")
    launcher_log_file.write("       Temp Folder           : {}\n".format(LauncherData.Paths.temp_folder_path))
    launcher_log_file.write("       PDO Package           : {}\n".format(LauncherData.Paths.pdo_package_path))
    launcher_log_file.write("       Log Files Output      : {}\n".format(LauncherData.Paths.logs_out_path))
    launcher_log_file.write("       Dat Files Output      : {}\n".format(LauncherData.Paths.dat_out_path))
    launcher_log_file.write("       A2l/SDL File Output   : {}\n".format(LauncherData.Paths.a2l_sdl_out_path))
    launcher_log_file.write("   [INPUT] Section:\n")
    launcher_log_file.write("       Scan List             : {}\n".format(LauncherData.Paths.scan_input_list_path))
    launcher_log_file.write("       Merge List            : {}\n".format(LauncherData.Paths.merge_input_list_path))
    if LauncherData.Flags.include_headers_list_path_provided:
        launcher_log_file.write("       Include headers list  : {}\n".format(LauncherData.Paths.include_headers_list_path))
    launcher_log_file.write("       Converted Map File    : {}\n".format(LauncherData.Paths.converted_map_in_path))


# function used to log every action that the Launcher takes
def logEvent(event_data):
    # current Date Time
    current_datetime = datetime.datetime.now()

    launcher_log_file.write(
        "{}/{}/{} {}:{}:{} -- ".format(current_datetime.day, current_datetime.month, current_datetime.year,current_datetime.hour,
                                       current_datetime.minute, current_datetime.second))
    launcher_log_file.write("{}\n".format(event_data))


# function used to log any warnings encountered
def logWarning(event_data):
    global warnings_encountered

    warnings_encountered += 1
    # current Date Time
    current_datetime = datetime.datetime.now()

    launcher_log_file.write(
        "{}/{}/{} {}:{}:{} -- ".format(current_datetime.day, current_datetime.month, current_datetime.year, current_datetime.hour,
                                       current_datetime.minute, current_datetime.second))
    launcher_log_file.write("WARNING: {}\n".format(event_data))


# function used to log any errors encountered
def logError(event_data):
    global errors_encountered

    errors_encountered += 1
    # current Date Time
    current_datetime = datetime.datetime.now()

    launcher_log_file.write(
        "{}/{}/{} {}:{}:{} -- ".format(current_datetime.day, current_datetime.month, current_datetime.year, current_datetime.hour,
                                       current_datetime.minute, current_datetime.second))
    launcher_log_file.write("ERROR: {}\n".format(event_data))


# function that will log the number of warnings and errors encountered
def printLauncherErrorsAndWarningsCount():
    # current Date Time
    current_datetime = datetime.datetime.now()

    launcher_log_file.write(
        "{}/{}/{} {}:{}:{} -- ".format(current_datetime.day, current_datetime.month, current_datetime.year, current_datetime.hour,
                                       current_datetime.minute, current_datetime.second))
    launcher_log_file.write("PDO Launcher encountered WARNINGS: {}\n".format(warnings_encountered))
    launcher_log_file.write(
        "{}/{}/{} {}:{}:{} -- ".format(current_datetime.day, current_datetime.month, current_datetime.year, current_datetime.hour,
                                       current_datetime.minute, current_datetime.second))
    launcher_log_file.write("PDO Launcher encountered ERRORS: {}\n".format(warnings_encountered))

# function that will log all the commands used to call the PDO Scan
def logPDOScanCommandArray():
    log_file = open("{}/pdo_scan_commands.log".format(LauncherData.Paths.logs_out_path), 'w')

    number_of_commands = len(LauncherData.Arrays.scan_command_array)
    index = 0

    while index < number_of_commands:
        log_file.write("{}\n".format(LauncherData.Arrays.scan_command_array[index]))
        index += 1

    log_file.close()


# function that will log all the commands used to call the PDO Tool
def logPDOToolCommandArray():
    log_file = open("{}/pdo_tool_commands.log".format(LauncherData.Paths.logs_out_path), 'w')

    number_of_commands = len(LauncherData.Arrays.tool_command_array)
    index = 0

    while index < number_of_commands:
        log_file.write("{}\n".format(LauncherData.Arrays.tool_command_array[index]))
        index += 1

    log_file.close()
