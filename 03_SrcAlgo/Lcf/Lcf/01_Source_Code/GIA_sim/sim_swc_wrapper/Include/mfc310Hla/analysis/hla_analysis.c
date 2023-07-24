/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysis.c

  DESCRIPTION:            Functions for light track analysis.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2011-05-21

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysis.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:40CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:50CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:11CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.28 2014/03/28 10:36:17CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:17 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/03/26 11:27:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:32 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.26 2014/03/25 19:11:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:48 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.25 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysis.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysis.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.24 2014/03/21 09:38:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:44 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2014/03/19 16:30:25CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:26 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.22 2014/03/13 10:14:05CET Glebov, Roman (uidg4759) 
  CHANGE:                 moved chain of light computation from HLAAnalysisBase to HLAAnalysis2nd
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 13, 2014 10:14:05 AM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.21 2014/03/12 18:07:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:41 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.20 2014/03/10 13:20:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:52 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2014/03/04 16:51:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:47 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2014/02/18 13:21:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:52 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.17 2014/02/11 12:34:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed analysis level 1 color internal time meas
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2014 12:34:47 PM CET]
  CHANGE:                 Change Package : 207432:18 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/02/11 09:20:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed time meas
  CHANGE:                 Fixed dframe calculation on HIL
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:12 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/02/07 09:49:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed critical QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 9:49:55 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.14 2014/02/06 16:02:50CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:51 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.13 2014/01/28 11:46:51CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 -fixed: use only global add features
  CHANGE:                 -remove unused parameter
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 11:46:52 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.12 2014/01/28 10:48:06CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 -renaming of some unclear variables
  CHANGE:                 -changes to meet coding guideline
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:07 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.11 2014/01/21 09:12:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:49 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.10 2014/01/17 13:46:28CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 rename pT and pTLB to pTrack
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 17, 2014 1:46:28 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.9 2014/01/17 11:38:46CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 rename all remaining pT to pTrack
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 17, 2014 11:38:47 AM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.8 2014/01/13 16:57:11CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 pass pHighwayData to IconClassification
  CHANGE:                 Revision 1.7 2014/01/10 18:33:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:30 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.6 2013/12/26 14:32:16CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: solved implicit conversion in the assignment of signed int to the unsigned variable.
  CHANGE:                 
  CHANGE:                 
  CHANGE:                 notes:
  CHANGE:                 bitfield of 1 bit seems to be integer per default
  CHANGE:                 hex constants are also integer.
  CHANGE:                 
  CHANGE:                 multiplication of two integer produces also integer
  CHANGE:                 --- Added comments ---  uidg4759 [Dec 26, 2013 2:32:16 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.5 2013/12/18 15:13:49CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 new function HLAAnalysisHighwayBrightTruckLights
  CHANGE:                 changes in HLAAnalysisHighwayBright
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:13:49 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.4 2013/12/17 17:32:43CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGE:                 --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:43 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.3 2013/12/13 16:45:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:13 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.2 2013/11/21 17:53:59CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:54:00 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1.1.2 2013/11/12 13:44:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:44 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.1.1.1 2013/10/18 13:27:30CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:30 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.1 2013/08/05 17:01:53CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */


/* includes */
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>

#include "hla_base.h"
#include "hlar_ext.h"
#include "hla_cam_rot.h"
#include "hla_analysis.h"
#include "hla_imager.h"
#include "hla_icon.h"

#include "hla_analysisintensity.h"
#include "hla_analysiscolor.h"
#include "hla_analysismisc.h"
#include "hla_analysisicon.h"

#include "hla_analysischain.h"
#include "hla_analysisstreetlamps.h"


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

/*! Do the base analysis. */
static void HLAAnalysisBase( const HLAR_t_RequiredInputs*    pRequiredIn,
                             HLATrack_t*                     pTrack_Start,
                             const HLACamRot*                pCamRot,
                             const HLACameraData_t*          pCamData,
                             HLASLInput_t*                   pSLInput,
                             const HLA_t_AnalysisParameters* pAnalysisParameters,
                             HLAAnalysisData_t*              pAnalysisData,
                             HLAWeatherData_t*               pWeatherData,
                             HLATimeMeasurement_t*           pTimeMeasurement,
                             AS_t_GetTimestampuS32           pfGetTimestampuS32
                            );

/*! Do the 1st level vehicle analysis. */
static void HLAAnalysisLevel1st( const HLAR_t_RequiredInputs* pRequiredIn,
                                 const HLATracking3DOutput_t* pHlaTrackOut,
                                 const HLACameraData_t*       pCamData,
                                 const HLACamRot*             pCamRot,
                                 const RTE_HLA_TrafficStyle   eTrafficStyle,
                                 const HLA_t_Highway*         pHighwayData,
                                 HLATimeMeasurement_t*        pTimeMeasurement,
                                 AS_t_GetTimestampuS32        pfGetTimestampuS32
                                );

/*! Do the 2nd level vehicle analysis. */
static void HLAAnalysisLevel2nd( const HLAR_t_RequiredInputs*                pRequiredIn,
                                 const HLATracking3DOutput_t*                pHlaTrackOut,
                                 const HLA_t_AnalysisParameters*             pAnalysisParameters,
                                 const HLACamRot*                            pCamRot,
                                 const HLACameraData_t*                      pCamData,
                                 HLAChainOfLightData_t*                      pCoLData,
                                 const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                                 const HLA_t_Highway*                        pHighwayData,
                                 const AS_t_ServiceFuncts*                   Services,
                                       HLAIconData_t                         IconData[],
                                       HLAAnalysisData_t*                    pAnalysisData,
                                       HLADebugOutputs_t*                    phlaDebugOutputs
                                );

/*! Do the 3rd level vehicle analysis. */
static void HLAAnalysisLevel3rd(HLATrack_t* pTrack_Start);

/*! Do identification for potential oncoming vehicles. */
static void HLAIdentificationPotVehOncoming(HLATrack_t* pTrack);

/*! Do identification for potential leading vehicles. */
static void HLAIdentificationPotVehAhead(HLATrack_t* pTrack);

/* build up turn off reason */
static void HLAAnalysisBuildTurnOffReason( HLATrack_t*         pTrack_Start,
                                           HLATurnOffReason_t* pDat
                                         );

/* pulsed light analysis */
static void HLAAnalysisPulsedLight( HLATrack_t*  pTrack,
                                    boolean      bIsRed );

/* pulsed light identification */
static void HLAIdentificationPulsedLight( HLATrack_t* pTrack );

/*! Computes time to border */
static void HLAAnalysisTTB(
                           HLATrack_t*                   pTrack_Start,
                           const HLACameraData_t*        pCamData,
                           const HLA_t_AnalysisTTB*      pParam,
                           float32                       cycleTime
                          );

static void HLAAnalysisHorizon(
                               HLATrack_t*            pTrack_Start,
                               const HLACamRot*       pCamRot,
                               const HLACameraData_t* pCamData
                              );

static void HLAAnalysisRedReflectorDensity(const HLAR_t_RequiredInputs* pRequiredIn,
                                           HLATrack_t*                  pTrack_Start,
                                           const HLACameraData_t*       pCamData,
                                           HLAAnalysisData_t*           pAnalysisData);

static void HLAAnalysisPotVehHighProbable(HLATrack_t* pTrack_Start);

/*! Analyses if bad weather conditions detected. */
static sint32 HLAAnalysisWeather(const HLA_t_VehicleState* pVehicleState,
                                       HLAWeatherData_t*   pWeatherData
                                );

/* debug variables. */


/* **************************************************************************** 
  Functionname:     HLAAnalysisInit()                                   */ /*!  
  Description:      Initializes hla analysis. 
                    
  @param[in]        -

  @return           - 
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAAnalysisInit(const HLAR_t_RequiredInputs* ps_In,
                     HLAIconData_t                IconData[],
                     t_PixelData                  Icon[], 
                     HLAAnalysisData_t*           pAnalysisData)
{
  uint32 i;

  (void)memset(&Icon[0], 0, (sizeof(t_PixelData) * HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y * HLA_ICON_ANALYSIS_MAX_BOXES));
  for(i=0; i<HLA_ICON_ANALYSIS_MAX_BOXES; i++)
  {
    (void)memset(&IconData[i], 0, sizeof(HLAIconData_t));
    IconData[i].pData = &Icon[i * HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y];
  }

  (void)memset(pAnalysisData, 0, sizeof(HLAAnalysisData_t));
  
  HLAAnalysisIntensityInit(ps_In);

  HLAAnalysisIconInit();
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisWeather                     */ /*!  
  Description:      Analyses if bad weather conditions detected.


  @param[in]        -

  @return           -1: error, else success
  @pre              -
  @post             -
  @author           Timo Seifert, Marcus Brunn
**************************************************************************** */
static sint32 HLAAnalysisWeather(const HLA_t_VehicleState* pVehicleState,
                                 HLAWeatherData_t*         pWeatherData)
{
  /* weather state machine */
  switch(pWeatherData->eWeatherState)
  {
    case RTE_HLAR_WEATHER_BAD:
      /* adverse weather detected */
      if(pVehicleState->b_FogLampRear == FALSE)
      {
        /* rear fog lamps off */
        pWeatherData->FogLampCnt++;
        /* ~CodeReview ~ID:ff1fdce200b5c4a8b455dc6bca532ee9 ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
        if(pWeatherData->FogLampCnt > 50)
        {
          /* no adverse weather detected */
          /* reset FogLamp counter    */
          pWeatherData->FogLampCnt   = 0;
          pWeatherData->eWeatherState = RTE_HLAR_WEATHER_GOOD;
        }
      }
      else
      {
        /* rear fog lamps on */
        /* reset counter     */
        pWeatherData->FogLampCnt = 0;
      }
      break;

    case RTE_HLAR_WEATHER_UNKNOWN:
    case RTE_HLAR_WEATHER_GOOD:
    case RTE_HLAR_WEATHER_LIGHT_FOG:
    case RTE_HLAR_WEATHER_MEDIUM_FOG:
    case RTE_HLAR_WEATHER_HEAVY_FOG:
    case RTE_HLAR_WEATHER_INVALID:
    /* use RTE_HLAR_WEATHER_INVALID as default */
    default:
      /* No adverse weather detected */
      if(pVehicleState->b_FogLampRear == TRUE)
      {
        /* rear fog lamps on */
        pWeatherData->FogLampCnt++;
        /* ~CodeReview ~ID:dae749adbf3ad1207bab58111ec6010e ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
        if(pWeatherData->FogLampCnt > 50)
        {
          /* adverse weather detected */
          /* reset FogLamp counter    */
          pWeatherData->FogLampCnt   = 0;
          pWeatherData->eWeatherState = RTE_HLAR_WEATHER_BAD;
        }
      }
      else
      {
        /* rear fog lamps off */
        /* reset counter      */
        pWeatherData->FogLampCnt = 0;
      }
      break;
  }
 
  return 0;
}
/* **************************************************************************** 
  Functionname:     HLAAnalysisTTB                     */ /*!  
  Description:      Computes time to border 


  @param[in]        void

  @return           -
  @pre              -
  @post             -
  @author           Dirk Ulbricht
**************************************************************************** */
static void HLAAnalysisTTB(HLATrack_t                    *pTrack_Start,
                           const HLACameraData_t         *pCamData,
                           const HLA_t_AnalysisTTB       *pParam,
                           float32                       cycleTime)
{
  /* get local copy of global pointer */
  HLATrack_t* pTrack = pTrack_Start;

  /* variales for ttb */
  float32 ttb, ttb_l, ttb_r, ttb_u, ttb_o;
          
  /* go thru all list entries */
  while (pTrack != NULL)
  {
    /* compute image coordinates */
    float32 xb = pTrack->xcenter;
    float32 yb = pTrack->ycenter;
    float32 dx = pTrack->delta_x_lp;
    float32 dy = pTrack->delta_y_lp;

    /* predict ttb using cycle time, check ttb not lower zero */
    pTrack->ttb = CML_f_Max(pTrack->ttb - cycleTime, 0.0f);

    /* compute current ttb */
    ttb_l = pTrack->ttb;
    ttb_r = pTrack->ttb;
    ttb_u = pTrack->ttb;
    ttb_o = pTrack->ttb;

    if (pTrack->lost_time==0)
    {
      /* ~CodeReview ~ID:e3f3ecb2dc105362383f3a197f77278d ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
      if (fabsf(dx)>0.001) 
      {
        ttb_l = (((pCamData->RoiX1 - pParam->ttbBorder) - xb) / dx) * cycleTime;
        ttb_r = (((pCamData->RoiX2 + pParam->ttbBorder) - xb) / dx) * cycleTime;
      } 
      else 
      {
        ttb_l = pParam->maxTTB;
        ttb_r = pParam->maxTTB;        
      }

      /* ~CodeReview ~ID:c8f0bf13d0a4c90540762357f15443d2 ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
      if (fabsf(dy)>0.001) 
      {
        ttb_o = (((pCamData->RoiY1 - pParam->ttbBorder) - yb) / dy) * cycleTime;
        ttb_u = (((pCamData->RoiY2 + pParam->ttbBorder) - yb) / dy) * cycleTime;
      } 
      else 
      {
        ttb_o = pParam->maxTTB;
        ttb_u = pParam->maxTTB;
      }
    }

    /* compute ttb from ttb_l, ttb_r, ttb_u */
    ttb_l = CML_f_Max(ttb_l, ttb_r);
    ttb_u = CML_f_Max(ttb_u, ttb_o);
    ttb = CML_f_Min(ttb_l, ttb_u);

    /* check for max/min valid ttb */
    ttb = CML_f_MinMax(0.0f, pParam->maxTTB, ttb);

    /* filter TTB using previous measurements */
    pTrack->ttb = (pTrack->ttb * (pParam->ttbLowPassFactor)) + (ttb * (1.0f - pParam->ttbLowPassFactor));

    /* next object */
    pTrack = pTrack->next;
  }
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisPulsedLight                         */ /*!  
  Description:      Find pulsed lights which saturates during T1
                    and do not accumulate light during T2 and T3
                    -> indication for pulsed lights
                    This effect is best observed on the red and green channels.
                    Fast moving objects are discarded because motion blur
                    may generate the same appearance.

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisPulsedLight( HLATrack_t*  pTrack,
                                    boolean      bIsRed )
{
  uint8 satPixels_Red = 0;
  uint8 satPixels_Green = 0;
  uint8 satPixels_Max1Green = 0;
  uint16 maxRed = 0;
  uint16 maxGreen = 0;
  boolean enoughSaturated = b_FALSE;

  const uint16 minLuxRed = HLAImager_GetIntT1SatLow_RedLux();
  const uint16 maxLuxRed = HLAImager_GetIntT1SatHigh_RedLux();
  const uint16 minLuxGreen = HLAImager_GetIntT1SatLow_GreenLux();
  const uint16 maxLuxGreen = HLAImager_GetIntT1SatHigh_GreenLux();

  /* ~CodeReview ~ID:e61a55fdcba1970e23ad7c1e0666f520 ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:missing is-not-null safety checks for pTrack and pRegion */
  if (pTrack->light_ref != NULL)
  {
    /*         R                   0         */
    /*      B  G  B             1  2  3      */
    /*   R  G  R  G  R       4  5  6  7  8   */
    /*      B  G  B             9 10 11      */
    /*         R                  12         */

    {
      /* count red and green saturated pixels */
      maxRed   = CML_Max(CML_Max(CML_Max(CML_Max(pTrack->light_ref->Maxima.ngb[NGB_0].lux, pTrack->light_ref->Maxima.ngb[NGB_4].lux), pTrack->light_ref->Maxima.ngb[NGB_6].lux), pTrack->light_ref->Maxima.ngb[NGB_8].lux),pTrack->light_ref->Maxima.ngb[NGB_12].lux);
      maxGreen = CML_Max(CML_Max(CML_Max(pTrack->light_ref->Maxima.ngb[NGB_2].lux, pTrack->light_ref->Maxima.ngb[NGB_5].lux), pTrack->light_ref->Maxima.ngb[NGB_7].lux), pTrack->light_ref->Maxima.ngb[NGB_10].lux);
      
      if ((maxRed >= minLuxRed) &&
          (maxRed <= maxLuxRed))
      {
        if (pTrack->light_ref->Maxima.ngb[NGB_0].lux  >= minLuxRed  ) { satPixels_Red++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_4].lux  >= minLuxRed  ) { satPixels_Red++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_6].lux  >= minLuxRed  ) { satPixels_Red++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_8].lux  >= minLuxRed  ) { satPixels_Red++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_12].lux >= minLuxRed  ) { satPixels_Red++; }
      }
      else
      {
        satPixels_Red = 0;
      }

      if ((maxGreen >= minLuxGreen) &&
          (maxGreen <= maxLuxGreen))
      {
        if (pTrack->light_ref->Maxima.ngb[NGB_2].lux  >= minLuxGreen) { satPixels_Green++; satPixels_Max1Green++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_5].lux  >= minLuxGreen) { satPixels_Green++; satPixels_Max1Green++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_7].lux  >= minLuxGreen) { satPixels_Green++; satPixels_Max1Green++; }
        if (pTrack->light_ref->Maxima.ngb[NGB_10].lux >= minLuxGreen) { satPixels_Green++; satPixels_Max1Green++; }
     }
      else
      {
        satPixels_Green = 0;
        satPixels_Max1Green = 0;
      }
    }

    /* ~CodeReview ~ID:3e0fff7e0ad50ec4f4883895f8418edc ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
    if (satPixels_Max1Green >= 4)
    {
      /* workaround for the big saturated lights which generate poor second maxima at the borders */
      enoughSaturated = b_TRUE;
    }
    else
    {
      {
        /* width,height: 0,0 - 2,0 */
        /* ~CodeReview ~ID:a7fcccb6213b482e78350c28aca49c6a ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic numbers */
        if ((satPixels_Red >= 2) ||
            (satPixels_Green >= 2) ||
            ((satPixels_Red + satPixels_Green) >= 2)
           )
        {
          enoughSaturated = b_TRUE;
        }
      }
    }

    if (enoughSaturated == b_TRUE)
    {
      pTrack->anaResStat.isPulsedLight.result = HLA_RESULT_POSITIVE;
    }
    else if (bIsRed == b_FALSE)
    {
      pTrack->anaResStat.isPulsedLight.result = HLA_RESULT_NEGATIVE;
    }
    else
    {
      pTrack->anaResStat.isPulsedLight.result = HLA_RESULT_IDLE;
    }

  }
  else
  {
    /* no light detected */
    pTrack->anaResStat.isPulsedLight.result = HLA_RESULT_NEGATIVE;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationPulsedLight */ /*!
  Description:      Do identification for pulsed light detection.
  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIdentificationPulsedLight( HLATrack_t* pTrack )
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  const sint8 maxNegativeConfidence = -7;
  const sint8 maxPositiveConfidence = 31;

  /*--- VARIABLES ---*/
  uint8 analysisResult;

  if (pTrack != NULL)
  {
    analysisResult = pTrack->anaResStat.isPulsedLight.result;

    if (analysisResult == HLA_RESULT_NEGATIVE)
    {
      /* update confidence to "negative" direction */
      pTrack->idResStat.isPulsedLight.confidence = CML_Max(maxNegativeConfidence, pTrack->idResStat.isPulsedLight.confidence - hlaIdentParam.pulsedLightConfStepSize);
    }
    else if (analysisResult == HLA_RESULT_POSITIVE)
    {
      /* update confidence to "positive" direction */
      pTrack->idResStat.isPulsedLight.confidence = CML_Min(maxPositiveConfidence, pTrack->idResStat.isPulsedLight.confidence + hlaIdentParam.pulsedLightConfStepSize);
    }
    else /*if (analysisResult == HLA_RESULT_IDLE) || (analysisResult == HLA_RESULT_ERROR) */
    {
      /* ~CodeReview ~ID:bd2f7d481bd7302ff00cb918b8cff8f3 ~Reviewer:CW01\muellerr5/PC2357\dijkstg ~Date:16.07.2012 ~Priority:3 ~Comment:dead code */
      /* reset confidence to "unknown" */
      /*pTrack->idResStat.isPulsedLight.confidence = maxUnknownConfidence;*/
    }

    /* set identification result by confidence level */
    if (pTrack->idResStat.isPulsedLight.confidence <= hlaIdentParam.pulsedLightNegativeBound)
    {
      pTrack->idResStat.isPulsedLight.result = HLA_RESULT_NEGATIVE;
    }
    else if (pTrack->idResStat.isPulsedLight.confidence >= hlaIdentParam.pulsedLightPositiveBound)
    {
      pTrack->idResStat.isPulsedLight.result = HLA_RESULT_POSITIVE;
    }
    else
    {
      pTrack->idResStat.isPulsedLight.result = HLA_RESULT_IDLE;
    }
  }

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisBuildTurnOffReason */ /*!
  Description:      build up turn off reason.

  @param[in]        
  @param[out]       
  
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
/* ~CodeReview ~ID:25b15e348fbabb91c3162fd30cc491b4 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:General: poorly documented. */
static void HLAAnalysisBuildTurnOffReason( HLATrack_t*         pTrack_Start,
                                           HLATurnOffReason_t* pDat)
{
  uint32 bufReason = 0;

  HLATrack_t *pTrack = pTrack_Start;

  /* go thru all list entries */
  while (pTrack != NULL) 
  {
    if ( pTrack->statusAnalysisVehicle.isPotentialVehicleOncoming2nd == 1)
    {
      pDat->vehicleOncomingFound = 1;

      /* 1st level turn offs */
      bufReason |= (uint32) ( HLA_TOR__ONCOM__TOO_BRIGHT                * pTrack->statusAnalysisVehicle.isTooBright);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__CONTRA_MOTION_WHITE       * pTrack->statusAnalysisVehicle.isMovingWhite);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__ONCOMING_PAIR             * pTrack->statusAnalysisVehicle.isOncomingPair);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__CENTER_BRIGHT             * pTrack->statusAnalysisVehicle.isCenterBright);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__EXTREME_BRIGHT            * pTrack->statusAnalysisVehicle.isExtremeBright);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__LATERAL_BRIGHT            * pTrack->statusAnalysisVehicle.isLateralBright);

      /* 2nd level turn offs */
      bufReason |= (uint32) ( HLA_TOR__ONCOM__HIGHWAYONCOMINGCAR        * pTrack->statusAnalysisVehicle.isHighwayOncomingCar);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__CLASSRESULTREACHED        * pTrack->statusAnalysisVehicle.isClassResultReached);
      bufReason |= (uint32) ( HLA_TOR__ONCOM__SUDDENLYAPPEARINGVEHICLE  * pTrack->statusAnalysisVehicle.isSuddenlyAppearingVehicle);

      pDat->vehicleOncomingCRCnt = HLA_TOR__MAX_CNT;

