/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_brakefunction.h

DESCRIPTION:               header of the head generic brake function output

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:14:48CEST $

VERSION:                   $Revision: 1.3.1.9 $

LEGACY VERSION:            1.21

**************************************************************************** */
/**
@ingroup head_out_brakefunction
@{ **/
#ifndef HEAD_OUT_BRAKEFUNCTION_H_INCLUDED
#define HEAD_OUT_BRAKEFUNCTION_H_INCLUDED

/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*Brake SM States*/

/*! @brief        Brake is waiting to get active  */
#define BrakeState_ONCOMING   ((BrakeState_t) eBrakeState_ONCOMING)

/*Brake Events*/

/*! @brief       Break Event : Oncoming Break Event Activated */
#define BRAKE_EVENT_ONCOMING_ACTIVATED  ((BrakeEvent_t) eBrake_Event_OncomingBrake_Activated)
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
******************************************************************************/

/*****************************************************************************
  TYPEDEFS ENUM BrakeModule_t
*****************************************************************************/
/*! @brief Brake Modules 
    @general Level of brake depends on the object criticality
    @conseq -
    @attention -*/
typedef enum
{
  Veh_AutoBrkVehLevel1,       /*!< First  level auto brake for FctChan_Vehicle crossing       */
  Veh_AutoBrkVehLevel2,       /*!< Second level auto brake for FctChan_Vehicle crossing       */
  Veh_AutoBrkVehLevel3,       /*!< Third  level auto brake for FctChan_Vehicle crossing       */
  Veh_AutoBrkPedLevel1,       /*!< First  level auto brake for FctChan_Pedestrian crossing    */
  Veh_AutoBrkPedLevel2,       /*!< Second level auto brake for FctChan_Pedestrian crossing    */
  Veh_AutoBrkPedLevel3,       /*!< Third  level auto brake for FctChan_Pedestrian crossing    */
  Veh_AutoBrkLongVruLevel1,   /*!< First  level auto brake for vulnerable Pedestrian crossing */
  Veh_AutoBrkLongVruLevel2,   /*!< Second level auto brake for Vulnerable Pedestrian crossing */
  #if (HEAD_USE_CROSSING_BRK)
  Veh_AutoCrossBrk,           /*!< Brake level for crossing                         */
  #endif
  #if HEAD_CFG_TURN_ASSIST
  Veh_AutoOncomingBrk,        /*!<Vehicle auto break activated for on coming object */
  #endif
  Veh_AutoBrkModule_Num       /*!< Maximum no of brake level depends on object      */
} BrakeModule_t;

/*****************************************************************************
  TYPEDEFS ENUM BrakeState_t
*****************************************************************************/
/*! @brief Brake Modules state  
    
    @general Brake Modules state 
    
    @conseq -
    
    @attention -
    */
/*! @brief Brake States */
typedef enum
{
  eBrakeState_PASSIVE,          /*!< prebrake is waiting to get active*/
  eBrakeState_VEH_LEVEL_1,      /*!< prebrake vehicle is active - level 1*/
  eBrakeState_VEH_LEVEL_2,      /*!< prebrake vehicle is active - level 2*/
  eBrakeState_VEH_LEVEL_3,      /*!< prebrake vehicle is active - level 3*/
  eBrakeState_PED_LEVEL_1,      /*!< prebrake pedestrian is active - level 1*/
  eBrakeState_PED_LEVEL_2,      /*!< prebrake pedestrian is active - level 2*/
  eBrakeState_PED_LEVEL_3,      /*!< prebrake pedestrian is active - level 3*/
  eBrakeState_LongVru_LEVEL_1,  /*!< prebrake longitudinal VRU is active - level 1*/
  eBrakeState_LongVru_LEVEL_2,  /*!< prebrake longitudinal VRU is active - level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  eBrakeState_CROSSBRK,         /*!< prebrake is active - Cross Break */
  #endif
  eBrakeState_RAMP,             /*!< prebrake is ramping out*/
  #if HEAD_CFG_TURN_ASSIST
  eBrakeState_ONCOMING,         /*!< prebrake is waiting to get active - Oncoming */
  #endif
  eBrakeState_Num               /*!< Maximum no of state */
} BrakeState_t;

/*****************************************************************************
  TYPEDEFS ENUM BrakeEvent_t
*****************************************************************************/
/*! @brief Break Events 
    
    @general Brake Modules state 
    
    @conseq [None]

    @attention [None]
    */
