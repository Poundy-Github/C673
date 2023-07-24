"""
stk/img/__init__.py
-------------------

Generate Plots and reload images from database

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:52CET $
"""

# pylint: disable=C0103,R0913

# Import Python Modules -----------------------------------------------------------------------------------------------
from PIL import Image as Img
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.backends.backend_ps import papersize
from matplotlib.figure import Figure
from matplotlib.font_manager import FontProperties
from matplotlib.lines import Line2D
from matplotlib.ticker import MaxNLocator
from matplotlib import mlab
from numpy.ma import MaskedArray
import os
from reportlab.graphics.shapes import Image, Drawing
import math
import matplotlib
import matplotlib.pyplot as pltt
import numpy
import numpy.core as npc
import tempfile
import logging
import stk.obj.geo as pp
import warnings

# try:
#     from matplotlib.transforms import blended_transform_factory
# except:
#     from matplotlib.transforms import blend_xy_sep_transform as blended_transform_factory

# Import STK Modules --------------------------------------------------------------------------------------------------
# import val_functions as val_utils

# Defines -------------------------------------------------------------------------------------------------------------
DRAWING_W = 450
DRAWING_H = 100

PLOT_W = DRAWING_W * 0.75  # DRAWING_W - DRAWING_W / 5
PLOT_H = DRAWING_H - DRAWING_H / 5
LEGEND_X = DRAWING_W * 0.85  # DRAWING_W - DRAWING_W / 10
LEGEND_Y = DRAWING_H * 0.8
TEXT_SIZE = 7
DEFAULT_OUTPUT_FILEEXT = "png"

PLOT_BAR = "Bar"
PLOT_SCATTER = "Scatter"

DEF_COLORS = ["b", "r", "g", "orange", "magenta", "cyan", "k", "y", "b", "r", "g",
              "orange", "magenta", "cyan", "k", "y"]
DEF_LINE_STYLES = ["-", "--", "-.", ":", "", "+"]
DEF_LINE_MARKERS = ["None", "+", "*", ",", ".", "<", ">", "+", "*", ",", ".", "<", ">", "+", "*", ",", ".", "<", ">"]

# Functions -----------------------------------------------------------------------------------------------------------


# Classes -------------------------------------------------------------------------------------------------------------
class PlotException(StandardError):
    """Plot exception Class"""
    def __init__(self, description):
        """ Constructor """
        StandardError.__init__(description)
        self.__description = str(description)

    def __str__(self):
        """ Return the plot exception string """
        return str(self.__description)


class ValidationFigure(object):
    """Figure class used by ValidationPlot class"""
    def __init__(self, subplots=None, fig_width=10, fig_height=3, show_grid=True):
        """ Create initial Figure ValidationPlot
        :param subplots: specifiy subplots per figure
        :type subplots:  list of integer
        :param fig_width: width of the figure
        :type fig_width: int
        :param fig_height: heigh of the figure
        :type fig_height: int
        :param show_grid: flag to show or hide grid
        :type show_grid: boolean
        """
        self.__plot = pltt
        self.__fig = pltt.figure(figsize=(fig_width, fig_height))
        self.__width = fig_width
        self.__height = fig_height
        self.__show_grid = show_grid
        self.__subplots = subplots
        self.__axes = None
        self.__Initialize()

    def __Initialize(self):
        """Initialize the attribute when the contructor is called
        creates the subplot if values are passed in constructor"""
        self.__plot.clf()
        if self.__subplots is None:
            self.__axes = self.__fig.add_subplot(111)
            self.__axes.grid(self.__show_grid)
        else:
            self.__axes = []
            for i in range(len(self.__subplots)):
                self.__axes.append(self.__fig.add_subplot(self.__subplots[i]))
                self.__axes[i].grid(self.__show_grid[i])

    def AddSubplot(self, subplots, show_grid=True):
        """
        Add subplots in the existing figure
        :param subplots: specifiy subplots to be added
        :type subplots: list of integer
        :param show_grid: flag to show or hide grid
        :type show_grid: boolean
        """
        if self.__subplots is not None:
            self.__subplots += subplots

        for i in range(len(subplots)):
            self.__axes.append(self.__fig.add_subplot(subplots[i]))
            self.__axes[i].grid(show_grid[i])

    def GetFig(self):
        """
        Get Property function to get Figure
        """
        return self.__fig

    def GetPlot(self):
        """
        Get Property function to get plot
        """
        return self.__plot

    def GetWidth(self):
        """
        Get Property function to get Figure width
        """
        return self.__width

    def GetHeight(self):
        """
        Get Property function to get Figure width
        """
        return self.__height

    def GetAxes(self):
        """
        Get Property function to get Axes
        """
        return self.__axes

    def GetShowGrid(self):
        """
        Get Property function to get grid flag
        """
        return self.__show_grid


