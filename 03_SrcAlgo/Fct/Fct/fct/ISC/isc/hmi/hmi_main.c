/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/HMI (Adaptive Cruise Control - Interface and State Coordinator - Human Machine Interface)

PACKAGENAME:               hmi_main.c

DESCRIPTION:               Main functions for HMI in ISC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

---*/ /*---
CHANGES:                    $Log: hmi_main.c  $
CHANGES:                    Revision 1.4 2018/06/11 14:56:59CEST uidj5069 
CHANGES:                    New Ports added for LOPC based Start Coordination
CHANGES:                    Revision 1.3 2018/04/09 14:51:00CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <HMI_v_InitPersistentData()> updated
CHANGES:                    Revision 1.2 2017/10/12 16:28:32CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port and Functionality for Target Control (ACC) added
CHANGES:                    Revision 1.1 2017/10/05 08:35:03CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/hmi/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:44CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hmi.h"

#if (FCT_CFG_ISC_COMPONENT)


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
SET_MEMSEC_VAR(HMI_State)
HMI_t_State HMI_State;
/*! @endcond Doxygen_Suppress */

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*! Input Ports required by HMI component for processing */
SET_MEMSEC_VAR(t_HMI_IN_HMIP)
ISC_HMI_InformationPort_t t_HMI_IN_HMIP;

SET_MEMSEC_VAR(t_HMI_IN_HMCP)
ISC_HMI_CommandPort_t t_HMI_IN_HMCP;

SET_MEMSEC_VAR(t_HMI_IN_SMSP)
ISC_SM_StatusPort_t t_HMI_IN_SMSP;

SET_MEMSEC_VAR(t_HMI_IN_LVSP)
ISC_LOC_StatePort_t t_HMI_IN_LVSP;


/*! Output Ports provided by HMI component after processing */
SET_MEMSEC_VAR(t_HMI_OUT_SMCP)
ISC_SM_CommandPort_t t_HMI_OUT_SMCP;

SET_MEMSEC_VAR(t_HMI_OUT_HMSP)
ISC_HMI_StatusPort_t t_HMI_OUT_HMSP;

#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(t_HMI_OUT_CCDP)
  ISC_CC_DegradationPort_t t_HMI_OUT_CCDP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  SET_MEMSEC_VAR(t_HMI_OUT_TCDP)
  ISC_TC_DegradationPort_t t_HMI_OUT_TCDP;
#endif

SET_MEMSEC_VAR(t_HMI_OUT_LVCP)
ISC_LOC_CommandPort_t t_HMI_OUT_LVCP;


/*! Local Buffered Input Command State */
SET_MEMSEC_VAR(t_HMI_LOC_ISCC)
ACT_ISC_Command_t t_HMI_LOC_ISCC;

/* Local Headway Setting Stage */
SET_MEMSEC_VAR(u_HMI_LOC_Headway_Stage)
uint8 u_HMI_LOC_Headway_Stage;

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/
static void HMI_v_SetupPorts(const HMI_ReqPortList_t *pRequirePorts, const HMI_ProPortList_t *pProvidePorts);

static void HMI_v_MeasFreeze(void);
static void HMI_v_MeasCallback(void);
static void HMI_v_InitEveryCycle(void);
static void HMI_v_InitPersistentData(void);

/*************************************************************************************************************************
  Functionname:    HMI_v_Process                                                                                    */ /*!

  @brief           Main processing function of HMI sub-component

  @description     Main processing function of HMI sub-component

  @return          void

  @param[in]       pt_HMI_InputGlob : Reference to global input struct to HMI [defined as per hmi_ext.h]

  @glob_in         -

  @created         -
  @changed         12/11/2015

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HMI_v_Process(const HMI_ReqPortList_t *pRequirePorts, const HMI_ProPortList_t *pProvidePorts)
{
  /* Assign HMI port pointers */
  HMI_v_SetupPorts(pRequirePorts, pProvidePorts);

  switch(HMI_State)
  {
  case HMI_OK:
    {
      HMI_v_InitEveryCycle();

      /* Calling of all functions to be done here in order */
      HMI_v_Generic_Process();
      HMI_v_Custom_Process();

      break;
    }
  case HMI_INIT:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
  default:
    HMI_v_InitEveryCycle();
    HMI_v_InitPersistentData();
    break;
  }

  /* HMI Measurement Freeze */
  HMI_v_MeasFreeze();
}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    HMI_v_MeasCallback                                                                                   */ /*!

  @brief           Central HMI MEASFreezeDataMTS callback function

  @description     Central HMI MEASFreezeDataMTS callback function. Since callback information is not used in HMI, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for HMI sub-component

  @pre             -
  @post            -

  @created         -
  @changed         07.03.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void HMI_v_MeasCallback(void)
{
  return;
}
#endif /* FCT_MEASUREMENT */

