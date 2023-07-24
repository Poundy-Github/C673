/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackpair.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackpair.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:11CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:54CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:12CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.41 2014/03/28 10:53:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Better distance estimation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:53:11 AM CET]
  CHANGE:                 Change Package : 207432:50 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.40 2014/03/26 11:27:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:34 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.39 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackpair.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackpair.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.38 2014/03/21 09:38:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:45 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.37 2014/03/19 16:31:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:31 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.36 2014/03/10 13:20:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:53 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.35 2014/03/05 11:05:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:24 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2014/03/04 16:52:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:12 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.33 2014/02/21 16:54:41CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update: Changed "Vehicle" to "Pair" for better understandability in macro name
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 21, 2014 4:54:42 PM CET]
  CHANGE:                 Change Package : 207634:3 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.32 2014/02/11 17:24:52CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fixes:
  CHANGE:                  - improved selection of region for tracking
  CHANGE:                  - minor bug fixes for tracking 
  CHANGE:                 
  CHANGE:                 Update in visu:
  CHANGE:                  - new pair visualization
  CHANGE:                  - new features to disable horizon, ROI and vehicle data visu parts
  CHANGE:                  - tunnel visu moved to be part of environment
  CHANGE:                  - minor restructuring of hotkeys
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 11, 2014 5:24:52 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.31 2014/02/07 09:49:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:50:00 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.30 2014/02/06 16:01:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:27 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.29 2014/01/24 13:37:52CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:52 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.28 2014/01/21 13:09:15CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:16 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.27 2014/01/16 11:35:43CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - added some improvements for trucklights-on-highway pair tracking
  CHANGE:                  - changed pairing parameter for trucklights-on-highway pair tracking
  CHANGE:                  - removed switch between night and day visualization
  CHANGE:                 
  CHANGE:                 Minor fixes:
  CHANGE:                  - fixed some tabs
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 16, 2014 11:35:43 AM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.26 2014/01/10 18:33:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:58 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.25 2013/12/18 15:18:06CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:07 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.24 2013/12/13 16:44:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:55 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2013/11/21 17:53:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:30 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22.1.3 2013/11/21 14:15:33CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:33 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.22.1.2 2013/11/21 13:37:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:28 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22.1.1 2013/11/12 13:45:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:02 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.22 2013/08/02 15:25:59CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:59 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
**************************************************************************** */

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>

#include "hla_trackpair.h"
#include "hla_trackmeas.h"
#include "hla_imager.h"
#include "hla_trackmodel.h"

/* init precompuited data for pairs */
static void HLATrackPairInitPreComputed(      HLATracking3DDataPreComputedPair_t* pDataPreComputedPair, 
                                        const HLATracking3DParametersPair_t*      pParamPair,
                                        const HLATracking3DDataPreComputed_t*     pDataPreComputed
                                       );

/* pair kalman tracker init */
#ifdef PC_SIM
static void HLATrackPairKalmanInit(       HLAPair_t*                          pPair,
                                    const HLAKalmanMeas_t*                    pMeasLeft,
                                    const HLAKalmanMeas_t*                    pMeasRight,
                                    const HLATracking3DDataRotations_t*       pDataRotations,
                                    const HLATracking3DDataCali_t*            pDataCali,
                                    const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                  );
#endif

static void HLATrackPairKalmanInitPosition(       HLAPair_t*                          pPair,
                                                  HLAPairStateWidthFree_t*            pStateWidthFree,
                                            const HLAKalmanMeasPos_t*                 pMeasLeftPos,
                                            const HLAKalmanMeasPos_t*                 pMeasRightPos,
                                            const HLATracking3DDataRotations_t*       pDataRotations,
                                            const HLATracking3DDataCali_t*            pDataCali,
                                            const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                          );

static void HLATrackPairKalmanInitIntensityConstant(      HLAPair_t*                          pPair,
                                                          HLAPairStateWidthFree_t*            pStateWidthFree,
                                                    const HLAKalmanMeasPos_t*                 pMeasLeftPos,
                                                    const HLAKalmanMeasPos_t*                 pMeasRightPos,
                                                    const HLAKalmanMeasInt_t*                 pMeasLeftInt,
                                                    const HLAKalmanMeasInt_t*                 pMeasRightInt,
                                                    const HLATracking3DDataCali_t*            pDataCali,
                                                    const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                                   );

static void HLATrackPairKalmanInitWidthFree(      HLAPairStateWidthFree_t*      pStateWidthFree,
                                            const uint8                         doPosition,
                                            const uint8                         doIntConstant,
                                            const HLAKalmanMeas_t*              pMeasLeft,
                                            const HLAKalmanMeas_t*              pMeasRight,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                           );

static void HLATrackPairKalmanInitColor(      HLAPair_t*          pPair,
                                        const HLAKalmanMeasCol_t* pMeasLeftCol,
                                        const HLAKalmanMeasCol_t* pMeasRightCol
                                       );


/* pair kalman tracker time update */
static void HLATrackPairKalmanTimeUpdate(       HLAPair_t*                          pPair,
                                          const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                          const HLATracking3DDataEgomotion_t*       pDataEgomotion
                                        );


/* pair kalman tracker predict/update */
static void HLATrackPairKalmanOneLightPredictOrUpdate(      HLAPair_t*                      pPair,
                                                            HLAKalmanMeasPos_t*             pPredPos,
                                                            HLAKalmanMeasPosPixArea_t*      pPredPixArea,
                                                      const float32*                        pHP,
                                                      const float32*                        pHE,
                                                      const HLAKalmanMeasPos_t*             pMeasPos,
                                                      const HLAKalmanMeasCol_t*             pMeasCol,
                                                      const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                                      const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                                      const uint8                           inputCommand
                                                      );

static void HLATrackPairKalmanUpdate(       HLAPair_t*                      pPair,
                                      const HLAKalmanMeasPos_t*             pMeasPos,
                                      const HLAKalmanMeasCol_t*             pMeasCol,
                                      const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                      const HLATracking3DDataRotations_t*   pDataRotations,
                                      const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                      const float32                         pw,
                                      const uint8                           inputCommand
                                    );

static void HLATrackPairKalmanDelayedUpdate(      HLAPair_t*                    pPair,
                                            const HLATracking3DDataEgomotion_t* pDataEgomotion,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                           );

/* pair reprojection */
static void HLATrackPairReprojectAndGetConfidence(      float32*                            pdist_left,
                                                        float32*                            pdist_right,
                                                        HLAKalmanMeas_t*                    pRepjLeft,
                                                        HLAKalmanMeas_t*                    pRepjRight,
                                                        HLAPairTTBInput*                    pTTBIn,
                                                  const HLAPair_t*                          pPair,
                                                  const HLAKalmanMeas_t*                    pMeasLeft,
                                                  const HLAKalmanMeas_t*                    pMeasRight,
                                                  const HLATracking3DDataRotations_t*       pDataRotations,
                                                  const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                                 );

static void HLATrackPairKalmanReprojectOneLight(      HLAKalmanMeasPos_t* pRepjPos,
                                                      HLAKalmanMeasInt_t* pRepjInt,
                                                      HLAKalmanMeasCol_t* pRepjCol,
                                                const HLAPair_t*          pPair,
                                                const float32*            pHP
                                               );

static void HLATrackPairKalmanReprojection(       HLAKalmanMeas_t*                    pRepjLeft,
                                                  HLAKalmanMeas_t*                    pRepjRight,
                                                  HLAPairTTBInput*                    pTTBIn,
                                            const HLAPair_t*                          pPair,
                                            const HLATracking3DDataRotations_t*       pDataRotations,
                                            const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                          );

static void HLATrackPairGetRMSEOneLight(      float32*            pdist,
                                        const HLAKalmanMeasPos_t* pRepjPos,
                                        const HLAKalmanMeasInt_t* pRepjInt,
                                        const HLAKalmanMeasCol_t* pRepjCol,
                                        const HLAKalmanMeasPos_t* pMeasPos,
                                        const HLAKalmanMeasInt_t* pMeasInt,
                                        const HLAKalmanMeasCol_t* pMeasCol
                                       );

/* track birth */
static void HLATrackPairIsANewPair(       HLAPair_t*                            pPair,
                                          float32*                              pdist,
                                          HLAPairStateWidthFree_t*              pStateWidthFree,
                                    const HLATrack_t*                           pTLeft,
                                    const HLATrack_t*                           pTRight,
                                    const HLATracking3DDataRotations_t*         pDataRotations,
                                    const HLATracking3DDataPreComputedPair_t*   pDataPreComputedPair,
                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                  );


/* models */
static void HLATrackPairModelPredRightFromLeftPre(      float32*                            pdx_p,
                                                        float32*                            pdy_p,
                                                        float32*                            pccdxx_p,
                                                        float32*                            pccdyy_p,
                                                  const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                                  const HLATracking3DDataRotations_t*       pDataRotations
                                                 );

static void HLATrackPairModelInitWidthFree(       float32*                      pfd,
                                                  float32*                      pfl,
                                                  float32*                      pfh,
                                                  float32*                      pfr,
                                                  float32*                      pfi,
                                                  float32*                      pHJL,
                                                  float32*                      pHJR,
                                                  float32*                      pHC,
                                            const HLAKalmanMeasPos_t*           pMeasLeftPos,
                                            const HLAKalmanMeasPos_t*           pMeasRightPos,
                                            const HLAKalmanMeasInt_t*           pMeasLeftInt,
                                            const HLAKalmanMeasInt_t*           pMeasRightInt,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                            );


static void HLATrackPairModelMeasurement(       HLAKalmanMeasPos_t*           pMeasLeftPos,
                                                HLAKalmanMeasInt_t*           pMeasLeftInt,
                                                float32*                      pHLP,
                                                float32*                      pHLE,
                                                HLAKalmanMeasPos_t*           pMeasRightPos,
                                                HLAKalmanMeasInt_t*           pMeasRightInt,
                                                float32*                      pHRP,
                                                float32*                      pHRE,
                                          const HLAPair_t*                    pPair,
                                          const HLATracking3DDataRotations_t* pDataRotations,
                                          const float32                       pw
                                        );

static void HLATrackPairModelReprojection(      HLAKalmanMeasPos_t*           pRepjLeftPos,
                                                HLAKalmanMeasInt_t*           pRepjLeftInt,
                                                HLAKalmanMeasPos_t*           pRepjRightPos,
                                                HLAKalmanMeasInt_t*           pRepjRightInt,
                                                float32*                      pHLP,
                                                float32*                      pHRP,
                                                HLAPairTTBInput*              pTTBIn,
                                          const HLAPair_t*                    pPair,
                                          const HLATracking3DDataRotations_t* pDataRotations,
                                          const float32                       pw
                                         );

static void HLATrackPairModelTimeUpdate(      HLAPair_t*                    pPairOut,
                                              float32*                      pHPS,
                                        const HLAPair_t*                    pPairIn,
                                        const HLATracking3DDataEgomotion_t* pDataEgomotion
                                       );

static void HLATrackPairModelMapUpdate(       HLAPair_t*                    pPairOut,
                                              float32*                      pHP,
                                              float32*                      pHE,
                                        const HLAPair_t*                    pPairIn,
                                        const HLATracking3DDataRotations_t* pDataRotations,
                                        const HLATracking3DDataEgomotion_t* pDataEgomotion
                                      );

/* tools */
static void HLATrackPairToolsGetWidth(      float32*                        pw,
                                            float32*                        ppww,
                                      const HLAPair_t*                      pPair,
                                      const HLATracking3DDataPreComputed_t* pDataPreComputed
                                     );

/* ~CodeReview ~ID:f480dec4f2677b572559c59879fa1738 ~Reviewer:CW01\uidt9253 ~Date:6/26/2012 ~Priority:3 ~Comment:general comment: function documentation not updated, function names do not match */

/* ****************************************************************************
  Functionname:     HLATrackPairInit()                             */ /*!
  Description:      
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
/* ~CodeReview ~ID:5a526d774bfefaecef5a195402aaf7de ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
/* ~CodeReview ~ID:7604ffc55e8702442c7d01fefdb52374 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Pointer parameters of exported functions are not checked for NULL (general issue). */
/* <ln_offset:+2 MISRA Rule 3.4: reviewer name: Alexander Kaps date: 04.09.2012 reason: pragma needed for ROM optimization on Golddust ECU */
/* <ln_offset:+2 MISRA Rule 3.4: reviewer name: Alexander Kaps date: 04.09.2012 reason: pragma needed for ROM optimization on Golddust ECU */
#if(defined(__GOLDDUST__) && (__GOLDDUST__ == 1))
#pragma push
#pragma optimize_for_size_on
#endif
void HLATrackPairInit(      HLATracking3DDataPairs_t*           pDataPairs,
                            HLATracking3DDataPreComputedPair_t* pDataPreComputedPairAhead, 
                            HLATracking3DDataPreComputedPair_t* pDataPreComputedPairOncoming, 
                            HLATracking3DDataPreComputedPair_t* pDataPreComputedPairTruckLights,
                      const HLATracking3DParametersPairing_t*   pParamPair,
                      const HLATracking3DDataPreComputed_t*     pDataPreComputed
                     )
{
  uint8 i;
  HLAPair_t* pPair;
  HLAPair_t* pPairNext;

  /* init pair buffer */
  pPair = &pDataPairs->bufferPairs[0];
  pPairNext = &(pDataPairs->bufferPairs[1]);

  for(i = 0 ; i < (HLA_TRACKING_MAX_NUM_PAIRS - 1) ; i++)
  {
    pPair->next = pPairNext;
    pPair++;
    pPairNext++;
  }

  /* last pair */
  pPair->next = 0;

  pDataPairs->pFreePair = &pDataPairs->bufferPairs[0];


  /* precomuted pair data */
  HLATrackPairInitPreComputed(pDataPreComputedPairAhead,
                              &pParamPair->paramPairAhead,
                              pDataPreComputed
                             );

  HLATrackPairInitPreComputed(pDataPreComputedPairOncoming,
                              &pParamPair->paramPairOncoming,
                              pDataPreComputed
                             );

  HLATrackPairInitPreComputed(pDataPreComputedPairTruckLights,
                              &pParamPair->paramPairTruckLights,
                              pDataPreComputed
                             );
}
/* <ln_offset:+1 MISRA Rule 3.4: reviewer name: Alexander Kaps date: 04.09.2012 reason: pragma needed for ROM optimization on Golddust ECU */
#if(defined(__GOLDDUST__) && (__GOLDDUST__ == 1))
#pragma pop
#endif

/* ****************************************************************************
  Functionname:     HLATrackPairInitPreComputed()                   */ /*!
  Description:      Initialize Pre computed data from parameters
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
static void HLATrackPairInitPreComputed(      HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                        const HLATracking3DParametersPair_t*      pParamPair,
                                        const HLATracking3DDataPreComputed_t*     pDataPreComputed
                                       )
{
  float32 crr,chh;
  float32 idmin,idmean;

  pDataPreComputedPair->pw = (pParamPair->maxInterDist + pParamPair->minInterDist)/2.0f;
  pDataPreComputedPair->ppww = ((pParamPair->maxInterDist - pDataPreComputedPair->pw)*(pParamPair->maxInterDist - pDataPreComputedPair->pw))/9.0f;

  pDataPreComputedPair->ph = (pParamPair->maxHeight + pParamPair->minHeight)/2.0f;
  pDataPreComputedPair->pphh = ((pParamPair->maxHeight - pDataPreComputedPair->ph)*(pParamPair->maxHeight - pDataPreComputedPair->ph))/9.0f;

  pDataPreComputedPair->pdStart = (pParamPair->maxDist + pParamPair->minDistStart)/2.0f;
  pDataPreComputedPair->ppddStart = ((pParamPair->maxDist - pDataPreComputedPair->pdStart)*(pParamPair->maxDist - pDataPreComputedPair->pdStart))/9.0f;

  /* ~CodeReview ~ID:0a322719b899a6f5ad18ece560d9fbdd ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO (2x). */
  idmin = 1/pParamPair->minDistStart;
  idmean = 1/pDataPreComputedPair->pdStart;

  pDataPreComputedPair->dwStart = idmean;
  pDataPreComputedPair->cddStart = (( idmin - idmean )*( idmin - idmean ))/9.0f;


  pDataPreComputedPair->pdEnd = (pParamPair->maxDist + pParamPair->minDistEnd)/2.0f;
  pDataPreComputedPair->ppddEnd = ((pParamPair->maxDist - pDataPreComputedPair->pdEnd)*(pParamPair->maxDist - pDataPreComputedPair->pdEnd))/9.0f;

  pDataPreComputedPair->pa = (pParamPair->maxIcst + pParamPair->minIcst)/2.0f;
  pDataPreComputedPair->ppaa = ((pParamPair->maxIcst - pDataPreComputedPair->pa)*(pParamPair->maxIcst - pDataPreComputedPair->pa))/9.0f;

  /* pair roll (parameterized with delta height) */
  pDataPreComputedPair->pr = 0;

  crr = (pParamPair->maxRollStart*pParamPair->maxRollStart)/9.0f;  /* roll variance */
  chh = ((pDataPreComputedPair->pw/2.0f)*(pDataPreComputedPair->pw/2.0f))*crr;  /* delta height variance */

  pDataPreComputedPair->pprrStart = chh;

  crr = (pParamPair->maxRollEnd*pParamPair->maxRollEnd)/9.0f;  /* roll variance */
  chh = ((pDataPreComputedPair->pw/2.0f)*(pDataPreComputedPair->pw/2.0f))*crr;  /* delta height variance */

  pDataPreComputedPair->pprrEnd = chh;


  /* red chromaticity */
  pDataPreComputedPair->pc = (255*(pParamPair->maxRedChromaticity + pParamPair->minRedChromaticity))/2.0f;
  pDataPreComputedPair->ppcc = (((pParamPair->maxRedChromaticity*255) - pDataPreComputedPair->pc)*((pParamPair->maxRedChromaticity*255) - pDataPreComputedPair->pc))/9.0f;

  /* green chromaticity */
  pDataPreComputedPair->pg = (255*(pParamPair->maxGreenChromaticity + pParamPair->minGreenChromaticity))/2.0f;
  pDataPreComputedPair->ppgg = (((pParamPair->maxGreenChromaticity*255) - pDataPreComputedPair->pg)*((pParamPair->maxGreenChromaticity*255) - pDataPreComputedPair->pg))/9.0f;

  /* speed */
  pDataPreComputedPair->ps = (pParamPair->maxStartSpeed + pParamPair->minStartSpeed)/2.0f;
  pDataPreComputedPair->ppss = ((pParamPair->maxStartSpeed - pDataPreComputedPair->ps)*(pParamPair->maxStartSpeed - pDataPreComputedPair->ps))/9.0f;

  /* yaw */
  pDataPreComputedPair->py = (pParamPair->maxStartYaw + pParamPair->minStartYaw)/2.0f;
  pDataPreComputedPair->ppyy = ((pParamPair->maxStartYaw - pDataPreComputedPair->py)*(pParamPair->maxStartYaw - pDataPreComputedPair->py))/9.0f;

  /* measurement error */
  pDataPreComputedPair->scc = ((255*pParamPair->errMeasRedChromaticity)*(255*pParamPair->errMeasRedChromaticity))/9.0f;
  pDataPreComputedPair->sgg = ((255*pParamPair->errMeasGreenChromaticity)*(255*pParamPair->errMeasGreenChromaticity))/9.0f;
  pDataPreComputedPair->errMaxIntGreyValue = pParamPair->errMeasGreyValue;

  /* horizontal pixel position */
  /* ~CodeReview ~ID:65fbd6aafad9a8690e2d2ed54aa3b69f ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO (2x). */
  pDataPreComputedPair->cxx = ((pParamPair->errMeasPositionHorizontalPixel/pDataPreComputed->FX)*(pParamPair->errMeasPositionHorizontalPixel/pDataPreComputed->FX))/9.0f;
  pDataPreComputedPair->cyy = ((pParamPair->errMeasPositionVerticalPixel/pDataPreComputed->FX)*(pParamPair->errMeasPositionVerticalPixel/pDataPreComputed->FX))/9.0f;

  /* initial hypothesis on on-line cali error */
  pDataPreComputedPair->ccyy_init = (CML_Deg2Rad(1.0f)*CML_Deg2Rad(1.0f))/9.0f;
  pDataPreComputedPair->ccpp_init = (CML_Deg2Rad(1.3f)*CML_Deg2Rad(1.3f))/9.0f;
  pDataPreComputedPair->ccrr_init = (CML_Deg2Rad(0.2f)*CML_Deg2Rad(0.2f))/9.0f;

  /* process white noise on acceleration and yaw rate */
  pDataPreComputedPair->pp_acceleration = (pParamPair->maxAcc*pParamPair->maxAcc)/9.0f;
  pDataPreComputedPair->pp_yawrate = (pParamPair->maxYawRate*pParamPair->maxYawRate)/9.0f;
  pDataPreComputedPair->pp_heightspeed = (pParamPair->maxHeightSpeed*pParamPair->maxHeightSpeed)/9.0f;
  pDataPreComputedPair->pp_deltaheightspeed = (pParamPair->maxDeltaHeightSpeed*pParamPair->maxDeltaHeightSpeed)/9.0f;

  /* variance on minimal speed for yaw estimate */
  pDataPreComputedPair->pp_minspeed_foryaw = (pParamPair->minSpeedForYawEst*pParamPair->minSpeedForYawEst)/9.0f;
}


