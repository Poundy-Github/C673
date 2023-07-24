import os
import stat
import shutil
import getpass
import Tkinter
import subprocess
import tkFileDialog
import tkMessageBox
import xml.etree.ElementTree as ET

def newProcess(cmdLine, workingDir = None):
  proc = subprocess.Popen(
    cmdLine,
    cwd    = workingDir,
    bufsize=1024,
    stdout = subprocess.PIPE,
    stderr = subprocess.PIPE,
    stdin  = subprocess.PIPE,
    creationflags=0x08000000    )
  return proc

def deformat(string):
  return string.decode('cp852').encode('utf-8')

def on_rm_error( func, path, exc_info):
  # path contains the path of the file that couldn't be removed
  # let's just assume that it's read-only and unlink it.
  os.chmod( path, stat.S_IWRITE )
  os.unlink( path )

class InfectProject():
  def __init__(self):
    self.DEFAULT_FONT = 'SegoeUI 10'
    
    self.SRC_CMN     = r'04_Engineering\01_Source_Code\common'
    self.SRC_ALG     = r'04_Engineering\01_Source_Code\algo'
    self.SRC_ALG_CST = r'04_Engineering\01_Source_Code\algo\00_Custom'
    self.WS_ALG      = r'04_Engineering\03_Workspace\algo'
    self.DLV         = r'04_Engineering\05_Deliverables'
    self.DLV_ALG_CFG = r'cfg\algo'
    self.DLV_ALG_INC = r'include\algo'
    self.TST_MTS     = r'05_Testing\06_Test_Tools\mts'
    self.TST_ALG_CFG = r'05_Testing\06_Test_Tools\mts_measurement\cfg\algo'
    
    self.__src_alg_cst_root = ''
    self.__dlv_root         = ''
    
    self.__root = Tkinter.Tk()
    
    self.__selectedSandboxToBeInfected = Tkinter.StringVar(self.__root)
    self.__selectedComponentSandbox    = Tkinter.StringVar(self.__root)
    self.__selectedComponent           = Tkinter.StringVar(self.__root)
    self.__selectedCustomDevPath       = Tkinter.StringVar(self.__root)
    
    self.__IMSRunning = self.isIMSRunning()
    self.__sandboxes  = self.__getSandboxes()
    self.__setupFrame()
  
  def run(self):
    self.__root.mainloop()
  
  def __setupFrame(self):
    self.__frame  = Tkinter.Frame(self.__root, borderwidth=6)
    self.__frame2 = Tkinter.Frame(self.__root, borderwidth=6)
    self.__frame3 = Tkinter.Frame(self.__root, borderwidth=6)
    self.__frame4 = Tkinter.Frame(self.__root, borderwidth=6)
    
    self.__root.resizable(width=Tkinter.NO, height=Tkinter.NO)
    self.__root.title( 'Infect component into project' + (' (IMS not running)' if not self.__IMSRunning else '') )
    
    row = 0
    padding = 2
    
    Tkinter.Label( self.__frame, text='Project to infect:', font = self.DEFAULT_FONT + ' bold').grid( row=row, column=0 )
    
    self.__projectWidget = Tkinter.Entry( self.__frame, width=60 )
    self.__projectWidget.grid( row=row, column=1, padx=padding, pady=padding )
    
    self.__browseProjectButton = Tkinter.Button( self.__frame, text='Browse...', command=lambda: self.__selectFolder(self.__projectWidget, self.__selectedSandboxToBeInfected) )
    self.__browseProjectButton.grid( row=row, column=2, padx=padding, pady=padding )
    
    if self.__IMSRunning:
      sandboxesReadyToBeInfected = self.__getSandboxesReadyToBeInfected()
      if len(sandboxesReadyToBeInfected) == 0:
        sandboxesReadyToBeInfected.append('')
      self.__infectOptionMenu = Tkinter.OptionMenu( self.__frame, self.__selectedSandboxToBeInfected, *sorted([os.path.dirname(item) for item in sandboxesReadyToBeInfected]), command=self.__selectInfect )
      self.__infectOptionMenu.config(width=60)
      self.__infectOptionMenu.grid( row=row, column=3, padx=padding, pady=padding )
    
    row += 1
    
    Tkinter.Label( self.__frame, text='Component Sandbox:', font = self.DEFAULT_FONT + ' bold').grid( row=row, column=0 )
    
    self.__componentSbxWidget = Tkinter.Entry( self.__frame, width=60 )
    self.__componentSbxWidget.grid( row=row, column=1, padx=padding, pady=padding )
    
    self.__browseComponentButton = Tkinter.Button( self.__frame, text='Browse...', command=lambda: self.__selectFolder(self.__componentSbxWidget, self.__selectedComponentSandbox) )
    self.__browseComponentButton.grid( row=row, column=2, padx=padding, pady=padding )
    
    if self.__IMSRunning:
      componentSandboxes = self.__getValidComponentSandboxes()
      if len(componentSandboxes) == 0:
        componentSandboxes.append('')
      self.__componentSbxOptionMenu = Tkinter.OptionMenu( self.__frame, self.__selectedComponentSandbox, *sorted([os.path.dirname(item) for item in componentSandboxes]), command=self.__selectComponentSbx )
      self.__componentSbxOptionMenu.config(width=60)
      self.__componentSbxOptionMenu.grid( row=row, column=3, padx=padding, pady=padding )
    
    row = 0
    
    Tkinter.Label( self.__frame2, text='Component to link:', font = self.DEFAULT_FONT + ' bold').grid( row=row, column=0 )
    
    self.__componentWidget = Tkinter.Entry( self.__frame2, width=10 )
    self.__componentWidget.grid( row=row, column=1, padx=padding, pady=padding )
    
    self.__componentOptionMenu = Tkinter.OptionMenu( self.__frame2, self.__selectedComponent, '' )
    self.__componentOptionMenu.config(width=10)
    self.__componentOptionMenu.grid( row=row, column=3, padx=padding, pady=padding )
    
    row = 0
    
    Tkinter.Label( self.__frame3, text='Custom Devpath to link (leave empty for base):', font = self.DEFAULT_FONT + ' bold').grid( row=row, column=0 )
    
    self.__customDevpathWidget = Tkinter.Entry( self.__frame3, width=30 )
    self.__customDevpathWidget.grid( row=row, column=1, padx=padding, pady=padding )
    
    if self.__IMSRunning:
      customDevPaths = self.__getValidCustomDevPaths()
      if len(customDevPaths) == 0:
        customDevPaths.append('')
      self.__componentCstDevPathOptionMenu = Tkinter.OptionMenu( self.__frame3, self.__selectedCustomDevPath, *customDevPaths, command=self.__selectComponentCstDevPath )
      self.__componentCstDevPathOptionMenu.config(width=30)
      self.__componentCstDevPathOptionMenu.grid( row=row, column=3, padx=padding, pady=padding )
    
    row = 0
    
    self.__infectButton = Tkinter.Button( self.__frame4, text='Infect', font = self.DEFAULT_FONT + ' bold', width=20, command=self.__infect )
    self.__infectButton.grid( row=row, column=0, padx=padding, pady=padding )
    
    self.__infectButton = Tkinter.Button( self.__frame4, text='Desinfect', font = self.DEFAULT_FONT + ' bold', width=20, command=self.__desinfect )
    self.__infectButton.grid( row=row, column=1, padx=padding, pady=padding )
    
    self.__frame.pack()
    self.__frame2.pack()
    self.__frame3.pack()
    self.__frame4.pack()
  
  def __infect(self):
    if self.__projectWidget.get().strip() != '':
      self.__selectedSandboxToBeInfected.set( self.__projectWidget.get().strip() )
    
    if self.__componentSbxWidget.get().strip() != '':
      self.__selectedComponentSandbox.set( self.__componentSbxWidget.get().strip() )
    
    if self.__componentWidget.get().strip() != '':
      self.__selectedComponent.set( self.__componentWidget.get().strip() )
    
    if   self.__selectedSandboxToBeInfected.get() == ''\
      or self.__selectedComponentSandbox.get()    == ''\
      or self.__selectedComponent.get()           == '':
      return
    
    self.__checkCustomPaths()
    
    if tkMessageBox.askquestion( "Infect", "The following sandbox will be infected\n    " +\
      self.__selectedSandboxToBeInfected.get() +\
      "\n\nAll relevant folders and their content (like source-code, workspace, cfg, etc.) of component " + self.__selectedComponent.get().upper() + " will be deleted and then symlinked to\n    " +\
      self.__selectedComponentSandbox.get() +\
      "\n\nDo you want to continue?", icon='warning') != 'yes':
      return
    
    linkPairs = self.__createLinkPairs()
    
    linkedFolders = []
    
    for src, dst in linkPairs:
      if self.__link( src, dst ):
        linkedFolders.append( src + " <==> " + dst )
    
    tkMessageBox.showinfo("Infect result", "The following links have been created:\n\n" + "\n\n".join(linkedFolders))
  
  def __desinfect(self):
    if self.__projectWidget.get().strip() != '':
      self.__selectedSandboxToBeInfected.set( self.__projectWidget.get().strip() )
    
    if self.__componentWidget.get().strip() != '':
      self.__selectedComponent.set( self.__componentWidget.get().strip() )
    
    if   self.__selectedSandboxToBeInfected.get() == ''\
      or self.__selectedComponent.get()           == '':
      return
    
    linkPairs = self.__createLinkPairs()
    
    linksRemoved = []
    
    for src, dst in linkPairs:
      if self.__islink(dst):
        os.rmdir(dst)
        linksRemoved.append(dst)
    
    tkMessageBox.showinfo("Desinfect result", "The following links have been removed:\n    " + "\n    ".join(linksRemoved))
  
  def __checkCustomPaths(self):
    self.__selectedCustomDevPath.set( self.__customDevpathWidget.get().strip() )
    
    if self.__selectedCustomDevPath.get() == '':
      self.__src_alg_cst_root = os.path.join( self.__selectedComponentSandbox.get(), self.SRC_ALG_CST, self.__selectedComponent.get().strip().lower() )
      self.__dlv_root         = os.path.join( self.__selectedComponentSandbox.get(), self.DLV )
      return
    else:
      self.__src_alg_cst_root = ''
      self.__dlv_root         = ''
    
    candidates = [ item[0] for item in self.__sandboxes['variant'] if item[2] == self.__selectedCustomDevPath.get().strip() ]
    repoLocationRoot = '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/' + self.__getMksComponent( self.__selectedComponent.get() )
    
    for sbx in candidates:
      proc = newProcess(['mksapiviewer', '--iplocal', '--xml', 'si', 'sandboxinfo', '--hostname=ims-adas', '--port=7001', '--noassociatedIssues', '--noattributes', '--noshowCheckpointDescription', '--sandbox=' + sbx])
      ret, err = proc.communicate()
      
      if err != '':
        tkMessageBox.showinfo('MKS Error', err)
      
      root = ET.fromstring( deformat(ret) )
      repoLocation = root.find('./WorkItems[@selectionType="Sandbox"]/WorkItem[@id="' + sbx.replace('\\', '/') + '"]/Field[@name="projectName"]/Value[@dataType="string"]').text
      repoLocation = os.path.dirname(repoLocation)
      
      if (self.__src_alg_cst_root == '') and repoLocation.endswith( self.SRC_ALG_CST.replace('\\', '/') + '/' + self.__selectedComponent.get().strip().lower() ):
        self.__src_alg_cst_root = os.path.dirname(sbx)
      
      if (self.__dlv_root == '') and repoLocation.endswith( '05_Deliverables' ) and repoLocation.startswith( repoLocationRoot ):
        self.__dlv_root = os.path.dirname(sbx)
    
    if self.__src_alg_cst_root == '':
      self.__src_alg_cst_root = os.path.join( os.path.dirname(self.__selectedComponentSandbox.get())
        ,                                     self.__selectedComponent.get().strip().upper() + '_' + self.__selectedCustomDevPath.get().strip()
        ,                                     self.SRC_ALG_CST
        ,                                     self.__selectedComponent.get().strip().lower() )
      
      if not os.path.isdir( self.__src_alg_cst_root ):
        os.makedirs(self.__src_alg_cst_root)
      
      self.__createSandbox( self.__src_alg_cst_root
        ,                   repoLocationRoot + '/' + self.SRC_ALG_CST.replace('\\', '/') + '/' + self.__selectedComponent.get().strip().lower() + '/project.pj'
        ,                   self.__selectedCustomDevPath.get().strip() )
    
    if self.__dlv_root == '':
      self.__dlv_root = os.path.join( os.path.dirname(self.__selectedComponentSandbox.get())
        ,                             self.__selectedComponent.get().strip().upper() + '_' + self.__selectedCustomDevPath.get().strip()
        ,                             self.DLV )
      
      if not os.path.isdir( self.__dlv_root ):
        os.makedirs(self.__dlv_root)
      
      self.__createSandbox( self.__dlv_root, repoLocationRoot + '/' + self.DLV.replace('\\', '/') + '/project.pj', self.__selectedCustomDevPath.get().strip() )
  
  def __createLinkPairs(self):
    return [ ( os.path.join( self.__selectedComponentSandbox.get()   , self.SRC_ALG, self.__selectedComponent.get() ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.SRC_ALG, self.__selectedComponent.get() ) ),
               
             ( os.path.join( self.__src_alg_cst_root ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.SRC_ALG_CST, self.__selectedComponent.get() ) ),
               
             ( os.path.join( self.__src_alg_cst_root                                                                    + "_wrp" ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.SRC_ALG_CST, self.__selectedComponent.get() + "_wrp" ) ),
               
             ( os.path.join( self.__selectedComponentSandbox.get()   , self.WS_ALG, self.__selectedComponent.get() ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.WS_ALG, self.__selectedComponent.get() ) ),
               
             ( os.path.join( self.__selectedComponentSandbox.get()   , self.WS_ALG, self.__selectedComponent.get() + "_sim" ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.WS_ALG, self.__selectedComponent.get() + "_sim" ) ),
               
             ( os.path.join( self.__selectedComponentSandbox.get()   , self.WS_ALG, self.__selectedComponent.get() + "_mo" ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.WS_ALG, self.__selectedComponent.get() + "_mo" ) ),
               
             ( os.path.join( self.__selectedComponentSandbox.get()   , self.WS_ALG, self.__selectedComponent.get() + "_ref" ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.WS_ALG, self.__selectedComponent.get() + "_ref" ) ),
               
             ( os.path.join( self.__dlv_root                                   , self.DLV_ALG_CFG, self.__selectedComponent.get() ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.DLV, self.DLV_ALG_CFG, self.__selectedComponent.get() ) ),
               
             ( os.path.join( self.__dlv_root                         , self.DLV_ALG_CFG, self.__selectedComponent.get() ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.TST_ALG_CFG, self.__selectedComponent.get() ) ),
               
             ( os.path.join( self.__dlv_root                                   , self.DLV_ALG_INC, self.__selectedComponent.get() ),
               os.path.join( self.__selectedSandboxToBeInfected.get(), self.DLV, self.DLV_ALG_INC, self.__selectedComponent.get() ) )
           ]
  
  @staticmethod
  def __selectFolder(folderWidget, stringWidget):
    folder = tkFileDialog.askdirectory()
    folder = folder.replace('/', '\\')
    stringWidget.set(folder)
    InfectProject.__enterDir(folderWidget, folder)
  
  def __selectInfect(self, sbx):
    InfectProject.__enterDir(self.__projectWidget, sbx)
  
  def __selectComponentSbx(self, sbx):
    InfectProject.__enterDir(self.__componentSbxWidget, sbx)
    
    self.__componentOptionMenu['menu'].delete(0, 'end')
    sourceFolder = os.path.join( sbx, self.SRC_ALG )
    for item in os.listdir( sourceFolder ):
      if os.path.isdir( os.path.join(sourceFolder, item) ) and (item != '00_Custom'):
        self.__componentOptionMenu['menu'].add_command(label=item, command=lambda value=item: self.__selectComponent(value))
  
  def __selectComponent(self, cmp):
    self.__selectedComponent.set(cmp)
    InfectProject.__enterDir( self.__componentWidget, cmp )
  
  def __selectComponentCstDevPath(self, devPath):
    self.__selectedCustomDevPath.set(devPath)
    InfectProject.__enterDir( self.__customDevpathWidget, devPath )
  
  @staticmethod
  def __enterDir(folderWidget, folder):
    folderWidget.delete(0, 'end')
    folderWidget.insert(0, folder)
  
  @staticmethod
  def __getMksComponent(cmp):
    cmd = ['si', 'viewproject', '--hostname=ims-adas', '--port=7001', '--fields=name', '--norecurse', '--project=/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/project.pj']
    
    proc = newProcess(cmd)
    ret, err = proc.communicate()
    
    if err != '':
      tkMessageBox.showinfo('MKS Error', err)
    
    mksName = ''
    
    for line in ret.splitlines():
      if line.startswith(cmp.upper() + '_'):
        mksName = os.path.dirname(line)
        break
    
    return mksName
  
  @staticmethod
  def __getSandboxes():
    sandboxes = {}
    sandboxes['normal']  = []
    sandboxes['variant'] = []
    sandboxes['build']   = []
    
    if InfectProject.isIMSRunning():
      cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'sandboxes', '--hostname=ims-adas', '--port=7001']
      proc = newProcess(cmd)
      ret,  err = proc.communicate()
      
      if err != '':
        tkMessageBox.showinfo('MKS Error', err)
      
      root = ET.fromstring( deformat(ret) )
      
      for item in root.findall('./WorkItems[@selectionType="Sandboxes"]/WorkItem[@modelType="si.Sandbox"]'):
        name          = item.find('./Field[@name="sandboxName"]/Value[@dataType="string"]').text
        project       = item.find('./Field[@name="projectName"]/Value[@dataType="string"]').text
        devPath       = item.find('./Field[@name="developmentPath"]/Item[@modelType="si.Devpath"]')
        buildRevision = item.find('./Field[@name="buildRevision"]/Item[@modelType="si.Revision"]')
        
        if devPath is not None:
          assert buildRevision is None
          sandboxes['variant'].append( (name, project, devPath.attrib['id']) )
        elif buildRevision is not None:
          sandboxes['build'].append( (name, project, buildRevision.attrib['id']) )
        else:
          sandboxes['normal'].append( (name, project, '') )
    
    return sandboxes

  @staticmethod
  def isIMSRunning():
    cmd = 'wmic process where name="IntegrityClient.exe" call getowner'
    proc = newProcess(cmd)
    ret, err = proc.communicate()
    
    for line in ret.splitlines():
      if line.strip() == ('User = "' + getpass.getuser() + '";'):
        return True
    
    return False

  def __getSandboxesReadyToBeInfected(self):
    validSandboxes = [item[0] for sublist in self.__sandboxes.values() for item in sublist]
    
    for idx in range(len(validSandboxes)-1, -1, -1):
      sbxRoot = os.path.dirname(validSandboxes[idx])
      if   not os.path.isdir ( os.path.join( sbxRoot, self.SRC_CMN     ) )\
        or not os.path.isfile( os.path.join( sbxRoot, self.TST_MTS    , 'measapp.exe' ) )\
        or not os.path.isdir ( os.path.join( sbxRoot, self.TST_ALG_CFG ) ):
        validSandboxes.pop(idx)
    
    return validSandboxes
  
  def __getValidComponentSandboxes(self):
    validSandboxes = [ item[0] for item in (self.__sandboxes['normal'] + self.__sandboxes['variant']) ]
    
    for idx in range(len(validSandboxes)-1, -1, -1):
      sbxRoot = os.path.dirname(validSandboxes[idx])
      if   not os.path.isdir( os.path.join( sbxRoot          , self.SRC_ALG     ) )\
        or not os.path.isdir( os.path.join( sbxRoot          , self.WS_ALG      ) )\
        or not os.path.isdir( os.path.join( sbxRoot, self.DLV, self.DLV_ALG_CFG ) ):
        validSandboxes.pop(idx)
    
    return validSandboxes
  
  def __getValidCustomDevPaths(self):
    devPaths = []
    
    for sbx in self.__sandboxes['variant']:
      if self.SRC_ALG_CST.replace('\\', '/') in sbx[1]:
        devPaths.append(sbx[2])
    
    return devPaths
  
  @staticmethod
  def __createSandbox(root, project, devpath=''):
    cmd = ['si', 'createsandbox', '--hostname=ims-adas', '--port=7001', '--populate', '--recurse', '-g', '--noopenview', '--project=' + project]
    if devpath != '':
      cmd.append('--devpath=' + devpath)
    cmd.append(root)
    
    proc = newProcess(cmd)
    ret, err = proc.communicate()
  
  @staticmethod
  def __link( src, dst ):
    linkSuccessful = False
    
    if os.path.isdir( src ):
      if InfectProject.__islink(dst):
        os.rmdir( dst )
      elif os.path.isdir( dst ):
        shutil.rmtree( dst, onerror = on_rm_error )
      elif not os.path.isdir( os.path.dirname(dst) ):
        os.makedirs( os.path.dirname(dst) )
      
      proc = newProcess( ['cmd', '/c', 'mklink', '/J', dst, src] )
      ret, err = proc.communicate()
      
      if err != "":
        tkMessageBox.showinfo("Linking Error", dst + '\n' + err)
      else:
        linkSuccessful = True
    
    return linkSuccessful
  
  @staticmethod
  def __islink(path):
    islink = False
    dir, base = os.path.split(path)

    if os.path.isdir( dir ):
      proc = newProcess(['cmd','/c','dir','/al','/b'], dir)
      ret, err = proc.communicate()

      islink = base in ret.splitlines()

    return islink

if __name__ == "__main__":
  infectProject = InfectProject()
  infectProject.run()
