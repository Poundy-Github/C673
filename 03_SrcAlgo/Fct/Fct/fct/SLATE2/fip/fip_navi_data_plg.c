/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_navi_data_plg.c

DESCRIPTION:               ACC FCT Preprocessing of Navi Data

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             21.08.2014

VERSION:                   $Revision: 1.14 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

// PRQA S 7013 STTLN_EXCEEDED
/* date: 2017-02-17, reviewer: Harsha Umesh Babu, Chintan Raval, reason: Number of lines exceeded per file, not safety critical */
/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_navi_data_plg FIP Navi Data
@ingroup fip
@brief          Preprocessing of Navi data. FIP Navi ports are initialised and updated with relevant data before
	            being used for navi related calculations. \n\n

@{

*/
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
#include "fip_navi_data_process.h"

/*****************************************************************************
  GLOBAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/

/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/
#define FIP_BRANCH_DISTANCE_TIME_GAP      (4.0f)  /*!< time gap threshold for Navi Branch detection */
#define FIP_ANGLE_PPREV_BRANCH_MIN        (10.0f)
#define FIP_ANGLE_PPREV_BRANCH_MAX        (170.0f)
#define FIP_NAVI_UINT8_THRES              (250u)  /*!< Threshold to compare uint8 */

/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (SLATE_CFG_CAM_LANE_INTERFACE)
static boolean FIPDrivingOnHighwayBasedOnCameraLaneWidth(void);
static boolean FIPDrivingOnMultilanePathBasedOnCamera(void);
#endif

#if (FIP_EVAL_SHAPE_POINTS)
static void FIP_v_CalcPositionShapePoint(float32 * pf_XPosShapePoint, float32 * pf_YPosShapePoint, const float32 f_LengthSeg, const float32 f_AngleSeg, 
                                                const float32 f_XPosSegStart,const float32 f_YPosSegStart, const float32 f_AngleAccu);
#endif

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_NaviSetLastCycleMotionParams                                                               */ /*!

  @brief           Update motion parameters for current cycle

  @description     Update motion parameters such as velocity, acceleration, yaw rate, slip and cycle time for current cycle. 
                   Information is used for navi path ego compensation.
  
  @startuml 
  Partition FIP_v_NaviSetLastCycleMotionParams
  Start
  	- Update motion parameters such as velocity, \n acceleration, yaw rate, slip and cycle time for current cycle 
  Stop
  @enduml

  @return          -

  @param[in,out]   p_VehicleMotionParaLastCycle : Reference to structure containing EGO motion data in current cycle
                     f_Velocity : velocity          [-330.f ... 330.f] m/s
                     f_Acceleration : acceleration     [-100.f ... 100.f] m/s2
                     f_YawRate : yaw rate          [-100.f ... 100.f] rad/s
                     f_Slip : slip             [0.f]
                     f_CycleTime : cycle time        [0.f ... 1.f] s

  @glob_in         pt_FIP_RTE_Input->pf_EgoVelObjSync : ego speed                           [-330.f ... 330.f] m/s
  @glob_in         pt_FIP_RTE_Input->pf_EgoAccObjSync : ego acceleration                    [-100.f ... 100.f] m/s2
  @glob_in         SLATE_f_GetEgoYawRateObjSync() : ego yaw rate                       [-100.f ... 100.f] rad/s
  @glob_in         SLATE_f_GetCycleTime() : cycle time                                [0.f ... 1.f] s

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         27.01.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_NaviSetLastCycleMotionParams(FIPNaviVehicleMotionParameters_t * p_VehicleMotionParaLastCycle)
{
  p_VehicleMotionParaLastCycle->f_Velocity = *pt_FIP_RTE_Input->pf_EgoVelObjSync;
  p_VehicleMotionParaLastCycle->f_Acceleration = *pt_FIP_RTE_Input->pf_EgoAccObjSync;
  p_VehicleMotionParaLastCycle->f_YawRate = SLATE_f_GetEgoYawRateObjSync();
  p_VehicleMotionParaLastCycle->f_Slip = 0.f; /*NOT using slip in ego motion computation for now! */
  p_VehicleMotionParaLastCycle->f_CycleTime = SLATE_f_GetCycleTime();
}
#endif

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_NaviInitVehicleMotionParameters                                                            */ /*!

  @brief           Initialize the vehicle ego motion parameters

  @description     Initialize the vehicle ego motion parameters. Information is used for navi path ego compensation.

  @startuml
  Partition FIP_v_NaviSetLastCycleMotionParams
  Start
	  - Initialize the vehicle ego motion parameters
  Stop
  @enduml

  @return          -

  @param[in,out]   p_VehicleMotionParameters : Reference to structure containing EGO motion information
                     f_Velocity : velocity          [0.f] m/s
                     f_Acceleration : acceleration     [0.f] m/s2
                     f_YawRate : yaw rate          [0.f] rad/s
                     f_Slip : slip             [0.f]
                     f_CycleTime : cycle time        [0.f] s
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         27.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_NaviInitVehicleMotionParameters(FIPNaviVehicleMotionParameters_t * p_VehicleMotionParameters)
{
  p_VehicleMotionParameters->f_Velocity = 0.f;
  p_VehicleMotionParameters->f_Acceleration = 0.f;
  p_VehicleMotionParameters->f_YawRate = 0.f;
  p_VehicleMotionParameters->f_Slip = 0.f;
  p_VehicleMotionParameters->f_CycleTime = 0.f;
}
#endif


#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_f_NaviGetArcLengthSeg                                                                        */ /*!

  @brief           Get the arc length of a segment

  @description     Get the arc length of a segment based on the curvature and the longitudinal 
                   distance between two shape points
                   assumption: circular segments (constant curvature over segment)
  
  @startuml 
    Partition FIP_f_NaviGetArcLengthSeg
    Start
  	  Note right: This function is used to get the arc length of a segment
  	  - Set default arc length with longitudinal distance between two shape points
  	  If (Curvature is close to zero) 
  		- Calculate Arc length using radius and linear distance between circle points
  	  Else (False)
    		- The arc length is the same as the distance \n between the sample points between segments
  	  	
  	  Endif
    Stop
  @enduml

  @return          f_ArcLengthSeg : Arc length of the segment                         [0.f ... 400.f] rad

  @param[in]       f_SegLengthLine : Longitudinal distance between two shape points   [0.f ... 400.f] m
  @param[in]       f_SegCurvature : Curvature of the segment                          [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         27.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
float32 FIP_f_NaviGetArcLengthSeg(float32 const f_SegLengthLine, float32 const f_SegCurvature)
{
  float32 f_ArcLengthSeg;

  /*! Set default value: arc length si the longitudinal distance between two shape points */
  f_ArcLengthSeg = f_SegLengthLine;

  /*! If the curvature is close to zero, the arc length is the same as the distance between the sample points between segments */
  if( (fABS(f_SegCurvature) > C_F32_DELTA) && (f_SegLengthLine > C_F32_DELTA))
  {
    /*! Arc length = 2 * radius * arcsin( (linear distance between circle points) /(2*radius) ) */
    float32 f_ProdTemp = 0.5f * f_SegLengthLine * f_SegCurvature;
    /*! Check if definition range of ASIN_ is valid */
    if(fABS(f_ProdTemp) < (1.f - C_F32_DELTA))
    {
      f_ArcLengthSeg = (2.f/f_SegCurvature) * ASIN_(f_ProdTemp);
    }
  }

  return f_ArcLengthSeg;
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */


/*************************************************************************************************************************
  Functionname:    FIPCheckNaviPathNumberLanes                                                                      */ /*!

  @brief           Evaluate if the reported number of lanes by the navi is plausible

  @description     Evaluate if the reported number of lanes by the navi is plausible using NAVI street type, camera 
                   information indicating a street with more than one lane and ego velocity
  
  @startuml 
  Partition FIPCheckNaviPathNumberLanes
  Start
	  Note right: This function evaluates if the reported number of lanes by the navi is plausible
	  - Check if any segment has only one number of lane and the street type corresponds to one lane is True

	  If(Any segment has only one number of lane and the street type corresponds to one lane \n AND \n Ego speed is over Minimum ego speed which indicates a highway \n AND \n The camera lanes indicate a highway or a street with more than one lane) then (True)
    		- Navi number of lanes is not valid
    Else(no)
    Endif
  Stop
  @enduml

  @return          b_ValidNaviNumberLanes : information if the number of lanes in navi can be trusted [TRUE, FALSE]

  @param[in]       *p_NaviData : Reference to incoming NAVI data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[
                        u_QuanLanes : number of lanes [0u ... FIP_NAV_MAX_VALID_LANE_NUM]
                        TypStreet : street type [t_NavStreetType as in Rte_Type.h]

  @glob_in         pt_FIP_RTE_Input->pf_EgoVelObjSync : ego speed [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         27.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
boolean FIPCheckNaviPathNumberLanes(const t_NaviInputData *p_NaviData)
{
  boolean b_ValidNaviNumberLanes;
  boolean b_OneLaneAndOneLaneStreetType;
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  boolean b_DrivingOnHighwayBasedOnCamera;
  boolean b_DrivingOnMultilanePathBasedOnCamera;
#endif
  uint32 i;

  /*! Set default value */
  b_ValidNaviNumberLanes = TRUE;

  /*! Check if any segment has only one number of lane and the street type corresponds to one lane 
  (i.e. no highway/highway i/o) */
  b_OneLaneAndOneLaneStreetType = FALSE;

  for(i = 0u; (i < FIP_NAVI_MAXSEG_FORDATAVALIDITY) && (b_OneLaneAndOneLaneStreetType == FALSE); i++)
  {
    if( (p_NaviData->Segments[i].u_QuanLanes == 1u) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_INTERSTATE_HIGHWAY_RAMP) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_INTERSTATE_HIGHWAY) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY_RAMP) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY_DIVIDER) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_URBAN_INTERSTATE_HIGHWAY) &&
        (p_NaviData->Segments[i].TypStreet != NAV_STT_RACETRACK)
      )
    {
      b_OneLaneAndOneLaneStreetType = TRUE;
    }
  }

#if (SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Evaluate if the camera lanes indicate a highway -> a street with more than one lane */
  b_DrivingOnMultilanePathBasedOnCamera = FIPDrivingOnMultilanePathBasedOnCamera();
  b_DrivingOnHighwayBasedOnCamera = FIPDrivingOnHighwayBasedOnCameraLaneWidth();
#endif

  /*! Navi path is implausible, if the navi reports one lane and a one-lane street type, but the ego vehicle is 
      driving very fast and if the camera indicates a highway/multi lane path */
  if( (b_OneLaneAndOneLaneStreetType == TRUE ) 
      && (*pt_FIP_RTE_Input->pf_EgoVelObjSync >= FIP_NAVI_MIN_SPEED_HIGHWAY) 
#if (SLATE_CFG_CAM_LANE_INTERFACE)
      && ( (b_DrivingOnMultilanePathBasedOnCamera) ||
           (b_DrivingOnHighwayBasedOnCamera)
         )
#endif
    )
  {
    b_ValidNaviNumberLanes = FALSE;
  }

  return b_ValidNaviNumberLanes;
}


#if (SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIPDrivingOnHighwayBasedOnCameraLaneWidth                                                        */ /*!

  @brief           Evaluate if the camera lane width indicates a highway

  @description     Evaluate if the camera lane width indicates a highway using existence probability, signal status and 
                   marker distance
  
  @startuml 
  Partition FIPDrivingOnHighwayBasedOnCameraLaneWidth
  Start
	  Note right: This function evaluates if the camera lane width indicates a highway
	
	  If (Existance Probability of left and right \n lane marker is higher than threshold \n AND \n Signal header status is OK) then (True)
    		- Calculate lane width
    Else (False)
    Endif

  	If (Lane width is higher than lane width on a highway) then (True)
  		- Ego is driving on highway
  	Else (False)
 		- Ego is not driving on highway
	  Endif
  Stop
  @enduml

  @return          b_DrivingOnHighwayBasedOnCameraLaneWidth: information, if the camera lane width indicates a highway 
                                                                                    [TRUE, FALSE]

  @param[in]       -

  @glob_in         pSLATE_CamLaneData : Camera lane information. Structure of type t_CamLaneInputData, defined in Rte_Type.h
                        LaneMarkerInfo[i] : Lane marker information with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]
                          u_ExistanceProbability : Probability of existence for camera lane marker [0u ... 100u] %
                          f_MarkerDist : Distance to camera lane marker [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        sSigHeader.eSigStatus : Signal header status [AlgoSignalState_t as in Rte_SWCAlnAdapt_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static boolean FIPDrivingOnHighwayBasedOnCameraLaneWidth(void)
{
  boolean b_DrivingOnHighwayBasedOnCameraLaneWidth;
  float32 f_CamEgoLaneWidth;

  /*! Default value */
  b_DrivingOnHighwayBasedOnCameraLaneWidth = FALSE;

  /*! Determine the ego camera lane width */
  f_CamEgoLaneWidth = 0.f;
  if( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
      (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
      (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    f_CamEgoLaneWidth = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist - 
      pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;
  }

  /*! Highway if ego lane width exceeds threshold */
  if(f_CamEgoLaneWidth > FIP_NAVI_HIGHWAY_LANE_WIDTH) 
  {
    b_DrivingOnHighwayBasedOnCameraLaneWidth = TRUE;
  }

  return b_DrivingOnHighwayBasedOnCameraLaneWidth;
}
#endif /* SLATE_CFG_CAM_LANE_INTERFACE */

#if (SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIPDrivingOnMultilanePathBasedOnCamera                                                           */ /*!

  @brief           Evaluate if the camera lanes indicate a multi lane path

  @description     Evaluate if the camera lanes indicate a multi lane path
                   Multilane path is considered if all four camera lane markers are visible or if (in right hand traffic) 
                   a far right lane is detected and the right lane is striped and the distance between the right and far 
                   right is within limits (reversible for left hand traffic)
  
  @startuml 
    Partition FIPDrivingOnMultilanePathBasedOnCamera
    Start
    	Note right: This function evaluates if the camera lanes indicate a multi lane path
    	If(Existance Probability of all four \n lane marker is higher than Threshold \n AND \n Signal header status is OK) then (True)
     		- Driving on multilane
    	Else (False)
    	Endif
  
    	If (Traffic orientation is right hand side) then (True)
    		If (A far right lane is detected and the right lane \n is striped and the distance between the right \n and far right is within limits) then (True)
    			- Driving on multilane
    		Else (False)
  			- Not driving on multilane
    		Endif
    	Else (False) 
  	  If(traffic orientation is left hand side) then (True)
    		If (A far left lane is detected and the left lane \n is striped and the distance between the left \n and far left is within limits) then (True)
    			- Driving on multilane
    		Else (False)
    		Endif
    	Else (False)
    			- Not driving on multilane
    	Endif
  	  Endif
    Stop
  @enduml

  @return          b_DrivingOnMultilanePath : information, if the camera lane indicates a multi lane path [TRUE, FALSE]

  @param[in]       -

  @glob_in         pSLATE_CamLaneData: Camera lane input data
                      LaneMarkerInfo[i] lane marker information
                      with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]
                        u_ExistanceProbability : Probability of existence for camera lane marker [0u ... 100u] %
                        MarkerType : Camera lane marker type [t_MarkerType as in Rte_Type.h]
                        f_MarkerDist : Distance to camera lane marker [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      sSigHeader.eSigStatus : Signal header status [AlgoSignalState_t as in Rte_SWCAlnAdapt_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static boolean FIPDrivingOnMultilanePathBasedOnCamera(void)
{
  boolean b_DrivingOnMultilanePath;
  boolean b_FourValidCamLanes;
  t_CamLaneMarkerEnum CamLaneMarkerIx;
  SLATE_t_TrafficOrientation t_TrafficOrientation;

  /*! Default value: no multi lane path */
  b_DrivingOnMultilanePath = FALSE;

  /*! Check if all four camera lane markers are visible -> multi lane path */
  b_FourValidCamLanes = TRUE;
  for(CamLaneMarkerIx = FIP_CL_MK_ADJ_LEFT; 
      ((CamLaneMarkerIx < FIP_CL_NUM_LANES) && (b_FourValidCamLanes == TRUE)); CamLaneMarkerIx++)
  {
    if( (pSLATE_CamLaneData->LaneMarkerInfo[CamLaneMarkerIx].u_ExistanceProbability < FIP_CAM_LANE_POE_LEVEL) || 
        (pSLATE_CamLaneData->sSigHeader.eSigStatus != AL_SIG_STATE_OK)
      )
    {
      b_FourValidCamLanes = FALSE;
    }
  }

  /*! It is considered a multi lane path if all four camera lane markers are visible 
      (i.e. three lanes/ four markers are visible) */
  if(b_FourValidCamLanes == TRUE)
  {
    b_DrivingOnMultilanePath = TRUE;
  }

  /*! Check if there is a second lane for vehicles driving in the same direction -> multi lane path 
      (depends on the traffic orientation) */
  t_TrafficOrientation = FIP_pt_TO_GetTrafficOrientation()->t_FIPTrafficOrientation;  /* Get fused traffic orientation */

  switch (t_TrafficOrientation)
  {
    case SLATE_TRAFFIC_ORIENTATION_RIGHT:
      /*! Driving on a multi lane path, if a far right lane is detected and the right lane is striped and 
        the distance between the right and far right is within limits 
        (only right lane evaluated, since left lane could be oncoming lane) */
      if( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
          (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
          ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].MarkerType == CL_MARKER_TYPE_DASHED) ||
            (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].MarkerType == CL_MARKER_TYPE_DOTTED) ||
            (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].MarkerType == CL_MARKER_TYPE_NARROWDASHED)
          ) &&
          ( ( pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - 
              pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].f_MarkerDist) > FIP_NAVI_MIN_VALID_SECOND_LANE_WIDTH) &&
          ( ( pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - 
              pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_RIGHT].f_MarkerDist) < FIP_NAVI_MAX_VALID_SECOND_LANE_WIDTH)
        )
      {
        b_DrivingOnMultilanePath = TRUE;
      }
      break;
    case SLATE_TRAFFIC_ORIENTATION_LEFT:
      /*! Driving on a multi lane path, if a far left lane is detected and the left lane is striped and 
          the distance between the left and far left is within limits 
          (only left lane evaluated, since right lane could be oncoming lane) */
      if( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
          (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
          ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].MarkerType == CL_MARKER_TYPE_DASHED) ||
            (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].MarkerType == CL_MARKER_TYPE_DOTTED) ||
            (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].MarkerType == CL_MARKER_TYPE_NARROWDASHED)
          ) &&
          ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].f_MarkerDist - 
             pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist) > FIP_NAVI_MIN_VALID_SECOND_LANE_WIDTH) &&
          ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_ADJ_LEFT].f_MarkerDist - 
             pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist) < FIP_NAVI_MAX_VALID_SECOND_LANE_WIDTH)
        )
      {
        b_DrivingOnMultilanePath = TRUE;
      }
      break;
    case SLATE_TRAFFIC_ORIENTATION_UNKNOWN:
    default:
      /*! Leave default value of false, since traffic orientation not known */
      break;
  }

  return b_DrivingOnMultilanePath;
}
#endif /*!< SLATE_CFG_CAM_LANE_INTERFACE */


