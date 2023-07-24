"""
@author: uidq3472
"""

from __future__ import print_function
import os
import argparse
import logging
# needed if deployed with local packages not installed to the global python instance
# noinspection PyUnresolvedReferences
from excelaccess.utils.general_functions import local_packages

local_packages()
# noinspection PyUnresolvedReferences
from excelaccess.libwrappers import xlrd_xlwt_wrapper
# noinspection PyUnresolvedReferences
from excelaccess.utils.unorderd_tree import get_leave_lambda

# xml cfg paths for testing
hla_xml = ".\hla_algo_interface_types.xls.xml"
lsd_xml = ".\lsd_algo_interface_types.xls.xml"
mfc_xml = ".\MFC401_ResourceSheet.xlsm.xml"


def main():
    """For testing purposes. Actual functionality lies in ExcelFileReader-class below this function."""

    """ testing with hla """
    hla_efo = ExcelFileReader(hla_xml).read_excel_file()
    with open("./test_out/hla_test.txt", "w") as testfile:
        testfile.write("Excel file: '{0}'\n\n".upper().format(hla_efo.excel_file_path))
        for sheet in hla_efo.get_sheet_contents(hla_efo.xml_parser.get_sheet_names()):
            testfile.write(sheet.__str__())

    table = hla_efo.get_sheet_by_name("Meas").get_table(0)
    values = get_leave_lambda(table.header_tree, lambda node: [(node.title, node.get_relative_col())])
    col = None
    for value in values:
        title = value[0]
        relative_column = value[1]
        if title == "Component / Description":
            col = relative_column

    for row in table.data_list:
        print(row[col])

    """ testing with lsd """
    lsd_efo = ExcelFileReader(lsd_xml).read_excel_file()
    with open("./test_out/lsd_test.txt", "w") as testfile:
        testfile.write("Excel file: '{0}'\n\n".upper().format(lsd_efo.excel_file_path))
        for sheet in lsd_efo.get_sheet_contents(lsd_efo.xml_parser.get_sheet_names()):
            testfile.write(sheet.__str__())

    """ testing with mfc """
    mfc_efo = ExcelFileReader(mfc_xml).read_excel_file()
    with open("./test_out/mfc_test.txt", "w") as testfile:
        testfile.write("Excel file: '{0}'\n\n".upper().format(mfc_efo.excel_file_path))
        for sheet in mfc_efo.get_sheet_contents(mfc_efo.xml_parser.get_sheet_names()):
            testfile.write(sheet.__str__())

    table = mfc_efo.get_sheet_by_index(0).get_table(5)

    print(get_leave_lambda(table.header_tree, lambda node: (node.get_absolute_column())))


class ExcelFileReader:
    """Class for reading an Excel file based on the provided XML configuration file.
    
    :param cfg_xml: a (relative) path to Config XML (if not provided via command line arguments)
    :type cfg_xml: str or None
    """

    def __init__(self, configuration_xml=None):
        """ Constructor for ExcelFileReader-class. """
        self.logger = None
        self.init_logger()
        self.parser = None
        self.init_argument_parser()
        arguments = self.parser.parse_args()
        self.configuration_xml = configuration_xml if configuration_xml else arguments.cfg_xml

    def read_excel_file(self):
        """Reads a given Excel file (through XML).
        
        :return: Excel file representation
        :rtype: xlrd_xlwt_wrapper.ExcelFileObject
        """
        try:
            if os.path.exists(self.configuration_xml) and os.path.isfile(self.configuration_xml):
                configuration_xml = os.path.abspath(self.configuration_xml)
                self.logger.debug("Using \'{0}\'.".format(configuration_xml))
            else:
                self.logger.debug("Tried to use \'{0}\'.".format(self.configuration_xml))
                raise IOError
        except IOError:
            self.logger.exception("file not found or is no (XML-)file: {path}".format(path=self.configuration_xml))
        else:
            try:
                excel_file = xlrd_xlwt_wrapper.ExcelFileObject(configuration_xml)
            except Exception:
                # TODO: improve Exception
                self.logger.exception("Could not compute configuration_xml-File ({0}).".format(self.configuration_xml))
            else:
                return excel_file

    def init_logger(self):
        """Initializes logger for this module."""
        self.logger = logging.getLogger(__name__)
        self.logger.setLevel(logging.DEBUG)
        # avoid multiple handlers respectively logs
        if not len(self.logger.handlers):
            stream_handler = logging.StreamHandler()
            stream_handler.setLevel(logging.DEBUG)
            formatter = logging.Formatter("(l.%(lineno)d) - %(asctime)s - %(name)s - %(levelname)s - %(message)s")
            stream_handler.setFormatter(formatter)
            self.logger.addHandler(stream_handler)

    def init_argument_parser(self):
        """Initializes argument parser."""
        self.parser = argparse.ArgumentParser(description="Provide Config as XML file")
        self.parser.add_argument("cfg_xml", action="store", nargs="*", default=None, help="Path to Config XML.")


if __name__ == "__main__":
    main()