/* ****************************************************************************
  Functionname:     HLATrackPairPredict                     */ /*!
  Description:      predict track position if static and if dynamic.
                    calculate exclusion area for possible light associations to speed up association algo.

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackPairPredict(       HLAPair_t*                      pPairStart,
                          const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                          const HLATracking3DDataRotations_t*   pDataRotations,
                          const HLATracking3DDataPreComputed_t* pDataPreComputed
                        )
{
  HLAPair_t* pPair;

  /* measurement equation */
  /* ~CodeReview ~ID:89c5413c077a9cd4f311548b04b5b805 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Preferably declare variables within the scope (compound statement) where they are used (general to this file). */
  HLAKalmanMeasPos_t          predLeftPos;
  HLAKalmanMeasPos_t          predRightPos;
  HLAKalmanMeasPosPixArea_t   predLeftArea;
  HLAKalmanMeasPosPixArea_t   predRightArea;
  /* ~CodeReview ~ID:51cb043f837365453eb48a3a789dede4 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:120930 Magic numbers (4x). Consider centralization of these numbers. */
  float32 HLP[21];
  float32 HLE[9];
  float32 HRP[21];
  float32 HRE[9];

  /* precomp data */
  const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair;


  /* predict pair measurement */
  pPair = pPairStart;
  while(pPair != NULL)
  {
    /* --------------------------------------------------------------------------------------------------*/
    /* get pDataPreComputedPair */
    pDataPreComputedPair = &pDataPreComputed->dataOncoming;
    if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_AHEAD)
    {
      pDataPreComputedPair = &pDataPreComputed->dataAhead;
    }
    else if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
    {
      pDataPreComputedPair = &pDataPreComputed->dataTruckLights;
    }
    else
    {
      /* Do nothing */
    }

    /* --------------------------------------------------------------------------------------------------*/
    /* pair state kalman time update */
    HLATrackPairKalmanTimeUpdate( pPair,
                                  pDataPreComputedPair,
                                  pDataEgomotion
                                );

    /* --------------------------------------------------------------------------------------------------*/
    /* predict tracked pairs image position */
    if(pPair->bit_isTracked == 1)
    {
      /* --------------------------------------------------------------------------------------------------*/
      /* pair measurement model: left and right image position prediction and jacobians */
      HLATrackPairModelMeasurement( &(predLeftPos),
                                    0,
                                    HLP,
                                    HLE,
                                    &(predRightPos),
                                    0,
                                    HRP,
                                    HRE,
                                    pPair,
                                    pDataRotations,
                                    pDataPreComputedPair->pw
                                  );

      /* --------------------------------------------------------------------------------------------------*/
      /* get left prediction uncertainty */
      HLATrackPairKalmanOneLightPredictOrUpdate(pPair,
                                                &(predLeftPos),
                                                &(predLeftArea),
                                                HLP,
                                                HLE,
                                                0,
                                                0,
                                                pDataEgomotion,
                                                pDataPreComputed,
                                                HLA_TRACK_KALMANINPUTCMD_PREDICT
                                               );

      if(pPair->stageTrackPair.statusPred != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      {
        pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
      }
      else
      {
        /* --------------------------------------------------------------------------------------------------*/
        /* reinitialize prediction stage */
        pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_INIT;

        /* --------------------------------------------------------------------------------------------------*/
        /* get right prediction uncertainty */
        HLATrackPairKalmanOneLightPredictOrUpdate(pPair,
                                                  &(predRightPos),
                                                  &(predRightArea),
                                                  HRP,
                                                  HRE,
                                                  0,
                                                  0,
                                                  pDataEgomotion,
                                                  pDataPreComputed,
                                                  HLA_TRACK_KALMANINPUTCMD_PREDICT
                                                 );

        if(pPair->stageTrackPair.statusPred != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
        {
          pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
        }
        else
        {
          /* --------------------------------------------------------------------------------------------------*/
          /* copy output of pair prediction for data association */
          pPair->pTLeft->ox_p = predLeftPos.x;
          pPair->pTLeft->oy_p = predLeftPos.y;
          pPair->pTLeft->osxx = predLeftPos.cxx;
          pPair->pTLeft->osxy = predLeftPos.cyx;
          pPair->pTLeft->osyy = predLeftPos.cyy;
          pPair->pTLeft->xmin = predLeftArea.xmin;
          pPair->pTLeft->xmax = predLeftArea.xmax;
          pPair->pTLeft->ymin = predLeftArea.ymin;
          pPair->pTLeft->ymax = predLeftArea.ymax;
          pPair->pTLeft->TrackingStatus.isPredFromPair = 1;

          pPair->pTRight->ox_p = predRightPos.x;
          pPair->pTRight->oy_p = predRightPos.y;
          pPair->pTRight->osxx = predRightPos.cxx;
          pPair->pTRight->osxy = predRightPos.cyx;
          pPair->pTRight->osyy = predRightPos.cyy;
          pPair->pTRight->xmin = predRightArea.xmin;
          pPair->pTRight->xmax = predRightArea.xmax;
          pPair->pTRight->ymin = predRightArea.ymin;
          pPair->pTRight->ymax = predRightArea.ymax;
          pPair->pTRight->TrackingStatus.isPredFromPair = 1;
        }
      }
    }

    pPair = pPair->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackPairUpdate                                */ /*!  
  Description:      Perform update of the kalman dynamic filter (3D position and speed).


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackPairUpdate(      HLAPair_t*                            pPair,
                        const HLATracking3DDataEgomotion_t*         pDataEgomotion,
                        const HLATracking3DDataRotations_t*         pDataRotations,
                        const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                        const HLATracking3DDataPreComputedPair_t*   pDataPreComputedPair,
                        const HLATracking3DParametersMeasurement_t* pParamMeas,
                        const HLATracking3DParametersTTB_t*         pParamTTB
                        )
{
  HLAKalmanMeas_t     repjLeft;
  HLAKalmanMeas_t     repjRight;
  HLAPairTTBInput     ttbInputs;
  float32             dist_left,dist_right;

  /* measurement */
  HLAKalmanMeas_t         measLeft;
  HLAKalmanMeas_t         measRight;
  const HLAKalmanMeas_t*  pMeasLeft;
  const HLAKalmanMeas_t*  pMeasRight;

  /* -----------------------------------------------------------------------------------*/
  /* get left measurement */
  pMeasLeft = 0;
  if(pPair->pTLeft->light_ref != 0)
  {
    /* pre-processing light measurement */
    pMeasLeft = &measLeft;
    HLATrackMeasGetKalmanMeas(&measLeft,
                              pPair->pTLeft->light_ref,
                              pDataPreComputed,
                              pParamMeas,
                              pDataPreComputedPair
                             );
  }

  /* -----------------------------------------------------------------------------------*/
  /* get right measurement */
  pMeasRight = 0;
  if(pPair->pTRight->light_ref != 0)
  {
    /* pre-processing light measurement */
    pMeasRight = &measRight;
    HLATrackMeasGetKalmanMeas(&measRight,
                              pPair->pTRight->light_ref,
                              pDataPreComputed,
                              pParamMeas,
                              pDataPreComputedPair
                             );
  }


  /* -----------------------------------------------------------------------------------*/
  /* update pair kalman filter with left/right measurements */
  if(   (pMeasLeft != 0)
     && (pMeasRight != 0)
     && (pPair->pTRight->dist2Pred < pPair->pTLeft->dist2Pred)
    )
  {
    /* -----------------------------------------------------------------------------------*/
    /* when right meas is closer to pred -> update first with right light*/
    HLATrackPairKalmanUpdate( pPair,
                              &(pMeasRight->pos),
                              &(pMeasRight->col),
                              pDataEgomotion,
                              pDataRotations,
                              pDataPreComputed,
                              pDataPreComputedPair->pw,
                              HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTRIGHT
                            );

    /* -----------------------------------------------------------------------------------*/
    /* update then with left light */
    HLATrackPairKalmanUpdate( pPair,
                              &(pMeasLeft->pos),
                              &(pMeasLeft->col),
                              pDataEgomotion,
                              pDataRotations,
                              pDataPreComputed,
                              pDataPreComputedPair->pw,
                              HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTLEFT
                            );
  }
  else
  {
    /* -----------------------------------------------------------------------------------*/
    /* default update -> update first with left light*/
    if(pMeasLeft != 0)
    {
      HLATrackPairKalmanUpdate( pPair,
                                &(pMeasLeft->pos),
                                &(pMeasLeft->col),
                                pDataEgomotion,
                                pDataRotations,
                                pDataPreComputed,
                                pDataPreComputedPair->pw,
                                HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTLEFT
                              );
    }
    
    /* -----------------------------------------------------------------------------------*/
    /* update then with right light */
    if(pMeasRight != 0)
    {      
      HLATrackPairKalmanUpdate( pPair,
                                &(pMeasRight->pos),
                                &(pMeasRight->col),
                                pDataEgomotion,
                                pDataRotations,
                                pDataPreComputed,
                                pDataPreComputedPair->pw,
                                HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTRIGHT
                              );
    }      
  }

  /* -----------------------------------------------------------------------------------*/
  /* delayed update pair tracker */
  HLATrackPairKalmanDelayedUpdate(pPair,
                                  pDataEgomotion,
                                  pDataRotations
                                 );

  /* -----------------------------------------------------------------------------------*/
  /* reprojection and pair confidence */
  if(pPair->stageTrackPair.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
  {            
    if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_AHEAD)
    {
      /* for pair ahead: calculate maha distance between reprojection and measurement and use it for confidence */
      HLATrackPairReprojectAndGetConfidence(&dist_left,
                                            &dist_right,
                                            &(repjLeft),
                                            &(repjRight),
                                            &ttbInputs,
                                            pPair,
                                            pMeasLeft,
                                            pMeasRight,
                                            pDataRotations,
                                            pDataPreComputedPair
                                           );

      /* update confidence */
      pPair->confidence += (HLA_CHI2_VALUE_N3 - dist_left)/HLA_CHI2_VALUE_N3;
      pPair->confidence += (HLA_CHI2_VALUE_N3 - dist_right)/HLA_CHI2_VALUE_N3;
    }
    else
    {
      /* for pair oncoming: use only lost_time to update confidence (simple reprojection , no jacobian calculations) */
      HLATrackPairModelReprojection(&(repjLeft.pos),
                                    &(repjLeft.intL),
                                    &(repjRight.pos),
                                    &(repjRight.intL),
                                    0,
                                    0,
                                    &ttbInputs,
                                    pPair,
                                    pDataRotations,
                                    pDataPreComputedPair->pw
                                   );
      
      /* update confidence */
      if(pMeasLeft != 0)
      {
        pPair->confidence++;
      }

      if(pMeasRight != 0)
      {
        pPair->confidence++;
      }
    }

    /* set reprojection */
    if(   (pPair->bit_isTracked == 1)
       && (pPair->pTLeft->TrackingStatus.isPredFromPair == 1)
       && (pPair->pTRight->TrackingStatus.isPredFromPair == 1)
      )
    {
      pPair->pTLeft->ouk  = repjLeft.pos.x;
      pPair->pTLeft->ovk  = repjLeft.pos.y;
      pPair->pTLeft->TrackingStatus.isRepjFromPair = 1;

      pPair->pTRight->ouk  = repjRight.pos.x;
      pPair->pTRight->ovk  = repjRight.pos.y;
      pPair->pTRight->TrackingStatus.isRepjFromPair = 1;

      /* left track ttb */
      HLATrackModelTTB( &(pPair->pTLeft->ttb18),
                        ttbInputs.uwl,
                        ttbInputs.dwl,
                        ttbInputs.os,
                        ttbInputs.ol,
                        pDataEgomotion->ego_speed,
                        pDataEgomotion->ego_yawrate,
                        pDataPreComputed->tanaTTB,
                        pParamTTB->maxTTB
                      );
      pPair->pTLeft->TrackingStatus.isTTBFromPair = 1;

      /* right track ttb */
      HLATrackModelTTB( &(pPair->pTRight->ttb18),
                        ttbInputs.uwr,
                        ttbInputs.dwr,
                        ttbInputs.os,
                        ttbInputs.ol,
                        pDataEgomotion->ego_speed,
                        pDataEgomotion->ego_yawrate,
                        pDataPreComputed->tanaTTB,
                        pParamTTB->maxTTB
                      );
      pPair->pTRight->TrackingStatus.isTTBFromPair = 1;
    }
  }
}

/* ***********************************************************************/ /*!
  @fn            void HLATrackPairUpdateTrackedInPairFlag()


  @brief         find best combination of pairs

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackPairUpdateTrackedInPairFlag(       HLAPair_t*                        pPairStart,
                                                HLATracking3DDataDebug_t*         pDataDebug,
                                                HLADebugOutputs_t*                phlaDebugOutputs,
                                          const HLATracking3DParametersPairing_t* pParamPair,
                                          const HLATracking3DDataPreComputed_t*   pDataPreComputed,
                                          AS_t_GetTimestampuS32                   pfGetTimestampuS32
                                        )
{
  HLAPair_t* pPair;
  HLAPair_t* pPair2;

  HLAPair_t* pPairnext;
  HLAPair_t** ppPairGlobalTemp;
  HLAPair_t** ppPairNext;
  HLAPair_t* tableTVGlobalFinal[HLA_TRACKING_MAX_NUM_PAIRS+1];
  HLAPair_t* tableTVGlobalTemp[HLA_TRACKING_MAX_NUM_PAIRS+1];
  float32 conf;
  float32 confmax;

  /* pair width */
  float32 pw;
  float32 ppww;

  uint32 TimeStart_us;

  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* update my and mw for each target vehicle */
  pDataDebug->numPairsCanBeTracked = 0;
  pPair = pPairStart;
  while(pPair != NULL)
  {
    /* find pairs that can be tracked */
    if(   (pPair->confidence>10)
       && (   (pPair->bit_isTracked == 1)
           || (   (pPair->bit_isTracked == 0)
               &&
                  (   (   (   (pPair->pTLeft->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
                           || (pPair->pTLeft->statusAnalysisVehicle.isVehicleAhead == 1)
                          )
                       && (   (pPair->pTRight->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
                           || (pPair->pTRight->statusAnalysisVehicle.isVehicleAhead == 1)
                          )
                      )
                   || (   (   (pPair->pTLeft->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1)
                           || (pPair->pTLeft->statusAnalysisVehicle.isVehicleOncoming == 1)
                          )
                       && (   (pPair->pTRight->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1)
                           || (pPair->pTRight->statusAnalysisVehicle.isVehicleOncoming == 1)
                          )
                      )
                  /* Truck test */
                   || (   (   (pPair->pTLeft->statusAnalysisVehicle.isHighwayBrightTruckLights == 1)
                           || (pPair->pTLeft->statusAnalysisVehicle.isHighwayBright == 1)
                          )
                       && (   (pPair->pTRight->statusAnalysisVehicle.isHighwayBrightTruckLights == 1)
                           || (pPair->pTRight->statusAnalysisVehicle.isHighwayBright == 1)
                          )
                      )
                  )
               && (pPair->lost_time_left == 0)
               && (pPair->lost_time_right == 0)
              )
           )
       )
    {
      pPair->bit_canBeTracked = 1;
      (pDataDebug->numPairsCanBeTracked)++;

      /* get pair width */
      HLATrackPairToolsGetWidth(&pw,
                                &ppww,
                                pPair,
                                pDataPreComputed
                               );

      pPair->xwmin = pPair->pd;
      pPair->xwmax = pPair->pd + pParamPair->maxVehicleLength;
      pPair->ywmin = (pPair->pl) + (-pw/2.0f);
      pPair->ywmax = (pPair->pl) + (pw/2.0f);
    }
    else
    {
      pPair->bit_canBeTracked = 0;

      pPair->xwmin = -1;
      pPair->xwmax = -1;

      pPair->ywmin = -1;
      pPair->ywmax = -1;
    }

    pPair = pPair->next;
  }


  /* create chain of targets above */
  pPair = pPairStart;
  while(pPair != NULL)
  {
    if(pPair->bit_canBeTracked == 1)
    {
      /* reset chain */
      (void)memset(&pPair->tableTVNext[0], 0, sizeof(HLAPair_t*) * (HLA_TRACKING_MAX_NUM_PAIRS));
      ppPairNext = &pPair->tableTVNext[0];

      /* go through the top and smaller targets */
      pPair2 = pPairStart;
      while(pPair2 != NULL)
      {
        if(   (pPair2->bit_canBeTracked == 1)
           && (pPair2 != pPair)
           && (pPair2->pTLeft != pPair->pTLeft)
           && (pPair2->pTLeft != pPair->pTRight)
           && (pPair2->pTRight != pPair->pTLeft)
           && (pPair2->pTRight != pPair->pTRight)
           && (pPair2->xwmin > pPair->xwmin)
          )
        {
          if(   (pPair2->xwmin > pPair->xwmax)
             || (pPair2->ywmax < pPair->ywmin)
             || (pPair2->ywmin > pPair->ywmax)
            )
          {
            (*ppPairNext) = pPair2;
            ppPairNext++;
          }
        }
          
        pPair2 = pPair2->next;
      }

    }
    pPair = pPair->next;
  }
  
  /* reset final chain */
  (void)memset((void*)tableTVGlobalFinal, 0, sizeof(HLAPair_t*) * (HLA_TRACKING_MAX_NUM_PAIRS+1));

  conf = 0;
  confmax = 0;
  pPair = pPairStart;
  while(pPair != NULL)
  {
    /* reset isTracked flag */
    pPair->bit_isTracked = 0;
    pPair->pTLeft->dist_est_pair_link = 0;
    pPair->pTLeft->TrackingStatus.isTrackedInPair = 0;
    pPair->pTRight->dist_est_pair_link = 0;
    pPair->pTRight->TrackingStatus.isTrackedInPair = 0;

    if(pPair->bit_canBeTracked == 1)
    {
      /* init pointer to current target current target*/
      pPair2 = pPairStart;
      while(pPair2 != NULL)
      {
        pPair2->ppPairNext = &pPair2->tableTVNext[0];
        pPair2->pTLeft->TrackingStatus.isLinked2PairTemp = 0;
        pPair2->pTRight->TrackingStatus.isLinked2PairTemp = 0;
        
        pPair2 = pPair2->next;
      }

      /* reset temp chain */
      (void)memset((void*)tableTVGlobalTemp, 0, sizeof(HLAPair_t*) * (HLA_TRACKING_MAX_NUM_PAIRS+1));

      /* init temp chain with pPair */
      ppPairGlobalTemp = tableTVGlobalTemp;
      (*ppPairGlobalTemp) = pPair;   
      (*ppPairGlobalTemp)->pTLeft->TrackingStatus.isLinked2PairTemp = 1;
      (*ppPairGlobalTemp)->pTRight->TrackingStatus.isLinked2PairTemp = 1;
      conf += (*ppPairGlobalTemp)->confidence;

      /* inifinite loop to search along the tree */
      do
      {
        /* get pointer to next pair */
        pPairnext = *((*ppPairGlobalTemp)->ppPairNext);
          
        /* add it to the temporary global chain ? */
        if(   (pPairnext != 0)
           && (pPairnext->pTLeft->TrackingStatus.isLinked2PairTemp == 0)
           && (pPairnext->pTRight->TrackingStatus.isLinked2PairTemp == 0)
          )
        {
          /* incremante temporary lobal chain */
          ppPairGlobalTemp++;

          /* add pair to last position */
          (*ppPairGlobalTemp) = pPairnext; 

          /* lock tracks attached to the pair */
          (*ppPairGlobalTemp)->pTLeft->TrackingStatus.isLinked2PairTemp = 1;
          (*ppPairGlobalTemp)->pTRight->TrackingStatus.isLinked2PairTemp = 1;

          /* update confidence in the temporary global chain */
          conf += (*ppPairGlobalTemp)->confidence;
        }
        else if(pPairnext != 0)
        {
          /* check next pair in table */
          ((*ppPairGlobalTemp)->ppPairNext)++;
        }
        else
        {
          /* copy temporary global chain to final global chain */
          if(conf > confmax)
          {
            confmax = conf;
            (void)memcpy(tableTVGlobalFinal, tableTVGlobalTemp, sizeof(HLAPair_t*) * (HLA_TRACKING_MAX_NUM_PAIRS+1));
          }
        
          /* save position in the table of the next pairs */
          (*ppPairGlobalTemp)->ppPairNext = &(*ppPairGlobalTemp)->tableTVNext[0];
          
          /* unlock tracks attached to the pair */
          (*ppPairGlobalTemp)->pTLeft->TrackingStatus.isLinked2PairTemp = 0;
          (*ppPairGlobalTemp)->pTRight->TrackingStatus.isLinked2PairTemp = 0;

          /* update confidence in the temporary global chain */
          conf -= (*ppPairGlobalTemp)->confidence;

          /* reset the position in the temporary global chain */
          (*ppPairGlobalTemp) = 0;

          /* decremente pointer to the temporary global chain */
          ppPairGlobalTemp--;

          /* check tree search is not finished  */
          /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 24.05.2011 reason: pointer comparison wanted to save runtime */
          if(ppPairGlobalTemp >= tableTVGlobalTemp)
          {
            /* see next in current level */
            ((*ppPairGlobalTemp)->ppPairNext)++;
          }
        }
        
      }
      /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 24.05.2011 reason: pointer comparison wanted to save runtime */
      while(ppPairGlobalTemp>=tableTVGlobalTemp);
    }

    pPair = pPair->next;
  }

  /* set chained target ato be tracked next cycle */
  /* update distances */
  pDataDebug->numPairsTracked = 0;
  ppPairGlobalTemp = tableTVGlobalFinal;
  pPair = (*ppPairGlobalTemp);
  while(pPair != NULL)
  {
    pPair->bit_isTracked = 1;

    /* update track features */
    pPair->pTLeft->dist_est_pair_link = (*ppPairGlobalTemp)->pTRight;
    pPair->pTLeft->TrackingStatus.isTrackedInPair = 1;
    pPair->pTRight->dist_est_pair_link = (*ppPairGlobalTemp)->pTLeft;
    pPair->pTRight->TrackingStatus.isTrackedInPair = 1;

    /* incremante number of targets */
    pDataDebug->numPairsTracked++;

    ppPairGlobalTemp++;
    pPair = (*ppPairGlobalTemp);
  }

  /* save confidence */
  pDataDebug->confPairingGlobal = confmax;

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackPredictFindBestPairs_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}


/* ****************************************************************************
  Functionname:     HLATrackPairRemove                            */ /*!
  Description:      remove landmark from full egomotion state


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackPairRemove(HLAPair_t**               ppPairStart,
                        uint8*                    pnumPairs,
                        HLATracking3DDataPairs_t* pDataPairs
                       )
{

  HLAPair_t* pPair     = (*ppPairStart);
  HLAPair_t* pPairNext = 0;
  HLAPair_t* pPairPrev = 0;

  while(pPair != NULL)
  {
    if(pPair->bit_willBeRemoved == 1)
    {
      (*pnumPairs)--;

      /* save next track pointer in track list. */
      pPairNext = pPair->next;

      /* save the next-in-list track to the previous track. */
      if (pPairPrev != NULL)
      {
        pPairPrev->next = pPair->next;
      }
      else
      {
        (*ppPairStart) = pPair->next;
      }

      /* remove link */
      pPair->pTLeft->TrackingStatus.isLinked2Pair    = 0;
      pPair->pTLeft->TrackingStatus.isTrackedInPair  = 0;
      pPair->pTRight->TrackingStatus.isLinked2Pair   = 0;
      pPair->pTRight->TrackingStatus.isTrackedInPair = 0;

      /* add removed tracks to the beginning of free tracked lights list. */
      pPair->next = pDataPairs->pFreePair;
      pDataPairs->pFreePair = pPair;

      /* move the pointer to the next track. */
      pPair = pPairNext;
    }
    else
    {
      pPairPrev = pPair;
      pPair = pPair->next;
    }

  }
}


/* ***********************************************************************/ /*! 
  @fn            HLATrackPairAdd(void)


  @brief         Detect pairs of tracks

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
void HLATrackPairAdd(       HLATrack_t*                           pTrackStart,
                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                      const HLATracking3DParametersMeasurement_t* pParamMeas,
                      const HLATracking3DDataRotations_t*         pDataRotations,
                            HLAPair_t**                           ppPairStart,
                            uint8*                                pnumPairs,
                            HLATracking3DDataPairs_t*             pDataPairs,
                      const HLACameraData_t*                      pCamData,
                            HLATracking3DDataTracks_t*            pDataTracks,
                      const RTE_HLA_TrafficStyle                  eTrafficStyle
                    )
{
  uint8 i;

  HLATrack_t*           pTrackIn;
  HLAKalmanMeasPos_t    lightPosNorm;
  HLAKalmanMeasPosPix_t lightPosPix;
  
  sint16 xLeft, xRight;
  float32 intLeft, intRight;

  HLATrack_t* pTrackStartSearch;
  HLATrack_t* pTrackCurrent;
  const HLATracking3DDataPreComputedPair_t*  pPairData;

  HLATrack_t* pTLeft;
  HLATrack_t* pTRight;
  HLATrack_t* pT1;
  HLATrack_t* pT2;
  uint8       IDLeft, IDRight, ID1, ID2;
  uint8       TPLeft, TPRight, TP1, TP2;

  /* light measurement and prediction */
  float32 xl;
  float32 yl;
  float32 cxxl;
  float32 cyyl;

  float32 xr;
  float32 yr;
  float32 cxxr;
  float32 cyyr;

  float32 x1;
  float32 y1;
  float32 cxx1;
  float32 cyy1;

  float32 x2;
  float32 y2;
  float32 cxx2;
  float32 cyy2;

  uint16 xmin1, ymin1;
  uint16 xmax1, ymax1;

  uint16 xmin1R, ymin1R;
  uint16 xmax1R, ymax1R;

  /* oncoming right light prediction */
  float32 dx_p_on;
  float32 dy_p_on;
  float32 ccdxx_p_on;
  float32 ccdyy_p_on;

  /* ahead right light prediction */
  float32 dx_p_ah;
  float32 dy_p_ah;
  float32 ccdxx_p_ah;
  float32 ccdyy_p_ah;

  /* add new target vehicle */
  HLAPair_t* pPair;

  /* width-free pair state */
  HLAPairStateWidthFree_t statePairWidthFree;

  /* pair prediction */
  uint16 ymin_p, ymax_p;

  /* pair state  */
  HLAPair_t statePairAhead, statePairOncoming, statePairTruckLights;

  /* mahalanobis distance */
  float32 dist2pred_ahead, dist2pred_oncoming, dist2pred_trucklights, dist,distOncoming, distAhead, distTruckLights;

  /* couple data */
  HLACoupleData_t trackCouple;
  HLACoupleData_t* pTC;

  /* buffer */
  HLATrack_t* pTrackBuffer;
  HLACoupleData_t* pCoupleBuffer;

  /* pair type (ahead, oncoming) */
  uint8 pairtype;

  /* pairing roi */
  sint16 x_pix;
  sint16 y_pix;
  sint16 dx_p_pix;
  sint16 dy_p_pix;
  sint16 deltax;
  sint16 deltay;
  sint16 deltax_p;
  sint16 deltay_p;
  float32 temp;

  /* get buffers */
  pTrackBuffer  = &pDataTracks->free_tracked_lights_buffer[0];
  pCoupleBuffer = &pDataTracks->tableCouple[0];

  /* reset track couple table */
  pDataTracks->numPair = 0;
  (void)memset((void*)(pCoupleBuffer), 0, sizeof(HLACoupleData_t) * HLA_TRACKING_MAX_NUM_TRACKS * HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK);

  /* reset state pairs */
  (void)memset((void*)&statePairAhead, 0, sizeof(HLAPair_t));
  (void)memset((void*)&statePairOncoming, 0, sizeof(HLAPair_t));
  (void)memset((void*)&statePairWidthFree, 0, sizeof(HLAPairStateWidthFree_t));

