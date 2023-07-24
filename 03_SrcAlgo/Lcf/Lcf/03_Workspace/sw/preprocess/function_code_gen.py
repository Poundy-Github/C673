import sys, getopt
import re
import os
import stat
import xml.etree.ElementTree as ET
import time
import filecmp
from Tkinter import *
import shutil # file operations

# indent = 4 spaces. DO NOT USE TAB!
# see http://legacy.python.org/dev/peps/pep-0008

tmpFileExtension  = '.tmp'
templateExtension = '.template'
currentProject    = None # global variable that defines the current platform - this is not nice, but it was the quick way. Feel free to make it better :)

class ToolTip(object):
    """ToolTip class copied from:
    http://www.voidspace.org.uk/python/weblog/arch_d7_2006_07_01.shtml
    
    Actually, you shouldn't care about this class. Just use the functions createToolTip() and removeToolTip()!"""
    def __init__(self, widget):
        self.widget = widget
        self.tipwindow = None
        self.id = None
        self.x = self.y = 0

    def showtip(self, text):
        "Display text in tooltip window"
        self.text = text
        if self.tipwindow or not self.text:
            return
        x, y, cx, cy = self.widget.bbox("insert")
        x = x + self.widget.winfo_rootx() + 27
        y = y + cy + self.widget.winfo_rooty() +27
        self.tipwindow = tw = Toplevel(self.widget)
        tw.wm_overrideredirect(1)
        tw.wm_geometry("+%d+%d" % (x, y))
        try:
            # For Mac OS
            tw.tk.call("::tk::unsupported::MacWindowStyle",
                       "style", tw._w,
                       "help", "noActivates")
        except TclError:
            pass
        label = Label(tw, text=self.text, justify=LEFT,
                      background="#ffffe0", relief=SOLID, borderwidth=1,
                      font=("tahoma", "8", "normal"))
        label.pack(ipadx=1)

    def hidetip(self):
        tw = self.tipwindow
        self.tipwindow = None
        if tw:
            tw.destroy()

def createToolTip(widget, text):
    """intput: widget: the widget for which the tooltip should be shown when hovered by the mouse
               text: the text that should be displayed in the tool tip"""
    toolTip = ToolTip(widget)
    def enter(event):
        toolTip.showtip(text)
    def leave(event):
        toolTip.hidetip()
    widget.bind('<Enter>', enter)
    widget.bind('<Leave>', leave)
    return toolTip

def removeToolTip(widget):
    widget.unbind('<Enter>')
    widget.unbind('<Leave>')

def warn(string, level=1):
    "very primitive error reporting. This could be replaced by some logging module"
    prefix = ""
    if level == 0:
        prefix = "*** ERROR ***  "
    if level == 1:
        prefix = " ==WARNING==   "
    if level == 2: #not so serious warning
        prefix = "  --warning--  "
    if level == 3:
        prefix = "   . meeeeeh . "
    print >> sys.stderr, prefix + str(string) #baaah, not python 3 compatible at all. But what else should we do ...

class FileGenerator:
    """Class that encapsulates all information needed to generate a file"""
    def __init__(self, file, outDir, function):
        """Constructor:
        Input:
            file     (String):   Only the file name that should be generated (no path)
            outDir   (String):   The output directory relative to the current working directory
            function (function): The function that generates the file"""
        self.file     = file 
        self.outDir   = outDir
        self.function = function

# translates values in the config to stuff that can be understood by the compiler
IpcConfigMap = { "STEREO_2_MCU" : "e_CFG_IPC_MCU", 
                   "MONO_2_MCU" : "e_CFG_IPC_MCU",
                   "MCU_2_MONO" : "e_CFG_IPC_MONO",
                 "MCU_2_STEREO" : "e_CFG_IPC_STEREO",
            "MCU_2_MONO_STEREO" : "e_CFG_IPC_MONO | e_CFG_IPC_STEREO",
                          "XXX" : None,
            "i_do_nothing_here" : None }

class MdbCluster:
    """internal representation for one single mdb cluster.
    All the settings in the configuration will be mapped to one of these instances"""
    def __init__(self):
        self.mId                = None
        self.uId                = None
        self.enfg               = None
        self.dmaConfig          = None
        self.dataType           = None
        self.copyAtStartupTo    = None
        self.isProtRead         = None
        self.isPcisSync         = None
        self.isPrefill          = None
        self.isFifoMode         = None
        self.dataAlign          = None
        self.mtsVirtAddr        = None
        self.mtsCycleId         = None
        self.ringBufferSize     = None
        self.ipcConfig          = None
        self.ipcNorm            = None
        self.ipcIob             = None
        self.generalComment     = None
        self.dataSection        = None
        self.isCrc              = None
        self.dmaDataSection     = None
        self.dmaDataPtrInCl     = None
        self.dmaDataType        = None
        self.dmaArraySize       = None
        self.dmaDataAlign       = None
        self.dmaIsExtPtr        = None
        self.dmaMemBase         = None
        self.dmaComments        = None
        
class GaBlock:
    """This represents one block in the GA configuration, i.e. one algo entry in the ga config.
    It contains a list of configs, reqPorts and proPorts each (the inner classes)."""
    class Config:
        """This represents once single config entry in a ga block"""
        def __init__(self, sId, coreId, reqPort, proPort, qualityLevel, isOnCore):
            self.sId          = sId
            self.coreId       = coreId
            self.reqPort      = reqPort
            self.proPort      = proPort
            self.qualityLevel = qualityLevel
            self.isOnCore     = isOnCore
    
    class ReqPort:
        """This represents once single GA_ReqPort entry in a ga block"""
        def __init__(self, sId, elemInStruct, instance, isCrc, mdbId):
            self.sId          = sId
            self.elemInStruct = elemInStruct
            self.instance     = instance
            self.isCrc        = isCrc
            self.enMdbId      = mdbId
    
    class ProPort:
        """This represents once single GA_ProPort entry in a ga block"""
        def __init__(self, sId, elemInStruct, mdbId):
            self.sId          = sId
            self.elemInStruct = elemInStruct
            self.enMdbId      = mdbId
        
    def __init__(self):
        self.mId          = None
        self.uId          = None
        self.enfg         = None

        self.interface    = None
        self.taskId       = None
        self.fswResp      = None
        self.algoResp     = None
        self.comment      = None
        self.enForProd    = None
        self.fullName     = None
        self.reqPort      = None
        self.proPort      = None

        self.configs      = [] #array of GaBlock.Config
        self.reqPorts     = [] #array of GaBlock.ReqPort
        self.proPorts     = [] #array of GaBlock.ProPort
        
def patchFile(outFile, blockName, insertString):
    """inserts the insertString between the blockName markers in the given outFile"""
    tagStart = r"^\s*/\*!<codegen_start:" + blockName + r">\*/"
    tagEnd   = r"^\s*/\*!<codegen_end:"   + blockName + r">\*/"
    
    success = False
    
    f = open(outFile, "r+")
    try:
        allLines = f.readlines()
        f.seek(0)
        containsTrailingSpace = False
        containsTabCharacter = False
        for lineNr, line in enumerate(allLines):
            if re.search(r'\s+\n', line): #one space before \\ is ok. Note that each line here contains a newline at the end, which is not matched by $
                containsTrailingSpace = True
            if '\t' in line:
                containsTabCharacter = True
            f.write(line)
            if re.match(tagStart, line) and re.match(tagEnd, allLines[lineNr+1]):
                f.write(insertString)
                success = True
        if containsTrailingSpace:
            warn('Template file for ' + os.path.basename(outFile) + ' contains unnecessary trailing space!', 3)
        if containsTabCharacter:
            warn('Template file for ' + os.path.basename(outFile) + ' contains tab characters, which should be avoided!', 3)
    finally:
        f.close()
    if not success:
        raise Exception("Could not find matching pair for " + blockName + " in " + outFile)


def gen_mdb_cluster_h(mdbClusters, outFile):
    maxIdLen = max([len(a.mId) for a in mdbClusters if a.enfg])
    clusterEnum = ""
    count = 0
    for cluster in mdbClusters:
        if cluster.enfg:
            clusterEnum += (("  %-" + str(maxIdLen) + "s = %3d") % (cluster.mId, count)) + ",\n"
            count += 1
    clusterEnum += ("  %-" + str(maxIdLen) + "s") %"MDB_e_CLUSTER_NUM_CLUSTERS" + " = " + str(count) + ",  /* Not a cluster type - used only for sanity checks */\n"
    patchFile(outFile, 'CLUSTER_ENUM', clusterEnum)
    del clusterEnum
    
    patchFile(outFile, 'NUM_CLUSTER_INSTANCES', '#define NUM_CLUSTER_INSTANCES ('+ str(sum([cluster.ringBufferSize for cluster in mdbClusters])) +')\n')
    
