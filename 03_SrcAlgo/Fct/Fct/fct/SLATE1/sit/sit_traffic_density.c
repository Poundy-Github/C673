/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_traffic_density.c

DESCRIPTION:               Calculation of traffic density

AUTHOR:                    Simon Sinnstein

CREATION DATE:             -

VERSION:                   $Revision: 1.11 $

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
@defgroup sit_traffic_density Sit Traffic Density
@ingroup sit
@brief          This module clacultes the traffic density. \n\n
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
#define SIT_TD_OBJ_QUALITY (80u)               /*!< min allowed object quality */
#define SIT_TD_MIN_LIFETIME (30u)              /*!< min allowed object lifetime */

#define SIT_TD_MAX_DIST_X (90.f)               /*!< max distance for objects in field of view */
#define SIT_TD_MAX_DIST_X_EGO (150.f)          /*!< max distance for objects in field of view ego lane*/
#define SIT_TD_MIN_DIST_X (5.f)                /*!< min distance for objects in field of view */
#define SIT_TD_MAX_HIST_DIST_FOR (250.f)       /*!< max distance for density calculation */
#define SIT_TD_MAX_HIST_DIST_BACK (-250.f)     /*!< min distance for density calculation */
#define SIT_TD_DELETE_BORDER_FOR (350.f)       /*!< max distance for object prediction in historical lists */
#define SIT_TD_DELETE_BORDER_BACK (-350.f)     /*!< min distance for object prediction in historical lists */
#define SIT_TD_INIT_MAX_BORDER (60.f)          /*!< detection border, if outside object can be lost */
#define SIT_TD_INIT_MIN_BORDER (15.f)          /*!< detection border, if outside object can be lost */

#define SIT_TD_V_MAX_TRUCK (22.3f)             /*!< max truck velocity */
#define SIT_TD_SYNCHRO_VELOCITY_REL (1.f)      /*!< rel velocity of congested traffic */
#define SIT_TD_SYNCHRO_VELOCITY_ABS (25.f)     /*!< abs velocity of congested traffic */
#define SIT_TD_DEFAULT_REL_VELOCITY_BACK (-5.f)/*!< default rel velocity if no object available */
#define SIT_TD_DEFAULT_REL_VELOCITY_FOR (5.f)  /*!< default rel velocity if no object available */
#define SIT_TD_JAM_VELOCITY (3.5f)             /*!< ALGO for neighbor lanes works only, if own velocity > JAM_VELOCITY, if velocity smaller - no action */
#define SIT_TD_JAM_VELOCITY_EGO (3.5f)          /*!< ALGO for neighbor lanes works only, if own velocity > JAM_VELOCITY, if velocity smaller - no action */
#define SIT_TD_MIN_DETECTION_VELOCITY (10u)    /*!< min lane detection velocity, lane detection is not working properly at low vel. */
#define SIT_TD_JAM_MEAN_VEL (1.5f)             /*!< if mean velocity is below SIT_TD_JAM_MEAN_VEL, than ego density is increased automatically over time */
#define SIT_TD_CAR_LENGTH (6.f)                /*!< length of any car */
#define SIT_TD_TRUCK_LENGTH (19.f)             /*!< length of any truck */

#define SIT_TD_CAR_UNIT (1.f)                  /*!< number of vehicle units */
#define SIT_TD_TRUCK_UNIT (2.0f)               /*!< number of vehicle units */

#define SIT_TD_COLLISION_TIME_GAP (0.3f)       /*!< time gap if two objects collide */
#define SIT_TD_NORMAL_TIME_GAP (1.2f)          /*!< normal time gap between two objects */

#define SIT_TD_OBJ_PREDICTION_CLC (45u)        /*!< hysteresis if object expires in FoV */
#define SIT_TD_OBJ_HYSTERESE_CLC (45u)         /*!< hysteresis if object changes lane */
#define SIT_TD_NO_OBJECT_DELAY (300u)          /*!< no traffic object available delay */
#define SIT_TD_MAX__OBJECT_AGE (30u)           /*!< 10 seconds * MAX__OBJECT_AGE = max existence time for historical objects */
#define SIT_TD_OBJ_AGE_UNIT (150u)             /*!< 1 unit = 150 radar cycles */
#define SIT_TD_CONF_SWITCH_TIME (150u)         /*!< 15 cycles * 10 seconds todo. replace with cycle time */

#define SIT_TD_INV_VALUE (-1)                  /*!< invalid value */
#define SIT_TD_CONVERT_MCS_TO_MS (0.001f)      /*!< conversion index from microseconds to milliseconds */
#define SIT_TD_VEH_PER_KM_COEF (1000.f)        /*!< conversion index from vehicle per meter to vehicle per kilometer */

#define SIT_TD_DENSITY_GRAD_UP (0.05f)         /*!< max allowed change of density per cycle if increasing */
#define SIT_TD_DENSITY_GRAD_DOWN (0.05f)       /*!< max allowed change of density per cycle if decreasing */

#define SIT_TD_MAX_EGO_DENSITY_1_OBJ (13.f)    /*!< max traffic density in ego lane if only one object detected */

#define SIT_TD_CONF_WEIGHT_ACT_OBJ_ADJ_LANE (25)   /*!< confidence weight factor for act obj. in adj. lane */
#define SIT_TD_CONF_WEIGHT_HIST_OBJ__ADJ_LANE (5)  /*!< confidence weight factor for hist obj. in adj. lane */
#define SIT_TD_CONF_WEIGHT_ACT_OBJ_EGO_LANE (25)   /*!< confidence weight factor for act obj. in ego lane */
#define SIT_TD_CONF_WEIGHT_NO_LANE (70)            /*!< confidence weight factor for no lane */
#define SIT_TD_CONF_WEIGHT_NO_OBJ (50)             /*!< confidence weight factor for no obj. */
#define SIT_TD_CONF_WEIGHT_VELOCITY (15)           /*!< confidence weight velocity factor  */
#define SIT_TD_CONF_WEIGHT_DIST (15)               /*!< confidence weight distance factor */
#define SIT_TD_CONF_TDENSITY_VAL (25.f)            /*!< confidence weight tr. density factor */
#define SIT_TD_CONF_DIST_VAL_EGO_LANE (80.f)       /*!< confidence weight tr. density ego lane factor */
#define SIT_TD_CONF_VEL_MIN (21.f)                 /*!< min velocity for confidence factor */
#define SIT_TD_CONF_VEL_MAX (28.f)                 /*!< max velocity for confidence factor */
#define SIT_TD_CONF_MAX (100u)                     /*!< max confidence */
#define SIT_TD_CONF_MIN (0u)                       /*!< min confidence */