#ifdef PC_SIM
  HLAPair_t rawPair;
  float32 pw;
  float32 ppww;
  HLAKalmanMeas_t   measLeftInit;
  HLAKalmanMeas_t   measRightInit;

  pPair = *ppPairStart;
  while(pPair)
  {
    pPair->has2meas = 0;

    if(   (pPair->pTLeft->light_ref)
       && (pPair->pTRight->light_ref)
      )
    {
      /* get pair width */
      HLATrackPairToolsGetWidth(&pw,
                                &ppww,
                                pPair,
                                pDataPreComputed
                               );
     
      /* get pair measurement for left light */
      HLATrackMeasGetKalmanMeas(&measLeftInit,
                                pPair->pTLeft->light_ref,
                                pDataPreComputed,
                                pParamMeas,
                                &pDataPreComputed->dataAhead
                               );

      /* get pair measurement for right light */
      HLATrackMeasGetKalmanMeas(&measRightInit,
                                pPair->pTRight->light_ref,
                                pDataPreComputed,
                                pParamMeas,
                                &pDataPreComputed->dataAhead
                               );

      if( ((measRightInit.pos.x - measLeftInit.pos.x) * pDataPreComputed->FX) >= 2.0f )
      {
        pPair->has2meas = 1;

        HLATrackPairKalmanInit( &(rawPair),
                                &measLeftInit,
                                &measRightInit,
                                pDataRotations,
                                0,
                                &(pDataPreComputed->dataAhead)
                              );

        pPair->db_pd  = rawPair.pd;
        pPair->db_pl  = rawPair.pl;                                               /* lateral position */
        pPair->db_ph  = rawPair.ph;                                               /* height */
        pPair->db_pa  = rawPair.pa;                                               /* light intensity constant  */
        pPair->db_pr  = CML_Rad2Deg(atanf(rawPair.pr / pw));                      /* roll as a delta-height */
        pPair->db_pc  = rawPair.pc / 255.0f;                                      /* color state: red chromaticity */
        pPair->db_pg  = rawPair.pg / 255.0f;                                      /* color state: green chromaticity */
        pPair->db_mli = HLAImager_GetRed_Lux(pPair->pTLeft->light_ref->MaxInt);
        pPair->db_mlc = pPair->pTLeft->light_ref->current_R/255.0f;
        pPair->db_mlg = pPair->pTLeft->light_ref->current_G/255.0f;
        pPair->db_mri = HLAImager_GetRed_Lux(pPair->pTRight->light_ref->MaxInt);
        pPair->db_mrc = pPair->pTRight->light_ref->current_R/255.0f;
        pPair->db_mrg = pPair->pTRight->light_ref->current_G/255.0f;
      }
    }

    pPair = pPair->next;
  }
#endif

  /* compute pre-processed data for light pair prediction */
  /* A.Manz: could be done after pDataRotations were updated and stored in PreComputed struct */
  HLATrackPairModelPredRightFromLeftPre(&dx_p_ah,
                                        &dy_p_ah,
                                        &ccdxx_p_ah,
                                        &ccdyy_p_ah,
                                        &(pDataPreComputed->dataAhead),
                                        pDataRotations
                                       );

  HLATrackPairModelPredRightFromLeftPre(&dx_p_on,
                                        &dy_p_on,
                                        &ccdxx_p_on,
                                        &ccdyy_p_on,
                                        &(pDataPreComputed->dataOncoming),
                                        pDataRotations
                                       );

  /* width/height of light area */
  /* ~CodeReview ~ID:d735e69a0ccca79a1b3eef9d53473d5e ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:Check if argument of sqrtf() is positive (4x)! */
  /* Godreau B, code review findings priority changed from 1 to 3 : covariance values are always positive */
  temp = 3.0f * (pDataPreComputed->FX) * sqrtf(pDataPreComputed->dataAhead.cxx);
  deltax = (sint16)CML_s_Round2Int(temp);
  
  temp = 3.0f * (pDataPreComputed->FY) * sqrtf(pDataPreComputed->dataAhead.cyy);
  deltay = (sint16)CML_s_Round2Int(temp);

  /* pred of pairing roi in pixels */
  dx_p_pix = (sint16)CML_s_Round2Int(pDataPreComputed->FX * dx_p_ah);
  dy_p_pix = (sint16)CML_s_Round2Int(pDataPreComputed->FY * dy_p_ah);

  /* width/height of pairing ROI */
  temp = 3.0f * (pDataPreComputed->FX) * sqrtf(pDataPreComputed->dataAhead.cxx + ccdxx_p_ah);
  deltax_p = (sint16)CML_s_Round2Int(temp);

  temp = 3.0f * (pDataPreComputed->FY) * sqrtf(pDataPreComputed->dataAhead.cyy + ccdyy_p_ah);
  deltay_p = (sint16)CML_s_Round2Int(temp);

  /* ----------------------------------------------------------------------------*/
  /* loop over all tracks */
  /* generate search list using pTStartSearch and next_in_cluster pointer */
  pTrackStartSearch = 0;
  pTrackCurrent = 0;
  pT1 = pTrackStart;
  while (pT1 != NULL)
  {
    /* only find pair for measured tracks */
    if(   (pT1->light_ref != 0)
       && (   (pT1->TrackingStatus.willBeRemoved == 0)
           || (pT1->TrackingStatus.testPairForBirth == 1)
          )
       && (pT1->ycenter > pCamData->RoiYu)
      )
    {
      /* preproc light */
      HLATrackMeasGetPixCoordinates(&lightPosPix,
                                    pT1->light_ref,
                                    pParamMeas
                                   );

      /* prediction of horizontal track pixel position in world image cs*/
      x_pix = (sint16)CML_s_Round2Int(lightPosPix.x_center_pix);
      y_pix = (sint16)CML_s_Round2Int(lightPosPix.y_center_pix);
      
      /* horizontal min/max of light area for pairing */
      /* uint16 is always >= 0 */
      pT1->xmin = CML_Min(UI16_T_MAX, (uint16)(x_pix - deltax));
      pT1->xmax = CML_Min(UI16_T_MAX, (uint16)(x_pix + deltax));
      
      /* vertical min/max of light area for pairing */
      /* uint16 is always >= 0 */
      pT1->ymin = CML_Min(UI16_T_MAX, (uint16)(y_pix - deltay));
      pT1->ymax = CML_Min(UI16_T_MAX, (uint16)(y_pix + deltay));

      /* compute uncertainty area in image of a paired right light */
      x_pix = x_pix + dx_p_pix;
      y_pix = y_pix + dy_p_pix;
      
      /* horizontal min/max of light area for pairing */
      pT1->xminR = (uint16)(pT1->xcenter + 1);    /* force xminR to xcenter + 1*/
      /* uint16 is always >= 0 */
      pT1->xmaxR = CML_Min(UI16_T_MAX, (uint16)(x_pix + deltax_p));
      
      /* vertical min/max of light area for pairing */
      /* uint16 is always >= 0 */
      pT1->yminR = CML_Min(UI16_T_MAX, (uint16)(y_pix - deltay_p));
      pT1->ymaxR = CML_Min(UI16_T_MAX, (uint16)(y_pix + deltay_p));

      if(pTrackStartSearch == 0)
      {
        pTrackStartSearch = pT1;
        pTrackCurrent = pTrackStartSearch;
        pTrackCurrent->nextTemp = 0;
      }
      else if(pTrackCurrent != NULL)
      {
        pTrackCurrent->nextTemp = pT1;
        pTrackCurrent = pT1;
        pTrackCurrent->nextTemp = 0;
      }
      else
      {
        /* Do nothing */
      }
    }
    else
    {
      pT1->xmin = UI16_T_MAX;
      pT1->xmax = 0;
      pT1->ymin = UI16_T_MAX;
      pT1->ymax = 0;

      pT1->xminR = UI16_T_MAX;
      pT1->xmaxR = 0;
      pT1->yminR = UI16_T_MAX;
      pT1->ymaxR = 0;
    }

    /* get next track */
    pT1 = pT1->next;
  }

  /* ----------------------------------------------------------------------------*/
  /* loop over all tracks */
  pT1 = pTrackStartSearch;
  while(pT1 != NULL)
  {
    /* preproc light */
    HLATrackMeasGetNormCoordinates( &lightPosNorm,
                                    pT1->light_ref,
                                    pDataPreComputed,
                                    pParamMeas
                                  );

    /* get pair measurement for left light */
    x1 = lightPosNorm.x;
    y1 = lightPosNorm.y;
    cxx1 = pDataPreComputed->dataAhead.cxx;
    cyy1 = pDataPreComputed->dataAhead.cyy;

    xmin1 = pT1->xmin;
    ymin1 = pT1->ymin;
    xmax1 = pT1->xmax;
    ymax1 = pT1->ymax;

    xmin1R = pT1->xminR;
    ymin1R = pT1->yminR;
    xmax1R = pT1->xmaxR;
    ymax1R = pT1->ymaxR;

    ID1 = pT1->TrackID;
    TP1 = pT1->TrackingStatus.testPairForBirth;

    /* second loop over all tracks ("diagonal" search) */
    pT2 = pT1->nextTemp;
    while (pT2 != NULL)
    {
      if(   (   ( xmax1 > pT2->xminR )
             && ( xmin1 < pT2->xmaxR )
             && ( ymax1 > pT2->yminR )
             && ( ymin1 < pT2->ymaxR )
            /* ~CodeReview ~ID:64b15db6b7571341ac19a959d4420184 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (applies to complete sourcefile). */
            /*&&  (((sint16)(pT1->light_ref->xcenter) - (sint16)(pT2->light_ref->xcenter)) > 1 )*/
            )
         || (   ( pT2->xmax > xmin1R )
             && ( pT2->xmin < xmax1R )
             && ( pT2->ymax > ymin1R )
             && ( pT2->ymin < ymax1R )
            /*&&  (((sint16)(pT2->light_ref->xcenter) - (sint16)(pT1->light_ref->xcenter)) > 1 )*/
            )
        )
      {
        /* get testPairForBirth */
        TP2 = pT2->TrackingStatus.testPairForBirth;
        ID2 = pT2->TrackID;
        
        if(   (   (TP1 == 0)
               && (TP2 == 0)
              )
           || (   (TP1 == 0)
               && (TP2 == 1)
               && (pT2->light_ref->TrackID0 == ID1)
              )
           || (   (TP1 == 1)
               && (TP2 == 0)
               && (pT1->light_ref->TrackID0 == pT2->TrackID )
              )
          )
        {
          /* check both are not already tracked in pairs */
          if(  (   (pT1->dist_est_pair_link == 0)
                || (pT2->dist_est_pair_link == 0)
                || (pT1->dist_est_pair_link != pT2)
                )
             && (pT1->TrackingStatus.isTrackedInPair == pT2->TrackingStatus.isTrackedInPair) /*NEW */
            )
          {
            /* preproc light */
            HLATrackMeasGetNormCoordinates( &lightPosNorm,
                                            pT2->light_ref,
                                            pDataPreComputed,
                                            pParamMeas
                                          );

            x2 = lightPosNorm.x;
            y2 = lightPosNorm.y;
            cxx2 = pDataPreComputed->dataAhead.cxx;
            cyy2 = pDataPreComputed->dataAhead.cyy;

            if(x1 < x2)
            {
              /* assign T1/T2 to left/right track */
              pTLeft = pT1;   pTRight = pT2;
              IDLeft = ID1;   IDRight = ID2;
              TPLeft = TP1;   TPRight = TP2;

              xl = x1;   xr = x2;
              yl = y1;   yr = y2;

              cxxl = cxx1;   cxxr = cxx2;
              cyyl = cyy1;   cyyr = cyy2;
            }
            else
            {
              /* assign T1/T2 to left/right track */
              pTLeft = pT2;   pTRight = pT1;
              IDLeft = ID2;   IDRight = ID1;
              TPLeft = TP2;   TPRight = TP1;

              xl = x2;   xr = x1;
              yl = y2;   yr = y1;

              cxxl = cxx2;   cxxr = cxx1;
              cyyl = cyy2;   cyyr = cyy1;
            }

            if( ((xr-xl)*pDataPreComputed->FX) >= 2.0f )
            {
              /* mahalanobis distance to right prediction ahead */
              /* ~CodeReview ~ID:097d04d77b5b5480c5cc0206c99e1522 ~Reviewer:CW01\uidt9253 ~Date:6/27/2012 ~Priority:2 ~Comment:can be moved into the if clause of traffic ahead */
              HLATrackUtilsMaha22Diag(&dist2pred_ahead,
                                      (xl + dx_p_ah) - xr,
                                      (yl + dy_p_ah) - yr,
                                      (cxxl + ccdxx_p_ah) + cxxr,
                                      (cyyl + ccdyy_p_ah) + cyyr
                                     );

              /* init pair state width free */
              statePairWidthFree.isIntConstantUpdated = 0;
              statePairWidthFree.isPositionUpdated = 0;

              /* init pair type */
              pairtype = HLA_TV_TRAFFIC_TYPE_UNKWOWN;

              /* init maha distance */
              distAhead = (HLA_CHI2_VALUE_N6);
              distOncoming = (HLA_CHI2_VALUE_N6);
              distTruckLights = (HLA_CHI2_VALUE_N6);

              /* test traffic oncoming truck lights */
              if(   /*(   (TPRight == 0)
                       && (TPLeft == 0)
                    )
                 ||*/ (   /*(pTRight->light_ref->Status.isOPLight == 1)
                       && (pTLeft->light_ref->Status.isOPLight == 1)
                       &&*/ (pTRight->TrackingStatus.isTrackedInPair == 0)
                       && (pTLeft->TrackingStatus.isTrackedInPair == 0)
                       && (   (   (eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD )
                               && (pTRight->xcenter < pCamData->FOE_x)
                               && (pTLeft->xcenter < pCamData->FOE_x)
                              )
                           || (   (eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
                               && (pTRight->xcenter > pCamData->FOE_x)
                               && (pTLeft->xcenter > pCamData->FOE_x)
                              )
                          )
                       && (pTRight->ycenter < pCamData->FOE_y)
                       && (pTLeft->ycenter < pCamData->FOE_y)
                       && (pTRight->statusAnalysisMisc.isInTruckLightRegion == 1)
                       && (pTLeft->statusAnalysisMisc.isInTruckLightRegion == 1)
                      )
                )
              {
                /* mahalanobis distance to right prediction oncoming */
                HLATrackUtilsMaha22Diag(&dist2pred_trucklights,
                                        (xl + dx_p_on) - xr,
                                        (yl + dy_p_on) - yr,
                                        (cxxl + ccdxx_p_on) + cxxr,
                                        (cyyl + ccdyy_p_on) + cyyr
                                        );

                if(   (dist2pred_trucklights >= 0)
                   && (dist2pred_trucklights < HLA_CHI2_VALUE_N2)
                  )
                {
                  /* indicate test is for traffic oncoming */
                  statePairOncoming.bit_TrafficType = HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS;

                  /* check pair can be traffic oncoming */
                  HLATrackPairIsANewPair( &statePairTruckLights,
                                          &distTruckLights,
                                          &statePairWidthFree,
                                          pTLeft,
                                          pTRight,
                                          pDataRotations,
                                          &(pDataPreComputed->dataTruckLights),
                                          pDataPreComputed,
                                          pParamMeas
                                        );

                  /* update pairtype */
                  if(   (distTruckLights >= 0)
                     && (distTruckLights < HLA_CHI2_VALUE_N6)
                    )
                  {
                    pairtype = HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS;
                  }
                }
              }

              /* test traffic ahead pair */
              if(   (   (TPRight == 0)
                     && (TPLeft == 0)
                    )
                 || (   (pTRight->light_ref->Status.isOPLight == 0)
                     && (pTLeft->light_ref->Status.isOPLight == 0)
                     && (pTRight->TrackingStatus.isTrackedInPair == 0)
                     && (pTLeft->TrackingStatus.isTrackedInPair == 0)
                    )
                )
              {

                if(   (dist2pred_ahead >= 0)
                   && (dist2pred_ahead < HLA_CHI2_VALUE_N2)
                  )
                {
                  /* indicate test is for traffic ahead */
                  statePairAhead.bit_TrafficType = HLA_TV_TRAFFIC_TYPE_AHEAD;
                 
                  /* check pair can be traffic ahead */
                  HLATrackPairIsANewPair(&statePairAhead,
                                         &distAhead,
                                         &statePairWidthFree,
                                         pTLeft,
                                         pTRight,
                                         pDataRotations,
                                         &(pDataPreComputed->dataAhead),
                                         pDataPreComputed,
                                         pParamMeas
                                        );

                  /* update pairtype */
                  if(   (distAhead >= 0)
                     && (distAhead < HLA_CHI2_VALUE_N6)
                    )
                  {
                    if(pairtype == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
                    {
                      /* pair can be TRUCKLIGHTS or AHEAD, check which fits better*/
                      if(distAhead < distTruckLights)
                      {
                        pairtype = HLA_TV_TRAFFIC_TYPE_AHEAD;
                      }
                    }
                    else
                    {
                      /* pair can only be AHEAD */
                      pairtype = HLA_TV_TRAFFIC_TYPE_AHEAD;
                    }
                  }
                }
              }

              /* test traffic oncoming pair */
              if(   (   (TPRight == 0)
                     && (TPLeft == 0)
                    )
                 || (   (pTRight->light_ref->Status.isOPLight == 1)
                     && (pTLeft->light_ref->Status.isOPLight == 1)
                     && (pTRight->TrackingStatus.isTrackedInPair == 0)
                     && (pTLeft->TrackingStatus.isTrackedInPair == 0)
                    )
                )
              {
                /* mahalanobis distance to right prediction oncoming */
                HLATrackUtilsMaha22Diag(&dist2pred_oncoming,
                                        (xl + dx_p_on) - xr, 
                                        (yl + dy_p_on) - yr, 
                                        (cxxl + ccdxx_p_on) + cxxr, 
                                        (cyyl + ccdyy_p_on) + cyyr
                                       );

                if(   (dist2pred_oncoming >= 0)
                   && (dist2pred_oncoming < HLA_CHI2_VALUE_N2)
                  )
                {
                  /* indicate test is for traffic oncoming */
                  statePairOncoming.bit_TrafficType = HLA_TV_TRAFFIC_TYPE_ONCOMING;
                 
                  /* check pair can be traffic oncoming */
                  HLATrackPairIsANewPair(&statePairOncoming,
                                         &distOncoming,
                                         &statePairWidthFree,
                                         pTLeft,
                                         pTRight,
                                         pDataRotations,
                                         &(pDataPreComputed->dataOncoming),
                                         pDataPreComputed,
                                         pParamMeas
                                        );

                  /* update pairtype */
                  if(   (distOncoming >= 0)
                    &&  (distOncoming < HLA_CHI2_VALUE_N6)
                    )
                  {
                    if(pairtype == HLA_TV_TRAFFIC_TYPE_AHEAD)
                    {
                      /* pair can be AHEAD or ONCOMING, check which fits better */
                      if(distOncoming < distAhead)
                      {
                        pairtype = HLA_TV_TRAFFIC_TYPE_ONCOMING;
                      }
                    }
                    else if(pairtype == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
                    {
                      /* pair can be TRUCKLIGHT or ONCOMING, check which fits better */
                      if (distOncoming < distTruckLights)
                      {
                        pairtype = HLA_TV_TRAFFIC_TYPE_ONCOMING;
                      }
                    }
                    else
                    {
                      /* pair can only be oncoming */
                      pairtype = HLA_TV_TRAFFIC_TYPE_ONCOMING;
                    }
                  }
                }
              }

              /* add couple to the global list */
              if(pairtype != HLA_TV_TRAFFIC_TYPE_UNKWOWN)
              {
                trackCouple.IDL = IDLeft;
                trackCouple.IDT = IDRight;
                trackCouple.type = pairtype;
                trackCouple.ui_dist = 0;

                if(pairtype == HLA_TV_TRAFFIC_TYPE_AHEAD)
                {
                  trackCouple.ui_dist = (uint16)CML_f_MinMax(0, UI13_T_MAX, (distAhead / HLA_CHI2_VALUE_N6) * UI13_T_MAX);
                  trackCouple.type = HLA_TV_TRAFFIC_TYPE_AHEAD;
                }
                else if(pairtype == HLA_TV_TRAFFIC_TYPE_ONCOMING)
                {
                  trackCouple.ui_dist = (uint16)CML_f_MinMax(0, UI13_T_MAX, (distOncoming / HLA_CHI2_VALUE_N6) * UI13_T_MAX);
                  trackCouple.type = HLA_TV_TRAFFIC_TYPE_ONCOMING;
                }
                else
                {
                  trackCouple.ui_dist = (uint16)CML_f_MinMax(0, UI13_T_MAX, (distTruckLights / HLA_CHI2_VALUE_N6) * UI13_T_MAX);
                  trackCouple.type = HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS;
                }
                
                /* add track couple to list */
                HLATrackUtilsAddCoupleToList( &pDataTracks->tableCouple[0],
                                              &(pDataTracks->numPair),
                                              &trackCouple,
                                              HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK*HLA_TRACKING_MAX_NUM_TRACKS
                                            );
              }
            }
          }
        }
      }

      /* get next track */
      pT2 = pT2->nextTemp;
    }

    /* get next track */
    pT1 = pT1->nextTemp;
  }

  /********************************************************************************************/
  /* go through all track couples */
  pTC = &pDataTracks->tableCouple[0];
  for(i = 0 ; i < pDataTracks->numPair ; i++)
  {
    if(pDataPairs->pFreePair != 0)
    {
      /* ~CodeReview ~ID:71418a4b0cc8ea9a3fa06310f8668da2 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Possible array out of bounds. How is it assured that IDL and IDT are in range with HLA_TRACKING_MAX_NUM_TRACKS? */
      pTLeft  = &(pTrackBuffer[pTC->IDL]);
      pTRight = &(pTrackBuffer[pTC->IDT]);
      
      {
        dist = 0;

        /* check pair doesn't already exist */
        pPair = (*ppPairStart);
        while(pPair != NULL)
        {
          if(   (pPair->pTLeft == pTLeft)
             && (pPair->pTRight == pTRight)
            )
          {
            dist = -1;
            break;
          }

          pPair = pPair->next;
        }

        if(dist >= 0)
        {
          /* last check:  check if there are brighter lights inside the prediction area */
          xLeft = pTLeft->xcenter;
          intLeft = pTLeft->MaxInt;
          xRight = pTRight->xcenter;
          intRight = pTRight->MaxInt;
          ymax_p = CML_Max(pTLeft->ymax, pTRight->ymax);
          ymin_p = CML_Max(pTLeft->ymin, pTRight->ymin);

          pTrackIn = pTrackStart;
          while (pTrackIn != NULL)
          {
            if(   (pTrackIn->xcenter > xLeft)
               && (pTrackIn->xcenter < xRight)
               && (pTrackIn->ycenter < ymax_p)
               && (pTrackIn->ycenter > ymin_p)
               && (   (pTrackIn->MaxInt > intLeft)
                   || (pTrackIn->MaxInt > intRight)
                  )
              )
            {
              dist = -1;
              break;
            }
            pTrackIn = pTrackIn->next;
          }
        }

        if(dist >= 0)
        {
          /* set up new pair */
          
          /* manage ROLLING BUFFER */

          /*  get next free TrackListnode */
          pPair = pDataPairs->pFreePair;
          pDataPairs->pFreePair = pDataPairs->pFreePair->next;

          /* reset target vehicle struct */
          (void)memset((void*)pPair, 0, sizeof(HLAPair_t));

          /* get traffic type (ahead/oncoming) */
          pPair->bit_TrafficType = pTC->type;

          if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_AHEAD)
          {
            pPairData = &pDataPreComputed->dataAhead;
          }
          else if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
          {
            pPairData = &pDataPreComputed->dataTruckLights;
          }
          else
          {
            pPairData = &pDataPreComputed->dataOncoming;
          }

          statePairWidthFree.isIntConstantUpdated = 0;
          statePairWidthFree.isPositionUpdated = 0;

          HLATrackPairIsANewPair( pPair,
                                  0,
                                  &statePairWidthFree,
                                  pTLeft,
                                  pTRight,
                                  pDataRotations,
                                  pPairData,
                                  pDataPreComputed,
                                  pParamMeas
                                );

          /* add new elemt as first elemt of tracking list */
          pPair->next = (*ppPairStart);

          /* return tracked_lights */
          (*ppPairStart) = pPair;

          /* incremente counter landmarks */
          (*pnumPairs)++;

          /* link tracks to target vehicle */
          pPair->pTLeft  = pTLeft;
          pPair->pTRight = pTRight;

          /* set track time */
          pPair->track_time_pair2 = 2;
          pPair->trace_time_pair  = 1;

          /* set confidence */
          pPair->confidence = (((float32)UI13_T_MAX - pTC->ui_dist)/(float32)UI13_T_MAX)*(pPair->track_time_pair2);

          /* set lost time */
          pPair->lost_time_left = 0;
          pPair->lost_time_right = 0;

#ifdef PC_SIM
          pPair->PairID = ((uint8)(pPair-&pDataPairs->bufferPairs[0]));

          if(pTLeft->TrackingStatus.testPairForBirth)
          {
            pTLeft->light_ref->newTrackAnalysis.newTrackReasonTestPairSuccess = 1;
          }

          if(pTRight->TrackingStatus.testPairForBirth)
          {
            pTRight->light_ref->newTrackAnalysis.newTrackReasonTestPairSuccess = 1;
          }
#endif

          /* cancel remove flag for paired new tracks */
          if(pTLeft->TrackingStatus.testPairForBirth == 1)
          {
            pPair->bit_bornFromPairTest = 1;
            pTLeft->TrackingStatus.willBeRemoved = 0;
            pTLeft->TrackingStatus.testPairForBirth = 0;
            pTLeft->TrackingStatus.isBornFromPairTest = 1;
          }

          if(pTRight->TrackingStatus.testPairForBirth == 1)
          {
            pPair->bit_bornFromPairTest = 1;
            pTRight->TrackingStatus.willBeRemoved = 0;
            pTRight->TrackingStatus.testPairForBirth = 0;
            pTRight->TrackingStatus.isBornFromPairTest = 1;
          }

          /* flag tracks */
          pTLeft->TrackingStatus.isLinked2Pair = 1;
          pTLeft->TrackingStatus.isTrackedInPair = 0;
          pTRight->TrackingStatus.isLinked2Pair = 1;
          pTRight->TrackingStatus.isTrackedInPair = 0;

          /* add only one pair : stop the loop*/
          break;
        }
      }
    }

    pTC++;
  }
}


#ifdef PC_SIM
/* ****************************************************************************
  Functionname:     HLATrackPairKalmanInit                          */ /*!
  Description:      initialize extended Kalman filter (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanInit(       HLAPair_t*                          pPair,
                                    const HLAKalmanMeas_t*                    pMeasLeft,
                                    const HLAKalmanMeas_t*                    pMeasRight,
                                    const HLATracking3DDataRotations_t*       pDataRotations,
                                    const HLATracking3DDataCali_t*            pDataCali,
                                    const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                  )
{
  HLAPairStateWidthFree_t stateWidthFree;

  /* reset stateWidthFree */
  stateWidthFree.isIntConstantUpdated = 0;
  stateWidthFree.isPositionUpdated = 0;

  /* update position part of the width-free pair state */
  HLATrackPairKalmanInitWidthFree(&stateWidthFree,
                                  1,
                                  1,
                                  pMeasLeft,
                                  pMeasRight,
                                  pDataRotations
                                 );

  /* initialize pair state from pair measurement */
  HLATrackPairKalmanInitPosition(pPair,
                                 &stateWidthFree,
                                 &(pMeasLeft->pos),
                                 &(pMeasRight->pos),
                                 pDataRotations,
                                 0,
                                 pDataPreComputedPair
                                );

  /* init pair intensity constant */
  HLATrackPairKalmanInitIntensityConstant(pPair,
                                          &stateWidthFree,
                                          &(pMeasLeft->pos),
                                          &(pMeasRight->pos),
                                          &(pMeasLeft->intL),
                                          &(pMeasRight->intL),
                                          0,
                                          pDataPreComputedPair
                                         );

  /* init color*/
  HLATrackPairKalmanInitColor(pPair,
                              &(pMeasLeft->col),
                              &(pMeasRight->col)
                             );
}
#endif

