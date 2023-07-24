/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    Renesas M32R

  COMPONENT:              HLA

  MODULNAME:              hla_tracking_3d.c

  DESCRIPTION:            Functions for light track analysis.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          01.09.2010

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_tracking_3d.c  $  
  CHANGE:                 Revision 1.1 2021/12/13 17:28:09CET Wang, David (Wangd3)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj  
  CHANGE:                 Revision 1.0 2017/03/03 10:39:50CET Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj  
  CHANGE:                 Revision 1.1 2014/04/17 16:06:10CEST Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj  
  CHANGE:                 Revision 1.20 2014/03/28 10:36:21CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Introduced CML_u_Round2Uint  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:21 AM CET]  
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.19 2014/03/26 11:27:46CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed some mandatory QAC warnings  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:47 AM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.18 2014/03/25 19:11:50CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Separation of hla_segmentation.c  
  CHANGE:                 Removed QAC warnings  
  CHANGE:                 Replaces fABS by CML_f_abs  
  CHANGE:                 Introduced CML_s_Round2Int  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:50 PM CET]  
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.17 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Member moved from hla_tracking_3d.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_tracking_3d.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.  
  CHANGE:                 Revision 1.16 2014/03/21 09:38:40CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed some QAC warnings (parenthesis)  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:40 AM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.15 2014/03/19 16:30:42CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h  
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)  
  CHANGE:                 Clean-up of no longer needed files in simulation  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:43 PM CET]  
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959  
  CHANGE:                 Revision 1.14 2014/03/10 13:21:10CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Fixed some new critical QAC warnings  
  CHANGE:                 Moved suppressions from .hoc file to comment in source code  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:10 PM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.13 2014/03/04 16:52:08CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Fixed QAC warnings  
  CHANGE:                 Coding style  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:09 PM CET]  
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.12 2014/02/28 15:04:57CET Brunn, Marcus (brunnm)   
  CHANGE:                 - improved light filtering  
  CHANGE:                 - preparation of light list for new rte interface i390  
  CHANGE:                 --- Added comments ---  brunnm [Feb 28, 2014 3:04:58 PM CET]  
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024  
  CHANGE:                 Revision 1.11 2014/02/11 17:24:54CET Manz, Alexander (uidv8777)   
  CHANGE:                 Fixes:  
  CHANGE:                  - improved selection of region for tracking  
  CHANGE:                  - minor bug fixes for tracking   
  CHANGE:                   
  CHANGE:                 Update in visu:  
  CHANGE:                  - new pair visualization  
  CHANGE:                  - new features to disable horizon, ROI and vehicle data visu parts  
  CHANGE:                  - tunnel visu moved to be part of environment  
  CHANGE:                  - minor restructuring of hotkeys  
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 11, 2014 5:24:54 PM CET]  
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634  
  CHANGE:                 Revision 1.10 2014/02/07 09:49:59CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Fixed critical QAC warnings  
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:49:59 AM CET]  
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.9 2014/02/06 16:02:32CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)  
  CHANGE:                 Centralized Null pointer checks  
  CHANGE:                 Refactored dframe calculation  
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:33 PM CET]  
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576  
  CHANGE:                 Revision 1.8 2014/02/05 15:26:54CET Brunn, Marcus (brunnm)   
  CHANGE:                 removed LED segmentation  
  CHANGE:                 --- Added comments ---  brunnm [Feb 5, 2014 3:26:55 PM CET]  
  CHANGE:                 Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024  
  CHANGE:                 Revision 1.7 2014/01/24 13:37:48CET Manz, Alexander (uidv8777)   
  CHANGE:                 Update:  
  CHANGE:                  - adapt to HLA coding guidelines (more)  
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:48 PM CET]  
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634  
  CHANGE:                 Revision 1.6 2014/01/21 13:09:13CET Manz, Alexander (uidv8777)   
  CHANGE:                 Cosmetic changes:  
  CHANGE:                  - replaced pT and pTLB with pTrack  
  CHANGE:                  - removed unnecessary PC_SIM parts  
  CHANGE:                  - realigned code in various places  
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:13 PM CET]  
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634  
  CHANGE:                 Revision 1.5 2014/01/05 22:57:55CET Glebov, Roman (uidg4759)   
  CHANGE:                 QAC: implicite conversion from int to unsigned int and vise versa removed  
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:57:55 PM CET]  
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435  
  CHANGE:                 Revision 1.4 2013/12/18 15:18:05CET Schillinger, Patrick (uidv8776)   
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection  
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:05 PM CET]  
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150  
  CHANGE:                 Revision 1.3 2013/12/13 16:45:05CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Service functions are now passed in one struct  
  CHANGE:                 SDLfile definitions moved to separate file  
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:05 PM CET]  
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.2 2013/11/21 17:53:42CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Merge from NEW_SEG branch  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:42 PM CET]  
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.1.1.8 2013/11/21 14:15:26CET Manz, Alexander (uidv8777)   
  CHANGE:                 Fix:   
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking  
  CHANGE:                  - region selection for tracking fixed  
  CHANGE:                  - minor bug in pseudo census code generation fixed  
  CHANGE:                 Updates:  
  CHANGE:                  - some minor cosmetic changes in tracking files  
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration  
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:26 PM CET]  
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634  
  CHANGE:                 Revision 1.1.1.7 2013/11/21 13:37:33CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Improved Icon normalize  
  CHANGE:                 Bug fixes in segmentation  
  CHANGE:                 Removed no longer compiler switches  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:33 PM CET]  
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.1.1.6 2013/11/19 07:54:25CET Brunn, Marcus (brunnm)   
  CHANGE:                 - removed day segmentation  
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 7:54:26 AM CET]  
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639  
  CHANGE:                 Revision 1.1.1.5 2013/11/12 13:44:47CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed SegOut from function arguments  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:47 PM CET]  
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787  
  CHANGE:                 Revision 1.1.1.4 2013/10/25 15:17:43CEST Brunn, Marcus (brunnm)   
  CHANGE:                 improved detection of preceding cars (reduced thresholds for birth of red lights)  
  CHANGE:                 --- Added comments ---  brunnm [Oct 25, 2013 3:17:43 PM CEST]  
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639  
  CHANGE:                 Revision 1.1.1.3 2013/10/24 10:44:20CEST Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed some not needed variables  
  CHANGE:                 Made HLA working on evalboard  
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 24, 2013 10:44:20 AM CEST]  
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787  
  CHANGE:                 Revision 1.1.1.2 2013/10/21 10:18:30CEST Brunn, Marcus (brunnm)   
  CHANGE:                 - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t  
  CHANGE:                 - removed bit field for line position  
  CHANGE:                 - moved  level index from line to region  
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 10:18:30 AM CEST]  
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639  
  CHANGE:                 Revision 1.1.1.1 2013/10/18 13:27:58CEST Brunn, Marcus (brunnm)   
  CHANGE:                 intial version of new segmentation  
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:58 PM CEST]  
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639  
  CHANGE:                 Revision 1.1 2013/08/05 17:01:58CEST Manz, Alexander (uidv8777)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj  
  CHANGE:                 Revision 1.1.1.196 2013/08/02 15:25:57CEST Manz, Alexander (uidv8777)   
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding  
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:57 PM CEST]  
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283  
  CHANGE:                 Revision 1.1.1.195 2013/05/03 07:53:05CEST Brunn, Marcus (brunnm)   
  CHANGE:                 fixed LINT/MISRA Errors  
  CHANGE:                 --- Added comments ---  brunnm [May 3, 2013 7:53:05 AM CEST]  
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112  
  CHANGE:                 Revision 1.1.1.194 2013/04/12 12:45:22CEST Mutschler, Matthias (uidv7867)   
  CHANGE:                 Took more coding parameters into use  
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:23 PM CEST]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.193 2013/01/23 16:39:56CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Converted enum to rte like type for  
  CHANGE:                 - HLA_t_eHeadLightMode  
  CHANGE:                 - HLA_t_eSpotLight  
  CHANGE:                 - HLA_t_eWindshieldType  
  CHANGE:                 - HLA_t_eDefectPixelType  
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 23, 2013 4:39:57 PM CET]  
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173  
  CHANGE:                 Revision 1.1.1.192 2013/01/11 16:04:52CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Fixed compiler warnings (type casting) due to 32-bit enums  
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 11, 2013 4:04:52 PM CET]  
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173  
**************************************************************************** */
#include "hla_tracking.h"

/* includes */
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>

#include "hla_trackmeas.h"
#include "hla_trackmodel.h"
#include "hla_trackstatic.h"
#include "hla_trackdynamic.h"
#include "hla_lightdist.h"
#include "hla_imager.h"

#ifdef PC_SIM
#include "param.h"
#endif


/* init data */
static void HLATracking3DInitPreComputed(       HLATracking3DDataPreComputed_t*           pDataPreComputed, 
                                          const HLA_t_FocalLength*                        ps_FocalLength,
                                          const HLA_t_LensCenter*                         ps_LensCenter,
                                          const HLATracking3DParametersMatching_t*        pParamMatching,
                                          const HLATracking3DParametersStaticTracker_t*   pParamStatic,
                                          const HLATracking3DParametersDynamicTracker_t*  pParamDynamic,
                                          const HLATracking3DParametersDistFromHeight_t*  pParamDistFromHeight,
                                          const HLATracking3DParametersEgomotion_t*       pParamEgomotion,
                                          const HLATracking3DParametersAnalysis_t*        pParamAnalysis,
                                          const CPAR_HLAR_Parameter_t*                    pCPar_Hlar
                                        );

static void HLATracking3DInitTracks(HLATracking3DDataTracks_t* pDataTracks);

/* associate light to tracks */
static void HLATracking3DAssocTrack2LightReset( HLATrack_t* pTrackStart,
                                                HLAPair_t*  pPairStart
                                              );

static void HLATracking3DAssocTrack2Light(      HLATrack_t*                           pTrackStart,
                                                HLADebugOutputs_t*                    phlaDebugOutputs,
                                                HLATracking3DDataTracks_t*            pDataTracks,
                                                HLAHotPixelsData_t*                   pDataHotPixels,
                                          const HLASegOut_t*                          pSegOut,
                                          const AS_t_GetTimestampuS32                 pfGetTimestampuS32,
                                          const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                          const HLATracking3DParametersMeasurement_t* pParamMeas,
                                          const HLATracking3DParametersMatching_t*    pParamMatching,
                                          const HLACameraData_t*                      pCamData
                                         );

static void HLATracking3DAssocTrack2LightSolve(       HLADebugOutputs_t*            phlaDebugOutputs,
                                                      HLATracking3DDataTracks_t*    pDataTracks,
                                                      HLATracking3DDataCrossCorr_t* pDataCrossCorr,
                                                const HLASegOut_t*                  pSegOut,
                                                const AS_t_GetTimestampuS32         pfGetTimestampuS32
                                              );

/* track update */
static void HLATracking3DUpdateTracks(      HLATrack_t*                             pTrackStart,
                                            HLADebugOutputs_t*                      phlaDebugOutputs,
                                      const AS_t_GetTimestampuS32                   pfGetTimestampuS32,
                                      const HLASegOut_t*                            pSegOut,
                                      const HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                      const HLATracking3DDataRotations_t*           pDataRotations,
                                      const HLATracking3DDataPreComputed_t*         pDataPreComputed,
                                      const HLATracking3DParametersAnalysis_t*      pParamAnalysis,
                                      const HLATracking3DParametersMeasurement_t*   pParamMeas,
                                      const HLATracking3DParametersDeath_t*         pParamDeath,
                                      const HLACameraData_t*                        pCamData,
                                      const HLATracking3DParametersMatching_t*      pParamMatching,
                                      const HLATracking3DParametersStaticTracker_t* pParamStatic,
                                      const HLATracking3DParametersTTB_t*           pParamTTB
#ifdef PC_SIM
                                    , const HLATracking3DParametersDynamicTracker_t*  pParamDynamic
                                    ,       HLATracking3DDataDebug_t*                pDataDebug
#endif
                                     );

static void HLATracking3DUpdateTrackBasics(       HLATrack_t*                         pTrack,
                                            const HLAKalmanMeasPosPix_t*              pLPix,
                                            const HLATracking3DDataPreComputed_t*     pDataPreComputed,
                                            const HLATracking3DParametersAnalysis_t*  pParamAnalysis,
                                            const HLACameraData_t*                    pCamData
                                          );

static boolean HLATracking3DIsATrackToRemove(
#ifdef PC_SIM
                                                    HLATrack_t*                     pT,
#else
                                              const HLATrack_t*                     pT,
#endif
                                              const HLATracking3DParametersDeath_t* pParamDeath,
                                              const HLACameraData_t*                pCamData
                                            );

/* pair update */
static void HLATracking3DUpdatePairs(       HLAPair_t*                            pPairStart,
                                            HLADebugOutputs_t*                    phlaDebugOutputs,
                                      const HLATracking3DDataEgomotion_t*         pDataEgomotion,
                                      const HLATracking3DDataRotations_t*         pDataRotations,
                                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                      const HLATracking3DParametersMeasurement_t* pParamMeas,
                                      const HLATracking3DParametersDeath_t*       pParamDeath,
                                      const HLATracking3DParametersTTB_t*         pParamTTB,
                                      const AS_t_GetTimestampuS32                 pfGetTimestampuS32
                                    );

static void HLATracking3DUpdatePairBasics(HLAPair_t* pPair);

static uint16 HLATracking3DIsAPairToRemove( const HLAPair_t*                          pPair,
                                            const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                            const HLATracking3DParametersDeath_t*     pParamDeath
                                          );

/* track birth */
static boolean HLATracking3DIsALightToStartNewTrack(      HLASegLight_t*                  pLight,
                                                    const HLATracking3DParametersBirth_t* pParamBirth,
                                                    const HLATracking3DDataTracks_t*      pDataTracks
                                                   );

static void HLATracking3DAddTracks( HLATrack_t**                                ppTrackStart,
                                    uint8*                                      pnumTracks,
                                    HLATracking3DDataTracks_t*                  pDataTracks,
                                    const HLASegOut_t*                          pSegOut,
                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                    const HLATracking3DDataRotations_t*         pDataRotations,
#ifdef PC_SIM
                                    const HLATracking3DDataDebug_t*             pDataDebug,
#endif
                                    const HLATracking3DParametersMeasurement_t* pParamMeas,
                                    const HLATracking3DParametersBirth_t*       pParamBirth
                                  );


/* track death */
static void HLATracking3DFindTracksAndPairsToRemove(      HLATrack_t*                           pTrackStart,
                                                          HLAPair_t*                            pPairStart,
                                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                                    const HLATracking3DDataRotations_t*         pDataRotations,
                                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                                   );

static void HLATracking3DRemoveTracks(      HLATrack_t**                ppTrackStart,
                                            uint8*                      pnumTracks,
                                            HLATracking3DDataTracks_t*  pDataTracks,
                                      const uint8                       removeBornDeadTracks
                                     );


