/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD (Collision Detection)

PACKAGENAME:               cd_customfunctions.c

DESCRIPTION:               Implementation of the custom functions for CD (Collision Detection)

AUTHOR:                    $Author: Kanthi, Sheetal (uia80691) (uia80691) $

CREATION DATE:             $Date: 2019/06/13 17:52:04CEST $

VERSION:                   $Revision: 1.24 $

LEGACY_VERSION:            Revision: 1.65
  
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
@defgroup cd_customfunctions Customfunctions
@ingroup cd
@brief              Provides customer specific functions.\n\n
@description        The following functionalities are provided by this module:
                    - Initialization of the customer specific data: @ref CDInitCustomerData
                    - Main function to execute customer specific functions: @ref CDCalcCustomerFunctions
                    - Estimation if a pedestrian is out- or inside of the road: @ref CDPedIsOutsideRoadEstimation
                    - Call of the Customer specific hypothesis handler: @ref CDCustomerHypothesisHandler
@{
*/
/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

#if (FCT_CFG_CD_MSA_SELECTION)
static ObjNumber_t CDCustomSelectMSAObject (void);
static void CDCustomFillMSAOutput (ObjNumber_t iObjectIndex);
#endif /* (FCT_CFG_CD_MSA_SELECTION) */
#if (CD_USE_GENERIC_HYPOTHIS_HANDLER == SWITCH_OFF)
static boolean CDCheckObjectFilter(const CDHypoHandler_t * const pCurHypHandler,
                                   const ObjNumber_t iObjectIndex);
#endif /* (CD_USE_GENERIC_HYPOTHIS_HANDLER == SWITCH_OFF) */

/*************************************************************************************************************************
  Functionname:         CDInitCustomerData                                                                           */ /*!

  @brief                Initialize all customer specific data.

  @description          Currently this function is empty. Nevertheless it is kept and can be filled if necessary.

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 Customer specific data initialized.

  @author               Christian Gutmann
*************************************************************************************************************************/
void CDInitCustomerData( void )
{

}

#if (CD_USE_GENERIC_HYPOTHIS_HANDLER == SWITCH_OFF)
/*************************************************************************************************************************
  Functionname:         CDCheckObjectFilter                                                                          */ /*!

  @brief                Checks for all objects if they match the object filter of a certain hypothesis.

  @description          This function is only used if the @ref CDGenHypothesisObjectFilter is turned off.
                        The following conditions are checked for every object:
                        - Objects EBAQuality
                        - Objects class and class confidence
                        @startuml CDCheckObjectFilter_activity.png
                        start
                          if(Object has minimum Quality and class confidence?) then (Yes)
                            
                            if(Object was in the same hypothesis in the last cycle?) then (No)
                              :Check if objects HypCat is relevant 
                              for the current hypothesis;
                              :Check if objects Class is relevant 
                              for the current hypothesis;
                              if(Checks passed?) then (Yes)
                                :Object filter matched;
                              else(No)
                                :Object filter not matched;
                              endif
                            else(Yes)
                              :Object filter matched;
                            endif
                          else(No)
                            :Object filter not matched;
                          endif
                        stop
                        @enduml
  @return               boolean

  @param[in]            pCurHypHandler :    Hypothesis handler of the current hypothesis.
  @param[in]            iObjectIndex :      Index of the considered object. @range [0,+...[

  @glob_in              @ref ACDC_b_GetEMGenObjIsDeleted  \n
                        @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetEMGenObjQualifiers \n
                        @ref ACDC_p_GetPrevIntHypotheses
  @glob_out             None

  @c_switch_part        @ref EM_GEN_OBJECT_LIST_INTFVER
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GENERIC_HYPOTHIS_HANDLER

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Jakob
*************************************************************************************************************************/
static boolean CDCheckObjectFilter(const CDHypoHandler_t    * const pCurHypHandler,
                                   const ObjNumber_t                iObjectIndex)
{
  boolean bObjFilterMatched = FALSE;
  
  /* check relevant qualities and class conf. > min. required class conf. */
  if(    (   ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->uiEbaObjQuality   >= pCurHypHandler->uiGenObjQuality                  )
      && ( !(ACDC_b_GetEMGenObjIsDeleted(iObjectIndex) )                                                                       )
      && (   ACDC_p_GetEMGenObjAttributes(iObjectIndex)->uiClassConfidence >= pCurHypHandler->pClassFilter->uMinClassConfidence) )
  {
    CDIntHypotheses_t const * const pPrevHypothesisList = ACDC_p_GetPrevIntHypotheses();
    EM_t_GenObjClassification  eClass;
    uint8   uiPrevHypIndex;
    boolean bObjInPrevHypList = FALSE;
    uint8   uiClassFilterCnt;
    uint8   uiClassFilterIdx;
    bObjFilterMatched = TRUE;

    /* If iObjectIndex matches one iObjectRef in rgPreviousHypothesesList for the current
    hypothesis the hypothesis must be evaluated without check of rgClassFilter. */
    for ( uiPrevHypIndex = 0; 
      (bObjInPrevHypList == FALSE) 
      && (uiPrevHypIndex < pPrevHypothesisList->uNumOfHyps) 
      && (uiPrevHypIndex < CD_NUMBER_OF_HYPOTHESES); 
    uiPrevHypIndex++ )
    {
      CDIntHypothesis_t const * const currentPrevHypo = &(pPrevHypothesisList->aHyp[uiPrevHypIndex]);
      if (    ( ( ((uint32)(pCurHypHandler->uiHypTypes)) & (1u << (uint32)currentPrevHypo->eType) ) > 0 ) 
           && ( iObjectIndex == currentPrevHypo->iObjectRef ) )
      {
        bObjInPrevHypList = TRUE;
      }
    }

    /* check classification filter only if object has not already been in previous hypothesis
    list and the class filter for the current hypothesis is valid */
    if( bObjInPrevHypList == FALSE )
    {
      /* check hypothesis category from FPS */
      if ( ( ((uint32)pCurHypHandler->bitHypCat) & ((uint32)ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->eEbaHypCat) ) == 0 )
      {
        bObjFilterMatched = FALSE;
      }

      /* maybe check the classification */
      uiClassFilterCnt = pCurHypHandler->pClassFilter->uNumOfClasses;

      /* check classification filter if the class confidence is high enough and the class 
      filter for the current hypothesis is valid */
      if (    ( bObjFilterMatched            == TRUE )
           && ( pCurHypHandler->pClassFilter != NULL )
           && ( uiClassFilterCnt              > 0u   ) )
      {
        /* for positive filter, filter match should be FALSE until object class is found, 
        for negative filter, filter match should be TRUE until object class is found */
        bObjFilterMatched = FALSE;

        for( uiClassFilterIdx = 0u; (uiClassFilterIdx < uiClassFilterCnt) && (bObjFilterMatched == FALSE); uiClassFilterIdx++ )
        {
          eClass = pCurHypHandler->pClassFilter->aClassFilter[ uiClassFilterIdx ]; /*PRQA S 0491*//*array with known length*/

          /* check if class is in filter */
#if (EM_GEN_OBJECT_LIST_INTFVER >= 13)
          if (ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->eEbaObjClass == eClass )
#else
          if( ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eClassification == eClass )
#endif
          {
            bObjFilterMatched = TRUE;
          }
        }
      }
    }
  }
  
  return bObjFilterMatched;
}

/*************************************************************************************************************************
  Functionname:         CDCustomerHypothesisHandler                                                                  */ /*!

  @brief                Customer specific hypothesis handler

  @description          Matches in its main steps the Generic Hypothesis handler (@ref CDGenHypothesisHandler).
                        The main difference is that instead of the function @ref CDGenHypothesisObjectFilter,  \n
                        the customer specific function @ref CDCheckObjectFilter is called.

  @attention            The hypothesis handlers must be executed in specfic order. Otherwise the hypothesis selection 
                        will fail. Each hypothesis handler must be called for all relevant object before the next handler \n
                        is considered. Also there is an order between the handlers which is determined by the selection
                        algorithm.

  @return               void

  @param[in,out]        None

  @glob_in              @ref ACDC_p_GetVDYDynRaw\n
                        @ref CD_HYP_HANDLERS\n
  @glob_out             None

  @c_switch_part        @ref CD_HYP_HANDLERS_NO
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GENERIC_HYPOTHIS_HANDLER

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich
*************************************************************************************************************************/
void CDCustomerHypothesisHandler(void)
{
#if (CD_HYP_HANDLERS_NO > 0u)
  uint8 uiHypHandlerIdx;
  ObjNumber_t iObjectIndex;
  boolean bObjFilterMatched;

  if (ACDC_p_GetVDYDynRaw()->MotionState.MotState != VDY_LONG_MOT_STATE_MOVE_RWD)
  {
    /*PRQA S 3493 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    for( uiHypHandlerIdx = 0u; uiHypHandlerIdx < (uint32)CD_HYP_HANDLERS_NO; uiHypHandlerIdx++ )
    {
      const CDHypoHandler_t * const pCurHypHandler = CD_HYP_HANDLERS[ uiHypHandlerIdx ];
      if( pCurHypHandler != NULL )
      {
        if( pCurHypHandler->fpHypHandler != NULL )
        {
          ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, pCurHypHandler->uRTACheckpoint, 0);
          /* for all objects try to calculate hypothesis */
          for(iObjectIndex = 0; iObjectIndex < EM_N_OBJECTS; iObjectIndex++)
          {
            bObjFilterMatched = CDCheckObjectFilter(pCurHypHandler, iObjectIndex);
            /* call the hypothesis handler */
            pCurHypHandler->fpHypHandler( iObjectIndex, bObjFilterMatched);
          }
          ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, pCurHypHandler->uRTACheckpoint, 0);
        }
      }
    }
  }

