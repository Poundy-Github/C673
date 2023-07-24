from __future__ import print_function
import sys, os
# Added path to our python packages 
sys.path.insert(0, os.path.abspath(os.path.join(os.path.split(__file__)[0], r"../../pythonPackages")))

import csv, datetime, os.path, argparse, sys, xlsxwriter, logging
from xmlModels import XmlDoc
from jinja2 import Environment, BaseLoader, TemplateNotFound
from xml.etree.ElementTree import parse

#output states, at one colors for html/css
CONST_COMPARE_SUCCESS = "green"
CONST_COMPARE_FAIL = "red"
CONST_COMPARE_ACCEPTABLE = "yellow"
#output states for readable output
CONST_NO_DEVIATION = "nd"
CONST_ACCEPTABLE_DEVIATION = "ad"
CONST_UNACCEPTABLE_DEVIATION = "ud"
#output styles indicating how the output should be shown or saved
CONST_OUTPUT_STYLE_CMD = "cmd"
CONST_OUTPUT_STYLE_TXT = ".txt"
CONST_OUTPUT_STYLE_CSV = ".csv"
CONST_OUTPUT_STYLE_XLSX = ".xlsx"
CONST_OUTPUT_STYLE_HTML = ".html"
CONST_OUTPUT_STYLE_BPL = ".bpl"
#output filenames
CONST_LOG_FILENAME = "compareMeasfreezes.log"

#get path from directory where this script is lying
default_path = os.path.dirname(os.path.abspath(__file__))

