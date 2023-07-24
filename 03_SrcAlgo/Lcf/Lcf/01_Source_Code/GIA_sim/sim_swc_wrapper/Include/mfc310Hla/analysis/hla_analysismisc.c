/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysismisc.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-12-21

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_analysismisc.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:43CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:58CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:16CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.63 2014/03/28 10:36:04CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed some QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:04 AM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.62 2014/03/26 11:27:45CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed some mandatory QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:46 AM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.61 2014/03/25 19:11:46CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Separation of hla_segmentation.c
  CHANGES:                Removed QAC warnings
  CHANGES:                Replaces fABS by CML_f_abs
  CHANGES:                Introduced CML_s_Round2Int
  CHANGES:                --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:46 PM CET]
  CHANGES:                Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.60 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_analysismisc.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysismisc.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGES:                Revision 1.59 2014/03/24 18:33:22CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed boost assert
  CHANGES:                --- Added comments ---  uidv7867 [Mar 24, 2014 6:33:23 PM CET]
  CHANGES:                Change Package : 207432:44 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.58 2014/03/19 16:30:17CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:17 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.57 2014/03/10 13:21:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed some new critical QAC warnings
  CHANGES:                Moved suppressions from .hoc file to comment in source code
  CHANGES:                --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:09 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.56 2014/03/03 16:02:55CET Glebov, Roman (uidg4759) 
  CHANGES:                added two asserts and removed unneeded checks for != NULL for the tracks pointers which are parts of a 
  CHANGES:                tracking pair
  CHANGES:                --- Added comments ---  uidg4759 [Mar 3, 2014 4:02:55 PM CET]
  CHANGES:                Change Package : 217406:1 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGES:                Revision 1.55 2014/02/28 15:48:02CET Schillinger, Patrick (uidv8776) 
  CHANGES:                introduce ratio check for oncoming pair analysis
  CHANGES:                --- Added comments ---  uidv8776 [Feb 28, 2014 3:48:03 PM CET]
  CHANGES:                Change Package : 217405:1 http://mks-psad:7002/im/viewissue?selection=217405
  CHANGES:                Revision 1.54 2014/02/06 16:01:07CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:08 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.53 2014/01/28 10:48:13CET Schillinger, Patrick (uidv8776) 
  CHANGES:                -renaming of some unclear variables
  CHANGES:                -changes to meet coding guideline
  CHANGES:                --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:14 AM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.52 2014/01/17 13:46:31CET Schillinger, Patrick (uidv8776) 
  CHANGES:                rename pT and pTLB to pTrack
  CHANGES:                --- Added comments ---  uidv8776 [Jan 17, 2014 1:46:32 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.51 2014/01/10 18:33:19CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:19 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.50 2013/12/26 15:25:22CET Glebov, Roman (uidg4759) 
  CHANGES:                Solved several QAC critical messages:
  CHANGES:                
  CHANGES:                - implicit conversion from signed char to float
  CHANGES:                - possible side effects ciritical warnings if conditional expressions
  CHANGES:                - comparison with 0 of float variables in conditional expressions
  CHANGES:                --- Added comments ---  uidg4759 [Dec 26, 2013 3:25:22 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.49 2013/12/18 15:15:22CET Schillinger, Patrick (uidv8776) 
  CHANGES:                new HighwayOncomingTruckLight detection
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:15:22 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.48 2013/11/21 17:53:06CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:06 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.47.1.1 2013/10/18 13:27:32CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:32 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.47 2013/08/02 15:25:49CEST Manz, Alexander (uidv8777) 
  CHANGES:                Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGES:                --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:49 PM CEST]
  CHANGES:                Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGES:                Revision 1.46 2013/04/08 13:23:45CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed Lint errors
  CHANGES:                --- Added comments ---  uidv7867 [Apr 8, 2013 1:23:46 PM CEST]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.45 2013/03/27 12:56:16CET Schillinger, Patrick (uidv8776) 
  CHANGES:                magic numbers of highway oncoming car detection are now paramaters in hlaAnalysisParameters
  CHANGES:                --- Added comments ---  uidv8776 [Mar 27, 2013 12:56:17 PM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.44 2013/03/14 17:44:34CET Schillinger, Patrick (uidv8776) 
  CHANGES:                improvement of  highway oncoming car detection.
  CHANGES:                --- Added comments ---  uidv8776 [Mar 14, 2013 5:44:34 PM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.43 2013/03/11 16:13:24CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced no longer needed types by RTE ones
  CHANGES:                - HLA_t_eSignalState
  CHANGES:                - HLA_t_eLightStyle
  CHANGES:                - HLA_t_eTunnel
  CHANGES:                - HLA_t_eCityState
  CHANGES:                - HLA_t_eWeatherState
  CHANGES:                - HLA_t_eMotorwayState
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:25 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.42 2013/03/08 15:51:29CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed Misra errors
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 3:51:29 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.41 2013/03/08 10:29:50CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:29:51 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.40 2013/03/08 10:12:24CET Schillinger, Patrick (uidv8776) 
  CHANGES:                Moved Highway Oncoming Car Analysis to First Level Analysis
  CHANGES:                --- Added comments ---  uidv8776 [Mar 8, 2013 10:12:24 AM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.39 2013/03/04 11:15:07CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integrated cam_rot into HLA
  CHANGES:                bug fix in jacobian calculation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:07 AM CET]
  CHANGES:                Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.38 2013/01/08 10:28:46CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Exchanged ABS by fABS for floating point calculations
  CHANGES:                --- Added comments ---  uidv7867 [Jan 8, 2013 10:28:46 AM CET]
  CHANGES:                Change Package : 167173:21 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#ifdef PC_SIM
#include <assert.h>
#endif

#include "hla_analysismisc.h"

/*****************************************************************************
  CONSTANTS 
*****************************************************************************/
/* Track distance threshold for float values assumed as zero. 
The value is oriented to hlaTracking3DParameters.paramStaticTracker.minTrackDist
which is currently set to 8.f */
static const float32 f_TrackDistThresAssumedAsZero = 0.00001f;

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
  sint8 sign;
  uint8 idx;
  float32 thresh;
  float32 alpha;
} opa_adaboost_rule_t;

/* ~CodeReview ~ID:73b97b5b6682dcb96f749e440f279827 ~Reviewer:CW01\muellerr5 ~Date:28.03.2012 ~Priority:3 ~Comment:magic number */
static const ARRAY(opa_adaboost_rule_t, 50, OPa_Ada) = {
  {-1,  0, 15.0000000000F, 0.7797060227F},
  { 1,  7, -1758.0000000000F, 0.6658549390F},
  { 1,  4, -97.7500000000F, 0.4510735147F},
  {-1,  0, 7.0000000000F, 0.4188368444F},
  {-1,  1, 251.2500000000F, 0.2523295232F},
  { 1, 12, -111.2500000000F, 0.2471529316F},
  { 1,  7, -2985.5000000000F, 0.2487250396F},
  {-1,  0, 19.0000000000F, 0.2583408755F},
  {-1, 14, 35.5000000000F, 0.2390253938F},
  {-1,  1, 690.7500000000F, 0.1616558174F},
  { 1,  4, -448.7500000000F, 0.2184399606F},
  {-1,  5, 206.2500000000F, 0.1712528012F},
  { 1,  7, -2963.7500000000F, 0.1778287031F},
  { 1,  4, -28.7500000000F, 0.2390593998F},
  {-1,  8, 287.2500000000F, 0.1914077248F},
  { 1,  7, -856.2500000000F, 0.1782506394F},
  {-1,  1, 690.7500000000F, 0.1761646548F},
  { 1,  7, -3758.7500000000F, 0.2179292086F},
  {-1,  0, 11.0000000000F, 0.2207020987F},
  { 1,  7, -5575.2500000000F, 0.1411768602F},
  { 1,  2, -23.7500000000F, 0.2004084075F},
  {-1,  5, 75.7500000000F, 0.1953148287F},
  { 1,  2, -148.7500000000F, 0.1669077261F},
  {-1,  1, 226.7500000000F, 0.1551313110F},
  { 1,  3, -2912.0000000000F, 0.1629164449F},
  {-1, 20, 2440.0000000000F, 0.2041900733F},
  { 1, 17, -611.5000000000F, 0.1840237026F},
  {-1,  6, 1728.2500000000F, 0.1502579939F},
  { 1, 13, -1367.7500000000F, 0.1637844615F},
  {-1,  0, 21.0000000000F, 0.2028574579F},
  { 1,  7, -5575.2500000000F, 0.1779431438F},
  { 1, 12, -35.7500000000F, 0.1786785254F},
  {-1, 11, 155.7500000000F, 0.1505133883F},
  { 1, 10, -182.5000000000F, 0.1512682316F},
  {-1,  5, 415.7500000000F, 0.1502141319F},
  { 1,  7, -989.2500000000F, 0.1530066802F},
  {-1,  1, 365.5000000000F, 0.1503187667F},
  { 1,  7, -5575.2500000000F, 0.1481720456F},
  {-1,  0, 9.0000000000F, 0.1633099122F},
  { 1,  2, -54.7500000000F, 0.1387112866F},
  {-1,  5, 46.7500000000F, 0.1429113201F},
  { 1,  2, -196.2500000000F, 0.1310898500F},
  {-1,  5, 210.0000000000F, 0.1469173577F},
  { 1,  7, -1855.0000000000F, 0.1308856336F},
  {-1, 20, 2440.0000000000F, 0.1934584577F},
  { 1,  7, -2875.2500000000F, 0.1596622205F},
  {-1,  8, 1628.7500000000F, 0.1681692947F},
  { 1,  7, -856.2500000000F, 0.1652654769F},
  {-1,  8, 278.7500000000F, 0.1358387764F},
  { 1,  9, -104.0000000000F, 0.1506165601F}
};


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do above ROI analysis. */
static void HLAAnalysisAboveROI( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                 const HLACameraData_t*           pCamData,
                                       HLATrack_t*                pTrack
                               );

/*! Analyse if track motion is consistent with optical flow of static objects. */
static void HLAAnalysisContraMotion( const HLA_t_AnalysisParameters*     pAnalysisParamIn,
                                     const HLA_t_MotionState*            pMotionState,
                                     const HLACameraData_t*              pCamData,
                                     const HLATracking3DDataEgomotion_t* pEgomotionData,
                                     const HLACamRot*                    pCam,
                                           HLATrack_t*                   pTrack
                                   );

/*! Analyse if tracked motion indicates a dynamic object */
static void HLAAnalysisDynamicMotion( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                            HLATrack_t*                      pTrack );

/*! Analyse if track is moving like a static object in close range and is too dark to be a vehicle in close range. */
static void HLAAnalysisCloseReflector( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                       const HLACameraData_t*           pCamData,
                                             HLATrack_t*                pTrack
                                     );

static void HLAAnalysisStaticHigh( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                         HLATrack_t*                pTrack );

/*! Analyse if tracks looks like a light pair of an oncoming vehicle. */
static void HLAAnalysisOncomingPair( HLATrack_t* pTrack );

/*! Calculates features for the input vector of the oncoming pair classifier. */
static void HLAGetOPaInputVector( const uint8       length,
                                  const HLATrack_t* pTrackLeft,
                                  const HLATrack_t* pTrackRight,
                                  float32*    pX
                                );

/* **************************************************************************** 
  Functionname:     HLAAnalysisBaseMisc */ /*!
  Description:      Do base miscellaneous analysis.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in]        const HLACameraData_t           *pCamData required ROI parameters input
  @param[in]        const HLACamRot                 *pCam     pinhole camera model
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAAnalysisBaseMisc( const HLA_t_AnalysisParameters*     pAnalysisParamIn,
                          const HLAR_t_RequiredInputs*        pRequiredIn,
                          const HLACameraData_t*              pCamData,
                          const HLATracking3DDataEgomotion_t* pEgomotionData,
                          const HLACamRot*                    pCam,
                                HLATrack_t*                   pTrack 
                        )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/

  HLAAnalysisAboveROI(pAnalysisParamIn, pCamData, pTrack);

  HLAAnalysisContraMotion(pAnalysisParamIn, &pRequiredIn->s_Sig.s_MotionState, pCamData, pEgomotionData, pCam, pTrack);

  HLAAnalysisDynamicMotion(pAnalysisParamIn, pTrack);

  HLAAnalysisCloseReflector(pAnalysisParamIn, pCamData, pTrack);

  HLAAnalysisStaticHigh(pAnalysisParamIn, pTrack);

  HLAAnalysisOncomingPair(pTrack);

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/

}

/* **************************************************************************** 
  Functionname:     HLAAnalysisHighwayBright */ /*!
  Description:      Do analysis for onoming lights on highways

  @param[in]        const RTE_HLA_TrafficStyle  eTrafficStyle   required traffic style input (left- or right-handed)
  @param[in]        const HLA_t_Highway       *pHighwayData   required highway input
  @param[in,out]    HLATrack_t                *pTrack             current track for analysis
  @param[in]        const HLACameraData_t     *pCamData       Camera data input


  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
void HLAAnalysisHighwayBright( const RTE_HLA_TrafficStyle   eTrafficStyle, 
                               const HLA_t_Highway*         pHighwayData,     
                               const HLACameraData_t*       pCamData,
                               const HLACamRot*             pCamRot,
                                     HLATrack_t*            pTrack
                              )
{

    sint8 fak = 1;
    float32 xl_s;
    float32 yl_s;
    float32 xl_e;
    float32 yl_e;
    float32 x_val;


    /* Check if Track is in Truck Light area */
    if(eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
    {
        fak = -1;
    }

    /* Start Point */
    HLACamRotGetXb( pCamRot, &xl_s, &yl_s, 400.0f, (float32) fak * 7.0f, 2.5f);

    /* End Point */
    HLACamRotGetXb( pCamRot, &xl_e, &yl_e, 15.0f, (float32)fak * 7.0f, 1.5f);

    x_val = (((pTrack->ycenter - yl_e)*(xl_s - xl_e))/(yl_s - yl_e)) + xl_e;

    if(pTrack->xcenter > x_val)
    {
        pTrack->statusAnalysisMisc.isInTruckLightRegion = 1;
    }
    else
    {
        pTrack->statusAnalysisMisc.isInTruckLightRegion = 0;
    }

  /*if the car is on the highway, the region of potential oncoming cars is left or right from the focus 
    and below the far above horizon region*/
  if(  (pHighwayData->e_HighwayOutInternal == RTE_HLAF_MTWY_MOTORWAY)
     &&(  ((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD) && (pTrack->xcenter < pCamData->FOE_x))
        ||((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD) && (pTrack->xcenter > pCamData->FOE_x))
       )
    )
  {
    /*if the light is bright enough and the track is older than 2 frames it is a potential car */
    if(  (pTrack->statusAnalysisMisc.isInTruckLightRegion == 0)
       &&(pTrack->statusAnalysisMisc.isFarAboveHorizon == 0)
       &&(pTrack->AverageMaxInt > hlaAnalysisParameters.highwayBrightMinInt)
       &&(pTrack->MaxInt > hlaAnalysisParameters.highwayBrightMinInt)
       &&(pTrack->track_time > hlaAnalysisParameters.highwayBrightMinTrackTime)
      )
    {
      pTrack->anaResStat.isHighwayBright.result = HLA_RESULT_POSITIVE;
    }
    /* Truck Lights case. If the light is above the line it could be a truck light */
    else if(        (pTrack->statusAnalysisMisc.isInTruckLightRegion == 1)
                &&  (pTrack->AverageMaxInt > hlaAnalysisParameters.highwayBrightMinIntTruckLights)
                &&  (pTrack->MaxInt > hlaAnalysisParameters.highwayBrightMinIntTruckLights)
                &&  (pTrack->track_time > hlaAnalysisParameters.highwayBrightMinTrackTimeTruckLights)
            )
    {
        pTrack->anaResStat.isHighwayBright.result = HLA_RESULT_POSITIVE;
    }
    else
    {
      /* light is neither a potential car nor a truck -> Do nothing */
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisHighwayBrightTruckLights */ /*!
  Description:      Do analysis for oncoming truck lights lights on highways

  @param[in]        const RTE_HLA_TrafficStyle  eTrafficStyle   required traffic style input (left- or right-handed)
  @param[in]        const HLA_t_Highway       *pHighwayData   required highway input
  @param[in,out]    HLATrack_t                *pTrack             current track for analysis
  @param[in]        const HLACameraData_t     *pCamData       Camera data input


  @return           -
  @pre              -
  @post             -
  @author           Alexander Fischer
**************************************************************************** */
void HLAAnalysisHighwayBrightTruckLights( const RTE_HLA_TrafficStyle   eTrafficStyle, 
                                          const HLA_t_Highway         *pHighwayData, 
                                          const HLACameraData_t       *pCamData,
                                          HLAPair_t                   *pPair_Start
                                         )
{

  HLAPair_t *pPair;

  if(  (pHighwayData->e_HighwayOutInternal == RTE_HLAF_MTWY_MOTORWAY))
  {
      pPair = pPair_Start;
      while(pPair != NULL)
      {
          if(       (pPair->pTLeft->statusAnalysisMisc.isAboveHorizon == 1)
                &&  (pPair->pTRight->statusAnalysisMisc.isAboveHorizon == 1)
                &&  (((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD ) && (pPair->pTLeft->xcenter < pCamData->FOE_x))
                    ||((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD) && (pPair->pTLeft->xcenter > pCamData->FOE_x))
                    )
                &&  (((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD ) && (pPair->pTRight->xcenter < pCamData->FOE_x))
                    ||((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD) && (pPair->pTRight->xcenter > pCamData->FOE_x))
                    )
                &&  (pPair->pTLeft->AverageMaxInt > hlaAnalysisParameters.highwayBrightMinIntTruckLights)
                &&  (pPair->pTRight->AverageMaxInt > hlaAnalysisParameters.highwayBrightMinIntTruckLights)
                &&  (pPair->pTLeft->MaxInt > hlaAnalysisParameters.highwayBrightMinIntTruckLights)
                &&  (pPair->pTRight->MaxInt > hlaAnalysisParameters.highwayBrightMinIntTruckLights)
                &&  (pPair->pTLeft->track_time > hlaAnalysisParameters.highwayBrightMinTrackTimeTruckLights)
                &&  (pPair->pTRight->track_time > hlaAnalysisParameters.highwayBrightMinTrackTimeTruckLights)
                &&  (((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD ) && (pPair->pTLeft->delta_x_lp < -hlaAnalysisParameters.highwayBrightMinTrackDeltaX))
                ||((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD) && (pPair->pTLeft->delta_x_lp > hlaAnalysisParameters.highwayBrightMinTrackDeltaX))
                )
                &&  (((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD ) && (pPair->pTRight->delta_x_lp < -hlaAnalysisParameters.highwayBrightMinTrackDeltaX))
                ||((eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD) && (pPair->pTRight->delta_x_lp > hlaAnalysisParameters.highwayBrightMinTrackDeltaX))
                )
                &&  (pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
              )
          {
              pPair->pTLeft->anaResStat.isHighwayBrightTruckLights.result = HLA_RESULT_POSITIVE;
              pPair->pTRight->anaResStat.isHighwayBrightTruckLights.result = HLA_RESULT_POSITIVE;
          }

          /* Set potential Truck Light state */
          if(     (pPair->bit_TrafficType == HLA_TV_TRAFFIC_TYPE_TRUCKLIGHTS)
              &&  ( (     (eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD )
                      &&  (pPair->pTLeft->delta_x_lp < - hlaAnalysisParameters.highwayBrightMinTrackDeltaX)
                      &&  (pPair->pTRight->delta_x_lp < -hlaAnalysisParameters.highwayBrightMinTrackDeltaX)
                    )
                   ||
                    (     (eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD )
                      &&  (pPair->pTLeft->delta_x_lp > hlaAnalysisParameters.highwayBrightMinTrackDeltaX)
                      &&  (pPair->pTRight->delta_x_lp > hlaAnalysisParameters.highwayBrightMinTrackDeltaX)
                    )
                   )
            )
          {
            pPair->pTLeft->statusAnalysisMisc.isPotentialTruckLight = 1;
            pPair->pTRight->statusAnalysisMisc.isPotentialTruckLight = 1;
          }

          pPair = pPair->next;

      }
  }


}
/* **************************************************************************** 
  Functionname:     HLAAnalysisAboveROI */ /*!
  Description:      Do above ROI analysis.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn    required input for function
  @param[in]        const HLA_t_RoiParameters       *pROIIn required ROI parameters input
  @param[in,out]    HLATrack_t                      *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAAnalysisAboveROI( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                 const HLACameraData_t*           pCamData,
                                       HLATrack_t*                pTrack
                               )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/
  sint16 yUROI, yUTolROI, yMinROI, yMaxROI;

  /* upper ROI y-position. */
  yUROI = (sint16)pCamData->RoiYu; 
  yUTolROI = (sint16)(yUROI + pAnalysisParamIn->aboveRoiTolerance_pix); 
  yMaxROI = yUROI;
  yMinROI = yUTolROI;

  /* set isAboveROI flag. */
  if ( pTrack->ycenter < yMinROI )
  {
    if (   (pTrack->ycenter < yMaxROI)
        || ((pTrack->ycenter < yMinROI) && (pTrack->statusAnalysisMisc.isAboveROI == 1))
        )
    {     
      pTrack->statusAnalysisMisc.isAboveROI = 1;
    }
  }
  else 
  {
    pTrack->statusAnalysisMisc.isAboveROI = 0;
  }

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/

}

/* **************************************************************************** 
  Functionname:     HLAAnalysisContraMotion */ /*!
  Description:      Analyse if track motion is consistent with optical flow of
                    static objects.

  @param[in]        const HLA_t_AnalysisParameters        *pAnalysisParamIn            required input for function
  @param[in]        const HLACameraData_t                 *pCamData       required camera data input
  @param[in]        const HLATracking3DDataEgomotion_t    *pEgomotionData required egomotion data input
  @param[in]        const HLACamRot                       *pCam           pinhole camera model
  @param[in,out]    HLATrack_t                            *pTrack             current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAAnalysisContraMotion( const HLA_t_AnalysisParameters*      pAnalysisParamIn,
                                     const HLA_t_MotionState*             pMotionState,
                                     const HLACameraData_t*               pCamData,
                                     const HLATracking3DDataEgomotion_t*  pEgomotionData,
                                     const HLACamRot*                     pCam,
                                           HLATrack_t*                    pTrack
                                    )
{
  /*
  const float32 minDist2FOE = 100.0f;
  const float32 minDisplacement = 6.0f;
  */

  sint16 xPos, yPos;
  sint16 old_xPos, old_yPos;
  float32 absXDiff, absYDiff;
  float32 deltaYaw, deltaPitch;
  float32 xb_a, xb_c, yb_a, yb_c;
  float32 tx, ty;
  float32 diffx, diffy;
  float32 de, dl;
  float32 alpha_diff;
  float32 ax, ay, bx, by;

  if ( (pTrack->lost_time == 0) && 
       (
         (pTrack->MaxInt > pAnalysisParamIn->contraMotionMinIntensityLux) ||
         (pTrack->anaResStat.isPulsedLight.result == HLA_RESULT_POSITIVE)
       )
     )
  {
    xPos = pTrack->xcenter;
    yPos = pTrack->ycenter;
    old_xPos = xPos - pTrack->delta_x;
    old_yPos = yPos - pTrack->delta_y;

    /*deltaYaw   = -pEgomotionData->yaw;*/
    deltaYaw   = -pMotionState->f32_YawRate * (pEgomotionData->dt);
    deltaPitch = pEgomotionData->ego_pitch;

    /* calc distance between object and epipole (FOE) */
    diffx = (float32)(pCamData->FOE_x - old_xPos);
    diffy = (float32)(pCamData->FOE_y - old_yPos);
    de = (diffx*diffx) + (diffy*diffy);

    if (de < pAnalysisParamIn->contraMotionMinDist2FOE)
    {
      /* set result "idle" */
      pTrack->anaResStat.isContraMotion.result = HLA_RESULT_IDLE;
    }
    else
    {
      /* calc dispalcement in image without rotation */
      HLACamRotGetJacobianxbaxbcybaybcXb(pCam, &xb_a, &xb_c, &yb_a, &yb_c, (float32)old_xPos, (float32)old_yPos);
      tx = (float32)xPos + (xb_a * deltaPitch) + (xb_c * deltaYaw);
      ty = (float32)yPos + (yb_a * deltaPitch) + (yb_c * deltaYaw);

      /* calc length of displacement vector (without rotation) */
      diffx = (float32)old_xPos - tx;
      diffy = (float32)old_yPos - ty;
      dl = (diffx*diffx) + (diffy*diffy);
      absXDiff = CML_f_Abs(tx - old_xPos);
      absYDiff = CML_f_Abs(ty - old_yPos);

      if (    (dl < pAnalysisParamIn->contraMotionMinDisplacement) 
           || ( absXDiff < absYDiff)
         )
      {
        /* set result "idle" */
        pTrack->anaResStat.isContraMotion.result = HLA_RESULT_IDLE;
      }
      else
      {
        /* calc angle between vectors */
        ax = tx - old_xPos;
        ay = ty - old_yPos;
        bx = (float32)(old_xPos - pCamData->FOE_x);
        by = (float32)(old_yPos - pCamData->FOE_y);
        /*alpha_diff = acosf( (ax*bx + ay*by) / (sqrtf(ax*ax + ay*ay) * sqrtf(bx*bx + by*by)) );*/
        alpha_diff = (sqrtf((ax*ax) + (ay*ay)));
        alpha_diff *= (sqrtf((bx*bx) + (by*by)));
        /* ~CodeReview ~ID:b905d736eab1e450656efca64e13bd20 ~Reviewer:CW01\muellerr5 ~Date:28.03.2012 ~Priority:3 ~Comment:check dividion by zero */
        alpha_diff = ((ax*bx) + (ay*by)) / alpha_diff;

        if (alpha_diff < pAnalysisParamIn->contraMotionLowerAlphaThresh)
        {
          /* set result "positive" */
          pTrack->anaResStat.isContraMotion.result = HLA_RESULT_POSITIVE;
        }
        else if (alpha_diff > pAnalysisParamIn->contraMotionUpperAlphaThresh)
        {
          /* set result "negative" */
          pTrack->anaResStat.isContraMotion.result = HLA_RESULT_NEGATIVE;
        }
        else
        {
          /* set result "idle" */
          pTrack->anaResStat.isContraMotion.result = HLA_RESULT_IDLE;
        }
      }
    }
  }
  else
  {
    /* set result "idle" */
    pTrack->anaResStat.isContraMotion.result = HLA_RESULT_IDLE;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationContraMotion */ /*!
  Description:      Do identification for contra motion.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    seg_TrackListnode                       *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void HLAIdentificationContraMotion( const HLA_t_IdentificationParameters* pIdentParamIn,
                                    HLATrack_t*                           pTrack )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  const sint8 maxNegativeConfidence = -31;
  const sint8 maxUnknownConfidence  =   0;
  const sint8 maxPositiveConfidence =  31;

  /*--- VARIABLES ---*/
  uint8 analysisResult;
  
  if (pTrack != NULL)
  {
    /* if the ident state has already reached its maximum positive confidence, do no further updates */
    if (pTrack->idResStat.isContraMotion.confidence < pIdentParamIn->contraMoverPositiveBound)
    {
      analysisResult = pTrack->anaResStat.isContraMotion.result;

      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* update confidence in "negative" direction */
        pTrack->idResStat.isContraMotion.confidence = CML_Max(maxNegativeConfidence, CML_Min(maxUnknownConfidence, pTrack->idResStat.isContraMotion.confidence) - pIdentParamIn->contraMoverConfStepSize);
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* update confidence in "positive" direction */
        pTrack->idResStat.isContraMotion.confidence = CML_Min(maxPositiveConfidence, CML_Max(maxUnknownConfidence, pTrack->idResStat.isContraMotion.confidence) + pIdentParamIn->contraMoverConfStepSize);
      }
      else /*if (analysisResult == HLA_RESULT_IDLE)*/
      {
        /* reset confidence to "unknown" */
        pTrack->idResStat.isContraMotion.confidence = maxUnknownConfidence;
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isContraMotion.confidence<= pIdentParamIn->contraMoverNegativeBound)
      {
        pTrack->idResStat.isContraMotion.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isContraMotion.confidence>= pIdentParamIn->contraMoverPositiveBound)
      {
        pTrack->idResStat.isContraMotion.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isContraMotion.result = HLA_RESULT_IDLE;
      }
    }
  }
  
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisDynamicMotion */ /*!
  Description:      Set the analysis result state isDynamicMotion 

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn      required input for function
  @param[in,out]    HLATrack_t                      *pTrack       current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisDynamicMotion( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                                            HLATrack_t*               pTrack )
{
  pTrack->anaResStat.isDynamicMotion.result = HLA_RESULT_IDLE;

  if (   (pTrack->light_ref != NULL) 
      && (pTrack->lost_time == 0)
     )
  {
    if (pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_DYNAMIC)
    {
      if ((pTrack->MaxInt > pAnalysisParamIn->dynamicMotionMaxInt) ||
          (pTrack->anaResStat.isPulsedLight.result == HLA_RESULT_POSITIVE))
      {
        pTrack->anaResStat.isDynamicMotion.result = HLA_RESULT_POSITIVE;
      }
    }
    else
    {
      pTrack->anaResStat.isDynamicMotion.result = HLA_RESULT_NEGATIVE;
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationDynamicMotion */ /*!
  Description:      Do identification for dynamic tracked objects

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
void HLAIdentificationDynamicMotion( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                           HLATrack_t*                      pTrack )
{
  const sint8 maxNegativeConfidence = -31;
  const sint8 maxPositiveConfidence =  31;

  if (pTrack->idResStat.isDynamicMotion.result == HLA_RESULT_IDLE)
  {
    if (pTrack->anaResStat.isDynamicMotion.result == HLA_RESULT_POSITIVE)
    {
      pTrack->idResStat.isDynamicMotion.result = HLA_RESULT_POSITIVE;
      pTrack->idResStat.isDynamicMotion.confidence = pIdentParamIn->dynamicMotionPositiveBound;
    }
  }
  else
  {
    const uint8 analysisResult = pTrack->anaResStat.isDynamicMotion.result;

    if (analysisResult == HLA_RESULT_NEGATIVE)
    {
      /* update confidence in "negative" direction */
      pTrack->idResStat.isDynamicMotion.confidence = pIdentParamIn->dynamicMotionNegativeBound;
    }
    else if (analysisResult == HLA_RESULT_POSITIVE)
    {
      /* update confidence in "positive" direction */
      pTrack->idResStat.isDynamicMotion.confidence = CML_Min(maxPositiveConfidence, pTrack->idResStat.isDynamicMotion.confidence + pIdentParamIn->dynamicMotionConfStepSize);
    }
    else /*if (analysisResult == HLA_RESULT_IDLE) */
    {
      /* reset confidence to "unknown" */
      pTrack->idResStat.isDynamicMotion.confidence = CML_Max(maxNegativeConfidence, pTrack->idResStat.isDynamicMotion.confidence - pIdentParamIn->dynamicMotionConfStepSize);
    }

    /* set identification result by confidence level */
    if (pTrack->idResStat.isDynamicMotion.confidence >= pIdentParamIn->dynamicMotionPositiveBound)
    {
      pTrack->idResStat.isDynamicMotion.result = HLA_RESULT_POSITIVE;
    }
    else
    {
      pTrack->idResStat.isDynamicMotion.result = HLA_RESULT_NEGATIVE;
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisCloseReflector */ /*!
  Description:      Analyse if track is moving like a static object in close
                    range and is too dark to be a vehicle in close range.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn            required input for function
  @param[in,out]    HLATrack_t                      *pTrack             current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAAnalysisCloseReflector( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                       const HLACameraData_t*           pCamData,
                                             HLATrack_t*                pTrack
                                     )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/
  float32 distRange, maxDist;
  float32 min_dist_static, max_dist_static;
  uint8 isStraightRoad = 0;
  uint8 isInCenter = 0;

  sint16 imageCenterLeftX = (sint16)(pCamData->FOE_x - pAnalysisParamIn->closeReflectorMinDist2FOE);
  sint16 imageCenterRightX = (sint16)(pCamData->FOE_x + pAnalysisParamIn->closeReflectorMinDist2FOE);

  if (pTrack != NULL)
  {
    if ((pTrack->lost_time == 0) && (pTrack->track_time >= pAnalysisParamIn->closeReflectorMinTrackTime))
    {
      if (pTrack->MaxInt > pAnalysisParamIn->closeReflectorMaxIntensity)
      {
        /* set result negative */
        pTrack->anaResStat.isCloseReflector.result = HLA_RESULT_NEGATIVE;
      }
      else
      {
        /* check if own vehicle moves on a straight road (high curve radius) */
        if (pCamData->radiusAbs_m > pAnalysisParamIn->closeReflectorStraightRoadMinRadius)
        {
          isStraightRoad = 1;
        }

        /* check if track lies in the center of the image (related to FOE) */
        if ((pTrack->xcenter > imageCenterLeftX) && (pTrack->xcenter < imageCenterRightX))
        {
          isInCenter = 1;
        }

        /* if we are on a straight road and the track is close to the FOE, */
        /* then do not trust the dynamic / static estimation and set result to "unknown" */
        if ((isStraightRoad == 1) && (isInCenter == 1))
        {
          /* set result idle */
          pTrack->anaResStat.isCloseReflector.result = HLA_RESULT_IDLE;
        }
        else
        {
          max_dist_static = pTrack->xwmax100;
          min_dist_static = pTrack->xwmin100;

          distRange = max_dist_static - min_dist_static;
          maxDist = max_dist_static;

          if (  ( fabsf((max_dist_static - (hlaTracking3DParameters.paramStaticTracker.minTrackDist * 100.f)) <= f_TrackDistThresAssumedAsZero) )
              && ( fabsf((min_dist_static - (hlaTracking3DParameters.paramStaticTracker.minTrackDist * 100.f)) <= f_TrackDistThresAssumedAsZero) )
             )
          {
            /* set result unknown */
            pTrack->anaResStat.isCloseReflector.result = HLA_RESULT_IDLE;
          }
          else
          {
            if (   (pTrack->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_STATIC) 
                && (distRange < pAnalysisParamIn->closeReflectorMaxDistRange) 
                && (maxDist < pAnalysisParamIn->closeReflectorMaxStaticDist))
            {
              /* set result positive */
              pTrack->anaResStat.isCloseReflector.result = HLA_RESULT_POSITIVE;
            }
            else
            {
              /* set result negative */
              pTrack->anaResStat.isCloseReflector.result = HLA_RESULT_NEGATIVE;
            }
          }
        }
      }
    }
    else
    {
      /* set result idle */
      pTrack->anaResStat.isCloseReflector.result = HLA_RESULT_IDLE;
    }
  }

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationCloseReflector */ /*!
  Description:      Do identification for close reflector.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    required input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void HLAIdentificationCloseReflector( const HLA_t_IdentificationParameters* pIdentParamIn,
                                            HLATrack_t*                     pTrack )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  const sint8 maxNegativeConfidence = -31;
  const sint8 maxUnknownConfidence  =   0;
  const sint8 maxPositiveConfidence =  31;

  /*--- VARIABLES ---*/
  uint8 analysisResult;
  
  if (pTrack != NULL)
  {
    /* if the ident state has already reached its maximum positive confidence, do no further updates */
    /* if (pTrack->idResStat.isCloseReflector.confidence != maxPositiveConfidence) */
    {
      analysisResult = pTrack->anaResStat.isCloseReflector.result;

      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* set confidence to "negative" */
        pTrack->idResStat.isCloseReflector.confidence = maxNegativeConfidence;
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* set confidence to "positive" */
        pTrack->idResStat.isCloseReflector.confidence = maxPositiveConfidence;
      }
      else /* if (analysisResult == HLA_RESULT_IDLE) */
      {
        /* reset confidence to "unknown" */
        pTrack->idResStat.isCloseReflector.confidence = maxUnknownConfidence;
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isCloseReflector.confidence <= pIdentParamIn->closeReflectorNegativeBound)
      {
        pTrack->idResStat.isCloseReflector.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isCloseReflector.confidence >= pIdentParamIn->closeReflectorPositiveBound)
      {
        pTrack->idResStat.isCloseReflector.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isCloseReflector.result = HLA_RESULT_IDLE;
      }
    }
  }
  
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisOncomingPair */ /*!
  Description:      Analyse if tracks looks like a light pair of an oncoming 
                    vehicle. Use linked maxima to determine the light pair.

  @param[in]        const HLA_t_AnalysisParameters  *pAnalysisParamIn            required input for function
  @param[in,out]    HLATrack_t                      *pTrack             current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAAnalysisOncomingPair( HLATrack_t*  pTrack )
{
  /* reset analysis result flag */
  pTrack->anaResStat.isOncomingPair.result = HLA_RESULT_IDLE;

  /* get result from HLASegLightOncomingPair() function */
  if (pTrack->light_ref != NULL)
  {
    pTrack->anaResStat.isOncomingPair.result = pTrack->light_ref->Status.resultOP;
  }
}

