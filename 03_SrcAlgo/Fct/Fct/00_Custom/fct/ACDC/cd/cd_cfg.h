/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD (Collision Detection)

PACKAGENAME:               cd_cfg.h

DESCRIPTION:               Configuration of CD (Collision Detection)

AUTHOR:                    $Author: uidn3976 $

CREATION DATE:             $Date: 2020/07/15 15:46:00CEST $

VERSION:                   $Revision: 1.43.5.1 $

LEGACY VERSION:            Revision: 1.2.1.4.3.2

**************************************************************************** */
#ifndef CD_CFG_H_INCLUDED
#define CD_CFG_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include"acdc_cfg.h"

#if (ACDC_CFG_CD)


/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup cd_cfg Configuration
@ingroup cd
@brief    Contains all configuration switches related to the cd subcomponent.\n\n
@{
*/
/*****************************************************************************
  MACROS
*****************************************************************************/

/*! @brief CD parameter dependent switch: (A && B)? */
#define CD_PAR_DEPENDENT_SWITCH(switch_value1, switch_value2) ((((switch_value1) == SWITCH_ON) && ((switch_value2) == SWITCH_ON))?(SWITCH_ON):(SWITCH_OFF))
/*! @brief CD parameter dependent switch with three inputs: (A && B && C)? */
#define CD_PAR_DEPENDENT_SWITCH_THREE(switch_value1, switch_value2, switch_value3)  ((((switch_value1) == SWITCH_ON) && ((switch_value2) == SWITCH_ON) && ((switch_value3) == SWITCH_ON))?(SWITCH_ON):(SWITCH_OFF))

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/***************************************
Use Yokotan Partial Blockage Counter Measure
****************************************/
/*! @breif Use of Yokotan Partial Blockage Counter Measure: If Blockage Probability and Confidence is greater the threshold set
then, inhibit EBA activations*/

#define CD_USE_YOKO_PAR_BLK_CM                      SWITCH_OFF
#if (CD_USE_YOKO_PAR_BLK_CM)
        #define CD_CamConfThresh                       (90u)
        #define CD_PartialBlockage_ProbThresh         (0.9f)
        #define CD_PartialBlockage_ConfThresh         (0.1f)
#endif

/***************************************
Deprecated candidates
****************************************/

/*! @brief Use small trajectory width for at farer range for small object like bicycle */
#define CD_USE_NAR_TRAJ_RUN_UP_SMALL_OBJ            SWITCH_ON

/*! Enable/disable keep optimization for run-up scenarios 
 *
 * Keep objects in narrow curves at a max. distance/TTC,
 * when they follow the curve.
 */

/*! @brief  Till the version 1.67 of cd_hyprunup.c the function was out of service because of a BUG
            If the function is needed, it has to be fixed and analyzed. Otherwise it has to be removed*/
#define CD_RUN_UP_USE_NCURVE_KEEP                   SWITCH_ON

/*! @brief  CD_USE_CUSTOM_TRACK_ASSIGNMENT. 
            This Switch is only needed in ARS4D0 to prevent conflict between the basic implementation of the function
            CDAssignTrackProbability and its project-specific implementation*/
#define CD_USE_CUSTOM_TRACK_ASSIGNMENT              SWITCH_OFF

/* ***********************************
Always On candidates
***************************************/
/*! @brief  Enable generic hypothesis handler.
      - @attention  Behavior could be different. Hypothesis is not switched off if eba quality decreases. 
                    Make sure that all relevant modules have a object probability check */
#define CD_USE_GENERIC_HYPOTHIS_HANDLER             SWITCH_ON

/*! Activate the usage of the hypcat to determine the  */
#define CD_USE_HYPCAT_FOR_DYNAMIC_PROPERTY          SWITCH_OFF

/*************************************************************
Rework needed
**************************************************************/
/*! @brief Enable eba object high quality life time. TODO: The function has to be moved to the Custom-Part */
#define CD_USE_HIGH_QUALITY_LIFETIME                FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_EBA_USE_HIGH_QUALITY_LIFETIME, SWITCH_ON)

/*! @brief   Activate persistent hypothesis IDs. 
    Hypothesis are not sorted according to their relevance. Hypothesis keep their IDs when the ID was assigned once. */
#define CD_USE_PERSISTENT_HYPOTHESIS_IDS            SWITCH_OFF

/*
only one Concept can be followed in base implementation 
=> significant propblems in calculations in high dynamic situations in case of mixing up
=> clarify and clean up
*/

/**********************************************************************************************************
***********************************************************************************************************
 Configuration of Feature Switches
***********************************************************************************************************
***********************************************************************************************************/

/*! @brief Use hypothesis relations calculation */
#define CD_USE_HYPOTHESIS_RELATION                  SWITCH_ON

/*! @brief Use SI-ACC object for ACC hypothesis */
#define CD_USE_ACC_SI_OBJECT                        CD_PAR_DEPENDENT_SWITCH (FCT_CFG_SLATE_COMPONENT, SWITCH_ON)

/*! @brief Use TTS occupy recognition to check safe evasion side */
#define CD_USE_TTS_OCCUPY_RECOGNITION               SWITCH_ON

/*! @brief Enable when TTC with brake jerk assumptions shall be calculated / considered */
#define CD_USE_BRAKE_JERK_TTC                       SWITCH_ON

/*! @brief Suppress crossing objects in case they are stopped */
#define CD_SUPPRESS_CROSSING_STOPPED_OBJECTS        SWITCH_OFF

/*! @brief Use the RoadEstimation to determine if a pedestrian is on the Road or not */
#define CD_PED_USE_EM_ROAD_ESTIMATION               SWITCH_OFF

/*! @brief Use the RoadEstimation to determine if a bicycle is on the Road or not */
#define CD_BICYCLE_USE_EM_ROAD_ESTIMATION           SWITCH_OFF

/*! @brief Use Distance to pass in TTS calculation */
#define CD_USE_DISTANCE_TO_PASS                     SWITCH_ON

/*! @brief give only needed AnecLong to pass behind a vehicle */
#define CD_USE_ANECLONG_PASS                        (SWITCH_OFF)

/****************************************************************
  EPF - Evasion Possibility Front Settings
 *****************************************************************/

/*! @brief  CD_USE_EPF */
#define CD_USE_EPF                                  CD_PAR_DEPENDENT_SWITCH(FCT_CFG_SEN_CAM_LANE_INTERFACE, SWITCH_OFF)

/*! @brief  enable the corridor output freeze (radar specific) */
#define CD_EPF_CORRIDOR_FREEZE                      (    SWITCH_ON)
/****************************************************************
  EMP Configuration
 *****************************************************************/

/***********************************************************************************************************
************************************************************************************************************
Switches related to Manipulations on Objects and Ego in calculation
************************************************************************************************************
************************************************************************************************************/

/*! @brief At stationary targets assume TTC-filtering in OD as correct and adjust distance accordingly */
#define CD_USE_VREL_COMPENSATED_DISTANCE            SWITCH_OFF

/*! @brief Use limited dimensions for pedestrian objects */
#define CD_PED_USE_LIMITED_DIMENSIONS               SWITCH_OFF

/*! @brief Use limited dimensions for Bicycle objects */
#define CD_BICYCLE_USE_LIMITED_DIMENSIONS           SWITCH_OFF

/*! @brief TTM LONG interface is present */
#define CD_TTM_LONG_INTF_AVAILABLE                  SWITCH_ON

/*! @brief Include TTM Calculations */
#define CD_USE_TTM_LONG                             CD_PAR_DEPENDENT_SWITCH(CD_TTM_LONG_INTF_AVAILABLE, SWITCH_OFF)

/*! @brief Use positive ego acceleration for prediction (if no: use 0 instead)*/
#define CD_USE_POS_LONG_EGO_ACCEL                   SWITCH_OFF

/*! @brief CD_LIMIT_RADAR_OBJECT_WIDTH */
#define CD_LIMIT_RADAR_OBJECT_WIDTH                 SWITCH_ON

/*! @brief      Use object association probabilities from fusion object list to fill eSensorSource interface
    @attention  If this is switched on and FCT_CFG_INCLUDE_FUSION_OBJECT_LIST is not switched on, only the host sensor bit is set. */
#define CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE          SWITCH_ON

/*! @brief      Enables the use of a constant value for the Objects width (@ref CD_CONST_OBJ_WIDTH_VAR) and 
                length (@ref CD_CONST_OBJ_LENGTH_VAR) variance.
                @attention: Test the function CDCalcGeometryVarianceFromShapePoints before deactivating this switch.*/
#define CD_USE_CONST_OBJ_GEOMETRY_VAR               SWITCH_ON

/*! @brief      Enable High Quality Lifetime for crossing objects */
#define CD_USE_HIGH_QUALITY_LIFETIME_CROSSING       SWITCH_OFF
/***********************************************************************************************************
************************************************************************************************************
Hypothesis feature switches
************************************************************************************************************
************************************************************************************************************/
/*! @brief  Enable Follow Hypothesis Evaluation */
#define CD_USE_FOLLOW_HYPOTHESIS                    SWITCH_ON

/*! @brief  Enable Run-up Hypothesis Evaluation */
#define CD_USE_RUN_UP_HYPOTHESIS                    SWITCH_ON

/*! @brief  Enable Pass Hypothesis Evaluation */
#define CD_USE_PASS_HYPOTHESIS                      SWITCH_ON

/*! @brief  Enable Pass Hypothesis Evaluation */
#define CD_USE_CUT_IN_HYPOTHESIS                    SWITCH_OFF

/*! @brief  CD_USE_ACC_HYPOTHESIS */
#define CD_USE_ACC_HYPOTHESIS                       SWITCH_ON

/*! @brief  Enable Collision Hypothesis Evaluation */
#define CD_USE_COLL_HYPOTHESIS                      SWITCH_ON

/*! @brief  Enable Collision Hypothesis Evaluation */
#define CD_USE_RUN_UP_STAT_HYPOTHESIS               SWITCH_ON

/*! @brief  Enable Pedestrian Collision Hypothesis Evaluation Needs CD_USE_EMP*/
#define CD_USE_PED_COLL_HYPOTHESIS                  SWITCH_ON

/*! @brief  Enable Bicycle Collision Hypothesis */
#define CD_USE_BICYCLE_COLL_HYPOTHESIS              SWITCH_ON

/*! @brief  Enable Crossing Hypothesis Evaluation */
#define CD_USE_CROSSING_HYPOTHESIS                  CD_PAR_DEPENDENT_SWITCH(CD_USE_TTM_LONG, SWITCH_OFF)

/*! @brief  Enable Long generic Ru-Up Hypothesis Evaluation */
#define CD_USE_LONG_COLL_HYPOTHESIS                 (SWITCH_ON)

/*! @brief  Enable Oncoming Hypothesis Evaluation */
#define CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS       (SWITCH_OFF)

/*! @brief  Enable turn into oncoming pedestrian hypothesis, @attention: Evaluation needs CD_USE_EMP*/
#define CD_USE_TURNINTOVRU_HYPOTHESIS               (SWITCH_OFF)

/*! @brief  Enable drive into slow moving hypothesis */
#define CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS          (SWITCH_OFF)

/*! @brief  Enable the blocking of turn scenario detection in the opposite direction for specific distance,
            to avoid the detection of the orientation correction phase in lane change scenario as turning. */
#define CD_BLK_DIST_TURN_OPST_DIR                   (SWITCH_OFF)

/*! @brief  Use custom anec long signal */
#define CD_USE_CUSTOM_ANEC_LONG                     (SWITCH_ON)

/*! @brief  Enable Probability of Speed Concept */
#define  CD_USE_GEN_PSC                             (SWITCH_ON)

/*! @brief  Enable the hypothesis common module */
#define  CD_USE_HYP_COMMON                          (SWITCH_ON)

/*! @brief  Use FPS object class   */
#define  CD_USE_EM_FPS_OBJCLASS                     (SWITCH_ON)

/****************************************************************
  Switch between standard and custom hypothesis call
 *****************************************************************/
 
/*! @brief  CD_USE_CUSTOM_HYPOTHESIS_RUNUP */
#define CD_USE_CUSTOM_HYPOTHESIS_RUNUP                    SWITCH_OFF
/*! @brief  CD_USE_CUSTOM_HYPOTHESIS_RUNUPSTATIONARY */
#define CD_USE_CUSTOM_HYPOTHESIS_RUNUPSTATIONARY          SWITCH_OFF
/*! @brief  CD_USE_CUSTOM_HYPOTHESIS_PEDESTRIAN_COLLISION */
#define CD_USE_CUSTOM_HYPOTHESIS_PEDESTRIAN_COLLISION     SWITCH_OFF

/***********************************************************************************************************
************************************************************************************************************
Hypothesis specific switches
************************************************************************************************************
************************************************************************************************************/

/************************************************************************/
/* Long collision hypothesis                                            */
/************************************************************************/

/*! @brief Enables the time based hypothesis probability */
#define CD_HYP_LONG_COLL_TIME_BASED_HYP_PROB_ENABLE SWITCH_ON

/*! @brief Restrict the admissible object class for oncoming objects to pedestrians */
#define CD_HYP_LONG_COLL_ONC_ONLY_PED               SWITCH_OFF

/************************************************************************/
/* Run up stationary hypothesis                                         */
/************************************************************************/
/*! @brief Enable the suppression of objects which are located in a object chain. */
#define CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION  SWITCH_ON
/*! @brief Use hypothesis relations between ACC and run up stationary hypothesis */
#define CD_HYP_RUN_UP_STAT_USE_ACC_HYPOTHESIS_SUPPORT SWITCH_ON
/*! @brief Enable suppression of bicycles. */
#define CD_RUN_UP_STAT_SUPPRESS_BICYCLES              SWITCH_OFF

/***********************************************
  Ped Hypothesis
************************************************/
#if (SWITCH_ON == CD_USE_PED_COLL_HYPOTHESIS)
/*! @brief Use Corridor Approach */
#define CD_PED_COLL_USE_CORR_APPROACH               SWITCH_OFF
/*! @brief Downgrade Ped Coll Prob for Ped/Bicycles with dominant velocity not crossing */
#define CD_PED_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE SWITCH_ON

#endif

/***********************************************
  Bicycle Hypothesis
************************************************/
#if (SWITCH_ON == CD_USE_BICYCLE_COLL_HYPOTHESIS)
/*! @brief  Downgrade Ped Coll Prob for Bicycles with dominant velocity not crossing */
#define CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE     SWITCH_ON
#endif

/****************************************************************
  Crossing Hypothesis
 *****************************************************************/
#if (SWITCH_ON == CD_USE_CROSSING_HYPOTHESIS)
/*! @brief Enable Crossing Hypothesis Internal Object Data */
#define CD_HYP_CROSSING_INT_OBJ_DATA                SWITCH_OFF
#endif

/****************************************************************
  Oncoming Hypothesis
 *****************************************************************/
#if (SWITCH_ON == CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
/*! @brief Include Truck Objects for Oncoming Hypothesis */
#define CD_HYP_ONCOMING_USE_TRUCK_OBJECT             SWITCH_OFF

/*! @brief Use smoothened orientation of object's velocity vector for the    
*   calculation of the corridor stop distance
*   Background: Raw orientation calculated from the velocity vector oscillates
*               between two sen-cycles with about 1� amplitude when ego is
*               turning at 25kph.                                            */
#define CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION        (SWITCH_OFF)
#endif

/***********************************************************************************************************
************************************************************************************************************
  Measurement Settings
************************************************************************************************************
************************************************************************************************************/



///@}
#endif /*(ACDC_CFG_CD)*/

#endif /* CD_CFG_H_INCLUDED */

