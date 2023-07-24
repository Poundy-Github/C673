/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_traffic_estimation.c

DESCRIPTION:               Estimation of traffic density value

AUTHOR:                    Simon Sinnstein

CREATION DATE:             -

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_traffic.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_traffic_estimation Sit Traffic Estimation
@ingroup sit
@brief          This module estimates of traffic density value. \n\n
@{
*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/
#if (SIT_CFG_TRAFFIC_DENSITY)
#define SIT_TE_RIGHT_UNBOUND     (24u)     /*!< right lane unbound traffic */
#define SIT_TE_RIGHT_BOUND       (29u)     /*!< right lane bound traffic */
#define SIT_TE_RIGHT_JAM         (50u)     /*!< right lane jam traffic */
#define SIT_TE_RIGHT_NO_JAM      (45u)     /*!< right lane no jam, bound traffic */
#define SIT_TE_RIGHT_JAM_VEL     (11u)     /*!< right lane jam traffic velocity */
#define SIT_TE_RIGHT_NO_JAM_VEL  (14u)     /*!< right lane no jam traffic velocity */

#define SIT_TE_LEFT_UNBOUND      (20u)     /*!< left lane unbound traffic */
#define SIT_TE_LEFT_BOUND        (25u)     /*!< left lane bound traffic */
#define SIT_TE_LEFT_JAM          (45u)     /*!< left lane jam traffic */
#define SIT_TE_LEFT_NO_JAM       (40u)     /*!< left lane no jam, bound traffic */
#define SIT_TE_LEFT_JAM_VEL      (11u)     /*!< left lane jam traffic velocity */
#define SIT_TE_LEFT_NO_JAM_VEL   (14u)     /*!< left lane no jam traffic velocity */

#define SIT_TE_EGO_UNBOUND       (20u)     /*!< ego lane unbound traffic */
#define SIT_TE_EGO_BOUND         (25u)     /*!< ego lane bound traffic */
#define SIT_TE_EGO_JAM           (45u)     /*!< ego lane jam traffic */
#define SIT_TE_EGO_NO_JAM        (40u)     /*!< ego lane no jam, bound traffic */
#define SIT_TE_EGO_JAM_VEL       (11u)     /*!< ego lane jam traffic velocity */
#define SIT_TE_EGO_NO_JAM_VEL    (14u)     /*!< ego lane no jam traffic velocity */

#define SIT_TE_DENSITY_SCALE_VEL_MAX (75.f/C_KMH_MS) /*!< empirically determined max velocity beyond the focus is on ego lane */


/*! enum to describe traffic density states */
enum LaneDensityState
{
  INIT,    /*!< Init */
  UNBOUND, /*!< free drive */
  BOUND,   /*!< tough-flowing */
  JAM      /*!< traffic jam */
};

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/
/*! Traffic density estimation data per lane */
typedef struct LaneEstimation
{
  uint8      uiUnbound;
  uint8      uiBound;
  uint8      uiJam;
  uint8      uiNoJam;
  uint8      uiJamVel;
  uint8      uiNoJamVel;
} t_LaneEstimation;

SET_MEMSEC_VAR(pidLastOffset)
static float32 pidLastOffset; /* auxiliary variable used for PID control */
SET_MEMSEC_VAR(meanDiffPJam)
static float32 meanDiffPJam;  /* changes in the traffic jam probability are bounded by the difference to the mean change */

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/
SET_MEMSEC_CONST(RightLaneEstimation)
static const t_LaneEstimation        RightLaneEstimation = {SIT_TE_RIGHT_UNBOUND, 
                                                     SIT_TE_RIGHT_BOUND, 
                                                     SIT_TE_RIGHT_JAM, 
                                                     SIT_TE_RIGHT_NO_JAM, 
                                                     SIT_TE_RIGHT_JAM_VEL, 
                                                     SIT_TE_RIGHT_NO_JAM_VEL};

SET_MEMSEC_CONST(LeftLaneEstimation)
static const t_LaneEstimation        LeftLaneEstimation =  {SIT_TE_LEFT_UNBOUND, 
                                                     SIT_TE_LEFT_BOUND, 
                                                     SIT_TE_LEFT_JAM, 
                                                     SIT_TE_LEFT_NO_JAM, 
                                                     SIT_TE_LEFT_JAM_VEL, 
                                                     SIT_TE_LEFT_NO_JAM_VEL};

SET_MEMSEC_CONST(EgoLaneEstimation)
static const t_LaneEstimation        EgoLaneEstimation =   {SIT_TE_EGO_UNBOUND, 
                                                     SIT_TE_EGO_BOUND, 
                                                     SIT_TE_EGO_JAM, 
                                                     SIT_TE_EGO_NO_JAM, 
                                                     SIT_TE_EGO_JAM_VEL, 
                                                     SIT_TE_EGO_NO_JAM_VEL};

#define SIT_TE_CONF_THRESHOLD  (60u)     /*!< minimum confidence threshold */

#define SIT_TE_MINSHIFT_LEFT   (0.f)     /*!< minimum shift for ego density given left lane density information */
#define SIT_TE_MAXSHIFT_LEFT   (20.f)    /*!< maximum shift for ego density given left lane density information */

#define SIT_TE_MINSHIFT_RIGHT  (0.f)     /*!< minimum shift for ego density given right lane density information */
#define SIT_TE_MAXSHIFT_RIGHT  (20.f)    /*!< maximum shift for ego density given right lane density information */

#endif


#if (SIT_CFG_TRAFFIC_DENSITY || SIT_CFG_TRAFFIC_ESTIMATION)

SET_MEMSEC_VAR(SITGlobalDensityData)
GlobalDensityData_t SITGlobalDensityData;

#endif

#if (SIT_CFG_TRAFFIC_ESTIMATION)

/******* Traffic Jam Probability ********************/
#define SIT_TE_ZO_VEL_NOJAM    (100.0f)  /*!< Default velocity for ZO when there is no traffic jam */
#define SIT_TE_COLL_TIME_HIST  (75u)     /*!< Number of previous cycles to be considered while computing collective velocity */

#define SIT_TE_PJAM_LEVEL_1    (1u)      /*!< Level 1 of traffic jam probability */
#define SIT_TE_PJAM_LEVEL_2    (2u)      /*!< Level 2 of traffic jam probability */
#define SIT_TE_PJAM_LEVEL_3    (3u)      /*!< Level 3 of traffic jam probability */
#define SIT_TE_PJAM_LEVEL_4    (4u)      /*!< Level 4 of traffic jam probability */

/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/
SET_MEMSEC_VAR(fTEPJamSet_1)
static float32 fTEPJamSet_1     = 0.25f;// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */  /*!< TE Probability Level 1 @allow:oem_bmw */
SET_MEMSEC_VAR(fTEPJamSet_2)
static float32 fTEPJamSet_2     = 0.50f;// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */  /*!< TE Probability Level 2 @allow:oem_bmw */
SET_MEMSEC_VAR(fTEPJamSet_3)
static float32 fTEPJamSet_3     = 0.75f;// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */  /*!< TE Probability Level 3 @allow:oem_bmw */
SET_MEMSEC_VAR(fTEPJamSet_4)
static float32 fTEPJamSet_4     = 1.00f;// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */  /*!< TE Probability Level 4 @allow:oem_bmw */

SET_MEMSEC_VAR(fTEZOVelSet_1)
static float32 fTEZOVelSet_1    = (35.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Target Object Velocity set 1 (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTEZOVelSet_2)
static float32 fTEZOVelSet_2    = (25.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Target Object Velocity set 2 (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTEZOVelSet_3)
static float32 fTEZOVelSet_3    = (20.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Target Object Velocity set 3 (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTEZOVelSet_4)
static float32 fTEZOVelSet_4    = (15.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Target Object Velocity set 4 (in m/s) @allow:oem_bmw */

SET_MEMSEC_VAR(fTECollVelSet_1)
static float32 fTECollVelSet_1  = (30.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Collective Object Velocity set 1 (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollVelSet_2)
static float32 fTECollVelSet_2  = (20.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Collective Object Velocity set 2 (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollVelSet_3)
static float32 fTECollVelSet_3  = (15.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Collective Object Velocity set 3 (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollVelSet_4)
static float32 fTECollVelSet_4  = (10.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Collective Object Velocity set 4 (in m/s) @allow:oem_bmw */

SET_MEMSEC_VAR(fTEDebounceThres)
static float32 fTEDebounceThres = (60.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */          /*!< TE Debounce Time Threshold (in s) @allow:oem_bmw */

SET_MEMSEC_VAR(fTESNGZOMinVel)
static float32 fTESNGZOMinVel  = (10.0f/C_KMH_MS);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */ /*!< TE Stop n Go Min. Velocity Threshold (in m/s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTESNGZOMinTime)
static float32 fTESNGZOMinTime = (40.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */          /*!< TE Stop n Go Min. Time Threshold (in s) @allow:oem_bmw */

SET_MEMSEC_VAR(fTESNGTimeUp)
static float32 fTESNGTimeUp    = (200.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */          /*!< TE Stop n Go Filter UP Time (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTESNGTimeDown)
static float32 fTESNGTimeDown  = (40.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */          /*!< TE Stop n Go Filter DOWN Time (in s) @allow:oem_bmw */


SET_MEMSEC_VAR(fTECollTimeUpSet_1)
static float32 fTECollTimeUpSet_1   = (60.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter UP Time set 1 (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollTimeUpSet_2)
static float32 fTECollTimeUpSet_2   = (60.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter UP Time set 2 (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollTimeUpSet_3)
static float32 fTECollTimeUpSet_3   = (60.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter UP Time set 3 (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollTimeUpSet_4)
static float32 fTECollTimeUpSet_4   = (60.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter UP Time set 4 (in s) @allow:oem_bmw */

SET_MEMSEC_VAR(fTECollTimeDownSet_1)
static float32 fTECollTimeDownSet_1 = (20.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter Down Time set 1 (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollTimeDownSet_2)
static float32 fTECollTimeDownSet_2 = (20.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter Down Time set 2 (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollTimeDownSet_3)
static float32 fTECollTimeDownSet_3 = (20.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter Down Time set 3 (in s) @allow:oem_bmw */
SET_MEMSEC_VAR(fTECollTimeDownSet_4)
static float32 fTECollTimeDownSet_4 = (20.0f);// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */   /*!< TE Collective Filter Down Time set 4 (in s) @allow:oem_bmw */

/* Traffic Estimation specific Timer */
SET_MEMSEC_VAR(fTimerVZO)
static float32 fTimerVZO    = 0.0f;// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */  /*!< Timer for the relevant object in Stop n Go scenario*/
SET_MEMSEC_VAR(fDebounceTimer)
static float32 fDebounceTimer = 0.0f;// PRQA S 3218
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */  /* Time to delay an increment of traffic jam probability */

#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (SIT_CFG_TRAFFIC_DENSITY)
static void SIT_v_TrafficLaneEstimation( float32* const pTrafficDensity, sint8* const pConfidence, float32* const pVrelXMed, t_LaneEstimation const * const pLaneEstimation, uint8* const pTrafficState );
#endif

#if (SIT_CFG_TRAFFIC_ESTIMATION)
static void SIT_v_TrafficJamProbability(const boolean bOOIOnly, const float32 fVelMedOOI, const float32 fVelMedCollective);
static float32 SIT_v_GetTrafficJamProb(const float32 fCollVel, const float32 fZOVel, const float32 fPJam, float32* const pfCurrentPState, float32* const pfFilterTime);
static void SIT_v_GetTJPUpTime(const uint8 uiCurrentSet, const uint8 uiTargetSet, float32* const pfFilterTime);
static void SIT_v_GetTJPDownTime(const uint8 uiCurrentSet, const uint8 uiTargetSet, float32* const pfFilterTime);
static boolean SIT_v_GetCollectiveVelocity(CML_t_WeightedSample* pt_CollectiveObject);
#endif

/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
#if (SIT_CFG_TRAFFIC_DENSITY)
/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficEstiInit                                                                                */ /*!

  @brief           Init module

  @description     Initialization function for module specific variables

		@startuml
		Start
		Partition SIT_v_TrafficEstiInit {
		: Initialization function for module specific variables;
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         - 
  @glob_out        pidLastOffset : auxiliary variable used for PID control [0.f]
  @glob_out        meanDiffPJam : changes in the traffic jam probability are bounded by the difference to the mean change [0.f]


  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_DENSITY: Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.12.2013
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
void SIT_v_TrafficEstiInit(void)
{
  pidLastOffset = 0;
  meanDiffPJam  = 0;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficEstiProcess                                                                             */ /*!

  @brief           Traffic estimation calculation main function

  @description     This is the main function for traffic estimation. Traffic jam estimation is carried out for all the lanes and traffic state variables are updated.

		@startuml
		Start
		Partition SIT_v_TrafficEstiProcess {
		: This is the main function for traffic estimation. Traffic jam estimation is carried out for all the lanes and traffic state variables are updated;
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         SITGlobalDensityData : Global structure for storing traffic density data for all lanes [GlobalDensityData_t as defined in sit_traffic.h]
                      DensityDataLeft : Structure for storing information about traffic density on left lane [t_LaneDensityData as defined in sit_traffic.h]
                      DensityDataRight : Structure for storing information about traffic density on right lane [t_LaneDensityData as defined in sit_traffic.h]
                      DensityDataEGO : Structure for storing information about traffic density on EGO lane [t_LaneDensityDataE as defined in sit_traffic.h]
                   For each LaneDensityData
                      fVrelXMed : relative middle/average velocity in lane [-330.f ... 330.f] m/s
                      fTrafficDensity : traffic density in lane [full range of datatype]
                      siConfidence : Confidence of traffic density [full range of datatype]
                      uiLaneState : Traffic density state per lane [LaneDensityState as defined in sit_traffic.h]

  @glob_out        SITGlobalDensityData : Global structure for storing traffic density data for all lanes [GlobalDensityData_t as defined in sit_traffic.h]
                      uiTrafficState : combined traffic state [full range of datatype]

  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_DENSITY: Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.12.2013
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_TrafficEstiProcess(void)
{

  SIT_v_TrafficLaneEstimation(&SITGlobalDensityData.DensityDataRight.fTrafficDensity,
    &SITGlobalDensityData.DensityDataRight.siConfidence,
    &SITGlobalDensityData.DensityDataRight.fVrelXMed,
    &RightLaneEstimation,
    &SITGlobalDensityData.DensityDataRight.uiLaneState );

  SIT_v_TrafficLaneEstimation(&SITGlobalDensityData.DensityDataLeft.fTrafficDensity,
    &SITGlobalDensityData.DensityDataLeft.siConfidence,
    &SITGlobalDensityData.DensityDataLeft.fVrelXMed,
    &LeftLaneEstimation,
    &SITGlobalDensityData.DensityDataLeft.uiLaneState );

  SIT_v_TrafficLaneEstimation(&SITGlobalDensityData.DensityDataEgo.fTrafficDensity,
    &SITGlobalDensityData.DensityDataEgo.siConfidence,
    &SITGlobalDensityData.DensityDataEgo.fVrelXMed,
    &EgoLaneEstimation,
    &SITGlobalDensityData.DensityDataEgo.uiLaneState );

  SITGlobalDensityData.uiTrafficState = MAX( MAX(SITGlobalDensityData.DensityDataRight.uiLaneState,
    SITGlobalDensityData.DensityDataLeft.uiLaneState),
    SITGlobalDensityData.DensityDataEgo.uiLaneState);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficLaneEstimation                                                                          */ /*!

  @brief           Traffic estimation calculation in a given lane

  @description     Traffic estimation calculation in a given lane. Traffic state variable is updated based on confidence and existing traffic state.

		@startuml
		Start
		Partition SIT_v_TrafficLaneEstimation {
		If (if confidence of traffic density is above threshold) then (yes)
			If (Unbound Lane Estimation is more than traffic Density) then (yes)
				: Set traffic Density as Unbound;
			Else if (Bound Lane Estimation is less than traffic Density and traffic Jam is more than traffic Density) then (yes)
				: Set traffic Density as Bound;
			Else if (Unbound Lane Estimation is less than traffic Density and traffic jam is more than traffic density) then (yes)
				: Set traffic density as Bound;
			Else if (No Traffic Jam traffic jam is less than traffic density) then (yes)
				: Set traffic density as Traffic Jam;
			Else (no)
				: Do Nothing;
			Endif
		Else (no)
			: Set traffic Density as Unbound;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in,out]   pTrafficDensity : traffic density in lane [full range of datatype]
  @param[in,out]   pConfidence : Confidence of traffic density [full range of datatype]
  @param[in,out]   pVrelXMed : relative middle/average velocity in lane [-330.f ... 330.f] m/s
  @param[in]       pLaneEstimation : Traffic density estimation data per lane [t_LaneEstimation as defined in sit_traffic_estimation.c]
  @param[in,out]   pTrafficState : Traffic density state per lane [LaneDensityState as defined in sit_traffic.h]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : velocity of the ego vehicle   [-330.f ... 330.f] m/s
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_DENSITY: Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.12.2013
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
static void SIT_v_TrafficLaneEstimation( float32* const pTrafficDensity, sint8* const pConfidence, float32* const pVrelXMed, t_LaneEstimation const * const pLaneEstimation, uint8* const pTrafficState )
{
  if ( SIT_TE_VALID_CONFIDENCE < *pConfidence )
  {
    if ( pLaneEstimation->uiUnbound > *pTrafficDensity )
    {
      *pTrafficState = (uint8)UNBOUND;
    }
    else if ( ( BOUND > *pTrafficState ) && ( pLaneEstimation->uiBound < *pTrafficDensity ) && ( pLaneEstimation->uiJam > *pTrafficDensity ) )
    {
      *pTrafficState = (uint8)BOUND;
    }
    else if ( ( BOUND < *pTrafficState ) && ( pLaneEstimation->uiUnbound <= *pTrafficDensity ) 
            && ( pLaneEstimation->uiNoJam > *pTrafficDensity ) && ( pLaneEstimation->uiNoJamVel < (*pt_SITInput->t_RTE.pf_EgoLongVel + *pVrelXMed) ) )
    {
      *pTrafficState = (uint8)BOUND;
    }
    else if ( ( JAM != *pTrafficState ) && ( pLaneEstimation->uiJam <= *pTrafficDensity ) && ( pLaneEstimation->uiJamVel > (*pt_SITInput->t_RTE.pf_EgoLongVel + *pVrelXMed) ) )
    {
      *pTrafficState = (uint8)JAM;
    }
    else
    {
    }
  }
  else
  {
    /* Vego bedingung hinzufuegen */
    *pTrafficState = UNBOUND;
  }
}
#endif /*!< SIT_CFG_TRAFFIC_DENSITY */



#if (SIT_CFG_TRAFFIC_ESTIMATION)
/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficJamInit                                                                                 */ /*!

  @brief           Init module

  @description     Initialize counters & timers used in traffic jam probability estimation

		@startuml
		Start
		Partition SIT_v_TrafficJamInit {
		: Initialize counters & timers used in traffic jam probability estimation;
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        SITGlobalDensityData.uiJamProbability : Traffic jam probability  [0.f ... 1.f]
  @glob_out        fDebounceTimer : Debounce timer [full range of datatype > 0.f] s
  @glob_out        fTimerVZO : Timer specific to relevant object [full range of datatype > 0.f] s


  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Harsha Umesh Babu | Christopher Knievel
*************************************************************************************************************************/
void SIT_v_TrafficJamInit(void)
{
  /* Initialize counters & timers used in traffic jam probability estimation */
  SITGlobalDensityData.uiJamProbability = 0.f;
  fDebounceTimer = 0.f;
  fTimerVZO = 0.f;

}

/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficJamEstimationMain                                                                       */ /*!

  @brief           Traffic jam calculation main function

  @description     Check for neighboring objects, get collective velocity and compute traffic jam probability 
                   based on this collective velocity/relevant object velocity.

		@startuml
		Start
		Partition SIT_v_TrafficJamEstimationMain {
		: Flag to indicate only OOI present and traffic jam probability is considered primarily for SnG scenario. Initialized to TRUE, while even in worst case scenarios, one is expected to have ZO in sight;
		: Set initial velocity to 100 m/s since this will increase the likelihood for a low traffic jam probability;
		: Initialize collective object with default values;
		: estimate traffic jam probability;
		If (if OOI0 is present) then (yes)
			If (Object is moving or on coming or Object is moving to stationary) then (yes)
				: Update absolute velocity of the object;
			Endif
		Endif
		: Save average collective velocity;
		: Set Traffic Jam Probability;
		}
		End
		@enduml

  @return          -

  @param[in]       - 

  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.pb_ObjIsMovingToStationary(i) : Macro to check if a moving object i is stopping [TRUE, FALSE]
  @glob_in         pt_SITInput->t_FIPOA.pf_ObjAbsVelX(i) : absolute velocity of the object i    [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING : Configuration switch for enabling custom output of the collective velocity
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Harsha Umesh Babu | Christopher Knievel
*************************************************************************************************************************/
void SIT_v_TrafficJamEstimationMain(void)
{
  ObjNumber_t RelObjNr;
  /*Flag to indicate only OOI present and traffic jam probability is 
  considered primarily for SnG scenario.
  Initialized to TRUE, while even in worst case scenarios, one is expected to have ZO in sight!
  */
  boolean bOOIOnly = TRUE;
  boolean b_ObjIsMovingToStationary = FALSE;
  SLATE_t_Obj_DynamicProperty ObjDynProperty;
  
  /* Holder variable for OOI velocity */
  /* Set initial velocity to 100 m/s since this
     will increase the likelihood for a low traffic jam probability */
  float32 fVelMedOOI        = SIT_TE_ZO_VEL_NOJAM;

  /* Holder variable for average velocity and standard deviation of collective velocity */
  CML_t_WeightedSample t_CollectiveObject;

  /* Holder variable for collective velocity  */
  float32 fVelMedCollective = 0.0f;


  /* Initialize collective object with default values */
  t_CollectiveObject.dSumme         = 0.0f;
  t_CollectiveObject.dQuadSumme     = 0.0f;
  t_CollectiveObject.f_sumOfWeights = 0.0f;
  t_CollectiveObject.dMittel        = 0.0f;
  t_CollectiveObject.dStdAbw        = 0.0f; 

  /* Defining local variables from reference pointer */
  RelObjNr = *pt_SITInput->t_OOI.pu_OOIListObjId((uint8)OBJ_NEXT_OOI);

  /* estimate traffic jam probability */

  /* check whether surrounding objects are available */
  if(RelObjNr != OBJ_INDEX_NO_OBJECT)
  {
    ObjDynProperty=*pt_SITInput->t_RTE.pt_ObjDynProperty(RelObjNr);
    b_ObjIsMovingToStationary=pt_SITInput->t_RTE.b_ObjIsMovingToStationary(RelObjNr);
    /* Exclude a priori stationary objects */
    if ((ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) ||
        (ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING) ||
        (b_ObjIsMovingToStationary))
    {
      fVelMedOOI = pt_SITInput->pt_FIPOA->t_ObjList[RelObjNr].fAbsVelocity;
    }
  }

  bOOIOnly = SIT_v_GetCollectiveVelocity(&t_CollectiveObject);

  /* Save average collective velocity */
  fVelMedCollective = t_CollectiveObject.dMittel;
  
  SIT_v_TrafficJamProbability(bOOIOnly,fVelMedOOI,fVelMedCollective);

#if (SIT_CFG_CUSTOM_COLECTIVE_VEL_POSTPROCESSING)
  SITGlobalDensityData.t_CollectiveObject = t_CollectiveObject;
#endif
}

/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficJamProbability                                                                          */ /*!

  @brief           Function to estimate traffic jam probability

  @description     Detailed Design
  
		@startuml
		Start
		Partition SIT_v_TrafficJamProbability {
		If (OOI-0 exists and Traffic Jam Probability given only Velocity of OOI-0) then (yes)
			If (no Object Found on either left or right lane) then (yes)
				If (Target object has been seen for SIT_TE_SNG_ZO_MIN_TIME) then (yes)
					If (Debounce Timer is more than Debounce Threshold and Traffic Jam probability > 0) then (yes)
						: We have waited for SIT_TE_SNG_MIN_TIME + SIT_TE_DEBOUNCE_THRES sec the traffic jam probability should be increased to 100% within SIT_TE_SNG_TIME_UP;
						: Set current state to zero so that slope is computed [0-1] over SIT_TE_SNG_TIME_UP;
					Else (no)
						: Debounce timer is incremented by cycle time of 60ms;
					Endif
				Else (no)
					: increment counterVZO;
				Endif
			Else (no)
				: traffic jam down to 0% in SIT_TE_SNG_TIME_DOWN sec;
				If (traffic jam probability almost zero) then (yes)
					: reset counters;
				Endif
				: Set current state to zero so that slope is computed [1-0] over SIT_TE_SNG_TIME_DOWN;
			Endif
		Else (no)
			If (the traffic jam probability given the velocity of the OOI-0 as well as the averaged velocity of the surrounding objects) then (yes)
				If (Debounce Timer is more than Debounce Threshold and Traffic Jam probability is more than 0) then (yes)
					If (traffic jam probability reaches zero) then (yes)
						: Reset the counters;
					Endif
				Else (no)
					: Debounce timer is incremented by cycle time of 60ms;
				Endif
			Endif
		Endif
		: Increment/ Decrement traffic Jam Probability;
		}
		End
		@enduml  

  @return          Two difference scenarios are evaluated - traffic jam probability with only OOI-0 or with collection of vehicles around EGO vehicle.
                   Considerations are made for Stop-and-Go traffic and traffic light scenarios using debounce timers and relevant object specific timer.

  @param[in]       bOOIOnly : Boolean indicating if only relevant object should be used in computing traffic jam probability [TRUE, FALSE]
  @param[in]       fVelMedOOI : Absolute velocity of the relevant object [-330.f   330.f] m/s
  @param[in]       fVelMedCollective : Average collective velocity [-330.f   330.f] m/s

  @glob_in         -
  @glob_out        SITGlobalDensityData.uiJamProbability : Traffic jam probability  [0.f ... 1.f]
  
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             SITrafficProcess
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Harsha Umesh Babu | Christopher Knievel
*************************************************************************************************************************/
static void SIT_v_TrafficJamProbability(const boolean bOOIOnly, const float32 fVelMedOOI, const float32 fVelMedCollective)
{
  float32 fPJam       = SITGlobalDensityData.uiJamProbability;   /* current traffic jam probability */
  float32 fTargetPJam = 0.0f;  /* target traffic jam probability */
  float32 fFilterTime = 1.0f;  /* Filter time (must be > 0) */

  float32 fCurrentPState = 0.f; /* Current probability state, used in computing slope for change in probability of traffic jam */

  float32 fChangePJam = 0.0f;  /* the actual increment/decrement for the traffic jam prob */

  /*Estimation of traffic jam probability with two approaches*/
  if((bOOIOnly == TRUE) && SIT_TE_CALC_TJP_OOI_ONLY)
  {
    /********************* Scenario 2 ************************************
     *
     * Use only relevant object to calculate traffic jam probability 
     *
     ******************************************************************/
    /* no objects found on either left or right lane */
    if(fVelMedOOI < fTESNGZOMinVel)
    {
      if((fTimerVZO > fTESNGZOMinTime) || (fPJam > C_F32_DELTA))
      {
        /* Target object has been seen for SIT_TE_SNG_ZO_MIN_TIME below S_TE_SNG_ZO_MIN_VEL
           Now check fDebounceTimer
        */
        if((fDebounceTimer > fTEDebounceThres) || (fPJam > C_F32_DELTA))
        {
          /* We have waited for SIT_TE_SNG_MIN_TIME + SIT_TE_DEBOUNCE_THRES sec 
             the traffic jam probability should be increased to 100%
             within SIT_TE_SNG_TIME_UP
          */
          fTargetPJam = 1.0f;
          fFilterTime = fTESNGTimeUp;

          fCurrentPState = 0.f; /* Set current state to zero so that slope is computed [0-1] over SIT_TE_SNG_TIME_UP */
        }
        else
        {
          /* increment fDeBounceTimer */
          fDebounceTimer += SLATE_f_GetSITCycleTime();
        }
      } 
      else
      {
        /* increment counterVZO */
        fTimerVZO += SLATE_f_GetSITCycleTime();
      }
      
    }
    else
    {
      /* traffic jam down to 0% in SIT_TE_SNG_TIME_DOWN sec */
      fTargetPJam = 0.0f;
      fFilterTime = fTESNGTimeDown;
      /* reset counters if traffic jam probability almost zero*/
      if(fPJam < C_F32_DELTA)
      {
        fTimerVZO      = 0.0f;
        fDebounceTimer = 0.0f;
      }
      
      fCurrentPState = 1.f; /* Set current state to zero so that slope is computed [1-0] over SIT_TE_SNG_TIME_DOWN */
    }
  }
  else 
  {
    /********************* Scenario 1 ************************************
     *
     * Use both relevant object and collective velocity to calculate 
     * traffic jam probability 
     *
     ******************************************************************/
    if(SIT_TE_CALC_TJP_COLLECTIVE)
    {

      if((fDebounceTimer > fTEDebounceThres) || (fPJam > C_F32_DELTA))
      {

        fTargetPJam = SIT_v_GetTrafficJamProb(fVelMedCollective,fVelMedOOI,fPJam,&fCurrentPState, &fFilterTime);
        if((fTargetPJam < C_F32_DELTA) && (fPJam < C_F32_DELTA))
        {
          /* If traffic jam probability reaches zero, then reset the counter.
             This means that whenever a traffic jam probability of zero is attained,
             the timer will be reseted
          */
          fDebounceTimer = 0.f;
          fTimerVZO      = 0.f;
        }
      }
      else
      {
        /* increment fDeBounceTimer */
        fDebounceTimer += SLATE_f_GetSITCycleTime();
        fTargetPJam     = 0.0f;
      }
    }
  }
  
  /*******************************************************************
   *  Increment/Decrement traffic jam probability 
   ******************************************************************/

  /* Calculate the increment and calculate the decrement.
     Since the evaluation is using all float variables, negative signs
     are automatically taken care off, decrement and increment can be 
     determined by the sign of the fChangePJam.

     fFilterTime cannot be zero. It is initialized to 1 and always 
     assigned value greater than zero
     */
  /*fChangePJam = ((fTargetPJam - fPJam) / fFilterTime) * SLATE_f_GetSITCycleTime();*/
  fChangePJam = ((fTargetPJam - fCurrentPState) / fFilterTime) * SLATE_f_GetSITCycleTime();

  SITGlobalDensityData.uiJamProbability = MINMAX_FLOAT(0.0f,1.0f,fPJam + fChangePJam);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_GetTrafficJamProb                                                                              */ /*!

  @brief           Calculate the target traffic jam probability

  @description     Calculation of a target traffic jam probability given the velocity of the object of interest OOI-0 
                   and the average velocity of the surrounding objects. The time needed to increment/decrement the 
                   current traffic jam probability to the target traffic jam probability depends on four different 
                   predetermined sets and can be chosen independently.

		@startuml
		Start
		Partition SIT_v_GetTrafficJamProb {
		: Indicator for driving in city limits, default is outside city limits;
		If (Traffic Jam is less than current probability level1) then (yes)
			: Update Current Set as Jam Level_1;
			: Update Current State as 0;
		Else if (Traffic Jam is less than Probability level2) then (yes)
			: Update Current Set as Jam Level_2;
			: Update Current State as current probability level1;
		Else if (Traffic Jam is less than Probability level3) then (yes)
			: Update Current Set as Jam Level_3;
			: Update Current State as current probability level2;
		Else (no)
			: Update Current Set as Jam Level_4;
			: Update Current State as current probability level3;
		Endif
		If (Navi Path In city Limits is always false) then (yes)
			If (Driving outside city limits) then (yes)
				: apply all levels of traffic jam probability calculate the target traffic jam probability;
			Else (no)
				: Do Nothing;
			Endif
		Else (no)
			If (Driving within city limits) then (yes)
				: apply only level 3 & 4 of traffic jam probability;
				: calculate the target traffic jam probability;
			Else (no)
				: Do Nothing;
			Endif
		Endif
		If (Traffic Jam is less than Traffic Jam Probability) then (yes)
			: Target probability larger than current probability -> increment;
		Else if (Traffic Jam is more than Traffic Jam Probability and traffic Jam is more than 0) then (yes)
			: Calculate the time for decreasing target traffic jam probability;
			If (Current Set is Level 1) then (yes)
				: Set Current State as Traffic Jam Set 1;
			Else if (Current Set is Level 2) then (yes)
				: Set Current State as Traffic Jam Set 2;
			Else if (Current Set is Level 3) then (yes)
				: Set Current State as Traffic Jam Set 3;
			Else (no)
				: Set Current State as Traffic Jam Set 4;
			Endif
		Else (no)
			: Do Nothing;
		Endif
		}
		End
		@enduml

  @return          fJamProb : traffic jam probability [0.f ... 1.f]

  @param[in]       fCollVel : Velocity of surrounding objects [-330.f   330.f] m/s
  @param[in]       fZOVel : Velocity of the object of interest OOI-0 [-330.f   330.f] m/s
  @param[in]       fPJam : Current traffic jam probability [0.f ... 1.f]
  @param[in,out]   pfCurrentPState : Current probability state, used in computing slope for change in probability of traffic jam [0.f ... 1.f]
  @param[in,out]   pfFilterTime : Time needed to reach the target traffic jam probability [full range of datatype > 0.f]

  @glob_in         -
  @glob_out        - 

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             SITrafficProcess
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Christopher Knievel | Christopher.Knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static float32 SIT_v_GetTrafficJamProb(const float32 fCollVel, const float32 fZOVel, const float32 fPJam, 
                                   float32* const pfCurrentPState, float32* const pfFilterTime)
{
  float32 fJamProb   = 0.0f;
  uint8 uiCurrentSet = 0u;     /* determine the traffic jam set for current fPJam */
  uint8 uiTargetSet  = 0u;
  
  /* Indicator for driving in city limits, default is outside city limits */
  boolean isNaviPathInCityLimits = FALSE;

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_SIMPLE_NAVI_INTERFACE))
  if(pt_SITInput->pt_FIPNaviData->b_NaviPathIsADASQuality)
  {
    /* Only if Navi data is available, and its ADAS quality is acceptable, 
    query for information about city limits, else assume driving outside city limits */
    isNaviPathInCityLimits = (pt_SITInput->pt_FIPNaviData->b_NaviPathIsInCityLimits);
  }  
#endif

  /* Estimate the current probability level */
  if(fPJam < fTEPJamSet_1)
  {
    uiCurrentSet = SIT_TE_PJAM_LEVEL_1;
    *pfCurrentPState = 0.f;
  }
  else if(fPJam < fTEPJamSet_2)
  {
    uiCurrentSet = SIT_TE_PJAM_LEVEL_2;
    *pfCurrentPState = fTEPJamSet_1;
  }
  else if(fPJam < fTEPJamSet_3)
  {
    uiCurrentSet = SIT_TE_PJAM_LEVEL_3;
    *pfCurrentPState = fTEPJamSet_2;
  }
  else 
  {
    uiCurrentSet = SIT_TE_PJAM_LEVEL_4;
    *pfCurrentPState = fTEPJamSet_3;
  }

  if(isNaviPathInCityLimits == FALSE)  // PRQA S 3358,3355
    /* date: 2017-01-6, reviewer: Bibin Mathew, reason:isNaviPathInCityLimits is always FALSE since TRUE part is disabled by conditional MACRO*/
  {
    /* Driving outside city limits, apply all levels of traffic jam probability 
       calculate the target traffic jam probability
     */
    if((fCollVel < fTECollVelSet_4) && (fZOVel < fTEZOVelSet_4))
    {
      fJamProb = fTEPJamSet_4;
      uiTargetSet = SIT_TE_PJAM_LEVEL_4;
    }
    else if((fCollVel < fTECollVelSet_3) && (fZOVel < fTEZOVelSet_3))
    {
      fJamProb = fTEPJamSet_3;
      uiTargetSet = SIT_TE_PJAM_LEVEL_3;
    }
    else if((fCollVel < fTECollVelSet_2) && (fZOVel < fTEZOVelSet_2))
    {
      fJamProb = fTEPJamSet_2;
      uiTargetSet = SIT_TE_PJAM_LEVEL_2;
    }
    else if((fCollVel < fTECollVelSet_1) && (fZOVel < fTEZOVelSet_1))
    {
      fJamProb = fTEPJamSet_1;
      uiTargetSet = SIT_TE_PJAM_LEVEL_1;
    }
    else
    {
      /* Do nothing - No Traffic Jam - QAC fix
      leave the uiTargetSet = 0 and 
      fJamProb = 0.0
      */
    }
  }
  else 
  {// PRQA S 3201
      /* date: 2017-01-6, reviewer: Bibin Mathew , reason: control will reach else part only when isNaviPathInCityLimits is TRUE, currently TRUE Part is disabled by MACRO*/
    /* Driving within city limits, apply only level 3 & 4 of traffic jam probability */
    /* calculate the target traffic jam probability */
    if((fCollVel < fTECollVelSet_4) && (fZOVel < fTEZOVelSet_4))
    {
      fJamProb = fTEPJamSet_4;
      uiTargetSet = SIT_TE_PJAM_LEVEL_4;
    }
    else if((fCollVel < fTECollVelSet_3) && (fZOVel < fTEZOVelSet_3))
    {
      fJamProb = fTEPJamSet_3;
      uiTargetSet = SIT_TE_PJAM_LEVEL_3;
    }
    else
    {
      /* Do nothing - No Traffic Jam - QAC fix
      leave the uiTargetSet = 0 and 
      fJamProb = 0.0
      */
    }
  } /* End of IF condition checking if, we are driving within city limits */
  
  
  if(fPJam < fJamProb)
  {
    /* Target probability larger than current probability -> increment */
    SIT_v_GetTJPUpTime(uiCurrentSet, uiTargetSet, pfFilterTime);

  }
  else if((fPJam >= fJamProb) && (fPJam > C_F32_DELTA))
  {
    /* Target probability smaller than current probability -> decrement
       In case current is already current probability is already zero, then don't do anything!
    */
    SIT_v_GetTJPDownTime(uiCurrentSet, uiTargetSet, pfFilterTime);

    /* Correct pfCurrentPState for downward slope */
    if(uiCurrentSet == SIT_TE_PJAM_LEVEL_1)
    {
      *pfCurrentPState = fTEPJamSet_1;
    }
    else if(fPJam < fTEPJamSet_2)
    {
      *pfCurrentPState = fTEPJamSet_2;
    }
    else if(fPJam < fTEPJamSet_3)
    {
      *pfCurrentPState = fTEPJamSet_3;
    }
    else 
    {
      *pfCurrentPState = fTEPJamSet_4;
    }
  }
  else
  {
    /* QAC fix */
  } /* End of IF condition for computing slope of traffic jam probability */

  return fJamProb;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_GetTJPUpTime                                                                                   */ /*!

  @brief           Calculate the time for increasing target traffic jam probability

  @description     Calculation of filtering time for increasing target 
                   traffic jam probability given the current and target levels of probability.
                   The time needed to increment/decrement the current traffic jam
                   probability to the target traffic jam probability depends on four
                   different predetermined sets and can be chosen independently.

		@startuml
		Start
		Partition SIT_v_GetTJPUpTime {
		If (Current State is SIT_TE_PJAM_LEVEL_1) then (yes)
			: Update Filter time as Collision Time Up Set_1;
		Else If (Current State is SIT_TE_PJAM_LEVEL_2) then (yes)
			: Update Filter time as Collision Time Up Set_2;
		Else If (Current State is SIT_TE_PJAM_LEVEL_3) then (yes)
			: Update Filter time as Collision Time Up Set_3;
		Else If (Current State is SIT_TE_PJAM_LEVEL_4) then (yes)
			: Update Filter time as Collision Time Up Set_4;
		Else (no)
			: Do Nothing;
		Endif
		Repeat
			If (Current Probability is SIT_TE_PJAM_LEVEL_1) then (yes)
				: Update Filter time using add collision Time Up Set_1;
			Else if (Current Probability is SIT_TE_PJAM_LEVEL_2) then (yes)
				: Update Filter time using add collision Time Up Set_2;
			Else if (Current Probability is SIT_TE_PJAM_LEVEL_3) then (yes)
				: Update Filter time using add collision Time Up Set_3;
			Else if (Current Probability is SIT_TE_PJAM_LEVEL_4) then (yes)
				: Update Filter time using add collision Time Up Set_4;
			Else (no)
				: Do Nothing;
			Endif
			: Increment level of current traffic jam probability;
		Repeat While (Target probability larger than current probability)
		}
		End
		@enduml

  @return          -

  @param[in]       uiCurrentSet : Current level of probability as defined in sit_traffic_estimation [SIT_TE_PJAM_LEVEL_1, SIT_TE_PJAM_LEVEL_2, SIT_TE_PJAM_LEVEL_3, SIT_TE_PJAM_LEVEL_4]
  @param[in]       uiTargetSet : Target level of probability as defined in sit_traffic_estimation [SIT_TE_PJAM_LEVEL_1, SIT_TE_PJAM_LEVEL_2, SIT_TE_PJAM_LEVEL_3, SIT_TE_PJAM_LEVEL_4]
  @param[in,out]   pfFilterTime : Time needed to reach the target traffic jam probability [full range of datatype > 0.f] s

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             SIT_v_TrafficJamEstimationMain
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void SIT_v_GetTJPUpTime(const uint8 uiCurrentSet, const uint8 uiTargetSet, float32* const pfFilterTime)
{
  uint8 uiAuxSet = uiCurrentSet + 1u;

  /* Compute slope for changing the traffic jam probability 
     First step of the slope is dependent on current level and 
     is independent of which way the probability is moving.
  */
  switch(uiCurrentSet)
  {
  case SIT_TE_PJAM_LEVEL_1: 
    *pfFilterTime = fTECollTimeUpSet_1;
    break;
  case SIT_TE_PJAM_LEVEL_2:
    *pfFilterTime = fTECollTimeUpSet_2;
    break;
  case SIT_TE_PJAM_LEVEL_3:
    *pfFilterTime = fTECollTimeUpSet_3;
    break;
  case SIT_TE_PJAM_LEVEL_4:
    *pfFilterTime = fTECollTimeUpSet_4;
    break;
  default:
    /* QAC fix*/
    break;
  }

  /* Target probability larger than current probability -> increment */
  while(uiAuxSet <= uiTargetSet)
  {
    switch(uiAuxSet)
    {
    case SIT_TE_PJAM_LEVEL_1:
      *pfFilterTime += fTECollTimeUpSet_1;
      break;
    case SIT_TE_PJAM_LEVEL_2:
      *pfFilterTime += fTECollTimeUpSet_2;
      break;
    case SIT_TE_PJAM_LEVEL_3:
      *pfFilterTime += fTECollTimeUpSet_3;
      break;
    case SIT_TE_PJAM_LEVEL_4:
      *pfFilterTime += fTECollTimeUpSet_4;
      break;
    default:
      /* QAC fix*/
      break;
    }  /* End of Switch statement */
    uiAuxSet++;
  }

}

/*************************************************************************************************************************
  Functionname:    SIT_v_GetTJPDownTime                                                                                 */ /*!

  @brief           Calculate the time for decreasing target traffic jam probability

  @description     Calculation of filtering time for decreasing target 
                   traffic jam probability given the current and target levels of probability. 
                   The time needed to increment/decrement the current traffic jam 
                   probability to the target traffic jam probability depends on four 
                   different predetermined sets and can be chosen independently.

		@startuml
		Start
		Partition SIT_v_GetTJPDownTime {
		If (Current State is SIT_TE_PJAM_LEVEL_1) then (yes)
			: Update Filter time as Collision Time Down Set_1;
		Else If (Current State is SIT_TE_PJAM_LEVEL_2) then (yes)
			: Update Filter time as Collision Time Down Set_2;
		Else If (Current State is SIT_TE_PJAM_LEVEL_3) then (yes)
			: Update Filter time as Collision Time Down Set_3;
		Else If (Current State is SIT_TE_PJAM_LEVEL_4) then (yes)
			: Update Filter time as Collision Time Down Set_4;
		Else (no)
			: Do Nothing;
		Endif
		Repeat
			If (Current Probability is SIT_TE_PJAM_LEVEL_1) then (yes)
				: Update Filter time using add collision Time Down Set_1;
			Else if (Current Probability is SIT_TE_PJAM_LEVEL_2) then (yes)
				: Update Filter time using add collision Time Down Set_2;
			Else if (Current Probability is SIT_TE_PJAM_LEVEL_3) then (yes)
				: Update Filter time using add collision Time Down Set_3;
			Else if (Current Probability is SIT_TE_PJAM_LEVEL_4) then (yes)
				: Update Filter time using add collision Time Down Set_4;
			Else (no)
				: Do Nothing;
			Endif
			If (Current Probability is more than 0) then (yes)
				: Decrement level of current traffic jam probability;
			Endif
		Repeat While (Target probability smaller than current probability)
		}
		End
		@enduml

  @return          -

  @param[in]       uiCurrentSet : Current level of probability as defined in sit_traffic_estimation [SIT_TE_PJAM_LEVEL_1, SIT_TE_PJAM_LEVEL_2, SIT_TE_PJAM_LEVEL_3, SIT_TE_PJAM_LEVEL_4]
  @param[in]       uiTargetSet : Target level of probability as defined in sit_traffic_estimation [SIT_TE_PJAM_LEVEL_1, SIT_TE_PJAM_LEVEL_2, SIT_TE_PJAM_LEVEL_3, SIT_TE_PJAM_LEVEL_4]
  @param[in,out]   pfFilterTime : Time needed to reach the target traffic jam probability [full range of datatype > 0.f] s

  @glob_in         -
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             SIT_v_TrafficJamEstimationMain
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void SIT_v_GetTJPDownTime(const uint8 uiCurrentSet, const uint8 uiTargetSet, float32* const pfFilterTime)
{
  uint8 uiAuxSet = uiCurrentSet - 1u;

  /* Compute slope for changing the traffic jam probability 
     First step of the slope is dependent on current level and 
     is independent of which way the probability is moving.
  */
  switch(uiCurrentSet)
  {
  case SIT_TE_PJAM_LEVEL_1: 
    *pfFilterTime = fTECollTimeDownSet_1;
    break;
  case SIT_TE_PJAM_LEVEL_2:
    *pfFilterTime = fTECollTimeDownSet_2;
    break;
  case SIT_TE_PJAM_LEVEL_3:
    *pfFilterTime = fTECollTimeDownSet_3;
    break;
  case SIT_TE_PJAM_LEVEL_4:
    *pfFilterTime = fTECollTimeDownSet_4;
    break;
  default:
    /* QAC fix*/
    break;
  }
  
  while(uiAuxSet > uiTargetSet)
  {
    switch(uiAuxSet)
    {
    case SIT_TE_PJAM_LEVEL_1:
      *pfFilterTime += fTECollTimeDownSet_1;
      break;
    case SIT_TE_PJAM_LEVEL_2:
      *pfFilterTime += fTECollTimeDownSet_2;
      break;
    case SIT_TE_PJAM_LEVEL_3:
      *pfFilterTime += fTECollTimeDownSet_3;
      break;
    case SIT_TE_PJAM_LEVEL_4:
      *pfFilterTime += fTECollTimeDownSet_4;
      break;
    default:
      /* QAC fix*/
      break;
    } /* End of Switch statement */
    if(uiAuxSet > 0u)
    {
      uiAuxSet--;
    }
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_GetCollectiveVelocity                                                                          */ /*!

  @brief           Calculate the Collective velocity

  @description     Calculation of collective velocity. Considering objects having 
                   ACC quality (checking for eFuncAssociatedLane) and all objects 
                   that are [NOT (ONCOMING & ON_EGOLane)].

		@startuml
		Start
		Partition SIT_v_GetCollectiveVelocity {
		Repeat
			If (Object Quality is sufficient) then (yes)
				If (check for oncoming object and object is not in-lane) then (yes)
					: Do Nothing;
				Else (no)
					If (Object is moving or On Coming or Object is moving to stationary) then (yes)
						: Calculate Sum of the elements, Sum of Square of elements;
						: Increment Sum of the weight of the elements by 1;
						: Update Last Object with current Object;
					Endif
				Endif
			Endif
		Repeat While (For entire EM Object List)
		If (Sum of Weight of Collective Objects >= 1) then (yes)
			If (the single object is not the relevant object) then (yes)
				: only calculate the collective velocity;
				: return the average collective velocity which includes EGO velocity;
			Else (no)
				: Do Nothing;
			Endif
			: Update Collective Objects;
		Endif
		}
		End
		@enduml

  @return          bZOOnly : FALSE if there are objects apart from ZO contributing 
                   to collective velocity

  @param[in,out]   pt_CollectiveObject : Pointer to collective velocity/variance [CML_t_WeightedSample as defined in cml_stat.h]
                      dSumme : Sum of velocities  [-330.f *EM_N_OBJECTS ... 330.f*EM_N_OBJECTS] m/s
                      dQuadSumme : Quadratic sum of velocities [0.f ... (330.f*EM_N_OBJECTS)^2] 
                      f_sumOfWeights : Sum of weights [full range of datatype > 0.f]
                      dStdAbw : Standard deviation of velocity [0.f ... 330.f]


  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : velocity of the ego vehicle   [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.b_ObjIsMovingToStationary(i) : Macro to check if a moving object i is stopping [TRUE, FALSE]
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component 

  @pre             SILaneAssociation
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.09.2014
  @changed         17.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static boolean SIT_v_GetCollectiveVelocity(CML_t_WeightedSample* pt_CollectiveObject)
{
  SLATE_t_Obj_DynamicProperty ObjDynProperty;
  ObjNumber_t   iObj;
  ObjNumber_t   iLastObj = OBJ_INDEX_NO_OBJECT;
  boolean bZOOnly = TRUE;
  boolean b_ObjIsMovingToStationary;
  boolean b_ObjIsRelevant;

  /* Loop over EM Object List */
  for (iObj = (ObjNumber_t)(EM_N_OBJECTS - 1); iObj >= 0; iObj--)
  {
    /* Defining local variables from reference pointer */
    ObjDynProperty = *pt_SITInput->t_RTE.pt_ObjDynProperty(iObj);
    /* Filter for objects with ACC quality */
    if(LA_SUFFICIENT_FUN_PRESEL_QUALITY(iObj) != FALSE)
    {
      /* Now that object is having ACC quality, filter for oncoming and not on EGO lane */
      if ((ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING) &&
#if (FCT_CFG_ACC_LANE_ASSOCIATION) 
          (pt_SITInputModify->t_LAInputModify.pt_ObjLaneState(iObj)->LAInlaneState != OBJ_STATE_INLANE))
#endif
      {
        /* DO NOTHING - Not interested in these objects.*/
      }
      else
      {
        b_ObjIsMovingToStationary=pt_SITInput->t_RTE.b_ObjIsMovingToStationary(iObj);
        /* Select moving constellation, including stopped objects and objects rolling back on EGO lane(!) */
        if ((ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) ||
            (ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING) ||
            (b_ObjIsMovingToStationary))
        {
          pt_CollectiveObject->dSumme += pt_SITInput->pt_FIPOA->t_ObjList[iObj].fAbsVelocity;
          pt_CollectiveObject->dQuadSumme += SQR(pt_SITInput->pt_FIPOA->t_ObjList[iObj].fAbsVelocity);
          pt_CollectiveObject->f_sumOfWeights++;

          iLastObj = iObj;
        }
      } /* Conditions for interesting objects */
    } /* Condition for ACC quality */
  } /* End of FOR loop - EM_N_objects */

  if (pt_CollectiveObject->f_sumOfWeights >= 1.f)
  {
    b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(iLastObj);
    /* only calculate the collective velocity if the single object is not the relevant object */
    if( ((uint8)pt_CollectiveObject->f_sumOfWeights > 1u) ||
         (((uint8)pt_CollectiveObject->f_sumOfWeights == 1u) &&
          (b_ObjIsRelevant == FALSE)))// PRQA S 3689
/* date: 2015-05-15, reviewer: Gangadhar Badiger, reason: It is manually verified, no side effect */
    {  
      /* return the average collective velocity which includes EGO velocity */
      bZOOnly = FALSE;
    }
    else
    {
      /* Do nothing here. Only the OOI-0 is detect (return true) */
    }

    pt_CollectiveObject->dSumme     += *pt_SITInput->t_RTE.pf_EgoLongVel;
    pt_CollectiveObject->dQuadSumme += SQR(*pt_SITInput->t_RTE.pf_EgoLongVel);
    pt_CollectiveObject->f_sumOfWeights++;

    CML_v_ComputeMeanStd(pt_CollectiveObject);
  }

  return bZOOnly;
}
#endif /*!< SIT_CFG_TRAFFIC_ESTIMATION */
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
///@}
#endif /*!< FCT_CFG_ACC_SITUATION */


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

