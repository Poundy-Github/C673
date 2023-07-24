/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypstatic.c

DESCRIPTION:               Implementation of the static hypothesis

AUTHOR:                    $Author: uidn3976 $

CREATION DATE:             $Date: 2020/09/09 09:10:30CEST $

VERSION:                   $Revision: 1.19 $

LEGACY VERSION:            Revision: 2.4

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_FOLLOW_HYPOTHESIS)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hypstatic HypStatic
@ingroup cd
@brief          The Static Hypothesis describes a situation in which the ego vehicle follows a 
                preceding object with a very low or no delta velocity. \n\n
@description    In opposite to the ACC Hypothesis in this hypothesis describes scenarios with a 
                small distance to the followed object. \n\n
                @image html StaticHyp.jpg width=400cm
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

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

static boolean CDHypoStaticObjectFilter (ObjNumber_t const iObjectIndex);

static void CDHypoStaticCalculateProb (ObjNumber_t iObjectIndex, CDIntHypothesis_t * pHypothesis);

/*************************************************************************************************************************
  Functionname:         CDHypoStaticObjectFilter                                                                     */ /*!

  @brief                Checks if an object is relevant for the static hypothesis.

  @description          checks if the object is relevant for CGEB and if the object
                        is relevant for static hypothesis type.
                        A object has to match with the following criteria to open a static hypothesis:
                         - Object has min. required quality
                         - Object is moving
                         - Objects Vrel is in following range [@ref CD_FOLLOWING_MIN_VREL, @ref CD_FOLLOWING_MAX_VREL]
                         - Object is close enough in long. direction
                         - Object was seen at least one cycle in track
                         - Previous following hypothesis is kept until vrel is greater than threshold

  @return               boolean: True if the object is relevant.

  @param[in]            iObjectIndex : Index of the considered object. @range [0,+...[
  @param[in]            *pLocalObj :   CD Internal object information.

  @glob_in              @ref ACDC_p_GetObjMovement        \n
                        @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetObjPositions       \n
                        @ref ACDC_p_GetObjHypothesisData  \n
                        @ref ACDC_p_GetObjStaticEvasionData
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_FOLLOW_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@contiautomotive.com

  @testmethod           @ref TEST_CDHYPOSTATICOBJECTFILTER_001\n
                        @ref TEST_CDHYPOSTATICOBJECTFILTER_002\n
						@ref TEST_CDHYPOSTATICOBJECTFILTER_003\n
						@ref TEST_CDHYPOSTATICOBJECTFILTER_004\n
						@ref TEST_CDHYPOSTATICOBJECTFILTER_005\n
						@ref TEST_CDHYPOSTATICOBJECTFILTER_006\n
						@ref TEST_CDHYPOSTATICOBJECTFILTER_007\n
						
  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoStaticObjectFilter (ObjNumber_t        const        iObjectIndex)
{
  boolean bReturn;
  float32               const         fObjVrelX   = ACDC_p_GetObjMovement(iObjectIndex)->Rel.Vel.fX;
  float32               const         fObjDistX   = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
  EM_t_GenObjAttributes const * const pObjAttribs = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
  CDObj_Hypothesis_t    const * const pObjHypData = ACDC_p_GetObjHypothesisData(iObjectIndex);
  CDObj_EvasionStatic_t const * const pEvasion    = ACDC_p_GetObjStaticEvasionData(iObjectIndex);

  /* Allow following hypothesis if
   * a) object has min. required quality
   * b) object is moving
   * c) vrel is in following range (CD_FOLLOWING_MIN_VREL, CD_FOLLOWING_MAX_VREL)
   * d) object is close enough in long. direction
   * e) object was seen at least one cycle in track
   * f) previous following hypothesis is kept until vrel is greater than threshold
   */
  if (    (           pObjAttribs->eDynamicProperty       == EM_GEN_OBJECT_DYN_PROPERTY_MOVING      )
       && (           fObjDistX                           <  CD_FOLLOWING_MAX_DIST                  )
       && (           fObjVrelX                            > CD_FOLLOWING_MIN_VREL                  )
       && (    (      fObjVrelX                           <  CD_FOLLOWING_MAX_VREL                )
            || (    ( fObjVrelX                           <  CD_FOLLOWING_MAX_VREL_KEEP         )
                 && ( pObjHypData->HypothesisHist.Following == (ubit16_t)1u                       ) ) )
       && ( (         pEvasion->TrackAssigned & (uint8)CD_FOLLOWING_MIN_TRACK_ASSIGNED ) != 0u      ) )
  {
    bReturn = b_TRUE;
  }
  else
  {
    bReturn = b_FALSE;
  }

  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDHypoStaticCalculateProb                                                                    */ /*!

  @brief                Calculates the hypothesis probability of a certain object for the static hypothesis

  @description          Sets the hypothesis probability for a static hypothesis to 1 for every object that 
                        passes the object filter (@ref CDHypoStaticObjectFilter).

  @return               void

  @param[in]            iObjectIndex :  Index of the considered object. @range [0,+...[
  @param[in,out]        pHypothesis :   Hypothesis information of the current hypothesis.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_FOLLOW_HYPOTHESIS

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@contiautomotive.com

  @testmethod           @ref TEST_CDHYPOSTATICCALCULATEPROB_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoStaticCalculateProb (ObjNumber_t iObjectIndex, CDIntHypothesis_t * pHypothesis)
{
  _PARAM_UNUSED(iObjectIndex);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
  pHypothesis->fHypothesisProbability = 1.0f;

  /* <ln_offset:+1 PCLINT Error 715: reviewer name: Dominik Froehlich date: 19-03-2011 reason: an improved algo could use the argument. Keep for generality. */
}

