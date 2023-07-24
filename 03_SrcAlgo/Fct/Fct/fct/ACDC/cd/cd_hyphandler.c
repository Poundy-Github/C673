/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hyphandler.c

DESCRIPTION:               The generic hypothesis handling is implemented here

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 13:12:11CEST $

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 1.5

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_GENERIC_HYPOTHIS_HANDLER)

/**
\defgroup cd_hyphandler Hyphandler
\ingroup cd

\brief The Hypothesis Handler creates or confirms hypotheses based on the latest object information. 
Each object is crosschecked with every hypothesis.\n\n

The only external function provided by this module is \ref CDGenHypothesisHandler. It is responsible for the handling 
of several hypothesis of which each describes a certain driving situation. 

  @startuml CDGenHypothesisHandler_activity.png
  title Generic Hypothesis Handler
    start
    if (Ego vehicle moves backward?) then (No)
      while (All Hypotheses handled?) is (No)
        while (All Objects handled?) is (No)
          #Orange:Check if selected object matches
          all entry conditions for the Hypothesis:
          <b>CDGenHypothesisObjectFilter</b> >
          :Call Current Hypothesis handler >
        endwhile (Yes)
      endwhile (Yes)
    else(Yes)
    endif
    stop

  @enduml

    A short description of the actual status of the hypotheses concept can be found here:
    [Hypotheses Concept](https://cws1.conti.de/content/00015821/NoRevMngmt/NCAP18/OneNote/NCAP2018/Base-Hypothesis-Design.one#section-id={9E7BA075-AB5A-40B9-88BF-5667F5510970}&end) \n
    All hypotheses are handled by a generic hypotheses handler (see diagram Generic Hypothesis Handler). In a first step it checks whether the selected object matches all entry conditions  \n
    for a certain hypothesis. To be considered for a hypothesis a Object has to satisfy 3 criteria:
    1. The required EbaHypCat bit of the Object has to be active.
    2. The Eba Object Quality has to be above a certain threshold.
    3. The Object class has to be in the class list of the hypothesis and have a certain confidence. 
    .
    Additionally a object ALLWAYS passes the object filter if it has been in a hypothesis in the previous cycle. \n
    \n
    If an object passes the object filter, it is handed over to the hypothesis' module. Each module consists of at least 3 functions:
    - **Object Filter**: \n
      Additionally to the already mentioned object filter, each hypothesis has an additional function to for object filtering. 
      This function determines which of the previously selected objects exactly match the requirements of the considered hypothesis.
    - **Probability Calculation**: \n
      Calculates the probability for a hypothesis.
    - **Main**: \n
      Controls the information flow during the hypothesis calculation (see diagram Common Hypothesis Process).
    .
    @startuml CommonHypothesisProcess_activity.png
      title Common Hypothesis process
      start
      #Orange:Check specific object filter:
      <b>CDHypo____ObjectFilter </b> >
      if(Object passes filter?) then (Yes)
        #Orange:Change the FPS to the EBA classification:
        <b>CDHypCommonMapFPSToEBAObjClass</b> >
        #Orange:Calculate hypothesis probability:
        <b>CDHypo____CalculateProb</b> >
        if(Hypothesis Probability > Threshold?) then (Yes)
          #Orange:Append hypothesis to existing ones and 
          select the most important hypotheses:
          <b>CDHypSelCreateInternalHypotheses</b> >
        else(No)
        endif
      else(No)
      endif

      
      stop
    @enduml
    
    The selection of the most important hypotheses is executed via the generic function \ref CDHypSelCreateInternalHypotheses. 
    This step reduces the hypotheses existing in parallel and therefore helps saving processing time and storage. \n 
    Whenever a new hypothesis is created and the number of existing hypotheses equals the maximum number of hypotheses, 
    the most critical hypotheses are selected. This implies that one hypothesis is discarded. After all hypothesis types \n
    have been evaluated for the valid objects, the hypotheses are sorted according to their relevance. \n
    An overview of all hypotheses as soon as their object filter conditions can be found below. Additionally the 
    detailed description of every hypothesis is available in its module:
    - The \ref cd_hypacc describes a situation in which the velocity delta between object and ego vehicle is very small.
      This Hypothesis describes especially scenarios with a high object distance. \n
    - The \ref cd_hypcollision describes a situation in which a collision in close future (<<1s) is highly probable.
    - \ref cd_hypcommon
    - The \ref cd_hypcrossing describes a situation in which the Object is currently not in the ego trajectory, 
      but follows a trajectory that will lead to a collision of the ego vehicle and the object if both keep their kinematics.
    - The \ref cd_hypcutin describes a situation in which the ego vehicle approaches a slower object that is not 
      directly located in the ego trajectory but in one of the side lanes. A collision can only occur if either 
      the ego vehicle changes its course or the object its Y-position. \n
    - The \ref cd_hypcyclecoll describes a situation in which a cyclist crosses the ego trajectory with an angle of 
      more or less 90�. If both ego vehicle and cyclist keep their kinematics, a collision will occur.
    - The \ref cd_hyplong is an attempt to generically handle all hypotheses that refer to objects moving in the same 
      direction as the ego vehicle \n
    - The \ref cd_hyppass describes a situation in which a object overtakes the ego vehicle. A Cut-In scenario is possible.
    - The \ref cd_hyppedcoll describes a situation in which a pedestrian crosses before the ego vehicle. If both, 
      the ego vehicle and the pedestrian keep their kinematics, a collision will occur.
    - The \ref cd_hyprunup describes a situation in which the ego vehicle approaches any kind of slower object 
      (moving or stationary) which is located in the ego trajectory.
    - \ref cd_hyprunupstationary 
    - The \ref cd_hypstatic describes a situation in which the ego vehicle follows an object with a close distance 
      at a low delta velocity. The distance is below the prescribed one.
\{
*/

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/
static boolean CDGenCheckObjClass         (CDHypoHandlerClassFilter_t const * const pClassFilter,  ObjNumber_t const iObjectIndex);
static boolean CDGenCheckObjInPrevHypList (CDHypoHandler_t const * const pCurHypHandler,           ObjNumber_t const iObjectIndex);
static boolean CDGenHypothesisObjectFilter(CDHypoHandler_t const * const pCurHypHandler,           ObjNumber_t const iObjectIndex);

