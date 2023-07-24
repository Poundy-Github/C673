/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_calc_cutin_pot.c

DESCRIPTION:               This module inherits algorithms for cut-in potential
                            calculation

AUTHOR:                    Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474

CREATION DATE:             14.09.2016

VERSION:                   $Revision: 1.33 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_calc_cutin_pot Cutin potential
@ingroup sit
@brief          Calculation of the cutin potential is done in this module. \n\n
@{
*/
#ifdef FCT_SIMU
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#endif  /* FCT_SIMU */

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/* defines for detecting an unlikely cutin situation */
#define CUTIN_RADIUS_BLINDSPOTAREA            (3.0f)
#define CUTIN_MIN_TTC                         (1.6f)
#define CUTIN_MIN_TG                          (0.16f)
#define SIT_CUTIN_MAX_TTC                     (999.f)
#define SIT_CUTIN_MAX_TG                      (999.f)
#define SIT_CUTIN_INIT_BLINDSPOTOFFSET        (99.0f)
#define SIT_CUTIN_MAX_LONG_DIST_BLINDSPOT     (5.f)
/*! Tunnel probability threshold, above which tunnel specific behavior @min:0 @max: 1 */
#define MOR_TUNNEL_PROB_THRES                 (0.5f)

/* defines for sppressing LongPot in case no lateral velocity observed */
/* for prevention of toggling, do not suppress potential if in last cycle potential was already higher than x % */
#define SIT_CUTIN_MINPOT_HYTSTERESE  (50u)
/* minimal lateral velocity for calculating LongPotential */
#define SIT_CUTIN_MIN_LAT_VEL      (0.25f)

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
#define MOA_MIN_IL_FACTOR           ( 0.0f)   /*!< minimal scale factor for obj2ahead-inlap scaling */
#define MOA_MAX_IL_FACTOR           ( 1.0f)   /*!< maximal scale factor for obj2ahead-inlap scaling*/

#define MOA_OBJ2AHEAD_INLAP_MIN     (-0.75f)  /*!< minimal object to object ahead inlap value for scaling */
#define MOA_OBJ2AHEAD_INLAP_MAX     (-0.25f)  /*!< maximal object to object ahead inlap value for scaling */

#define MOA_OBJ2EGO_INLAP_MIN       (-0.3f)   /*!< minimal object to ego lane inlap value for scaling */
#define MOA_OBJ2EGO_INLAP_MAX       ( 0.3f)   /*!< maximal object to ego lane inlap value for scaling */
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
SET_MEMSEC_VAR(SITCutInObjData)
/* <ln_offset:+2 MISRA Rule 8.10: reviewer name: Hanel date: 07-09-2012 reason: not static, because struct is accessed in sim_swc_fct_draw.cpp */
SITCutInObjData_t SITCutInObjData[EM_N_OBJECTS]; // PRQA S 3408
/* date: 2015-05-18, reviewer: Lonard jaison manohar, reason: External Linkage, because struct is accessed in sim_swc_fct_draw.cpp */

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
#ifdef FCT_SIMU
SET_MEMSEC_VAR(SITCutInDebugObjData)
/*! SIT potential simulation extended debug data */
SITPotentialDebugData_t SITCutInDebugObjData;
/*! Pointer to the current debug info (used by potential calculation) */
SITPotentialObjDebugData_t * pSICutInDebugObj;
static SITCutInPotLatKinDebug_t * pDebugInfoLatKin;
static SITCutInPotMultiObjAnalyseDebug_t * pDebugInfoMultiObjAnalyse;

SET_MEMSEC_CONST(SITCutInDebugObjData_MeasInfo)
static const MEASInfo_t SITCutInDebugObjData_MeasInfo = 
{
  SIT_POTENTIAL_DEBUG_DATA_VADDR,  /* .VirtualAddress */
  sizeof(SITCutInDebugObjData),         /* .Length */
  OOI_MEAS_FUNC_ID,                /* .FuncID */
  OOI_MEAS_FUNC_CHAN_ID            /* .FuncChannelID */
};
#endif /* FCT_SIMU */


SET_MEMSEC_VAR(MOARampObj2ObjInlap)
static GDBLFunction_t MOARampObj2ObjInlap = {// PRQA S 3218
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */
  /* Minimaler Ausgangswert */
  MOA_MIN_IL_FACTOR, 
  /* Maximaler Ausgangswert */
  MOA_MAX_IL_FACTOR, 
  /* Steigung der Anpassungsgerade:        (Amax-Amin)/(Emax-Emin) */
  (MOA_MAX_IL_FACTOR - MOA_MIN_IL_FACTOR) / (MOA_OBJ2AHEAD_INLAP_MAX - MOA_OBJ2AHEAD_INLAP_MIN), 
  /* Achsabschnitt der Anpassungsgerade: Amin - (Amax-Amin)/(Emax-Emin) * Emin */
  MOA_MIN_IL_FACTOR - ( ((MOA_MAX_IL_FACTOR - MOA_MIN_IL_FACTOR)/(MOA_OBJ2AHEAD_INLAP_MAX - MOA_OBJ2AHEAD_INLAP_MIN)) * MOA_OBJ2AHEAD_INLAP_MIN) 
};

SET_MEMSEC_VAR(MOARampObj2EgoInlap)
static GDBLFunction_t MOARampObj2EgoInlap = {// PRQA S 3218
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */
  /* Minimaler Ausgangswert */
  MOA_MIN_IL_FACTOR, 
  /* Maximaler Ausgangswert */
  MOA_MAX_IL_FACTOR, 
  /* Steigung der Anpassungsgerade:        (Amax-Amin)/(Emax-Emin) */
  (MOA_MAX_IL_FACTOR - MOA_MIN_IL_FACTOR) / (MOA_OBJ2EGO_INLAP_MAX - MOA_OBJ2EGO_INLAP_MIN), 
  /* Achsabschnitt der Anpassungsgerade: Amin - (Amax-Amin)/(Emax-Emin) * Emin */
  MOA_MIN_IL_FACTOR - ( ((MOA_MAX_IL_FACTOR - MOA_MIN_IL_FACTOR)/(MOA_OBJ2EGO_INLAP_MAX - MOA_OBJ2EGO_INLAP_MIN)) * MOA_OBJ2EGO_INLAP_MIN) 
};

#ifdef FCT_SIMU
/*! SIT potential simulation extended debug data */
extern SITPotentialDebugData_t SITCutInDebugObjData;
#endif /* FCT_SIMU */
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
static ObjNumber_t SIT_s_SelectNextLongObjectMoving(ObjNumber_t CurrentObjID);
static float32 SIT_f_EvaluateObj2AheadInlap(ObjNumber_t ObjId, ObjNumber_t obj_ahead);
static uint8 SIT_u_CalcCutInFromMultiObjectAnalyse(ObjNumber_t ObjId);
static float32 SIT_f_CutInCalcTTC(const ObjNumber_t ObjId);
static float32 SIT_f_CutInCalcTG(const ObjNumber_t ObjId);
static boolean SIT_b_CutInCheckLatPos(const ObjNumber_t ObjId);
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */

/*************************************************************************************************************************
  Functionname:    SIT_u_CutInPotCalcKinematic                                                                 */ /*!

  @brief           Calculate cut-in potential

  @description     Calculates the cut-in potential based on Total time to inlap.

                   @startuml
                   Partition SIT_u_CutInPotCalcKinematic{
                   Start
                   : Get TTIFull_Calculated, Low Threshold, Time Factor;
                   : Get the Total TTI;
                   : Calculate cutin potential;
                   End
                   }
                   @enduml

  @return          f_Cut_in_pot : calculated cut in potential value in percent [0u ... 100u]

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_LAInput.pt_TotalTimeToInlap(ObjId) :              []
  @glob_in         pt_SITInput->t_LAInput.pt_PredTimeThreshold(ObjId) :              []

  @glob_out        None

  @pre             ObjId passed has to belong to a valid object
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    375:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-375-00061542 \n
                   376:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-376-00061542 \n
                   379:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-379-00061542 \n

  @created         17.05.2018
  @changed         17.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
uint8 SIT_u_CutInPotCalcKinematic(const ObjNumber_t ObjId)
{
  float32 f_Cut_in_pot;
  fTime_t t_TTIFull_Calculated = *(pt_SITInput->t_LAInput.pt_TotalTimeToInlap(ObjId));
  /* 100 percent potential line */
  float32 f_PredTimeLowThres = *(pt_SITInput->t_LAInput.pt_PredTimeThreshold(ObjId)); 
  /* 0 percent potential line */
  float32 f_PredTimeHighThres; 
  float32 f_PredTimeFactor = SIT_POT_PRED_TIME_FAC;
  GDBLFunction_t SIT_Cutin_Potential;

#if (SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE)
  percentage_t TurnLightsStateConf = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].t_CamObjectData.t_TurnLightsStateConf;
  FIP_t_CamTurnLightsState TurnLightsState = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].t_CamObjectData.eTurnLightsState;
  float32 f_ObjVrelY = *pt_SITInput->t_RTE.pf_ObjVrelY(ObjId);

  if ( (TurnLightsStateConf > (percentage_t)LA_TURNIND_CONF_MIN)
     &&( ( (TurnLightsState == FIP_CAM_TURN_LIGHT_RIGHT) 
         &&(f_ObjVrelY < -LA_TURNIND_VRELY_THRES)
         )
       ||( (TurnLightsState == FIP_CAM_TURN_LIGHT_LEFT) 
         &&(f_ObjVrelY > LA_TURNIND_VRELY_THRES)
         )
       )
     )
  {  
    f_PredTimeFactor = SIT_POT_PRED_TIME_FAC_TURNIND;
  }
#endif

  /* Low Threshold already hold information about prediction quality
     We use this information also for the High Threshold */
#if SIT_CUTIN_POT_LIMIT
  f_PredTimeHighThres  = MIN_FLOAT(f_PredTimeLowThres * f_PredTimeFactor, SIT_POT_HIGH_PRED_LIMIT);
#else
  f_PredTimeHighThres  = f_PredTimeLowThres * f_PredTimeFactor;
#endif
/* Cut-in potential is computed only in case LA predicts the object lane */
  if (f_PredTimeLowThres < C_F32_DELTA)
  {
    f_Cut_in_pot = SIT_CUT_IN_OUT_POT_MIN;
  }
  /* Check is added to prevent division-by-zero when f_PredTimeLowThres is above f_PredTimeHighThres */
  else if ( ( f_PredTimeHighThres - f_PredTimeLowThres ) > C_F32_DELTA ) 
  {
    /*!< A1 */
    SIT_Cutin_Potential.dAmax = SIT_CUT_IN_OUT_POT_MIN;

    /*!< A2 */
    SIT_Cutin_Potential.dAmin = SIT_CUT_IN_OUT_POT_MAX;

    /*! (A2-A1)/(E2-E1) */
    SIT_Cutin_Potential.dM = ( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( f_PredTimeLowThres - f_PredTimeHighThres );

    /*! A1 - (A2-A1)/(E2-E1) * E1 */
    SIT_Cutin_Potential.dB = SIT_CUT_IN_OUT_POT_MIN -( (( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( f_PredTimeLowThres - f_PredTimeHighThres ) * f_PredTimeHighThres));

    /*! Calculate cutin potential */
    f_Cut_in_pot = dGDBmathLineareFunktion(&SIT_Cutin_Potential, (float32)(t_TTIFull_Calculated));
  }
  else
  {
    /* f_PredTimeLowThres is above f_PredTimeHighThres */
    /* This case shall be avoided by parametrization: f_PredTimeLowThres which is computed in LA should always be less than f_PredTimeHighThres */
    /* In case it happens nevertheless, set potential to maximum. */
    f_Cut_in_pot = SIT_CUT_IN_OUT_POT_MAX;
  }

  return (uint8)f_Cut_in_pot;
}

/*************************************************************************************************************************
  Functionname:    SIT_u_CutInPotCalcDist                                                                 */ /*!

  @brief           Calculate cut-in potential

  @description     Calculates the cut-in potential based on Distance to inlap.

                    @startuml
                    Partition SIT_u_CutInPotCalcDist{
                    Start
                        : Get the Total Distance to Inlap;
                        : Calculate cutin potential;
                    End
					}
                    @enduml

  @return          f_Cut_in_pot : calculated cut in potential value in percent [0u ... 100u]

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_LAInput.pt_f_DistanceToInlap(ObjId) :              []

  @glob_out        None

  @pre             ObjId passed has to belong to a valid object
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    377:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-377-00061542 \n
                   378:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-378-00061542 \n
                   380:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-380-00061542 \n

  @created         10.08.2018
  @changed         10.08.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com |
  *************************************************************************************************************************/
uint8 SIT_u_CutInPotCalcDist(const ObjNumber_t ObjId)
{
  float32 f_Cut_in_pot;
  float32 f_TotalDistanceToInlap;
  GDBLFunction_t SIT_Cutin_Potential;

  /*! Get the Distance to Inlap */
  f_TotalDistanceToInlap =  *(pt_SITInput->t_LAInput.pt_f_TotalDistanceToInlap(ObjId));

  /*!< A1 */
  SIT_Cutin_Potential.dAmax = SIT_CUT_IN_OUT_POT_MIN; 

  /*!< A2 */
  SIT_Cutin_Potential.dAmin = SIT_CUT_IN_OUT_POT_MAX;

  /*! (A2-A1)/(E2-E1) */
  SIT_Cutin_Potential.dM = ( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_LOWER - SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER);

  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  SIT_Cutin_Potential.dB = SIT_CUT_IN_OUT_POT_MIN -( (( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_LOWER - SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER) * SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER));

  /*! Calculate cutin potential */
  f_Cut_in_pot = dGDBmathLineareFunktion(&SIT_Cutin_Potential, f_TotalDistanceToInlap);

  return (uint8)f_Cut_in_pot;
}



/*************************************************************************************************************************
  Functionname:    SIT_u_CutInPotFusion                                                                           */ /*!

  @brief           Fuses all cut In potential information

  @description     Fuses all cut In potential information from camera, kinematics and Multi Object analyse.

                   @startuml
                   Partition SIT_u_CutInPotFusion{
                   Start
                   : get values for detecting a situation which is very unlikely for a cutin;
                   : if the kinematic relation of ego vehicle and object are unlikely for a cutin then\n do not calculate potential;
                   : Additive Fusion;
                   : Camera cutin potential;
                   End
                   }
                   @enduml

  @return          u_Potential_fused: Fused cut In potential information.

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]
                   u_KinematicCutInPot: Integer containing Kinematic CutIn Potential
                   u_PotentialDistanceCutInOut:Integer containing CutIn Potential based on distance 

  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i                  [-330.f ... 330.f] m/s
  @glob_in         *SLATE_pt_GetObjClassification(i) : object class                              [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability : Probability that the current state is tunnel [0.f ... 1.f]
  @glob_in         pt_SITInputModify->t_LAInputModify.pt_ObjLaneState(ObjId)->In2OutlaneTransition  : Outlane timer of object i  [0 ... LA_IN2OUTLANE_MAX_TRANSITIONTIME
  @glob_in         pt_SITInput : Reference to SIT input data structure
                        t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m       
                        t_LAInput.pf_ObjToRefDistFiltVar : Pointer to variance of object to reference distance measurement                        [0 ... PI/2*RW_FCT_MAX] m          
                        t_LAInput.pf_ObjToRefDistGradFilt : Pointer to gradient filter of object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m    
                        t_LAInput.pf_ObjToRefDistGradFiltVar : Pointer to variance of gradient filter of object to reference distance measurement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
  @glob_out        SITCutInObjData[ObjId].PotentialLateralKinematics value in percent  [0 ... 100]
  @glob_out        SITCutInObjData[ObjId].PotentialMultiObjectAnalyse value in percent [0 ... 100]


  @c_switch_part   FCT_SIMU : Simulation config switch
  @c_switch_part   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE : Configuration switch to enable multi object analyse as one input for the cutin potential
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component

  @pre             ObjId passed has to belong to a valid object
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.05.2018

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
uint8 SIT_u_CutInPotFusion(const ObjNumber_t ObjId, const uint8 u_KinematicCutInPot, const uint8 u_PotentialDistanceCutInOut)
{
  uint8 u_Potential_fused;

#if FCT_CFG_CAMERA_CUTIN_POTENTIAL 
  uint8 u_Potential_Camera;
#endif

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
  uint8 uiPotential_MultiObjectAnalyse;
  float32 ttc_ego_obj;
  float32 tg_ego_obj;
  boolean plausible_lateral_position;
  float32 f_ObjVrelX = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId);

#ifdef FCT_SIMU
  pSICutInDebugObj = &SITCutInDebugObjData.Objects[ObjId];
  pDebugInfoLatKin = &pSICutInDebugObj->LatKinPot;
  pDebugInfoMultiObjAnalyse = &pSICutInDebugObj->MultiObjAnalysePot;
  SITCutInDebugObjData.Objects[SLATE_p_GetFCTPubObj_OOI(ObjId)->eObjOOI].ObjID = ObjId;
#endif

  /* get values for detecting a situation which is very unlikely for a cutin */
  /* (compare ego kinematics to object kinematics) */
  plausible_lateral_position =   SIT_b_CutInCheckLatPos(ObjId);
  ttc_ego_obj = SIT_f_CutInCalcTTC(ObjId);
  tg_ego_obj = SIT_f_CutInCalcTG(ObjId);

  /* if the kinematic relation of ego vehicle and object are unlikely for a cutin */
  /* do not calculate potential */
  /* (this mainly avoids false positives in short distances) */
  /* no potential for trucks in tunnel */
  /* no potential for objects with In2OutlaneTransition > 0 */
  /* either the case after lane change or after object position has been behind road estimation */
  if(   (plausible_lateral_position == FALSE)
     || (   (f_ObjVrelX < -C_F32_DELTA)
         && (   (ttc_ego_obj < CUTIN_MIN_TTC)
             || (tg_ego_obj < CUTIN_MIN_TG) 
            ) 
        )
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
     || (*pt_SITInput->t_RTE.pf_TunnelProbability >= MOR_TUNNEL_PROB_THRES)
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
     || (pt_SITInputModify->t_LAInputModify.pt_ObjLaneState(ObjId)->In2OutlaneTransition > 0u ) 
#endif 
    )
  {
    uiPotential_MultiObjectAnalyse = 0u;
  }
  else
  {
    uiPotential_MultiObjectAnalyse  = SIT_u_CalcCutInFromMultiObjectAnalyse(ObjId);
  }

  if (uiPotential_MultiObjectAnalyse == 0u)
  {
    if(u_KinematicCutInPot < u_PotentialDistanceCutInOut)
    {
      u_Potential_fused = pt_SITOutput->t_ObjList[ObjId].u_ObjCutInPotential;
      u_Potential_fused = MIN(u_Potential_fused, u_PotentialDistanceCutInOut);
    }
    else
    {
      u_Potential_fused = u_KinematicCutInPot;
    }
  }
  else
  {
    /* Additive Fusion */
    u_Potential_fused = MAX(u_KinematicCutInPot, u_PotentialDistanceCutInOut) + uiPotential_MultiObjectAnalyse;
    u_Potential_fused = MIN(u_Potential_fused, 100u);
  }

  SITCutInObjData[ObjId].PotentialMultiObjectAnalyse = uiPotential_MultiObjectAnalyse;

#ifdef FCT_SIMU
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pSICutInDebugObj->fDistFromCourse     = *(pt_SITInput->t_LAInput.pf_ObjToRefDistMeas(ObjId)); 
  pSICutInDebugObj->fDistFromCourseVar  = *(pt_SITInput->t_LAInput.pf_ObjToRefDistFiltVar(ObjId));
  pSICutInDebugObj->fRelVelocityTraj    = *(pt_SITInput->t_LAInput.pf_ObjToRefDistGradFilt(ObjId));
  pSICutInDebugObj->fRelVelocityTrajVar = *(pt_SITInput->t_LAInput.pf_ObjToRefDistGradFiltVar(ObjId));
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */
  pSICutInDebugObj->fDistX                     = *pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId);
  pSICutInDebugObj->fRelVelX                   = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId);
  pSICutInDebugObj->ttc_ego_obj                = ttc_ego_obj;
  pSICutInDebugObj->tg_ego_obj                 = tg_ego_obj;
  pSICutInDebugObj->plausible_lateral_position = plausible_lateral_position;
  pSICutInDebugObj->fDistY                     = *pt_SITInput->t_RTE.pf_ObjLatDisp (ObjId);
  pSICutInDebugObj->CutinObjClass              = *SLATE_pt_GetObjClassification(ObjId);
#endif /* FCT_SIMU */
#else
  if(u_KinematicCutInPot < u_PotentialDistanceCutInOut)
  {
    u_Potential_fused = pt_SITOutput->t_ObjList[ObjId].u_ObjCutInPotential;
    u_Potential_fused = MIN(u_Potential_fused, u_PotentialDistanceCutInOut);
  }
  else
  {
    u_Potential_fused = u_KinematicCutInPot;
  }
#endif /* (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */

  /*!Camera cutin potential*/
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
  u_Potential_Camera = *(pt_SITInput->t_LAInput.pf_CameraCutInPotential(ObjId)); 
  u_Potential_fused = MAX(u_Potential_fused, u_Potential_Camera);
#endif

  /* Lowpass Filter of Cut-In Potential, only falling Flank is filtered, the false-positive rate of the u_ObjCutInPotential Signal is 
  low enough to consider only "loosing" the Signal (a falsely drop in the Signal).*/
  if (u_Potential_fused < pt_SITOutput->t_ObjList[ObjId].u_ObjCutInPotential)
  {
    u_Potential_fused = (uint8)GDB_FILTER((float32)u_Potential_fused,(float32)pt_SITOutput->t_ObjList[ObjId].u_ObjCutInPotential, SIT_CUTINPOT_FILT_CONST);
  }

  SITCutInObjData[ObjId].u_FusedCutinPotential = u_Potential_fused;

  return u_Potential_fused;
}

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
/*************************************************************************************************************************
  Functionname:    SIT_s_SelectNextLongObjectMoving                                                                     */ /*!

  @brief           Select Object ahead of input object

  @description     Select Object ahead of input object (in the same associated lane)

  @return          nextLongObjID : static Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

                   @startuml  {SIT_s_SelectNextLongObjectMoving.png}
                   start

                   :Check if object exists;

                   :Get object ID in longitudinal distance sorted list;
                   
                   repeat
                   :Get next object in longitudinal distance sorted list;

                   if(Next object is moving, has ACC quality and low time-gap distance and is on same lane as object) then (Yes)
                   :Next object has been found;                   
                   
                   else (No)
                   :Next object has not been found;
                   
                   endif

                   repeat while (next object has not been found and end of list not reached)

                   end
                   @enduml

  @param[in]       CurrentObjID : Object ID [0u ... EM_N_OBJECTS-1]

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i  [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in         *SLATE_pu_GetDistXSortedObj(iObjSorted) : Object sorted ID [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : ego vehicle speed                                [-330.f ... 330.f] m/s
  @glob_in         *pt_SITInput->t_RTE.pf_ObjLongDisp (i) : Longitudinal displacement of an object i     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i                        [-330.f ... 330.f] m/s
  @glob_in         OBJ_GET_ASSOCIATED_LANE(i) : associated lane information of an object i [eAssociatedLane_t as in Rte_Type.h]
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information [0 ... 100]
  @glob_in         SLATE_b_GetObjIsDeleted(iObj) : Boolean [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : Configuration switch for DRT project
  @c_switch_full   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE : Configuration switch to enable multi object analyse as one input for the cutin potential
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Nele Hanel | nele.hanel@contiautomotive.com | +49 (8382) 9699-401
*************************************************************************************************************************/
static ObjNumber_t SIT_s_SelectNextLongObjectMoving(ObjNumber_t CurrentObjID)
{
  ObjNumber_t iObjSorted;               /* Index in range sorted FCT list */
  float32 f_TimegapDistance;
  eAssociatedLane_t t_CurrentObjAssociatedLane;
  boolean b_found                       = FALSE;
  ObjNumber_t CurrentObjID_insortedList = OBJ_INDEX_NO_OBJECT;
  ObjNumber_t nextLongObjID             = OBJ_INDEX_NO_OBJECT;
  boolean b_CurrentObjIsDeleted         = pt_SITInput->t_RTE.b_ObjIsDeleted(CurrentObjID);
  SLATE_t_Obj_DynamicProperty t_CurrentObjDynProperty = *pt_SITInput->t_RTE.pt_ObjDynProperty(CurrentObjID);
#if (LA_CFG_DTR_OBJ_SELECTION)
  boolean b_DTRPreSelect = LA_b_DTRPreselectCrit(CurrentObjID);
#endif /* (LA_CFG_DTR_OBJ_SELECTION) */

  /* Check if object exists (is selected) */
  if (  (CurrentObjID != OBJ_INDEX_NO_OBJECT)
     && (!b_CurrentObjIsDeleted)
     && (t_CurrentObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) )
  {
    ObjNumber_t iNumOfUsedObjects = SLATE_t_GetNumOfObjectsUsed();

    /* find obj in sorted obj list */
    /* the x-distance sorted FCT list starts with the used objects and is filled up with -1  */
    /* loop until number of used objects */
    for(iObjSorted = 0; (iObjSorted < iNumOfUsedObjects) && (b_found == FALSE); iObjSorted++)
    {
      ObjNumber_t iSortedObjectList = *pt_SITInput->t_RTE.pu_DistXSortedObj(iObjSorted);

      if(iSortedObjectList == CurrentObjID)
      {
        CurrentObjID_insortedList = iObjSorted;
        b_found = TRUE;
      }
    }

    /* object position in range sorted FCT list is found */
    if(b_found == TRUE)
    {
      /* search all following objects for next longitudinal obj */
      b_found             = FALSE;
      f_TimegapDistance   = (*pt_SITInput->t_RTE.pf_ObjLongDisp (CurrentObjID)) + ((*pt_SITInput->t_RTE.pf_ObjVrelX(CurrentObjID) + *pt_SITInput->t_RTE.pf_EgoLongVel) * MOR_TIMEGAP_SELECTION_OBJ_AHEAD);
      t_CurrentObjAssociatedLane = *pt_SITInput->t_LAInput.pt_ObjAssociatedLane(CurrentObjID);

      /* In *SLATE_pu_GetDistXSortedObj(i) "empty" objects have index -1. */
      /* They are at the end of the list. That is why we loop over iNumOfUsedObjects */
      for(iObjSorted = CurrentObjID_insortedList + 1 ; (iObjSorted < iNumOfUsedObjects) && (b_found == FALSE); iObjSorted++)
      {
        /* Get index in normal FCT list */
        ObjNumber_t iObj = *pt_SITInput->t_RTE.pu_DistXSortedObj(iObjSorted);
        boolean b_ObjIsDeleted = pt_SITInput->t_RTE.b_ObjIsDeleted(iObj);
        SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *pt_SITInput->t_RTE.pt_ObjDynProperty(iObj);
        uint8 u_ObjACCQuality = pt_SITInput->t_RTE.pu_AccObjQuality(iObj);
        float32 f_ObjLongDisp = *pt_SITInput->t_RTE.pf_ObjLongDisp (iObj);
        eAssociatedLane_t t_ObjAssociatedLane = *pt_SITInput->t_LAInput.pt_ObjAssociatedLane(iObj);

        /* check lane association */
        if (   (!b_ObjIsDeleted)
            && (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
#if (LA_CFG_DTR_OBJ_SELECTION)
            && (b_DTRPreSelect == TRUE)
#else
            && (u_ObjACCQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
#endif /* (LA_CFG_DTR_OBJ_SELECTION) */
            && (f_ObjLongDisp <= f_TimegapDistance)
            && (t_ObjAssociatedLane == t_CurrentObjAssociatedLane)
           )
        {
          nextLongObjID = iObj;
          b_found       = TRUE;
        }
      }
    }

  }

  return nextLongObjID;
}


/*************************************************************************************************************************
  Functionname:    SIT_f_EvaluateObj2AheadInlap                                                                       */ /*!

  @brief           calculate a scaling factor for the cutin potential depending on the object to object ahead inlap

  @description     This function shall help to avoid false positive cutin potential in cases 
                   when the object ahead is falsely associated to LANE_LEFT/RIGHT instead of LANE_LEFT/RIGHT_FAR.
                   It checks the inlap of the object to the object ahead. 
                   If they have a negative inlap (means there is a gap between the to objects), it is less likely, that they are on the same lane.
                   Since the inlap will also decrease, if the obj really changes lanes from neighbour to ego, one also has to consider the object to ego inlap. 

                   On narrow lanes object on the neighbour lane often have a positive inlap to the ego lane although they do not intend to change lanes. 
                   Therefor on narrow lanes, the obj2ego inlap shall be considered less. 

                   @startuml
                   Partition SIT_f_EvaluateObj2AheadInlap{
                   Start
                   : Set the distance and object, Trajectory width values;
                   : Get ego lane inlap;
                   : calculate the scaling factor depending on object to object ahead inlap;
                   : calculate the scaling factor depending on object to ego lane inlap;
                   : set the resulting scaling factor;
                   : Return Scaling factor for the cutin potential;
                   End
                   }
                   @enduml

  @return          ramp_factor_inlap: Scaling factor for the cutin potential

  @param[in]       ObjId : Object ID                                        [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       obj_ahead : Object ahead ID                              [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_FIPOA.pf_GetObjWidthforCorridor    :   Object Width for corrdior calculations [0.f   10.f]
  @glob_in         pt_SITInput->t_LAInput.pf_SeekLaneWidth : Seek lane width variable                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m    
  @glob_out        -

  @c_switch_part   FCT_SIMU : Simulation config switch
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE : Configuration switch to enable multi object analyze as one input for the cutin potential
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @todo            choose a better parametrization / logic to distinguish between different lane widths. 
                  
                   Once object to object ahead connection is saved over the cycles:
                   Maybe observe the history of the obj2obj and obj2ego inlap. 
                   if the object really cuts out from the neighbour lane and cuts in onto the ego lane, 
                   the obj2obj overlay should decrease and the obj2ego inlap should increase. 

  @author          Nele Hanel | nele.hanel@contiautomotive.com | +49 (8382) 9699-401
*************************************************************************************************************************/
static float32 SIT_f_EvaluateObj2AheadInlap(ObjNumber_t ObjId, ObjNumber_t obj_ahead)
{
  float32 ramp_factor_inlap; 
  float32 obj2ego_inlap, obj2ahead_inlap; 
  float32 factor_o2e_il, factor_o2a_il;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  /* object (OOI-4/5) to ego lane inlap is already calculated in the lane association */
  obj2ahead_inlap = *pt_SITInput->t_LAInput.pf_ObjInLap(obj_ahead); 
  /* object (OOI-2/3) to ego lane inlap is already calculated in the lane association */
  obj2ego_inlap = *pt_SITInput->t_LAInput.pf_ObjInLap(ObjId);
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

  /* calculate the scaling factor depending on object to object ahead inlap */
  factor_o2a_il = dGDBmathLineareFunktion(&MOARampObj2ObjInlap, obj2ahead_inlap);

  /* calculate the scaling factor depending on object to ego lane inlap */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  if(*(pt_SITInput->t_LAInput.pf_SeekLaneWidth) >= LA_HIGHWAYLANEWIDTHSEEK_MIN)
  {
    factor_o2e_il = dGDBmathLineareFunktion(&MOARampObj2EgoInlap, obj2ego_inlap);
  }
  else /*(FCT_CFG_ACC_LANE_ASSOCIATION)*/
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */
  {
    /* narrow lanewidth */
    /* obj2ego inlap most times > 0, even if obj is driving stable on neighbour lane */
    factor_o2e_il = 0.0f;
  }
  
  /* set the resulting scaling factor */
  ramp_factor_inlap = MAX_FLOAT(factor_o2a_il, factor_o2e_il);

#ifdef FCT_SIMU
  /* write result to debug struct */
  pDebugInfoMultiObjAnalyse->obj2ahead_il = obj2ahead_inlap;
  pDebugInfoMultiObjAnalyse->obj2ego_il = obj2ego_inlap;
  pDebugInfoMultiObjAnalyse->ramp_il = ramp_factor_inlap;
#endif /* FCT_SIMU */

  return ramp_factor_inlap;
}

/*************************************************************************************************************************
  Functionname:    SIT_u_CalcCutInFromMultiObjectAnalyse                                                                */ /*!

  @brief           Calculate cut-in potential based on MOR algorithm

  @description     Calculate cut-in potential based on MOR algorithm
                   Multi Object Observer is designed for Highways only
                   It checks the velocity, distance and inlap relations of object and
                   object ahead

                   @startuml  {SIT_u_CalcCutInFromMultiObjectAnalyse.png}
                   start

                   :Check cut-in probability pre-conditions based on kinematic cut-in probability, velocity to trajectory, longitudinal distance, ego velocity;                        

                   partition "FCT_CFG_ROAD_INPUT and FCT_CFG_INPUT_PREPROCESSSING" {
                   :Compute cut-in probability only on highways;
                   }  

                   :Select Object ahead of input object (in the same associated lane)
                   <b>SIT_s_SelectNextLongObjectMoving</b>;                        

                   :Check that object ahead of input object exists and is moving;

                   :For object under consideration and the object ahead of it get distance to trajectory and variances;     

                   :For further consdierations both objects have to have similar velocity and lateral distance;    

                   :Dependent on object class compute the deltas of longitudinal distance, relative velocity and acceleration;      

                   :For further considerations both objects must not be too close to each other;  

                   :For further considerations objects must have truck, motorcycle or car classification;                                                                                                     

                   :Dependent on deltas of longitudinal distance, relative velocity and acceleration compute the enhanced time-to-collision (TTC) between objects;          

                   :Linearly ramp time-to-collision into a cut-in potential; 

                   :Scale the cut-in potential depending on the object to object ahead inlap
                   <b>SIT_f_EvaluateObj2AheadInlap</b>;     

                   :Scale the cut-in potential depending on the difference between the TTC between ego and object, and object and the object ahead of it;   

                   :Scale the cut-in potential depending on the relative velocities of the object and the object ahead of it;

                   :Scale the cut-in potential depending on the distance to tajectories of the object and the object ahead of it;

                   :Force the cut-in potential to reach 100% more easily when high enough; 

                   end
                   @enduml

  @return          cut_in_pot : static uint8, calculated potential value [0u ... 100u]

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : ego vehicle speed                            [-330.f ... 330.f] m/s
  @glob_in         OBJ_GET_CUT_IN_POTENTIAL(i) : old cut_in potential in percent       [0u ... 100u]
  @glob_in         pt_SITInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         *pt_SITInput->t_RTE.pf_ObjLongDisp (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i           [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in         OBJ_LONG_VREL(i) : Relative velocity of object i                    [-330.f ... 330.f] m/s
  @glob_in         *SLATE_pt_GetObjClassification(ObjId) : object class                            [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         pt_SITInput->t_FIPOA.pf_ObjAbsAccelX(i) : the absolute acceleration of the object i      [-100.f … +100.f] m/s2
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistMeas : Pointer to object to reference distance measurement                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m       
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistFiltVar : Pointer to variance of object to reference distance measurement                        [0 ... PI/2*RW_FCT_MAX] m          
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistGradFilt : Pointer to gradient filter of object to reference distance measurement                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m    
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistGradFiltVar : Pointer to variance of gradient filter of object to reference distance measurement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 

  @glob_out        -

  @c_switch_part   FCT_SIMU : Simulation config switch
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FCT_CFG_ROAD_INPUT : Compiler switch for Road estimation input to FCT
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE : Configuration switch to enable multi object analyse as one input for the cutin potential
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             ObjId passed has to belong to a valid object
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Mark Fiolka | Mark.Fiolka@contiautomotive.com
*************************************************************************************************************************/
static uint8 SIT_u_CalcCutInFromMultiObjectAnalyse(ObjNumber_t ObjId)
{
  float32 cut_in_pot = 0.f;
  float32 f_EgoLongVel = *pt_SITInput->t_RTE.pf_EgoLongVel;
  ObjNumber_t obj_ahead;
  float32 ttc_obj_ahead = 0.0f;
  float32 delta_dis = 0.0f;
  float32 delta_vel = 0.0f;
  float32 delta_acc = 0.0f;
  float32 dist_obj2traj;
  float32 dist_objahead2traj;
  float32 ttc_ego_obj;
  float32 factor_il;
  float32 ftemp_rampfactor; 
  float32 dist_to_traj, rel_vel_to_traj;
  uint8 foldPotential; 
  boolean bLatVelpresent = TRUE;
  float32 f_ObjLongDisp = *pt_SITInput->t_RTE.pf_ObjLongDisp(ObjId);

  foldPotential = *SIT_pu_GetCutInProbability(ObjId);
  /* ARS4D0 requirement: only allow LongPot in case that lateral velocity was observed */
  /* evaluation shows, that this supress also some false events, therefore activate for all projects */
  /* to avoid toggeling potential, only suppress new potential depending on relative velocity in case, the potential was not already high */
  /* because sometimes the lateral velocity in instable */
  if (foldPotential < SIT_CUTIN_MINPOT_HYTSTERESE)
  {
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
    dist_to_traj = *(pt_SITInput->t_LAInput.pf_ObjToRefDistMeas(ObjId));
    rel_vel_to_traj = *(pt_SITInput->t_LAInput.pf_ObjToRefDistGradFilt(ObjId));
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

    if (dist_to_traj <= 0.f)
    {
      if(rel_vel_to_traj < SIT_CUTIN_MIN_LAT_VEL)
      {
        bLatVelpresent = FALSE; 
      }
    }
    else
    {
      if(rel_vel_to_traj > (-SIT_CUTIN_MIN_LAT_VEL))
      {
        bLatVelpresent = FALSE; 
      }
    } 

  }

  /* Multi Object Observer is designed for Highways only, ignore Situations with ego speed under MOR_ACTIVE_MIN_SPEED,
  Object has a maximal distance of MOR_ACTIVE_MAX_DIST */
  if (
#if ((FCT_CFG_ROAD_INPUT) && (FCT_CFG_INPUT_PREPROCESSSING))
         ((pt_SITInput->pt_FIPRoadType->t_FIPFusedRoadType) == FIP_ROAD_TYPE_HIGHWAY ) &&
#endif /* ((FCT_CFG_ROAD_INPUT) && (FCT_CFG_INPUT_PREPROCESSSING)) */
         (f_EgoLongVel > MOR_ACTIVE_MIN_SPEED ) 
      && (f_ObjLongDisp < MOR_ACTIVE_MAX_DIST) 
      && (bLatVelpresent == TRUE) 
     )
  {
    obj_ahead = SIT_s_SelectNextLongObjectMoving(ObjId);

#ifdef FCT_SIMU
    /* write result to debug struct */
    pSICutInDebugObj->ObjID = ObjId;
    pSICutInDebugObj->nextLongObjID = obj_ahead;
#endif /* FCT_SIMU */

    /* Check if Object ahead is not the next long, moving Object */
    if (obj_ahead != OBJ_INDEX_NO_OBJECT)
    {
      SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *pt_SITInput->t_RTE.pt_ObjDynProperty(obj_ahead);

      if (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
      {
        float32 f_ObjVrelX = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId);
        float32 f_ObjAheadVrelX = *pt_SITInput->t_RTE.pf_ObjVrelX(obj_ahead);

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
        dist_obj2traj = *(pt_SITInput->t_LAInput.pf_ObjToRefDistMeas(ObjId));
        dist_objahead2traj = *(pt_SITInput->t_LAInput.pf_ObjToRefDistMeas(obj_ahead)); 
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

        /* Check if Object and Object ahead are faster than Ego-Vehicle -> they seem to be on the fast lane */
        if ( ((f_ObjVrelX + f_ObjAheadVrelX) < MOR_ACTIVE_RAMP_REL_VEL_MAX )
          && ( (fABS(dist_obj2traj) - fABS(dist_objahead2traj)) < MOR_ACTIVE_RAMP_OFFSET_LAT_MAX) )
        {
          SLATE_t_Obj_CLassification t_ObjClassification = *pt_SITInput->t_RTE.pt_ObjClassification(ObjId);
          SLATE_t_Obj_CLassification t_ObjAheadClassification = *pt_SITInput->t_RTE.pt_ObjClassification(obj_ahead);

          switch (t_ObjClassification)
          {
          case SLATE_OBJCLASS_MOTORCYCLE:
            delta_dis = *pt_SITInput->t_RTE.pf_ObjLongDisp (obj_ahead) - *pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId);
            delta_vel = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId) - *pt_SITInput->t_RTE.pf_ObjVrelX(obj_ahead);
            delta_acc = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].fAbsAcceleration - pt_SITInput->pt_FIPOA->t_ObjList[obj_ahead].fAbsAcceleration;
            break;

          case SLATE_OBJCLASS_CAR:
            delta_dis = *pt_SITInput->t_RTE.pf_ObjLongDisp (obj_ahead) - (*pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId) + MOR_OFFSET_LEN_CAR);
            delta_vel = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId) - *pt_SITInput->t_RTE.pf_ObjVrelX(obj_ahead);
            delta_acc = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].fAbsAcceleration - pt_SITInput->pt_FIPOA->t_ObjList[obj_ahead].fAbsAcceleration;
            break;
        
          case SLATE_OBJCLASS_TRUCK:
            delta_dis = *pt_SITInput->t_RTE.pf_ObjLongDisp (obj_ahead) - (*pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId) + MOR_OFFSET_LEN_TRUCK);
            delta_vel = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId) - *pt_SITInput->t_RTE.pf_ObjVrelX(obj_ahead);
            delta_acc = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].fAbsAcceleration - pt_SITInput->pt_FIPOA->t_ObjList[obj_ahead].fAbsAcceleration;

            if (((delta_dis + MOR_OFFSET_LEN_TRUCK) < MOR_MAX_DIST_TRUCK_CAB) 
              && (t_ObjAheadClassification != SLATE_OBJCLASS_CAR) 
              && (t_ObjAheadClassification != SLATE_OBJCLASS_TRUCK))
            {
              /* Object ahead seems to be the driver's cab */
              delta_dis = 0.f;
              delta_vel = 0.f;
              delta_acc = 0.f;
            }
            break;

          default:
            delta_dis = 0.f;
            delta_vel = 0.f;
            delta_acc = 0.f;
            break;
          }

          /* Do not use the Multi Object Observer if Object is to close to or to far from the Object ahead */
          if ( (delta_dis < MOR_ACTIVE_MIN_REL_DIST) || (delta_dis > MOR_ACTIVE_MAX_REL_DIST) )
          {
            delta_dis = 0.f;
            delta_vel = 0.f;
            delta_acc = 0.f;
          }

          /* Force delta_acc to be negative */
          if ( delta_acc > -C_F32_DELTA )
          {
            delta_acc = 0.f;
          }
        
          switch (t_ObjAheadClassification)
          {
          case SLATE_OBJCLASS_TRUCK:
          case SLATE_OBJCLASS_MOTORCYCLE:
          case SLATE_OBJCLASS_CAR:
#ifdef FCT_SIMU
    pDebugInfoMultiObjAnalyse->ahead_veh = 1u;
#endif /* FCT_SIMU */

            if ((delta_dis < MOR_ETTC_RAMP_MAX_DIST) 
              && (delta_acc < -C_F32_DELTA) /*!< We only need object with negative delta ACC (already limited above) */
              && (delta_vel > C_F32_DELTA) 
              && (fABS((delta_vel*delta_vel)+(2.f*delta_acc*delta_dis)) > C_F32_DELTA))
            {
              /* Enhanced Time to Collision */
              if ( ((delta_vel*delta_vel)+(2.f*delta_acc*delta_dis)) > C_F32_DELTA )
              {
                /* <ln_offset:+1 MISRA Rule 1.2: reviewer name: Hanel date: 28-03-2012 reason: delta_acc is checked above for not being close to zero */
                ttc_obj_ahead = (SQRT_((delta_vel*delta_vel) + (2.f*delta_acc*delta_dis)) - delta_vel) / delta_acc;
#ifdef FCT_SIMU
                pDebugInfoMultiObjAnalyse->ttc_case = 1u;
#endif /* FCT_SIMU */
              }
              else
              {
                /* Object will not reach Object ahead => set ETTC to MOR_MAX_TTC_VALUE */
                ttc_obj_ahead = MOR_MAX_TTC_VALUE;
#ifdef FCT_SIMU
                pDebugInfoMultiObjAnalyse->ttc_case = 2u;
#endif /* FCT_SIMU */
              }
              /* Build a linear transition between TTC and ETTC in range MOR_ETTC_RAMP_MIN_DIST to MOR_ETTC_RAMP_MAX_DIST */
              if ( delta_dis > MOR_ETTC_RAMP_MIN_DIST )
              {
                /* <ln_offset:+1 MISRA Rule 1.2: reviewer name: Hanel date: 28-03-2012 reason: divisors are checked above for not being close to zero */
                ttc_obj_ahead = (((delta_dis-MOR_ETTC_RAMP_MIN_DIST)/MOR_ETTC_RAMP_LENGTH)*(delta_dis/delta_vel)) + ((1.f-((delta_dis-MOR_ETTC_RAMP_MIN_DIST)/MOR_ETTC_RAMP_LENGTH))*ttc_obj_ahead);
#ifdef FCT_SIMU
                pDebugInfoMultiObjAnalyse->ttc_case = 3u;
#endif /* FCT_SIMU */
              }
            }
            else
            {
              if (delta_vel > C_F32_DELTA) 
              {
                /* Time to Collision */
                /* <ln_offset:+1 MISRA Rule 1.2: reviewer name: Hanel date: 28-03-2012 reason: delta_vel is checked above for not being close to zero */
                ttc_obj_ahead = delta_dis / delta_vel;
#ifdef FCT_SIMU
                pDebugInfoMultiObjAnalyse->ttc_case = 4u;
#endif /* FCT_SIMU */
              }
              else
              {
                ttc_obj_ahead = 0.f;
#ifdef FCT_SIMU
                pDebugInfoMultiObjAnalyse->ttc_case = 5u;
#endif /* FCT_SIMU */
              }
            }
          
            /* Build a linear Ramp for the Cut-In-Potential between MOR_MIN_TTC_VALUE and MOR_MAX_TTC_VALUE */
            if (( ttc_obj_ahead > MOR_MIN_TTC_VALUE ) && ( ttc_obj_ahead < MOR_MAX_TTC_VALUE ))
            {
              cut_in_pot = 1.f - ((ttc_obj_ahead - MOR_MIN_TTC_VALUE)/(MOR_MAX_TTC_VALUE - MOR_MIN_TTC_VALUE));
            }

            /* scale the potential depending on the object to object ahead inlap */
            factor_il = SIT_f_EvaluateObj2AheadInlap(ObjId, obj_ahead);
            cut_in_pot = factor_il * cut_in_pot;

            /* Do not give any potential if we will more likely pass the Object before it reaches Object ahead */
            ttc_ego_obj = SIT_f_CutInCalcTTC(ObjId);          

            if ( ((ttc_obj_ahead - ttc_ego_obj) > MOR_TTC_DIFF_RAMP_MIN) && (ttc_ego_obj < MOR_TTC_OBJ_RAMP_MAX) && (ttc_ego_obj > 0.f) )
            {
              if ( ttc_ego_obj < MOR_TTC_DIFF_RAMP_MIN )
              {
                /* Build linear Ramp between (ttc_ego_obj - ttc_obj_ahead) = MOR_TTC_DIFF_RAMP_MIN ... MOR_TTC_DIFF_RAMP_MAX */
                ftemp_rampfactor = (MOR_TTC_DIFF_RAMP_MAX - (ttc_obj_ahead - ttc_ego_obj))/MOR_TTC_DIFF_RAMP_LENGTH;
                cut_in_pot *= ftemp_rampfactor;
                cut_in_pot = MAX_FLOAT(cut_in_pot, 0.f);
#ifdef FCT_SIMU
    pDebugInfoMultiObjAnalyse->ramp_ttc_e2o = ftemp_rampfactor;
    pDebugInfoMultiObjAnalyse->ramp_ttc_e2o_case = 1u;
#endif /* FCT_SIMU */
              }
              else
              {
                /* Build an additional linear ramp for ttc_ego_obj in range MOR_TTC_OBJ_RAMP_MIN ... MOR_TTC_OBJ_RAMP_MAX */
                ftemp_rampfactor = (((ttc_ego_obj - MOR_TTC_OBJ_RAMP_MIN) / MOR_TTC_OBJ_RAMP_LENGTH)*cut_in_pot) + ((1.f - ((ttc_ego_obj - MOR_TTC_OBJ_RAMP_MIN) / MOR_TTC_OBJ_RAMP_LENGTH))*cut_in_pot*((MOR_TTC_DIFF_RAMP_MAX - (ttc_obj_ahead - ttc_ego_obj)) / MOR_TTC_DIFF_RAMP_LENGTH));
#ifdef FCT_SIMU
                if(cut_in_pot > C_F32_DELTA)
                {
                  pDebugInfoMultiObjAnalyse->ramp_ttc_e2o = ftemp_rampfactor/cut_in_pot;
                }
                else
                {
                  pDebugInfoMultiObjAnalyse->ramp_ttc_e2o = 0.0f;
                }
                pDebugInfoMultiObjAnalyse->ramp_ttc_e2o_case = 2u;
#endif /* FCT_SIMU */
                cut_in_pot = ftemp_rampfactor;
                cut_in_pot = MAX_FLOAT(cut_in_pot, 0.f);
              }
            }

            /* Build additional Ramps for the Right-Hand / Left-Hand Traffic Observation */
            if ( (f_ObjVrelX + f_ObjAheadVrelX) > MOR_ACTIVE_RAMP_REL_VEL_MIN )
            {
              ftemp_rampfactor = (MOR_ACTIVE_RAMP_REL_VEL_MAX - (*pt_SITInput->t_RTE.pf_ObjVrelX(ObjId) + *pt_SITInput->t_RTE.pf_ObjVrelX(obj_ahead)))/MOR_ACTIVE_RAMP_REL_VEL_LENGTH;
              cut_in_pot *= ftemp_rampfactor;
#ifdef FCT_SIMU
              pDebugInfoMultiObjAnalyse->ramp_relvel = ftemp_rampfactor;
#endif /* FCT_SIMU */
            }
            if ( (fABS(dist_obj2traj) - fABS(dist_objahead2traj)) > MOR_ACTIVE_RAMP_OFFSET_LAT_MIN )
            {
              ftemp_rampfactor = (MOR_ACTIVE_RAMP_OFFSET_LAT_MAX - (fABS(dist_obj2traj) - fABS(dist_objahead2traj)))/MOR_ACTIVE_RAMP_OFFSET_LAT_LENGTH;
              cut_in_pot *= ftemp_rampfactor;
#ifdef FCT_SIMU
              pDebugInfoMultiObjAnalyse->ramp_offsetlat = ftemp_rampfactor;
#endif /* FCT_SIMU */
            }

            break;

          default:
            /* Do not observe Object ahead if its not a Vehicle */
            cut_in_pot = 0.f;
            break;
          }
        }
      }
    }
  }

  /* The most true MOR-Events do not rise to the maximal potential, the MOR-Observer is already very reliable for medium potentials:
     Every potential bigger than MOR_FULL_POTENTIAL_RAMP_MAX is set to 1, MOR_FULL_POTENTIAL_RAMP_MIN to MOR_FULL_POTENTIAL_RAMP_MAX is converted linearly to MOR_FULL_POTENTIAL_RAMP_MIN to 1 */
  if (cut_in_pot > MOR_FULL_POTENTIAL_RAMP_MIN)
  {
    cut_in_pot += ((cut_in_pot - MOR_FULL_POTENTIAL_RAMP_MIN) * ((1.f - MOR_FULL_POTENTIAL_RAMP_MAX) / (MOR_FULL_POTENTIAL_RAMP_LENGTH)));
    cut_in_pot = MIN_FLOAT(cut_in_pot, 1.f);
  }
  /*! @todo : Check if "cut_in_pot = MAX_FLOAT(cut_in_pot, 0.f);" necessary */

  /* Convert the [0..1] ranged internal cut-in into percent */
  cut_in_pot *= 100.F;

