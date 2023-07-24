/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_lightdist.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_lightdist.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:08CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:48CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:08CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.5 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_lightdist.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_lightdist.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.4 2013/08/02 15:25:52CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:53 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.3 2013/04/12 12:45:13CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:14 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.2 2012/02/20 15:07:41CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Finish restucturing of tracking algo
  CHANGE:                 --- Added comments ---  uid28828 [Feb 20, 2012 3:07:42 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.1 2012/01/25 17:34:25CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_LIGHTDIST_INCLUDED
#define HLA_LIGHTDIST_INCLUDED


#include "hla_trackutils.h"



/* update lighting distance */
void HLALightDistUpdate(
                         HLATrack_t                                    *pTLB_Start,
                         HLAPair_t                            *pPairStart,
                         const HLATracking3DDataPreComputed_t          *pDataPreComputed, 
                         const HLATracking3DDataRotations_t            *pDataRotations,
                         const HLATracking3DParametersDistFromHeight_t *pParamDistFromHeight,
                         const HLATracking3DParametersPairing_t        *pParamPairing,
                         const RTE_HLAR_ParameterDistEst_t             *pCpar_DistEst
                        );


/* avoid cyclic binding ---------------------------------------------------*/
#endif
