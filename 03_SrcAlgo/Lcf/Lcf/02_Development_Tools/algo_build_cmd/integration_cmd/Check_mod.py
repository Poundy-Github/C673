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
import info
import timeit
from common import  Email_Address,fprint , fo
import common
tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
import mks_utils
from mks_utils import ProgressBar_obj

AUTO_CP = info.MyConf.AUTO_CP
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD) 

FoldersToSynch = [".\\05_Testing\\06_Test_Tools\\"]

relFolders = [".\\04_Engineering\\05_Deliverables", ".\\04_Engineering\\04_Build\\algo\\vdy_sim\\"]
relNotRecursiveFolders = ["."]
SandboxFolders=[]
for relFolder in relFolders:
    folder = os.path.abspath(relFolder)
    SandboxFolder = folder+"/project.pj"
    SandboxFolders.append(SandboxFolder)
    
NRSandboxFolders=[]
for relFolder in relNotRecursiveFolders:
    folder = os.path.abspath(relFolder)
    NRSandboxFolder = folder+"/project.pj"
    NRSandboxFolders.append(NRSandboxFolder)    
Proj_NAme = info.MyConf.MainPrj
CP = info.MyConf.cp
user = info.MyConf.user
Label=""
Comment=""
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
ModFiles = []
LocModFiles = []
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0
logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint;

Stand_Alone="STD_OFF"
Module_Name="Check-in"
Module_Description="Chick-in the built objects into the server ."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"
InstallFolders = {".\\04_Engineering\\05_Deliverables\\dll\\algo":".\\05_Testing\\06_Test_Tools\\mts_measurement\\dll\\algo"}
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



def PrintTitel(text):
    M = 60
    L = len(text)
    N = M - L
    T = N/2
    print("*"*M)
    print("*"*T+" "*L+"*"*T)
    print("*"*T+text+"*"*T)
    print("*"*T+" "*L+"*"*T)
    print("*"*M)


def CheckShared(file):
    opt ="  --nolabels --nolocks "
    Build_Command = "si archiveinfo " +opt+ file
    #print("-*"*random.randint(0,30))
    proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    Lines = stdout_str.split('\n')
    for line in Lines:
        if "Archive Name:" in line:
            if Proj_NAme in line:
                #print(line)
                return(0)
            else:
                #print(line)
                return (1)
    if debug == 1:        
        if stdout_str :                
            print("Out: \n" + stdout_str+"\n")
        if stderr_str:
            print("Messages: \n"+stderr_str+"\n")
        else:
            print("Succeded !!!"+"\n")
        return(0)    
        
def GetLocalFiles(FilesList):
    RetFiles = []
    for file in FilesList:
        if not CheckShared(file):
            RetFiles.append(file)
        else:
            print("File is shared : !!! ")
            print(file)
    return(RetFiles)
    
def GetRevision(file):
    opt =" --nochangePackage --nolabels --nolocate --lockRecordFormat=project "
    Build_Command = "si revisioninfo " +opt+ file
    proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    Lines = stdout_str.split('\n')
    for line in Lines:
        if "Revision:" in line:
            Rev = line.replace("Revision:", "");
            Rev = Rev.replace(" ", "");
            return(Rev)
    if debug == 1:        
        if stdout_str :                
            print("Out: \n" + stdout_str+"\n")
        if stderr_str:
            print("Messages: \n"+stderr_str+"\n")
        else:
            print("Succeded !!!"+"\n")
def GetLock():
    #print(SandboxFolder, 111)
    ListTwo = []
    for SandboxFolder in SandboxFolders:
        #Build_Command = "si viewlocks --recurse  --sandbox="+SandboxFolder+" --filter=locked:"+user+" --lockRecordFormat={sandbox}::{member}; " 
        Build_Command = "si viewlocks --recurse  --sandbox="+SandboxFolder+" --rfilter=locked:"+user+" --lockRecordFormat={sandbox}::{member}; " 
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        common.fprint(stdout_str)
        if stderr_str:LogFunc(stderr_str)
        
        ListOne = stdout_str.split(";")
        
        #if info.MyConf.debug_mode == "STD_ON":print(Build_Command)
        for I in ListOne:
            if I:
                t = I.split("::")
                #print(t)
                str = t[0].replace("project.pj", t[1])
                ListTwo.append(str)
    #if info.MyConf.debug_mode == "STD_ON":print(ListTwo)
    '''-------------------------------------------------------------------------------'''    
    for SandboxFolder in NRSandboxFolders:
        Build_Command = "si viewlocks --norecurse  --sandbox="+SandboxFolder+" --rfilter=locked:"+user+" --lockRecordFormat={sandbox}::{member}; " 
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        common.fprint(stdout_str)
        if stderr_str:LogFunc(stderr_str)
        
        ListOne = stdout_str.split(";")
        
        #if info.MyConf.debug_mode == "STD_ON":print(Build_Command)
        for I in ListOne:
            if I:
                t = I.split("::")
                #print(t)
                str = t[0].replace("project.pj", t[1])
                ListTwo.append(str)
    #if info.MyConf.debug_mode == "STD_ON":print(ListTwo)            
    return(ListTwo)
    #print(stderr_str)

