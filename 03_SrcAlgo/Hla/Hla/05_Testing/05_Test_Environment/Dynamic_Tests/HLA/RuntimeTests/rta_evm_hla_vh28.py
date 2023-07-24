#rta_evm_hla_vh28.py:
#-------------------------
#
# This python script is intended to be used with "RTA Analysis" MO in MTS.
# It provides statistics like runtime, histograms for EVM HIL for HLA.
# Additionally, logs and reports can be generated.

import rtanetruntimeevm
import rtashortcuts
import rtacycles
import rtavislogger
import rtahistogram
import rtaoshelper
from rtareporting import templated_rep
from rtareporting.templated_rep import UdexInfo
import time               # for getting time of RTA report generation
import inspect,os         # for calculating path to the folder with budget csv files

CYCLELENGTH_MONO = 60280
# **********************************************************************
# CONFIGURATION
# **********************************************************************
USAGE_MESSAGE = """
 
There are several user functions available in the command line of RTA Analysis MO:
 
  help():                Prints this usage message.
  disableProfileLog():   Disables profile logging.
  enableProfileLog():    Enables profile logging. Default case.
  disableDetailedMode(): Disables reporting of detailed time measurements.
  enableDetailedMode():  Enables reporting of detailed time measurements. Default case.
  writeLog():            Writes the screen content to the log path.
  writeHist():           Writes the excel histograms (.csv) to the log path.
  writeReport():         Write pdf report to log path.
 
Please note the commands have to be entered including the parenthesis, e.g. "writeOutputs()"
"""

# Cores (<ID>, <Name>)
CORE_MAIN     = (12, "C66xx")
CORE_EVE      = (16, "EVE")

# Project
PROJECT = "MFC431"

# Algo/component 
COMP_NAME = "HLA"

#Udex device data 
UDEX_DEVICE = "SIM VFB"
UDEX_URLS= [ ("HLA.HilHlaProPortAlgoCompState.eCompState"),
             ("HLA.HilHlaProPortAlgoCompState.sSigHeader.uiMeasurementCounter"),
             ("HLA.SilHlaReqPortLsdLightObjectList.numObjects"),
             ("HLA.SilHlaReqPortEMObjectList.HeaderObjList.iNumOfUsedObjects")
            ]

# Correpsonding reports/logging
SCRIPT_DIR = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))           # get path to this file
BUDGETS_FILE = os.path.join(SCRIPT_DIR, './%s_budgets.csv' % (PROJECT.lower()))
LOG_PATH  = SCRIPT_DIR + "\\..\\..\\..\\..\\..\\04_Test_Data\\02_Output\\algo\\inttests\\%s\\%s\\" % (COMP_NAME.lower(), PROJECT.lower())
REPORT_DESCRIPTION = "Budget violations shown in red below on histograms. Important: all histograms are in logarithmic scale"

# modify this list for runtime measurements
# <core>, <component>, <function>, <range>, <histMin>, <histMax>, <histStep, <report section>

runtimeTargetsMainCore = [
  (CORE_MAIN, COMP_NAME, "TOTAL",          None, 0, 800, 50, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "RESET",          None, 0, 200, 20, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "EXEC",           None, 0, 800, 50, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "RUN",            None, 0, 800, 50, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "INPUT_CHECKS",   None, 0, 100, 10, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "SET_DEFAULTS",   None, 0,  50,  5, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "HLAF_EXEC",      None, 0, 600, 50, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "OUTPUT_CHECKS",  None, 0, 100, 10, COMP_NAME),
  (CORE_MAIN, COMP_NAME, "DEM_EVENTS",     None, 0,  50,  5, COMP_NAME)
]

runtimeTargetsFunction = [
  (CORE_MAIN, COMP_NAME, "HLAF_INIT",     None, 0, 100,  5, "Function"),
  (CORE_MAIN, COMP_NAME, "HLAF_DECISION", None, 0, 100,  5, "Function"),
  (CORE_MAIN, COMP_NAME, "HLAF_MATRIX",   None, 0, 300, 10, "Function")
]

