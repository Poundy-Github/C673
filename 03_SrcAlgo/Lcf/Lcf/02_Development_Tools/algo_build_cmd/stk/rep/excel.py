"""
stk/rep/excel
-------------

Module to Create Excel Based Reports.

:org:           Continental AG
:author:        Robert Hecker,
                David Kubera,
                Maria Nicoara

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:02CET $
"""

# pylint:disable=C0103,R0912,R0913

# Imports ------------------------------------------------------------------
from win32com.client import constants, DispatchEx
from win32gui import PostMessage
from win32con import WM_QUIT, PROCESS_TERMINATE  # , WM_CLOSE
from win32process import GetWindowThreadProcessId
from win32api import OpenProcess, TerminateProcess, CloseHandle
from time import sleep
# from win32com.client.dynamic import Dispatch
from pythoncom import com_error  # pylint:disable=E0611
import types

#===================================================================================
# Constant declarations
#===================================================================================
COLOR_MAP = {'Black': 1,
             'White': 2,
             'Red': 3,
             'Bright Green': 4,
             'Blue': 5, 'Yellow': 6,
             'Pink': 7,
             'Turqoise': 8,
             'Dark Red': 9,
             'Green': 10,
             'Dark Blue': 11,
             'Dark Yellow': 12,
             'Violet': 13,
             'Teal': 14,
             'Gray-25%': 15,
             'Gray-50%': 16,
             'Sky Blue': 33,
             'Light Turqoise': 34,
             'Light Green': 35,
             'Light Yellow': 36,
             'Pale Blue': 37,
             'Rose': 38,
             'Lavendar': 39,
             'Tan': 40,
             'Light Blue': 41,
             'Aqua': 42,
             'Lime': 43,
             'Gold': 44,
             'Light Orange': 45,
             'Orange': 46,
             'Blue-Gray': 47,
             'Gray-40%': 48,
             'Dark Teal': 49,
             'Sea Green': 50,
             'Dark Green': 51,
             'Olive Green': 52,
             'Brown': 53,
             'Plum': 54,
             'Indigo': 55,
             'Gray-80%': 56}
# The codes for the specified alignments in excel
VERTICAL_ALIGNMENT_TOP = -4160
VERTICAL_ALIGNMENT_CENTER = -4108
VERTICAL_ALIGNMENT_BOTOM = -4107

HORIZONTAL_ALIGNMENT_LEFT = -4131
HORIZONTAL_ALIGNMENT_CENTER = -4108
HORIZONTAL_ALIGNMENT_RIGHT = -4152

# The codes for the borders in excel:
# 7 - the left border of the cell
# 8 - the top border of the cell
# 9 - the bottom border of the cell
# 10 - the right border of the cell
# 11 - the inside vertical border of the cell
# 12 - the inside horizontal border of the cell
BORDERS_MAP = [7, 8, 9, 10, 11, 12]
# the excel code for the continuous type of border
# this constant can take values in [1,13] interval
CONTINUOUS_BORDER = 1

# Class ---------------------------------------------------------------------

############################################################################
# # Class for Excel File Read/Write access
#
#  Class which hase Base Methods for Reading and Writing Excel Files
############################################################################


class Excel(object):  # pylint: disable=R0902,R0904
    """
    **main class for MS Excel I/O**

    - You can use this class to read and write XLS files.

    **example usage:**

    .. python::

        # import excel:
        from stk.rep.excel import Excel

        # create instance and open an excel file:
        myXls = Excel(myExcelFile)
        # write some data:
        myXls.SetCellValue(5, 6, "1st value as string")
        myXls.SetCellValue(6, 6, 4711)
        # ok, cleanup:
        myXls.SaveWorkbook()
        myXls.Close()

        # now, let's read out these values:
        with Excel(myExcelFile) as myXls:
            # print the values:
            print("1: %s" % myXls.GetCellValue(5, 6))
            print("2: %d" % myXls.GetCellValue(6, 6))
        # on close, Excel automagically saves the workbook and closes gracefully

    """
    def __init__(self, workfile=None):  # Constructor
        # Start the conection with the Excel

        self.NUMBER_FORMAT_TEXT = "@"
        self.NUMBER_FORMAT_NUMBER = "0.00"
        self.NUMBER_FORMAT_DATE = "m/d/yyyy"
        self.NUMBER_FORMAT_TIME = "[$-F400]h:mm:ss AM/PM"
        self.NUMBER_FORMAT_PERCENTAGE = "0.00%"
        self.NUMBER_FORMAT_GENERAL = "General"

        self.FONT_NAME_ARIAL = "Arial"
        self.FONT_NAME_TIMES_NEW_ROMAN = "Times New Roman"
        self.FONT_NAME_COMIC = "Comic Sans MS"
        self.FONT_NAME_LUCIDA_CONSOLE = "Lucida Console"

        self.FONT_COLOR_RED = "Red"
        self.FONT_COLOR_YELLOW = "Yellow"
        self.FONT_COLOR_BLUE = "Blue"
        self.FONT_COLOR_GREEN = "Green"
        self.FONT_COLOR_GREY = "Gray-25%"
        self.FONT_COLOR_VIOLET = "Violet"

        self.ALIGNMENT_HORIZAONTAL_LEFT = "Left"
        self.ALIGNMENT_HORIZAONTAL_CENTER = "Center"
        self.ALIGNMENT_HORIZAONTAL_RIGHT = "Right"

        self.ALIGNMENT_VERTICAL_TOP = "Top"
        self.ALIGNMENT_VERTICAL_CENTER = "Center"
        self.ALIGNMENT_VERTICAL_BOTOM = "Botom"

        self.BORDER_DASHED = 1
        self.BORDER_THIN = 2
        self.BORDER_THICK1 = 3
        self.BORDER_THICK2 = 4

        self.CHART_TYPE_LINE_MARKERS = 65
        self.CHART_TYPE_COLUMNCLUSTERED = 51
        self.CHART_TYPE_BARCLUSTERED = 57
        self.CHART_TYPE_PIE = 5
        self.CHART_TYPE_XYSCATTER = -4169
        self.CHART_TYPE_AREA = 1
        self.CHART_TYPE_DOUGHNUT = -4120
        self.CHART_TYPE_SURFACE = 83

        self.CHART_PLOT_BY_COLUMNS = 2
        self.CHART_PLOT_BY_ROWS = 1

        self.CHART_LOCATION_OBJECT_CURRENT_SHEET = 2
        self.CHART_LOCATION_NEW_SHEET = 1

        self.__workbook = None
        self.__worksheet = None
        self.__app = DispatchEx("Excel.Application")
        self.__app.DisplayAlerts = False

        self._closeCalled = False

        if workfile is not None:
            self.OpenWorkbook(workfile)

    def __del__(self):  # Destructor
        # deprecated: we should remove this for the future!
        if self._closeCalled:
            return
        self.CloseWorkbook()
        self.__app.Quit()
        # delete all references in right order
        del self.__worksheet
        del self.__workbook
        del self.__app

    def Close(self):
        """close excel application, WM_CLOSE won't work with embedded startup option
        """
        self._closeCalled = True

        self.CloseWorkbook()

        hdl = self.__app.Hwnd
        proc = proc2 = GetWindowThreadProcessId(hdl)[1]
        PostMessage(hdl, WM_QUIT, 0, 0)
        # Allow some time for app to close
        for i in xrange(15):
            _, proc2 = GetWindowThreadProcessId(hdl)
            if proc2 != proc:
                break
            sleep(float(i) / 3)
        # If the application didn't close within 5 secs, force it!
        if proc == proc2:
            try:
                hdl = OpenProcess(PROCESS_TERMINATE, 0, proc)
                if hdl:
                    TerminateProcess(hdl, 0)
                    CloseHandle(hdl)
            except:
                pass

    def __enter__(self):
        return self

    def __exit__(self, *args):
        self.SaveWorkbook()
        self.Close()

