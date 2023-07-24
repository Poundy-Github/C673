/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               $Source: slate_pdo_tags.c $

DESCRIPTION:               This module contains ACDC PDO tags 

AUTHOR:                    $Author: Ramesh, Sangeetha (uidn1528) $

CREATION DATE:             $Date: 2020/07/30 19:02:57CEST $

VERSION:                   $Revision: 1.11 $
**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifdef __PDO__
#include "slate_ext.h"
#include "slate.h"
#include "cp.h"
#include "sit.h"
#include "sit_lanechange.h"
#include "la_corridor_crit.h"
#include "la.h"
#include "apm.h"

#if (FCT_CFG_SLATE_COMPONENT)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         slate_pdo   pdo tags for slate
@ingroup          frame
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/


/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

/* frame slate */                                                    
typedef SLATEFrame_t                PDO_SLATEFrame_t                ;  /*!< @VADDR:FCT_MEAS_ID_SEN_ACC_FRAME_DATA 
                                                                            @CYCLEID: FCT_ENV 
                                                                            @VNAME:SLATE_FrameData */

typedef SLATESyncRef_t               PDO_SLATESyncRef_t             ;  /*!< @vaddr:FCT_MEAS_ID_SEN_ACC_INPUT_SIGHEADERS 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname:SLATE_SyncRef */
#if FCT_CFG_USE_ALGOCOMPSTATE                                       
typedef AlgoCompState_t             PDO_SLATECompState              ;  /*!< @vaddr:FCT_MEAS_ID_SEN_ACC_COMP_STATE
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: SLATE_Compstate */
#endif                                                              
#if FCT_CFG_RUNTIME_MEAS
typedef SLATERuntimeInfo_t          PDO_SLATERuntimeInfo_t          ;  /*!< @VADDR:FCT_MEAS_ID_ACC_RUNTIME_DEBUG
                                                                            @CYCLEID: FCT_ENV
                                                                            @VNAME:FCTSEN_ACCRuntimeInfo  */
#endif

/* Device Debug Information */
typedef FIP_DeviceMeasInfo_t        PDO_FIP_DeviceInfo_t            ;  /*!< @vaddr: FCT_MEAS_ID_FIP_DEVICE 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: FIP_DeviceMeasInfo */

typedef SIT_t_DeviceMeasInfo        PDO_SIT_DeviceInfo_t            ;  /*!< @vaddr: FCT_MEAS_ID_SIT_DEVICE 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: SIT_DeviceMeasInfo */

typedef CP_t_DeviceMeasInfo         PDO_CP_DeviceInfo_t             ;  /*!< @vaddr: FCT_MEAS_ID_CP_DEVICE 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: CP_DeviceMeasInfo */

typedef LA_DeviceMeasInfo_t         PDO_LA_DeviceInfo_t             ;  /*!< @vaddr: FCT_MEAS_ID_LA_DEVICE 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: LA_DeviceMeasInfo */

typedef OUT_DeviceMeasInfo_t        PDO_OUT_DeviceInfo_t            ;  /*!< @vaddr: FCT_MEAS_ID_OUT_DEVICE 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: OUT_DeviceMeasInfo  */
/* Simulation Debug Information */
#ifdef FCT_SIMU
typedef CP_SimMeasInfo_t            PDO_CP_SimMeasInfo_t            ;  /*!< @vaddr: FCT_MEAS_ID_CP_SIM 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: CP_SimMeasInfo */

typedef FIP_SimMeasInfo_t           PDO_FIP_SimMeasInfo_t           ;  /*!< @vaddr: FCT_MEAS_ID_FIP_SIM 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: FIP_SimMeasInfo */

typedef LA_SimMeasInfo_t            PDO_LA_SimMeasInfo_t            ;  /*!< @vaddr: FCT_MEAS_ID_LA_SIM 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: LA_SimMeasInfo */

typedef OOI_SimMeasInfo_t           PDO_OOI_SimMeasInfo_t           ;  /*!< @vaddr: FCT_MEAS_ID_OOI_SIM 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: OOI_SimMeasInfo */

typedef OUT_SimMeasInfo_t           PDO_OUT_SimMeasInfo_t           ;  /*!< @vaddr: FCT_MEAS_ID_OUT_SIM 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: OUT_SimMeasInfo */

typedef SIT_SimMeasInfo_t           PDO_SIT_SimMeasInfo_t           ;  /*!< @vaddr: FCT_MEAS_ID_SIT_SIM 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: SIT_SimMeasInfo */


/* CP */
typedef CP_t_TrajFusionDebugInfo    PDO_CP_TrajFusionDebugInfo_t    ;  /*!< @vaddr: CP_MOV_OBJ_TRACE_TRAJ_FUSION_VADDR 
                                                                            @cycleid:FCT_ENV
                                                                            @vname: CP_TrajFusionDebugInfo */
#endif  /* FCT_SIMU */

/* LA */
#ifdef FCT_SIMU
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM ||\
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
typedef LA_t_DebugCriteriaMatrixAllObj PDO_LA_CriteriaMatrixAll_t   ;  /*!< @VADDR:FCT_MEAS_ID_LA_CRITERIA_MATRIX_ALL_OBJ 
                                                                            @CYCLEID: FCT_ENV 
                                                                            @vname: LA_CriteriaMatrixAllObj */
#endif  /* ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM ) */
#endif /* FCT_SIMU */

#ifdef FCT_SIMU
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
typedef LA_t_CorrNeighbourDebug     PDO_LA_CorrNeighbourDebug_t     ;  /*!< @vaddr: LA_CORR_NEIGHBOUR_EXT_DEBUG_VADDR 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: LA_CorrNeighbourDebug */
#endif  /* LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ */
#endif  /* FCT_SIMU */

/* SIT */
#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE == 1)
typedef SITPotentialDebugData_t     PDO_SITPotentialDebugData_t     ;  /*!< @vaddr: SIT_POTENTIAL_DEBUG_DATA_VADDR
                                                                            @cycleid: FCT_ENV 
                                                                            @vname: SITPotentialDebugData */
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE == 1)*/
#ifdef FCT_SIMU
typedef SITLCProbDebugData_t        PDO_SITLCProbDebugData_t        ;  /*!< @vaddr: SIT_LC_PROB_DEBUG_VADDR 
                                                                            @cycleid:FCT_ENV
                                                                            @vname: SITLCProbDebugData */
#endif  /* FCT_SIMU */

/* These variables is no longer used in debug, check and delete all references */
//typedef SALaneChange_t              PDO_SALaneChange_t              ;  /*!< @vaddr: SIT_MEAS_ADDR_LANE_CHANGE 
//                                                                            @cycleid:FCT_ENV 
//                                                                            @vname: SITLaneChange */

//typedef SITLCCamLaneCrossDebugInfo_t  PDO_SITLCCamLaneCrossDebugInfo_t;/*!< @vaddr: SIT_LC_CAM_LANE_CROSS_DEBUG_VADDR 
//                                                                            @cycleid:FCT_ENV 
//                                                                            @vname: SITLCCamLaneCrossDebugInfo */

//typedef SILCCamMovePreDebugInfo_t   PDO_SILCCamMovePreDebugInfo_t   ;  /*!< @vaddr: SIT_LC_CAM_MOVE_PRE_DEBUG_VADDR 
//                                                                            @cycleid:FCT_ENV 
//                                                                            @vname: SILCCamMovePreDebugInfo */

//typedef SITTraceLanes_t             PDO_SITTraceLanes_t             ;  /*!< @vaddr: SIT_MEAS_ADDR_SCORING_TRACE_LANES
//                                                                            @cycleid: FCT_ENV 
//                                                                            @vname: SITTraceLanes */

/* APM */
#if (SLATE_CFG_ACC_PERF_MONITORING)
typedef APM_Degradation_Data_t        PDO_APM_Degradation_Data_t    ;  /*!< @vaddr: FCT_MEAS_ID_APM_DEGRADATION_DATA 
                                                                            @cycleid:FCT_ENV 
                                                                            @vname: APM_DegData */
#endif /* END IF (SLATE_CFG_ACC_PERF_MONITORING) */
/// @}
#if (FCT_CFG_LOHP_COMPONENT)
typedef SLATE_HC_Data_t               PDO_SLATE_HC_Data_t;          /*!< @VADDR:   FCT_MEAS_ID_SEN_SLATE_HC_DATA
                                                                         @CYCLEID: FCT_ENV
                                                                         @VNAME:   LOHP_SLATE_HC_Data */
#endif
#endif /* FCT_CFG_SLATE_COMPONENT*/
#endif /* #ifdef __PDO__ */



/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}


