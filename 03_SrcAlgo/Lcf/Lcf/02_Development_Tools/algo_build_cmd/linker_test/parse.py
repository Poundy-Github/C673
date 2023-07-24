import os
import shlex, subprocess
import sys, getopt
import logging
import glob
from os.path import basename , dirname
import re
import shutil
import getopt
import datetime 
from common import fprint
from cStringIO import StringIO
file = ""
N = 0
def init():
    opts, args = getopt.getopt(sys.argv[1:], 'x:y:')
    #print(opts, args)
    if len(sys.argv) == 1:
        global file
        file = "Callout.c"
    else :
        file = sys.argv[1]
    
#print(sys.argv)
def List2Str(List, Seprator):
    returnStr=""
    if List:
        returnStr = List[0]
        del List[0]
        for x in List:
            returnStr = returnStr + Seprator+x
    return returnStr
    
def RemoveComments(file):
    #os.chdir("./tools")
    #Build_Command2 = "sed --expression=\"/^$/d\"  --in-place=.tmp " +file
    cc="/^\s*$/d"
    Build_Command2 = "sed/^\s*d$/d  --in-place=.tmp " +file
    Build_Command1 = "sed --file=Rules.sed  -n  --in-place=.bak "+file
    Build_Command = "sed --file=Rules.sed "
    CopiedFile = file+".bak"
    TmpFile = file+".tmp"
    #shutil.copyfile(file, CopiedFile)
    #print(" I am one ...")
    #Input1 = open(CopiedFile, "rb+")
    #Output1 = open(file, "wb+", 0)
    STR1= ""
    #fprint(Build_Command)
    #print(" I am two ...")
    print(Build_Command1)
    proc = subprocess.Popen(Build_Command1, shell=True,  stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    #shutil.copyfile(file, TmpFile)
    #print(" I am three ...")
    #Input1.close()
    #f.write(STR1)
    #Output1.close()
    proc = subprocess.Popen(Build_Command2, shell=True,  stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    print(stderr_str)

def Interprate(TypeAndName):
    TypeAndName=TypeAndName.strip()
    returnDic = {"type":"", "name":""}
    x = re.split(" +", TypeAndName)
    if len(x) == 0:
        print("parse error")
    elif len(x) == 1:
        returnDic["type"] = "void"
        returnDic["name"] = TypeAndName
    elif len(x) ==2:
        returnDic["type"] = x[0]
        returnDic["name"] = x[1]
    else:
        returnDic["type"] = List2Str(x[0:len(x)-2], " ")
        returnDic["name"] = x[-1]  
    m =     returnDic["name"].find("*")
    if m != "-1":
        returnDic["type"] = returnDic["type"] + returnDic["name"][0:m+1]
        returnDic["name"] = returnDic["name"][m+1:]
    #print(x)
    #print(returnDic)
    return    returnDic
    
    return(returnStr)

def GetTest(file):
    os.chdir("./tools")
    RemoveComments(file)
    Build_Command = "indent -kr --line-length500 -npsl  --no-tabs  --comment-line-length500  --ignore-newlines -dj -cd0  --no-comment-delimiters-on-blank-lines -nbbo -lp " +file
    fprint(Build_Command)
    StartTime = datetime.datetime.now()
    proc=subprocess.Popen(Build_Command, shell=False,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    fprint(stdout_str)
    EndTime = datetime.datetime.now()
    fprint("Duration :: "+str(EndTime-StartTime))
    Build_Command = "ctags.exe  -x --c++-kinds=pf --language-force=c++ --fields=+S " +file
    fprint(Build_Command)
    StartTime = datetime.datetime.now()
    proc=subprocess.Popen(Build_Command, shell=False,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout_str, stderr_str = proc.communicate()
    fprint(stdout_str)
    EndTime = datetime.datetime.now()
    fprint("Duration :: "+str(EndTime-StartTime))
    os.chdir("../")
    Lines = stdout_str.splitlines(True)
    final = ""
    for line in Lines:
        Var = []
        #Col=line.split("   ")
        Col = re.split(" +", line)
        if Col[1] == "prototype":
            global N
            N = N +1
            #print(N)
            FunPT= Col[4:]
            strFunPT=List2Str(FunPT, " ")
            strFunPT =strFunPT.replace("extern","")
            strFunPT =strFunPT.replace("static","")
            x =re.split("[(,)]", strFunPT )
            del x[-1]
            Args = x[:]
            Func = x[0]

            FuncDic = Interprate(Func)
            xx = Func.split()
            RetType = "void"
            #print(Func, 1)
            #print(line)
               
            RetType = FuncDic["type"]
            FuncName  = FuncDic["name"]
            #print(RetType,FuncName)
            del Args[0]
            x = filter(None, x) 
            #print(x)
            #print(x[1])
            NoP = len(x)-1
            if (NoP == 1) and (x[1] == "void" or (not x[1])):
                NoP = 0
            #print(NoP)
            
            ReturnList = []

            if RetType != "void":
                ReturnList.append("    "+RetType+" Ret"+FuncName)
            else:
                RetType = ""
            out = 0
            if NoP != 0:
                for Arg in Args:
                    ReturnList.append("    "+Arg.strip())
                    yy = Arg.split()
                    if len(yy) <= 1:
                        out = 1
                        break
                    Dic=Interprate(Arg)
                    Var.append(Dic["name"].strip())
            #print(List2Str(Var,","), 3)
            if out: break
            if Var:
                P = List2Str(Var,",")
            else:
                P = ""
            if RetType:
                FunCall = "Ret"+FuncName+"="+FuncName+"("+P +")"
            else:
                FunCall = FuncName+"("+P +")"
                
            ReturnList.append("    "+FunCall) 
            
            #print(ReturnList)    
            final1 = List2Str(ReturnList,";\n")
            
            final1 = final1 + ";\n"
            if ("eve" in FuncName) or("arp32" in FuncName) or ("Eve" in FuncName) or("ARP32" in FuncName):
                final1="    #ifdef ti_arp32\n"+final1+"    #endif\n"
            final1 = "  {\n"+final1+"   }\n"
            final = final +final1+"\n"
            #print(final)
            
            
    return final
                
        #print(Col)
        #for x in Col:
            #print(x)
    if not stderr_str:
        #print(stdout_str)
        print(file+ " Done !!! "+str(N)+" \n")
        print("*"*30)
        
def main():
    init()
    GetTest(file.replace("\\","/"))
#main()