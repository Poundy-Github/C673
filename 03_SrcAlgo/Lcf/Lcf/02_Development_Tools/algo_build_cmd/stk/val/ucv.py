"""
stk/val/ucv
-----------

Module for the UseCaseValidation.

usage Constraint Load over MeasID or ConstraintName
---------------------------------------------------
.. python::

    #Create Instance of Use Case Validator
    ucv = UseCaseValidator()

    #Load constraints based on a given measurement file or constraint name
    # and retrieve a class containing information on constraints,
    # which are needed to perform the UseCaseValidation
    # do either:
    MeasID = 35287
    CompData = ucv.loadConstraintsByMeasID(MeasID)

    # or:
    ConstraintName = "HLA_Blend_Time_CL"
    CompData = ucv.loadConstraintsByName(ConstraintName)

    # Now, get the Signal Data from VALF, BSIG, etc.
    # and fill it into the CompareData's class (Signal), e.g.:
    for idx in range(len(CompData.ID)):
        CompData.Signal[idx] = bsig.get_signal_by_name2(CompData.Signal[idx], CompData.Length[idx]):

    # Feed the SignalData back into the UseCaseValidation
    # and do the final compare.
    result = ucv.compare(CompData)

    if(result is True):
        print "Test passed!"
    else:
        print "Test failed!"


:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:46CET $
"""

# pylint: disable=W0141

# Import Python Modules -----------------------------------------------------------------------------------------------
from numpy import array, zeros, ones, convolve, concatenate, all as npall
import logging

# Local Imports -----------------------------------------------------------------------------------------------

import stk.db.cl.cl as cl
from stk.db.cat import cat
import stk.img.plot as stk_plot

# Defines -------------------------------------------------------------------------------------------------------------

SHOW_PLOTS_DEFAULT = False

# Functions -----------------------------------------------------------------------------------------------------------


# TODO: what is this used for? really needed for ucv???
def signalCompare(signal1, signal2, diff, discrete=None):
    """compare two signals with given difference against each other
    if dicrete state changes are given, e.g. [0, 1] to be checked when signal raises to 1 from 0,
    indices are calculated and those are compared. By using an algo signal, each frame is of about 60ms.
    So 1/0.12 (half) => 8.3 would be half the diff (+-) to check state changes within 1 second inside a recording.

    :param signal1: the first signal list to compare signal2 against
    :param signal2: the second signal list
    :param diff: allowed difference [+- value]
    :param discrete: check for a discrete signal change, e.g. [[0, 1], [1, 0]]
    :return: True if (signal2 - diff) <= signal1 <= (signal2 + diff) else False
    """
    if type(signal1) != type(array):
        signal1 = array(signal1)
    if type(signal2) != type(array):
        signal2 = array(signal2)

    if discrete is not None:
        # we also can check wether discrete is int, float or long and occures in signals
        if type(discrete) not in (list, tuple):
            discrete = [discrete]
        # continue to create list of list
        if type(discrete[0]) not in (list, tuple):
            discrete = [discrete]
        # transform to continuous signal, zeroed the result before as signals were from different SW versions
        signal1 = [i for i in xrange(len(signal1)) for k in discrete if npall(signal1[i:i + len(k)] == k)]
        signal2 = array([i for i in xrange(len(signal2)) for k in discrete if npall(signal2[i:i + len(k)] == k)])

    # final check
    return len(signal1) == len(signal2) and npall((signal2 - diff) <= signal1) and npall(signal1 <= (signal2 + diff))


def ConstructConstraintBox(single_constraint, keep_time_offset):
    """
    Construct the data field for the GeneratePlot function of class ucv_plot
    for visualizing a constraint as a box, something like this:                 +----------+
                                                                                |          |
                                                                                |          |
                                                                                +----------+
    :param single_constraint: the constraint to visualize
    :type single_constraint: list of dict, e.g. [{'LOWERTOL': 0.0, 'COEFFB': ...}]
    :param keep_time_offset: True to plot from begints to endts, False to plot starting at 0
    """
    single_constraint = single_constraint[0]
    begints = single_constraint[cl.COL_NAME_SIGCON_BEGINTS]
    endts = single_constraint[cl.COL_NAME_SIGCON_ENDTS]
    coeffa = single_constraint[cl.COL_NAME_SIGCON_COEFA]
    coeffb = single_constraint[cl.COL_NAME_SIGCON_COEFB]
    uppertol = single_constraint[cl.COL_NAME_SIGCON_UPPERTOL]
    lowertol = single_constraint[cl.COL_NAME_SIGCON_LOWERTOL]
    if keep_time_offset:
        x = [begints, begints, endts, endts, begints]
        y = [coeffb + uppertol, coeffb - lowertol,
             coeffa * endts + coeffb - lowertol, coeffa * endts + coeffb + uppertol,
             coeffb + uppertol]
    else:
        t_end = endts - begints
        x = [0, 0, t_end, t_end, 0]
        y = [coeffb + uppertol, coeffb - lowertol,
             coeffa * t_end + coeffb - lowertol, coeffa * t_end + coeffb + uppertol,
             coeffb + uppertol]
    return x, y

