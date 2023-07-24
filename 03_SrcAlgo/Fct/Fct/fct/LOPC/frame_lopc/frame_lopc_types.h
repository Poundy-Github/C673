/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACT/LOPC (Adaptive Cruise Control - Longitudinal Planner & Controller)

PACKAGENAME:               lopc_ext.h

DESCRIPTION:               Types header file for LOPC in FCT_SEN task

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             02.06.2017

VERSION:                   $Revision: 1.14 $

---*/ /*---

**************************************************************************** */

#ifndef _LOPC_TYPES_INCLUDED
#define _LOPC_TYPES_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup   frame_lopc_types Frame_lopc_types
@brief      Internal type definitions for LOPC Component
@ingroup    lopc_base_frame
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_par.h"
#include "fct_glob_ext.h"
#include "lopc_cfg.h"
#include "frame_lopc_ver.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

#ifndef FCT_MEAS_ID_LOPC_STATIC_MEM
#define FCT_MEAS_ID_LOPC_STATIC_MEM  (0x20274400u)
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_LOPC_COMP_STATE
#define FCT_MEAS_ID_LOPC_COMP_STATE   (20274600u) 
#endif
#endif
/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

typedef uint32 LOPCSwVersion_t; /*!< Type used for describing LOPC component version */

typedef enum {
  LOPC_INIT,      /*!< initialize all    */
  LOPC_RUN,       /*!< normal processing */
  LOPC_ERROR,     /*!< system in error, but recovery possible */
  LOPC_SHUTDOWN   /*!< shutdown, fatal error, no recovery*/
} LOPCState_t;

/*! LOPC component version structure */
typedef struct 
{
  LOPCSwVersion_t   LOPC_VERSION_AS_TEXT;
  LOPCSwVersion_t   uiLopc;                 /*!< SW version of LOPC*/
} LOPCVersions_t;


typedef struct LOPCFrame_t {
  AlgoCycleCounter_t  uiCycleCounter;   /*!< The LOPC cycle counter */
  boolean             bFirstCycleDone;  /*!< Boolean showing if first cycle was done */
  FCT_OP_MODE_t       eLOPCOpMode;      /*!< FCT current operation mode */
  LOPCState_t         eLOPCState;       /*!< Current component operation mode */
  LOPCVersions_t      Versions;         /*!< Component versions */
} LOPCFrame_t;

/*!< aggregation struct of all input port data update information*/
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
typedef struct
{
  sMeasCycleMonitor sVehCtrlData;       /*!< Vehicle Control Data input */
  sMeasCycleMonitor sEgoDynRaw;         /*!< EgoDynRaw*/
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor sVehSig;
#endif
#if ((CFG_ACC_LEVER_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor sAccLeverInput;
#endif
#if (FCT_CFG_SLA_FEATURE)
  sMeasCycleMonitor sSLAData;
#endif
  sMeasCycleMonitor sLongCtrlInput;
#if ((FCT_CFG_ACC_HEADWAY_PLANNER) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor sAcc_object;
  sMeasCycleMonitor sAcc_output_data;
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor sFCTSenAccOOI;
#endif
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  sMeasCycleMonitor sFctVehCustInput;   /*!< Custom input for FCT_VEH */
#endif
} Lopc_InputMeasCounter;
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_RTA_PROFILING)// PRQA S 3332
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
/*!enumeration of RunTimeAssessment events.*/
typedef enum {
  LOPC_RTA_PROCESS            = 0,                  /*!<whole procedure runtime*/
  LOPC_RTA_PREPRE_PROCESS     = 1,                  /*!<data preparation runtime*/
  LOPC_RTA_KMC_PROCESS        = 2,                  /*!<Longitudinal control runtime*/
  LOPC_RTA_PROCESSFREEZE      = 3,                  /*!<Process Measfreeze runtime*/
  LOPC_RTA_FRAMEFREEZE        = 4,                  /*!<Frame Measfreeze runtime*/
  LOPC_RTA_LAST_ENTRY         = 5                   /*!<max enum*/
} LOPC_t_FCT_VEH_LocalID; /* RTA_LOCAL_ID_FOR_XML_GENERATION */
#endif

#if (FCT_CFG_ACT_CODE_VERSION)