class BasePlot():  # pylint: disable=R0902,R0904
    """ Base Class for plotting functions using matplot lib """
    def __init__(self, figure=None, position=None, figsize=(8, 6), fontsize=8, show_grid=True):
        """ Contructor """
        self.__figure = figure

        if not self.__figure:
            self.__figure = Figure(figsize=figsize, facecolor='#ddddee')

        self.__show_grid = show_grid

        self._canvas = FigureCanvas(self.__figure)

        if position and self.__figure:
            self.__axes = self.__figure.add_axes(position)
        else:
            self.__axes = self.__figure.gca()

        self.__fontsize = fontsize

        # Set\Re-set grid
        self.__axes.grid(show_grid)

        # set axis labels
        label_list = self.__axes.get_xticklabels() + self.__axes.get_yticklabels()
        for label in label_list:
            label.set_size(self.__fontsize)

        self.__lines = []
        self.__vlines = []
        self.__texts = []
        self.__legends = []

        self.__styles = "line dashed dotted dashdot".split()
        self.__color_map = "blue green red black cyan magenta orange purple yellow pink".split()
        self.__lsalias = {"line": [1, 0],
                          "dashdot": [4, 2, 1, 2],
                          "dashed": [4, 2, 4, 2],
                          "dotted": [1, 2],
                          "dashdotdot": [4, 2, 1, 2, 1, 2],
                          "dashdashdot": [4, 2, 4, 2, 1, 2]}

        self.__color = 0
        self.__linestyle = 0
        self.__line_attributes = {}
        self.__text_attributes = {}
        self.__legend_loc = 0

        self.__background = None

        ss = []
        for line_style in self.__styles:
            if line_style in self.__lsalias:
                ss.append(self.__lsalias.get(line_style))
            else:
                ss.append("-")

        self.__linestyles = ss

        self.__set_draw_mode = False

    def add_patch(self, patch):
        """
        Add a patch to the plot.
        """
        self.__axes.add_patch(patch)

    def set_xticklabels(self, labels=""):
        """ Set the xtick labels
        """
        self.__axes.set_xticklabels(labels, visible=False)

    def set_label2(self, text):
        """ Set the x axes label """
        self.__axes.set_xlabel(text)

    def set_patch(self, patch):
        """
        Sets an existing patch
        """
        if not self.__set_draw_mode:
            self._canvas.draw()
            self.__set_draw_mode = True

        # self.__axes.set_xy(vertices)
        self.__axes.draw_artist(patch)

    def set_title(self, *args, **kwargs):
        """
        Sets the title of the plot. Use the previous title if omitted.
        """
        self.__axes.set_title(*args, **kwargs)

    def set_grid(self, show_grid):
        """ Enable of Diable the grid"""
        self.__axes.grid(show_grid)

    def getImage(self):
        """ returns the plot as a PIL image
        """
        self.__figure.canvas.draw()
        image_size = self.__figure.canvas.get_width_height()
        image_rgb = self.__figure.canvas.tostring_rgb()
        return Img.fromstring("RGB", image_size, image_rgb)

    def save_plot(self, filename):
        """
        Save the plot to a file.

        :param filename: The name of the output file.
        """
        self.__figure.canvas.draw()
        image_size = self.__figure.canvas.get_width_height()
        image_rgb = self.__figure.canvas.tostring_rgb()
        pil_image = Img.fromstring("RGB", image_size, image_rgb)
        pil_image.save(filename, "JPEG")

    def save(self, filename=None, orientation=None, dpi=None, papertype=None):
        """
        Save the plot to a file.

        :param filename: The name of the output file.  The image format is determined
        from the file suffix: 'png', 'ps', and 'eps' are recognized.  If no
        file name is specified 'yyyymmdd_hhmmss.png' is created in the current
        directory.
        :param orientation: Orientation of the plot
        :param dpi: Resolution
        :param papertype: Papertype 'A4'
        """
        if papertype is None:
            papertype = "A4"

        if filename is None:
            raise PlotException("Filename not specified.")

        file_ext = ['png', '.ps', 'eps']

        filename = os.path.expandvars(filename)
        if filename[-3:].lower() in file_ext:
            try:
                if filename[-3:].lower() == ".ps":

                    fig_weight = self.__figure.get_figwidth()
                    fig_height = self.__figure.get_figheight()

                    if orientation is None:
                        # oriented
                        if fig_weight > fig_height:
                            orientation = 'landscape'
                        else:
                            orientation = 'portrait'

                    paper_weight, paper_height = papersize[papertype.lower()]
                    ds = None
                    if orientation == 'landscape':
                        ds = min(paper_height / fig_weight, paper_weight / fig_height)
                    else:
                        ds = min(paper_weight / fig_weight, paper_height / fig_height)
                    ow = ds * fig_weight
                    oh = ds * fig_height
                    self.__figure.set_size_inches((ow, oh))
                    self.__figure.savefig(filename, orientation=orientation,
                                          papertype=papertype.lower())
                    self.__figure.set_size_inches((fig_weight, fig_height))
                else:
                    if dpi is None:
                        dpi = 100  # 150
                    self.__figure.canvas.print_figure(filename)  # , dpi = dpi)
            except IOError, err:
                raise PlotException("Failed to save '%s' due to\n%s" % (filename, err))
        else:
            raise PlotException("Invalid image type. Valid types are: 'ps', 'eps', 'png'")

        return filename

    def set_font_size(self, fontsize):
        """ Set the Font size """
        label_list = self.__axes.get_xticklabels() + self.__axes.get_yticklabels()
        for label in label_list:
            label.set_size(fontsize)

    def get_axes_limits(self):
        """ Return the limits of the axes """
        return [self.__axes.get_xlim(), self.__axes.get_ylim()]

    def set_limits(self, xlim=None, ylim=None):
        """
        Set x, y limits of the plot
        xlim = [xmin, xmax]
        ylim = [ymin, ymax]
        """
        old_xlim = list(self.__axes.get_xlim())
        old_ylim = list(self.__axes.get_ylim())

        if xlim:
            for i in range(len(xlim)):
                if xlim[i]:
                    old_xlim[i] = xlim[i]

        if ylim:
            for i in range(len(ylim)):
                if ylim[i]:
                    old_ylim[i] = ylim[i]

        self.__axes.set_xlim(old_xlim)
        self.__axes.set_ylim(old_ylim)

    def axes_yticks(self):
        """ Get the y ticks """
        return self.__axes.get_yticks()

    def set_ylabel1On(self, val):
        """ Set the y label """
        ticks = self.__axes.get_yticklabels()
        for tick in ticks:
            tick.label1On = val
            tick.tick1On = val

    def set_xlabel1On(self, val=False):
        """ Set the x label """
        ticks = self.__axes.get_xticklabels()
        for tick in ticks:
            tick.set_visible(val)

    def hide_yticklabels(self):
        """ Hide the y tick labels """
        self.__axes.get_yticklabels().set_visible(False)

    def get_axes(self):
        """ Get the axes """
        return self.__axes

    def set_legend(self, labels, legend_number=0):
        """ Set the legend """
        texts = self.__legends[legend_number].get_texts()
        if len(texts) != len(labels):
            return

        for idx in xrange(0, len(texts)):
            texts[idx].set_text(labels[idx])
            y = texts[idx].get_position()[1]
            texts[idx].set_y(y - 0.1)

    def add_legend(self, labels, colors, fontsize="xx-small", **kwargs):
        """
        Add a legend to the plot.
        :param loc: Possible values:
                1: upper right
                2: upper left
                3: lower left
                4: lower right
                5: right
                6: center left
                7: center right
                8: lower center
                9: upper center
                10: center
        """
        if not isinstance(labels, list):
            labels = list(labels)

        if not isinstance(colors, list):
            colors = list(colors)

        if len(labels) != len(colors):
            return

        # rects = []
        lines = []
        for color in colors:
            line = matplotlib.lines.Line2D([0], [0], marker='o', color=color)
            lines.append(line)

        legend = self.__axes.legend(lines, labels, **kwargs)

        # Set fontsize
        texts = legend.get_texts()
        for text in texts:
            text.set_size(fontsize)

        legend.draw_frame(False)

        self.__legends.append(legend)

    def plot(self, x=None, y=None, fmt=None, add=None, **kwargs):
        """
        Plot a line using the current line attributes
        """
        if x is None:
            if y is None:
                return
            x = range(len(y))
        elif y is None:
            y = x
            x = range(len(y))

        if fmt is None:
            line = self.__axes.plot(x, y, **kwargs)
        else:
            line = self.__axes.plot(x, y, fmt, **kwargs)

        self.__axes.grid(self.__show_grid)
        # Add to an existing line?
        i = None
        if add is None or len(self.__lines) < add < 0:
            self.__lines.append(line)
            i = len(self.__lines) - 1
        else:
            if add == 0:
                add = len(self.__lines)
                i = add - 1
                self.__lines[i].extended(line)

        return line

    def add_vline(self, x, **kwargs):
        """
        Adds a vertical line at x position.
        """
        plot = self.__axes.axvline(x, **kwargs)
        self.__vlines.append(plot)

    def set_vline(self, x, line_number):
        """
        Sets an existing vertical line.
        """
        if 0 <= line_number < len(self.__vlines):
            self.__vlines[line_number].set_xdata([x, x])

    def add_texts(self, x, y, text, *args, **kwargs):
        """
        Add texts to the figure.
        """
        texts = []
        if not isinstance(x, list):
            x = list(x)

        if not isinstance(y, list):
            y = list(y)

        if not isinstance(text, list):
            text = list(text)

        if len(x) != len(y):
            return

        for idx in xrange(0, len(x)):
            text = self.__axes.text(x[idx], y[idx], text[idx] * args, **kwargs)
            texts.append(text)

        return texts

    def add_text(self, x, y, text, *args, **kwargs):
        """
        Add text to the axes.
        """
        text = self.__axes.text(x, y, text, *args, **kwargs)
        self.__texts.append(text)

        return text

    def remove_texts(self):
        """
        Deletes all texts from the plot.
        Text numbering will be reset to 0.
        """
        for text_number in xrange(0, len(self.__texts)):
            self.__remove_text(text_number)

        self.__texts = []

    def __remove_text(self, text_numbers=None):
        """
        Delete the 0-relative text number, default is to delete the last one.
        The remainning text(s) are not re-numbered
        """
        if text_numbers is None:
            text_numbers = [len(self.__texts) - 1]

        if not hasattr(text_numbers, '__iter__'):
            text_numbers = [text_numbers]

        for text_number in text_numbers:
            if 0 <= text_number < len(self.__texts):
                if self.__texts[text_number] is not None:
                    for text in self.__texts[text_number]:
                        text.set_text('None')
                        self.__text[text_number] = None

    def set_major_locator(self, size):
        """ Set the mayor locator """
        if not size:
            return

        self.__axes.yaxis.set_major_locator(MaxNLocator(size))

    def draw(self):
        """ Draw canvas """
        # self._canvas.draw()
        self._canvas.draw()
        self._canvas.blit(self.__axes.bbox)

    def set_text(self, text_number=None, **kwargs):
        """
        Set attributes for specified text number
        number_number is 0-relative number of a text that already been plotted.
        If no text exists, attributes will be used for the next text(s).
        """
        if not self.__set_draw_mode:
            self._canvas.draw()
            self.__set_draw_mode = True

        redraw = False
        for k, v in kwargs.iteritems():
            k = k.lower()
            if k == "colour":
                k = "color"

            if 0 <= text_number < len(self.__texts):
                if self.__texts[text_number]:
                    text = self.__texts[text_number]
                    getattr(text, "set_%s" % k)(v)
                    redraw = True

            else:
                if not v:
                    del self.__text_attributes[k]
                else:
                    self.__text_attributes[k] = v

            if redraw:
                self.__axes.draw_artist(self.__texts[text_number])

    def set_line(self, line_number=None, **kwargs):
        """
        Set attributes for specified line
        line_number is 0-relative number of a line that already been plotted.
        If no line exists, attributes will be used for the next line(s).
        """
        if not self.__set_draw_mode:
            self._canvas.draw()
            self.__set_draw_mode = True

        redraw = False
        for k, v in kwargs.iteritems():
            k = k.lower()
            if k == "colour":
                k = "color"

            if 0 <= line_number < len(self.__lines):
                if self.__lines[line_number]:
                    for line in self.__lines[line_number]:
                        getattr(line, "set_%s" % k)(v)
                    redraw = True
            else:
                if not v:
                    del self.__line_attributes[k]
                else:
                    self.__line_attributes[k] = v

            if redraw:
                for segment in self.__lines[line_number]:
                    self.__axes.draw_artist(segment)
                # self.show(hardrefresh = False)

    def remove_lines(self):
        """
        Deletes all lines from the plot.
        Line numbering will be reset to 0.
        """
        for line_number in xrange(0, len(self.__lines)):
            self.__remove_line(line_number)

        self.__axes.clear()
        self.__lines = []

    def clear(self):
        """ Clear local variables """
        self.__axes.clear()
        self.__lines = []
        self.__vlines = []
        self.__texts = []
        self.__legends = []

    def __remove_line(self, line_numbers=None):
        """
        Delete the 0-relative line number, default is to delete the last one.
        The remainning line(s) are not re-numbered
        """
        if line_numbers is None:
            line_numbers = [len(self.__lines) - 1]

        if not hasattr(line_numbers, '__iter__'):
            line_numbers = [line_numbers]

        for line_number in line_numbers:
            if 0 <= line_number < len(self.__lines):
                if self.__lines[line_number] is not None:
                    for line in self.__lines[line_number]:
                        line.set_linestyle('None')
                        self.__lines[line_number] = None

        # self._show()

    def histogram(self, x=None, y=None, fmt=None, add=None):
        """
        Plot a histogram.
        @param x Start of the histogram bin
        @param fmt Line style
        """

        if x is None:
            if y is None:
                return
            x = range(len(y))

        if len(x) != len(y):
            return

        l2 = 2 * len(x)
        x2 = range(l2)
        y2 = range(l2)
        m2 = range(l2)

        y_mask = None
        y_dat = None

        if hasattr(y, "raw_mask"):
            y_mask = y.raw_mask()
            y_dat = y.raw_data()
        else:
            y_mask = y.mask
            y_dat = y.dat

        for i in range(l2):
            x2[i] = x[i / 2]
            m2[i] = y_mask[i / 2]

        y2[0] = 0.0

        for i in range(1, l2):
            y2[i] = y_dat[(i - 1) / 2]

        self.plot(x2, MaskedArray(y2, mask=m2, copy=0), fmt, add)

    def save_background(self):
        """ set the background """
        self.__background = self._canvas.copy_from_bbox(self.__axes.bbox)

    def restore_background(self):
        """ retore the backgound """
        if not self.__background:
            return
        self._canvas.restore_region(self.__background)

    def show(self, hardrefresh=True):
        """ show the drawing """
        if not hardrefresh:
            return
        self._canvas.draw()
        self._canvas.show()