#if( FIP_EVAL_SHAPE_POINTS )
/*************************************************************************************************************************
  Functionname:    FIP_b_DrivingDifferentFromNaviPath                                                               */ /*!

  @brief           Evaluate if ego-vehicle drives different from reported NAVI path

  @description     Evaluate if ego-vehicle drives different from reported NAVI path
                   hint: actual implementation without logic -> always returns FALSE
  
  @startuml 
  Partition FIP_b_DrivingDifferentFromNaviPath
  Start
  	- Evaluate if ego-vehicle drives different from reported navigation path
  Stop
  @enduml

  @return          b_DrivingDifferentFromNaviPath : information, if ego-vehicle is driving different from navi path [FALSE]

  @param[in]       *p_FIPShapePointsInNaviRef : Reference to data structure containing shape points in NAVI reference coordinate system
                      f_AvgEGOPathDiff: average difference between navi and ego lane [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
boolean FIP_b_DrivingDifferentFromNaviPath(const FIPNaviReferenceShapePoint_t *p_FIPShapePointsInNaviRef)
{
  /* Implementation changed in such a way that this is independent of approximation: eg. based on sample points and ego path -> ONLY history SPs are considered */
  boolean b_DrivingDifferentFromNaviPath;
  
  /*! Default value */
  b_DrivingDifferentFromNaviPath = FALSE;

  if (p_FIPShapePointsInNaviRef->f_AvgEGOPathDiff > FIP_MAX_DIFF_EGO_TO_NAVI)
  {
    /* CHECK - f_AvgEGOPathDiff > 3.75 causes new tree to be constructed, but for further control of fusion decision this function uses the threshold FIP_MAX_DIFF_EGO_TO_NAVI */
    /* b_DrivingDifferentFromNaviPath = FALSE; */
  }
  
  return b_DrivingDifferentFromNaviPath;
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPGetCubicSplineBasedOnShapePoints                                                              */ /*!

  @brief           Determine a cubic spline based on given shape points

  @description     Determine a cubic spline based on given shape points using CML_CalculateCubicSplineClamped

  @startuml 
  Partition FIPGetCubicSplineBasedOnShapePoints
  Start
  	Note right: This function determines a cubic spline based on given shape points
	  - Determine the slope for the first and last shape point for the cubic spline interpolation
     	If (At least one point is present) then (True)
     		- Compute spline
  	  Else (False)
  	  Endif 
  Stop
  @enduml

  @return          -

  @param[in,out]   p_NaviShapePointInEgoRef : navi shape point in ego referenc structure 
                     af_XPosShapePointEgoRef[i] : X-position of point i all shape points in ego reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                     with i in [0...FIP_NUM_NAVI_REF_SHAPE_POINTS[
                     af_YPosShapePointEgoRef[i] : Y-position of point i all shape points in ego reference  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     with i in [0...FIP_NUM_NAVI_REF_SHAPE_POINTS[
                     ui_NumberOfShapePoints : Number of shape points in EGO reference coordinate system [0u ... FIP_NUM_NAVI_PATH_SHAPE_POINTS[
                     af_ParaA : Parameter for the spline of each segment [-100.f ... 100.f]
                     af_ParaB : Parameter for the spline of each segment [-100.f ... 100.f]
                     af_ParaC : Parameter for the spline of each segment [-100.f ... 100.f]
                     af_ParaD : Parameter for the spline of each segment [-100.f ... 100.f]
                     ab_SegmentSplineValid : Info the interpolated spline for a single segment was valid [TRUE, FALSE]
                     b_SplineValid : info if entire spline interpolation was valid [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIPGetCubicSplineBasedOnShapePoints(FIPNaviShapePointEgo_t* p_NaviShapePointInEgoRef)
{
  uint8 i;
  float32 f_SlopeStart, f_SlopeEnd, f_DiffDistXEnd;
  /*! Allocate memory for structures which are used in CML_CalculateCubicSplineClamped(...) */
  Vector2_f32_t ShapePointVector[FIP_NUM_NAVI_PATH_SHAPE_POINTS]; /*!< Position if the shape points */
  float32 af_Matrix   [ (FIP_NUM_NAVI_PATH_SHAPE_POINTS) * 
                        (FIP_NUM_NAVI_PATH_SHAPE_POINTS)]; /*!< Matrix for calculating the parameters */
  float32 af_MatrixInv[ (FIP_NUM_NAVI_PATH_SHAPE_POINTS) * 
                        (FIP_NUM_NAVI_PATH_SHAPE_POINTS)]; /*!< Inverse matrix of af_Matrix */
  float32 af_Temp     [ (FIP_NUM_NAVI_PATH_SHAPE_POINTS) * 
                        (FIP_NUM_NAVI_PATH_SHAPE_POINTS)]; /*!< Temporary matrix necessary for calculating af_MatrixInv */
  float32 af_YVector  [  FIP_NUM_NAVI_PATH_SHAPE_POINTS ]; /*!< Vector for calculating the parameters. Contains x- and y-differences between shape points */
  float32 af_MatrixInvXYVector[FIP_NUM_NAVI_PATH_SHAPE_POINTS]; /*!< Vector containing the results of the matrix multiplication af_MatrixInvXYVector = af_MatrixInv * af_YVector */


  /*! Store the position of the shape points in a format that can be used by GDB_Math_CalculateCubicSpline(...) */
  for (i = 0u; i < FIP_NUM_NAVI_PATH_SHAPE_POINTS; i++)
  {
    if(i < p_NaviShapePointInEgoRef->ui_NumberOfShapePoints)
    {
      ShapePointVector[i].fXDist = p_NaviShapePointInEgoRef->af_XPosShapePointEgoRef[i];
      ShapePointVector[i].fYDist = p_NaviShapePointInEgoRef->af_YPosShapePointEgoRef[i];
    }
    else
    {
      ShapePointVector[i].fXDist = 0.f;
      ShapePointVector[i].fYDist = 0.f;
    }
  }

  /*! Get the cubic splines */

  /*! Determine the slope for the first and last shape point for the cubic spline interpolation */
  f_SlopeStart = 0.f;   /*!< Slope at the ego position should be zeros */
  f_SlopeEnd = 0.f;     /*!< Slope at the last shape point is assumed to be the slope in the last segment */
  f_DiffDistXEnd = 0.f; /*!< Set init value */
  /*! The slope can be better estimated by the curvature */
  /*! x-difference between shape points of the last segment */
  if (p_NaviShapePointInEgoRef->ui_NumberOfShapePoints >= 2u)
  {
    f_DiffDistXEnd = p_NaviShapePointInEgoRef->af_XPosShapePointEgoRef[p_NaviShapePointInEgoRef->ui_NumberOfShapePoints - 1u] - 
      p_NaviShapePointInEgoRef->af_XPosShapePointEgoRef[p_NaviShapePointInEgoRef->ui_NumberOfShapePoints - 2u];
  }
  if(fABS(f_DiffDistXEnd) > C_F32_DELTA)
  {
    /*! Slope in the last segment */
    f_SlopeEnd = (p_NaviShapePointInEgoRef->af_YPosShapePointEgoRef[p_NaviShapePointInEgoRef->ui_NumberOfShapePoints - 1u] - 
      p_NaviShapePointInEgoRef->af_YPosShapePointEgoRef[p_NaviShapePointInEgoRef->ui_NumberOfShapePoints - 2u]) / f_DiffDistXEnd;
  }

  /*! Get the cubic spline (clamped -> f_SlopeStart and f_SlopeEnd are given) */
  if (p_NaviShapePointInEgoRef->ui_NumberOfShapePoints > 0u)
  {
    /* Compute splines if at least one point is present! */
    p_NaviShapePointInEgoRef->b_SplineValid = CML_CalculateCubicSplineClamped(p_NaviShapePointInEgoRef->ui_NumberOfShapePoints, ShapePointVector, 
      f_SlopeStart, f_SlopeEnd, af_Matrix, af_MatrixInv, af_Temp, af_YVector, af_MatrixInvXYVector,
      p_NaviShapePointInEgoRef->af_ParaA, p_NaviShapePointInEgoRef->af_ParaB, p_NaviShapePointInEgoRef->af_ParaC, p_NaviShapePointInEgoRef->af_ParaD, p_NaviShapePointInEgoRef->ab_SegmentSplineValid);
  }
  
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_f_CalcSampleYPosForSpline                                                                    */ /*!

  @brief           Determine the y-position of a sample point in a given spline

  @description     Determine the y-position of a sample point in a given spline based on the x-position relative to the 
                   beginning of the corresponding segment
                   according to
                        y = f_ParaA + f_ParaB * (x - x_i) + f_ParaC*(x - x_i)^2 + f_ParaD*(x - x_i)^3 for x in [x_i x_(i+1)]
                        i = index of the segment
  
  @startuml 
  Partition FIP_f_CalcSampleYPosForSpline
  Start
  	Note right: This function determines the y-position of a sample point \n in a given spline
	  - Compute square of the x-position of the sample point relative to the beginning of the corresponding segment
  	- Compute Y-position of the sample point 
  Stop
  @enduml

  @return          f_YPosSample : y-position of a sample point in a given spline          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       f_SampleXPosRelToSegment : x-position of the sample point relative to the beginning of the corresponding segment
                                                                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_ParaA : Parameter for describing the spline of a given i-th segment  [-100.f ... 100.f]
  @param[in]       f_ParaB : Parameter for describing the spline of a given i-th segment  [-100.f ... 100.f]
  @param[in]       f_ParaC : Parameter for describing the spline of a given i-th segment  [-100.f ... 100.f]
  @param[in]       f_ParaD : Parameter for describing the spline of a given i-th segment  [-100.f ... 100.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
float32 FIP_f_CalcSampleYPosForSpline(const float32 f_SampleXPosRelToSegment, const float32 f_ParaA, 
  const float32 f_ParaB, const float32 f_ParaC, const float32 f_ParaD)
{
  float32 f_YPosSample, f_SampleXPosRelToSegmentSqr;

  /*! Square of the x-position of the sample point relative to the beginning of the corresponding segment */
  f_SampleXPosRelToSegmentSqr = SQR(f_SampleXPosRelToSegment);

  /*! Y-position of the sample point according to
      y = f_ParaA + f_ParaB * (x - x_i) + f_ParaC*(x - x_i)^2 + f_ParaD*(x - x_i)^3 for x in [x_i x_(i+1)]*/
  f_YPosSample = f_ParaA + (f_ParaB * f_SampleXPosRelToSegment) + 
    (f_ParaC * f_SampleXPosRelToSegmentSqr) + (f_ParaD * f_SampleXPosRelToSegmentSqr * f_SampleXPosRelToSegment);

  return f_YPosSample;
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_CalcPositionShapePoint                                                                     */ /*!

  @brief           Determine the position of the second shape point of segment based on a given distance and angle to the 
                   next shape point relative to the beginning of the entire "segment tree"

  @description     Determine the position of the second shape point of segment based on a given distance and angle to the 
                   next shape point relative to the beginning of the entire "segment tree"
                   hint: only valid for representation in which the angle directly gives the direction from first to second 
                         point of segment, not if the angle is the tangential angle to the previous segment in the starting 
                         point of the segment
  
  @startuml 
  Partition FIP_v_CalcPositionShapePoint
  Start
	  Note right: This function determines the position of the second shape point of segment
	  - Determine the sin/cos of the accumulated angle of all previous segments
	  - Compute Position of the next shape point \n in the local coordinate system at the origin of a segment
	  - Rotate the coordinate system by the accumulated \n rotation angle between the origin of the current segment \n and navigation path 
  	- Move coordinate system to the origin \n of the navigation path 
  Stop
  @enduml

  @return          -

  @param[out]      pf_XPosShapePoint : X-position of the next shape point relative to the beginning of the entire "segment tree"
                                                                                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[out]      pf_YPosShapePoint : y-position of the next shape point relative to the beginning of the entire "segment tree"
                                                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       f_LengthSeg : Distance to the next shape point                           [full range of float32 >= 0.f] m
  @param[in]       f_AngleSeg : Angle between the previous segment and the next shape point [-180.f ... 180.f] rad
  @param[in]       f_XPosSegStart : x-position of the beginning of the considered segment   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_YPosSegStart : y-position of the beginning of the considered segment   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       f_AngleAccu : Accumulated angle of all previous segments                 [-180.f ... 180.f] rad

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_CalcPositionShapePoint(float32 * pf_XPosShapePoint, float32 * pf_YPosShapePoint, const float32 f_LengthSeg, const float32 f_AngleSeg, 
                                                const float32 f_XPosSegStart,const float32 f_YPosSegStart, const float32 f_AngleAccu)
{
  float32 f_SinAngleAccuLocal, f_CosAngleAccuLocal, f_XPosLocal, f_YPosLocal, f_XPosRot, f_YPosRot;

  /*! Determine the sin/cos of the accumulated angle of all previous segments */
  f_SinAngleAccuLocal = SIN_HD_(f_AngleAccu);
  f_CosAngleAccuLocal = COS_HD_(f_AngleAccu);

   /*! First: Position of the next shape point in the local coordinate system at the origin of a segment */
  f_XPosLocal = COS_HD_(f_AngleSeg) * f_LengthSeg;
  f_YPosLocal = SIN_HD_(f_AngleSeg) * f_LengthSeg;

  /*! Second: Rotate the coordinate system by the accumulated rotation angle between the origin of the current segment and 
          the coordinate system at the origin of the NAVI path ("segment tree") */
  f_XPosRot = (f_CosAngleAccuLocal * f_XPosLocal) - (f_SinAngleAccuLocal * f_YPosLocal);
  f_YPosRot = (f_SinAngleAccuLocal * f_XPosLocal) + (f_CosAngleAccuLocal * f_YPosLocal);

  /*! Third: Move coordinate system to the origin of the NAVI path ("segment tree") */
  (*pf_XPosShapePoint) = f_XPosRot + f_XPosSegStart;
  (*pf_YPosShapePoint) = f_YPosRot + f_YPosSegStart;
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPGetNaviRefShapePoints                                                                         */ /*!

  @brief           Get the position of the shape points of the NAVI path in NAVI reference coordinates

  @description     Get the position of the shape points of the NAVI path in NAVI reference coordinates
                   If a Segments with an angle higher than a threshold is found, this segment and all following segments 
                   are discarded.

  @startuml 
  Partition FIPGetNaviRefShapePoints
  Start
  	Note right: This function is used to get the position of the shape points of the NAVI path in NAVI reference coordinates
  	If(Angle between the segments is higher than a threshold) then (True)
  		- Discard following segment
  		- Set the position of the shape point to the position of the previous shape point
  		- Make tree extendable
  	Else (no)
  		- Get position of next shape point
  		- Make tree not extendable
  	Endif
  	- Adapt the accumulated orientation
  Stop
  @enduml

  @return          -

  @param[in]       ui_IdxSegNaviOrig : Segment ID of NAVI origin                              [full range of uint8]
  @param[in]       ui_IdxSegNaviEnd : Segment ID of NAVI end                                  [full range of uint8]
  @param[in,out]   pFIPShapePointsInNaviRef : Pointer to data structure containing all shape point related information
                     af_AlphaShapePointNaviRef[i] : Angle  of segment i of current NAVI path [-180.f ... 180.f] rad
                     with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
                     af_LengthShapePointNaviRef[i] : Length of segment i of current NAVI path [0.f ... 400.f] m
                     with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
                     af_CurvatureShapePointNaviRef[i] : Curvature of segment i of current NAVI path [-1.f ... 1.f]
                     with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
                     au_ProbTakeBranchShapePointNaviRef[i] : Probability of segment i that EGO takes branch of current NAVI path [0u ... 100u] %
                     with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
                     ui_IndexLastSPInBuffer : Index indicating the last filled position in shape point array [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                     b_TreeExtendable : Info if the tree can be extended by adding shape points [TRUE, FALSE]
                     af_XPosShapePointNaviRef[i] : X-position of segment i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                     with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
                     af_YPosShapePointNaviRef[i] : Y-position of segment i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
  @param[in]       f_XPosOrigin : X Origin of the NAVI tree [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_YPosOrigin : Y Origin of the NAVI tree [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIPGetNaviRefShapePoints(uint8 ui_IdxSegNaviOrig, uint8 ui_IdxSegNaviEnd, FIPNaviReferenceShapePoint_t * pFIPShapePointsInNaviRef, float32 f_XPosOrigin, float32 f_YPosOrigin)
{
  sint8 s_IdxFirstHighAngleBetweenSeg;
  float32 f_AngleAccu, f_AngleSeg;
  uint8 i, j;    /*Generic index variable used in this function */
  
  uint8 ui_NumOfSegmentsExpected = (ui_IdxSegNaviEnd - ui_IdxSegNaviOrig);
  uint8 ui_NumOfShapePointsExpected = ui_NumOfSegmentsExpected + 1u;
  
  /* If everything goes well, then we end with same number of segments and shape points as expected - Initialize optimistically!!! */
  uint8 ui_NumOfSegmentsProcessed = (ui_IdxSegNaviEnd - ui_IdxSegNaviOrig);
  uint8 ui_NumOfShapePointsProcessed = ui_NumOfSegmentsProcessed + 1u;
  
  /*! Local variable to store position of shape points -> max FIP_NUM_NAVI_PATH_SHAPE_POINTS number of shape points */
  float32 af_XPosShapePointNaviRef[FIP_NUM_NAVI_REF_SHAPE_POINTS];
  float32 af_YPosShapePointNaviRef[FIP_NUM_NAVI_REF_SHAPE_POINTS];

  /*! Local variable to store length/angle of segments -> max FCT_NAV_NUM_SEG number of segments */
  float32 af_AlphaAllShapePoint[FIP_NUM_NAVI_REF_SEGMENTS];
  float32 af_LengthAllShapePoint[FIP_NUM_NAVI_REF_SEGMENTS];
  float32 af_CurvatureAllShapePoint[FIP_NUM_NAVI_REF_SEGMENTS];
  uint8 au_ProbTakeBranchAllShapePoint[FIP_NUM_NAVI_REF_SEGMENTS];

  /*! Initialization of local variables and output data */
  for (i = 0u; i < FIP_NUM_NAVI_REF_SHAPE_POINTS; i++)
  {
    af_XPosShapePointNaviRef[i] = 0.f;
    af_YPosShapePointNaviRef[i] = 0.f;
  }
  for (i = 0u; i < FIP_NUM_NAVI_REF_SEGMENTS; i++)
  {
    af_AlphaAllShapePoint[i] = 0.f;
    af_LengthAllShapePoint[i] = 0.f;
    af_CurvatureAllShapePoint[i] = 0.f;
    au_ProbTakeBranchAllShapePoint[i] = 0u;
  }

  /*! First save the angle between shape points and the length of the line between shape points in a local variable */
  for (i = 0u, j = ui_IdxSegNaviOrig; i < ui_NumOfSegmentsExpected ; i++, j++) /*PRQA S 3418 */
  /* date: 2015-04-27, reviewer: Rachit Sharma (uidr5426), reason: Commas required because it is a 2-variable for-loop */
  { 
    af_AlphaAllShapePoint[i] = pFIPShapePointsInNaviRef->af_AlphaShapePointNaviRef[j];
    af_LengthAllShapePoint[i] = pFIPShapePointsInNaviRef->af_LengthShapePointNaviRef[j];
    af_CurvatureAllShapePoint[i] = pFIPShapePointsInNaviRef->af_CurvatureShapePointNaviRef[j];
    au_ProbTakeBranchAllShapePoint[i] = pFIPShapePointsInNaviRef->au_ProbTakeBranchShapePointNaviRef[i];
  }

  /*! Index of the first segment with a high angle between two segments. The segments afterwards should be discarded. 
  Set the default index to -1 -> no segment with high angle. */
  s_IdxFirstHighAngleBetweenSeg = FIP_NAVI_VALID_SEG_IDX_DEFAULT; 

  /* This function is either called from process new tree or reset function. In case the origin is shifted to (0,0), it should be handled in calling function */
  af_XPosShapePointNaviRef[0u] = f_XPosOrigin;
  af_YPosShapePointNaviRef[0u] = f_YPosOrigin;

  /*! Determine the position of the shape points send by the NAVI in this cycle relative 
  to the position of the ego position -> position of the future shape points */
  f_AngleAccu = 0.f; /*! Set the accumulated angle of the previous segments to zero */
  for (i = 0u; ((i < ui_NumOfSegmentsExpected) && (s_IdxFirstHighAngleBetweenSeg == FIP_NAVI_VALID_SEG_IDX_DEFAULT)); i++)
  {
    /*! Angle between the segments is higher than a threshold and the following segments are discarded */
    if( (fABS(af_AlphaAllShapePoint[i]) > DEG2RAD(FIP_NAVI_VALID_PATH_MAX_ANGLE)) ||
        (au_ProbTakeBranchAllShapePoint[i] > FIP_NAVI_VALID_PATH_MAX_BRANCH_PROP)
      )
    {
      s_IdxFirstHighAngleBetweenSeg = (sint8)i;
    }

    if( (af_LengthAllShapePoint[i] >= C_F32_DELTA) && (s_IdxFirstHighAngleBetweenSeg == FIP_NAVI_VALID_SEG_IDX_DEFAULT) ) 
    { 
      /*! Set angle between previous segment and next shape point */
      f_AngleSeg = af_AlphaAllShapePoint[i];
      /*! Get position of next shape point */
      FIP_v_CalcPositionShapePoint(&(af_XPosShapePointNaviRef[i + 1u]), &(af_YPosShapePointNaviRef[i + 1u]), 
        af_LengthAllShapePoint[i], af_AlphaAllShapePoint[i], af_XPosShapePointNaviRef[i], af_YPosShapePointNaviRef[i], f_AngleAccu);
    }
    else
    {
      /*! Handling of invalid length to next shape point -> Set the position of the shape point to the position of the previous shape point */
      af_XPosShapePointNaviRef[i + 1u] = af_XPosShapePointNaviRef[i];
      af_YPosShapePointNaviRef[i + 1u] = af_YPosShapePointNaviRef[i];
      f_AngleSeg = 0.f; /*! Set default value */
    }

    /*! Adapt the accumulated orientation */
    f_AngleAccu += f_AngleSeg;
  }

  /*! If segment with high difference found, the following segments are discarded.
  Loop necessary here due to handling of previous shape points */
  if(s_IdxFirstHighAngleBetweenSeg > FIP_NAVI_VALID_SEG_IDX_DEFAULT)
  {
    ui_NumOfSegmentsProcessed = (uint8) s_IdxFirstHighAngleBetweenSeg;
  }
  
  ui_NumOfShapePointsProcessed = ui_NumOfSegmentsProcessed + 1;
  pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer = ui_NumOfShapePointsProcessed - 1u;

  if (ui_NumOfShapePointsProcessed == ui_NumOfShapePointsExpected)
  {
    /* Set boolean indicating tree can extended */
    pFIPShapePointsInNaviRef->b_TreeExtendable = TRUE;
  }else
  {
    /* Don't add shape points to current tree, new tree must be built after running through currently available valid segments */
    pFIPShapePointsInNaviRef->b_TreeExtendable = FALSE;
  }

  /* Pass the generated shape points back using the pointer to FIPShapePointsInNaviRef */
  for (i = 0u; i < ui_NumOfShapePointsProcessed; i++)
  {
    pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[i] = af_XPosShapePointNaviRef[i];
    pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[i] = af_YPosShapePointNaviRef[i];
  }

  /* Pass the new set of segment info back using the pointer to FIPShapePointsInNaviRef */
  for (i = 0u; i < ui_NumOfSegmentsProcessed; i++)
  {
    pFIPShapePointsInNaviRef->af_AlphaShapePointNaviRef[i] = af_AlphaAllShapePoint[i];
    pFIPShapePointsInNaviRef->af_LengthShapePointNaviRef[i] = af_LengthAllShapePoint[i];
    pFIPShapePointsInNaviRef->af_CurvatureShapePointNaviRef[i] = af_CurvatureAllShapePoint[i];
    pFIPShapePointsInNaviRef->au_ProbTakeBranchShapePointNaviRef[i] = au_ProbTakeBranchAllShapePoint[i];
  }

  /* Reset the remaining data holders to zeros just to avoid any problems later on */
  for (i = ui_NumOfShapePointsProcessed; i < FIP_NUM_NAVI_REF_SHAPE_POINTS; i++)
  {
    pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[i] = 0.f;
    pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[i] = 0.f;
  }

  for (i = ui_NumOfSegmentsProcessed; i < FIP_NUM_NAVI_REF_SEGMENTS; i++)
  {
    pFIPShapePointsInNaviRef->af_AlphaShapePointNaviRef[i] = 0.f;
    pFIPShapePointsInNaviRef->af_LengthShapePointNaviRef[i] = 0.f;
    pFIPShapePointsInNaviRef->af_CurvatureShapePointNaviRef[i] = 0.f;
    pFIPShapePointsInNaviRef->au_ProbTakeBranchShapePointNaviRef[i] = 0u;
  }
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPGetEgoRefShapePoints                                                                          */ /*!

  @brief           Get the position of the shape points of the NAVI path in EGO reference coordinates

  @description     Get the position of the shape points of the NAVI path in EGO reference coordinates
                   In case a SP was added in this cycle, and CON2COG was compensated since EGO motion does not indicate 
                   new segment, then the shape point from before the increment of ui_IndexCurrentSegEgo should be considered 
                   for origin and all shape points are rotated and shifted according to the new origin. 
  
  @startuml 
  Partition FIPGetEgoRefShapePoints
  Start
	  Note right: This function is used to get the position of the shape points of the navigation path in EGO reference coordinates
	  - Y-Compensation based on difference between EGO path and NAVI path at last shape point
  	- Get the last shape point in navigation reference coordinates
	  - Rotate through the angle accumulated from the base of the navigation tree up to this point
  	- Shift the origin to EGO coordinate system as SP0
  	- Repeat the same for all other shape points
  Stop
  @enduml

  @return          -

  @param[in]       pFIPShapePointsInNaviRef : Pointer to data structure containing all shape point related information in 
                                              NAVI reference coordinates
                      b_TreeExtendable : Info if the tree can be extended by adding shape points [TRUE, FALSE]
                      ui_IndexCurrentSegEgo : Index indicating the position of the EGO in terms of segment [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                      af_XPosShapePointNaviRef[i] : X-position of point i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                      af_YPosShapePointNaviRef[i] : Y-position of point i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                      ui_IndexLastSPInBuffer : Index indicating the last filled position in shape point array [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
  @param[in]       pFIPNaviCON2COG : Transformation matrix from NAVI coordinate system to EGO reference coordinates
                      f00 : the elements of the matrix [-1.f ... 1.f]
                      f10 : the elements of the matrix [-1.f ... 1.f]
                      f02 : the elements of the matrix [-1.f ... 1.f]
                      f12 : the elements of the matrix [-1.f ... 1.f]
  @param[in,out]   pFIPShapePointsInEgoRef : Pointer to data structure containing all shape point related information in EGO reference coordinates
                      af_XPosShapePointEgoRef[i] : X-position of point i in ego reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      af_YPosShapePointEgoRef[i] . Y-position of point i in ego reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       b_NewSegment : Boolean indicating arrival of new segment                       [TRUE, FALSE]
  @param[in]       b_NewSegmentF : Boolean indicating forced new segment based on EGO motion data [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIPGetEgoRefShapePoints(const FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t* pFIPNaviCON2COG, FIPNaviShapePointEgo_t* pFIPShapePointsInEgoRef,
                             const boolean b_NewSegment, const boolean b_NewSegmentF)
{
  uint8 ui_IdxSP1;  
  uint8 j, k;
  /* Shape points in NAVI coordinates                 - f_SPInNaviOrig_
     Intermediate shape points during transformation  - f_PosRot_
     Shape points in EGO coordinates                  - f_SPInEgoOrig_
  */
  float32 f_SPInNaviOrig_X, f_SPInNaviOrig_Y, f_PosRot_X, f_PosRot_Y, f_SPInEgoOrig_X, f_SPInEgoOrig_Y;//, f_XDiff, f_YDiff;

  if((b_NewSegment == TRUE) && (b_NewSegmentF == FALSE) && (pFIPShapePointsInNaviRef->b_TreeExtendable == TRUE) && (pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo > 0u))
  {
    /* In case a SP was added in this cycle, and CON2COG was compensated since EGO motion does not indicate new segment, 
       then the shape point from before the increment of ui_IndexCurrentSegEgo should be considered for origin */
    ui_IdxSP1 = pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo;
  } else
  {
    ui_IdxSP1 = pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo + 1u;
  }

  /* if (pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef > 0u)
  {
  ui_IdxHistorySP = pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef - 1u;
  }
  */

  /* Y-Compensation based on difference between EGO path and NAVI path at last shape point */

  /* Get the last shape point in NAVI reference coordinates */
  f_SPInNaviOrig_X = pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[ui_IdxSP1 - 1u];
  f_SPInNaviOrig_Y = pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[ui_IdxSP1 - 1u];// + f_YDiff;
  
  /* Rotate through the angle accumulated from the base of the NAVI tree up to this point */
  f_PosRot_X = (pFIPNaviCON2COG->f00 * f_SPInNaviOrig_X) - (pFIPNaviCON2COG->f10 * f_SPInNaviOrig_Y);
  f_PosRot_Y = (pFIPNaviCON2COG->f10 * f_SPInNaviOrig_X) + (pFIPNaviCON2COG->f00 * f_SPInNaviOrig_Y);

  /* Shift the origin to EGO coordinate system as SP0 */
  pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[0u] = f_PosRot_X + pFIPNaviCON2COG->f02;
  pFIPShapePointsInEgoRef->af_YPosShapePointEgoRef[0u] = f_PosRot_Y + pFIPNaviCON2COG->f12;

  /* Repeat the same for all other shape points */
  for (j = ui_IdxSP1, k = 1u; ((j <= pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer) && (k < FIP_NUM_NAVI_PATH_SHAPE_POINTS)); j++) /*PRQA S 3418 */
  /* date: 2015-04-27, reviewer: Rachit Sharma (uidr5426), reason: Commas required because it is a 2-variable for-loop */
  {
    /* Get the shape point in NAVI reference coordinates */
    f_SPInNaviOrig_X = pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[j];
    f_SPInNaviOrig_Y = pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[j];// + f_YDiff;   /* Y-Compensation */

    /* Rotate through the angle accumulated from the base of the NAVI tree up to this point */
    f_PosRot_X = (pFIPNaviCON2COG->f00 * f_SPInNaviOrig_X) - (pFIPNaviCON2COG->f10 * f_SPInNaviOrig_Y);
    f_PosRot_Y = (pFIPNaviCON2COG->f10 * f_SPInNaviOrig_X) + (pFIPNaviCON2COG->f00 * f_SPInNaviOrig_Y);

    /* Shift the origin to EGO coordinate system */
    f_SPInEgoOrig_X = f_PosRot_X + pFIPNaviCON2COG->f02;
    f_SPInEgoOrig_Y = f_PosRot_Y + pFIPNaviCON2COG->f12;

    if (f_SPInEgoOrig_X > C_F32_DELTA)
    {
      /* All point must be ahead of EGO, i.e., > (0, y) */
      /* Store the newly computed shape point in data structure */
      pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[k] = f_SPInEgoOrig_X;
      pFIPShapePointsInEgoRef->af_YPosShapePointEgoRef[k] = f_SPInEgoOrig_Y;
      pFIPShapePointsInEgoRef->ui_NumberOfShapePoints = k + 1u;    /* Omitting 0 while using counter */
      k++;
    } /* IF f_SPInEgoOrig_X > C_F32_DELTA */
  } /* LOOP over all relevant shape points in NAVI reference */
}
#endif /*!< FIP_EVAL_SHAPE_POINTS */

