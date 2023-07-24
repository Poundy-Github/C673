"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:51:01CET $

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
import  Check_mod

import timeit
from common import Email_Address, fprint , fo
import common
tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
import mks_utils
from mks_utils import ProgressBar_obj
import RemoteJenkins
import xml.etree.ElementTree as ET
import string
import random

Comment="Updated"
Label="HEAD"

AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
MainFile="./Jenkins.xml"    
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)
MainFile = os.path.abspath(MainFile)
      
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD) 
if info.MyConf.debug_mode == "STD_ON":print("WD: "+ WD + " \n ")
logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0
DicJobs={}
OrderedJobs = []
fo = None
Stand_Alone="STD_OFF"
Module_Name="Smoke-Test"
Module_Description="Run the smoke test."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"
FoldersToSynch = [".\\05_Testing\\06_Test_Tools\\"]
InstallFolders = {".\\04_Engineering\\05_Deliverables\\dll\\algo":".\\05_Testing\\06_Test_Tools\\mts_measurement\\dll\\algo"}

from optparse import OptionParser
parser = OptionParser()
Email_Address = None
parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="FILE")
(options, args) = parser.parse_args()
if options.__dict__['email_list'] and Stand_Alone=="STD_ON":
    Email_Address = options.__dict__['email_list']
else:
    Email_Address = info.MyConf.default_email

Prefix = "" 
buildspec = ""
Security_File = "pwd.s"  

def id_generator(size=6, chars=string.ascii_uppercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))
 
def AddErr(err=LineErrMeg):
    global logName
    global EndingErrMeg, EndingErrLevel
    logName = os.path.basename(__file__)
    x = logName.split(".")
    if x: logName = x[0]
    logName = logName.replace(".py", "")
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
    if  EndingErrLevel != 0 and Stand_Alone=="STD_ON": common.PrintList(EndingErrMeg, logName +" ERR MSGS")
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
    #print(MailFreeTEXT, "!!!!")
    if info.MyConf.step_email_notification == "STD_ON":
        common.ActivityReportMail(aModule_Name=Module_Name, aModule_Description=Module_Description,aEndingErrLevel=EndingErrLevel,alogName=LogFile,aTimeConsumption=m,aEmail_Address=common.Email_Address,FreeTXT = MailFreeTEXT)
    shutil.rmtree(SX)
def CreatDummyfile(file="dummy.txt"):
    with open(file, "w") as text_file:
        text_file.write("")
def GetPrefix():
    global Prefix
    if ("MFS430BW16" in info.CurrentSandBox.DevPath) or ("SMFC4B0" in info.CurrentSandBox.DevPath):Prefix="algo_stereo:"
    elif ( "MFC440GY18" in info.CurrentSandBox.DevPath) or ( "MFC430TA16" in info.CurrentSandBox.DevPath):Prefix="algo_mono:"
    elif ( "SRLCam4T0" in info.CurrentSandBox.DevPath) or ( "MFL420TA36" in info.CurrentSandBox.DevPath):Prefix="algo_srlcam:"
    else:Prefix="algo_stereo:"
def ParseConfig():
    global DicJobs
    global OrderedJobs 
    global Prefix
    global buildspec
    DicJobs={}
    OrderedJobs = []
    tree = ET.parse(MainFile)
    root = tree.getroot()
    Jobs = root.findall("Job")
    n = 0
    global SX
    SX = "TempS"
    if not os.path.exists(SX):
        os.makedirs(SX)
    for Job in Jobs:
        par = {}
        Paremeters = Job.findall("Paremeter")
        for Paremeter in Paremeters:
            par[Paremeter.get('name') ] = Paremeter.get('value')
        if Job.get('build') != "STD_ON":continue 
        pwd = SX+"/"+id_generator()+".sx"
        if Job.get('name') not in OrderedJobs: OrderedJobs.append(Job.get('name'))
        if Job.get('name') not in DicJobs:
            DicJobs[Job.get('name')] = [RemoteJenkins.TJenkins(n,Job.get('protocol'),Job.get('server'),Job.get('job'),Job.get('username'), Job.get('pwd'),pwd,par)]
        else:
            DicJobs[Job.get('name')].append(RemoteJenkins.TJenkins(n,Job.get('protocol'),Job.get('server'),Job.get('job'),Job.get('username'), Job.get('pwd'),pwd,par))
        with open(pwd, "w") as text_file:
            text_file.write(Job.get('pwd'))
        n = n +1
        '''
        if  Job.get('name') == "Remote_SW_DevGate":
           #Devpaths =  Job.find("Paremeter").findall("Devpath")
           Paremeters = Job.findall("Paremeter")
           for Paremeter in Paremeters:
            print(Paremeter.get('name') )
            if Paremeter.get('name') == "buildspec.txt":
                buildspec = Paremeter.get('value') 
           GetPrefix()   ''' 

def FailSafe():
    pass
def InstallDlls():
    LogFunc("Installing Dlls ...")
    for key, value in InstallFolders.items():
        source = os.path.abspath(key)
        Destination = os.path.abspath(value)
        common.GenericCopy(source, Destination)
def MTSSynch():
    LogFunc("Synch: MTS env.")
    for folder in FoldersToSynch:
        folder = os.path.abspath(folder)
        Pfolder = folder + "/project.pj"
        Build_Command = "si resync --overwriteChanged -R "+Pfolder
        if info.MyConf.debug_mode == "STD_ON":print("Synch Project : "+ Pfolder+" ...")
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            print("Out: \n" + stdout_str+"\n")

