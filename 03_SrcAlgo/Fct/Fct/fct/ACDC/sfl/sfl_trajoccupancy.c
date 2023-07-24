/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 SFL (Safety Functions Library)

PACKAGENAME:               sfl_trajoccupancy.c

DESCRIPTION:               Functions for the calculation of the TTX values based on the TrajOccupancy

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             24.09.2018

VERSION:                   $Revision: 1.8 $

**************************************************************************** */
#include "sfl_int.h"

#if (ACDC_CFG_SFL)

/************************************************************************/
/*                      Module Description                              */
/************************************************************************/
/**
  @defgroup sfl_trajoccupancy Trajectory Occupancy
  @ingroup sfl
  @brief        This module provides functions for the calculation of the TTX values on base of the Trajectory occupancy. \n\n

  @description  The following functionalities are provided:
                - Calculate TTB and TTC: @ref SFL_v_TrajOccCalcTTX
  @{
  */

/***********************************************************************
  FUNCTION DECLARATIONS
************************************************************************/
static uint8 SFL_u_TrajOccCheckCollision(SFLTrajOccupancy_t const * const pTrajOccupancy,
                                         SFLPolyDeg2_t      const * const pInitialKinematics,
                                         uint8              const         uStartTimeStep,
                                         uint8              const         uStopTimeStep,
                                         float32            const         fEgoLength,
                                         float32            const         afDecelerations[]);

static uint8 SFL_u_TrajOccCheckCollisionHysteresis(SFLTrajOccupancy_t const * const pTrajOccupancy,
                                                   uint8            const         uLastCycleTTC,
                                                   SFLPolyDeg2_t    const * const pEgoKinematic,
                                                   float32 const fEgoLength,
                                                   float32  const afDecelerations[]);



/***********************************************************************
  FUNCTION DEFINITIONS
************************************************************************/

