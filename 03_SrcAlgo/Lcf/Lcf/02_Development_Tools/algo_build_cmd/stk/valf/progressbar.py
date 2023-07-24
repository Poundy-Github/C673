"""
stk/valf/progressbar
----------------

Textbased Progressbar

:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:53CET $
"""
# Import Python Modules -------------------------------------------------------
import sys

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class ProgressBar:
    """ Creates a text-based progress bar. Call the object with the `print'
        command to see the progress bar, which looks something like this:

        [##########        22%                ]

        You may specify the progress bar's width, min and max values on init.
    """
    def __init__(self, minValue=0, maxValue=100, totalWidth=50, multiline=False):
        self.__progress_bar = "[]"
        self.__min = minValue
        self.__max = maxValue
        self.__span = maxValue - minValue
        self.__width = totalWidth
        self.__amount = 0
        self.__updateAmount(0)
        self.__old_amount = 0

        self.__multiline = multiline

        self.__old_progBar = "[]"

    def __updateAmount(self, newAmount=0):
        """ Update the progress bar with the new amount (with min and max
            values set at initialization; if it is over or under, it takes the
            min or max value as a default. """
        if newAmount < self.__min:
            newAmount = self.__min
        if newAmount > self.__max:
            newAmount = self.__max

        self.__amount = newAmount

        # Figure out the new percent done, round to an integer
        diffFromMin = float(self.__amount - self.__min)
        percentDone = int(round((diffFromMin / float(self.__span)) * 100.0))

        # Figure out how many hash bars the percentage should be
        allFull = self.__width - 2
        numHashes = int(round((percentDone / 100.0) * allFull))

        # Build a progress bar with an arrow of equal signs; special cases for
        # empty and full
        if numHashes == 0:
            self.__progress_bar = "[=%s]" % ('=' * (allFull - 1))
        elif numHashes == allFull:
            self.__progress_bar = "[%s]" % ('#' * allFull)
        else:
            self.__progress_bar = "[%s%s]" % ('#' * (numHashes),
                                              '=' * (allFull - numHashes))

        # figure out where to put the percentage, roughly centered
        percentPlace = (len(self.__progress_bar) / 2) - len(str(percentDone))
        percentString = str(percentDone) + "%"

        # slice the percentage into the bar
        self.__progress_bar = ''.join([self.__progress_bar[0:percentPlace],
                                      percentString,
                                      self.__progress_bar[percentPlace + len(percentString):]])

    def __str__(self):
        return str("[PROCESS] " + self.__progress_bar)

    def __call__(self, value):
        """ Updates the amount, and writes to stdout. Prints a carriage return
            first, so it will overwrite the current line in stdout."""

        self.__old_progBar = self.__progress_bar

        self.__updateAmount(value)

        if self.__multiline:
            sys.stdout.write('\n')
        else:
            tmp = self.__width + 11
            sys.stdout.write('\r' * tmp)

        sys.stdout.write(str(self))
        sys.stdout.flush()
        if self.__multiline:
            sys.stdout.write('\n\n')
        elif self.__amount >= self.__max:
            sys.stdout.write('\n')
            sys.stdout.write('\r' * tmp)
            sys.stdout.write(' ' * tmp)
            sys.stdout.write('\r' * tmp)
            sys.stdout.write('\nDone...\n\n')
            # stdout.flush()

        self.__old_amount = self.__amount


"""
$Log: progressbar.py  $
Revision 1.1 2021/12/13 17:59:53CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.9 2013/07/04 11:17:47CEST Hospes, Gerd-Joachim (uidv8815) 
changes for new module valf:
- process_manager initiates data_manager at init instead of load_config
- bpl uses correct module path
- processbar with simple 'include sys' to redirect process bar output
- Added comments -  uidv8815 [Jul 4, 2013 11:17:47 AM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.8 2013/04/03 08:02:15CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:15 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/01 10:23:25CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:25 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/28 08:12:17CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:18 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 17:55:10CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:11 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/27 16:19:54CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:55 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/26 20:18:07CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:18:08 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/19 21:16:25CET Hecker, Robert (heckerr)
Updates after Pep8 Styleguides..
--- Added comments ---  heckerr [Feb 19, 2013 9:16:26 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:09CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.4 2010/06/28 13:46:24CEST smogos
* added configuration manager
--- Added comments ---  smogos [2010/06/28 11:46:25Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.3 2010/03/19 10:40:25EET Sorin Mogos (smogos)
* code customisation and bug fixes
--- Added comments ---  smogos [2010/03/19 08:40:26Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.2 2010/02/18 15:30:58EET Sorin Mogos (smogos)
* code optimisation and bug-fixes
--- Added comments ---  smogos [2010/02/18 13:30:58Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.1 2009/10/30 14:18:45EET dkubera
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/ETK_EngineeringToolKit/04_Engineering/VALF_ValidationFrame/
04_Engineering/31_PyLib/project.pj
"""
