"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:43CET $

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
#from xlwt import Workbook
#from xlutils import copy as copy
#import xlutils
#import xlwt
from copy import deepcopy
from common import Email_Address, Checkout , Checkin , Lock , UnLock , PrintTitel , fprint, Synch , dump , OldCP , NewCP, ReleaseInfo
import common
import threading
import info
import timeit
import check_labels

AUTO_CP = "STD_ON"

if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
Debug_Mode = info.MyConf.debug_mode

#if Debug_Mode == "fake":
    #def Checkin(ListOfFiles,CPLabel=None, Comment=None):
        #pass
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD)     
    
MainFile="../06_Algorithm/shared_project_config_files.xml"
logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0

files = []
ReplaceDic = {}
file = "../06_Algorithm/01_Supporting_Processes/01_Project_Management/05_Release/ModuleOverview.xlsx"

MainFile = os.path.abspath(MainFile)
file = os.path.abspath(file)
Stand_Alone="STD_OFF"
Module_Name="Parse Request"
Module_Description="Parsing the received Module overview sheet"
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"

FilesToCheckin = []
MissedLabels = []
OldLabels = []
FoundLabels = []
NewLabels = []
ModLabels = []
CMPs_NAMES = []
#sheet1 = (file, "I450-CW08.1.2")
#sheet2 = (file, "I450-CW07.6.1")

from optparse import OptionParser
parser = OptionParser()
Email_Address = None
parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="FILE")
(options, args) = parser.parse_args()
if options.__dict__['email_list'] and Stand_Alone=="STD_ON":
    Email_Address = options.__dict__['email_list']
else:
    Email_Address = info.MyConf.default_email
'''
class CP :
    def __init__(self, id):
        self.ID=""
        self.cp=""
        self.rte=""
        self.label = ""
        self.release=""
        self.RO = ""
        self.DevPath = ""
class Release :
    def __init__(self, id):
        self.ID=""
        self.release=""
        self.rte=""
        self.Newrte="False"
        self.label = ""
        self.comment = ""
        self.RO = ""
        self.cp = ""
        self.DevPath = ""
        
OldCP =    CP(0)
NewCP =    CP(1)
ReleaseInfo = Release(0)
'''
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
    
    
def GetFilesToReplace():
    tree = ET.parse(MainFile)
    root = tree.getroot()
    filesConf = root.findall("FileCfg")
    for fileLine in filesConf :
        file = fileLine.get('File')
        file = os.path.dirname(MainFile)+"/"+file
        files.append(file)
    #print(files)
def GetHeader(LineOld, LineNew):
    global ReleaseInfo
    for col in LineOld:
        strcol = str(col)
        if "Algo checkpoint:" in strcol:
            strcol = strcol.replace("Algo checkpoint:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")
            OldCP.label = strcol
        elif "SW RTE:" in strcol:
            strcol = strcol.replace("SW RTE:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")            
            OldCP.rte = strcol
    for col in LineNew:
        strcol = str(col)
        if "Algo checkpoint:" in strcol:
            strcol = strcol.replace("Algo checkpoint:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")            
            NewCP.label = strcol
        elif "SW RTE:" in strcol:
            strcol = strcol.replace("SW RTE:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")            
            NewCP.rte = strcol
        elif "Release:" in strcol:
            strcol = strcol.replace("Release:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")            
            NewCP.release = strcol
        elif "RO:" in strcol:
            strcol = strcol.replace("RO:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")            
            NewCP.RO = strcol
        elif "DevPath:" in strcol:
            strcol = strcol.replace("DevPath:","")
            strcol = strcol.replace(" ","")
            strcol = strcol.replace("text:u","")
            strcol = strcol.replace("'","")            
            NewCP.DevPath = strcol
    ReleaseInfo.rte = NewCP.rte
    ReleaseInfo.label = NewCP.label 
    ReleaseInfo.release = NewCP.release 
    ReleaseInfo.RO = NewCP.RO 
    ReleaseInfo.DevPath = NewCP.DevPath 
    ReleaseInfo.comment =  "HAI: Highly automated integration \n"
    ReleaseInfo.comment =  ReleaseInfo.comment +"----------------------------- \n"
    ReleaseInfo.comment =  ReleaseInfo.comment +"Label = "+ReleaseInfo.label +"\n"
    ReleaseInfo.comment = ReleaseInfo.comment +"RTE   = "+ReleaseInfo.rte +"\n"
    ReleaseInfo.comment = ReleaseInfo.comment +"Release   = "+ReleaseInfo.release +"\n"
    ReleaseInfo.comment = ReleaseInfo.comment +"RO   = "+ReleaseInfo.RO +"\n"
    if NewCP.rte  != OldCP.rte:
        ReleaseInfo.Newrte = "True"
    if info.MyConf.debug_mode == "STD_ON":dump(ReleaseInfo)
    