#ifdef PC_SIM
      /* 1. reset oncoming turn off reason */
      pTrack->specFirstTurnOffReason &= ~HLA_TOR__ONCOM_BIT_MASK;
      /* 2. set current oncoming turn off reason         */
      /*    but do not delete the ahead turn off reason */
      pTrack->specFirstTurnOffReason |= bufReason;
#endif
    }

    if ( pTrack->statusAnalysisVehicle.isPotentialVehicleAhead2nd == 1)
    {
      pDat->vehicleAheadFound = 1;

      /* 1st level turn offs */
      bufReason |= (uint32) ( HLA_TOR__AHEAD__RED_LIGHT                * pTrack->statusAnalysisVehicle.isRed);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__RED_LIGHT2               * pTrack->statusAnalysisVehicle.isRed2);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__PULSED_LIGHT             * pTrack->statusAnalysisVehicle.isPulsedLight);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__CONTRA_MOTION_NONWHITE   * pTrack->statusAnalysisVehicle.isMovingNonWhite);

      /* 2nd level turn offs */
      bufReason |= (uint32) ( HLA_TOR__AHEAD__CLASSRESULTREACHED       * pTrack->statusAnalysisVehicle.isClassResultReached);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__SUDDENLYAPPEARINGVEHICLE * pTrack->statusAnalysisVehicle.isSuddenlyAppearingVehicle);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__DRIVEDISTREACHED         * pTrack->statusAnalysisVehicle.isDriveDistAheadReached);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__DRIVEDISTDYNAMICREACHED  * pTrack->statusAnalysisVehicle.isDriveDistAheadDynamicReached);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__DRIVEDISTPAIRREACHED     * pTrack->statusAnalysisVehicle.isDriveDistAheadPairReached);
      bufReason |= (uint32) ( HLA_TOR__AHEAD__OVERTAKER                * pTrack->statusAnalysisVehicle.isOvertaker);

      pDat->vehicleAheadCRCnt = HLA_TOR__MAX_CNT;

