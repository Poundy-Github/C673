/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/LOP (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               lop_main.c

DESCRIPTION:               Main functions for LOP in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.8 $

---*/ /*---
CHANGES:                    $Log: lop_main.c  $
CHANGES:                    Revision 1.8 2018/06/13 15:59:35CEST uidj5069 
CHANGES:                    Unused Function Parameter <const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP> removed
CHANGES:                    Revision 1.7 2018/06/11 08:10:25CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Remove old "Start Coordination"
CHANGES:                    Revision 1.6 2017/11/21 10:47:33CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Revision 1.5 2017/11/02 15:25:56CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Integration of Info <b_StartTrial> of Target Follow Controller into Vehicle Speed Control State
CHANGES:                    Revision 1.4 2017/10/26 10:15:37CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Additional Input Port <EgoVehicleStatePort> for LOP Target Follow Control
CHANGES:                    Revision 1.3 2017/10/20 10:05:20CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    GEN 4 Bugfix - Port Assignment
CHANGES:                    Revision 1.2 2017/10/10 15:31:44CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Updates for Target Follow Controller
CHANGES:                    Revision 1.1 2017/03/15 20:58:44CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "lop.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP))


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

/*! @cond Doxygen_Suppress */
SET_MEMSEC_VAR(LOP_State)
LOP_State_t LOP_State;
/*! @endcond Doxygen_Suppress */


/*! Declaration of pointers to LOP input ports for access within this component - NEW */

#if (LOP_CFG_VSC_PORT_CNT)
  SET_MEMSEC_VAR(at_LOP_IN_VSCP)
  LOPC_VehicleSpeedCommandPort_t at_LOP_IN_VSCP[LOP_CFG_VSC_PORT_CNT];
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(at_LOP_IN_DSCP)
  LOPC_DistanceSpeedCommandPort_t at_LOP_IN_DSCP[LOP_CFG_DSC_PORT_CNT];
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(at_LOP_IN_DCCP)
  LOPC_DistanceCurveCommandPort_t at_LOP_IN_DCCP[LOP_CFG_DCC_PORT_CNT];
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_VAR(at_LOP_IN_TFCP)
  LOPC_TargetFollowCommandPort_t at_LOP_IN_TFCP[FCT_CFG_HP_TFC_PORT_CNT];
#endif

SET_MEMSEC_VAR(t_LOP_IN_IVSP)
LOPC_IdealVehicleStatePort_t t_LOP_IN_IVSP;

SET_MEMSEC_VAR(t_LOC_IN_EVSP)
LOPC_EgoVehicleStatePort_t t_LOP_IN_EVSP;


/*! Declaration of pointers to LOP output ports for access within this component - NEW */

#if (LOP_CFG_VSC_PORT_CNT)
  SET_MEMSEC_VAR(at_LOP_OUT_VSSP)
  LOPC_VehicleSpeedStatePort_t at_LOP_OUT_VSSP[LOP_CFG_VSC_PORT_CNT];
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(at_LOP_OUT_DSSP)
  LOPC_DistanceSpeedStatePort_t at_LOP_OUT_DSSP[LOP_CFG_DSC_PORT_CNT];
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(at_LOP_OUT_DCSP)
  LOPC_DistanceCurveStatePort_t at_LOP_OUT_DCSP[LOP_CFG_DCC_PORT_CNT];
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_VAR(at_LOP_OUT_TFSP)
  LOPC_TargetFollowStatePort_t at_LOP_OUT_TFSP[FCT_CFG_HP_TFC_PORT_CNT];
#endif

SET_MEMSEC_VAR(t_LOP_OUT_IVCP)
LOPC_IdealVehicleCommandPort_t t_LOP_OUT_IVCP;

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/
#if (LOP_CFG_VSC_PORT_CNT)
  SET_MEMSEC_VAR(t_LOP_LOC_VSOP)
  LOP_VehicleSpeedOutputPort_t t_LOP_LOC_VSOP;
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(t_LOP_LOC_DSOP)
  LOP_DistanceSpeedOutputPort_t t_LOP_LOC_DSOP;
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  SET_MEMSEC_VAR(t_LOP_LOC_DCOP)
  LOP_DistanceCurveOutputPort_t t_LOP_LOC_DCOP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_VAR(t_LOP_LOC_TFOP)
  LOP_TargetFollowOutputPort_t t_LOP_LOC_TFOP;
#endif


/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/

static void LOP_v_SetupPorts(const LOP_ReqPortList_t *pRequirePorts, const LOP_ProPortList_t *pProvidePorts);

static void LOP_v_MeasFreeze(void);
static void LOP_v_MeasCallback(void);
static void LOP_v_InitEveryCycle(void);
static void LOP_v_InitPersistentData(void);

/*************************************************************************************************************************
  Functionname:    LOP_v_Process                                                                                    */ /*!

  @brief           Main processing function of LOP sub-component

  @description     Main processing function of LOP sub-component

  @return          void

  @param[in]       const LOP_ReqPortList_t * pRequirePorts
  @param[in]       const LOP_ProPortList_t * pProvidePorts

  @glob_in         -

  @created         -
  @changed         12/11/2015

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOP_v_Process(const LOP_ReqPortList_t *pRequirePorts, const LOP_ProPortList_t *pProvidePorts)
{
  /* Assign local pointers */
  LOP_v_SetupPorts(pRequirePorts, pProvidePorts);

  switch(LOP_State)
  {
  case LOP_OK:
    {
      LOP_v_InitEveryCycle();

      /* Calling of all functions to be done here in order */
#if (LOP_CFG_VSC_PORT_CNT)
      LOP_v_VehicleSpeedControl_Process(&t_LOP_IN_IVSP, at_LOP_IN_VSCP, &t_LOP_LOC_VSOP, at_LOP_OUT_VSSP);
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
      LOP_v_DistanceSpeedControl_Process (&t_LOP_IN_IVSP, at_LOP_IN_DSCP, &t_LOP_LOC_DSOP, at_LOP_OUT_DSSP);
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
      LOP_v_DistanceCurveControl_Process (&t_LOP_IN_IVSP, at_LOP_IN_DCCP, &t_LOP_LOC_DCOP, at_LOP_OUT_DCSP);
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
      LOP_v_TargetFollowControl_Process(&t_LOP_IN_IVSP, &t_LOP_IN_EVSP, at_LOP_IN_TFCP, &t_LOP_LOC_TFOP, at_LOP_OUT_TFSP);
#endif

      LOP_v_ControlArbitration_Process (
#if (LOP_CFG_VSC_PORT_CNT)
                                        &t_LOP_LOC_VSOP,
#endif
#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
                                        &t_LOP_LOC_DSOP,
#endif
#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
                                        &t_LOP_LOC_DCOP,
#endif
#if (FCT_CFG_HP_TFC_PORT_CNT)
                                        &t_LOP_LOC_TFOP,
#endif
                                        &t_LOP_OUT_IVCP);

      LOP_v_Custom_Process();

      break;
    }
  case LOP_INIT:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
  default:
    LOP_v_InitEveryCycle();
    LOP_v_InitPersistentData();
    break;
  }

  /* LOP Measurement Freeze */
  LOP_v_MeasFreeze();

  /* Reset local pointers */
}


/*************************************************************************************************************************
  Functionname:    LOP_v_SetupPorts                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       LOP_ReqPortList_pt pRequirePorts
  @param[in]       LOP_ProPortList_pt pProvidePorts

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         05.05.2017
  @changed         05.05.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-8382-9699-839
*************************************************************************************************************************/
static void LOP_v_SetupPorts(const LOP_ReqPortList_t *pRequirePorts, const LOP_ProPortList_t *pProvidePorts)
{
  uint8 i;

/*! Assignment of pointers to LOP input ports for access within this component */
#if (LOP_CFG_VSC_PORT_CNT)
  for (i=0; i<LOP_CFG_VSC_PORT_CNT; i++)
  {
    at_LOP_IN_VSCP[i] = pRequirePorts->at_LOP_IN_VSCP[i];
  }
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  for (i=0; i<LOP_CFG_DSC_PORT_CNT; i++)
  {
    at_LOP_IN_DSCP[i] = pRequirePorts->at_LOP_IN_DSCP[i];
  }
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  for (i=0; i<LOP_CFG_DCC_PORT_CNT; i++)
  {
    at_LOP_IN_DCCP[i] = pRequirePorts->at_LOP_IN_DCCP[i];
  }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    at_LOP_IN_TFCP[i] = pRequirePorts->at_LOP_IN_TFCP[i];
  }
#endif

  t_LOP_IN_IVSP = pRequirePorts->t_LOP_IN_IVSP;
  t_LOP_IN_EVSP = pRequirePorts->t_LOP_IN_EVSP;


/*! Assignment of pointers to LOP output ports for access within this component - NEW */
#if (LOP_CFG_VSC_PORT_CNT)
  for (i=0; i<LOP_CFG_VSC_PORT_CNT; i++)
  {
    at_LOP_OUT_VSSP[i] = pProvidePorts->at_LOP_OUT_VSSP[i];
  }
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  for (i=0; i<LOP_CFG_DSC_PORT_CNT; i++)
  {
    at_LOP_OUT_DSSP[i] = pProvidePorts->at_LOP_OUT_DSSP[i];
  }
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  for (i=0; i<LOP_CFG_DCC_PORT_CNT; i++)
  {
    at_LOP_OUT_DCSP[i] = pProvidePorts->at_LOP_OUT_DCSP[i];
  }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    at_LOP_OUT_TFSP[i] = pProvidePorts->at_LOP_OUT_TFSP[i];
  }
#endif

  t_LOP_OUT_IVCP = pProvidePorts->t_LOP_OUT_IVCP;

  return;
}


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LOP_v_MeasCallback                                                                                   */ /*!

  @brief           Central LOP MEASFreezeDataMTS callback function

  @description     Central LOP MEASFreezeDataMTS callback function. Since callback information is not used in LOP, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for LOP sub-component

  @pre             -
  @post            -

  @created         -
  @changed         07.03.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOP_v_MeasCallback(void)
{
  return;
}
#endif /* FCT_MEASUREMENT */


/*************************************************************************************************************************
  Functionname:    LOP_v_MeasFreeze                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       void : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         21.04.2017
  @changed         21.04.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOP_v_MeasFreeze(void)
{

  /*! Get data for measurement freeze in device */

  /*! Freeze device data */
//  FCT_FREEZE_DATA(pt_LOPInput->t_FrameFreezes.pt_LOP_DeviceMeasInfoFreeze, pt_LOPInput->t_FrameFreezes.pt_LOP_DeviceMeasInfo, &LOP_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  //pt_LOPInput->t_FrameFreezes.pt_LOP_SimMeasInfo->t_LOP_FreezeOutput = *(pt_LOPOutput);

  /*! Freeze simulation data */
  //FCT_FREEZE_DATA(pt_LOPInput->t_FrameFreezes.pt_LOP_SimMeasInfoFreeze, pt_LOPInput->t_FrameFreezes.pt_LOP_SimMeasInfo, LOP_v_MeasCallback);
#endif

}
/*************************************************************************************************************************
  Functionname:    LOP_v_InitPersistentData                                                                         */ /*!

  @brief           Initialize persistent memory structures in LOP component

  @description     Initialize persistent memory structures in LOP component

  @return          -

  @param[in]       -


  @created         25.10.2016
  @changed         25.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOP_v_InitPersistentData(void)
{

/*Initialising Output*/

  /* Initialize inputs */

  /*Note: Pointers to Inputs from RTE Ports are not initialized because their value is reset every cycle from external inputs */

}
/*************************************************************************************************************************
  Functionname:    LOP_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output data structures for LOP component

  @description     Initialize input-output data structures for LOP component

  @return          -

  @param[in]       -

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOP_v_InitEveryCycle(void)
{
  /* Initialize inputs */
}

/*************************************************************************************************************************
  Functionname:    LOP_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of LOP sub-component

  @description     Set operation mode of LOP sub-component based on given value

  @return          -

  @param[in]       t_LOPOpModeValue : LOP operation mode value [full range of datatype LOPState_t as in lop_ext.h]

  @glob_in         LOPState : LOP operation mode variable [full range of datatype LOPState_t as in lop_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : FCT support for LOP sub-component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOP_v_SetOperationMode(const LOP_State_t t_LOPOpModeValue)
{
  LOP_State = t_LOPOpModeValue;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#endif /* ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP)) */

