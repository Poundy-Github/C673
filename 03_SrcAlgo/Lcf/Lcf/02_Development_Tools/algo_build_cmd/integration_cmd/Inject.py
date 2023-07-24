"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:45CET $

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
import info

import timeit
from common import fprint , fo , Email_Address
import common


CP = info.MyConf.cp
AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
#WD =os.path.abspath(info.MyConf.WD)
#os.chdir(WD) 
#print("WD: "+ WD + " \n ")
logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0
LogFile="./log/Build"+os.path.basename(__file__)+".log"

fo = None
Stand_Alone="STD_OFF"
Module_Name=""
Module_Description=""
Module_Status="NO_ERROR"

from optparse import OptionParser
parser = OptionParser()
Email_Address = None
parser.add_option("-c", "--components", help="List of Components Coma separated ",dest="comps", metavar="FILE")
parser.add_option("-l", "--labels", help="List of Components Coma separated ",dest="labs", metavar="FILE")
parser.add_option("-v", "--variants", help="List of Components Coma separated ",dest="vars", metavar="FILE")
(options, args) = parser.parse_args()
if options.__dict__['comps'] and options.__dict__['labs'] and Stand_Alone=="STD_ON":
    Email_Address = options.__dict__['email_list']
else:
    Email_Address = info.MyConf.default_email

InjectConfig = {"EM_EnvironmentModel":"AL_EM_MFC400_01.12.10_INT-0"}    
InjectConfig = {}    
InjectConfigv = {}    

WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD)    

if options.__dict__['labs']: ListOfLabels=options.__dict__['labs'].split(","); 
else :ListOfLabels = []
if options.__dict__['vars']:ListOfVariants=options.__dict__['vars'].split(","); 
else : ListOfVariants = []

ScanningFolders = [
                os.getcwd()+"\\04_Engineering\\01_Source_Code\\algo\\",
                os.getcwd()+"\\04_Engineering\\00_CodeGen\\algo\\",
                os.getcwd()+"\\04_Engineering\\01_Source_Code\\algo\\00_Custom\\",
                os.getcwd()+"\\04_Engineering\\03_Workspace\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\dll\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\cfg\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\include\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\lib\\pc\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\lib\\ti_arp32\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\lib\\ti_c66xx\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\lib\\ti_c674x\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\lib\\ti_cortex_a8\\algo\\",
                os.getcwd()+"\\04_Engineering\\05_Deliverables\\lib\\ti_cortex_a15\\algo\\",
                ]
SynchFolders = [
                "\\04_Engineering\\01_Source_Code\\algo\\",
                "\\04_Engineering\\00_CodeGen\\algo\\",
                "\\04_Engineering\\01_Source_Code\\algo\\00_Custom\\",
                "\\04_Engineering\\03_Workspace\\algo\\",
                "\\04_Engineering\\05_Deliverables\\dll\\algo\\",
                "\\04_Engineering\\05_Deliverables\\cfg\\algo\\",
                "\\04_Engineering\\05_Deliverables\\include\\algo\\",
                "\\04_Engineering\\05_Deliverables\\lib\\pc\\algo\\",
                "\\04_Engineering\\05_Deliverables\\lib\\ti_arp32\\algo\\",
                "\\04_Engineering\\05_Deliverables\\lib\\ti_c66xx\\algo\\",
                "\\04_Engineering\\05_Deliverables\\lib\\ti_c674x\\algo\\",
                "\\04_Engineering\\05_Deliverables\\lib\\ti_cortex_a8\\algo\\",
                "\\04_Engineering\\05_Deliverables\\lib\\ti_cortex_a15\\algo\\",
                ]
                                
def AddErr(err=LineErrMeg):
    global logName
    global EndingErrMeg, EndingErrLevel
    logName = os.path.basename(__file__)
    logName = logName.replace(".pyc", "")
    logName = logName.replace(".py", "")
    EndingErrLevel = EndingErrLevel + 1
    strx = ""
    if info.MyConf.debug_mode == "STD_ON":strx =str(EndingErrLevel)+": "+logName
    EndingErrMeg.append( strx+": "+err)
    