#ifdef FCT_SIMU
  pDebugInfoMultiObjAnalyse->fPotential = cut_in_pot;
  pDebugInfoMultiObjAnalyse->delta_acc = delta_acc;
  pDebugInfoMultiObjAnalyse->delta_vel = delta_vel;
  pDebugInfoMultiObjAnalyse->delta_dis = delta_dis;
  pDebugInfoMultiObjAnalyse->ttc_obj_ahead = ttc_obj_ahead;
#endif /* FCT_SIMU */

  return (uint8)cut_in_pot;
}//PRQA S 7002, 7004
/* date: 2015-09-23, reviewer: Gangadhar Badiger,reason: Not a safety critical*/


/*************************************************************************************************************************
  Functionname:    SIT_f_CutInCalcTTC                                                                                   */ /*!

  @brief           calculate time to collision of ego vehicle to object

  @description     calculate time to collision of ego vehicle to object

                   @startuml
                   Partition SIT_f_CutInCalcTTC{
                   Start
                   If (Relative velocity is less than low delta) then (TRUE)
                   : Set Time to collision of ego vehicle to object with\n calculating Longitudinal displacement and Relative velocity of object;
                   Else (FALSE)
                   : Set Time to collision of ego vehicle to object with max Time to collision;
                   Endif
                   : Return Time to collision of ego vehicle to object;
                   End
                   }
                   @enduml

  @return          ttc_ego_obj: static float32, Time to collision of ego vehicle to object. [0.f ... 1/C_F32_DELTA] s

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         *pt_SITInput->t_RTE.pf_ObjLongDisp (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                   pt_SITInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i                    [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component


  @pre             -
  @post            -
  
  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Nele Hanel | nele.hanel@contiautomotive.com | +49 (8382) 9699-401
*************************************************************************************************************************/
static float32 SIT_f_CutInCalcTTC(const ObjNumber_t ObjId)
{
  float32 ttc_ego_obj;
  float32 f_ObjVrelX = *pt_SITInput->t_RTE.pf_ObjVrelX(ObjId);
  float32 f_ObjLongDisp = *pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId);

  if(fABS(f_ObjVrelX) > C_F32_DELTA)
  {
    ttc_ego_obj = f_ObjLongDisp/-f_ObjVrelX;
  }
  else
  {
    ttc_ego_obj = SIT_CUTIN_MAX_TTC;
  }

  return ttc_ego_obj;
}

/*************************************************************************************************************************
  Functionname:    SIT_f_CutInCalcTG                                                                                    */ /*!

  @brief           calculate time gap of ego vehicle to object

  @description     calculate time gap of ego vehicle to object

                   @startuml
                   Partition SIT_f_CutInCalcTG{
                   Start
                   If (Longitudinal velocity of ego vehicle is greater than Delta) then (TRUE)
                   : Set time gap of ego vehicle to object by calculating Longitudinal displacement of object\n and Longitudinal velocity of ego vehicle;
                   Else (FALSE)
                   : Set time gap of ego vehicle to object with max time gap;
                   Endif
                   : Return time gap of ego vehicle to object;
                   end
                   }
                   @enduml

  @return          tg_ego_obj: static float32, time gap of ego vehicle to object. [0.f ... full range of datatype]

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : ego vehicle speed                            [-330.f ... 330.f] m/s
  @glob_in         *pt_SITInput->t_RTE.pf_ObjLongDisp (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Nele Hanel | nele.hanel@contiautomotive.com | +49 (8382) 9699-401
*************************************************************************************************************************/
static float32 SIT_f_CutInCalcTG(const ObjNumber_t ObjId)
{
  float32 tg_ego_obj;
  float32 f_ObjLongDisp = *pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId);
  float32 f_EgoLongVel = *pt_SITInput->t_RTE.pf_EgoLongVel;

  if(f_EgoLongVel > C_F32_DELTA)
  {
    tg_ego_obj =  f_ObjLongDisp/f_EgoLongVel;
  }
  else
  {
    tg_ego_obj = SIT_CUTIN_MAX_TG;
  }

  return tg_ego_obj; 
}

