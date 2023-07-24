"""
Filename                  : scons_adas_extensions\gscons_exception_handler.py
Description               : Script to handle the exceptions.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: gscons_exception_handler.py
#
# DESCRIPTION: Script to handle the exceptions.
#
# INITIAL AUTHOR: Shwetha.Annashamachar (uidj8746)
#
# CREATION DATE: - 2016/06/28
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:54CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: gscons_exception_handler.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:54CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.2 2016/07/12 13:00:26CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and exception handled in GSCons.
# CHANGES:                   Revision 1.1 2016/07/12 07:43:33CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/SCT_Sconstools/scons_adas_extensions/project.pj
#***************************************************************************************************

import inspect
import sys

path=inspect.currentframe().f_back.f_code.co_filename

def exception_error(e,msg=""):
	"""
	Function            :  exception_error
	Description         :  Handling exceptions for errors
	e             		:  Type of error
	msg                 :  Message to display
	Returns             :  
	"""
	print "::GenericSCons::Error::%s %s" %(e,msg)
	print "\nBuild Failed!!!!!!!!"
	sys.exit(0)

if path not in exception_handler_file_list:
    def exception_warning(e,exception_handler,msg=""):
		"""
		Function            :  exception_warning
		Description         :  Handling exceptions for warnings
		e             		:  Type of error
		exception_handler	:  Flag for exception handling
		msg                 :  Message to display
		Returns             :  
		"""
		if exception_handler:
			print "::GenericScons::Warning::%s %s" %(e,msg)
		exception_handler_file_list.append(path)
else:
    def exception_warning(e,exception_handler,msg=""):
        pass



                
    


