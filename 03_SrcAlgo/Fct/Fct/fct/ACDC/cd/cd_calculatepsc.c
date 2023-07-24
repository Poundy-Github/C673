/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculatepsc.c

DESCRIPTION:               Implementation of the probability of speed concept (PSC) for CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 09:50:32CEST $

VERSION:                   $Revision: 1.39 $

LEGACY VERSION:            Revision: 2.5

*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)

#if(CD_USE_GEN_PSC)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup cd_calculatepsc CalculatePsc
\ingroup cd

\brief Calculates a velocity distribution of a given object and checks how much of this distribution is within the critical 
velocity range for a collision with the ego vehicle. \n\n

The module provides two external functions:
- **Init PSC**: \n
The function \ref CDPSCInit initializes all data that is relevant for the calculation of the collision probability. 
It is called once at the beginning of each cycle.
- **Calculate Collision Probability**: \n
The main functionality is the calculation of a collision probability. It is handled by the function \ref CDPSCGetProbCollision.\n 
It uses the velocity distribution of an object and a collision velocity corridor to calculate a collision probability.

\{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/
#if !ACDC_CFG_EMP 
#error "ACDC_CFG_EMP" has to be activated
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief      Oldest factor used in calculating weights for y distance history */
#define CD_PSC_VELO_WEIGHT_OLDEST                 (0.5f)


/*! @brief      Youngest factor used in calculating weights for y distance history */
#define CD_PSC_VELO_WEIGHT_YOUNGEST               (1.5f)


/*! @brief      standard deviation of 0.7m for camera measured distances expected */
#define CD_PSC_VELO_WEIGHT_STD_B                  (0.5f) 


/*! @brief     Constant used to calculate allowed error */
#define CD_PSC_VELO_ALLOWED_CONST_ERROR_M         (0.0f)


/*! @brief     Probability constant A used to map error to Probability */
#define CD_PSC_VELO_MAP_ERROR_PROB_CONST_A        (0.0031f)


/*! @brief     Probability constant B used to map error to Probability */
#define CD_PSC_VELO_MAP_ERROR_PROB_CONST_B        (0.0000015f)


/*! @brief      Path factor used for calculation of collision corridor velocity */
#define CD_PSC_VELO_VEHICLE_PATH_FACTOR           (1.0f)

/*! @brief      Maximum weight of measured pedestrian velocity added to velocity probability density function */
#define CD_PSC_VELO_ADD_MEASURED_VELO_MAX_WEIGHT  (0.8f)

/*! @brief      Lower limit on absolute value of cosine of angle between object
                velocity vector and vector orthogonal to ego velocity. Used to
                limit the projected ego trajectory width 
                @typical 0.866f (cos(30°)) */
#define CD_PSC_MIN_COS_OBJ_CROSSING_ANGLE         (0.8f)

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/

static void CDPSCCalcProbCollisionPSC       ( ObjNumber_t                       iObjectIndex,
                                              float32             const         afPossibleVelocity_mps[CD_PSC_PROB_VELO_STEPS_N],
                                              float32             const         fCollCorrVeloLeft_mps,
                                              float32             const         fCollCorrVeloRight_mps,
                                              float32                   * const pfPSCProbCollision );
static void CDPSCCalcProbCollisionGaussian  ( ObjNumber_t                       iObjectIndex,
                                              float32             const         fCollCorrVeloLeft_mps,
                                              float32             const         fCollCorrVeloRight_mps,
                                              CDPSCRefPointType_t         const eRefPointType,
                                              float32                   * const pfGaussProbCollision);
static void CDPSCCalcFusedProb              ( float32             const         fGaussProbCollision,
                                              float32             const         fPSCProbCollision,
                                              float32                   * const pfFusedVelocityProb );
static void CDPSCCalcVelCorridor            ( ObjNumber_t                 const iObjectIndex,
                                              float32                     const fEgoCorridorWidthLeft,
                                              float32                     const fEgoCorridorWidthRight,
                                              float32                   * const pfCollCorrVeloLeft_mps,
                                              float32                   * const pfCollCorrVeloRight_mps );
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
static void CDPSCCalcVelCorridorToCollPt    ( ObjNumber_t         const         iObjectIndex,
                                              float32             const         fEgoCorridorWidthLeft,
                                              float32             const         fEgoCorridorWidthRight,
                                              float32                   * const pfCollCorrVeloLeft,
                                              float32                   * const pfCollCorrVeloRight );
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
static void CDPSCGetPossibleVelocity        ( ObjNumber_t         const         iObjectIndex,
                                              CDPSCRefPointType_t const         eRefPointType,
                                              float32                           afPossibleVelocity_mps  [CD_PSC_PROB_VELO_STEPS_N]);
/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDPSCInit                                                                                    */ /*!

  @brief                The function initializes all data of an object that is relevant for the 
                        calculation of the collision probability based on the PSC. 

  @description          The structure \ref sPSCObjDataDebug, the implies simulation relevant data is initialized. The function is called once for 
                        each object at the beginning of each cycle.
                        @attention Now reset simulation relevant variables only, other variables could be reset in this function in the future.
                        @startuml CDPSCInit_activity.png
                        start
                         :Reset simulation relevant variables;
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex : Object identifier. @range [0,EM_N_OBJECTS[

  @glob_in              None
  @glob_out             @ref ACDC_p_ModSimuData

  @c_switch_part        @ref ACDC_SIMU
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDPSCINIT_001  COU_TEST


  @traceability         Design Decision

*************************************************************************************************************************/
void CDPSCInit(  ObjNumber_t const iObjectIndex )
{
   /* Initialize simulation relevant variables */
#ifdef ACDC_SIMU
  {
    CDPSCObjDataDebug_t * pObjPSCSimuData = &(ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sPSCObjDataDebug);
    uint32 uIndex;

    for (uIndex = 0u; uIndex < CD_PSC_PROB_VELO_STEPS_N; uIndex++)
    {
      pObjPSCSimuData->afPSCVelocityProb[uIndex]      = 0;
      pObjPSCSimuData->afPSCVelocitySteps[uIndex]     = 0;
    }
    pObjPSCSimuData->fCollCorrVeloLeft          = CD_PSC_PROB_VELO_MAX;
    pObjPSCSimuData->fCollCorrVeloRight         = CD_PSC_PROB_VELO_MAX;
    pObjPSCSimuData->fCollCorrToCollPtVelLeft   = CD_PSC_PROB_VELO_MAX;
    pObjPSCSimuData->fCollCorrToCollPtVelRight  = CD_PSC_PROB_VELO_MAX;
    pObjPSCSimuData->fCenterVelocity            = 0;
    pObjPSCSimuData->fCenterVelocityStd         = 0;
    pObjPSCSimuData->fCenterToCollPtVel         = 0;
    pObjPSCSimuData->fCenterToCollPtVelStd      = 0;
    pObjPSCSimuData->fVelocityGate              = 0;
    pObjPSCSimuData->fPSCProb                   = 0;
    pObjPSCSimuData->fPSCProbGauss              = 0;
    pObjPSCSimuData->fPSCProbGaussFused         = 0;
    pObjPSCSimuData->collPtEgoFront.fX          = 0;
    pObjPSCSimuData->collPtEgoFront.fY          = 0;
    pObjPSCSimuData->collPtToGenObjPos.fX       = 0;
    pObjPSCSimuData->collPtToGenObjPos.fY       = 0;
  }
#else
  _PARAM_UNUSED(iObjectIndex);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
#endif
}

/*************************************************************************************************************************
  Functionname:         CDPSCGetProbCollision                                                                       */ /*!

  @brief                Calculation of the collision probability based on a velocity corridor and a velocity 
                        distribution of the object.

  @description          The function calculates a collision probability of the ego vehicle and an object by 
                        executing the following steps:
                        1. **Calculation of the velocity corridor**: \n
                          The Velocity corridor describes the minimum and maximum velocity of any object that is 
                          on collision course with the ego vehicle. \n
                          E.g. a collision will occur if the object drives with a speed between 10 and 15 km/h. 
                          The calculation is executed in the function @ref CDPSCCalcVelCorridor (with respect to min distance to trajectors) 
                          or @ref CDPSCCalcVelCorridorToCollPt (with respect to estimated collision point).
                        2. **Calculation of the array of possible velocities**: \n
                          The array of possible velocities is filled by calling the function @ref CDPSCGetPossibleVelocity
                        3. **Calculation of the collision probability**: \n
                          For each object a velocity distribution is calculated. The collision probability describes 
                          the area under the distribution curve that is within the limits of the velocity corridor \n
                          which was calculated in step 2.

                        @startuml CDPSCCalcDistributionPSC_activity.png
                        start
                        if ( ref point type == collision point ) then (yes)
partition #LightBlue **CD_USE_TURNINTOVRU_HYPOTHESIS** {
                          #Orange: calc. velocity corridor to collision point:
                          <b>CDPSCCalcVelCorridorToCollPt</b> >
                          #Orange: calc. prob. of collision using Gaussian vel. distribution:
                          <b>CDPSCCalcProbCollisionGaussian</b> >
                        }
                        else (no)
                          #Orange: calc velocity corridor to traj (to closest point on traj):
                          <b>CDPSCCalcVelCorridor</b> >
                          #Orange: calc. prob. of collision using Gaussian vel. distribution:
                          <b>CDPSCCalcProbCollisionGaussian</b> >
                          #Orange: calc. velocity steps around center velocity:
                          <b>CDPSCGetPossibleVelocity</b> >
                          #Orange: calc. prob. of collision using PSC vel. distribution:
                          <b>CDPSCCalcProbCollisionPSC</b> >
                          #Orange: Fuse prob. of collision for PSC and Gaussian distributions:
                          <b>CDPSCCalcFusedProb</b> >
                        endif
                        stop
                        @enduml


  @return               fProbOfCollision :   The probability of collision
    
  @param[in]            iObjectIndex :                Object index. @range [0,EM_N_OBJECTS[
  @param[in]            fEgoCorridorWidthLeft :       Ego corridor width on the left side.  @range [0,+...[ @phys_unit [m]
  @param[in]            fEgoCorridorWidthRight :      Ego corridor width on the right side. @range [0,+...[ @phys_unit [m]
  @param[in]            eRefPointType :               switch for reference point (to traj or to collision point).

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref ACDC_SIMU \n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDPSCGETPROBCOLLISION_001  COU_TEST \n
                        @ref TEST_CDPSCGETPROBCOLLISION_002  COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
float32 CDPSCGetProbCollision( ObjNumber_t         const iObjectIndex          ,
                               float32             const fEgoCorridorWidthLeft ,
                               float32             const fEgoCorridorWidthRight,
                               CDPSCRefPointType_t const eRefPointType          )
{
  float32                     fCollCorrVeloLeft;
  float32                     fCollCorrVeloRight;
  float32                     fProbOfCollision;
  float32                     afPossibleVelocity   [CD_PSC_PROB_VELO_STEPS_N];
#ifdef ACDC_SIMU
  CDPSCObjDataDebug_t * const pObjPSCSimuData = &(ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sPSCObjDataDebug);
#endif

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  if ( eRefPointType == CD_PSC_USE_TO_COLL_POINT )
  {
  /* Find out the velocity corridor based on the passed Ego width */
    CDPSCCalcVelCorridorToCollPt( iObjectIndex,
                                  fEgoCorridorWidthLeft,
                                  fEgoCorridorWidthRight,
                                  &fCollCorrVeloLeft,
                                  &fCollCorrVeloRight );
    /* get pdf of velocity to collision point from EMP */
    CDPSCCalcProbCollisionGaussian ( iObjectIndex , fCollCorrVeloLeft, fCollCorrVeloRight, CD_PSC_USE_TO_COLL_POINT, &fProbOfCollision);
#ifdef ACDC_SIMU
    pObjPSCSimuData->fCollCorrToCollPtVelLeft  = fCollCorrVeloLeft;
    pObjPSCSimuData->fCollCorrToCollPtVelRight = fCollCorrVeloRight;
#endif
  }
  else
