from xml.etree.ElementTree import Element, SubElement, tostring, ElementTree as ET, parse
from xml.dom import minidom
import os.path, logging

class XmlDoc:
    
    def __init__(self, filename, filepath = "", log=False, main_logger_name="", main_log_file="", log_path=""):
        self.initLogger(main_logger_name, main_log_file, log_path, log)
        self.out_path = os.path.join(filepath, filename)
        if os.path.exists(self.out_path):
            self.from_file = True
            with open(self.out_path, "r") as xmlfile:
                self.tree = parse(xmlfile)
            self.root = self.tree.getroot()
        else:
            self.from_file = False
            self.root = Element("BatchList")
            self.tree = ET(self.root)
      
    def initLogger(self, logger_name="", log_file="", path="", log=False):
        #initialize logger for this module with main logger from another module if given
        #if logging is 'False' a handler is added to the logger which ignores logging messages instead of writing it to a log file
        log_file = log_file if log_file != "" else ".".join((__name__, self.__class__.__name__, ".log"))
        if logger_name == "":
            self.logger_name = ".".join((__name__, self.__class__.__name__))
            self.logger = logging.getLogger(self.logger_name)
            self.logger.setLevel(logging.INFO)
            self.logger.propagate=False
            if log:
                handler = logging.FileHandler(os.path.join(path, log_file), mode="a")
                handler.setLevel(logging.INFO)
                formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
                handler.setFormatter(formatter)
                self.logger.addHandler(handler)
            else:
                idle = logging.NullHandler()
                self.logger.addHandler(idle)                            
        else:
            self.logger_name = ".".join((logger_name, __name__, self.__class__.__name__))
            self.logger = logging.getLogger(self.logger_name)
            
        self.logger.info("Initialized logger {logger_name} with associated log file {log_file}".format(logger_name=logger_name, log_file=log_file))    
        
    def writeXML(self):
        #writing xml-tree to .bpl-file
        self.logger.info("Building document '{out}'".format(out=self.out_path))
        try:
            with open(self.out_path, "w") as xmlfile:
                xmlfile.write(self.__str__())
        except Exception:
            self.logger.exception("Writing to .bpl-file failed.")
        
    def __str__(self):
        #walk elements and strip blank spaces from them - kind of bugfix for 'toprettyxml()'
        self.strip(self.tree.getroot())
        #get string representation of xml tree and reparse for human readable output
        rough_string = tostring(self.tree.getroot(), encoding='utf8', method='xml')
        reparsed = minidom.parseString(rough_string)
        return reparsed.toprettyxml()
    
    def strip(self, elem):
        #removes leading and trailing spaces from elements and their texts
        for elem in elem.iter():
            if(elem.text):
                elem.text = elem.text.strip()
            if(elem.tail):
                elem.tail = elem.tail.strip()
        
    def addBatchEntry(self, file_name):
        #just add entry if it is not already there
        if self.from_file:
            already_there = False
            for batch_entry in self.root.findall("BatchEntry"):
                if file_name == batch_entry.attrib["fileName"]:
                    self.batch_entry = batch_entry
                    already_there = True 
            if not already_there:
                self.batch_entry = SubElement(self.root, "BatchEntry", {"fileName":file_name})
        else:
            self.batch_entry = SubElement(self.root, "BatchEntry", {"fileName":file_name})
        
    def addSectionList(self):
        #just add entry if it is not already there
        if self.from_file:
            self.section_list = self.batch_entry.find("SectionList")
            if self.section_list is None:
                self.section_list = SubElement(self.batch_entry, "SectionList")
        else:
            self.section_list = SubElement(self.batch_entry, "SectionList")
        
    def addSection(self, end_time, start_time):
        #just add entry if it is not already there
        end_time = str(end_time)
        start_time = str(start_time)
        if self.from_file:
            already_there = False
            for xsection in self.section_list.findall("Section"):
                if end_time == xsection.attrib["endTime"] and start_time == xsection.attrib["startTime"]:
                    already_there = True
                    break
            if not already_there:
                self.section = SubElement(self.section_list, "Section", {"endTime": end_time, "startTime": start_time})
        else:
            self.section = SubElement(self.section_list, "Section", {"endTime": str(end_time), "startTime": str(start_time)})
            