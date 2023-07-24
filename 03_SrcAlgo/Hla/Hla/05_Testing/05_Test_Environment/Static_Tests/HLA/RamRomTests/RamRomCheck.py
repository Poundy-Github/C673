import argparse, re, os.path, sys, xlwings, logging
from win32com.universal import com_error

# classification states
NO_TRANSGRESSION = "green"
SLIGHT_TRANSGRESSION = "yellow"
HEAVY_TRANSGRESSION = "red"

# output values
output_values = {
                 NO_TRANSGRESSION : "\"{real}KB, i.e. {usage}% {name} usage  within budget ({bound}KB).\"",
                 SLIGHT_TRANSGRESSION : "\"Warning: {real}KB, i.e. {usage}% {name} usage is slightly above budget ({bound}KB).\"",
                 HEAVY_TRANSGRESSION : "\"Error: {real}KB, i.e. {usage}% {name} usage is heavily above budget ({bound}KB).\"", 
                 }
LOG_FILE_NAME = "RamRomCheck.log"

# regex patterns for finding ram and rom summary in log file 
REGEX_RAM_SUM_IN_LOG = "^ram = ([0-9]*)$"
REGEX_ROM_SUM_IN_LOG = "^rom = ([0-9]*)$"

# default values
DEFAULT_LOG_FILE_PATH = "..\\..\\..\\..\\..\\..\\04_Engineering\\04_Build\\algo\\"
DEFAULT_LOG_FILE_NAMES = {
                          "vh28": "vh28_ramrom.txt", 
                          "vme": "vme_ramrom.txt"
                          }
DEFAULT_RS_LOCATION ="..\\..\\..\\..\\..\\..\\03_Design\\01_Supporting_Documents\\"
DEFAULT_RS_NAME = "MFC401_ResourceSheet.xlsm"
DEFAULT_RAM_BUDGET = 200000
DEFAULT_ROM_BUDGET = 460000
CONVERSION_BASE_FACTOR = 1024
CONVERSION_EXP_MAP = {
                  "kB" : 1,
                  "MB" : 2,
                  "GB" : 3,
                  "TB" : 4,
                  "PB" : 5
                  }

# 'global' variables ; in order to access as global they have to be declared global locally making python use the global variable instead of creating one in the local scope
logger = None

def main():
    # declare 'global' variables to use
    global logger
    
    SANDBOX = os.environ["SANDBOX"] if os.environ.has_key("SANDBOX") else None
    
    parser = initArgparser()
    args = parser.parse_args()
    
    global logger
    logger = initLogger()
    logger.info("SANDBOX = {box}{info}".format(box=SANDBOX, info="" if SANDBOX else "local call"))
    logger.info("Arguments: {args}".format(args=args))
    
    resource_sheet = os.path.abspath(os.path.join(args.resource_sheet_path, args.resource_sheet_name))
    logger.info(resource_sheet)
        
    # command line args have priority
    # read log file and interpret log file; 03_Workspace\algo\hla\sconsbuild.log
    try:
        if not (args.ram_real and args.rom_real):
            log_file_exists = False
            # check if hardware version was selected; otherwise take first existing text/log file
            log_file_path = DEFAULT_LOG_FILE_PATH + args.component_name + "_sim"
            if args.hardware_version:
                log_file = os.path.abspath(os.path.join(log_file_path, DEFAULT_LOG_FILE_NAMES[args.hardware_version]))
                if os.path.exists(log_file):
                    log_file_exists = True
                    logger.info("Using file '{file}' as resource log file.".format(file=log_file))
                else:
                    logger.info("File '{file}' does not exists.".format(file=log_file))
            else:
                for filename in DEFAULT_LOG_FILE_NAMES:
                    log_file = os.path.abspath(os.path.join(log_file_path, DEFAULT_LOG_FILE_NAMES[filename]))
                    if os.path.exists(log_file):
                        log_file_exists = True
                        logger.info("Using file '{file}' as resource log file.".format(file=log_file))
                        break
                    else:
                        logger.info("File '{file}' does not exists.".format(file=log_file))
            if not log_file_exists: raise InputError(InputError.FILE_NOT_FOUND, log_file) 
            ram_usage, rom_usage = readLogFile(log_file)
        if not args.ram_real: 
            if ram_usage: args.ram_real = ram_usage
            else: raise InputError(InputError.MISSING_RAM_USAGE)
        if not args.rom_real:
            if rom_usage: args.rom_real = rom_usage 
            else: raise InputError(InputError.MISSING_ROM_USAGE)
        if not (args.ram_budget and args.rom_budget):
            ram_buffer, rom_buffer = readExcel(resource_sheet, args.component_name, 
                                               args.project_name if args.project_name else getProjectName((SANDBOX.split("\\"))[-1]))
        if not args.ram_budget: 
            if ram_buffer: args.ram_budget = ram_buffer
            else: raise InputError(InputError.MISSING_RAM_BUDGET)
        if not args.rom_budget: 
            if rom_buffer: args.rom_budget = rom_buffer 
            else: raise InputError(InputError.MISSING_ROM_BUDGET)
    except InputError as e:
        logger.error(e)
        print(e)
        return -1
    except Exception as e:
        print("Unexpected Exception:")
        print(repr(e))
        logger.error(repr(e))
        return -1
    else:
        logger.info("Evaluating RAM/ROM budget to usage ratio.")
        # compare values from log file and budget res-file (or from command line input as priority)
        ram = checkBudget(args.ram_budget, args.ram_real, "RAM")
        rom = checkBudget(args.rom_budget, args.rom_real, "ROM")
        # print results and return corresponding return values
        logger.info("Printing results and return corresponding return values.")
        print(ram[0])
        print(rom[0])
        return (ram[1] if ram[1] < 0 else rom[1])
    
