/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 SLATE CP (Course Prediction)

MODULNAME:                 cp_customfunctions.c

DESCRIPTION:               CP custom functions for SI-Module

AUTHOR:                    Matthias Thomi, Gregor Powarzynski

CREATION DATE:             16.04.2012

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.0
  
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cp_customfunctions.h"
#if (FCT_CFG_COURSE_PREDICTION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_customfunctions Custom functions
@ingroup cp
@brief          This module contains customer specific functions for ACC Course Prediction module.
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
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/*! application parameters for restriction of trace bracket extensions*/
#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
typedef struct
{
  uint8 LaneChangeProbThresMin;  /*!< Min. Threshold to restrict trace bracket extentions   @min:0 @max: 100 */
  uint8 LaneChangeProbThresMax;  /*!< Max Threshold to restrict trace bracket extentions   @min:0 @max: 100 */
  uint8 LaneChangeTimer;         /*!< Timer not to make object relevant at once again     @min:0 @max: 100 */
} CP_t_CustomParameterLaneChange; /*!< @allow: all_cust */
#endif /*SLATE_CFG_ENABLE_OVERTAKE_ASSIST*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

#if (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE)
/* course filter parameters     */
#define CP_CONST_ZERO             (0.0F)
#define CP_CONST_ONE              (1.0F)
#define CP_CYCLE_TIME_MIN         (0.001F)
#define CP_VEH_CURVE_LP_FREQ      (10.0F) /* Filter Frequency[rad/s] - Vehicle Curve Lowpass */
#define CP_TRACK_CURVE_LP_FREQ    (1.0F) /* Filter Frequency[rad/s] - Track Curve Lowpass */
#endif	/* END IF (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE) */

/* lane change parameters       */
/********************************/

/*! Threshold to restrict trace bracket extentions    min:00  max: 100 */
#define CP_CUSTOM_LANE_CHANGE_MIN_PROB_THRES  0u
#define CP_CUSTOM_LANE_CHANGE_MAX_PROB_THRES  35u
/*! Timer not to make object relevant at once again     @min:00 @max: 100 */
#define CP_CUSTOM_LANE_CHANGE_TIMER       5u

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
#if (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE)
static fCurve_t t_CP_Vehicle_Curve_Flt;
static fCurve_t t_CP_Track_Curve_Flt;
#endif /* END IF (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE) */

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
SET_MEMSEC_VAR(CP_CustomLaneChangeParameters)
/*! application parameters for restriction of trace bracket extensions*/
static const CP_t_CustomParameterLaneChange CP_CustomLaneChangeParameters = // PRQA S 3218
/* date: 2015-05-07, reviewer: Gangadhar Badiger, reason: static local required for saving data across function calls*/
{
  CP_CUSTOM_LANE_CHANGE_MIN_PROB_THRES,
  CP_CUSTOM_LANE_CHANGE_MAX_PROB_THRES,
  CP_CUSTOM_LANE_CHANGE_TIMER,
};
#endif  /* (SLATE_CFG_ENABLE_OVERTAKE_ASSIST) */

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
/*! The lane change overtake assist states */
SET_MEMSEC_VAR(CP_CustomOvertakeAssistance)
static CP_CustomOvertakeAssistance_t CP_CustomOvertakeAssistance;
#endif /* (SLATE_CFG_ENABLE_OVERTAKE_ASSIST) */

#ifdef FCT_SIMU
#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
SET_MEMSEC_CONST(CP_CustOvertakeMeasInfo) 
static const MEASInfo_t CP_CustOvertakeMeasInfo = 
{
  /* .VirtualAddress = */
  FCT_MEAS_ID_CP_CUSTOM_OVERTAKE,
  /* .Length = */
  sizeof(CP_CustomOvertakeAssistance),
  /* .FuncID = */
  FCT_MEAS_FUNC_ID,
  /* .FuncChannelID = */
  FCT_MEAS_FUNC_CHAN_ID,
};
#endif /* END IF (SLATE_CFG_ENABLE_OVERTAKE_ASSIST) */

#endif /* FCT_SIMU */

/*****************************************************************************
  STATIC FUNCTION PROTOTYPES
*****************************************************************************/

static void CP_v_ACC_Init(void);
static void CP_v_ACC_CustomCourseProc(CP_t_CourseData * pCourseData);
#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
static void CP_v_ACC_CustomTrajectoryParamProc(CP_t_TrajectoryInputParameter * pTrajInputPara);
#endif /*(SLATE_CFG_ENABLE_OVERTAKE_ASSIST)*/
static void CP_v_ACC_CustomTrajectoryPostProc(CP_t_TrajectoryData * pTrajData);
#if (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE)
static float32 CPSILowPassFilter(float32 f_raw, float32 f_flt, float32 f_freq, float32 f_ts);
#endif
/*****************************************************************************
  NON-STATIC FUNCTIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    CP_v_ACC_Init                                                                                         */ /*!

  @brief           Init function of CP sub-component

  @description     Init function of CP sub-component

                    @startuml
                        Start
                            Partition CP_v_ACC_Init {
                                - Init function of CP sub-component
                            }
                        End
                    @enduml

  @return          static void

  @param[in,out]   pCourseData : Pointer to structure containing ego course data
  @param[in,out]   pTrajectoryData : Pointer to structure containing ego trajectory data

  @glob_in         -
  @glob_out        -

  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST   : Configuration switch enabling overtake support feature
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @created         -
  @changed         12/18/2015

  @author          Norman Apel | norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CP_v_ACC_Init(void)
{
  /* Initialize persistent memory */
  CP_v_InitPersistentData();

  /* Initialize input-output data structures */
  CP_v_InitEveryCycle();

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
  CP_CustomOvertakeAssistance.iOvertakeObj = -1;
  CP_CustomOvertakeAssistance.uiLaneChgProb = 0;
  CP_CustomOvertakeAssistance.uiLaneChgProbLC = 0;
  CP_CustomOvertakeAssistance.ucLaneChgDownCnt = 0;
#endif /*SLATE_CFG_ENABLE_OVERTAKE_ASSIST*/

