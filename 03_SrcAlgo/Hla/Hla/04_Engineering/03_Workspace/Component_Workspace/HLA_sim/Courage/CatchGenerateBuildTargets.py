# CatchGenerateBuildTargets.py:
#-------------------------
#
# This python script is intended to parse folder structure of this folder.
# If a Makefile was found it means there are unit tests available for which
# a build target in Catch+ project will be generated.

#-------------------------
# import
#-------------------------
import os, re, stat

#-------------------------
# configuration
#-------------------------
UNIT_TEST_INDICATOR_FILE="Makefile"
CPROJECT_FILE = ".cproject"
BUILD_TARGET_PATTERN = "buildTargets>"
BUILD_TARGET = \
"""			<target name="{name}" path="{path}" targetID="org.eclipse.cdt.build.MakeTargetBuilder">
				<buildCommand>${{COURAGE_MK}}</buildCommand>
				<buildArguments/>
				<buildTarget>{name}</buildTarget>
				<stopOnError>true</stopOnError>
				<useDefaultCommand>false</useDefaultCommand>
				<runAllBuilders>true</runAllBuilders>
			</target>
"""
BUILD_TARGET_STORAGE_MODULE_BEGIN= \
"""	<storageModule moduleId="org.eclipse.cdt.make.core.buildtargets">
		<buildTargets>
"""
BUILD_TARGET_STORAGE_MODULE_END = \
"""		</buildTargets>
	</storageModule>
"""

#-------------------------
# functions
#-------------------------
def main():
    unitTests = []

    # Check all subfolders to find available unit tests
    for file in os.listdir("."):
        if os.path.isdir(file):
            # Get underlying folder structure
            for root, subdirs, files in os.walk(file):
                # Check whether Makefile was in this folder, i.e. this folder is a unit test
                if UNIT_TEST_INDICATOR_FILE in files:
                    # Append to list of valid unit test
                    unitTests.append([os.path.basename(root), root])

    if (os.path.isfile(CPROJECT_FILE)):
        # Remove write protection
        os.chmod(CPROJECT_FILE, stat.S_IWRITE)

        # Open cproject file.
        cprojectFile = open(CPROJECT_FILE, 'r+')

        # Read whole content
        cprojectFileContent = cprojectFile.readlines()

        indexStart = 0
        indexEnd = 0
        # Go through every line until build targets area is found
        for index, line in enumerate(cprojectFileContent):
            # Search for a build target pattern
            if re.search(BUILD_TARGET_PATTERN, line):
                if indexStart:
                    # We reached end of critical area. Let's stop here.
                    indexEnd = index
                    break;
                else:
                    # We reached critical area.
                    indexStart = index + 1

        if indexStart != 0 and indexEnd != 0:
            # Remove all old build targets between indexStart and indexEnd
            for index in range(0, indexEnd - indexStart):
                del cprojectFileContent[indexStart]
                
            # Insert build targets
            insertBuildTargets(cprojectFileContent, indexStart, unitTests)
        else:
            # This seems to be an empty .cproject file, i.e. fill some missing xml tags at last line but one
            cprojectFileContent.insert(index, BUILD_TARGET_STORAGE_MODULE_END)
            # Insert build targets
            insertBuildTargets(cprojectFileContent, index, unitTests)
            # This seems to be an empty .cproject file, i.e. fill some missing xml tags at last line but one
            cprojectFileContent.insert(index, BUILD_TARGET_STORAGE_MODULE_BEGIN)
        
        # Return to beginning of cproject file and write back new content
        cprojectFile.seek(0)
        cprojectFile.writelines(cprojectFileContent)

        # Close cproject file as no longer needed
        cprojectFile.close()
    else:
        print(os.path.basename(__file__) + ': CProject ' + os.path.abspath(CPROJECT_FILE) + ' could not be opened. Please check path.')
        exit
        
        
def insertBuildTargets(fileContent, index, unitTests):
    # Write new build targets for every valid unit test
    for unitTest in reversed(unitTests):
        fileContent.insert(index, BUILD_TARGET.format(name="clean", path=unitTest[1]))
        fileContent.insert(index, BUILD_TARGET.format(name=unitTest[0]+"_DONE", path=unitTest[1]))


# **********************************************************************
# MAIN FUNCTION CALL
# ********************************************************************** 
# Put this at the end of the file in order to force the interpreter 
# to go throught the whole file. Then he knows all functions.   
if __name__ == "__main__":
    main()