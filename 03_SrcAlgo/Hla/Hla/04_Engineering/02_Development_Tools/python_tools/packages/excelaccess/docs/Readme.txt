Recreation: 
-> change conf.py to add path to modules/project root:
	
	import os
	import sys
	sys.path.append( os.path.join(os.path.dirname(__name__), "..\..\.."))

-> adapt index.rst if changed (e.g. add manually creatd files)