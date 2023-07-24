#! /usr/bin/python
#coding: utf-8

#===============================================================================
# IssuesIntegrated.py
#   Should be used to check which Issues are integrated into a release.
#   The input parameter is the release checkpoint and a list of Issues to check.
#   The script generates a report, where all changes for the issues is checked.
#===============================================================================

import mks         # Provides MKS access function
import sys         # Access to command line parameters
import os          # Access to windows environment variables
import Checkpoint  # Provides a class to import check points
from   IntegrityItem            import *  # Used to import a release item
from   IntegrityItem_Issue      import *  # Provides a class to import integrity items
import IssuesIntegrated_Report  as report # Provieds a class to generate the html report
from IssuesIntegrated_Parameter import *  # Script parameters

#-------------------------------------------------------------------------------
# GetEnvironmentVariable
#   Access to windows environment variables with excpetion handler.
#
# Parameter:
#   VarName [in] Name of the environment variable
#
# Return Value:
#   String -> Value of the envirnoment variable
#   None   -> Envirnoment variable not found or empty
#-------------------------------------------------------------------------------
def GetEnvironmentVariable(VarName):
  try:
    Value = os.environ[VarName]
    Value = Value.strip()
    if len(Value):
      return Value
    else:
      return None
  except KeyError as err:
    return None


#-------------------------------------------------------------------------------
# ImportIssue
#   Used to import one issue with all releated ROs and change packages.
#   Issue collection:
#     C
#   The issue will be add to the IssueList.
#   
#   For every issue will be one CIssue created and add to a list and to dicitionary (IssueId is the dict key).
#   If an issue ID is requested a second time, the item will only add to list.
#
# Parameter:
#   IssueID         [in]     Issue ID (example: "123546")
#   IssueCollection [in/out] Dictionary of CIssue items (key = Issue ID)
#                            -> To have a list of all issues (every issues ID only one time).
#                            -> To find double request (one issue can be founde by different filters)
#   IssueList       [in/out] List of CIssue items (the item can be several times in the list).
#                            -> To have a list of all issues which match one filter (CIssue items can be referenced in several lists).
#-------------------------------------------------------------------------------
def ImportIssue(IssueID, IssueCollection, IssueList):
  # Issue already in list
  if IssueCollection.has_key(IssueID):
    IssueList.append(IssueCollection[IssueID])

  # Import issue
  else:
    Issue = CIssue(IssueID)
    IssueList.append(Issue)
    IssueCollection.update({IssueID: Issue})
  