def main():
    exit_code = 0
    #initialize argument parser for getting command line arguments 
    parser = initArgParser()
    args = parser.parse_args()
    
    #get path from calling directory
    entry_point = os.path.dirname(os.path.abspath(parser.prog))
    
    #path to where outputs are intended to be saved
    if not (CONST_OUTPUT_STYLE_CMD in args.output_style and len(args.output_style) == 1):    
        if args.output_path == None:
            args.output_path = os.path.abspath(os.path.join(default_path, "outputs"))
            if not os.path.exists(args.output_path):
                os.mkdir(args.output_path)
        else:
            args.output_path = os.path.abspath(args.output_path)
            if not os.path.exists(args.output_path):
                os.mkdir(args.output_path)
        os.chdir(args.output_path)  
        
    #inititailize main logger
    logger = initLogger(args, args.output_path)
    logger.info(args)  
    
    logger.info("Script at {path} getting called from {entry}.".format(path=default_path, entry=entry_point))
    
    #get file line offset values from args
    offset_ref = args.offsets[0]
    offset_new = args.offsets[1]
    
    # read files from playlist if playlist is intended to be used
    refs_from_playlist = []
    if args.use_playlist != -1: #-1 stands for unused, None stands for used with default path and file as below
        if args.use_playlist == None:
            playlist_path = os.path.join(default_path, "..\\outputs\\SILTestRecordings.bpl")
        else:
            playlist_path = os.path.abspath(args.use_playlist)
            
        try:
            logger.info("Try to use playlist at {path}.".format(path=playlist_path))
            with open(playlist_path, "r") as xmlfile:
                root = parse(xmlfile).getroot()
                for entry in root.findall("BatchEntry"):
                    filepath, filename = os.path.split(entry.get("fileName"))
                    basename, extension = filename.split(".")
                    refs_from_playlist.append((filepath, basename, "." + extension)) 
            #update recordings path 
            args.rec_path = refs_from_playlist[0][0] 
        except: 
            logger.error("Specified playlist was not found or could not be opened.")
            return 1
    
    #check if path variables are set; if not: set to default value and create directories if not existing
    #path where reference input files can be found
    elif args.input_path_ref == None:
        input_path_ref = os.path.abspath(os.path.join(default_path, "input_ref"))
        if not os.path.exists(input_path_ref):
            os.mkdir(input_path_ref)
    else:
        input_path_ref = os.path.abspath(args.input_path_ref)
        
    #path where new input files can be found
    if args.input_path_new == None:
        args.input_path_new = args.output_path
    else:
        args.input_path_new = os.path.abspath(args.input_path_new)
        
    result_sets = []
    #create new input files list (one element if input is a file and refactoring input path)
    input_path_new, input_files_new = readInput(args.input_path_new, logger)

    # Remove Export.csv as this file is useless for comparison
    if 'Export.csv' in input_files_new:
        input_files_new.remove('Export.csv')
    
    # return an error if one csv file is missing
    if len(refs_from_playlist) != len(input_files_new):
        logger.error("There are {len_ref_list} recordings in playlist but {len_input_list} corresponding csv files found".format(len_ref_list=len(refs_from_playlist), len_input_list=len(input_files_new)))
        return 2
        
    if args.use_playlist != -1:
        #iterate over files from playlist 
        for ref in refs_from_playlist:
            refFileName = ref[1]+".csv"
            refFilePath = ref[0]
            print(refFileName)
            for newFileName in input_files_new:
                if newFileName == refFileName:
                    logger.info("comparing file_ref = {ref_name} with file_new = {new_name}".format(ref_name=refFileName, new_name=newFileName))
                    file_ref = CSVFile(refFilePath, refFileName, offset_ref)
                    file_new = CSVFile(input_path_new, newFileName, offset_new)
                    compare_set = CompareSet(file_ref, file_new, args)
                    result_sets.append(compare_set.compareFiles())
                    break;
        # print empty line
        print("")

    elif input_path_ref != None:
        #create reference input files list (one element if input is a file and refactoring input path)
        input_path_ref, input_files_ref = readInput(input_path_ref, logger)
        
        if not (input_files_ref and input_files_new):
            logger.warning("One or both of the given directories ({ref}, {new}) are empty or a wrong file extension was used!".format(ref=input_path_ref, new=input_path_new))
        else:
            logger.info("Comparing; {cnt_ref} files in 'ref' and {cnt_new} files in new".format(cnt_ref=len(input_files_ref), cnt_new=len(input_files_new)))
            logger.info("References: {refs} \n NewFiles: {news}".format(refs=input_files_ref, news=input_files_new))
            
        #iterate directories and compare files
        for refFileName in input_files_ref:
            # Search for corresponding new csv file
            for newFileName in input_files_new:
                if newFileName == refFileName:
                    break;
            logger.info("comparing file_ref = {ref_name} with file_new = {new_name}".format(ref_name=refFileName, new_name=newFileName))
            file_ref = CSVFile(input_path_ref, refFileName, offset_ref)
            file_new = CSVFile(input_path_new, newFileName, offset_new)
            compare_set = CompareSet(file_ref, file_new, args)
            result_sets.append(compare_set.compareFiles())
    else:
        logger.error("No input was provided.")
        return 1

    #create outputs for results
    for result_set in result_sets:
        if result_set.diff_flag == CONST_UNACCEPTABLE_DEVIATION:
            exit_code = 3
        result_set.output() 
    
    #create index file for outputted html-files
    if CONST_OUTPUT_STYLE_HTML in args.output_style:
        writeIndexHtml(result_sets)     
    
    #change cwd to path where script was started
    os.chdir(entry_point)    
    return exit_code
    
