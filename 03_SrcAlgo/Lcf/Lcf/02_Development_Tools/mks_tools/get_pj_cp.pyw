import os
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

class GetPjCP():
  class ProjectAttribs():
    def __init__(self, variants, mksPath, ecuVisCfg):
      self.variants  = variants
      self.mksPath   = mksPath
      self.ecuVisCfg = ecuVisCfg
  
  def __init__(self):
    self.PROJECTS =\
      { 'MFS430BW15': self.ProjectAttribs(['MFS430BW15', 'SMFC4B0'], '/nfs/projekte1/PROJECTS/MFC400/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFS430BW16': self.ProjectAttribs(['MFS430BW16']           , '/nfs/projekte1/PROJECTS/MFC400/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFC430TA16': self.ProjectAttribs(['MFC430TA16', 'MFC4T0'] , '/nfs/projekte1/PROJECTS/MFC400/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFC440GY18': self.ProjectAttribs(['MFC440GY18']           , '/nfs/projekte1/PROJECTS/MFC400/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFL420'    : self.ProjectAttribs(['MFL420', 'SRLCam']     , '/nfs/projekte1/PROJECTS/SRLCam/06_Algorithm/project.pj'                      , 'sim_srlcam400_vis_offline.cfg'),
        'MFC431'    : self.ProjectAttribs(['MFC431_']              , '/nfs/projekte1/PROJECTS/MFC431/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFC431HI28': self.ProjectAttribs(['MFC431HI28']           , '/nfs/projekte1/PROJECTS/MFC431/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFC431TA19': self.ProjectAttribs(['MFC431TA19']           , '/nfs/projekte1/PROJECTS/MFC431/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'MFC430HI17': self.ProjectAttribs(['MFC430HI17']           , '/nfs/projekte1/PROJECTS/MFC431/06_Algorithm/project.pj'                      , 'sim_mfc400_vis_offline.cfg'   ),
        'NCAP18'    : self.ProjectAttribs(['MFC431', 'NCAP18']     , '/nfs/projekte1/REPOSITORY/Function_Projects/EUNCAP18/06_Algorithm/project.pj', 'sim_mfc400_vis_offline.cfg'   ) }
    
    self.__checkpoints = {}
    
    self.DEFAULT_FONT = 'SegoeUI 10'
    
    self.__root  = Tkinter.Tk()
    
    self.__destinationDir = ''
    self.__selectedProject    = Tkinter.StringVar(self.__root)
    self.__selectedCheckpoint = Tkinter.StringVar(self.__root)
    
    self.__sandboxDir = ''
    
    self.__setupFrame()
    
  def run(self):
    self.__root.mainloop()
  
  def __setupFrame(self):
    self.__frame  = Tkinter.Frame(self.__root, borderwidth=6)
    self.__frame2 = Tkinter.Frame(self.__root, borderwidth=6)
    self.__frame3 = Tkinter.Frame(self.__root, borderwidth=6)
    
    self.__root.resizable(width=Tkinter.NO, height=Tkinter.NO)
    self.__root.title('Download Project checkpoint')
    
    row = 0
    columns = 2
    
    Tkinter.Label( self.__frame, text='1. Select project you want to check out', font=self.DEFAULT_FONT + ' bold' ).grid(row=row, columnspan=columns)
    row += 1
    
    self.__projectOptionMenu = Tkinter.OptionMenu( self.__frame, self.__selectedProject, *sorted(self.PROJECTS.keys()), command=self.__processSelectedProject )
    self.__projectOptionMenu.grid(row=row, columnspan=columns)
    row += 1
    
    Tkinter.Label( self.__frame, text='2. Specifiy or select checkpoint you want to have', font=self.DEFAULT_FONT + ' bold' ).grid(row=row, columnspan=columns)
    row += 1
    
    self.__checkpointWidget = Tkinter.Entry(self.__frame, width=50)
    self.__checkpointWidget.grid(row=row, column=0)
    
    self.__checkpointOptionMenu = Tkinter.OptionMenu( self.__frame, self.__selectedCheckpoint, '', command=self.__processSelectedCheckpoint )
    self.__checkpointOptionMenu.grid(row=row, column=1)
    row +=1
    
    Tkinter.Label( self.__frame, text='3. Select the folder you want to download in', font=self.DEFAULT_FONT + ' bold' ).grid(row=row, columnspan=columns)
    row += 1
    
    padding = 2
    
    self.__folderWidget = Tkinter.Entry( self.__frame, width=50 )
    self.__folderWidget.grid( row=row,  column=0, sticky=Tkinter.E, padx=padding, pady=padding )
    
    self.__destinationDirButton = Tkinter.Button( self.__frame, text='Destination directory', command=self.__selectFolder )
    self.__destinationDirButton.grid( row=row, column=1, sticky=Tkinter.W, padx=padding, pady=padding )
    
    row = 0
    
    width=17
    
    self.__createSandboxButton = Tkinter.Button( self.__frame2, text='Create Sandbox', command=self.__createSandbox, width=width )
    self.__createSandboxButton.grid( row=row, column=0, sticky=Tkinter.E, padx=padding, pady=padding )
    
    self.__dropSandboxButton = Tkinter.Button( self.__frame2, text='Drop Sandbox', command=self.__dropSandbox, width=width )
    self.__dropSandboxButton.grid( row=row, column=1, sticky=Tkinter.W, padx=padding, pady=padding )
    row += 1
    
    self.__resyncSourceCodeButton = Tkinter.Button( self.__frame2, text='Resync Source Code', command=self.__resyncSourceCode, width=width )
    self.__resyncSourceCodeButton.grid( row=row, column=0, sticky=Tkinter.E, padx=padding, pady=padding )
    
    self.__resyncMtsButton = Tkinter.Button( self.__frame2, text='Resync MTS', command=self.__resyncMts, width=width )
    self.__resyncMtsButton.grid( row=row, column=1, sticky=Tkinter.W, padx=padding, pady=padding )
    row += 1
    
    self.__runJointSimButton = Tkinter.Button( self.__frame2, text='Joint SIM', command=self.__runJointSim, width=width )
    self.__runJointSimButton.grid( row=row, column=0, sticky=Tkinter.E, padx=padding, pady=padding )
    
    self.__runJointVisButton = Tkinter.Button( self.__frame2, text='Joint Vis', command=self.__runJointVis, width=width )
    self.__runJointVisButton.grid( row=row, column=1, sticky=Tkinter.W, padx=padding, pady=padding )
    
    row = 0
    
    if os.path.isfile('infect_project.pyw'):
      self.__infectProjectButton = Tkinter.Button( self.__frame3, text='Infect Project', command=self.__runInfectProject, width=width )
      self.__infectProjectButton.grid( row=row, column=1, sticky=Tkinter.W, padx=padding, pady=padding )
    
    self.__frame.pack()
    self.__frame2.pack()
    self.__frame3.pack()
  
  def __processSelectedProject(self, selectedPj):
    self.__selectedProject.set(selectedPj)

    self.__checkpoints.clear()
    
    si_cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'projectinfo', '--hostname=ims-adas', '--port=7001', '--status=gui', '--project=' + self.PROJECTS[selectedPj].mksPath]
    
    proc = newProcess(si_cmd)
    
    ret, err = proc.communicate()
    
    if err != '':
      tkMessageBox.showinfo('MKS Error', err)
    
    root  = ET.fromstring( deformat(ret) )
    lines = [ item.attrib['id'] for item in root.findall('./WorkItems/WorkItem[@displayId="' + self.PROJECTS[selectedPj].mksPath + '"]/Field[@name="developmentPaths"]/List[@elementType="item"]/Item[@modelType="si.Devpath"]') ]
    
    si_cmd[4] = 'viewprojecthistory'
    si_cmd.append('--fields=revision,labels')
    for line in lines:
      devpath = line.split()[0]
      
      validDevPath = False
      for name in self.PROJECTS[selectedPj].variants:
        if name.lower() in devpath.lower():
          validDevPath = True
          break
      
      if validDevPath:
        proc = newProcess( si_cmd + ['--rfilter=devpath:' + devpath] )
        
        ret, err = proc.communicate()
        
        if err != '':
          tkMessageBox.showinfo('MKS Error', err)
        
        root = ET.fromstring( deformat(ret) )
        
        for item in root.findall('./WorkItems/WorkItem[@displayId="' + self.PROJECTS[selectedPj].mksPath + '"]/Field[@name="revisions"]/List[@elementType="item"]/Item[@modelType="si.Revision"]'):
          revision = item.attrib['id']
          labels = item.findall('./Field[@name="labels"]/List/Value[@dataType="string"]')
          for label in labels:
            self.__checkpoints[label.text] = revision
    
    self.__checkpointOptionMenu['menu'].delete(0, 'end')
    for cp in sorted(self.__checkpoints):
      self.__checkpointOptionMenu['menu'].add_command(label=cp, command=lambda value=cp: self.__processSelectedCheckpoint(value))
  
  def __processSelectedCheckpoint(self, selectedCp):
    self.__selectedCheckpoint.set(selectedCp)
    
    self.__checkpointWidget.delete(0, 'end')
    self.__checkpointWidget.insert(0, selectedCp)
    
    self.__sandboxDir = os.path.join( self.__folderWidget.get(), self.__selectedProject.get().upper() + '_' + selectedCp.upper() )
  
  def __selectFolder(self):
    self.__folderWidget.delete(0, 'end')
    self.__folderWidget.insert(0, tkFileDialog.askdirectory())
    
    self.__sandboxDir = os.path.join( self.__folderWidget.get(), self.__selectedProject.get().upper() + '_' + self.__selectedCheckpoint.get().upper() )
  
  def __createSandbox(self):
    self.__processSelectedCheckpoint( self.__checkpointWidget.get().strip() )
    selectedCp = self.__selectedCheckpoint.get()
    selectedDir = self.__folderWidget.get()
    
    if not os.path.isdir(selectedDir):
      tkMessageBox.showinfo('Error', 'Given path does not exist:\n' + selectedDir)
      return
    
    if self.__checkpoints.has_key(selectedCp):
      pjRevision = self.__checkpoints[selectedCp]
    else:
      tkMessageBox.showinfo('Error', 'Given checkpoint does not exist:\n' + selectedCp)
      return
    
    if os.path.exists(self.__sandboxDir):
      tkMessageBox.showinfo('Error', 'Sandbox already exists:\n' + self.__sandboxDir)
      return
    
    si_cmd = ['si', 'createsandbox', '--hostname=ims-adas', '--port=7001', '--nopopulate', '--norecurse',\
      '--noopenview', '--status=gui', '--project=' + self.PROJECTS[self.__selectedProject.get()].mksPath, '--projectRevision=' + pjRevision, self.__sandboxDir]
    
    proc = newProcess(si_cmd)
    ret, err = proc.communicate()
    
    if err != '':
      tkMessageBox.showinfo('MKS Error', err)
  
  def __dropSandbox(self):
    self.__processSelectedCheckpoint( self.__checkpointWidget.get().strip() )
    if not os.path.isdir(self.__sandboxDir):
      tkMessageBox.showinfo('Error', 'Sandbox does not exist\n' + self.__sandboxDir)
      return
    
    for link in self.getAllLinks( self.__sandboxDir ):
      os.rmdir( link )
    
    si_cmd = ['si', 'dropsandbox', '--hostname=ims-adas', '--port=7001', '-Y', '--status=gui', '--delete=all', os.path.join(self.__sandboxDir, 'project.pj') ]
    
    proc = newProcess(si_cmd)
    ret, err = proc.communicate()
    
    if err != '':
      tkMessageBox.showinfo('MKS Error', err)
  
  def __resyncSourceCode(self):
    self.__resync( os.path.join(self.__sandboxDir, '04_Engineering') )
  
  def __resyncMts(self):
    self.__resync( os.path.join(self.__sandboxDir, r'05_Testing\06_Test_Tools') )
  
  @staticmethod
  def __resync(sandbox):
    si_cmd = ['si', 'resync', '--hostname=ims-adas', '--port=7001', '-g', '--recurse', '--nooverwriteChanged', os.path.join(sandbox, 'project.pj')]
    
    proc = newProcess(si_cmd)
    ret, err = proc.communicate()
    
    if err != '':
      tkMessageBox.showinfo('MKS Error', err)
  
  def __runJointSim(self):
    cwd = os.getcwd()
    jointCfgDir    = os.path.join( self.__sandboxDir, r'05_Testing\06_Test_Tools\mts_measurement\cfg\algo\joint' )
    jointCfgScript = 'create_custom_config.pyw'
    if os.path.isfile( os.path.join( jointCfgDir, jointCfgScript ) ):
      os.chdir( jointCfgDir )
      subprocess.Popen( ['pythonw',jointCfgScript] )
      os.chdir(cwd)
    else:
      tkMessageBox.showinfo('Error', 'Joint SIM script is not existing in\n' + jointCfgDir)
  
  def __runJointVis(self):
    cwd = os.getcwd()
    mtsDir = os.path.join( self.__sandboxDir, r'05_Testing\06_Test_Tools\mts' )
    if os.path.isdir(mtsDir):
      os.chdir( mtsDir )
    else:
      tkMessageBox.showinfo('Error', 'MTS directory is not existing\n' + mtsDir)
    
    cfg = os.path.join( r'algo\joint', self.PROJECTS[self.__selectedProject.get()].ecuVisCfg )
    
    if os.path.isfile('measapp.exe') and os.path.isfile( os.path.join( r'..\mts_measurement\cfg', cfg ) ):
      subprocess.Popen( [r'measapp.exe', '-showmaximized', '-lc' + cfg] )
    else:
      tkMessageBox.showinfo('Error', 'CFG file\n' + cfg + '\nor measapp.exe is not existing')
    
    os.chdir(cwd)
  
  @staticmethod
  def __runInfectProject():
    if os.path.isfile('infect_project.pyw'):
      subprocess.Popen(['pythonw', 'infect_project.pyw'])

  @staticmethod
  def getAllLinks(path):
    links = []
    if os.path.isdir( path ):
      proc = newProcess(['cmd','/c','dir','/al','/s','/b'], path)
      ret, err = proc.communicate()

      links = ret.splitlines()

    return links

if __name__ == "__main__":
  getPjCP = GetPjCP()
  getPjCP.run()
