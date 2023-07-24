"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:59CET $

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
#from lxml import etree
import os, shutil, stat
#from xlwt import Workbook
#from xlutils import copy as copy
#import xlutils
#import xlwt
from copy import deepcopy
from common import Email_Address, Checkout , Checkin , Lock , UnLock , PrintTitel , fprint, Synch , dump
import common
import threading
import os, shutil, stat
import timeit
import xml.dom.minidom
from xml.etree.ElementTree import Element, SubElement, Comment, tostring
from xml.etree import ElementTree
from xml.dom import minidom
import CompareXls
import info
AUTO_CP = "STD_ON"

if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
os.chdir(os.path.dirname(os.path.realpath(__file__)))    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD) 
#print(WD)    
MainFile="./04_Engineering/02_Development_Tools/algo_build_cmd/integration_cmd/make_all_tmp.xml"
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
file = "../06_Algorithm/04_Engineering/03_Workspace/algo/make_all.xml"

MainFile = os.path.abspath(MainFile)
file = os.path.abspath(file)

LogFile="./log/Build"+os.path.basename(__file__)+".log"
FilesToCheckin = []
MissedLabels = []
OldLabels = []
FoundLabels = []
NewLabels = []

Stand_Alone="STD_OFF"
Module_Name="Dependency"
Module_Description="Building the make_all.xml file ."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"

#sheet1 = (file, "I450-CW08.1.2")
#sheet2 = (file, "I450-CW07.6.1")
class CP :
    def __init__(self, id):
        self.ID=""
        self.cp=""
        self.rte=""
        self.label = ""
class Release :
    def __init__(self, id):
        self.ID=""
        self.IMID=""
        self.rte=""
        self.label = ""
        self.comment = ""
        
OldCP =    CP(0)
NewCP =    CP(1)
ReleaseInfo = Release(0)
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
    
def prettify(elem):
    """Return a pretty-printed XML string for the Element.
    """
    rough_string = ElementTree.tostring(elem, 'utf-8')
    reparsed = xml.dom.minidom.parseString(rough_string)
    return reparsed.toprettyxml(indent="\t")
    
def GetLinesToWrite(inComps, All="False"):
    #Outroot = ET.Element("xml", version="1.0" , encoding="utf-8")
    #conf = ET.SubElement(Outroot, "BuildConfig")
    os.chmod( file, stat.S_IWRITE )
    EF = open(file, "wb+")
    conf = ET.Element("BuildConfig", encoding="utf-8")
    
    tree = ET.parse(MainFile)
    root = tree.getroot()
    COMPs = root.findall("Component")
    DepSNames = []
    for Comp in COMPs :
        CMPName = Comp.get('name')
        for inComp in inComps:
            if (CMPName in inComp):
                DepSNames.append(Comp.get('sname'))
    if info.MyConf.debug_mode == "STD_ON":print(DepSNames)
    
    C = 0
    for Comp in COMPs :
        CMPName = Comp.get('name')
        CMPBuild = Comp.get('build')
        C = 0
        for inComp in inComps:
            if ((CMPName in inComp and CMPBuild == "STD_ON")or All == "True" ) and C == 0:
                for BuildCfgFile in Comp.getiterator('BuildCfgFile'):
                    #print(Comp.child.tag)
                    #print BuildCfgFile.tag, BuildCfgFile.attrib
                    if BuildCfgFile.attrib["dep"] != None:
                        t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"], dep=BuildCfgFile.attrib["dep"])
                    else:
                        t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"])
                C = C + 1
            else:
                try:
                    #if Comp.find('BuildCfgFile') != None:
                    DependencyList = Comp.find('BuildCfgFile').get("dep").split(",")
                    for x in DependencyList:
                        if x in DepSNames and C == 0:
                            for BuildCfgFile in Comp.getiterator('BuildCfgFile'):
                                t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"], dep=BuildCfgFile.attrib["dep"])
                            C = C + 1    
                except OSError,ValueError:
                    print formatExceptionInfo()
                #C = C + 1
    #Outtree = ET.ElementTree(conf)
    #Outtree = prettify(Outtree)
    #Outtree.write("filename.xml",encoding="UTF-8",xml_declaration=True)
    xmlstr  = ET.tostring(conf, 'utf-8')
    xml1 = xml.dom.minidom.parseString(xmlstr)
    pretty_xml_as_string = xml1.toprettyxml()
    EF.write(pretty_xml_as_string)
    EF.close()
    if info.MyConf.debug_mode == "STD_ON":print(pretty_xml_as_string)
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
    common.fo  = Logf
    fprint("#"*30)
    fprint("#"*30)
    if info.MyConf.debug_mode == "STD_ON":
        if  EndingErrMeg: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    #common.fo.close()
    #Logf.close()
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

def main():
    #t1 = threading.Thread(target=CompareXls.Container)
    #t1.start()
    #t1.join()
    global CP
    global EndingErrLevel, EndingErrMeg
    if CP:CompareXls.CP = CP
    (RetEndingErrLevel , (RetEndingErrMeg)) = CompareXls.Container()
    EndingErrLevel = EndingErrLevel + RetEndingErrLevel
    #EndingErrMeg = EndingErrMeg+"\n"+RetEndingErrMeg
    EndingErrMeg = common.AddLists(EndingErrMeg,RetEndingErrMeg)
    BuildAll = "False"
    if CompareXls.ReleaseInfo.Newrte == "True" or info.MyConf.Build_ALL == "STD_ON":
        BuildAll = "True"
    GetLinesToWrite(CompareXls.CMPs_NAMES, BuildAll)  
    if info.MyConf.debug_mode == "STD_ON":print(CompareXls.CMPs_NAMES)
    
def test():
    common.Init()
    #p = re.compile('\\\\n')
    print(common.Email_Address)
    
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
    common.Init()
    reload(common)
    Container()
    print(EndingErrLevel , (EndingErrMeg)) 