/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    Vision Mid

  COMPONENT:              HLA

  MODULNAME:              hla_tunnel.c

  DESCRIPTION:            Functions for tunnel detection.

  AUTHOR:                 Alexander Manz

  CREATION DATE:          01.11.2012

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_tunnel.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:58CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:40CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:30CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.12 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_tunnel.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_tunnel.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.11 2014/03/19 16:30:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:35 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.10 2014/03/10 13:20:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:47 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9 2014/03/04 16:52:17CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:18 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.8 2014/02/24 11:44:36CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - tunnel detection types changed
  CHANGE:                  - removed some unnecessary flags from the simulation INI file (all related to very old visu)
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 24, 2014 11:44:37 AM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.7 2014/01/24 13:37:59CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:59 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.6 2014/01/10 18:33:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:34 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.5 2013/08/30 13:31:37CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: stop giving out the tunnel state at night due to many false positives. Will be reenabled once the detection quality is up.
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 30, 2013 1:31:37 PM CEST]
  CHANGE:                 Change Package : 188780:1 http://mks-psad:7002/im/viewissue?selection=188780
  CHANGE:                 Revision 1.4 2013/08/22 09:45:43CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: fixed a bug cause by *#%&% PC_SIM flag
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 22, 2013 9:45:44 AM CEST]
  CHANGE:                 Change Package : 188780:1 http://mks-psad:7002/im/viewissue?selection=188780
  CHANGE:                 Revision 1.3 2013/08/19 16:53:02CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: Rough implementation of tunnel detection at night based on street lamps.
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 19, 2013 4:53:03 PM CEST]
  CHANGE:                 Change Package : 188780:1 http://mks-psad:7002/im/viewissue?selection=188780
  CHANGE:                 Revision 1.2 2013/08/12 15:38:23CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Fixed a bug in the tunnel detection escape mode.
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 12, 2013 3:38:24 PM CEST]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1 2013/08/05 17:01:59CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.1.1.27 2013/08/05 16:15:50CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: Change in detection type
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 5, 2013 4:15:50 PM CEST]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.26 2013/08/05 14:46:01CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                 - Fixed a bug in tunnel detection and
  CHANGE:                 - Improved the usage of measFreezes in tunnel detection visualization
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 5, 2013 2:46:01 PM CEST]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.25 2013/08/02 15:28:15CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: First code for Tunnel Detection at night - not enabled yet
  CHANGE:                 Fix: changed a minor bug in the code
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:28:16 PM CEST]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.24 2013/06/13 16:23:23CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra error
  CHANGE:                 --- Added comments ---  brunnm [Jun 13, 2013 4:23:23 PM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.1.1.23 2013/06/07 10:42:50CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Structure updates
  CHANGE:                 --- Added comments ---  uidv8777 [Jun 7, 2013 10:42:50 AM CEST]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.22 2013/03/26 17:27:53CET Manz, Alexander (uidv8777) 
  CHANGE:                 Adapted Tunnel Detection to use BMW Kodierparameter
  CHANGE:                  == Warning: not fully tested yet, though it should work (with an emphasis on should) ==
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 26, 2013 5:27:54 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.21 2013/03/21 17:21:53CET Manz, Alexander (uidv8777) 
  CHANGE:                 Added possibility to store screenshots of tunnel events in evaluation.
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 21, 2013 5:21:54 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.20 2013/03/15 12:56:46CET Manz, Alexander (uidv8777) 
  CHANGE:                 Tunnel detection update includes ability to work with parameter and create measFreezes
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 15, 2013 12:56:47 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.19 2013/03/12 10:38:19CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed Lint errors
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 10:38:19 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1.1.18 2013/03/11 16:13:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:45 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1.1.17 2013/03/11 14:33:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:04 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1.1.16 2013/03/08 17:34:45CET Manz, Alexander (uidv8777) 
  CHANGE:                 Changed data structure for tunnel recognition.
  CHANGE:                 Contains also first implementations for possibility of measFreezes
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 8, 2013 5:34:46 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.15 2013/02/04 17:33:22CET Manz, Alexander (uidv8777) 
  CHANGE:                 Further improvements for tunnel detection:
  CHANGE:                  - added city detection information for a emergency escape in twilight scenario
  CHANGE:                  - sorted features for tunnel detection in different order
  CHANGE:                  - changed limits in detection
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 4, 2013 5:33:23 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.14 2013/01/30 13:16:25CET Manz, Alexander (uidv8777) 
  CHANGE:                 Corrected TunnelDetection Init/Reset Function
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 30, 2013 1:16:26 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.13 2013/01/24 16:37:11CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:12 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.1.1.12 2013/01/22 11:07:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed lint/misra errors
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 22, 2013 11:07:54 AM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1.1.11 2013/01/21 13:37:36CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra/ lint errors
  CHANGE:                 --- Added comments ---  brunnm [Jan 21, 2013 1:37:37 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.1.1.10 2013/01/18 13:51:09CET Manz, Alexander (uidv8777) 
  CHANGE:                 Tunnel detection at daylight first version
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 18, 2013 1:51:10 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hla_tunnel.h"

/*****************************************************************************
  EXTERNAL VARIABLES 
*****************************************************************************/


/*****************************************************************************
  [SYMBOLIC] CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
static float32            change_dist     = 0.0f;
static RTE_HLAR_CityState eCity           = RTE_HLAR_CITY_UNKNOWN;
static boolean            bCityEscapeMode = b_FALSE;
static uint8              nightHyst       = 0;
static float32            frame_dist      = 0.0f;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLATunnelCalculation( const HLASegSubImage_t*   pHLASubImage,
                                        HLATunnelOutput_t*  pOut
                                );

/*! Day time tunnel detection algorithm. */
static void HLATunnelDecisionDay( const RTE_HLAR_ParameterTunnel_t* pParams,
                                        HLATunnelOutput_t*          pHLATunnelOutput,
                                        RTE_HLAR_Tunnel*            pTunnelResult
                                );

/*! Night time tunnel detection algorithm. */
static void HLATunnelDecisionNight(       HLATrack_t*                 pTrackStart,
                                    const RTE_HLAR_ParameterTunnel_t* pParams,
                                          HLATunnelOutput_t*          pHLATunnelOutput,
                                          RTE_HLAR_Tunnel*            pTunnelResult
                                  );


/* **************************************************************************** 
  Functionname:     HLATunnelCalculation                                 */ /*!  
  Description:      Calculates the features for tunnel detection based on the
                    luminances in a sub-sampled image.

  @param[in]        HLASegSubImage_t*   pHLASubImage      pointer to the subsampled image
  @param[in]        HLATunnelOutput_t*  pHLATunnelOutput  pointer to tunnel analysis data
  @pre              -
  @post             -
  @author           Alexander Manz
**************************************************************************** */
static void HLATunnelCalculation(const HLASegSubImage_t*  pHLASubImage,
                                       HLATunnelOutput_t* pOut
                                )
{
  static eHLADataState_t seg_status = HLA_DATA_STATE_VALID;
  static float32 temp_dist;
  static float32 temp_dist_inv;
#if (TUNNEL_FEATURES_NEXT_GEN == SWITCH_ON)
  static const float32 div3 = 1.0f / 3.0f;
#endif
  static HLATunnelFeatures_t* pNewFeat;
  uint8 iy, iFt;

  HLATunnelFeatures_t* pAvg    =  &(pOut->filteredFeat);
  HLATunnelFeatures_t* pStart  =  pOut->pFeaturesStart;

  /* check if segmentation was successful */
  for(iy = 0; iy < HLA_SEG_INTENSITY_SUB_IMG_HEIGHT; iy++)
  {
    if (pHLASubImage->SubImage_State[iy].State != HLA_DATA_STATE_VALID)
    {
      seg_status = HLA_DATA_STATE_INVALID;
    }
  }

  if(seg_status == HLA_DATA_STATE_VALID)
  {
    /* get next HLATunnelFeature */
    pNewFeat = pStart->pNext;

    /* remove old data from average */
    temp_dist = pAvg->frame_distance - pNewFeat->frame_distance;
    
    for(iFt = 0; iFt < TUNNEL_FEATURE_NUMBER; iFt++)
    {
      /* temporary store the not normalized "average" */
      pAvg->frame_luminances[iFt] = ((pAvg->frame_luminances[iFt] * pAvg->frame_distance) - (pNewFeat->frame_luminances[iFt] * pNewFeat->frame_distance));
    }

    /* flush old data */
    (void)memset((void*)pNewFeat->frame_luminances, 0, sizeof(pNewFeat->frame_luminances));
    pNewFeat->frame_distance = 0.0f;
    
    pNewFeat->frame_luminances[TNL_ALL] =
    (
      pHLASubImage->SubImage_lux[0][0] + pHLASubImage->SubImage_lux[0][1] + pHLASubImage->SubImage_lux[0][2] + pHLASubImage->SubImage_lux[0][3] + pHLASubImage->SubImage_lux[0][4] + 
      pHLASubImage->SubImage_lux[1][0] + pHLASubImage->SubImage_lux[1][1] + pHLASubImage->SubImage_lux[1][2] + pHLASubImage->SubImage_lux[1][3] + pHLASubImage->SubImage_lux[1][4] + 
      pHLASubImage->SubImage_lux[2][0] + pHLASubImage->SubImage_lux[2][1] + pHLASubImage->SubImage_lux[2][2] + pHLASubImage->SubImage_lux[2][3] + pHLASubImage->SubImage_lux[2][4] + 
      pHLASubImage->SubImage_lux[3][0] + pHLASubImage->SubImage_lux[3][1] + pHLASubImage->SubImage_lux[3][2] + pHLASubImage->SubImage_lux[3][3] + pHLASubImage->SubImage_lux[3][4] + 
      pHLASubImage->SubImage_lux[4][0] + pHLASubImage->SubImage_lux[4][1] + pHLASubImage->SubImage_lux[4][2] + pHLASubImage->SubImage_lux[4][3] + pHLASubImage->SubImage_lux[4][4] 
    ) * 0.04f;

#if (TUNNEL_FEATURES_NEXT_GEN == SWITCH_ON)
    /* fill with new data */
    /*  lum[0]            lum[1-5]          lum[6-9]      <- all luminance values will be averaged
      |0 0 0 0 0|       |4       5|       |8 8 8 8 8|     
      |0 0 0 0 0|       |4 2   3 5|       |  6 6 6  |     lum[0]    lum[1]    lum[2,3,6,7]    lum[4,5,8,9]
      |0 0 0 0 0|       |4 2 1 3 5|       |    1    |     ------    ------    ------------    ------------
      |0 0 0 0 0|       |4 2   3 5|       |  7 7 7  |       25         1            3               5     
      |0 0 0 0 0|       |4       5|       |9 9 9 9 9|     
    */

    /* The next generation of grouped subimages */
    pNewFeat->frame_luminances[TNL_GROUND]  =  pHLASubImage->SubImage_lux[2][2];
    pNewFeat->frame_luminances[TNL_LEFT]    = (pHLASubImage->SubImage_lux[1][1] + pHLASubImage->SubImage_lux[2][1] + pHLASubImage->SubImage_lux[3][1]) * div3;
    pNewFeat->frame_luminances[TNL_RIGHT]   = (pHLASubImage->SubImage_lux[1][3] + pHLASubImage->SubImage_lux[2][3] + pHLASubImage->SubImage_lux[3][3]) * div3;
    pNewFeat->frame_luminances[TNL_SKY]     = (pHLASubImage->SubImage_lux[0][0] + pHLASubImage->SubImage_lux[1][0] + pHLASubImage->SubImage_lux[2][0] + pHLASubImage->SubImage_lux[3][0] + pHLASubImage->SubImage_lux[4][0]) * 0.2f;
    pNewFeat->frame_luminances[TNL_CEILING] = (pHLASubImage->SubImage_lux[0][4] + pHLASubImage->SubImage_lux[1][4] + pHLASubImage->SubImage_lux[2][4] + pHLASubImage->SubImage_lux[3][4] + pHLASubImage->SubImage_lux[4][4]) * 0.2f;
    pNewFeat->frame_luminances[TNL_CENTER]  = (pHLASubImage->SubImage_lux[1][1] + pHLASubImage->SubImage_lux[1][2] + pHLASubImage->SubImage_lux[1][3]) * div3;
    pNewFeat->frame_luminances[TNL_RING]    = (pHLASubImage->SubImage_lux[3][1] + pHLASubImage->SubImage_lux[3][2] + pHLASubImage->SubImage_lux[3][3]) * div3;
    pNewFeat->frame_luminances[TNL_MIDDLE]  = (pHLASubImage->SubImage_lux[0][0] + pHLASubImage->SubImage_lux[0][1] + pHLASubImage->SubImage_lux[0][2] + pHLASubImage->SubImage_lux[0][3] + pHLASubImage->SubImage_lux[0][4]) * 0.2f;
    pNewFeat->frame_luminances[9] = (pHLASubImage->SubImage_lux[4][0] + pHLASubImage->SubImage_lux[4][1] + pHLASubImage->SubImage_lux[4][2] + pHLASubImage->SubImage_lux[4][3] + pHLASubImage->SubImage_lux[4][4]) * 0.2f;
#else
    /* The old version of grouped subimages */
    /*  
    o o o o o
    o o o o o   1 
    o o o o o * -
    o o o o o   5
    1 1 1 1 1
    average of bottom of image */
    pNewFeat->frame_luminances[TNL_GROUND] =
      (pHLASubImage->SubImage_lux[4][0] + pHLASubImage->SubImage_lux[4][1] + pHLASubImage->SubImage_lux[4][2] + pHLASubImage->SubImage_lux[4][3] + pHLASubImage->SubImage_lux[4][4]) * 0.2f;

    /*
    1 o o o o
    1 o o o o   1
    1 o o o o * -
    1 o o o o   4
    o o o o o
    average of left side of image without bottom */
    pNewFeat->frame_luminances[TNL_LEFT] =
      (pHLASubImage->SubImage_lux[0][0] +
       pHLASubImage->SubImage_lux[1][0] +
       pHLASubImage->SubImage_lux[2][0] +
       pHLASubImage->SubImage_lux[3][0]) * 0.25f;

    /*
    o o o o 1
    o o o o 1   1
    o o o o 1 * -
    o o o o 1   4
    o o o o o
    average of right side of image without bottom */
    pNewFeat->frame_luminances[TNL_RIGHT] =
      (pHLASubImage->SubImage_lux[0][4] +
       pHLASubImage->SubImage_lux[1][4] +
       pHLASubImage->SubImage_lux[2][4] +
       pHLASubImage->SubImage_lux[3][4]) * 0.25f;
      
    /*
    1 1 1 1 1
    o o o o o   1
    o o o o o * -
    o o o o o   5
    o o o o o
    average of top of image */
    pNewFeat->frame_luminances[TNL_SKY] = 
    (pHLASubImage->SubImage_lux[0][0] + pHLASubImage->SubImage_lux[0][1] + pHLASubImage->SubImage_lux[0][2] + pHLASubImage->SubImage_lux[0][3] + pHLASubImage->SubImage_lux[0][4]) * 0.2f;

    /*
    o 1 1 1 o
    o o o o o   1
    o o o o o * -
    o o o o o   3
    o o o o o
    average of middle top of image */
    pNewFeat->frame_luminances[TNL_CEILING] = (pHLASubImage->SubImage_lux[0][1] + pHLASubImage->SubImage_lux[0][2] + pHLASubImage->SubImage_lux[0][3]) / 3.0f;
      
    /*
    o o o o o 
    o o 1 o o   1
    o o 1 o o * -
    o o o o o   2
    o o o o o
    average of center of image */
    pNewFeat->frame_luminances[TNL_CENTER] = 
    (pHLASubImage->SubImage_lux[1][2] +
     pHLASubImage->SubImage_lux[2][2]) * 0.5f;
    
    /*
    o 1 1 1 o
    o 1 o 1 o    1
    o 1 o 1 o * --
    o 1 1 1 o   10
    o o o o o
    average of ring around center of image */
    pNewFeat->frame_luminances[TNL_RING] = 
    (pHLASubImage->SubImage_lux[0][1] + pHLASubImage->SubImage_lux[0][2] + pHLASubImage->SubImage_lux[0][3] +
     pHLASubImage->SubImage_lux[1][1] +                                    pHLASubImage->SubImage_lux[1][3] +
     pHLASubImage->SubImage_lux[2][1] +                                    pHLASubImage->SubImage_lux[2][3] +
     pHLASubImage->SubImage_lux[3][1] + pHLASubImage->SubImage_lux[3][2] + pHLASubImage->SubImage_lux[3][3]) * 0.1f;
        
    /*
    o 1 1 1 o
    o 1 1 1 o    1
    o 1 1 1 o * --
    o 1 1 1 o   12
    o o o o o
    average of middle of image */
    pNewFeat->frame_luminances[TNL_MIDDLE] =
      (pHLASubImage->SubImage_lux[0][1] + pHLASubImage->SubImage_lux[0][2] + pHLASubImage->SubImage_lux[0][3] +
       pHLASubImage->SubImage_lux[1][1] + pHLASubImage->SubImage_lux[1][2] + pHLASubImage->SubImage_lux[1][3] +
       pHLASubImage->SubImage_lux[2][1] + pHLASubImage->SubImage_lux[2][2] + pHLASubImage->SubImage_lux[2][3] +
       pHLASubImage->SubImage_lux[3][1] + pHLASubImage->SubImage_lux[3][2] + pHLASubImage->SubImage_lux[3][3]) / 12.0f;
#endif

    /* update distance within frame */
    pNewFeat->frame_distance = frame_dist;

    /* update pStart */
    pOut->pFeaturesStart = pNewFeat;

    temp_dist = temp_dist + pNewFeat->frame_distance;

    /* temp_dist is at least pNewFeat->frame_distance therefore division should be safe */
    temp_dist_inv = 1 / temp_dist;
    
    /* update average */
    for (iFt = 0; iFt < TUNNEL_FEATURE_NUMBER; iFt++)
    {
      /* temporary store the not normalized "average" */
      pAvg->frame_luminances[iFt] = (pAvg->frame_luminances[iFt] + (pNewFeat->frame_luminances[iFt] * pNewFeat->frame_distance)) * temp_dist_inv;
    }

    pAvg->frame_distance = temp_dist;
    
    /* just to make sure */
    pAvg->pNext = 0;
  }
}

/* **************************************************************************** 
  Functionname:     HLATunnelDetectionDay                                */ /*!  
  Description:      New tunnel decision algorithm (day time)

  @param[in]        -
  @return           -
  @pre              -
  @post             -
  @author           Alexander Manz
**************************************************************************** */
static void HLATunnelDecisionDay( const RTE_HLAR_ParameterTunnel_t* pParams,
                                        HLATunnelOutput_t*          pHLATunnelOutput,
                                        RTE_HLAR_Tunnel*            pTunnelResult
                                )
{
  /* TUNNEL DETECTION STATE MACHINE */
  /* start only if filter is properly filled -> we have covered app. 10 m distance */
  if(pHLATunnelOutput->filteredFeat.frame_distance >= DAY_MIN_DIST_COVERED)
  {
    /* use darker average of ring around center of image or middle of image */
    float32 temp_luminance = (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RING] <= pHLATunnelOutput->filteredFeat.frame_luminances[TNL_MIDDLE]) ? pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RING] : pHLATunnelOutput->filteredFeat.frame_luminances[TNL_MIDDLE];

    switch(pHLATunnelOutput->tunnelState)
    {
    case TSM_NO_TUNNEL:
      if(   (temp_luminance <= pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL])    /* intensity of ring around center of image below intensity of whole image */
         && (temp_luminance <= pHLATunnelOutput->filteredFeat.frame_luminances[TNL_GROUND]) /* intensity of ring around center of image below intensity of lower part */
        )
      {
        /* store luminance value of whole image at entry point */
        pHLATunnelOutput->threshValue[0] = pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL];
        /* store luminance value of center of image at entry point */
        pHLATunnelOutput->threshValue[1] = temp_luminance;
        /* move to next step of state machine */
        pHLATunnelOutput->tunnelState = TSM_ENTRY;
        /* do not show upfront flag */
        /* *pTunnelResult = RTE_HLAR_TUNNEL_UPFRONT; */
        *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;
      }
      pHLATunnelOutput->detected_dist = 0.0F;
      /* possible else case here? */
      break;
    case TSM_ENTRY:
      /* if the entry condition is satisfied for a certain distance, the tunnel is detected */
      if(   (temp_luminance <= pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL])    /* intensity of ring around center of image below intensity of whole image */
          && (temp_luminance <= pHLATunnelOutput->filteredFeat.frame_luminances[TNL_GROUND]) /* intensity of ring around center of image below intensity of lower part */
        )
      {
        /* entry condition is still satisfied and bottom luminance is dropping below threshold*/
        if(   (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_GROUND]  < (pParams->EntryThreshHigh * pHLATunnelOutput->threshValue[1]) ) /* intensity of lower part below threshold[5]*/
            /*&& (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CEILING] < (pParams->EntryThreshLow  * pHLATunnelOutput->threshValue[1]) )*/ /* intensity of upper part below threshold[5]*/
            && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_SKY] < (pParams->EntryThreshLow  * pHLATunnelOutput->threshValue[1]) )
            && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CENTER]  < pHLATunnelOutput->threshValue[0])                               /* inner areas are below entry threshold -> no short bridges etc */
            && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RING]    < pHLATunnelOutput->threshValue[0])                               /* probably remove innermost area due to problems with straight tunnel */
            && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL]     < 200.0f) /* 200 Lux as threshold between real tunnel and false tunnel ? */
            && (pHLATunnelOutput->detected_dist > pParams->EntryDistanceMin)                                                                   /* detected over a certain distance */
            /* difference between left and right side of image is not that big -> against curve driving */
            /*&& ( (abs(pHLATunnelOutput->filteredFeat.frame_luminances[TNL_LEFT] - pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RIGHT])
                  / (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_LEFT] + pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RIGHT])
                ) <= (1.0f - pParams->EntryThreshLow) )*/
          )
        {
          /* state machine is now sure */
          pHLATunnelOutput->tunnelState = TSM_INSIDE_TUNNEL;
          *pTunnelResult = RTE_HLAR_TUNNEL_INSIDE;
          /* initialize threshold values for leaving the tunnel */
          pHLATunnelOutput->threshValue[0] = 0xFFFF;
          pHLATunnelOutput->threshValue[2] = pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RING];
          /* reset distance */
          pHLATunnelOutput->detected_dist = 0.0F;
          /* reset threshold value */
          pHLATunnelOutput->threshValue[1] = 0.0F;
        }
        if(pHLATunnelOutput->detected_dist > pParams->EntryDistanceMax)
        {
          /* tunnel was not detected after a certain distance, so reset to NO_TUNNEL */
          pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;
          *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;
          /* reset distance */
          pHLATunnelOutput->detected_dist = 0.0F;
          /* reset threshold values */
          pHLATunnelOutput->threshValue[0] = 0.0F;
          pHLATunnelOutput->threshValue[1] = 0.0F;
        }
      }
      else
      {
        /* entry condition is not satisfied anymore -> false positive tunnel detection, reset to NO_TUNNEL state */
        pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;
        *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;
        /* reset distance */
        pHLATunnelOutput->detected_dist = 0.0F;
        /* reset threshold values */
        pHLATunnelOutput->threshValue[0] = 0.0F;
        pHLATunnelOutput->threshValue[1] = 0.0F;
      }
      break;
    case TSM_INSIDE_TUNNEL:
      if(   (   (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CENTER] > pHLATunnelOutput->filteredFeat.frame_luminances[TNL_MIDDLE])  /*     intensity of center of view is larger than intensity of middle part */
              || (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RING]   > pHLATunnelOutput->filteredFeat.frame_luminances[TNL_MIDDLE]) /*  or intensity of ring around center is larger than intensity of middle part */
            ) 
          && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_MIDDLE] > pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL])         /* and intensity of middle of image is larger than intensity of whole image */
          && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL]    > (pParams->ExitThreshHigh * pHLATunnelOutput->threshValue[0]))     /* and intensity of whole image is larger than threshold times factor */
        )
      {
        if(pHLATunnelOutput->detected_dist > pParams->ExitDistanceMin) /* detected over a certain distance */
        {
          /* set tunnel state to EXIT */
          pHLATunnelOutput->tunnelState = TSM_EXIT;
          /* reset distance */
          pHLATunnelOutput->detected_dist = 0.0F;
          /* store time since exit ? */
          /* reset threshold value */
          pHLATunnelOutput->threshValue[0] = 0.0F;
          /* reset escape mode */
          bCityEscapeMode = b_FALSE;
        }
      }
      else if(   (bCityEscapeMode == b_TRUE)        /* bCityEscapeMode enabled */
              && (eCity == RTE_HLAR_CITY_NOT_DTCD) /* city is not detected anymore */
              )
      {
        /* emergency escape if bCityEscapeMode is on and no streetlights are visible */
        if(pHLATunnelOutput->detected_dist > pParams->ExitDistanceMin) /* detected over a certain distance */
        {
          /* set tunnel state to NO_TUNNEL */
          pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;
          *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;
          /* reset distance */
          pHLATunnelOutput->detected_dist = 0.0F;
          /* reset threshold value */
          pHLATunnelOutput->threshValue[2] = 0.0F;
          /* reset escape mode */
          bCityEscapeMode = b_FALSE;
        }
      }
      else
      {
        /* reset distance */
        pHLATunnelOutput->detected_dist = 0.0F;
        /* adapt threshold value to current overall luminance value */
        if (pHLATunnelOutput->threshValue[0] > pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL])
        {
          pHLATunnelOutput->threshValue[0] = pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL];
        }
        /* check if bCityEscapeMode is available via city detection */
        if(   (bCityEscapeMode == b_FALSE)
            && (eCity == RTE_HLAR_CITY_DTCD)
          )
        {
          /* turn on bCityEscapeMode */
          bCityEscapeMode = b_TRUE;
        }
      }
      break;
    case TSM_EXIT:
      if(   ( ((pHLATunnelOutput->filteredFeat.frame_luminances[TNL_LEFT] + pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RIGHT]) * 0.5f
               ) >= pHLATunnelOutput->threshValue[2]
             ) /* intensity of both sides is higher than threshold [2] */
         && (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_SKY] >= pHLATunnelOutput->threshValue[2])
        )
      {
        if(pHLATunnelOutput->detected_dist > pParams->ExitDistanceMin)
        {
          /* set tunnel state to NO_TUNNEL */
          pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;
          *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;
          /* reset distance */
          pHLATunnelOutput->detected_dist = 0.0F;
          /* reset threshold value */
          pHLATunnelOutput->threshValue[2] = 0.0F;
          /* reset escape mode */
          bCityEscapeMode = b_FALSE;
        }
        /* else if (pHLATunnelOutput->detected_dist) */
      }
      else if(   (bCityEscapeMode == b_TRUE)
              && (eCity == RTE_HLAR_CITY_NOT_DTCD)
              )
      {
        /* fast escape mode */
        if(pHLATunnelOutput->detected_dist > pParams->ExitDistanceMin)
        {
          /* set tunnel state to NO_TUNNEL */
          pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;
          *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;
          /* reset distance */
          pHLATunnelOutput->detected_dist = 0.0F;
          /* reset threshold value */
          pHLATunnelOutput->threshValue[2] = 0.0F;
          /* reset escape mode */
          bCityEscapeMode = b_FALSE;
        }
      }
      else
      {
        /* reset detected distance */
        pHLATunnelOutput->detected_dist = 0.0F;

        /* check if bCityEscapeMode is available via city detection */
        if(   (bCityEscapeMode == b_FALSE)
            && (eCity == RTE_HLAR_CITY_DTCD)
          )
        {
          /* turn on bCityEscapeMode */
          bCityEscapeMode = b_TRUE;
        }
      }
      break;
    default:
      /* ERROR STATE                       */
      /* this case should never be reached */
      pHLATunnelOutput->detected_dist = 0.0f;
      break;
    }
  }
  /* increase the detected distance value */
  pHLATunnelOutput->detected_dist += frame_dist;
}