#ifdef PC_SIM
      /* 1. reset ahead turn off reason */
      pTrack->specFirstTurnOffReason &= ~HLA_TOR__AHEAD_BIT_MASK;
      /* 2. set current ahead turn off reason         */
      /*    but do not delete the oncoming turn off reason */
      pTrack->specFirstTurnOffReason |= bufReason;
#endif
    }

    /* save current turn of reason */
    pDat->TurnOffReason_Current |= bufReason; 

    /* go to next object */
    pTrack = pTrack->next;
  }


  /* check, if oncoming vehicle was found and save the information for next cycle. */
  if (pDat->vehicleOncomingFound == 1)
  {
    if (pDat->vehicleOncomingFoundLastCycle == 0)
    {
      pDat->TurnOffReason_First |= (pDat->TurnOffReason_Current & HLA_TOR__ONCOM_BIT_MASK);
      pDat->vehicleOncomingFRCnt = HLA_TOR__MAX_CNT;
    }
    pDat->vehicleOncomingFoundLastCycle = 1;  
  }
  else
  {
    if (pDat->vehicleOncomingFRCnt == 0)
    {
      /* reset first turn off reason */
      pDat->TurnOffReason_First &= ~HLA_TOR__ONCOM_BIT_MASK;
    }
    pDat->vehicleOncomingFoundLastCycle = 0;
  }

  /* Reset the current turn off reason. */
  if (pDat->vehicleOncomingCRCnt == 0)
  {
    pDat->TurnOffReason_Current &= ~HLA_TOR__ONCOM_BIT_MASK;
  }

  /* reset vehicle oncoming found for next cycle */
  pDat->vehicleOncomingFound = 0;

  /* Decrement counter for the turn off reason storage. */
  if (pDat->vehicleOncomingFRCnt >= 1)
  {
    pDat->vehicleOncomingFRCnt--;
  }
  else
  {
    pDat->vehicleOncomingFRCnt = 0;
  }
  if (pDat->vehicleOncomingCRCnt >= 1)
  {
    pDat->vehicleOncomingCRCnt--;
  }
  else
  {
    pDat->vehicleOncomingCRCnt = 0;
  }


  /* check, if ahead vehicle was found and save the information for next cycle. */
  if (pDat->vehicleAheadFound == 1)
  {
    if (pDat->vehicleAheadFoundLastCycle == 0)
    {
      pDat->TurnOffReason_First |= (pDat->TurnOffReason_Current & HLA_TOR__AHEAD_BIT_MASK);
      pDat->vehicleAheadFRCnt = HLA_TOR__MAX_CNT;
    }
    pDat->vehicleAheadFoundLastCycle = 1;
  }
  else
  {
    if (pDat->vehicleAheadFRCnt == 0)
    {
      /* reset first turn off reason */
      pDat->TurnOffReason_First &= ~HLA_TOR__AHEAD_BIT_MASK;
    }
    pDat->vehicleAheadFoundLastCycle = 0;
  }

  /* Reset the current turn off reason. */
  if (pDat->vehicleAheadCRCnt == 0)
  {
    pDat->TurnOffReason_Current &= ~HLA_TOR__AHEAD_BIT_MASK;
  }

  /* reset vehicle oncoming found for next cycle */
  pDat->vehicleAheadFound = 0;

  /* Decrement counter for the turn off reason storage. */
  if (pDat->vehicleAheadFRCnt >= 1)
  {
    pDat->vehicleAheadFRCnt--;
  }
  else
  {
    pDat->vehicleAheadFRCnt = 0;
  }
  if (pDat->vehicleAheadCRCnt >= 1)
  {
    pDat->vehicleAheadCRCnt--;
  }
  else
  {
    pDat->vehicleAheadCRCnt = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAAnalysis */ /*!
  Description:      Do the analysis.

  @param[in]        const HLAR_t_RequiredInputs   *pRequiredIn,   required input for HLAR
  @param[out]       HLAR_t_ProvidedOutputs        *pOut   provided output from HLAR
  @param[in,out]    HLATrack_t                    *pTrack_Start pointer to tracks
  @param[in,out]    HLAConfiguration_t            *pCfg   HLA frame work configuration

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAAnalysis( const HLAR_t_RequiredInputs*                pRequiredIn,
                  const HLATracking3DOutput_t*                pTrackOut,
                  HLATurnOffReason_t*                         pTOR,
                  const HLACamRot*                            pCamRot,
                  const HLACameraData_t*                      pCamData,
                  const RTE_HLA_TrafficStyle                  eTrafficStyle, 
                  /* icons */
                  HLAIconData_t                               IconData[],
                  HLASLInput_t*                               pSLInput,
                  const HLA_t_AnalysisParameters*             pAnalysisParameters,
                  HLAAnalysisData_t*                          pAnalysisData,
                  const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                  const HLA_t_Highway*                        pHighwayData,
                  HLAChainOfLightData_t*                      pCoLData,
                  HLAWeatherData_t*                           pWeatherData,
                  HLADebugOutputs_t*                          phlaDebugOutputs,
                  const AS_t_ServiceFuncts*                   Services
                 )
{
  uint32 TimeStart_us;

  /* --- base analysis level --- */
  TimeStart_us = Services->pfGetTimestampuS32();
  HLAAnalysisBase( pRequiredIn, 
                   pTrackOut->pTrack, 
                   pCamRot, 
                   pCamData, 
                   pSLInput, 
                   pAnalysisParameters, 
                   pAnalysisData, 
                   pWeatherData, 
                   &phlaDebugOutputs->timeMeas, 
                   Services->pfGetTimestampuS32
                 );

  phlaDebugOutputs->timeMeas.dTimeAnalysisBase_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);
  
  /* --- 1. level analysis --- */
  TimeStart_us = Services->pfGetTimestampuS32();

  HLAAnalysisLevel1st( pRequiredIn, 
                       pTrackOut, 
                       pCamData, 
                       pCamRot, 
                       eTrafficStyle, 
                       pHighwayData, 
                       &phlaDebugOutputs->timeMeas, 
                       Services->pfGetTimestampuS32
                     );
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel1st_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);


  /* --- 2. level analysis --- */
  TimeStart_us = Services->pfGetTimestampuS32();
  HLAAnalysisLevel2nd( pRequiredIn, 
                       pTrackOut, 
                       pAnalysisParameters, 
                       pCamRot,
                       pCamData, 
                       pCoLData,
                       pTracking3DParamsMeasurement, 
                       pHighwayData,
                       Services, 
                       IconData, 
                       pAnalysisData, 
                       phlaDebugOutputs
                     );
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel2nd_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us) - phlaDebugOutputs->timeMeasEve.dTimeEveLrf_us;

  /* --- 3. level analysis --- */
  TimeStart_us = Services->pfGetTimestampuS32();
  HLAAnalysisLevel3rd(pTrackOut->pTrack);
  phlaDebugOutputs->timeMeas.dTimeAnalysisLevel3rd_us = (uint16)(Services->pfGetTimestampuS32() - TimeStart_us);

  /* build up turn off reason buffer. */
  HLAAnalysisBuildTurnOffReason(pTrackOut->pTrack, pTOR);

  /* set the high probability flag for potential candidates */
  HLAAnalysisPotVehHighProbable(pTrackOut->pTrack);
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisBase */ /*!
  Description:      Do the base analysis for helper classifiers.

  @param[in]        const HLAR_t_RequiredInputs   *pRequiredIn,     required input for HLAR
  @param[out]       HLAR_t_ProvidedOutputs        *pOut     provided output from HLAR
  @param[in,out]    HLATrack_t                    *pTrack_Start pointer to tracks
  @param[in,out]    HLAConfiguration_t            *pCfg     HLA frame work configuration

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAAnalysisBase( const HLAR_t_RequiredInputs*    pRequiredIn,
                             HLATrack_t*                     pTrack_Start,
                             const HLACamRot*                pCamRot,
                             const HLACameraData_t*          pCamData,
                             HLASLInput_t*                   pSLInput,
                             const HLA_t_AnalysisParameters* pAnalysisParameters,
                             HLAAnalysisData_t*              pAnalysisData,
                             HLAWeatherData_t*               pWeatherData,
                             HLATimeMeasurement_t*           pTimeMeasurement,
                             AS_t_GetTimestampuS32           pfGetTimestampuS32
                            )
{
  uint32      TimeStart_us;

  /* adverse weather analysis */
  TimeStart_us = pfGetTimestampuS32();
  HLAAnalysisWeather(&pRequiredIn->s_Sig.s_VehicleState, pWeatherData);
  pTimeMeasurement->dTimeAnalysisBaseWeather_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);

  /* estimate Time To Border */
  TimeStart_us = pfGetTimestampuS32();
  HLAAnalysisTTB(pTrack_Start, pCamData, &pAnalysisParameters->ttb, pRequiredIn->s_Par.s_CameraParameter.f32_cycleTime);
  pTimeMeasurement->dTimeAnalysisBaseTTB_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
  
  /* Street Lamps Analysis */
  TimeStart_us = pfGetTimestampuS32();
  HLAAnalysisStreetLamps(pSLInput,&pRequiredIn->s_Sig.s_MotionState,pTrack_Start,pCamData,&pAnalysisParameters->hlaSLParam,pCamRot,&pRequiredIn->s_Par.s_CameraParameter);
  pTimeMeasurement->dTimeAnalysisBaseStreetLamps_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);

  TimeStart_us = pfGetTimestampuS32();
  HLAAnalysisHorizon(pTrack_Start, pCamRot, pCamData);
  pTimeMeasurement->dTimeAnalysisBaseHorizon_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);

  TimeStart_us = pfGetTimestampuS32();
  HLAAnalysisRedReflectorDensity(pRequiredIn, pTrack_Start, pCamData, pAnalysisData);
  pTimeMeasurement->dTimeAnalysisBaseRedReflectorDensity_us = (uint16)(pfGetTimestampuS32() - TimeStart_us);
}




