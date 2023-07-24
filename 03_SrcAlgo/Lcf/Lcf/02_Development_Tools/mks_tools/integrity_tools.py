"""
MKS Scripting tool for integrity

Features:
---------

"""
import os
import sys
import xml.dom.minidom
from datetime import datetime, date, time, timedelta
from optparse import OptionParser

from mks_config_tools import mks_obj,xml_obj
from lotus_notes_tools.send_email import lotus_notes_send_email_obj
from mks_utils import ProgressBar_obj


class CreateIssuesForAllComps_obj(mks_obj,xml_obj,lotus_notes_send_email_obj):
    OWNER          = "Owner"
    STRUCT_ELEMENT = "StrElement"
    MKS_USER       = "MksName"
    COMP_TAG       = "$COMP_NAME$"
    
    DEMO_COMP_CONFIG = """
<?xml version="1.0" encoding="UTF-8"?>
   <?xml-stylesheet type="text/xsl" href="Config.xslt"?>
   <ConfigComponents>
      <Aldw    Owner="Alexander Kaps"      MksName = "kapsa"           StrElement = "/SMFC4B0 System/ALGO/ALDW - /SMFC4B0"/>
      <Cb      Owner="Laure Bajard"        MksName = "uidt3229"        StrElement = "/SMFC4B0 System/ALGO/CB - /SMFC4B0" />
      <EbaSen  Owner="Andreas Hartmann"    MksName = "tfetc2"          StrElement = "/SMFC4B0 System/ALGO/EBA - /SMFC4B0" />
      <EbaVeh  Owner="Andreas Hartmann"    MksName = "tfetc2"          StrElement = "/SMFC4B0 System/ALGO/EBA - /SMFC4B0" />
      <Ecm     Owner="Arnaud Faure"        MksName = "uidv0442"        StrElement = "/SMFC4B0 System/ALGO/ECM - /SMFC4B0" />
      <Em      Owner="Markus Friebertshaeuser" MksName = "uidt0551"    StrElement = "/SMFC4B0 System/ALGO/SOD - /SMFC4B0" />
      <Fex     Owner="Robert Thiel"        MksName = "thielr"          StrElement = "/SMFC4B0 System/ALGO/FEX - /SMFC4B0" />
      <Fsd     Owner="Alexander Bachmann"  MksName = "uidt5584"        StrElement = "/SMFC4B0 System/ALGO/FSD - /SMFC4B0" />
      <Ftrc    Owner="Markus Friebertshaeuser" MksName = "uidt0551"    StrElement = "/SMFC4B0 System/ALGO/FTRC - /SMFC4B0" />
      <Gen     Owner="Markus Friebertshaeuser" MksName = "uidt0551"    StrElement = "/SMFC4B0 System/ALGO/GEN - /SMFC4B0" />
      <Hla     Owner="Tobias Schwarz"      MksName = "uidw4444"        StrElement = "/SMFC4B0 System/ALGO/HLA - /SMFC4B0" />
      <Ld      Owner="Alexander Kaps"      MksName = "kapsa"           StrElement = "/SMFC4B0 System/ALGO/LD - /SMFC4B0" />
      <Memo    Owner="Bertrand Godreau"    MksName = "uid28828"        StrElement = "/SMFC4B0 System/ALGO/SEMO - /SMFC4B0" />
      <Pc      Owner="Alexander Bachmann"  MksName = "uidt5584"        StrElement = "/SMFC4B0 System/ALGO/SOD - /SMFC4B0" />
      <Ped     Owner="Robert Thiel"        MksName = "thielr"          StrElement = "/SMFC4B0 System/ALGO/PED - /SMFC4B0" />
      <Pv      Owner="Alexander Kaps"      MksName = "kapsa"           StrElement = "/SMFC4B0 System/ALGO/PV - /SMFC4B0" />
      <Sac     Owner="Nicolaj Stache"      MksName = "uidt6711"        StrElement = "/SMFC4B0 System/ALGO/SAC - /SMFC4B0" />
      <Scb     Owner="Laure Bajard"        MksName = "uidt3229"        StrElement = "/SMFC4B0 System/ALGO/CB - /SMFC4B0" />
      <Semo    Owner="Bertrand Godreau"    MksName = "uid28828"        StrElement = "/SMFC4B0 System/ALGO/SEMO - /SMFC4B0" />
      <Sib     Owner="Alexander Bachmann"  MksName = "uidt5584"        StrElement = "/SMFC4B0 System/ALGO/SOD - /SMFC4B0" />
      <Sr      Owner="Steen Kristensen"    MksName = "kristensens"     StrElement = "/SMFC4B0 System/ALGO/SR - /SMFC4B0"  />
      <Tsa     Owner="Steen Kristensen"    MksName = "kristensens"     StrElement = "/SMFC4B0 System/ALGO/SR - /SMFC4B0"  />
      <Vcl     Owner="Stefan Munder"       MksName = "uidk7697"        StrElement = "/SMFC4B0 System/ALGO/VCL - /SMFC4B0"  />
      <Vdy     Owner="Frank Wolter"        MksName = "wolterf"         StrElement = "/SMFC4B0 System/ALGO/VDY - /SMFC4B0"  />
   </ConfigComponents>
"""
    
    DEMO_ISSUE_CONFIG = """
<?xml version="1.0" encoding="UTF-8"?>
   <?xml-stylesheet type="text/xsl" href="Config.xslt"?>
   <IssueConfig>
     <IssueSummary>(Arch#6) Algo $COMP_NAME$ must implement reset/init concept for sim regarding concept</IssueSummary>
     <IssueProject ProjectName="/SMFC4B0"/>
     <IssueDescription>Algo $COMP_NAME$ must implement reset/init concept for sim regarding concept. 
    Documentation could be found in doors 
     </IssueDescription>
     <IssueUrgency>High</IssueUrgency>
     <IssueImportance>High</IssueImportance>
     <IssueAnalyseData>19.9.2013</IssueAnalyseData>
     <IssuePlannedTargetRelease>KaFAS3 BMW I320 - PreRelease 2 (Start of System Test), Planned ; Nov 5, 2013</IssuePlannedTargetRelease>
     <IssueCCBComment>Needed for I320 Pre 1</IssueCCBComment>
   </IssueConfig>
"""
    
    """
    Description: Create Issues for all algo components
    """
    def __init__(self):
        mks_obj.__init__(self)
        xml_obj.__init__(self)
        lotus_notes_send_email_obj.__init__(self)
        self.ReleaseID = ""
        
        self.Logging = False
        self.LogDir  =""
    
    def PharseConfigFiles(self):
        """
        PharseConfigFiles(self,argu)

        Description: Pharse the input xml files and put it to class members

        Parameter:    retruns false in case of error
        """
        
        #read issue config xml file
        if (os.path.isfile(self.IssueConfigFileName) == 1):
            #load an existing project cfg file    
            self.IssueCfgs = self.get_a_document(self.IssueConfigFileName)
            
            IssueSummary = self.IssueCfgs.getElementsByTagName("IssueSummary")
            if IssueSummary.length > 0:
                self.IssueSummary = IssueSummary.item(0).childNodes.item(0).data
                #print self.IssueSummary
            else:
                self.Logging("Error","Could not read Issue summary from issue config")
                return False
            
            try:
                self.ProjectName = self.IssueCfgs.getElementsByTagName("IssueProject").item(0).getAttribute("ProjectName")
            except:
                self.Logging("Error","Could not read Issue project from issue config")
                return False
            
            IssueDescription = self.IssueCfgs.getElementsByTagName("IssueDescription")
            if IssueDescription.length > 0:
                self.IssueDescription = IssueDescription.item(0).childNodes.item(0).data
                #print self.IssueDescription
            else:
                self.Logging("Error","Could not read Issue description from issue config")
                return False
            
            IssueImportance = self.IssueCfgs.getElementsByTagName("IssueImportance")
            if IssueImportance.length > 0:
                self.IssueImportance = IssueImportance.item(0).childNodes.item(0).data
                #print self.IssueImportance
            else:
                self.Logging("Error","Could not read Issue importance form issue config")
                return False
            
            IssueUrgency = self.IssueCfgs.getElementsByTagName("IssueUrgency")
            if IssueUrgency.length > 0:
                self.IssueUrgency = IssueUrgency.item(0).childNodes.item(0).data
                #print self.IssueUrgency
            else:
                self.Logging("Info","Could not read Issue urgence form issue config")
                self.IssueUrgency = None
            
            IssueAnalyseData = self.IssueCfgs.getElementsByTagName("IssueAnalyseData")
            if IssueAnalyseData.length > 0:
                self.IssueAnalyseData = IssueAnalyseData.item(0).childNodes.item(0).data
                self.IssueAnalyseData = datetime.strptime(self.IssueAnalyseData, "%d.%m.%Y").date().strftime("%b %d, %Y")
                #print self.IssueAnalyseData
            else:
                self.Logging("Info","Could not read Issue analyse date form issue config")
                self.IssueAnalyseData = None
            
            IssuePlannedTargetRelease = self.IssueCfgs.getElementsByTagName("IssuePlannedTargetRelease")
            if IssuePlannedTargetRelease.length > 0:
                self.IssuePlannedTargetRelease = IssuePlannedTargetRelease.item(0).childNodes.item(0).data
                #print self.IssuePlannedTargetRelease
            else:
                self.Logging("Info","Could not read Issue Planned target release form issue config")
                self.IssuePlannedTargetRelease = None
            
            IssueCCBComment = self.IssueCfgs.getElementsByTagName("IssueCCBComment")
            if IssueCCBComment.length > 0:
                self.IssueCCBComment = IssueCCBComment.item(0).childNodes.item(0).data
                #print self.IssueCCBComment
            else:
                self.Logging("Info","Could not read Issue ccb comment form issue config")
                self.IssueCCBComment = None
        
        #read component config xml file
        if (os.path.isfile(self.ComponentConfigFileName) == 1):
            #load an existing project cfg file    
            self.ComponentCfgs = self.get_a_document(self.ComponentConfigFileName)
            
            Components = self.ComponentCfgs.getElementsByTagName("ConfigComponents")
            self.CompDict = {}
            if Components.length > 0:
                for Comp in Components.item(0).childNodes:
                    if (Comp.nodeType == Comp.ELEMENT_NODE):
                        if Comp.nodeName not in self.CompDict:
                            self.CompDict[Comp.nodeName] = {}
#                        names = Comp.getAttribute("MKS_USER").split(' ')
#                        self.CompDict[Comp.nodeName][self.OWNER] = "%s %s"%(names[1],names[0])
                        self.CompDict[Comp.nodeName][self.OWNER]          = Comp.getAttribute(self.MKS_USER)
                        self.CompDict[Comp.nodeName][self.STRUCT_ELEMENT] = Comp.getAttribute(self.STRUCT_ELEMENT)
                        
            else:
                self.Logging("Error","could not read component config")
                return False
        
        return True
    
    def SetIssueToAnalyzed(self, issue_id, StructureElement):
        """
        SetIssueToAnalyzed(self,argu)

        Description: Set the issue to analyzed

        Parameter:   issue_id: the issue id
        """
        #prepare updated fieldes:
        update_fields = {}
        update_fields[self.ISSUE_FIELD_STATE.strip(':')] = "Analyzed"
        
        if self.IssueImportance != None:
            update_fields[self.ISSUE_FIELD_IMPORTANCE.strip(':')] = self.IssueImportance
        else:
            self.Logging("Error","Issue Importance not defined in issue xml")
            return False
        
        if self.IssueUrgency != None:
            update_fields[self.ISSUE_FIELD_URGENCY.strip(':')] = self.IssueUrgency
        else:
            self.Logging("Error","Issue Urgency not defined in issue xml")
            return False
        
        if self.IssueAnalyseData != None:
            update_fields[self.ISSUE_FIELD_ANALYSIS_DATE.strip(':')] = self.IssueAnalyseData
        else:
            self.Logging("Error","Issue Analyse date not defined in issue xml")
            return False
        
        if StructureElement != None:
            update_fields[self.ISSUE_FIELD_STRUCT_ELEMENT.strip(':')] = StructureElement
        else:
            self.Logging("Error","Structure element not defined in component config xml")
            return False
        
        # update the issue
        ret_issue = self.UpdateIssue( issue_id, update_fields )
        if ret_issue != None and len(ret_issue) > 0:
            return True
        else:
            return False
    
    def SetIssueToAcceped(self, issue_id):
        """
        SetIssueToAcceped(self,argu)

        Description: Set the issue to accepted

        Parameter:   issue_id: the issue id
        """
        #prepare updated fieldes:
        update_fields = {}
        update_fields[self.ISSUE_FIELD_STATE.strip(':')] = "Accepted"
        
        if self.IssuePlannedTargetRelease != None:
            update_fields[self.ISSUE_FIELD_PLANNED_TARGET_RELEASE.strip(':')] = self.IssuePlannedTargetRelease
        else:
            self.Logging("Error","Issue Panned target release not defined in issue xml")
            return False
        
        if self.IssueCCBComment != None:
            update_fields[self.ISSUE_FIELD_CCB_COMMENT.strip(':')] = self.IssueCCBComment
        else:
            self.Logging("Error","Issue CCB comment not defined in issue xml")
            return False
        
        # update the issue
        ret_issue = self.UpdateIssue( issue_id, update_fields )
        if ret_issue != None and len(ret_issue) > 0:
            return True
        else:
            return False

    def PrepareIssueTest(self, component_name):
        """
        PrepareIssueTest(self,argu)

        Description: Prepares the issue component text, replace the special component tag by the given comp name

        Parameter:   component_name: the name that is used when replacing the tag
        """
        
        return (self.IssueSummary.replace(self.COMP_TAG, component_name),self.IssueDescription.replace(self.COMP_TAG, component_name))

    def CreateAlgoIssues(self):
        """
        CreateAlgoIssues(self,argu)

        Description: Creates the issues for all components given in the xml

        """
        
        #loop over all components
        for Comp in self.CompDict:
            #prepare the text
            Summary,Description = self.PrepareIssueTest(Comp)
            #print Summary
            #print Description
            #call the mks command
            issue_id = self.AddIssue(Summary, self.ProjectName, "Change Request", Description )
            print self.ChangeIssueUser(self.CompDict[Comp][self.OWNER],issue_id)
            
            if self.IssueState == "analyzed":
                self.SetIssueToAnalyzed(issue_id, self.CompDict[Comp][self.STRUCT_ELEMENT])
            elif self.IssueState == "accepted":
                success = self.SetIssueToAnalyzed(issue_id, self.CompDict[Comp][self.STRUCT_ELEMENT])
                if success == True:
                    self.SetIssueToAcceped(issue_id)
                else:
                    self.Logging("Error", "Could not switch issue %s to accepted"%(issue_id))
            else:
                pass
        
    def CreateIssuesForAllComps(self,argu):
        """
        CreateIssuesForAllComps(self,argu)

        Description: Create Issues for all Algo components defined in config file

        Parameter:    -argu the command line options and arguments
        """

        usage = """usage : %s CreateIssuesForAllComps [options]
Example: python %s CreateIssuesForAllComps -H mks-psad -P 7002 -c config.xml -l -o c:\temp

component config file:
%s

issue config file:

%s
"""%(os.path.basename(__file__), os.path.basename(__file__), self.DEMO_COMP_CONFIG, self.DEMO_ISSUE_CONFIG)
        
        #parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                  help="e.g. liss014.auto.contiwan.com (mandatory)", metavar="liss014.auto.contiwan.com")
        parser.add_option("-P", "--Portconfig", dest="Port",
                  help=" e.g. 6001 (mandatory)", metavar="6001")
        parser.add_option("-R", "--Release", dest="ReleaseID",
                  help="Source issue id e.g. 23456")
        parser.add_option("-c", "--config", dest="ComponentConfigFileName",
                  help="component configuration file name (mandatory)", metavar="FILE")
        parser.add_option("-i", "--issue", dest="IssueConfigFileName",
                  help="issue configuration file name (mandatory)", metavar="FILE")
        parser.add_option("-s", "--issue_state", dest="issue_state", default = "New",
                  help="issue state could be new/cassified/analyzed/accepted", metavar="FILE")
        parser.add_option("-m", "--mail", dest="Mail",action="store_true", default = True,
                  help="Sending notification emalis (on/off)")
        parser.add_option("-l", "--log", dest="Logging",action="store_true", default = False,
                  help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                  help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port

        self.Logging = options.Logging
        self.LogDir  = options.LogDir

        self.ComponentConfigFileName = options.ComponentConfigFileName
        self.IssueConfigFileName     = options.IssueConfigFileName
        
        self.IssueState              = options.issue_state
        
        # check output log directory
        if ((os.path.isdir(self.LogDir) == 0) and (self.Logging == True)):
            print "Error: log directory does not exist e.g. -oc:\temp"
            sys.exit()
        else:
            logTypes = {}
            logTypes["Info"]=1
#            logTypes["Warn"]=2
#            logTypes["Debug"]=3
            if self.Logging == True:
                self.SetupLogging("%s\logging.txt"%(self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt"%(self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error","setup host e.g. -Hliss014.auto.contiwan.com")
            sys.exit()
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error","setup host e.g. -P6001")
            sys.exit()
            
            
        if ((self.ComponentConfigFileName == "") or (self.ComponentConfigFileName == None)):
            self.Log("Error","Component config file not defined ")
        
        if ((self.IssueConfigFileName == "") or (self.IssueConfigFileName == None)):
            self.Log("Error","Issue config file not defined ")
        
        #testing code for future skripting
        #print self.GetFieldOfIssue("188652", self.ISSUE_FIELD_URGENCY)
        
        # get configuration
        if self.PharseConfigFiles():
            self.CreateAlgoIssues()
        else:
            self.Log("Error", "Config pharsing error")
        
        self.Log("Info", "Algo issue creation successful finished")
    
class GetAllOpenTasks_obj(mks_obj,xml_obj,lotus_notes_send_email_obj):
    """
    Description: Get all open tasks
    """
    def __init__(self):
        mks_obj.__init__(self)
        xml_obj.__init__(self)
        lotus_notes_send_email_obj.__init__(self)
        self.ReleaseID = ""

        self.Logging = False
        self.LogDir  =""

        self.SetProjectsEMailCfg = 0
        self._UserEmailDict = {}
        
        self._ConfigFileName =""

        self._EMailTextTemplate ="""Automatic generated Task close notification:

Please close your Task(s) with following id(s):%s

Here the links to the task(s):
%s

Thanks!"""

        self._IMLinkTemplate = "http://mks-psad:7002/im/issues?selection=%s"
        
    def CheckSetEmailProjectCfg(self, IsProjectsCfgEmpty, ProjectUserIssues):
        """
        CheckSetEmailProjectCfg(self, IsProjectsCfgEmpty)

        Description: Checks if for all Email adresses exits in the xml fiel
                     if not or the config does not exist(empty) add a default config 
                     for the missing project people email adresses

        Parameter:  -IsProjectsCfgEmpty if the config file does not exist set it to 1 and it is created
                    -ProjectUserIssues: User that have an open issue
        
        return true if differences found between the project members and the users configured in the email config file
        """
        diff_found = False
        self._UserEmailDict = {}
        #if the SetProjectCfg xml file exists
        UserEMailConfig = 0
        if (IsProjectsCfgEmpty == 0) :
            #build a dictionary of all actual project inside of the sep project xml file
            UserEMailConfig_e = self.SetProjectsEMailCfg.getElementsByTagName("UserEmailConfig")
            if (UserEMailConfig_e.length >= 1):
                UserEMailConfig = UserEMailConfig_e.item(0)
                UserEMailConfig.normalize( )
                for SharedProject in UserEMailConfig.childNodes:
                    if (SharedProject.nodeType == SharedProject.ELEMENT_NODE):            
#                        print SharedProject.getAttribute("UserName")
                        self._UserEmailDict[SharedProject.getAttribute("UserName")] = SharedProject.getAttribute("EmailAdress")
        
            else:
                #if the file exists but there is no UserEmailConfig node
                UserEMailConfig = self.SetProjectsEMailCfg.createElement("UserEmailConfig")
                self.SetProjectsEMailCfg.appendChild(UserEMailConfig)
        else:
            #if the fiel does not exists
            UserEMailConfig = self.SetProjectsEMailCfg.createElement("UserEmailConfig")
            self.SetProjectsEMailCfg.appendChild(UserEMailConfig)
#            print self.SetProjectsCfg.toxml()
        
        #compare actual subprojects with the config file subprojects
        for ActUser in ProjectUserIssues:
            if not ActUser in self._UserEmailDict:
                diff_found = True
                elem     = self.SetProjectsEMailCfg.createElement("ProjectUserEMailConfig")
                elem.setAttribute("UserName",ActUser)
                Name = ActUser.split(" ")
                elem.setAttribute("EmailAdress","%s.%s@continental-corporation.com"%(Name[1],Name[0]))
                UserEMailConfig.appendChild(elem)
                self.Log("Info", "Added user %s to Project Email config file, his email adress is only a suggestion"%(ActUser))
    
#        print SetProjectsCfg.toprettyxml( )
        return diff_found 

    def ReadEmailText(self):
        """
        ReadEmailText(self)

        Description: Read the email text from the xml file 

        return 0 if the email text was not found if the file exist a template text was generated
        """
        ret_value = 0
        #check if the email text node exists if not create on and add a template text
        EMailText = self.SetProjectsEMailCfg.getElementsByTagName("EMailText")
        if (EMailText.length >= 1):
            ret_value = EMailText.item(0).childNodes.item(0).data
#            for SubWorkflowTexte in EMailText:
#                if (SubWorkflowTexte.nodeType == SubWorkflowTexte.ELEMENT_NODE):
#                    if SubWorkflowTexte.childNodes.length > 0:
#                        print  SubWorkflowTexte.childNodes.item(0).data
#
#            ret_value = EMailText.item(0)
        else:
            UserEMailConfig = self.SetProjectsEMailCfg.getElementsByTagName("UserEmailConfig")
            #if the file exists but there is no EMailText node
            EMailTextElem = self.SetProjectsEMailCfg.createElement("EMailText")
            EMailText = self.SetProjectsEMailCfg.createTextNode(self._EMailTextTemplate)
            EMailTextElem.appendChild(EMailText)
            UserEMailConfig.item(0).appendChild(EMailTextElem)
            self.Log("Info", "Set Email Template text to xml file")
        return ret_value
    
    def ReadAndUpdateProjectUserEmail(self, ProjectUserIssues):
        """
        ReadAndUpdateProjectUserEmail(self)

        Description: Read and update the Project Users/members email adresse 
        
        Parameter:  -ProjectUserIssues: the User that have an open issue

        return 0 if the email configuration is updated otherwise return the configuration xml sturct
        """
        IsProjectsCfgEmpty = 1
        
        #read set config xml file
        if (os.path.isfile(self._ConfigFileName) == 1):
            #load an existing project cfg file    
            self.SetProjectsEMailCfg = self.get_a_document(self._ConfigFileName)
            IsProjectsCfgEmpty = 0
        else:
            #create a new project cfg document
            self.SetProjectsEMailCfg = self.create_a_document()
#            self.SetProjectsEMailCfg.appendChild(self.SetProjectsEMailCfg.createProcessingInstruction("xml-stylesheet","type=\"text/xsl\" href=\"Config.xslt\""))
            IsProjectsCfgEmpty = 1;
            
        #check the Set Project Cfg if all shared projects are in the config and add it if not
        checkMail = self.CheckSetEmailProjectCfg( IsProjectsCfgEmpty, ProjectUserIssues)
        checkMailText = self.ReadEmailText()
        if ( (checkMail == True ) or (checkMailText == 0))  :
            self.Log("Info","Diff found please setup your config file %s"%(self._ConfigFileName))
            file_object = open(self._ConfigFileName, "w")
            # get the modified xml file string
            XMLstr = self.SetProjectsEMailCfg.toxml()
            # replace all new lines and all three blanks
            doreplace = True
            forcereplace = False
            XMLstr1 = ""
            XMLstr = XMLstr.replace('   ','')
            
            #find end block of email text
            end = XMLstr.find("</EMailText>")
            #seardch around the end block for cr
            x = XMLstr[end-4:end+4].find("\n")
            if x != -1:
                #if found romove this cr
                XMLstr = ("%s%s")%(XMLstr[:end-1], XMLstr[end:])

#            print XMLstr
            for l in XMLstr.splitlines():
                # find start and end tag for the email text
                start = l.find("<EMailText>")
                end   = l.find("</EMailText>")
                if start != -1:
                    #in case of first tag in lane force replacement of cr at this line
                    if start == 0:
                        forcereplace = True
                    doreplace = False
                if end != -1:
                    doreplace = True
#                print l
                if ((doreplace == True) or (forcereplace == True)):
                    XMLstr1 = "%s%s"%(XMLstr1,l.replace('\n',''))
                    forcereplace = False
                else:
                    XMLstr1 = "%s%s\n"%(XMLstr1,l)

            SetProjectsCfgNew = xml.dom.minidom.parseString(XMLstr1.replace('   ',''))
            #write the new cfg xml file     
            SetProjectsCfgNew.writexml(file_object, "   ", "   ", "\n", "UTF-8")
            
            file_object.close()
            return 0
        else:
            # overwrite the template email text with the text form the xml file
            self._EMailTextTemplate = checkMailText
            # if the config is ok
            return 1

    def GetRelatedIssuesOfRelease(self):
        """
        GetRelatedIssuesOfRelease(self)

        Description: Get all the related issues of the selected release 

        return empty dict if no open issues found otherwise return the open issues
        """
        #return all open issues
        OpenIssues = {}

        #setup the not wanted issue states
        dict = {"AD_released":1} #,"AD_test":1
        #get related issues
        self.Log("Info", "Get all related issues of release %s"%(self.ReleaseID))
        related_issues = self.GetRelationListForIssue(self.ReleaseID,"AD_Release",dict)
        start = 0
        prog = ProgressBar_obj(0, len(related_issues), 60, mode='fixed')
        oldprog = str(prog)
        for issue in related_issues:
            dict = {"AD_completed":1,"AD_rejected":2,"AD_submit":3} #,"AD_test":1

            Task_issues = self.GetRelationListForIssue(issue,"AD_FR",dict)
            if Task_issues == 0:
                Task_issues = self.GetRelationListForIssue(issue,"AD_CR",dict)

            if (Task_issues == 0) or (len(Task_issues) == 0):
                self.Log("Info", "No open Task(s) found for issue %s"%(issue))
            else:
                if issue not in OpenIssues:
                    OpenIssues[issue] = {}
                for Task in Task_issues:
                    OpenIssues[issue][Task] = Task

            prog.update_amount(start)
            if oldprog != str(prog):
                print prog, "\r",
                sys.stdout.flush()
                oldprog=str(prog)
            start = start + 1

        return OpenIssues

    def GetOpenTasks(self,OpenIssues):
        """
        GetOpenTasks(self,OpenIssues)

        Description: Get all open tasks of related issues from the selected release 
                     Print the open task of users to the log file

        Parameter:  -OpenIssues: dictionary of all open issues

        return empty dict if no open issues found otherwise return a dict with people and open tasks
        """
#        print OpenIssues
        self.Log("Info", "Get all open tasks of related issues from release %s"%(self.ReleaseID))
        ProjectUserIssues = {}
        dict = {"AD_completed":1,"AD_rejected":2}
        start = 0
        prog = ProgressBar_obj(0, len(OpenIssues), 60, mode='fixed')
        oldprog = str(prog)
        for issue in OpenIssues:
            for task in OpenIssues[issue]:
                AssignedUser = self.GetFieldOfIssue(task,"Assigned User: ")
                TaskState = self.GetFieldOfIssue(task,"State: ")
                if (TaskState != 0) and (TaskState not in dict):
                    if AssignedUser not in ProjectUserIssues:
                        ProjectUserIssues[AssignedUser] = []
                    #add task to people issue list
                    if task not in ProjectUserIssues[AssignedUser]:
                        ProjectUserIssues[AssignedUser].append(task)
                
#                print task
            prog.update_amount(start)
            if oldprog != str(prog):
                print prog, "\r",
                sys.stdout.flush()
                oldprog=str(prog)
            start = start + 1

        # write user open task list to logging file
        for User in ProjectUserIssues:
            tasklist = ""
            for task in ProjectUserIssues[User]:
                if len(tasklist) == 0:
                    tasklist = " %s"%(task)
                else:
                    tasklist = " %s,%s"%( task,tasklist)
            self.Log("Info", "%s has following open tasks %s"%(User,tasklist))
        
        return ProjectUserIssues

    def CheckMailConfigAndSendOpenTasksMail(self,ProjectUserIssues):
        """
        CheckMailConfigAndSendOpenTasksMail(self,ProjectUserIssues)

        Description: Check the email config and send then the open tasks to the users 

        Parameter:  -ProjectUserIssues: Open task dictionary with users

        return False if the configuration was updated and has to be reviewed
        """

#        ProjectUserIssues = {'Spruck Jochen (spruckj) (spruckj)': ['65274'], 'Ungvary Gergely (ungvaryg) (ungvaryg)': ['63605'], 'Bitter Torsten (bittert) (bittert)': ['64522', '64495'], 'Konarski Witek (uidt8403) (uidt8403)': ['65330'], 'Easa Martin (uid02498) (uid02498)': ['64506'], 'Rus Artur (uidl6720) (uidl6720)': ['64821'], 'Raedler Guenther (uidt9430) (uidt9430)': ['62825'], 'Codruta Pumnea (pumneac)': ['62016', '62017', '62014', '62015'], 'Zunker Uwe-Juergen (zunkeru) (zunkeru)': ['63689'], 'Canisag Tiberiu (uidt2445) (uidt2445)': ['66621'], 'Mueller Stefan (uidk7634) (uidk7634)': ['65748', '64334', '62835'], 'Petzold Thomas (petzoldt) (petzoldt)': ['64817'], 'Kaps Alexander (kapsa) (kapsa)': ['66662'], 'Dintzer Philippe (dintzerp) (dintzerp)': ['62091', '62092']}

        ret_value = False
        self.Log("Info", "Check Email configuration")
        if (self.ReadAndUpdateProjectUserEmail(ProjectUserIssues) == 0):
            self.Log("Info","Some project members/users are not configured, mails are not send")
            ret_value = False
        else:
            self.Log("Info", "Send Notifaction Mails")
            for User in ProjectUserIssues:
                if User not in self._UserEmailDict:
                    self.Log("Error", "User email not set")
                else:
                    mkslinks =""
                    tasklist = ""
                    for task in ProjectUserIssues[User]:
                        mkslinks = "%s%s\n"%(mkslinks, (self._IMLinkTemplate)%(task) )
                        if len(tasklist) == 0:
                            tasklist = " %s"%(task)
                        else:
                            tasklist = " %s,%s"%( task,tasklist)
#                        print task
#                    print mkslinks
                    FormatedMailText = (self._EMailTextTemplate)%(tasklist,mkslinks)
                    self.sendEmail(recipients=self._UserEmailDict[User],subject='Please close Task(s) with ID(s):%s'%(tasklist), body=FormatedMailText)
            ret_value = True
            
        return ret_value

    def GetAllOpenTasks(self,argu):
        """
        GetAllOpenTasks(self,argu)

        Description: the GetAllOpenTasks main function

        Parameter:    -argu the command line options and arguments
        """

        usage = """usage : %prog GetAllOpenTasks [options]
Example: python %prog MergeReleaseIssues -H liss014.auto.contiwan.com -P 6001 -R 12345 -l -o c:\temp"""
        
        #parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                  help="e.g. liss014.auto.contiwan.com (mandatory)", metavar="liss014.auto.contiwan.com")
        parser.add_option("-P", "--Portconfig", dest="Port",
                  help=" e.g. 6001 (mandatory)", metavar="6001")
        parser.add_option("-R", "--Release", dest="ReleaseID",
                  help="Source issue id e.g. 23456")
        parser.add_option("-c", "--config", dest="ConfigFileName",
                  help="configuration file name (mandatory)", metavar="FILE")
        parser.add_option("-m", "--mail", dest="Mail",action="store_true", default = True,
                  help="Sending notification emalis (on/off)")
        parser.add_option("-l", "--log", dest="Logging",action="store_true", default = False,
                  help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                  help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port

        self.ReleaseID = options.ReleaseID

        self.Logging = options.Logging
        self.LogDir  = options.LogDir

        self._ConfigFileName = options.ConfigFileName

        # check output log directory
        if ((os.path.isdir(self.LogDir) == 0) and (self.Logging == True)):
            print "Error: log directory does not exist e.g. -oc:\temp"
            sys.exit()
        else:
            logTypes = {}
            logTypes["Info"]=1
#            logTypes["Warn"]=2
#            logTypes["Debug"]=3
            if self.Logging == True:
                self.SetupLogging("%s\logging.txt"%(self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt"%(self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error","setup host e.g. -Hliss014.auto.contiwan.com")
            sys.exit()
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error","setup host e.g. -P6001")
            sys.exit()
            

        if ((self._ConfigFileName == "") or (self._ConfigFileName == None)):
            self.Log("Error","Config file not defined ( use default file name and location c:\project_mailconfig.xml )")
            self._ConfigFileName = "c:\project_mailconfig.xml"

        # check release id and if not specified promt for it
        if ((self.ReleaseID == "") or (self.ReleaseID == None)):
            self.Log("Info","No release ID given by command line parameter e.g. -R 23345 please enter it now:")
            ReleaseID = raw_input("Your release ID:")
            if (ReleaseID == ""):
                self.Log("Error","No issue id -> exit")
                sys.exit()
            else:
                self.ReleaseID = ReleaseID
        
        OpenIssues = self.GetRelatedIssuesOfRelease()
        
        if len(OpenIssues) > 0:
            ProjectUserIssues = self.GetOpenTasks(OpenIssues)
            if len(ProjectUserIssues) > 0:
                if options.Mail == True:
                    self.CheckMailConfigAndSendOpenTasksMail(ProjectUserIssues)
                else:
                    self.Log("Info", "Notifaction Mail sending diabled")
            else:
                self.Log("Info", "No open Tasks found for release %s"%(self.ReleaseID))
        else:
            self.Log("Info", "No open issues (FR/CR) found for release %s"%(self.ReleaseID))
        self.Log("Info", "Check successful finished")


class MergeReleaseIssues_obj(mks_obj):
    """
    Description: Merge Issues from one release to another
    """
    def __init__(self):
        mks_obj.__init__(self)
        
        self.SourceIssueID = ""
        self.TargetIssueID = ""

        self.Logging = False
        self.LogDir  =""
        
    def MergeReleaseIssues(self,argu):
        """
        MergeReleaseIssues(self,argu)

        Description: the MergeReleaseIssues main function

        Parameter:    -argu the command line options and arguments
        """

        usage = """usage : %prog MergeReleaseIssues [options]
Example: python %prog MergeReleaseIssues -H liss014.auto.contiwan.com -P 6001 -S 23456 -T 12345 -l -o c:\temp"""
        
        #parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                  help="e.g. liss014.auto.contiwan.com (mandatory)", metavar="liss014.auto.contiwan.com")
        parser.add_option("-P", "--Portconfig", dest="Port",
                  help=" e.g. 6001 (mandatory)", metavar="6001")
        parser.add_option("-S", "--Source", dest="SourceIssueID",
                  help="Source issue id e.g. 23456")
        parser.add_option("-T", "--Target", dest="TargetIssueID",
                  help="Target issue id e.g. 12345")
        parser.add_option("-l", "--log", dest="Logging",action="store_true", default = False,
                  help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir",
                  help="logging outputfolder")

        (options, args) = parser.parse_args(argu)

        # setup the local members to the arguments
        self.Host = options.Host
        self.Port = options.Port

        self.SourceIssueID = options.SourceIssueID
        self.TargetIssueID = options.TargetIssueID

        self.Logging = options.Logging
        self.LogDir  = options.LogDir


        # check output log directory
        if ((os.path.isdir(self.LogDir) == 0) and (self.Logging == True)):
            print "Error: log directory does not exist e.g. -oc:\temp"
            sys.exit()
        else:
            logTypes = {}
            logTypes["Info"]=1
#            logTypes["Warn"]=2
#            logTypes["Debug"]=3
            if self.Logging == True:
                self.SetupLogging("%s\logging.txt"%(self.LogDir), "file", logTypes)
            else:
                self.SetupLogging("%s\logging.txt"%(self.LogDir), "console", logTypes)
        # check host
        if ((self.Host == "") or (self.Host == None)):
            self.Log("Error","setup host e.g. -Hliss014.auto.contiwan.com")
            sys.exit()
        # check port
        if ((self.Port == "") or (self.Port == None)):
            self.Log("Error","setup host e.g. -P6001")
            sys.exit()
        
        # check source issue id and if not specified promt for it
        if ((self.SourceIssueID == "") or (self.SourceIssueID == None)):
            self.Log("Info","No source issue ID given by command line parameter e.g. -S 12334 please enter it now:")
            SourceIssueID = raw_input("Your source issue ID:")
            if (SourceIssueID == ""):
                self.Log("Error","No issue id -> exit")
                sys.exit()
            else:
                self.SourceIssueID = SourceIssueID

        # check target issue id and if not specified promt for it
        if ((self.TargetIssueID == "") or (self.TargetIssueID == None)):
            self.Log("Info","No target issue ID given by command line parameter e.g. -S 23345 please enter it now:")
            TargetIssueID = raw_input("Your target issue ID:")
            if (TargetIssueID == ""):
                self.Log("Error","No issue id -> exit")
                sys.exit()
            else:
                self.TargetIssueID = TargetIssueID
            
        #setup the not wanted issue states
        dict = {"AD_released":1} #,"AD_test":1

        #get the target issue state
        TargetIssueState = self.CheckStateOfIssue(self.TargetIssueID,"AD_Release",dict)
        
        if TargetIssueState == 1:
            #get related issues
            related_issues = self.GetRelationListForIssue(self.SourceIssueID,"AD_Release",dict)
            existing_related_issues = self.GetRelationListForIssue(self.TargetIssueID,"AD_Release",dict)
            
            summary = {"added":{},"failed":{},"existing":{}}       
            for issue in related_issues:
                #only if issue does not exitst in the target issue add it as relation
                if issue not in existing_related_issues:
                    if self.UpdatedRelationOfIssue(self.TargetIssueID, "AD_c.o. CR(s) / FR(s) / SR(s)", issue):
                        summary["added"][issue] = issue
                    else:
                        summary["failed"][issue] = issue
                else:
                    summary["existing"][issue] = issue
                    
            
            self.Log("Info", "<---- Summary --->")

            # check if some issues are added and display it
            if len(summary["added"]) != 0:
                self.Log("Info", "To issues %s are the following issues added %s"%(self.TargetIssueID, sorted(summary["added"])))
            
            # check if some issues could not be added and display it               
            if len(summary["failed"]) != 0:
                self.Log("Info", "not added %s"%(sorted(summary["failed"])) )
                
            # check if some issues are already existing in the target issue and display it               
            if len(summary["existing"]) != 0:
                self.Log("Info", "The following issues already exists %s"%(sorted(summary["existing"])) )
                
        else:
            self.Log("Error", "Issues could not be added to that issue because of wrong issue state")
        
        self.Log("Info", "Merge release issues successful finished")            

def PrintHelp():
    """
    PrintHelp()

    Description: Print the Help menu 
    """
    print """Usage: 
python integrity_tools.py MergeReleaseIssues [options e.g. -h for help]
python integrity_tools.py GetAllOpenTasks [options e.g. -h for help]
"""

def main(argv):
    """
    main()

    Description: the main function 
    """

    #demo / test mks interfaces
#    mks = mks_obj()
#    mks.Setup("liss014.auto.contiwan.com","6001","33263:2","project","c:\\temp\\logging.txt",logTypes,"file")
#    print mks.GetRevisionForLabel("/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/00_Custom/vdy/project.pj", "AL_VDY_TRUNK_03.00.00_preInt")
#    print mks.GetLabelForRevision("","/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/00_Custom/vdy/project.pj", "","1.4.1.2")
#    mks.SetProjectType("sandbox")
#    print mks.GetLabelForRevision("","","D:\\SWProjects\\ARS301_BASE\\06_Algorithm\\04_Engineering\\01_Source_Code\\algo\\vdy\\project.pj", "1.4.1.4")
#    print mks.CheckDevPathName("/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/00_Custom/vdy/project.pj", "AL_VDY_SMR200_03.00.00")
    
    #check for script
    if (argv[1] == "MergeReleaseIssues"):
        if len(argv) < 3:
            argv.append("-h")
        MergeReleaseIssues_obj().MergeReleaseIssues(argv)
        sys.exit()
    elif (argv[1] == "GetAllOpenTasks"):
        if len(argv) < 3:
            argv.append("-h")
        GetAllOpenTasks_obj().GetAllOpenTasks(argv)
        sys.exit()
    elif (argv[1] == "CreateIssuesForAllComps"):
        if len(argv) < 3:
            argv.append("-h")
        CreateIssuesForAllComps_obj().CreateIssuesForAllComps(argv)
        sys.exit()
        
    else:
        PrintHelp() 
    
# check input args
if (len(sys.argv) > 1):
    main(sys.argv)
else:
    PrintHelp()


"""
CHANGE LOG:
-----------
$Log: integrity_tools.py  $
Revision 1.1 2021/12/13 18:20:42CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/mks_tools/project.pj
Revision 1.7 2017/04/25 18:18:21CEST uidg4889 
Merging from GIT 2017/1.027
Revision 1.6 2013/09/23 14:35:59CEST spruckj 
Extend the issue creation skripting, now also the issues could be switched to analyzed or accepted
- Added comments -  spruckj [Sep 23, 2013 2:36:00 PM CEST]
Change Package : 196584:1 http://mks-psad:7002/im/viewissue?selection=196584
Revision 1.5 2013/09/05 16:43:19CEST Paulig, Ralf (uidt3509) 
small fixes
--- Added comments ---  uidt3509 [Sep 5, 2013 4:43:20 PM CEST]
Change Package : 175257:12 http://mks-psad:7002/im/viewissue?selection=175257
Revision 1.4 2013/09/05 13:40:08CEST Spruck, Jochen (spruckj) 
Add skripting to create issues for multiple components
--- Added comments ---  spruckj [Sep 5, 2013 1:40:08 PM CEST]
Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
Revision 1.3 2012/02/09 13:05:41CET Spruck, Jochen (spruckj) 
Add new mks si / im script to if all tasks with working packages are assigned to releases
Revision 1.2 2011/06/14 11:44:58CEST Spruck Jochen (spruckj) (spruckj) 
Bug fix email text from xml file
Revision 1.1 2011/05/11 09:06:03CEST Spruck Jochen (spruckj) (spruckj) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/CMD_Tools/mks_tools/project.pj
"""