#define SIT_TD_TEN_SEC (150u)                      /*!< should be 10 sec, to be replaced with cycle time logic */

#define SIT_TD_MIN_NUM_OBJ_FOR_TD (2u)             /*!< min object number for traffic density */

#define SIT_TD_YDIST_LEFT   (5.f)      /*Default Y distance of objects on the left in the list*/
#define SIT_TD_YDIST_RIGHT  (-5.f)     /*Default Y distance of objects on the right in the list*/

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
SET_MEMSEC_VAR(uiSITimer)
static uint8 uiSITimer;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void SIT_v_AddObjectToHistList(t_LaneDensityData* pLaneDensityData, uint8 ActIDX, uint8 uiHistIDX);
static void SIT_v_CalculateTrafficDensity( t_LaneDensityData* pLaneDensityData, const sint8 NoofLanes);

/*************************************************************************************************************************
  Functionname:    SIT_v_uiSITTimer                                                                                    */ /*!

  @brief           set content of static variable new_uiSITimer

  @description     set content of static variable new_uiSITimer

		@startuml
		Start
		Partition SIT_v_uiSITTimer {
			: Set content of static variable new_SITimer;
		}
		End
		@enduml

  @return          -

  @param[in]       new_uiSITimer : Value used to set the Timer/ Counter [full range of datatype uint8]

  @glob_in         - 
  @glob_out        uiSITimer : SI Timer/Counter for traffic density     [full range of datatype uint8]

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
  @changed         16.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
void SIT_v_uiSITTimer(uint8 new_uiSITimer)
{
  uiSITimer = new_uiSITimer;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_TrafficProcess                                                                                 */ /*!

  @brief           Main function to calculate the traffic density

  @description     This is the main function for computing traffic density. Initially information from lane matrix is read in, and then
                   check for jam situation is done based on EGO velocity and JAM velocity. In case there is no JAM, then the data structure containing 
                   traffic density information is initialized. If the velocity comparison detects a JAM then traffic density is computed by going
                   through all EM_N_OBJECTS objects. Individual left lane, right lane and EGO lane densities are computed and the JAM velocity updated.
                   Only objects with high quality are considered.

		@startuml
		Start
		Partition SIT_v_TrafficProcess {
		: Get lane matrix information;
		: SIT Timer to be changed from counter to timer;
		If (Ego Velocity is less than Jam Velocity) then (yes)
			Repeat
				: Update ACT Object list;
			Repeat While (For entire ACT Object List)
		Else (no)
			Repeat
				: All objects from last cycle will be set to not exist;
			Repeat While (For entire ACT Object List)
		Endif
		Repeat 
			: All objects from last cycle will be set to not exist;
		Repeat While (For entire ACT Ego Object List)
		Repeat
			If (High Quality Objects are filtered) then (yes)
				If (Object Associated Lane is Ego) then (yes)
					If (Ego speed is more than Ego Jam Velocity and Distance to Object is less than maximum Ego Distance) then (yes)
						: Create Active Object List for determination of existing and not existing Objects;
					Endif
				Else if (Object Associated Lane is Right) then (yes) 
					If (Ego speed is more than Jam Velocity and Distance to Object is less than maximum Distance) then (yes)
						: Create Active Object List for determination of existing and not existing Objects;
					Endif
				Else if (Object Associated Lane is Left) then (yes)
					If (Ego speed is more than Jam Velocity and Distance to Object is less than maximum Distance) then (yes)
						: Create Active Object List for determination of existing and not existing Objects;
					Endif
				Else (no)
					If (Ego speed is more than Ego Jam Velocity and Distance to Object is less than maximum Ego Distance) then (yes)
						: Detection of the lane change from (to) the other lanes;
						If (Object is new) then (yes)
							: Detection of the lane change from (to) the other lanes;
						Endif
					Endif
				Endif
			Endif
		Repeat While (For entire Object List)
		If (Ego Speed is more than Jam Velocity) then (yes)
			: Calculation of the traffic density right lane;
			: Calculation of the traffic density left lane;
		Endif
		If (Ego Speed is more than Jam Ego Velocity) then (yes)
			: Calculation of the traffic density ego lane;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       - 

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed                                                                  [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty(i) : Dynamic property of an object i                                     [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_u_GetObjLifeCycles(i) : Object lifetime in cycles                                                                 [AlgoCycleCounter_t as defined in Rte_type.h]
  @glob_in         pt_SITInput->t_LAInput.pt_ObjAssociatedLane(i) : associated lane information of an object i                   [eAssociatedLane_t as in Rte_Type.h]
  @glob_in         SITGlobalDensityData.DensityDataLeft.a_ActObjList : Structure for storing information on left lane FoV 
  @glob_in         SITGlobalDensityData.DensityDataRight.a_ActObjList : Structure for storing information on right lane FoV 
  @glob_in         SITGlobalDensityData.DensityDataEGO.a_ActObjList : Structure for storing information on ego lane FoV 
  @glob_in         SITGlobalDensityData.DensityDataRight : Structure for storing information about traffic density on right lane 
  @glob_in         SITGlobalDensityData.DensityDataleft  : Structure for storing information about traffic density on left lane 
  @glob_in         SITGlobalDensityData.DensityDataEgo   : Structure for storing information about traffic density on EGO lane 
  @glob_out        uiSITimer : SIT Timer/Counter for traffic density [full range of datatype uint8]
  @glob_out        SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].ObjID : Object Number (Object ID)                      [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @glob_out        SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].uiClass : Object class                                 [SLATE_t_Obj_CLassification as defined Rte_Type.h]
  @glob_out        SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].uiLifeTime : object lifetime                           [full range of datatype uint16] s
  @glob_out        SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].fDistX : Longitudinal distance to object               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].uiObjLossCount : counter for lane change hysteresis    [full range of datatype]
  @glob_out        SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list [TRUE, FALSE]
  @glob_out        SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].ObjID : Object Number (Object ID)                       [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @glob_out        SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].uiClass = Object class                                  [SLATE_t_Obj_CLassification as defined Rte_Type.h]
  @glob_out        SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].uiLifeTime : object lifetime                            [full range of datatype uint16] s
  @glob_out        SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].fDistX : Longitudinal distance to object                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].uiObjLossCount : counter for lane change hysteresis     [full range of datatype]
  @glob_out        SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list [TRUE, FALSE]
  @glob_out        SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].bObjExist :  Boolean indicating existence of object, if FALSE add object to historical list [TRUE, FALSE]
                   
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT Input Preprocessing Lane matrix (FIP Lane Matrix)
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
  @changed         16.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_TrafficProcess(void)
{
  ObjNumber_t   iObj;
  boolean       b_ObjExistFlag;
  uint8         idx;
  float32 fDistXObj, f_EgoSpeed;

  /* Get lane matrix information */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  const sint8 s_NumberLanesLeft = (pt_SITInput->pt_FIPLM->s_NumOfLaneLeft);
  const sint8 s_NumberLanesRight = (pt_SITInput->pt_FIPLM->s_NumOfLaneRight);