#if (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE)
  /* Initialize Lowpass Filtered Curves */
  t_CP_Vehicle_Curve_Flt = CP_CONST_ZERO;
  t_CP_Track_Curve_Flt = CP_CONST_ZERO;
#endif /* (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE) */
}

/*************************************************************************************************************************
  Functionname:    CP_v_ACC_CustomCourseProc                                                                             */ /*!

  @brief           Do customizable processing of course

  @description     Do customizable processing of course

                    @startuml
                        Start
                            Partition CP_v_ACC_CustomCourseProc {
                                - Initialiazing course data as per customer requirment 
                            }
                        End
                    @enduml

  @return          static void

  @param[in,out]   pCourseData : The base calculated course data on input, 
                                 which can be modified according to customer requirements
                        pCourseData->fCurve : Curvature of Trajectory                                              [float data type][range as mentioned in Rte_Type.h]
                        pCourseData->fCurveGradient : Gradient value of a Curve                                    [full range of datatype float]
                        pCourseData->HeadingAngle : The orientation angle of direction to 
                                                    which vehicle nose is pointingof Heading Angle                 [full range of datatype float32]

  @glob_in         t_CP_Custom_Curve_Flt : CP Course Filter parameter configuration variable                       [full range of datatype of float32]
  @glob_out        t_CP_Custom_Curve_Flt : CP Course Filter parameter configuration variable                       [full range of datatype of float32]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @created         -
  @changed         12/18/2015

  @todo            For ARS32X use this for application!

  @author          Norman Apel / Mark Fiolka
*************************************************************************************************************************/
static void CP_v_ACC_CustomCourseProc( CP_t_CourseData * pCourseData )
{
#if (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE)
  /* Get Cycle Time */
  fTime_t t_CycleTime = MAX(TASK_CYCLE_TIME, CP_CYCLE_TIME_MIN);

  /* Eval Vehicle Lowpass Filtered Curve */
  t_CP_Vehicle_Curve_Flt = CPSILowPassFilter(EGO_DRV_INT_CURVE_OBJ_SYNC, t_CP_Vehicle_Curve_Flt, CP_VEH_CURVE_LP_FREQ, t_CycleTime);

  /* Eval Track Lowpass Filtered Curve */
  t_CP_Track_Curve_Flt = CPSILowPassFilter(EGO_CURVE_OBJ_SYNC-t_CP_Vehicle_Curve_Flt, t_CP_Track_Curve_Flt, CP_TRACK_CURVE_LP_FREQ, t_CycleTime);

  /* Output Result Filtered Curve */
  pCourseData->fCurve = t_CP_Vehicle_Curve_Flt + t_CP_Track_Curve_Flt;

  /* Output default values */
  pCourseData->fCurveGradient = CP_CONST_ZERO;
  pCourseData->fCurveVar      = CP_CONST_ZERO;
  pCourseData->HeadingAngle   = CP_CONST_ZERO;

  /* Output Side Slip Angle */
#if (CP_CFG_USE_SLIPANGLE)
  pCourseData->SideSlipAngle         = EGO_SIDE_SLIP_OBJ_SYNC;      /* pInputSignals->Lateral.SlipAngle.SideSlipAngle */
  pCourseData->SideSlipAngleVariance = EGO_SIDE_SLIP_VAR_OBJ_SYNC;  /* pInputSignals->Lateral.SlipAngle.Variance */
#else
  pCourseData->SideSlipAngle         = CP_CONST_ZERO;
  pCourseData->SideSlipAngleVariance = CP_CONST_ZERO;
#endif /* END IF (CP_CFG_USE_SLIPANGLE) */
#else  
  pCourseData = pCourseData;//PRQA S 3199
  /* date: 2015-05-07, reviewer: Gangadhar Badiger, reason: Not a safety critical issue*/
#endif  /* END IF CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE */
}

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
/*************************************************************************************************************************
  Functionname:    CP_v_ACC_CustomTrajectoryParamProc                                                                    */ /*!

  @brief           Do customizable processing of trajectory

  @description     Do customizable processing of trajectory

                    @startuml
                        Start
                            Partition CP_v_ACC_CustomTrajectoryParamProc {
                                - Initializing trajectory as per customer
                            }
                        End
                    @enduml

  @return          static void

  @param[in,out]   pTrajInputPara : Pointer to CP_t_TrajectoryInputParameter structure containing custom trajectory data which will be modified based on customer requirements

  @glob_in         pSLATE_CustomInput : Pointer to structure FCTCustomInput_t containing customer specific input data for custom functional requirements
                      pSLATE_CustomInput->sProbabilityLaneChange.uiProbabilityLaneChangeLeft : Probability of ego lane change to left lane         [full range of datatype unsigned character]
                      pSLATE_CustomInput->sProbabilityLaneChange.uiProbabilityLaneChangeRight : Probability of ego lane change to right lane       [full range of datatype unsigned character]

  @glob_in         CP_CustomOvertakeAssistance : Structure containing data for ego lane change probability and object being overtaken for overtake assist feature
  @glob_in         CP_CustomLaneChangeParameters : Structure containing application parameters for restriction of trace bracket extensions
                      CP_CustomLaneChangeParameters.LaneChangeProbThresMax : Max Threshold to restrict trace bracket extensions                      [Datatype uint8 as in Platform_types.h][0u.....100u]
                      CP_CustomLaneChangeParameters.LaneChangeProbThresMin : Min Threshold to restrict trace bracket extensions                      [Datatype uint8 as in Platform_types.h][0u.....100u]
                      CP_CustomLaneChangeParameters.LaneChangeTimer : Timer not to make object relevant at once again                                [Datatype uint8 as in Platform_types.h][0u.....100u]

  @glob_in         pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr : object number of relevant object [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @glob_out        CP_CustomOvertakeAssistance : Structure containing data for ego lane change probability and object being overtaken for overtake assist feature
                      CP_CustomOvertakeAssistance.uiLaneChgProbLC : Calculated ego left lane change probability data of last cycle                   [full range of datatype uint8 as in Platform_types.h]
                      CP_CustomOvertakeAssistance.uiLaneChgProb : Calculated ego left lane change probability data for current cycle                 [full range of datatype uint8 as in Platform_types.h]
                      CP_CustomOvertakeAssistance.ucLaneChgDownCnt : Lane change down-counter, when non-zero, then lane change is active             [full range of datatype uint8 as in Platform_types.h]
                      CP_CustomOvertakeAssistance.iOvertakeObj : Object ID of relevant object (i.e. OOI_0) being overtaken                           [ObjNumber_t type datatype as in Rte_Type.h]

  @glob_out         CP_CustOvertakeMeasInfo : Structure containing CP_CustomOvertakeAssistance measurement data for use in simulation

  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT Custom I/O Interface
  @c_switch_part   FCT_SIMU : FCT simulation enabling switch
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING : FCT Driver intention monitoring switch
  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST : Configuration switch enabling overtake support feature
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component of FCT

  @pre             -
  @post            -

  @created         -
  @changed         12/16/2015

  @todo           For ARS32X use this for application!

  @author          Norman Apel / Mark Fiolka
*************************************************************************************************************************/
static void CP_v_ACC_CustomTrajectoryParamProc(CP_t_TrajectoryInputParameter * pTrajInputPara)
{
  /* Special 'Blinker-Feature' for BMW. When the turn indicator is on (blinking)
  then the fusion of road/traces into the predicted ACC course is turned off */

  /* Get left and right lane change probability */
  const SIT_LC_t_LaneChangePhaseInfo SILaneChangeInfo = *(pt_CPInput->t_SIT.pt_GetLaneChangeInfo); //PRQA S 1031
  uint8 LaneChgProb = (uint8)0;
  ObjNumber_t t_RelObjNr = pt_CPInput->t_OOI.pt_OOIRelObj->ObjectNr;

  if((SILaneChangeInfo.t_LCPhaseState == LC_LEFT) && (SILaneChangeInfo.t_LCTrafficOrientation == LC_TRAFFIC_ORIENT_RIGHT))
  {
    LaneChgProb = SILaneChangeInfo.u_LCPhaseProb;
  }
  else if((SILaneChangeInfo.t_LCPhaseState == LC_RIGHT) && (SILaneChangeInfo.t_LCTrafficOrientation == LC_TRAFFIC_ORIENT_LEFT))
  {
    LaneChgProb = SILaneChangeInfo.u_LCPhaseProb;
  }
  else
  {
    LaneChgProb = (uint8)0;
  }

  /* Copy last lane change probability to last cycle */
  CP_CustomOvertakeAssistance.uiLaneChgProbLC = CP_CustomOvertakeAssistance.uiLaneChgProb;

  /* Store new lane change probability */
  CP_CustomOvertakeAssistance.uiLaneChgProb  = LaneChgProb;

  /* Different processing depending if the lane change probability ,
   Turn indicator and lane change phase avoiding steerback phase supressing fusion
   */
  if ( ( ( (LaneChgProb >= CP_CustomLaneChangeParameters.LaneChangeProbThresMax)
        && ( (*pt_CPInput->t_RTE.pt_TurnIndicator == eTurnIndicator_Right)
          || (*pt_CPInput->t_RTE.pt_TurnIndicator == eTurnIndicator_Left)
           )
         )
      || (CP_CustomOvertakeAssistance.ucLaneChgDownCnt > 0u) 
       ) 
    && (SILaneChangeInfo.t_LCPhase != LC_STEERBACK)
     )
  { 
    /* Check if the lane change probability is rising (to detect a rising edge) */
    if ((LaneChgProb >= CP_CustomOvertakeAssistance.uiLaneChgProbLC) && (LaneChgProb > 0u))
    {
      /* Lane change probability increased compared to previous cycle
      If this is the activation (ucLaneChgDownCnt was zero), then also
      store the relevant object ID */
      if (CP_CustomOvertakeAssistance.ucLaneChgDownCnt == 0u)
      {
        /* Store the relevant object's index */
        CP_CustomOvertakeAssistance.iOvertakeObj = t_RelObjNr;
      }
      /* Initialize lane change down counter */
      CP_CustomOvertakeAssistance.ucLaneChgDownCnt = CP_CustomLaneChangeParameters.LaneChangeTimer;
    }
    else
    {
      /* Lane change probability decreased compared to previous cycle, thus we
      can decrease down counter, if positive */
      if (CP_CustomOvertakeAssistance.ucLaneChgDownCnt > 0u)
      {
        CP_CustomOvertakeAssistance.ucLaneChgDownCnt--;
      }
    }
  }
  else
  {
    /* Lane change probability below threshold, reset lane change down counter to
    immediately exit lane change mode and reset relevant object index */
    CP_CustomOvertakeAssistance.ucLaneChgDownCnt = 0u;
    CP_CustomOvertakeAssistance.iOvertakeObj     = OBJ_INDEX_NO_OBJECT;
  }
  /* If the lane change down counter is active, then set suppress fusion bit, otherwise
  clear it */
  if (    (CP_CustomOvertakeAssistance.ucLaneChgDownCnt > 0u)
  && (CP_CustomOvertakeAssistance.iOvertakeObj != OBJ_INDEX_NO_OBJECT)
       && (SILaneChangeInfo.t_LCPhase != LC_STEERBACK)
          
     )
  {
    pTrajInputPara->bSuppressFusion  = TRUE;
  }
  else
  {
    pTrajInputPara->bSuppressFusion  = FALSE;
  }

#ifdef FCT_SIMU
  FCT_FREEZE_DATA(&CP_CustOvertakeMeasInfo, &CP_CustomOvertakeAssistance, NULL); 
#endif 
}
#endif /*(SLATE_CFG_ENABLE_OVERTAKE_ASSIST)*/

