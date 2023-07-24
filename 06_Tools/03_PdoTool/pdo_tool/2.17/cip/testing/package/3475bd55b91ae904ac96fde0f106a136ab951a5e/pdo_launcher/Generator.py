import sys

# implemented modules
import Logger
import Utility
import Container

LauncherData = Container.LauncherData


# variables in which to store mandatory paths
temp_folder_path = ""
scan_path = ""
tool_path = ""
logs_out_path = ""
dat_out_path = ""
a2l_sdl_out_path = ""
converted_map_in_path = ""


# function that initialises the global variables with the given params
def initGenerator():
    global temp_folder_path
    global scan_path
    global tool_path
    global logs_out_path
    global dat_out_path
    global a2l_sdl_out_path
    global converted_map_in_path

    temp_folder_path = LauncherData.Paths.temp_folder_path
    scan_path = LauncherData.Paths.pdo_package_path
    tool_path = LauncherData.Paths.pdo_package_path
    logs_out_path = LauncherData.Paths.logs_out_path
    dat_out_path = LauncherData.Paths.dat_out_path
    a2l_sdl_out_path = LauncherData.Paths.a2l_sdl_out_path
    converted_map_in_path = LauncherData.Paths.converted_map_in_path


# function used to generate the PDO Scan command array
def generatePDOScanCommandArray(core_count):
    Logger.logEvent("Generating PDO Scan command array...")
    number_of_threads = 0
    thread_counter = 1

    scan_files_path_array = Utility.getScanFilesPathArray()
    paths_array = Utility.createDATOutFileStructure(scan_files_path_array)
    LauncherData.Arrays.scan_out_dat_array = paths_array

    number_of_files_in_target = len(paths_array)
    if number_of_files_in_target >= core_count:
        Logger.logEvent(
            "Number of files to be scanned: {} is greater or equal to CPU core count: {}".format(
                                                                                number_of_files_in_target, core_count))
        Logger.logEvent("Number of threads will be set to: {}".format(core_count))
        number_of_threads = core_count
    else:
        Logger.logEvent(
            "Number of files to be scanned: {} is less than CPU core count: {}".format(number_of_files_in_target,
                                                                                       core_count))
        Logger.logEvent("Number of threads will be set to: {}".format(number_of_files_in_target))
        number_of_threads = number_of_files_in_target

    while thread_counter <= number_of_threads:
        scan_command = "{}/pdo_scan.exe -l {}/pdo_scan_t{}.log ".format(scan_path, logs_out_path, thread_counter)

        nr_commands = len(LauncherData.Arrays.sc_parameters_array)
        index = 0
        while index < nr_commands:
            scan_command = "{}{} ".format(scan_command, LauncherData.Arrays.sc_parameters_array[index])
            index += 1

        scan_command = "{}@{}/target_t{}.txt".format(scan_command, temp_folder_path, thread_counter)
        LauncherData.Arrays.scan_command_array.append(scan_command)
        thread_counter += 1

    Logger.logEvent("Generation of PDO Scan command array completed")
    Logger.logPDOScanCommandArray()
    generateCommandFiles(scan_files_path_array, paths_array, number_of_files_in_target, number_of_threads)

    LauncherData.number_of_threads = number_of_threads


# function that will generate the command files for each thread
def generateCommandFiles(c_paths_array, dat_paths_array, number_of_files_in_target, number_of_threads):
    Logger.logEvent("Generating command files...")
    Logger.logEvent("Number of files to be scanned: {}".format(number_of_files_in_target))
    thread_counter = 1
    path_counter = 0

    # casting to int type in oder to obtain a whole number, in case the number of files to be scanned is odd
    files_to_scan_on_thread = int(number_of_files_in_target / number_of_threads)
    # in the eventuality that the number of files to be scanned is odd, the following line will obtain the remaining
    # number of files, that the previous line did not manage to 'catch'
    remaining_files = number_of_files_in_target - files_to_scan_on_thread * number_of_threads

    while thread_counter <= number_of_threads:
        try:
            command_file = open("{}/target_t{}.txt".format(temp_folder_path, thread_counter), 'w')
            path_inserted_counter = 0

            if thread_counter != number_of_threads:
                while path_counter < files_to_scan_on_thread * thread_counter:
                    if path_counter < files_to_scan_on_thread * thread_counter - 1:
                        command_file.write("-o {}\n".format(dat_paths_array[path_counter]))
                        command_file.write("{}\n".format(c_paths_array[path_counter]))
                    else:
                        command_file.write("-o {}\n".format(dat_paths_array[path_counter]))
                        command_file.write("{}".format(c_paths_array[path_counter]))
                    path_counter += 1
                    path_inserted_counter += 1
            else:
                while path_counter < files_to_scan_on_thread * thread_counter + remaining_files:
                    if path_counter < files_to_scan_on_thread * thread_counter + remaining_files - 1:
                        command_file.write("-o {}\n".format(dat_paths_array[path_counter]))
                        command_file.write("{}\n".format(c_paths_array[path_counter]))
                    else:
                        command_file.write("-o {}\n".format(dat_paths_array[path_counter]))
                        command_file.write("{}".format(c_paths_array[path_counter]))
                    path_counter += 1
                    path_inserted_counter += 1

            command_file.close()
            Logger.logEvent("File: target_t{}.txt created contains number of paths: {}".format(thread_counter,
                                                                                               path_inserted_counter))
        except IOError:
            Logger.logError("cannot open {}/target_t{}.txt\n                      -> Incorrect path or disk is full".format(
                                                                                           temp_folder_path, thread_counter))
            sys.exit()
        thread_counter += 1

    Logger.logEvent("Generation of command files completed")


