import os
import re
import sys


class State(object):

    @staticmethod
    def append_Dem(demEntries, new_DemEntry):
        demEntries.append(new_DemEntry)

    @staticmethod
    def match_line(line, dem_entry):
        pass


class StateDefault(State):
    def __init__(self):
        State.__init__(self)
        self.index = 0

    @staticmethod
    def append_Dem(demEntries, new_DemEntry):
        pass


class StateEntryAvailable(State):
    def __init__(self):
        State.__init__(self)
        self.index = 1


class StateDemId(State):
    def __init__(self):
        State.__init__(self)
        self.index = 2

    @staticmethod
    def match_line(line, dem_entry):
        linePartition = line.strip('*/')
        # Assign the ID to the actual Dem entry
        dem_entry.id.append(linePartition.strip())


class StateDemDesc(State):
    def __init__(self):
        State.__init__(self)
        self.index = 3

    @staticmethod
    def match_line(line, dem_entry):
        # Remove comment key
        lineCleaned = line.strip()
        linePartition = lineCleaned.strip('*/')
        # Add HTML line break
        dem_entry.desc += "</p>"
        # Assign the text to the actual Dem entry
        dem_entry.desc += linePartition.strip()


class StateDemExt(State):
    def __init__(self):
        State.__init__(self)
        self.index = 4


class StateDemExtType(State):
    def __init__(self):
        State.__init__(self)
        self.index = 5


class StateDemExtDesc(State):
    def __init__(self):
        State.__init__(self)
        self.index = 6

    @staticmethod
    def match_line(line, dem_entry):
        getDesc = dem_entry.extDesc.pop()
        # Add HTML line break
        getDesc += "</p>"
        # Remove comment key
        lineCleaned = line.strip()
        # Remove comment key
        linePartition = lineCleaned.strip('*/')
        getDesc += linePartition.strip()
        # Assign the text to the actual Dem entry
        dem_entry.extDesc.append(getDesc)


class StateDemExtFound(State):
    def __init__(self):
        State.__init__(self)
        self.index = 7


#States
class SetState():
    default = StateDefault()
    entryAvailable = StateEntryAvailable()
    demId = StateDemId()
    demDesc = StateDemDesc()
    demExt = StateDemExt()
    demExtType = StateDemExtType()
    demExtDesc = StateDemExtDesc()
    demExtTypeFound = StateDemExtFound()


# Single Type
class TypeEntry:
    def __init__(self):
        self.name = ""
        self.body = ""


# Single Dem entry with all information
class DemEntry:
    def __init__(self):
        self.id = []
        self.desc = ""
        self.extByteHigh = []
        self.extByteLow = []
        self.extText = []
        self.extType = []
        self.extDesc = []