def parseXLS():
 xls = xlrd.open_workbook(file, encoding_override="cp1252")
 global CMPs_NAMES 
 global ModLabels
 CMP_NAME = ""
 #w_sheet = deepcopy(xls.get_sheet(0))
 #new_book = xlwt.Workbook()
 #test = new_book.add_sheet('TEST')
 #copy_sheet1 = xls.sheet_by_index(0)
 #copy_sheet2 = xlutils.copy(copy_sheet1)
 
 

 SheetNew =  xls.sheet_names()[0]
 SheetOld =  xls.sheet_names()[1]
 #shutil.copy2(src, dst)
 print("#"*30)
 print("New  Config :"+SheetNew)
 print("Base Config :"+SheetOld)
 print("#"*30)

 #print(file, SheetOld)
 #df1 = pd.read_excel(file, SheetOld, na_values=['NA'])
 #df2 = pd.read_excel(file, SheetNew, na_values=['NA'])
 XOld = xls.sheet_by_name(SheetOld)
 XNew = xls.sheet_by_name(SheetNew)
 #print (xls.sheet_by_name(SheetOld))
 #print(xls.sheet_by_name(SheetNew).row(3))
 #print(df1)
 df1_lines = []
 df2_lines = []
 
 for row_idx in range(0, XOld.nrows):
    df1_lines.append(XOld.row(row_idx))
    df2_lines.append(XNew.row(row_idx))
 #print(str(df1_lines[0]))
 GetHeader(df1_lines[0], df2_lines[0])
 
 #print(len(df1_lines))
 LineIndex = 2
 p = re.compile('\\\\n+|\s')
 for line in df1_lines:
    #print(df1_lines[LineIndex])
    #print(df2_lines[LineIndex])
    #print(LineIndex)
    if LineIndex >= len(df1_lines):
        break
    if df1_lines[LineIndex] != df2_lines[LineIndex]:
        
        #common.PrintList(df1_lines, "OLD LInes")
        #print(df2_lines[LineIndex])
        df1_line = (df1_lines[LineIndex])
        df2_line = (df2_lines[LineIndex])
        
        CellIndex = 0
        if df1_line and df2_line:
            #print(df1_line)
            for Col in df1_line:
                #print(Col)
                #print(df1_line[CellIndex])
                #entry1 = str(df1_line[CellIndex]).split()
                #entry2 = str(df2_line[CellIndex]).split()
                if not ((CellIndex == 2) or (CellIndex == 3)):
                    CellIndex = CellIndex +1
                    continue
                st1 = str(df1_line[CellIndex]).strip()
                st2 = str(df2_line[CellIndex]).strip()
                #if "TSA" in st1:
                    #print(st1, st2)
                    
                st1 = st1.replace("'","")
                st2 = st2.replace("'","")    
                st1 = st1.strip("\\\\n")
                st2 = st2.strip("\\\\n")
                st1 = st1.strip("\n")
                st2 = st2.strip("\n")
                #if "TSA" in st1:
                    #print(st1, st2)
                #print(st1, st2)
                entry1 = p.split(st1)
                entry2 = p.split(st2)
                CMP_NAME = df1_line[0]
                entry1 = filter(None, entry1)
                entry2 = filter(None, entry2)
                #print(entry2)
                #df1_line[CellIndex] = df1_line[CellIndex].replace("text:u","")
                #df2_line[CellIndex] = df2_line[CellIndex].replace("text:u","")
                try:
                    #if df1_line[CellIndex] != df2_line[CellIndex] and not("CW" in df1_line[CellIndex]) and (df1_line[CellIndex] != OldCP.label) :
                    if (str(df1_line[CellIndex]) != str(df2_line[CellIndex])) and not("CW" in str(df1_line[CellIndex])) and ((str(df1_line[CellIndex])) != OldCP.label) and not("Algo checkpoint" in str(df1_line[CellIndex])) and not("DevPath:" in str(df1_line[CellIndex]) ):
                        #print("|"*30)
                        #print(df1_line[CellIndex])
                        #print(df2_line[CellIndex])
                        #print(entry1)
                        CellEntryIndex = 0
                        if len(entry1) == len(entry2):
                            
                            for entry in entry1:
                                if info.MyConf.debug_mode == "STD_ON":print("CellEntryIndex : "+ str(CellEntryIndex))
                                if entry1[CellEntryIndex] != entry2[CellEntryIndex] :
                                    T1 = str(entry1[CellEntryIndex]).replace("text:u","")
                                    T1 = T1.replace("'","")
                                    T1 = T1.strip()
                                    T1 = T1.strip("\\n")
                                    T1 = T1.replace("\\n","")
                                    T2 = str(entry2[CellEntryIndex]).replace("text:u","")
                                    T2 = T2.replace("'","")
                                    T2 = T2.strip()
                                    T2 = T2.strip("\\n")
                                    T2 = T2.replace("\\n","")
                                    ReplaceDic[T1] = (T2, "NO", "")
                                    ModLabels.append(T2)
                                    #print(CMP_NAME)
                                    CMP_NAME1 = str(CMP_NAME).replace("text:u","")
                                    CMP_NAME1 = CMP_NAME1.replace("'","")
                                    CMP_NAME1 = CMP_NAME1.strip()
                                    CMP_NAME1 = CMP_NAME1.replace("\\n","")
                                    #print(CMP_NAME)
                                    #print("**"*60)
                                    CMPs_NAMES.append(CMP_NAME1)
                                CellEntryIndex = CellEntryIndex + 1
                        else:
                            T1 = str(df1_line[CellIndex]).replace("text:u","")
                            T1 = T1.replace("'","")
                            T1 = T1.replace(" ","")
                            T1 = T1.replace("\\n","")
                            T2 = str(df2_line[CellIndex]).replace("text:u","")
                            T2 = T2.replace("'","")
                            T2 = T2.replace(" ","")
                            T2 = T2.replace("\\n","")
                            #print(T1)
                            #print(T2)
                            ReplaceDic[T1] = (T2, "NO", "")
                        #LogFunc("-"*30)
                except ValueError:
                    print str(ValueError)
                CellIndex = CellIndex +1
    LineIndex = LineIndex +1
 CMPs_NAMES = common.ListRemoveduplication(CMPs_NAMES)
 if info.MyConf.debug_mode == "STD_ON":print(CMPs_NAMES)
 #xls.close()
 #print(ReplaceDic)       

