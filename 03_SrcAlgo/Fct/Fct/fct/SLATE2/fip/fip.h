/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip.h

DESCRIPTION:               Internal Header File for ACC FCT Input Preprocessing (FIP) module

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             12.11.2012

VERSION:                   $Revision: 1.16 $

LEGACY VERSION:            Revision: 2.1.1.1

**************************************************************************** */
#ifndef FIP_H_INCLUDED
#define FIP_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"
#include "fip_par.h"

#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip
@{ */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS
*****************************************************************************/

//#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
//  /* Virtual adress for navi debug freeze in the device (to be moved to rte) */
//#ifndef FCT_MEAS_ID_NAVI_FIP_DEBUG
//#define FCT_MEAS_ID_NAVI_FIP_DEBUG 0x20270360
//#endif
//#endif

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#if (FCT_CFG_TJA_OBJECT_TRACE)

/*! Structure to describe the a single trace trajectory */
typedef struct
{
  ObjNumber_t tObjNum;  /* FCT ID of trajectory object */
  float32 fLength;        /* Valid length*/
  float32 fPosX0;         /* Min X-Position */
  float32 fPosY0;         /* Y-Position at X=0 */
  float32 fAngle;         /* Slope at X=0 */
  float32 fCurveC0;       /* Curvature at X=0 */
  float32 fCurveC1;       /* Change of Curvature */
  float32 fPosY0Dev;      /* Standard Deviation of Y-Position */
  float32 fAngleDev;      /* Standard Deviation of Slope */
  float32 fCurveC0Dev;    /* Standard Deviation of Curvature */
  float32 fCurveC1Dev;    /* Standard Deviation of Curvature change */
} FIP_ObjTraceTraj_t;

/*! Structure to describe the trace trajectories for the different traces */
typedef struct
{
  uint8 uiTrajsCount;                                 /* Number of valid trace trajectories */
  FIP_ObjTraceTraj_t ObjTrajects[FIP_DYN_TRACE_NO_OF_TRACES]; /* Structure of trace trajectories */
} FIP_ObjTraceTrajectory_t;

#endif

/*****************************************************************************
  VARIABLES
*****************************************************************************/
#if (FCT_CFG_TJA_OBJECT_TRACE)
#ifdef FCT_SIMU
extern MEMSEC_REF FIP_ObjTraceTrajectory_t FIPObjTraceTrajectory;
#endif
#endif

/*! External declaration of component internal pointer to FIP Input structure for global access within FIP */
extern MEMSEC_REF FIPInputRTEConst_t * pt_FIP_RTE_Input;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*---fip_camera_lane_plg.c---*/
#if (SLATE_CFG_CAM_LANE_INTERFACE)
extern void FIP_v_CamLaneDataProcess(FIP_CL_Output_t * pt_FIP_CL_OutputGlobal);       /*!< FCT Camera Lane Data Preprocessing */
extern void FIP_v_InitGlobalCamLaneData(FIP_CL_Output_t * pt_FIP_CL_OutputGlobal);    /*!< Initialization of global camera lane data */
extern boolean FIP_b_CamLaneExistanceProb(void);
#endif

/*! fip_lane_matrix_plg.c */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
extern void FIP_v_LaneMatrixProcess(FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal, FIP_LM_Output_t * pt_FIP_LM_OutputGlobal);        /*!< FIP lane matrix preprocessing */
extern void FIP_v_LM_PreProcess(FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal);
extern void FIP_v_InitGlobalLaneMatrixData(FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal, FIP_LM_Output_t * pt_FIP_LM_OutputGlobal); /*!< Initialization of global lane matrix data */
extern void FIP_v_LMSetMeasData(FIPLM_DeviceMeasInfo_t * pt_LMDebugMeasFreeze, FIP_LM_Output_t const *pt_FIP_LM_OutputLocal);
#endif

/*---fip_navi_data_process.c---*/
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
extern void FIP_v_ND_PreProcess(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal);
extern void FIPNaviDataProcess(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal, FIP_ND_Output_t * pt_FIP_ND_OutputGlobal);         /*!< FCT Navi Data Preprocessing */
extern void FIPInitGlobalNaviData(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal, FIP_ND_Output_t * pt_FIP_ND_OutputGlobal);      /*!< Initialization of global navi path data */
extern void FIP_v_NaviSetMeasData(FIP_NaviDebugMeasInfo_t * p_NaviDebugMeasFreeze, FIP_ND_Output_t * pt_FIP_ND_OutputLocal);
#endif

/*! fip_objattributes.c */
#if (FCT_CFG_INPUT_PREPROCESSSING)
extern void FIP_v_OA_CalcObjAttributes(FIP_OA_InputConst_t * pt_FIP_OA_InputGlobal, FIP_OA_Output_t * pt_FIP_OA_OutputGlobal);
extern void FIP_v_OA_DeleteObject(const ObjNumber_t t_ObjNr);
extern void FIP_v_InitGlobalObjAttributes(FIP_OA_InputConst_t * pt_FIP_OA_InputGlobal, FIP_OA_Output_t * pt_FIP_OA_OutputGlobal);
extern void FIP_v_OA_PreProcess(FIP_OA_InputConst_t * pt_FIP_OA_InputGlobal);
#endif /* END IF (FCT_CFG_INPUT_PREPROCESSSING) */

/*! fip_object_traces.c */
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
extern void FIP_v_InitGlobalObjTraceData(FIP_MOT_Output_t * pt_FIP_MOT_OutputGlobal);   /*!< Initialization of global object trace data */
extern void FIP_v_ObjTraceProcess(FIP_MOT_Output_t * pt_FIP_MOT_OutputGlobal);          /*!< FIP Object Trace Preprocessing */
#endif

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! fip_road.c */
extern void FIP_v_Init_Road(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal, FIP_RD_Output_t * pt_FIP_RD_OutputGlobal);
extern void FIP_v_RD_PreProcess(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal);
extern void FIP_v_RoadProcess(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal, FIP_RD_Output_t * pt_FIP_RD_OutputGlobal);
#endif /* END IF (FCT_CFG_INPUT_PREPROCESSSING) */

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! fip_road_type.c */
extern void FIP_v_Init_FuseRoadType(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal, FIP_RT_Output_t * pt_FIP_RT_OutputGlobal);
extern void FIP_v_RT_PreProcess(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal);
extern void FIP_v_Process_FuseRoadType(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal, FIP_RT_Output_t * pt_FIP_RT_OutputGlobal);
#endif /* END IF (FCT_CFG_INPUT_PREPROCESSSING) */

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! fip_traffic_orientation.c */
extern void FIP_v_InitGlobalLaneTrafficOrientation(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal, FIP_TO_Output_t * pt_FIP_TO_OutputGlobal);
extern void FIP_v_TO_PreProcess(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal);
extern void FIP_v_TrafficOrientationProcess(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal, FIP_TO_Output_t * pt_FIP_TO_OutputGlobal);
extern void FIP_v_TOSetMeasData(FIPTO_DeviceMeasInfo_t * pt_TODebugMeasFreeze, FIP_TO_Output_t const * pt_FIP_TO_OutputLocal);
#endif /* END IF (FCT_CFG_INPUT_PREPROCESSSING) */

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
/*! fip_curvature_change.c */
extern void FIP_v_InitCurvatureChangeFusionData(FIP_CC_Output_t * pt_FIP_CC_OutputGlobal);
extern void FIP_v_CurvatureChangeFusionProcess(FIP_CC_Output_t * pt_FIP_CC_OutputGlobal);
#endif /* FCT_CFG_CURVATURE_CHANGE_COMPUTATION */

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! fip_customfunctions.c */
extern void FIP_v_Set_CustomTrafficOrientation(FIP_TO_Output_t * pt_FIP_TO_Output);
extern void FIP_v_Init_CustomTrafficOrientation(void);
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) 
#if (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY)
void FIP_v_InitCustInternalData(void);
#endif /* END IF (FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY) */
#endif /*  END IF (SLATE_CFG_SEN_SIMPLE_NAVI_INTERFACE) */
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
extern void  FIP_v_SetCameraObjData(FIP_OA_Output_t * pt_FIP_OA_Output, const ObjNumber_t ObjNr);
#endif /* END IF FCT_CFG_CAMERA_OBJECT_DETECTION */
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
float32 FIP_f_GetObjOverlapFromCamera(const ObjNumber_t iCurObj);
#endif /* (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL) */
#endif /* END IF (FCT_CFG_INPUT_PREPROCESSSING) */
#ifdef __cplusplus
};
#endif

/* End of conditional inclusion */

#endif

///@}
#endif  /*!< _FIP_H_INCLUDED */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
