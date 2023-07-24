/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_ext.h

DESCRIPTION:               External header file for HP function in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.32 $

LEGACY VERSION:            Revision: 1.12

**************************************************************************** */

#ifndef HP_EXT_H_INCLUDED
#define HP_EXT_H_INCLUDED


/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   hp HP (Headway Planner)
@ingroup    lohp_base_lohp
@brief      Module for HP functionalities
@description
In this context HP in LoHP is responsible for:\n
   - The calculation of headway distance to next object as desired by the driver.\n
   - The calculation of control distance and corresponding acceleration output for six objects.\n
   - Arbitration of a single relevant object and acceleration output based on traffic situation and object criticality.\n
   - Implementation of features like overtake support and overtake prevention.\n
   - The calculation of driver alert.\n
   - The estimation of traffic situation.
 */

/** 
@defgroup   hp_ext Hp_ext_h
@ingroup    hp
@brief      HP external header file
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lohp_ext.h"
#include "hp_cfg.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/
#define Acc_max_number_ooi  (6u)
/* Definition of the required MTS alignment, added to unions to assure that
the alignment requirements are met */
#define MTS_ALIGNMENT_DUMMY     uint32 MTS_DUMMY; // PRQA S 3412
/* date: 2015-09-16, reviewer: Chirag, reason: Not safety critical */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef enum {
  OVERTAKE_OFF,               /*!< Overtake maneouvre off */
  OVERTAKE_LEFT_ON,           /*!< Overtake maneouvre towards left on */
  OVERTAKE_RIGHT_ON           /*!< Overtake maneouvre towards right on */
} OTIntention_t_e;

typedef enum {
  INDICATOR_OFF,               /*!< Driver turn indicator off */
  INDICATOR_LEFT_ON,           /*!< Driver turn indicator towards left on */
  INDICATOR_RIGHT_ON           /*!< Driver turn indicator towards right on */
} TurnIndicator_t_e;

typedef enum {
  OVERTAKE_IDLE,              /*!< Idle state */
  OVERTAKE_RUNNING,           /*!< Overtake maneouvre running */
  OVERTAKE_EXTENDED,          /*!< Overtake maneouvre extended for lanechange/passing by state */
  OVERTAKE_PASSBY,            /*!< Overtake maneouvre in passing-by state */
  OVERTAKE_DONE               /*!< Overtake maneouvre completed. Waiting for reset */
} OTState_t_e;

typedef enum {
  LANECHANGE_NO,              /*!< No lane change undertaken */
  LANECHANGE_ON               /*!< Lane change confirmed and underway */
} LCPhase_t_e;

typedef enum {
  LANECHANGE_NONE,   /*!< No lane change */
  LANECHANGE_LEFT,   /*!< Lane change left */
  LANECHANGE_RIGHT   /*!< Lane change right */
} LC_Direction_t_e;

typedef struct acc_driver_controls_t {
  percentage_t P_LANE_CHANGE_LEFT;        /*!< probability of a lane change into left direction*/
  percentage_t P_LANE_CHANGE_RIGHT;       /*!< probability of a lane change into right direction*/
  percentage_t HEADWAY_SETTING;           /*!< actual headway setting in percent*/
  OTIntention_t_e e_OTIntention;          /*!< Input to overtake feature activation*/
  LCPhase_t_e e_LCPhase;                  /*!< Indication if ego lane change is undertaken */
  TurnIndicator_t_e e_TurnIndicator;      /*!< Driver turn indicator signal */
} acc_driver_controls_t;                  /*! @brief HMI Input */

typedef struct acc_input_status_t {
  ubit8_t ACC_ON                 :1; /*!< acc is active (no override) */
  ubit8_t ACC_NOT_OFF            :1; /*!< acc is activated (override included) */
  ubit8_t INHIBIT                :1; /*!< acc cannot be engaged*/
  ubit8_t OBJECT_EFFECTIVE       :1; /*!< the object is effective for control*/
  ubit8_t CC_DECEL_LIM_OVERRIDE  :1; /*!< the host vehicle uses limited deceleration due to an previously occurred override situation*/
  ubit8_t OBJECT_LOST            :1; /*!< the object got lost due to a sensor limitation*/
  ubit8_t ACC_CONTROL_TO_FIRST_OBJECT :1; /*!< the acc will ever control to the first object (although it could be stationary)*/
  ubit8_t                        :1;
} acc_input_status_t; /*! @brief Status bits for the ACC algorithm */

typedef struct acc_lodm_status_t {
  ubit8_t STANDSTILL            : 1;  /*!< Ego vehicle in stand still */
  ubit8_t OVERRIDE_ACCEL        : 1;  /*!< Driver override of accelerator pedal */
} acc_lodm_status_t;  /*! @brief Vehicle status bits for ACC */

typedef struct acc_input_data_t {
  acc_input_status_t    INPUT_STATUS;       /*!< Input status bits for ACC */
  acc_driver_controls_t DRIVER_CONTROLS;    /*!< Inputs from driver for ACC */
  acc_lodm_status_t     LODM_STAT;          /*!< Vehicle status bits for ACC */
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
  boolean               OT_PREVENTION[Acc_max_number_ooi];  /*!< overtake prevention activate request from slate for ooi objects*/
#endif
  velocity_t            LONG_VELOCITY;      /*!< longitudinal velocity of the host vehicle */
  acceleration_t        LONG_ACCELERATION;  /*!< longitudinal acceleration of the host vehicle */
  acceleration_t        CC_ACCEL_LIMIT;     /*!< maximum allowed acceleration for object reaction */
  acceleration_t        CC_DECEL_LIMIT;     /*!< maximum allowed deceleration for object reaction */
  distance_t            VISIBILITY_RANGE;   /*!< maximum longitudinal displacement at which objects can be reported*/
#if ( HP_CFG_PARALLEL_LANE_CHANGE )
  LC_Direction_t_e      OOI_LC_DIRECTION[Acc_max_number_ooi];   /*!< Lanechange direction of OOI's */
#endif
#if (HP_CFG_PRE_LC_OBJ_LA)
  eAssociatedLane_t FuncLaneAss_AT_PRE_LC[OOI_NUMBER_OF_OOI];
#endif /* HP_CFG_PRE_LC_OBJ_LA */
} acc_input_data_t; /*! @brief ACC input interface: vehicle related data */

typedef struct acc_alert_data_t {
  distance_t        ESTIM_DISTANCE;
  velocity_t        ESTIM_REL_SPEED;
  factor_t          ALERT_THRES_FACTOR;
  velocity_t        ESTIM_HOST_SPEED;
  distance_t        ALERT_DISTANCE;
  times_t           ALERT_SUPRESS_TIME;
} acc_alert_data_t; /*! @brief Result of the ACC alert algorithm */

typedef struct acc_decel_lim_override_t {
  ubit8_t  CC_LIMITER_ACTIVE              :1;
  ubit8_t  ACC_LIMITER_ACTIVE             :1;
  ubit8_t  ACC_LIMITER_ACTIVE_LAST_CYCLE  :1;
  ubit8_t                                 :5;
} acc_decel_lim_override_t; /*! @brief Internal information about decel limiter for ACC*/

typedef struct acc_driver_intention_t {
  uint8                     LANE_CHANGE_LEFT_PROBABILITY;   /*!< probability of a lane change to left direction*/
  uint8                     LANE_CHANGE_RIGHT_PROBABILITY;  /*!< probability of a lane change to right direction*/
  acc_decel_lim_override_t  DECEL_LIM_OVERRIDE;             /*!< information if decel limiter after override is active*/
  acceleration_t            DECEL_LIM_OVERRIDE_ACCEL;       /*!< max allowed acceleration after override*/
  switch_t                  ACC_ENGAGED;                   /*!< acc is engaged*/
  ObjNumber_t               OBJECT_NR_TO_CONTROL_TO;        /*!< object nr that is used to control regardless if it is stationary or not!*/
} acc_driver_intention_t; /*! @brief driver intention for ACC */

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
typedef struct acc_overtake_data_t {
  OTState_t_e               e_OTState;                /*!< Overtake support feature transition state */
  OTIntention_t_e           e_OTDirection;            /*!< Overtake direction status */
  times_t                   Timer_TGR;                /*!< Timer for running of time gap reduction phase */
  times_t                   Timer_BP;                 /*!< Timer for running of bypass phase */
  ObjNumber_t               OOI_OTS_ObjId;            /*!< Object Id of OOI-0 at start of overtake support maneouvre */
  factor_t                  s_LCModFactor;            /*!< Overtake maneuver alert modification factor */
  boolean                   b_Overtake_Support_On;    /*!< Boolean indicating that overtake support is active */
  boolean                   b_RampObjReqDist;         /*!< Boolean to ramp up object distance after feature cancel */
} acc_overtake_data_t;  /*! @brief ACC overtake support */
#endif

typedef struct acc_status_t { 
  acc_driver_intention_t  ACC_DRIVER_INTENTION;                     /*!< driver intention*/
  acc_object_t            ACC_CONTROL_OBJECT;                       /*!< control object for ACC*/
  acc_alert_data_t        ACC_ALERT_DATA;                           /*!< alert data*/
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
  acc_overtake_data_t     ACC_OVERTAKE_DATA;                        /*!< overtake support data*/
  boolean                 APPROACH_SUPPRESSION[Acc_max_number_ooi]; /*!< approach decel suppression flag for ooi objects*/
#endif
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
  boolean                 OT_PREVENTION[Acc_max_number_ooi];        /*!< overtake prevention active flag for ooi objects*/
  distance_t              REQ_DIST_OT_PREVENTION;                   /*!< current requested distance for overtake prevention feature */
#endif
  distance_t              REQUESTED_DISTANCE_ACT;                   /*!< current requested distance */
  distance_t              REQUESTED_DISTANCE_PREDICTED;             /*!< current predicted requested distance*/
  times_t                 TIMER_LIMIT_ACCEL_OBJ_LOST;               /*!< timer to limit acceleration output after object is lost*/
} acc_status_t; /*! @brief handles all internal status information of acc component*/

/* Combined struct with debug signals for HP */
typedef struct {
#if ( FCT_CFG_ACC_HEADWAY_PLANNER || FCT_CFG_FCA || FCT_CFG_DM )
  acc_input_data_t  ACC_INPUT_DATA;                       /*!< The real ACC input data */
  acc_object_t      ACC_OBJECT_LIST[Acc_max_number_ooi];  /*!< The ACC object of interest data */
  acc_object_t      ACC_ALERT_OBJECT;                     /*!< The real ACC alert object data */
  acc_status_t      ACC_STATUS;                           /*!< The real ACC status information data */
#endif
#if ( FCT_CFG_FCA )
  fca_input_data_t  FCA_INPUT_DATA;                       /*!< The forward collision alert function input data */
  fca_output_data_t FCA_OUTPUT_DATA;                      /*!< The real forward collision alert data */
#endif
#if ( FCT_CFG_DM )
  dm_input_data_t   DM_INPUT_DATA;                        /*!< The real Distance Monitoring input data */
  dm_status_t       DM_STATUS;                            /*!< Distance monitoring status information */
  dm_output_data_t  DM_OUTPUT_DATA;                       /*!< The real data itself (not necessarily aligned */
#endif
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
  FuzzyDebugData_t  FUZZY_DATA_CTL_OBJ;                   /*!< Fuzzy Controller Data used for debugging */
#endif
} hp_static_mem_t;

typedef union {
  hp_static_mem_t HP_STATIC_MEMORY;
  MTS_ALIGNMENT_DUMMY                                     /*!< Needed to align the data to the MTS requirement */
} hp_static_mem_u_t;


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
extern FuzzyDebugData_t FuzzyDebugDataControlObject;
extern FuzzyDebugData_t FuzzyDebugData;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

extern void HP_v_Init(acc_object_t *alert_object, acc_status_t *acc_status, acc_input_data_t * acc_input_data_ptr, acc_object_t object_list[Acc_max_number_ooi]);
DLLEXPORT extern void HP_v_Process(const times_t cycle_time, 
                                         const acc_input_data_t* input, 
                                         acc_object_t object_list[Acc_max_number_ooi], 
                                         acc_output_data_t* output, 
                                         acc_object_t* alert_object, 
                                         acc_object_t* display_object, 
                                         acc_status_t *acc_status);

extern void HP_v_DeleteObject(acc_object_t * const object);
extern void HP_v_OutInit(acc_object_t* pAccDisplayObj, acc_output_data_t *acc_output_data);
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
extern void HP_v_CopyObjectUsage(const FCTSenAccOOI_t* pFCTAccOOIData, const ObjNumber_t ACC_LONG_OBJECT_ID, const FCTObjUsageState_t eUsageState, LOHP_ObjUsageState_t* pLOHPUsageState);
#endif

extern void HP_v_PreProcess(const times_t cycle_time,
                            const FctVeh2SenInfo_t * pFctVehLongOut,
                            const VehDyn_t * pVehDyn,
                            const SLATE_HC_Data_t     * pSLATEData,
                            const FCTSenAccOOI_t* pFCTAccOOIData,
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
                            const FCTCustomInput_t  * pCustomInput,
#endif
                            acc_object_t object_list[Acc_max_number_ooi],
                            acc_input_data_t * const acc_input_data_ptr,
                            acc_output_data_t         * pAccOutput);

#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */

#endif /* HP_EXT_H_INCLUDED */