def ReplaceInXml():
    Synch(files)
    Checkout(files)
    for file in files:
        dst = file.replace("xml", "xml.bak")
        os.chmod( file, stat.S_IWRITE )
        if os.path.isfile(dst):
            os.remove(dst)
        shutil.copyfile(file, dst)
        fb = open(dst, "rb")
        data=fb.read()
        m = 1
        fo = None
        if any(ext in data for ext in list(ReplaceDic.keys())):
            fo = open(file, "wb")
        for line in data.split("\\n"):
            for key in ReplaceDic:
                listtemp = list(ReplaceDic[key])
                t1 = str(key).replace("'","")
                t1 = t1.replace("\n","")
                #print("Searching in  : " + file)
                #print(line)
                if "\""+t1+"\"" in line:
                    #listtemp = list(ReplaceDic[key])
                    line = line.replace("\""+key+"\"", "\""+listtemp[0]+"\"")
                    listtemp[1] = "YES"
                    listtemp[2] = file
                    ReplaceDic[key] = tuple(listtemp)
                    if info.MyConf.debug_mode == "STD_ON":
                        LogFunc("-"*30)
                        print(key+" found in "+ file + " :")
                        print("replaced with "+ ReplaceDic[key][0])
                        LogFunc("-"*30)
                        m = m +1
                elif "\""+str(listtemp[0])+"\"" in line:
                    #listtemp = list(ReplaceDic[key])
                    listtemp[1] = "Dup"
                    listtemp[2] = file
                    ReplaceDic[key] = tuple(listtemp)
                    print("Label "+str(listtemp[0]) +" Already available in :\n")
                    #print(file)        
            if fo: fo.write(line)    
                        
                                
        if fo: fo.close()
        fb.close()
        os.remove(dst)
        #print(ReplaceDic)
