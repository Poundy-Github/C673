/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackslam.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackslam.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:12CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:55CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:13CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.40 2014/03/26 11:27:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:39 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.39 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackslam.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackslam.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.38 2014/03/21 09:38:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:44 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.37 2014/03/19 16:30:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:23 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.36 2014/03/10 13:20:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:58 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.35 2014/03/05 11:05:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:25 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.34 2014/03/04 16:52:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:14 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.33 2014/02/07 09:50:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:50:01 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.32 2014/02/06 16:01:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:19 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.31 2014/01/24 13:37:54CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:54 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.30 2014/01/24 09:35:03CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:35:03 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.29 2014/01/21 13:58:01CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixed unsafe comparison of float with 0 and 1
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 21, 2014 1:58:01 PM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.28 2014/01/21 13:09:17CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:18 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.27 2013/12/13 16:44:46CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:46 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.26 2013/11/21 17:53:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:11 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.25.1.4 2013/11/21 14:15:32CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:33 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.25.1.3 2013/11/21 13:37:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:26 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.25.1.2 2013/11/19 07:54:44CET Brunn, Marcus (brunnm) 
  CHANGE:                 - removed day segmentation
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 7:54:45 AM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.25.1.1 2013/11/12 13:45:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:04 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
**************************************************************************** */
#include "hla_trackslam.h"

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "hla_trackmeas.h"
#include "hla_trackmodel.h"

/* static const uint32 RANDOM_NUMBER_RANGE = 32768u; */
static uint32 randomNumber;

/* init functions */
static void HLATrackSlamInitCali(       HLATracking3DDataCali_t*        pDataCali,
                                  const HLATracking3DParametersCali_t*  pParamCali
                                );

static void HLATrackSlamInitEgomotion(HLATracking3DDataEgomotion_t* pDataEgomotion);

static void HLATrackSlamInitFeaturesTable(HLATracking3DDataCrossCorr_t* pDataCrossCorr);

static void HLATrackSlamInitRotations(      HLATracking3DDataRotations_t* pDataRotations,
                                      const HLA_t_SensorSocket*           ps_SensorSocket
                                     );

/* predict function */
static void HLATrackSlamPredictEgomotion(       HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                          const HLATracking3DDataCrossCorr_t*   pDataCrossCorr,
                                          const HLA_t_MotionState*              pMotionData,
                                          const HLACameraData_t*                pCamData,
                                          const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                          const RTE_HLAR_BrightnessState        eBrightnessState
                                        );

static void HLATrackSlamPredictCali(      HLATracking3DDataCali_t*      pDataCali,
                                    const HLATracking3DDataCrossCorr_t* pDataCrossCorr,
                                    const RTE_HLAR_BrightnessState      eBrightnessState
                                   );

/* update functions */
static void HLATrackSlamUpdateRotations(      HLATracking3DDataRotations_t* pDataRotations,
                                        const HLATracking3DDataCali_t*      pDataCali,
                                        const HLATracking3DDataEgomotion_t* pDataEgomotion
                                       );

static void HLATrackSlamUpdateCaliOutput(       HLATracking3DDataCali_t*        pDataCali,
                                          const HLATracking3DParametersCali_t*  pParamCali
                                        );

/* kalman filter */
static void HLATrackSlamKalmanInit(       FullEgoData_t*                  pFi,
                                    const HLATracking3DDataCrossCorr_t*   pDataCrossCorr,
                                    const HLAKalmanMeasPos_t*             pLNorm,
                                    const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                    const HLATracking3DDataCali_t*        pDataCali,
                                    const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                    const HLATracking3DDataRotations_t*   pDataRotations
                                  );

static void HLATrackSlamKalmanPredictOrUpdate(      uint16*                                 p_assoc_type,
                                                    FullEgoData_t*                          pFj,
                                                    HLATracking3DDataCali_t*                pDataCali,
                                                    HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                                    HLATracking3DDataRotations_t*           pDataRotations,
                                              const HLATracking3DDataCrossCorr_t*           pDataCrossCorr,
                                              const HLAKalmanMeasPos_t*                     pLNorm,
                                              const HLATracking3DParametersStaticTracker_t* pParamStatic
                                              );

static void HLATrackSlamKalmanCorrelationsDelayedUpdate(const HLATracking3DDataCrossCorr_t* pDataCrossCorr);


static void HLATrackSlamKalmanDelayedUpdate(      FullEgoData_t*                pF,
                                            const HLATracking3DDataEgomotion_t* pDataEgomotion,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                           );

static void seedLCG(uint32 seed);

static uint32 theLCG(void);

/* **************************************************************************** 
  Functionname:     HLATrackSlamInit()                             */ /*!  
  Description:      
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
/* ~CodeReview ~ID:70177ebbec5404f57b4991a21fd1a415 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
/* ~CodeReview ~ID:9a822861ff43a9f3ae558858ca36e847 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:General: pointer parameters of exported functions are not checked for NULL. */
void HLATrackSlamInit(      HLATracking3DDataCali_t*        pDataCali,
                            HLATracking3DDataEgomotion_t*   pDataEgomotion,
                            HLATracking3DDataCrossCorr_t*   pDataCrossCorr,
                            HLATracking3DDataRotations_t*   pDataRotations,
                      const HLATracking3DParametersCali_t*  pParamCali,
                      const HLA_t_SensorSocket*             ps_SensorSocket
                     )
{
  /* init on line cali and egomotion data */
  HLATrackSlamInitCali( pDataCali,
                        pParamCali
                      );

  /* init egomotion */
  HLATrackSlamInitEgomotion(pDataEgomotion);

  /* init cross correlations */
  HLATrackSlamInitFeaturesTable(pDataCrossCorr);

  /* init pre-calculate values for rotation/translation from world to cam */
  HLATrackSlamInitRotations(pDataRotations,
                            ps_SensorSocket
                           );
}


/* **************************************************************************** 
  Functionname:     HLATrackSlamInitCali()                             */ /*!  
  Description:      
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
static void HLATrackSlamInitCali( HLATracking3DDataCali_t*              pDataCali, 
                                  const HLATracking3DParametersCali_t*  pParamCali
                                )
{
  /* --------------------------------------------------------------------------------------------*/
  /* on line cali */

  /* max uncertainty on on-line cali */
  pDataCali->ccyymax = (pParamCali->errCalYawMax*pParamCali->errCalYawMax)     / 9.0f;
  pDataCali->ccppmax = (pParamCali->errCalPitchMax*pParamCali->errCalPitchMax) / 9.0f;
  pDataCali->ccrrmax = (pParamCali->errCalRollMax*pParamCali->errCalRollMax)   / 9.0f;

  /* min uncertainty on on-line cali */
  pDataCali->ccyymin = (pParamCali->errCalYawMin*pParamCali->errCalYawMin)     / 9.0f;
  pDataCali->ccppmin = (pParamCali->errCalPitchMin*pParamCali->errCalPitchMin) / 9.0f;
  pDataCali->ccrrmin = (pParamCali->errCalRollMin*pParamCali->errCalRollMin)   / 9.0f;

  /* init online cali */
  pDataCali->cal_yaw   = -1.57080f;
  pDataCali->cal_pitch = -1.58825f;
  pDataCali->cal_roll  = 0.00000f;
  
  pDataCali->ccyy = pDataCali->ccyymax;
  pDataCali->ccpy = 0;                    pDataCali->ccpp = pDataCali->ccppmax;
  pDataCali->ccry = 0;                    pDataCali->ccrp = 0;                    pDataCali->ccrr = pDataCali->ccrrmax;

  /* reset on;line cali odometer */
  /*pDataCali->odometerOnLineCaliM = 0;*/
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamInitEgomotion()                             */ /*!  
  Description:      
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
static void HLATrackSlamInitEgomotion(HLATracking3DDataEgomotion_t* pDataEgomotion)
{
  /* --------------------------------------------------------------------------------------------*/
  /* egomotion */

  /* init egomotion */
  pDataEgomotion->ego_yaw   = 0;
  pDataEgomotion->ego_pitch = 0;
  pDataEgomotion->ego_roll  = 0;

  pDataEgomotion->eeyy = 0;
  pDataEgomotion->eepy = 0;   pDataEgomotion->eepp = 0;
  pDataEgomotion->eery = 0;   pDataEgomotion->eerp = 0;   pDataEgomotion->eerr = 0;

  /* extreme values of egomotion */
  pDataEgomotion->eeyy_ex = 0;
  pDataEgomotion->eepp_ex = 0;
  pDataEgomotion->eerr_ex = 0;

  /* --------------------------------------------------------------------------------------------*/
  /* correlations between online cali and egomotion */
  pDataEgomotion->ecyy = 0;   pDataEgomotion->ecyp = 0;   pDataEgomotion->ecyr = 0;
  pDataEgomotion->ecpy = 0;   pDataEgomotion->ecpp = 0;   pDataEgomotion->ecpr = 0;
  pDataEgomotion->ecry = 0;   pDataEgomotion->ecrp = 0;   pDataEgomotion->ecrr = 0;
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamInitRotations                                           */ /*!  
  Description:      

  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamInitRotations(      HLATracking3DDataRotations_t* pDataRotations, 
                                      const HLA_t_SensorSocket*           ps_SensorSocket
                                     )
{
  /* reset */
  (void)memset((void*)pDataRotations, 0, sizeof(HLATracking3DDataRotations_t));

  pDataRotations->TK[0] = ps_SensorSocket->f32_X;
  pDataRotations->TK[1] = ps_SensorSocket->f32_Y;
  pDataRotations->TK[2] = ps_SensorSocket->f32_Z;
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamInitFeaturesTable()                             */ /*!  
  Description:      
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */ 
static void HLATrackSlamInitFeaturesTable(HLATracking3DDataCrossCorr_t  *pDataCrossCorr)
{
  uint8 i;
  FullEgoData_t* pF;
  FullEgoData_t* pFnext;
  TracksCrossCorr_t* pMem;

  /* init full egomotion data buffer */
  pF = pDataCrossCorr->FullEgoData;
  pFnext = &(pDataCrossCorr->FullEgoData[1]);
  for(i = 0 ; i < (HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR - 1) ; i++)
  {
    pF->next = pFnext;
    pF++;
    pFnext++;
  }

  /*last track */
  pF->next = 0;


  pDataCrossCorr->pFullEgoDataBufferFree = pDataCrossCorr->FullEgoData;
  pDataCrossCorr->pFullEgoDataBuffer = 0;

  /* init cross correlation pointer table */
  pMem = pDataCrossCorr->CrossCorrelations;
  pDataCrossCorr->FullEgoData[0].pCrossCorrelations = 0;
  pDataCrossCorr->FullEgoData[0].slot = 0;
  for(i = 1; i < HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR ; i++)
  {
    pDataCrossCorr->FullEgoData[i].pCrossCorrelations = pMem; 
    pDataCrossCorr->FullEgoData[i].slot = i;
    pMem += i;
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamRemove                            */ /*!  
  Description:      remove landmark from full egomotion state


  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackSlamRemove(HLATracking3DDataCrossCorr_t* pDataCrossCorr,
                        uint8*                        pnumTracksCrossCorr
                       )
{
  FullEgoData_t* pF     = pDataCrossCorr->pFullEgoDataBuffer;
  FullEgoData_t* pFnext = 0;
  FullEgoData_t* pFprev = 0;

  while(pF != NULL)
  {
    if(pF->pTrack == 0)
    {
      (*pnumTracksCrossCorr)--;

      /* save next track pointer in track list. */
      pFnext = pF->next;

      /* save the next-in-list track to the previous track. */
      if (pFprev != NULL)
      {
        pFprev->next = pF->next;
      }
      else
      {
        pDataCrossCorr->pFullEgoDataBuffer = pF->next;
      }

      /* add removed tracks to the beginning of free tracked lights list. */
      pF->next = pDataCrossCorr->pFullEgoDataBufferFree;
      pDataCrossCorr->pFullEgoDataBufferFree = pF;

      /* move the pointer to the next track. */
      pF = pFnext;
    }
    else
    {
      pFprev = pF;
      pF = pF->next;
    }

  }
}


/* **************************************************************************** 
  Functionname:     HLATrackSlamPredict                              */ /*!  
  Description:      predict step of slam algo


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackSlamPredict(       HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                HLATracking3DDataCali_t*        pDataCali,
                                HLATracking3DDataRotations_t*   pDataRotations, 
                          const HLATracking3DDataCrossCorr_t*   pDataCrossCorr, 
                          const HLA_t_MotionState*              pMotionData,
                          const HLACameraData_t*                pCamData,
                          const HLATracking3DDataPreComputed_t* pDataPreComputed,
                          const RTE_HLAR_BrightnessState        eBrightnessState
                         )
{
  /* egomotion time update */
  HLATrackSlamPredictEgomotion( pDataEgomotion,
                                pDataCrossCorr,
                                pMotionData,
                                pCamData,
                                pDataPreComputed,
                                eBrightnessState
                              );

  /* on-line cali time update */
  HLATrackSlamPredictCali(pDataCali,
                          pDataCrossCorr,
                          eBrightnessState
                         );

  /* update associated rotation matrices */
  HLATrackSlamUpdateRotations(pDataRotations,
                              pDataCali,
                              pDataEgomotion
                             );
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamPredictEgomotion                              */ /*!  
  Description:      Perform time update step of the kalman filter


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamPredictEgomotion(       HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                          const HLATracking3DDataCrossCorr_t*   pDataCrossCorr, 
                                          const HLA_t_MotionState*              pMotionData,
                                          const HLACameraData_t*                pCamData,
                                          const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                          const RTE_HLAR_BrightnessState        eBrightnessState
                                        )
{
  float32  dt;
  float32 Cey,Cey_1;
  float32 proc_epp,proc_err;
  FullEgoData_t* pF;

  /* egomotion */
  float32 ego_yaw;
  /* ~CodeReview ~ID:7bda4faa4e6d7a9f6e5483f69199188d ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (general). */
  /* float32 ego_pitch; */
  /* float32 ego_roll; */
  float32 eeyy;
  /* float32 eepy, eepp; */
  /* float32 eery, eerp, eerr; */

  /* correlations between online cali and egomotion */
  float32 /* ecyy, */ ecyp /*, ecyr */;
  /* float32 ecpy, ecpp, ecpr; */
  /* float32 ecry, ecrp, ecrr; */

  /* get egomotion */
  ego_yaw    = pDataEgomotion->ego_yaw;
  /* ego_pitch  = pDataEgomotion->ego_pitch; */
  /* ego_roll   = pDataEgomotion->ego_roll; */

  eeyy = pDataEgomotion->eeyy;
  /* eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp; */
  /* eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr; */

  /* correlations between online cali and egomotion */
  /* ecyy = pDataEgomotion->ecyy;*/    ecyp = pDataEgomotion->ecyp;     /*ecyr = pDataEgomotion->ecyr; */
  /* ecpy = pDataEgomotion->ecpy;    ecpp = pDataEgomotion->ecpp;     ecpr = pDataEgomotion->ecpr; */
  /* ecry = pDataEgomotion->ecry;    ecrp = pDataEgomotion->ecrp;     ecrr = pDataEgomotion->ecrr; */


  /* get pitch filter constant */
  if(fabsf(pMotionData->f32_Speed) > 0)
  {
    Cey = 0.0f;
    proc_epp      = pDataPreComputed->proc_epp;
    proc_err      = pDataPreComputed->proc_err;    
  }
  else
  {
    Cey = 1.0f;
    proc_epp    = 0.0f;
    proc_err    = 0.0f;
  }

  Cey_1 = 1 - Cey;

  /* set delta time */
  pDataEgomotion->dt = pCamData->dtime_s;
  
  /* get delta time */
  dt = pDataEgomotion->dt;

  /* set egomotion */
  pDataEgomotion->ego_length = (pMotionData->f32_Speed * dt) + ((pMotionData->f32_Acceleration) * ((dt * dt)/2.0f));
  pDataEgomotion->ego_yaw    = (ego_yaw * Cey) + (((pMotionData->f32_YawRateRaw) * dt) * Cey_1);
  pDataEgomotion->ego_pitch  = 0;
  pDataEgomotion->ego_roll   = 0;
  pDataEgomotion->ego_speed  = pMotionData->f32_Speed;
  pDataEgomotion->ego_yawrate = pMotionData->f32_YawRateRaw;

  /* egomotion : update state covariances with model */
  pDataEgomotion->eeyy = Cey*Cey*eeyy;
  pDataEgomotion->eepy = 0;     pDataEgomotion->eepp = 0;
  pDataEgomotion->eery = 0;     pDataEgomotion->eerp = 0;                           pDataEgomotion->eerr = 0;

  /* egomotion : add process noise */
  pDataEgomotion->eeyy += CML_f_Max(pDataPreComputed->varianceYawRate, pMotionData->f32_YawRateVariance) * Cey_1 * Cey_1 * dt * dt;
  pDataEgomotion->eepp += proc_epp;
  pDataEgomotion->eerr += proc_err;

  /* set up extreme yaw rate covariance */
  pDataEgomotion->eeyy_ex = CML_f_Max(pDataPreComputed->varianceYawRateExtreme, pMotionData->f32_YawRateVariance) * Cey_1 * Cey_1 * dt * dt;

  /* set up extreme pitch covariance */
  pDataEgomotion->eepp_ex = pDataPreComputed->proc_epp_ex;

  /* set up extreme roll covariance */
  pDataEgomotion->eerr_ex = pDataPreComputed->proc_err_ex;

  if(   (eBrightnessState == RTE_HLAR_BRT_TWLGT_3)
     || (eBrightnessState == RTE_HLAR_BRT_NIGHT)
    )
  {
    pDataEgomotion->ecyy = 0;     pDataEgomotion->ecyp = Cey*ecyp;          pDataEgomotion->ecyr = 0;
    pDataEgomotion->ecpy = 0;     pDataEgomotion->ecpp = 0;                 pDataEgomotion->ecpr = 0;
    pDataEgomotion->ecry = 0;     pDataEgomotion->ecrp = 0;                 pDataEgomotion->ecrr = 0;
  }
  else
  {
    /* ensure reset of calibration corroletions when day or < twilight 3 */
    pDataEgomotion->ecyy = 0;     pDataEgomotion->ecyp = 0;                 pDataEgomotion->ecyr = 0;
    pDataEgomotion->ecpy = 0;     pDataEgomotion->ecpp = 0;                 pDataEgomotion->ecpr = 0;
    pDataEgomotion->ecry = 0;     pDataEgomotion->ecrp = 0;                 pDataEgomotion->ecrr = 0;
  }

  /* local variable */
  pF = pDataCrossCorr->pFullEgoDataBuffer;
  while(pF != NULL)
  {
    /* update cross-correlation between landmark and egomotion */
    pF->euy = Cey * pF->euy;
    pF->evy = Cey * pF->evy;
    pF->edy = Cey * pF->edy;

    pF->eup = 0;
    pF->evp = 0;
    pF->edp = 0;

    pF->eur = 0;
    pF->evr = 0;
    pF->edr = 0;

    pF = pF->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamPredictCali                              */ /*!  
  Description:      Perform time update step of the kalman filter


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamPredictCali(      HLATracking3DDataCali_t*      pDataCali, 
                                    const HLATracking3DDataCrossCorr_t* pDataCrossCorr,
                                    const RTE_HLAR_BrightnessState      eBrightnessState
                                   )
{
  FullEgoData_t* pF;

  /* online cali */
  float32 ccyy;
  float32 ccpy, ccpp;
  float32 ccry, ccrp, ccrr;

  ccyy = pDataCali->ccyy;
  ccpy = pDataCali->ccpy;   ccpp = pDataCali->ccpp;
  ccry = pDataCali->ccry;   ccrp = pDataCali->ccrp;   ccrr = pDataCali->ccrr;

  /* calibrate only during night and twilight 3 */
  if(   (eBrightnessState == RTE_HLAR_BRT_TWLGT_3)
     || (eBrightnessState == RTE_HLAR_BRT_NIGHT)
    )
  {
    /* online cali : update state covariances with model */
    pDataCali->ccyy = ccyy;
    pDataCali->ccpy = ccpy;   pDataCali->ccpp = ccpp;
    pDataCali->ccry = ccry;   pDataCali->ccrp = ccrp;   pDataCali->ccrr = ccrr;

    /* online cali : add process noise */
    pDataCali->ccyy = CML_f_MinMax(pDataCali->ccyymin, pDataCali->ccyymax, pDataCali->ccyy);
    pDataCali->ccpp = CML_f_MinMax(pDataCali->ccppmin, pDataCali->ccppmax, pDataCali->ccpp);
    pDataCali->ccrr = CML_f_MinMax(pDataCali->ccrrmin, pDataCali->ccrrmax, pDataCali->ccrr);

    /* local variable */
    pF = pDataCrossCorr->pFullEgoDataBuffer;
    while(pF != NULL)
    {
      /* update cross-correlation between landmark and online cali */
      /* ~CodeReview ~ID:40f7ce8a05eb4873bf0c684c83cf88f4 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:Code makes no sense: Assignment to itself 'pF->cuy = pF->cuy' (9x). */
      /* Godreau B, code review findings priority changed from 1 to 3 : code to clean-up */
      pF->cuy = pF->cuy;
      pF->cvy = pF->cvy;
      pF->cdy = pF->cdy;

      pF->cup = pF->cup;
      pF->cvp = pF->cvp;
      pF->cdp = pF->cdp;

      pF->cur = pF->cur;
      pF->cvr = pF->cvr;
      pF->cdr = pF->cdr;

      pF = pF->next;
    }
  }
  else
  {
    /* prevent updates of online cali angles by setting their covariance to zero */
    pDataCali->ccyy = 0;
    pDataCali->ccpy = 0;     pDataCali->ccpp = 0;
    pDataCali->ccry = 0;     pDataCali->ccrp = 0;                           pDataCali->ccrr = 0;

    /* local variable */
    pF = pDataCrossCorr->pFullEgoDataBuffer;
    while(pF != NULL)
    {
      /* reset cross-correlation between landmark and online cali */
      pF->cuy = 0;
      pF->cvy = 0;
      pF->cdy = 0;

      pF->cup = 0;
      pF->cvp = 0;
      pF->cdp = 0;

      pF->cur = 0;
      pF->cvr = 0;
      pF->cdr = 0;

      pF = pF->next;
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLATrackSlamEstimateEssentialMatrix                              */ /*!  
  Description:      Robust estimation of essential matrix from point matching


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackSlamEstimateEssentialMatrix(       HLATrack_t*                           pTrackStart,
                                                HLATracking3DDataEgomotion_t*         pDataEgomotion,
                                                HLADebugOutputs_t*                    phlaDebugOutputs,
                                          const HLATracking3DDataRotations_t*         pDataRotations,
                                          const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                          const HLATracking3DParametersMeasurement_t* pParamMeas,
                                          const HLASegOut_t*                          pSegOut,
                                          AS_t_GetTimestampuS32                       pfGetTimestampuS32
                                        )
{
  HLATrack_t* apTrackTable[HLA_TRACKING_MAX_NUM_TRACKS];
  HLATrack_t* pTrack;
  HLATrack_t* pTrackRef;

  uint8  numTracks;
  uint8  idTrack;
  uint8  numInlier;
  uint8  numInlierMax;

  uint32  numIter;
  uint32  numIterMax;
  uint32  numIterMaxGlobal;

  float32 numIterFloat;
  float32 outlier_rate;
  float32 prob;
  float32 delta_pitch;

  const float32* pEK;

  float32 ek00, ek01, ek02;
  float32 ek10, ek11, ek12;
  float32 ek20, ek21, ek22;
  float32 ee00, ee01, ee02;
  float32 ee10, ee11, ee12;
  float32 ee20, ee21, ee22;
  float32 ea00, ea01, ea02;
  float32 eb00, eb01;
  float32 eba;
  float32 num;
  float32 den;
  float32 xA,yA;
  float32 xB,yB;
  float32 et00,et01,et02;

  HLAKalmanMeasPos_t lightNorm;

  uint32 TimeStart_us;

  float32 maxRepjErrorPix;
  float32 factor;
  float32 logfprob;
  float32 max_outlier_rate;
  float32 randId;

  /* ----------------------------------------------------------------------------------------- */
  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* init table */
  (void)memset((void*)apTrackTable, 0, HLA_TRACKING_MAX_NUM_TRACKS*sizeof(HLATrack_t*));

  /* get tracks in a pointer table for easy access with IDs */
  numTracks = 0;
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    if(pTrack->light_ref != NULL)
    {
      apTrackTable[numTracks] = pTrack;
      numTracks++;      
    }

    pTrack->TrackingStatus.isEpipolarConsistent = 0;

#ifdef PC_SIM
    if(pTrack->light_ref != NULL)
    {
      HLATrackMeasGetNormCoordinates( &lightNorm,
                                      pTrack->light_ref,
                                      pDataPreComputed,
                                      pParamMeas
                                    );

      pTrack->xs = (lightNorm.x*pDataPreComputed->FX) + pDataPreComputed->XO;
      pTrack->ys = (lightNorm.y*pDataPreComputed->FY) + pDataPreComputed->YO;

      pTrack->dxs = 1.0f*( lightNorm.x - pTrack->ouk )*pDataPreComputed->FX;
      pTrack->dys = 1.0f*( lightNorm.y - pTrack->ovk )*pDataPreComputed->FY;
    }
    else
    {
      pTrack->xs = 0;
      pTrack->ys = 0;
      pTrack->dxs = 0;
      pTrack->dys = 0;
    }
#endif

    pTrack = pTrack->next;
  }

  numIter = 0;

  if(numTracks>2u)
  {
    /* robust essential matrix estimation : see "Multiple View Geometry In Computer Vision. Hartley, Zisserman, 2nd Edition. Chapter 11.6 " */
    /* RANSAC algorithm */

    /* parameters */
    prob = 0.99f;
    maxRepjErrorPix = 2.5f;
    max_outlier_rate = 0.5f;
    numIterMaxGlobal = 15;

    /* pre computed data */
    logfprob = logf(1.0f - prob);
    factor = ((maxRepjErrorPix*maxRepjErrorPix)/(pDataPreComputed->FX*pDataPreComputed->FX));
    pEK = &pDataRotations->EK[0];
    ek00 = pEK[0];    ek01 = pEK[1];    ek02 = pEK[2];
    ek10 = pEK[3];    ek11 = pEK[4];    ek12 = pEK[5];
    ek20 = pEK[6];    ek21 = pEK[7];    ek22 = pEK[8];

    /* initialization */
    numIter = 0;
    numIterMax = numIterMaxGlobal;
    numInlierMax = 0;

    /* seed LCG with actual FrameCount to ensure a kind of reproducibility */
    /* srand(pSegOut->dFrameCnt); */
    seedLCG(pSegOut->FrameCnt);

    /* RANSAC loop */
    while(numIter < numIterMax)
    {
      /* select randomly one track */
      /* randId = ((float32)rand()/RAND_MAX)*(numTracks-1); */
      randId = ( (float32) theLCG() / RAND_MAX ) * (numTracks - 1);

      /* uint8 is always >= 0 */
      idTrack = (uint8)CML_Min(numTracks - 1u, CML_u_Round2Uint(randId));
      pTrackRef = apTrackTable[idTrack];

      /* calculate essential matrix E from the track association */
      /* xb(t)'*E*xb(t-1) = 0 */
      /* we separate E in two parts E = RP*EK */
      /* RP only depends on delta pitch between the two frames */
      /* other parameters are considered as known (yaw from yaw rate, roll=0, translation from pitch and yaw rate) and stored in EK matrix */   
      /* Then, to determine E, we only have to estimate delta_pitch */
      /* XB'*RP*EK*XA = 0 */
      /* XA -> previous position of the track */
      /* XB -> position of the associated light to the track */

      /* calculate ETrack = ET = EK*XA */
      HLATrackMeasGetNormCoordinates( &lightNorm,
                                      pTrackRef->light_ref,
                                      pDataPreComputed,
                                      pParamMeas
                                    );
      
      xA = pTrackRef->ouk;
      yA = pTrackRef->ovk;

      xB = lightNorm.x;
      yB = lightNorm.y;

      et00 = (ek00*xA) + (ek01*yA) + ek02;
      et01 = (ek10*xA) + (ek11*yA) + ek12;
      et02 = (ek20*xA) + (ek21*yA) + ek22;

      /* 
      solve XB'*RP*ET = 0 

                 [1      ] [0    ] [0    ]
      RP       = [0      ] [cosp ] [sinp ]
                 [0      ] [-sinp] [cosp ]

      p = delta_pitch   
      solve for pitch by doing a first order approximation cosp = 1, sinp = delta_pitch 


                 [1      ] [0            ] [0           ]
      RP       = [0      ] [1            ] [delta_pitch ]
                 [0      ] [-delta_pitch ] [1           ]

      
                [ et00                    ]
      RP*ET =   [ et01 + delta_pitch*et02 ]
                [ et02 - delta_pitch*et01 ]


      XB'*RP*ET = xB*et00 + yB*(et01 + delta_pitch*et02) + (et02 - delta_pitch*et01) = 0

                      (xB*et00 + yB*et01 + et02)
      delta_pitch =  ----------------------------
                           et01 - yB*et02 

      */
      num = (xB*et00) + (yB*et01) + et02;
      den = et01 - (yB*et02);

      if( CML_f_IsNonZero(den) )
      {
        delta_pitch = (num)/den;

        /* 
        calculate resulting essentiel matrix E = RP*EK 
                                                              [ek00]                          [ek01]                          [ek02]
                                                              [ek10]                          [ek11]                          [ek12]
                                                              [ek20]                          [ek21]                          [ek22]  

                   [1      ] [0            ] [0           ]   [ek00]                          [ek01]                          [ek02]
        RP       = [0      ] [1            ] [delta_pitch ] = [ek10 + delta_pitch*ek20 ]      [ek11 + delta_pitch*ek21 ]      [ek12 + delta_pitch*ek22 ]      
                   [0      ] [-delta_pitch ] [1           ]   [-delta_pitch*ek10 + ek20]      [-delta_pitch*ek11 + ek21]      [-delta_pitch*ek12 + ek22]        
        
        */
        ee00 = ek00;
        ee01 = ek01;
        ee02 = ek02;

        ee10 = ek10 + (delta_pitch*ek20);
        ee11 = ek11 + (delta_pitch*ek21);
        ee12 = ek12 + (delta_pitch*ek22);

        ee20 = -(delta_pitch*ek10) + ek20;
        ee21 = -(delta_pitch*ek11) + ek21;
        ee22 = -(delta_pitch*ek12) + ek22;

        /* compute number of inliers consistent with estimated essential matrix */
        numInlier = 0;
        pTrack = pTrackStart;
        while(pTrack != NULL)
        {
          pTrack->TrackingStatus.isEpipolarConsistentTemp = 0;

          /* Calculate the reprojection error for current track using estimated essential matrix */
          /* Use Sampson approximation to calculate the reprojection error */
          if(pTrack->light_ref != NULL)
          {
            /* get track positions */
            HLATrackMeasGetNormCoordinates( &lightNorm,
                                            pTrack->light_ref,
                                            pDataPreComputed,
                                            pParamMeas
                                          );
            xA = pTrack->ouk;
            yA = pTrack->ovk;
            xB = lightNorm.x;
            yB = lightNorm.y;

            /* calulate E*xA */
            ea00 = (ee00*xA) + (ee01*yA) + (ee02);
            ea01 = (ee10*xA) + (ee11*yA) + (ee12);
            ea02 = (ee20*xA) + (ee21*yA) + (ee22);

            /* calulate E'*xB */
            eb00 = (ee00*xB) + (ee10*yB) + (ee20);
            eb01 = (ee01*xB) + (ee11*yB) + (ee21);
            /*eb02 = (ee02*xB) + (ee12*yB) + (ee22);*/

            /* calculate xB'*E*xA */ 
            eba = (xB*ea00) + (yB*ea01) + (ea02);

            /* resulting Sampson distance */ 
            num = (eba*eba);
            den = (ea00*ea00) + (ea01*ea01) + (eb00*eb00) + (eb01*eb01);

            /* 
            reprojection error in pixel is dist = sqrt(num/den)*pDataPreComputed->FX
            check (dist < maxRepjErrorPix)

            test is equivalent to ( num < ((maxRepjErrorPix*maxRepjErrorPix)/(FX*FX))*den )
            */
            if( num < (factor * den) )
            {
              pTrack->TrackingStatus.isEpipolarConsistentTemp = 1;
              numInlier++;
            }
          }
         
          pTrack = pTrack->next;
        }


        outlier_rate = 1.0f - ((float32)numInlier / (float32)numTracks);

        /* chose essential matrix with maximum of inliers */
        if(   (numInlier>numInlierMax)
          &&  (outlier_rate<max_outlier_rate)
          )
        {
          numInlierMax = numInlier;
          pTrack = pTrackStart;
          while(pTrack != NULL)
          {
            pTrack->TrackingStatus.isEpipolarConsistent = pTrack->TrackingStatus.isEpipolarConsistentTemp;
            pTrack = pTrack->next;
          }
        }

        /* update numIterMax according to "Multiple View Geometry In Computer Vision. Hartley, Zisserman, 2nd Edition. Chapter 4.7 " */   
        if(CML_f_IsZero(outlier_rate))
        {
          numIterMax = 0;
        }
        else if(CML_f_IsZero(outlier_rate - 1.0f))
        {
          numIterMax = numIterMaxGlobal;
        }
        else
        {          
          numIterFloat = (logfprob/logf(outlier_rate)) + 0.5f;
          /* uint32 is always >= 0 */
          numIterMax = CML_Min(numIterMaxGlobal, CML_u_Round2Uint(numIterFloat));
        }

        numIter++;
      }
      else
      {
        numIterMax = numIterMaxGlobal;
        numIter++;
      }
    }
  }

  /* save number of iterations */
  pDataEgomotion->numIterRANSACEpipol = numIter;

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackUpdateEpipol_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}



/* **************************************************************************** 
  Functionname:     HLATrackSlamUpdate                              */ /*!  
  Description:      update step of slam algo


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackSlamUpdate(      AS_t_GetTimestampuS32                   pfGetTimestampuS32,
                              HLATracking3DDataCali_t*                pDataCali,
                              HLATracking3DDataEgomotion_t*           pDataEgomotion,
                              HLATracking3DDataRotations_t*           pDataRotations,
                              HLADebugOutputs_t*                      phlaDebugOutputs,
                        const HLATracking3DDataCrossCorr_t*           pDataCrossCorr,
                        const HLATracking3DParametersCali_t*          pParamCali,
                        const HLATracking3DDataPreComputed_t*         pDataPreComputed,
                        const HLATracking3DParametersMeasurement_t*   pParamMeas,
                        const HLATracking3DParametersStaticTracker_t* pParamStatic
                       )
{
  FullEgoData_t*      pF;
  HLATrack_t*         pTrack;
  uint32              TimeStart_us;
  uint16              assoc_type;
  HLAKalmanMeasPos_t  lightPosNorm;

  /* ----------------------------------------------------------------------------------------- */
  /* !!!!   time measurement */
  TimeStart_us = pfGetTimestampuS32();

  /* check validity of association before updating full kalman filter */
  pF = pDataCrossCorr->pFullEgoDataBuffer;
  while(pF != NULL)
  {
    pTrack = pF->pTrack;
    if(   (pTrack != 0)
       && (pTrack->light_ref != 0)
      )
    {
      pTrack->light_ref->Status.assoc_type = HLA_TRACKING3D_ASSOCTYPE_STATIC;

      /* ~CodeReview ~ID:cf8472a640346d3b7f7bcebb6bf2dc51 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:2 ~Comment:120938 Commented out code. Some decision to take? Or consider clean-up. */
      /*if(pT->TrackingStatus.isOneToOneAssociation == 1)*/
      if(pTrack->light_ref->Status.isIsolatedLight == 1)
      {
        /* get associated measurement */
        HLATrackMeasGetNormCoordinatesForIsolatedLights(&lightPosNorm,
                                                        pTrack->light_ref,
                                                        pDataPreComputed,
                                                        pParamMeas
                                                       );

        /* prediction */
        HLATrackSlamKalmanPredictOrUpdate(&(assoc_type),
                                          pF,
                                          pDataCali,
                                          pDataEgomotion,
                                          pDataRotations,
                                          pDataCrossCorr,
                                          &(lightPosNorm),
                                          pParamStatic
                                         );

        /* set association type */
        pTrack->light_ref->Status.assoc_type = assoc_type;
      }
    }

    pF = pF->next;
  }
  
  /* ----------------------------------------------------------------------------------------- */
  /* count number of tracks that updates full egomotion */
  pDataEgomotion->numTracksCrossCorrUpdated = 0;

  /* update SLAM kalman feature using the sorted list (from the closest track to prediction to the further one) */
  pF = pDataCrossCorr->pFullEgoDataBufferSorted;
  while(pF != NULL)
  {
    pTrack = pF->pTrack;
    if(   (pTrack != 0)
       && (pTrack->light_ref != 0)
       && (pTrack->light_ref->Status.assoc_type == HLA_TRACKING3D_ASSOCTYPE_STATICROBUST)
       && (pTrack->TrackingStatus.isEpipolarConsistent == 1)
      )
    {
      /* get associated measurement */
      HLATrackMeasGetNormCoordinatesForIsolatedLights(&lightPosNorm,
                                                      pTrack->light_ref,
                                                      pDataPreComputed,
                                                      pParamMeas
                                                     );

      /* update static tracker */
      HLATrackSlamKalmanPredictOrUpdate(0,
                                        pF,
                                        pDataCali,
                                        pDataEgomotion,
                                        pDataRotations,
                                        pDataCrossCorr,
                                        &(lightPosNorm),
                                        pParamStatic
                                       );

      /* update static tracker counter */
      if(pF->stageTrackSlam.statusUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
      {
        if(pF->stageTrackSlam.trackTimeToReinit < HLA_TRACKSTAGE_MAX_TRACK_TIME)
        {
          pF->stageTrackSlam.trackTimeToReinit++;
        }

        pF->stageTrackSlam.lostTime = 0;

        /* count number of tracks that updates full egomotion */
        pDataEgomotion->numTracksCrossCorrUpdated++;
      }
    }

    if(pF->stageTrackSlam.statusUpdate != HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
    {
      pF->stageTrackSlam.winTime = 0;
    }

    pF = pF->next_sorted;
  }

  /* update odometer for on line cali */
  if(   ( pDataEgomotion->numTracksCrossCorrUpdated >= (pParamCali->minNumFullEgoTracksToUpdateOnlineCaliOdometer) )
     && (   (pDataCali->cal_pitch_changed == 1)
         || (pDataCali->cal_yaw_changed   == 1)
         || (pDataCali->cal_roll_changed  == 1)
        )
     )
  {
    if(pDataCali->odometerOnLineCaliM < pParamCali->maxOdometerOnLineCaliM)
    {
      pDataCali->odometerOnLineCaliM += pDataEgomotion->ego_length * ( (float32)(pDataEgomotion->numTracksCrossCorrUpdated)/(float32)(HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR) );
    }
  }

  /* ----------------------------------------------------------------------------------------- */
  /* delayed update step */

  /* update static trackers */
  pF = pDataCrossCorr->pFullEgoDataBuffer;
  while(pF != NULL)
  {
    /* delayed update static tracker */
    HLATrackSlamKalmanDelayedUpdate(pF,
                                    pDataEgomotion,
                                    pDataRotations
                                   );

    pF = pF->next;
  }

  /* delayed update for cross correlations */
  HLATrackSlamKalmanCorrelationsDelayedUpdate(pDataCrossCorr);

  /* ----------------------------------------------------------------------------------------- */
  /* calculate horizon line */
  HLATrackSlamUpdateCaliOutput( pDataCali,
                                pParamCali
                              );

  /* !!!!   time measurement */
  phlaDebugOutputs->timeMeas.dTimeTrackUpdateSlam_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}


/* **************************************************************************** 
  Functionname:     HLATrackSlamUpdateRotations                                           */ /*!  
  Description:      

                    pre-calculated rotations and translations with their derivates along egomotion 
                    variable for measurement equation and delayed update equation.
                    (see comments in HLATracking3DModelMeasurement function
                                     HLATracking3DModelMapUpdateStatic function )

                    RA = RK*RE
                    TA = RA*(- TE)   -   RK*TK

                    TD = RE*(- TE)

                    with (RK,TK) camera to world transform
                    with (RE,TE) interframe world transform

                    -------------------------------------
                    camera to world transform
                    Xk   = RK*( Xw - TK ) 

fB*                   :      [ cos(y)*cos(z)                        ] [ cos(y)*sin(z)                        ] [-sin(y)        ]
fB*                   : RK = [-cos(x)*sin(z) + sin(x)*sin(y)*cos(z) ] [ cos(x)*cos(z) + sin(x)*sin(y)*sin(z) ] [ sin(x)*cos(y) ]
fB*                   :      [ sin(x)*sin(z) + cos(x)*sin(y)*cos(z) ] [-sin(x)*cos(z) + cos(x)*sin(y)*sin(z) ] [ cos(x)*cos(y) ]

                    x = cal_pitch = cp
                    y = cal_roll  = cr
                    z = cal_yaw   = cy

fB*                   :      [ cos(cr)*cos(cy)                           ] [ cos(cr)*sin(cy)                         ] [-sin(cr)         ]
fB*                   : RK = [-cos(cp)*sin(cy) + sin(cp)*sin(cr)*cos(cy) ] [ cos(cp)*cos(cy) + sin(cp)*sincr*sin(cy) ] [ sin(cp)*cos(cr) ]
fB*                   :      [ sin(cp)*sin(cy) + cos(cp)*sin(cr)*cos(cy) ] [-sin(cp)*cos(cy) + cos(cp)*sincr*sin(cy) ] [ cos(cp)*cos(cr) ]


                    -------------------------------------
                    interframe world transform
                    Xw(t) = RE*(Xw(t-1) - RE)

fB*                   :      [ cos(y)*cos(z)                        ] [ cos(y)*sin(z)                        ] [-sin(y)        ]
fB*                   : RE = [-cos(x)*sin(z) + sin(x)*sin(y)*cos(z) ] [ cos(x)*cos(z) + sin(x)*sin(y)*sin(z) ] [ sin(x)*cos(y) ]
fB*                   :      [ sin(x)*sin(z) + cos(x)*sin(y)*cos(z) ] [-sin(x)*cos(z) + cos(x)*sin(y)*sin(z) ] [ cos(x)*cos(y) ]

                      x = interframe world roll   = ego_roll                  = er
                      y = interframe world pitch  = ego_pitch                 = ep
                      z = interframe world yaw    = ego_yaw  =  yaw_rate*dt   = ey

fB*                   :      [ cos(ep)*cos(ey)                           ] [ cos(ep)*sin(ey)                           ] [-sin(ep)         ]
fB*                   : RE = [-cos(er)*sin(ey) + sin(er)*sin(ep)*cos(ey) ] [ cos(er)*cos(ey) + sin(er)*sin(ep)*sin(ey) ] [ sin(er)*cos(ep) ]
fB*                   :      [ sin(er)*sin(ey) + cos(er)*sin(ep)*cos(ey) ] [-sin(er)*cos(ey) + cos(er)*sin(ep)*sin(ey) ] [ cos(er)*cos(ep) ]

                            [ ego_length*cosey ]
                      TE =  [ ego_length*siney ]
                            [ 0                ]
  
                      ego_length = speed*dt + acc*(dt²/2)


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamUpdateRotations(      HLATracking3DDataRotations_t* pDataRotations,
                                        const HLATracking3DDataCali_t*      pDataCali,
                                        const HLATracking3DDataEgomotion_t* pDataEgomotion
                                       )
{
  /* on line cali */
  float32   sincy, coscy;
  float32   sincp, coscp;
  float32   sincr, coscr;
  float32*  RK;
  float32*  dRK_dcy;
  float32*  dRK_dcp;
  float32*  dRK_dcr;
  float32*  TK;
  float32*  VK;

  float32   rkx0, rkx1, rkx2;
  float32   rk00, rk01, rk02, rk10, rk11, rk12,rk20, rk21, rk22;
  float32   tkx, tky, tkz;

  /* egomotion */
  float32   siney, cosey;
  float32   sinep, cosep;
  float32   siner, coser;
  float32*  RE;
  float32*  dRE_dey;
  float32*  dRE_dep;
  float32*  dRE_der;
  float32*  TE;
  float32*  dTE_dey;
  float32*  VE;
  float32*  dVE_dey;
  float32*  dVE_dep;
  float32*  dVE_der;

  float32   tex, tey, tez;
  float32   rex0, rex1, rex2;
  float32   re00, re01, re02, re10, re11, re12,re20, re21, re22;

  /* composition matrices and vector RA / TA */
  float32*  RA;
  float32*  dRA_dcy;
  float32*  dRA_dcp;
  float32*  dRA_dcr;
  float32*  dRA_dey;
  float32*  dRA_dep;
  float32*  dRA_der;

  float32   ra00, ra01, ra02, ra10, ra11, ra12,ra20, ra21, ra22;

  float32*  TA;
  float32*  dTA_dcy;
  float32*  dTA_dcp;
  float32*  dTA_dcr;
  float32*  dTA_dey;
  float32*  dTA_dep;
  float32*  dTA_der;

  float32   tdx, tdy, tdz;

  /* essential sub matrix */
  float32*  EK;
  float32   rf00, rf01, rf02, rf10, rf11, rf12,rf20, rf21, rf22;
  float32   tfx;
  float32   tfy;
  float32   tfz;
  float32   delta_yaw;


  /*-------------------------------------------------------------*/
  /* Online cali */

  /* get pointers */
  RK = &pDataRotations->RK[0];
  dRK_dcy = &pDataRotations->dRK_dcy[0];
  dRK_dcp = &pDataRotations->dRK_dcp[0];
  dRK_dcr = &pDataRotations->dRK_dcr[0];

  /* calculate sin and cos  */
  sincy = sinf( pDataCali->cal_yaw );    coscy = cosf( pDataCali->cal_yaw );
  sincp = sinf( pDataCali->cal_pitch );  coscp = cosf( pDataCali->cal_pitch );
  sincr = sinf( pDataCali->cal_roll );   coscr = cosf( pDataCali->cal_roll );

  /* get world to cam rotation : equivalent to ROT_K 
fB*                   :      [ coscr*coscy                    ] [ coscr*sincy                    ] [-sincr        ]
fB*                   : RK = [-coscp*sincy + sincp*sincr*coscy] [ coscp*coscy + sincp*sincr*sincy] [ sincp*coscr  ]
fB*                   :      [ sincp*sincy + coscp*sincr*coscy] [-sincp*coscy + coscp*sincr*sincy] [ coscp*coscr  ]
  */
  rkx0 = sincr*coscy;
  rkx1 = sincr*sincy;
  rkx2 = coscr;

  rk00 =  (coscr*coscy);                         rk01 =  (coscr*sincy);                         rk02 = -sincr;
  rk10 = -(coscp*sincy) + (sincp*rkx0);          rk11 =  (coscp*coscy) + (sincp*rkx1);          rk12 = sincp*rkx2;
  rk20 =  (sincp*sincy) + (coscp*rkx0);          rk21 = -(sincp*coscy) + (coscp*rkx1);          rk22 = coscp*rkx2;
 
  /* save RK  */
  RK[0] = rk00;        RK[1] = rk01;    RK[2] = rk02;
  RK[3] = rk10;        RK[4] = rk11;    RK[5] = rk12;
  RK[6] = rk20;        RK[7] = rk21;    RK[8] = rk22;

  /* derivate along cal_yaw */
  dRK_dcy[0] = -rk01;   dRK_dcy[1] =  rk00;   /*dRK_dcy[2] = 0;*/
  dRK_dcy[3] = -rk11;   dRK_dcy[4] =  rk10;   /*dRK_dcy[5] = 0;*/
  dRK_dcy[6] = -rk21;   dRK_dcy[7] =  rk20;   /*dRK_dcy[8] = 0;*/

  /* derivate along cal_pitch */
  /* ~CodeReview ~ID:69c13c4bab66c2c98f038ad33a41ead8 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:2 ~Comment:120938 Commented out code. Consider clean-up. */
  /*dRK_dcp[0] = 0;             dRK_dcp[1] = 0;                 dRK_dcp[2] = 0;*/
  dRK_dcp[3] = rk20;          dRK_dcp[4] = rk21;              dRK_dcp[5] = rk22;
  dRK_dcp[6] = -rk10;         dRK_dcp[7] = -rk11;             dRK_dcp[8] = -rk12;

  /* derivate along cal_roll */
  dRK_dcr[0] =  -rkx0;                 dRK_dcr[1] =  -rkx1;                 dRK_dcr[2] = -rkx2;
  dRK_dcr[3] =  sincp*rk00;            dRK_dcr[4] =  sincp*rk01;            dRK_dcr[5] = sincp*rk02;
  dRK_dcr[6] =  coscp*rk00;            dRK_dcr[7] =  coscp*rk01;            dRK_dcr[8] = coscp*rk02;

  /* world to cam translation */
  TK = &pDataRotations->TK[0];
  tkx = TK[0];
  tky = TK[1];
  tkz = TK[2];

  /* VK = -RK*TK */
  VK = &pDataRotations->VK[0];
  VK[0] = -((rk00*tkx) + (rk01*tky) + (rk02*tkz));
  VK[1] = -((rk10*tkx) + (rk11*tky) + (rk12*tkz));
  VK[2] = -((rk20*tkx) + (rk21*tky) + (rk22*tkz));


  /*-------------------------------------------------------------*/
  /* Egomotion */ 

  /* get pointers */
  RE = &pDataRotations->RE[0];
  dRE_dey = &pDataRotations->dRE_dey[0];
  dRE_dep = &pDataRotations->dRE_dep[0];
  dRE_der = &pDataRotations->dRE_der[0];

  /* calculate sin and cos  */
  siney = sinf( pDataEgomotion->ego_yaw );     cosey = cosf( pDataEgomotion->ego_yaw );
  sinep = sinf( pDataEgomotion->ego_pitch );   cosep = cosf( pDataEgomotion->ego_pitch );
  siner = sinf( pDataEgomotion->ego_roll );    coser = cosf( pDataEgomotion->ego_roll );
 
  /* interframe roation 
fB*                   :      [ cosep*cosey                    ] [ cosep*siney                    ] [-sinep        ]
fB*                   : RE = [-coser*siney + siner*sinep*cosey] [ coser*cosey + siner*sinep*siney] [ siner*cosep  ]
fB*                   :      [ siner*siney + coser*sinep*cosey] [-siner*cosey + coser*sinep*siney] [ coser*cosep  ]
*/
  rex0 = sinep*cosey;
  rex1 = sinep*siney;
  rex2 = cosep;

  re00 =  (cosep*cosey);                        re01 =  (cosep*siney);                     re02 = -sinep;
  re10 = -(coser*siney) + (siner*rex0);         re11 =  (coser*cosey) + (siner*rex1);      re12 = siner*rex2;
  re20 =  (siner*siney) + (coser*rex0);         re21 = -(siner*cosey) + (coser*rex1);      re22 = coser*rex2;

  /* save RE */
  RE[0] = re00;        RE[1] = re01;    RE[2] = re02;
  RE[3] = re10;        RE[4] = re11;    RE[5] = re12;
  RE[6] = re20;        RE[7] = re21;    RE[8] = re22;

  /* derivate along ego_yaw  */
  /* ~CodeReview ~ID:add781e03069626a33523e8c421a7076 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (3x). */
  dRE_dey[0] = -re01;            dRE_dey[1] = re00;                 /*dRE_dey[2] = 0;*/
  dRE_dey[3] = -re11;            dRE_dey[4] = re10;                 /*dRE_dey[5] = 0;*/
  dRE_dey[6] = -re21;            dRE_dey[7] = re20;                 /*dRE_dey[8] = 0;*/

  /* derivate along ego_pitch  */
  dRE_dep[0] = -rex0;               dRE_dep[1] = -rex1;             dRE_dep[2] = -rex2;
  dRE_dep[3] = siner*re00;          dRE_dep[4] = siner*re01;        dRE_dep[5] = siner*re02;
  dRE_dep[6] = coser*re00;          dRE_dep[7] = coser*re01;        dRE_dep[8] = coser*re02;

  /* derivate along ego_roll  */
  /*dRE_der[0] = 0;            dRE_der[1] = 0;          dRE_der[2] = 0;*/
  dRE_der[3] = re20;         dRE_der[4] = re21;       dRE_der[5] = re22;
  dRE_der[6] = -re10;        dRE_der[7] = -re11;      dRE_der[8] = -re12;

  /*-------------------------------------------------------------------------------------------------*/
  /* interframe translation TE */

  /* get pointers */
  TE = &pDataRotations->TE[0];
  dTE_dey = &pDataRotations->dTE_dey[0];

  /* interframe translation TE */
  tex = pDataEgomotion->ego_length*cosey;
  tey = pDataEgomotion->ego_length*siney;
  tez = 0;

  /* save TE */
  TE[0] = tex;
  TE[1] = tey;
  TE[2] = tez;

  /* derivate along ego_yaw */
  dTE_dey[0] = - tey;
  dTE_dey[1] = tex;
  dTE_dey[2] = 0;

  /*-------------------------------------------------------------------------------------------------*/
  /* resultant translation vector  VE = -RE*TE */

  /* get pointers */
  VE = &pDataRotations->VE[0];
  dVE_dey = &pDataRotations->dVE_dey[0];
  dVE_dep = &pDataRotations->dVE_dep[0];
  dVE_der = &pDataRotations->dVE_der[0];

  /* resultant translation vector  VE = -RE*TE */
  /* ~CodeReview ~ID:997ea6ff3900a733d8b149d542065755 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (for the rest of this function). */
/*
  VE[0] = -( (re00*tex) + (re01*tey) + (re02*tez) );
  VE[1] = -( (re10*tex) + (re11*tey) + (re12*tez) );
  VE[2] = -( (re20*tex) + (re21*tey) + (re22*tez) );
*/
  VE[0] = -( (re00*tex) + (re01*tey) );
  VE[1] = -( (re10*tex) + (re11*tey) );
  VE[2] = -( (re20*tex) + (re21*tey) );

  /* get derivate along ego_yaw */
/*
  dVE_dey[0] = -( (dRE_dey[0]*tex) + (dRE_dey[1]*tey) + (dRE_dey[2]*tez) + (re00*dTE_dey[0]) + (re01*dTE_dey[1]) + (re02*dTE_dey[2]) );
  dVE_dey[1] = -( (dRE_dey[3]*tex) + (dRE_dey[4]*tey) + (dRE_dey[5]*tez) + (re10*dTE_dey[0]) + (re11*dTE_dey[1]) + (re12*dTE_dey[2]) );
  dVE_dey[2] = -( (dRE_dey[6]*tex) + (dRE_dey[7]*tey) + (dRE_dey[8]*tez) + (re20*dTE_dey[0]) + (re21*dTE_dey[1]) + (re22*dTE_dey[2]) );
*/
/*
  dVE_dey[0] = -( - (re01*tex) + (re00*tey) - (re00*tey) + (re01*tex) );
  dVE_dey[1] = -( - (re11*tex) + (re10*tey) - (re10*tey) + (re11*tex) );
  dVE_dey[2] = -( - (re21*tex) + (re20*tey) - (re20*tey) + (re21*tex) );
*/

  dVE_dey[0] = 0;
  dVE_dey[1] = 0;
  dVE_dey[2] = 0;

  /* get derivate along ego_pitch*/
/*
  dVE_dep[0] = -( (dRE_dep[0]*tex) + (dRE_dep[1]*tey) + (dRE_dep[2]*tez) );
  dVE_dep[1] = -( (dRE_dep[3]*tex) + (dRE_dep[4]*tey) + (dRE_dep[5]*tez) );
  dVE_dep[2] = -( (dRE_dep[6]*tex) + (dRE_dep[7]*tey) + (dRE_dep[8]*tez) );
*/
/*
  dVE_dep[0] = -( (dRE_dep[0]*tex) + (dRE_dep[1]*tey) );
  dVE_dep[1] = -( (dRE_dep[3]*tex) + (dRE_dep[4]*tey) );
  dVE_dep[2] = -( (dRE_dep[6]*tex) + (dRE_dep[7]*tey) );
*/
  dVE_dep[0] = (rex0*tex) + (rex1*tey);
  dVE_dep[1] = siner*VE[0];
  dVE_dep[2] = coser*VE[0];

  /* get derivate along ego_roll*/
/*
  dVE_der[0] = -( (dRE_der[0]*tex) + (dRE_der[1]*tey) + (dRE_der[2]*tez) );
  dVE_der[1] = -( (dRE_der[3]*tex) + (dRE_der[4]*tey) + (dRE_der[5]*tez) );
  dVE_der[2] = -( (dRE_der[6]*tex) + (dRE_der[7]*tey) + (dRE_der[8]*tez) );
*/
  dVE_der[0] = 0;
  dVE_der[1] = VE[2];
  dVE_der[2] = -VE[1];


  /*-------------------------------------------------------------------------------------------------*/
  /* compose rotations RA */

  /* get pointers */
  RA = &pDataRotations->RA[0];
  dRA_dcy = &pDataRotations->dRA_dcy[0];
  dRA_dcp = &pDataRotations->dRA_dcp[0];
  dRA_dcr = &pDataRotations->dRA_dcr[0];
  dRA_dey = &pDataRotations->dRA_dey[0];
  dRA_dep = &pDataRotations->dRA_dep[0];
  dRA_der = &pDataRotations->dRA_der[0];

  /* compose rotations RA = RK*RE  */
  ra00 = (rk00*re00) + (rk01*re10) + (rk02*re20);
  ra01 = (rk00*re01) + (rk01*re11) + (rk02*re21);
  ra02 = (rk00*re02) + (rk01*re12) + (rk02*re22);

  ra10 = (rk10*re00) + (rk11*re10) + (rk12*re20);
  ra11 = (rk10*re01) + (rk11*re11) + (rk12*re21);
  ra12 = (rk10*re02) + (rk11*re12) + (rk12*re22);

  ra20 = (rk20*re00) + (rk21*re10) + (rk22*re20);
  ra21 = (rk20*re01) + (rk21*re11) + (rk22*re21);
  ra22 = (rk20*re02) + (rk21*re12) + (rk22*re22);

  /* save RA */
  RA[0] = ra00;        RA[1] = ra01;    RA[2] = ra02;
  RA[3] = ra10;        RA[4] = ra11;    RA[5] = ra12;
  RA[6] = ra20;        RA[7] = ra21;    RA[8] = ra22;

  /* derivate along cal_yaw dRA = dRK*RE */
  dRA_dcy[0] = -(rk01*re00) + (rk00*re10);  
  dRA_dcy[1] = -(rk01*re01) + (rk00*re11);  
  dRA_dcy[2] = -(rk01*re02) + (rk00*re12);

  dRA_dcy[3] = -(rk11*re00) + (rk10*re10);  
  dRA_dcy[4] = -(rk11*re01) + (rk10*re11);  
  dRA_dcy[5] = -(rk11*re02) + (rk10*re12);

  dRA_dcy[6] = -(rk21*re00) + (rk20*re10);  
  dRA_dcy[7] = -(rk21*re01) + (rk20*re11);  
  dRA_dcy[8] = -(rk21*re02) + (rk20*re12);

  /* derivate along cal_pitch dRA = dRK*RE */
  /*dRA_dcp[0] = 0;            dRA_dcp[1] = 0;          dRA_dcp[2] = 0;*/
  dRA_dcp[3] = ra20;         dRA_dcp[4] = ra21;       dRA_dcp[5] = ra22;
  dRA_dcp[6] = - ra10;       dRA_dcp[7] = - ra11;     dRA_dcp[8] = - ra12;

  /* derivate along cal_roll dRA = dRK*RE */
  dRA_dcr[0] = - ((rkx0*re00) + (rkx1*re10) + (rkx2*re20));
  dRA_dcr[1] = - ((rkx0*re01) + (rkx1*re11) + (rkx2*re21));
  dRA_dcr[2] = - ((rkx0*re02) + (rkx1*re12) + (rkx2*re22));

  dRA_dcr[3] = sincp*ra00;
  dRA_dcr[4] = sincp*ra01;
  dRA_dcr[5] = sincp*ra02;

  dRA_dcr[6] = coscp*ra00;
  dRA_dcr[7] = coscp*ra01;
  dRA_dcr[8] = coscp*ra02;

  /* derivate along ego_yaw dRA = RK*dRE */
  dRA_dey[0] = - ra01;       dRA_dey[1] = ra00;       /*dRA_dey[2] = 0;*/
  dRA_dey[3] = - ra11;       dRA_dey[4] = ra10;       /*dRA_dey[5] = 0;*/
  dRA_dey[6] = - ra21;       dRA_dey[7] = ra20;       /*dRA_dey[8] = 0;*/

  /* derivate along ego_pitch dRA = RK*dRE */
  dRA_dep[0] = (rk00*(-rex0)) + (rk01*dRE_dep[3]) + (rk02*dRE_dep[6]);
  dRA_dep[1] = (rk00*(-rex1)) + (rk01*dRE_dep[4]) + (rk02*dRE_dep[7]);
  dRA_dep[2] = (rk00*(-rex2)) + (rk01*dRE_dep[5]) + (rk02*dRE_dep[8]);

  dRA_dep[3] = (rk10*(-rex0)) + (rk11*dRE_dep[3]) + (rk12*dRE_dep[6]);
  dRA_dep[4] = (rk10*(-rex1)) + (rk11*dRE_dep[4]) + (rk12*dRE_dep[7]);
  dRA_dep[5] = (rk10*(-rex2)) + (rk11*dRE_dep[5]) + (rk12*dRE_dep[8]);

  dRA_dep[6] = (rk20*(-rex0)) + (rk21*dRE_dep[3]) + (rk22*dRE_dep[6]);
  dRA_dep[7] = (rk20*(-rex1)) + (rk21*dRE_dep[4]) + (rk22*dRE_dep[7]);
  dRA_dep[8] = (rk20*(-rex2)) + (rk21*dRE_dep[5]) + (rk22*dRE_dep[8]);

  /* derivate along ego_roll dRA = RK*dRE */
  dRA_der[0] = (rk01*re20) + (rk02*(-re10));  
  dRA_der[1] = (rk01*re21) + (rk02*(-re11));  
  dRA_der[2] = (rk01*re22) + (rk02*(-re12));

  dRA_der[3] = (rk11*re20) + (rk12*(-re10));  
  dRA_der[4] = (rk11*re21) + (rk12*(-re11));  
  dRA_der[5] = (rk11*re22) + (rk12*(-re12));

  dRA_der[6] = (rk21*re20) + (rk22*(-re10));  
  dRA_der[7] = (rk21*re21) + (rk22*(-re11));  
  dRA_der[8] = (rk21*re22) + (rk22*(-re12));


  /*---------------------------------------------------------------------------------------------*/
  /* composed translation TA */

  /* get pointers */
  /* ~CodeReview ~ID:a1504ee4010277510b35e5daf4443976 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:Are these pointers valid? Is a check needed? */
  TA = &pDataRotations->TA[0];
  dTA_dcy = &pDataRotations->dTA_dcy[0];
  dTA_dcp = &pDataRotations->dTA_dcp[0];
  dTA_dcr = &pDataRotations->dTA_dcr[0];
  dTA_dey = &pDataRotations->dTA_dey[0];
  dTA_dep = &pDataRotations->dTA_dep[0];
  dTA_der = &pDataRotations->dTA_der[0];

  /* TA = RA*(-TE)   - RK*TK */
  /* TA = RK*RE*(-TE) - RK*TK */
  /* TA = RK*(VE - TK) */
  /* TA = RK*TD    with     TD = VE - TK */
  tdx = VE[0] - tkx;
  tdy = VE[1] - tky;
  tdz = VE[2] - tkz;

  TA[0] = (rk00*tdx) + (rk01*tdy) + (rk02*tdz);
  TA[1] = (rk10*tdx) + (rk11*tdy) + (rk12*tdz);
  TA[2] = (rk20*tdx) + (rk21*tdy) + (rk22*tdz);

  /* derivate along cal_yaw */
/*
  dTA_dcy[0] = (dRK_dcy[0]*tdx) + (dRK_dcy[1]*tdy) + (dRK_dcy[2]*tdz);
  dTA_dcy[1] = (dRK_dcy[3]*tdx) + (dRK_dcy[4]*tdy) + (dRK_dcy[5]*tdz);
  dTA_dcy[2] = (dRK_dcy[6]*tdx) + (dRK_dcy[7]*tdy) + (dRK_dcy[8]*tdz);
*/
  dTA_dcy[0] = - (rk01*tdx) + (rk00*tdy);
  dTA_dcy[1] = - (rk11*tdx) + (rk10*tdy);
  dTA_dcy[2] = - (rk21*tdx) + (rk20*tdy);

  /* derivate along cal_pitch */
/*
  dTA_dcp[0] = (dRK_dcp[0]*tdx) + (dRK_dcp[1]*tdy) + (dRK_dcp[2]*tdz);
  dTA_dcp[1] = (dRK_dcp[3]*tdx) + (dRK_dcp[4]*tdy) + (dRK_dcp[5]*tdz);
  dTA_dcp[2] = (dRK_dcp[6]*tdx) + (dRK_dcp[7]*tdy) + (dRK_dcp[8]*tdz);
*/
  dTA_dcp[0] = 0;
  dTA_dcp[1] = TA[2];
  dTA_dcp[2] = -TA[1];

  /* derivate along cal_roll */
/*
  dTA_dcr[0] = (dRK_dcr[0]*tdx) + (dRK_dcr[1]*tdy) + (dRK_dcr[2]*tdz);
  dTA_dcr[1] = (dRK_dcr[3]*tdx) + (dRK_dcr[4]*tdy) + (dRK_dcr[5]*tdz);
  dTA_dcr[2] = (dRK_dcr[6]*tdx) + (dRK_dcr[7]*tdy) + (dRK_dcr[8]*tdz);
*/ 
/*
  dTA_dcr[0] = -((rkx0*tdx) + (rkx1*tdy) + (rkx2*tdz));
  dTA_dcr[1] = (sincp*rk00*tdx) + (sincp*rk01*tdy) + (sincp*rk02*tdz);
  dTA_dcr[2] = (coscp*rk00*tdx) + (coscp*rk01*tdy) + (coscp*rk02*tdz);
*/
  dTA_dcr[0] = -((rkx0*tdx) + (rkx1*tdy) + (rkx2*tdz));
  dTA_dcr[1] = sincp*TA[0];
  dTA_dcr[2] = coscp*TA[0];

  /* derivate along ego_yaw */
/*
  dTA_dey[0] = (rk00*dVE_dey[0]) + (rk01*dVE_dey[1]) + (rk02*dVE_dey[2]);
  dTA_dey[1] = (rk10*dVE_dey[0]) + (rk11*dVE_dey[1]) + (rk12*dVE_dey[2]);
  dTA_dey[2] = (rk20*dVE_dey[0]) + (rk21*dVE_dey[1]) + (rk22*dVE_dey[2]);
*/
  
  dTA_dey[0] = 0;
  dTA_dey[1] = 0;
  dTA_dey[2] = 0;
  

  /* derivate along ego_pitch */
  dTA_dep[0] = (rk00*dVE_dep[0]) + (rk01*dVE_dep[1]) + (rk02*dVE_dep[2]);
  dTA_dep[1] = (rk10*dVE_dep[0]) + (rk11*dVE_dep[1]) + (rk12*dVE_dep[2]);
  dTA_dep[2] = (rk20*dVE_dep[0]) + (rk21*dVE_dep[1]) + (rk22*dVE_dep[2]);

  /* derivate along ego_roll */
/*
  dTA_der[0] = (rk00*dVE_der[0]) + (rk01*dVE_der[1]) + (rk02*dVE_der[2]);
  dTA_der[1] = (rk10*dVE_der[0]) + (rk11*dVE_der[1]) + (rk12*dVE_der[2]);
  dTA_der[2] = (rk20*dVE_der[0]) + (rk21*dVE_der[1]) + (rk22*dVE_der[2]);
*/
  dTA_der[0] = (rk01*dVE_der[1]) + (rk02*dVE_der[2]);
  dTA_der[1] = (rk11*dVE_der[1]) + (rk12*dVE_der[2]);
  dTA_der[2] = (rk21*dVE_der[1]) + (rk22*dVE_der[2]);



  /*---------------------------------------------------------------------------------------------*/
  /* 
  Essential sub-matrix EK 

  Essential matrice between two frame: E = RF*[TF]x 
  with RF, rotation between two frames in camera coordinate system 
  with TF, translation between two frames in camera coordinate system 
  with [TF]x, skew matrix of TF 
           [   0]  [-tfz]  [ tfy]
  [TF]x =  [ tfz]  [   0]  [-tfx]
           [-tfy]  [ tfx]  [   0]
  a 3D point in camera cs Xk is transformed between (t) and (t-1):     Xk(t) = RF*(Xk(t-1) - TF) 
  image projections xk are related with the essential matrix:  xk(t)*E*xk(t-1) 


  RF and TF can be calculated from (RE,TE) and (RK,TK)  
  Xk(t) = RK*(Xw(t) - TK )   <=>    Xw(t) = RK'*Xk(t) + TK     
  Xw(t) = RE*(Xw(t-1) - TE) 

  Xk(t) = RK*( RE*(Xw(t-1) - TE)   - TK ) 

  Xk(t) = RK*RE*( (Xw(t-1) - TE)   - RE'*TK ) 

  Xk(t) = RK*RE*( Xw(t-1) - (TE + RE'*TK) ) 

  Xk(t) = RK*RE*( RK'*Xk(t-1) + TK - (TE + RE'*TK) ) 

  Xk(t) = RK*RE*RK'*( Xk(t-1) + RK*(TK - (TE + RE'*TK)) ) 

  Xk(t) = RK*RE*RK'*( Xk(t-1) - RK*((TE + RE'*TK) - TK) ) 

  --------------------------------
  RF = RK*RE*RK' 
  TF = RK*((TE + RE'*TK) - TK) 
  --------------------------------

  simplify TF:
  TF = RK*(TE + RE'*TK - TK)
  TF = RK*(TE + RE'*TK) - RK*TK
  TF = RK*RE'*RK'( RK*RE*TE + RK*RE*RE'*TK) - RK*TK
  TF = RK*RE'*RK'( RA*TE + RK*TK) + VK
  TF = RK*RE'*RK'( -TA) + VK

  --------------------
  TF = RF'( -TA) + VK
  --------------------
  

  Xk(t) = RF*(Xk(t-1) - TF)

  RF = Rx*Ry*Rz

       [1      ] [0      ] [0      ]
  Rx = [0      ] [cos(x) ] [sin(x) ]
       [0      ] [-sin(x)] [cos(x) ]

       [cos(y) ] [0      ] [-sin(y)]
  Ry = [0      ] [1      ] [0      ]
       [sin(y) ] [0      ] [cos(y) ]

       [cos(z) ] [sin(z) ] [0      ]
  Rz = [-sin(z)] [cos(z) ] [0      ]
       [0      ] [0      ] [1      ]


            [cos(y)*cos(z) ]    [cos(y)*sin(z) ]    [-sin(y)]
  Ry*Rz =   [-sin(z)       ]    [cos(z)        ]    [  0    ]
            [sin(y)*cos(z) ]    [sin(y)*sin(z) ]    [cos(y) ]


                    [ cos(y)*cos(z)                       ] [ cos(y)*sin(z)                       ] [-sin(y)         ]
  RF = Rx*(Ry*Rz) = [-cos(x)*sin(z) + sin(x)*sin(y)*cos(z)] [ cos(x)*cos(z) + sin(x)*sin(y)*sin(z)] [ sin(x)*cos(y)  ]
                    [ sin(x)*sin(z) + cos(x)*sin(y)*cos(z)] [-sin(x)*cos(z) + cos(x)*sin(y)*sin(z)] [ cos(x)*cos(y)  ]

  z = interframe camera roll   = fr
  y = interframe camera yaw    = fy
  x = interframe camera pitch  = fp


  considering roll is null between two frames:

  RF = Rx*Ry

  yaw is considered known (via yaw rate fy=yr*dt ) , so

  RF = R(pitch)*RYaw


  Essential matrix is then:


  E = R(pitch)*RYaw*[TF]x

  we can calculate here EK such as 

  E = R(pitch)*EK
                 

                                                          [   0]          [-tfz]                        [ tfy]
                                                          [ tfz]          [   0]                        [-tfx]
                                                   X      [-tfy]          [ tfx]                        [   0]

                          [cos(y) ] [0      ] [-sin(y)]   [ sin(y)*tfy]   [-cos(y)*tfz - sin(y)*tfx]    [cos(y)*tfy]
    EK = RYaw*[TF]x  =    [0      ] [1      ] [0      ] = [        tfz]   [                       0]    [      -tfx]
                          [sin(y) ] [0      ] [ cos(y)]   [-cos(y)*tfy]   [-sin(y)*tfz + cos(y)*tfx]    [sin(y)*tfy]



  

             [1      ] [0    ] [0    ]
  R(pitch) = [0      ] [cosp ] [sinp ]
             [0      ] [-sinp] [cosp ]


  */

  /* compose rotations RF = RK*RE*RK' = RA*RK'  */
  rf00 = (ra00*rk00) + (ra01*rk01) + (ra02*rk02);
  rf01 = (ra00*rk10) + (ra01*rk11) + (ra02*rk12);
  rf02 = (ra00*rk20) + (ra01*rk21) + (ra02*rk22);

  rf10 = (ra10*rk00) + (ra11*rk01) + (ra12*rk02);
  rf11 = (ra10*rk10) + (ra11*rk11) + (ra12*rk12);
  rf12 = (ra10*rk20) + (ra11*rk21) + (ra12*rk22);

  rf20 = (ra20*rk00) + (ra21*rk01) + (ra22*rk02);
  rf21 = (ra20*rk10) + (ra21*rk11) + (ra22*rk12);
  rf22 = (ra20*rk20) + (ra21*rk21) + (ra22*rk22);


  /* translation TF = RF'( -TA) + VK */
  tfx = - ( (rf00*TA[0]) + (rf10*TA[1]) + (rf20*TA[2]) ) + VK[0];
  tfy = - ( (rf01*TA[0]) + (rf11*TA[1]) + (rf21*TA[2]) ) + VK[1];
  tfz = - ( (rf02*TA[0]) + (rf12*TA[1]) + (rf22*TA[2]) ) + VK[2];

  /* test: yaw from RF:  rf02 = -sin(y) */
  delta_yaw = asinf(-rf02);

  /* recalculate siney and cosey in camera cs */
  /*
  siney = sinf(-pDataEgomotion->ego_yaw);
  cosey = cosf(-pDataEgomotion->ego_yaw);
  */
  siney = sinf(delta_yaw);
  cosey = cosf(delta_yaw);

  EK = &pDataRotations->EK[0];
  EK[0] = (siney*tfy);
  EK[1] = -(cosey*tfz) - (siney*tfx);
  EK[2] = (cosey*tfy);

  EK[3] = tfz;
  EK[4] = 0;
  EK[5] = -tfx;

  EK[6] = -(cosey*tfy);
  EK[7] = -(siney*tfz) + (cosey*tfx);
  EK[8] = (siney*tfy);

}


/* **************************************************************************** 
  Functionname:     HLATrackSlamUpdateCaliOutput                                   */ /*!  
  Description:      calculate mean/max/min horizon lines


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamUpdateCaliOutput(       HLATracking3DDataCali_t*        pDataCali, 
                                          const HLATracking3DParametersCali_t*  pParamCali
                                        )
{
  float32 err;

  /* confidence in yaw */
  if(fabsf(pParamCali->errCalYawMax - pParamCali->errCalYawMin) > 0.00001f )
  { 
    err = 3.0f*sqrtf(pDataCali->ccyy);
    pDataCali->cal_yaw_conf   = (pParamCali->errCalYawMax - err)/(pParamCali->errCalYawMax - pParamCali->errCalYawMin);
    pDataCali->cal_yaw_conf   = CML_f_MinMax(0.0f, 1.0f, pDataCali->cal_yaw_conf);
  }
  else
  {
    pDataCali->cal_yaw_conf   = 1.0f;
  }

  /* confidence in pitch */
  if(fabsf(pParamCali->errCalPitchMax - pParamCali->errCalPitchMin) > 0.00001f )
  { 
    err = 3.0f*sqrtf(pDataCali->ccpp);
    pDataCali->cal_pitch_conf   = (pParamCali->errCalPitchMax - err)/(pParamCali->errCalPitchMax - pParamCali->errCalPitchMin);
    pDataCali->cal_pitch_conf   = CML_f_MinMax(0.0f, 1.0f, pDataCali->cal_pitch_conf);
  }
  else
  {
    pDataCali->cal_pitch_conf   = 1.0f;
  }

  /* confidence in roll */
  if(fabsf(pParamCali->errCalRollMax - pParamCali->errCalRollMin) > 0.00001f )
  { 
    err = 3.0f*sqrtf(pDataCali->ccrr);
    pDataCali->cal_roll_conf   = (pParamCali->errCalRollMax - err)/(pParamCali->errCalRollMax - pParamCali->errCalRollMin);
    pDataCali->cal_roll_conf   = CML_f_MinMax(0.0f, 1.0f, pDataCali->cal_roll_conf);
  }
  else
  {
    pDataCali->cal_roll_conf   = 1.0f;
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackSlamAdd                     */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
void HLATrackSlamAdd(       HLATrack_t*                           pTrackStart,
                            HLATracking3DDataCrossCorr_t*         pDataCrossCorr,
                            uint8*                                pnumTracksCrossCorr,
                      const HLATracking3DDataPreComputed_t*       pDataPreComputed, 
                      const HLATracking3DDataCali_t*              pDataCali,
                      const HLATracking3DDataEgomotion_t*         pDataEgomotion,
                      const HLATracking3DDataRotations_t*         pDataRotations,
                      const HLATracking3DParametersMeasurement_t* pParamMeas
                    )
{
  /* local variable */
  HLATrack_t*         pTrack;
  FullEgoData_t*      pF;
  FullEgoData_t*      pFj;
  FullEgoData_t*      pFjInsert;
  HLAKalmanMeasPos_t  lightPosNorm;
 
  /* add new landmark */
  pTrack = pTrackStart;
  while(   (pDataCrossCorr->pFullEgoDataBufferFree != 0)
        && (pTrack != 0)
        )
  {
    if(   (pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_STATIC)
       && (pTrack->light_ref != 0)
       && (pTrack->pFullEgoData == 0)
      )
    {
      /* manage ROLLING BUFFER */

      /*  get next free TrackListnode */
      pF = pDataCrossCorr->pFullEgoDataBufferFree;
      pDataCrossCorr->pFullEgoDataBufferFree = pDataCrossCorr->pFullEgoDataBufferFree->next;

      /* insert new element in order to have a sorted list */
      pFj = pDataCrossCorr->pFullEgoDataBuffer;
      pFjInsert = 0;
      while(pFj != NULL)
      {
        if(   (pF->slot > pFj->slot)
           && (   ( pFj->next==0 )
               || (   ( pFj->next!=0 ) 
                   && ( pF->slot < pFj->next->slot )
                  )
              )
          )
        {
          pFjInsert = pFj;
          break;
        }

        pFj = pFj->next;
      }

      if(pFjInsert!=0)
      {
        pF->next = pFjInsert->next;
        pFjInsert->next = pF;
      }
      else
      {
        /* add new elemt as first elemt of tracking list */
        pF->next = pDataCrossCorr->pFullEgoDataBuffer;

        /* return tracked_lights */
        pDataCrossCorr->pFullEgoDataBuffer = pF;
      }

      /* incremente counter landmarks */
      (*pnumTracksCrossCorr)++;

      /* initialize NEW LANDMARK for full egomotion*/
      pF->pTrack = pTrack;
      pTrack->pFullEgoData = pF;

      /* get associated measurement */
      if(pTrack->light_ref->Status.isIsolatedLight == 1)
      {
        HLATrackMeasGetNormCoordinatesForIsolatedLights(&lightPosNorm,
                                                        pTrack->light_ref,
                                                        pDataPreComputed,
                                                        pParamMeas
                                                       );
      }
      else
      {
        HLATrackMeasGetNormCoordinates( &lightPosNorm,
                                        pTrack->light_ref,
                                        pDataPreComputed,
                                        pParamMeas
                                      );
      }
      /* init slam kalman filter */
      HLATrackSlamKalmanInit( pF,
                              pDataCrossCorr,
                              &(lightPosNorm),
                              pDataPreComputed,
                              pDataCali,
                              pDataEgomotion,
                              pDataRotations
                            );
    }
    /* go to next track */
    pTrack = pTrack->next;
  }
}


/* **************************************************************************** 
  Functionname:     HLATrackSlamKalmanInit                                           */ /*!  
  Description:      initialize static track


  @param[in]        
                    
  @param[out]       
                    

  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamKalmanInit(       FullEgoData_t*                  pFi,
                                    const HLATracking3DDataCrossCorr_t*   pDataCrossCorr,
                                    const HLAKalmanMeasPos_t*             pLNorm,
                                    const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                    const HLATracking3DDataCali_t*        pDataCali,
                                    const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                    const HLATracking3DDataRotations_t*   pDataRotations
                                   )
{
  /* landmark state */
  float32 uw, vw, dw;
  float32 cuu;
  float32 cvu, cvv;
  float32 cdu, cdv, cdd;

  /* online cali uncertainty */ 
  float32 ccyy;
  float32 ccpy, ccpp;
  float32 ccry, ccrp, ccrr;

  /* egomotion to online cali correlations */
  float32 ecyy, ecyp, ecyr;
  float32 ecpy, ecpp, ecpr;
  float32 ecry, ecrp, ecrr;

  /* image measurement */
  float32 xk;
  float32 yk;
  float32 fk;       /* initial depth */

  float32 cxx;
  float32 cyy;
  float32 cff;      /* depth uncertainty */

  /* jacobian */
  float32 HC[9];
  float32 HJ[9];
  
  /* ~CodeReview ~ID:6a7bdf7f858893693c98a003a9251e1e ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (for the rest of this function). */
  /*
  float32 hc0,hc1,hc2;
  float32 hc3,hc4,hc5;
  float32 hc6,hc7,hc8;

  float32 hj0,hj1,hj2;
  float32 hj3,hj4,hj5;
  float32 hj6,hj7,hj8;

  float32 pchcp0,pchcp1,pchcp2;
  float32 pchcp3,pchcp4,pchcp5;
  float32 pchcp6,pchcp7,pchcp8;

  float32 pqhj0,pqhj1,pqhj2;
  float32 pqhj3,pqhj4,pqhj5;
  float32 pqhj6,pqhj7,pqhj8;
  */

  float32 hc0, hc2;
  float32 hc4, hc5;

  float32 hj0, hj2;
  float32 hj4, hj5;
  float32 hj8;

  float32 pchcp0, pchcp1;
  float32 pchcp3, pchcp4;
  float32 pchcp6, pchcp7;

  float32 pqhj0;
  float32 pqhj4;
  float32 pqhj6, pqhj7, pqhj8;

  /* slam data */
  uint8 sloti;
  TracksCrossCorr_t* pCrossCorrelations_i;
  TracksCrossCorr_t* pPij;
  TracksCrossCorr_t* pPji;
  FullEgoData_t*     pFj;
  

  /* reset static counter */
  pFi->stageTrackSlam.trackTimeToReinit = 1;
  pFi->stageTrackSlam.traceTimeToReinit = 1;
  pFi->stageTrackSlam.lostTime = 0;
  pFi->stageTrackSlam.winTime = 0;

  /* get on-line cali */
  ccyy = pDataCali->ccyy;
  ccpy = pDataCali->ccpy;     ccpp = pDataCali->ccpp;
  ccry = pDataCali->ccry;     ccrp = pDataCali->ccrp;     ccrr = pDataCali->ccrr;

  /* correlations between online cali and egomotion */
  ecyy = pDataEgomotion->ecyy;    ecyp = pDataEgomotion->ecyp;     ecyr = pDataEgomotion->ecyr;
  ecpy = pDataEgomotion->ecpy;    ecpp = pDataEgomotion->ecpp;     ecpr = pDataEgomotion->ecpr;
  ecry = pDataEgomotion->ecry;    ecrp = pDataEgomotion->ecrp;     ecrr = pDataEgomotion->ecrr;

  /* get image measurement */
  xk = pLNorm->x;
  yk = pLNorm->y;
  fk = pDataPreComputed->dw_init;

  cxx = pLNorm->cxx;
  cyy = pLNorm->cyy;
  cff = pDataPreComputed->cdd_init;

  /* get uw, vw and dw : projective coordinates in world cs */
  HLATrackModelInit(&uw,
                    &vw,
                    &dw,
                    HJ,
                    HC,
                    xk,
                    yk,
                    fk,
                    pDataRotations
                   );

  /* get jacobians */
  /*
  hj0 = HJ[0];    hj1 = HJ[1];    hj2 = HJ[2];
  hj3 = HJ[3];    hj4 = HJ[4];    hj5 = HJ[5];
  hj6 = HJ[6];    hj7 = HJ[7];    hj8 = HJ[8];

  hc0 = HC[0];    hc1 = HC[1];    hc2 = HC[2];
  hc3 = HC[3];    hc4 = HC[4];    hc5 = HC[5];
  hc6 = HC[6];    hc7 = HC[7];    hc8 = HC[8];
  */
  hj0 = HJ[0];                    hj2 = HJ[2];
                  hj4 = HJ[4];    hj5 = HJ[5];
                                  hj8 = HJ[8];

  hc0 = HC[0];                    hc2 = HC[2];
                  hc4 = HC[4];    hc5 = HC[5];

  /* calculate PQHJp = Q*HJ' */
  /*
  pqhj0 = (cxx*hj0) + (cyx*hj1) + (cfx*hj2);
  pqhj1 = (cxx*hj3) + (cyx*hj4) + (cfx*hj5);
  pqhj2 = (cxx*hj6) + (cyx*hj7) + (cfx*hj8);
 
  pqhj3 = (cyx*hj0) + (cyy*hj1) + (cfy*hj2);
  pqhj4 = (cyx*hj3) + (cyy*hj4) + (cfy*hj5);
  pqhj5 = (cyx*hj6) + (cyy*hj7) + (cfy*hj8);
 
  pqhj6 = (cfx*hj0) + (cfy*hj1) + (cff*hj2);
  pqhj7 = (cfx*hj3) + (cfy*hj4) + (cff*hj5);
  pqhj8 = (cfx*hj6) + (cfy*hj7) + (cff*hj8);
  */

  pqhj0 = (cxx*hj0);
 
  pqhj4 = (cyy*hj4);
 
  pqhj6 = (cff*hj2);
  pqhj7 = (cff*hj5);
  pqhj8 = (cff*hj8);
 
  /* calculate CovUV = H*Q*H' + HC*PC*HC'  = HJ*PQHJp + HC*PCHCp */
  /*
  cuu = (hj0*pqhj0) + (hj1*pqhj3) + (hj2*pqhj6);
  cvu = (hj3*pqhj0) + (hj4*pqhj3) + (hj5*pqhj6);
  cdu = (hj6*pqhj0) + (hj7*pqhj3) + (hj8*pqhj6);

  cvv = (hj3*pqhj1) + (hj4*pqhj4) + (hj5*pqhj7);
  cdv = (hj6*pqhj1) + (hj7*pqhj4) + (hj8*pqhj7);

  cdd = (hj6*pqhj2) + (hj7*pqhj5) + (hj8*pqhj8);
  */

  cuu = (hj0*pqhj0)               + (hj2*pqhj6);
  cvu =                             (hj5*pqhj6);
  cdu =                             (hj8*pqhj6);

  cvv =               (hj4*pqhj4) + (hj5*pqhj7);
  cdv =                             (hj8*pqhj7);

  cdd =                             (hj8*pqhj8);
  
  /* calculate PCHCp = PC*HC' */
  /*
  pchcp0 = (ccyy*hc0) + (ccpy*hc1) + (ccry*hc2);
  pchcp1 = (ccyy*hc3) + (ccpy*hc4) + (ccry*hc5);
  pchcp2 = (ccyy*hc6) + (ccpy*hc7) + (ccry*hc8);

  pchcp3 = (ccpy*hc0) + (ccpp*hc1) + (ccrp*hc2);
  pchcp4 = (ccpy*hc3) + (ccpp*hc4) + (ccrp*hc5);
  pchcp5 = (ccpy*hc6) + (ccpp*hc7) + (ccrp*hc8);

  pchcp6 = (ccry*hc0) + (ccrp*hc1) + (ccrr*hc2);
  pchcp7 = (ccry*hc3) + (ccrp*hc4) + (ccrr*hc5);
  pchcp8 = (ccry*hc6) + (ccrp*hc7) + (ccrr*hc8);
  */
  pchcp0 = (ccyy*hc0)              + (ccry*hc2);
  pchcp1 =              (ccpy*hc4) + (ccry*hc5);

  pchcp3 = (ccpy*hc0)              + (ccrp*hc2);
  pchcp4 =              (ccpp*hc4) + (ccrp*hc5);

  pchcp6 = (ccry*hc0)              + (ccrr*hc2);
  pchcp7 =              (ccrp*hc4) + (ccrr*hc5);


  /* calculate CovUV = H*Q*H' + HC*PC*HC'  = HJ*PQHJp + HC*PCHCp */
  /*
  cuu += (hc0*pchcp0) + (hc1*pchcp3) + (hc2*pchcp6);
  cvu += (hc3*pchcp0) + (hc4*pchcp3) + (hc5*pchcp6);
  cdu += (hc6*pchcp0) + (hc7*pchcp3) + (hc8*pchcp6);

  cvv += (hc3*pchcp1) + (hc4*pchcp4) + (hc5*pchcp7);
  cdv += (hc6*pchcp1) + (hc7*pchcp4) + (hc8*pchcp7);

  cdd += (hc6*pchcp2) + (hc7*pchcp5) + (hc8*pchcp8);
  */

  cuu += (hc0*pchcp0)                + (hc2*pchcp6);
  cvu +=                (hc4*pchcp3) + (hc5*pchcp6);

  cvv +=                (hc4*pchcp4) + (hc5*pchcp7);

  /* update cross-correlation between landmark and online cali */
  /* PCJ = HC*PC = (PCHCp)' */
  pFi->cuy = pchcp0;      pFi->cup = pchcp3;      pFi->cur = pchcp6;
  pFi->cvy = pchcp1;      pFi->cvp = pchcp4;      pFi->cvr = pchcp7;
  pFi->cdy = 0;           pFi->cdp = 0;           pFi->cdr = 0;        


  /* update cross-correlation between landmark and egomotion */
  /* PEJ = HC*PCE' = 0 */
  /*
  pFi->euy = (hc0*ecyy) + (hc1*ecyp) + (hc2*ecyr);
  pFi->eup = (hc0*ecpy) + (hc1*ecpp) + (hc2*ecpr);
  pFi->eur = (hc0*ecry) + (hc1*ecrp) + (hc2*ecrr);
  
  pFi->evy = (hc3*ecyy) + (hc4*ecyp) + (hc5*ecyr);
  pFi->evp = (hc3*ecpy) + (hc4*ecpp) + (hc5*ecpr);
  pFi->evr = (hc3*ecry) + (hc4*ecrp) + (hc5*ecrr);

  pFi->edy = (hc6*ecyy) + (hc7*ecyp) + (hc8*ecyr);
  pFi->edp = (hc6*ecpy) + (hc7*ecpp) + (hc8*ecpr);
  pFi->edr = (hc6*ecry) + (hc7*ecrp) + (hc8*ecrr);
  */

  pFi->euy = (hc0*ecyy)              + (hc2*ecyr);
  pFi->eup = (hc0*ecpy)              + (hc2*ecpr);
  pFi->eur = (hc0*ecry)              + (hc2*ecrr);
  
  pFi->evy =              (hc4*ecyp) + (hc5*ecyr);
  pFi->evp =              (hc4*ecpp) + (hc5*ecpr);
  pFi->evr =              (hc4*ecrp) + (hc5*ecrr);

  pFi->edy = 0;
  pFi->edp = 0;
  pFi->edr = 0;


  /* init cross-correlation with other landmarks */
  sloti = pFi->slot;
  pCrossCorrelations_i = pFi->pCrossCorrelations;

  pFj = pDataCrossCorr->pFullEgoDataBuffer;
  while(pFj != NULL)
  {
    if(pFj != pFi)
    {
      /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 09.05.2011 reason: pointer comparison wanted to save runtime */
      if(pFj < pFi)
      {
        pPij = pCrossCorrelations_i + pFj->slot;

        /* PIJ = HC * PCJ' */ 
        /*
        pPij->cuu = (hc0*pFj->cuy) + (hc1*pFj->cup) + (hc2*pFj->cur);
        pPij->cuv = (hc0*pFj->cvy) + (hc1*pFj->cvp) + (hc2*pFj->cvr);
        pPij->cud = (hc0*pFj->cdy) + (hc1*pFj->cdp) + (hc2*pFj->cdr);

        pPij->cvu = (hc3*pFj->cuy) + (hc4*pFj->cup) + (hc5*pFj->cur);
        pPij->cvv = (hc3*pFj->cvy) + (hc4*pFj->cvp) + (hc5*pFj->cvr);
        pPij->cvd = (hc3*pFj->cdy) + (hc4*pFj->cdp) + (hc5*pFj->cdr);

        pPij->cdu = (hc6*pFj->cuy) + (hc7*pFj->cup) + (hc8*pFj->cur);
        pPij->cdv = (hc6*pFj->cvy) + (hc7*pFj->cvp) + (hc8*pFj->cvr);
        pPij->cdd = (hc6*pFj->cdy) + (hc7*pFj->cdp) + (hc8*pFj->cdr);
        */
        pPij->cuu = (hc0*pFj->cuy)                  + (hc2*pFj->cur);
        pPij->cuv = (hc0*pFj->cvy)                  + (hc2*pFj->cvr);
        pPij->cud = (hc0*pFj->cdy)                  + (hc2*pFj->cdr);

        pPij->cvu =                  (hc4*pFj->cup) + (hc5*pFj->cur);
        pPij->cvv =                  (hc4*pFj->cvp) + (hc5*pFj->cvr);
        pPij->cvd =                  (hc4*pFj->cdp) + (hc5*pFj->cdr);

        pPij->cdu = 0;
        pPij->cdv = 0;
        pPij->cdd = 0;
      }
      else
      {
        pPji = pFj->pCrossCorrelations + sloti;

        /* PJI = PCJ * HC' */ 
        /*
        pPji->cuu = (hc0 * pFj->cuy) + (hc1 * pFj->cup) + (hc2 * pFj->cur);
        pPji->cuv = (hc3 * pFj->cuy) + (hc4 * pFj->cup) + (hc5 * pFj->cur);
        pPji->cud = (hc6 * pFj->cuy) + (hc7 * pFj->cup) + (hc8 * pFj->cur);

        pPji->cvu = (hc0 * pFj->cvy) + (hc1 * pFj->cvp) + (hc2 * pFj->cvr);
        pPji->cvv = (hc3 * pFj->cvy) + (hc4 * pFj->cvp) + (hc5 * pFj->cvr);
        pPji->cvd = (hc6 * pFj->cvy) + (hc7 * pFj->cvp) + (hc8 * pFj->cvr);

        pPji->cdu = (hc0 * pFj->cdy) + (hc1 * pFj->cdp) + (hc2 * pFj->cdr);
        pPji->cdv = (hc3 * pFj->cdy) + (hc4 * pFj->cdp) + (hc5 * pFj->cdr);
        pPji->cdd = (hc6 * pFj->cdy) + (hc7 * pFj->cdp) + (hc8 * pFj->cdr);
        */

        pPji->cuu = (hc0 * pFj->cuy)                    + (hc2 * pFj->cur);
        pPji->cuv =                    (hc4 * pFj->cup) + (hc5 * pFj->cur);
        pPji->cud = 0;

        pPji->cvu = (hc0 * pFj->cvy)                    + (hc2 * pFj->cvr);
        pPji->cvv =                    (hc4 * pFj->cvp) + (hc5 * pFj->cvr);
        pPji->cvd = 0;

        pPji->cdu = (hc0 * pFj->cdy)                    + (hc2 * pFj->cdr);
        pPji->cdv =                    (hc4 * pFj->cdp) + (hc5 * pFj->cdr);
        pPji->cdd = 0;
      }
    }
   
    pFj = pFj->next;
  }

  /* fill landmark covariance matrix element */
  pFi->uw = uw;
  pFi->vw = vw;
  pFi->dw = dw;

  pFi->cuu = cuu;
  pFi->cvu = cvu;     pFi->cvv = cvv;
  pFi->cdu = cdu;     pFi->cdv = cdv;   pFi->cdd = cdd;
}


/* **************************************************************************** 
  Functionname:     HLATrackSlamKalmanPredictOrUpdate                                           */ /*!  
  Description:      measurement equation of the extended Kalman filter (static and full)

  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamKalmanPredictOrUpdate(      uint16*                                 p_assoc_type,
                                                    FullEgoData_t*                          pFj,
                                                    HLATracking3DDataCali_t*                pDataCali,
                                                    HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                                    HLATracking3DDataRotations_t*           pDataRotations,
                                              const HLATracking3DDataCrossCorr_t*           pDataCrossCorr,
                                              const HLAKalmanMeasPos_t*                     pLNorm,
                                              const HLATracking3DParametersStaticTracker_t* pParamStatic
                                             )
{
  /* online cali */
  float32 cal_yaw;
  float32 cal_pitch;
  float32 cal_roll;
  float32 ccyy;
  float32 ccpy, ccpp;
  float32 ccry, ccrp, ccrr;

  /* egomotion */
  float32 ego_yaw;
  float32 ego_pitch;
  float32 ego_roll;
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* correlations between online cali and egomotion */
  float32 ecyy, ecyp, ecyr;
  float32 ecpy, ecpp, ecpr;
  float32 ecry, ecrp, ecrr;

  /* 3D landmark  */
  float32 uw;
  float32 vw;
  float32 dw;

  float32 cuu;
  float32 cvu, cvv;
  float32 cdu, cdv, cdd;

  /* cross-correlation between landmark and online cali */
  float32 cuy, cup, cur;
  float32 cvy, cvp, cvr;
  float32 cdy, cdp, cdr;

  /* cross-correlation between landmark and egomotion */
  float32 euy, eup, eur;
  float32 evy, evp, evr;
  float32 edy, edp, edr;

  /* innovation */
  float32 xpj, ypj;
  float32 sxx;
  float32 sxy,syy;

  float32 sixx;
  float32 sixy,siyy;

  float32 dxj,dyj;
  float32 dist;

  /* kalman gain */
  float32 pchp0, pchp1;
  float32 pchp2, pchp3;
  float32 pchp4, pchp5;

  float32 pehp0, pehp1;
  float32 pehp2, pehp3;
  float32 pehp4, pehp5;

  float32 pjhp0, pjhp1;
  float32 pjhp2, pjhp3;
  float32 pjhp4, pjhp5;

  float32 pihp0, pihp1;
  float32 pihp2, pihp3;
  float32 pihp4, pihp5;

  float32 kc0, kc1, kc2, kc3, kc4, kc5;
  float32 ke0, ke1, ke2, ke3, ke4, ke5;
  float32 kj0, kj1, kj2, kj3, kj4, kj5;
  float32 ki0, ki1, ki2, ki3, ki4, ki5;
  
  /* measurement equation jacobians */
  float32 HC[6];
  float32 HE[6];
  float32 HJ[6];

  float32 hc0, hc2;
  /* <ln_offset:+1 PCLINT Error 793: reviewer name: Bertrand Godreau date: 09.05.2011 reason: declare more than 127 identifiers in the function to speed-up calculations */
  float32 hc4, hc5;

  float32 he0;
  float32 he4, he5;

  float32 hj0, hj2;
  float32 hj4, hj5;

  /* pointer to other landmarks and cross-correlations */
  TracksCrossCorr_t*  pPij;
  TracksCrossCorr_t*  pPji;
  TracksCrossCorr_t*  pCrossCorrelations_j;
  FullEgoData_t*      pFi;
  uint8 sloti, slotj;

  /*-----------------------------------------------------------------------------------------*/
  /* get state */

  /* get 3D landmark */
  uw = pFj->uw;
  vw = pFj->vw;
  dw = pFj->dw;

  cuu = pFj->cuu;
  cvu = pFj->cvu;    cvv = pFj->cvv;
  cdu = pFj->cdu;    cdv = pFj->cdv;    cdd = pFj->cdd;

  /* get on-line cali PC */
  cal_yaw    = pDataCali->cal_yaw;
  cal_pitch  = pDataCali->cal_pitch;
  cal_roll   = pDataCali->cal_roll;

  ccyy = pDataCali->ccyy;
  ccpy = pDataCali->ccpy;     ccpp = pDataCali->ccpp;
  ccry = pDataCali->ccry;     ccrp = pDataCali->ccrp;     ccrr = pDataCali->ccrr;

  /* get egomotion PE */
  ego_yaw    = pDataEgomotion->ego_yaw;
  ego_pitch  = pDataEgomotion->ego_pitch;
  ego_roll   = pDataEgomotion->ego_roll;

  eeyy = pDataEgomotion->eeyy;
  eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
  eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;

  /* correlations between online cali and egomotion PEC */
  ecyy = pDataEgomotion->ecyy;    ecyp = pDataEgomotion->ecyp;     ecyr = pDataEgomotion->ecyr;
  ecpy = pDataEgomotion->ecpy;    ecpp = pDataEgomotion->ecpp;     ecpr = pDataEgomotion->ecpr;
  ecry = pDataEgomotion->ecry;    ecrp = pDataEgomotion->ecrp;     ecrr = pDataEgomotion->ecrr;

  /* get cross-correlation between landmark and online cali PJC */
  cuy = pFj->cuy;  cup = pFj->cup;  cur = pFj->cur;
  cvy = pFj->cvy;  cvp = pFj->cvp;  cvr = pFj->cvr;
  cdy = pFj->cdy;  cdp = pFj->cdp;  cdr = pFj->cdr;

  /* get cross-correlation between landmark and egomotion PJE */
  euy = pFj->euy;  eup = pFj->eup;  eur = pFj->eur;
  evy = pFj->evy;  evp = pFj->evp;  evr = pFj->evr;
  edy = pFj->edy;  edp = pFj->edp;  edr = pFj->edr;



  /*-----------------------------------------------------------------------------------------*/
  /* predict landmark */
  HLATrackModelMeasurement( pFj->uw,
                            pFj->vw,
                            pFj->dw,
                            1.0f,
                            &(xpj),
                            &(ypj),
                            HC,
                            HE,
                            HJ,
                            pDataRotations
                          );

  /*-----------------------------------------------------------------------------------------*/
  /* get jacobians */
  he0 = HE[0];            /*he1 = 0;*/          /*he2 = 0;*/
  /*he3 = 0;*/            he4 = HE[4];          he5 = HE[5];

  hj0 = HJ[0];            /*hj1 = 0;*/          hj2 = HJ[2];
  /*hj3 = 0;*/            hj4 = HJ[4];          hj5 = HJ[5];

  hc0 = HC[0];            /*hc1 = 0;*/          hc2 = HC[2];
  /*hc3 = 0;*/            hc4 = HC[4];          hc5 = HC[5];


  /* ------------------------------------------------------------------------------------------*/
  /* kalman filter block matrices */
  /*

  STATE VECTOR:

  (example with 2 landmarks I,J)  (max of 12 landmarks)

                                    o      e      l      l
                                    n      g      a      a
                                    l      o      n      n
                                    i      m      d      d 
                                    n      o      m      m
                                    e      t      a      a
                                    -      i      r      r
                                    c      o      k      k
                                    a      n               
                                    l             I      J
                                    i      |               
                                           |      |      |
                                    |      |      |      |
                                    |      |      |      |
                                    |      |      |      |
                   
   online-cali ----- [ XC ] ---  [ PC    PEC'   PIC'   PJC' ]  
                     [    ]      [                          ]  
   egomotion ------- [ XE ] ---  [ PEC   PE     PIE'   PJE' ]  
                     [    ]      [                          ]  
   landmark I ------ [ XI ] ---  [ PIC   PIE    PI     PJI' ]  
                     [    ]      [                          ]  
   landmark J -------[ XJ ]----- [ PJC   PJE    PJI    PJ   ]  

                  (state vector)     (correlation matrix)


  MEASUREMENT:

  landmark J prediction XPJ (projection on the imager)
  
  [XPJ,H] = meas_function(XC, XE, XJ)   (independant of other landmarks)

  with jacobian output :  H = [ HC    HE     0      HJ   ] 


  INNOVATION AND KALMAN GAIN:

  innovation: S = H*P*H' + CJ

  with CJ, noise on the associated measurement XMJ  ( light from segmentation )

  kalman gain: K = PH'*inv(S)



                                o      e      l      l
                                n      g      a      a
                                l      o      n      n                                                                                    ------------<----------<-------
                                i      m      d      d                                                                                    |                             |
                                n      o      m      m                                                                                    |                             ^
                                e      t      a      a                                                                                    |           K                 |
                                -      i      r      r                                                                                    |           A                 |
                                c      o      k      k                                                                                    |           L                 |
                                a      n                                                                                                  |           M                 |
                                l             I      J        [ HC' ]                                                                     |           A                 |
                                i      |                      [     ]                                                                     |           N                 |
                                       |      |      |        [ HE' ]                                                                     |                             |
                                |      |      |      |        [     ]                                                                     |           G                 |
                                |      |      |      |        [  0  ]                               (inverse of innovation matrix) -> [  inv(S) ]     A                 |
                                |      |      |      |        [     ]                                                                     ||          I                 |
                                                              [ HJ' ]                                                                 [   Si    ]     N                 |
              (covariance matrix with 2 landmarks I,J)      X                                                                       X                                   |
 online-cali ---------------  [ PC    PEC'   PIC'   PJC' ]    [ PC*HC'  + PEC'*HE' + PJC'*HJ' ]   [ PCHp ] - - - - - - - - - - - - -  [ PCHp*Si ]   [ KC ]              |
                              [                          ]    [                               ]   [      ]                            [         ]   [    ]              |
 egomotion -----------------  [ PEC   PE     PIE'   PJE' ]    [ PEC*HC' + PE*HE'   + PJE'*HJ' ]   [ PEHp ] - - - - - - - - - - - - -  [ PEHp*Si ]   [ KE ]              |
                              [                          ]    [                               ] = [      ]                            [         ] = [    ]              |
 landmark I ----------------  [ PIC   PIE    PI     PJI' ]    [ PIC*HC' + PIE*HE'  + PJI'*HJ' ]   [ PIHp ] - - - - - - - - - - - - -  [ PIHp*Si ]   [ KI ]              |
                              [                          ]    [                               ]   [      ]                            [         ]   [    ]              |
 landmark J ----------------- [ PJC   PJE    PJI    PJ   ]    [ PJC*HC' + PJE*HE'  + PJ'*HJ'  ]   [ PJHp ] - - - - - - - - - - - - -  [ PJHp*Si ]   [ KJ ]              ^
                                                                                                                                                                        |
                                                                                                X                                                                       |  
landmark J prediction     --- [ HC    HE     0      HJ   ]  - - - - - - - - - - - - - - - - - -   [ HC*PCHp + HE*PEHp + HJ*PJHp ]   (uncertainty on prediction)         |
(projection)                  (jacobian of the measurement equation for landmark J)                                                                                     |
                                                                                                                 +                                                      |
                                                                                                                                                                        |
                                                                                                               [ CJ ]            |
                                                                                                                                                                        |
                                                                                                                ||                                                      |
                                                                                                                                                                        |
                                                                                                               [ S ]                                                    |
                                                                                                                                                                        |
                                                                                                         (innovation matrix) ------------------>-------------->----------




  KALMAN UPDATE:

  using difference between mesurement and prediction :  DXJ = XJM - XJP 

  X = X + K*DXJ

  online-cali ---------------  XC = XC + KC*DXJ
  egomotion -----------------  XE = XE + KE*DXJ
  landmark I ----------------  XI = XI + KI*DXJ
  landmark J ----------------  XJ = XJ + KJ*DXJ



  P = P - PH'*K'



                                                                               [ KC'        KE'        KI'        KJ'     ]
                                                                            X                                           
   [ PC                       ]   [ PC                       ]      [ PCHp ]   [ PCHp*KC                                  ]
   [                          ]   [                          ]      [      ]   [                                          ]
   [ PEC   PE                 ]   [ PEC   PE                 ]      [ PEHp ]   [ PEHp*KC    PEHp*KE                       ]
   [                          ] = [                          ]  -   [      ]   [                                          ]
   [ PIC   PIE    PI          ]   [ PIC   PIE    PI          ]      [ PIHp ]   [ PIHp*KC    PIHp*KE    PIHp*KI            ]
   [                          ]   [                          ]      [      ]   [                                          ]
   [ PJC   PJE    PJI    PJ   ]   [ PJC   PJE    PJI    PJ   ]      [ PJHp ]   [ PJHp*KC    PJHp*KE    PJHp*KI    PJHp*KJ ] 


  */


  /*-----------------------------------------------------------------------------------------*/
  /* calculate innovation matrix */     

  /* PCHp = PC*HC'  + PEC'*HE' + PJC'*HJ' */
  pchp0 = (ccyy * hc0) + (ccry * hc2) + (ecyy * he0);
  pchp1 = (ccpy * hc4) + (ccry * hc5) + (ecpy * he4) + (ecry * he5);

  pchp2 = (ccpy * hc0) + (ccrp * hc2) + (ecyp * he0);
  pchp3 = (ccpp * hc4) + (ccrp * hc5) + (ecpp * he4) + (ecrp * he5);

  pchp4 = (ccry * hc0) + (ccrr * hc2) + (ecyr * he0);
  pchp5 = (ccrp * hc4) + (ccrr * hc5) + (ecpr * he4) + (ecrr * he5);


  pchp0 += (cuy * hj0) + (cdy * hj2);
  pchp1 += (cvy * hj4) + (cdy * hj5);

  pchp2 += (cup * hj0) + (cdp * hj2);
  pchp3 += (cvp * hj4) + (cdp * hj5);

  pchp4 += (cur * hj0) + (cdr * hj2);
  pchp5 += (cvr * hj4) + (cdr * hj5);

  /* PEHp = PEC*HC' + PE*HE'   + PJE'*HJ' */
  pehp0 = (ecyy * hc0) + (ecyr * hc2);
  pehp1 = (ecyp * hc4) + (ecyr * hc5);

  pehp2 = (ecpy * hc0) + (ecpr * hc2);
  pehp3 = (ecpp * hc4) + (ecpr * hc5);

  pehp4 = (ecry * hc0) + (ecrr * hc2);
  pehp5 = (ecrp * hc4) + (ecrr * hc5);


  pehp0 += (eeyy * he0);
  pehp1 += (eepy * he4) + (eery * he5);

  pehp2 += (eepy * he0);
  pehp3 += (eepp * he4) + (eerp * he5);

  pehp4 += (eery * he0);
  pehp5 += (eerp * he4) + (eerr * he5);


  pehp0 += (euy * hj0) + (edy * hj2);
  pehp1 += (evy * hj4) + (edy * hj5);

  pehp2 += (eup * hj0) + (edp * hj2);
  pehp3 += (evp * hj4) + (edp * hj5);

  pehp4 += (eur * hj0) + (edr * hj2);
  pehp5 += (evr * hj4) + (edr * hj5);

  /* PJHp = PJC*HC' + PJE*HE'  + PJ'*HJ' */
  pjhp0 = (cuy * hc0) + (cur * hc2) + (euy * he0);
  pjhp1 = (cup * hc4) + (cur * hc5) + (eup * he4) + (eur * he5);

  pjhp2 = (cvy * hc0) + (cvr * hc2) + (evy * he0);
  pjhp3 = (cvp * hc4) + (cvr * hc5) + (evp * he4) + (evr * he5);

  pjhp4 = (cdy * hc0) + (cdr * hc2) + (edy * he0);
  pjhp5 = (cdp * hc4) + (cdr * hc5) + (edp * he4) + (edr * he5);


  pjhp0 += (cuu * hj0) + (cdu * hj2);
  pjhp1 += (cvu * hj4) + (cdu * hj5);

  pjhp2 += (cvu * hj0) + (cdv * hj2);
  pjhp3 += (cvv * hj4) + (cdv * hj5);

  pjhp4 += (cdu * hj0) + (cdd * hj2);
  pjhp5 += (cdv * hj4) + (cdd * hj5);


  /*----------------------------------------------------------*/
  /* innovation */
  /* S = HC*PCHp + HE*PEHp + HJ*PJHp */
  sxx = (hc0 * pchp0) + (hc2 * pchp4);
  sxy = (hc4 * pchp2) + (hc5 * pchp4);
  syy = (hc4 * pchp3) + (hc5 * pchp5);
  
  sxx += (he0 * pehp0);
  sxy += (he4 * pehp2) + (he5 * pehp4);
  syy += (he4 * pehp3) + (he5 * pehp5);

  sxx += (hj0 * pjhp0) + (hj2 * pjhp4);
  sxy += (hj4 * pjhp2) + (hj5 * pjhp4);
  syy += (hj4 * pjhp3) + (hj5 * pjhp5);

  /* init association type */
  if(p_assoc_type != NULL)
  {
    *p_assoc_type = HLA_TRACKING3D_ASSOCTYPE_DYNAMIC;
  }

  if( (sxx<0)||(syy<0) )
  {
  }
  else
  {
    /* set prediction flag */
    pFj->stageTrackSlam.statusPred = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;

    /*-----------------------------------------------------------------------------------------*/
    /* KALMAN UPDATE if associated measure avalaible */
    if(pLNorm != NULL)
    {
      /* add measurement noise */
      sxx += pLNorm->cxx;
      syy += pLNorm->cyy;

      /* inverse innovation */
      boolean bInverseSuccess = HLATrackUtilsInverseInnovation(sxx, syy, sxy, &sixx, &siyy, &sixy);

      if(bInverseSuccess == b_FALSE)
      {
        /* do nothing */
      }
      else
      {
        /* calculate diff vector */
        dxj = pLNorm->x - xpj;
        dyj = pLNorm->y - ypj;

        /* get association type (static, static robust) */
        if(p_assoc_type != NULL)
        {         
          /* mahalanobis distance */
          dist =  dxj * dxj * sixx;
          dist += dyj * dyj * siyy;
          dist += dxj * dyj * (sixy + sixy);

          /* look if light is inside static prediction area */
          if(   (dist >= 0.0f )
             && (dist < HLA_CHI2_VALUE_N2)
            )
          {
            /* associate light to track as static */
            (*p_assoc_type) = HLA_TRACKING3D_ASSOCTYPE_STATIC;

            /* check if static association is robust */
            /* ~CodeReview ~ID:de99e6d3201a12f87afa75dc4ce3cbe4 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:Potential division by zero. The if condition states that sxx can be zero. Probably the measured noise "pLNorm->cxx" can be 0. */
            /* Godreau B, code review findings priority changed from 1 to 3 : pLNorm->cxx can not be zero */
            dist = (dxj*dxj)/(sxx);

            if( dist < pParamStatic->chi2_1_StaticRobust )
            {
              (*p_assoc_type) = HLA_TRACKING3D_ASSOCTYPE_STATICROBUST;
            }
          }
        }
        else
        {
          /* ------------------------------------------------------*/
          /* Kalman Gain KC = PCHp*Sinv */
          kc0 = (pchp0 * sixx) + (pchp1 * sixy);
          kc1 = (pchp0 * sixy) + (pchp1 * siyy);
          kc2 = (pchp2 * sixx) + (pchp3 * sixy);
          kc3 = (pchp2 * sixy) + (pchp3 * siyy);
          kc4 = (pchp4 * sixx) + (pchp5 * sixy);
          kc5 = (pchp4 * sixy) + (pchp5 * siyy);

          /* Kalman Gain KE = PEHp*Sinv */
          ke0 = (pehp0 * sixx) + (pehp1 * sixy);
          ke1 = (pehp0 * sixy) + (pehp1 * siyy);
          ke2 = (pehp2 * sixx) + (pehp3 * sixy);
          ke3 = (pehp2 * sixy) + (pehp3 * siyy);
          ke4 = (pehp4 * sixx) + (pehp5 * sixy);
          ke5 = (pehp4 * sixy) + (pehp5 * siyy);

          /* Kalman gain KJ = PJHp*Sinv */
          kj0 = (pjhp0 * sixx) + (pjhp1 * sixy);
          kj1 = (pjhp0 * sixy) + (pjhp1 * siyy);
          kj2 = (pjhp2 * sixx) + (pjhp3 * sixy);
          kj3 = (pjhp2 * sixy) + (pjhp3 * siyy);
          kj4 = (pjhp4 * sixx) + (pjhp5 * sixy);
          kj5 = (pjhp4 * sixy) + (pjhp5 * siyy);

          /* ------------------------------------------------------*/
          /* online cali update XC += KC*DXJ */
          cal_yaw   += (kc0 * dxj) + (kc1 * dyj);
          cal_pitch += (kc2 * dxj) + (kc3 * dyj);
          cal_roll  += (kc4 * dxj) + (kc5 * dyj);

          /* egomotion state update XE += KE*DXJ */
          ego_yaw    += (ke0 * dxj) + (ke1 * dyj);
          ego_pitch  += (ke2 * dxj) + (ke3 * dyj);
          ego_roll   += (ke4 * dxj) + (ke5 * dyj);

          /* 3D landmark update update XJ += KJ*DXJ */
          uw += (kj0 * dxj) + (kj1 * dyj);
          vw += (kj2 * dxj) + (kj3 * dyj);
          dw += (kj4 * dxj) + (kj5 * dyj);

          /* ------------------------------------------------------*/
          /* online cali covariance state update PC -= PCHp*KC' */
          ccyy -= (pchp0 * kc0) + (pchp1 * kc1);
          
          ccpy -= (pchp2 * kc0) + (pchp3 * kc1);
          ccpp -= (pchp2 * kc2) + (pchp3 * kc3);

          ccry -= (pchp4 * kc0) + (pchp5 * kc1);
          ccrp -= (pchp4 * kc2) + (pchp5 * kc3);
          ccrr -= (pchp4 * kc4) + (pchp5 * kc5);

          /* update correlations between online cali and egomotion PCE -= PEHp*KC' */
          ecyy -= (pehp0 * kc0) + (pehp1 * kc1);
          ecyp -= (pehp0 * kc2) + (pehp1 * kc3);
          ecyr -= (pehp0 * kc4) + (pehp1 * kc5);

          ecpy -= (pehp2 * kc0) + (pehp3 * kc1);
          ecpp -= (pehp2 * kc2) + (pehp3 * kc3);
          ecpr -= (pehp2 * kc4) + (pehp3 * kc5);

          ecry -= (pehp4 * kc0) + (pehp5 * kc1);
          ecrp -= (pehp4 * kc2) + (pehp5 * kc3);
          ecrr -= (pehp4 * kc4) + (pehp5 * kc5);

          /* egomotion covariance state update PE -= PEHp*KE' */
          eeyy -= (pehp0 * ke0) + (pehp1 * ke1);

          eepy -= (pehp2 * ke0) + (pehp3 * ke1);
          eepp -= (pehp2 * ke2) + (pehp3 * ke3);

          eery -= (pehp4 * ke0) + (pehp5 * ke1);
          eerp -= (pehp4 * ke2) + (pehp5 * ke3);
          eerr -= (pehp4 * ke4) + (pehp5 * ke5);

          /* update cross-correlation between landmark and online cali PJC -= PJHp*KC' */
          cuy -= (pjhp0 * kc0) + (pjhp1 * kc1);
          cup -= (pjhp0 * kc2) + (pjhp1 * kc3);
          cur -= (pjhp0 * kc4) + (pjhp1 * kc5);

          cvy -= (pjhp2 * kc0) + (pjhp3 * kc1);
          cvp -= (pjhp2 * kc2) + (pjhp3 * kc3);
          cvr -= (pjhp2 * kc4) + (pjhp3 * kc5);

          cdy -= (pjhp4 * kc0) + (pjhp5 * kc1);
          cdp -= (pjhp4 * kc2) + (pjhp5 * kc3);
          cdr -= (pjhp4 * kc4) + (pjhp5 * kc5);
          
          /* update cross-correlation between landmark and egomotion PJE -= PJHp*KE' */
          euy -= (pjhp0 * ke0) + (pjhp1 * ke1);
          eup -= (pjhp0 * ke2) + (pjhp1 * ke3);
          eur -= (pjhp0 * ke4) + (pjhp1 * ke5);

          evy -= (pjhp2 * ke0) + (pjhp3 * ke1);
          evp -= (pjhp2 * ke2) + (pjhp3 * ke3);
          evr -= (pjhp2 * ke4) + (pjhp3 * ke5);

          edy -= (pjhp4 * ke0) + (pjhp5 * ke1);
          edp -= (pjhp4 * ke2) + (pjhp5 * ke3);
          edr -= (pjhp4 * ke4) + (pjhp5 * ke5);

          /* state covariance update PJJ = PJJ - PJHp*KJ'*/
          cuu -= (pjhp0 * kj0) + (pjhp1 * kj1);

          cvu -= (pjhp2 * kj0) + (pjhp3 * kj1);
          cvv -= (pjhp2 * kj2) + (pjhp3 * kj3);

          cdu -= (pjhp4 * kj0) + (pjhp5 * kj1);
          cdv -= (pjhp4 * kj2) + (pjhp5 * kj3);
          cdd -= (pjhp4 * kj4) + (pjhp5 * kj5);


          if(   (cuu < 0)
             || (cvv < 0)
             || (cdd < 0)
             || (ccyy < 0)
             || (ccpp < 0)
             || (ccrr < 0)
             || (eeyy < 0)
             || (eepp < 0)
             || (eerr < 0)
            )
          {
            /* do nothing */
          }
          else
          {
            /* set meas flag */
            pFj->stageTrackSlam.statusUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;
            
            /* set 3D landmark */
            pFj->uw = uw;
            pFj->vw = vw;
            pFj->dw = dw;

            pFj->cuu = cuu;
            pFj->cvu = cvu;    pFj->cvv = cvv;
            pFj->cdu = cdu;    pFj->cdv = cdv;    pFj->cdd = cdd;

            /* set online cali with modifications flags */
            if( CML_f_IsNonZero(cal_yaw - pDataCali->cal_yaw) )
            {
              pDataCali->cal_yaw           = cal_yaw;
              pDataCali->cal_yaw_changed   = 1;
            }

            if( CML_f_IsNonZero(cal_pitch - pDataCali->cal_pitch) )
            {
              pDataCali->cal_pitch         = cal_pitch;
              pDataCali->cal_pitch_changed = 1;
            }

            if( CML_f_IsNonZero(cal_roll - pDataCali->cal_roll) )
            {
              pDataCali->cal_roll          = cal_roll;
              pDataCali->cal_roll_changed  = 1;
            }

            pDataCali->ccyy = ccyy;
            pDataCali->ccpy = ccpy;     pDataCali->ccpp = ccpp;
            pDataCali->ccry = ccry;     pDataCali->ccrp = ccrp;     pDataCali->ccrr = ccrr;

            /* set egomotion */
            pDataEgomotion->ego_yaw   = ego_yaw;
            pDataEgomotion->ego_pitch = ego_pitch;
            pDataEgomotion->ego_roll  = ego_roll;

            pDataEgomotion->eeyy = eeyy;
            pDataEgomotion->eepy = eepy;     pDataEgomotion->eepp = eepp;
            pDataEgomotion->eery = eery;     pDataEgomotion->eerp = eerp;     pDataEgomotion->eerr = eerr;

            /* set correlations between online cali and egomotion */
            pDataEgomotion->ecyy = ecyy;    pDataEgomotion->ecyp = ecyp;     pDataEgomotion->ecyr = ecyr;
            pDataEgomotion->ecpy = ecpy;    pDataEgomotion->ecpp = ecpp;     pDataEgomotion->ecpr = ecpr;
            pDataEgomotion->ecry = ecry;    pDataEgomotion->ecrp = ecrp;     pDataEgomotion->ecrr = ecrr;

            /* set cross-correlation between landmark and online cali */
            pFj->cuy = cuy;  pFj->cup = cup;  pFj->cur = cur;
            pFj->cvy = cvy;  pFj->cvp = cvp;  pFj->cvr = cvr;
            pFj->cdy = cdy;  pFj->cdp = cdp;  pFj->cdr = cdr;

            /* set cross-correlation between landmark and egomotion */
            pFj->euy = euy;  pFj->eup = eup;  pFj->eur = eur;
            pFj->evy = evy;  pFj->evp = evp;  pFj->evr = evr;
            pFj->edy = edy;  pFj->edp = edp;  pFj->edr = edr;

            /* update associated rotation matrices */
            HLATrackSlamUpdateRotations(pDataRotations,
                                        pDataCali,
                                        pDataEgomotion
                                       );
           
            /* save kalman gain */
            pFj->v00 = kj0;
            pFj->v01 = kj1;
            pFj->v02 = kj2;
            pFj->v03 = kj3;
            pFj->v04 = kj4;
            pFj->v05 = kj5;

            pFj->v06 = pjhp0;
            pFj->v07 = pjhp1;
            pFj->v08 = pjhp2;
            pFj->v09 = pjhp3;
            pFj->v10 = pjhp4;
            pFj->v11 = pjhp5;

            slotj = pFj->slot;
            pCrossCorrelations_j = pFj->pCrossCorrelations;

            /* update other landmark correlations */
            pFi = pDataCrossCorr->pFullEgoDataBuffer;
            while(pFi != NULL)
            {
              if(pFi!=pFj)
              {
                /* PIHp = PIC*HC' + PIE*HE'  (+ PJI'*HJ')/(+ PIJ*HJ')  */
                pihp0 = (pFi->cuy * hc0) + (pFi->cur * hc2) + (pFi->euy * he0);
                pihp1 = (pFi->cup * hc4) + (pFi->cur * hc5) + (pFi->eup * he4) + (pFi->eur * he5);

                pihp2 = (pFi->cvy * hc0) + (pFi->cvr * hc2) + (pFi->evy * he0);
                pihp3 = (pFi->cvp * hc4) + (pFi->cvr * hc5) + (pFi->evp * he4) + (pFi->evr * he5);

                pihp4 = (pFi->cdy * hc0) + (pFi->cdr * hc2) + (pFi->edy * he0);
                pihp5 = (pFi->cdp * hc4) + (pFi->cdr * hc5) + (pFi->edp * he4) + (pFi->edr * he5);


                /* <ln_offset:+1 MISRA Rule  17.2, 17.3: reviewer name: Bertrand Godreau date: 09.05.2011 reason: pointer comparison wanted to save runtime */
                if(pFj<pFi)
                {
                  /* PIHp += PIJ*HJ'*/
                  pPij = pFi->pCrossCorrelations + slotj;

                  pihp0 += (pPij->cuu * hj0) + (pPij->cud * hj2);
                  pihp1 += (pPij->cuv * hj4) + (pPij->cud * hj5);

                  pihp2 += (pPij->cvu * hj0) + (pPij->cvd * hj2);
                  pihp3 += (pPij->cvv * hj4) + (pPij->cvd * hj5);

                  pihp4 += (pPij->cdu * hj0) + (pPij->cdd * hj2);
                  pihp5 += (pPij->cdv * hj4) + (pPij->cdd * hj5);

                }
                else
                {
                  /* PIHp += PJI'*HJ'*/
                  pPji = pCrossCorrelations_j + pFi->slot;

                  pihp0 += (pPji->cuu * hj0) + (pPji->cdu * hj2);
                  pihp1 += (pPji->cvu * hj4) + (pPji->cdu * hj5);

                  pihp2 += (pPji->cuv * hj0) + (pPji->cdv * hj2);
                  pihp3 += (pPji->cvv * hj4) + (pPji->cdv * hj5);

                  pihp4 += (pPji->cud * hj0) + (pPji->cdd * hj2);
                  pihp5 += (pPji->cvd * hj4) + (pPji->cdd * hj5);
                }

                /* Kalman gain KI = PIHp*Sinv */
                ki0 = (pihp0 * sixx) + (pihp1 * sixy);
                ki1 = (pihp0 * sixy) + (pihp1 * siyy);
                ki2 = (pihp2 * sixx) + (pihp3 * sixy);
                ki3 = (pihp2 * sixy) + (pihp3 * siyy);
                ki4 = (pihp4 * sixx) + (pihp5 * sixy);
                ki5 = (pihp4 * sixy) + (pihp5 * siyy);

                /* update 3D landmark: XI += KI*DXJ */
                pFi->uw += (ki0 * dxj) + (ki1 * dyj);
                pFi->vw += (ki2 * dxj) + (ki3 * dyj);
                pFi->dw += (ki4 * dxj) + (ki5 * dyj);

                /* update 3D landmark: state covariance update PIC = PIC - PIHp*KC' */
                pFi->cuy -= (pihp0 * kc0) + (pihp1 * kc1);
                pFi->cup -= (pihp0 * kc2) + (pihp1 * kc3);
                pFi->cur -= (pihp0 * kc4) + (pihp1 * kc5);

                pFi->cvy -= (pihp2 * kc0) + (pihp3 * kc1);
                pFi->cvp -= (pihp2 * kc2) + (pihp3 * kc3);
                pFi->cvr -= (pihp2 * kc4) + (pihp3 * kc5);

                pFi->cdy -= (pihp4 * kc0) + (pihp5 * kc1);
                pFi->cdp -= (pihp4 * kc2) + (pihp5 * kc3);
                pFi->cdr -= (pihp4 * kc4) + (pihp5 * kc5);

                /* update 3D landmark: state covariance update PIE = PIE - PIHp*KE' */
                pFi->euy -= (pihp0 * ke0) + (pihp1 * ke1);
                pFi->eup -= (pihp0 * ke2) + (pihp1 * ke3);
                pFi->eur -= (pihp0 * ke4) + (pihp1 * ke5);

                pFi->evy -= (pihp2 * ke0) + (pihp3 * ke1);
                pFi->evp -= (pihp2 * ke2) + (pihp3 * ke3);
                pFi->evr -= (pihp2 * ke4) + (pihp3 * ke5);

                pFi->edy -= (pihp4 * ke0) + (pihp5 * ke1);
                pFi->edp -= (pihp4 * ke2) + (pihp5 * ke3);
                pFi->edr -= (pihp4 * ke4) + (pihp5 * ke5);

                /* update 3D landmark: state covariance PI = PI - PIHp*KI'*/
                pFi->cuu -= (pihp0 * ki0) + (pihp1 * ki1);

                pFi->cvu -= (pihp2 * ki0) + (pihp3 * ki1);
                pFi->cvv -= (pihp2 * ki2) + (pihp3 * ki3);

                pFi->cdu -= (pihp4 * ki0) + (pihp5 * ki1);
                pFi->cdv -= (pihp4 * ki2) + (pihp5 * ki3);
                pFi->cdd -= (pihp4 * ki4) + (pihp5 * ki5);

                if(   (pFi->cuu < 0)
                   || (pFi->cvv < 0)
                   || (pFi->cdd < 0) 
                  )
                {
                  /* set failed flag */
                  pFi->stageTrackSlam.statusUpdate = HLA_TRACKSTAGE_KALMAN_INIT;
/*                  return;*/
                }

                /* save kalman gain */
                pFi->v00 = ki0;
                pFi->v01 = ki1;
                pFi->v02 = ki2;
                pFi->v03 = ki3;
                pFi->v04 = ki4;
                pFi->v05 = ki5;

                pFi->v06 = pihp0;
                pFi->v07 = pihp1;
                pFi->v08 = pihp2;
                pFi->v09 = pihp3;
                pFi->v10 = pihp4;
                pFi->v11 = pihp5;
              }
              pFi = pFi->next;
            }


            /* !!!! next code can only be used test when FullEgo list is sorted !!!! */

            /* update cross correlation between landmarks */
            pFi = pDataCrossCorr->pFullEgoDataBuffer;
            while(pFi != NULL)
            {
              sloti = pFi->slot;

              ki0 = pFi->v00;
              ki1 = pFi->v01;
              ki2 = pFi->v02;
              ki3 = pFi->v03;
              ki4 = pFi->v04;
              ki5 = pFi->v05;

              pFj = pFi->next;
              while(pFj != NULL)
              {
                /* PJI = PJI - PJHp*KI' */
                pPji = pFj->pCrossCorrelations + sloti;

                pjhp0 = pFj->v06;
                pjhp1 = pFj->v07;
                pjhp2 = pFj->v08;
                pjhp3 = pFj->v09;
                pjhp4 = pFj->v10;
                pjhp5 = pFj->v11;

                pPji->cuu -= (pjhp0 * ki0) + (pjhp1 * ki1);
                pPji->cuv -= (pjhp0 * ki2) + (pjhp1 * ki3);
                pPji->cud -= (pjhp0 * ki4) + (pjhp1 * ki5);

                pPji->cvu -= (pjhp2 * ki0) + (pjhp3 * ki1);
                pPji->cvv -= (pjhp2 * ki2) + (pjhp3 * ki3);
                pPji->cvd -= (pjhp2 * ki4) + (pjhp3 * ki5);

                pPji->cdu -= (pjhp4 * ki0) + (pjhp5 * ki1);
                pPji->cdv -= (pjhp4 * ki2) + (pjhp5 * ki3);
                pPji->cdd -= (pjhp4 * ki4) + (pjhp5 * ki5);
              
                pFj = pFj->next;
              }

              pFi = pFi->next;
            }
          }
        }
      }
    }
  }
}




/* **************************************************************************** 
  Functionname:     HLATrackSlamKalmanDelayedUpdate                                         */ /*!  
  Description:      Delayed update equation for slam
                    
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamKalmanDelayedUpdate(      FullEgoData_t*                pF,
                                            const HLATracking3DDataEgomotion_t* pDataEgomotion,
                                            const HLATracking3DDataRotations_t* pDataRotations
                                           )
{
  /* egomotion */
  float32 eeyy;
  float32 eepy, eepp;
  float32 eery, eerp, eerr;

  /* correlations between online cali and egomotion */
  float32 ecyy, ecyp, ecyr;
  float32 ecpy, ecpp, ecpr;
  float32 ecry, ecrp, ecrr;

  /* 3D landmark */
  float32 uw;
  float32 vw;
  float32 dw;

  float32 cuu;
  float32 cvu, cvv;
  float32 cdu, cdv, cdd;

 /* cross-correlation between landmark and online cali */
  float32 cuy, cup, cur;
  float32 cvy, cvp, cvr;
  float32 cdy, cdp, cdr;

  /* cross-correlation between landmark and egomotion */
  float32 euy, eup, eur;
  float32 evy, evp, evr;
  float32 edy, edp, edr;

  /* intermediate calculations */
  float32 pchp0, pchp1, pchp2;
  float32 pchp3, pchp4, pchp5;
  float32 pchp6, pchp7, pchp8;

  float32 pehp0, pehp1, pehp2;
  float32 pehp3, pehp4, pehp5;
  float32 pehp6, pehp7, pehp8;

  float32 pjhp0;
  float32 pjhp3, pjhp4;
  float32 pjhp6, pjhp7, pjhp8;

  /* delayed equation jacobians */
  float32 HE[9];
  float32 HJ[9];

  float32 he0;
  float32 he4,he5;

  float32 hj0, hj2;
  float32 hj4, hj5;
  float32 hj8;

  /*-----------------------------------------------------------------------------------------*/
  /* get state */

  /* get egomotion */
  eeyy = pDataEgomotion->eeyy;
  eepy = pDataEgomotion->eepy;    eepp = pDataEgomotion->eepp;
  eery = pDataEgomotion->eery;    eerp = pDataEgomotion->eerp;     eerr = pDataEgomotion->eerr;

  /* get 3D landmark */
  uw = pF->uw;
  vw = pF->vw;
  dw = pF->dw;

  cuu = pF->cuu;
  cvu = pF->cvu;    cvv = pF->cvv;
  cdu = pF->cdu;    cdv = pF->cdv;    cdd = pF->cdd;

  /*------------------------------------------------------------------------------------*/  
  /* apply static delayed update equation */
  HLATrackModelMapUpdate( uw,
                          vw,
                          dw,
                          &(uw),
                          &(vw),
                          &(dw),
                          HE,
                          HJ,
                          pDataRotations
                        );


  /*-----------------------------------------------------------------------------------------*/
  /* get jacobians */
  /* ~CodeReview ~ID:ceba7a723e4efaa021c3a0f3954a90fa ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:120938 Commented out code. Consider clean-up (for the rest of this function). */
  he0 = HE[0];          /*he1 = 0;*//*HE[1];*/    /*he2 = 0;*//*HE[2];*/
  /*he3 = 0;*//*HE[3];*/    he4 = HE[4];          he5 = HE[5];
  /*he6 = 0;*//*HE[6];*/    /*he7 = 0;*//*HE[7];*/    /*he8 = 0;*//*HE[8];*/

  hj0 = HJ[0];          /*hj1 = 0;*//*HJ[1];*/    hj2 = HJ[2];
  /*hj3 = 0;*//*HJ[3];*/    hj4 = HJ[4];          hj5 = HJ[5];
  /*hj6 = 0;*//*HJ[6];*/    /*hj7 = 0;*//*HJ[7];*/        hj8 = HJ[8];

  /*----------------------------------------------------*/
  /* UPDATE COVARIANCE MATRIX */

  /* PJ = HE*(PE*HE' + PJE'*HJ') + HJ*(PJE*HE' + PJ*HJ') for full egomotion */
  /* PJ = HE*(PE*HE') + HJ*(PJ*HJ') for simple static tracker */


  /* PEHp = PE*HE' */
  pehp0 = (eeyy * he0);

  pehp3 = (eepy * he0);
  pehp4 = (eepp * he4) + (eerp * he5);

  pehp6 = (eery * he0);
  pehp7 = (eerp * he4) + (eerr * he5);

  /* PJHJp = PJ*HJ' */
  pjhp0 = (cuu * hj0) + (cdu * hj2);

  pjhp3 = (cvu * hj0) + (cdv * hj2);
  pjhp4 = (cvv * hj4) + (cdv * hj5);

  pjhp6 = (cdu * hj0) + (cdd * hj2);
  pjhp7 = (cdv * hj4) + (cdd * hj5);
  pjhp8 = (cdd * hj8);

  /* get correlations between online cali and egomotion */
  ecyy = pDataEgomotion->ecyy;    ecyp = pDataEgomotion->ecyp;     ecyr = pDataEgomotion->ecyr;
  ecpy = pDataEgomotion->ecpy;    ecpp = pDataEgomotion->ecpp;     ecpr = pDataEgomotion->ecpr;
  ecry = pDataEgomotion->ecry;    ecrp = pDataEgomotion->ecrp;     ecrr = pDataEgomotion->ecrr;

  /* get cross-correlation between landmark and online cali */
  cuy = pF->cuy;  cup = pF->cup;  cur = pF->cur;
  cvy = pF->cvy;  cvp = pF->cvp;  cvr = pF->cvr;
  cdy = pF->cdy;  cdp = pF->cdp;  cdr = pF->cdr;


  /* PEHp = PE*HE' */
  pehp1 = (eepy * he4) + (eery * he5);
  pehp2 = 0;

  pehp5 = 0;

  pehp8 = 0;

  /* PCHp = PCE'*HE' + PJC'*HJ' */
  pchp0 = (ecyy * he0) +                               (cuy * hj0) + (cdy * hj2);
  pchp1 = (ecpy * he4) + (ecry * he5) +                (cvy * hj4) + (cdy * hj5);
  pchp2 =                                              (cdy * hj8);

  pchp3 = (ecyp * he0) +                               (cup * hj0) + (cdp * hj2);
  pchp4 = (ecpp * he4) + (ecrp * he5) +                (cvp * hj4) + (cdp * hj5);
  pchp5 =                                              (cdp * hj8);

  pchp6 = (ecyr * he0) +                               (cur * hj0) + (cdr * hj2);
  pchp7 = (ecpr * he4) + (ecrr * he5) +                (cvr * hj4) + (cdr * hj5);
  pchp8 =                                              (cdr * hj8);

  /* PJC = (PCHp)' */
  cuy = pchp0;  cup = pchp3;  cur = pchp6;
  cvy = pchp1;  cvp = pchp4;  cvr = pchp7;
  cdy = pchp2;  cdp = pchp5;  cdr = pchp8;

  /* get cross-correlation between landmark and egomotion */
  euy = pF->euy;  eup = pF->eup;  eur = pF->eur;
  evy = pF->evy;  evp = pF->evp;  evr = pF->evr;
  edy = pF->edy;  edp = pF->edp;  edr = pF->edr;

  /* PEHp += PJE'*HJ' */
  pehp0 += (euy * hj0) + (edy * hj2);
  pehp1 += (evy * hj4) + (edy * hj5);
  pehp2 += (edy * hj8);

  pehp3 += (eup * hj0) + (edp * hj2);
  pehp4 += (evp * hj4) + (edp * hj5);
  pehp5 += (edp * hj8);

  pehp6 += (eur * hj0) + (edr * hj2);
  pehp7 += (evr * hj4) + (edr * hj5);
  pehp8 += (edr * hj8);

  /* PJHJp += PJE*HE' */
  pjhp0 += (euy * he0);

  pjhp3 += (evy * he0);
  pjhp4 += (evp * he4) + (evr * he5);

  pjhp6 += (edy * he0);
  pjhp7 += (edp * he4) + (edr * he5);
  /*pjhp8 += 0;*/

  /* set cross-correlation between landmark and online cali */
  pF->cuy = cuy;  pF->cup = cup;  pF->cur = cur;
  pF->cvy = cvy;  pF->cvp = cvp;  pF->cvr = cvr;
  pF->cdy = cdy;  pF->cdp = cdp;  pF->cdr = cdr;

  /* save derivatives */
  pF->v00 = he0;
  pF->v01 = he4;   pF->v02 = he5;

  pF->v03 = hj0;   pF->v04 = hj2;
  pF->v05 = hj4;   pF->v06 = hj5;
  pF->v07 = hj8;

  /* save PEHp : future cross-correlation between landmark and egomotion in a separate memory */
  pF->v08 = pehp0;  pF->v09 = pehp1;  pF->v10 = pehp2;
  pF->v11 = pehp3;  pF->v12 = pehp4;  pF->v13 = pehp5;
  pF->v14 = pehp6;  pF->v15 = pehp7;  pF->v16 = pehp8;

  /* PJ = HE*(PEHp) + HJ*(PJHJp) */
  cuu = (he0 * pehp0) + (hj0 * pjhp0) + (hj2 * pjhp6);

  cvu = (he4 * pehp3) + (he5 * pehp6) + (hj4 * pjhp3) + (hj5 * pjhp6);
  cvv = (he4 * pehp4) + (he5 * pehp7) + (hj4 * pjhp4) + (hj5 * pjhp7);

  cdu = (hj8 * pjhp6);
  cdv = (hj8 * pjhp7);
  cdd = (hj8 * pjhp8);

  if(   (cuu<0)
     || (cvv<0)
     || (cdd<0) 
    )
  {
  }
  else
  {
    pF->stageTrackSlam.statusDelayedUpdate = HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS;
    
    /* save state */
    pF->uw = uw;
    pF->vw = vw;
    pF->dw = dw;

    pF->cuu = cuu;
    pF->cvu = cvu;    pF->cvv = cvv;
    pF->cdu = cdu;    pF->cdv = cdv;    pF->cdd = cdd;
  }

}


/* **************************************************************************** 
  Functionname:     HLATrackSlamKalmanCorrelationsDelayedUpdate                                         */ /*!  
  Description:      Delayed update of Landmark To Landmark cross-correlations
                    
  @param[in]        
  @param[out]       
  @return           -
  @pre              -
  @post             -
  @author           Bertrand Godreau
**************************************************************************** */
static void HLATrackSlamKalmanCorrelationsDelayedUpdate(const HLATracking3DDataCrossCorr_t* pDataCrossCorr)
{
  /* pointer to full ego data */
  FullEgoData_t* pFi;
  FullEgoData_t* pFj;

  /* pointer to cross-correlations matrices */
  TracksCrossCorr_t* pPji;
  uint8 sloti;

  /* data common for landmark i and j */
  float32 cuu, cuv, cud;
  float32 cvu, cvv, cvd;
  float32 cdu, cdv, cdd;
  
  float32 pjhpi0, pjhpi1, pjhpi2;
  float32 pjhpi3, pjhpi4, pjhpi5;
  float32 pjhpi6, pjhpi7, pjhpi8;

  /* data from kandmark i */
  float32 hie0;
  float32 hie4, hie5;

  float32 hi0, hi2;
  float32 hi4, hi5;
  float32 hi8;

  float32 pehpi0, pehpi1, pehpi2;
  float32 pehpi3, pehpi4, pehpi5;
  float32 pehpi6, pehpi7, pehpi8;

  /* data from kandmark j */
  float32 hje0;
  float32 hje4, hje5;

  float32 hj0, hj2;
  float32 hj4, hj5;
  float32 hj8;

  float32 ejuy, ejup, ejur;
  float32 ejvy, ejvp, ejvr;
  float32 ejdy, ejdp, ejdr;
  

  /* !!!! next code can only be used test when FullEgo list is sorted !!!! */

  /* update cross correlation between landmarks */
  pFi = pDataCrossCorr->pFullEgoDataBuffer;
  while(pFi != NULL)
  {
    if(pFi->stageTrackSlam.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
    {
      sloti = pFi->slot;

      /* get data of landmark i */
      hie0 = pFi->v00;
      hie4 = pFi->v01;    hie5 = pFi->v02;

      hi0 = pFi->v03;    hi2 = pFi->v04;
      hi4 = pFi->v05;    hi5 = pFi->v06;
      hi8 = pFi->v07;

      pehpi0 = pFi->v08;    pehpi1 = pFi->v09;    pehpi2 = pFi->v10;
      pehpi3 = pFi->v11;    pehpi4 = pFi->v12;    pehpi5 = pFi->v13;
      pehpi6 = pFi->v14;    pehpi7 = pFi->v15;    pehpi8 = pFi->v16;


      pFj = pFi->next;
      while(pFj != NULL)
      {
        if(pFj->stageTrackSlam.statusDelayedUpdate == HLA_TRACKSTAGE_KALMAN_RUN_SUCCESS)
        {
          /* get data of landmark j */
          hje0 = pFj->v00;
          hje4 = pFj->v01;    hje5 = pFj->v02;

          hj0 = pFj->v03;    hj2 = pFj->v04;
          hj4 = pFj->v05;    hj5 = pFj->v06;
          hj8 = pFj->v07;

          /* get cross-correlation between landmark and egomotion */
          ejuy = pFj->euy;  ejup = pFj->eup;  ejur = pFj->eur;
          ejvy = pFj->evy;  ejvp = pFj->evp;  ejvr = pFj->evr;
          ejdy = pFj->edy;  ejdp = pFj->edp;  ejdr = pFj->edr;

          /* PJI = HJE*(PEHIp) + HJ*(PJE*HIE' + PJI*HI') */
          pPji = pFj->pCrossCorrelations + sloti;

          /*get pij*/
          cuu = pPji->cuu;  cuv = pPji->cuv;  cud = pPji->cud;
          cvu = pPji->cvu;  cvv = pPji->cvv;  cvd = pPji->cvd;
          cdu = pPji->cdu;  cdv = pPji->cdv;  cdd = pPji->cdd;

          /* PJHI = PJI*HI' + PJE*HIE' */
          pjhpi0 = (cuu * hi0) + (cud * hi2) + (ejuy * hie0);
          pjhpi1 = (cuv * hi4) + (cud * hi5) + (ejup * hie4) + (ejur * hie5);
          pjhpi2 = (cud * hi8);

          pjhpi3 = (cvu * hi0) + (cvd * hi2) + (ejvy * hie0);
          pjhpi4 = (cvv * hi4) + (cvd * hi5) + (ejvp * hie4) + (ejvr * hie5);
          pjhpi5 = (cvd * hi8);

          pjhpi6 = (cdu * hi0) + (cdd * hi2) + (ejdy * hie0);
          pjhpi7 = (cdv * hi4) + (cdd * hi5) + (ejdp * hie4) + (ejdr * hie5);
          pjhpi8 = (cdd * hi8);

          /* PJI = HJE*(PEHIp) + HJ*(PJHI) */
          pPji->cuu = (hje0 * pehpi0)   +   (hj0 * pjhpi0) + (hj2 * pjhpi6);
          pPji->cuv = (hje0 * pehpi1)   +   (hj0 * pjhpi1) + (hj2 * pjhpi7);
          pPji->cud = (hje0 * pehpi2)   +   (hj0 * pjhpi2) + (hj2 * pjhpi8);

          pPji->cvu = (hje4 * pehpi3) + (hje5 * pehpi6)   +  (hj4 * pjhpi3) + (hj5 * pjhpi6);
          pPji->cvv = (hje4 * pehpi4) + (hje5 * pehpi7)   +  (hj4 * pjhpi4) + (hj5 * pjhpi7);
          pPji->cvd = (hje4 * pehpi5) + (hje5 * pehpi8)   +  (hj4 * pjhpi5) + (hj5 * pjhpi8);

          pPji->cdu = (hj8 * pjhpi6);
          pPji->cdv = (hj8 * pjhpi7);
          pPji->cdd = (hj8 * pjhpi8);

        }
        pFj = pFj->next;
      }

      /* cross-correlation between landmark and egomotion PJE = (PEHp)' */
      pFi->euy = pehpi0;  pFi->eup = pehpi3;  pFi->eur = pehpi6;
      pFi->evy = pehpi1;  pFi->evp = pehpi4;  pFi->evr = pehpi7;
      pFi->edy = pehpi2;  pFi->edp = pehpi5;  pFi->edr = pehpi8;
    }
    pFi = pFi->next;
  }
}

static void seedLCG(uint32 seed)
{
  randomNumber = seed;
}

static uint32 theLCG(void)
{
  randomNumber = (randomNumber * 1103515245u) + 12345u;
  return (uint32)((randomNumber>>17) % RAND_MAX);
}/* PRQA S 861 1 */
