"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:51:00CET $

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
from common import fprint , fo
import common


CP = info.MyConf.cp
AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp

SEND_CP = "STD_OFF"


logName = "" 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0

fo = None
Stand_Alone="STD_OFF"
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
    
def Configure():
    global CP
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)        
    Build_Command = ".\\run_config.cmd"
    Build_Command = os.path.abspath(Build_Command)
    W = os.path.dirname(Build_Command)
    Build_Command = Build_Command
    print(Build_Command)
    proc=subprocess.Popen([Build_Command,"-b","-C",CP], shell=False,stdin=subprocess.PIPE,stdout=subprocess.PIPE, stderr=subprocess.PIPE,cwd = W)
    if SEND_CP == "STD_ON":
        print("CP used is : "+CP)
        proc.stdin.write(CP+"\n")
    proc.stdin.write("2\n")
    proc.stdin.write("y\n")
    while True:
        x = proc.stdout.readline()
        if x:
            print(x)
        else:
            break
    #stdout_str, stderr_str = proc.communicate()
    #if stdout_str :
        #print("Out: \n" + stdout_str+"\n")
    #if stderr_str:
        #print("Messages: \n"+stderr_str+"\n")
    #stdout_str = proc.communicate(input='2\n')[0]
    #stdout_str = proc.communicate(input='y\n')[0]
    #if stdout_str :
        #print("Out: \n" + stdout_str+"\n")
def premain():
    global logName
    global start_time, logName 
    start_time = timeit.default_timer()
    common.Init()
    logName = os.path.basename(__file__)
    logName = logName.replace(".py", "")
    print("logging :" + logName)
    if not os.path.exists("log"):
        os.makedirs("log")
    global  fo
    if os.path.isfile("./log/"+logName+".log"):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename("./log/"+logName+".log", "./log/"+logName+"_"+time+".log")
    
    fo = open("./log/"+logName+".log", "wb+")
    common.fo = fo
def postmain():
    global logName
    global fo
    common.fo  = fo
    fprint("#"*30)
    fprint("#"*30)
    if  EndingErrLevel != 0: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    fo.close()
    if EndingErrLevel != 0:
        if info.MyConf.fail_safe == "STD_ON":
            FailSafe()
    t = timeit.default_timer() - start_time
    m = t/60
    s = t %60
    print("-"*30)
    print("--- %s seconds ---" % (timeit.default_timer() - start_time))
    print("    "+str(m) + " Minutes ")
    print("-"*30)
def FailSafe():
    pass
def main():
    Configure()
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    os.system("Compare.py")
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    os.system("Post_Config.py")
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    os.system("Check_mod.py")

def test():
    pass    

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
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 