/*************************************************************************************************************************
  Functionname:    FIPNaviPathIsHighway                                                                             */ /*!

  @brief           Determine if driving on a highway based on the infos of the NAVI

  @description     Determine if driving on a highway based on the street type infos of the NAVI

  @startuml 
  Partition FIPNaviPathIsHighway
  Start
  	Note right: This function determines if driving on a highway based on the infos of the navigation
  	If(Any of segment’s stree \n type is not Federal Highway \n AND \n Federal Highway Divider\n AND \n Intestate Highway \n AND \n Urban Intestate Highway \n AND \n Urban Intestate Highway Divider) then (True)
   		- Navi path is not highway
   	Else (False)
		- Navi path is not highway
  	Endif 
  Stop
  @enduml

  @return          bIsHighway : information, if driving on a highway based on the infos of the NAVI [TRUE, FALSE]

  @param[in]       *pNaviData : Reference to incoming NAVI data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        TypStreet : street type [t_NavStreetType as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
/*boolean FIPNaviPathIsHighway(const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, const t_NaviInputData *pNaviData)*/
boolean FIPNaviPathIsHighway(const t_NaviInputData *pNaviData)
{
  uint8 i;
  boolean bIsHighway;

  /*! Initialization: driving on a highway */
  bIsHighway = TRUE;

#if 0
  for(i = ui_ValidIndexStart; (i < ui_ValidIndexEnd) && (bIsHighway == TRUE) ; i++)
#endif
  for(i = 0u; (i < FIP_NAVI_MAXSEG_FORDATAVALIDITY) && (bIsHighway == TRUE) ; i++)
  {
    /* Remark: without ramp, exit and ramp_exit */
    if( (pNaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY) &&
        (pNaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY_DIVIDER) &&
        (pNaviData->Segments[i].TypStreet != NAV_STT_INTERSTATE_HIGHWAY) &&
        (pNaviData->Segments[i].TypStreet != NAV_STT_URBAN_INTERSTATE_HIGHWAY) &&
        (pNaviData->Segments[i].TypStreet != NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER)
      )
    {
      bIsHighway = FALSE;
    }
  }

  return bIsHighway;
}

