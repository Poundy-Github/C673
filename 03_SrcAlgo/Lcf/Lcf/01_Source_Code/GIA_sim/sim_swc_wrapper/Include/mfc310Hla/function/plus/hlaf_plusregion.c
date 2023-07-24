/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plusregion.c

  DESCRIPTION:            Set all region depending data (vehicle in activation/ deactivation or hold region).

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_plusregion.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:28CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:10CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:49CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.27 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_plusregion.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusregion.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.26 2014/03/19 16:31:19CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:20 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.25 2014/03/04 16:52:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:29 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.24 2014/02/06 16:01:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:24 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.23 2014/01/24 09:35:04CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:35:05 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.22 2014/01/23 10:35:24CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixes for float with zero comparison
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 23, 2014 10:35:25 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.21 2014/01/21 09:12:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:58 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.20 2013/03/11 16:13:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:29 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19 2013/03/08 17:43:25CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:25 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.18 2013/01/28 15:06:13CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eRedReflectorArea
  CHANGE:                 - HLA_t_eHighwayLatPosState
  CHANGE:                 - HLA_t_eHighwayEgoMotionState
  CHANGE:                 - HLA_t_eHighwayOcclusionState
  CHANGE:                 --- Added comments ---  brunnm [Jan 28, 2013 3:06:13 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.17 2013/01/24 16:37:21CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:22 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.16 2013/01/18 07:46:03CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:04 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.15 2012/12/05 17:10:12CET Zechner, Stefan (uidt9253) 
  CHANGE:                 avoid division by zero
  CHANGE:                 --- Added comments ---  uidt9253 [Dec 5, 2012 5:10:16 PM CET]
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGE:                 Revision 1.14 2012/09/10 06:31:36CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed usage of wrong activation parameter set while switching from full HB to partial HB
  CHANGE:                 --- Added comments ---  brunnm [Sep 10, 2012 6:31:36 AM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.13 2012/07/23 12:58:07CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:07 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.12 2012/07/18 07:51:47CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 7:51:48 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.11 2012/04/25 19:24:32CEST Brunn, Marcus (brunnm) 
  CHANGE:                 HLAF:
  CHANGE:                 - reduced TurnOff_minTTB from 2 to 1sec
  CHANGE:                 - fixed maybecity full HB turn off
  CHANGE:                 - turn off partial HB for preceding vehicles in less than 25m
  CHANGE:                 --- Added comments ---  brunnm [Apr 25, 2012 7:24:34 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.10 2012/04/23 21:02:39CEST Brunn, Marcus (brunnm) 
  CHANGE:                 used si16_delta_x instead of si16_delta_x_lp
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 9:02:39 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/04/23 15:49:54CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGE:                 - delayed HB turn on after vehicles goes lost
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 3:49:54 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.8 2012/04/21 15:04:38CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:38 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/03/23 11:36:15CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGE:                 time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 23, 2012 11:36:15 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.6 2012/03/15 16:25:12CET Brunn, Marcus (brunnm) 
  CHANGE:                 added new highway state: HLAR_HIGHWAY_EM_LOW_SPEED
  CHANGE:                 Revision 1.5 2012/02/20 16:40:35CET Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf optimization in curvy roads
  CHANGE:                 Revision 1.4 2012/02/13 06:24:09CET Brunn, Marcus (brunnm) 
  CHANGE:                 used relevant traffic flag from extended object list
  CHANGE:                 Revision 1.3 2012/02/08 16:57:52CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed detection of relevant traffic
  CHANGE:                 - hla plus: fast HB on when oncoming traffic passed
  CHANGE:                 Revision 1.2 2012/02/06 15:27:45CET Brunn, Marcus (brunnm) 
  CHANGE:                 turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGE:                 Revision 1.1 2012/01/31 06:43:28CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_plusregion.h"
#include "hlaf_decision.h"

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
static void HLAPlusRegion_SetActDeactRegion( /* input */
                                             const HLAplusData_t               *pPlusData,
                                             HLA_t_Object                      *pObj,
                                             const HLA_t_CameraParameter       *pCamPar,
                                             const HLAplusActDeactRegionPar_t  *pActReg,
                                             const HLAplusActDeactRegionPar_t  *pDeactReg,
                                             const float32                      CurveLightRotAngle,
                                             const eHLAplusHeadlamp_t           eHeadlamp,
                                             const HLAFTrafficStyleOut_t        *pTrafficStyle,
                                             /* history */
                                             float32                           *pTimeToAct,
                                             float32                           *pTimeToDeact,
                                             /* output */
                                             HLAplusRegion_t                    *pObjPos,
                                             HLA_t_Object                       **ppObjPos,
                                             HLAplusObjectData_t                *pObjExt
                                           );
static void HLAPlusRegion_GetPotOncomingInDeactRegion( const HLAplus2ActDeactRegionPO_t   *pActDeactReg,
                                                       const HLA_t_Object                 *pObj,
                                                       const HLAFTrafficStyleOut_t  *pTrafficStyle,
                                                       float32                      CurveLightRotAngle,
                                                       uint8                        *pPotOncom,
                                                       eHLAplusHeadlamp_t          eHeadlamp,
                                                       eHLAplusHBState_t   eHBState
                                                     );
static void HLAPlusRegion_CalcActDeactRegionAngle( /* input */
                                           const HLA_t_Object                *pObj,
                                           const HLAplusActDeactRegionPar_t *pPar,
                                           const float32                      CurveLightRotAngle,
                                           /* output */
                                           float32                           *pAngle
                                           );
static void HLAPlusRegion_DetermineActDeactRegion( /* input */
                                           float32                     ObjAng_rad,
                                           float32                     Ang_Act_rad,
                                           float32                     Ang_Deact_rad,
                                           eHLAplusHeadlamp_t         eHeadlamp,
                                           /* output */
                                           eHLAplusRegion_t           *pObjPos
                                           );
static void HLAPlusRegion_GetTimeToActDeactRegion(/* input */
                                                  const HLAplusData_t         *pPlusData,
                                                  const HLA_t_CameraParameter *pCamPar,
                                                  const HLA_t_Object          *pObj,
                                                  const HLAFTrafficStyleOut_t *pTrafficStyle,
                                                  const float32               actAngle,
                                                  const float32               deactAngle,
                                                  const eHLAplusHeadlamp_t    eHeadlamp,
                                                  /* output */
                                                  float32                     *pTimeToAct, 
                                                  float32                     *pTimeToDeact
                                                 );
static void HLAPlusRegion_SetRegionTimeDistance( eHLAplusRegion_t  eObjPos_Fallback, /* fallback object */
                                                 float32           ddist_m,
                                                 float32           dtime_s,
                                                 HLAplusRegion_t   *pObjPos     
                                                 );



static void HLAPlusRegion_GetPotOncomingInDeactRegion( const HLAplus2ActDeactRegionPO_t   *pActDeactReg,
                                                       const HLA_t_Object           *pObj,
                                                       const HLAFTrafficStyleOut_t  *pTrafficStyle,  
                                                       float32                      CurveLightRotAngle,
                                                       uint8                        *pPotOncom,
                                                       eHLAplusHeadlamp_t          eHeadlamp,
                                                       eHLAplusHBState_t   eHBState
                                                     )
{
  float32                       Ang_Deact;
  float32                       Ang_Act;
  eHLAplusRegion_t             eObjPos;
  const HLAplusActDeactRegionPar_t   *pActReg;

  /* set pointer to activation region     */
  /* depending on current high beam state */
  if(   (eHBState == HLA_PLUS_HB_STATE_OFF)
    || (eHBState == HLA_PLUS_HB_STATE_FULL_2_OFF)
    || (eHBState == HLA_PLUS_HB_STATE_PART_2_OFF)
    )
  {
    /* low beam active  */
    pActReg  = &pActDeactReg->ActRegion_LowBeam;
  }
  else
  {
    /* high beam/ partial high beam active */
    pActReg  = &pActDeactReg->ActRegion_HighBeam;
  }

  /* deactivation region */
  HLAPlusRegion_CalcActDeactRegionAngle( /* input */
    pObj,
    &pActDeactReg->DeactRegion,
    CurveLightRotAngle,
    /* output */
    &Ang_Deact
    );

  /* activation region */
  HLAPlusRegion_CalcActDeactRegionAngle( /* input */
    pObj,
    pActReg,
    CurveLightRotAngle,
    /* output */
    &Ang_Act
    );

  /* determine activation/ deactivation region of vehicle */
  HLAPlusRegion_DetermineActDeactRegion( /* input */
    (pTrafficStyle->NormFactor * pObj->f32_ObjectHorAng_rad),
    Ang_Act,
    Ang_Deact,
    eHeadlamp,
    /* output */
    &eObjPos
    );

  /* detect potential oncoming vehicle in DEACT REGION */
  if(    (   (eObjPos == HLA_PLUS_DEACT_REGION)
    || (eObjPos == HLA_PLUS_HOLD_REGION)
    )
    && (pObj->s_Status.isPotentialVehicleOncoming1st == 1)
    && (pObj->s_Status.isVehicleOncoming == 0)
    && (pObj->s_Status.isVehicleAhead == 0)
    )
  {
    *pPotOncom = 1;
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlus2CalcActDeactRegionAngle                       */ /*!
  @brief            
  @description      


  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusRegion_CalcActDeactRegionAngle( /* input */
                                      const HLA_t_Object                *pObj,
                                      const HLAplusActDeactRegionPar_t *pPar,
                                      const float32                      CurveLightRotAngle,
                                      /* output */
                                      float32                           *pAngle
                                    )
{
  sint32  i, i0;
  float32 ObjDist;
  float32 dDist;
  

  ObjDist = 0.005f * (pObj->s_ObjectPos_xw.ui16_distMin_cm + pObj->s_ObjectPos_xw.ui16_distMax_cm);
  

  /* find parameters from LUT to interpolate the AbsAngle */
  i0 = HLA_PLUS2_ACT_DEACT_REGION_LUT-2;
  for(i=1; i<HLA_PLUS2_ACT_DEACT_REGION_LUT; i++)
  {
    if(ObjDist <= pPar->Dist_m[i])
    {
      i0 = i-1;
      break;
    }
  }
  
  /* interpolate angle */
  dDist = pPar->Dist_m[i0+1] - pPar->Dist_m[i0];
  if(dDist > 0.0f)
  {
    float32 Gradient = (pPar->Ang_rad[i0+1] - pPar->Ang_rad[i0])/ dDist;

    *pAngle = pPar->Ang_rad[i0] + (Gradient * (ObjDist - pPar->Dist_m[i0]));
  }
  else
  {
    *pAngle = pPar->Ang_rad[i0];
  }
    
  
  /* add CurveLightRotAngle */
  *pAngle = *pAngle + (pPar->CurveLightAngleFactor * CurveLightRotAngle);
  
}


/* **************************************************************************** 
  Functionname:     HLAPlus2SetRegionTimeDistance                       */ /*!
  @brief            set distance and time since the object is detected in the current region
  @description      


  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusRegion_SetRegionTimeDistance( eHLAplusRegion_t  eObjPos_Fallback, /* fallback object */
                                                 float32           ddist_m,
                                                 float32           dtime_s,
                                                 HLAplusRegion_t   *pObjPos     
                                               )
{
  /* set distance and time since the object is detected in the current region */
  if(pObjPos->eRegion_TimeDist !=  pObjPos->eRegion)
  {
    /* region changed  */
    
    /* reset time and distance if there is no fallback object */
    /* or the fallback object is in a different region        */
    if(    (eObjPos_Fallback == HLA_PLUS_NO_OBJ)
        || (eObjPos_Fallback != pObjPos->eRegion_TimeDist)
      )
    {
      /* do not change  */
      pObjPos->eRegion_TimeDist = pObjPos->eRegion;

      /* -> reset time and distance */
      pObjPos->dist_m = 0.0f;
      pObjPos->time_s = 0.0f;
    }
  }  
  else
  {
    /* region unchanged             */
    /* increment distance and time  */
    pObjPos->dist_m += ddist_m;
    pObjPos->time_s += dtime_s;
  }
}


/* track currently in activation region   */
/* timeToDeactRegion > 0.0f               */
/* timeToActRegion   = 0.0f               */
/* track currently in deactivation region */
/* timeToDeactRegion = 0.0f               */
/* timeToActRegion   > 0.0f               */
static void HLAPlusRegion_GetTimeToActDeactRegion( /* input */
                                                   const HLAplusData_t         *pPlusData,
                                                   const HLA_t_CameraParameter *pCamPar,
                                                   const HLA_t_Object          *pObj,
                                                   const HLAFTrafficStyleOut_t *pTrafficStyle,
                                                   const float32               actAngle,
                                                   const float32               deactAngle,
                                                   const eHLAplusHeadlamp_t    eHeadlamp,
                                                   /* output */
                                                   float32                     *pTimeToAct, 
                                                   float32                     *pTimeToDeact
                                                 )
{
  float32 timeToDeactRegion      = 0.0f;
  float32 timeToActRegion        = 0.0f;
  const float32 HLA_PLUS_MAX_TTD = 100.0f;

  /* traffic style and headlamp normalized dx, object angle, activation to deactivation angle */
  float32 dx_norm;
  float32 ObjAngle_norm;
  float32 ActDeactAngle_norm;

  

  /* normalize all angles for left headlamps */
  /* and right hand traffic                  */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    /* left headlamp */
    dx_norm       = pTrafficStyle->NormFactor * pObj->si16_delta_x;
    ObjAngle_norm = pTrafficStyle->NormFactor * pObj->f32_ObjectHorAng_rad;
    
    /* set ActDeactAngle                                          */
    /* HB on:  ActDeactAngle = angle where HB will be deactivated */
    /* HB off: ActDeactAngle = angle where HB will be activated   */
    if(    (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_PARTIAL)
        || (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_FULL_ON)
      )
    {
      /* partial/ full HB on */
      ActDeactAngle_norm = deactAngle;
    }
    else
    {
      /* HB off */
      ActDeactAngle_norm = actAngle;
    }
  }
  else
  {
    /* right headlamp */
    dx_norm       = -pTrafficStyle->NormFactor * pObj->si16_delta_x;
    ObjAngle_norm = -pTrafficStyle->NormFactor * pObj->f32_ObjectHorAng_rad;

    /* set ActDeactAngle                                          */
    /* HB on:  ActDeactAngle = angle where HB will be deactivated */
    /* HB off: ActDeactAngle = angle where HB will be activated   */
    if(    (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
        || (pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON)
      )
    {
      /* partial/ full HB on */
      ActDeactAngle_norm = -deactAngle;
    }
    else
    {
      /* HB off */
      ActDeactAngle_norm = -actAngle;
    }
  }  

  /* get time to deactivation region depending on track motion */
  /* get time to activation region depending on track motion   */
  if(ObjAngle_norm < ActDeactAngle_norm)
  {
    /* track currently in activation region */
    /* consider: 1 pixel variance           */
    if(dx_norm > -1.0f)
    {
      /* track moves deeper into the activation region */
      timeToDeactRegion = HLA_PLUS_MAX_TTD;
    }
    else
    {
      float32 diffAngle;
      float32 angleSpeed;

      /* track moves into deactivation region */
      /* 1 pixel variance                     */
      /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() */
      angleSpeed        = (-dx_norm - 1.0f)/ pCamPar->s_FocalLength.f32_x;
      diffAngle         = ActDeactAngle_norm - ObjAngle_norm;

      if (CML_f_IsNonZero(angleSpeed))
      {
        timeToDeactRegion = (diffAngle / angleSpeed) * pCamPar->f32_cycleTime;
      }
      else
      {
        timeToDeactRegion = HLA_PLUS_MAX_TTD;
      }
    }
  }
  else
  {
    /* track currently in deactivation region */
    /* consider: 1 pixel variance           */
    if(dx_norm < 1.0f)
    {
      /* track moves deeper into the deactivation region */
      timeToActRegion = HLA_PLUS_MAX_TTD;
    }
    else
    {
      float32 diffAngle;
      float32 angleSpeed;

      /* track moves into activation region */
      /* 1 pixel variance                   */
      /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() */
      angleSpeed        = (-dx_norm  + 1.0f)/ pCamPar->s_FocalLength.f32_x;
      diffAngle         = ActDeactAngle_norm - ObjAngle_norm;

      if (CML_f_IsNonZero(angleSpeed))
      {
        timeToActRegion = (diffAngle / angleSpeed) * pCamPar->f32_cycleTime;
      }
      else
      {
        timeToActRegion = HLA_PLUS_MAX_TTD;
      }
    }
  }

  /* copy outputs */
  *pTimeToAct   = timeToActRegion;
  *pTimeToDeact = timeToDeactRegion;
}


/* **************************************************************************** 
  Functionname:     HLAPlus2DetermineActDeactRegion                       */ /*!
  @brief            determine the object position regarding the deactivation/ hold/ activation region
  @description      


  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusRegion_DetermineActDeactRegion( /* input */
                                      float32                     ObjAng_rad,
                                      float32                     Ang_Act_rad,
                                      float32                     Ang_Deact_rad,
                                      eHLAplusHeadlamp_t         eHeadlamp,
                                      /* output */
                                      eHLAplusRegion_t           *pObjPos
                                    )
{
  /* determine object region */
  /* for left headlamp */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    /* left side */
    /* positive angles related to AUTOSAR */
    if(ObjAng_rad > Ang_Deact_rad)
    {
      *pObjPos = HLA_PLUS_DEACT_REGION;
    }
    else if(ObjAng_rad < Ang_Act_rad)
    {
      *pObjPos = HLA_PLUS_ACT_REGION;
    }
    else
    {
      *pObjPos = HLA_PLUS_HOLD_REGION;
    }
  }
  else
  {
    /* right side */
    /* negative angles related to AUTOSAR */
    if(ObjAng_rad < Ang_Deact_rad)
    {
      *pObjPos = HLA_PLUS_DEACT_REGION;
    }
    else if(ObjAng_rad > Ang_Act_rad)
    {
      *pObjPos = HLA_PLUS_ACT_REGION;
    }
    else
    {
      *pObjPos = HLA_PLUS_HOLD_REGION;
    }
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlusRegion_SetActDeactRegion                      */ /*!
  @brief            set object position
  @description      


  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusRegion_SetActDeactRegion(  /* input */
                                              const HLAplusData_t               *pPlusData,
                                              HLA_t_Object                      *pObj,
                                              const HLA_t_CameraParameter       *pCamPar,
                                              const HLAplusActDeactRegionPar_t  *pActReg,
                                              const HLAplusActDeactRegionPar_t  *pDeactReg,
                                              const float32                     CurveLightRotAngle,
                                              const eHLAplusHeadlamp_t          eHeadlamp,
                                              const HLAFTrafficStyleOut_t       *pTrafficStyle,
                                              /* history */
                                              float32                           *pTimeToAct,
                                              float32                           *pTimeToDeact,
                                              /* output */
                                              HLAplusRegion_t                   *pObjPos,
                                              HLA_t_Object                      **ppObjPos,
                                              HLAplusObjectData_t               *pObjExt
                                           )
{
  float32           Ang_Deact;
  float32           Ang_Act;
  eHLAplusRegion_t  eObjPos;
  float32           timeToAct;  
  float32           timeToDeact;
  
    
  
  /* deactivation region */
  HLAPlusRegion_CalcActDeactRegionAngle( /* input */
                                         pObj,
                                         pDeactReg,
                                         CurveLightRotAngle,
                                         /* output */
                                         &Ang_Deact
                                       );
  
  /* activation region */
  HLAPlusRegion_CalcActDeactRegionAngle( /* input */
                                         pObj,
                                         pActReg,
                                         CurveLightRotAngle,
                                         /* output */
                                         &Ang_Act
                                       );

  
  /* determine activation/ deactivation region of track (x, y_center) */
  HLAPlusRegion_DetermineActDeactRegion( /* input */
                                         (pTrafficStyle->NormFactor * pObj->f32_ObjectHorAng_rad),
                                         Ang_Act,
                                         Ang_Deact,
                                         eHeadlamp,
                                         /* output */
                                         &eObjPos
                                       );
  
  /* get TTD (time to DEACT REGION) */
  /* get TTA (time to ACT REGION)   */
  HLAPlusRegion_GetTimeToActDeactRegion(/* input */
                                        pPlusData,
                                        pCamPar, 
                                        pObj,
                                        pTrafficStyle,
                                        Ang_Act,
                                        Ang_Deact,
                                        eHeadlamp,
                                        /* output */
                                        &timeToAct,    
                                        &timeToDeact
                                       );
  
  
   
  

  /* do not overwrite HLA_PLUS_HOLD_REGION with HLA_PLUS_ACT_REGION */
  if(    (pObjPos->eRegion == HLA_PLUS_HOLD_REGION)
      && (eObjPos   == HLA_PLUS_ACT_REGION)
    )
  {
    /* do nothing */
  }
  /* do not overwrite HLA_PLUS_DEACT_REGION with HLA_PLUS_ACT_REGION  */
  /*                                          or HLA_PLUS_HOLD_REGION */
  else if(   (pObjPos->eRegion == HLA_PLUS_DEACT_REGION)
          && (  (eObjPos   == HLA_PLUS_ACT_REGION)
              ||(eObjPos   == HLA_PLUS_HOLD_REGION)
             )
         )
  {
    /* do nothing */
  }
  else
  {
    /* save data of outermost object */
    if(pObjPos->eRegion != HLA_PLUS_DEACT_REGION) 
    {
      /* first object in deactivation region detected */
      pObjPos->eRegion  = eObjPos;
      *ppObjPos         = pObj;
    }
    else
    {
      /* more than one object in deactivation region detected */
      /* save data of outermost object                        */

      if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
      {
        /* left headlamp:        */
        /* take most left object */

        /* take object with min TTD */
        if(timeToDeact < *pTimeToDeact)
        {
          pObjPos->eRegion  = eObjPos;
          *ppObjPos         = pObj;
        }
      }
      else 
      {
        /* right headlamp:        */
        /* take most right object */
        /* take object with min TTD */
        if(timeToDeact < *pTimeToDeact)
        {
          pObjPos->eRegion  = eObjPos;
          *ppObjPos         = pObj;
        }
      }
    }
  }


  /* set output */
  /* save extended object features */
  if(pObjExt != NULL)
  {
    pObjExt->TimeToActRegion_s    = timeToAct;
    pObjExt->TimeToDeactRegion_s  = timeToDeact;
    pObjExt->eObjRegion           = eObjPos;
  } 

  *pTimeToAct   = timeToAct;
  *pTimeToDeact = timeToDeact;
}


/* **************************************************************************** 
  Functionname:     HLAPlus2AnalyzeVehiclePosition                       */ /*!
  @brief            analyze vehicle position 
  @description      vehicle found in deactivation/ hold or activation region


  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAPlusRegion_VehiclePosition( const HLAF_t_RequiredInputs *pIn,
                                    const HLAplusInputData_t    *pPlusInput,
                                    const HLAFData_t            *pFData,
                                    HLAplusData_t               *pPlusData,
                                    const HLAplusParameters_t   *pPar,
                                    eHLAplusHBState_t           eHBState_Left,
                                    eHLAplusHBState_t           eHBState_Right
                                  )
{
  float32                       timeToAct_left;
  float32                       timeToAct_right;
  float32                       timeToDeact_left;
  float32                       timeToDeact_right;
  const HLAplusActDeactRegionPar_t   *pActReg_left_preced,   *pActReg_right_preced;
  const HLAplusActDeactRegionPar_t   *pDeactReg_left_preced, *pDeactReg_right_preced;
  const HLAplusActDeactRegionPar_t   *pActReg_left_oncom,    *pActReg_right_oncom;
  const HLAplusActDeactRegionPar_t   *pDeactReg_left_oncom,  *pDeactReg_right_oncom;
  uint32 i;
  

  /* reset output data */
  /* oncoming vehicle  */
  /* lost or alive */
  pPlusData->Region.RegionOncom_left.eRegion        = HLA_PLUS_NO_OBJ;
  pPlusData->Region.RegionOncom_right.eRegion       = HLA_PLUS_NO_OBJ;
  pPlusData->Region.pObjOncom_left                  = (HLA_t_Object*)NULL;
  pPlusData->Region.pObjOncom_right                 = (HLA_t_Object*)NULL;
  /* only alive */
  pPlusData->Region.RegionOncom_Alive_left.eRegion  = HLA_PLUS_NO_OBJ;
  pPlusData->Region.RegionOncom_Alive_right.eRegion = HLA_PLUS_NO_OBJ;
  pPlusData->Region.pObjOncom_Alive_left            = (HLA_t_Object*)NULL;
  pPlusData->Region.pObjOncom_Alive_right           = (HLA_t_Object*)NULL;
  
  /* preceding vehicle */
  /* lost or alive */
  pPlusData->Region.RegionPreced_left.eRegion       = HLA_PLUS_NO_OBJ;
  pPlusData->Region.RegionPreced_right.eRegion      = HLA_PLUS_NO_OBJ;
  pPlusData->Region.pObjPreced_left                 = (HLA_t_Object*)NULL;
  pPlusData->Region.pObjPreced_right                = (HLA_t_Object*)NULL;
  /* only alive */
  pPlusData->Region.RegionPreced_Alive_left.eRegion = HLA_PLUS_NO_OBJ;
  pPlusData->Region.RegionPreced_Alive_right.eRegion= HLA_PLUS_NO_OBJ;
  pPlusData->Region.pObjPreced_Alive_left           = (HLA_t_Object*)NULL;
  pPlusData->Region.pObjPreced_Alive_right          = (HLA_t_Object*)NULL;
  
  pPlusData->Region.MaxTimeToAct_left_s             = 0.0f;
  pPlusData->Region.MaxTimeToAct_right_s            = 0.0f;
  /* ~CodeReview ~ID:003928042b901897fa178efbfc722cec ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
  pPlusData->Region.MinTimeToDeact_left_s           = 100.0f;
  pPlusData->Region.MinTimeToDeact_right_s          = 100.0f;
  pPlusData->Region.pObj_MinTimeToDeact_left        = (HLA_t_Object*)NULL;
  pPlusData->Region.pObj_MinTimeToDeact_right       = (HLA_t_Object*)NULL;


  pPlusData->Region.PotOncoming_left            = 0;
  pPlusData->Region.PotOncoming_right           = 0;

  pPlusData->Region.RelevantVehicle             = 0.0f;
  
  /* initialize variables       */

  /* select activation / deactivation region parameter set */
  if(pFData->DecisionOut.Motorway.eStateInt == RTE_HLAF_MTWY_MOTORWAY)
  {
    /* motorway */
    pDeactReg_left_preced  = &pPar->Left.RegPreced_Motorway.DeactRegion;
    pDeactReg_right_preced = &pPar->Right.RegPreced_Motorway.DeactRegion;

    pDeactReg_left_oncom   = &pPar->Left.RegOncom_Motorway.DeactRegion;
    pDeactReg_right_oncom  = &pPar->Right.RegOncom_Motorway.DeactRegion;
    
    if(pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_OFF)
    {
      /* HB off */
      pActReg_left_preced  = &pPar->Left.RegPreced_Motorway.ActRegion_LowBeam;
      pActReg_left_oncom   = &pPar->Left.RegOncom_Motorway.ActRegion_LowBeam;
    }
    else if(pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* full HB on */
      pActReg_left_preced  = &pPar->Left.RegPreced_Motorway.ActRegion_HighBeam;
      pActReg_left_oncom   = &pPar->Left.RegOncom_Motorway.ActRegion_HighBeam;
    }
    else
    {
      /* Spot or partial HB on */
      pActReg_left_preced  = &pPar->Left.RegPreced_Motorway.DeactRegion;
      pActReg_left_oncom   = &pPar->Left.RegOncom_Motorway.DeactRegion;
    }
    if(pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
    {
      /* HB off */
      pActReg_right_preced = &pPar->Right.RegPreced_Motorway.ActRegion_LowBeam;
      pActReg_right_oncom  = &pPar->Right.RegOncom_Motorway.ActRegion_LowBeam;
    }
    else if(pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* full HB on */
      pActReg_right_preced = &pPar->Right.RegPreced_Motorway.ActRegion_HighBeam;
      pActReg_right_oncom  = &pPar->Right.RegOncom_Motorway.ActRegion_HighBeam;
    }
    else
    {
      /* Spot or partial HB on */
      pActReg_right_preced = &pPar->Right.RegPreced_Motorway.DeactRegion;
      pActReg_right_oncom  = &pPar->Right.RegOncom_Motorway.DeactRegion;
    }
  }
  else
  {
    /* country road */
    pDeactReg_left_preced  = &pPar->Left.RegPreced.DeactRegion;
    pDeactReg_right_preced = &pPar->Right.RegPreced.DeactRegion;

    pDeactReg_left_oncom   = &pPar->Left.RegOncom.DeactRegion;
    pDeactReg_right_oncom  = &pPar->Right.RegOncom.DeactRegion;

    if(pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_OFF)
    {
      /* HB off */
      pActReg_left_preced  = &pPar->Left.RegPreced.ActRegion_LowBeam;
      pActReg_left_oncom   = &pPar->Left.RegOncom.ActRegion_LowBeam;
    }
    else if (pPlusData->Out.eHighBeamState_Lt == RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* full HB on */
      pActReg_left_preced  = &pPar->Left.RegPreced.ActRegion_HighBeam;
      pActReg_left_oncom   = &pPar->Left.RegOncom.ActRegion_HighBeam;
    }
    else
    {
      /* Spot or partial HB on */
      pActReg_left_preced  = &pPar->Left.RegPreced.DeactRegion;
      pActReg_left_oncom   = &pPar->Left.RegOncom.DeactRegion;
    }
    if(pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_OFF)
    {
      /* HB off */
      pActReg_right_preced = &pPar->Right.RegPreced.ActRegion_LowBeam;
      pActReg_right_oncom  = &pPar->Right.RegOncom.ActRegion_LowBeam;
    }
    else if(pPlusData->Out.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON)
    {
      /* full HB on */
      pActReg_right_preced = &pPar->Right.RegPreced.ActRegion_HighBeam;
      pActReg_right_oncom  = &pPar->Right.RegOncom.ActRegion_HighBeam;
    }
    else
    {
      /* Spot or partial HB on */
      pActReg_right_preced = &pPar->Right.RegPreced.DeactRegion;
      pActReg_right_oncom  = &pPar->Right.RegOncom.DeactRegion;
    }
  }
  /* save current activation/ deactivation region parameter */
  /* preceding vehicle */
  pPlusData->Region.pActReg_right_preced    = pActReg_right_preced;
  pPlusData->Region.pActReg_left_preced     = pActReg_left_preced;
  pPlusData->Region.pDeactReg_left_preced   = pDeactReg_left_preced;
  pPlusData->Region.pDeactReg_right_preced  = pDeactReg_right_preced;
  /* oncoming vehicle */
  pPlusData->Region.pActReg_left_oncom      = pActReg_left_oncom;
  pPlusData->Region.pActReg_right_oncom     = pActReg_right_oncom;
  pPlusData->Region.pDeactReg_left_oncom    = pDeactReg_left_oncom;
  pPlusData->Region.pDeactReg_right_oncom   = pDeactReg_right_oncom;
  
  
  /* analyze the vehicle position */
  /* ~CodeReview ~ID:db285654924890fd819beae4a3c762a0 ~Reviewer:CW01\brunnm ~Date:17.07.2012 ~Priority:3 ~Comment:"i" could be out of array - check ui32_NumVehicles */
  for(i=0; i< pIn->s_Sig.ps_ObjectList->ui32_NumVehicles; i++)
  {
    HLA_t_Object *pObj = &pIn->s_Sig.ps_ObjectList->as_Object[i];
    HLAplusObjectData_t *pObjExt_lt = &pPlusData->Object.Left.Obj[i];
    HLAplusObjectData_t *pObjExt_rt = &pPlusData->Object.Right.Obj[i];
            

    timeToAct_left    = 0.0f;
    timeToAct_right   = 0.0f;
    timeToDeact_left  = 100.0f;
    timeToDeact_right = 100.0f;

    /**************************/
    /* lost or alive vehicles */
    /**************************/
    if(pObj->s_Status.isVehicleAhead == 1)
    {
      /* ahead traffic */
      /* left side     */
      if(pObjExt_lt->Status.isRelevantTraffic == 1)
      {
        HLAPlusRegion_SetActDeactRegion( /* input */
                                         pPlusData,
                                         pObj,
                                         pIn->s_Par.ps_CameraParameter,
                                         pActReg_left_preced,
                                         pDeactReg_left_preced,
                                         pPlusInput->OffsetAngle_left,
                                         HLA_PLUS_LEFT_HEADLAMP,
                                         &pFData->DecisionOut.TrafficStyle,
                                         /* history */
                                         &timeToAct_left,
                                         &timeToDeact_left,
                                         /* output */
                                         &pPlusData->Region.RegionPreced_left,
                                         &pPlusData->Region.pObjPreced_left,
                                         pObjExt_lt 
                                       );
      }
     
      /* right side */
      if(pObjExt_rt->Status.isRelevantTraffic == 1)
      {
        HLAPlusRegion_SetActDeactRegion( /* input */
                                         pPlusData,
                                         pObj,
                                         pIn->s_Par.ps_CameraParameter,
                                         pActReg_right_preced,
                                         pDeactReg_right_preced,
                                         pPlusInput->OffsetAngle_right,
                                         HLA_PLUS_RIGHT_HEADLAMP,
                                         &pFData->DecisionOut.TrafficStyle,
                                         /* history */
                                         &timeToAct_right,
                                         &timeToDeact_right,
                                         /* output */
                                         &pPlusData->Region.RegionPreced_right,
                                         &pPlusData->Region.pObjPreced_right,
                                         pObjExt_rt
                                       );
      }
    }
    else
    {
      /* oncoming traffic detected */
      /* left side */
      if(pObjExt_lt->Status.isRelevantTraffic == 1)
      {
        HLAPlusRegion_SetActDeactRegion( /* input */
                                         pPlusData,
                                         pObj,
                                         pIn->s_Par.ps_CameraParameter,
                                         pActReg_left_oncom,
                                         pDeactReg_left_oncom,
                                         pPlusInput->OffsetAngle_left,
                                         HLA_PLUS_LEFT_HEADLAMP,
                                         &pFData->DecisionOut.TrafficStyle,
                                         /* history */
                                         &timeToAct_left,
                                         &timeToDeact_left,
                                         /* output */
                                         &pPlusData->Region.RegionOncom_left,
                                         &pPlusData->Region.pObjOncom_left,
                                         pObjExt_lt
                                       );
      }
      /* right side */
      if(pObjExt_rt->Status.isRelevantTraffic == 1)
      {
        HLAPlusRegion_SetActDeactRegion( /* input */
                                         pPlusData,
                                         pObj,
                                         pIn->s_Par.ps_CameraParameter,
                                         pActReg_right_oncom,
                                         pDeactReg_right_oncom,
                                         pPlusInput->OffsetAngle_right,
                                         HLA_PLUS_RIGHT_HEADLAMP,
                                         &pFData->DecisionOut.TrafficStyle,
                                         /* history */
                                         &timeToAct_right,
                                         &timeToDeact_right,
                                         /* output */
                                         &pPlusData->Region.RegionOncom_right,
                                         &pPlusData->Region.pObjOncom_right,
                                         pObjExt_rt
                                       );
      }
    }
    
    /***********************/
    /* only alive vehicles */
    /***********************/
    if(pObj->ui8_lost_time == 0)
    {
      if(pObj->s_Status.isVehicleAhead == 1)
      {
        /* ahead traffic */
        /* left side */
        if(pObjExt_lt->Status.isRelevantTraffic == 1)
        {
          HLAPlusRegion_SetActDeactRegion(  /* input */
                                            pPlusData,
                                            pObj,
                                            pIn->s_Par.ps_CameraParameter,
                                            pActReg_left_preced,
                                            pDeactReg_left_preced,
                                            pPlusInput->OffsetAngle_left,
                                            HLA_PLUS_LEFT_HEADLAMP,
                                            &pFData->DecisionOut.TrafficStyle,
                                            /* history */
                                            &timeToAct_left,
                                            &timeToDeact_left,
                                            /* output */
                                            &pPlusData->Region.RegionPreced_Alive_left,
                                            &pPlusData->Region.pObjPreced_Alive_left,
                                            (HLAplusObjectData_t*)NULL 
                                         );
        }       

        /* right side */
        if(pObjExt_rt->Status.isRelevantTraffic == 1)
        {
          HLAPlusRegion_SetActDeactRegion(/* input */
                                          pPlusData,
                                          pObj,
                                          pIn->s_Par.ps_CameraParameter,
                                          pActReg_right_preced,
                                          pDeactReg_right_preced,
                                          pPlusInput->OffsetAngle_right,
                                          HLA_PLUS_RIGHT_HEADLAMP,
                                          &pFData->DecisionOut.TrafficStyle,
                                          /* history */
                                          &timeToAct_right,
                                          &timeToDeact_right,
                                          /* output */
                                          &pPlusData->Region.RegionPreced_Alive_right,
                                          &pPlusData->Region.pObjPreced_Alive_right,
                                          (HLAplusObjectData_t*)NULL 
                                       );
        }
      }
      else
      {
        /* oncoming traffic detected */
        /* left side */
        if(pObjExt_lt->Status.isRelevantTraffic == 1)
        {
          HLAPlusRegion_SetActDeactRegion(/* input */
                                          pPlusData,
                                          pObj,
                                          pIn->s_Par.ps_CameraParameter,
                                          pActReg_left_oncom,
                                          pDeactReg_left_oncom,
                                          pPlusInput->OffsetAngle_left,
                                          HLA_PLUS_LEFT_HEADLAMP,
                                          &pFData->DecisionOut.TrafficStyle,
                                          /* history */
                                          &timeToAct_left,
                                          &timeToDeact_left,
                                          /* output */
                                          &pPlusData->Region.RegionOncom_Alive_left,
                                          &pPlusData->Region.pObjOncom_Alive_left,
                                          (HLAplusObjectData_t*)NULL 
                                       );
        }
       
        /* right side */
        if(pObjExt_rt->Status.isRelevantTraffic == 1)
        {
          HLAPlusRegion_SetActDeactRegion(/* input */
                                          pPlusData,
                                          pObj,
                                          pIn->s_Par.ps_CameraParameter,
                                          pActReg_right_oncom,
                                          pDeactReg_right_oncom,
                                          pPlusInput->OffsetAngle_right,
                                          HLA_PLUS_RIGHT_HEADLAMP,
                                          &pFData->DecisionOut.TrafficStyle,
                                          /* history */
                                          &timeToAct_right,
                                          &timeToDeact_right,
                                          /* output */
                                          &pPlusData->Region.RegionOncom_Alive_right,
                                          &pPlusData->Region.pObjOncom_Alive_right,
                                          (HLAplusObjectData_t*)NULL 
                                       );
        }
      }
    }
    
    /*************************************/
    /* detect potential oncoming vehicle */
    /*************************************/
    {
      /* left side */
      if(pObjExt_lt->Status.isRelevantTraffic == 1)
      {
        HLAPlusRegion_GetPotOncomingInDeactRegion(&pPar->Left.RegOncom,
                                                  pObj,
                                                  &pFData->DecisionOut.TrafficStyle,
                                                  pPlusInput->OffsetAngle_left,
                                                  &pPlusData->Region.PotOncoming_left,
                                                  HLA_PLUS_LEFT_HEADLAMP,
                                                  eHBState_Left
                                                 );
      }
      /* right side */
      if(pObjExt_rt->Status.isRelevantTraffic == 1)
      {
        HLAPlusRegion_GetPotOncomingInDeactRegion(&pPar->Right.RegOncom,
                                                  pObj,
                                                  &pFData->DecisionOut.TrafficStyle,
                                                  pPlusInput->OffsetAngle_right,
                                                  &pPlusData->Region.PotOncoming_right,
                                                  HLA_PLUS_RIGHT_HEADLAMP,
                                                  eHBState_Right
                                                 );
      }
    }

    /* update global time to activation */
    if(timeToAct_left > pPlusData->Region.MaxTimeToAct_left_s)
    {
      pPlusData->Region.MaxTimeToAct_left_s     = timeToAct_left;
    }
    if(timeToAct_right > pPlusData->Region.MaxTimeToAct_right_s)
    {
      pPlusData->Region.MaxTimeToAct_right_s     = timeToAct_right;
    }

    /* update global time to deactivation */
    if(timeToDeact_left < pPlusData->Region.MinTimeToDeact_left_s)
    {
      pPlusData->Region.MinTimeToDeact_left_s     = timeToDeact_left;
      pPlusData->Region.pObj_MinTimeToDeact_left  = pObj;
    }
    if(timeToDeact_right < pPlusData->Region.MinTimeToDeact_right_s)
    {
      pPlusData->Region.MinTimeToDeact_right_s     = timeToDeact_right;
      pPlusData->Region.pObj_MinTimeToDeact_right  = pObj;
    }
    
    /* update maximum ttb */
    pPlusData->Region.RelevantVehicle = CML_f_Max(pPlusData->Region.RelevantVehicle, (pObj->ui16_ttb18_ms*0.001f));
  }


  /* set distance and time since the object is detected in the current region */
  /* oncoming vehicles */
  HLAPlusRegion_SetRegionTimeDistance(HLA_PLUS_NO_OBJ,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionOncom_left
                                     );
  HLAPlusRegion_SetRegionTimeDistance(HLA_PLUS_NO_OBJ,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionOncom_right
                                     );
  HLAPlusRegion_SetRegionTimeDistance(pPlusData->Region.RegionOncom_left.eRegion,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionOncom_Alive_left
                                     );
  HLAPlusRegion_SetRegionTimeDistance(pPlusData->Region.RegionOncom_right.eRegion,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionOncom_Alive_right
                                     );
  /* preceding vehicles */
  HLAPlusRegion_SetRegionTimeDistance(HLA_PLUS_NO_OBJ,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionPreced_left
                                     );
  HLAPlusRegion_SetRegionTimeDistance(HLA_PLUS_NO_OBJ,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionPreced_right
                                     );
  HLAPlusRegion_SetRegionTimeDistance(pPlusData->Region.RegionPreced_left.eRegion,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionPreced_Alive_left
                                     );
  HLAPlusRegion_SetRegionTimeDistance(pPlusData->Region.RegionPreced_right.eRegion,
                                      pFData->CamData.ddistFwd_m,
                                      pFData->CamData.dtimeFwd_s,
                                      &pPlusData->Region.RegionPreced_Alive_right
                                     );
}
