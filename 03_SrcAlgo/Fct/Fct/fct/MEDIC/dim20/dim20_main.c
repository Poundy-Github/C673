/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_main.c

DESCRIPTION:               Implementation of the DIM process

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/07/10 15:40:56CEST $

VERSION:                   $Revision: 1.18 $
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_DIM20)

#include "dim20/dim20_int.h"
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  CONSTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:        DIMProcess                                                                          */ /*!

  @brief               Main process function of DIM

  @description         Main process function of DIM. This function will initialize DIM module if not already initialized,
                       collects the new set of input values for the signals thats are of interest for DIM hypothesis, triggers 
                       evaluations of these input signals for creating DIM hypothesis probabilities during the vehicle cycle time
                       duration. Also this function will trigger the output creation from DIM module using the hypothesis 
                       probability information.

                       @startuml
                       Start
                        :Get DIM component current status from GA;
                        #orange:if(DIM not yet initialized,\n<b>DIMInitialized is false)then (yes)
                        :overwrite the comp state to not initialized;
                        Endif
                        If(DIM init not done?) then (yes)
                        Partition Initialization {
                        :Initialize DIM;
                        Note left:DIM inputs, internal structures\nand outputs are initialized
                        }
                        Else if(DIM is running?)then (yes)
                        partition Running {
                        :Collect inputs;
                        :Do signal PreProc;
                        :Evaluate Hypothesis;
                        :Fill outputs;
                        }
                        Else (no)
                        Partition ReInit {
                        :error or unknown state,\nDIM reinit;
                        }
                        Endif
                       :Update the component state\n<b>MEDIC_v_SetSubComponentStates;
                      Stop
                      @enduml

  @return               void

  @param[in]            fCycleTime : The cycle time in seconds
  

  @glob_in              @ref MEDIC_e_GetSubCompState 
  @glob_in              @ref MEDIC_p_GetWorkingData
  @glob_out             @ref MEDIC_v_SetSubComponentStates

  @c_switch_part        @ref DIM_CFG_IN_PREPROC
                        @ref DIM_CFG_HYPO_EBA
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                  None
  @post                 None 

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1149-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1151-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
  *************************************************************************************************************************/
void DIMProcess( const float32 fCycleTime )
{
  MEDICCompState_t DIMState = MEDIC_e_GetSubCompState(MEDIC_SUB_COMP_DIM);
  if( MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.bDIMInitialized == b_FALSE)
  {
    DIMState = COMP_STATE_NOT_INITIALIZED;
  }

  switch (DIMState)
  {
    case COMP_STATE_NOT_INITIALIZED:
      DIMInit();
    break;

    case COMP_STATE_RUNNING:
      DIMCollectInputs();

      #if (DIM_CFG_IN_PREPROC)
      DIMRunSigPreProc(fCycleTime);
      #endif

      #if (DIM_CFG_HYPO_EBA)
      DIMRunHypothesisEval(fCycleTime);
      #endif

      DIMFillOutput();
    break;

    default: 
      DIMInit();
    break;
  }

   MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_DIM,DIMState);
}
/*************************************************************************************************************************
  Functionname:         DIMInit                                                                          */ /*!

  @brief                Main init function of DIM 

  @description          Main init function of DIM. This function will reset the signal status that was saved during
                        the last cycles, and also triggers the reset of DIM hypothesis related parameters, their
                        probabilities and confidence.This function is generally executed once during the start of DIM 
                        and the initialization status is retained and monitored, so that in case of any disruption in 
                        DIM operations, the module would be reinitialized. DIMInit is also called by simulation functions

                        @startuml
                        Start
                        Partition InputInit {
                        :Init all inputs;
                        Note left:Set all inputs\nto default
                        :init PreProc structures;
                        }
                        Partition HypothesisInit {
                        :Init hypothesis structures;
                        }
                        Partition OutputInit {
                        :Init all DimOut structures;
                        }
                        :update DIM module version in GA;
                        :update DIM data size in GA;
                        :Set DIM to initialized state in GA;
                        stop
                        @enduml

  @return               void

  @param[in]            None

  @glob_in              None
  @glob_out             @ref MEDIC_p_GetDIMData
  @glob_out             @ref MEDIC_p_GetWorkingData

  @c_switch_part        @ref DIM_CFG_HYPO_EBA, @ref DIM_CFG_OUT_CALIB, @ref DIM_CFG_IN_PREPROC
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  [none]  
  @post                 [none]

  @InOutCorrelation     Not Applicable
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1149-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/*PRQA S 1505 1*//*DIMInit is also called by simulation functions*/
void DIMInit(void)
{
  /*clear DIM input signal data*/
  DIMInitInputMgr();

  /*init signal preprocessing data*/
  #if (DIM_CFG_IN_PREPROC)
  DIMInitSigPreProc();
  #endif /* DIM_CFG_IN_PREPROC */

  /*init hypothesis data*/
  #if (DIM_CFG_HYPO_EBA)
  DIMInitHypothesisMgr();
  #endif /* DIM_CFG_HYPO_EBA */

  /*init DIM output data*/
  #if (DIM_CFG_OUT_CALIB)
  DIMInitOutputMgr();
  #endif /* DIM_CFG_OUT_CALIB */

  MEDIC_p_GetDIMData()->DIMHeaderData.uiBaseVersion = (uint32) DIM_AUTOVERSION;
  MEDIC_p_GetDIMData()->DIMHeaderData.uiStructSize = sizeof(DIMData_t);
  
  MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.bDIMInitialized = b_TRUE;
}

#endif  /* #if MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* MEDIC_CFG_DIM20 */