/*************************************************************************************************************************
  Functionname:    FIPNaviPathIsCountryRoadOneLane                                                                  */ /*!

  @brief           Determine if driving on a country road with one lane based on the infos of the NAVI

  @description     Determine if driving on a countryroad with one lane; a main road is considered as country road

  @startuml 
  Partition FIPNaviPathIsCountryRoadOneLane
  Start
	  Note right: This function determines if driving on a country road with one lane based on the infos of the navigation
	  If(Number of used segments is greater than zero) then (True)
  		If(Navi segment street type is not Country Road Divider \n AND \n Country Road \n ANDR \n Federal Highway \n AND \n Federal Highway Divider \n AND \n Interstate Highway \n OR \n Number of lanes is not 1) then (True)
  			- Navi Path is not Country Road
  		Else (False)
  			- Navi Path is Country Road
  		Endif
  	Else (False)
  		- Navi Path is not CountryRoad
  	Endif
  Stop
  @enduml

  @return          bIsCountryRoadOneLane : information, if driving on a country road with own lane based on the info of 
                                           the NAVI       [TRUE, FALSE]

  @param[in]       *pNaviData : Reference to incoming NAVI data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        TypStreet : street type [t_NavStreetType as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
/*boolean FIPNaviPathIsCountryRoadOneLane(const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, const t_NaviInputData *pNaviData)*/
boolean FIPNaviPathIsCountryRoadOneLane(const t_NaviInputData *pNaviData)
{
  uint8 i;

  /*! Initialization: driving on a country road with one lane */
  boolean bIsCountryRoadOneLane = TRUE;

  /* Only if number of used segments is greater than zero, evaluate for country road, else return false */
  if(pNaviData->u_NumUsedSegments > 0)
  {
#if 0
    for(i = ui_ValidIndexStart; (i < ui_ValidIndexEnd) && (bIsCountryRoadOneLane == TRUE) ; i++)
#endif
    for(i = 0u; (i < FIP_NAVI_MAXSEG_FORCOUNTRYROAD) && (bIsCountryRoadOneLane == TRUE); i++)
    {
      /* Updated t_NavStreetType TypeDefs based on fct_interface_types */
      /* Replaced NAV_STT_MAIN_ROAD by
        NAV_STT_FEDERAL_HIGHWAY
        in existing IF condition, for checking if we are driving on a Country Road.
      */
      if( ( (pNaviData->Segments[i].TypStreet != NAV_STT_COUNTRY_ROAD_DIVIDER) &&
            (pNaviData->Segments[i].TypStreet != NAV_STT_COUNTRY_ROAD) &&
            (pNaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY) &&
            (pNaviData->Segments[i].TypStreet != NAV_STT_FEDERAL_HIGHWAY_DIVIDER) &&
            (pNaviData->Segments[i].TypStreet != NAV_STT_INTERSTATE_HIGHWAY) 
          ) || 
          (pNaviData->Segments[i].u_QuanLanes != 1u)
        )
      {
        bIsCountryRoadOneLane = FALSE;
      } 
    } /* End of FOR loop - u_NumUsedSegments */
  }
  else
  {  
    /*! Initialization: driving on a country road with one lane */
    bIsCountryRoadOneLane = FALSE;
  }

  return bIsCountryRoadOneLane;
}

/*************************************************************************************************************************
  Functionname:    FIPNaviPathIsInCityLimits                                                                        */ /*!

  @brief           Determine if current NAVI path indicates if EGO is in city limits

  @description     Determine if current NAVI path indicates if EGO is in city limits using NAVI street type

  @startuml 
  Partition FIPNaviPathIsInCityLimits
  Start
	  Note right: This function determines if current NAVI path indicates if EGO is in city limits
	  If(Number of used segments is greater than zero) then (True)
  		If(Navigation segemnt street type is not Traffic calm zone bidriection \n AND \n Traffic calm zone oneway \n AND \n Residential Bidrection \n AND \n Residential Oneway or Urban Bidrection \n AND \n Urban Oneway \n AND \n Urban Divider) then (True)
  			- Driving outside city limits
		Else (False)
  			- Driving inside city limits
  		Endif
  	Else (False)
  			- Driving outside city limits
  	Endif
  Stop
  @enduml

  @return          bNaviPathIsInCityLimits : information, if driving within city limits based on the infos of the 
                                             NAVI         [TRUE, FALSE]

  @param[in]       *pNaviData : Reference to incoming NAVI data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        TypStreet : street type [t_NavStreetType as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
/*boolean FIPNaviPathIsInCityLimits(const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, const t_NaviInputData *pNaviData)*/
boolean FIPNaviPathIsInCityLimits(const t_NaviInputData *pNaviData)
{
  uint8 i;

  /* Only if number of used segments is greater than zero, evaluate for city road, else return false */
  boolean bNaviPathIsInCityLimits = TRUE;
  
  if(pNaviData->u_NumUsedSegments > 0u)
  {
#if 0
    for(i = ui_ValidIndexStart; (i < ui_ValidIndexEnd) && (bNaviPathIsInCityLimits == TRUE) ; i++)
#endif
    for(i = 0u; ((i < FIP_NAVI_MAXSEG_FORCITYLIMIT) && (bNaviPathIsInCityLimits == TRUE)); i++)
    {
      /*
        Checking if we are driving on roads within city limits.
      */
      if((pNaviData->Segments[i].TypStreet != NAV_STT_TRAFFICCALMZONE_BIDIRECTION) &&
         (pNaviData->Segments[i].TypStreet != NAV_STT_TRAFFICCALMZONE_ONEWAY) &&
         (pNaviData->Segments[i].TypStreet != NAV_STT_RESIDENTIAL_BIDIRECTION) &&
         (pNaviData->Segments[i].TypStreet != NAV_STT_RESIDENTIAL_ONEWAY) &&
         (pNaviData->Segments[i].TypStreet != NAV_STT_URBAN_BIDIRECTION) &&
         (pNaviData->Segments[i].TypStreet != NAV_STT_URBAN_ONEWAY) &&
         (pNaviData->Segments[i].TypStreet != NAV_STT_URBAN_DIVIDER) 
        ) 
      {
        bNaviPathIsInCityLimits = FALSE;
      }
    } /* End of FOR loop - u_NumUsedSegments */
  }
  else
  {  
    /*! Initialization: driving outside city limits */
    bNaviPathIsInCityLimits = FALSE;
  }

  return bNaviPathIsInCityLimits;

}

