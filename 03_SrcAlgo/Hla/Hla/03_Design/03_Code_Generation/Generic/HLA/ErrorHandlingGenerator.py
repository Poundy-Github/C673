# generateEnumHash.py:
#-------------------------
#
# This python script is intended to parse enums and generates hashes for it.
# This hash can be included in a struct where this enum is used.
# It shall play safe that the enum is interpreted correctly. Main use case:
# Measfreezes of enum is of different version than then one used for visualization
# of it. This can happen if size of measfreeze is qual to current one, for instance
# enum value added, deleted, etc.

#-------------------------
# import
#-------------------------
import os, re, hashlib, stat
from ErrorHandlingGeneratorCfg import *

#-------------------------
# configuration
#-------------------------
# Is done in generateEnumHashCfg.py

#-------------------------
# functions
#-------------------------
def main():
  
  if (os.path.isfile(ERROR_HANDLING_HEADER_FILE)):
    # Remove write protection
    os.chmod(ERROR_HANDLING_HEADER_FILE, stat.S_IWRITE)

    # Open error handling header file.
    headerFile = open(ERROR_HANDLING_HEADER_FILE, 'r+')
  
    # Read whole content
    headerFileContent        = headerFile.readlines()
    headerFileContentReverse = reversed(headerFileContent)
    
    # Generate hashes
    hashInformation = GenerateHash(headerFileContentReverse, ENUM_INFORMATION, ENUM_PREFIX_INFORMATION)
    hashWarnings    = GenerateHash(headerFileContentReverse, ENUM_WARNING,     ENUM_PREFIX_WARNING)
    hashErrors      = GenerateHash(headerFileContentReverse, ENUM_ERROR,       ENUM_PREFIX_ERROR)
    
  
    headerFileModified = False
    # Go through every line and replace hashes if needed
    for index, line in enumerate(headerFileContent):
      # Search for a hash field
      if re.search(HASH_NAME_PREFIX, line):
        # A hash field was found -> Let's check whether we should update it
        headerFileModified |= UpdateHash(headerFileContent, index,     HASH_NAME_ERROR,       hashErrors)
        headerFileModified |= UpdateHash(headerFileContent, index + 1, HASH_NAME_WARNING,     hashWarnings)
        headerFileModified |= UpdateHash(headerFileContent, index + 2, HASH_NAME_INFORMATION, hashInformation)
        # No need to check more details
        break
    
    # Return to beginning of source file and write back new content if needed
    if headerFileModified == True:
      headerFile.seek(0)
      headerFile.writelines(headerFileContent)
      print("Hashes for error handling enums were update in {file}.".format(file=os.path.abspath(ERROR_HANDLING_HEADER_FILE)))
    
    # Close header as no longer needed
    headerFile.close()
    
    headerFileContentReverse = reversed(headerFileContent)
    
    # Extract enum entries
    enumEntriesInformation = ExtractErrorEnums(headerFileContentReverse, ENUM_INFORMATION, ENUM_PREFIX_INFORMATION)
    enumEntriesWarnings    = ExtractErrorEnums(headerFileContentReverse, ENUM_WARNING,     ENUM_PREFIX_WARNING)
    enumEntriesErrors      = ExtractErrorEnums(headerFileContentReverse, ENUM_ERROR,       ENUM_PREFIX_ERROR)
    
    # Update visualization if needed
    if headerFileModified == True:
      updateVisErrorEnums(enumEntriesErrors, enumEntriesWarnings, enumEntriesInformation, ENUM_PREFIX_ERROR, ENUM_PREFIX_WARNING, ENUM_PREFIX_INFORMATION) 
      print("")    
  else:
    print("{file}: Error handling header file {path} could not be opened. Please check path.".format(file=os.path.basename(__file__), path=os.path.abspath(ERROR_HANDLING_HEADER_FILE)))
    exit
    
def GenerateHash(file, enumName, enumPrefix):
  # read header file bottom up until enumName was found
  for line in file:
    # Search for corresponding enum defintion
    if re.search(enumName + ';', line):
      break

  enumEntries = []
  # Enum found -> let's collect all enum elements
  for line in file:
    # Search for corresponding enum defintion
    regex = re.search('(%s\w*)' % enumPrefix, line)
    if regex != None:
      # Append enum definition to list
      enumEntries.append(regex.group(1))
      
    # Search for end of enum definition
    regex = re.search('typedef enum', line)
    if regex != None:
      break
    
  # Generate hash over all elements of this enum
  SHAhash = hashlib.md5()
  for element in enumEntries:
    SHAhash.update(hashlib.md5(element).hexdigest())

  # Return lower 32-bits, should enough for us
  return SHAhash.hexdigest()[-8:]  

def UpdateHash(fileContent, index, hashField, hashValue):
  line = fileContent[index]
  # Search for hashField
  regex = re.search('%s *\(0x([0-9A-Fa-f]*)u\)' % hashField, line)
  if regex != None:
    # Replace hash value if needed
    if regex.group(1) != hashValue:
      fileContent[index] = line.replace(regex.group(1), str(hashValue))
      # Hash was replaced -> source file has to be updated
      return True
  
  # Hash was not replaced -> no need to update source file
  return False
 
    
