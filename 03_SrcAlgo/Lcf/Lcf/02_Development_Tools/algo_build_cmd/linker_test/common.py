import os
import shlex, subprocess
import sys, getopt
import logging
import glob
from os.path import basename

fo = None 
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
    fo.write(text)
    fo.write("\n")
    
def kprint(text):
    fo.write(text+"\n")
    print(text)
    
def FixedLengStr(str, l):
    StrOut = str
    l1 = len(str)
    if l > l1:
        StrOut = str + " "*(l-l1)
    return StrOut