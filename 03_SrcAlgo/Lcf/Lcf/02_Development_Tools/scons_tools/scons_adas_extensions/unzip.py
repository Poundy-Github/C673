"""
Filename                  :  scons_adas_extensions\unzip.py
Description               :  Scons Builder for extracting archives
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: unzip.py
#
# DESCRIPTION: Scons Builder for extracting archives
#
# INITIAL AUTHOR: Andre.Fischer-EXT (uidg5297)
#
# CREATION DATE: 2015/09/24
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:01CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: unzip.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:01CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.3 2016/05/27 14:35:13CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.2 2015/09/24 14:46:15CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add junction-flag for auto-accept licence
# CHANGES:                   - Added comments -  uidg5297 [Sep 24, 2015 2:46:16 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.1 2015/09/24 08:32:01CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/SCT_Sconstools/scons_adas_extensions/project.pj

#***************************************************************************************************

from SCons.Script import *

def generate(env):  
    
    """
    Function        :  generate
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    env['XZIP']     = 'unzip.exe'
    env['XZIP_EXT'] = '.zip'
    env['XZ']       = '7za.exe'
    env['XZ_EXT']   = '.7z'
    env['JUNCTION'] = 'junction.exe'
    
    env['GEN_REPORT_FILE'] = 'echo Successfully unzipped at %date% @%time% > ${SOURCE.dir}/unzip_report.txt'
    
    env.PrependENVPath('PATH', Dir(env.subst('$UNZIP_DIR')).abspath)
    env.PrependENVPath('PATH', Dir(env.subst('$JUNCTION_DIR')).abspath)
    
    env['JUNC_CREATE_LINK']     = 'IF EXIST ${TARGET.dir} rmdir /S /Q ${TARGET.dir} && $JUNCTION /accepteula ${TARGET.dir} $SOURCE.dir >nul'
    env['JUNC_CREATE_LINK_STR'] = 'Prepare extracting $SOURCE'
    env['JUNC_REM_LINK']        = '$JUNCTION -d ${TARGET.dir} >nul'
    # Extract commands do the following:
    #   1) Extract archive
    #   2) If successful, create a report file with timestamp
    #   3) If successful, remove symbolic link associated with that very archive.
    env['XZIPCOM']              = '$XZIP -o $SOURCE -d ${TARGET.dir}\\..\\ 1>nul && $GEN_REPORT_FILE && $JUNC_REM_LINK'
    env['XZIPCOMSTR']           = 'Extracting $SOURCE ...'
    env['XZCOM']                = '$XZ x $SOURCE -o${TARGET.dir}\\..\\ -y 1>nul  && $GEN_REPORT_FILE && $JUNC_REM_LINK'
    env['XZCOMSTR']             = '$XZIPCOMSTR'

    
    action_list_zip = SCons.Action.Action('$XZIPCOM', '$XZIPCOMSTR')
    action_list_z   = SCons.Action.Action('$XZCOM', '$XZCOMSTR')
    action_list_j  = SCons.Action.Action('$JUNC_CREATE_LINK', '$JUNC_CREATE_LINK_STR')
    extractZipBld   = Builder(action     = action_list_zip,
                              src_suffix = '$XZIP_EXT')
    extractZBld     = Builder(action = action_list_z,
                              src_suffix = '$XZ_EXT')
    createLink      = Builder(action = action_list_j)

    env['BUILDERS']['XZIP']  = extractZipBld
    env['BUILDERS']['XZ']    = extractZBld
    env['BUILDERS']['CLINK'] = createLink
    
def exists(env):
    """
    Function        :  exists
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    return 1