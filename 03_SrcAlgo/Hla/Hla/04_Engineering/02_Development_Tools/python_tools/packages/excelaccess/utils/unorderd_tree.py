"""
@author: uidq3472
"""

from collections import OrderedDict


class TreeNode:
    """Base class for a node in a tree-like structure.
    
    :param str title: header field
    :param parent: parent element if there is one
    :type parent: TreeNode or None
    :param int row_index: row index of this field for better determination and for indexing of data
    :param int column_index: column index of this field for better determination and for indexing of data
    :param int column_offset: absolute column offset if table does not start at 0 in Excel
    :param int row_offset: absolute row offset if table does not start at 0 in Excel
    """

    def __init__(self, title, parent=None, row_index=0, column_index=0, column_offset=0, row_offset=0):
        # TODO: docu + better solution for information in here? more general? e.g. dict to store stuff
        self.title = title
        self.parent = parent
        self.column_offset = column_offset
        self.row_offset = row_offset
        self.column_index = column_index
        self.row_index = row_index
        self.children = OrderedDict()  # (title, node)

    def add_child(self, child):
        """Adds a child to the calling node.
        
        :param TreeNode child: a child node to be added
        """
        if child.title in self.children:
            return False
        else:
            child.parent = self
            self.children[child.title] = child
            # root column offset; if we need to compute relative instead of absolute indices
            child.row_offset = self.row_index
            child.column_offset = self.column_index
            return True

    def get_child(self, child_title):
        """Returns the node's title.
        
        :return: node's title
        :rtype: str
        """
        return self.children.get(child_title)

    def get_absolute_row(self):
        """Returns the absolut row index.
        
        :return: absolute row index
        :rtype: int
        """
        return self.row_index

    def get_absolute_column(self):
        """Returns the absolute column index.
        
        :return: absolute column index
        :rtype: int
        """
        return self.column_index

    def get_relative_row(self):
        """Returns the relative row index. I.d. subtracting the row offset.
        
        :return: relative row index
        :rtype: int
        """
        return self.row_index - self.row_offset

    def get_relative_col(self):
        """Returns the relative column index. I.d. subtracting the column offset.
        
        :return: relative column index
        :rtype: int
        """
        return self.column_index - self.column_offset


class RootNode(TreeNode):
    """Inherited class of TreeNode. Its purpose is only too provide an empty base root. That is needed because of flat header hierarchies.
    
    :param int column_offset: absolute column offset if table does not start at 0 in Excel
    :param int row_offset: absolute row offset if table does not start at 0 in Excel
    """

    def __init__(self, column_offset=0, row_offset=0):
        TreeNode.__init__(self, "RootNode", None, column_offset=column_offset, row_offset=row_offset)


def search(node, ordered_titles_list):
    """"""
    # TODO: fill ; make for more than one 'path'?
    if len(ordered_titles_list) < 1:
        return node
    child = node.get_child(ordered_titles_list[0])
    if child is not None and len(ordered_titles_list) > 0:
        search(child, ordered_titles_list[1:])


def get_leave_nodes(node):
    """Returns leave nodes starting at the given node.
    
    :param TreeNode node: the node to start at
    :return: list of leave nodes
    :rtype: list(TreeNode)
    """
    leaves = None
    if len(node.children.keys()) > 0:
        # has child nodes, cannot be a leave
        leaves = leaves if leaves else []
        for _, child in node.children.items():
            leaves.extend(get_leave_nodes(child))
        return leaves
    else:
        # node is a leave
        return [node]


def print_tree(src, depth=1, return_function=None):
    """Prints a tree.
    
    :param src: tree node
    :type: TreeNode
    :param int depth: depth of indent
    :param return_function: lambda for return type, defaults to node.title
    :return: string representation of a tree
    :rtype: str
    """
    if return_function is None:
        return_function = lambda node: node.title

    tabs = lambda n: ' ' * max((n - 1, 0)) * 4  # or 2 or 8 or...
    brace = lambda s, n: '%s%s%s' % ('[' * n, s, ']' * n)

    out_str = ""

    # if is TreeNode, has a name and a dict of TreeNodes (maybe empty but no matter): recursive call
    if isinstance(src, TreeNode):
        out_str += tabs(depth) + brace(return_function(src), depth) + "\n"
        out_str += print_tree(src.children, depth, return_function)
    # if is OrderedDict there might be more nodes inside
    elif isinstance(src, OrderedDict):
        for _, value in src.items():
            out_str += print_tree(value, depth + 1, return_function)

    return out_str


def get_leave_lambda(node, return_function):
    """Returns leave nodes starting at the given node.
    
    :param TreeNode node: the node to start at
    :param return_function: lambda for return type
    :return: list of leave nodes
    :rtype: list(TreeNode)
    """
    leaves = None
    if len(node.children.keys()) > 0:
        # has child nodes, cannot be a leave
        leaves = leaves if leaves else []
        for _, child in node.children.items():
            leave_val = get_leave_lambda(child, return_function)
            leaves.extend(leave_val if hasattr(leave_val, "__iter__") else [leave_val])
        return leaves
    else:
        # node is a leave
        return return_function(node)


def get_leave_lambda_dict(node, return_function):
    """Returns leave nodes starting at the given node.
    
    :param TreeNode node: the node to start at
    :param return_function: lambda for return type
    :return: dict
    :rtype: dict()
    """
    leaves = None
    if len(node.children.keys()) > 0:
        # has child nodes, cannot be a leave
        leaves = leaves if leaves else {}
        for _, child in node.children.items():
            leaves.update(get_leave_lambda_dict(child, return_function))
        return leaves
    else:
        # node is a leave
        return return_function(node)
