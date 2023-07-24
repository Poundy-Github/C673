/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA Signal Performance Monitoring)

PACKAGENAME:               espm_main.c

DESCRIPTION:               Main functions for EBA Signal Performance Monitoring (ESPM) module

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 07:34:29CEST $

VERSION:                   $Revision: 1.15 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "espm_int.h"

#if (ACDC_CFG_ESPM)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup espm_main Main
@ingroup espm

@brief          The module main contains the main function of the ESPM subcomponent 
                as soon as a function for the setting of the ESPM OpMode.\n\n
@description    The module provides the following functionalities:
                - Execution of the ESPM Main routine: @ref ESPM_v_DegradationProcess
@{
*/

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         ESPM_v_DegradationProcess                                                                    */ /*!

  @brief                The function processes the main steps of the ESPM subcomponent according to the 
                        current operation mode.

  @description          Depending on the operation mode of the ESPMState in the global variable @ref ACDC_p_GetFrameData, the degradation information 
                        of the global variable @ref ACDC_pHypotheses is initialized or not. 
                        If status is OK, the information is written to the Outports.
                        @startuml ESPM_v_DegradationProcess.png
                        start
                         if(ESPM State is OK?) then (Yes)
                          :1}
                           #Orange:Calculate current safety 
                           performance degradation:
                           <b>ESPM_v_PerfDegradation</b> >
                           #Orange:Write degradation data to outport:
                           <b>ESPM_v_FillOutputports</b> >
                         else (No)
                          :2}
                           #Orange:Initialize degradation data:
                           <b>ESPM_v_InitDegradationData</b> >
                           #Orange:Initialize outport:
                           <b>ESPM_v_InitOutput</b> >
                         endif

                         #Orange:Measfreeze the degradation information:
                         <b>ESPM_v_MeasFreezeDegradationData</b> >
                        stop
                        @enduml

  @return               void

  @param[in,out]        pDegradationOut : Degradation Substructure of the Hypothesis Interface of ACDC (@ref ACDC_pHypotheses). 
                                          The Rest of the Interface (hypotheses list + Header) is filled by CD
  @param[in,out]        pErrorOut       : Error Out Port of the ACDC Component. To be filled exclusively by ESPM.

  @glob_in              @ref ACDC_e_GetSubCompState
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_V_DEGRADATIONPROCESS_001 \n
                        @ref TEST_ESPM_V_DEGRADATIONPROCESS_002 \n
						@ref TEST_ESPM_V_DEGRADATIONPROCESS_003 \n
                        @ref TEST_ESPM_V_DEGRADATIONPROCESS_004

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
void ESPM_v_DegradationProcess(HypoIntfDegr_t        * const pDegradationOut, 
                               ACDCErrorOutProPort_t * const pErrorOut)
{
  ACDCCompState_t ESPMState = ACDC_e_GetSubCompState(ACDC_SUB_COMP_ESPM);
  switch (ESPMState)
  {
  case COMP_STATE_RUNNING:
    /* Process degradation based on ALN and VDY */
#if (ESPM_CFG_USE_SPM_OUTPUT)
    ESPM_v_PerfDegradation();
#endif
    ESPM_v_FillOutputports(pDegradationOut, pErrorOut);
	if (ACDC_p_GetFrameData()->uiVDYSigErrorCnt > ACDC_MAX_VDY_SIG_ERRORS)
    {
		ESPM_v_InitOutput(pDegradationOut, pErrorOut);
	}
    break;
  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /* Default */
    ESPM_v_InitDegradationData();
    ESPM_v_InitOutput(pDegradationOut, pErrorOut);
    break;
  }

  /* Measfreeze */
  /* Freeze degradation data */
  ESPM_v_MeasFreezeDegradationData();
 
}


/*!\}*/

#endif /*!< ACDC_CFG_ESPM */