/* ****************************************************************************
  Functionname:     HLATrackPairKalmanInitPosition                  */ /*!
  Description:      initialize extended Kalman filter only for distance check (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanInitPosition(       HLAPair_t*                          pPair,
                                                  HLAPairStateWidthFree_t*            pStateWidthFree,
                                            const HLAKalmanMeasPos_t*                 pMeasLeftPos,
                                            const HLAKalmanMeasPos_t*                 pMeasRightPos,
                                            const HLATracking3DDataRotations_t*       pDataRotations,
                                            const HLATracking3DDataCali_t*            pDataCali,
                                            const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                          )
{
  const float32* TK;
  float32 tkx, tky, tkz;

  /* pair state */
  float32 ppdd;
  float32 ppld, ppll;
  float32 pphd, pphl, pphh;
  float32 pprd, pprl, pprh, pprr;

  /* pair state without width info */
  float32 fd;
  float32 fl;
  float32 fh;
  float32 fr;

  /* pair mesurement */
  float32 cxxl;
  float32 cyyl;

  float32 cxxr;
  float32 cyyr;

  /* pair witdh */
  float32 w;
  float32 sww;

  /* online cali */
  float32 ccyy;
  float32 ccpp;
  float32 ccrr;

  /* jacobian */
  float32* HJL;  /* 6x3 */
  float32* HJR;  /* 6x3 */
  float32* HC;   /* 6x3 */

  float32 hjl0,  hjl1;
  float32 hjl3,  hjl4;
  float32 hjl6,  hjl7;
  float32 hjl15, hjl16;

  float32 hjr0,  hjr1;
  float32 hjr3,  hjr4;
  float32 hjr6,  hjr7;
  float32 hjr15, hjr16;

  float32 hc0,  hc1,  hc2;
  float32 hc3,  hc4,  hc5;
  float32 hc6,  hc7,  hc8;
  float32 hc15, hc16, hc17;

  float32 hw0;
  float32 hw1;
  float32 hw2;
  float32 hw5;

  /* temp values */
  float32 ph0, ph1, ph2;
  float32 ph5;
  float32 ph6, ph7, ph8;
  float32 ph11;
  float32 ph12, ph13, ph14;
  /* <ln_offset:+1 PCLINT Error 793: reviewer name: Bertrand Godreau date: 23.05.2011 reason: declare more than 127 identifiers in the function to speed-up calculations */
  float32 ph17;


  /* get pair measurement */
  cxxl = pMeasLeftPos->cxx;
  cyyl = pMeasLeftPos->cyy;

  cxxr = pMeasRightPos->cxx;
  cyyr = pMeasRightPos->cyy;

  /* get pair width */
  w = pDataPreComputedPair->pw;
  sww = pDataPreComputedPair->ppww;

  /* get translation */
  TK = &pDataRotations->TK[0];
  tkx = TK[0];
  tky = TK[1];
  tkz = TK[2];

  /* get road */
  /*rrvv = pDataRoad->rrvv;*/

  /* get on-line cali */
  if(pDataCali != NULL)
  {
    ccyy = pDataCali->ccyy;
    ccpp = pDataCali->ccpp;
    ccrr = pDataCali->ccrr;
  }
  else
  {
    ccyy = pDataPreComputedPair->ccyy_init;
    ccpp = pDataPreComputedPair->ccpp_init;
    ccrr = pDataPreComputedPair->ccrr_init;
  }

  /* init pair model (without width info) */
  /*HLATracking3DModelPairInitWidthFree( 
                            &fd,
                            &fl,
                            &fh,
                            &fr,
                            0,
                            HJL, 
                            HJR, 
                            HC, 
                            pM, 
                            pDataRotations
                            );*/

  fd = pStateWidthFree->fd;
  fl = pStateWidthFree->fl;
  fh = pStateWidthFree->fh;
  fr = pStateWidthFree->fr;

  HJL = &pStateWidthFree->HJLf[0];
  HJR = &pStateWidthFree->HJRf[0];
  HC = &pStateWidthFree->HCf[0];

  /* add witdh info */
  pPair->pd = tkx + (w*fd);
  pPair->pl = tky + (w*fl);
  pPair->ph = tkz + (w*fh);
  pPair->pr = (w*fr);

  pPair->ps = pDataPreComputedPair->ps;
  pPair->py = pDataPreComputedPair->py;

  /* get jacobians */
  hjl0  = w * HJL[0];      hjl1  = w * HJL[1];
  hjl3  = w * HJL[3];      hjl4  = w * HJL[4];
  hjl6  = w * HJL[6];      hjl7  = w * HJL[7];
  hjl15 = w * HJL[15];     hjl16 = w * HJL[16];

  hjr0  = w * HJR[0];      hjr1  = w * HJR[1];
  hjr3  = w * HJR[3];      hjr4  = w * HJR[4];
  hjr6  = w * HJR[6];      hjr7  = w * HJR[7];
  hjr15 = w * HJR[15];     hjr16 = w * HJR[16];

  hc0  = w * HC[0];    hc1  = w * HC[1];    hc2  = w * HC[2];    
  hc3  = w * HC[3];    hc4  = w * HC[4];    hc5  = w * HC[5];    
  hc6  = w * HC[6];    hc7  = w * HC[7];    hc8  = w * HC[8];    
  hc15 = w * HC[15];   hc16 = w * HC[16];   hc17 = w * HC[17];    

  hw0 = fd;
  hw1 = fl;
  hw2 = fh;
  hw5 = fr;

  /* calculate covariance matrix PP = HJL*PJL*HJL' + HJR*PJR*HJR' + HC*PC*HC' + HR*PR*HR' + HW*PW*HW' */

  /* PH = HJL*PJL*HJL' */
  ph0  = (cxxl*hjl0);
  ph1  = (cxxl*hjl3);
  ph2  = (cxxl*hjl6);
  ph5  = (cxxl*hjl15);

  ph6  = (cyyl*hjl1);
  ph7  = (cyyl*hjl4);
  ph8  = (cyyl*hjl7);
  ph11 = (cyyl*hjl16);

  ppdd = (hjl0 *ph0) + (hjl1 *ph6);
  ppld = (hjl3 *ph0) + (hjl4 *ph6);
  pphd = (hjl6 *ph0) + (hjl7 *ph6);
  pprd = (hjl15*ph0) + (hjl16*ph6);

  ppll = (hjl3 *ph1) + (hjl4 *ph7);
  pphl = (hjl6 *ph1) + (hjl7 *ph7);
  pprl = (hjl15*ph1) + (hjl16*ph7);

  pphh = (hjl6 *ph2) + (hjl7 *ph8);
  pprh = (hjl15*ph2) + (hjl16*ph8);

  pprr = (hjl15*ph5) + (hjl16*ph11);


  /* PH += HJR*PJR*HJR' */
  ph0  = (cxxr*hjr0);
  ph1  = (cxxr*hjr3);
  ph2  = (cxxr*hjr6);
  ph5  = (cxxr*hjr15);

  ph6  = (cyyr*hjr1);
  ph7  = (cyyr*hjr4);
  ph8  = (cyyr*hjr7);
  ph11 = (cyyr*hjr16);


  ppdd += (hjr0 *ph0) + (hjr1 *ph6);
  ppld += (hjr3 *ph0) + (hjr4 *ph6);
  pphd += (hjr6 *ph0) + (hjr7 *ph6);
  pprd += (hjr15*ph0) + (hjr16*ph6);

  ppll += (hjr3 *ph1) + (hjr4 *ph7);
  pphl += (hjr6 *ph1) + (hjr7 *ph7);
  pprl += (hjr15*ph1) + (hjr16*ph7);

  pphh += (hjr6 *ph2) + (hjr7 *ph8);
  pprh += (hjr15*ph2) + (hjr16*ph8);

  pprr += (hjr15*ph5) + (hjr16*ph11);

  /* PH += HC*PC*HC' */
  ph0  = (ccyy*hc0);
  ph1  = (ccyy*hc3);
  ph2  = (ccyy*hc6);
  ph5  = (ccyy*hc15);

  ph6  = (ccpp*hc1);
  ph7  = (ccpp*hc4);
  ph8  = (ccpp*hc7);
  ph11 = (ccpp*hc16);

  ph12 = (ccrr*hc2);
  ph13 = (ccrr*hc5);
  ph14 = (ccrr*hc8);
  ph17 = (ccrr*hc17);


  ppdd += (hc0 *ph0) + (hc1 *ph6)  + (hc2 *ph12);
  ppld += (hc3 *ph0) + (hc4 *ph6)  + (hc5 *ph12);
  pphd += (hc6 *ph0) + (hc7 *ph6)  + (hc8 *ph12);
  pprd += (hc15*ph0) + (hc16*ph6)  + (hc17*ph12);

  ppll += (hc3 *ph1) + (hc4 *ph7)  + (hc5 *ph13);
  pphl += (hc6 *ph1) + (hc7 *ph7)  + (hc8 *ph13);
  pprl += (hc15*ph1) + (hc16*ph7)  + (hc17*ph13);

  pphh += (hc6 *ph2) + (hc7 *ph8)  + (hc8 *ph14);
  pprh += (hc15*ph2) + (hc16*ph8)  + (hc17*ph14);

  pprr += (hc15*ph5) + (hc16*ph11) + (hc17*ph17);

  /* PJ += HW*PW*HW' */
  ph0 = (sww*hw0);
  ph1 = (sww*hw1);
  ph2 = (sww*hw2);
  ph5 = (sww*hw5);

  ppdd += (hw0*ph0);
  ppld += (hw1*ph0);
  pphd += (hw2*ph0);
  pprd += (hw5*ph0);

  ppll += (hw1*ph1);
  pphl += (hw2*ph1);
  pprl += (hw5*ph1);

  pphh += (hw2*ph2);
  pprh += (hw5*ph2);

  pprr += (hw5*ph5);

  /* set pair state covariance */
  pPair->ppdd = ppdd;
  pPair->ppld = ppld;    pPair->ppll = ppll;
  pPair->pphd = pphd;    pPair->pphl = pphl;    pPair->pphh = pphh;
  pPair->pprd = pprd;    pPair->pprl = pprl;    pPair->pprh = pprh;      pPair->pprr = pprr;

  /* set cross-correlation between dynamic  and position: PSD */ 
  pPair->ppsd = 0;  pPair->ppsl = 0;
  pPair->ppyd = 0;  pPair->ppyl = 0;

  /* set cross-correlation between dynamic and structure: PSC */ 
  pPair->ppsh = 0;  pPair->ppsr = 0;
  pPair->ppyh = 0;  pPair->ppyr = 0;

  /* set dynamic part: PS */
  pPair->ppss = pDataPreComputedPair->ppss;
  pPair->ppys = 0;  pPair->ppyy = pDataPreComputedPair->ppyy;
}


/* ****************************************************************************
  Functionname:     HLATrackPairKalmanInitIntensityConstant         */ /*!
  Description:      initialize extended Kalman filter only for intensity constant check (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanInitIntensityConstant(      HLAPair_t*                          pPair,
                                                          HLAPairStateWidthFree_t*            pStateWidthFree,
                                                    const HLAKalmanMeasPos_t*                 pMeasLeftPos,
                                                    const HLAKalmanMeasPos_t*                 pMeasRightPos,
                                                    const HLAKalmanMeasInt_t*                 pMeasLeftInt,
                                                    const HLAKalmanMeasInt_t*                 pMeasRightInt,
                                                    const HLATracking3DDataCali_t*            pDataCali,
                                                    const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                                   )
{
  /* pair state */
  float32 ppaa;

  /* pair state without width info */
  float32 fi;

  /* pair mesurement */
  float32 cxxl;
  float32 cyyl;
  float32 siil;

  float32 cxxr;
  float32 cyyr;
  float32 siir;

  /* pair witdh */
  float32 w,w2;
  float32 sww;

  /* online cali */
  float32 ccyy;
  float32 ccpp;
  float32 ccrr;

  /* jacobian */
  float32* HJL;  /* 6x3 */
  float32* HJR;  /* 6x3 */
  float32* HC;   /* 6x3 */

  float32 hjl12, hjl13, hjl14;

  float32 hjr12, hjr13, hjr14;

  float32 hc12, hc13, hc14;

  float32 hw4;

  /* temp values */
  float32 ph4;
  float32 ph10;
  /* <ln_offset:+1 PCLINT Error 793: reviewer name: Bertrand Godreau date: 23.05.2011 reason: declare more than 127 identifiers in the function to speed-up calculations */
  float32 ph16;


  /* get pair measurement */
  cxxl = pMeasLeftPos->cxx;
  cyyl = pMeasLeftPos->cyy;
  siil = pMeasLeftInt->sii;

  cxxr = pMeasRightPos->cxx;
  cyyr = pMeasRightPos->cyy;
  siir = pMeasRightInt->sii;

  /* get pair width */
  w = pDataPreComputedPair->pw;
  w2 = w * w;
  sww = pDataPreComputedPair->ppww;

  /* get on-line cali */
  if(pDataCali != NULL)
  {
    ccyy = pDataCali->ccyy;
    ccpp = pDataCali->ccpp;
    ccrr = pDataCali->ccrr;
  }
  else
  {
    ccyy = pDataPreComputedPair->ccyy_init;
    ccpp = pDataPreComputedPair->ccpp_init;
    ccrr = pDataPreComputedPair->ccrr_init;
  }

  /* init pair model (without width info) */
  /*HLATracking3DModelPairInitWidthFree( 
                            0,
                            0,
                            0,
                            0,
                            &fi,
                            HJL, 
                            HJR, 
                            HC, 
                            pM, 
                            pDataRotations
                            );*/

  fi = pStateWidthFree->fa;

  HJL = &pStateWidthFree->HJLf[0];
  HJR = &pStateWidthFree->HJRf[0];
  HC = &pStateWidthFree->HCf[0];


  /* add witdh info */
  pPair->pa = (w2*fi);

  /* get jacobians */
  hjl12 = w2* HJL[12];     hjl13 = w2* HJL[13];     hjl14 = w2 * HJL[14];    
  hjr12 = w2* HJR[12];     hjr13 = w2* HJR[13];     hjr14 = w2 * HJR[14];    
  hc12 = w2* HC[12];   hc13 = w2* HC[13];   hc14 = w2* HC[14];    
  hw4 = 2*(w*fi);

  /* calculate covariance matrix PP = HJL*PJL*HJL' + HJR*PJR*HJR' + HC*PC*HC' + HR*PR*HR' + HW*PW*HW' */

  /* PH = HJL*PJL*HJL' */
  ph4  = (cxxl*hjl12);
  ph10 = (cyyl*hjl13);
  ph16 = (siil*hjl14);

  ppaa = (hjl12*ph4) + (hjl13*ph10) + (hjl14*ph16);


  /* PH += HJR*PJR*HJR' */
  ph4  = (cxxr*hjr12);
  ph10 = (cyyr*hjr13);
  ph16 = (siir*hjr14);

  ppaa += (hjr12*ph4) + (hjr13*ph10) + (hjr14*ph16);

  /* PH += HC*PC*HC' */
  ph4  = (ccyy*hc12);
  ph10 = (ccpp*hc13);
  ph16 = (ccrr*hc14);

  ppaa += (hc12*ph4) + (hc13*ph10) + (hc14*ph16);

  /* PJ += HW*PW*HW' */
  ph4 = (sww*hw4);

  ppaa += (hw4*ph4);

  /* set pair state covariance */
  pPair->ppaa = ppaa;
}


/* ****************************************************************************
  Functionname:     HLATrackPairKalmanInitColor                     */ /*!
  Description:      initialize pair color

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanInitColor(      HLAPair_t*          pPair,
                                        const HLAKalmanMeasCol_t* pMeasLeftCol,
                                        const HLAKalmanMeasCol_t* pMeasRightCol
                                       )
{
  pPair->pc = (pMeasLeftCol->ck + pMeasRightCol->ck)*0.5f;
  pPair->pg = (pMeasLeftCol->gk + pMeasRightCol->gk)*0.5f;

  /* set chromatic part */
  pPair->ppcc = (0.25f*pMeasLeftCol->scc) + (0.25f*pMeasRightCol->scc);
  pPair->ppgg = (0.25f*pMeasLeftCol->sgg) + (0.25f*pMeasRightCol->sgg);
}


/* ****************************************************************************
  Functionname:     HLATrackPairKalmanInitWidthFree         */ /*!
  Description:      

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanInitWidthFree(      HLAPairStateWidthFree_t*      pStateWidthFree,
                                            const uint8                         doPosition,
                                            const uint8                         doIntConstant,
                                            const HLAKalmanMeas_t*              pMeasLeft,
                                            const HLAKalmanMeas_t*              pMeasRight,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                           )
{
  if(   (doPosition == 1)
     && (pStateWidthFree->isPositionUpdated == 0)
    )
  {
    /* init pair model (without width info) */
    HLATrackPairModelInitWidthFree( &pStateWidthFree->fd,
                                    &pStateWidthFree->fl,
                                    &pStateWidthFree->fh,
                                    &pStateWidthFree->fr,
                                    0,
                                    &pStateWidthFree->HJLf[0],
                                    &pStateWidthFree->HJRf[0],
                                    &pStateWidthFree->HCf[0],
                                    &(pMeasLeft->pos),
                                    &(pMeasRight->pos),
                                    &(pMeasLeft->intL),
                                    &(pMeasRight->intL),
                                    pDataRotations
                                  );

    pStateWidthFree->isPositionUpdated = 1;
  }

  if(   (doIntConstant == 1)
     && (pStateWidthFree->isIntConstantUpdated == 0)
    )
  {
    /* init pair model (without width info) */
    HLATrackPairModelInitWidthFree( 0,
                                    0,
                                    0,
                                    0,
                                    &pStateWidthFree->fa,
                                    &pStateWidthFree->HJLf[0],
                                    &pStateWidthFree->HJRf[0],
                                    &pStateWidthFree->HCf[0],
                                    &(pMeasLeft->pos),
                                    &(pMeasRight->pos),
                                    &(pMeasLeft->intL),
                                    &(pMeasRight->intL),
                                    pDataRotations
                                  );

    pStateWidthFree->isIntConstantUpdated = 1;
  }
}



/* ****************************************************************************
  Functionname:     HLATrackPairKalmanTimeUpdate                    */ /*!
  Description:      time update equation of the extended Kalman filter (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanTimeUpdate(       HLAPair_t*                          pPair,
                                          const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                          const HLATracking3DDataEgomotion_t*       pDataEgomotion
                                        )
{
  /* pair state output */
  HLAPair_t sPout;

  /* interframe time */
  float32 dt;

  /* cross-correlation between dynamic and position */ 
  float32 ppsd, ppsl;
  float32 ppyd, ppyl;

  /* cross-correlation between dynamic and structure */ 
  float32 ppsh, ppsr;
  float32 ppyh, ppyr;

  /* dynamic part */
  float32 ppss;
  float32 ppys, ppyy;

  /* jacobian */
  float32 HPS[4];

  float32 hp0, hp1;
  float32 hp2, hp3;

  if(pPair->stageTrackPair.statusTimeUpdate != HLA_TRACKSTAGE_KALMAN_INIT)
  {
    /* set flag */
    pPair->stageTrackPair.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
  }
  else
  {
    /* get cycle time */
    dt = pDataEgomotion->dt;

    /* get pair state */
    sPout = (*pPair);

    /* perform time update */
    HLATrackPairModelTimeUpdate(&sPout,
                                HPS,
                                pPair,
                                pDataEgomotion
                               );

    /* get jacobian */
    hp0 = HPS[0];     hp1 = HPS[1];
    hp2 = HPS[2];     hp3 = HPS[3];

    /* get cross-correlation between dynamic and position: PSD */ 
    ppsd = pPair->ppsd;  ppsl = pPair->ppsl;
    ppyd = pPair->ppyd;  ppyl = pPair->ppyl;

    /* get cross-correlation between dynamic and structure: PSC */ 
    ppsh = pPair->ppsh;  ppsr = pPair->ppsr;
    ppyh = pPair->ppyh;  ppyr = pPair->ppyr;

    /* get dynamic part: PS */
    ppss = pPair->ppss;
    ppys = pPair->ppys;  ppyy = pPair->ppyy;


    /* calculate PD = PD + PSD'*Hp' + HP*PSD + HP*PS*Hp' */
    sPout.ppdd += (ppsd*hp0) + (ppyd*hp1) + (hp0*ppsd) + (hp1*ppyd) + (hp0*( (ppss*hp0) + (ppys*hp1) )) + (hp1*( (ppys*hp0) + (ppyy*hp1) ));
    sPout.ppld += (ppsl*hp0) + (ppyl*hp1) + (hp2*ppsd) + (hp3*ppyd) + (hp2*( (ppss*hp0) + (ppys*hp1) )) + (hp3*( (ppys*hp0) + (ppyy*hp1) ));

    sPout.ppll += (ppsl*hp2) + (ppyl*hp3) + (hp2*ppsl) + (hp3*ppyl) + (hp2*( (ppss*hp2) + (ppys*hp3) )) + (hp3*( (ppys*hp2) + (ppyy*hp3) ));

    /* calculate PCD = PCD + PSC'*Hp' */
    sPout.pphd += (ppsh*hp0) + (ppyh*hp1);
    sPout.pprd += (ppsr*hp0) + (ppyr*hp1);

    sPout.pphl += (ppsh*hp2) + (ppyh*hp3);
    sPout.pprl += (ppsr*hp2) + (ppyr*hp3);

    /* calculate PSD = PSD + PS*Hp' */
    sPout.ppsd += (ppss*hp0) + (ppys*hp1);
    sPout.ppyd += (ppys*hp0) + (ppyy*hp1);

    sPout.ppsl += (ppss*hp2) + (ppys*hp3);
    sPout.ppyl += (ppys*hp2) + (ppyy*hp3);

    if(   (sPout.ppdd < 0)
       || (sPout.ppll < 0)
      )
    {
      /* set flag */
      pPair->stageTrackPair.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
    }
    else
    {
      /* add procees noise on speeed */
      sPout.ppss += (pDataPreComputedPair->pp_acceleration)*(dt*dt);

      /* add procees noise on yaw */
      /* ~CodeReview ~ID:77113a758954455785724062c60b714e ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO. */
      /* Godreau B, code review findings priority changed from 1 to 3 : covariance value are always positive and not null */
      if( (  (pPair->ps*pPair->ps)/( pPair->ppss + pDataPreComputedPair->pp_minspeed_foryaw ) ) > HLA_CHI2_VALUE_N1  )
      {
        sPout.ppyy += (pDataPreComputedPair->pp_yawrate)*(dt*dt);
      }

      /* add procees noise on height */
      sPout.pphh += (pDataPreComputedPair->pp_heightspeed)*(dt*dt);

      /* add procees noise on delta height */
      sPout.pprr += (pDataPreComputedPair->pp_deltaheightspeed)*(dt*dt);

      /* set output */
      (*pPair) = sPout;

      /* set flag */
      pPair->stageTrackPair.statusTimeUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;
    }
  }
}


