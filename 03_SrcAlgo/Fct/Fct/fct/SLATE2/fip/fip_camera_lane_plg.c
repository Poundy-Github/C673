/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_camera_lane_plg.c

DESCRIPTION:               ACC FCT Preprocessing of Camera Lane Data

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             04.12.2013

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

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
@defgroup fip_camera_lane_plg FIP Camera Lane
@ingroup fip
@brief          Main file for preprocessing camera lane data \n\n

@description    The following functionalities are provided by this module:
                - Preprocess inputs for FIP Camera Lane sub module.
                - Initialize non-persistent output data structures and variables in FIP Camera Lane sub-module.
				- Initialize persistent output data structures and variables in FIP Camera Lane sub-module.
				- Determine which lane marker should be considered for finding the curvature, visibility distance or heading angle.
				- Determine the curvature change of the camera lane.
				- Determine the curvature of the camera lane.
				- Determine the visibility range of the camera lane.
				- Determine the width of the ego lane based on the camera information.
				- Determine the heading angle of the camera lane.
				- Determine if the camera lane is a road edge.
				- Determine if the camera lane indicates a roadworks & if the camera lane object association is valid.
@{

*/

#if (SLATE_CFG_CAM_LANE_INTERFACE)

/*****************************************************************************
  GLOBAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/

#define FIP_CAM_MIN_VISIB_DIST            (7.f)            /*!< Minimal visibility distance for a valid camera lane */
#define FIP_CAM_MAX_DIFF_HEADING_ANGLE    (DEG2RAD(1.f))   /*!< Threshold for the difference of the heading angle 
                                                                between the left and right lane marker. 
                                                                Below this threshold the lane markers are trusted */
#define FIP_CAM_MAX_LANE_WIDTH_ROADWORKS  (2.5f)            /*!< Maximum camera lane width for assuming a roadworks on a highway */
#define FIP_CAM_MIN_LANE_WIDTH_RANGE      (2.0f)            /*!< Minimum valid camera lane width */
#define FIP_CAM_MAX_LANE_WIDTH_RANGE      (5.0f)            /*!< Maximum valid camera lane width */

/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/

/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*! Definition of pointer to FIPCamLane output structure for access within this sub module */
SET_MEMSEC_VAR(pt_FIP_CL_Output)
static FIP_CL_Output_t * pt_FIP_CL_Output;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_CL_InitEveryCycle(void);
static void FIP_v_CalcCurveCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse);
static void FIP_v_CalcCurvatureChangeCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse);
static void FIP_v_CalcVisibilityDistCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse);
static void FIP_v_CalcHeadingAngleCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse);
static void FIP_v_CalcWidthCamLane(const boolean b_MarkerToUse);
static void FIP_v_SetCamLaneMarkerToUseFusion(boolean * pb_MarkerToUse, t_CamLaneMarkerEnum * pt_MarkerToUse);
static void FIP_v_SetCamLaneIsRoadEdge(const boolean b_MarkerToUse);
static void FIP_v_SetCamLaneObjAssociationValidity(const boolean b_MarkerToUse);
static void FIP_v_SetRoadworksCam(const boolean b_MarkerToUse);