def initArgparser():
    parser = argparse.ArgumentParser(description="Python script for measuring/comparing RAM and ROM usage in respect of RAM/ROM budget.")
    parser.add_argument("-bram", action="store", dest="ram_budget", default=None, type=int, help="Budget for RAM in bytes as a number. [Default: 200000 or from resource file]")
    parser.add_argument("-brom", action="store", dest="rom_budget", default=None, type=int, help="Budget for ROM in bytes as a number. [Default: 460000 or from resource file]")
    parser.add_argument("-rram", action="store", dest="ram_real", default=None, type=int, help="Real usage of RAM in bytes as a number. [Default: read from log file]")
    parser.add_argument("-rrom", action="store", dest="rom_real", default=None, type=int, help="Real usage of ROM in bytes as a number. [Default: read from log file]")
    parser.add_argument("-c", action="store", required=True, dest="component_name", help="Name of component to be processed.")
    parser.add_argument("-p", action="store", dest="project_name", default="MFC431", help="Name of project to be processed.")
    parser.add_argument("-rs", action="store", dest="resource_sheet_name", default=DEFAULT_RS_NAME, help="Name of ressource sheet to be processed.")
    parser.add_argument("-rp", action="store", dest="resource_sheet_path", default=DEFAULT_RS_LOCATION, help="Path to ressource sheet to be processed.")
    parser.add_argument("-hw", action="store", dest="hardware_version", default=None, choices=("vme","vh28"), help="Choose vme or vh28 as version to enforce usage of appropiate text/log file.")
    return parser

def initLogger():
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.INFO)
    logger.propagate=True
    file_handler = logging.FileHandler(os.path.join(".", LOG_FILE_NAME), mode="w")
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    file_handler.setLevel(logging.INFO)
    file_handler.setFormatter(formatter)
    logger.addHandler(file_handler)
    logger.info("(Logger initiated {logger})".format(logger=__name__))
    return logger

def checkBudget(bound, real, name="RAM"):
    pct = round((float(real) / bound) * 100.0, 1)
    rtn_val = 0
    
    if pct < 100.0:
        value = output_values[NO_TRANSGRESSION]
        rtn_val = 0
    elif pct > 105.0: 
        value = output_values[HEAVY_TRANSGRESSION]
        rtn_val = -1
    else:
        value = output_values[SLIGHT_TRANSGRESSION]
        rtn_val = 0
    
    return (value.format(usage=pct, name=name, real=round(float(real) / 1024.0, 1), bound=round(float(bound) / 1024.0, 1)), rtn_val)

def readLogFile(filepath):
    ram = None
    rom = None
    logger.info("Reading and evaluating log file at '{path}'.".format(path=filepath))
    with open(os.path.abspath(filepath), "r+") as f:
        for line in f:
            input_ram = re.search(REGEX_RAM_SUM_IN_LOG, line)
            if input_ram:
                ram = input_ram.group(1)
            else: input_rom = re.search(REGEX_ROM_SUM_IN_LOG, line)
            if input_rom:
                rom = input_rom.group(1)
                # jump out of loop after rom was read because rom is after ram in log file
                break
                
     # returns a tuple of ram and rom value and None if there is no match in the file, i.d. nothin was found
    logger.info("Returning results from log file.")
    return (ram, rom) 