#if FIP_EVAL_SHAPE_POINTS
#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckNewTreeOrSegment                                                                      */ /*!

  @brief           This function checks if EGO has entered a new segment or new tree

  @description     This function checks if EGO has entered a new segment or if incoming NAVI data indicates new tree 
                   based on last cycle and current cycle NAVI information
  
  @startuml 
  Partition FIP_v_CheckNewTreeOrSegment
  Start
  	Note right: This function checks if EGO has entered a new segment or new tree
	  - Compare length, Angel previous segment of current cycle and last cycle’s segments
   	If(Length and angel is same) then (True)
  		- No need for new segment or new tree
  	Else (False)
  		If(Length and angel of current cycle’s 1st segment and last cycle’s 2nd segment and  like that for all segments are same) then (True)
  			- Ego is in new segment
			- Save the NAVI data when entering the new segment
  		Else (False)
			- Ego is in new segment
			- New tree creation is necessory
  		Endif
  	Endif
  Stop
  @enduml

  @return          -

  @param[in,out]   p_NaviDataSegmentChange : last cycle input data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        f_Length : length of near segment [0.f ... 400.f] m
                        f_AnglePrevSeg angle of the previous segment [-180.f ... 180.f] rad
  @param[in]       pSLATE_NaviData : current cycle input data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        f_Length : length of near segment [0.f ... 400.f] m
                        f_AnglePrevSeg : angle of previous segment [-180.f ... 180.f] rad
  @param[out]      pb_NewSegment : boolean indicating if EGO has entered a new segment              [TRUE, FALSE]
  @param[out]      pb_NewTree : boolean indicating if incoming NAVI data show new tree information  [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             (FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF)
  @post            

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_CheckNewTreeOrSegment(t_NaviInputData* p_NaviDataSegmentChange, const t_NaviInputData * p_FCTSEN_pNaviData, boolean* pb_NewSegment, boolean* pb_NewTree)
{
  /* Works with default false value */
  *pb_NewTree = FALSE;
  *pb_NewSegment = FALSE;

  /*Check if we are in a known segment
  For length comparison
  Compare last cycle's 1st, 2nd, 3rd, 4th, 5th, 6th, and 7th segments
  with current cycle's 1st, 2nd, 3rd  4th, 5th, 6th, and 7th segments.
  For AnglePrevSeg comparison
  Compare last cycle's 0th, 1st, 2nd, 3rd  4th, 5th, 6th, and 7th segments
  with current cycle's 0th, 1st, 2nd, 3rd  4th, 5th, 6th, and 7th segments.
  If they are the same then we are in a known segment, if they are different
  then check if new segment has been entered
  */
  /* First check lengths */
  if( (fABS(p_NaviDataSegmentChange->Segments[1].f_Length - p_FCTSEN_pNaviData->Segments[1].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[2].f_Length - p_FCTSEN_pNaviData->Segments[2].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[3].f_Length - p_FCTSEN_pNaviData->Segments[3].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[4].f_Length - p_FCTSEN_pNaviData->Segments[4].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[5].f_Length - p_FCTSEN_pNaviData->Segments[5].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[6].f_Length - p_FCTSEN_pNaviData->Segments[6].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[7].f_Length - p_FCTSEN_pNaviData->Segments[7].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[0].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[0].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[1].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[1].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[2].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[2].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[3].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[3].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[4].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[4].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[5].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[5].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[6].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[6].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[7].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[7].f_AnglePrevSeg) < C_F32_DELTA)
    )
  {
    /* Known segment - DO NOTHING*/
    *pb_NewTree = FALSE;
    *pb_NewSegment = FALSE;
  }
  else
  {
    /* Ego vehicle is in a new segment, check if we have entered a new segment in the old tree 
      -> segments are in the same order */
    /*For length comparison
    Compare last cycle's 2nd, 3rd, 4th, 5th, 6th, 7th segments
    with current cycle's 1st, 2nd, 3rd  4th, 5th, 6th segments.

    For AnglePrevSeg comparison
    Compare last cycle's 1st, 2nd, 3rd  4th, 5th, 6th, 7th segments
    with current cycle's 0th, 1st, 2nd, 3rd  4th, 5th, 6th segments.

    If they are the same then we are in new segment, check only 3 segments for now!
    */
    if( (fABS(p_NaviDataSegmentChange->Segments[2].f_Length - p_FCTSEN_pNaviData->Segments[1].f_Length) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[3].f_Length - p_FCTSEN_pNaviData->Segments[2].f_Length) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[4].f_Length - p_FCTSEN_pNaviData->Segments[3].f_Length) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[1].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[0].f_AnglePrevSeg) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[2].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[1].f_AnglePrevSeg) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[3].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[2].f_AnglePrevSeg) < C_F32_DELTA)
      )
    {
      /* In a new Segment but still in old tree */
      *pb_NewSegment = TRUE;
      /*! Save the NAVI data when entering the new segment */
      *p_NaviDataSegmentChange = *p_FCTSEN_pNaviData;

    }
    else
    {
      /* Not in known segment, nor is it a new segment, therefore it must be a new tree! */
      *pb_NewTree = TRUE;
      /* Although a new tree is indicated, we shall build it on the basis of current tree only replacing future segments but retaining history. 
      Hence b_TreeValid is not reset! */

    }   /* Check for new segment in an old tree or if new tree is delivered without b_MppNew */
  }     /* Check for known segment */

}
#else
#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckNewTreeOrSegment                                                                      */ /*!

  @brief           This function checks if EGO has entered a new segment or new tree

  @description     This function checks if EGO has entered a new segment or if incoming NAVI data indicates new tree 
                   based on last cycle and current cycle NAVI information
  
  @startuml 
  Partition FIP_v_CheckNewTreeOrSegment
  Start
  	Note right: This function checks if EGO has entered a new segment or new tree
	  - Compare length, Angel previous segment of current cycle and last cycle’s segments
   	If(Length and angel is same) then (True)
  		- No need for new segment or new tree
  	Else (False)
  		If(Length and angel of current cycle’s 1st segment and last cycle’s 2nd segment and  like that for all segments are same) then (True)
  			- Ego is in new segment
			- Save the NAVI data when entering the new segment
  		Else (False)
			- Ego is in new segment
			- New tree creation is necessory
  		Endif
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       p_NaviDataSegmentChange : last cycle input data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        f_Length : length of near segment [0.f ... 400.f] m
                        f_AnglePrevSeg : angle of previous segment [-180.f ... 180.f] rad
  @param[in]       p_FCTSEN_pNaviData : current cycle input data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        f_Length : length of near segment [0.f ... 400.f] m
                        f_AnglePrevSeg : angle of previous segment [-180.f ... 180.f] rad
  @param[out]      pb_NewSegment : boolean indicating if EGO has entered a new segment              [TRUE, FALSE]
  @param[out]      pb_NewTree : boolean indicating if incoming NAVI data show new tree information  [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF)) == FALSE
  @post            

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         29.01.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_CheckNewTreeOrSegment(const t_NaviInputData* p_NaviDataSegmentChange, const t_NaviInputData * p_FCTSEN_pNaviData, boolean* pb_NewSegment, boolean* pb_NewTree)
{
  /* Works with default false value */
  *pb_NewTree = FALSE;
  *pb_NewSegment = FALSE;

  /*Check if we are in a known segment
  For length comparison
  Compare last cycle's 1st, 2nd, 3rd, 4th, 5th, 6th, and 7th segments
  with current cycle's 1st, 2nd, 3rd  4th, 5th, 6th, and 7th segments.
  For AnglePrevSeg comparison
  Compare last cycle's 0th, 1st, 2nd, 3rd  4th, 5th, 6th, and 7th segments
  with current cycle's 0th, 1st, 2nd, 3rd  4th, 5th, 6th, and 7th segments.
  If they are the same then we are in a known segment, if they are different
  then check if new segment has been entered
  */
  /* First check lengths */
  if( (fABS(p_NaviDataSegmentChange->Segments[1].f_Length - p_FCTSEN_pNaviData->Segments[1].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[2].f_Length - p_FCTSEN_pNaviData->Segments[2].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[3].f_Length - p_FCTSEN_pNaviData->Segments[3].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[4].f_Length - p_FCTSEN_pNaviData->Segments[4].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[5].f_Length - p_FCTSEN_pNaviData->Segments[5].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[6].f_Length - p_FCTSEN_pNaviData->Segments[6].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[7].f_Length - p_FCTSEN_pNaviData->Segments[7].f_Length) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[0].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[0].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[1].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[1].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[2].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[2].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[3].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[3].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[4].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[4].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[5].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[5].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[6].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[6].f_AnglePrevSeg) < C_F32_DELTA) && 
    (fABS(p_NaviDataSegmentChange->Segments[7].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[7].f_AnglePrevSeg) < C_F32_DELTA)
    )
  {
    /* Known segment - DO NOTHING*/
    *pb_NewTree = FALSE;
    *pb_NewSegment = FALSE;
  }
  else
  {
    /* Ego vehicle is in a new segment, check if we have entered a new segment in the old tree 
      -> segments are in the same order */
    /*For length comparison
    Compare last cycle's 2nd, 3rd, 4th, 5th, 6th, 7th segments
    with current cycle's 1st, 2nd, 3rd  4th, 5th, 6th segments.

    For AnglePrevSeg comparison
    Compare last cycle's 1st, 2nd, 3rd  4th, 5th, 6th, 7th segments
    with current cycle's 0th, 1st, 2nd, 3rd  4th, 5th, 6th segments.

    If they are the same then we are in new segment, check only 3 segments for now!
    */
    if( (fABS(p_NaviDataSegmentChange->Segments[2].f_Length - p_FCTSEN_pNaviData->Segments[1].f_Length) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[3].f_Length - p_FCTSEN_pNaviData->Segments[2].f_Length) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[4].f_Length - p_FCTSEN_pNaviData->Segments[3].f_Length) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[1].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[0].f_AnglePrevSeg) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[2].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[1].f_AnglePrevSeg) < C_F32_DELTA) && 
      (fABS(p_NaviDataSegmentChange->Segments[3].f_AnglePrevSeg - p_FCTSEN_pNaviData->Segments[2].f_AnglePrevSeg) < C_F32_DELTA)
      )
    {
      /* In a new Segment but still in old tree */
      *pb_NewSegment = TRUE;
    }
    else
    {
      /* Not in known segment, nor is it a new segment, therefore it must be a new tree! */
      *pb_NewTree = TRUE;
      /* Although a new tree is indicated, we shall build it on the basis of current tree only replacing future segments but retaining history. 
      Hence b_TreeValid is not reset! */

    }   /* Check for new segment in an old tree or if new tree is delivered without b_MppNew */
  }     /* Check for known segment */
}
#endif /* END FCT_SIMU */
#endif /* FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS && (FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON)
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckNewTreeOrSegmentWithSegID                                                             */ /*!

  @brief           This function checks if EGO has entered a new segment or new tree

  @description     This function checks if EGO has entered a new segment or if incoming NAVI data indicates new tree 
                   based on last cycle and current cycle NAVI information
  
  @startuml 
  Partition FIP_v_CheckNewTreeOrSegmentWithSegID
  Start
	  Note right: This function checks if EGO has entered a new segment or new tree with Segment ID
	  - Check if the order of the segments is valid
  		If (Ego is in same segment) then (True)
  			If (The order of the later segments are same) then (True)
  				- Segment order is valid
  			Else (False)
  				- Segment order is not valid
  			Endif
		Else (False)
  			If (The order of the later segments are same) then (True)
  				- Segment order is valid
  			Else (False)
  				- Segment order is not valid
  			Endif
  		Endif
  	
	  If (Segment order is valid) then (True)
  		- No need to create new tree
  		If(ego is in same segment) then (True)
  			- Need to change segment
  		Else (False)
  			- No need to change segment
  		Endif
  	Else (False)
  		- Need to create new tree
  		- No need to change segment
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       au_SegIDSegmentChange[i] : segment ID of last segment change [full range of uint8] 
                   with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
  @param[in]       p_FCTSEN_pNaviData : current cycle NAVI input data
                      u_NumUsedSegments : number of the used segments [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        u_SegmentID : Segment IDs of the navi path when entering a new segment [full range of uint8]
  @param[out]      pb_NewSegment : boolean indicating if EGO has entered a new segment              [TRUE, FALSE]
  @param[out]      pb_NewTree : boolean indicating if incoming NAVI data show new tree information  [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             (FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON)
  @post            

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_CheckNewTreeOrSegmentWithSegID(uint16 au_SegIDSegmentChange[], const t_NaviInputData * p_FCTSEN_pNaviData, boolean* pb_NewSegment, boolean* pb_NewTree)
{
  boolean b_EgoInSameSeg;
  boolean b_ValidSegOrder;
  uint8 i;

  /* Set default values for return values */
  *pb_NewTree = FALSE;
  *pb_NewSegment = FALSE;

  /*! Initialize local value */
  b_EgoInSameSeg = TRUE;  /*!< Ego is in the same segment as before */
  b_ValidSegOrder = TRUE; /*!< Segment order is valid */

  /*! When entering a new segment, the segment ID of the first segment changes (and of the later segments as well) */
  if (p_FCTSEN_pNaviData->Segments[SEGMENT_0].u_SegmentID != au_SegIDSegmentChange[SEGMENT_0])
  {
    b_EgoInSameSeg = FALSE;
  }

  /*! Check if the order of the segments is valid */
  /* If the first segments are the same, the order of the later segments needs to be identical */
  if (b_EgoInSameSeg == TRUE)
  {
    /*! Remark: For-loop starts with the second segment since the first segment is checked before */
    for (i = SEGMENT_1; (i < p_FCTSEN_pNaviData->u_NumUsedSegments) && (b_ValidSegOrder == TRUE); i++) 
    {
      if(p_FCTSEN_pNaviData->Segments[i].u_SegmentID != au_SegIDSegmentChange[i])
      {
        b_ValidSegOrder = FALSE;
      }
    }
  }
  else /* If the ID of the first segment is different (= entering a new segment), 
       the ID of the first segment needs to be identical with the ID of the second segment in the last cycle an so on. */
  {
    for (i = 0u; (i < (p_FCTSEN_pNaviData->u_NumUsedSegments - 1u)) && (b_ValidSegOrder == TRUE); i++)
    {
      if(p_FCTSEN_pNaviData->Segments[i].u_SegmentID != au_SegIDSegmentChange[i + 1u])
      {
        b_ValidSegOrder = FALSE;
      }
    }
  }

  /*! Set pb_NewTree and pb_NewSegment */
  if(b_ValidSegOrder == FALSE)
  {
    *pb_NewTree = TRUE;
    *pb_NewSegment = FALSE;
  }
  else
  {
    *pb_NewTree = FALSE;
    if(b_EgoInSameSeg == FALSE)
    {
      *pb_NewSegment = TRUE;
    }
    else
    {
      *pb_NewSegment = FALSE;
    }
  }
}
#endif
#endif /* FIP_NAV_USE_SEG_ID is ON/OFF */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPCheckNaviSegmentForced                                                                        */ /*!

  @brief           This function checks if EGO has entered a new segment using EGO motion information

  @description     This function checks if EGO has entered a new segment using EGO motion information

  @startuml 
  Partition FIPCheckNaviSegmentForced
  Start
  	Note right: This function checks if EGO has entered a new segment using EGO motion information
	  If(index of last shape point in buffer is more than current ego segment) then (True)
  		- Get the shape point in navigation reference coordinates
  		- Rotate through the angle accumulated from the base of the navigation tree up to this point
  		- Shift the origin to EGO coordinate system
  		If(Distance in navi segment0 is greater than length of ego segment and ego is at other plcae than origin of segment) then (True)
  			- Forced new segment is true
  		Else (False)
  		Endif
  	Else (False)
  	Endif
  Stop
  @enduml

  @return          -

  @param[in,out]   pNaviEGOSegment : reference to information about ego segment 
                     f_DistInNaviSeg0 : Driven distance of ego vehicle in the first segment (segment 0) [0.f ... 400.f] m
                     f_Length : length of near segment [0.f ... 400.f] m
                     b_ForcedNewSegment : Boolean indicating if the current segment was forced [TRUE, FALSE]
  @param[out]      pb_NewSegmentF : reference to boolean indicating if EGO has entered a new segment based on EGO motion monitoring [TRUE, FALSE]
  @param[in,out]   pFIPShapePointsInNaviRef : reference to all shape point information along with segment info
                    ui_IndexLastSPInBuffer : Index indicating the last filled position in shape point array [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                    ui_IndexCurrentSegEgo : ui_IndexCurrentSegEgo : Index indicating the position of the EGO in terms of segment [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                    af_XPosShapePointNaviRef[i] : X-position of point i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                    af_YPosShapePointNaviRef[i] : Y-position of segment i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                    ui_CountSegmentForced : Counter for number of consecutive forced segments [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
  @param[in]       pFIPNaviCON2COG : reference to transformation matrix from NAVI reference coordinates to EGO reference coordinates
                    f00 : the elements of the matrix [-1.f ... 1.f]
                    f10 : the elements of the matrix [-1.f ... 1.f]
                    f02 : the elements of the matrix [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIPCheckNaviSegmentForced(FIPNaviEgoSegmentInfo_t* pNaviEGOSegment, boolean* pb_NewSegmentF, FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t* pFIPNaviCON2COG)
{
  uint8 ui_IdxSP1;
  float32 f_SPInNaviOrig_X, f_SPInNaviOrig_Y, f_PosRot_X, f_SPInEgoOrig_X;

  if(pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer > pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo)
  {
    ui_IdxSP1 = pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo + 1u;

    /* Get the shape point in NAVI reference coordinates */
    f_SPInNaviOrig_X = pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[ui_IdxSP1];
    f_SPInNaviOrig_Y = pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[ui_IdxSP1];

    /* Rotate through the angle accumulated from the base of the NAVI tree up to this point */
    f_PosRot_X = (pFIPNaviCON2COG->f00 * f_SPInNaviOrig_X) - (pFIPNaviCON2COG->f10 * f_SPInNaviOrig_Y);

    /* Shift the origin to EGO coordinate system */
    f_SPInEgoOrig_X = f_PosRot_X + pFIPNaviCON2COG->f02;

    if((pNaviEGOSegment->f_DistInNaviSeg0 >= pNaviEGOSegment->f_Length) && (f_SPInEgoOrig_X < C_F32_DELTA ))
    {
      *pb_NewSegmentF = TRUE;
      pFIPShapePointsInNaviRef->ui_CountSegmentForced += 1u;
      if (pNaviEGOSegment->b_ForcedNewSegment == TRUE)
      {
        /* Current segment already forced, therefore add one extra to forced counter. 
           This is a special case when second segment force is required at the same time when new segment is arriving for filling in first spot */
        pFIPShapePointsInNaviRef->ui_CountSegmentForced += 1u;
      }
      /* This is set after new segment 'actual force' operation */
      pNaviEGOSegment->b_ForcedNewSegment = FALSE;
    }
  }
  
}
#endif

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPAddNaviShapePoint                                                                             */ /*!

  @brief           This function adds a new shape point to the existing tree

  @description     This function adds a new shape point based on the new segment information received from incoming NAVI data

  @startuml 
  Partition FIPAddNaviShapePoint
  Start
  	Note right: This function adds a new shape point to the existing tree
	  If(Number of used segments is over 0) then (True)
		  - Compute Angle, Length. Curvature of the new segment
		  - Compute Probability that EGO takes branch
	  Else (False)
	  Endif

	  If(Index of last shape point in buffer is over 0 \n AND \n less than Total number of segments in navigation reference coordinate system) then (True)
		  - Origin for the new shape point is the last shape point
	  Else (False)
	  Endif

	  - Compute cumulative angle from origin in NAVI reference to last shape point
	  - Get position of next shape point
  	- Update Shape Points In Navi Reference data structure with new segment info and shape point
		
  Stop
  @enduml

  @return          -

  @param[in]       pNaviInputData : Reference to incoming NAVI data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        f_AnglePrevSeg : angle of the previous segment [-180.f ... 180.f] rad                                                           [-180.f ... 180.f]
                        f_Length : f_Length : length of near segment [0.f ... 400.f] m                                                                [0.f ... 400.f]
                        f_Curvature : Curvature change of the camera lane [-1.f ... 1.f]
                        u_ProbEgoTakesBranch : Probility the ego vehicle takes branch [0u ... 100u] %
  @param[in,out]   pFIPShapePointsInNaviRef : Reference to data structure holding NAVI segment information and all the shape points in NAVI reference coordinates
                     ui_IndexLastSPInBuffer : Index indicating the last filled position in shape point array [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                     af_XPosShapePointNaviRef[i] : X-position of point i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                                  af_YPosShapePointNaviRef[i] : Y-position of point i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                     af_AlphaShapePointNaviRef[i] : Angle  of segment i of current NAVI path [-180.f ... 180.f] rad
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                     af_LengthShapePointNaviRef[i] Length of segment i of current NAVI path [0.f ... 400.f] m
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                     af_CurvatureShapePointNaviRef[i] : Curvature of segment i of current NAVI path [-1.f ... 1.f]
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                     au_ProbTakeBranchShapePointNaviRef[i] : Probability of segment i that EGO takes branch of current NAVI path [0u ... 100u] %
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIPAddNaviShapePoint(const t_NaviInputData * pNaviInputData, FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef)
{
  uint8 i, ui_IdxOriginSP;
  uint8 u_ProbTakeBranchShapePointNaviRef = 0u;
  float32 f_AngleAccu = 0.f;
  float32 f_NewSPX = 0.f;
  float32 f_NewSPY = 0.f;
  float32 f_OriginX = 0.f;
  float32 f_OriginY = 0.f;
  float32 f_AngleSeg = 0.f;
  float32 f_LengthSeg = 0.f;
  float32 f_Curvature = 0.f;

  if(pNaviInputData->u_NumUsedSegments > 0u)
  {
    /* Angle of the new segment */
    f_AngleSeg = DEG2RAD(pNaviInputData->Segments[pNaviInputData->u_NumUsedSegments - 1u].f_AnglePrevSeg);
    /* Length of the new segment */
    f_LengthSeg = pNaviInputData->Segments[pNaviInputData->u_NumUsedSegments - 1u].f_Length;
    /* Curvature of the new segment */
    f_Curvature = pNaviInputData->Segments[pNaviInputData->u_NumUsedSegments - 1u].f_Curvature;
    /* Probability that EGO takes branch */
    u_ProbTakeBranchShapePointNaviRef = pNaviInputData->Segments[pNaviInputData->u_NumUsedSegments - 1u].u_ProbEgoTakesBranch;
  }

  /* Origin for the new shape point is the last shape point */
  if ( (pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer > 0u) && ((pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer - 1u) < FIP_NUM_NAVI_REF_SEGMENTS) )
  {
    ui_IdxOriginSP = pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer - 1u;      /* ui_IndexLastSPInBuffer points to the SP that will be added here */
  }
  else
  {
    ui_IdxOriginSP = 0u;
  }
  f_OriginX = pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[ui_IdxOriginSP];
  f_OriginY = pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[ui_IdxOriginSP];

  /* Compute cumulative angle from origin in NAVI reference to last shape point */
  for(i = 0; i < ui_IdxOriginSP; i++)
  {
    f_AngleAccu += pFIPShapePointsInNaviRef->af_AlphaShapePointNaviRef[i];
  }

  /*! Get position of next shape point */
  FIP_v_CalcPositionShapePoint(&(f_NewSPX), &(f_NewSPY), f_LengthSeg, f_AngleSeg, f_OriginX, f_OriginY, f_AngleAccu);

  /* Update FIPSHapePointsInNaviRef data structure with new segment info and shape point */
  pFIPShapePointsInNaviRef->af_AlphaShapePointNaviRef[ui_IdxOriginSP] = f_AngleSeg;
  pFIPShapePointsInNaviRef->af_LengthShapePointNaviRef[ui_IdxOriginSP] = f_LengthSeg;
  pFIPShapePointsInNaviRef->af_CurvatureShapePointNaviRef[ui_IdxOriginSP] = f_Curvature;
  pFIPShapePointsInNaviRef->au_ProbTakeBranchShapePointNaviRef[ui_IdxOriginSP] = u_ProbTakeBranchShapePointNaviRef;

  pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer] = f_NewSPX;
  pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer] = f_NewSPY;
}
#endif

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_b_ComputeEgoPathDifference                                                                   */ /*!

  @brief           This function computes the difference in EGO path to the adjacent Shape point in NAVI reference coordinates

  @description     This function computes the difference in EGO path to the adjacent Shape point in NAVI reference coordinates

  @startuml 
  Partition FIP_b_ComputeEgoPathDifference
  Start
  	Note right: This function computes the difference in EGO path to the adjacent Shape point in NAVI reference coordinates
	  - Inverse transformation of the current position
  	- Compute the difference with reference to EGO
	  - Update the shape point history difference buffer
  	If (Buffer is full) then (True)
  		- Delete oldest data, move everything one \n step down and fill the buffer
  	Else (False)
  		- Update the buffer
  	Endif
  	
	  - Calculate running average of difference of all segments
  End
  @enduml

  @return          -

  @param[in,out]   *pFIPShapePointsInNaviRef : Reference to data structure holding NAVI segment information and all the shape points in both NAVI reference and EGO reference coordinates
                      ui_IndexCurrentSegEgo : Index indicating the position of the EGO in terms of segment [0u ... FIP_NUM_NAVI_REF_SEGMENTS]
                      af_XPosShapePointNaviRef[i] : Y-position of point i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      with in in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                      af_YPosShapePointNaviRef[i] : Y-position of point i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      with in in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                      ui_IndexDiffPosHistorySPNaviRef : Index indicating the last filled position in difference between history SP and EGO array (af_DiffXPosHistorySPNaviRef, af_DiffYPosHistorySPNaviRef) [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                      af_DiffXPosHistorySPNaviRef[i] : X-position difference between EGO position and history shape points in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      with i in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                      af_DiffYPosHistorySPNaviRef[i] : Y-position difference between EGO position and history shape points in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      with i in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                      f_AvgEGOPathDiff : average difference between navi and ego lane [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       *pFIPNavi_CON2COG : Reference to transformation matrix between NAVI reference coordinates and EGO reference coordinates
                      f00 : the elements of the matrix [-1.f ... 1.f]
                      f10 : the elements of the matrix [-1.f ... 1.f]
                      f02 : the elements of the matrix [-1.f ... 1.f]
                      f12 : the elements of the matrix [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_b_ComputeEgoPathDifference(FIPNaviReferenceShapePoint_t *pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t *pFIPNavi_CON2COG)
{
  float32 f_XDiff, f_YDiff, f_RunningAvg, f_XPos, f_YPos;
  uint8 i;                    /* Generic index variable */
  uint8 ui_IdxCurrentSPInNaviRef = pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo + 1u;  /* Segment reference is one less that  SP reference */
  
  /* Inverse transformation of the current position - dx = CON2COG.02, dy = CON2COG.12 */
  f_XPos = ((-pFIPNavi_CON2COG->f10)*pFIPNavi_CON2COG->f12) - (pFIPNavi_CON2COG->f02*pFIPNavi_CON2COG->f00);
  f_YPos = ((-pFIPNavi_CON2COG->f00)*pFIPNavi_CON2COG->f12) - (pFIPNavi_CON2COG->f02*(-pFIPNavi_CON2COG->f10));


  /* Compute the difference with reference to EGO */
  if(ui_IdxCurrentSPInNaviRef < FIP_NUM_NAVI_REF_SHAPE_POINTS)
  {
    f_XDiff = f_XPos-pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[ui_IdxCurrentSPInNaviRef];
    f_YDiff = f_YPos-pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[ui_IdxCurrentSPInNaviRef];
  }
  else
  {
    f_XDiff = 0.f;
    f_YDiff = 0.f;
  }

  /* Update the shape point history difference buffer */
  if (pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef < FIP_NUM_HIST_SHAPE_POINTS)
  {
    /* Buffer is not yet full */
    /* Update the buffer */
    pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef] = f_XDiff;
    pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef] = f_YDiff;

    pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef += 1u;   /* Increment the index for the buffer */
  } 
  else
  {
    /* Buffer is full. Delete oldest data, move everything one step down and fill the buffer */
    for (i = 0; i < (FIP_NUM_HIST_SHAPE_POINTS - 1u); i++)
    {
      pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[i] = pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[i + 1u];
      pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[i] = pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[i + 1u];
    }
    pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[(FIP_NUM_HIST_SHAPE_POINTS - 1u)] = f_XDiff;
    pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[(FIP_NUM_HIST_SHAPE_POINTS - 1u)] = f_YDiff;
  } /* Check if SP history buffer difference buffer is full */

  f_RunningAvg = 0.f;
  for (i = 0; i < FIP_NUM_HIST_SHAPE_POINTS; i++)
  {
    f_XDiff = pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[i];
    f_YDiff = pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[i];

    if((SQR(f_XDiff) + SQR(f_YDiff)) >= 0.f)
    {
      f_RunningAvg += SQRT_(SQR(f_XDiff) + SQR(f_YDiff));
    }
    
  }

  if(pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef > 0u) /* Remark: ui_IndexDiffPosHistorySPNaviRef is uint8 */
  {
    pFIPShapePointsInNaviRef->f_AvgEGOPathDiff = f_RunningAvg / pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef;
  }
  else
  {
    pFIPShapePointsInNaviRef->f_AvgEGOPathDiff = f_RunningAvg;
  }
}
#endif

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_UpdateHistorySP                                                                            */ /*!

  @brief           This function updates the difference between history shape points and EGO after transformation/ shift 
                   of origin

  @description     This function updates the difference between history shape points and EGO after transformation/ shift 
                   of origin
                   The shape points under consideration are SP4, SP5, SP6 (SP3 - new origin) before transformation/ shift 
                   of origin or SP1, SP2, SP3 (SP0 - new origin) after transformation/ shift origin
  
  @startuml 
  Partition FIP_v_UpdateHistorySP
  Start
	  Note right: This function computes the difference in EGO path to the adjacent Shape point in NAVI reference coordinates
	  - Get the EGO position in NAVI reference coordinates
  	- Rotate through the angle accumulated from the base of the NAVI tree up to this point
  	- Shift the origin to EGO coordinate system
	  - Compute difference after transformation
  	- Store the difference 
  	- Compute running average
  	- LOOP over all relevant history shape points before transformation
  End
  @enduml

  @return          -

  @param[in]       p_af_XHistSPBT[i] : Reference to X positions of current history shape points before transformation / 
                                      shifting of origin
                                      NOTE: reference to array!!!
                   with i in [0...FIP_NUM_HIST_SHAPE_POINTS[
  @param[in]       p_af_YHistSPBT[i] : Reference to Y positions of current history shape points before transformation / 
                                      shifting of origin
                                      NOTE - reference to array!!!
                   with i in [0...FIP_NUM_HIST_SHAPE_POINTS[
  @param[in,out]   *pFIPShapePointsInNaviRef : Reference to data structure holding NAVI segment information and all the 
                                               shape points in both NAVI reference and EGO reference coordinates
                     af_DiffXPosHistorySPNaviRef[i] : X-position difference between EGO position and history shape points in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                     with i in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                     af_DiffYPosHistorySPNaviRef[i] : Y-position difference between EGO position and history shape points in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     with i in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                     af_XPosShapePointNaviRef[i] : X-position of point i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                     af_YPosShapePointNaviRef[i] : Y-position of point i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                     ui_IndexDiffPosHistorySPNaviRef : Index indicating the last filled position in difference between history SP and EGO array (af_DiffXPosHistorySPNaviRef, af_DiffYPosHistorySPNaviRef) [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                     f_AvgEGOPathDiff : average difference between navi and ego lane [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pFIPNaviCON2COG : Transformation matrix corresponding to SP3 before shifting of origin
                     f00 : the elements of the matrix [-1.f ... 1.f]
                     f10 : the elements of the matrix [-1.f ... 1.f]
                     f02 : the elements of the matrix [-1.f ... 1.f]
                     f12 : the elements of the matrix [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @created         -
  @changed         01.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_UpdateHistorySP(const float32 p_af_XHistSPBT[], const float32 p_af_YHistSPBT[], FIPNaviReferenceShapePoint_t *pFIPShapePointsInNaviRef, const GDBTrafoMatrix2D_t* pFIPNaviCON2COG)
{
  uint8 i, j;  /* Generic index variables */
  float32 f_XDiffNew, f_YDiffNew;   /* Differences in history SPs (X,Y) after transformation/shifting of origin */
  float32 f_RunningAvgNew = 0.f;

  /* EGO position points in OLD NAVI coordinates                  - f_SPInNaviOrig_
     Intermediate shape points during transformation              - f_PosRot_
     Shape points in NEW EGO coordinates                          - f_SPInEgoOrig_
  */
  float32 f_EGOPosInNaviOrig_X, f_EGOPosInNaviOrig_Y, f_PosRot_X, f_PosRot_Y, f_EGOPosInEgoOrig_X, f_EGOPosInEgoOrig_Y;


  /*
                          Before transformation                           After transformation
  SP                      (xo, yo)                                        (xn, yn)
  Difference in positions (xd1, yd1)                                      (xd2, yd2)
  EGO corresponding to SP (xe1, ye1) = (xo+xd1, yo+yd1)                   (xe2, ye2) - use logic from FIPGetEgoRefShapePoints()
  */
  
  for (j = 0u; j < FIP_NUM_HIST_SHAPE_POINTS; j++)
  {
    /* Start computing SP1, since SP0 is origin */
    i = j + 1u;

    /* Get the EGO position in NAVI reference coordinates - (xe1, ye1) = (xo+xd1, yo+yd1) */
    f_EGOPosInNaviOrig_X = p_af_XHistSPBT[j] + pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[j];
    f_EGOPosInNaviOrig_Y = p_af_YHistSPBT[j] + pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[j];

    /* Rotate through the angle accumulated from the base of the NAVI tree up to this point */
    f_PosRot_X = (pFIPNaviCON2COG->f00 * f_EGOPosInNaviOrig_X) - (pFIPNaviCON2COG->f10 * f_EGOPosInNaviOrig_Y);
    f_PosRot_Y = (pFIPNaviCON2COG->f10 * f_EGOPosInNaviOrig_X) + (pFIPNaviCON2COG->f00 * f_EGOPosInNaviOrig_Y);

    /* Shift the origin to EGO coordinate system */
    f_EGOPosInEgoOrig_X = f_PosRot_X + pFIPNaviCON2COG->f02;
    f_EGOPosInEgoOrig_Y = f_PosRot_Y + pFIPNaviCON2COG->f12;

    /* Compute difference after transformation */
    f_XDiffNew = f_EGOPosInEgoOrig_X - pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[i];
    f_YDiffNew = f_EGOPosInEgoOrig_Y - pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[i];

    /* Store the difference */
    pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[j] = f_XDiffNew;
    pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[j] = f_YDiffNew;

    /* Compute running average */
    if((SQR(f_XDiffNew) + SQR(f_YDiffNew)) >= 0.f)
    {
      f_RunningAvgNew += SQRT_(SQR(f_XDiffNew) + SQR(f_YDiffNew));
    }

  } /* LOOP over all relevant history shape points before transformation */

  if(pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef > 0u)
  {
    pFIPShapePointsInNaviRef->f_AvgEGOPathDiff = f_RunningAvgNew / pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef;
  }
  else
  {
    pFIPShapePointsInNaviRef->f_AvgEGOPathDiff = f_RunningAvgNew;
  }
  
}
#endif

