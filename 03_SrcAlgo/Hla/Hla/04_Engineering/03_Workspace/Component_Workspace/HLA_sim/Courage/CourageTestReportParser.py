# CourageTestReportParser.py:
#-------------------------
#
# This python script is intended to parse coverage report of every test suite.
# In case of DC or DC-bytest coverage lower than 100% it will print a corresponding message to stdout
# so that other tools like Jenkins text finder can search for it. We need both reports since ...
# ... DC report contains disabled parts (COU_COV_DISBALE flag in source code)
# ... DC-bytest contains all statements. In DC, there is a bug. Some statements are marked as not covered altough they are.
# It is designed to be located in DPU\05_Testing\05_Test_Environment\Dynamic_Tests\<component>\Courage

#-------------------------
# import
#-------------------------
import os, re, stat, sys

#-------------------------
# configuration
#-------------------------
SEARCH_PATTERN_COVERAGE_DECISION = """<tr><td class="info">TER structural</td><td class="info">:</td><td><span class="aboveb">(\d*) %</span>"""
SEARCH_PATTERN_COVERAGE_STATEMENT = """<tr><td class="info">TER statement</td><td class="info">:</td><td><span class="aboveb">(\d*) %</span>"""

PATH_TO_COURAGE_OUTPUT="""..\\..\\..\\..\\..\\04_Engineering\\04_Build\\ModuleTests\\"""


#-------------------------
# functions
#-------------------------
def main():
    
    # Command line arguments
    if len(sys.argv) < 3:
      # Find out component name
      logPath   = PATH_TO_COURAGE_OUTPUT
      target    = "dsp_0"
      component = os.path.basename(os.path.abspath(".."))
      project   = "mfc431"
    else:
      logPath   = sys.argv[1]
      target    = sys.argv[2]
      component = sys.argv[3]
      project   = sys.argv[4]

    # Compose path to courage results
    courageResults = os.path.abspath(logPath + "\\" + project + "\\" + target + "\\" + component + "\\Cou\\")

    # Loop over all Courage tests results
    for unitTest in os.listdir(courageResults):
        # Check courage test report for DC coverage
        statementCoverageDC, decisionCoverageDC = analyseCoverageReport(courageResults, unitTest, "DC")

        # Check courage test report for DC-bytest coverage
        statementCoverageDCbytest, decisionCoverageDCbytest = analyseCoverageReport(courageResults, unitTest, "DC-bytest")

        # Print message if coverage is below target
        if max(statementCoverageDC, statementCoverageDCbytest) < 100 or max(decisionCoverageDC, decisionCoverageDCbytest) < 100:
            print("[FAILED]: Coverage for unit test " + unitTest + " is below target.")
        else:
            print("[PASSED]: Coverage for unit test " + unitTest + " is on target.")
        print

def analyseCoverageReport(courageResults, unitTest, coverageKind):
    coverageFilePath = os.path.abspath(courageResults + "\\" + unitTest + "\\TEST\\COV\\" + coverageKind + "\\index.html")

    if os.path.isfile(coverageFilePath):
        # Check courage test report
        print("Check coverage report: " + coverageFilePath)

        # Open result file.
        coverageFile = open(coverageFilePath, 'r+')

        # Read whole content
        coverageFileContent = coverageFile.readlines()

        # Close coverage file as no longer needed
        coverageFile.close()

        statementCoverage = ""
        decisionCoverage = ""
        # Go through every line until required patterns were found
        for line in coverageFileContent:
            # Search for a Statement coverage
            patternMatch = re.search(SEARCH_PATTERN_COVERAGE_STATEMENT, line)
            if patternMatch:
                statementCoverage = patternMatch.group(1)
                print("Statement coverage for " + unitTest + ":    " + statementCoverage + "%.")

            # Search for a Decision coverage
            patternMatch = re.search(SEARCH_PATTERN_COVERAGE_DECISION, line)
            if patternMatch:
                decisionCoverage = patternMatch.group(1)
                print(coverageKind + " coverage for " + unitTest + ":  " + decisionCoverage + "%.")
        return int(statementCoverage), int(decisionCoverage)
    else:
        print(os.path.basename(__file__) + ': [FAILED]: Coverage file ' + coverageFilePath + ' could not be opened. Please check path.')
        return 0, 0
    
# **********************************************************************
# MAIN FUNCTION CALL
# ********************************************************************** 
# Put this at the end of the file in order to force the interpreter 
# to go throught the whole file. Then he knows all functions.   
if __name__ == "__main__":
    main()