/* **************************************************************************** 
  Functionname:     HLAGetOPaInputVector */ /*!
  Description:      Calculates features for the input vector of the oncoming
                    pair classifier.

  @param[in,out]    float32     *pX          pointer to feature array
  @param[in]        uint8       length       number of elements in feat. array
  @param[in]        HLATrack_t  *pTrackLeft      pointer to left track of pair
  @param[in]        HLATrack_t  *pTrackRight     pointer to right track of pair

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
static void HLAGetOPaInputVector( const uint8       length,
                                  const HLATrack_t* pTrackLeft,
                                  const HLATrack_t* pTrackRight,
                                        float32*    pX
                                )
{
  /* expecting pTrackLeft and pTrackRight, which come from track pair, to be != NULL. Expecting that there is never the case where there is a track pair with one of tracks != NULL . See hla_trackpair::HLATrackPairAdd */
#ifdef PC_SIM
  assert(pTrackLeft != NULL);
  assert(pTrackRight != NULL);
#endif


  if (   (pTrackLeft->light_ref != NULL) 
      && (pTrackRight->light_ref != NULL) 
     )
  {
    /* reset X */
    (void)memset((void*)(pX), 0, sizeof(float32) * length);
    
    
    /* diff in X position */
    pX[0] = CML_f_Abs((float32)(pTrackLeft->light_ref->Maxima.x) - (float32)(pTrackRight->light_ref->Maxima.x));

    /* avg ngb lux */
    pX[ 1]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_0].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_0].lux);
    pX[ 2]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_1].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_1].lux);
    pX[ 3]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_2].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_2].lux);
    pX[ 4]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_3].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_3].lux);
    pX[ 5]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_4].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_4].lux);
    pX[ 6]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_5].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_5].lux);
    pX[ 7]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_6].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_6].lux);
    pX[ 8]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_7].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_7].lux);
    pX[ 9]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_8].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_8].lux);
    pX[10]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_9].lux  + pTrackRight->light_ref->Maxima.ngb[NGB_9].lux);
    pX[11]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_10].lux + pTrackRight->light_ref->Maxima.ngb[NGB_10].lux);
    pX[12]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_11].lux + pTrackRight->light_ref->Maxima.ngb[NGB_11].lux);
    pX[13]  = 0.5f*(pTrackLeft->light_ref->Maxima.ngb[NGB_12].lux + pTrackRight->light_ref->Maxima.ngb[NGB_12].lux);