/*************************************************************************************************************************
  Functionname:    HMI_v_MeasFreeze                                                                                 */ /*!

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
static void HMI_v_MeasFreeze(void)
{

  /*! Get data for measurement freeze in device */

  /*! Freeze device data */
  //FCT_FREEZE_DATA(pt_HMIInput->t_FrameFreezes.pt_HMI_DeviceMeasInfoFreeze, pt_HMIInput->t_FrameFreezes.pt_HMI_DeviceMeasInfo, &HMI_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  //pt_HMIInput->t_FrameFreezes.pt_HMI_SimMeasInfo->t_HMI_FreezeOutput = *(pt_HMIOutput);

  /*! Freeze simulation data */
  //FCT_FREEZE_DATA(pt_HMIInput->t_FrameFreezes.pt_HMI_SimMeasInfoFreeze, pt_HMIInput->t_FrameFreezes.pt_HMI_SimMeasInfo, HMI_v_MeasCallback);
#endif
}

/*************************************************************************************************************************
  Functionname:    HMI_v_InitPersistentData                                                                         */ /*!

  @brief           Initialize persistent memory structures in HMI component

  @description     Initialize persistent memory structures in HMI component

  @return          -

  @param[in]       -


  @created         25.10.2016
  @changed         25.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void HMI_v_InitPersistentData(void)
{
  /* Set all local stored input buttons to FALSE */
  t_HMI_LOC_ISCC.b_Main = FALSE;
  t_HMI_LOC_ISCC.b_Set = FALSE;
  t_HMI_LOC_ISCC.b_Resume = FALSE;
  t_HMI_LOC_ISCC.b_Cancel = FALSE;
  t_HMI_LOC_ISCC.b_SpeedDec = FALSE;
  t_HMI_LOC_ISCC.b_SpeedInc = FALSE;
  t_HMI_LOC_ISCC.b_HeadwayInc = FALSE;

  /* Set Headway Setting Stage to Init Value */
  u_HMI_LOC_Headway_Stage = HMI_ACC_HEADWAY_STAGE_INIT;
}

/*************************************************************************************************************************
  Functionname:    HMI_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output data structures for HMI component

  @description     Initialize input-output data structures for HMI component

  @return          -

  @param[in]       -

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void HMI_v_InitEveryCycle(void)
{
  /* Initialize inputs every cycle */
}

/*************************************************************************************************************************
  Functionname:    HMI_v_SetupPorts                                                                                   */ /*!

  @brief           Assign ports to HMI by port lists

  @description     Assign ports to HMI by port lists

  @return          -

  @param[in]       -

  @glob_in         
  @glob_out        

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void HMI_v_SetupPorts(const HMI_ReqPortList_t *pRequirePorts, const HMI_ProPortList_t *pProvidePorts)
{
/*! Input Ports required by HMI component for processing */
  t_HMI_IN_HMIP = pRequirePorts->t_HMI_IN_HMIP;
  t_HMI_IN_HMCP = pRequirePorts->t_HMI_IN_HMCP;
  t_HMI_IN_SMSP = pRequirePorts->t_HMI_IN_SMSP;
  t_HMI_IN_LVSP = pRequirePorts->t_HMI_IN_LVSP;

/*! Output Ports provided by HMI component after processing */
  t_HMI_OUT_SMCP = pProvidePorts->t_HMI_OUT_SMCP;
  t_HMI_OUT_HMSP = pProvidePorts->t_HMI_OUT_HMSP;

#if (FCT_CFG_LOCC_COMPONENT)
  t_HMI_OUT_CCDP = pProvidePorts->t_HMI_OUT_CCDP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  t_HMI_OUT_TCDP = pProvidePorts->t_HMI_OUT_TCDP;
#endif

  t_HMI_OUT_LVCP = pProvidePorts->t_HMI_OUT_LVCP;
}

/*************************************************************************************************************************
  Functionname:    HMI_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of HMI sub-component

  @description     Set operation mode of HMI sub-component based on given value

  @return          -

  @param[in]       t_HMIOpModeValue : HMI operation mode value [full range of datatype HMIState_t as in hmi_ext.h]

  @glob_in         HMIState : HMI operation mode variable [full range of datatype HMIState_t as in hmi_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_HMIC_COMPONENT : FCT support for HMI sub-component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HMI_v_SetOperationMode(const HMI_t_State t_HMIOpModeValue)
{
  HMI_State = t_HMIOpModeValue;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#endif /* (FCT_CFG_ISC_COMPONENT) */