/*************************************************************************************************************************
  Functionname:    FIPNaviSetDistNextExit                                                                           */ /*!

  @brief           Set the distance to the next exist left/right

  @description     Set the distance to the next exist left/right based on NAVI information such as street type of branch, 
                   branches angle to previous segment, segments angle to previous segment
  
  @startuml 
  Partition FIPNaviSetDistNextExit
  Start
  	Note right: This function sets the distance to the next exist left/right
	  If (Next left exit is false \n AND \n street type of branch is \n not Signal Unfilled \n AND \n Angel with previous branch is over zero \n OR \n Angel with previous segment is over \n Segment angle threshold) then (True)
  		- Next left exit distance is segment start distance
  		- Next left exit is true
  	Else (False)
  	Endif
  	
	  If(Next right exit is false \n AND \n street type of branch is \n not Signal Unfilled \n AND \n Angel with previous branch is over zero \n OR \n Angel with previous segment is over \n Segment angle threshold) then (True)
  		- Next right exit distance is segment start distance
  		- Next right exit is true
  	Else (False)
  	Endif
  	- Loop from Valid Index Start to Valid Index End
  End
  @enduml

  @return          -

  @param[in]       f_LengthSeg0Adapted : Adapted length of the first segment  [0.f ... 400.f] m
  @param[in]       ui_ValidIndexStart : Index of the first relevant segment   [full range of uint8]
  @param[in]       ui_ValidIndexEnd : Index of the last relevant segment      [full range of uint8]
  @param[in]       p_NaviData : Reference to incoming NAVI data
                      Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        TypStreetBranch : type of the street branch [t_NavStreetType as in Rte_SWCFctSenAdapt_Type]
                        f_AnglePrevBranch : branches angle to previous segment [-180.f ... 180.f] rad
                        f_AnglePrevSeg : segments angle to previous segment [-180.f ... 180.f] rad
  @param[out]      *pFIPNaviDataEvaluated : Reference to evaluated NAVI data
                      f_DistNextLeftExit : Distance to the next exit on the left side [0.f ... FCT_NAV_NUM_SEG*400.f] m
                      f_DistNextRightExit : Distance to the next exit on the right side[0.f ... FCT_NAV_NUM_SEG*400.f] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIPNaviSetDistNextExit(const float32 f_LengthSeg0Adapted, const uint8 ui_ValidIndexStart, const uint8 ui_ValidIndexEnd, t_NaviInputData const * p_NaviData, 
                            FIP_ND_Output_t *pFIP_ND_Output)
{
  uint8 i;

  boolean b_NextLeftExit, b_NextRightExit;
  float32 f_DistSegStart = 0.f;

  /*! Set default value */
  pFIP_ND_Output->f_DistNextLeftExit = (float32)FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pFIP_ND_Output->f_DistNextRightExit = (float32)FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  b_NextLeftExit = FALSE;
  b_NextRightExit = FALSE;

  for (i = ui_ValidIndexStart; (i < ui_ValidIndexEnd) && ( (b_NextLeftExit == FALSE) || (b_NextRightExit == FALSE) ); i++)
  {
    /*! Determine the distance to the next exit (an exit exists, 
        if the angle to the branch exceeds zeros or if the MPP is on the branch) */
    if( (b_NextLeftExit == FALSE) && 
        (p_NaviData->Segments[i].TypStreetBranch != NAV_STT_SIGNAL_UNFILLED) && 
        ( (p_NaviData->Segments[i].f_AnglePrevBranch > C_F32_DELTA) || 
          (p_NaviData->Segments[i].f_AnglePrevSeg > FIP_NAVI_SEG_ANGLE_THRES_EXIT) 
        )
      )
    {
      pFIP_ND_Output->f_DistNextLeftExit = f_DistSegStart;
      b_NextLeftExit = TRUE;
    }
    
    if( (b_NextRightExit == FALSE) && 
        (p_NaviData->Segments[i].TypStreetBranch != NAV_STT_SIGNAL_UNFILLED) && 
        ( (p_NaviData->Segments[i].f_AnglePrevBranch < - C_F32_DELTA) || 
          (p_NaviData->Segments[i].f_AnglePrevSeg < -FIP_NAVI_SEG_ANGLE_THRES_EXIT) 
        )
      )
    {
      pFIP_ND_Output->f_DistNextRightExit = f_DistSegStart;
      b_NextRightExit = TRUE;
    }
    
    if (i == ui_ValidIndexStart)
    {
      f_DistSegStart = f_LengthSeg0Adapted;
    } 
    else
    {
      f_DistSegStart += p_NaviData->Segments[i].f_Length;
    }
  } /* Loop from ui_ValidIndexStart to ui_ValidIndexEnd */
}

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_NaviUpdateEgoMotion                                                                        */ /*!

  @brief           Update ego motion matrix

  @description     Update ego motion matrix: Compute the new XY vectors from translation and shift computed in the 
                   predetermined coordinate system
  
  @startuml 
  Partition FIP_v_NaviUpdateEgoMotion
  Start
	  Note right: This function updates ego motion matrix
	  - Shift the translation vectors to predetermined origin
  	- Return the newly computed xy vectors
  End
  @enduml

  @return          -

  @param[in]       f_CosAngle : Cosine of the accumulated angle         [-1.f ... 1.f]
  @param[in]       f_SinAngle : Sine of the accumulated angle           [-1.f ... 1.f]
  @param[in]       f_abs_dx : delta distance traveled in X-direction    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       f_abs_dy : delta distance traveled in Y-direction    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pFIPNaviEgoCummul : Reference to structure containing cumulative EGO motion information
                    f_rel_dx : X-position of the EGO with reference to a given origin [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    f_rel_dy . Y-position of the EGO with reference to a given origin[-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             Delta motion has to completed and fed to this function (check FIPNaviUpdateCON2COG)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_NaviUpdateEgoMotion(const float32 f_CosAngle, const float32 f_SinAngle, const float32 f_abs_dx, const float32 f_abs_dy, FIPNaviCummulativeEgoMotion_t * pFIPNaviEgoCummul)
{
  float32 f_abs2rel_dx, f_abs2rel_dy;

  /* Shift the translation vectors to predetermined origin */
  f_abs2rel_dx = (( f_CosAngle * pFIPNaviEgoCummul->f_rel_dx) + (f_SinAngle * pFIPNaviEgoCummul->f_rel_dy) + f_abs_dx);
  f_abs2rel_dy = ((-f_SinAngle * pFIPNaviEgoCummul->f_rel_dx) + (f_CosAngle * pFIPNaviEgoCummul->f_rel_dy) + f_abs_dy);

  /* Return the newly computed xy vectors */
  pFIPNaviEgoCummul->f_rel_dx = f_abs2rel_dx;
  pFIPNaviEgoCummul->f_rel_dy = f_abs2rel_dy;

}
#endif

