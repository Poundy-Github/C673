#! /usr/bin/python
#coding: utf-8

#===============================================================================
# ChangePackage.py
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
#   OrderID [in] Realization Order ID
#
# Return value:
#   Change package ID list
#-------------------------------------------------------------------------------
def GetChangePackageList(OrderID):
  MksResponse = mks.run("si viewcps --fields=Id %s" % (OrderID,), TIMEOUT_LIST_CP, True)

  ChangePackageList = []

  if MksResponse:
    if MksResponse[2] <> "->":  # No change packages
      for ChangePackageID in MksResponse.split("\n"):
        if len(ChangePackageID):
          ChangePackageList.append(ChangePackageID)

  return ChangePackageList

#-------------------------------------------------------------------------------
# ImportChangePackage
#   Imports 1 change package from MKS.
#   Adds the all changes in the change package to a list of CChange objects
#
# Parameter:
#   ChangePackageID [in]     Change package ID
#   ChangeList      [in/out] List of CChange objects
#-------------------------------------------------------------------------------
def ImportChangePackage(ChangePackageID, ChangeDict):
  # Request change package from MKS
  MksResponse = mks.run("im viewcp --batch --attributes=Entries %s" % (ChangePackageID,), TIMEOUT_VIEW_CP)
  if MksResponse:

    # Get change package entries
    for Change in MksResponse.split("\n"):

      # Ignore headlines and empty lines
      ChangeDataList = Change.split('\t')
      if len(ChangeDataList) == 10:

        # Ignore changes on subprojects
        if ChangeDataList[2].find('/') < 0:

          Member   = ChangeDataList[7]
          Revision = ChangeDataList[3]

          # Member already in the list:
          if ChangeDict.has_key(Member):
            ChangeDict[Member].UpdateRevision(Revision, ChangePackageID)

          # Add new Member to list
          else:
            # Add new CChange object to the list
            NewChange = CChange(ChangePackageID, Member, Revision)
            ChangeDict.update({Member: NewChange})

#===============================================================================
# Class CChange
#   Contains one chang epackage entry
#===============================================================================
class CChange:

  #-----------------------------------------------------------------------------
  # Init class:
  #   Stores the data to member variables.
  #   
  #
  # Parameter:
  #   ChangePackageID [in] Change Package ID where the new change is listed
  #   Member          [in] Changed file (with full path information
  #   Revision        [in] Member revision of the new change
  #-----------------------------------------------------------------------------
  def __init__(self, ChangePackageID, Member, Revision):
    self.mChangePackageID = ChangePackageID
    self.mMember          = Member
    self.mRevision        = CRevision(Revision)

    # Used to compare the Issue revision with the released revision
    self.mReleaseRevision   = ""
    self.mIntegrationStatus = "NOT FOUND"

  #-----------------------------------------------------------------------------
  # UpdateRevision:
  #   Used when a file has more then one change. Only the change with the highest
  #   member revision will be stored.
  #
  # Parameter:
  #   Revision        [in] Member revision of the new change
  #   ChangePackageID [in] Change Package ID where the new change is listed
  #-----------------------------------------------------------------------------
  def UpdateRevision(self, Revision, ChangePackageID):
    Revision=CRevision(Revision)
    if self.mRevision < Revision:
      self.mRevision = Revision
      self.mChangePackageID = ChangePackageID

  #-----------------------------------------------------------------------------
  # CheckIntegrationStatus
  #   Compares the file revision of the release with the file revision of the change.
  #
  # Parameter:
  #   ReleaseRevision [in] Revision of the file in the release
  #
  # Return value:
  #   True  -> The change is integrated
  #   False -> The change is not integrated
  #-----------------------------------------------------------------------------
  def CheckIntegrationStatus(self, ReleaseRevision):
    self.mReleaseRevision = ReleaseRevision

    if self.mRevision <= ReleaseRevision:
      if self.mRevision.CompareParent(ReleaseRevision):
        self.mIntegrationStatus = "INTEGRATED"
      else:
        self.mIntegrationStatus = "BRANCH INTEGRATED"
      return True

    else:
      self.mIntegrationStatus = "NOT INTEGRATED"
      return False

  #-----------------------------------------------------------------------------
  # __str__:
  #   Generate string for print
  #
  # Parameter:
  #   - none -
  #
  # Return value:
  #   "Revision Member"
  #-----------------------------------------------------------------------------
  def __str__(self):
    return "%-10s %s" % (self.mRevision, self.mMember)

  #-----------------------------------------------------------------------------
  # Compare operators
  #   Operators == != < > <= >=
  #   Used to sort the change list by location
  #
  # Parameter:
  #   right [in] Second compare obejct (type CChange)
  #
  # Return Value:
  #   True  -> Compare is True
  #   False -> Compare is False
  #-----------------------------------------------------------------------------
  def __eq__(self, right):	# self == right
    return (self.mMember == right.mMember) and (self.mRevision == right.mRevision)

  def __ne__(self, right):	# self != right
    return (self.mMember <> right.mMember) or (self.mRevision <> right.mRevision)

  def __lt__(self, right):	# self < right
    if self.mMember <> right.mMember:
      return self.mMember < right.mMember
    else:
      return self.mRevision < right.mRevision

  def __gt__(self, right):	# self > right
    if self.mMember <> right.mMember:
      return self.mMember > right.mMember
    else:
      return self.mRevision > right.mRevision

  def __le__(self, right):	# self <= right
    return (self < right) or (self == right)

  def __ge__(self, right):	# self >= right
    return (self > right) or (self == right)


