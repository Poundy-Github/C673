/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_main.c

DESCRIPTION:               Handles the main routine of CD

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 13:32:18CEST $

VERSION:                   $Revision: 1.41 $

LEGACY VERSION:            Revision: 1.89

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**

@defgroup cd_main Main
@ingroup cd
@brief          The CD Main module controls the information flow of the CD Subcomponent and provides 
                frame functions.\n\n
@description    The following functionalities are provided by cd_main:
                - **Main Calculation**: \n
                  The module handles the main process of @ref cd. This means it controls the sequence 
                  of function calls and the flow of information inside of the CD subcomponent. The 
                  responsible function for this is @ref CDRun.
                - **Object Resetting**: \n
                  In some cases objects are deleted outside of CD. For these cases CD has to provide a 
                  function to also delete the CD internal object. This is handled by the function 
                  @ref CDDeleteInternalObject.
                - ** The get functions of the Ego- and object movement, as well as the correspondingly needed static calculation functions
                  \n
                  @startuml CommonGetFunction_activity.png 
                  title Common Get Function
                  start
                  :Attribute A of Object O required;
                  if (A has been calculated before?) then (Yes)
                  :return A;
                  else(No)
                  #Orange:Calculate A >
                  :Write A to O;
                  :return A;
                  endif
                  stop
                  @enduml
@{
*/

/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

static void        CDPrepareCycle               (void);
static void        CDUpdateHypothesisHistory    (void); 
static void        CDInitObjectDataAtCycleBegin ( ObjNumber_t         const         iObjectIndex );
static void        CD_v_EgoBehaviorObserver     (void);


/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDPrepareCycle                                                                               */ /*!

  @brief                Initializes the hypothesis, the ego and the object data structures.

  @description          Initializes the hypothesis, the ego and the object data structures by calling the
                        functions @ref CDHypSelPrepareCycleHypothesesSelection and 
                        @ref CDInitObjectDataAtCycleBegin. \n
                        The function is called once at the beginning of each cycle.

  @return               void

  @glob_in              @ref ACDC_p_GetVehPar \n
                        @ref CD_a_GetInternalObjectList
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDPREPARECYCLE_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDPrepareCycle(void)
{
  ObjNumber_t                iObjectIndex;
  
  /************************************************************************/
  /* Init hypothesis data                                                 */
  /************************************************************************/
  CDHypSelPrepareCycleHypothesesSelection();

  /************************************************************************/
  /* Init object data                                                     */
  /************************************************************************/
  
  for(iObjectIndex=0; iObjectIndex < EM_N_OBJECTS; iObjectIndex++)
  {
    CDInitObjectDataAtCycleBegin(iObjectIndex);
  }
  /* CD_NEC_LONG_VIRTUAL_OBJ_DIST has to be greater than C_F32_DELTA. Ensure this here. */
  ACDC_ASSERT(CD_NEC_LONG_VIRTUAL_OBJ_DIST > C_F32_DELTA);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
}


/*************************************************************************************************************************
  Functionname:         CDRun                                                                                        */ /*!

  @brief                The function controls the sequence of function calls and the flow of information 
                        inside of the CD subcomponent. \n

  @description          The function is called by the ACDC main routine and calls all necessary functions 
                        of the CD component. The following diagram shows the processing steps and the called 
                        functions of CDRun.
                        @startuml CDRun_activity.png
                        start
                          #Orange: Initialization of variables and
                          several structures (e.g. Hypotheses List):
                          <b>CDPrepareCycle</b> >
                          #Orange: Calculate object related additional information
                          (e.g. [Dist/Vel][To/On]Traj, TTC, TTS, TTB):
                          <b>CDCalculateObjectProperties</b> >
                          #Orange: Run Ego Behavior Observer:
                          <b>CD_v_EgoBehaviorObserver</b> >
                          partition #LightBlue **ACDC_CFG_CALC_TRAJ_OCCUPANCY** {
                          #Orange:Calculate the trajectory occupancy:
                          <b>CD_v_CalculateTrajectoryOccupancy</b> >
                          #Orange:Calculate the TTC and TTB based on the trajectory occupancy:
                          <b>CD_v_TrajOccCalcCriticalities</b> >
                          }
                          partition #LightBlue **CD_USE_GENERIC_HYPOTHIS_HANDLER** {
                          #Orange: Generic hypothesis handling:
                          <b>CDGenHypothesisHandler</b> >
                          }
                          partition #LightBlue **!CD_USE_GENERIC_HYPOTHIS_HANDLER** {
                          #Orange: Custom hypothesis handling:
                          <b>CDCustomerHypothesisHandler</b> >
                          }
                          #Orange: Increase the lifetime of all found hypotheses:
                          <b>CDUpdateHypothesisHistory</b> >
                          #Orange: Sort hypotheses according to their relevance.
                          Select the 12 most relevant ones and discard the rest:
                          <b>CDFillHypothesesInterface</b> >
                          #Orange: Calculate customer specific functions:
                          <b>CDCalcCustomerFunctions</b> >
                        stop
                        @enduml

  @return              eGDBError_t : GDB_ERROR_NONE if no error occurred, otherwise returns the error.

  @glob_in             @ref ACDC_p_ModWorkingData
  @glob_out            @ref ACDC_p_ModWorkingData

  @c_switch_part       @ref ACDC_CFG_CALC_TRAJ_OCCUPANCY\n
                       @ref CD_USE_GENERIC_HYPOTHIS_HANDLER

  @c_switch_full       @ref ACDC_CFG_CD

  @pre                 @ref CDPreProcessing was called.
  @post                OutputData (=Hypotheses List) is filled.

  @InOutCorrelation    see description

  @author              robert.thiel@continental-corporation.com

  @testmethod           @ref TEST_CDRUN_001

  @traceability         Design Decision

*************************************************************************************************************************/
eGDBError_t CDRun(void)
{

  /* initialize the CD situation analysis variables each loop */
  CDPrepareCycle();

  /*----------------------------------------  calculate the CGEB relevant object properties  ----------------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_CALCULATE_OBJECT_PROP, 0); /* start profiling for CDCalculateObjectProperties */
  CDCalculateObjectProperties();
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_CALCULATE_OBJECT_PROP, 0);

  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_OBSERVE_EGO_BEHAVIOR, 0); /* start profiling for CDEgoBehaviorObserver */
  CD_v_EgoBehaviorObserver();/*PRQA S 2987*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Function call is not redundant and No side effects.*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_OBSERVE_EGO_BEHAVIOR, 0);

#if(ACDC_CFG_CALC_TRAJ_OCCUPANCY)
  /*----------------------------------------  Calculate the Trajectory Occupancy   ----------------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_TRAJOCCUPANCY_ACDC, 0);
  
  CD_v_CalculateTrajectoryOccupancy(&ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.TrajOccupancy);
  
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_TRAJOCCUPANCY_ACDC, 0); 

  /*-----------------------------------  Calculate TTX on base of the Trajectory Occupancy   -------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_TRAJOCCUPANCY_MEDIC, 0);
  
  CD_v_TrajOccCalcCriticalities(&(ACDC_p_GetWorkingData()->pInterCycle->sGlobData.CD.TrajOccupancy), 
                                &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.fTTC_TrajOcc),
                                &(ACDC_p_ModWorkingData()->pInterCycle->sGlobData.CD.fTTB_TrajOcc));
                                
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_TRAJOCCUPANCY_MEDIC, 0); 
  
#endif /*ACDC_CFG_CALC_TRAJ_OCCUPANCY*/

  /*----------------------------------------  tests hypothesis types for all relevant objects  ----------------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYPO_HANDLER, 0); /* start profiling for hypothesis handler */

#if CD_USE_GENERIC_HYPOTHIS_HANDLER
  CDGenHypothesisHandler();
#else
  CDCustomerHypothesisHandler();
#endif
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYPO_HANDLER, 0);

  /*----------------------------------------  update hypothesis history  ----------------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYPO_UPDATE, 0); /* start profiling for CDUpdateHypothesisHistory */
  CDUpdateHypothesisHistory();
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYPO_UPDATE, 0); 


  /*----------------------------------------  copy the most important hypotheses to outputs  ----------------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_SORT_HYPO, 0);
  CDHypSelFillHypothesesInterface();
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_SORT_HYPO, 0);


  /*----------------------------------------  calc customer specific functions  ----------------------------------------*/
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_CUSTOMER_FUNCTIONS, 0); /* start profiling for CDSortHypotheses */


  CDCalcCustomerFunctions();

  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_CUSTOMER_FUNCTIONS, 0);

  return GDB_ERROR_NONE;
}

/*************************************************************************************************************************
  Functionname:         CDUpdateHypothesisHistory                                                                    */ /*!

  @brief                Increases the hypothesis lifetime if the same hypothesis was set up in the last cycle.

  @description          The lifetime of a hypothesis is increased, if in the last cycle a hypothesis with
                        the same type was calculated on the same object as the current one.

  @return               void

  @param[in]            None

  @glob_in              @ref ACDC_f_GetCycleTime \n
                        @ref ACDC_p_GetPrevIntHypotheses\n
  @glob_out             @ref ACDC_p_ModCurrentIntHypotheses\n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  Hypothesis calculation has been executed
  @post                 None

  @InOutCorrelation     see description

  @author               Dominik Froehlich | dominik01.froehlich@continental-corporation.com

  @testmethod           @ref TEST_CDUPDATEHYPOTHESISHISTORY_001\n
                        @ref TEST_CDUPDATEHYPOTHESISHISTORY_002\n
  @traceability         Design Decision

*************************************************************************************************************************/
static void CDUpdateHypothesisHistory (void)
{
  uint8 uRelHypIndex;
  uint8 uPrevHypIndex;

  CDIntHypotheses_t       * const pIntHypothesisList  = ACDC_p_ModCurrentIntHypotheses();
  CDIntHypotheses_t const * const pPrevHypothesisList = ACDC_p_GetPrevIntHypotheses();

  for( uRelHypIndex = 0; uRelHypIndex < pIntHypothesisList->uNumOfHyps; uRelHypIndex++ )
  {
    CDIntHypothesis_t * const currentRelHypo = &(pIntHypothesisList->aHyp[uRelHypIndex]);

    for( uPrevHypIndex = 0; uPrevHypIndex < pPrevHypothesisList->uNumOfHyps; uPrevHypIndex++ )
    {
      CDIntHypothesis_t const * const currentPrevHypo = &(pPrevHypothesisList->aHyp[uPrevHypIndex]);

      if( ( currentRelHypo->eType == currentPrevHypo->eType )
          &&
          ( currentRelHypo->iObjectRef == currentPrevHypo->iObjectRef )
        )
      {
        currentRelHypo->fHypothesisLifetime = currentPrevHypo->fHypothesisLifetime + ACDC_f_GetCycleTime();
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:         CDDeleteInternalObject                                                                       */ /*!

  @brief                Deletes an CD Internal Object.

  @description          In case an object gets deleted outside of CD, the CD internal object also has to be deleted.
                        For these cases CD provides the external function CDDeleteInternalObject.
                        It initializes the local object data as soon as the object specific data that was stored
                        in certain hypotheses.
                        @startuml CDDeleteInternalObject_activity.png
                        start
                          #Orange:Initialize all data of the internal object:
                          <b>CDInitObjectDataAtCycleBegin</b> >
                          :Reset Track Assignment register and
                          Hypotheses history;
                          #Orange:Initialize all data stored in certain
                          hypotheses:
                          <b>CDHypoRunUpInitInternalData</b>
                          <b>CDHypoCrossingInitInternalData</b>
                          <b>CDHypoLongInitInternalData</b>
                          <b>CDHypoCutInInitInternalData</b>
                          <b>CDHypoDrvIntOncInitInternalData</b> >
                        stop
                        @enduml

  @return               void

  @param[in,out]        pLocalObject : Internal object that shall be deleted.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n
                        @ref ACDC_p_ModObjStaticEvasionData\n

  @c_switch_part        @ref CD_USE_RUN_UP_HYPOTHESIS \n
                        @ref CD_USE_CUT_IN_HYPOTHESIS \n
                        @ref CD_USE_CROSSING_HYPOTHESIS \n
                        @ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS \n
                        @ref CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 Object is initialized

  @InOutCorrelation     see description

  @author               robert.thiel@continental-corporation.com

  @testmethod           @ref TEST_CDDELETEINTERNALOBJECT_001

  @traceability         Design Decision

*************************************************************************************************************************/
void CDDeleteInternalObject (ObjNumber_t const iObjectIndex)
{
  CDObj_Hypothesis_t    * const pObjHypData    = ACDC_p_ModObjHypothesisData(iObjectIndex);
  CDObj_EvasionStatic_t * const pStaticEvasion = ACDC_p_ModObjStaticEvasionData(iObjectIndex);

  CDInitObjectDataAtCycleBegin( iObjectIndex );

  pStaticEvasion->TrackAssigned                 = 0u;                 /* Shifting Register for Track Assignment */
#if(CD_USE_TURNINTOVRU_HYPOTHESIS)
  pStaticEvasion->PSCCollProbHist               = 0u;                 /* Shifting Register for Collision Prediction */
#endif
#if (CD_USE_HIGH_QUALITY_LIFETIME)
  pStaticEvasion->fObjLifeCycleTimeHiQual       = 0.0f;
#endif
  pObjHypData->HypothesisHist.CutIn             = 0u;
  pObjHypData->HypothesisHist.Following         = 0u;
  pObjHypData->HypothesisHist.Pass              = 0u;
  pObjHypData->HypothesisHist.RunUpLong         = 0u;
  pObjHypData->HypothesisHist.RunUpMoving       = 0u;
  pObjHypData->HypothesisHist.RunUpStationary   = 0u;
  pObjHypData->HypothesisHist.WasOncomming      = 0u;
  pObjHypData->HypothesisHist.PedColl           = 0u;
  pObjHypData->HypothesisHist.CrossingLeft      = 0u;
  pObjHypData->HypothesisHist.CrossingRight     = 0u;
  pObjHypData->HypothesisHist.WasCrossing       = 0u;
  pObjHypData->HypothesisHist.BicycleColl       = 0u;
  pObjHypData->HypothesisHist.TurnIntoVRU       = 0u;
  pObjHypData->HypothesisHist.DriveIntoSloMo    = 0u;

  pObjHypData->bitHypPresel                     = 0x0u;

#if (CD_USE_RUN_UP_HYPOTHESIS)
  CDHypoRunUpInitInternalData(iObjectIndex, b_FALSE);
#endif

#if (CD_USE_CUT_IN_HYPOTHESIS)
  CDHypoCutInInitInternalData(iObjectIndex);
#endif /* CD_CUT_IN_CHECK_NBOR_OBJ_RUN_UP */

#if (CD_USE_CROSSING_HYPOTHESIS)
  CDHypCrossingInitInternalData(iObjectIndex);
#endif /* CD_USE_CROSSING_HYPOTHESIS */

#if (CD_USE_LONG_COLL_HYPOTHESIS)
  CDHypoLongCollInitInternalData(iObjectIndex);
#endif
/*PRQA S 3332 1*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Macro shall be defined in certain configurations(ONC), so keep this structure same in all configs*/
#if (CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION)
  // DrvIntoOncoming hypothesis for this object is maybe being destroyed here
  // initialize values to defaults for this iObjectIndex
  CDHypoDrvIntOncInitInternalData(iObjectIndex);
#endif/* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */

}

/*************************************************************************************************************************
  Functionname:         CD_s_GetEgoMov                                                                               */ /*!

  @brief                Returns a structure of the Ego Kinematics containing position and movement.
  
  @description          Transferes the current ego movement into a structure of the type @ref CDMovement_t.
                        If the switch CD_USE_POS_LONG_EGO_ACCEL is inactive, no positive ego accelerations are considered.

  @return               CDMovement_t : Ego Kinematics

  @param[in]            void

  @glob_in              @ref ACDC_p_GetEgoMovementRaw
  @glob_out             None

  @c_switch_part        @ref CD_USE_POS_LONG_EGO_ACCEL
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_S_GETEGOMOV_001

  @traceability         Design Decision

*************************************************************************************************************************/
CDMovement_t CD_s_GetEgoMov(void)
{  
  CDMovement_t CDEgoMovement;
  SFLMovement_t const * const pEgoMovementRaw = ACDC_p_GetEgoMovementRaw();

  CDEgoMovement.fX  = 0.f;
  CDEgoMovement.fY  = 0.f;
  CDEgoMovement.fVx = pEgoMovementRaw->Vel.fX;
  CDEgoMovement.fVy = pEgoMovementRaw->Vel.fY;
  CDEgoMovement.fAy = pEgoMovementRaw->Accel.fY;

#if CD_USE_POS_LONG_EGO_ACCEL
  CDEgoMovement.fAx = pEgoMovementRaw->Accel.fX;
#else
  CDEgoMovement.fAx = MIN_FLOAT( 0.f, pEgoMovementRaw->Accel.fX);
#endif

  return CDEgoMovement;
}

/*************************************************************************************************************************
  Functionname:         CD_s_GetObjMov                                                                               */ /*!

  @brief                Returns a structure of the Object Kinematics containing position and movement.
  
  @description          Transfers the objects movement and position into a structure of the type @ref CDMovement_t.
                        Therefore one of the objects positions and movements is selected according to the given enums.
                        The selected values are then written into the CDMovement_t structure.

  @return               CDMovement_t : Kinematic description of the object including position and movement.

  @param[in]            iObjectIndex :  Index of the object for which the information shall be returned. @range [0,+...[
  @param[in]            eObjPosition :  Enum describing which position shall be used for the returned structure. 
                                        For values see @ref ACDCObjPositions_e.
  @param[in]            eObjKinematics: Enum describing which kinematic shall be used for the returned structure. 
                                        For values see @ref ACDCObjKinematics_e.

  @glob_in              @ref ACDC_p_GetObjMovement\n
                        @ref ACDC_p_GetObjPositions
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_S_GETOBJMOV_001\n
                        @ref TEST_CD_S_GETOBJMOV_002\n
						@ref TEST_CD_S_GETOBJMOV_003\n
						@ref TEST_CD_S_GETOBJMOV_004\n
						@ref TEST_CD_S_GETOBJMOV_005\n
						@ref TEST_CD_S_GETOBJMOV_006\n

  @traceability         Design Decision

*************************************************************************************************************************/
CDMovement_t CD_s_GetObjMov( ObjNumber_t         const iObjectIndex,
                             ACDCObjPositions_e  const eObjPosition,
                             ACDCObjKinematics_e const eObjKinematics)
{
  CDMovement_t                      ObjectMovement;
  ACDCObjMovement_t   const * const pCurrObjKin = ACDC_p_GetObjMovement(iObjectIndex);
  ACDCObjPositions_t  const * const pCurrObjPos = ACDC_p_GetObjPositions(iObjectIndex);
  SFLMovement_t                     Movement    = {0};
  SFLVector2D_t                     Position    = {0};

  /* Select the Position which shall be used */
  switch (eObjPosition)
  {
  case POS_CENTER:
    Position = pCurrObjPos->Center;
    break;
  case POS_CLOSEST_IN_X:
    Position = pCurrObjPos->ClosestInX;
    break;
  case POS_CLOSEST_IN_CORR:
    Position = pCurrObjPos->ClosestInCorr;
    break;
  case POS_VAR:
    Position = pCurrObjPos->Var;
    break;
  case POS_GEN_OBJECT:
    Position = pCurrObjPos->GenObject;
    break;
  default:
    ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
    Position = pCurrObjPos->GenObject;
    break;
  }

  /* Select the kinematics which shall be used */
  switch (eObjKinematics)
  {
    case KIN_ABS:
      Movement = pCurrObjKin->Abs;
      break;
    case KIN_REL:
      Movement = pCurrObjKin->Rel;
      break;
    case KIN_VAR:
      Movement = pCurrObjKin->Var;
      break;
    default:
      ACDC_ASSERT(FALSE);
      Movement = pCurrObjKin->Abs;
      break;
  }

  ObjectMovement.fAx = Movement.Accel.fX;
  ObjectMovement.fAy = Movement.Accel.fY;
  ObjectMovement.fVx = Movement.Vel.fX;
  ObjectMovement.fVy = Movement.Vel.fY;
  ObjectMovement.fX  = Position.fX;
  ObjectMovement.fY  = Position.fY;

  return ObjectMovement;
}

/*************************************************************************************************************************
  Functionname:         CDInitObjectDataAtCycleBegin                                                                 */ /*!

  @brief                Initializes all data of one object.

  @description          Initializes all data of one object stored in the format of the structure \ref CDInternalObject_t.
                        Resets also all data related to the object that is stored for the PSC calculation(\ref cd_calculatepsc).
                        It is called at the cycle begin or if a object gets deleted.
                        @startuml CDInitObjectDataAtCycleBegin_activity.png
                        start
                         :Set all objects attributes 
                         to specific inital values;
                         #Orange:Reset objects PSC data
                         <b>CDPSCInit</b> >
                        stop
                        @enduml

  @return               void

  @param[in,out]        iObjectIndex : object identifier

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjEvasionData\n
                        @ref ACDC_p_ModObjTTXData\n

  @c_switch_part        @ref CD_USE_TTM_LONG\n 
                        @ref CD_USE_BRAKE_JERK_TTC\n 
                        @ref CD_USE_GEN_PSC
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 Object initialized

  @InOutCorrelation     see description

  @author               Gergely Ungvery

  @testmethod           @ref TEST_CDINITOBJECTDATAATCYCLEBEGIN_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDInitObjectDataAtCycleBegin( ObjNumber_t const iObjectIndex )
{
  CDObj_Evasion_t   * const pEvasion = ACDC_p_ModObjEvasionData(iObjectIndex);
  CDObj_TTX_t       * const pTTX     = ACDC_p_ModObjTTXData(iObjectIndex);

  pTTX->TTC                              = CD_TTC_INIT;                  /* Time to collision (assuming that the vehicle is in course) w/ accelerations */
  pTTX->TTC2                             = CD_TTC_INIT;                  /* Time to collision 2 (assuming that the vehicle is in course) w/o object acceleration */
  pTTX->TTC3                             = CD_TTC_INIT;                  /* Time to collision 3 (assuming that the vehicle is in course w/o accelerations */
  pTTX->TTC4                             = CD_TTC_INIT;                  /* Time to collision 4 (assuming that the vehicle is in course w/o accelerations, object velocity */
#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
  pTTX->TTMLongPre                       = CD_TTM_INIT;                  /* Time to do nothing before comfort action to avoid a collision in 2D scenario */
  pTTX->TTMLongAcute                     = CD_TTM_INIT;                  /* Time to do nothing before emergency action to avoid  a collision in 2D scenario */
#endif /* CD_USE_TTM_LONG */
  pTTX->TTBAcute                         = CD_TTBDYN_INIT;               /* time to brake for emergency braking */
  pTTX->TTSPre                           = CD_TTSPRE_INIT;               /* time to steer for comfort steering*/ 
  pTTX->TTSAcute                         = CD_TTSACUTE_INIT;             /* time to steer for emergency steering*/
  pTTX->TTSPreRight                      = CD_TTSPRE_INIT;               /* time to steer for comfort steering right */
  pTTX->TTSPreLeft                       = CD_TTSPRE_INIT;               /* time to steer for comfort steering left */
  pTTX->TTSAcuteRight                    = CD_TTSACUTE_INIT;             /* time to steer for emergency steering right*/
  pTTX->TTSAcuteLeft                     = CD_TTSACUTE_INIT;             /* time to steer for emergency steering left */
  pTTX->TTBPre                           = CD_TTBDYN_INIT;               /* time to brake for comfort braking */
#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
  pTTX->sBrakeJerk.fTTCBrakeJerk         = CD_TTCBRAKEJERK_INIT;         /* Time to collision assuming a brake jerk */
  pTTX->sBrakeJerk.fTTCBrakeJerkFactor   = CD_TTCBRAKEJERKFACTOR_INIT;   /* Hypothesis reduction factor based on the calculated TTCBrakeJerk */
#endif /* CD_USE_BRAKE_JERK_TTC */
  pEvasion->LongNecAccel                 = CD_LONGNECACCEL_INIT;         /* Necessary longitudinal acceleration to avoid a collision */
  pEvasion->LatNecAccelRight             = CD_LATNECACCEL_INIT;          /* Necessary lateral acceleration to right side to avoid a collision*/
  pEvasion->LatNecAccelLeft              = CD_LATNECACCEL_INIT;          /* Necessary lateral acceleration to left side to avoid a collision */
  pEvasion->LatNecAccel                  = CD_LATNECACCEL_INIT;          /* Necessary lateral acceleration to avoid a collision */
  pEvasion->ClosingVelocity              = CD_CLOSINGVELOCITY_INIT;      /* Relative speed at time of collision (not AUTOSAR) */
#if (ACDC_CFG_TURN_ASSIST)
  pEvasion->fCorridorStopDistance        = CD_CORRIDORSTOPDIST_INIT;
#endif /* #if (ACDC_CFG_TURN_ASSIST) */

  /* Init PSC module */
#if(CD_USE_GEN_PSC)
  CDPSCInit(iObjectIndex);
#endif
}


/*************************************************************************************************************************
  Functionname:         CD_v_EgoBehaviorObserver                                                                        */ /*!

  @brief                Ego behavior observers

  @description          In this function the ego behavior observation is done:
                          - Evaluate/classify whether the ego is turning by calling the function @ref CDEgoTurningEval.

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref CD_USE_TURNINTOVRU_HYPOTHESIS
  @c_switch_full        @ref ACDC_CFG_CD\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248

  @testmethod           @ref TEST_CD_V_EGOBEHAVIOROBSERVER_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CD_v_EgoBehaviorObserver(void)
{
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  /* execute the state machine of the ego-vehicle turning maneuver detection */
  CDEgoTurningEval();
#endif
}
/*! @} */
#endif  /* #if (ACDC_CFG_CD) */
/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

