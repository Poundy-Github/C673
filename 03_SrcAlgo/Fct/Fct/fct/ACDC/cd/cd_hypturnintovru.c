/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypTurnIntoVRU.c

DESCRIPTION:               Implementation of the turn into oncoming pedestrian hypothesis

AUTHOR:                    $Author: Kanthi, Sheetal (uia80691) (uia80691) $

CREATION DATE:             $Date: 2019/08/13 11:06:08CEST $

VERSION:                   $Revision: 1.13 $

*******************************************************************************/

/*******************************************************************************
  INCLUDES
*******************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)

/*******************************************************************************
  MODULE DESCRIPTION
*******************************************************************************/
/**
@defgroup     cd_hypTurnIntoVRU HypTurnIntoVRU
@ingroup      cd

@brief        The turn into oncoming VRU hypothesis describes
              a scenario in which the ego vehicle is turning into a
              crossing pedestrian.\n\n
@description  The external functions of the module is: @ref CDHypTurnIntoVRUMain and @ref CDEgoTurningEval.
                - The function @ref CDHypTurnIntoVRUMain executes the main processing steps of the turn into VRU collision hypothesis.
                - The function @ref CDEgoTurningEval executes the state machine for the detection of ego vehicle turning scenario
@{
*/

/*******************************************************************************
  MACROS 
*******************************************************************************/
#if !CD_USE_GEN_PSC 
#error "CD_USE_GEN_PSC" has to be activated
#endif
/*******************************************************************************
  TYPEDEFS 
*******************************************************************************/

/*******************************************************************************
  (SYMBOLIC) CONSTANTS 
*******************************************************************************/

/*******************************************************************************
  VARIABLES 
*******************************************************************************/

/*******************************************************************************
  LOCAL FUNCTIONS Declarations
*******************************************************************************/
static boolean  CDHypoTurnIntoVRUObjectFilter        ( ObjNumber_t       const         iObjectIndex );
static void     CDHypoTurnIntoVRUCalculateProb       ( ObjNumber_t       const         iObjectIndex, 
                                                       CDIntHypothesis_t       * const pHypothesis );
static void     CDEvalStateTransitionNotTurning     ( void );
static void     CDEvalStateTransitionLeftTurning    ( void );
static void     CDEvalStateTransitionRightTurning   ( void );

/*******************************************************************************
  LOCAL FUNCTIONS Definitions
*******************************************************************************/

/*******************************************************************************
  Functionname:      CDHypoTurnIntoVRUObjectFilter                        */ /*!

  @brief             Checks whether the object is relevant for turning into crossing VRU hypothesis

  @description       To open a turn into vru hypothesis, the following criteria have to be fulfilled :
                     - The Objects TTC has to be below threshold
                     - The ego-vehicle kinematics confirms the turning scenario
                     - PSC collision probability of the object should be greater than predefined thershold for more than 5 cycles
                     - The Object has to be a moving target.
                     The filtration regarding HypCat and object class is done formerly in the generic hypothesis handler.
                     However, the hypothesis is not opened on objects with absolute velocity less than specific threshold 
                     and have only stationary HypCat. This logic is implemented in the hypothesis filter.

  @return            boolean : True if object fulfills the filter conditions.

  @param[in]         iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS]

  @glob_in           @ref CD_f_GetTTC3 \n
                     @ref ACDC_p_GetEgoDrvScenario \n
                     @ref ACDC_p_GetObjMovement \n
                     @ref ACDC_p_GetObjHypothesisData \n
                     @ref ACDC_p_GetEMGenObj \n
                     @ref ACDC_p_GetObjStaticEvasionData

  @glob_out          None

  @c_switch_part     None
  @c_switch_full     @ref ACDC_CFG_CD \n
                     @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre               None
  @post              None

  @InOutCorrelation  see description

  @testmethod        @Generic_Testmethods

  @author            Matthias Lorenzen
*******************************************************************************/
static boolean CDHypoTurnIntoVRUObjectFilter(ObjNumber_t const iObjectIndex)
{
  CDEgoTurningState_t                 eEgoCurrentTurnState    = ACDC_p_GetEgoDrvScenario()->eEgoCurrentTurnState;
  ACDCObjMovement_t     const * const pObjMovement            = ACDC_p_GetObjMovement(iObjectIndex);
  CDObj_Hypothesis_t    const * const pObjHypData             = ACDC_p_GetObjHypothesisData(iObjectIndex);
  EM_t_GenObject        const * const pEmObj                  = ACDC_p_GetEMGenObj(iObjectIndex);
  CDObj_EvasionStatic_t const * const pEvasion                = ACDC_p_GetObjStaticEvasionData(iObjectIndex);
  float32               const         fObjAbsVel              = SQRT( SQR(pObjMovement->Abs.Vel.fX) + SQR(pObjMovement->Abs.Vel.fY) );
  boolean                             bAcceptObj              = TRUE;

  if (     ( CD_f_GetTTC3(iObjectIndex) > CD_TURNINTOVRU_MAX_TTC_FILTER                     )
        || ( eEgoCurrentTurnState == CD_EGO_TURNING_NO                                      )
        || ( pEvasion->PSCCollProbHist < CD_TURNINTOVRU_MIN_COLL_CONFIRM                    )
        || (    ( pObjHypData->HypothesisHist.TurnIntoVRU != 1                            )
             && ( fObjAbsVel < CD_TURNINTOVRU_OBJ_ABS_VEL_MIN                             )
             && ( CML_GetBit(pEmObj->Qualifiers.eEbaHypCat, FPS_EBA_HYP_CAT_STAT) == TRUE )
             && ( CML_GetBit(pEmObj->Qualifiers.eEbaHypCat, FPS_EBA_HYP_CAT_XING) != TRUE )
             && ( CML_GetBit(pEmObj->Qualifiers.eEbaHypCat, FPS_EBA_HYP_CAT_ONC)  != TRUE ) ) )
  {
    bAcceptObj = FALSE;
  }

  return bAcceptObj;
}

/*******************************************************************************
  Functionname:         CDHypoTurnIntoVRUCalculateProb                        */ /*!

  @brief                Calculates the probability of the turn into vru hypothesis.

  @description          The collision probability is calculated by means of the probability of 
                        speed concept: @ref CDPSCGetProbCollision\n
                        The required width of the ego corridor is assumed to be the vehicle width. \n

                        @startuml CDHypoTurnIntoVruCalculateProb_activity.png
                        start
                          :Calculate width of ego corridor;
                          note left: Assumed as ego-vehicle width
                          #Orange: Calculate psc collision probability:
                          <b>CDPSCGetProbCollision</b> >
                          note left: psc = probability of speed concept
                          :Determine confidence for PSC value;
                          note left
                            PSC value valid if angle between
                            object velocity vector and vector from object
                            to collision point is small or distance to collision 
                            is already low
                          end note
                          :set hypothesis probability to PSC probability
                          multiplied with confidence;
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        *pHypothesis : Pointer to the hypothesis for which the probability shall be calculated

  @glob_in              @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetObjMovement \n
                        @ref ACDC_p_GetObjPositions 

  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Lorenzen
*************************************************************************************************************************/
static void CDHypoTurnIntoVRUCalculateProb( ObjNumber_t       const         iObjectIndex, 
                                            CDIntHypothesis_t       * const pHypothesis)
{
  /* probability of speed concept */
  float32 fPSCProb       = 0.0f;
  float32 fEgoWidthLeft  = 0.5f * ACDC_p_GetEgoGeometry()->fWidth;
  float32 fEgoWidthRight = fEgoWidthLeft;
  
  /* confidence for PSC concept */
  ACDCObjMovement_t  const * const pObjMovement  = ACDC_p_GetObjMovement(iObjectIndex);
  ACDCObjPositions_t const * const pObjPositions = ACDC_p_GetObjPositions(iObjectIndex);
  SFLVector2D_t                    CollPt;
  SFLVector2D_t                    ObjPosToCollPt;
  float32                          fConfPSCProb = 0.0f;
  float32                          fTTCOnTrajDummy;
  float32                          fMinDistDummy;      /* dummy variable for unused function input/output */
  float32                          fObjCollPtDist;
  float32                          fObjAbsVel;

  /* get PSC probability using velocity to collision point from EMP module */
  fPSCProb = CDPSCGetProbCollision(iObjectIndex, fEgoWidthLeft, fEgoWidthRight,CD_PSC_USE_TO_COLL_POINT);
 
  /* get confidence for PSC calculation by checking if target is moving towards ego front center at TTC */
  EMPCalcDynObjToEgoFrontRelation( iObjectIndex, &fTTCOnTrajDummy, &CollPt, &fMinDistDummy, &fObjCollPtDist);
  ObjPosToCollPt.fX = CollPt.fX - pObjPositions->GenObject.fX;
  ObjPosToCollPt.fY = CollPt.fY - pObjPositions->GenObject.fY;
  fObjAbsVel = SQRT( SQR(pObjMovement->Abs.Vel.fX) + SQR(pObjMovement->Abs.Vel.fY) );
  if ( (fObjAbsVel > C_F32_DELTA) && (fObjCollPtDist > C_F32_DELTA) )
  { /* confidence ~ cos(angle(obj velocity vector, (obj pos - col pt) vector)) */
    /* get cosine */
    fConfPSCProb = /* cos(.) = < (EgoPos(TTC) - ObjPos(0)) , v_Obj > / |EgoPos(TTC) - ObjPos(0)| */ 
      fABS( ( (ObjPosToCollPt.fX * pObjMovement->Abs.Vel.fX) + 
              (ObjPosToCollPt.fY * pObjMovement->Abs.Vel.fY) ) /
            (fObjCollPtDist * fObjAbsVel ) );
    /* map values between CD_TURNINTOVRU_COS_NO_CONF_ANGL,CD_TURNINTOVRU_COS_MAX_CONF_ANGL to range [0,1] */
    fConfPSCProb = CML_f_boundedLinInterpol2(fConfPSCProb,CD_TURNINTOVRU_COS_NO_CONF_ANGL,CD_TURNINTOVRU_COS_MAX_CONF_ANGL,0.0f,1.0f);
    /* apply degradation only for objects that are not close to the collision point */
    fConfPSCProb = CML_f_boundedLinInterpol2(fObjCollPtDist,CD_TURNINTOVRU_DIST_IGNR_CONF,CD_TURNINTOVRU_DIST_FULL_CONF,1.0f,fConfPSCProb);
  }
  else /* either object at coll pt or object velocity = 0 */
  {
    fConfPSCProb = 1.0f;
  }

  fPSCProb *= fConfPSCProb;
  
  pHypothesis->fHypothesisProbability = fPSCProb;
}


/*******************************************************************************
  Functionname:         CDHypTurnIntoVRUMain                              */ /*!

  @brief                Handles the main steps of the turn into oncoming 
                        pedestrian (CPTA) hypothesis.

  @description          Handles the turn into oncoming pedestrian (CPTA) 
                        hypothesis by executing the three common steps for a 
                        hypothesis generation (see diagram "Common steps of hypothesis creation"):
                        1. Call of the hypothesis object filter: @ref CDHypoTurnIntoVRUObjectFilter
                        2. Call of the hypothesis probability calculation: @ref CDHypoTurnIntoVRUCalculateProb
                        3. If an object with sufficient probability was found:
                        Call of the hypothesis selection: @ref CDHypSelCreateInternalHypotheses.
                        More information about the three main steps that are 
                        described in the diagram can be found in the description
                        of the @ref cd_hyphandler.
                        @image html CommonHypothesisProcess_activity.png 
                        "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0, EM_N_OBJECTS[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history (if exists)

  @glob_in              @ref ACDC_p_ModObjHypothesisData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS \n

  @pre                  None
  @post                 No changes

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Lorenzen | matthias.lorenzen@continental-corporation.com
*************************************************************************************************************************/
void CDHypTurnIntoVRUMain( ObjNumber_t const iObjectIndex, 
                           boolean     const bObjFilterMatched )
{
  CDIntHypothesis_t          Hypothesis;
  CDObj_Hypothesis_t * const pObjHypData  = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), CDHypothesisType_TurnIntoVRU);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), CDHypothesisType_TurnIntoVRU);

  /* Default Hypothesis Prob Calculation calling */
  if( bObjFilterMatched == TRUE)
  {
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart, ACDC_RTA_CD_HYP_TURNINTOVRU_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoTurnIntoVRUObjectFilter(iObjectIndex) == TRUE )
    {
      /* Default Hypothesis handling */
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), CDHypothesisType_TurnIntoVRU);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_TurnIntoVRU);

      CDHypoTurnIntoVRUCalculateProb(iObjectIndex, &Hypothesis);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > CD_TURNINTOVRU_MIN_HYP_PROB)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), CDHypothesisType_TurnIntoVRU);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.TurnIntoVRU = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.TurnIntoVRU = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.TurnIntoVRU = 0u;
    }
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYP_TURNINTOVRU_SINGLE, (uint8)(iObjectIndex));
  }
  else
  {
    pObjHypData->HypothesisHist.TurnIntoVRU = 0u;
  }
}