/*! LOPC Sync-ref structure. Declared here so that simulation can instantiate */
typedef struct
{
  SignalHeader_t sSigHeader;       /*!<sSigHeader of SyncRef */
  SignalHeader_t t_SH_CTRL;         /*!< Signal Header of control port */

#if (ACT_CFG_CC_VSC_PORT_CNT)
  SignalHeader_t t_CC_VSCP;         /* Signal Header of CC VehicleSpeedCommandPort */
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  SignalHeader_t t_SLA_VSCP;        /* Signal Header of SLA VehicleSpeedCommandPort */
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  SignalHeader_t t_SLA_DSCP;        /* Signal Header of SLA DistanceSpeedCommandPort */
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  SignalHeader_t t_CP_DCCP;         /* Signal Header of CP DistanceCurveCommandPort */
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SignalHeader_t t_HP_TFCP;         /* Signal Header of HP TargetFollowCommandPort */
#endif

  SignalHeader_t t_LogVehCommand;   /*!< Signal Header of LVC port */

  SignalHeader_t t_EgoVehDynCtrl;   /*!< Signal Header of DMC port */
  SignalHeader_t t_EgoVehDynState;  /*!< Signal Header of VDY port */
}
LOPC_SyncRef_t;

#else /* Legacy */

/*! LOPC Sync-ref structure. Declared here so that simulation can instantiate */
typedef struct
{
  SignalHeader_t sSigHeader;            /*!< Signal Header of Veh_SyncRef */
  SignalHeader_t FCTCtrlData;         /*!< FCT_VEH operation mode control data */
  SignalHeader_t VehDyn;              /*!< The dynamic vehicle ego data raw */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  SignalHeader_t AccLeverInput;     /*!< ACC lever information (input from driver) */
  SignalHeader_t LongCtrlInput;     /*!< Dynamic controller response */
  SignalHeader_t AccObject;        /*!< Display object data output by FCT_SEN */
  SignalHeader_t AccOutputData;   /*!< ACC output data by FCT_SEN */
#if (FCT_CFG_TCI)
  SignalHeader_t TCIInput;          /*!< Input for TCI Feature */
#endif
#if (FCT_CFG_SLA_FEATURE)
  SignalHeader_t SLAData;           /*!< SLA speed limit data from FCT_SEN */
#endif
#endif /* FCT_CFG_LOPC_COMPONENT */
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t FCTAccOOIData       /*! OOI Data from FCT_SEN cycle */;
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t VehSig;            /*!< Direct access to vehicle signals */
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  SignalHeader_t  FctVehCustInput;  /*!< FCTVehCustomInput */
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
  SignalHeader_t  LoDmcOutput;      /*!< LoDMC Output */
#endif
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
  SignalHeader_t  HeadOutputCustom; /*!< HeadOutputCustom Output */
#endif
} LOPC_SyncRef_t;

#endif /* FCT_CFG_ACT_CODE_VERSION */

/* Combined struct with debug signals for LOPC Frame */
typedef struct lopc_static_mem{
  LOPCFrame_t     LOPC_Frame;
  LOPC_SyncRef_t  LOPC_SyncRef;
}lopc_static_mem_t;

#if (FCT_CFG_ACT_CODE_VERSION)
/*! Typedef of <VehicleSpeedCommandPort> port from LOPC to LOP component */
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const ACT_VehicleSpeedCommand_t *pt_VSC;
}
LOPC_VehicleSpeedCommandPort_t;

/*! Typedef of <DistanceSpeedCommandPort> port from LOPC to LOP component */
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const ACT_DistanceSpeedCommand_t *pt_DSC;
}
LOPC_DistanceSpeedCommandPort_t;

/*! Typedef of <DistanceCurveCommandPort> port from LOPC to LOP component */
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const ACT_DistanceCurveCommand_t *pt_DCC;
}
LOPC_DistanceCurveCommandPort_t;

/*! Typedef of <TargetFollowCommandPort> port from LOPC to LOP component */
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const TargetFollowCommand_t *pt_TFC;
}
LOPC_TargetFollowCommandPort_t;


/*! Typedef of <VehicleSpeedStatePort> port from LOP to LOPC component */
typedef struct
{
  SignalHeader_t *pt_SigHeader;
  ACT_VehicleSpeedState_t *pt_VSS;
}
LOPC_VehicleSpeedStatePort_t;

/*! Typedef of <DistanceSpeedStatePort> port from LOP to LOPC component */
typedef struct
{
  SignalHeader_t *pt_SigHeader;
  ACT_DistanceSpeedState_t *pt_DSS;
}
LOPC_DistanceSpeedStatePort_t;

/*! Typedef of <DistanceCurveStatePort> port from LOP to LOPC component */
typedef struct
{
  SignalHeader_t *pt_SigHeader;
  ACT_DistanceCurveState_t *pt_DCS;
}
LOPC_DistanceCurveStatePort_t;

/*! Typedef of <TargetFollowStatePort> port from LOP to LOPC component */
typedef struct
{
  SignalHeader_t *pt_SigHeader;
  TargetFollowState_t *pt_TFS;
}
LOPC_TargetFollowStatePort_t;


/*! Typedef of <LogicVehicleCommandPort> port from LOPC to LOC component */
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const ACT_LogicVehicleCommand_t *pt_LVC;
}
LOPC_LogicVehicleCommandPort_t;