# function that generates the command array used to call PDO Tool (pl script, merge, sdl ...)
def generatePDOToolCommandArray():
    xmldat_length = len(LauncherData.Arrays.xmldat10_parameters_array)
    sdl_length = len(LauncherData.Arrays.sdl20_parameters_array)
    asap2_length = len(LauncherData.Arrays.asap2_parameters_array)
    textdat_length = len(LauncherData.Arrays.textdat_parameters_array)
    tool_command = ""

    Logger.logEvent("Generating PDO Tool command array...")

    merge_files_path_array = Utility.getMergeFilesPathArray()
    LauncherData.Arrays.merge_in_dat_array = Utility.createDATOutFileStructure(merge_files_path_array)
    generateMergeDatList()

    # get the name of the project
    # will be used to name the .dat, .sdl and .a2l files
    project_name = Utility.getProjectName()

    # generate tool call for ordered xmldat1.0 format
    tool_command = "{}/pdo_tool.exe --enable ordered_output @{}/merge_dat_list.txt -f xmldat1.0 -l {} -o {}/{}_sorted.dat".format(
                                                                      tool_path, temp_folder_path, logs_out_path, dat_out_path,project_name)
    LauncherData.Arrays.tool_command_array.append(tool_command)

    # write tool call for sdl2.0 format
    if sdl_length > 0:
        appendSDLCommands(project_name, LauncherData.Arrays.sdl20_parameters_array)
    # write tool call for asap2 format
    if asap2_length > 0:
        appendA2LCommands(project_name, LauncherData.Arrays.asap2_parameters_array)

    Logger.logEvent("Generation of PDO Tool command array completed")
    Logger.logPDOToolCommandArray()


# function that will create a command file with all the .dat file paths given to the PDO Tool as input
def generateMergeDatList():
    number_of_files_in_target = len(LauncherData.Arrays.merge_in_dat_array)
    Logger.logEvent("Generating merge target list files...")
    Logger.logEvent("Number of files to be merged: {}".format(number_of_files_in_target))
    try:
        merge_dat_list_file = open("{}/merge_dat_list.txt".format(temp_folder_path), 'w')
        Logger.logEvent("File created: {}/merge_dat_list.txt".format(temp_folder_path))

        path_counter = 0
        for dat_path in LauncherData.Arrays.merge_in_dat_array:
            merge_dat_list_file.write("{}\n".format(dat_path))
            path_counter += 1
        merge_dat_list_file.close()
        Logger.logEvent("File: merge_dat_list.txt created contains number of paths: {}".format(path_counter))
    except IOError:
        Logger.logError("cannot open {}/merge_dat_list.txt\n                      -> Incorrect path or disk is full".format(
                                                                                                           temp_folder_path))
        sys.exit()
    Logger.logEvent("Generation of merge target list file completed")


# function that will append the SDL set of command to the tool command array
def appendSDLCommands(project_name, parameters_array):
    tool_command = "{}/pdo_tool.exe -f sdl2.0 -l {}/pdo_sdl.log {}/{}_sorted.dat ".format(tool_path, logs_out_path, dat_out_path,
                                                                                          project_name)
    for parameter in parameters_array:
        tool_command = "{}{} ".format(tool_command, parameter)

    tool_command = "{}-o {}/{}.sdl".format(tool_command, a2l_sdl_out_path, project_name)
    LauncherData.Arrays.tool_command_array.append(tool_command)

# function that will append the A2L set of command to the tool command array
def appendA2LCommands(project_name, parameters_array):

    # generate tool call for ordered xmldat1.0 format, merged with the map file
    # MM = Merged with Map
    # if we do not enable the ordered output, even tho we are using a sorted .dat file, by merging with
    # the map file, the output will not be sorted
    tool_command = "{}/pdo_tool.exe --enable ordered_output {}/{}_sorted.dat -f xmldat1.0 -l {} -o {}/{}_MM_sorted.dat -c {}".format(
        tool_path, dat_out_path, project_name, logs_out_path, dat_out_path,
        project_name, converted_map_in_path)
    LauncherData.Arrays.tool_command_array.append(tool_command)

    tool_command = "{}/pdo_tool.exe -f asap2 -l {}/pdo_a2l.log {}/{}_MM_sorted.dat ".format(tool_path, logs_out_path, dat_out_path,
                                                                                            project_name)
    for parameter in parameters_array:
        tool_command = "{}{} ".format(tool_command, parameter)

    tool_command = "{}-o {}/{}.a2l".format(tool_command, a2l_sdl_out_path, project_name)
    LauncherData.Arrays.tool_command_array.append(tool_command)

