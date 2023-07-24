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
import glob
from os.path import basename
import info
import msvcrt
import logging
from optparse import OptionParser
import shutil, errno, distutils.dir_util
import re

tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
from lotus_notes_tools.send_email import lotus_notes_send_email_obj

tt = os.path.join(os.path.dirname(__file__), '..\\..\\mks_tools')
sys.path.append(tt)
import mks_utils, stat
from mks_utils import ProgressBar_obj

fo = None 
MessageDic = {}            
DEFAULT_STRING = "default"
class ACheckinType(object):
    def __init__(self, id):
        self.ID=""
        self.Files=[]
        self.Label = None
        self.Comment = None
        
        
        
ACheckin = ACheckinType(0)
ACheckin.Files = []
ACheckin.Label = None
ACheckin.Comment = None

AUnlockFiles = []

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

Session_ID = str(os.getpid())
Email_Address = None
parser = OptionParser()
parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="FILE")
#(options, args) = parser.parse_args()
#print(options)
'''if options.__dict__['email_list']:
    Email_Address = options.__dict__['email_list']
else:
    Email_Address = info.MyConf.default_email
'''
class email_Att(object):
    def __init__(self, id):
        self.ID=""
        self.recipients=[]
        self.CCrecipients=[]
        self.subject=""
        self.body = ""
        self.attachments=[]

My_email = email_Att(0)
lotus_notes_email = lotus_notes_send_email_obj()        
AUTO_CP = "STD_ON"
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp

DescriptionFile = "./Desc.txt"
DescriptionFile = os.path.abspath(DescriptionFile)

#if info.MyConf.debug_mode == "STD_ON":LogFunc = kprint
#else:LogFunc = kprint
def Init():
    global parser
    global options
    global args
    global Email_Address
    parser = OptionParser()
    parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="FILE")
    (options, args) = parser.parse_args()
    #print(options)
    if options.__dict__['email_list']:
        Email_Address = options.__dict__['email_list']
    else:
        Email_Address = info.MyConf.default_email
def CheckMKSError(Mess):
    ret=0
    p = re.compile('mks\d+:', re.IGNORECASE)
    m= p.match(Mess)
    if m: ret=1
    
    return ret
def getSubdirs(abs_path_dir) :  
    #lst = [ name for name in os.listdir(abs_path_dir) if os.path.isdir(os.path.join(abs_path_dir, name)) and name[0] != '.' ]
    lst=[]
    for name in os.listdir(abs_path_dir):
        if os.path.isdir(os.path.join(abs_path_dir, name)) and name[0] != '.':
            if lst:
                lst.append(str(abs_path_dir)+'/'+str(name))
            else:
                lst=[str(abs_path_dir)+'/'+str(name)]
            
    lst.sort()
    return lst

def getSubdirsRecursive(abs_path_dir) :  
    #lst = [ name for name in os.listdir(abs_path_dir) if os.path.isdir(os.path.join(abs_path_dir, name)) and name[0] != '.' ]
    lst=[]
    temp = os.listdir(abs_path_dir)
    if not temp:
        return lst
    for name in temp:
        if os.path.isdir(os.path.join(abs_path_dir, name)) and name[0] != '.':
            #print(name)
            if lst:
                lst.append(str(abs_path_dir)+'/'+str(name))
            else:
                lst=[str(abs_path_dir)+'/'+str(name)]
            w = os.path.join(abs_path_dir, os.path.basename(name))
            #print("Recursive ")
            #print(w)
            x = getSubdirsRecursive(w)
            if     x:
                for y in x:
                    lst.append(str(y))
    lst = list(set(lst))
    #print(lst)
    lst.sort()
    #print(lst)
    return lst
    
def List2Str(List, Seprator):
    returnStr = " "
    for x in List:
        returnStr = returnStr + Seprator+x
        
    return(returnStr)

def ListRemoveduplication(inList):
    outList = []
    for mem in inList:
        if inList.count(mem) > 1:
            inList.remove(mem)
    inList.sort()
    return(inList)

def AppendListGroup(ListGroup):
    outlist = []
    for List in ListGroup:
        for mem in List:
            outlist.append(mem)
    return outlist        
def MergLists(ListGroup):
    List = AppendListGroup(ListGroup)
    List = ListRemoveduplication(List)
    return(List)

def checkExistance(lst):
    Outlst = []
    for folder in lst:
        if os.path.exists(folder):
            Outlst.append(folder)
    return (Outlst)
    
def ORStr(x, y):
    outstr = x
    outlst = list(x)
    for i in range(50):
        outlst.append(" ")
    #for index in range(len(x)):
        #if x[index] != " ":
            #outstr[index] = x[index] 
    s = list(y)
    for index in range(len(y)):
        if y[index] != " ":
            outlst[index] = s[index]
    outstr ="".join(outlst)            
    return (outstr)
    
def fprint(text):
    if fo:
        fo.write(text)
        fo.write("\n")
    else:
        print(text)
def iprint(text):
    fo.write(str(text)+"\n")
    print(str(text))
def kprint(text):
    fo.write(str(text)+"\n")
    logging.info("\n"+str(text)+"\n")
    print(str(text))    
    
if info.MyConf.debug_mode == "STD_ON":LogFunc = kprint
else:LogFunc = fprint
    
def FixedLengStr(str, l):
    StrOut = str
    l1 = len(str)
    if l > l1:
        StrOut = str + " "*(l-l1)
    return StrOut

def PrintTitel(text):
    M = 60
    L = len(text)
    N = M - L
    T = N/2
    kprint("*"*M)
    kprint("*"*T+" "*L+"*"*T)
    kprint("*"*T+text+"*"*T)
    kprint("*"*T+" "*L+"*"*T)
    kprint("*"*M)

def PrintList(vlist, Text):
    PrintTitel(Text)
    n =1
    for m in vlist:
        kprint(str(n) +": "+ str(m))
        n = n +1
    
def Checkout(ListOfFiles):
    BAR_MAX = len(ListOfFiles)
    if BAR_MAX != 0:BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed');BAR.display()
    for file in ListOfFiles:
        Build_Command = "si co --yes --changePackageId="+CP+" "+file
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        MessageDic[file] = stdout_str
        if info.MyConf.debug_mode != "STD_ON":BAR.increment_amount();BAR.display();
        if stdout_str:
            if info.MyConf.debug_mode == "STD_ON":kprint(stdout_str)
            else:fprint(stdout_str)
        if stderr_str:
            if info.MyConf.debug_mode == "STD_ON":kprint(stderr_str)
            else:fprint(stderr_str)
    for key, value in MessageDic.iteritems():
        TextAll = "Checking Out :: "+key+" ->"+value
        #print(value)
Debug_Mode = info.MyConf.debug_mode

if Debug_Mode == "Fake":
    def Checkin(ListOfFiles,CPLabel=None, Comment=None):
        pass
else:    
    def Checkin(ListOfFiles,CPLabel=None, Comment=None):
        if not ListOfFiles:return
        global DescriptionFile
        if info.MyConf.debug_mode == "STD_ON":PrintTitel("Checkin");
        else: 
            LogFunc("Checkin...")
            BAR_MAX = len(ListOfFiles)
            BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
            BAR.display()
        
        fd=open(DescriptionFile, 'w')
        DescriptionFile = DescriptionFile.replace("\\", "/")
        global Label
        if Comment == None or CPLabel == None:
            Label=common.GetInput('Please enter a Label, [-] for Escaping Chickin:')
            Comment = Label
            CPLabel = Label
        else:
            Comment = str(Comment)
            CPLabel = str(CPLabel)
        fd.write(Comment)
        fd.close()
        if CPLabel == "-":
            kprint("Checkin has been canceled ....")
            return
        for file in ListOfFiles:
            
            Build_Command = "si ci --update --changePackageId="+CP+" --yes "+" --label="+CPLabel+" --descriptionFile="+DescriptionFile+" "+file
            #print(Build_Command)
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            if info.MyConf.debug_mode == "STD_OFF":BAR.increment_amount();BAR.display()
            MessageDic[file] = stdout_str
            #print(stdout_str)
            LogFunc(stderr_str)
        for key, value in MessageDic.iteritems():
            TextAll = "Checking in :: "+key+" ->"+value
            #print("wfwfw")  
        #fd.close()
def Lock(ListOfFiles):
    if not ListOfFiles:return
    if info.MyConf.debug_mode == "STD_ON":PrintTitel("Lock");
    else: 
        LogFunc("Lock...")
        BAR_MAX = len(ListOfFiles)
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
    
    for file in ListOfFiles:
        Build_Command = "si lock --changePackageId="+CP+" "+file
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if info.MyConf.debug_mode == "STD_OFF":BAR.increment_amount();BAR.display()
        MessageDic[file] = stderr_str
        if info.MyConf.debug_mode == "STD_ON":kprint(stderr_str)
        else:fprint(stderr_str)
    for key, value in MessageDic.iteritems():
        TextAll = "Locking :: "+key+" ->"+value
        #print(value)
    
