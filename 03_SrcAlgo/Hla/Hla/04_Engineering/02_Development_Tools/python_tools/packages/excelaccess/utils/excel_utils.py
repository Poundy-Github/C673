"""
@author: uidq3472
"""

import re
import regex_patterns as rp


def parse_cell_idx(cell_str):
    """Parses Excel indices to int. (not 'zero indexed', standard Excel index range)
    
    :param str cell_str: cell in Excel notation
    :return: (row, column)
    :rtype: (int, int)
    """
    column = 0
    match_letters = re.search(rp.excel_index_numbers, cell_str)
    row = int(match_letters.group(1))
    match_numbers = re.search(rp.excel_index_letters, cell_str)
    for char in match_numbers.group(1):
        column = column * 26 + (ord(char.upper()) - ord("A")) + 1

    return row, column


def parse_cell_idx_zero(cell_str):
    """Uses above parse function and shifts indices by 1. ('zero indexed')
    
    :param str cell_str: cell in Excel notation
    :return: (row - 1, column - 1)
    :rtype: (int, int)
    """
    row, column = parse_cell_idx(cell_str)
    return (row - 1), (column - 1)


def is_last(list_object, list_item):
    """Simple check for last elment of a list.
    
    :param list list_object: a list
    :param list_item: item to check
    :return: if item is last item
    :rtype: Boolean
    """
    if list_object[-1] is list_item:
        return True
    else:
        return False


def is_old_excel_format(excel_file_path):
    """Simple check for Excel format by file ending.
    
    :param str excel_file_path: a (relative) path to an Excel file
    :return: True if is old, False if not and None if none of them applies
    :rtype: Boolean or None
    """
    if excel_file_path.endswith((".xls", ".xlm", ".xlt")):
        return True
    elif excel_file_path.endswith((".xlsx", ".xlsm", ".xltx", ".xltm")):
        return False
    else:
        return None
