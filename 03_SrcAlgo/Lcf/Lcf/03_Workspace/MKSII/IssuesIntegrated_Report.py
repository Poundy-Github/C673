#! /usr/bin/python
#coding: utf-8

from IntegrityItem_Issue import *  # Classes CIssue and CRealizationOrder hast to add to the report

#===============================================================================
# IssuesIntegrated_Report.py
#   Used to generate a hteml report for script IssuesIntegrated.
#===============================================================================

class CReport:
  #-----------------------------------------------------------------------------
  # Init class:
  #   open html report for write.
  #   Write html report header.
  #
  # Parameter:
  #   FileName        [in] html report file which should be generated
  #   MksProject      [in] MKS Project which was checked
  #   ProjectRevision [in] checkpoint number of the MKS project
  #-----------------------------------------------------------------------------
  def __init__(self, FileName, MksProject, ProjectRevision):
    self.File = None

    # Open file
    try:
      self.File = open(FileName, "w")

    # File open failed
    except:
      self.File = None
      print "Error: Open file %s failed!" % (FileName,)
      sys.exit(1)

    # Write report header
    self.File.write('<html>\n')
    self.File.write('  <head><title>Issue Integration Check</title></head>\n')
    self.File.write('  <body>\n')
    self.File.write('    <H2>Checkpoint</H2>\n')
    self.File.write('      <p><b>Project:</b> %s<br/>\n' % (MksProject,))
    self.File.write('         <b>Revision:</b> %s</p>\n' % (ProjectRevision,))
    self.File.write('    <H2>Issues</H2>\n')

  #-----------------------------------------------------------------------------
  # AddShortIssueList
  #   Writes a list of issues with the integration state into the report
  #   This is only a short overview. A more detailed list will be generated in function AddIssueList
  #
  # Parameter:
  #   IssueList [in] List of CIssue items (see IntegrityItem_Issue.py)
  #   ListName  [in] Headline for the list
  #-----------------------------------------------------------------------------
  def AddShortIssueList(self, IssueList, ListName):
    self.File.write('      <p>%s:</p>\n' % (ListName,))
    if len(IssueList):
      self.File.write('      <table border>\n')
      self.File.write('        <tr> <th>ID</th> <th>State</th> <th>RO states</th> <th>Changes Integrated</th> <th>Issue Summary</th> </tr>\n')
      for Issue in IssueList:
        self.AddIssue(Issue)
      self.File.write('      </table>\n')

  # Subfcuntion of AddShortIssueList
  def AddIssue(self, Issue):
    # Write issue ID
    IssueID      = Issue.mItemData["ID"]
    self.File.write('        <tr> <td><a href="#Issue%s">%s</a></td> ' % (IssueID, IssueID))

    # Write Issue state
    IssueState = Issue.mItemData["State"]
    if (IssueState == "Closed") or (IssueState == "Approved") or (IssueState == "Realized") or (IssueState == "Accepted"):
      self.File.write('<td>%s</td>' % (IssueState))
    else:
      # Wrong Issue state: Color red
      self.File.write('<td><font color=rgb(255,0,0)>%s</font></td>' % (IssueState,))

    # Count open and closed orders
    if len(Issue.mOrderList):
      OrdersInWork = 0
      OrdersDone = 0
      for Order in Issue.mOrderList:
        OrderState = Order.mItemData["State"]
        if OrderState <> "Canceled":
          if (OrderState <> "Closed") and (OrderState <> "Realized"):
            OrdersInWork += 1
          else:
            OrdersDone += 1

      if OrdersInWork:
        self.File.write('<td><font color=rgb(255,0,0)>%d open ROs</font><br/>%d finished ROs</td>' % (OrdersInWork, OrdersDone))
      else:
        self.File.write('<td>%d finished ROs</td>' % (OrdersDone,))
    else:
      self.File.write('<td><font color=rgb(255,0,0)>No Relization Orders!</font></td>')

    # Write changes overall state
    if (Issue.mNotIntegratedCnt + Issue.mIntegratedCnt) == 0:
      if Issue.mNotFoundCnt > 0:
        self.File.write('<td><font color=rgb(255,0,0)>No changes integrated!</font></td>')
      else:
        self.File.write('<td><font color=rgb(255,0,0)>Issue has no changes!</font></td>')
    elif Issue.mNotIntegratedCnt == 0:
      if Issue.mNotFoundCnt > 0:
        self.File.write('<td>%d changes integrated<br/>%d changes not found</td>' % (Issue.mIntegratedCnt, Issue.mNotFoundCnt))
      else:
        self.File.write('<td>%d changes integrated</td>' % (Issue.mIntegratedCnt,))
    else:
      self.File.write('<td><font color=rgb(255,0,0)>%d changes not integrated</font></td>' % (Issue.mNotIntegratedCnt,))

    # Write Isse summary
    self.File.write('<td>%s</td> </tr>\n' % (Issue.mItemData["Summary"],))

  #-----------------------------------------------------------------------------
  # AddIssueList
  #   Generates issue list of CIssue items to the report:
  #   - Issue ID, name, State
  #   - Realization Orders ID, name, State
  #   - File table
  #
  # Parameter:
  #   IssueList [in] List of CIssue items (see IntegrityItem_Issue.py)
  #-----------------------------------------------------------------------------
  def AddIssueList(self, IssueList):
    self.File.write('\n    <H1>Results</H1>\n')

    # Add next Issue
    for Issue in IssueList:
      #===== Print headline: Issue =====

      # Get Issue data
      IssueID      = Issue.mItemData["ID"]
      IssueSummary = Issue.mItemData["Summary"]
      IssueState   = Issue.mItemData["State"]

      # Check Issue state
      if (IssueState == "Closed") or (IssueState == "Approved") or (IssueState == "Realized") or (IssueState == "Accepted"):
        IssueColor = "rgb(0,200,0)" # green
      elif IssueState == "Canceled":
        IssueColor = "rgb(240,170,0)" # yellow
      else:
        IssueColor = "rgb(255,0,0)"   # red

      # Write headline
      self.File.write('      <H3><a name="Issue%s"/><a href="integrity://ims-adas:7002/im/viewissue?selection=%s">Issue %s:</a> %s (<font color=%s>%s</font>)</H3>\n' % (IssueID, IssueID, IssueID, IssueSummary, IssueColor, IssueState))

      #===== Print RO list =====
      if len (Issue.mOrderList):

        # Walk through RO list
        self.File.write('        <p>\n')
        for Order in Issue.mOrderList:

          # Get RO data
          OrderID      = Order.mItemData["ID"]
          OrderSummary = Order.mItemData["Summary"]
          OrderState   = Order.mItemData["State"]

          # Check RO state
          if (OrderState == "Closed") or (OrderState == "Realized"):
            OrderColor = "rgb(0,200,0)" # green
          elif OrderState == "Canceled":
            OrderColor = "rgb(240,170,0)" # yellow
          else:
            OrderColor = "rgb(255,0,0)"   # red

          # Print RO
          self.File.write('          <a href="integrity://ims-adas:7002/im/viewissue?selection=%s">RO %s:</a> %s (<font color=%s>%s</font>)<br/>\n' % (OrderID, OrderID, OrderSummary, OrderColor, OrderState))
        self.File.write('        </p>\n')

      # Issue has no ROs
      else:
        self.File.write('        <p>No Realization Orders</p\n>')

      #===== Print change table =====
      # Print table headline
      self.File.write('        <table border>\n')
      self.File.write  ('          <tr> <th>Status</th> <th>Integrated<br/>Revision</th> <th>Issue<br/>Revision</th> <th>Change<br>Package</th> <th>File</th> </tr>\n')

      # Walk through member list
      for Member in Issue.mFileList:
        # Get member integration state
        if Member.mIntegrationStatus == "INTEGRATED":
          ChangeColor = "rgb(204,255,204)" # green
        elif Member.mIntegrationStatus ==  "BRANCH INTEGRATED":
          ChangeColor = "rgb(230,204,102)" # orange
        elif Member.mIntegrationStatus == "NOT INTEGRATED":
          ChangeColor = "rgb(255,204,204)" # red
        else:
          ChangeColor = "rgb(255,255,180)" # yellow

        # Print member
        self.File.write('          <tr bgcolor=%s> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> </tr>\n' % (ChangeColor, Member.mIntegrationStatus, Member.mRevision, Member.mPlannedRevision, Member.mChangePackageID, Member.mFile))

      # Generate sorted list of changes
      ChangeList = []
      for Change in Issue.mChangeList:
        ChangeList.append(Issue.mChangeList[Change])
      ChangeList.sort()

      # Print all not found changes
      for Change in ChangeList:
        if Change.mIntegrationStatus == "NOT FOUND":
          ChangeColor = "rgb(255,255,180)" # yellow
          self.File.write('          <tr bgcolor=%s> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> </tr>\n' % (ChangeColor, Change.mIntegrationStatus, Change.mReleaseRevision, Change.mRevision, Change.mChangePackageID, Change.mMember))

      # end table
      self.File.write('        </table>\n')

  #-----------------------------------------------------------------------------
  # Delete class:
  #   Write html report footer
  #-----------------------------------------------------------------------------
  def __del__(self):
    if self.File <> None:
      self.File.write('  </body>\n')
      self.File.write('</html>')