/* **************************************************************************** 
  Functionname:     HLATunnelDetectionNight                              */ /*!  
  Description:      New tunnel decision algorithm (night time)


  @param[in]        -
  @return           -
  @pre              -
  @post             -
  @author           Alexander Manz
**************************************************************************** */
/* J.Häfer unused Parameter in function will be used in #if 0 */
/* PRQA S 3206 5*/ 
static void HLATunnelDecisionNight(       HLATrack_t*                 pTrackStart,
                                    const RTE_HLAR_ParameterTunnel_t* pParams,           
                                          HLATunnelOutput_t*          pHLATunnelOutput,  
                                          RTE_HLAR_Tunnel*            pTunnelResult
                                  )
{
  /* rudimentary implemented */
  /* TODO AlexM: implement tunnel detection at night -> try not to collide with city detection */
  HLATrack_t* pTrack;
  uint8 tunnelSLcount = 0;

  /*(void) pParams;*/

  /* check if there are tracks classified as tunnel street lamps */
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    if(   (pTrack->statusAnalysisMisc.isSceneStreetLampTunnel == 1)
       && (pTrack->statusAnalysisMisc.isSceneStreetLampIcon   != 1)
      )
    {
      /* increase number of tunnel street lamps */
      tunnelSLcount++;
    }
    pTrack = pTrack->next;
  }

  /* incredibly small tunnel state machine */
  if(   (   (   (tunnelSLcount > 4) /* need 5 tunnel street lamps when not in tunnel */
             && (*pTunnelResult == RTE_HLAR_TUNNEL_NOT_DTCD)
            )
         || (   (tunnelSLcount > 2) /* need 3 tunnel street lamps while in tunnel */
             && (*pTunnelResult == RTE_HLAR_TUNNEL_INSIDE)
            )
        )
     && (eCity == RTE_HLAR_CITY_DTCD) /* while city detection has reported a city */
    )
  {
    /* *pTunnelResult = RTE_HLAR_TUNNEL_INSIDE; */
    pHLATunnelOutput->tunnelState = TSM_INSIDE_TUNNEL;
    /* reset stay in tunnel hysteresis */
    nightHyst = 3;
  }
  else
  {
    /* count down to survive a 3 framed lack of tunnel street lamps */
    if(nightHyst > 0)
    {
      nightHyst--;
    }
    else
    {
      /* no tunnel */
      /* *pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD; */
      pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;
    }
  }

