/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysischain_utils.c

  DESCRIPTION:            Implementation file for chain of light utility functions

  AUTHOR:                 Roman Glebov

  CREATION DATE:          2014-01-24

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGE:                 $Log: hla_analysischain_utils.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:40CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:51CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:13CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.4 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysischain_utils.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysischain_utils.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.3 2014/03/04 15:52:27CET Glebov, Roman (uidg4759) 
  CHANGE:                 using now sint32 in place of float32 for angle.
  CHANGE:                 
  CHANGE:                 changed directAngleFunction input arguments from float32 to sint16
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 4, 2014 3:52:28 PM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.2 2014/03/04 10:06:08CET Glebov, Roman (uidg4759) 
  CHANGE:                 refactoring and speed up of chain of light
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 4, 2014 10:06:08 AM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.1 2014/01/28 16:17:00CET Glebov, Roman (uidg4759) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj

*/

#include "hla_analysischain_utils.h"
#include "hla_atan2.h"

sint32 HLAAnalysisChainSegmentDirectedAngle( sint16 xa, sint16 ya, sint16 xb, sint16 yb, sint16 xc, sint16 yc )
{
    sint16 vectorBAx, vectorBAy;
    sint16 vectorBCx, vectorBCy;

    sint32 dotProduct, pseudoCrossProduct;

    vectorBAx = xa - xb;
    vectorBAy = ya - yb;

    vectorBCx = xc - xb;
    vectorBCy = yc - yb;

    /* stable angle computation */
    
    dotProduct = (vectorBAx * vectorBCx) + (vectorBAy * vectorBCy);

    pseudoCrossProduct = (vectorBAx * vectorBCy) - (vectorBAy * vectorBCx);


    /* computing angle and converting it from rad to grad */
    return hla_atan2( pseudoCrossProduct, dotProduct );
}