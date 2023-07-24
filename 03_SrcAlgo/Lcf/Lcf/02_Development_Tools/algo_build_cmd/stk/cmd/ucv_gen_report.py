"""
fct\cgeb\usecase
----------------

put the constraint visualization in a pdf

:org:           Continental AG
:author:        Oliver Weinhold

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:34CET $


====================================================================
 Log
====================================================================
Log:
$Log: ucv_gen_report.py  $
Revision 1.1 2021/12/13 17:55:34CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.2 2013/12/06 14:51:02CET Weinhold, Oliver (uidg4236) 
Adapt to new signature of UseCaseValidator.__init__()
- Added comments -  uidg4236 [Dec 6, 2013 2:51:02 PM CET]
Change Package : 208496:1 http://mks-psad:7002/im/viewissue?selection=208496
Revision 1.1 2013/12/05 14:17:03CET Weinhold, Oliver (uidg4236) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/cmd/project.pj
"""

#====================================================================
# System Imports
#====================================================================

from argparse import ArgumentParser
from re import search as research
from os import environ, getcwd, path
from sqlite3 import connect
import sys

#====================================================================
# Local Imports
#====================================================================

STK_FOLDER = path.abspath(path.join(path.split(__file__)[0], r"..\.."))

if STK_FOLDER not in sys.path:
    sys.path.append(STK_FOLDER)

#====================================================================
# Local Imports
#====================================================================

import stk.db.cl.cl as cl
import stk.img as val_plot
import stk.rep as rep
import stk.rep.report_base as rep_base
from stk.db.cl.cl import SQLite3BaseCLDB, BaseCLDBException, OracleBaseCLDB
from stk.rep import ValidationReportBase
from stk.rep.report_base import BaseReportLabGenerator
from stk.rep.report_base import PdfReport
from stk.val.ucv import UcvPlot
from stk.db.db_connect import DBConnect

#====================================================================
# Constants
#====================================================================


#====================================================================
# Helper Functions
#====================================================================


#====================================================================
# Classes
#====================================================================

class UcvGenReport(PdfReport):
    """
    Write a pdf report with constraint visualizations.  Default mode of operation is to create one section in the
    report with one subsection for every constraint set.  Each of the subsections then contains a subsubsection for
    each of its constraints, with one plot for each constraint.
    """

    def __init__(self, report_title, outfile_path_name, cl_connection, cat_connection):
        """
        :param report_title: Name of report, printed on first page
        :param outfile_path_name: full path to the ouput file
        :param db_connector: represents db object
        """
        self.outfile_path_name = outfile_path_name
        PdfReport.__init__(self, report_title=report_title, outfile_path_name=outfile_path_name)
        self._cl = cl_connection
        self._cat = cat_connection
        self.plotter = val_plot.ValidationPlot(path.dirname(outfile_path_name))

    def __del__(self):
        pass

    def DefaultGenerator(self, constraint_set_id_list):
        """
        Visualize all constraint sets referenced by constraint_set_id_list.  For each constraint set generate a 
        SubSection with all of its constraints plotted in one SubSubsection.
        :parameter constraint_set_id_list: for example get these via cl.getConstraintSetIDs()
        :type constraint_set_id_list: list of int
        """
        self.AddSection('All Constraint Sets')
        for constraint_set_id in constraint_set_id_list:
            self._AddSubsectionFromConstraintSet(constraint_set_id, 'Constraint Set ' + str(constraint_set_id),
                                                 constraint_list_list=None, constraint_list_names=None)


    def _AddSubsectionFromConstraintSet(self, constraint_set_id, subsection_name, constraint_list_list=None,
                                        constraint_list_names=None):
        """
        Add one SubSection to the report.  Don't call directly, use AddSectionFromConstraintSet(), because
        adding a SubSection without adding a Section results in a ValueError from self.BuildReport().
        Default content of the SubSection is one SubSubSection as constructed by
        _AddSubsubsectionFromConstraintList() that contains all the constraints in the set.  Deviate from that 
        default with parameter constraint_list_list.
        :param constraint_set_id: constraint set to extract constraints from, which are plotted in a SubSubSection.
        :type constraint_set_id: get this from a DB, e.g. using cl.getConstraintSetIDs() 
        :param subsection_name: SubSection header in the report
        :param constraint_list_list: group  the constraints of set constraint_set to lists of constraints that should
            be plotted together.
        :type constraint_list_list: list of list of ints
        :param constraint_list_names: names for 
        :type constraint_list_names: list of string
        """
        consSet_maps = self._cl.getConsMap(constraint_set_id, col=cl.COL_NAME_CONMAP_SETID)
        constraint_list = []
        for i in range(len(consSet_maps)):
            _ = consSet_maps[i][cl.COL_NAME_CONMAP_CONSID]
            constraint_list.append([self._cl.getSigConstraint(_)])