def gen_mdb_database_cpp(mdbClusters, outFile):
    noDmaDataSection = '<none>'
    clusterPayload = ""
    clusterDma     = ""
    # MAX strlens
    maxTypeLen        = str(max([len(a.dataType)                             for a in mdbClusters if a.enfg]))
    maxIdLen          = str(max([len(a.mId)                                  for a in mdbClusters if a.enfg]))
    maxTypeLen_forDma = str(max([len(a.dataType)       if a.dmaConfig else 0 for a in mdbClusters if a.enfg]))
    maxIdLen_forDma   = str(max([len(a.mId)            if a.dmaConfig else 0 for a in mdbClusters if a.enfg]))
    maxDmaTypeLen     = str(max([len(a.dmaDataType)    if a.dmaConfig else 0 for a in mdbClusters if a.enfg]))
    maxDmaDataPtr     = str(max([len(a.dmaDataPtrInCl) if a.dmaConfig else 0 for a in mdbClusters if a.enfg]))
    maxDmaDataAlign   = str(max([len(a.dmaDataAlign)   if a.dmaConfig else 0 for a in mdbClusters if a.enfg]))
    maxDmaMemBase     = str(max([len(a.dmaMemBase)     if a.dmaConfig else 0 for a in mdbClusters if a.enfg]))
    
    #Cluster Payload
    for cluster in mdbClusters:
        if cluster.enfg:
            clusterPayload += '#pragma DATA_SECTION("' +     cluster.dataSection  + '")\n'
            clusterPayload += '#pragma DATA_ALIGN('  + str(cluster.dataAlign  ) +  ')\n'
            clusterPayload += ('%-' + maxTypeLen + 's a_%-' + maxIdLen + 's[NUM_' + cluster.mId + '_ENTRIES];\n') % (cluster.dataType, cluster.mId)
    patchFile(outFile, "CLUSTER_PAYLOAD", clusterPayload)

    #Cluster Dma
    for cluster in mdbClusters:
        if cluster.enfg and cluster.dmaConfig and cluster.dmaDataSection.lower() != noDmaDataSection:
            clusterDma += '#pragma DATA_SECTION("' + cluster.dmaDataSection+ '")\n'
            clusterDma += '#pragma DATA_ALIGN(' + cluster.dmaDataAlign + ")\n"
            clusterDma += ('%-' + maxDmaTypeLen + 's MDBEXT_a_%-' + maxIdLen + 's[' + str(cluster.ringBufferSize) + "]" + "[" + str(cluster.dmaArraySize) + "];\n") % (cluster.dmaDataType, cluster.mId)
    patchFile(outFile, "CLUSTER_DMA", clusterDma)

    #Cluster Config
    clusterConfig = ""
    flags       = {}
    for cluster in mdbClusters:
        if cluster.enfg:
            tmpFlagList = []
            if cluster.isPcisSync:
                tmpFlagList.append("(uint32)MDB_e_FLAG_PCIe_SYNC")
            if cluster.isPrefill:
                tmpFlagList.append("(uint32)MDB_e_FLAG_PREFILL")
            if cluster.isFifoMode:
                tmpFlagList.append("(uint32)MDB_e_FLAG_FIFO_MODE")
            if cluster.isCrc:
                tmpFlagList.append("(uint32)MDB_e_FLAG_CRC")
            if tmpFlagList == []:
                tmpFlagList.append("(uint32)MDB_e_FLAG_NONE")
            flags[cluster.mId] = " | ".join(tmpFlagList) #"or" all flags together
            
    maxFlagsLen = max([len(a) for a in flags.values()])
    for cluster in mdbClusters:
        if cluster.enfg:
            clusterConfig += ("  { %-" + str(int(maxIdLen) + len(",")) + "s %-" + str(int(maxIdLen) + len("NUM_" + "_ENTRIES,")) + "s sizeof(%-" + str(int(maxTypeLen) + len("),")) + "s a_%-" + str(int(maxIdLen)+len(',')) + "s %-" + str(maxFlagsLen) + "s },\n") %(cluster.mId + ",", "NUM_" + cluster.mId + "_ENTRIES,", cluster.dataType+"),", cluster.mId+',', flags[cluster.mId])
    patchFile(outFile, "CLUSTER_CONFIG", clusterConfig)
    
    #Cluster Config DMA
    clusterConfigDma = ""

    maxIdLen_forMDBEXT  = str(max([len(a.mId) if a.dmaConfig and not a.dmaIsExtPtr else 0 for a in mdbClusters]))
    maxSizeof_forMDBEXT = str(max([len(a.mId) + len('sizeof(MDBEXT_a_'+'[0]),') if a.dmaConfig and not a.dmaIsExtPtr else 0 for a in mdbClusters]))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.dmaConfig:
            clusterConfigDma += ("  { %-" + str(int(maxIdLen_forDma) + len(',')) + "s %-" + str(len('MDBEXT_a_') + int(maxIdLen_forMDBEXT) + len(',')) + "s offsetof(%-" + str(int(maxTypeLen_forDma) + len(',')) + "s %-" + maxDmaDataPtr + "s), %-" + maxSizeof_forMDBEXT + "s %-" + str(int(maxDmaDataAlign) + len(',')) + "s %-" + str(len("MDB_e_DMAFLAG_EXTPOINTER,")) + "s %-" + maxDmaMemBase + "s },\n") \
                                % (cluster.mId + ',', \
                                   ('MDBEXT_a_' + cluster.mId + ',') if not cluster.dmaIsExtPtr else 'NULL,', \
                                   cluster.dataType + ',', \
                                   cluster.dmaDataPtrInCl, \
                                   ('sizeof(MDBEXT_a_' + cluster.mId + '[0]),') if not cluster.dmaIsExtPtr else (cluster.dmaArraySize + ' * sizeof(' + cluster.dmaDataType + '),'), \
                                   str(cluster.dmaDataAlign) + ',', \
                                   "MDB_e_DMAFLAG_EXTPOINTER," if cluster.dmaIsExtPtr else "MDB_e_DMAFLAG_NONE,", cluster.dmaMemBase)
    patchFile(outFile, "CLUSTER_CONFIG_DMA", clusterConfigDma)

def gen_mdb_database_h(mdbClusters, outFile):
    #Cluster Num Entries
    clusterNumEntries  = ""
    maxIdLen   = str(max([len(a.mId) for a in mdbClusters if a.enfg]))
    for cluster in mdbClusters:
        if cluster.enfg:
            clusterNumEntries += ("#define %-" + str(int(maxIdLen) + len('NUM_' + '_ENTRIES')) + "s %s\n") %("NUM_" + cluster.mId + "_ENTRIES", cluster.ringBufferSize)
    patchFile(outFile, "CLUSTER_NUM_ENTRIES", clusterNumEntries)

def gen_sw_measfreezes_cfg_cpp(mdbClusters, outFile):
    swMeasfreezeList = ""
    maxIdLen    = str(max([len(a.mId)                                     for a in mdbClusters if a.enfg]) + len(","))
    maxTypeLen  = str(max([len(a.dataType)                                for a in mdbClusters if a.enfg]) + len("sizeof("+"),"))
    maxVAddrLen = str(max([len(    a.mtsVirtAddr) if a.mtsVirtAddr else 0 for a in mdbClusters if a.enfg]) + len(","))
    maxCycIdLen = str(max([len(str(a.mtsCycleId)) if a.mtsCycleId  else 0 for a in mdbClusters if a.enfg]))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.mtsVirtAddr and cluster.mtsCycleId:
            swMeasfreezeList += ("  { %-" + maxIdLen + "s %-" + maxTypeLen + "s %-" + maxVAddrLen + "s %-" + maxCycIdLen + "s },\n") %(cluster.mId + ",", "sizeof(" + cluster.dataType + "),", cluster.mtsVirtAddr + ",", cluster.mtsCycleId)
    patchFile(outFile, "SW_MEASFREEZE_LIST", swMeasfreezeList)
        
        
def gen_ipc_cluster_cync_cfg_cpp(mdbClusters, outFile, genSwap=True):
    #IPCv2_SYNC_LIST
    ipcv2SyncList = ""
    ipcModes = {}
    
    for cluster in mdbClusters:
        if cluster.enfg:
        #if "e_CFG_IPC_MONO" in cluster.ipcConfig or "e_CFG_IPC_STEREO" in cluster.ipcConfig:
            ipcMode = []
            if cluster.ipcConfig is not None:
                if cluster.ipcNorm:
                    ipcMode.append("IPC_MODE_NORMAL")
                if cluster.ipcIob:
                    ipcMode.append("IPC_MODE_IOB")
                if ipcMode == []:
                    if cluster.ipcConfig != "": # TODO remove this! it's just there because of inconsistencies in the config!
                                                # But first, all warnings, which are spit out by this script must be removed!
                        ipcMode.append("IPC_MODE_NONE")
                        # TODO throw an error if this occurs 
                        warn(cluster.mId + " is neither configured for normal, nor IOB, but has a valid direction entry! IPC_MODE will default to \"NONE\"")
                ipcMode = " | ".join(ipcMode)
                ipcModes[cluster.mId] = ipcMode
    
    maxMdbLen   = str(max([len(a.mId) for a in mdbClusters if a.enfg and a.ipcConfig]) + len(","))
    maxIpcLen   = str(int(maxMdbLen) - len("MDB_e_") + len("IPC_e_"))
    maxSwapLen  = str(max([(len(a.dataType)+len("&v_ipcswap_") if genSwap else len("NULL")) for a in mdbClusters if a.enfg]) + len(","))
    maxSizeLen  = str(max([len(a.dataType)                                                  for a in mdbClusters if a.enfg]) + len("sizeof(),"))
    maxModeLen  = str(max([len(ipcModes[a.mId]) if a.ipcConfig else 0                       for a in mdbClusters if a.enfg]))
        
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig is not None and cluster.ipcConfig != "":
            ipcv2SyncList += ("  { %-" + maxIpcLen + "s %-" + maxMdbLen + "s %-" + maxSwapLen + "s %-" + maxSizeLen + "s %-" + maxModeLen + "s },\n") \
                            % (cluster.mId.replace("MDB_e_", "IPC_e_", 1) + ',',                \
                               cluster.mId + ',',                                               \
                               ("&v_Ipcswap_" + cluster.dataType if genSwap else "NULL") + ',', \
                               "sizeof(" + cluster.dataType + "),",                             \
                               ipcModes[cluster.mId])
    patchFile(outFile, "IPCv2_SYNC_LIST", ipcv2SyncList)

    #cluster short cut list
    clusterShortCutList = ""
    maxIdLen      = str(max([len(a.mId)             if a.copyAtStartupTo else 0 for a in mdbClusters if a.enfg]) + len(","))
    maxOtherIdLen = str(max([len(a.copyAtStartupTo) if a.copyAtStartupTo else 0 for a in mdbClusters if a.enfg]) + len(','))
    maxTypeLen    = str(max([len(a.dataType)        if a.copyAtStartupTo else 0 for a in mdbClusters if a.enfg]) + len('sizeof(),'))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.copyAtStartupTo:
            clusterShortCutList += ("  { %-" + maxIdLen + "s %-" + maxOtherIdLen + "s %-" + maxTypeLen + "s b_FALSE },\n") % (cluster.mId + ',', cluster.copyAtStartupTo + ',', "sizeof(" + cluster.dataType + "),")
    patchFile(outFile, "a_clusterShortcutList", clusterShortCutList)
    
    #INCLUDE_IPCSWAP
    if genSwap:
        patchFile(outFile, 'INCLUDE_IPCSWAP', '#include "ipcswap.h"\n')
    else:
        patchFile(outFile, 'INCLUDE_IPCSWAP', '// #include "ipcswap.h" // disabled because of noswap option\n')


def gen_ipc_sync_cfg_c(mdbClusters, outFile, genSwap=True):
    #IPC_CLUSTER_DESCR_LIST
    ipcClusterDescrList = ""

    maxIdLen     = str(max([len(a.mId)                     if a.ipcConfig else 0 for a in mdbClusters if a.enfg]) - len("MDB_e_") + len("IPC_e_,"))
    maxTypeLen   = str(max([len(a.dataType)                if a.ipcConfig else 0 for a in mdbClusters if a.enfg]) + len("sizeof(),"))
    maxDirection = str(max([len(IpcConfigMap[a.ipcConfig]) if a.ipcConfig else 0 for a in mdbClusters if a.enfg]) + len(""))

    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            ipcClusterDescrList += ("  { %-" + maxIdLen + "s %-" + maxTypeLen + "s %-" + maxDirection + "s },\n") % (cluster.mId.replace("MDB_e_", "IPC_e_", 1) + ',', "sizeof("+cluster.dataType+"),", IpcConfigMap[cluster.ipcConfig])
    patchFile(outFile, "IPC_CLUSTER_DESCR_LIST", ipcClusterDescrList)
    
    isStereoSystem = False
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            if 'stereo' in cluster.ipcConfig.lower(): #if there is at least one stereo tag in the config, it is most probably a stereo project.
                # TODO this should at one point go into the xml config
                isStereoSystem = True
                break
    if isStereoSystem:
        patchFile(outFile, "STEREO_COMM_PARTNER", '  e_CFG_IPC_STEREO\n')

    
def gen_ipc_sync_cfg_h(mdbClusters, outFile, genSwap=True):
    #IPC_VERSION_CTRL
    rteVersion, ipcVersion, wasCancelled = IpcVersionControlDialog(outFile).askUserForVersions()
    ipcVersionCtrl = '#define IPC_RTE_TYPE_VERSION ' + rteVersion + '\n#define IPC_SYNC_VERSION ' + ipcVersion + '\n'
    if wasCancelled:
        ipcVersionCtrl = '/* These are the old versions from the configuration before */\n' + ipcVersionCtrl + '#error "IPC Version control dialog was cancelled"\n'
    patchFile(outFile, 'IPC_VERSION_CTRL', ipcVersionCtrl)
    
    #IPC_CLUSTER_ID
    maxIdLen = str(max([len(a.mId) if a.ipcConfig else 0 for a in mdbClusters if a.enfg]) - len("MDB_e_") + len("IPC_e_"))
    ipcClusterIndex = 0
    ipcClusterIds = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            ipcClusterIds += ("  %-" + maxIdLen + "s = %3d,\n") % (cluster.mId.replace('MDB_e_', 'IPC_e_', 1), ipcClusterIndex)
            ipcClusterIndex += 1
    ipcClusterIds += "  IPC_E_NUM_CLUSTERS = " + str(ipcClusterIndex) + ",\n";
    patchFile(outFile, 'IPC_CLUSTER_ID', ipcClusterIds)
    
    #IPC_ROBUSTNESS_FEATURE    
    #TODO move this hard wired config for the products to the xml config!
    if currentProject == 'mfc411' or currentProject == 'mfs430bw16':
        patchFile(outFile, 'IPC_ROBUSTNESS_FEATURE', '#define IPC_ROBUSTNESS_FEATURE // enabled for ' + currentProject + '\n')
    else:
        patchFile(outFile, 'IPC_ROBUSTNESS_FEATURE', '// #define IPC_ROBUSTNESS_FEATURE //disabled for ' + currentProject + '\n')
        
    #IPC_NUMBER_OF_COMM_PARTNERS
    isStereoSystem = False
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            if 'stereo' in cluster.ipcConfig.lower(): #if there is at least one stereo tag in the config, it is most probably a stereo project.
                # TODO this should at one point go into the xml config
                isStereoSystem = True
                break
    if isStereoSystem:
        patchFile(outFile, "IPC_NUMBER_OF_COMM_PARTNERS", "#define IPC_NUMBER_OF_COMM_PARTNERS (2) /* we're on a stereo system */\n")
    else:
        patchFile(outFile, "IPC_NUMBER_OF_COMM_PARTNERS", "#define IPC_NUMBER_OF_COMM_PARTNERS (1) /* we're on a mono system */\n")
    
    #IPC_NUM_CYCLES
    # TODO move this config to the xml config!
    numIpcCycles = { 'mfc4t0'     : { 'mono' : 6, 'stereo' : 1 },
                     'mfc411'     : { 'mono' : 3, 'stereo' : 3 },
                     'mfc431'     : { 'mono' : 6, 'stereo' : 1 },
                     'mfl420ta46' : { 'mono' : 3, 'stereo' : 3 },
                     'mfs430bw16' : { 'mono' : 3, 'stereo' : 3 } }
    patchFile(outFile, 'NUM_CYCLES_MONO',   '#define IPC_NO_OF_COMMUNICATIONS_IN_CYCLE_MONO ('   + str(numIpcCycles[currentProject]['mono'])   + ')\n')
    patchFile(outFile, 'NUM_CYCLES_STEREO', '#define IPC_NO_OF_COMMUNICATIONS_IN_CYCLE_STEREO (' + str(numIpcCycles[currentProject]['stereo']) + ')\n')

    
def gen_ipc_sync_iuc_cfg_c(mdbClusters, outFile, genSwap=True):
    #IPC_a_IUC_RECEIVE_CLUSTERS_FROM_MONO
    rxClusterFromMono = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig == "MONO_2_MCU":
            rxClusterFromMono += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_RECEIVE_CLUSTERS_FROM_MONO', rxClusterFromMono)

    #IPC_a_IUC_RECEIVE_CLUSTERS_FROM_STEREO
    rxClusterFromStereo = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig == "STEREO_2_MCU":
            rxClusterFromStereo += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_RECEIVE_CLUSTERS_FROM_STEREO', rxClusterFromStereo)

    #IPC_a_IUC_SEND_CLUSTERS
    iucSendClusters = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig and cluster.ipcConfig.startswith('MCU_2_'):
            iucSendClusters += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_SEND_CLUSTERS', iucSendClusters)

    #IPC_a_IUC_RECEIVE_CLUSTERS_FROM_MONO_NORMAL
    rxClustersFromMonoNormal = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig == 'MONO_2_MCU' and cluster.ipcNorm:
            rxClustersFromMonoNormal += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_RECEIVE_CLUSTERS_FROM_MONO_NORMAL', rxClustersFromMonoNormal)
    
    #IPC_a_IUC_RECEIVE_CLUSTERS_FROM_MONO_IOB
    rxClustersFromMonoIob = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig == 'MONO_2_MCU' and cluster.ipcIob:
            rxClustersFromMonoIob += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_RECEIVE_CLUSTERS_FROM_MONO_IOB', rxClustersFromMonoIob)

    #IPC_a_IUC_RECEIVE_CLUSTERS_FROM_STEREO_NORMAL
    rxClustersFromStereoNormal = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig == 'STEREO_2_MCU' and cluster.ipcNorm:
            rxClustersFromStereoNormal += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_RECEIVE_CLUSTERS_FROM_STEREO_NORMAL', rxClustersFromStereoNormal)
    
    #IPC_a_IUC_RECEIVE_CLUSTERS_FROM_STEREO_IOB
    rxClustersFromStereoIob = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig == 'STEREO_2_MCU' and cluster.ipcIob:
            rxClustersFromStereoIob += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_RECEIVE_CLUSTERS_FROM_STEREO_IOB', rxClustersFromStereoIob)

    #IPC_a_IUC_SEND_CLUSTERS_NORMAL
    txSendClustersNormal = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig and cluster.ipcConfig.startswith('MCU_2_') and cluster.ipcNorm:
            txSendClustersNormal += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_SEND_CLUSTERS_NORMAL', txSendClustersNormal)

    #IPC_a_IUC_SEND_CLUSTERS_IOB
    txSendClustersIob = ''
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig and cluster.ipcConfig.startswith('MCU_2_') and cluster.ipcIob:
            txSendClustersIob += cluster.mId.replace('MDB_e_', '  IPC_e_', 1) + ",\n";
    patchFile(outFile, 'IPC_a_IUC_SEND_CLUSTERS_IOB', txSendClustersIob)