/*************************************************************************************************************************
  Functionname:    FIP_v_CamLaneDataProcess                                                                         */ /*!

  @brief           FCT Camera Lane Data Preprocessing Main

  @description     FCT camera lane data preprocessing main function. Calls other functions for preprocessing the 
                    camera lane information received in FCT_SEN for reuse in other parts of FCT_SEN.
                    - Determine which lane marker should be considered for determining the curvature, visibility distance or heading angle
                    - Determine the heading angle of the camera lane
                    - Determine the curvature of the camera lane 
                    - Determine the curvature change of the camera lane
                    - Determine the visibility range of the camera lane
                    - Determine the width of the camera lane
                    - Determine if the camera lane is a road edge
                    - Determine if the camera lane object association is valid
                    - Determine if the camera lane indicates a roadworks

  @startuml
    Partition FIP_v_CamLaneDataProcess
    Start
    Note right: This function calls other functions for preprocessing the camera lane information \n received in FCT sensor cycle for reuse in other parts of FCT sensor cycle
    - Determine which lane marker should be considered for determining \n the curvature, visibility distance or heading angle 
    - Determine the heading angle of the camera lane
    - Determine the curvature of the camera lane
    - Determine the curvature change of the camera lane
    - Determine the visibility range of the camera lane
    - Determine the width of the camera lane
    - Determine if the camera lane is a road edge
    - Determine if the camera lane object association is valid
    - Determine if the camera lane indicates a roadworks
    End
  @enduml

  @return          -

  @param[in]       pt_FIP_CL_InputGlobal : Reference to FIP Camera Lane input structure that is instantiated in Frame module
  @param[in]       pt_FIP_CL_OutputGlobal : Reference to FIP Camera Lane output structure that is instantiated in Frame module

  @glob_in         pt_FIP_CL_Output->t_FIPCamLaneDebugData : Data structure used for storing debug data
  @glob_in         FIP_SimCamLaneOutputFreeze : Data structure used for storing simulation output
 
  @c_switch_part   FCT_SIMU : Simulation specific compiler switch
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             FIP_v_CL_PreProcess (FIP_CL_InputConst_t * pt_FIP_CL_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_CamLaneDataProcess(FIP_CL_Output_t * pt_FIP_CL_OutputGlobal)
{
  boolean b_MarkerToUse;            /*!< Boolean if the info in t_MarkerToUse should be considered */
  t_CamLaneMarkerEnum MarkerToUse;  /*!< Lane marker to be used for determining the curvature, visibility distance or heading angle */

  /* Assign the local pointers */
  pt_FIP_CL_Output = pt_FIP_CL_OutputGlobal;

  /*! Initialize input-output structures for this component */
  FIP_v_CL_InitEveryCycle();
  
  /*! Determine which lane marker should be considered for determining the curvature, visibility distance or heading angle */
  FIP_v_SetCamLaneMarkerToUseFusion(&b_MarkerToUse, &MarkerToUse);
  /*! Determine the heading angle of the camera lane */
  FIP_v_CalcHeadingAngleCamLane(b_MarkerToUse, MarkerToUse);
  /*! Determine the curvature of the camera lane */
  FIP_v_CalcCurveCamLane(b_MarkerToUse, MarkerToUse);
  /*! Determine the curvature change of the camera lane */
  FIP_v_CalcCurvatureChangeCamLane(b_MarkerToUse, MarkerToUse);
  /*! Determine the visibility range of the camera lane */
  FIP_v_CalcVisibilityDistCamLane(b_MarkerToUse, MarkerToUse);
  /*! Determine the width of the camera lane */
  FIP_v_CalcWidthCamLane(b_MarkerToUse);
  /*! Determine if the camera lane is a road edge */
  FIP_v_SetCamLaneIsRoadEdge(b_MarkerToUse);
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
  /*! Determine if the camera lane object association is valid */
  FIP_v_SetCamLaneObjAssociationValidity(b_MarkerToUse);
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
  /*! Determine if the camera lane indicates a roadworks */
  FIP_v_SetRoadworksCam(b_MarkerToUse);


#ifdef FCT_SIMU
  {
    /*! Set debug data */
    pt_FIP_CL_Output->t_FIPCamLaneDebugData.b_MarkerToUse = b_MarkerToUse;
  }