#else
  _PARAM_UNUSED(eRefPointType);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
  {
    float32 fGaussProbCollision;
    float32 fPSCProbCollision;

    /* Find out the velocity corridor based on the passed Ego width */
    CDPSCCalcVelCorridor( iObjectIndex,
                          fEgoCorridorWidthLeft,
                          fEgoCorridorWidthRight,
                          &fCollCorrVeloLeft,
                          &fCollCorrVeloRight );
    /* Calculate the collision probability based on a Gaussian distribution for the velocity to trajectory */
    CDPSCCalcProbCollisionGaussian  ( iObjectIndex, fCollCorrVeloLeft, fCollCorrVeloRight, CD_PSC_USE_TO_TRAJ, &fGaussProbCollision );
    /* Get the array of velocity steps around the center velocity */
    CDPSCGetPossibleVelocity        (iObjectIndex, eRefPointType, afPossibleVelocity);
    /*  Calculate the probability of collision based on historical position information */
    CDPSCCalcProbCollisionPSC       ( iObjectIndex, afPossibleVelocity, fCollCorrVeloLeft, fCollCorrVeloRight,&fPSCProbCollision );
    /* Fusion of the calculated Gaussian- and PSC-collision probability */
    CDPSCCalcFusedProb              ( fGaussProbCollision, fPSCProbCollision, &fProbOfCollision );
    /* Fill out simulation data */
#ifdef ACDC_SIMU
    {
      uint32 uIndex;
      pObjPSCSimuData->fCollCorrVeloLeft    = fCollCorrVeloLeft;
      pObjPSCSimuData->fCollCorrVeloRight   = fCollCorrVeloRight;
      pObjPSCSimuData->fPSCProbGauss        = fGaussProbCollision;
      pObjPSCSimuData->fPSCProb             = fPSCProbCollision;
      pObjPSCSimuData->fPSCProbGaussFused   = fProbOfCollision;
      pObjPSCSimuData->fCenterVelocity      = ACDC_p_GetObjTrajRelation(iObjectIndex)->fVelocityToTraj;
      pObjPSCSimuData->fVelocityGate        = CD_PSC_VEL_GATE;
      for (uIndex = 0; uIndex < CD_PSC_PROB_VELO_STEPS_N; ++uIndex)
      {
        pObjPSCSimuData->afPSCVelocitySteps[uIndex] = afPossibleVelocity[uIndex];
      }
    }
#endif
  }
  return fProbOfCollision;
}

