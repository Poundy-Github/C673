/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_locc_meas.c

DESCRIPTION:               File contains functions for freezing of information

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             31.01.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */

#include "frame_locc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) && (FCT_CFG_ACT_CODE_VERSION))

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


/****************   end of Buffers for MeasFreezes *******************/
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LOCC_v_FrameFreeze                                                                               */ /*!

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
void LOCC_v_FrameFreeze(void)
{

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

  MeasFreeze_Locc_GlobVar(FCT_MEAS_ID_LOCC_FRAME_DATA, &LOCCFrame, sizeof(LOCCFrame_t));
  MeasFreeze_Locc_GlobVar(FCT_MEAS_ID_LOCC_INPUT_SIGHEADERS, &LOCC_SyncRef, sizeof(LOCC_SyncRef_t));

  MeasFreeze_Locc_GlobVar(FCT_MEAS_ID_LOCC_LOPC_VSSP, (void*)pt_LOCC_IN_VSSP, sizeof(ACT_CC_VehicleSpeedStatePort_t));
  MeasFreeze_Locc_GlobVar(FCT_MEAS_ID_LOCC_LOPC_VSCP, (void*)pt_LOCC_OUT_VSCP, sizeof(ACT_CC_VehicleSpeedCommandPort_t));

#else /* FCT_VEH_CFG_FREEZE_USE_CALLBACK */

  MeasFreeze_Locc_StackVar(FCT_MEAS_ID_LOCC_FRAME_DATA, &LOCCFrame, sizeof(LOCCFrame_t));
  MeasFreeze_Locc_StackVar(FCT_MEAS_ID_LOCC_INPUT_SIGHEADERS, &LOCC_SyncRef, sizeof(LOCC_SyncRef_t));

  MeasFreeze_Locc_StackVar(FCT_MEAS_ID_LOCC_IN_VSSP, (void*)pt_LOCC_IN_VSSP, sizeof(ACT_CC_VehicleSpeedStatePort_t));
  MeasFreeze_Locc_StackVar(FCT_MEAS_ID_LOCC_OUT_VSCP, (void*)pt_LOCC_OUT_VSCP, sizeof(ACT_CC_VehicleSpeedCommandPort_t));

#endif /* FCT_VEH_CFG_FREEZE_USE_CALLBACK */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /* Algo Component State Output */
  if (LOCC_pCompState != NULL)
  {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
    memcpy(&LOCC_FreezeBufferVehCompState, LOCC_pCompState, sizeof(AlgoCompState_t));
    MeasFreeze_Locc_GlobVar(FCT_MEAS_ID_LOCC_COMP_STATE, &LOCC_FreezeBufferVehCompState, sizeof(AlgoCompState_t));
#else
    MeasFreeze_Locc_StackVar(FCT_MEAS_ID_LOCC_COMP_STATE, LOCC_pCompState, sizeof(AlgoCompState_t));
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
}


/* ***********************************************************************
  @fn              LOCC_v_ProcessMeasFreeze  */ /*! 
  @brief           meas freezes of ACC outputs
  @description     freezes provided data from ACC
  @return          None
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
**************************************************************************** */
void LOCC_v_ProcessMeasFreeze(void)
{

  /*------------------------------- Input ----------------------------------*/
#ifdef FCT_SIMU
  /* Freeze input data only in simulation (as in ECU SW adapter already does this for us) */
#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */

#endif /* FCT_CFG_ACT_CODE_VERSION */
#endif /*FCT_SIMU*/

  /*------------------------------- Output ----------------------------------*/

#if (FCT_CFG_ACT_CODE_VERSION)
  /* Todo: Write for new ports */

#endif /* FCT_CFG_ACT_CODE_VERSION */
}
#endif  /* ENDIF FCT_MEASUREMENT */


#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) && (FCT_CFG_ACT_CODE_VERSION)*/