#endif

  /* Reset the local pointers */
  pt_FIP_CL_Output = NULL;
}
/*************************************************************************************************************************
  Functionname:    FIP_v_CL_InitEveryCycle                                                                        */ /*!

  @brief           Initialize non-persistent output data structures and variables in FIP Camera Lane sub-module

  @description     Initialize non-persistent output data structures and variables in the sub module, This function uses 
                   local pointer to the sub module output instantiated in Frame

  @startuml 
    Partition FIP_v_CL_InitEveryCycle
    Start
        Note right: This function initialize non-persistent data structures \n and variables in FIP Camera Lane sub-module	
        - Depending on the available sources set default \n values to the non-persistent data structure
    End
  @enduml
  
  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_CL_Output: Reference to the sub module output 
                    b_Roadworks : Info if camera lane indicates a roadworks (on a highway) [TRUE, FALSE]
                    b_CamLaneAssocValid : Info if camera lane association is valid [TRUE, FALSE]
                    f_Curve : Curvature of the camera lane [full range of datatype float32] 1/m
                    f_CurvatureChange : Curvature change of the camera lane [full range of datatype float32] m-2
                    f_VisibilityDist : Visibility distance of the camera lane [full range of datatype float32 >= 0.f] m
                    f_HeadingAngle : Heading angle relative to the camera lane [full range of datatype float32] rad
                    f_LaneWidth : Width of the camera lane [full range of datatype float32 >= 0.f] m
                    b_CamLaneIsRoadEdge : Info if the camera lane is a road edge [TRUE, FALSE] with i in [0u ... FIP_CL_NUM_LANES[

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.10.2016
  @changed         03.10.2016

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_CL_InitEveryCycle(void)
{
  t_CamLaneMarkerEnum t_NumCamLanes;
    /*! Set default values */
  pt_FIP_CL_Output->b_Roadworks = FALSE;      /*!< Info if camera lane indicates a roadworks (on a highway) */
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
  pt_FIP_CL_Output->b_CamLaneAssocValid = FALSE;  /*! Info if camera lane association is valid */
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
  pt_FIP_CL_Output->f_Curve = 0.f;            /*!< Curvature of the camera lane */
  pt_FIP_CL_Output->f_CurvatureChange = 0.f;  /*!< Curvature change of the camera lane*/
  pt_FIP_CL_Output->f_VisibilityDist = 0.f;   /*!< Visibility distance of the camera lane */
  pt_FIP_CL_Output->f_HeadingAngle = 0.f;     /*!< Heading angle relative to the camera lane */
  pt_FIP_CL_Output->f_LaneWidth = 0.f;        /*!< Width of the camera lane */

 for (t_NumCamLanes = (t_CamLaneMarkerEnum)0; t_NumCamLanes < FIP_CL_NUM_LANES; t_NumCamLanes++)
 {
     pt_FIP_CL_Output->b_CamLaneIsRoadEdge[t_NumCamLanes] = FALSE;
 }
}
/*************************************************************************************************************************
  Functionname:    FIP_v_SetCamLaneMarkerToUseFusion                                                                */ /*!

  @brief           Determine which lane marker should be considered for determining the curvature, visibility distance or 
                    heading angle

  @description     Determine which lane marker of the left or right camera lane should be considered for 
                   determining the curvature, visibility distance or heading angle. The existence probability of 
                   the lane markers, the visibility distance and the heading angle for the left and 
                   right lane markers are considered.

  @startuml 
    Partition FIP_v_SetCamLaneMarkerToUseFusion
    Start
        Note right: This function determines which lane marker should be considered \n for determining the curvature, visibility distance or heading angle
        If (Both markers are valid based on \n existence probability and visibility range) then (True) 
          If (Difference between Left and Right Heading angle &lt; 1 degree) then (True)
            If (Left visibility range is higher) then (true)
              - Use left side marker
            Else (False)
              - Use right side marker
            Endif
          Else (False)
            : Set default marker to be used;
            Note right: If the heading angle is \n different for both sides
          Endif
        Else (False)
          If (Only the left marker is valid) then (True)
            - Use left side marker
          Else (False)
            If (Only the right marker is valid) then (True)
              - Use right side marker
            Else (False)
              :Set default marker to be used;
              Note right: If no valid lane marker
            Endif
          Endif
        Endif
    End
  @enduml

  @return          -

  @param[in]      None
  @param[out]     pb_MarkerToUse : Boolean if the info in t_MarkerToUse should be considered [TRUE, FALSE]
  @param[out]     pt_MarkerToUse : Info which lane marker should be considered [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                      CourseInfo[i] : Course information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                        CourseInfoSegNear.f_Length : length of near segment [full range of datatype float32 with >= 0.f] m
                        f_Angle : [full range of datatype float32] rad
                      sSigHeader.eSigStatus: signal header status [AlgoSignalState_t as in Rte_Type.h]
                      LaneMarkerInfo[i] : Lane marker information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                        u_ExistanceProbability : Probability of existence [0u...100u] %
                  pSLATE_CamLaneData->sSigHeader.eSigStatus: signal header status [AlgoSignalState_t as in Rte_Type.h]
  @glob_out       -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @created         -
  @changed         12.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetCamLaneMarkerToUseFusion(boolean * pb_MarkerToUse, t_CamLaneMarkerEnum * pt_MarkerToUse)
{
  /*! Set local variable for visibility distance */
  const float32 f_VisibDistLeft = pSLATE_CamLaneData->CourseInfo[FIP_CL_MK_LEFT].CourseInfoSegNear.f_Length;
  const float32 f_VisibDistRight = pSLATE_CamLaneData->CourseInfo[FIP_CL_MK_RIGHT].CourseInfoSegNear.f_Length;
  float32 f_Abs_CourseInfo;

  /*! Set boolean if Marker to be used at all */
  (*pb_MarkerToUse) = TRUE;

  /*! If both markers are valid based on existence probability and visibility range */
  if( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
      (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
      (f_VisibDistLeft > FIP_CAM_MIN_VISIB_DIST) &&
      (f_VisibDistRight > FIP_CAM_MIN_VISIB_DIST) &&
      (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
    )
  {
    /*! Only trust the camera lane if the heading angle is similar for both sides */
    f_Abs_CourseInfo = fABS(pSLATE_CamLaneData->CourseInfo[FIP_CL_MK_LEFT].f_Angle - pSLATE_CamLaneData->CourseInfo[FIP_CL_MK_RIGHT].f_Angle);
    if(f_Abs_CourseInfo < FIP_CAM_MAX_DIFF_HEADING_ANGLE)
    {
      if (f_VisibDistLeft > f_VisibDistRight)
      {
        /*! If the left visibility range is higher, use the left side */
        (*pt_MarkerToUse) = FIP_CL_MK_LEFT;
      }
      else
      {
        /*! If the right visibility range is higher, use the right side */
        (*pt_MarkerToUse) = FIP_CL_MK_RIGHT;
      }
    }
    else
    {
      /*! If the heading angle is different for both sides, set default */
      (*pt_MarkerToUse) = FIP_CL_MK_LEFT; /*!< Any valid value is set. The info in pt_MarkerToUse is only considered in the following, if pb_MarkerToUse == TRUE. */
      (*pb_MarkerToUse) = FALSE;
    }
  }
  else if( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
           (f_VisibDistLeft > FIP_CAM_MIN_VISIB_DIST) &&
           (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
         )
  {
    /*! If only the left marker is valid, use the left side */
    (*pt_MarkerToUse) = FIP_CL_MK_LEFT;
  }
  else if( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
           (f_VisibDistRight > FIP_CAM_MIN_VISIB_DIST) &&
           (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
         )
  {
    /*! If only the right marker is valid, use the right side */
    (*pt_MarkerToUse) = FIP_CL_MK_RIGHT;
  }
  else
  {
    /*! If no valid lane marker, set default */
    (*pt_MarkerToUse) = FIP_CL_MK_LEFT; /*!< Any valid value is set. The info in pt_MarkerToUse is only considered in the following, if pb_MarkerToUse == TRUE. */
    (*pb_MarkerToUse) = FALSE;
  }
  
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CalcCurveCamLane                                                                           */ /*!

  @brief           Determine the curvature of the camera lane

  @description     Determine the curvature of the camera lane that should be used on other parts of the code :
                   If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value 

  @startuml 
  Partition FIP_v_CalcCurveCamLane 
  Start
      Note right: This function determine the curvature of the camera lane
    if (Information in Lane Marker is valid) then (True)
        : Use camera lane curvature as input of camera;
    else (False)
        : Set camera lane curvature to 0;
   endif
   stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]
  @param[in]       MarkerToUse : Info which lane marker should be considered [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         pSLATE_CamLaneData . Camera lane information
                     CourseInfo[i] : Course information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       CourseInfoSegNear.f_C0 : camera lane curvature as input of camera [full range of datatype float32] 1/m
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     f_Curve : camera lane curvature to be considered in other parts of the code [full range of datatype float32] 1/m
  

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         13.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_CalcCurveCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse)
{
  /*! If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value */
  if(b_MarkerToUse == TRUE) 
  {
    pt_FIP_CL_Output->f_Curve = pSLATE_CamLaneData->CourseInfo[MarkerToUse].CourseInfoSegNear.f_C0;
  }
  else
  {
    pt_FIP_CL_Output->f_Curve = 0.f;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_CalcCurvatureChangeCamLane                                                                 */ /*!

  @brief           Determine the curvature change of the camera lane

  @description     Determine the curvature change of the camera lane to be used in other parts of the code :
                   If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value 

  @startuml 
  Partition FIP_v_CalcCurvatureChangeCamLane
  Start
      Note right: This function determine the curvature change of the camera lane
    if (Information in Lane Marker is valid)then (True)
      - Use camera lane curvature change as input of camera
    else (False)
      - Set camera lane curvature change to 0
    endif
  stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]
  @param[in]       MarkerToUse : Info which lane marker should be considered [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                     CourseInfo[i]: Course information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       CourseInfoSegNear.f_C1 : camera lane curvature change as input of camera [full range of datatype float32] 1/m
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     f_CurvatureChange : camera lane curvature change to be considered in other parts of the code [full range of datatype float32] m-2


  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         13.01.2016

  @author          Thomas Bock
*************************************************************************************************************************/
static void FIP_v_CalcCurvatureChangeCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse)
{
  /*! If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value */
  if(b_MarkerToUse == TRUE) 
  {
    pt_FIP_CL_Output->f_CurvatureChange = pSLATE_CamLaneData->CourseInfo[MarkerToUse].CourseInfoSegNear.f_C1;
  }
  else
  {
    pt_FIP_CL_Output->f_CurvatureChange = 0.f;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_CalcVisibilityDistCamLane                                                                  */ /*!

  @brief           Determine the visibility range of the camera lane

  @description     Determine the visibility range of the camera lane to be considered in other parts of the code : 
                   If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value

  @startuml 
  Partition FIP_v_CalcVisibilityDistCamLane
  Start
      Note right: This function determine the visibility range of the camera lane
    if (Information in Lane Marker is valid)then (True)
        - Use length of camera lane as input to camera lane visibility range
    else (False)
        - Set camera lane visibility range to 0
    endif 
  Stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]
  @param[in]       MarkerToUse : Info which lane marker should be considered [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                     CourseInfo[i] : Course information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       CourseInfoSegNear.f_Length : length of near segment of camera lane i [full range of datatype float32 >= 0.f] m
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     f_VisibilityDist : camera lane visibility range to be used on other parts of the code [full range of datatype float32 >= 0.f] m
  
  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         13.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_CalcVisibilityDistCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse)
{
  /*! If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value */
  if(b_MarkerToUse == TRUE)
  {
    pt_FIP_CL_Output->f_VisibilityDist = pSLATE_CamLaneData->CourseInfo[MarkerToUse].CourseInfoSegNear.f_Length;
  }
  else
  {
    pt_FIP_CL_Output->f_VisibilityDist = 0.f;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_CalcWidthCamLane                                                                           */ /*!

  @brief           Determine the width of the ego lane based on the camera information

  @description     Determine the width of the ego lane based on the camera information

  @startuml 
  Partition FIP_v_CalcWidthCamLane
  Start
      Note right: This function determine the width of the ego lane \n based on the camera information
      If (Existence probability of both left and right \n lane marker should be greater or equal to threshold \n and \n Visibility distances of both left and right lane should \n be greater than minimal visibility distance for a valid \n camera lane \n and \n left side marker distance is greater than right side \n marker distance) then (True)
      - Calculate lane width using left and right lane marker
        If (lane width is less than minimum lane width range \n OR greater than maximum lane width range) then (True)
        - Reset invalid cam lane width to 0
        else (False)
        Endif
      else (False)
        - Reset invalid cam lane width to 0
      endif
  Stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]

  @glob_in         pSLATE_CamLaneData :  Camera lane information
                     LaneMarkerInfo[i]: Lane marker information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       f_MarkerDist : Distance to camera lane marker [full range of datatype float32] m
                       u_ExistanceProbability : Probability of existence for camera lane marker i [0u...100u] %
                     sSigHeader.eSigStatus : Signal header status [AlgoSignalState_t as in Rte_Type.h]
                     CourseInfo[i]:  Course information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       CourseInfoSegNear.f_Length : length of near segment of camera lane i [full range of datatype float32 with >= 0.f] m
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     f_LaneWidth : Width of the ego lane based on the camera information [full range of datatype float32 >= 0.f] m

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         14.01.2016

  @author          Fabian Killus, Thomas Bock
*************************************************************************************************************************/
static void FIP_v_CalcWidthCamLane(const boolean b_MarkerToUse)
{
  /*! Obtain lateral position of left and right lane marker */
  const float32 f_LeftMarkerDist  = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist;
  const float32 f_RightMarkerDist = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;

  /*! Check if lane markers are trustworthy */
  if( 
      (b_MarkerToUse == TRUE) &&
      (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) && 
      (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
      (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
      (pSLATE_CamLaneData->CourseInfo[FIP_CL_MK_LEFT].CourseInfoSegNear.f_Length > FIP_CAM_MIN_VISIB_DIST) &&
      (pSLATE_CamLaneData->CourseInfo[FIP_CL_MK_RIGHT].CourseInfoSegNear.f_Length > FIP_CAM_MIN_VISIB_DIST) &&
      (f_LeftMarkerDist > f_RightMarkerDist)
  )
  {
    /*! Calculate lane width */
    pt_FIP_CL_Output->f_LaneWidth =  f_LeftMarkerDist - f_RightMarkerDist;
    /*! Range Check*/
    if(  (pt_FIP_CL_Output->f_LaneWidth < FIP_CAM_MIN_LANE_WIDTH_RANGE)
      || (pt_FIP_CL_Output->f_LaneWidth > FIP_CAM_MAX_LANE_WIDTH_RANGE)  
      )
    {
      /*! Reset invalid cam lane width*/
      pt_FIP_CL_Output->f_LaneWidth = 0.f;
    }
    else
    {
      /* do nothing */
    }
  }
  else
  {
    /*! Not possible to provide reasonable lane width */
    pt_FIP_CL_Output->f_LaneWidth = 0.f;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_CalcHeadingAngleCamLane                                                                    */ /*!

  @brief           Determine the heading angle of the camera lane

  @description     Determine the heading angle of the camera lane to be used in other parts of the code

  @startuml 
  Partition FIP_v_CalcHeadingAngleCamLane
  Start
      Note right: This function determine the heading angle of the camera lane	
      if (Information in Lane Marker is valid)then (True)
        -Use heading angle of the camera as input to camera lane heading angle
      else (False)
        -Set camera lane heading angle to 0
      endif 
  Stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]
  @param[in]       MarkerToUse : Info which lane marker should be considered [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                     CourseInfo[i]: Course information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       f_Angle : heading angle of the camera as input of camera [full range of datatype float32] rad
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                    f_HeadingAngle : heading angle of the camera to be used in other parts of the code [full range of datatype float32] rad

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         13.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_CalcHeadingAngleCamLane(const boolean b_MarkerToUse, const t_CamLaneMarkerEnum MarkerToUse)
{
  /*! If the info in MarkerToUse is valid, use the lane marker in MarkerToUse; otherwise set the default value */
  if(b_MarkerToUse == TRUE)
  {
    pt_FIP_CL_Output->f_HeadingAngle = pSLATE_CamLaneData->CourseInfo[MarkerToUse].f_Angle;
  }
  else
  {
    /*! Set default if camera lane not valid */
    pt_FIP_CL_Output->f_HeadingAngle = 0.f;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_SetCamLaneIsRoadEdge                                                                       */ /*!

  @brief           Determine if the camera lane is a road edge

  @description     Determine if the camera lane is a road edge based on the camera lane marker type and 
                   the elevation information of the camera

  @startuml 
  Partition FIP_v_SetCamLaneIsRoadEdge
  Start
      If (Check if any one of the lane markers \n is selected for usea \n and \n Probability of existence for camera lane \n marker is greater than zero) then (True)
          if(Camera lane marker type is any one of the below \n Continuous marker \n Low curb marker \n High curb marker \n Crash barriers/traffic barriers \n Wall marker \n Road shoulder) then (True)
            -Camera lane is at road edge
          Else (False)
        If(Camera lane markers are elevated \n and \n Marker type should not be dashed \n and narrow dashed) then (True)
            - Camera lane is at road edge
        Else
        Endif
          Endif
      Endif
  Stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                     LaneMarkerInfo[i] : Lane marker information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       u_ExistanceProbability : Probability of existence for camera lane marker i [0u...100u] %
                       MarkerType : Camera lane marker type [t_MarkerType as in Rte_Type.h]
                       b_MarkerElevated : Information if camera lane marker i is elevated [TRUE, FALSE]
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     b_CamLaneIsRoadEdge[i] : Info if camera lane i is a road edge [TRUE, FALSE]
                     with i in [t_CamLaneMarkerEnum as in Rte_SWCFctSenAdapt_Type.h]


  @c_switch_part   FIP_CAM_USE_ELEVATED_LANE_MARKERS : Use the information if camera lane markers are elevated
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         14.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetCamLaneIsRoadEdge(const boolean b_MarkerToUse)
{
  uint8 i;

  for(i = 0u; i < (uint8)FIP_CL_NUM_LANES; i++)
  {
    /*! Default: No road edge */
    pt_FIP_CL_Output->b_CamLaneIsRoadEdge[i] = FALSE;

    /*! Possible lane marker types for a road edge */
    if( (b_MarkerToUse == TRUE) &&
        (pSLATE_CamLaneData->LaneMarkerInfo[i].u_ExistanceProbability > 0u) &&
        ( (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType == CL_MARKER_TYPE_CONTINUOUS) ||
          (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType == CL_MARKER_TYPE_LOWCURB) ||
          (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType == CL_MARKER_TYPE_HIGHCURB) ||
          (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType == CL_MARKER_TYPE_CRASHBARRIER) ||
          (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType == CL_MARKER_TYPE_WALL) ||
          (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType == CL_MARKER_TYPE_ROADSHOULDER)
#if(FIP_CAM_USE_ELEVATED_LANE_MARKERS)
          || 
          ( 
            (pSLATE_CamLaneData->LaneMarkerInfo[i].b_MarkerElevated == TRUE) &&
            (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType != CL_MARKER_TYPE_DASHED) &&
            (pSLATE_CamLaneData->LaneMarkerInfo[i].MarkerType != CL_MARKER_TYPE_NARROWDASHED)
          )
#endif
        )
      )
    {
      pt_FIP_CL_Output->b_CamLaneIsRoadEdge[i] = TRUE;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_SetRoadworksCam                                                                            */ /*!

  @brief           Determine if the camera lane indicates a roadworks

  @description     Determine if the camera lane indicates a roadworks. This depends on the validity of the camera data and 
                   the roadworks detection of the camera.

  @startuml 
    Partition FIP_v_SetRoadworksCam
    Start
        Note right: This function determine if the camera lane indicates a roadworks	
        if (Check if any one of the lane markers is selected for use) then (True)
            if (Existence probability of both left \n and right lane marker should be greater \n or equal to Threshold \n and \n ¬lane width is less than Maximum \n camera lane width for assuming \n a roadworks on a highway)then (True)
              -Camera lane indicates roadworks
            Else
          If (Check if camera lane marker is any of below type \n Multiple marker \n Left barrier \n Right barrier \n Crossing marker \n Inhibit single lane \n Hold) then (True)
              -Camera lane indicates roadworks
            Endif
          Endif
        Endif
    Stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                     sSigHeader.eSigStatus : Signal header status [AlgoSignalState_t as in Rte_Type.h]
                     LaneMarkerInfo[i] : Lane marker information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       u_ExistanceProbability : Probability of existence for camera lane marker i [0u...100u] %
                       f_MarkerDist : Distance to camera lane marker i [full range of datatype float32] m
                     ConstructionSite : Construction side information provided by the camera
                        b_CrossingMarker [TRUE, FALSE]
                        b_Hold [TRUE, FALSE]
                        b_InhibitSingleLane [TRUE, FALSE]
                        b_LeftBarrier [TRUE, FALSE]
                        b_RightBarrier [TRUE, FALSE]
                        b_MultipleMarker [TRUE, FALSE]

  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     b_Roadworks : Info if camera lane indicates a roadworks (on a highway) [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         14.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetRoadworksCam(const boolean b_MarkerToUse)
{ 
  /*! Initialize detected roadworks to false */
  pt_FIP_CL_Output->b_Roadworks = FALSE;

  /*! If the camera lane width is lower than a threshold or if the ConstructionSite structure indicates a roadworks, 
      set the detected roadworks information to true */
  if( (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
      (b_MarkerToUse == TRUE) &&
      ( ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
          (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
          ( (pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist - pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist) 
            < FIP_CAM_MAX_LANE_WIDTH_ROADWORKS
          )
        ) ||
        (pSLATE_CamLaneData->ConstructionSite.b_CrossingMarker == TRUE) ||
        (pSLATE_CamLaneData->ConstructionSite.b_Hold == TRUE) ||
        (pSLATE_CamLaneData->ConstructionSite.b_InhibitSingleLane == TRUE) ||
        (pSLATE_CamLaneData->ConstructionSite.b_LeftBarrier == TRUE) ||
        (pSLATE_CamLaneData->ConstructionSite.b_RightBarrier == TRUE) ||
        (pSLATE_CamLaneData->ConstructionSite.b_MultipleMarker == TRUE)
      )
    )
  {
    pt_FIP_CL_Output->b_Roadworks = TRUE;
  }
}

#if(LA_CFG_CAM_OBJ_ASSOC_VALID)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetCamLaneObjAssociationValidity                                                           */ /*!

  @brief           Determine if the camera lane object association is valid

  @description     Determine if the camera lane object association is valid based on the validity of the camera lane information

  @startuml 
  Partition FIP_v_SetCamLaneObjAssociationValidity
  Start
      Note right: This function determine if the camera lane object association is valid
      If (Check if any one of the lane markers \n is selected for use \n                              and \n Existence probability of both left \n and right lane marker should be greater \n or equal to Threshold)then (True)
        -Camera lane object association is valid
      Endif
  Stop
  @enduml

  @return          -

  @param[in]       b_MarkerToUse : Boolean if the camera lane marker information can be used [TRUE, FALSE]

  @glob_in         pSLATE_CamLaneData : Camera lane information
                     sSigHeader.eSigStatus : Signal header status [AlgoSignalState_t as in Rte_Type.h]
                     LaneMarkerInfo[i]:  Lane marker information of camera lane i with i in [FIP_CL_MK_LEFT, FIP_CL_MK_RIGHT as in Rte_SWCFctSenAdapt_Type.h] 
                       u_ExistanceProbability : Probability of existence for camera lane marker i [0u...100u] %
  @glob_out        pt_FIP_CL_Output : Reference to the sub module input
                     b_CamLaneAssocValid : Info if camera lane association is valid [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @created         -
  @changed         14.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetCamLaneObjAssociationValidity(const boolean b_MarkerToUse)
{
	boolean b_CamLaneExistance = FIP_b_CamLaneExistanceProb();
  /*! Initialize camera lane object association to false */
  pt_FIP_CL_Output->b_CamLaneAssocValid = FALSE;
 
  if( 
      (b_MarkerToUse == TRUE) &&
	  (b_CamLaneExistance)
	)
  {
    pt_FIP_CL_Output->b_CamLaneAssocValid = TRUE;
  }

}
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
/*************************************************************************************************************************
  Functionname:    FIP_v_InitGlobalCamLaneData                                                                      */ /*!

  @brief           Initialization of global camera lane data

  @description     Initialization of global camera lane data, i.e. evaluated camera lane data which is used in other files

  @startuml 
  Partition FIP_v_InitGlobalCamLaneData
  Start
      Note right: This function initializes global camera lane data	
      - Depending on the available sources initialize persistent memory \n and non-persistent memory used in FIP Camera Lane  
  Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_CL_InputGlobal : Reference to FIP Camera Lane input structure that is instantiated in Frame module
  @param[in]       pt_FIP_CL_OutputGlobal : Reference to FIP Camera Lane output structure that is instantiated in Frame module

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         14.01.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_InitGlobalCamLaneData(FIP_CL_Output_t * pt_FIP_CL_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_CL_Output = pt_FIP_CL_OutputGlobal;

  /* Initialize non-persistent memory used in FIP Camera Lane sub-module */
  FIP_v_CL_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_CL_Output = NULL;
}

#endif /*!< SLATE_CFG_CAM_LANE_INTERFACE */

///@}
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
