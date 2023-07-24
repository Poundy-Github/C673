/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculateobjhistory.c

DESCRIPTION:               The calculation of object history for CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 09:21:55CEST $

VERSION:                   $Revision: 1.25 $
*****************************************************************************/
#pragma PRQA_NO_SIDE_EFFECTS EMP_b_CalcTrajectoryRefPoint //function can be marked as being free from side effects(Needed for Helix QAC warning fix).

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD)

#if (CD_USE_GEN_PSC)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_calculateobjhistory Calculate Obj History
@ingroup cd

@brief          The objects' historical data are calculated and saved in this module \n\n

@description   The history functions provide functionalities regarding the storing of object and ego positions 
               from the past cycles and the access to this information:
                 - *History Update*:\n
                   The function \ref CDUpdateHistory is called every cycle and stores the positions of all existing 
                   objects in history floats.
                 - *Information Access*: \n
                   The history information can be accessed in three ways. Either the entire history of an object, 
                   or only one specific history value are returned. As a third way, the DistanceToTrajectory can \n
                   be calculated directly for all history positions.
@{
*/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
 static void CDPushHistoryFloat            ( float32                          fLatestValue, 
                                             CDHistoryFloat_t         *       pIn_FloatHistory );

 static void CDResetObjHistoryFloat        ( CDKinHistObj_t           *       pIn_ObjHistory );

 static void CDTransform2DCoordHistoryFloat( GDBTrafoMatrix2D_t const *       M, 
                                             CDHistoryFloat_t         *       FloatHistory_X, 
                                             CDHistoryFloat_t         *       FloatHistory_Y );

 static void CDResetHistoryFloat           ( CDHistoryFloat_t         *       pIn_FloatHistory );

 static void CDUpdateObjHist( ObjNumber_t iObjectIndex);

 static boolean CDGetNthHistoryFloat       ( uint8                            uiSteps            ,
                                             CDHistoryFloat_t   const * const pIn_FloatHistory   ,
                                             float32*                         pOut_Result         );
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDGetCompleteHistory                                                                         */ /*!

  @brief                Returns all values of a history float by writing them into an array.

  @description          Loops through a history float (see @ref CDHistoryFloat_t) and writes all of its values into the 
                        float array afHistory.
                        @startuml CDGetCompleteHistory_activity.png
                        start
                          :Reset output array;
                          if(Is Valid value?) then(Yes)
                            :1}
                            :Write float history value to array;
                            :Count valid values;
                          else(Yes)
                            :2}
                            :Write zero to array;
                          endif
                          :Return valid value count;
                        stop
                        @enduml

  @return               uint8:              Number of valid output values @range[0,...]

  @param[in]            pIn_FloatHistory :  History float whose value shall be returned
  @param[out]           afHistory :         Array used to store and return the resulting values
  @param[in]            uiArrayLength :     Length of the array used for the output @range[0,...]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_GEN_PSC \n
                        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               

  @testmethod           @ref TEST_CDGETCOMPLETEHISTORY_001

  @traceability         Design Decision
*************************************************************************************************************************/
uint8 CDGetCompleteHistory( CDHistoryFloat_t const * const pIn_FloatHistory , float32 afHistory[], uint8 uiArrayLength)
{
  uint8 i;
  /* Fill Array */
  for ( i=0u; i<uiArrayLength; ++i )
  {
    /* Valid Values to be filled in. Reset to 0 else*/
    if (i < pIn_FloatHistory->uiValidValueCount)
    {
    /* Calculate Target ID in the History. Note that the order is to be reversed and we have an offset.*/
      const uint8 uiTargetID = ((pIn_FloatHistory->uiLastID + CD_PSC_PROB_OBSERVE_Y_DIST_N) - i) % CD_PSC_PROB_OBSERVE_Y_DIST_N;
      afHistory[i] = pIn_FloatHistory->afValues[uiTargetID];
    }
    else
    {
      afHistory[i] = 0.0f;
    }
  }
  /* Return count of valid values */
  return pIn_FloatHistory->uiValidValueCount;
}

/*************************************************************************************************************************
  Functionname:         CDGetNthHistoryFloat                                                                         */ /*!

  @brief                Returns the value that is at the position uiSteps in the given history float. 
  
  @description          Returns the value that is at the position uiSteps in the given history float. If uiSteps is 
                        higher than the maximum number of contained history values, the last history float is returned.
                        If uiSteps is below zero, it is treated as a wrap around.
                        @startuml CDGetNthHistoryFloat_activity.png
                        start
                          if(uiSteps exceeds maximum number of values?) then (Yes)
                            :1}
                            :Set uiSteps to maximum number of steps;
                          else(No)
                            :2}
                          endif
                          :Select and return value 
                          from history float;
                        stop
                        @enduml

  @return               boolean: Indicates whether uiSteps exceeds the maximum number of steps (FALSE) or not (TRUE)

  @param[in]            uiSteps :           Index of the required value in the history float. @range [0,+...[
  @param[in]            pIn_FloatHistory :  History float containing values of various previous cycles.
  @param[out]           pOut_Result :       Value of the requested float. @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @author               

  @testmethod           @ref TEST_CDGETNTHHISTORYFLOAT_001

  @traceability         Design Decision
*************************************************************************************************************************/
static boolean CDGetNthHistoryFloat( uint8 uiSteps, CDHistoryFloat_t const * const pIn_FloatHistory, float32* pOut_Result )
{

  uint8 uiTargetID;
  boolean bValidStep = b_TRUE;

  /* Assure Consistency */
  ACDC_ASSERT(pIn_FloatHistory->uiValidValueCount <= CD_PSC_PROB_OBSERVE_Y_DIST_N);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */

  /* Limit requested history ID to maximum if too big */
  if ( uiSteps > (pIn_FloatHistory->uiValidValueCount - 1u) )
  {
    uiSteps = pIn_FloatHistory->uiValidValueCount - 1u;
    bValidStep = b_FALSE;
  }

  /* % is implementation defined for negative numbers therefore add uiArrayLength*/
  uiTargetID = ((pIn_FloatHistory->uiLastID + CD_PSC_PROB_OBSERVE_Y_DIST_N) - uiSteps) % CD_PSC_PROB_OBSERVE_Y_DIST_N;

  *pOut_Result = pIn_FloatHistory->afValues[uiTargetID];
  return bValidStep;
}

/*************************************************************************************************************************
  Functionname:         CDCalcHistDistToTraj                                                                         */ /*!

  @brief                Calculates the distance to trajectory and distance on trajectory for given history positions.

  @description          Calculates the distance to trajectory and distance on trajectory (more details see 
                        @ref EMP_b_CalcTrajectoryRefPoint and @ref EMP_v_CalcDistToRefPoint) for given history positions.
                        @startuml CDCalcHistDistToTraj_activity.png
                        start
                        partition "Execute for each timestep" {
                          #Orange:Get the X and Y position of the 
                          object at the considered time:
                          <b>CDGetNthHistoryFloat</b> >
                          #Orange:Calculate the DistanceTo/OnTrajectory
                          for this position:
                          <b>EMP_b_CalcTrajectoryRefPoint</b>
                          <b>EMPCalcDistToRefPoint</b> >
                        }
                        stop
                        @enduml

  @return               void

  @param[in]            pIn_Obj :           Kinematic history of an object.
  @param[in]            uiMaxSteps :        Number of history steps that shall be considered. @range [0,...]
  @param[out]           afHistDistToTraj :  Array containing the resulting distances to trajectory. @phys_unit [m] @range ]-...,+...[
  @param[out]           afHistDistOnTraj :  Array containing the resulting distances on trajectory. @phys_unit [m] @range [0,+...[

  @glob_in              @ref AIP_p_GetACDCEgoTraj
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com

  @testmethod           @ref TEST_CDCALCHISTDISTTOTRAJ_001 \n
                        @ref TEST_CDCALCHISTDISTTOTRAJ_002

  @traceability         Design Decision
*************************************************************************************************************************/
void CDCalcHistDistToTraj(CDKinHistObj_t const * const pIn_Obj           ,
                          uint8                        uiMaxSteps        ,
                          float32                      afHistDistToTraj[],
                          float32                      afHistDistOnTraj[] )
{
  boolean       bResultOk = b_TRUE;
  uint8         uiCurrTimeStep;
  SFLVector2D_t RefPoint = {0.f,0.f};
  SFLVector2D_t VelAtRefPoint;
  SFLVector2D_t HistoryPos;
  ACDCTrajPred_t const * const pEgoTraj = AIP_p_GetACDCEgoTraj(ACDC_MANEUVER_KinematicsWithoutAcceleration);

  /* Higher Values lead to the behaviour (as within to short history) that the last valid value is repeated */
  ACDC_ASSERT(uiMaxSteps<=CD_PSC_PROB_OBSERVE_Y_DIST_N);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */

  for ( uiCurrTimeStep = 0u; uiCurrTimeStep < uiMaxSteps; ++uiCurrTimeStep )
  {
    (void)CDGetNthHistoryFloat( uiCurrTimeStep, &(pIn_Obj->sPosX), &(HistoryPos.fX));
    (void)CDGetNthHistoryFloat( uiCurrTimeStep, &(pIn_Obj->sPosY), &(HistoryPos.fY));
    bResultOk = (bResultOk) && (EMP_b_CalcTrajectoryRefPoint( &HistoryPos, pEgoTraj, &RefPoint, &VelAtRefPoint));
    if(bResultOk == b_TRUE)
    {
      EMP_v_CalcDistToRefPoint( &HistoryPos, &RefPoint, &(afHistDistToTraj[uiCurrTimeStep]), &(afHistDistOnTraj[uiCurrTimeStep]));
    }
    else
    {
      afHistDistToTraj[uiCurrTimeStep] = ACDC_DIST_DEFAULT;
      afHistDistOnTraj[uiCurrTimeStep] = ACDC_DIST_DEFAULT;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         CDHistIntegrate                                                                              */ /*!

  @brief                Integrates a function that is stored in an array for the X-Values and an array 
                        for the corresponding Y-Values.

  @description          
                        @startuml CDHistIntegrate_activity.png
                        start
                          :Assure that limits are correct, 
                          Correct them if they are not;
                          note left 
                          Criteria:
                          - LeftLimit < RightLimit
                          - LeftLimit between Min and Max Value
                          - RightLimit between Min and Max Value
                          end note
                          
                          partition "Execute for every array value pair" {
                          :Calculate Y for the 
                          integration limits;
                          note left: >see Formula\n"Y-Integration Limits"
                          :Integrate function between 
                          the current X-Value (X0) and the 
                          next X-Value;
                          note left 
                              See formulas for integration
                              in cases 1-5
                          end note
                          }
                          :Sum up results of all integration steps;
                        stop
                        @enduml

  @return               boolean

  @param[in]            afXValues :                 X-Values of the function that shall be integrated. @range ]-...,+...[
  @param[in]            afYValues :                 Y-Values of the function that shall be integrated. @range ]-...,+...[
  @param[in]            fLeftIntLimX :              Left integration limit. @range ]-...,+...[
  @param[in]            fRightIntLimX :             Right integration limit. @range ]-...,+...[
  @param[in]            uiLenXYVec :                Length of the value arrays. @range [0,+...[
  @param[in,out]        pOut_fHistIntegralResult :  Result of the integration. @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Y-Integration Limits:** \n
                        \f$ Y_{Lim,Left} = Y_0 + \frac{(X_{Lim,Left} - X_0)}{X_1-X_0} \cdot (Y_1 - Y_0) \f$ \n
                        \f$ Y_{Lim,Right} = Y_0 + \frac{(X_{Lim,Right} - X_0)}{X_1-X_0} \cdot (Y_1 - Y_0) \f$ \n
                        .
                        All calculations are according to the trapezoidal rule:
                        - **Case 1:** Current and next x value are within the integration limits:\n
                        \f$ IntStep = \frac{Y_0+Y_1}{2}\cdot(X_1-X_0) \f$ \n
                        \n
                        - **Case 2:** Current and next x value enclose the right integration limit: \n
                        \f$ IntStep = \frac{Y_0+Y_{Lim,Right}}{2}\cdot(X_{Lim,Right}-X_0) \f$ \n
                        \n
                        - **Case 3:** Current and next x value enclose the left integration limit: \n
                        \f$ IntStep = \frac{Y_{Lim,Left}+Y_0}{2}\cdot(X_1-X_{Lim,Left}) \f$\n
                        \n
                        - **Case 4:** Current and next x value enclose both integration limits: \n
                        \f$ IntStep = \frac{Y_{Lim,Left}+Y_{Lim,Right}}{2}\cdot(X_{Lim,Right}-X_{Lim,Left}) \f$ \n
                        \n
                        - **Case 5:** Current and next x value don't enclose a part of the integration area:\n
                        \f$ IntStep = 0\f$

  @author               

  @testmethod           @ref TEST_CDHISTINTEGRATE_001 \n
                        @ref TEST_CDHISTINTEGRATE_002

  @traceability         Design Decision


*************************************************************************************************************************/
void CDHistIntegrate(float32 const afXValues[], float32 const afYValues[], float32 fLeftIntLimX, 
                        float32 fRightIntLimX    , uint8 const uiLenXYVec   , float32* pOut_fHistIntegralResult)
{
  uint8 uiCountXYVec;
  float32 fHistIntegralResult = 0.0f;
  float32 fLeftIntLimY;
  float32 fRightIntLimY;
  float32 fTmp;
  
  /* Securing limits */
  if (fLeftIntLimX > fRightIntLimX) 
  {
    /* Swap left and right values */
    fTmp          = fLeftIntLimX;
    fLeftIntLimX  = fRightIntLimX;
    fRightIntLimX = fTmp;
  }

  fLeftIntLimX  = MAX(fLeftIntLimX,afXValues[0]);
  fLeftIntLimX  = MIN(fLeftIntLimX,afXValues[uiLenXYVec-1u]);
  fRightIntLimX = MAX(fRightIntLimX,afXValues[0]);
  fRightIntLimX = MIN(fRightIntLimX,afXValues[uiLenXYVec-1u]);

  for (uiCountXYVec = 0u; uiCountXYVec < (uiLenXYVec-1u); ++uiCountXYVec)
  {
    /* Calculate Y Values for left and right integration limit */
    fLeftIntLimY  = afYValues[uiCountXYVec] 
    + (((fLeftIntLimX-afXValues[uiCountXYVec])/(afXValues[uiCountXYVec+1u]-afXValues[uiCountXYVec]))
      *(afYValues[uiCountXYVec+1u]-afYValues[uiCountXYVec]));
    fRightIntLimY = afYValues[uiCountXYVec] 
    + (((fRightIntLimX-afXValues[uiCountXYVec])/(afXValues[uiCountXYVec+1u]-afXValues[uiCountXYVec]))
      *(afYValues[uiCountXYVec+1u]-afYValues[uiCountXYVec]));

    /* Test if left and right integration limits are between the current two sampling points */
    if ((fLeftIntLimX > afXValues[uiCountXYVec]) && (fLeftIntLimX < afXValues[uiCountXYVec+1u]))
    {
      if ((fRightIntLimX > afXValues[uiCountXYVec]) && (fRightIntLimX < afXValues[uiCountXYVec+1u]))
      {
        // Case 4
        fHistIntegralResult += 0.5f*(fLeftIntLimY+fRightIntLimY) * (fRightIntLimX-fLeftIntLimX);/*PRQA S 3121*//*Trapezoidal rule*/
      }
      else
      {
        // Case 3
        fHistIntegralResult += 0.5f*(fLeftIntLimY+afYValues[uiCountXYVec+1u]) * (afXValues[uiCountXYVec+1u]-fLeftIntLimX);/*PRQA S 3121*//*Trapezoidal rule*/
      }
    }
    else
      if ((fRightIntLimX > afXValues[uiCountXYVec]) && (fRightIntLimX < afXValues[uiCountXYVec+1u]))
      {
        //Case 2
        fHistIntegralResult += 0.5f*(afYValues[uiCountXYVec]+fRightIntLimY) * (fRightIntLimX-afXValues[uiCountXYVec]);/*PRQA S 3121*//*Trapezoidal rule*/
      }
      else
      {
        if ((fLeftIntLimX <= afXValues[uiCountXYVec]) && (fRightIntLimX >= afXValues[uiCountXYVec+1u]))
        {
          //Case 1
          fHistIntegralResult += 0.5f*(afYValues[uiCountXYVec]+afYValues[uiCountXYVec+1u]) * (afXValues[uiCountXYVec+1u]-afXValues[uiCountXYVec]);/*PRQA S 3121*//*Trapezoidal rule*/
        }
      }
  }

  *pOut_fHistIntegralResult = fHistIntegralResult;
  
}

/*************************************************************************************************************************
  Functionname:         CDUpdateHistory                                                                              */ /*!

  @brief                Appends the current object positions to the history structures.

  @description          Appends the current ego and object positions to the history structures by calling the 
                        function @ref CDUpdateObjHist.
                        @startuml CDUpdateHistory_activity.png
                        start
                          partition "Execute for all objects" {
                            if(Object is deleted?) then (Yes)
                              :1}
                            else (No)
                              :2}
                              #Orange:Append object position to history
                              <b>CDUpdateObjHist</b> >
                            endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in]            None

  @glob_in              ACDC_b_GetEMGenObjIsDeleted
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim

  @testmethod           @ref TEST_CDUPDATEHISTORY_001 \n
                        @ref TEST_CDUPDATEHISTORY_002 \n


  @traceability         Design Decision

*************************************************************************************************************************/
void CDUpdateHistory(void)
{
  ObjNumber_t iObjectIndex;

  /* update Object history */
  for(iObjectIndex=0; iObjectIndex < EM_N_OBJECTS; iObjectIndex++)
  {
    if (ACDC_b_GetEMGenObjIsDeleted(iObjectIndex) == b_FALSE)
    {
      CDUpdateObjHist(iObjectIndex);
    }
  }
}

/*************************************************************************************************************************
  Functionname:         CDPushHistoryFloat                                                                           */ /*!

  @brief                Adds a new value to the history float.

  @description          The new value is written to the position following on the one marked by the LastID counter.
                        Instead of shifting all values, this ID allows, to leave all values at their positions \n
                        and only increase the counter. If this counter reaches the maximum number of values 
                        (\ref CD_PSC_PROB_OBSERVE_Y_DIST_N), it is set back to 0.
                        @startuml CDPushHistoryFloat_activity.png
                        start
                          if(LastID < MaxNofValues) then (Yes)
                            :1}
                            :NextID = LastID + 1;
                          else (No)
                            :2}
                            :NextID = 0;
                          endif

                          :Add new value at "NextID" position
                          and update LastID;

                          if (ValidValueCounter < MaxNofValues) then (Yes)
                            :3}
                            :Increase ValidValueCounter;
                          else(No)
                            :4}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            fLatestValue :      Value that shall be written to the history float. @range ]-...,+...[
  @param[in,out]        pIn_FloatHistory :  History float to which the value shall be written.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               

  @testmethod           @ref TEST_CDPUSHHISTORYFLOAT_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void CDPushHistoryFloat( float32 fLatestValue, CDHistoryFloat_t* pIn_FloatHistory )
{
  /* Determine ID to save latest Value */
  uint8 uiNextID = (pIn_FloatHistory->uiLastID + 1u) % CD_PSC_PROB_OBSERVE_Y_DIST_N;
  /* Update LastID */
  pIn_FloatHistory->afValues[uiNextID] = fLatestValue;
  pIn_FloatHistory->uiLastID = uiNextID;
  pIn_FloatHistory->uiValidValueCount = MIN( (pIn_FloatHistory->uiValidValueCount + 1u), CD_PSC_PROB_OBSERVE_Y_DIST_N );
   
}

/*************************************************************************************************************************
  Functionname:         CDUpdateObjHist                                                                              */ /*!

  @brief                Appends an objects current kinematic to the object history.

  @description          Appends an objects current kinematic to the object history. If an object is new,
                        first the entire history is deleted. Otherwise the current position is appended \n
                        to the history and the positions from the former cycles are transformed to the current
                        coordinate system.
                        @startuml CDUpdateObjHist_activity.png
                        start
                          if(Object is new?) then (Yes)
                            :1}
                            #Orange:Reset objects history information
                            <b>CDResetObjHistoryFloat</b> >
                          else(No)
                            :2}
                          endif

                          if (Object is deleted?) then (No)
                            :3}
                            #Orange:Append current position to objects history
                            <b>CDPushHistoryFloat</b> >
                            #Orange:Transform positions from former cycles to 
                            current coordinate system
                            <b>CDTransform2DCoordHistoryFloat</b> >
                          else(Yes)
                            :4}
                            #Orange:Reset objects history information
                            <b>CDResetObjHistoryFloat</b> >
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range [0,+...[

  @glob_in              @ref ACDC_b_GetEMGenObjIsNew \n
                        @ref ACDC_p_GetObjPositions \n
                        @ref ACDC_p_ModObjKinematicHistory \n
                        @ref ACDC_p_GetTrafoMatForward\n
  @glob_out             @ref ACDC_p_ModObjKinematicHistory \n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  Object index have to be valid
  @post                 None

  @InOutCorrelation     see description

  @author               Gregor Powarzynski | Gregor.Powarzynski@continental-corporation.com

  @testmethod           @ref TEST_CDUPDATEOBJHIST_001 \n
                        @ref TEST_CDUPDATEOBJHIST_002 \n
                        @ref TEST_CDUPDATEOBJHIST_003   

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDUpdateObjHist( ObjNumber_t iObjectIndex)
{
  ACDCObjPositions_t const * const pCurrACDCObjPos = ACDC_p_GetObjPositions(iObjectIndex);
  CDKinHistObj_t           * const pObjKinHist     = ACDC_p_ModObjKinematicHistory(iObjectIndex);

  if(ACDC_b_GetEMGenObjIsNew(iObjectIndex) == b_TRUE)
  {
    CDResetObjHistoryFloat(pObjKinHist);
  }

  CDPushHistoryFloat( pCurrACDCObjPos->GenObject.fX, &(pObjKinHist->sPosX   ) );
  CDPushHistoryFloat( pCurrACDCObjPos->GenObject.fY, &(pObjKinHist->sPosY   ) );
  CDPushHistoryFloat( pCurrACDCObjPos->Var.fY      , &(pObjKinHist->sPosYVar) );

  CDTransform2DCoordHistoryFloat( ACDC_p_GetTrafoMatForward(), &(pObjKinHist->sPosX), &(pObjKinHist->sPosY) );
}

/*************************************************************************************************************************
  Functionname:         CDResetObjHistoryFloat                                                                       */ /*!

  @brief                Resets an object history float.

  @description          Resets an object history float (\ref CDKinHistObj_t) by calling the function 
                        \ref CDResetHistoryFloat for each member of the structure.

  @return               void

  @param[in,out]        pIn_ObjHistory : Object history float that shall be reseted.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author

  @testmethod           @ref TEST_CDRESETOBJHISTORYFLOAT_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void CDResetObjHistoryFloat( CDKinHistObj_t* pIn_ObjHistory )
{
  CDResetHistoryFloat( &(pIn_ObjHistory->sPosX) );
  CDResetHistoryFloat( &(pIn_ObjHistory->sPosY) );
  CDResetHistoryFloat( &(pIn_ObjHistory->sPosYVar) );
}

/*************************************************************************************************************************
  Functionname:         CDTransform2DCoordHistoryFloat                                                               */ /*!

  @brief                Transforms all position values of an history float to the corresponding coordinates of 
                        the current cycle.

  @description          As the ego vehicle usually changes its position from one cycle to the other, also the 
                        coordinate system changes. Therefore historical positions have to be adapted to the \n
                        currently valid coordinate system. This calculation is executed by the function 
                        \ref CML_v_TransformPosition2D for every history value.
                        @startuml CDTransform2DCoordHistoryFloat_activity.png
                        start
                          partition "Execute for each value of a history float" {
                            if (Current float is last added float?) then (Yes)
                              :1}
                              :No transformation necessary;
                            else (No)
                              :2}
                              #Orange:Transform position into
                              the new coordinate system
                              <b>CML_v_TransformPosition2D</b> >
                            endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in]            *M : Matrix used for the transformation
  @param[in,out]        FloatHistory_X : history float containing historical x-positions. @phys_unit [m] @range ]-...,+...[
  @param[in,out]        FloatHistory_Y : history float containing historical y-positions. @phys_unit [m] @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               

  @testmethod           @ref TEST_CDTRANSFORM2DCOORDHISTORYFLOAT_001

  @traceability         Design Decision

*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2017-10-19, reviewer: Wenting Huang, reason: FloatHistory_X and FloatHistory_Y cannot be const in CML_v_TransformPosition2D()*/
static void CDTransform2DCoordHistoryFloat( GDBTrafoMatrix2D_t const *M, CDHistoryFloat_t* FloatHistory_X, CDHistoryFloat_t* FloatHistory_Y )
{
  sint32 iCount;

  /* Loop over all valid points. Start at 1, because the last id value is already up to date and must not be transformed.*/
  for(iCount = 1; iCount < (sint32)FloatHistory_X->uiValidValueCount; ++iCount)
  {
    sint32 iIndex = (sint32)FloatHistory_X->uiLastID - iCount;

    /* The index is negative add the length of the array to start over with the last element */
    if (iIndex < 0)
    {
      iIndex += (sint32)CD_PSC_PROB_OBSERVE_Y_DIST_N;
    }

    CML_v_TransformPosition2D(M, &(FloatHistory_X->afValues[iIndex]), &(FloatHistory_Y->afValues[iIndex]));
  }
}

/*************************************************************************************************************************
  Functionname:         CDResetHistoryFloat                                                                          */ /*!

  @brief                Resets all values of an history float

  @description          Resets all values contained in a history float structure: \n
                        Sets LastId and ValidValueCounter to 0. Sets the value of all contained history values to 0.

  @return               void

  @param[in,out]        pIn_FloatHistory : History float that shall be reseted.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 History float is initialized

  @InOutCorrelation     see description
  @author 

  @testmethod           @ref TEST_CDRESETHISTORYFLOAT_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void CDResetHistoryFloat( CDHistoryFloat_t* pIn_FloatHistory )
{
  uint8 uiCurrID;

  for ( uiCurrID = 0u; uiCurrID < CD_PSC_PROB_OBSERVE_Y_DIST_N; ++uiCurrID )
  {
    pIn_FloatHistory->afValues[uiCurrID] = 0.0f;
  }

  pIn_FloatHistory->uiLastID = 0u;
  pIn_FloatHistory->uiValidValueCount = 0u;
}

#endif /* #if (CD_USE_GEN_PSC) */

#endif /* #if (ACDC_CFG_CD) */
//!@}