#if (CD_USE_BICYCLE_COLL_HYPOTHESIS)||(CD_USE_PED_COLL_HYPOTHESIS)
/*************************************************************************************************************************
  Functionname:         CDPSCCalcCorridorWidthCrossVru                                                                        */ /*!

  @brief                Calculates the width of left and right sides of the asymmetric ego vehicle corridor.

  @description          Calculates the width of left and right sides of the asymmetric ego vehicle corridor
                        based on Ego speed and object velocity to trajectory as following:
                        1- Determine the maximum additional width to be added to ego vehicle width on both inlet and outlet sides 
                           of ego corridor based on ego speed. The additional width for both inlet and outlet ego corridor sides
                           are parameterized at @CD_EGO_ADD_WIDTH_IN_VELO_DEP_M and @CD_EGO_ADD_WIDTH_OUT_VELO_DEP_M.
                        2- Determine and apply the reduction factor on the additional corridor width based on the 
                           velocity to trajectory. Background: For the objects with low velocity to trajectory, 
                           the ego vehicle corridor shall not be expanded over the ego width.
                        3- Calculate the left and right part of corridor width for expanded ego corridor based on the position 
                           and direction of object.

                           @startuml CDPSCCalcCorridorWidthCrossVru.png
                           start
                           #Orange: Determine the additional ego corridor width
                           on both inlet and outlet sides based 
                           on the Ego Vehicle speed. The used lookup tables are:
                           <b>CD_EGO_ADD_WIDTH_IN_VELO_DEP_M</b>,  <b>CD_EGO_ADD_WIDTH_OUT_VELO_DEP_M</b> >
                           note left: >see **Additional Width Ego-Corridor Inlet Side** \n and **Additional Width Ego-Corridor Outlet Side**
                           #Orange:  Determine the decreasing factor for 
                           the corridor expansion based on the 
                           object velocity to trajectory. The used lookup table is:
                           <b>CD_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_M</b> >
                           note left: >see **Expansion Decrease Factor** \n
                           :Calculate the **Additional corridor width** of both inlet and outlet sides;
                            if (The object is on the left of ego trajectory or exactly on the ego trajectory?) then (Yes)
                              if(The object is crossing towards the trajectory or stationary?) then (Yes)
                                :1}
                                :**Width Left**  = **Inlet Side Width**;
                                :**Width Right** = **Outlet Side Width**;
                              else  (No)
                                :2}
                                :**Width Left**  = **Outlet Side Width**;
                                :**Width Right** = **Inlet Side Width**;
                              endif
                           else (No)
                            if(The object is crossing towards the trajectory or stationary?) then (Yes)
                              :3}
                              :**Width Left**  = **Outlet Side Width**;
                              :**Width Right** = **Inlet Side Width**;
                            else  (No)
                              :4}
                              :**Width Left**  = **Inlet Side Width**;
                              :**Width Right** = **Outlet Side Width**;
                            endif
                           endif
                           stop
                           @enduml

  @return               void

  @param[in]            iObjectIndex          : Index of the considered object. @range [0, EM_N_OBJECTS[
  @param[in,out]        fEgoVeloDepWidthLeft  : The calculated width of the left side of ego vehicle corridor width
  @param[in,out]        fEgoVeloDepWidthRight : The calculated width of the Right side of ego vehicle corridor width

  @glob_in              @ref ACDC_f_GetEgoVelObjSync \n
                        @ref ACDC_p_GetObjTrajRelation \n
                        @ref ACDC_p_GetEgoGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC \n
                        @ref CD_USE_BICYCLE_COLL_HYPOTHESIS \n
                        @ref CD_USE_PED_COLL_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Additional Width Ego-Corridor Inlet Side:**\n
                          \f$Width_{AdditionalInlet} = f(V_{Ego}) \f$
                        - **Additional Width Ego-Corridor Outlet Side:**\n
                          \f$Width_{AdditionalOutlet} = f(V_{Ego})\f$
                        - **Expansion Decrease Factor:**\n
                          \f$Factor_{DecreaseExpansion} = f(V_{ToTrajObj})\f$
                        - **Inlet Side Width:**\n
                          \f$Width_{InletSide} = 0.5 \cdot Width_{Ego} + Width_{AdditionalInlet} \cdot Factor_{DecreaseExpansion}\f$
                        - **Outlet Side Width:**\n
                          \f$Width_{OutletSide} = 0.5 \cdot Width_{Ego} + Width_{AdditionalOutlet} \cdot Factor_{DecreaseExpansion}\f$

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDPSCCALCCORRIDORWIDTHCROSSVRU_001 COU_TEST\n
                        @ref TEST_CDPSCCALCCORRIDORWIDTHCROSSVRU_002 COU_TEST\n
                        @ref TEST_CDPSCCALCCORRIDORWIDTHCROSSVRU_003 COU_TEST\n
                        @ref TEST_CDPSCCALCCORRIDORWIDTHCROSSVRU_004 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
void CDPSCCalcCorridorWidthCrossVru ( ObjNumber_t  const   iObjectIndex,
                                      float32            * fEgoVeloDepWidthLeft,
                                      float32            * fEgoVeloDepWidthRight )
{
  /* Get relevant Ego and object kinematics values */
  const float32 fEgoVelocityX                     = ACDC_f_GetEgoVelObjSync();
  const float32 fObjDistToEgoTraj                 = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTraj;
  const float32 fObjVrelToEgoTraj                 = ACDC_p_GetObjTrajRelation(iObjectIndex)->fVelocityToTraj;
  
  /* Determine the added width to the inlet side of the Ego corridor based on the Ego Vehicle speed */
  const float32 fAddCorrWidthInletEgoVel          = CML_f_CalculatePolygonValue( CD_NUMBER_OF_EGO_ADD_WIDTH_IN_VELO_DEP_VALUES, 
                                                                                 CD_EGO_ADD_WIDTH_IN_VELO_DEP_M, 
                                                                                 fEgoVelocityX                                   );
  /* Determine the added width to the outlet side of the Ego corridor based on the Ego Vehicle speed */
  const float32 fAddCorrWidthOutletEgoVel         = CML_f_CalculatePolygonValue( CD_NUMBER_OF_EGO_ADD_WIDTH_OUT_VELO_DEP_VALUES, 
                                                                                 CD_EGO_ADD_WIDTH_OUT_VELO_DEP_M, 
                                                                                 fEgoVelocityX                                   );
  /* Determine the decreasing factor for the corridor expansion based on the object velocity to trajectory.
  *  The corridor is not to be expanded for objects, which are approaching the ego corridor with low speed*/
  const float32 fDecreaseCorrWidthObjLatVelFact   = CML_f_CalculatePolygonValue( CD_NOF_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_VALUES, 
                                                                                 CD_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_M, 
                                                                                 fABS(fObjVrelToEgoTraj)                         );
  /* Calculate the net additional Ego-Vehicle corridor width for both corridor inlet and outlet sides */
  const float32 fEgoCorrAddedWidthInlet                = fAddCorrWidthInletEgoVel  * fDecreaseCorrWidthObjLatVelFact;
  const float32 fEgoCorrAddedWidthOutlet               = fAddCorrWidthOutletEgoVel * fDecreaseCorrWidthObjLatVelFact;

  /* Calculate the Ego-Corridor width on both sides based on the position and the speed of the object towards the trajectory */
  *fEgoVeloDepWidthLeft  = 0.5f * ACDC_p_GetEgoGeometry()->fWidth;
  *fEgoVeloDepWidthRight = 0.5f * ACDC_p_GetEgoGeometry()->fWidth;

  if (fObjDistToEgoTraj >= 0.0f)
  {
    if (fObjVrelToEgoTraj <= 0.0f)
    {
      /* The object is on the left side and moving towards the trajectory */
      *fEgoVeloDepWidthLeft  += fEgoCorrAddedWidthInlet;
      *fEgoVeloDepWidthRight += fEgoCorrAddedWidthOutlet;
    } 
    else
    {
      /* The object is on the left side and moving away from the trajectory */
      *fEgoVeloDepWidthLeft  += fEgoCorrAddedWidthOutlet;
      *fEgoVeloDepWidthRight += fEgoCorrAddedWidthInlet;
    }
  } 
  else
  {
    if (fObjVrelToEgoTraj >= 0.0f)
    {
      /* The object is on the right side and moving towards the trajectory */
      *fEgoVeloDepWidthLeft  += fEgoCorrAddedWidthOutlet;
      *fEgoVeloDepWidthRight += fEgoCorrAddedWidthInlet;
    } 
    else
    {
      /* The object is on the right side and moving away from the trajectory */
      *fEgoVeloDepWidthLeft  += fEgoCorrAddedWidthInlet;
      *fEgoVeloDepWidthRight += fEgoCorrAddedWidthOutlet;
    }
  }
}
#endif /* #if (CD_USE_BICYCLE_COLL_HYPOTHESIS)||(CD_USE_PED_COLL_HYPOTHESIS) */

