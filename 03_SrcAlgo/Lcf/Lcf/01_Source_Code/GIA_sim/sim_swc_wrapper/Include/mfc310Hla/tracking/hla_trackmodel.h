/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackmodel.h

  DESCRIPTION:            Shared model between dynamic, slam and static tracker

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackmodel.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:10CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:53CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:11CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.6 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackmodel.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackmodel.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.5 2014/01/24 13:37:51CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:51 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.4 2014/01/21 13:09:14CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:15 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.3 2013/11/21 14:15:24CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:25 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.2 2012/04/19 20:01:49CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 integrate ttb18 for each track: time to border for a 18° angle
  CHANGE:                 ttb18 calculations are based on 3D estimations
  CHANGE:                 --- Added comments ---  uid28828 [Apr 19, 2012 8:01:51 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.1 2012/01/25 17:35:19CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKMODEL_INCLUDED
#define HLA_TRACKMODEL_INCLUDED

#include "hla_trackutils.h"


void HLATrackModelInit(       float32*                      puw,
                              float32*                      pvw,
                              float32*                      pfw,
                              float32*                      pHJ,
                              float32*                      pHC,
                        const float32                       uk,
                        const float32                       vk,
                        const float32                       fk,
                        const HLATracking3DDataRotations_t* pDataRotations
                      );

void HLATrackModelMeasurement(      float32                       u,
                                    float32                       v,
                                    float32                       factor,
                                    float32                       dfactor_dsd,
                                    float32*                      xb,
                                    float32*                      yb,
                                    float32*                      pHC,
                                    float32*                      pHE,
                                    float32*                      pHJ,
                              const HLATracking3DDataRotations_t* pDataRotations
                             );

void HLATrackModelMapUpdate(      float32                       uw_in,
                                  float32                       vw_in,
                                  float32                       dw_in,
                                  float32*                      puw_out,
                                  float32*                      pvw_out,
                                  float32*                      pdw_out,
                                  float32*                      pHE,
                                  float32*                      pHJ,
                            const HLATracking3DDataRotations_t* pDataRotations
                           );

void HLATrackModelWorldToCam(       float32*                      puk,
                                    float32*                      pvk,
                              const float32                       uw,
                              const float32                       vw,
                              const float32                       factor,
                              const HLATracking3DDataRotations_t* pDataRotations
                            );

void HLATrackModelTTB(      float32*  pTTBHor,
                      const float32   uw,
                      const float32   dw,
                      const float32   os,
                      const float32   ol,
                      const float32   sp,
                      const float32   yr,
                      const float32   tana,
                      const float32   ttbmax
                     );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
