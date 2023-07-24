/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_meas.c

DESCRIPTION:               Management of measurement output of LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup   frame_lohp_meas Frame_lohp_meas
@brief      File contains functions for measurement freezes of LOHP ports and structs
@ingroup    lohp_base_frame
@{ */ 

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */


#include "frame_lohp.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

/*****************************************************************************
  MACROS
*****************************************************************************/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_SEN_HC_COMP_STATE
#define FCT_MEAS_ID_SEN_HC_COMP_STATE      to be definded
#endif
#endif

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
#ifndef FCT_MEAS_ID_SEN_HC_CTRL_DATA
#define FCT_MEAS_ID_SEN_HC_CTRL_DATA       to be definded
#endif
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if (FCT_MEASUREMENT)
/* Static meas freeze variables: To ensure that correct values are freezed in the device */

/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

/*input ports*/

/*output ports*/
SET_MEMSEC_VAR(LOHP_FreezeBufferTargetControlState)
static TargetControlStatePort_t LOHP_FreezeBufferTargetControlState;  /*!<internal data buffer for measfreezing TargetControlStatePort OUTPUT interface.*/

#if (FCT_CFG_HP_TFC_PORT_CNT)
SET_MEMSEC_VAR(LOPC_FreezeBufferTargetFollowCommand)
static TargetFollowCommandPort_t LOPC_FreezeBufferTargetFollowCommand;  /*!<internal data buffer for measfreezing TargetFollowCommandPort OUTPUT interface.*/
#endif

#else   /* GEN 3 */

/*input ports*/

/*output ports*/
#if (FCT_SEN_CFG_FREEZE_CTRL_DATA) // to be freezed for ACC/HC
SET_MEMSEC_VAR(FCTSen_HCFreezeBufferSenCtrlData)
static FCTCtrlData_t FCTSen_HCFreezeBufferSenCtrlData;
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */

#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#endif  /* #if (FCT_MEASUREMENT) */


/*****************************************************************************
  VARIABLES
*****************************************************************************/
/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*input ports*/

/*output ports*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(FCTSen_HCFreezeBufferSenCompState)
static AlgoCompState_t FCTSen_HCFreezeBufferSenCompState;
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
/****************   Eof Buffers for MeasFreezes *******************/
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*! freeze function for FCT-output data (delayed ego signals) */
//static void FCTMeasFreezeFCTOutput (void);

#if (FCT_MEASUREMENT)
static void LOHP_v_FreezeInput(void);
#endif

/*! @endcond Doxygen_Suppress */
/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LOHP_v_FreezeInput                                                                               */ /*!

  @brief           Freeze Sensor Input

  @description     Freeze Sensor Input

					@startuml
					Start
					Partition LOHP_v_FreezeInput {
					 -Freeze control data Input
					 }	
					End	
					@enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SEN_CFG_FREEZE_CTRL_DATA : Switch to Freeze FCTSenCtrlData from ECU code as defined in fct_config.h
  @c_switch_part   FCT_SEN_CFG_FREEZE_USE_CALLBACK : Use this functionality if output pointers are non constant (ringbuffer IPC) as defined in fct_config.h
  
  @c_switch_full   FCT_MEASUREMENT: Activate Measurement Output Code as defined in fct_config.h

  @pre             -
  @post            -

  @created         -
  @changed         3/11/2016

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com | 
*************************************************************************************************************************/
static void LOHP_v_FreezeInput(void) 
{

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&FCTSen_HCFreezeBufferSenCtrlData, LOHP_pSenCtrlData, sizeof(FCTCtrlData_t));
  (void)MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_SEN_HC_CTRL_DATA, &FCTSen_HCFreezeBufferSenCtrlData, sizeof(FCTCtrlData_t));
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_SEN_HC_CTRL_DATA, (void*)LOHP_pSenCtrlData, sizeof(FCTCtrlData_t));
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif /*FCT_SEN_CFG_FREEZE_CTRL_DATA*/

}
#endif


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LOHP_v_FrameFreeze                                                                               */ /*!

  @brief           Freezes Frame Measurement Data (SW versions)

  @description     Freezes Frame Measurement Data (SW versions)

					@startuml
					Start
						Partition LOHP_v_FrameFreeze {
						 -Freezes Frame Measurement Data
					}	
					End	
					@enduml

  @return          -

  @param[in]       -

  @glob_in         FCTSEN_pBswAlgoParameters : Pointer to data type BSW_s_AlgoParameters_t as defined in fct_sen_main.c
  @glob_out        -

  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT
                          component. This should be enabled, if the SW environment provides this information as defined in fct_config.h
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface as defined in fct_config.h
  @c_switch_part   FCT_SEN_CFG_FREEZE_USE_CALLBACK : Use this functionality if output pointers are non constant (ringbuffer IPC) in fct_config.h

  @c_switch_full   FCT_MEASUREMENT : Activate Measurement Output Code as defined in fct_config.h

  @pre             The passed pFrame pointer filled, and the area pointed to remains static (i.e.: buffered meas freeze may be used)
  @post            -

  @created         -
  @changed         3/14/2016

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-88-0008a201

  @author          Jochen Spruck & Gergely Ungvary | Jochen.Spruck & Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void LOHP_v_FrameFreeze(void)
{

#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_LOHP_FRAME_DATA, &t_LOHPFrame, sizeof(LOHPFrame_t));
  (void)MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_LOHP_INPUT_SIGHEADERS, &t_LOHP_SyncRef, sizeof(LOHP_SyncRef_t));
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_LOHP_FRAME_DATA, &t_LOHPFrame, sizeof(LOHPFrame_t));
  (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_LOHP_INPUT_SIGHEADERS, &t_LOHP_SyncRef, sizeof(LOHP_SyncRef_t));
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  if (LOHP_pCompState != NULL)
  {
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
    (void)memcpy(&FCTSen_HCFreezeBufferSenCompState, LOHP_pCompState, sizeof(AlgoCompState_t));
    (void)MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_SEN_HC_COMP_STATE, &FCTSen_HCFreezeBufferSenCompState, sizeof(AlgoCompState_t));
#else
    (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_SEN_HC_COMP_STATE, LOHP_pCompState, sizeof(AlgoCompState_t));
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/

}
#endif  /* #if FCT_MEASUREMENT */