#    def __del__(self):  # Destructor
#        # delete all references in right order
#         del self.__worksheet
#         del self.__workbook
#         del self.__app

# Workbook Functions ----------------------------------------------------------
    def get_data(self, row_from, col_from, worksheet_name=None, row_to=None,
                 col_to=None, all_data=False):
        """
        Get data

        :param worksheet_name:  name of worksheet, default(Current Sheet)
        :param row_from:        Upper row   of a range or a single cell
        :param col_from:        Left column of a range or a single cell
        :param row_to:          Bottom row of range , optional (default) for 1 cell
        :param col_to:          Right Column of range, optional (default) for 1 cell
        :param all_data:        if True selection of all data in sheet

        :return:                Tupel of row-tupels
                                (('R1C1','R1C2',..),('R2C1','R2C2',..),..)

        :author:                kuberad
        """
        # check worksheet
        if worksheet_name is None:
            # use current
            pass
        else:
            try:
                self.__workbook.Worksheets(worksheet_name)
            except com_error:
                raise StandardError('Error: worksheet does not exist : %s !!' % str(worksheet_name))
        self.__worksheet = self.__workbook.Worksheets(worksheet_name)

        # adaption for single rows/cols
        if row_to is None:
            row_to = row_from
        if col_to is None:
            col_to = col_from

        if all_data:
            row_from, col_from = 1, 1
            row_to, col_to = self.get_last_cell()

        return self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                      self.__worksheet.Cells(row_to, col_to)).Value

    def merge_cells(self, tbl_idx):
        tbl_obj = self.__internal_get_table(tbl_idx)
        cell = self.__internal_get_table_cell(tbl_obj, 1, 1)
        cell.Merge(self.__internal_get_table_cell(tbl_obj, 2, 1))

    def set_format(self, row_from, col_from, worksheet_name=None, row_to=None,
                   col_to=None, regular=False, italic=False, bold=False,
                   underline=False, font_name=None, font_color=None,
                   cell_color=None, font_size=None, orientation=None,
                   h_align=None, v_align=None, category=None, col_width=None,
                   wrap_text=False, auto_filter=False):
        """
        Set format of a cell or a range. ROWs are given as numbers 1,2,...
        Columns can be either numbers or chars "A","B",...

        :param worksheet_name:  name of worksheet, default(Current Sheet)
        :param row_from:        Upper row   of a range or a single cell
        :param col_from:        Left column of a range or a single cell
        :param row_to:          Bottom row of range , False(default) for 1 cell
        :param col_to:          Right Column of range, False(default) for 1 cell
        :param regular:         True, False(default)
        :param italic:          True, False(default)
        :param bold:            True, False(default)
        :param underline:       True, False(default)
        :param font_name:       "Arial", "Times New Roman", ...
        :param font_color:      "Black", "Red", ... s.COLOR_MAP, "Standard"(default)
        :param cell_color:      s. font_color
        :param font_size:       8,9,...
        :param orientation:     orientation in degree,   0(default)
        :param h_align:         "Left","Center","Right"
        :param v_align:         "Bottom","Center","Top"
        :param category:        "@" Text Format, "0.00" Number Format
        :param col_width:       column width or "AUTO_FIT"
        :param wrap_text:       True, False(default)
        :param auto_filter:     AutoFilter, False(default)  only use for 1 row!

        :author:                kuberad
        """
        if worksheet_name is None:
            # use current
            pass
        else:
            try:
                self.__workbook.Worksheets(worksheet_name)
            except com_error:
                raise StandardError('Error: worksheet does not exist : %s !!' % str(worksheet_name))

        d_alignment_vert = {"Bottom": VERTICAL_ALIGNMENT_BOTOM,
                            "Center": VERTICAL_ALIGNMENT_CENTER,
                            "Top": VERTICAL_ALIGNMENT_TOP}

        d_alignment_hor = {"Left": HORIZONTAL_ALIGNMENT_LEFT,
                           "Center": HORIZONTAL_ALIGNMENT_CENTER,
                           "Right": HORIZONTAL_ALIGNMENT_RIGHT}

        # check for valid input
        if font_color is not None and font_color not in COLOR_MAP:
            print " %s is not in COLOR_MAP!" % str(font_color)

        if cell_color is not None and cell_color not in COLOR_MAP:
            print " %s is not in COLOR_MAP!" % str(cell_color)

        if v_align is not None and v_align not in d_alignment_vert.keys():
            print " %s is invalid input for v_align!" % str(v_align)

        if h_align is not None and h_align not in d_alignment_hor.keys():
            print " %s is invalid input for h_align!" % str(h_align)

        # adaption for single rows/cols
        if row_to is None:
            row_to = row_from
        if col_to is None:
            col_to = col_from
        # formatting ...
        if v_align in d_alignment_vert.keys():
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).VerticalAlignment = \
                d_alignment_vert[v_align]
        if h_align in d_alignment_hor.keys():
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).HorizontalAlignment = \
                d_alignment_hor[h_align]
        if regular is True:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.FontStyle = "Regular"
        if bold is True:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.Bold = True
        if italic is True:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.Italic = True
        if underline is True:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.Underline = True
        if font_name is not None:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.Name = font_name
        if font_color in COLOR_MAP:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.ColorIndex = COLOR_MAP[font_color]
        if cell_color in COLOR_MAP:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Interior.ColorIndex = COLOR_MAP[cell_color]
        if category is not None:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).NumberFormat = category
        if font_size is not None:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Font.Size = font_size
        if orientation is not None:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Orientation = orientation
        if col_width is not None and col_width == "AUTO_FIT":
            self.__worksheet.Range(self.__worksheet.Columns(col_from),
                                   self.__worksheet.Columns(col_to)).EntireColumn.AutoFit()

        if col_width is not None and type(col_width) in [types.IntType, types.LongType, types.FloatType]:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).ColumnWidth = col_width
        if wrap_text is True:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).WrapText = True
        if auto_filter is True:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).AutoFilter()

    def set_data(self, data, row_from, col_from, ws_name=None,
                 empty_value="'-", f_regular=False, f_italic=False,
                 f_bold=False, f_underline=False, f_font_name=None,
                 f_font_color=None, f_cell_color=None, f_font_size=None,
                 f_orientation=None, f_h_align=None, f_v_align=None,
                 f_category=None, f_col_width=None, f_wrap_text=False,
                 f_auto_filter=False):
        """
        Flexible Set Data Function.

        Sets data to 1 cell or a range regarding size of data.
        Data is either a single value or string or a list of lists of rows

        Sets also format if specified.
        ROWs are given as numbers 1,2,... Columns can be either numbers or chars "A","B",...

        :param ws_name:         name of worksheet, default(Current Sheet)
        :param data:            data to write, list of rows [[r1col1,r1col2,...],[r2col1,r2col2,...]]
        :param empty_value:     fills inconsitent matrices with this value, '-'(default)

        :param row_from:        Upper row   of a range or a single cell
        :param col_from:        Left column of a range or a single cell
        :param f_regular:       True, False(default)
        :param f_italic:        True, False(default)
        :param f_bold:          True, False(default)
        :param f_underline:     True, False(default)
        :param f_font_name:     "Arial", "Times New Roman", ...
        :param f_font_color:    "Black", "Red", ... s.COLOR_MAP, "Standard"(default)
        :param f_cell_color:    s. font_color
        :param f_font_size:     8,9,...
        :param f_orientation:   orientation in degree,   0(default)
        :param f_h_align:       "Left","Center","Right"
        :param f_v_align:       "Bottom","Center","Top"
        :param f_category:      "@" Text Format, "0.00" Number Format
        :param f_col_width:     column width or "AUTO_FIT"
        :param f_wrap_text:     True, False(default)
        :param auto_filter:     AutoFilter, False(default)  only use for 1 row!

        :author:                kuberad
        """
        if ws_name is None:
            # use current
            pass
        elif ws_name in self.get_work_sheet_names():
            # select if already there
            self.__worksheet = self.__workbook.Worksheets(ws_name)
        else:
            # name not existent -> create new sheet
            self.__worksheet = self.__workbook.Worksheets.Add()
            self.__worksheet.Name = ws_name

        if row_from <= 0 or col_from <= 0:
            raise StandardError('Error: wrong indexing (%s, %s)! start with 1!!' % (str(row_from), str(col_from)))
        if data is None:
            raise StandardError('Error: data is None to write into excel!! ')
        elif type(data) in [types.IntType, types.LongType, types.FloatType, types.StringType]:
            # single data
            data = [[data]]
        elif isinstance(data, list):
            # a list ... is it a list of lists?
            if len(data) > 0:
                if isinstance(data[0], list):
                    # list of rows --> everythings OK ... perhaps
                    pass
                else:
                    # 1 list ... 1 row
                    data = [data]
            else:
                # empty list
                raise StandardError('Error: empty data !!')
        else:
            raise StandardError('Error: unsupported data type: single value, 1 list for row or list of rows !!')

        if empty_value is not None:
            # check and fill empty cells
            # determine max row len
            max_row_len = 0
            for row in data:
                if row is not None:
                    max_row_len = max(max_row_len, len(row))
            # check for empty cells
            for i in range(len(data)):
                for v in range(len(data[i])):
                    if data[i][v] is None:
                        data[i][v] = empty_value
                    elif data[i][v] == []:
                        data[i][v] = empty_value
                delta = max_row_len - len(data[i])
                while delta > 0:
                    data[i].append(empty_value)
                    delta -= 1
            col_TO = col_from + max_row_len - 1
        else:
            col_TO = col_from + len(data[0]) - 1
        row_TO = row_from + len(data) - 1
        self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                               self.__worksheet.Cells(row_TO, col_TO)).Value = data

        if(f_regular is False and f_italic is False and f_bold is False and
           f_underline is False and f_font_name is None and
           f_font_color is None and f_cell_color is None and
           f_font_size is None and f_orientation is None and
           f_h_align is None and f_v_align is None and f_category is None and
           f_col_width is None and f_wrap_text is False and
           f_auto_filter is False):
            # nothing to format ...
            pass
        else:
            self.set_format(row_from, col_from, worksheet_name=ws_name,
                            row_to=row_TO,
                            col_to=col_TO,
                            regular=f_regular,
                            italic=f_italic,
                            bold=f_bold,
                            underline=f_underline,
                            font_name=f_font_name,
                            font_color=f_font_color,
                            cell_color=f_cell_color,
                            font_size=f_font_size,
                            orientation=f_orientation,
                            h_align=f_h_align,
                            v_align=f_v_align,
                            category=f_category,
                            col_width=f_col_width,
                            wrap_text=f_wrap_text,
                            auto_filter=f_auto_filter)

    def OpenWorkbook(self, FilePath):
        """
        Open the specified excel file

        :param FilePath:   FilePath
        :author:           Robert Hecker
        """
        self.CloseWorkbook()
        self.__workbook = self.__app.Workbooks.Open(FilePath)

        return self.__workbook is not None

    def CreateWorkbook(self):
        """
        Create an excel file

        :author:           Robert Hecker
        """
        self.CloseWorkbook()
        self.__workbook = self.__app.Workbooks.Add()

        if self.__workbook is not None:
            return True
        else:
            return False

    def CloseWorkbook(self):
        """
        Close excel file
        :author:           Robert Hecker
        """
        if self.__workbook is not None:
            self.__worksheet = None
            self.__workbook.Close()
            del self.__workbook
            self.__workbook = None

    def SaveWorkbook(self, name=None):
        """
        Save opened excel file

        :param         name - if no name given like parameter -> Save
                            - if name parameter -> SaveAs - save excel file
                              with specified name
        :author:           Robert Hecker
        """
        if name is not None:
            self.__workbook.SaveAs(name)
        else:
            self.__workbook.Save()

