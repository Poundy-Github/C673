
"""@package activate_project
This script can be used to perform TD4 style project activation on projects that do not
actually use TD4, but which have a need for the tools stored on l: drive to be installed
automatically.  When executed, it will check to see if the core tools required for building
(i.e. Python) are installed and if not, will install them.  It will then search for a
BuildDescription.xml file in the usual place and will install whatever tools are listed in
it.  It uses l: drive but will fall back to a hard coded UNC path in the absence of a
drive mapping, enabling it to also be used on Jenkins where l: drive is not always available.

@author Colin Ward, Continental ADC
"""

import os
import re
import shutil
import stat
import subprocess
import sys
import xml.etree.ElementTree as ET

## The default drive from which to install the tools
installDrive = r'\\cw01.contiwan.com\root\loc\ulm2\didt6402\SW-DevTools' + '\\'
## List of source files used by the cloneDirectory() function
sourceFiles = []
## List of destination files used by the cloneDirectory() function
destFiles = []
## The list of tools to be installed, read from the BuildDescription.xml file
tools = []
## True to print information about what is being installed, else False to do it quietly
verbose = True

## Recursively mirrors one directory into another.
#
# This function will recursively mirror one directory into another, ensuring that by the end, the source and
# destination directories are an exact copy of one another, right down to the timestamps of the files in the
# directories.  If a directory exists in the source but not the destination, that directory will be created in
# the destination and its contents copied.  If a file exists in the destination but not the source, that file
# will be deleted.
#
# The only way in which the two directories will not match is that all instances of the project.pj file are
# ignored and not copied.  These are not required for building and if they were copied then this would break the
# destination directory if it was in an MKS sandbox.
#
# @param	sourceDir	The source directory from which to mirror the files
# @param	destDir		The destination directory into which to mirror the files
# @param	wildcard	A wildcard to be used for filtering file files to copy
def cloneDirectory(sourceDir, destDir, wildcard):
	global sourceFiles
	global destFiles

	dryRun = False

	if not dryRun:
		# Reset the source and destination file arrays in case there are any files left in them from a previous call
		sourceFiles = []
		destFiles = []

		# Save the current directory and change into the source directory in order to perform a recursive scan
		oldDir = os.getcwd()
		os.chdir(sourceDir)

		# Scan the source directory for files
		os.path.walk('.', examineDirectory, True)

		os.chdir(oldDir)

		# If the destination directory exists then change to it and and scan it for files
		if os.path.exists(destDir):
			os.chdir(destDir)
			os.path.walk('.', examineDirectory, False)
			os.chdir(oldDir)

		# Ensure that the source and destination directory names have a trailing slash
		if sourceDir[-1] != '/':
			sourceDir += '/'

		if destDir[-1] != '/':
			destDir += '/'

		# Prepare the regular expression for use in the copy loop
		pattern = re.compile(wildcard)

		# Iterate through all files in the source list and copy them into the destination.  If the target directory
		# does not exist, create it
		while len(sourceFiles) > 0:
			# Get the name and qualify it for the source and destination directories
			name = sourceFiles.pop(0)
			sourceFile = sourceDir + name
			destFile = destDir + name

			# Check to see if the path to the destination directory exists and if not, create it.  shutil.copyfile() can
			# only copy into an existing directory and will throw an exception if the destination directory does not exist
			destPath = os.path.dirname(destFile)

			# Copy the file to the destination directory if it matches the wildcard passed in
			if pattern.match(name):
				if not os.path.exists(destPath):
					os.makedirs(destPath)

				# Ensure that the destination file is writeable, if it exists
				if os.path.exists(destFile):
					os.chmod(destFile, stat.S_IWRITE)

				# Copy the source file into the destination
				if os.path.basename(sourceFile) != '__dummyEmptyDir.txt':
					shutil.copyfile(sourceFile, destFile)

					# And set the time of the destination file to the time of the source file.  This is not absolutely needed but
					# is done for the sake of neatness.  It also makes it easier to confirm that the files have been copied correctly
					statInfo = os.stat(sourceFile)
					os.utime(destFile, (statInfo.st_atime, statInfo.st_mtime))

			# And remove the file from the destination array, if it exists
			if destFiles.count(name) > 0:
				destFiles.remove(name)

		# Iterate through any files that are left in the destination array and delete them from disk.  This ensures that
		# files that exist only in the destination directory are deleted
		for name in destFiles:
			destFile = destDir + name
			os.chmod(destFile, stat.S_IWRITE)
			os.remove(destFile)

## Examines a directory to decide which files to add to the source or destination file list.
#
# This function is called by os.path.walk() for each directory that is found.  It will scan through the list
# of files in the directory and qualify each one with the path to the directory and will then add the qualified
# file name to a list of files.  This will be done for all files except project.pj, which is an MKS file that
# we wish to ignore.
#
# @param	isSource	True if the directory being examined is a source directory, else False for destination
# @param	dirName		The name of the directory being examined
# @param	names		A list of files found in the directory being examined
def examineDirectory(isSource, dirName, names):
	global sourceFiles
	global destFiles

	# Iterate through the list of file system objects in the directory and add any files found to the list of
	# files to be processed
	for name in names:
		# We want to work with qualified file names
		qualifiedName = dirName + '/' + name

		# If the file system object being examined is not the special "project.pj" MKS file and it is also
		# not a directory then add it to the list of files to be copied
		mode = os.stat(qualifiedName).st_mode

		if name != 'project.pj' and not stat.S_ISDIR(mode):
			if isSource:
				sourceFiles.append(qualifiedName)
			else:
				destFiles.append(qualifiedName)

	if len(names) == 0:
		if isSource:
			sourceFiles.append(dirName + '/' + '__dummyEmptyDir.txt')