def ViewLock11():
    Build_Command = "si viewsandbox --recurse --fields=indent,name "+ " --lockRecordFormat={revision}{locker} "
    proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    List = stdout_str.split("\n")
    print(stdout_str)
    print(stderr_str)
    
def CMPLocalSandbox():
    global LocModFiles
    Build_Command = "si viewsandbox --recurse --fields=indent,name,wfdelta "
    proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    List = stdout_str.split("\n")
    OldLine = ""
    CurrentLine = ""
    for line in List:
        OldLine = CurrentLine
        CurrentLine = line
        if "Working file" in line:
            OldLine = OldLine.replace(" ","")
            ModFiles.append(OldLine)
    LocModFiles = GetLocalFiles(ModFiles)
    #print(LocModFiles)
            #print(line)


def CMPSandbox():
    global LocModFiles
    #print(SandboxFolders)
    for SandboxFolder in SandboxFolders:
        Build_Command = "si viewsandbox --sandbox="+SandboxFolder+" --recurse --fields=indent,name,wfdelta "
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        print(stderr_str)
        List = stdout_str.split("\n")
        OldLine = ""
        CurrentLine = ""
        for line in List:
            OldLine = CurrentLine
            CurrentLine = line
            if "Working file" in line:
                OldLine = OldLine.replace(" ","")
                ModFiles.append(OldLine)
    LocModFiles = GetLocalFiles(ModFiles)
def NRCMPSandbox():
    RetLocModFiles = []
    Loc_ModFiles = []
    #print(NRSandboxFolders)
    for SandboxFolder in NRSandboxFolders:
        Build_Command = "si viewsandbox --sandbox="+SandboxFolder+" --norecurse --fields=indent,name,wfdelta "
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        print(stderr_str)
        List = stdout_str.split("\n")
        OldLine = ""
        CurrentLine = ""
        for line in List:
            OldLine = CurrentLine
            CurrentLine = line
            if "Working file" in line:
                OldLine = OldLine.replace(" ","")
                Loc_ModFiles.append(OldLine)
    RetLocModFiles = GetLocalFiles(Loc_ModFiles)
    return RetLocModFiles
MessageDic = {}            
def Checkout(ListOfFiles):
    for file in ListOfFiles:
        Build_Command = "si co --changePackageId="+CP+" "+file
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        MessageDic[file] = stdout_str
        print(stdout_str)
    for key, value in MessageDic.iteritems():
        TextAll = "Checking Out :: "+key+" ->"+value
        #print(value)
        
def Checkin(ListOfFiles):
    if info.MyConf.debug_mode == "STD_ON":PrintTitel("Checkin")
    else:
        LogFunc("Checkin Built targets ... ");
        BAR_MAX = len(ListOfFiles)
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        #BAR.display()
    global Label
    global Comment
    if info.MyConf.build_checkin == "STD_OFF":
        Label = "-"
    if not Label or (Stand_Alone=="STD_ON"):
        Label=common.GetInput('Please enter a Label, [-] for Escaping Chickin:')
        Comment = Label
    else:
        LogFunc("Label used is :")
        LogFunc(Label)
        LogFunc("Comment used is :")
        LogFunc(Comment)
    common.CP = CP    
    common.Checkin(ListOfFiles,Label,Comment)    
    '''if Label == "-":
        print("Checkin has been canceled ....")
        return
    for file in ListOfFiles:
        Build_Command = "si ci --changePackageId="+CP+" --yes "+" --label="+Label+" --description="+Label+" "+file
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        MessageDic[file] = stdout_str
        print(stderr_str)
    for key, value in MessageDic.iteritems():
        TextAll = "Checking in :: "+key+" ->"+value
        #print(value) '''       