/*************************************************************************************************************************
  Functionname:    SIT_b_CutInCheckLatPos                                                                               */ /*!

  @brief           Check plausibility of lateral position for cut_in

  @description     Assume a "blind spot" area in front of the ego vehicle
                   and check, if the object is located in that area. 
                   The area is defined by a curve radius of xxx m.
                   If the object is inside the "blind spot" area, a cutin is unlikely 
                   (because it actually would collide with the ego vehicle). 

                   @startuml
                   Partition SIT_b_CutInCheckLatPos{
                   Start
                   : Initialize plausible lateral position, blind spot offset;
                   If (Longitudinal displacement of object is less than\n Max Longitudinal displacement Blind Spot) then (TRUE)
                   : Update blind spot offset;
                   : Update plausible lateral position;
                   Else (FALSE)
                   Endif
                   : Return plausible lateral position;
                   End
                   }
                   @enduml

  @return          plausible_lateral_position : static boolean [TRUE, FALSE], true, if the object is OUTSIDE of the area
                   false, if the object is located INSIDE the area

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         *pt_SITInput->t_RTE.pf_ObjLongDisp (i) : Longitudinal displacement of an object i  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *pt_SITInput->t_RTE.pf_ObjLatDisp (i) : Lateral displacement of an object i        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Nele Hanel | nele.hanel@contiautomotive.com | +49 (8382) 9699-401
*************************************************************************************************************************/
static boolean SIT_b_CutInCheckLatPos(const ObjNumber_t ObjId)
{
  boolean plausible_lateral_position = TRUE;
  float32 f_BlindSpotOffset = SIT_CUTIN_INIT_BLINDSPOTOFFSET;
  float32 f_ObjLongDisp = *pt_SITInput->t_RTE.pf_ObjLongDisp (ObjId);
  float32 fAbs_ObjLatDisp = fABS(*pt_SITInput->t_RTE.pf_ObjLatDisp (ObjId));

  if(f_ObjLongDisp < SIT_CUTIN_MAX_LONG_DIST_BLINDSPOT)
  {
    f_BlindSpotOffset  = (SQR(f_ObjLongDisp)*(0.5f / CUTIN_RADIUS_BLINDSPOTAREA));  /* curve with radius 3m */ 

    if(   (f_ObjLongDisp < 0.f)
       || (fAbs_ObjLatDisp > f_BlindSpotOffset) )
    {
      plausible_lateral_position = FALSE;
    }
  }

  return plausible_lateral_position; 
}
#endif  /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE) */

/*************************************************************************************************************************
  Functionname:    SIT_v_CutInObjectDataInit                                                                            */ /*!

  @brief           Initialization of SITCutInObjDat

  @description     Initialization of SITCutInObjDat
 
                   @startuml
                   Partition SIT_v_CutInObjectDataInit{
                   Start
                   : Reset data for all objects;
                   End
                   }
                   @enduml

  @return          None

  @param[in]       None

  @glob_in         None
  @glob_out        SITCutInObjData[ObjID].u_PotentialDistanceCutInOut :   [0u]
                   SITCutInObjData[ObjID].PotentialMultiObjectAnalyse :  [0u]
                   SITCutInObjData[ObjID].u_KinematicCutInOutPot :  [0u]
                   SITCutInObjData[ObjID].u_FusedCutinPotential : [0u]

  @c_switch_part   FCT_SIMU : Simulation config switch
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         10.08.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
void SIT_v_CutInObjectDataInit(void)
{
  ObjNumber_t ObjID;

  /* reset data for all objects */
  for(ObjID = 0; ObjID < EM_N_OBJECTS; ObjID++)
  {
    SITCutInObjData[ObjID].u_PotentialDistanceCutInOut  = 0u;
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
    SITCutInObjData[ObjID].PotentialMultiObjectAnalyse = 0u;
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)*/
    SITCutInObjData[ObjID].u_KinematicCutInOutPot      = 0u;
    SITCutInObjData[ObjID].u_FusedCutinPotential    = 0u;
  }

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
#ifdef FCT_SIMU
  /* reset debug data */
  SIT_v_CutInDebugDataInit();