/*************************************************************************************************************************
  Functionname:         SFL_u_TrajOccCheckCollision                                                            */ /*!

  @brief                Checks if there will be a collision if the ego vehicle follows a list of given accelerations.

  @description          Checks in the trajectory occupancy if the ego vehicle will collide with any object. Therefore 
                        a "MiniSimulation" is calculated from the time uStartTimeStap until uStopTimeStep. during this 
                        period the decelerations given in the table afDecelerations are applied.
                        @startuml SFL_u_TrajOccCheckCollision_activity.png
                        start
                          partition "Execute for each time step between Start and Stop time\nas long as no collision is found" {
                            :Predict the Ego movement with the 
                            currently assumed deceleration;
                            note left:Only allow positive velocities.\nSet V = 0 if it gets negative.
                            :Check if the ego vehicle collides with 
                            any of the lines in the current time step;
                          }
                          if(A Collision was found?) then (Yes)
                            :1}
                            :uTimeColl = TimeStep at which the 
                            collision was detected;
                          else (No)
                            :2}
                            :Set uTimeColl to Default;
                          endif
                        stop
                        @enduml


  @return               uint8 : uTimeColl: TimeStep at which a collision is detected. is SFL_TRAJOCC_MAX_NOF_TIME_STEPS 
                                           if no collision is detected. @range [0,@ref SFL_TRAJOCC_MAX_NOF_TIME_STEPS]

  @param[in]            pTrajOccupancy :     Trajectory Occupancy interface
  @param[in]            pInitialKinematics : Initial kinematics of the ego vehicle.
  @param[in]            uStartTimeStep :     Time step at which the "Mini Simulation" starts. @range [0, @ref SFL_TRAJOCC_MAX_NOF_TIME_STEPS]
  @param[in]            uStopTimeStep :      Time step at which the "Mini Simulation" ends.   @range [0, @ref SFL_TRAJOCC_MAX_NOF_TIME_STEPS]
  @param[in]            fEgoLength :         Length of the ego vehicle. @range ]0,+...[, @phys_unit [m]
  @param[in]            afDecelerations :    Decelerations which shall be applied to the ego vehicle at certain time steps. @range ]-...,0], phys_unit [m/s^2]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_U_TRAJOCCCHECKCOLLISION_001 \n
                        @ref TEST_SFL_U_TRAJOCCCHECKCOLLISION_002 \n
						@ref TEST_SFL_U_TRAJOCCCHECKCOLLISION_003 \n
						@ref TEST_SFL_U_TRAJOCCCHECKCOLLISION_004 \n
						@ref TEST_SFL_U_TRAJOCCCHECKCOLLISION_005
  
  @traceability          Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static uint8 SFL_u_TrajOccCheckCollision(SFLTrajOccupancy_t const * const pTrajOccupancy,
                                         SFLPolyDeg2_t      const * const pInitialKinematics,
                                         uint8              const         uStartTimeStep,
                                         uint8              const         uStopTimeStep,
                                         float32            const         fEgoLength,
                                         float32            const         afDecelerations[])
{
  /*PRQA S 1031 1*//* 2018-09-24, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  SFLPolyDeg2_t CurrKinematic = *pInitialKinematics;
  uint8 uTimeStep;
  uint8 uTimeColl = SFL_TRAJOCC_MAX_NOF_TIME_STEPS;
  boolean bCollisionFound = b_FALSE;

  /* Step forwards and check in each timestep if there is a collision. Abort the loop if a collision is found*/
  for(uTimeStep = uStartTimeStep; (uTimeStep < (uStopTimeStep - 1u)) && (bCollisionFound == b_FALSE); ++uTimeStep)
  {
    uint8 uLineIdx;
    uint8 const uMinIdx = pTrajOccupancy->uTimeAccessTable[uTimeStep];
    uint8 const uMaxIdx = pTrajOccupancy->uTimeAccessTable[uTimeStep + 1u];
    float32 fDEgoMin;
    float32 fDEgoMax;

    if (CurrKinematic.fC1 > 0.f)
    {
      /* Select a deceleration according to the current timestep */
      CurrKinematic.fC2 = 0.5f * afDecelerations[uTimeStep - uStartTimeStep];
      /* Predict the ego vehicle */
      CurrKinematic.fC0 = SFL_f_EvalPolyDeg2(&CurrKinematic,SFL_TRAJOCC_STEP_SIZE_TIME);
      /* Predict the ego movement to the left edge of the line. 
      This distance describes the distance to the ego rear point.*/
      fDEgoMin          = CurrKinematic.fC0 - fEgoLength;
      /* Predict the ego movement to the right edge of the line. 
      This distance describes the distance to the ego front point after predicting extra cycle to offer the estimation line a width. 
      To compensate the effect of time discrete lines.*/
      fDEgoMax          = SFL_f_EvalPolyDeg2(&CurrKinematic,SFL_TRAJOCC_STEP_SIZE_TIME);
      /* Predict the ego velocity */
      CurrKinematic.fC1 += (2.f * CurrKinematic.fC2 * SFL_TRAJOCC_STEP_SIZE_TIME);
    }
    else
    {
      /* The ego velocity drops below 0, set deceleration and velocity to 0 (no backwards driving) */
      CurrKinematic.fC1 = 0.f;
      /*PRQA S 2982 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Finding is wrong Assignement ist not redundant due to loop*/
      CurrKinematic.fC2 = 0.f;
      fDEgoMin = CurrKinematic.fC0 - fEgoLength;
      fDEgoMax = CurrKinematic.fC0;
    }


    /* Check for all lines in the current time step if there is a collision */
    for(uLineIdx = uMinIdx; (uLineIdx < pTrajOccupancy->uNofLines) && (uLineIdx < uMaxIdx) && (bCollisionFound == b_FALSE); ++uLineIdx)
    {
      bCollisionFound =  (boolean)(b_FALSE==((fDEgoMax < pTrajOccupancy->fMinDistances[uLineIdx])  || (fDEgoMin > pTrajOccupancy->fMaxDistances[uLineIdx])));
    }
    uTimeColl       = (bCollisionFound==b_TRUE)?uTimeStep:SFL_TRAJOCC_MAX_NOF_TIME_STEPS;
  }


  return uTimeColl;
}