#if( FIP_EVAL_SHAPE_POINTS )
/*************************************************************************************************************************
  Functionname:    FIP_b_SetTreeValidShapePointsInNaviRef                                                           */ /*!

  @brief           Determine if the FIPNaviReferenceShapePoint_t contains valid data

  @description     Determine if the FIPNaviReferenceShapePoint_t contains valid data (i.e. no initial data values)

  @startuml 
  Partition FIP_b_SetTreeValidShapePointsInNaviRef
  Start
  	Note right: This function determines if the FIP Navigation \n Reference Shape Point contains valid data

  	If(Currrent ego segment index is zero \n OR \n last shape point index in buffer is zero \n AND \n tree is not extendable \n AND \n x and y coordinates of first shape point is not valid) then (True)
  		- Tree is not valid
  		- Initialise global navi data
  	Else (False)
  		- Tree is valid
  	Endif
  End
  @enduml

  @return          b_TreeValid: information if FIPNaviReferenceShapePoint_t contains valid data [TRUE, FALSE]

  @param[in]       p_ShapePointsInNaviRef : Reference to data structure containing shape points in NAVI reference coordinate system
                      ui_IndexCurrentSegEgo : Index indicating the position of the EGO in terms of segment [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                      ui_IndexLastSPInBuffer : Index indicating the last filled position in shape point array [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                      b_TreeExtendable : Info if the tree can be extended by adding shape points [TRUE, FALSE]
                      af_XPosShapePointNaviRef[i] : X-position of segment i in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      with i [0...FIP_NUM_NAVI_REF_SEGMENTS[
                      af_YPosShapePointNaviRef[i] : Y-position of segment i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      with i [0...FIP_NUM_NAVI_REF_SEGMENTS[

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
boolean FIP_b_SetTreeValidShapePointsInNaviRef(const FIPNaviReferenceShapePoint_t * p_ShapePointsInNaviRef)
{
  boolean b_TreeValid = TRUE;

  if( (p_ShapePointsInNaviRef->ui_IndexCurrentSegEgo == 0u) && 
      (p_ShapePointsInNaviRef->ui_IndexLastSPInBuffer == 0u) &&
      (p_ShapePointsInNaviRef->b_TreeExtendable == FALSE) && 
      (fABS(p_ShapePointsInNaviRef->af_XPosShapePointNaviRef[0u]) < C_F32_DELTA) &&
      (fABS(p_ShapePointsInNaviRef->af_YPosShapePointNaviRef[0u]) < C_F32_DELTA)
    )
  {
    b_TreeValid = FALSE;
    FIP_v_ND_InitPersistentData();
  }

  return b_TreeValid;
}
#endif

/*************************************************************************************************************************
  Functionname:    FIP_f_CalcDyOffsetCurvatureNavi                                                                  */ /*!

  @brief           calculates maximal dy-offset between course of constant navi curvature at ego position and course from 
                   navi data for a given reference point

  @description     calculates maximal dy-offset between course of constant navi curvature at ego position and course from 
                   navi data for a reference point in maximum distance either from given time gap or from given minimal 
                   distance
                   hint: if minimal distance is 0, only time gap is considered
                   hint: if navi tree is not built up to given time gap / distance -> dy is set to zero (ARS410VW26 UE_1104)
                   hint: in situations of u-curves it could be necessary to use the maximal deviation value (ARS410VW26 UE_1103 [I])
                         -> always maximal value used
                   hint: determine approximation type for given navi segment to be independent from navi input structure 
                         (e.g. curvature change) and interpretation of navi input structure (e.g. segment angle based on curve)
  
  @startuml 
  Partition FIP_f_CalcDyOffsetCurvatureNavi
  Start
	  Note right: This function calculates maximal dy-offset \n between course of constant navigation curvature \n at ego position and course from navigation data \n for a given reference point

	  If(Min distance for reference point is over zero) then (True)
  		- Take maximum between min distance for \n reference point and distance calculated from  \n ego speed and time gap
  	Else (False)
  		- Take distance calculated from ego speed and time gap
  	Endif
  	
  	- Check the CurvatureType of the Navi Segment
  	- Update accumulated angle of previous segments
  	- Determine sin and cos of accumulated angles 
  	- Determine the points of the Navi course in a not rotated coordinate system relative to end point of previous segment

  	If(Actual segment length is less than remaining distance) then (True)
  		- Determine the x- and y-position at the end of the segment considered
  		- Calculate corresponding point in virtual trajectory with constatnt curvature from actual position
  		- Update accumulated angle of previous segments
  	Else (False)
  		- Calculate corresponding point on navi path 
  		- Calculate corresponding point in virtual trajectory with constatnt curvature from actual position
  	Endif
	
  	- Store maximum y-deviation between Navi-course and course of ego-curvature
	  - Actual navigation path is not built up to given time gap/distance then set dy-offset to zero
  End
  @enduml

  @return          f_dyDiffMax : maximal (signed) delta in y-direction within considered range [full range float32] m

  @param[in]       f_TimeGap : time gap for calculation of reference point [full range float32] s
  @param[in]       f_minDistance : minimal distance for reference point [full range float32] m

  @glob_in         -
  @glob_out        -
  
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         08.10.2015
  @changed         20.06.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
float32 FIP_f_CalcDyOffsetCurvatureNavi(float32 f_TimeGap, float32 f_minDistance)
{
  uint8 ui8_seg_indx = 0u;
  float32 f_remainingDistance, f_TimeGapDistance, f_actualSegLength;
  boolean b_segmentFound = FALSE;
  float32 f_dxNaviCourse, f_dyNaviCourse, f_dxCourseEgoPos, f_dyCourseEgoPos, f_dyDiffMax;
  float32 f_AngleAccumPrevSegmentsNavi, f_AngleAccumPrevSegmentsEgoPos, f_Abs_AngleAccumPrevSegmentsNavi, f_Abs_AngleAccumPrevSegEgoPos;
  float32 f_SinAngleAccuNavi, f_CosAngleAccuNavi, f_SinAngleAccuEgoPos, f_CosAngleAccuEgoPos;
  float32 f_lengthEgoCurve = 0.f;
  float32 f_dyDiffEgoPosNaviCourse, f_Abs_dyDiffMax;

  FIPNaviPathCurvatureType_t t_NaviPathCurvatureType;

  /* initialization of variables */
  f_dxNaviCourse = 0.f;
  f_dyNaviCourse = 0.f;
  f_dxCourseEgoPos = 0.f;
  f_dyCourseEgoPos = 0.f;
  f_AngleAccumPrevSegmentsNavi = 0.f;
  f_AngleAccumPrevSegmentsEgoPos = 0.f;
  f_dyDiffMax = 0.f;
  f_actualSegLength = 0.f;
  ui8_seg_indx = 0u;

  /* if f_minDistance is 0, do not consider minimal distance */
  if (f_minDistance > C_F32_DELTA)
  {
    f_TimeGapDistance = MAX_FLOAT(f_minDistance, (*pt_FIP_RTE_Input->pf_EgoVelObjSync * f_TimeGap));
  }
  else
  {
    f_TimeGapDistance = *pt_FIP_RTE_Input->pf_EgoVelObjSync * f_TimeGap;
  }

  f_remainingDistance = f_TimeGapDistance;
  
  while ((ui8_seg_indx < pSLATE_NaviData->u_NumUsedSegments) && (b_segmentFound == FALSE))
  {
    /* CHeck the CurvatureType of the Navi Segment */
    t_NaviPathCurvatureType = FIP_t_GetNaviPathCurvatureType(&pSLATE_NaviData->Segments[ui8_seg_indx]);

    /* update accumulated angle of previous segments */

    f_AngleAccumPrevSegmentsNavi += DEG2RAD(pSLATE_NaviData->Segments[ui8_seg_indx].f_AnglePrevSeg);

    /* determine sin and cos of accumulated angles */
    f_Abs_AngleAccumPrevSegmentsNavi = fABS(f_AngleAccumPrevSegmentsNavi);
    if (f_Abs_AngleAccumPrevSegmentsNavi < C_F32_DELTA)
    {
      f_SinAngleAccuNavi = 0.f;
      f_CosAngleAccuNavi = 1.f;
    }
    else
    {
      f_SinAngleAccuNavi = SIN_HD_(f_AngleAccumPrevSegmentsNavi);
      f_CosAngleAccuNavi = COS_HD_(f_AngleAccumPrevSegmentsNavi);
    }

    f_Abs_AngleAccumPrevSegEgoPos = fABS(f_AngleAccumPrevSegmentsEgoPos);
    if (f_Abs_AngleAccumPrevSegEgoPos < C_F32_DELTA)
    {
      f_SinAngleAccuEgoPos = 0.f;
      f_CosAngleAccuEgoPos = 1.f;
    }
    else
    {
      f_SinAngleAccuEgoPos = SIN_HD_(f_AngleAccumPrevSegmentsEgoPos);
      f_CosAngleAccuEgoPos = COS_HD_(f_AngleAccumPrevSegmentsEgoPos);
    }

    /* First: determine the points of the Navi course in a not rotated coordinate system relative to end point of previous segment */
    f_actualSegLength = pSLATE_NaviData->Segments[ui8_seg_indx].f_Length;

    if (f_actualSegLength < f_remainingDistance)
    {
      /* end of search not in actual segment */

      /* determine the x- and y-position at the end of the segment considered */
      FIPSamplePosAbsNaviPathArcRel(&f_dxNaviCourse, &f_dyNaviCourse, pSLATE_NaviData->Segments[ui8_seg_indx].f_Length, &pSLATE_NaviData->Segments[ui8_seg_indx], 
        f_CosAngleAccuNavi, f_SinAngleAccuNavi, f_dxNaviCourse, f_dyNaviCourse, t_NaviPathCurvatureType);


      f_lengthEgoCurve += f_actualSegLength;
      /* calculate corresponding point in virtual trajectory with constatnt curvature from actual position */
      FIPSamplePosAbsNaviPathArcRel(&f_dxCourseEgoPos, &f_dyCourseEgoPos, f_lengthEgoCurve, &pSLATE_NaviData->Segments[0u], 
        f_CosAngleAccuEgoPos, f_SinAngleAccuEgoPos, 0.f, 0.f, NAVI_PATH_CURVY);

      /* update accumulated angle of previous segments */
      f_AngleAccumPrevSegmentsNavi +=  FIP_f_CalcSegAngleBasedOnCurve(pSLATE_NaviData->Segments[ui8_seg_indx].f_Length, &pSLATE_NaviData->Segments[ui8_seg_indx], t_NaviPathCurvatureType);
      
      f_remainingDistance -= pSLATE_NaviData->Segments[ui8_seg_indx].f_Length;

    }
    else /* f_actualSegLength >= f_remainingDistance */
    {
      /* end of search reached */
      b_segmentFound = TRUE;

      /* calculate corresponding point on navi path */
      FIPSamplePosAbsNaviPathArcRel(&f_dxNaviCourse, &f_dyNaviCourse, f_remainingDistance, &pSLATE_NaviData->Segments[ui8_seg_indx], f_CosAngleAccuNavi, 
        f_SinAngleAccuNavi, f_dxNaviCourse, f_dyNaviCourse, t_NaviPathCurvatureType);

      
      /* calculate corresponding point in virtual trajectory with constatnt curvature from actual position */
      FIPSamplePosAbsNaviPathArcRel(&f_dxCourseEgoPos, &f_dyCourseEgoPos, f_TimeGapDistance, &pSLATE_NaviData->Segments[0u], f_CosAngleAccuEgoPos, 
        f_SinAngleAccuEgoPos, 0.0f, 0.0f, NAVI_PATH_CURVY);
  

    }


    /* store maximum y-deviation between Navi-course and course of ego-curvature */
    f_dyDiffEgoPosNaviCourse = fABS(f_dyCourseEgoPos - f_dyNaviCourse);
    f_Abs_dyDiffMax = fABS(f_dyDiffMax);
    if(f_dyDiffEgoPosNaviCourse > f_Abs_dyDiffMax)
    {
      f_dyDiffMax = f_dyCourseEgoPos - f_dyNaviCourse;
    }

    ui8_seg_indx++;
  }

  /* actual navi path is not built up to given time gap / distance -> set dy to zero (UE_1104)*/
  if (b_segmentFound == FALSE)
  {
    f_dyDiffMax = 0.0f;
  }

  return f_dyDiffMax; 
}