#if (CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE)
/*************************************************************************************************************************
  Functionname:    CPSILowPassFilter                                                                                */ /*!

  @brief           Generic low pass filter

  @description     Generic low pass filter. Right now only used to filter the ego curve. 
                   Therefore, the input/output ranges are given based on the ego curve.

  @return          Filtered input value; range assumed for curvature [-1.f ... 1.f]

  @param[in]       f_raw : raw input value; range assumed for curvature [-1.f ... 1.f]
  @param[in]       f_flt : last filtered value; range assumed for curvature [-1.f ... 1.f]
  @param[in]       f_freq : filter frequency [0.f ... 1000.f] rad/s
  @param[in]       f_ts : sample time [0.f ... 1.f]s

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OBJECT_SELECTION : Switch to configure ACC object selection sub-component of FCT Module

  @pre             -
  @post            -

  @created         -
  @changed         29.03.2016

  @author          Wolfgang Borgs
*************************************************************************************************************************/
static float32 CPSILowPassFilter(float32 f_raw, float32 f_flt, float32 f_freq, float32 f_ts)
{
  float32 f_fact = f_ts*f_freq;
  return ((f_fact*f_raw) + f_flt) / (f_fact + CP_CONST_ONE);
}
#endif  /* ENDIF CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE */
/*************************************************************************************************************************
  Functionname:    CP_v_ACC_CustomTrajectoryPostProc                                                                     */ /*!

  @brief           Do customizable processing of trajectory

  @description     Do customizable processing of trajectory

                    @startuml
                        Start
                            Partition CP_v_ACC_CustomTrajectoryPostProc {
                                - Initializing processing of trajectory as per customer 
                            }
                        End
                    @enduml

  @return          static void

  @param[in,out]   pTrajData : The base calculated trajectory as input, which can be modified according to customer requirements

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component of FCT

  @pre             -
  @post            -

  @created         -
  @changed         12/16/2015

  @todo            If application needed modify this!

  @author          Norman Apel / Mark Fiolka
*************************************************************************************************************************/
static void CP_v_ACC_CustomTrajectoryPostProc(CP_t_TrajectoryData * pTrajData)
{
#ifdef _MSC_VER
 pTrajData = pTrajData;//PRQA S 3199
  /* date: 2015-05-07, reviewer: Gangadhar Badiger, reason: Not a safety critical issue*/
#endif
}

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
/*************************************************************************************************************************
  Functionname:    CP_b_ACC_CheckObjForOvertake                                                                          */ /*!

  @brief           Check if given object is being overtaken

  @description     Return TRUE if given object is being overtaken. This shall
                   lead to the trace bracket extensions usually applied to
                   relevant objects being reset

  @return          boolean : TRUE if object being overtaken is same as input object and lane change is active
                             FALSE if object being overtaken is not input oject or lane change is not active

  @param[in]       iObj : Object ID of object being queried for                      [ObjNumber_t type datatype as in Rte_Type.h]

  @glob_in         CP_CustomOvertakeAssistance : Structure containing data for ego lane change probablity and object being overtaken for overtake assist feature
                      CP_CustomOvertakeAssistance.ucLaneChgDownCnt : Lane change down-counter, when non-zero, then lane change is active      [full range of datatype uint8 as in Platform_types.h]
                      CP_CustomOvertakeAssistance.iOvertakeObj : Object ID of relavant object (i.e. OOI_0) being overtaken                    [ObjNumber_t type datatype as in Rte_Type.h]

  @glob_out        -

  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST : Configuration switch enabling overtake support feature
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component of FCT
  @c_switch_full   FCT_CFG_CUSTOM_IO_INTERFACE : FCT Custom I/O Interface

  @pre             -
  @post            -

  @created         -
  @changed         12/16/2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
boolean CP_b_ACC_CheckObjForOvertake(ObjNumber_t iObj)
{
  boolean bRetVal;

  /* If the lane change counter is active (non-zero) and the object we
  are being queried for, was the relevant object at activation time (iOvertakeObj)
  or the relevant object in the last cycle, then return TRUE (as this is the
  object we are overtaking or another object selected after the overtaken one
  was deselected) */
  if ((CP_CustomOvertakeAssistance.ucLaneChgDownCnt > 0u) &&
      (CP_CustomOvertakeAssistance.iOvertakeObj == iObj))
  {
    bRetVal = TRUE;
  }
  else
  {
    bRetVal = FALSE;
  }
  return bRetVal;
}

