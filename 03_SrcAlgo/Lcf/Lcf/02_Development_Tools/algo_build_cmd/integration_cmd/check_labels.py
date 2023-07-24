"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:42CET $

----------------------------------------------------"""
import os,  stat
import shlex, subprocess
import sys, getopt
import logging
import glob
from os.path import basename , dirname
#import CppHeaderParser
import shutil
import datetime
import configparser
import xml.etree.ElementTree as ET
import copy
import collections
import info
import common
from common import Email_Address, kprint , fprint
import timeit
tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
import mks_utils
from mks_utils import ProgressBar_obj

EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
global fo 
AUTO_CP = "STD_ON"
if AUTO_CP == "STD_ON":
    ChangePackage = info.MyInfo.cp
    
SCAN_FILES = "STD_OFF"

Stand_Alone="STD_OFF"
Module_Name="Check-Labels"
Module_Description="Verify the received labels  ."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"
    
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD)     
start_time = None
logName=""
EndingErrMeg = []
EndingErrLevel = 0 
MainFile="shared_project_config_files.xml"
files = ["shared_project_config_master.xml", "shared_project_config_interface.xml", "shared_project_config_rte.xml"]
CompsSubProjects = {}
CompsLabels = {}
CompsDevpaths = {}
CompsDevpathsSimple = {}
CompsSubProjectslist = []
Comps = []
CompsToExclude=["mts_proj_mo", "SIM_CSFHelper", "FPGA_MFC400FieldProgGateArray","loc_metrics", "RFE_RecFileExtractor", "source_monitor", "SW_ti_Tools"]
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
if SCAN_FILES == "STD_ON":
    LstDirFolder = [\
    "./05_Testing/05_Test_Environment/algo/modtests/qac_tests/common",\
    "./05_Testing/05_Test_Environment/algo/modtests/qacpp_tests/common",\
    "../02_System/05_Tools/mts_system/mts_system_2.5",\
    "../02_System/05_Tools/mts_system/mts_system_2.6",\
    "../02_System/05_Tools/mts_system/appl_2.5",\
    "../02_System/05_Tools/mts_system/appl_2.6",\
    ]
    LstFolderList = [\
    "./04_Engineering/00_CodeGen/algo",\
    "./04_Engineering/01_Source_Code/algo",\
    "./04_Engineering/01_Source_Code/algo/00_Custom",\
    "./04_Engineering/01_Source_Code/algo/00_Custom/sw_support",\
    "./04_Engineering/01_Source_Code",\
    "./04_Engineering/05_Deliverables/dll/algo",\
    "./04_Engineering/02_Development_Tools",\
    "./04_Engineering/03_Workspace/algo/externals",\
    "./05_Testing/05_Test_Environment/algo/inttests/stk",\
    "./05_Testing/05_Test_Environment/algo/reqtests/valf_tests",\
    "./05_Testing/06_Test_Tools/mts_measurement/dll",\
    "./05_Testing/06_Test_Tools/mts",\
    ]
elif SCAN_FILES == "STD_OFF":
    LstDirFolder = [\
    "./04_Engineering/02_Development_Tools/scons_tools",\
    "./05_Testing/05_Test_Environment/algo/inttests/hpc",\
    "./05_Testing/05_Test_Environment/algo/inttests/stk",\
    "./05_Testing/05_Test_Environment/algo/reqtests/valf_tests",\
    ]
    LstFolderList = [\
    "./04_Engineering/00_CodeGen/algo",\
    "./04_Engineering/01_Source_Code/algo",\
    "./04_Engineering/01_Source_Code/algo/00_Custom",\
    "./04_Engineering/01_Source_Code/algo/00_Custom/sw_support",\
    "./04_Engineering/01_Source_Code",\
    "./04_Engineering/05_Deliverables/dll/algo",\
    "./04_Engineering/03_Workspace/algo/externals",\
    "./04_Engineering/02_Development_Tools"\
    ]

class Sandbox:
    def __init__(self, sandbox,id):
        self.DevPath = ""
        #self.path=""
        self.label=""
        self.cp=""
        self.LatestCP=""
        self.LatestLabel=""
        self.Project=""
        self.RootProject=""
        self.SharingProject=""
        self.Component=""
        self.GetSandBoxinfo(sandbox)
        
    def GetSandBoxinfo(Obj,sandbox):
        cmdline_info = "si sandboxinfo   --noshowCheckpointDescription --noassociatedIssues --sandbox="+sandbox
        #kprint(cmdline_info)
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            #kprint(stdout_str)
            #kprint(stderr_str)
            
        except OSError,ValueError:
            print formatExceptionInfo()
        if "Shared From:" in stdout_str  :
            stdout_str_lines = stdout_str.splitlines()
        
            for Line in stdout_str_lines:
                #if "Development Path:" in Line:
                    
                    #DevPath = Line.replace("Development Path:", "")
                    #DevPath = DevPath.replace(" ", "")
                    #Obj.DevPath = DevPath
                #elif "Revision:" in Line:
                    #LatestCP = Line.replace("Revision:", "")
                    #LatestCP = LatestCP.replace(" ", "")
                    #Obj.LatestCP = LatestCP
                #elif "Configuration Path:" in Line:
                    #Obj.RootProject=Line.replace("Configuration Path:","")
                    #x = Obj.RootProject.split("#")
                    #Obj.RootProject = x[2]
                    #MainProjectName = Obj.RootProject
                #if "Project Name:" in Line:
                    #Obj.Project=Line.replace("Project Name:","")
                    #Obj.Project = Obj.Project.replace(" ", "")
                if "Shared From:" in Line:
                    Obj.SharingProject=Line.replace("Shared From:","")
                    Obj.SharingProject = Obj.SharingProject.replace(" ", "")
                #elif "Variant Sandbox Name:" in Line:
                    #Obj.path=Line.replace("Variant Sandbox Name:","")
                    #Obj.path = Obj.path.replace(" ", "")
            #Obj.LatestLabel = info.GetLabelForRevision(Obj.DevPath,Obj.Project, Obj.LatestCP, Obj )
            t =Obj.SharingProject.split("/")
            #print(t)
            #if t[4] == "Tools":
                #Obj.Component = t[5]
                #print("x"*60)
                #print(Obj.Component)                
            #else:
                #Obj.Component = t[6]
            for comp in Comps:
                for folder in t:
                    if comp == folder:
                        Obj.Component = comp
                        break
                if Obj.Component:
                    #print("OK")
                    break
class SubProject:
    def __init__(self, ID):
        self.ID = ID
        self.path=""
        self.cmp=""
        self.label.main=""
        self.label.interface=""
        self.label.custom=""
        self.Cp=""
        self.Rev=""
        self.Typ=""
def AddErr(err=LineErrMeg):
    global logName
    global EndingErrMeg, EndingErrLevel
    logName = os.path.basename(__file__)
    logName = logName.replace(".pyc", "")
    logName = logName.replace(".py", "")
    EndingErrLevel = EndingErrLevel + 1
    EndingErrMeg.append( str(EndingErrLevel)+": "+logName+": "+err)
    
def GetLabelForRevision(SharedProject, Rev):
        """
        GetRevisionForLabel( SharedProject, Label)

        Description: Get the revision corresponding to a label

        Parameter: -SharedProject the path from where the shared project is shared
                   -Label serach the revision to this label

        return 0 if label could not be found in this shared project
        """
        ret_value = "default"
        #if CurrentSandBox.DevPath:
           # cmdline_info='si viewprojecthistory --batch  --fields=revision,labels --rfilter=labeled ' +' -P  #p='+ConvertFlatToConfigPath(SharedProject)+''
        #else:
            #cmdline_info='si viewprojecthistory --batch  --fields=revision,labels  --rfilter=labeled   --project='+SharedProject
        cmdline_info='si viewprojecthistory --batch  --fields=revision,labels  --rfilter=labeled   --project='+SharedProject
        #kprint cmdline_info
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            #kprint(stdout_str)
            #kprint(stderr_str)
            stdout_str_lines = stdout_str.splitlines()
        except OSError,ValueError:
            print formatExceptionInfo()
#        kprint Label
        for line in stdout_str_lines:
            #kprint line
            if (len(line) > 1):
                argu = line.split()
                #kprint (argu)
                if (len(argu) > 2):
                    argu[1] = argu[len(argu)-1]
                    argu[0] = line.replace(argu[1],"")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n","")
    #                    kprint argu[0]
                    if (len(argu) > 1):
    #                    kprint argu[0]
    #                    kprint argu[1]

                        # check if unicode
                        try:
                            argu[0].decode('ascii')
                        except UnicodeDecodeError:
                            kprint("Decoding issue")
                else:
                    # an ascii-encoded unicode string
                    #kprint(argu[0],1)
                    if (argu[0] == Rev):
                        ret_value = argu[1]
                        #kprint(cmdline_info)
                        break
#                        kprint "Return value " + ret_value
        #if ret_value == "default":
            #kprint(stdout_str)
            #kprint(stderr_str)
        return ret_value
    
def premain():
    global logName
    global start_time 
    start_time = timeit.default_timer()
    common.Init()
    logName = os.path.basename(__file__)
    logName = logName.replace(".py", "")
    
    if not os.path.exists("log"):
        os.makedirs("log")
    global  fo
    if os.path.isfile("./log/"+logName+".log"):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename("./log/"+logName+".log", "./log/"+logName+"_"+time+".log")
    
    fo = open("./log/"+logName+".log", "wb+")
    common.fo = fo
    if info.MyConf.debug_mode == "STD_ON":LogFunc("logging :" + logName)
def postmain():
    global logName
    fprint("#"*30)
    fprint("#"*30)
    if  EndingErrLevel != 0: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    #fo.close()
    if EndingErrLevel != 0:
        if info.MyConf.fail_safe == "STD_ON":
            FailSafe()
    t = timeit.default_timer() - start_time
    m = t/60
    s = t %60
    LogFunc("-"*30)
    LogFunc("--- %s seconds ---" % (timeit.default_timer() - start_time))
    LogFunc("    "+str(m) + " Minutes ")
    LogFunc("-"*30)
    fo.close()
    if info.MyConf.step_email_notification == "STD_ON":
        common.ActivityReportMail(aModule_Name=Module_Name, aModule_Description=Module_Description,aEndingErrLevel=EndingErrLevel,alogName=LogFile,aTimeConsumption=m,aEmail_Address=common.Email_Address)

    
        
#def fprint(text):
    #fo.write(text)
    #fo.write("\n")
    
def GetRevisionForLabel(SharedProject, Label):
        """
        GetRevisionForLabel( SharedProject, Label)

        Description: Get the revision corresponding to a label

        Parameter: -SharedProject the path from where the shared project is shared
                   -Label serach the revision to this label

        return 0 if label could not be found in this shared project
        """
        ret_value = "default"
        #if CurrentSandBox.DevPath:
           # cmdline_info='si viewprojecthistory --batch  --fields=revision,labels --rfilter=labeled ' +' -P  #p='+ConvertFlatToConfigPath(SharedProject)+''
        #else:
            #cmdline_info='si viewprojecthistory --batch  --fields=revision,labels  --rfilter=labeled   --project='+SharedProject
        cmdline_info='si viewprojecthistory --batch  --fields=revision,labels  --rfilter=labeled   --project='+SharedProject
        #kprint cmdline_info
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            #kprint("search : " + Label)
            #kprint(cmdline_info)
            #if stdout_str:
                #kprint("Out :" + stdout_str)
            if stderr_str:
                kprint("Err: "+stderr_str)
            stdout_str_lines = stdout_str.splitlines()
        except OSError,ValueError:
            print formatExceptionInfo()
#        kprint Label
        for line in stdout_str_lines:
            #kprint line
            if (len(line) > 1):
                argu = line.split()
                #kprint ("argu :"+str(argu))
                if (len(argu) > 2):
                    argu[1] = argu[len(argu)-1]
                    argu[0] = line.replace(argu[1],"")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n","")
    #                    kprint argu[0]
                if (len(argu) > 1):
#                    kprint argu[0]
#                    kprint argu[1]

                    # check if unicode
                    try:
                        argu[0].decode('ascii')
                    except UnicodeDecodeError:
                        kprint("Decoding issue")
                    #kprint("argu[1] "+ argu[1] )    
                    if (argu[1] == Label):
                        ret_value = argu[0]
                        #kprint(cmdline_info)
                        break
                #else:
                    # an ascii-encoded unicode string
                    #kprint(argu[0],1)
                    #if (argu[1] == label):
                        #ret_value = argu[0]
                        #kprint(cmdline_info)
                        #break
#                        kprint "Return value " + ret_value
        #if ret_value == "default":
            #kprint(stdout_str)
            #kprint(stderr_str)
        return ret_value
def dump(obj):
   fprint("#"*30)
   for attr in dir(obj):
       if hasattr( obj, attr ):
           if attr != "__doc__" and attr != "__init__" and attr != "__module__":
               fLogFunc("-"*30)
               fprint( "obj.%s = %s" % (attr, getattr(obj, attr)))
               fLogFunc("-"*30)
               
def ReadXml(XmlFileName, tag):
    returnValue = {}
    Paths = {}
    CurrentLabel = {}
     
    SubPros = []
    tree = ET.parse(XmlFileName)
    root = tree.getroot()
    xx=0
    yy=0
    for Cfg in root.findall(tag):
        subPro = SubProject(xx)
        xx=xx+1
        CMPName = Cfg.get('CompName')
        Paths[CMPName] = Cfg.get('Path')
        CurrentLabel[CMPName] = Cfg.find('Label').get('Label')
        subPro.path=Cfg.get('Path')
        subPro.label.main = Cfg.find('Label').get('Label')
        subPro.Rev = Cfg.find('Revision').get('Revision')
        subPro.Typ = Cfg.find('Type').get('Type')
        subPro.cmp=CMPName
        #returnValue[Cfg.get('name')] = Cfg.text
        SubPros.append(copy.deepcopy(subPro))
        #dump(subPro)
        
    return SubPros
    
    
    
def main1():
    tree = ET.parse(MainFile)
    root = tree.getroot()
    filesConf = root.findall("FileCfg")
    for fileLine in filesConf :
        file = fileLine.get('File')
        files.append(file)
    kprint(files)
    for file in files:
        tree = ET.parse(file)
        root = tree.getroot()
        C = root.find("BaseConfig")
        x = C.find("SharedProject")
        while(x):
            kprint(x.get("CompName"))
            Name = x.get("CompName")
            label = x.find("Config").get("Label")
            Type = x.find("Config").get("Type")
            if not Name in CompsSubProjects:
                CompsSubProjects[Name] = (label, Type)
            #x = C.find("SharedProject")
    kprint(CompsSubProjects)
def getSubprojects():
    ret = []
    subfolders = []
    for folder in LstFolderList:
        folder = os.path.abspath(folder)
        subfolders = common.getSubdirs(folder)
        for F in subfolders:
            if os.path.isfile(F+"/project.pj"):
                ret.append(F+"/project.pj")
                
    for folder in LstDirFolder:
        folder = os.path.abspath(folder)
        if os.path.isfile(folder+"/project.pj"):
            ret.append(folder+"/project.pj")
    return ret
def getSubprojects1():
    ret = []
    folder = info.CurrentSandBox.path.replace("project.pj", "")
    folder  = folder+WD+"/04_Engineering"
    kprint("#"*30)
    kprint("Parsing folder :"+folder)
    t = os.walk(folder)
    for x in t:
        #kprint(x[0])
        if os.path.isfile( x[0]+"/project.pj") :
            ret.append(x[0]+"/project.pj")
    #temp = glob.glob(str(folder)+'/'+"*.pj")
    kprint("Total Subprojects :" + str(len(ret)))
    return ret
def checkLabs(Labels):
    #global CompsLabels
    #CompsLabels = Labels[:]
    print("Checking Labels ...")
    BAR_MAX = len(Labels)
    if BAR_MAX != 0:
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
    found = {}
    subProj = getSubprojects()
    subProj = getBSharedSubProjects(subProj)
    for label in  Labels:
        found[label] = 0
        for folder in subProj:
            x =  GetRevisionForLabel(folder, label)
            if x !="default":
                found[label] = 1
                break
        BAR.increment_amount()
        BAR.display()
    ret = 0            
    for label in  Labels:
        
        if found[label] == 0:
            print("Err: label not found "+label)
            AddErr("Label "+label+" Not found !!!")
            ret = 1
    if ret == 0:
        print( " OK !!!")
    return(ret)                           
def getBSharedSubProjects(vlist):
    ret = []
    n = 1000
    for folder in vlist:
        CurrentSandBox = Sandbox(folder,n)
        if CurrentSandBox.SharingProject:
            ret.append(CurrentSandBox.SharingProject)
            
    return(ret)
def FailSafe():
    pass           
def getSharedSubProjects(vlist):
    ret = []
    #command = "si sandboxinfo -S   --noattributes --noshowCheckpointDescription --noassociatedIssues "
    n= 1
    m =1
    global CompsSubProjects
    global CompsLabels
    global Comps
    #print("S"*30)
    #print(CompsLabels)
    #print("S"*30)
    print("Full Labels' verification ...")
    BAR_MAX = len(vlist)
    BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
    for folder in vlist:
        BAR.increment_amount()
        BAR.display()
        CurrentSandBox = Sandbox(folder,n)
        n = n+1
        if CurrentSandBox.SharingProject:
            #kprint (str("#")*30+": ")
            #kprint (str("#")*30+": ")
            #kprint (str(m)+": \n")
            m = m +1
            if CurrentSandBox.Component in CompsSubProjects:
                CompsSubProjects[CurrentSandBox.Component ].append((CurrentSandBox.Project, CurrentSandBox.SharingProject))
                
            else:
                CompsSubProjects[CurrentSandBox.Component ]=[(CurrentSandBox.Project, CurrentSandBox.SharingProject)]
            
            #kprint("Here am I")
            #kprint(CompsSubProjects[CurrentSandBox.Component])
            if not CurrentSandBox.Component in CompsLabels:
                continue
            for temp in CompsLabels[CurrentSandBox.Component]:
               lab = temp[0] 
               type = temp[1]
               #kprint("temp: "+str(temp))
               
               if type != "build":
                   kprint("type"+ type)
                   continue
               x =  GetRevisionForLabel(CurrentSandBox.SharingProject, lab)
               #kprint("lab :"+ lab)
               #kprint(x)
               if x != "default":
                   CurrentSandBox.cp = x
                   CurrentSandBox.label = lab
                   #CurrentSandBox.DevPath = GetDevpathCP(CurrentSandBox.SharingProject, x)
                   if CurrentSandBox.Component in CompsDevpaths:
                       CompsDevpaths[CurrentSandBox.Component ].append((CurrentSandBox.DevPath, CurrentSandBox.label,CurrentSandBox.Project))               
                   else:
                       CompsDevpaths[CurrentSandBox.Component ]=[(CurrentSandBox.DevPath, CurrentSandBox.label,CurrentSandBox.Project)]
                   #print("S"*30)
                   #print(CompsLabels)
                   #print("S"*30)
                   K = 0
                   for E1 in CompsLabels[CurrentSandBox.Component]:
                       L = list( E1 )
                       #listtemp = list(ReplaceDic[key])
                       if L[0] == lab:
                           L[3] = "OK"
                           CompsLabels[CurrentSandBox.Component][K] = tuple(L)
                          #print("E"*30)
                           #print(CompsLabels[CurrentSandBox.Component])
                          #print("E"*30)
                       K = K +1
                   #CompsLabels[CurrentSandBox.Component] = templist  
               #dump(CurrentSandBox)
    #print("E"*30)
    #print(CompsLabels)
    #print("E"*30)
    
    if info.MyConf.debug_mode == "STD_ON":           
        kprint( "#"*30)
        kprint( "Shared projects are "+ str(m-1))
        kprint( "#"*30)
    if info.MyConf.debug_mode == "STD_OFF":           
        fprint( "#"*30)
        fprint( "Shared projects are "+ str(m-1))
        fprint( "#"*30)
    for comp in CompsDevpaths:
        #kprint( "-"*30)
        #kprint(comp)
        for entry in CompsDevpaths[comp]:
            if not comp in CompsDevpathsSimple:
                CompsDevpathsSimple[comp] = [entry[0]]
            else:
                if entry[0] not in CompsDevpathsSimple[comp]:
                    CompsDevpathsSimple[comp].append(entry[0])
            #kprint(entry)
    #for comp in CompsDevpathsSimple:
        #kprint( "*"*30)
        #kprint(comp)
        #kprint(CompsDevpathsSimple[comp])
         
def GetDevpaths(prj):
    ret = {}
    cmdline_info = "si projectinfo --noattributes --noshowCheckpointDescription --noshowCheckpointDescription  --noacl --project="+prj  
        #kprint(cmdline_info)
    try:
        proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
            #kprint(stdout_str)
            #kprint(stderr_str)
            
    except OSError,ValueError:
        kprint (formatExceptionInfo())
        
    stdout_str_lines = stdout_str.splitlines()
    f = 0            
    for Line in stdout_str_lines:
        if "Development Paths:" in Line:
            f = 1
            continue
        if not ":" in Line and f == 1:
            t = Line.split()
            ret[t[1].replace("(","").replace(")","")] = t[0]
            #kprint(t)
    #kprint(ret)    
    return ret      

def GetDevpathCP(pj, cp):
    dict = GetDevpaths(pj)
    ret = "default"
    Lmax = 0
    x = cp.split(".")
    if len(x) == 2:
        ret = "Normal"
    else:
        for key in dict:
            l = len(key)
            #kprint(cp[:l])
            #kprint(key)
            #kprint(cp)
            if key == cp[:l] and l > Lmax:
                #kprint(dict[key])
                Lmax = l
                ret = dict[key]
    kprint("Devpath :" +ret)  
    return ret
NotFoundLabels = []
def Report():
    if info.MyConf.debug_mode == "STD_ON":info.dump(info.MyInfo)
    if info.MyConf.debug_mode == "STD_ON":info.dump(info.CurrentSandBox)
    subProj = getSubprojects()
    getSharedSubProjects(subProj)
   
    od = collections.OrderedDict(sorted(CompsLabels.items()))
    #print(od)
    n = 1
    for x in od:
        #kprint("*"*30)
        #kprint( str(n) +" : "+str(x))
        m=1
        for t in CompsLabels[x]:
            #kprint (str(n)+"."+str(m)+" : "+str(t))
            L = list(t)
            if L[3] == "NOK":
                NotFoundLabels.append(L[0])
            m = m + 1
        #kprint("*"*30)
        n = n +1
    if  NotFoundLabels:   
        s = 1
        errtxt = "Labels not found are " + str(len(NotFoundLabels))+"/"+str(len(Comps))+" :\n"
        kprint(errtxt)
        AddErr(errtxt)
        for nf in NotFoundLabels:
            kprint (str(s)+": "+str(nf))
            s = s+1
        if info.MyConf.debug_mode == "STD_ON":common.PrintTitel("NOK !!!")
        else: print("NOK !!!")
    else:
        if info.MyConf.debug_mode == "STD_ON":common.PrintTitel(" OK ")
        else: print(" OK ")
    #for comp in CompsLabels:
        #info.dump(comp )
def main():
    global CompsLabels
    global Comps
    global files
    global SCAN_FILES
    #BAR_MAX = 400
    #BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
    #common.PrintTitel(" Validate Labels !!! ")
    if SCAN_FILES == "STD_ON":
        files = []
        tree = ET.parse(MainFile)
        root = tree.getroot()
        filesConf = root.findall("FileCfg")
        for fileLine in filesConf :
            file = fileLine.get('File')
            files.append(file)
        kprint(files)
        common.PrintList(CompsToExclude, "Excluded Comps")
    for file in files:
        tree = ET.parse(file)
        root = tree.getroot()
        C = root.find("BaseConfig")
        x = root.findall("./BaseConfig/SharedProject")
        for y in x:
            #kprint(y)
            Name = y.get("CompName")
            label = y.find("Config").get("Label")
            Type = y.find("Config").get("Type")
            if Type != "build":
                for cfg in y.iter('Config'):
                    label = cfg.get("Label")
                    Type = cfg.get("Type")
            if Type != "build":
                continue
            if Name in CompsToExclude:
                continue
            if not Name in CompsLabels:
                CompsLabels[Name] = [(label, Type, file, "NOK")]
                Comps.append(Name)
            else:
                 CompsLabels[Name].append((label, Type, file, "NOK"))
                 Comps.append(Name)
            #x = C.find("SharedProject")
            #BAR.increment_amount()
            #BAR.display()
        C = root.find("CustomConfigV2")
        x = root.findall("./CustomConfigV2/SharedProject")
        for y in x:
            #kprint(y)
            Name = y.get("CompName")
            label = y.find("Config").get("Label")
            Type = y.find("Config").get("Type")
            if not Name in CompsLabels:
                CompsLabels[Name] = [(label, Type,file, "NOK")]
                Comps.append(Name)
            else:
                CompsLabels[Name].append((label, Type,file, "NOK"))
                Comps.append(Name)
            #x = C.find("SharedProject")
            #BAR.increment_amount()
            #BAR.display()
    #BAR.update_amount(new_amount =BAR_MAX) 
    #BAR.display()
    Report()

def test():
     #GetDevpathCP("/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CB_CameraBlockage/04_Engineering/01_Source_Code/algo/gb/project.pj", "1.78")
     checkLabs(["AL_LD_05.12.07_INT-2_MKSFix1"])
def Container():
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)
    try:
        premain()
        if info.MyConf.tst_mode == "STD_ON": 
            test()
        else:    
            main()
    except OSError,ValueError:
        AddErr(formatExceptionInfo())
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 
    #print(EndingErrLevel , (EndingErrMeg))    