#===============================================================================
# Class CRevision
#   Class is needed to compare file revisions.
#===============================================================================
class CRevision:
  #-----------------------------------------------------------------------------
  # Init class:
  #   Convert revision string to list.
  #
  # Parameter:
  #   RevisionString [in] Revision as string
  #-----------------------------------------------------------------------------
  def __init__(self, RevisionString):
    # Convert revision string to a integer list
    self.mRevision = RevisionString.split('.')
    i = 0
    while i < len(self.mRevision):
      self.mRevision[i] = int(self.mRevision[i])
      i += 1

  #-----------------------------------------------------------------------------
  # __str__:
  #   Print revision string
  #
  # Parameter:
  #   - none -
  #
  # Return value:
  #   String
  #-----------------------------------------------------------------------------
  def __str__(self):
    if len(self.mRevision):
      VersionString = str(self.mRevision[0])

      i = 1
      while i < len(self.mRevision):
        VersionString += "." + str(self.mRevision[i])
        i += 1

      return VersionString
    else:
      return "-"

  #-----------------------------------------------------------------------------
  # Compare operators
  #   Operators == != < > <= >=
  #   Used to sort the change list by location
  #
  # Parameter:
  #   right [in] Second compare obejct (type CRevision)
  #
  # Return Value:
  #   True  -> Compare is true
  #   False -> Conpare is false
  #-----------------------------------------------------------------------------
  def __eq__(self, right):	# self == right
    return self.Compare(right) == 0
  def __ne__(self, right):	# self != right
    return self.Compare(right) <> 0
  def __lt__(self, right):	# self < right
    return self.Compare(right) < 0
  def __gt__(self, right):	# self > right
    return self.Compare(right) > 0
  def __le__(self, right):	# self <= right
    return self.Compare(right) <= 0
  def __ge__(self, right):	# self >= right
    return self.Compare(right) >= 0

  def Compare(self, right):
    # Compare revision number for revision namer
    i = 0
    while (i < len(self.mRevision)) and (i < len(right.mRevision)):
      # Return for the first number which is different
      if self.mRevision[i] < right.mRevision[i]:
        return -1
      if self.mRevision[i] > right.mRevision[i]:
        return +1
      i += 1

    # All numbers are identic: Check if one file is branechd and the othe rnot
    if len(self.mRevision) < len(right.mRevision):
      return -1   
    if len(self.mRevision) > len(right.mRevision):
      return +1

    # Return 0 if the files are completely identic
    return 0

  #-----------------------------------------------------------------------------
  # CompareParent
  #   Checks if the reveision of the other file is done in the same branch or not.
  #
  # Parameter:
  #   right [in] Second compare obejct (type CRevision)
  #
  # Return Value:
  #   True  -> Root of both revisions is identic
  #   False -> Root of both revisions is different
  #-----------------------------------------------------------------------------
  def CompareParent(self, right):
    # Compare revision number for revision namer
    i = 0
    while (i < (len(self.mRevision)-1)) and (i < (len(right.mRevision)-1)):
      # Return for the first number which is different
      if self.mRevision[i] <> right.mRevision[i]:
        return False
      i += 1

    return True

#===============================================================================
# main function
#   Imports one change package
#
# Parameter:
# - Change package ID
#===============================================================================
if __name__ == "__main__":
  if len(sys.argv) <> 2:
    print "Error: python ChangePackage.py needs the change package ID as parameter!"
    print "       Example: ChangePackage.py 123456:1"
    sys.exit(1) 

  else:
    ChangeDict = {}
    print "Change package %s" % (sys.argv[1],)
    ImportChangePackage(sys.argv[1], ChangeDict)

    # Convert change dictionary to a sorted list
    ChangeList = []
    for Member in ChangeDict:
      ChangeList.append(ChangeDict[Member])
    ChangeList.sort()

    for Change in ChangeList:
      print Change  