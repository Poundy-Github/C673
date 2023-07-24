/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACT/LOCC (Adaptive Cruise Control - Longitudinal Cruise Control)

PACKAGENAME:               frame_locc_types.h

DESCRIPTION:               Types header file for LOCC in FCT_VEH task

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             02.06.2017

VERSION:                   $Revision: 1.2 $

---*/ /*---

**************************************************************************** */

#ifndef _LOCC_TYPES_INCLUDED
#define _LOCC_TYPES_INCLUDED

/**
   @defgroup Cruise Control (CC) Frame
   @ingroup fct_veh_cc
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
//#include "locc_ver.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! Typedef of <CruiseControlCommandPort> port from LOCC to CC component */
typedef struct
{
  const ACT_CruiseControlCommand_t *pt_CCC;
  const FunctionDegradation_t *pt_FD;
}
LOCC_CruiseControlCommandPort_t;

/*! Typedef of <VehicleSpeedStatePort> port from LOCC to CC component */
typedef struct
{
  const ACT_VehicleSpeedState_t *pt_VSS;
}
LOCC_VehicleSpeedStatePort_t;

/*! Typedef of <EgoVehicleInfoPort> port from LOCC to CC component */
typedef struct
{
  float32 f_DriverIntendCurve;      /* Ego trajectory target curve estimated by steering angle [1/m] */
  float32 f_LongAcceleration;       /* Absolute longitudinal acceleration of ego vehicle [m/s^2] */
  float32 f_LongVeloReal;           /* Real longitudinal velocity of ego vehicle [m/s] */
  float32 f_LongVeloDisplay;        /* Display longitudinal velocity of ego vehicle [kmh | mph] */
  boolean b_VeloDispUnitKmh;        /* Velocity display unit is [kmh] */
  boolean b_Override_Accel;         /* Driver overriding by accelerator pedal */
  boolean b_Override_Decel;         /* Driver overriding by decelerator pedal */
  boolean b_StandStill;             /* Standstill of ego vehicle */
  boolean b_Valid;                  /* State is valid */
}
LOCC_EgoVehicleInfo_t;
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const LOCC_EgoVehicleInfo_t *pt_EVI;
}
LOCC_EgoVehicleInfoPort_t;


/*! Typedef of <CruiseControlStatePort> port from CC to LOCC component */
typedef struct
{
  ACT_CruiseControlState_t *pt_CCS;
}
LOCC_CruiseControlStatePort_t;

/*! Typedef of <VehicleSpeedCommandPort> port from CC to LOCC component */
typedef struct
{
  ACT_VehicleSpeedCommand_t *pt_VSC;
}
LOCC_VehicleSpeedCommandPort_t;


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT)) */

#endif  /*!< _LOCC_TYPES_INCLUDED */

/** @} end defgroup */