# TODO: OLIVER: handling of constraint_list_list: postponed
#        if constraint_list_list:
#            pass
#        else:
#            constraint_list_list = [constraint_list]
#            subsubsection_names = ['All Constraints of Set ' + str(constraint_set_id)]
# OLIVER: handling of constraint_list_list: postponed
        constraint_list_list = [constraint_list]
        subsubsection_names = ['Constraint ' + str(constraint_set_id)]

        self.AddSubSection(subsection_name)
        for i in range(len(constraint_list_list)):
            for j in range(len(constraint_list_list[i])):
                self._AddSubsubsectionFromConstraintList(constraint_list_list[i][j],
                                                         subsubsection_names[i] + '_' + str(j))


    def _AddSubsubsectionFromConstraintList(self, constraint_list, subsubsection_name):
        """
        Add one SubSubSection to the report.  Don't call directly, use _AddSubsectionFromConstraintSet(), because
        adding a SubSubSection without adding a SubSection and Section results in a ValueError from self.BuildReport().
        :param constraint_list: the constraints that are to be put into single subplots of one figure
        type constraint_list: list of list of dict
        :param subsubsection_name: SubSubSection header in the report
        """
        self.AddSubSubSection(subsubsection_name)
        constraint_names = []
        for single_constraint in constraint_list:
            constraint_names.append([str(single_constraint[0]['CONSID'])])
        self.AddPlotsToDocument(constraint_list=constraint_list, constraint_names=constraint_names)


    def AddPlotsToDocument(self, constraint_list, constraint_names, show_grid=False, keep_time_offset=True):
        """
        Add one plot to the pdf document.  The plot is constructed from constraint_list.  Use parameters as for
        UcvGenReport.PlotConstraints().
        The constraints in constraint_list are put into one figure each.        
        :param constraint_list: the constraints that are to be put in the figures
        """
        n_constraints = len(constraint_list)
        ucvp = UcvPlot(self._cl, self._cat)
        for i, single_constraint in enumerate(constraint_list):
            plt = ucvp.PlotConstraints([constraint_list[i]], constraint_names=constraint_names[i],
                                        x_label='t [s]', y_label='tbd', single_figures=True,
                                        show_grid=show_grid, plotter=self.plotter, titles=[''],
                                        show_plots=False, keep_time_offset=keep_time_offset)
            buffer = self.plotter.GetPlotDataBuffer(grid=show_grid)
            drawing = self.plotter.GetDrawingFromBuffer(buffer, width=450, height=150) # don't give parameter file_name! Else: Only one plot in buffer
#            self.InsertImage("Constraint list", drawing)
            self.InsertImage('Constraint' + str(constraint_names[i][0]), drawing)
        #test drawing.save(['gif'], outDir='D:\\aa', title=str(time.time()), fnRoot=str(time.time()), bmFmt='png')


if __name__ == '__main__':
    opts = ArgumentParser(description="Generate a pdf with constraint plots, by default ordered by Constraint Sets")
    opts.add_argument("-m", "--mode", dest="mode", default=0, type=int,
                      help="Mode of operation.\n0 for DefaultGenerator --> all ConstraintSets as Subsections")
    opts.add_argument("-f", "--db_file", dest="db_file_name",
                      help="Full path to database file from which to read constraints")
    opts.add_argument("-d", "--out_file_path", dest="out_file_path", default=getcwd(),
                      help="Full path to the generated file, excluding file name")
    opts.add_argument("-o", "--out_file_name", dest="out_file_name", default='Default_Report.pdf',
                      help="File name, excluding path")
    opts.add_argument("--report_title", dest="report_title", default='Default Report',
                      help="Title of the generated report")
    args = opts.parse_args()

    db = connect(args.db_file_name)
    _cl = SQLite3BaseCLDB(db)
    _cat = OracleBaseCLDB(db)

    if args.mode == 0:
        ugr = UcvGenReport(args.report_title, path.join(args.out_file_path, args.out_file_name), _cl, _cat)
        constraint_set_ids = _cl.getConstraintSetIDs()
        ugr.DefaultGenerator(constraint_set_ids)
        ugr.BuildReport()

