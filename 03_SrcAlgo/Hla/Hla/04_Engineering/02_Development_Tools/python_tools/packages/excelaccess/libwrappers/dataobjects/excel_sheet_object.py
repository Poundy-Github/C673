"""
@author: uidq3472
"""

# noinspection PyUnresolvedReferences
from excelaccess.xmldescriptor.xml_defs import sheet_port_attr


class SheetObject:
    """Data structure containing and representing the excel file object's sheets. It 
    owns methods for operating on its contents, e.g. all row-objects.
    
    :param str name: the sheets name
    """

    def __init__(self, name, config=None):
        self.name = name
        self.config = config
        self.tables = []  # list of table objects present in this sheet

    def __str__(self):
        """Pretty print sheet and its content."""
        tables_str = "".join([table.__str__() + ",\n" for table in self.tables])
        return "SheetObject: name: '{name}', tables:\n{tables}".format(name=self.name, tables=tables_str)

    def get_sheet_name(self):
        """Returns the sheet`s name.
        
        :return: the sheet name
        :rtype: str
        """
        return self.name

    def add_table(self, table):
        """Adds a ExcelTableObject to the sheet`s table list.
        
        :param ExcelTableObject table: a table present in this sheet
        """
        self.tables.append(table)

    def get_table(self, table_idx=0):
        """Returns a table by its index from the sheet`s table list.
        
        :param int table_idx: index of the table to be retrieved
        :return: table
        :rtype: ExcelTableObject
        """
        return self.tables[table_idx]

    def get_tables(self):
        """Returns the sheet`s table list.
        
        :return: all tables
        :rtype: list(ExcelTableObject)
        """
        return self.tables

    def get_caption(self):
        """Method for pretty printing the sheet`s identifier.
        
        :return: caption
        :rtype: str
        """
        sheet_s = "SheetObject: name: '{name}', index: '{idx}', tables:".format(name=self.name, idx=None)
        caption_s = "{frame}{caption}{frame}".format(caption=sheet_s, frame="#" * len(sheet_s))
        return caption_s

    def get_port_name(self):
        """Returns port name from sheet config element.
        
        :return port name
        :rtype: str
        """
        if self.config is not None:
            return self.config.get(sheet_port_attr)