class ValidationPlot(object):  # pylint: disable=R0902
    '''
    Provides common plot methods for EM Validators
    '''
    def __init__(self, path=None, title=None, width=None, height=None):
        """ Constructor to create ValidationPlot instance
        :param path: file path to store the plot into image file
        :type path: str
        :param title: Plot title
        :type title: str
        :param width: figure wdith
        :type width: int
        :param height: figure height
        :type height: int
        """

        self.__title = title
        self.__file_counter = 0
        if width is not None or height is not None:
            self.__valfig = ValidationFigure(fig_width=width, fig_height=height)
        else:
            self.__valfig = None

        self.__img_data = None
        if(path is None):
            self.__out_path = tempfile.gettempdir()
        else:
            if(len(path) >= 255):
                logging.info("Path >= 255 characters is used")
                path = "\\\\?\\" + path

            if not os.path.exists(path):
                os.makedirs(path)
            self.__out_path = path

    def __str__(self):
        """ Get String represting the information of the instance """
        if self.__title is not None:
            if self.GetWidth() is not None and self.GetHeight():
                return self.__title + " (%dx%d) " % (self.GetWidth(), self.GetHeight())
            else:
                return self.__title
        else:
            return "Plot"

    def GetWidth(self):
        """ Get the width """
        return self.__valfig.GetWidth()

    def GetHeight(self):
        """ Get the height """
        return self.__valfig.GetHeight()

    def GetTitle(self):
        """ Get the title """
        return self.__title

    def GenerateFigure(self, subplots=None, fig_width=10, fig_height=3, show_grid=True):
        """ Generates a matplotlib figure
        :param subplots: List of subplots, ex: [221, 222, 223, 224]
        :type subplots: list of int
        :param fig_width: figure's width, default value is 10
        :type fig_width: int
        :param fig_height: figure's height, default value is 3
        :type fig_height: int
        """
        self.__valfig = ValidationFigure(subplots=subplots, fig_width=fig_width,
                                         fig_height=fig_height, show_grid=show_grid)
        return self.__valfig.GetAxes()

    def GetBarChart(self, axes, data, xlabel=None, ylabel=None, title=None, legend=None, group_labels=True,
                    stacked_bars=False, overlap=False, tick_labels=None, rotate=None, size=10, rwidth=0.8,
                    xticks=None, xticks_labels=None, x_axis_ext=None, yticks=None, yticks_labels=None,
                    y_axis_ext=None, colors=None, extra_lines=None, bar_pos=None, bar_orientation='vertical',
                    **kwargs):  # pylint: disable=R0912, R0914, R0915, W0613
        """ Plots a bar chart.
        Bars can be stacked and/or grouped depending on input data.
        :param axes: matplotlib axes handle
        :param data: list of list of lists containing the already calculated histogram (frequencies)
            example data:
            3 bars/bins, no stacks/groups:    [[[1,2,3]]]
            2 bars/bins, stacked (2 classes) and grouped (2 sets): [[[1,5],[2,6]],[[4,8],[3,7]]]
            2 bars/bins, stacked (3 classes): [[[2,3],[3,2],[2,2]]]
            3 bars/bins, groups (3 sets):     [[[1,2,3]],[[5,4,3]],[[1,2,1]]]
        :param xlabel: label for the x-axis
        :param ylabel: label for the y-axis
        :param title: a title for the figure
        :param legend: a list of strings with the labels
        :param rotate: rotate tick labels (angle in degrees or one of the following keywords:
                       'horizontal' / 'vertical').
        :param size: size of the tick labels
        :param rwidth: relative width of the bar, compared to the width of the bin

        :param xticks: list of numbers that give the position of the ticks (marks) on the x-axis
        :param xticks_labels: list of strings or numbers used to set labels for the ticks in the x-axis
        :param x_axis_ext: list of two numbers to set the limits of the x-axis
        :param yticks: list of numbers that give the position of the ticks (marks) on the y-axis
        :param yticks_labels: list of strings or numbers used to set labels for the ticks in the y-axis
        :param y_axis_ext: list of two numbers to set the limits of the y-axis

        :param colors: list of lists of colors - according to number of sets and classes
        :param extra_lines: list of values; adds horizontal lines, one for each bar at the height
                            of the according value
        :param bar_pos: list of custom position values for the positions of the bars (i.e. the bar groups)
        :param bar_orientation: choose if 'horizontal' or 'vertical' (normal) bar chart
        :param **kwargs: keyword arguments for the matplotlib bar function only!

        :param tick_labels: DEPRECATED [use xticks_labels now]
        :param group_labels: DEPRECATED [automatically determined via length of ticks_labels ]
                            (Set label for every group of bars.)
        :param stacked_bars: DEPRECATED [done via format of data]
                            (True for stacked bars, false for side-by-side bars.)
        :param overlap: DEPRECATED (..) """

        # Adapt interface
        _, _, _ = group_labels, stacked_bars, overlap
        axes = self.__GetAppropriateAxes(axes)
        try:
            try:
                _ = len(data[0])
            except TypeError:
                data = [data]

            _ = len(data[0][0])
        except TypeError:
            data = [data]

        if tick_labels is not None and xticks_labels is None:
            xticks_labels = tick_labels  # DEPRECATED parameter

        no_of_sets = len(data)
        no_of_classes_per_set = len(data[0])

        # check if number of bar groups is consistent for the data
        tmp_lens = []
        # check within a set
        for i in range(len(data)):
            for j in range(len(data[i])):
                if j == 0:
                    continue
                if len(data[i][j]) == len(data[i][j - 1]):
                    continue
                else:  # no_of_bar_groups is different for the classes/sets
                    return
            tmp_lens.append(len(data[i][0]))

        # check in between sets
        for i in range(len(tmp_lens)):
            if i == 0:
                continue
            if tmp_lens[i] == tmp_lens[i - 1]:
                continue
            else:  # no_of_bar_groups is different for the classes/sets
                return

        if colors is None or len(colors) != no_of_sets or len(colors[0]) != no_of_classes_per_set:
            colors = []
            cur_set = 0
            counter = 0
            while counter < no_of_sets:  # taking default colors
                colors.append(DEF_COLORS[cur_set:cur_set + no_of_classes_per_set])
                cur_set += no_of_classes_per_set
                counter += 1

        no_of_bar_groups = len(data[0][0])
        # check if number of custom bar_pos is consistent for the data
        if bar_pos is not None:
            if len(bar_pos) != no_of_bar_groups:
                bar_pos = None

        bar_group_range = numpy.arange(no_of_bar_groups)
        bar_width = rwidth / no_of_sets

        # Create actual bar for all bins/bar groups, for all sets, for all classes
        for bar_group in range(no_of_bar_groups):
            for cur_set in range(no_of_sets):
                last_height = 0
                for cur_class in range(no_of_classes_per_set):
                    if bar_pos is None:
                        bargroup_left = (bar_group + cur_set * bar_width)
                    else:
                        bargroup_left = (bar_pos[bar_group] + cur_set * bar_width)
                    if bar_orientation == 'vertical':
                        axes.bar(left=bargroup_left,
                                 height=data[cur_set][cur_class][bar_group],
                                 width=bar_width, color=colors[cur_set][cur_class],
                                 bottom=last_height, **kwargs)
                    else:
                        axes.barh(bargroup_left, data[cur_set][cur_class][bar_group],
                                  height=bar_width, color=colors[cur_set][cur_class],
                                  left=last_height, **kwargs)
                    last_height += data[cur_set][cur_class][bar_group]

        # add axis-labels, title and legend
        if xlabel is not None:
            axes.set_xlabel(xlabel, size=size)
        if ylabel is not None:
            axes.set_ylabel(ylabel, size=size)
        if title is not None:
            axes.set_title(title, size=size)
        if legend is not None:
            leg = axes.legend(legend, loc=1)
            leg.get_frame().set_alpha(0.5)

        # add x tick labels
        if xticks_labels is not None:
            if xticks is None:
                if bar_orientation == 'vertical':
                    lab_ind = []
                    if len(xticks_labels) == no_of_bar_groups:
                    # if every bar group should have a label
                        lab_ind.append(bar_group_range + (.5) * no_of_sets * bar_width)
                    else:
                    # if every bar should have a label
                        for j in range(no_of_sets):
                            lab_ind.append(bar_group_range + (j + .5) * bar_width)
                    xticks = numpy.vstack(lab_ind).transpose().ravel()  # flatten the array for the label positions
            # add xticks_labels
            if xticks is not None:
                axes.set_xticks(xticks)
            axes.set_xticklabels(xticks_labels, rotation=rotate, size=size)
        # add y tick labels
        if yticks_labels is not None:
            if yticks is None:
                if bar_orientation == 'horizontal':
                    lab_ind = []
                    if len(yticks_labels) == no_of_bar_groups:
                    # if every bar group should have a label
                        lab_ind.append(bar_group_range + (.5) * no_of_sets * bar_width)
                    else:
                    # if every bar should have a label
                        for j in range(no_of_sets):
                            lab_ind.append(bar_group_range + (j + .5) * bar_width)
                    yticks = numpy.vstack(lab_ind).transpose().ravel()  # flatten the array for the label positions
            # add xticks_labels
            if yticks is not None:
                axes.set_yticks(yticks)
            axes.set_yticklabels(yticks_labels)

        # add extra lines
        # (they only work properly for default xlim/ylim currently)
        if extra_lines is not None and len(extra_lines) == no_of_bar_groups:
            for i, res in enumerate(extra_lines):
                line_min = float(i) / no_of_bar_groups
                line_max = float(i + rwidth * 1.05) / no_of_bar_groups
                if bar_orientation == 'vertical' and x_axis_ext is None:
                    axes.axhline(y=res, xmin=line_min, xmax=line_max,
                                 linewidth=3, linestyle='dotted')
                elif bar_orientation == 'horizontal' and y_axis_ext is None:
                    axes.axvline(x=res, ymin=line_min, ymax=line_max,
                                 linewidth=3, linestyle='dotted')

        # fit data limits to given data (if x_axis_ext / y_axis_ext is None)
        stackheights = [0]
        for bar_group in range(no_of_bar_groups):
            for cur_set in range(no_of_sets):
                cur_height = 0
                for cur_class in range(no_of_classes_per_set):
                    cur_height += data[cur_set][cur_class][bar_group]
                stackheights.append(cur_height)
        if extra_lines is not None:  # consider case that extra_lines exceed the data
            stackheights.append(max(extra_lines))
            stackheights.append(min(extra_lines))
            delta = 0.0
        else:
            delta = 0.05
            # margin over highest value
            stackheights.append(max(stackheights) + 0.1 * math.fabs(max(stackheights) -
                                                                    min(stackheights)))

        if bar_pos is None:
            if rwidth < 1 and extra_lines is None:
                bar_pos = [0, no_of_bar_groups - (1 - rwidth)]
            else:
                bar_pos = [0, no_of_bar_groups]
        else:
            bar_pos.append(max(bar_pos) + rwidth)
        if bar_orientation == 'vertical':
            axes.set_xlim(self.__LimitFromExt(x_axis_ext, bar_pos, delta))
            axes.set_ylim(self.__LimitFromExt(y_axis_ext, stackheights))
        else:
            axes.set_xlim(self.__LimitFromExt(x_axis_ext, stackheights))
            axes.set_ylim(self.__LimitFromExt(y_axis_ext, bar_pos, delta))

        return pltt, bar_group_range

    def __LimitFromExt(self, axis_ext, data, delta=0):
        """
        Method for GetBarChart
        :param axis_ext: parameter for the limits of the figure
        :param data: input data for the bar chart
        :param delta: the percentage value for the margin
        """
        data_max = numpy.amax(data)
        data_min = numpy.amin(data)

        if axis_ext is None:
            margin = delta * math.fabs(data_max - data_min)
            lim = [data_min - margin, data_max + margin]
        elif len(axis_ext) == 2:
            lim = axis_ext
        else:
            lim = [data_min, data_max]
        return lim

    def GetHistogram(self, axes, data, binning, xlabel, ylabel, title, legend=None,
                     tick_labels=None, rotate=None, size=None, normed=1,
                     rwidth=0.9, **kwargs):  # pylint: disable=R0914
        """ Calculates and plots a histogram
        :param axes: axes handle.
        :param data: List of lists containing the already calculated histogram (frequencies).
        :param binning: List of values for the x-axis.
        :param legend: a list of strings with the bar names.
        :param xlabel: label for the x-axis.
        :param ylabel: label for the y-axis.
        :param title: a title for the figure.
        :param tick_labels: List of strings or numbers used to set labels for the ticks in the x-axis.
        :param rotate: rotate tick labels (angle in degrees or one of the following keywords:
                       'horizontal' / 'vertical').
        :param size: size of the tick labels.
        :param rwidth: relative width of the bar, compared to the width of the bin.
        :param align: Controls how the histogram is plotted. 'left', 'mid' or 'right'.
        :param **kwargs: keyword arguments for the hist function only!
        """
        axes = self.__GetAppropriateAxes(axes)
        # Formatting the input data for the hist function
        inarr = numpy.array(data).T
        # Calculating the histogram
        if legend is not None:
            _, bins, _ = axes.hist(inarr, binning, normed=normed, label=legend, rwidth=rwidth, **kwargs)
        else:
            _, bins, _ = axes.hist(inarr, binning, normed=normed, rwidth=rwidth, **kwargs)
        # Setting the labels and legend
        axes.set_ylabel(ylabel, size=size)
        axes.set_xlabel(xlabel, size=size)
        axes.set_title(title, size=size)
        axes.set_xticks(bins)
        if tick_labels is not None:
            axes.set_xticklabels(tick_labels, rotation=rotate, size=size)
        # Setting the legend
        if legend is not None:
            axes.legend()

        return pltt, bins

    def GetNormalPdf(self, axes, bins, sigma, mu, legend=None, draw_lines=True,
                     write_text=None, gauss_color='orange',
                     line_colors=DEF_COLORS, tick_labels=None,
                     title=None, xlabel=None,
                     ylabel=None):  # pylint: disable=R0914, W0102
        """ Plot the Probability Density Function of Normal distribution
        :param axes: axes handle.
        :param bins: List of values for which the gauss pdf is calculated.
        :param sigma: Standard deviation of the distribution
        :param mu: Mean value of the distribution
        :param legend(optional): A string for the label
        :param draw_lines(optional): Draw lines at mu-sigma, sigma, sigma+mu. Deactivated by default
        :param write_text(optional): Writes down the values of sigma and mu.
               Input is the location in the vertical axis, 1 being the top of the axes and 0 the bottom.
        :param gauss_color(optional): Color of tha gaussian plot.
        :param line_colors(optional): Color of the [mu-sigma, sigma, sigma+mu] lines
        :param tick_labels(optional): List of strings or numbers used to set labels for the ticks in the x-axis.
        :param title(optional): A title for the figure, if only a gauss plot has to be plotted for instance.
        :param xlabel(optional): A label for the x-axis, if only a gauss plot has to be plotted for instance.
        :param ylabel(optional): A label for the y-axis, if only a gauss plot has to be plotted for instance.
        """
        axes = self.__GetAppropriateAxes(axes)

        # Only display Gauss curve with a standard deviation bigger than 0
        if (abs(sigma) > 0.0):
            # Get value for every x position of the bins vector
            y = mlab.normpdf(bins, mu, sigma)
            # Plot the gaussian distribution
            if legend is not None:
                axes.plot(bins, y, gauss_color, label=legend)
                pltt.legend()
            else:
                axes.plot(bins, y, gauss_color)
            if draw_lines is True:
                # Draw a vertical line at the mu position
                line = Line2D([mu, mu], [0, numpy.max(y)], color=line_colors[1], label=r'$\mu$', alpha=0.5, lw=1.5)
                axes.add_line(line)
                if (abs(sigma) > 0.0):
                    # Draw a vertical line at the (mu - sigma) position
                    line = Line2D([mu - sigma, mu - sigma], [0, self.__CalcGauss([mu - sigma], mu, sigma)[0]],
                                  color=line_colors[0], label=r'$\mu$' + ' - ' + r'$\sigma$', alpha=0.5, lw=1.5)
                    axes.add_line(line)
                    # Draw a vertical line at the (mu + sigma) position
                    line = Line2D([mu + sigma, mu + sigma], [0, self.__CalcGauss([mu + sigma], mu, sigma)[0]],
                                  color=line_colors[2], label=r'$\mu$' + ' + ' + r'$\sigma$', alpha=0.5, lw=1.5)
                    axes.add_line(line)
        # otherwise just draw a line at the mean value
        else:
            if draw_lines is True:
                # Draw a vertical line at the mu position
                line = Line2D([mu, mu], [0, 1], color=line_colors[1], label=r'$\mu$', alpha=0.5, lw=1.5)
                axes.add_line(line)

        if write_text is not None:
            # Write down the values for mu and sigma
            axes.text(0.01, write_text, r'$\mu$' + ' = ' + "%0.2f" % mu + ', ' + r'$\sigma$' + ' = ' + "%0.2f" %
                      sigma, transform=axes.transAxes)
        if tick_labels is not None:
            axes.set_xticklabels(tick_labels)
        # Setting axis labels and title if provided
        if ylabel is not None:
            axes.set_ylabel(ylabel)
        if xlabel is not None:
            axes.set_xlabel(xlabel)
        if title is not None:
            axes.set_title(title)
        pltt.axis('tight')
        return pltt

    def GetScatterPlot(self, data, data_names, x_axis_name, y_axis_name,
                       bool_line, bool_legend, x_value_step=0, y_value_step=0,
                       line_colors=None, line_styles=None,
                       fig_width=10, fig_height=3, title=None,
                       line_markers=None, line_width=None,
                       x_axis_ext=False, y_axis_ext=None,
                       xticks_labels=None, yticks_labels=None, axes=None):  # pylint: disable=W0613,R0914
        """ Create a plot with two lines.
        :param data: Array of pair point lists representing data lines
        :param data_names: Name of the data lines
        :param x_axis_name: Name written on the x-axis.
        :param y_axis_name: Name written on the y-axis.
        :param bool_line: True for a line plot, False for a scatter plot.
        :param bool_legend: True for a legend and False for no legend.
        :param x_value_step: Value step on the x-axis. Default automatic.
        :param y_value_step: Value step on the y-axis. Default automatic.
        :param line_colors: Array of line colors (lenth of data needs to be equal) defined in DEF_COLORS
        :param line_styles: Array of line styles (lenth of data needs to be equal) defines in DEF_LINE_STYLES
        :param fig_width: The width of the figure (default = 10)
        :param fig_height: The height of the figure (default = 3)
        :param title: Title of the figure to be added
        :param line_markers: Array of line markers (lenth of data needs to be equal) defines in DEF_LINE_MARKERS
        :param y_axis_ext: By default extends by 10% of the maximum. If the min and max values are passed as a list,
                           this new list is taken as the limit [min,max]. Anyother value performs no extension
        :param x_axis_ext: Extend the x-axis scaling by 10% of the maximum.
        :param xticks_labels: List of strings labeling the ticks for the x-axis.
        :param yticks_labels: List of strings labeling the ticks for the y-axis.
        """
        _ = y_axis_ext  # Just fixed pylint unsed warning
        axes = self.__GetAppropriateAxes(axes, fig_width=fig_width, fig_height=fig_height)

        self.GeneratePlot(data, data_names, x_axis_name, y_axis_name,
                          bool_line, bool_legend,
                          x_value_step, y_value_step,
                          line_colors, line_styles,
                          fig_width, fig_height, title,
                          line_markers, line_width, x_axis_ext, y_axis_ext=None, plot_type=None, barWidth=None,
                          xticks_labels=xticks_labels, yticks_labels=yticks_labels, axes=axes)
        return self.__valfig.GetPlot()

    def GeneratePlot(self, data, data_names, x_axis_name, y_axis_name, bool_line, bool_legend,
                     x_value_step=0, y_value_step=0, line_colors=None, line_styles=None,
                     fig_width=10, fig_height=3, title=None, line_markers=None, line_width=None,
                     x_axis_ext=None, y_axis_ext=None, plot_type=None, barWidth=None,
                     xticks_labels=None, yticks_labels=None, axes=None):  # pylint: disable=R0912, R0914, R0915, W0613

        """ Create a scatter or bar plot .
        :param data: Array of pair point lists representing data lines
        :param data_names: Name of the data lines
        :param x_axis_name: Name written on the x-axis.
        :param y_axis_name: Name written on the y-axis.
        :param bool_line: True for a line plot, False for a scatter plot.
        :param bool_legend: True for a legend and False for no legend.
        :param x_value_step: Value step on the x-axis. Default automatic.
        :param y_value_step: Value step on the y-axis. Default automatic.
        :param line_colors: Array of line colors (lenth of data needs to be equal) defined in DEF_COLORS
        :param line_styles: Array of line styles (lenth of data needs to be equal) defines in DEF_LINE_STYLES
        :param fig_width: The width of the figure (default = 10)
        :param fig_height: The height of the figure (default = 3)
        :param title: Title of the figure to be added
        :param line_markers: Array of line markers (lenth of data needs to be equal) defines in DEF_LINE_MARKERS
        :param x_axis_ext: Extend the x-axis scaling by 10% of the maximum.
        :param y_axis_ext: By default extends by 10% of the maximum. If the min and max values are passed as a list,
                           this new list is taken as the limit [min,max]. Anyother value performs no extension
        :param plot_type: List of plottypes ("Bar" or "Scatter")
        :param xticks_labels: List of strings labeling the ticks for the x-axis.
        :param yticks_labels: List of strings labeling the ticks for the y-axis.
        """
        _, _ = x_value_step, y_value_step

        axes = self.__GetAppropriateAxes(axes, fig_width=fig_width, fig_height=fig_height)
        if line_colors is not None and len(line_colors) != len(data):
            line_colors = None
        if line_styles is not None and len(line_styles) != len(data):
            line_styles = None
        if line_markers is not None and len(line_markers) != len(data):
            line_markers = None
        if line_width is not None and len(line_width) != len(data):
            line_width = None

        kw = {}
        min_x = 10000
        min_y = 10000
        max_x = -10000
        max_y = -10000
        for i in range(len(data)):
            kw = {}
            xdata, ydata = pp.SplitPairList(data[i])

            if xdata is None or len(xdata) == 0:
                continue
            min_xi = min(xdata)
            min_yi = min(ydata)
            max_xi = max(xdata)
            max_yi = max(ydata)
            if min_xi < min_x:
                min_x = min_xi
            if min_yi < min_y:
                min_y = min_yi
            if max_xi > max_x:
                max_x = max_xi
            if max_yi > max_y:
                max_y = max_yi
            if i < len(data_names):
                kw['label'] = data_names[i]
            else:
                try:
                    kw.pop('label')
                except StandardError:
                    pass

            if line_colors is not None:
                kw['color'] = line_colors[i]
            else:
                kw['color'] = DEF_COLORS[i % len(DEF_COLORS)]

            if line_styles is not None:
                kw['linestyle'] = line_styles[i]

            if line_width is not None:
                kw['linewidth'] = line_width[i]

            if line_markers is not None and line_markers[i] != "None":
                kw['marker'] = line_markers[i]
                kw['markerfacecolor'] = kw['color']
                kw['markeredgecolor'] = kw['color']
                kw['markersize'] = 3
            else:
                if bool_line is False:
                    kw['marker'] = DEF_LINE_MARKERS[1:][i % (len(DEF_LINE_MARKERS) - 1)]

            if bool_line is False:
                kw['linestyle'] = DEF_LINE_STYLES[4]

            if plot_type is not None:
                if plot_type[i] == "Bar":
                    if barWidth is not None:
                        kw['width'] = barWidth[i]
                    else:
                        kw['width'] = 5
                    axes.bar(xdata, ydata, **kw)  # pylint: disable=E1103,W0142
                else:
                    axes.plot(xdata, ydata, **kw)  # pylint: disable=E1103,W0142
            else:
                if len(xdata) == 1:
                    kw['marker'] = DEF_LINE_MARKERS[(i % (len(DEF_LINE_MARKERS) - 1)) + 1]
                    kw['linestyle'] = DEF_LINE_STYLES[4]
                axes.plot(xdata, ydata, **kw)  # pylint: disable=E1103,W0142

        if y_axis_ext is None:
            if math.fabs(max_y) > math.fabs(min_y):
                delta_y = 0.1 * math.fabs(max_y)
            else:
                delta_y = 0.1 * math.fabs(min_y)

            ylim = [min_y - delta_y, max_y + delta_y]
        elif len(y_axis_ext) == 2:
            ylim = y_axis_ext
        else:
            ylim = [min_y, max_y]

        delta_x = 0.0

        if x_axis_ext is None:
            # Do a x axis scaling extension
            if math.fabs(max_x) > math.fabs(min_x):
                delta_x = 0.1 * math.fabs(max_x)
            else:
                delta_x = 0.1 * math.fabs(min_x)
            xlim = [min_x - delta_x, max_x + delta_x]
        elif len(x_axis_ext) == 2:
            xlim = x_axis_ext
        else:
            xlim = [min_x, max_x]

        axes.set_xlim(xlim)  # pylint: disable=E1103
        axes.set_ylim(ylim)  # pylint: disable=E1103

        axes.set_xlabel(x_axis_name, fontsize=8, verticalalignment='center')  # pylint: disable=E1103
        axes.set_ylabel(y_axis_name, fontsize=8)  # pylint: disable=E1103
        if xticks_labels is not None:
            axes.set_xticklabels(xticks_labels)  # pylint: disable=E1103
        if yticks_labels is not None:
            axes.set_yticklabels(yticks_labels)  # pylint: disable=E1103

        if title is not None:
            axes.set_title(title, fontsize=8)  # pylint: disable=E1103

        if bool_legend:
            font_prop = FontProperties(size=8)
            axes.legend(ncol=len(data), prop=font_prop)  # pylint: disable=E1103

        return self.__valfig.GetPlot()

    def GetBarPlot(self, axes, bar_data, bar_pos, x_axis_name, y_axis_name,
                   title=None, xticks=None, xticks_labels=None, x_axis_ext=None,
                   yticks=None, yticks_labels=None, y_axis_ext=None, bar_width=0.9,
                   bar_orientation='vertical', **kwargs):  # pylint: disable=R0914
        """ Interface Wrapper of Method GetBarPlot for backward compatibility
            use GetBarChart instead
        """
        # handle bar_pos
        _, _ = self.GetBarChart(axes, bar_data, xlabel=x_axis_name, ylabel=y_axis_name,
                                title=title, xticks=xticks, xticks_labels=xticks_labels,
                                x_axis_ext=x_axis_ext, yticks=yticks, yticks_labels=yticks_labels,
                                y_axis_ext=y_axis_ext, rwidth=bar_width, bar_pos=bar_pos,
                                bar_orientation=bar_orientation, **kwargs)

        return self.__valfig.GetPlot()

    def GetMedianPlot(self, axes, data, x_axis_name, y_axis_name, title=None,
                      xticks_labels=None, y_axis_ext=None,
                      box_width=0.5, whisker_box_ratio=1.5, notched_box=False,
                      outlier_sym='+', vert_orientation=True, **kwargs):  # pylint: disable=R0914
        """ Generate a Media Plot of the given data

        :param axes: Axes of the figure
        :type axes: Axes or ValdationFigure
        :param data: plot data
        :type data: list of name
        :param x_axis_name: label of x-axis
        :type x_axis_name: str
        :param y_axis_name: label for y-axis
        :type y_axis_name: str
        :param title: title of the plot
        :type title: str
        :param y_axis_ext: addtional extension to y-axis typically max value of the y axis
        :type y_axis_ext: int
        :param box_width: width of the box
        :type box_width: int
        :param whisker_box_ratio: plot whisker ratio
        :type whisker_box_ratio: int
        :param notched_box: flag to control notch for box plot
        :param outlier_sym: outline symbol e.g. '+' '-'  '*'
        :type outlier_sym: char
        :param vert_orientation: plot orientiation flag
        :type vert_orientation: boolean
        """

        axes = self.__GetAppropriateAxes(axes)

        # boxplot crashes if the given data vector is empty
        if(len(data) > 0):
            axes.boxplot(data, notch=notched_box, sym=outlier_sym, vert=vert_orientation, whis=whisker_box_ratio,
                         widths=box_width, **kwargs)

        if title is not None:
            axes.set_title(title, fontsize=8)
        axes.set_xlabel(x_axis_name, fontsize=8, verticalalignment='center')
        axes.set_ylabel(y_axis_name, fontsize=8)

        if y_axis_ext is None:
            max_y = max(data)
            min_y = min(data)
            delta_y = 0.05 * math.fabs(max_y - min_y)
            ylim = [min_y - delta_y, max_y + delta_y]
        elif len(y_axis_ext) == 2:
            ylim = y_axis_ext
        else:
            ylim = [min(data), max(data)]

        axes.set_ylim(ylim)

        if xticks_labels is not None:
            axes.set_xticklabels(xticks_labels, fontsize=8)

        return self.__valfig.GetPlot()

    def GetGaussPlot(self, data, title, x_axis_name, y_axis_name, legend_data=None,
                     legend_reg=False, fig_width=5, fig_height=3, ticks=None, y_axis_ext=None,
                     barWidth=None, plottypes=None, line_colors=None):  # pylint: disable=W0613, R0914
        """
        @deprecated: Use the new GetHistogram and GetNormalPdf functions (examples in the Valiplot unit test script)
        """
        warnings.warn('Method GetGaussPlot() is deprecated ', stacklevel=2)
        _, _, _, _, _, = data, title, x_axis_name, y_axis_name, legend_data  # these are only to fix pylint error
        _, _, _, _, _, = legend_reg, fig_width, fig_height, ticks, y_axis_ext  # for unused parameter
        _, _, _ = barWidth, plottypes, line_colors
        return None

    def GetPieChart(self, axes, data, title=None, labels=None, legend=None, colors=None, labels_fontsize=None,
                    legend_fontsize=6, **kwargs):
        """ Plots a pie chart.
        :param axes: axes handle
        :type axes: ValidationFigure or axes
        :param data: List of values; The fractional area of each wedge is given by x/sum(x)
        :param title: a title for the figure
        :param labels: list of strings as a description of the wedges (must be same length as data)
        :param legend: if set True: labels are given as a legend if list of strings: custom legend
        :param colors: list of colors for the wedges
        :param labels_fontsize: size for the labels
        :param legend_fontsize: size for the legend , by default the value is 6
        :param **kwargs: keyword arguments for the matplotlib pie function
            e.g. explode (a len(data) array which specifies the fraction of the radius with which to offset each wedge)
            e.g. shadow (False or True)
            note: startangle -> not in matplotlib 1.0.1
        """
        axes = self.__GetAppropriateAxes(axes)

        if labels is not None:
            if len(labels) != len(data):
                labels = None

        if colors is None or len(colors) != len(data):
            colors = []
            for i, _ in enumerate(data):
                colors.append(DEF_COLORS[i])

        ret = pltt.pie(data, labels=labels, colors=colors, **kwargs)
        # print(ret)
        texts = ret[1]
        # print(texts)
        if labels_fontsize is not None:
            for text in texts:
                text.set_fontsize(labels_fontsize)

        if title is not None:
            pltt.title(title, bbox={'facecolor': '0.8', 'pad': 5})

        if len(data) > 1:
            no_of_col = int(math.ceil(float(len(data)) / 2))
        else:
            no_of_col = len(data)

        if legend is not None and legend is not True:
            leg = axes.legend(legend, bbox_to_anchor=(1.05, 1.10), loc=1,
                              prop={'size': legend_fontsize}, ncol=no_of_col)
            leg.get_frame().set_alpha(0.5)
        elif legend and labels:
            leg = axes.legend(labels, bbox_to_anchor=(1.05, 1.10), loc=1,
                              prop={'size': legend_fontsize}, ncol=no_of_col)
            leg.get_frame().set_alpha(0.5)

        return self.__valfig.GetPlot()

    def SetImageDataBuffer(self, img_data):
        """Set the Image DataBuffer loaded from DB

        :param img_data: buffer of the image data
        :type img_data: buffer
        """
        self.__img_data = img_data

    def GetPlotDataBuffer(self, pltt_=None, grid=None, fontsize=8):
        """ Get a buffer containing the plot image
        :param plt: plot (if 'None', the stored plot is used)
        :return: Buffer of data
        """
        _ = pltt_  # unsed parameter warning Fix
        plot_for_saving = BasePlot(figure=self.__valfig.GetFig(), fontsize=fontsize)
        if grid is not None:
            plot_for_saving.set_grid(grid)
        else:
            plot_for_saving.set_grid(self.__valfig.GetShowGrid())

        filepointer = tempfile.NamedTemporaryFile(mode='r+b', suffix="." + DEFAULT_OUTPUT_FILEEXT,
                                                  prefix='Valf_', dir=self.__out_path, delete=False)
        plot_for_saving.save(filepointer.name, dpi=400, papertype=None)
        buf = buffer(filepointer.read())
        filepointer.close()
        os.unlink(filepointer.name)

        return buf

    def GetDrawing(self, file_name=None, width=DRAWING_W, height=DRAWING_H):
        """Get the drawing of the stored image of the current plot
        :param file_name: file name
        :type file_name: str
        :param width: width of the drawing
        :type width: int
        :param height: height of the drawing
        :type height: int
        """

        if self.__img_data is not None:
            return self.GetDrawingFromBuffer(self.__img_data,
                                             file_name=file_name,
                                             width=width, height=height)
        else:
            img_data = self.GetPlotDataBuffer()
            return self.GetDrawingFromBuffer(img_data, file_name=file_name,
                                             width=width, height=height)

    def GetDrawingFromBuffer(self, draw_data, file_name=None, width=None, height=None):
        """ Converts the given Drawing object into a string
        :param draw_data: Drawing as Buffer
        :param file_name: File name extension
        :param width: Width of the new drawing (optional)
        :param height: Height of the new drawing (optional)
        """
        if self.__valfig is not None:
            if width is None:
                width = self.GetWidth() * self.__valfig.GetFig().dpi
            if height is None:
                height = width * self.GetHeight() / self.GetWidth()

        if width is None and height is None:
            return None

        if draw_data is not None:

            # store the file into the temp output path
            if file_name is not None:
                if len(file_name) > 100:
                    logging.info("image file name >= 100 characters will be truncated")
                    file_name = file_name[0:96] + "_" + str(self.__file_counter)
                    self.__file_counter += 1
                filename = os.path.join(self.__out_path, "%s.%s" % (file_name, DEFAULT_OUTPUT_FILEEXT))
                if(len(filename) >= 255):
                    logging.info("Path to image file >= 255 characters is used")
                    filename = "\\\\?\\" + filename
                    f = file(filename, "wb")
                else:
                    f = file(filename, "wb")
            else:
                f = tempfile.NamedTemporaryFile(mode='w+b', suffix="." + DEFAULT_OUTPUT_FILEEXT,
                                                prefix='ValfReport_', dir=self.__out_path, delete=False)
                filename = f.name

            f.write(draw_data)
            f.close()
            # image from file
            d = Drawing(width, height)
            inPath = str(filename)
            img = Image(0, 0, width, height, inPath)
            d.add(img)
            return d
        return None

    def PlotRelevance(self, array_val, pattern, Gauss=True, percent_data=None, offset=None):
        """ Plot Relevance Statistics
            Do not use the function is deprecated
        """
        warnings.warn('Method PlotRelevance is deprecated', stacklevel=2)

        for i, x in enumerate(array_val):
            if x is None:
                array_val.pop(i)
        # for bar plot
        no_tiks = len(pattern)
        # pattern = [0] * no_tiks
        # pattern = [x*10 for x in range(no_tiks)]
        # offset = abs(pattern[1]-pattern[0])/2
        no_bars = no_tiks - 1
        # distribution=[]
        distribution = [0] * no_bars
        for i in range(no_bars):
            count = 0
            for data in array_val:
                if(data >= pattern[i] and data < pattern[i + 1]):
                    count += 1
            distribution[i] = count
        count = 0
        for data in array_val:
            if(data == pattern[no_tiks - 1]):
                count += 1
        distribution[no_bars - 1] = distribution[no_bars - 1] + count
        length = len(array_val)
        pattern_process = []
        pattern_process[:] = pattern[0: no_bars]
        # pattern_offset=[]
        distribution_new = []
        pattern_offset_new = []
        if percent_data is None:
            distribution = [x * 100 / length for x in distribution]
        else:
            for i in range(no_bars):
                distribution[i] = distribution[i] * 100 / percent_data[i]

        if Gauss is True:
        # for gaussian plot
            # making an offset of 3 for making the width thick for the bars
            # pattern_offset = [x+1.5 for x in pattern_process]
            offset_val = 0
            if offset is not None:
                offset_val = offset
            pattern_offset = [x + offset_val for x in pattern_process]
            for i in range(len(distribution)):
                if(distribution[i] != 0):
                    distribution_new.append(distribution[i])
                    pattern_offset_new.append(pattern_offset[i])

            distribution = None
            # pattern_offset = None

            precision = abs(pattern[1] - pattern[0])
            single_range = (float(precision) / 50)
            # increasing the magnitude because range doesnt work for float
            # range_gauss = range(0.0,1000.0,(single_range*10))
            # range_gauss = [float(x)/10 for x in range_gauss]
            range_gauss = [float(x) * single_range for x in range(min(pattern_process), max(pattern_process) * 10)]
            meanval = npc.mean(array_val)
            # stddev2= npc.std(array_val)
            stddev = self.sd(meanval, array_val)

            mean_stddev = []
            mean_stddev.append(meanval - stddev)
            mean_stddev.append(meanval - stddev)
            gauss_arr = [0] * 2
            if (abs(stddev) > 0.0):
                gauss = self.__CalcGauss(range_gauss, meanval, stddev)
                max_gauss = max(gauss)
                x = self.__CalcGauss([meanval - stddev], meanval, stddev)
                gauss_arr[1] = (100 * x[0]) / max_gauss
                gauss_ar = [100 * temp / max_gauss for temp in gauss]
            else:
                gauss = [0] * len(range_gauss)
                gauss_ar = gauss

            data = []
            data.append(pp.GetPointPairList(pattern_offset_new, distribution_new))  # bars
            data.append(pp.GetPointPairList([meanval, meanval], [0, 100]))  # mean
            data.append(pp.GetPointPairList(mean_stddev, gauss_arr))  # mean - standard deviation
            data.append(pp.GetPointPairList(range_gauss, gauss_ar))  # gauss

            meanval = round(meanval, 3)
            stddev = round(stddev, 3)

            return data, meanval, stddev
        else:
            for i in range(len(distribution)):
                if(distribution[i] != 0):
                    distribution_new.append(distribution[i])
                    temp_pattern = float(pattern_process[i]) / 100
                    temp_pattern = round(temp_pattern, 2)
                    pattern_offset_new.append(temp_pattern)

            data = pp.GetPointPairList(pattern_offset_new, distribution_new)
            return [data]

    def __CalcGauss(self, value, MeanVal, StdDev):
        """Calculate the gaussian function
            Function is deprecated - do not use
        :param value: list of value
        :type value: list of int
        :param MeanVal: mean value
        :type MeanVal: int
        :param StdDev: standard deviation
        :type StdDev: int
        :return gauss: list of values represing gaussian curve
        :type gauss: list of int
        """

        if (abs(StdDev) > 0.0):
            gauss = [math.exp(-1 * (pow((v - MeanVal), 2) / (2 * pow(StdDev, 2)))) /
                     (StdDev * math.sqrt(2 * math.pi)) for v in value]
        else:
            gauss = [0 for v in value]
        return gauss

    def __GetAppropriateAxes(self, axes, fig_width=10, fig_height=3):
        """Get the appropriate reference of Axes with following precedence sequence
        *    axes from ValidationFigure
        *    axes from last generated ValidationFigure
        *    axes from new ValidationFigure
        :param axes: existing axes
        :type axes: can be matplot Axes/None/ValdiationFigure
        :param fig_width: width of figure
        :param fig_height: height of the figure
        :return axes: Return Axes
        :type axes: matplot Axes
        """
        if type(axes) == ValidationFigure:
            axes = axes.GetAxes()
        elif self.__valfig is not None and axes is None:
            axes = self.__valfig.GetAxes()
        elif axes is None:
            axes = self.GenerateFigure(fig_width=fig_width, fig_height=fig_height)
        return axes

