"""
@author: uidq3472
"""

from descriptor_xlrd_wrapper import XlrdDeEx
from descriptor_openpyxl_wrapper import OpenpyxlDeEx
# noinspection PyUnresolvedReferences
from excelaccess.utils.excel_utils import is_old_excel_format
import logging
import os.path


class DescriptionExtractor:
    """Central class for usage of DescriptionWrapper implementations. Determines which library to use according to excel file ending. 
    
    :param str excel_file_path: a (relative) path to an Excel file
    :param dump_path: just used if a dump file is created
    :type dump_path: str or None
    """

    def __init__(self, excel_file_path, dump_path=None):
        # set up logger
        self.logger = logging.getLogger(__name__)
        self.logger.setLevel(logging.DEBUG)
        # avoid multiple handlers respectively logs
        if not len(self.logger.handlers):
            stream_handler = logging.StreamHandler()
            stream_handler.setLevel(logging.DEBUG)
            formatter = logging.Formatter("(l.%(lineno)d) - %(asctime)s - %(name)s - %(levelname)s - %(message)s")
            stream_handler.setFormatter(formatter)
            self.logger.addHandler(stream_handler)

        self.excel_file_path = excel_file_path
        self.dump_path = dump_path
        self.dumper = None
        self.dump_reader = None

    def read_workbook(self):
        """Reads Excel file with apropriate liberary - depends on file ending (new or old)."""
        # check file ending to determine which library to use 
        is_old = is_old_excel_format(self.excel_file_path)
        if is_old is None:
            self.logger.error("No valid file extension for an Excel file: {0}".format(self.excel_file_path))
        elif is_old:
            self.logger.debug("is old excel file")
            self.dumper = XlrdDeEx(self.excel_file_path, self.dump_path)
        elif not is_old:
            self.logger.debug("is new excel file")
            self.dumper = OpenpyxlDeEx(self.excel_file_path, self.dump_path)

        try:
            self.dumper.read_workbook()
        except IOError:
            self.logger.exception("Could not read Excel file: {0}".format(self.excel_file_path))
        else:
            self.logger.info("Successfully read Excel file: {0}".format(self.excel_file_path))

    def read_workbooks(self, excel_file_paths):
        """Read in multiple excel files. 
        
        :param excel_file_paths: the (relative) path to multiple Excel files 
        :type excel_file_paths: list(str)
        
        :raises NotImplementedError: not yet finished
        
        TODO: apply to code if needed and vice versa
        """
        raise NotImplementedError
        # if not hasattr(excel_file_paths, "__iter__"):
        #     excel_file_paths = [excel_file_paths]
        #
        # for excel_file_path in excel_file_paths:
        #     self.read_workbook(excel_file_path)

    def read_dump(self, dump_file_path):
        """Reads in an existing dump file.
        
        :param str dump_file_path: a (relative) path to a dump file
        """
        self.dump_reader = XlrdDeEx()
        self.dump_reader.read_dump(dump_file_path)

    def get_dump_name_from_excel(self, excel_file_path):
        """Computes dump file name from excel file name. 
        
        :param str excel_file_path: a (relative) path to an Excel file
        :reurn: dump file name by Excel file name
        """
        return os.path.split(excel_file_path)[1] + ".dump"

    def get_merged_cells_from_dump(self, sheet_name):
        """Returns merged cells for a specific sheet. 
        
        :param str sheet_name: a sheet name
        :return: merged cells from dump for a given sheet
        :rtype: list(MergedCell)
        """
        return self.dump_reader.get_merged_cells_for_sheet(sheet_name)

    def get_sheet_names_from_dump(self):
        """Returns all sheet names saved to the dump file. 
        
        :return: all sheet names from dump
        :rtype: list(str)
        """
        return self.dump_reader.get_sheet_names()

    def get_merged_cells(self, sheet_name):
        """Returns merged cells for a specific sheet. 
        
        :return: merged cells for a given sheet
        :rtype: list(MergedCell)
        """
        return self.dumper.get_merged_cells_for_sheet(sheet_name)

    def get_sheet_names(self):
        """Returns all sheet names from dump dict.
        
        :return: all sheet names from dump dict
        :rtype: list(str)
        """
        return self.dumper.get_sheet_names()