def initArgParser():
    parser = argparse.ArgumentParser(description="Python script for comparing measfreeze outputs (csv file) from current HLA version against pre-defined reference measfreeze.", usage="%(prog)s [options]", epilog="For more help see also: wiki")
    #define path for reference source csv
    parser.add_argument("-ref", dest="input_path_ref", default=None, nargs="?", help = "Directory where reference measfreezes (csv files) are located or direct file path")
    #define path for new source csv
    parser.add_argument("-new", dest="input_path_new", default=None, nargs="?", help="Directory where new measfreezes (csv files) are located or direct file path")
    #define path for ouput
    parser.add_argument("-outpath", dest="output_path", default=None, nargs="?", help="Directory where output should be saved")
    #define if output should be printed to commandline
    parser.add_argument("-out", dest="output_style", action="store", nargs="+", default=[CONST_OUTPUT_STYLE_TXT], help="Type of output. Multiple types possible seperated by spaces. [Default: '" + CONST_OUTPUT_STYLE_TXT + "']", 
                        choices=[CONST_OUTPUT_STYLE_CMD, CONST_OUTPUT_STYLE_HTML, CONST_OUTPUT_STYLE_TXT, CONST_OUTPUT_STYLE_BPL, CONST_OUTPUT_STYLE_CSV, CONST_OUTPUT_STYLE_XLSX])
    #offsets of lines in the result_list 
    parser.add_argument("-offsets", dest="offsets", action="store", nargs=2, default=[55,55], type=int, help="First cycles are ignored. Two offsets seperated by spaces define number of cycles. [Default: 50 50]")
    #delay for transistions between reference and new values; default hard border 
    parser.add_argument("-delay", dest="delay", action="store", nargs="+", default=[0], type=int, help="Defines number of cyclces where measfreezes can differ without throwing an error. [Default: 0]")
    #decide if header should be printed or not
    parser.add_argument("-header", dest="header", action="store_true", default=False, help="Writes output header if used. [Default: False]")
    #decide, which columns should be compared
    parser.add_argument("-columns", dest="columns", action="store", nargs="+", default=None, type=int, help="Measfreezes (columns in csv file) that should be written in output. Seperate them by spaces")
    #TODO: Parameter erweitern (bestehende) und neue hinzufuegen: z.B. Toleranz/Spiel einbauen, zusaetzlich zu delay; Delay anpassen auf mehrere Delay-Werte
    parser.add_argument("-redundant", dest="show_redundant", action="store_true", default=False, help="writes all information even without deviation")
    #define path for referenced rec_path (where relevant recordings can be found)
    parser.add_argument("-rec", dest="rec_path", action="store", help="Directory where analyzed recordings can be found.", nargs="?", default=None)
    #turn on logging to a log-file
    parser.add_argument("-log", dest="log", action="store_true", default=False, help="Turn on logging. [Default: False]")
    #using a playlist instead of explicit reference
    parser.add_argument("-playlist", dest="use_playlist", action="store", nargs="?", default=-1, help="Using a playlist instead of explicit '-ref'. Usage: -playlits <path>, where path is opotional. [Default: None]")
    return parser   

def initLogger(args, path=""):
    #create logger with program name
    logger = logging.getLogger(__name__)
    #mute output to command line
    logger.propagate=False
    logger.setLevel(logging.INFO)
    if(args.log):
        file_handler = logging.FileHandler(os.path.join(path, CONST_LOG_FILENAME), mode="w")
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        file_handler.setLevel(logging.INFO)
        file_handler.setFormatter(formatter)
        logger.addHandler(file_handler)
        logger.info("(Logger initiated {logger})".format(logger=__name__))
    else:
        idle = logging.NullHandler()
        logger.addHandler(idle)
    return logger

def getTimeStamp():
    #create time stamp formatted als follows and return as string
    return str(datetime.datetime.now()).replace(" ", "_").replace(":", "-")

def readInput(path, logger):
    input_list = []
    if os.path.isfile(path) and path.endswith(".csv"):
            split_path = os.path.split(path)
            path = split_path[0]
            input_list.append(split_path[1])
    elif os.path.isdir(path):
        input_list = [name for name in os.listdir(path) if name.endswith(".csv")]
    else:
        msg = "Invalid input for reference file. '{input}' is neither file nor directory!".format(input=path)
        if logger:
            logger.error(msg)
        print(msg)
    return (path, input_list)
    