## Installs a tool from the tools drive to c:/Tools.
#
# This function can install a tool from either a directory or a .7z file on the tools drive.  It will
# check first for the existence of a directory containing the tool of the version specified, and, if
# not found, will then check for a .7z file containing the tool of the version specified.
#
# @param	name		The name of the tool to be installed
# @param	version		The version of the tool to be installed
def installTool(name, version):
	sourceName = installDrive + name
	sourceNameVersion = sourceName + '/' + version

	destName = 'c:/Tools/' + name
	destNameVersion = destName + '/' + version

	# Only do anything if the target tool is not already installed
	if not os.path.exists(destNameVersion):
		# Check to see if the tool specified has any versions available on l: drive
		if os.path.exists(sourceName):
			# First check if a directory containing the requested version of the tool exists.  This
			# is for legacy tools that were put onto l: drive before the faster 7z archive method was
			# introduced
			if os.path.exists(sourceNameVersion):
				print 'Installing', name, 'version', version, 'from directory'
				cloneDirectory(sourceNameVersion, destNameVersion, '.*')
			else:
				# Scan through the source directory for .7z files named after the version of the tool
				# that was requested
				found = False
				files = os.listdir(sourceName)

				for file in files:
					# These archives have the CRC of the unarchived directory encoded into their names
					# so strip that off before checking if the version number matches that requested
					archiveVersion = file.split('_')[0]

					if file[-3:] == '.7Z' and archiveVersion == version:
						found = True

						break

				# If an archive was found of the requested version then unarchive it now
				if found:
					print 'Installing', name, 'version', version, 'from archive'

					# Create the target directory and copy the archive into it, if it does not already exit
					if not os.path.exists(destName):
						os.makedirs(destName)

					if not os.path.exists(destName + '/' + file):
						shutil.copyfile(sourceName + '/' + file, destName + '/' + file)

					# And finally change to the target directory and unarchive the archive containing the tool
					oldDir = os.getcwd()
					os.chdir(destName)
					nulFile = open('nul')
					result = subprocess.call('c:/Tools/7-zip/100/7z.exe x ' + file, stdout = nulFile)
					nulFile.close()
					os.chdir(oldDir)

					if result != 0:
						print 'Error: Unable to unzip archive', file

						sys.exit(1)
				else:
					print name + '/' + version, 'does not exist'
		else:
			print name, 'does not exist'
	else:
		if verbose:
			print name, 'version', version, 'is already present'

## Main entry point for the program.
#
# The main entry point for the program.  This will attempt to open and parse the TD4 BuildDescription.xml
# file and will then install any base tools required for the functioning of the development system, as
# well as any files listed in the BuildDescription.xml file.
#
# @param	argv	A list of the arguments passed in on the command line
def main(argv):
	global installDrive

	# Check to see if l: drive is mounted and if so, use it as the installation source.  Otherwise
	# fall back to the default UNC path that is already assigned to installDrive
	if os.path.exists('l:/'):
		installDrive = 'l:/'

	# Try and open the TD4 BuildDescription.xml file for parsing.  If is not an error if this does
	# not exist so in this case, simply continue on to install just the default tools
	try:
		tree = ET.parse('04_Engineering/03_Workspace/td4/BuildDescription.xml')

		# TD4 is a special case as it is not listed like the other tools.  So begin by searching for
		# which TD4 and Eclipse versions are to be used and append them to the tools list
		td4Element = tree.find('BuildEnvironment/TD4Version')
		tools.append(('TD4', td4Element.text))

		eclipseElement = tree.find('BuildEnvironment/EclipseVersion')
		tools.append(('eclipse', eclipseElement.text))

		# Get a handle to the element representing the list of tools required by the project
		toolsElement = tree.find('Platforms/Platform/Tools')

		# Iterate through the tools contained within the Tools element and, for each one, extract
		# the tool name and the version required, and add them to the tools list
		for tool in toolsElement:
			toolName = ''
			toolVersion = ''

			# Each Tool element should contain a ToolName and a ToolVersion element so extract these
			for field in tool:
				if field.tag == 'ToolName':
					toolName = field.text
				elif field.tag == 'ToolVersion':
					toolVersion = field.text

			# If both elements were present then add the tool to the tools list
			if toolName != '' and toolVersion != '':
				tools.append((toolName, toolVersion))

	except IOError:
		pass

	# Install core tools that are required for basic functioning of the system
	installTool('7-zip', '100')
	installTool('python', '2.7.10')

	# And finally iterate through the tools that are listed in the project's BuildDescription.xml file
	# and install their required versions
	for tool in tools:
		# Skip installing Cessar-CT as its extra long directory paths can only be accessed by using special
		# Win32 APIs and trying to install it will crash Python!  TD4 is able to handle the creation of these
		# long directories so we leave it to that
		if tool[0] != 'cessar-ct':
			installTool(tool[0], tool[1])

if __name__ == '__main__':
	main(sys.argv)
