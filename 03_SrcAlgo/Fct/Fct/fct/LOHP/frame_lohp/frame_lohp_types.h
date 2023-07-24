/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACT/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_types.h

DESCRIPTION:               Types header file for LOHP in FCT_SEN task

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             06.09.2017

VERSION:                   $Revision: 1.19 $

---*/ /*---

**************************************************************************** */

#ifndef _LOHP_TYPES_INCLUDED
#define _LOHP_TYPES_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup   frame_lohp_types Frame_lohp_types
@brief      Internal type definitions for LOHP Component
@ingroup    lohp_base_frame
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_par.h"
#include "lohp_cfg.h"
#include "frame_lohp_ver.h"


#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS
*****************************************************************************/
#ifndef FCT_MEAS_ID_LOHP_FRAME_DATA
#define FCT_MEAS_ID_LOHP_FRAME_DATA (0x20270650u)  //0x20270000u FCT_MEAS_ID_SEN_FRAME_DATA
#endif

#if ( FCT_CFG_ACC_HEADWAY_PLANNER )

#ifndef FCT_MEAS_ID_LOHP_HP_STATIC_MEM
#define FCT_MEAS_ID_LOHP_HP_STATIC_MEM (0x20020000u)
#endif
 
#endif /* FCT_CFG_ACC_HEADWAY_PLANNER */

#if ( LOHP_CFG_PRED )
#ifndef FCT_MEAS_ID_LOHP_PRED_OUTPUT_DATA
#define FCT_MEAS_ID_LOHP_PRED_OUTPUT_DATA (0x20020900u)
#endif
#endif /* LOHP_CFG_PRED */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

typedef uint32 LOHPSwVersion_t; /*!< Type used for describing an FCT sub-component version */

/*! operating modes of sub-component */
typedef enum LOHPState
{
  LOHP_INIT,      /*!< initialize all    */
  LOHP_RUN,       /*!< normal processing */
  LOHP_ERROR,     /*!< system in error, but recovery possible */
  LOHP_SHUTDOWN   /*!< shutdown, fatal error, no recovery*/
}
LOHPState_t;

/*! @brief    structure containing information about the current project and software version*/
typedef struct LOHPVersions
{
  LOHPSwVersion_t   LOHP_VERSION_AS_TEXT;
  LOHPSwVersion_t   uiLohp;
}
LOHPVersions_t;

/*! @brief  structure for a global variable containing frame information 
            for the calculations of the component.  */
typedef struct LOHPFrame
{
  AlgoCycleCounter_t  uiCycleCounter;   /*!< The LOHP cycle counter */
  boolean             bFirstCycleDone;  /*!< Boolean showing if first cycle was done */
  FCT_OP_MODE_t       eFCTOpMode;       /*!< FCT current operation mode */
  LOHPState_t         eLOHPState;       /*!< Current component operation mode */
  LOHPVersions_t      Versions;         /*!< Component versions */
}
LOHPFrame_t;

/*! aggregation struct of all input port measurement timestamps */
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

#else   /* GEN 3 */

typedef struct FCTSenHC_InputMeasCounter
{
  sMeasCycleMonitor pSenCtrlData;
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  sMeasCycleMonitor pEmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  sMeasCycleMonitor pEmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  sMeasCycleMonitor pEmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  sMeasCycleMonitor pEmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#else
  sMeasCycleMonitor pPubEmObj;        /*!< The public EM object data */
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  sMeasCycleMonitor pPubFctObj;
#endif
#endif
  sMeasCycleMonitor pEgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  sMeasCycleMonitor pEgoStaticData;   /*!< the static vehicle ego data */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  sMeasCycleMonitor pFctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  sMeasCycleMonitor pFCTCustomOutput;
#endif
#endif
#if (FCT_CFG_SLATE_COMPONENT)
  sMeasCycleMonitor pSLATE_HC_Data;
#endif
#if(FCT_CFG_SIGNAL_PERF_MONITORING)
  sMeasCycleMonitor pSPM_HC_Data;
#endif
}
FCTSenHC_InputMeasCounter_t;

#endif /* FCT_CFG_ACT_CODE_VERSION */

#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/