#else
  const sint8 s_NumberLanesLeft  = -1;
  const sint8 s_NumberLanesRight = -1;
#endif

  /* SIT Timer to be changed from counter to timer */
  uiSITimer = ( SIT_TD_TEN_SEC > uiSITimer) ? ( uiSITimer + 1u ) : 0u;

  /* Defining local variables from reference pointer */
  f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  
  if ( SIT_TD_JAM_VELOCITY > f_EgoSpeed ) /* if ego velocity > jam velocity */
  {
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
  }
  else
  {
    /* all objects from last cycle will be set ot not exist */
    for ( idx=0u; idx < SIT_TD_ACT_LIST_SIZE; idx++ )
    {
      SITGlobalDensityData.DensityDataRight.a_ActObjList[idx].bObjExist = FALSE;
      SITGlobalDensityData.DensityDataLeft.a_ActObjList[idx].bObjExist = FALSE;
    }
  }
  for ( idx=0u; idx < SIT_TD_ACT_LIST_EGO_SIZE; idx++ )
  {
    SITGlobalDensityData.DensityDataEgo.a_ActObjList[idx].bObjExist = FALSE;
  }

  /* Loop over 40 Objects */
  for ( iObj=0; iObj<EM_N_OBJECTS; iObj++ )
  {
    /*Defining local variable from input pointer*/
    fDistXObj = *pt_SITInput->t_RTE.pf_ObjLongDisp(iObj);
    /* Filter for high quality objects */
    if ( (SLATE_OBJECT_PROPERTY_MOVING == *pt_SITInput->t_RTE.pt_ObjDynProperty(iObj)) && 
         (SIT_TD_MIN_LIFETIME < SLATE_u_GetObjLifeCycles(iObj)) && 
         (SIT_TD_MIN_DIST_X < fDistXObj)
       )
    {
      switch ( *pt_SITInput->t_LAInput.pt_ObjAssociatedLane(iObj) )
      {
      case ASSOC_LANE_EGO:
        if (( SIT_TD_JAM_VELOCITY_EGO < f_EgoSpeed) && ( SIT_TD_MAX_DIST_X_EGO > fDistXObj ))
        {
          /* Function for determination of existing and not existing objects */
          SIT_v_CreateActiveObjectList( iObj, SITGlobalDensityData.DensityDataEgo.a_ActObjList, SIT_TD_ACT_LIST_EGO_SIZE,
                                    SITGlobalDensityData.DensityDataLeft.a_ActObjList, SIT_TD_ACT_LIST_SIZE,
                                    SITGlobalDensityData.DensityDataRight.a_ActObjList, SIT_TD_ACT_LIST_SIZE 
                                    );
        }
        break;
      case ASSOC_LANE_RIGHT:
        if (( SIT_TD_JAM_VELOCITY < f_EgoSpeed ) && ( SIT_TD_MAX_DIST_X > fDistXObj ))
        {
          /* Function for determination of existing and not existing objects */
          SIT_v_CreateActiveObjectList( iObj, SITGlobalDensityData.DensityDataRight.a_ActObjList, SIT_TD_ACT_LIST_SIZE ,
                                    SITGlobalDensityData.DensityDataEgo.a_ActObjList, SIT_TD_ACT_LIST_EGO_SIZE,
                                    SITGlobalDensityData.DensityDataLeft.a_ActObjList, SIT_TD_ACT_LIST_SIZE
                                    );
        }
        break;
      case ASSOC_LANE_LEFT:
        if (( SIT_TD_JAM_VELOCITY < f_EgoSpeed ) && ( SIT_TD_MAX_DIST_X > fDistXObj ))
        {
          /* Function for determination of existing and not existing objects */
          SIT_v_CreateActiveObjectList( iObj, SITGlobalDensityData.DensityDataLeft.a_ActObjList, SIT_TD_ACT_LIST_SIZE,
                                    SITGlobalDensityData.DensityDataEgo.a_ActObjList, SIT_TD_ACT_LIST_EGO_SIZE,
                                    SITGlobalDensityData.DensityDataRight.a_ActObjList, SIT_TD_ACT_LIST_SIZE
                                    );
        }
        break;
      default:
        if (( SIT_TD_JAM_VELOCITY < f_EgoSpeed ) && ( SIT_TD_MAX_DIST_X_EGO > fDistXObj ))
        {
          /* Detection of the lanechange from (to) the other lanes*/
          b_ObjExistFlag = SIT_b_LaneChangeHandling( iObj, SITGlobalDensityData.DensityDataRight.a_ActObjList, SIT_TD_ACT_LIST_SIZE );
          if ( b_ObjExistFlag == FALSE )
          {
            b_ObjExistFlag = SIT_b_LaneChangeHandling( iObj, SITGlobalDensityData.DensityDataLeft.a_ActObjList, SIT_TD_ACT_LIST_SIZE );
          }
        }
        break;
      }
    }
  }
  if ( SIT_TD_JAM_VELOCITY < f_EgoSpeed )
  {
    /* Calculation of the traffic density right lane */
    SIT_v_CalculateTrafficDensity( &SITGlobalDensityData.DensityDataRight, s_NumberLanesRight );
    /* Calculation of the traffic density left lane */
    SIT_v_CalculateTrafficDensity( &SITGlobalDensityData.DensityDataLeft, s_NumberLanesLeft );
  }
  if ( SIT_TD_JAM_VELOCITY_EGO < f_EgoSpeed )
  {
    /* Calculation of the traffic density ego lane */
    SIT_v_CalculateTrafficDensityEgo( &SITGlobalDensityData.DensityDataEgo );
  }

 
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalculateTrafficDensity                                                                        */ /*!

  @brief           Traffic Density Calculation

  @description     This is the main function for traffic density computation. The function loops over all objects in FoV from previous cycle and if the object exists,
                   then average/middle velocity is computed for the given lane. In case object does not exist in active FoV list, update the history FOV list.
                   Check is carried out on a cycle by cycle basis if objects in the relevant lane are available else the object history counter is updated.
                   In the current cycle the minimum and maximum borders are computed for the given lane and based on this the active FoV list and the history FoV list are updated.
                   Based on the updated lists in current cycle, the traffic density, its gradient and the confidence value is computed for the given lane.

		@startuml
		Start
		Partition SIT_v_CalculateTrafficDensity {
		Repeat
			If (No Object) then (yes)
				If (Object exists) then (yes)
					If (Detect Minimum Objects in FoV) then (yes)
						: Set Minimum Objects using Distance to X direction;
					Endif
					If (Detect Miximum Objects in FoV) then (yes)
						: Set Maximum Objects using Distance to X direction;
					Endif
					If (No Object Loss Count) then (yes)
						: Calculate of middle relative velocity for one lane;
					Endif
				Else (no)
					If (No storage memory in the history list) then (yes)
						If (Front Object cell is in the history list) then (yes)
							: Set Back Object cell;
							: Update Front Object cell ;
						Endif
						: Add Object to History List;
						: Update Old Object Id;
					Else (no)
						Repeat 
							If (No Object Id) then (yes)
								: add object to history list;
							Else (no)
								: Increase Object Id by 1;
							Endif
						Repeat While (For Entire Object history)
					Endif
				Endif
			Endif
		Repeat While (active objects in FOV)
		If (period of time no object available) then (yes)
			If (Object counter is greater than 0) then (yes)
				: Update Object Counter to 0;
			Endif
		Else (no)
			If (No Object Delay) then (yes)
				: Add 1 to Object Counter;
			Endif
		Endif
		: Calculate of middle relative velocity for one lane;
		: Loop over history objects;
		If (history list is full) then (yes)
			: object will be replaced;
		Else (no)
			If (Old Object cell Id is less than History List size) then (yes)
				: No object will be replaced;
			Endif
			If (No Objects) then (yes)
				: reset min, max borders;
			Endif
		Endif
		: Calculate max border, add normal distance gap;
		: Calculate min max borders depends on relative Velocity;
		If (Density will increase in situation with no traffic) then (yes)
			: Update Min and max point;
		Else (no)
			If (Min Object is under the Min Point) then (yes)
				: Update Min Point;
			Endif
			If (Max Object is far to the Max Point) then (yes)
				: Update Max Point;
			Endif
		Endif
		If (max history distance limit) then (yes)
			: Update Max Point;
		Else if (max border limit) then (yes) 
			: Update max point;
		Else (no)
			: Do Nothing;
		Endif
		If (min history distance limit) then (yes)
			: Update Min Point;
		Else if (min border limit) then (yes) 
			: Update min point to 0;
		Else (no)
			: Do Nothing;
		Endif
		Repeat
			If (No Object) then (yes)
				: Update Object Counter by 1;
				If (Not Truck Object) then (yes)
					: Update Density Counter with car;
				Else (no)
					:  Update Density Counter with truck;
				Endif
			Endif
		Repeat While (For all Objects in Fov)
		Repeat 
			If (No Object and min point is less then X direction distance and max point is more than X direction distance) then (yes)
				: Update Object Counter by 1;
				If (Not Truck Object) then (yes)
					: Update Density Counter with car;
				Else (no)
					:  Update Density Counter with truck;
				Endif
			Endif
		Repeat While (For all Objects in History list)
		If (max point - min point is more than 0) then (yes)
			: calculate temp traffic density;
		Else (no)
			: Update temp traffic density to 0;
		Endif
		: calculate traffic density with gradient;
		: calculate confidence;
		If (lane not detected) then (yes)
			: Update Confidence;
		Endif
		If (Traffic Density is less than Confidence Traffic Density) then (yes)
			If (ACT Object counter is less than minimum object traffic density) then (yes)
				: Add traffic density confidence with Confidence;
			Endif
			If (Ego speed add with relative X velocity is less than minimum confidence velocity) then (yes)
				: Subtract confidence velocity with Confidence;
			Endif
			If (Ego speed add with relative X velocity is less than maximum confidence velocity) then (yes) 
				: Add confidence velocity with Confidence;
			Endif
		Else (no)
			If (Ego speed add with relative X velocity is less than minimum confidence velocity) then (yes)
				: Add confidence velocity with Confidence;
			Endif
			If (Ego speed add with relative X velocity is less than maximum confidence velocity) then (yes) 
				: Subtract confidence velocity with Confidence;
			Endif
		Endif
		: Confidence change the state;
		}
		End
		@enduml

  @return          -

  @param[in,out]   pLaneDensityData : Structure for storing information about traffic density on a given lane 
                      fVrelXMed : relative middle/average velocity in lane                                                          [-330.f   330.f] m/s
                      a_ActObjList[idx].ObjID : Object Number (Object ID)                                                           [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_ActObjList[idx].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list  [TRUE, FALSE]
                      a_ActObjList[idx].fDistX : Longitudinal distance to object                                                    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_ActObjList[idx].uiObjLossCount : counter for lane change hysteresis                                         [full range of datatype uint8]
                      a_ActObjList[idx].uiClass : Object class                                                                      [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      a_HistObjList[idx].uiFrontObjCell : last array index of the historical object in positive area                [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_HistObjList[idx].uiBackObjCell : last array index of the historical object in negative area                 [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_HistObjList[idx].ObjID : Object Number (Object ID)                                                          [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]  
                      a_HistObjList[idx].fDistX : Longitudinal distance to object                                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_HistObjList[idx].uiClass : Object class                                                                     [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      uiOldObjectCellID : object to delete if no place in a list                                                    [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      uiNoObjectCounter : no traffic object available counter                                                       [full range of datatype uint16]
                      fMaxPoint : max distance border for traffic density calculation                                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fMinPoint : min distance border for traffic density calculation                                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fTrafficDensity : traffic density in lane                                                                     [full range of datatype float32]
                      siConfidence : Confidence of traffic density                                                                  [full range of datatype sint8]
                      uiConfidenceCounter : Confidence Counter for confidence change delay                                          [full range of datatype uinnt8]
  @param[in]       NoofLanes : Number of lanes in the given direction                                                               [-1 ... 20]
  
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed                                                                    [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX(i) : relative velocity between EGO and object i                                   [-330.f ... 330.f] m/s
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
  @changed         16.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
static void SIT_v_CalculateTrafficDensity( t_LaneDensityData* pLaneDensityData, const sint8 NoofLanes)
{
  
  uint8     ui_ind;
  uint8     ui_ind2;
  uint8     uiMinObjIDX, uiMaxObjIDX; /* index of max and min objects in ´FoV */
  uint8     uiMemoryListCounter;      /* counter for historical objects, needed for detection of storage capacity in array */
  uint8     uiOldObjCellID;           /* cell id of oldest object in the list, it can be replaced */
  float32   fMinObj = SIT_TD_MAX_DIST_X, fMaxObj = 0.f; /* min, max borders of 1 cycle for calculation of traffic density */
  float32   fTempDensity;             /* temp value of traffic density */
  float32   fVrelXMedCounter;         
  float32   fVrelXMed;
  float32   fDensityCounter;
  uint8     uiActObjectCounter;        /* number of objects in FoV */
  uint8     uiHistObjectCounter;       /* number of objects in historical list */
  sint16    siConfidence;
  float32   f_EgoSpeed;

  ui_ind2 = 0u;
  uiMinObjIDX = SIT_TD_ACT_LIST_SIZE;
  uiMaxObjIDX = SIT_TD_ACT_LIST_SIZE;
  uiMemoryListCounter = 0u;
  uiOldObjCellID = SIT_TD_HIST_LIST_SIZE;
  uiActObjectCounter = 0u;
  uiHistObjectCounter = 0u;
  fDensityCounter = 0.f;
  fTempDensity = 0.f;
  fVrelXMedCounter = 1.f;
  fVrelXMed = pLaneDensityData->fVrelXMed;
  siConfidence = 0;

  /* Defining local variables from reference pointer */
  f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;

  /* loop over selected objects in FoV */
  for ( ui_ind = 0u; ui_ind < SIT_TD_ACT_LIST_SIZE; ui_ind++ )
  {
    if ( OBJ_INDEX_NO_OBJECT != pLaneDensityData->a_ActObjList[ui_ind].ObjID )
    {
      /* detection of min and max objects in FoV */
      if ( pLaneDensityData->a_ActObjList[ui_ind].bObjExist == TRUE )
      {
        if ( fMinObj > pLaneDensityData->a_ActObjList[ui_ind].fDistX )
        {
          fMinObj = pLaneDensityData->a_ActObjList[ui_ind].fDistX;
          uiMinObjIDX = ui_ind;
        }
        if ( fMaxObj < pLaneDensityData->a_ActObjList[ui_ind].fDistX )
        {
          fMaxObj = pLaneDensityData->a_ActObjList[ui_ind].fDistX;
          uiMaxObjIDX = ui_ind;
        }
        /* Calculation of middle relative velocity for one lane */
        if ( 0u == pLaneDensityData->a_ActObjList[ui_ind].uiObjLossCount )
        {
          fVrelXMed += *pt_SITInput->t_RTE.pf_ObjVrelX(pLaneDensityData->a_ActObjList[ui_ind].ObjID);
          fVrelXMedCounter += 1.f;
        }
      }
      else
      {
        /* handling if no storage memory in the history list */
        if (SIT_TD_HIST_LIST_SIZE > pLaneDensityData->uiOldObjectCellID)
        {
          if ( SIT_TD_HIST_LIST_SIZE > pLaneDensityData->a_HistObjList[pLaneDensityData->uiOldObjectCellID].uiFrontObjCell )
          {
            pLaneDensityData->a_HistObjList[pLaneDensityData->a_HistObjList[pLaneDensityData->uiOldObjectCellID].uiFrontObjCell].uiBackObjCell = SIT_TD_HIST_LIST_SIZE;
            pLaneDensityData->a_HistObjList[pLaneDensityData->uiOldObjectCellID].uiFrontObjCell = SIT_TD_HIST_LIST_SIZE;
          }
          SIT_v_AddObjectToHistList(pLaneDensityData, ui_ind, pLaneDensityData->uiOldObjectCellID);
          pLaneDensityData->uiOldObjectCellID = SIT_TD_HIST_LIST_SIZE;
        }
        /* if memory available, look for free cell */
        else
        {
          while ( ui_ind2 < SIT_TD_HIST_LIST_SIZE )
          {
            /* add object to history list */
            if ( OBJ_INDEX_NO_OBJECT == pLaneDensityData->a_HistObjList[ui_ind2].ObjID )
            {
              SIT_v_AddObjectToHistList(pLaneDensityData, ui_ind, ui_ind2);
              ui_ind2 = SIT_TD_HIST_LIST_SIZE;/* break */
            }
            else
            {
              ui_ind2 += 1u;
            }
          }
        }
      }
    }
  }

  /* detects if a period of time no object available, then the object history will be decreased */
  if (1.f < fVrelXMedCounter )
  {
    if ( 0 < pLaneDensityData->uiNoObjectCounter )
    {
      pLaneDensityData->uiNoObjectCounter = 0u;
    }
  }
  else
  {
    if ( SIT_TD_NO_OBJECT_DELAY != pLaneDensityData->uiNoObjectCounter )
    {
      pLaneDensityData->uiNoObjectCounter += 1u;
    }
  }

  /* Calculation of middle relative velocity for one lane */
  pLaneDensityData->fVrelXMed = fVrelXMed / fVrelXMedCounter; /*!< Remark: fVrelXMedCounter >= 1 */

  /*Loop over history objects*/
  SIT_v_CalculateTrafficDensity_mainloop( pLaneDensityData, &uiOldObjCellID, &uiMinObjIDX, &uiMaxObjIDX,&uiMemoryListCounter, uiSITimer,
                                      &fMinObj,&fMaxObj, &fTempDensity );

  if ( uiMemoryListCounter >= SIT_TD_HIST_LIST_SIZE ) /* if history list is full */
  {
    pLaneDensityData->uiOldObjectCellID = uiOldObjCellID; /* that object will be replaced */
  }
  else /* hist list is not full */
  {
    if ( SIT_TD_HIST_LIST_SIZE > pLaneDensityData->uiOldObjectCellID )
    {
      pLaneDensityData->uiOldObjectCellID = SIT_TD_HIST_LIST_SIZE; /* no object will be replaced */
    }
     /* if no objects, reset min, max borders */
    if ( (0u == uiMemoryListCounter) && (1.f > fVrelXMedCounter ) )
    {
      pLaneDensityData->fMaxPoint = SIT_TD_INIT_MAX_BORDER;
      pLaneDensityData->fMinPoint = SIT_TD_INIT_MIN_BORDER;
    }
  }
  /* caculate max border, add normal distance gap */
  fMaxObj = fMaxObj + ( SIT_TD_CAR_LENGTH + ( (f_EgoSpeed + pLaneDensityData->fVrelXMed) * SIT_TD_NORMAL_TIME_GAP ) );
  /* calculate min max borders depens on Vrel */
  pLaneDensityData->fMaxPoint = pLaneDensityData->fMaxPoint + ( pLaneDensityData->fVrelXMed * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
  pLaneDensityData->fMinPoint = pLaneDensityData->fMinPoint + ( pLaneDensityData->fVrelXMed * GLOB_CYCLE_TIME * SIT_TD_CONVERT_MCS_TO_MS );
  
  /* density will increase in situation with no traffic */
  if ( ( SIT_TD_SYNCHRO_VELOCITY_ABS > f_EgoSpeed ) && 
      ((SIT_TD_SYNCHRO_VELOCITY_REL > pLaneDensityData->fVrelXMed) && (-SIT_TD_SYNCHRO_VELOCITY_REL < pLaneDensityData->fVrelXMed))
    ) 
  {
    pLaneDensityData->fMinPoint = fMinObj;
    pLaneDensityData->fMaxPoint = fMaxObj;
  }
  else /* choose the farthest border */
  {
    if ( fMinObj < pLaneDensityData->fMinPoint )
    {
      pLaneDensityData->fMinPoint = fMinObj;
    }
    if ( fMaxObj > pLaneDensityData->fMaxPoint )
    {
      pLaneDensityData->fMaxPoint = fMaxObj;
    }
  }
  /* max border limit */
  if ( SIT_TD_MAX_HIST_DIST_FOR < pLaneDensityData->fMaxPoint )
  {
    pLaneDensityData->fMaxPoint = SIT_TD_MAX_HIST_DIST_FOR;
  }
  else if ( SIT_TD_INIT_MAX_BORDER > pLaneDensityData->fMaxPoint )
  {
    pLaneDensityData->fMaxPoint = SIT_TD_INIT_MAX_BORDER;
  }
  else
  {
    /* Nothing to do */
  }
  /* min border limit */
  if ( SIT_TD_MAX_HIST_DIST_BACK > pLaneDensityData->fMinPoint )
  {
    pLaneDensityData->fMinPoint = SIT_TD_MAX_HIST_DIST_BACK;
  }
  else if ( 0.f < pLaneDensityData->fMinPoint )
  {
    pLaneDensityData->fMinPoint = 0.f;
  }
  else
  {
    /* Nothing to do */
  }

  /* calculate objects in FoV */
  for ( ui_ind = 0u; ui_ind < SIT_TD_ACT_LIST_SIZE; ui_ind++ )
  {
    if ( OBJ_INDEX_NO_OBJECT < pLaneDensityData->a_ActObjList[ui_ind].ObjID )
    {
      uiActObjectCounter += 1u;
      if ( SLATE_OBJCLASS_TRUCK != pLaneDensityData->a_ActObjList[ui_ind].uiClass )
      {
        fDensityCounter += SIT_TD_CAR_UNIT;
      }
      else
      {
        fDensityCounter += SIT_TD_TRUCK_UNIT;
      }
    }
  }
  /* calculate objects in hist list */
  for ( ui_ind = 0u; ui_ind < SIT_TD_HIST_LIST_SIZE; ui_ind++ )
  {
    if ( ( OBJ_INDEX_NO_OBJECT < pLaneDensityData->a_HistObjList[ui_ind].ObjID ) && ( pLaneDensityData->fMinPoint <= pLaneDensityData->a_HistObjList[ui_ind].fDistX )
      && ( pLaneDensityData->fMaxPoint > pLaneDensityData->a_HistObjList[ui_ind].fDistX ) )
    {
      uiHistObjectCounter += 1u;
      if ( SLATE_OBJCLASS_TRUCK != pLaneDensityData->a_HistObjList[ui_ind].uiClass )
      {
        fDensityCounter += SIT_TD_CAR_UNIT;
      }
      else
      {
        fDensityCounter += SIT_TD_TRUCK_UNIT;
      }
    }
  }
  /* calculate temp traffic density */
  if( fABS( pLaneDensityData->fMaxPoint - pLaneDensityData->fMinPoint ) > C_F32_DELTA )
  {
    fTempDensity = ( fDensityCounter * SIT_TD_VEH_PER_KM_COEF ) / ( pLaneDensityData->fMaxPoint - pLaneDensityData->fMinPoint );
  }
  else
  {
    fTempDensity = 0.f;
  }

  /* calculate traffic density with gradient */
  pLaneDensityData->fTrafficDensity += MINMAX_FLOAT(-SIT_TD_DENSITY_GRAD_DOWN, SIT_TD_DENSITY_GRAD_UP, (fTempDensity - pLaneDensityData->fTrafficDensity));

  /* confidence calculation */
  siConfidence = (sint16) (uiActObjectCounter * SIT_TD_CONF_WEIGHT_ACT_OBJ_ADJ_LANE + uiHistObjectCounter * SIT_TD_CONF_WEIGHT_HIST_OBJ__ADJ_LANE);
  /* if lane not detected */
  if ( (1 > NoofLanes) && (SIT_TD_MIN_DETECTION_VELOCITY < f_EgoSpeed) )
  {
    siConfidence -= SIT_TD_CONF_WEIGHT_NO_LANE;
  }

  if ( SIT_TD_CONF_TDENSITY_VAL > pLaneDensityData->fTrafficDensity )
  {
    if ( SIT_TD_MIN_NUM_OBJ_FOR_TD > uiActObjectCounter )
    {
      siConfidence += SIT_TD_CONF_WEIGHT_NO_OBJ;
    }
    if ( SIT_TD_CONF_VEL_MIN > ( f_EgoSpeed + pLaneDensityData->fVrelXMed) )
    {
      siConfidence -= SIT_TD_CONF_WEIGHT_VELOCITY;
    }
    if ( SIT_TD_CONF_VEL_MAX < ( f_EgoSpeed + pLaneDensityData->fVrelXMed) )
    {
      siConfidence += SIT_TD_CONF_WEIGHT_VELOCITY;
    }
  }
  else
  {
    if ( SIT_TD_CONF_VEL_MIN > ( f_EgoSpeed + pLaneDensityData->fVrelXMed) )
    {
      siConfidence += SIT_TD_CONF_WEIGHT_VELOCITY;
    }
    if ( SIT_TD_CONF_VEL_MAX < ( f_EgoSpeed + pLaneDensityData->fVrelXMed) )
    {
      siConfidence -= SIT_TD_CONF_WEIGHT_VELOCITY;
    }
  }

  siConfidence = (sint16) MINMAX_FLOAT(SIT_TD_CONF_MIN, SIT_TD_CONF_MAX, siConfidence);
  /* added type cast (sint16) to fulfill MISRA-C 2004 Rule 10.1 */

  /* if confidence change the state, wait */
  SIT_v_ConfChangeState( &siConfidence, &pLaneDensityData->siConfidence, &pLaneDensityData->uiConfidenceCounter);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_AddObjectToHistList                                                                            */ /*!

  @brief           Add object to history list

  @description     Add objects to history list based on object class and precomputed borders. Update the indices in the history list structure.

		@startuml
		Start
		Partition SIT_v_AddObjectToHistList {
			If (longitudinal distance of active object in FOV is less than SIT_TD_INIT_MIN_BORDER) then (yes)
				If (No Truck Object) then (yes)
					If (historical objects in back direction is less that object history list) then (yes)
						: Set Front Object Cell for Lane Density;
					Endif
				Endif
			Else(no)
				If (historical objects in forward direction is less that object history list) then (yes)
					: Set Back Object Cell for Lane Density;
				Endif
			Endif
			: Update Lane Density Data;
		}
		End
		@enduml

  @return          -

  @param[in,out]   pLaneDensityData : Structure for storing information about traffic density on a given lane
                      a_HistObjList[i].ObjID : Object Number (Object ID)                                                         [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_HistObjList[i].fDistX : Longitudinal distance to object                                                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_HistObjList[i].uiClass : Object class                                                                    [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      a_HistObjList[i].fVabsX : Boolean indicating existence of object, if FALSE add object to historical list   [TRUE, FALSE]
                      a_HistObjList[i].uiFrontObjCell : last array index of the historical object in positive area               [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_HistObjList[i].uiBackObjCell : last array index of the historical object in negative area                [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_ActObjList[i].ObjID : Object Number (Object ID)                                                          [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                      a_ActObjList[i].fDistX : Longitudinal distance to object                                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_ActObjList[i].uiClass : Object class                                                                     [SLATE_t_Obj_CLassification as defined Rte_Type.h]
                      a_ActObjList[i].bObjExist : Boolean indicating existence of object, if FALSE add object to historical list [TRUE, FALSE] 
                      a_ActObjList[i].uiLifeTime : object lifetime                                                               [full range of datatype uint16] s
                      a_ActObjList[idx].uiFrontObjCell : last array index of the historical object in positive area              [0 ... SIT_TD_HIST_LIST_SIZE]
                      a_ActObjList[idx].uiBackObjCell : last array index of the historical object in negative area               [0 ... SIT_TD_HIST_LIST_SIZE]
                      fVrelXMed : relative middle/average velocity in lane                                                       [-330.f ... 330.f] m/s
                      uiLastCellIDBack : last array index of the historical object in negative area                              [0 ... SIT_TD_HIST_LIST_SIZE]
                      uiLastCellIDFront : last array index of the historical object in positive area                             [0 ... SIT_TD_HIST_LIST_SIZE]
  @param[in]       ActIDX : index for current object list                                                                        [0 ... SIT_TD_ACT_LIST_SIZE]
  @param[in]       uiHistIDX : index for history object list                                                                     [0 ... SIT_TD_HIST_LIST_SIZE]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed                                                                  [-330.f ... 330.f] m/s
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
  @changed         16.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
static void SIT_v_AddObjectToHistList(t_LaneDensityData* pLaneDensityData, uint8 ActIDX, uint8 uiHistIDX)
{
  pLaneDensityData->a_HistObjList[uiHistIDX].ObjID = pLaneDensityData->a_ActObjList[ActIDX].ObjID;
  pLaneDensityData->a_HistObjList[uiHistIDX].fDistX = pLaneDensityData->a_ActObjList[ActIDX].fDistX;
  pLaneDensityData->a_HistObjList[uiHistIDX].uiClass = pLaneDensityData->a_ActObjList[ActIDX].uiClass;
  pLaneDensityData->a_HistObjList[uiHistIDX].fVabsX = ( *pt_SITInput->t_RTE.pf_EgoLongVel + pLaneDensityData->fVrelXMed );
  /* save ui_ind2 */
  if ( SIT_TD_INIT_MIN_BORDER > pLaneDensityData->a_ActObjList[ActIDX].fDistX )
  {
    if (SLATE_OBJCLASS_TRUCK != pLaneDensityData->a_HistObjList[uiHistIDX].uiClass)
    {
      if ( SIT_TD_HIST_LIST_SIZE > pLaneDensityData->uiLastCellIDBack )
      {
        /* vor und nach objekt */
        pLaneDensityData->a_HistObjList[pLaneDensityData->uiLastCellIDBack].uiFrontObjCell = uiHistIDX;
        pLaneDensityData->a_HistObjList[uiHistIDX].uiBackObjCell = pLaneDensityData->uiLastCellIDBack;
      }
      pLaneDensityData->uiLastCellIDBack = uiHistIDX;
    }
  }
  else
  {
    if ( SIT_TD_HIST_LIST_SIZE > pLaneDensityData->uiLastCellIDFront )
    {
      /* vor und nach objekt */
      pLaneDensityData->a_HistObjList[pLaneDensityData->uiLastCellIDFront].uiBackObjCell = uiHistIDX;
      pLaneDensityData->a_HistObjList[uiHistIDX].uiFrontObjCell = pLaneDensityData->uiLastCellIDFront;
    }
    pLaneDensityData->uiLastCellIDFront = uiHistIDX;
  }
  pLaneDensityData->a_ActObjList[ActIDX].ObjID = OBJ_INDEX_NO_OBJECT;
  pLaneDensityData->a_ActObjList[ActIDX].bObjExist = FALSE;
  pLaneDensityData->a_ActObjList[ActIDX].uiLifeTime = 0u;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_ConfChangeState                                                                                */ /*!

  @brief           Function to update the confidence

  @description     Based on confidence counter and other constraints, update the existing confidence value with newly computed value. 
                   Confidence counters are also updated in this function

		@startuml
		Start
		Partition SIT_v_ConfChangeState {
		If (confidence changes the state is valid) then (yes)
			If (temporary confidence changes the state is valid) then (yes)
				: Increase confidence counter by 1;
				If (Confidence Counter is more than SIT_TD_CONF_SWITCH_TIME) then (yes)	
					: Update Confidence;
					: Update Confidence Counter;
				Endif
			Else (no)
				: Update Confidence;
				: Update Confidence Counter;
			Endif
		Else (no)
			If (temporary confidence changes the state and Ego Longitudinal Velocity is more than minimum Detection Velocity) then (yes)
				: Increase confidence counter by 1;
				If (Confidence Counter is more than SIT_TD_CONF_SWITCH_TIME) then (yes)	
					: Update Confidence;
					: Update Confidence Counter;
				Endif
			Else (no)
				: Update Confidence;
				: Update Confidence Counter;
			Endif
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       piTempConfidence : Newly computed confidence of traffic density [full range of datatype]
  @param[in,out]   piConfidence : Existing confidence of traffic density [full range of datatype]
  @param[in,out]   puiConfidenceCounter : Confidence Counter for confidence change delay [full range of datatype]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed   [-330.f ... 330.f] m/s
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
  @changed         16.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_ConfChangeState(sint16* piTempConfidence, sint8* piConfidence, uint8* puiConfidenceCounter)
{
  /* if confidence change the state, wait */
  if ( SIT_TE_VALID_CONFIDENCE > *piConfidence )
  {
    if( SIT_TE_VALID_CONFIDENCE < *piTempConfidence )
    {
      *puiConfidenceCounter += 1u;
      if ( SIT_TD_CONF_SWITCH_TIME < *puiConfidenceCounter )
      {
        *piConfidence = (sint8)*piTempConfidence;
        *puiConfidenceCounter = 0u;
      }
    }
    else
    {
      *piConfidence = (sint8)*piTempConfidence;
      *puiConfidenceCounter = 0u;
    }
  }
  else
  {
    if( (SIT_TE_VALID_CONFIDENCE > *piTempConfidence) && (SIT_TD_MIN_DETECTION_VELOCITY < *pt_SITInput->t_RTE.pf_EgoLongVel) )
    {
      *puiConfidenceCounter += 1u;
      if ( SIT_TD_CONF_SWITCH_TIME < *puiConfidenceCounter )
      {
        *piConfidence = (sint8)*piTempConfidence;
        *puiConfidenceCounter = 0u;
      }
    }
    else
    {
      *piConfidence = (sint8)*piTempConfidence;
      *puiConfidenceCounter = 0u;
    }
  }
}


