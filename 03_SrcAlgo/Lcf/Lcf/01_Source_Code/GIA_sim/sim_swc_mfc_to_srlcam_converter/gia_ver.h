/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 GIA

  MODULNAME:                 gia_ver.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: gia_ver.h  $  
  CHANGES:                   Revision 1.1 2021/12/13 17:22:01CET Wang, David (Wangd3)   
  CHANGES:                   Initial revision  
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_mfc_to_srlcam_converter/project.pj  
  CHANGES:                   Revision 1.0 2017/03/03 10:33:46CET Sorge, Sven (uidg3181)   
  CHANGES:                   Initial revision  
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_mfc_to_srlcam_converter/project.pj  
  CHANGES:                   Revision 1.1 2014/03/27 15:42:42CET Sorge, Sven (uidg3181)   
  CHANGES:                   Initial revision  
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/sim_swc_mfc_to_srlcam_converter/project.pj  
  CHANGES:                   Revision 1.1 2014/03/13 15:10:31CET Sorge-EXT, Sven (uidg3181)   
  CHANGES:                   Initial revision  
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/project.pj  
  CHANGES:                   Revision 1.3 2013/11/18 18:48:01CET Bajard, Laure (uidt3229)   
  CHANGES:                   move BusDebugData version  
  CHANGES:                   --- Added comments ---  uidt3229 [Nov 18, 2013 6:48:01 PM CET]  
  CHANGES:                   Change Package : 206974:1 http://mks-psad:7002/im/viewissue?selection=206974  
  CHANGES:                   Revision 1.2 2013/05/30 10:20:58CEST Rony, Sophie (uidt9854)   
  CHANGES:                   Take external version from internal version  
  CHANGES:                   --- Added comments ---  uidt9854 [May 30, 2013 10:20:58 AM CEST]  
  CHANGES:                   Change Package : 181204:3 http://mks-psad:7002/im/viewissue?selection=181204  
  CHANGES:                   Revision 1.1 2012/12/07 15:28:34CET Bajard, Laure (uidt3229)   
  CHANGES:                   Initial revision  
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CB_CameraBlockage/04_Engineering/01_Source_Code/algo/00_Custom/cb_wrp/project.pj  

**************************************************************************** */
#ifndef gia_ver_h__
#define gia_ver_h__


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/* Component version number as 4 byte BCD MM.SS.F1.F2
  MM: Main version number. This number is dependent on the external component 
      interface i.e. interface change enforces an increase. The number 
      starts with "01".
  SS: Sub version number. This number reflects functional changes within the main
      version of the component. The number starts with "00" at every new main 
      version number step. 
  F1: Bug fix level number. This number indicates exclusively error-correcting changes.
      If the sub version number in incremented the bug fix level restarts with "00".
  F2: Bug fix sub-level number.
*/
#define GIA_ALL_SW_MAIN_VER_NO             0x01U
#define GIA_ALL_SW_SUB_VER_NO              0x00U
#define GIA_ALL_SW_BUG_FIX_LEV             0x00U
#define GIA_ALL_SW_BUG_FIX_LEV2            0x00U


#endif // gia_ver_h__
