"""
@author: uidq3472
"""

import os
import logging
from abc import ABCMeta, abstractmethod
# noinspection PyUnresolvedReferences
from excelaccess.dumping.excel_description_extractor import DescriptionExtractor
# noinspection PyUnresolvedReferences
from excelaccess.xmldescriptor.xml_creator import XMLParser
# noinspection PyUnresolvedReferences
from excelaccess.xmldescriptor.xml_defs import root_configuration_dump_path


def get_previous_jobs_list(path):
    """Returns a list of the directory under 'path'. Represents the previously worked jobs. 
    
    :param str path: a (relative) path 
    :return: directories
    :rtype: list(str)
    """
    if not os.path.exists(path):
        os.makedirs(path)
    previous_jobs_list = os.listdir(path)

    return previous_jobs_list


class ExcelLibraryWrapper:
    """Abstract base class for all wrappers.
    
    :param str configuration_xml_path: a (relative) path to a Config XML file
    """
    __metaclass__ = ABCMeta

    def __init__(self, configuration_xml_path):
        self.sheets_index_dict = {}  # contains excel sheet objects
        self.sheets_list = []
        self.sheet_index = 0

        logger = self.init_logger(__name__)

        # read in XML file
        try:
            self.xml_parser = XMLParser(configuration_xml_path)
            self.excel_file_path = self.xml_parser.get_excel_path()
            self.xml_root_configuration = self.xml_parser.get_excel_configuration()
            logger.info("ExcelFilePath: {0}".format(self.excel_file_path))
        except IOError:
            logger.exception("Could not read XML file.")
        else:
            logger.info("Successfully read XML file.")

        # read in dump file 
        try:
            # TODO: backpropagate to input level
            dump_path = self.xml_root_configuration.attrib.get(
                root_configuration_dump_path) if self.xml_root_configuration is not None else None
            self.description_extractor = DescriptionExtractor(self.excel_file_path, dump_path)
            self.description_extractor.read_workbook()
        except Exception:
            # TODO: improve Exception
            logger.exception("Could not extract information.")
        else:
            logger.info("Successfully extracted information.")

    @abstractmethod
    def read_workbook(self):
        """Method for reading an Excel file. 
        
        :raises NotImplementedError: if inherited class does not implement this method 
        """
        raise NotImplementedError

    @abstractmethod
    def get_library_sheets(self):
        """Return list of sheet objects of the used library.
        
        :raises NotImplementedError: if inherited class does not implement this method
        """
        raise NotImplementedError

    @abstractmethod
    def get_library_sheet(self, sheet_identifier):
        """Return a sheet object of the used library.
        
        :raises NotImplementedError: if inherited class does not implement this method
        """
        raise NotImplementedError

    def get_sheets(self):
        """Return list of sheet objects.
        
        :return: list of sheets
        :rtype: list(SheetObject)
        """
        return self.sheets_list

    def get_sheet_by_name(self, name):
        """Return sheet object by its identifier.
        
        :param str name: name of the sheet
        :return: sheet by name
        :rtype: SheetObject
        """
        return self.sheets_list[self.sheets_index_dict[name]]

    def get_sheet_by_index(self, index):
        """Return sheet object by its index.
        
        :param int index: index of sheet in list
        :return: sheet by index
        :rtype: SheetObject
        """
        return self.sheets_list[index]

    @abstractmethod
    def save(self):
        """
        :raises NotImplementedError: if inherited class does not implement this method
        """
        raise NotImplementedError

    @abstractmethod
    def close(self):
        """
        :raises NotImplementedError: if inherited class does not implement this method
        """
        raise NotImplementedError

    def get_column_index_from_headers(self, potential_headers, headers):
        """Method to get column index based on list of possible captions (headers)"""
        for header in potential_headers:
            lowercase_header = header.lower()
            if lowercase_header in headers:
                return headers[lowercase_header]
        return None

    def get_merged_cells(self, sheet_name):
        """Returns merged cells for a specific sheet.
        
        :param str sheet_name: Excel sheet name
        :return: merged cells for a given sheet
        :rtype: dumping._descriptor_wrapper.MergedCell
        """
        return self.description_extractor.get_merged_cells(sheet_name)

    def get_tables_from_xml(self, sheet_name):
        """Returns tables for a given sheet.
        
        :param str sheet_name: Excel sheet name
        :return: tables
        :rtype: list(xml_tables)
        """
        return self.xml_parser.get_tables(self.xml_parser.get_xml_sheet(sheet_name))

    def save_tables_to_xml(self):
        """Saves tables to the XML file."""
        for sheet in self.sheets_list:
            sheet_element = self.xml_parser.get_xml_sheet(sheet.get_sheet_name())
            for table in sheet.get_tables():
                table_element = self.xml_parser.get_table(sheet_element, table.table_index)
                if table_element is not None:
                    header_element = self.xml_parser.add_header(table_element)
                    self.save_header_fields_to_xml(header_element, table.header_dict)
        # TODO: missing parameter?
        self.xml_parser.write_xml()

    def save_header_fields_to_xml(self, parent_element, header_dict, key=None):
        """Saves computed header fields to the XML file.
        
        :param Element parent_element: xml parent element
        :param dict header_dict: dict for header
        :param key: key for dict
        :type key: str or None
        """
        if isinstance(header_dict, dict):
            for key, value in header_dict.iteritems():
                header_field_element = self.xml_parser.add_header_field(parent_element, key)
                self.save_header_fields_to_xml(header_field_element, value, key)
        else:
            if key:
                self.xml_parser.add_header_field(parent_element, key)

    def get_sheets_from_xml(self):
        """Returns all sheet elements specified in XML.
    
        :return: list of sheet elements
        :rtype: list(xml.etree.ElementTree.SubElement)
        """
        return self.xml_parser.get_xml_sheets()

    def add_sheet(self, sheet):
        """Adds a sheet.
        
        :param SheetObject sheet: a sheet object
        """
        self.sheets_list.append(sheet)
        self.sheets_index_dict[sheet.name] = self.sheet_index
        self.sheet_index += 1

    def init_logger(self, name):
        """Initializes logger. 
        
        :param str name: name for the logger, best '__name__'
        :return: logger 
        :rtype: logging.Logger
        """
        logger = logging.getLogger(name)
        logger.setLevel(logging.DEBUG)
        # avoid multiple handlers respectively logs
        if not len(logger.handlers):
            stream_handler = logging.StreamHandler()
            stream_handler.setLevel(logging.DEBUG)
            formatter = logging.Formatter("(l.%(lineno)d) - %(asctime)s - %(name)s - %(levelname)s - %(message)s")
            stream_handler.setFormatter(formatter)
            logger.addHandler(stream_handler)
        return logger
