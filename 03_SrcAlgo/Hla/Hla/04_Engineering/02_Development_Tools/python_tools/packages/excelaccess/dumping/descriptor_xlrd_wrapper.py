"""
@author: uidq3472
"""

# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.dumping._descriptor_wrapper import DescriptorWrapper, MergedCell
# noinspection PyUnresolvedReferences
from excelaccess.utils import defs
import xlrd
import os.path
import traceback
import sys


class XlrdDeEx(DescriptorWrapper):
    """Implementation of DescriptionWrapper with the xlrd library. 
    
    :param str excel_file_path: a (relative) path to an Excel file
    :param dump_path: just used if a dump file is created
    :type dump_path: str or None
    """

    def __init__(self, excel_file_path, dump_path=None):
        DescriptorWrapper.__init__(self, excel_file_path, dump_path)

        self.logger = self._init_logger(__name__)
        self.logger.debug("using xlrd: {xlrd_v}".format(xlrd_v=xlrd.__VERSION__))

        self.workbook = None
        self.merged_cells_dict = {}

    def read_workbook(self):
        """Method for reading and processing excel file according to xlrd library."""
        # check if dump file has to be (re)created or if no dump file requested
        if not self.dump_path or not os.path.exists(self.dump_path) or os.path.getmtime(
                self.excel_file_path) > os.path.getmtime(self.dump_path) or os.path.getmtime(
                os.path.realpath(__file__)) > os.path.getmtime(self.dump_path):
            if self.dump_path:
                self.logger.info("Dump-File is outdated. Creating new one: {0}".format(self.dump_path))
            else:
                self.logger.info("Reading information from Excel.")
            try:
                self.workbook = xlrd.open_workbook(self.excel_file_path, on_demand=True, formatting_info=True)
                self.parse_merged_cells()
                self.parse_sheet_names()
                if self.dump_path:
                    self.dump_description()
            except IOError:
                traceback.print_exc(file=sys.stdout)
                self.logger.exception("Could not recreate dump file: {0}".format(self.excel_file_path))
            else:
                if self.dump_path:
                    self.logger.info("Successfully created up-to-date dump file.")
                else:
                    self.logger.info("Successfully read from Excel.")
        elif self.dump_path:
            # dump file requested and up-to-date
            self.logger.info("Dump file is up-to-date: {0}. Reading from file.".format(self.dump_path))
            self.read_dump(self.dump_path)

    def get_library_sheets(self):
        """Method returning all excel sheets according to xlrd library. 
        
        :return: all xlrd sheets
        :rtype: list(xlrd.sheet)
        """
        return self.workbook.sheets()

    def get_library_sheet(self, sheet_identifier):
        """Method returning specific excel sheet according to xlrd library. 
        
        :param str sheet_identifier: name of a xlrd sheet
        :return: sheet by name
        :rtype: xlrd.sheet
        """
        return self.workbook.sheet_by_name(sheet_identifier)

    def parse_sheet_names(self):
        """Method parsing sheet names according to xlrd library."""
        sheet_names_list = [sheet.name for sheet in self.get_library_sheets()]
        self.dump_dict[defs.dict_key_sheet_names] = sheet_names_list

    def parse_merged_cells(self):
        """Method for parsing merged cells according to xlrd library."""
        for sheet in self.get_library_sheets():
            merged_cells = sheet.merged_cells
            if len(merged_cells) > 0:
                for crange in merged_cells:
                    rlo, rhi, clo, chi = crange
                    merged_cell = MergedCell(rlo, clo, rhi - 1, chi - 1)  # minus one because of exclusive upper bounds
                    self.merged_cells_dict.setdefault(sheet.name, []).append(merged_cell)
            else:
                self.merged_cells_dict.setdefault(sheet.name, [])

        self.dump_dict[defs.dict_key_merged_cells] = self.merged_cells_dict
        self.logger.debug(self.dump_dict)