def gen_ipc_sync_iuc_cfg_h(mdbClusters, outFile, genSwap=True):
    #EFFECTIVE_DATABASE_SIZE
    effectiveDatabaseSize = ''
    maxTypeLen = str(max([len(a.dataType) if a.ipcConfig else 0 for a in mdbClusters if a.enfg]) + len("))"))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            effectiveDatabaseSize += ("  + SYNC_MULTIPLE_OF_4(sizeof(%-" + maxTypeLen + "s + SYNC_MULTIPLE_OF_4(sizeof(clusterHeaderIuc_t))\\\n") % (cluster.dataType + "))")
    patchFile(outFile, 'EFFECTIVE_DATABASE_SIZE', effectiveDatabaseSize)

    #UNION_CLUSTER_TYPE
    unionClusterType = ''
    maxTypeLen = str(max([len(a.dataType) if a.ipcConfig else 0 for a in mdbClusters if a.enfg]))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            unionClusterType += ("  %-" + maxTypeLen + "s " + cluster.mId.replace('MDB_e_', 'IPC_e_', 1) + ";\n") % (cluster.dataType)
    patchFile(outFile, 'UNION_CLUSTER_TYPE', unionClusterType)

    #IPC_NO_IUC_RECEIVE_CLUSTERS_MONO
    patchFile(outFile, 'IPC_NO_IUC_RECEIVE_CLUSTERS_MONO',   '  ' + str(len(filter(lambda cluster: cluster.ipcConfig == 'MONO_2_MCU' and cluster.enfg,   mdbClusters))) + '\\\n')

    #IPC_NO_IUC_RECEIVE_CLUSTERS_STEREO
    patchFile(outFile, 'IPC_NO_IUC_RECEIVE_CLUSTERS_STEREO', '  ' + str(len(filter(lambda cluster: cluster.ipcConfig == 'STEREO_2_MCU' and cluster.enfg, mdbClusters))) + '\\\n')

    #IPC_NO_IUC_SEND_CLUSTERS
    # inner if-else because ipcConfig might be None.
    patchFile(outFile, 'IPC_NO_IUC_SEND_CLUSTERS', '  ' + str(len(filter(lambda cluster: (cluster.ipcConfig.startswith('MCU_2_') if cluster.ipcConfig else False) and cluster.enfg, mdbClusters))) + '\\\n')

    #EFFECTIVE_DB_SIZE_NORMAL
    effectiveDbSizeNormal = ''
    count = 0
    maxTypeLen = str(max([len(a.dataType) if a.ipcConfig and a.ipcNorm else len('clusterHeaderIuc_t') for a in mdbClusters if a.enfg]))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig and cluster.ipcNorm:
            effectiveDbSizeNormal += ("  %-" + maxTypeLen + "s %s_dummy" + str(count) + ";\n  %-"\
                                             + maxTypeLen + "s clusterHeaderIuc_t_dummy" + str(count + 1) + ';\n') % (cluster.dataType, cluster.dataType, "clusterHeaderIuc_t")
            count += 2
    patchFile(outFile, 'EFFECTIVE_DB_SIZE_NORMAL', effectiveDbSizeNormal)

    #EFFECTIVE_DB_SIZE_IOB
    effectiveDbSizeIob = ''
    count = 0
    maxTypeLen = str(max([len(a.dataType) if a.ipcConfig and a.ipcIob else len('clusterHeaderIuc_t') for a in mdbClusters if a.enfg]))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig and cluster.ipcIob:
            effectiveDbSizeIob += ("  %-" + maxTypeLen + "s %s_dummy" + str(count) + ";\n  %-"\
                                          + maxTypeLen + "s clusterHeaderIuc_t_dummy" + str(count + 1) + ';\n') % (cluster.dataType, cluster.dataType, "clusterHeaderIuc_t")
            count += 2
    patchFile(outFile, 'EFFECTIVE_DB_SIZE_IOB', effectiveDbSizeIob)

    #CLUSTER_NAME_TYPE
    clusterNameType = ''
    maxIdLen = str(max([len(a.mId) if a.ipcConfig else 0 for a in mdbClusters if a.enfg]) + len('_TYPE'))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig:
            clusterNameType += ("#define %-" + maxIdLen + "s " + cluster.dataType + '\n') % (cluster.mId.replace('MDB_e_', 'IPC_e_', 1) + '_TYPE')
    patchFile(outFile, 'CLUSTER_NAME_TYPE', clusterNameType)

    #IPC_NO_IUC_RECEIVE_CLUSTERS_MONO_NORMAL
    patchFile(outFile, 'IPC_NO_IUC_RECEIVE_CLUSTERS_MONO_NORMAL', '  '   + str(len(filter(lambda cluster: cluster.enfg and cluster.ipcConfig == 'MONO_2_MCU'   and cluster.ipcNorm, mdbClusters))) + '\\\n')

    #IPC_NO_IUC_RECEIVE_CLUSTERS_MONO_IOB
    patchFile(outFile, 'IPC_NO_IUC_RECEIVE_CLUSTERS_MONO_IOB', '  '      + str(len(filter(lambda cluster: cluster.enfg and cluster.ipcConfig == 'MONO_2_MCU'   and cluster.ipcIob,  mdbClusters))) + '\\\n')

    #IPC_NO_IUC_RECEIVE_CLUSTERS_STEREO_NORMAL
    patchFile(outFile, 'IPC_NO_IUC_RECEIVE_CLUSTERS_STEREO_NORMAL', '  ' + str(len(filter(lambda cluster: cluster.enfg and cluster.ipcConfig == 'STEREO_2_MCU' and cluster.ipcNorm, mdbClusters))) + '\\\n')

    #IPC_NO_IUC_RECEIVE_CLUSTERS_STEREO_IOB
    patchFile(outFile, 'IPC_NO_IUC_RECEIVE_CLUSTERS_STEREO_IOB', '  '    + str(len(filter(lambda cluster: cluster.enfg and cluster.ipcConfig == 'STEREO_2_MCU' and cluster.ipcIob,  mdbClusters))) + '\\\n')

    #IPC_NO_IUC_SEND_CLUSTERS_NORMAL
    patchFile(outFile, 'IPC_NO_IUC_SEND_CLUSTERS_NORMAL', '  '           + str(len(filter(lambda cluster: cluster.enfg and cluster.ipcNorm and (cluster.ipcConfig.startswith('MCU_2_') if cluster.ipcConfig else False), mdbClusters))) + '\\\n')

    #IPC_NO_IUC_SEND_CLUSTERS_IOB
    patchFile(outFile, 'IPC_NO_IUC_SEND_CLUSTERS_IOB', '  '              + str(len(filter(lambda cluster: cluster.enfg and cluster.ipcIob  and (cluster.ipcConfig.startswith('MCU_2_') if cluster.ipcConfig else False), mdbClusters))) + '\\\n')
    
    #IPC_XM_RX_CLUSTERS
    ipcXmRxClusters = ''
    maxIdLen = str(max([len(a.mId) if a.ipcConfig and a.ipcConfig.endswith('_2_MCU') else 0 for a in mdbClusters if a.enfg]) + len(')'))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig  and cluster.ipcConfig.endswith('_2_MCU'):
            ipcXmRxClusters += ("  IPC_XM(%-" + maxIdLen + "s \\\n") % (cluster.mId.replace('MDB_e_', 'IPC_e_', 1) + ')')
    patchFile(outFile, 'IPC_XM_RX_CLUSTERS', ipcXmRxClusters)
    # The last 6 lines are almost the same as this (without the alignment space): (for learning purposes for the reader ;)
    #patchFile(outFile, 'IPC_XM_RX_CLUSTERS', ''.join([ '  IPC_XM(' + a.mId.replace('MDB_e_', 'IPC_e_', 1) + ') \\\n' for a in filter(lambda cluster: cluster.ipcConfig  and cluster.ipcConfig.endswith('_2_MCU'), mdbClusters)]))
    
    #IPC_XM_TX_CLUSTERS
    ipcXmTxClusters = ''
    maxIdLen = str(max([len(a.mId) if a.ipcConfig and a.ipcConfig.startswith('MCU_2_') else 0 for a in mdbClusters if a.enfg]) + len(')'))
    for cluster in mdbClusters:
        if cluster.enfg and cluster.ipcConfig  and cluster.ipcConfig.startswith('MCU_2_'):
            ipcXmTxClusters += ("  IPC_XM(%-" + maxIdLen + "s \\\n") % (cluster.mId.replace('MDB_e_', 'IPC_e_', 1) + ')')
    patchFile(outFile, 'IPC_XM_TX_CLUSTERS', ipcXmTxClusters)

def gen_gen_adapter_conf_h(gaBlocks, outFile):
    #GEN_ADAPTER_EN_ALGO
    enabledAlgos = "/* Enabled algos on core: */\n"
    #disabledAlgos = "/* Disabled algos on core: */\n"
    for gaBlock in gaBlocks:
        if gaBlock.enfg:
            for configEntry in gaBlock.configs:
                if configEntry.isOnCore:
                    enabledAlgos += '#define ' + gaBlock.mId + '_' + configEntry.coreId + '\n'
                #else:
                #    disabledAlgos += '// #define ' + gaBlock.mId + '_' + configEntry.coreId + '\n'
    genAdapterEnAlgo = enabledAlgos + '\n' #+ disabledAlgos + '\n'
    patchFile(outFile, 'GEN_ADAPTER_EN_ALGO', genAdapterEnAlgo)
    
    #GEN_ADAPTER_INCLUDES
    genAdapterIncludes = ""
    includesPerCore = {}
    # calculate includes per core
    for gaBlock in gaBlocks:
        if gaBlock.enfg and gaBlock.interface:
            for configEntry in gaBlock.configs:
                if configEntry.isOnCore:
                    if not configEntry.coreId in includesPerCore:
                        includesPerCore[configEntry.coreId] = []
                    includesPerCore[configEntry.coreId].append(gaBlock.interface)
    # calculation done, now generate the code
    for core, includes in sorted(includesPerCore.iteritems()):
        genAdapterIncludes += '#ifdef ' + core + '\n'
        for include in includes:
            genAdapterIncludes += '  #include "' + include + '"\n'
        genAdapterIncludes += '#endif //' + core + '\n\n'
    genAdapterIncludes += '#define GA_MAX_NUM_PRO_PORT ' + str(max([len(gaBlock.proPorts) for gaBlock in gaBlocks])) + '\n'
    genAdapterIncludes += '#define GA_MAX_NUM_REQ_PORT ' + str(max([len(gaBlock.reqPorts) for gaBlock in gaBlocks])) + '\n'
    patchFile(outFile, 'GEN_ADAPTER_INCLUDES', genAdapterIncludes)
    
    #GEN_ADAPTER_CFG
    genAdapterCfg = ""
    # REQ PORTS
    for gaBlock in gaBlocks:
        if gaBlock.enfg:
            coreListWithEnabledReqPorts = [config.coreId for config in gaBlock.configs if config.isOnCore and config.reqPort ]
            if coreListWithEnabledReqPorts != []:
                # preprocessor #if
                maxCoreLen     = str(max([len(coreId) for coreId in coreListWithEnabledReqPorts]) + len(")"))
                maxAlgoCoreLen = str(int(maxCoreLen) + len(gaBlock.mId) + len("_"))
                genAdapterCfg += ("#if   (defined(%-" + maxCoreLen + "s && defined(%-" + maxAlgoCoreLen + "s)") % (coreListWithEnabledReqPorts[0] + ')', gaBlock.mId + '_' + coreListWithEnabledReqPorts[0] + ')')
                for coreId in coreListWithEnabledReqPorts[1:]:
                    genAdapterCfg += ("\\\n   || (defined(%-" + maxCoreLen + "s && defined(%-" + maxAlgoCoreLen + "s)") % (coreId + ')', gaBlock.mId + '_' + coreId + ')')
                genAdapterCfg += "\n"

                #GA_AlgoReqPrtList
                genAdapterCfg += "const t_GA_reqPortElement GA_" + gaBlock.mId + "ReqPrtList[] = {\n"
                maxMdbIdLen        = str(max([len(reqPort.enMdbId)       for reqPort in gaBlock.reqPorts]) + len(','))
                maxGaReadModeLen   = str(max([len('GA_e_ReadLatest'), len('GA_e_ReadFrameID')])            + len(','))
                maxIdOffsetLen     = str(max([len(str(reqPort.instance)) for reqPort in gaBlock.reqPorts]) + len(','))
                maxElemInStructLen = str(max([len(reqPort.elemInStruct)  for reqPort in gaBlock.reqPorts]) + len(')'))
                for gaReqPort in gaBlock.reqPorts:
                    genAdapterCfg += ("  { %-" + maxMdbIdLen + "s %-" + maxGaReadModeLen + "s %-" + str(len("MDB_e_CRC_OFF,")) + "s %" + maxIdOffsetLen + "s offsetof("+ gaBlock.reqPort +", %-" + maxElemInStructLen + "s },\n") \
                        % (gaReqPort.enMdbId + ',',                                                          \
                           'GA_e_ReadLatest,' if gaReqPort.instance.upper() == 'L' else 'GA_e_ReadFrameID,', \
                           'MDB_e_CRC_' + ('ON' if gaReqPort.isCrc else 'OFF') + ',',                        \
                           (gaReqPort.instance if gaReqPort.instance.upper() != 'L' else '0') + ',',         \
                           gaReqPort.elemInStruct + ')')
                genAdapterCfg += "};\n"
                genAdapterCfg += "#endif\n\n"
                
    # PRO PORTS
    for gaBlock in gaBlocks:
        if gaBlock.enfg:
            coreListWithEnabledProPorts = [config.coreId for config in gaBlock.configs if config.isOnCore and config.proPort ]
            if coreListWithEnabledProPorts != []:
                # preprocessor #if
                maxCoreLen     = str(max([len(coreId) for coreId in coreListWithEnabledProPorts]) + len(")"))
                maxAlgoCoreLen = str(int(maxCoreLen) + len(gaBlock.mId) + len("_"))
                genAdapterCfg += ("#if   (defined(%-" + maxCoreLen + "s && defined(%-" + maxAlgoCoreLen + "s)") % (coreListWithEnabledProPorts[0] + ')', gaBlock.mId + '_' + coreListWithEnabledProPorts[0] + ')')
                for coreId in coreListWithEnabledProPorts[1:]:
                    genAdapterCfg += ("\\\n   || (defined(%-" + maxCoreLen + "s && defined(%-" + maxAlgoCoreLen + "s)") % (coreId + ')', gaBlock.mId + '_' + coreId + ')')
                genAdapterCfg += "\n"
                #PROVIDED PORTS
                if gaBlock.proPorts != []:
                    genAdapterCfg += "const t_GA_proPortElement GA_" + gaBlock.mId + "ProPrtList[] = {\n"
                    maxMdbIdLen        = str(max([len(proPort.enMdbId)       for proPort in gaBlock.proPorts]) + len(','))
                    maxElemInStructLen = str(max([len(proPort.elemInStruct)  for proPort in gaBlock.proPorts]) + len(')'))
                    for gaProPort in gaBlock.proPorts:
                        genAdapterCfg += ("  { %-" + maxMdbIdLen + "s offsetof("+ gaBlock.proPort +", %-" + maxElemInStructLen + "s },\n") % (gaProPort.enMdbId + ',', gaProPort.elemInStruct + ')')
                    genAdapterCfg += "};\n"
                    genAdapterCfg += "#endif\n\n"
    
    # GA_t_AlgoId:
    algosPerCore = {}
    for gaBlock in gaBlocks:
        if gaBlock.enfg:
            for configEntry in gaBlock.configs:
                if configEntry.isOnCore:
                    if not configEntry.coreId in algosPerCore:
                        algosPerCore[configEntry.coreId] = []
                    algosPerCore[configEntry.coreId].append({'algo' : gaBlock, 'config' : configEntry})
    genAdapterCfg += 'typedef enum {\n'
    for core, dicts in sorted(algosPerCore.iteritems()):
        genAdapterCfg += '#ifdef ' + core + '\n'
        for dict in dicts:
            genAdapterCfg += '  GA_' + dict['algo'].mId + '_ID,\n'
        genAdapterCfg += '#endif\n\n'
    genAdapterCfg += '  GA_MAX_ALGO_ID\n} GA_t_AlgoId;\n\n'
    
    # GA_algoElement GA_PortConfig
    genAdapterCfg += 'const t_GA_algoElement GA_PortConfig[GA_MAX_ALGO_ID] = {\n'
    for core, dicts in sorted(algosPerCore.iteritems()):
        genAdapterCfg += '#ifdef ' + core + '\n'
        maxReqPortLen     = str(max([len(dict['config'].reqPort)      + len('sizeof(),')      if dict['config'].reqPort else len('0')     for dict in dicts]))
        maxProPortLen     = str(max([len(dict['config'].proPort)      + len('sizeof(),')      if dict['config'].proPort else len('0')     for dict in dicts]))
        maxAlgoNameReqLen = str(max([len(dict['algo'].mId)            + len('GA_ReqPrtList,') if dict['config'].reqPort else len('NULL,') for dict in dicts]))
        maxAlgoNameProLen = str(max([len(dict['algo'].mId)            + len('GA_ProPrtList,') if dict['config'].proPort else len('NULL,') for dict in dicts]))
        maxTaskIdLen      = str(max([len(dict['algo'].taskId)         + len(',')                                                          for dict in dicts]))
        maxQualityLen     = str(max([len(dict['config'].qualityLevel) + len('GA_e_QL_')                                                   for dict in dicts]))
        for dict in dicts:
            genAdapterCfg += ('  { %2s, %2s, %-' + maxReqPortLen + 's %-' + maxProPortLen + 's %-' + maxAlgoNameReqLen + 's %-' + maxAlgoNameProLen +'s %-' + maxTaskIdLen + 's %-' + maxQualityLen + 's },\n') \
             % (len(dict['algo'].reqPorts) if dict['config'].reqPort else '0',                    \
                len(dict['algo'].proPorts) if dict['config'].proPort else '0',                    \
                ('sizeof('+dict['config'].reqPort+'),') if dict['config'].reqPort else '0,',      \
                ('sizeof('+dict['config'].proPort+'),') if dict['config'].proPort else '0,',      \
                'GA_' + dict['algo'].mId + 'ReqPrtList,' if dict['config'].reqPort else 'NULL,',  \
                'GA_' + dict['algo'].mId + 'ProPrtList,' if dict['config'].proPort else 'NULL,',  \
                dict['algo'].taskId + ',',                                                        \
                'GA_e_QL_' + dict['config'].qualityLevel)
        genAdapterCfg += '#endif\n\n'
    genAdapterCfg += '};\n'

    patchFile(outFile, 'GEN_ADAPTER_CFG', genAdapterCfg)

