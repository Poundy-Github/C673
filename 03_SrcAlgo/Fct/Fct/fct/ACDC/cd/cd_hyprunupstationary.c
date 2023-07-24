/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hyprunupstationary.c

DESCRIPTION:               Implementation of the stationary hypothesis

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/09/08 12:01:19CEST $

VERSION:                   $Revision: 1.41 $ 

LEGACY VERSION:            Revision: 2.7

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_RUN_UP_STAT_HYPOTHESIS)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hyprunupstationary HypRunUpStationary
@ingroup cd
@brief The Run Up Stationary Hypothesis describes a scenario in which the ego vehicle is closing up to a stationary object.\n\n

The only extern function of the module is: @ref CDHypoRunUpStationaryMain \n
Additionally the module contains a function to calculate the hypothesis' object filter (@ref CDHypoRunUpStationaryFilter) 
and probability (@ref CDCalculateProbRunUpStationaryHypo)
@{

*/
/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*! @brief       Local identifier for right lane*/
#define CD_RUN_UP_STAT_RIGHT_LANE     (1u)

/*! @brief       Local identifier for left lane*/
#define CD_RUN_UP_STAT_LEFT_LANE      (2u)

/*! @brief       Number of sampling points for run up hypothesis probability*/
#define CD_RUN_UP_STAT_HYP_PROB_NO_POINTS  (9u)

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CDHypoRunUpStationaryFilter (ObjNumber_t const iObjectIndex);
#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
static boolean CDCheckStationaryObjectRelations   (ObjNumber_t const iObjectIndex);
#endif
static void CDCalculateProbRunUpStationaryHypo (CDIntHypothesis_t *const pHypothesis, ObjNumber_t const iObjectIndex);
static void CDHypRelationsRunUpStationaryHypo  (void);

/*************************************************************************************************************************
  Functionname:         CDHypoRunUpStationaryFilter                                                                  */ /*!

  @brief                Checks if the object is relevant for the run up stationary hypothesis

  @description          To pass the hypothesis' Object Filter, the object has to fulfill the following criteria: 
                        - The Objects TTC, TTB and TTS need to be below certain thresholds.
                        - The Object has been track assigned for at least @ref CD_RUN_UP_MIN_TRACK_ASSIGNED cycles.
                        - The Objects distance has to be above a certain threshold or it has been part of a previous RunUp or CutIn Hypothesis.
                        @startuml CDHypoRunUpStationaryFilter_activity.png
                        start
                          if(Object was Track assigned for a minimum number of cycles?
                            AND Object is above a certain X-Distance (...)?
                            AND Objects TTS is below a threshold (...)?) then (Yes)
                            note left: For detailed criteria\nsee description above
                            :1}
                            :Object passes filter;
                          else(No)
                            :2}
                            :Object does not pass filter;
                          endif
                        stop
                        @enduml
  @return               boolean : True if the object is relevant

  @param[in]            iObjectIndex : Index of the considered object. @range [0,+...[
  @param[in]            *pLocalObject : CD internal object information.

  @glob_in              @ref ACDC_p_GetObjPositions\n
                        @ref CD_f_GetLongNecAccel \n
                        @ref CD_f_GetTTC4 \n
                        @ref CD_f_GetTTSPreLeft \n
                        @ref CD_f_GetTTSPreRight \n
                        @ref ACDC_p_GetEMGenObjAttributes\n
                        @ref ACDC_p_GetObjHypothesisData\n
                        @ref ACDC_p_GetObjStaticEvasionData\n
  @glob_out             None

  @c_switch_part        @ref CD_SUPPRESS_CROSSING_STOPPED_OBJECTS
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_STAT_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Hartmann | andreas.hartmann@continental-corporation.com

  @testmethod           @ref TEST_CDHYPORUNUPSTATIONARYFILTER_001 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYFILTER_002 \n
						@ref TEST_CDHYPORUNUPSTATIONARYFILTER_003 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYFILTER_004 \n
						@ref TEST_CDHYPORUNUPSTATIONARYFILTER_005 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYFILTER_006 \n
						@ref TEST_CDHYPORUNUPSTATIONARYFILTER_007 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYFILTER_008 \n
						@ref TEST_CDHYPORUNUPSTATIONARYFILTER_009 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYFILTER_010 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoRunUpStationaryFilter (ObjNumber_t const   iObjectIndex)
{
  boolean bReturn;
  const float32 fObjDistX     = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
  const float32 fLongNecAccel = CD_f_GetLongNecAccel(iObjectIndex);
  const float32 fTTC4         = CD_f_GetTTC4(iObjectIndex);
  const float32 fTTSPreLeft   = CD_f_GetTTSPreLeft(iObjectIndex);
  const float32 fTTSPreRight  = CD_f_GetTTSPreRight(iObjectIndex);
  CDObj_Hypothesis_t    const * const pObjHypData   = ACDC_p_GetObjHypothesisData(iObjectIndex);
  CDObj_EvasionStatic_t const * const pEvasion      = ACDC_p_GetObjStaticEvasionData(iObjectIndex);

#if ((defined CD_SUPPRESS_CROSSING_STOPPED_OBJECTS)&&(CD_SUPPRESS_CROSSING_STOPPED_OBJECTS == SWITCH_ON))
  const boolean isStoppedAndWasCrossing = (boolean)
    (   (    ( ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eDynamicProperty == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)
          && ( pObjHypData->HypothesisHist.WasCrossing                     == TRUE                                                          ) ) );
#endif

  if (
#if ((defined CD_SUPPRESS_CROSSING_STOPPED_OBJECTS)&&(CD_SUPPRESS_CROSSING_STOPPED_OBJECTS == SWITCH_ON))
          // If the Object was Crossing and is now Stopped, it is NOT relevant for the RunUpStationary Hypothesis
          (               isStoppedAndWasCrossing                      != TRUE                                    )
       &&
#endif
          (    (          fTTSPreLeft                                              <  CD_RUN_UP_STAT_MAX_TTS                )
            || (          fTTSPreRight                                             <  CD_RUN_UP_STAT_MAX_TTS                )
            || (    (    (fLongNecAccel                                            <  0.0f                              )
                      || (fTTC4                                                    <  CD_COMMON_TTC_THRES               ) )
                 && (     pObjHypData->HypothesisHist.RunUpStationary             == (ubit16_t)1u                                    ) ) )
       && (               pEvasion->TrackAssigned                                  > (uint8)CD_RUN_UP_MIN_TRACK_ASSIGNED      )
       && (    (          fObjDistX                                                > CD_COMMON_MIN_DISTX                    )
            || (          pObjHypData->HypothesisHist.RunUpMoving                 == (ubit16_t)1u                                      )
            || (          pObjHypData->HypothesisHist.RunUpStationary             == (ubit16_t)1u                                      )
            || (          pObjHypData->HypothesisHist.CutIn                       == (ubit16_t)1u                                      ) )
#if CD_RUN_UP_STAT_SUPPRESS_BICYCLES
       && (               ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->eEbaObjClass != FPS_EBA_CLASS_CYCLIST                   ) 
#endif
                                                                                                                                )
  {
    bReturn = b_TRUE;
  }
  else
  {    
    bReturn  = b_FALSE;
  }

  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDCalculateProbRunUpStationaryHypo                                                           */ /*!

  @brief                (Describe in few words the purpose of the function.)

  @description          The probability for the Run Up Stationary hypothesis depends on the number of cycles that an object has 
                        been assigned to the ego track. The information about the track assignment is stored in a 8-Bit shifting \n
                        register (Calculation in @ref CDAssignTrack). E.g. a value of 224 (binary: 1110 0000) means, that the 
                        object was track assigned for the last 3 cycles. The hypothesis probability increases according to a table.\n
                        It reaches 100 % for 8 cycles of track assignment. \n

  @return               static void

  @param[in,out]        pHypothesis :   Hypothesis for which the probability shall be calculated
  @param[in]            iObjectIndex :  object identifier

  @glob_in              @ref ACDC_p_GetObjStaticEvasionData\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_STAT_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     |Number of Track assigned cycles|      0|      1|      2|      3|      4|      5|      6|      7|      8|
                        |:------------------------------|:------|:------|:------|:------|:------|:------|:------|:------|:------|
                        |        Probability            |      0|   0.25|    0.5|   0.57|    0.6|   0.61|   0.62|   0.63|    1.0|

  @author               Andreas Hartmann | andreas.hartmann@continental-corporation.com)

  @testmethod           @ref TEST_CDCALCULATEPROBRUNUPSTATIONARYHYPO_001\n
                        @ref TEST_CDCALCULATEPROBRUNUPSTATIONARYHYPO_002\n
                        @ref TEST_CDCALCULATEPROBRUNUPSTATIONARYHYPO_003

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDCalculateProbRunUpStationaryHypo (CDIntHypothesis_t        *const pHypothesis,
                                                ObjNumber_t               const iObjectIndex)
{
  uint8 uiTrackMask;
  uint8 uiTrackHist;
  CDObj_EvasionStatic_t const * const pEvasion = ACDC_p_GetObjStaticEvasionData(iObjectIndex);
  static const float32 fCDRunUpStatHypProb[CD_RUN_UP_STAT_HYP_PROB_NO_POINTS] = {0.0f, 0.25f, 0.5f, 0.57f, 0.6f, 0.61f, 0.62f, 0.63f, 1.0f };

  /* search first zero bit */
  uiTrackMask = 128u;
  uiTrackHist = 0u;
  /*while loop will terminate after 8th shift*/
  while( ( pEvasion->TrackAssigned & uiTrackMask ) != 0u )
  {
    uiTrackMask = uiTrackMask >> 1;
    uiTrackHist++;
  }
  /* uiTrackHist is the (zero based) number of the first 0 bit; if no bit is zero uiTrackHist is 8 */

  pHypothesis->fHypothesisProbability     = fCDRunUpStatHypProb[ uiTrackHist ];

  /* done */
  return;
}

#if (!CD_USE_CUSTOM_HYPOTHESIS_RUNUPSTATIONARY)
/*************************************************************************************************************************
  Functionname:         CDHypoRunUpStationaryMain                                                                    */ /*!

  @brief                Handles the main processing steps of the run up stationary hypothesis. \n\n

  @description          Handles the run up stationary hypothesis by executing the three common steps for a hypothesis 
                        generation (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CDHypoRunUpStationaryFilter
                        2. Call of the Hypothesis probability calculation: @ref CDCalculateProbRunUpStationaryHypo
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the three main steps that are described in the diagram
                        can be found in the description of the @ref cd_hyphandler.
                        @image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0,+...[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history (if exists).
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref EM_GEN_OBJECT_INTFVER \n
                        @ref CD_USE_EM_FPS_OBJCLASS
  @c_switch_full        @ref CD_USE_CUSTOM_HYPOTHESIS_RUNUPSTATIONARY \n
                        @ref ACDC_CFG_CD \n
                        @ref CD_USE_RUN_UP_STAT_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Hartmann | andreas.hartmann@continental-corporation.com

  @testmethod           @ref TEST_CDHYPORUNUPSTATIONARYMAIN_001 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYMAIN_002 \n
                        @ref TEST_CDHYPORUNUPSTATIONARYMAIN_003

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoRunUpStationaryMain(ObjNumber_t const   iObjectIndex,
                               boolean     const   bObjFilterMatched)
{
  CDIntHypothesis_t          Hypothesis;
  CDObj_Hypothesis_t * const pObjHypData         = ACDC_p_ModObjHypothesisData(iObjectIndex);
#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
  boolean                    bObjValidForStatHyp = TRUE;
#endif

  pObjHypData->sHypRunUpStatData.bObstacleAtLeft = b_FALSE;
  pObjHypData->sHypRunUpStatData.bObstacleAtRight = b_FALSE;

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_RunUpStationary);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_RunUpStationary);

  /* handle only hypothesis relevant objects */
  if( bObjFilterMatched != b_FALSE )
  {
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_RUNUP_STAT_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoRunUpStationaryFilter(iObjectIndex) != b_FALSE )
    {
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_RunUpStationary);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_RunUpStationary);

      /* calculate Hypothesis probability */
      CDCalculateProbRunUpStationaryHypo(&Hypothesis, iObjectIndex);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > 0.0f)
      {
#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
        bObjValidForStatHyp = CDCheckStationaryObjectRelations(iObjectIndex);

        if (bObjValidForStatHyp == FALSE)
        {
          Hypothesis.fHypothesisProbability = CML_Max(Hypothesis.fHypothesisProbability - (0.1f * ((float32)pObjHypData->sHypRunUpStatData.iObjInvalidCnt)), 0.f);
        }
#endif

        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_RunUpStationary);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.RunUpStationary = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.RunUpStationary = 0u;
        CDHypoRunUpStatInitInternalData(iObjectIndex);
      }
    }
    else
    {
      pObjHypData->HypothesisHist.RunUpStationary = 0u;
      CDHypoRunUpStatInitInternalData(iObjectIndex);
    }
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_RUNUP_STAT_SINGLE, (uint8)(iObjectIndex));
  }
  /* <ln_offset:+1 PCLINT Error 715: reviewer name: Dominik Froehlich date: 19-03-2011 reason: an improved algo could use the argument. Keep for generality. */
}
#endif /* #if (!CD_USE_CUSTOM_HYPOTHESIS_RUNUPSTATIONARY) */