class Database:
    def __init__(self, searchPath):
        self.searchPath = searchPath
        self.currentState = SetState.default
        self.currentDemEntry = DemEntry()

    def generate(self):
        global demEntries
        fileList = []

        # Create Filelist
        for root, subFolders, files in os.walk(self.searchPath):
            for fileName in files:
                if fileName.endswith(('.cpp', '.c', '.h')):
                    absFolderPath = os.path.abspath(root)
                    filePath = os.path.join(absFolderPath, fileName)
                    fileList.append(filePath)

        # Search in file list
        for file in fileList:
            src = open(file, 'r')
            for line in src:
                # Search for struct and enum types
                result = re.search('\\b(struct)|(enum)\\b', line)
                if result:
                    self.SearchType(result.group(0), line, src)
                elif "$dem" in line:
                    self.SearchMarker(line)
                    self.SearchNextMarker(src)
            src.close()
        self.currentState.append_Dem(demEntries, self.currentDemEntry)

    # Search limited on file
    def SearchNextMarker(self, src):
        count = 0

        # Max number of items of a marker
        while count < 10:
            line = src.next()
            # Empty line and End of Line
            if line == '\n' or None:
                return
            # Check if comment end
            if "*/" in line:
                return
            # New marker is found
            if "$dem" in line:
                self.SearchMarker(line)
            # Current marker is still active
            else:
                self.currentState.match_line(line, self.currentDemEntry)

            count += 1
        self.currentState == SetState.default

    def SearchMarker(self, line):

        # Search line
        if "$dem_id:" in line:
            if self.currentState != SetState.default:
                demEntries.append(self.currentDemEntry)
                self.currentDemEntry = DemEntry()
            linePartition = line.partition("$dem_id:")
            # Remove blancs
            demId = linePartition[2].strip()
            # Assign the ID to the actual Dem entry
            self.currentDemEntry.id.append(demId)
            # Store current state
            self.currentState = SetState.demId
        elif "$dem_desc:" in line:
            if self.currentState != SetState.default:
                linePartition = line.partition("$dem_desc:")
                # Remove blancs and assign to the current element
                self.currentDemEntry.desc = linePartition[2].strip()
                # Store current state
                self.currentState = SetState.demDesc
        elif "$dem_ext[" in line:
             if self.currentState != SetState.default:
                marker = re.search('\$dem_ext\[(\d):(\d)\]:', line)
                if marker:
                    # Store numbers
                    self.currentDemEntry.extByteHigh.append(marker.group(1))
                    self.currentDemEntry.extByteLow.append(marker.group(2))
                    linePartition = line.partition("]:")
                    # Remove blancs and assign to the current element
                    self.currentDemEntry.extText.append(linePartition[2].strip())
                    # Insert dummy entries for optional data
                    self.currentDemEntry.extType.append("")
                    self.currentDemEntry.extDesc.append("")
                    # Store current state
                    self.currentState = SetState.demExt
        elif "$dem_ext_type:" in line:
            if self.currentState != SetState.default:
                if self.currentDemEntry.extType:
                    linePartition = line.partition("$dem_ext_type:")
                    # Remove blancs and assign to the last element
                    self.currentDemEntry.extType[-1] = linePartition[2].strip()
                    # Store current state
                    self.currentState = SetState.demExtType
        elif "$dem_ext_desc:" in line:
            if self.currentState != SetState.default:
                if self.currentDemEntry.extDesc:
                    linePartition = line.partition("$dem_ext_desc:")
                    # Remove blancs and assign to the last element
                    self.currentDemEntry.extDesc[-1] = linePartition[2].strip()
                    # Store current state
                    self.currentState = SetState.demExtDesc

    # Search for all structs + enums
    def SearchType(self, searchType, firstLine, currentSrc):
        global typeEntries

        count = 0
        singleTypeEntry = TypeEntry()

        # Clean the string
        cleanedStr = firstLine.strip()
        # Check if the line is a comment
        if re.match("//", cleanedStr):
            return
        if re.match('\*', cleanedStr):
            return
        # Remove comments
        cleanedStr = remove_comments(cleanedStr)
        # Maybe the cleared string does not contain the Type anymore...
        if searchType not in cleanedStr:
            return
        if "{" in cleanedStr:
            # Type and "{"
            result = re.search(searchType + '(.+?){', cleanedStr)
            if result:
                if result.group(1) != ' ':
                    name = result.group(1).strip()
                    # Check if the type name contains several names
                    result = re.search(' ', name)
                    if result:
                        return
                    singleTypeEntry.name = name
        else:
            # Only the type is found
            result = re.search(searchType + ' (.+)', cleanedStr)
            if result:
                name = result.group(1).strip()
                # Check if the type name contains several names
                result = re.search(' ', name)
                if result:
                    return
                singleTypeEntry.name = name

        # Assign first line
        singleTypeEntry.body = firstLine
        # Max number of items of a marker
        while count < 500:
            try:
                line = currentSrc.next()
            except(StopIteration): return
            if line != '\n':
                # Read current data and extend it
                singleTypeEntry.body = singleTypeEntry.body + "<br>" + line
            # Forward check
            if "}" in line:
                # Search for name
                # Clean the string
                cleanedStr = line.strip()
                # Remove comments
                cleanedStr = remove_comments(cleanedStr)
                # Extract type name
                result = re.search('}(.+?);', cleanedStr)
                if result:
                    if result.group(1) != ' ':
                        singleTypeEntry.name = result.group(1).strip()
                break
            # Unknown error
            count += 1
        # Check if an ID is available
        if singleTypeEntry.name != '':
            typeEntries.append(singleTypeEntry)