/* **************************************************************************** 
  Functionname:     HLAAnalysisLevel1st */ /*!
  Description:      Do the 1st level vehicle analysis.

  @param[in]        const HLAR_t_RequiredInputs    *pRequiredIn         required input for HLAR
  @param[out]       HLAR_t_ProvidedOutputs         *pOut        provided output from HLAR
  @param[in,out]    HLATrack_t                     *pTrack_Start  pointer to tracks
  @param[in,out]    HLAConfiguration_t             *pCfg        HLA frame work configuration
                    HLACameraData_t                *pCamData    the camera model

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAAnalysisLevel1st( const HLAR_t_RequiredInputs* pRequiredIn,
                                 const HLATracking3DOutput_t* pTrackOut,
                                 const HLACameraData_t*       pCamData,
                                 const HLACamRot*             pCamRot,
                                 const RTE_HLA_TrafficStyle   eTrafficStyle,
                                 const HLA_t_Highway*         pHighwayData,
                                 HLATimeMeasurement_t*        pTimeMeasurement,
                                 AS_t_GetTimestampuS32        pfGetTimestampuS32
                                )
{
  HLATrack_t* pTrack = pTrackOut->pTrack;
  boolean     bIsRed = b_FALSE;
  uint32      TimeStart_us;

  /* Reset time meas */
  pTimeMeasurement->dTimeAnalysisLevel1stIntensity_us = 0;
  pTimeMeasurement->dTimeAnalysisLevel1stColor_us = 0;
  pTimeMeasurement->dTimeAnalysisLevel1stPulsedLight_us = 0;
  pTimeMeasurement->dTimeAnalysisLevel1stMisc_us = 0;
  pTimeMeasurement->dTimeAnalysisLevel1stHighway_us = 0;
  HLAAnalysisIntensityPrepare(pRequiredIn, pCamData, pCamRot, eTrafficStyle);

  /*** analysis part ***/
  while (pTrack != NULL) 
  {
    /* base intensity analysis */ 
    TimeStart_us = pfGetTimestampuS32();
    HLAAnalysisIntensity(&hlaAnalysisParameters, pCamData, pTrack);
    pTimeMeasurement->dTimeAnalysisLevel1stIntensity_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

    /* color analysis */ 
    TimeStart_us = pfGetTimestampuS32();
    bIsRed = HLAAnalysisColor(&hlaAnalysisParameters, pRequiredIn->s_Par.s_HlaPar.Headlight.HeadLightType, pTrack);
    pTimeMeasurement->dTimeAnalysisLevel1stColor_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

    /* pulsed light analysis */
    TimeStart_us = pfGetTimestampuS32();
    HLAAnalysisPulsedLight(pTrack, bIsRed);
    pTimeMeasurement->dTimeAnalysisLevel1stPulsedLight_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

    /* base miscellaneous analysis */ 
    TimeStart_us = pfGetTimestampuS32();
    HLAAnalysisBaseMisc(&hlaAnalysisParameters, pRequiredIn, pCamData, &pTrackOut->dataEgomotion, pCamRot, pTrack);
    pTimeMeasurement->dTimeAnalysisLevel1stMisc_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

    /*highway bright analysis*/
    TimeStart_us = pfGetTimestampuS32();
    HLAAnalysisHighwayBright(eTrafficStyle, pHighwayData, pCamData, pCamRot, pTrack);

    /*highway bright analysis Truck Lights */
    HLAAnalysisHighwayBrightTruckLights(eTrafficStyle, pHighwayData, pCamData, pTrackOut->pPairs);
    pTimeMeasurement->dTimeAnalysisLevel1stHighway_us += (uint16)(pfGetTimestampuS32() - TimeStart_us);

    /* go to next object */
    pTrack = pTrack->next;
  }
  HLAAnalysisOncomingPairFromPairs(pTrackOut->pPairs);

  /*** identification part ***/
  pTrack = pTrackOut->pTrack;
  while (pTrack != NULL) 
  {
    /* base intensity identification */ 
    HLAIdentificationIntensity(&hlaIdentParam, pTrack);

    /* color identification */ 
    HLAIdentificationColorOther(&hlaIdentParam, pTrack);
    HLAIdentificationColorWhiteOrRed(&hlaIdentParam, pTrack);

    /* pulsed light identification */
    HLAIdentificationPulsedLight( pTrack );

    /* base miscellaneous identification */ 
    HLAIdentificationContraMotion(&hlaIdentParam, pTrack);
    HLAIdentificationDynamicMotion(&hlaIdentParam, pTrack);
    HLAIdentificationCloseReflector(&hlaIdentParam, pTrack);
    HLAIdentificationStaticHigh(&hlaIdentParam, pTrack);
    HLAIdentificationOncomingPair(&hlaIdentParam, pTrack);
    HLAIdentificationHighwayBright(pTrack);
    HLAIdentificationHighwayBrightTruckLights(pTrack);


    HLAIdentificationPotVehOncoming(pTrack);

    HLAIdentificationPotVehAhead(pTrack);

    /* go to next object */
    pTrack = pTrack->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisLevel2nd */ /*!
  Description:      Do the 2st level vehicle analysis.

  @param[in]        const HLAR_t_RequiredInputs   *pRequiredIn,     required input for HLAR
  @param[out]       HLAR_t_ProvidedOutputs        *pOut     provided output from HLAR
  @param[in,out]    seg_TrackListnode             *pTrack_Start pointer to tracks
  @param[in,out]    HLAConfiguration_t            *pCfg     HLA frame work configuration

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAAnalysisLevel2nd( const HLAR_t_RequiredInputs*                pRequiredIn,
                                 const HLATracking3DOutput_t*                pHlaTrackOut,
                                 const HLA_t_AnalysisParameters*             pAnalysisParameters,
                                 const HLACamRot*                            pCamRot,
                                 const HLACameraData_t*                      pCamData,
                                       HLAChainOfLightData_t*                pCoLData,
                                 const HLATracking3DParametersMeasurement_t* pTracking3DParamsMeasurement,
                                 const HLA_t_Highway*                        pHighwayData,
                                 const AS_t_ServiceFuncts*                   Services,
                                       HLAIconData_t                         IconData[],
                                       HLAAnalysisData_t*                    pAnalysisData,
                                       HLADebugOutputs_t*                    phlaDebugOutputs
                                )
{
  HLAAnalysisChain(pHlaTrackOut->pTrack,pCamRot, &pAnalysisParameters->hlaChainParam,pCoLData);
  /* extract the Icons of the current Image */
  HLAIconPrepareThisFrame(pHlaTrackOut->pTrack, IconData, pCamData, &pRequiredIn->s_Par.s_CameraParameter, pTracking3DParamsMeasurement);

  HLAIconClassification( pRequiredIn, 
                         pHlaTrackOut,
                         pCamData, 
                         pTracking3DParamsMeasurement,
                         Services,
                         pHighwayData,
                         &hlaAnalysisParameters,
                         pAnalysisData, 
                         IconData,
                         phlaDebugOutputs
                       );
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisLevel3rd */ /*!
  Description:      Do the 3rd level vehicle analysis.

  @param[in]        const HLAR_t_RequiredInputs   *pRequiredIn,     required input for HLAR
  @param[out]       HLAR_t_ProvidedOutputs        *pOut     provided output from HLAR
  @param[in,out]    seg_TrackListnode             *pTrack_Start pointer to tracks
  @param[in,out]    HLAConfiguration_t            *pCfg     HLA frame work configuration

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAAnalysisLevel3rd(HLATrack_t* pTrack_Start)
{
  HLATrack_t* pTrack = pTrack_Start;
  HLAStatusAnalysisVehicle_t* pStatusAnalysisVehicle;
  HLAIdentificationResultState_t idResStat;

  /* go thru all list entries */
  while (pTrack != NULL) 
  {
    pStatusAnalysisVehicle = &pTrack->statusAnalysisVehicle;
    idResStat = pTrack->idResStat;

    /* set target driving direction                                                           */
    /* 1st level is sticky, except that the track is above ROI                                */
    /* 2nd level is sticky, except that 1st level is not passed (e.g. track is above ROI)     */
    /* 3rd level keeps vehicle status but could change from ahead to oncoming and vice versa  */
    /*           except that 2nd level is not passed                                          */
    if(    (pStatusAnalysisVehicle->isPotentialVehicleOncoming2nd == 1)
        || (pStatusAnalysisVehicle->isPotentialVehicleAhead2nd == 1)
      )
    {
      /* vehicle detected */

      if(pStatusAnalysisVehicle->isVehicleAhead == 1)
      {
        /* vehicle ahead */
        if(    (pTrack->RedLightCnt == 0)
            && (idResStat.isWhiteOrRed.result  == HLA_RESULT_POSITIVE)
            && (idResStat.isPulsedLight.result == HLA_RESULT_NEGATIVE)
          )
        {
          /* switch to oncoming traffic */
          pStatusAnalysisVehicle->isVehicleOncoming = 1;
          pStatusAnalysisVehicle->isVehicleAhead    = 0;
        }
        else
        {
          /* still traffic ahead */
        }
      }
      else if(pStatusAnalysisVehicle->isVehicleOncoming == 1)
      {
        /* oncoming traffic */
        /* ~CodeReview ~ID:3570344e5e7d760661a3caa9838d2b6d ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
        if(    (pTrack->RedLightCnt >= 7)
            || (idResStat.isWhiteOrRed.result  == HLA_RESULT_NEGATIVE)
            || (idResStat.isPulsedLight.result == HLA_RESULT_POSITIVE)
          )
        {
          /* switch to vehicle ahead */
          pStatusAnalysisVehicle->isVehicleAhead    = 1;
          pStatusAnalysisVehicle->isVehicleOncoming = 0;
        }
        else
        {
          /* still traffic oncoming */
        }
      }
      else
      {
        /* vehicle detected the first time */
        pTrack->trace_time_firstVehicleDetection = pTrack->trace_time;

        /* ~CodeReview ~ID:bb43a8b5be16056d6246e3e938d0e9da ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
        if(    (pTrack->RedLightCnt >= 7)
            || (idResStat.isWhiteOrRed.confidence < 0)
            || (idResStat.isPulsedLight.confidence > 0)
          )
        {
          /* vehicle ahead */
          pStatusAnalysisVehicle->isVehicleAhead    = 1;
          pStatusAnalysisVehicle->isVehicleOncoming = 0;
        }
        else
        {
          /* oncoming traffic */
          pStatusAnalysisVehicle->isVehicleOncoming = 1;
          pStatusAnalysisVehicle->isVehicleAhead    = 0;
        }
      }
    }
    else
    {
      /* no vehicle detected */
      pStatusAnalysisVehicle->isVehicleOncoming = 0;
      pStatusAnalysisVehicle->isVehicleAhead    = 0; 
    }
   
    /* go to next object */
    pTrack = pTrack->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationPotentialVehicleOncoming */ /*!
  Description:      Do identification for potential oncoming vehicles.

  @param[in,out]    HLATrack_t                              *pTrack     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAIdentificationPotVehOncoming( HLATrack_t* pTrack )
{
  HLAStatusAnalysisVehicle_t* pStatusAnalysisVehicle = &pTrack->statusAnalysisVehicle;
  HLAIdentificationResultState_t idResStat = pTrack->idResStat;

  if (pTrack->statusAnalysisMisc.isAboveROI == 0)
  {
    /* in vehicle roi */

    if(pTrack->lost_time == 0)
    {
      /* too bright */
      if (   (  idResStat.isTooBright.result  == HLA_RESULT_POSITIVE)
          && (!(idResStat.isOtherColor.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE))
          && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
         )
      {
        pStatusAnalysisVehicle->isTooBright = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isTooBright = 0;
      }
      
      /* center bright */
      if (   (idResStat.isCenterBright.result == HLA_RESULT_POSITIVE)
          && (!(idResStat.isOtherColor.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE))
          && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
         )
      {
        pStatusAnalysisVehicle->isCenterBright = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isCenterBright = 0;
      }

      /* lateral bright */
      if (   (idResStat.isLateralBright.result == HLA_RESULT_POSITIVE)
          && (!(idResStat.isOtherColor.result  == HLA_RESULT_POSITIVE))
          && (!(idResStat.isWhiteOrRed.result  == HLA_RESULT_NEGATIVE))
          && (!(idResStat.isStreetLamp.result  == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result  == HLA_RESULT_POSITIVE))
         )
      {
        pStatusAnalysisVehicle->isLateralBright = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isLateralBright = 0;
      }

      /* extreme bright */
      if (idResStat.isExtremeBright.result == HLA_RESULT_POSITIVE)
      {
        pStatusAnalysisVehicle->isExtremeBright = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isExtremeBright = 0;
      }

      /* moving and white color */
      if (   (   (idResStat.isContraMotion.result == HLA_RESULT_POSITIVE)
              || (idResStat.isDynamicMotion.result == HLA_RESULT_POSITIVE)
             )
          && (!(idResStat.isOtherColor.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE))
         )
      {
        pStatusAnalysisVehicle->isMovingWhite = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isMovingWhite = 0;
      }

      /* oncoming pair */
      if (     (idResStat.isOncomingPair.result == HLA_RESULT_POSITIVE)
          && (!(idResStat.isOtherColor.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE))
          && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
         )
      {
        pStatusAnalysisVehicle->isOncomingPair = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isOncomingPair = 0;
      }    

      /* highway oncoming light */
      if(     (idResStat.isHighwayBright.result == HLA_RESULT_POSITIVE)
         && (!(idResStat.isOtherColor.confidence > 0))
         && (!(idResStat.isWhiteOrRed.confidence < 0))
         && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
         && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
         )
      {
        pStatusAnalysisVehicle->isHighwayBright = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isHighwayBright = 0;
      }

      /* highway oncoming truck position light */
      if(      (idResStat.isHighwayBrightTruckLights.result == HLA_RESULT_POSITIVE)
          && (!(idResStat.isOtherColor.confidence > 0))
          && (!(idResStat.isWhiteOrRed.confidence < 0))
          &&   (idResStat.isChainOfLights.result == HLA_RESULT_NEGATIVE)
          )
      {
          pStatusAnalysisVehicle->isHighwayBrightTruckLights = 1;
      }
      else
      {
          pStatusAnalysisVehicle->isHighwayBrightTruckLights = 0;
      }

      if (   (pStatusAnalysisVehicle->isVehicleOncoming == 1)        /* detected last frame as vehicle -> sticky status */
          || (pStatusAnalysisVehicle->isTooBright == 1)
          || (pStatusAnalysisVehicle->isCenterBright == 1)
          || (pStatusAnalysisVehicle->isLateralBright == 1)
          || (pStatusAnalysisVehicle->isExtremeBright == 1)
          || (pStatusAnalysisVehicle->isMovingWhite == 1)
          || (pStatusAnalysisVehicle->isOncomingPair == 1)
          || (pStatusAnalysisVehicle->isHighwayBright == 1)
         )
      {
        pStatusAnalysisVehicle->isPotentialVehicleOncoming1st = 1; 
      }
      else
      {
        pStatusAnalysisVehicle->isPotentialVehicleOncoming1st = 0;
      }
    }
  }
  else
  {
    /* above Roi -> no vehicle  */
    pStatusAnalysisVehicle->isPotentialVehicleOncoming1st = 0;
  }
}

