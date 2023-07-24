# Author: Martin Blais
# Contact: blais@furius.ca
# Revision: $Revision: 1.1 $
# Date: $Date: 2021/12/13 18:27:18CET $
# Copyright: This module has been placed in the public domain.

"""A do-nothing parser."""

from docutils import parsers


class Parser(parsers.Parser):

    """A do-nothing parser."""

    supported = ('null',)

    config_section = 'null parser'
    config_section_dependencies = ('parsers',)

    def parse(self, inputstring, document):
        pass