#endif
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)*/
}

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)
#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    SIT_v_CutInDebugDataInit                                                                             */ /*!

  @brief           Initializing the Cutin debug structures with the default values.

  @description     Initializing the Cutin debug structures with the default values.

                   @startuml
                   Partition SIT_v_CutInDebugDataInit{
                   Start
                   Repeat
                   : Get PoeDebugData, Obj ID and plausible lateral position;
                   Repeat while(Object Number is Less than Num of Objects)
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         SITCutInDebugObjData.Objects[iObj] : Structure describing the potential calculation extra debug data per object
  @glob_out        SITCutInDebugObjData.Objects[iObj].nextLongObjID              [OBJ_INDEX_NO_OBJECT]
  @glob_out        SITCutInDebugObjData.Objects[iObj].ObjID                      [OBJ_INDEX_NO_OBJECT]
  @glob_out        SITCutInDebugObjData.Objects[iObj].plausible_lateral_position [TRUE]

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Simulation config switch
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Nele Hanel | nele.hanel@contiautomotive.com | +49 (8382) 9699-401
*************************************************************************************************************************/
void SIT_v_CutInDebugDataInit(void)
{
  ObjNumber_t iObj;

  for (iObj=0; iObj<EM_N_OBJECTS; iObj++)
  {
    SITPotentialObjDebugData_t * const pPoeDebugData = &SITCutInDebugObjData.Objects[iObj];
    memset(pPoeDebugData, 0, sizeof(SITPotentialObjDebugData_t));
    SITCutInDebugObjData.Objects[iObj].nextLongObjID = OBJ_INDEX_NO_OBJECT;
    SITCutInDebugObjData.Objects[iObj].ObjID = OBJ_INDEX_NO_OBJECT;
    SITCutInDebugObjData.Objects[iObj].plausible_lateral_position = TRUE;
  }
}
#endif /* FCT_SIMU */

#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    SIT_v_CutInDebugDataFreeze                                                                           */ /*!

  @brief           Freeze cut in debug data for MTS

  @description     Freeze cut in debug data for MTS
   
                   @startuml
                   Partition SIT_v_CutInDebugDataFreeze{
                   Start
                   : Function measfreeze;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         SITCutInDebugObjData.Objects[iObj] : Structure describing the potential calculation extra debug data per object
  @glob_in         SITCutInDebugObjData_MeasInfo                 [MEASInfo_t defined in sit_calc_cutin_pot.c]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Simulation config switch
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.03.2016
  @changed         01.03.2016

  @todo            Remove this entire line if not needed

  @author          Benoit Bagot | benoit.bagot@continental-corporation.com | +49 (8382) 9699-376
*************************************************************************************************************************/
void SIT_v_CutInDebugDataFreeze(void)
{
  (void) FCT_FREEZE_DATA(&SITCutInDebugObjData_MeasInfo, &SITCutInDebugObjData, SIT_v_MeasCallback);
}
#endif /* FCT_SIMU */
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE)*/
///@}
#endif /* (FCT_CFG_ACC_SITUATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