/*************************************************************************************************************************
  Functionname:    CP_b_ACC_GetCustomOvertakeAssistanceState                                                             */ /*!

  @brief           Check if overtake assistance feature active

  @description     Return TRUE if overtake assist functionality active

  @return          boolean : TRUE: overtake assist active
                             FALSE: otherwise

  @param[in]       void

  @glob_in         CP_CustomOvertakeAssistance : Structure containing data for ego lane change probablity and object being overtaken for overtake assist feature
                             CP_CustomOvertakeAssistance.ucLaneChgDownCnt : Lane change down-counter, when non-zero, then lane change is active       [full range of datatype uint8 as in Platform_types.h]
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST : Configuration switch enabling overtake support feature
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component of FCT
  @c_switch_full   FCT_CFG_CUSTOM_IO_INTERFACE : FCT Custom I/O Interface

  @pre             -
  @post            -

  @created         -
  @changed         12/16/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
boolean CP_b_ACC_GetCustomOvertakeAssistanceState(void)
{
  boolean bRet = FALSE;
  if (CP_CustomOvertakeAssistance.ucLaneChgDownCnt > 0u)
  {
    bRet = TRUE;
  }
  return bRet;
}
#endif  /* SLATE_CFG_ENABLE_OVERTAKE_ASSIST */