FileGenerators = {}
FileGenerators["MDB"] = [ FileGenerator("mdb_cluster.h",            "",                    gen_mdb_cluster_h),
                          FileGenerator("mdb_database.cpp",         "",                    gen_mdb_database_cpp),
                          FileGenerator("mdb_database.h",           "",                    gen_mdb_database_h),
                          FileGenerator("sw_measfreezes_cfg.cpp",   "",                    gen_sw_measfreezes_cfg_cpp) ]
FileGenerators["IPC"] = [ FileGenerator("ipc_cluster_sync_cfg.cpp", "ipc_database_config", gen_ipc_cluster_cync_cfg_cpp),
                          FileGenerator("ipc_sync_cfg.c",           "ipc_database_config", gen_ipc_sync_cfg_c),
                          FileGenerator("ipc_sync_cfg.h",           "ipc_database_config", gen_ipc_sync_cfg_h),
                          FileGenerator("ipc_sync_iuc_cfg.c",       "ipc_database_config", gen_ipc_sync_iuc_cfg_c),
                          FileGenerator("ipc_sync_iuc_cfg.h",       "ipc_database_config", gen_ipc_sync_iuc_cfg_h) ]
FileGenerators["GA"]  = [ FileGenerator("gen_adapter_conf.h",       "",                    gen_gen_adapter_conf_h) ]

# The following defines all used XML tags/attributes for finding the entries
class MdbXmlTags:
    "container for all the xml tags for the mdb configuration"
    mdb             = "mdb"
    mid             = "mID"
    uid             = "uID"
    enfg            = "ENfg"
    dataType        = "Data_Type"
    copyAtStartup   = "Copy_At_Startup_To"
    dmaConfig       = "DMA_Config"
    dmaIs           = "is"
    dmaDataSection  = "DMA_Data_Section"
    dmaDataPtr      = "DMA_DataPtr_In_Cluster"
    dmaDataType     = "DMA_Data_Type"
    dmaArraySize    = "DMA_ArraySize"
    dmaDataAlign    = "DMA_Data_Align"
    dmaIsExtPtr     = "DMA_Is_External_Pointer"
    dmaMemBase      = "DMA_Memory_Base"
    dmaComments     = "DMA_Comments"
    isProtRead      = "Is_Prot_Read"
    isPcisSync      = "Is_PCIs_Sync"
    isPrefill       = "Is_Prefill"
    isFifoMode      = "Is_FIFO_Mode"
    dataAlign       = "Data_Align"
    mtsVirtualAddr  = "MTS_Virtual_Address"
    mtsCycleId      = "MTS_Cycleld"
    ringBufferSize  = "Ring_Buffer_Size"
    ipcConfig       = "IPC_Config"
    ipcNorm         = "IPC_Norm"
    ipcIob          = "IPC_IOB"
    generalComments = "General_Comments"
    dataSection     = "Data_Section"
    isCrc           = "Is_CRC"

class GaXmlTags:
    "container for all the xml tags for the ga configuration"
    ga           = "ga"
    mId          = "mID"
    uId          = "uID"
    enForProd    = "EN_for_Prod"
    enfg         = "ENfg"
    interface    = "Interface"
    taskId       = "Task_ID"
    fswResp      = "FSW_resp"
    algoResp     = "ALGO_resp"
    comment      = "Comment"
    fullName     = "Full_Name"
    gaConf       = "GA_Conf"
    elCount      = "ElCount"
    entry        = "entry"
    sId          = "sID"
    coreId       = "Core_ID"
    reqPort      = "ReqPort"
    proPort      = "ProPort"
    gaReqPort    = "GA_ReqPort"
    gaProPort    = "GA_ProPort"
    qualityLevel = "Quality_Level"
    enAlgoOnCore = "EN_AlgoOnCore"
    instance     = "Instance"
    elemInStruct = "ElemInStruct"
    isCrc        = "Is_CRC"
    enMdbId      = "EN_MDB_ID"


