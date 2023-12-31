"""
stk/img/draw.py
-------------------

**Simple DrawMethods to generate charts.**

This module creates charts based on the reportlab charting possibility.

**Following Classes are available for the User-API:**

    - `PieChart`
    - `BarChart`
    - `LineChart`


:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:52CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from sys import maxint
from reportlab.lib.units import cm
from reportlab.lib.colors import HexColor
from reportlab.graphics.charts.piecharts import Pie as pie
from reportlab.graphics.charts.barcharts import VerticalBarChart
from reportlab.graphics.charts.lineplots import LinePlot, ScatterPlot
from reportlab.graphics.charts.legends import Legend
from reportlab.graphics.charts.textlabels import Label
from reportlab.graphics.shapes import Drawing, String
from reportlab.graphics.widgets.markers import makeMarker

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------

# Defines -------------------------------------------------------------------------------------------------------------
PDF_CHART_COLORS = ["#ff9900", "#5f5f5f", "#969696", "#ffce6a", "#ffefbb", "#c0c0c0", "#57718d", "#a6b6c8",
                    "#e6e9f0", "#000000", "#a00000", "#ff0000", "#00d000", "#ffffff"]

PDF_LINE_MARKERS = ['Cross', 'Circle', 'Square', 'Triangle', 'Diamond', 'StarSix', 'Pentagon', 'Hexagon',
                    'Heptagon', 'Octagon', 'StarFive', 'FilledSquare', 'FilledCircle', 'FilledDiamond', 'FilledCross',
                    'FilledTriangle', 'FilledStarSix', 'FilledPentagon', 'FilledHexagon', 'FilledHeptagon',
                    'FilledOctagon', 'FilledStarFive', 'Smiley', 'ArrowHead', 'FilledArrowHead']

# Classes -------------------------------------------------------------------------------------------------------------


def PieChart(data, **kw):
    """
    Function to Create a reportlab Drawing with a Pie Chart included.

    :param data:       1d array of data, e.g. [5, 10, 20, ...]
    :type data:        list[numbers]
    :kwarg kw:         list of optional keyword parameters
    :kwparam lables:   1d array of labels
    :type labels:      string
    :kwparam lblFrmt:  how to format the data, e.g. 5%
    :type lblFrmt:     format string
    :kwparam plotSize: size in pixels, e.g. (400, 200)
    :type plotSize:    Tuple
    :kwparam title:    title of pie chart
    :type title:       string
    :param legend:     true/false, when true, labels are displayed here, when false added to the pie
    :type legend:      bool
    """
    title = kw.pop('title', None)
    labels = kw.pop('labels', '%.1f%%')
    lblFrmt = kw.pop('lblFrmt', '%.1f%%')
    legend = kw.pop('legend', False)
    size = kw.pop('plotSize', (18 * cm, 9 * cm))

    # Create the drawing
    drawing = Drawing(size[0], size[1])

    # Create the Pie Chart
    chart = pie()

    for key, val in kw.items():
        setattr(chart, key, val)

    chart.x = 10
    chart.y = (drawing.height - chart.height) / 2
    chart.slices.strokeWidth = 1
    # self.chart.slices.popout = 1
    chart.direction = 'clockwise'
    chart.width = chart.height
    chart.startAngle = 90
    # self.chart.slices[0].popout = 10
    for i in xrange(len(data)):
        chart.slices[i].fillColor = HexColor(PDF_CHART_COLORS[i % len(PDF_CHART_COLORS)])

    chart.data = data
    chart.labels = [(lblFrmt % i) for i in chart.data]
    chart.checkLabelOverlap = True

    if title is not None:
        drawing.add(String(20, size[1] - 20, title), name='title')
        chart.y -= 10

    if legend:
        legend = Legend()
        legend.boxAnchor = 'w'
        legend.x = chart.width + 40
        legend.y = drawing.height / 2
        legend.subCols[1].align = 'right'
        legend.alignment = 'right'
        legend.columnMaximum = 7
        if labels is not None:
            legend.colorNamePairs = [(chart.slices[i].fillColor, labels[i]) for i in xrange(len(labels))]
        drawing.add(legend, name='legend')

    elif labels is not None:
        for i in xrange(min([len(labels), len(data)])):
            chart.labels[i] = labels[i]

    drawing.add(chart, name='chart')

    return drawing


def BarChart(data, labels, **kw):
    """
    :param data:    contains a two dimentional array of values, e.g. [[d11, d21, x1], [d12, d22, x2]]
    :type data:     list[list[numbers],...]
    :param labels:  can contain, but must not ["xlabel", "ylabel", ["data label0", ...]]
                    third item can also be an interger stating the iteration start as label
    :type lables:   ???
    :param ylim:    limit the y axis to these values, e.g. (0, 100)
    :type ylim:     ???
    :param bars:    list of colors we should use for the bars, refer to PDF_CHART_COLORS as an example
    :type bars:     ???
    :param size:    size in pixels, e.g. (8 * cm, 4 * cm) or pixels, e.g. (400, 200)
    :type size:     ???
    :param title:   title of bar chart
    :type title:    string
    :param stacked: weather to do a stacked bar plot or std column plot
    :type stacked:  ???
    """
    title = kw.pop('title', None)
    stacked = kw.pop('stacked', False)
    bars = kw.pop('bars', PDF_CHART_COLORS)
    size = kw.pop('plotSize', (18 * cm, 9 * cm))
    ylim = kw.pop('ylim', None)

    # Create the drawing
    drawing = Drawing(size[0], size[1])

    # Create the Chart
    chart = VerticalBarChart()

    for key, val in kw.items():
        setattr(chart, key, val)

    if title is not None:
        drawing.add(String(20, size[1] - 20, title), name='title')
        chart.y -= 10

    chart.width = drawing.width - 20
    chart.height = drawing.height - 40

    chart.data = data
    maxY = 0
    minY = maxint
    for i in xrange(len(data)):
        chart.bars[i].fillColor = HexColor(bars[i % len(bars)])
        maxY = max(data[i] + [maxY])
        minY = min(data[i] + [minY])
    chart.valueAxis.valueMax = maxY * 1.1
    chart.valueAxis.valueMin = minY * 0.9

    if ylim is not None:
        chart.valueAxis.valueMin = ylim[0]
        chart.valueAxis.valueMax = ylim[1]

    if len(data) > 1:
        chart.barSpacing = 2

    if labels is not None:
        if len(labels) > 0:
            xlabel = Label()
            xlabel._text = labels[0]  # pylint: disable=W0212
            xlabel.textAnchor = 'middle'
            xlabel.x = drawing.width / 2
            xlabel.y = 0
            chart.y += 15
            drawing.add(xlabel, name="xlabel")

        if len(labels) > 1:
            ylabel = Label()
            ylabel._text = labels[1]  # pylint: disable=W0212
            xlabel.textAnchor = 'middle'
            ylabel.angle = 90
            ylabel.x = 0
            ylabel.y = drawing.height / 2
            chart.x += 10
            drawing.add(ylabel, name="ylabel")

        if len(labels) > 2:
            if len(labels[2]) == max([len(x) for x in data]):
                chart.categoryAxis.categoryNames = labels[2]
                chart.categoryAxis.labels.angle = 30
            elif type(labels[2]) == int:
                chart.categoryAxis.categoryNames = xrange(labels[2], max([len(x) for x in data]) + labels[2])

    if stacked:
        chart.categoryAxis.style = 'stacked'

    drawing.add(chart, name='chart')

    return drawing


def LineChart(data, labels, **kw):
    """
    :param data:    contains a three dimensional array of values (list of lists of points)
                    or just a list of datapoint lists (it will be auto-transposed to start at 0)
    :type data:     list
    :param labels:  can contain, but must not ["xlabel", "ylabel", ["data label0", ...]]
                    third item can also be an interger stating the iteration start as label
                    when of same size as data, then a legend is added instead
    :type lables:   ???
    :param xlim:    limit the x axis to these values, e.g. (0, 100)
    :type xlim:     Tuple(Number, Number)
    :param ylim:    limit the y axis to these values, e.g. (0, 50)
    :type ylim:     Tuple(Number, Number)
    :param size:    size in pixels, e.g. (18*cm, 9*cm)
    :type size:     Tuple(Number, Number)
    :param title:   title of bar chart
    :type title:    string
    :param lines:   list of colors we should use to paint lines
    :type lines:    list[???]
    :param markers: list of markers we should use to draw markers
    :type markers:  list[`PDF_LINE_MARKERS`,...]
    :param scatter: weather to do a scatter plot or line chart
    :type scatter:  boolean
    """
    # Get all arguments from the keywordargs
    title = kw.pop('title', None)
    scatter = kw.pop('scatter', False)
    size = kw.pop('plotSize', (18 * cm, 9 * cm))
    lines = kw.pop('lines', PDF_CHART_COLORS)
    markers = kw.pop('markers', PDF_LINE_MARKERS)
    xlim = kw.pop('xlim', None)
    ylim = kw.pop('ylim', None)

    drawing = Drawing(size[0], size[1])

    chart = None

    if(scatter):
        chart = ScatterPlot()
    else:
        chart = LinePlot()

    for key, val in kw.items():
        setattr(chart, key, val)

    if title is not None:
        drawing.add(String(20, size[1] - 10, title), name='title')
        chart.y -= 10

    chart.width = drawing.width - 20
    chart.height = drawing.height - 40
    chart.x = 10
    chart.y = 10

    chart.data = data if type(data[0][0]) in (tuple, list) else [zip(xrange(len(i)), i) for i in data]

    maxY = 0
    minY = maxint
    for i in xrange(len(data)):
        chart.lines[i].strokeColor = HexColor(lines[i % len(lines)])
        if markers is not None:
            chart.lines[i].symbol = makeMarker(markers[i % len(markers)])
            chart.lines[i].symbol.size = 3
        maxY = max([k[1] for k in chart.data[i]] + [maxY])
        minY = min([k[1] for k in chart.data[i]] + [minY])
    chart.yValueAxis.valueMax = maxY * 1.1
    chart.yValueAxis.valueMin = minY * 0.9

    chart.xValueAxis.visibleGrid = True
    chart.yValueAxis.visibleGrid = True

    if xlim is not None:
        chart.xValueAxis.valueMin = xlim[0]
        chart.xValueAxis.valueMax = xlim[1]
    if ylim is not None:
        chart.yValueAxis.valueMin = ylim[0]
        chart.yValueAxis.valueMax = ylim[1]

    if scatter:
        chart.xLabel = ''
        chart.yLabel = ''
        chart.y -= 10
        chart.lineLabelFormat = None

    if labels is not None:
        if len(labels) > 0:
            xlabel = Label()
            xlabel._text = labels[0]  # pylint: disable=W0212
            xlabel.textAnchor = 'middle'
            xlabel.x = drawing.width / 2
            xlabel.y = 5
            chart.y += 15
            drawing.add(xlabel, name="xlabel")

        if len(labels) > 1:
            ylabel = Label()
            ylabel._text = labels[1]  # pylint: disable=W0212
            xlabel.textAnchor = 'middle'
            ylabel.angle = 90
            ylabel.x = 0
            ylabel.y = drawing.height / 2
            chart.x += 12
            drawing.add(ylabel, name="ylabel")

        if len(labels) > 2:
            # when labels are of same size as max nr of data point, use as x axis labels
            if len(labels[2]) == max([len(x) for x in data]):
                chart.categoryAxis.categoryNames = labels[2]  # pylint: disable=E1101
                chart.xValueAxis.labels.angle = 30  # pylint: disable=E1101
            # otherwise when integer use the counter
            elif type(labels[2]) == int:
                temp = xrange(labels[2], max([len(x) for x in data]) + labels[2])
                chart.categoryAxis.categoryNames = temp  # pylint: disable=E1101
            # or we could add a legend when of same size as data
            elif len(labels[2]) == len(data):
                legend = Legend()
                chart.height -= 8
                chart.y += 8
                xlabel.y += 8
                legend.boxAnchor = 'sw'
                legend.x = chart.x + 8
                legend.y = -2
                legend.columnMaximum = 1
                legend.deltax = 50
                legend.deltay = 0
                legend.dx = 10
                legend.dy = 1.5
                legend.fontSize = 7
                legend.alignment = 'right'
                legend.dxTextSpace = 5
                legend.colorNamePairs = [(HexColor(lines[i]), labels[2][i]) for i in xrange(len(chart.data))]
                legend.strokeWidth = 0
                drawing.add(legend, name='legend')

    drawing.add(chart, name='chart')

    return drawing


"""
CHANGE LOG:
-----------
$Log: draw.py  $
Revision 1.1 2021/12/13 17:57:52CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/img/project.pj
Revision 1.1 2013/10/22 16:11:05CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/img/project.pj
"""