# modify this list for bandwidth measurements (max. 8 counters)
# <visu-label>, <core-id>, <source-id>, <access-mode>, <histogram-params: (min, max, step-width)>
MEAS_CONFIG = (
  (CORE_MAIN[1] + " (RD+WR) [kByte]", CORE_MAIN[0], 4, "r/w",  (0, 1500,  50)), # DSP
  (CORE_MAIN[1] + " (RD)    [kByte]", CORE_MAIN[0], 4, "read", (0, 1500,  50)),
  (CORE_MAIN[1] + " (WR)    [kByte]", CORE_MAIN[0], 4, "write",(0,  500,  10)),
  (CORE_EVE[1]  + " (RD+WR) [kByte]", CORE_MAIN[0], 6, "r/w",  (0, 1000,  10)), # EVE
  (CORE_EVE[1]  + " (RD)    [kByte]", CORE_MAIN[0], 6, "read", (0,  500,   5)),
  (CORE_EVE[1]  + " (WR)    [kByte]", CORE_MAIN[0], 6, "write",(0,  500,   5)),
)

# Initialize variables that should contain class instances
bandWidthMeas = []
runTimes = []


class BandWidthMeas:
  # summation of single bandwidth period measures
  def listener(self, index):
    # index 0 is transfered by python as None. Restore it.
    if not index:
      index = 0
    self.temp_buffer[index] += self.CntMeas[index].counter.getValue()

  # take over summation of single bandwidth period measures
  def start_listener(self, dummy):
    for index in range(len(self.MeasPtr)):
      if (self.temp_buffer[index] >= 0):
        self.MeasPtr[index].setValue(self.temp_buffer[index])
      self.temp_buffer[index] = -1
            
  # Visualizes current bandwidth figures
  def visualize(self):
      self.Header = VisBoxTitle("DDR BANDWIDTH")  
      for index in range(len(self.CntMeas)):    
        self.VisuLine += [VisBoxStatistics(self.measConfig[index][0], Statistics(self.MeasPtr[index]))]
    
  # Visualizes bandwidth figures across all recordings
  def visualizeTotal(self):
      self.HeaderTotal = VisBoxTitle("DDR BANDWIDTH (total)")
      for index in range(len(self.CntMeas)):
        StatsObj = Statistics(self.MeasPtr[index])
        StatsObj.setTotal(True)
        self.VisuLineTotal += [VisBoxStatistics(self.measConfig[index][0], StatsObj)]
            
  # initialize bandwith measurement
  def __init__(self, config):
    # Store meas config for later usage
    self.measConfig = config
    # temporary buffer for summation
    self.temp_buffer = [-1] * len(self.measConfig)

    # Init visualization
    self.Header = []
    self.HeaderTotal = []
    self.VisuLine = []
    self.VisuLineTotal = []

    # Initialize bandwidh measurement
    self.CntMeas  = []
    self.MeasPtr  = []
    for conf in self.measConfig:
      self.CntMeas  += [CounterMeasures(conf[1], conf[2], conf[3])]
      self.MeasPtr  += [MeasurePointer()]

    # Create histograms for bandwidth measurement
    self.HistList = []
    for index in range(len(self.measConfig)):
      min, max, width = self.measConfig[index][4]
      self.HistList += [Histogram1D(self.MeasPtr[index], min, max, width)]

    # start maker => used to reset and take over bandwidth summation
    self.myMarker = MarkerMeasures(CORE_MAIN[0], "SW_EVT_MARKER", "IMAGE_ODDR")
    self.myMarker.triggerTime.addEventListener(self.start_listener, None)

    # add event listener for adding single bandwidth measurements
    for index in range(len(self.CntMeas)):
      self.CntMeas[index].time.addEventListener(self.listener, index)