#if 0
  /* First idea:                                                                                        */
  /*  - try reverse version of daylight detection:                                                      */
  /*    -> try to find a bright hole in the middle of the averaged subimages and count it as entry      */
  /*    -> if ceiling and sides follow the increase in ambient illumination, count it as inside tunnel  */
  /*    -> try to find a dark hole in the middle of the averaged subimages and count it as exit         */
  /*    -> if walls and floor follow the decrease in ambient illumination, count it as left tunnel      */
  /*  - if this fails, try something with tunnel lights and city detection                              */

  /* check if there was motion between frames */
  if(pHLATunnelOutput->frame_dist > 0)
  {
    /* TUNNEL DETECTION STATE MACHINE */
    /* start only if filter is properly filled -> we have covered app. 10 m distance */
    /* TODO AlexM: magic number removal */
    if(pHLATunnelOutput->filteredFeat.frame_distance >= 10.0f)
    {
      /* temp_luminance1 = 1.25 * upper part of subimages:  */
      /*          | 1 1 1 1 1 |                                                           */
      /*          | 1 1 1 1 1 |    1     5   / 1            3              1         \    */
      /*   1.25 * | 1 1 1 1 1 | * --  =  - * | - * LEFT  +  - * MIDDLE  +  - * RIGHT |    */
      /*          | 1 1 1 1 1 |   20     4   \ 5            5              5         /    */
      /*          | o o o o o |                                                           */

      float32 temp_luminance1 = (  (0.25f * pHLATunnelOutput->filteredFeat.frame_luminances[TNL_LEFT])
                                 + (0.75f * pHLATunnelOutput->filteredFeat.frame_luminances[TNL_MIDDLE])
                                 + (0.25f * pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RIGHT]));

      switch(pHLATunnelOutput->tunnelState)
      {
      case TSM_NO_TUNNEL:
        /* entry condition */
        if(pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CENTER] > temp_luminance1 )
        {
          /* store luminance value of whole image at entry point */
          pHLATunnelOutput->threshValue[0] = pHLATunnelOutput->filteredFeat.frame_luminances[TNL_ALL];
          /* store luminance value of center of image at entry point */
          pHLATunnelOutput->threshValue[1] = pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CENTER];
          /* move to next step of state machine */
          pHLATunnelOutput->tunnelState = TSM_ENTRY;
          /* do not show upfront flag */
          /**pTunnelResult = RTE_HLAR_TUNNEL_UPFRONT;*/
          /**pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;*/
        }
        break;
      case TSM_ENTRY:
        /* first entry condition still satisfied? */
        if(pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CENTER] > temp_luminance1 )
        {
          /* temp_luminance2 = */
          /*  1 1 1 1 1        */
          /*  1 o o o 1    1   */
          /*  1 o o o 1 * --   */
          /*  1 o o o 1   11   */
          /*  o o o o o        */

          float32 temp_luminance2 =  (  (4.0f * (pHLATunnelOutput->filteredFeat.frame_luminances[TNL_LEFT] + pHLATunnelOutput->filteredFeat.frame_luminances[TNL_RIGHT]))
                                      + (3.0f *  pHLATunnelOutput->filteredFeat.frame_luminances[TNL_CEILING])
                                     ) / 11.0f;

          /* code inside condition here */
          if(   (temp_luminance2 > pHLATunnelOutput->threshValue[0])
             && (pHLATunnelOutput->detected_dist > pParams->EntryDistanceMin)
            )
          {
            pHLATunnelOutput->detected_dist   = 0.0f;

            pHLATunnelOutput->tunnelState = TSM_INSIDE_TUNNEL;
            /**pTunnelResult = RTE_HLAR_TUNNEL_INSIDE;*/
          }
          /* if we have been too long in detection state, reset and check for updated threshold */
          if(pHLATunnelOutput->detected_dist > 30.0f)
          {
            pHLATunnelOutput->threshValue[0]  = 0.0f;
            pHLATunnelOutput->threshValue[1]  = 0.0f;
            pHLATunnelOutput->detected_dist   = 0.0f;
            pHLATunnelOutput->tunnelState     = TSM_NO_TUNNEL;
            /**pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;*/
          }
        }
        else
        {
          /* entry condition is not satisfied anymore */
          pHLATunnelOutput->threshValue[0]  = 0.0f;
          pHLATunnelOutput->threshValue[1]  = 0.0f;
          pHLATunnelOutput->detected_dist   = 0.0f;
          pHLATunnelOutput->tunnelState     = TSM_NO_TUNNEL;
          /**pTunnelResult = RTE_HLAR_TUNNEL_NOT_DTCD;*/
        }
        break;
      case TSM_INSIDE_TUNNEL:
        if(pHLATunnelOutput->detected_dist > 600.0f)
        {
          pHLATunnelOutput->tunnelState     = TSM_NO_TUNNEL;
        }
        break;
      case TSM_EXIT:
        break;
      }
    }
  }
  pHLATunnelOutput->detected_dist += pHLATunnelOutput->frame_dist;
  /* TODO: remove hardoceded external tunnel state value */
