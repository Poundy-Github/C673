"""
stk/rep/word
------------

Module to create Reports as Microsoft Word Document.
Library to write and read word Files

:org:           Continental AG
:author:        Ovidiu Raicu,
                Robert Hecker,
                Sorin Mogos

:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:59:04CET $
"""
# Imports ----------------------------------------------------------------------
import win32com.client as wc
from os.path import exists
from pythoncom import CoInitializeEx, CoUninitialize, COINIT_APARTMENTTHREADED  # pylint: disable-msg=E0611

# try:
#     from exceptions import StandardError as _BaseException
# except ImportError:
#     _BaseException = Exception

#===================================================================================
# Constant declarations
#===================================================================================
# FONT color constants used for changing the font color for all font functions
FONT_COLOR = {'Black': 0, 'White': 16777215, 'Red': 255, 'Bright Green': 65280,
              'Blue': 16711680, 'Yellow': 65535, 'Pink': 16711935,
              'Turqoise': 16776960, 'Dark Red': 128, 'Green': 32768,
              'Dark Blue': 8388608, 'Dark Yellow': 32896, 'Violet': 8388736,
              'Teal': 8421376, 'Gray-25%': 12632256, 'Gray-50%': 16,
              'Sky Blue': 16763904, 'Light Turqoise': 16777164,
              'Light Green': 13434828, 'Light Yellow': 10092543,
              'Pale Blue': 16764057, 'Rose': 13408767, 'Lavendar': 16751052,
              'Tan': 10079487, 'Light Blue': 16737843, 'Aqua': 13421619,
              'Lime': 52377, 'Gold': 52479, 'Light Orange': 39423,
              'Orange': 26367, 'Blue-Gray': 10053222, 'Gray-40%': 10066329,
              'Dark Teal': 6697728, 'Sea Green': 6723891, 'Dark Green': 13056,
              'Olive Green': 13107, 'Brown': 13209, 'Plum': 6697881,
              'Indigo': 10040115, 'Gray-80%': 3355443}
# Backround color uses the same constants as font color
BACKROUND_COLOR = FONT_COLOR
# Table autofit behavior
AUTOFIT_BEHAVIOR = {'AutoFitFixed': 0, 'AutoFitContent': 1, 'AutoFitWindow': 2}
# Paragraph alignment
PARAGRAPH_ALINGMENT = {'Left': 0, 'Center': 1, 'Right': 2, 'JustifyHigh': 7,
                       'JustifyLow': 8, 'JustifyMedium': 5}
# Used for shapes and pictures
TEXT_ORIENTATION = {'Downward': 3, 'Horizontal': 1,
                    'HorizontalRotatedFarEast': 6, 'Mixed':-2, 'Upward': 2,
                    'Vertical': 5, 'VerticalFarEast': 4}
# Used for diagrams
DIAGRAM_TYPE = {'Cycle': 2, 'Mixed':-2, 'OrganizationalChart': 1,
                'Pyramid': 4, 'Radial': 3, 'Target': 6, 'Venn': 5}


class WordException(StandardError):
    """
    Exception class for stkWord.
    """
    def __init__(self, description):
        self.__description = str(description)

    def __str__(self):
        errror_description = "\n=====================================================\n"
        errror_description += "ERROR: " + self.__description
        errror_description += "\n=====================================================\n"
        return str(errror_description)

    def Description(self):
        return self.__description

#==============================================================================
# Class declaration
#==============================================================================


