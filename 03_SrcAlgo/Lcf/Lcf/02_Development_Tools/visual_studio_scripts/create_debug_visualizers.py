import os
import sys
import shutil
import platform
import _winreg


def getVSInstallDirs():
  reg = _winreg.ConnectRegistry( None, _winreg.HKEY_LOCAL_MACHINE )
  
  dirs = []
  
  for i in range(8, 11): # VisualStudio 8.0 to 10.0
    if platform.machine().endswith('64'):
      key = _winreg.OpenKey( reg, os.path.join(r"SOFTWARE\Wow6432Node\Microsoft\VisualStudio", str(i) + ".0") )
    else:
      key = _winreg.OpenKey( reg, os.path.join(r"SOFTWARE\Microsoft\VisualStudio", str(i) + ".0") )
    
    try:
      dirs.append( _winreg.QueryValueEx( key, "InstallDir" )[0] )
    except WindowsError:
      pass
  
  return dirs
  

def insertToAutoexpDat( file, lst ):
  content = open(file, 'r').readlines()
  
  idx = -1
  
  # Append to the end of visualizers, i.e. before PROPVARIANT begins 
  idx = [i for i, s in enumerate(content) if "PROPVARIANT" in s]
  
  # If PROPVARIANT wasn't found, insert at the begin of the visualizers
  if (len(idx) == 0) or (idx[0] < 3):
    idx = [i for i, s in enumerate(content) if "[Visualizer]" in s]
    if len(idx) == 0:
      print "Error: File cannot be parsed"
      sys.exit(2)
    else:
      idx = idx[0] + 1
  else:
    idx = idx[0] - 2
  
  result = content[:idx] + lst + content[idx:]
  
  with open( file, 'w' ) as f:
    print "Writing stuff at line: ", idx
    f.writelines(result)
  
  pass


def addCmlVisualizers( file ):
  cmlStuff = []
  
  if not "cml::CArray" in open(file).read():
    cmlStuff.append( "\n" )
    cmlStuff.append( ";------------------------------------------------------------------------------\n" )
    cmlStuff.append( ";  cml::CArray\n" )
    cmlStuff.append( ";------------------------------------------------------------------------------\n" )
    cmlStuff.append( "cml::CArray<*,*,*>{\n" )
    cmlStuff.append( "  children\n" )
    cmlStuff.append( "  (\n" )
    cmlStuff.append( "    #array\n" )
    cmlStuff.append( "    (\n" )
    cmlStuff.append( "      expr :  ($c.m_data)[$i], \n" )
    cmlStuff.append( "      size :  $T2\n" )
    cmlStuff.append( "    )\n" )
    cmlStuff.append( "  )\n" )
    cmlStuff.append( "}\n" )
  else:
    print "cml::CArray already defined"
  
  if not "cml::CArray2D" in open(file).read():
    cmlStuff.append( "\n" )
    cmlStuff.append( ";------------------------------------------------------------------------------\n" )
    cmlStuff.append( ";  cml::CArray2D\n" )
    cmlStuff.append( ";------------------------------------------------------------------------------\n" )
    cmlStuff.append( "cml::CArray2D<*,*,*,*>{\n" )
    cmlStuff.append( "  children\n" )
    cmlStuff.append( "  (\n" )
    cmlStuff.append( "    #array\n" )
    cmlStuff.append( "    (\n" )
    cmlStuff.append( "      expr: $c.m_data[$i/$T2 + ($i % $T2) * $T3],\n" )
    cmlStuff.append( "      rank: 2,\n" )
    cmlStuff.append( "      size: ($r==1)*$T2+($r==0)*$T3,\n" )
    cmlStuff.append( "      base: 0\n" )
    cmlStuff.append( "    )\n" )
    cmlStuff.append( "  )\n" )
    cmlStuff.append( "}\n" )
  else:
    print "cml::CArray2D already defined"
  
  if len(cmlStuff) > 0:
    insertToAutoexpDat(file, cmlStuff)
  else:
    print "File not changed"


def main():
  installPaths =  getVSInstallDirs()
  
  for installPath in installPaths:
    autoexpPath = os.path.normpath( os.path.join( installPath, r"..\Packages\Debugger\autoexp.dat" ) )
    
    if not os.path.isfile( autoexpPath ):
      print "Error: autoexp.dat not existing at ", os.path.dirname(autoexpPath)
      sys.exit(2)
    
    print autoexpPath
    
    autoexpPathBak = autoexpPath + ".bak"
    print "Making backup to ", autoexpPathBak
    shutil.copy( autoexpPath, autoexpPath + ".bak" )
    
    addCmlVisualizers(autoexpPath)


if __name__ == "__main__":
  main()