# Classes -------------------------------------------------------------------------------------------------------------

#  CompData class looks like following:
# class CompareData(object):
#     def __init__(self):
#         self.ID = []
#         self.MeasID = []
#         self.SigName = []
#         self.StartTS = []
#         self.EndTS = []
#         self.Signal = []
# Whereas each constraint is organized along one index,
# e.g. all data at index 0 belongs to first constraint.


class UseCaseValidator(object):
    """class for being able to validate use cases
    TODO: add more description...
    """

    def __init__(self, cl_connection, cat_connection):
        """
        UseCaseValidator uses BaseCLDB, which needs to be initialized outside.
        :param cl_connection: represents BaseCLDB object
        :param cat_connection: represents BaseRecCatalogDB object
        """
        self._cld = cl_connection
        self._consSet = None

        self.__RecCatDB = cat_connection
        self.__RecCatDB.Initialize()

    def loadConstraintsByName(self, consSetName):
        """
        Load the Constraints from the Constraint DataBase.
        :param consSetName: constratint set name to reference on.
        :return: True/False for successfull loading.
        """
        return self.loadConstraints(consSet=consSetName)

    def loadConstraintsByMeasID(self, measID):
        """
        Load the Constraints from the Constraint DataBase.
        :param measID: measurement to reference on. Integer = CAT number, str = recfilename.
        :return: True/False for successfull loading.
        """

        return self.loadConstraints(measid=measID)

    def loadConstraints(self, consSet=None, measid=None):
        """
        Load the Constraints from the Constraint DataBase.
        The selection for the correct ConstraintSet will be done via
        the MeasID or constraint set name.
        :param consSet: set name to reference on.
        :param measid: measurement to reference on. Integer = CAT number, str = recfilename.
        :return: True/False for successfull loading.
        """
        if isinstance(measid, str):
            measid = self.__RecCatDB.GetMeasurementID(measid)

        self._consSet = self._cld.getConstraints(consSet, measid)

        value_dict = {}
        for value in self._consSet.value:
            value_dict.update(value)
        value_dict[cl.KID_NAME_SETID] = self._consSet.ident
        value_dict[cl.KID_NAME_KIDIDS] = self._consSet.allKidIDs

        sigcons = type('CompareData', (), value_dict)

        return sigcons

    def getConstraintSignals(self):
        """
        Get all signal ids and names that belong to the current constraint set

        :return: signals {dict}
        """
        signals = {}
        for values_per_subset in self._consSet.values:

            #get constraints
            # TODO: replace magic numbers
            constr_list = values_per_subset[1][0][cl.KID_VALUENAME_CONSTRAINTS]
            for constr in constr_list:

                #get one signal
                sig_id = constr[cl.COL_NAME_SIGCON_SIGNALID]
                if not sig_id in signals:
                    sig_details = self._cld.getConsSignal(sig_id)
                    signals[sig_id] = sig_details[0][cl.COL_NAME_CONSIG_NAME]

        return signals

    def compare(self):
        """
        Perform a comparision between the internal loaded constraints
        and the Signal Data

        :return: True/False (Comparision Result)
        """
        # evaluate kids
        self._consSet.evalKids(self.checkConstrSet)

        return self._consSet.result

    def addCompareData(self, compData):
        """Add given input data to Trie
        :compData: input data to compare [dict]
        """

        # append the signal from compData to the kid
        # TODO: what if compData belongs only to special kid?
        # for idx in xrange(len(compData.ID)):
        for set_id in self._consSet.allIDs:
            # if compData.Signal != []:
                # self._consSet.appendValue(compData.ID[idx], compData.Signal[idx])
            self._consSet.appendValue(set_id, compData)

        return

    def _getCompareResultDetails(self, consSet):
        """generate overview about all compare results and its logical operant in one constraint set
        :param consSet: constraint set from with get its detailed results [trie object]
        :return details: compare result details [dict]
        """

        details = {}

        operant = cl.CL_OP_NAME_MAP[consSet.value[0][cl.KID_VALUENAME_OPERANT]]
        details[consSet.ident] = [operant,
                                  consSet.value[0][cl.KID_VALUENAME_COMP_RESULTS][cl.KID_VALUENAME_COMP_DETAILS]]

        for kid in consSet.kids:
            details[consSet.ident][-1].append({kid.ident: kid.result})
            details.update(self._getCompareResultDetails(kid))

        return details

    def getCompareResultDetails(self):
        """
        Return a List of classes with details of every constrain set.

        Every Class should contain:
            - Constriaint ID
            - Pass/Fail Result
            - Timestamp info where first failed happened.
            - .....

        :return: List of Classes
        """
        # TODO: depends on the outcome of checkConstraint

        details = self._getCompareResultDetails(self._consSet)

        return details

    def checkConstraint(self, constraint):  # pylint: disable=R0201
        """check all constraints of one set
        :param constraint: one set to compare
        :return: true/false or None if compare was not performed properly
        :TODO in future:
                0 - passed
                1 - ... TODO
                etc
        """
        #TODO: constraint was meant to be only 1 check, does extending it to set of constrains need any other changes
        #somewhere else?

        #TODO: WARNING: constraint is a reference to self._consSet.value - that is used to return check results!

        return_result = None
        check_results = []

        for cons in constraint[0][cl.KID_VALUENAME_CONSTRAINTS]:

            cons_signal_name = self._cld.getConsSignal(cons[cl.COL_NAME_SIGCON_SIGNALID])
            cons_signal_name = cons_signal_name[0][cl.COL_NAME_CONSIG_NAME]

            if cons_signal_name in constraint[1][cl.KID_VALUENAME_SIGNALS]:

                # build up comp_signal = input signal
                cons_begin_time = cons[cl.COL_NAME_SIGCON_BEGINTS]
                cons_end_time = cons[cl.COL_NAME_SIGCON_ENDTS]

                # TODO: what if timestamp is not exactly matching?
                begin_index = constraint[1][cl.KID_VALUENAME_SIGNALS][cl.SIGCON_DEFAULT_TRIGGER].index(cons_begin_time)
                end_index = constraint[1][cl.KID_VALUENAME_SIGNALS][cl.SIGCON_DEFAULT_TRIGGER].index(cons_end_time)

                comp_signal = constraint[1][cl.KID_VALUENAME_SIGNALS][cons_signal_name][begin_index:end_index + 1]

                # build up cons_signal = constraint signal
                slope = float(cons[cl.COL_NAME_SIGCON_COEFA])
                y_intercept = float(cons[cl.COL_NAME_SIGCON_COEFB])
                cons_signal = zeros(len(comp_signal))
                for i in range(len(cons_signal)):
                    cons_signal[i] = slope * i + y_intercept

                # evaluate upper and lower boundary

                # problem with upper / lower bounds with extreme slope
                # we could use e.g. constraint[2|3] = ca / math.cos(math.atan(constraint[2|3]))
                # where constraint[2] = cons[cl.COL_NAME_SIGCON_UPPERTOL]
                #       constraint[3] = cons[cl.COL_NAME_SIGCON_LOWERTOL]
                uCons = cons_signal + cons[cl.COL_NAME_SIGCON_UPPERTOL]
                lCons = cons_signal + cons[cl.COL_NAME_SIGCON_LOWERTOL]

                # TODO: for method getCompareResultDetails, we need to save the result
                # to be able to see which constraint failed.
                # e.g. by splitting all up and make 0 - Pass, >0 - fail with message

                # compare if each value of comp_signal is in range of lower and upper bound
                cmpRes = (lCons <= comp_signal) & (comp_signal <= uCons)

                # evaluate min and max valid consecutive samples
                min_samples = cons[cl.COL_NAME_SIGCON_MINSAMPLES]
                max_samples = cons[cl.COL_NAME_SIGCON_MAXSAMPLES]

                # TODO: both 0 or both None?
                if min_samples + max_samples == 0:  # if not given, all values must be in range
                    result = sum(cmpRes) == len(comp_signal)

                else:
                    # check min and max of consecutives
                    cmpRes = convolve(cmpRes, concatenate([ones(min_samples, dtype=int),
                                                           zeros(len(comp_signal) - min_samples, dtype=int)]))
                    mx = cmpRes.max()  # max lenght of consecutive samples inside bounds
                    result = mx == min_samples and (cmpRes == mx).sum() + mx - 1 <= max_samples

                # collect results of each constraint in this set
                check_results.append(result)

            else:
                logging.warning('signal "%s" to compare not given, skip this constraint', cons_signal_name)

        # get overall result
        if len(check_results) > 0:
            return_result = eval(cl.CL_OP_FUNC_MAP[constraint[0][cl.KID_VALUENAME_OPERANT]] % check_results)

        # save results to self
        constraint[0][cl.KID_VALUENAME_COMP_RESULTS][cl.KID_VALUENAME_COMP_DETAILS] = check_results
        constraint[0][cl.KID_VALUENAME_COMP_RESULTS][cl.KID_VALUENAME_COMP_SUM] = return_result

        # return
        return return_result

    def checkConstrSet(self, constr_set_trie):
        """check all constraints in a trie
        :param constr_set_trie: one trie to compare
        :return: true/false
        :TODO in future:
                0 - passed
                1 - ... TODO
                etc
        """

        constr_result = self.checkConstraint(constr_set_trie.value)
        details = constr_set_trie.value[0][cl.KID_VALUENAME_COMP_RESULTS][cl.KID_VALUENAME_COMP_DETAILS]

        kid_results = []
        all_kids = constr_set_trie.kids
        for kid in all_kids:
            kid_results.append(kid.result)

        all_results = details + kid_results

        # get overall result
        if len(all_results) > 0:
            return_result = eval(cl.CL_OP_FUNC_MAP[constr_set_trie.value[0][cl.KID_VALUENAME_OPERANT]] % all_results)

        return return_result

    #==================================================================================================================
    # constraint handling
    #==================================================================================================================

    def retrieveConstraints(self, measID):
        """retrieves all constraints by given measurement id
        :param measID: measurement ID
        """
        return self._cld.getConstraintsByMeas(measID)


