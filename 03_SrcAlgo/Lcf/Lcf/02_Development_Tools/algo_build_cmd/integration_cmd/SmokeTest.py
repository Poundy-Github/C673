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

import timeit
from common import Email_Address, fprint , fo
import common
tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
import mks_utils
from mks_utils import ProgressBar_obj

AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)      
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
                
def test():
    #MTSSynch()
    InstallDlls()
    #InvokeMTS()
    pass       
def main():
    MTSSynch()
    InstallDlls()
    InvokeMTS()
    ans = common.GetInput('Do you want to continue ? y/[n]:')
    if ans != "y":
        sys.exit(EndingErrLevel)
    
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
    #common.Init()
    Container()
    print(EndingErrLevel , (EndingErrMeg)) 