def parseXml(xmlFile):
    """ parses the given xmlFile (absolute path!)
    It does some sanity checks and returns an array of  MdbClusters or GAinstances depending on the given file."""
    
    def checkTrueFalse(input):
        "tries to interpret the given input string as a boolean. Returns true or false."
        regexTrue  = r'(?i)^(yes|true|x)$'
        regexFalse = r'(?i)^(no|false)$'

        """little helper function"""
        if re.match(regexTrue, input):
            return True
        elif re.match(regexFalse, input):
            return False
        else:
            return None
    
    def getXmlChild(parent, child):
        """returns the underlying element with the child tag.
        throws an exception if there is no or multiple child elements with the given tag."""
        children = parent.findall(child)
        if len(children) != 1:
            raise Exception("multiple or no " + child + " attribute in " + str(parent))
        return children[0]
    
    def getXmlChildText(parent, child, newLineAllowed=False, emptyAllowed=False):
        """Retrieves the text of a child item"""
        children = parent.findall(child)
        if len(children) != 1:
            raise Exception("multiple or no " + child + " attribute in " + str(parent))
        if not emptyAllowed and children[0].text.strip() == "":  #strip() because it might be like this:
                                                                 # <tag>
                                                                 # </tag>
                                                                 # then, the content is "\n"
            raise Exception("empty " + child + " attribute in " + str(parent))
        elif not newLineAllowed and (children[0].text != None) and ('\n' in children[0].text.strip()):
            raise Exception(child + " contains a newline in " + str(parent))
        else:
            return children[0].text.strip() if children[0].text else ""
    
    def getDmaConfig(parent):
        """We need this extra function because of the incredibly well designed, consistent and well-thought-out XML structure"""
        dmaConfigs = parent.findall(MdbXmlTags.dmaConfig)
        if len(dmaConfigs) != 1:
            raise Exception("multiple or no DMA config attributes in " + parent.attrib[MdbXmlTags.mid])
        boolDmaConfig = checkTrueFalse(dmaConfigs[0].attrib[MdbXmlTags.dmaIs])
        if boolDmaConfig is None:
            raise Exception("Content of \"is\" attribute in DMA_Config of " + parent.attrib[MdbXmlTags.mid] + " ("+dmaConfigs[0].attrib[MdbXmlTags.dmaIs] + ") is invalid!")
        else:
            return boolDmaConfig
        
    def noneIfEmpty(string):
        "returns None if the given string is empty"
        return None if string == "" else string
    
    root = ET.parse(xmlFile).getroot()
    m = re.search(r'(mdb|ga)_config_(\w+)\b', root.tag, re.IGNORECASE)
    if m:
        configType = m.group(1).lower()
        project    = m.group(2).lower()
        print "configType: " + configType + "\nproject: " + project
    
        # ========================================= MDB SECTION ==================================================================================
        if configType == "mdb":
            mdbClusters = []
            for mdbChild in root: #for each mdb entry
                if MdbXmlTags.mdb == mdbChild.tag: #if it's an mdb entry
                    tmpMdbCluster = MdbCluster()
                    tmpMdbCluster.mId      =                mdbChild.attrib[MdbXmlTags.mid]
                    tmpMdbCluster.uId      =            int(mdbChild.attrib[MdbXmlTags.uid])
                    tmpMdbCluster.enfg     = checkTrueFalse(mdbChild.attrib[MdbXmlTags.enfg])
                    #check plausibility
                    if not (100000 <= tmpMdbCluster.uId and tmpMdbCluster.uId <= 199999):
                        raise Exception("uid " + tmpMdbCluster.uId + " is not in range")
                    if tmpMdbCluster.enfg is None:
                        raise Exception("ENfg " + mdbChild.attrib[MdbXmlTags.enfg] + "is not valid in " + tmpMdbCluster.mId)
                    if not tmpMdbCluster.enfg: #actually, all of these entries must be "Yes" - no "No" allowed.
                        warn("ENfg " + mdbChild.attrib[MdbXmlTags.enfg] + " is not \"Yes\" in " + tmpMdbCluster.mId + '. Please remove it!', 1)
                    if not re.match(r'MDB_e_CL_', tmpMdbCluster.mId):
                        raise Exception("invalid cluster ID: " + tmpMdbCluster.mId)
                    
                    # now parse all the child elements of mdbChild
                    tmpMdbCluster.dataType        =                getXmlChildText(mdbChild, MdbXmlTags.dataType)
                    tmpMdbCluster.copyAtStartupTo =                getXmlChildText(mdbChild, MdbXmlTags.copyAtStartup, emptyAllowed=True)
                    if tmpMdbCluster.copyAtStartupTo == "":
                        tmpMdbCluster.copyAtStartupTo = None

                    tmpMdbCluster.dataSection     =                getXmlChildText(mdbChild, MdbXmlTags.dataSection)
                    tmpMdbCluster.dataAlign       =            int(getXmlChildText(mdbChild, MdbXmlTags.dataAlign))
                    tmpMdbCluster.ringBufferSize  =            int(getXmlChildText(mdbChild, MdbXmlTags.ringBufferSize))

                    tmpMdbCluster.mtsVirtAddr     =    noneIfEmpty(getXmlChildText(mdbChild, MdbXmlTags.mtsVirtualAddr, emptyAllowed=True))
                    tmpMdbCluster.mtsCycleId      =    noneIfEmpty(getXmlChildText(mdbChild, MdbXmlTags.mtsCycleId, emptyAllowed=True))
                    if (tmpMdbCluster.mtsCycleId is None) ^ (tmpMdbCluster.mtsVirtAddr is None): #this is an xor - either both are none, or both are set. anything else is bad!
                        warn(MdbXmlTags.mtsVirtualAddr + " and " + MdbXmlTags.mtsCycleId + " are not both set or unset for " + tmpMdbCluster.mId, 0)
                    if tmpMdbCluster.mtsCycleId is not None:
                        tmpMdbCluster.mtsCycleId = int(tmpMdbCluster.mtsCycleId)

                    raw_ipcConfig                 =    noneIfEmpty(getXmlChildText(mdbChild, MdbXmlTags.ipcConfig, emptyAllowed=True))
                    if raw_ipcConfig in IpcConfigMap:
                        if raw_ipcConfig.lower() == 'i_do_nothing_here' or raw_ipcConfig.lower() == 'xxx':
                            warn("Placeholders for \"nothing\" shall not be used ("+raw_ipcConfig+" found in " + tmpMdbCluster.mId + ")",2)
                            tmpMdbCluster.ipcConfig = None
                        else:
                            #tmpMdbCluster.ipcConfig = IpcConfigMap[raw_ipcConfig]
                            tmpMdbCluster.ipcConfig = raw_ipcConfig
                    elif raw_ipcConfig is None:
                        tmpMdbCluster.ipcConfig = ""
                    else:
                        raise Exception(str(raw_ipcConfig) + " is not a valid ipc config in " + tmpMdbCluster.mId)
                    
                    tmpMdbCluster.ipcNorm        =  checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.ipcNorm, emptyAllowed=True))
                    tmpMdbCluster.ipcIob         =  checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.ipcIob, emptyAllowed=True))
                    tmpMdbCluster.generalComment =     noneIfEmpty(getXmlChildText(mdbChild, MdbXmlTags.generalComments, newLineAllowed=True, emptyAllowed=True))

                    if tmpMdbCluster.ringBufferSize < 1:
                        raise Exception("RingBufferSize of " + tmpMdbCluster.mId + " is < 1")
                    tmpMdbCluster.dmaConfig      = getDmaConfig(mdbChild)
                    if tmpMdbCluster.dmaConfig: # if DMA_Config is true / "Yes"
                        # then parse the children
                        tmpDmaConfig = mdbChild.find(MdbXmlTags.dmaConfig) # this is valid, because it has already been tested in getDmaConfig(..)
                        tmpMdbCluster.dmaDataSection =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaDataSection)
                        if not tmpMdbCluster.dmaDataSection or tmpMdbCluster.dmaDataSection == "":
                            raise Exception("DMA_Data_Section is empty for cluster " + tmpMdbCluster.mId)
                        tmpMdbCluster.dmaDataPtrInCl =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaDataPtr)
                        tmpMdbCluster.dmaDataType    =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaDataType)
                        tmpMdbCluster.dmaArraySize   =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaArraySize)
                        tmpMdbCluster.dmaDataAlign   =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaDataAlign)
                        tmpMdbCluster.dmaIsExtPtr    = checkTrueFalse(getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaIsExtPtr))
                        tmpMdbCluster.dmaMemBase     =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaMemBase,        emptyAllowed=True)
                        if tmpMdbCluster.dmaMemBase == "":
                            tmpMdbCluster.dmaMemBase = "MDB_e_NULL"
                        tmpMdbCluster.dmaComments    =                getXmlChildText(tmpDmaConfig, MdbXmlTags.dmaComments, True, emptyAllowed=True) #allow newline in comment

                    tmpMdbCluster.isProtRead     = checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.isProtRead))
                    tmpMdbCluster.isPcisSync     = checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.isPcisSync))
                    tmpMdbCluster.isPrefill      = checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.isPrefill))
                    tmpMdbCluster.isFifoMode     = checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.isFifoMode))
                    tmpMdbCluster.isCrc          = checkTrueFalse(getXmlChildText(mdbChild, MdbXmlTags.isCrc))
                    if    tmpMdbCluster.isProtRead is None \
                       or tmpMdbCluster.isPcisSync is None \
                       or tmpMdbCluster.isPrefill  is None \
                       or tmpMdbCluster.isFifoMode is None \
                       or tmpMdbCluster.isCrc      is None:
                        raise Exception("One of isProtRead, isPcisSync, isPrefill, isFifoMode or isCrc is empty for cluster " + tmpMdbCluster.mId)
                    if tmpMdbCluster.isProtRead == True:
                        raise Exception("isProtRead is set for cluster " + tmpMdbCluster.mId + ", which is not allowed.")

                    # all checks passed without exception
                    mdbClusters.append(tmpMdbCluster)

                else:
                    if re.match(r'GENERAL_INFO|SELECTIVE_INFO|STATIC_INFO', mdbChild.tag):
                        pass #this is actually fine. We just ignore these entries. It's only relevant for the cepi tool.
                    else:
                        warn(mdbChild.tag + " is an invalid child of root " + root.tag + "\nThis xml file is corrupted or doesn't match this generation script.", 0)

            mdbClusters.sort(key=lambda cluster: cluster.mId)

            #check for uniqueness of clusters ids and uids
            uidSet = set()
            midSet = set()
            for cluster in mdbClusters:
                if cluster.mId in midSet:
                    raise Exception(cluster.mId + " is not a unique mid!")
                if cluster.uId in uidSet:
                    raise Exception(cluster.uId + " is not a unique uid!")
                uidSet.add(cluster.uId)
                midSet.add(cluster.mId)
            return configType, project, mdbClusters

        # ========================================= GA SECTION ===================================================================================
        elif configType == "ga":
            gaBlocks = []
            for gaChild in root: #for each mdb entry
                if GaXmlTags.ga == gaChild.tag: #if it's a ga entry
                    tmpGaBlock = GaBlock()
                    tmpGaBlock.mId       =                gaChild.attrib[GaXmlTags.mId]
                    tmpGaBlock.uId       =            int(gaChild.attrib[GaXmlTags.uId])
                    if not (200000 <= tmpGaBlock.uId and tmpGaBlock.uId <= 299999):
                        raise Exception("uid in gaBlock " + tmpGaBlock.mId + " (" + tmpGaBlock.uId + ") is not in a valid range.")
                    tmpGaBlock.enfg      = checkTrueFalse(gaChild.attrib[GaXmlTags.enfg])
                    tmpGaBlock.interface =    noneIfEmpty(getXmlChildText(gaChild, GaXmlTags.interface,                    emptyAllowed=True))
                    tmpGaBlock.taskId    =                getXmlChildText(gaChild, GaXmlTags.taskId)

                    try:
                        tmpGaBlock.fswResp =  noneIfEmpty(getXmlChildText(gaChild, GaXmlTags.fswResp,                      emptyAllowed=True))
                    except Exception:
                        warn("There is no FSW_Resp field in GA config for " + tmpGaBlock.mId, 1)
                    try:
                        tmpGaBlock.algoResp = noneIfEmpty(getXmlChildText(gaChild, GaXmlTags.algoResp,                     emptyAllowed=True))
                    except Exception:
                        warn("There is no Algo_Resp field in GA config for " + tmpGaBlock.mId, 1)

                    try:
                        tmpGaBlock.comment  =             getXmlChildText(gaChild, GaXmlTags.comment, newLineAllowed=True, emptyAllowed=True)
                    except Exception:
                        warn("There is no Comment field in GA config for " + tmpGaBlock.mId, 1)

                    tmpGaBlock.enForProd = checkTrueFalse(getXmlChildText(gaChild, GaXmlTags.enForProd,                    emptyAllowed=True))
                    if tmpGaBlock.enForProd is None:
                        tmpGaBlock.enForProd = False

                    try:
                        tmpGaBlock.fullName  = getXmlChildText(gaChild, GaXmlTags.fullName, emptyAllowed=True)
                    except Exception:
                        warn("There is no Full_Name field in GA config for " + tmpGaBlock.mId, 1)

                    #CONFIG
                    configurations = getXmlChild(gaChild, GaXmlTags.gaConf)
                    if len(configurations.getchildren()) != int(configurations.attrib[GaXmlTags.elCount]):
                        raise Exception("Number of elements (" + str(len(configurations.getchildren())) + ") in the configurations for gaBlock " + tmpGaBlock.mId + " does not match the elCount of " + configurations.attrib[GaXmlTags.elCount])
                    if int(configurations.attrib[GaXmlTags.elCount]) < 1:
                        raise Exception("gaBlock " + tmpGaBlock.mId + " contains less than 1 configuration!")
                    for entry in configurations:
                        if GaXmlTags.entry == entry.tag:
                            tmpGaBlock.configs.append(GaBlock.Config(entry.attrib[GaXmlTags.sId],                                   \
                                                                     getXmlChildText(entry, GaXmlTags.coreId),                      \
                                                         noneIfEmpty(getXmlChildText(entry, GaXmlTags.reqPort, emptyAllowed=True)), \
                                                         noneIfEmpty(getXmlChildText(entry, GaXmlTags.proPort, emptyAllowed=True)), \
                                                                     getXmlChildText(entry, GaXmlTags.qualityLevel),                \
                                                      checkTrueFalse(getXmlChildText(entry, GaXmlTags.enAlgoOnCore))))
                            if tmpGaBlock.configs[-1].reqPort and tmpGaBlock.configs[-1].reqPort.lower() == 'i_do_nothing_here':
                                warn("Placeholders for \"nothing\" shall not be used ("+tmpGaBlock.configs[-1].reqPort+" found in the GA config of " + tmpGaBlock.mId + ")",2)
                        else:
                            raise Exception("Unknown tag (" + entry.tag + ") in config of gaBlock " + tmpGaBlock.mId)

                    # check consistency of req and pro ports
                    # TODO remove this! This should be done by a proper xml setup! The req port shouldn't be repeated in each config entry, but in the GA block directly!
                    for config in tmpGaBlock.configs:
                        if config.reqPort:
                            if not tmpGaBlock.reqPort:
                                tmpGaBlock.reqPort = config.reqPort
                            elif config.reqPort != tmpGaBlock.reqPort:
                                raise Exception(tmpGaBlock.mId + " has multiple reqPorts in the config: " + tmpGaBlock.reqPort + " and " + config.reqPort + ". This is not allowed!")
                        if config.proPort:
                            if not tmpGaBlock.proPort:
                                tmpGaBlock.proPort = config.proPort
                            elif config.proPort != tmpGaBlock.proPort:
                                raise Exception(tmpGaBlock.mId + " has multiple proPorts in the config: " + tmpGaBlock.proPort + " and " + config.proPort + ". This is not allowed!")

                    #REQ_PORTS
                    reqPorts = getXmlChild(gaChild, GaXmlTags.gaReqPort)
                    if len(reqPorts.getchildren()) != int(reqPorts.attrib[GaXmlTags.elCount]):
                        raise Exception("Number of elements (" + str(len(reqPorts.getchildren())) + ") in the reqPorts for gaBlock " + tmpGaBlock.mId + " does not match the elCount of " + reqPorts.attrib[GaXmlTags.elCount])
                    if int(reqPorts.attrib[GaXmlTags.elCount]) < 0:
                        raise Exception("gaBlock " + tmpGaBlock.mId + " contains less than 0 reqPorts!")
                    for entry in reqPorts:
                        if GaXmlTags.entry == entry.tag:
                            tmpGaBlock.reqPorts.append(GaBlock.ReqPort(entry.attrib[GaXmlTags.sId],                    \
                                                                      getXmlChildText(entry, GaXmlTags.elemInStruct), \
                                                                      getXmlChildText(entry, GaXmlTags.instance),     \
                                                       checkTrueFalse(getXmlChildText(entry, GaXmlTags.isCrc)),       \
                                                                      getXmlChildText(entry, GaXmlTags.enMdbId)))
                        else:
                            raise Exception("Unknown tag (" + entry.tag + ") in reqPorts of gaBlock " + tmpGaBlock.mId)

                    #PRO_PORTS
                    proPorts = getXmlChild(gaChild, GaXmlTags.gaProPort)
                    if len(proPorts.getchildren()) != int(proPorts.attrib[GaXmlTags.elCount]):
                        raise Exception("Number of elements (" + str(len(proPorts.getchildren())) + ") in the proPorts for gaBlock " + tmpGaBlock.mId + " does not match the elCount of " + proPorts.attrib[GaXmlTags.elCount])
                    if int(proPorts.attrib[GaXmlTags.elCount]) < 0:
                        raise Exception("gaBlock " + tmpGaBlock.mId + " contains less than 0 proPorts!")
                    for entry in proPorts:
                        if GaXmlTags.entry == entry.tag:
                            tmpGaBlock.proPorts.append(GaBlock.ProPort(entry.attrib[GaXmlTags.sId],                    \
                                                                      getXmlChildText(entry, GaXmlTags.elemInStruct), \
                                                                      getXmlChildText(entry, GaXmlTags.enMdbId)))
                        else:
                            raise Exception("Unknown tag (" + entry.tag + ") in proPorts of gaBlock " + tmpGaBlock.mId)
                    gaBlocks.append(tmpGaBlock)
                        
                else:
                    if re.match(r'GENERAL_INFO|SELECTIVE_INFO|STATIC_INFO', gaChild.tag):
                        pass #this is actually fine. We just ignore these entries. It's only relevant for the cepi tool.
                    else:
                        warn(gaChild.tag + " is an invalid child of root " + root.tag + "\nThis xml file is corrupted or doesn't match this generation script.", 0)

            #check uniqueness of uIDs and mIDs
            uidSet = set()
            midSet = set()
            for block in gaBlocks:
                if block.uId in uidSet:
                    raise Exception(block.uId + " is not a unique uid!")
                if block.mId in midSet:
                    raise Exception(block.mId + " is not a unique mid!")
                uidSet.add(block.uId)
                midSet.add(block.mId)

            return configType, project, gaBlocks
    else:
        warn("could not match root tag in file" +xmlFile, 0)
        raise Exception("could not match root tag in file" + str(xmlFile))
    