class UcvPlot(UseCaseValidator):
    """
    Visualize constraints only.  No handling of signals.  Connection to a DB is necessary to get a grip on constraint
    sets, since they don't have a python representation like single constraints do (single constraints are lists of
    dicts).  Relies heavily on the stk ValidationPlot class.  Matplotlib axes resp. stk_plot.ValidationPlot instances
    can be passed to most functions (as parameter axes resp. plotter) to add constraint visualization to these
    axes/plots.  Check test_add_constraint_plot_to_signal_plot from test_ucv_plot.py for an example.
    """

    def __init__(self, cl_connection, cat_connection):
        UseCaseValidator.__init__(self, cl_connection, cat_connection)
        self.constraint_line_color = ['b']
        self.constraint_line_style = ['--']
        self._db = cl_connection

    def __del__(self):
        pass

    def GetConstraintLineColor(self):
        return self.constraint_line_color

    def GetConstraintLineStyle(self):
        return self.constraint_line_style

    def SetConstraintLineColor(self, index):
        self.constraint_line_color = stk_plot.DEF_COLORS[index]

    def SetConstraintLineStyle(self, index):
        self.constraint_line_style = stk_plot.DEF_LINE_STYLES[index]

    def PlotConstraints(self, constraint_list, constraint_names=[], x_label='t [s]', y_label='tbd', titles=[''],
                        show_grid=False, show_plots=SHOW_PLOTS_DEFAULT, single_figures=False, keep_time_offset=True,
                        axes=None, plotter=None):
        """
        Plot boxes to visualize constraints.
        :param constraint_list: the constraints.
        :type constraint_list: list of lists of dict
        :param constraint_names: names for legend
        :param x_label: x-axis label
        :param y_label: y-axis label
        :param titles: list of plot titles (list with one item if single_figures == False)
        :param show_grid: figure property for grid display
        :param show_plots: show the figure or figures
        :param single_figures: True gives one figure window per constraint,
            False gives one plot with ALL constraints combined
        :param keep_time_offset: if true use original constraint time stamps,
            else plot in interval [0, endts - begints]
        :param axes: axis on which the plot is fixed, necessary for connection to self.SubplotConstraints()
        :param plotter: stk_plot.ValidationPlot() object for which the plot is generated, necessary for connection to
            self.SubplotConstraints()
        """
        bool_legend = False
        if constraint_names:
            bool_legend = True
        if single_figures:
            if plotter is None:
                plotter = stk_plot.ValidationPlot()
            for i, single_constraint in enumerate(constraint_list):
                x, y = ConstructConstraintBox(single_constraint, keep_time_offset)
                if axes is None:
                    axes_new = plotter.GenerateFigure(show_grid=show_grid)
                else:
                    axes_new = axes
                plt = plotter.GeneratePlot([zip(x, y)], [constraint_names[i]], x_label, y_label, bool_line=True,
                                           title=titles[i], bool_legend=bool_legend,
                                           line_colors=self.constraint_line_color,
                                           line_styles=self.constraint_line_style, axes=axes_new)
        else:  # not single_figures
            if plotter is None:
                plotter = stk_plot.ValidationPlot()
            data = []
            for single_constraint in constraint_list:
                xx, yy = ConstructConstraintBox(single_constraint, keep_time_offset)
                data.append([(xx[i], yy[i]) for i in range(len(xx))])
            if axes is None:
                axes = plotter.GenerateFigure(show_grid=show_grid)
            plt = plotter.GeneratePlot(data, constraint_names, x_label, y_label, title=titles[0], bool_line=True,
                                           bool_legend=bool_legend, line_colors=len(data) * self.constraint_line_color,
                                           line_styles=len(data) * self.constraint_line_style, axes=axes)