def Lock(ListOfFiles):
    if info.MyConf.debug_mode == "STD_ON":PrintTitel("Lock");LogFunc = common.kprint
    else:
        print("Lock ... ");LogFunc = common.fprint;
        BAR_MAX = len(ListOfFiles)
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
    for file in ListOfFiles:
        Build_Command = "si lock --changePackageId="+CP+" "+file
        LogFunc(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        (stdout_str,stderr_str) = proc.communicate()
        LogFunc(stdout_str)
        LogFunc(stderr_str)
        MessageDic[file] = stderr_str
        if info.MyConf.debug_mode == "STD_OFF":BAR.increment_amount();BAR.display()
        if "si: MKS" in stderr_str:
            if info.MyConf.strict_lock == "STD_OFF":
                common.kprint("un-strict lock Policy .....")                
                Build_Command = "si lock --changePackageId="+CP+" --lockType=auto   "+file
                common.kprint(Build_Command)
                proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                stdout_str, stderr_str = proc.communicate()
                #print("OUT: \n"+stdout_str)
                #print("ERR: \n"+stderr_str)
                MessageDic[file] = stderr_str
            if info.MyConf.strict_lock == "STD_USR":
                ans = common.GetInput('Branch file ... ?  y/[n]:')
                if ans == "y":
                    common.kprint("Not strict lock Policy .....")                
                    Build_Command = "si lock --changePackageId="+CP+" --lockType=auto  "+file
                    common.kprint(Build_Command)
                    proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    stdout_str, stderr_str = proc.communicate()
                    MessageDic[file] = stderr_str
                
            LogFunc(stdout_str)
            LogFunc(stderr_str)
    for key, value in MessageDic.iteritems():
        TextAll = "Locking :: "+key+" ->"+value
        #print(value)
        
def PostCheckinSynch():
    PrintTitel("Synch: MTS env.")
    for folder in FoldersToSynch:
        folder = os.path.abspath(folder)
        Pfolder = folder + "/project.pj"
        Build_Command = "si resync --overwriteChanged -R "+Pfolder
        if info.MyConf.debug_mode == "STD_ON":print("Synch Project : "+ Pfolder+" ...")
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            print("Out: \n" + stdout_str+"\n")
        if info.MyConf.invoke_mts  == "STD_USER":
            ans = common.GetInput('Invoke MTS y/[n]:')
        elif info.MyConf.invoke_mts  == "STD_ON":
            ans  = "y"
        elif info.MyConf.invoke_mts  == "STD_OFF":
            ans = "n"
        else:
            ans ="n"
        if ans == "y":
            print("Invoke MTS : ... \n")
            print(folder+"/run_algo_integration_test.bat")
            MTS = folder+"/run_algo_integration_test.bat"
            Build_Command = MTS
            proc=subprocess.Popen(Build_Command, shell=True, cwd=folder)
            stdout_str, stderr_str = proc.communicate()
            if stdout_str :
                print("Out: \n" + stdout_str+"\n")
            if stderr_str:
                print("Messages: \n"+stderr_str+"\n")

def UnLock(ListOfFiles):
    if not ListOfFiles:return
    if info.MyConf.debug_mode == "STD_ON":PrintTitel("Unlock");
    else:
        common.kprint("Unlock ... ");
        BAR_MAX = len(ListOfFiles)
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
    for file in ListOfFiles:
        Build_Command = "si unlock --action=remove " +file
        LogFunc(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if info.MyConf.debug_mode == "STD_OFF":BAR.increment_amount();BAR.display()
        LogFunc(stderr_str)
        LogFunc(stdout_str)
        MessageDic[file] = stderr_str
    for key, value in MessageDic.items():
        TextAll = "UnLocking :: "+key+" ->"+value

def premain():
    global logName
    global start_time 
    start_time = timeit.default_timer()
    common.Init()
    logName = os.path.basename(__file__)
    logName = logName.replace(".py", "")
    global  fo
    if not os.path.exists("log"):
        os.makedirs("log")
    
    if os.path.isfile("./log/"+logName+".log"):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename("./log/"+logName+".log", "./log/"+logName+"_"+time+".log")
    

    fo = open("./log/"+logName+".log", "wb+")
    common.fo = fo
    LogFunc("logging :" + logName)
    #fo = open("./log/"+logName+".log", "wb+")
    #common.fo = fo
def postmain():
    global logName
    global fo
    common.fo  = fo
    LogFunc("#"*30)
    LogFunc("#"*30)
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
    
def FailSafe():
    pass
def main():
    #global LocModFiles
    CMPSandbox()
    M1 = NRCMPSandbox()
    for IFile in M1:
        LocModFiles.append(IFile)
    if info.MyConf.debug_mode == "STD_ON":common.PrintList(LocModFiles, "MODE")
    if LocModFiles:
        Lock(LocModFiles)
        Checkin(LocModFiles)
    else:
        print("No files' differences .... ")
    UnLock(GetLock())
    PostCheckinSynch()
def InstallDlls():
    for key, value in InstallFolders.items():
        source = os.path.abspath(key)
        Destination = os.path.abspath(value)
        common.GenericCopy(source, Destination)
def test():
    InstallDlls()
    pass   
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
        AddErr(str(ValueError))
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    Stand_Alone="STD_ON"
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 