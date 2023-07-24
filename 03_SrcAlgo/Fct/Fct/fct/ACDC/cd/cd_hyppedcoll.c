/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hyppedcoll.c

DESCRIPTION:               Implementation of the pedcoll hypothesis

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 13:17:45CEST $

VERSION:                   $Revision: 1.29 $

LEGACY VERSION:            Revision: 2.11

*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_PED_COLL_HYPOTHESIS)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hyppedcoll HypPedColl
@ingroup cd

@brief          The Pedestrian Collision Hypothesis describes a scenario in which a collision with a 
                crossing pedestrian is likely to occur.\n\n
@description    The only external function of the module is: @ref CDHypoPedCollMain. It executes the 
                main processing steps of the pedestrian collision hypothesis.
@{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/
#if !CD_USE_GEN_PSC 
#error "CD_USE_GEN_PSC" has to be activated
#endif
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief      Oldest factor used in calculating weights for y distance history */
#define PED_VELO_WEIGHT_OLDEST (1.0f)


/*! @brief      Youngest factor used in calculating weights for y distance history */
#define PED_VELO_WEIGHT_YOUNGEST (3.0f)


/*! @brief      standard deviation of 0.7m for camera measured distances expected */
#define PED_VELO_WEIGHT_STD_B                   (0.7f) 


/*! @brief     Constant used to calculate allowed error */
#define PED_VELO_ALLOWED_CONST_ERROR_M          (0)


/*! @brief     Probability constant A used to map error to Probability */
#define PED_VELO_MAP_ERROR_PROB_CONST_A         (0.0031f)


/*! @brief     Probability constant B used to map error to Probability */
#define PED_VELO_MAP_ERROR_PROB_CONST_B         (0.0015f)


/*! @brief      Path factor used for calculation of collision corridor velocity */
#define PED_VELO_VEHICLE_PATH_FACTOR            (1.0f)

/*! @brief      Maximum weight of measured pedestrian velocity added to velocity probability density function */
#define PED_VELO_ADD_MEASURED_VELO_MAX_WEIGHT   (0.8f)

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/
#if (SWITCH_ON == CD_PED_COLL_USE_CORR_APPROACH)
static void  CDHypoPedCollCalculateCorridorApproachProb(const float32 fObjVrelToEgoTraj_mps,
                                                        const float32 fObjTTC_s,
                                                        const float32 fObjDistToEgoTraj_m, 
                                                        const float32 fObjYProjLength_m, 
                                                        const float32 fEgoWidth_m, 
                                                        float32* pOut_fCorrProb);
static boolean CDHypoPedCollCalcTTE(const float32 fPedWidth, const float32 fPedDistY, const float32 fPedVrelY, 
                                    const float32 fZoneWidth, float32 * fTTE );
static boolean CDHypoPedCollCalcTimeToVehiclePath(const float32 fObjEdgeDistToEgoTraj_m, 
                                                  const float32 fObjVrelY_mps, const float32 fEgoWidth_m, 
                                                  float32 * pfObjTTO_s );
#endif
static boolean CDHypoPedCollObjectFilter  ( ObjNumber_t const iObjectIndex);
static void CDHypoPedCollCalculateProb( ObjNumber_t        const         iObjectIndex, 
                                        CDIntHypothesis_t        * const pHypothesis);

#if (SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
static void CDPedCollDowngradeProbDominantVelo(float32 * out_fDownGradeFac, const float32 fObjVrelToEgoTraj_mps, const float32 fObjVrelOnEgoTraj_mps, 
                                               const float32 fObjDistToEgoTraj_m, const float32 fEgoVeloDepWidth_m);
#endif

/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/
#if (SWITCH_ON == CD_PED_COLL_USE_CORR_APPROACH)
/*************************************************************************************************************************
  Functionname:         CDHypoPedCollCalculateCorridorApproachProb                                                   */ /*!

  @brief                Calculates the Hypothesis Probability with the Corridor Approach

  @description          The function checks the different conditions whether the Pedestrian is on road, in PreBrake zone,
                        will be in corridor or not, and whether the Pedestrian can escape. Based on these conditions,
                        set the Hypothesis Probability of Pedestrian Collision
                        The following functions are used during the checks:
                        - Time until pedestrian enters corridor: @ref CDHypoPedCollCalcTimeToVehiclePath
                        - Time until pedestrian leaves corridor: @ref CDHypoPedCollCalcTTE
                        .
                        @startuml CDHypoPedCollCalculateCorridorApproachProb_activity.png
                        start
                          :Calculate distance of right and left 
                          object edge to ego corridor center;
                          note left:>see formula "Distance Edge to Ego Traj"
                          :Check if object is on road;
                          note left 
                            Objects nearest edge is closer
                            than trajectory width
                          end note
                          :Check if object is in prebrake zone;
                          note left
                            Prebrake zone width < road width
                          end note
                          #Orange:Check if pedestrian will be in corridor:
                          <b>CDHypoPedCollCalcTimeToVehiclePath</b> >
                          note left
                            Time until pedestrian enters corridor
                            has to be below threshold
                          end note
                          #Orange:Check if pedestrian can escape from corridor:
                          <b>CDHypoPedCollCalcTTE</b> >
                          note left
                            Time until pedestrian leaves 
                            corridor is below TTC?
                          end note
                          if(Ped cannot escape zone? OR\n(Ped is in prebrake zone AND will be in the corridor at TTC)?) then (Yes)
                            :1}
                            :Set very High probability;
                          elseif(Pedestrian is in prebrake zone?) then (Yes)
                            :2}
                            :Set High probability;
                          elseif(Pedestrian is in the ego corridor?) then (Yes)
                            :3}
                            :Set medium probability;
                          else(No)
                            :4}
                            :Set zero probability;
                          endif

                        stop
                        @enduml

  @return               void

  @param[in]            fObjVrelToEgoTraj_mps : Relative velocity of the object towards the ego trajectory. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fObjTTC_s :             Time to collision of the considered object based on its longitudinal kinematic. @phys_unit [s] @range [0,40]
  @param[in]            fObjDistToEgoTraj_m :   Distance of the object to the center of the ego trajectory. @phys_unit [m] @range ]-...,+...[
  @param[in]            fObjYProjLength_m :     Width of the considered object. @phys_unit [m] @range ]0,+...[
  @param[in]            fEgoWidth_m :           Width of the corridor of the ego vehicle. @phys_unit [m] @range ]0,+...[
  @param[in,out]        pOut_fCorrProb :        Calculated probability. @range [0,1]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS \n
                        @ref CD_PED_COLL_USE_CORR_APPROACH

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Distance Edge to Ego Traj:** \n
                          \f$Dist_{LeftEdge,EgoTraj} = DistToTraj_{Obj} + Width_{Obj} \cdot 0.5\f$
                          \f$Dist_{RigthEdge,EgoTraj} = DistToTraj_{Obj} - Width_{Obj} \cdot 0.5\f$

  @testmethod           @Generic_Testmethods

  @author               Gregor Powarzynski
*************************************************************************************************************************/
static void  CDHypoPedCollCalculateCorridorApproachProb(const float32   fObjVrelToEgoTraj_mps,
                                                        const float32   fObjTTC_s,
                                                        const float32   fObjDistToEgoTraj_m, 
                                                        const float32   fObjYProjLength_m, 
                                                        const float32   fEgoWidth_m, 
                                                              float32 * pOut_fCorrProb)
{
  const float32 fEscapeZoneWidth_m = fEgoWidth_m + CD_PED_COLL_ESCAPE_ZONE_OFFSET;//TODO HD was fEgoVeloDepWidth_m
  float32 fObjTTE_s; /* Time to escape! Needed time of Pedestrian to leave the vehicle Path. */
  float32 fObjTTV_s; /* Time to corridor. Time until the Pedestrian will reach the Vehicle Path. */
  float32 fNearestObjEdgeDistToEgoTraj_m;
  const float32 fObjLeftEdgeDistToEgoTraj_m  = fObjDistToEgoTraj_m + (fObjYProjLength_m * 0.5f);
  const float32 fObjRightEdgeDistToEgoTraj_m = fObjDistToEgoTraj_m - (fObjYProjLength_m * 0.5f);

  /* Init Bools */
  boolean bPedOnRoad           = FALSE;
  boolean bPedInPrebrakeZone   = FALSE;
  boolean bPedWillBeInCorridor = FALSE;
  boolean bPedCannotEscape     = FALSE;

  /* Calculate Distance between nearest Obj Edge and Course */
  if (fABS(fObjDistToEgoTraj_m) < (fObjYProjLength_m *0.50f))
  {
    /* Obj is on the course */
    fNearestObjEdgeDistToEgoTraj_m = 0;
  }
  else
  {
    /* Obj is next to the course */
    if (fABS(fObjLeftEdgeDistToEgoTraj_m) < fABS(fObjRightEdgeDistToEgoTraj_m))
    {
      fNearestObjEdgeDistToEgoTraj_m = fObjLeftEdgeDistToEgoTraj_m;
    }
    else
    {
      fNearestObjEdgeDistToEgoTraj_m = fObjRightEdgeDistToEgoTraj_m;
    }
  }

  /*********************/
  /* Check Ped On Road */
  /*********************/
  if (fABS(fNearestObjEdgeDistToEgoTraj_m) < (CD_PED_COLL_ON_ROAD_ZONE_WIDTH / 2.0f) )
  {
    bPedOnRoad = TRUE;
  }

  /******************************/
  /* Check Ped In Prebrake Zone */
  /******************************/
  if (fABS(fNearestObjEdgeDistToEgoTraj_m) < (CD_PED_COLL_PREBRAKE_ZONE_WIDTH / 2.0f) )
  {
    bPedInPrebrakeZone = TRUE;
  }

  /*********************************/
  /* Check Ped Will be in Corridor */
  /*********************************/
  if (FALSE != CDHypoPedCollCalcTimeToVehiclePath( fNearestObjEdgeDistToEgoTraj_m, fObjVrelToEgoTraj_mps, fEgoWidth_m, &fObjTTV_s ))
  {
    if ( fObjTTV_s <= CD_PED_TIME_TO_VEHICLE_PATH_S )
    {
      bPedWillBeInCorridor = TRUE;
    }
  }

  /***************************/
  /* Check Ped Cannot Escape */
  /***************************/
  if(FALSE != CDHypoPedCollCalcTTE( fObjYProjLength_m, fObjDistToEgoTraj_m, fObjVrelToEgoTraj_mps, fEscapeZoneWidth_m, &fObjTTE_s ))
  {
    if (fObjTTC_s <= fObjTTE_s ) //TODO HD TTC
    {
      bPedCannotEscape = TRUE;
    }
  }

  /******************************/
  /* Set Hypothesis probability */
  /******************************/
  if ((FALSE != bPedCannotEscape) || ((bPedInPrebrakeZone == TRUE) && (bPedWillBeInCorridor == TRUE))) /*TODO HD Added second cond*/
  {
    *pOut_fCorrProb = 1.0f;
  } 
  else if ((FALSE != bPedInPrebrakeZone))/*TODO HD || (FALSE != bPedWillBeInCorridor))*/
  {
    *pOut_fCorrProb = 0.8f;
  }
  else if(FALSE != bPedOnRoad)
  {
    *pOut_fCorrProb = 0.5f;
  }
  else
  {
    *pOut_fCorrProb = 0.f;
  }
}

/*************************************************************************************************************************
  Functionname:         CDHypoPedCollCalcTimeToVehiclePath                                                           */ /*!

  @brief                Calculates the time a pedestrian needs to enter the corridor of the ego vehicle

  @description          The function follows the subsequent steps:
                        @startuml CDHypoPedCollCalcTimeToVehiclePath_activity.png
                        start
                          :Calculate distance to the 
                          edge of the ego corridor;
                          note left: >see formula "Distance to Vehicle Path"
                          if (Object moves towards the ego corridor?) then (Yes)
                            :1}
                            :Calculate remaining time until 
                            pedestrian reaches corridor (=**TTO**);
                            note left: >see formula "Time to enter vehicle path"

                          elseif(Object is inside of the ego corridor?)then (Yes)
                            :2}
                            :**TTO** = 0;
                          else(No)
                            :3}
                            :**TTO** = default;
                            note left: Pedestrian is standing or walking\naway from the ego corridor
                          endif
                        stop
                        @enduml

  @return               boolean : Always true

  @param[in]            fObjEdgeDistToEgoTraj_m : Distance of the objects edge to the center of the ego trajectory. 
                                                  @phys_unit [m] @range ]-...,+...[
  @param[in]            fObjVrelY_mps :           Relative Y-Velocity of the pedestrian. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fEgoWidth_m :             Width of the ego path. @phys_unit [m] @range ]0,+...[
  @param[in,out]        pfObjTTO_s :              Time the pedestrian needs to enter the vehicle path. @phys_unit [s] @range[0,40]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS \n
                        @ref CD_PED_COLL_USE_CORR_APPROACH

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Distance to Vehicle Path:**\n
                        \f$Dist_{Obj,vehiclePath} = |Dist_{ObjEdge,EgoTraj}| - Width_{Ego} \cdot 0.5\f$
                        - **Formula Time to enter vehicle path:**\n
                        \f$\frac{Dist_{Obj,vehiclePath} }{ |V_{Obj,Rel,Y}|}\f$

  @testmethod           @Generic_Testmethods

  @author               Gregor Powarzynski
*************************************************************************************************************************/
static boolean CDHypoPedCollCalcTimeToVehiclePath( const float32 fObjEdgeDistToEgoTraj_m, const float32 fObjVrelY_mps, 
                                           const float32 fEgoWidth_m, float32 * pfObjTTO_s )
{
  /* Init */
  const float32 MAX_OBJ_TTV_S      = 40.0f; /* Max TTV Value */
  boolean       bResultOk          = TRUE;
  boolean       bPedTowardsVehicle = FALSE;

  /* Calculate distance to Vehicle Path */
  const float32 fPedDistToVehiclePath_m = fABS(fObjEdgeDistToEgoTraj_m) - (fEgoWidth_m/2.0f);
   
  /* Check if Pedestrian is coming from left or right side */
  if ((fObjVrelY_mps > C_F32_DELTA) && (fObjEdgeDistToEgoTraj_m < 0)) /* Walking in left direction towards the vehicle path */
  {
    bPedTowardsVehicle = TRUE;
  }
  if ((fObjVrelY_mps < (-C_F32_DELTA)) && (fObjEdgeDistToEgoTraj_m > 0) ) /* Walking in right direction towards the vehicle path */
  {
    bPedTowardsVehicle = TRUE;
  }
  
  if (fPedDistToVehiclePath_m <= 0) /* Pedestrian is already in vehicle path */
  {
    *pfObjTTO_s = 0;
  }
  else
  {
    if (FALSE != bPedTowardsVehicle) /* Pedestrian is moving in direction of vehicle path */
    {
      *pfObjTTO_s = fPedDistToVehiclePath_m / fABS(fObjVrelY_mps);
    }
    else /* Pedestrian is standing or walking away */
    {
      *pfObjTTO_s = MAX_OBJ_TTV_S;
    }
    
  }
  
  return bResultOk;
}

/*************************************************************************************************************************
  Functionname:         CDHypoPedCollCalcTTE                                                                         */ /*!

  @brief                Calculates time a pedestrian needs to leave a given zone.

  @description          This time is called Time to escape (=TTE)
                        @startuml CDHypoPedCollCalcTTE_activity.png
                        start
                          :Calculate Y-Distance to pedestrians 
                          left and right edge;
                          :Calculate distance pedestrian has to cover 
                          to escape the zone (left and right);
                          :Calculate TTE for each side;
                          note left: >see formula "TTE"
                          if(Pedestrian is walking to the left?) then (Yes)
                            :1}
                            note left
                              Assume that moving Pedestrians takes
                              time to change his moving direction 
                              to escape in the opposite side
                            end note
                            :Increase **TTERight**;
                          elseif(Pedestrian is walking to the right?) then (Yes)
                            :2}
                            :Increase **TTELeft**;
                          else(No)
                            :3}
                          endif
                          :**TTE** = Min( **TTELeft** , **TTERight** );
                        stop
                        @enduml
                        

  @return               boolean

  @param[in]            fPedWidth :   Width of the pedestrian. @phys_unit [m] @range ]0,...[
  @param[in]            fPedDistY :   Distance of the pedestrian in Y-direction. @phys_unit [m] @range ]-...,...[
  @param[in]            fPedVrelY :   Relative velocity of the pedestrian in Y-direction. @phys_unit [m/s] @range [0,+...[
  @param[in]            fZoneWidth :  Width of the zone of which the pedestrian has to escape. @phys_unit [m] @range ]0,...[
  @param[in,out]        fTTE :        Calculated time the pedestrian needs to escape the given area. @phys_unit [s] @range [0,...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS \n
                        @ref CD_PED_COLL_USE_CORR_APPROACH

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula TTE:** \n
                          \f$t_{TTE,Right/Left} = \frac{Y_{Escape,Right/Left}}{V_{Escape}}\f$ \n
                          with:\n
                          \f$V_{Escape} = |V_{rel}|\f$ \n
                          \f$Y_{Escape,Right} =  Y_{Ped} + 0.5 \cdot (Width_{Zone} - Width_{Ped}) \f$ \n
                          \f$Y_{Escape,Left}  = -Y_{Ped} + 0.5 \cdot (Width_{Zone} - Width_{Ped}) \f$

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static boolean CDHypoPedCollCalcTTE(const float32 fPedWidth, const float32 fPedDistY, const float32 fPedVrelY, 
                             const float32 fZoneWidth, float32 * fTTE )
{
  boolean bResultOk = TRUE;

  const float32 fPedOuterEdgeLeft  = fPedDistY + (fPedWidth / 2.0f);
  const float32 fPedOuterEdgeRight = fPedDistY - (fPedWidth / 2.0f);

  /* Calc escape Distances */
  const float32 fPedEscapeDistLeft  = (fZoneWidth / 2.0f) - fPedOuterEdgeRight;
  const float32 fPedEscapeDistRight =   fPedOuterEdgeLeft + (fZoneWidth / 2.0f);

  /* Calc Pedestrian escape Speed */
  const float32 fAbsPedVrelY = fABS(fPedVrelY);
  const float32 fPedEscapeSpeed = MAX(fAbsPedVrelY, CD_PED_COLL_PED_SPEED_MAX);

  /* Calc Side dependent TTEs */
  float32 fTTELeft  = fPedEscapeDistLeft  / fPedEscapeSpeed;
  float32 fTTERight = fPedEscapeDistRight / fPedEscapeSpeed;

  if (fPedVrelY < (-CD_PED_COLL_PED_SPEED_MAX/2.f))
  {
    /* Assume that moving Pedestrian takes 0.5s to change his moving direction to escape in the opposite side -> Move logic to EMP later */
    fTTELeft += 0.5f;
  }
  else if (fPedVrelY > (CD_PED_COLL_PED_SPEED_MAX/2.f))
  {
    /* Assume that moving Pedestrians takes 0.5s to change his moving direction to escape in the opposite side -> Move logic to EMP later */
    fTTERight += 0.5f;
  }
  else
  {
    /* Standing Pedestrians can change their lateral moving directions immediately -> Move logic to EMP later */
  }

  /* Only use positive TTEs (negative means, the pedestrian could stop before entering) */
  fTTELeft  = MAX(0, fTTELeft);
  fTTERight = MAX(0, fTTERight);
    
  /* Take minimum of escape times */
  *fTTE = MIN(fTTELeft, fTTERight);

  return bResultOk;
}
#endif

