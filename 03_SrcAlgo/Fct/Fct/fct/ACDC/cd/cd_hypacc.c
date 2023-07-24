/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection 

PACKAGENAME:               cd_hypacc.c

DESCRIPTION:               Implementation of the ACC Hypothesis

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 14:46:15CEST $

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 2.11

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
#if (ACDC_CFG_CD)
#if (CD_USE_ACC_HYPOTHESIS)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup cd_hypacc HypAcc
\ingroup cd

\brief            The ACC Hypothesis describes a scenario in which the velocity delta between object and 
                  ego vehicle is very small. It describes especially scenarios with a high object distance.\n\n
\description      The ACC Hypothesis describes a scenario in which the velocity delta between object and 
                  ego vehicle is very small. It describes especially scenarios with a high object distance.\n
                  Therefore it relies on the object that is selected by the SLATE component for the ACC
                  functionality. If this is not available, several criteria are applied to select an object.\n
                  The Module provides one external function that checks whether an object matches for the ACC 
                  hypothesis or not: \ref CDHypoAccMain

\image html AccHyp.jpg width=400

\{
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
static boolean CDHypoAccObjectFilter(ObjNumber_t        const         iObjectIndex);

static void CDHypoAccCalculateProb (ObjNumber_t iObjectIndex, CDIntHypothesis_t * pHypothesis);

/*************************************************************************************************************************
  Functionname:         CDHypoAccObjectFilter                                                                        */ /*!

  @brief                Checks if the object is relevant for the ACC hypothesis.

  @description          For this hypothesis SLATE provides the object selected for the ACC functionality towards ACDC. \n
                        In case no object is provided by SLATE, the determination of matching objects is 
                        carried out by comparing each object with the following criteria:
                        - The Object has the HypCat Comoving
                        - The Object has a minimum EBA Quality
                        - The Object is moving or stopped currently and has a high confidence
                        - The Object has a certain criticality according to its attributes (TTC, TTB, ANecLong)
                        - The Object has been assigned to the Ego Track for several cycles

  @return               boolean: True if the object fullfills all criteria

  @param[in]            iObjectIndex :        the index of the object to check. @range [0, EM_N_OBJECTS]
  @param[in]            *currentObjInternal : Pointer to the CD internal data, that contains criticality attributes

  @glob_in              @ref ACDC_p_GetSLATE_CD_DataPointer\n
                        @ref ACDC_p_GetEMGenObjAttributes\n
                        @ref CD_f_GetTTC\n
                        @ref CD_f_GetTTBDynPre \n
                        @ref CD_f_GetTTBDynAcute\n
                        @ref CD_f_GetLongNecAccel\n
                        @ref ACDC_p_GetObjStaticEvasionData
  @glob_out             None

  @c_switch_part        @ref CD_USE_ACC_SI_OBJECT
  @c_switch_full        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL \n
                        @ref ACDC_CFG_CD     \n
                        @ref CD_USE_ACC_HYPOTHESIS

  @pre                  NULL-pointer checks have been conducted
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOACCOBJECTFILTER_001 \n
                        @ref TEST_CDHYPOACCOBJECTFILTER_002 \n
						@ref TEST_CDHYPOACCOBJECTFILTER_003 \n
						@ref TEST_CDHYPOACCOBJECTFILTER_004 \n
						@ref TEST_CDHYPOACCOBJECTFILTER_005 \n
						@ref TEST_CDHYPOACCOBJECTFILTER_006 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoAccObjectFilter(ObjNumber_t        const         iObjectIndex)
{
  boolean back = FALSE;
#if (CD_USE_ACC_SI_OBJECT)
  const SLATE_CD_Data_t * pt_SLATE_CD = ACDC_p_GetSLATE_CD_DataPointer();
  const ObjNumber_t iAccObj = pt_SLATE_CD->t_ACCRelObjID;
  if (iObjectIndex == iAccObj)
  {
    EM_t_GenObjAttributes const * const pEmObjAttributes = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
    if (    (           ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->uiEbaObjQuality           >  CD_COMMON_MIN_OBJ_QUALITY                                         )
         && (    (      pEmObjAttributes->eDynamicProperty                                   == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING    )
              || (    ( pEmObjAttributes->eDynamicProperty                                   == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED )
                   && ( pEmObjAttributes->uiDynConfidence                                    >= CD_COMMON_MIN_STOPPED_CONF                                     ) ) ) )
    {
      back = TRUE;
    }
    else
    {
      back = FALSE;
    }
  }
  else
  {
    back = FALSE;
  }
#else
  /* Allow hypothesis if
   * a) object has min. required quality
   * b) object is moving or stopped
   * c) object has min. required criticality (TTC, TTB, ANecLong)
   * d) object has been assigned to track for some cycles 
   */
  if (!ACDC_b_GetEMGenObjIsDeleted(iObjectIndex))
  {
    /* Query object's dynamic property into local variable */
    EM_t_GenObjAttributes const * const pEmObjAttributes = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
    if (    (           ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->uiEbaObjQuality             >  CD_COMMON_MIN_OBJ_QUALITY                                         )
         && (    (      pEmObjAttributes.eDynamicProperty                                      == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING    )
              || (    ( pEmObjAttributes.eDynamicProperty                                      == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED )
                   && ( pEmObjAttributes->uiDynConfidence                                      >= CD_COMMON_MIN_STOPPED_CONF                                     ) ) )
         && (    (      CD_f_GetTTC(iObjectIndex)                                              <  CD_COMMON_TTC_THRES                                              ) 
              || (      CD_f_GetTTBDynPre(iObjectIndex)                                        <  CD_COMMON_TTB_THRES                                              ) 
              || (      CD_f_GetTTBDynAcute(iObjectIndex)                                      <  CD_COMMON_TTB_THRES                                              )
              || (      CD_f_GetLongNecAccel(iObjectIndex)                                     <  CD_COMMON_ANECLONG_THRES                                         ) )
         && (         ( ACDC_p_GetObjStaticEvasionData(iObjectIndex)->TrackAssigned & (uint8)CD_ACC_MIN_TRACK_ASSIGNED ) != 0u                                                                 ) )
    {
      back = TRUE;
    }
    else
    {
      back = FALSE;
    }
  }
  else
  {
    back = FALSE;
  }
#endif

  return back;
}

/*************************************************************************************************************************
  Functionname:         CDHypoAccCalculateProb                                                                       */ /*!

  @brief                Calculates the probability of an object for the ACC hypothesis. (Current implementation: Always 1)

  @description          In case of the ACC hypothesis the probability calculation is omitted. This means that any object 
                        that passes the ACC object filter sets up an ACC hypothesis with probability 1.

  @return               void

  @param[in]            iObjectIndex : Index of the object to check
  @param[in,out]        pHypothesis :  Pointer to the Hypothesis

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL \n
                        @ref ACDC_CFG_CD     \n
                        @ref CD_USE_ACC_HYPOTHESIS

  @pre                  NULL-pointer checks have been conducted
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOACCCALCULATEPROB_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoAccCalculateProb (ObjNumber_t iObjectIndex, CDIntHypothesis_t * pHypothesis)
{
  _PARAM_UNUSED(iObjectIndex);
  pHypothesis->fHypothesisProbability = 1.0f;
  /* <ln_offset:+1 PCLINT Error 715: reviewer name: Dominik Froehlich date: 19-03-2011 reason: an improved algo could use the argument. Keep for generality. */
}

/*************************************************************************************************************************
  Functionname:         CDHypoAccMain                                                                                */ /*!

  @brief                Handles the main processing steps of the ACC hypothesis

  @description          Handles ACC Hypothesis by executing the three common steps for a hypothesis generation 
                        (see diagram Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: \ref CDHypoAccObjectFilter
                        2. Call of the Hypothesis probability calculation: \ref CDHypoAccCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: \ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the ACC hypothesis can also be found in the description of the module @ref cd_hypacc.
                        \image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :       The index of the object
  @param[in]            bObjFilterMatched :  If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history (if exists)
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        @ref CD_USE_EM_FPS_OBJCLASS \n
  @c_switch_full        @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL \n
                        @ref ACDC_CFG_CD \n
                        @ref CD_USE_ACC_HYPOTHESIS

  @pre                  NULL-pointer checks have been conducted
  @post                 None

  @InOutCorrelation     see description

  @author               martin.kallnik@contiautomotive.com

  @testmethod           @ref TEST_CDHYPOACCMAIN_001 \n
                        @ref TEST_CDHYPOACCMAIN_002 \n
                        @ref TEST_CDHYPOACCMAIN_003

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoAccMain(      ObjNumber_t const  iObjectIndex, 
                         boolean     const  bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;
  CDObj_Hypothesis_t * pObjHypData       = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_ACC);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_ACC);

  /* handle only hypothesis relevant objects */
  if( bObjFilterMatched != FALSE )
  {
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_ACC_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoAccObjectFilter(iObjectIndex) != FALSE )
    {
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_ACC);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_ACC);

      /* calculate Hypothesis probability */
      CDHypoAccCalculateProb(iObjectIndex, &Hypothesis);

      /* store hypothesis (if relevant) */
      if ( Hypothesis.fHypothesisProbability > CD_COMMON_MIN_HYP_PROB )
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_ACC);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
      }
    }
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_ACC_SINGLE, (uint8)(iObjectIndex));
  } /*bObjFilterMatched != FALSE*/

}
#endif  /* #if (CD_USE_ACC_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */
#endif

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

///\}

