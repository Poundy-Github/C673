# $Id: null.py 1.1 2018/03/15 10:44:13CET Mutschler, Matthias (uidv7867) none  $
# Author: David Goodger <goodger@python.org>
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