/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDGenCheckObjInPrevHypList                                                                   */ /*!

  @brief                Checks whether the specified object was used in the same hypothesis type in the last cycle.

  @description          Functions follows the subsequent steps:
                        @startuml CDGenCheckObjInPrevHypList_activity.png
                        start
                          :Set flag to false;
                          while (All previous hypotheses handled?) is (No)
                            if(Object was in previous hypothesis? \nAND Hypothesis was of the same type as current one?) then (Yes)
                              :1}
                              :Set flag to true;
                            else(No)
                              :2}
                            endif
                          endwhile (Yes)
                          :Return flag;
                        stop
                        @enduml

  @return               boolean : True if object was used in the same hypothesis type in the last cycle.

  @param[in]            pCurHypHandler :  Pointer to the current hypothesis handler
  @param[in]            iObjectIndex :    Index of the considered object. \range [0,...]

  @glob_in              @ref ACDC_p_GetPrevIntHypotheses\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GENERIC_HYPOTHIS_HANDLER

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDGENCHECKOBJINPREVHYPLIST_001 \n
                        @ref TEST_CDGENCHECKOBJINPREVHYPLIST_002 \n
						@ref TEST_CDGENCHECKOBJINPREVHYPLIST_003

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDGenCheckObjInPrevHypList(CDHypoHandler_t    const * const pCurHypHandler,
                                          ObjNumber_t const iObjectIndex)
{
  uint32  uiPrevHypIndex;
  boolean bObjInPrevHypList   = b_FALSE;
  CDIntHypotheses_t const * const pPrevHypothesisList = ACDC_p_GetPrevIntHypotheses();
  uint32  uMaxNumOfHypothesis = MIN(pPrevHypothesisList->uNumOfHyps,CD_NUMBER_OF_HYPOTHESES);
  uint32  uPrevHypTypeMask;

  /* Loop over all hypothesis of the previous cycle */
  for ( uiPrevHypIndex = 0;  (bObjInPrevHypList == b_FALSE) && (uiPrevHypIndex < uMaxNumOfHypothesis); uiPrevHypIndex++ )
  {
    /* Get the pointer to the previous hypothesis specified in the loop counter */
    CDIntHypothesis_t const * const pPrevHypo = &(pPrevHypothesisList->aHyp[uiPrevHypIndex]);
    /* Get the type of the current previous hypothesis. 
    The type has to be converted to a bitfield in the same way as its done in the Hypothesis handler definition*/
    uPrevHypTypeMask = ((uint32)1u << (uint32)pPrevHypo->eType);
    /* Check whether this object was used in the previous hypothesis and whether the hypothesis has the same type as the current one */ 
    if (    ( pPrevHypo->iObjectRef                                   == iObjectIndex )
         && ( CML_GetBit(pCurHypHandler->uiHypTypes,uPrevHypTypeMask) == b_TRUE         ) )
    {
      /* The object was used in the last cycle */
      bObjInPrevHypList = b_TRUE;
    }
  }
  return bObjInPrevHypList;
}