def UnLock(ListOfFiles):
    if not ListOfFiles:return
    if info.MyConf.debug_mode == "STD_ON":PrintTitel("UnLock");
    else: 
        LogFunc("UnLock...")
        BAR_MAX = len(ListOfFiles)
        BAR = ProgressBar_obj(0, BAR_MAX, 60, mode='fixed')
        BAR.display()
        
    BAR_MAX = len(ListOfFiles)
    for file in ListOfFiles:
        Build_Command = "si unlock --action=remove " +file
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if info.MyConf.debug_mode == "STD_OFF":BAR.increment_amount();BAR.display()
        if info.MyConf.debug_mode == "STD_ON":kprint(stderr_str)
        else:fprint(stderr_str)
        MessageDic[file] = stderr_str
    for key, value in MessageDic.items():
        TextAll = "UnLocking :: "+key+" ->"+value
        #print(value)
#ACheckin.Files = []
#ACheckin.Label = None
#ACheckin.Comment = None

#AUnlockFiles = []

def SACheckin(ListOfFiles,CPLabel=None, Comment=None):
    ACheckin.Files = AddLists(ACheckin.Files, ListOfFiles)
    if not ACheckin.Label and CPLabel:
        ACheckin.Label = CPLabel
    if not ACheckin.Comment and Comment:
        ACheckin.Comment = Comment
        
        
def EACheckin():
    Checkin(ACheckin.Files,ACheckin.Label, ACheckin.Comment)
    
def SAUnLock(ListOfFiles):    
    AUnlockFiles = AddLists(AUnlockFiles, ListOfFiles)
    
    
def EAUnLock():
    UnLock(AUnlockFiles)
    
    
    
def Synch(ListOfFiles):
    for folder in ListOfFiles:
        folder = os.path.abspath(folder)
        folder = folder 
        Build_Command = "si resync --overwriteChanged -R -Y "+folder
        if info.MyConf.debug_mode == "STD_ON":kprint("Synch Project : "+ folder+" ...")
        else:fprint("Synch Project : "+ folder+" ...")
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            fprint("Out: \n" + stdout_str+"\n")
                
        if stderr_str:
            fprint("Messages: \n"+stderr_str+"\n")

def dump(obj):
   print("#"*30)
   for attr in dir(obj):
       if hasattr( obj, attr ):
           if attr != "__doc__" and attr != "__init__" and attr != "__module__" and "__" not in attr:
               LogFunc("-"*30)
               print( "obj.%s = %s" % (attr, getattr(obj, attr)))
               LogFunc("-"*30)
               
def CompLst(s, b):
    ret = 0
    lst = []
    for i in s:
        if i in b:
            continue
        else:
            ret = ret + 1
            lst.append(i)
            #break
    return(ret, lst)
    
def AddLists(A, B):
    for x in B:
        A.append(x)
    return(A) 

def CreateCP(issue):
        ret = "default"
        Build_Command = "im editissue --field=state=\"in work\"  "+issue
        kprint("Open RO : "+ issue+" ...")
        #print(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            fprint("Out: \n" + stdout_str+"\n")
                
        if stderr_str:
            fprint("Messages: \n"+stderr_str+"\n")
        Build_Command = "si createcp  --issueId="+issue
        kprint("Create Change package : "+ issue+" ...")
        #print(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            kprint("Out: \n" + stdout_str+"\n")
                
        if stderr_str:
            kprint("Messages: \n"+stderr_str+"\n")
            #if CheckMKSError(stderr_str):ret = 
        if  "Created new change package" in  stderr_str:
            ret = stderr_str.replace("Created new change package", "")
            ret = ret.replace(" ", "")
            ret = ret.strip("\n")
        #print(ret)    
        return(ret)

def GetCP(issue):
    ret = "default"
    #print(issue)
    for ChangPack in info.MyInfo.cpList:
        #print(ChangPack)
        if issue in ChangPack:
            #print(ChangPack)
            ret = ChangPack
            kprint("Changepackage Available :"+ret)
            break
    if ret == "default":
        ret = CreateCP(issue)
    return(ret)
        