/*************************************************************************************************************************
  Functionname:         CDEgoTurningEval                                                                            */ /*!

  @brief                The main function of the ego turning detection

  @description          In this function, The state machine of the detection of the Ego-vehicle turning maneuver is executed.
                            1- Firstly, the Ego-vehicle VDY curvature is filtered.
                            2- The state machine is executed. Based on the current state. the corresponding state transition function
                                is called.

                        The following steps are executed:
                        @startuml CDEgoTurningEval.png
                        start
                          #Orange:Low pass filtering the ego curvature:
                          <b>CML_f_LowPassFilter2</b> >
                          if (Current state is not turning?) then (Yes)
                            #Orange:Evaluate the transition conditions of the state not turning:
                            <b>CDEvalStateTransitionNotTurning</b> >
                          else(No)
                            if (Current state is left turning?) then (Yes)
                              #Orange:Evaluate the transition conditions of the state left turning:
                              <b>CDEvalStateTransitionLeftTurning</b> >
                            else(No)
                              if (Current state is right turning?) then (Yes)
                              #Orange:Evaluate the transition conditions of the state right turning:
                              <b>CDEvalStateTransitionRightTurning</b> >
                              endif
                            endif
                          endif
                        stop
                        @enduml
  @return               void

  @param[in]            void

  @glob_in              ACDC_p_GetVDYDynObjSync\n
                        ACDC_p_ModEgoDrvScenario\n
                        ACDC_p_GetEgoDrvScenario
  @glob_out             ACDC_p_ModEgoDrvScenario

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248
*************************************************************************************************************************/
void CDEgoTurningEval(void)
{
  float32          const         fEgoCurveVDY         = ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve;
  float32                * const pfEgoCrvLowPassOut   = &(ACDC_p_ModEgoDrvScenario()->fEgoCurveLowPassOut);

  /* Apply a low pass filter on the VDY ego curve and update the filter output*/
  CML_f_LowPassFilter2(pfEgoCrvLowPassOut,fEgoCurveVDY,CD_FILTER_FACTOR_EGO_CRV);

  /* Apply the state machine for the determination of the ego turn state */
  switch ( ACDC_p_GetEgoDrvScenario()->eEgoCurrentTurnState )
  {
    case CD_EGO_TURNING_NO:
    {
      /* Evaluate the transition conditions of the state not turning */
      CDEvalStateTransitionNotTurning();
      break;
    }

    case CD_EGO_TURNING_LEFT:
    {
      /* Evaluate the transition conditions of the state left turning */
      CDEvalStateTransitionLeftTurning();
      break;
    }

    case CD_EGO_TURNING_RIGHT:
    {
      /* Evaluate the transition conditions of the state right turning */
      CDEvalStateTransitionRightTurning();
      break;
    }
    default:
    {
      /* This path is not possible */
      break;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         CDEvalStateTransitionNotTurning                                                            */ /*!

  @brief                Evaluate the state transition conditions of the state not turning

  @description          In this function, the transition conditions from the state not turning are evaluated:
                          1- The Block distances are decremented by the value of driven distance in one cycle.
                          2- Evaluate the low pass filtered ego-vehicle curvature against the velocity dependent curvature threshold.
                          3- The ego velocity is evaluated against the maximum allowed velocity to detect turning into vru scenario
                          4- based on the sign of the curvature the next state is selected to be left/right turning
                        The following steps are executed:
                        @startuml CDEvalStateTransitionNotTurning.png
                        start
                        if (CD_BLK_DIST_TURN_OPST_DIR switched on?) then (Yes)
                        partition #LightBlue **CD_BLK_DIST_TURN_OPST_DIR** {
                        :Decrement the blocking distance of 
                         left and right turning;
                          if (Abs. Ego-Curvature exceed threshold
                              and Ego-Velocity less than max. speed?) then (Yes)
                            if (Is sign of Ego Curvature positive and
                            the blocking distance of left turn in zero?) then (Yes)
                               :Set the state of state machine to turn to left;
                               :Reset the blocking distances of turn to left and right;
                            else(No)
                              if (Is sign of Ego Curvature negative and
                              the blocking distance of right turn in zero?) then (Yes)
                              :Set the state of state machine to turn to right;
                              :Reset the blocking distances of turn to left and right;
                              else(No)
                              endif
                            endif
                          else(No)
                          endif
                        }
                        else(No)
                          if (Abs. Ego-Curvature exceed threshold
                          and Ego-Velocity less than max. speed?) then (Yes)
                            if (Is sign of Ego Curvature positive?) then (Yes)
                            :Set the state of state machine to turn to left;
                            else(No)
                              if (Is sign of Ego Curvature negative?) then (Yes)
                              :Set the state of state machine to turn to right;
                              else(No)
                              endif
                            endif
                          else(No)
                          endif
                        endif
                        stop
                        @enduml
  @return               void

  @param[in]            None

  @glob_in              ACDC_f_GetEgoVelObjSync \n
                        ACDC_f_GetEgoAccelObjSync \n
                        ACDC_p_GetEgoDrvScenario \n
                        ACDC_p_ModEgoDrvScenario \n
                        ACDC_f_GetCycleTime
  @glob_out             ACDC_p_ModEgoDrvScenario

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248
*************************************************************************************************************************/
static void CDEvalStateTransitionNotTurning(void)
{
  float32                           fLongVelocity         = ACDC_f_GetEgoVelObjSync();
  float32             const         fEgoCrvTurnThre       = CML_f_CalculatePolygonValue(CD_EGO_DRV_CRV_TRN_THRE_NO, CD_EGO_DRV_CRV_TRN_THRE, fLongVelocity);
  float32             const         fEgoCrvLowPassOut     = ACDC_p_GetEgoDrvScenario()->fEgoCurveLowPassOut;
  CDEgoTurningState_t       * const peEgoCurrentTurnState = &(ACDC_p_ModEgoDrvScenario()->eEgoCurrentTurnState);
#if(CD_BLK_DIST_TURN_OPST_DIR)
  float32                           fLongAccel            = ACDC_f_GetEgoAccelObjSync();
  float32                           fCycleTime            = ACDC_f_GetCycleTime();
  float32           const           fDrivenDistanceCycle  = ((fLongVelocity * fCycleTime) + ((0.5f * fLongAccel) * SQR(fCycleTime)));
  float32                   * const pfDistBlockLeftTurn   = &(ACDC_p_ModEgoDrvScenario()->fDistBlockLeftTurn);
  float32                   * const pfDistBlockRightTurn  = &(ACDC_p_ModEgoDrvScenario()->fDistBlockRightTurn);

  /* Decrement the blocking distance of the left turn by integrating the velocity */
  if (*pfDistBlockLeftTurn > CML_f_Delta)
  {
    *pfDistBlockLeftTurn -= fDrivenDistanceCycle;
    *pfDistBlockLeftTurn = CML_f_Max(*pfDistBlockLeftTurn, 0.f);
  }

  /* Decrement the blocking distance of the left turn by integrating the velocity */
  if (*pfDistBlockRightTurn > CML_f_Delta)
  {
    *pfDistBlockRightTurn -= fDrivenDistanceCycle;
    *pfDistBlockRightTurn = CML_f_Max(*pfDistBlockRightTurn, 0.f);
  }
#endif

  /* Check the state transition conditions */
  if ( (fABS(fEgoCrvLowPassOut) >= fEgoCrvTurnThre) && (fLongVelocity < CD_EGO_DRV_CRV_VEL_MAX))
  {
    if ((CML_f_Sign(fEgoCrvLowPassOut) == 1)
#if(CD_BLK_DIST_TURN_OPST_DIR)
        && (*pfDistBlockLeftTurn <= CML_f_Delta)
#endif
        )
    {
      *peEgoCurrentTurnState = CD_EGO_TURNING_LEFT;
#if(CD_BLK_DIST_TURN_OPST_DIR)
      *pfDistBlockLeftTurn   = 0.f;
      *pfDistBlockRightTurn  = 0.f;
#endif
    }
    else if((CML_f_Sign(fEgoCrvLowPassOut) == -1) 
#if(CD_BLK_DIST_TURN_OPST_DIR)
      && (*pfDistBlockRightTurn <= CML_f_Delta)
#endif
      )
    {
      *peEgoCurrentTurnState = CD_EGO_TURNING_RIGHT;
#if(CD_BLK_DIST_TURN_OPST_DIR)
      *pfDistBlockLeftTurn   = 0.f;
      *pfDistBlockRightTurn  = 0.f;
#endif
    }
    else
    {
      /* Do nothing. The state is not to be changed*/
    }
  }

}

/*************************************************************************************************************************
  Functionname:         CDEvalStateTransitionLeftTurning                                                           */ /*!

  @brief                Evaluate the state transition conditions of the state left turning.

  @description          Evaluate the state transition conditions of the state left turning:
                          - Evaluate the low pass filtered ego-vehicle curvature against the velocity dependent curvature threshold.
                          The following steps are executed:
                          @startuml CDEvalStateTransitionLeftTurning.png
                          start
                          if (Ego curvature falls bellow the keep threshold?) then (Yes)
                          :Set the state of state machine to Not turning;
                          partition #LightBlue **CD_BLK_DIST_TURN_OPST_DIR** {
                          :Set the blocking distance for turning right;
                          }
                          else(No)
                          endif
                          end
                          @enduml
  @return               void

  @param[in]            None

  @glob_in              ACDC_f_GetEgoVelObjSync \n
                        ACDC_p_GetEgoDrvScenario \n
                        ACDC_p_ModEgoDrvScenario
                        
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248
*************************************************************************************************************************/
static void CDEvalStateTransitionLeftTurning(void)
{
  float32                           fLongVelocity         = ACDC_f_GetEgoVelObjSync();
  float32             const         fEgoCrvTurnKeepThre   = CML_f_CalculatePolygonValue(CD_EGO_DRV_CRV_KEEP_TRN_THRE_NO, CD_EGO_DRV_CRV_KEEP_TRN_THRE, fLongVelocity);
  float32             const         fEgoCrvLowPassOut     = ACDC_p_GetEgoDrvScenario()->fEgoCurveLowPassOut;
  CDEgoTurningState_t       * const peEgoCurrentTurnState = &(ACDC_p_ModEgoDrvScenario()->eEgoCurrentTurnState);
#if(CD_BLK_DIST_TURN_OPST_DIR)
  float32                 * const fDistBlockRightTurn   = &(ACDC_p_ModEgoDrvScenario()->fDistBlockRightTurn);
#endif

  /* Check the keep dependent curvature threshold */
  if (fEgoCrvLowPassOut < fEgoCrvTurnKeepThre)
  {
    *peEgoCurrentTurnState = CD_EGO_TURNING_NO;
#if(CD_BLK_DIST_TURN_OPST_DIR)
    *fDistBlockRightTurn   = CML_f_CalculatePolygonValue(CD_EGO_DRV_CRV_BLK_OPP_DIR_NO, CD_EGO_DRV_CRV_BLK_OPP_DIR, fLongVelocity);
#endif
  }
}


/*************************************************************************************************************************
  Functionname:         CDEvalStateTransitionRightTurning                                                          */ /*!

  @brief                Evaluate the state transition conditions of the state right turning.

  @description          Evaluate the state transition conditions of the state right turning:
                          - Evaluate the low pass filtered ego-vehicle curvature against the velocity dependent curvature threshold.
                          The following steps are executed:
                          @startuml CDEvalStateTransitionRightTurning.png
                          start
                          if (Ego curvature falls bellow the keep threshold?) then (Yes)
                          :Set the state of state machine to Not turning;
                          partition #LightBlue **CD_BLK_DIST_TURN_OPST_DIR** {
                          :Set the blocking distance for turning left;
                          }
                          else(No)
                          endif
                          end
                          @enduml
  @return               void

  @param[in]            None

  @glob_in              ACDC_f_GetEgoVelObjSync \n
                        ACDC_p_GetEgoDrvScenario \n
                        ACDC_p_ModEgoDrvScenario
  @glob_out             ACDC_p_ModEgoDrvScenario

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248
*************************************************************************************************************************/
static void CDEvalStateTransitionRightTurning(void)
{
  float32                           fLongVelocity         = ACDC_f_GetEgoVelObjSync();
  float32             const         fEgoCrvTurnKeepThre   = CML_f_CalculatePolygonValue(CD_EGO_DRV_CRV_KEEP_TRN_THRE_NO, CD_EGO_DRV_CRV_KEEP_TRN_THRE, fLongVelocity);
  float32             const         fEgoCrvLowPassOut     = ACDC_p_GetEgoDrvScenario()->fEgoCurveLowPassOut;
  CDEgoTurningState_t       * const peEgoCurrentTurnState = &(ACDC_p_ModEgoDrvScenario()->eEgoCurrentTurnState);
#if(CD_BLK_DIST_TURN_OPST_DIR)
  float32                 * const fDistBlockLeftTurn    = &(ACDC_p_ModEgoDrvScenario()->fDistBlockLeftTurn);
#endif

  /* Check the keep dependent curvature threshold */
  if (fEgoCrvLowPassOut > -fEgoCrvTurnKeepThre)
  {
    *peEgoCurrentTurnState = CD_EGO_TURNING_NO;
#if(CD_BLK_DIST_TURN_OPST_DIR)
    *fDistBlockLeftTurn   = CML_f_CalculatePolygonValue(CD_EGO_DRV_CRV_BLK_OPP_DIR_NO, CD_EGO_DRV_CRV_BLK_OPP_DIR, fLongVelocity);
#endif
  }
}

//! @} /* doxygen end of module /*
#endif /* (CD_USE_TURNINTOVRU_HYPOTHESIS)  */
#endif /* (ACDC_CFG_CD) */

