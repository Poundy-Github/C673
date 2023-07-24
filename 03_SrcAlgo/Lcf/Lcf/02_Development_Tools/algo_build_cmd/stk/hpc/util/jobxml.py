"""
stk/hpc/jobxml
--------------

XML-Interface for collecting the whole JobInformation during submit.
This JobInfo will be saved as xml file, and used for the hpc submit to reduce
server communication time.


:org:           Continental AG
:author:        Robert Hecker

:creation date: 28.06.2013

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:43CET $
"""
# Import Python Modules -------------------------------------------------------
from xml.dom.minidom import Document

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------

class Job(object):
    def __init__(self):

        self.Name = None
        self.IsExclusive = None
        self.RunUntilCanceled = None
        self.UnitType = None
        self.UserName = None
        self.Project = None
        self.JobTemplate = None
        self.Priority = None
        self.AutoCalcMax = None
        self.AutoCalcMin = None
        self.FailOnTask = None
        self.MinNodes = None
        self.MaxNodes = None

    def appendAttributes(self, xml):

        if(self.Name):
            xml.setAttribute("Name", self.Name)

        if(self.IsExclusive):
            xml.setAttribute("IsExclusive", self.IsExclusive)

        if(self.RunUntilCanceled):
            xml.setAttribute("RunUntilCanceled", self.RunUntilCanceled)

        if(self.UnitType):
            xml.setAttribute("UnitType", self.UnitType)

        if(self.UserName):
            xml.setAttribute("UserName", self.UserName)

        if(self.Project):
            xml.setAttribute("Project", self.Project)

        if(self.JobTemplate):
            xml.setAttribute("JobTemplate", self.JobTemplate)

        if(self.Priority):
            xml.setAttribute("Priority", self.Priority)

        if(self.AutoCalcMax):
            xml.setAttribute("AutoCalcMax", self.AutoCalcMax)

        if(self.AutoCalcMin):
            xml.setAttribute("AutoCalcMin", self.AutoCalcMin)

        if(self.FailOnTask):
            xml.setAttribute("FailOnTask", self.FailOnTask)

        if(self.MinNodes):
            xml.setAttribute("MinNodes", self.MinNodes)

        if(self.MaxNodes):
            xml.setAttribute("MaxNodes", self.MaxNodes)


class Task(object):
    def __init__(self):

        self.CommandLine = None
        self.DependsOn = None
        self.EndValue = None
        self.IncrementValue = None
        self.IsExclusive = None
        self.IsParametric = None
        self.IsRerunnable = None
        self.MaxCores = None
        self.MaxNodes = None
        self.MaxSockets = None
        self.MinCores = None
        self.MinNodes = None
        self.MinSockets = None
        self.Name = None
        self.RequiredNodes = None
        self.RuntimeSeconds = None
        self.StartValue = None
        self.StdErrFilePath = None
        self.StdInFilePath = None
        self.StdOutFilePath = None
        self.WorkDirectory = None

    def appendAttributes(self, xml):

        if(self.CommandLine):
            xml.setAttribute("CommandLine", self.CommandLine)

        if(self.DependsOn):
            dependsOnString = ""
            init = False

            for item in self.DependsOn:
                if(init):
                    dependsOnString += ','
                dependsOnString += item
                init = True

            xml.setAttribute("DependsOn", dependsOnString)

        if(self.EndValue):
            xml.setAttribute("EndValue", self.EndValue)

        if(self.IncrementValue):
            xml.setAttribute("IncrementValue", self.IncrementValue)

        if(self.IsExclusive):
            xml.setAttribute("IsExclusive", self.IsExclusive)

        if(self.IsParametric):
            xml.setAttribute("IsParametric", self.IsParametric)

        if(self.IsRerunnable):
            xml.setAttribute("IsRerunnable", self.IsRerunnable)

        if(self.MaxCores):
            xml.setAttribute("MaxCores", str(self.MaxCores))

        if(self.MaxNodes):
            xml.setAttribute("MaxNodes", str(self.MaxNodes))

        if(self.MaxSockets):
            xml.setAttribute("MaxSockets", str(self.MaxSockets))

        if(self.MinCores):
            xml.setAttribute("MinCores", str(self.MinCores))

        if(self.MinNodes):
            xml.setAttribute("MinNodes", str(self.MinNodes))

        if(self.MinSockets):
            xml.setAttribute("MinSockets", str(self.MinSockets))

        if(self.Name):
            xml.setAttribute("Name", self.Name)

        if(self.RequiredNodes):
            xml.setAttribute("RequiredNodes", self.RequiredNodes)

        if(self.RuntimeSeconds):
            xml.setAttribute("RuntimeSeconds", self.RuntimeSeconds)

        if(self.StartValue):
            xml.setAttribute("StartValue", self.StartValue)

        if(self.StdErrFilePath):
            xml.setAttribute("StdErrFilePath", self.StdErrFilePath)

        if(self.StdInFilePath):
            xml.setAttribute("StdInFilePath", self.StdInFilePath)

        if(self.StdOutFilePath):
            xml.setAttribute("StdOutFilePath", self.StdOutFilePath)

        if(self.WorkDirectory):
            xml.setAttribute("WorkDirectory", self.WorkDirectory)

    def createElement(self, doc):

        task = doc.createElement("Task")
        self.appendAttributes(task)

        return task


class HpcXml(object):
    def __init__(self):
        self.doc = None
        self.root = None
        self.tasks = None

    def createJob(self, job):
        # Erzeugen eines leeren minidom-Documentes
        self.doc = Document()

        # Erzeugen des <address-book>-root-Elementes
        self.root = self.doc.createElement("Job")
        job.appendAttributes(self.root)
        self.doc.appendChild(self.root)

        self.__CreateTasks()

    def __CreateTasks(self):

        self.tasks = self.doc.createElement("Tasks")
        self.root.appendChild(self.tasks)

    def AppendTask(self, task):

        el = task.createElement(self.doc)
        self.tasks.appendChild(el)

    def getXml(self):
        return self.doc.toprettyxml(indent="   ", encoding="utf-8")

"""
CHANGE LOG:
-----------
$Log: jobxml.py  $
Revision 1.1 2021/12/13 17:57:43CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/util/project.pj
Revision 1.2 2013/07/02 16:43:40CEST Hecker, Robert (heckerr) 
Changed Format of DependsOnString to get Feature working.
- Added comments -  heckerr [Jul 2, 2013 4:43:41 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/07/01 08:50:54CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