def prepareOutFile(fileGenerator, outputDir, templateDir):
    """copies the template to the out directory and renames it, so the generator functions can directly write to the prepared files.
    If the output file is not writable, it will be made writable. Also, any existing file will be overwritten."""
    outFilePath      = os.path.join(os.getcwd(), outputDir, fileGenerator.outDir, fileGenerator.file + tmpFileExtension)
    templateFilePath = os.path.join(os.getcwd(),            templateDir,          fileGenerator.file + templateExtension)
    #copy template to outfilePath
    if os.path.exists(outFilePath):
        if os.path.isfile(outFilePath):
            os.chmod(outFilePath, stat.S_IWRITE)
            os.unlink(outFilePath)
        else:
            raise Exception(outFilePath + " exists but is not a file. Please remove it manually!")
    shutil.copyfile(templateFilePath, outFilePath)
    return outFilePath

def updateOutput(tmpOutFile):
    """Only if the output of the code generation reveals changes in the output files, those files will be replaced.
    If there are no changes, the generated (temporary) files will be deleted.
    This functionality was implemented in order to avoid unnecessary recompilation because of changed files."""
    originalOutFile = re.sub(tmpFileExtension+"$", "", tmpOutFile) #remove extension at the end of the file
    if os.path.exists(originalOutFile):
        if filecmp.cmp(tmpOutFile, originalOutFile):
            #if the files have the same content, just remove the newly generated file and keep the old one to avoid recompilation
            os.remove(tmpOutFile)
        else:
            #if the files don't have the same content, remove the old one and rename the new one.
            os.remove(originalOutFile)
            os.rename(tmpOutFile, originalOutFile)
    else:
        os.rename(tmpOutFile, originalOutFile)
            
def main(argv):
    inputfile   = ''
    outputdir   = ''
    templatedir = ''
    genIPC      = False
    genMDB      = False
    genGA       = False
    genSWAP     = True
    try:
        opts, args = getopt.getopt(argv,"hi:o:t:",["ifile=","odir=","templatedir=","ga","mdb","ipc","noswap"])
    except getopt.GetoptError:
        print 'test.py -i <inputfile> -o <outputdir> -t <templatedir>'
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print """
|============================================================================================|
| test.py -i <inputfile> -o <outputdir> -t <templatedir>                                     |
|============================================================================================|
| Help: script [OPTIONS]                                                                     |
| [OPTIONS]:                                                                                 |
|      -h                        Display this help message                                   |
|      -i  --ifile               Input file that containts the informations                  |
|      -o  --odir                Output directory - files with the same name get overwritten |
|      -t  --templatedir         Template file directory                                     |
|      --ga  generates generic adapter config file                                           |
|      --mdb  generates mdb config files                                                     |
|      --ipc  generates ipc files                                                            |
|      --noswap  generates ipc files without swap-functionpointer                            |
|      if not set -ga or -mdb or -ipc  ->  generates all files files                         |
|============================================================================================|
| All three parameter are necessary as:                                                      |
| Inputfile + Templates = Output                                                             |
| else: script will be aborted                                                               |
|============================================================================================|"""
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputdir = arg
        elif opt in ("-t", "--templatedir"):
            templatedir = arg
        elif opt in ("--ga"):
            genGA = True
        elif opt in ("--mdb"):
            genMDB = True
        elif opt in ("--ipc"):
            genIPC = True
        elif opt in ("--noswap"):
            genSWAP = False
    if genGA == False and genMDB == False and genIPC == False:
        genIPC = True
        genMDB = True
        genGA  = True

    configs = {}

    global currentProject #tell python that this is global
    
    for inputFilePath in inputfile.split("?"):
        configType, currentProject, entries = parseXml(os.path.join(os.getcwd(), inputFilePath))
        configs[configType] = entries

    if genMDB:
        for fileGenerator in FileGenerators["MDB"]:
            tmpOutFile = prepareOutFile(fileGenerator, outputdir, templatedir)
            fileGenerator.function(configs['mdb'], tmpOutFile)
            updateOutput(tmpOutFile)
    if genIPC:
        for fileGenerator in FileGenerators["IPC"]:
            tmpOutFile = prepareOutFile(fileGenerator, outputdir, templatedir)
            fileGenerator.function(configs['mdb'], tmpOutFile, genSWAP)
            updateOutput(tmpOutFile)
    if genGA:
        for fileGenerator in FileGenerators["GA"]:
            tmpOutFile = prepareOutFile(fileGenerator, outputdir, templatedir)
            fileGenerator.function(configs['ga'], tmpOutFile)
            updateOutput(tmpOutFile)

