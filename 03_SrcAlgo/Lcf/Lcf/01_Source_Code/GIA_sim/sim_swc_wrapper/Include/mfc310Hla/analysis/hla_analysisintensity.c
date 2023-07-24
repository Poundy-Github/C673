/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysisintensity.c

  DESCRIPTION:            Analysis based on intensity evaluation.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-09-30

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_analysisintensity.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:42CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:57CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:15CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.39 2014/03/28 10:36:18CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed some QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:18 AM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.38 2014/03/26 11:27:49CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some mandatory QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:49 AM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.37 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_analysisintensity.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysisintensity.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGES:                Revision 1.36 2014/03/19 16:31:02CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:03 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.35 2014/01/28 10:48:11CET Schillinger, Patrick (uidv8776) 
  CHANGES:                -renaming of some unclear variables
  CHANGES:                -changes to meet coding guideline
  CHANGES:                --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:12 AM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.34 2014/01/17 13:18:53CET Schillinger, Patrick (uidv8776) 
  CHANGES:                rename pT to pTrack
  CHANGES:                --- Added comments ---  uidv8776 [Jan 17, 2014 1:18:53 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.33 2014/01/05 22:50:56CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC: replaced fabs with fabsf
  CHANGES:                --- Added comments ---  uidg4759 [Jan 5, 2014 10:50:57 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.32 2013/03/08 10:31:18CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:18 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.31 2013/03/04 11:15:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integrated cam_rot into HLA
  CHANGES:                bug fix in jacobian calculation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:10 AM CET]
  CHANGES:                Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.30 2012/11/15 09:56:24CET Brunn, Marcus (brunnm) 
  CHANGES:                interface update for MFC4B0, BMW I210 (without RTE)
  CHANGES:                --- Added comments ---  brunnm [Nov 15, 2012 9:56:24 AM CET]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.29 2012/07/19 18:56:47CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - calculate center bright box by parameters specified as angle in rad instead of pixels
  CHANGES:                --- Added comments ---  uidt9253 [Jul 19, 2012 6:56:47 PM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.28 2012/04/02 16:52:39CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - added comments from code review
  CHANGES:                --- Added comments ---  uidt9253 [Apr 2, 2012 4:52:40 PM CEST]
  CHANGES:                Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGES:                Revision 1.27 2012/03/22 15:59:18CET Zechner, Stefan (uidt9253) 
  CHANGES:                - code review tool destroyed the windows line endings
  CHANGES:                --- Added comments ---  uidt9253 [Mar 22, 2012 3:59:20 PM CET]
  CHANGES:                Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGES:                Revision 1.26 2012/03/22 15:56:09CET Zechner, Stefan (uidt9253) 
  CHANGES:                - comments from code review with Reinhard Schuler
  CHANGES:                --- Added comments ---  uidt9253 [Mar 22, 2012 3:56:09 PM CET]
  CHANGES:                Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGES:                Revision 1.25 2012/03/09 16:48:25CET Zechner, Stefan (uidt9253) 
  CHANGES:                - feature extreme bright: set back to negative when MaxInt < 5000 lux
  CHANGES:                --- Added comments ---  uidt9253 [Mar 9, 2012 4:48:25 PM CET]
  CHANGES:                Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGES:                Revision 1.24 2011/11/29 09:58:38CET Zechner, Stefan (uidt9253) 
  CHANGES:                - remove the "Carlos Nurbs Based Headlamp Model" for tooBright detection because it uses a lot of resources and batch runs have proven no benefit of detection performance
  CHANGES:                --- Added comments ---  uidt9253 [Nov 29, 2011 9:58:38 AM CET]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.23 2011/11/16 18:58:41CET Zechner, Stefan (uidt9253) 
  CHANGES:                - introduce 1st level oncoming feature lateral bright objects (for oncoming vehicles in sharp curves, side ways, crossroads)
  CHANGES:                --- Added comments ---  uidt9253 [Nov 16, 2011 6:58:41 PM CET]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.22 2011/09/27 13:39:41CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                separation of HLAR/ HLAF
  CHANGES:                --- Added comments ---  brunnm [Sep 27, 2011 1:39:41 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.21 2011/09/02 17:09:26CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - parameter tuning
  CHANGES:                --- Added comments ---  uidt9253 [Sep 2, 2011 5:09:50 PM CEST]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.20 2011/08/30 17:41:10CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - new feature for oncoming vehicles: Extreme Bright. It's for very bright vehicles and ignores non-white or street lamp supression
  CHANGES:                --- Added comments ---  uidt9253 [Aug 30, 2011 5:41:10 PM CEST]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.19 2011/07/25 15:23:13CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - remove hlaMotionData from blackboard
  CHANGES:                --- Added comments ---  uidt9253 [Jul 25, 2011 3:23:13 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.18 2011/07/16 16:12:14CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - parameter tuning
  CHANGES:                --- Added comments ---  uidt9253 [Jul 16, 2011 4:12:14 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.17 2011/07/13 17:22:53CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - fix some misra errors
  CHANGES:                --- Added comments ---  uidt9253 [Jul 13, 2011 5:22:53 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.16 2011/07/08 17:08:05CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - introduce the HLA Analysis ROI (road course estimation) for high probability of vehicles appearing
  CHANGES:                - center bright analysis ROI get the new house style
  CHANGES:                --- Added comments ---  uidt9253 [Jul 8, 2011 5:08:06 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.15 2011/07/07 15:00:41CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - remove HLAInitAnalysisGlobals() and according unused memory
  CHANGES:                - introduce HLAAnalysisIntensityInit()
  CHANGES:                --- Added comments ---  uidt9253 [Jul 7, 2011 3:00:41 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.14 2011/07/06 09:45:02CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - new center&bright high intensity analysis feature (a centered box is estimated from vehicle motion. Bright white lights within the box are marked as potential vehicle oncoming)
  CHANGES:                - potential oncoming vehicles need time-to-border less than 3 seconds
  CHANGES:                - hla_analysisintensity code refactoring
  CHANGES:                --- Added comments ---  uidt9253 [Jul 6, 2011 9:45:02 AM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.13 2011/05/23 19:48:42CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Adapted new identification model on all classifiers
  CHANGES:                --- Added comments ---  almeidac [May 23, 2011 7:48:43 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.12 2011/05/23 15:48:25CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Added new identification strategy
  CHANGES:                --- Added comments ---  almeidac [May 23, 2011 3:48:25 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.11 2011/05/23 14:02:18CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                - renamed seg_TracklistNode into HLATrack_t
  CHANGES:                - renamed seg_ListNode into HLASegLight_t
  CHANGES:                --- Added comments ---  brunnm [May 23, 2011 2:02:18 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.10 2011/05/21 19:12:47CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Added new result status concept
  CHANGES:                --- Added comments ---  almeidac [May 21, 2011 7:12:48 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.9 2011/05/20 15:23:07CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Close to final version of head lamp model
  CHANGES:                --- Added comments ---  almeidac [May 20, 2011 3:23:07 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.8 2011/05/18 18:10:32CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Improved head lamp model for right head lamp
  CHANGES:                --- Added comments ---  almeidac [May 18, 2011 6:10:32 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.7 2011/05/16 17:02:28CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Added head lamp model for right head lamp
  CHANGES:                --- Added comments ---  almeidac [May 16, 2011 5:02:29 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.6 2011/03/03 17:33:22CET Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                updated intensity grid (reduce false white turn off, too bright)
  CHANGES:                --- Added comments ---  brunnm [Mar 3, 2011 5:33:22 PM CET]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.5 2011/02/28 16:20:44CET Reik Mueller (muellerr5) 
  CHANGES:                - added HLAIdentificationTooBright()
  CHANGES:                --- Added comments ---  muellerr5 [Feb 28, 2011 4:20:45 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.4 2010/12/21 13:29:38CET Carlos Almeida (almeidac) 
  CHANGES:                Added intensity grid analysis with new spline
  CHANGES:                --- Added comments ---  almeidac [Dec 21, 2010 1:29:39 PM CET]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.3 2010/12/14 13:20:29CET Carlos Almeida (almeidac) 
  CHANGES:                Added spline-engine for intensity analysis
  CHANGES:                --- Added comments ---  almeidac [Dec 14, 2010 1:20:29 PM CET]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.2 2010/10/21 19:29:14CEST Reik Mueller (x-muellerr5) 
  CHANGES:                - updated HLAAnalysisIntensityGrid()
  CHANGES:                --- Added comments ---  x-muellerr5 [Oct 21, 2010 7:29:14 PM CEST]
  CHANGES:                Change Package : 38439:1 http://mks-psad:7002/im/viewissue?selection=38439
  CHANGES:                Revision 1.1 2010/10/14 14:38:06CEST Marcus Brunn (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                Revision 1.2 2010/10/04 11:55:05CEST Marcus Brunn (brunnm) 
  CHANGES:                set to bright only when light is available
  CHANGES:                --- Added comments ---  brunnm [Oct 4, 2010 11:55:05 AM CEST]
  CHANGES:                Change Package : 38437:1 http://mks-psad:7002/im/viewissue?selection=38437
  CHANGES:                Revision 1.1 2010/10/01 22:15:20CEST Carlos Almeida (almeidac) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_analysisintensity.h"
#include "math.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct 
{
  sint16                    centerBrightLeftRightPx;
  sint16                    centerBrightTopPx;
  sint16                    centerBrightBottomPx;

  boolean                   active;
  uint16                    activateCnt;
  sint16                    roiLeftX;
  sint16                    roiLeftY;
  sint16                    roiMiddleX;
  sint16                    roiMiddleY;
  sint16                    roiRightX;
  sint16                    roiRightY;
  sint16                    roiBottomY;
  float32                   roiSlopeLeft;
  float32                   roiSlopeRight;
} HLAAnaCenterBrightData_t;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
HLA_GLOBAL_STATIC HLAAnaCenterBrightData_t anaCenterBrightData;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do intensity analysis based on too bright threshold. */
static void HLAAnalysisTooBright( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                        HLATrack_t*               pTrack );

/*! Do intensity analysis based on center bright criteria. */
static void HLAAnalysisCenterBright( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                           HLATrack_t*                pTrack );

/*! Do intensity analysis based on lateral bright criteria. */
static void HLAAnalysisLateralBright( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                      const HLACameraData_t*          pCamData,
                                            HLATrack_t*               pTrack );

/*! Do intensity analysis based on extreme bright criteria. */
static void HLAAnalysisExtremeBright( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                            HLATrack_t*               pTrack );

/*! Do identification for intensity grid (too bright). */
static void HLAIdentificationTooBright( const HLA_t_IdentificationParameters* pIdentParamIn,
                                              HLATrack_t*                     pTrack );

/*! Do identification for center bright. */
static void HLAIdentificationCenterBright( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                                 HLATrack_t*                      pTrack );

/*! Do identification for lateral bright. */  
static void HLAIdentificationLateralBright( const HLA_t_IdentificationParameters* pIdentParamIn,
                                                  HLATrack_t*                     pTrack );   

/*! Do identification for extreme bright. */
static void HLAIdentificationExtremeBright( HLATrack_t*  pTrack );

/* **************************************************************************** 
  Functionname:     HLAAnalysisIntensityInit */ /*!
  Description:      Initialize state variables 

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
void HLAAnalysisIntensityInit(const HLAR_t_RequiredInputs* ps_In)
{
  anaCenterBrightData.centerBrightLeftRightPx = (sint16)(ps_In->s_Par.s_CameraParameter.s_FocalLength.f32_x * tanf(hlaAnalysisParameters.centerBrightLeftRightRad));
  anaCenterBrightData.centerBrightTopPx       = (sint16)(ps_In->s_Par.s_CameraParameter.s_FocalLength.f32_y * tanf(hlaAnalysisParameters.centerBrightTopRad));
  anaCenterBrightData.centerBrightBottomPx    = (sint16)(ps_In->s_Par.s_CameraParameter.s_FocalLength.f32_y * tanf(hlaAnalysisParameters.centerBrightBottomRad));

  anaCenterBrightData.active = b_FALSE;
  anaCenterBrightData.activateCnt = 0;
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisPrepare */ /*!
  Description:      Prepare the intensity based analysis once per frame before
                    the tracks are analysed.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in]        const HLACamRot                 *pCam     the camera model

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
/* ~CodeReviewBegin ~ID:49c96e0c0c9bf01ac7741e21672aca65 ~Reviewer:CW01\uidt9253 ~Date:3/22/2012 ~Priority:3 ~Comment:convert magic numbers to parameters */
void HLAAnalysisIntensityPrepare( const HLAR_t_RequiredInputs*   pRequiredIn,
                                  const HLACameraData_t*         pCamData,
                                  const HLACamRot*               pCamRot,
                                  const RTE_HLA_TrafficStyle     eTrafficStyle
                                )
{
  {
    /* fill input data for analysis intensity component: center bright */
    float32 trafficStyleCorrection = 0;
    if(eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
    {
      trafficStyleCorrection = 1.5f;
    }
    else if(eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
    {
      trafficStyleCorrection = -1.5f;
    }
    else
    {
      /* Do not fill input when RTE_HLA_TRAFFIC_STYLE_INVALID or */
    }

    if (pRequiredIn->s_Sig.s_MotionState.f32_Speed > 5)
    {
      const float32 curvature = pRequiredIn->s_Sig.s_MotionState.f32_YawRateRaw / pRequiredIn->s_Sig.s_MotionState.f32_Speed;
      const float32 absCurvature = fabsf(curvature);

      if (absCurvature < 0.002)
      {
        /* ~CodeReview ~ID:9f86bb10bbc9b9536ce94b6ec1ceacc9 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:check for overflow */
        anaCenterBrightData.activateCnt++;
      }
      else
      {
        anaCenterBrightData.activateCnt = 0;
      }

      if ( (anaCenterBrightData.activateCnt > 10) ||
           ((anaCenterBrightData.active == b_TRUE) && (absCurvature < 0.004))
         )
      {
        const float32 x = 100;
        const float32 y = (0.5f * (curvature * (x * x))) + trafficStyleCorrection;
        /* ~CodeReview ~ID:2a030a373aaede6416f4a10c48e3847d ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:document that sint16 range is sufficient */
        const sint16 xFOE = (sint16)(HLACamRotGetxb(pCamRot, x, y, 0.0f));

        /* ~CodeReview ~ID:06596d67d5355d739a101f60df66c548 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:document downcast to sint16 */
        anaCenterBrightData.active = b_TRUE;
        anaCenterBrightData.roiLeftX = xFOE - anaCenterBrightData.centerBrightLeftRightPx;
        anaCenterBrightData.roiLeftY = (sint16)pCamData->FOE_y;
        anaCenterBrightData.roiMiddleX = xFOE;
        anaCenterBrightData.roiMiddleY = (sint16)pCamData->FOE_y - anaCenterBrightData.centerBrightTopPx;
        anaCenterBrightData.roiRightX = xFOE + anaCenterBrightData.centerBrightLeftRightPx;
        anaCenterBrightData.roiRightY = (sint16)pCamData->FOE_y;
        anaCenterBrightData.roiBottomY = (sint16)pCamData->FOE_y + anaCenterBrightData.centerBrightBottomPx;

        /* ~CodeReview ~ID:9f68599281aaafd67c56eba7955458f0 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:docment why division by zero is not possbile here */
        anaCenterBrightData.roiSlopeLeft  = ((float32)(anaCenterBrightData.roiMiddleY - anaCenterBrightData.roiLeftY )) / ((float32)(anaCenterBrightData.roiMiddleX - anaCenterBrightData.roiLeftX ));
        anaCenterBrightData.roiSlopeRight = ((float32)(anaCenterBrightData.roiMiddleY - anaCenterBrightData.roiRightY)) / ((float32)(anaCenterBrightData.roiMiddleX - anaCenterBrightData.roiRightX));
      }
      else
      {
        anaCenterBrightData.active = b_FALSE;
      }
    }
    else
    {
      anaCenterBrightData.active = b_FALSE;
      anaCenterBrightData.activateCnt = 0;
    }
  }
}
/* ~CodeReviewEnd   ~ID:49c96e0c0c9bf01ac7741e21672aca65 */

/* **************************************************************************** 
  Functionname:     HLAAnalysisIntensity */ /*!
  Description:      Do intensity based analysis.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in]        const HLACamRot                 *pCam     the camera model
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAAnalysisIntensity( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                           const HLACameraData_t*           pCamData,
                                 HLATrack_t*                pTrack )
{
  HLAAnalysisTooBright(pAnalysisParamIn, pTrack);

  HLAAnalysisCenterBright(pAnalysisParamIn, pTrack);

  HLAAnalysisLateralBright(pAnalysisParamIn, pCamData, pTrack);

  HLAAnalysisExtremeBright(pAnalysisParamIn, pTrack);
}

void HLAIdentificationIntensity( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                       HLATrack_t*                      pTrack )
{
  HLAIdentificationTooBright(pIdentParamIn, pTrack);

  HLAIdentificationCenterBright(pIdentParamIn, pTrack);

  HLAIdentificationLateralBright(pIdentParamIn, pTrack);

  HLAIdentificationExtremeBright(pTrack);
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisTooBright */ /*!
  Description:      Do intensity analysis based on too bright threshold.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisTooBright( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                        HLATrack_t*               pTrack )
{
  if (   (pTrack->light_ref != NULL) 
      && (pTrack->lost_time == 0)
      && (pTrack->MaxInt > pAnalysisParamIn->tooBrightMinInt)
     )
  {
    pTrack->anaResStat.isTooBright.result = HLA_RESULT_POSITIVE;
  }
  else
  {
    pTrack->anaResStat.isTooBright.result = HLA_RESULT_NEGATIVE;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationTooBright */ /*!
  Description:      Do identification for too bright intensity.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAIdentificationTooBright( const HLA_t_IdentificationParameters* pIdentParamIn,
                                              HLATrack_t*                     pTrack )
{
  if (pTrack != NULL)
  {
    /* if the ident state has already reached its maximum positive confidence, do no further updates */
    if (pTrack->idResStat.isTooBright.confidence != pIdentParamIn->tooBrightPositiveBound) 
    {
      const uint8 analysisResult = pTrack->anaResStat.isTooBright.result;

      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* update confidence in "negative" direction */
        pTrack->idResStat.isTooBright.confidence = CML_Max(pIdentParamIn->tooBrightNegativeBound, pTrack->idResStat.isTooBright.confidence - pIdentParamIn->tooBrightConfStepSize);
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* update confidence in "positive" direction */
        pTrack->idResStat.isTooBright.confidence = CML_Min(pIdentParamIn->tooBrightPositiveBound, pTrack->idResStat.isTooBright.confidence + pIdentParamIn->tooBrightConfStepSize);
      }
      else /*if (analysisResult == HLA_RESULT_IDLE)*/
      {
        /* "unknown" -> no change */
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isTooBright.confidence <= pIdentParamIn->tooBrightNegativeBound)
      {
        pTrack->idResStat.isTooBright.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isTooBright.confidence >= pIdentParamIn->tooBrightPositiveBound)
      {
        pTrack->idResStat.isTooBright.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isTooBright.result = HLA_RESULT_IDLE;
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisCenterBright */ /*!
  Description:      Set the analysis result state isCenterBright 

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisCenterBright( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                           HLATrack_t*                pTrack )
{
  /* check for valid measurement within center bright box which exceeds some defined intensity */

  pTrack->anaResStat.isCenterBright.result = HLA_RESULT_NEGATIVE;

  if (   (pTrack->light_ref != NULL) 
      && (pTrack->lost_time == 0)
      && (anaCenterBrightData.active == b_TRUE)
      && (pTrack->MaxInt > pAnalysisParamIn->centerBrightMaxInt)
      && (pTrack->xcenter >= anaCenterBrightData.roiLeftX)
      && (pTrack->xcenter <= anaCenterBrightData.roiRightX)
      && (pTrack->ycenter <= anaCenterBrightData.roiBottomY)
     )
  {
    const sint16 offsetX = pTrack->xcenter - anaCenterBrightData.roiMiddleX;

    if (offsetX > 0)
    {
      /* right side of the center bright house */
      if (pTrack->ycenter >= (anaCenterBrightData.roiMiddleY + (anaCenterBrightData.roiSlopeRight * offsetX)))
      {
        pTrack->anaResStat.isCenterBright.result = HLA_RESULT_POSITIVE;
      }
    }
    else
    {
      /* left side of the center bright house */
      if (pTrack->ycenter >= (anaCenterBrightData.roiMiddleY + (anaCenterBrightData.roiSlopeLeft * offsetX)))
      {
        pTrack->anaResStat.isCenterBright.result = HLA_RESULT_POSITIVE;
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationCenterBright */ /*!
  Description:      Do identification for bright centered lights.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIdentificationCenterBright( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                                 HLATrack_t*                      pTrack )
{
  if (pTrack != NULL)
  {
    /* if the ident state has already reached its maximum positive confidence, do no further updates */
    if (pTrack->idResStat.isCenterBright.confidence != pIdentParamIn->centerBrightPositiveBound) 
    {
      const uint8 analysisResult = pTrack->anaResStat.isCenterBright.result;

      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* update confidence in "negative" direction */
        pTrack->idResStat.isCenterBright.confidence = CML_Max(pIdentParamIn->centerBrightNegativeBound, pTrack->idResStat.isCenterBright.confidence - pIdentParamIn->centerBrightConfStepSize);
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* update confidence in "positive" direction */
        pTrack->idResStat.isCenterBright.confidence = CML_Min(pIdentParamIn->centerBrightPositiveBound, pTrack->idResStat.isCenterBright.confidence + pIdentParamIn->centerBrightConfStepSize);
      }
      else /*if (analysisResult == HLA_RESULT_IDLE)*/
      {
        /* "unknown" -> no change */
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isCenterBright.confidence <= pIdentParamIn->centerBrightNegativeBound)
      {
        pTrack->idResStat.isCenterBright.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isCenterBright.confidence >= pIdentParamIn->centerBrightPositiveBound)
      {
        pTrack->idResStat.isCenterBright.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isCenterBright.result = HLA_RESULT_IDLE;
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisLateralBright */ /*!
  Description:      Set the analysis result state isLateralBright 

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisLateralBright( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                      const HLACameraData_t*          pCamData,
                                            HLATrack_t*               pTrack )
{
  pTrack->anaResStat.isLateralBright.result = HLA_RESULT_NEGATIVE;

  if (   (pTrack->light_ref != NULL) 
      && (pTrack->lost_time == 0)
      && (pTrack->statusAnalysisMisc.isFarAboveHorizon == 0)
      && (pTrack->MaxInt > pAnalysisParamIn->lateralBrightMinInt)
     )
  {
    if (pTrack->xcenter > pCamData->FOE_x)
    {
      if ((pTrack->delta_x_lp < 0) &&
          (pTrack->MaxInt > (pAnalysisParamIn->lateralBrightMaxInt - (pAnalysisParamIn->lateralBrightSlopeInt * (pTrack->xcenter - pCamData->FOE_x)))))
      {
        pTrack->anaResStat.isLateralBright.result = HLA_RESULT_POSITIVE;
      }
    }
    else
    {
      if ((pTrack->delta_x_lp > 0) &&
          (pTrack->MaxInt > (pAnalysisParamIn->lateralBrightMaxInt - (pAnalysisParamIn->lateralBrightSlopeInt * (pCamData->FOE_x - pTrack->xcenter)))))
      {
        pTrack->anaResStat.isLateralBright.result = HLA_RESULT_POSITIVE;
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationLateralBright */ /*!
  Description:      Do identification for bright lateral lights.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIdentificationLateralBright( const HLA_t_IdentificationParameters* pIdentParamIn,
                                                  HLATrack_t*                     pTrack )
{
  if (pTrack != NULL)
  {
    /* if the ident state has already reached its maximum positive confidence, do no further updates */
    if (pTrack->idResStat.isLateralBright.confidence != pIdentParamIn->lateralBrightPositiveBound) 
    {
      const uint8 analysisResult = pTrack->anaResStat.isLateralBright.result;

      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* update confidence in "negative" direction */
        pTrack->idResStat.isLateralBright.confidence = CML_Max(pIdentParamIn->lateralBrightNegativeBound, pTrack->idResStat.isLateralBright.confidence - pIdentParamIn->lateralBrightConfStepSize);
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* update confidence in "positive" direction */
        pTrack->idResStat.isLateralBright.confidence = CML_Min(pIdentParamIn->lateralBrightPositiveBound, pTrack->idResStat.isLateralBright.confidence + pIdentParamIn->lateralBrightConfStepSize);
      }
      else /*if (analysisResult == HLA_RESULT_IDLE)*/
      {
        /* "unknown" -> no change */
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isLateralBright.confidence <= pIdentParamIn->lateralBrightNegativeBound)
      {
        pTrack->idResStat.isLateralBright.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isLateralBright.confidence >= pIdentParamIn->lateralBrightPositiveBound)
      {
        pTrack->idResStat.isLateralBright.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isLateralBright.result = HLA_RESULT_IDLE;
      }
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisExtremeBright */ /*!
  Description:      Set the analysis result state isExtremeBright 

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisExtremeBright( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                            HLATrack_t*               pTrack )
{
  pTrack->anaResStat.isExtremeBright.result = HLA_RESULT_IDLE;

  if (   (pTrack->light_ref != NULL) 
      && (pTrack->lost_time == 0)
     )
  {
    if (   (pTrack->statusAnalysisMisc.isFarAboveHorizon == 0)
        && (pTrack->MaxInt > pAnalysisParamIn->extremeBrightMaxInt)
       )
    {
      pTrack->anaResStat.isExtremeBright.result = HLA_RESULT_POSITIVE;
    }
    else if (   (pTrack->statusAnalysisMisc.isFarAboveHorizon == 1)
             || (pTrack->MaxInt < pAnalysisParamIn->extremeBrightMinInt)
            )
    {
      pTrack->anaResStat.isExtremeBright.result = HLA_RESULT_NEGATIVE;
    }
    else
    {
      /* Do nothing when light is not extrembright */
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationExtremeBright */ /*!
  Description:      Do identification for extreme bright lights.
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis
  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIdentificationExtremeBright( HLATrack_t* pTrack )
{
  if (pTrack->anaResStat.isExtremeBright.result != HLA_RESULT_IDLE)
  {
    pTrack->idResStat.isExtremeBright.result = pTrack->anaResStat.isExtremeBright.result;
  }
}