/*************************************************************************************************************************
  Functionname:    CP_v_ACC_Process                                                                                      */ /*!

  @brief           This function will process the CPSI data

  @description     This function will process the CPSI data

                    @startuml {CP_v_ACC_Process.png}
                        Start
                            Partition CP_v_ACC_Process {
                                If(CP_State is INIT or in error state) then (True)
                                    -Initialize the CP components
                                Else (False)
                                    -Compute the Ego Trajectory based on the types of fusion available\n (Ego course, Object Traces, Road Estimation, Camera Information, NAVI Information)
                                endif
                            }
                        End
                    @enduml

  @return          void

  @param[in]       void

  @glob_in         CP_State : flag to set operating modes of CP sub-component                                 [CP_t_State type datatype as in cp_ext.h]

  @c_switch_part   FCT_SIMU : FCT simulation switch
  @c_switch_part   SLATE_CFG_ENABLE_OVERTAKE_ASSIST : Configuration switch enabling overtake support feature
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component of FCT

  @pre             -
  @post            -

  @created         -
  @changed         12/16/2015

  @author          -
*************************************************************************************************************************/
void CP_v_ACC_Process(void)
{
  CP_t_TrajectoryInputParameter  TrajInputPara;
  TrajInputPara.bSuppressFusion  = FALSE;

  switch (CP_State)
  {
  case COMP_STATE_RUNNING:
    /* Initialize input-output data structures */
    CP_v_InitEveryCycle();

    /* get SA course data */
    CP_v_GetCourseDataEgo( &(pt_CPOutput->CP_CourseData) , (boolean)CP_CFG_USE_SLIPANGLE /*, GET_EGO_OBJ_SYNC_DATA_PTR */);

    /* Call CP custom course processing */
    CP_v_ACC_CustomCourseProc(  &(pt_CPOutput->CP_CourseData) );

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
    /* Call CP custom processing */
    CP_v_ACC_CustomTrajectoryParamProc( &TrajInputPara );
#endif /*(SLATE_CFG_ENABLE_OVERTAKE_ASSIST)*/

    /* calc TRAJECTORY */
    CP_v_CalculateTrajectory(&TrajInputPara);

    /* Call CP custom processing */
    CP_v_ACC_CustomTrajectoryPostProc(  &(pt_CPOutput->CP_TrajectoryData) );
    break;

  case COMP_STATE_NOT_INITIALIZED:
  case COMP_STATE_TEMPORARY_ERROR:
  case COMP_STATE_PERMANENT_ERROR:
  default:
    /* Initialize CP component */
    CP_v_ACC_Init();
    break;
  }
  _PARAM_UNUSED (TrajInputPara.b_dummy);
}

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
/*************************************************************************************************************************
  Functionname:    CP_v_DetermineObjectLaneChange                                                              */ /*!

  @brief           This function gives the direction of the lane change (LEFT or RIGHT) of 10 traces

  @description     Checks the lateral velocity of the traces and gives the direction of the lane change

                   @startuml
                   skinparam defaultTextAlignment center
                   Start
                     Partition CP_v_DetermineObjectLaneChange {
                     If (FCT Object ID with \n given Trace ID is Valid \n AND \n No of points for the given trace \n >= Minimum Trace points) then (True)
                       : Calculate fYDiffAvg i.e. the Average \n difference between current and \n previous curve value of each trace;
                       If (((fYDiffAvg is greater than MIN THRESHOLD \n AND \n fYDiffAvg is lesser than MAX THRESHOLD \n AND \n Target Turn Indicator State is Right) \n OR \n
                            (f_TraceEgoDifference is lesser than -MIN THRESHOLD \n AND \n f_TraceEgoDifference greater is than than -MAX THRESHOLD)) \n AND\n
                            (Traffic Orientation is Right)) then (True)
                         : Set Target Lane Change to RIGHT;
                         : Set the Right Turn Indicator CutOut Flag;
                         If (f_TraceEgoDifference is lesser than -MIN THRESHOLD \n AND \n f_TraceEgoDifference is greater than than -MAX THRESHOLD) then (True)
                           : Set the Trace Right Lane CutOut Flag;
                         EndIf
                       Else if (((fYDiffAvg is lesser than -MIN THRESHOLD \n AND \n fYDiffAvg is greater than MAX THRESHOLD \n AND \n Target Turn Indicator State is Right) \n OR \n
                                 (f_TraceEgoDifference is greater than MIN THRESHOLD \n AND \n f_TraceEgoDifference is lesser than MAX THRESHOLD)) \n AND\n
                                 (Traffic Orientation is Left)) then (True)
                         : Set Target Lane Change to LEFT;
                         : Set the Left Turn Indicator CutOut Flag;
                         If (f_TraceEgoDifference is greater than MIN THRESHOLD \n AND \n f_TraceEgoDifference is lesser than MAX THRESHOLD)
                           : Set the Trace Left Lane CutOut Flag;
                         EndIf
                       Else
                         If (Right Turn Indicator CutOut Flag is FALSE \n AND \n Left Turn Indicator CutOut Flag is FALSE) then (True)
                           : Set Traget Lane Change to NONE;
                         EndIf  
                       Endif

                       If (Right Turn Indicator CutOut Flag is TRUE) then (True)
                         : Set Target Lane Change to RIGHT;
                         If (f_TraceEgoDifference is greater than C_F32_DELTA \n AND \n f_TraceEgoDifference is lesser than than -MAX THRESHOLD) then (True)
                           : Reset the Right Turn Indicator CutOut Flag;
                           : Reset the Trace Right Lane CutOut Flag;
                         Else If (Target Turn Indicator State is Not Right \n AND \n Trace Right Lane CutOut Flag is FALSE)
                           : Reset the Right Turn Indicator CutOut Flag;
                         EndIf
                       EndIf

                       If (Left Turn Indicator CutOut Flag is TRUE) then (True)
                         : Set Target Lane Change to LEFT;
                         If (f_TraceEgoDifference is lesser than -C_F32_DELTA \n AND \n f_TraceEgoDifference is greater than than MAX THRESHOLD) then (True)
                           : Reset the Left Turn Indicator CutOut Flag;
                           : Reset the Trace Left Lane CutOut Flag;
                         Else If (Target Turn Indicator State is Not Left \n AND \n Trace Left Lane CutOut Flag is FALSE)
                           : Reset the Left Turn Indicator CutOut Flag;
                         EndIf
                       EndIf
                     Endif
                   }
                   End
                   @enduml

  @return          -

  @param[in]       iTr : Trace ID as defined in Rte_type.h ObjectTraces_t is an array of size 10  [0...10]
  @param[in]       MOT2CIR : Pointer to structure of type CML_t_TrafoMatrix2D defined in cml_mat.h
                        Transformation Matrix to Circle Coordinate System (with Rotation)
  @param[in]       iObjNr :  Object number of the trace                                           [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_CPInput : Pointer to CP input structure
                     t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                     t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->uiReferenceToFCTObject : The reference FCT Object Id with given trace id    [0 ... EM_N_OBJECTS-1] 
                     t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointX[iS] : The X coordinate of given trace ID                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                     t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointY[iS] : The Y coordinate of given trace ID                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pt_FIPOA->t_ObjList[iObj].t_CamObjectData.eTurnLightsState : Target Turn Indicator state                           [FIP_t_CamTurnLightsState as defined in slate_types.h]
  @glob_out        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iObjNr].t_TraceLaneChange : Lane Change info of the trace       [LC_RIGHT ... LC_LEFT]

  @c_switch_part   CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT : Configuration switch to use the Target Turn Indicator from Camera to determine the Target Cut-Out
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING           : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                     : FCT support for CP sub-component as defined in fct_config.h
  @c_switch_full   SLATE_CFG_PARALLEL_LANE_CHANGE                : Configuration switch for enabling Parallel lane change detection

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author          Rahul Raj | Rahul.Raj@continental-corporation.com | +91 (80) 6679-7305
*************************************************************************************************************************/
void CP_v_DetermineObjectLaneChange(TraceID_t iTrace, const GDBTrafoMatrix2D_t * MOT2CIR)
{
  sint8 iS;
  /* Defining local variable to reference pointer in function */
  sint8 i_NumberOfPoints= pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].iNumberOfPoints;
  float32 fYDiffCur = 0.f, fYDiffLst = 0.f, fYDiffAvg = 0.f;
