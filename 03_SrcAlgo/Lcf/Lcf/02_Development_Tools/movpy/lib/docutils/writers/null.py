# Author: David Goodger
# Contact: goodger@python.org
# Revision: $Revision: 1.1 $
# Date: $Date: 2021/12/13 18:28:21CET $
# Copyright: This module has been placed in the public domain.

"""
A do-nothing Writer.
"""

from docutils import writers


class Writer(writers.UnfilteredWriter):

    supported = ('null',)
    """Formats this writer supports."""

    config_section = 'null writer'
    config_section_dependencies = ('writers',)

    def translate(self):
        pass