#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */
/*************************************************************************************************************************
  Functionname:    LOHP_v_ProcessMeasFreeze                                                                         */ /*!

  @brief           Freeze LOHP measurement data

  @description     Freeze process relevant LOHP measurement data

  @startuml
    Start
      Partition LOHP_v_ProcessMeasFreeze {
        -Freeze control Input data	
        -Freeze output ports of LOHP with buffered measfreeze
      }	
    End	
  @enduml

  @return          -

  @param[in]       pProvidePorts : Pointer to proFCTSenPrtList_t as defined in fct_sen_ext.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : FCT config for sensor to vehicle ACC Object of interest Port as defined in Rte_SWCEmAdapt_Type.h
  @c_switch_part   FCT_MEASUREMENT : Activate Measurement Output Code as defined in fct_config.h

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component as defined in fct_config.h

  @pre             -
  @post            -

  @created         -
  @changed         3/14/2016

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-87-0008a201
	
  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void LOHP_v_ProcessMeasFreeze(const LOHP_ProPortList_t * const pProvidePorts)
{

  /*******************/
  /* INPUT-Port-Data */
  /*******************/
#if (FCT_MEASUREMENT)
  LOHP_v_FreezeInput();
#endif

  /**********************/
  /* OUTPUT PORT-Data   */
  /**********************/
  /*! Freeze delayed input data of FCTOutput data */
  //FCTMeasFreezeFCTOutput();

#if (FCT_MEASUREMENT)

#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)

  memcpy(&LOHP_FreezeBufferTargetControlState, pProvidePorts->pt_LOHP_OUT_TCSP, sizeof(TargetControlStatePort_t));
  MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_LOHP_TCSP, (void*)&LOHP_FreezeBufferTargetControlState, sizeof(TargetControlStatePort_t));

#if (FCT_CFG_HP_TFC_PORT_CNT)
  memcpy(&LOPC_FreezeBufferTargetFollowCommand, pProvidePorts->pt_LOHP_OUT_TFCP, sizeof(TargetFollowCommandPort_t));
  MeasFreeze_Lohp_GlobVar(FCT_MEAS_ID_LOPC_TFCP, (void*)&LOPC_FreezeBufferTargetFollowCommand, sizeof(TargetFollowCommandPort_t));
#endif

#else

  MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_LOHP_TCSP, (void*)pProvidePorts->pt_LOHP_OUT_TCSP, sizeof(TargetControlStatePort_t));

#if (FCT_CFG_HP_TFC_PORT_CNT)
  MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_LOPC_TFCP, (void*)pProvidePorts->pt_LOHP_OUT_TFCP, sizeof(TargetFollowCommandPort_t));
#endif

#endif /* (FCT_SEN_CFG_FREEZE_USE_CALLBACK) */

#else
  _PARAM_UNUSED(pProvidePorts); /* PRQA S 3112 */
#endif /* (FCT_MEASUREMENT) */

}
#else   /* GEN 3 */
/*************************************************************************************************************************
  Functionname:    LOHP_v_ProcessMeasFreeze                                                                         */ /*!

  @brief           Freeze LOHP measurement data

  @description     Freeze process relevant LOHP measurement data

  @startuml
    Start
      Partition LOHP_v_ProcessMeasFreeze {
        -Freeze control Input data	
        -Freeze output ports of LOHP with buffered measfreeze
      }	
    End	
  @enduml

  @return          -

  @param[in]       pProvidePorts : Pointer to proFCTSenPrtList_t as defined in fct_sen_ext.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : FCT config for sensor to vehicle ACC Object of interest Port as defined in Rte_SWCEmAdapt_Type.h
  @c_switch_part   FCT_MEASUREMENT : Activate Measurement Output Code as defined in fct_config.h

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component as defined in fct_config.h

  @pre             -
  @post            -

  @created         -
  @changed         3/14/2016

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-87-0008a201

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void LOHP_v_ProcessMeasFreeze(const LOHPProPort_t * const pProvidePorts)
{

  /*******************/
  /* INPUT-Port-Data */
  /*******************/
#if (FCT_MEASUREMENT)
  LOHP_v_FreezeInput();
#endif

  /**********************/
  /* OUTPUT PORT-Data   */
  /**********************/
  /*! Freeze delayed input data of FCTOutput data */
  //FCTMeasFreezeFCTOutput();

#if (FCT_MEASUREMENT)

  (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_ACC_DISPLAY_OBJ, (void*)pProvidePorts->pAccDisplayObj, sizeof(acc_object_t));
  (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_ACC_OUTPUT_DATA, (void*)pProvidePorts->pAccOutput, sizeof(acc_output_data_t));

#endif /* (FCT_MEASUREMENT) */


#if (!FCT_MEASUREMENT)
  _PARAM_UNUSED(pProvidePorts); /* PRQA S 3112 */
#endif

}
#endif /* FCT_CFG_ACT_CODE_VERSION */


#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
