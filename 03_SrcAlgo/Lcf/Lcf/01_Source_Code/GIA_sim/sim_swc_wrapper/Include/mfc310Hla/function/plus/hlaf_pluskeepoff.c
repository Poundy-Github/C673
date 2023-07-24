/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_pluskeepoff.c

  DESCRIPTION:            HLA plus keep off functions.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_pluskeepoff.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:28CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:09CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:48CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.37 2014/03/26 11:27:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:40 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.36 2014/03/25 19:11:52CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:52 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.35 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_pluskeepoff.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_pluskeepoff.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.34 2014/03/19 16:31:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:19 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.33 2014/03/04 16:52:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:28 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.32 2014/02/20 08:12:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC critical warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 20, 2014 8:12:56 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.31 2014/02/06 16:01:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:30 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.30 2013/05/23 10:31:03CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed PC-LINT errors
  CHANGE:                 --- Added comments ---  uidv7867 [May 23, 2013 10:31:04 AM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.29 2013/04/25 11:02:58CEST Brunn, Marcus (brunnm) 
  CHANGE:                 implemented hla plus configuration switch 
  CHANGE:                 implemented TurnOffLeft_OncOnly, TurnOffLeft_LeftOnly, KeepOffLeft_LeftOnly and AsymmetricMode
  CHANGE:                 --- Added comments ---  brunnm [Apr 25, 2013 11:03:02 AM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.28 2013/04/11 16:21:01CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:21:01 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.27 2013/03/11 16:13:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:34 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.26 2013/03/08 17:43:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:07 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.25 2013/03/08 10:30:32CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:35 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.24 2013/01/28 15:06:44CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eRedReflectorArea
  CHANGE:                 - HLA_t_eHighwayLatPosState
  CHANGE:                 - HLA_t_eHighwayEgoMotionState
  CHANGE:                 - HLA_t_eHighwayOcclusionState
  CHANGE:                 --- Added comments ---  brunnm [Jan 28, 2013 3:06:44 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.23 2013/01/24 16:37:21CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:21 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.22 2013/01/23 17:57:39CET Brunn, Marcus (brunnm) 
  CHANGE:                 Converted enum to rte like type for
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 --- Added comments ---  brunnm [Jan 23, 2013 5:57:39 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.21 2013/01/18 07:46:03CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:03 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.20 2012/09/24 11:28:46CEST Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf plus: introduced road type depending turn on delay (partial HB -> full HB: highway = 5sec, country road = 1sec)
  CHANGE:                 --- Added comments ---  brunnm [Sep 24, 2012 11:28:48 AM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.19 2012/07/23 12:58:00CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:00 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.18 2012/07/18 07:51:47CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 7:51:47 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.17 2012/04/23 15:49:51CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGE:                 - delayed HB turn on after vehicles goes lost
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 3:49:52 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.16 2012/04/21 15:04:37CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:38 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.15 2012/03/23 11:36:14CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGE:                 time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 23, 2012 11:36:15 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.14 2012/03/15 16:25:12CET Brunn, Marcus (brunnm) 
  CHANGE:                 added new highway state: HLAR_HIGHWAY_EM_LOW_SPEED
  CHANGE:                 Revision 1.13 2012/03/14 08:55:30CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed one cycle HB on bug (England test drive, city entry, 29.02.2012 22:25)
  CHANGE:                 --- Added comments ---  brunnm [Mar 14, 2012 8:55:30 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.12 2012/03/12 08:01:28CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixes for England test drive:
  CHANGE:                 - fixed keep off PrecMinTimeInActRegion on highway
  CHANGE:                 --- Added comments ---  brunnm [Mar 12, 2012 8:01:28 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.11 2012/03/12 07:27:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed use of global variable (hlafPlusData)
  CHANGE:                 Revision 1.10 2012/02/27 18:04:15CET Brunn, Marcus (brunnm) 
  CHANGE:                 - used wiperstate instead of wiperstage
  CHANGE:                 - fixed light style decision after init
  CHANGE:                 --- Added comments ---  brunnm [Feb 27, 2012 6:04:15 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/02/23 16:42:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed some issues for left hand traffic
  CHANGE:                 - increased HB turn on delay when wiper is on stage 6
  CHANGE:                 - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGE:                 - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGE:                 Revision 1.8 2012/02/21 19:21:25CET Brunn, Marcus (brunnm) 
  CHANGE:                 - used ttb delay only for track lost in deact region
  CHANGE:                 - oncoming covered by preceding car (removed motion criteria)
  CHANGE:                 - keep off bugfix: preceding car detected for min time in activation region
  CHANGE:                 --- Added comments ---  brunnm [Feb 21, 2012 7:21:25 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/02/20 16:54:42CET Brunn, Marcus (brunnm) 
  CHANGE:                 misra fixes
  CHANGE:                 Revision 1.6 2012/02/20 16:40:35CET Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf optimization in curvy roads
  CHANGE:                 --- Added comments ---  brunnm [Feb 20, 2012 4:40:35 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.5 2012/02/13 15:33:06CET Brunn, Marcus (brunnm) 
  CHANGE:                 - optimized HLAFDecisionTurnOnDelayTTB() for overtaking cars and passed oncoming vehicles 
  CHANGE:                 - HLAFDecisionRelevantVehicle2TurnOff(): check FOV
  CHANGE:                 Revision 1.4 2012/02/13 06:23:29CET Brunn, Marcus (brunnm) 
  CHANGE:                 used relevant traffic flag from extended object list
  CHANGE:                 --- Added comments ---  brunnm [Feb 13, 2012 6:23:30 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.3 2012/02/08 16:57:51CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed detection of relevant traffic
  CHANGE:                 - hla plus: fast HB on when oncoming traffic passed
  CHANGE:                 --- Added comments ---  brunnm [Feb 8, 2012 4:57:52 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.2 2012/02/01 15:28:30CET Brunn, Marcus (brunnm) 
  CHANGE:                 keep partial HB off when oncoming vehicle will leave FOV in "next seconds"
  CHANGE:                 --- Added comments ---  brunnm [Feb 1, 2012 3:28:30 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.1 2012/01/31 06:43:27CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_pluskeepoff.h"
#include "hlaf_decision.h"
#include "hlaf_defs.h"
#include "hlaf_plusdecision.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
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


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLAPlusKeepOffPart_TTDTurnOnDelay(const float32 dTime_s,    
                                              float32       *pTurnOnDelay_TTD,
                                              float32       minTimeToDeact,
                                              float32       TTD_Threshold,
                                              float32       TTD_MaxTurnOnDelay
                                            );
static void HLAPlusKeepOffPart_TTBTurnOnDelay( const eHLAplusHeadlamp_t           eHeadlamp,
                                              const float32                       dTime_s,
                                              const HLAF_t_RequiredInputs         *ps_In,
                                              const HLAFData_t                    *pFData,
                                              const HLAplusData_t                 *pPlusData,
                                              /* output */  
                                              float32                             *pTurnOnDelay_TTBOnc_s,
                                              float32                             *pTurnOnDelay_TTBPrec_s
                                             );
static void HLAPlusKeepOffPart_OncCoveredByPrec( /* input */
                                                 const HLA_t_ObjectList       *pObjList,
                                                 const HLAplusData_t          *pPlusData,
                                                 const HLAFTrafficStyleOut_t  *pTrafficStyle,
                                                 const float32                dTime_s,
                                                 /* output */
                                                 HLAplusKeepOffReasonPartHB_t *pKeepOffReason
                                               );
static void HLAPlusKeepOffPart_PotOncomDeact(float32           *pTurnOnDelay_PotOncomDeact_s,
                                             const float32     dTime_s,  
                                             uint8             potOncomDetected,
                                             eHLAplusHBState_t eHBState,
                                             boolean           b_HBOff2PartHBOn /* part HB will be switched on after this cycle ? */
                                            );
static void HLAPlusKeepOffPart_PotOncom(const HLA_t_ObjectList  *pObjList,
                                        const float32           dTime_s,
                                        float32                 *pTurnOnDelay_PotOncom,
                                        eHLAplusHBState_t       eHBState,
                                        boolean                 b_HBOff2PartHBOn /* part HB will be switched on after this cycle ? */
                                        );



static void HLAPlusKeepOffPart_PotOncom(const HLA_t_ObjectList        *pObjList, 
                                        const float32                 dTime_s,
                                        float32                       *pTurnOnDelay_PotOncom_s,
                                        eHLAplusHBState_t             eHBState,
                                        boolean                       b_HBOff2PartHBOn /* part HB will be switched on after this cycle ? */
                                       )
{
  boolean b_PotOncom;


  /* meaning of delay time:                                                */
  /* >   0.0f:     delay is running, keep off is active                    */
  /* ==  0.0f:     delay elapsed, keep off inactive                        */
  /* <   0.0f:     delay is activated but not running, keep off not active */
  /*               waits for a valid event                                 */

  /* decrement delay counter */
  if(*pTurnOnDelay_PotOncom_s > 0.0f)
  {
    (*pTurnOnDelay_PotOncom_s) = CML_f_Max(0.0f, ((*pTurnOnDelay_PotOncom_s) - dTime_s));
  }

  /* activate delay counter ? */
  if(    (eHBState != HLA_PLUS_HB_STATE_OFF)
    || (b_HBOff2PartHBOn == FALSE)
    )
  {
    *pTurnOnDelay_PotOncom_s = -1.0f; 
  }


  /* pot. oncoming detected anywhere ? */
  b_PotOncom = FALSE;
  {
    uint32 i;
 /* ~CodeReview ~ID:ea2688838698a2b7d81cd77cfe60febb ~Reviewer:PC2184\jongd ~Date:18-7-2012 ~Priority:2 ~Comment:Check whether pObjList->ui32_NumObjects <= RTE_HLAR_OBJECT_LIST_LENGTH. (Range checking) */
    for(i=0; i< pObjList->ui32_NumObjects; i++)
    {
      if(    (pObjList->as_Object[i].s_Status.isVehicleOncoming == 0)
          && (pObjList->as_Object[i].s_Status.isVehicleAhead == 0)
          && (pObjList->as_Object[i].s_Status.isPotentialVehicleOncoming1st == 1)
        )
      {
        b_PotOncom = TRUE;
      }
    }
  }

  /* set delay counter ? */
  if(    (eHBState == HLA_PLUS_HB_STATE_OFF)
      /* wants to switch part HB on after this cycle ? */
      && (b_HBOff2PartHBOn == TRUE)
      /* delay counter activated ? */
      && (*pTurnOnDelay_PotOncom_s < 0.0f)
      /* potential oncoming detected anywhere ? */
      && (b_PotOncom == TRUE)
    )
  {
    *pTurnOnDelay_PotOncom_s = 1.0f;
  }

}


static void HLAPlusKeepOffPart_PotOncomDeact( float32 *pTurnOnDelay_PotOncomDeact_s,
                                                   const float32 dTime_s,
                                                   uint8  potOncomDetected,
                                                   eHLAplusHBState_t eHBState,
                                                   boolean b_HBOff2PartHBOn /* part HB will be switched on after this cycle ? */
                                                   )
{
  /* meaning of delay time:                                                 */
  /* >   0:        delay is running, keep off is avctive                   */
  /* ==  0:        delay elapsed, keep off inactive                        */
  /* <   0:        delay is activated but not running, keep off not active */
  /*               waits for a valid event                                 */


  /* decrease delay counter */
  if (*pTurnOnDelay_PotOncomDeact_s > 0.0f)
  {
    (*pTurnOnDelay_PotOncomDeact_s) = CML_f_Max(0.0f, ((*pTurnOnDelay_PotOncomDeact_s)- dTime_s));
  }

  /* reset possibility for potential oncoming delay */
  if (    (eHBState != HLA_PLUS_HB_STATE_OFF)
    || (b_HBOff2PartHBOn == FALSE)
    )
  {
    *pTurnOnDelay_PotOncomDeact_s = -1.0f;
  }


  /* part HB will be switched on after this cycle */
  /* -> set fixed delay once a potential oncoming vehicle is detected */
  if (    (b_HBOff2PartHBOn == TRUE)
    && (eHBState == HLA_PLUS_HB_STATE_OFF)
    /* delay counter is activated ? */
    && ((*pTurnOnDelay_PotOncomDeact_s) < 0.0f)
    && (potOncomDetected == 1)
    )
  {
    *pTurnOnDelay_PotOncomDeact_s = 1.0f;
  }
}

static void HLAPlusKeepOffPart_TTDTurnOnDelay(const float32               dTime_s,
                                              float32                     *pTurnOnDelay_TTD,
                                              float32                     minTimeToDeact,
                                              float32                     TTD_Threshold,
                                              float32                     TTD_MaxTurnOnDelay
                                             )
{
  /* decrease delay counter */
  if (*pTurnOnDelay_TTD > 0.0f)
  {
    (*pTurnOnDelay_TTD) -= dTime_s;
  }
  else
  {
    (*pTurnOnDelay_TTD) = 0.0f;
  }

  /* set delay if an object will move from ACT to DEACT soon */
  if(    (minTimeToDeact < TTD_Threshold)
      && (minTimeToDeact > 0.0f)
    )
  {
    *pTurnOnDelay_TTD = CML_f_Min(minTimeToDeact, TTD_MaxTurnOnDelay);
  }
}


static void HLAPlusKeepOffPart_TTBTurnOnDelay( const eHLAplusHeadlamp_t            eHeadlamp,
                                               const float32                       dTime_s,
                                               const HLAF_t_RequiredInputs         *ps_In,
                                               const HLAFData_t                    *pFData,
                                               const HLAplusData_t                 *pPlusData,
                                               /* output */  
                                               float32                             *pTurnOnDelay_TTBOnc_s,
                                               float32                             *pTurnOnDelay_TTBPrec_s
                                             )
{
  float32 maxTTBOnc  = 0.0f;
  float32 maxTTBPrec = 0.0f;
  uint32  i;
  const HLA_t_ObjectList        *pObjList = ps_In->s_Sig.ps_ObjectList;
  const float32                 Speed = ps_In->s_Sig.ps_MotionState->f32_Speed;
  const RTE_HLAF_MotorwayState  eMotorwayState = pFData->DecisionOut.Motorway.eStateInt;
  const RTE_HLA_TrafficStyle    eTrafficStyle  = pFData->DecisionOut.TrafficStyle.eTrafficStyle;


  /* decrease delay counter */
  /* oncoming car */
  if(*pTurnOnDelay_TTBOnc_s > 0.0f)
  {
    (*pTurnOnDelay_TTBOnc_s) -= dTime_s;
  }
  else
  {
    *pTurnOnDelay_TTBOnc_s = 0.0f;
  }
  /* preceding car */
  if(*pTurnOnDelay_TTBPrec_s > 0.0f)
  {
    (*pTurnOnDelay_TTBPrec_s) -= dTime_s;
  }
  else
  {
    *pTurnOnDelay_TTBPrec_s = 0.0f;
  }

/* ~CodeReview ~ID:ea2688838698a2b7d81cd77cfe60febb ~Reviewer:PC2184\jongd ~Date:18-7-2012 ~Priority:2 ~Comment:Check whether pObjList->ui32_NumVehicles <= RTE_HLAR_OBJECT_LIST_LENGTH. (Range checking) */
  /* get max tbb from lost oncoming / preceding object */
  for(i=0; i<pObjList->ui32_NumVehicles; i++)
  {
    const HLA_t_Object    *pObj    = &pObjList->as_Object[i];
    const HLAplusObjectData_t *pObjExt_lt = &pPlusData->Object.Left.Obj[i];
    const HLAplusObjectData_t *pObjExt_rt = &pPlusData->Object.Right.Obj[i];
    float32 TurnOnDelay_s = 0.0f;

    
    if(    (   (eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
               /* track will be removed in the next frame */
            && (pObj->s_Status.willBeRemoved == 1)
            && (pObjExt_lt->Status.isRelevantTraffic == 1)
            && (    /* track lost in deact region */
                    (pObjExt_lt->eObjRegion == HLA_PLUS_DEACT_REGION)
                    /* or in the next frame there is no relevant traffic, independent of the region */
                 || (pPlusData->Object.Left.numRelevantVehiclesNextFrame == 0)
               )
           )
        || (   (eHeadlamp == HLA_PLUS_RIGHT_HEADLAMP)   
               /* track will be removed in the next frame */
            && (pObj->s_Status.willBeRemoved == 1)
            && (pObjExt_rt->Status.isRelevantTraffic == 1)
            && (    /* track lost in deact region */
                    (pObjExt_rt->eObjRegion == HLA_PLUS_DEACT_REGION)
                    /* or in the next frame there is no relevant traffic, independent of the region */
                 || (pPlusData->Object.Right.numRelevantVehiclesNextFrame == 0)
               )
           )
      )
    {
      /* track will be removed in the next frame  */
      
      /* get turn on delay                        */
      HLAFDecisionTurnOnDelayTTB( /* input */
                                  pObj,
                                  Speed,
                                  eMotorwayState,
                                  eTrafficStyle,
                                  ps_In,
                                  /* history/ output */
                                  &TurnOnDelay_s
                                );

    }
    if(pObj->s_Status.isVehicleOncoming == 1)
    {
      /* oncoming traffic */
      maxTTBOnc = CML_f_Max(maxTTBOnc, TurnOnDelay_s);
    }
    else
    {
      /* preceding traffic */
      maxTTBPrec = CML_f_Max(maxTTBPrec, TurnOnDelay_s);
    }
  }

  {
    float32 Penalty;

    if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
    {
      Penalty = CML_f_Max(pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);
    }
    else
    {
      Penalty = CML_f_Max(pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);
    }
  
    /* set delay if object is lost in DEACT */
    if(maxTTBOnc > 0.0f)
    {
      *pTurnOnDelay_TTBOnc_s  = maxTTBOnc  + Penalty;
    }
    if(maxTTBPrec > 0.0f)
    {
      *pTurnOnDelay_TTBPrec_s = maxTTBPrec + Penalty;
    }
  }
}

/* oncoming covered by preceding car ? */
static void HLAPlusKeepOffPart_OncCoveredByPrec( /* input */
                                                 const HLA_t_ObjectList       *pObjList,
                                                 const HLAplusData_t          *pPlusData,
                                                 const HLAFTrafficStyleOut_t  *pTrafficStyle,
                                                 const float32                dTime_s,
                                                 /* output */
                                                 HLAplusKeepOffReasonPartHB_t *pKeepOffReason
                                               )
{
  uint32 i_onc, i_prec;
  boolean bOncCoveredByPrec = FALSE;
  float32 TrafficStyle_NormFactor = pTrafficStyle->NormFactor;

/* ~CodeReview ~ID:ea2688838698a2b7d81cd77cfe60febb ~Reviewer:PC2184\jongd ~Date:18-7-2012 ~Priority:2 ~Comment:Check whether pObjList->ui32_NumVehicles <= RTE_HLAR_OBJECT_LIST_LENGTH. (Range checking) */
  /* check if oncoming vehicle will be removed and is covered by an preceding car */
  for(i_onc=0; i_onc<pObjList->ui32_NumVehicles; i_onc++)
  {
    const HLA_t_Object        *pObj_Onc    = &pObjList->as_Object[i_onc];
    const HLAplusObjectData_t *pObjExt_Onc = &pPlusData->Object.Right.Obj[i_onc];

    if( /*  oncoming vehicle */
        (pObj_Onc->s_Status.isVehicleOncoming == 1)
        /* relevant traffic */
        && (pObjExt_Onc->Status.isRelevantTraffic == 1)
        /* will be removed */
        && (pObj_Onc->s_Status.willBeRemoved == 1)
      )
    {
      /* check against preceding cars */
      for(i_prec=0; i_prec<pObjList->ui32_NumVehicles; i_prec++)
      {
        const HLA_t_Object        *pObj_Prec    = &pObjList->as_Object[i_prec];
        const HLAplusObjectData_t *pObjExt_Prec = &pPlusData->Object.Right.Obj[i_prec];

        if(    (pObj_Prec->s_Status.isVehicleAhead == 1)
            /* relevant traffic */
            && (pObjExt_Prec->Status.isRelevantTraffic == 1)
            /* track alive */
            && (pObj_Prec->ui8_lost_time == 0)
            /* oncoming on the right side of the preceding car */
            && ((TrafficStyle_NormFactor * pObj_Prec->f32_ObjectHorAng_rad) > (TrafficStyle_NormFactor * pObj_Onc->f32_ObjectHorAng_rad))
            /* oncoming near to preceding car */
            /* ~CodeReview ~ID:b44b9a84db21f4ef8489efac2587c49b ~Reviewer:CW01\brunnm ~Date:18.07.2012 ~Priority:3 ~Comment:magic number */
            && (((TrafficStyle_NormFactor * pObj_Prec->f32_ObjectHorAng_rad) - (TrafficStyle_NormFactor * pObj_Onc->f32_ObjectHorAng_rad)) < CML_Deg2Rad(2.0f))
          )   
        {
          bOncCoveredByPrec = TRUE;
        }
      }   
    }
  }

  if(bOncCoveredByPrec == TRUE)
  {
    /* set timer */
    /* ~CodeReview ~ID:30ca96e83457ed3db8aa2bb95a51639c ~Reviewer:CW01\brunnm ~Date:18.07.2012 ~Priority:3 ~Comment:magic number */
    pKeepOffReason->TurnOnDelay_OncCoverdByPrec_s = 3.0f;
  }
  else
  {
    /* decrement timer */
    if(pKeepOffReason->TurnOnDelay_OncCoverdByPrec_s > 0.0f)
    {
      pKeepOffReason->TurnOnDelay_OncCoverdByPrec_s -= dTime_s;
    }
    else
    {
      pKeepOffReason->TurnOnDelay_OncCoverdByPrec_s = 0.0f;
    }
  }  

  if(pKeepOffReason->TurnOnDelay_OncCoverdByPrec_s > 0.0f)
  {
    pKeepOffReason->Reason.Bit.OncCoveredByPrec = 1;
    pKeepOffReason->Cnt.OncCoveredByPrec    = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.OncCoveredByPrec = 0;
  }
}


void HLAPlusKeepOffPart_Stage1( const HLAF_t_RequiredInputs  *ps_In,
                                const HLAFData_t             *pFData,
                                const HLAFPlusOut_t          *pPlusOut,
                                const float32                dTime_s,
                                HLAplusData_t                *pPlusData,
                                HLAplusKeepOffReasonPartHB_t *pKeepOffReason_left,
                                HLAplusKeepOffReasonPartHB_t *pKeepOffReason_right
                              )
{
  HLAFDecicionDecTurnKeepOffCnt( &pKeepOffReason_left->Cnt.TimeToDeact,
                                 sizeof(pKeepOffReason_left->Cnt)
                               );
  HLAFDecicionDecTurnKeepOffCnt( &pKeepOffReason_right->Cnt.TimeToDeact,
                                 sizeof(pKeepOffReason_right->Cnt)
                               );



  /************************************************************************************/
  /* set Penalty Timer (additional time to wait until partial HB will be switched on  */
  /*     when too many short partial (<5sec) HB on switches were detected             */
  /*        -> increase penalty timer                                                 */
  /* **********************************************************************************/
  HLAFDecisionPenaltyTimer( /* input */
                            pPlusOut->eHighBeamState_Lt,
                            dTime_s,
                            /* history/ output */
                            &pPlusData->KeepOff.PenaltyTimer_left
                          );
  HLAFDecisionPenaltyTimer( /* input */
                            pPlusOut->eHighBeamState_Rt,
                            dTime_s,
                            /* history/ output */
                            &pPlusData->KeepOff.PenaltyTimer_right
                          );

  /*******************************************/
  /* Time to deactivate                      */
  /*******************************************/
  {
    HLAPlusKeepOffPart_TTDTurnOnDelay( dTime_s,
                                       &pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTD_s,
                                       pPlusData->Region.MinTimeToDeact_left_s, 
                                       hlafPlusParameter.Left.TTD_Threshold,
                                       hlafPlusParameter.Left.TTD_MaxTurnOnDelay
                                     );
    HLAPlusKeepOffPart_TTDTurnOnDelay( dTime_s,
                                       &pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTD_s,
                                       pPlusData->Region.MinTimeToDeact_right_s,
                                       hlafPlusParameter.Right.TTD_Threshold,
                                       hlafPlusParameter.Right.TTD_MaxTurnOnDelay
                                     );
    if(    (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
        && (pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTD_s > 0.0f)
      )
    {
      pKeepOffReason_left->Reason.Bit.TimeToDeact = 1;
      pKeepOffReason_left->Cnt.TimeToDeact = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pKeepOffReason_left->Reason.Bit.TimeToDeact = 0;
    }
    if(    (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
        && (pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTD_s > 0.0f)
      )
    {
      pKeepOffReason_right->Reason.Bit.TimeToDeact = 1;
      pKeepOffReason_right->Cnt.TimeToDeact = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pKeepOffReason_right->Reason.Bit.TimeToDeact = 0;
    }
  }


  /*******************************************/
  /* Time to border                          */
  /*******************************************/
  HLAPlusKeepOffPart_TTBTurnOnDelay( HLA_PLUS_LEFT_HEADLAMP,
                                     dTime_s,
                                     ps_In,
                                     pFData,
                                     pPlusData,
                                     /* output */
                                     &pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTBOnc_s,
                                     &pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTBPrec_s
                                   );
  HLAPlusKeepOffPart_TTBTurnOnDelay( HLA_PLUS_RIGHT_HEADLAMP,
                                     dTime_s,
                                     ps_In,
                                     pFData, 
                                     pPlusData,
                                     /* output */
                                     &pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTBOnc_s,
                                     &pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTBPrec_s
                                   );
  if(    (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
      && (    (pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTBOnc_s  > 0.0f)
           || (pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTBPrec_s > 0.0f)
         )
    )
  {
    pKeepOffReason_left->Reason.Bit.TimeToBorder = 1;
    pKeepOffReason_left->Cnt.TimeToBorder = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.TimeToBorder = 0;
  }

  if(    (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
      && (    (pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTBOnc_s  > 0.0f)
           || (pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTBPrec_s > 0.0f)
         )
    )
  {
    pKeepOffReason_right->Reason.Bit.TimeToBorder = 1;
    pKeepOffReason_right->Cnt.TimeToBorder = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_right->Reason.Bit.TimeToBorder = 0;
  }

  /**************************************************************************/
  /* left and right partial HB off, oncoming detected on the left side,     */
  /* no preceding car in FOV                                                */
  /* and all oncoming vehicles will leave the FOV in the next few frames    */
  /* (dist < 150 or ttb < 5sec)                                             */
  /*   -> keep partial HB off until oncoming will leave FOV                 */
  /**************************************************************************/
  if(    (pPlusData->HBState.Left.eState  == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->Region.RegionOncom_left.eRegion != HLA_PLUS_NO_OBJ)
      && (pPlusData->Region.RegionPreced_right.eRegion == HLA_PLUS_NO_OBJ)
    )
  {
    uint32 i;
    boolean bKeepOff = TRUE;

    /* one oncoming which is long enough in the FOV */
    /* -> do not keep right partial off             */
/* ~CodeReview ~ID:ea2688838698a2b7d81cd77cfe60febb ~Reviewer:PC2184\jongd ~Date:18-7-2012 ~Priority:2 ~Comment:Check whether ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles <= RTE_HLAR_OBJECT_LIST_LENGTH. (Range checking) */
    for(i=0; i<ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles;i++)
    {
      /* ~CodeReview ~ID:a14f84a24c985b80faaea8c8b1adb4ad ~Reviewer:CW01\brunnm ~Date:18.07.2012 ~Priority:3 ~Comment:magic number */
      if(    (ps_In->s_Sig.ps_ObjectList->as_Object[i].s_ObjectPos_xw.ui16_distMin_cm > 15000)
          && (ps_In->s_Sig.ps_ObjectList->as_Object[i].ui16_ttb18_ms > 5000)
        )
      {
        bKeepOff = FALSE;
      }
    } 
    /* no preceding car detected AND                                */
    /* all oncoming vehicles will leave the FOV in the next frames  */
    /* -> keep partial HB off                                       */
    if(bKeepOff == TRUE)
    {
      pKeepOffReason_left->Reason.Bit.OncWillLeaveFOV = 1;
      pKeepOffReason_left->Cnt.OncWillLeaveFOV = HLAF_TURN_OFF_REASON_MAX_CNT;
      pKeepOffReason_left->TurnOnDelay_OncWillLeaveFOV_s = 1.0f;
      
      pKeepOffReason_right->Reason.Bit.OncWillLeaveFOV = 1;
      pKeepOffReason_right->Cnt.OncWillLeaveFOV = HLAF_TURN_OFF_REASON_MAX_CNT;
      pKeepOffReason_right->TurnOnDelay_OncWillLeaveFOV_s = 1.0f;
    }

    if(    (pKeepOffReason_left->Reason.Bit.OncWillLeaveFOV == 1)
        && (pKeepOffReason_left->TurnOnDelay_OncWillLeaveFOV_s > 0.0f)
      )
    {
      pKeepOffReason_left->TurnOnDelay_OncWillLeaveFOV_s  -= dTime_s;
      pKeepOffReason_right->TurnOnDelay_OncWillLeaveFOV_s -= dTime_s;
    }  
    else
    {
      pKeepOffReason_left->Reason.Bit.OncWillLeaveFOV  = 0;
      pKeepOffReason_right->Reason.Bit.OncWillLeaveFOV = 0;
    }
  }
  else
  {   
    /* no vehicle detected or preceding car detected  */
    /* -> reset timer and keep off reason             */
    pKeepOffReason_left->TurnOnDelay_OncWillLeaveFOV_s  = 0.0f;
    pKeepOffReason_right->TurnOnDelay_OncWillLeaveFOV_s = 0.0f;
    pKeepOffReason_left->Reason.Bit.OncWillLeaveFOV     = 0;
    pKeepOffReason_right->Reason.Bit.OncWillLeaveFOV    = 0;
  }   
  

  /*************************************************************************/
  /* keep left high beam off until no oncoming vehicle is detected anymore */
  /*************************************************************************/
  if(    (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
      && (   (pPlusData->Region.RegionOncom_Alive_left.eRegion  != HLA_PLUS_NO_OBJ)
          || (pPlusData->Region.RegionOncom_Alive_right.eRegion != HLA_PLUS_NO_OBJ)
         )
    )
  {
    /* high beams off                                                               */
    /* and oncoming vehicle (alive) detected                                        */
    /* -> keep high beam off until no oncoming (alive and lost) is detected anymore */
    pKeepOffReason_left->Reason.Bit.NoOncoming = 1;
    pKeepOffReason_left->Cnt.NoOncoming = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  /* reset flag when no oncoming vehicle (alive or lost) detected */
  if(    (pPlusData->Region.RegionOncom_left.eRegion  == HLA_PLUS_NO_OBJ)
      && (pPlusData->Region.RegionOncom_right.eRegion == HLA_PLUS_NO_OBJ)
    )
  {
    /* reset partial high beam off flag */
    pKeepOffReason_left->Reason.Bit.NoOncoming  = 0;
    pKeepOffReason_right->Reason.Bit.NoOncoming = 0;
  }

  /*******************************************************************************************/
  /* set timer to keep left HB off for a minimal time after last oncoming leaves the HLA roi */
  /*******************************************************************************************/
  if(pKeepOffReason_left->Reason.Bit.NoOncoming == 1)
  {
    pPlusData->KeepOff.Reason_Left.TurnOnDelay_NoOncoming_s  = hlafPlusParameter.Left.MinTimeLowNoOncoming_s;
    pPlusData->KeepOff.Reason_Left.TurnOnDelay_NoOncoming_s += CML_f_Max(pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);
  }
  else
  {
    /* no oncoming vehicle detected */
    if(pPlusData->KeepOff.Reason_Left.TurnOnDelay_NoOncoming_s > 0.0f)
    {
      pPlusData->KeepOff.Reason_Left.TurnOnDelay_NoOncoming_s = pPlusData->KeepOff.Reason_Left.TurnOnDelay_NoOncoming_s - dTime_s;
      pKeepOffReason_left->Reason.Bit.NoOncomingMinTime = 1;
      pKeepOffReason_left->Cnt.NoOncomingMinTime = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pKeepOffReason_left->Reason.Bit.NoOncomingMinTime = 0;
    }
  }

  /********************************************************************************************/
  /* oncoming vehicles covered by preceding car wait some cycles until onc.Veh detected again */
  /********************************************************************************************/
  HLAPlusKeepOffPart_OncCoveredByPrec( /* input */
                                       ps_In->s_Sig.ps_ObjectList,
                                       pPlusData, 
                                       &pFData->DecisionOut.TrafficStyle,
                                       dTime_s,
                                       /* output */
                                       pKeepOffReason_left
                                     );




  /****************************/
  /* Outermost vehicle lost   */
  /****************************/
  pKeepOffReason_left->Reason.Bit.OutermostLost = 0;
  if(pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
  {
    if(pPlusData->Outermost.Left.bVehDet == TRUE)
    {
      if(pPlusData->Outermost.Left.VehOutermost.ui8_lost_time > 0)
      {
        pKeepOffReason_left->Reason.Bit.OutermostLost = 1;
        pKeepOffReason_left->Cnt.OutermostLost = HLAF_TURN_OFF_REASON_MAX_CNT;
      }
    }
  }
  pKeepOffReason_right->Reason.Bit.OutermostLost = 0;
  if(pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
  {
    if(pPlusData->Outermost.Right.bVehDet == TRUE)
    {
      if(pPlusData->Outermost.Right.VehOutermost.ui8_lost_time > 0)
      {
        pKeepOffReason_right->Reason.Bit.OutermostLost = 1;
        pKeepOffReason_right->Cnt.OutermostLost = HLAF_TURN_OFF_REASON_MAX_CNT;
      }
    }
  }


  /******************************************/
  /* No vehicle detected                    */
  /* wait until full HB will be switched on */
  /******************************************/
  if(   (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
     && (pPlusData->Region.RegionOncom_Alive_left.eRegion   == HLA_PLUS_NO_OBJ)
     && (pPlusData->Region.RegionPreced_Alive_left.eRegion  == HLA_PLUS_NO_OBJ)
     && (pPlusData->Region.RegionOncom_Alive_right.eRegion  == HLA_PLUS_NO_OBJ)
     && (pPlusData->Region.RegionPreced_Alive_right.eRegion == HLA_PLUS_NO_OBJ)
    )
  {
    pKeepOffReason_left->Reason.Bit.NoVeh = 1;
    pKeepOffReason_left->Cnt.NoVeh = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.NoVeh = 0;
  }

  if(   (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
     && (pPlusData->Region.RegionOncom_Alive_left.eRegion   == HLA_PLUS_NO_OBJ)
     && (pPlusData->Region.RegionPreced_Alive_left.eRegion  == HLA_PLUS_NO_OBJ)
     && (pPlusData->Region.RegionOncom_Alive_right.eRegion  == HLA_PLUS_NO_OBJ)
     && (pPlusData->Region.RegionPreced_Alive_right.eRegion == HLA_PLUS_NO_OBJ)
    )
  {
    pKeepOffReason_right->Reason.Bit.NoVeh = 1;
    pKeepOffReason_right->Cnt.NoVeh = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_right->Reason.Bit.NoVeh = 0;
  }

  /***************************************************************************/
  /* velocity will fall below activation speed in less than 2 to 3 seconds ? */
  /***************************************************************************/
  if(    (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->DecisionData.Speed.keepOffHLABySpeed == 1)
    )
  {
    pKeepOffReason_left->Reason.Bit.SpdAcc = 1;
    pKeepOffReason_left->Cnt.SpdAcc = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.SpdAcc = 0;
  }
 
  if(    (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->DecisionData.Speed.keepOffHLABySpeed == 1)
    )
  {
    pKeepOffReason_right->Reason.Bit.SpdAcc = 1;
    pKeepOffReason_right->Cnt.SpdAcc = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_right->Reason.Bit.SpdAcc = 0;
  }

  /*************************/
  /* maybe city detected ? */
  /*************************/
  if(pFData->DecisionOut.eCityState == RTE_HLAR_CITY_MAYBE)
  {
    pKeepOffReason_left->Reason.Bit.MaybeCity = 1;
    pKeepOffReason_left->Cnt.MaybeCity = HLAF_TURN_OFF_REASON_MAX_CNT;

    pKeepOffReason_right->Reason.Bit.MaybeCity = 1;
    pKeepOffReason_right->Cnt.MaybeCity = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.MaybeCity = 0;
    pKeepOffReason_right->Reason.Bit.MaybeCity = 0;
  }


  /*****************************************************/
  /* keep partial HB off for a minimal time            */
  /*****************************************************/
  /* set counters, when switching full/part HB off */
  if(   (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
     || (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
    )
  {
    pPlusData->KeepOff.Reason_Left.TurnOnDelay_Low2PartHB_s  = hlafPlusParameter.Left.MinTimeLow2PartHB_s;
    pPlusData->KeepOff.Reason_Left.TurnOnDelay_Low2PartHB_s += CML_f_Max(pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);
  }
  if(pPlusData->KeepOff.Reason_Left.TurnOnDelay_Low2PartHB_s > 0.0f)
  {
    pPlusData->KeepOff.Reason_Left.TurnOnDelay_Low2PartHB_s -= dTime_s;

    pKeepOffReason_left->Reason.Bit.minTimeOff = 1;
    pKeepOffReason_left->Cnt.minTimeOff = HLAF_TURN_OFF_REASON_MAX_CNT; 
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.minTimeOff = 0;
  }

  /* set counters, when switching full/part HB off */
  if(   (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
     || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
    )
  {
    pPlusData->KeepOff.Reason_Right.TurnOnDelay_Low2PartHB_s  = hlafPlusParameter.Right.MinTimeLow2PartHB_s;
    pPlusData->KeepOff.Reason_Right.TurnOnDelay_Low2PartHB_s += CML_f_Max(pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);
  }
  if(pPlusData->KeepOff.Reason_Right.TurnOnDelay_Low2PartHB_s > 0.0f)
  {
    pPlusData->KeepOff.Reason_Right.TurnOnDelay_Low2PartHB_s -= dTime_s;
    pKeepOffReason_right->Reason.Bit.minTimeOff = 1;
    pKeepOffReason_right->Cnt.minTimeOff = HLAF_TURN_OFF_REASON_MAX_CNT; 
  }
  else
  {
    pKeepOffReason_right->Reason.Bit.minTimeOff = 0;
  }

  /************************************************************************************************************************/
  /* preceding car detected for min time in activation region                                                             */
  /* 1. only preceding cars -> all preceding cars in RIGHT ACTIVATION REGION                                              */
  /* 2. preceding and oncoming vehicles (only on country road) -> all preceding cars in LEFT AND RIGHT ACTIVATION REGION  */
  /*              (oncoming vehicle could cover preceding car)                                                            */
  /************************************************************************************************************************/
  {
    float32 MinTimeInActRegion = pPlusData->Region.pActReg_right_preced->minTime_s + CML_f_Max(pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);
   
   
    if(pKeepOffReason_right->Reason.Bit.PrecMinTimeInActRegion == 0)
    {
      /* set keep off ? */
      if(    (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
             /* any alive preceding car ? */
          && (pPlusData->Region.RegionPreced_Alive_right.eRegion != HLA_PLUS_NO_OBJ)
        )
      {
        /* HB off and alive preceding car detected */
        if(    (pPlusData->Region.RegionPreced_Alive_right.eRegion != HLA_PLUS_ACT_REGION)
            || (   (pPlusData->Region.RegionPreced_Alive_right.eRegion == HLA_PLUS_ACT_REGION)
                && (pPlusData->Region.RegionPreced_Alive_right.time_s < MinTimeInActRegion)
               )
               /* oncoming car detected -> preceding car in left activation region */
            || (   (pFData->DecisionOut.Motorway.eStateInt != RTE_HLAF_MTWY_MOTORWAY)
                && (pPlusData->Region.RegionOncom_Alive_left.eRegion != HLA_PLUS_NO_OBJ)
                && (pPlusData->Region.RegionPreced_Alive_left.eRegion != HLA_PLUS_ACT_REGION)
               )
               /* oncoming car detected -> preceding car not long enough in left activation region */
            || (   (pFData->DecisionOut.Motorway.eStateInt != RTE_HLAF_MTWY_MOTORWAY)
                && (pPlusData->Region.RegionOncom_Alive_left.eRegion != HLA_PLUS_NO_OBJ)
                && (pPlusData->Region.RegionPreced_Alive_left.eRegion == HLA_PLUS_ACT_REGION)
                && (pPlusData->Region.RegionPreced_Alive_left.time_s < MinTimeInActRegion)
               )
          )
        {
          /* preceding car detected not long enough in activation region */
          pKeepOffReason_right->Reason.Bit.PrecMinTimeInActRegion = 1;
          pKeepOffReason_right->Cnt.PrecMinTimeInActRegion        = HLAF_TURN_OFF_REASON_MAX_CNT;
        }
      }
    }
    else
    {
      /* release keep off ? */
      if(    (pPlusData->Out.eHighBeamState_Rt != RTE_HLAF_HB_STATE_OFF)
          || (pPlusData->Region.RegionPreced_right.eRegion == HLA_PLUS_NO_OBJ)
          || (   (pPlusData->Region.RegionPreced_Alive_right.eRegion == HLA_PLUS_ACT_REGION)
              && (pPlusData->Region.RegionPreced_Alive_right.time_s > MinTimeInActRegion)
              && (   (pFData->DecisionOut.Motorway.eStateInt == RTE_HLAF_MTWY_MOTORWAY)
                  || (pPlusData->Region.RegionOncom_left.eRegion == HLA_PLUS_NO_OBJ)
                  || (   (pPlusData->Region.RegionPreced_Alive_left.eRegion == HLA_PLUS_ACT_REGION)
                      && (pPlusData->Region.RegionPreced_Alive_left.time_s > MinTimeInActRegion)
                     ) 
                 )
             )
        ) 
      {
        /* release keep off */
        pKeepOffReason_right->Reason.Bit.PrecMinTimeInActRegion = 0;
      }
      else
      {
        pKeepOffReason_right->Reason.Bit.PrecMinTimeInActRegion = 1;
        pKeepOffReason_right->Cnt.PrecMinTimeInActRegion        = HLAF_TURN_OFF_REASON_MAX_CNT;
      }
    }
    /* left side */
    MinTimeInActRegion = pPlusData->Region.pActReg_left_preced->minTime_s + CML_f_Max(pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);

    if(pKeepOffReason_left->Reason.Bit.PrecMinTimeInActRegion == 0)
    {
      /* set keep off ? */
      if(    (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_OFF)
             /* any alive preceding car ? */
          && (pPlusData->Region.RegionPreced_Alive_left.eRegion != HLA_PLUS_NO_OBJ)
        )
      {
        /* HB off and alive preceding car detected */
        if(    (pPlusData->Region.RegionPreced_Alive_left.eRegion != HLA_PLUS_ACT_REGION)
            || (   (pPlusData->Region.RegionPreced_Alive_left.eRegion == HLA_PLUS_ACT_REGION)
                && (pPlusData->Region.RegionPreced_Alive_left.time_s < MinTimeInActRegion)
               )
          )
        {
          /* preceding car detected not long enough in activation region */
          pKeepOffReason_left->Reason.Bit.PrecMinTimeInActRegion = 1;
          pKeepOffReason_left->Cnt.PrecMinTimeInActRegion        = HLAF_TURN_OFF_REASON_MAX_CNT;
        }
      }
    }
    else
    {
      /* release keep off ? */
      if(    (pPlusData->Out.eHighBeamState_Lt != RTE_HLAF_HB_STATE_OFF)
          || (pPlusData->Region.RegionPreced_left.eRegion == HLA_PLUS_NO_OBJ)
          || (   (pPlusData->Region.RegionPreced_Alive_left.eRegion == HLA_PLUS_ACT_REGION)
              && (pPlusData->Region.RegionPreced_Alive_left.time_s > MinTimeInActRegion)
             )
        ) 
      {
        /* release keep off */
        pKeepOffReason_left->Reason.Bit.PrecMinTimeInActRegion = 0;
      }
      else
      {
        pKeepOffReason_left->Reason.Bit.PrecMinTimeInActRegion = 1;
        pKeepOffReason_left->Cnt.PrecMinTimeInActRegion        = HLAF_TURN_OFF_REASON_MAX_CNT;
      }
    }
  }
  

  /*******************************************************************************/
  /* oncoming car detected for min time in activation region (only right region) */
  /*******************************************************************************/
  {
    float32 MinTimeInActRegion = pPlusData->Region.pActReg_right_oncom->minTime_s + CML_f_Max(pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s, pFData->HLAStdOut.activatePenaltyTime_s);

    if(pKeepOffReason_right->Reason.Bit.OncMinTimeInActRegion == 0)
    {
      /* set keep off ? */
      if(   (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
            /* any alive preceding car ? */
         && (pPlusData->Region.RegionOncom_Alive_right.eRegion != HLA_PLUS_NO_OBJ)
        )
      {
        /* HB off and alive oncoming car detected */
        if(    (pPlusData->Region.RegionOncom_Alive_right.eRegion != HLA_PLUS_ACT_REGION)
            || (   (pPlusData->Region.RegionOncom_Alive_right.eRegion == HLA_PLUS_ACT_REGION)
                && (pPlusData->Region.RegionOncom_Alive_right.time_s < MinTimeInActRegion)
               )
          )
        {
          /* preceding car detected not long enough in activation region */
          pKeepOffReason_right->Reason.Bit.OncMinTimeInActRegion = 1;
          pKeepOffReason_right->Cnt.OncMinTimeInActRegion        = HLAF_TURN_OFF_REASON_MAX_CNT;
        }
      }
    }
    else
    {
      /* release keep off ? */
      if(    (pPlusData->Out.eHighBeamState_Rt != RTE_HLAF_HB_STATE_OFF)
          || (pPlusData->Region.RegionOncom_right.eRegion == HLA_PLUS_NO_OBJ)
          || (   (pPlusData->Region.RegionOncom_Alive_right.eRegion == HLA_PLUS_ACT_REGION)
              && (pPlusData->Region.RegionOncom_Alive_right.time_s > MinTimeInActRegion)
             )
        ) 
      {
        /* release keep off */
        pKeepOffReason_right->Reason.Bit.OncMinTimeInActRegion = 0;
      }
      else
      {
        pKeepOffReason_right->Reason.Bit.OncMinTimeInActRegion = 1;
        pKeepOffReason_right->Cnt.OncMinTimeInActRegion        = HLAF_TURN_OFF_REASON_MAX_CNT;
      }
    }
    /* copy from right to left */
    pKeepOffReason_left->Reason.Bit.OncMinTimeInActRegion = pKeepOffReason_right->Reason.Bit.OncMinTimeInActRegion;
    pKeepOffReason_left->Cnt.OncMinTimeInActRegion        = pKeepOffReason_right->Cnt.OncMinTimeInActRegion;
  }


  /**********************************************************************************/
  /* keep partial HB off if the gap between left and right partial HB is too larges */
  /**********************************************************************************/
  if(    (pPlusData->HBState.Left.eState   == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->HBState.Right.eState  == HLA_PLUS_HB_STATE_PART_ON)
    )
  {
    if(CML_f_Abs(pPlusData->HBAngle.Left.Ang_Raw - pPlusOut->RotAngleMin_Rt) > hlafPlusParameter.KeepOff_MaxGap)
    {
      pKeepOffReason_left->Reason.Bit.Gap2Large = 1;
      pKeepOffReason_left->Cnt.Gap2Large        = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.Gap2Large = 0;
  }
  if(    (pPlusData->HBState.Right.eState  == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->HBState.Left.eState   == HLA_PLUS_HB_STATE_PART_ON)
    )
  {
    if(CML_f_Abs(pPlusOut->RotAngleMin_Lt - pPlusData->HBAngle.Right.Ang_Raw) > hlafPlusParameter.KeepOff_MaxGap)
    {
      pKeepOffReason_right->Reason.Bit.Gap2Large = 1;
      pKeepOffReason_right->Cnt.Gap2Large        = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
  }
  else
  {
    pKeepOffReason_right->Reason.Bit.Gap2Large = 0;
  }


  /**********************************************************************************/
  /* keep left partial HB off if right partial HB will switch off in a certain time */
  /**********************************************************************************/
  if(    (pPlusData->HBState.Left.eState  == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_PART_ON)
      && (pPlusData->Region.MinTimeToDeact_right_s < hlafPlusParameter.KeepOff_MinTimeToDeact)
    )
  {
    pKeepOffReason_left->Reason.Bit.TimeToDeactOther = 1;
    pKeepOffReason_left->Cnt.TimeToDeactOther        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_left->Reason.Bit.TimeToDeactOther = 0;
  }
  /**********************************************************************************/
  /* keep right partial HB off if left partial HB will switch off in a certain time */
  /**********************************************************************************/
  if(    (pPlusData->HBState.Right.eState  == HLA_PLUS_HB_STATE_OFF)
      && (pPlusData->HBState.Left.eState   == HLA_PLUS_HB_STATE_PART_ON)
      && (pPlusData->Region.MinTimeToDeact_left_s < hlafPlusParameter.KeepOff_MinTimeToDeact)
    )
  {
    pKeepOffReason_right->Reason.Bit.TimeToDeactOther = 1;
    pKeepOffReason_right->Cnt.TimeToDeactOther        = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason_right->Reason.Bit.TimeToDeactOther = 0;
  }


  /****************************************/
  /* maximum turn on delay for partial HB */
  /****************************************/
  {
    float32 max;
    
    /* left side */
    max = CML_f_Max(pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTD_s, pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTBOnc_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_TTBPrec_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_PotOncomDeact_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_PotOncom_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_Low2PartHB_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_NoOncoming_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_OncCoverdByPrec_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Left.TurnOnDelay_OncWillLeaveFOV_s);
    pPlusData->KeepOff.Reason_Left.TurnOnDelay_Max_s = max;

    /* right side */
    max = CML_f_Max(pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTD_s, pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTBOnc_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_TTBPrec_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_PotOncomDeact_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_PotOncom_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_Low2PartHB_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_NoOncoming_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_OncCoverdByPrec_s);
    max = CML_f_Max(max, pPlusData->KeepOff.Reason_Right.TurnOnDelay_OncWillLeaveFOV_s);
    pPlusData->KeepOff.Reason_Right.TurnOnDelay_Max_s = max;
  }
}

/* **************************************************************************** 
  Functionname:     HLAPlus2DecisionSetKeepOffReasonFullHB                 */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
*****************************************************************************/
void HLAPlusKeepOffFull( const HLAFData_t             *pFData,
                         const float32                dTime_s,
                         const HLAplusParameterTurnOnDelay_t *pTurnOnDelay,
                         HLAplusData_t                *pPlusData,
                         HLAplusKeepOffReasonFullHB_t *pKeepOffReason
                       )
{
  float32 PartHBwithoutVeh_s;
    

  /* set max time partial HB on without relevant vehicle depending on road type */
  if(pFData->DecisionOut.Motorway.eStateInt == RTE_HLAF_MTWY_MOTORWAY)
  {
    /* highway */
    PartHBwithoutVeh_s = pTurnOnDelay->PartHBwithoutVeh_Highway_s;
  }
  else
  {
    /* country road */
    PartHBwithoutVeh_s = pTurnOnDelay->PartHBwithoutVeh_Country_s;
  }

  HLAFDecicionDecTurnKeepOffCnt( &pKeepOffReason->Cnt.HB_Off,
                                 sizeof(pKeepOffReason->Cnt)
                               );

  /*********************************************************/
  /* keep full HB off until hla decides to turn on the HB  */
  /*********************************************************/
  
  /*    left AND right partial HB on                                                                   */
  /*    and no reason to deactivate HB (no vehicle detected)                                           */
  /*    and the gap between left and right part HB is closed or 1s (2s maybe city) no vehicle detected */
  /*    and partial HB will not be deactivated because velocity will fall below activation speed       */
  if(   (    (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_PARTIAL)
          && (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
          && (pPlusData->TurnOff.Reason_FullHB.Reason.u32 == 0)
          && (pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
          && (   ((pPlusData->HBAngle.Right.Ang_LP - pPlusData->HBAngle.Left.Ang_LP) >  0.0f)
              || (pPlusData->HBAngle.Left.NoVehTimer_s > PartHBwithoutVeh_s)
             )
          && (pPlusData->DecisionData.Speed.keepOffHLABySpeed == 0)
        )
    )
  {
    pKeepOffReason->Reason.Bit.HB_Off = 0;
  }
  /*    right partial HB on                                                                      */
  /*    and no reason to deactivate HB (no vehicle detected)                                     */
  /*    and 1s (2s maybe city) no vehicle detected                                               */
  /*    and partial HB will not be deactivated because velocity will fall below activation speed */
  else if(   (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
          && (pPlusData->TurnOff.Reason_FullHB.Reason.u32 == 0)
          && (pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
          && (pPlusData->HBAngle.Left.NoVehTimer_s > PartHBwithoutVeh_s)
          && (pPlusData->DecisionData.Speed.keepOffHLABySpeed == 0)
         )
  {
    pKeepOffReason->Reason.Bit.HB_Off = 0;
  }
  /*    right partial HB on, left off                                                            */
  /*    and no reason to deactivate HB (no vehicle detected)                                     */
  /*    and TimeToBorder == 0 (e.g. onc. passed and partial HB on -> full HB on wanted)          */
  /*    and no potential oncoming vehicle detected                                               */
  /*    and partial HB will not be deactivated because velocity will fall below activation speed */
  else if(   (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
          && (    (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_OFF)
               || (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_SPOT)
             ) 
          && (pPlusData->TurnOff.Reason_FullHB.Reason.u32 == 0)
          && (pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
          && (pPlusData->KeepOff.Reason_Left.Reason.Bit.TimeToBorder == 0)
          && (pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncoming == 0)
          && (pPlusData->DecisionData.Speed.keepOffHLABySpeed == 0)
          && (pPlusData->KeepOff.Reason_Left.Reason.Bit.MaybeCity == 0)
             /* not on the highway */
          && (pFData->DecisionOut.Motorway.eStateInt != RTE_HLAF_MTWY_MOTORWAY)
         )
  {
    pKeepOffReason->Reason.Bit.HB_Off = 0;
  }
  /* keep HB off when : */
  /* - hla standard HB state off (HB of HLA not HLA PLUS) */
  /* - and the current HB state is not on                 */
  else if(    (pFData->HLAStdOut.eHighBeamState == RTE_HLAF_HB_STATE_OFF)
           && (pPlusData->Out.eHighBeamState_Lt != RTE_HLAF_HB_STATE_FULL_ON)
           && (pPlusData->Out.eHighBeamState_Rt != RTE_HLAF_HB_STATE_FULL_ON)
         )
  {
    pKeepOffReason->Reason.Bit.HB_Off = 1;
    pKeepOffReason->Cnt.HB_Off = HLAF_TURN_OFF_REASON_MAX_CNT;
  }
  else
  {
    pKeepOffReason->Reason.Bit.HB_Off = 0;
  }


  /*****************************************************/
  /* stay in low beam for minimal time                 */
  /*****************************************************/
  /* set counters, when switching full/part HB off */
  if(   (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
     || (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
    )
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_left_s  = hlafPlusParameter.Left.MinTimeLow2FullHB_s;
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_left_s += pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s;
  }
  if(pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_left_s > 0.0f)
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_left_s -= dTime_s;
  }
  
  /* set counters, when switching full/part HB off */
  if(   (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
     || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
    )
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_right_s  = hlafPlusParameter.Right.MinTimeLow2FullHB_s;
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_right_s += pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s;
  }
  if(pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_right_s > 0.0f)
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_right_s -= dTime_s;
  }
    
  if(   (pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_left_s  > 0.0f)
     || (pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Low2FullHB_right_s > 0.0f)
    )
  {
    pKeepOffReason->Reason.Bit.minTimeOff = 1;
    pKeepOffReason->Cnt.minTimeOff = HLAF_TURN_OFF_REASON_MAX_CNT; 
  }
  else
  {
    pKeepOffReason->Reason.Bit.minTimeOff = 0;
  }


  /*****************************************************/
  /* stay in partial HB for minimal time               */
  /*****************************************************/
  /* set counters, when switching full/part HB off */
  if(   (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
     || (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_FULL_2_PART_ON)
    )
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_left_s  = hlafPlusParameter.Left.MinTimePart2FullHB_s;
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_left_s += pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s;
  }
  if(pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_left_s > 0.0f)
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_left_s -= dTime_s;
  }
  
  /* set counters, when switching full/part HB off */
  if(   (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF_2_PART_ON)
     || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_FULL_2_PART_ON)
    )
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_right_s = hlafPlusParameter.Right.MinTimePart2FullHB_s;
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_right_s += pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s;
  }
  if(pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_right_s > 0.0f)
  {
    pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_right_s -= dTime_s;
  }
    
  if(   (pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_left_s  > 0.0f)
     || (pPlusData->KeepOff.Reason_FullHB.TurnOnDelay_Part2FullHB_right_s > 0.0f)
    )
  {
    pKeepOffReason->Reason.Bit.minTimePartOn = 1;
    pKeepOffReason->Cnt.minTimePartOn = HLAF_TURN_OFF_REASON_MAX_CNT; 
  }
  else
  {
    pKeepOffReason->Reason.Bit.minTimePartOn = 0;
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlusKeepOffPart_Stage2                    */ /*!
  @brief            keep off partial HB stage 2.
  
  @description
                    1.  partial HB will be switched on in the next cycle                 
                        check if there is any reason to refuse the partial HB            
                        e.g. potential oncoming vehicle in FOV                           
                        -> set penalty timer only once                                   
                          when timer is elapsed and no other reason refuses partial HB  
                        -> turn on partial HB                                           
                    2. synchronize left and right partial HB                            

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
#define HLAPLUS2_MAX_SYNC_TIME_S    3.0f
#define HLAPLUS2_MIN_SYNC_TIME_S    2.0f
#define HLAPLUS2_MAX_TURNONDELAY_S  1.5f

void HLAPlusKeepOffPart_Stage2( const HLAF_t_RequiredInputs  *ps_In,
                                const HLAplusInputData_t     *pPlusIn,
                                const HLAFData_t             *pFData,
                                HLAplusData_t                *pPlusData
                              )
{
  boolean b_HBOff2PartHBOn_left, b_HBOff2PartHBOn_right;
  

  /**********************************************************************/
  /* the following keep off reasons                                     */
  /* checks whether the partial HB will be switched on after this cycle */
  /* and will delay the turn on if some events occurs                   */
  /* e.g. potential oncoming detected, ...                              */
  /**********************************************************************/

  /**********************************************************************/
  /* check whether the partial HB could be switched on after this cycle */
  /**********************************************************************/

  /* reset some keep off reason which will be set afterwards */
  pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncoming       = 0;
  pPlusData->KeepOff.Reason_Right.Reason.Bit.PotentialOncoming      = 0;
  pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncomingDeact  = 0;
  pPlusData->KeepOff.Reason_Right.Reason.Bit.PotentialOncomingDeact = 0;
  pPlusData->KeepOff.Reason_Left.Reason.Bit.Sync                    = 0;
  pPlusData->KeepOff.Reason_Right.Reason.Bit.Sync                   = 0;
  pPlusData->KeepOff.Reason_Left.Reason.Bit.Wait4OtherPHB           = 0;
  pPlusData->KeepOff.Reason_Right.Reason.Bit.Wait4OtherPHB          = 0;

  b_HBOff2PartHBOn_left  = HLAPlusDecision_HBOff2PartHBOn(pPlusData->HBState.Left.eState,
                                                          pFData->DecisionData.TurnOffReason_glob,
                                                          pPlusData->TurnOff.Reason_Left,
                                                          pPlusData->KeepOff.Reason_Left,
                                                          pPlusData->KeepOff.Reason_FullHB
                                                         );
  b_HBOff2PartHBOn_right = HLAPlusDecision_HBOff2PartHBOn(pPlusData->HBState.Right.eState,
                                                          pFData->DecisionData.TurnOffReason_glob,
                                                          pPlusData->TurnOff.Reason_Right,
                                                          pPlusData->KeepOff.Reason_Right,
                                                          pPlusData->KeepOff.Reason_FullHB
                                                         );


  /******************************************************/
  /* part HB will be switched on after this cycle       */
  /******************************************************/
  /* and potential oncoming traffic is detected         */
  /* (deactivation/ hold region)                        */
  /* keep part HB off for a certain time                */
  /******************************************************/
  {
    HLAPlusKeepOffPart_PotOncomDeact( &pPlusData->KeepOff.Reason_Left.TurnOnDelay_PotOncomDeact_s,
                                      pFData->CamData.dtimeFwd_s,
                                      pPlusData->Region.PotOncoming_left,
                                      pPlusData->HBState.Left.eState,
                                      b_HBOff2PartHBOn_left
                                    );
    HLAPlusKeepOffPart_PotOncomDeact( &pPlusData->KeepOff.Reason_Right.TurnOnDelay_PotOncomDeact_s,
                                      pFData->CamData.dtimeFwd_s,
                                      pPlusData->Region.PotOncoming_right,
                                      pPlusData->HBState.Right.eState,
                                      b_HBOff2PartHBOn_right
                                    );
    if(    (pPlusData->HBState.Left.eState == HLA_PLUS_HB_STATE_OFF)
        && (pPlusData->KeepOff.Reason_Left.TurnOnDelay_PotOncomDeact_s > 0.0f)
      )
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncomingDeact = 1;
      pPlusData->KeepOff.Reason_Left.Cnt.PotentialOncomingDeact = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncomingDeact = 0;
    }

    if(    (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
        && (pPlusData->KeepOff.Reason_Right.TurnOnDelay_PotOncomDeact_s > 0.0f)
      )
    {
      pPlusData->KeepOff.Reason_Right.Reason.Bit.PotentialOncomingDeact = 1;
      pPlusData->KeepOff.Reason_Right.Cnt.PotentialOncomingDeact = HLAF_TURN_OFF_REASON_MAX_CNT;

    }
    else
    {
      pPlusData->KeepOff.Reason_Right.Reason.Bit.PotentialOncomingDeact = 0;
    }


    /******************************************************/
    /* part HB will be switched on after this cycle       */
    /******************************************************/
    /*   potential oncoming traffic is detected anywhere  */
    /*   (activation/ deactivation hold region)           */
    /*   keep left part HB off for a certain time         */
    /******************************************************/
    HLAPlusKeepOffPart_PotOncom( ps_In->s_Sig.ps_ObjectList,
                                 pFData->CamData.dtimeFwd_s,
                                 &pPlusData->KeepOff.Reason_Left.TurnOnDelay_PotOncom_s,
                                 pPlusData->HBState.Left.eState,
                                 b_HBOff2PartHBOn_left 
                               );

    /* keep of part HB ? */
    if(pPlusData->KeepOff.Reason_Left.TurnOnDelay_PotOncom_s > 0)
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncoming    = 1;
      pPlusData->KeepOff.Reason_Left.Cnt.PotentialOncoming           = HLAF_TURN_OFF_REASON_MAX_CNT;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.PotentialOncoming  = 1;
      pPlusData->KeepOff.Reason_Right.Cnt.PotentialOncoming         = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.PotentialOncoming  = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.PotentialOncoming = 0;
    }
  }



  /**************************************************************************/
  /* synchronously partial HB on when only 1 or 2 preceding lights detected */
  /**************************************************************************/
  {
    float32 maxPenalty = CML_f_Max(pPlusData->KeepOff.PenaltyTimer_left.activatePenaltyTime_s, pPlusData->KeepOff.PenaltyTimer_right.activatePenaltyTime_s);
    maxPenalty = CML_f_Max(maxPenalty, pFData->HLAStdOut.activatePenaltyTime_s);

    if(    /* HB off */
           (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_OFF)
        && (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
           /* no oncoming vehicle (alive or lost) detected */
        && (pPlusData->Region.RegionOncom_left.eRegion  == HLA_PLUS_NO_OBJ)
        && (pPlusData->Region.RegionOncom_right.eRegion == HLA_PLUS_NO_OBJ)
           /* only one or two preceding lights detected */ 
        && (ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles <= 2)
        && (    /* vehicle not in activation region */
               (pPlusData->Region.RegionPreced_left.eRegion != HLA_PLUS_ACT_REGION)
            || (pPlusData->Region.RegionPreced_right.eRegion != HLA_PLUS_ACT_REGION)
               /* preceding car will leave activation region */
            || (pPlusData->KeepOff.Reason_Left.Reason.Bit.TimeToDeact  == 1)
            || (pPlusData->KeepOff.Reason_Right.Reason.Bit.TimeToDeact == 1)
               /* preceding car not long enough in activation region */
            || (    (pPlusData->Region.RegionPreced_left.eRegion == HLA_PLUS_ACT_REGION)
                 && (pPlusData->Region.RegionPreced_left.time_s < (0.5f + maxPenalty))
               )
            || (    (pPlusData->Region.RegionPreced_right.eRegion == HLA_PLUS_ACT_REGION)
                 && (pPlusData->Region.RegionPreced_right.time_s < (0.5f + maxPenalty))
               )
           )
      )
    {
      /* do not switch single left or right HB on */
      /* wait for synchronously HB on             */
      pPlusData->KeepOff.Reason_Left.Reason.Bit.SyncSinglePrecCar  = 1;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.SyncSinglePrecCar = 1;
      pPlusData->KeepOff.Reason_Left.Cnt.SyncSinglePrecCar  = HLAF_TURN_OFF_REASON_MAX_CNT; 
      pPlusData->KeepOff.Reason_Right.Cnt.SyncSinglePrecCar = HLAF_TURN_OFF_REASON_MAX_CNT; 
    }
    else
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.SyncSinglePrecCar  = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.SyncSinglePrecCar = 0;
    }
  }


  /***************************************************/
  /* synchronize left and right partial HB           */
  /***************************************************/
  
  /* check whether the partial HB could be switched on after this cycle */
  b_HBOff2PartHBOn_left  = HLAPlusDecision_HBOff2PartHBOn(pPlusData->HBState.Left.eState,
                                                          pFData->DecisionData.TurnOffReason_glob,
                                                          pPlusData->TurnOff.Reason_Left,
                                                          pPlusData->KeepOff.Reason_Left,
                                                          pPlusData->KeepOff.Reason_FullHB
                                                         );
  b_HBOff2PartHBOn_right = HLAPlusDecision_HBOff2PartHBOn(pPlusData->HBState.Right.eState,
                                                          pFData->DecisionData.TurnOffReason_glob,
                                                          pPlusData->TurnOff.Reason_Right,
                                                          pPlusData->KeepOff.Reason_Right,
                                                          pPlusData->KeepOff.Reason_FullHB
                                                         );
  
  if(   (pPlusData->HBState.Left.eState  == HLA_PLUS_HB_STATE_OFF)
     && (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
    )
  {
    /* both partial HB will be switched on in this cycle ? */
    if(    (b_HBOff2PartHBOn_left == TRUE)
        && (b_HBOff2PartHBOn_right == TRUE)
      )
    {
      /* partial HB will be switched synchronously in this cycle */
    }
    /* right partial HB could be switched on in this cycle */
    else if(b_HBOff2PartHBOn_right == TRUE)
    {
      if(    (pPlusData->KeepOff.PartHB_SyncTimer_right_s < HLAPLUS2_MIN_SYNC_TIME_S)
             /* no oncoming vehicles detected */
          && (pPlusData->KeepOff.Reason_Left.Reason.Bit.NoOncoming == 0)
             /* max turn on delay for left HB < 1.5sec -> wait for left partial HB */
          && (pPlusData->KeepOff.Reason_Left.TurnOnDelay_Max_s < HLAPLUS2_MAX_TURNONDELAY_S)
             /* vehicle will come soon into activation region */
          && (pPlusData->Region.MaxTimeToAct_left_s < HLAPLUS2_MAX_TURNONDELAY_S)
             /* vehicle will not come soon into deactivation region */
          && (pPlusData->Region.MinTimeToDeact_left_s > HLAPLUS2_MAX_TURNONDELAY_S)
        )
      {
        /* wait a few cycles */
        pPlusData->KeepOff.Reason_Right.Reason.Bit.Sync = 1;
        pPlusData->KeepOff.Reason_Right.Cnt.Sync = HLAF_TURN_OFF_REASON_MAX_CNT;
      }
      

      /* increment sync counter */
      if(pPlusData->KeepOff.PartHB_SyncTimer_right_s < HLAPLUS2_MAX_SYNC_TIME_S)
      {
        pPlusData->KeepOff.PartHB_SyncTimer_right_s += pFData->CamData.dtimeFwd_s;
      }
    }
    /* left partial HB could be switched on in this cycle */
    else if(b_HBOff2PartHBOn_left == TRUE)
    {
      if(    (pPlusData->KeepOff.PartHB_SyncTimer_left_s < HLAPLUS2_MIN_SYNC_TIME_S)
        /* max turn on delay for left HB < 1.5sec -> wait for left partial HB */
        && (pPlusData->KeepOff.Reason_Right.TurnOnDelay_Max_s < HLAPLUS2_MAX_TURNONDELAY_S)
        /* vehicle will come soon into activation region */
        && (pPlusData->Region.MaxTimeToAct_left_s < HLAPLUS2_MAX_TURNONDELAY_S)
        /* vehicle will not come soon into deactivation region */
        && (pPlusData->Region.MinTimeToDeact_left_s > HLAPLUS2_MAX_TURNONDELAY_S)
        )
      {
        /* wait a few cycles */
        pPlusData->KeepOff.Reason_Left.Reason.Bit.Sync = 1;
        pPlusData->KeepOff.Reason_Left.Cnt.Sync = HLAF_TURN_OFF_REASON_MAX_CNT;
      }


      /* increment sync counter */
      if(pPlusData->KeepOff.PartHB_SyncTimer_left_s < HLAPLUS2_MAX_SYNC_TIME_S)
      {
        pPlusData->KeepOff.PartHB_SyncTimer_left_s += pFData->CamData.dtimeFwd_s;
      }
    }
    else
    {
      /* Do nothing */
    }
  }
  /* reset sync counter */
  if(    (pPlusData->HBState.Right.eState != HLA_PLUS_HB_STATE_OFF)
      || (b_HBOff2PartHBOn_right == FALSE)
    )
  {
    pPlusData->KeepOff.PartHB_SyncTimer_right_s = 0.0f;
  }
  if(    (pPlusData->HBState.Left.eState != HLA_PLUS_HB_STATE_OFF)
      || (b_HBOff2PartHBOn_left == FALSE)
    )
  {
    pPlusData->KeepOff.PartHB_SyncTimer_left_s = 0.0f;
  }


  /***************************************************/
  /* keep left partial HB off until right part. HB   */
  /* will be switched on                             */
  /***************************************************/
  if(pPlusIn->Cfg.KeepOffLeft_LeftOnly == 1)
  {
    /* keep left partial HB off until right partial HB will be switched on */
    if(    (    (pPlusData->HBState.Left.eState  == HLA_PLUS_HB_STATE_OFF)
             || (pPlusData->HBState.Left.eState  == HLA_PLUS_HB_STATE_PART_2_OFF)
             || (pPlusData->HBState.Left.eState  == HLA_PLUS_HB_STATE_FULL_2_OFF)
           )   
        && (    (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_OFF)
             || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
             || (pPlusData->HBState.Right.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
           )
        && (b_HBOff2PartHBOn_right == FALSE)
      )
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.Wait4OtherPHB = 1;
      pPlusData->KeepOff.Reason_Left.Cnt.Wait4OtherPHB = HLAF_TURN_OFF_REASON_MAX_CNT;
    }
    else
    {
      pPlusData->KeepOff.Reason_Left.Reason.Bit.Wait4OtherPHB  = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.Wait4OtherPHB = 0;
    }
  }


  /*******************************************************************************/
  /* asymmetric mode enabled ?                                                   */
  /* idea: switch left partial HB on when right partial HB will be switched off  */
  /*       and vice versa                                                        */
  /*******************************************************************************/
  if(pPlusIn->Cfg.AsymmetricMode == 1)
  {
    if(   /* left partial HB off */
          (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_OFF)
          /* right partial HB on */
       && (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
          /* right partial HB will be switched off in this cycle */
       && (pPlusData->TurnOff.Reason_Right.Reason.u32 != 0)
      )
    {
      /* delete Keep off of left partial HB */
      /* -> left partial HB could be switched on */
      pPlusData->KeepOff.Reason_Left.Reason.Bit.TimeToBorder = 0;
      pPlusData->KeepOff.Reason_Left.Reason.Bit.SyncSinglePrecCar = 0;
      pPlusData->KeepOff.Reason_Left.Reason.Bit.Gap2Large = 0;
      pPlusData->KeepOff.Reason_Left.Reason.Bit.TimeToDeactOther = 0;
      pPlusData->KeepOff.Reason_Left.Reason.Bit.Sync = 0;
      pPlusData->KeepOff.Reason_Left.Reason.Bit.Wait4OtherPHB = 0;
    }
    if(   /* right partial HB off */
          (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
          /* right partial HB on */
       && (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_PARTIAL)
          /* right partial HB will be switched off in this cycle */
       && (pPlusData->TurnOff.Reason_Left.Reason.u32 != 0)
      )
    {
      /* delete some Keep off of right partial HB */
      /* -> right partial HB could be switched on */
      pPlusData->KeepOff.Reason_Right.Reason.Bit.TimeToBorder = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.SyncSinglePrecCar = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.Gap2Large = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.TimeToDeactOther = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.Sync = 0;
      pPlusData->KeepOff.Reason_Right.Reason.Bit.Wait4OtherPHB = 0;
    }
  }
}
