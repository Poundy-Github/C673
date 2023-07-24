/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hyplong.c.c

DESCRIPTION:               Implementation of the generic long hypothesis

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/09/08 11:57:36CEST $

VERSION:                   $Revision: 1.40 $

LEGACY VERSION:            Revision: 2.10 (+2.7.2.3)

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)

#if(CD_USE_LONG_COLL_HYPOTHESIS)&& (CD_USE_GEN_PSC)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hyplong HypLong
@ingroup cd

@brief        The Longitudinal Hypothesis generically describes all kind of scenarios in which a collision 
              with a longitudinally moving object is probable. \n\n
@description  According to the actual implementation state this relates only to objects of classes Cyclist, 
              Pedestrian and Motorbike. The main function of the HypLong module if \ref CDHypoLongMain.

@{
*/

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/
static boolean CDHypoLongCollObjectFilter(ObjNumber_t const iObjectIndex);
#if (CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE)
static void CDHypoLongUpdateTimeBasedHypProbability(ObjNumber_t                      const iObjectIndex, 
                                                    float32                          const fTrajOverlap, 
                                                    CDInternalObjHypLongCollData_t * const pHypLongCollData );
#endif

/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDHypoLongUpdateTimeBasedHypProbability                                                      */ /*!

  @brief                Update the time based hypothesis probability.

  @description          Sets all elements of a structure of the data type @ref CDInternalObjHypLongCollData_t to 0.

  @return               void

  @param[in,out]        pHypData : Data of the current longitudinal hypothesis.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC \n
                        @ref CD_USE_LONG_COLL_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref test_CDHypoLongUpdateTimeBasedHypProbability_001 \n
                        @ref test_CDHypoLongUpdateTimeBasedHypProbability_002 \n
						@ref test_CDHypoLongUpdateTimeBasedHypProbability_003 \n
						@ref test_CDHypoLongUpdateTimeBasedHypProbability_004 \n

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoLongCollInitInternalData(ObjNumber_t const iObjectIndex)
{
  CDInternalObjHypLongCollData_t * const pHypData = &(ACDC_p_ModObjHypothesisData(iObjectIndex)->sHypLongCollData);

  pHypData->uDummy         = 0u;
#if (CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE)
  pHypData->uDummy1        = 0u;
  pHypData->uDummy2        = 0u;
  pHypData->uTimeBasedProb = 0u;
#endif
}

#if (CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE)
/*************************************************************************************************************************
  Functionname:         CDHypoLongUpdateTimeBasedHypProbability                                                      */ /*!

  @brief                Update the time based hypothesis probability. 

  @description          To stabilize the reaction on bicycles with small overlap, a time based probability 
                        addition is calculated. If the current overlap is sufficient increase the value 
                        otherwise decrease it.
                        @startuml CDHypoLongUpdateTimeBasedHypProbability_activity.png
                        start
                          if(Ego-Object Overlap > Threshold?) then (Yes)
                            :Calculate orientation angle delta between 
                            object and ego vehicle trajectory;
                            note left: >see formula "Orientation Angle Delta"
                            if(Orientation Angle < Threshold) then (Yes)
                              :1}
                              :Increase time based probability;
                            else(No)
                              :2}
                              :Decrease time based probability;
                            endif
                          else(No)
                            :3}
                            :Decrease time based probability;
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :     Index of the considered object. \range [0,+...[
  @param[in]            fTrajOverlap :     Current overlap of the object in relation to the ego trajectory width. \range [0,1]
  @param[in,out]        pHypLongCollData : Data of the current longitudinal hypothesis.

  @glob_in              @ref ACDC_p_GetObjMovement   \n
                        @ref ACDC_p_GetVDYDynObjSync \n
                        @ref ACDC_p_GetObjPositions
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_GEN_PSC \n
                        @ref CD_USE_LONG_COLL_HYPOTHESIS \n
                        @ref CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Orientation Angle Delta:** \n
                          Calculate the ego slope using the curve: \n
                          \f$Y = 0.5 \cdot fc0 \cdot X^2 + 0.167 \cdot fc1 \cdot X^3 \f$ \n
                          => \f$Y' = fc0 \cdot X + 0.5  \cdot fc1 \cdot X^2\f$ with \f$fc1 = 0 \f$ \n
                          \n
                          \f$Angle_{EgoTraj} = \arctan(Curve \cdot X_{Obj},1)\f$\n
                          \f$Angle_{Obj} = \arctan(V_{Y,Obj},V_{X,Obj})\f$ \n
                          \f$Angle = |Angle_{Obj} - Angle_{EgoTraj}|\f$

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDHYPOLONGUPDATETIMEBASEDHYPPROBABILITY_001 \n
                        @ref TEST_CDHYPOLONGUPDATETIMEBASEDHYPPROBABILITY_002 \n
                        @ref TEST_CDHYPOLONGUPDATETIMEBASEDHYPPROBABILITY_003 \n
						@ref TEST_CDHYPOLONGUPDATETIMEBASEDHYPPROBABILITY_004 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoLongUpdateTimeBasedHypProbability(ObjNumber_t                      const iObjectIndex, 
                                                    float32                          const fTrajOverlap, 
                                                    CDInternalObjHypLongCollData_t * const pHypLongCollData )
{
  sint32  iTimeBasedProb        = (sint32)pHypLongCollData->uTimeBasedProb ;
  boolean bIncreaseTimeBaseProb = b_FALSE;

  /* Check sufficient overlap */
  if (fTrajOverlap >  CD_LONG_COLL_TIME_BASED_HYP_PROB_MIN_OVERLAP)
  {
    /* Get necessary input pointers */
    SFLMovement_t const * const pObjMovAbs   = &(ACDC_p_GetObjMovement(iObjectIndex)->Abs);
    CurveVehDyn_t const * const pVehDynCurve = &ACDC_p_GetVDYDynObjSync()->Lateral.Curve;

    /* Calculate slope using curve y = 1/2*fc0*x^2 + 1/6*fc1*x^3 => y' = fc0*x + 1/2*fc1*x^2. fc1 is currently always 0.*/
    float32 fTrajSlope       = pVehDynCurve->Curve * ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
    float32 fTrajSlopeAngle  = ATAN2_(fTrajSlope, 1.0F);
    
    /* Calculate the object orientation here. This is necessary to use only information from the generic object list */
    float32 fOrientAngle     = ATAN2_(pObjMovAbs->Vel.fY,pObjMovAbs->Vel.fX);

    /* Check whether object orientation points along the expected trajectory */
    if (fABS(fOrientAngle - fTrajSlopeAngle)  < DEG2RAD(CD_LONG_COLL_TIME_BASED_HYP_PROB_MAX_ORIENT_DIFF ) )
    {
      bIncreaseTimeBaseProb = b_TRUE;
    }
  }

  /* Increase or decrease time based probability */ 
  if (bIncreaseTimeBaseProb == b_TRUE)
  {
    iTimeBasedProb += CD_LONG_COLL_TIME_BASED_HYP_PROB_INCR;
  }
  else
  {
    iTimeBasedProb -= CD_LONG_COLL_TIME_BASED_HYP_PROB_DECR;
  }

  /* Limit the probability */
  iTimeBasedProb = MINMAX(0, CD_LONG_COLL_TIME_BASED_HYP_PROB_MAX_VALUE, iTimeBasedProb);

  /* Write calculated value back to the object list */
  pHypLongCollData->uTimeBasedProb = (uint8)iTimeBasedProb;
}
#endif