#endif
  
}


/* **************************************************************************** 
  Functionname:     HLATunnelDetectionMain                               */ /*!  
  Description:      New tunnel detection algorithm


  @param[in]        -
  @return           -
  @pre              -
  @post             -
  @author           Cristian Craciunas
                    Alexander Manz
**************************************************************************** */
void HLATunnelDetectionMain(const HLATunnelInput_t*           pTunnelInput,
                            const RTE_HLAR_ParameterTunnel_t* pHlaTunnelDetectionParams,
                                  HLATunnelOutput_t*          pHLATunnelOutput,
                                  RTE_HLAR_Tunnel*            pEnumTunnel
                           )
{
  static eTunnelDetectionType_t eRightDetMode;
  static eTunnelDetectionType_t eWrongDetMode;
  eCity = pTunnelInput->eCityState;

  /* distance covered in last frame */
  /* dDistFwd_m is coming from hlaCamData and is in case of standstill and backward motion 0 */
  frame_dist = pTunnelInput->dDistFwd_m;

  /* decide what kind of detection is needed, only if outside of a tunnel */
  if(*pEnumTunnel == RTE_HLAR_TUNNEL_NOT_DTCD)
  {
    switch(pTunnelInput->eBrightnessState)
    {
    case RTE_HLAR_BRT_NIGHT:   /*   5u */
    case RTE_HLAR_BRT_TWLGT_3: /*   4u */
      eRightDetMode = TDT_NIGHT;
      eWrongDetMode = TDT_DAY;
      break;
    case RTE_HLAR_BRT_TWLGT_2: /*   3u */
    case RTE_HLAR_BRT_TWLGT_1: /*   2u */
    case RTE_HLAR_BRT_DAY:     /*   1u */
    default:
    /* also covering the cases         */
    /* case RTE_HLAR_BRT_INVALID: 255u */
    /* case RTE_HLAR_BRT_UNKNOWN:   0u */
      eRightDetMode = TDT_DAY;
      eWrongDetMode = TDT_NIGHT;
      break;
    }

    if(pHLATunnelOutput->eTunnelDetectionType == TDT_UNKNOWN)
    {
      /* do a fast decision at the beginning of the tunnel detection */
      pHLATunnelOutput->eTunnelDetectionType = eRightDetMode;
    }
    else if(pHLATunnelOutput->eTunnelDetectionType == eWrongDetMode)
    {
      /* wait until hysteresisDist is covered to be sure */
      change_dist += frame_dist;

      if(change_dist >= pHlaTunnelDetectionParams->DetectionTypeDistance)
      {
        /* distance was covered and no change in brightness happened -> change detection type */
        pHLATunnelOutput->eTunnelDetectionType = eRightDetMode;
        /* TODO AlexM: reset tunnelData ? */
        /* HLAResetTunnelData(pHLATunnelOutput); */
        /* reset hysteresis distance */
        change_dist = 0.0f;
      }
    }
    else
    {
      /* reset hysteresis distance */
      change_dist = 0.0f;
    }
  }

  /* check if there was motion between two frames, if not do not check for tunnel */
  if(frame_dist > 0)
  {
    /* Calculation of tunnel detection values independent of night/day flag */
    HLATunnelCalculation( pTunnelInput->pHLASubImage,
                          pHLATunnelOutput
                        );

    /* based on night/day flag call the appropiate function for tunnel detection */
    if(pHLATunnelOutput->eTunnelDetectionType == TDT_NIGHT)
    {
      HLATunnelDecisionNight( pTunnelInput->pTrackStart,
                              pHlaTunnelDetectionParams,
                              pHLATunnelOutput,
                              pEnumTunnel
                            );
    }
    else if(pHLATunnelOutput->eTunnelDetectionType == TDT_DAY)
    {
      HLATunnelDecisionDay( pHlaTunnelDetectionParams,
                            pHLATunnelOutput,
                            pEnumTunnel
                          );
    }
    else
    {
      /* if this path is reached something went horribly wrong */
      /* TODO AlexM: possibly try to reset tunnel detection here? */
    }
  }
}


/* ****************************************************************************
  Functionname:     HLATunnelDetectionInit                               */ /*!
  Description:      init all internal tunnel variables


  @param[in]        -
  @return           -
  @pre              -
  @post             -
  @author           Alexander Manz
**************************************************************************** */
void HLATunnelDetectionInit(HLATunnelData_t*    pHLATunnelData,
                            HLATunnelOutput_t*  pHLATunnelOutput,
                            RTE_HLAR_Tunnel*    p_Out
                           )
{
  uint8 i;
  HLATunnelFeatures_t* pTF;
  HLATunnelFeatures_t* pTFnext;

  /* ********************* initialize pHLATunnelData ********************* */
  (void)memset((void*)pHLATunnelData, 0, sizeof(HLATunnelData_t));

  /* initialize pHLATunnelData->tunnel_feature_buffer */
  (void)memset((void*)pHLATunnelData->tunnel_feature_buffer, 0, sizeof(pHLATunnelData->tunnel_feature_buffer));

  /* initialize flag to indicate buffer is ready */
  pHLATunnelData->bBufferReady = b_FALSE;

  /* initialize linking of features */
  for (i = 0; i < (TUNNEL_FEATURE_LENGTH - 1); i++)
  {
    /* avoid complaining of QAC with this step */
    pTF     = &(pHLATunnelData->tunnel_feature_buffer[i]);
    pTFnext = &(pHLATunnelData->tunnel_feature_buffer[i + 1]);
    pTF->pNext = pTFnext;
    /* pTF++; */
    /* pTFnext++; */
  }
  /* close ring */
  pTF->pNext = &(pHLATunnelData->tunnel_feature_buffer[0]);

  /* ********************************************************************* */
     
  /* ******************** initialize pHLATunnelOutput ******************** */
  (void)memset((void*)pHLATunnelOutput, 0, sizeof(HLATunnelOutput_t));

  /* just to be sure */
  /* (void)memset((void*)pHLATunnelOutput->filteredFeat, 0, sizeof(pHLATunnelOutput->filteredFeat)); */

  /* init array to store the various tunnel features over the time*/
  /* (void)memset((void*)pHLATunnelOutput->tunnelFeat, 0, sizeof(pHLATunnelOutput->tunnelFeat)); */

  /* init array to store the lux values at tunnel entry*/
  (void)memset((void*)pHLATunnelOutput->threshValue, 0, sizeof(pHLATunnelOutput->threshValue));

  /* point pFeaturesStart to first element of tunnel_feature_buffer */
  pHLATunnelOutput->pFeaturesStart = &(pHLATunnelData->tunnel_feature_buffer[0]);

  /* measured distance for tunnel detection */
  pHLATunnelOutput->detected_dist = 0.0F;

  /* state machine for tunnel status */
  pHLATunnelOutput->tunnelState = TSM_NO_TUNNEL;

  /* internal detection type (day|night) */
  pHLATunnelOutput->eTunnelDetectionType = TDT_UNKNOWN;
  /* ********************************************************************* */
     
  /* *************************** internal data *************************** */
  /* set distance to 0 */
  change_dist = 0.0f;

  /* city escape mode */
  bCityEscapeMode = b_FALSE;

  /* init city backup solution */
  eCity = RTE_HLAR_CITY_UNKNOWN;

  /* set output to idle */
  *p_Out = RTE_HLAR_TUNNEL_NOT_DTCD;
  /* ********************************************************************* */
}
