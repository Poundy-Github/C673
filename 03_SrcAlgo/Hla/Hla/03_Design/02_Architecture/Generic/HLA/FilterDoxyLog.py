# FilterDoxyLog.py:
#-------------------------
#
# This python script is intended to parse doxygen log file.
# It shall filter not relevant meessage and create a new filtered log file 
# with all important errors and warnings from doxygen.

#-------------------------
# import
#-------------------------
import os, re, stat, getopt, sys

#-------------------------
# configuration
#-------------------------
DoxyLogFile         = os.environ["DOXY_ERROR_LOG"]
DoxyLogFileFiltered = 'doxyErrorsFiltered.log'
Warnings2Filter     = ['warning: argument \'([Vv]oid|None)\' of command @param is not found in the argument list of', \
                       'warning: unable to resolve reference to \`(CFG_|ANALYSIS_LRF_TANH_LUT_SLOPE_OFFSET)', \
                       'LSD_\w*_ERROR',   # temporary one for missing DEM events in MFC5xx \
                       'DPUSERVICE', \
                       '_copy.cpp\' not found', \
                       ' command because PLANTUML_JAR_PATH is not set', \
                       ' not generated, too many nodes. Consider increasing DOT_GRAPH_MAX_NODES.', \
                       ]
                       
#-------------------------
# functions
#-------------------------
def main(argv):
  # Arguments handling
  print2stdout = False
  try:
    opts, args = getopt.getopt(argv,"hp")
  except getopt.GetoptError:
    print(os.path.basename(__file__) + ' -p')
    sys.exit(2)
  for opt, arg in opts:
    if opt == '-h':
      print(os.path.basename(__file__) + ' -p')
      sys.exit()
    elif opt == '-p':
      print2stdout = True
  
  if (os.path.isfile(DoxyLogFile)):
    # Open Doxy log
    logFile = open(DoxyLogFile, 'r')
  
    # Read whole content
    logFileContent = logFile.readlines()
    
    # Close log file as no longer needed
    logFile.close()
    
    # Go through every line of a copy of log file and remove filtered lines
    for line in logFileContent[:]:
      # Filter this line if applicable
      for filter in Warnings2Filter[:]:
        if re.search(filter, line):
          # Line is to be removed
          logFileContent.remove(line)
          break
          
    if print2stdout:
      # print to stdout
      for line in logFileContent:
        print(line),
    else:  
      # print to filtered log file
      if (os.path.isfile(DoxyLogFileFiltered)):
        # Remove write protection
        os.chmod(DoxyLogFileFiltered, stat.S_IWRITE)
  
      # Open filter doxy log file
      logFileFiltered = open(DoxyLogFileFiltered, 'w')
      
      # Write back filtered warnings
      logFileFiltered.writelines(logFileContent)
      
      # Close log file as no longer needed
      logFileFiltered.close()
  else:
    print(os.path.basename(__file__) + ': Doxygen log file ' + DoxyLogFile + ' could not be opened! Please check path.')
    exit
    
  
# **********************************************************************
# MAIN FUNCTION CALL
# ********************************************************************** 
# Put this at the end of the file in order to force the interpreter 
# to go throught the whole file. Then he knows all functions.   
if __name__ == "__main__":
    main(sys.argv[1:])