/*************************************************************************************************************************
  Functionname:         CDPSCCalcProbCollisionPSC                                                                     */ /*!

  @brief                Calculates the probability of collision based on historical position information.

  @description          As the velocity to trajectory of an object may have a low reliability, the PSC distribution 
                        calculation determines the objects lateral velocity by differentiation of the distance to \n
                        trajectory. Therefore a number of historical positions of an object are saved. These positions 
                        are then set in relation to the actual trajectory by a calculation of the distance to trajectory \n
                        for each position. The following steps are explained according to the illustration 
                        "PSC Distribution Calculation". Each step is executed for each velocity: \n
                        - In **Step 1** the historical object positions are weighted according to their actuality 
                          (The older an object, the lower its weight) and their variance referring to their distance \n
                          to trajectory (The higher the variance, the lower the weight)
                        - In **Step 2** the objects are predicted according to the velocity that shall be tested (=assumed velocity).
                        - In **Step 3** the distance between the position of the predicted historical objects and 
                          the ego trajectory is calculated (= DistToTraj).
                        - In **Step 4** all resulting DistToTraj are averaged.
                        - In **Step 5** the average DistToTraj is compared to each of the previously calculated 
                          DistToTraj values. If their deviation is high, the probability for the selected velocity is low.
                        - In **Step 6** the received probabilites are averaged according to the weight of the historical objects.
                        At that point, the probability distribution for the velocity to trajectory is calculated. 
                        Accordingly, the integration under the distribution curve between the given boundary velocity represents the probability of collision.
                        \image html CD_PSCPscDistribution.svg "PSC Distribution Calculation" width=1800
                        @startuml CDPSCCalcProbCollisionPSC_activity.png
                        start
                          #Orange:Get all objects history positions:
                          <b>CDGetCompleteHistory</b> >
                          #Orange:Calculate the distance to trajectory 
                          for each history position:
                          <b>CDCalcHistDistToTraj</b> >
                          partition "Execute for each assumed velocity" {
                            :Calculate weight of each history position;
                            note left: >see formula "Weight"
                            :Calculate average distance the object 
                            should have based on the assumed velocity;
                            note left: >see formula "Average Distance"
                            :Calculate overall Error for the assumed velocity;
                            note left: >see formula "Error"
                            :Calculate probability for the assumed velocity;
                            note left: >see formula "Probability"
                          }
                          #Orange:Calculate Normalization factor and
                          normalize the calculated probabilities:
                          <b>CDHistIntegrate</b> >
                          note left: >see Formula "Normalize Probabilites"
                          #Orange:Calculate the prob. of collision considering
                          the velocity boundaries:
                          <b>CDHistIntegrate</b> >
                        stop
                        @enduml
  @return               void

  @param[in]            iObjectIndex           : Object index. @range [0,EM_N_OBJECTS[
  @param[in]            afPossibleVelocity_mps : Velocity range of distribution. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fCollCorrVeloLeft_mps  : Left limit of velocity corridor. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fCollCorrVeloRight_mps : Right limit of velocity corridor. @phys_unit [m/s] @range ]-...,+...[
  @param[in,out]        pfPSCProbCollision     : The probability of collision based on PSC @range [0,1]

  @glob_in              @ref ACDC_p_GetObjKinematicHistory
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     For all formulas: \n
                        \f$n =\f$ Number of the history position \n
                        \f$k =\f$ Number of the assumed velocity \n
                        \f$t_{Hist} = \f$ Time that passed since the object was at the considered history position \n
                        - **Formula Weight:**\n
                          \f$Weight_{Var,1-n} = \frac{1}{\sqrt{|Y_{ToTraj,Var,History,1-n}|} + CONSTANT}\f$ \n
                          \f$Weight_{Age,1-n} = \f$ Linear Interpolation between 0.5 and 1.5\n
                          \f$Weight_{1-n} = Weight_{Age,1-n} \cdot Weight_{Var,1-n}\f$
                        - **Formula Average Distance:**\n
                          \f$Y_{Assumed,Obj,1-n}= Y_{ToTraj,Hist,1-n} - (t_{Hist,1-n} \cdot V_{Assumed,Obj})\f$ \n
                          \f$Y_{Avg,Now,Obj} = \frac{\sum_{1-n}{Y_{Assumed,Obj,1-n} * Weight_{1-n}}}{Weight}\f$
                        - **Formula Error:**\n
                          \f$AllowedError = \f$ Lateral tolerance resulting from the velocity step size \n
                          \f$Error_{1-n} = |Y_{Assumed,Obj,1-n} - Y_{Avg,Now,Obj}| - AllowedError \f$ \n
                          \f$Error = \frac{\sum_{1-n}{Error_{1-n} \cdot Weights_{1-n}}}{NofHistoryValues \cdot Weight_{Max}}\f$ \n
                          The Error is calculated for each Assumed velocity \f$V_{Assumed,Obj,1-k}\f$
                        - **Formula Probability:**\n
                          \f$P_{1-k} = \frac{CONSTANT_A}{CONSTANT_B + Error_{1-k}^3}\f$
                        - **Formula Normalize Probabilites:**\n
                          \f$P_{1-k} = \frac{P_{1-k}}{NormalizationFactor}\f$

  @author               Gregor Powarzynski | Gregor.Powarzynski@continental-corporation.com | 

  @testmethod           @ref TEST_CDPSCCALCPROBCOLLISIONPSC_001 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPSCCalcProbCollisionPSC( ObjNumber_t              iObjectIndex,
                                      float32     const         afPossibleVelocity_mps[CD_PSC_PROB_VELO_STEPS_N],
                                      float32     const         fCollCorrVeloLeft_mps,
                                      float32     const         fCollCorrVeloRight_mps,
                                      float32           * const pfPSCProbCollision )
{
  CDKinHistObj_t const * const pObjKinHist = ACDC_p_GetObjKinematicHistory(iObjectIndex);
  float32 afPSCVelocityProbabilities  [CD_PSC_PROB_VELO_STEPS_N];
  float32 afDistToTrajHistory         [CD_PSC_PROB_OBSERVE_Y_DIST_N];
  float32 afDistOnTrajHistory         [CD_PSC_PROB_OBSERVE_Y_DIST_N];
  float32 afDistToTrajVarHistory      [CD_PSC_PROB_OBSERVE_Y_DIST_N];
  float32 afTimeVec_s                 [CD_PSC_PROB_OBSERVE_Y_DIST_N];
  float32 afWeights                   [CD_PSC_PROB_OBSERVE_Y_DIST_N];
  float32 fWeightSum        = 0.0f;
  float32 fMaxWeight        = 0.0f;
  float32 fBWeighted        = 0.0f; /* Best linear fitted function: y=obj_velo_mps*t+fBWeighted */
  float32 fError            = 0.0f;
  float32 fWeightStdPart;
  float32 fWeightLinearPart;
  float32 fPSCConst_T;
  float32 fPSCConst_Y;
  float32 fPSCConst_B;
  float32 fAllowedErrorDiscretization;
  float32 fAllowedError;
  float32 fExpectedYDist;
  float32 fErrorAtThisPoint;
  float32 fNormFac;
  uint32   i;
  uint32   j;
  uint8   uiNumberOfValidDataPoints;

  /************************************************************************/
  /* Start calculation of a velocity probability density function based   */
  /* on the last measured y distance values                               */
  /************************************************************************/
  /* Get the last y distVar values and save it in the variable afDistToTrajVarHistory*/
  uiNumberOfValidDataPoints = CDGetCompleteHistory( &(pObjKinHist->sPosYVar),
                                                    afDistToTrajVarHistory,
                                                    CD_PSC_PROB_OBSERVE_Y_DIST_N  );
  /* Calculates the Distance to Trajectory for a given ObjectDescription and save them in afDistToTrajHistory and afDistOnTrajHistory */
  CDCalcHistDistToTraj(   pObjKinHist                  ,
                          CD_PSC_PROB_OBSERVE_Y_DIST_N ,
                          afDistToTrajHistory          ,
                          afDistOnTrajHistory           );

  /* Iterate over all possible velocities */
  for (i=0; i<CD_PSC_PROB_VELO_STEPS_N; ++i)
  {
    fWeightSum = 0.0f;
    fMaxWeight = 0.0f;
    fBWeighted = 0.0f; /* Best linear fitted function: y=obj_velo_mps*t+fBWeighted */
    fError     = 0.0f;

    /* Calculate Weights for y distance history */
    for(j=0; j<CD_PSC_PROB_OBSERVE_Y_DIST_N; ++j)
    {
      if (((CD_PSC_PROB_OBSERVE_Y_DIST_N - j) - 1u) < uiNumberOfValidDataPoints)
      {
        /*f(distance to trajectory)*/
        fWeightStdPart    = 1.0f / (SQRT( fABS(afDistToTrajVarHistory[((CD_PSC_PROB_OBSERVE_Y_DIST_N - j) - 1u)]) ) + CD_PSC_VELO_WEIGHT_STD_B);
        fWeightLinearPart = ( ((CD_PSC_VELO_WEIGHT_YOUNGEST-CD_PSC_VELO_WEIGHT_OLDEST)/((float32)(CD_PSC_PROB_OBSERVE_Y_DIST_N-1u))) * (float32)j) + CD_PSC_VELO_WEIGHT_OLDEST;

        afWeights[j] = fWeightStdPart * fWeightLinearPart;
        fWeightSum  += afWeights[j];
        fMaxWeight   = MAX_FLOAT(fMaxWeight, afWeights[j]);
      }
      else
      {
        afWeights[j] = 0.0f;
      }
      /* Create the time vector (last Y_DIST_N cycle times) */
      afTimeVec_s[j] = -((((float32)CD_PSC_PROB_OBSERVE_Y_DIST_N - (float32)j) - 1.0f) * ACDC_f_GetCycleTime());
    }

    /* Fit linear function */
    for(j=0; j<CD_PSC_PROB_OBSERVE_Y_DIST_N; ++j)
    {
      if (((CD_PSC_PROB_OBSERVE_Y_DIST_N - j) - 1u) < uiNumberOfValidDataPoints)
      {
        fPSCConst_T = afTimeVec_s[j];
        fPSCConst_Y = afDistToTrajHistory[((CD_PSC_PROB_OBSERVE_Y_DIST_N - j) - 1u)];
        fPSCConst_B = fPSCConst_Y - (fPSCConst_T*afPossibleVelocity_mps[i]);
        /* The division is safe regarding division by zero */
        fBWeighted += (fPSCConst_B * afWeights[j]) / fWeightSum;
      }
    }

    /* Calculate Error */
    for(j=0; j<CD_PSC_PROB_OBSERVE_Y_DIST_N; ++j)
    {
      if (((CD_PSC_PROB_OBSERVE_Y_DIST_N - j) - 1u) < uiNumberOfValidDataPoints)
      {
        /*
        Allowed Error:
        - Discretization Compensation (linear function starting in fBWeighted, with gradient ped_velo_mps+CD_PSC_STEP_SIZE_VELOCITY/2)
        - Constant offset
        */
        fPSCConst_T                 = afTimeVec_s[j];
        fAllowedErrorDiscretization = fABS((fPSCConst_T*CD_PSC_STEP_SIZE_VELOCITY)*0.5f);/*PRQA S 3121*//*physical constant*/
        fAllowedError               = fAllowedErrorDiscretization + CD_PSC_VELO_ALLOWED_CONST_ERROR_M;
        fExpectedYDist              = (afPossibleVelocity_mps[i] * fPSCConst_T) + fBWeighted;
        fErrorAtThisPoint           = MAX_FLOAT(0.0f, (fABS(afDistToTrajHistory[((CD_PSC_PROB_OBSERVE_Y_DIST_N - j) - 1u)] - fExpectedYDist) - fAllowedError) );
        /* Add weighted error (The division is safe regarding division by zero)*/
        fError += (fErrorAtThisPoint*afWeights[j]) / ((float32)CD_PSC_PROB_OBSERVE_Y_DIST_N*fMaxWeight);

      }
    }
    /* Map Error to Probability (The division is safe regarding division by zero) */
    afPSCVelocityProbabilities[i] = CD_PSC_VELO_MAP_ERROR_PROB_CONST_A / (CD_PSC_VELO_MAP_ERROR_PROB_CONST_B + ( fError*fError*fError ));
  }
  
  /* Normalize Probability */
  CDHistIntegrate( afPossibleVelocity_mps, afPSCVelocityProbabilities, afPossibleVelocity_mps[0], afPossibleVelocity_mps[CD_PSC_PROB_VELO_STEPS_N-1u],
                   CD_PSC_PROB_VELO_STEPS_N, &(fNormFac));
  if ( fNormFac  > C_F32_DELTA )
  {
    for (i = 0; i < CD_PSC_PROB_VELO_STEPS_N; ++i)
    {
      afPSCVelocityProbabilities[i] = afPSCVelocityProbabilities[i] / fNormFac;
    }
  }

  /* Integrate afVelocityProbabilities between CollCorrVelo{left,right} */
  CDHistIntegrate(  afPossibleVelocity_mps,
                    afPSCVelocityProbabilities,
                    fCollCorrVeloLeft_mps,
                    fCollCorrVeloRight_mps,
                    CD_PSC_PROB_VELO_STEPS_N,
                    pfPSCProbCollision);

  *pfPSCProbCollision = MIN_FLOAT(1.0f, *pfPSCProbCollision);

  /* Fill simulation relevant  global variables */