#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
/*************************************************************************************************************************
  Functionname:         CDCheckStationaryObjectRelations                                                            */ /*!
                        
  @brief                Checks the relations between stationary objects by searching for chains of stationary objects. 
                        
  @description          Checks the relations between stationary objects by searching for chains of stationary objects. 
                        The idea is to search forward and backward with respect to the longitudinal position of the given object.\n
                        The initial search gates are determined by the position of the given object. If a new object has been 
                        found the search gates for a new object are determined by that found object.\n
                        \n
                        1. Loop over all objects to search the index of the relevant (given) object in the sorted object list
                        2. Loop backward with respect to the longitudinal position and search for objects that approximately have 
                           the same distance to trajectory as the given object and are within the specified longitudinal gates.
                        3. Loop forward with respect to the longitudinal position and perform the same as in 2.
                        4. If more than CD_STAT_OBJ_CHAIN_DET_MIN_NOF_OBJS objects have been found increase the variable iObjInvalidCnt
                        5. If the counter iObjInvalidCnt is greater than zero, the object shall not be marked as valid for run up stationary hypothesis
                        The following steps are executed:
                        @startuml CDCheckStationaryObjectRelations_activity.png
                          start
                            :Calculate X gate based on ego velocity;
                            if (Are we not driving in a narrow curve?
                                AND The given object is not confirmed by camera?
                                AND The given object is not directly in front of us?) then (Yes)
                              :Loop over all objects to determine
                              the position of the given object in
                              the sorted object list;
                              :Set the search gates based on the
                              position of the given object;
                              note left: >see formula "search gates"
                              :Loop <b>backward</b> using the sorted object list with 
                              respect to longitudinal position of the given object;
                              while (Stationary object found inside longitudinal gates) is (Yes)
                                if (Stationary object inside dist2traj gates?) then (Yes)
                                  :1}
                                  :Update search gates based on the X pos and dist2traj 
                                  of the found object (for dist2traj the standard processing
                                  gate is used);
                                  note left: >see formula "search gates"
                                  :Increase iObjCount;
                                else(No)
                                  :2}
                                endif
                                :Select next object;
                              endwhile(No)
                              :Set the search gates based on the
                              position of the given object;
                              note left: >see formula "search gates"
                              :Loop <b>forward</b> using the sorted object list with
                              respect to longitudinal position of the given object;
                              while (Stationary object found inside longitudinal gates) is (Yes)
                                if (Stationary object inside dist2traj gates) then (Yes)
                                  :3}
                                  :Update search gates based on the X pos and dist2traj 
                                  of the found object (for dist2traj the standard processing
                                  gate is used);
                                  note left: >see formula "search gates"
                                  :Increase iObjCount;
                                else(No)
                                  :4}
                                endif
                                :Select next object;
                              endwhile(No)
                            else(No)
                              :5}
                            endif
                            if (iObjCount >= CD_STAT_OBJ_CHAIN_DET_MIN_NOF_OBJS) then (Yes)
                              if (RunUpStat hypothesis was not active in the last cycle) then (Yes)
                                :6}
                                :Set iObjInvalidCnt to the init value \nCD_STAT_OBJ_CHAIN_DET_INIT_CNT;
                              else(No)
                                :7}
                                :Increase iObjInvalidCnt to a maximum of \nCD_STAT_OBJ_CHAIN_DET_MAX_CNT;
                              endif
                            else(No)
                              :8}
                              :Decrement iObjInvalidCnt;
                            endif
                            if (iObjInvalidCnt > 0) then (Yes)
                              :9}
                              :Mark the object as invalid for \nRunUpStat hypothesis;
                            else(No)
                              :10}
                            endif
                          stop
                        @enduml
                        
  @return               boolean bObjValidForStatHyp: Indicating if the object is valid for a run up stationary hypothesis
                        
  @param[in]            iObjectIndex : Index of the object for which a run up stationary hypothesis shall be activated
  @param[in]            *pObjectData : Pointer to the internal static object data
                        
  @glob_in              @ref ACDC_f_GetEgoVelObjSync\n
                        @ref ACDC_p_GetObjTrajRelation \n
                        ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve : Current ego vehicle curvature from VDY\n
                        ACDC_p_GetObjPositions : Longitudinal x distance of the object\n
                        ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eDynamicProperty : Dynamic property of the object\n
                        ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->uiProbabilityOfExistence : Probability of existence of the object\n
                        CD_e_GetSensorSource(iObjectIndex) : Sensors by which this object has been measured\n
                        @ref CD_a_GetInternalObjectList\n
                        pCurrObject->TrajRelation.fDistToTraj : Distance to trajectory of the object\n
                        pCurrObject->HypothesisHist.RunUpStationary : Hypothesis history of the object\n
                        pCurrObject->sHypRunUpStatData : Internal run up stationary static data of the object\n
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref ACDC_SIMU
  @c_switch_full        @ref CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formulas:**\n
                        \f$\text{Dist2TrajGate}_{\text{min}} = \text{Dist2Traj} - \text{Dist2TrajGate}_{\text{init}} \f$\n
                        \f$\text{Dist2TrajGate}_{\text{max}} = \text{Dist2Traj} + \text{Dist2TrajGate}_{\text{init}} \f$\n
                        \f$x_\text{LimitLower}               = x_{\text{Obj}} - x_{\text{VelocityGate}} \f$\n
                        \f$x_\text{LimitUpper}               = x_{\text{Obj}} + x_{\text{VelocityGate}} \f$\n
                        \f$x_{\text{VelocityGate}}           = \begin{cases}\text{CD_STAT_OBJ_CHAIN_DET_MIN_X_GATE},& \text{for } v_\text{Ego} < \text{CD_STAT_OBJ_CHAIN_DET_VEL_MIN_X_GATE}\frac{\text{m}}{\text{s}} \\ y = \frac{\Delta x_\text{Gate}}{\Delta v_\text{Gate}}m \cdot v_{\text{Ego}} + 4\frac{\text{m}}{\text{s}} ,& \text{for } \text{CD_STAT_OBJ_CHAIN_DET_VEL_MIN_X_GATE}\frac{\text{m}}{\text{s}} \leq v_{\text{Ego}} \leq \text{CD_STAT_OBJ_CHAIN_DET_VEL_MAX_X_GATE}\frac{\text{m}}{\text{s}} \\ \text{CD_STAT_OBJ_CHAIN_DET_MAX_X_GATE},& \text{for } v_\text{Ego} > \text{CD_STAT_OBJ_CHAIN_DET_VEL_MAX_X_GATE}\frac{\text{m}}{\text{s}}\end{cases} \f$

  @author               David Stenmanns | david.stenmanns@continental-corporation.com | +49 (8382) 9699-553

  @testmethod           @ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_001 \n
                        @ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_002 \n
                        @ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_003 \n
                        @ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_004 \n
						@ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_005 \n
						@ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_006 \n
						@ref TEST_CDCHECKSTATIONARYOBJECTRELATIONS_007 \n
						
  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCheckStationaryObjectRelations(ObjNumber_t const iObjectIndex)
{
  ACDCObjToTrajRelation_t const * const pTrajRelation = ACDC_p_GetObjTrajRelation(iObjectIndex);
  CDObj_Hypothesis_t            * const pObjHypData   = ACDC_p_ModObjHypothesisData(iObjectIndex);
  const float32     fXEgoVelocityGate = CML_f_BoundedLinInterpol2(ACDC_f_GetEgoVelObjSync(), CD_STAT_OBJ_CHAIN_DET_VEL_MIN_X_GATE, CD_STAT_OBJ_CHAIN_DET_VEL_MAX_X_GATE, CD_STAT_OBJ_CHAIN_DET_MIN_X_GATE, CD_STAT_OBJ_CHAIN_DET_MAX_X_GATE);
  const float32     fEgoCurveAbs      = fABS(ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve);
        float32     fXUpperLimit;
        float32     fXLowerLimit;
        float32     fDist2TrajGateMin;
        float32     fDist2TrajGateMax;
        float32     fDist2TrajStatObj;
        float32     fXObj;
        sint32      iObjCount            = 0;
        ObjNumber_t iObjIndexSortedStore = 0;
        ObjNumber_t iObjIndexSorted;
        ObjNumber_t iObj;
        boolean     bObjValidForStatHyp  = TRUE;
        boolean     bAbortLoop           = FALSE;

#ifdef ACDC_SIMU
  for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
  {
    ACDC_p_ModSimuData()->sObjData.aObj[iObj].CD.sHypRunupStatDebug.aiStatObjChainID[iObj] = OBJ_INDEX_NO_OBJECT;

  }
#endif

  if (    (CML_GetBit(CD_e_GetSensorSource(iObjectIndex), EM_GEN_OBJECT_MS_CAM)   == FALSE                              )
       && (fABS(pTrajRelation->fDistToTraj)                                        > CD_STAT_OBJ_CHAIN_DET_MIN_DIST2TRAJ)
       && (fEgoCurveAbs                                                           <  CD_STAT_OBJ_CHAIN_MIN_CURVE_RAD    ) )
  {
    /* Loop over all objects to search the index of the relevant object in the sorted object list */
    for (iObj = 0; (iObj < EM_N_OBJECTS) && (bAbortLoop == FALSE); iObj++)
    {
      iObjIndexSorted = ACDC_p_GetEMGenObjList()->HeaderObjList.iSortedObjectList[iObj];

      if (iObjIndexSorted == iObjectIndex)
      {
        /* Store the index in variable iObjIndexSortedStore */
        iObjIndexSortedStore = iObj;
        bAbortLoop           = TRUE;
      }
    }

    bAbortLoop        = FALSE;
    fXLowerLimit      = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX - fXEgoVelocityGate;
    fDist2TrajGateMin = pTrajRelation->fDistToTraj - CD_STAT_OBJ_CHAIN_DET_INIT_GATE;
    fDist2TrajGateMax = pTrajRelation->fDistToTraj + CD_STAT_OBJ_CHAIN_DET_INIT_GATE;

    /* Check that the stored object index is not the first element in the list (object closest to the subject vehicle) */
    if (iObjIndexSortedStore > 0)
    {
      /* Loop backward with respect to the longitudinal position */
      for (iObj = iObjIndexSortedStore - 1; (iObj >= 0) && (bAbortLoop == FALSE); iObj--)
      {
        iObjIndexSorted = ACDC_p_GetEMGenObjList()->HeaderObjList.iSortedObjectList[iObj];

        if (    (iObjIndexSorted                                                           != OBJ_INDEX_NO_OBJECT                                              )
             && (ACDC_p_GetEMGenObjAttributes(iObjIndexSorted)->eDynamicProperty           == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
             && (ACDC_p_GetEMGenObjQualifiers(iObjIndexSorted)->uiProbabilityOfExistence    > CD_STAT_OBJ_CHAIN_DET_MIN_STAT_POE                               ) )
        {
          fXObj = ACDC_p_GetObjPositions(iObjIndexSorted)->GenObject.fX;

          /* Only continue if the longitudinal position of the object is greater than the lower limit */
          if (fXObj > fXLowerLimit)
          {
            /* Get the distance to trajectory of the current stationary object */

            fDist2TrajStatObj = ACDC_p_GetObjTrajRelation(iObjIndexSorted)->fDistToTraj;
       
            /* Check if there is an overlap between the relevant and the current stationary object */
            if (    (fDist2TrajStatObj <  fDist2TrajGateMax)
                 && (fDist2TrajStatObj  > fDist2TrajGateMin) )
            {
              /* Set the new lower limit for the x position based on the current stationary object */
              fXLowerLimit = fXObj - fXEgoVelocityGate;
              /* Update the distance to trajectory gates gates */
              fDist2TrajGateMin = fDist2TrajStatObj - CD_STAT_OBJ_CHAIN_DET_PROC_GATE;
              fDist2TrajGateMax = fDist2TrajStatObj + CD_STAT_OBJ_CHAIN_DET_PROC_GATE;
#ifdef ACDC_SIMU
              /* In simulation store the ID of each object found in the chain */
              ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sHypRunupStatDebug.aiStatObjChainID[iObjCount]  = iObjIndexSorted;
#endif
              /* If both objects overlap increase the object counter */
              iObjCount++;
            }
          }
          else
          {
            bAbortLoop = TRUE;
          }
        }
      }
    }

    bAbortLoop        = FALSE;
    fXUpperLimit      = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX + fXEgoVelocityGate;
    fDist2TrajGateMin = pTrajRelation->fDistToTraj - CD_STAT_OBJ_CHAIN_DET_INIT_GATE;
    fDist2TrajGateMax = pTrajRelation->fDistToTraj + CD_STAT_OBJ_CHAIN_DET_INIT_GATE;

    /* Check that the stored object index is not the last element in the list (object furthest away to the subject vehicle) */
    if (iObjIndexSortedStore < (EM_N_OBJECTS - 1))
    {
      /* Loop forward with respect to the longitudinal position */
      for (iObj = (iObjIndexSortedStore + 1); (iObj < EM_N_OBJECTS) && (bAbortLoop == FALSE); iObj++)
      {
        iObjIndexSorted = ACDC_p_GetEMGenObjList()->HeaderObjList.iSortedObjectList[iObj];

        if (    (iObjIndexSorted                                                           != OBJ_INDEX_NO_OBJECT                                              )
             && (ACDC_p_GetEMGenObjAttributes(iObjIndexSorted)->eDynamicProperty           == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
             && (ACDC_p_GetEMGenObjQualifiers(iObjIndexSorted)->uiProbabilityOfExistence    > CD_STAT_OBJ_CHAIN_DET_MIN_STAT_POE                               ) )
        {
          fXObj = ACDC_p_GetObjPositions(iObjIndexSorted)->GenObject.fX;

          /* If the longitudinal position of the object exceeds the upper limit abort the whole loop, otherwise continue */
          if (fXObj < fXUpperLimit)
          {
            /* Get the distance to trajectory of the current stationary object */
            fDist2TrajStatObj = ACDC_p_GetObjTrajRelation(iObjIndexSorted)->fDistToTraj;

            /* Check if there is an overlap between the relevant and the current stationary object */
            if (    (fDist2TrajStatObj <  fDist2TrajGateMax)
                 && (fDist2TrajStatObj  > fDist2TrajGateMin) )
            {
              /* Set the new upper limit for the x position based on the current stationary object */
              fXUpperLimit = fXObj + fXEgoVelocityGate;
              /* Update the distance to trajectory gates gates */
              fDist2TrajGateMin = fDist2TrajStatObj - CD_STAT_OBJ_CHAIN_DET_PROC_GATE;
              fDist2TrajGateMax = fDist2TrajStatObj + CD_STAT_OBJ_CHAIN_DET_PROC_GATE;
#ifdef ACDC_SIMU
              /* In simulation store the ID of each object found in the chain */
              ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sHypRunupStatDebug.aiStatObjChainID[iObjCount]  = iObjIndexSorted;
#endif

              /* If both objects overlap increase the object counter */
              iObjCount++;
            }
          }
          else
          {
            bAbortLoop = TRUE;
          }
        }
      }
    }
  }

  /* If more than CD_STAT_OBJ_CHAIN_DET_MIN_NOF_OBJS objects have been found increase the variable iObjInvalidCnt */
  if (iObjCount >= CD_STAT_OBJ_CHAIN_DET_MIN_NOF_OBJS)
  {
    /* If no run up stationary hypothesis was active for this object set the iObjInvalidCnt to its initial value */
    if (pObjHypData->HypothesisHist.RunUpStationary == 0)
    {
      pObjHypData->sHypRunUpStatData.iObjInvalidCnt = CD_STAT_OBJ_CHAIN_DET_INIT_CNT;
    }
    else
    {
      /* Increment the variable iObjInvalidCnt to a maximum of CD_STAT_OBJ_CHAIN_DET_MAX_CNT */
      pObjHypData->sHypRunUpStatData.iObjInvalidCnt++;
      pObjHypData->sHypRunUpStatData.iObjInvalidCnt = CML_Min(pObjHypData->sHypRunUpStatData.iObjInvalidCnt, CD_STAT_OBJ_CHAIN_DET_MAX_CNT);
    }
  }
  else
  {
    /* Decrement the counter */
    pObjHypData->sHypRunUpStatData.iObjInvalidCnt--;
    pObjHypData->sHypRunUpStatData.iObjInvalidCnt = CML_Max(pObjHypData->sHypRunUpStatData.iObjInvalidCnt, 0);
  }

  /* If the counter is greater than zero, the object shall not be marked as valid for run up stationary hypothesis */
  if (pObjHypData->sHypRunUpStatData.iObjInvalidCnt > 0)
  {
    bObjValidForStatHyp = FALSE;
  }

  return bObjValidForStatHyp;
}
#endif /* CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON */

/*************************************************************************************************************************
  Functionname:         CDHypoRunUpStatInitInternalData                                                             */ /*!

  @brief                Initialization of run up stationary internal data

  @description          Initialization of run up stationary internal data by resetting the structure 
                        @ref CDInternalObjHypRunUpStatData_t

  @return               void

  @param[in]            iObjectIndex: object identifier

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION
  @c_switch_full        None
  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @author               David Stenmanns | david.stenmanns@continental-corporation.com | +49 (8382) 9699-553

  @testmethod           @ref TEST_CDHYPORUNUPSTATINITINTERNALDATA_001

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoRunUpStatInitInternalData(ObjNumber_t const iObjectIndex )
{
  CDInternalObjHypRunUpStatData_t * const pHypData = &(ACDC_p_ModObjHypothesisData(iObjectIndex)->sHypRunUpStatData);

#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)

 #ifdef ACDC_SIMU
  ObjNumber_t iObjChain;
  
  for (iObjChain = 0; iObjChain < EM_N_OBJECTS; iObjChain++)
  {
    ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].CD.sHypRunupStatDebug.aiStatObjChainID[iObjChain] = OBJ_INDEX_NO_OBJECT;
  }
 #endif

  pHypData->iObjInvalidCnt   = 0;
#else
  pHypData->uDummy1          = 0u;
#endif

  pHypData->bObstacleAtLeft  = b_FALSE;
  pHypData->bObstacleAtRight = b_FALSE;
  pHypData->uDummy           = 0u;

}

/*************************************************************************************************************************
  Functionname:         CDHypRelationsRunUpStationaryHypo                                                                */ /*!

  @brief                Adapts the previously calculated stationary hypothesis on base of other calculates hypotheses.

  @description          Decreases the Run Up Stationary hypothesis probability if an ACC or Static hypothesis was 
                        active during the last cycles. \n
                        Therefore a counter is increased for each cycle an ACC or static hypothesis is active up 
                        to a maximum value of @ref CD_HYPREL_ACC2RUNUPSTAT_MAX_SUPPRESS_TIME. The same counter is \n
                        decreased when the ACC or Static Hypothesis is lost. As long as this counter has not reached 0 
                        and the related object is stationary, the hypothesis probability of a static hypothesis is set \n
                        hard to @ref CD_HYPREL_ACC2RUNUPSTAT_SUPPRESS_HYP_PROB.
                        @startuml CDHypRelationsRunUpStationaryHypo_activity.png
                        start
                        : Check whether a ACC hypothesis is active;
                        note right
                          Loop over all hypothesis and check the type
                        end note
                        if(Active hypothesis was found) then (Yes)
                          :1}
                          : increase the ACC hypothesis timer;
                        else (No)
                          :2}
                          : decrease the ACC hypothesis timer;
                        endif
                        : Limit the ACC hypothesis timer;
                        if (Check ACC hypothesis timer) then (is active (>0s))
                        partition "Execute for all hypothesis" {
                          if (Check hypothesis type and object ID) then (Runup stationary found and object is not the one from the ACC hypothesis)
                            if (Check whether the object is stationary (not stopped)) then (hypothesis with suitable object found)
                              :3}
                              : **Limit the hypothesis probability**;
                            else
                              :4}
                            endif
                          else
                            :5}
                          endif 
                          }
                        else
                          :6}
                        endif
                        stop
                        @enduml

  @return               void

  @param[in,out]        None

  @glob_in              @ref ACDC_f_GetCycleTime \n
                        @ref ACDC_p_GetEMARSObjMotionAttributes \n
                        @ref ACDC_b_GetObjIsMovingToStationary \n
                        @ref ACDC_p_GetIntHypothesisList\n
  @glob_out             @ref ACDC_p_ModCurrentIntHypotheses\n
                        @ref ACDC_p_ModIntHypothesesData\n

  @c_switch_part        @ref CD_HYP_RUN_UP_STAT_USE_ACC_HYPOTHESIS_SUPPORT
  @c_switch_full        None  

  @pre                  Only one ACC hypothesis is allowed. If this is changed the logic here has to be adapted. 
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDHYPRELATIONSRUNUPSTATIONARYHYPO_001 \n
                        @ref TEST_CDHYPRELATIONSRUNUPSTATIONARYHYPO_002 \n
                        @ref TEST_CDHYPRELATIONSRUNUPSTATIONARYHYPO_003 \n
                        @ref TEST_CDHYPRELATIONSRUNUPSTATIONARYHYPO_004 \n
						@ref TEST_CDHYPRELATIONSRUNUPSTATIONARYHYPO_005 \n
						@ref TEST_CDHYPRELATIONSRUNUPSTATIONARYHYPO_006 \n
						

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypRelationsRunUpStationaryHypo (void)
{
#if CD_HYP_RUN_UP_STAT_USE_ACC_HYPOTHESIS_SUPPORT

  CDIntHypotheses_t                * const pIntHypothesisList = ACDC_p_ModCurrentIntHypotheses();
  CDHypRelationAcc2RunUpStat_t  * const pAcc2RunUpStat     = &(ACDC_p_ModIntHypothesesData()->sHypRelations.Acc2RunUpStat);
  boolean                               bACCHypFound       = FALSE;
  ObjNumber_t                           iACCHypObj         = OBJ_INDEX_NO_OBJECT;
  uint32                                uiIdx;

  /************************************************************************/
  /* Find ACC or follow hypothesis                                        */
  /************************************************************************/
  for( uiIdx = 0u; (uiIdx < pIntHypothesisList->uNumOfHyps) && (bACCHypFound == FALSE); uiIdx++ )
  {
    /* Get pointer to current hypothesis */
    CDIntHypothesis_t const * const pHypoACC = &(pIntHypothesisList->aHyp[uiIdx]);

    /* Check for static or ACC hypothesis */
    if ( (pHypoACC->eType == CDHypothesisType_ACC)
      || (pHypoACC->eType == CDHypothesisType_Static) )
    {
      bACCHypFound = TRUE;
      iACCHypObj   = pHypoACC->iObjectRef;
    }
  }

  /************************************************************************/
  /* Update suppress timer                                                */
  /************************************************************************/
  if (bACCHypFound == TRUE)
  {
    pAcc2RunUpStat->fACCHypTimer += ACDC_f_GetCycleTime();
  }
  else
  {
    pAcc2RunUpStat->fACCHypTimer -= ACDC_f_GetCycleTime();
  }
  /* Limit block time to a reasonable range */
  pAcc2RunUpStat->fACCHypTimer = MINMAX_FLOAT(0.f, CD_HYPREL_ACC2RUNUPSTAT_MAX_SUPPRESS_TIME, pAcc2RunUpStat->fACCHypTimer);

  /************************************************************************/
  /* Apply relation conclusion                                            */
  /************************************************************************/

  /* Check whether the block time has not ran out */
  if (pAcc2RunUpStat->fACCHypTimer >  C_F32_DELTA )
  {
    /* Check for RunUpStat Hypothesis */
    for( uiIdx = 0u; uiIdx < pIntHypothesisList->uNumOfHyps; uiIdx++ )
    {
      /* Get pointer to current hypothesis */
      CDIntHypothesis_t * const pHypo = &(pIntHypothesisList->aHyp[uiIdx]);
    
      /* Check for run-up stationary hypothesis, and whether the object is not the one from the used ACC hypothesis */
      if (    (pHypo->eType      == CDHypothesisType_RunUpStationary )
           && (pHypo->iObjectRef != OBJ_INDEX_NO_OBJECT              )
           && (pHypo->iObjectRef != iACCHypObj                       ) )
      {
        /* Check whether the block time has not ran out and whether the object is a stationary (not stopped) */
        if (ACDC_p_GetEMGenObjAttributes(pHypo->iObjectRef)->eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
        {
          pHypo->fHypothesisProbability = MIN(CD_HYPREL_ACC2RUNUPSTAT_SUPPRESS_HYP_PROB, pHypo->fHypothesisProbability);
        }
      }
    }
  }
#endif
}



/*************************************************************************************************************************
  Functionname:         CDHypoRunUpStationaryPost                                                                        */ /*!

  @brief                Call all functions which have to be executed after the object hypothesis calculations

  @description          Calls the function @ref CDHypRelationsRunUpStationaryHypo that handles the relations between 
                        the previously created hypotheses.
                        @startuml CDHypoRunUpStationaryPost.png
                        start
                          #Orange:Call hypothesis relation calculation:
                          <b>CDHypRelationsRunUpStationaryHypo</b> >
                        stop
                        @enduml

  @return               void

  @param[in,out]        None

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        None

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDHYPORUNUPSTATIONARYPOST_001

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoRunUpStationaryPost(void)
{

  /* Calculate properties according to hypothesis relations */
  /*PRQA S 2987 1*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Function call is not redundant and No side effects.*/
  CDHypRelationsRunUpStationaryHypo ();

}

///@}
#endif  /* #if (CD_USE_RUN_UP_STAT_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

