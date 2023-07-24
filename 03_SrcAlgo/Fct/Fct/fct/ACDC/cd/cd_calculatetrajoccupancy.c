/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 CD (Collision Detection)

PACKAGENAME:               cd_calculatetrajoccupancy.c

DESCRIPTION:               Functions for the calculation of the trajectory occupancy

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             27.08.2018

VERSION:                   $Revision: 1.10 $


**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD && ACDC_CFG_CALC_TRAJ_OCCUPANCY)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_calculatetrajoccpuancy Trajectory Occupancy
@ingroup cd

@brief          Module for the calculation of the Trajectory Occupancy Map and the calculation of the criticality values TTB and TTC on base of it.

@description    This module provides the following functionalities:
                - Calculation of the Trajectory occupancy map: @ref CD_v_CalculateTrajectoryOccupancy
                - Calculation of the TTC / TTB by means of the Trajectory Occupancy Map: @ref CD_v_TrajOccCalcCriticalities
@{
*/



/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static boolean  CD_b_TrajOccCheckObjectRelevance(ObjNumber_t const iObjectIndex);
static void     CD_v_TrajOccCalcObjectLines(ObjNumber_t     const        iObjectIndex,   SFLTrajOccupancy_t       *const pTrajOccupancy,float32                      afTimeList[]);
static void     CD_v_TrajOccCalcObjectLinesCore(ObjNumber_t const iObjectIndex, float32 const fTStart, float32 const fTEnd, SFLPolyDeg2_t const * const pKinStart, SFLVector2D_t const * const pVectorPredict, SFLTrajOccupancy_t * const pTrajOccupancy, float32 afTimeList[]);
static void     CD_v_TrajOccCalcShapePointIntersectionPoints(SFLVector2D_t const         aLimitedShapePoints[],
                                                             SFLVector2D_t const * const pShiftDirection,
                                                             float32       const         fShiftDistance,
                                                             SFLCircle_t   const * const pMaxEgoCircle, 
                                                             SFLCircle_t   const * const pMinEgoCircle,
                                                             SFLVector2D_t               aPositions [],
                                                             sint8               * const piNofSolutions);
static void     CD_v_TrajOccSortObjectLines(float32 const afTimeList[],SFLTrajOccupancy_t * const pTrajOccupancy);

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief  The number of local simulation cycles of brake level 1.
            @typical 8u, @unit [-]*/
#define CD_TRAJOCC_BRK_L1_CYCLS     8u

/*! @brief  The assumed acceleration for brake level 1.
            @typical -4.0f, -6.0f or ,-9.0f @unit [m/s^2]*/
#define CD_TRAJOCC_BRK_L1_ACCEL         CD_EMERGENCY_BRAKE_ACCEL

/*! @brief  The assumed acceleration for brake level 1.
            @typical -4.0f, -6.0f or ,-9.0f @unit [m/s^2]*/
#define CD_TRAJOCC_BRK_L2_ACCEL         CD_EMERGENCY_BRAKE_ACCEL
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CD_v_TrajOccCalcCriticalities                                                                */ /*!

  @brief                Calculates the TTC and TTB on base of the trajectory occupancy.

  @description          Sets up a table of possible decelerations and uses this table to calculate the TTB and \n
                        TTC on base of the trajectory occupancy by calling the function @ref SFL_v_TrajOccCalcTTX.

  @return               void

  @param[in]            pTrajOccupancy : Trajectory occupancy interface.
  @param[in,out]        pfTTC : Time to collision. Calculated on  base of the trajOccupancy. @range [0,40], @phys_unit [s]
  @param[in,out]        pfTTB : Time to brake. Calculated on  base of the trajOccupancy. @range [0,40], @phys_unit [s]

  @glob_in              @ref ACDC_p_GetWorkingData    \n
                        @ref ACDC_p_GetEgoKinematics \n
                        @ref ACDC_p_GetEgoGeometry
  @glob_out             None

  @c_switch_part        @ref ACDC_SIMU\n
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods
  
  @todo                 According to the new architecture, this function is to be moved to MEDIC. 
                        Currently, the afDecelerations is filled with CD_EMERGENCY_BRAKE_ACCEL as the TTB_Acute.
                        In MEDIC, this array has to be filled with the intended braking cascade.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void CD_v_TrajOccCalcCriticalities(SFLTrajOccupancy_t const *const pTrajOccupancy, 
                                   float32                  *const pfTTC, 
                                   float32                  *const pfTTB)
{
#ifdef ACDC_SIMU
  ACDCTrajOccupancySimu_t *const pTrajOccSimu = &(ACDC_p_GetWorkingData()->pSimuData->sGlobData.CD.TrajOccupancySimuData);
#endif
  float32                 afDecelerations[SFL_TRAJOCC_MAX_NOF_TIME_STEPS] = {0};
  SFLPolyDeg2_t           EgoKinematics;
  uint8                   uTimeStep;
  EgoKinematics.fC0 = 0.f;
  EgoKinematics.fC1 = ACDC_p_GetEgoKinematics()->fVel;
  EgoKinematics.fC2 = 0.5f * ACDC_p_GetEgoKinematics()->fAccel;


  /* Fill the Deceleration table with the allowed deceleration at a certain timestamp */
  for(uTimeStep = 0u; uTimeStep < (uint8)(SFL_TRAJOCC_MAX_NOF_TIME_STEPS); ++uTimeStep)
  {
    float32 const fDecel = (uTimeStep < CD_TRAJOCC_BRK_L1_CYCLS)?(CD_TRAJOCC_BRK_L1_ACCEL):(CD_TRAJOCC_BRK_L2_ACCEL);
    afDecelerations[uTimeStep] = fDecel;
#ifdef ACDC_SIMU
    pTrajOccSimu->afDecelerations[uTimeStep] = fDecel;
#endif
  }

  /* Calculate TTC and TTB on base of the trajectory occupancy and the given Deceleration Table */
  SFL_v_TrajOccCalcTTX(pTrajOccupancy, afDecelerations, ACDC_p_GetEgoGeometry()->fLength, &EgoKinematics, pfTTC, pfTTB);
  
}


/*************************************************************************************************************************
  Functionname:         CD_v_CalculateTrajectoryOccupancy                                                            */ /*!

  @brief                Calculates the Trajectory occupancy

  @description          Calculates the distances on the ego trajectory which are occupied by all selected objects 
                        over the time. This information is stored as lines. Each line is given by its minimum and maximum.\n
                        value, indicating the occupied DistOnTraj at a certain time. The access to these lines can be done 
                        by the TimeAccessTable. 
                        @startuml CD_v_CalculateTrajectoryOccupancy_activity.png
                        start
                          :Reset the TrajOccupancy structure;
                          partition "Execute for each object"{
                            #Orange:Check if the object is relevant for the 
                            trajectory occupancy calculation:
                            <b>CD_b_TrajOccCheckObjectRelevance</b> >
                            note left
                              As the following calculation is very runtime 
                              consuming for moving objects and the number 
                              of lines is limited, this filter should be very strict.
                            end note
                            if(Object is relevant?) then (Yes)
                              :1}
                              #Orange:Calculate the lines of the current object 
                              in the TrajOccupancy Map:
                              <b>CD_v_TrajOccCalculateObjectLines</b> >
                            else(No)
                              :2}
                            endif
                          }
                          #Orange:Sort all lines according to their time stamp 
                          and generate the TimeAccess Table:
                          <b>CD_v_TrajOccSortObjectLines</b> >

                        stop
                        @enduml

  @return               void

  @param[in,out]        pTrajOccupancy : Trajectory Occupancy in form of lines.

  @glob_in              None
  @glob_out             @ref ACDC_p_GetWorkingData

  @c_switch_part        @ref ACDC_SIMU\n
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void CD_v_CalculateTrajectoryOccupancy(SFLTrajOccupancy_t *const pTrajOccupancy)
{
  ObjNumber_t        iObjectIndex;
  float32            afTimeList[SFL_TRAJOCC_MAX_NOF_LINES] = {0};
 
  pTrajOccupancy->uNofLines = 0u;
#ifdef ACDC_SIMU
  /* Count the number of calculations (only for debug purpose)*/
  (ACDC_p_GetWorkingData()->pSimuData->sGlobData.CD.TrajOccupancySimuData.uNofCalculations) = 0u;
#endif

  /* Loop over all objects to calculate the ego trajectory occupancy. Stop if all objects are processed or maximum number of lines is reached */
  for (iObjectIndex = 0;(iObjectIndex < EM_N_OBJECTS) && (pTrajOccupancy->uNofLines <= SFL_TRAJOCC_MAX_NOF_LINES);++iObjectIndex)
  {
    /* Object filter */
    boolean const bObjIsRelevant = CD_b_TrajOccCheckObjectRelevance(iObjectIndex);
    if(bObjIsRelevant == TRUE)
    {
      /* Calculate the lines for each object */
      CD_v_TrajOccCalcObjectLines(iObjectIndex, pTrajOccupancy, afTimeList);

    }
  }
  
  /* Sort the resulting list of lines according to their timestamp (stored in the fTimeList) */
  CD_v_TrajOccSortObjectLines(afTimeList, pTrajOccupancy);
  
}

/*************************************************************************************************************************
  Functionname:         CD_v_TrajOccSortObjectLines                                                                  */ /*!

  @brief                Sort the previously calculated object lines.

  @description          Sort the previously calculated object lines according to their timestamp and create the TimeAccess Table.
                        This table stores the indices of the lines according to their timestamps.
                        E.g. [0 3 4 4] means: 
                        - The Traj Occupancy consists of 3 time steps
                        - The Lines with the indices 0, 1 and 2 belong to the time step 0
                        - The Line with the index 3 belongs to the time step 1
                        - No Lines belong to the time step 3 and 4
                        .
                        @startuml CD_v_TrajOccSortObjectLines_activity.png
                        start
                          #Orange:Get a list of indices of the lines sorted by their timestamps:
                          <b>SFL_v_GetSortedArrayIndices</b> >
                          :Sort the Min/Max Distances according 
                          to the sorted array list;
                          partition "Execute for all time steps" {
                            if(TimeStamp is found which is bigger\nthan the current time step?) then (Yes)
                            note left
                              **Attention:**
                              Time Step  = Step between 0 and SFL_TRAJOCC_MAX_TIME
                              Time Stamp = Time allocated to a line
                            end note
                              :1}
                              :Store the current index and
                              continue with next time step;
                            else(No)
                              :2}
                              :Continue with next TimeStamp;
                            endif
                          }

                        stop
                        @enduml

  @return               void

  @param[in]            afTimeList :     List of Time stamps of the Min/Max Distances provided by the TrajOccupancy. @range [0,@ref SFL_TRAJOCC_MAX_TIME]
  @param[in,out]        pTrajOccupancy : Trajectory Occupancy with filled Min/Max distances.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  Min / Max values of the TrajOccupancy are filled.
  @post                 Time Access table in the TrajOccupancy is filled.

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods
  
  @todo                 Find a method of sorting the TrajOccupancy that does not require the help structure SFLTrajOccupancy_t TrajOccUnsorted.
                        It requires almost 2k of storage on the stack!
                        Possible Idea: Do not sort the Min and Max Distances by time, only create a sorted index array. The access to the Lines 
                        would then have to be done via two index arrays

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void CD_v_TrajOccSortObjectLines(float32            const         afTimeList[],
                                        SFLTrajOccupancy_t       * const pTrajOccupancy)
{
  /*PRQA S 1031 1*//* 2018-09-24, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  SFLTrajOccupancy_t TrajOccUnsorted = *pTrajOccupancy;
  uint8              auSortedTimeIndices[SFL_TRAJOCC_MAX_NOF_LINES] = {0};
  uint8              uCurrListIdx;
  uint8              uTimeIndex;

  /* Get the indices of the TimeList sorted by value (from Min to Max)*/
  SFL_v_GetSortedArrayIndices(afTimeList, pTrajOccupancy->uNofLines, auSortedTimeIndices);

  /* Sort the List of Lines according to their timestamp */
  for(uCurrListIdx = 0; uCurrListIdx < pTrajOccupancy->uNofLines; ++uCurrListIdx)
  {
    /* Sort the TrajOccupancy Lines according to their time stamps */
    pTrajOccupancy->fMinDistances[uCurrListIdx] = TrajOccUnsorted.fMinDistances[auSortedTimeIndices[uCurrListIdx]];
    pTrajOccupancy->fMaxDistances[uCurrListIdx] = TrajOccUnsorted.fMaxDistances[auSortedTimeIndices[uCurrListIdx]];
  }

  uCurrListIdx = 0u;
  for(uTimeIndex = 0; uTimeIndex < SFL_TRAJOCC_MAX_NOF_TIME_STEPS;++uTimeIndex)
  {
    /* Create a Time Access table : Array with one index for each timestamp. It contains the index of the first Line at the corresponding time stamp 
        This list allows an easy access to the Lines without the need of searching for timestamps afterwards */
    
    while(    (uCurrListIdx                                 < pTrajOccupancy->uNofLines                           )
           && (afTimeList[auSortedTimeIndices[uCurrListIdx]] < ((float32)uTimeIndex * (SFL_TRAJOCC_STEP_SIZE_TIME))))
    {
      ++uCurrListIdx;
    }
    pTrajOccupancy->uTimeAccessTable[uTimeIndex] = uCurrListIdx;
  }

}



/*************************************************************************************************************************
  Functionname:         CD_b_TrajOccCheckObjectRelevance                                                             */ /*!

  @brief                Checks if an object is relevant for the trajectory occupancy calculation.

  @description          If one of the following criteria is fulfilled, the object is not considered for the 
                        trajectory occupancy calculation:
                        - The object is deleted
                        - The object is of class FPS_EBA_CLASS_MAX_VALUE, FPS_EBA_CLASS_UNKNOWN or FPS_EBA_CLASS_NONE
                        - The object is outside of the ego trajectory and moving from it
                        - The object is stationary and not inside of the ego trajectory
                        - The object is further away than a threshold

  @return               boolean: Flag indicating if the object is relevant for the Trajectory occupancy. (TRUE = Relevant)

  @param[in]            iObjectIndex : Index of the considered object. @range [0,@ref EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetEMGenObjQualifiers \n
                        @ref ACDC_p_GetACDCEgoData \n
                        @ref ACDC_p_GetObjTrajRelation \n
                        @ref ACDC_b_GetEMGenObjIsDeleted
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @todo                 Try to find more criteria to exclude objects. (Especially Moving objects require lots of calculations)

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static boolean CD_b_TrajOccCheckObjectRelevance(ObjNumber_t const iObjectIndex)
{
  boolean                                bObjIsRelevant = TRUE;
  EM_t_GenEbaObjClass      const         EbaObjClass    = ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->eEbaObjClass;
  ACDCEgoData_t            const * const pEgoData       = ACDC_p_GetEgoData();
  ACDCObjToTrajRelation_t  const * const pTrajRelation  = ACDC_p_GetObjTrajRelation(iObjectIndex);

  /* Apply a filter to assure that only qualified objects get to be in the Traj Occupancy*/
  if (    (    (ACDC_b_GetEMGenObjIsDeleted(iObjectIndex)) ==  TRUE                            )
       || (    (EbaObjClass                                ==  FPS_EBA_CLASS_MAX_VALUE       )
            || (EbaObjClass                                ==  FPS_EBA_CLASS_UNKNOWN         ) 
            || (EbaObjClass                                ==  FPS_EBA_CLASS_NONE            ) )
       /* Be careful with the use of the Traj relation structure here! It is calculated based 
          on a timeBased Trajectory and therefore not 100% compatible with the here used Circle Attempt.
          To assure consistency a x based attempt should be used for both (either circle or 2nd deg polynomial)*/
       || (    (pTrajRelation->fVelocityToTraj       >  1.f                                  )
            && (pTrajRelation->fDistToTrajMin        >  (0.5f * pEgoData->Geometry.fWidth)   ) )
       || (    (pTrajRelation->fVelocityToTraj      <   -1.f                                 )
            && (pTrajRelation->fDistToTrajMax       <   (-0.5f * pEgoData->Geometry.fWidth)  ) )
       || (    (fABS(pTrajRelation->fVelocityToTraj)<=  1.f                                  )
            && (    (pTrajRelation->fDistToTrajMin   >  (0.5f * pEgoData->Geometry.fWidth) ) 
                 || (pTrajRelation->fDistToTrajMax  <   (-0.5f * pEgoData->Geometry.fWidth)) ) )
       || (     pTrajRelation->fDistOnTraj           >  120.f)
                 /*Add here more conditions*/                                                   )
  {
    bObjIsRelevant = FALSE;
  }
  return bObjIsRelevant;
}

