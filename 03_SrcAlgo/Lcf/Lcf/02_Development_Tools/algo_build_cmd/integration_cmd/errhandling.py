"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:44CET $

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
#WD =os.path.abspath(info.MyConf.WD)
#os.chdir(WD) 
#print("WD: "+ WD + " \n ")
logName = "" 
start_time = None
logName=""
EndingErrMeg = " "
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0

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
    if  EndingErrMeg: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    fo.close()
    t = timeit.default_timer() - start_time
    m = t/60
    s = t %60
    print("-"*30)
    print("--- %s seconds ---" % (timeit.default_timer() - start_time))
    print("    "+str(m) + " Minutes ")
    print("-"*30)
    
def main():
    pass
def Container():
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)    
    premain()
    main()
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    Container()
    print(EndingErrLevel , (EndingErrMeg)) 