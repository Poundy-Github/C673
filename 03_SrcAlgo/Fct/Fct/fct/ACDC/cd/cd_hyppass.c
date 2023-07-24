/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:              cd_hyppass.c

DESCRIPTION:               Implementation of the pass hypothesis

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 13:16:20CEST $

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.6

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_PASS_HYPOTHESIS)

/************************************************************************
  MODULE DESCRIPTION
*************************************************************************/
/**
@defgroup cd_hyppass HypPass
@ingroup cd

@brief        The Pass Hypothesis describes a situation in which the ego vehicle passes a preceding 
              vehicle which drives in the left or right adjacent lane in the same direction as the ego vehicle.\n\n
@description  The only externally provided function of HypPass is @ref CDHypoPassMain. It handles the 
              call of the object filter (@ref CDHypoPassObjectFilter) an the probability calculation 
              (@ref CDHypoPassCalculateProb).
              @image html PassHyp.jpg width=400cm
@{
*/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CDHypoPassObjectFilter (ObjNumber_t        const        iObjectIndex);

static void CDHypoPassCalculateProb (ObjNumber_t       const         iObjectIndex, 
                                     CDIntHypothesis_t       * const pHypothesis);


/*************************************************************************************************************************
  Functionname:         CDHypoPassObjectFilter                                                                       */ /*!

  @brief                Checks if the object is relevant for the pass hypothesis

  @description          To open a pass hypothesis, the object has to fulfill the following criteria:
                        - The Objects distance to trajectory is below a threshold
                        - The Objects dynamic property is moving
                        - The Objects TTC and TTB are below threshold
                        - The Objects AnecLong is below threshold

  @return               boolean : True if object is relevant for the hypothesis

  @param[in]            iObjectIndex :        Index of the object to check. @range [0,+...[
  @param[in]            *pCurrentObjIntern :  Array of internal object data.

  @glob_in              @ref CD_f_GetTTC \n
                        @ref CD_f_GetTTBDynPre \n
                        @ref CD_f_GetTTBDynAcute \n
                        @ref CD_f_GetLongNecAccel \n
                        @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetObjTrajRelation\n
                        @ref ACDC_p_GetObjHypothesisData\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD
                        @ref CD_USE_PASS_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @remark               Use additionally the TTC/TTB because ANecLong does not consider 
                        if the ego vehicle already decelerates stronger than would be \n
                        necessary for collision avoidance. TTC/TTB becomes infinite
                        when ego deceleration > ANecLong

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOPASSOBJECTFILTER_001 \n
                        @ref TEST_CDHYPOPASSOBJECTFILTER_002 \n
						@ref TEST_CDHYPOPASSOBJECTFILTER_003 \n
						@ref TEST_CDHYPOPASSOBJECTFILTER_004 \n
						@ref TEST_CDHYPOPASSOBJECTFILTER_005 \n
						@ref TEST_CDHYPOPASSOBJECTFILTER_006 \n
						@ref TEST_CDHYPOPASSOBJECTFILTER_007 \n


  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoPassObjectFilter (ObjNumber_t        const        iObjectIndex)
{
  float32 fDistTraj;
  boolean bReturn;
  float32 fTTC          = CD_f_GetTTC(iObjectIndex);
  float32 fTTBDynPre    = CD_f_GetTTBDynPre(iObjectIndex);
  float32 fTTBDynAcute  = CD_f_GetTTBDynAcute(iObjectIndex);
  float32 fLongNecAccel = CD_f_GetLongNecAccel(iObjectIndex);
  CDObj_Hypothesis_t const * const pObjHypData  = ACDC_p_GetObjHypothesisData(iObjectIndex);

  fDistTraj = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTraj;

  /* Allow hypothesis if
   * a) object is close enough to course
   * b) object is moving
   * c) longitudinal deceleration is necessary
   * d) ttc or ttb < infinity
   * previous pass hypothesis is kept until long. deceleration is greater than threshold
   */
  if (    (           fABS(fDistTraj)                                              <  CD_PASS_MAX_LAT_DIST             ) 
       && (           ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eDynamicProperty == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING)
       && (    (    ( fTTC                                                         <  CD_COMMON_TTC_THRES        ) 
                 || ( fTTBDynPre                                                   <  CD_COMMON_TTB_THRES        ) 
                 || ( fTTBDynAcute                                                 <  CD_COMMON_TTB_THRES        ) )
       && (    (      fLongNecAccel                                                <  CD_PASS_ANECLONG_THRES       )
            || (    ( fLongNecAccel                                                <  CD_PASS_ANECLONG_THRES_KEEP)
                 && ( pObjHypData->HypothesisHist.Pass                             == 1                          ) ) ) ) )
  {
    bReturn = TRUE;
  }
  else
  {
    bReturn = FALSE;
  }

  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDHypoPassCalculateProb                                                                      */ /*!

  @brief                Calculates the probability for the pass hypothesis.

  @description          The probability of the pass hypothesis depends on the current inlap and the inlap at TTC.
                        Two qualities are calculated from the inlaps. The probability results from the multiplication \n
                        of those qualities. The following steps are executed:\n
                        @startuml HypPassProb_activity.png
                        start
                          #Orange:Calculate current inlap of object 
                          into the ego trajectory:
                          <b>CDCalculateInlapAtTime</b> >
                          note left: Based on ego trajectory width\nand DistToTrajMin/Max
                          
                          #Orange:Calculate inlap of object 
                          into the ego trajectory at TTC:
                          <b>CDCalculateInlapAtTime</b> >
                          note left: Based on ego trajectory width\nand DistToTrajMin/Max

                          :Calculate Quality based on the 
                          current kinematics and inlap;
                          note left: >see formula "Quality Now"
                          
                          :Calculate Quality based on the 
                          predicted kinematics and inlap;
                          note left: >see formula "Quality TTC"

                          :Calculate Hypothesis Probability;
                          note left: >see formula "Hypothesis Probability"
partition #LightBlue **CD_USE_BRAKE_JERK_TTC**{
                          #Orange:Apply the brake jerk factor to the Probability:
                          <b>CD_f_GetTTCBrakeJerkFactor<b> >
}
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :        Index of the considered object. @range [0,+...[
  @param[in,out]        pHypothesis :         Information about the current hypothesis.

  @glob_in              @ref CD_f_GetTTC \n
                        @ref CD_f_GetTTCBrakeJerkFactor
  @glob_out             None

  @c_switch_part        @ref CD_USE_BRAKE_JERK_TTC
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_PASS_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     The probability calculation is based on a calculated overlap (for more details see @ref CDCalculateInlapAtTime). 
                        Two different Qualities result from these values:
                        - **Quality Now**: \n
                          Converts the current occupancy into a quality between 0 and 1. \n
                          \f$Q_{now} = \frac{Overlap_{now} - Threshold_{now0}}{Threshold_{now1}-Threshold_{now0}}\f$
                        - **Quality TTC**: \n
                          Converts the occupancy at TTC into a quality between 0 and 1. \n
                          \f$Q_{ttc} = \frac{Overlap_{ttc} - Threshold_{ttc0}}{Threshold_{ttc1}-Threshold_{ttc0}}\f$
                        - **Hypothesis Probability:**\n
                          \f$P_{Pass} = Q_{now} \cdot Q_{ttc} \f$

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDHYPOPASSCALCULATEPROB_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoPassCalculateProb (ObjNumber_t       const        iObjectIndex, 
                                     CDIntHypothesis_t       * const pHypothesis)
{
  float32 fQualityNow;
  float32 fQualityTTC;

  float32 fInlapNow;
  float32 fInlapVarNow;
  float32 fInlapTTC;
  float32 fInlapVarTTC;

  float32 const fTTC = CD_f_GetTTC(iObjectIndex);
  
  /* calculate overlap and occupancy */
  CDCalculateInlapAtTime(iObjectIndex,0.f,CD_PASS_TRACK_WIDTH,&fInlapNow,&fInlapVarNow);

  CDCalculateInlapAtTime(iObjectIndex,MIN_FLOAT(fTTC, CD_PASS_MAX_PRED_TIME),CD_PASS_TRACK_WIDTH_TTC,&fInlapTTC,&fInlapVarTTC);

  fQualityNow = CML_f_BoundedLinInterpol2((fInlapNow - fInlapVarNow), CD_PASS_THRES_OCC_0_NOW, CD_PASS_THRES_OCC_1_NOW, 0.f, 1.f);
  fQualityTTC = CML_f_BoundedLinInterpol2((fInlapTTC - fInlapVarTTC), CD_PASS_THRES_OCC_0_TTC, CD_PASS_THRES_OCC_1_TTC, 0.f, 1.f);


  pHypothesis->fHypothesisProbability = fQualityNow * fQualityTTC;

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
  /* reduce hypothesis probability in case of brake jerk */
  pHypothesis->fHypothesisProbability *= CD_f_GetTTCBrakeJerkFactor(iObjectIndex);
