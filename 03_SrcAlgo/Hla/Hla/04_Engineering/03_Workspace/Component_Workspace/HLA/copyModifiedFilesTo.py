# CopyModifiedFilesTo.py
#-------------------------
#
# This python script is intended to copy modified (in terms of MKS) files to another sandbox.
# This only works for mainstream sandboxes. Not matched files are ignored.

#-------------------------
# import
#-------------------------
import os, sys, re, stat, subprocess, shutil

#-------------------------
# configuration
#-------------------------
SANDBOX_PATH = os.path.abspath("../../../../../")
MTS_PATH = os.path.abspath(SANDBOX_PATH + "/MTS/05_Testing/MTS/mts_measurement/cfg")
BUILD_UNITS = ["APPL", "DPU"]

SI_GET_MODIFIED_FILES = "si print --recurse --filter=changed:working"

#-------------------------
# functions
#-------------------------
def main():
    originalFolder = os.getcwd()

    # Move to build unit path
    os.chdir(SANDBOX_PATH)

    # Determin Build Unit path and project
    buildUnit = determineBuildUnitPath(SANDBOX_PATH)
    project   = determineProject(SANDBOX_PATH)

    modifiedFilePaths = []
    # Get a list of modified files
    findModifiedFiles(SANDBOX_PATH + "/" + buildUnit, modifiedFilePaths)
    findModifiedFiles(MTS_PATH, modifiedFilePaths)

    # Select target sandbox
    possibleSandboxes = os.listdir(SANDBOX_PATH + "/..")
    numSandboxes = 0
    for sandbox in possibleSandboxes:
        # print possible sandboxes at same level as this one
        print "(" + str(numSandboxes) + "): " + sandbox
        numSandboxes += 1

    # Ask user which one to take
    print "Please select a sandbox or specify relative path to it: "
    sys.stdout.flush()
    selection = raw_input("")
    print ""
    try:
        if int(selection) < numSandboxes:
            # Valid selection
            targetSandbox = os.path.abspath("../" + possibleSandboxes[int(selection)])
        else:
            print "No valid selection."
            exit(-1)
    except ValueError:
        # No valid sandbox selected. Try to resolve the possible path
        if os.path.isdir(selection):
            # But valid path entered to a different sandbox
            targetSandbox = os.path.abspath(selection)
        else:
            print "No valid path to sandbox."
            exit(-2)

    print "Sandbox " + targetSandbox + " selected."

    # Verify target build unit path
    targetBuildUnit = determineBuildUnitPath(targetSandbox)
    targetProject = determineProject(targetSandbox)

    # Replace build unit and project in file paths if needed
    targetFilePaths = list(modifiedFilePaths)
    for index, targetFilePath in enumerate(targetFilePaths):
        targetFilePaths[index] = targetFilePath.replace(buildUnit, targetBuildUnit)
        targetFilePaths[index] = targetFilePaths[index].replace(project, targetProject)

    # Get user confirmation for overwriting files in traget sandbox
    print "Files in target sandbox " + targetSandbox + " will be overwritten. Are you sure to continue? (y|n): "
    sys.stdout.flush()
    overwriteConfirmation = raw_input("")
    print ""

    if overwriteConfirmation == "y":
        # Copy files to target sandbox and list not matching/copied files
        for index, targetFile in enumerate(targetFilePaths):
            sourcePath = SANDBOX_PATH + "/" + modifiedFilePaths[index]
            targetPath = targetSandbox + "/" + targetFile

            if os.path.isfile(targetPath):
                # Target file exists, let's replace it
                os.chmod(targetPath, stat.S_IWRITE)
                try:
                    shutil.copy2(sourcePath, targetPath);
                except:
                    print "File " + sourcePath + " could not be matched to target sandbox."
            else:
                print "File " + sourcePath + " could not be matched to target sandbox."

    # Move back to original folder
    os.chdir(originalFolder)

def determineBuildUnitPath(sandboxPath):
    for buildUnit in BUILD_UNITS:
        if os.path.isdir(sandboxPath + "/" + buildUnit):
            return buildUnit

    print "No valid build unit path could be established for sandbox " + sandboxPath
    exit(-3)

def determineProject(sandboxPath):
    # Search for MFCxxx project in sandbox path
    regex = re.search('(MFC\d{3})', sandboxPath)
    if regex != None:
      return regex.group(1)

    print "No valid project determined for sandbox " + sandboxPath
    exit(-4)

def findModifiedFiles(searchPath, fileList):

    # Get a list of modified files
    foundFiles = subprocess.check_output(SI_GET_MODIFIED_FILES + " " + searchPath + "/project.pj")
    for file in foundFiles.split():
        if '\\' in file:
            # file found, store it
            fileList.append(file)

# **********************************************************************
# MAIN FUNCTION CALL
# **********************************************************************
# Put this at the end of the file in order to force the interpreter
# to go throught the whole file. Then he knows all functions.
if __name__ == "__main__":
    main()