/*************************************************************************************************************************
  Functionname:         CDHypoLongCollObjectFilter                                                                   */ /*!

  @brief                Checks whether an object is relevant for Longitudinal (at the moment VRU) Hypothesis

  @description          To pass the object filter, an object has to fulfill the following criteria:
                        - The Objects TTC has to be below a threshold or a Run Up hypothesis has 
                          been calculated on it in the last cycle. If oncoming objects are allowed 
                          for this hypothesis type, the admissible objects for this HypCat can be 
                          restricted to pedestrians using @ref CD_HYP_LONG_COLL_ONC_ONLY_PED.
                        - The Object is of Eba Object Class Cyclist, Pedestrian, or Motorbike.
                        \n\n
                        The generic Object filter previously requires the objects 
                        HypCat to be comoving. If it is configured to also allow oncoming objects to
                        cover the respective pedestrian use-cases, @ref CD_HYP_LONG_COLL_ONC_ONLY_PED can 
                        be used to prevent the creation of a hypothesis for objects which are not pedestrians.

  @return               boolean

  @param[in]            iObjectIndex :    Index of the considered object @range [0, EM_N_OBJECTS]
  @param[in]            *pObjInternData : CD Intern object data

  @glob_in              @ref ACDC_p_GetEMGenObjQualifiers \n
                        @ref CD_f_GetTTC\n
                        @ref ACDC_p_GetObjHypothesisData\n
  @glob_out             None

  @c_switch_part        @ref CD_HYP_LONG_COLL_ONC_ONLY_PED

  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_LONG_COLL_HYPOTHESIS \n
                        @ref CD_USE_GEN_PSC

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490

  @testmethod           @ref TEST_CDHYPOLONGCOLLOBJECTFILTER_001 \n
                        @ref TEST_CDHYPOLONGCOLLOBJECTFILTER_002 \n
                        @ref TEST_CDHYPOLONGCOLLOBJECTFILTER_003 \n
                        @ref TEST_CDHYPOLONGCOLLOBJECTFILTER_004 \n
                        @ref TEST_CDHYPOLONGCOLLOBJECTFILTER_005

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoLongCollObjectFilter(ObjNumber_t const iObjectIndex)
{
  boolean bReturn = b_FALSE;

  EM_t_GenObjQualifiers const * const pObjClass   = ACDC_p_GetEMGenObjQualifiers(iObjectIndex);
  CDObj_Hypothesis_t    const * const pObjHypData = ACDC_p_GetObjHypothesisData(iObjectIndex);
  const float32 fTmpDistToTraj = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTraj;
  
#if CD_HYP_LONG_COLL_ONC_ONLY_PED
  boolean bHypCatAllowedForObject = TRUE; /* Restrict feasible hyp. categories to specific object classes */
  /* Allow creation of hypothesis with oncoming HypCat only for pedestrians */
  if (  (( pObjClass->eEbaHypCat & FPS_EBA_HYP_CAT_ONC )  >  0                        )
     && (  pObjClass->eEbaObjClass                        != FPS_EBA_CLASS_PEDESTRIAN ))
  {
    bHypCatAllowedForObject = FALSE;
  }
