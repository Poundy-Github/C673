"""
@author: uidq3472

http://xlrd.readthedocs.io/en/latest/
https://xlwt.readthedocs.io/en/latest/
http://xlutils.readthedocs.io/en/latest/

-> ATTENTION to indexing: most of the time has to be decremented by 1 before use 
   due to the aligning to xlwings which is 1 indexed instead of zero indexed
"""

from __future__ import print_function
import xlrd
import xlwt
# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.libwrappers._excel_library_wrapper import ExcelLibraryWrapper
from dataobjects import excel_sheet_object, excel_table_object
# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.utils import excel_utils as eu
# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.utils import unorderd_tree as utree
# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.xmldescriptor.xml_defs import table_start_attr, table_end_attr, header_rows_attr


class ExcelFileObject(ExcelLibraryWrapper):
    """ExcelFileObject for xlrd/xlwt libraries.
    
    :param str configuration_xml_path: a (relative) path to a Config XML file
    """

    def __init__(self, configuration_xml_path):
        self.logger = self.init_logger(__name__)
        # log used library versions
        self.logger.debug("using xlrd/xlwt: {xlrd_v}/{xlwt_v}".format(xlrd_v=xlrd.__VERSION__, xlwt_v=xlwt.__VERSION__))

        # call superclass constructor
        ExcelLibraryWrapper.__init__(self, configuration_xml_path)

        self.workbook = None

        self.read_workbook()

    def read_workbook(self):
        """Reads in a Excel file with xlrd."""
        try:
            self.workbook = xlrd.open_workbook(self.excel_file_path, on_demand=True)  # , formatting_info=True)
        except Exception:
            # TODO: improve Exception
            self.logger.error("xlrd_wrapper.readWorkbook")
        else:
            self.logger.debug("read in workbook '{workbook}'".format(workbook=self.excel_file_path))

    def get_library_sheets(self):
        """Returns all sheets of a workbook.
        
        :return: list of sheets
        :rtype: list(xlrd.sheet)
        """
        return self.workbook.sheets()

    def get_library_sheet(self, sheet_identifier):
        """Returns one specific sheet from a workbook. 
        
        :param str sheet_identifier: a sheet name
        :return: xlrd sheet object by name
        :rtype: list(xlrd.sheet)
        """
        return self.workbook.sheet_by_name(sheet_identifier)

    def get_xml_sheet_names(self):
        """Returns sheet names present in the XML file.
        
        :return: Excel sheet names
        :rtype: list(str)
        """
        return self.xml_parser.get_sheet_names()

    def get_sheet_contents(self, sheet_names):
        """Computes sheets and their tables and data.
        
        :param sheet_names: Excel sheet names 
        :type sheet_names: list(str)
        :return: sheets
        :rtype: list(SheetObject) or None
        """
        if hasattr(sheet_names, "__iter__"):
            for sheet_name in sheet_names:
                sheet_object = excel_sheet_object.SheetObject(sheet_name, self.xml_parser.get_sheet_configuration(
                    self.xml_parser.get_xml_sheet(sheet_name)))
                self.get_sheet_content(sheet_object)
                self.add_sheet(sheet_object)

            return self.sheets_list
        else:
            self.logger.error("Method needs iterable! (e.g. list of sheet names)")
            return

    def get_sheet_content(self, sheet_object):
        """Computes content of one SheetObject."""
        sheet_name = sheet_object.get_sheet_name()

        # get merged cells and tables for sheet
        sheet_merged_cells = self.get_merged_cells(sheet_name)
        tables = self.get_tables_from_xml(sheet_name)

        # TODO: remove hardcoding, or rather move the whole thing somewhere else;
        # e.g. move to table object in order to make the parameters more transparent?
        # compute xml tables to table objects and add them to the sheet object
        for table in tables:
            table_object = excel_table_object.ExcelTableObject(eu.parse_cell_idx(table.attrib[table_start_attr]),
                                                               eu.parse_cell_idx(table.attrib[table_end_attr]),
                                                               int(table.attrib[header_rows_attr]))
            sheet_merged_cells = self.get_table_content(sheet_name, sheet_merged_cells, table_object)
            sheet_object.add_table(table_object)

    def save(self):
        """ 
        :raises NotImplementedError: method not yet implemented
        """
        # wwb = copy(self.wb)
        # wwb.save("test.xls")
        raise NotImplementedError

    def close(self):
        """ 
        :raises NotImplementedError: method not yet implemented
        """
        raise NotImplementedError

    def get_table_content(self, sheet_name, cells, table_object):
        """Computes content of on ExcelTableObject.

        :param sheet_name:
        :param cells:
        :param table_object:
        :return:
        """
        """
        TODOs: 
        -> aufteilen in Funktionen und verschieben falls sinnvoll in entsprechende Klassen
        -> effizienz! z.B. merged cells ueber dicts schon im dump etwas ordnen und hier besser drauf zugreifen
        -> alles auf logger umbauen und prints entfernen
        -> contents laden falls in xml vorhanden!
        ==> refactoring, splitting and improving!
        
        """
        # create table object or something for mapping purposes? as soon as I know how to clue all together
        # get sheet xlrd sheet object
        sheet_oectbj = self.get_library_sheet(sheet_name)
        header_rows = table_object.header_rows
        table_start = table_object.table_start
        table_end = table_object.table_end

        self.logger.debug("(#rows){header_rows}::(start){table_start}:(end){table_end}".format(header_rows=header_rows,
                                                                                               table_start=table_start,
                                                                                               table_end=table_end))

        # ranges for reading the table header segment
        header_row_range = range(table_start[0] - 1, (table_start[0] - 1) + header_rows)
        header_column_range = range(table_start[1] - 1, table_end[1])

        # ranges for reading the table data objects segment
        data_row_range = range((table_start[0] - 1) + header_rows, table_end[0])
        data_column_range = range(table_start[1] - 1, table_end[1])

        # TODO: save differentiation of merged cells to dump?
        # split merged cell information into header... 
        header_merged_cells = []
        if len(cells) > 0:
            self.logger.info("header_row_range: {0}".format(header_row_range))
            self.logger.info("header_column_range: {0}".format(header_column_range))
            for cell in cells:
                if cell.start_row in header_row_range and cell.start_column in header_column_range:
                    header_merged_cells.append(cell)

        self.logger.debug("Headersegment merged cells: {0}".format(header_merged_cells))

        table_object.header_merged_cells = header_merged_cells

        # ...and dataobjects                
        data_merged_cells = []
        if len(cells) > 0:
            for cell in cells:
                if cell.start_row in data_row_range and cell.start_column in data_column_range:
                    data_merged_cells.append(cell)

        self.logger.debug("Datasegment merged cells: {0}".format(data_merged_cells))

        table_object.data_merged_cells = data_merged_cells

        # remove used cells so next table has not to check cells which can not be in its range anymore
        for cell in cells:
            if cell in data_merged_cells or cell in header_merged_cells:
                cells.remove(cell)

        self.logger.debug("Remaining merged cells: {0}".format(cells))

        header_tree = self.create_header_tree(sheet_oectbj, header_column_range, header_row_range, header_merged_cells)
        # print([(node.title, node.col_index, node.row_index) for node in utree.get_leave_nodes(header_tree)])

        # TODO: work with dataobjects; add header from file option and header saving to file! ;
        # attention to merged cells in the dataobjects segment!
        data_segment = []
        in_merged = False
        merged_end = None
        for row in data_row_range:
            data_row = []
            for column in data_column_range:
                if merged_end < column:
                    in_merged = False
                if in_merged:
                    continue
                else:
                    data_row.append(sheet_oectbj.cell_value(row, column))
                for cell in data_merged_cells:
                    if column == cell.start_column and row == cell.start_row:
                        in_merged = True
                        merged_end = cell.end_column

            in_merged = False
            data_segment.append(data_row)

        table_object.data_list = data_segment
        table_object.set_header_tree(header_tree)

        return cells

    def create_header_tree(self, sheet_object, header_column_range, header_row_range, header_merged_cells, parent=None):
        """Returns a tree structure of the header fields in the specified ranges of the provided sheet.
        
        :param xlrd.sheet sheet_object: Excel sheet to operate on
        :param list(int) header_column_range: the range of columns of the header
        :param list(int) header_row_range: the range of rows of the header
        :param list(MergedCell) header_merged_cells: list of merged cells in the header area
        :param parent: parent node
        :type parent: TreeNode or None
        :return: tree of headers
        :rtype: TreeNode
        """
        # empty root node because of tables without a single top element
        if parent is None:
            parent = utree.RootNode()

        # if there is at least one row left, compute it
        if len(header_row_range) > 0 and header_row_range:
            row = header_row_range[0]

            in_merged = False
            merged_end = None

            for column in header_column_range:

                # check if already in a merged cell range
                if merged_end < column:
                    in_merged = False
                if in_merged:
                    continue

                # get cell value and check if its empty
                child = parent
                cell_value = sheet_object.cell_value(row, column)
                if cell_value:
                    child = utree.TreeNode(cell_value, parent, row_index=row, column_index=column)
                    parent.add_child(child)

                # check if is a merged cell
                merge_range = None
                for cell in header_merged_cells:
                    # check if a merged cell is starting here
                    if column == cell.start_column and row == cell.start_row:
                        in_merged = True
                        merged_end = cell.end_column
                        merge_range = range(cell.start_column, cell.end_column + 1)
                    # else check if we are in a merged cell range
                    elif cell.start_column < column <= cell.end_column and row == cell.start_row:
                        # there already is a recursion running down this path: abort method call
                        return

                # handle if in merged cell range or not
                if in_merged:
                    self.create_header_tree(sheet_object, merge_range, header_row_range[1:], header_merged_cells, child)
                else:
                    self.create_header_tree(sheet_object, [column], header_row_range[1:], header_merged_cells, child)

            return parent


if __name__ == "__main__":
    print("main not implemented")