def ExtractErrorEnums(file, enumName, enumPrefix):
  # read header file bottom up until enumName was found
  for line in file:
    # Search for corresponding enum defintion
    if re.search(enumName + ';', line):
      break

  enumEntries = []
  # Enum found -> let's collect all enum elements
  for line in file:
    # Search for corresponding enum defintion
    regex = re.search('(%s\w*)' % enumPrefix, line)
    if regex != None:
      # Append enum definition to list
      enumEntries.append(regex.group(1))

    # Search for conditional compilations, #if, #endif, etc.
    if '#' in line:
      # Append conditional compilations to list
      enumEntries.append(line)

    # Search for end of enum definition
    regex = re.search('typedef enum', line)
    if regex != None:
      break
  return enumEntries
  
def updateVisErrorEnums(enumEntriesErrors, enumEntriesWarnings, enumEntriesInformation, ENUM_PREFIX_ERROR, ENUM_PREFIX_WARNING, ENUM_PREFIX_INFORMATION): 
    
  [file_buf, errors_begin, errors_end, warnings_begin, warnings_end, infos_begin, infos_end] = getContentOfLSD_VisError()
  file_buf = buildCppContent( file_buf, 
                              enumEntriesErrors,       ENUM_PREFIX_ERROR,      errors_begin,   errors_end, 
                              enumEntriesWarnings,     ENUM_PREFIX_WARNING,    warnings_begin, warnings_end, 
                              enumEntriesInformation, ENUM_PREFIX_INFORMATION, infos_begin,    infos_end
                             )
  
  writeFile(file_buf)

def getContentOfLSD_VisError():
  # Remove write protection
  os.chmod(PATH_VIS_ERROR_CPP, stat.S_IWRITE)
  ## gets content of PATH_VIS_ERROR_CPP
  # returns buffer with file content and beginning and ending index of enumerations
  #
  errorVis = open(PATH_VIS_ERROR_CPP, 'r')
  
  errors_begin   = 0
  errors_end     = 0
  warnings_begin = 0
  warnings_end   = 0
  infos_begin    = 0
  infos_end      = 0
  try:
    file_buf = list(errorVis)
    
    # get begin and end of error, warning and info TYPE-handling
    for i, line in enumerate(file_buf):
      buf = line.strip()
      if (buf == DELIMITER_ERROR_START):
        errors_begin = i+1
      elif (buf == DELIMITER_ERROR_END):
        errors_end = i+1
      elif (buf == DELIMITER_WARNING_START):
        warnings_begin = i+1
      elif (buf == DELIMITER_WARNING_END):
        warnings_end = i+1
      elif (buf == DELIMITER_INFO_START):
        infos_begin = i+1
      elif (buf == DELIMITER_INFO_END):
        infos_end = i+1
    
  except Exception, e:
    print("Error while reading {path} in line: ".format(path=os.path.abspath(PATH_VIS_ERROR_CPP)))
    print(i)
    print(e)
  finally:
    errorVis.close()
    return [file_buf, errors_begin, errors_end, warnings_begin, warnings_end, infos_begin, infos_end]
     
def buildCppContent(file_buf, errors, errors_prefix, errors_begin, errors_end, warnings, warnings_prefix, warnings_begin, warnings_end, infos, infos_prefix, infos_begin, infos_end):    
  ## update in LSD_VisError.cpp
  # fills file bottom up.
  # deletes and updates entries from the bottom to save the beginning index of each enumeration.
  # parameters:
  # file_buf := buffer with file content
  # errors := array of error enumerations
  # warnings := array of warning enumerations
  # infos := array of information enumerations
  # x_begin := index witch defines where the enumeration of x begins
  # x_end := index witch defines where the enumeration of x ends
  #
  # returns updated file buffer
  
  # refill content of INFORMATION_TYPES
  del file_buf[infos_begin:infos_end-1]
  for info in infos:
    insertCase(file_buf, infos_begin, infos_prefix, info, 'information')
      
  # refill content of WARNING_TYPES
  del file_buf[warnings_begin:warnings_end-1]
  for warning in warnings:
    insertCase(file_buf, warnings_begin, warnings_prefix, warning, 'warning')
  
  # refill content of ERROR_TYPES
  del file_buf[errors_begin:errors_end-1]
  for error in errors:
    insertCase(file_buf, errors_begin, errors_prefix, error, 'error')
  
  return file_buf

def insertCase(file_buf, index, prefix, code, kind):
  ## builds and inserts case instructions into file buffer
  # parameters:
  # file_buf := the content of the file to be filled.
  # index := line to insert case instruction
  # prefix := type of error-code (ERROR, WARNING or INFORMATION)
  # code := the error-code itself
  # kind := see prefix
  #

  # Search for conditional compilations, #if, #endif, etc.
  if '#' in code:
    case_templ = code
  else:
    case_templ = "      case %(code)s:\n        %(kind)sList.SetCell(++row, COL_0, \"%(codeshort)s\", drawColor);\n        break;\n" % {'code' : code, 'kind' : kind, 'codeshort' : re.sub(prefix, '', code)}
  file_buf.insert(index, case_templ)

def writeFile(file_buf):
  ## writes content of given buffer into file
  #
  errorVis = open(PATH_VIS_ERROR_CPP, 'w')
  try:
    for line in file_buf:
      errorVis.write(line)
  except Exception, e:
    print("Error while writing file: {path}".format(path=os.path.abspath(PATH_VIS_ERROR_CPP)))
    print(e)
  finally:
    errorVis.close()
    print("Error handling visualization file {path} was successfully updated.".format(path=os.path.abspath(PATH_VIS_ERROR_CPP)))
  
# **********************************************************************
# MAIN FUNCTION CALL
# ********************************************************************** 
# Put this at the end of the file in order to force the interpreter 
# to go throught the whole file. Then he knows all functions.   
if __name__ == "__main__":
  main()