def premain():
    global logName
    global start_time, logName 
    start_time = timeit.default_timer()
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
    global fo
    common.fo  = fo
    fprint("#"*30)
    fprint("#"*30)
    if  EndingErrLevel != 0: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    
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
    '''if info.MyConf.step_email_notification == "STD_ON":
        common.ActivityReportMail(aModule_Name=Module_Name, aModule_Description=Module_Description,aEndingErrLevel=EndingErrLevel,alogName=LogFile,aTimeConsumption=m,aEmail_Address=Email_Address)'''

RootLocation = "D:\\Sandboxs\\Build"
RootProject = "/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/"
class IterRegistry(type):
    def __iter__(cls):
        return iter(cls._registry)

class Person(object):
    __metaclass__ = IterRegistry
    _registry = []

    def __init__(self, name):
        self._registry.append(self)
        self.name = name
def MakeBuildSandbox():
    for key, value in InjectConfig.iteritems():
        LOC = RootLocation+"/"+key+"/"+value
        Project=RootProject+key+"/project.pj"
        LOCPrj = LOC+"/project.pj"
        if os.path.isfile(LOCPrj):
            Build_Command = "si resync --overwriteChanged --norecurse "+LOCPrj
            print("Sandbox already there !!! : %s")%(LOCPrj)
            print("Synch : "+LOCPrj)
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            continue
        print("Creating sandbox !!! : %s")    %(LOCPrj)
        ProjectVersion = common.GetRevisionForLabel(Project, value)
        if ProjectVersion == "default": return
        Build_Command =  "si createsandbox --project=%s --norecurse --projectRevision=%s --cwd=%s" % (Project,ProjectVersion,LOC)
        print(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()

        if stdout_str:
            if info.MyConf.debug_mode == "STD_ON":common.kprint(stdout_str)
            else:common.fprint(stdout_str)
        if stderr_str:
            if info.MyConf.debug_mode == "STD_ON":common.kprint(stderr_str)
            else:common.fprint(stderr_str)

def MakeVariantSandbox():
    for key, value in InjectConfigv.iteritems():
        LOC = RootLocation+"/"+key+"/"+value
        Project=RootProject+key+"/project.pj"
        LOCPrj = LOC+"/project.pj"
        if os.path.isfile(LOCPrj):
            Build_Command = "si resync --overwriteChanged --norecurse "+LOCPrj
            print("Sandbox already there !!! : %s")%(LOCPrj)
            print("Synch : "+LOCPrj)
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            continue
        print("Creating sandbox !!! : %s")    %(LOCPrj)
        #ProjectVersion = common.GetRevisionForLabel(Project, value)
        #if ProjectVersion == "default": return
        Build_Command =  "si createsandbox --project=%s --norecurse --devpath=%s --cwd=%s" % (Project,value,LOC)
        print(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()

        if stdout_str:
            if info.MyConf.debug_mode == "STD_ON":common.kprint(stdout_str)
            else:common.fprint(stdout_str)
        if stderr_str:
            if info.MyConf.debug_mode == "STD_ON":common.kprint(stderr_str)
            else:common.fprint(stderr_str)

def LocalCopy():
    for key, value in InjectConfig.iteritems():
        LOC = RootLocation+"/"+key+"/"+value
        for folder in copyFolders:
            src = LOC+folder
            dst = os.getcwd()+folder
            print(src, dst)
            common.GenericCopy(src, dst)
SharingDic = {}

def Gcopy():
    common.PrintTitel("Copy Shared folders")
    InjectConfigAll = InjectConfigv.copy()
    InjectConfigAll.update(InjectConfig)
    print(InjectConfigAll)
    for key, value in InjectConfigAll.iteritems():
        LOC = RootLocation+"/"+key+"/"+value
        for dst in filteredDic:
            srcprj = filteredDic[dst]
            print(srcprj)
            if key in srcprj:
                srcprj = srcprj.replace("/project.pj", "")
                src = srcprj.replace("/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/"+key,LOC)
                print("Folder %s copied to %s"% (src,dst))
                common.GenericCopy(src, dst)
        
def GetShared(Basefolder=None):

    if Basefolder:
        FolderList = common.getSubdirsRecursive(Basefolder)
        GetSharedM(FolderList)
    else:
        for folder in ScanningFolders:
            FolderList = common.getSubdirs(folder)
            GetSharedM(FolderList)
def GetSharedM(FolderList):
    print("Getting shared folders ....")
    print("Scanning ....")
    for folder in FolderList:
        P = folder+"/project.pj"
        cmdline_info = "si sandboxinfo   --noshowCheckpointDescription --noassociatedIssues --sandbox="+P
        #print(cmdline_info)
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            
        except OSError,ValueError:
            print formatExceptionInfo()
        if "Shared From:" in stdout_str  :
            stdout_str_lines = stdout_str.splitlines()      
            for Line in stdout_str_lines:
                if "Shared From:" in Line:
                    SharingProject=Line.replace("Shared From:","")
                    SharingProject = SharingProject.replace(" ", "")
                    SharingDic[folder] = SharingProject
            t =SharingProject.split("/")
def FilterShared():
    global filteredDic
    filteredDic = {}
    common.PrintTitel("Filtering Shared folders")
    InjectConfigAll = InjectConfigv.copy()
    InjectConfigAll.update(InjectConfig)
    for key, value in InjectConfigAll.iteritems():
        for skey in SharingDic:
            svalue = SharingDic[skey]
            if key in svalue:
                filteredDic[skey] = svalue
                print ("folder %s shared from %s"% (skey,svalue))
    return(filteredDic)  
    
    
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
    
def GetCompNamesFromLabels(ListOfLabels=ListOfLabels):
    global InjectConfig
    if ListOfLabels: InjectConfig={}
    Build_Command = "si viewprojecthistory --fields=labels --rfilter=labeled  --sandbox="
    GetShared()
    
        
    for label in ListOfLabels:
        for key, value in SharingDic.iteritems():
            (stdout_str, stderr_str) = common.RunCommand(Build_Command+key+"/project.pj")
            if label in stdout_str:
                #print(stdout_str)
                #print(value)
                COMP = value.split("/")[6]
                print(COMP)
                InjectConfig[COMP] =  label
                break

def GetCompNamesFromVariants(ListOfVariants=ListOfVariants):
    global InjectConfigv
    if ListOfVariants: InjectConfigv={}
    Build_Command = "si projectinfo --noattributes --noshowCheckpointDescription --noshowCheckpointDescription  --noacl   --project="
    GetShared()
    
        
    for Variant in ListOfVariants:
        for key, value in SharingDic.iteritems():
            (stdout_str, stderr_str) = common.RunCommand(Build_Command+value)
            #print(stdout_str)
            if Variant in stdout_str:
                #print(stdout_str)
                #print(value)
                COMP = value.split("/")[6]
                print(COMP)
                InjectConfigv[COMP] =  Variant
                break
                
def GetCompNames():
    if ListOfLabels: GetCompNamesFromLabels()
    if ListOfVariants: GetCompNamesFromVariants()
    
    pass
def SynchAll():
    SynchList = []
    common.PrintTitel("Synchronization")
    InjectConfigAll = InjectConfigv.copy()
    InjectConfigAll.update(InjectConfig)
    for key, value in InjectConfigAll.iteritems():
        for Base in SynchFolders:
            LOC = RootLocation+"/"+key+"/"+value
            Project=RootProject+key+"/project.pj"
            LOCPrj = LOC+Base+"/project.pj"
            #if os.path.isfile(LOCPrj):
            SynchList.append(LOCPrj)
    common.Synch(SynchList)            
def FailSafe():
    pass
def main():
    GetCompNames()
    MakeBuildSandbox()
    MakeVariantSandbox()
    SynchAll()
    f = os.getcwd()+"\\04_Engineering"
    #GetShared()
    filteredDic = FilterShared()
    Gcopy()
    #LocalCopy()
def test():
    GetCompNames()    
def Container():
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)    
    premain()
    if info.MyConf.tst_mode == "STD_ON": 
        test()
    else:    
        main()
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    Stand_Alone="STD_ON"
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 