#ifdef ACDC_SIMU
  {
    CDPSCObjDataDebug_t * pObjPSCSimuData = &(ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sPSCObjDataDebug);
    uint32  uIndex;

    for (uIndex = 0; uIndex < CD_PSC_PROB_VELO_STEPS_N; ++uIndex)
    {
      pObjPSCSimuData->afPSCVelocityProb[uIndex] = afPSCVelocityProbabilities[uIndex];
    }
  }
#endif
}/* PRQA S 7002,7004 # Date:2020-06-03, Reviewer: Praveen Annareddy , Reason: suppressing cyclomatic complexity for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         CDPSCCalcProbCollisionGaussian                                                                */ /*!

  @brief                Calculate the collision probability based on a Gaussian distribution for the velocity to trajectory. \n\n

  @description          The Gaussian distribution is calculated on base of the assumed velocity and the variance 
                        of the velocity to trajectory or to the predicted collision point. The result is normalized. 
                        Accordingly, the integration under the distribution curve between the given boundary velocity represents the probability of collision.
                        An example for a resulting distribution is shown in the illustration "Gaussian distribution PSC".
                        @startuml CDPASCCalcDistributionGaussian_activity.png
                        start
                        if ( ( ref point == collision point ) && ( obj position != collision point) ) then (yes)
                        partition #LightBlue **CD_USE_TURNINTOVRU_HYPOTHESIS** {
                          : project object mean velocity and standard deviation onto orthogonal to
                            ego velocity vector at collision point;
                            note left: > see formula "projection"
                         }
                        else (no)
                          : use object to traj velocity and standard deviation;
                        endif
                        #Orange:Calculate Gaussian CDF for 
                        right and left limit of velocity range:
                        <b>CML_f_CalcStdGaussianCDF</b> >
                        :Calculate Probability for a certain velocity;
                        note left: >see formula "Velocity Probability"
                        stop
                        @enduml
                        \image html CD_PSCGaussian.svg "Gaussian distribution PSC" width = 1000
  @return               static void

  @param[in]            iObjectIndex           : Index of the considered object. @range[0, EM_N_OBJECTS[
  @param[in]            fCollCorrVeloLeft_mps  : Left limit of velocity corridor. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fCollCorrVeloRight_mps : Right limit of velocity corridor. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            eRefPointType          : switch for reference point (to traj or to collision point)
  @param[in,out]        pfGaussProbCollision   : The probability of collision based on Gaussian distribution @range [0,1]


  @glob_in              @ref ACDC_p_GetObjTrajRelation
                        @ref ACDC_p_GetObjMovement \n
                        @ref AIP_p_GetACDCEgoTraj \n

  @glob_out             None

  @c_switch_part        @ref CD_USE_TURNINTOVRU_HYPOTHESIS
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula velocity probability:**\n
                          \f$P = P_{Left} - P_{Right}\f$\n
                        - **Formula velocity projection*
                           Define normalized orthogonal to ego velocity vector at collision
                          \f$ v^{N}_{Orth}(TTC) = v_{Orth}(TTC) /  \left | v_{Orth}(TTC) \right | \f$\n
                           where, \f$ (v_{Orth}(TTC).v_{Ego}(TTC)) = 0 \f$
                           Projected velocity:\n
                           \f$ v_{obj,toColPt} =  v^{N}_{Orth}(TTC) \cdot v_{Obj} \f$ \n
                           with velocity of object as \f$v_{Obj}\f$\n 
                           Standard deviation of velocity projected onto \f$x = v^{N}_{Orth}(TTC)\f$:\n
                           \f$ \sigma_{v_{obj,toColPt}} = \sqrt{ x^\top \Sigma_{v_{Obj}} x }\f$
                           with given object velocity covariance matrix \f$\Sigma_{v_{Obj}}\f$
  @author               Gregor Powarzynski

  @testmethod           @ref TEST_CDPSCCALCPROBCOLLISIONGAUSSIAN_001 COU_TEST\n
                        @ref TEST_CDPSCCALCPROBCOLLISIONGAUSSIAN_002 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPSCCalcProbCollisionGaussian( ObjNumber_t                       iObjectIndex,
                                            float32             const         fCollCorrVeloLeft_mps,
                                            float32             const         fCollCorrVeloRight_mps,
                                            CDPSCRefPointType_t const         eRefPointType,
                                            float32                   * const pfGaussProbCollision )
{
  ACDCObjToTrajRelation_t const * const pObjTrajRelation = ACDC_p_GetObjTrajRelation(iObjectIndex);
  float32                               fPedVeloToTraj;    /* if toCollPt is set, then this is velocity to collision point (ego front center) */
  float32                               fPedVeloToTrajStd; /* if toCollPt is set, then this refers to velocity to collision point (ego front center) */
  float32                               fGaussCDFLeft;
  float32                               fGaussCDFRight;

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  ACDCObjMovement_t const * const pObjMovement   = ACDC_p_GetObjMovement(iObjectIndex);
  ACDCTrajPred_t    const * const pEgoTrajectory = AIP_p_GetACDCEgoTraj(ACDC_MANEUVER_KinematicsWithoutAcceleration_Front);
  SFLVector2D_t                   EgoPosAtTTCDummy;         /* dummy variable for unused function input/output */
  SFLVector2D_t                   EgoVelAtTTC;              /* ego velocity vector at collision */
  SFLVector2D_t                   NormEgoVelOrthAtTTC;      /* normalized orthogonal to ego velocity vector at collision */
  float32                         fEgoVelOrthAtTTCLen;      /* length of orthogonal to ego velocity vector at collision */ 
  float32                         fCurrentObjTTC;           /* time at which ego and object have minimal distance */
  float32                         fMinDistDummy;            /* dummy variable for unused function input/output */
  float32                         fCurDistDummy;            /* dummy variable for unused function input/output */
  
  if ( eRefPointType == CD_PSC_USE_TO_COLL_POINT)
  { 
    /* get time at which ego and object have minimal distance */
    EMPCalcDynObjToEgoFrontRelation( iObjectIndex, &fCurrentObjTTC, &EgoPosAtTTCDummy, &fMinDistDummy, &fCurDistDummy);
    
    /* calculate the unit vector for the orthogonal of ego velocity at collision (assumption: tanget to trajectory) */
    EMPCalcVelocityAtTime (fCurrentObjTTC,pEgoTrajectory,&EgoVelAtTTC);
    NormEgoVelOrthAtTTC.fX = -EgoVelAtTTC.fY;
    NormEgoVelOrthAtTTC.fY =  EgoVelAtTTC.fX;
    fEgoVelOrthAtTTCLen    =  SQRT(SQR(NormEgoVelOrthAtTTC.fX) + SQR(NormEgoVelOrthAtTTC.fY));

    if (fEgoVelOrthAtTTCLen > C_F32_DELTA)
    {
      /* normalize vector of orthogonal to ego velocity at collision (assumption: tanget to trajectory) */
      NormEgoVelOrthAtTTC.fX /= fEgoVelOrthAtTTCLen;
      NormEgoVelOrthAtTTC.fY /= fEgoVelOrthAtTTCLen;
      /* project velocity and variance onto vector of orthogonal to ego velocity at collision */
      fPedVeloToTraj = /* < EgoVelOrthAtTTC , v_Obj > / |EgoVelOrthAtTTC| where EgoVelOrthAtTTC is orthogonal to EgoVelAtTTC */ 
        (NormEgoVelOrthAtTTC.fX * pObjMovement->Abs.Vel.fX) + 
        (NormEgoVelOrthAtTTC.fY * pObjMovement->Abs.Vel.fY); 
      /* Covariance matrix Var.Vel is diagonal matrix */
      fPedVeloToTrajStd = /* Std = sqrt( x^T Sigma_vel x) with x = EgoVelOrthAtTTC / |EgoVelOrthAtTTC|*/
        MAX( CD_PED_COLL_PED_MIN_VELO_TO_TRAJ_STD, 
        SQRT( (pObjMovement->Var.Vel.fX * SQR(NormEgoVelOrthAtTTC.fX)) +
              (pObjMovement->Var.Vel.fY * SQR(NormEgoVelOrthAtTTC.fY)) ) );
    }
    else /* object is at collision point -> take velocity to traj */
    {
      fPedVeloToTraj = pObjTrajRelation->fVelocityToTraj; 
      fPedVeloToTrajStd = MAX( CD_PED_COLL_PED_MIN_VELO_TO_TRAJ_STD,
                               SQRT(pObjTrajRelation->fVelocityToTrajVar) );
    }
  }
  else /* use toTraj relation */
