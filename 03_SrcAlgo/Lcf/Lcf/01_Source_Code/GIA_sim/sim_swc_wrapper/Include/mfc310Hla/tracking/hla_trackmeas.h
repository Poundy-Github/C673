/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackmeas.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackmeas.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:09CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:52CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:11CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.10 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackmeas.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackmeas.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.9 2014/01/24 13:37:49CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:50 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.8 2014/01/10 18:33:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:44 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.7 2013/11/21 17:53:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:12 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.6.1.3 2013/11/21 14:15:27CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:28 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.6.1.2 2013/11/12 13:44:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:43 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.6.1.1 2013/10/18 13:27:59CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:59 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.6 2012/10/10 13:02:43CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:02:43 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.5 2012/10/05 12:46:48CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:46:48 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.4 2012/04/18 17:55:56CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 increase pitch range for tracking to avoid track losses on bumpers
  CHANGE:                 -> remove pitch range Vs speed concept
  CHANGE:                 -> sort SLAM features: update SLAM beginning with the closest light to the prediction, ending with the further one
  CHANGE:                 -> use a wider noise measurement for the isolated lights used in SLAM
  CHANGE:                 --- Added comments ---  uid28828 [Apr 18, 2012 5:55:56 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.3 2012/04/11 17:14:36CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 code review finding fix (no changes in perf): 
  CHANGE:                 split HLATrackMeasGetMeasurementExt() into smaller functions (access to light position)
  CHANGE:                   -> split corresponding structure into smaller structs
  CHANGE:                   -> affects tracking, pairs and icon functions
  CHANGE:                 --- Added comments ---  uid28828 [Apr 11, 2012 5:14:37 PM CEST]
  CHANGE:                 Change Package : 110195:1 http://mks-psad:7002/im/viewissue?selection=110195
  CHANGE:                 Revision 1.2 2012/03/22 19:08:04CET Godreau, Bertrand (uid28828) 
  CHANGE:                 improve data association for the "Oncoming_1stLevelSuppression" rec files
  CHANGE:                 --- Added comments ---  uid28828 [Mar 22, 2012 7:08:04 PM CET]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.1 2012/01/25 17:34:54CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKMEAS_INCLUDED
#define HLA_TRACKMEAS_INCLUDED


#include "hla_trackutils.h"

/* measurement */
void HLATrackMeasGetNormCoordinates(      HLAKalmanMeasPos_t*                   pLNorm,
                                    const HLASegLight_t*                        pL,
                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                   );

void HLATrackMeasGetNormCoordinatesForIsolatedLights(       HLAKalmanMeasPos_t*                   pLNorm,
                                                      const HLASegLight_t*                        pLIsolated,
                                                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                                      const HLATracking3DParametersMeasurement_t* pParamMeas
                                                    );

void HLATrackMeasGetPixCoordinates(       HLAKalmanMeasPosPix_t*                pLPix,
                                    const HLASegLight_t*                        pL,
                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                  );

void HLATrackMeasGetNormAndPixCoordinates(      HLAKalmanMeasPos_t*                   pLNorm,
                                                HLAKalmanMeasPosPix_t*                pLPix,
                                          const HLASegLight_t*                        pL,
                                          const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                          const HLATracking3DParametersMeasurement_t* pParamMeas
                                         );

void HLATrackMeasGetKalmanMeas(       HLAKalmanMeas_t*                      pMeas,
                                const HLASegLight_t*                        pL,
                                const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                const HLATracking3DParametersMeasurement_t* pParamMeas,
                                const HLATracking3DDataPreComputedPair_t*   pDataPreComputedPair
                              );

void HLATrackMeasGetIntensity12bits(        uint16*       pInt12bits,
                                     const HLASegLight_t* pL
                                   );

void HLATrackMeasAddMeasurement(      HLATrack_t*     pT,
                                      HLASegLight_t*  pL,
                                const uint16          ui_dist
                               );

void HLATrackMeasRemoveMeasurement( HLATrack_t* pT );

void HLATrackMeasHammingDistance(       uint32* pdist,
                                  const uint32  x,
                                  const uint32  y
                                );


void HLATrackMeasGetLightPattern(       uint32*       pcodePattern,
                                  const HLASegNgb_t*  pngb
                                );

void HLATrackMeasUpdateMatchingData(      HLATrack_t*                         pT,
                                    const HLASegLight_t*                      pL,
                                    const HLATracking3DParametersMatching_t*  pParamMatching
                                   );

void HLATrackMeasInitMatchingData(      HLATrack_t*     pT,
                                  const HLASegLight_t*  pL
                                 );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
