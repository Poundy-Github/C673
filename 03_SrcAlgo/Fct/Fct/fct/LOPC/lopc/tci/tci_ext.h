/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/TCI (Adaptive Cruise Control - Traffic Continuation Indicator)

PACKAGENAME:               tci_ext.h

DESCRIPTION:               External header file for TCI functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             22.06.2017

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 1.1
**************************************************************************** */

#ifndef TCI_EXT_H_INCLUDED
#define TCI_EXT_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/*!
@defgroup   tci TCI (Traffic Continuation Indicator)
@ingroup    lopc_base_lopc
@brief      Module for TCI functionalities
 */

/** 
@defgroup   tci_ext Tci_ext_h
@ingroup    tci
@brief      TCI external header file
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lopc_ext.h"

#if (FCT_CFG_TCI==SWITCH_ON)

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    TCI_v_Process                                                                                    */ /*!

  @brief           Main function to process the Traffic Continuation Indication function

  @description     Main function to process the Traffic Continuation Indication function
  @startuml 
  Start
	  Partition TCI_Process {
			  Partition CheckforStatusofAutoCodeSwitch {
				  If(AutoCode switch is Turned OFF) then (true)
					  -Declare Variable for TCI Input Structure
				        -Setting pointer to Global Data Structure
				  Endif
			  }
		   -Call for Custom Specific Input Wrapper
			  Partition CheckforvalueofINTFVER {
				  If(INTFVER is >= 4) then (true)
					  - Set output states of TCI to default
				  Elseif(false)
				        - Set output states of TCI to no init
				  Endif
			  }
	         -Make BuzReq signal as FALSE
			  Partition CheckforLOPCState {
				  If(LOPCState is INIT) then (true)
					  -call InitPersistentdata & load signals with default values
				  Elseif(LOPCState is RUN) then (true)
					  -call Preprocess for loading TCI signals from RTE
					  -StateMachine is triggered
					  -All the necessary TCI signals are freezed for Simulation
				  Else(false)
					  -do nothing
				  Endif
			  }
		  - Setting pointer to NULL
	  } 
  End 
  @enduml


  @return          -

  @param[in]       pLongCtrlResp : Long control input as defined in RTE of type LongCtrlInput_t
  @param[in]       pVehDyn : Ego vehicle dynamic as defined in RTE of type VehDyn_t
  @param[in]       pAccOutput : ACC output data as port between SEN and VEH defined in RTE of type acc_output_data_t
  @param[in]       pFCTAccOOIData : ACC port between SEN and VEH defined in RTE of type FCTSenAccOOI_t
  @param[in]       pAccDisplayObj : ACC object data define in RTE of type acc_object_t
  @param[in]       pLongCtrlCmd : Long control output defined in RTE of type LongCtrlOutput_t
  @param[in]       pTCIInput : TCI inputs detined in RTE of type TCIInput_t
  @param[in,out]   TCIOutput : TCI outputs defined in RTE of type TCIOutput_t

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : FCT support for ACC HP (Headway Planner)
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Switch to activate ACC input port from SEN to VEH cycle
  @c_switch_part   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode
  @c_switch_full   FCT_CFG_TCI : FCT support for TCI module


  @created         13.07.2017
  @changed         13.07.2017

  @author          Cristian Santa | cristian02.santa@continental-corporation.com | +49 (8382) 9699-5630
*************************************************************************************************************************/
extern void TCI_v_Process(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t * pFCTAccOOIData,
#endif
                             const acc_object_t * pAccDisplayObj,
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
                             const PowerTrain_t * pPowerTrain,
#endif
                             const TCIInput_t * pTCIInputExt,
                             TCIOutput_t * pTCIOutput);


#endif  /* FCT_CFG_TCI */

/** @} end defgroup */
#endif /* TCI_EXT_H_INCLUDED */