/*************************************************************************************************************************
  Functionname:         CDGenCheckObjClass                                                                           */ /*!

  @brief                Checks whether the object has a class which is specified in the class filter of a hypothesis.

  @description          The function compares the objects class to the hypothesis' class filter.
                        Therefore the following steps are executed:
                        \startuml CDGenCheckObjClass_activity.png
                          start
                            if (Hypothesis class filter is off?) then (No)
                              if(Objects class confidence is above threshold?) then (Yes)
                                :Compare object class to all 
                                classes of the hypothesis filter;
                                if(One class matches?) then (Yes)
                                  :1}
                                  :Return **true**;
                                else(No)
                                  :2}
                                  #Yellow:<b>ACDC_ASSERT</b>|
                                  :Return **false**;
                                endif
                              else(No)
                                :3}
                                :Return **false**;
                              endif
                            else(Yes)
                              :4}
                              :Return **true**;
                            endif
                          stop
                        \enduml

  @return               static boolean : True if object class matches a class of the hypothesis' class filter

  @param[in]            pClassFilter : Class filter of an hypothesis
  @param[in]            iObjectIndex : index of the considered object. \range [0,...]

  @glob_in              @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetEMGenObjQualifiers
  @glob_out             None

  @c_switch_part        @ref EM_GEN_OBJECT_INTFVER \n
  @c_switch_full        @ref ACDC_CFG_CD  \n
                        @ref CD_USE_GENERIC_HYPOTHIS_HANDLER  \n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDGENCHECKOBJCLASS_001 \n
                        @ref TEST_CDGENCHECKOBJCLASS_002 \n
                        @ref TEST_CDGENCHECKOBJCLASS_003 \n
                        @ref TEST_CDGENCHECKOBJCLASS_004 \n
						@ref TEST_CDGENCHECKOBJCLASS_005

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDGenCheckObjClass(CDHypoHandlerClassFilter_t const * const pClassFilter, ObjNumber_t const iObjectIndex)
{
  boolean bClassValid = b_FALSE;

  /* Check whether class filter is off (the pointer to the class handler structure is set to NULL) */
  if (pClassFilter == NULL)
  {
    bClassValid = b_TRUE;
  }
  else
  {
    /* Check class confidence */
    if (ACDC_p_GetEMGenObjAttributes(iObjectIndex)->uiClassConfidence >= pClassFilter->uMinClassConfidence)
    {
      /* Check whether there is at least one class specified */
      if (pClassFilter->uNumOfClasses > 0u)
      { 
        /* Check whether object class is in the positive list */
        uint32                       uiClassFilterIdx;
        CDHypFilterClass_t           eFilterClass;
        CDHypFilterClass_t           eObjClass;
#if (EM_GEN_OBJECT_INTFVER >= 13)
        eObjClass = ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->eEbaObjClass;
#else
        eObjClass = ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eClassification;
#endif
        
        /* Loop over list of all classes in class list */
        for( uiClassFilterIdx = 0u; (uiClassFilterIdx < pClassFilter->uNumOfClasses) && (bClassValid == b_FALSE); ++uiClassFilterIdx )
        {
          /* Get one class of positive list */
          eFilterClass = pClassFilter->aClassFilter[uiClassFilterIdx];

          /* Compare this class with current object class */
          if ( eFilterClass == eObjClass )
          {
            bClassValid = b_TRUE;
          }
        }
      }
      else
      {
        /* No class is specified. This hypothesis will never be reached */
        ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
      }
    }
  }
  return bClassValid;
}

