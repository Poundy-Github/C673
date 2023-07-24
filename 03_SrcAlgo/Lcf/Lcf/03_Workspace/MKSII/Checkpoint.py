#! /usr/bin/python
#coding: utf-8

#===============================================================================
# Checkpoint.py
#   Imports a change package and generates a list of all changes on files.
#===============================================================================

import mks                      # Provides MKS access function
import sys                      # Access to command line parameters
from IssuesIntegrated_Parameter import *

#-------------------------------------------------------------------------------
# GetIssueChangePackages
#   Requests the change package which are related to a RO
#
# Parameter:
#   Project  [in] MKS project ("project.pj" will be add in the function!)
#   Revision [in] Project revision or Development path name
#   Timeout  [in] Timeout for MKS request in seconds
#   DevPath  [in] If True, then get a developmen patch and not a checkpoint
#
# Return value:
#   Dictionary of CMember objects. The key is the member archive name.
#-------------------------------------------------------------------------------
def ImportCheckpointMemers(Project, Revision, Timeout, DevPath):
  if Project[-1:] <> '/':
    Project = Project + '/'
    
  # Import checkpoint
  print "Import %s %s" % (Project + "project.pj", Revision)
  if DevPath:
    MksResponse = mks.run("si viewproject --batch -R --project=%s --devpath=%s --fields=indent,name,memberrev,memberarchive" % (Project + "project.pj", Revision), Timeout)    
  else:
    MksResponse = mks.run("si viewproject --batch -R --project=%s --projectRevision=%s --fields=indent,name,memberrev,memberarchive" % (Project + "project.pj", Revision), Timeout)
  
  Directories = []
  FullProject = Project
  MemberList = []
  
  if MksResponse:
    for Line in MksResponse.split("\n"):
      if len(Line):
        
        # Get indent
        Indent = (len(Line) - len(Line.lstrip()) - 1) // 2
        
        # Check if file or subproject
        SplitLine = Line.lstrip().split()
        SlashPos = SplitLine[0].find('/')
        
        # Add file to list
        if SlashPos < 0:
          
          #                File                      , Revision    , MemberArchive
          Member = CMember(FullProject + SplitLine[0], SplitLine[1], SplitLine[2])
          MemberList.append(Member)
        
        # Add subproject to Directory list        
        else:
          if Indent == len(Directories):
            Directories.append(SplitLine[0][:SlashPos])
          elif Indent < len(Directories):
            Directories[Indent] = SplitLine[0][:SlashPos]
          else:
            print "Error: Incomplete project returned from MKS"
            return None
          
          # Generate project string
          FullProject = Project
          i = 0
          while i <= Indent:
            FullProject += Directories[i] +  "/"
            i += 1
    
    return MemberList

  else:
    return None

#===============================================================================
# Class CChange
#   Contains the data of one MKS change package entry.
#===============================================================================
class CMember:
  def __init__(self, File, Revision, MemberArchive):
    self.mFile           = File
    self.mMemberArchive  = MemberArchive
    self.mRevision       = Revision

    # Follwing parameters will be set if an change for this member is found
    self.mPlannedRevision = None
    self.mIntegrationStatus = "UNKNOWN"
    self.mChangePackageID = "?"

  #-----------------------------------------------------------------------------
  # __str__:
  #   Generate string for print
  #
  # Parameter:
  #   - none -
  #
  # Return value:
  #   String
  #-----------------------------------------------------------------------------
  def __str__(self):
    return "%-10s %s (%s)" % (self.mRevision, self.mFile, self.mMemberArchive)

#===============================================================================
# main function
#   Print a list of all members in release checkpoint
#
# Parameter:
# - Change package ID
#===============================================================================
if __name__ == "__main__":
  # Check number of parameters
  if len(sys.argv) <> 3:
    print "Error: Checkpoint.py needs 2 parameters!"
    print "       Parameter 1: MKS loacation of engineering folder"
    print "       Parameter 2: Checkpoint revision"
    print "       Example: python Checkpoint.py /ADAS/SW/Projects/SRR52x/SRR520/M11_APPL/04_Engineering 1.12.1.6"
    sys.exit(1) 

  # Get Parameters
  else:
    # Import checkpoint members
    MemberList = ImportCheckpointMemers(sys.argv[1], sys.argv[2], 60, False)
    if MemberList:
      for Member in MemberList:
        print Member