/*************************************************************************************************************************
  Functionname:         CDHypoPedCollObjectFilter                                                                    */ /*!

  @brief                Checks whether the object is relevant for Pedestrian Collision Hypothesis

  @description          To open a pedestrian collision hypothesis, the following criteria have to be fulfilled :
                        - The Objects HypCat is Crossing or Stationary
                        - The Object has to be of EBA-Class Pedestrian
                        - The Objects TTC has to be below threshold
                        - Hypothesis is initiated only if ego is not turning either left or right

  @return               boolean : True if object fulfills the filter conditions.

  @param[in]            iObjectIndex : Index of the considered object. @range [0,...]

  @glob_in              @ref CD_f_GetTTC3\n
                        @ref ACDC_p_GetEgoDrvScenario \n
                        @ref ACDC_p_GetObjHypothesisData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Matthias Thomi

  @testmethod           @ref TEST_CDHYPOPEDCOLLOBJECTFILTER_001 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoPedCollObjectFilter(ObjNumber_t const iObjectIndex)
{
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  CDEgoTurningState_t                 eEgoCurrentTurnState    = ACDC_p_GetEgoDrvScenario()->eEgoCurrentTurnState;
  CDObj_Hypothesis_t    const * const pObjHypData             = ACDC_p_GetObjHypothesisData(iObjectIndex);
#endif
  boolean bAcceptObj = b_TRUE;

  if (    ( CD_f_GetTTC3(iObjectIndex) > CD_PED_MAX_TTC_FILTER )
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
        ||(    ( eEgoCurrentTurnState != CD_EGO_TURNING_NO )
            && ( pObjHypData->HypothesisHist.PedColl != 1  )   )
#endif
                                                                  )
  {
    bAcceptObj = b_FALSE;
  }

  /* Check for Class Peds is already done in generic Class filter */

  return bAcceptObj;
}

/*************************************************************************************************************************
  Functionname:         CDHypoPedCollCalculateProb                                                                   */ /*!

  @brief                Calculates the probability of the pedestrian collision hypothesis.

  @description          The collision probability is calculated by means of the probability of 
                        speed concept: @ref CDPSCGetProbCollision\n
                        The therefore required width of the ego corridor is calculated by adding a velocity dependent 
                        polygon value based on the variable @ref CD_EGO_ADD_WIDTH_VELO_DEP_M to the ego vehicle width. \n
                        All following actions are optional and can be decoded by configuration switches:
                        - The probability is calculated again on base of the corridor approach 
                          (@ref CDHypoPedCollCalculateCorridorApproachProb) 
                          and multiplied by the previously calculated probability.
                        - The probability is set to 0 if the pedestrian is detected to be outside 
                          of the estimated road: @ref CDPedIsOutsideRoadEstimation \n
                        - The probability is decreased if the main movement direction of the bicycle is not
                          crossing in relation to the ego vehicle. The factor by which it is decreased 
                          is calculated by the function @ref CDPedCollDowngradeProbDominantVelo.
                        .
                        @startuml CDHypoPedCollCalculateProb_activity.png
                        start
                        :Calculate width of ego corridor;
                        note left: Depending on ego velocity
                        #Orange:Calculate psc collision probability:
                        <b>CDPSCGetProbCollision</b> >
                        note left: psc = probability of speed concept

                        #Orange:Calculate probability on base of corridor
                        approach and fuse with psc probability:
                        <b>CDHypoPedCollCalculateCorridorApproachProb</b> >
                        note left: Configuration dependent step

                        #Orange:Set probability to zero if pedestrian 
                        is outside of estimated road:
                        <b>CDPedIsOutsideRoadEstimation</b> >
                        note left: Configuration dependent step
                        
                        #Orange:Reduce probability if main movement 
                        direction of pedestrian is not crossing:
                        <b>CDPedCollDowngradeProbDominantVelo</b> >
                        note left: Configuration dependent step

                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :        Index of the considered object. @range [0,...]
  @param[in,out]        *pHypothesis :        Pointer to the hypothesis for which the probability shall be calculated

  @glob_in              @ref ACDC_p_GetObjTrajRelation\n
                        @ref CD_f_GetTTC4
  @glob_out             None

  @c_switch_part        @ref CD_PED_USE_EM_ROAD_ESTIMATION \n
                        @ref CD_PED_COLL_USE_CORR_APPROACH \n
                        @ref CD_PED_USE_LIMITED_DIMENSIONS \n
                        @ref CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @author               Matthias Thomi

  @testmethod           @ref TEST_CDHYPOPEDCOLLCALCULATEPROB_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoPedCollCalculateProb( ObjNumber_t        const         iObjectIndex, 
                                        CDIntHypothesis_t        * const pHypothesis)
{
  /* Collect Object Informations */
#if ((SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE) || (SWITCH_ON == CD_PED_COLL_USE_CORR_APPROACH))
  ACDCObjToTrajRelation_t const * const pTrajRelation = ACDC_p_GetObjTrajRelation(iObjectIndex);
  const float32 fObjDistToEgoTraj_m   = pTrajRelation->fDistToTraj;
  const float32 fObjVrelToEgoTraj_mps = pTrajRelation->fVelocityToTraj;
#if (SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
  const float32 fObjVrelOnEgoTraj_mps = pTrajRelation->fVelocityOnTraj;
#endif /* #if (SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE) */
#endif /* #if ((SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE) || (SWITCH_ON == CD_PED_COLL_USE_CORR_APPROACH)) */

#if (SWITCH_ON == CD_PED_COLL_USE_CORR_APPROACH)
  const float32 fObjTTC4_s            = CD_f_GetTTC4(iObjectIndex);
#endif

  /* Probability of Speed Concept */
  float32 fPSCProb          = 0.0f;
  float32 fCorrApproachProb = 1.0f;
  float32 fObjCollProb      = 1.0f;
  float32 fEgoVeloDepWidthLeft_m;
  float32 fEgoVeloDepWidthRight_m;

  /* calculate the asymmetric ego vehicle corridor */
  CDPSCCalcCorridorWidthCrossVru ( iObjectIndex, &fEgoVeloDepWidthLeft_m, &fEgoVeloDepWidthRight_m);
  
  /* get PSC probability using the generic calculation */
  fPSCProb     = CDPSCGetProbCollision(iObjectIndex, fEgoVeloDepWidthLeft_m, fEgoVeloDepWidthRight_m, CD_PSC_USE_TO_TRAJ);

