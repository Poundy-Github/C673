"""
Filename                  :  scons_adas_extensions\sconscript_setup.py
Description               :  Script that setup shared scons scripts to a project and copy them into folder structure.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: sconscript_setup.py
#
# DESCRIPTION: Script that setup shared scons scripts to a project and copy them into folder structure.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/09/26
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:59CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: sconscript_setup.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:59CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.8 2016/05/27 12:45:21CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.7 2015/06/26 05:17:32CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:32 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# setup shared scons scripts to project

import os, stat
import shutil

def setup_scripts(features):
    """
    Function             :  setup_scripts
    Description          :  Function to copy files from source to destination as defined in sconscript_setup_config.py.
    features             :  Features defined in sconscript_setup_config.py.
    Returns              :  
    """
    # get working directory
    working_dir = os.getcwd()
    # store root directory
    root_dir = os.path.abspath(os.path.join(working_dir, "../../../.."))
    # store directory containing shared scons scripts
    script_dir = os.path.abspath(os.path.join(working_dir, "../../../02_Development_Tools/scons_tools/scons_common_scripts"))
    
    for item in features:
        if item["copy"] == True:
            for src_file in item["source"]:
                # get file name of shared scripts
                file_name = src_file.rsplit('/')[-1]
                source_file = os.path.abspath(os.path.join(script_dir, src_file))
                dest_dir = os.path.abspath(os.path.join(root_dir, item["dest_folder"]))
                dest_file = os.path.abspath(os.path.join(root_dir, item["dest_folder"], file_name))
                # check destination folder
                if os.path.isdir(dest_dir):
                    if os.path.isfile(dest_file):
                        # change permission to allow overwrite
                        os.chmod(dest_file, 0666)
                    # copy shared scripts
                    try:
                        shutil.copy(source_file, dest_dir)
                    except IOError, e:
                        print "Unable to copy file. %s" % e
                else:
                    print "\nWARNING: Path %s is not found." % dest_dir
                    print "         No SConscript will be copied there."
                    print "         Related targets won't build!!!\n"
    
def main():
    """
    Function        :  main
    Description     :  Standard main function.
    Returns         :  
    """
    # import python file containing setup configuration
    # print "setup script"
    setup_dict = dict()
    if os.path.isfile(os.path.join(os.getcwd(), "sconscript_setup_config.scfg")):
        execfile("sconscript_setup_config.scfg", setup_dict)
        setup_scripts(setup_dict["features"])
    else:
        print "Error: sconscript_setup_config.scfg is not found."
    # print "end of setup script"

main()