/*************************************************************************************************************************
  Functionname:         CDHypoStaticMain                                                                             */ /*!

  @brief                Handles the main processing steps of the static hypothesis.

  @description          Handles the static hypothesis by executing the three common steps for a hypothesis generation 
                        (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CDHypoStaticObjectFilter
                        2. Call of the Hypothesis probability calculation: @ref CDHypoStaticCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the three main steps that are described in the diagram can be 
                        found in the description of the @ref cd_hyphandler.
                        \image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0,+...[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history (if exists).

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_FOLLOW_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOSTATICMAIN_001\n
                        @ref TEST_CDHYPOSTATICMAIN_002\n
                        @ref TEST_CDHYPOSTATICMAIN_003

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoStaticMain(ObjNumber_t const iObjectIndex, 
                      boolean     const bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;
  CDObj_Hypothesis_t * const pObjHyp = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHyp->bitHypPresel), (uint32)CDHypothesisType_Static);
  CD_CLEAR_HYP_BIT(&(pObjHyp->bitHypActive), (uint32)CDHypothesisType_Static);

  /* handle only hypothesis relevant objects */
  if( bObjFilterMatched != b_FALSE )
  {
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_STATIC_SINGLE, (uint8)(iObjectIndex) ); /* start profiling for Hypothesis */
    if( CDHypoStaticObjectFilter(iObjectIndex)!= b_FALSE ) 
    {
      CD_SET_HYP_BIT(&(pObjHyp->bitHypPresel), (uint32)CDHypothesisType_Static);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_Static);

      /* calculate Hypothesis probability */
      CDHypoStaticCalculateProb(iObjectIndex,&Hypothesis);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > CD_COMMON_MIN_HYP_PROB )
      {
        CD_SET_HYP_BIT(&(pObjHyp->bitHypActive), (uint32)CDHypothesisType_Static);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHyp->HypothesisHist.Following = 1u;
      }
      else
      {
        pObjHyp->HypothesisHist.Following = 0u;
      }
    }
    else
    {
      pObjHyp->HypothesisHist.Following = 0u;
    }
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYP_STATIC_SINGLE, (uint8)(iObjectIndex) );
  }
  /* <ln_offset:+1 PCLINT Error 715: reviewer name: Dominik Froehlich date: 19-03-2011 reason: an improved algo could use the argument. Keep for generality. */
}

///\}
#endif  /* #if (CD_USE_FOLLOW_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