#else /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
  _PARAM_UNUSED(eRefPointType);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
  {
    fPedVeloToTraj = pObjTrajRelation->fVelocityToTraj;
    fPedVeloToTrajStd = MAX( CD_PED_COLL_PED_MIN_VELO_TO_TRAJ_STD,
                             SQRT(pObjTrajRelation->fVelocityToTrajVar) );
  }

  /* Calculate the Integral of the Gauss Function between the velocity boundaries */
  fGaussCDFLeft  = CML_f_CalcStdGaussianCDF(fCollCorrVeloLeft_mps, fPedVeloToTraj, fPedVeloToTrajStd );
  fGaussCDFRight = CML_f_CalcStdGaussianCDF(fCollCorrVeloRight_mps, fPedVeloToTraj, fPedVeloToTrajStd );
  *pfGaussProbCollision = CML_f_Abs(fGaussCDFRight - fGaussCDFLeft);

#ifdef ACDC_SIMU
  {
    CDPSCObjDataDebug_t * pObjPSCSimuData =  &(ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sPSCObjDataDebug);
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
    if ( eRefPointType == CD_PSC_USE_TO_COLL_POINT)
    {
      pObjPSCSimuData->fCenterToCollPtVelStd = fPedVeloToTrajStd;
      pObjPSCSimuData->fCenterToCollPtVel = fPedVeloToTraj;
    }
    else
#endif /* CD_USE_TURNINTOVRU_HYPOTHESIS */
    {
      pObjPSCSimuData->fCenterVelocityStd = fPedVeloToTrajStd;
    }
  }

#endif

} /* End Calculate Gaussian*/

/*************************************************************************************************************************
  Functionname:         CDPSCCalcFusedProb                                                                   */ /*!

  @brief                Fuses the probabilities of collision, which are calculated based on Gaussian and PSC distributions 
                        to one final probability of collision.

  @description          The collision probabilities of the Gaussian distribution (see \ref CDPSCCalcProbCollisionGaussian) 
                        and the PSC distribution (see \ref CDPSCCalcProbCollisionPSC) are fused \n
                        according to the formula "Fused Distribution". \n
                        The weight factor is constant with the value \ref CD_PSC_VELO_ADD_MEASURED_VELO_MAX_WEIGHT. \n

  @return               void

  @param[in]            fGaussProbCollision : The probability of collision based on Gaussian distribution @range [0,1]
  @param[in]            fPSCProbCollision :   The probability of collision based on PSC distribution @range [0,1]
  @param[in, out]       pfFusedVelocityProb : The Fused probability of collision @range [0,1]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  fGaussProbCollision and fPSCProbCollision have been calculated.
  @post                 None

  @InOutCorrelation     - **Formula Fused distribution:** \n
                          \f$P = P_{PSC} + (P_{Gauss} - P_{PSC}) \cdot Weight\f$ \n

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDPSCCALCFUSEDPROB_001 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPSCCalcFusedProb( float32 const         fGaussProbCollision,
                                float32 const         fPSCProbCollision,
                                float32       * const pfFusedVelocityProb )
{
  float32 fWeight;
  /* calculate the weigh of the Gaussian part */
  fWeight = CD_PSC_VELO_ADD_MEASURED_VELO_MAX_WEIGHT;
  *pfFusedVelocityProb = fPSCProbCollision + ( (fGaussProbCollision - fPSCProbCollision) * fWeight);
}

