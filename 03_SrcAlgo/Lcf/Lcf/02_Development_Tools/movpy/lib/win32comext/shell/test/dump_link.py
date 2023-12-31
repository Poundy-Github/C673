# testShell.py
#
import sys, os
from win32com.shell import shell, shellcon
import pythoncom
import glob
from win32com.storagecon import *

def DumpLink(fname):
	shellLink = pythoncom.CoCreateInstance(shell.CLSID_ShellLink, None, pythoncom.CLSCTX_INPROC_SERVER, shell.IID_IShellLink)
	persistFile = shellLink.QueryInterface(pythoncom.IID_IPersistFile)
	persistFile.Load(fname,STGM_READ)
	shellLink.Resolve(0, shell.SLR_ANY_MATCH | shell.SLR_NO_UI)
	fname, findData = shellLink.GetPath(0)
	print "Filename", fname, ", UNC=", shellLink.GetPath(shell.SLGP_UNCPRIORITY)[0]

def FavDumper(nothing, path, names):
	# called by os.path.walk
	for name in names:
		print name, 
		try:
			DumpLink(name)
		except pythoncom.com_error:
			print " - not a link"

def DumpFavorites():
	favfold = str(shell.SHGetSpecialFolderPath(0, shellcon.CSIDL_FAVORITES))
	print "Your favourites are at", favfold
	os.path.walk(favfold, FavDumper, None)
	
if __name__=='__main__':
	if len(sys.argv)>1:
		for fspec in sys.argv[1:]:
			files = glob.glob(fspec)
			if files:
				for file in files:
					print file
					DumpLink(file)
					print
			else:
				print "Can not find", fspec
	else:
		print "Dumping your favorites folder!"
		DumpFavorites()