#endif /* #if (CD_HYP_HANDLERS_NO > 0u) */
}
#endif

/*************************************************************************************************************************
  Functionname:         CDCalcCustomerFunctions                                                                      */ /*!

  @brief                Executes the calculation of all customer specific functions.

  @description          The currently called customer functions are:
                        - MSA: @ref CDCustomFillMSAOutput and @ref CDCustomSelectMSAObject

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_CD_MSA_SELECTION
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @author               Andreas Hartmann
*************************************************************************************************************************/
void CDCalcCustomerFunctions (void)
{
#if (FCT_CFG_CD_MSA_SELECTION)
  const ObjNumber_t iNearestObj = CDCustomSelectMSAObject();
  CDCustomFillMSAOutput(iNearestObj);
#endif

}

#if( FCT_CFG_ROAD_INPUT)
#if ((CD_PED_USE_EM_ROAD_ESTIMATION) || (CD_BICYCLE_USE_EM_ROAD_ESTIMATION))
/*************************************************************************************************************************
  Functionname:         CDPedIsOutsideRoadEstimation                                                                 */ /*!

  @brief                Checks if an Pedestrian object is on the Road according to the Road estimation

  @description          For each road boarder is checked, if the pedestrian is in- or outside. If the following 
                        criteria are fulfilled, the pedestrian is outside of a boarder:
                        - The road boarder confidence is above threshold.
                        - The lateral distance of the pedestrian is above a minimum value.
                        - The lateral distance of the pedestrian is below a maximum value.
                        - The difference between minimum and maximum value is above threshold.
                        - The lateral distance of the pedestrian is above the estimated road border.
                        .
                        For each side one flag is set to indicate if the pedestrian is detected outside of the corresponding border.
                        If one of the two flags is set, the pedestrian is outside of the road.
                        @startuml CDPedIsOutsideRoadEstimation_activity.png
                        start
                          :Calculate Y Positions of the Road 
                          trajectory at the X of the Pedestrian;
                          note left: >See formula "Road Border"
                          :Check Tracking Status;
                          :Check if road has sufficient confidence 
                          and the required range;
                          :Check if pedestrian is outside of
                          left and right road border;
                          if(All Checks passed?) then (Yes)
                            :The Pedestrian is outside of the road;
                          else(No)
                            :A statement about the pedestrians
                            position is not possible;
                          endif
                        stop
                        @enduml
  @return               boolean : True if pedestrian is outside of the road.

  @param[in]            iObjectIndex : Index of the considered object. @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref EM_ROAD_INTFVER
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref FCT_CFG_ROAD_INPUT \n
                        @ref CD_BICYCLE_USE_EM_ROAD_ESTIMATION \n
                        @ref CD_PED_USE_EM_ROAD_ESTIMATION

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Road Border:** \n
                          \f$Y_{RoadBorder,Left} = (Curve \cdot 0.5 \cdot X_{Ped}^2) + X_{RoadTrajOffset,Left}\f$ \n
                          \f$Y_{RoadBorder,Right}= (Curve \cdot 0.5 \cdot X_{Ped}^2) + X_{RoadTrajOffset,Right}\f$

  @testmethod           @Generic_Testmethods

  @author               Patrick Hielscher
*************************************************************************************************************************/
boolean CDPedIsOutsideRoadEstimation(ObjNumber_t iObjectIndex )
{
  fDistance_t fDistXPed;
  fDistance_t fDistYPed;
  float32 fRoadBorderRefY;
  float32 fRoadBorderRefYRight;
  float32 fRoadBorderRefYLeft;
  boolean bPedOutsideRoad = FALSE;
  boolean bPedOutsideRoadLeft = FALSE;
  boolean bPedOutsideRoadRight = FALSE;

  fDistXPed = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
  fDistYPed = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fY;

#if (EM_ROAD_INTFVER >= 2U)
  if ( (GET_ROAD_ESTIMATION)->CoupledRoad.u_GlobalTrackingStatus >= CD_PED_ROAD_EST_MIN_TRACKSTAT )
#else
  if ( (GET_ROAD_ESTIMATION)->Legacy.uiTrackingStatus >= CD_PED_ROAD_EST_MIN_TRACKSTAT )
#endif
  {
#if (EM_ROAD_INTFVER >= 2U)
    fRoadBorderRefY = (GET_ROAD_ESTIMATION)->CoupledRoad.ClothoidParams.f_Curvature * (SQR(fDistXPed) * 0.5f);
#else
    fRoadBorderRefY = (GET_ROAD_ESTIMATION)->fC0 * (SQR(fDistXPed) * 0.5f);
#endif

    /* Check Left Side Road Border */
#if (EM_ROAD_INTFVER >= 2U)
    if ( ((GET_ROAD_ESTIMATION)->RoadBorderLeft.QualityMeas.u_TrackingStatus >= CD_PED_ROAD_EST_MIN_TRACKSTAT)
      && (ROAD_GET_CR_CONFIDENCE_LEFT >= CD_PED_ROAD_EST_MIN_CONF)
      && ((ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED - ROAD_GET_CR_MIN_X_LEFT) >= CD_PED_ROAD_MIN_RANGE)
      && (ROAD_GET_CR_MIN_X_LEFT < fDistXPed)
      && (ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED > fDistXPed)
#else
    if ( ((GET_ROAD_ESTIMATION)->Legacy.uiTrackingStatusLeft >= CD_PED_ROAD_EST_MIN_TRACKSTAT)
      && (ROAD_GET_CONFIDENCE_LEFT >= CD_PED_ROAD_EST_MIN_CONF)
      && ((ROAD_GET_MAX_X_LEFT_COMPENSTATED - ROAD_GET_MIN_X_LEFT) >= CD_PED_ROAD_MIN_RANGE)
      && (ROAD_GET_MIN_X_LEFT < fDistXPed)
      && (ROAD_GET_MAX_X_LEFT_COMPENSTATED > fDistXPed)
#endif
      )
    {
#if (EM_ROAD_INTFVER >= 2U)
      fRoadBorderRefYLeft = fRoadBorderRefY + (GET_ROAD_ESTIMATION)->RoadBorderLeft.f_LateralOffset;
#else
      fRoadBorderRefYLeft = fRoadBorderRefY + (GET_ROAD_ESTIMATION)->Legacy.fYLeft;
#endif
      if ( fDistYPed >= (fRoadBorderRefYLeft - CD_PED_ROAD_MIN_DIST_TO_BORDER) )
      {
        bPedOutsideRoadLeft = TRUE;
      }
      else
      {
        bPedOutsideRoadLeft = FALSE;
      }
    }
    else
    {
      bPedOutsideRoadLeft = FALSE;
    }

    /* Check Right Side Road Border */
#if (EM_ROAD_INTFVER >= 2U)
    if ( ((GET_ROAD_ESTIMATION)->RoadBorderRight.QualityMeas.u_TrackingStatus >= CD_PED_ROAD_EST_MIN_TRACKSTAT)
      && (ROAD_GET_CR_CONFIDENCE_RIGHT >= CD_PED_ROAD_EST_MIN_CONF)
      && ((ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED - ROAD_GET_CR_MIN_X_RIGHT) >= CD_PED_ROAD_MIN_RANGE)
      && (ROAD_GET_CR_MIN_X_RIGHT < fDistXPed)
      && (ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED > fDistXPed)
#else
    if ( ((GET_ROAD_ESTIMATION)->Legacy.uiTrackingStatusRight >= CD_PED_ROAD_EST_MIN_TRACKSTAT)
      && (ROAD_GET_CONFIDENCE_RIGHT >= CD_PED_ROAD_EST_MIN_CONF)
      && ((ROAD_GET_MAX_X_RIGHT_COMPENSTATED - ROAD_GET_MIN_X_RIGHT) >= CD_PED_ROAD_MIN_RANGE)
      && (ROAD_GET_MIN_X_RIGHT < fDistXPed)
      && (ROAD_GET_MAX_X_RIGHT_COMPENSTATED > fDistXPed)
#endif
      )
    {
#if (EM_ROAD_INTFVER >= 2U)
      fRoadBorderRefYRight = fRoadBorderRefY + (GET_ROAD_ESTIMATION)->RoadBorderRight.f_LateralOffset;
#else
      fRoadBorderRefYRight = fRoadBorderRefY + (GET_ROAD_ESTIMATION)->Legacy.fYRight;
#endif
      if ( fDistYPed <= (fRoadBorderRefYRight + CD_PED_ROAD_MIN_DIST_TO_BORDER) )
      {
        bPedOutsideRoadRight = TRUE;
      }
      else
      {
        bPedOutsideRoadRight = FALSE;
      }
    }
    else
    {
      bPedOutsideRoadRight = FALSE;
    }
  }
  else
  {
    bPedOutsideRoadLeft = FALSE;
    bPedOutsideRoadRight = FALSE;
  }

  bPedOutsideRoad = bPedOutsideRoadLeft | bPedOutsideRoadRight;

  return bPedOutsideRoad;
}
#endif /* #if ((CD_PED_USE_EM_ROAD_ESTIMATION) || (CD_BICYCLE_USE_EM_ROAD_ESTIMATION)) */
#endif /* FCT_CFG_ROAD_INPUT*/

#if (FCT_CFG_CD_MSA_SELECTION)
/*************************************************************************************************************************
  Functionname:         CDCustomSelectMSAObject                                                                      */ /*!

  @brief                Get Customer Specific MSA Object (MFS430BW16)

  @description          Selects of all non oncoming Car, Truck or motorcycle objects which are directly ahead of 
                        the ego vehicle the one with the smallest X-distance. \n
                        An object is directly ahead if its y-distance is smaller than the sum of the half ego 
                        and the half object width.
                        @startuml CDCustomSelectMSAObject_activity.png
                        start
                          if(SigStatus of GenObjectList is OK?) then (Yes)
                            partition "Execute for all objects" {
                              if(Object is oncoming vehicle?
                                 AND Object is directly ahead of the ego vehicle?
                                 AND Object is the closest in X Direction?) then (Yes)
                                 :1}
                                 :Select object as MSA object;
                              else(No)
                                :2}
                              endif
                            }
                          else(No)
                            :3}
                            :No MSA Object selected;
                          endif
                          :Return MSA object;
                        stop
                        @enduml

  @return               ObjNumber_t : Index of the selected MSA Object. @range [0,+...[

  @param[in]            void

  @glob_in              @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetObjGeometry \n
                        @ref ACDC_p_GetObjPositions\n

  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref FCT_CFG_CD_MSA_SELECTION

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Hartmann
*************************************************************************************************************************/
static ObjNumber_t CDCustomSelectMSAObject (void)
{
  float32 fNextDist = 0;
  ObjNumber_t iObjectIndex;
  ObjNumber_t iNearestObjectID = OBJ_INDEX_NO_OBJECT;


  if (pObjectData->pGenObjList->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
  {
    /* select nearest distX object */
    for(iObjectIndex=0 ; iObjectIndex < EM_N_OBJECTS ; iObjectIndex++)
    {
      EM_t_GenObjAttributes const * const pEmObjAttributes = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
      float32               const         fObjectWidth     = ACDC_p_GetObjGeometry(iObjectIndex)->fWidth;

      if ( pEmObjAttributes->eDynamicProperty != EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING)
      {
        if (    (pEmObjAttributes->eClassification == (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_CAR       )
             || (pEmObjAttributes->eClassification == (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_TRUCK     )
             || (pEmObjAttributes->eClassification == (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_MOTORCYCLE) )
        {
          const float32 fDistY = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fY;
          if( (fABS(fDistY) - (0.5f*fObjectWidth)) <= ACDC_COMMON_EGO_WIDTH)/*PRQA S 3121*//*physical constant*/
          {
            if ( (OBJ_INDEX_NO_OBJECT == iNearestObjectID) || (ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX <= fNextDist))
            {
              fNextDist        = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
              iNearestObjectID = iObjectIndex;
            }
          }
        }
      }
    } /* end for */
  } /* end if eSigStatus */
  return iNearestObjectID;
}

/*************************************************************************************************************************
  Functionname:         CDCustomFillMSAOutput                                                                        */ /*!

  @brief                Fills the MSA Connected output structure.

  @description          Fills the MSA connected structure of the cd custom output with the information of the
                        found MSA object.

  @return               void

  @param[in]            iObjectIndex : Index of the MSA object. @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjGeometry \n
                        @ref ACDC_p_GetObjMovement  \n
                        @ref ACDC_p_GetObjPositions\n
  @glob_out             @ref ACDC_p_GetCDCustomOutput

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref FCT_CFG_CD_MSA_SELECTION

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Hartmann
*************************************************************************************************************************/
static void CDCustomFillMSAOutput (ObjNumber_t iObjectIndex)
{
  FCTCDOutputCustom_t * const pCustOutput =  ACDC_p_GetCDCustomOutput();

  if (    (iObjectIndex >= 0           )
       && (iObjectIndex <= EM_N_OBJECTS) )
  {
    pCustOutput->MSAConnected.fDistX             = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
    pCustOutput->MSAConnected.fDistY             = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fY;
    pCustOutput->MSAConnected.fObjectWidth       = ACDC_p_GetObjGeometry(iObjectIndex)->fWidth;
    pCustOutput->MSAConnected.fVx                = ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel.fX;
    pCustOutput->MSAConnected.fVy                = ACDC_p_GetObjMovement(iObjectIndex)->Abs.Vel.fY;
    pCustOutput->MSAConnected.uID                = iObjectIndex;
  } 
  else
  {
    pCustOutput->MSAConnected.fDistX             = CD_DIST_MAX;
    pCustOutput->MSAConnected.fDistY             = CD_DIST_MAX;
    pCustOutput->MSAConnected.fObjectWidth       = 0;
    pCustOutput->MSAConnected.fVx                = 0;
    pCustOutput->MSAConnected.fVy                = 0;
    pCustOutput->MSAConnected.uID                = OBJ_INDEX_NO_OBJECT;
  }  
}
#endif  /*(FCT_CFG_CD_MSA_SELECTION) */
///@}
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */


