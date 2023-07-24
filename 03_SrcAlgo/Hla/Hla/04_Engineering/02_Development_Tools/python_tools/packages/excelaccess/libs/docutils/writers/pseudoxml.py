# $Id: pseudoxml.py 1.1 2018/03/15 10:44:13CET Mutschler, Matthias (uidv7867) none  $
# Author: David Goodger <goodger@python.org>
# Copyright: This module has been placed in the public domain.

"""
Simple internal document tree Writer, writes indented pseudo-XML.
"""

__docformat__ = 'reStructuredText'


from docutils import writers


class Writer(writers.Writer):

    supported = ('pprint', 'pformat', 'pseudoxml')
    """Formats this writer supports."""

    config_section = 'pseudoxml writer'
    config_section_dependencies = ('writers',)

    output = None
    """Final translated form of `document`."""

    def translate(self):
        self.output = self.document.pformat()

    def supports(self, format):
        """This writer supports all format-specific elements."""
        return True