#if 0
    for (i = 0; i < 13; i++)
    {
      pX[1 + i] = 0.5F * (SegMax[pTrackLeft->light_ref->iMaxima].ngb[i].lux + SegMax[pTrackRight->light_ref->iMaxima].ngb[i].lux);
    }
#endif

    /*    symmetric diff of ngb lux
     *
     *      left                right
     *        0        <|>        0              
     *     1  2  3     <|>     1  2  3
     *  4  5  6  7  8  <|>  4  5  6  7  8
     *     9 10 11     <|>     9 10 11
     *       12        <|>       12
     */
    pX[14] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_0].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_0].lux);
    pX[15] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_1].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_3].lux);
    pX[16] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_2].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_2].lux);
    pX[17] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_3].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_1].lux);
    pX[18] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_4].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_8].lux);
    pX[19] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_5].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_7].lux);
    pX[20] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_6].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_6].lux);
    pX[21] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_7].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_5].lux);
    pX[22] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_8].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_4].lux);
    pX[23] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_9].lux  - pTrackRight->light_ref->Maxima.ngb[NGB_11].lux);
    pX[24] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_10].lux - pTrackRight->light_ref->Maxima.ngb[NGB_10].lux);
    pX[25] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_11].lux - pTrackRight->light_ref->Maxima.ngb[NGB_9].lux);
    pX[26] = (float32)abs(pTrackLeft->light_ref->Maxima.ngb[NGB_12].lux - pTrackRight->light_ref->Maxima.ngb[NGB_12].lux);
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisOncomingPairFromTargetVehicles */ /*!
  Description:      Use target vehicles to find oncoming vehicle light pairs.  

  @param[in]        HLATargetVehicle_t     *pPair_Start        list of target vehicles

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void HLAAnalysisOncomingPairFromPairs(HLAPair_t *pPair_Start)
{
  HLAPair_t *pPair = pPair_Start;
  HLATrack_t  *pTrackLeft;
  HLATrack_t  *pTrackRight;
  /* ~CodeReview ~ID:fe7e4b668d96acfdfaacfd52fb39ad45 ~Reviewer:CW01\muellerr5 ~Date:28.03.2012 ~Priority:3 ~Comment:magic number */
  float32 X[27];
  float32 sum;
  uint32 i;
  float32 diffRatio;

  while (pPair != NULL)
  {
    pTrackLeft  = pPair->pTLeft;
    pTrackRight = pPair->pTRight;

    
#ifdef PC_SIM
    assert(pTrackLeft != NULL);
    assert(pTrackRight != NULL);
#endif

    diffRatio = (float32)(abs(pTrackRight->MaxInt - pTrackLeft->MaxInt)) / (float32)(CML_Max(pTrackRight->MaxInt, pTrackLeft->MaxInt));

    /* ~CodeReviewBegin ~ID:07ef574356355c4806752ea1835964ad ~Reviewer:CW01\muellerr5 ~Date:28.03.2012 ~Priority:3 ~Comment:magic numbers */
    if (   (abs(pTrackRight->ycenter - pTrackLeft->ycenter) <= 3)
        && ((pTrackRight->xcenter - pTrackLeft->xcenter) <= 15)
        && ((pTrackRight->xcenter - pTrackLeft->xcenter) >= 3)
        && (diffRatio < 0.7f)
    /* ~CodeReviewEnd   ~ID:07ef574356355c4806752ea1835964ad */
        && (pTrackLeft->light_ref != NULL) 
        && (pTrackRight->light_ref != NULL)
       )
    {

      /* get input vector for adaboost classifier */
      /* ~CodeReview ~ID:9c8eecb9c775a210aad308e2511d9304 ~Reviewer:CW01\muellerr5 ~Date:28.03.2012 ~Priority:3 ~Comment:magic number */
      HLAGetOPaInputVector( 27, pTrackLeft, pTrackRight, &(X[0]) );

      /* run classifier */
      sum = 0.0f;
      /* ~CodeReview ~ID:0ccf09df93a1774952ddeb42dea35bf6 ~Reviewer:CW01\muellerr5 ~Date:28.03.2012 ~Priority:3 ~Comment:magic number */
      for (i = 0; i < 50; i++)
      {
        if ( (  ( ( (float32) OPa_Ada[i].sign * X[OPa_Ada[i].idx] ) + OPa_Ada[i].thresh )    ) > 0.0f )
        {
          sum += OPa_Ada[i].alpha;
        }
        else
        {
          sum -= OPa_Ada[i].alpha;
        }
      }

      if (sum > 0.0f)
      {
        pTrackLeft->anaResStat.isOncomingPair.result = HLA_RESULT_POSITIVE;
        pTrackRight->anaResStat.isOncomingPair.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrackLeft->anaResStat.isOncomingPair.result = HLA_RESULT_NEGATIVE;
        pTrackRight->anaResStat.isOncomingPair.result = HLA_RESULT_NEGATIVE;
      }
    }

    pPair = pPair->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationHighwayBright */ /*!
  Description:      Do identification for oncoming lights on highways.

  @param[in]        -
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Patrick Schillinger
**************************************************************************** */
void HLAIdentificationHighwayBright(HLATrack_t   *pTrack)
{
  if( pTrack->anaResStat.isHighwayBright.result == HLA_RESULT_POSITIVE )
  {
    pTrack->idResStat.isHighwayBright.result = HLA_RESULT_POSITIVE;
    pTrack->idResStat.isHighwayBright.confidence = 1;
  }
  else
  {
    pTrack->idResStat.isHighwayBright.result = HLA_RESULT_NEGATIVE;
    pTrack->idResStat.isHighwayBright.confidence = 0;
  }

}

/* **************************************************************************** 
  Functionname:     HLAIdentificationHighwayBrightTruckLights */ /*!
  Description:      Do identification for oncoming truck lights on highways.

  @param[in]        -
  @param[in,out]    HLATrack_t* pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Alexander Fischer
**************************************************************************** */
void HLAIdentificationHighwayBrightTruckLights(HLATrack_t   *pTrack)
{
  if( pTrack->anaResStat.isHighwayBrightTruckLights.result == HLA_RESULT_POSITIVE )
  {
    pTrack->idResStat.isHighwayBrightTruckLights.result = HLA_RESULT_POSITIVE;
    pTrack->idResStat.isHighwayBrightTruckLights.confidence = 1;
  }
  else
  {
    pTrack->idResStat.isHighwayBrightTruckLights.result = HLA_RESULT_NEGATIVE;
    pTrack->idResStat.isHighwayBrightTruckLights.confidence = 0;
  }

}

/* **************************************************************************** 
  Functionname:     HLAIdentificationOncomingPair */ /*!
  Description:      Do identification for oncoming pair.

  @param[in]        const HLA_t_IdentificationParameters    *pIdentParamIn    input for function
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Reik Müller
**************************************************************************** */
void HLAIdentificationOncomingPair( const HLA_t_IdentificationParameters* pIdentParamIn,
                                          HLATrack_t*                     pTrack )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  const sint8 maxNegativeConfidence = -31;
  const sint8 maxUnknownConfidence  =   0;
  const sint8 maxPositiveConfidence =  31;

  /*--- VARIABLES ---*/
  uint8 analysisResult;
  
  if (pTrack != NULL)
  {
    /* if the ident state has already reached its maximum positive confidence, do no further updates */
    /*if (pTrack->idResStat.isOncomingPair.confidence != maxPositiveConfidence)*/
    if (pTrack->idResStat.isOncomingPair.confidence < pIdentParamIn->oncomingPairPositiveBound)
    {
      analysisResult = pTrack->anaResStat.isOncomingPair.result;

      if (analysisResult == HLA_RESULT_NEGATIVE)
      {
        /* update confidence to "negative" direction */
        pTrack->idResStat.isOncomingPair.confidence =   CML_Max(maxNegativeConfidence, CML_Min(maxUnknownConfidence, pTrack->idResStat.isOncomingPair.confidence) 
                                                      - pIdentParamIn->oncomingPairConfStepSize);
      }
      else if (analysisResult == HLA_RESULT_POSITIVE)
      {
        /* update confidence to "positive" direction */
        pTrack->idResStat.isOncomingPair.confidence =   CML_Min(maxPositiveConfidence, CML_Max(maxUnknownConfidence, pTrack->idResStat.isOncomingPair.confidence) 
                                                      + pIdentParamIn->oncomingPairConfStepSize);
      }
      else /* if (analysisResult == HLA_RESULT_IDLE) */
      {
        /* reset confidence to "unknown" */
        /*pTrack->idResStat.isOncomingPair.confidence = maxUnknownConfidence;*/
      }

      /* set identification result by confidence level */
      if (pTrack->idResStat.isOncomingPair.confidence <= pIdentParamIn->oncomingPairNegativeBound)
      {
        pTrack->idResStat.isOncomingPair.result = HLA_RESULT_NEGATIVE;
      }
      else if (pTrack->idResStat.isOncomingPair.confidence >= pIdentParamIn->oncomingPairPositiveBound)
      {
        pTrack->idResStat.isOncomingPair.result = HLA_RESULT_POSITIVE;
      }
      else
      {
        pTrack->idResStat.isOncomingPair.result = HLA_RESULT_IDLE;
      }
    }
  }
  
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

static void HLAAnalysisStaticHigh( const HLA_t_AnalysisParameters*  pAnalysisParamIn,
                                         HLATrack_t*                pTrack )
{
  pTrack->anaResStat.isStaticHigh.result = HLA_RESULT_IDLE;

  if (pTrack->lost_time == 0)
  {
    if (   (pTrack->TrackerClass != HLA_TRACKING3D_TRACKERCLASS_DYNAMIC)
        && (pTrack->statusAnalysisMisc.isFarAboveHorizon == 1)
       )
    {
      if (pTrack->delta_y_lp_lt < pAnalysisParamIn->staticHighDeltaYThresholdPos)
      {
        pTrack->anaResStat.isStaticHigh.result = HLA_RESULT_POSITIVE;
      }
      else if (pTrack->delta_y_lp_lt > pAnalysisParamIn->staticHighDeltaYThresholdNeg)
      {
        pTrack->anaResStat.isStaticHigh.result = HLA_RESULT_NEGATIVE;
      }
      else
      {
        /* when delta_y_lp_lt is equal the threshold -> HLA_RESULT_IDLE is set already */
      }
    }
    else
    {
      pTrack->anaResStat.isStaticHigh.result = HLA_RESULT_NEGATIVE;
    }
  }
}

void HLAIdentificationStaticHigh( const HLA_t_IdentificationParameters* pIdentParamIn,
                                        HLATrack_t*                     pTrack )
{
  const sint8 maxNegativeConfidence = -5;
  const sint8 maxPositiveConfidence =  20;

  if (pTrack != NULL)
  {
    const uint8 analysisResult = pTrack->anaResStat.isStaticHigh.result;

    if (analysisResult == HLA_RESULT_NEGATIVE)
    {
      /* update confidence in "negative" direction */
      pTrack->idResStat.isStaticHigh.confidence = CML_Max(maxNegativeConfidence, pTrack->idResStat.isStaticHigh.confidence - pIdentParamIn->staticHighConfStepSize);
    }
    else if (analysisResult == HLA_RESULT_POSITIVE)
    {
      /* update confidence in "positive" direction */
      pTrack->idResStat.isStaticHigh.confidence = CML_Min(maxPositiveConfidence, pTrack->idResStat.isStaticHigh.confidence + pIdentParamIn->staticHighConfStepSize);
    }
    else /* if (analysisResult == HLA_RESULT_IDLE) */
    {
      /* "unknown" -> no change */
    }


    /* set identification result by confidence level */
    if (pTrack->idResStat.isStaticHigh.confidence <= pIdentParamIn->staticHighNegativeBound)
    {
      pTrack->idResStat.isStaticHigh.result = HLA_RESULT_NEGATIVE;
    }
    else if (pTrack->idResStat.isStaticHigh.confidence >= pIdentParamIn->staticHighPositiveBound)
    {
      pTrack->idResStat.isStaticHigh.result = HLA_RESULT_POSITIVE;
    }
    else
    {
      pTrack->idResStat.isStaticHigh.result = HLA_RESULT_IDLE;
    }
  }
}/* PRQA S 861 1 */
