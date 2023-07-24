"""
@author: uidq3472
"""

# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.dumping._descriptor_wrapper import DescriptorWrapper, MergedCell
import openpyxl
import os
# noinspection PyUnresolvedReferences
from excelaccess.utils import defs
# noinspection PyUnresolvedReferences
from excelaccess.utils.excel_utils import parse_cell_idx_zero


class OpenpyxlDeEx(DescriptorWrapper):
    """Implementation of DescriptionWrapper with the openpyxl library. 
    
    :param str excel_file_path: a (relative) path to an Excel file
    :param dump_path: just used if a dump file is created
    :type dump_path: str or None
    """

    def __init__(self, excel_file_path, dump_path=None):
        DescriptorWrapper.__init__(self, excel_file_path, dump_path)

        self.logger = self._init_logger(__name__)
        self.logger.debug("using openpyxl: {openpyxl_v}".format(openpyxl_v=openpyxl.__version__))

        self.workbook = None
        self.merged_cells_dict = {}

    def read_workbook(self):
        """Read and parse given Excel file."""
        # check if dump file has to be (re)created or if no dump file requested
        if (not self.dump_path) or (
                        not os.path.exists(self.dump_path) or os.path.getmtime(self.excel_file_path) > os.path.getmtime(
                            self.dump_path) or os.path.getmtime(os.path.realpath(__file__)) > os.path.getmtime(
                            self.dump_path)):
            if self.dump_path:
                self.logger.info("Dump-File is outdated. Creating new one: {0}".format(self.dump_path))
            else:
                self.logger.info("Reading information from Excel.")
            try:
                self.workbook = openpyxl.load_workbook(self.excel_file_path, read_only=False, keep_vba=True)
                self.parse_merged_cells()
                self.parse_sheet_names()
                if self.dump_path:
                    self.dump_description()
            except IOError:
                self.logger.exception("Could not read from Excel.")
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
        """Method returning all excel sheets according to openpyxl library - being in the 'visible' state. 
        
        :return: all (visible) excel sheets
        :rtype: list(openpyxl.worksheet)
        """
        return [sheet for sheet in self.workbook if sheet.sheet_state == "visible"]

    def get_library_sheet(self, sheet_identifier):
        """Method returning specific excel sheets according to openpyxl library. 
        
        :param str sheet_identifier: name of a sheet
        :return: sheet object
        :rtype: openpyxl.worksheet
        """
        return self.workbook[sheet_identifier]

    def parse_sheet_names(self):
        """Method parsing sheet names according to openpyxl library."""
        sheet_names_list = [sheet.title for sheet in self.get_library_sheets()]
        self.dump_dict[defs.dict_key_sheet_names] = sheet_names_list

    def parse_merged_cells(self):
        """Method for parsing merged cells according to openpyxl library."""
        for sheet in self.get_library_sheets():
            merged_cell_ranges = sheet.merged_cell_ranges
            self.logger.debug(merged_cell_ranges)
            if len(merged_cell_ranges) > 0:
                for cell_range_str in merged_cell_ranges:
                    rlo, clo, rhi, chi = self.parse_cell_range(cell_range_str)
                    self.merged_cells_dict.setdefault(sheet.title, []).append(MergedCell(rlo, clo, rhi, chi))
            else:
                self.merged_cells_dict.setdefault(sheet.title, [])

        self.dump_dict[defs.dict_key_merged_cells] = self.merged_cells_dict
        self.logger.debug(self.dump_dict)

    def parse_cell_range(self, cell_range_str):
        """Method parsing openpyxl cell ranges. 
        
        :param str cell_range_str: an openpyxl cell range
        :return: start row/col and end row/col
        :rtype: (int, int, int, int)
        """
        start_cell, end_cell = cell_range_str.split(":")
        start_row, start_column = parse_cell_idx_zero(start_cell)
        end_row, end_column = parse_cell_idx_zero(end_cell)

        return start_row, start_column, end_row, end_column
