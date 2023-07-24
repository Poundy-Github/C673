"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:59CET $

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
import re
tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
import mks_utils
from mks_utils import ProgressBar_obj



FoldersToSynch = [".\\04_Engineering\\01_Source_Code\\", ".\\04_Engineering\\03_Workspace\\", ".\\04_Engineering\\05_Deliverables\\",".\\04_Engineering\\02_Development_Tools\\scons_tools\\", ".\\04_Engineering\\04_Build\\algo\\vdy_sim\\"]
ScriptsToInvoke = [".\\04_Engineering\\03_Workspace\\algo\\make_all_ecu.cmd",".\\04_Engineering\\03_Workspace\\algo\\make_all_sim.cmd",".\\04_Engineering\\03_Workspace\\algo\\make_all_vis.cmd"]
FilesNotToSynch = [".\\04_Engineering\\03_Workspace\\algo\\make_all.xml"]
FoldersToBeRemoved = [".\\04_Engineering\\04_Build\\algo"]

CLEAN = info.MyConf.CLEAN
Rebuild = info.MyConf.Rebuild
Build_Options=info.MyConf.Extra_Build_Options
if Rebuild == "STD_ON":
    Build_Options =Build_Options+ " -r "

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
Stand_Alone="STD_OFF"
Module_Name="BUILD"
Module_Description="Building the latest configured source-code ."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"

EndingErrLevel = 0
def RemoveFolders():
    for folder in FoldersToBeRemoved:
        folder = os.path.abspath(folder)
        if os.path.isdir(folder):
            try:
                shutil.rmtree(folder, ignore_errors=True)
            except ValueError:
                print("Could not delete folder :"+folder)
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
    global  start_time 
    global  Logf
    global  fo
    start_time = timeit.default_timer()
    common.Init()
    if not os.path.exists("log"):
        os.makedirs("log")
    if os.path.isfile("./log/Build.log"):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename("./log/Build.log", "./log/Build_"+time+".log")
    Logf = open("./log/Build.log", "wb+")
    common.fo  = Logf
def postmain():
    global logName
    LogFunc("#"*30)
    LogFunc("#"*30)
    if  EndingErrLevel != 0: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    #Logf.close()
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
    Logf.close()
    if info.MyConf.step_email_notification == "STD_ON":
        common.Init()
        common.ActivityReportMail(aModule_Name=Module_Name, aModule_Description=Module_Description,aEndingErrLevel=EndingErrLevel,alogName=LogFile,aTimeConsumption=m,aEmail_Address=common.Email_Address)
    
def Kprint(Mess):
    print(Mess+"\n")
    Logf.write(Mess+"\n")
    
def Fprint(Mess):
    Logf.write(Mess+"\n")
def PreSynch():
    for file in FilesNotToSynch:
        file = os.path.abspath(file)
        if os.path.isfile(file):
            if os.path.isfile(file+".bak"):
                os.chmod(file+".bak", stat.S_IWRITE)
            shutil.copy2(file, file+".bak")


def PostSynch():
    for file in FilesNotToSynch:
        file = os.path.abspath(file)
        os.chmod(file, stat.S_IWRITE)
        if os.path.isfile(file+".bak"):
            shutil.copy2(file+".bak", file)
        
def SynchAll():
    PreSynch()
    BAR_MAX = len(FoldersToSynch)
    print("Synchronization ...")
    if BAR_MAX != 0 and info.MyConf.debug_mode == "STD_OFF":
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
    for folder in FoldersToSynch:
        folder = os.path.abspath(folder)
        folder = folder + "/project.pj"
        Build_Command = "si resync --overwriteChanged -R -Y "+folder
        if info.MyConf.debug_mode == "STD_ON":
            Kprint("Synch Project : "+ folder+" ...")
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()

        else:
            fprint("Synch Project : "+ folder+" ...")
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()              
            BAR.increment_amount()
            BAR.display()

        if stdout_str :
            fprint("Out: \n" + stdout_str+"\n")
                
        if stderr_str:
            fprint("Messages: \n"+stderr_str+"\n")
    PostSynch()
    
def BuildAll():
    BAR_MAX = len(ScriptsToInvoke)
    print("Building ...")
    if BAR_MAX != 0 and info.MyConf.debug_mode == "STD_OFF":
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
    e = 0
    for Script in ScriptsToInvoke:
        Script = os.path.abspath(Script)
        Build_Command = Script+"  " + Build_Options +"  "
        if info.MyConf.debug_mode == "STD_OFF":
            Fprint("Building  : "+ Script+Build_Options +" ...")
        else:
            Kprint("Building  : "+ Script+Build_Options +" ...")
        BaseFolder = os.path.dirname(Script)
        abspath = os.path.abspath(__file__)
        dname = os.path.dirname(abspath)
        proc=subprocess.Popen(Build_Command, shell=True,stdin=subprocess.PIPE,stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=BaseFolder)
        stdout_str  = proc.communicate(input='Enter \n')[0]
        if info.MyConf.debug_mode == "STD_OFF":
            BAR.increment_amount()
            BAR.display()
        if stdout_str :
            if info.MyConf.debug_mode == "STD_OFF":Fprint("Out: \n" + stdout_str+"\n")
            else:Kprint("Out: \n" + stdout_str+"\n")
        error_c = re.compile("\s+Error:.*", re.U)
        warning_c = re.compile("(:)\s+(warning)", re.U)
        error_warnings = error_c.findall(stdout_str)
        if error_warnings:
            for l in error_warnings:
                AddErr(str(l))
            #print("Building : " + Script+" NOK!!! ")
            txt = "Building : " + Script+" NOK!!! "
            if info.MyConf.debug_mode == "STD_OFF":Fprint(txt)
            else:Kprint(txt)
            e = e + 1
            if info.MyConf.check_build == "STD_ON":
                break
        else :
            #print("Building :" + Script+" OK!!! ")
            txt = "Building : " + Script+" OK!!! "
            if info.MyConf.debug_mode == "STD_OFF":Fprint(txt)
            else:Kprint(txt)
    if e == 0:
        print("Building: OK !!!\n")
    else:
        print("Building: NOK !!!, See log file ... \n")
        
def main():
    if CLEAN == "STD_ON":
        RemoveFolders()
    SynchAll()
    BuildAll()
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