/*************************************************************************************************************************
  Functionname:         CD_v_TrajOccCalculateObjectLines                                                             */ /*!

  @brief                Calculates all TrajOccupancy lines of an object by calling the function @ref CD_v_TrajOccCalculateObjectLinesCore.

  @description          Predicts the objects kinematics up to a start time. Afterwards calls the function 
                        @ref CD_v_TrajOccCalculateObjectLinesCore. This prediction can reduces the runtime significantly as \n
                        only the relevant cycles are calculated iteratively.

  @return               void

  @param[in]            iObjectIndex :    Index of the considered object. @range [0,@ref EM_N_OBJECTS[
  @param[in,out]        pTrajOccupancy :  Trajectory occupancy. Will be filled with the lines of the object.
  @param[in,out]        afTimeList :      List of timestamps. @phys_unit [s], @range [0,@ref SFL_TRAJOCC_MAX_TIME]

  @glob_in              @ref ACDC_p_GetObjMovement \n
                        @ref ACDC_p_GetObjGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Velocity**:\n
                        \f$V = V_x \cdot \cos(Orient_{Obj})+ V_y \cdot sin(Orient_{Obj})\f$
                        - **Acceleration:**\n
                        \f$A = 0.5 \cdot (A_x \cdot \cos(Orient_{Obj})+ A_y \cdot sin(Orient_{Obj}))\f$

  @testmethod           @Generic_Testmethods

  @todo                 Currently no prediction is done. Check if a prediction can reduce the runtime.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void CD_v_TrajOccCalcObjectLines(ObjNumber_t        const        iObjectIndex, 
                                             SFLTrajOccupancy_t       *const pTrajOccupancy, 
                                             float32                         afTimeList[])
{
  /*PRQA S 1031 3*//* 2018-09-24, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  SFLMovement_t                ObjMovementAbs   = ACDC_p_GetObjMovement(iObjectIndex)->Abs;
  ACDCGeometry_t const * const pObjGeometry     = ACDC_p_GetObjGeometry(iObjectIndex);
  SFLVector2D_t const          PredictionVector = SFL_s_CalculateNormalizedVector(SFL_s_SetupVector2(1.f,SFL_f_CalcGradientFromAngle(pObjGeometry->fOrientation)));
  
  /* Set start and end time and start kinematic. Currently the start values are 0. The idea is to jump directly to the timestamp at which the object enters the 
     ego corridor to reduce the number of iteration steps during the line calculation*/
  SFLPolyDeg2_t                StartKinematic   = {0};
  float32                      fTStart          = 0.f;
  float32                      fTEnd            = SFL_TRAJOCC_MAX_TIME;

  ObjMovementAbs.Accel.fY = 0.f;

  /* Calculate the current object velocity and acceleration */
  StartKinematic.fC1 =         (ObjMovementAbs.Vel.fX    * COS_(pObjGeometry->fOrientation)) + (ObjMovementAbs.Vel.fY   * SIN_(pObjGeometry->fOrientation));
  StartKinematic.fC2 = 0.5f * ((ObjMovementAbs.Accel.fX  * COS_(pObjGeometry->fOrientation)) + (ObjMovementAbs.Accel.fY * SIN_(pObjGeometry->fOrientation)));

  
  CD_v_TrajOccCalcObjectLinesCore(iObjectIndex, fTStart, fTEnd, &StartKinematic, &PredictionVector, pTrajOccupancy, afTimeList);
}