/*! Typedef of <LogicVehicleStatePort> port from LOC to LOPC component */
typedef struct
{
  SignalHeader_t *pt_SigHeader;
  ACT_LogicVehicleState_t *pt_LVS;
}
LOPC_LogicVehicleStatePort_t;


/*! Typedef of <EgoVehicleStatePort> port from LOPC to LOC component */
typedef struct
{
  float32 f_LongAcceleration;       /* Absolute longitudinal acceleration of ego vehicle */
  float32 f_LongVelocity;           /* Absolute longitudinal velocity of ego vehicle */
  boolean b_Standstill;             /* Controlled Standstill */
  boolean b_Valid;                  /* State is valid */
}
LOPC_EgoVehicleState_t;
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const LOPC_EgoVehicleState_t *pt_EVS;
}
LOPC_EgoVehicleStatePort_t;

/*! Typedef of <EgoVehicleCommandPort> port from LOC to LOPC component */
typedef struct
{
  SignalHeader_t *pt_SigHeader;
  ACT_EgoVehicleCommand_t *pt_EVC;
}
LOPC_EgoVehicleCommandPort_t;

/*! Typedef of <IdealVehicleCommandPort> port from LOP to LOC component */
typedef struct
{
  float32 f_LongAccelGrad;          /* Longitudinal acceleration gradient for ideal vehicle distance model */
  boolean b_Enable;                 /* Command is enabled */
}
LOPC_IdealVehicleDistCmd_t;
typedef struct
{
  float32 f_LongAccelGrad;          /* Longitudinal acceleration gradient for ideal vehicle velocity model */
  boolean b_ArbitDriverMin;         /* Minimum arbitration against driver request (speed limiter function) */
  boolean b_Enable;                 /* Command is enabled */
}
LOPC_IdealVehicleVeloCmd_t;
typedef struct
{
  LOPC_IdealVehicleDistCmd_t t_IVDC;
  LOPC_IdealVehicleVeloCmd_t t_IVVC;
}
LOPC_IdealVehicleCommand_t;
typedef struct
{
  LOPC_IdealVehicleCommand_t *pt_IVC;
}
LOPC_IdealVehicleCommandPort_t;

/*! Typedef of <IdealVehicleStatePort> port from LOC to LOP component */
typedef struct
{
  float32 f_AbsLongAccel;           /* Absolute longitudinal acceleration of ideal vehicle velocity model */
  float32 f_AbsLongVelo;            /* Absolute longitudinal velocity of ideal vehicle velocity model */
  boolean b_Valid;                  /* State is valid */
  boolean b_Reset;                  /* State is reset to EgoVehicle */
}
LOPC_IdealVehVeloState_t;
typedef struct
{
  LOPC_IdealVehVeloState_t t_IVVS;  /* Ideal vehicle velocity model state */
  float32 f_RelLongDist;            /* Relative longitudinal distance to ideal vehicle distance model */
}
LOPC_IdealVehDistState_t;
typedef struct
{
  LOPC_IdealVehDistState_t t_IVDS;
  LOPC_IdealVehVeloState_t t_IVVS;
}
LOPC_IdealVehicleState_t;
typedef struct
{
  LOPC_IdealVehicleState_t *pt_IVS;
}
LOPC_IdealVehicleStatePort_t;

#endif /* FCT_CFG_ACT_CODE_VERSION */

/*! The LOPC FuncID used for meas-freezes */
#if (defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor)) /* ARS4xx / ARS5xx case */
#if (defined(ALGO_ARS400Sensor) && (ALGO_ARS400Sensor))
#define LOPC_MEAS_FUNC_ID        TASK_ID_ALGO_VEH_CYCLE    /*!< alias to FCTVehicle ID (for measfreezing)*/
/*! The FCT-Veh FuncChannelID used for meas-freezes, clarify this later! */
#define LOPC_MEAS_FUNC_CHAN_ID   20u
#elif (defined(ALGO_ARS500Sensor) && (ALGO_ARS500Sensor))
#define LOPC_MEAS_FUNC_ID        TASK_ID_ALGO_VEH_CYCLE    /*!< alias to FCTVehicle ID (for measfreezing)*/
/*! The FCT-Veh FuncChannelID used for meas-freezes, clarify this later! */
#define LOPC_MEAS_FUNC_CHAN_ID   20u
#endif
#else /* camera case */
#define LOPC_MEAS_FUNC_ID        TASK_ID_FCT   /*!< alias to FCTVehicle ID (for measfreezing) @todo : 20150611CO: seperate COMP_ID_EBA needed to get better split between FCT and subcomponents*/
#define LOPC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT   /*!< The FCT-Veh FuncChannelID used for meas-freezes @todo : 20150611CO: seperate COMP_ID_EBA needed to get better split between FCT and subcomponents*/
#endif

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT)) */

#endif  /*!< _LOPC_TYPES_INCLUDED */

/** @} end defgroup */