# adding the autoscale command gives extra empty figures!
#        plt.autoscale(tight=True)
        if show_plots:
            plt.show()

        return plt

    def SubplotConstraints(self, constraint_list, n_rows=1, n_cols=1, n_plots_per_subplot=[1],
                            constraint_names=[[]], x_labels=['t [s]'], y_labels=['tbd'], show_grid=[False],
                            show_plots=SHOW_PLOTS_DEFAULT, keep_time_offset=True, plotter=None):
        """
        Visualize a list of linear constraints in one figure with subplots.  Input parameters are lists of input
        parameters for self.PlotConstraints().  Figure title is the concatenation of constraint names.   
        :param constraint_list: list of lists of linear constraints, one list of constraints for each subplot
        :type constraint_list: list of list of list of dict
        :type constraint_names: list of lists
        :type x_labels: list of strings
        :type y_labels: list of strings
        :param n_rows: number of rows for the figure
        :param n_cols: number of columns for the figure 
        :param n_plots_per_subplot: number of plots for each subplot
        :type n_plots_per_subplot: list of ints
        :param show_grid: list bools to show grids or not
        :param show_plots: show the figure or not 
        :param keep_time_offset: if true use original constraint time stamps,
            else plot in interval [0, endts - begints]
        :param plotter: stk_plot.ValidationPlot() object for which the plot is generated, necessary for connection to
            self.PlotConstraints()
        """
        # TODO: HOW MUCH DO I HAVE TO CATCH??
        for i, n_plots in enumerate(n_plots_per_subplot):
            if constraint_names and n_plots != len(constraint_names[i]):
                raise IndexError('Number of plots does not match number of constraint names! ' +
                                'n_plots_per_subplot[i] must equal len(constraint_names[i])')
            if n_plots != len(constraint_list[i]):
                raise IndexError('Number of plots does not match number of constraints! ' +
                                'n_plots_per_subplot[i] must equal len(constraint_list[i])')

        subplot_layout = [100 * n_rows + 10 * n_cols + i for i in range(1, n_rows * n_cols + 1)]
        if plotter is None:
            plotter = stk_plot.ValidationPlot()
        axes = plotter.GenerateFigure(subplots=subplot_layout, show_grid=show_grid)
        if constraint_names:
            bool_legend = True
        else:
            bool_legend = True
            concat_title = ''
            constraint_names = [[] for i in range(len(axes))]

        for i in range(len(constraint_list)):
            concat_title = [constraint_name_list for constraint_name_list in constraint_names[i]]
            plt = self.PlotConstraints(constraint_list[i], constraint_names=constraint_names[i],
                                         x_label=x_labels[i], y_label=y_labels[i], titles=[concat_title],
                                         show_plots=False, single_figures=False,
                                         keep_time_offset=False, axes=axes[i], plotter=plotter)
        if show_plots:
            plt.show()

        return plt

    def SubplotConstraints_via_ids(self, constraint_ids_list, n_plots_per_subplot,
                                    show_plots=SHOW_PLOTS_DEFAULT, single_figures=False,
                                    keep_time_offset=True):
        """
        Like self.SubplotConstraints(), with constraint IDs instead of a constraint list.
        :type constraint_ids_list: list of int
        """
        constraint_list = []
        constraint_names = []
        x_labels = []
        y_labels = []
        for i, single_constraint_id  in enumerate(constraint_ids_list):
            single_constraint = self._db.getSigConstraint(single_constraint_id)
            constraint_list.append([single_constraint])  # each constraint fills only one subplot, so it is the only item in the list representing that subplot
            constraint_names.append([str(single_constraint[0][cl.COL_NAME_SIGCON_CONSID])])
            x_labels.append('t [ms]')
            y_labels.append('tbd')

        plt = self.SubplotConstraints(constraint_list=constraint_list,
                                        n_rows=len(constraint_list), n_cols=1, n_plots_per_subplot=n_plots_per_subplot,
                                        constraint_names=constraint_names, x_labels=x_labels, y_labels=y_labels,
                                        show_grid=len(constraint_list) * [False], show_plots=show_plots,
                                        keep_time_offset=keep_time_offset)
        return plt

    def PlotConstraintsViaIds(self):
        pass

    def PlotConstraintSet(self):
        pass

    def SubplotConstraintSet(self, constraint_set_id, keep_time_offset=True, show_plots=SHOW_PLOTS_DEFAULT):
        """
        Use the information contained in a constraint set to plot all signal constraints contained in the set.  Child
        sets are not taken care of.
        In lack of better ideas, the figure that is constructed here consists of one column of subplots, one subplot 
        for each constraint.
        :param constraint_set_id: get this from a DB, e.g. using cl.getConstraintSetIDs()
        :param keep_time_offset: if true use original constraint time stamps,
            else plot in interval [0, endts - begints]
        :param show_plots: switch this off to not call show() from the matplotlib.pyplot handle
        """
        constraint_set_maps = self._db.getConsMap(constraint_set_id, col=cl.COL_NAME_CONMAP_SETID)
        constraint_list = []
        constraint_names = []
        x_labels = []
        y_labels = []
        for i, constraint_set_map in enumerate(constraint_set_maps):
            single_constraint_id = constraint_set_map[cl.COL_NAME_CONMAP_CONSID]
            single_constraint = self._db.getSigConstraint(single_constraint_id)
            constraint_list.append([single_constraint])  # each constraint fills only one subplot, so it is the only item in the list representing that subplot
            constraint_names.append([str(single_constraint[0][cl.COL_NAME_SIGCON_CONSID])])
            x_labels.append('t [ms]')
            y_labels.append('tbd')

        # OLIVER: for now, make one figure with subplots in one column
        plt = self.SubplotConstraints(constraint_list=constraint_list,
                                        n_rows=len(constraint_list), n_cols=1,
                                        n_plots_per_subplot=len(constraint_list) * [1],
                                        constraint_names=constraint_names, x_labels=x_labels, y_labels=y_labels,
                                        show_grid=len(constraint_list) * [False], show_plots=show_plots,
                                        keep_time_offset=keep_time_offset)
        return plt

