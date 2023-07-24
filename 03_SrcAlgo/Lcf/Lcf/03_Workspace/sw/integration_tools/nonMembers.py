#!/usr/bin/python

import os
import subprocess
import sys
import getopt
import stat



## List of directories to be excluded from the sandbox cleanup performed by cleanupSandbox()
exclusionDirList = []
## List of files to be excluded from the sandbox cleanup performed by cleanupSandbox()
exclusionFileList = []
## True to perform a dry run, or False to really perform the resync or revision update on the files
dryRun = False
hotRun = False



# Converts a drive letter to lower case.
#
# Checks if the path passed in contains a drive letter and if so, converts it to lower case.  This is
# required because it is pretty much random whether an upper case or lower case drive letter is used,
# depending on the program that generates the qualified path.  We want to compare fully qualified paths
# for equality, and this will fail the test if different drive letter cases are used.  The rest of the
# path itself seems to remain accurate.
#
# @param	path		The path to have its drive letter (if any) converted
# @return	The path passed in, with the initial drive letter (if any) converted to lower case
def lowerCaseDrive(path):
	if len(path) >= 2 and path[1] == ':':
		path = path[0].lower() + path[1:]

	return path



## Reads the configuration file (if any) and parses it for configuration keywords.
#
# This function will try to open the configuration file specified and will parse it for known configuration
#
# @param	configFileName	Name of the configuration file to be parsed
# @retval	True if the configuration file specified was processed, else False if it was not found
def readConfig(configFileName):
	global exclusionDirList
	global exclusionFileList

	# Assume that the configuration file could be opened and processed successfully
	errorFound = False
	retVal = True
	fileMessageDisplayed = False
	folderMessageDisplayed = False
	
	# Attempt to open the optional configuration file.  If the file doesn't exist then open() will throw and exception;
	# just ignore it and continue
	try:
		configFile = open(configFileName, 'r')
		lineNumber = 1

		print ('Parsing configuration file ' + configFileName)

		# Iterate through all lines in the configuration file and see what configuration settings are specified
		for line in configFile:
			line = line.strip()

			# Skip any blank lines or commented out lines
			if len(line) > 1 and line[0] != '#':
				tokens = line.split()

				# If there is at least one token on the line then see what it is
				if len(tokens) >= 1:
					if tokens[0] == 'KeepDirs':
						if len(tokens) >= 2:
							directories = tokens[1].split(',')

							# Before appending exclusion paths to the directory exclusion list, normalise them to DOS format (with \ separators) as
							# this is what is returned by the MKS "viewnonmembers" command
							for directory in directories:
								# Display a title message if no files have been as yet deleted
								if not folderMessageDisplayed and dryRun:
									print ('\nFolders NOT to be deleted:')
									folderMessageDisplayed = True
								printStatus (directory)
								exclusionDirList.append(os.path.normpath(directory))
						else:
							errorFound = True

							print 'Error: ' + configFileName + ' line ' + str(lineNumber) + ': "KeepDirs" keyword must specify a list of comma separated directories'
					elif tokens[0] == 'KeepFiles':
						if len(tokens) >= 2:
							files = tokens[1].split(',')

							for file in files:
								# Display a title message if no files have been as yet deleted
								if not fileMessageDisplayed and dryRun:
									print ('\nFiles NOT to be deleted:')
									fileMessageDisplayed = True
								printStatus (file)
								exclusionFileList.append(file)
						else:
							errorFound = True

							print 'Error: ' + configFileName + ' line ' + str(lineNumber) + ': "KeepFiles" keyword must specify a list of comma separated files'
					# An unknown keyword has been found so display a warning but continue
					else:
						print 'Warning: ' + configFileName + ' line ' + str(lineNumber) + ': Unknown keyword found'
						print line

			lineNumber += 1

		configFile.close()
	except IOError:
		retVal = False

	# If an error occurred during processing then treat this as fatal and exit
	if errorFound:
		sys.exit(1)

	return retVal
	

	
## Displays a status string on the screen.
#
# This function is a simple wrapper around the print function, which will only print the string passed in
# if either the dryRun or verbose flags are set.
#
# @param	status		The string to be displayed
def printStatus(status):
	if dryRun:
		print status



## Displays a short help page for the program.
#
# This function should be called when the user requests help, and will display all of the arguments that can be
# passed to the program.
def usage():
	print 'Find non-sandbox members'
	print ''
	print 'Usage: nonMembers.py [-h] [-d] [-t]'
	print ''
	print 'Where -d|--dryrun      = Perform a dry run. Output the actions that would be'
	print '                         performed without performing them'
	print ''
	print 'Where -t|--hotrun      = Perform a hot run. Remove all non-members.'


	