def writeIndexHtml(result_sets):
    with open("index.html", "w") as indexfile:
        env = Environment(loader=TemplateLoader("templates"))
        env.trim_blocks = True
        env.lstrip_blocks = True
        template = env.get_template('index_template.html')
        indexfile.write(template.render(out_dir=os.getcwd(),
                                        result_sets=result_sets))

#class for storing result values
class ResultValue:
    def __init__(self, diff_state, result_value):
        self.diff_state = diff_state
        self.result_value = result_value
        
    def __str__(self):
        return self.result_value
    
    def getDiffState(self):
        return self.diff_state
    
#class for storing starting and ending fram times in order to create xml
class FrameTimes:
    def __init__(self, start_time, end_time):
        self.start_time = start_time
        self.end_time = end_time

#class for comparing two files    
class CompareSet:
    def __init__(self, file_ref, file_new, args):
        self.file_ref = file_ref
        self.file_new = file_new
        self.result_list = []
        self.args = args
        self.result_set = ResultSet(args, self.getOutFileName())
        self.result_set.setFiles(file_ref.filepath, file_ref.filename, file_new.filepath, file_new.filename)
        self.logger = logging.getLogger(".".join((__name__, self.__class__.__name__)))
        
    def mrange(self, start, stop):
        return range(start, stop) if start < stop else range((start-1), stop)
        
    def getOutFileName(self):
        return "{ref_name}_VS_{new_name}".format(ref_name=self.file_ref.filename.split(".")[0], new_name=self.file_new.filename.split(".")[0])
    
    def compareFiles(self):
        #determine minimal number of rows and columns of both files
        numRows = min(len(self.file_ref.value_list), len(self.file_new.value_list))
        numColumns = min(len(self.file_ref.value_list[0]), len(self.file_new.value_list[0]))
        self.logger.info("Minimal number of rows of both files: {rows}".format(rows=numRows))
        self.logger.info("Minimal number of columns of both files: {columns}".format(columns=numColumns))
        #init some vars for later use
        result_list = []
        frame_times = []
        start_time = None
        end_time = None
        diff_state = CONST_NO_DEVIATION
        
        #check for columns arg and create column list if it is not given
        if self.args.columns == None:
            columns = [col for col in range(1, numColumns)]
        else:
            columns = self.args.columns 
            # Remove not available columns from argument list
            for index, column in reversed(list(enumerate(self.args.columns))):
                if column >= numColumns:
                    del self.args.columns[index]
        
        if(self.args.header):
            header = []
            if self.args.columns == None:
                for i in range(1, len(self.file_ref.value_list[0])):
                    header.append(self.file_ref.value_list[0][i])
            else:
                if len(self.args.columns) > 1:    
                    header.append(self.file_ref.value_list[0][self.args.columns[0]])
                    for i in self.args.columns[1:len(self.args.columns)]:
                        header.append(self.file_ref.value_list[0][i])
                else: 
                    header.append(self.file_ref.value_list[0][self.args.columns[0]])
            result_list.append(header)

        #compare result_list with given delay and other args; 'off' is for fixating starting frame or ending frame which means
        #if there is no deviation, off will be same as 'i' in the loop. So the starting frame is adjusted. But once there is deviation, 'off' will differ for the duration of deviation and thus
        #fixate the ending frame
        off = 1
        for i in range(1, numRows):
            if i == off:
                if end_time != None:
                    frame_times.append(FrameTimes(start_time, end_time))
                    end_time = None
                start_time = self.file_ref.value_list[i][0]
            
            result = []
            row_redundant = True
            col = 0;
            j = 0
            for j in range(len(columns)):
                #init some buffers
                col = columns[j]
                delay_buffer = False;
                try:
                    delay = self.args.delay[j]
                except:
                    delay = 0
                delay_range = min(i + 1 + delay, numRows)
                
                #compare list result_list with respect to chosen delay
                if self.file_ref.value_list[i][col] == self.file_new.value_list[i][col]:
                    result.append(ResultValue(CONST_COMPARE_SUCCESS, "{devi} - Reference: {ref}, Measurement: {new}".format(devi=CONST_NO_DEVIATION, ref=self.file_ref.value_list[i][col], new=self.file_new.value_list[i][col])))
                    off = i+1
                else:
                    diff_state = CONST_ACCEPTABLE_DEVIATION
                    row_redundant = False
                    for k in self.mrange(i+1, delay_range):
                        delay_buffer = delay_buffer | (self.file_ref.value_list[k][col] == self.file_new.value_list[i][col])
                        if delay_buffer:
                            result.append(ResultValue(CONST_COMPARE_ACCEPTABLE, "{devi} - Reference: {ref}, Measurement: {new}".format(devi=CONST_ACCEPTABLE_DEVIATION, ref=self.file_ref.value_list[i][col], new=self.file_new.value_list[i][col])))
                            end_time = self.file_ref.value_list[k][0]
                            off = k
                            break
                        elif k >= (delay_range-1):
                            result.append(ResultValue(CONST_COMPARE_FAIL, "{devi} - Reference: {ref}, Measurement: {new}".format(devi=CONST_UNACCEPTABLE_DEVIATION, ref=self.file_ref.value_list[i][col], new=self.file_new.value_list[i][col])))
                            end_time = self.file_ref.value_list[k][0]
                            off = k
                            diff_state = CONST_UNACCEPTABLE_DEVIATION
            result_list.append((result, row_redundant))
        
        #set diff state indicating if there was a deviation while comparing        
        self.result_set.updateSet(result_list, diff_state)
        #set frame list containing starting frame and ending frame of deviations
        self.result_set.setFrameList(frame_times)
        return self.result_set
   