/*************************************************************************************************************************
  Functionname:         SFL_u_TrajOccCheckCollisionHysteresis                                                  */ /*!

  @brief                Calculates a hysteresis around the TTC of the last cycle to avoid toggling.

  @description          Checks for a collision in a range of 4 time steps around the TTC of the last cycle. 
                        Therefore the ego kinematic if shifted:
                        1. Simulate a ego movement delayed by  1 cycle.
                        2. Simulate a ego movement delayed by -1 cycle.
                        .
                        Calculate the collision time for both movements in the range of the 4 time steps.
                        @startuml SFL_u_TrajOccCheckCollisionHysteresis
                        start
                          :Initialize Time Steps:
                          T_Start = LastCycleTTC - 2
                          T_End   = T_Start + 4
                          T_1     = T_Start - 1
                          T_2     = T_Start + 2;
                          #Orange:Predict the ego movement up to T_1 and T_2
                          and simulate from T_Start to T_End each time:
                          <b>SFL_u_TrajOccCheckCollision</b> >
                          :Select the minimum of the
                          calculated collision times;
                          legend
                          T_start    = TimeStep to start the simulation
                          T_end      = TimeStep to end the simulation
                          T_1        = TimeStep 1 up to which the ego movement is predicted
                          T_2        = TimeStep 2 up to which the ego movement is predicted
                          endlegend
                        stop
                        @enduml

  @return               uint8 uTimeColl: Collision time if the hysteresis calculation is applied. @range[0,@ref SFL_TRAJOCC_MAX_NOF_TIME_STEPS]

  @param[in]            pTrajOccupancy :  Trajectory occupancy interface.
  @param[in]            uLastCycleTTC :   Time step of the TTC in the last cycle. @range [0, @ref SFL_TRAJOCC_MAX_NOF_TIME_STEPS]
  @param[in]            pEgoKinematic :   Kinematics of the ego vehicle.
  @param[in]            fEgoLength :      Length of the ego vehicle. @phys_unit [m], @range ]0,+...[
  @param[in]            afDecelerations : Table of decelerations over time. @phys_unit[m], @range ]-...,0]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_U_TRAJOCCCHECKCOLLISIONHYSTERESIS_001 \n
                        @ref TEST_SFL_U_TRAJOCCCHECKCOLLISIONHYSTERESIS_002
  
  @traceability          Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static uint8 SFL_u_TrajOccCheckCollisionHysteresis(SFLTrajOccupancy_t const * const pTrajOccupancy,
                                                   uint8              const         uLastCycleTTC,
                                                   SFLPolyDeg2_t      const * const pEgoKinematic,
                                                   float32            const         fEgoLength,
                                                   float32            const         afDecelerations[])
{
  /*PRQA S 1031 2*//* 2018-09-24, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  SFLPolyDeg2_t PreviousKinematic = *pEgoKinematic;
  SFLPolyDeg2_t NextKinematic     = *pEgoKinematic;
  uint8 const   uTTCCheck_TStart = (uLastCycleTTC    - 2u);
  uint8 const   uTTCCheck_TStop  = (uTTCCheck_TStart + 4u);
  uint8 const   uTTCCheck_TPrev  = (uTTCCheck_TStart - 1u);
  uint8 const   uTTCCheck_TNext  = (uTTCCheck_TStart + 1u);
  uint8         uTimeCollPrev = SFL_TRAJOCC_MAX_NOF_TIME_STEPS;
  uint8         uTimeCollNext = SFL_TRAJOCC_MAX_NOF_TIME_STEPS;


  /* Predict the ego vehicle to the previous and to the following time step => simulates increased length of the ego vehicle*/
  PreviousKinematic.fC0 = SFL_f_EvalPolyDeg2(&PreviousKinematic,(float32)uTTCCheck_TPrev * SFL_TRAJOCC_STEP_SIZE_TIME);
  PreviousKinematic.fC1 = PreviousKinematic.fC2 * (float32)uTTCCheck_TPrev * SFL_TRAJOCC_STEP_SIZE_TIME;
  NextKinematic.fC0     = SFL_f_EvalPolyDeg2(&NextKinematic    ,(float32)uTTCCheck_TNext * SFL_TRAJOCC_STEP_SIZE_TIME);
  NextKinematic.fC1     = NextKinematic.fC2     * (float32)uTTCCheck_TNext * SFL_TRAJOCC_STEP_SIZE_TIME;

  uTimeCollPrev = SFL_u_TrajOccCheckCollision(pTrajOccupancy, &PreviousKinematic, uTTCCheck_TStart, uTTCCheck_TStop, fEgoLength, afDecelerations);
  uTimeCollNext = SFL_u_TrajOccCheckCollision(pTrajOccupancy, &NextKinematic    , uTTCCheck_TStart, uTTCCheck_TStop, fEgoLength, afDecelerations);
  return MIN(uTimeCollNext,uTimeCollPrev);
}