"""
CHANGE LOG:
-----------
$Log: ucv.py  $
Revision 1.1 2021/12/13 17:59:46CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/val/project.pj
Revision 1.24 2013/12/10 15:21:08CET Skerl, Anne (uid19464) 
*add _getCompareResultDetails() to get all compare results of trie
*remove getConstraintPlotLines()
- Added comments -  uid19464 [Dec 10, 2013 3:21:08 PM CET]
Change Package : 198254:5 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.23 2013/12/06 14:50:06CET Weinhold, Oliver (uidg4236)
Adapt UcvPlot to new signature of UseCaseValidator.__init__()
--- Added comments ---  uidg4236 [Dec 6, 2013 2:50:06 PM CET]
Change Package : 208496:1 http://mks-psad:7002/im/viewissue?selection=208496
Revision 1.22 2013/12/05 17:02:46CET Skerl, Anne (uid19464)
*change back UseCaseValidator interface
--- Added comments ---  uid19464 [Dec 5, 2013 5:02:46 PM CET]
Change Package : 198254:5 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.21 2013/12/05 14:13:51CET Weinhold, Oliver (uidg4236)
Add the UcvPlot class for constraint visualization.
--- Added comments ---  uidg4236 [Dec 5, 2013 2:13:52 PM CET]
Change Package : 208496:1 http://mks-psad:7002/im/viewissue?selection=208496
Revision 1.20 2013/12/04 18:46:39CET Skerl, Anne (uid19464)
*enable loadConstraints() to work with rec file name
*add method getConstraintSignals()
--- Added comments ---  uid19464 [Dec 4, 2013 6:46:40 PM CET]
Change Package : 198254:5 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.19 2013/11/29 16:40:16CET Skerl, Anne (uid19464)
*pep8
--- Added comments ---  uid19464 [Nov 29, 2013 4:40:17 PM CET]
Change Package : 198254:3 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.18 2013/11/29 15:22:16CET Skerl, Anne (uid19464)
*bugfix loadConstraints()
*make it nicer
--- Added comments ---  uid19464 [Nov 29, 2013 3:22:17 PM CET]
Change Package : 198254:3 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.17 2013/11/26 13:40:43CET Skerl, Anne (uid19464)
*remove: self._consJoin
*bugfix: addCompareData also to parent
*change checkConstraint: adapt to changed structure of trie values
*add: checkConstrSet
--- Added comments ---  uid19464 [Nov 26, 2013 1:40:44 PM CET]
Change Package : 198254:2 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.16 2013/11/22 11:18:00CET Skerl, Anne (uid19464)
*remove saving of input compare data from compare() to addCompareData()
--- Added comments ---  uid19464 [Nov 22, 2013 11:18:01 AM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.15 2013/11/21 15:22:58CET Skerl, Anne (uid19464)
*extend checkConstraint() to check all constraints in one ConstraintSet
--- Added comments ---  uid19464 [Nov 21, 2013 3:22:58 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.14 2013/11/18 16:51:46CET Skerl, Anne (uid19464)
*remove: import of cgeb file, index settings for contraint values
--- Added comments ---  uid19464 [Nov 18, 2013 4:51:47 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.13 2013/11/13 18:19:19CET Skerl, Anne (uid19464)
*change: loadConstraints(self, consSet) -> loadConstraints(self, consSet=None, measid=None)
*change: write values of Trie kids as list of dicts
--- Added comments ---  uid19464 [Nov 13, 2013 6:19:19 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.12 2013/11/04 16:55:23CET Skerl, Anne (uid19464)
*change: comment out try/except, maybe delete it in next revision?
*change: checkConstraint() for signals based on TimeStamp
*add: TODOs
*add: getConstraintPlotLines(), but not finished
--- Added comments ---  uid19464 [Nov 4, 2013 4:55:23 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.11 2013/07/17 09:30:20CEST Mertens, Sven (uidv7805)
removing 0 alignment as signals should be proper by default
--- Added comments ---  uidv7805 [Jul 17, 2013 9:30:20 AM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.10 2013/07/05 13:36:03CEST Mertens, Sven (uidv7805)
fixing 2 errors:
- constraint compare was only able to test against 2 signals,
- signalCompare expects numpy.array
--- Added comments ---  uidv7805 [Jul 5, 2013 1:36:04 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.9 2013/06/28 11:39:46CEST Mertens, Sven (uidv7805)
added new signalCompare function to get signals compared
--- Added comments ---  uidv7805 [Jun 28, 2013 11:39:46 AM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.8 2013/03/22 08:24:22CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
--- Added comments ---  uidv7805 [Mar 22, 2013 8:24:22 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/15 10:01:20CET Mertens, Sven (uidv7805)
added addConstraint method to add new constrain set with details
--- Added comments ---  uidv7805 [Mar 15, 2013 10:01:21 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.6 2013/03/06 10:21:23CET Mertens, Sven (uidv7805)
done, pep8 styling
--- Added comments ---  uidv7805 [Mar 6, 2013 10:21:23 AM CET]
Change Package : 176171:7 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.4 2013/03/01 10:29:41CET Mertens, Sven (uidv7805)
bugfixing STK imports
--- Added comments ---  uidv7805 [Mar 1, 2013 10:29:41 AM CET]
Change Package : 176171:2 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.3 2013/02/28 17:12:40CET Mertens, Sven (uidv7805)
first working version of constraint related things
--- Added comments ---  uidv7805 [Feb 28, 2013 5:12:40 PM CET]
Change Package : 176171:1 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.1 2013/02/21 11:07:10CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk
    /val/project.pj
"""