typedef enum
{
  eBrake_Event_No_New_Event,              /*!< No new Brake Event*/
  eBrake_Event_Veh_Level1_Activated,      /*!< prebrake vehicle is active - level 1*/
  eBrake_Event_Veh_Level2_Activated,      /*!< prebrake vehicle is active - level 2*/
  eBrake_Event_Veh_Level3_Activated,      /*!< prebrake vehicle is active - level 3*/
  eBrake_Event_Ped_Level1_Activated,      /*!< prebrake pedestrian is active - level 1*/
  eBrake_Event_Ped_Level2_Activated,      /*!< prebrake pedestrain is active - level 2*/
  eBrake_Event_Ped_Level3_Activated,      /*!< prebrake ped is active - level 3*/
  eBrake_Event_LongVru_Level1_Activated,  /*!< prebrake longitudinal VRU is active - level 1*/
  eBrake_Event_LongVru_Level2_Activated,  /*!< prebrake longitudinal VRU is active - level 2*/
  #if (HEAD_USE_CROSSING_BRK)
  eBrake_Event_CrossBrk_Activated,        /*!< prebrake is active - CrossBrk*/
  #endif
  #if (HEAD_USE_RAMP_BRK)
  eBrake_Event_Rampout_Activated,         /*!< prebrake is not active*/
  #endif
  eBrake_Event_Passive_Activated,         /*!< prebrake is waiting to get active*/
  #if HEAD_CFG_TURN_ASSIST
  eBrake_Event_OncomingBrake_Activated,   /*!< prebrake is active - Oncoming */
  #endif
  eBrake_Event_Num                        /*!< Maximum no of event number */
} BrakeEvent_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleOutputBrakeFunction_t
    **************************************************************** */
/*! @brief Data type for Output of Brake Function 
    @general Head Custom Coding Info
    @conseq [None]
    @attention [None] */
typedef struct 
{
  HEADModuleCustomOutput_ft *fpCustomOutput; /*!< Output @unit:m/s^2*/
  
  /*internal state variables*/
  float32      *pfPreBrakeDeceleration;      /*!< Prebreak Deceleration @unit:m/s^2*/
  boolean      *pbPreBrakeActive;            /*!< Prebreak Active @unit:bool*/
  BrakeState_t *pePreBrakeState;             /*!< Prebreak state @unit:[active1, active2, active3, ramp, off, passive]*/
  float32      *pfActiveTimeVeh1;            /*!< counts the time function is in active1 state @unit:s*/
  float32      *pfActiveTimeVeh2;            /*!< counts the time function is in active2 state @unit:s*/
  float32      *pfActiveTimeVeh3;            /*!< counts the time function is in active3 state @unit:s*/
  float32      *pfActiveTimePed1;            /*!< counts the time function is in Ped brake level 1 state @unit:s*/
  float32      *pfActiveTimePed2;            /*!< counts the time function is in Ped brake level 2 state @unit:s*/
  float32      *pfActiveTimePed3;            /*!< counts the time function is in Ped brake level 3 state @unit:s*/
  float32      *pfActiveTimeLongVru1;        /*!< counts the time function is in LongVru1 brake level 1 state @unit:s*/
  float32      *pfActiveTimeLongVru2;            /*!< counts the time function is in LongVru1 brake level 2 state @unit:s*/
  #if (HEAD_USE_CROSSING_BRK)
  float32      *pfActiveTimeCrossBrk;        /*!< counts the time the function is in cross brake state @unit:s*/
  #endif
  #if HEAD_CFG_TURN_ASSIST
  float32      *pfActiveTimeOncomingBrk;     /*!< time since the OncomingBrake event */
  #endif
  eEBAFctChan_t *peFctChan;                  /*!< contains the actual function channel for brake event @min: 0 @max:16 @unit:[-] */
  HEADHypothesisNr_t  *pActHypNr;            /*!< activation hypothesis nr for this module @min: 0 @max:255 @unit:[-] */
} HEADModuleOutputBrakeFunction_t;           /*!@ref HEADModuleOutputInterface_t*/

/* ****************************************************************
    TYPEDEF STRUCT Transitions_t
    **************************************************************** */
/*! @brief Data type for Transitions structure 
    @general Data type for Transitions structure 
    @conseq [None]
    @attention [None]*/
typedef struct
{
  BrakeState_t BrakeState;  /*!< Break States @min: 0 @max:11  */
  BrakeEvent_t BrakeEvent;  /*!< Break Events @min: 0 @max:12 */
  BrakeState_t (*pBrakeOutFunction)( const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, HEADModuleOutputBrakeFunction_t *pPreBrakeFunction, const HEADModOutBrakeFunctionPar_t *pPreBrakeFunctionPar ); /*!< Function pointer for break out functions*/
} Transitions_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
extern eGDBError_t HEADOutBrakeFunction(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit);

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif /* _HEAD_OUT_BRAKEFUNCTION_H_INCLUDED */

/**@}*/ 