#if (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT)
  FIP_t_CamTurnLightsState eTurnLightsState;
#endif /* (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT) */
  ObjNumber_t iObj;
  float32 f_TraceEgoDifference;
  SLATE_t_TrafficOrientation t_FIPTrafficOrientation = pt_CPInput->pt_FIPTO->t_FIPTrafficOrientation;

  if (    (pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID) 
       && (i_NumberOfPoints >= CP_PARALLELISM_MIN_LENGTH_TRACE) )
  {
    const float32 InvNoPts = (1.f / (float32)(i_NumberOfPoints - 1));
    iObj = (ObjNumber_t)pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;
#if (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT)
    eTurnLightsState = pt_CPInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.eTurnLightsState;
#endif /* (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT) */

    /* Determine the Trace Cut out and calculate the path difference between the Trace and Ego/ACC Course */
    CP_v_TraceCutOutDetection(iTrace, iObj);

    f_TraceEgoDifference = pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].f_AveragePathDifference;

    for (iS = 0; iS < i_NumberOfPoints ; iS ++ )
    {
      float32 fX = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[iS];
      float32 fY = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointY[iS];
      float32 C1, C2;
      C1 = CP_TraceAdd[iTrace].ApproxPoly.fC1;
      C2 = CP_TraceAdd[iTrace].ApproxPoly.fC2;
      GDBmathTrafoPos2D(MOT2CIR, &fX, &fY ); 

      fYDiffCur = ((2.f * C2 * fX) + (C1));

      if (iS > 0)
      {        
        fYDiffAvg += (fYDiffCur - fYDiffLst);
      }

      fYDiffLst = fYDiffCur;
    }

    fYDiffAvg *= InvNoPts;

    if (   ((   (fYDiffAvg > CP_OBJECT_LANE_CHANGE_MIN_THRESHOLD) && (fYDiffAvg < CP_OBJECT_LANE_CHANGE_MAX_THRESHOLD)
#if (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT)
                /* Check if the the Target Turn Indicator is Right*/
             && (eTurnLightsState == FIP_CAM_TURN_LIGHT_RIGHT)
#endif /* (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT) */
            )
                /* Check if Trace Ego/ACC Path Difference is within the threshold*/
            || ((f_TraceEgoDifference < -CP_EGO_ACC_TRACE_DIFF_MIN_THRESHOLD) && (f_TraceEgoDifference > -CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD))
           )
           /* Check if Traffic Orientation is Left since Overtake Assist is dependent on this*/
        && (t_FIPTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT)
       )
    {
      /* Set Trace Lane Change direction to the RIGHT */
      pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].t_TraceLaneChange = SLATE_LC_RIGHT;
      /* Set the Right Turn Indicator CutOut Flag */
      pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetRightTurnIndicatorCutOut = TRUE;

      if ((f_TraceEgoDifference < -CP_EGO_ACC_TRACE_DIFF_MIN_THRESHOLD) && (f_TraceEgoDifference > -CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD))
      {
        /* Set the Trace Right Lane CutOut Flag */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetTraceRightLaneCutOut = TRUE;
      }
    }
    else if (   ((   (fYDiffAvg < -CP_OBJECT_LANE_CHANGE_MIN_THRESHOLD) && (fYDiffAvg > -CP_OBJECT_LANE_CHANGE_MAX_THRESHOLD)
#if (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT)
                     /* Check if the the Target Turn Indicator is Left*/
                  && (eTurnLightsState == FIP_CAM_TURN_LIGHT_LEFT)
#endif /* (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT) */
                 )
                     /* Check if Trace Ego/ACC Path Difference is within the threshold*/
                 || ((f_TraceEgoDifference > CP_EGO_ACC_TRACE_DIFF_MIN_THRESHOLD) && (f_TraceEgoDifference < CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD))
                )
                /* Check if Traffic Orientation is Left since Overtake Assist is dependent on this*/
             && (t_FIPTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT)
            )
    {
      /* Set Trace Lane Change direction to the LEFT */
      pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].t_TraceLaneChange = SLATE_LC_LEFT;
      /* Set the Left Turn Indicator CutOut Flag */
      pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetLeftTurnIndicatorCutOut = TRUE;

      if ((f_TraceEgoDifference > CP_EGO_ACC_TRACE_DIFF_MIN_THRESHOLD) && (f_TraceEgoDifference < CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD))
      {
        /* Set the Trace Left Lane CutOut Flag */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetTraceLeftLaneCutOut = TRUE;
      }
    }
    else
    {
            /* Check if Left Turn Indicator CutOut Flag and Right Turn Indicator CutOut Flag is FALSE */
      if (   (pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetLeftTurnIndicatorCutOut == FALSE)
          && (pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetRightTurnIndicatorCutOut  == FALSE)
         )
      {
        /* Set Trace Lane Change direction to the NONE */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].t_TraceLaneChange = SLATE_LC_NONE;
      }
    }

    if (pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetRightTurnIndicatorCutOut == TRUE)
    {
      /* If Right Turn Indicator CutOut Flag is TRUE then set Trace Lane Change direction to the RIGHT*/
      pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].t_TraceLaneChange = SLATE_LC_RIGHT;

      if ((f_TraceEgoDifference > C_F32_DELTA) || (f_TraceEgoDifference < -CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD))
      {
        /*Reset the Right Turn Indicator CutOut Flag and the Trace Right Lane CutOut Flag */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetTraceRightLaneCutOut     = FALSE;
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetRightTurnIndicatorCutOut = FALSE;
      }
      else if (
#if (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT)
                /* Check if the the Target Turn Indicator is Not Right*/
               (eTurnLightsState != FIP_CAM_TURN_LIGHT_RIGHT) && 
#endif /* (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT) */
               (pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetTraceRightLaneCutOut == FALSE)
              )
      {
        /*Reset the Right Turn Indicator CutOut Flag */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetRightTurnIndicatorCutOut = FALSE;
      }
    }
    else if (pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetLeftTurnIndicatorCutOut == TRUE)
    {
      /* If Left Turn Indicator CutOut Flag is TRUE then set Trace Lane Change direction to the LEFT*/
      pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].t_TraceLaneChange = SLATE_LC_LEFT;

      if ((f_TraceEgoDifference < -C_F32_DELTA) || (f_TraceEgoDifference > CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD))
      {
        /*Reset the Left Turn Indicator CutOut Flag and the Trace Left Lane CutOut Flag */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetTraceLeftLaneCutOut     = FALSE;
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetLeftTurnIndicatorCutOut = FALSE;
      }
      else if (
#if (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT)
               /* Check if the the Target Turn Indicator is Not Left*/
               (eTurnLightsState != FIP_CAM_TURN_LIGHT_LEFT)  &&
#endif /* (CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT) */
               (pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetTraceLeftLaneCutOut == FALSE)
              )
      {
        /*Reset the Left Turn Indicator CutOut Flag */
        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].b_SetLeftTurnIndicatorCutOut = FALSE;
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:    CP_v_TraceCutOutDetection                                                              */ /*!

  @brief           This function determines the Trace Cut out and calculates the path difference between the Trace and Ego/ACC Course

  @description     Determine the Trace Cut out and calculate the path difference between the Trace and Ego/ACC Course

  @return          -
 @startuml
                   @startuml
                   skinparam defaultTextAlignment center
                   Partition LA_v_RelTraRestrictObjTrace{
                   Start
                   : Initialize Longitudinal distance of the object, Difference between\n EGO path and relevant object trace, Difference between ACC trajectory\n and relevant object trace, road type;
                   : Get the object distance;
                   : Store polynomial trace parameters;
                   : Get road type information;
                   If (valid trace and EGO is traveling above a certain speed\n and road type is highway and longitudinal distance\n in within limits) then (TRUE)
                   : Get the crossing distance between object trace and EGO/ACC-trajectory;
                   If (Crossing Distance is more than Delta and\n Cross distance is less than object distance) then (TRUE)
                   : Get the path difference threshold based on object distance;
                   : Get difference between EGO course and object trace as an area integral\n between intersection to longitudinal distance of the object from EGO;
                   : Get difference between the ACC-Trajectory and object trace as an area integral\n between intersection to longitudinal distance of the object from EGO;
                   Else (FALSE)
                   : Get the path difference threshold based on object distance;
                   : Get difference between EGO course and object trace as an area integral\n between EGO Position to longitudinal distance of the object from EGO;
                   : Get difference between the ACC-Trajectory and object trace as an area integral\n between EGO Position to longitudinal distance of the object from EGO;
                   Endif
                   : Get Average Path difference;
                   Endif
                   End
                   }
                   @enduml

  @param[in]       iTr : Trace ID as defined in Rte_type.h ObjectTraces_t is an array of size 10  [0...10]
  @param[in]       iObjNr :  Object number of the trace                                           [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_CPInput : Pointer to CP input structure
                     t_RTE.pf_EgoLongVel  : Ego speed                                                                                   [-330.f ... 330.f] m/s
                     t_RTE.pf_ObjLongDisp : Object Longitudinal distance                                                                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                     pt_FIPRoadType->t_FIPFusedRoadType.pt_FusedRoadType : Reference to FIP road type                                   [Full range of eRoadType_t as in Rte_Type.h]
                     t_SIT.pf_CrossingDistTrace : longitudinal crossing point of the trajectory and the corresponding trace trajectory  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_CPOutput->CP_TrajectoryData.Current.fTrajC1 : Trajectory clothoid parameter                                       [-1 … +1] m^-2
  @glob_in         pt_CPOutput->CP_TrajectoryData.Current.fTrajC0 : Trajectory clothoid parameter                                       [-1 … +1] m^-1
  @glob_in         *pt_CPInput->t_RTE.pf_EgoCurve : Ego curve                                                                           [-1 … +1] m^-1
  @glob_in         pt_CPOutput->CP_TracePoly[iTrace]
                      CP_TracePoly[i].fC0 : Trace approximation polynomial                                                              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      CP_TracePoly[i].fC1 : Trace approximation polynomial                                                              [-1.f...+1.f]
                      CP_TracePoly[i].fC2 : Trace approximation polynomial                                                              [-1f....+1.f]
                      CP_TracePoly[i].isValid : Flag to indicate if trace polynomial is valid                                           [TRUE,FALSE]
  @glob_out        pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iObjNr].f_AveragePathDifference : Path Difference between the Trace and Ego/ACC Course

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING           : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                     : FCT support for CP sub-component as defined in fct_config.h
  @c_switch_full   SLATE_CFG_PARALLEL_LANE_CHANGE                : Configuration switch for enabling Parallel lane change detection

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author          Rahul Raj | Rahul.Raj@continental-corporation.com | +91 (80) 6679-7305
*************************************************************************************************************************/
void CP_v_TraceCutOutDetection(TraceID_t iTrace, ObjNumber_t iObj)
{
  float32 fTemp1, fTemp2, fCrossDist, f_AveragePathDifference;
  float32 fObjDist = 0.f;               /* Longitudinal distance of the object */
  float32 f_EgoObjPathDiffAvg = 0.f;    /* Difference between EGO path and relevant object trace, normalized to distance between EGO and relevant object */
  float32 f_SATrajObjPathDiffAvg = 0.f; /* Difference between ACC trajectory and relevant object trace, normalized to distance between EGO and relevant object */
  CAL_t_TracePolyL2 pTracePoly;
#if (FCT_CFG_INPUT_PREPROCESSSING)
  FIP_t_FusedRoadType t_FIPFusedRoadType = (pt_CPInput->pt_FIPRoadType->t_FIPFusedRoadType); /* HIGHWAY=3, NOINFO=0, CITY=1, COUNTYROAD=2 */
#endif /* (FCT_CFG_INPUT_PREPROCESSSING) */
  const float32 f_EgoSpeed = *pt_CPInput->t_RTE.pf_EgoLongVel;
  fObjDist = *pt_CPInput->t_RTE.pf_ObjLongDisp(iObj);
 
  /* Store polynomial trace parameters of trace iTrace*/
  pTracePoly = pt_CPOutput->CP_TracePoly[iTrace];
    
  if ((pTracePoly.isValid == TRUE) && 
      (f_EgoSpeed >= CP_EGO_ACC_TRACE_DIFF_EGO_SPEED_THRES) &&
#if (FCT_CFG_INPUT_PREPROCESSSING)
      (t_FIPFusedRoadType == FIP_ROAD_TYPE_HIGHWAY) &&
#endif /* (FCT_CFG_INPUT_PREPROCESSSING) */
      (fObjDist >= CP_EGO_ACC_TRACE_DIFF_MIN_LONG_DISP) && (fObjDist < CP_EGO_ACC_TRACE_DIFF_MAX_LONG_DISP)
     )
  {
    /* Get the intersection between object trace and EGO/ACC-trajectory */
    fCrossDist = *(pt_CPInput->t_SIT.pf_CrossingDistTrace(iObj));

    if ((fCrossDist > C_F32_DELTA) && (fCrossDist < fObjDist))
    {
      /* Computation of the difference between EGO course and object trace as an area integral between intersection to longitudinal distance of the object from EGO, normalized to x */
      f_EgoObjPathDiffAvg = (((((pTracePoly.fC2 - (0.5f * (*pt_CPInput->t_RTE.pf_EgoCurve))) * fObjDist * (2.f/3.f)) + pTracePoly.fC1) * fObjDist * 0.5f) -
                             ((((pTracePoly.fC2 - (0.5f * (*pt_CPInput->t_RTE.pf_EgoCurve))) * fCrossDist * (2.f/3.f)) + pTracePoly.fC1) * fCrossDist * 0.5f));

      /* Computation of the difference between the ACC-Trajectory and object trace as an area integral between intersection to longitudinal distance of the object from EGO, normalized to x */
      fTemp1 = -0.25f * pt_CPOutput->CP_TrajectoryData.Current.fTrajC1 * fObjDist;
      fTemp2 = (2.f * pTracePoly.fC2) - pt_CPOutput->CP_TrajectoryData.Current.fTrajC0;
      f_SATrajObjPathDiffAvg = (((fTemp1 + fTemp2) * (fObjDist/3.f) ) + pTracePoly.fC1) * fObjDist * 0.5f;

      fTemp1 = -0.25f * pt_CPOutput->CP_TrajectoryData.Current.fTrajC1 * fCrossDist;
      fTemp2 = (2.f * pTracePoly.fC2) - pt_CPOutput->CP_TrajectoryData.Current.fTrajC0;
      f_SATrajObjPathDiffAvg = f_SATrajObjPathDiffAvg - ((((fTemp1 + fTemp2) * (fCrossDist/3.f) ) + pTracePoly.fC1) * fCrossDist * 0.5f);
    } 
    else
    {
      /* Computation of the difference between EGO course and object trace as an area integral between EGO Position to longitudinal distance of the object from EGO, normalized to x */
      f_EgoObjPathDiffAvg = (((pTracePoly.fC2 - (0.5f * (*pt_CPInput->t_RTE.pf_EgoCurve))) * fObjDist * (2.f/3.f)) + pTracePoly.fC1) * fObjDist * 0.5f;

      /* Computation of the difference between the ACC-Trajectory and object trace as an area integral between EGO Position to longitudinal distance of the object from EGO, normalized to x */
      fTemp1 = -0.25f * pt_CPOutput->CP_TrajectoryData.Current.fTrajC1 * fObjDist;
      fTemp2 = (2.f * pTracePoly.fC2) - pt_CPOutput->CP_TrajectoryData.Current.fTrajC0;
      f_SATrajObjPathDiffAvg = (((fTemp1 + fTemp2) * (fObjDist/3.f) ) + pTracePoly.fC1) * fObjDist * 0.5f;

    } /* Check if Object trace intersects the EGO/ACC-Trajectory */

    /* Either of the computation or the average of the two computations can be used, here the average is considerd */
    f_AveragePathDifference = (f_EgoObjPathDiffAvg + f_SATrajObjPathDiffAvg)/2.f;

    /*Update the Average Path Difference to the Global variable*/
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].f_AveragePathDifference = f_AveragePathDifference;
  }
}
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

/** @} end defgroup */
#endif /*FCT_CFG_COURSE_PREDICTION*/