/* ****************************************************************************
  Functionname:     HLATrackPairKalmanOneLightPredictOrUpdate        */ /*!
  Description:      measurement equation of the extended Kalman filter (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanOneLightPredictOrUpdate(      HLAPair_t*                      pPair,
                                                            HLAKalmanMeasPos_t*             pPredPos,
                                                            HLAKalmanMeasPosPixArea_t*      pPredPixArea,
                                                      const float32*                        pHP,
                                                      const float32*                        pHE,
                                                      const HLAKalmanMeasPos_t*             pMeasPos,
                                                      const HLAKalmanMeasCol_t*             pMeasCol,
                                                      const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                                      const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                                      const uint8                           inputCommand
                                                     )
{
  /* position */
  float32 pd;         /* distance */
  float32 pl;         /* lateral position */

  float32 ppdd;
  float32 ppld, ppll;

  /* structure part */
  float32 ph;         /* height */
  float32 pa;         /* light intensity constant  */
  float32 pr;         /* roll as a delta-height */

  float32 pphh;
  float32 ppaa;
  float32 pprh, pprr;

  /* dynamic part */
  float32 ps;         /* speed */
  float32 py;         /* yaw */

  float32 ppss;
  float32 ppys, ppyy;

  /* cross-correlation between structure and position */ 
  float32 pphd, pphl;
  float32 pprd, pprl;

  /* cross-correlation between dynamic and position */ 
  float32 ppsd, ppsl;
  float32 ppyd, ppyl;

  /* cross-correlation between dynamic and structure */ 
  float32 ppsh, ppsr;
  float32 ppyh, ppyr;

  /* chromaticities part */
  float32 pc;
  float32 pg;

  float32 ppcc;
  float32 ppgg;

  /* egomotion */
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* innovation */
  float32 dx;
  float32 dy;

  float32 cxx;
  float32 cyx, cyy;

  float32 sjuu;
  float32 sjvu, sjvv;

  float32 seuu;
  float32 sevu, sevv;

  /* innovation inverse */
  float32 icxx;
  float32 icyx, icyy;

  /* jacobian */
  float32 hp0, hp1, hp2, hp5, hp6;
  float32 hp7, hp8, hp9, hp12, hp13;
/*
  float32 hr0;
  float32 hr1;
*/
  float32 he0, he1, he2;
  float32 he3, he4, he5;

  /* temp values */
  float32 pjhp0,  pjhp1;
  float32 pjhp3,  pjhp4;
  float32 pjhp6,  pjhp7;
  float32 pjhp15, pjhp16;
  float32 pjhp18, pjhp19;
  float32 pjhp21, pjhp22;

/*  float32 prhr0 ,prhr1 ,prhr2;*/

  float32 pehp0, pehp1;
  float32 pehp3, pehp4;
  float32 pehp6, pehp7;

  /* kalman gain */
  float32 kj0,  kj1;
  float32 kj3,  kj4;
  float32 kj6,  kj7;
  float32 kj15, kj16;
  float32 kj18, kj19;
  float32 kj21, kj22;
  float32 kc,   kg;

/*  float32 kr0 ,kr1 ,kr2;*/

/*  float32 tr0 ,tr1 ,tr2;*/

  /* exclusion are */
  float32 delta,p;

  /* maha distance */
  /* <ln_offset:+1 PCLINT Error 793: reviewer name: Bertrand Godreau date: 09.05.2011 reason: declare more than 127 identifiers in the function to speed-up calculations */
  float32 dist;

  if(   (inputCommand == HLA_TRACK_KALMANINPUTCMD_PREDICT)
     || (inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT)
    )
  {
    /* PREDICT */
    if(   (pPair->stageTrackPair.statusPred != HLA_TRACKSTAGE_KALMAN_INIT)
       || (pPair->stageTrackPair.statusTimeUpdate != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      )
    {
      /* set flag */
      pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;

      if(inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT)
      {
        /* set flag */
        pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
      }
    }
    else
    {
      /* get state */
      pd = pPair->pd;
      pl = pPair->pl;
      ph = pPair->ph;
      pa = pPair->pa;
      pr = pPair->pr;
      ps = pPair->ps;
      py = pPair->py;

      /* get pair state covariance */
      ppdd = pPair->ppdd;
      ppld = pPair->ppld;    ppll = pPair->ppll;
      pphd = pPair->pphd;    pphl = pPair->pphl;    pphh = pPair->pphh;
     
      ppaa = pPair->ppaa;
      pprr = pPair->pprr;
      
      pprd = pPair->pprd;  pprl = pPair->pprl;  pprh = pPair->pprh;

      /* get cross-correlation between dynamic and position: PSD */ 
      ppsd = pPair->ppsd;  ppsl = pPair->ppsl;
      ppyd = pPair->ppyd;  ppyl = pPair->ppyl;

      /* get cross-correlation between dynamic and structure: PSC */ 
      ppsh = pPair->ppsh;  ppsr = pPair->ppsr;
      ppyh = pPair->ppyh;  ppyr = pPair->ppyr;

      /* get dynamic part: PS */
      ppss = pPair->ppss;
      ppys = pPair->ppys;  ppyy = pPair->ppyy;

      /* get chromaticities */
      pc = pPair->pc;
      pg = pPair->pg;

      ppcc = pPair->ppcc;
      ppgg = pPair->ppgg;

      /* get egomotion */
      eeyy = pDataEgomotion->eeyy;
      eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
      eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;


      /* get jacobians for left projection */
      hp0  = pHP[0];    hp1  = pHP[1];    hp2  = pHP[2];    hp5  = pHP[5];      hp6  = pHP[6];
      hp7  = pHP[7];    hp8  = pHP[8];    hp9  = pHP[9];    hp12 = pHP[12];     hp13 = pHP[13];
     /*
      hr0 = pHR[0];
      hr1 = pHR[1];
    */
      he0 = pHE[0];        he1 = pHE[1];          he2 = pHE[2];
      he3 = pHE[3];        he4 = pHE[4];          he5 = pHE[5];

      /* uncertainty on left projection P = HLP*PR*HLP' + HLR*PR*HLR'*/

      /* P = HLP*P*HLP' */
      pjhp0  = (ppdd*hp0)  + (ppld*hp1)  + (pphd*hp2) + (pprd*hp5)  + (ppyd*hp6);
      pjhp1  = (ppdd*hp7)  + (ppld*hp8)  + (pphd*hp9) + (pprd*hp12) + (ppyd*hp13);

      pjhp3  = (ppld*hp0)  + (ppll*hp1)  + (pphl*hp2)  + (pprl*hp5)  + (ppyl*hp6);
      pjhp4  = (ppld*hp7)  + (ppll*hp8)  + (pphl*hp9)  + (pprl*hp12) + (ppyl*hp13);

      pjhp6  = (pphd*hp0)  + (pphl*hp1)  + (pphh*hp2)  + (pprh*hp5)  + (ppyh*hp6);
      pjhp7  = (pphd*hp7)  + (pphl*hp8)  + (pphh*hp9)  + (pprh*hp12) + (ppyh*hp13);

      pjhp15 = (pprd*hp0)  + (pprl*hp1)  + (pprh*hp2)  + (pprr*hp5)  + (ppyr*hp6);
      pjhp16 = (pprd*hp7)  + (pprl*hp8)  + (pprh*hp9)  + (pprr*hp12) + (ppyr*hp13);

      pjhp18 = (ppsd*hp0)  + (ppsl*hp1)  + (ppsh*hp2)  + (ppsr*hp5)  + (ppys*hp6);
      pjhp19 = (ppsd*hp7)  + (ppsl*hp8)  + (ppsh*hp9)  + (ppsr*hp12) + (ppys*hp13);

      pjhp21 = (ppyd*hp0)  + (ppyl*hp1)  + (ppyh*hp2)  + (ppyr*hp5)  + (ppyy*hp6);
      pjhp22 = (ppyd*hp7)  + (ppyl*hp8)  + (ppyh*hp9)  + (ppyr*hp12) + (ppyy*hp13);


      sjuu = (hp0*pjhp0)  + (hp1*pjhp3)  + (hp2 *pjhp6) + (hp5 *pjhp15) + (hp6 *pjhp21);
      sjvu = (hp7*pjhp0)  + (hp8*pjhp3)  + (hp9 *pjhp6) + (hp12*pjhp15) + (hp13*pjhp21);

      sjvv = (hp7*pjhp1)  + (hp8*pjhp4)  + (hp9 *pjhp7) + (hp12*pjhp16) + (hp13*pjhp22);


      /* P += HLR*PR*HLR */
      /*prhr0 = (rrvv*hr0);
      prhr1 = (rrvv*hr1);
      prhr2 = (rrvv*hr2);

      cxx += (hr0*prhr0);
      cyx += (hr1*prhr0);
      siu += (hr2*prhr0);

      cyy += (hr1*prhr1);
      siv += (hr2*prhr1);

      sii += (hr2*prhr2);*/

      /* P += HE*PE*HE' */
      pehp0 = (eeyy * he0) + (eepy * he1) + (eery * he2);
      pehp1 = (eeyy * he3) + (eepy * he4) + (eery * he5);

      pehp3 = (eepy * he0) + (eepp * he1) + (eerp * he2);
      pehp4 = (eepy * he3) + (eepp * he4) + (eerp * he5);

      pehp6 = (eery * he0) + (eerp * he1) + (eerr * he2);
      pehp7 = (eery * he3) + (eerp * he4) + (eerr * he5);

      seuu = (he0 * pehp0) + (he1 * pehp3) + (he2 * pehp6);
      sevu = (he3 * pehp0) + (he4 * pehp3) + (he5 * pehp6);

      sevv = (he3 * pehp1) + (he4 * pehp4) + (he5 * pehp7);

      /* final innovation */
      cxx = sjuu + seuu;
      cyx = sjvu + sevu;
      cyy = sjvv + sevv;

      if(   (cxx < 0)
         || (cyy < 0)
        )
      {
        /* set flag */
        pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
      }
      else
      {
        /* set flag */
        pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

        /* set predictions */
        pPredPos->cxx = cxx;
        pPredPos->cyx = cyx;    pPredPos->cyy = cyy;
      }


      /* only prediction : calculate then exclusion area */
      if(inputCommand == HLA_TRACK_KALMANINPUTCMD_PREDICT)
      {
        if(   (pPair->stageTrackPair.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
           && (pPredPixArea != 0)
          )
        {
          /* get extreme values of egomotion */
          eeyy = pDataEgomotion->eeyy_ex;
          eepp = pDataEgomotion->eepp_ex;
          eerr = pDataEgomotion->eerr_ex;

          /* P += HE*PE*HE' */
          pehp0 = (eeyy * he0);
          pehp1 = (eeyy * he3);

          pehp3 = (eepp * he1);
          pehp4 = (eepp * he4);

          pehp6 = (eerr * he2);
          pehp7 = (eerr * he5);

          seuu = (he0 * pehp0) + (he1 * pehp3) + (he2 * pehp6);
          sevv = (he3 * pehp1) + (he4 * pehp4) + (he5 * pehp7);

          /* final innovation */
          cxx = sjuu + seuu;
          cyy = sjvv + sevv;

          if(   (cxx >= 0.0f)
             && (cyy >= 0.0f)
            )
          {
            /* width of exclusion area */
            delta = 3.0f*(pDataPreComputed->FX)*sqrtf(cxx);

            /* prediction of horizontal track pixel position */
            p = (pPredPos->x*pDataPreComputed->FX) + (pDataPreComputed->XO);
            
            /* horizontal min/max of exlusion area */
            pPredPixArea->xmin = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p - delta);
            pPredPixArea->xmax = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p + delta);

            /* height of exclusion area */
            delta = 3.0f*(pDataPreComputed->FY)*sqrtf(cyy);

            /* prediction of vertical track pixel position */
            p = (pPredPos->y*pDataPreComputed->FY) + (pDataPreComputed->YO);
            
            /* vertical min/max of exlusion area */
            pPredPixArea->ymin = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p - delta);
            pPredPixArea->ymax = (uint16) CML_f_MinMax(0.0f, (float32)UI16_T_MAX, p + delta);
          }
        }
      }


      /* KALMAN UPDATE */
      if(inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT)
      {
        if(   (pPair->stageTrackPair.statusUpdate != HLA_TRACKSTAGE_KALMAN_INIT)
           || (pMeasPos == 0)    /* should be always true when inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT */
           || (pMeasCol == 0)    /* should be always true when inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT */
           || (pPair->stageTrackPair.statusPred != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
          )
        {
          /* set flag */
          pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
        }
        else
        {
          /* add measurement noise */
          cxx += pMeasPos->cxx;
          cyx += pMeasPos->cyx;      cyy += pMeasPos->cyy;

          /* inverse innovation */
          boolean bInverseSuccess = HLATrackUtilsInverseInnovation( cxx,
                                                                    cyy,
                                                                    cyx,
                                                                    &icxx,
                                                                    &icyy,
                                                                    &icyx
                                                                  );

          if(bInverseSuccess == b_FALSE)
          {
            /* set flag */
            pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;

            /* remove association */
            pPair->bit_isAssocToRemove = 1;
          }
          else
          {
            /* calculate diff vector */
            dx = pMeasPos->x - pPredPos->x;
            dy = pMeasPos->y - pPredPos->y;

            /* calculate distance */
            dist =  dx * dx * icxx;
            dist += dy * dy * icyy;
            dist += dx * dy * (icyx + icyx);

            /* check again maha test */
            if(dist >= HLA_CHI2_VALUE_N2)
            {
              /* set flag */
              pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;

              /* remove association */
              pPair->bit_isAssocToRemove = 1;
            }
            else
            {
              /* kalman gain KJ = Temp*Sinv */
              kj0 = (pjhp0 * icxx) + (pjhp1 * icyx);
              kj1 = (pjhp0 * icyx) + (pjhp1 * icyy);

              kj3 = (pjhp3 * icxx) + (pjhp4 * icyx);
              kj4 = (pjhp3 * icyx) + (pjhp4 * icyy);

              kj6 = (pjhp6 * icxx) + (pjhp7 * icyx);
              kj7 = (pjhp6 * icyx) + (pjhp7 * icyy);

              kj15 = (pjhp15 * icxx) + (pjhp16 * icyx);
              kj16 = (pjhp15 * icyx) + (pjhp16 * icyy);

              kj18 = (pjhp18 * icxx) + (pjhp19 * icyx);
              kj19 = (pjhp18 * icyx) + (pjhp19 * icyy);

              kj21 = (pjhp21 * icxx) + (pjhp22 * icyx);
              kj22 = (pjhp21 * icyx) + (pjhp22 * icyy);

              /* state update XJ += KJ*xb */
              pd += (kj0 * dx)  + (kj1 * dy);
              pl += (kj3 * dx)  + (kj4 * dy);
              ph += (kj6 * dx)  + (kj7 * dy);
              pr += (kj15 * dx) + (kj16 * dy);
              ps += (kj18 * dx) + (kj19 * dy);
              py += (kj21 * dx) + (kj22 * dy);          

              /* state covariance update PJJ = PJJ - Temp*KJ'*/
              ppdd -= (pjhp0 * kj0)  + (pjhp1 * kj1);
              ppld -= (pjhp3 * kj0)  + (pjhp4 * kj1);
              pphd -= (pjhp6 * kj0)  + (pjhp7 * kj1);
              pprd -= (pjhp15 * kj0) + (pjhp16 * kj1);
              ppsd -= (pjhp18 * kj0) + (pjhp19 * kj1);
              ppyd -= (pjhp21 * kj0) + (pjhp22 * kj1);

              ppll -= (pjhp3 * kj3)  + (pjhp4 * kj4);
              pphl -= (pjhp6 * kj3)  + (pjhp7 * kj4);
              pprl -= (pjhp15 * kj3) + (pjhp16 * kj4);
              ppsl -= (pjhp18 * kj3) + (pjhp19 * kj4);
              ppyl -= (pjhp21 * kj3) + (pjhp22 * kj4);

              pphh -= (pjhp6 * kj6)  + (pjhp7 * kj7);
              pprh -= (pjhp15 * kj6) + (pjhp16 * kj7);
              ppsh -= (pjhp18 * kj6) + (pjhp19 * kj7);
              ppyh -= (pjhp21 * kj6) + (pjhp22 * kj7);

              pprr -= (pjhp15 * kj15) + (pjhp16 * kj16);
              ppsr -= (pjhp18 * kj15) + (pjhp19 * kj16);
              ppyr -= (pjhp21 * kj15) + (pjhp22 * kj16);

              ppss -= (pjhp18 * kj18) + (pjhp19 * kj19);
              ppys -= (pjhp21 * kj18) + (pjhp22 * kj19);

              ppyy -= (pjhp21 * kj21) + (pjhp22 * kj22);

              /* kalman gain for chromaticities */
              /* ~CodeReview ~ID:2cf0449ea50f8fd5b920f3074a988d71 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO (2x). */
              /* Godreau B, code review findings priority changed from 1 to 3 : covariance value are always positive and not null */
              kc = (ppcc)/(ppcc + pMeasCol->scc);
              kg = (ppgg)/(ppgg + pMeasCol->sgg);

              /* update chromaticities */
              pc += kc*(pMeasCol->ck - pc);
              pg += kg*(pMeasCol->gk - pg);

              /* update chromaticites covariances */
              ppcc -= (kc*kc)*(ppcc + pMeasCol->scc);
              ppgg -= (kg*kg)*(ppgg + pMeasCol->sgg);

              if(   (ppdd < 0)
                 || (ppll < 0)
                 || (pphh < 0)
                 || (ppaa < 0)
                 || (pprr < 0)
                 || (ppss < 0)
                 || (ppyy < 0)
                 || (ppcc < 0)
                 || (ppgg < 0)
                )
              {
                /* set flag */
                pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
              }
              else
              {
                /* set flag */
                pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

                /* set state */
                pPair->pd = pd;
                pPair->pl = pl;
                pPair->ph = ph;
                pPair->pa = pa;
                pPair->pr = pr;
                pPair->ps = ps;
                pPair->py = py;

                /* set pair state covariance */
                pPair->ppdd = ppdd;
                pPair->ppld = ppld;    pPair->ppll = ppll;
                pPair->pphd = pphd;    pPair->pphl = pphl;    pPair->pphh = pphh;
               
                pPair->ppaa = ppaa;
                pPair->pprr = pprr;
                
                pPair->pprd = pprd;  pPair->pprl = pprl;  pPair->pprh = pprh;

                /* set cross-correlation between dynamic and position: PSD */ 
                pPair->ppsd = ppsd;  pPair->ppsl = ppsl;
                pPair->ppyd = ppyd;  pPair->ppyl = ppyl;

                /* set cross-correlation between dynamic and structure: PSC */ 
                pPair->ppsh = ppsh;  pPair->ppsr = ppsr;
                pPair->ppyh = ppyh;  pPair->ppyr = ppyr;

                /* set dynamic part: PS */
                pPair->ppss = ppss;
                pPair->ppys = ppys;  pPair->ppyy = ppyy;


                /* set chromaticities */
                pPair->pc = pc;
                pPair->pg = pg;

                pPair->ppcc = ppcc;
                pPair->ppgg = ppgg;

                /* update relative velocity */
                pPair->relVel = pPair->ps - pDataEgomotion->ego_speed;
              }
            }
          }
        }
      }
    }
  }
}

/* ****************************************************************************
  Functionname:     HLATrackPairKalmanUpdate                             */ /*!
  Description:      pair kalman filter update with the left light or with right light

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanUpdate(       HLAPair_t*                      pPair,
                                      const HLAKalmanMeasPos_t*             pMeasPos,
                                      const HLAKalmanMeasCol_t*             pMeasCol,
                                      const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                      const HLATracking3DDataRotations_t*   pDataRotations,
                                      const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                      const float32                         pw,
                                      const uint8                           inputCommand
                                     )
{
  /* measurement equation */
  HLAKalmanMeasPos_t   predLightPos;
  /* ~CodeReview ~ID:d96eb21e2e165d1e634d5e5fe829ca97 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:120930 Magic numbers (2x). Consider centralization of these numbers. */
  float32 HP[21];
  float32 HE[9];

  if(   (inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTLEFT)
     || (inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTRIGHT)
    )
  {
    /* -----------------------------------------------------------------------------------------*/
    /* redo prediction before update since egomotion/online cali has changed */
    pPair->stageTrackPair.statusPred = HLA_TRACKSTAGE_KALMAN_INIT;

    /* reset update flag */
    pPair->stageTrackPair.statusUpdate = HLA_TRACKSTAGE_KALMAN_INIT;

    /* reset bit_isAssocToRemove */
    pPair->bit_isAssocToRemove = 0;

    /* -----------------------------------------------------------------------------------------*/
    /* measurement equation of the kalman filter */
    if(inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTLEFT)
    {
      /* reproject left light of the pair in image :  */
      HLATrackPairModelMeasurement( &(predLightPos),
                                    0,
                                    HP,
                                    HE,
                                    0,
                                    0,
                                    0,
                                    0,
                                    pPair,
                                    pDataRotations,
                                    pw
                                  );
    }
    else
    {
      /* reproject right light of the pair in image :  */
      HLATrackPairModelMeasurement( 0,
                                    0,
                                    0,
                                    0,
                                    &(predLightPos),
                                    0,
                                    HP,
                                    HE,
                                    pPair,
                                    pDataRotations,
                                    pw
                                  );
    }

    /* -----------------------------------------------------------------------------------------*/
    /* Kalman update */
    HLATrackPairKalmanOneLightPredictOrUpdate(pPair,
                                              &(predLightPos),
                                              0,
                                              HP,
                                              HE,
                                              pMeasPos,
                                              pMeasCol,
                                              pDataEgomotion,
                                              pDataPreComputed,
                                              HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHT
                                             );

    /* -----------------------------------------------------------------------------------------*/
    /* manage success/failure of tracker */
    if(inputCommand == HLA_TRACK_KALMANINPUTCMD_UPDATE_LIGHTLEFT)
    {
      /* remove association if tracked pair */
      if(   (pPair->bit_isTracked == 1)
         && (pPair->pTLeft->TrackingStatus.isPredFromPair == 1)
         && (pPair->stageTrackPair.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
         && (pPair->bit_isAssocToRemove == 1)
        )
      {
        HLATrackMeasRemoveMeasurement(pPair->pTLeft);
      }

      /* update pair tracker counter */
      if(pPair->stageTrackPair.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      {
        pPair->lost_time_left = 0;
        if(pPair->stageTrackPair.trackTimeToReinit < HLA_TRACKSTAGE_MAX_TRACK_TIME)
        {
          pPair->stageTrackPair.trackTimeToReinit++;
        }

        pPair->stageTrackPair.lostTime = 0;

        if(   (pPair->bit_isTracked == 1)
           && (pPair->pTLeft->TrackingStatus.isPredFromPair == 1)
          )
        {
          pPair->pTLeft->TrackingStatus.isAssocFromPair = 1;
        }        
      }
    }
    else
    {
      /* remove association if tracked pair */
      if(   (pPair->bit_isTracked == 1)
         && (pPair->pTRight->TrackingStatus.isPredFromPair == 1)
         && (pPair->stageTrackPair.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
         && (pPair->bit_isAssocToRemove == 1)
        )
      {
        HLATrackMeasRemoveMeasurement(pPair->pTRight);
      }

      /* update pair tracker counter */
      if(pPair->stageTrackPair.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      {
        pPair->lost_time_right = 0;
        if(pPair->stageTrackPair.trackTimeToReinit < HLA_TRACKSTAGE_MAX_TRACK_TIME)
        {
          pPair->stageTrackPair.trackTimeToReinit++;
        }

        pPair->stageTrackPair.lostTime = 0;

        if(   (pPair->bit_isTracked == 1)
           && (pPair->pTRight->TrackingStatus.isPredFromPair == 1)
          )
        {
          pPair->pTRight->TrackingStatus.isAssocFromPair = 1;
        }
      }
    }
  }
}


/* ****************************************************************************
  Functionname:     HLATrackPairKalmanDelayedUpdate                 */ /*!
  Description:      delayed update equation of the extended Kalman filter (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanDelayedUpdate(      HLAPair_t*                    pPair,
                                            const HLATracking3DDataEgomotion_t* pDataEgomotion,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                           )

{
  /* pair state output */
  HLAPair_t sPout;

  /* egomotion */
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* position : PD*/
  float32 ppdd;
  float32 ppld, ppll;
  float32 pphd, pphl, pphh;

  /* cross-correlation between structure and position : PCD*/ 
  float32 pprd, pprl, pprh;

  /* cross-correlation between dynamic and position : PSD*/ 
  float32 ppsd, ppsl, ppsh;
  float32 ppyd, ppyl, ppyh;

  /* jacobian */
  float32 HP[9];
  float32 HE[9];

  float32 he0, he1, he2;
  float32 he3, he4, he5;
  float32 he6, he7, he8;

  float32 hp0, hp1, hp2;
  float32 hp3, hp4, hp5;
  float32 hp6, hp7, hp8;

  /* temp values */
  float32 ph0, ph1, ph2;
  float32 ph3, ph4, ph5;
  float32 ph6, ph7, ph8;

  if(   (pPair->stageTrackPair.statusDelayedUpdate != HLA_TRACKSTAGE_KALMAN_INIT)
     || (pPair->stageTrackPair.statusTimeUpdate != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
    )
  {
    /* set flag */
    pPair->stageTrackPair.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
  }
  else
  {
    /* get pair state */
    sPout = (*pPair);

    /* get egomotion */
    eeyy = pDataEgomotion->eeyy;
    eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
    eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;

    /* get position : PD*/
    ppdd = pPair->ppdd;
    ppld = pPair->ppld;    ppll = pPair->ppll;
    pphd = pPair->pphd;    pphl = pPair->pphl;    pphh = pPair->pphh;

    /* get cross-correlation between structure and position : PCD*/ 
    pprd = pPair->pprd;  pprl = pPair->pprl;  pprh = pPair->pprh;
   
    /* get cross-correlation between dynamic and position: PSD */ 
    ppsd = pPair->ppsd;  ppsl = pPair->ppsl;    ppsh = pPair->ppsh;
    ppyd = pPair->ppyd;  ppyl = pPair->ppyl;    ppyh = pPair->ppyh;


    /* perform time update */
    HLATrackPairModelMapUpdate( &sPout,
                                HP,
                                HE,
                                pPair,
                                pDataRotations,
                                pDataEgomotion
                              );

    /* get jacobian */
    he0 = HE[0];              he1 = HE[1];          he2 = HE[2];
    he3 = HE[3];              he4 = HE[4];          he5 = HE[5];
    he6 = HE[6];              he7 = HE[7];          he8 = HE[8];

    hp0 = HP[0];              hp1 = HP[1];          hp2 = HP[2];
    hp3 = HP[3];              hp4 = HP[4];          hp5 = HP[5];
    hp6 = HP[6];              hp7 = HP[7];          hp8 = HP[8];


    /* PCD = PCD*Hp' */
    /* PSD = PSD*Hp' */
    sPout.pprd = (pprd*hp0) + (pprl*hp1) + (pprh*hp2);
    sPout.ppsd = (ppsd*hp0) + (ppsl*hp1) + (ppsh*hp2);
    sPout.ppyd = (ppyd*hp0) + (ppyl*hp1) + (ppyh*hp2);

    sPout.pprl = (pprd*hp3) + (pprl*hp4) + (pprh*hp5);
    sPout.ppsl = (ppsd*hp3) + (ppsl*hp4) + (ppsh*hp5);
    sPout.ppyl = (ppyd*hp3) + (ppyl*hp4) + (ppyh*hp5);

    sPout.pprh = (pprd*hp6) + (pprl*hp7) + (pprh*hp8);
    sPout.ppsh = (ppsd*hp6) + (ppsl*hp7) + (ppsh*hp8);
    sPout.ppyh = (ppyd*hp6) + (ppyl*hp7) + (ppyh*hp8);

    /* PD = HP*PD*Hp' */
    ph0 = (ppdd*hp0) + (ppld*hp1) + (pphd*hp2);
    ph1 = (ppdd*hp3) + (ppld*hp4) + (pphd*hp5);
    ph2 = (ppdd*hp6) + (ppld*hp7) + (pphd*hp8);

    ph3 = (ppld*hp0) + (ppll*hp1) + (pphl*hp2);
    ph4 = (ppld*hp3) + (ppll*hp4) + (pphl*hp5);
    ph5 = (ppld*hp6) + (ppll*hp7) + (pphl*hp8);

    ph6 = (pphd*hp0) + (pphl*hp1) + (pphh*hp2);
    ph7 = (pphd*hp3) + (pphl*hp4) + (pphh*hp5);
    ph8 = (pphd*hp6) + (pphl*hp7) + (pphh*hp8);


    sPout.ppdd = (hp0*ph0) + (hp1*ph3) + (hp2*ph6);
    sPout.ppld = (hp3*ph0) + (hp4*ph3) + (hp5*ph6);
    sPout.pphd = (hp6*ph0) + (hp7*ph3) + (hp8*ph6);

    sPout.ppll = (hp3*ph1) + (hp4*ph4) + (hp5*ph7);
    sPout.pphl = (hp6*ph1) + (hp7*ph4) + (hp8*ph7);

    sPout.pphh = (hp6*ph2) + (hp7*ph5) + (hp8*ph8);


    /* add egomotion uncertainty */
    ph0 = (eeyy * he0) + (eepy * he1) + (eery * he2);
    ph1 = (eeyy * he3) + (eepy * he4) + (eery * he5);
    ph2 = (eeyy * he6) + (eepy * he7) + (eery * he8);

    ph3 = (eepy * he0) + (eepp * he1) + (eerp * he2);
    ph4 = (eepy * he3) + (eepp * he4) + (eerp * he5);
    ph5 = (eepy * he6) + (eepp * he7) + (eerp * he8);

    ph6 = (eery * he0) + (eerp * he1) + (eerr * he2);
    ph7 = (eery * he3) + (eerp * he4) + (eerr * he5);
    ph8 = (eery * he6) + (eerp * he7) + (eerr * he8);

    sPout.ppdd += (he0*ph0) + (he1*ph3) + (he2*ph6);
    sPout.ppld += (he3*ph0) + (he4*ph3) + (he5*ph6);
    sPout.pphd += (he6*ph0) + (he7*ph3) + (he8*ph6);

    sPout.ppll += (he3*ph1) + (he4*ph4) + (he5*ph7);
    sPout.pphl += (he6*ph1) + (he7*ph4) + (he8*ph7);

    sPout.pphh += (he6*ph2) + (he7*ph5) + (he8*ph8);

    /* PSD += HSE*PE*HE' */
    sPout.ppyd +=  -ph0;
    sPout.ppyl +=  -ph1;
    sPout.ppyh +=  -ph2;

    /* PS += HSE*PE*HSE' */
    sPout.ppyy += eeyy;

    if(   (sPout.ppdd < 0)
       || (sPout.ppll < 0)
       || (sPout.pphh < 0)
      )
    {
      /* set flag */
      pPair->stageTrackPair.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_FAIL;
    }
    else
    {
      /* set output */
      (*pPair) = sPout;

      /* set flag */
      pPair->stageTrackPair.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;
    }
  }
}


/* ****************************************************************************
  Functionname:     HLATrackPairKalmanReprojectOneLight         */ /*!  
  Description:      measurement equation of the extended Kalman filter (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanReprojectOneLight(      HLAKalmanMeasPos_t* pRepjPos,
                                                      HLAKalmanMeasInt_t* pRepjInt,
                                                      HLAKalmanMeasCol_t* pRepjCol,
                                                const HLAPair_t*          pPair,
                                                const float32*            pHP
                                               )
{
  /* position */
  float32 ppdd;
  float32 ppld, ppll;

  /* structure part */
  float32 pphh;
  float32 ppaa;
  float32 pprh, pprr;

  /* cross-correlation between structure and position */ 
  float32 pphd, pphl;
  float32 pprd, pprl;

  /* measurement */
  float32 cxx;
  float32 cyx, cyy;
  float32 sii;

  /* jacobian */
  float32 hp0,  hp1,  hp2,  hp5;
  float32 hp6,  hp7,  hp8,  hp11;
  float32 hp12, hp13, hp14, hp16, hp17;

  /* temp values */
  float32 pjhp0,  pjhp1,  pjhp2;
  float32 pjhp3,  pjhp4,  pjhp5;
  float32 pjhp6,  pjhp7,  pjhp8;
  float32 pjhp14;
  float32 pjhp15, pjhp16, pjhp17;

  /* get pair state covariance */
  ppdd = pPair->ppdd;
  ppld = pPair->ppld;    ppll = pPair->ppll;
  pphd = pPair->pphd;    pphl = pPair->pphl;    pphh = pPair->pphh;
  pprd = pPair->pprd;    pprl = pPair->pprl;    pprh = pPair->pprh;      pprr = pPair->pprr;
 
  ppaa = pPair->ppaa;
  
  /* get jacobians for left projection */
  hp0  = pHP[0];    hp1  = pHP[1];    hp2  = pHP[2];                          hp5  = pHP[5];
  hp6  = pHP[6];    hp7  = pHP[7];    hp8  = pHP[8];                          hp11 = pHP[11];
  hp12 = pHP[12];   hp13 = pHP[13];   hp14 = pHP[14];   hp16 = pHP[16];       hp17 = pHP[17];
 
  /* uncertainty on left projection P = HLP*PR*HLP' + HLR*PR*HLR'*/

  /* P = HLP*P*HLP' */
  pjhp0  = (ppdd*hp0)  + (ppld*hp1)  + (pphd*hp2)  + (pprd*hp5);
  pjhp1  = (ppdd*hp6)  + (ppld*hp7)  + (pphd*hp8)  + (pprd*hp11);
  pjhp2  = (ppdd*hp12) + (ppld*hp13) + (pphd*hp14) + (pprd*hp17);

  pjhp3  = (ppld*hp0)  + (ppll*hp1)  + (pphl*hp2)  + (pprl*hp5);
  pjhp4  = (ppld*hp6)  + (ppll*hp7)  + (pphl*hp8)  + (pprl*hp11);
  pjhp5  = (ppld*hp12) + (ppll*hp13) + (pphl*hp14) + (pprl*hp17);

  pjhp6  = (pphd*hp0)  + (pphl*hp1)  + (pphh*hp2)  + (pprh*hp5);
  pjhp7  = (pphd*hp6)  + (pphl*hp7)  + (pphh*hp8)  + (pprh*hp11);
  pjhp8  = (pphd*hp12) + (pphl*hp13) + (pphh*hp14) + (pprh*hp17);

  pjhp14 = (ppaa*hp16);

  pjhp15 = (pprd*hp0)  + (pprl*hp1)  + (pprh*hp2)  + (pprr*hp5);
  pjhp16 = (pprd*hp6)  + (pprl*hp7)  + (pprh*hp8)  + (pprr*hp11);
  pjhp17 = (pprd*hp12) + (pprl*hp13) + (pprh*hp14) + (pprr*hp17);


  cxx = (hp0*pjhp0)  + (hp1*pjhp3)  + (hp2 *pjhp6)                 + (hp5 *pjhp15);
  cyx = (hp6*pjhp0)  + (hp7*pjhp3)  + (hp8 *pjhp6)                 + (hp11*pjhp15);

  cyy = (hp6*pjhp1)  + (hp7*pjhp4)  + (hp8 *pjhp7)                 + (hp11*pjhp16);

  sii = (hp12*pjhp2) + (hp13*pjhp5) + (hp14*pjhp8) + (hp16*pjhp14) + (hp17*pjhp17);


  /* P = HLR*PR*HLR */
  /*
  prhr0 = (rrvv*hr0);
  prhr1 = (rrvv*hr1);
  prhr2 = (rrvv*hr2);

  cxx += (hr0*prhr0);
  cyx += (hr1*prhr0);

  cyy += (hr1*prhr1);

  sii += (hr2*prhr2);
  */

  /* set measurment uncertainty */
  pRepjPos->cxx = cxx;
  pRepjPos->cyx = cyx;    pRepjPos->cyy = cyy;

  pRepjInt->sii = sii;

  pRepjCol->ck = pPair->pc;
  pRepjCol->gk = pPair->pg;

  pRepjCol->scc = pPair->ppcc;
  pRepjCol->sgg = pPair->ppgg;
}

/* ***********************************************************************/ /*!
  Functionname:     HLATrackPairKalmanReprojection
  Description:      measurement equation of the extended Kalman filter (pair tracker)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairKalmanReprojection(       HLAKalmanMeas_t*                    pRepjLeft,
                                                  HLAKalmanMeas_t*                    pRepjRight,
                                                  HLAPairTTBInput*                    pTTBIn,
                                            const HLAPair_t*                          pPair,
                                            const HLATracking3DDataRotations_t*       pDataRotations,
                                            const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                          )
{
  /* jacobian */
  float32 HLP[18];
  float32 HRP[18];

  /* reproject pair in image */
  HLATrackPairModelReprojection(&(pRepjLeft->pos),
                                &(pRepjLeft->intL),
                                &(pRepjRight->pos),
                                &(pRepjRight->intL),
                                HLP, 
                                HRP, 
                                pTTBIn,
                                pPair,
                                pDataRotations,
                                pDataPreComputedPair->pw
                               );

  /* get innovation matrix for left measurement */
  HLATrackPairKalmanReprojectOneLight(&(pRepjLeft->pos),
                                      &(pRepjLeft->intL),
                                      &(pRepjLeft->col),
                                      pPair,
                                      HLP
                                     );

  /* get innovation matrix for right measurement */
  HLATrackPairKalmanReprojectOneLight(&(pRepjRight->pos),
                                      &(pRepjRight->intL),
                                      &(pRepjRight->col),
                                      pPair,
                                      HRP
                                     );
}


/* ***********************************************************************/ /*! 
  @fn            HLATrackPairGetRMSEOneLight

  @brief         reproject pair and get confidence

  @description   RMSE = ReprojectionErrorOneMeas

  @return         

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackPairGetRMSEOneLight(      float32*            pdist,
                                        const HLAKalmanMeasPos_t* pRepjPos,
                                        const HLAKalmanMeasInt_t* pRepjInt,
                                        const HLAKalmanMeasCol_t* pRepjCol,
                                        const HLAKalmanMeasPos_t* pMeasPos,
                                        const HLAKalmanMeasInt_t* pMeasInt,
                                        const HLAKalmanMeasCol_t* pMeasCol
                                       )
{
  /* mahalanobis distance */
  float32 dist, disti, distc, distg;

  /* set default value of reprojection error */
  *pdist = HLA_CHI2_VALUE_N3;

  /* test 2D reprojection */
  HLATrackUtilsMaha22(&dist,
                      pRepjPos->x - pMeasPos->x,
                      pRepjPos->y - pMeasPos->y,
                      pRepjPos->cxx + pMeasPos->cxx,
                      pRepjPos->cyy + pMeasPos->cyy,
                      pRepjPos->cyx + pMeasPos->cyx
                     );

  if(   (dist >= 0)
     && (dist < HLA_CHI2_VALUE_N2)
    )
  {
    /* test intensity reprojection */
    HLATrackUtilsMaha11(&disti,
                        pRepjInt->ik  - pMeasInt->ik, 
                        pRepjInt->sii + pMeasInt->sii
                       );

    if(   (disti >= 0)
       && (disti < HLA_CHI2_VALUE_N1)
      )
    {
      /* test red reprojection */
      HLATrackUtilsMaha11(&distc,
                          pRepjCol->ck  - pMeasCol->ck, 
                          pRepjCol->scc + pMeasCol->scc
                         );

      if(   (distc >= 0)
         && (distc < HLA_CHI2_VALUE_N1)
        )
      {
        /* test green reprojection */
        HLATrackUtilsMaha11(&distg,
                            pRepjCol->gk  - pMeasCol->gk,
                            pRepjCol->sgg + pMeasCol->sgg
                           );

        if(   (distg >= 0)
           && (distg < HLA_CHI2_VALUE_N1)
          )
        {
          /* 2D+intensity reprojection */
          HLATrackUtilsMaha33(pdist,
                              pRepjPos->x  - pMeasPos->x,
                              pRepjPos->y  - pMeasPos->y,
                              pRepjInt->ik  - pMeasInt->ik,
                              pRepjPos->cxx + pMeasPos->cxx,
                              pRepjPos->cyx + pMeasPos->cyx,
                              0.0f,
                              pRepjPos->cyy + pMeasPos->cyy,
                              0.0f,
                              pRepjInt->sii + pMeasInt->sii
                             );
        }
      }
    }
  }
}


/* ***********************************************************************/ /*!
  @fn            HLATrackPairReprojectAndGetConfidence


  @brief         reproject pair and get confidence

  @description   --

  @return         

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackPairReprojectAndGetConfidence(      float32*                            pdist_left,
                                                        float32*                            pdist_right,
                                                        HLAKalmanMeas_t*                    pRepjLeft,
                                                        HLAKalmanMeas_t*                    pRepjRight,
                                                        HLAPairTTBInput*                    pTTBIn,
                                                  const HLAPair_t*                          pPair,
                                                  const HLAKalmanMeas_t*                    pMeasLeft,
                                                  const HLAKalmanMeas_t*                    pMeasRight,
                                                  const HLATracking3DDataRotations_t*       pDataRotations,
                                                  const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair
                                                 )
{
  /* reproject pair model state in image */
  HLATrackPairKalmanReprojection( pRepjLeft,
                                  pRepjRight,
                                  pTTBIn,
                                  pPair,
                                  pDataRotations,
                                  pDataPreComputedPair
                                );

  /* left reprojection error */
  if(pMeasLeft != 0)
  {
    HLATrackPairGetRMSEOneLight(pdist_left,
                                &(pRepjLeft->pos),
                                &(pRepjLeft->intL),
                                &(pRepjLeft->col),
                                &(pMeasLeft->pos),
                                &(pMeasLeft->intL),
                                &(pMeasLeft->col)
                               );
  }
  else
  {
    *pdist_left = HLA_CHI2_VALUE_N3;
  }

  /* right reprojection error */
  if(pMeasRight != 0)
  {
    HLATrackPairGetRMSEOneLight(pdist_right,
                                &(pRepjRight->pos),
                                &(pRepjRight->intL),
                                &(pRepjRight->col),
                                &(pMeasRight->pos),
                                &(pMeasRight->intL),
                                &(pMeasRight->col)
                               );
  }
  else
  {
    *pdist_right = HLA_CHI2_VALUE_N3;
  }
}


/* ***********************************************************************/ /*! 
  @fn            HLATrackPairIsANewPair


  @brief         check if pair is a new pair

  @description   --

  @return         

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackPairIsANewPair(       HLAPair_t*                            pPair,
                                          float32*                              pdist,
                                          HLAPairStateWidthFree_t*              pStateWidthFree,
                                    const HLATrack_t*                           pTLeft,
                                    const HLATrack_t*                           pTRight,
                                    const HLATracking3DDataRotations_t*         pDataRotations,
                                    const HLATracking3DDataPreComputedPair_t*   pDataPreComputedPair,
                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                  )
{

  /* mahalanobis distance */
  float32 dist, dista, distr, distc, distg, distleft, distright;

  /* measurement */
  HLAKalmanMeas_t   measLeft;
  HLAKalmanMeas_t   measRight;

  /* reprojection */
  HLAKalmanMeas_t   repjLeft;
  HLAKalmanMeas_t   repjRight;

  /* max position error */
  float32 maxerr;
  float32 maxcxx;

  maxerr = (float32)(pTRight->xcenter - pTLeft->xcenter);
  maxcxx = (maxerr*maxerr)*pDataPreComputed->factorMaxCxx;

  /* init returned distance */
  if(pdist != NULL)
  {
    *pdist = HLA_CHI2_VALUE_N6;
  }

  /* get pair measurement for left light */
  HLATrackMeasGetKalmanMeas(&measLeft,
                            pTLeft->light_ref,
                            pDataPreComputed,
                            pParamMeas,
                            pDataPreComputedPair
                           );
  
  measLeft.pos.cxx = pDataPreComputedPair->cxx;
  measLeft.pos.cyy = pDataPreComputedPair->cyy;

  if(measLeft.pos.cxx > maxcxx)
  {
    measLeft.pos.cxx = maxcxx;
    measLeft.pos.cyy = maxcxx;
  }
  
  /* get pair measurement for right light */
  HLATrackMeasGetKalmanMeas(&measRight,
                            pTRight->light_ref,
                            pDataPreComputed,
                            pParamMeas,
                            pDataPreComputedPair
                           );

  measRight.pos.cxx = pDataPreComputedPair->cxx;
  measRight.pos.cyy = pDataPreComputedPair->cyy;

  if(measRight.pos.cxx > maxcxx)
  {
    measRight.pos.cxx = maxcxx;
    measRight.pos.cyy = maxcxx;
  }

  /* initialize color */
  HLATrackPairKalmanInitColor(pPair,
                              &(measLeft.col),
                              &(measRight.col)
                             );

  /* check color */
  distc = 0;
  distg = 0;
  if(pdist != NULL)
  {
    /* check color */
    HLATrackUtilsMaha11(&distc,
                        pPair->pc  - pDataPreComputedPair->pc,
                        pPair->ppcc  + pDataPreComputedPair->ppcc
                       );

    HLATrackUtilsMaha11(&distg,
                        pPair->pg  - pDataPreComputedPair->pg,
                        pPair->ppgg  + pDataPreComputedPair->ppgg
                       );
  }

  if(   (distc >= 0)
     && (distc < HLA_CHI2_VALUE_N1)
     && (distg >= 0)
     && (distg < HLA_CHI2_VALUE_N1)
   )
  {
    /* update position part of the width-free pair state */
    HLATrackPairKalmanInitWidthFree(pStateWidthFree,
                                    1,
                                    0,
                                    &measLeft,
                                    &measRight,
                                    pDataRotations
                                   );

    /* initialize pair state from pair measurement */
    HLATrackPairKalmanInitPosition(pPair,
                                   pStateWidthFree,
                                   &(measLeft.pos),
                                   &(measRight.pos),
                                   pDataRotations,
                                   0,
                                   pDataPreComputedPair
                                  );

    dist = 0;
    distr = 0;
    if(pdist != NULL)
    {
      /* check height and distance are correct */
      HLATrackUtilsMaha22(&dist,
                          pPair->pd - pDataPreComputedPair->pdStart,
                          pPair->ph - pDataPreComputedPair->ph,
                          pPair->ppdd + pDataPreComputedPair->ppddStart,
                          pPair->pphh + pDataPreComputedPair->pphh,
                          pPair->pphd
                         );

      /* check roll */
      HLATrackUtilsMaha11(&distr,
                          pPair->pr  - pDataPreComputedPair->pr,
                          pPair->pprr  + pDataPreComputedPair->pprrStart
                         );
    }

    if(   (dist >= 0)
       && (dist < HLA_CHI2_VALUE_N2)
       && (distr >= 0)
       && (distr < HLA_CHI2_VALUE_N1)
      )
    {
      /* update position part of the width-free pair state */
      HLATrackPairKalmanInitWidthFree(pStateWidthFree,
                                      0,
                                      1,
                                      &measLeft,
                                      &measRight,
                                      pDataRotations
                                     );

      /* init pair intensity constant */
      HLATrackPairKalmanInitIntensityConstant(pPair,
                                              pStateWidthFree,
                                              &(measLeft.pos),
                                              &(measRight.pos),
                                              &(measLeft.intL),
                                              &(measRight.intL),
                                              0,
                                              pDataPreComputedPair
                                             );

      /* initialize pair counter */
      pPair->stageTrackPair.trackTimeToReinit = 1;
      pPair->stageTrackPair.traceTimeToReinit = 1;
      pPair->stageTrackPair.lostTime = 0;

      /* check luminosity constant is correct */
      dista = 0;
      if(pdist != NULL)
      {

        HLATrackUtilsMaha11(&dista,
                            pPair->pa  - pDataPreComputedPair->pa,
                            pPair->ppaa  + pDataPreComputedPair->ppaa
                           );

        if(   (dista >= 0)
           && (dista < HLA_CHI2_VALUE_N1)
          )
        {
          /* reproject */
          HLATrackPairReprojectAndGetConfidence(&distleft,
                                                &distright,
                                                &repjLeft,
                                                &repjRight,
                                                0,
                                                pPair,
                                                &measLeft,
                                                &measRight,
                                                pDataRotations,
                                                pDataPreComputedPair
                                               );

          if(   (distleft >= 0)
             && (distleft < HLA_CHI2_VALUE_N3)
             && (distright >= 0)
             && (distright < HLA_CHI2_VALUE_N3)
            )
          {
            *pdist = distleft + distright;
          }
        }
      }
    }
  }
}


/* ***********************************************************************/ /*!
  Functionname:     HLATrackPairModelPredRightFromLeftPre
  Description:      
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairModelPredRightFromLeftPre(      float32*                            pdx_p,
                                                        float32*                            pdy_p,
                                                        float32*                            pccdxx_p,
                                                        float32*                            pccdyy_p,
                                                  const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                                  const HLATracking3DDataRotations_t*       pDataRotations
                                                 )
{
  /* scale */
  float32 factor, dfactor_dsd;
  float32 cdd;

  /* pair width */
  float32 w;
  float32 sww;

  /* get roll as delta height */
  float32 r;
  float32 crr;

  /* temp values */
  float32 du;
  float32 dv;

  /* on line cali rotation matriw */
  float32 rk01, rk02;
  float32 rk11, rk12;

  /* jacobian */
  float32 husd;
  float32 hvsd;
  float32 huw;
  float32 hvw;
  float32 hur;
  float32 hvr;

  /*-------------------------------------------------------------*/
  /* get scale */
  factor = pDataPreComputedPair->dwStart;
  dfactor_dsd = 1;
  cdd = pDataPreComputedPair->cddStart;

  /* get pair width */
  w = pDataPreComputedPair->pw;
  sww = pDataPreComputedPair->ppww;

  /* get roll as delta height */
  r = pDataPreComputedPair->pr;
  crr = pDataPreComputedPair->pprrStart;

  /* get on line cali rotation matriw */
  rk01 = pDataRotations->RK[1];     rk02 = pDataRotations->RK[2];
  rk11 = pDataRotations->RK[4];     rk12 = pDataRotations->RK[5];

  /*----------------------------------------------------------------*/
  /* predict position */
  du = (rk01*(-w)) + (rk02*(-2*r));
  dv = (rk11*(-w)) + (rk12*(-2*r));

  *pdx_p = (du*factor);
  *pdy_p = (dv*factor);

  /*----------------------------------------------------------------*/
  /* right prediction jacobian along sd and w*/
  husd = du*dfactor_dsd;
  hvsd = dv*dfactor_dsd;

  huw = - rk01*factor;
  hvw = - rk11*factor;

  hur = - 2*rk02*factor;
  hvr = - 2*rk12*factor;

  /*----------------------------------------------------------------*/
  /* left covariance matrix */
  *pccdxx_p = ((husd*husd)*cdd) + ((huw*huw)*sww) + ((hur*hur)*crr);
  *pccdyy_p = ((hvsd*hvsd)*cdd) + ((hvw*hvw)*sww) + ((hvr*hvr)*crr);
}


