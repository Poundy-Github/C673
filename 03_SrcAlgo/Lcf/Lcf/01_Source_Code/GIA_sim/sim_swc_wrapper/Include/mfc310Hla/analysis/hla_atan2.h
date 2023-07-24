/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_atan2.h

  DESCRIPTION:            Own implementation of approximated atan2 function

  AUTHOR:                 Roman Glebov

  CREATION DATE:          2014-02-19

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGE:                 $Log: hla_atan2.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:45CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:02CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:18CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.4 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_atan2.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_atan2.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.3 2014/03/11 15:43:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took cfg_project.h into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:40 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.2 2014/03/04 15:52:27CET Glebov, Roman (uidg4759) 
  CHANGE:                 using now sint32 in place of float32 for angle.
  CHANGE:                 
  CHANGE:                 changed directAngleFunction input arguments from float32 to sint16
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 4, 2014 3:52:27 PM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.1 2014/03/04 10:04:21CET Glebov, Roman (uidg4759) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
*/


#ifndef hla_atan2_h__
#define hla_atan2_h__


#include "hla_base.h"

sint32 hla_atan2 (sint32 y, sint32 x);

#endif // hla_atan2_h__