#if (SWITCH_ON == CD_PED_COLL_USE_CORR_APPROACH)
  /********************************************/
  /* Calculate Zone Model Approach            */
  /********************************************/
  CDHypoPedCollCalculateCorridorApproachProb(fObjVrelToEgoTraj_mps, fObjTTC4_s,fObjDistToEgoTraj_m, fObjWidth_m, ACDC_COMMON_EGO_WIDTH, &fCorrApproachProb);
#endif

  /***********************************/
  /* Fuse Probs                      */
  /***********************************/
  pHypothesis->fHypothesisProbability = fPSCProb * fCorrApproachProb;

#if (defined(CD_PED_USE_EM_ROAD_ESTIMATION) && (CD_PED_USE_EM_ROAD_ESTIMATION == SWITCH_ON))
  if ( CDPedIsOutsideRoadEstimation(iObjectIndex) != FALSE )
  {
    fObjCollProb = 0.f;
  }
#endif
  pHypothesis->fHypothesisProbability *= fObjCollProb;
   
#if (SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
  {
  /* Downgrade hypothesis probability in case of dominant velocity direction is not crossing! */
    float32 out_fDownGradeFac  = 1.0f;
    float32 fEgoVeloDepWidth_m = fEgoVeloDepWidthLeft_m + fEgoVeloDepWidthRight_m;
    CDPedCollDowngradeProbDominantVelo(&out_fDownGradeFac, fObjVrelToEgoTraj_mps, fObjVrelOnEgoTraj_mps, fObjDistToEgoTraj_m, fEgoVeloDepWidth_m);
    pHypothesis->fHypothesisProbability *= out_fDownGradeFac;
  }
#endif
}

#if (SWITCH_ON == CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
/*************************************************************************************************************************
  Functionname:         CDPedCollDowngradeProbDominantVelo                                                       */ /*!

  @brief                Calculates a factor by which the probability for the bicycle hypothesis is downgraded 
                        if the movement direction of the bicycle is not crossing.

  @description          The function downgrades the pedestrian collision probability when the dominant
                        object velocity direction is not crossing in relation to the ego vehicle path. \n
                        This ensures that some of the FalsePositives are suppressed. \n
                        Possible FalsePositive suppressions are:
                        - Pedestrian/Bicycle standing -> a minimum velocity required
                        - Pedestrian/Bicycle moving inside the ego vehicle path

  @return               void

  @param[in,out]        out_fDownGradeFac :     Calculated factor by which the collision probability shall be downgraded. @range [0,1]
  @param[in]            fObjVrelToEgoTraj_mps : Velocity by which the object is closing up to the ego trajectory. @phys_unit [m/s]
  @param[in]            fObjVrelOnEgoTraj_mps : Velocity by which the object is driving along the ego trajectory. @phys_unit [m/s]
  @param[in]            fObjDistToEgoTraj_m :   Distance of the Object and the ego trajectory. @phys_unit [m]
  @param[in]            fEgoVeloDepWidth_m :    Width of the ego vehicle corridor. @phys_unit [m]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS \n
                        @ref CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Downgrade Factor:**\n
                        \f$ Fctr = \frac{V_{ToTraj}}{V_{OnTraj}} \cdot \frac{1}{MaxRate}, Fctr >= MinFactor\f$ \n
                        With \n
                        \f$ MinFactor = - |D_{ToTraj} - 0.5 \cdot Width_{Corr,Ego}|, 0 <= MinFactor <= 1 \f$ \n
                        \f$ MaxRate = A \ cdot |D_{ToTraj} - 0.5 \cdot Width_{Corr,Ego}|, 0 < MaxRate <= 1 \f$\n
                        \n
                        If a pedestrian is detected to be not moving or outside of the ego vehicle corridor, 
                        the down grade factor is set to 1.

  @todo                 Function is identical to CDBicycleCollDowngradeProbDominantVelo

  @author               Gregor Powarzynski

  @testmethod           @ref TEST_CDPEDCOLLDOWNGRADEPROBDOMINANTVELO_001 \n
                        @ref TEST_CDPEDCOLLDOWNGRADEPROBDOMINANTVELO_002 \n
                        @ref TEST_CDPEDCOLLDOWNGRADEPROBDOMINANTVELO_003

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPedCollDowngradeProbDominantVelo(float32 * out_fDownGradeFac, const float32 fObjVrelToEgoTraj_mps, const float32 fObjVrelOnEgoTraj_mps, 
                                               const float32 fObjDistToEgoTraj_m, const float32 fEgoVeloDepWidth_m)
{
  /*
  Thoughts:
  Downgrading the pedestrian collision probability is a workaround, to use this hypothesis for bicycles also. 
  To downgrade an objects, which move on trajectory with the ego-vehicle means: near overtake scenarios with bicycles are suppressed.

  FalsePositive suppressions could be:
  - Pedestrian/Bicycle standing -> a minimum velocity required
  - Pedestrian/Bicycle moving inside the ego vehicle path
  */
  const float32 fPedDistToVehiclePath_m = MAX_FLOAT(0.0f, fABS(fObjDistToEgoTraj_m) - (fEgoVeloDepWidth_m*0.5f));
  const float32 fMaxRate   = CML_f_CalculatePolygonValue(CD_NUMBER_OF_DOMINANTDOWNGRADE_MAX_RATE_VALUES, CD_PED_COLL_DOM_DG_MAX_RATE_VEC, fPedDistToVehiclePath_m);
  const float32 fMinFactor = CML_f_CalculatePolygonValue(CD_NUMBER_OF_DOMINANTDOWNGRADE_MIN_FACTOR_VALUES, CD_PED_COLL_DOM_DG_MIN_FACTOR_VEC, fPedDistToVehiclePath_m);


  const float32 fObjVelo_mps = SQR(fObjVrelOnEgoTraj_mps) + SQR(fObjVrelToEgoTraj_mps); /* Be careful: not the real velocity of the object. SQRT not done because of efficiency */
  const boolean bPedIsMoving = (boolean) (fObjVelo_mps > CD_PED_COLL_DOM_DG_MIN_OBJ_VELO_MPS);
    
  const boolean bPedIsNotInVehiclePath = (boolean) (fABS(fObjDistToEgoTraj_m) > (fEgoVeloDepWidth_m*0.5f));

  float32 fVrelToOnTrajRate;

  *out_fDownGradeFac = 1.0f;

  if (fABS(fObjVrelOnEgoTraj_mps) > C_F32_DELTA)
  {
    fVrelToOnTrajRate = fABS(fObjVrelToEgoTraj_mps) / fABS(fObjVrelOnEgoTraj_mps);
    if ( ( b_FALSE!=bPedIsMoving ) && ( b_FALSE!=bPedIsNotInVehiclePath ) )
    {
      *out_fDownGradeFac = MAX_FLOAT(fMinFactor, MIN_FLOAT(1.0f,fVrelToOnTrajRate/fMaxRate));
    }
  }
}
#endif