/*************************************************************************************************************************
  Functionname:         SFL_v_TrajOccCalcTTX                                                                   */ /*!

  @brief                Calculates the TTB and TTC on base of the Trajectory occupancy.

  @description          Calculates the TTX values by iterating through the Trajectory Occupancy interface.
                        Checks in the first place if there is a collision with the current kinematics. If there is,
                        Checks several assumed TTBs. The start TTB is the current TTC.
                        @startuml SFL_v_TrajOccCalcTTX_activity.png
                        start
                          #Orange:Check if the ego vehicle collides with any 
                          object if it keeps the current kinematics:
                          <b>SFL_u_TrajOccCheckCollision</b> >
                          if(Collision is found?) then (Yes)
                            :Set the TTC as initial TTB;
                            partition "Loop backwards through possible TTBs\nuntil no more collision is found\nor TTB = 0 is reached" {
                              :Predict the ego movement up 
                              to the currently assumed TTB;
                              #Orange:Check if there will be a collision 
                              with the current TTB:
                              <b>SFL_u_TrajOccCheckCollision</b> >
                              if(A valid TTB is found\nAND the TTB is higher than the last cycle TTB?) then (Yes)
                                :1}
                                #Orange:Avoid a toggling effect by calculating a hysteresis:
                                <b>SFL_u_TrajOccCheckCollisionHysteresis</b> >
                              else (No)
                                :2}
                              endif
                            }
                          else(No)
                            :3}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            pTrajOccupancy :        Trajectory Occupancy Interface.
  @param[in]            afAssumedDeceleration : Table with assumed decelerations at certain timestamps. The resolution 
                                                of the table is @ref SFL_TRAJOCC_STEP_SIZE_TIME. @phys_unit [m/s^2] @range ]-...,0]
  @param[in]            fEgoLength :            Length of the ego vehicle. @phys_unit [m] @range ]0,+...[
  @param[in]            pEgoKinematic :         Kinematics of the ego vehicle as polynomial.
  @param[in,out]        pfTTC :                 In: TTC of the last cycle, Out: Calculated TTC. @phys_unit [s], @range [0,40]
  @param[in,out]        pfTTB :                 In: TTB of the last cycle, Out: Calculated TTB. @phys_unit [s], @range [0,40]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  The TTC and TTB of the last cycle are still stored in the variables pfTTC and pfTTB
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_V_TRAJOCCCALCTTX_001 \n
                        @ref TEST_SFL_V_TRAJOCCCALCTTX_002 \n
						@ref TEST_SFL_V_TRAJOCCCALCTTX_003 \n
                        @ref TEST_SFL_V_TRAJOCCCALCTTX_004 
  
  @traceability         Design Decision

  @todo                 The hysteresis part of the algorithm did work good in matlab. As the C implementation 
                        is slightly different it should be validated again on base of artificial scenarios.
                        E.g. object is crossing with 90° very short time before the ego vehicle.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void SFL_v_TrajOccCalcTTX(SFLTrajOccupancy_t const * const pTrajOccupancy,
                                float32            const         afAssumedDeceleration[],
                                float32            const         fEgoLength,
                                SFLPolyDeg2_t      const * const pEgoKinematic,
                                float32                  * const pfTTC,
                                float32                  * const pfTTB)
{

  uint8 uTTC;
  uint8 uTimeStepNo;
  float32 fTTB_tmp = SFL_TIME_MAX;
  float32 fTTC_tmp = SFL_TIME_MAX;
  float32 afCurrEgoDeceleration [SFL_TRAJOCC_MAX_NOF_TIME_STEPS] = {0};
  uint8 const uLastCycleTTB = (uint8)CML_u_Round2Uint(((*pfTTB-FCT_SEN_CYCLE_TIME) / SFL_TRAJOCC_STEP_SIZE_TIME));
  uint8 const uLastCycleTTC = (uint8)CML_u_Round2Uint(((*pfTTC-FCT_SEN_CYCLE_TIME) / SFL_TRAJOCC_STEP_SIZE_TIME));


  /* Check if the ego vehicle collides with any object with its current kinematics */
  for(uTimeStepNo = 0u; uTimeStepNo < SFL_TRAJOCC_MAX_NOF_TIME_STEPS; ++ uTimeStepNo)
  {
    afCurrEgoDeceleration[uTimeStepNo] = 2.f * pEgoKinematic->fC2;
  }
  uTTC = SFL_u_TrajOccCheckCollision(pTrajOccupancy, pEgoKinematic, 0u, (SFL_TRAJOCC_MAX_NOF_TIME_STEPS), fEgoLength, afCurrEgoDeceleration);
  
  if(    (uTTC  == SFL_TRAJOCC_MAX_NOF_TIME_STEPS )
      && (uTTC   > uLastCycleTTC                  ) )
  {
    /* If the TTC is higher than in the last cycle, a possible toggling was detected. Calculate a hysteresis in this case to avoid that effect */
    uint8 const uTimeCollHyst = SFL_u_TrajOccCheckCollisionHysteresis(pTrajOccupancy,uLastCycleTTC,pEgoKinematic,fEgoLength, afAssumedDeceleration);
    uTTC = MIN(uTTC,uTimeCollHyst);
  }

  if(uTTC < SFL_TRAJOCC_MAX_NOF_TIME_STEPS)
  {
    /* Start to search at the timestep of the collision */
    uint8 uTTBAssumed;
    uint8 uTimeColl;

    fTTC_tmp = (float32)uTTC * SFL_TRAJOCC_STEP_SIZE_TIME;

    uTimeColl = uTTC;
    /* If a collision is found, iterate backwards from the collision time until a timestep is found at which the given decelerations avoid a collision */
    for(uTTBAssumed = uTTC; (uTTBAssumed != 0u) && (uTimeColl < SFL_TRAJOCC_MAX_NOF_TIME_STEPS); --uTTBAssumed)
    {
      SFLPolyDeg2_t CurrKinematic;
      float32 const fTTBAssumed = (float32)(uTTBAssumed) * SFL_TRAJOCC_STEP_SIZE_TIME;
      
      /* Predict the ego movement up to the assumed TTB */
      CurrKinematic.fC0 = SFL_f_EvalPolyDeg2(pEgoKinematic,fTTBAssumed);
      CurrKinematic.fC1 = pEgoKinematic->fC1 + (2.f * (fTTBAssumed) * pEgoKinematic->fC2);

      /* Check if there will be a collision with the predicted kinematics and the assumed decelerations. If yes, continue the loop. If no, exit the loop: the TTB is found*/
      uTimeColl = SFL_u_TrajOccCheckCollision(pTrajOccupancy, &CurrKinematic, uTTBAssumed, (SFL_TRAJOCC_MAX_NOF_TIME_STEPS), fEgoLength, afAssumedDeceleration);
      if(    (uTimeColl         == SFL_TRAJOCC_MAX_NOF_TIME_STEPS )
          && (uTTBAssumed   > uLastCycleTTB              ) )
      {
        /* If the TTB is higher than in the last cycle, a possible toggling was detected. Calculate a hysteresis in this case to avoid that effect */
        uint8 const uTimeCollHyst = SFL_u_TrajOccCheckCollisionHysteresis(pTrajOccupancy,uLastCycleTTC,pEgoKinematic,fEgoLength, afAssumedDeceleration);
        uTimeColl = MIN(uTimeColl,uTimeCollHyst);
      }
    }

    /* Increment uTTBAssumed by 1 as it is decreased once more after the loop is terminated */
    /*PRQA S 4394 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Cast to float intended as implemented*/
    fTTB_tmp = (float32)(uTTBAssumed + 1u) * SFL_TRAJOCC_STEP_SIZE_TIME;

  }
  else
  {
    /* No collision is found on the current ego trajectory */
    fTTC_tmp = SFL_TIME_MAX;
    fTTB_tmp = SFL_TIME_MAX;
  }

  *pfTTB = fTTB_tmp;
  *pfTTC = fTTC_tmp;
}





 /*!@}*/
#endif