class Word(object):
    """stkWord class definition."""
    def __init__(self, create_new_word_instance=False, visible=False):
        """Constructor"""
        self.__create_new_word_instance = create_new_word_instance

        if self.__create_new_word_instance:
            CoInitializeEx(COINIT_APARTMENTTHREADED)
            self.__app = wc.DispatchEx('Word.Application')
        else:
            self.__app = wc.dynamic.Dispatch('Word.Application')

        if visible:
            self.__app.Visible = True
        else:
            self.__app.Visible = False

        self.__document = None
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

        self.FONT_STYLE_NORMAL = "Normal"

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

    def __del__(self):
        """ Destructor. """
        try:
            self.__app.Quit()
        except Exception, errmsg:
            raise WordException("Error while closing MSWord App due to '%s'." % errmsg)

        del self.__document
        del self.__app

        if self.__create_new_word_instance:
            CoUninitialize()

    def create_document(self):
        """Creates a new empty document in word."""
        try:
            self.__document = self.__app.Documents.Add()

        except Exception, errmsg:
            raise WordException("Error while creating document due to '%s'." % errmsg)

    def open_document(self, file_pathname):
        """Opens a new document.

         :param path: The file_pathname to the document.
        """
        if self.is_document_opened() is True:
            raise WordException("A document is already opened.")

        try:
            self.__document = self.__app.Documents.Open(file_pathname, False, False, False)
            self.__document.ShowGrammaticalErrors = False
            self.__document.ShowRevisions = False
            self.__document.ShowSpellingErrors = False
        except Exception, errmsg:
            raise WordException("Error while opening document due to '%s'." % errmsg)

    def get_current_document_path(self):
        """Returns the path to the document currently opened.

        :return:  The path to the document currently opened.

        """
        if self.is_document_opened():
            raise WordException("No document currently opened.")
        else:
            try:
                return self.__document.Path
            except Exception, errmsg:
                raise WordException("Failed to get the current document path due to '%s'." % errmsg)

    def is_document_opened(self):
        """Returns True or False whether there is a document currently opened.

        :return: True or False whether there is a document currently opened.

        """
        if self.__document is None:
            return False
        else:
            return True

    def __internal_get_toc(self, tbl_toc_idx):
        """TODO
        """
        tbl_toc_obj = None
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            try:
                tbl_toc_obj = self.__document.TablesOfContents.Item(tbl_toc_idx)
            except:
                tmp = "The table of contents with the specified index does not "
                tmp += "exist or error occured while accessing it."
                raise WordException(tmp)
        return tbl_toc_obj

    def __internal_get_table(self, table_idx):
        """TODO
        """
        if  self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        if isinstance(table_idx, str):
            return self.__internal_get_table_by_id(table_idx)
        else:
            return self.__internal_get_table_by_idx(table_idx)

    def __internal_get_table_by_idx(self, table_idx):
        """TODO
        """
        if  self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:

            try:
                table = self.__document.Tables.Item(table_idx)
            except Exception, errmsg:
                raise WordException("Error while getting table with %d index due to '%s'." % (table_idx, errmsg))

        return table

    def __internal_get_table_by_id(self, table_id_str):
        """TODO
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            tbl_cnt = self.get_tables_count()
            tbl_cnt += 1
            try:
                for tbl_idx in xrange(1, tbl_cnt + 1):
                    tbl_obj = self.__internal_get_table_by_idx(tbl_idx)
                    if tbl_obj.ID == table_id_str:
                        return tbl_obj
                else:
                    raise WordException("The specified ID does not exist.")
            except:
                tmp = "The specified ID does not exist or an error occured "
                tmp += "while attempting to access table with ID %(table_id)s." % {'table_id': table_id_str}
                raise WordException(tmp)

    def __internal_get_table_cell(self, table_obj, row_idx, col_idx):
        """TODO
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            try:
                return table_obj.Cell(row_idx, col_idx)
            except:
                tmp = "An error occured while attempting to access cell "
                tmp += "[%(col)d X %(row)d]." % {'col': col_idx, 'row': row_idx}
                raise WordException(tmp)

    def __internal_get_table_cell_value(self, table_obj, row_idx, col_idx):
        """TODO
        """
        if  self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        tbl_cell_value = ""
        tbl_cell_obj = self.__internal_get_table_cell(table_obj, row_idx, col_idx)
        try:
            tbl_cell_value = tbl_cell_obj.Range.Text
        except:
            tmp = "The specified index does not exist or an error occured "
            tmp += "while attempting to access the table cell [%(col)d X %(row)d]." % {'col': col_idx, 'row': row_idx}
            raise WordException(tmp)
        return str(tbl_cell_value).rstrip("\r\007")

    def __internal_get_table_row(self, tbl_obj, row_idx):
        """TODO
        """
        if  self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            try:
                tbl_row_obj = tbl_obj.Rows(row_idx)
            except:
                tmp = "The specified index does not exist or an error occured "
                tmp += "while attempting to access the table row %(row)d ." % {'row': row_idx}
                raise WordException(tmp)
            return tbl_row_obj

    def __internal_get_table_column(self, tbl_obj, col_idx):
        """TODO
        """
        if  self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            try:
                tbl_col_obj = tbl_obj.Columns(col_idx)
            except:
                tmp = "The specified index does not exist or an error occured "
                tmp += "while attempting to access the table column %(row)d ." % {'row': col_idx}
                raise WordException(tmp)
            return tbl_col_obj

    def __internal_set_table_cell_value(self, tbl_obj, col_idx, row_idx, value):
        """TODO
        """
        if  self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            try:
                cell = None
                cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
                if cell is None:
                    return False
                else:
                    cell.Range.Text = value
            except:
                tmp = "The specified index does not exist or an error occured "
                tmp += "while attempting to access the table cell "
                tmp += "[%(col)d X %(row)d]." % {'col': col_idx, 'row': row_idx}
                raise WordException(tmp)
            return True

    def __internal_set_table_data(self, tbl_obj, col_cnt, row_cnt, data):
        """TODO
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            for row in xrange(row_cnt):
                for col in xrange(col_cnt):
                    if self.__internal_set_table_cell_value(tbl_obj, col + 1, row + 1, data[row][col]) is False:
                        return False
            return True

    def __internal_get_hyperlink(self, hyperlink_idx):
        """TODO
        """
        hyperlink_obj = None
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        else:
            try:
                hyperlink_obj = self.__document.Hyperlinks.Item(hyperlink_idx)
            except:
                tmp = "The hyperlink with the specified index does not exist or error occured while accesing it."
                raise WordException(tmp)
        return hyperlink_obj

    def  __internal_resize_table(self, tbl_idx, new_col_cnt, new_row_cnt):
        """TODO
        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_dim = self.get_table_dimensions(tbl_idx)
        tbl_row_cnt = tbl_dim[0]
        tbl_col_cnt = tbl_dim[1]
        try:
            if tbl_row_cnt < new_row_cnt:
                for _ in range(new_row_cnt - tbl_row_cnt):
                    tbl_obj.Rows.Add()
            if tbl_col_cnt < new_col_cnt:
                for _ in range(new_col_cnt - tbl_col_cnt):
                    tbl_obj.Columns.Add()
        except:
            raise WordException("Failed to resize table.")

    def __internal_alignment_to_string(self, alignment_idx):
        """TODO
        """
        idx = 0
        for alignment_id in PARAGRAPH_ALINGMENT.values():
            if alignment_id == alignment_idx:
                return PARAGRAPH_ALINGMENT.keys()[idx]
            else:
                idx += 1
        return "Unknown"

    def __internal_get_shape_by_id(self, shape_id):
        """TODO
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        shape_cnt = self.get_shapes_count()
        shape_cnt += 1
        try:
            for shape_idx in xrange(1, shape_cnt + 1):
                shape_obj = self.__document.Shapes.Item(shape_idx)
                if shape_obj.ID == shape_id:
                    return shape_obj
            else:
                return None
        except:
            tmp = "An error occured while searching document for shape with ID %(id_str)s" % {'id_str': shape_id}
            raise WordException(tmp)

    def __internal_get_shape_by_idx(self, shape_idx):
        """TODO
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            return self.__document.Shapes.Item(shape_idx)
        except:
            tmp = "An error occured while searching document for shape with index %(idx)d ." % {'idx': shape_idx}
            raise WordException(tmp)

    def __internal_get_shape(self, shape_idx):
        """TODO
        """
        if isinstance(shape_idx, str):
            return self.__internal_get_shape_by_id(shape_idx)
        else:
            return self.__internal_get_shape_by_idx(shape_idx)

    def __internal_font_color_to_string(self, font_color):
        """TODO
        """
        idx = 0
        for color in FONT_COLOR.values():
            if color == font_color:
                return FONT_COLOR.keys()[idx]
            else:
                idx += 1
        return "Unknown"

    def __internal_bkrnd_color_to_string(self, bkrnd_color):
        """TODO
        """
        idx = 0
        for color in BACKROUND_COLOR.values():
            if color == bkrnd_color:
                return BACKROUND_COLOR.keys()[idx]
            else:
                idx += 1
        return "Unknown"

    def __internal_get_paragraph(self, paragraph_idx):
        """TODO
        """
        if self.__document is None:
            raise WordException("No document currently opened.")
        if isinstance(paragraph_idx, str):
            return self.__internal_get_paragraph_by_id(paragraph_idx)
        else:
            return self.__internal_get_paragraph_by_idx(paragraph_idx)

    def __internal_get_paragraph_by_idx(self, paragraph_idx):
        """TODO
        """
        if self.__document is None:
            raise WordException("No document currently opened.")
        else:
            try:
                paragraph = self.__document.Paragraphs.Item(paragraph_idx)
            except:
                tmp = "The specified index does not exist or an error occured "
                tmp += "while attempting to access paragraph "
                tmp += "%(paragraph_index)d." % {'paragraph_index': paragraph_idx}
                raise WordException(tmp)
        return paragraph

    def __internal_get_paragraph_by_id(self, paragraph_id):
        """TODO
        """
        if self.__document is None:
            raise WordException("No document currently opened.")
        else:
            try:
                paragraph_cnt = self.get_paragraphs_count()
                paragraph_cnt += 1
                for paragraph_idx in xrange(1, paragraph_cnt + 1):
                    paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
                    if paragraph_obj.ID == paragraph_id:
                        return paragraph_obj
                else:
                    raise WordException("A paragraph with the specified ID does not exist.")
            except:
                tmp = "The specified ID does not exist or an error occured "
                tmp += "while attempting to access paragraph with ID "
                tmp += "%(paragraph_id)s." % {'paragraph_id': paragraph_id}
                raise WordException(tmp)