/*************************************************************************************************************************
  Functionname:         CD_v_TrajOccCalcShapePointIntersectionPoints                                                 */ /*!

  @brief                Calculates the intersections between all edges of an object and the ego corridor.

  @description          Loops through all shape points and intersects the edges with the edges of the ego corridor.
                        @startuml CD_v_TrajOccCalcShapePointIntersectionPoints_activity.png
                          start
                          partition "Execute for each shape point" {
                          #Orange:Check if the ShapePoint is inside 
                          of the Ego Corridor:
                          <b>SFL_b_CheckPosInCircle</b> >
                          if(ShapePoint is inside of the EgoCorridor?) then (Yes)
                            :1}
                            :Return the ShapePoint as intersection position;
                          else(No)
                            :2}
                            :Calculate a vector orthogonal to the ShapePointVector;
                            #Orange:Calculate the intersections between:
                            - The current ego circle and the ShapePointVector
                            - The current ego circle and the OrthogonalShapePointVector
                            <b>SFL_v_CircleIntersectWithVector</b> >
                          endif
                          }
                          partition "Execute for each intersection point" {
                            if(Intersection point is inside of the object?) then (Yes)
                              :3}
                              :Append the intersection 
                              point to the output list;
                            else(No)
                            :4}
                            endif
                          }
                          stop
                        @enduml
  @return               void

  @param[in]            aLimitedShapePoints : Array of limited shape points of the object
  @param[in]            pShiftDirection :     Predicted shift direction for object position at prediction time
  @param[in]            fShiftDistance :      Predicted shift distance for object position at prediction time
  @param[in]            pMaxEgoCircle :       Circle describing the outer edge of the ego corridor.
  @param[in]            pMinEgoCircle :       Circle describing the inner edge of the ego corridor.
  @param[in,out]        aPositions :          Array of found intersection positions. Minimum Length : 4
  @param[in,out]        piNofSolutions :      Number of found intersection positions. @range [0,4]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @todo                 This function costs too much runtime! It is executed up to 200 times and more. Try to simplify this calculation!

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void CD_v_TrajOccCalcShapePointIntersectionPoints(SFLVector2D_t const         aLimitedShapePoints[],
                                                         SFLVector2D_t const * const pShiftDirection,
                                                         float32       const         fShiftDistance,
                                                         SFLCircle_t   const * const pMaxEgoCircle, 
                                                         SFLCircle_t   const * const pMinEgoCircle,
                                                         SFLVector2D_t               aPositions [],
                                                         sint8               * const piNofSolutions)
{
  SFLPositionVector2D_t ShapePointVector;
  SFLPositionVector2D_t OrthShapePointVector;
  SFLVector2D_t         afTempPositions[8u * EM_GEN_OBJ_N_SHAPE_POINTS] = {0};
  float32               fXMax = -ACDC_DIST_DEFAULT;
  float32               fXMin =  ACDC_DIST_DEFAULT;
  float32               fYMax = -ACDC_DIST_DEFAULT;
  float32               fYMin =  ACDC_DIST_DEFAULT;
  uint32                uSPIdx;
  /* The total number of found solutions.
  This variable has to be initialized here to be incremented afterwards for each found solution*/
  sint32                iNofTempSolutions = 0;

  ShapePointVector.Line = SFL_s_CalculateNormalizedVector(*pShiftDirection);
  OrthShapePointVector.Line.fX =  ShapePointVector.Line.fY;
  OrthShapePointVector.Line.fY = -ShapePointVector.Line.fX;

  for(uSPIdx = 0; uSPIdx< EM_GEN_OBJ_N_SHAPE_POINTS; ++uSPIdx)
  {
    ShapePointVector.Foot = SFL_s_AddVector2(aLimitedShapePoints[uSPIdx],SFL_s_MultiplyScalarVector(fShiftDistance,ShapePointVector.Line));
    OrthShapePointVector.Foot = ShapePointVector.Foot;
    fXMax = MAX(ShapePointVector.Foot.fX, fXMax);
    fXMin = MIN(ShapePointVector.Foot.fX, fXMin);
    fYMax = MAX(ShapePointVector.Foot.fY, fYMax);
    fYMin = MIN(ShapePointVector.Foot.fY, fYMin);

    if(    (TRUE  == SFL_b_CheckPosInCircle(pMaxEgoCircle,&ShapePointVector.Foot) )
        && (FALSE == SFL_b_CheckPosInCircle(pMinEgoCircle,&ShapePointVector.Foot) ) )
    {
      /* The current shape point is inside of the ego corridor */
      afTempPositions[iNofTempSolutions] = ShapePointVector.Foot;
      iNofTempSolutions++;
    }
    else
    {
      SFLCircle_t const * pCurrCircle;
      if(TRUE == SFL_b_CheckPosInCircle(pMinEgoCircle,&ShapePointVector.Foot))
      {
        pCurrCircle = pMinEgoCircle;
      }
      else
      {
        pCurrCircle = pMaxEgoCircle;
      }
      SFL_v_CircleIntersectWithVector(pCurrCircle, &OrthShapePointVector , afTempPositions, &iNofTempSolutions);

      SFL_v_CircleIntersectWithVector(pCurrCircle, &ShapePointVector     , afTempPositions, &iNofTempSolutions);

    }

  }

  /* Discard all positions which are not part of the object */
  *piNofSolutions = 0;
  for(;iNofTempSolutions >= 0;--iNofTempSolutions)
  {
    if(    (afTempPositions[iNofTempSolutions].fX <  (fXMax + C_F32_DELTA) )
        && (afTempPositions[iNofTempSolutions].fX  > (fXMin - C_F32_DELTA) )
        && (afTempPositions[iNofTempSolutions].fY <  (fYMax + C_F32_DELTA) )
        && (afTempPositions[iNofTempSolutions].fY  > (fYMin - C_F32_DELTA) ) )
    {
      aPositions[*piNofSolutions] = afTempPositions[iNofTempSolutions];
      (*piNofSolutions) ++;
      ACDC_ASSERT((*piNofSolutions) >= 0 && (*piNofSolutions) <= 6);
    }
  }

}