#if (!CD_USE_CUSTOM_HYPOTHESIS_PEDESTRIAN_COLLISION)
/*************************************************************************************************************************
  Functionname:         CDHypoPedCollMain                                                                           */ /*!

  @brief                Handles the main steps of the pedestrian collision hypothesis.

  @description          Handles the pedestrian collision hypothesis by executing the three common steps for a 
                        hypothesis generation (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CDHypoPedCollObjectFilter
                        2. Call of the Hypothesis probability calculation: @ref CDHypoPedCollCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: 
                        @ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the three main steps that are described in the diagram can be 
                        found in the description of the @ref cd_hyphandler.
                        @image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range[0,...]
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history (if exists)
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_CUSTOM_HYPOTHESIS_PEDESTRIAN_COLLISION \n
                        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS

  @pre                  None
  @post                 No changes

  @InOutCorrelation     see description

  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOPEDCOLLMAIN_001 \n
                        @ref TEST_CDHYPOPEDCOLLMAIN_002 \n
                        @ref TEST_CDHYPOPEDCOLLMAIN_003 \n
                        @ref TEST_CDHYPOPEDCOLLMAIN_004

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoPedCollMain(      ObjNumber_t const   iObjectIndex, 
                             boolean     const   bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;

  CDObj_Hypothesis_t *const pObjHypData  = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_PedCollision);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_PedCollision);

  /* Default Hypothesis Prob Calculation calling */
  if( bObjFilterMatched != b_FALSE )
  { 
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart, ACDC_RTA_CD_HYP_PEDCOLL_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoPedCollObjectFilter(iObjectIndex) != b_FALSE )
    {
      /* Default Hypothesis handling */
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_PedCollision);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_PedCollision);

      CDHypoPedCollCalculateProb(iObjectIndex, &Hypothesis);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > 0.2f)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_PedCollision);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.PedColl = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.PedColl = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.PedColl = 0u;
    }
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYP_PEDCOLL_SINGLE, (uint8)(iObjectIndex));
  }
  else
  {
    pObjHypData->HypothesisHist.PedColl = 0u;
  }
}
#endif /* (!CD_USE_CUSTOM_HYPOTHESIS_PEDESTRIAN_COLLISION) */
//! @}
#endif /* (CD_USE_PED_COLL_HYPOTHESIS)  */
#endif /* (ACDC_CFG_CD) */