#endif

  if (  ((  ( CD_f_GetTTC(iObjectIndex)                     <= CD_COMMON_TTC_THRES     )
#if CD_HYP_LONG_COLL_ONC_ONLY_PED
          &&( bHypCatAllowedForObject == TRUE )
#endif
         )
        ||  (pObjHypData->HypothesisHist.RunUpLong       == (ubit16_t)1u                          ) )
     && (   (pObjClass->eEbaObjClass                     == FPS_EBA_CLASS_CYCLIST      )
        ||  (pObjClass->eEbaObjClass                     == FPS_EBA_CLASS_PEDESTRIAN   )
        ||  (pObjClass->eEbaObjClass                     == FPS_EBA_CLASS_MOTORBIKE    ) )
		&& (fABS(fTmpDistToTraj)                           <  4.0f)
	  ) 
  {
    bReturn = b_TRUE;
  }

  return bReturn;
}



/*************************************************************************************************************************
  Functionname:         CDHypoLongMain                                                                               */ /*!

  @brief                Handles the main processing steps of the longitudinal hypothesis.

  @description          Handles longitudinal hypothesis by checking if object hypothesis filter and 
                        CDHypoLongCollObjectFilter match. The probability for the longitudinal hypothesis\n
                        is calculated via the actual overlap (see \ref cd_calculateoverlap) and
                        the probability of collision based on the probability of speed concept (see \ref cd_calculatepsc).\n
                        The two resulting probabilities are weighted and summed up.
                        The result is the hypothesis probability. As there is no Longitudinal Hypothesis \n
                        Flag, the Flag for the Run Up Hypothesis is set.
                        @startuml CDHypoLongMain_activity.png
                        start
                          if(Object matches generic object filter?) then (Yes)
                            #Orange:Check hypothesis specific object filter
                            <b>CDHypoLongCollObjectFilter</b> >
                            if(Specific object filter is matched?) then (Yes)
                              #Orange:Calculate hypothesis probability:
                              <b>CDPSCGetProbCollision</b>
                              <b>CDCalculateTrajectoryOverlapNowAndPred</b>
                              <b>CDCalculateProbOverlap</b> >
                              note left: >see formula "Hypothesis probability"
                              #Orange:In-/Decrease Probability on base of a time dependent factor:
                              <b>CDHypoLongUpdateTimeBasedHypProbability</b> >
                              if(Probability is above threshold?) then (Yes)
                                :1}
                                #Orange:Append current hypothesis to existing ones:
                                <b>CDHypSelCreateInternalHypotheses</b> >
                              else(No)
                                :2}
                                #Orange:Initialize the module intern data:
                                <b>CDHypoLongCollInitInternalData</b> >
                              endif
                            else(No)
                              :3}
                              #Orange:Initialize the module intern data:
                              <b>CDHypoLongCollInitInternalData</b> >
                            endif
                          else(No)
                            :4}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :        Index of the considered object
  @param[in]            bObjFilterMatched :   flag indicating if the object filter was matched or not

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_LONG_COLL_HYPOTHESIS \n
                        @ref CD_USE_GEN_PSC
  
  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Hypothesis probability:**\n
                          \f$P_{HypLong} = P_{Overlap} \cdot Weight_{Overlap} + P_{Collision} \cdot Weight_{Collision}\f$

  @todo                 weighting of overlap and PSC might need to be changed

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490

  @testmethod           @ref TEST_CDHYPOLONGMAIN_001 \n
                        @ref TEST_CDHYPOLONGMAIN_002 \n
                        @ref TEST_CDHYPOLONGMAIN_003 \n
                        @ref TEST_CDHYPOLONGMAIN_004

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoLongMain( ObjNumber_t const iObjectIndex, 
                       boolean   const bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;
  float32 fProbOverlap;
  float32 fProbPSC;
  float32 fPSCWeight      = 0.3f;
  float32 fOverlapWeight  = 0.7f;

  CDObj_Hypothesis_t *const pObjHypData  = ACDC_p_ModObjHypothesisData(iObjectIndex);
  /* ATTENTION : Hypothesis type CDHypothesisType_RunupCoMoving is only defined for interface 
                 versions FCT_HYPOTHESIS_INTFVER = 0x00001C or newer. 
                 For older versions the switch @ref ACDC_CFG_USE_HYP_TYPE_RUNUP_COMOVING is inactive.
                 The hypothesis type CDHypothesisType_RunupCoMoving is then mapped to CDHypothesisType_RunUp in 
                 the function CDHypSelCopySingleIntToExtHypothesis */
  eCDHypothesisType_t const CDHypothesisType = CDHypothesisType_RunupCoMoving;


  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType);


  /* Default Hypothesis Prob Calculation calling */
  if( bObjFilterMatched != b_FALSE )
  {
    if ( CDHypoLongCollObjectFilter( iObjectIndex) != b_FALSE)
    {
            float32 fTrajectoryOverlapNow;
            float32 fTrajectoryOverlapTTC;
      const float32 fEgoVeloDepWidthLeft_m  = 0.5f * CD_RUN_UP_TRACK_WIDTH;
      const float32 fEgoVeloDepWidthRight_m = 0.5f * CD_RUN_UP_TRACK_WIDTH;

      /* Default Hypothesis handling */
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType);

      /* get PSC and Overlap probability */
      fProbPSC     = CDPSCGetProbCollision(iObjectIndex, fEgoVeloDepWidthLeft_m, fEgoVeloDepWidthRight_m, CD_PSC_USE_TO_TRAJ);

      /* Get trajectory overlap */
      CDCalculateTrajectoryOverlapNowAndPred (iObjectIndex, &fTrajectoryOverlapNow, &fTrajectoryOverlapTTC);
      /* Calculate overlap probability */
      fProbOverlap = CDCalculateProbOverlap  (fTrajectoryOverlapNow, fTrajectoryOverlapTTC);
      /* set hypothesis probability */
      Hypothesis.fHypothesisProbability  = (fOverlapWeight * fProbOverlap);
      Hypothesis.fHypothesisProbability += (fPSCWeight     * fProbPSC    );

#if CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE
      /* Update the time confirmation value */
      CDHypoLongUpdateTimeBasedHypProbability(iObjectIndex, fTrajectoryOverlapNow, &pObjHypData->sHypLongCollData);
      Hypothesis.fHypothesisProbability += (0.01f * (float32)pObjHypData->sHypLongCollData.uTimeBasedProb);
#endif

      /* Limit the hypothesis to reasonable values */
      Hypothesis.fHypothesisProbability = MINMAX(0.0F, 1.0F, Hypothesis.fHypothesisProbability);

      /* store hypothesis (if relevant) */
      {
        if (Hypothesis.fHypothesisProbability > 0.35f)
        {
          CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType);
          CDHypSelCreateInternalHypotheses(&Hypothesis);
          pObjHypData->HypothesisHist.RunUpLong = 1u;
        }
        else
        {
          pObjHypData->HypothesisHist.RunUpLong = 0u;
          /* Init the static data */
          CDHypoLongCollInitInternalData(iObjectIndex);
        }
      }
    }
    else
    {
      pObjHypData->HypothesisHist.RunUpLong = 0u;
      /* Init the static data */
      CDHypoLongCollInitInternalData(iObjectIndex);
    }
  }
  else
  {
    pObjHypData->HypothesisHist.RunUpLong = 0u;
    /* Init the static data */
    CDHypoLongCollInitInternalData(iObjectIndex);
  }
}
///\}
#endif
#endif
