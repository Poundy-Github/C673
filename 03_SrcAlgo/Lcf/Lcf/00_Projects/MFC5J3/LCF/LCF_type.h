/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3
  COMPONENT      : LCF
  AUTHOR         : Component_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCF_type.h
//! @brief    Lateral Control Functions (LCF) Component Type Header.

#ifndef LCF_TYPE_H_
#define LCF_TYPE_H_

/*-------------------------------------------------*
   I N C L U D E S
**-------------------------------------------------*/

#include "lcf_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------*
   M A C R O   C O N S T A N T S
**-------------------------------------------------*/

#ifndef NULL
#define NULL ((void*) 0u) //!< Null pointer.
#endif // NULL

#ifndef FALSE
#define FALSE (0u) //!< Boolean constant.
#endif // FALSE

#ifndef TRUE
#define TRUE (1u) //!< Boolean constant.
#endif // TRUE

/*-------------------------------------------------*
   E N U M E R A T I O N S
**-------------------------------------------------*/

#ifndef _E_ABPLBP_KALMANSTATUSTYPE_T_
#define _E_ABPLBP_KALMANSTATUSTYPE_T_ //!< Macro switch for enumeration @ref E_ABPLBP_KalmanStatusType.
/*!
 *	Left road edge kalman filter status \n
 *	 \n
 *	0: not valid \n
 *	1: full update \n
 *	2: degraded update \n
 *	3: predict \n
 *	4: init \n
 *	5: reset
 */
typedef enum
{
	E_ABPLBP_KF_INVALID	= 0, //!< 0
	E_ABPLBP_KF_FULL_UPDATE	= 1, //!< 1
	E_ABPLBP_KF_DEGR_UPDATE	= 2, //!< 2
	E_ABPLBP_KF_PREDICTION	= 3, //!< 3
	E_ABPLBP_KF_INITIALIZATION	= 4, //!< 4
	E_ABPLBP_KF_RESET	= 5 //!< 5
} E_ABPLBP_KalmanStatusType;
#endif // _E_ABPLBP_KALMANSTATUSTYPE_T_
#define E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_INVALID	(E_ABPLBP_KF_INVALID) //!< SDA enumeration mapping.
#define E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_FULL_UPDATE	(E_ABPLBP_KF_FULL_UPDATE) //!< SDA enumeration mapping.
#define E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_DEGR_UPDATE	(E_ABPLBP_KF_DEGR_UPDATE) //!< SDA enumeration mapping.
#define E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_PREDICTION	(E_ABPLBP_KF_PREDICTION) //!< SDA enumeration mapping.
#define E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_INITIALIZATION	(E_ABPLBP_KF_INITIALIZATION) //!< SDA enumeration mapping.
#define E_ABPLBP_KalmanStatusType_E_ABPLBP_KF_RESET	(E_ABPLBP_KF_RESET) //!< SDA enumeration mapping.
typedef uint8 E_ABPLBP_KalmanStatusType_t; //!< Enumeration base type definition. [\@values: E_ABPLBP_KalmanStatusType](@ref E_ABPLBP_KalmanStatusType)

#ifndef _E_ABPR_ABDLNMARKERSTYPE2_T_
#define _E_ABPR_ABDLNMARKERSTYPE2_T_ //!< Macro switch for enumeration @ref E_ABPR_AbdLnMarkersType2.
/*!
 *	Decribes the type of a lane marker (e.g. continuous, dashed, road edge,�). \n
 *	ABD_MT_NO_LINE= 0 \n
 *	ABD_MT_PAINTED_CONTINUOUS = 1 \n
 *	ABD_MT_PAINTED_DASHED = 2 \n
 *	ABD_MT_PAINTED_DECORATIVE = 3 \n
 *	ABD_MT_DOTTED_CONTINUOUS = 4 \n
 *	ABD_MT_DOTTED_DASHED = 5  \n
 *	ABD_MT_ELEVATED_CONTINUOUS=6 \n
 *	ABD_MT_ELEVATED_DISCRETE = 7 \n
 *	ABD_MT_CURBSTONE =8 \n
 *	ABD_MT_ROADEDGE =9 \n
 *	ABD_MT_UNKNOWN = 100
 */
typedef enum
{
	ABD_MT_NO_LINE	= 0, //!< 0
	ABD_MT_PAINTED_CONTINUOUS	= 1, //!< 1
	ABD_MT_PAINTED_DASHED	= 2, //!< 2
	ABD_MT_PAINTED_DECORATIVE	= 3, //!< 3
	ABD_MT_DOTTED_CONTINUOUS	= 4, //!< 4
	ABD_MT_DOTTED_DASHED	= 5, //!< 5
	ABD_MT_ELEVATED_CONTINUOUS	= 6, //!< 6
	ABD_MT_ELEVATED_DISCRETE	= 7, //!< 7
	ABD_MT_CURBSTONE	= 8, //!< 8
	ABD_MT_ROADEDGE	= 9, //!< 9
	ABD_MT_UNKNOWN	= 100 //!< 100
} E_ABPR_AbdLnMarkersType2;
#endif // _E_ABPR_ABDLNMARKERSTYPE2_T_
#define E_ABPR_AbdLnMarkersType2_ABD_MT_NO_LINE	(ABD_MT_NO_LINE) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_PAINTED_CONTINUOUS	(ABD_MT_PAINTED_CONTINUOUS) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_PAINTED_DASHED	(ABD_MT_PAINTED_DASHED) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_PAINTED_DECORATIVE	(ABD_MT_PAINTED_DECORATIVE) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_DOTTED_CONTINUOUS	(ABD_MT_DOTTED_CONTINUOUS) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_DOTTED_DASHED	(ABD_MT_DOTTED_DASHED) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_ELEVATED_CONTINUOUS	(ABD_MT_ELEVATED_CONTINUOUS) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_ELEVATED_DISCRETE	(ABD_MT_ELEVATED_DISCRETE) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_CURBSTONE	(ABD_MT_CURBSTONE) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_ROADEDGE	(ABD_MT_ROADEDGE) //!< SDA enumeration mapping.
#define E_ABPR_AbdLnMarkersType2_ABD_MT_UNKNOWN	(ABD_MT_UNKNOWN) //!< SDA enumeration mapping.
typedef uint8 E_ABPR_AbdLnMarkersType2_t; //!< Enumeration base type definition. [\@values: E_ABPR_AbdLnMarkersType2](@ref E_ABPR_AbdLnMarkersType2)

#ifndef _E_ABPR_ALGOCOMPSTATEV2_T_
#define _E_ABPR_ALGOCOMPSTATEV2_T_ //!< Macro switch for enumeration @ref E_ABPR_AlgoCompStateV2.
/*!
 *	Lane detection component state enumeration
 */
typedef enum
{
	COMP_ST_NOT_INITIALIZED	= 0, //!< 0
	COMP_ST_RUNNING	= 1, //!< 1
	COMP_ST_TEMPORARY_ERROR	= 2, //!< 2
	COMP_ST_PERMANENT_ERROR	= 3, //!< 3
	COMP_ST_SUCCESS	= 4, //!< 4
	COMP_ST_REDUCED_AVAILABILITY	= 5, //!< 5
	COMP_ST_NOT_RUNNING	= 6 //!< 6
} E_ABPR_AlgoCompStateV2;
#endif // _E_ABPR_ALGOCOMPSTATEV2_T_
#define E_ABPR_AlgoCompStateV2_COMP_ST_NOT_INITIALIZED	(COMP_ST_NOT_INITIALIZED) //!< SDA enumeration mapping.
#define E_ABPR_AlgoCompStateV2_COMP_ST_RUNNING	(COMP_ST_RUNNING) //!< SDA enumeration mapping.
#define E_ABPR_AlgoCompStateV2_COMP_ST_TEMPORARY_ERROR	(COMP_ST_TEMPORARY_ERROR) //!< SDA enumeration mapping.
#define E_ABPR_AlgoCompStateV2_COMP_ST_PERMANENT_ERROR	(COMP_ST_PERMANENT_ERROR) //!< SDA enumeration mapping.
#define E_ABPR_AlgoCompStateV2_COMP_ST_SUCCESS	(COMP_ST_SUCCESS) //!< SDA enumeration mapping.
#define E_ABPR_AlgoCompStateV2_COMP_ST_REDUCED_AVAILABILITY	(COMP_ST_REDUCED_AVAILABILITY) //!< SDA enumeration mapping.
#define E_ABPR_AlgoCompStateV2_COMP_ST_NOT_RUNNING	(COMP_ST_NOT_RUNNING) //!< SDA enumeration mapping.
typedef uint8 E_ABPR_AlgoCompStateV2_t; //!< Enumeration base type definition. [\@values: E_ABPR_AlgoCompStateV2](@ref E_ABPR_AlgoCompStateV2)

#ifndef _E_ABPR_LANECHANGETYPE_T_
#define _E_ABPR_LANECHANGETYPE_T_ //!< Macro switch for enumeration @ref E_ABPR_LaneChangeType.
/*!
 *	Defines whether a lane change has been detected or not. In case that a lane change has been detected, the direction of the lane change (left to right or right to left) is given. \n
 *	ABD_LC_UNKNOWN = 0 \n
 *	ABD_LC_LEFT = 1 \n
 *	ABD_LC_RIGHT = 2 \n
 *	ABD_LC_UNCHANGED = 3
 */
typedef enum
{
	ABD_LC_UNKNOWN	= 0, //!< 0
	ABD_LC_LEFT	= 1, //!< 1
	ABD_LC_RIGHT	= 2, //!< 2
	ABD_LC_UNCHANGED	= 3 //!< 3
} E_ABPR_LaneChangeType;
#endif // _E_ABPR_LANECHANGETYPE_T_
#define E_ABPR_LaneChangeType_ABD_LC_UNKNOWN	(ABD_LC_UNKNOWN) //!< SDA enumeration mapping.
#define E_ABPR_LaneChangeType_ABD_LC_LEFT	(ABD_LC_LEFT) //!< SDA enumeration mapping.
#define E_ABPR_LaneChangeType_ABD_LC_RIGHT	(ABD_LC_RIGHT) //!< SDA enumeration mapping.
#define E_ABPR_LaneChangeType_ABD_LC_UNCHANGED	(ABD_LC_UNCHANGED) //!< SDA enumeration mapping.
typedef uint8 E_ABPR_LaneChangeType_t; //!< Enumeration base type definition. [\@values: E_ABPR_LaneChangeType](@ref E_ABPR_LaneChangeType)

#ifndef _E_ABPR_LANEEVENTTYPE_T_
#define _E_ABPR_LANEEVENTTYPE_T_ //!< Macro switch for enumeration @ref E_ABPR_LaneEventType.
/*!
 *	Describes the event (e.g. construction site, pedestrian crossing, exit,�) present on one or both sides of the ego lane boundary. \n
 *	ABD_LE_IDLE = 0 \n
 *	ABD_LE_FORK_EXIT = 1 \n
 *	ABD_LE_FORK_ENTRY = 2 \n
 *	ABD_LE_FORK_UNKNOWN_OPEN = 3 \n
 *	ABD_LE_FORK_UNKNOWN_CLOSE = 4 \n
 *	ABD_LE_CONSTRUCTION_START = 5 \n
 *	ABD_LE_CONSTRUCTION_STOP = 6 \n
 *	ABD_LE_PEDX_START = 7 \n
 *	ABD_LE_PEDX_STOP = 8
 */
typedef enum
{
	ABD_LE_IDLE	= 0, //!< 0
	ABD_LE_FORK_EXIT	= 1, //!< 1
	ABD_LE_FORK_ENTRY	= 2, //!< 2
	ABD_LE_FORK_UNKNOWN_OPEN	= 3, //!< 3
	ABD_LE_FORK_UNKNOWN_CLOSE	= 4, //!< 4
	ABD_LE_CONSTRUCTION_START	= 5, //!< 5
	ABD_LE_CONSTRUCTION_STOP	= 6, //!< 6
	ABD_LE_PEDX_START	= 7, //!< 7
	ABD_LE_PEDX_STOP	= 8 //!< 8
} E_ABPR_LaneEventType;
#endif // _E_ABPR_LANEEVENTTYPE_T_
#define E_ABPR_LaneEventType_ABD_LE_IDLE	(ABD_LE_IDLE) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_FORK_EXIT	(ABD_LE_FORK_EXIT) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_FORK_ENTRY	(ABD_LE_FORK_ENTRY) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_FORK_UNKNOWN_OPEN	(ABD_LE_FORK_UNKNOWN_OPEN) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_FORK_UNKNOWN_CLOSE	(ABD_LE_FORK_UNKNOWN_CLOSE) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_CONSTRUCTION_START	(ABD_LE_CONSTRUCTION_START) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_CONSTRUCTION_STOP	(ABD_LE_CONSTRUCTION_STOP) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_PEDX_START	(ABD_LE_PEDX_START) //!< SDA enumeration mapping.
#define E_ABPR_LaneEventType_ABD_LE_PEDX_STOP	(ABD_LE_PEDX_STOP) //!< SDA enumeration mapping.
typedef uint8 E_ABPR_LaneEventType_t; //!< Enumeration base type definition. [\@values: E_ABPR_LaneEventType](@ref E_ABPR_LaneEventType)

#ifndef _E_ABPR_LANEMARKERSCOLORTYPE_T_
#define _E_ABPR_LANEMARKERSCOLORTYPE_T_ //!< Macro switch for enumeration @ref E_ABPR_LaneMarkersColorType.
/*!
 *	Defines the color of a lane boundary track. Remark: Green is a legacy value that will not be filled. Red will be mapped to yellow. \n
 *	ABD_MC_UNCLASSIFIED = 0  \n
 *	ABD_MC_WHITE = 1 \n
 *	ABD_MC_YELLOW = 2 \n
 *	ABD_MC_RED = 3 \n
 *	ABD_MC_BLUE = 4 \n
 *	ABD_MC_GREEN = 5
 */
typedef enum
{
	ABD_MC_UNCLASSIFIED	= 0, //!< 0
	ABD_MC_WHITE	= 1, //!< 1
	ABD_MC_YELLOW	= 2, //!< 2
	ABD_MC_RED	= 3, //!< 3
	ABD_MC_BLUE	= 4, //!< 4
	ABD_MC_GREEN	= 5 //!< 5
} E_ABPR_LaneMarkersColorType;
#endif // _E_ABPR_LANEMARKERSCOLORTYPE_T_
#define E_ABPR_LaneMarkersColorType_ABD_MC_UNCLASSIFIED	(ABD_MC_UNCLASSIFIED) //!< SDA enumeration mapping.
#define E_ABPR_LaneMarkersColorType_ABD_MC_WHITE	(ABD_MC_WHITE) //!< SDA enumeration mapping.
#define E_ABPR_LaneMarkersColorType_ABD_MC_YELLOW	(ABD_MC_YELLOW) //!< SDA enumeration mapping.
#define E_ABPR_LaneMarkersColorType_ABD_MC_RED	(ABD_MC_RED) //!< SDA enumeration mapping.
#define E_ABPR_LaneMarkersColorType_ABD_MC_BLUE	(ABD_MC_BLUE) //!< SDA enumeration mapping.
#define E_ABPR_LaneMarkersColorType_ABD_MC_GREEN	(ABD_MC_GREEN) //!< SDA enumeration mapping.
typedef uint8 E_ABPR_LaneMarkersColorType_t; //!< Enumeration base type definition. [\@values: E_ABPR_LaneMarkersColorType](@ref E_ABPR_LaneMarkersColorType)

#ifndef _E_ABPR_LANEQUALIFIERTYPE_T_
#define _E_ABPR_LANEQUALIFIERTYPE_T_ //!< Macro switch for enumeration @ref E_ABPR_LaneQualifierType.
/*!
 *	Qualifier enumeration that determines the internal ego lane detection state
 */
typedef enum
{
	E_ABPLBP_LQ_NO_EGO_LN_MARKER	= 0, //!< 0
	E_ABPLBP_LQ_RI_EGO_LN_VALID	= 1, //!< 1
	E_ABPLBP_LQ_LE_EGO_LN_VALID	= 2, //!< 2
	E_ABPLBP_LQ_RI_EGO_LN_VIRTUAL	= 3, //!< 3
	E_ABPLBP_LQ_LE_EGO_LN_VIRTUAL	= 4, //!< 4
	E_ABPLBP_LQ_BOTH_EGO_LN_VALID	= 5 //!< 5
} E_ABPR_LaneQualifierType;
#endif // _E_ABPR_LANEQUALIFIERTYPE_T_
#define E_ABPR_LaneQualifierType_E_ABPLBP_LQ_NO_EGO_LN_MARKER	(E_ABPLBP_LQ_NO_EGO_LN_MARKER) //!< SDA enumeration mapping.
#define E_ABPR_LaneQualifierType_E_ABPLBP_LQ_RI_EGO_LN_VALID	(E_ABPLBP_LQ_RI_EGO_LN_VALID) //!< SDA enumeration mapping.
#define E_ABPR_LaneQualifierType_E_ABPLBP_LQ_LE_EGO_LN_VALID	(E_ABPLBP_LQ_LE_EGO_LN_VALID) //!< SDA enumeration mapping.
#define E_ABPR_LaneQualifierType_E_ABPLBP_LQ_RI_EGO_LN_VIRTUAL	(E_ABPLBP_LQ_RI_EGO_LN_VIRTUAL) //!< SDA enumeration mapping.
#define E_ABPR_LaneQualifierType_E_ABPLBP_LQ_LE_EGO_LN_VIRTUAL	(E_ABPLBP_LQ_LE_EGO_LN_VIRTUAL) //!< SDA enumeration mapping.
#define E_ABPR_LaneQualifierType_E_ABPLBP_LQ_BOTH_EGO_LN_VALID	(E_ABPLBP_LQ_BOTH_EGO_LN_VALID) //!< SDA enumeration mapping.
typedef uint8 E_ABPR_LaneQualifierType_t; //!< Enumeration base type definition. [\@values: E_ABPR_LaneQualifierType](@ref E_ABPR_LaneQualifierType)

#ifndef _E_DPRSMI_TRGREASTYPE_T_
#define _E_DPRSMI_TRGREASTYPE_T_ //!< Macro switch for enumeration @ref E_DPRSMI_TrgReasType.
/*!
 *	Trigger Reason of the RDP function.
 */
typedef enum
{
	E_DPRSMI_TRGREAS_NO_RDEDG	= 0, //!< 0
	E_DPRSMI_TRGREAS_RDEDG_ONLY	= 1, //!< 1
	E_DPRSMI_TRGREAS_RDEDG_LN_CONTG	= 2, //!< 2
	E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS	= 3, //!< 3
	E_DPRSMI_TRGREAS_RDEDG_LN_BOTH	= 4 //!< 4
} E_DPRSMI_TrgReasType;
#endif // _E_DPRSMI_TRGREASTYPE_T_
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG	(E_DPRSMI_TRGREAS_NO_RDEDG) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY	(E_DPRSMI_TRGREAS_RDEDG_ONLY) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG	(E_DPRSMI_TRGREAS_RDEDG_LN_CONTG) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS	(E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH	(E_DPRSMI_TRGREAS_RDEDG_LN_BOTH) //!< SDA enumeration mapping.
typedef uint8 E_DPRSMI_TrgReasType_t; //!< Enumeration base type definition. [\@values: E_DPRSMI_TrgReasType](@ref E_DPRSMI_TrgReasType)

#ifndef _E_DRMDAE_SYSWARNTYPE_T_
#define _E_DRMDAE_SYSWARNTYPE_T_ //!< Macro switch for enumeration @ref E_DRMDAE_SysWarnType.
/*!
 *	0 - NoWarning \n
 *	1 - AttentivnessRequest \n
 *	2 - TakeOverRequest  \n
 *	3 - DegradationTrigger
 */
typedef enum
{
	E_DRMDAE_NOWNG	= 0, //!< 0
	E_DRMDAE_ATVNREQ	= 1, //!< 1
	E_DRMDAE_TOR	= 2, //!< 2
	E_DRMDAE_DEGRTRIG	= 3 //!< 3
} E_DRMDAE_SysWarnType;
#endif // _E_DRMDAE_SYSWARNTYPE_T_
#define E_DRMDAE_SysWarnType_E_DRMDAE_NOWNG	(E_DRMDAE_NOWNG) //!< SDA enumeration mapping.
#define E_DRMDAE_SysWarnType_E_DRMDAE_ATVNREQ	(E_DRMDAE_ATVNREQ) //!< SDA enumeration mapping.
#define E_DRMDAE_SysWarnType_E_DRMDAE_TOR	(E_DRMDAE_TOR) //!< SDA enumeration mapping.
#define E_DRMDAE_SysWarnType_E_DRMDAE_DEGRTRIG	(E_DRMDAE_DEGRTRIG) //!< SDA enumeration mapping.
typedef uint8 E_DRMDAE_SysWarnType_t; //!< Enumeration base type definition. [\@values: E_DRMDAE_SysWarnType](@ref E_DRMDAE_SysWarnType)

#ifndef _E_DRMHOD_DEBUGMODETYPE_T_
#define _E_DRMHOD_DEBUGMODETYPE_T_ //!< Macro switch for enumeration @ref E_DRMHOD_DebugModeType.
/*!
 *	Debug mode for DRMHOD
 */
typedef enum
{
	E_DRMHOD_NORMAL_MODE	= 0, //!< 0
	E_DRMHOD_ALWAYS_HANDS_ON	= 1, //!< 1
	E_DRMHOD_ALWAYS_HANDS_OFF	= 2 //!< 2
} E_DRMHOD_DebugModeType;
#endif // _E_DRMHOD_DEBUGMODETYPE_T_
#define E_DRMHOD_DebugModeType_E_DRMHOD_NORMAL_MODE	(E_DRMHOD_NORMAL_MODE) //!< SDA enumeration mapping.
#define E_DRMHOD_DebugModeType_E_DRMHOD_ALWAYS_HANDS_ON	(E_DRMHOD_ALWAYS_HANDS_ON) //!< SDA enumeration mapping.
#define E_DRMHOD_DebugModeType_E_DRMHOD_ALWAYS_HANDS_OFF	(E_DRMHOD_ALWAYS_HANDS_OFF) //!< SDA enumeration mapping.
typedef uint8 E_DRMHOD_DebugModeType_t; //!< Enumeration base type definition. [\@values: E_DRMHOD_DebugModeType](@ref E_DRMHOD_DebugModeType)

#ifndef _E_DRMHOD_INTSTATETYPE_T_
#define _E_DRMHOD_INTSTATETYPE_T_ //!< Macro switch for enumeration @ref E_DRMHOD_IntStateType.
/*!
 *	Internal state of hands off detection module
 */
typedef enum
{
	E_DRMHOD_HON_L	= 0, //!< 0
	E_DRMHOD_HON_R	= 1, //!< 1
	E_DRMHOD_HON_SUSP	= 2, //!< 2
	E_DRMHOD_HOFF_SUSP_L	= 3, //!< 3
	E_DRMHOD_HOFF_SUSP_R	= 4, //!< 4
	E_DRMHOD_HOFF	= 5 //!< 5
} E_DRMHOD_IntStateType;
#endif // _E_DRMHOD_INTSTATETYPE_T_
#define E_DRMHOD_IntStateType_E_DRMHOD_HON_L	(E_DRMHOD_HON_L) //!< SDA enumeration mapping.
#define E_DRMHOD_IntStateType_E_DRMHOD_HON_R	(E_DRMHOD_HON_R) //!< SDA enumeration mapping.
#define E_DRMHOD_IntStateType_E_DRMHOD_HON_SUSP	(E_DRMHOD_HON_SUSP) //!< SDA enumeration mapping.
#define E_DRMHOD_IntStateType_E_DRMHOD_HOFF_SUSP_L	(E_DRMHOD_HOFF_SUSP_L) //!< SDA enumeration mapping.
#define E_DRMHOD_IntStateType_E_DRMHOD_HOFF_SUSP_R	(E_DRMHOD_HOFF_SUSP_R) //!< SDA enumeration mapping.
#define E_DRMHOD_IntStateType_E_DRMHOD_HOFF	(E_DRMHOD_HOFF) //!< SDA enumeration mapping.
typedef uint8 E_DRMHOD_IntStateType_t; //!< Enumeration base type definition. [\@values: E_DRMHOD_IntStateType](@ref E_DRMHOD_IntStateType)

#ifndef _E_HMORQG_BNDVALIDTYPE_T_
#define _E_HMORQG_BNDVALIDTYPE_T_ //!< Macro switch for enumeration @ref E_HMORQG_BndValidType.
/*!
 *	UNDEFINED
 */
typedef enum
{
	E_HMORQG_BND_NOT_VALID	= 0, //!< 0
	E_HMORQG_BND_VAL_LEFT_ONLY	= 1, //!< 1
	E_HMORQG_BND_VAL_RIGHT_ONLY	= 2, //!< 2
	E_HMORQG_BND_VAL_BOTH_SIDE	= 3 //!< 3
} E_HMORQG_BndValidType;
#endif // _E_HMORQG_BNDVALIDTYPE_T_
#define E_HMORQG_BndValidType_E_HMORQG_BND_NOT_VALID	(E_HMORQG_BND_NOT_VALID) //!< SDA enumeration mapping.
#define E_HMORQG_BndValidType_E_HMORQG_BND_VAL_LEFT_ONLY	(E_HMORQG_BND_VAL_LEFT_ONLY) //!< SDA enumeration mapping.
#define E_HMORQG_BndValidType_E_HMORQG_BND_VAL_RIGHT_ONLY	(E_HMORQG_BND_VAL_RIGHT_ONLY) //!< SDA enumeration mapping.
#define E_HMORQG_BndValidType_E_HMORQG_BND_VAL_BOTH_SIDE	(E_HMORQG_BND_VAL_BOTH_SIDE) //!< SDA enumeration mapping.
typedef uint8 E_HMORQG_BndValidType_t; //!< Enumeration base type definition. [\@values: E_HMORQG_BndValidType](@ref E_HMORQG_BndValidType)

#ifndef _E_LCF_CURVETYPE_T_
#define _E_LCF_CURVETYPE_T_ //!< Macro switch for enumeration @ref E_LCF_CurveType.
/*!
 *	Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight.
 */
typedef enum
{
	E_LCF_CURVE_NONE	= 0, //!< 0
	E_LCF_CURVE_INNER	= 1, //!< 1
	E_LCF_CURVE_OUTER	= 2 //!< 2
} E_LCF_CurveType;
#endif // _E_LCF_CURVETYPE_T_
#define E_LCF_CurveType_E_LCF_CURVE_NONE	(E_LCF_CURVE_NONE) //!< SDA enumeration mapping.
#define E_LCF_CurveType_E_LCF_CURVE_INNER	(E_LCF_CURVE_INNER) //!< SDA enumeration mapping.
#define E_LCF_CurveType_E_LCF_CURVE_OUTER	(E_LCF_CURVE_OUTER) //!< SDA enumeration mapping.
typedef uint8 E_LCF_CurveType_t; //!< Enumeration base type definition. [\@values: E_LCF_CurveType](@ref E_LCF_CurveType)

#ifndef _E_LCF_DANGEROUSSIDETYPE_T_
#define _E_LCF_DANGEROUSSIDETYPE_T_ //!< Macro switch for enumeration @ref E_LCF_DangerousSideType.
/*!
 *	UNDEFINED
 */
typedef enum
{
	E_LCF_DANGEROUSSIDE_NONE	= 0, //!< 0
	E_LCF_DANGEROUSSIDE_LEFT	= 1, //!< 1
	E_LCF_DANGEROUSSIDE_RIGHT	= 2 //!< 2
} E_LCF_DangerousSideType;
#endif // _E_LCF_DANGEROUSSIDETYPE_T_
#define E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE	(E_LCF_DANGEROUSSIDE_NONE) //!< SDA enumeration mapping.
#define E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT	(E_LCF_DANGEROUSSIDE_LEFT) //!< SDA enumeration mapping.
#define E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT	(E_LCF_DANGEROUSSIDE_RIGHT) //!< SDA enumeration mapping.
typedef uint8 E_LCF_DangerousSideType_t; //!< Enumeration base type definition. [\@values: E_LCF_DangerousSideType](@ref E_LCF_DangerousSideType)

#ifndef _E_LCF_FUNCTIONV3TYPE_T_
#define _E_LCF_FUNCTIONV3TYPE_T_ //!< Macro switch for enumeration @ref E_LCF_FunctionV3Type.
/*!
 *	Carries which function is allowed to control.
 */
typedef enum
{
	E_LCF_OFF_nu	= 0, //!< 0
	E_LCF_TJA_nu	= 1, //!< 1
	E_LCF_LDP_nu	= 2, //!< 2
	E_LCF_LDPOC_nu	= 3, //!< 3
	E_LCF_RDP_nu	= 4, //!< 4
	E_LCF_ALCA_nu	= 5, //!< 5
	E_LCF_AOLC_nu	= 6, //!< 6
	E_LCF_ESA_nu	= 7 //!< 7
} E_LCF_FunctionV3Type;
#endif // _E_LCF_FUNCTIONV3TYPE_T_
#define E_LCF_FunctionV3Type_E_LCF_OFF_nu	(E_LCF_OFF_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_TJA_nu	(E_LCF_TJA_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_LDP_nu	(E_LCF_LDP_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_LDPOC_nu	(E_LCF_LDPOC_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_RDP_nu	(E_LCF_RDP_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_ALCA_nu	(E_LCF_ALCA_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_AOLC_nu	(E_LCF_AOLC_nu) //!< SDA enumeration mapping.
#define E_LCF_FunctionV3Type_E_LCF_ESA_nu	(E_LCF_ESA_nu) //!< SDA enumeration mapping.
typedef uint8 E_LCF_FunctionV3Type_t; //!< Enumeration base type definition. [\@values: E_LCF_FunctionV3Type](@ref E_LCF_FunctionV3Type)

#ifndef _E_LCF_LAKMCLANESTATUSTYPE_T_
#define _E_LCF_LAKMCLANESTATUSTYPE_T_ //!< Macro switch for enumeration @ref E_LCF_LaKMCLaneStatusType.
/*!
 *	Side of xDP Intervention
 */
typedef enum
{
	E_LCF_NO_LANE_DEPARTURE	= 0, //!< 0
	E_LCF_DEPARTING_LEFT_LANE	= 1, //!< 1
	E_LCF_DEPARTING_LEFT_LANE_FAST	= 2, //!< 2
	E_LCF_DEPARTING_RIGHT_LANE	= 3, //!< 3
	E_LCF_DEPARTING_RIGHT_LANE_FAST	= 4, //!< 4
	E_LCF_DEPARTING_LANE_INVALID	= 7 //!< 7
} E_LCF_LaKMCLaneStatusType;
#endif // _E_LCF_LAKMCLANESTATUSTYPE_T_
#define E_LCF_LaKMCLaneStatusType_E_LCF_NO_LANE_DEPARTURE	(E_LCF_NO_LANE_DEPARTURE) //!< SDA enumeration mapping.
#define E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_LEFT_LANE	(E_LCF_DEPARTING_LEFT_LANE) //!< SDA enumeration mapping.
#define E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_LEFT_LANE_FAST	(E_LCF_DEPARTING_LEFT_LANE_FAST) //!< SDA enumeration mapping.
#define E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_RIGHT_LANE	(E_LCF_DEPARTING_RIGHT_LANE) //!< SDA enumeration mapping.
#define E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_RIGHT_LANE_FAST	(E_LCF_DEPARTING_RIGHT_LANE_FAST) //!< SDA enumeration mapping.
#define E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_LANE_INVALID	(E_LCF_DEPARTING_LANE_INVALID) //!< SDA enumeration mapping.
typedef uint8 E_LCF_LaKMCLaneStatusType_t; //!< Enumeration base type definition. [\@values: E_LCF_LaKMCLaneStatusType](@ref E_LCF_LaKMCLaneStatusType)

#ifndef _E_LCF_SYSSTATEDIRECTIONTYPE_T_
#define _E_LCF_SYSSTATEDIRECTIONTYPE_T_ //!< Macro switch for enumeration @ref E_LCF_SysStateDirectionType.
/*!
 *	System State for the left side of the RDW function.
 */
typedef enum
{
	E_LCF_SSD_LN_NOT_AVL	= 0, //!< 0
	E_LCF_SSD_LN_AVL	= 1, //!< 1
	E_LCF_SSD_TRIGGER	= 2, //!< 2
	E_LCF_SSD_RUNNING	= 3, //!< 3
	E_LCF_SSD_SUCCESSFUL	= 4, //!< 4
	E_LCF_SSD_CNCL_DRV	= 5, //!< 5
	E_LCF_SSD_CNCL_LAT_DEV	= 6, //!< 6
	E_LCF_SSD_CNCL_LANE	= 7, //!< 7
	E_LCF_SSD_CNCL_OTHER	= 8, //!< 8
	E_LCF_SSD_ABORT	= 9, //!< 9
	E_LCF_SSD_INVALID	= 15 //!< 15
} E_LCF_SysStateDirectionType;
#endif // _E_LCF_SYSSTATEDIRECTIONTYPE_T_
#define E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL	(E_LCF_SSD_LN_NOT_AVL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL	(E_LCF_SSD_LN_AVL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_TRIGGER	(E_LCF_SSD_TRIGGER) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_RUNNING	(E_LCF_SSD_RUNNING) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_SUCCESSFUL	(E_LCF_SSD_SUCCESSFUL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV	(E_LCF_SSD_CNCL_DRV) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV	(E_LCF_SSD_CNCL_LAT_DEV) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE	(E_LCF_SSD_CNCL_LANE) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER	(E_LCF_SSD_CNCL_OTHER) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_ABORT	(E_LCF_SSD_ABORT) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirectionType_E_LCF_SSD_INVALID	(E_LCF_SSD_INVALID) //!< SDA enumeration mapping.
typedef uint8 E_LCF_SysStateDirectionType_t; //!< Enumeration base type definition. [\@values: E_LCF_SysStateDirectionType](@ref E_LCF_SysStateDirectionType)

#ifndef _E_LCF_SYSSTATETYPE_T_
#define _E_LCF_SYSSTATETYPE_T_ //!< Macro switch for enumeration @ref E_LCF_SysStateType.
/*!
 *	ESA System State
 */
typedef enum
{
	E_LCF_SYSSTATE_NOTPRESENT_nu	= 0, //!< 0
	E_LCF_SYSSTATE_DISABLED_nu	= 1, //!< 1
	E_LCF_SYSSTATE_PASSIVE_nu	= 2, //!< 2
	E_LCF_SYSSTATE_REQUEST_nu	= 3, //!< 3
	E_LCF_SYSSTATE_CONTROLLING_nu	= 4, //!< 4
	E_LCF_SYSSTATE_RAMPOUT_nu	= 5, //!< 5
	E_LCF_SYSSTATE_ERROR_nu	= 6 //!< 6
} E_LCF_SysStateType;
#endif // _E_LCF_SYSSTATETYPE_T_
#define E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu	(E_LCF_SYSSTATE_NOTPRESENT_nu) //!< SDA enumeration mapping.
#define E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu	(E_LCF_SYSSTATE_DISABLED_nu) //!< SDA enumeration mapping.
#define E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu	(E_LCF_SYSSTATE_PASSIVE_nu) //!< SDA enumeration mapping.
#define E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu	(E_LCF_SYSSTATE_REQUEST_nu) //!< SDA enumeration mapping.
#define E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu	(E_LCF_SYSSTATE_CONTROLLING_nu) //!< SDA enumeration mapping.
#define E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu	(E_LCF_SYSSTATE_RAMPOUT_nu) //!< SDA enumeration mapping.
#define E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu	(E_LCF_SYSSTATE_ERROR_nu) //!< SDA enumeration mapping.
typedef uint8 E_LCF_SysStateType_t; //!< Enumeration base type definition. [\@values: E_LCF_SysStateType](@ref E_LCF_SysStateType)

#ifndef _E_HMOS202_SYSSTATETYPE_
#define _E_HMOS202_SYSSTATETYPE_ //!< Macro switch for enumeration @ref.
/*!
 *	ESA System State
 */
typedef enum
{
	E_HMOS202_SYSSTATE_OFF	= 0, //!< 0
	E_HMOS202_SYSSTATE_STANDBY	= 1, //!< 1
	E_HMOS202_SYSSTATE_PASSIVE	= 2, //!< 2
	E_HMOS202_SYSSTATE_ACTIVE	= 3, //!< 3
	E_HMOS202_SYSSTATE_SUSPEND	= 4, //!< 4
	E_HMOS202_SYSSTATE_PROHIBITION	= 5, //!< 5
	E_HMOS202_SYSSTATE_ERROR	= 6 //!< 6
} E_HMOS202_SysStateType;
#endif // 
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_OFF	(E_HMOS202_SYSSTATE_OFF) //!< SDA enumeration mapping.
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_STANDBY	(E_HMOS202_SYSSTATE_STANDBY) //!< SDA enumeration mapping.
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_PASSIVE	(E_HMOS202_SYSSTATE_PASSIVE) //!< SDA enumeration mapping.
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_ACTIVE	(E_HMOS202_SYSSTATE_ACTIVE) //!< SDA enumeration mapping.
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_SUSPEND	(E_HMOS202_SYSSTATE_SUSPEND) //!< SDA enumeration mapping.
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_PROHIBITION	(E_HMOS202_SYSSTATE_PROHIBITION) //!< SDA enumeration mapping.
#define E_HMOS202_SysStateType_E_HMOS202_SYSSTATE_ERROR	(E_HMOS202_SYSSTATE_ERROR) //!< SDA enumeration mapping.
typedef uint8 E_HMOS202_SysStateType_t; //!< Enumeration base type definition. [\@values: E_LCF_SysStateType](@ref E_LCF_SysStateType)

#ifndef _E_LCF_TGQ_TYPE_T_
#define _E_LCF_TGQ_TYPE_T_ //!< Macro switch for enumeration @ref E_LCF_TGQ_Type.
/*!
 *	Trajectory Guidance Qualifier Output
 */
typedef enum
{
	E_LCF_TGQ_REQ_OFF	= 0, //!< 0
	E_LCF_TGQ_REQ	= 1, //!< 1
	E_LCF_TGQ_REQ_FREEZE	= 3, //!< 3
	E_LCF_TGQ_REQ_FFC	= 4, //!< 4
	E_LCF_TGQ_REQ_REFCHNG	= 5 //!< 5
} E_LCF_TGQ_Type;
#endif // _E_LCF_TGQ_TYPE_T_
#define E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF	(E_LCF_TGQ_REQ_OFF) //!< SDA enumeration mapping.
#define E_LCF_TGQ_Type_E_LCF_TGQ_REQ	(E_LCF_TGQ_REQ) //!< SDA enumeration mapping.
#define E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE	(E_LCF_TGQ_REQ_FREEZE) //!< SDA enumeration mapping.
#define E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FFC	(E_LCF_TGQ_REQ_FFC) //!< SDA enumeration mapping.
#define E_LCF_TGQ_Type_E_LCF_TGQ_REQ_REFCHNG	(E_LCF_TGQ_REQ_REFCHNG) //!< SDA enumeration mapping.
typedef uint8 E_LCF_TGQ_Type_t; //!< Enumeration base type definition. [\@values: E_LCF_TGQ_Type](@ref E_LCF_TGQ_Type)

#ifndef _E_LCF_WIPER_STAGE_T_
#define _E_LCF_WIPER_STAGE_T_ //!< Macro switch for enumeration @ref E_LCF_WIPER_STAGE.
/*!
 *	Wiper state
 */
typedef enum
{
	E_VEH_SIG_ADD_WIPER_OFF	= 0, //!< 0
	E_VEH_SIG_ADD_WIPER_INTERVAL1	= 1, //!< 1
	E_VEH_SIG_ADD_WIPER_INTERVAL2	= 2, //!< 2
	E_VEH_SIG_ADD_WIPER_INTERVAL3	= 3, //!< 3
	E_VEH_SIG_ADD_WIPER_INTERVAL4	= 4, //!< 4
	E_VEH_SIG_ADD_WIPER_STAGE1	= 5, //!< 5
	E_VEH_SIG_ADD_WIPER_STAGE2	= 6 //!< 6
} E_LCF_WIPER_STAGE;
#endif // _E_LCF_WIPER_STAGE_T_
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_OFF	(E_VEH_SIG_ADD_WIPER_OFF) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL1	(E_VEH_SIG_ADD_WIPER_INTERVAL1) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL2	(E_VEH_SIG_ADD_WIPER_INTERVAL2) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL3	(E_VEH_SIG_ADD_WIPER_INTERVAL3) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_INTERVAL4	(E_VEH_SIG_ADD_WIPER_INTERVAL4) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_STAGE1	(E_VEH_SIG_ADD_WIPER_STAGE1) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STAGE_E_VEH_SIG_ADD_WIPER_STAGE2	(E_VEH_SIG_ADD_WIPER_STAGE2) //!< SDA enumeration mapping.
typedef uint8 E_LCF_WIPER_STAGE_t; //!< Enumeration base type definition. [\@values: E_LCF_WIPER_STAGE](@ref E_LCF_WIPER_STAGE)

#ifndef _E_LCF_WIPER_STATE_T_
#define _E_LCF_WIPER_STATE_T_ //!< Macro switch for enumeration @ref E_LCF_WIPER_STATE.
/*!
 *	Wiper State
 */
typedef enum
{
	E_VEH_SIG_WIPER_STATE_INACTIVE	= 0, //!< 0
	E_VEH_SIG_WIPER_STATE_ACTIVE	= 1 //!< 1
} E_LCF_WIPER_STATE;
#endif // _E_LCF_WIPER_STATE_T_
#define E_LCF_WIPER_STATE_E_VEH_SIG_WIPER_STATE_INACTIVE	(E_VEH_SIG_WIPER_STATE_INACTIVE) //!< SDA enumeration mapping.
#define E_LCF_WIPER_STATE_E_VEH_SIG_WIPER_STATE_ACTIVE	(E_VEH_SIG_WIPER_STATE_ACTIVE) //!< SDA enumeration mapping.
typedef uint8 E_LCF_WIPER_STATE_t; //!< Enumeration base type definition. [\@values: E_LCF_WIPER_STATE](@ref E_LCF_WIPER_STATE)

#ifndef _E_LKASTM_LATCTRLMDTYPE_T_
#define _E_LKASTM_LATCTRLMDTYPE_T_ //!< Macro switch for enumeration @ref E_LKASTM_LatCtrlMdType.
/*!
 *	UNDEFINED
 */
typedef enum
{
	E_LKASTM_LATCTRLMD_PASSIVE	= 0, //!< 0
	E_LKASTM_LATCTRLMD_LNCENTRING	= 1, //!< 1
	E_LKASTM_LATCTRLMD_DEGR	= 2 //!< 2
} E_LKASTM_LatCtrlMdType;
#endif // _E_LKASTM_LATCTRLMDTYPE_T_
#define E_LKASTM_LatCtrlMdType_E_LKASTM_LATCTRLMD_PASSIVE	(E_LKASTM_LATCTRLMD_PASSIVE) //!< SDA enumeration mapping.
#define E_LKASTM_LatCtrlMdType_E_LKASTM_LATCTRLMD_LNCENTRING	(E_LKASTM_LATCTRLMD_LNCENTRING) //!< SDA enumeration mapping.
#define E_LKASTM_LatCtrlMdType_E_LKASTM_LATCTRLMD_DEGR	(E_LKASTM_LATCTRLMD_DEGR) //!< SDA enumeration mapping.
typedef uint8 E_LKASTM_LatCtrlMdType_t; //!< Enumeration base type definition. [\@values: E_LKASTM_LatCtrlMdType](@ref E_LKASTM_LatCtrlMdType)

#ifndef _E_OBPFOP_ACCOBJMEASSTATETYPE_T_
#define _E_OBPFOP_ACCOBJMEASSTATETYPE_T_ //!< Macro switch for enumeration @ref E_OBPFOP_ACCObjMeasStateType.
/*!
 *	ACC object measurement state
 */
typedef enum
{
	E_ODPFOP_ACC_MS_DELETED	= 0, //!< 0
	E_ODPFOP_ACC_MS_NEW	= 1, //!< 1
	E_ODPFOP_ACC_MS_MEASURED	= 2, //!< 2
	E_ODPFOP_ACC_MS_PREDICTED	= 3, //!< 3
	E_ODPFOP_ACC_MS_INACTIVE	= 4, //!< 4
	E_ODPFOP_ACC_MS_MAXDIFF	= 5 //!< 5
} E_OBPFOP_ACCObjMeasStateType;
#endif // _E_OBPFOP_ACCOBJMEASSTATETYPE_T_
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_DELETED	(E_ODPFOP_ACC_MS_DELETED) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_NEW	(E_ODPFOP_ACC_MS_NEW) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_MEASURED	(E_ODPFOP_ACC_MS_MEASURED) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_PREDICTED	(E_ODPFOP_ACC_MS_PREDICTED) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_INACTIVE	(E_ODPFOP_ACC_MS_INACTIVE) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_MAXDIFF	(E_ODPFOP_ACC_MS_MAXDIFF) //!< SDA enumeration mapping.
typedef uint8 E_OBPFOP_ACCObjMeasStateType_t; //!< Enumeration base type definition. [\@values: E_OBPFOP_ACCObjMeasStateType](@ref E_OBPFOP_ACCObjMeasStateType)

#ifndef _E_ODPFOP_ACCOBJCLASSTYPE_T_
#define _E_ODPFOP_ACCOBJCLASSTYPE_T_ //!< Macro switch for enumeration @ref E_ODPFOP_ACCObjClassType.
/*!
 *	This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles
 */
typedef enum
{
	E_ODPFOP_ACC_OC_POINT	= 0, //!< 0
	E_ODPFOP_ACC_OC_CAR	= 1, //!< 1
	E_ODPFOP_ACC_OC_TRUCK	= 2, //!< 2
	E_ODPFOP_ACC_OC_PEDESTRIAN	= 3, //!< 3
	E_ODPFOP_ACC_OC_MOTORCYCLE	= 4, //!< 4
	E_ODPFOP_ACC_OC_BICYCLE	= 5, //!< 5
	E_ODPFOP_ACC_OC_WIDE	= 6, //!< 6
	E_ODPFOP_ACC_OC_UNCLASSIFIED	= 7, //!< 7
	E_ODPFOP_ACC_OC_TL	= 8, //!< 8
	E_ODPFOP_ACC_OC_MAXDIFFTYPES	= 9 //!< 9
} E_ODPFOP_ACCObjClassType;
#endif // _E_ODPFOP_ACCOBJCLASSTYPE_T_
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_POINT	(E_ODPFOP_ACC_OC_POINT) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_CAR	(E_ODPFOP_ACC_OC_CAR) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_TRUCK	(E_ODPFOP_ACC_OC_TRUCK) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_PEDESTRIAN	(E_ODPFOP_ACC_OC_PEDESTRIAN) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_MOTORCYCLE	(E_ODPFOP_ACC_OC_MOTORCYCLE) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_BICYCLE	(E_ODPFOP_ACC_OC_BICYCLE) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_WIDE	(E_ODPFOP_ACC_OC_WIDE) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_UNCLASSIFIED	(E_ODPFOP_ACC_OC_UNCLASSIFIED) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_TL	(E_ODPFOP_ACC_OC_TL) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_MAXDIFFTYPES	(E_ODPFOP_ACC_OC_MAXDIFFTYPES) //!< SDA enumeration mapping.
typedef uint8 E_ODPFOP_ACCObjClassType_t; //!< Enumeration base type definition. [\@values: E_ODPFOP_ACCObjClassType](@ref E_ODPFOP_ACCObjClassType)

#ifndef _E_TJACMB_COMBMODETYPE_T_
#define _E_TJACMB_COMBMODETYPE_T_ //!< Macro switch for enumeration @ref E_TJACMB_CombModeType.
/*!
 *	Combined mode state
 */
typedef enum
{
	E_TJACMB_CMBMD_PASSIVE	= 0, //!< 0
	E_TJACMB_CMBMD_LC	= 1, //!< 1
	E_TJACMB_CMBMD_OF	= 2, //!< 2
	E_TJACMB_CMBMD_OF_DEBUG	= 3 //!< 3
} E_TJACMB_CombModeType;
#endif // _E_TJACMB_COMBMODETYPE_T_
#define E_TJACMB_CombModeType_E_TJACMB_CMBMD_PASSIVE	(E_TJACMB_CMBMD_PASSIVE) //!< SDA enumeration mapping.
#define E_TJACMB_CombModeType_E_TJACMB_CMBMD_LC	(E_TJACMB_CMBMD_LC) //!< SDA enumeration mapping.
#define E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF	(E_TJACMB_CMBMD_OF) //!< SDA enumeration mapping.
#define E_TJACMB_CombModeType_E_TJACMB_CMBMD_OF_DEBUG	(E_TJACMB_CMBMD_OF_DEBUG) //!< SDA enumeration mapping.
typedef uint8 E_TJACMB_CombModeType_t; //!< Enumeration base type definition. [\@values: E_TJACMB_CombModeType](@ref E_TJACMB_CombModeType)

#ifndef _E_TJASLC_MNVSTATETYPE_T_
#define _E_TJASLC_MNVSTATETYPE_T_ //!< Macro switch for enumeration @ref E_TJASLC_MnvStateType.
/*!
 *	TJASLC_OUTPUT \n
 *	 \n
 *	Outputs the lane change maneuver state
 */
typedef enum
{
	E_TJASLC_PASSIVE	= 0, //!< 0
	E_TJASLC_TRIGREADY	= 1, //!< 1
	E_TJASLC_LCPSTART	= 2, //!< 2
	E_TJASLC_LATMVSTART	= 3, //!< 3
	E_TJASLC_LCMSTART	= 4, //!< 4
	E_TJASLC_NEWEGO	= 5, //!< 5
	E_TJASLC_LCMEND	= 6, //!< 6
	E_TJASLC_ABORT	= 7 //!< 7
} E_TJASLC_MnvStateType;
#endif // _E_TJASLC_MNVSTATETYPE_T_
#define E_TJASLC_MnvStateType_E_TJASLC_PASSIVE	(E_TJASLC_PASSIVE) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_TRIGREADY	(E_TJASLC_TRIGREADY) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_LCPSTART	(E_TJASLC_LCPSTART) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_LATMVSTART	(E_TJASLC_LATMVSTART) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_LCMSTART	(E_TJASLC_LCMSTART) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_NEWEGO	(E_TJASLC_NEWEGO) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_LCMEND	(E_TJASLC_LCMEND) //!< SDA enumeration mapping.
#define E_TJASLC_MnvStateType_E_TJASLC_ABORT	(E_TJASLC_ABORT) //!< SDA enumeration mapping.
typedef uint8 E_TJASLC_MnvStateType_t; //!< Enumeration base type definition. [\@values: E_TJASLC_MnvStateType](@ref E_TJASLC_MnvStateType)

#ifndef _E_TJASTM_LATCTRLMDV4TYPE_T_
#define _E_TJASTM_LATCTRLMDV4TYPE_T_ //!< Macro switch for enumeration @ref E_TJASTM_LatCtrlMdV4Type.
/*!
 *	TJASTM_OUTPUT
 */
typedef enum
{
	E_TJASTM_LATCTRLMD_PASSIVE	= 0, //!< 0
	E_TJASTM_LATCTRLMD_LC	= 1, //!< 1
	E_TJASTM_LATCTRLMD_OF	= 2, //!< 2
	E_TJASTM_LATCTRLMD_CMB	= 3, //!< 3
	E_TJASTM_LATCTRLMD_SALC	= 4, //!< 4
	E_TJASTM_LATCTRLMD_LC_RQ	= 5, //!< 5
	E_TJASTM_LATCTRLMD_OF_RQ	= 6, //!< 6
	E_TJASTM_LATCTRLMD_CMB_RQ	= 7, //!< 7
	E_TJASTM_LATCTRLMD_SALC_RQ	= 8 //!< 8
} E_TJASTM_LatCtrlMdV4Type;
#endif // _E_TJASTM_LATCTRLMDV4TYPE_T_
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE	(E_TJASTM_LATCTRLMD_PASSIVE) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC	(E_TJASTM_LATCTRLMD_LC) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF	(E_TJASTM_LATCTRLMD_OF) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB	(E_TJASTM_LATCTRLMD_CMB) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC	(E_TJASTM_LATCTRLMD_SALC) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ	(E_TJASTM_LATCTRLMD_LC_RQ) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ	(E_TJASTM_LATCTRLMD_OF_RQ) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ	(E_TJASTM_LATCTRLMD_CMB_RQ) //!< SDA enumeration mapping.
#define E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC_RQ	(E_TJASTM_LATCTRLMD_SALC_RQ) //!< SDA enumeration mapping.
typedef uint8 E_TJASTM_LatCtrlMdV4Type_t; //!< Enumeration base type definition. [\@values: E_TJASTM_LatCtrlMdV4Type](@ref E_TJASTM_LatCtrlMdV4Type)

#ifndef _E_TJASTM_LNCHNGTRIGGERTYPE_T_
#define _E_TJASTM_LNCHNGTRIGGERTYPE_T_ //!< Macro switch for enumeration @ref E_TJASTM_LnChngTriggerType.
/*!
 *	Indicates if and to which side lane change is triggered by driver
 */
typedef enum
{
	E_TJASTM_LNCHNG_NO_TRIG	= 0, //!< 0
	E_TJASTM_LNCHNG_LEFT_TRIG	= 1, //!< 1
	E_TJASTM_LNCHNG_RIGHT_TRIG	= 2 //!< 2
} E_TJASTM_LnChngTriggerType;
#endif // _E_TJASTM_LNCHNGTRIGGERTYPE_T_
#define E_TJASTM_LnChngTriggerType_E_TJASTM_LNCHNG_NO_TRIG	(E_TJASTM_LNCHNG_NO_TRIG) //!< SDA enumeration mapping.
#define E_TJASTM_LnChngTriggerType_E_TJASTM_LNCHNG_LEFT_TRIG	(E_TJASTM_LNCHNG_LEFT_TRIG) //!< SDA enumeration mapping.
#define E_TJASTM_LnChngTriggerType_E_TJASTM_LNCHNG_RIGHT_TRIG	(E_TJASTM_LNCHNG_RIGHT_TRIG) //!< SDA enumeration mapping.
typedef uint8 E_TJASTM_LnChngTriggerType_t; //!< Enumeration base type definition. [\@values: E_TJASTM_LnChngTriggerType](@ref E_TJASTM_LnChngTriggerType)

#ifndef _E_VDPDRV_TURNSIGNALTYPE_T_
#define _E_VDPDRV_TURNSIGNALTYPE_T_ //!< Macro switch for enumeration @ref E_VDPDRV_TurnSignalType.
/*!
 *	Turn Indicator signal state
 */
typedef enum
{
	E_VDPDRV_TURN_SIG_OFF	= 0, //!< 0
	E_VDPDRV_TURN_SIG_LEFT	= 1, //!< 1
	E_VDPDRV_TURN_SIG_RIGHT	= 2, //!< 2
	E_VDPDRV_TURN_SIG_BOTH	= 3 //!< 3
} E_VDPDRV_TurnSignalType;
#endif // _E_VDPDRV_TURNSIGNALTYPE_T_
#define E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_OFF	(E_VDPDRV_TURN_SIG_OFF) //!< SDA enumeration mapping.
#define E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_LEFT	(E_VDPDRV_TURN_SIG_LEFT) //!< SDA enumeration mapping.
#define E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_RIGHT	(E_VDPDRV_TURN_SIG_RIGHT) //!< SDA enumeration mapping.
#define E_VDPDRV_TurnSignalType_E_VDPDRV_TURN_SIG_BOTH	(E_VDPDRV_TURN_SIG_BOTH) //!< SDA enumeration mapping.
typedef uint8 E_VDPDRV_TurnSignalType_t; //!< Enumeration base type definition. [\@values: E_VDPDRV_TurnSignalType](@ref E_VDPDRV_TurnSignalType)

/* add for MFC5J3 in 20211119 start*/
#ifndef _E_LCF_SYSSTATEDIROBJTYPE_T_
#define _E_LCF_SYSSTATEDIROBJTYPE_T_ //!< Macro switch for enumeration @ref E_LCF_SysStateDirObjType.
/*!
 *	UNDEFINED
 */
typedef enum
{
	E_LCF_SSDO_LN_OBJ_IF_NOT_AVL	= 0, //!< 0
	E_LCF_SSDO_LN_AVL	= 1, //!< 1
	E_LCF_SSDO_OBJ_IFACE_AVL	= 2, //!< 2
	E_LCF_SSDO_TRIGGER	= 3, //!< 3
	E_LCF_SSDO_RUNNING	= 4, //!< 4
	E_LCF_SSDO_SUCCESSFUL	= 5, //!< 5
	E_LCF_SSDO_CNCL_DRV	= 6, //!< 6
	E_LCF_SSDO_CNCL_LAT_DEV	= 7, //!< 7
	E_LCF_SSDO_CNCL_LANE	= 8, //!< 8
	E_LCF_SSDO_CNCL_OBJ_IFACE	= 9, //!< 9
	E_LCF_SSDO_CNCL_OTHER	= 10, //!< 10
	E_LCF_SSDO_ABORT	= 11, //!< 11
	E_LCF_SSDO_INVALID	= 15 //!< 15
} E_LCF_SysStateDirObjType;
#endif // _E_LCF_SYSSTATEDIROBJTYPE_T_
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_LN_OBJ_IF_NOT_AVL	(E_LCF_SSDO_LN_OBJ_IF_NOT_AVL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_LN_AVL	(E_LCF_SSDO_LN_AVL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_OBJ_IFACE_AVL	(E_LCF_SSDO_OBJ_IFACE_AVL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_TRIGGER	(E_LCF_SSDO_TRIGGER) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_RUNNING	(E_LCF_SSDO_RUNNING) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_SUCCESSFUL	(E_LCF_SSDO_SUCCESSFUL) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_DRV	(E_LCF_SSDO_CNCL_DRV) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_LAT_DEV	(E_LCF_SSDO_CNCL_LAT_DEV) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_LANE	(E_LCF_SSDO_CNCL_LANE) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_OBJ_IFACE	(E_LCF_SSDO_CNCL_OBJ_IFACE) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_CNCL_OTHER	(E_LCF_SSDO_CNCL_OTHER) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_ABORT	(E_LCF_SSDO_ABORT) //!< SDA enumeration mapping.
#define E_LCF_SysStateDirObjType_E_LCF_SSDO_INVALID	(E_LCF_SSDO_INVALID) //!< SDA enumeration mapping.
typedef uint8 E_LCF_SysStateDirObjType_t; //!< Enumeration base type definition. [\@values: E_LCF_SysStateDirObjType](@ref E_LCF_SysStateDirObjType)
///* add for MFC5J3 in 20211119 end*/

///*add for MFC5J3 in 20211119 start*/
#ifndef _E_OBPFOP_ACCOBJMEASSTATETYPE_T_
#define _E_OBPFOP_ACCOBJMEASSTATETYPE_T_ //!< Macro switch for enumeration @ref E_OBPFOP_ACCObjMeasStateType.
/*!
 *	ACC object measurement state
 */
typedef enum
{
	E_ODPFOP_ACC_MS_DELETED	= 0, //!< 0
	E_ODPFOP_ACC_MS_NEW	= 1, //!< 1
	E_ODPFOP_ACC_MS_MEASURED	= 2, //!< 2
	E_ODPFOP_ACC_MS_PREDICTED	= 3, //!< 3
	E_ODPFOP_ACC_MS_INACTIVE	= 4, //!< 4
	E_ODPFOP_ACC_MS_MAXDIFF	= 5 //!< 5
} E_OBPFOP_ACCObjMeasStateType;
#endif // _E_OBPFOP_ACCOBJMEASSTATETYPE_T_
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_DELETED	(E_ODPFOP_ACC_MS_DELETED) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_NEW	(E_ODPFOP_ACC_MS_NEW) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_MEASURED	(E_ODPFOP_ACC_MS_MEASURED) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_PREDICTED	(E_ODPFOP_ACC_MS_PREDICTED) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_INACTIVE	(E_ODPFOP_ACC_MS_INACTIVE) //!< SDA enumeration mapping.
#define E_OBPFOP_ACCObjMeasStateType_E_ODPFOP_ACC_MS_MAXDIFF	(E_ODPFOP_ACC_MS_MAXDIFF) //!< SDA enumeration mapping.
typedef uint8 E_OBPFOP_ACCObjMeasStateType_t; //!< Enumeration base type definition. [\@values: E_OBPFOP_ACCObjMeasStateType](@ref E_OBPFOP_ACCObjMeasStateType)

#ifndef _E_ODPFOP_ACCOBJCLASSTYPE_T_
#define _E_ODPFOP_ACCOBJCLASSTYPE_T_ //!< Macro switch for enumeration @ref E_ODPFOP_ACCObjClassType.
/*!
 *	This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles
 */
typedef enum
{
	E_ODPFOP_ACC_OC_POINT	= 0, //!< 0
	E_ODPFOP_ACC_OC_CAR	= 1, //!< 1
	E_ODPFOP_ACC_OC_TRUCK	= 2, //!< 2
	E_ODPFOP_ACC_OC_PEDESTRIAN	= 3, //!< 3
	E_ODPFOP_ACC_OC_MOTORCYCLE	= 4, //!< 4
	E_ODPFOP_ACC_OC_BICYCLE	= 5, //!< 5
	E_ODPFOP_ACC_OC_WIDE	= 6, //!< 6
	E_ODPFOP_ACC_OC_UNCLASSIFIED	= 7, //!< 7
	E_ODPFOP_ACC_OC_TL	= 8, //!< 8
	E_ODPFOP_ACC_OC_MAXDIFFTYPES	= 9 //!< 9
} E_ODPFOP_ACCObjClassType;
#endif // _E_ODPFOP_ACCOBJCLASSTYPE_T_
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_POINT	(E_ODPFOP_ACC_OC_POINT) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_CAR	(E_ODPFOP_ACC_OC_CAR) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_TRUCK	(E_ODPFOP_ACC_OC_TRUCK) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_PEDESTRIAN	(E_ODPFOP_ACC_OC_PEDESTRIAN) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_MOTORCYCLE	(E_ODPFOP_ACC_OC_MOTORCYCLE) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_BICYCLE	(E_ODPFOP_ACC_OC_BICYCLE) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_WIDE	(E_ODPFOP_ACC_OC_WIDE) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_UNCLASSIFIED	(E_ODPFOP_ACC_OC_UNCLASSIFIED) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_TL	(E_ODPFOP_ACC_OC_TL) //!< SDA enumeration mapping.
#define E_ODPFOP_ACCObjClassType_E_ODPFOP_ACC_OC_MAXDIFFTYPES	(E_ODPFOP_ACC_OC_MAXDIFFTYPES) //!< SDA enumeration mapping.
typedef uint8 E_ODPFOP_ACCObjClassType_t; //!< Enumeration base type definition. [\@values: E_ODPFOP_ACCObjClassType](@ref E_ODPFOP_ACCObjClassType)

#ifndef _E_ODPOOP_GENIBJCITYPE_T_
#define _E_ODPOOP_GENIBJCITYPE_T_ //!< Macro switch for enumeration @ref E_ODPOOP_GenIbjCIType.
/*!
 *	This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles \n
 *	Source: EM_t_GenObjAttributes.eClassification \n
 *	Enum: \n
 *	EM_GEN_OBJECT_CLASS_POINT = 0 \n
 *	EM_GEN_OBJECT_CLASS_CAR = 1 \n
 *	EM_GEN_OBJECT_CLASS_TRUCK = 2 \n
 *	EM_GEN_OBJECT_CLASS_PEDESTRIAN = 3 \n
 *	EM_GEN_OBJECT_CLASS_MOTORCYCLE = 4 \n
 *	EM_GEN_OBJECT_CLASS_BICYCLE = 5 \n
 *	EM_GEN_OBJECT_CLASS_WIDE = 6 \n
 *	EM_GEN_OBJECT_CLASS_UNCLASSIFIED = 7 \n
 *	EM_GEN_OBJECT_CLASS_OTHER_VEHICLE = 8 \n
 *	EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES_LCF = 9
 */
typedef enum
{
	EM_GEN_OBJ_CLASS_POINT	= 0, //!< 0
	EM_GEN_OBJ_CLASS_CAR	= 1, //!< 1
	EM_GEN_OBJ_CLASS_TRUCK	= 2, //!< 2
	EM_GEN_OBJ_CLASS_PEDESTRIAN	= 3, //!< 3
	EM_GEN_OBJ_CLASS_MOTORCYCLE	= 4, //!< 4
	EM_GEN_OBJ_CLASS_BICYCLE	= 5, //!< 5
	EM_GEN_OBJ_CLASS_WIDE	= 6, //!< 6
	EM_GEN_OBJ_CLASS_UNCLASSIFIED	= 7, //!< 7
	EM_GEN_OBJ_CLASS_OTHER_VEHICLE	= 8, //!< 8
	EM_GEN_OBJ_CLASS_MAX_DIFF_TYPES	= 9 //!< 9
} E_ODPOOP_GenIbjCIType;
#endif // _E_ODPOOP_GENIBJCITYPE_T_
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_POINT	(EM_GEN_OBJ_CLASS_POINT) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_CAR	(EM_GEN_OBJ_CLASS_CAR) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_TRUCK	(EM_GEN_OBJ_CLASS_TRUCK) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_PEDESTRIAN	(EM_GEN_OBJ_CLASS_PEDESTRIAN) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_MOTORCYCLE	(EM_GEN_OBJ_CLASS_MOTORCYCLE) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_BICYCLE	(EM_GEN_OBJ_CLASS_BICYCLE) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_WIDE	(EM_GEN_OBJ_CLASS_WIDE) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_UNCLASSIFIED	(EM_GEN_OBJ_CLASS_UNCLASSIFIED) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_OTHER_VEHICLE	(EM_GEN_OBJ_CLASS_OTHER_VEHICLE) //!< SDA enumeration mapping.
#define E_ODPOOP_GenIbjCIType_EM_GEN_OBJ_CLASS_MAX_DIFF_TYPES	(EM_GEN_OBJ_CLASS_MAX_DIFF_TYPES) //!< SDA enumeration mapping.
typedef uint8 E_ODPOOP_GenIbjCIType_t; //!< Enumeration base type definition. [\@values: E_ODPOOP_GenIbjCIType](@ref E_ODPOOP_GenIbjCIType)

#ifndef _E_ODPOOP_OBJSHAPEPTSTTYPE_T_
#define _E_ODPOOP_OBJSHAPEPTSTTYPE_T_ //!< Macro switch for enumeration @ref E_ODPOOP_ObjShapePtStType.
/*!
 *	State of shape point at the same index in the aShapePointCoordinates array. \n
 *	Source: EM_t_GenObjGeometry.EM_t_GenObjShapePointState \n
 *	Enum \n
 *	INVALID: \n
 *	  Shape point does not exist. \n
 *	EDGE_MEASURED: \n
 *	  Shapepoint exists and is measured by the EM. This marks a real corner of the bounding shape of the object. \n
 *	EDGE_ASSUMED: \n
 *	  Shape point exists but is not measured by the EM. The Pos of the shape point is generated out of model knowledge. It is not verified by a measurement. \n
 *	VISIBILITY_EDGE: \n
 *	  Shape point exists but is not a real corner of the object. It is just the boundary up to what an object is visible to the sensor. Typically used when we only see a part of the object and know it.
 */
typedef enum
{
	E_ODPOOP_SHAPE_PT_INVALID	= 0, //!< 0
	E_ODPOOP_SHAPE_PT_EDG_MEASURED	= 1, //!< 1
	E_ODPOOP_SHAPE_PT_EDG_ASSUMED	= 2, //!< 2
	E_ODPOOP_SHAPE_PT_EDG_VISIB_EDG	= 3, //!< 3
	E_ODPOOP_SHAPE_PT_EDG_MAX_DIFF	= 4 //!< 4
} E_ODPOOP_ObjShapePtStType;
#endif // _E_ODPOOP_OBJSHAPEPTSTTYPE_T_
#define E_ODPOOP_ObjShapePtStType_E_ODPOOP_SHAPE_PT_INVALID	(E_ODPOOP_SHAPE_PT_INVALID) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjShapePtStType_E_ODPOOP_SHAPE_PT_EDG_MEASURED	(E_ODPOOP_SHAPE_PT_EDG_MEASURED) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjShapePtStType_E_ODPOOP_SHAPE_PT_EDG_ASSUMED	(E_ODPOOP_SHAPE_PT_EDG_ASSUMED) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjShapePtStType_E_ODPOOP_SHAPE_PT_EDG_VISIB_EDG	(E_ODPOOP_SHAPE_PT_EDG_VISIB_EDG) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjShapePtStType_E_ODPOOP_SHAPE_PT_EDG_MAX_DIFF	(E_ODPOOP_SHAPE_PT_EDG_MAX_DIFF) //!< SDA enumeration mapping.
typedef uint8 E_ODPOOP_ObjShapePtStType_t; //!< Enumeration base type definition. [\@values: E_ODPOOP_ObjShapePtStType](@ref E_ODPOOP_ObjShapePtStType)

#ifndef _E_ODPOOP_OBJSTATMOVTYPE_T_
#define _E_ODPOOP_OBJSTATMOVTYPE_T_ //!< Macro switch for enumeration @ref E_ODPOOP_ObjStatMovType.
/*!
 *	This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity \n
 *	Source: EM_t_GenObjAttributes.eDynamicProperty \n
 *	Enum: \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_MOVING = 0 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY = 1 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING = 2 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT = 3 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT = 4 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN = 5 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_STOPPED = 6 \n
 *	EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES = 7
 */
typedef enum
{
	E_ODPOOP_STMOV_MOVING	= 0, //!< 0
	E_ODPOOP_STMOV_STATIONARY	= 1, //!< 1
	E_ODPOOP_STMOV_ONCOMING	= 2, //!< 2
	E_ODPOOP_STMOV_CROSSING_LEFT	= 3, //!< 3
	E_ODPOOP_STMOV_CROSSING_RIGHT	= 4, //!< 4
	E_ODPOOP_STMOV_UNKNOWN	= 5, //!< 5
	E_ODPOOP_STMOV_STOPPED	= 6, //!< 6
	E_ODPOOP_STMOV_MAX_DIFF_TYPE	= 7 //!< 7
} E_ODPOOP_ObjStatMovType;
#endif // _E_ODPOOP_OBJSTATMOVTYPE_T_
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_MOVING	(E_ODPOOP_STMOV_MOVING) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_STATIONARY	(E_ODPOOP_STMOV_STATIONARY) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_ONCOMING	(E_ODPOOP_STMOV_ONCOMING) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_CROSSING_LEFT	(E_ODPOOP_STMOV_CROSSING_LEFT) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_CROSSING_RIGHT	(E_ODPOOP_STMOV_CROSSING_RIGHT) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_UNKNOWN	(E_ODPOOP_STMOV_UNKNOWN) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_STOPPED	(E_ODPOOP_STMOV_STOPPED) //!< SDA enumeration mapping.
#define E_ODPOOP_ObjStatMovType_E_ODPOOP_STMOV_MAX_DIFF_TYPE	(E_ODPOOP_STMOV_MAX_DIFF_TYPE) //!< SDA enumeration mapping.
typedef uint8 E_ODPOOP_ObjStatMovType_t; //!< Enumeration base type definition. [\@values: E_ODPOOP_ObjStatMovType](@ref E_ODPOOP_ObjStatMovType)

#ifndef _E_ODPR_SHPTSTTYPE_T_
#define _E_ODPR_SHPTSTTYPE_T_ //!< Macro switch for enumeration @ref E_ODPR_ShPtStType.
/*!
 *	State of shape point at the same index in the aShapePointCoordinates array. \n
 *	Source: EM_t_GenObjGeometry.EM_t_GenObjShapePointState \n
 *	Enum \n
 *	INVALID: \n
 *	  Shape point does not exist. \n
 *	EDGE_MEASURED: \n
 *	  Shapepoint exists and is measured by the EM. This marks a real corner of the bounding shape of the object. \n
 *	EDGE_ASSUMED: \n
 *	  Shape point exists but is not measured by the EM. The Pos of the shape point is generated out of model knowledge. It is not verified by a measurement. \n
 *	VISIBILITY_EDGE: \n
 *	  Shape point exists but is not a real corner of the object. It is just the boundary up to what an object is visible to the sensor. Typically used when we only see a part of the object and know it.
 */
typedef enum
{
	E_ODPR_SHPT_INVALID	= 0, //!< 0
	E_ODPR_SH_PT_EDG_MEASURED	= 1, //!< 1
	E_ODPR_SH_PT_EDG_ASSUMED	= 2, //!< 2
	E_ODPR_SH_PT_EDG_VISIB_EDG	= 3, //!< 3
	E_ODPR_SH_PT_EDG_MAX_DIFF	= 4 //!< 4
} E_ODPR_ShPtStType;
#endif // _E_ODPR_SHPTSTTYPE_T_
#define E_ODPR_ShPtStType_E_ODPR_SHPT_INVALID	(E_ODPR_SHPT_INVALID) //!< SDA enumeration mapping.
#define E_ODPR_ShPtStType_E_ODPR_SH_PT_EDG_MEASURED	(E_ODPR_SH_PT_EDG_MEASURED) //!< SDA enumeration mapping.
#define E_ODPR_ShPtStType_E_ODPR_SH_PT_EDG_ASSUMED	(E_ODPR_SH_PT_EDG_ASSUMED) //!< SDA enumeration mapping.
#define E_ODPR_ShPtStType_E_ODPR_SH_PT_EDG_VISIB_EDG	(E_ODPR_SH_PT_EDG_VISIB_EDG) //!< SDA enumeration mapping.
#define E_ODPR_ShPtStType_E_ODPR_SH_PT_EDG_MAX_DIFF	(E_ODPR_SH_PT_EDG_MAX_DIFF) //!< SDA enumeration mapping.
typedef uint8 E_ODPR_ShPtStType_t; //!< Enumeration base type definition. [\@values: E_ODPR_ShPtStType](@ref E_ODPR_ShPtStType)

#ifndef _E_ODPR_STATMEASTYPE_T_
#define _E_ODPR_STATMEASTYPE_T_ //!< Macro switch for enumeration @ref E_ODPR_StatMeasType.
/*!
 *	Indicate the adminstration state of object \n
 *	Source: EM_t_GenObjGenerals.eMaintenanceState \n
 *	Enum: \n
 *	EM_GEN_OBJECT_MT_STATE_DELETED = 0 \n
 *	EM_GEN_OBJECT_MT_STATE_NEW = 1 \n
 *	EM_GEN_OBJECT_MT_STATE_MEASURED = 2 \n
 *	EM_GEN_OBJECT_MT_STATE_PREDICTED = 3 \n
 *	EM_GEN_OBJECT_MT_STATE_INACTIVE = 4 \n
 *	EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES = 5
 */
typedef enum
{
	E_ODPR_MEAS_ST_DELETED	= 0, //!< 0
	E_ODPR_MEAS_ST_NEW	= 1, //!< 1
	E_ODPR_MEAS_ST_MEASURED	= 2, //!< 2
	E_ODPR_MEAS_ST_PREDICTED	= 3, //!< 3
	E_ODPR_MEAS_ST_INACTIVE	= 4, //!< 4
	E_ODPR_MEAS_MAX_DIFF_TYPE	= 5 //!< 5
} E_ODPR_StatMeasType;
#endif // _E_ODPR_STATMEASTYPE_T_
#define E_ODPR_StatMeasType_E_ODPR_MEAS_ST_DELETED	(E_ODPR_MEAS_ST_DELETED) //!< SDA enumeration mapping.
#define E_ODPR_StatMeasType_E_ODPR_MEAS_ST_NEW	(E_ODPR_MEAS_ST_NEW) //!< SDA enumeration mapping.
#define E_ODPR_StatMeasType_E_ODPR_MEAS_ST_MEASURED	(E_ODPR_MEAS_ST_MEASURED) //!< SDA enumeration mapping.
#define E_ODPR_StatMeasType_E_ODPR_MEAS_ST_PREDICTED	(E_ODPR_MEAS_ST_PREDICTED) //!< SDA enumeration mapping.
#define E_ODPR_StatMeasType_E_ODPR_MEAS_ST_INACTIVE	(E_ODPR_MEAS_ST_INACTIVE) //!< SDA enumeration mapping.
#define E_ODPR_StatMeasType_E_ODPR_MEAS_MAX_DIFF_TYPE	(E_ODPR_MEAS_MAX_DIFF_TYPE) //!< SDA enumeration mapping.
typedef uint8 E_ODPR_StatMeasType_t; //!< Enumeration base type definition. [\@values: E_ODPR_StatMeasType](@ref E_ODPR_StatMeasType)
///* add for MFC5J3 in 20211119 end*/

///*MFC5J3 start*//
#ifndef _E_DPRSMI_TRGREASTYPE_T_
#define _E_DPRSMI_TRGREASTYPE_T_ //!< Macro switch for enumeration @ref E_DPRSMI_TrgReasType.
/*!
 *	Trigger Reason of the RDP function.
 */
typedef enum
{
	E_DPRSMI_TRGREAS_NO_RDEDG	= 0, //!< 0
	E_DPRSMI_TRGREAS_RDEDG_ONLY	= 1, //!< 1
	E_DPRSMI_TRGREAS_RDEDG_LN_CONTG	= 2, //!< 2
	E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS	= 3, //!< 3
	E_DPRSMI_TRGREAS_RDEDG_LN_BOTH	= 4 //!< 4
} E_DPRSMI_TrgReasType;
#endif // _E_DPRSMI_TRGREASTYPE_T_
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG	(E_DPRSMI_TRGREAS_NO_RDEDG) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY	(E_DPRSMI_TRGREAS_RDEDG_ONLY) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG	(E_DPRSMI_TRGREAS_RDEDG_LN_CONTG) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS	(E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS) //!< SDA enumeration mapping.
#define E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH	(E_DPRSMI_TRGREAS_RDEDG_LN_BOTH) //!< SDA enumeration mapping.
typedef uint8 E_DPRSMI_TrgReasType_t; //!< Enumeration base type definition. [\@values: E_DPRSMI_TrgReasType](@ref E_DPRSMI_TrgReasType)
///*MFC5J3 end*//


#ifndef _E_VDPR_BRIGHTNSTTYPE_T_
#define _E_VDPR_BRIGHTNSTTYPE_T_ //!< Macro switch for enumeration @ref E_VDPR_BrightnStType.
/*!
 *	LSD Brightness State: \n
 *	 \n
 *	 \n
 *	 \n
 *	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN = 0 \n
 *	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY = 1 \n
 *	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1 = 2 \n
 *	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2 = 3 \n
 *	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3 = 4 \n
 *	LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT = 5
 */
typedef enum
{
	E_LSD_BRIGHT_ST_UNKWN	= 0, //!< 0
	E_LSD_BRIGHT_ST_DAY	= 1, //!< 1
	E_LSD_BRIGHT_ST_TWILIGHT_1	= 2, //!< 2
	E_LSD_BRIGHT_ST_TWILIGHT_2	= 3, //!< 3
	E_LSD_BRIGHT_ST_TWILIGHT_3	= 4, //!< 4
	E_LSD_BRIGHT_ST_NIGHT	= 5 //!< 5
} E_VDPR_BrightnStType;
#endif // _E_VDPR_BRIGHTNSTTYPE_T_
#define E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_UNKWN	(E_LSD_BRIGHT_ST_UNKWN) //!< SDA enumeration mapping.
#define E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_DAY	(E_LSD_BRIGHT_ST_DAY) //!< SDA enumeration mapping.
#define E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_TWILIGHT_1	(E_LSD_BRIGHT_ST_TWILIGHT_1) //!< SDA enumeration mapping.
#define E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_TWILIGHT_2	(E_LSD_BRIGHT_ST_TWILIGHT_2) //!< SDA enumeration mapping.
#define E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_TWILIGHT_3	(E_LSD_BRIGHT_ST_TWILIGHT_3) //!< SDA enumeration mapping.
#define E_VDPR_BrightnStType_E_LSD_BRIGHT_ST_NIGHT	(E_LSD_BRIGHT_ST_NIGHT) //!< SDA enumeration mapping.
typedef uint8 E_VDPR_BrightnStType_t; //!< Enumeration base type definition. [\@values: E_VDPR_BrightnStType](@ref E_VDPR_BrightnStType)

/*-------------------------------------------------*
   D A T A T Y P E   D E F I N I T I O N S
**-------------------------------------------------*/

typedef float32	f32_1pm2_0_0p1_1em8_t;	//!< 32-bit floating point. \@unit: 1/m^2 \n \@min: 0 \n \@max: 0.1
typedef float32	f32_1pm2_0_0p5_1em8_t;	//!< 32-bit floating point. \@unit: 1/m^2 \n \@min: 0 \n \@max: 0.5
typedef float32	f32_1pm2_0_1_1em3_t;	//!< 32-bit floating point. \@unit: 1/m^2 \n \@min: 0 \n \@max: 1
typedef float32	f32_1pm2_m0p001_0p001_1em3_t;	//!< 32-bit floating point. \@unit: 1/m^2 \n \@min: -0.001 \n \@max: 0.001
typedef float32	f32_1pm2_m0p1_0p1_1em8_t;	//!< 32-bit floating point. \@unit: 1/m^2 \n \@min: -0.1 \n \@max: 0.1
typedef float32	f32_1pm2_m1_1_1em3_t;	//!< 32-bit floating point. \@unit: 1/m^2 \n \@min: -1 \n \@max: 1
typedef float32	f32_1pm_0_0p1_1em6_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: 0 \n \@max: 0.1
typedef float32	f32_1pm_0_0p5001_1em8_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: 0 \n \@max: 0.5001
typedef float32	f32_1pm_0_0p5_1em3_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: 0 \n \@max: 0.5
typedef float32	f32_1pm_0_40_1em3_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: 0 \n \@max: 40
typedef float32	f32_1pm_0_50_1em8_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: 0 \n \@max: 50
typedef float32	f32_1pm_m0p02_0p02_1em9_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: -0.02 \n \@max: 0.02
typedef float32	f32_1pm_m0p15_0p15_1em8_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: -0.15 \n \@max: 0.15
typedef float32	f32_1pm_m0p1_0p1_1em3_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: -0.1 \n \@max: 0.1
typedef float32	f32_1pm_m1_1_1em3_t;	//!< 32-bit floating point. \@unit: 1/m \n \@min: -1 \n \@max: 1
typedef float32	f32_1pms2_0_0p1_1em7_t;	//!< 32-bit floating point. \@unit: 1/ms^2 \n \@min: 0 \n \@max: 0.1
typedef float32	f32_1pms_0_100_1em3_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: 0 \n \@max: 100
typedef float32	f32_1pms_0_10_1em6_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: 0 \n \@max: 10
typedef float32	f32_1pms_0_5_1em7_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: 0 \n \@max: 5
typedef float32	f32_1pms_m0p1_0p1_1em8_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: -0.1 \n \@max: 0.1
typedef float32	f32_1pms_m1000_1000_1em3_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: -1000 \n \@max: 1000
typedef float32	f32_1pms_m1_1_1em3_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: -1 \n \@max: 1
typedef float32	f32_1pms_m2_2_1em8_t;	//!< 32-bit floating point. \@unit: 1/ms \n \@min: -2 \n \@max: 2
typedef float32	f32_N_m100000_100000_1em8_t;	//!< 32-bit floating point. \@unit: N \n \@min: -100000 \n \@max: 100000
typedef float32	f32_Nm_0_10_1em3_t;	//!< 32-bit floating point. \@unit: Nm \n \@min: 0 \n \@max: 10
typedef float32	f32_Nm_m100_100_1em3_t;	//!< 32-bit floating point. \@unit: Nm \n \@min: -100 \n \@max: 100
typedef float32	f32_NoUnit_0_100000_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 100000
typedef float32	f32_NoUnit_0_100_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 100
typedef float32	f32_NoUnit_0_10_1em6_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 10
typedef float32	f32_NoUnit_0_1_1em6_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 1
typedef float32	f32_NoUnit_0_20_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 20
typedef float32	f32_NoUnit_0_2_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 2
typedef float32	f32_NoUnit_0_5_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 5
typedef float32	f32_NoUnit_0_65535_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0 \n \@max: 65535
typedef float32	f32_NoUnit_0p0001_1_1em6_t;	//!< 32-bit floating point. \@unit: - \n \@min: 0.0001 \n \@max: 1
typedef float32	f32_NoUnit_1Em20_1Em05_1em9_t;	//!< 32-bit floating point. \@unit: - \n \@min: 1E-20 \n \@max: 1E-05
typedef float32	f32_NoUnit_1_100_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: 1 \n \@max: 100
typedef float32	f32_NoUnit_m0p1_0p1_1em8_t;	//!< 32-bit floating point. \@unit: - \n \@min: -0.1 \n \@max: 0.1
typedef float32	f32_NoUnit_m10000000_10000000_1em9_t;	//!< 32-bit floating point. \@unit: - \n \@min: -10000000 \n \@max: 10000000
typedef float32	f32_NoUnit_m100_100_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: -100 \n \@max: 100
typedef float32	f32_NoUnit_m10_10_1em3_t;	//!< 32-bit floating point. \@unit: - \n \@min: -10 \n \@max: 10
typedef float32	f32_Npr_0_500000_1em4_t;	//!< 32-bit floating point. \@unit: N/rad \n \@min: 0 \n \@max: 500000
typedef float32	f32_Perc_0_100_1em3_t;	//!< 32-bit floating point. \@unit: % \n \@min: 0 \n \@max: 100
typedef float32	f32_Pers_0_10000_1em3_t;	//!< 32-bit floating point. \@unit: 1/s \n \@min: 0 \n \@max: 10000
typedef float32	f32_Pers_0_1000_1em3_t;	//!< 32-bit floating point. \@unit: 1/s \n \@min: 0 \n \@max: 1000
typedef float32	f32_Pers_1_10000_1em3_t;	//!< 32-bit floating point. \@unit: 1/s \n \@min: 1 \n \@max: 10000
typedef float32	f32_Pers_m1000_0_1em4_t;	//!< 32-bit floating point. \@unit: 1/s \n \@min: -1000 \n \@max: 0
typedef float32	f32_deg_0_180_1em6_t;	//!< 32-bit floating point. \@unit: � \n \@min: 0 \n \@max: 180
typedef float32	f32_deg_m50_50_1em8_t;	//!< 32-bit floating point. \@unit: � \n \@min: -50 \n \@max: 50
typedef float32	f32_deg_m720_720_1em3_t;	//!< 32-bit floating point. \@unit: � \n \@min: -720 \n \@max: 720
typedef float32	f32_deg_m90_90_1em8_t;	//!< 32-bit floating point. \@unit: � \n \@min: -90 \n \@max: 90
typedef float32	f32_degm_0_5000_1em2_t;	//!< 32-bit floating point. \@unit: degm \n \@min: 0 \n \@max: 5000
typedef float32	f32_degps_0_360_1em2_t;	//!< 32-bit floating point. \@unit: �/s \n \@min: 0 \n \@max: 360
typedef float32	f32_degps_m360_360_1em3_t;	//!< 32-bit floating point. \@unit: �/s \n \@min: -360 \n \@max: 360
typedef float32	f32_kgm2_1_100000_1em2_t;	//!< 32-bit floating point. \@unit: kgm^2 \n \@min: 1 \n \@max: 100000
typedef float32	f32_kph_0_250_1em3_t;	//!< 32-bit floating point. \@unit: km/h \n \@min: 0 \n \@max: 250
typedef float32	f32_kph_0_300_1em3_t;	//!< 32-bit floating point. \@unit: km/h \n \@min: 0 \n \@max: 300
typedef float32	f32_kph_m72_360_1em3_t;	//!< 32-bit floating point. \@unit: km/h \n \@min: -72 \n \@max: 360
typedef float32	f32_m_0_1000_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 1000
typedef float32	f32_m_0_100_1em5_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 100
typedef float32	f32_m_0_10_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 10
typedef float32	f32_m_0_150_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 150
typedef float32	f32_m_0_1_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 1
typedef float32	f32_m_0_200_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 200
typedef float32	f32_m_0_300_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 300
typedef float32	f32_m_0_3p4E38_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 3.4E+38
typedef float32	f32_m_0_40_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 40
typedef float32	f32_m_0_5000_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 5000
typedef float32	f32_m_0_5_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 0 \n \@max: 5
typedef float32	f32_m_1_100_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: 1 \n \@max: 100
typedef float32	f32_m_m1000_1000_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: -1000 \n \@max: 1000
typedef float32	f32_m_m100_100_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: -100 \n \@max: 100
typedef float32	f32_m_m10_10_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: -10 \n \@max: 10
typedef float32	f32_m_m15_15_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: -15 \n \@max: 15
typedef float32	f32_m_m300_300_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: -300 \n \@max: 300
typedef float32	f32_m_m30_30_1em3_t;	//!< 32-bit floating point. \@unit: m \n \@min: -30 \n \@max: 30
typedef float32	f32_mps2_0_20_1em3_t;	//!< 32-bit floating point. \@unit: m/s^2 \n \@min: 0 \n \@max: 20
typedef float32	f32_mps2_0_50_1em3_t;	//!< 32-bit floating point. \@unit: m/s^2 \n \@min: 0 \n \@max: 50
typedef float32	f32_mps2_m20_20_1em3_t;	//!< 32-bit floating point. \@unit: m/s^2 \n \@min: -20 \n \@max: 20
typedef float32	f32_mps3_0_50_1em3_t;	//!< 32-bit floating point. \@unit: m/s^3 \n \@min: 0 \n \@max: 50
typedef float32	f32_mps3_m10_10_1em3_t;	//!< 32-bit floating point. \@unit: m/s^3 \n \@min: -10 \n \@max: 10
typedef float32	f32_mps3_m1_1_1em3_t;	//!< 32-bit floating point. \@unit: m/s^3 \n \@min: -1 \n \@max: 1
typedef float32	f32_mps3_m20_20_1em3_t;	//!< 32-bit floating point. \@unit: m/s^3 \n \@min: -20 \n \@max: 20
typedef float32	f32_mps_0_100_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: 0 \n \@max: 100
typedef float32	f32_mps_0_250_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: 0 \n \@max: 250
typedef float32	f32_mps_0p001_20_1em5_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: 0.001 \n \@max: 20
typedef float32	f32_mps_1_100_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: 1 \n \@max: 100
typedef float32	f32_mps_m100_100_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: -100 \n \@max: 100
typedef float32	f32_mps_m150_150_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: -150 \n \@max: 150
typedef float32	f32_mps_m20_100_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: -20 \n \@max: 100
typedef float32	f32_mps_m20_150_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: -20 \n \@max: 150
typedef float32	f32_mps_m20_20_1em3_t;	//!< 32-bit floating point. \@unit: m/s \n \@min: -20 \n \@max: 20
typedef float32	f32_rad_0_0p78539816_1em8_t;	//!< 32-bit floating point. \@unit: rad \n \@min: 0 \n \@max: 0.78539816
typedef float32	f32_rad_0_12_1em4_t;	//!< 32-bit floating point. \@unit: rad \n \@min: 0 \n \@max: 12
typedef float32	f32_rad_0_1_1em6_t;	//!< 32-bit floating point. \@unit: rad \n \@min: 0 \n \@max: 1
typedef float32	f32_rad_0_3p14_1em3_t;	//!< 32-bit floating point. \@unit: rad \n \@min: 0 \n \@max: 3.14
typedef float32	f32_rad_0_5_1em3_t;	//!< 32-bit floating point. \@unit: rad \n \@min: 0 \n \@max: 5
typedef float32	f32_rad_0_6p28_1em3_t;	//!< 32-bit floating point. \@unit: rad \n \@min: 0 \n \@max: 6.28
typedef float32	f32_rad_m0p78539816_0p78539816_1em8_t;	//!< 32-bit floating point. \@unit: rad \n \@min: -0.78539816 \n \@max: 0.78539816
typedef float32	f32_rad_m0p7854_0p7854_1em3_t;	//!< 32-bit floating point. \@unit: rad \n \@min: -0.7854 \n \@max: 0.7854
typedef float32	f32_rad_m10_10_1em3_t;	//!< 32-bit floating point. \@unit: rad \n \@min: -10 \n \@max: 10
typedef float32	f32_rad_m12p57_12p57_1em4_t;	//!< 32-bit floating point. \@unit: rad \n \@min: -12.57 \n \@max: 12.57
typedef float32	f32_rad_m6_6_1em3_t;	//!< 32-bit floating point. \@unit: rad \n \@min: -6 \n \@max: 6
typedef float32	f32_rad_m6p28_6p28_1em4_t;	//!< 32-bit floating point. \@unit: rad \n \@min: -6.28 \n \@max: 6.28
typedef float32	f32_radpm_0_100_1em4_t;	//!< 32-bit floating point. \@unit: rad/m \n \@min: 0 \n \@max: 100
typedef float32	f32_radpm_0_2_1em3_t;	//!< 32-bit floating point. \@unit: rad/m \n \@min: 0 \n \@max: 2
typedef float32	f32_radps_0_100000_1em3_t;	//!< 32-bit floating point. \@unit: rad/s \n \@min: 0 \n \@max: 100000
typedef float32	f32_radps_0_1_1em3_t;	//!< 32-bit floating point. \@unit: rad/s \n \@min: 0 \n \@max: 1
typedef float32	f32_radps_0_1p5_1em6_t;	//!< 32-bit floating point. \@unit: rad/s \n \@min: 0 \n \@max: 1.5
typedef float32	f32_radps_0_50_1em3_t;	//!< 32-bit floating point. \@unit: rad/s \n \@min: 0 \n \@max: 50
typedef float32	f32_radps_m1_1_1em3_t;	//!< 32-bit floating point. \@unit: rad/s \n \@min: -1 \n \@max: 1
typedef float32	f32_radps_m1p5708_1p5708_1em3_t;	//!< 32-bit floating point. \@unit: rad/s \n \@min: -1.5708 \n \@max: 1.5708
typedef float32	f32_radpsm_0_100_1em4_t;	//!< 32-bit floating point. \@unit: rad/sm \n \@min: 0 \n \@max: 100
typedef float32	f32_radspm_0_100_1em4_t;	//!< 32-bit floating point. \@unit: rads/m \n \@min: 0 \n \@max: 100
typedef float32	f32_s_0_100000_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 100000
typedef float32	f32_s_0_100_1em4_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 100
typedef float32	f32_s_0_1_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 1
typedef float32	f32_s_0_300_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 300
typedef float32	f32_s_0_4295_1em6_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 4295
typedef float32	f32_s_0_5_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 5
typedef float32	f32_s_0_600_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 600
typedef float32	f32_s_0_60_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0 \n \@max: 60
typedef float32	f32_s_0p001_0p03_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.001 \n \@max: 0.03
typedef float32	f32_s_0p001_0p1_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.001 \n \@max: 0.1
typedef float32	f32_s_0p001_100_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.001 \n \@max: 100
typedef float32	f32_s_0p025_10_1em4_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.025 \n \@max: 10
typedef float32	f32_s_0p04_10_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.04 \n \@max: 10
typedef float32	f32_s_0p06_10_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.06 \n \@max: 10
typedef float32	f32_s_0p1_20_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: 0.1 \n \@max: 20
typedef float32	f32_s_m60_60_1em3_t;	//!< 32-bit floating point. \@unit: s \n \@min: -60 \n \@max: 60
typedef uint32	u32_NoUnit_0_4294967295_0_1_t;	//!< Unsigned 32-bit integer. \@unit: - \n \@min: 0 \n \@max: 4294967295
typedef uint32	u32_us_0_4294967295_0_1_t;	//!< Unsigned 32-bit integer. \@unit: us \n \@min: 0 \n \@max: 4294967295
typedef uint16	u16_NoUnit_0_65535_0_1_t;	//!< Unsigned 16-bit integer. \@unit: - \n \@min: 0 \n \@max: 65535
typedef uint16	u16_kg_0_10000_0_1_t;	//!< Unsigned 16-bit integer. \@unit: kg \n \@min: 0 \n \@max: 10000
typedef sint8	s8_NoUnit_m1_10_0_1_t;	//!< Signed 8-bit integer. \@unit: - \n \@min: -1 \n \@max: 10
typedef sint8	s8_Perc_m128_127_0_1_t;	//!< Signed 8-bit integer. \@unit: % \n \@min: -128 \n \@max: 127
typedef uint8	u8_NoUnit_0_100_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 100
typedef uint8	u8_NoUnit_0_10_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 10
typedef uint8	u8_NoUnit_0_1_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 1
typedef uint8	u8_NoUnit_0_20_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 20
typedef uint8	u8_NoUnit_0_255_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 255
typedef uint8	u8_NoUnit_0_2_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 2
typedef uint8	u8_NoUnit_0_5_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 5
typedef uint8	u8_NoUnit_0_7_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 0 \n \@max: 7
typedef uint8	u8_NoUnit_1_100_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 1 \n \@max: 100
typedef uint8	u8_NoUnit_1_3_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 1 \n \@max: 3
typedef uint8	u8_NoUnit_1_4_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 1 \n \@max: 4
typedef uint8	u8_NoUnit_1_7_0_1_t;	//!< Unsigned 8-bit integer. \@unit: - \n \@min: 1 \n \@max: 7
typedef uint8	u8_Perc_0_100_0_1_t;	//!< Unsigned 8-bit integer. \@unit: % \n \@min: 0 \n \@max: 100
typedef uint8	u8_boolean_t;	//!< Boolean data type. \@name: Boolean \n \@values: FALSE, TRUE \n \@links: @ref FALSE, @ref TRUE
typedef uint32	u32_Pa_0_1500000_0_1_t;	//!< Unsigned 32-bit integer. \@unit: Pa \n \@min: 0 \n \@max: 1500000

#ifdef __cplusplus
}
#endif

#endif /* LCF_TYPE_H_ */