def InvokeMTS():
    folder =FoldersToSynch[0]
    folder = os.path.abspath(folder)
    LogFunc("Invoke MTS ...")
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
        LogFunc(folder+"/run_algo_integration_test.bat")
        MTS = folder+"/run_algo_integration_test.bat"
        Build_Command = MTS
        proc=subprocess.Popen(Build_Command, shell=True, cwd=folder)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            print("Out: \n" + stdout_str+"\n")
        if stderr_str:
            print("Messages: \n"+stderr_str+"\n")     
def CallModule(object):
    global CP
    global EndingErrLevel, EndingErrMeg, fo
    if CP:object.CP = CP
    (RetEndingErrLevel , RetEndingErrMeg) = object.Container()
    EndingErrLevel = EndingErrLevel + RetEndingErrLevel
    if RetEndingErrLevel:
        #print(RetEndingErrMeg)
        EndingErrMeg = common.AddLists(EndingErrMeg, RetEndingErrMeg)
    #print(1)
    #print(RetEndingErrMeg)
    common.fo = fo
    return RetEndingErrLevel
    
def test():
    #MTSSynch()
    global DicJobs
    ParseConfig()
    for key in DicJobs:
        for obj in DicJobs[key]:
            common.dump(obj)
    #InvokeMTS()
    pass

MailFreeTEXT = ""

def main():
    global buildspec
    global MailFreeTEXT
    ParseConfig()
    MTSSynch()
    #InstallDlls()
    Check_mod.Comment =  Comment   
    Check_mod.Label =  Label   
    if CallModule(Check_mod):
        return
    for key in OrderedJobs:
        for obj in DicJobs[key]:
            #common.dump(obj)
            RemoteJenkins.Jenkins = obj
            if CallModule(RemoteJenkins):os.remove(obj.pwdf);return
            if os.path.isfile(obj.pwdf) :os.remove(obj.pwdf)
            if RemoteJenkins.stdout_str: MailFreeTEXT = MailFreeTEXT +"\n"+RemoteJenkins.stdout_str
            if RemoteJenkins.stderr_str: MailFreeTEXT = MailFreeTEXT +"\n"+RemoteJenkins.stderr_str
            
            
            
def main_old():
    global buildspec
    global MailFreeTEXT
    ParseConfig()
    MTSSynch()
    #InstallDlls()
    # Local MTS Check
    RemoteJenkins.Paremeters={}
    RemoteJenkins.Paremeters["Variant"] = info.CurrentSandBox.DevPath
    if info.MyConf.local_compstate == "STD_ON": 
        InstallDlls()
        RemoteJenkins.Jenkins = DicJobs["Local_Compstate"]
        if CallModule(RemoteJenkins):os.remove(RemoteJenkins.Jenkins.pwdf);return
        os.remove(RemoteJenkins.Jenkins.pwdf)
    else:
        print("Test %s has been disabled ..." %("Local CompState checks"))
    if os.path.isfile(DicJobs["Local_Compstate"].pwdf) :os.remove(DicJobs["Local_Compstate"].pwdf)
    
        
        
    Check_mod.Comment =  Comment   
    Check_mod.Label =  Label   
    if CallModule(Check_mod):
        return
        
    # Remote MTS Check
    RemoteJenkins.Paremeters={}
    RemoteJenkins.Paremeters["DEVPATH"] = info.CurrentSandBox.DevPath
    if info.MyConf.remote_compstate == "STD_ON":
        RemoteJenkins.Jenkins = DicJobs["Remote_Compstate"]
        if CallModule(RemoteJenkins):os.remove(RemoteJenkins.Jenkins.pwdf);return
        os.remove(RemoteJenkins.Jenkins.pwdf);
    else:
        print("Test %s has been disabled ..." %("Remote CompState checks"))
    if os.path.isfile(DicJobs["Remote_Compstate"].pwdf) :os.remove(DicJobs["Remote_Compstate"].pwdf)
    if RemoteJenkins.stdout_str: MailFreeTEXT = MailFreeTEXT +"\n"+RemoteJenkins.stdout_str 
    if RemoteJenkins.stderr_str: MailFreeTEXT = MailFreeTEXT +"\n"+RemoteJenkins.stderr_str

    # DevGate MTS Check
    RemoteJenkins.Paremeters={}
    if Label:RemoteJenkins.Paremeters["checkpoints"] = Prefix+Label
    if buildspec:RemoteJenkins.Paremeters["buildspec.txt"] = buildspec
    #print("buildspec",buildspec)
    CreatDummyfile(buildspec)    
    if info.MyConf.remote_sw_devgate == "STD_ON":
        RemoteJenkins.Jenkins = DicJobs["Remote_SW_DevGate"]
        if CallModule(RemoteJenkins):os.remove(RemoteJenkins.Jenkins.pwdf);return
        os.remove(RemoteJenkins.Jenkins.pwdf);
    else:
        print("Test %s has been disabled ..." %("SW DevGate"))
    if os.path.isfile(DicJobs["Remote_SW_DevGate"].pwdf) :os.remove(DicJobs["Remote_SW_DevGate"].pwdf)
    if os.path.isfile(buildspec) :os.remove(buildspec)
    if RemoteJenkins.stdout_str: MailFreeTEXT = MailFreeTEXT +"\n"+RemoteJenkins.stdout_str
    if RemoteJenkins.stderr_str: MailFreeTEXT = MailFreeTEXT +"\n"+RemoteJenkins.stderr_str
    
    #InvokeMTS()
    #ans = common.GetInput('Do you want to continue ? y/[n]:')
    #if ans != "y":
        #sys.exit(EndingErrLevel)
    
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
    common.Init()
    Container()
    print(EndingErrLevel , (EndingErrMeg)) 