"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:43CET $

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

Stand_Alone="STD_OFF"
Module_Name="Release"
Module_Description="Creating a Checkpoint."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"


CP = info.MyConf.cp
AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
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
Label=""
fo = None

def AddErr(err=LineErrMeg):
    global logName
    global EndingErrMeg, EndingErrLevel
    logName = os.path.basename(__file__)
    logName = logName.replace(".pyc", "")
    logName = logName.replace(".py", "")
    EndingErrLevel = EndingErrLevel + 1
    EndingErrMeg.append( str(EndingErrLevel)+": "+logName+": "+err)
    
def premain():
    global logName
    global start_time, logName 
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
    LogFunc("logging :" + logName)
def postmain():
    global logName
    global fo
    common.fo  = fo
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
    
def FailSafe():
    pass
def main():
    global Label
    Build_Command = ".\\check_for_build_and_cp.cmd"
    Build_Command = os.path.abspath(Build_Command)
    print(Build_Command)
    proc=subprocess.Popen([Build_Command,"-b"], shell=False,stdin=subprocess.PIPE,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    #t = proc.poll()
    #while not t:
        #t = proc.poll()
    #print(t)    
    if info.MyConf.auto_cp_creation == "STD_ON" or info.MyConf.auto_cp_creation=="STD_AUTO":
        if  Stand_Alone=="STD_OFF":
            print("Label to be used  : "+Label)
        elif Stand_Alone=="STD_ON":
            Label = common.GetInput('Please enter label:')
        if not proc.poll(): proc.stdin.write("y\n")
        if not proc.poll(): proc.stdin.write(Label+"\n")
        while True:
            x = proc.stdout.readline()
            if x:
                print(x)
            else:
                break
    elif  info.MyConf.auto_cp_creation == "STD_USER":
        ans =  common.GetInput('Do You Want to Checkpoint y/[n]:')
        if ans == "y":
            if not proc.poll(): proc.stdin.write("y\n")
            Label = common.GetInput('Please enter label:')
            if not proc.poll(): proc.stdin.write(Label+"\n")
        else:   
            if not proc.poll(): proc.stdin.write("n\n")
        
        while True:
            x = proc.stdout.readline()
            if x:
                print(x)
            else:
                break
    else:
        if not proc.poll(): proc.stdin.write("n\n")
        while True:
            x = proc.stdout.readline()
            if x:
                print(x)
            else:
                break
    if proc.poll():AddErr("Error Creating Checkpoint !!!")
    #print(proc.poll())
def test():
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
        AddErr(formatExceptionInfo())
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    Stand_Alone="STD_ON"
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 