# Worksheet Functions ------------------------------------------------------

    def CreateWorksheet(self, name):
        """
        Create sheet in the opened excel file

        :param         name - the new worksheet name
        :author:           Robert Hecker
        """
        self.__worksheet = self.__workbook.Worksheets.Add()
        self.__worksheet.Name = name

        if self.__worksheet is not None:
            return True
        else:
            return False

    def SelectWorksheet(self, name):
        """
        Select a sheet for the next operations to be made in

        :param          name - the name of the worksheet to work with
        :author:           Robert Hecker
        """
        self.__worksheet = self.__workbook.Worksheets(name)

        if self.__worksheet is not None:
            return True
        else:
            return False

    def DeleteWorksheet(self, name):
        """
        Delete the specified Worksheet

        :param         name
        :author:           Nicoara Maria
        """
        self.__app.DisplayAlerts = False
        self.__workbook.Worksheets(name).Delete()

    def CountWorksheets(self):
        """
        Count the worksheets of the current excel file

        :return:           the number of worksheets
        :author:           Nicoara Maria
        """
        return self.__workbook.Worksheets.Count

    def get_work_sheet_names(self):
        """
        Get all worksheets names of the current excel file

        :return:        list with worksheed names
        :author:        Anne Skerl
        """
        worksheetnames = []
        worksheetcount = self.CountWorksheets()
        for index in range(1, worksheetcount + 1):
            worksheetnames.append(self.__workbook.Worksheets(index).Name)
        return worksheetnames

