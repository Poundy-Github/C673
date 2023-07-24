/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Planner and Controller))

PACKAGENAME:               frame_locc_ext.h

DESCRIPTION:               External header file for frame locc

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 2.3

**************************************************************************** */
#ifndef FRAME_LOCC_EXT_H
#define FRAME_LOCC_EXT_H

/*!
   @defgroup acc_long_veh  ACC_LONG_VEH
   @ingroup fct_veh
@{ */ 

/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT))
/*****************************************************************************
  INCLUDES
*****************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/
#ifndef FCT_MEAS_ID_LOCC_INPUT_SIGHEADERS
#define FCT_MEAS_ID_LOCC_INPUT_SIGHEADERS (0x20274560) 
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! LOCC required port struct  Inputs required by LOCC component for vehicle cycle processing */
typedef struct
{
  const FCTCtrlData_t                   *pt_LOCC_IN_Ctrl;

  const ACT_CruiseControlCommandPort_t  *pt_LOCC_IN_CCCP;

  const LongCtrlInput_t                 *pt_LOCC_IN_EgoVehDynCtrl;
  const VehDyn_t                        *pt_LOCC_IN_EgoVehDynState;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  const ACT_CC_VehicleSpeedStatePort_t  *pt_LOCC_IN_VSSP;
#endif
}
LOCC_ReqPortList_t;


/*! LOCC provide ports struct */
typedef struct
{
  ACT_CruiseControlStatePort_t          *pt_LOCC_OUT_CCSP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  ACT_CC_VehicleSpeedCommandPort_t      *pt_LOCC_OUT_VSCP;
#endif
}
LOCC_ProPortList_t;


/*! LOCC Sync-ref structure. Declared here so that simulation can instantiate */
typedef struct
{
  SignalHeader_t sSigHeader;       /*!<sSigHeader */
  SignalHeader_t t_SH_CTRL;         /*!< Signal Header of control port */

  SignalHeader_t t_LOCC_IN_CCCP;    /* Signal Header of LOCC CruiseControlCommandPort */

#if (ACT_CFG_CC_VSC_PORT_CNT)
  SignalHeader_t t_LOCC_IN_VSSP;    /* Signal Header of LOCC VehicleSpeedStatePort */
#endif

  SignalHeader_t t_EgoVehDynCtrl;   /*!< The ego vehicle DMC data */
  SignalHeader_t t_EgoVehDynState;  /*!< The ego vehicle VDY data */
}
LOCC_SyncRef_t;


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void LOCC_v_Exec(const LOCC_ReqPortList_t *p_RequirePorts, const LOCC_ProPortList_t *p_ProvidePorts, const FCT_OP_MODE_t t_OpMode, const AS_t_ServiceFuncts *p_ServiceFuncts);
#else
extern void LOCC_v_Exec(const LOCC_ReqPortList_t *p_RequirePorts, const LOCC_ProPortList_t *p_ProvidePorts, const FCT_OP_MODE_t t_OpMode);
#endif


#ifdef __cplusplus
};
#endif

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) */
#endif  /*!< FRAME_LOCC_EXT_H */

/** @} end defgroup */
