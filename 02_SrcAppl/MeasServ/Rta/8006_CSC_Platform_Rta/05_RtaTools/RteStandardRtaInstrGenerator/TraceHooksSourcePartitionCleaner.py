import os

from InstrGeneratorBase import InstrGenBase

#################################################################################
#
#################################################################################
class TraceHooksSourcePartitionCleaner(InstrGenBase):


  CLEANUP_INFO_TEXT = '''

#warning: MemoryPartiton removed - check if this file is still needed. If not please remove it!!

/* Note: The MemoryPartition related to this partitionSpecific traceHookSourceFile has been removed.
   Therefore there are no generated traceHookFunctions within this file anymore.
   In this regard the file shall be dropped!!
*/

'''

  #Initialise the class################################################################################################################################################################################
  def __init__(self, notNeededFiles):

    tagList = [
      self.GEN_TAG_HOOK_FCT_START,
      self.GEN_TAG_HOOK_FCT_END,
    ]

    #Loop over all files and remove the generated part if possible
    for File in notNeededFiles:
      if self.isTraceHookSourceValid(File, tagList):
        self.removeGeneratedPartOfTraceHookSoure(File)


  #####################################################################################################################################################################################################
  def isTraceHookSourceValid(self, fileToCheck, allRequiredTags):
    isValid = False

    #Read the lines of given file
    allLines = self.getLinesOfFile(fileToCheck)
    listIdx = 0

    #Check whether the file contains all needed tags in the right order
    for line in allLines:
      #Find next tag
      if -1 != line.find(allRequiredTags[listIdx]):
        #Ok - next tag found just increment index
        listIdx += 1
        #Check whether this was already the last index to be found
        if len(allRequiredTags) <= listIdx:
          # ok, all tags found
          isValid = True
          break

    return isValid

  #####################################################################################################################################################################################################
  def removeGeneratedPartOfTraceHookSoure(self, fileToClean):
    print ('Clean the file ' + str(os.path.basename(fileToClean)))

    #Read the current lines of the file to be cleaned
    lines = self.getLinesOfFile(fileToClean)

    linesBelowStartTag = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_HOOK_FCT_START, lines, linesBelowStartTag)

    lines.extend(self.CLEANUP_INFO_TEXT)

    self.addLinesBelowTag(self.GEN_TAG_HOOK_FCT_END , linesBelowStartTag, lines)

    #Finally write the lines into the file to be cleaned
    self.writeLinesintoFile(fileToClean, lines)