# Attributes ---------------------------------------------------------------
    def Visible(self, bVisible):
        """
        Make excel visible
        :author:        Robert Hecker
        """
        self.__app.visible = bVisible

# Data I/O -----------------------------------------------------------------
    def get_last_cell(self, ws_name=None):
        """
        Get row and column index of last Cell

        :param ws_name: (otional) work sheet name
        :return:        lastrow, lastcol

        :author:        Anne Skerl
        """
        # check worksheet
        if ws_name is None:
            # use current
            pass
        else:
            try:
                self.__workbook.Worksheets(ws_name)
            except com_error:
                raise StandardError('Error: worksheet does not exist : %s !!' % str(ws_name))
            self.__worksheet = self.__workbook.Worksheets(ws_name)
        lastrow = self.__worksheet.UsedRange.Rows.Count
        lastcol = self.__worksheet.UsedRange.Columns.Count
        return lastrow, lastcol

    def SetCellValue(self, row, col, value):
        """
        Set the specified Cell with an Value row and col could be integer or
        string for example "A", 'A' or 1

        :return:        value
        :author:        Robert Hecker
        """
        self.__worksheet.Cells(row, col).Value = value

    def GetCellValue(self, row, col):
        """
        Get the specified Cell value. Row and col could be integer
        or string for example "A", 'A' or 1

        :return:        value
        :author:        Robert Hecker
        """
        return self.__worksheet.Cells(row, col).Value

    def SetRangeValues(self, worksheet_name, row_from, col_from, values, empty_value="'-"):
        """
        Set the specified cells range values.
        row_from and col_from could be integer or string, for example "A", 'A' or 1

        :param worksheet_name:   name of the excel worksheet
        :param row_from:         row number (integer data type)
        :param col_from:         column number (integer data type)
        :param empty_value:      when None no consistency check, otherwise fill empty cell with this value
        :param values:           is a tuple of tuples
                                 Each tuple corresponds to a row in excel sheet
        :author:                 Nicoara Maria
        """
        if empty_value is not None:
            # check and fill empty cells
            # determine max row len
            max_row_len = 0
            for row in values:
                if row is not None:
                    max_row_len = max(max_row_len, len(row))
            # check for empty cells
            for i in range(len(values)):
                for v in range(len(values[i])):
                    if values[i][v] is None:
                        values[i][v] = empty_value
                    elif values[i][v] == []:
                        values[i][v] = empty_value
                delta = max_row_len - len(values[i])
                while delta > 0:
                    values[i].append(empty_value)
                    delta -= 1
            col_to = col_from + max_row_len - 1
        else:
            col_to = col_from + len(values[0]) - 1
        row_to = row_from + len(values) - 1
        self.__worksheet = self.__workbook.Worksheets(worksheet_name)
        self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                               self.__worksheet.Cells(row_to, col_to)).Value = values

    def GetRangeValues(self, worksheet_name, range_address):
        """
        Return the specified cells range values

        :param worksheet_name:   name of the excel worksheet
        :param range_address:    rangeAddress,
                                 tuple of integers (row1,col1,row2,col2) or
                                 "cell1Address:cell2Address"
                                 row1,col1 refers to first cell(left upper corner)
                                 row2,col2 refers to second cell(right botom corner)
                                  e.g. (1,2,5,7) or "B1:G5"
        :author:                 Nicoara Maria
        """
        self.__worksheet = self.__workbook.Worksheets(worksheet_name)
        if (isinstance(range_address, str)):
            return self.__worksheet.Range(range_address).Value
        elif (isinstance(range_address, tuple)):
            row1 = range_address[0]
            col1 = range_address[1]
            row2 = range_address[2]
            col2 = range_address[3]
            return self.__worksheet.Range(self.__worksheet.Cells(row1, col1), self.__worksheet.Cells(row2, col2)).Value

    def DeleteCellContent(self, row, col):
        """
        Delete the specified cell content -> empty cell
        row and col could be integer or string, for example "A", 'A' or 1

        :author:                 Nicoara Maria
        """
        self.__worksheet.Cells(row, col).ClearContents()

    def DeleteRangeContent(self, row_from, col_from, row_to, col_to):
        """
        Delete the specified range content  -> empty range cell
        row and col could be integer or string, for example "A", 'A' or 1

        :author:                 Nicoara Maria
        """
        self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                               self.__worksheet.Cells(row_to, col_to)).ClearContents()

