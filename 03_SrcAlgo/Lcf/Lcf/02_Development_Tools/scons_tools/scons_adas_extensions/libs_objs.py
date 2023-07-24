#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: libs_objs.py
#
# DESCRIPTION: Script that contains the list of libraries and objects used for Ram/Rom allocation of Libraries.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/11/04
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:55CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: libs_objs.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:55CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.2 2015/06/26 05:17:42CEST uidr0826 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:42 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

libsAndObjs=[
"sr.lib",
"tsa.lib",
"vcl_haar.lib",
"fct.lib",
"cb.lib",
"cipp_c674x_release.lib",
"ecm.lib",
"em_c674x_release.lib",
"hla_c674x_release.lib",
"lanedetection.lib",
"memo_c674x_release.lib",
"vcl_c674x_release.lib",
"gb_haar.lib",
"CIPP_DeBayer_release.lib",
"hla_arp32_release.lib",
"LD_eve.lib",
"vcl_haar.lib",

"vcl_tracking.obj",
"sr_wrp_main.obj",
]