/*************************************************************************************************************************
  Functionname:         CDGenHypothesisObjectFilter                                                                  */ /*!

  @brief                Check whether this object fulfills all conditions to be used for the current hypothesis type.

  @description          Check whether this object fulfills all conditions to be used for the current hypothesis type.
                        Therefore the object is checked for previous usage, hypothesis category, quality and class. \n
                        The function follows the subsequent steps:
                        \startuml CDGenHypothesisObjectFilter_activity.png
                        start
                          #Orange: Check if object was used in the same 
                          hypothesis in the previous cycle:
                          <b>CDGenCheckObjInPrevHypList</b> >
                          if (Check passed?) then (Yes)
                            :1}
                            :**Filter passed**;
                          else (No)
                            :Check Objects HypCat;
                            note right: Objects HypCat is permits the hypothesis?

                            :Check Objects Quality;
                            note right: Objects Eba Quality is above threshold?

                            #Orange:Check Objects Class:
                            <b>CDGenCheckObjClass</b> >
                            note right: Objects class matches a class of the hypothesis filter?
                            
                            if(All checks passed?) then (Yes)
                              :2}
                              :**Filter passed**;
                            else(No)
                              :3}
                              :**Filter not passed**;
                            endif
                          endif
                        stop
                        \enduml

  @return               static boolean

  @param[in]            pCurHypHandler :  Pointer to the current hypothesis handler
  @param[in]            iObjectIndex :    Object ID

  @glob_in              @ref ACDC_p_GetEMGenObjQualifiers
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD  \n
                        @ref CD_USE_GENERIC_HYPOTHIS_HANDLER  \n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDGENHYPOTHESISOBJECTFILTER_001 \n
                        @ref TEST_CDGENHYPOTHESISOBJECTFILTER_002 \n
                        @ref TEST_CDGENHYPOTHESISOBJECTFILTER_003 \n
						@ref TEST_CDGENHYPOTHESISOBJECTFILTER_004 \n
						@ref TEST_CDGENHYPOTHESISOBJECTFILTER_005 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDGenHypothesisObjectFilter(CDHypoHandler_t const * const pCurHypHandler,
                                           ObjNumber_t const iObjectIndex)
{
  boolean bObjFilterMatched = b_TRUE;
  boolean bObjInPrevHypList;

  /* check whether the object was already used in a hypothesis in the last cycle */
  bObjInPrevHypList = CDGenCheckObjInPrevHypList( pCurHypHandler, iObjectIndex);

  /* If the object was already used, no more conditions have to be checked. It is valid again */
  if( bObjInPrevHypList == b_FALSE )
  {
    /* Object will create a new hypothesis. Check all entry conditions now */
    
    EM_t_GenObjQualifiers const * pObjQualifier = ACDC_p_GetEMGenObjQualifiers(iObjectIndex);
    
      /* Check hypothesis category from FPS */
    if ( ( ((uint32)pCurHypHandler->bitHypCat) & ((uint32)pObjQualifier->eEbaHypCat) ) == 0u )
    {
      bObjFilterMatched = b_FALSE;
    }
    /* Check eba quality */
    else if (pObjQualifier->uiEbaObjQuality < pCurHypHandler->uiGenObjQuality)
    {
      bObjFilterMatched = b_FALSE;
    }
    else
    {
      /* Check whether class is in the positive list */
      bObjFilterMatched = CDGenCheckObjClass(pCurHypHandler->pClassFilter, iObjectIndex);
    }
  }

  return bObjFilterMatched;
}


/*************************************************************************************************************************
  Functionname:         CDGenHypothesisHandler                                                                       */ /*!

  @brief                The Hypothesis Handler creates or confirms hypotheses based on the latest object information. 
                        Each object is crosschecked with every hypothesis.\n\n

  @description          Manages the call of all hypothesis calculations. Loops for each hypothesis over all objects, 
                        executing two steps for each:
                        - Check of the hypothesis entry conditions for each object: @ref CDGenHypothesisObjectFilter
                        - Call the hypothesis calculation for each object.
                        .
                        For more information about the hypothesis creation see the module description of the module @ref cd_hyphandler.
                        \image html CDGenHypothesisHandler_activity.png

  @return               void

  @param[in,out]        None

  @glob_in              @ref ACDC_p_GetVDYDynObjSync \n
                        @ref ACDC_b_GetEMGenObjIsDeleted
  @glob_out             None

  @c_switch_part        @ref CD_HYP_HANDLERS_NO
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GENERIC_HYPOTHIS_HANDLER

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDGENHYPOTHESISHANDLER_001 \n
                        @ref TEST_CDGENHYPOTHESISHANDLER_002

  @traceability         Design Decision

*************************************************************************************************************************/
void CDGenHypothesisHandler(void) 
{
#if (CD_HYP_HANDLERS_NO > 0u)
  uint32      uiHypHandlerIdx;
  sint32      iObjectIndex;
  boolean     bObjFilterMatched;

  /* No hypothesis shall be created or kept if the ego vehicle moves backward */
  if (ACDC_p_GetVDYDynObjSync()->MotionState.MotState != VDY_LONG_MOT_STATE_MOVE_RWD)
  {
    /************************************************************************/
    /* Object processing                                                    */
    /************************************************************************/
    
    /* Loop over all active hypothesis */
    /*PRQA S 3493,3494 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    for( uiHypHandlerIdx = 0u; uiHypHandlerIdx < (uint32)CD_HYP_HANDLERS_NO; uiHypHandlerIdx++ )
    {
      /* Get the pointer to the current hypothesis */
      const CDHypoHandler_t * const pCurHypHandler = CD_HYP_HANDLERS[ uiHypHandlerIdx ];


      /* Check whether the needed pointer exists */
      if(    (pCurHypHandler               != NULL )
          && (pCurHypHandler->fpHypHandler != NULL ) )
      {
        /* Set the start checkpoint for the runtime analysis */
        ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, pCurHypHandler->uRTACheckpoint, 0);

        /* Loop over all objects */
        for(iObjectIndex = ((sint32)EM_N_OBJECTS-1); iObjectIndex >= 0; --iObjectIndex)
        {
          if (ACDC_b_GetEMGenObjIsDeleted((ObjNumber_t)iObjectIndex) == b_FALSE)
          {
            /* Check whether the object matches all entry conditions for the hypothesis */
            bObjFilterMatched = CDGenHypothesisObjectFilter(pCurHypHandler, (ObjNumber_t)iObjectIndex);
            
            /* Call the main function of the specified hypothesis */
            pCurHypHandler->fpHypHandler( (ObjNumber_t)iObjectIndex, bObjFilterMatched);
          }
        }

        /* Set the stop checkpoint for the runtime analysis */
        ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, pCurHypHandler->uRTACheckpoint, 0);
      }
      else
      {
        /* The hypothesis is called but not configured correctly */
        ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
      }
    }

#if CD_USE_HYPOTHESIS_RELATION
    /************************************************************************/
    /* Post processing                                                      */
    /************************************************************************/

    /* Loop over all active hypothesis */
    /*PRQA S 3493 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    for( uiHypHandlerIdx = 0u; uiHypHandlerIdx < (uint32)CD_HYP_HANDLERS_NO; uiHypHandlerIdx++ )
    {
      /* Get the pointer to the current hypothesis */
      const CDHypoHandler_t * const pCurHypHandler = CD_HYP_HANDLERS[ uiHypHandlerIdx ];

      /* Check whether the needed pointer exists */
      if(    (pCurHypHandler                   != NULL )
          && (pCurHypHandler->fpHypPostHandler != NULL ) )
      {
        /* Call the post processing function of the specified hypothesis */
        pCurHypHandler->fpHypPostHandler();
      }
    }
#endif
  }

#endif /* #if (CD_HYP_HANDLERS_NO > 0u) */
}

/// \}
#endif
#endif

