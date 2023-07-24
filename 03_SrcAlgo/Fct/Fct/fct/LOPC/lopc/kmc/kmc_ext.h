/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_ext.h

DESCRIPTION:               External header file for CruiseControl functionality in KMC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            Revision: 1.30.1.5

**************************************************************************** */

#ifndef KMC_EXT_H_INCLUDED
#define KMC_EXT_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/*!
@defgroup   kmc KMC (Kinematic Motion Control)
@ingroup    lopc_base_lopc
@brief      Module for KMC functionalities
@description
In this context KMC in LoPC is responsible for:\n
   -The determination of the control state with the internal state machine logic.\n
   -The calculation of the cruise control acceleration based on the difference between the current speed and the set speed 
    as well as the state in the state machine.\n
   -The calculation of the maximum and minimum commanded accelerations within different states by abitration of the cruise control, 
    the speed limit assist and the ACC object control in component LoHP. \n
   -The determination of the maximum and minimum acceleration based on the jerk limit for comfortable reason.\n
   -The coordination of the standstill and drive off based on the driver input and traffic situation.\n
   -The setting of the requested acceleration to dynamics management.
 */

/** 
@defgroup   kmc_ext Kmc_ext_h
@ingroup    kmc
@brief      KMC external header file
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lopc_ext.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))


/* GLOBAL VARIABLES (KOMPONENT EXTERNAL) */


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_LOPC_COMPONENT)
extern void KMC_v_Process(const times_t cycle_time,
                          const VehDyn_t * pVehDyn,
                          const PowerTrain_t * pPowerTrain,
#if (CFG_ACC_LEVER_INPUT)
                          const AccLeverInput_t * pAccLever,
#endif
                          const LongCtrlInput_t * pLongCtrlResp,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                          const acc_object_t * pAccDisplayObj,
                          const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                          const FCTSenAccOOI_t* pFCTAccOOIData,
#endif
#if (FCT_CFG_SLA_FEATURE)
                          const SLAData_t* pSLAData,
#endif
                          FctVeh2SenInfo_t * pFctVehLongOut,
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
                          const Lodmc_output_t * pLoDmcOut,
#endif
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
                          const HEADOutputCustom_t * pHeadOutputCustom,
#endif
                          LongCtrlOutput_t * pLongCtrlCmd);
#endif /*FCT_CFG_LOPC_COMPONENT*/

#endif  /* FCT_CFG_CC */

/** @} end defgroup */

#endif /* ifndef KMC_EXT_H_INCLUDED */