#   def __internal_get_shape_by_id(self,shape_id):
#       if self.__document is None:
#           raise WordException("No document currently opened.")
#       else:
#           try:
#               shapes_cnt = self.get_shapes_count()
#               for idx in range(1,shapes_cnt+1):
#                   if self.__document.Shapes.Item(idx).ID==shape_id:
#                       return self.__document.Shapes.Item(idx)
#
#           except:
#                raise WordException("An error occured while getting shape.")
#       return None

    def set_table_cell_font_size(self, tbl_idx, col_idx, row_idx, font_size):
        """Function sets the size font for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :param font_size: The size of the font.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            tbl_cell.Range.Font.Size = font_size
        except:
            raise WordException("Failed to set cell font.")

    def get_table_cell_font_size(self, tbl_idx, col_idx, row_idx):
        """Function returns the size font for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .

        :return: The size of the font for the specified table cell.
       """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            return tbl_cell.Range.Font.Size
        except:
            raise WordException("Failed to get cell font.")

    def set_table_cell_font(self, tbl_idx, col_idx, row_idx, font):
        """Function sets the font for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :param font:    The new font for the cell.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            tbl_cell.Range.Font.Name = font
        except:
            raise WordException("Failed to set table cell font.")

    def get_table_cell_font(self, tbl_idx, col_idx, row_idx):
        """Function returns the font for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :return:        The name of the font for the specified table cell.
        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            return tbl_cell.Range.Font.Name
        except:
            raise WordException("Failed to get table cell font.")

    def set_table_cell_color(self, tbl_idx, col_idx, row_idx, color):
        """Function sets the backround color for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :param color:   The new backround color for the table cell as string.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            tbl_cell.Range.Shading.BackgroundPatternColor = BACKROUND_COLOR[color]
        except:
            raise WordException("Failed to set cell font color.")

    def get_table_cell_color(self, tbl_idx, col_idx, row_idx):
        """Function returns the backround color for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :return:   The  backround color for the table cell as string.
        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            return self.__internal_bkrnd_color_to_string(tbl_cell.Range.Shading.BackgroundPatternColor)
        except:
            raise WordException("Failed to get cell font color.")

    def set_table_cell_font_color(self, tbl_idx, col_idx, row_idx, font_color):
        """
        Function sets the font color for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :param font_color:   The new font color for the table cell as string.
        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            tbl_cell.Range.Font.Color = FONT_COLOR[font_color]
        except:
            raise WordException("Failed to set cell font color.")

    def get_table_cell_font_color(self, tbl_idx, col_idx, row_idx):
        """
        Function returns the font color for a table cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row .
        :return:        The font color for the table cell as string.
        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            return self.__internal_font_color_to_string(tbl_cell.Range.Font.Color)
        except:
            raise WordException("Failed to get cell font color.")

    def set_table_row_style(self, tbl_idx, row_idx, bold=False, italic=False, underline=False, alignment='Left'):
        """
        Function sets the style for all the cells on the specified row.

        :param tbl_idx: Table index or table id.
        :param row_idx: The index of the row .
        :param bold:    Specifies if the text in the table cell will be bold or not. By default set to False.
        :param italic:  Specifies if the text in the table cell will be italic or not.By default set to False.
        :param underline: Specifies if the text in the table cell will be underlined or not.By default set to False.
        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        row_cnt, col_cnt = self.get_table_dimensions(tbl_idx)
        try:
            for col_idx in xrange(1, col_cnt + 1):
                tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
                if bold is True:
                    tbl_cell.Range.Font.Bold = True
                else:
                    tbl_cell.Range.Font.Bold = False
                if italic is True:
                    tbl_cell.Range.Font.Italic = True
                else:
                    tbl_cell.Range.Font.Italic = False
                if underline is True:
                    tbl_cell.Range.Font.Underline = True
                else:
                    tbl_cell.Range.Font.Underline = False
                tbl_cell.Range.ParagraphFormat.Alignment = PARAGRAPH_ALINGMENT[alignment]
        except:
            raise WordException("Failed to set row style.")

    def set_table_column_style(self, tbl_idx, col_idx, alignment='Left', bold=False, italic=False, underline=False):
        """
        Function sets the style for all the cells on the specified row.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param alignment: The alignment of the text in the cells on the specified column.
        :param bold:    Specifies if the text in the table cell will be bold or not. By default set to False.
        :param italic:  Specifies if the text in the table cell will be italic or not.By default set to False.
        :param underline: Specifies if the text in the table cell will be underlined or not.By default set to False.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        row_cnt, col_cnt = self.get_table_dimensions(tbl_idx)
        try:
            for row_idx in xrange(1, row_cnt + 1):
                tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
                if bold is True:
                    tbl_cell.Range.Font.Bold = True
                else:
                    tbl_cell.Range.Font.Bold = False
                if italic is True:
                    tbl_cell.Range.Font.Italic = True
                else:
                    tbl_cell.Range.Font.Italic = False
                if underline is True:
                    tbl_cell.Range.Font.Underline = True
                else:
                    tbl_cell.Range.Font.Underline = False
                tbl_cell.Range.ParagraphFormat.Alignment = PARAGRAPH_ALINGMENT[alignment]
        except:
            raise WordException("Failed to set column style.")

    def set_table_cell_style(self, tbl_idx, col_idx, row_idx, bold=False,
                             italic=False, underline=False, alignment='Left'):
        """Function sets the style for  the specified cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row.
        :param bold:    Specifies if the text in the table cell will be bold or not. By default set to False.
        :param italic:  Specifies if the text in the table cell will be italic or not.By default set to False.
        :param underline: Specifies if the text in the table cell will be underlined or not.By default set to False.
        :param alignment: The alignment of the text in the cells on the
                          specified column.By default set to ALIGNMENT_HORIZAONTAL_LEFT.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            if bold is True:
                tbl_cell.Range.Font.Bold = True
            else:
                tbl_cell.Range.Font.Bold = False
            if italic is True:
                tbl_cell.Range.Font.Italic = True
            else:
                tbl_cell.Range.Font.Italic = False
            if underline is True:
                tbl_cell.Range.Font.Underline = True
            else:
                tbl_cell.Range.Font.Underline = False
            tbl_cell.Range.ParagraphFormat.Alignment = PARAGRAPH_ALINGMENT[alignment]
        except:
            raise WordException("Failed to set cell font style.")

    def get_table_cell_style(self, tbl_idx, col_idx, row_idx):
        """Function returns the style for  the specified cell.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .
        :param row_idx: The index of the row.
        :return:  A tuple with the style of the table cell.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            if tbl_cell.Range.Font.Italic != 0:
                bItalic = True
            else:
                bItalic = False
            if tbl_cell.Range.Font.Bold != 0:
                bBold = True
            else:
                bBold = False
            if tbl_cell.Range.Font.Underline != 0:
                bUnderline = True
            else:
                bUnderline = False
            sAlignment = self.__internal_alignment_to_string(tbl_cell.Range.ParagraphFormat.Alignment)
            return (bBold, bItalic, bUnderline, sAlignment)
        except:
            raise WordException("Failed to get cell font style.")

    def remove_table(self, tbl_idx):
        """Function removes the specified table from the document.

        :param tbl_idx: Table index or table id.
        :param col_idx: The index of the column .

        """
        if self.__document is None:
            raise WordException("No document currently opened.")
        try:
            tbl_obj = self.__internal_get_table(tbl_idx)
            tbl_obj.Delete()
        except:
            raise WordException("An error occured while removing table.")

    def  get_table_dimensions(self, tbl_idx):
        """Function returns the size of the specified table.

        :param tbl_idx: Table index or table id.
        :return:  A list with the number of rows and number of columns.
                  If the table has a different number of cells or a row the maximum number will be returned.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        try:
            return [tbl_obj.Rows.Count, tbl_obj.Columns.Count]
        except:
            WordException("Failed to get table dimensions.")

    def resize_table(self, tbl_idx, new_col_cnt, new_row_cnt):
        """Function resizes the specified table to the new dimension.The table can only grow.

        :param tbl_idx: Table index or table id.
        :param new_col_cnt: The new number of columns for the table.
        :param new_row_cnt: The new number of rows for the table.

        """
        return self.__internal_resize_table(tbl_idx, new_col_cnt, new_row_cnt)

    def set_table_cell_data(self, tbl_idx, row_idx, col_idx, tbl_data, Force=False):
        """Function sets the text for the specified table cell.

        :param tbl_idx: Table index or table id.
        :param row_idx: The index of the row that contains the cell.
        :param col_idx: The index of the column that contains the cell.
        :param tbl_data: The new cell text.
        :param Force:    Makes it posible to access tables that have rows with different number of cells.
                         By default set to False(assuming all the rows have the same number of cells.)
                         By setting to True disables check of the row and column indexes vs dimensions of the table.
        :return:  A list with the number of rows and number of columns.
                  If the table has a different number of cells or a row the maximum number will be returned.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        # Check if the specified cell is in the table dimensions(Default).
        # Word returns a cell can return a cell even is the index is out of bound.
        # It is also posible that the table does not have the same number of columns for each row.
        if Force is False:
            tbl_dim = self.get_table_dimensions(tbl_idx)
            if row_idx not in xrange(1, tbl_dim[0] + 1) or col_idx not in xrange(1, tbl_dim[1] + 1):
                raise WordException("The specified table cell is not within table bounds.")
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            tbl_cell.Range.Text = tbl_data
        except:
            raise WordException("Failed to set table cell data.")

    def get_table_cell_data(self, tbl_idx, row_idx, col_idx):
        """Function returns the text for the specified table cell.

        :param tbl_idx: Table index or table id.
        :param row_idx: The index of the row that contains the cell.
        :param col_idx: The index of the column that contains the cell.
        :return:   The text contained in the specified table cell as a str.

        """
        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            return str(tbl_cell.Range.Text).rstrip('\r\007')
        except:
            raise WordException("Failed to set table cell data.")

    def set_table_data(self, tbl_idx, tbl_data):
        """Function sets the data for the entire table.

        :param tbl_idx: Table index or table id.
        :param tbl_data: The new data for the entire table.
                         The size of the data must match the size of the table
                         if not the table will be automatically resized.

        """
        if len(tbl_data) == 0:
            pass

        tbl_obj = self.__internal_get_table(tbl_idx)
        tbl_dim = self.get_table_dimensions(tbl_idx)
        tbl_row_cnt = tbl_dim[0]
        tbl_col_cnt = tbl_dim[1]

        data_row_cnt = len(tbl_data)
        data_col_cnt = len(tbl_data[0])

        if tbl_row_cnt == 0 or tbl_col_cnt == 0 or len(tbl_data) == 0:
            self.__internal_resize_table(tbl_idx, data_col_cnt, data_row_cnt)
            self.__internal_set_table_data(tbl_obj, data_col_cnt, data_row_cnt, tbl_data)
        else:
            data_row_cnt = len(tbl_data)
            data_col_cnt = len(tbl_data[0])
            if tbl_row_cnt != data_row_cnt or tbl_col_cnt != data_col_cnt:
                # Resize the table and set the data or not
                self.__internal_resize_table(tbl_idx, data_col_cnt, data_row_cnt)
                self.__internal_set_table_data(tbl_obj, data_col_cnt, data_row_cnt, tbl_data)
            else:
                self.__internal_set_table_data(tbl_obj, data_col_cnt, data_row_cnt, tbl_data)

    def  get_table_data(self, table_idx):
        """Function returns the data for the entire table.

        :param tbl_idx: Table index or table id.
        :return: A list containing aditional lists for each row.
                 Each value in the list represents a different cell.
        """
        tbl_obj = None
        cells = []
        tbl_obj = self.__internal_get_table(table_idx)
        try:
            row_cnt = tbl_obj.Rows.Count
        except:
            raise WordException("Failed to get table rows count.")
        for row in xrange(1, row_cnt + 1):
            row_cells = []
            tbl_row_obj = self.__internal_get_table_row(tbl_obj, row)
            try:
                col_cnt = tbl_row_obj.Cells.Count
            except:
                raise WordException("Failed to get number of cells for the table row %(row_id)%" % {'row_id': row})
            for col in xrange(1, col_cnt + 1):
                row_cells.append(self.__internal_get_table_cell_value(tbl_obj, row, col))
            cells.append(row_cells)
        return cells

    def set_paragraph_font_size(self, paragraph_idx, font_size):
        """Function sets the font size for the specified paragraph.

        :param paragraph_idx: Paragraph index or Paragraph id.
        :param font_size:     The new size for the font in the paragraph.
        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            paragraph_obj.Range.Font.Size = font_size
        except:
            raise WordException("Failed to set paragraph font size.")

    def get_paragraph_font_size(self, paragraph_idx):
        """
        Function returns the font size for the specified paragraph.

        :param paragraph_idx: Paragraph index or Paragraph id.
        :return: The font size for the specified paragraph.
        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            return paragraph_obj.Range.Font.Size
        except:
            raise WordException("Failed to get paragraph font size.")

    def set_paragraph_font_color(self, paragraph_idx, font_color):
        """
        Function sets the font color for the specified paragraph.

        :param paragraph_idx: Paragraph index or Paragraph id.
        :param font_color: The new font color for the specified paragraph.
        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            paragraph_obj.Range.Font.Color = FONT_COLOR[font_color]
        except:
            raise WordException("Failed to set paragraph font color.")

    def get_paragraph_font_color(self, paragraph_idx):
        """Function returns the font color for the specified paragraph.

        :param paragraph_idx: Paragraph index or Paragraph id.
        :return: The font color for the specified paragraph.

       """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            return self.__internal_font_color_to_string(paragraph_obj.Range.Font.Color)
        except:
            raise WordException("Failed to get paragraph font color.")

    def remove_paragraph(self, paragraph_idx):
        """Function removes the speicified paragraph.

         :param paragraph_idx: Paragraph index or Paragraph id.

        """
        if self.__document is None:
            raise WordException("No document currently opened.")
        try:
            self.__document.Paragraphs.Remove(paragraph_idx)
        except:
            raise WordException("An error occured while removing table.")

    def set_paragraph_ident(self, paragraph_idx, ident_size):
        """Function sets the identation for the specified paragraph.

         :param paragraph_idx: Paragraph index or Paragraph id.
         :param ident_size:    Identation size.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            paragraph_obj.IndentFirstLineCharWidth(ident_size)
        except:
            raise WordException("An error occured while setting paragraph identation.")

    def get_paragraph_ident(self, paragraph_idx):
        """Function returns the identation for the speicified paragraph.

         :param paragraph_idx: Paragraph index or Paragraph id.
         :return:    Identation size.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            return  paragraph_obj.IndentFirstLine
        except:
            raise WordException("An error occured while getting paragraph identation.")

    def set_paragraph_font(self, paragraph_idx, font_name):
        """Function sets the font for the specified paragraph.

         :param paragraph_idx: Paragraph index or Paragraph id.
         :param font_name: The name of the font for the paragraph.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            paragraph_obj.Range.Font.Name = font_name
        except:
            raise WordException("Failed to set paragraph font.")

    def set_paragraph_style(self, paragraph_idx, bold=False, italic=False, underline=False, alignment='Left'):
        """Function sets the style for the specified paragraph.

        :param paragraph_idx: Paragraph index or Paragraph id.
        :param bold:  Flag to specify if the text should be set to bold. By default set to False.
        :param italic: Flag to specify if the text should be italic. By default set to False.
        :param underline: Flag to specify if the text should be underline. By default set to False.
        :param alignment: The alignment for the paragraph as a string. By default set to ALIGNMENT_HORIZAONTAL_LEFT.
        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            if bold is True:
                paragraph_obj.Range.Font.Bold = True
            else:
                paragraph_obj.Range.Font.Bold = False
            if italic is True:
                paragraph_obj.Range.Font.Italic = True
            else:
                paragraph_obj.Range.Font.Italic = False
            if underline is True:
                paragraph_obj.Range.Font.Underline = True
            else:
                paragraph_obj.Range.Font.Underline = False
            paragraph_obj.Alignment = PARAGRAPH_ALINGMENT[alignment]
        except:
            raise WordException("Failed to set paragraph style.")

    def get_paragraph_style(self, paragraph_idx):
        """Function returns the style for the specified paragraph.

        :return: A list with the style. The order is the same as for SetParagraphStyle.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            bBold = False
            bItalic = False
            bUnderline = False
            sAlignment = self.__internal_alignment_to_string(paragraph_obj.Alignment)
            if paragraph_obj.Range.Font.Bold != 0:
                bBold = True
            else:
                bBold = False
            if paragraph_obj.Range.Font.Italic != 0:
                bItalic = True
            else:
                bItalic = False
            if paragraph_obj.Range.Font.Underline != 0:
                bUnderline = True
            else:
                bUnderline = False
            return [bBold, bItalic, bUnderline, sAlignment]
        except:
            raise WordException("Failed to get paragraph style.")

    def get_tables_count(self):
        """Function returns the number of tables in the document.

        :return: The number of tables in the document currently opened.

        """
        tbl_count = 0
        if self.__document is None:
            raise WordException("No document currently opened.")
        try:
            tbl_count = self.__document.Tables.Count
        except:
            raise WordException("Failed to get the tables count.")
        return tbl_count

    def get_paragraphs_count(self):
        """Function returns the number of paragraphs in the document.

        :return: The number of paragraphs in the document currently opened.

        """
        paragraphs_count = 0
        if self.__document is None:
            raise WordException("No document currently opened.")
        else:
            try:
                paragraphs_count = self.__document.Paragraphs.Count
            except:
                raise WordException("Failed to get the number of paragraphs in the document.")
        return paragraphs_count

    def set_paragraph_id(self, paragraph_idx, id_str):
        """Function sets an aditional string ID which can be used to identify a paragraph.

        :param paragraph_idx: The index of the paragraph.
        :param id_str: A string which will be used to identify the paragraph.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            paragraph_obj.ID = id_str
        except:
            raise WordException("Failed to set paragraph ID.")

    def get_paragraph_id(self, paragraph_idx):
        """Function returns the string ID.

        :param paragraph_idx: The index of the paragraph.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        paragraph_id = ""
        try:
            paragraph_id = paragraph_obj.ID
        except:
            raise WordException("Failed to get paragraph ID.")
        return paragraph_id

    def set_paragraph_text(self, paragraph_idx, text):
        """
        Function sets the text in the specified paragraph.

        :param paragraph_idx: The paragraph index or the ID string.
        :param text: The new text for the paragraph.
        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            paragraph_obj.Range.Text = text
        except:
            raise WordException("Failed to set paragraph text.")

    def get_paragraph_text(self, paragraph_idx):
        """Function returns the text in the specified paragraph.

        :param paragraph_idx: The paragraph index or the ID string.
        :return: The text in the paragraph.

        """
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            return paragraph_obj.Range.Text
        except:
            raise WordException("Failed to get paragraph text.")

    def set_paragraph_hyperlink(self, paragraph_idx, hyperlink_text="", hyperlink_address="", hyperlink_screen_tip=""):
        """
        Function inserts a hyperlink in the specified paragraph.

        :param paragraph_idx:  The paragraph index or the ID string.
        :param hyperlink_text: The text for the hyperlink.
        :param hyperlink_address: The address for the hyperlink.
        :param hyperlink_screen_tip: The tooptip text displayed over the hyperlink.
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            self.__document.Hyperlinks.Add(paragraph_obj.Range,
                                           hyperlink_address,
                                           "",
                                           hyperlink_screen_tip,
                                           hyperlink_text)
        except:
            raise WordException("Failed to add hyperlink to paragraph.")

    def set_table_cell_hyperlink(self, table_idx, row_idx, col_idx,
                                 hyperlink_text, hyperlink_address, hyperlink_screen_tip):
        """Function inserts a hyperlink in the specified table cell.

        :param table_idx:  The table index or the ID string.
        :param row_idx:  The index of the row on which the cell is situated.
        :param col_idx:  The index of the column on which the cell is situated.
        :param hyperlink_text: The text for the hyperlink.
        :param hyperlink_address: The address for the hyperlink.
        :param hyperlink_screen_tip: The tooptip text displayed over the hyperlink.
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        tbl_obj = self.__internal_get_table(table_idx)
        cell = self.__internal_get_table_cell(tbl_obj, row_idx, col_idx)
        try:
            self.__document.Hyperlinks.Add(cell.Range, hyperlink_address, "", hyperlink_screen_tip, hyperlink_text)
        except:
            raise WordException("Failed to add hyperlink to paragraph.")

    def get_hyperlinks_count(self):
        """
        Function returns the number of hyperlinks in the document.

         :return: The number of hyperlinks in the document.
        """
        hyperlinks_count = 0
        if self.__document is None:
            raise WordException("Failed to get hyperlinks count.No document is opened.")
        else:
            try:
                hyperlinks_count = self.__documnet.Hyperlinks.Count
            except:
                raise WordException("Failed to get the hyperlinks count in the current document.")
        return hyperlinks_count

    def set_hyperlink_display_text(self, hyperlink_idx, hyperlink_text):
        """Function sets the display text for the specified hyperlink.

         :param hyperlink_idx: The index of the hyperlink.
         :param hyperlink_text: The new text for the hyperlink.

        """
        hyperlink_obj = self.__internal_get_hyperlink(hyperlink_idx)
        try:
            hyperlink_obj.TextToDisplay = hyperlink_text
        except:
            raise WordException("Failed to set hyperlink text.")

    def get_hyperlink_display_text(self, hyperlink_idx):
        """Function returns the display text for the specified hyperlink.

         :param hyperlink_idx: The index of the hyperlink.
         :return: The display text for the hyperlink.

        """
        hyperlink_text = ""
        hyperlink_obj = self.__internal_get_hyperlink(hyperlink_idx)
        try:
            hyperlink_text = hyperlink_obj.TextToDisplay
        except:
            raise WordException("Failed to get hyperlink text.")
        return hyperlink_text

    def set_hyperlink_address_text(self, hyperlink_idx, hyperlink_address):
        """Function sets the address for the specified hyperlink.

         :param hyperlink_idx: The index of the hyperlink.
         :param hyperlink_address: The new address for the hyperlink.

        """
        hyperlink_obj = self.__internal_get_hyperlink(hyperlink_idx)
        try:
            hyperlink_obj.Address = hyperlink_address
        except:
            raise WordException("Failed to set hyperlink address.")

    def get_hyperlink_address_text(self, hyperlink_idx):
        """Function returns the address for the specified hyperlink.

         :param hyperlink_idx: The index of the hyperlink.
         :return :The address for the specified hyperlink.

        """
        hyperlink_address = ""
        hyperlink_obj = self.__internal_get_hyperlink(hyperlink_idx)
        try:
            hyperlink_address = hyperlink_obj.Address
        except:
            raise WordException("Failed to get hyperlink address.")
        return hyperlink_address

    def set_hyperlink_screen_tip(self, hyperlink_idx, hyperlink_screen_tip):
        """Function sets the screen for the specified hyperlink.

         :param hyperlink_idx: The index of the hyperlink.
         :param hyperlink_screen_tip: The new screen tip for the hyperlink.

        """
        hyperlink_obj = self.__internal_get_hyperlink(hyperlink_idx)
        try:
            hyperlink_obj.ScreenTip = hyperlink_screen_tip
        except:
            raise WordException("Failed to set hyperlink screent tip.")

    def get_hyperlink_screen_tip(self, hyperlink_idx):
        """Function returns the screen for the specified hyperlink.

         :param hyperlink_idx: The index of the hyperlink.
         :return: The screen tip for the hyperlink.

        """
        hyperlink_screen_tip = ""
        hyperlink_obj = self.__internal_get_hyperlink(hyperlink_idx)
        try:
            hyperlink_screen_tip = hyperlink_obj.ScreenTip
        except:
            raise WordException("Failed to get hyperlink screen tip.")
        return hyperlink_screen_tip

    def update_table_of_contents(self, tbl_toc_idx):
        """Function updates the specified table of contents."""
        tbl_toc_obj = self.__internal_get_toc(tbl_toc_idx)
        try:
            tbl_toc_obj.Update()
        except:
            raise WordException("Failed to update table of contents.")

    def get_table_of_contents_count(self):
        """Function returns the number of tables of contents.

         :return: The number of tables of contents.

        """
        toc_count = 0
        if self.__document is None:
            raise WordException("No document is currently opened.")
        else:
            try:
                toc_count = self.__document.TablesOfContents.Count
            except:
                raise WordException("Failed to get tables of contents count for the current document.")
        return toc_count

    def hide_word_application(self):
        """Function hides the WinWord application."""
        if self.__app is None:
            raise WordException("Initialization error.")
        try:
            self.__app.Visible = False
        except:
            raise WordException("Failed to hide Word window.")

    def show_word_application(self):
        """Function shows the WinWord application."""
        if self.__app is None:
            raise WordException("Initialization error.")
        try:
            self.__app.Visible = True
        except:
            raise WordException("Failed to show Word window.")

    def hide_current_document(self):
        """Function hides the document currenltly opened."""
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            self.__document.Visible = False
        except:
            raise WordException("Failed to hide the current document.")

    def show_current_document(self):
        """Function shows the current document."""
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            self.__document.Visible = True
        except:
            raise WordException("Failed to show the current document.")

    def table_id_to_index(self, id_str):
        """Function returns the index of the table which has the specified ID string.

         :param id_str: The ID string that indetifies a table.
         :return: The index of the table with the ID string.

        """
        tbl_count = self.get_tables_count()
        for tbl_idx in xrange(1, tbl_count + 1):
            if self.__internal_get_table(tbl_idx).ID == id_str:
                return tbl_idx
        else:
            return -1

    def insert_table(self, paragraph_idx, row_count, col_count, tbl_id_str='', autofit_behavior='AutoFitContent'):
        """Function inserts a new table in the document.

         :param pargraph_idx: The index or ID string of a paragraph. The new table will be inserted in the paragraph.
         :param row_count:  The number of rows for the new table.
         :param col_count:  The number of columns for the new table.
         :param tbl_id_str: An string which can be used to identify the table. By default set to ''
         :param autofit_behavior: The autofit behavior of the table as a string.

        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            tbl_obj = self.__document.Tables.Add(paragraph_obj.Range, row_count, col_count,
                                                 1, AUTOFIT_BEHAVIOR[autofit_behavior])
            tbl_obj.ID = tbl_id_str
            return self.get_tables_count()
        except:
            raise WordException("Failed to add new paragraph in the document.")

    def insert_paragraph_at_end(self):
        """Function inserts a new paragraph at the end of the document.

         :return: The number of paragraphs in the document.

        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            self.__document.Paragraphs.Add()
        except:
            raise WordException("Failed to add new paragraph in the document.")
        return self.get_paragraphs_count()

    def insert_paragraph(self, paragraph_idx):
        """Function inserts a new paragraph before the specified paragraph.

         :return: The number of paragraphs in the document.

        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        paragraph_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            self.__document.Paragraphs.Add(paragraph_obj.Range)
        except:
            raise WordException("Failed to add new paragraph in the document.")
        return self.get_paragraphs_count()

    def add_picture_shape(self, file_name, paragraph_idx=None, orientation='Horizontal'):
        """
        Function inserts a new paragraph at the end of the document.

        :param file_name: The file path to picture to be inserted.
        :param paragraph_idx: The paragraph which is used as an anchor.
                              The picture shape will be inserted at the begining of the paragraph.
        :return: The new shape ID.
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        if len(file_name) == 0:
            raise WordException("No picture document specified.")
        else:
            if exists(file_name) is False:
                raise WordException("The specified path does not exist.(%(path)s)" % {'path': file_name})

        anchor_obj = None
        if paragraph_idx is not None:
            anchor_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            shape_obj = None
            if anchor_obj is None:
                shape_obj = self.__document.Shapes.AddPicture(file_name, False, True)
            else:
                shape_obj = self.__document.Shapes.AddPicture(file_name, False, True, anchor_obj)
            if shape_obj is not None:
                return shape_obj.ID
        except:
            raise WordException("Failed to add picture to the document.")

    def get_shape_size(self, pic_shape_id):
        """Function returns the size of the specified shape.

          :param pic_shape_id: The id of the shape for which the dimensions are needed.
          :return: A list with the dimensions of the picture shape. The list members are heigh,width,left,top.

        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            shape = self.__internal_get_shape_by_id(pic_shape_id)
            if shape is None:
                raise WordException("A shape with the specified ID does not exist.")
            else:
                return {'Height': shape.Height, 'Width': shape.Width, 'Left': shape.Left, 'Top': shape.Top}
        except:
            raise WordException("The picture with the specified id does not exist.")

    def add_diagram_shape(self):
        """
        Function returns the size of the specified shape.

        :param pic_shape_id: The id of the shape for which the dimensions are needed.
        :return: A list with the dimensions of the picture shape. The list members are heigh,width,left,top.
        """
        raise WordException("Not implemented.")

    def add_polyline_shape(self, x_values, y_values, paragraph_idx=None, orientation='Horizontal'):
        raise WordException("Not implemented.")

#         if self.is_document_opened() is False:
#             raise WordException("No document currently opened.")
#         # if not isinstance(x_value,list) or not isinstance(y_values,list):
#         #   raise WordException("Expecting type list for x_values or y_values parameters.")
#         if len(x_values) != len(y_values):
#             raise WordException("The number of values for x_values must be equal to y_values.")
#         anchor_obj = None
#         if paragraph_idx is not None:
#             anchor_obj = self.__internal_get_paragraph(paragraph_idx)
#         # try:
#         shape_obj = None
#         x_values += y_values
#
#         if anchor_obj is None:
#             shape_obj = self.__document.Shapes.AddPolyline(x_values)
#         else:
#             shape_obj = self.__document.Shapes.AddPolyline(x_values + y_values, anchor_obj)
#             if shape_obj is not None:
#                 return shape_obj.ID
#         # except:
#         #    raise WordException("Failed to add polyline to the document.")

    def add_label_shape(self, left, top, width, height, label_text="", paragraph_idx=None, orientation='Horizontal'):
        """
        Function adds a new label shape.

        :param left: The distance from the left side of the containing paragraph.
        :param top:  The distance from the top side of the containing paragraph.
        :param width: The width of the label shape.
        :param heigh: The height of the label shape.
        :param label_text: The text in the label shape.
        :param paragraph_idx: The index or ID of a paragraph which will be used as an anchor.
        :param orientation: The orientation of the label shape.
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        if left < 0 or top < 0 or width < 0 or height < 0:
            raise WordException("Coordinates and dimensions must be positive numbers.")
        anchor_obj = None
        if paragraph_idx is not None:
            anchor_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            shape_obj = None
            if anchor_obj is None:
                shape_obj = self.__document.Shapes.AddLabel(TEXT_ORIENTATION[orientation], left, top, width, height)
            else:
                shape_obj = self.__document.Shapes.AddLabel(TEXT_ORIENTATION[orientation],
                                                            left, top, width, height, anchor_obj.Range)
            if shape_obj is not None:
                shape_obj.TextFrame.TextRange.Text = label_text
            return shape_obj.ID
        except:
            raise WordException("Failed to add label to the document.")

    def add_textbox_shape(self, left, top, width, height, textbox_text="",
                          paragraph_idx=None, orientation='Horizontal'):
        """
        Function adds a new text box shape.

        :param left: The distance from the left side of the containing paragraph.
        :param top:   The distance from the top side of the containing paragraph.
        :param width:  The width of the text box shape.
        :param height: The height of the text box shape.
        :param textbox_text: The text inside of the text box shape.
        :param paragrpah_idx: An index or ID of a paragraph which will be used as an anchor for the text box shape.
        :param orientation: The orientation of the text box shape.
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        if left < 0 or top < 0 or height < 0 or height < 0:
            raise WordException("Coordinates and dimensions must be positive numbers.")
        anchor_obj = None
        if paragraph_idx is not None:
            anchor_obj = self.__internal_get_paragraph(paragraph_idx)
        try:
            shape_obj = None
            if anchor_obj is None:
                shape_obj = self.__document.Shapes.AddTextbox(TEXT_ORIENTATION[orientation], left, top, width, height)
            else:
                shape_obj = self.__document.Shapes.AddLabel(TEXT_ORIENTATION[orientation],
                                                            left, top, width, height, anchor_obj.Range)
            if shape_obj is not None:
                shape_obj.TextFrame.TextRange.Text = textbox_text
            return shape_obj.ID
        except:
            raise WordException("Failed to add textbox to the document.")

    def add_line_shape(self, x_start, y_start, x_end, y_end, paragraph_idx=None):
        """
        Function adds a new line shape.

        :param x_start: The start X coordinate for the line within the containing paragraph.
        :param y_start: The start Y coordinate for the line within the containing paragraph.
        :param x_end: The end X coordinate for the line within the containing paragraph.
        :param y_end: The end Y coordinate for the line within the containing paragraph.
        :param paragrpah_idx: An index or ID of a paragraph which will be used as an anchor for the text box shape.
         """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        anchor_obj = None
        if paragraph_idx is not None:
            anchor_obj = self.__internal_get_paragraph(paragraph_idx)
        if x_start < 0 or y_start < 0 or x_end < 0 or y_end < 0:
            raise WordException("Coordinates must be positive numbers.")
        try:
            shape_obj = None
            if anchor_obj is None:
                shape_obj = self.__document.Shapes.AddLine(x_start, y_start, x_end, y_end)
            else:
                shape_obj = self.__document.Shapes.AddLine(x_start, y_start, x_end, y_end, anchor_obj.Range)
            if shape_obj is not None:
                return shape_obj.ID
        except:
            raise WordException("Failed to add label to the document.")

    def get_shapes_count(self):
        """
        Function returns the number of shapes in the document.

        :return: The number of shapes in the document.
        """
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            return self.__document.Shapes.Count
        except:
            raise WordException("Failed to get the number of shapes present in the document.")

    def close(self):
        """Function closes the document currently opened."""
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        del self.__document
        self.__document = None

    def save(self):
        """Function saves the document currently opened."""
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            self.__document.Save()
        except:
            raise WordException("An exception occured while closing the document.")

    def save_as(self, filename):
        """Function saves the document currently opened to the specified path."""
        if self.is_document_opened() is False:
            raise WordException("No document currently opened.")
        try:
            self.__document.SaveAs(filename)
        except:
            raise WordException("An error occured while saving the document as %(doc_path)s" % {'doc_path': filename})

"""
CHANGE LOG:
-----------
$Log: word.py  $
Revision 1.1 2021/12/13 17:59:04CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/project.pj
Revision 1.13 2013/04/19 12:53:37CEST Hecker, Robert (heckerr) 
Functionality revert to version 1.11.
- Added comments -  heckerr [Apr 19, 2013 12:53:37 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.12 2013/04/11 10:17:02CEST Mertens, Sven (uidv7805) 
fixing some pylint errors
--- Added comments ---  uidv7805 [Apr 11, 2013 10:17:03 AM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.11 2013/04/03 08:02:19CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:19 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/04/02 10:24:59CEST Mertens, Sven (uidv7805)
pylint: E0213, E1123, E9900, E9904, E1003, E9905, E1103
--- Added comments ---  uidv7805 [Apr 2, 2013 10:25:01 AM CEST]
Change Package : 176171:9 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.9 2013/03/28 15:25:13CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:13 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/28 14:20:05CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
Revision 1.7 2013/03/28 13:31:15CET Mertens, Sven (uidv7805)
minor pep8
--- Added comments ---  uidv7805 [Mar 28, 2013 1:31:15 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/28 09:33:15CET Mertens, Sven (uidv7805)
pylint: removing unused imports
Revision 1.5 2013/02/28 17:21:00CET Hecker, Robert (heckerr)
Updates regarding Pep8 Style.
--- Added comments ---  heckerr [Feb 28, 2013 5:21:01 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/28 08:12:26CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:26 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 16:19:59CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:20:00 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/20 08:21:53CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:53 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/12 16:13:29CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/rep/project.pj
Revision 1.9 2012/09/25 08:08:01CEST Mogos, Sorin (mogoss)
* bug-fix: fixed "global name 'create_new_word_instance' is not defined" error
--- Added comments ---  mogoss [Sep 25, 2012 8:08:05 AM CEST]
Change Package : 147308:2 http://mks-psad:7002/im/viewissue?selection=147308
Revision 1.8 2012/09/25 08:05:43CEST Mogos, Sorin (mogoss)
* update: turn off grammatical and spelling errors
--- Added comments ---  mogoss [Sep 25, 2012 8:05:50 AM CEST]
Change Package : 147308:2 http://mks-psad:7002/im/viewissue?selection=147308
Revision 1.7 2010/10/04 10:20:19CEST Raicu, Ovidiu (RaicuO)
Bug-fix for remove_table function, error handling in save_as function, and table_id_to_index() function.
--- Added comments ---  RaicuO [Oct 4, 2010 10:20:19 AM CEST]
Change Package : 37852:1 http://mks-psad:7002/im/viewissue?selection=37852
Revision 1.6 2010/04/29 10:31:36CEST oraicu
Added auto resize for tables when the size of the data is greater than the size of the table.
Bugfix for set_row_style.
--- Added comments ---  oraicu [2010/04/29 08:31:36Z]
Change Package : 41938:1 http://LISS014:6001/im/viewissue?selection=41938
Revision 1.5 2010/03/22 08:32:24CET Ovidiu Raicu (oraicu)
Changed the name of the functions to be according to coding guidelines.
--- Added comments ---  oraicu [2010/03/22 07:32:24Z]
Change Package : 37852:1 http://LISS014:6001/im/viewissue?selection=37852
Revision 1.4 2010/02/19 15:06:31CET dkubera
update header and footer
--- Added comments ---  dkubera [2010/02/19 14:06:31Z]
Change Package : 33974:2 http://LISS014:6001/im/viewissue?selection=33974
Revision 1.3 2010/01/26 07:25:10CET Ovidiu Raicu (oraicu)
Updated stk_word class.
--- Added comments ---  oraicu [2010/01/26 06:25:10Z]
Change Package : 35288:1 http://LISS014:6001/im/viewissue?selection=35288
Revision 1.2 2009/06/24 22:18:34CEST Robert Hecker (rhecker)
Some Changes for Doxygen Comments
--- Added comments ---  rhecker [2009/06/24 20:18:34Z]
Change Package : 27994:1 http://LISS014:6001/im/viewissue?selection=27994
--- Added comments ---  rhecker [2009/06/24 20:18:34Z]
Change Package : 27994:1 http://LISS014:6001/im/viewissue?selection=27994
Revision 1.1 2009/06/24 21:36:04CEST Robert Hecker (rhecker)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/31_PyLib/project.pj
"""
