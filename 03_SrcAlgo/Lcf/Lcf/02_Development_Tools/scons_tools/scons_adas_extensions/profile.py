"""
Filename                  :  scons_adas_extensions\profile.py
Description               :  Script that allows using a profiling mode for Generic Scons.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: profile.py
#
# DESCRIPTION: Script that allows using a profiling mode for Generic Scons.
#
# INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
#
# CREATION DATE: - 2014/10/22
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:59CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: profile.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:59CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.3 2016/05/27 12:00:30CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.2 2015/06/26 05:17:28CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:28 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import inspect, time

spacing = 3

class SconscriptTimeInfo(object):
    """Instances represent all information on SConscript-file
    caller: the Scripts that calls the profile feature
    hierarchy: the hierarchy of the calling script in GenericScons hierarchy,
                e.g. SConstruct has hierarchy 0, etc.
    start_time: start time to be measured
    info: allows to include certain information on what is measured    
    """
    def __init__(self, caller, hierarchy, start_time, info):
        """
        Function                :  __init__
        Description             :  
        caller                  :  
        hierarchy               :  
        start_time              :  
        info                    :  
        Returns                 :  
        """
        self.caller = caller
        self.hierarchy = hierarchy
        self.start_time = start_time
        self.end_time = '0'
        self.info = info
    def __str__(self):
        """
        Function        :  __str__
        Description     :  
        Returns         :  
        """
        return "caller: " + self.caller + " hierarchy: " + self.hierarchy + " time: " + str(self.time)
    
def calcMaxEntryWidth(sconscriptList):
    """
    Function                   :  calcMaxEntryWidth
    Description                :  
    sconscriptList             :  
    Returns                    :  
    """
    temp = map(lambda x : int(x.hierarchy) * spacing + len(x.caller), sconscriptList)
    maxWidth = max(temp)
    return maxWidth
    
def StartSconscriptEntry(hierarchy, info = ''):
    """
    Function              :  StartSconscriptEntry
    Description           :  
    hierarchy             :  
    info                  :  
    Returns               :  
    """
    # get time
    start_time = time.time()
    # determine the caller
    frm = inspect.stack()[1]
    if '04_Engineering' in frm[1]:
        caller = '04_Engineering' + frm[1].split('04_Engineering')[1]
    elif '05_Testing' in frm[1]:
        caller = '05_Testing' + frm[1].split('05_Testing')[1]
    else:
        caller = frm[1]
    # initiate a SconscriptTimeInfo object
    SconscriptTimesEntry = SconscriptTimeInfo(caller, hierarchy, start_time, info)
    # write results in global list
    SconscriptTimesTable.extend([SconscriptTimesEntry])
        
def FinishSconscriptEntry():
    """
    Function        :  FinishSconscriptEntry
    Description     :  
    Returns         :  
    """
    # get time
    end_time = time.time()
    # determine highest SConscript-entry which has end_time 0 --> this is the one that is closed!
    temp = map(lambda x : x.end_time, SconscriptTimesTable)
    index = max(loc for loc, val in enumerate(temp) if val == "0")
    SconscriptTimesTable[index].end_time = end_time
    SconscriptTimesTable[index].time = SconscriptTimesTable[index].end_time - SconscriptTimesTable[index].start_time

    
def PrintSconscriptInfo():
    """
    Function        :  PrintSconscriptInfo
    Description     :  
    Returns         :  
    """
    maxWidth = calcMaxEntryWidth(SconscriptTimesTable)
    """display profiling information"""
    f = open('profile.txt','w')
    print >>f, "Display profile information :\n"
    i = 0
    for sconscript in SconscriptTimesTable:
        i = i+1
        print >>f, "%3d" % i + " " * spacing * int(sconscript.hierarchy) + " " + sconscript.caller + " " * (maxWidth + 3 - spacing * int(sconscript.hierarchy) - len(sconscript.caller)) + " : " + " " * spacing * int(sconscript.hierarchy) + "%.2f sec" % sconscript.time + "     " + sconscript.info + "\n"
    f.close()