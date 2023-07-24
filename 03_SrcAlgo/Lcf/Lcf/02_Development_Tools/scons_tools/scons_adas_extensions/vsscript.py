"""
Filename                  :  scons_adas_extensions\vsscript.py
Description               :  Script that contains Additional builder to patch Visual Studio Resource (.rc) file.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: vsscript.py
#
# DESCRIPTION: Script that contains Additional builder to patch Visual Studio Resource (.rc) file.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/05/14
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:02CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: vsscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:02CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.3 2016/05/27 14:36:47CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.2 2015/06/26 05:17:36CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:37 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import SCons.Tool.msvc
import os.path
from SCons.Script import *

def generate(env):   
    """
    Function        :  generate
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    env["_VS_SCRIPT_DIR"] = Dir(env.subst('$VS_SCRIPT_DIR')).abspath
    env.SetDefault(
        RESPATCHCOM         = 'cscript $_VS_SCRIPT_DIR/res_patch.vbs /D:$variant /R:${TARGET} /V:${SOURCE} //NoLogo',
        RESPATCHCOMSTR      = ''
        )
                                        
    env['BUILDERS']['ResPatch'] = Builder(action = Action('$RESPATCHCOM', '$RESPATCHCOMSTR'))

def exists(env):
    """
    Function        :  exists
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    return 1
