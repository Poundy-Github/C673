# $Id: null.py 1.1 2018/03/15 10:31:02CET Mutschler, Matthias (uidv7867) none  $
# Author: Martin Blais <blais@furius.ca>
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
