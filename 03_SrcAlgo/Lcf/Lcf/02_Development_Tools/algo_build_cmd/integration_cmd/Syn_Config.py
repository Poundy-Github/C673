"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:51:01CET $

----------------------------------------------------"""
import os
import shlex, subprocess
import sys, getopt
import logging
import sys
import glob
import random
import datetime
from os.path import basename
import pandas as pd
import xlrd
import re
import xml.etree.ElementTree as ET
import os, shutil, stat
from xlwt import Workbook
import xlwt
from copy import deepcopy
from common import Checkout , Checkin , Lock , UnLock , PrintTitel , fprint, Synch
import common
import threading
import info
import timeit

AUTO_CP = "STD_ON"

if AUTO_CP == "STD_ON":
	CP = info.MyInfo.cp
    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD) 
    
MainFile="../06_Algorithm/shared_project_config_files.xml"
logName = "" 
start_time = None
logName=""
EndingErrMeg = []

files = []
ReplaceDic = {}

MainFile = os.path.abspath(MainFile)


LogFile="./log/Build"+os.path.basename(__file__)+".log"
FilesToCheckin = []
MissedLabels = []
OldLabels = []
FoundLabels = []
#sheet1 = (file, "I450-CW08.1.2")
#sheet2 = (file, "I450-CW07.6.1")

def GetFilesToReplace():
    tree = ET.parse(MainFile)
    root = tree.getroot()
    filesConf = root.findall("FileCfg")
    for fileLine in filesConf :
        file = fileLine.get('File')
        file = os.path.dirname(MainFile)+"/"+file
        files.append(file)
    #print(files)

    
def premain():
    global logName
    global  start_time 
    global  Logf
    global  fo
    start_time = timeit.default_timer()
    common.Init()
    if not os.path.exists("log"):
        os.makedirs("log")
    if os.path.isfile(LogFile):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename(LogFile, LogFile.replace(".log","_"+time+".log" ))
    Logf = open(LogFile, "wb+")
    common.fo  = Logf
def postmain():
    global logName
    fprint("#"*30)
    fprint("#"*30)
    if  EndingErrMeg: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    Logf.close()
    if common.fo != None :
        common.fo.close()
    t = timeit.default_timer() - start_time
    m = t/60
    s = t %60
    print("-"*30)
    print("--- %s seconds ---" % (timeit.default_timer() - start_time))
    print("    "+str(m) + " Minutes ")
    print("-"*30)
def main():
    GetFilesToReplace()
    Synch(files)
def Test():
    text="text:u'AL_TSA_WRP_02.080.02_INT-1\\nAL_TSA_RTE_01.12.02\\nAL_TSA_SWSUP_00.00.02'"
    p = re.compile('\\\\n')
    print(p.split(text))
    
premain() 
common.Init()  
main()
postmain()
#Test()