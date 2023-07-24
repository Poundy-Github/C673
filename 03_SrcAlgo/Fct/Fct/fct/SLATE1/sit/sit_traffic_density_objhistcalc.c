/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_traffic_density_objhistcalc.c

DESCRIPTION:               Calculation of traffic density

AUTHOR:                    Simon Sinnstein

CREATION DATE:             -

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#include "sit_traffic.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)

#if (SIT_CFG_TRAFFIC_DENSITY)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_traffic_density
@{ */

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/
#define SIT_TD_OBJ_QUALITY (80u)               /*!< min allowed object quality */
#define SIT_TD_MIN_LIFETIME (30u)              /*!< min allowed object lifetime */

#define SIT_TD_MAX_DIST_X (90.f)               /*!< max distance for objects in fiel of view */
#define SIT_TD_MAX_DIST_X_EGO (150.f)          /*!< max distance for objects in fiel of view ego lane*/
#define SIT_TD_MIN_DIST_X (5.f)                /*!< min distance for objects in fiel of view */
#define SIT_TD_MAX_HIST_DIST_FOR (250.f)       /*!< max distance for density calculation */
#define SIT_TD_MAX_HIST_DIST_BACK (-250.f)     /*!< min distance for density calculation */
#define SIT_TD_DELETE_BORDER_FOR (350.f)       /*!< max distance for object prediction in historical lists */
#define SIT_TD_DELETE_BORDER_BACK (-350.f)     /*!< min distance for object prediction in historical lists */
#define SIT_TD_INIT_MAX_BORDER (60.f)          /*!< detection border, if outside object kann be lost */
#define SIT_TD_INIT_MIN_BORDER (15.f)          /*!< detection border, if outside object kann be lost */

#define SIT_TD_V_MAX_TRUCK (22.3f)             /*!< max truck velocity */
#define SIT_TD_SYNCHRO_VELOCITY_REL (1.f)      /*!< rel velosity of congested traffic */
#define SIT_TD_SYNCHRO_VELOCITY_ABS (25.f)     /*!< abs velosity of congested traffic */
#define SIT_TD_DEFAULT_REL_VELOCITY_BACK (-5.f)/*!< default rel velocity if no object available */
#define SIT_TD_DEFAULT_REL_VELOCITY_FOR (5.f)  /*!< default rel velocity if no object available */
#define SIT_TD_JAM_VELOCITY (3.5f)             /*!< algo for neighbor lanes works only, if own velosity > JAM_VELOCITY, if velocity smaller - no action */
#define SIT_TD_JAM_VELOCITY_EGO (3.f)          /*!< algo for neighbor lanes works only, if own velosity > JAM_VELOCITY, if velocity smaller - no action */
#define SIT_TD_MIN_DETECTION_VELOCITY (10u)    /*!< min lane detection velocity, lane detection is not working properly at low vel. */
#define SIT_TD_JAM_MEAN_VEL (1.f)               /*!< if mean velocity is below SIT_TD_JAM_MEAN_VEL, than ego density is increased automatically over time */
#define SIT_TD_CAR_LENGTH (6.f)                /*!< length of any car */
#define SIT_TD_TRUCK_LENGTH (19.f)             /*!< lenght of any truck */

#define SIT_TD_CAR_UNIT (1.f)                  /*!< number of vehicle units */
#define SIT_TD_TRUCK_UNIT (2.0f)               /*!< number of vehicle units */

#define SIT_TD_COLLISION_TIME_GAP (0.3f)       /*!< time gap if two objects collide */
#define SIT_TD_NORMAL_TIME_GAP (1.2f)          /*!< normal time gap between two objects */

#define SIT_TD_OBJ_PREDICTION_CLC (45u)        /*!< hysterese if object expires in FoV */
#define SIT_TD_OBJ_HYSTERESE_CLC (45u)         /*!< hysterese if object changes lane */
#define SIT_TD_NO_OBJECT_DELAY (300u)          /*!< no traffic object availible delay */
#define SIT_TD_MAX__OBJECT_AGE (30u)           /*!< 10 seconds * MAX__OBJECT_AGE = max existence time for historical objects */
#define SIT_TD_OBJ_AGE_UNIT (150u)             /*!< 1 unit = 150 radar cycles */
#define SIT_TD_CONF_SWITCH_TIME (150u)         /*!< 15 cycles * 10 seconds todo. replace with cycle time */

#define SIT_TD_INV_VALUE (-1)                  /*!< invalid value */
#define SIT_TD_CONVERT_MCS_TO_MS (0.001f)      /*!< conversion index from microseconds to milliseconds */
#define SIT_TD_VEH_PER_KM_COEF (1000.f)        /*!< conversion index from vehicle per meter to vehicle per kilometer */

#define SIT_TD_DENSITY_GRAD_UP (0.05f)         /*!< max allowed change of density per cycle if increasing */
#define SIT_TD_DENSITY_GRAD_DOWN (0.05f)       /*!< max allowed change of density per cycle if decreasing */

#define SIT_TD_MAX_EGO_DENSITY_1_OBJ (13.f)    /*!< max traffic density in ego lane if only one object detected */

#define SIT_TD_CONF_WEIGHT_ACT_OBJ_ADJ_LANE (25)   /*!< confidence weight factror for act obj. in adj. lane */
#define SIT_TD_CONF_WEIGHT_HIST_OBJ__ADJ_LANE (5)  /*!< confidence weight factror for hist obj. in adj. lane */
#define SIT_TD_CONF_WEIGHT_ACT_OBJ_EGO_LANE (25)   /*!< confidence weight factror for act obj. in ego lane */
#define SIT_TD_CONF_WEIGHT_NO_LANE (70)            /*!< confidence weight factror for no lane */
#define SIT_TD_CONF_WEIGHT_NO_OBJ (50)             /*!< confidence weight factror for no obj. */
#define SIT_TD_CONF_WEIGHT_VELOCITY (15)           /*!< confidence weight velocity factror  */
#define SIT_TD_CONF_WEIGHT_DIST (15)               /*!< confidence weight distance factror */
#define SIT_TD_CONF_TDENSITY_VAL (25.f)            /*!< confidence weight tr. density factror */
#define SIT_TD_CONF_DIST_VAL_EGO_LANE (80.f)       /*!< confidence weight tr. density ego lane factror */
#define SIT_TD_CONF_VEL_MIN (21.f)                 /*!< min velocity for confidence factror */
#define SIT_TD_CONF_VEL_MAX (28.f)                 /*!< max velocity for confidence factror */
#define SIT_TD_CONF_MAX (100u)                     /*!< max confidence */
#define SIT_TD_CONF_MIN (0u)                       /*!< min confidence */

#define SIT_TD_TEN_SEC (150u)                      /*!< should be 10 sec, to be replaced with cycle time logic */

#define SIT_TD_MIN_NUM_OBJ_FOR_TD (2u)             /*!< min object number for traffic density */

#define SIT_TD_MEAS_ID_DENSITY (0x20285000u)
/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void SIT_v_DeleteHistoryObject(t_LaneDensityData* pLaneDensityData, uint8 uiHistIDX);


/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficInit                                                                                    */ /*!

  @brief           Init module to initialize variables

  @description     Init module to initialize variables

		@startuml
		Start
		Partition SIT_v_TrafficInit {
		: Set content of static variable new_uiSITimer;
		: Initialize Density traffic state;
		: Initialize right Density traffic data;
		: Initialize left Density traffic data;
		: Initialize Ego Density traffic data;
		Repeat 
			: Initialize right Density traffic ACT Objects;
			: Initialize left Density traffic ACT Objects;
		Repeat While (For all Traffic Density ACT List)
		Repeat
			: Initialize right Density traffic history Object list;
			: Initialize left Density traffic history Object list;
		Repeat While (For all Traffic Density History list)
		Repeat 
			: Initialize Ego Density traffic ACT Objects;
		Repeat While (For all Traffic Density ACT List Ego size)
		}
		End
		@enduml

  @return          -

  @param[in]       - 

  @glob_in         - 
  @glob_out        SITGlobalDensityData : Global structure for storing traffic density data for all lanes 
                      uiTrafficState : combined traffic state [LaneDensityState as defined in sit_traffic.h]
                      uiJamProbability : Traffic jam probability  [0.f ... 1.f]
                      DensityDataLeft : Structure for storing information about traffic density on left lane 
                      DensityDataRight : Structure for storing information about traffic density on right lane 
                      DensityDataEGO : Structure for storing information about traffic density on EGO lane 
                      For each LaneDensityData
                        fTrafficDensity : traffic density in lane                                                                  [full range of datatype float32]
                        fVrelXMed : relative middle/average velocity in lane                                                       [-330.f   330.f] m/s
                        fMaxPoint : max distance border for traffic density calculation                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        fMinPoint : min distance border for traffic density calculation                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        siConfidence : Confidence of traffic density                                                               [full range of datatype sint8]
                        uiConfidenceCounter : Confidence Counter for confidence change delay                                       [full range of datatype uint8]
                        uiLastCellIDBack : last array index of the historical object in negative area                              [0 ... SIT_TD_HIST_LIST_SIZE]
                        uiLastCellIDFront : last array index of the historical object in positive area                             [0 ... SIT_TD_HIST_LIST_SIZE]
                        uiOldObjectCellID : object to delete if no place in a list                                                 [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                        uiNoObjectCounter : no traffic object available counter                                                    [full range of datatype uint16]
                        uiLaneState : Traffic density state per lane                                                               [full range of datatype uint8]
                      For each active object list
                        a_ActObjList[i].ObjID : Object Number (Object ID)                                                          [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                        a_ActObjList[i].uiClass : Object class                                                                     [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                        a_ActObjList[i].uiLifeTime : object lifetime                                                               [full range of datatype uint16] s
                        a_ActObjList[i].fDistX : Longitudinal distance to object                                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        a_ActObjList[i].uiObjLossCount : counter for lane change hysteresis                                        [full range of datatype uint8]
                        a_ActObjList[i].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list [TRUE, FALSE] 
                      For each history object list
                        a_HistObjList[i].fDistX : Longitudinal distance to object                                                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        a_HistObjList[i].ObjID : Object Number (Object ID)                                                         [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]  
                        a_HistObjList[i].fVabsX : absolute velocity                                                                [-330.f   330.f] m/s
                        a_HistObjList[i].uiObjectAge : existence time for historical object                                        [full range of datatype uint8] s
                        a_HistObjList[i].uiClass : Object class                                                                    [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                        a_HistObjList[i].uiFrontObjCell : last array index of the historical object in positive area               [0 ... SIT_TD_HIST_LIST_SIZE]
                        a_HistObjList[i].uiBackObjCell : last array index of the historical object in negative area                [0 ... SIT_TD_HIST_LIST_SIZE]

  @c_switch_part   SIT_CFG_TRAFFIC_ESTIMATION : Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c)
  @c_switch_full   SIT_CFG_TRAFFIC_DENSITY    : Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION      :  FCT support for ACC SIT (situation) sub-component 

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.07.2014
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
void SIT_v_TrafficInit(void)
{
  uint8 idx;

  SIT_v_uiSITTimer(0);

  SITGlobalDensityData.uiTrafficState = 0u;
  #if (SIT_CFG_TRAFFIC_ESTIMATION)
  SITGlobalDensityData.uiJamProbability = 0.f;
  #endif
  SITGlobalDensityData.DensityDataRight.fTrafficDensity = 0.f;
  SITGlobalDensityData.DensityDataRight.fVrelXMed = 0.f;
  SITGlobalDensityData.DensityDataRight.fMaxPoint = SIT_TD_INIT_MAX_BORDER;
  SITGlobalDensityData.DensityDataRight.fMinPoint = SIT_TD_INIT_MIN_BORDER;
  SITGlobalDensityData.DensityDataRight.siConfidence = 0;
  SITGlobalDensityData.DensityDataRight.uiConfidenceCounter = 0u;
  SITGlobalDensityData.DensityDataRight.uiLastCellIDBack = SIT_TD_HIST_LIST_SIZE;
  SITGlobalDensityData.DensityDataRight.uiLastCellIDFront = SIT_TD_HIST_LIST_SIZE;
  SITGlobalDensityData.DensityDataRight.uiOldObjectCellID = SIT_TD_HIST_LIST_SIZE;
  SITGlobalDensityData.DensityDataRight.uiNoObjectCounter = 0u;
  SITGlobalDensityData.DensityDataRight.uiLaneState = 0u;
  SITGlobalDensityData.DensityDataLeft.fTrafficDensity = 0.f;
  SITGlobalDensityData.DensityDataLeft.fVrelXMed = 0.f;
  SITGlobalDensityData.DensityDataLeft.fMaxPoint = SIT_TD_INIT_MAX_BORDER;
  SITGlobalDensityData.DensityDataLeft.fMinPoint = SIT_TD_INIT_MIN_BORDER;
  SITGlobalDensityData.DensityDataLeft.siConfidence = 0;
  SITGlobalDensityData.DensityDataLeft.uiConfidenceCounter = 0u;
  SITGlobalDensityData.DensityDataLeft.uiLastCellIDBack = SIT_TD_HIST_LIST_SIZE;
  SITGlobalDensityData.DensityDataLeft.uiLastCellIDFront = SIT_TD_HIST_LIST_SIZE;
  SITGlobalDensityData.DensityDataLeft.uiOldObjectCellID = SIT_TD_HIST_LIST_SIZE;
  SITGlobalDensityData.DensityDataLeft.uiNoObjectCounter = 0u;
  SITGlobalDensityData.DensityDataLeft.uiLaneState = 0u;
  SITGlobalDensityData.DensityDataEgo.fTrafficDensity = 0.f;
  SITGlobalDensityData.DensityDataEgo.fVrelXMed = 0.f;
  SITGlobalDensityData.DensityDataEgo.fMaxPoint = 0.f;
  SITGlobalDensityData.DensityDataEgo.fMinPoint = 0.f;
  SITGlobalDensityData.DensityDataEgo.siConfidence = 0;
  SITGlobalDensityData.DensityDataEgo.uiConfidenceCounter = 0u;
  SITGlobalDensityData.DensityDataEgo.uiLaneState = 0u;

  for ( idx=0u; idx < SIT_TD_ACT_LIST_SIZE; idx++ )
  {
    SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].ObjID = OBJ_INDEX_NO_OBJECT;
    SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].uiClass = SLATE_OBJCLASS_UNCLASSIFIED;
    SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].uiLifeTime = 0u;
    SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].fDistX = 0.f;
    SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].uiObjLossCount = 0u;
    SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].bObjExist = FALSE;
    SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].ObjID = OBJ_INDEX_NO_OBJECT;
    SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].uiClass = SLATE_OBJCLASS_UNCLASSIFIED;
    SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].uiLifeTime = 0u;
    SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].fDistX = 0.f;
    SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].uiObjLossCount = 0u;
    SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].bObjExist = FALSE;
  }

  for ( idx=0u; idx < SIT_TD_HIST_LIST_SIZE; idx++ )
  {
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].fDistX = 0.f;
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].ObjID = OBJ_INDEX_NO_OBJECT;
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].fVabsX = 0.f;
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].uiObjectAge = 0u;
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].uiClass = SLATE_OBJCLASS_UNCLASSIFIED;
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].uiFrontObjCell = SIT_TD_HIST_LIST_SIZE;
    SITGlobalDensityData.DensityDataRight.a_HistObjList[idx].uiBackObjCell = SIT_TD_HIST_LIST_SIZE;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].fDistX = 0.f;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].ObjID = OBJ_INDEX_NO_OBJECT;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].fVabsX = 0.f;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].uiObjectAge = 0u;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].uiClass = SLATE_OBJCLASS_UNCLASSIFIED;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].uiFrontObjCell = SIT_TD_HIST_LIST_SIZE;
    SITGlobalDensityData.DensityDataLeft.a_HistObjList[idx].uiBackObjCell = SIT_TD_HIST_LIST_SIZE;
  }

  for ( idx=0u; idx < SIT_TD_ACT_LIST_EGO_SIZE; idx++ )
  {
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].ObjID = OBJ_INDEX_NO_OBJECT;
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].uiClass = SLATE_OBJCLASS_UNCLASSIFIED;
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].uiLifeTime = 0u;
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].fDistX = 0.f;
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].uiObjLossCount = 0u;
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].bObjExist = FALSE;
  }

}

/*************************************************************************************************************************
  Functionname:    SIT_v_CreateActiveObjectList                                                                         */ /*!

  @brief           Create an active object list to be used in traffic density computation

  @description     Create list of existing objects, detects new objects in FoV and delete objects which are not in FoV any more.
                   Here, the time gap and ego lane change are considered.

		@startuml
		Start
		Partition SIT_v_CreateActiveObjectList {
		: Collision gap in meter behind the object;
		If (Object is a truck) then (yes)
			: Collision gap in front is X meter longer;
		Else (no)
			: Collision gap in front of a car;
		Endif
		: Search for object lane change;
		If (No Existed Object) then (yes)
			: Search for object lane change;
		Endif
		If (Object in lane after lane change hysterese) then (yes)
			Repeat
				If (No valid Object saved) then (yes)
					If (No valid free cell number) then (yes)
						: found free cell in array;
					Endif
				Else (no)
					If (No Object Exists) then (yes)
						: search object in the list from last cycle;
						: Update ACT Object List;
					Else (no)
						If (Object is Truck) then (yes)
							: Check for collision objects in the list with new object;	
							: Update correction factor for object collision calculation;
						Else(no)
							: Update correction factor as 0 for object collision calculation;
						Endif
					If (collision detected) then (yes)
						If (Life Cycles is more than Object Life time) then (yes)
							: Update ACT Object List;
						Else (no)
							: Do Nothing;
						Endif
					Endif
				Endif
				If (farest object in the list) then (yes)
					If (valid value of farest Object exists) then (yes)
						If (the loop is interrupted) then (yes)
							: Update Max Object using value at which the loop is interrupted;
						Else (no)
							: Update Max Object;
						Endif
					Endif
				Else (no)
					If (the loop is interrupted) then (yes)
						: Update Max Object using value at which the loop is interrupted;
					Else (no)
						: Update Max Object;
					Endif
				Endif
				If (the loop is interrupted) then (yes)
					: break for loop;
				Endif
			Endif
			Repeat While(For all Objects)
		Endif
		If (No Object Exists) then (yes)
			If (Associated Lane is Ego Lane) then (yes)
				If (Free cells exists and Free cells are less than Length) then (yes)
					: Update ACT Object List for free cell;
				Else (no)
					If (length list of Object list is more than maximum Objects and longitudinal distance of object is less than maximum longitudinal distance) then (yes)
						: Update ACT Object List for Max Object ID;
					Endif
				Endif
			Else (no)
				If (object quality conditions are satisfied) then (yes)
					: Update ACT Object List for Free cell;
				Endif
			Endif
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       iObj : Object Number (Object ID)                                                                      [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in,out]   a_ActObjList : Reference to structure containing active objects for a given lane
                      ObjID : Object Number (Object ID)                                                                  [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      bObjExist : Boolean indicating existence of object, if FALSE add object to historical list         [TRUE, FALSE]
                      uiLifeTime : object lifetime                                                                       [full range of datatype uint16] s
                      uiClass : Object class                                                                             [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      fDistX : Longitudinal distance to object                                                           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      uiObjLossCount : counter for lane change hysteresis                                                [full range of datatype uint8]
  @param[in]       uiLength : Size of the active object list                                                             [0 ... SIT_TD_ACT_LIST_SIZE]
  @param[in]       a_ActObjListEXT : Reference to structure containing active objects for a given lane 
  @param[in]       uiLengthEXT : Size of the active object list                                                          [0 ... SIT_TD_ACT_LIST_SIZE]
  @param[in]       a_ActObjListEXT2 : Reference to structure containing active objects for a given lane   
  @param[in]       uiLengthEXT2 : Size of the active object list                                                         [0 ... SIT_TD_ACT_LIST_SIZE]

  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : velocity of the ego vehicle                                        [-330.f ... 330.f] m/s 
  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX(i) : relative velocity between EGO and object i                        [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pu_ObjLifeCycles(i) : Lifetime of an object i                                      [AlgoCycleCounter_t as defined in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.pt_ObjClassification(i) : Object Classification for object i                       [EM_t_GenObjClassification defined in Rte_Type.h]
  @glob_in         pt_SITInput->t_LAInput.pt_ObjAssociatedLane(i) : associated lane information of an object i           [eAssociatedLane_t as in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.pu_AccObjQuality(i) : Macro to access EM-based function pre-selection information  [full range of unsigned char]
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

  @created         29.07.2014
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_CreateActiveObjectList(const ObjNumber_t iObj, t_ActObject* a_ActObjList, const uint8 uiLength, t_ActObject* a_ActObjListEXT, const uint8 uiLengthEXT, t_ActObject* a_ActObjListEXT2, const uint8 uiLengthEXT2)
{
  boolean       b_ObjExistFlag;
  sint8         siFreeCell; /* number of empty cell in array */
  float32       fCollisionTimeGapF; /* collision gap in front */
  float32       fCollisionTimeGapB; /* collision gap behind */
  float32       fCorrFactor; /* correction factor for object collision calculation */
  uint8         ui_ind;
  uint8         uiMaxObjIDX;
  float32       fDistXObj, fEgoSpeed, fVrelX;
  uint16        uLifeCycles;

  boolean       bBreakFor;  /* flag to indicate that the loop is interrupted */
  uint8         uiBreakVal; /* value at which the loop is interrupted */

  siFreeCell = SIT_TD_INV_VALUE;
  uiMaxObjIDX = (uint8)uiLength;
  b_ObjExistFlag = FALSE;
  bBreakFor   = FALSE;
  uiBreakVal = uiLength;
  fCorrFactor = 0.f;

  /*Defining local variable from input pointer*/
  fDistXObj = *pt_SITInput->t_RTE.pf_ObjLongDisp(iObj);
  fEgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  fVrelX = *pt_SITInput->t_RTE.pf_ObjVrelX(iObj);
  uLifeCycles = *pt_SITInput->t_RTE.pu_ObjLifeCycles(iObj);

  /* collision gap in meter behind the object */
  fCollisionTimeGapB = SIT_TD_CAR_LENGTH + ( (fEgoSpeed + fVrelX ) * SIT_TD_COLLISION_TIME_GAP ); /*!< s */
  if ( SLATE_OBJCLASS_TRUCK == *pt_SITInput->t_RTE.pt_ObjClassification(iObj) )
  {
    /* if object is a truck, collision gap in front is X meter longer */
    fCollisionTimeGapF = SIT_TD_TRUCK_LENGTH + ( (fEgoSpeed + fVrelX ) * SIT_TD_COLLISION_TIME_GAP ); /*!< s */
  }
  else
  {
    /*.collision gap in front of a car.*/
    fCollisionTimeGapF = SIT_TD_CAR_LENGTH + ( (fEgoSpeed + fVrelX ) * SIT_TD_COLLISION_TIME_GAP ); /*!< s */
  }
  /* searching for object lane change */
  b_ObjExistFlag = SIT_b_LaneChangeHandling( iObj, a_ActObjListEXT, uiLengthEXT );
  if ( b_ObjExistFlag == FALSE )
  {
    /* searching for object lane change */
    b_ObjExistFlag = SIT_b_LaneChangeHandling( iObj, a_ActObjListEXT2, uiLengthEXT2 );
  }
  
  /* if object in lane after lane change hysterese */
  if ( b_ObjExistFlag == FALSE )
  {
    for ( ui_ind = 0u; ui_ind < uiLength; ui_ind++ ) /*  */
    {
      if ( OBJ_INDEX_NO_OBJECT == a_ActObjList[ui_ind].ObjID ) /* if no valid object saved */
      {
        if ( SIT_TD_INV_VALUE == siFreeCell ) /* if no valid free cell number */
        {
          /* found free cell in array */
          siFreeCell = (sint8)ui_ind;
        }
      }
      else
      {
        /* searching for object in the list from last cycle */
        if( ( a_ActObjList[ui_ind].bObjExist == FALSE ) && 
          ( a_ActObjList[ui_ind].ObjID == iObj ) && 
          ( a_ActObjList[ui_ind].uiLifeTime <= uLifeCycles ) )
        {
          a_ActObjList[ui_ind].bObjExist = TRUE;
          a_ActObjList[ui_ind].uiClass = *pt_SITInput->t_RTE.pt_ObjClassification(iObj);
          a_ActObjList[ui_ind].fDistX = fDistXObj;
          a_ActObjList[ui_ind].uiLifeTime = uLifeCycles;
          a_ActObjList[ui_ind].uiObjLossCount = 0u;
          b_ObjExistFlag = TRUE;
          //ui_ind = uiLength; /* break */ /* not used to fulfil MISRA-C:2004 Rule 13.6 */
          bBreakFor = TRUE;
          uiBreakVal = uiLength;
        }
        else
        {
          /* check for collision objects in the list with new object */
          if(SLATE_OBJCLASS_TRUCK == a_ActObjList[ui_ind].uiClass)
          {
            fCorrFactor = SIT_TD_TRUCK_LENGTH - SIT_TD_CAR_LENGTH; /*!< s */
          }
          else
          {
            fCorrFactor = 0.f;
          }
          /* if collision detected, oldest object stay in the list */
          if( ( (fDistXObj + fCollisionTimeGapF) > a_ActObjList[ui_ind].fDistX ) && 
              ( (fDistXObj - fCollisionTimeGapB) < (a_ActObjList[ui_ind].fDistX + fCorrFactor) )
            )
          {
            if ( uLifeCycles > a_ActObjList[ui_ind].uiLifeTime )
            {
              a_ActObjList[ui_ind].ObjID = iObj;
              a_ActObjList[ui_ind].uiClass = *pt_SITInput->t_RTE.pt_ObjClassification(iObj);
              a_ActObjList[ui_ind].fDistX = fDistXObj;
              a_ActObjList[ui_ind].uiLifeTime = uLifeCycles;
              a_ActObjList[ui_ind].uiObjLossCount = 0u;
              a_ActObjList[ui_ind].bObjExist = TRUE;
            }
            else
            {
              /* do nothing */
            }
            b_ObjExistFlag = TRUE;
            /* break */ /* not used to fulfil MISRA-C:2004 Rule 13.6 */
            bBreakFor = TRUE;
            uiBreakVal = uiLength;
          }
        }
        /* farest object in the list */
        if (uiLength > uiMaxObjIDX) /* if valid value exists */
        {
          if ( a_ActObjList[uiMaxObjIDX].fDistX < a_ActObjList[ui_ind].fDistX )
          {
            if(bBreakFor==TRUE)
            {
              uiMaxObjIDX = uiBreakVal;
            }
            else
            {              
              uiMaxObjIDX = ui_ind;
            }
          }
        }
        else
        {
          if(bBreakFor==TRUE)
          {
            uiMaxObjIDX = uiBreakVal;
          }
          else
          {              
            uiMaxObjIDX = ui_ind;
          }
        }
        if(bBreakFor==TRUE)
        {
          break; /* break for-loop */
        }
      }
    }
  }
  /* add new object to the list */
  if ( b_ObjExistFlag == FALSE )
  {
    if ( ASSOC_LANE_EGO == *pt_SITInput->t_LAInput.pt_ObjAssociatedLane(iObj) )
    {
      if ( (SIT_TD_INV_VALUE < siFreeCell) && (siFreeCell < uiLength) )
      {
        a_ActObjList[siFreeCell].ObjID = iObj;
        a_ActObjList[siFreeCell].uiClass = *pt_SITInput->t_RTE.pt_ObjClassification(iObj);
        a_ActObjList[siFreeCell].fDistX = fDistXObj;
        a_ActObjList[siFreeCell].uiLifeTime = uLifeCycles;
        a_ActObjList[siFreeCell].bObjExist = TRUE;
      }
      else
      {
        if ( ( uiLength > uiMaxObjIDX ) && ( fDistXObj < a_ActObjList[uiMaxObjIDX].fDistX ) )
        {
          a_ActObjList[uiMaxObjIDX].ObjID = iObj;
          a_ActObjList[uiMaxObjIDX].uiClass = *pt_SITInput->t_RTE.pt_ObjClassification(iObj);
          a_ActObjList[uiMaxObjIDX].fDistX = fDistXObj;
          a_ActObjList[uiMaxObjIDX].uiLifeTime = uLifeCycles;
          a_ActObjList[uiMaxObjIDX].bObjExist = TRUE;
        }
      }
    }
    else
    {
      if ( ( SIT_TD_INV_VALUE < siFreeCell ) && (siFreeCell < uiLength) && ( SIT_TD_OBJ_QUALITY < pt_SITInput->t_RTE.pu_AccObjQuality(iObj) ) ) /* object quality condition */
      {
        a_ActObjList[siFreeCell].ObjID = iObj;
        a_ActObjList[siFreeCell].uiClass = *pt_SITInput->t_RTE.pt_ObjClassification(iObj);
        a_ActObjList[siFreeCell].fDistX = fDistXObj;
        a_ActObjList[siFreeCell].uiLifeTime = uLifeCycles;
        a_ActObjList[siFreeCell].bObjExist = TRUE;
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalculateTrafficDensityEgo                                                                     */ /*!

  @brief           Calculate traffic density for ego lane

  @description     The function loops over all objects in EGO lane within FoV from previous cycle and if the object exists,
                   then average/middle velocity is computed for the given lane. In case object does not exist in active FoV list, update the history FOV list.
                   Check is carried out on a cycle by cycle basis if objects in the relevant lane are available else the object history counter is updated.
                   In the current cycle the minimum and maximum borders are computed for the given lane and based on this the active FoV list and the history FoV list are updated.
                   Based on the updated lists in current cycle, the traffic density, its gradient and the confidence value is computed for the given lane.

		@startuml
		Start
		Partition SIT_v_CalculateTrafficDensityEgo{
		Repeat 
		If (Valid Objects) then (yes)
			If (Object is detected under the maximum Distance) then (yes)
				: Find Max Distance;
			Endif
			If (No Object loss) then (yes)
				: Calculate middle relative velocity for one lane;
			Endif
			If (Objects are lost) then (yes)
				If (Object loss is more than predicted loss) then (yes)
					: Update ACT Object List of Lane Density for Object;
				Else (no)
					: Update ACT Object List of Lane Density for Object;
					If (Object is not Truck) then (yes)
						: Update Density Counter using add car unit;
					Else (no)
						: Update Density Counter using add truck unit;
					Endif
				Endif
			Else(no)
				If (Object is not Truck) then (yes)
					: Update Density Counter using add car unit;
				Else (no)
					: Update Density Counter using add truck unit;
				Endif
			Endif	
		Endif
		Repeat While (For all valid active Object list)
		: Calculate of middle relative velocity for one lane;
		If (Object counter is greater than 0) then (yes)
			: Update Temparory Density;
			If (Object counter is less than Minimum Object counter and Temp Density is more than Maximum Ego Density) then (yes)
				: Update Temp Density;
			Endif
		Else (no)
			: Update Temp Density as 0;
		Endif
		: Calculate Gradient calculation Ego Lane;
		: Calculate Confidence calculation Ego lane;
		If (Traffic Density is less than Confidence Traffic Density) then (yes)
			If (Object Counter is less than Minimum Objects for Traffic Density) then (yes)
				: Update Confidence usinf add confidence weight factror for no object;
			Endif
		Else (no)
			If (Max Point is less than confidence weight tr. density ego lane factor) then (yes) 
				: Update Confidence using add confidence weight distance factor;
			Else(no)
				: Update Confidence using subtract confidence weight distance factor;
			Endif
		Endif
		: Update Confidence, if confidence change the state, wait;
		}
		End
		@enduml

  @return          -

  @param[in,out]   pLaneDensityDataE : Reference to structure containing Lane Density Data for ego lane 
                      a_ActObjList[i].ObjID : Object Number (Object ID)                                                            [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_ActObjList[i].fDistX : Longitudinal distance to object                                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_ActObjList[i].uiObjLossCount : counter for lane change hysteresis                                          [full range of datatype uint8]
                      a_ActObjList[i].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list   [TRUE, FALSE]
                      a_ActObjList[i].uiLifeTime : object lifetime                                                                 [full range of datatype uint16] s
                      a_ActObjList[i].uiClass : Object class                                                                       [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      fVrelXMed : relative middle/average velocity in lane                                                         [-330.f ... 330.f] m/s
                      fMaxPoint : max distance border for traffic density calculation                                              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fMinPoint : min distance border for traffic density calculation                                              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fTrafficDensity : traffic density in lane                                                                    [full range of datatype float32]
                      siConfidence : Confidence of traffic density                                                                 [full range of datatype sint8]
                      uiConfidenceCounter : Confidence Counter for confidence change delay                                         [full range of datatype uint8]

  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX(i) : relative velocity between EGO and object i                                  [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego speed                                                                    [-330.f ... 330.f] m/s
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

  @created         29.07.2014
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_CalculateTrafficDensityEgo( t_LaneDensityDataE* pLaneDensityDataE )
{
  float32     fMinObj; /* min border */
  float32     fMaxObj = 0.f; /* max border */
  float32     fDensityCounter;
  float32     fTempDensity; /* temp traffic density */
  float32     fVrelXMedCounter;
  float32     fVrelXMed;
  sint16      siConfidence;
  uint8       uiObjectCounter;
  uint8       ui_ind;
      
  fVrelXMedCounter = 1.f;
  fVrelXMed = pLaneDensityDataE->fVrelXMed;
  fDensityCounter = 0.f;
  uiObjectCounter = 0u;
  siConfidence = 0;
  /* loop over objects in active list, at the moment only 2 */
  for ( ui_ind = 0u; ui_ind < SIT_TD_ACT_LIST_EGO_SIZE; ui_ind++ )
  {
    if ( OBJ_INDEX_NO_OBJECT < pLaneDensityDataE->a_ActObjList[ui_ind].ObjID ) /* for valid objects */
    {
      if ( fMaxObj < pLaneDensityDataE->a_ActObjList[ui_ind].fDistX ) /* find max distance */
      {
        fMaxObj = pLaneDensityDataE->a_ActObjList[ui_ind].fDistX;
      }
      /* Calculation of middle relative velosity for one lane */
      if ( 0u == pLaneDensityDataE->a_ActObjList[ui_ind].uiObjLossCount )
      {
        fVrelXMed += *pt_SITInput->t_RTE.pf_ObjVrelX(pLaneDensityDataE->a_ActObjList[ui_ind].ObjID);
        fVrelXMedCounter += 1.f;
      }
      /* hysteresis for lost objects */
      if ( pLaneDensityDataE->a_ActObjList[ui_ind].bObjExist == FALSE )
      {
        if (SIT_TD_OBJ_PREDICTION_CLC < pLaneDensityDataE->a_ActObjList[ui_ind].uiObjLossCount)
        {
          pLaneDensityDataE->a_ActObjList[ui_ind].fDistX = 0.f;
          pLaneDensityDataE->a_ActObjList[ui_ind].ObjID = OBJ_INDEX_NO_OBJECT;
          pLaneDensityDataE->a_ActObjList[ui_ind].uiObjLossCount = 0u;
          pLaneDensityDataE->a_ActObjList[ui_ind].uiLifeTime = 0u;
        }
        else
        {
          pLaneDensityDataE->a_ActObjList[ui_ind].fDistX = pLaneDensityDataE->a_ActObjList[ui_ind].fDistX + ( pLaneDensityDataE->fVrelXMed * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
          pLaneDensityDataE->a_ActObjList[ui_ind].bObjExist = TRUE;
          pLaneDensityDataE->a_ActObjList[ui_ind].uiObjLossCount += 1u;
          
          uiObjectCounter += 1u;
          if ( SLATE_OBJCLASS_TRUCK != pLaneDensityDataE->a_ActObjList[ui_ind].uiClass )
          {
            fDensityCounter += SIT_TD_CAR_UNIT;
          }
          else
          {
            fDensityCounter += SIT_TD_TRUCK_UNIT;
          }
        }
      }
      else
      {
        uiObjectCounter += 1u;
        if ( SLATE_OBJCLASS_TRUCK != pLaneDensityDataE->a_ActObjList[ui_ind].uiClass )
        {
          fDensityCounter += SIT_TD_CAR_UNIT;
        }
        else
        {
          fDensityCounter += SIT_TD_TRUCK_UNIT;
        }
      }
    }
  }

  /* Calculation of middle relative velosity for one lane */
  pLaneDensityDataE->fVrelXMed = fVrelXMed / fVrelXMedCounter; /*!< Remark: cannnot be zero  */

  fMinObj = -1.0f * SIT_TD_CAR_LENGTH;
  pLaneDensityDataE->fMaxPoint = fMaxObj;
  pLaneDensityDataE->fMinPoint = fMinObj;

  if ( 0u < uiObjectCounter )
  {
    fTempDensity = ( fDensityCounter * SIT_TD_VEH_PER_KM_COEF ) / ( pLaneDensityDataE->fMaxPoint - pLaneDensityDataE->fMinPoint );
    if ( ( SIT_TD_MIN_NUM_OBJ_FOR_TD > uiObjectCounter ) && ( SIT_TD_MAX_EGO_DENSITY_1_OBJ < fTempDensity ) )
    {
      fTempDensity = SIT_TD_MAX_EGO_DENSITY_1_OBJ;
    }
  }
  else
  {
    fTempDensity = 0.f;
  }


  /* Gradient calculation Ego Lane */
  pLaneDensityDataE->fTrafficDensity += MINMAX_FLOAT(-SIT_TD_DENSITY_GRAD_DOWN, SIT_TD_DENSITY_GRAD_UP, (fTempDensity - pLaneDensityDataE->fTrafficDensity));
  
  /* Confidence calculation Ego lane */
  siConfidence = (sint16) SIT_TD_CONF_WEIGHT_ACT_OBJ_EGO_LANE * uiObjectCounter;
  /* added type cast (sint16) to fulfil MISRA-C 2004 Rule 10.1 */

  if ( SIT_TD_CONF_TDENSITY_VAL > pLaneDensityDataE->fTrafficDensity )
  {
    if (SIT_TD_MIN_NUM_OBJ_FOR_TD > uiObjectCounter )
    {
      siConfidence += SIT_TD_CONF_WEIGHT_NO_OBJ;
    }
  }
  else
  {
    if ( SIT_TD_CONF_DIST_VAL_EGO_LANE > pLaneDensityDataE->fMaxPoint )
    {
      siConfidence += SIT_TD_CONF_WEIGHT_DIST;
    }
    else
    {
      siConfidence -= SIT_TD_CONF_WEIGHT_DIST;
    }
    if ( SIT_TD_CONF_VEL_MIN > ( *pt_SITInput->t_RTE.pf_EgoLongVel + pLaneDensityDataE->fVrelXMed) )
    {
      siConfidence += SIT_TD_CONF_WEIGHT_VELOCITY;
    }
    if ( SIT_TD_CONF_VEL_MAX < ( *pt_SITInput->t_RTE.pf_EgoLongVel + pLaneDensityDataE->fVrelXMed) )
    {
      siConfidence -= SIT_TD_CONF_WEIGHT_VELOCITY;
    }
  }

  siConfidence = (sint16) MINMAX_FLOAT(SIT_TD_CONF_MIN, SIT_TD_CONF_MAX,siConfidence);
  /* added type cast (sint16) to fulfil MISRA-C 2004 Rule 10.1 */

/* if confidence change the state, wait */
  SIT_v_ConfChangeState( &siConfidence, &pLaneDensityDataE->siConfidence, &pLaneDensityDataE->uiConfidenceCounter);

}

/*************************************************************************************************************************
  Functionname:    SIT_v_DeleteHistoryObject                                                                            */ /*!

  @brief           Delete Object from History List

  @description     Delete Object from History List and update the relevant indices

		@startuml
		Start
		Partition SIT_v_DeleteHistoryObject {
		If (object in front exists) then (yes)
			: Update Back Object cell;
			If (last history object will be deleted) then (yes)
				: Update Last Cell Id Front for Lane Density Data;
			Endif
			: Update Front Object Cell;
		Else (no)
			If (History Id is equals to Last cell Id Front) then (yes)
				: Update Last Cell ID Front;
			Endif
		Endif
		If (object back exists) then (yes) 
			: Update Front ObjectID;
			If (last history object will be deleted) then (yes)
				: Update Last Back Cell ID;
			Endif
			: Update Back Object cell;
		Else (no)
			If (last history object will be deleted) then (yes)
				: Update Last Back cell using SIT_TD_HIST_LIST_SIZE; 
			Endif
		Endif
		} 
		End
		@enduml

  @return          -

  @param[in,out]   pLaneDensityData : Structure for storing information about traffic density on a given lane 
                      a_HistObjList[i].fDistX : Longitudinal distance to object                                    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_HistObjList[i].ObjID : Object Number (Object ID)                                           [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_HistObjList[i].fVabsX : absolute velocity                                                  [-330.f   330.f]
                      a_HistObjList[i].uiObjectAge : existence time for historical object                          [full range of datatype uint8] s
                      a_HistObjList[i].uiFrontObjCell : last array index of the historical object in positive area [0 ... SIT_TD_HIST_LIST_SIZE[
                      a_HistObjList[i].uiBackObjCell : last array index of the historical object in negative area  [0 ... SIT_TD_HIST_LIST_SIZE[                   
                      uiLastCellIDBack : last array index of the historical object in negative area                [0 ... SIT_TD_HIST_LIST_SIZE[
                      uiLastCellIDFront : last array index of the historical object in positive area               [0 ... SIT_TD_HIST_LIST_SIZE[
  @param[in]       uiHistIDX : Index of the object in the history list to be deleted                               [0 ... SIT_TD_HIST_LIST_SIZE]

  @glob_in         - 
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

  @created         29.07.2014
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void SIT_v_DeleteHistoryObject(t_LaneDensityData* pLaneDensityData, uint8 uiHistIDX)
{
  pLaneDensityData->a_HistObjList[uiHistIDX].fDistX = 0.f;
  pLaneDensityData->a_HistObjList[uiHistIDX].ObjID = OBJ_INDEX_NO_OBJECT;
  pLaneDensityData->a_HistObjList[uiHistIDX].fVabsX = 0.f;
  pLaneDensityData->a_HistObjList[uiHistIDX].uiObjectAge = 0u;

  if ( OBJ_INDEX_NO_OBJECT > (sint8) pLaneDensityData->a_HistObjList[uiHistIDX].uiFrontObjCell ) /* if object in front exists */
    /* added type cast to (sint8) to fulfil MISRA-C 2004 Rule 13.7 */
  {
    pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[uiHistIDX].uiFrontObjCell].uiBackObjCell = SIT_TD_HIST_LIST_SIZE;
    if ( uiHistIDX == pLaneDensityData->uiLastCellIDFront ) /* if last history object will be deleted */
    {
      pLaneDensityData->uiLastCellIDFront = pLaneDensityData->a_HistObjList[uiHistIDX].uiFrontObjCell;
    }
    pLaneDensityData->a_HistObjList[uiHistIDX].uiFrontObjCell = SIT_TD_HIST_LIST_SIZE;
  }
  else /* if no object in front exists */
  {
    if ( uiHistIDX == pLaneDensityData->uiLastCellIDFront )
    {
      pLaneDensityData->uiLastCellIDFront = SIT_TD_HIST_LIST_SIZE;
    }
  }
  if ( SIT_TD_HIST_LIST_SIZE > pLaneDensityData->a_HistObjList[uiHistIDX].uiBackObjCell ) /* if object back exists */
  {
    pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[uiHistIDX].uiBackObjCell].uiFrontObjCell = SIT_TD_HIST_LIST_SIZE;
    if ( uiHistIDX == pLaneDensityData->uiLastCellIDBack ) /* if last history object will be deleted */
    {
      pLaneDensityData->uiLastCellIDBack = pLaneDensityData->a_HistObjList[uiHistIDX].uiBackObjCell;
    }
    pLaneDensityData->a_HistObjList[uiHistIDX].uiBackObjCell = SIT_TD_HIST_LIST_SIZE;
  }
  else
  {
    if ( uiHistIDX == pLaneDensityData->uiLastCellIDBack )
    {
      pLaneDensityData->uiLastCellIDBack = SIT_TD_HIST_LIST_SIZE;
    }
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_b_LaneChangeHandling                                                                             */ /*!

  @brief           Function to handle lane change hysteresis for object in FoV

  @description     Function to handle lane change hysteresis for object in FoV

		@startuml
		Start
		Partition SIT_b_LaneChangeHandling {
		Repeat
			If (check if the object was found and Life Time < Object Life cycles and Longitudinal distance > SIT_TD_INIT_MIN_BORDER) then (yes)
				: Set done flag to abort loop;
				If (if object loss count threshold is not exceeded) then (yes)
					: Update ACT Object List;
					Note Left : Object to be exists, \nLongitudinal Distance, \nLife Time, \nObject Loss Count and \nObject exist flag
				Else (no)
					: Reset ACT Object List;
				Endif
			Endif
		Repeat While (until found object or object list processed)
		}
		End
		@enduml

  @return          b_ObjExistFlag: boolean [TRUE, FALSE]

  @param[in]       iObj : Object Number (Object ID)                                                                              [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in,out]   a_ActObjListEXT : Reference to structure containing active objects for a given lane                           
                      a_ActObjList[i].ObjID : Object Number (Object ID)                                                          [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_ActObjList[i].uiLifeTime : Object class                                                                  [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      a_ActObjList[i].fDistX : Longitudinal distance to object                                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_ActObjList[i].uiObjLossCount : counter for lane change hysteresis                                        [full range of datatype uint8]
                      a_ActObjList[i].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list [TRUE, FALSE] 
                      a_ActObjList[i].uiClass : Object class                                                                     [SLATE_t_Obj_CLassification as defined Rte_Type.h]                      
  @param[in]       uiLengthEXT : Size of the active object list                                                                  [0 ... SIT_TD_ACT_LIST_SIZE]

  @glob_in         pt_SITInput->t_RTE.pu_ObjLifeCycles(i) : Lifetime of an object i                                              [AlgoCycleCounter_t as defined in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
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

  @created         29.07.2014
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
boolean SIT_b_LaneChangeHandling( const ObjNumber_t iObj, t_ActObject* a_ActObjListEXT, const uint8 uiLengthEXT )
{  
  boolean       b_ObjExistFlag;
  boolean       b_Done;
  uint8         ui_ind;

  b_ObjExistFlag  = FALSE;
  b_Done          = FALSE;
  /* Try finding the given object - loop until found (b_Done) or object list processed */
  for ( ui_ind = 0u; (ui_ind < uiLengthEXT) && (!b_Done); ui_ind++ )
  {
    if( ( a_ActObjListEXT[ui_ind].ObjID == iObj ) && 
        ( a_ActObjListEXT[ui_ind].uiLifeTime < *pt_SITInput->t_RTE.pu_ObjLifeCycles(iObj) ) && 
        ( SIT_TD_INIT_MIN_BORDER < a_ActObjListEXT[ui_ind].fDistX ) 
      )
    {
      /* Set done flag to abort loop, since the object was found */
      b_Done = TRUE;
      /* If object loss count threshold not exceeded, then update object state */
      if ( SIT_TD_OBJ_HYSTERESE_CLC > a_ActObjListEXT[ui_ind].uiObjLossCount )
      {
        a_ActObjListEXT[ui_ind].bObjExist = TRUE;
        a_ActObjListEXT[ui_ind].fDistX = *pt_SITInput->t_RTE.pf_ObjLongDisp(iObj);
        a_ActObjListEXT[ui_ind].uiLifeTime = *pt_SITInput->t_RTE.pu_ObjLifeCycles(iObj);
        a_ActObjListEXT[ui_ind].uiObjLossCount += 1u;
        b_ObjExistFlag = TRUE;
      }
      else
      { /* set to inv since object loss count threshold exceeded */
        a_ActObjListEXT[ui_ind].ObjID = OBJ_INDEX_NO_OBJECT;
        a_ActObjListEXT[ui_ind].uiLifeTime = 0u;
        a_ActObjListEXT[ui_ind].bObjExist = FALSE;
        a_ActObjListEXT[ui_ind].uiObjLossCount = 0u;
      }
    }
  }
  
  return b_ObjExistFlag;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalculateTrafficDensity_mainloop                                                               */ /*!

  @brief           Traffic Density Calculation 

  @description     This is a part of SICalculateTrafficDensity, the function was split to reduce size and increase readability (QAC, function size)
                   Multi-object apporoach: Different cases are considered based on several objects in the FOV. Object class is considered.

		@startuml
		Start
		Partition SIT_v_CalculateTrafficDensity_mainloop {
		Repeat 
			If (valid object in the cell) then (yes)
				If (SIT Timer is SIT_TD_OBJ_AGE_UNIT) then (yes)
					: increment object age in history list;
				Endif
				If (no storage memory in the history list) then (yes)
					: Update Old Object Cell; 
				Endif
				If (object with negative distance) then (yes)
					If (object in FoV available in front) then (yes)
						If (object in front exists) then (yes)
							: Calculate distance to the next object;
							If (object in front slower) then (yes)
								If (distance gap too big) then (yes)
									: Update Longitudinal Distance;
								Else (no)
									: Update Absolute Velocity towards to X Direction;
									:  Update Longitudinal Distance;
								Endif
							Else (no)
								If (distance gap too small) then (yes)
									: gap will be increased;
									: Update Longitudinal Distance;
								Else (no)
									: Update Absolute Velocity towards to X Direction;
									:  Update Longitudinal Distance;
								Endif
							Endif
						Else (no)
							: Calculate Distance to next Object;
							If (object in front slower) then (yes)
								If (No Trucks) then (yes)
									: Calculate longitudinal distance of historical objects;
								Else (no)
									: Calculate longitudinal distance of historical objects;
									: Calculate Absolute Velocity towards X Direction;					
								Endif
								If (first hist object should not drive in FoV) then (yes)
									: Calculate Longitudinal Distance;
								Else (no)
									: Calculate Absolute Velocity towards X Direction;	
								Endif
							Else (no)
								If (Object is Truck and its velocity is less than 80kph) then (yes)
									: Update Absolute Velocity towards X Direction as maximum velocity of truck;
									: Calculate Longitudinal Distance;
								Else (no)
									If (Distance gap too small) then (yes)
										: gap will be increased;
										: Calculate longitudinal distance of historical objects;
									Else (no)
										: Calculate longitudinal distance of historical objects;
									Endif
									If (object should not drive in FoV) then (yes)
										: Update Absolute Velocity towards to X Direction;
										: Update Longitudinal Distance;
									Else (no)
										: Update Absolute Velocity towards to X Direction;
									Endif
								Endif
							Endif
						Endif
					Else (no)
						If (a period of time no object in FoV) then (yes)
							: history list will be cleared;
						Endif
						If (Object is Truck and its velocity is less than 80kph) then (yes)
							: Update Absolute Velocity towards X Direction as maximum velocity of truck;
							:  Update Longitudinal Distance;
						Else (no)
							If (object in front exists) then (yes)
								: Calculate Distance to the next Object;
								If (object in front slower) then (yes)
									If (distance gap too big) then (yes)
										: Calculate Longitudinal Distance;
									Else (no)
										: Calculate Absolute Velocity towards X Direction;
										: Calculate Longitudinal Distance;
									Endif
								Else (no)
									If (distance gap too small) then (yes)
										: gap will be increased;
										: Calculate Longitudinal Distance;
									Else (no)
										: Calculate Absolute Velocity towards X Direction;
										: Calculate Longitudinal Distance;
									Endif
								Endif
							Else (no)
								If (Object should not drive in FoV) then (yes)
									: Calculate Absolute Velocity towards X Direction;
									: Calculate Longitudinal Distance;
								Else (no)
									: Calculate Absolute Velocity;
								Endif
							Endif
						Endif
					Endif
					Else (no)
						If (object in FoV exists) then (yes)
							If (Object back exists) then (yes)
								: Calculate distance to next object;
								If (Object back slower) then (yes)
									If (distance gap too big) then (yes)
										: Calculate Longitudinal Distance;
									Else (no)
										: Calculate velocity and Distance to X Direction;
									Endif
								Else (no)
									If (Distance gap too small) then (yes)
										: Calculate Longitudinal Distance;
									Else (no)
										:  Calculate velocity and Distance to X Direction;
									Endif
								Endif
							Else (no)
								: Calculate longitudinal distance of historical objects;
								If (object should not drive in FoV) then (yes)
									: Calculate Longitudinal Distance;
								Else (no)
									:  Calculate velocity and Distance to X Direction;
								Endif
							Endif
						Else (no)
							If (a period of time no object in FoV) then (yes)
								: history list will be cleared;
							Endif
							If (Object back exists) then (yes)
								: Calculate distance to the next object;
								If (Object back slower) then (yes)
									If (distance gap too big) then (yes)
										: Calculate Longitudinal Distance;
									Else (no)
										: Calculate velocity and Distance to X Direction;
									Endif
								Else (no)
									If (distance gap too small) then (yes)
										: Calculate Longitudinal Distance;
									Else (no)
										: Calculate Velocity and Distance to X Direction;
									Endif
								Endif
							Else (no)
								If (longitudinal distance of historical objects is more than maximumborder) then (yes)
									: Calculate Velocity and Distance to X Direction;
								Else (no)
									: Calculate Absolute Velocity towards X Direction;
								Endif
							Endif
						Endif
					Endif
					If (Object is deleted from History Object) then (yes)
						If (Object Age is more than maximum Object Age) then (yes)
							: Reset Min max Borders;
						Endif
						: Delete Object from History list;
					Else (no)
						Repeat 
							If (collision history object exists) then (yes)
								: Delete Object from history List ;
							Endif
						Repeat While (For ACT Objects List)
						: Find min and max distance;
						: Find Oldest Object;
					Endif
				Endif
		Repeat While (For Traffic Density History List)
		}
		End
		@enduml

  @return          -

  @param[in,out]   pLaneDensityData : Structure for storing information about traffic density on a given lane 
                      a_ActObjList[idx].ObjID : Object Number (Object ID)                                                                 [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_ActObjList[idx].fDistX : Longitudinal distance to object                                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_ActObjList[idx].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list        [TRUE, FALSE]
                      a_HistObjList[idx].fDistX : Longitudinal distance to object                                                         [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_HistObjList[idx].uiFrontObjCell : last array index of the historical object in positive area                      [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_HistObjList[idx].uiBackObjCell : last array index of the historical object in negative area                       [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_HistObjList[idx].uiObjectAge : existence time for historical object                                               [full range of datatype uint8] s
                      a_HistObjList[idx].fVabsX : absolute velocity                                                                       [-330.f ... 330.f] m/s
                      a_HistObjList[idx].uiClass : Object class                                                                           [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      uiNoObjectCounter : no traffic object available counter                                                             [full range of datatype uint16]
                      fVrelXMed : relative middle/average velocity in lane                                                                [-330.f ... 330.f] m/s
                      fMaxPoint : max distance border for traffic density calculation                                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fMinPoint : min distance border for traffic density calculation                                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   puiOldObjCellID : Reference to object to be deleted if no place in a list                                              [0 ... SIT_TD_HIST_LIST_SIZE]
  @param[in,out]   puiMinObjIDX : Reference to index of min object in FoV                                                                 [0 ... SIT_TD_ACT_LIST_SIZE]
  @param[in,out]   puiMaxObjIDX : Reference to index of max object in FoV                                                                 [0 ... SIT_TD_ACT_LIST_SIZE]
  @param[in,out]   puiMemoryListCounter : Reference to counter for historical objects, needed for detection of storage capacity in array  [0 ... SIT_TD_HIST_LIST_SIZE]
  @param[in]       uiSITimer : SIT Timer/Counter for traffic density                                                                      [full range of datatype uint8]
  @param[in,out]   pfMinObj : Reference to min borders of 1 cycle for calculation of traffic density                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pfMaxObj : Reference to max borders of 1 cycle for calculation of traffic dencity                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pfTempDensity : Reference to temp value of traffic density                                                             [full range of datatype float32]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed                                                                           [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX(i) : relative velocity between EGO and object i                                         [-330.f ... 330.f] m/s
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

  @created         29.07.2014
  @changed         17.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_CalculateTrafficDensity_mainloop( t_LaneDensityData* pLaneDensityData,  uint8     *puiOldObjCellID,  uint8     *puiMinObjIDX,  uint8     *puiMaxObjIDX,
  uint8     *puiMemoryListCounter,  uint8     uiSITimer,  float32   *pfMinObj,  float32   *pfMaxObj,  float32   *pfTempDensity  )
{
  uint8     ui_ind              = 0u;
  uint8     ui_ind2             = 0u;
  uint8     uiMinObjIDX         = *puiMinObjIDX;
  uint8     uiMaxObjIDX         = *puiMaxObjIDX;
  uint8     uiMemoryListCounter = *puiMemoryListCounter;  /* counter for historical objects, needed for detection of storage capacity in array */
  float32   fCollisionTimeGap;                    /* minimal possible time gap between 2 objects */
  float32   fNormalTimeGap      = 0.f;            /* normal TG between 2 objects, needed for object prediction in historical lists */
  float32   fTempDist           = 0.f;            /* temp value of object distance */
  float32   fMinObj             = *pfMinObj;      /* min borders of 1 cycle for calculation of traffic density */
  float32   fMaxObj             = *pfMaxObj;      /* max borders of 1 cycle for calculation of traffic density */
  float32   fTempDensity        = *pfTempDensity; /* temp value of traffic density */

  /*Defining local variable for input*/
  float32 fEgoVel = *pt_SITInput->t_RTE.pf_EgoLongVel;
  float32 fVrelObj = *pt_SITInput->t_RTE.pf_ObjVrelX(pLaneDensityData->a_ActObjList[uiMinObjIDX].ObjID);

  for ( ui_ind = 0u; ui_ind < SIT_TD_HIST_LIST_SIZE; ui_ind++ )
  {
    if ( OBJ_INDEX_NO_OBJECT < pLaneDensityData->a_HistObjList[ui_ind].ObjID ) /* if valid object in the cell */
    {
      if ( SIT_TD_OBJ_AGE_UNIT == uiSITimer ) /* increment object age in history list */
      {
        pLaneDensityData->a_HistObjList[ui_ind].uiObjectAge += 1u;
      }
      /* handling if no storage memory in the history list */
      if ( SIT_TD_HIST_LIST_SIZE == *puiOldObjCellID )
      {
        *puiOldObjCellID = ui_ind;
      }
      
      if ( SIT_TD_INIT_MIN_BORDER > pLaneDensityData->a_HistObjList[ui_ind].fDistX ) /* handling for object with negative distance */
      {
        if (SIT_TD_ACT_LIST_SIZE > uiMinObjIDX) /* if object in FoV available in front */
        {
          if ( (SIT_TD_HIST_LIST_SIZE) > pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell ) /* if object in front exists */
          {
            fNormalTimeGap = SIT_TD_CAR_LENGTH + ( pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX * SIT_TD_NORMAL_TIME_GAP ); /* distance to the next object */
            if ( pLaneDensityData->a_HistObjList[ui_ind].fVabsX > pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX ) /* if object in front slower */
            {
              if (fNormalTimeGap < (pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fDistX - pLaneDensityData->a_HistObjList[ui_ind].fDistX)) /* if distance gap too big */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( (pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
            }
            else /* if object in front not slower */
            {
              if ( fNormalTimeGap > (pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fDistX - pLaneDensityData->a_HistObjList[ui_ind].fDistX) ) /* if distance gap too small, gap will be increased */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else /* distance gap stay constant */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
            }
          }
          else /* if no history object in front exists, first object or truck */
          {
            fNormalTimeGap = SIT_TD_CAR_LENGTH + (( fEgoVel + fVrelObj) * SIT_TD_NORMAL_TIME_GAP ); /* distance to the next object */
            if ( pLaneDensityData->a_HistObjList[ui_ind].fVabsX > (fEgoVel + fVrelObj) ) /* if object in front slower */
            {
              if ((!( SLATE_OBJCLASS_TRUCK == pLaneDensityData->a_HistObjList[ui_ind].uiClass )) && ( fNormalTimeGap < (pLaneDensityData->a_ActObjList[uiMinObjIDX].fDistX - pLaneDensityData->a_HistObjList[ui_ind].fDistX) ) ) /* handling for not trucks */
              {
                fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( (pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else
              {
                fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( fVrelObj * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = ( fEgoVel + fVrelObj);
              }
              if (SIT_TD_INIT_MIN_BORDER > fTempDist) /* first hist object should not drive in FoV */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = fTempDist;
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = fEgoVel;
              }
            }
            else /* if active object is not slower, as hist object */
            {
              if ( ( SLATE_OBJCLASS_TRUCK == pLaneDensityData->a_HistObjList[ui_ind].uiClass ) && (fVrelObj > ( SIT_TD_V_MAX_TRUCK - fEgoVel )) ) /* handling for trucks, V <= 80kph */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = SIT_TD_V_MAX_TRUCK;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( ( SIT_TD_V_MAX_TRUCK - fEgoVel ) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else /* if not trucks */
              {
                if ( fNormalTimeGap > (pLaneDensityData->a_ActObjList[uiMinObjIDX].fDistX - pLaneDensityData->a_HistObjList[ui_ind].fDistX) ) /* if distance gap too small, gap will be increased */
                {
                  fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                }
                else
                {
                  fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + (fVrelObj * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                }
                if (SIT_TD_INIT_MIN_BORDER > fTempDist) /* object should not drive in FoV */
                {
                  pLaneDensityData->a_HistObjList[ui_ind].fDistX = fTempDist;
                  pLaneDensityData->a_HistObjList[ui_ind].fVabsX = ( fEgoVel + fVrelObj);
                }
                else
                {
                  pLaneDensityData->a_HistObjList[ui_ind].fVabsX = fEgoVel;
                }
              }
            }
          }
        }
        else  /* if no active object available */
        {
           /* if a period of time no object in FoV, hist list will be cleared */
          if ((SIT_TD_NO_OBJECT_DELAY < pLaneDensityData->uiNoObjectCounter) && (SIT_TD_DEFAULT_REL_VELOCITY_BACK < pLaneDensityData->fVrelXMed ))
          {
            pLaneDensityData->fVrelXMed = SIT_TD_DEFAULT_REL_VELOCITY_BACK;
          }
          if ( ( SLATE_OBJCLASS_TRUCK == pLaneDensityData->a_HistObjList[ui_ind].uiClass ) && (pLaneDensityData->fVrelXMed > ( SIT_TD_V_MAX_TRUCK - fEgoVel )) ) /* handling for trucks, V <= 80kph */
          {
            pLaneDensityData->a_HistObjList[ui_ind].fVabsX = SIT_TD_V_MAX_TRUCK;
            pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( ( SIT_TD_V_MAX_TRUCK - fEgoVel ) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
          }
          else /* if object not truck */
          {
            if ( (SIT_TD_HIST_LIST_SIZE) > pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell )  /* if object in front exists */
            {
              fNormalTimeGap = SIT_TD_CAR_LENGTH + ( pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX * SIT_TD_NORMAL_TIME_GAP ); /* distance to the next object */
              if ( pLaneDensityData->a_HistObjList[ui_ind].fVabsX > pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX ) /* if object in front slower */
              {
                if (fNormalTimeGap < (pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fDistX - pLaneDensityData->a_HistObjList[ui_ind].fDistX)) /* if distance gap too big */
                {
                  pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( (pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                }
                else
                {
                  pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX;
                  pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                }
              }
              else /* if object in front not slower */
              {
                if ( fNormalTimeGap > (pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fDistX - pLaneDensityData->a_HistObjList[ui_ind].fDistX) ) /* if distance gap too small, gap will be increased */
                {
                  pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                }
                else /* distance gap stay constant */
                {
                  pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiFrontObjCell].fVabsX;
                  pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
                }
              }
            }
            else /* no object in front, first object */
            {
              fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( pLaneDensityData->fVrelXMed * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              if (SIT_TD_INIT_MIN_BORDER > fTempDist) /* object should not drive in FoV */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = fTempDist;
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = ( fEgoVel + pLaneDensityData->fVrelXMed);
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = fEgoVel;
              }
            }
          }
        }
      }
      else /* if object from positive area, before FoV */
      {
        if ( SIT_TD_ACT_LIST_SIZE > uiMaxObjIDX ) /* if object in FoV exists */
        {
          if ( (SIT_TD_HIST_LIST_SIZE) > pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell ) /* if object back exists */
          {
            fNormalTimeGap = SIT_TD_CAR_LENGTH + ( pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX * SIT_TD_NORMAL_TIME_GAP ); /* distance to the next object */
            if ( pLaneDensityData->a_HistObjList[ui_ind].fVabsX > pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX ) /* if object back slower */
            {
              if (fNormalTimeGap > (pLaneDensityData->a_HistObjList[ui_ind].fDistX - pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fDistX )) /* if distance gap too big */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
            }
            else /* not slower */
            {
              if ( fNormalTimeGap < (pLaneDensityData->a_HistObjList[ui_ind].fDistX - pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fDistX) ) /* if distance gap too small */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
            }
          }
          else /* no object back, first object */
          {
            fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( *pt_SITInput->t_RTE.pf_ObjVrelX(pLaneDensityData->a_ActObjList[uiMaxObjIDX].ObjID) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
            
            if (SIT_TD_INIT_MAX_BORDER < fTempDist) /* object should not drive in FoV */
            {
              pLaneDensityData->a_HistObjList[ui_ind].fDistX = fTempDist;
              pLaneDensityData->a_HistObjList[ui_ind].fVabsX = ( fEgoVel + *pt_SITInput->t_RTE.pf_ObjVrelX(pLaneDensityData->a_ActObjList[uiMaxObjIDX].ObjID));
            }
            else
            {
              pLaneDensityData->a_HistObjList[ui_ind].fVabsX = fEgoVel;
            }
          }
        }
        else /* no object in FoV exists */
        {
           /* if a period of time no object in FoV, hist list will be cleared */
          if ((SIT_TD_NO_OBJECT_DELAY < pLaneDensityData->uiNoObjectCounter) && (SIT_TD_DEFAULT_REL_VELOCITY_FOR > pLaneDensityData->fVrelXMed ))
          {
            pLaneDensityData->fVrelXMed = SIT_TD_DEFAULT_REL_VELOCITY_FOR;
          }
          if ( (SIT_TD_HIST_LIST_SIZE) > pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell ) /* if object back exists */
          {
            fNormalTimeGap = SIT_TD_CAR_LENGTH + ( pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX * SIT_TD_NORMAL_TIME_GAP ); /* distance to the next object */
            if ( pLaneDensityData->a_HistObjList[ui_ind].fVabsX > pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX ) /* if object back slower */
            {
              if (fNormalTimeGap > (pLaneDensityData->a_HistObjList[ui_ind].fDistX - pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fDistX )) /* if distance gap too big */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
            }
            else /* not slower */
            {
              if ( fNormalTimeGap < (pLaneDensityData->a_HistObjList[ui_ind].fDistX - pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fDistX) ) /* if distance gap too small */
              {
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
              else
              {
                pLaneDensityData->a_HistObjList[ui_ind].fVabsX = pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[ui_ind].uiBackObjCell].fVabsX;
                pLaneDensityData->a_HistObjList[ui_ind].fDistX = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ((pLaneDensityData->a_HistObjList[ui_ind].fVabsX - fEgoVel) * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
              }
            }
          }
          else /* no object back */
          {
            fTempDist = pLaneDensityData->a_HistObjList[ui_ind].fDistX + ( pLaneDensityData->fVrelXMed * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
            if (SIT_TD_INIT_MAX_BORDER < fTempDist)
            {
              pLaneDensityData->a_HistObjList[ui_ind].fDistX = fTempDist;
              pLaneDensityData->a_HistObjList[ui_ind].fVabsX = ( fEgoVel + pLaneDensityData->fVrelXMed);
            }
            else
            {
              pLaneDensityData->a_HistObjList[ui_ind].fVabsX = fEgoVel;
            }
          }
        }
      }
      /* delete hist object */
      if ( ( SIT_TD_DELETE_BORDER_FOR < pLaneDensityData->a_HistObjList[ui_ind].fDistX ) || ( SIT_TD_DELETE_BORDER_BACK > pLaneDensityData->a_HistObjList[ui_ind].fDistX )
          || ( ( SIT_TD_INIT_MAX_BORDER > pLaneDensityData->a_HistObjList[ui_ind].fDistX ) && (SIT_TD_INIT_MIN_BORDER < pLaneDensityData->a_HistObjList[ui_ind].fDistX ) )
          || (SIT_TD_MAX__OBJECT_AGE < pLaneDensityData->a_HistObjList[ui_ind].uiObjectAge ))
      {
        if ( SIT_TD_MAX__OBJECT_AGE < pLaneDensityData->a_HistObjList[ui_ind].uiObjectAge )
        {
           /* reset min max borders */
          pLaneDensityData->fMaxPoint = fMaxObj;
          pLaneDensityData->fMinPoint = fMinObj;
        }
        /* delete object from history list */
        SIT_v_DeleteHistoryObject( pLaneDensityData, ui_ind );
      }
      else
      {
        uiMemoryListCounter += 1u;
        ui_ind2 = 0u;
        while ( ui_ind2 < SIT_TD_ACT_LIST_SIZE ) /* optimieren, ohne scheife, min max aktive objekt verwenden */
        {
          if ( SIT_TD_INV_VALUE < pLaneDensityData->a_ActObjList[ui_ind2].ObjID ) /* check collision history object with object from FoV */
          {
            fCollisionTimeGap = SIT_TD_CAR_LENGTH + ( (fEgoVel + *pt_SITInput->t_RTE.pf_ObjVrelX(pLaneDensityData->a_ActObjList[ui_ind2].ObjID)) * SIT_TD_COLLISION_TIME_GAP );
            if ( ( pLaneDensityData->a_ActObjList[ui_ind2].bObjExist ) && ( (pLaneDensityData->a_ActObjList[ui_ind2].fDistX + fCollisionTimeGap) > pLaneDensityData->a_HistObjList[ui_ind].fDistX ) 
                 && ( (pLaneDensityData->a_ActObjList[ui_ind2].fDistX - fCollisionTimeGap) < pLaneDensityData->a_HistObjList[ui_ind].fDistX ) )
            {
              /* delete object from history list */
              SIT_v_DeleteHistoryObject( pLaneDensityData, ui_ind );
              
              uiMemoryListCounter -= 1u; /*!< Remark: counter cannot become smaller than 0 (set to 1 before the while-loop) */
              /* Abort the loop (replacement for break) */
              ui_ind2 = SIT_TD_ACT_LIST_SIZE;
            }
          }
          ui_ind2 += 1u;
        }
        /* find min and max distance */
        if ( fMinObj > pLaneDensityData->a_HistObjList[ui_ind].fDistX )
        {
          fMinObj = pLaneDensityData->a_HistObjList[ui_ind].fDistX;
        }
        if ( fMaxObj < pLaneDensityData->a_HistObjList[ui_ind].fDistX )
        {
          fMaxObj = pLaneDensityData->a_HistObjList[ui_ind].fDistX;
        }
        /* find oldest object */
        if ( pLaneDensityData->a_HistObjList[ui_ind].uiObjectAge > pLaneDensityData->a_HistObjList[*puiOldObjCellID].uiObjectAge )
        {
          *puiOldObjCellID = ui_ind;
        }
      }
    }
  }

  *puiMinObjIDX = uiMinObjIDX;
  *puiMaxObjIDX = uiMaxObjIDX;
  *puiMemoryListCounter = uiMemoryListCounter;
  *pfMinObj     = fMinObj;
  *pfMaxObj     = fMaxObj; 
  *pfTempDensity        = fTempDensity ;
}
///@}
#endif /*!< SIT_CFG_TRAFFIC_DENSITY */

#endif /*!< FCT_CFG_ACC_SITUATION */


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