class IpcVersionControlDialog:
    """This is the IPC update dialog"""
    #banana icon
    gifIconBase64 = """\
R0lGODlhEAAQALMAAAAAAP/////5SP/5Xv/6Z//7jf/8of/zNv/fKtGuIMimH01ADPjOJ+C6I///
/wAAACH5BAEAAA4ALAAAAAAQABAAAARN0MlJgaW4LpC7s5xXHUwofmRjdgCRrln7njKjikDh2rBk
GQQBgvcB/XSDYSPBASAEA4I0qbx9GIiDVltVmACMsNjW8GIsjXSa2fMZYREAOw=="""
    padding = {'padx': '1m', 'pady': '1m'}
    
    class GuiModel:
        """This is the data representation of the gui elements"""
        def __init__(self):
            self.oldRteVar = StringVar()
            self.newRteVar = StringVar()
            self.oldIpcVar = StringVar()
            self.newIpcVar = StringVar()
            self.wasCancelled = False

    def __init__(self, tmpOutFile):
        self.toolTips = []
        self.dialogRoot = Tk()
        self.dialogRoot.resizable(False, False)
        self.dialogRoot.title("IPC Version Control")
        
        self.mainFrame = Frame(self.dialogRoot)
        self.mainFrame.pack(fill=BOTH, expand=1)
        
        self.model = IpcVersionControlDialog.GuiModel()

        #line 1
        Label(self.mainFrame, text='#define').grid(row=0, column=0, sticky='w',  **IpcVersionControlDialog.padding)
        Label(self.mainFrame, text='old').    grid(row=0, column=1, sticky='we', **IpcVersionControlDialog.padding)
        Label(self.mainFrame, text='new').    grid(row=0, column=2, sticky='we', **IpcVersionControlDialog.padding)
        #Label(self.mainFrame, text='update'). grid(row=0, column=3, sticky='we', **IpcVersionControlDialog.padding)
        
        #line 2 (RTE)
        Label(self.mainFrame, text='IPC_RTE_TYPE_VERSION').grid(row=1, column=0, sticky='w', **IpcVersionControlDialog.padding)
        self.E_RteOld = Entry(self.mainFrame, state="readonly", textvariable=self.model.oldRteVar)
        self.E_RteOld.grid(row=1, column=1, sticky='we', **IpcVersionControlDialog.padding)
        self.E_RteNew = Entry(self.mainFrame, textvariable=self.model.newRteVar)
        self.E_RteNew.grid(row=1, column=2, sticky='we', **IpcVersionControlDialog.padding)

        #line 3 (IPC) 
        Label(self.mainFrame, text='IPC_SYNC_VERSION').grid(row=2, column=0, sticky='w', **IpcVersionControlDialog.padding)
        self.E_IpcOld = Entry(self.mainFrame, state="readonly", textvariable=self.model.oldIpcVar)
        self.E_IpcOld.grid(row=2, column=1, sticky='we', **IpcVersionControlDialog.padding)
        self.E_IpcNew = Entry(self.mainFrame, textvariable=self.model.newIpcVar)
        self.E_IpcNew.grid(row=2, column=2, sticky='we', **IpcVersionControlDialog.padding)
        
        #line 4 (Buttons)
        self.ButtonFrame = Frame(self.mainFrame) #we need a new frame, because we can't mix pack and grid, but we want those buttons equally big
        self.ButtonFrame.grid(row=3, column=0, columnspan=3)
        self.B_Cancel = Button(self.ButtonFrame, text="Cancel", name="cancelButton", command=self.cancel, width="20")
        self.B_Cancel.pack(expand=1, side=LEFT, **IpcVersionControlDialog.padding)
        self.B_Ok = Button(self.ButtonFrame, text="Ok", name="okButton", command=self.ok, width="20")
        self.B_Ok.pack(expand=1, side=LEFT, **IpcVersionControlDialog.padding)

        self.B_Cancel.configure(command=lambda *ignoreArguments: self.cancel())
        self.dialogRoot.protocol("WM_DELETE_WINDOW", self.cancel)

        self.dialogRoot.update()
        self.dialogRoot.minsize(self.dialogRoot.winfo_width(), self.dialogRoot.winfo_height())
        self.centrify()
        self.B_Ok.focus()
        try: #set application icon - this is just for fun
            img = PhotoImage(data=IpcVersionControlDialog.gifIconBase64)
            self.dialogRoot.tk.call('wm', 'iconphoto', self.dialogRoot._w, img)
        except Exception:
            pass
        self.defaultBG = self.E_IpcOld.cget('bg')
        self.parseOldFile(tmpOutFile)
        self.updateAvailability()
        
        #bindings
        self.model.oldRteVar.trace('w', lambda *ignoreArguments: self.updateAvailability())
        self.model.oldIpcVar.trace('w', lambda *ignoreArguments: self.updateAvailability())
        self.model.newRteVar.trace('w', lambda *ignoreArguments: self.updateAvailability())
        self.model.newIpcVar.trace('w', lambda *ignoreArguments: self.updateAvailability())
    
    def updateAvailability(self):
        """This function is called every time when the user changes some input in order to check its validity and in order to dis- or enable certain gui elements."""
        NumberRegex = r'^\d+$'
        HexRegex    = r'^0x[0-9a-fA-F]+$'
        errBG       = "#ff8888"
        normBG      = self.defaultBG
        self.B_Ok.config(state=('normal')) #disabled
        for toolTip in self.toolTips:
            toolTip.hidetip()
            del(toolTip)
        self.toolTips = []
        removeToolTip(self.E_RteNew)
        removeToolTip(self.E_RteOld)
        removeToolTip(self.E_IpcNew)
        removeToolTip(self.E_IpcOld)
        removeToolTip(self.B_Ok)

        if re.match(NumberRegex, self.model.newRteVar.get().strip()):
            self.E_RteNew.configure(bg=normBG)
            self.toolTips.append(createToolTip(self.E_RteNew, "Put a decimal number here (must be >= the old one)."))
            if re.match(NumberRegex, self.model.oldRteVar.get().strip()):
                self.E_RteOld.configure(bg=normBG)
                if not int(self.model.oldRteVar.get().strip(), 0) <= int(self.model.newRteVar.get().strip(), 0):
                    self.toolTips.append(createToolTip(self.E_RteNew, "The new Rte version must be >= the old version!"))
                    self.E_RteNew.configure(bg=errBG)
                    self.B_Ok.config(state=('disabled'))
                    self.toolTips.append(createToolTip(self.B_Ok, "You are trying to configure an older Rte version than what is already configured."))
            else:
                self.E_RteOld.configure(bg=errBG)
                self.toolTips.append(createToolTip(self.E_RteOld, "Could not find the old version in the existing config file."))
        else:
            self.E_RteNew.configure(bg=errBG)
            self.toolTips.append(createToolTip(self.E_RteNew, "This is not a decimal number."))
            self.B_Ok.config(state=('disabled'))
            self.toolTips.append(createToolTip(self.B_Ok, "The new Rte version is not a decimal number."))
            
        if re.match(HexRegex, self.model.newIpcVar.get().strip()):
            self.E_IpcNew.configure(bg=normBG)
            self.toolTips.append(createToolTip(self.E_IpcNew, "Put a hex number here (must be >= the old one)."))
            if re.match(HexRegex, self.model.oldIpcVar.get().strip()):
                self.E_IpcOld.configure(bg=normBG)
                if not int(self.model.oldIpcVar.get().strip(), 0) <= int(self.model.newIpcVar.get().strip(), 0):
                    self.toolTips.append(createToolTip(self.E_RteNew, "The new Ipc version must be >= the old version!"))
                    self.E_IpcNew.configure(bg=errBG)
                    self.B_Ok.config(state=('disabled'))
                    self.toolTips.append(createToolTip(self.B_Ok, "You are trying to configure an older Ipc version than what is already configured."))
            else:
                self.E_IpcOld.configure(bg=errBG)
                self.toolTips.append(createToolTip(self.E_RteOld, "Could not find the old version in the existing config file."))
        else:
            self.E_IpcNew.configure(bg=errBG)
            self.toolTips.append(createToolTip(self.E_IpcNew, "This is not a hex number."))
            self.B_Ok.config(state=('disabled'))
            self.toolTips.append(createToolTip(self.B_Ok, "The new Ipc version is not a hex number."))
    
    def parseOldFile(self, tmpOutFile):
        """Parses the old generated file to retrieve the old IPC and RTE version"""
        ipcMatch = None
        rteMatch = None
        f = open(re.sub(tmpFileExtension + '$', '', tmpOutFile), "r")
        try:
            for line in f.readlines():
                if not ipcMatch:
                    ipcMatch = re.match(r'#define\s+IPC_SYNC_VERSION\s+((0x)?[0-9a-fA-F]+)\s*$', line.strip())
                    if ipcMatch:
                        self.model.oldIpcVar.set(ipcMatch.group(1))
                        self.model.newIpcVar.set(ipcMatch.group(1))
                        try:
                            # add 1 to the hex value
                            self.model.newIpcVar.set('0x%04x' % (int(self.model.newIpcVar.get().strip(), 0) + 1))
                        except Exception:
                            pass #well, if it didn't work, so what ...
                if not rteMatch:
                    rteMatch = re.match(r'#define\s+IPC_RTE_TYPE_VERSION\s+(\d+)\s*$', line.strip())
                    if rteMatch:
                        self.model.oldRteVar.set(rteMatch.group(1))
                        self.model.newRteVar.set(rteMatch.group(1))
                if ipcMatch and rteMatch:
                    break
        finally:
            f.close()
        if not ipcMatch:
            self.model.oldIpcVar.set("<could not read old file>")
        if not rteMatch:
            self.model.oldRteVar.set("<could not read old file>")
            

    def askUserForVersions(self):
        """ returns a tuple (newRte, newIpc, False) if everything was ok, or (oldRte, oldIpc, True) if the dialog was cancelled."""
        self.dialogRoot.mainloop()
        if self.model.wasCancelled:
            return self.model.oldRteVar.get(), self.model.oldIpcVar.get(), self.model.wasCancelled
        return self.model.newRteVar.get(), self.model.newIpcVar.get(), self.model.wasCancelled

    def ok(self):
        """callback for the OK button"""
        self.dialogRoot.destroy()
    
    def cancel(self):
        """callback for the cancel button or for the close button"""
        self.model.wasCancelled = True
        self.dialogRoot.destroy()
    
    def centrify(self):
        """Puts the dialog to the screen center"""
        w = self.dialogRoot.winfo_screenwidth()
        h = self.dialogRoot.winfo_screenheight()
        size = tuple(int(_) for _ in self.dialogRoot.geometry().split('+')[0].split('x'))
        x = w/2 - size[0]/2
        y = h/2 - size[1]/2
        self.dialogRoot.geometry("+%d+%d" % (x, y))

if __name__ == "__main__":
    main(sys.argv[1:])
    
# vim: textwidth=0: tabstop=4: softtabstop=4: shiftwidth=4: expandtab: autoindent: smartindent: smarttab: