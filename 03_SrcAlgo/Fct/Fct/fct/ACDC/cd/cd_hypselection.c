/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypselection.c

DESCRIPTION:               selects the most relevant hypotheses

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 13:25:12CEST $

VERSION:                   $Revision: 1.50 $

LEGACY VERSION:            Revision: 2.10

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
@defgroup cd_hypselection HypSelection
@ingroup cd
@brief          The Hypotheses Selection module contains two main functions: One to select the most 
                important hypotheses, and one to sort the hypotheses list and copy it to the output structure.\n\n

@description    With its extern functions the module provides 2 different functionalities:
                - **Hypotheses Selection**: \n
                  The function @ref CDHypSelCreateInternalHypotheses handles the inserting of a newly created hypothesis 
                  into the list of existing hypotheses. It is called at the end of each hypothesis handler.\n
                  The function @ref CDHypSelPrepareCycleHypothesesSelection initializes the module internal data 
                  required for the hypotheses selection function. It is called once at the beginning of each cycle.
                - **Hypotheses Sorting**: \n
                  At the end of each cycle the hypotheses list is sorted according to the hypotheses' relevance 
                  and all hypothesis relevant attributes are updated. Subsequently its data is copied to the 
                  output structure. These steps are handled by the function @ref CDHypSelFillHypothesesInterface.
                - **Module initialization**:\n
                  The function @ref CDHypSelPrepareCycleHypothesesSelection is called once at the beginning of 
                  each cycle and initializes all static data.
@{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! Invalid hypothesis id */
#define CD_HYPSEL_HYPINDEX_NOHYP             (-1)
/*! Number which is larger than the largest possible hypothesis relevance */
#define CD_HYPSEL_LARGEST_HYP_RELEVANCE      (1.0E10F)
/*! This switch has to be active if there are more internal hypothesis than on the interface */
#define CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS  SWITCH_OFF


/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void    CDHypSelInitExtHypothesis                (sint32 iHypID);
static void    CDHypSelCopySingleIntToExtHypothesis     (sint32 const iIntHypIndex, sint32 const iExtHypIndex );
static void    CDHypSelCopyIntToExtHypotheses           (void);
static void    CDHypSelSortHypotheses                   (void);
static void    CDHypSelCalculateHypothesisRelevance     (CDIntHypothesis_t       *const pHypothesis);
static fTime_t CDHypSelCorrectSingleTimingValueByLatency(fTime_t timingValue );
#if (CD_USE_PERSISTENT_HYPOTHESIS_IDS == SWITCH_OFF)
static void    CDHypSelSortHypsAccordingToRelevance                         (CDIntHypothesis_t aRelHypList[]);
#else
/* PRQA S 2217 LINE_LENGTH */ /*Andreas Kramer: Keep definition in one line to have better readability */
static void    CDHypSelSortHypsPersistInit                                  (CDIntHypothesis_t aRelHypList[], boolean abExtHypIndexUsed[], boolean abIntHypAssigned[]);
static void    CDHypSelSortHypsPersistAssignPreviousHyps                    (CDIntHypothesis_t aRelHypList[], boolean abExtHypIndexUsed[], boolean abIntHypAssigned[], CDIntHypothesis_t const aPrevHypList[]);
static void    CDHypSelSortHypsPersistAssignRemainHypsToFreeSlots           (CDIntHypothesis_t aRelHypList[], boolean abExtHypIndexUsed[], boolean abIntHypAssigned[]);
#if CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS                                     
static void    CDHypSelSortHypsPersistAssignRemainHypsToLeastRelevanceSlots (CDIntHypothesis_t aRelHypList[], boolean abExtHypIndexUsed[], boolean abIntHypAssigned[]);
#endif
/* PRQA L:LINE_LENGTH */
#endif

/*************************************************************************************************************************
  Functionname:         CDHypSelCalculateHypothesisRelevance                                                               */ /*!

  @brief                Calculates the hypothesis relevance on base of the hypothesis type and its probability.

  @description          The relevance of the hypothesis is calculated based on the hypothesis information.
                        Therefore each hypothesis type gets assigned a certain basic relevance
                        (>see "Dependencies Hypothesis - Relevance"). \n
                        If the assigned object index is valid, this relevance is subsequently 
                        modified via the Formula "Relevance".

  @return               void

  @param[in,out]        *pHypothesis :  Pointer to the hypothesis for which the relevance shall be calculated.

  @glob_in              @ref CD_f_GetLongNecAccel \n
                        @ref ACDC_p_GetEMGenObjQualifiers
  @glob_out             None

  @c_switch_part        @ref CD_USE_TURNINTOVRU_HYPOTHESIS \n
                        @ref CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS \n
                        @ref CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     
                        - **Dependencies Hypothesis - Relevance:**\n
                          |Hypothesis           | Type Relevance |
                          |:--------------------|:---------------|
                          |CollisionUnavoidable |           40000|
                          |PedCollision         |           20000|
                          |TurnIntoVRU          |           20000|
                          |Collision            |           20000|
                          |BicycleCollision     |           20000|
                          |DriveIntoSloMo       |           15000|
                          |Crossing             |           15000|
                          |RunUp                |           10000|
                          |RunUpBraking         |           10000|
                          |PedPass              |           10000|
                          |RunUpStationary      |            8000|
                          |ACC                  |            7500|
                          |CutIn                |            5000|
                          |Static               |            3000|
                          |Pass                 |            1000|
                          |No Hypothesis        |               0|
                          \n
                        - **Formula Relevance:**\n
                        \f$ Relevance = TypeRelevance_{Hyp} \cdot Probability_{Hyp} \cdot EbaQuality_{Obj} - LongNecAccel_{Obj}\f$

  @author               Martin Kallnik | martin.kallnik@contiautomotive.com

  @testmethod           @ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_001\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_002\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_003\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_004\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_005\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_006\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_007\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_008\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_009\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_010\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_011\n
                        @ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_012\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_013\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_014\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_015\n
						@ref TEST_CDHYPSELCALCULATEHYPOTHESISRELEVANCE_016\n
  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypSelCalculateHypothesisRelevance(CDIntHypothesis_t       *const pHypothesis) 
{
  float32 CDHypRelevance;
  
  if (pHypothesis->iObjectRef != OBJ_INDEX_NO_OBJECT)
  {
    /*PRQA S 3121,2205 SWITCHCASE*/ /* date: 2017-09-22, reviewer: Danner Andreas (uid41765), Andreas Kramer, reason: Definition of macros would degrade readability.*/
    switch(pHypothesis->eType)
    {
      case CDHypothesisType_CollisionUnavoidable: CDHypRelevance = 40000.0f;    break;
      case CDHypothesisType_PedCollision        : CDHypRelevance = 20000.0f;    break;
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
      case CDHypothesisType_TurnIntoVRU         : CDHypRelevance = 20000.0f;    break;
#endif /* #if (CD_USE_TURNINTOVRU_HYPOTHESIS) */
      case CDHypothesisType_Collision           : CDHypRelevance = 20000.0f;    break;
      case CDHypothesisType_CyclColl            : CDHypRelevance = 20000.0f;    break;
#if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
      case CDHypothesisType_DriveIntoOncoming   : CDHypRelevance = 15000.0f;    break;
#endif /* #if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS) */
#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)
      case CDHypothesisType_DriveIntoSloMo      : CDHypRelevance = 15000.0f;    break;
#endif /* #if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS) */
      case CDHypothesisType_Crossing            : CDHypRelevance = 15000.0f;    break;
      case CDHypothesisType_RunUp               : CDHypRelevance = 10000.0f;    break;
      case CDHypothesisType_RunupCoMoving       : CDHypRelevance = 10000.0f;    break;
      case CDHypothesisType_RunUpBraking        : CDHypRelevance = 10000.0f;    break;
      case CDHypothesisType_PedPass             : CDHypRelevance = 10000.0f;    break;
      case CDHypothesisType_RunUpStationary     : CDHypRelevance =  8000.0f;    break;
      case CDHypothesisType_ACC                 : CDHypRelevance =  7500.0f;    break;
      case CDHypothesisType_CutIn               : CDHypRelevance =  5000.0f;    break;
      case CDHypothesisType_Static              : CDHypRelevance =  3000.0f;    break;
      case CDHypothesisType_Pass                : CDHypRelevance =  1000.0f;    break;
      case CDHypothesisType_No                  : CDHypRelevance =     0.0f;    break;
      default                                   : CDHypRelevance =     0.0f;    break;
    }
    /*PRQA L:SWITCHCASE*/
    pHypothesis->fRelevance  = CDHypRelevance;
    /* Reduce relevance for low hypothesis probability */
    pHypothesis->fRelevance *= pHypothesis->fHypothesisProbability;
    /* Reduce relevance for low object quality */
    pHypothesis->fRelevance *= (((float32)ACDC_p_GetEMGenObjQualifiers(pHypothesis->iObjectRef)->uiEbaObjQuality) * (0.01f));
    /* Reduce relevance according to needed acceleration */
    pHypothesis->fRelevance -= CD_f_GetLongNecAccel(pHypothesis->iObjectRef);
  }
  else
  {
    /* Error path. This should never happen. */
    pHypothesis->fRelevance = 0.0F;
    ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  }
}


/*************************************************************************************************************************
  Functionname:         CDHypSelCreateInternalHypotheses                                                                        */ /*!

  @brief                The Hypotheses Selection function is called after the calculation of every single hypothesis to 
                        assure that never more than 12 Hypotheses can exist at the same time. If this limit is reached, 
                        hypotheses with low importance are discarded.

  @description          The function compares the criticality of the current hypothesis with the relevance of the already 
                        found hypotheses. Only if the hypothesis belongs to the most important hypotheses, it is stored.
                        @startuml CDHypSelCreateInternalHypotheses_activity.png
                        start
                          #Orange:Calculate Relevance of the given Hypothesis:
                          <b>CDHypSelCalculateHypothesisRelevance</b> >
                          if(Hypothesis is **Pass**? 
                          AND another hypothesis on the same object is
                          **Cut In**, **Run Up** or **Run Up Braking**?) then (Yes)
                             :1}
                             :Discard current hypothesis;
                          elseif(Hypothesis is **Cut In**? 
                          AND another hypothesis on the same object is
                          **Run Up** or **Run Up Braking**?) then (Yes)
                            :2}
                            :Discard current hypothesis;
                          else(No)
                            if(Maximum number of hypotheses already reached?) then (Yes)
                              :Select the least critical hypothesis;
                              if(New Hypothesis Relevance > least critical hypothesis' relevance?) then (Yes)
                                :3}
                                :Replace the least critical 
                                hypothesis with the current;
                              else(No)
                                :4}
                                :Discard current hypothesis;
                              endif
                            else(No)
                              :5}
                              :Append current hypothesis 
                              to the hypotheses list;
                            endif
                          endif
                        stop
                        @enduml

  @return               void

  @param[in,out]        *pHypothesis :      Pointer to the hypothesis for which the relevance shall be calculated.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModCurrentIntHypotheses\n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  Assure that pointers are valid \n
                        @ref CDHypSelPrepareCycleHypothesesSelection was called at the beginning of the cycle
  @post                 No changes

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_001\n
                        @ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_002\n
                        @ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_003\n
                        @ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_004\n
                        @ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_005\n
						@ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_006\n
						@ref TEST_CDHYPSELCREATEINTERNALHYPOTHESES_007\n

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypSelCreateInternalHypotheses(CDIntHypothesis_t        *const pHypothesis)
{
  CDIntHypotheses_t * const pInternalHypothesisList = ACDC_p_ModCurrentIntHypotheses();
  uint8   uiHypothesis = 0u;
  uint8   uiLeastCritHypothesis;
  boolean bHypNotRelevant;

  bHypNotRelevant = b_FALSE;

  /* get criticality of hypothesis */
  CDHypSelCalculateHypothesisRelevance(pHypothesis);

  /* pre-filter: do not store pass hypothesis on object if a run-up or cut-in exists for the object */
  if (pHypothesis->eType == CDHypothesisType_Pass)
  {

    for ( uiHypothesis = 0u; uiHypothesis < pInternalHypothesisList->uNumOfHyps; uiHypothesis++ )
    {  
      CDIntHypothesis_t const * const currentRelHypo = &(pInternalHypothesisList->aHyp[uiHypothesis]);
      
      if (    (      currentRelHypo->iObjectRef             == pHypothesis->iObjectRef       )
           && (    ( currentRelHypo->eType                  == CDHypothesisType_RunUp        )
                || ( currentRelHypo->eType                  == CDHypothesisType_RunupCoMoving)
                || ( currentRelHypo->eType                  == CDHypothesisType_RunUpBraking )
                || ( currentRelHypo->eType                  == CDHypothesisType_CutIn        ) )
           && (      currentRelHypo->fHypothesisProbability  > CD_COMMON_HYP_PROB_IRREL_THRES  ) )
      {
        bHypNotRelevant = b_TRUE;
      }
    }
  }
  else if ( pHypothesis->eType == CDHypothesisType_CutIn )
  {
    for ( uiHypothesis = 0u; uiHypothesis < pInternalHypothesisList->uNumOfHyps; uiHypothesis++ )
    {  
      CDIntHypothesis_t const * const currentRelHypo = &(pInternalHypothesisList->aHyp[uiHypothesis]);
      
      if (    (      currentRelHypo->iObjectRef             == pHypothesis->iObjectRef       )
           && (    ( currentRelHypo->eType                  == CDHypothesisType_RunUp        )
                || ( currentRelHypo->eType                  == CDHypothesisType_RunupCoMoving)
                || ( currentRelHypo->eType                  == CDHypothesisType_RunUpBraking ) )
           && (      currentRelHypo->fHypothesisProbability  > CD_COMMON_HYP_PROB_IRREL_THRES  ) )
      {
        bHypNotRelevant = b_TRUE;
      }
    }
  }
  else
  {
    /* Nothing to Do! */
    /* pre-filter: do not store pass hypothesis on object if a run-up or cut-in exists for the object */
  }

  /* prefilter: do not store cut-in hypothesis on object if a run-up exists for the object */

  /* two cases has to be handled:
     case a : there are 'free' slot in the array (just add the hypothesis)
     case b : array is full. remove least critical hypothesis (this may be the new one)
   */  
  if ( bHypNotRelevant == b_TRUE )
  {
    /* do nothing, a more precise hypothesis already exists*/
  }
  else 
  {
    if ( pInternalHypothesisList->uNumOfHyps < CD_NUMBER_OF_HYPOTHESES ) /* case a */
    {
      /* copy hypothesis to first free slot*/
      pInternalHypothesisList->aHyp[pInternalHypothesisList->uNumOfHyps] = *pHypothesis;
      
      /* increase number of found hypothesis*/
      pInternalHypothesisList->uNumOfHyps++;
    }  
    else /* case b */
    {
      /* find least important hypothesis */
      /* initialize least important hypothesis with hypothesis 0 */
      uiLeastCritHypothesis = 0u;
      /* compare hypothesis with least critical hypothesis */
      for (uiHypothesis = 0u; uiHypothesis < CD_NUMBER_OF_HYPOTHESES; uiHypothesis++)
      {
        /* if criticality of hypothesis is below the current least critical one,
           update the least critical hypothesis index*/
        if (   pInternalHypothesisList->aHyp[uiHypothesis].fRelevance 
             < pInternalHypothesisList->aHyp[uiLeastCritHypothesis].fRelevance
           ) 
        {
          uiLeastCritHypothesis = uiHypothesis;
        }   
      }
      /* if new hypothesis is more critical than least critical hypothesis from array,
         replace the least critical one */
      if ( pInternalHypothesisList->aHyp[uiLeastCritHypothesis].fRelevance < pHypothesis->fRelevance )
      {
        pInternalHypothesisList->aHyp[uiLeastCritHypothesis] = *pHypothesis;
      }
    }
  }
  return;
}

/*************************************************************************************************************************
  Functionname:         CDHypSelPrepareCycleHypothesesSelection                                                            */ /*!

  @brief                The function initializes the module internal data required for the hypotheses selection function. 
                        It is called once at the beginning of each cycle.

  @description          The function initializes the module internal data required for the hypotheses selection function.
                        It is called once at the beginning of each cycle. It resets the hypotheses array
                        (@ref CDIntHypothesis_t) and the number of relevant hypotheses.
                        @startuml CDPrepareCycleHypothesesSelection_activity.png
                        start
                          :Copy current hypotheses to 
                          list of previous hypotheses;
                          :Copy number of current hypotheses 
                          to number of previous hypotheses;
                          :Set number of current 
                          hypotheses to 0;
                          :Reset entire array of
                          current hyptheses;
                        stop
                        @enduml
  @return               void

  
  @glob_in              @ref CD_a_GetIntHypothesisList
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPSELPREPARECYCLEHYPOTHESESSELECTION_001

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypSelPrepareCycleHypothesesSelection(void)
{
  uint32 uiHypothesis;
  CDIntHypotheses_t * const pInternalHypothesisList = ACDC_p_ModCurrentIntHypotheses();
  
  /* store hypotheses from last cycle */
  *ACDC_p_ModPrevIntHypotheses() = *pInternalHypothesisList;
  
  /* reset hypotheses */  
  pInternalHypothesisList->uNumOfHyps = 0u;
  /* reset array*/
  for (uiHypothesis = 0u; uiHypothesis < CD_NUMBER_OF_HYPOTHESES; uiHypothesis++)
  {
    CDIntHypothesis_t * const currentRelHypo = &(pInternalHypothesisList->aHyp[uiHypothesis]);
    currentRelHypo->eType                  = CDHypothesisType_No;
    currentRelHypo->fRelevance             = 0.0f;
    currentRelHypo->iObjectRef             = OBJ_INDEX_NO_OBJECT;
    currentRelHypo->eObjectClass           = EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
    currentRelHypo->fHypothesisProbability = 0.0f;
    currentRelHypo->fHypothesisLifetime    = 0.0f;
    currentRelHypo->eEBAInhibitionMask     = FPS_EBA_INH_ALL;
    currentRelHypo->iExtHypID              = CD_HYPSEL_HYPINDEX_NOHYP;
  }
}


/*************************************************************************************************************************
  Functionname:         CDCorrectSingleTimingValueByLatency                                                          */ /*!

  @brief                Corrects a single timing value by subtracting the system latency.

  @description          Corrects a single timing value by subtracting the system latency from the input value.
                        (>see Formula "Timing Value")

  @return               fTime_t : corrected timing value. @phys_unit [s] @range [0,@ref CD_TIME_MAX]

  @param[in]            timingValue : Timing value that shall be corrected. @phys_unit [s] @range[0,@ref CD_TIME_MAX]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Timing Value:**\n
                        \f$ timingValue_{tmp} = timingvalue_{In} - SystemLatency \f$\n
                        \n
                        |\f$timingValue_{tmp}\f$|\f$timingValue_{out}\f$|
                        |:----------------------|:----------------------|
                        |         <= 0          |           0           |
                        |          > 0          |\f$timingValue_{tmp}\f$|

  @author               Clemens Schnurr

  @testmethod           @ref TEST_CDHYPSELCORRECTSINGLETIMINGVALUEBYLATENCY_001\n
                        @ref TEST_CDHYPSELCORRECTSINGLETIMINGVALUEBYLATENCY_002\n
                        @ref TEST_CDHYPSELCORRECTSINGLETIMINGVALUEBYLATENCY_003

  @traceability         Design Decision

*************************************************************************************************************************/
static fTime_t CDHypSelCorrectSingleTimingValueByLatency( fTime_t timingValue ) 
{
  if (timingValue < (CD_TIME_MAX - C_F32_DELTA))
  {
    timingValue = timingValue - CD_LATENCY_SYSTEM;
    timingValue = MAX_FLOAT(timingValue, 0.f);
  }
  return timingValue;
}


/*************************************************************************************************************************
  Functionname:         CDHypSelCopyIntToExtHypothesis                                                              */ /*!

  @brief                Fill external hypothesis according to internal hypothesis

  @description          Calculates and copies all required data to the output interface.
                        @startuml CDHypSelCopyIntToExtHypothesis.png
                          start
                          :Update all Hypotheses relevant data;
                          note left
                          Due to GetFunctions some of the hypotheses'
                          attributes might not be calculated yet. Call
                          all GetFunctions to assure that all data exists
                          for the Objects used in the hypotheses.
                          end note
                          #Orange:Correct TTC. TTB and TTS Values:
                          <b>CDCorrectSingleTimingValueByLatency</b> >
                          stop
                        @enduml
  
  @return               void

  @param[in]            iIntHypIndex    : Index of the internal hypothesis (sorted by relevance).
  @param[in]            iExtHypIndex    : Index of the external hypothesis (unsorted).
  
  @glob_in              @ref ACDC_p_GetEMGenObj       \n
                        @ref ACDC_p_GetObjMovement    \n
                        @ref CD_f_GetTTC              \n
                        @ref CD_f_GetTTC2             \n
                        @ref CD_f_GetTTC3             \n
                        @ref CD_f_GetTTBDynPre        \n
                        @ref CD_f_GetTTBDynAcute      \n
                        @ref CD_f_GetTTSPre           \n
                        @ref CD_f_GetTTSAcute         \n
                        @ref ACDC_p_GetObjPositions   \n
                        @ref CD_f_GetClosingVelocity  \n
                        @ref CD_f_GetLongNecAccel     \n
                        @ref CD_f_GetLatNecAccel      \n
                        @ref CD_f_GetTTMLongAcute     \n
                        @ref CD_f_GetTTMLongPre       \n
                        @ref ACDC_p_GetCurrentIntHypothesis \n
                        @ref ACDC_p_GetObjStaticEvasionData

  @glob_out             @ref ACDC_p_ModExtHypothesis

  @c_switch_part        @ref ACDC_CFG_USE_HYP_TYPE_RUNUP_COMOVING \n
                        @ref CD_USE_HYPCAT_FOR_DYNAMIC_PROPERTY \n
                        @ref CD_USE_TTM_LONG
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer

  @testmethod           @ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_001 \n
                        @ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_002 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypSelCopySingleIntToExtHypothesis( sint32 const iIntHypIndex, 
                                                  sint32 const iExtHypIndex )
{
  CDIntHypothesis_t     const * const pIntHyp          = ACDC_p_GetCurrentIntHypothesis((uint32)iIntHypIndex);
  Hypothesis_t                * const pExtHyp          = ACDC_p_ModExtHypothesis(iExtHypIndex);
  ObjNumber_t           const         iObj             = pIntHyp->iObjectRef;
  
  /* Check whether object ID is valid */
  if (iObj != OBJ_INDEX_NO_OBJECT)
  {
    EM_t_GenObject        const * const pGenObj        = ACDC_p_GetEMGenObj(iObj);
    SFLMovement_t         const * const pObjMovRel     = &(ACDC_p_GetObjMovement(iObj)->Rel);
    EM_t_GenObjQualifiers const * const pObjQualifier  = &pGenObj->Qualifiers;
   
    float32 fTTC          = CD_f_GetTTC(iObj);
    float32 fTTC2         = CD_f_GetTTC2(iObj);
    float32 fTTC3         = CD_f_GetTTC3(iObj);
    float32 fTTBDynPre    = CD_f_GetTTBDynPre(iObj);
    float32 fTTBDynAcute  = CD_f_GetTTBDynAcute(iObj);
    float32 fTTSPre       = CD_f_GetTTSPre(iObj);
    float32 fTTSAcute     = CD_f_GetTTSAcute(iObj);
#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
    float32 fTTMLongPre   = CD_f_GetTTMLongPre(iObj);
    float32 fTTMLongAcute = CD_f_GetTTMLongAcute(iObj);
#endif /* #if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON) */
    pExtHyp->uiHypothesisProbability = (uint8)ROUND_TO_UINT(pIntHyp->fHypothesisProbability * 100.0F);
    pExtHyp->uiObjectRef             = pIntHyp->iObjectRef;

    pExtHyp->eType                   = pIntHyp->eType;

#if (ACDC_CFG_USE_HYP_TYPE_RUNUP_COMOVING == SWITCH_OFF)
    /* Use the hypothesis type CDHypothesisType_RunUp instead of the type CDHypothesisType_RunupCoMoving in old interface versions
       or in case head does not use this hypothesis type */
    if(pExtHyp->eType == CDHypothesisType_RunupCoMoving)
    {
      pExtHyp->eType = CDHypothesisType_RunUp;
    }
#endif

    pExtHyp->uiObjectProbability     = pObjQualifier->uiEbaObjQuality;
   
    pExtHyp->eSensorSource           = CD_e_GetSensorSource(iObj);
    pExtHyp->eEBAObjectClass         = pIntHyp->eObjectClass;

#if CD_USE_HYPCAT_FOR_DYNAMIC_PROPERTY
    if (CML_GetBit(pObjQualifier->eEbaHypCat, FPS_EBA_HYP_CAT_STAT) == TRUE )
    {
      pExtHyp->eEBADynProp   = EBADynProp_Stat;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_DoT;
    }
    else if (CML_GetBit(pObjQualifier->eEbaHypCat, FPS_EBA_HYP_CAT_COMOV) == TRUE )
    {
      pExtHyp->eEBADynProp   = EBADynProp_Mov;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_DoT;
    }
    else if (CML_GetBit(pObjQualifier->eEbaHypCat, FPS_EBA_HYP_CAT_XING) == TRUE )
    {
      pExtHyp->eEBADynProp   = EBADynProp_Mov;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_Cross;
    }
    else if (CML_GetBit(pObjQualifier->eEbaHypCat, FPS_EBA_HYP_CAT_ONC) == TRUE )
    {
      pExtHyp->eEBADynProp   = EBADynProp_Mov;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_Onco;
    }
    else
    {
      pExtHyp->eEBADynProp   = EBADynProp_NotAvail;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_DoT;
    }
#else
    switch (pGenObj->Attributes.eDynamicProperty)
    {
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY:
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED:
      pExtHyp->eEBADynProp   = EBADynProp_Stat;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_DoT;
      break;
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING:
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN: /* Currently workaround to enable Objects with not-set dyn-prob*/
      pExtHyp->eEBADynProp   = EBADynProp_Mov;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_DoT;
      break;
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT:
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT:
      pExtHyp->eEBADynProp   = EBADynProp_Mov;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_Cross;
      break;
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING:
      pExtHyp->eEBADynProp   = EBADynProp_Mov;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_Onco;
      break;
    default:
      pExtHyp->eEBADynProp   = EBADynProp_NotAvail;
      pExtHyp->eEBAObjMovDir = EBAObjMovDir_DoT;
      break;
    }
#endif

    pExtHyp->eEBAInhibitionMask      = ((pObjQualifier->eEbaInhibitionMask)|(pIntHyp->eEBAInhibitionMask));
   
    pExtHyp->fHypothesisLifetime     = pIntHyp->fHypothesisLifetime;
    
    /* adding information to output hypothesis */
    pExtHyp->fTTC                   = CDHypSelCorrectSingleTimingValueByLatency(fTTC);
    pExtHyp->fTTC2                  = CDHypSelCorrectSingleTimingValueByLatency(fTTC2);
    pExtHyp->fTTC3                  = CDHypSelCorrectSingleTimingValueByLatency(fTTC3);
    /* Don't add latency to TTC4 since it should only be the time gap between Ego and the object */
    pExtHyp->fTTC4                  = CD_f_GetTTC4(iObj);
    pExtHyp->fTTBPre                = CDHypSelCorrectSingleTimingValueByLatency(fTTBDynPre);
    pExtHyp->fTTBAcute              = CDHypSelCorrectSingleTimingValueByLatency(fTTBDynAcute);
    pExtHyp->fTTSPre                = CDHypSelCorrectSingleTimingValueByLatency(fTTSPre);
    pExtHyp->fTTSAcute              = CDHypSelCorrectSingleTimingValueByLatency(fTTSAcute);
    pExtHyp->fLongNecAccel          = CD_f_GetLongNecAccel(iObj);
#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
    pExtHyp->fTTMLongPre            = CDHypSelCorrectSingleTimingValueByLatency(fTTMLongPre);
    pExtHyp->fTTMLongAcute          = CDHypSelCorrectSingleTimingValueByLatency(fTTMLongAcute);
#endif /* CD_USE_TTM_LONG */
    pExtHyp->fLatNecAccel           = CD_f_GetLatNecAccel(iObj);
    pExtHyp->fDistX                 = ACDC_p_GetObjPositions(iObj)->GenObject.fX;
  
    pExtHyp->fVrelX                 = pObjMovRel->Vel.fX;
    pExtHyp->fDistY                 = ACDC_p_GetObjPositions(iObj)->GenObject.fY;
    pExtHyp->fArelX                 = pObjMovRel->Accel.fX;
    pExtHyp->fVrelY                 = pObjMovRel->Vel.fY;
    pExtHyp->fArelY                 = pObjMovRel->Accel.fY;
    pExtHyp->fClosingVelocity       = CD_f_GetClosingVelocity(iObj);

#if(FCT_HYPOTHESIS_INTFVER >= 0x00001C)
#if(ACDC_CFG_TURN_ASSIST == SWITCH_ON)
    pExtHyp->fCorridorStopDistance  = CD_f_GetCorridorStopDistance(iObj);
#else
    pExtHyp->fCorridorStopDistance  = CD_CORRIDORSTOPDIST_INIT;
#endif

    pExtHyp->fCorridorOccupancy     = CD_f_CalcEgoCorridorOccupancy(iObj);
#endif

#if (CD_USE_HIGH_QUALITY_LIFETIME)
    pExtHyp->Custom.fObjLifeTimeHiQual   = ACDC_p_GetObjStaticEvasionData(iObj)->fObjLifeCycleTimeHiQual;
#endif


  }
  else
  {
    /*This path may never appear */
    ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  }

}


