/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackutils.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackutils.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:13CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:58CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:14CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.18 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackutils.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackutils.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.17 2014/03/05 11:05:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed build errors from previous check-in
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:27 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/03/04 16:52:15CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:16 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/01/24 13:37:58CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:59 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.14 2014/01/21 13:09:22CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:22 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.13 2014/01/10 18:34:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:07 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.12 2013/12/18 15:18:07CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:08 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.11 2012/12/04 17:49:16CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Avoid including isPotentialVehicleAhead1st in the SLAM feature list
  CHANGE:                 -> Add a step to make a robust estimate of the essential matrix between two frames using a RANSAC algorithm
  CHANGE:                 -> Integration of Day Segmentation for online calibration
  CHANGE:                 --- Added comments ---  uid28828 [Dec 4, 2012 5:49:18 PM CET]
  CHANGE:                 Change Package : 166968:1 http://mks-psad:7002/im/viewissue?selection=166968
  CHANGE:                 Revision 1.10 2012/10/18 17:56:03CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:56:03 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.9 2012/06/27 17:11:21CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - findings from code review
  CHANGE:                 --- Added comments ---  uidt9253 [Jun 27, 2012 5:11:21 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.8 2012/04/19 20:01:53CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 integrate ttb18 for each track: time to border for a 18° angle
  CHANGE:                 ttb18 calculations are based on 3D estimations
  CHANGE:                 --- Added comments ---  uid28828 [Apr 19, 2012 8:01:55 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.7 2012/04/18 17:55:57CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 increase pitch range for tracking to avoid track losses on bumpers
  CHANGE:                 -> remove pitch range Vs speed concept
  CHANGE:                 -> sort SLAM features: update SLAM beginning with the closest light to the prediction, ending with the further one
  CHANGE:                 -> use a wider noise measurement for the isolated lights used in SLAM
  CHANGE:                 --- Added comments ---  uid28828 [Apr 18, 2012 5:55:58 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.6 2012/04/12 13:05:06CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 fix code review findings for delta_x filters implementation
  CHANGE:                 --- Added comments ---  uid28828 [Apr 12, 2012 1:05:07 PM CEST]
  CHANGE:                 Change Package : 110195:1 http://mks-psad:7002/im/viewissue?selection=110195
  CHANGE:                 Revision 1.5 2012/04/05 16:53:58CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 -> code review finding fix : use hla roi limits + margin instead of cropped roi limits for killing tracks
  CHANGE:                 -> code review finding fix : init tracking in the HLAR_v_Init() function
  CHANGE:                 
  CHANGE:                 -> clean-up HLAR_v_Init() function
  CHANGE:                 -> clean-up init and updates of cali/camera/camrot/roi in hla_main.c and hla_camera.c
  CHANGE:                 -> remove global variables from hla_camera.c
  CHANGE:                 -> remove HLA_t_CameraParameters hlaCamParam
  CHANGE:                 -> remove useless usage of camRot/camParamInput in tracking
  CHANGE:                 --- Added comments ---  uid28828 [Apr 5, 2012 4:53:58 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.4 2012/03/12 13:50:22CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Rework of dynamic object classification
  CHANGE:                 -> Separate static kalman part from SLAM and static tracker
  CHANGE:                 --- Added comments ---  uid28828 [Mar 12, 2012 1:50:22 PM CET]
  CHANGE:                 Change Package : 94859:1 http://mks-psad:7002/im/viewissue?selection=94859
  CHANGE:                 Revision 1.3 2012/02/24 16:34:46CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Bugfixes pair tracker/rockets/track losses
  CHANGE:                 -> Tuning pair tracker
  CHANGE:                 --- Added comments ---  uid28828 [Feb 24, 2012 4:34:46 PM CET]
  CHANGE:                 Change Package : 94857:1 http://mks-psad:7002/im/viewissue?selection=94857
  CHANGE:                 Revision 1.2 2012/02/20 15:07:44CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Finish restucturing of tracking algo
  CHANGE:                 --- Added comments ---  uid28828 [Feb 20, 2012 3:07:44 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.1 2012/01/25 17:36:28CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKUTILS_INCLUDED
#define HLA_TRACKUTILS_INCLUDED

#include "hla_base.h"
#include "hla_debug.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_TRACKING_6X3_MATRIXSIZE 18
#define HLA_TRACKING_3X3_MATRIXSIZE 9
#define HLA_TRACKING_3X3_VECTORSIZE 3


/*! Type definition for cross-correlations in Cali algo */
typedef struct
{
  /* allocate memory for TrackListnodes */
  ARRAY(HLATrack_t, HLA_TRACKING_MAX_NUM_TRACKS, free_tracked_lights_buffer);
  HLATrack_t* pTrackedLightsBufferFree;                    /*!< @brief list of unused tracks  */

  /* allocate memory for track/light couple data */
  /* ~CodeReview ~ID:beee0589609b70eced41c56013fdc1ef ~Reviewer:CW01\uidt9253 ~Date:6/27/2012 ~Priority:2 ~Comment:can be local variables to save RAM */
  ARRAY(HLACoupleData_t, (HLA_TRACKING_MAX_NUM_TRACKS * HLA_TRACKING3D_MAX_NUM_LIGHTASS_PER_TRACK), tableCouple);
  uint32      numAssoc;
  uint32      numPair;

#ifdef PC_SIM
  uint32      HLAGlobalLightCount;
#endif
} HLATracking3DDataTracks_t;

/*! Type definition for pre-calculated rotations matrix and vectors */
typedef struct
{
  /* rotation matrix and translation vector for egomotion */
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, RE);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRE_dey);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRE_dep);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRE_der);

  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, TE);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTE_dey);

  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, VE);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dVE_dey);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dVE_dep);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dVE_der);

  /* rotation matrices and translation vectors and their derivatives along online cali and egomotion */
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, RK);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRK_dcy);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRK_dcp);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRK_dcr);

  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, TK);

  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, VK);

  /* pre-calculated values for essentiel matrix estimation */
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, EK);

  /* combined rotation matrices and translation vectors to speed-up process */
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, RA);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRA_dcy);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRA_dcp);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRA_dcr);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRA_dey);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRA_dep);
  ARRAY(float32, HLA_TRACKING_3X3_MATRIXSIZE, dRA_der);

  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, TA);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTA_dcy);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTA_dcp);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTA_dcr);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTA_dey);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTA_dep);
  ARRAY(float32, HLA_TRACKING_3X3_VECTORSIZE, dTA_der);
} HLATracking3DDataRotations_t;