/*************************************************************************************************************************
  Functionname:         CDPSCCalcVelCorridor                                                                         */ /*!

  @brief                Calculates a velocity corridor in which a crossing vehicle collides with the ego vehicle.

  @description          Calculates the minimum and maximum velocity a crossing object can have to collide with the ego vehicle.
                        @startuml CDPSCCalcVelCorridor_activity.png
                        start
                          :Calculate the projection of the 
                          object width on the ego perspective;
                          note left: >see Formula "Object Projection"

                          :Calculate velocity to 
                          enter corridor at TTC;
                          note left
                            For object moving to the left:
                            Left Object Edge = Right Trajectory edge
                            >see formula "Velocity Enter"
                          end note
                          :Calculate velocity to 
                          leave corridor at TTC;
                          note left
                            For object moving to the left:
                            Right Object Edge = Left Trajectory edge
                            >see Formula "Velocity Leave"
                          end note
                        stop
                        @enduml

                        For the calculation the used TTC is the TTC3 which only considers current positions and velocities.
                        It therefore provides a higher stability.

  @return               void

  @param[in]            iObjectIndex :            Index of the considered Object. @range [0,EM_N_OBJECTS[
  @param[in]            fEgoCorridorWidthLeft :   Left ego vehicle corridor width. @phys_unit [m] @range ]0,+...[
  @param[in]            fEgoCorridorWidthRight :  Right ego vehicle corridor width. @phys_unit [m] @range ]0,+...[
  @param[in,out]        pfCollCorrVeloLeft_mps :  Left limit of velocity corridor. @phys_unit [m] @range ]-...,+...[
  @param[in,out]        pfCollCorrVeloRight_mps : Right limit of velocity corridor. @phys_unit [m] @range ]-...,+...[

  @glob_in              @ref ACDC_p_GetObjGeometry \n
                        @ref ACDC_p_GetObjTrajRelation \n
                        @ref CD_f_GetTTC3
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Object Projection:** \n
                          \f$ Width_{Obj,Proj} = |\cos(Orientation_{Obj})|\cdot Width_{Obj} + |\sin(Orientation_{Obj})|\cdot Length_{Obj}\f$
                        - **Formula Velocity Enter:** \n
                          \f$ V_{TTC,Enter} = \frac{-(Dist_{ToTraj}-Width_{Obj,Proj}\cdot 0.5) - (Width_{Ego} \cdot Factor \cdot 0.5)}{t_{TTC}}\f$
                        - **Formula Velocity Leave:** \n
                          \f$ V_{TTC,Leave} = \frac{-(Dist_{ToTraj}-Width_{Obj,Proj}\cdot 0.5) + (Width_{Ego} \cdot Factor \cdot 0.5)}{t_{TTC}}\f$

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDPSCCALCVELCORRIDOR_01 COU_TEST\n
                        @ref TEST_CDPSCCALCVELCORRIDOR_02 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPSCCalcVelCorridor( ObjNumber_t const         iObjectIndex,
                                  float32     const         fEgoCorridorWidthLeft,
                                  float32     const         fEgoCorridorWidthRight,
                                  float32           * const pfCollCorrVeloLeft_mps,
                                  float32           * const pfCollCorrVeloRight_mps )
{
  /* Get the object distance to trajectory */
  ACDCGeometry_t const * const pGeometry = ACDC_p_GetObjGeometry(iObjectIndex);
  const float32 fObjDistToEgoTraj_m      = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTraj;
  /* get object geometric data */
  const float32 fObjWidth_m         = pGeometry->fWidth;
  const float32 fObjLength_m        = pGeometry->fLength;
  const float32 fObjOrientation_rad = pGeometry->fOrientation;
  /* Calculate the object projected width for ego view */
  const float32 fCosObjOrientation  = COS_(fObjOrientation_rad);
  const float32 fSinObjOrientation  = SIN_(fObjOrientation_rad);
  const float32 fObjYProjLength_m   = (fABS(fCosObjOrientation)*fObjWidth_m) + (fABS(fSinObjOrientation)*fObjLength_m);
  const float32 fCurrentObjTTC3     = CD_f_GetTTC3(iObjectIndex);

  /************************************************************************/
  /*    Calculate the minimum and maximum collision corridor velocity     */
  /************************************************************************/
  /* TTC3 is used due to its higher level of robustness, as the acceleration is not considered */
  if (fCurrentObjTTC3 > C_F32_DELTA) 
  {
    /*PRQA S 3121 4*//*physical constant*/
    *pfCollCorrVeloLeft_mps  = -((fObjDistToEgoTraj_m - (fObjYProjLength_m * 0.5f)) - (fEgoCorridorWidthLeft*CD_PSC_VELO_VEHICLE_PATH_FACTOR)) / fCurrentObjTTC3;
    *pfCollCorrVeloRight_mps = -((fObjDistToEgoTraj_m + (fObjYProjLength_m * 0.5f)) + (fEgoCorridorWidthRight*CD_PSC_VELO_VEHICLE_PATH_FACTOR)) / fCurrentObjTTC3;
  }
  else
  {
    *pfCollCorrVeloLeft_mps  = CD_PSC_PROB_VELO_MAX;
    *pfCollCorrVeloRight_mps = CD_PSC_PROB_VELO_MAX;
  }
}

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
/*******************************************************************************
  Functionname:         CDPSCCalcVelCorridorToCollPt                      */ /*!

  @brief                Calculates a velocity corridor in which a target collides
                        with the ego vehicle based upon EMP predictions

  @description          Calculates the minimum and maximum velocity a target can
                        have to collide with the ego vehicle.
                        Crash location and TTC are based upon EMP predictions.
                        @attention To approximate ego front position XofT.fC0 
                        is set to zero in EMP prediction.
                        @startuml CDPSCCalcVelCorridorEMP_activity.png
                        start
                        #Orange:Get TTC and projected distance to collision point based on EMP ego 
                        and object prediction:
                        <b>EMPCalcDynObjToEgoFrontRelation</b> >
                          note left
                            To approximate ego front position XofT.fC0 is set to zero
                          end note
                          :Calculate projected ego length;
                          note left
                            See formula "object projection"
                          end note
                          :Calculate vector between collision point and object current position;
                          note left
                            See formula "coll obj vector"
                          end note
                          :Calculate normalized orthogonal to velocity vector at collision;
                          note left
                            See formula "normal orthogonal vector"
                          end note
                          :Calculate projected distance between collision point and object position
                           on the orthogonal to velocity vector at collision
                          note left
                            See formula "projected distance"
                          end note
                          :Calculate minimal object velocity to enter corridor at TTC;
                          note left
                            See formula "velocity enter"
                          end note
                          :Calculate the maximal velocity to leave corridor at TTC;;
                          note left
                            See formula "velocity leave"
                          end note
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :           Index of the considered Object. @range [0,EM_N_OBJECTS[
  @param[in]            fEgoCorridorWidthLeft :  Left ego vehicle corridor width. @phys_unit [m] @range ]0,+...[
  @param[in]            fEgoCorridorWidthRight : Right ego vehicle corridor width. @phys_unit [m] @range ]0,+...[
  @param[in,out]        pfCollCorrVeloLeft :     Left limit of velocity corridor. @phys_unit [m/s] @range ]-...,+...[
  @param[in,out]        pfCollCorrVeloRight:     Right limit of velocity corridor. @phys_unit [m/s] @range ]-...,+...[

  @glob_in              @ref AIP_p_GetACDCEgoTraj \n
                        @ref ACDC_p_GetObjPositions \n
                        @ref ACDC_p_GetObjMovement \n
                        @ref ACDC_p_GetObjGeometry \n
                        @ref ACDC_p_GetObjDescMain
  @glob_out             @ref ACDC_p_ModSimuData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC \n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula object projection:** \n
                          see @image html drawingObjectProjections.svg, note \f$ \langle x_1^\perp, x_2^\perp\rangle = \langle x_1, x_2 \rangle \f$
                          Assumption: ego/obj velocity at TTC is tangent to trajectory at collision point\n
                          \f$ l_{Obj,Proj} = 
                            \frac{ b_{Obj} |\langle v_{Obj};v_{Ego}(TTC) \rangle| + l_{Obj} |\langle v_{Obj};v^\perp_{Ego}(TTC)\rangle|  }
                                 {\|v_{Ego}(TTC)\|\|v_{Obj}(TTC) \| }\f$
                        - **Formula coll obj vector:** \n
                          \f$ v_{ObjColpt} = p_{Obj}(0) - p_{Ego}(TTC) \f$\n
                          with ego position at TTC \f$p_{Ego}(TTC)\f$ and current obj. position \f$p_{Obj}(0)\f$\n
                        - **Formula normal orthogonal vector:** \n
                          \f$ v^{N}_{Orth}(TTC) = v_{Orth}(TTC) /  \left | v_{Orth}(TTC) \right | \f$\n
                           with \f$ (v_{Orth}(TTC).v_{Ego}(TTC)) = 0 \f$
                        - **Formula projected distance:** \n
                          \f$ dist_{toCollPt} = v^{N}_{Orth}(TTC) \cdot v_{ObjColpt} \f$
                        - **Formula velocity enter:** \n
                          \f$ v_{TTC,Enter} = \frac{ |dist_{toCollPt}| - \frac{1}{2} l_{Obj,Proj} - \frac{b_{Egocorridor}}{|cos(angle(v_{Ego}^\perp,v_{Obj}))|} }{TTC_{onTraj}} \f$
                        - **Formula velocity leave:** \n
                          \f$ v_{TTC,Leave} = \frac{ |dist_{toCollPt}| + \frac{1}{2} l_{Obj,Proj} - \frac{b_{Egocorridor}}{|cos(angle(v_{Ego}^\perp,v_{Obj}))|} }{TTC_{onTraj}} \f$
  @testmethod           @Generic_Testmethods

  @author               Matthias Lorenzen | matthias.lorenzen@continental-corporation.com
*******************************************************************************/
static void CDPSCCalcVelCorridorToCollPt( ObjNumber_t const         iObjectIndex,
                                          float32     const         fEgoCorridorWidthLeft,
                                          float32     const         fEgoCorridorWidthRight,
                                          float32           * const pfCollCorrVeloLeft,
                                          float32           * const pfCollCorrVeloRight )
{
  /* ego and obj vel to calc projected obj length and corridor width*/
  ACDCTrajPred_t     const * const pEgoTrajectory = AIP_p_GetACDCEgoTraj(ACDC_MANEUVER_KinematicsWithoutAcceleration_Front);
  ACDCObjPositions_t const * const pObjPositions        = ACDC_p_GetObjPositions(iObjectIndex); 
  SFLVector2D_t      const * const pObjMovAtTTC         = &(ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel);
  SFLVector2D_t                    EgoPosAtTTC;           /* collision point on ego trajectory at minimum distance time*/
  SFLVector2D_t                    EgoVelAtTTC;           /* ego velocity vector at TTC (assumption: tanget to trajectory)*/
  SFLVector2D_t                    CollPntToObjPos;       /* vector between collision point and current object position */
  SFLVector2D_t                    NormEgoVelOrthAtTTC;   /* normalized orthogonal to ego velocity at collision */
  /* target position and geometry data */
  float32            const         fObjWidth            = ACDC_p_GetObjGeometry(iObjectIndex)->fWidth;
  float32            const         fObjLength           = ACDC_p_GetObjGeometry(iObjectIndex)->fLength;
  float32                          fAbsCosVelObjEgo;      /* cosine of angle between obj velocity vector and ego vel at TTC vec (approx for road traj) */
  float32                          fAbsCosVelObjEgoOrth;  /* cosine of angle between obj velocity vector and rotated ego vel at TTC vec (approx for orth road traj) */
  float32                          fNormConst;            /* normalization constant */
  float32                          fObjProjLength;        /* projected target length on orthogonal to ego velocity vector */
  float32                          fCurrentObjTTC;        /* TTC on trajectory with reference point of ego trajectory changed to obj front */
  float32                          fEgoVelAtTTCLen;       /* length of the ego velocity vector at collision */ 
  float32                          fProjObjDistToCollPnt; /* projection of vector(Collpnt - Obj pos current) on orthogonal of ego velocity vector at collision */
  float32                          fObjDistDummy;         /* dummy variable for unused function input/output */
  float32                          fMinDistDummy;         /* dummy variable for unused function input/output */

#ifdef ACDC_SIMU
  CDPSCObjDataDebug_t * pObjPSCSimuData = &(ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sPSCObjDataDebug);
  ACDCTrajPred_t TargetTrajectory;
  SFLVector2D_t ObjPosAtTTC;
#endif

  /* Get TTC and Ego-position at collision based on EMP ego and object prediction */
  EMPCalcDynObjToEgoFrontRelation( iObjectIndex, &fCurrentObjTTC, &EgoPosAtTTC, &fMinDistDummy, &fObjDistDummy);

  /* Calculate projected target length (assumption: ego velocity vector tangent to traj at coll pt) */
  EMPCalcVelocityAtTime (fCurrentObjTTC,pEgoTrajectory,&EgoVelAtTTC);
  fNormConst = SQRT( SQR(pObjMovAtTTC->fX) + SQR(pObjMovAtTTC->fY) ) *
               SQRT( SQR(EgoVelAtTTC.fX) + SQR(EgoVelAtTTC.fY) ); /* |vObj|*|vEgo| */
  if ( fNormConst > C_F32_DELTA ) /* ego and object have positive velocity */
  {
    fAbsCosVelObjEgo     = fABS( ( (pObjMovAtTTC->fX * EgoVelAtTTC.fX) + (pObjMovAtTTC->fY * EgoVelAtTTC.fY) ) / 
                                  fNormConst );
    fAbsCosVelObjEgoOrth = fABS( ( (pObjMovAtTTC->fX * (-EgoVelAtTTC.fY)) + (pObjMovAtTTC->fY * EgoVelAtTTC.fX) ) / 
                                  fNormConst );
    fObjProjLength = (fObjLength * fAbsCosVelObjEgoOrth) + (fObjWidth * fAbsCosVelObjEgo);
  }
  else /* no information of object orientation (stationary object) */
  { /* @attention: can lead to switching of corridor width if obj. velocity is close to zero */
    fObjProjLength = fObjLength;
  }

  /* Calculate the vector between Collision point (Ego Fron at collision) and object current postion */
  CollPntToObjPos.fX      = pObjPositions->Center.fX - EgoPosAtTTC.fX;
  CollPntToObjPos.fY      = pObjPositions->Center.fY - EgoPosAtTTC.fY;
  /* Calculate the length of the ego velocity vector at TTC */
  fEgoVelAtTTCLen     = SQRT(SQR(EgoVelAtTTC.fX) + SQR(EgoVelAtTTC.fY));

  /************************************************************************/
  /*    Calculate the minimum and maximum collision corridor velocity     */
  /************************************************************************/
  if ((fCurrentObjTTC > C_F32_DELTA) && (fEgoVelAtTTCLen > C_F32_DELTA ))
  {
    /* Calculate the unit vector for the orthogonal of ego velocity at collision */
    NormEgoVelOrthAtTTC.fX  = -EgoVelAtTTC.fY/fEgoVelAtTTCLen;
    NormEgoVelOrthAtTTC.fY  =  EgoVelAtTTC.fX/fEgoVelAtTTCLen;

    /* Calculate the length of the projection of the Vector(Collpnt - current Obj pos) along the orthogonal of the Ego velocity vector at collision*/
    fProjObjDistToCollPnt   = (NormEgoVelOrthAtTTC.fX * CollPntToObjPos.fX) + (NormEgoVelOrthAtTTC.fY * CollPntToObjPos.fY);

    /*PRQA S 3121 4*//*physical constant*/
    *pfCollCorrVeloLeft  = -( ( fProjObjDistToCollPnt - (0.5f * fObjProjLength) ) - (fEgoCorridorWidthLeft) ) / fCurrentObjTTC;
    *pfCollCorrVeloRight = -( ( fProjObjDistToCollPnt + (0.5f * fObjProjLength) ) + (fEgoCorridorWidthRight) ) / fCurrentObjTTC;
  }
  else
  {
    *pfCollCorrVeloLeft  = CD_PSC_PROB_VELO_MAX;
    *pfCollCorrVeloRight = CD_PSC_PROB_VELO_MAX;
  }

#ifdef ACDC_SIMU
  EMPResetTrajPred( &TargetTrajectory);
  EMPPredictObjTraj( ACDC_p_GetObjDescMain(iObjectIndex), ACDC_MANEUVER_KinematicsUnchanged, &TargetTrajectory );
  EMPCalcPositionAtTime(fCurrentObjTTC, &TargetTrajectory, &ObjPosAtTTC); /* assumption of object is not rotating */

  pObjPSCSimuData->collPtEgoFront    = EgoPosAtTTC;
  pObjPSCSimuData->collPtToGenObjPos = ObjPosAtTTC;
#endif
}
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */

/*************************************************************************************************************************
  Functionname:         CDPSCGetPossibleVelocity                                                                     */ /*!

  @brief                Calculates an array filled with possible object velocities.

  @description          Calculates an array filled with possible object velocities. The reference for the 
                        velocities is the center object velocity (See illustration below). \n
                        The velocities range (\ref CD_PSC_VEL_GATE) around this center velocity is divided 
                        according to the array size (\ref CD_PSC_PROB_VELO_STEPS_N)
                        \image html CD_PSCPossibleVelocity.svg width=1200

  @return               void

  @param[in]            iObjectIndex :            Index of the considered object. @range[0, EM_N_OBJECTS[
  @param[in]            eRefPointType :           switch for reference point (to traj or to collision point)
  @param[out]           afPossibleVelocity_mps :  Velocity range of distribution. @phys_unit [m/s] @range ]-...,+...[

  @glob_in              @ref ACDC_p_GetObjTrajRelation
  @glob_out             None

  @c_switch_part        @ref CD_USE_TURNINTOVRU_HYPOTHESIS
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CDPSCGETPOSSIBLEVELOCITY_001 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPSCGetPossibleVelocity( ObjNumber_t         const iObjectIndex,
                                      CDPSCRefPointType_t const eRefPointType,
                                      float32                   afPossibleVelocity_mps[CD_PSC_PROB_VELO_STEPS_N] )
{
  float32 fCenterObjVelocity;
  float32 fMinObjVelocity;
  uint32  uIndex;

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  ACDCObjMovement_t const * const pObjMovement = ACDC_p_GetObjMovement(iObjectIndex);
  if ( eRefPointType == CD_PSC_USE_TO_COLL_POINT )
  {
    /* this should be velocity to collision point, taking absolute object
       velocity as a proxy in order to save calculation time */
    fCenterObjVelocity = SQRT( SQR(pObjMovement->Abs.Vel.fX) + SQR(pObjMovement->Abs.Vel.fY) );
  }
  else
#else
  _PARAM_UNUSED(eRefPointType);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
  {
    fCenterObjVelocity = ACDC_p_GetObjTrajRelation(iObjectIndex)->fVelocityToTraj;
  }

  /* calculate the minimum value in the velocity distribution range */
  fMinObjVelocity    = (fCenterObjVelocity) - (0.5f * CD_PSC_VEL_GATE);

  /* Calculate velocities that shall be checked */
  for (uIndex=0; uIndex<CD_PSC_PROB_VELO_STEPS_N; ++uIndex)
  {
    afPossibleVelocity_mps[uIndex] = (fMinObjVelocity + ((float32)uIndex*CD_PSC_STEP_SIZE_VELOCITY));
  }
}

/*!@}*/
#endif  /* CD_USE_GEN_PSC*/
#endif /* (ACDC_CFG_CD) */

