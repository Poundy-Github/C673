#! /usr/bin/python
#coding: utf-8

#===============================================================================
# IntegrityItem_Issue.py
#   Used to import all changes related to one Issue.
#   Therefore the issue, the related ROs and all relates change packages are
#   imported from MKS.
#   Provides funcitons to check if the changes for the Issue are in a release
#   integrated.
#===============================================================================

from   IntegrityItem import *  # Provides a class to import integrity items
import ChangePackage           # Provides a class to import change packages
import Checkpoint              # The class CMember is

# Constants
STATE_CHANGES_NOT_INTEGRATED = 1
STATE_CHANGES_INTEGRATED     = 2
STATE_CHANGES_NO_CHANGES     = 3

#===============================================================================
# Class CIssue
#===============================================================================
class CIssue (CItem):

  #-----------------------------------------------------------------------------
  # Init class:
  #   Import Issue and all related Realization Orders
  #
  # Parameter:
  #   IssueID [in] Issue ID
  #-----------------------------------------------------------------------------
  def __init__(self, IssueID):
    # Import Issue
    print "- Import Issue %s" % (IssueID,)
    CItem.__init__(self, IssueID, "Issue")

    self.mOrderList  = []  # List of realization order items related to this issue
    self.mChangeList = {}  # List of changes done for this issue
    self.mFileList   = []  # List of changed files in the project

    self.mStateChanges = STATE_CHANGES_NO_CHANGES
    self.mIntegratedCnt    = 0
    self.mNotIntegratedCnt = 0
    self.mNotFoundCnt      = 0

    DoublicateOrderList = {}

    # Import Realization Orders
    for RO_ID in self.mItemData["Orders"].split(","):
      RO_ID = RO_ID.strip()
      if len(RO_ID):
        DoublicateOrderList.update({RO_ID: RO_ID})
        Order = CRealizationOrder(RO_ID, self.mChangeList)
        self.mOrderList.append(Order)

    # Import related Orders
    for RO_ID in self.mItemData["is related to"].split(","):
      RO_ID = RO_ID.strip()
      if (len(RO_ID) > 0) and (not DoublicateOrderList.has_key(RO_ID)):
        Order = CRealizationOrder(RO_ID, self.mChangeList)
        self.mOrderList.append(Order)

  #-----------------------------------------------------------------------------
  # CheckIntegrationStatus:
  #   Compares the list of changes for this issue with the revisions in the release.
  #
  # Parameter
  #   CheckpointMemberList [in] List of CMember objects (contains the revisions in the checkpoint)
  #-----------------------------------------------------------------------------
  def CheckIntegrationStatus(self, CheckpointMemberList):
    # Scan all members of the project
    for Member in CheckpointMemberList:

      # Check if the member has been changed by this issue
      if self.mChangeList.has_key(Member.mMemberArchive):
        Change = self.mChangeList[Member.mMemberArchive]

        # Add a copy of the member to a list        
        MemberCopy = Checkpoint.CMember(Member.mFile, Member.mRevision, Member.mMemberArchive)
        self.mFileList.append(MemberCopy)

        # Compare checkpoint revision with change package revision
        ReleaseRevision = ChangePackage.CRevision(MemberCopy.mRevision)
        if Change.CheckIntegrationStatus(ReleaseRevision):
          self.mIntegratedCnt += 1
        else:
          self.mNotIntegratedCnt += 1

        # Copy change status to member
        MemberCopy.mIntegrationStatus = Change.mIntegrationStatus
        MemberCopy.mPlannedRevision = Change.mRevision
        MemberCopy.mChangePackageID = Change.mChangePackageID

    # Count number of not found changes
    self.mNotFoundCnt = 0
    for ChangeName in self.mChangeList:
      Change = self.mChangeList[ChangeName]
      if Change.mIntegrationStatus == "NOT INTEGRATED":
        self.mNotFoundCnt += 1

#===============================================================================
# Class CRealizationOrder
#===============================================================================
class CRealizationOrder (CItem):

  #-----------------------------------------------------------------------------
  # Init class:
  #   Import Realization Order and all related change packages
  #
  # Parameter:
  #   RealizationOrderID [in]     Relization Order ID
  #   ChangeDict         [in/out] Dictionary of CChange objects
  #-----------------------------------------------------------------------------
  def __init__(self, RealizationOrderID, ChangeDict):
    # Import Issue
    print "  - Import RO %s" % (RealizationOrderID,)
    CItem.__init__(self, RealizationOrderID, "Realization Order")

    # Get the change package IDs which are related to this Realization Order
    ChangePackageList = ChangePackage.GetChangePackageList(self.mItemData["ID"])

    # Import change packages
    for ChangePackgeID in ChangePackageList:
      print "    - Import CP %s" % (ChangePackgeID,)
      ChangePackage.ImportChangePackage(ChangePackgeID, ChangeDict)

#===============================================================================
# main function
#   Imports one Issue item
#
# Parameter:
# - Item ID
#===============================================================================
if __name__ == "__main__":
  if len(sys.argv) <> 2:
    print "Error: IntegrityItem.py needs the item ID as parameter!"
    print "       Example: IntegrityItem.py 123456"
    sys.exit(1) 

  else:
    Issue = CIssue(sys.argv[1])
    print Issue