/*************************************************************************************************************************
  Functionname:         CD_v_TrajOccCalculateObjectLinesCore                                                         */ /*!

  @brief                Calculates the DistOnTraj a given object occupies between fTStart and fTEnd

  @description          
                        @startuml CD_v_TrajOccCalculateObjectLinesCore_activity.png
                        start
                        #Orange:Get the shape point indices with the 
                        minimum and maximum x and y:
                        <b>SFL_v_GetIndicesExtremePositions</b> >
                        partition "Execute while t < t_end\nAND Max Number of lines is not reached" {
                          if(Object Velocity is > 0) then (Yes)
                            #Orange:Predict the object movement with its 
                            current kinematics:
                            <b>SFL_f_EvalPolyDeg2</b> >
                            #Orange:Predict the shape points with the predicted 
                            kinematics and calculate the **intersection 
                            points** with the ego corridor:
                            <b>CD_v_TrajOccCalcShapePointIntersectionPoints</b> >
                            :Select the minimum and maximum position in X as **PosMin** and **PosMax**;
                            #Orange:Calculate the **DistOnTrajMin** and **DistOnTrajMax** 
                            on base of the **PosMin** and **PosMax**:
                            <b>SFL_f_CircleCalcArcLengthAtPos</b> >
                          else(No)
                            :3}
                            :Set velocity and acceleration to 0,
                            Keep the **DistOnTrajMin** and **-Max** 
                            from the previous iteration;
                          endif
                          if(A valid **DistOnTrajMin/Max** was found?) then (Yes)
                            :4}
                            :Append a new line to the list;
                          else (No)
                            :5}
                          endif
                        }
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :   Index of the considered object. @range [0,@ref EM_N_OBJECTS[
  @param[in]            fTStart :        Time at which the iterative calculation of the Min/Max Distances starts. @phys_unit[s]
  @param[in]            fTEnd :          Time at which the iterative calculation of the Min/Max Distances ends. @phys_unit[s]
  @param[in]            pKinStart :      Initial kinematics of the object.
  @param[in]            pVectorPredict : Vector indicating the direction into which the object shall be predicted.
  @param[in,out]        pTrajOccupancy : TrajOccupancy which shall be filled with lines (represented by Min and Max values)
  @param[in,out]        afTimeList :     Array of time stamps allocated to each line.

  @glob_in              @ref ACDC_a_GetObjLimitedShapePoints \n
                        @ref ACDC_p_GetACDCEgoData \n
                        @ref AIP_i_GetShapePointIdx
  @glob_out             None

  @c_switch_part        @ref ACDC_SIMU\n
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @todo                 pEgoData->TrajCircle.fY is zero if ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve is too small.
                        Therfore, the circle-based calculation shall be avoided when the ego vehicle drives straight.

  @testmethod           @Generic_Testmethods

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void CD_v_TrajOccCalcObjectLinesCore(ObjNumber_t        const         iObjectIndex, 
                                            float32            const         fTStart,
                                            float32            const         fTEnd,
                                            SFLPolyDeg2_t      const * const pKinStart,
                                            SFLVector2D_t      const * const pVectorPredict,
                                            SFLTrajOccupancy_t       * const pTrajOccupancy,
                                            float32                          afTimeList[])
{
  /*PRQA S 1031 5*//* 2018-09-24, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  SFLVector2D_t const * const aLimitedShapePoints = ACDC_a_GetObjLimitedShapePoints(iObjectIndex);
  SFLCircle_t   const * const pEgoCircle          = &(ACDC_p_GetEgoData()->TrajCircle);
  SFLPolyDeg2_t               KinPredicted        = *pKinStart;
  SFLCircle_t                 MinEgoCircle        = *pEgoCircle;
  SFLCircle_t                 MaxEgoCircle        = *pEgoCircle;
  float32                     fDistOnTrajMin      =  ACDC_DIST_DEFAULT;
  float32                     fDistOnTrajMax      = -ACDC_DIST_DEFAULT;
  uint32                      uTimeStep;

  /* Calculate one circle for the left and one for the right edge of the ego trajectory */
  MinEgoCircle.fRadius -= 0.5f * ACDC_p_GetEgoData()->Geometry.fWidth;
  MaxEgoCircle.fRadius += 0.5f * ACDC_p_GetEgoData()->Geometry.fWidth;


  for (uTimeStep = CML_u_Round2Uint(fTStart/SFL_TRAJOCC_STEP_SIZE_TIME); (uTimeStep < CML_u_Round2Uint(fTEnd/SFL_TRAJOCC_STEP_SIZE_TIME)) && (pTrajOccupancy->uNofLines < SFL_TRAJOCC_MAX_NOF_LINES); ++uTimeStep)
  {
    /* This is the heart of the trajectory occupancy: The movement of all objects is simulated. Here special behavior can be modeled, e.g. stopping at zero, 
       Faster movement of the front shape points,... 
       Also this Loop is the main reason for the high runtime consumption of the functionality.*/
    SFLVector2D_t aPositions[2u * EM_GEN_OBJ_N_SHAPE_POINTS]  = {0};
    sint8         iNofSolutions   = 0;
    float32 const fVelNew         = KinPredicted.fC1 + (2.f * KinPredicted.fC2 * SFL_TRAJOCC_STEP_SIZE_TIME);


    if(    (fVelNew    > 0.f                                                 )
        || (uTimeStep == CML_u_Round2Uint(fTStart/SFL_TRAJOCC_STEP_SIZE_TIME))) /* Do the calculation always in the first cycle! */
    {
      SFLVector2D_t PosMin;
      SFLVector2D_t PosMax;

      /* Set Default values */
      PosMin.fX =  ACDC_DIST_DEFAULT;
      PosMax.fX = -ACDC_DIST_DEFAULT;

#ifdef ACDC_SIMU
      /* Count the number of calculations (only for debug purpose)*/
      (ACDC_p_GetWorkingData()->pSimuData->sGlobData.CD.TrajOccupancySimuData.uNofCalculations)++;
#endif

      /* Predict the distance the Object will have covered until fT*/
      KinPredicted.fC0 = SFL_f_EvalPolyDeg2(&KinPredicted,SFL_TRAJOCC_STEP_SIZE_TIME);
      KinPredicted.fC1 = fVelNew;

      CD_v_TrajOccCalcShapePointIntersectionPoints(aLimitedShapePoints,pVectorPredict, KinPredicted.fC0, &MaxEgoCircle, &MinEgoCircle, aPositions, &iNofSolutions);

      /* Validate the found solutions and select the minimum and maximum value out of the valid ones */
      for(iNofSolutions = iNofSolutions-1; iNofSolutions >= 0; --iNofSolutions)
      {
        /* Actually the Min and max DistOnTraj are searched. 
        This way of selecting is correct as long as no turns >90° are allowed*/
        if(PosMin.fX > aPositions[iNofSolutions].fX)
        {
          PosMin = aPositions[iNofSolutions];
        }
        if(PosMax.fX < aPositions[iNofSolutions].fX)
        {
          PosMax = aPositions[iNofSolutions];
        }

      }
      /* If a valid intersection position has been found, calculate the DistOnTrajMin/Max */
      fDistOnTrajMin = (PosMin.fX <   ACDC_DIST_DEFAULT) ? SFL_f_CircleCalcArcLengthAtPos(pEgoCircle, &PosMin): ACDC_DIST_DEFAULT;
      fDistOnTrajMax = (PosMax.fX  > -ACDC_DIST_DEFAULT) ? SFL_f_CircleCalcArcLengthAtPos(pEgoCircle, &PosMax):-ACDC_DIST_DEFAULT;
    }
    else
    {
      /* The objects velocity changes its direction => simulate a stopped object */
      /* In this case also the fDistOnTrajMin and fDistOnTrajMax will not change anymore => keep the values from the iteration step */
      KinPredicted.fC1 = 0.f;
      KinPredicted.fC2 = 0.f;
    }

    if(fDistOnTrajMin < ACDC_DIST_DEFAULT)
    {
      /* If an intersection has been found, append the line to the list of lines */
      pTrajOccupancy->fMinDistances[pTrajOccupancy->uNofLines] = fDistOnTrajMin;
      pTrajOccupancy->fMaxDistances[pTrajOccupancy->uNofLines] = fDistOnTrajMax;
      afTimeList[pTrajOccupancy->uNofLines] = (float32)uTimeStep *SFL_TRAJOCC_STEP_SIZE_TIME;
      pTrajOccupancy->uNofLines++;
    }
  }

}


/**@}*/
#endif /* ACDC_CFG_CD && ACDC_CFG_CALC_TRAJ_OCCUPANCY */