#endif /* CD_USE_BRAKE_JERK_TTC */
}

/*************************************************************************************************************************
  Functionname:         CDHypoPassMain                                                                               */ /*!

  @brief                Handles the main processing steps of the pass hypothesis.

  @description          Handles the pass Hypothesis by executing the three common steps for a hypothesis generation 
                        (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CDHypoPassObjectFilter
                        2. Call of the Hypothesis probability calculation: @ref CDHypoPassCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: 
                        @ref CDHypSelCreateInternalHypotheses
                        .
                        @image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0,+...[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. 
                                            If FALSE reset history (if exists).

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        @ref EM_GEN_OBJECT_INTFVER \n
                        @ref CD_USE_EM_FPS_OBJCLASS
  @c_switch_full        @ref ACDC_CFG_CD
                        @ref CD_USE_PASS_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDHYPOPASSMAIN_001 \n
                        @ref TEST_CDHYPOPASSMAIN_002 \n
                        @ref TEST_CDHYPOPASSMAIN_003 \n
                        @ref TEST_CDHYPOPASSMAIN_004

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoPassMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;
  CDObj_Hypothesis_t * pObjHypData       = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_Pass);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Pass);

  /* handle only hypothesis relevant objects */
  if ( bObjFilterMatched != FALSE ) 
  {
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_PASS_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoPassObjectFilter(iObjectIndex ) != FALSE)
    {
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_Pass);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_Pass);

      /* calculate Hypothesis probability */
      CDHypoPassCalculateProb(iObjectIndex, &Hypothesis);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > CD_COMMON_MIN_HYP_PROB)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Pass);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.Pass = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.Pass = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.Pass = 0u;
    }
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_PASS_SINGLE, (uint8)(iObjectIndex));
  }
  else
  {
    pObjHypData->HypothesisHist.Pass = 0u;
  }
}
///\}
#endif  /* #if (CD_USE_PASS_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