/*************************************************************************************************************************
  Functionname:         CDHypSelCopyIntToExtHypotheses                                                                         */ /*!

  @brief                Copies all internal hypothesis to the interface according to the derived sorting

  @description          Resets the external interface. Afterwards copies the internal hypotheses to the interface.
                        @startuml CDHypSelCopyIntToExtHypotheses_activity.png
                          start
                            #Orange:Initialize all external hypothesis:
                            <b>CDHypSelInitExtHypothesis</b> >
                            partition "Execute for all internal hypotheses" {
                            #Orange:Loop over all relevant hypothesis and call the copy function:
                            <b>CDHypSelCopySingleIntToExtHypothesis</b> >
                            }
                          stop
                        @enduml
                        
  @return               void

  @param[in]            None

  @glob_in              @ref ACDC_p_GetCurrentIntHypotheses\n
  @glob_out             None

  @c_switch_part        @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS \n
                        @ref CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS
  @c_switch_full        None

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer 

  @testmethod           @ref TEST_CDHYPSELCOPYINTTOEXTHYPOTHESES_001 \n
                        @ref TEST_CDHYPSELCOPYINTTOEXTHYPOTHESES_002 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypSelCopyIntToExtHypotheses(void)
{
  sint32 iHypIndex;
  CDIntHypotheses_t const * const pInternalHypothesisList = ACDC_p_GetCurrentIntHypotheses();

  /* Initialize all external hypothesis */
  for ( iHypIndex = 0; iHypIndex < (sint32)CD_NUMBER_OF_HYPOTHESES; iHypIndex++)
  {
    CDHypSelInitExtHypothesis(iHypIndex);
  }


  /* Copy data to output*/
  for ( iHypIndex = 0; iHypIndex < (sint32)pInternalHypothesisList->uNumOfHyps; iHypIndex++)
  {

    sint32 iExtHypID = pInternalHypothesisList->aHyp[iHypIndex].iExtHypID;

    if (iExtHypID != CD_HYPSEL_HYPINDEX_NOHYP )
    {
      CDHypSelCopySingleIntToExtHypothesis(iHypIndex, iExtHypID);
    }
    else
    {
#if (CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS==SWITCH_OFF) || (CD_USE_PERSISTENT_HYPOTHESIS_IDS == SWITCH_OFF)
      /* All hypothesis have to be assigned */
      ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
#endif
    }
  }
}


/*************************************************************************************************************************
  Functionname:         CDHypSelFillHypothesesInterface                                                                  */ /*!

  @brief                Fill measurement data for freeze, Sort hypothesis and fill the hypothesis output structure

  @description          Maps the internal hypotheses to the interface. An hypothesis that has been set up once will 
                        always remain at the same index position.
                        @startuml CDHypSelFillHypothesesInterface_activity.png
                        start
                          #Orange:Sort the hypothesis list:
                          <b>CDHypSelSortHypotheses</b> >
                          #Orange:Fill hypothesis interface according to the calculated sorting:
                          <b>CDHypSelCopyIntToExtHypotheses</b> >
                        end
                        @enduml

  @return               void

  @param[in,out]        None

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @todo                 Check why the measurement data step is needed.

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
  
  @testmethod           @ref TEST_CDHYPSELFILLHYPOTHESESINTERFACE_001

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypSelFillHypothesesInterface(void)
{
  /* Map internal hypothesis to the interface */
  CDHypSelSortHypotheses();

  /* Fill hypothesis interface */
  CDHypSelCopyIntToExtHypotheses();

}

#if (CD_USE_PERSISTENT_HYPOTHESIS_IDS == SWITCH_OFF)
/*************************************************************************************************************************
  Functionname:         CDHypSelSortHypothesisAccordingToTheRelevance                         */ /*!

  @brief                Do a selection sort of the internal hypothesis according to the relevance
  @description          Do a selection sort of the internal hypothesis:
                        @startuml CDHypSelSortHypothesisAccordingToTheRelevance.png
                        start
                           :Sort all current hypotheses 
                           according to their relevance;
                        stop
                        @enduml

  @return               void

  @param[in,out]        aRelHypList : Array of all internal hypothesis

  @glob_in              @ref ACDC_p_GetCurrentIntHypotheses\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS

  @pre                  None 
  @post                 None 

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDHYPSELSORTHYPSACCORDINGTORELEVANCE_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypSelSortHypsAccordingToRelevance(CDIntHypothesis_t aRelHypList[])
{
  uint8 uiHypIndex;
  uint8 uiSortedIndex[CD_NUMBER_OF_HYPOTHESES];
  uint8 uiNumOfHyps = ACDC_p_GetCurrentIntHypotheses()->uNumOfHyps;

  /* 1 sort the hypotheses */
  /* 1.1 init sortedIndex */
  for (uiHypIndex = 0u; uiHypIndex < (uint8)CD_NUMBER_OF_HYPOTHESES; uiHypIndex ++)
  {
    uiSortedIndex[uiHypIndex]         = uiHypIndex;
    aRelHypList[uiHypIndex].iExtHypID = CD_HYPSEL_HYPINDEX_NOHYP;
  }

  /* 1.2 sort Hypothesis using "selection sort" with the relevance as sorting criteria */
  for (uiHypIndex = 0u; (uiHypIndex + 1u) < uiNumOfHyps; uiHypIndex++)
  {
    uint8 uiInnerHypIndex;

    for ( uiInnerHypIndex = (uiHypIndex + 1u); uiInnerHypIndex < uiNumOfHyps; uiInnerHypIndex++)
    {
      if ( aRelHypList[uiSortedIndex[uiHypIndex]].fRelevance < aRelHypList[uiSortedIndex[uiInnerHypIndex]].fRelevance)
      {
        /* swap inner and outer */
        const uint8 uiTmpObjIndex      = uiSortedIndex[uiInnerHypIndex];
        uiSortedIndex[uiInnerHypIndex] = uiSortedIndex[uiHypIndex];
        uiSortedIndex[uiHypIndex]      = uiTmpObjIndex;
      }
    }
  }

  /* Assign the calculated order to the internal hypothesis list */
  for (uiHypIndex = 0u; uiHypIndex < uiNumOfHyps; uiHypIndex ++)
  {
    aRelHypList[uiSortedIndex[uiHypIndex]].iExtHypID = (sint8)uiHypIndex;
  }
}
#else


/*************************************************************************************************************************
  Functionname:         CDHypSelSortHypPersistentInit                                                               */ /*!

  @brief                Init the intermediate values

  @description          Init the intermediate values
                        @startuml CDHypSelSortHypPersistentInit.png
                          start
                          partition " <b>Init</b>\n Loop over all internal hypothesis" \
                          {
                            :Init all sorting related values;
                          }
                          stop
                        @enduml
                        
  @return               void

  @param[in,out]        aRelHypList :       Array of all internal hypothesis
  @param[in,out]        abExtHypIndexUsed : Array with flags to save which external hypothesis is already used 
  @param[in,out]        abIntHypAssigned :  Array with flags to save which internal hypothesis are already assigned

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS

  @pre                  None 
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void CDHypSelSortHypsPersistInit(CDIntHypothesis_t aRelHypList[]      , 
                                        boolean           abExtHypIndexUsed[], 
                                        boolean           abIntHypAssigned[] )
{
  sint32 iHypIndex;  
  for (iHypIndex = 0; iHypIndex < (sint32)CD_NUMBER_OF_HYPOTHESES; iHypIndex ++)
  {
    CDIntHypothesis_t * const pCurrentIntHyp = &aRelHypList[iHypIndex];

    pCurrentIntHyp->iExtHypID     = CD_HYPSEL_HYPINDEX_NOHYP;
    abExtHypIndexUsed [iHypIndex] = FALSE;
    abIntHypAssigned  [iHypIndex] = FALSE;
  }
}


/*************************************************************************************************************************
  Functionname:         CDHypSelSortHypPersistentAssignPreviousHyps                                */ /*!

  @brief                Assign all hypothesis which were active in the previous cycle to the same external id

  @description          Assign all hypothesis which were active in the previous cycle to the same external id.
                        @startuml CDHypSelSortHypPersistentAssignPreviousHyps.png
                          start
                          partition " <b>Find matching hypothesis of previous cycle</b>\n Loop over all previous hypothesis" \
                          {
                            if (hypothesis type matches) then (yes)
                              if (object id matches or merged object id matches) then (yes)
                                :1}
                                : Assign the found previous hypothesis ID to the current internal hypothesis;
                                : Mark the external ID as used;
                                : Mark the internal hypothesis as assigned;
                              else
                                :2}
                              endif
                            else
                              :3}
                            endif
                          }
                          stop
                        @enduml

  @return               void

  @param[in,out]        aRelHypList :       Array of all internal hypothesis.
  @param[in,out]        abExtHypIndexUsed : Array with flags to save which external hypothesis is already used.
  @param[in,out]        abIntHypAssigned :  Array with flags to save which internal hypothesis are already assigned.
  @param[in,out]        aPrevHypList :      Previous cycle hypotheses list.

  @glob_in              @ref ACDC_p_GetCurrentIntHypotheses\n
                        @ref ACDC_p_GetPrevIntHypotheses\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void CDHypSelSortHypsPersistAssignPreviousHyps(CDIntHypothesis_t                aRelHypList[]      , 
                                                      boolean                          abExtHypIndexUsed[], 
                                                      boolean                          abIntHypAssigned[] , 
                                                      CDIntHypothesis_t const          aPrevHypList[]     )
{
  sint32       iHypIndex;  
  sint32 const iNumOfHyps     = (sint32)ACDC_p_GetCurrentIntHypotheses()->uNumOfHyps;

  /* Loop over all internal hypothesis to assign all previously used hypothesis again */
  for (iHypIndex = 0; iHypIndex < iNumOfHyps; ++iHypIndex)
  {
    /* Check whether the hypothesis already exists */
    sint32              const iNumOfPrevHyps = (sint32)ACDC_p_GetPrevIntHypotheses()->uNumOfHyps;
    CDIntHypothesis_t * const pCurrentIntHyp = &aRelHypList[iHypIndex];
    sint32                    iPrevIntHypID;
    
    /* Loop over all previous hypothesis */
    for (iPrevIntHypID = 0; (iPrevIntHypID < iNumOfPrevHyps) && (abIntHypAssigned [iHypIndex] == FALSE); iPrevIntHypID++)
    {
      CDIntHypothesis_t const * const pPrevIntHyp = &aPrevHypList[iPrevIntHypID];

      /* Same hypothesis the same hypothesis type. Also check the hypothesis id for validity. */
      if (    (pPrevIntHyp->iExtHypID != CD_HYPSEL_HYPINDEX_NOHYP)
           && (pCurrentIntHyp->eType  == pPrevIntHyp->eType      ) )
      {
        if (pPrevIntHyp->iObjectRef != OBJ_INDEX_NO_OBJECT)
        {
          EM_t_GenObjGenerals const * const pGenObjGenerals = &ACDC_p_GetEMGenObj(pPrevIntHyp->iObjectRef)->General;

          /* If the object is not merged the object ID is identical also. If its merged the mergeID has to be used */
          if (    (    (pCurrentIntHyp->iObjectRef        == pPrevIntHyp->iObjectRef     ) )
               || (    (pGenObjGenerals->eSplitMergeState == EM_GEN_OBJECT_SM_STATE_MERGE)
                    && (pGenObjGenerals->uiMergeID        == pPrevIntHyp->iObjectRef     ) ) )
          {  
            /* Use same hyp ID */
            pCurrentIntHyp->iExtHypID                    = pPrevIntHyp->iExtHypID;
            abExtHypIndexUsed[pCurrentIntHyp->iExtHypID] = TRUE;
            abIntHypAssigned [iHypIndex]                 = TRUE;
          }
        }
        else
        {
          ACDC_ASSERT(FALSE);
        }
      }
    }
  }
}


/*************************************************************************************************************************
  Functionname:           CDHypSelSortHypPersistentAssignRemainingHypsToFreeSlots                                */ /*!

  @brief                  Assign remaining internal hypothesis to the free external slots.

  @description            Assign remaining internal hypothesis to the free external slots.
                          @startuml CDHypSelSortHypPersistentAssignRemainingHypsToFreeSlots.png
                            start
                            if (Is internal hypothesis already assigned?) then (no)
                            partition " <b>Search for free external ID</b>\n Loop over all external hypothesis" \
                            {
                              if (Is external hypothesis used already?) then (no)
                                :1}
                                : Set <b>free external hypothesis id found</b> flag to abort loop
                                : Assign the found free ID to the current internal hypothesis;
                                : Mark the found external ID as used;
                                : Mark the internal hypothesis as assigned;
                              else
                                :2}
                              endif
                            }
                            else
                              :3}
                            endif
                            stop
                          @enduml

  @return                 void

  @param[in,out]          aRelHypList :       Array of all internal hypothesis
  @param[in,out]          abExtHypIndexUsed : Array with flags to save which external hypothesis is already used 
  @param[in,out]          abIntHypAssigned :  Array with flags to save which internal hypothesis are already assigned

  @glob_in                @ref ACDC_p_GetCurrentIntHypotheses\n
  @glob_out               None

  @c_switch_part          None
  @c_switch_full          @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS

  @pre                    None 
  @post                   None

  @InOutCorrelation       see description
  
  @testmethod             @Generic_Testmethods

  @author                 Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void CDHypSelSortHypsPersistAssignRemainHypsToFreeSlots(CDIntHypothesis_t                aRelHypList[]      , 
                                                               boolean                          abExtHypIndexUsed[], 
                                                               boolean                          abIntHypAssigned[] )
{
  sint32 iHypIndex;  
  sint32 const iNumOfHyps     = (sint32)ACDC_p_GetCurrentIntHypotheses()->uNumOfHyps;

  /* Loop over all internal hypothesis again to assign the remaining hypothesis */
  for (iHypIndex = 0u; iHypIndex < iNumOfHyps; ++iHypIndex)
  {
    /* Check whether the hypothesis not assigned yet*/
    if (abIntHypAssigned [iHypIndex] == FALSE)
    { 
      CDIntHypothesis_t * pCurrentIntHyp     = &aRelHypList[iHypIndex];
      boolean             bFreeExtIndexFound = FALSE;
      sint32              iSearchID;

      for (iSearchID = 0; (iSearchID < (sint32)CD_NUMBER_OF_HYPOTHESES) && (bFreeExtIndexFound == FALSE); ++iSearchID)
      {

        /*Check whether ID is free */
        if (abExtHypIndexUsed[iSearchID] == FALSE )
        {
          bFreeExtIndexFound = TRUE;

          /* Assign hypothesis to this slot*/
          pCurrentIntHyp->iExtHypID     = (sint8)iSearchID;
          abExtHypIndexUsed[iSearchID]  = TRUE;
          abIntHypAssigned [iHypIndex]  = TRUE;
        }
      }
    }
  }
}


#if CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS
/*************************************************************************************************************************
  Functionname:           CDHypSelSortHypPersistentAssignRemainingHypsToLowerRelevanceSlots                                */ /*!

  @brief                  Assign remaining internal hypothesis to the external slots with lowest priority.

  @description            Assign remaining internal hypothesis to the external slots with lowest priority.
                          @startuml CDHypSelSortHypPersistentAssignRemainingHypsToLowerRelevanceSlots.png
                            start
                            partition " <b>Assign remaining internal hypothesis according to their relevance</b>\n Loop over all active internal hypothesis" \
                            {
                            : Create struct to save whether a hypothesis was removed because of its relevance;
                            if (Is internal hypothesis already assigned?) then (no)
                              : Find the hypothesis which was already assigned and is not in the removed list and has the lowest priority;
                              if (current hypothesis has a higher relevance than the assigned one with the lowest relevance) then (yes)
                                :1}
                                : Assign the found ID to the current internal hypothesis;
                                : Mark the found external ID as used;
                                : Mark the internal hypothesis as assigned;
                                : Remove the external hypothesis ID from the internal hypothesis;
                                : Add the removed hypothesis to the removed hypothesis list;
                              else
                                :2}
                              endif
                            else
                              :3}
                            endif
                            }
                            stop
                          @enduml

  @return                 void

  @param[in,out]          aRelHypList :       Array of all internal hypothesis
  @param[in,out]          abExtHypIndexUsed : Array with flags to save which external hypothesis is already used 
  @param[in,out]          abIntHypAssigned :  Array with flags to save which internal hypothesis are already assigned

  @glob_in                @ref ACDC_p_GetCurrentIntHypotheses\n
  @glob_out               None

  @c_switch_part          none
  @c_switch_full          @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS \n
                          @ref CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS

  @pre                    None 
  @post                   No changes 

  @InOutCorrelation       see description

  @testmethod             @Generic_Testmethods

  @author                 Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
static void CDHypSelSortHypsPersistAssignRemainHypsToLeastRelevanceSlots(CDIntHypothesis_t        * const aRelHypList      , 
                                                                         boolean                  *       abExtHypIndexUsed, 
                                                                         boolean                  *       abIntHypAssigned )
{
  sint32 iHypIndex;  
  sint32 const iNumOfHyps     = (sint32)ACDC_p_GetCurrentIntHypotheses()->uNumOfHyps;
  
  /* Loop over all Internal hypothesis again to assign the remaining hypothesis */
  for (iHypIndex = 0u; iHypIndex < iNumOfHyps; ++iHypIndex)
  {
    boolean abIntHypRemoved [CD_NUMBER_OF_HYPOTHESES] = {FALSE};

    /* Check whether no free ID was found */
    if (abIntHypAssigned [iHypIndex] == FALSE)
    {
      CDIntHypothesis_t * pCurrentIntHyp = &aRelHypList[iHypIndex];

      /* All IDs are used. Find the one with the lowest relevance */
      sint32  iLowestRelevanceIDCounter;
      sint32  iLowestRelevanceID        = CD_HYPSEL_HYPINDEX_NOHYP;
      float32 fLowestRelevance          = CD_HYPSEL_LARGEST_HYP_RELEVANCE;

      /* Loop over all assigned hypothesis */
      for (iLowestRelevanceIDCounter = 0; iLowestRelevanceIDCounter < CD_NUMBER_OF_HYPOTHESES; ++iLowestRelevanceIDCounter)
      {
        CDIntHypothesis_t const * const pSearchIntHyp = &aRelHypList[iLowestRelevanceIDCounter];

        if (    (abIntHypAssigned [iLowestRelevanceIDCounter] == TRUE            )
             && (abIntHypRemoved  [iLowestRelevanceIDCounter] == FALSE           )
             && (pSearchIntHyp->fRelevance                    <  fLowestRelevance) )
        {
          fLowestRelevance   = pSearchIntHyp->fRelevance;
          iLowestRelevanceID = iLowestRelevanceIDCounter;
        }
      }

      /* Check whether the current hypothesis has higher relevance */
      if (pCurrentIntHyp->fRelevance > fLowestRelevance)
      {
        CDIntHypothesis_t * const pLowestRelIntHyp = &aRelHypList[iLowestRelevanceID];

        /* Assign hypothesis to this slot*/
        pCurrentIntHyp->iExtHypID                     = pLowestRelIntHyp->iExtHypID;
        abIntHypAssigned [iHypIndex]                  = TRUE;
        abExtHypIndexUsed[pCurrentIntHyp->iExtHypID]  = TRUE;

        /* Remove assignment from lowest relevance hypothesis. */
        pLowestRelIntHyp->iExtHypID                   = CD_HYPSEL_HYPINDEX_NOHYP;
        abIntHypRemoved  [iLowestRelevanceID]         = TRUE;
      }
    }
  }
}
#endif /*CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS*/

#endif

/*************************************************************************************************************************
  Functionname:           CDHypSelSortHypotheses                                                                      */ /*!

  @brief                  Sorts all hypotheses according to their relevance.

  @description            At the end of each cycle the hypotheses list is sorted according to the hypotheses' 
                          relevance and all hypothesis relevant attributes are updated. Subsequently its data 
                          is copied to the output structure.
                          @startuml CDHypSelSortHypotheses_activity.png
                          start
                          partition  #LightSkyBlue "CD_USE_PERSISTENT_HYPOTHESIS_IDS == SWITCH_OFF" \
                          {
                            note
                              Sort hypothesis according to their relevance;
                            end note 
                            : Call selection sort;
                          }
                          partition #LightSkyBlue "CD_USE_PERSISTENT_HYPOTHESIS_IDS == SWITCH_ON" \
                          {
                            note
                            Assign the internal hypothesis to external hypothesis in a persistent way;
                            end note
                            :Init intermediate values;
                            :Assign hypothesis of previous cycle;
                            :Assign remaining hypothesis to free external hypothesis;
                            :Assign remaining hypothesis to the least relevant external hypothesis;
                          }
                          stop
                          @enduml

  @return                 void

  @param[in,out]          None

  @glob_in                @ref ACDC_p_ModCurrentIntHypotheses \n
                          @ref ACDC_p_GetPrevIntHypotheses\n
  @glob_out               @ref ACDC_p_ModCurrentIntHypotheses\n

  @c_switch_part          @ref CD_USE_PERSISTENT_HYPOTHESIS_IDS 
  @c_switch_full          @ref ACDC_CFG_CD

  @pre                    None
  @post                   None

  @InOutCorrelation       see description

  @author                 Andreas Kramer/Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPSELSORTHYPOTHESES_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypSelSortHypotheses(void)
{
  /* Get relevant hypothesis list in an array like format */
  CDIntHypotheses_t  * const pRelHypList = ACDC_p_ModCurrentIntHypotheses();


#if (CD_USE_PERSISTENT_HYPOTHESIS_IDS == SWITCH_OFF)
  CDHypSelSortHypsAccordingToRelevance(pRelHypList->aHyp );
#else

  /* Get previous hypothesis list in an array like format */
  /*PRQA S 0310 1 */ /* Andreas Kramer: Cast from list type to single entry of this list.*/
  CDIntHypotheses_t const * const pPrevHypList     = ACDC_p_GetPrevIntHypotheses();
  boolean                      abExtHypIndexUsed [CD_NUMBER_OF_HYPOTHESES];
  boolean                      abIntHypAssigned  [CD_NUMBER_OF_HYPOTHESES];

  /* Init all arrays */
  CDHypSelSortHypsPersistInit                                 ( pRelHypList->aHyp, abExtHypIndexUsed, abIntHypAssigned);
  /* Assign all internal hypothesis which were already active in the previous cycle */
  CDHypSelSortHypsPersistAssignPreviousHyps                   ( pRelHypList->aHyp, abExtHypIndexUsed, abIntHypAssigned, pPrevHypList->aHyp);
  /* Assign all remaining internal hypothesis to free slots */
  CDHypSelSortHypsPersistAssignRemainHypsToFreeSlots          ( pRelHypList->aHyp, abExtHypIndexUsed, abIntHypAssigned);

/* Here all hypothesis have to be assigned as long as the number of internal hypothesis is equal to the number of hypothesis on the interface. This path may currently never occur. */
#if CD_HYPSEL_USE_MORE_INT_THAN_EXT_HYPS
  /* Assign all remaining internal hypothesis to the slots with lowest priority */
  CDHypSelSortHypsPersistAssignRemainHypsToLeastRelevanceSlots( pRelHypList->aHyp, abExtHypIndexUsed, abIntHypAssigned);
#endif

#endif

}

/*************************************************************************************************************************
  Functionname:         CDHypSelInitExtHypothesis                                                                   */ /*!

  @brief                Init all values of an external hypothesis

  @description          Init all values of an external hypothesis

  @return               void

  @param[in]            iHypID : Id of the considered Hypothesis. @range[0,@ref CDHypothesisType_CyclColl]

  @glob_in              None 
  @glob_out             @ref ACDC_p_ModExtHypothesis

  @c_switch_part        @ref CD_TTM_LONG_INTF_AVAILABLE \n
                        @ref CD_USE_HIGH_QUALITY_LIFETIME \n
                        @ref CD_USE_CUSTOM_ANEC_LONG
  @c_switch_full        None

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDHYPSELINITEXTHYPTHESIS_001\n
                        @ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_001\n
						@ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_002\n
						@ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_003\n
						@ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_004\n
						@ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_005\n
						@ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_006\n
						@ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_007\n
                        @ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_008\n
                        @ref TEST_CDHYPSELCOPYSINGLEINTTOEXTHYPOTHESIS_009\n

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypSelInitExtHypothesis(sint32 iHypID) 
{
  Hypothesis_t *const pHyp      = ACDC_p_ModExtHypothesis(iHypID);

  pHyp->uiObjectRef             = OBJ_INDEX_NO_OBJECT;
  pHyp->eType                   = CDHypothesisType_No;
  pHyp->uiObjectProbability     = 0u;

  pHyp->eEBAObjectClass         = EBAObjectClass_NotAvail;
  pHyp->eEBADynProp             = EBADynProp_NotAvail;
  pHyp->eEBAInhibitionMask      = FPS_EBA_INH_ALL;
  pHyp->uiHypothesisProbability = 0u;
  pHyp->eSensorSource           = EM_GEN_OBJECT_MS_NONE;
  pHyp->fHypothesisLifetime     = 0.0f;
  pHyp->fTTC                    = CD_TIME_MAX;
  pHyp->fTTC2                   = CD_TIME_MAX;
  pHyp->fTTC3                   = CD_TIME_MAX;
  pHyp->fTTC4                   = CD_TIME_MAX;
  pHyp->fTTBPre                 = CD_TIME_MAX;
  pHyp->fTTBAcute               = CD_TIME_MAX;
  pHyp->fTTSPre                 = CD_TIME_MAX;
  pHyp->fTTSAcute               = CD_TIME_MAX;
  pHyp->fLongNecAccel           = 0.0f;
  pHyp->fLatNecAccel            = 0.0f;
  pHyp->fDistX                  = CD_DIST_MAX;
  pHyp->fVrelX                  = 0.0f;
  pHyp->fArelX                  = 0.0f;
  pHyp->fDistY                  = 0.0f;
  pHyp->fVrelY                  = 0.0f;
  pHyp->fArelY                  = 0.0f;
  pHyp->fClosingVelocity        = 0.0f;
#if defined(CD_TTM_LONG_INTF_AVAILABLE) && (CD_TTM_LONG_INTF_AVAILABLE == SWITCH_ON)
  pHyp->fTTMLongPre             = CD_TIME_MAX;
  pHyp->fTTMLongAcute           = CD_TIME_MAX;
#endif /* CD_TTM_LONG_INTF_AVAILABLE */
#if (CD_USE_HIGH_QUALITY_LIFETIME)
  pHyp->Custom.fObjLifeTimeHiQual  = 0.0F;
#endif /* CD_USE_HIGH_QUALITY_LIFETIME */
#if defined (CD_USE_CUSTOM_ANEC_LONG) && (CD_USE_CUSTOM_ANEC_LONG == SWITCH_ON)
  pHyp->Custom.fLongNecAccelCustom = 0.0F;
#endif /* CD_USE_CUSTOM_ANEC_LONG */
}



//!@}
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

