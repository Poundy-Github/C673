/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc_meas.c

DESCRIPTION:               File contains functions for freezing of information

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             31.01.2017

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup   frame_lopc_meas Frame_lopc_meas
@brief      File contains functions for measurement freezes of LOPC ports and structs
@ingroup    lopc_base_frame
@{ */ 

#include "frame_lopc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))

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
/****************   Buffers for MeasFreezes *******************/
#if (FCT_CFG_ACT_CODE_VERSION)

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
/*output ports*/
SET_MEMSEC_VAR(LOPC_FreezeBufferTargetFollowState)
static TargetFollowStatePort_t LOPC_FreezeBufferTargetFollowState;  /*!<internal data buffer for measfreezing TargetFollowStatePort OUTPUT interface.*/
#endif

#else /* Legacy code */

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
/*input ports*/
#ifdef FCT_SIMU
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LOPC_FreezeBufferAccLeverIn)
static AccLeverInput_t LOPC_FreezeBufferAccLeverIn;   /*!<internal data buffer for measfreezing ACCLeverInput.*/

/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LOPC_FreezeBufferLongCtrlResp)
static LongCtrlInput_t LOPC_FreezeBufferLongCtrlResp; /*!<internal data buffer for measfreezing LongCtrlInput.*/

#if (FCT_CFG_TCI)
SET_MEMSEC_VAR(LOPC_FreezeBufferTCIInput)
static TCIInput_t LOPC_FreezeBufferTCIInput; /*!<internal data buffer for measfreezing TCIInput.*/
#endif

#endif /*FCT_SIMU*/

/*output ports*/
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LOPC_FreezeBufferVehLongOut)
static FctVeh2SenInfo_t LOPC_FreezeBufferVehLongOut;               /*!<internal data buffer for measfreezing Veh2SenInfo OUTPUT interface.*/
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LOPC_FreezeBufferLongCtrlOut)
static LongCtrlOutput_t LOPC_FreezeBufferLongCtrlOut;              /*!<internal data buffer for measfreezing LongCtrl OUTPUT interface.*/

#if (FCT_CFG_TCI)
SET_MEMSEC_VAR(LOPC_FreezeBufferTCIOutput)
static TCIOutput_t LOPC_FreezeBufferTCIOutput;              /*!<internal data buffer for measfreezing TCI OUTPUT interface.*/
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(LOPC_FreezeBufferVehCompState)
static AlgoCompState_t LOPC_FreezeBufferVehCompState;              /*!<internal data buffer for measfreezing Algo Component State OUTPUT interface.*/
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/

#if (FCT_CFG_ERROR_OUTPUT_VEH)
SET_MEMSEC_VAR(LOPC_FreezeBufferErrorOut)
static LOPCErrorOut_t LOPC_FreezeBufferErrorOut;              /*!<internal data buffer for measfreezing LOPC Error output.*/
#endif /*FCT_CFG_ERROR_OUTPUT_VEH*/

#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

#endif /* FCT_CFG_ACT_CODE_VERSION */

/****************   end of Buffers for MeasFreezes *******************/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LOPC_v_FrameFreeze                                                                               */ /*!

  @brief           Functional Summary

  @description     Detailed Design

@startuml
Start
Partition LOPC_v_FrameFreeze(){
: Freeze Global Variables related to LOPC Frame;
}
End
@enduml

  @return          void

  @param[in]       void : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         01.02.2017
  @changed         01.02.2017

  @todo            Remove this entire line if not needed

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-136-0008a220

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOPC_v_FrameFreeze(void)
{

  MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LOPC_STATIC_MEM, &LOPC_STATIC_MEMORY, sizeof(lopc_static_mem_t));


#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /* Algo Component State Output */
  if (LOPC_pCompState != NULL)
  {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
    memcpy(&LOPC_FreezeBufferVehCompState, LOPC_pCompState, sizeof(AlgoCompState_t));
    MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LOPC_COMP_STATE, &LOPC_FreezeBufferVehCompState, sizeof(AlgoCompState_t));
#else
    MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LOPC_COMP_STATE, LOPC_pCompState, sizeof(AlgoCompState_t));
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
}


/* ***********************************************************************
  @fn              LOPC_v_ProcessMeasFreeze  */ /*! 
  @brief           meas freezes of ACC outputs
  @description     freezes provided data from ACC

@startuml
Start
Partition LOPC_v_ProcessMeasFreeze(){
If (running simulation (MTS)) Then (True)
: Freeze of Incoming Required ports;
endif
: Freeze all the provide ports form LOPC;
: Free copies of data to Internal Buffer;
}
End
@enduml
  @return          None

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-137-0008a220

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
**************************************************************************** */
void LOPC_v_ProcessMeasFreeze(void)
{

  /*------------------------------- Input ----------------------------------*/
#ifdef FCT_SIMU
  /* Freeze input data only in simulation (as in ECU SW adapter already does this for us) */
#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */

#else /* Legacy code */

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&LOPC_FreezeBufferLongCtrlResp, LOPC_pLongCtrlResp, sizeof(LongCtrlInput_t));
  (void)MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LONG_CTRL_INPUT, &LOPC_FreezeBufferLongCtrlResp, sizeof(LongCtrlInput_t));
