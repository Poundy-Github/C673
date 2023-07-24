"""
@author: uidq3472

https://openpyxl.readthedocs.io/en/default/
"""

import openpyxl
import os.path
# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.libwrappers._excel_library_wrapper import ExcelLibraryWrapper


class ExcelFileObject(ExcelLibraryWrapper):
    """Openpyxl implementation of ExcelFileObject."""

    def __init__(self, excel_file_path):
        """ TODO: fill 
        TODO: adapt/update according to xlrd or just remove it?"""
        print("using openpyxl: {openpyxl_v}".format(openpyxl_v=openpyxl.__version__))
        self.excel_file_path = excel_file_path

        # call superclass contructor
        ExcelLibraryWrapper.__init__(self, self.excel_file_path)

        self.workbook = None

        try:
            self.read_workbook()
        except Exception:
            # TODO: improve Exception
            print("openpyxl_wrapper")
            raise
        else:
            pass

    def read_workbook(self):
        """ TODO: fill """
        try:
            self.workbook = openpyxl.load_workbook(self.excel_file_path, read_only=False, keep_vba=True)
        except Exception:
            print("openpyxl_wrapper.readWorkbook")
            raise
        print(self.get_library_sheet("MFC431").merged_cell_ranges)

    def get_library_sheets(self):
        """ TODO: fill """
        return [sheet for sheet in self.wb]

    def get_library_sheet(self, sheet_identifier):
        """ TODO: fill """
        return self.workbook[sheet_identifier]

    def save(self, path=None, file_name=None):
        """ -> test saving """
        if path is None:
            self.workbook.save(self.excel_file_path)
        elif file_name is None:
            self.workbook.save(path)
        else:
            self.workbook.save(os.path.join(path, file_name))

            # raise NotImplementedError

    def close(self):
        """ -> not existing for this lib??? """
        self.save()

        # raise NotImplementedError

    def get_column_headers(self, excel_sheet=None, caption_row=1):
        """ - Load headers of columns """
        raise NotImplementedError


if __name__ == "__main__":
    print("not implemented yet")