def CloseCP(CP):
        Build_Command = "si closecp --noconfirm --noreleaseLocks "+CP
        kprint("Closing Changepackage  : "+ CP+" ...")
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            fprint("Out: \n" + stdout_str+"\n")
                
        if stderr_str:
            fprint("Messages: \n"+stderr_str+"\n")            
            return(1)
            
        return(0)

def GetInput(txt):
    x = DEFAULT_STRING 
    while msvcrt.kbhit():
        msvcrt.getch()
    try:    
        x = raw_input(txt)
    except ValueError: 
        print str(ValueError)
    return(x)   

def SendMAil(My_email=My_email):
    lotus_notes_email.__init__()
    lotus_notes_email.sendEmail( My_email.recipients, My_email.subject, My_email.body, My_email.attachments, cc=My_email.CCrecipients)

def ReportMail(My_email=My_email):
    Init()
    if  info.MyConf.send_email == "STD_ON":
        SendMAil(My_email=My_email)
    
def ActivityReportMail(aModule_Name="", aModule_Description="",aEndingErrLevel=0,alogName="",aTimeConsumption=0, aEmail_Address=Email_Address, FreeTXT = ""):
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)    
    logfile = os.path.abspath(alogName)
    #print(logfile)
    Init()
    My_email = email_Att(1)
    My_email.attachments = [logfile]
    if (aEndingErrLevel != 0) :
        Status = "NOK ---"
    else:
        Status = "OK  +++"
    My_email.recipients = aEmail_Address.split(",")
    My_email.CCrecipients = info.MyConf.admin_email.split(",")
    My_email.subject = "HAI: "+ReleaseInfo.label+" : Activity: "+aModule_Name+" " +Status 
    My_email.body = "Hi All,\n\nActivity info like below:\n ___________________________\n"
    My_email.body = My_email.body +"DevPath: "+info.CurrentSandBox.DevPath+"\n\n"
    My_email.body = My_email.body +"Module Name: "+aModule_Name+"\n\n"
    My_email.body = My_email.body +"Module Description: "+aModule_Description+"\n\n"
    My_email.body = My_email.body +"Consumed time: "+str(aTimeConsumption)+" Minutes \n\n"
    My_email.body = My_email.body +"Status : "+Status+"\n"
    My_email.body = My_email.body +"Session ID : "+Session_ID+"!!! \n"
    My_email.body = My_email.body +FreeTXT+" \n"
    
    
    ReportMail(My_email)
def Test():    
    My_email.recipients = info.MyConf.default_email.split(",")
    My_email.subject = "Test mail"  
    My_email.body = "I am a testing mail"
    ReportMail()
    
def GenericCopy(src, dst):
    try:
        ##shutil.rmtree(dst)
        #shutil.copytree(src, dst, symlinks=False, ignore=None)
        for root, dirs, files in os.walk(dst):
            for fname in files:
                full_path = os.path.join(root, fname)
                os.chmod(full_path ,stat.S_IWRITE)
        #os.chmod( dst, stat.S_IWRITE )
        distutils.dir_util.copy_tree(src, dst)
    except OSError as exc: # python >2.5
        if exc.errno == errno.ENOTDIR:
            shutil.copy(src, dst)
        else: raise
def RunCommand(cmdline_info):
    proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    if stderr_str: print (stderr_str)
    return(stdout_str, stderr_str) 
    
    
def GetRevisionForLabel(SharedProject, Label):
        """
        GetRevisionForLabel( SharedProject, Label)

        Description: Get the revision corresponding to a label

        Parameter: -SharedProject the path from where the shared project is shared
                   -Label serach the revision to this label

        return 0 if label could not be found in this shared project
        """
        ret_value = "default"

        cmdline_info='si viewprojecthistory --batch  --fields=revision,labels  --rfilter=labeled   --project='+SharedProject
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            if stderr_str:
                kprint("Err: "+stderr_str)
            stdout_str_lines = stdout_str.splitlines()
        except OSError,ValueError:
            print formatExceptionInfo()
        for line in stdout_str_lines:
            if (len(line) > 1):
                argu = line.split()
                if (len(argu) > 2):
                    argu[1] = argu[len(argu)-1]
                    argu[0] = line.replace(argu[1],"")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n","")
                if (len(argu) > 1):

                    try:
                        argu[0].decode('ascii')
                    except UnicodeDecodeError:
                        kprint("Decoding issue")
                    if (argu[1] == Label):
                        ret_value = argu[0]
                        break

        return ret_value    
