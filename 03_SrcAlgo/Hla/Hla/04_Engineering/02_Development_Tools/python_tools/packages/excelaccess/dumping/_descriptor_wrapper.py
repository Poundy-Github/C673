"""
@author: uidq3472
"""

from abc import ABCMeta, abstractmethod
# noinspection PyUnresolvedReferences
from excelaccess.utils import defs
import pickle
import logging
import os.path


class DescriptorWrapper:
    """Base class and/or interface for classes that extract and dump information from an Excel file. 
    
    :param str excel_file_path: a (relative) path to an Excel file
    :param dump_path: a (relative) path to save destination
    :type dump_path: str or None
    """
    __metaclass__ = ABCMeta

    def __init__(self, excel_file_path, dump_path=None):
        self.dump_dict = {}
        self.excel_file_path = os.path.abspath(excel_file_path)
        self.dump_path = dump_path if (
            dump_path is None or dump_path.endswith(".dump") or dump_path == "") else dump_path + ".dump"

    def _init_logger(self, name):
        """Initializes logger for the calling (inherited) class.
        
        :param str name: name of the logger, best '__name__'
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

    @abstractmethod
    def read_workbook(self):
        """Method for reading excel file. In this stadium just computes file name and save path. 
        
        :raises NotImplementedError: if inherited class does not implement this method 
        """
        raise NotImplementedError

    @abstractmethod
    def get_library_sheets(self):
        """Method for getting sheets. Needs to be specified according to inherited class. 
        
        :raises NotImplementedError: if inherited class does not implement this method 
        """
        raise NotImplementedError

    @abstractmethod
    def get_library_sheet(self, sheet_identifier):
        """Method for getting a specific sheet. Identifier depends on the inherited class and the library used. 
        
        :raises NotImplementedError: if inherited class does not implement this method 
        """
        raise NotImplementedError

    @abstractmethod
    def parse_sheet_names(self):
        """Method for parsing sheet names to a common structure in order to save them. E.g. a list. 
        
        :raises NotImplementedError: if inherited class does not implement this method 
        """
        raise NotImplementedError

    @abstractmethod
    def parse_merged_cells(self):
        """Method for parsing merged cells to a common and well defined structure. In this case, to the MergedCell class below. 
        
        :raises NotImplementedError: if inherited class does not implement this method 
        """
        raise NotImplementedError

    def dump_description(self):
        """Method for dumping computed descriptions as dictionary to file.
        right now contains:
        
        - merged cells 
        - sheet names
        """
        try:
            self.logger.info("Trying to write dump file to file: {0}".format(self.dump_path))
            with open(self.dump_path, "w") as dumpfile:
                # write dump dict to dump file
                pickle.dump(self.dump_dict, dumpfile)
        except Exception:
            self.logger.exception("Could not write dump to file: {0}".format(self.dump_path))
        else:
            self.logger.info("Wrote dumpe to file: {0}".format(self.dump_path))

    def read_dump(self, file_path=None):
        """Method for reading a dump-file created by this script which afterwards is accessible by below methods.
        
        :param file_path: a (relative) path to a dump file
        :type file_path: str or None
        """
        self.logger.debug("Dump dictionary before reading dump file: {0}".format(self.dump_dict))
        file_path = file_path if file_path else self.dump_path
        try:
            with open(file_path) as dumpfile:
                self.dump_dict = pickle.load(dumpfile)
        except IOError:
            self.logger.exception("Could not read dump from file: {0}".format(file_path))
        else:
            self.logger.info("Successfully read dump from file: {0}".format(file_path))

    def get_merged_cells_for_sheet(self, sheet_name):
        """Returns a list of MergedCell-Objects for the given Excel sheet name. Empty if there is no merged cell present in the sheet.
        
        :return: merged cells for a given sheet in an Excel file
        :rtype: list(MergedCell)
        """
        return self.dump_dict[defs.dict_key_merged_cells][sheet_name]

    def get_all_merged_cells(self):
        """Returns all merged cells. Keys are sheet names.
        
        :return: all merged cells of an Excel file
        :rtype: dict((str, MergedCell))
        """
        return self.dump_dict[defs.dict_key_merged_cells]

    def get_sheet_names(self):
        """Returns a list of the sheet names present in this Excel file. 
        
        :return: all sheet names of an Excel file 
        :rtype: list(str)
        """
        return self.dump_dict[defs.dict_key_sheet_names]


class MergedCell:
    """Class for storing cell ranges of merged cells in a well defined way. Initializes a MergedCell instance with a
    merged cell's stretching vertices.
    
    :param int start_row: row value of the first cell 
    :param int start_column: column value of the first cell
    :param int end_row: row value of the last cell
    :param int end_column: column value of the last cell
    """

    def __init__(self, start_row, start_column, end_row, end_column):
        self.start_row = start_row
        self.start_column = start_column
        self.end_row = end_row
        self.end_column = end_column

    def get_range(self):
        """Returns the range of merged cells as a 2-tuple of 2-tuples representing the starting and the ending cell of the merged area. 
        
        :return: start and end cell as 2-tuples
        :rtype: ((int, int), (int, int))
        """
        return (self.start_row, self.start_column), (self.end_row, self.end_column)

    def get_column_range(self):
        """Returns the merged range in column perspective. 
        
        :return: range of the columns
        :rtype: range 
        """
        return range(self.start_column, self.end_column)

    def get_row_range(self):
        """Returns the merged range in row perspective. 
        
        :return: range of the rows
        :rtype: range
        """
        return range(self.start_row, self.end_row)

    def get_range_length(self):
        """Returns the column delta of the merged range. 
        
        :return: simple difference of the columns
        :rtype: int
        """
        return self.end_column - self.start_column

    def get_range_height(self):
        """Returns the row delta of the merged range. 
        
        :return: simple difference of the rows
        :rtype: int
        """
        return self.end_row - self.start_row