/* **************************************************************************** 
  Functionname:     HLAIdentificationPotentialVehicleAhead */ /*!
  Description:      Do identification for potential leading vehicles.

  @param[in]        const HLAR_t_RequiredInputs             *pRequiredIn    required input for function
  @param[in,out]    HLATrack_t                              *pT     current track for analysis

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAIdentificationPotVehAhead(HLATrack_t* pTrack)
{
  HLAStatusAnalysisVehicle_t* pStatusAnalysisVehicle = &pTrack->statusAnalysisVehicle;
  HLAIdentificationResultState_t idResStat = pTrack->idResStat;

  if (pTrack->statusAnalysisMisc.isAboveROI == 0)
  {
    /* in vehicle roi */

    if(pTrack->lost_time == 0)
    {
      /* red light */
      /* ~CodeReview ~ID:b73111dfff5ea19cc5bb090f1f58a9ba ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
      if(      (pTrack->RedLightCnt >= 7)
          && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
        )
      {
        pStatusAnalysisVehicle->isRed = 1;  
      }
      else
      {
        pStatusAnalysisVehicle->isRed = 0;
      }
      
      /* red light #2 */
      if(    (!(idResStat.isOtherColor.result == HLA_RESULT_POSITIVE))
          &&   (idResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE)
          && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
        ) 
      {
        pStatusAnalysisVehicle->isRed2 = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isRed2 = 0;
      }
           

      /* pulsed light */
      if(      (idResStat.isPulsedLight.result == HLA_RESULT_POSITIVE)
          && (!(idResStat.isStreetLamp.result == HLA_RESULT_POSITIVE))
          && (!(idResStat.isStaticHigh.result == HLA_RESULT_POSITIVE))
        )
      {
        pStatusAnalysisVehicle->isPulsedLight = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isPulsedLight = 0;
      }
      
      
      /* moving and no white color */
      if (   (   (idResStat.isContraMotion.result == HLA_RESULT_POSITIVE)
              || (idResStat.isDynamicMotion.result == HLA_RESULT_POSITIVE)
             )
          && (   (idResStat.isOtherColor.result == HLA_RESULT_POSITIVE)
              || (   (!(idResStat.isOtherColor.result == HLA_RESULT_POSITIVE))
                  && (!(idResStat.isWhiteOrRed.result == HLA_RESULT_POSITIVE))
                 )
             )
         )
      {
        pStatusAnalysisVehicle->isMovingNonWhite = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isMovingNonWhite = 0;
      }

      if (   (pStatusAnalysisVehicle->isVehicleAhead == 1)           /* detected last frame as vehicle -> sticky status */
          || (pStatusAnalysisVehicle->isRed == 1)
          || (pStatusAnalysisVehicle->isRed2 == 1)
          || (pStatusAnalysisVehicle->isPulsedLight == 1)
          || (pStatusAnalysisVehicle->isMovingNonWhite == 1)
         )
      {
        pStatusAnalysisVehicle->isPotentialVehicleAhead1st = 1;
      }
      else
      {
        pStatusAnalysisVehicle->isPotentialVehicleAhead1st = 0; 
      }
    }
  }
  else
  {
    /* above Roi -> no vehicle  */
    pStatusAnalysisVehicle->isPotentialVehicleAhead1st = 0;
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisHorizon                                        */ /*!
  Description:      Set the miscellaneous analysis status isAboveHorizon
                    which indicates objects appearing above the camera horizon

  @param[in]        const HLACamRot                    *pCam     the camera model

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisHorizon(HLATrack_t*            pTrack_Start,
                               const HLACamRot*       pCamRot,
                               const HLACameraData_t* pCamData
                              )
{
  HLATrack_t *pTrack = pTrack_Start;

  /* straight horizontal line y = a*x + b */
  /* ~CodeReview ~ID:9f8d4ae4cbfd5888bfc6339163bec76d ~Reviewer:CW01\muellerr5/PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:120930 Magic numbers. Consider centralization of these numbers. */
  const float32 x1 = HLACamRotGetxb(pCamRot, 5000.0f,  500.0f,   0.0f);
  const float32 y1 = HLACamRotGetyb(pCamRot, 5000.0f,  500.0f,   0.0f);
  const float32 x2 = HLACamRotGetxb(pCamRot, 5000.0f, -500.0f,   0.0f);
  const float32 y2 = HLACamRotGetyb(pCamRot, 5000.0f, -500.0f,   0.0f);

  /* ~CodeReview ~ID:59b35d22315e7d15cccdf27f965c0ff9 ~Reviewer:PC2357\dijkstg/CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:possible division by zero (theoretically... if HLACamRotGetxb doesn't work correct) */
  const float32 a = (y1-y2) / (x1-x2);
  const float32 b = y1 - (a * x1);

  /* 40% of the pixels of horizon to upper function roi boundary */
  /* ~CodeReview ~ID:9af105d1c234962606cca046daac8b9b ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
  float32 farAboveHorizonPixels = 0.4f * (pCamData->FOE_y - pCamData->RoiYu);

  while (pTrack != NULL)
  {
    const float32 yHorizon = (a * pTrack->xcenter) + b;

    if (pTrack->ycenter < yHorizon)
    {
      pTrack->statusAnalysisMisc.isAboveHorizon = 1;
    }
    else
    {
      pTrack->statusAnalysisMisc.isAboveHorizon = 0;
    }

    if (pTrack->ycenter < (yHorizon - farAboveHorizonPixels))
    {
      pTrack->statusAnalysisMisc.isFarAboveHorizon = 1;
    }
    else
    {
      pTrack->statusAnalysisMisc.isFarAboveHorizon = 0;
    }

    pTrack = pTrack->next;
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisRedReflectorDensity                        */ /*!
  Description:      Count the red reflectors per driven meter and set the
                    redReflectorArea status flag

  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisRedReflectorDensity(const HLAR_t_RequiredInputs* pRequiredIn,
                                           HLATrack_t*                  pTrack_Start,
                                           const HLACameraData_t*       pCamData,
                                           HLAAnalysisData_t*           pAnalysisData)
{
  HLATrack_t *pTrack = pTrack_Start;
  const float32 dist = pRequiredIn->s_Sig.s_MotionState.f32_Speed * pRequiredIn->s_Par.s_CameraParameter.f32_cycleTime;

  /* ~CodeReview ~ID:f61f657ee5782c9baea8b1776c16afe8 ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
  if (dist > 0.01f)
  {
    /* count the red reflectors */
    uint16 reflectorCount = 0;

    while (pTrack != NULL)
    {
      if ((pTrack->TrackingStatus.willBeRemoved == 1) &&
          (pTrack->statusAnalysisMisc.isAboveHorizon == 0) &&
          /* ~CodeReview ~ID:8f8f9dd17484c3eac1909215bfffc11d ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
          (   (pTrack->RedLightCnt >= 7) ||
              (   (pTrack->idResStat.isOtherColor.result != HLA_RESULT_POSITIVE) && 
                  (pTrack->idResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE)
              )
          ) &&
          /* ~CodeReview ~ID:2032402d7fbe19a9660c9272ca22f1fe ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic numbers */
          (   (pTrack->xcenter > (pCamData->RoiX2 - ((pCamData->RoiX2 - pCamData->FOE_x) / 2))) ||
              (pTrack->xcenter < (pCamData->RoiX1 + ((pCamData->FOE_x - pCamData->RoiX1) / 2)))
          ) &&
          (pTrack->statusAnalysisVehicle.isVehicleAhead == 0) &&
          (pTrack->statusAnalysisVehicle.isVehicleOncoming == 0)
         )
      {
        reflectorCount++;
      }

      /* go to next object */
      pTrack = pTrack->next;
    }

    /* update reflector density */
    /* ~CodeReview ~ID:2680c53808314071927f9ad0b0f76ddc ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
    pAnalysisData->RedReflectorDensity += 0.01f* ((reflectorCount / dist) - pAnalysisData->RedReflectorDensity);

  }

  if (pAnalysisData->bRedReflectorArea == b_TRUE)
  {
    /* ~CodeReview ~ID:fae5a542aa310a17ac636cb48bb3595b ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
    if (pAnalysisData->RedReflectorDensity < 0.01f)
    {
      pAnalysisData->bRedReflectorArea = b_FALSE;
    }
  }
  else
  {
    /* ~CodeReview ~ID:241b18f4fb9962d7a3493c86c96eeb65 ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
    if (pAnalysisData->RedReflectorDensity > 0.02f)
    {
      pAnalysisData->bRedReflectorArea = b_TRUE;
    }
  }
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisPotVehHighProbable                        */ /*!
  Description:      Indicate which tracks have high probability to become
                    a vehicle quite soon.

  @author           Stefan Zechner
**************************************************************************** */
static void HLAAnalysisPotVehHighProbable( HLATrack_t* pTrack_Start )
{
  HLATrack_t *pTrack = pTrack_Start;

  while (pTrack != NULL)
  {
    if (pTrack->iconState.classResultSum > 0)
    {
      pTrack->statusAnalysisVehicle.isPotentialVehicleHighProbable = 1;
    }
    else
    {
      pTrack->statusAnalysisVehicle.isPotentialVehicleHighProbable = 0;
    }

    /* go to next object */
    pTrack = pTrack->next;
  }
}/* PRQA S 861 1 */