class Html:
    def __init__(self, outputPath):
        self.outputPath = outputPath
        self.file_handler = None


    def GenerateHtml(self):
        global demEntries
        # Create an HTML page
        self.file_handler = open(self.outputPath, 'w')

        self.file_handler.write("<html>\n" + self.GetSwVersion())

        # HTML generation
        for demEntry in demEntries:
            # DEM Header
            self.file_handler.write(htmlHeader)
            # DEM ID's
            for demId in demEntry.id:
                self.file_handler.write("<h2><a class=\"anchor\">" + demId + "</h2>\n")
            # DEM info
            if demEntry.desc:
                self.file_handler.write("<h3>Brief information:</h3>\n")
                self.file_handler.write("<p>" + demEntry.desc + "</p>\n")
            # DEM ext data description
            if demEntry.extByteHigh:  # Let us take this as reference
                self.file_handler.write("<h3>Usage of the extended Data:</h3>\n")
                for index in xrange(len(demEntry.extByteHigh)):
                    self.file_handler.write("<h4>Structure of the used data:</h4>\n")
                    self.file_handler.write("<p>DEM_PreExtData[" + demEntry.extByteHigh[index] + ":" +
                                   demEntry.extByteLow[index] + "]")
                    if demEntry.extText[index]:
                        self.file_handler.write(": " + demEntry.extText[index] + "</p>\n")
                    else:
                        self.file_handler.write("</p>\n")
                    if demEntry.extDesc[index]:
                        self.file_handler.write("<h4>Detailed Description about the extended Data:</h4>\n")
                        self.file_handler.write("<p>" + demEntry.extDesc[index] + "</p>\n")
                    if demEntry.extType[index]:
                        # Search for the used structs + enums
                        self.GenerateTypesOutput(demEntry.extType[index])
        self.file_handler.close()

    def GenerateTypesOutput(self, extType):
        global typeEntries

        # Search through the found types
        for typeEntry in typeEntries:
            if extType == typeEntry.name:
                self.file_handler.write("<h4>Information about the used type:</h4>\n")
                # Add the type to the docu
                self.file_handler.write("<p>" + typeEntry.body + "</p>")
                # Check for built in tags...
                if "$dem_ref_type" in typeEntry.body:
                    # Separate the string in a list
                    typeList = typeEntry.body.splitlines()
                    for line in typeList:
                        result = re.search('\$dem_ref_type:(.+)', line)
                        if result:
                            typeName = result.group(1)
                            # Remove the comment char
                            result = re.search('(.+) \*\/', typeName)
                            if result:
                                typeName = result.group(1)
                            # Clean the string and call the function recursively
                            self.GenerateTypesOutput(typeName.strip())

    def GetSwVersion(self):

        # Check if 3. parameter is available
        if len(sys.argv) < 4:
            return ""
        if os.path.isfile(sys.argv[3]):
            src = open(sys.argv[3], 'r')
            for line in src:
                if "MK_EXE_VERSION" in line:
                    linePartition = line.partition("MK_EXE_VERSION")
                    lineCleaned = linePartition[2].strip()
                    result = re.search('\(\(\((.+)\) << 16u', lineCleaned)
                    baselineCode = result.group(1).strip()
                    result = re.search('\+ \(\((.+)\) << 8u', lineCleaned)
                    projectCode = result.group(1).strip()
                    result = re.search('8u\) \+ \((.+)\)\)$', lineCleaned)
                    timeCode = result.group(1).strip()
            src.close()
            return "<h2><a class=\"anchor\">SOC SW Version Number: " \
                   + baselineCode + "." + projectCode + "." + timeCode + "</h2>\n"


def remove_comments(str):
    result = re.search('(.*?)\/\*', str)
    if result:
        str = result.group(1)
    result = re.search('(.*?)\//', str)
    if result:
        str = result.group(1)
    return str


# ******************************************************************************
# main
# ******************************************************************************
if __name__ == '__main__':

    # Only for Testing
    # Search path
    # sys.argv.append("D:\\sandbox\\CCS61\\S00_ALL\\04_Engineering\\01_Source_Code\\SW\\source")
    # Output file
    # sys.argv.append("D:\sandbox\CCS61\S00_ALL\\04_Engineering\\04_Build\doc\dem_docu\DEM_descriptions.html")
    # SW version file
    # sys.argv.append("D:\sandbox\CCS61\S00_ALL\\04_Engineering\\01_Source_Code\SW\config\products\mfs430bw16\gen_buildinfo.h")

    # Initialisation
    # HTML
    htmlHeader = "<div class=\"header\">\n<div class=\"headertitle\">\n<h1><div class=\"title\">DEM Description:</div>\n</div><!--header-->\n"
    # List of all files which will be are searched
    fileList = []
    # List of all DEM entries which are found
    demEntries = []
    # List of all struct and enum entries which are found
    typeEntries = []

    # Generate console output
    print "DEM search path: "
    print os.path.abspath(sys.argv[1])
    print  # empty line

    # Search through the sources and grab the required data for the mentioned path
    grabDataInPath = Database(sys.argv[1])
    grabDataInPath.generate()

    # Generate HTML file
    generateDocu = Html(sys.argv[2])
    generateDocu.GenerateHtml()

    # Generate console output
    print "DEM output file is generated successfully:"
    print os.path.abspath(sys.argv[2])