# **********************************************************************
# MAIN PART OF SCRIPT
# **********************************************************************
def main(modeDetailed):
  global bandWidthMeas
  global runTimes
  
  # **********************************************************************
  # GENERIC STUFF
  # **********************************************************************
  # Create log file paths if not yet existing
  rtaoshelper.makeDir(LOG_PATH)
  
  # Add callback function for printing reports at the end of runtime test
  rta.eofRecording.trigger.addEventListener(checkBatchStatus, None)
  
  # Get algo version information from EVM HIL comp state
  UdexInfo.registerUdexEvmHil("SIM VFB", "HLA.HilHlaProPortAlgoCompState") 
  
  # **********************************************************************
  # CONFIGURATION
  # **********************************************************************
  runTimes = rtanetruntimeevm.RunTimes(LOG_PATH , COMP_NAME , REPORT_DESCRIPTION , UDEX_DEVICE , UDEX_URLS)
  # Add all runtime targets to corresponding list.
  runTimes.addToMainList("EVM " + COMP_NAME,                       runtimeTargetsMainCore)
  runTimes.addToDetailedList("EVM " + COMP_NAME + " FUNCTION",     runtimeTargetsFunction)

  # Configure lists containing relevant runtime events and update loggers, report data, etc.
  runTimes.configureLists()

  # Configure bandwidth measurement
  bandWidthMeas = BandWidthMeas(MEAS_CONFIG)

  # **********************************************************************
  # VISUALIZATION
  # **********************************************************************
  # Visualize runtimes of this recording
  runTimes.showRuntimes()

  # Visualize bandwidth of this recording
  bandWidthMeas.visualize()

  # Visualize summaries
  runTimes.showTotalRuntimes()

  bandWidthMeas.visualizeTotal()

# **********************************************************************
# INTERACTIVE USER-CONSOLE-FUNCTIONS
# **********************************************************************
def enableProfileLog():
  runTimes.loggerProfile.switchOn()
  print "Profile logging switched on!"

def disableProfileLog():
  runTimes.loggerProfile.switchOff()
  print "Profile logging switched off!"
  
def enableDetailedMode():
  #reconfigure lists, reports, etc. including detailed time measurements
  runTimes.enableDetailedMode()
  print "Detailed runtimes will be considered!"
  
def disableDetailedMode():
  #reconfigure lists, reports, etc. without detailed time measurements
  runTimes.disableDetailedMode()
  print "Detailed runtimes will be ignored!"
  
def writeLog():
  runTimes.loggerVis.EndRecordingEvent()
  runTimes.loggerProfile.EndRecordingEvent()
  
def writeHist():
  for hist in runTimes.histograms:
    rtahistogram.writeHistogram(hist[0], "Histogram Runtime %s_%s" % (hist[1], hist[2]), LOG_PATH + "HIST_RT_%s_%s.csv" % (hist[1], hist[2]))
  for x in range(len(bandWidthMeas.measConfig)):
    rtahistogram.writeHistogram(bandWidthMeas.HistList[x], bandWidthMeas.measConfig[x][0], LOG_PATH + "HIST_BW_%i_%i.csv" % (bandWidthMeas.measConfig[x][2], x))

def writeReport():
  meta = { "algo_ver"        : UdexInfo.algo_ver,
           "application_ver" : UdexInfo.application_ver,
           "algo_ver_info"   : UdexInfo.algo_ver_info
          }
  templated_rep.writeReport(COMP_NAME + " runtime report on EVM HIL", LOG_PATH, "report_template_evm_hil.html", COMP_NAME + "_runtime_report_EVM_HIL", COMP_NAME, BUDGETS_FILE, meta, CYCLELENGTH_MONO, *tuple(runTimes.reports))

def checkBatchStatus(x):
  if rta.eofRecording.batchstatus == True:
    writeReport()
    writeLog()
    writeHist()
    print "Histogram , log files and reports are generated "

def help():
  print USAGE_MESSAGE


# **********************************************************************
# MAIN FUNCTION CALL
# **********************************************************************
# Put this at the end of the file in order to force the interpreter 
# to go throught the whole file. Then he knows all functions.
if __name__ == "__main__":
  main(True)