def getProjectName(full_name):
    name_fragments = full_name.split("_")
    return name_fragments[1]
    
def readExcel(filename, component_name, project_name):
    # needed because automatic continious reading of cells is not possible with empty cells in between; represents boundaries for reading cells
    maxRows = 300
    maxCols = 100
    
    # initializing return values
    ram_cell = None
    rom_cell = None
    
    # conversion of kByte to Byte because res-file contains budget values in kBytes
    conv_factor = pow(CONVERSION_BASE_FACTOR, CONVERSION_EXP_MAP["kB"])
    
    wb = None
    try:
        if not (os.path.exists(filename)): raise InputError(InputError.FILE_NOT_FOUND, filename)
        # open excel file with excel not visible
        logger.info("Loading '{file}'.".format(file=filename))
        wb = xlwings.Workbook(filename, app_visible=False)
        wb.set_current()
        # change sheet (or tab) by a project's name
        logger.info("Looking for project '{project}'.".format(project=project_name))
        sheet = xlwings.Sheet(project_name)
        if not sheet: raise InputError(InputError.SHEET_NOT_FOUND, project_name)
    except InputError as e:
        print(e)
        logger.error(e)
    except TypeError as e:
        print(e)
        logger.error(e)
    except com_error as e:
        print(repr(e))
        logger.error(repr(e))
        print("Is Excel installed? If yes maybe the sheet/tab '{project}' was not found in Excel.".format(project=project_name))
    except Exception as e:
        print("Unexpected Exception:")
        print(repr(e))
        logger.error(repr(e))
    else:
        header_row = None
        component_column = None
        ram_column = None
        rom_column = None
        # looking for relevant table headers plus their column indices for following searches
        logger.info("Looking for relevant table headers in order to determine column indices.")
        rows = xlwings.Range(sheet, (1, 1), (maxRows, maxCols)).value
        for i, row in enumerate(rows, 1):
            for j, cell in enumerate(row, 1):
                if cell and isinstance(cell, basestring):
                    if(cell == "Component"):
                        header_row = i
                        component_column = j
                    elif(cell.find("external RAM usage ('algo state') [kByte]") != -1 ):
                        ram_column = j
                    elif(cell.find("Code & Constants (ROM) [kByte]") != -1 ):
                        rom_column = j
            if component_column and ram_column and rom_column:
                logger.info("Found column indices.")
                break
        
        component_row = None
        # looking for column indices using the component name in order to access the corresponding cells for ram/rom values
        logger.info("Looking for component name '{component}' in order to determine row index.".format(component=component_name))
        component_cells = xlwings.Range(sheet, (header_row, component_column), (maxRows, component_column)).value
        for i, cell in enumerate (component_cells, header_row):
            if cell and isinstance(cell, basestring):
                if(cell.lower() == component_name.lower()):
                    component_row = i
                    logger.info("Found row index.")
                    break
        # access corresponding cells if found by row and column indices
        if component_row:
            logger.info("Looking for RAM/ROM values.")
            if ram_column:
                ram_cell = xlwings.Range(sheet, (component_row, ram_column)).value
            if rom_column:
                rom_cell = xlwings.Range(sheet, (component_row, rom_column)).value
    finally:
        if wb:
            wb.close()
                
    logger.info("Returning results from RAM/ROM search.")
    return (ram_cell*conv_factor if ram_cell else None, rom_cell*conv_factor if rom_cell else None)
    
class InputError(Exception):
    
    FILE_NOT_FOUND = 0
    SHEET_NOT_FOUND = 1
    MISSING_RAM_USAGE = 2
    MISSING_ROM_USAGE = 3
    MISSING_RAM_BUDGET = 4
    MISSING_ROM_BUDGET = 5
    
    error_msgs = {
                  FILE_NOT_FOUND : "File '{value}' could not be found or opened.",
                  SHEET_NOT_FOUND : "Sheet/Project 'value' could not be found.",
                  MISSING_RAM_USAGE : "No RAM usage value was provided.",
                  MISSING_ROM_USAGE : "No ROM usage value was provided.",
                  MISSING_RAM_BUDGET : "No RAM budget value was provided.",
                  MISSING_ROM_BUDGET : "No ROM budget value was provided."
                  }
    
    def __init__(self, code, value=None):
        self.value = value
        self.code = code
        
    def __str__(self):
        return  "InputError:" + repr(self.error_msgs[self.code].format(value=self.value) if self.value else self.error_msgs[self.code])
    
if __name__ == "__main__":
    sys.exit(main())