#if defined (FCT_SIMU) && !defined(FASTSIM)
/*************************************************************************************************************************
  Functionname:    SIT_v_MDrawTrafficDensity                                                                            */ /*!

  @brief           Function to draw/indicate objects in the history list

  @description     Function to draw/indicate objects in the history list

		@startuml
		Start
		Partition SIT_v_DrawTrafficDensity {
			Repeat
				If (Density Object is in Right) then (yes)
					: Update list of historical objects not found in FOV (Object Id, Distance to X Direction, Distance to Y Direction);
				Endif
				If (Density Object is in Left) then (yes)
					: Update list of historical objects not found in FOV (Object Id, Distance to X Direction, Distance to Y Direction);
				Endif
			Repeat While (For Entire History List size)
		}
		End
		@enduml

  @return          -

  @param[in]       - 

  @glob_in         SITGlobalDensityData.DensityDataRight.a_HistObjList[i].ObjID : Object Number (Object ID)         [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]  
  @glob_in         SITGlobalDensityData.DensityDataRight.a_HistObjList[i].fDistX : Longitudinal distance to object  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SITGlobalDensityData.DensityDataLeft.a_HistObjList[i].ObjID : Object Number (Object ID)          [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1] 
  @glob_in         SITGlobalDensityData.DensityDataLeft.a_HistObjList[i].fDistX : Longitudinal distance to object   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   SIT_CFG_TRAFFIC_DENSITY: Configuration switch to enable/disable the calculation of the traffic density (sit_trafficdensity.c)
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_SIMU : Simulation config switch
  @c_switch_full   FASTSIM : simulation specific function switch

  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.12.2013
  @changed         16.03.2016

  @author          Simon Sinnstein | Simon.Sinnstein@continental-corporation.com | +49 (8382) 9699-160 
*************************************************************************************************************************/
void SIT_v_DrawTrafficDensity(void)
{
  uint8 i;

  for (i = 0u; i < SIT_TD_HIST_LIST_SIZE; i++)
  {
    if ( -1 < SITGlobalDensityData.DensityDataRight.a_HistObjList[i].ObjID )
    {
      
      pt_SITOutput->a_SITHistData[i].ObjID = SITGlobalDensityData.DensityDataRight.a_HistObjList[i].ObjID;
      pt_SITOutput->a_SITHistData[i].fDistX = SITGlobalDensityData.DensityDataRight.a_HistObjList[i].fDistX;
      pt_SITOutput->a_SITHistData[i].fDistY = SIT_TD_YDIST_RIGHT;
    }
    if ( -1 < SITGlobalDensityData.DensityDataLeft.a_HistObjList[i].ObjID )
    {
      
      pt_SITOutput->a_SITHistData[i].ObjID = SITGlobalDensityData.DensityDataLeft.a_HistObjList[i].ObjID;
      pt_SITOutput->a_SITHistData[i].fDistX = SITGlobalDensityData.DensityDataLeft.a_HistObjList[i].fDistX;
      pt_SITOutput->a_SITHistData[i].fDistY = SIT_TD_YDIST_LEFT;
    }
  }
}
#endif
///@}
#endif /*!< SIT_CFG_TRAFFIC_DENSITY */

#endif /*!< FCT_CFG_ACC_SITUATION */


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