/* **************************************************************************** 
  Functionname:     HLATrackPairModelInitWidthFree                 */ /*!  
  Description:      

                    

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairModelInitWidthFree(       float32*                      pfd,
                                                  float32*                      pfl,
                                                  float32*                      pfh,
                                                  float32*                      pfr,
                                                  float32*                      pfi,
                                                  float32*                      pHJL,
                                                  float32*                      pHJR,
                                                  float32*                      pHC,
                                            const HLAKalmanMeasPos_t*           pMeasLeftPos,
                                            const HLAKalmanMeasPos_t*           pMeasRightPos,
                                            const HLAKalmanMeasInt_t*           pMeasLeftInt,
                                            const HLAKalmanMeasInt_t*           pMeasRightInt,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                          )
{

  const float32* RK;
  const float32* dRK_dcy;
  const float32* dRK_dcp;
  const float32* dRK_dcr;
  float32 rk00, rk01, rk02, rk10, rk11, rk12,rk20, rk21, rk22;

  /* pair mesurement */
  float32 xl;
  float32 yl;
  float32 ikl;
  float32 xr;
  float32 yr;
  float32 ikr;
  
  /* pre process */
  float32 muk, mvk, duk, dvk, rkl, rkr;
  float32 fm;

  float32 kw;
  float32 ikw, ikw2;
  float32 dkwul;
  float32 dkwvl;
  float32 dkwur;
  float32 dkwvr;
  float32 dkwcy;
  float32 dkwcp;
  float32 dkwcr;

  float32 k;
  float32 dk;
  float32 h;

  /* get world to cam transform */
  RK = &pDataRotations->RK[0];
  rk00 = RK[0];       rk01 = RK[1];   rk02 = RK[2];
  rk10 = RK[3];       rk11 = RK[4];   rk12 = RK[5];
  rk20 = RK[6];       rk21 = RK[7];   rk22 = RK[8];

  /* get measurement */
  xl = pMeasLeftPos->x;
  yl = pMeasLeftPos->y;
  ikl = pMeasLeftInt->ik;

  xr = pMeasRightPos->x;
  yr = pMeasRightPos->y;
  ikr = pMeasRightInt->ik;

  /* get kw factor */
  duk = (xl-xr);
  dvk = (yl-yr);

  kw = (rk01*duk) + (rk11*dvk);
  /* ~CodeReview ~ID:f2e54d7616bb42460543a3105f7ba7f8 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO. */
  /* Godreau B, code review findings priority changed from 1 to 3 : value can not be zero */
  ikw = 1/kw;

  /* get world to cam transform jacobians */
  dRK_dcy = &pDataRotations->dRK_dcy[0];
  dRK_dcp = &pDataRotations->dRK_dcp[0];
  dRK_dcr = &pDataRotations->dRK_dcr[0];

  /* derivate along xl */
  dkwul = rk01;

  /* derivate along yl */
  dkwvl = rk11;

  /* derivate along xr */
  dkwur = -rk01;

  /* derivate along yr */
  dkwvr = -rk11;
  
  /* derivate along cal_yaw */
  dkwcy = (dRK_dcy[1]*duk) + (dRK_dcy[4]*dvk);
  
  /* derivate along cal_pitch */
  dkwcp = (dRK_dcp[1]*duk) + (dRK_dcp[4]*dvk);

  /* derivate along cal_roll */
  dkwcr = (dRK_dcr[1]*duk) + (dRK_dcr[4]*dvk);

  /* calculate camera-centered image world coordinates */
  muk = 0.5f*(xl+xr);
  mvk = 0.5f*(yl+yr);

  /* calculate with free pair parameters : distance*/
  if(pfd != NULL)
  {
    k = (rk00*muk) + (rk10*mvk) + rk20;
    *pfd = ikw*k;

    /* jacobian */
    if(   (pHJL != 0)
       && (pHJR != 0)
       && (pHC != 0)
      )
    {
      /* temp values for jacobian calculations */
      h = - (ikw*(*pfd));

      /* derivate along xl */
      dk = rk00*0.5f;
      pHJL[0]  = (h*dkwul) + (ikw*dk);

      /* derivate along yl */
      dk = rk10*0.5f;
      pHJL[1]  = (h*dkwvl) + (ikw*dk);

      /* derivate along ikl */
      pHJL[2]  = 0;

      /* derivate along xr */
      dk = rk00*0.5f;
      pHJR[0]  = (h*dkwur) + (ikw*dk);

      /* derivate along yr */
      dk = rk10*0.5f;
      pHJR[1]  = (h*dkwvr) + (ikw*dk);

      /* derivate along ikr */
      pHJR[2]  = 0;

      /* derivate along cal_yaw */
      dk = (dRK_dcy[0]*muk) + (dRK_dcy[3]*mvk) + dRK_dcy[6];
      pHC[0]  = (h*dkwcy) + (ikw*dk);
      
      /* derivate along cal_pitch */
      dk = (dRK_dcp[0]*muk) + (dRK_dcp[3]*mvk) + dRK_dcp[6];
      pHC[1]  = (h*dkwcp) + (ikw*dk);

      /* derivate along cal_roll */
      dk = (dRK_dcr[0]*muk) + (dRK_dcr[3]*mvk) + dRK_dcr[6];
      pHC[2]  = (h*dkwcr) + (ikw*dk);
    }
  }

  /* calculate with free pair parameters : lateral distance*/
  if(pfl != NULL)
  {
    k = (rk01*muk) + (rk11*mvk) + rk21;
    *pfl = ikw*k;

    /* jacobian */
    if(   (pHJL != 0)
       && (pHJR != 0)
       && (pHC != 0)
      )
    {
      /* temp values for jacobian calculations */
      h = - (ikw*(*pfl));

      /* derivate along xl */
      dk = rk01*0.5f;
      pHJL[3]  = (h*dkwul) + (ikw*dk);

      /* derivate along yl */
      dk = rk11*0.5f;
      pHJL[4]  = (h*dkwvl) + (ikw*dk);

      /* derivate along ikl */
      pHJL[5] = 0;

      /* derivate along xr */
      dk = rk01*0.5f;
      pHJR[3]  = (h*dkwur) + (ikw*dk);

      /* derivate along yr */
      dk = rk11*0.5f;
      pHJR[4]  = (h*dkwvr) + (ikw*dk);

      /* derivate along ikr */
      pHJR[5] = 0;

      /* derivate along cal_yaw */
      dk = (dRK_dcy[1]*muk) + (dRK_dcy[4]*mvk) + dRK_dcy[7];
      pHC[3]  = (h*dkwcy) + (ikw*dk);
      
      /* derivate along cal_pitch */
      dk = (dRK_dcp[1]*muk) + (dRK_dcp[4]*mvk) + dRK_dcp[7];
      pHC[4]  = (h*dkwcp) + (ikw*dk);

      /* derivate along cal_roll */
      dk = (dRK_dcr[1]*muk) + (dRK_dcr[4]*mvk) + dRK_dcr[7];
      pHC[5]  = (h*dkwcr) + (ikw*dk);
    }
  }

  if(pfh != NULL)
  {
    k = (rk02*muk) + (rk12*mvk) + rk22;
    *pfh = ikw*k;

    /* jacobian */
    if(   (pHJL != 0)
       && (pHJR != 0)
       && (pHC != 0)
      )
    {
      /* temp values for jacobian calculations */
      h = - (ikw*(*pfh));

      /* derivate along xl */
      dk = rk02*0.5f;
      pHJL[6]  = (h*dkwul) + (ikw*dk);

      /* derivate along yl */
      dk = rk12*0.5f;
      pHJL[7]  = (h*dkwvl) + (ikw*dk);

      /* derivate along ikl */
      pHJL[8] = 0;

      /* derivate along xr */
      dk = rk02*0.5f;
      pHJR[6]  = (h*dkwur) + (ikw*dk);

      /* derivate along yr */
      dk = rk12*0.5f;
      pHJR[7]  = (h*dkwvr) + (ikw*dk);

      /* derivate along ikr */
      pHJR[8] = 0;

      /* derivate along cal_yaw */
      dk = (dRK_dcy[2]*muk) + (dRK_dcy[5]*mvk) + dRK_dcy[8];
      pHC[6]  = (h*dkwcy) + (ikw*dk);
      
      /* derivate along cal_pitch */
      dk = (dRK_dcp[2]*muk) + (dRK_dcp[5]*mvk) + dRK_dcp[8];
      pHC[7]  = (h*dkwcp) + (ikw*dk);

      /* derivate along cal_roll */
      dk = (dRK_dcr[2]*muk) + (dRK_dcr[5]*mvk) + dRK_dcr[8];
      pHC[8]  = (h*dkwcr) + (ikw*dk);
    }
  }

  if(pfr != NULL)
  {
    k = (rk02*duk) + (rk12*dvk);
    *pfr = ikw*k;

    /* jacobian */
    if(   (pHJL != 0)
       && (pHJR != 0)
       && (pHC != 0)
      )
    {
      /* temp values for jacobian calculations */
      h = - (ikw*(*pfr));

      /* derivate along xl */
      dk = rk02;
      pHJL[15] = (h*dkwul) + (ikw*dk);

      /* derivate along yl */
      dk = rk12;
      pHJL[16] = (h*dkwvl) + (ikw*dk);

      /* derivate along ikl */
      pHJL[17] = 0;

      /* derivate along xr */
      dk = -rk02;
      pHJR[15] = (h*dkwur) + (ikw*dk);

      /* derivate along yr */
      dk = -rk12;
      pHJR[16] = (h*dkwvr) + (ikw*dk);

      /* derivate along ikr */
      pHJR[17] = 0;

      /* derivate along cal_yaw */
      dk = (dRK_dcy[2]*duk) + (dRK_dcy[5]*dvk);
      pHC[15] = (h*dkwcy) + (ikw*dk);
      
      /* derivate along cal_pitch */
      dk = (dRK_dcp[2]*duk) + (dRK_dcp[5]*dvk);
      pHC[16] = (h*dkwcp) + (ikw*dk);

      /* derivate along cal_roll */
      dk = (dRK_dcr[2]*duk) + (dRK_dcr[5]*dvk);
      pHC[17] = (h*dkwcr) + (ikw*dk);
    }
  }

  if(pfi != NULL)
  {
    fm = (0.001f*0.001f)*0.5f;
    ikw2 = fm*(ikw*ikw);
    rkl = (xl*xl) + (yl*yl) + 1;
    rkr = (xr*xr) + (yr*yr) + 1;
    k = (ikl*rkl) + (ikr*rkr);
    *pfi = ikw2*k;

    /* jacobian */
    if(   (pHJL != 0)
       && (pHJR != 0)
       && (pHC != 0)
      )
    {
      /* temp values for jacobian calculations */
      h = - (2*ikw*(*pfi));

      /* derivate along xl */
      dk = ikl*(2*xl);
      pHJL[12] = (h*dkwul) + (ikw2*dk);

      /* derivate along yl */
      dk = ikl*(2*yl);
      pHJL[13] = (h*dkwvl) + (ikw2*dk);

      /* derivate along ikl */
      dk = rkl;
      pHJL[14] = ikw2*dk;

      /* derivate along xr */
      dk = ikr*(2*xr);
      pHJR[12] = (h*dkwur) + (ikw2*dk);

      /* derivate along yr */
      dk = ikr*(2*yr);
      pHJR[13] = (h*dkwvr) + (ikw2*dk);

      /* derivate along ikr */
      dk = rkr;
      pHJR[14] = (ikw2*dk);

      /* derivate along cal_yaw */
      pHC[12] = (h*dkwcy);
     
      /* derivate along cal_pitch */
      pHC[13] = (h*dkwcp);

      /* derivate along cal_roll */
      pHC[14] = (h*dkwcr);
    }
  }
}

/* ****************************************************************************
  Functionname:     HLATrackPairModelMeasurement                  */ /*!  
  Description:      
 -----------------------------------------
                    projection Xb(t) of 3D point in camera cs at time t Xk(t)
                    xb(t) = xk(t)/zk(t)
                    yb(t) = yk(t)/zk(t)

                    -----------------------------------------
                    world to cam transform at time t 
                    Xk(t) = RK*(Xw(t) - TK)

                    -----------------------------------------
                    interframe rotation and translation
                    Xw(t) = RE*(Xw(t-1) - RE)

                    -----------------------------------------
                    landmark parametrisation for left light of the pair
                    xwl(t-1) = pd
                    ywl(t-1) = pl + pw/2
                    zwl(t-1) = ph + pr

                    -----------------------------------------
                    landmark parametrisation for right light of the pair
                    xwr(t-1) = pd
                    ywr(t-1) = pl - pw/2
                    zwr(t-1) = ph - pr


                    -----------------------------------------
                    measurement
                    Xk(t) = RK*(RE*(Xw(t-1) - RE) - TK)
                    Xk(t) = RK*RE*Xw(t-1) + RK*( RE(- RE) - TK)

                    Xkl(t) = RA*Xwl(t-1) + TP

                    xbl(t) = xkl(t)/zkl(t)
                    ybl(t) = ykl(t)/zkl(t)

                    with:
                    RA = RK*RE
                    TP = RK*( RE(- RE) - TK)


  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairModelMeasurement(       HLAKalmanMeasPos_t*           pMeasLeftPos,
                                                HLAKalmanMeasInt_t*           pMeasLeftInt,
                                                float32*                      pHLP,
                                                float32*                      pHLE,
                                                HLAKalmanMeasPos_t*           pMeasRightPos,
                                                HLAKalmanMeasInt_t*           pMeasRightInt,
                                                float32*                      pHRP,
                                                float32*                      pHRE,
                                          const HLAPair_t*                    pPair,
                                          const HLATracking3DDataRotations_t* pDataRotations,
                                          const float32                       pw
                                        )
{
  /* pair measurement */
  float32 xl;
  float32 yl;
  float32 ikl;
  float32 xr;
  float32 yr;
  float32 ikr;

  /* pair state */
  float32 pd;
  float32 pl;
  float32 ph;
  float32 pa;
  float32 pr;
  float32 py;
  
  /* rotation matrix */
  const float32* RA;
  const float32* dRA_dey;
  const float32* dRA_dep;
  const float32* dRA_der;
  float32 ra00, ra01, ra02, ra10, ra11, ra12,ra20, ra21, ra22;

  /* translation vector */
  const float32* TA;
  const float32* dTA_dep;
  const float32* dTA_der;
  float32 ta0, ta1, ta2;

  /* world cordinates */
  float32 xw, yw, zw;
  float32 dxw, dyw;
  
  /* camera cordinates */
  float32 xk, yk, zk;
  float32 dxk, dyk, dzk;

  /* temp values */
  float32 izk, xiz2, yiz2;
  float32 dk2, idk2, fm;
  /*float32 ddk2, didk2;*/
  float32 cosy;
  float32 siny;

  /* get composition matrix */
  RA = &pDataRotations->RA[0];
  dRA_dey = &pDataRotations->dRA_dey[0];
  dRA_dep = &pDataRotations->dRA_dep[0];
  dRA_der = &pDataRotations->dRA_der[0];
  ra00 = RA[0];       ra01 = RA[1];   ra02 = RA[2];
  ra10 = RA[3];       ra11 = RA[4];   ra12 = RA[5];
  ra20 = RA[6];       ra21 = RA[7];   ra22 = RA[8];

  /* get resultatnt translation */
  TA = &pDataRotations->TA[0];
  dTA_dep = &pDataRotations->dTA_dep[0];
  dTA_der = &pDataRotations->dTA_der[0];
  ta0 = TA[0];
  ta1 = TA[1];
  ta2 = TA[2];

  /* get pair state */
  pd = pPair->pd;
  pl = pPair->pl;
  ph = pPair->ph;
  pa = pPair->pa;
  pr = pPair->pr;
  py = pPair->py;

  /* m2 to km2 */
  fm = (0.001f*0.001f);

  /* temp values */
  cosy = cosf(py);
  siny = sinf(py);

  /* left light projection */
  if( pMeasLeftPos != 0 )
  {
    /* xw coordinates left */
    xw = pd - ((pw/2.0f)*siny);
    yw = pl + ((pw/2.0f)*cosy);
    zw = ph + (pr/2.0f);

    /* xk coordinate left */
    xk = (ra00*xw) + (ra01*yw) + (ra02*zw) + ta0;
    yk = (ra10*xw) + (ra11*yw) + (ra12*zw) + ta1;
    zk = (ra20*xw) + (ra21*yw) + (ra22*zw) + ta2;

    /* temp values */
    /* ~CodeReview ~ID:ec0ab1591bf815bd50cc1faf371b1c7d ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO. */
    /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
    izk = 1/zk;

    /* left projection */
    xl = xk * izk;
    yl = yk * izk;

    /* set measurement output */
    pMeasLeftPos->x = xl;
    pMeasLeftPos->y = yl;

    /* set intensity output */
    if(pMeasLeftInt != NULL)
    {
      dk2 = ((xk*xk) + (yk*yk) + (zk*zk))*fm;
      idk2 = 1/dk2;

      ikl = pa * idk2;
      pMeasLeftInt->ik = ikl;
    }

    /* temp values for jacobian calculations */
    xiz2 = - (xl*izk);
    yiz2 = - (yl*izk);

    /* left projection derivates along p */
    if(pHLP != NULL)
    {
      /* derivate along pd */
      /*
      dxw = 1;
      dyw = 0;
      dzw = 0;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHLP[0] = (dxk*izk) + (dzk*xiz2);
      pHLP[7] = (dyk*izk) + (dzk*yiz2);
      pHLP[14] = (pa*didk2);
      */
      dxk = (ra00);
      dyk = (ra10);
      dzk = (ra20);

      pHLP[0] = (dxk*izk) + (dzk*xiz2);
      pHLP[7] = (dyk*izk) + (dzk*yiz2);
      
      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLP[14] = (pa*didk2);
      */


      /* derivate along pl */
      /*
      dxw = 0;
      dyw = 1;
      dzw = 0;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHLP[1] = (dxk*izk) + (dzk*xiz2);
      pHLP[8] = (dyk*izk) + (dzk*yiz2);
      pHLP[15] = (pa*didk2);
      */
      dxk = ra01;
      dyk = ra11;
      dzk = ra21;

      pHLP[1] = (dxk*izk) + (dzk*xiz2);
      pHLP[8] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLP[15] = (pa*didk2);
      */

      /* derivate along ph */
      /*
      dxw = 0;
      dyw = 0;
      dzw = 1;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHLP[2] = (dxk*izk) + (dzk*xiz2);
      pHLP[9] = (dyk*izk) + (dzk*yiz2);
      pHLP[16] = (pa*didk2);
      */
      dxk = (ra02);
      dyk = (ra12);
      dzk = (ra22);

      pHLP[2] = (dxk*izk) + (dzk*xiz2);
      pHLP[9] = (dyk*izk) + (dzk*yiz2);
      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLP[16] = (pa*didk2);
      */

      /* derivate along pa */
      pHLP[4] = 0;
      pHLP[11] = 0;

      /*
      pHLP[18] = idk2;
      */

      /* derivate along pr */
      /*
      dxw = 0;
      dyw = 0;
      dzw = 0.5f;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHLP[5] = (dxk*izk) + (dzk*xiz2);
      pHLP[12] = (dyk*izk) + (dzk*yiz2);
      pHLP[19] = (pa*didk2);
      */
      dxk = (ra02*0.5f);
      dyk = (ra12*0.5f);
      dzk = (ra22*0.5f);


      pHLP[5] = (dxk*izk) + (dzk*xiz2);
      pHLP[12] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLP[19] = (pa*didk2);
      */

      /* derivate along py */
      /*
      dxw = - (pw/2.0f)*cosy;
      dyw = - (pw/2.0f)*siny;
      dzw = 0;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHLP[6] = (dxk*izk) + (dzk*xiz2);
      pHLP[13] = (dyk*izk) + (dzk*yiz2);
      pHLP[20] = (pa*didk2);
      */
      dxw = - (pw/2.0f)*cosy;
      dyw = - (pw/2.0f)*siny;

      dxk = (ra00*dxw) + (ra01*dyw);
      dyk = (ra10*dxw) + (ra11*dyw);
      dzk = (ra20*dxw) + (ra21*dyw);

      pHLP[6] = (dxk*izk) + (dzk*xiz2);
      pHLP[13] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLP[20] = (pa*didk2);
      */
    }

    /* left projection derivates along egomotion */
    if(pHLE != NULL)
    {
      /* derivate along ego yaw */
      /*
      dxk = (dRA_dey[0]*xw) + (dRA_dey[1]*yw) + (dRA_dey[2]*zw) + dTA_dey[0];
      dyk = (dRA_dey[3]*xw) + (dRA_dey[4]*yw) + (dRA_dey[5]*zw) + dTA_dey[1];
      dzk = (dRA_dey[6]*xw) + (dRA_dey[7]*yw) + (dRA_dey[8]*zw) + dTA_dey[2];

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHLE[0] = (dxk*izk) + (dzk*xiz2);
      pHLE[3] = (dyk*izk) + (dzk*yiz2);
      pHLE[6] = (pa*didk2);
      */

      dxk = (dRA_dey[0]*xw) + (dRA_dey[1]*yw);
      dyk = (dRA_dey[3]*xw) + (dRA_dey[4]*yw);
      dzk = (dRA_dey[6]*xw) + (dRA_dey[7]*yw);

      pHLE[0] = (dxk*izk) + (dzk*xiz2);
      pHLE[3] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLE[6] = (pa*didk2);
      */

      /* derivate along ego pitch */
      dxk = (dRA_dep[0]*xw) + (dRA_dep[1]*yw) + (dRA_dep[2]*zw) + dTA_dep[0];
      dyk = (dRA_dep[3]*xw) + (dRA_dep[4]*yw) + (dRA_dep[5]*zw) + dTA_dep[1];
      dzk = (dRA_dep[6]*xw) + (dRA_dep[7]*yw) + (dRA_dep[8]*zw) + dTA_dep[2];

      pHLE[1] = (dxk*izk) + (dzk*xiz2);
      pHLE[4] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLE[7] = (pa*didk2);
      */

      /* derivate along ego roll */
      dxk = (dRA_der[0]*xw) + (dRA_der[1]*yw) + (dRA_der[2]*zw) + dTA_der[0];
      dyk = (dRA_der[3]*xw) + (dRA_der[4]*yw) + (dRA_der[5]*zw) + dTA_der[1];
      dzk = (dRA_der[6]*xw) + (dRA_der[7]*yw) + (dRA_der[8]*zw) + dTA_der[2];

      pHLE[2] = (dxk*izk) + (dzk*xiz2);
      pHLE[5] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHLE[8] = (pa*didk2);
      */
    }
  }

  /*  right light image projection */
  if( pMeasRightPos != 0 )
  {
    /* xw coordinates right */
    xw = pd + ((pw/2.0f)*siny);
    yw = pl + ((-pw/2.0f)*cosy);
    zw = ph + (-pr/2.0f);

    /* xk coordinate right */
    xk = (ra00*xw) + (ra01*yw) + (ra02*zw) + ta0;
    yk = (ra10*xw) + (ra11*yw) + (ra12*zw) + ta1;
    zk = (ra20*xw) + (ra21*yw) + (ra22*zw) + ta2;

    /* temp values */
    /* ~CodeReview ~ID:d18650576a1ea50e01bc74a7014b8eb5 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO. */
    /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
    izk = 1/zk;

    /* right projection */
    xr = xk * izk;
    yr = yk * izk;

    /* set measurement */
    pMeasRightPos->x = xr;
    pMeasRightPos->y = yr;

    if(pMeasRightInt != NULL)
    {
      dk2 = ((xk*xk) + (yk*yk) + (zk*zk))*fm;
      idk2 = 1/dk2;
    
      ikr = pa * idk2;

      pMeasRightInt->ik = ikr;
    }

    /* temp values */
    xiz2 = - (xr*izk);
    yiz2 = - (yr*izk);

    /* right projection derivates along p */
    if(pHRP != NULL)
    {
      /* derivate along pd */
      /*
      dxw = 1;
      dyw = 0;
      dzw = 0;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHRP[0] = (dxk*izk) + (dzk*xiz2);
      pHRP[7] = (dyk*izk) + (dzk*yiz2);
      pHRP[14] = (pa*didk2);
      */

      dxk = (ra00);
      dyk = (ra10);
      dzk = (ra20);

      pHRP[0] = (dxk*izk) + (dzk*xiz2);
      pHRP[7] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRP[14] = (pa*didk2);
      */

      /* derivate along pl */
      /*
      dxw = 0;
      dyw = 1;
      dzw = 0;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHRP[1] = (dxk*izk) + (dzk*xiz2);
      pHRP[8] = (dyk*izk) + (dzk*yiz2);
      pHRP[15] = (pa*didk2);
      */
      dxk = (ra01);
      dyk = (ra11);
      dzk = (ra21);

      pHRP[1] = (dxk*izk) + (dzk*xiz2);
      pHRP[8] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRP[15] = (pa*didk2);
      */

      /* derivate along ph */
      /*
      dxw = 0;
      dyw = 0;
      dzw = 1;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHRP[2] = (dxk*izk) + (dzk*xiz2);
      pHRP[9] = (dyk*izk) + (dzk*yiz2);
      pHRP[16] = (pa*didk2);
      */
      dxk = (ra02);
      dyk = (ra12);
      dzk = (ra22);

      pHRP[2] = (dxk*izk) + (dzk*xiz2);
      pHRP[9] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRP[16] = (pa*didk2);
      */

      /* derivate along pa */
      pHRP[4] = 0;
      pHRP[11] = 0;

      /*
      pHRP[18] = idk2;
      */

      /* derivate along pr */
      /*
      dxw = 0;
      dyw = 0;
      dzw = -0.5f;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHRP[5] = (dxk*izk) + (dzk*xiz2);
      pHRP[12] = (dyk*izk) + (dzk*yiz2);
      pHRP[19] = (pa*didk2);
      */
      dxk = -(ra02*0.5f);
      dyk = -(ra12*0.5f);
      dzk = -(ra22*0.5f);

      pHRP[5] = (dxk*izk) + (dzk*xiz2);
      pHRP[12] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRP[19] = (pa*didk2);
      */


      /* derivate along py */
      /*
      dxw = (pw/2.0f)*cosy;
      dyw = (pw/2.0f)*siny;
      dzw = 0;

      dxk = (ra00*dxw) + (ra01*dyw) + (ra02*dzw);
      dyk = (ra10*dxw) + (ra11*dyw) + (ra12*dzw);
      dzk = (ra20*dxw) + (ra21*dyw) + (ra22*dzw);

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHRP[6] = (dxk*izk) + (dzk*xiz2);
      pHRP[13] = (dyk*izk) + (dzk*yiz2);
      pHRP[20] = (pa*didk2);
      */
      dxw = (pw/2.0f)*cosy;
      dyw = (pw/2.0f)*siny;

      dxk = (ra00*dxw) + (ra01*dyw);
      dyk = (ra10*dxw) + (ra11*dyw);
      dzk = (ra20*dxw) + (ra21*dyw);

      pHRP[6] = (dxk*izk) + (dzk*xiz2);
      pHRP[13] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRP[20] = (pa*didk2);
      */
    }

    if(pHRE != NULL)
    {
      /* derivate along ego yaw */
      /*
      dxk = (dRA_dey[0]*xw) + (dRA_dey[1]*yw) + (dRA_dey[2]*zw) + dTA_dey[0];
      dyk = (dRA_dey[3]*xw) + (dRA_dey[4]*yw) + (dRA_dey[5]*zw) + dTA_dey[1];
      dzk = (dRA_dey[6]*xw) + (dRA_dey[7]*yw) + (dRA_dey[8]*zw) + dTA_dey[2];

      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;

      pHRE[0] = (dxk*izk) + (dzk*xiz2);
      pHRE[3] = (dyk*izk) + (dzk*yiz2);
      pHRE[6] = (pa*didk2);
      */

      dxk = (dRA_dey[0]*xw) + (dRA_dey[1]*yw);
      dyk = (dRA_dey[3]*xw) + (dRA_dey[4]*yw);
      dzk = (dRA_dey[6]*xw) + (dRA_dey[7]*yw);

      pHRE[0] = (dxk*izk) + (dzk*xiz2);
      pHRE[3] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRE[6] = (pa*didk2);
      */

      /* derivate along ego pitch */
      dxk = (dRA_dep[0]*xw) + (dRA_dep[1]*yw) + (dRA_dep[2]*zw) + dTA_dep[0];
      dyk = (dRA_dep[3]*xw) + (dRA_dep[4]*yw) + (dRA_dep[5]*zw) + dTA_dep[1];
      dzk = (dRA_dep[6]*xw) + (dRA_dep[7]*yw) + (dRA_dep[8]*zw) + dTA_dep[2];

      pHRE[1] = (dxk*izk) + (dzk*xiz2);
      pHRE[4] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRE[7] = (pa*didk2);
      */

      /* derivate along ego roll */
      dxk = (dRA_der[0]*xw) + (dRA_der[1]*yw) + (dRA_der[2]*zw) + dTA_der[0];
      dyk = (dRA_der[3]*xw) + (dRA_der[4]*yw) + (dRA_der[5]*zw) + dTA_der[1];
      dzk = (dRA_der[6]*xw) + (dRA_der[7]*yw) + (dRA_der[8]*zw) + dTA_der[2];

      pHRE[2] = (dxk*izk) + (dzk*xiz2);
      pHRE[5] = (dyk*izk) + (dzk*yiz2);

      /*
      ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
      didk2 = - (idk2*idk2)*ddk2;
      pHRE[8] = (pa*didk2);
      */
    }
  }
}