#===============================================================================
# main function
#   Checks all Issues with Integration flag if they are integrated into a checkpoint.
#===============================================================================
if __name__ == "__main__":

  #===== Get parameter =====
  Parameter_Project = GetEnvironmentVariable("INTEGRATED_PROJECT")

  Parameter_Revision = GetEnvironmentVariable("INTEGRATED_CHECKPOINT")
  Parameter_DevPath  = GetEnvironmentVariable("INTEGRATED_DEV_PATH")

  Parameter_ReleaseItem = GetEnvironmentVariable("INTEGRATED_RELEASE_ITEM_ID")
  Parameter_Issues      = GetEnvironmentVariable("INTEGRATED_ISSUES")
  Parameter_QueryName   = GetEnvironmentVariable("INTEGRATED_QUERY")
  Parameter_ProjectName = GetEnvironmentVariable("INTEGRATED_PROJECT_NAME")

  Parameter_TimeoutCheckpointImport = GetEnvironmentVariable("TIMEOUT_CHECKPOINT_IMPORT")

  #===== Check parameter =====
  ParameterMissing = False

  # html report
  if len(sys.argv) <> 2:
    ParameterMissing = True
    print "Error: Filename html report not set!"
  else:
    FilenameReport   = sys.argv[1]

  # MKS project
  if Parameter_Project == None:
    ParameterMissing = True
    print "Error: MKS project not set!"

  # Project revision or development path
  if (Parameter_Revision == None) and (Parameter_DevPath == None):
    ParameterMissing = True
    print "Error: MKS project revision or development path not set!"

  if (Parameter_Revision <> None) and (Parameter_DevPath <> None):
    ParameterMissing = True
    print "Error: MKS project revision and development path set! Only one must be set"

  if Parameter_Revision <> None:
    DevPathFlag = False
  else:
    DevPathFlag = True
    Parameter_Revision = Parameter_DevPath

  # Issue filter
  if (Parameter_ReleaseItem == None) and (Parameter_Issues == None) and (Parameter_QueryName == None) and (Parameter_ProjectName == None):
    ParameterMissing = True
    print "Error: No filter set to find Issues"

  if Parameter_TimeoutCheckpointImport <> None:
    try:
      TIMEOUT_CHECKPOINT_IMPORT = int(Parameter_TimeoutCheckpointImport)
    except:
      pass

  # Final error 
  if ParameterMissing:
    print ""
    print "Please set following environment variables: "
    print "- INTEGRATED_PROJECT"
    print "  (example: set INTEGRATED_PROJECT=/ADAS/SW/Projects/SRR52x/SRR520/M11_APPL/04_Engineering)"
    print "- INTEGRATED_CHECKPOINT or INTEGRATED_DEV_PATH:"
    print "  (example 1: set INTEGRATED_CHECKPOINT=1.2.1.3)"
    print "  (example 2: set INTEGRATED_DEV_PATH=SW_SRR520_01.01)"
    print "- INTEGRATED_RELEASE_ITEM_ID (optional): Release item ID"
    print "  (example: set INTEGRATED_RELEASE_ITEM_ID=123456)"
    print "- INTEGRATED_ISSUES (optional): List of issue IDs"
    print "  (example: set INTEGRATED_ISSUES=100200 100201 100202)"
    print "- INTEGRATED_QUERY (optional): Name of a stores integrety query"
    print "  (example: set INTEGRATED_QUERY=AL__OpenIssues)"
    print "- INTEGRATED_PROJECT (optional): Search for issue in state accepted with ADAS state ""to be Integrated"""
    print "  (example: set INTEGRATED_PROJECT=""SMR420"")"
    print "Call script with html report file as parameter"
    print "  (example: python %s report.html)" % (sys.argv[0],)
    sys.exit(1)

  print "==============================================================================="
  print " Check if Issues are completely integrated into a checkpoint"
  print " Parameter:"
  print " - Checkpoint:        %s: %s" % (Parameter_Revision, Parameter_Project)
  print " - Release item ID:   %s" % (Parameter_ReleaseItem,)
  print " - Project name:      %s" % (Parameter_ProjectName,)
  print " - Query name:        %s" % (Parameter_QueryName,)
  print " - Additional Issues: %s" % (Parameter_Issues,)
  print "==============================================================================="

  IssueList_ReleaseItem     = []
  IssueList_IntegrationFlag = []
  IssueList_Query           = []
  IssueList_AdditioanIssues = []
  IssueCollection = {}

  #===== Get Issues from release item =====
  if Parameter_ReleaseItem:
    print
    print "Search planned issues for release item %s" % (Parameter_ReleaseItem,)

    ReleaseItem = CItem(Parameter_ReleaseItem, "Release")
    for IssueID in ReleaseItem.mItemData["Planned Requests"].split(', '):
      ImportIssue(IssueID, IssueCollection, IssueList_ReleaseItem)

  #===== Get Issues from query =====
  if Parameter_QueryName:
    # Search issues with integration flag
    print
    print "Search for issues in query '%s'" % (Parameter_QueryName,)
    MksResponse = mks.run("im issues --batch --query=%s --fields=ID" % (Parameter_QueryName,), TIMEOUT_SEARCH_ISSUES)

    if MksResponse:
      # Import Issues with integration flag
      for IssueID in MksResponse.split("\n"):
        if len(IssueID):
          ImportIssue(IssueID, IssueCollection, IssueList_Query)

  #===== Additional Issues =====
  if Parameter_Issues:
    print
    print "Import additional Issues:"

    for IssueID in Parameter_Issues.split():
      ImportIssue(IssueID, IssueCollection, IssueList_AdditioanIssues)

  #===== Issues with intergation flag =====
  if Parameter_ProjectName:
    # Search issues with integration flag
    print
    print "Search issues in state 'to be integrated'"
    MksResponse = mks.run("im issues --batch --queryDefinition='((field[\"State\"] = \"Accepted\") and (field[\"Type\"] = \"Issue\") and (field[\"ADAS Sub State\"] = \"to be Integrated\") and (field[\"Project\"] = \"/%s\"))' --fields=ID" % (Parameter_ProjectName,), TIMEOUT_SEARCH_ISSUES)

    if MksResponse:
      # Import Issues with integration flag
      for IssueID in MksResponse.split("\n"):
        if len(IssueID):
          ImportIssue(IssueID, IssueCollection, IssueList_IntegrationFlag)

  #===== Import checkpoint =====
  print
  MemberList = Checkpoint.ImportCheckpointMemers(Parameter_Project, Parameter_Revision, TIMEOUT_CHECKPOINT_IMPORT, DevPathFlag)
  if MemberList:

    #===== Check integration state =====
    # Sort Issue collection by ID
    IssueList = []
    for IssueID in IssueCollection:
      IssueList.append(IssueCollection[IssueID])
    IssueList.sort()

    # Check the Issue integration status 
    print "Check integration state"
    for Issue in IssueList:
      Issue.CheckIntegrationStatus(MemberList)

    #===== Generate html report =====
    print
    print "Generate html report file (%s)" % (FilenameReport,)
    HtmlReport = report.CReport(FilenameReport, Parameter_Project, Parameter_Revision)

    # Generate a short list off requested issues
    if Parameter_ReleaseItem:
      HtmlReport.AddShortIssueList(IssueList_ReleaseItem, 'Issues planned to release item %s' % (Parameter_ReleaseItem,))

    if Parameter_Issues:
      HtmlReport.AddShortIssueList(IssueList_AdditioanIssues, 'Free issue list')

    if Parameter_QueryName:
      HtmlReport.AddShortIssueList(IssueList_Query, 'Issues of query "%s"' % (Parameter_QueryName,))

    if Parameter_ProjectName:
      HtmlReport.AddShortIssueList(IssueList_IntegrationFlag, 'Accepted issues in state "to be integrated" of project %s' % (Parameter_ProjectName,))

    # Generte a detailed report for all Issues
    HtmlReport.AddIssueList(IssueList)

  # No checkpoint found
  else:
    sys.exit(1)
