/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_output_mgr.c

DESCRIPTION:               DIM Output Manager

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/09/03 17:56:43CEST $

VERSION:                   $Revision: 1.16 $

**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_DIM20)

#include "dim20/dim20_int.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         DIMInitOutputMgr                                                      */ /*!

  @brief                DIMInitOutputMgr

  @description          Initialize the DIM output structures if any
                        @startuml
                        Start
                        :Set the init data to 0;
                        #orange: Return DIM_HYPOUT_CAL_DATA_EBA structure
                        <b> MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA</b> >
                        If (pCalData is not valid) then (yes)
                        : Assign the address of init data;
                        EndIf
                        Stop
                        @enduml

  @return               void

  @param[in]            none

  @glob_in              DIM_HYPOUT_CAL_DATA_EBA
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n

  @pre                  None  
  @post                 None

  @InOutCorrelation     Not Applicable
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}
  
  @author               
*************************************************************************************************************************/
void DIMInitOutputMgr(void)
{
  DIM_HYPOUT_CAL_DATA_t init_data = {0};
  DIM_HYPOUT_CAL_DATA_t* pCalData = MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA();

  if (pCalData != NULL)
  {
    pCalData = &init_data; /*PRQA S 2983 */ /*date: 2020-08-25, reviewer: Nalina M, reason: Supressing because the value will be used in future.*/
  }
}

/*************************************************************************************************************************
  Functionname:        DIMFillBaseOutput                                                                           */ /*!

  @brief               Copy local hypothesis data to output

  @description         This function copies the hypothesis data like probability and confidence to DIm output buffer,
                       by checking whether the DIM hypothesis data should be taken from internal evaluations or from the 
                       caliberation if enabled.

                       @startuml
                       start
                       if (hypothesis to be copied is \n one amongst the listed hypothesis?) then (yes)
                       :copy this hypothesis input to output buffer;
                       If (hypothesis calib data is available?) then (yes)
                       If (this hypothesis is within the range in calib \n and the calib mask is set for this hypo?) then (yes)
                       :save the probability and confidence info from calib to output buffer;
                       endif
                       endif
                       endif
                       stop
                       @enduml

  @return              void

  @param[in]           hypIn  : Internal hypothesis data
  @param[in]           uiHypNr  : Hypothesis number
  @param[in]           uiTotalHypNr : Total number of Hypothesis
  @param[in,out]       hypOut : Updated hypothesis data with calibrated Confidence and Probability values
  
  @glob_in             DIM_HYPOUT_CAL_DATA_EBA 
  @glob_out            None
 
  @c_switch_part       DIM_CFG_OUT_CALIB
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING
  
  @pre                 None 
  @post                None
  
  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test)

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void DIMFillBaseOutput( const GDB_DMHypothesis_t *hypIn, GDB_DMHypothesis_t hypOut[], uint8 uiHypNr, uint8 uiTotalHypNr)
{
  /* Check if sufficient space on output is provided */
  if (uiHypNr < uiTotalHypNr)
  {
    /* Copy whole structure data */
    hypOut[uiHypNr] = *hypIn;

    #if ((DIM_CFG_OUT_CALIB == MEDIC_ON) && defined (MEDIC_SIMU))
    /* As soon as calibration bit set for current hypothesis number, use calibration
       value instead of calculated one */
    if ( ((MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()->CalibMask & (1uL<<uiHypNr)) != 0uL) 
      && (uiHypNr < DIM_NO_CALIB_HYPS))
    {
      hypOut[uiHypNr].Confidence  = MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()->Confidence[uiHypNr];
      hypOut[uiHypNr].Probability = MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()->Probability[uiHypNr];
    }
    #endif
  }
}

/*************************************************************************************************************************
  Functionname:         DIMFillOutput                                                      */ /*!

  @brief                update DIM custom outputs to the buffer

  @description          update DIM custom outputs to the buffer
                        @startuml
                        Start
                        #orange: update DIM custom outputs to the buffer
                        <b> DIMFillCustomOut</b> >
                        Note: Custom data filling for the DIM monitoring states, Feedback, Attention, Activity.
                        Stop
                        @enduml


  @return               void

  @param[in]            fCycleTime : The function cycle time
  @param[in]            pDimInputSigPreProc : pointer to signal input which has to be differentiated
  @param[in]            pDimOutputSigPreProc : pointer to output which is the gradient of input signal
  @param[in]            DimIirFilt : pointer to the input signal value buffer

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        None

  @pre                  None  
  @post                 None

  @InOutCorrelation     Not Applicable
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}
  
  @author               
*************************************************************************************************************************/
void DIMFillOutput(void)
{
  DIMFillCustomOut();
}

#endif  /* #if MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* MEDIC_CFG_DIM20 */
