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
    x = logName.split(".")
    if x: logName = x[0]
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
    if  EndingErrLevel != 0 and Stand_Alone=="STD_ON" : common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    
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
    pass
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