/* **************************************************************************** 
  Functionname:     HLATracking3D                                           */ /*!  
  Description:      main function of 3D tracking


  @param[in]        
                                                    

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATracking3D(       HLATracking3DOutput_t*      pOutput,
                          HLADebugOutputs_t*          phlaDebugOutputs,
                          HLATracking3DData_t*        pData,
                    const HLATracking3DInput_t*       pInput,
                    const HLA_t_Tracking3DParameters* pParam,
                    const CPAR_HLAR_Parameter_t*      pCpar_Hlar,
                    const RTE_HLA_TrafficStyle        eTrafficStyle,
                    const AS_t_GetTimestampuS32       pfGetTimestampuS32
                  )
{
  /* time measurement variables */
  uint32 TimeStart_us;

#ifdef PC_SIM
  pOutput->dataDebug.numFrame++;
#endif

  /* -------------------------------- REMOVE TRACKS --------------------------------------------------*/

  /* remove tracks */
  HLATracking3DRemoveTracks(&(pOutput->pTrack),
                            &(pOutput->numTracks),
                            &(pData->dataTracks),
                            HLA_TRACKING_REMOVE_NORMAL_DEAD_TRACKS
                           );

  /* remove full egomotion tracks */
  HLATrackSlamRemove( &(pData->dataCrossCorr),
                      &(pOutput->dataEgomotion.numTracksCrossCorr)
                    );

  /* remove target vehicles */
  HLATrackPairRemove( &(pOutput->pPairs),
                      &(pOutput->numPairs),
                      &(pData->dataPairs)
                    );

  /* -------------------------------------------------------------------------------------------------*/


  /* --------------------------------- PREDICT TRACKS ------------------------------------------------*/
  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* find the best combination of pairs and set the isTracked flag */
  HLATrackPairUpdateTrackedInPairFlag(pOutput->pPairs,
                                      &(pOutput->dataDebug),
                                      phlaDebugOutputs,
                                      &(pParam->paramPair),
                                      &(pData->dataPreComputed),
                                      pfGetTimestampuS32
                                     );

  /* reset association data */
  HLATracking3DAssocTrack2LightReset( pOutput->pTrack,
                                      pOutput->pPairs
                                    );

  /* predict SLAM */
  HLATrackSlamPredict(&(pOutput->dataEgomotion),
                      &(pOutput->dataCali),
                      &(pData->dataRotations),
                      &(pData->dataCrossCorr),
                      pInput->pMotionData,
                      pInput->pCamData,
                      &(pData->dataPreComputed),
                      pInput->eBrightnessState
                     );

  /* predict position of tracks */
  HLATrackPairPredict(pOutput->pPairs,
                      &(pOutput->dataEgomotion),
                      &(pData->dataRotations),
                      &(pData->dataPreComputed)
                     );

  HLATrackDynamicPredict( pOutput->pTrack,
                          &(pOutput->dataEgomotion),
                          &(pData->dataRotations),
                          &(pData->dataPreComputed),
                          &(pParam->paramMatching)
                        );

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackPredict_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
  /* -------------------------------------------------------------------------------------------------*/


  /* ---------------------------------- ASSOCIATE TRACK TO LIGHTS ------------------------------------*/
  /* !!!!   associate track to lights */
  TimeStart_us = pfGetTimestampuS32();

  /* associate lights to tracks */
  HLATracking3DAssocTrack2Light(pOutput->pTrack,
                                phlaDebugOutputs,
                                &(pData->dataTracks),
                                pInput->pDataHotPixels,
                                pInput->pSegOut,
                                pfGetTimestampuS32,
                                &(pData->dataPreComputed),
                                &(pParam->paramMeasurement),
                                &(pParam->paramMatching),
                                pInput->pCamData
                               );

  /* solve track2light association */
  HLATracking3DAssocTrack2LightSolve( phlaDebugOutputs,
                                      &(pData->dataTracks),
                                      &(pData->dataCrossCorr),
                                      pInput->pSegOut,
                                      pfGetTimestampuS32
                                    );

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackAssoc_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
  /* -------------------------------------------------------------------------------------------------*/


  /* ---------------------------------- UPDATE TRACKS AND EGOMOTION ----------------------------------*/
  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* update essential matrix */
  HLATrackSlamEstimateEssentialMatrix(pOutput->pTrack,
                                      &(pOutput->dataEgomotion),
                                      phlaDebugOutputs,
                                      &(pData->dataRotations),
                                      &(pData->dataPreComputed),
                                      &(pParam->paramMeasurement),
                                      pInput->pSegOut,
                                      pfGetTimestampuS32
                                     );

  /* update SLAM */
  HLATrackSlamUpdate( pfGetTimestampuS32,
                      &(pOutput->dataCali),
                      &(pOutput->dataEgomotion),
                      &(pData->dataRotations),
                      phlaDebugOutputs,
                      &(pData->dataCrossCorr),
                      &(pParam->paramCali),
                      &(pData->dataPreComputed),
                      &(pParam->paramMeasurement),
                      &(pParam->paramStaticTracker)
                    );

  /* update pairs */
  HLATracking3DUpdatePairs( pOutput->pPairs,
                            phlaDebugOutputs,
                            &(pOutput->dataEgomotion),
                            &(pData->dataRotations),
                            &(pData->dataPreComputed),
                            &(pParam->paramMeasurement),
                            &(pParam->paramDeath),
                            &(pParam->paramTTB),
                            pfGetTimestampuS32
                          );

  /* update tracks */
  HLATracking3DUpdateTracks(pOutput->pTrack,
                            phlaDebugOutputs,
                            pfGetTimestampuS32,
                            pInput->pSegOut,
                            &(pOutput->dataEgomotion),
                            &(pData->dataRotations),
                            &(pData->dataPreComputed),
                            &(pParam->paramAnalysis),
                            &(pParam->paramMeasurement),
                            &(pParam->paramDeath),
                            pInput->pCamData,
                            &(pParam->paramMatching),
                            &(pParam->paramStaticTracker),
                            &(pParam->paramTTB)
#ifdef PC_SIM
                            , &(pParam->paramDynamicTracker)
                            , &(pOutput->dataDebug)
#endif
                           );

  /* find tracks and pairs to remove */
  HLATracking3DFindTracksAndPairsToRemove(pOutput->pTrack,
                                          pOutput->pPairs,
                                          &(pData->dataPreComputed),
                                          &(pData->dataRotations),
                                          &(pParam->paramMeasurement)
                                         );

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackUpdate_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
  /* -------------------------------------------------------------------------------------------------*/


  /* ------------------------------------ ADD TRACKS  ------------------------------------------------*/
  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* add new tracks */
  HLATracking3DAddTracks( &(pOutput->pTrack),
                          &(pOutput->numTracks),
                          &(pData->dataTracks),
                          pInput->pSegOut,
                          &(pData->dataPreComputed),
                          &(pData->dataRotations),
#ifdef PC_SIM
                          &(pOutput->dataDebug),
#endif
                          &(pParam->paramMeasurement),
                          &(pParam->paramBirth)
                        );

  /* add new tracks for full egomotion */
  HLATrackSlamAdd(pOutput->pTrack,
                  &(pData->dataCrossCorr),
                  &(pOutput->dataEgomotion.numTracksCrossCorr),
                  &(pData->dataPreComputed),
                  &(pOutput->dataCali),
                  &(pOutput->dataEgomotion),
                  &(pData->dataRotations),
                  &(pParam->paramMeasurement)
                 );

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackAdd_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);

  /* ------------------------------------ ADD PAIRS  ------------------------------------------------*/
  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* add pair of tracks */
  HLATrackPairAdd(pOutput->pTrack,
                  &(pData->dataPreComputed),
                  &(pParam->paramMeasurement),
                  &(pData->dataRotations),
                  &(pOutput->pPairs),
                  &(pOutput->numPairs),
                  &(pData->dataPairs),
                  pInput->pCamData,
                  &(pData->dataTracks),
                  eTrafficStyle
                  );

  /* remove born dead tracks */
  HLATracking3DRemoveTracks(&(pOutput->pTrack),
                            &(pOutput->numTracks),
                            &(pData->dataTracks),
                            HLA_TRACKING_REMOVE_BORN_DEAD_TRACKS
                            );

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackAddPair_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
  /* -------------------------------------------------------------------------------------------------*/


  /* -------------------------------------- ANALYSIS FUNCTIONS  (COULD BE MOVED TO ANALYSIS) --------------------------------------*/

  /* time update for dynamic tracker for next cycle */
  HLATrackDynamicPredictNextCycle(pOutput->pTrack,
                                  &(pData->dataRotations),
                                  &(pOutput->dataEgomotion)
                                 );

  /* update lighting distance */
  HLALightDistUpdate( pOutput->pTrack,
                      pOutput->pPairs,
                      &(pData->dataPreComputed),
                      &(pData->dataRotations),
                      &(pParam->paramDistFromHeight),
                      &(pParam->paramPair),
                      &(pCpar_Hlar->DistEst)
                    );

}

/* **************************************************************************** 
  Functionname:     HLATracking3DInit                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATracking3DInit(       HLATracking3DOutput_t*      pOutput,
                              HLATracking3DData_t*        pData,
                        const HLA_t_FocalLength*          ps_FocalLength,
                        const HLA_t_LensCenter*           ps_LensCenter,
                        const HLA_t_SensorSocket*         ps_SensorSocket,
                        const HLA_t_Tracking3DParameters* pParam,
                        const CPAR_HLAR_Parameter_t*      pCPar_Hlar
                       )
{
  /* reset tracking data */
  (void)memset((void*)pData, 0, sizeof(HLATracking3DData_t));
  (void)memset((void*)pOutput, 0, sizeof(HLATracking3DOutput_t));

  /* init slam algo */
  HLATrackSlamInit( &(pOutput->dataCali),
                    &(pOutput->dataEgomotion),
                    &(pData->dataCrossCorr),
                    &(pData->dataRotations),
                    &(pParam->paramCali),
                    ps_SensorSocket
                  );

  /* pre-computed dta from parameters */
  HLATracking3DInitPreComputed( &(pData->dataPreComputed),
                                ps_FocalLength,
                                ps_LensCenter,
                                &(pParam->paramMatching),
                                &(pParam->paramStaticTracker),
                                &(pParam->paramDynamicTracker),
                                &(pParam->paramDistFromHeight),
                                &(pParam->paramEgomotion),
                                &(pParam->paramAnalysis),
                                pCPar_Hlar
                               );
  
  /* init track list */
  HLATracking3DInitTracks(&(pData->dataTracks));

  /* init target vehicle list */
  HLATrackPairInit( &(pData->dataPairs),
                    &(pData->dataPreComputed.dataAhead),
                    &(pData->dataPreComputed.dataOncoming),
                    &(pData->dataPreComputed.dataTruckLights),
                    &(pParam->paramPair),
                    &(pData->dataPreComputed)
                  );
}


/* **************************************************************************** 
  Functionname:     HLATracking3DInitTracks()                             */ /*!  
  Description:      
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
static void HLATracking3DInitTracks(HLATracking3DDataTracks_t* pDataTracks)
{
  uint8 i;
  HLATrack_t* pTrack;
  HLATrack_t* pTrackNext;

  /* init landmarks buffer */
  pTrack      = &(pDataTracks->free_tracked_lights_buffer[0]);
  pTrackNext  = &(pDataTracks->free_tracked_lights_buffer[1]);

  for(i = 0 ; i < (HLA_TRACKING_MAX_NUM_TRACKS-1) ; i++)
  {
    pTrack->next = pTrackNext;
    pTrack++;
    pTrackNext++;
  }

  /*last track */
  pTrack->next = 0;

  pDataTracks->pTrackedLightsBufferFree = &(pDataTracks->free_tracked_lights_buffer[0]);
}


/* **************************************************************************** 
  Functionname:     HLATracking3DInitPreComputed()                             */ /*!  
  Description:      Initialize Pre computed data from parameters
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
static void HLATracking3DInitPreComputed(       HLATracking3DDataPreComputed_t*           pDataPreComputed,
                                          const HLA_t_FocalLength*                        ps_FocalLength,
                                          const HLA_t_LensCenter*                         ps_LensCenter,
                                          const HLATracking3DParametersMatching_t*        pParamMatching,
                                          const HLATracking3DParametersStaticTracker_t*   pParamStatic,
                                          const HLATracking3DParametersDynamicTracker_t*  pParamDynamic,
                                          const HLATracking3DParametersDistFromHeight_t*  pParamDistFromHeight,
                                          const HLATracking3DParametersEgomotion_t*       pParamEgomotion,
                                          const HLATracking3DParametersAnalysis_t*        pParamAnalysis,
                                          const CPAR_HLAR_Parameter_t*                    pCPar_Hlar
                                        )
{

  float32 idmin,idmean;

  /* --------------------------------------------------------------------------------------------*/
  /* init uncertainty on static object depth */
  idmin = 1/pParamStatic->minTrackDist;
  idmean = 1/pParamStatic->initDistanceStatic;

  pDataPreComputed->dw_init = idmean;
  pDataPreComputed->cdd_init = (( idmin - idmean )*( idmin - idmean ))/9.0f;

  /* set the default max/min stat distance */
  pDataPreComputed->xwmax100_absolute = UI16_T_MAX;
  pDataPreComputed->xwmin100_absolute = (uint16)(pParamStatic->minTrackDist*100.0f);


  /* --------------------------------------------------------------------------------------------*/
  /* init variances for dynamic tracker */
  pDataPreComputed->odw_init    = -logf(pParamDynamic->initDistanceDynamic);
  pDataPreComputed->ofw_init = expf(pDataPreComputed->odw_init);

  pDataPreComputed->coff_init = pParamDynamic->codd_init*(pDataPreComputed->ofw_init*pDataPreComputed->ofw_init);
  pDataPreComputed->coss_init = (pParamDynamic->errXWVelocityInit * pParamDynamic->errXWVelocityInit)/9.0f;
  pDataPreComputed->coll_init = (pParamDynamic->errYWVelocityInit * pParamDynamic->errYWVelocityInit)/9.0f;

  pDataPreComputed->coss_proc = (pParamDynamic->errXWVelocityProc * pParamDynamic->errXWVelocityProc)/9.0f;
  pDataPreComputed->coll_proc = (pParamDynamic->errYWVelocityProc * pParamDynamic->errYWVelocityProc)/9.0f;

  /* set max covariance for dynamic tracker */
  pDataPreComputed->osxx_max = (pParamDynamic->maxErrHorizontalInPix*pParamDynamic->maxErrHorizontalInPix)/(9*(ps_FocalLength->f32_x)*(ps_FocalLength->f32_x));
  pDataPreComputed->osyy_max = (pParamDynamic->maxErrVerticalInPix*pParamDynamic->maxErrVerticalInPix)/(9*(ps_FocalLength->f32_y)*(ps_FocalLength->f32_y));


  /* set max reprojection error covariance */
  pDataPreComputed->sxxRMSE = ((pParamDynamic->maxRMSE/ps_FocalLength->f32_x)*(pParamDynamic->maxRMSE/ps_FocalLength->f32_x))/9.0f;
  pDataPreComputed->syyRMSE = ((pParamDynamic->maxRMSE/ps_FocalLength->f32_y)*(pParamDynamic->maxRMSE/ps_FocalLength->f32_y))/9.0f;

  /* min/max odw */
  pDataPreComputed->odw_min    = -logf(pParamDynamic->maxDistDynamic);
  pDataPreComputed->odw_max    = -logf(pParamDynamic->minDistDynamic);

  /* pre-calculated values for light-preprocessing acceleration */
  pDataPreComputed->invFX = 1/(ps_FocalLength->f32_x);
  pDataPreComputed->invFY = 1/(ps_FocalLength->f32_y);

  pDataPreComputed->factorCxx = 1.0f/(9.0f*(ps_FocalLength->f32_x)*(ps_FocalLength->f32_x));
  pDataPreComputed->factorCyy = 1.0f/(9.0f*(ps_FocalLength->f32_y)*(ps_FocalLength->f32_y));

  /* ~CodeReview ~ID:b7486c65007b295071c597dbd22710a7 ~Reviewer:CW01\uid28828 ~Date:26/03/2012 ~Priority:3 ~Comment:remove magic number */
  pDataPreComputed->factorMaxCxx = 1.0f/(9.0f*(4.0f*ps_FocalLength->f32_x)*(4.0f*ps_FocalLength->f32_x));

  pDataPreComputed->FX = ps_FocalLength->f32_x;
  pDataPreComputed->FY = ps_FocalLength->f32_y;
  pDataPreComputed->XO = ps_LensCenter->f32_x;
  pDataPreComputed->YO = ps_LensCenter->f32_y;

  /* variance on yaw rate */
  pDataPreComputed->varianceYawRate = (pParamEgomotion->errMaxYawRate*pParamEgomotion->errMaxYawRate)/9.0f;
  pDataPreComputed->varianceYawRateExtreme = (pParamEgomotion->extremeErrYawRate*pParamEgomotion->extremeErrYawRate)/9.0f;

  /* process noise on egomotion */
  pDataPreComputed->proc_epp      = (pParamEgomotion->errEgoPitchRadian*pParamEgomotion->errEgoPitchRadian)/9.0f;
  pDataPreComputed->proc_epp_ex   = (pParamEgomotion->extremeErrEgoPitchRadian*pParamEgomotion->extremeErrEgoPitchRadian)/9.0f;
  pDataPreComputed->proc_err      = (pParamEgomotion->errEgoRollRadian*pParamEgomotion->errEgoRollRadian)/9.0f;
  pDataPreComputed->proc_err_ex   = (pParamEgomotion->extremeErrEgoRollRadian*pParamEgomotion->extremeErrEgoRollRadian)/9.0f;

  /* factor flaot to int */
  pDataPreComputed->factorF2IDist = ((float32)(UI13_T_MAX))/pParamMatching->maxEuclDistAssocTrack2Light;

  /* distance from height hyppothesis */
  pDataPreComputed->qh = (pCPar_Hlar->DistEst.LightHeight_Min + pCPar_Hlar->DistEst.LightHeight_Max)/2.0f;
  pDataPreComputed->qd = (pParamDistFromHeight->minDist + pParamDistFromHeight->maxDist)/2.0f;

  pDataPreComputed->qqhh = ((pCPar_Hlar->DistEst.LightHeight_Max - pDataPreComputed->qh)*(pCPar_Hlar->DistEst.LightHeight_Max - pDataPreComputed->qh))/9.0f;
  pDataPreComputed->qqdd = ((pParamDistFromHeight->maxDist - pDataPreComputed->qd)*(pParamDistFromHeight->maxDist - pDataPreComputed->qd))/9.0f;

  /* delta low pass long term filter constant when trace time is >= numCyclesDlpLt */
  pDataPreComputed->h_dlp_lt_tcn = 1.0f/(float32)pParamAnalysis->numCyclesDlpLt;

  /* tangent of ttb angle */
  pDataPreComputed->tanaTTB = tanf(pCPar_Hlar->TTBEst.ttbAngle);
}


/* **************************************************************************** 
  Functionname:     HLATracking3DUpdateTrackBasics                                */ /*!  
  Description:      

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DUpdateTrackBasics(       HLATrack_t*                         pTrack,
                                            const HLAKalmanMeasPosPix_t*              pLPix,
                                            const HLATracking3DDataPreComputed_t*     pDataPreComputed,
                                            const HLATracking3DParametersAnalysis_t*  pParamAnalysis,
                                            const HLACameraData_t*                    pCamData
                                          )
{
  HLASegLight_t* pLight;

  /* delta_x/y filter */
  float32  xcenter_f, ycenter_f;
  float32  delta_x_f, delta_y_f;
  float32  dxnew, dynew;
  float32  hx, hy;
  float32  xcenter_last_f, ycenter_last_f;
  pLight = pTrack->light_ref;

  if(pLight != NULL)
  {
    /* reset lost time */
    pTrack->lost_time = 0;
    
    /* compute the intensity value low pass. */
    pTrack->MaxInt = pLight->MaxInt;

#ifdef PC_SIM
    /* Set the maximum intensity of the track. */
    if(pTrack->MaxIntOfTrack < pTrack->MaxInt)
    {
      pTrack->MaxIntOfTrack = pTrack->MaxInt;
    }
#endif

    /* running average of the max intensity */
    pTrack->AverageMaxInt = (uint16)CML_MinMax(0, (sint32)UI16_T_MAX, pTrack->AverageMaxInt + ((pTrack->MaxInt - pTrack->AverageMaxInt) / pTrack->track_time));

    /* saturation flag */
    pTrack->TrackingStatus.isAnyNGBSaturatedLastLight = pLight->Status.isAnyNGBSaturated;
    /* LED segmentation flag */
    pTrack->TrackingStatus.isPotLedLastLight = pLight->Status.isPotLed;
  }

  /* get pixel position inside ROI of the track (get the updated value) */
  xcenter_last_f = (float32)(pTrack->xcenter);
  ycenter_last_f = (float32)(pTrack->ycenter);

  /* use dynamic tracker for xcenter, ycenter */
  xcenter_f = (pTrack->ouk*pDataPreComputed->FX) + (pDataPreComputed->XO);
  ycenter_f = (pTrack->ovk*pDataPreComputed->FY) + (pDataPreComputed->YO);

  /* compute absolute position delta : align it on HLA cycle (robutness against frame lost) */
  delta_x_f = (xcenter_f - xcenter_last_f)*(pCamData->dFrameHLACycle_inv);
  delta_y_f = (ycenter_f - ycenter_last_f)*(pCamData->dFrameHLACycle_inv);

  /* store center on signed 16 bits */
  pTrack->xcenter = (sint16)CML_MinMax( SI16_T_MIN, SI16_T_MAX, CML_s_Round2Int(xcenter_f) );
  pTrack->ycenter = (sint16)CML_MinMax( SI16_T_MIN, SI16_T_MAX, CML_s_Round2Int(ycenter_f) );

  /* store deltax on signed 16 bits */
  pTrack->delta_x = (sint16)CML_MinMax( SI16_T_MIN, SI16_T_MAX, CML_s_Round2Int(delta_x_f) );
  pTrack->delta_y = (sint16)CML_MinMax( SI16_T_MIN, SI16_T_MAX, CML_s_Round2Int(delta_y_f) );


  /* filter delta_x */

  /* get the filter constants depending on track time */
  if(pTrack->track_time == 1)
  {
    hx = pParamAnalysis->h_dlp_tk1;
    hy = pParamAnalysis->h_dlp_tk1;
  }
  else if(pTrack->track_time==2)
  {
    hx = pParamAnalysis->h_dlp_tk2;
    hy = pParamAnalysis->h_dlp_tk2;
  }
  else
  {
    hx = pParamAnalysis->hx_dlp_tkn;
    hy = pParamAnalysis->hy_dlp_tkn;
  }

  /* get relevant delta_x update */
  if(pLPix != NULL)
  {
    dxnew = (pLPix->x_center_pix - xcenter_last_f)*(pCamData->dFrameHLACycle_inv);
    dynew = (pLPix->y_center_pix - ycenter_last_f)*(pCamData->dFrameHLACycle_inv);
  }
  else
  {
    dxnew = delta_x_f;
    dynew = delta_y_f;
  }

  /* filter delta_x */
  pTrack->delta_x_lp = (pTrack->delta_x_lp * (1.0f - hx)) + (dxnew * hx);
  pTrack->delta_y_lp = (pTrack->delta_y_lp * (1.0f - hy)) + (dynew * hy);

  /* long term delta_y filter */

  /* calculate constant filter */
  if(pTrack->trace_time < pParamAnalysis->numCyclesDlpLt)
  {
    hy = 1.0f/(float32)pTrack->trace_time;
  }
  else
  {
    hy = pDataPreComputed->h_dlp_lt_tcn;
  }

  /* filter delta_y */
  pTrack->delta_y_lp_lt = (pTrack->delta_y_lp_lt * (1.0f - hy)) + ((float32)(pTrack->delta_y) * hy);
}



/* **************************************************************************** 
  Functionname:     HLATracking3DIsATrackToRemove                            */ /*!  
  Description:      check if track should be removed next cycle


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static boolean HLATracking3DIsATrackToRemove(
#ifdef PC_SIM
                                              HLATrack_t*                           pTrack,
#else
                                              const HLATrack_t*                     pTrack,
#endif
                                              const HLATracking3DParametersDeath_t* pParamDeath,
                                              const HLACameraData_t*                pCamData
                                            )
{
  sint16  minx, maxx, miny, maxy;
  boolean bRet = b_FALSE;

  /* set image border for tracks */
  minx = (sint16)CML_MinMax(SI16_T_MIN,SI16_T_MAX, (sint32)pCamData->RoiX1 - pParamDeath->pixelMarginOutOfRoi);
  maxx = (sint16)CML_MinMax(SI16_T_MIN,SI16_T_MAX, (sint32)pCamData->RoiX2 + pParamDeath->pixelMarginOutOfRoi);
  miny = (sint16)CML_MinMax(SI16_T_MIN,SI16_T_MAX, (sint32)pCamData->RoiY1 - pParamDeath->pixelMarginOutOfRoi);
  maxy = (sint16)CML_MinMax(SI16_T_MIN,SI16_T_MAX, (sint32)pCamData->RoiY2 + pParamDeath->pixelMarginOutOfRoi);

  /* 2 times more lost time than trace time */
  if( (pTrack->lost_time + pTrack->lost_time) == pTrack->stageTrackDynamic.traceTimeToReinit)

  {
    bRet = b_TRUE;
#ifdef PC_SIM
    pTrack->DeathReason.isTooMuchRelativeLostTime = 1;
#endif
  }

  /* out of image */
  if(   ( pTrack->xcenter < minx )
     || ( pTrack->xcenter > maxx )
     || ( pTrack->ycenter < miny )
     || ( pTrack->ycenter > maxy ) 
    )
  {
    bRet = b_TRUE;
#ifdef PC_SIM
    pTrack->DeathReason.isOutOfImage = 1;
#endif
  }

  /* max lost time */
  if(pTrack->lost_time > pParamDeath->maxCyclesTrackLost)
  { 
    bRet = b_TRUE;
#ifdef PC_SIM
    pTrack->DeathReason.isTooMuchAbsoluteLostTime = 1;
#endif
  }

  /* very bad dynamic tracker */
  if( (uint8) pTrack->stageTrackDynamic.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
  {
    bRet = b_TRUE;
  }

  return(bRet);
}

/* **************************************************************************** 
  Functionname:     HLATracking3DIsAPairToRemove                            */ /*!  
  Description:      check if pair should be removed next cycle


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static uint16 HLATracking3DIsAPairToRemove( const HLAPair_t*                          pPair,
                                            const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair,
                                            const HLATracking3DParametersDeath_t*     pParamDeath
                                          )
{
  uint16  ret;
  float32 distd, dists, dista, distr;

  distd = HLA_CHI2_VALUE_N1;
  dists = HLA_CHI2_VALUE_N1;
  dista = HLA_CHI2_VALUE_N1;
  distr = HLA_CHI2_VALUE_N1;

  ret = 0;

  /*---------------------------------------------------------------------------------*/
  /* MAX_CYCLE_PAIR_LOST */ 
  if( pPair->lost_time_pair > pParamDeath->maxCyclesPairLost )
  {
    ret |= HLA_TV_DEATHREASON_MAX_CYCLE_PAIR_LOST;
  }
 
  /*---------------------------------------------------------------------------------*/
  if(   (pPair->bit_isTracked == 1)
     && (pPair->relVel > pParamDeath->minRelVelToUseMaxCyclePair)
    )
  {
    /* MAX_CYCLE_LEFT_TRACK_INPAIR */
    if( pPair->lost_time_left > pParamDeath->maxCyclesTrackLostInPair )
    {
      ret |= HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK_INPAIR;
    }

    /* MAX_CYCLE_RIGHT_TRACK_INPAIR */
    if( pPair->lost_time_right > pParamDeath->maxCyclesTrackLostInPair )
    {
      ret |= HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK_INPAIR;
    }
  }
  else
  {
    /* MAX_CYCLE_LEFT_TRACK */
    if( pPair->lost_time_left > pParamDeath->maxCyclesTrackLost )
    {
       ret |= HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK;
    }

    /* MAX_CYCLE_RIGHT_TRACK */
    if( pPair->lost_time_right > pParamDeath->maxCyclesTrackLost )
    {
      ret |= HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK;
    }
  }

  /*---------------------------------------------------------------------------------*/
  /* HLA_TV_DEATHREASON_PAIR_EARLY_DEATH : 2 times more lost time than trace time */
  if( (pPair->lost_time_pair + pPair->lost_time_pair) == pPair->trace_time_pair)
  {
    ret |= HLA_TV_DEATHREASON_PAIR_EARLY_DEATH;
  }

  /*---------------------------------------------------------------------------------*/
  /* HLA_TV_DEATHREASON_NOT_COMFIRMED_PAIR */
  /* ~CodeReview ~ID:476a3966f68aec01fb1ba0bdeb939c17 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:magic number */
  if(   (pPair->trace_time_pair <= 5)
     && (pPair->track_time_pair2 != (pPair->trace_time_pair * 2) )
    )
  {
    ret |= HLA_TV_DEATHREASON_NOT_COMFIRMED_PAIR;
  }

  /*---------------------------------------------------------------------------------*/
  /* check distance is correct */
  HLATrackUtilsMaha11(&distd,
                      pPair->pd - pDataPreComputedPair->pdEnd,
                      pPair->ppdd + pDataPreComputedPair->ppddEnd
                     );  
  if(distd > HLA_CHI2_VALUE_N1)
  {
    /* check also that this happens only for too close objects */
    /* ~CodeReview ~ID:c15f659ad7dba35ce525ad503be60896 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:missing comment in if branch */
    /* ~CodeReview ~ID:c15f659ad7dba35ce525ad503be60896 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:magic number */
    if(   (pPair->ppdd > 0)
       && ( (pPair->pd - ( 3.0f*sqrtf(pPair->ppdd) ) ) > ( 0.5f * pDataPreComputedPair->pdEnd ) )
      )
    {
      /* do nothing */
    }
    else
    {
      ret |= HLA_TV_DEATHREASON_PD_OUT_OF_RANGE;
    }
  }

  /*---------------------------------------------------------------------------------*/
  /* check speed is correct */
  HLATrackUtilsMaha11(&dists,
                      pPair->ps - pDataPreComputedPair->ps,
                      pPair->ppss + pDataPreComputedPair->ppss
                     );

  if(dists > HLA_CHI2_VALUE_N1)
  {
    ret |= HLA_TV_DEATHREASON_PS_OUT_OF_RANGE;
  }

  /*---------------------------------------------------------------------------------*/
  /* check roll */
  HLATrackUtilsMaha11(&distr,
                      pPair->pr  - pDataPreComputedPair->pr,
                      pPair->pprr  + pDataPreComputedPair->pprrEnd
                     );

  if(distr > HLA_CHI2_VALUE_N1)
  {
    ret |= HLA_TV_DEATHREASON_PR_OUT_OF_RANGE;
  }

  /*---------------------------------------------------------------------------------*/
  /* check luminosity constant is correct */
  HLATrackUtilsMaha11(&dista,
                      pPair->pa  - pDataPreComputedPair->pa,
                      pPair->ppaa  + pDataPreComputedPair->ppaa
                     );

  if(dista > HLA_CHI2_VALUE_N1)
  {
    ret |= HLA_TV_DEATHREASON_PA_OUT_OF_RANGE;
  }


  /*-----------------------------------------------------------------------------------*/
  /* check stability of the pair kalman filter */
  if( (uint8) pPair->stageTrackPair.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_FAIL)
  {
    ret |= HLA_TV_DEATHREASON_KALMAN_FAILED;
  }

  return(ret);
}



/* **************************************************************************** 
  Functionname:     HLATracking3DIsALightToStartNewTrack                            */ /*!  
  Description:      check if light can start a new track


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static boolean HLATracking3DIsALightToStartNewTrack(      HLASegLight_t*                  pLight,
                                                    const HLATracking3DParametersBirth_t* pParamBirth,
                                                    const HLATracking3DDataTracks_t*      pDataTracks
                                                   )
{
  boolean bStartNewTrack;

  /* reset output */
  /* ~CodeReview ~ID:89edb90d0132a79a83c22dc7dda7fcf5 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:boolean type requires b_FALSE, b_TRUE */
  bStartNewTrack = b_FALSE;
  pLight->Status.testPair = 0;

  /* look for non-associated lights */
  if(pLight->Status.associated == 0 )
  {
    pLight->Status.isInitializingTrack = 1;

    if(pLight->Status.DoNotStartNewTrack == 1)
    {
      /* NO NEW TRACK */
      bStartNewTrack = b_FALSE;
#ifdef PC_SIM
      pLight->newTrackAnalysis.noNewTrackReasonRedinWhiteRegion = 1;
#endif
    }
    else
    {
      if( pLight->pRegion->Status.IsRegionAboveROI == 1)
      {
        /* special feature for lights in the street lamp ROI */
        if(   (pLight->Status.isIsolatedLight == 1)
           && (pLight->Status.countInPredArea == 0)
          )
        {
          bStartNewTrack = b_TRUE;
#ifdef PC_SIM
          pLight->newTrackAnalysis.newTrackReasonIsolatedAboveROI = 1;
#endif
        }
        else
        {
          bStartNewTrack = b_FALSE;
#ifdef PC_SIM
          pLight->newTrackAnalysis.noNewTrackReasonNotIsolatedAboveROI = 1;
#endif
        }
      }
      else
      {
        boolean bHelp0 = b_FALSE; /* missed association */
        
        if(pLight->infoAssoc2Light[0].ID < HLA_TRACKING_MAX_NUM_TRACKS)
        {
          if(   (   (pLight->infoAssoc2Light[0].ui_dist < UI13_T_MAX)
                 && (pLight->LightID == pDataTracks->free_tracked_lights_buffer[pLight->infoAssoc2Light[0].ID].infoAssoc2Track[0].ID)
                )
             || (   (pLight->infoAssoc2Light[0].count > 0)
                 && (pDataTracks->free_tracked_lights_buffer[pLight->infoAssoc2Light[0].ID].light_ref == 0)
                )
            )
          {
            bHelp0 = b_TRUE;
          }
        }
        if(pLight->TrackID0 < HLA_TRACKING_MAX_NUM_TRACKS)
        {
          if(   (pLight->Status.countInPredArea == 1)
             && (pDataTracks->free_tracked_lights_buffer[pLight->TrackID0].light_ref == 0)
            )
          {
            bHelp0 = b_TRUE;
          }
        }

        if(bHelp0 == b_TRUE)
        {
          /* MAYBE MISSED ASSOCIATION: dont create new track */
          bStartNewTrack = b_FALSE;
#ifdef PC_SIM
          pLight->newTrackAnalysis.noNewTrackReasonMaybeMissed = 1;
#endif
        }
        else
        {
          if(pLight->Status.isIsolatedLight == 1)
          {
            uint8 MinR = (uint8)CML_u_Round2Uint(pParamBirth->MinR*UI8_T_MAX);
            uint8 MaxG = (uint8)CML_u_Round2Uint(pParamBirth->MaxG*UI8_T_MAX);
            uint8 MaxB = (uint8)CML_u_Round2Uint(pParamBirth->MaxB*UI8_T_MAX);

            /* ISOLATED LIGHT */
            if(pLight->MaxInt > pParamBirth->minLuxIntensity4newTrackIsolatedLight)
            {
              bStartNewTrack = b_TRUE;
#ifdef PC_SIM
              pLight->newTrackAnalysis.newTrackReasonIsolatedLight = 1;
#endif
            }
            /* red light */
            else if(   (pLight->current_R > MinR)
                    && (pLight->current_G < MaxG)
                    && (pLight->current_B < MaxB)
                    && (pLight->MaxInt > pParamBirth->minLuxIntensity4newRedTrackIsolatedLight)
                   )
            {
              bStartNewTrack = b_TRUE;
            }
            else 
            {
              /* NO TRACK: TOO DARK*/
              bStartNewTrack = b_FALSE;
#ifdef PC_SIM
              pLight->newTrackAnalysis.noNewTrackReasonNotBrightEnough = 1;
#endif
            }
          }
          else
          {
            /* NOT ISOLATED LIGHT */
            if(pLight->MaxInt <= pParamBirth->minLuxIntensity4newTrack)
            {
              /* NO TRACK: TOO DARK*/
              bStartNewTrack = b_FALSE;
#ifdef PC_SIM
              pLight->newTrackAnalysis.noNewTrackReasonNotBrightEnough = 1;
#endif
            }
            else
            {
              if(pLight->Status.countInPredArea == 0)
              {
                if(   (pLight->Status.isOPLight == 1)
                  &&  (pLight->pRegion->Status.IsAssToTrack == 1)
                  )
                {
                  bStartNewTrack = b_FALSE;
#ifdef PC_SIM
                  pLight->newTrackAnalysis.noNewTrackReasonOtherOPAssociated = 1;
#endif
                }
                else
                {
                  /* NEW TRACK:  NOT IN ANY TRACK PREDICTION AREA */
                  bStartNewTrack = b_TRUE;
#ifdef PC_SIM
                  pLight->newTrackAnalysis.newTrackReasonNotInPredArea = 1;
#endif
                }
              }
              else if(pLight->Status.countInPredArea == 1)
              {
                boolean bHelp1 = b_FALSE;
                /* check case where one track for two lights */
                /* check if it can be a pair */

                if(pLight->TrackID0 < HLA_TRACKING_MAX_NUM_TRACKS)
                {
                  if(pDataTracks->free_tracked_lights_buffer[pLight->TrackID0].infoAssoc2Track[0].count > 2)
                  {
                   bHelp1 = b_TRUE;
                  }
                }
                

                /* do not test pair on regions already associate with pairs */
                if(bHelp1 == b_TRUE)
                {
                  /* light cannot be inside a pair */
                  bStartNewTrack = b_FALSE;
                  pLight->Status.testPair = 0;
#ifdef PC_SIM
                  pLight->newTrackAnalysis.noNewTrackReasonClosestTrackForMoreThan2Light = 1;
#endif
                }
                else
                {
                  /* TEST if light can be inside a pair (see ADDPAir algo) */
                  bStartNewTrack = b_TRUE;
                  pLight->Status.testPair = 1;
                }
              }          
              else
              {
                /* LIGHT IS INSIDE TOO MANY TRACK PREDICTION AREA */
                bStartNewTrack = b_FALSE;

#ifdef PC_SIM
                pLight->newTrackAnalysis.noNewTrackReasonIn2ManyPredArea = 1;
#endif
              }
            }
          }
        }
      }
    }
  }

#ifdef PC_SIM
  pLight->newTrackAnalysis.setupNewTrack = bStartNewTrack;
#endif

  return(bStartNewTrack);
}

/* **************************************************************************** 
  Functionname:     HLATracking3DAddTracks                     */ /*!  
  Description:      

                    

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DAddTracks(       HLATrack_t**                          ppTrackStart,
                                          uint8*                                pnumTracks,
                                          HLATracking3DDataTracks_t*            pDataTracks,
                                    const HLASegOut_t*                          pSegOut,
                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed, 
                                    const HLATracking3DDataRotations_t*         pDataRotations,
#ifdef PC_SIM
                                    const HLATracking3DDataDebug_t*             pDataDebug,
#endif
                                    const HLATracking3DParametersMeasurement_t* pParamMeas,
                                    const HLATracking3DParametersBirth_t*       pParamBirth
                                  )
{
  uint8                 iLight;
  HLASegLight_t*        pLightStart = &pSegOut->Light[0];
  HLAKalmanMeasPos_t    lightPosNorm;
  HLAKalmanMeasPosPix_t lightPosPix;
    
  /* local variable */
  uint8       CountNumberOfNewTracks;
  HLATrack_t* pTrack;

  /* count number of new tracks */
  CountNumberOfNewTracks = 0;

  /* add new landmark */
  iLight = pSegOut->iLight;
  while (   (pDataTracks->pTrackedLightsBufferFree != 0)                     /* check there are free slots */
         && (iLight < HLA_SEG_MAX_NUM_LIGHTS)
         && (CountNumberOfNewTracks < pParamBirth->MaxNumberOfNewTracks)     /* check there are not too much new lights */
        )
  {
    HLASegLight_t* pLight = &pLightStart[iLight];

    boolean bStartNewTrack = HLATracking3DIsALightToStartNewTrack(pLight,
                                                                  pParamBirth,
                                                                  pDataTracks
                                                                 );

    if(bStartNewTrack == b_TRUE)
    {
      /* is new track */
      CountNumberOfNewTracks++;

      /* manage ROLLING BUFFER */

      /*  get next free TrackListnode */
      pTrack = pDataTracks->pTrackedLightsBufferFree;
      pDataTracks->pTrackedLightsBufferFree = pDataTracks->pTrackedLightsBufferFree->next;

      /*!! RESET NEW TRACK !! */
      (void)memset((void*)pTrack, 0, sizeof(HLATrack_t));
      
      /* add new elemt as first elemt of tracking list */
      pTrack->next = (*ppTrackStart);

      /* return tracked_lights */
      (*ppTrackStart) = pTrack;

      /* tell light is associated */
      pLight->Status.associated  = 1;
      pTrack->light_ref = pLight;

      /* check new track has to be teset by the pair detection algo */
      if(pLight->Status.testPair == 1)
      {
        pTrack->TrackingStatus.testPairForBirth = 1;
        pTrack->TrackingStatus.willBeRemoved = 1;
      }

      /* incremente counter landmarks */
      (*pnumTracks)++;

      /* initialize trace/track times */
      pTrack->track_time = 1;
      pTrack->trace_time = 1;
      
      /* ttb */
      pTrack->ttb = 0.0f;           /* should be HLA_MIN_TTB */

      /* intensity */
      pTrack->MaxInt          = pLight->MaxInt;
#ifdef PC_SIM
      pTrack->MaxIntFirst     = pLight->MaxInt;
      pTrack->MaxIntOfTrack   = pLight->MaxInt;
#endif
      pTrack->AverageMaxInt = pLight->MaxInt;

      /* preprocess light */
      HLATrackMeasGetNormAndPixCoordinates( &lightPosNorm,
                                            &lightPosPix,
                                            pLight,
                                            pDataPreComputed,
                                            pParamMeas
                                          );

      /* initialize landmark state */
      HLATrackStaticKalmanInit( pTrack,
                                &lightPosNorm,
                                pDataPreComputed,
                                pDataRotations
                              );

      HLATrackDynamicKalmanInit(pTrack,
                                &lightPosNorm,
                                pDataPreComputed,
                                pDataRotations
                               );

      /* save image coordinates */
      pTrack->ouk  = lightPosNorm.x;
      pTrack->ovk  = lightPosNorm.y;

      /* get image coordinates */
      pTrack->xcenter = (sint16)CML_s_Round2Int(lightPosPix.x_center_pix);
      pTrack->ycenter = (sint16)CML_s_Round2Int(lightPosPix.y_center_pix);

      /* initialize matching data */
      HLATrackMeasInitMatchingData( pTrack,
                                    pLight
                                  );

      /* retain first position of the track */
      pTrack->xcenter_FD = pTrack->xcenter;
      pTrack->ycenter_FD = pTrack->ycenter;

      /* classify track as infinite */
      pTrack->statusAnalysisMisc.isInfinite = 1;

      /* init state machine for dynamic object detection */
      pTrack->TrackerClass = HLA_TRACKING3D_TRACKERCLASS_UNKNOWN;

      /* 3D estimate is correct */
      pTrack->statusAnalysisMisc.is3DCorrect = 1;

      /* set isLeavingStreetLamp */
      pTrack->statusAnalysisMisc.isLeavingStreetLamp = 0;

      pTrack->TrackID = (uint8)(  ((uint32)pTrack - (uint32)(&pDataTracks->free_tracked_lights_buffer[0]))/ sizeof( HLATrack_t ) );

#ifdef PC_SIM
      pTrack->numFrameStart = pDataDebug->numFrame;
      pTrack->numFrameEnd = pDataDebug->numFrame;

      /* set global light counter */
      pTrack->lightCount = pDataTracks->HLAGlobalLightCount;
      pDataTracks->HLAGlobalLightCount++;
#endif

    }
    /* go to next light */
    iLight = pLight->iLightNext;
  }

#ifdef PC_SIM
  iLight = pSegOut->iLight;
  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    HLASegLight_t* pLightTemp = &pLightStart[iLight];

    /* store preprocessed data */
    HLATrackMeasGetPixCoordinates(&(pLightTemp->posPix),
                                  pLightTemp,
                                  pParamMeas
                                 );

    /* go to next light */
    iLight = pLightTemp->iLightNext;
  }
#endif
}


/* **************************************************************************** 
  Functionname:     HLATracking3DClassifyTrackAsDynamicOrStatic                            */ /*!  
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DClassifyTrackAsDynamicOrStatic(      HLATrack_t*                         pTrack,
                                                        const HLATracking3DParametersAnalysis_t*  pParamAnalysis,
                                                        const HLATracking3DDataEgomotion_t*       pDataEgomotion
                                                        )
{
  float32 dwmax;
  float32 dwmin;
  float32 dwdelta;

  /* reset lost_time_static and count_static depending on type of association, tracker class and 3D estimate quality*/
  if(pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_UNKNOWN)
  {
    /* check if track can be classified static */
    if(   (pTrack->countRobustStatic>pParamAnalysis->minNumFrameFromUnknownToStatic)
       && (pTrack->statusAnalysisVehicle.isVehicleAhead == 0)
       && (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 0)
       && (pTrack->statusAnalysisVehicle.isVehicleOncoming == 0)
       && (fabsf(pDataEgomotion->ego_speed) > pParamAnalysis->minSpeedToAddSlamFeatures )
      )
    {
      pTrack->TrackerClass = HLA_TRACKING3D_TRACKERCLASS_STATIC;
    }
    else
    {
      if(pTrack->cdd > 0)
      {
        dwdelta = 3.0f*sqrtf(pTrack->cdd);
        dwmax = pTrack->dw + dwdelta;
        dwmin = pTrack->dw - dwdelta;

        /* test to check if static distance estimation is strongly converging to a negative depth value */
        if(   ((dwmax - dwmin) < (dwmax * ( -pParamAnalysis->minRatioStaticDepthConvergence )) )
           && (pTrack->stageTrackStatic.winTime>=pParamAnalysis->minNumFrameFromUnknownToDynamic)
          )
        {
          pTrack->TrackerClass = HLA_TRACKING3D_TRACKERCLASS_DYNAMIC;
        }
      }
    }
  }
  else if(pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_STATIC)
  {
    /* check if track class should be moved to UNKNOWN */
    if(  (   (pTrack->pFullEgoData != 0)
          && (pTrack->pFullEgoData->stageTrackSlam.lostTime > pParamAnalysis->minNumFrameFromStaticToUnknown)
         )
      || (pTrack->statusAnalysisVehicle.isVehicleAhead == 1)
      || (pTrack->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1)
      || (pTrack->statusAnalysisVehicle.isVehicleOncoming == 1)
      /* remove static flag if track is the only static feature and if it's estimated close to camera. Goal is to avoid over-estimation of ego_pitch due to only one track */
      || (   (pDataEgomotion->numTracksCrossCorr == 1)
          && (pTrack->pFullEgoData != 0)
          && (pTrack->pFullEgoData->dw > pParamAnalysis->minDwForLonelyStaticTrack )
         )
      /* remove static flag if track is the only static feature and if it's far above horizon (for example truck lights). Goal is to avoid over-estimation of ego_pitch due to only one track */
      || (   (pDataEgomotion->numTracksCrossCorr == 1)
          && (pTrack->pFullEgoData != 0)
          && (pTrack->statusAnalysisMisc.isFarAboveHorizon == 1)
         )
      /* remove static flag for all tracks when vehicle is at low speed */
      || (fabsf(pDataEgomotion->ego_speed) < pParamAnalysis->minSpeedToKeepSlamFeatures )
      )
    {
      pTrack->TrackerClass = HLA_TRACKING3D_TRACKERCLASS_UNKNOWN;

      /* remove track from full egomotion track list*/
      if(pTrack->pFullEgoData != NULL)
      {
        pTrack->pFullEgoData->pTrack = 0;
        pTrack->pFullEgoData = 0;
      }
    }

  }
  else if(pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_DYNAMIC)
  {
    /* ~CodeReview ~ID:11aaf43e147d26034f619921d26be699 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:commented code */
    /* check if track class should be moved to UNKNOWN */
    /*if(pT->stageTrackStatic.trackTimeToReinit>pParamAnalysis->minNumFrameFromDynamicToUnknown)
    {
      pT->TrackerClass = HLA_TRACKING3D_TRACKERCLASS_UNKNOWN;
    }*/
  }
  else
  {
    /* Do nothing */
  }
}


/* **************************************************************************** 
  Functionname:     HLATracking3DUpdateTracks                            */ /*!  
  Description:      update tracks
                    - check if track has to be removed
                    - check if track is static or dynamic
                    - check if track should be added/removed from full ego list


  @param[in]        seg_TrackListnode* pTLB: track to remove

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DUpdateTracks(      HLATrack_t*                             pTrackStart,
                                            HLADebugOutputs_t*                      phlaDebugOutputs,
                                            AS_t_GetTimestampuS32                   pfGetTimestampuS32,
                                      const HLASegOut_t*                            pSegOut,
                                      const HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                      const HLATracking3DDataRotations_t*           pDataRotations,
                                      const HLATracking3DDataPreComputed_t*         pDataPreComputed, 
                                      const HLATracking3DParametersAnalysis_t*      pParamAnalysis, 
                                      const HLATracking3DParametersMeasurement_t*   pParamMeas,
                                      const HLATracking3DParametersDeath_t*         pParamDeath,
                                      const HLACameraData_t*                        pCamData,
                                      const HLATracking3DParametersMatching_t*      pParamMatching,
                                      const HLATracking3DParametersStaticTracker_t* pParamStatic,
                                      const HLATracking3DParametersTTB_t*           pParamTTB
#ifdef PC_SIM
                                    , const HLATracking3DParametersDynamicTracker_t* pParamDynamic
                                    ,       HLATracking3DDataDebug_t*                pDataDebug
#endif
                                  )
{
  HLATrack_t*             pTrack;
  uint32                  TimeStart_us;

  HLAKalmanMeasPos_t      lightPosNorm;
  HLAKalmanMeasPosPix_t   lightPosPix;
  HLAKalmanMeasPos_t*     pLightNorm;
  HLAKalmanMeasPosPix_t*  pLightPix;

  HLASegLight_t*          pLightBackUp;
  uint8                   LightID;
  float32                 dx, dy, dist_dynamic;

  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    /* preprocess light */
    pLightNorm = 0;
    pLightPix = 0;
    LightID = 255;
    if(pTrack->light_ref != NULL)
    {
      LightID = pTrack->light_ref->LightID;

      /* preprocess light */
      HLATrackMeasGetNormAndPixCoordinates( &lightPosNorm,
                                            &lightPosPix,
                                            pTrack->light_ref,
                                            pDataPreComputed,
                                            pParamMeas
                                          );

      /* update pointers */
      pLightNorm = &lightPosNorm;
      pLightPix = &lightPosPix;
    }

    /* update dynamic kalman filter */
    HLATrackDynamicKalmanUpdate(pTrack,
                                pLightNorm,
                                pDataEgomotion,
                                pDataRotations,
                                pDataPreComputed
#ifdef PC_SIM
                              , pParamDynamic
#endif
                               );
    

    /* if meas failed then remove the association */
    if(   (pTrack->light_ref != 0)
       && (pTrack->TrackingStatus.isAssocFromPair == 0)
       && (pTrack->TrackingStatus.isAssocToRemove == 1)
      )
    {
      HLATrackMeasRemoveMeasurement(pTrack);
      pLightNorm = 0;
      pLightPix = 0;

      /* try back up association solution */
      if(   (pTrack->infoAssoc2Track[0].count > 1)
         && (pTrack->infoAssoc2Track[1].ID != LightID)
         && (pTrack->stageTrackDynamic.statusPred == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
        )
      {
        pLightBackUp = &(pSegOut->pLightMemoryStart[pTrack->infoAssoc2Track[1].ID]);

        if(   (pLightBackUp->Status.associated == 0)
           && (pLightBackUp->infoAssoc2Light[0].ID == pTrack->TrackID)
          )
        {            
          /* preprocess light */
          HLATrackMeasGetNormAndPixCoordinates( &lightPosNorm,
                                                &lightPosPix,
                                                pLightBackUp,
                                                pDataPreComputed,
                                                pParamMeas
                                              );

          /* calculate dynamic distance from light to track */
          dx = lightPosNorm.x - pTrack->ox_p;
          dy = lightPosNorm.y - pTrack->oy_p;

          HLATrackUtilsMaha22(&dist_dynamic,
                              dx,
                              dy,
                              lightPosNorm.cxx + pTrack->osxx,
                              lightPosNorm.cyy + pTrack->osyy,
                              pTrack->osxy
                             );

          /* add association in this case */
          if(   (dist_dynamic < HLA_CHI2_VALUE_N2)
             && (dist_dynamic >= 0.0f)
            )
          {
            HLATrackMeasAddMeasurement( pTrack,
                                        pLightBackUp,
                                        UI13_T_MAX
                                      );

            pTrack->TrackingStatus.isAssocToRemove = 0;

            /* update pointers */
            pLightNorm = &lightPosNorm;
            pLightPix = &lightPosPix;
          }
        }
      }
    }

    /* update static kalman filter */
    HLATrackStaticKalmanUpdate( pTrack,
                                pLightNorm,
                                pDataEgomotion,
                                pDataRotations,
                                pDataPreComputed,
                                pParamStatic
                              );

    /* classify track as dynamic or static */
    HLATracking3DClassifyTrackAsDynamicOrStatic(pTrack,
                                                pParamAnalysis,
                                                pDataEgomotion
                                               );

    /* update track basics (lost_time, image position, deltax/deltay ...) */
    HLATracking3DUpdateTrackBasics( pTrack,
                                    pLightPix,
                                    pDataPreComputed,
                                    pParamAnalysis,
                                    pCamData
                                  );

    /* update matching data */
    if(   (pTrack->stageTrackDynamic.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
       && (pTrack->light_ref != 0)
      )
    {
      HLATrackMeasUpdateMatchingData( pTrack,
                                      pTrack->light_ref,
                                      pParamMatching
                                    );
    }

    /* update ttb */
    if(pTrack->TrackingStatus.isTTBFromPair == 0)
    {
      HLATrackModelTTB( &(pTrack->ttb18),
                        pTrack->ouw,
                        pTrack->ofw,
                        pTrack->os,
                        pTrack->ol,
                        pDataEgomotion->ego_speed,
                        pDataEgomotion->ego_yawrate,
                        pDataPreComputed->tanaTTB,
                        pParamTTB->maxTTB
                      );
    }

    /* check we have to remove track */
    pTrack->trackDeathAnalysis = HLATracking3DIsATrackToRemove( pTrack,
                                                                pParamDeath,
                                                                pCamData
                                                              );

#ifdef PC_SIM
    /* udpate track frame counter */
    pTrack->numFrameEnd = pDataDebug->numFrame;
#endif

    pTrack = pTrack->next;
  }
 

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackUpdateTracks_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}


/* **************************************************************************** 
  Functionname:     HLATracking3DUpdatePairBasics                            */ /*!  
  Description:      
                    

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DUpdatePairBasics(HLAPair_t* pPair)
{
  HLASegLineRegion_t* pRegion1;
  HLASegLineRegion_t* pRegion2;
  uint8 shareRegion;

  /* set lost time */
  if(   (pPair->lost_time_left == 0)
     || (pPair->lost_time_right == 0)
    )
  {
    pPair->lost_time_pair = 0;
  }

  /* set track time2 */
  if(pPair->lost_time_left == 0)
  {
    if(pPair->track_time_pair2 < UI16_T_MAX)
    {
      pPair->track_time_pair2++;
    }
  }

  if(pPair->lost_time_right == 0)
  {
    if(pPair->track_time_pair2 < UI16_T_MAX)
    { 
      pPair->track_time_pair2++;
    }
  }


  /* update bit_bornFromPairTest as long as both tracks shares the same region */
  if(pPair->bit_bornFromPairTest == 1)
  {
    if(   (pPair->pTRight->light_ref != 0)
       && (pPair->pTLeft->light_ref != 0)
      )
    {
      pRegion1 = pPair->pTRight->light_ref->pRegion->pRegionBelow; 
      
      shareRegion = 0;

      while(pRegion1 != NULL)
      {
        pRegion2 = pPair->pTLeft->light_ref->pRegion->pRegionBelow;
        while(pRegion2 != NULL)
        {
          if(pRegion1==pRegion2)
          {
            shareRegion = 1;
          }

          pRegion2 = pRegion2->pRegionBelow;
        }

        pRegion1 = pRegion1->pRegionBelow;
      }

      if(shareRegion==0)
      {
        pPair->bit_bornFromPairTest = 0;
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLATracking3DUpdatePairs                            */ /*!  
  Description:      
                    

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DUpdatePairs(       HLAPair_t*                            pPairStart,
                                            HLADebugOutputs_t*                    phlaDebugOutputs,
                                      const HLATracking3DDataEgomotion_t*         pDataEgomotion,
                                      const HLATracking3DDataRotations_t*         pDataRotations,
                                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                      const HLATracking3DParametersMeasurement_t* pParamMeas,
                                      const HLATracking3DParametersDeath_t*       pParamDeath,
                                      const HLATracking3DParametersTTB_t*         pParamTTB,
                                      AS_t_GetTimestampuS32                       pfGetTimestampuS32
                                    )
{
  HLAPair_t* pPair;
  uint32 TimeStart_us;
  const HLATracking3DDataPreComputedPair_t* pDataPreComputedPair;

  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* update target vehicles state */
  pPair = pPairStart;
  while(pPair != NULL)
  {
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

    /* update kalman pair */
    HLATrackPairUpdate( pPair,
                        pDataEgomotion,
                        pDataRotations,
                        pDataPreComputed,
                        pDataPreComputedPair,
                        pParamMeas,
                        pParamTTB
                      );

    /* update pair basics */
    HLATracking3DUpdatePairBasics(pPair);

    /* check if pair has to be removed and why */
    pPair->pairDeathAnalysis = HLATracking3DIsAPairToRemove(pPair,
                                                            pDataPreComputedPair,
                                                            pParamDeath
                                                           );

    /* propagate pair deat info to corresponding tracks */
    if(pPair->pairDeathAnalysis > 0)
    {
      if(pPair->bit_isTracked == 1)
      {
        pPair->pTLeft->TrackingStatus.isTrackedPairToRemove = 1;
        pPair->pTRight->TrackingStatus.isTrackedPairToRemove = 1;
      }

      if(   (pPair->bit_bornFromPairTest == 1)
         && (   ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_PAIR_EARLY_DEATH)      != 0)
             || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_NOT_COMFIRMED_PAIR)    != 0)
             || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_LEFT_TRACK_REMOVED)    != 0)
             || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_RIGHT_TRACK_REMOVED)   != 0)
             || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK)  != 0)
             || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK) != 0)
            )
        )
      {
        /* remove the only the newest one */
        if(pPair->pTLeft->TrackingStatus.isBornFromPairTest == 1)
        {
          pPair->pTLeft->TrackingStatus.deathDueToBornFromPairTest = 1;

          /* prevent track death for lost time for the other track */
          if(pPair->pTRight->lost_time > 0)
          {
            pPair->pTRight->lost_time = 1;
          }
        }
        /* remove the only the newest one */
        if(pPair->pTRight->TrackingStatus.isBornFromPairTest == 1)
        {
          pPair->pTRight->TrackingStatus.deathDueToBornFromPairTest = 1;

          /* prevent track death for lost time for the other track */
          if(pPair->pTLeft->lost_time > 0)
          {
            pPair->pTLeft->lost_time = 1;
          }
        }
      }
    }
    /* get next pair */
    pPair = pPair->next;
  }
  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackUpdatePair_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}


/* **************************************************************************** 
  Functionname:     HLATracking3DFindTracksAndPairsToRemove                            */ /*!  
  Description:     

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DFindTracksAndPairsToRemove(      HLATrack_t*                           pTrackStart,
                                                          HLAPair_t*                            pPairStart,
                                                    const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                                    const HLATracking3DDataRotations_t*         pDataRotations,
                                                    const HLATracking3DParametersMeasurement_t* pParamMeas
                                                   )
{
  HLATrack_t* pTrack;
  HLAPair_t*  pPair;


  /* --------------------------------------------------------------*/
  /* First check tracks sure to be removed */
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    if(   (   (pTrack->TrackingStatus.isTrackedInPair == 0)
           && (pTrack->trackDeathAnalysis == 1)
          )
       || (   (pTrack->TrackingStatus.isTrackedPairToRemove == 1)
           && (pTrack->trackDeathAnalysis == 1)
          )
       || (pTrack->TrackingStatus.deathDueToBornFromPairTest == 1)
      )
    {
      pTrack->TrackingStatus.willBeRemoved = 1;
    }
    else
    {
      pTrack->TrackingStatus.willBeRemoved = 0;
    }

    pTrack = pTrack->next;
  }

  /* --------------------------------------------------------------*/
  /* check pairs */
  pPair = pPairStart;
  while(pPair != NULL)
  {       
    /* update pairDeathAnalysis with the track remove infos */

    /* LEFT_TRACK_REMOVED */
    if(pPair->pTLeft->TrackingStatus.willBeRemoved == 1)
    {
      pPair->pairDeathAnalysis |= HLA_TV_DEATHREASON_LEFT_TRACK_REMOVED;
    }

    /* RIGHT_TRACK_REMOVED */
    if(pPair->pTRight->TrackingStatus.willBeRemoved == 1)
    {
      pPair->pairDeathAnalysis |= HLA_TV_DEATHREASON_RIGHT_TRACK_REMOVED;
    }

    /* check if tracks have to be removed also */
    if(pPair->pairDeathAnalysis > 0)
    {
      pPair->bit_willBeRemoved = 1;

      /* reinit dynamic tracker with pair when it's a good pair and pair death is only due to failure of ONE track*/
      if(   (pPair->bit_isTracked == 1)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_PAIR_LOST) == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_PAIR_EARLY_DEATH)    == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_NOT_COMFIRMED_PAIR)  == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_PD_OUT_OF_RANGE)     == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_PS_OUT_OF_RANGE)     == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_PA_OUT_OF_RANGE)     == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_PR_OUT_OF_RANGE)     == 0)
         && ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_KALMAN_FAILED)       == 0)
        )
      {
        if(   ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK_INPAIR) != 0)
           || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_RIGHT_TRACK)        != 0)
           || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_RIGHT_TRACK_REMOVED)          != 0)
          )
        {
          /* right track is lost: reinit left track */
          HLATrackDynamicKalmanInitFromPair(pPair->pTLeft, 
                                            pPair,
                                            pDataPreComputed, 
                                            pDataRotations,
                                            pParamMeas
                                           );
        }

        if(   ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK_INPAIR) != 0)
           || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_MAX_CYCLE_LEFT_TRACK)        != 0)
           || ( (pPair->pairDeathAnalysis & HLA_TV_DEATHREASON_LEFT_TRACK_REMOVED)          != 0)
          )
        {
          /* left track is lost: reinit right track */
          HLATrackDynamicKalmanInitFromPair(pPair->pTRight, 
                                            pPair,
                                            pDataPreComputed, 
                                            pDataRotations,
                                            pParamMeas
                                           );
        }
      }
    }

    pPair = pPair->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLATracking3DRemoveTracks                            */ /*!  
  Description:      remove tracks


  @param[in]        seg_TrackListnode* pTLB: track to remove

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DRemoveTracks(        HLATrack_t**                ppTrackStart,
                                              uint8*                      pNumTracks,
                                              HLATracking3DDataTracks_t*  pDataTracks,
                                      const  uint8                        removeBornDeadTracks
                                     )
{
  HLATrack_t* pTrack      = (*ppTrackStart);
  HLATrack_t* pTrackNext  = 0;
  HLATrack_t* pTrackPrev  = 0;

  while(pTrack != NULL)
  {
    /* ~CodeReview ~ID:f58f6bff00ca5a951e5b98d44a00879f ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:commented out code */
    /* if(pT->n_hot==0) */ /* TODO: if not hot pixel */
    {
      if(   (pTrack->TrackingStatus.willBeRemoved == 1)
         && (   (removeBornDeadTracks == HLA_TRACKING_REMOVE_NORMAL_DEAD_TRACKS)
             || (   (removeBornDeadTracks == HLA_TRACKING_REMOVE_BORN_DEAD_TRACKS)
                 && (pTrack->trace_time == 1)
                )
            )
        )
      {
        /* ~CodeReview ~ID:6213c7f3c53891c59e04aecde3a44ef8 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:possible underflow when pNumTracks = 0 */
        (*pNumTracks)--;

        /* save next track pointer in track list. */
        pTrackNext = pTrack->next;

        /* save the next-in-list track to the previous track. */
        if(pTrackPrev != NULL)
        {
          pTrackPrev->next = pTrack->next;
        }
        else
        {
          (*ppTrackStart) = pTrack->next;
        }
      
        /* if light hash changes, pixel is not hot */
        /* ~CodeReview ~ID:d44f475c2bbba632a1afb5cd2cb6c0b0 ~Reviewer:CW01\uid28828 ~Date:26/03/2012 ~Priority:3 ~Comment:remove reset of hot pixels features */
        pTrack->countHotTrack = 0;
        pTrack->LightHash = 0;

        /* break link wih full egomotion tracks */
        if(pTrack->pFullEgoData != NULL)
        {
          pTrack->pFullEgoData->pTrack = 0;
          pTrack->pFullEgoData = 0;
        }

        /* break pair link from dist estimation */
        if (pTrack->dist_est_pair_link != NULL)
        {
          pTrack->dist_est_pair_link->dist_est_pair_link = 0;
          pTrack->dist_est_pair_link->TrackingStatus.isLinked2Pair = 0;
          pTrack->dist_est_pair_link->TrackingStatus.isTrackedInPair = 0;
          pTrack->TrackingStatus.isLinked2Pair = 0;
          pTrack->TrackingStatus.isTrackedInPair = 0;
        }

        /* remove the associated flag for born dead tracks */
        if(removeBornDeadTracks == HLA_TRACKING_REMOVE_BORN_DEAD_TRACKS)
        {
          if(pTrack->light_ref != NULL)
          {
            pTrack->light_ref->Status.associated = 0;
          }
        }

        /* add removed tracks to the beginning of free tracked lights list. */
        pTrack->next = pDataTracks->pTrackedLightsBufferFree;
        pDataTracks->pTrackedLightsBufferFree = pTrack;

        /* move the pointer to the next track. */
        pTrack = pTrackNext;
      }
      else
      {
        pTrackPrev = pTrack;
        pTrack = pTrack->next;
      }
    }
    /* ~CodeReview ~ID:a721c5d004f0995b875857614d729e85 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:commented out code */
    /*else
    {
      pTprev = pT;
      pT = pT->next;
    }*/
  }
}

/* **************************************************************************** 
  Functionname:     HLATracking3DAssocTrack2LightReset                         */ /*!  
  Description:      reset lights to track associations


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DAssocTrack2LightReset( HLATrack_t* pTrackStart,
                                                HLAPair_t*  pPairStart
                                              )
{
  HLATrack_t*     pTrack;
  HLAPair_t*      pPair;
  FullEgoData_t*  pF;


  /* reset features in track list */
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    /* reset light association info */
    pTrack->light_ref = 0;
    pTrack->dist2Pred = 0;
    pTrack->TrackingStatus.isOneToOneAssociation = 0;
    pTrack->TrackingStatus.isAssocToRemove = 0;
    memset(&pTrack->infoAssoc2Track[0], 0, sizeof(HLAAssocInfo_t));
    memset(&pTrack->infoAssoc2Track[1], 0, sizeof(HLAAssocInfo_t));
    pTrack->infoAssoc2Track[0].ID = 255;
    pTrack->infoAssoc2Track[1].ID = 255;
    pTrack->infoAssoc2Track[0].ui_dist = UI13_T_MAX;
    pTrack->infoAssoc2Track[1].ui_dist = UI13_T_MAX;

#ifdef PC_SIM
    (void)memset((void*)(&(pTrack->db_assoc_final)),0,sizeof(HLACoupleData_t));
    (void)memset(&pTrack->db_lights[0], 0, sizeof(HLACoupleData_t) * DB_HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK);
    pTrack->db_n = 0;
    pTrack->db_new_pattern = 0;
    pTrack->dist_hamming = 0;
#endif

    /* reset dynamic tracker stage flags */
    pTrack->stageTrackDynamic.statusTimeUpdate    = HLA_TRACKSTAGE_KALMAN_INIT;
    pTrack->stageTrackDynamic.statusPred          = HLA_TRACKSTAGE_KALMAN_INIT;
    pTrack->stageTrackDynamic.statusUpdate        = HLA_TRACKSTAGE_KALMAN_INIT;
    pTrack->stageTrackDynamic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_INIT;

    /* reset static tracker stage flags */
    pTrack->stageTrackStatic.statusTimeUpdate    = HLA_TRACKSTAGE_KALMAN_INIT;
    pTrack->stageTrackStatic.statusPred          = HLA_TRACKSTAGE_KALMAN_INIT;
    pTrack->stageTrackStatic.statusUpdate        = HLA_TRACKSTAGE_KALMAN_INIT;
    pTrack->stageTrackStatic.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_INIT;

    /* reset pair prediction flag */
    pTrack->TrackingStatus.isPredFromPair = 0;

    /* reset pair reprojection flag */
    pTrack->TrackingStatus.isRepjFromPair = 0;

    /* reset pair association flag */
    pTrack->TrackingStatus.isAssocFromPair = 0;

    /* reset pair ttb flag */
    pTrack->TrackingStatus.isTTBFromPair = 0;

    /* reset nextTemp */
    pTrack->nextTemp = 0;

    /* increment lost time */
    /* ~CodeReview ~ID:01128735561421e16b3e37da8d806656 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:document overflow can not happen */
    pTrack->lost_time++;

    if(pTrack->stageTrackDynamic.lostTime < HLA_TRACKSTAGE_MAX_LOST_TIME)
    {
      pTrack->stageTrackDynamic.lostTime = pTrack->stageTrackDynamic.lostTime + 1;
    }

    if(pTrack->stageTrackDynamic.winTime < HLA_TRACKSTAGE_MAX_WIN_TIME)
    {
      pTrack->stageTrackDynamic.winTime = pTrack->stageTrackDynamic.winTime + 1;
    }

    if(pTrack->stageTrackStatic.lostTime < HLA_TRACKSTAGE_MAX_LOST_TIME)
    {
      pTrack->stageTrackStatic.lostTime = pTrack->stageTrackStatic.lostTime + 1;
    }

    if(pTrack->stageTrackStatic.winTime < HLA_TRACKSTAGE_MAX_WIN_TIME)
    {
      pTrack->stageTrackStatic.winTime = pTrack->stageTrackStatic.winTime + 1;
    }


    /* increment trace time */
    if (pTrack->trace_time < UI16_T_MAX)
    {
      pTrack->trace_time++;
    }

    if(pTrack->stageTrackDynamic.traceTimeToReinit < HLA_TRACKSTAGE_MAX_TRACE_TIME)
    {
      pTrack->stageTrackDynamic.traceTimeToReinit = pTrack->stageTrackDynamic.traceTimeToReinit + 1;
    }

    if(pTrack->stageTrackStatic.traceTimeToReinit < HLA_TRACKSTAGE_MAX_TRACE_TIME)
    {
      pTrack->stageTrackStatic.traceTimeToReinit = pTrack->stageTrackStatic.traceTimeToReinit + 1;
    }

    /* reset slam tracker */
    if(pTrack->pFullEgoData != NULL)
    {
      pF = pTrack->pFullEgoData;

      /* reset pointer for sorted list */
      pF->next_sorted = 0;

      /* reset static tracker stage flags */
      pF->stageTrackSlam.statusTimeUpdate    = HLA_TRACKSTAGE_KALMAN_INIT;
      pF->stageTrackSlam.statusPred          = HLA_TRACKSTAGE_KALMAN_INIT;
      pF->stageTrackSlam.statusUpdate        = HLA_TRACKSTAGE_KALMAN_INIT;
      pF->stageTrackSlam.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_INIT;

      /* increment lost time */
      if(pF->stageTrackSlam.lostTime < HLA_TRACKSTAGE_MAX_LOST_TIME)
      {
        pF->stageTrackSlam.lostTime = pF->stageTrackSlam.lostTime + 1;
      }

      if(pF->stageTrackSlam.winTime < HLA_TRACKSTAGE_MAX_WIN_TIME)
      {
        pF->stageTrackSlam.winTime = pF->stageTrackSlam.winTime + 1;
      }

      /* increment trace time */
      if(pF->stageTrackSlam.traceTimeToReinit < HLA_TRACKSTAGE_MAX_TRACE_TIME)
      {
        pF->stageTrackSlam.traceTimeToReinit = pF->stageTrackSlam.traceTimeToReinit + 1;
      }
    }

    /* death analysis */
    pTrack->trackDeathAnalysis = 0;
    pTrack->TrackingStatus.deathDueToBornFromPairTest = 0;
    pTrack->TrackingStatus.isTrackedPairToRemove = 0;

    pTrack = pTrack->next;
  }


  /* reset features in pair list */
  pPair = pPairStart;
  while(pPair != NULL)
  {
    /* increment trace time */
    if (pPair->trace_time_pair < UI16_T_MAX)
    {
      pPair->trace_time_pair++;
    }

    if(pPair->stageTrackPair.traceTimeToReinit < HLA_TRACKSTAGE_MAX_TRACE_TIME)
    {
      pPair->stageTrackPair.traceTimeToReinit = pPair->stageTrackPair.traceTimeToReinit + 1;
    }

    /* increment lost time */
    pPair->lost_time_pair++;
    pPair->lost_time_left++;
    pPair->lost_time_right++;

    if(pPair->stageTrackPair.lostTime < HLA_TRACKSTAGE_MAX_LOST_TIME)
    {
      pPair->stageTrackPair.lostTime = pPair->stageTrackPair.lostTime + 1;
    }

    if(pPair->stageTrackPair.winTime < HLA_TRACKSTAGE_MAX_WIN_TIME)
    {
      pPair->stageTrackPair.winTime = pPair->stageTrackPair.winTime + 1;
    }

    /* reset pair tracker stage flags */
    pPair->stageTrackPair.statusTimeUpdate    = HLA_TRACKSTAGE_KALMAN_INIT;
    pPair->stageTrackPair.statusPred          = HLA_TRACKSTAGE_KALMAN_INIT;
    pPair->stageTrackPair.statusUpdate        = HLA_TRACKSTAGE_KALMAN_INIT;
    pPair->stageTrackPair.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_INIT;

    pPair = pPair->next;
  }
}



/* **************************************************************************** 
  Functionname:     HLATracking3DAssocTrack2Light                         */ /*!  
  Description:      Associate lights to track


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DAssocTrack2Light(      HLATrack_t*                           pTrackStart,
                                                HLADebugOutputs_t*                    phlaDebugOutputs,
                                                HLATracking3DDataTracks_t*            pDataTracks,
                                                HLAHotPixelsData_t*                   pDataHotPixels,
                                          const HLASegOut_t*                          pSegOut,
                                          const AS_t_GetTimestampuS32                 pfGetTimestampuS32, 
                                          const HLATracking3DDataPreComputed_t*       pDataPreComputed, 
                                          const HLATracking3DParametersMeasurement_t* pParamMeas,
                                          const HLATracking3DParametersMatching_t*    pParamMatching,
                                          const HLACameraData_t*                      pCamData
                                         )
{
  HLATrack_t*           pTrack;
  HLASegLight_t*        pLightStart = &pSegOut->Light[0];
  HLASegLineRegion_t*   pRegion;
  HLAKalmanMeasPos_t    lightPosNorm;
  HLAKalmanMeasPosPix_t lightPosPix;

  uint8 iLight;

  uint16 lightInt12bits;
  uint16 xLmin, xLmax, yLmin, yLmax;
  uint16 r_sat, g_sat, b_sat;

  float32 dist_dynamic;
  float32 dx, dy,dist_eucl;

  uint32 lightPattern;
  uint32 disthamming;
  
  HLASegNgb_t* pNGB;

  /* local variable */
  uint8           curTrackID;
  uint8           nLightInRegionsBelow;
  HLACoupleData_t AssocData;
  uint32          TimeStart_us;

  /* hot pixels check */
  uint16                x_light;
  uint16                y_light; 
  HLA_t_ICDefectPixel*  pHotPixel;
  uint8                 iHotPixel;
  uint8                 numHotPixels;
  sint8                 IsHot;

  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* get saturation values */
  r_sat = HLAImager_GetIntSaturation_RedLux();
  g_sat = HLAImager_GetIntSaturation_GreenLux();
  b_sat = HLAImager_GetIntSaturation_BlueLux();

  /* get number of hot pixels */
  numHotPixels = pDataHotPixels->hlaDefectPixelList.ui8_DefectsListLength;

  /* count number of hot pixels in HLA ROI */
  pDataHotPixels->numHotPixelInHLAROI = 0;

  /* reset association table */
  pDataTracks->numAssoc = 0;
  (void)memset(&pDataTracks->tableCouple[0], 0, sizeof(HLACoupleData_t) * HLA_TRACKING_MAX_NUM_TRACKS * HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK);

  /* associate light to tracks */
  iLight = pSegOut->iLight;
  while(iLight < HLA_SEG_MAX_NUM_LIGHTS)
  {
    HLASegLight_t *pLight = &pLightStart[iLight];
    
    /* reset cluster flag */
    pLight->Status.associated  = 0;
    pLight->Status.countInPredArea = 0;
    pLight->Status.assoc_type = HLA_TRACKING3D_ASSOCTYPE_DYNAMIC;
    /* ~CodeReview ~ID:0486a37dedfc02268b9ab2faa7acb6e2 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:magic number pixel search area */
    pLight->TrackID0 = 255;
    memset(&pLight->infoAssoc2Light[0], 0, 2 * sizeof(HLAAssocInfo_t));
    pLight->infoAssoc2Light[0].ID = 255;
    pLight->infoAssoc2Light[1].ID = 255;
    pLight->infoAssoc2Light[0].ui_dist = UI13_T_MAX;
    pLight->infoAssoc2Light[1].ui_dist = UI13_T_MAX;
    
    /* get region of light */
    pRegion = pLight->pRegion;
    /* loop through all the regions below */
    while(pRegion != NULL)
    {
      /* reset region status */
      pRegion->Status.IsAssToTrack = 0;
      pRegion->Status.IsAssToPairedTrack = 0;
      pRegion->Status.numOPAss = 0;
      pRegion->Status.numLightAss = 0;

      /* set status if region is above ROI */
      if( ((pRegion->y1 + pRegion->y2) >> 1) < pCamData->RoiYu )
      {
        pRegion->Status.IsRegionAboveROI = 1;
      }
      else
      {
        pRegion->Status.IsRegionAboveROI = 0;
      }

      pRegion = pRegion->pRegionBelow;
    }

    /* hot pixel check */

    /* go through hot pixel list (all types of defect pixels) */
    IsHot = 0;
    x_light = pLight->Maxima.x;
    y_light = pLight->Maxima.y;

    iHotPixel = 0;
    pHotPixel = &pDataHotPixels->hlaDefectPixelList.as_DefectList[0];
    /* TODO: check for hot pixel type is missing */
    while(iHotPixel < numHotPixels)
    {
      if(   (pHotPixel->ui16_xPos == x_light)
         && (pHotPixel->ui16_yPos == y_light)
        )
      {
        /* hot pixel found */
        IsHot = 1;

        /* build statistic if pixel are still hot                             */
        /* if pixel is found for the first time pHotPixel->count is set to 1  */
        /* to synchronize the update statisticse the value has to be set to 2 */
        /* before cycle count starts                                          */
        if (   (pHotPixel->ui16_Count >= 2) 
            && (pHotPixel->ui16_Count < UI16_T_MAX)
           )
        {
          pHotPixel->ui16_Count ++;
        }

        /* no more hot pixel possible at this position -> stop search */
        break;
      }
      
      /* get next hot pixel */
      pHotPixel++;

      /* increment counter */
      iHotPixel++;
    }

    if(IsHot == 1)
    {
      /* this light is hot, so do not start new tracks */
      pLight->Status.HotPixel = 1;
      pLight->Status.associated  = 1;

      /* count number of hot pixels in HLA ROI */
      /* ~CodeReview ~ID:786fc71250e638045e65a377b01589d9 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:document overflow can not happen */
      pDataHotPixels->numHotPixelInHLAROI++;
    }
    else
    {
      /* preprocess light */
      HLATrackMeasGetNormAndPixCoordinates( &lightPosNorm,
                                            &lightPosPix,
                                            pLight,
                                            pDataPreComputed,
                                            pParamMeas
                                          );

      /* 12bits intensity */
      HLATrackMeasGetIntensity12bits( &(lightInt12bits),
                                      pLight
                                    );
  
      /* min-max predicted position of light (exclusion area) */
      xLmin = (uint16) CML_f_MinMax(0.0f, UI16_T_MAX, (lightPosPix.x_center_pix - lightPosPix.x_radius_pix));
      xLmin = (uint16) CML_Max( (sint16)xLmin - 1, 0);

      yLmin = (uint16) CML_f_MinMax(0.0f, UI16_T_MAX, (lightPosPix.y_center_pix - lightPosPix.y_radius_pix));
      yLmin = (uint16) CML_Max( (sint16)yLmin - 1, 0);

      xLmax = (uint16) CML_f_MinMax(0.0f, UI16_T_MAX, (lightPosPix.x_center_pix + lightPosPix.x_radius_pix));
      xLmax = (uint16) CML_Min( (uint32)xLmax + 1, UI16_T_MAX);

      yLmax = (uint16) CML_f_MinMax(0.0f, UI16_T_MAX, (lightPosPix.y_center_pix + lightPosPix.y_radius_pix));
      yLmax = (uint16) CML_Min( (uint32)yLmax + 1, UI16_T_MAX);

      /* get light pattern */
      HLATrackMeasGetLightPattern(&lightPattern,
                                  &pLight->Maxima.ngb[0]
                                 );

      /* check if it's an isolated light inside the regions below */
      nLightInRegionsBelow = 0;
      if(pLight->Status.isIsolatedLight == 0)   /* check status has not been set during segmentation */
      {
        /* get region */
        pRegion = pLight->pRegion;
        /* loop through regions below */
        while(pRegion != NULL)
        {
          /* get largest number of lights in region from segmentation */
          nLightInRegionsBelow = (uint8) CML_Max(nLightInRegionsBelow, pRegion->Status.numLightInRegion);
          /* next region below */
          pRegion = pRegion->pRegionBelow;
        }

        /* if there were no other lights */
        if(nLightInRegionsBelow == 1)
        {
          pLight->Status.isIsolatedLight = 1;
        }
        else
        {
          pLight->Status.isIsolatedLight = 0;

          /* check if it's a level 2 isolated light */ 
          pRegion = pLight->pRegion;
          if(   (pRegion->Level == 2)
             && (pRegion->Status.numLightInRegion == 1)
             && (pRegion->pRegionBelow != 0)
             && (pRegion->pRegionBelow->Status.numLightInRegion == 1) /* A.Manz: probably go a level deeper with new regions */
            )
          {
            pLight->Status.isIsolatedLight = 1;
          }
        }
      }


      /* check for saturation */
      pNGB = &(pLight->Maxima.ngb[0]);
      if (   (pNGB[ NGB_0].lux >= r_sat)
          || (pNGB[ NGB_1].lux >= b_sat)
          || (pNGB[ NGB_2].lux >= g_sat)
          || (pNGB[ NGB_3].lux >= b_sat)
          || (pNGB[ NGB_4].lux >= r_sat)
          || (pNGB[ NGB_5].lux >= g_sat)
          || (pNGB[ NGB_6].lux >= r_sat)
          || (pNGB[ NGB_7].lux >= g_sat)
          || (pNGB[ NGB_8].lux >= r_sat)
          || (pNGB[ NGB_9].lux >= b_sat)
          || (pNGB[NGB_10].lux >= g_sat)
          || (pNGB[NGB_11].lux >= b_sat)
          || (pNGB[NGB_12].lux >= r_sat)
         )
      {
        pLight->Status.isAnyNGBSaturated = 1;
      }
      else
      {
        pLight->Status.isAnyNGBSaturated = 0;
      }

#ifdef PC_SIM
      (void)memset((void*)&(pLight->newTrackAnalysis), 0, sizeof(HLASegLightForNewTrackAnalysis_t));
      pLight->nLightInRegionsBelow = nLightInRegionsBelow;

      pLight->xLmin = xLmin;
      pLight->xLmax = xLmax;
      pLight->yLmin = yLmin;
      pLight->yLmax = yLmax;
#endif

      /* loop over all existing tracks */
      pTrack = pTrackStart;
      while(pTrack != NULL)
      {
        /* check if track is overlapping with prediction area of light */
        if(   ( xLmax > pTrack->xmin )
           && ( xLmin < pTrack->xmax )
           && ( yLmax > pTrack->ymin )
           && ( yLmin < pTrack->ymax )
          )
        {
          /* get TrackID */
          curTrackID = pTrack->TrackID;

          /* say light is inside exclusion area (max of countInPredArea is 3)*/
          if(pLight->Status.countInPredArea < 3) /* A.Manz: replace magic max. countInPredArea number with macro? */
          {
            pLight->Status.countInPredArea = pLight->Status.countInPredArea + 1;
          }

          /* save the first possible track association to the light */
          if(pLight->Status.countInPredArea == 1)
          {
            pLight->TrackID0 = curTrackID;
          }

          /* calculate dynamic distance from light to track */
          dx = lightPosNorm.x - pTrack->ox_p;
          dy = lightPosNorm.y - pTrack->oy_p;

          HLATrackUtilsMaha22(&dist_dynamic,
                              dx,
                              dy,
                              lightPosNorm.cxx + pTrack->osxx,
                              lightPosNorm.cyy + pTrack->osyy,
                              pTrack->osxy
                             );

          /* look if light and track dont have too much intensity difference */
          if(   (dist_dynamic >= 0.0f)
             && (dist_dynamic < HLA_CHI2_VALUE_N2)
             && (   (pTrack->TrackingStatus.isPredFromPair == 1)
                 || (lightInt12bits >= pTrack->minInt12bits)
                )
            )
          {
            /* get euclidian distance to dynamic pred */
            dist_eucl = sqrtf((dx * dx) + (dy * dy)) * pDataPreComputed->FX;

            memset(&AssocData, 0, sizeof(AssocData));
#ifdef PC_SIM
            AssocData.dist_eucl = dist_eucl;
            //AssocData.disthamming = 0;
            //AssocData.dist_int = 0.0f;
            AssocData.IntensityTrack = pTrack->MaxInt;
            AssocData.IntensityLight = pLight->MaxInt;
#endif
            /* hamming distance */
            /* AssocData.validHamming = 0; */
            if(   (pLight->Status.isAnyNGBSaturated == 0)
               && (pTrack->TrackingStatus.isAnyNGBSaturatedLastLight == 0)
               && (pTrack->TrackingStatus.isCodePatternAvailable == 1)
              )
            {
              /* check hamming distance of light patterns */
              HLATrackMeasHammingDistance(&disthamming,
                                          pTrack->codePattern,
                                          lightPattern
                                         );

#ifdef PC_SIM
              AssocData.disthamming = disthamming;
#endif

#if 0 /* M.Brunn */
              /* give penalty to the association depending to hamming distance : only if light or track are not saturated */          
              if(disthamming<pParamMatching->threshHammingAssocDistance[0])
              {
                dist_eucl += pParamMatching->penaltyAssocDistance[0];
              }
              else if(disthamming<pParamMatching->threshHammingAssocDistance[1])
              {
                dist_eucl += pParamMatching->penaltyAssocDistance[1];
              }
              else if(disthamming<pParamMatching->threshHammingAssocDistance[2])
              {
                dist_eucl += pParamMatching->penaltyAssocDistance[2];
              }
              else
              {
                dist_eucl += pParamMatching->penaltyAssocDistance[3];
              }
#endif
               /* update hamming valid flag */
              if(disthamming < pParamMatching->threshHammingAssocDistance[3])
              {
                AssocData.validHamming = 1;
              }
            }
            
            /* add intensity penalty */
            /* color penalty         */
            {
              /* add color penalty for preceding cars */
              if(   /* (pT->TrackingStatus.isRGBAvailable == 1) */
                    (pLight->pRegion)
                 && (pLight->Status.isAnyNGBSaturated == 0)
                 && (pTrack->TrackingStatus.isAnyNGBSaturatedLastLight == 0)
                 && (pLight->Status.isPotLed == 0)
                 && (pTrack->TrackingStatus.isPotLedLastLight == 0)
                )
              {
                /* check size of region                                      */
                /* -> large region -> near objects -> do not check the color */
                /*    potential LED rear lights, traffic signs, ...          */
                if(   ((pLight->pRegion->x2 - pLight->pRegion->x1) < 5)
                   && ((pLight->pRegion->y2 - pLight->pRegion->y1) < 10)
                  )
                {
                  /* red light track */
                  if(pTrack->RedLightCnt > 0)
                  {
                    if(   (pLight->current_R < pLight->current_G)
                       || (pLight->current_R < pLight->current_B)
                      )
                    {
                      AssocData.invalidColor = 1;
                    }
                  }
#if 0
                  uint32 dColor = fABS(pL->current_R - pT->current_R) + fABS(pL->current_G - pT->current_G) + fABS(pL->current_B - pT->current_B);

                  if(dColor > 14)
                  {
                    float32 Penalty;

                    Penalty = MIN(3.0f, (0.1f*(dColor-14)));

                    dist_eucl += Penalty;

#ifdef PC_SIM
                    AssocData.dist_color = Penalty;
#endif
                  }
                  if(dColor > 44)
                  {
                    AssocData.invalidColor = 1;
                  }
                }
#endif
                }
              }

              /* add intensity penalty */
              if(   (pTrack->MaxInt > 0)
                 && (pLight->Status.isPotLed == 0)
                 && (pTrack->TrackingStatus.isPotLedLastLight == 0)
                )
              {
                /* calculate factor of higher intensity diveded by lower intensity */
                float32 fac = (float32)CML_Max(pTrack->MaxInt, pLight->MaxInt) / (float32)CML_Max(CML_Min(pTrack->MaxInt, pLight->MaxInt), 1u);

                /* if higher intensity is larger than lower int by a factor larger than 2.0 */
                if(fac > 2.0f)
                {
                  /* calculate penalty */
                  float32 Penalty;
                  /* cap penalty at 8.0 */
                  Penalty = CML_f_Min((0.5f * (fac - 2.0f)), 8.0f);
                  /* add penalty */
                  dist_eucl += Penalty;
  #ifdef PC_SIM
                  AssocData.dist_int = Penalty; 
  #endif
                }
                /* if factor is larger than 50.0 consider intensity as invalid */
                if(fac > 50.0f)
                {
                  AssocData.invalidInt = 1;
                }
              }
            }

            /* associate light to track as dynamic */
            AssocData.ui_dist = (uint16)CML_f_Max( CML_f_Min( (pDataPreComputed->factorF2IDist * dist_eucl), (UI13_T_MAX-1.0f) ), 0.0f);
            AssocData.IDL     = iLight;
            AssocData.IDT     = curTrackID;

            /* add associated light to list */
            HLATrackUtilsAddCoupleToList( &pDataTracks->tableCouple[0],
                                          &(pDataTracks->numAssoc),
                                          &AssocData,
                                          (HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK * HLA_TRACKING_MAX_NUM_TRACKS)
                                        );

            /* save best association to light */
            if(AssocData.ui_dist < pLight->infoAssoc2Light[0].ui_dist)
            {
              pLight->infoAssoc2Light[1]              = pLight->infoAssoc2Light[0];
              pLight->infoAssoc2Light[0].ui_dist      = AssocData.ui_dist;
              pLight->infoAssoc2Light[0].ID           = AssocData.IDT;
              pLight->infoAssoc2Light[0].invalidColor = AssocData.invalidColor;
              pLight->infoAssoc2Light[0].invalidInt   = AssocData.invalidInt;
            }
            else if(AssocData.ui_dist < pLight->infoAssoc2Light[1].ui_dist)
            {
              pLight->infoAssoc2Light[1].ui_dist      = AssocData.ui_dist;
              pLight->infoAssoc2Light[1].ID           = AssocData.IDT;
              pLight->infoAssoc2Light[1].invalidColor = AssocData.invalidColor;
              pLight->infoAssoc2Light[1].invalidInt   = AssocData.invalidInt;
            }
            else
            {
              /* Do nothing */
            }

            /* ~CodeReview ~ID:e4b05dc593ea2809d3c43b965eb22a28 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:magic number */
            if(pLight->infoAssoc2Light[0].count < 7)
            {
              pLight->infoAssoc2Light[0].count = pLight->infoAssoc2Light[0].count + 1;
            }

            /* save best association to track */
            if(AssocData.ui_dist < pTrack->infoAssoc2Track[0].ui_dist)
            {
              pTrack->infoAssoc2Track[1]              = pTrack->infoAssoc2Track[0]; 
              pTrack->infoAssoc2Track[0].ui_dist      = AssocData.ui_dist;
              pTrack->infoAssoc2Track[0].ID           = AssocData.IDL;
              pTrack->infoAssoc2Track[0].invalidColor = AssocData.invalidColor;
              pTrack->infoAssoc2Track[0].invalidInt   = AssocData.invalidInt;
            }
            else if(AssocData.ui_dist < pTrack->infoAssoc2Track[1].ui_dist)
            {
              pTrack->infoAssoc2Track[1].ui_dist      = AssocData.ui_dist;
              pTrack->infoAssoc2Track[1].ID           = AssocData.IDL;
              pTrack->infoAssoc2Track[1].invalidColor = AssocData.invalidColor;
              pTrack->infoAssoc2Track[1].invalidInt   = AssocData.invalidInt;
            }
            else
            {
              /* Do nothing */
            }

            if(pTrack->infoAssoc2Track[0].count < 7)
            {
              pTrack->infoAssoc2Track[0].count = pTrack->infoAssoc2Track[0].count + 1;
            }

#ifdef PC_SIM
            /* get debug for info for track assoc */
            HLATrackUtilsAddCoupleToList( &pTrack->db_lights[0],
                                          &(pTrack->db_n),
                                          &AssocData,
                                          DB_HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK
                                        );
#endif
          }
        }
        pTrack = pTrack->next;
      }
    }
    iLight = pLight->iLightNext;
  }

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackAssocTrack2Light_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}



/* **************************************************************************** 
  Functionname:     HLATracking3DAssocTrack2LightSolve                         */ /*!  
  Description:      solve association of lights to track problem


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATracking3DAssocTrack2LightSolve(       HLADebugOutputs_t*            phlaDebugOutputs,
                                                      HLATracking3DDataTracks_t*    pDataTracks,
                                                      HLATracking3DDataCrossCorr_t* pDataCrossCorr,
                                                const HLASegOut_t*                  pSegOut,
                                                const AS_t_GetTimestampuS32         pfGetTimestampuS32
                                              )
{
  HLATrack_t*       pTrack;
  HLATrack_t*       pTrack2;
  HLASegLight_t*    pLight;
  HLASegLight_t*    pLight2;
  HLACoupleData_t*  pAssociation;

  HLATrack_t*       trackBuffer;
  HLASegLight_t*    lightBuffer;
  HLACoupleData_t*  assocBuffer;

  FullEgoData_t*    pFCurr;
  FullEgoData_t*    pFLast;

  uint32 i;
  uint32 TimeStart_us;
  uint8 skipAssoc;
 

  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* get buffers */
  lightBuffer = pSegOut->pLightMemoryStart;
  trackBuffer = &pDataTracks->free_tracked_lights_buffer[0];
  assocBuffer = &pDataTracks->tableCouple[0];

  /* reset SLAM sorted list */
  pDataCrossCorr->pFullEgoDataBufferSorted = 0;
  pFLast = 0;

  /* go through all associations */
  pAssociation = assocBuffer;
  for(i = 0 ; i < pDataTracks->numAssoc ; i++)
  {
    pTrack = &(trackBuffer[pAssociation->IDT]);
    pLight = &(lightBuffer[pAssociation->IDL]);

    if(   ( (uint32) pAssociation->ui_dist < UI13_T_MAX)
       && (pTrack->light_ref == 0)
       && (pLight->Status.associated == 0)
       && (pAssociation->invalidInt == 0)
       && (pAssociation->invalidColor == 0)
       && (   (pAssociation->validHamming == 1)
           || (pLight->infoAssoc2Light[0].count == 1)
           /* ~CodeReview ~ID:453d8df794b98524544de40cc8f2b9c9 ~Reviewer:CW01\uidt9253 ~Date:3/28/2012 ~Priority:3 ~Comment:magic number */
           || (   (   (pLight->infoAssoc2Light[0].ID == pAssociation->IDT)
                   || (pLight->infoAssoc2Light[0].ID == 254)
                  )
               && (   (pTrack->infoAssoc2Track[0].ID == pAssociation->IDL)
                   || (pTrack->infoAssoc2Track[0].ID == 254)
                  )
              )
          )
      )
    {
      /* avoid track losses for far pairs */
      if(   (pTrack->TrackingStatus.isTrackedInPair == 1)
         && (pTrack->infoAssoc2Track[0].ID == pAssociation->IDL)
         && (pTrack->infoAssoc2Track[0].count > 1)
         && (pTrack->dist_est_pair_link->infoAssoc2Track[0].ID == pAssociation->IDL)
         && (pTrack->dist_est_pair_link->infoAssoc2Track[0].count == 1)
        )
      {
        /* then skip the association : light will go to the other track*/

        /* unvalid the best associated track 2 light (used afterwards when Hamming distance is not valid) */
        pLight->infoAssoc2Light[0].ID = 254;

        /* unvalid the best associated light 2 track (used afterwards when Hamming distance is not valid) */
        pTrack->infoAssoc2Track[0].ID = 254;
      }
      else if(   (pTrack->trace_time == 2)                                                   /* first association of the track : Take care before validating it */
              && (pTrack->infoAssoc2Track[0].count == 1)                                     /* case where track can only be associated to this light */
              && (pLight->infoAssoc2Light[0].count == 2)                                     /* light can also be associated to another track */
              && (pLight->infoAssoc2Light[0].ID == pAssociation->IDT)                        /* other track is infoAssoc2Light[1].ID */
              && (trackBuffer[pLight->infoAssoc2Light[1].ID].infoAssoc2Track[0].count == 1)  /* other track can also only be associated to this light */
              && (trackBuffer[pLight->infoAssoc2Light[1].ID].trace_time > 2)                 /* other track have longer history : this is prefered choice */
             )
      {
        /* skip association */
      }
      else
      {
        skipAssoc = 0;

        /* track case where two tracks for 2 lights */
        /***************************/
        /*  tracks:  IDT1  IDT2    */
        /*             | \ / |     */
        /*             |  /  | ?   */
        /*             | / \ |     */
        /*  lights:  IDL1  IDL2    */
        /***************************/
        if(   (pTrack->infoAssoc2Track[0].count == 2)
           && (pLight->infoAssoc2Light[0].count > 1)
              /* best association of Light and Track */
           && (pTrack->infoAssoc2Track[0].ID == pLight->LightID)
           && (pLight->infoAssoc2Light[0].ID == pTrack->TrackID)
          )
        {
          pTrack2 = &(trackBuffer[pLight->infoAssoc2Light[1].ID]);
          pLight2 = &(lightBuffer[pTrack->infoAssoc2Track[1].ID]);

          if(   (pTrack->statusAnalysisVehicle.isVehicleAhead == 0)
             && (pTrack->statusAnalysisVehicle.isVehicleOncoming == 0)
             && (pTrack2->infoAssoc2Track[0].count == 2)
             && (pLight2->infoAssoc2Light[0].count > 1)
             /* track 2 has best association on same light as track 1 */
             && (pTrack2->infoAssoc2Track[0].ID == pLight->LightID) 
             && (pTrack2->infoAssoc2Track[1].ID == pLight2->LightID)
            )
          {
            /* check tracks share the same x direction */
            if(   ( pTrack2->xmax > pTrack->xmin )
               && ( pTrack2->xmin < pTrack->xmax )
              )
            {
              /* check if pT-to-pL and pT2-to-pL2 are the best set of associations */
              if(   (   (pTrack->oy_p > pTrack2->oy_p)
                     && (pLight->ycenter >= pLight2->ycenter)
                    )
                 || (   (pTrack->oy_p < pTrack2->oy_p)
                     && (pLight->ycenter <= pLight2->ycenter)
                    )
                )
              {
                skipAssoc = 0;
              }
              else
              {
                skipAssoc = 1;
              }
            }
          }
          /* M.Brunn */
          {
            /***************************/
            /*  tracks:   IDT  IDT2    */
            /*             | \ / |     */
            /*             |  /  | ?   */
            /*             | / \ |     */
            /*  lights:   IDL  IDL2    */
            /***************************/
            if(   (pTrack2->infoAssoc2Track[0].count <= 2)
               && (pLight2->infoAssoc2Light[0].count >= 1)
              )
            {
              uint32 dist_TL, dist_TL2 , dist_T2L, dist_T2L2;
              uint32 ui_dist_Penalty = 200; /* non vehicles */  
              uint32 ui_dist_Penalty_Veh = 400; /* vehicles */

              dist_TL  = pTrack->infoAssoc2Track[0].ui_dist;
              dist_TL2 = pTrack->infoAssoc2Track[1].ui_dist;
              dist_T2L = pLight->infoAssoc2Light[1].ui_dist;

              if(pTrack2->infoAssoc2Track[1].ID == 255)
              {
                /***************************/
                /*  tracks:   IDT  IDT2    */
                /*             | \ /       */
                /*             |  /        */
                /*             | / \       */
                /*  lights:   IDL  IDL2    */
                /***************************/
                if(   (pTrack2->statusAnalysisVehicle.isVehicleAhead == 1)
                   || (pTrack2->statusAnalysisVehicle.isVehicleOncoming == 1)
                  )
                {
                  /* vehicle track */
                  /* avoid track lost on vehicles */
                  if(dist_T2L < ((uint32)dist_TL+ui_dist_Penalty_Veh))
                  {
                    skipAssoc = 1;
                  }
                }
                else
                {
                  /* non vehicle track */
                  if(dist_T2L < ((uint32)dist_TL+ui_dist_Penalty))
                  {
                    skipAssoc = 1;
                  }
                }
              }
              else if(   (pTrack2->infoAssoc2Track[0].ID == pLight2->infoAssoc2Light[0].ID)
                      || (pTrack2->infoAssoc2Track[0].ID == pLight2->infoAssoc2Light[1].ID)
                      || (pTrack2->infoAssoc2Track[1].ID == pLight2->infoAssoc2Light[0].ID)
                      || (pTrack2->infoAssoc2Track[1].ID == pLight2->infoAssoc2Light[1].ID)
                     )
              {
                /***************************/
                /*  tracks:   IDT  IDT2    */
                /*             | \ / |     */
                /*             |  /  |     */
                /*             | / \ |     */
                /*  lights:   IDL  IDL2    */
                /***************************/
                uint32 sumDist_TL_T2L2;
                uint32 sumDist_TL2_T2L;


                if(pTrack2->TrackID == pLight2->infoAssoc2Light[0].ID)
                {
                  dist_T2L2 = pLight2->infoAssoc2Light[0].ui_dist;
                }
                else
                {
                  dist_T2L2 = pLight2->infoAssoc2Light[1].ui_dist;
                }

                sumDist_TL_T2L2 = dist_TL  + dist_T2L2;
                sumDist_TL2_T2L = dist_TL2 + dist_T2L;

                if((sumDist_TL2_T2L + 100) < sumDist_TL_T2L2)
                {
                  skipAssoc = 1;
                }
              }
              else
              {
                /* Do nothing */
              }
            }
          }
          /* M.Brunn */
        }
        
        if(skipAssoc == 0)
        {
          /* create association */
          HLATrackMeasAddMeasurement( pTrack,
                                      pLight,
                                      pAssociation->ui_dist
                                    );

          /* generate sorted list of SLAM features */
          pFCurr = pTrack->pFullEgoData;
          if(pFCurr != NULL)
          {
            if(pFLast == 0)
            {
              /* set first element in the list */
              pDataCrossCorr->pFullEgoDataBufferSorted = pFCurr;
            }
            else
            {
              /* insert new element */
              pFLast->next_sorted = pFCurr;
            }

            pFLast = pFCurr;
          }

#ifdef PC_SIM
          pTrack->db_assoc_final = *pAssociation;
#endif
        }
      }
    }

    pAssociation++;
  }


  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackAssocTrack2LightSolve_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}/* PRQA S 861 1 */
