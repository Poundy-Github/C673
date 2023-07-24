# DecodeErrorStack.py:
#-------------------------
#
# This python script is intended to decode error, warning and information 
# messages of the algo internal error stack.
# Please make sure that it is configured correctly.

#-------------------------
# import
#-------------------------
import os, re, stat, sys

#-------------------------
# configuration
#-------------------------
ERROR_STACK_DEFINITION_FILE = '../../../01_Source_Code/LSD/utils/LSD_UtilsErrorHandlingTypes.h'

ENUM_ERROR       = 'e_UtilsErrorHandling_Errors'
ENUM_WARNING     = 'e_UtilsErrorHandling_Warnings'
ENUM_INFORMATION = 'e_UtilsErrorHandling_Information'

ENUM_PREFIX_ERROR       = 'UTILS_ERROR_HANDLING_ERROR_'
ENUM_PREFIX_WARNING     = 'UTILS_ERROR_HANDLING_WARNING_'
ENUM_PREFIX_INFORMATION = 'UTILS_ERROR_HANDLING_INFORMATION_'

ERROR_CODE_INPUT_IN_HEX = False

class ContinueOuterLoop(Exception):
    pass

#-------------------------
# functions
#-------------------------
def main():
  try:
    # Open error handling header file.
    headerFile = open(os.path.abspath(ERROR_STACK_DEFINITION_FILE), 'r')
    # Read whole content
    headerFileContent = headerFile.readlines()
    # Close header as no longer needed
    headerFile.close()
  except:
    print os.path.basename(__file__) + ': Error handling header file ' + os.path.abspath(ERROR_STACK_DEFINITION_FILE) + ' could not be opened. Please check path.'
    sys.exit()
  
  # Check with user for active sections
  activeSections = CheckActiveSections(headerFileContent)
  
  # Extract error enums. Keep order
  enumEntries = []
  enumEntries.append(ExtractErrorEnums(headerFileContent, activeSections, 3, ENUM_INFORMATION, ENUM_PREFIX_INFORMATION))
  enumEntries.append(ExtractErrorEnums(headerFileContent, activeSections, 2, ENUM_WARNING,     ENUM_PREFIX_WARNING))
  enumEntries.append(ExtractErrorEnums(headerFileContent, activeSections, 1, ENUM_ERROR,       ENUM_PREFIX_ERROR))

  # Get error category firstly
  print "Which category do you want to decode? Errors(2), Warnings(1), Information messages(0): "
  sys.stdout.flush()
  try:
    category = int(sys.stdin.readline())
    if not 0 <= category <= 2:
      print "Out of range!"
      sys.exit()
  except: 
    print "Please type a valid category [0..2]."
    sys.exit()
  
  # Get array element next
  print "Which element do you want to decode? First element starts with 1: "
  sys.stdout.flush()
  try:
    element = int(sys.stdin.readline())
    if not 1 <= element <= ((len(enumEntries[category]) / 32) + 1):
      print "Out of range!"
      sys.exit()
  except: 
    print "Please type a valid elemt [1.." + str((len(enumEntries[category]) / 32) + 1) + "] for this category."
    sys.exit()

  # Get error code
  try:
    if ERROR_CODE_INPUT_IN_HEX == True:
      print "Which error code shall be decoded? Please insert in hex without leading 0x: "
      sys.stdout.flush()
      errorCode = int(sys.stdin.readline(), 16)
    else:
      print "Which error code (decimal) shall be decoded? "
      sys.stdout.flush()
      errorCode = int(sys.stdin.readline())
    if not 1 <= errorCode <= 0xFFFFFFFF:
      print "Out of range!"
      sys.exit()
  except: 
    print "Please type a valid number (32-bit integer)"
    sys.exit()

  # Print errors if bit is set in error code
  print "\nDecoded error messages:"
  for i in range(32):
    if (errorCode & (1 << i)):
      if len(enumEntries[category]) > ((element - 1) * 32 + i):
        print enumEntries[category][(element - 1) * 32 + i]  
      else: 
        print "Error code is out of range!"
        sys.exit()

# parse whole file for #if/#elif sections
# user shall be asked whether this section is active of not
def CheckActiveSections(file):
  sections = []
  continueOuterLoop_1 = ContinueOuterLoop()

  # Read file
  for line in file:
    # Search for #if/#elif sections
    if re.search('^\s*#e?l?if', line):
      userResponse = ''

      # skip header file guard
      if re.search('_H$', line):
        continue

      # skip #elif sections if previous #if was selected as True
      if re.search('^\s*#elif', line):
        if sections[-1]["active"]:
          continue

      # Check whether section has already been treated
      try:
        for section in sections:
          if line.rstrip() == section["name"]:
            # skip this section
            raise continueOuterLoop_1
            break
      except ContinueOuterLoop:
        continue

      # Ask user whether this section is active or not
      print "Please tell me. Is this section \"" + line.rstrip() + "\" active? (y/n): "
      sys.stdout.flush()
      while userResponse.rstrip() != 'y' and userResponse.rstrip() != 'n':
        userResponse = sys.stdin.readline()

      # Append section to list
      sections.append({"name": line.rstrip(), "active" : 1 if userResponse.rstrip() == 'y' else 0})

  return sections

def ExtractErrorEnums(file, activeSections, enumOrderNumber, enumName, enumPrefix):
  enumsFound = 0
  lastLineRead = 0

  # Search until enum of the right order starts, i.e. errors, warnings or information
  for index, line in enumerate(file):
    regex = re.search('typedef enum', line)
    if regex != None:
      enumsFound += 1
      if enumsFound == enumOrderNumber:
        lastLineRead = index
        break

  enumEntries = []
  bInSection = False
  bSectionActive = False

  # read header file until end of enumName was found
  for index, line in enumerate(file):
    # Skip first lines which are already read
    if index < lastLineRead:
      continue

    # Search for end of corresponding enum defintion
    if re.search(enumName + ';', line):
      break

    # Search for corresponding enum definition
    regex = re.search('(%s\w*)' % enumPrefix, line)
    if regex != None:
      # Append enum definition to list
      if not bInSection or bSectionActive:
        enumEntries.append(regex.group(1))
      
    # Search for section specific parts - the beginning
    regex = re.search('^\s*#e?l?if', line)
    if regex != None:
      # Select matching section
      for section in activeSections:
        if line.rstrip() == section["name"]:
          # Set section flag
          bInSection = True
          # Check whether section is active or not
          bSectionActive = section["active"]

    # Search for specific parts - the else part
    regex = re.search('#else', line)
    if regex != None:
      # Swap project state
      bSectionActive = not bSectionActive
      
    # Search for specific parts - the end
    regex = re.search('#endif', line)
    if regex != None:
      # Switch off project specific part in any case
      bInSection = False
      bSectionActive = False
      
  return enumEntries
  
# **********************************************************************
# MAIN FUNCTION CALL
# ********************************************************************** 
# Put this at the end of the file in order to force the interpreter 
# to go throught the whole file. Then he knows all functions.   
if __name__ == "__main__":
    main()