/* ****************************************************************************
  Functionname:     HLATrackPairModelReprojection                  */ /*!
  Description:      

                    

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackPairModelReprojection(      HLAKalmanMeasPos_t*           pRepjLeftPos,
                                                HLAKalmanMeasInt_t*           pRepjLeftInt,
                                                HLAKalmanMeasPos_t*           pRepjRightPos,
                                                HLAKalmanMeasInt_t*           pRepjRightInt,
                                                float32*                      pHLP,
                                                float32*                      pHRP,
                                                HLAPairTTBInput*              pTTBIn,
                                          const HLAPair_t*                    pPair,
                                          const HLATracking3DDataRotations_t* pDataRotations,
                                          const float32                       pw
                                         )
{
  /* pair measurement */
  float32 xl;
  float32 yl;
  float32 ikl;
  float32 xr;
  float32 yr;
  float32 ikr;

  /* pair state */
  float32 pd;
  float32 pl;
  float32 ph;
  float32 pa;
  float32 pr;
  float32 py;

  /* on-line cali roation matrix */
  const float32* RK;
  float32 rk00, rk01, rk02, rk10, rk11, rk12,rk20, rk21, rk22;

  const float32* TK;
  float32 tkx, tky, tkz;

  /* world cordinates */
  float32 xw, yw, zw;
  
  /* camera cordinates */
  float32 xk, yk, zk;
  float32 dxk, dyk, dzk;

  /* temp values */
  float32 pw05, pr05;
  float32 izk, xiz2, yiz2, izw;
  float32 ha, hax, hay, haz;
  float32 dk2, idk2, fm;
  float32 siny, cosy;

  /* get pair state */
  pd = pPair->pd;
  pl = pPair->pl;
  ph = pPair->ph;
  pa = pPair->pa;
  pr = pPair->pr;
  py = pPair->py;

  /* m2 to km2 */
  fm = (0.001f * 0.001f);

  /* get world to cam transform */
  RK = &pDataRotations->RK[0];
  rk00 = RK[0];       rk01 = RK[1];   rk02 = RK[2];
  rk10 = RK[3];       rk11 = RK[4];   rk12 = RK[5];
  rk20 = RK[6];       rk21 = RK[7];   rk22 = RK[8];

  TK = &pDataRotations->TK[0];
  tkx = TK[0];
  tky = TK[1];
  tkz = TK[2];

  /* temp values */
  siny = sinf(py);
  cosy = cosf(py);
  pw05 = 0.5f*pw;
  pr05 = 0.5f*pr;

  /* xw coordinates left */
  xw = (pd - (pw05*siny)) - tkx;
  yw = (pl + (pw05*cosy)) - tky;
  zw = (ph + (pr05))        - tkz;

  /* calculate ttb inputs for left track */
  if(pTTBIn != NULL)
  {
    /* ~CodeReview ~ID:b62615024be33bc02666d5a26d72ee20 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO. */
    /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
    izw = 1/xw;
    pTTBIn->uwl = (yw*izw);
    pTTBIn->dwl = izw;
  }

  /* xk coordinate left */
  xk = (rk00*xw) + (rk01*yw) + (rk02*zw);
  yk = (rk10*xw) + (rk11*yw) + (rk12*zw);
  zk = (rk20*xw) + (rk21*yw) + (rk22*zw);

  /* temp values */
  /* ~CodeReview ~ID:78e7d62c4903b07b1e2d74794e3313ec ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO (2x). */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
  izk = 1/zk;
  dk2 = ((xk*xk) + (yk*yk) + (zk*zk))*fm;
  idk2 = 1/dk2;

  /* left projection */
  xl = xk * izk;
  yl = yk * izk;
  ikl = pa * idk2;

  xiz2 = - (xl*izk);
  yiz2 = - (yl*izk);

  ha = - (2*ikl)*(fm*idk2);
  hax = (ha*xk);
  hay = (ha*yk);
  haz = (ha*zk);

  /* left projection derivates along p */
  if(pHLP != NULL)
  {
    /* derivate along pd */
    /*
    dxw = 1;
    dyw = 0;
    dzw = 0;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHLP[0] = (dxk*izk) + (dzk*xiz2);
    pHLP[6] = (dyk*izk) + (dzk*yiz2);
    pHLP[12] = (pa*didk2);
    */

    dxk = rk00;
    dyk = rk10;
    dzk = rk20;

    pHLP[0]  = (dxk*izk) + (dzk*xiz2);
    pHLP[6]  = (dyk*izk) + (dzk*yiz2);
    pHLP[12] = (hax*dxk) + (hay*dyk) + (haz*dzk);

   
    /* derivate along pl */
    /*
    dxw = 0;
    dyw = 1;
    dzw = 0;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHLP[1] = (dxk*izk) + (dzk*xiz2);
    pHLP[7] = (dyk*izk) + (dzk*yiz2);
    pHLP[13] = (pa*didk2);
    */

    dxk = rk01;
    dyk = rk11;
    dzk = rk21;

    pHLP[1]  = (dxk*izk) + (dzk*xiz2);
    pHLP[7]  = (dyk*izk) + (dzk*yiz2);
    pHLP[13] = (hax*dxk) + (hay*dyk) + (haz*dzk);

    /* derivate along ph */
    /*
    dxw = 0;
    dyw = 0;
    dzw = 1;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHLP[2] = (dxk*izk) + (dzk*xiz2);
    pHLP[8] = (dyk*izk) + (dzk*yiz2);
    pHLP[14] = (pa*didk2);
    */

    dxk = rk02;
    dyk = rk12;
    dzk = rk22;

    pHLP[2]  = (dxk*izk) + (dzk*xiz2);
    pHLP[8]  = (dyk*izk) + (dzk*yiz2);
    pHLP[14] = (hax*dxk) + (hay*dyk) + (haz*dzk);

    /* derivate along pa */
    pHLP[4] = 0;
    pHLP[10] = 0;
    pHLP[16] = idk2;

    /* derivate along pr */
    /*
    dxw = 0;
    dyw = 0;
    dzw = 0.5f;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHLP[5] = (dxk*izk) + (dzk*xiz2);
    pHLP[11] = (dyk*izk) + (dzk*yiz2);
    pHLP[17] = (pa*didk2);
    */

    dxk = rk02*0.5f;
    dyk = rk12*0.5f;
    dzk = rk22*0.5f;

    pHLP[5]  = (dxk*izk) + (dzk*xiz2);
    pHLP[11] = (dyk*izk) + (dzk*yiz2);
    pHLP[17] = (hax*dxk) + (hay*dyk) + (haz*dzk);
  }


  /* xw coordinates right */
  xw = (pd + (pw05*siny)) - tkx;
  yw = (pl - (pw05*cosy)) - tky;
  zw = (ph - (pr05))   - tkz;

  /* calculate ttb inputs for right track */
  if(pTTBIn != NULL)
  {
    /* ~CodeReview ~ID:3be756fa5e2ef03c32d9e61773ed9b51 ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO. */
    /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
    izw = 1/xw;
    pTTBIn->uwr = (yw*izw);
    pTTBIn->dwr = izw;

    /* speed vector */
    pTTBIn->os = cosy*(pPair->ps);
    pTTBIn->ol = siny*(pPair->ps);
  }

  /* xk coordinate left */
  xk = (rk00*xw) + (rk01*yw) + (rk02*zw);
  yk = (rk10*xw) + (rk11*yw) + (rk12*zw);
  zk = (rk20*xw) + (rk21*yw) + (rk22*zw);

  /* temp values */
  /* ~CodeReview ~ID:d5efd6f6ca5e9f9814428edffb17553b ~Reviewer:PC2357\dijkstg ~Date:12-7-2012 ~Priority:3 ~Comment:Potential division by ZERO (2x). */
  /* Godreau B, code review findings priority changed from 1 to 3 : it is not possible that the point depth value is 0 */
  izk = 1/zk;
  dk2 = ((xk*xk) + (yk*yk) + (zk*zk))*fm;
  idk2 = 1/dk2;

  /* right projection */
  xr = xk * izk;
  yr = yk * izk;
  ikr = pa * idk2;

  /* temp values */
  xiz2 = - (xr*izk);
  yiz2 = - (yr*izk);

  ha = - (2*ikl)*(fm*idk2);
  hax = (ha*xk);
  hay = (ha*yk);
  haz = (ha*zk);

  /* right projection derivates along p */
  if(pHRP != NULL)
  {
    /* derivate along pd */
    /*
    dxw = 1;
    dyw = 0;
    dzw = 0;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHRP[0] = (dxk*izk) + (dzk*xiz2);
    pHRP[6] = (dyk*izk) + (dzk*yiz2);
    pHRP[12] = (pa*didk2);
    */

    dxk = rk00;
    dyk = rk10;
    dzk = rk20;

    pHRP[0]  = (dxk*izk) + (dzk*xiz2);
    pHRP[6]  = (dyk*izk) + (dzk*yiz2);
    pHRP[12] = (hax*dxk) + (hay*dyk) + (haz*dzk);


    /* derivate along pl */
    /*
    dxw = 0;
    dyw = 1;
    dzw = 0;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHRP[1] = (dxk*izk) + (dzk*xiz2);
    pHRP[7] = (dyk*izk) + (dzk*yiz2);
    pHRP[13] = (pa*didk2);
    */

    dxk = rk01;
    dyk = rk11;
    dzk = rk21;

    pHRP[1]  = (dxk*izk) + (dzk*xiz2);
    pHRP[7]  = (dyk*izk) + (dzk*yiz2);
    pHRP[13] = (hax*dxk) + (hay*dyk) + (haz*dzk);

    /* derivate along ph */
    /*
    dxw = 0;
    dyw = 0;
    dzw = 1;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHRP[2] = (dxk*izk) + (dzk*xiz2);
    pHRP[8] = (dyk*izk) + (dzk*yiz2);
    pHRP[14] = (pa*didk2);
    */

    dxk = rk02;
    dyk = rk12;
    dzk = rk22;

    pHRP[2]  = (dxk*izk) + (dzk*xiz2);
    pHRP[8]  = (dyk*izk) + (dzk*yiz2);
    pHRP[14] = (hax*dxk) + (hay*dyk) + (haz*dzk);

    /* derivate along pa */
    pHRP[4] = 0;
    pHRP[10] = 0;
    pHRP[16] = idk2;

    /* derivate along pr */
    /*
    dxw = 0;
    dyw = 0;
    dzw = -0.5f;

    dxk = (rk00*dxw) + (rk01*dyw) + (rk02*dzw);
    dyk = (rk10*dxw) + (rk11*dyw) + (rk12*dzw);
    dzk = (rk20*dxw) + (rk21*dyw) + (rk22*dzw);

    ddk2 = ((2*xk*dxk) + (2*yk*dyk) + (2*zk*dzk))*fm;
    didk2 = - (idk2*idk2)*ddk2;

    pHRP[5] = (dxk*izk) + (dzk*xiz2);
    pHRP[11] = (dyk*izk) + (dzk*yiz2);
    pHRP[17] = (pa*didk2);
    */

    dxk = - (rk02*0.5f);
    dyk = - (rk12*0.5f);
    dzk = - (rk22*0.5f);

    pHRP[5]  = (dxk*izk) + (dzk*xiz2);
    pHRP[11] = (dyk*izk) + (dzk*yiz2);
    pHRP[17] = (hax*dxk) + (hay*dyk) + (haz*dzk);
  }

  /* set measurement */
  pRepjLeftPos->x = xl;
  pRepjLeftPos->y = yl;
  pRepjLeftInt->ik = ikl;
  pRepjRightPos->x = xr;
  pRepjRightPos->y = yr;
  pRepjRightInt->ik = ikr;
}


/* ****************************************************************************
  Functionname:     HLATrackPairModelTimeUpdate
  Description:      


 
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
static void HLATrackPairModelTimeUpdate(      HLAPair_t*                    pPairOut,
                                              float32*                      pHPS,
                                        const HLAPair_t*                    pPairIn,
                                        const HLATracking3DDataEgomotion_t* pDataEgomotion
                                       )
{
  float32 cosy, siny;
  float32 dd;
  float32 dl;
  float32 dt;

  /* get cycle time */
  dt = pDataEgomotion->dt;

  /* get yaw cosinus and sinnus */
  cosy = cosf(pPairIn->py);
  siny = sinf(pPairIn->py);

  /* speed vector */
  dd = cosy*((pPairIn->ps)*dt);
  dl = siny*((pPairIn->ps)*dt);

  /* constant */
  pPairOut->ph = pPairIn->ph;
  pPairOut->pa = pPairIn->pa;

  /* constant with process noise */
  pPairOut->pr = pPairIn->pr;
  pPairOut->ps = pPairIn->ps;
  pPairOut->py = pPairIn->py;

  /* depending on speed and yaw */
  pPairOut->pd = pPairIn->pd + dd;
  pPairOut->pl = pPairIn->pl + dl;

  if(pHPS != NULL)
  {
    /* derivate along speed */
    pHPS[0] = cosy*dt;
    pHPS[2] = siny*dt;

    /* derivate along yaw */
    pHPS[1] = -dl;
    pHPS[3] = dd;
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackPairModelMapUpdate
  Description:      
  compute landmark dynamic state (ouw,ovw,odw,os,ol) in the current coordinate system
                    depending on:
                    - previous landmark state (ouw(t-1),ovw(t-1),odw(t-1),os(t-1),ol(t-1))
                    - interframe motion


                    -----------------------------------------
                    interframe rotation and translation
                    Xw(t) = RE*(Xw(t-1) - RE)

                    -----------------------------------------
                    landmark parametrisation for left light of the pair
                    xwl(t-1) = pd
                    ywl(t-1) = pl
                    zwl(t-1) = ph + pr

                    -----------------------------------------
                    landmark parametrisation for right light of the pair
                    xwr(t-1) = pd
                    ywr(t-1) = pl - pw
                    zwr(t-1) = ph - pr

 
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
****************************************************************************/
static void HLATrackPairModelMapUpdate(       HLAPair_t*                    pPairOut,
                                              float32*                      pHP,
                                              float32*                      pHE,
                                        const HLAPair_t*                    pPairIn,
                                        const HLATracking3DDataRotations_t* pDataRotations,
                                        const HLATracking3DDataEgomotion_t* pDataEgomotion
                                      )
{
  /* get vehicle position */
  float32 pd;
  float32 pl;
  float32 ph;

  const float32* RE;
  const float32* dRE_dey;
  const float32* dRE_dep;
  const float32* dRE_der;

  const float32* VE;
  const float32* dVE_dep;
  const float32* dVE_der;

  float32  re00, re01, re02, re10, re11, re12,re20, re21, re22;

  RE = &pDataRotations->RE[0];
  dRE_dey = &pDataRotations->dRE_dey[0];
  dRE_dep = &pDataRotations->dRE_dep[0];
  dRE_der = &pDataRotations->dRE_der[0];

  VE = &pDataRotations->VE[0];
  dVE_dep = &pDataRotations->dVE_dep[0];
  dVE_der = &pDataRotations->dVE_der[0];

  /* calculate vehicle rotation matrix: RE */
  re00 = RE[0];       re01 = RE[1];   re02 = RE[2];
  re10 = RE[3];       re11 = RE[4];   re12 = RE[5];
  re20 = RE[6];       re21 = RE[7];   re22 = RE[8];

  /* get vehicle position */
  pd = pPairIn->pd;
  pl = pPairIn->pl;
  ph = pPairIn->ph;

  /* calculate new position */
  pPairOut->pd = (re00*pd) + (re01*pl) + (re02*ph) + VE[0];
  pPairOut->pl = (re10*pd) + (re11*pl) + (re12*ph) + VE[1];
  pPairOut->ph = (re20*pd) + (re21*pl) + (re22*ph) + VE[2];

  pPairOut->py =  pPairIn->py - pDataEgomotion->ego_yaw;

  /* jacobian */
  if(pHP != NULL)
  {
    /* derivate along pd */
    pHP[0] = re00;
    pHP[3] = re10;
    pHP[6] = re20;

    /* derivate along pl */
    pHP[1] = re01;
    pHP[4] = re11;
    pHP[7] = re21;

    /* derivate along ph */
    pHP[2] = re02;
    pHP[5] = re12;
    pHP[8] = re22;
  }

  if(pHE != NULL)
  {
    /* derivate along ego yaw */
    /*
    pHE[0] = (dRE_dey[0]*pd) + (dRE_dey[1]*pl) + (dRE_dey[2]*ph) + dVE_dey[0];
    pHE[3] = (dRE_dey[3]*pd) + (dRE_dey[4]*pl) + (dRE_dey[5]*ph) + dVE_dey[1];
    pHE[6] = (dRE_dey[6]*pd) + (dRE_dey[7]*pl) + (dRE_dey[8]*ph) + dVE_dey[2];
    */
    pHE[0] = (dRE_dey[0]*pd) + (dRE_dey[1]*pl);
    pHE[3] = (dRE_dey[3]*pd) + (dRE_dey[4]*pl);
    pHE[6] = (dRE_dey[6]*pd) + (dRE_dey[7]*pl);

    /* derivate along ego pitch */
    pHE[1] = (dRE_dep[0]*pd) + (dRE_dep[1]*pl) + (dRE_dep[2]*ph) + dVE_dep[0];
    pHE[4] = (dRE_dep[3]*pd) + (dRE_dep[4]*pl) + (dRE_dep[5]*ph) + dVE_dep[1];
    pHE[7] = (dRE_dep[6]*pd) + (dRE_dep[7]*pl) + (dRE_dep[8]*ph) + dVE_dep[2];

    /* derivate along ego roll */
    /*
    pHE[2] = (dRE_der[0]*pd) + (dRE_der[1]*pl) + (dRE_der[2]*ph) + dVE_der[0];
    pHE[5] = (dRE_der[3]*pd) + (dRE_der[4]*pl) + (dRE_der[5]*ph) + dVE_der[1];
    pHE[8] = (dRE_der[6]*pd) + (dRE_der[7]*pl) + (dRE_der[8]*ph) + dVE_der[2];
    */
    pHE[2] = 0;
    pHE[5] = (dRE_der[3]*pd) + (dRE_der[4]*pl) + (dRE_der[5]*ph) + dVE_der[1];
    pHE[8] = (dRE_der[6]*pd) + (dRE_der[7]*pl) + (dRE_der[8]*ph) + dVE_der[2];
  }

}


/* ***********************************************************************/ /*! 
  @fn            HLATrackPairToolsGetWidth


  @brief         get pair width assumption

  @description   --

  @return        int 

  @pre           -

  @post          -

  @author        Bertrand Godreau
**************************************************************************** */
static void HLATrackPairToolsGetWidth(      float32*                        pw,
                                            float32*                        ppww,
                                      const HLAPair_t*                      pPair,
                                      const HLATracking3DDataPreComputed_t* pDataPreComputed
                                     )
{
  *pw = 0;
  *ppww = 0;

  if(pDataPreComputed != NULL)
  {
    if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_AHEAD)
    {
      *pw = pDataPreComputed->dataAhead.pw;
      *ppww = pDataPreComputed->dataAhead.ppww;
    }
    else if(pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
    {
        *pw = pDataPreComputed->dataTruckLights.pw;
        *ppww = pDataPreComputed->dataTruckLights.ppww;
    }
    else
    {
      *pw = pDataPreComputed->dataOncoming.pw;
      *ppww = pDataPreComputed->dataOncoming.ppww;
    }
  }
}/* PRQA S 861 1 */