typedef struct
{
  float32 pw;
  float32 ph;
  float32 pdStart;
  float32 ppddStart;
  float32 dwStart;
  float32 cddStart;
  float32 pdEnd;
  float32 ppddEnd;
  float32 pphh;
  float32 ppww;
  float32 pa;
  float32 ppaa;
  float32 pr;
  float32 pprrStart;
  float32 pprrEnd;
  float32 pc;
  float32 ppcc;
  float32 pg;
  float32 ppgg;

  float32 ps;
  float32 ppss;

  float32 py;
  float32 ppyy;

  uint32 errMaxIntGreyValue;
  float32 scc;
  float32 sgg;
  float32 cxx;
  float32 cyy;

  float32 ccyy_init;
  float32 ccpp_init;
  float32 ccrr_init;

  float32 pp_acceleration;
  float32 pp_yawrate;
  float32 pp_heightspeed;
  float32 pp_deltaheightspeed;
  float32 pp_minspeed_foryaw;
} HLATracking3DDataPreComputedPair_t;

/*! Type definition for pre computed data during tracking 3D init */
typedef struct
{
  float32 dw_init;            /* init uncertainty on static object depth */
  float32 cdd_init;           /* init uncertainty on static object depth */
  uint16  xwmax100_absolute;  /* default values for distance estimation */
  uint16  xwmin100_absolute;  /* default values for distance estimation */

  /*! Type definition for dynamic tracker data */
  float32 odw_init;
  float32 ofw_init;

  float32 coff_init;
  float32 coss_init;
  float32 coll_init;

  float32 coss_proc;
  float32 coll_proc;

  float32 osxx_max;
  float32 osyy_max;

  float32 sxxRMSE;
  float32 syyRMSE;

  float32 odw_min;
  float32 odw_max;

  /*! Type definition for measurment data management*/
  float32 FX;
  float32 FY;
  float32 XO;
  float32 YO;
  float32 invFX;
  float32 invFY;
  float32 factorCxx;
  float32 factorCyy;
  float32 factorMaxCxx;

  /* variance on yaw rate */
  float32 varianceYawRate;
  float32 varianceYawRateExtreme;

  /* process noise for egomotion */
  float32 proc_epp;
  float32 proc_epp_ex;
  float32 proc_err;
  float32 proc_err_ex;

  /*! Type definition for data association algo */
  float32 factorF2IDist;
  
  /*! Type definition for pair detection and tracking */
  HLATracking3DDataPreComputedPair_t    dataOncoming;
  HLATracking3DDataPreComputedPair_t    dataAhead;
  HLATracking3DDataPreComputedPair_t    dataTruckLights;

  /* dist from height mean and covariance */
  float32 qh;
  float32 qd;
  float32 qqhh;
  float32 qqdd;

  /* delta low pass long term filter constant when trace time is >= numCyclesDlpLt */
  float32 h_dlp_lt_tcn;

  /* tangent of ttb angle */
  float32 tanaTTB;
} HLATracking3DDataPreComputed_t;


/* manage addition of item in the couple data list */
void HLATrackUtilsAddCoupleToList(HLACoupleData_t*        pAssocDataList,
                                  uint32*                 n,
                                  const HLACoupleData_t*  pAssocData2insert,
                                  const uint32            maxTableSize
                                 );

/* calc functions */
boolean HLATrackUtilsInverseInnovation(float32  sxx,
                                       float32  syy,
                                       float32  sxy,
                                       float32* isxx,
                                       float32* isyy,
                                       float32* isxy
                                      );

void HLATrackUtilsMaha11( float32*  pdist,
                          float32   dx,
                          float32   sxx
                        );

void HLATrackUtilsMaha22( float32*  pdist,
                          float32   dx,
                          float32   dy,
                          float32   sxx,
                          float32   syy,
                          float32   sxy
                        );

void HLATrackUtilsMaha22Diag( float32*  pdist,
                              float32   dx,
                              float32   dy,
                              float32   sxx,
                              float32   syy
                            );

void HLATrackUtilsMaha33(       float32*  pdist,
                          const float32   dx,
                          const float32   dy,
                          const float32   dh,
                          const float32   sxx,
                          const float32   syx,
                          const float32   shx,
                          const float32   syy,
                          const float32   shy,
                          const float32   shh
                         );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