#class for storing and printing results returned from compare sets                          
class ResultSet:
    def __init__(self, args, out_filename):
        self.args = args
        self.prettyprintArgs()
        self.result_list = []
        self.out_filename = out_filename
        self.diff_flag = CONST_NO_DEVIATION
        self.dir_file_ref = "."
        self.dir_file_new = "."
        self.filename_ref = "no filename"
        self.filename_new = "no filename"
        self.logger = logging.getLogger(".".join((__name__, self.__class__.__name__)))
        
    def prettyprintArgs(self):
        #create a list from args because args is not iterable and concatenate keys and values for output
        args_dict = vars(self.args)
        self.args_list = []
        for arg_name, arg_value in args_dict.items():
            args_str = "{name} = {value}".format(name=arg_name, value=arg_value)
            self.args_list.append(args_str)
        
    def setFiles(self, dir_file_ref, filename_ref, dir_file_new, filename_new):
        self.dir_file_ref = dir_file_ref
        self.dir_file_new = dir_file_new
        self.filename_ref = filename_ref
        self.filename_new = filename_new
        
    def setFrameList(self, frame_list):
        self.frame_list = frame_list
        
    def updateSet(self, result_list, diff_flag):
        self.result_list = result_list
        self.diff_flag = diff_flag
        
    def output(self):
        #check which output styles have to be processed
        for style in self.args.output_style:
            self.logger.info("Outputting: {style}".format(style=style))
            if style == CONST_OUTPUT_STYLE_TXT:
                self.writeText()
                self.logger.info("Results saved as {filename}{type} at {path}, diff_flag = {diff}".format(filename=self.out_filename, type=style, path=os.getcwd(), diff=self.diff_flag))
            elif style == CONST_OUTPUT_STYLE_CMD:
                self.printText()
                self.logger.info("Results printed in commandline, diff_flag = {diff}".format(diff=self.diff_flag))
            elif style == CONST_OUTPUT_STYLE_CSV:
                self.writeCsv()
            elif style == CONST_OUTPUT_STYLE_XLSX:
                self.writeXLSX()
            elif style == CONST_OUTPUT_STYLE_HTML:    
                self.writeHtml()
                logging.info("Results saved as {filename}{type} at {path}, diff_flag = {diff}".format(filename=self.out_filename, type=style, path=os.getcwd(), diff=self.diff_flag))
            elif style == CONST_OUTPUT_STYLE_BPL:
                self.writeBPL()
                self.logger.info("Results saved as {filename}{type} at {path}, diff_flag = {diff}".format(filename=self.out_filename, type=style, path=os.getcwd(), diff=self.diff_flag))
            else:
                print("UNKOWN OR WRONG OUTPUT STYLE!")
    
    def writeHtml(self):
        with open("".join((self.out_filename, ".html")), 'w') as htmlfile:
            env = Environment(loader=TemplateLoader("templates"))
            env.trim_blocks = True
            env.lstrip_blocks = True
            template = env.get_template('compare_template.html')
            #renaming following variables means also renaming corresponding variables in the html-templates
            htmlfile.write(template.render( args_list=self.args_list, 
                                            show_redundant=self.args.show_redundant,
                                            dir_file_ref="file:\\\\"+ os.path.join(self.dir_file_ref, self.filename_ref),
                                            filename_ref=self.filename_ref, 
                                            dir_file_new="file:\\\\"+ os.path.join(self.dir_file_new, self.filename_new),
                                            filename_new=self.filename_new, 
                                            header=self.args.header, 
                                            headers=self.result_list[0], 
                                            result_list=self.result_list[1:], 
                                            offset0=self.args.offsets[0], 
                                            offset1=self.args.offsets[1])
                                           )
    
    def writeBPL(self, rel=""):
        #write results to .bpl-file
        doc = XmlDoc("SILTest_Findings.bpl", rel, self.args.log, __name__, CONST_LOG_FILENAME)
        if(os.path.exists(os.path.join(self.args.rec_path, self.filename_ref.split(".")[0]+".rec"))):
                    doc.addBatchEntry(os.path.join(self.args.rec_path, self.filename_ref.split(".")[0]+".rec"))
        elif(os.path.exists(os.path.join(self.args.rec_path, self.filename_ref.split(".")[0]+".rrec"))):
                    doc.addBatchEntry(os.path.join(self.args.rec_path, self.filename_ref.split(".")[0]+".rrec"))
        doc.addSectionList()
        for frame in self.frame_list:
            if(frame.start_time != None and frame.end_time != None):
                doc.addSection(frame.end_time, frame.start_time)
        doc.writeXML()
        
    def writeText(self):
        #write result to a file with timestamp
        self.logger.info("Writing to text file.")
        try:
            with open(self.out_filename + CONST_OUTPUT_STYLE_TXT, 'w') as textfile:
                textfile.write(self.args.__str__() + "\n")
                textfile.write("#f1, #f2, ")
                if(self.args.header):
                    for value,is_last in self.notLast(self.result_list[0]):
                        textfile.write(value + ("\n" if is_last else ","))  
                i = 1; 
                for result in self.result_list[1:]:
                    if(not result[1] or self.args.show_redundant):
                        textfile.write("{lineff}:{linefs}:".format(lineff=(i+self.args.offsets[0]), linefs=(i+self.args.offsets[1])))    
                        for value,is_last in self.notLast(result[0]):
                            textfile.write("{result};{diff}{end}".format(result=value.result_value, diff=value.diff_state, end="\n" if is_last else ",")) 
                    i += 1
        except Exception:
            self.logger.exception("Writing to text file failed.")
        
    def printText(self):
        #just print result in command line
        print("\nResults of {file}:\n".format(file=self.filename_new))
        print("Deviating measfreeze: ", end="")
        if(self.args.header):
            for value,is_last in self.notLast(self.result_list[0]):
                print(value, end="\n" if is_last else ",")
        i = 1;  
        for result in self.result_list[1:]:
            if(not result[1] or self.args.show_redundant):
                print(str(i + self.args.offsets[0]), end=":")
                print(str(i + self.args.offsets[1]), end=":")
                for value,is_last in self.notLast(result[0]):
                    print("{result}:{diff}".format(result=value.result_value, diff=value.diff_state), end="\n" if is_last else ",")   
            i += 1  
            
    def writeCsv(self):
        #write result to csv-file
        with open("".join((self.out_filename, ".csv")), "wb") as csvfile:
            writer = csv.writer(csvfile, delimiter=";")
            if(self.args.header):
                headers = ["#f1", "#f2"]
                headers.extend(self.result_list[0])
                writer.writerow(headers)
            #TODO add columns
            out = []
            for i,(result, row_redundant) in enumerate(self.result_list[1:]):
                indices = [i + self.args.offsets[0], i + self.args.offsets[1]]
                if (not row_redundant or self.args.show_redundant):
                    indices.extend(result)
                    out.append(indices)
            
            writer.writerows(out)
            
    def writeXLSX(self):
        workbook = xlsxwriter.Workbook(self.out_filename + ".xlsx")
        worksheet = workbook.add_worksheet()
        
        #cell colors
        bg_red = workbook.add_format()
        bg_red.set_bg_color(CONST_COMPARE_FAIL)
        
        bg_yellow = workbook.add_format()
        bg_yellow.set_bg_color(CONST_COMPARE_ACCEPTABLE)
        
        bg_green = workbook.add_format()
        bg_green.set_bg_color(CONST_COMPARE_SUCCESS)
        
        color_dict = {CONST_COMPARE_SUCCESS: bg_green,
                      CONST_COMPARE_ACCEPTABLE: bg_yellow,
                      CONST_COMPARE_FAIL : bg_red}
        
        if(self.args.header):
            headers = ["#f1", "#f2"]
            headers.extend(self.result_list[0])
            for col, header in enumerate(headers):
                worksheet.write(0, col, header)
        
        row_index = 1
        for row,(result, row_redundant) in enumerate(self.result_list[1:]):
            if (not row_redundant or self.args.show_redundant):
                worksheet.write(row_index, 0, (row)+self.args.offsets[0])
                worksheet.write(row_index, 1, (row)+self.args.offsets[1])
                for col,value in enumerate(result, start=2):
                    worksheet.write(row_index, col, value.__str__(), color_dict[value.getDiffState()])
                    
                row_index += 1
        workbook.close()
                
    def notLast(self, itr):
        #helper method to distinguish the last entry from the rest in order to process line endings differently
        itr = iter(itr)
        prev = next(itr)
        for item in itr:
            yield prev, False
            prev = item
        yield prev, True    
           
