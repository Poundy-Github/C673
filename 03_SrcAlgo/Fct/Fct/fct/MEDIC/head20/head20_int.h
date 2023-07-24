/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision) 

PACKAGENAME:               head20_int.h

DESCRIPTION:               header file for HEAD module (HEAD 2.0)

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 16:02:14CEST $

VERSION:                   $Revision: 1.17 $

**************************************************************************** */

#ifndef HEAD20_INT_H_INCLUDED
#define HEAD20_INT_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "head20/head20_ext.h"
#include "head20/head20_wrapper.h"

#if (HEAD_USE_CUSTOM_SYSTEMFUNCTION)
#include "head20/head20_customSystemfunction.h"
#endif

#if (MEDIC_ARCHITECTURE_VERSION >= 0x010)
#include "head20/head20_brake_cascades.h"
#endif

/*****************************************************************************
  INLINES
*****************************************************************************/

/* PRQA S 3415 EOF */ /* date: 2019-09-24, reviewer: Sekar, Balaji, reason:If the function righ to && is not called also no side effects */
/* PRQA S 0616,1055,3238,3480,3219 EOF */ /* date: 20-11-2019, uic42639, cannot get rid of algo inlines and hence suppressed */
/*************************************************************************************************************************
  Functionname:         HEADGetMostCritHypOfBitfieldForState                                                       */ /*!

  @brief                Return the Most Critical Active Hypothesis for the State

  @description          Return the Most Critical Active Hypothesis for the State based on Deceleration value or TTC value

  @return               HEADHypothesisNr_t : Most Critical Active hypothesis Number

  @param[in]            pInputData : Pointer to a HEAD Input Data
  @param[in]            uiActHypField : Active hypothesis in Bit field
  @param[in]            ppCurrCDHypo : pointer Most Critical CD Hypothesis Poiner
  @param[in]            bUseDecel : Bit Indictes whether to use Deceleration value (bUseDecel : True)
                        or TTC value(bUseDecel : false) to find the most critical active hypothesis
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        None

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static ALGO_INLINE HEADHypothesisNr_t HEADGetMostCritHypOfBitfieldForState( const struct HEADInputData_t * const pInputData,
                                                                     const uint16 uiActHypField,
                                                                     const HEADHypothesis_t** const ppCurrCDHypo,
                                                                     const boolean bUseDecel)
{
  /* Get Most critical activating Hypotheses number */
  HEADActiveHypIterator_t Iterator;
  HEADHypothesisNr_t      ActiveHypoNr = HEADNoHypothesis;
  HEADHypothesisNr_t      retVal = HEADNoHypothesis;
  float32                 fDecelerationCurrent = 0.0f;
  float32                 fTTCCurrent = HEAD_TTX_MAX;

  Iterator.currentHypo = HEADNoHypothesis;
  Iterator.uiActiveHypos = uiActHypField;

  while(b_FALSE != HEADActiveHypoIteratorGetNext(&Iterator,&ActiveHypoNr))
  {
    const HEADHypothesis_t * const pActiveHyp    = HEADGetHypothesis(pInputData->rgHypothesisList, ActiveHypoNr);
    if (pActiveHyp != NULL)
    {
      if (pActiveHyp->pHypothesis != NULL)
      {
        if ( (bUseDecel == b_TRUE) &&
          ((fDecelerationCurrent > MEDIC_f_GetHypLongNecAccel(ActiveHypoNr)) || (retVal == HEADNoHypothesis)))
        {
          retVal = ActiveHypoNr;
          *ppCurrCDHypo = pActiveHyp;
          fDecelerationCurrent = MEDIC_f_GetHypLongNecAccel(ActiveHypoNr);
        }
        else if ((bUseDecel == b_FALSE) &&
                 /* PRQA S 3415 1 */ /* date: 2019-09-24, reviewer: Sekar, Balaji, reason:If the function righ to && is not called also no side effects */
                ((fTTCCurrent > MEDIC_f_GetHypTTC(pActiveHyp)) || (retVal == HEADNoHypothesis)))  
        {
          retVal = ActiveHypoNr;
          *ppCurrCDHypo = pActiveHyp;
          fTTCCurrent = MEDIC_f_GetHypTTC(pActiveHyp);
        }
        else
        {
          /* not relevant */
        }
      }
    }
    else
    {
      /* Hypo independent => No Change of Values*/
    }
  }
  return retVal;
}

#endif //end of check for HEAD
#endif  // HEAD20_INT_H_INCLUDED