#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  /*************************************************************************************************************************
  Functionname:    FIP_v_SetDistToHighCurvatureChangeNavi                                                                  */ /*!

  @brief           Calculates closest x-distance where dy-offset between course of constant navi curvature (at ego position) 
                   and course from navi data exceeds a given threshold

  @description     Calculates closest x-distance, where dy-offset between course of constant navi curvature (at ego position) 
                   and course from navi data pass a given threshold.
                   hint: if navi tree is not built up to given distance -> f_DistToHighCurvatureChange is set to maximum
                   hint: determine approximation type for given navi segment to be independent from navi input structure 
                         (e.g. curvature change) and interpretation of navi input structure (e.g. segment angle based on curve)
  
  @startuml 
  Partition FIP_v_SetDistToHighCurvatureChangeNavi
  Start
	  Note right: This function calculates closest x-distance \n where dy-offset between course of constant \n navigation curvature (at ego position) and \n course from navigation data exceeds a given threshold
	
	  - Get the curvature and calculate radius and its square
	  - Check the CurvatureType of the Navi Segment
  	- Update accumulated angle of previous segments
  	- Determine sin and cos of accumulated angles 
  	- Set current length in segment when end of previous segment has been reached

	  - Step through current segment till x-distance with high curvature change has been found
	  If (End of search is in current segment) then (True)
	  	- Limit length on segment
	  Else (False)
	  Endif

	  - Determine the x- and y-position at a given distance from the start point of the current segment
  	- Calculate y-distance of the virtual trajectory with constant curvature for x-position given by the navi trajectory

	  If (Curvature higher than zero)
		  - Compute square of x-distance at which y-distance of circle is to be computed
		  - Computation of y-distance of circle according to formula only possible when absolute value of x-distance is smaller than radius of circle
	  	- Y-distance of circle dependent on sign of radius
	  Else (False)
	  Endif

	  If (If y-deviation between navi-course and course of virtual navi trajectory (circle) exceeds threshold) then (True)
	  	- Take x-distance of current point on navi path as distance with a high curvature change
	  Else (False)
	  	-  Increment length on current navi segment
	  Endif

	  If (X distance found is False) then (True)
	  	- Determine the x- and y-position at the end of the segment considered
	  	- Update accumulated length of previous segments
	  	- Update accumulated angle of previous segments
	  	- Increment segment counter
	  Else (False)
  	Endif
  End
  @enduml

  @return          -

  @param[in]       t_FIP_ND_Output : reference to navi data output
                      t_FIP_ND_Output->f_DistToHighCurvatureChange [0.f ... FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX]

  @c_switch_part   FIP_EVAL_SHAPE_POINTS :  Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         18.01.2017
  @changed         18.01.2017

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
void FIP_v_SetDistToHighCurvatureChangeNavi(void)
{
  boolean b_DistXFound;                 /* stop flag for both while loops */
  uint8   ui8_SegIndx;                  /* index of current segment under consideration */
  float32 f_DistXNavi;                  /* x-coordinate (longitudinal) of position on navi course */
  float32 f_DistXSqrNavi;               /* square of x-coordinate of position on navi course */
  float32 f_DistXSegmentStartNavi;      /* x-coordinate (longitudinal) of segment start for current segment */
  float32 f_DistYNavi;                  /* y-coordinate (lateral) of position on navi course */
  float32 f_DistYSegmentStartNavi;      /* y-coordinate (longitudinal) of segment start for current segment */
  float32 f_SinAngleAccumNavi;          /* sine of accumulated angle of navi segments up to current segment */
  float32 f_CosAngleAccumNavi;          /* cosine of accumulated angle of navi segments up to current segment */
  float32 f_AngleAccumPrevSegmentsNavi; /* accumulated angle of navi segments up to current segment */
  float32 f_LengthOnSegmentNavi;        /* length on the the current navi segment */
  float32 f_AccumSegmentLengthNavi;     /* accumulated length of navi segments up to current segment */
  float32 f_DistYCircle;                /* y-coordinate (lateral) of position on circular course (either given by VDY course or first segment of navi course) */
  float32 f_RadiusCircle;               /* radius of circle (either given by VDY course or first segment of navi course) */
  float32 f_RadiusCircleSqr;            /* square of radius of circle (either given by VDY course or first segment of navi course) */
  float32 f_CurvatureCircle;            /* curvature of circle (either given by VDY course or first segment of navi course) */
  float32 f_Abs_CurvatureCircle, f_ABSCurvatureCircle, f_Abs_AngleAccumPrevSegNavi, f_Abs_DiffDistYCircleDistYNavi;
  FIPNaviPathCurvatureType_t t_NaviPathCurvatureType; /* curvature type of the navi segment*/

  /* Initialization of variables */
  b_DistXFound                  = FALSE;
  ui8_SegIndx                   = 0u;
  f_DistXNavi                   = 0.f;
  f_DistXSqrNavi                = 0.f;
  f_DistXSegmentStartNavi       = 0.f;
  f_DistYNavi                   = 0.f;
  f_DistYSegmentStartNavi       = 0.f;
  f_AngleAccumPrevSegmentsNavi  = 0.f;
  f_LengthOnSegmentNavi         = 0.f;
  f_AccumSegmentLengthNavi      = 0.f;
  f_DistYCircle                 = 0.f;
  f_RadiusCircle                = 0.f;
  f_RadiusCircleSqr             = 0.f;
  f_CurvatureCircle             = 0.f;

  /* Dependent on the available navi information use the curvature of the first segment or the VDY curvature */
#if (!FIP_EVAL_SHAPE_POINTS)
  f_CurvatureCircle = pSLATE_NaviData->Segments[0u].f_Curvature;
#else
  f_CurvatureCircle = EGO_CURVE_OBJ_SYNC;
#endif
  
  /* One-time computation of radius and its square of the virtual trajectory in case needed for accuracy */
  if (pSLATE_NaviData->u_NumUsedSegments > 0u)
  {
    f_Abs_CurvatureCircle = fABS(f_CurvatureCircle);
    if (f_Abs_CurvatureCircle > FIP_CURVATURE_USE_LINEAR_APPROX)
    {
      f_RadiusCircle    = (1.f/f_CurvatureCircle);
      f_RadiusCircleSqr = f_RadiusCircle * f_RadiusCircle;
    }
  }

  /* Loop over all segments while x-distance with high curvature change has not been found */
  while ((ui8_SegIndx < pSLATE_NaviData->u_NumUsedSegments) && (b_DistXFound == FALSE))
  {
    /* Check the curvature type of the navi segment */
    t_NaviPathCurvatureType = FIP_t_GetNaviPathCurvatureType(&pSLATE_NaviData->Segments[ui8_SegIndx]);

    /* Update accumulated angle of previous segments */
    f_AngleAccumPrevSegmentsNavi += DEG2RAD(pSLATE_NaviData->Segments[ui8_SegIndx].f_AnglePrevSeg);

    /* Determine sin and cos of accumulated angles */
    f_Abs_AngleAccumPrevSegNavi = fABS(f_AngleAccumPrevSegmentsNavi);
    if (f_Abs_AngleAccumPrevSegNavi < C_F32_DELTA)
    {
      f_SinAngleAccumNavi = 0.f;
      f_CosAngleAccumNavi = 1.f;
    }
    else
    {
      f_SinAngleAccumNavi = SIN_HD_(f_AngleAccumPrevSegmentsNavi);
      f_CosAngleAccumNavi = COS_HD_(f_AngleAccumPrevSegmentsNavi);
    }

    /* Set current length in segment when end of previous segment has been reached */
    if (ui8_SegIndx > 0u)
    {
      f_LengthOnSegmentNavi = f_LengthOnSegmentNavi - pSLATE_NaviData->Segments[ui8_SegIndx-1].f_Length;
    }

    /* Step through current segment while x-distance with high curvature change has not been found */
    while ( (f_LengthOnSegmentNavi < pSLATE_NaviData->Segments[ui8_SegIndx].f_Length) && (b_DistXFound == FALSE) )
    {
      /* Check if end of search is in current segment */
      if ((f_AccumSegmentLengthNavi + f_LengthOnSegmentNavi) >= FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX)
      {
        /* End of search reached at maximum distance on navi trajectory to be considered */
        b_DistXFound = TRUE;

        /* Limit length on segment. Do the final computation at distance FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX on navi trajectory. */
        f_LengthOnSegmentNavi = FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX - f_AccumSegmentLengthNavi;
      }

      /* Determine the x- and y-position at a given distance from the start point of the current segment */
      FIPSamplePosAbsNaviPathArcRel(&f_DistXNavi, &f_DistYNavi, f_LengthOnSegmentNavi, &pSLATE_NaviData->Segments[ui8_SegIndx], f_CosAngleAccumNavi, 
        f_SinAngleAccumNavi, f_DistXSegmentStartNavi, f_DistYSegmentStartNavi, t_NaviPathCurvatureType);

      /* Calculate y-distance of the virtual trajectory with constant curvature for x-position given by the navi trajectory */
      /* For very low curvature values of the circle (basically a straight trajectory) the y-distance is left unchanged at an initial value of zero */
      f_ABSCurvatureCircle = fABS(f_CurvatureCircle);
      if (f_ABSCurvatureCircle > FIP_CURVATURE_USE_LINEAR_APPROX)
      {
        /* Compute square of x-distance at which y-distance of circle is to be computed */
        f_DistXSqrNavi = SQR(f_DistXNavi);

        /* Computation of y-distance of circle according to formula only possible when absolute value of x-distance is smaller than radius of circle */
        if (f_DistXSqrNavi < f_RadiusCircleSqr)
        {
          /* Y-distance of circle dependent on sign of radius */
          if (f_RadiusCircle > 0.0f)
          {
            f_DistYCircle = f_RadiusCircle - SQRT(f_RadiusCircleSqr - f_DistXSqrNavi);
          }
          else
          {
            f_DistYCircle = f_RadiusCircle + SQRT(f_RadiusCircleSqr - f_DistXSqrNavi);
          }
        }
        else
        {
          /* End of search reached at maximum x-distance given by radius of circle radius */
          b_DistXFound = TRUE;

          /* Set y-distance of circle to radius */
          f_DistYCircle = f_RadiusCircle;
        }
      }

      /* Check if y-deviation between navi-course and course of virtual navi trajectory (circle) exceeds threshold */
      f_Abs_DiffDistYCircleDistYNavi = fABS(f_DistYCircle - f_DistYNavi);
      if(f_Abs_DiffDistYCircleDistYNavi > FIP_NAVI_CURVE_CHANGE_DELTA_Y_THRES)
      {
        /* End of search reached as x-distance found at which delta of y-distance passes threshold */
        b_DistXFound = TRUE;

        /* Take x-distance of current point on navi path as distance with a high curvature change */
        pt_FIP_ND_Output->f_DistToHighCC = f_DistXNavi;
      }
      else
      {
        /* Increment length on current navi segment */
        f_LengthOnSegmentNavi = f_LengthOnSegmentNavi + FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_STEP;
      }
    }

    if (b_DistXFound == FALSE)
    {
      /* Determine the x- and y-position at the end of the segment considered */
      FIPSamplePosAbsNaviPathArcRel(&f_DistXSegmentStartNavi, &f_DistYSegmentStartNavi, pSLATE_NaviData->Segments[ui8_SegIndx].f_Length, &pSLATE_NaviData->Segments[ui8_SegIndx], 
        f_CosAngleAccumNavi, f_SinAngleAccumNavi, f_DistXSegmentStartNavi, f_DistYSegmentStartNavi, t_NaviPathCurvatureType);

      /* Update accumulated length of previous segments */
      f_AccumSegmentLengthNavi += pSLATE_NaviData->Segments[ui8_SegIndx].f_Length;

      /* Update accumulated angle of previous segments */
      f_AngleAccumPrevSegmentsNavi +=  FIP_f_CalcSegAngleBasedOnCurve(pSLATE_NaviData->Segments[ui8_SegIndx].f_Length, &pSLATE_NaviData->Segments[ui8_SegIndx], t_NaviPathCurvatureType);

      /* Increment segment counter */
      ui8_SegIndx++;
    }
  }
}
#endif /* (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION) */

/*************************************************************************************************************************
  Functionname:    FIP_SetProbCurveDiffNaviNear                                                                      */ /*!

  @brief           Calculation of curviness probability value from offset between navi-curvature at ego position and 
                   navi-curvature for near timegap

  @description     Calculation of curviness probability value from offset between navi-curvature at ego position and 
                   navi-curvature for near timegap defined through FIP_TIME_CURVATURE_CHANGE_NEAR and FIP_DIST_CURVATURE_CHANGE_NEAR
                   (VW: i_wKurvAend2Sek_nav)
  
  @startuml 
  Partition FIP_SetProbCurveDiffNaviNear
  Start
  	Note right: This function Calculates curviness probability \n value from offset between navigation-curvature at \n ego position and navigation-curvature for near timegap
	  If(Navi data is valid) then (True)
  		- Calculate the maximum dy between navi path and the virtual constatnt curvature path
  		- Interpolation to value from 0 to 1
  	Else (False)
  		- Probability of curvature change near is zero
  	Endif
  
	  - Low pass filter the values
  	- Store Probability of curvature change near
  Stop
  @enduml

  @return          -

  @glob_in         -
  @glob_out        pt_FIP_ND_Output->f_CurvinessProbNear : Curviness probability value from offset between curvature at ego position and navi-curvature for timegap of 2s [0.f ... 1.f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             FIPNaviEgoTreeCumul.f_abs_dist has to be determined for use in FIP_f_CalcDyOffsetCurvatureNavi(FIPNaviUpdateCON2COG)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         08.10.2015
  @changed         20.06.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
void FIP_SetProbCurveDiffNaviNear(void)
{
  float32 f_ProbCurvatureChangeNear = 0.0f;
  float32 f_dyNear, f_CurvinessProbNearOld;
  boolean b_NaviDataValid= FALSE;
  

  b_NaviDataValid = pt_FIP_ND_Output->b_NaviPathIsValid;
  f_CurvinessProbNearOld = pt_FIP_ND_Output->f_CurvinessProbNear;
  
  /* ARS410VW26: UE_1107: i_wKurvAend2Sek_nav */
  if (b_NaviDataValid == FALSE)
  {
    f_ProbCurvatureChangeNear = 0.0f;
  }
  else
  {
    /* calculate the maximum dy between navi path and the virtual constatnt curvature path */
    f_dyNear = FIP_f_CalcDyOffsetCurvatureNavi(FIP_TIME_CURVATURE_CHANGE_NEAR, FIP_DIST_CURVATURE_CHANGE_NEAR);
    f_dyNear = fABS(f_dyNear);
    /* interpolation to value from 0 to 1 */
    f_ProbCurvatureChangeNear = GDBmathLinFuncLimBounded(f_dyNear, FIP_PROB_CURVATURE_CHANGE_NEAR_MIN, FIP_PROB_CURVATURE_CHANGE_NEAR_MAX, 0.0f, 1.0f); 
  }

  /* filtering */
  f_ProbCurvatureChangeNear = GDB_FILTER(f_ProbCurvatureChangeNear, f_CurvinessProbNearOld, FIP_CURVINESSPROB_FILTER);

  pt_FIP_ND_Output->f_CurvinessProbNear = f_ProbCurvatureChangeNear;
}


/*************************************************************************************************************************
  Functionname:    FIP_SetProbCurveDiffNaviFar                                                                      */ /*!

  @brief           Calculation of curviness probability value from offset between navi-curvature at ego position and 
                   navi-curvature for far timegap

  @description     Calculation of curviness probability value from offset between navi-curvature at ego position and 
                   navi-curvature for far timegap defined through FIP_TIME_CURVATURE_CHANGE_FAR and FIP_DIST_CURVATURE_CHANGE_FAR
  
  @startuml 
  Partition FIP_SetProbCurveDiffNaviFar
  Start
	  Note right: This function Calculates curviness probability \n value from offset between navigation-curvature at \n ego position and navigation-curvature for far timegap
	  If(Navi data is valid) then (True)
  		- Calculate the maximum dy between navi path and the virtual constatnt curvature path
  		- Interpolation to value from 0 to 1
  	Else (False)
  		- Probability of curvature change far is zero
  	Endif
  
	  - Low pass filter the values
  	- Store Probability of curvature change far
  Stop
  @enduml

  @return          -

  @glob_in         pSLATE_CustomInput : reference to global struct for customer specific input
                      ModulDegradation.b_Degradation_PSD : PSD degradation [TRUE, FALSE]
  @glob_out        pt_FIP_ND_Output->f_CurvinessProbFar : Curviness probability value from offset between curvature at ego position and navi-curvature for timegap of 4s [0.f ... 1.f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         08.10.2015
  @changed         20.06.2016

  @todo            f_ProbCurvatureChange4sec if (FIP_PROB_CURVATURE_CHANGE_4SEC_MAX - FIP_PROB_CURVATURE_CHANGE_4SEC_MIN) < C_F32_DELTA

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
void FIP_SetProbCurveDiffNaviFar(void)
{
  float32 f_ProbCurvatureChangeFar = 0.0f;
  float32 f_dyFar, f_CurvinessProbFarOld;
  boolean b_NaviDataValid= FALSE;

  b_NaviDataValid = pt_FIP_ND_Output->b_NaviPathIsValid;
  f_CurvinessProbFarOld = pt_FIP_ND_Output->f_CurvinessProbFar;

  /* f_ProbCurvatureChangeFar */
  /* UE_1108: i_wKurvAend4Sek_nav */
  if (b_NaviDataValid == FALSE)
  {
    f_ProbCurvatureChangeFar = 0.0f;
  }
  else
  {
    /* calculate the maximum dy between navi path and the virtual constatnt curvature path */
    f_dyFar = FIP_f_CalcDyOffsetCurvatureNavi(FIP_TIME_CURVATURE_CHANGE_FAR, FIP_DIST_CURVATURE_CHANGE_FAR);
    f_dyFar = fABS(f_dyFar);
    /* interpolation to value from 0 to 1 */
    f_ProbCurvatureChangeFar = GDBmathLinFuncLimBounded(f_dyFar, FIP_PROB_CURVATURE_CHANGE_FAR_MIN, FIP_PROB_CURVATURE_CHANGE_FAR_MAX, 0.0f, 1.0f); 
  }

  /* filtering */
  f_ProbCurvatureChangeFar = GDB_FILTER(f_ProbCurvatureChangeFar, f_CurvinessProbFarOld, FIP_CURVINESSPROB_FILTER);

  pt_FIP_ND_Output->f_CurvinessProbFar = f_ProbCurvatureChangeFar;
}


#endif /*!< FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE */
///@}
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED
