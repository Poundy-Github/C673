/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysischain_utils.h

  DESCRIPTION:            Definition file for chain of light utility functions

  AUTHOR:                 Roman Glebov

  CREATION DATE:          2014-01-24

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGE:                 $Log: hla_analysischain_utils.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:41CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:52CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:13CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.4 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysischain_utils.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysischain_utils.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.3 2014/03/05 11:05:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:21 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.2 2014/03/04 15:52:26CET Glebov, Roman (uidg4759) 
  CHANGE:                 using now sint32 in place of float32 for angle.
  CHANGE:                 
  CHANGE:                 changed directAngleFunction input arguments from float32 to sint16
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 4, 2014 3:52:26 PM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.1 2014/01/28 16:17:05CET Glebov, Roman (uidg4759) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj

*/

#ifndef HLA_ANALYSIS_CHAIN_UTILS
#define HLA_ANALYSIS_CHAIN_UTILS

#include "hla_base.h"

/* for a segment consisting of the points A B and C computes the angle between the 
vector in the direction BA-> and the vector in the direction BC->.
If needed the points A and C are swapped and sorted counter clock wise first based on the angle to the X-Axis and 
distance to the origin.
the angle is returned in Grad and is in the range [-180;180]
*/
sint32 HLAAnalysisChainSegmentDirectedAngle(sint16 xa, sint16 ya, sint16 xb, sint16 yb, sint16 xc, sint16 yc);

#endif /* (HLA_ANALYSIS_CHAIN_UTILS) */