"""
 $Log: plot.py  $
 Revision 1.1 2021/12/13 17:57:52CET Wang, David (Wangd3) 
 Initial revision
 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/img/project.pj
 Revision 1.31 2013/10/30 17:48:32CET Hecker, Robert (heckerr) 
 Fixed wrong usage of logger module.
 - Added comments -  heckerr [Oct 30, 2013 5:48:32 PM CET]
 Change Package : 204146:1 http://mks-psad:7002/im/viewissue?selection=204146
 Revision 1.30 2013/10/23 13:30:18CEST Raedler, Guenther (uidt9430) 
 - fixed barchart and getDrawing from buffer (by JW and AV)
 --- Added comments ---  uidt9430 [Oct 23, 2013 1:30:18 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.29 2013/09/19 13:30:09CEST Ahmed-EXT, Zaheer (uidu7634)
 -- New Class added ValidationFigure the functionality of figure handling from ValidationPlot moved to new class
   - added __GetAppropriateAxes() in ValdiationPlot
    - bugfix for showgrid in GetPlotDataBuffer
     - Added feature of height and width adjustment in GetDrawingBuffer to be taken from figure or provided as arguement
 --Improved documentation
 --removed commented code
 --fixed pep8 and pylint errors
 --- Added comments ---  uidu7634 [Sep 19, 2013 1:30:09 PM CEST]
 Change Package : 196580:2 http://mks-psad:7002/im/viewissue?selection=196580
 Revision 1.28 2013/09/12 17:52:32CEST Verma-EXT, Ajitesh (uidv5394)
 changes in legends:
 - adding the legends fontsize
 - no of coloumns in legends
 --- Added comments ---  uidv5394 [Sep 12, 2013 5:52:32 PM CEST]
 Change Package : 196582:1 http://mks-psad:7002/im/viewissue?selection=196582
 --- Added comments ---  uidv5394 [Sep 12, 2013 5:53:49 PM CEST]
 change in GetPieChart function
 Revision 1.27 2013/09/12 14:02:13CEST Raedler, Guenther (uidt9430)
 - fixed problem if filename is not given in (GetDrawingFromBuffer)
 - implememt automatic scaling of images
 --- Added comments ---  uidt9430 [Sep 12, 2013 2:02:13 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.26 2013/09/06 12:58:12CEST Raedler, Guenther (uidt9430)
 - fixed error for default condition
 --- Added comments ---  uidt9430 [Sep 6, 2013 12:58:12 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.25 2013/08/09 16:10:08CEST Raedler, Guenther (uidt9430)
 - improved bar plot functions (changes by JW)
 --- Added comments ---  uidt9430 [Aug 9, 2013 4:10:08 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.24 2013/08/06 16:30:12CEST Raedler, Guenther (uidt9430)
 - fixed BarPlot issues
 --- Added comments ---  uidt9430 [Aug 6, 2013 4:30:12 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.23 2013/08/06 10:54:24CEST Dintzer, Philippe (dintzerp)
 - handle long paths > 255 chars
 --- Added comments ---  dintzerp [Aug 6, 2013 10:54:25 AM CEST]
 Change Package : 175136:3 http://mks-psad:7002/im/viewissue?selection=175136
 Revision 1.22 2013/08/02 12:49:20CEST Raedler, Guenther (uidt9430)
 - created method GetPieChart()
 --- Added comments ---  uidt9430 [Aug 2, 2013 12:49:20 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.21 2013/07/30 14:08:32CEST Raedler, Guenther (uidt9430)
 - added documentation
 - revert removal of __CalcGauss
 --- Added comments ---  uidt9430 [Jul 30, 2013 2:08:32 PM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.20 2013/07/30 08:17:33CEST Raedler, Guenther (uidt9430)
 - extended GetBarChart()
   * changed data interface
   * support stacked bar charts
   * support regression bar charts including req value line
 - fixed wrong default value in GeneratePlot()
 - use numpy.mlab to calc. norm pdf  in GetNormalPdf()
 - use GetBarPlot() as wrapper funktion. Internally we use the GetBarChart
 - removed unused methods sd() and __CalcGauss()
 - started implementing module tests
 --- Added comments ---  uidt9430 [Jul 30, 2013 8:17:33 AM CEST]
 Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
 Revision 1.19 2013/07/15 15:34:52CEST Raedler, Guenther (uidt9430)
 - optimized file handling
 - fixed marker issue
 --- Added comments ---  uidt9430 [Jul 15, 2013 3:34:52 PM CEST]
 Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
 Revision 1.18 2013/07/03 07:39:41CEST Raedler, Guenther (uidt9430)
 - added new methods GetBarPlot() and GetMedianPlot()
 - fixed errors in GeneratePlot
 - improved save plot using pil.image
 --- Added comments ---  uidt9430 [Jul 3, 2013 7:39:41 AM CEST]
 Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
 Revision 1.17 2013/06/14 09:31:12CEST Mertens, Sven (uidv7805)
 method for retrieving pure PIL image from plot needed
 --- Added comments ---  uidv7805 [Jun 14, 2013 9:31:12 AM CEST]
 Change Package : 185933:2 http://mks-psad:7002/im/viewissue?selection=185933
 Revision 1.16 2013/06/05 16:22:30CEST Raedler, Guenther (uidt9430)
 - exended interface of Validation Plot to support the class as result_type
  * added __str__(), GetWidth(), GetHeight(), GetTitle(), SetImageDataBuffer(), GetDrawing()
 --- Added comments ---  uidt9430 [Jun 5, 2013 4:22:31 PM CEST]
 Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
 Revision 1.15 2013/05/28 07:40:10CEST Raedler, Guenther (uidt9430)
 - fixed wrong path ussage due to pylint corrections
 --- Added comments ---  uidt9430 [May 28, 2013 7:40:10 AM CEST]
 Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
 Revision 1.14 2013/05/24 14:14:44CEST Raedler, Guenther (uidt9430)
 - use tempfile from os to store output image
 - improved x-axis handling
 - avoid div 0
 --- Added comments ---  uidt9430 [May 24, 2013 2:14:45 PM CEST]
 Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
 Revision 1.13 2013/05/17 13:08:20CEST Raedler, Guenther (uidt9430)
 - fixed gaussian calc function
 - fixed pylint warning error
 - added documentation
 --- Added comments ---  uidt9430 [May 17, 2013 1:08:20 PM CEST]
 Change Package : 183302:1 http://mks-psad:7002/im/viewissue?selection=183302
 Revision 1.12 2013/03/28 14:20:08CET Mertens, Sven (uidv7805)
 pylint: solving some W0201 (Attribute %r defined outside __init__) errors
 --- Added comments ---  uidv7805 [Mar 28, 2013 2:20:08 PM CET]
 Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
 Revision 1.11 2013/03/27 13:51:25CET Mertens, Sven (uidv7805)
 pylint: bugfixing and error reduction
 Revision 1.10 2013/03/22 09:20:51CET Mertens, Sven (uidv7805)
 last pep8 update on non-trailing white space errors
 Revision 1.9 2013/03/22 08:24:31CET Mertens, Sven (uidv7805)
 aligning bulk of files again for peping 8
 --- Added comments ---  uidv7805 [Mar 22, 2013 8:24:31 AM CET]
 Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
 Revision 1.8 2013/03/05 11:09:43CET Raedler, Guenther (uidt9430)
 - revert unexpected changes for pep8 checks
 --- Added comments ---  uidt9430 [Mar 5, 2013 11:09:44 AM CET]
 Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
 Revision 1.7 2013/03/04 13:35:01CET Raedler, Guenther (uidt9430)
 - fixed failure after pep8 updates in version 1.2
 --- Added comments ---  uidt9430 [Mar 4, 2013 1:35:02 PM CET]
 Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
 Revision 1.6 2013/03/01 09:42:49CET Hecker, Robert (heckerr)
 Updates regarding Pep8 Styleguide.
 --- Added comments ---  heckerr [Mar 1, 2013 9:42:49 AM CET]
 Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
 Revision 1.5 2013/02/28 08:12:27CET Hecker, Robert (heckerr)
 Updates regarding Pep8 StyleGuide (partly).
 --- Added comments ---  heckerr [Feb 28, 2013 8:12:28 AM CET]
 Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
 Revision 1.4 2013/02/27 17:55:13CET Hecker, Robert (heckerr)
 Removed all E000 - E200 Errors regarding Pep8.
 --- Added comments ---  heckerr [Feb 27, 2013 5:55:13 PM CET]
 Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
 Revision 1.3 2013/02/27 16:20:00CET Hecker, Robert (heckerr)
 Updates regarding Pep8 StyleGuide (partly).
 --- Added comments ---  heckerr [Feb 27, 2013 4:20:00 PM CET]
 Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
 Revision 1.2 2013/02/26 20:13:10CET Raedler, Guenther (uidt9430)
 - Updates after Pep8 Styleguides
 --- Added comments ---  uidt9430 [Feb 26, 2013 8:13:11 PM CET]
 Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
 Revision 1.1 2013/02/11 10:13:49CET Raedler, Guenther (uidt9430)
 Initial revision
 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
 05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/img/project.pj
 ------------------------------------------------------------------------------
-- Merge from stkPlot and ETK/VPC Archive
------------------------------------------------------------------------------
 Revision 1.18 2012/11/15 10:24:58CET Hammernik-EXT, Dmitri (uidu5219)
 - added additional argument to GetPlotDataBuffer
 --- Added comments ---  uidu5219 [Nov 15, 2012 10:25:02 AM CET]
 Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
 Revision 1.17 2012/08/24 09:03:34CEST Hammernik-EXT, Dmitri (uidu5219)
 - added posibility to draw bars with overlaping
 --- Added comments ---  uidu5219 [Aug 24, 2012 9:03:34 AM CEST]
 Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
 Revision 1.16 2012/08/08 11:25:20CEST Ibrouchene-EXT, Nassim (uidt5589)
 Created new functions for plotting histograms, bar charts and normal distributions.
 Added GenerateFigure() method, which shall be used before using any plotting functions.
 Supports subplotting.
 --- Added comments ---  uidt5589 [Aug 8, 2012 11:25:20 AM CEST]
 Change Package : 151927:1 http://mks-psad:7002/im/viewissue?selection=151927
 Revision 1.15 2012/06/28 13:49:27CEST Sampat-EXT, Janani Vasumathy (uidu5218)
 - gauss plots updated
 --- Added comments ---  uidu5218 [Jun 28, 2012 1:49:27 PM CEST]
 Change Package : 97504:2 http://mks-psad:7002/im/viewissue?selection=97504
 Revision 1.14 2012/04/17 17:45:07CEST Sampat-EXT, Janani Vasumathy (uidu5218)
 - added histogram calulation and plotting
 - added gaussian plot calulation and plotting
 --- Added comments ---  uidu5218 [Apr 17, 2012 5:45:07 PM CEST]
 Change Package : 110628:1 http://mks-psad:7002/im/viewissue?selection=110628
 Revision 1.13 2011/12/07 11:00:43CET Sampat-EXT, Janani Vasumathy (uidu5218)
 - included y-axis extension
 - increases width of the bar in bar plot
 --- Added comments ---  uidu5218 [Dec 7, 2011 11:00:44 AM CET]
 Change Package : 88149:1 http://mks-psad:7002/im/viewissue?selection=88149
 Revision 1.12 2011/11/29 13:07:27CET Sampat-EXT, Janani Vasumathy (uidu5218)
 - scatter plot condition improved
 Revision 1.11 2011/11/10 15:37:58CET Raedler-EXT, Guenther (uidt9430)
 - support bar plot again
 --- Added comments ---  uidt9430 [Nov 10, 2011 3:37:59 PM CET]
 Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.10 2011/11/09 12:51:51CET Raedler Guenther (uidt9430) (uidt9430)
 - fixed corrupted plots by using stk plot again
 --- Added comments ---  uidt9430 [Nov 9, 2011 12:51:51 PM CET]
 Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.9 2011/11/08 08:18:58CET Raedler Guenther (uidt9430) (uidt9430)
 - introduced new derived method to support both scatter and bar plots
 - added gaussplot method (to be moved into the stationary obstacle report)
 --- Added comments ---  uidt9430 [Nov 8, 2011 8:18:59 AM CET]
 Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.8 2011/11/03 13:32:29CET Ibrouchene Nassim (uidt5589) (uidt5589)
 Added the GetBarChart() function for drawing bar charts.
 --- Added comments ---  uidt5589 [Nov 3, 2011 1:32:30 PM CET]
 Change Package : 84651:1 http://mks-psad:7002/im/viewissue?selection=84651
 Revision 1.7 2011/10/27 15:36:06CEST Raedler Guenther (uidt9430) (uidt9430)
 - don't break if data is empty or None
 --- Added comments ---  uidt9430 [Oct 27, 2011 3:36:06 PM CEST]
 Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.6 2011/10/13 13:55:59CEST Raedler Guenther (uidt9430) (uidt9430)
 - added line_width and line_marker option to plot
 --- Added comments ---  uidt9430 [Oct 13, 2011 1:55:59 PM CEST]
 Change Package : 67780:6 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.5 2011/09/09 08:17:43CEST Spruck Jochen (spruckj) (spruckj)
 cast the filename for the image because filename from oracle db is unicode
 and reportlab checks filename for type string
 --- Added comments ---  spruckj [Sep 9, 2011 8:17:44 AM CEST]
 Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
 Revision 1.4 2011/09/05 15:59:50CEST Raedler Guenther (uidt9430) (uidt9430)
 -- added title for graphic plot
 --- Added comments ---  uidt9430 [Sep 5, 2011 3:59:50 PM CEST]
 Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.3 2011/08/11 10:50:52CEST Raedler Guenther (uidt9430) (uidt9430)
 -- extended plot function
 -- updates to support new stk_plot revision
 --- Added comments ---  uidt9430 [Aug 11, 2011 10:50:53 AM CEST]
 Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.2 2011/08/02 07:12:59CEST Raedler Guenther (uidt9430) (uidt9430)
 change axis max and min in plots
 --- Added comments ---  uidt9430 [Aug 2, 2011 7:12:59 AM CEST]
 Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
 Revision 1.1 2011/07/21 16:38:41CEST Raedler Guenther (uidt9430) (uidt9430)
 Initial revision
 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/05_Testing/
    05_Test_Environment/algo/em_req_test/valf_tests/vpc/project.pj
"""