# Format -----------------------------------------------------------------
    def SetCellFontStyle(self, row, col, regular=True, bold=False,
                         italic=False, underline=False):
        """
        Set the Font style of the specified Cell to Bold, Italic, Underline or Regular
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         regular  - the font style will be regular by default
        :param         bold          = False, by default
        :param         italic        = False, by default
        :param         underline     = False, by default

        :author:           Nicoara Maria
        """
        if regular is True:
            self.__worksheet.Cells(row, col).Font.FontStyle = "Regular"

        if bold is True:
            self.__worksheet.Cells(row, col).Font.Bold = True

        if italic is True:
            self.__worksheet.Cells(row, col).Font.Italic = True

        if underline is True:
            self.__worksheet.Cells(row, col).Font.Underline = True

    def SetCellCategory(self, row, col, category):
        """
        Set the cell category of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         Category - can be for example "@" for Text Format or
                                     "0.00" for Number Format
        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(row, col).NumberFormat = category

    def SetCellFontName(self, row, col, font_name):
        """
        Set the Font name of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         fontName - can be for example "Arial" or "Times New Roman"
        :author:       Nicoara Maria
        """
        self.__worksheet.Cells(row, col).Font.Name = font_name

    def SetCellFontColor(self, row, col, font_color):
        """
        Set the Font name of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         font_color - can be for example 'Red' or  self.FONT_COLOR_RED

        :author:           Nicoara Maria
        """
        # For choosing the right color see the COLOR_MAP
        if font_color in COLOR_MAP:
            self.__worksheet.Cells(row, col).Font.ColorIndex = COLOR_MAP[font_color]
        else:
            print (" %s is not a valid color, for more details see the COLOR_MAP defined in stk_excel module" %
                   str(font_color))

    def SetCharactersColor(self, row, col, char_idx_start, char_idx_stop, font_color):
        """
        Set the color of specified charactersfrom the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         char_idx_start- the starting position of the string you
                          want to change the color of
        :param         char_idx_stop- the end position of the string you
                          want to change the color of
        :param         font_color - can be for example 'Red' or self.FONT_COLOR_RED

        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(row, col).GetCharacters(char_idx_start, char_idx_stop).Font.ColorIndex = font_color

    def SetCellFontSize(self, row, col, font_size):
        """
        Set the Font size of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         fontSize - can be a number

        :author:           Nicoara Maria
        """

        self.__worksheet.Cells(row, col).Font.Size = font_size

    def SetCellTextOrientation(self, row, col, degrees):
        """
        Set the text orientation of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         degrees - can be a number
                          for example 90 -> text will be written vertical

        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(row, col).Orientation = degrees

    def MergeCells(self, row_from, column_from, row_to, colum_to):
        self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                               self.__worksheet.Cells(row_to, colum_to)).MergeCells = True
        """
        Merge the range of the specified cells
        The row_from, column_from, row_to, colum_to could be integer or string
        for example "A", 'A' or 1

        :param         row_from
        :param         column_from
                          - The first cell from the selection
        :param         row_to
        :param         col_to
                          - The last cell from the selection

        :author:           Nicoara Maria
        """

        """
        Set the vertical alignment of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         alignment -
                          can take the fallowing values: "Botom", "Center" or "Top"

        :author:           Nicoara Maria
        """
    def SetVerticalCellAlign(self, row, col, alignment):
        """
        Set the vertical alignment of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         alignment -
                          can take the fallowing values: "Botom", "Center" or "Top"

        :author:           Nicoara Maria
        """
        if (alignment == "Botom"):
            self.__worksheet.Cells(row, col).VerticalAlignment = VERTICAL_ALIGNMENT_BOTOM
        elif (alignment == "Center"):
            self.__worksheet.Cells(row, col).VerticalAlignment = VERTICAL_ALIGNMENT_CENTER
        elif (alignment == "Top"):
            self.__worksheet.Cells(row, col).VerticalAlignment = VERTICAL_ALIGNMENT_TOP

    def SetHorizontalCellAlign(self, row, col, alignment):
        """
        Set the horizontal alignment of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         alignment -
                          can take the fallowing values: "Left", "Center" or "Right"

        :author:           Nicoara Maria
        """
        if (alignment == "Left"):
            self.__worksheet.Cells(row, col).Horizontal_Alignment = HORIZONTAL_ALIGNMENT_LEFT
        elif (alignment == "Center"):
            self.__worksheet.Cells(row, col).HorizontalAlignment = HORIZONTAL_ALIGNMENT_CENTER
        elif (alignment == "Right"):
            self.__worksheet.Cells(row, col).HorizontalAlignment = HORIZONTAL_ALIGNMENT_RIGHT

    def SetAutoFitColumns(self, column):
        """
        Set autofit of the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         column

        :author:           Nicoara Maria
        """
        self.__worksheet.Columns(column).EntireColumn.AutoFit()

    def InsertHyperlink(self, row, col, hyperlink, text):
        """
        Insert a hyperlink in the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         hyperlink - the link, for e.g. "www.google.ro"
                          or "O:\\Li\\"
        :param         text - the text that will be displayed in the cell, e.g. "google link"

        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(row, col).Hyperlinks.Add(self.__worksheet.Cells(row, col), hyperlink, "", text, text)

    def SetCellColor(self, row_from, col_from, row_to, col_to, color):
        """
        Set the color of the specified Cell
        The row_from/row_to and col_from/row_to could be integer or string
        for example "A", 'A' or 1

        :param         row_from
        :param         col_from
        :param         row_to
        :param         col_to
        :param         color - can be a string that represents a color
                          for example 'Red' or 'Yellow' or self.FONT_COLOR_RED

        :author:           Nicoara Maria
        """
        # For choosing the right color see the COLOR_MAP
        if color in COLOR_MAP:
            self.__worksheet.Range(self.__worksheet.Cells(row_from, col_from),
                                   self.__worksheet.Cells(row_to, col_to)).Interior.ColorIndex = COLOR_MAP[color]
        else:
            print "%s is not a valid color, for more details see the COLOR_MAP defined in stk_excel module" % color

    def SetCellWrapText(self, row, col):
        """
        Wrap text in the specified Cell
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col


        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(row, col).WrapText = True

    def SetColumnWidth(self, row, col, new_width):
        """
        Set the width of the column that the specified cell is a part of
        The row and col could be integer or string
        for example "A", 'A' or 1

        :param         row
        :param         col
        :param         new_width - is a number that specifies the width of the column

        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(row, col).ColumnWidth = new_width

    def SetCellsBorders(self, row_from, column_from, row_to, colum_to, line_width):
        """
        Set the borders of the specified range(selection) of cells
        The row_from, column_from, row_to, colum_to could be integer or string
        for example "A", 'A' or 1

        :param         row_from
        :param         column_from
                          - The first cell from the selection
        :param         row_to
        :param         col_to
                          - The last cell from the selection
        :param         line_width - takes values in [1,4]interval
                          2 - continuous line

        :author:           Nicoara Maria
        """
        # if there are no inside horizontal borders to set
        if row_from == row_to:
            for cnt in BORDERS_MAP[:-1]:
                self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                                       self.__worksheet.Cells(row_to, colum_to)). \
                    Borders(cnt).LineStyle = CONTINUOUS_BORDER
                self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                                       self.__worksheet.Cells(row_to, colum_to)). \
                    Borders(cnt).Weight = line_width
        # if there are no inside vertical borders to set
        elif column_from == colum_to:
            for cnt in BORDERS_MAP[:4] + [BORDERS_MAP[-1]]:
                self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                                       self.__worksheet.Cells(row_to, colum_to)). \
                    Borders(cnt).LineStyle = CONTINUOUS_BORDER
                self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                                       self.__worksheet.Cells(row_to, colum_to)). \
                    Borders(cnt).Weight = line_width

        else:
            for cnt in BORDERS_MAP:
                self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                                       self.__worksheet.Cells(row_to, colum_to)).Borders(cnt). \
                    LineStyle = CONTINUOUS_BORDER
                self.__worksheet.Range(self.__worksheet.Cells(row_from, column_from),
                                       self.__worksheet.Cells(row_to, colum_to)). \
                    Borders(cnt).Weight = line_width

    def SetDataAutofilter(self, col):
        """
        Insert filter in the specified Cell
        The col could be integer or string
        for example "A", 'A' or 1

        :param         col

        :author:           Nicoara Maria
        """
        self.__worksheet.Cells(col).AutoFilter()

    def InsertChart(self, sheet_name, num=1, left=10, width=600, top=50, height=450, chart_type=-4169):
        """
        Insert a chart
        :author:           Nicoara Maria
        """
        try:
            self.SelectWorksheet(sheet_name)
        except:  # sheet doesn't exist so create it
            self.CreateWorksheet(sheet_name)
        try:
            self.__workbook.Sheets(sheet_name).ChartObjects(num).Activate  # already exists
        except:
            self.xlChart = self.__workbook.Sheets(sheet_name).ChartObjects().Add(Left=left, Width=width,
                                                                                 Top=top, Height=height)
            self.xlChart.Chart.ChartType = chart_type

    def AddXYChartSeries(self, sheet, topRow, bottomRow, xCol, yCol,
                         series_name="", chart_sheet="", chart_num=1,
                         color=1, style='line', title="", xlabel="", ylabel="",
                         errorbars=None):
        if not chart_sheet:
            chart_sheet = sheet

        # series properties
        sht = self.__workbook.Worksheets(sheet)
        se = self.xlChart.Chart.SeriesCollection().NewSeries()
        se.Values = sht.Range(sht.Cells(topRow, yCol),
                              sht.Cells(bottomRow, yCol))
        se.XValues = sht.Range(sht.Cells(topRow, xCol), sht.Cells(bottomRow, xCol))
        if series_name:
            se.Name = series_name
        if style == 'line':
            # line style
            se.MarkerStyle = constants.xlNone
            se.Border.ColorIndex = color
            se.Border.Weight = constants.xlHairline
            se.Border.LineStyle = constants.xlContinuous
            se.Border.Weight = constants.xlMedium
        if style == 'point':
            # point style
            # se.MarkerBackgroundColorIndex = constants.xlNone
            # se.MarkerForegroundColorIndex = color
            se.MarkerBackgroundColorIndex = color
            se.MarkerForegroundColorIndex = 1  # black
            # se.MarkerStyle = constants.xlMarkerStyleCircle
            se.MarkerStyle = constants.xlMarkerStyleSquare
            se.MarkerSize = 5
        # Chart properties
        cht = self.xlBook.Sheets(chart_sheet).ChartObjects(chart_num).Chart
        # Chart Title
        if title:
            cht.HasTitle = True
            cht.ChartTitle.Caption = title
            cht.ChartTitle.Font.Name = 'Arial'
            cht.ChartTitle.Font.Size = 10
            cht.ChartTitle.Font.Bold = False
        # X axis labels
        if xlabel:
            cht.Axes(constants.xlCategory).HasTitle = True
            cht.Axes(constants.xlCategory).AxisTitle.Caption = xlabel
            cht.Axes(constants.xlCategory).AxisTitle.Font.Name = 'Arial'
            cht.Axes(constants.xlCategory).AxisTitle.Font.Size = 10
            cht.Axes(constants.xlCategory).AxisTitle.Font.Bold = False
            cht.Axes(constants.xlCategory).MinimumScale = 0
            cht.Axes(constants.xlCategory).MaximumScaleIsAuto = True
        # Y axis labels
        if ylabel:
            cht.Axes(constants.xlValue).HasTitle = True
            cht.Axes(constants.xlValue).AxisTitle.Caption = ylabel
            cht.Axes(constants.xlValue).AxisTitle.Font.Name = 'Arial'
            cht.Axes(constants.xlValue).AxisTitle.Font.Size = 10
            cht.Axes(constants.xlValue).AxisTitle.Font.Bold = False
            cht.Axes(constants.xlValue).MinimumScale = 0
            cht.Axes(constants.xlValue).MaximumScaleIsAuto = True

        if errorbars is not None:
            amount = "".join(["=", chart_sheet, "!",
                              "R",
                              str(errorbars['amount'][0]),
                              "C",
                              str(errorbars['amount'][2]),
                              ":",
                              "R",
                              str(errorbars['amount'][1]),
                              "C",
                              str(errorbars['amount'][2])])

            se.ErrorBar(Direction=constants.xlY,
                        Include=constants.xlErrorBarIncludeBoth,
                        Type=constants.xlErrorBarTypeCustom,
                        Amount=amount, MinusValues=amount)

            se.ErrorBars.EndStyle = constants.xlNoCap
            se.ErrorBars.Border.LineStyle = constants.xlContinuous
            se.ErrorBars.Border.ColorIndex = color
            se.ErrorBars.Border.Weight = constants.xlHairline

    def InsertPictureFromFile(self, file_path, left=0, top=0, width=350, height=300):
        """
        Insert a picture from the specified file

        :param        file_path
        :param        left - how far from the left of the window
        :param        top - how far from the top of the window
        :param        width  - image width
        :param        height - image height

        :author:           Nicoara Maria
        """
        self.__worksheet.Shapes.AddPicture(file_path, 1, 1, left, top, width, height)

"""
CHANGE LOG:
-----------
$Log: excel.py  $
Revision 1.1 2021/12/13 17:59:02CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/project.pj
Revision 1.17 2013/11/25 10:04:36CET Mertens, Sven (uidv7805) 
removing some pylints and pep8 finally
- Added comments -  uidv7805 [Nov 25, 2013 10:04:37 AM CET]
Change Package : 207693:3 http://mks-psad:7002/im/viewissue?selection=207693
Revision 1.16 2013/11/25 09:36:39CET Mertens, Sven (uidv7805)
prevent del being called when close method was used
--- Added comments ---  uidv7805 [Nov 25, 2013 9:36:39 AM CET]
Change Package : 207693:2 http://mks-psad:7002/im/viewissue?selection=207693
Revision 1.15 2013/11/22 13:18:56CET Mertens, Sven (uidv7805)
adding with statement support,
removing Excel app shutdown problem
--- Added comments ---  uidv7805 [Nov 22, 2013 1:18:56 PM CET]
Change Package : 207693:1 http://mks-psad:7002/im/viewissue?selection=207693
Revision 1.14 2013/09/06 10:52:39CEST Mertens, Sven (uidv7805)
removing my own changes as agreeded
--- Added comments ---  uidv7805 [Sep 6, 2013 10:52:40 AM CEST]
Change Package : 196367:2 http://mks-psad:7002/im/viewissue?selection=196367
Revision 1.13 2013/08/02 14:36:55CEST Mertens, Sven (uidv7805)
when using integer, start index is 0,
when using strings it aligns with Excel's own
--- Added comments ---  uidv7805 [Aug 2, 2013 2:36:55 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.12 2013/07/17 09:29:35CEST Mertens, Sven (uidv7805)
replacing isinstance as of stepping over while bugfixing
--- Added comments ---  uidv7805 [Jul 17, 2013 9:29:36 AM CEST]
Change Package : 185933:2 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.11 2013/06/26 09:34:23CEST Mertens, Sven (uidv7805)
fix: colorizing index wrong, counting one more was wrong
--- Added comments ---  uidv7805 [Jun 26, 2013 9:34:23 AM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.10 2013/06/24 13:31:43CEST Mertens, Sven (uidv7805)
worksheet methods don't take over integers as column index by default, therefore
there is a need to transfer those into base26. Adaptation of all realted methdos needed.
--- Added comments ---  uidv7805 [Jun 24, 2013 1:31:43 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.9 2013/04/03 08:17:14CEST Mertens, Sven (uidv7805)
pep8: removing format errors
--- Added comments ---  uidv7805 [Apr 3, 2013 8:17:14 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/04/03 08:02:12CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:13 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/02/28 17:07:23CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Feb 28, 2013 5:07:23 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/28 08:12:12CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:13 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 17:55:10CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:10 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/26 18:05:54CET Hecker, Robert (heckerr)
Some modifications to get current Unittest working.
--- Added comments ---  heckerr [Feb 26, 2013 6:05:55 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/20 08:21:52CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:52 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/18 10:30:55CET Paulig, Ralf (uidt3509)
Merged fix for open excel.exe from old STK.
--- Added comments ---  uidt3509 [Feb 18, 2013 10:30:57 AM CET]
Change Package : 175382:1 http://mks-psad:7002/im/viewissue?selection=175382
Revision 1.1 2013/02/12 16:13:28CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm
/STK_ScriptingToolKit/04_Engineering/stk/rep/project.pj
Revision 1.12 2012/05/02 09:02:00CEST Mogos, Sorin (mogoss)
* update: added merge_cells method
--- Added comments ---  mogoss [May 2, 2012 9:02:05 AM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.11 2012/02/22 10:26:04CET Mogos, Sorin (mogoss)
* small bug-fix
--- Added comments ---  mogoss [Feb 22, 2012 10:26:13 AM CET]
Change Package : 89706:1 http://mks-psad:7002/im/viewissue?selection=89706
Revision 1.10 2010/05/17 15:00:03CEST dkubera
generic read get_data added
get_last_cell extended with optional worksheet parameter
--- Added comments ---  dkubera [2010/05/17 13:00:03Z]
Change Package : 39727:3 http://LISS014:6001/im/viewissue?selection=39727
Revision 1.9 2010/05/07 12:20:33CEST dkubera
interface change for set_data and set_format
- set_format: optional worksheet name, default current
- set_data: optional worksheet name, default current, when given write into existing or create new sheet
--- Added comments ---  dkubera [2010/05/07 10:20:34Z]
Change Package : 32862:6 http://LISS014:6001/im/viewissue?selection=32862
Revision 1.8 2010/05/07 11:18:43CEST dkubera
reworked:
- set_data and set_format functions added for robust and comfortable writing and formatting
- get_work_sheet_names added
- get_last_cell added
- documentation updated regarding guideline
--- Added comments ---  dkubera [2010/05/07 09:18:44Z]
Change Package : 32862:6 http://LISS014:6001/im/viewissue?selection=32862
Revision 1.7 2010/04/08 17:08:25CEST dkubera
Fix for inconsitent data : SetRangeValues fills empty cells instead of doing nothing
header and footer update
--- Added comments ---  dkubera [2010/04/08 15:08:25Z]
Change Package : 33974:4 http://LISS014:6001/im/viewissue?selection=33974
Revision 1.6 2009/11/11 13:54:02CET Sorin Mogos (smogos)
* added new functions
--- Added comments ---  smogos [2009/11/11 12:54:03Z]
Change Package : 33973:1 http://LISS014:6001/im/viewissue?selection=33973
$Add methods $ Nicoara Maria
"""