def Report():
    global MissedLabels
    global OldLabels
    global FilesToCheckin
    global FoundLabels
    global NewLabels
    global files
    global file
    global ReleaseInfo
    if info.MyConf.debug_mode == "STD_ON":print(files)
    for key in ReplaceDic:
        if ReplaceDic[key][1] == "YES":
            FilesToCheckin.append(ReplaceDic[key][2])
            FoundLabels.append(key)
            NewLabels.append(ReplaceDic[key][0])
        elif  ReplaceDic[key][1] == "Dup":
            OldLabels.append(ReplaceDic[key][0])
        else:
            MissedLabels.append(key)
    FilesToCheckin = list(set(FilesToCheckin))
    print(FilesToCheckin)
    MissedLabels = list(set(MissedLabels))
    n = 1
    if NewLabels:
         print("#"*30)
         print("New Labels found "+str(len(NewLabels))+"/"+str(len(ReplaceDic)) + " Ones :")
         for label in NewLabels:
            t = str(n)+": "+label
            ReleaseInfo.comment = ReleaseInfo.comment + t+ "\n"
            print(t)
            
            n = n + 1
    n =1
    if OldLabels:
         print("#"*30)
         LineErrMeg = "Old Labels  "+str(len(OldLabels))+"/"+str(len(ReplaceDic)) + " Ones :"
         print(LineErrMeg)
         if info.MyConf.old_labels_check == "STD_ON":
             if not NewLabels:
                AddErr(LineErrMeg) 
         for label in OldLabels:
            print(str(n)+": "+label)
            n = n + 1
    n = 1     
    if MissedLabels:
        print("#"*30)
        LineErrMeg = "Labels Missed "+str(len(MissedLabels))+"/"+str(len(ReplaceDic)) + " Ones :"
        print(LineErrMeg)
        if info.MyConf.missed_labels_check == "STD_ON":
            AddErr(LineErrMeg)
        else:
            print("Missed labels Error will be bypassed, based on the current configuration ..")
        for label in MissedLabels:
            print(str(n)+": "+str(label))
            n = n + 1
        Out=common.GetInput('Not All labels found, DO YOU WANT TO CONTINUE ? [y/N]:')
        if Out == "y":
            if not FilesToCheckin:
                print("No files to Checkin !!!")
            else:
                print("Files to check in are "+str(len(FilesToCheckin))+ " Ones :")
                n = 1
                for fileLoop in FilesToCheckin:
                    print(str(n)+": "+fileLoop)
                Checkin(FilesToCheckin, ReleaseInfo.label, ReleaseInfo.comment )
                Synch(files)
                UnLock(files)
                if info.MyConf.AUTO_XLS == "STD_ON":
                    Checkin([file],  ReleaseInfo.label, ReleaseInfo.comment) 
                    UnLock([file])

    else:
        if FilesToCheckin:
            if info.MyConf.update_cfg_files == "STD_ON":Checkin(FilesToCheckin, ReleaseInfo.label, ReleaseInfo.comment )
            #print(ReleaseInfo.comment)
            if info.MyConf.AUTO_XLS == "STD_ON":
                Checkin([file], ReleaseInfo.label, ReleaseInfo.comment) 
            

        if info.MyConf.update_cfg_files == "STD_ON":Synch(files)
        UnLock(files)
        if info.MyConf.AUTO_XLS == "STD_ON":
            UnLock([file])
    #if FilesToCheckin and not MissedLabels:
        #Checkin(FilesToCheckin)
        #Synch(files)
        #UnLock(files)
    #elif not MissedLabels:
        #Synch(files)
        #UnLock(files)
def OpenXls():
    dst = file.replace("xlsx", "bak.xlsx")
    shutil.copyfile(file, dst)
    Checkout([file])  
    Build_Command =  file 
    proc=subprocess.Popen(Build_Command, shell=True)
    Out=common.GetInput('Please Modify the Module overview and save, DO YOU WANT TO CONTINUE ? [Y/n]:')
    if Out == "n":
        postmain()
        sys.exit()
def premain():
    global logName
    global  start_time 
    global  Logf
    global  fo
    common.Init()
    start_time = timeit.default_timer()
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
    if info.MyConf.debug_mode == "STD_ON":
        if  EndingErrMeg: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    #common.fo.close()
    #Logf.close()
    os.chdir(os.path.dirname(os.path.realpath(__file__)))
    #if common.fo != None :
        #common.fo.close()
    t = timeit.default_timer() - start_time
    m = t/60
    s = t %60
    LogFunc("-"*30)
    LogFunc("--- %s seconds ---" % (timeit.default_timer() - start_time))
    LogFunc("    "+str(m) + " Minutes ")
    LogFunc("-"*30)
    common.fo.close()
    Logf.close()
    if info.MyConf.step_email_notification == "STD_ON":
        common.ActivityReportMail(aModule_Name=Module_Name, aModule_Description=Module_Description,aEndingErrLevel=EndingErrLevel,alogName=LogFile,aTimeConsumption=m,aEmail_Address=common.Email_Address)
def FailSafe():
    pass
def main():
    if info.MyConf.AUTO_XLS == "STD_ON":
        OpenXls()
    else:
        Synch([file])
    parseXLS()
    if check_labels.checkLabs(ModLabels):
        if info.MyConf.debug_mode == "STD_ON": print(ModLabels)
        AddErr("labels not correct !!!")
        print("Err: labels not correct !!!")
        return
    if info.MyConf.update_cfg_files == "STD_ON" or info.MyConf.update_cfg_files == "STD_AUTO" :
        GetFilesToReplace()
        ReplaceInXml()
        Report()
    #print(ReplaceDic)
def test():
    text="text:u'AL_TSA_WRP_02.080.02_INT-1\\nAL_TSA_RTE_01.12.02\\nAL_TSA_SWSUP_00.00.02'"
    p = re.compile('\\\\n')
    print(p.split(text))
    
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