/* date: 2015-06-17, reviewer: Lonard jaison manohar(uidj2547), reason: Simulation specific macro */
typedef enum
{
  LOHP_RTA_PROCESS,                        /*!< Whole procedure runtime */
  LOHP_RTA_PREPRE_PROCESS,                 /*!< data preparation runtime */
  LOHP_RTA_PRE_PROCESS,                    /*!< data preprocessing runtime */
  LOHP_RTA_PROCESSFREEZE,                  /*!< Process Measfreeze runtime */
  LOHP_RTA_FRAMEFREEZE,                    /*!< Frame Measfreeze runtime */
  LOHP_RTA_HP_PROCESS,                     /*!< Runtime for HP (Headway Planner) */
  LOHP_RTA_LAST_ENTRY            /*!< This line has to be the last to determine the size of the structure */
} LOHP_t_FCT_SEN_LocalID; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

#if FCT_CFG_RUNTIME_MEAS
/* Virtual address for FCT ACC runtime measurement freeze in the device (to be moved to rte) */
#ifndef FCT_MEAS_ID_HC_RUNTIME_DEBUG
#define FCT_MEAS_ID_HC_RUNTIME_DEBUG 0x20273750u //0x20273600
#endif

typedef struct FCT_HCRuntimeInfo
{
  uint32 uRuntime[LOHP_RTA_LAST_ENTRY];
}
FCT_HCRuntimeInfo_t;

#endif

#if (FCT_CFG_ACT_CODE_VERSION == SWITCH_OFF)
typedef struct{
  FCTObjUsageState_t UsageState_OOI_0;
  FCTObjUsageState_t UsageState_OOI_1;
  FCTObjUsageState_t UsageState_OOI_2;
  FCTObjUsageState_t UsageState_OOI_3;
  FCTObjUsageState_t UsageState_OOI_4;
  FCTObjUsageState_t UsageState_OOI_5;
}LOHP_ObjUsageState_t; /*! Usage state of objects of interest for control, display and alert */
#endif

#if (LOHP_CFG_TC)
/*! Typedef of <TargetControlCommandPort> port from LOHP to TC component */
typedef struct
{
  const TargetControlCommand_t *pt_TCC;
  const FunctionDegradation_t *pt_FD;
}
LOHP_TargetControlCommandPort_t;

/*! Typedef of <TargetFollowStatePort> port from LOHP to TC component */
typedef struct
{
  const TargetFollowState_t *pt_TFS;
}
LOHP_TargetFollowStatePort_t;

/*! Typedef of <EgoVehicleInfoPort> port from LOHP to TC component */
typedef struct
{
  float32 f_LongAcceleration;       /* Absolute longitudinal acceleration of ego vehicle [m/s^2] */
  float32 f_LongVeloReal;           /* Real longitudinal velocity of ego vehicle [m/s] */
  boolean b_Override_Accel;         /* Driver overriding by accelerator pedal */
  boolean b_Override_Decel;         /* Driver overriding by decelerator pedal */
  boolean b_StandStill;             /* Standstill of ego vehicle */
  boolean b_Valid;                  /* State is valid */
}
LOHP_EgoVehicleInfo_t;
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const LOHP_EgoVehicleInfo_t *pt_EVI;
}
LOHP_EgoVehicleInfoPort_t;

/*! Typedef of <TargetVehicleInfoPort> port from LOHP to TC component */
typedef enum
{
  LOHP_OT_NONE,
  LOHP_OT_LEFT,
  LOHP_OT_RIGHT
}
LOHP_OT_DIR_t;
typedef struct
{
  AccOOINextLong_t AccOOINextLong;
  AccOOI_t AccOOIHiddenNextLong;
  AccOOI_t AccOOINextLeft;
  AccOOI_t AccOOINextRight;
  AccOOI_t AccOOIHiddenNextLeft;
  AccOOI_t AccOOIHiddenNextRight;
  LOHP_OT_DIR_t OvertakeDirection;
  boolean b_Valid;                      /* State is valid */
}
LOHP_TargetVehicleInfo_t;
typedef struct
{
  const SignalHeader_t *pt_SigHeader;
  const LOHP_TargetVehicleInfo_t *pt_TVI;
}
LOHP_TargetVehicleInfoPort_t;

/*! Typedef of <TargetControlStatePort> port from TC to LOHP component */
typedef struct
{
  TargetControlState_t *pt_TCS;
}
LOHP_TargetControlStatePort_t;

/*! Typedef of <TargetFollowCommandPort> port from TC to LOHP component */
typedef struct
{
  TargetFollowCommand_t *pt_TFC;
}
LOHP_TargetFollowCommandPort_t;
#endif /* LOHP_CFG_TC */

/*****************************************************************************
  CONSTANTS 
*****************************************************************************/


#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

#endif  /*!< _LOHP_TYPES_INCLUDED */