#else
  (void)MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LONG_CTRL_INPUT, (void*)LOPC_pLongCtrlResp, sizeof(LongCtrlInput_t));
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

#if (CFG_ACC_LEVER_INPUT)
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&LOPC_FreezeBufferAccLeverIn, LOPC_pAccLever, sizeof(AccLeverInput_t));
  (void)MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_ACC_LEVER_INPUT, &LOPC_FreezeBufferAccLeverIn, sizeof(AccLeverInput_t));
#else
  (void)MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_ACC_LEVER_INPUT, (void*)LOPC_pAccLever, sizeof(AccLeverInput_t));
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/
#endif /*CFG_ACC_LEVER_INPUT*/

#if (FCT_CFG_TCI)
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&LOPC_FreezeBufferTCIInput, LOPC_pTCIInput, sizeof(TCIInput_t));
  (void)MeasFreeze_Lopc_GlobVar(TCI_MEAS_ID_INPUT, &LOPC_FreezeBufferTCIInput, sizeof(TCIInput_t));
#else
  (void)MeasFreeze_Lopc_StackVar(TCI_MEAS_ID_INPUT, (void*)LOPC_pTCIInput, sizeof(TCIInput_t));
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/
#endif /* FCT_CFG_TCI */
#endif /* FCT_CFG_ACT_CODE_VERSION */
#endif /*FCT_SIMU*/

  /*------------------------------- Output ----------------------------------*/

#if (FCT_CFG_ACT_CODE_VERSION)

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

#if (FCT_CFG_HP_TFC_PORT_CNT)
  memcpy(&LOPC_FreezeBufferTargetFollowState, pt_LOPC_OUT_HP_TFSP, sizeof(TargetFollowStatePort_t));
  MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LOPC_TFSP, (void*)&LOPC_FreezeBufferTargetFollowState, sizeof(TargetFollowStatePort_t));
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
  MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LOPC_OUT_EVCP, pt_LOPC_OUT_EVCP, sizeof(ACT_EgoVehicleCommandPort_t));
#endif

#else /* (FCT_VEH_CFG_FREEZE_USE_CALLBACK) */

#if (FCT_CFG_HP_TFC_PORT_CNT)
  MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LOPC_TFSP, (void*)pt_LOPC_OUT_HP_TFSP, sizeof(TargetFollowStatePort_t));
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
  MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LOPC_OUT_EVCP, pt_LOPC_OUT_EVCP, sizeof(ACT_EgoVehicleCommandPort_t));
#endif

#endif  /* (FCT_VEH_CFG_FREEZE_USE_CALLBACK) */

#else /* Legacy code */

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  (void)memcpy(&LOPC_FreezeBufferVehLongOut, LOPC_pFctVehLongOut, sizeof(FctVeh2SenInfo_t));
  (void)MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_FCT_VEH_2_SEN, &LOPC_FreezeBufferVehLongOut, sizeof(FctVeh2SenInfo_t));
#endif
  (void)memcpy(&LOPC_FreezeBufferLongCtrlOut, LOPC_pLongCtrlOutput, sizeof(LongCtrlOutput_t));
  (void)MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LONG_CTRL_OUTPUT, &LOPC_FreezeBufferLongCtrlOut, sizeof(LongCtrlOutput_t));
#if (FCT_CFG_TCI)
  (void)memcpy(&LOPC_FreezeBufferTCIOutput, LOPC_pTCIOutput, sizeof(TCIOutput_t));
  (void)MeasFreeze_Lopc_GlobVar(TCI_MEAS_ID_OUTPUT, &LOPC_FreezeBufferTCIOutput, sizeof(TCIOutput_t));
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  (void)memcpy(&LOPC_FreezeBufferErrorOut, LOPC_pErrorOut, sizeof(LOPCErrorOut_t));
  (void)MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LOPC_ERROR_OUT, &LOPC_FreezeBufferErrorOut, sizeof(LOPCErrorOut_t));
#endif

#else

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  (void)MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_FCT_VEH_2_SEN, (void*)LOPC_pFctVehLongOut, sizeof(FctVeh2SenInfo_t));
#endif
#if (FCT_CFG_TCI)
  (void)MeasFreeze_Lopc_StackVar(TCI_MEAS_ID_OUTPUT, LOPC_pTCIOutput, sizeof(TCIOutput_t));
#endif
  (void)MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LONG_CTRL_OUTPUT, (void*)LOPC_pLongCtrlOutput, sizeof(LongCtrlOutput_t));
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

/*ERROR output*/
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  (void)MeasFreeze_Lopc_StackVar(FCT_MEAS_ID_LOPC_ERROR_OUT, (void*)LOPC_pErrorOut, sizeof(LOPCErrorOut_t));
#endif /*FCT_CFG_ERROR_OUTPUT_VEH*/

#endif /* FCT_CFG_ACT_CODE_VERSION */

}
#endif  /* ENDIF FCT_MEASUREMENT */


#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

/** @} end defgroup */