## Main entry pint of the script
#	
def main(argv):
	# Script to check if there are non sandbox members
	print '\nCheck if there are non-sandbox members ...'
	
	global dryRun
	global hotRun

	dryRun = False
	hotRun = False

	messageDisplayed = False
	currentDir = os.getcwd() + '\\'
	
	try:
		opts, args = getopt.getopt(argv[1:], 'dht', [ 'dryrun', 'help', 'hotrun' ])
	except getopt.GetoptError:
		print 'Error: Unable to parse command line'
		sys.exit(1)

	for opt, arg in opts:
		if opt in ('-h', '--help'):
			usage()
			sys.exit(0)
		elif opt in ('-d', '--dryrun'):
			dryRun = True
		elif opt in ('-t', '--hotrun'):
			hotRun = True
		else:
			print 'Unknown option ' + arg

	if hotRun:
		answer = raw_input('\nDo you really want to delete all non-member files from sandbox? [y/n] ')
		if not answer or answer[0].lower() != 'y':
			exit(0)
		else:
			print ('\nNote: Non-member files are now DELETED from sandbox!')
	else:
		print ('\nNote: Non-member files are NOT deleted from sandbox - just checking! Use hotrun option to delete the files!')

	# Sometimes os.getcwd() returns a lower case drive letter and sometimes an upper case drive letter.  Check to see
	# if there is a drive letter present and if so, make it lower case.  Otherwise we will get a mismatch when checking
	# it against the fully qualified paths returned by the MKS "viewnonmembers" command
	currentDir = lowerCaseDrive(currentDir)

	# Use MKS to scan the current sandbox for a list of non members
	command = 'si viewnonmembers --yes'
	viewnonmembers = open('viewnonmembers.txt', 'w+')

	# Execute SI command on higher project level and come back later
	pathDirs = currentDir.split(os.sep)
	try:
		dpu_depth = pathDirs.index('DPU')
	except ValueError:
		dpu_depth = pathDirs.index('04_Engineering')
		
	os.chdir(os.sep.join(pathDirs[:dpu_depth]))	
	print ('\nStarting from  ' + os.getcwd())
	
	result = subprocess.call(command, stdout = viewnonmembers)
	os.chdir(currentDir)

	# If the call to si failed, result will be non zero.  In this case the si command will have printed useful information
	# to the user as to why it failed, so simply display a generic error message and exit
	if result != 0:
		print '\nError: Unable to obtain list of non members in the sandbox'

		sys.exit(1)

	# Iterate through the list of qualified file names that was returned by MKS and delete any files left over from a
	# previous run, leaving certain files that we are interested in
	viewnonmembers.seek(0)

	# Try to read the configuration file
	configFileName = ('nonMembers.cfg')
	if not readConfig(configFileName):
		readConfig('../integration_tools/' + configFileName)
	
	for fileName in viewnonmembers:
		fileName = fileName.strip()

		# Obtain the name of the directory in which the non member has been found and make it relative to the sandbox
		directory = os.path.dirname(fileName)
		directories = directory.split('\\')

		# Ensure that the file being checked uses a lower case drive letter
		fileName = lowerCaseDrive(fileName)

		# And get the name of the non member file
		file = os.path.basename(fileName)
		
		# There are certain files and directories that we do not want to delete that are used by the build system.
		# Check for these and set a flag if the current file represents one of those that we wish to keep
		deleteFile = True

		# Display a title message if no files have been as yet deleted
		if not messageDisplayed:
			print ('\nDeleting dropped or temporary files(s)')
			messageDisplayed = True
		
		# If a build specification file was specified then check to see if this is the current file.  We check against the
		# qualified file name as we want to delete only that file, not a file of the same name in a different directory
		# Also exclude the viewnonmembers.txt file, as it is currently in use by this routine!
		if file == 'viewnonmembers.txt':
			deleteFile = False
			printStatus ('Do not delete:  ' + fileName)
		# Check to see if the file is in the explicit file exclusion list
		elif exclusionFileList.count(file) > 0:
			deleteFile = False
			printStatus ('Do not delete:  ' + fileName)
		# And finally check to see if the path is in the explicit directory exclusion list
		else:
			# Iterate through the explicit directory exclusion list.  Subpaths in the list are only considered to match the current
			# path if they are at the very beginning or very end of the current path.  This is to prevent filtering out directories
			# that we want to clean, but which happen to contain the specified subpath somewhere within their full path.  For
			# example, an exclusion filter of 01_Source_Code will not match 04_Engineering/01_Source_Code/SW, but an exclusion
			# filter of 04_Engineering or SW will match this path
			for exclusionDir in exclusionDirList:
				offset = directory.find(exclusionDir)

				if offset >= 0:
					deleteFile = False
					# printStatus ('Do not delete:  ' + fileName)
					break
	
		# Delete the non member file, but only if it is not on the exception list
		if deleteFile:
			# Delete the old file
			print ('Delete file:    ' + fileName)
			if hotRun:
				os.chmod(fileName, stat.S_IWRITE)
				os.remove(fileName)

	viewnonmembers.close()
	os.remove('viewnonmembers.txt')
	
	if hotRun:
		print ('\nDeleted non-member files from sandbox!')
	else:
		print ('\nNote: Non-member files are NOT deleted from sandbox! Use hotrun option to delete the files!')



if __name__ == '__main__':
	main(sys.argv)