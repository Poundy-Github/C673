"""
@author: uidq3472
"""

# noinspection PyUnresolvedReferences
# noinspection PyProtectedMember
from excelaccess.utils import unorderd_tree as utree


class ExcelTableObject:
    """Data structure containing and representing tables in a Excel sheet. It 
    owns methods for operating on its contents.
    
    :param (int, int) table_start: start
    :param (int, int) table_end: end
    :param int header_rows: count of header rows 
    :param int table_index: index of this table in its sheet
    """

    def __init__(self, table_start, table_end, header_rows, table_index=None):
        # basic attributes
        self.table_start = table_start  # xml attr
        self.table_end = table_end  # xml attr
        self.header_rows = header_rows  # xml attr
        self.table_index = table_index  # xml attr

        # advanced attributes
        self.merged_cells = []  # merged cells for this tables range
        self.header_merged_cells = []  # merged cells for this tables range
        self.data_merged_cells = []  # merged cells for this tables range

        # content attributes
        self.data_list = []  # rows/colums?
        self.header_tree = None

    def __str__(self):
        """Pretty print the table. 
        
        :return: pretty string
        :rtype: str
        """
        return "{table}{indent}HEADER_TREE: {indent}{header}{indent}HEADER_LIST: {indent}{hlist}{indent}DATA_LIST: {indent}{data}{indent}".format(
            table=self.get_out_header(self.table_index),
            indent="\n\n",
            header=utree.print_tree(self.header_tree,
                                    return_function=lambda node: "{0} (relRow={1}, relCol={2})".format(node.title,
                                                                                                       node.get_relative_row(),
                                                                                                       node.get_relative_col())),
            hlist=[node.title for node in utree.get_leave_nodes(self.header_tree)],
            data="\n".join([data.__str__() for data in self.data_list]))

    def set_header_tree(self, header_tree):
        """Sets the tables header tree structure.
        
        :param TreeNode header_tree: tree with headers
        """
        self.header_tree = header_tree

    def get_start_column(self):
        """Method for getting the tables start column.
        
        :return: start column
        :rtype: int
        """
        return self.table_start[0]

    def get_start_row(self):
        """Method for getting the table`s start row.
        
        :return: start row
        :rtype: int
        """
        return self.table_start[1]

    def get_end_column(self):
        """Method for getting the table`s end column.
        
        :return: end column
        :rtype: int
        """
        return self.table_end[0]

    def get_end_row(self):
        """Method for getting the table`s end row.
        
        :return: end row
        :rtype: int
        """
        return self.table_end[1]

    def get_out_header(self, idx):
        """Method for pretty printing the table`s identifier.
        
        :return: formatted header
        :rtype: str
        """
        table_s = "TABLE_ID: {id}".format(id=idx)
        header_s = "{frame}\n{header}\n{frame}".format(header=table_s, frame="-" * len(table_s))
        return header_s
