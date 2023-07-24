
"""@package qac_project_merger
This is the SOC QAC project file creator Python script, used to concatenate each core's
individual QAC project file into one big one that can be used to scan all cores in a
product, and to view the results of such scanning in QAC.

@author Colin Ward, Continental ADC
"""

import getopt
import os
import sys

## The header to be written to the start of the QAC project file, containing basic scanning options
header = '''VersionTag45
	ProjectConfigFile=ReportCfg\qac8.1.1_report_cfg.pcf
	ProjectDataflowFile=C:\Tools\QAC\8.1.1-R\personalities\preset_4.p_d'''

## The footer to be written at the end of each core's section in the QAC project file.
# This indicates to QAC the end of that core's section.
endCore = 'EndSubProjectMarker'

## The header to be written at the start of each core's section in the QAC project file.
# This indicates to QAC the beginning of a new core's section.  The special variable $core will be
# replaced with the name of the core when it is written to the QAC project file, and the special
# variable $product will be replaced with the name of the product.  The SourcePath, OutputPath,
# SubsPers, AnalPers and CompPers keywords are only required for QAW and do not make any difference
# to the functioning of QAC/QACPP
newCore = '''StartProjectMarker
	FolderName=$core
	SourcePath=.
	OutputPath=.
	SubsPers=MessagePers\ADAS_CPP.p_s
	AnalPers=_cnf\$product_$core_AnalyserPers_CPP.p_a
	CompPers=CompilerPers\TMS470_TI_ARM\CodeComposer_TMS470_ARMGCC_CPP.p_c
	EndContainedFilesMarker
	StartSubProjectMarker'''

## The list of cores to be written to the QAC project file
cores = []
## The QAC language (C or CPP) for which we are creating the QAC project files
language = ''
## The name of the product for which to create the QAC project file
product = ''

## Appends the contents of a core's QAC project file to the output project file.
#
# This function will determine the name of the core's QAC project file, based on the name of the core,
# and will append that QAC project file to the product's QAC project file, ensuring that the contents
# of the core's file is correctly begun and ended with the appropriate QAC headers to indicate the start
# and end of the core in the QAC project file.
#
# @param	outFile		A handle to the QAC project file to which to append the core's project file
# @param	core		The name of the core to be written to the QAC project file
def writeCore(outFile, core):
	# Write a header to indicate the beginning of a new core
	writeSeparator(outFile, newCore, core)

	# Determine the name of the core's QAC project file and open it
	coreProject = '_' + product + '_' + core + '.prj'
	inFile = open(coreProject)

	# Append the contents of the core's project file to the product's project file
	for line in inFile:
		outFile.write(line)

	# Write a footer to indicate the end of the core
	writeSeparator(outFile, endCore)

	# And close the core's QAC project file
	inFile.close()

## Writes a header or footer to the QAC project file.
#
# This is a helper function that is used to write either a header or a footer to the output QAC project
# file.  The header or footer is passed in as a string and before being written, any instances of the
# special variables $core and $product found in the string will be replaced by the contents of the "core"
# and "product" variables that were passed in, if any, and the names of any files that are referenced
# in the separator are adjusted depending on whether we are creating the QAC project files for C or CPP.
#
# @param	outFile		A handle to the QAC project file to which to write the separator
# @param	separator	The multiline string to be written to the QAC project file
# @param	core		The name of the core being written
def writeSeparator(outFile, separator, core = ''):
	separator = separator.replace('$core', core)
	separator = separator.replace('$product', product)

	# If a language was specified then adjust the name of any language specific files in the separator
	if language != '':
		separator = separator.replace('CPP', language)

	# Split the multiline string into a list of tokens and write each one individually, to ensure that
	# whitespace and EOL terminators are correctly handled
	tokens = separator.split()

	for token in tokens:
		outFile.write(token + '\n')

## Displays a short help page for the program.
#
# This function should be called when the user requests help, and will display all of the arguments that can be
# passed to the program.
def usage():
	print 'QAC project file creator merger 1.01'
	print ''
	print 'Usage: qac_project_merger.py [-c] [-h] [-p]'
	print ''
	print 'Where: -c|--cores    = A comma separated list of core configurations to be'
	print '                       written to the QAC project file.  ie. -c arm-a_0,arm-m_0'
	print '       -h|--help     = Display this help'
	print '       -l|--language = The optional language for which to create the QAC'
	print '                       project file (C or CPP)'
	print '       -p|--product  = The name of the product for which to create the QAC'
	print '                       project file'

## Main entry point for the program.
#
# The main entry point for the program.  This parses the arguments passed in and places them in the relevant global variables.  It
# then creates a QAC project file with the name of the project passed in and iterates through the list of cores passed in, appending
# each core's QAC project file to the overall QAC project file.  This results in a single project file that can be used to scan all
# cores.
#
# @param	argv	A list of the arguments passed in on the command line
def main(argv):
	global cores
	global language
	global product

	try:
		opts, args = getopt.getopt(argv[1:], 'c:hl:p:', ['cores=', 'help', 'language=', 'product='])
	except getopt.GetoptError:
		print 'Error: Unable to parse command line'
		sys.exit(1)

	for opt, arg in opts:
		if opt in ['-h', '--help']:
			usage()
			sys.exit(0)
		elif opt in ['-c', '--cores']:
			cores = arg.split(',')
		elif opt in ['-l', '--language']:
			language = arg
		elif opt in ['-p', '--product']:
			product = arg

	# Ensure that all command line arguments have been specified and if not, display an error
	if cores == []:
		print 'Error: List of cores to be added to QAC project not specified'

	if product == '':
		print 'Error: Name of product for which to create QAC project not specified'

	# If any command line arguments were missing then exit
	if cores == [] or product == '':
		sys.exit(1)

	# Create an empty QAC project file for the specified project
	outFile = open('_' + product + '.prj', 'w')

	# Write a header to indicate to QAC that this is a project file and to give it (QAC) basic scanning information
	writeSeparator(outFile, header)

	# For each core that we wish to add to the QAC project file, write a header to indicate to QAC that a new core is
	# being added, and then append the core's QAC project file that was generated by SCons
	for core in cores:
		writeCore(outFile, core.strip())

	# And close the output file
	outFile.close()

if __name__ == '__main__':
	main(sys.argv)
