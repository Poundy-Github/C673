/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC (Adaptive Cruise Control - Interface and State Coordinator)


PACKAGENAME:               lokmc_meas.c

DESCRIPTION:               File contains functions for freezing of information

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             31.01.2017

VERSION:                   $Revision: 1.5 $

---*/ /*---
CHANGES:                    $Log: isc_meas.c  $
CHANGES:                    Revision 1.5 2018/06/21 08:37:24CEST uidj5069 
CHANGES:                    Additional Component Ports measured
CHANGES:                    Revision 1.4 2018/04/05 15:04:56CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Freezing of ISC Ports added
CHANGES:                    Revision 1.3 2018/02/23 16:33:43CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Meas freeze of new output ports added
CHANGES:                    Revision 1.2 2017/10/11 08:03:54CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Updates for GEN 4
CHANGES:                    Revision 1.1 2017/10/05 08:33:19CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/frame_isc/project.pj
CHANGES:                    Revision 1.1 2017/03/10 10:48:13CET Koschalka, Mike (uidg3250) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOKMC_LongitudinalKinematicMotionControl/04_Engineering/01_Source_Code/LOKMC/frame_lokmc/project.pj
CHANGES:                    first filled version

**************************************************************************** */

#include "isc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))

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
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
/*input ports*/
#ifdef FCT_SIMU
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(ISC_FreezeBufferAccLeverIn)
  static AccLeverInput_t ISC_FreezeBufferAccLeverIn;   /*!<internal data buffer for measfreezing ACCLeverInput.*/

/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(ISC_FreezeBufferLongCtrlResp)
  static LongCtrlInput_t ISC_FreezeBufferLongCtrlResp; /*!<internal data buffer for measfreezing LongCtrlInput.*/
#endif /*FCT_SIMU*/

/*output ports*/
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(ISC_FreezeBufferVehLongOut)
  static FctVeh2SenInfo_t ISC_FreezeBufferVehLongOut;               /*!<internal data buffer for measfreezing Veh2SenInfo OUTPUT interface.*/
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(ISC_FreezeBufferLongCtrlOut)
  static LongCtrlOutput_t ISC_FreezeBufferLongCtrlOut;              /*!<internal data buffer for measfreezing LongCtrl OUTPUT interface.*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(ISC_FreezeBufferVehCompState)
  static  AlgoCompState_t ISC_FreezeBufferVehCompState;              /*!<internal data buffer for measfreezing Algo Component State OUTPUT interface.*/
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/

SET_MEMSEC_VAR(ISC_FreezeBufferTargetControlCommand)
  static TargetControlCommandPort_t ISC_FreezeBufferTargetControlCommand;   /*!<internal data buffer for measfreezing TargetControlCommand OUTPUT interface.*/

#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

/****************   end of Buffers for MeasFreezes *******************/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    ISC_v_FrameFreeze                                                                        */ /*!

  @brief           Functional Summary

  @description     Detailed Design

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

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void ISC_v_FrameFreeze(void)
{

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_FRAME_DATA, &ISCFrame, sizeof(ISCFrame_t));
  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_INPUT_SIGHEADERS, &ISC_SyncRef, sizeof(ISC_SyncRef_t));

  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_INFO_PORT, (void*)pt_ISC_IN_IIP, sizeof(ACT_ISC_InformationPort_t));
  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_COMMAND_PORT, (void*)pt_ISC_IN_ICP, sizeof(ACT_ISC_CommandPort_t));
  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_STATUS_PORT, (void*)pt_ISC_OUT_ISP, sizeof(ACT_ISC_StatusPort_t));

  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_CC_STATE_PORT, (void*)pt_ISC_IN_CCSP, sizeof(ACT_CruiseControlStatePort_t));
  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_CC_COMMAND_PORT, (void*)pt_ISC_OUT_CCCP, sizeof(ACT_CruiseControlCommandPort_t));

  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_LOC_STATE_PORT, (void*)pt_ISC_IN_LVSP, sizeof(ACT_LogicVehicleStatePort_t));
  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_LOC_COMMAND_PORT, (void*)pt_ISC_OUT_LVCP, sizeof(ACT_LogicVehicleCommandPort_t));

#else /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_FRAME_DATA, &ISCFrame, sizeof(ISCFrame_t));
  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_INPUT_SIGHEADERS, &ISC_SyncRef, sizeof(ISC_SyncRef_t));

  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_IN_IIP, (void*)pt_ISC_IN_IIP, sizeof(ACT_ISC_InformationPort_t));
  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_IN_ICP, (void*)pt_ISC_IN_ICP, sizeof(ACT_ISC_CommandPort_t));
  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_OUT_ISP, (void*)pt_ISC_OUT_ISP, sizeof(ACT_ISC_StatusPort_t));

  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_IN_CCSP, (void*)pt_ISC_IN_CCSP, sizeof(ACT_CruiseControlStatePort_t));
  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_OUT_CCCP, (void*)pt_ISC_OUT_CCCP, sizeof(ACT_CruiseControlCommandPort_t));

  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_IN_LVSP, (void*)pt_ISC_IN_LVSP, sizeof(ACT_LogicVehicleStatePort_t));
  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_OUT_LVCP, (void*)pt_ISC_OUT_LVCP, sizeof(ACT_LogicVehicleCommandPort_t));

#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

  /*Algo Component State Output*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  if (FCTVEH_pACCCompState != NULL)
  {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
    memcpy(&ISC_FreezeBufferVehCompState, FCTVEH_pACCCompState, sizeof(AlgoCompState_t));
    MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_ISC_COMP_STATE, &ISC_FreezeBufferVehCompState, sizeof(AlgoCompState_t));
#else
    MeasFreeze_Isc_StackVar(FCT_MEAS_ID_ISC_COMP_STATE, FCTVEH_pACCCompState, sizeof(AlgoCompState_t));
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
}


/* ***********************************************************************
  @fn             ISC_v_ProcessMeasFreeze  */ /*! 
  @brief          meas freezes of ACC outputs
  @description    freezes provided data from ACC
  @return         None
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
**************************************************************************** */
void ISC_v_ProcessMeasFreeze(void)
{

  /*------------------------------- Input ----------------------------------*/
#ifdef FCT_SIMU
  /* Freeze input data only in simulation (as in ECU SW adapter already does this for us) */
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
#else
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

#if (CFG_ACC_LEVER_INPUT)

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
#else
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

#endif /*CFG_ACC_LEVER_INPUT*/

#endif /*FCT_SIMU*/

  /*------------------------------- Output ----------------------------------*/
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

#if (FCT_CFG_LOHP_COMPONENT)
  memcpy(&ISC_FreezeBufferTargetControlCommand, pt_ISC_OUT_TCCP, sizeof(TargetControlCommandPort_t));
  MeasFreeze_Isc_GlobVar(FCT_MEAS_ID_LOHP_TCCP, (void*)&ISC_FreezeBufferTargetControlCommand, sizeof(TargetControlCommandPort_t));
#endif

#else

#if (FCT_CFG_LOHP_COMPONENT)
  MeasFreeze_Isc_StackVar(FCT_MEAS_ID_LOHP_TCCP, (void*)pt_ISC_OUT_TCCP, sizeof(TargetControlCommandPort_t));
#endif

#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/
}
#endif  /* ENDIF FCT_MEASUREMENT */


#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT) */