#class for reading csv files and holding some extra information of the file
class CSVFile:
    def __init__(self, filepath, filename, offset):
        self.logger = logging.getLogger(".".join((__name__, self.__class__.__name__)))
        self.filename = filename
        self.value_list = []
        self.filepath = filepath
        self.readCSVFile(filepath, filename, offset)
        
    def readCSVFile(self, filepath, filename, offset):
        try:
            self.logger.info("Reading {filename} from {filepath} with {offset} Offset.".format(filename=filename, filepath=filepath, offset=offset))
            with open(os.path.join(filepath, filename)) as csvfile:
                reader = csv.reader(csvfile)
                #read with initial "delay", i.d. ignore e.g. first 56 result_list
                #but take first row with col headers
                i = 0 
                for row in reader:
                    if(i > offset) or (i == 0):
                        self.value_list.append(row)
                    i += 1 
        except Exception:
            self.logger.exception("Reading .csv-file failed.")

class TemplateLoader(BaseLoader):
    def __init__(self, path):
        self.path = os.path.join(default_path, path)
    def get_source(self, environment, template):
        path = os.path.join(self.path, template)
        if not os.path.exists(path):
            raise TemplateNotFound(template)
        mtime = os.path.getmtime(path)
        with file(path) as f:
            source = f.read().decode('utf-8')
        return source, path, lambda: mtime == os.path.getmtime(path)
    
if __name__ == "__main__":
    sys.exit(main())