/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_lane_matrix_plg.c

DESCRIPTION:               ACC FCT Preprocessing of lane matrix data

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             19.03.2013

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_lane_matrix_plg FIP Lane Matrix
@ingroup fip
@brief          Preprocessing of lane matrix data is done, & Fusion of information from multiple sources such as EM, Navi, and CAM is considered for determining the parameters of FIP Lane matrix.\n\n

@{

*/
/*****************************************************************************
  GLOBAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/

///*! Virtual address for FIP lane matrix meas freeze information */ 
//#ifndef FCT_MEAS_ID_FIPLANEMATRIX_DEVICE
//#define FCT_MEAS_ID_FIPLANEMATRIX_DEVICE         (0x202703F0u)
//#endif

/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/

/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/

#define FIP_LM_INVALID_NUM_LANE               (-1)    /*!< Invalid/default number of lanes */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
#define FIP_LM_DEFAULT_CAM_LANE_WIDTH         (-1.f)  /*!< Default camera lane width */
#define FIP_LM_MIN_ADJ_CAM_LANE_WIDTH         (1.5f)  /*!< Minimal camera lane width of the adjacent lane */
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
#define FIP_LM_TIMER_INVAILD_CURRENT_NUM_LANE   (1.f)   /*!< Only above this threshold, the filtered number of lanes is set to invalid */
#define FIP_LM_TIMER_INVAILD_FILT_NUM_LANE      (1.f)   /*!< Only above this threshold, the invalid filtered number of lanes is set to the new current value */
#define FIP_LM_FILTER_CONSTANT                  (40.f)  /*!< Filter constant for filtering the number of lanes */
#define FIP_LM_MAX_ROAD_BORDER_DIST_FOR_CAM_FUSION  (6.f) /*!< Maximal road border distance for camera lane fusion */
#endif

/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
/*! Structure to store global data for determining the FIP lane matrix */
typedef struct FIPLaneMatrixGlobalData_t{
  float32 f_LeftTimerUnknownCurrentNumLane;   /*!< Timer for the unknown current number of lanes left */
  float32 f_RightTimerUnknownCurrentNumLane;  /*!< Timer for the unknown current number of lanes right */
  float32 f_LeftTimerUnknownFiltNumLane;      /*!< Timer for the unknown filtered number of lanes left */
  float32 f_RightTimerUnknownFiltNumLane;     /*!< Timer for the unknown filtered number of lanes right */
  float32 f_FusedNumLaneLeftFilt;   /*!< Filtered fused (EM, NAVI, camera) number of lanes left */
  float32 f_FusedNumLaneRightFilt;  /*!< Filtered fused (EM, NAVI, camera) number of lanes right */
}t_FIPLaneMatrixGlobalData;
#endif

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
SET_MEMSEC_VAR(FIPLaneMatrixGlobalData)
static t_FIPLaneMatrixGlobalData FIPLaneMatrixGlobalData; /*!< Structure to store global data for determining the FIP lane matrix */
#endif

/*! Definition of pointer to FIPLaneMatrix output structure for access within this module */
SET_MEMSEC_VAR(pt_FIP_LM_Output)
static FIP_LM_Output_t * pt_FIP_LM_Output; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to fill the data in to the sturcture representing component output */

/*! Definition of pointer to FIPLaneMatrix input structure for access within this module */
SET_MEMSEC_VAR(pt_FIP_LM_Input)
static FIP_LM_InputConst_t * pt_FIP_LM_Input; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to access the data within the structure represnting input to the component */

/*****************************************************************************
  Device Freezes
*****************************************************************************/

/*****************************************************************************
  Simulation Freezes
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_LM_InitPersistentData(void);
static void FIP_v_LM_InitEveryCycle(void);
static void FIP_v_LM_SetInput(void);
static void FIP_v_SetLaneMatrix(void);
static void FIP_v_SetLaneWidthInfo(void);

#if (FCT_CFG_ROAD_INPUT)
static void FIP_v_SetLaneMatrixEM(sint8 * ps_NumLaneLeft, sint8 * ps_NumLaneRight);
#endif /* FCT_CFG_ROAD_INPUT */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_SIMPLE_NAVI_INTERFACE)
static void FIP_v_SetLaneMatrixNavi(sint8 * ps_NumLane);
#endif
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
static void FIP_v_SetLaneMatrixCam(sint8 * ps_NumLaneLeft, sint8 * ps_NumLaneRight);
static void FIP_v_SetLaneMatrixCamOneSide(sint8 * ps_NumLane, t_CamLaneMarkerEnum const DirectLaneMarker, t_CamLaneMarkerEnum const AdjLaneMarker);
static void FIP_v_LaneMatrixLaneChange(void);
#endif
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
static void FIP_v_LaneMatrixFusion(boolean * pb_MultipleInputData, const sint8 s_EMNumLaneLeft, const sint8 s_EMNumLaneRight,
                                   const sint8 s_NaviNumLane, const sint8 s_CamNumLaneLeft, const sint8 s_CamNumLaneRight);
static void FIP_v_LaneMatrixFiltering(const boolean b_MultipleInputData, const sint8 s_EMNumLaneLeft, 
                                      const sint8 s_EMNumLaneRight, const sint8 s_NaviNumLane, const sint8 s_CamNumLaneLeft, const sint8 s_CamNumLaneRight);
static void FIP_v_IsLMInfoIdentical(boolean * pb_InfoIsIdenticalLeft, boolean * pb_InfoIsIdenticalRight, 
                                    const sint8 s_NumLaneLeft, const sint8 s_NumLaneRight, const sint8 s_EMNumLaneLeft, const sint8 s_EMNumLaneRight, 
                                    const sint8 s_NaviNumLane, const sint8 s_CamNumLaneLeft, const sint8 s_CamNumLaneRight);
static void FIP_v_LaneMatrixFilteringOneSide(float32 * pf_NumLaneFilt, float32 * pf_TimerUnknownCurrentNumLane, float32 * pf_TimerUnknownFiltNumLane, 
                                             sint8 const s_NumLaneCurrent, boolean const b_MultipleInputData, 
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
                                             SITLCStateCamLaneMarkerCrossed_t const CamLaneMarkerCrossed, 
#endif
                                             boolean const b_IsInfoIdentical);
#endif

/*************************************************************************************************************************
  Functionname:    FIP_v_LM_PreProcess                                                                              */ /*!

  @brief           Preprocess inputs for FIP Lane Matrix sub module

  @description     Preprocess inputs for FIP Lane Matrix sub module

  @startuml 
  Partition FIP_v_LM_PreProcess
  Start
  	Note right: This function preprocesses inputs for FIP Lane Matrix 	
	  - Depending on the available sources set all the FIP input data
  Stop
  @enduml

  @return          -

  @param[in,out]   pt_FIP_LM_InputGlobal : Reference to FIP Lane Matrix input structure instantiated in Frame module

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.10.2016
  @changed         22.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_LM_PreProcess(FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal)
{
  /* Assign local pointers */
  pt_FIP_LM_Input = pt_FIP_LM_InputGlobal;

  /* Set inputs */
  FIP_v_LM_SetInput();

  /* Reset local pointers */
  pt_FIP_LM_Input = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_LaneMatrixProcess                                                                          */ /*!

  @brief           Function processing for Lane Matrix

  @description     Initialize the non-persistent data, set FIP lane matrix, set the lane width and freeze data for the 
                   simulation
  
  @startuml 
  Partition FIP_v_LaneMatrixProcess
  Start
	  Note right: This function initializes persistent memory structures in FIP curvature changelane matrix module 	
	  - Initialize input-output structures for this component
  	- Set the lane matrix for function input preprocessing
  	- Set Lane Width
  End
  @enduml

  @return          -

  @param[in]       pt_FIP_LM_InputGlobal : Reference to FIP Lane Matrix input structure that is instantiated in Frame module
                      s_NumOfLaneLeft : Number of lanes on the left [full range of datatype as defined in Rte_Type.h]
                      s_NumOfLaneRight. Number of lanes on the right [full range of datatype as defined in Rte_Type.h]
                      f_FIPLaneWidth : Lane Width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pt_FIP_LM_OutputGlobal : Reference to FIP Lane Matrix output structure that is instantiated in Frame module
  
  @glob_in         FIPLM_DeviceMeasInfoFreeze : Data structure used for freezing debug data
  @glob_in         pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo : Data structure used for storing debug data
                   FIPLMDebugMeasInfo : Data structure used for storing debug data in simulation
                   FIP_SimLaneMatrixOutputFreeze : Data structure used for storing simulation output
  @glob_out        FIPLaneMatrix : Lane matrix global data structure which summarizes information from EM Road, NAVI and camera based on the FCT input preprocessing
                    s_NumOfLaneLeft : Number of lanes on the left [full range of datatype as defined in Rte_Type.h]
                    s_NumOfLaneRight : Number of lanes on the right [full range of datatype as defined in Rte_Type.h]
                    f_FIPLaneWidth : Lane Width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             FIP_v_LM_PreProcess(FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal) 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         22.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_LaneMatrixProcess (FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal, FIP_LM_Output_t * pt_FIP_LM_OutputGlobal)
{
  /* Assign the local pointers */
  pt_FIP_LM_Input = pt_FIP_LM_InputGlobal;
  pt_FIP_LM_Output = pt_FIP_LM_OutputGlobal;

  /*! Initialize input-output structures for this component */
  FIP_v_LM_InitEveryCycle();

  /*! Set the lane matrix for function input preprocessing */
  FIP_v_SetLaneMatrix();
  
  /*! Set Lane Width */
  FIP_v_SetLaneWidthInfo();

  /* Reset local pointers */
  pt_FIP_LM_Input = NULL;
  pt_FIP_LM_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_LM_InitPersistentData                                                                      */ /*!

  @brief           Initialize persistent output data structures and variables in FIP Camera Lane sub-module

  @description     Initialize persistent output data structures and variables in FIP Camera Lane sub-module

  @startuml 
  Partition FIP_v_LM_InitPersistentData
  Start
  	Note right: This function initializes persistent memory structures in FIP curvature change lane matrix module 
	  - Depending on the available sources set default values to the persistent data structure 
  End
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None 
  @glob_out        FIPLaneMatrix : Lane matrix which covers the information of EM Road, NAVI and camera based on the FCT input preprocessing 
                      sNumOfLaneLeft : Number of lanes on the left [full range of datatype as defined in Rte_Type.h]
                      sNumOfLaneRight : Number of lanes on the right [full range of datatype as defined in Rte_Type.h]
                      f_FIPLaneWidth : Lane width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        FIPLaneMatrixGlobalData : Structure to store global data for determining the FIP lane matrix
                      f_FusedNumLaneLeftFilt : Filtered fused (EM, NAVI, camera) number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_FusedNumLaneRightFilt : Filtered fused (EM, NAVI, camera) number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_LeftTimerUnknownCurrentNumLane : Timer for the unknown current number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_RightTimerUnknownCurrentNumLane : Timer for the unknown current number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_LeftTimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_RightTimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
  @glob_out        t_FIP_LM_Output : Reference to FIP Lane Matrix Output structure
                      f_FIPLaneWidth: Lane width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      s_NumOfLaneLeft: Number of lanes on the left [full range of datatype as defined in Rte_Type.h]
                      s_NumOfLaneRight: Number of lanes on the right [full range of datatype as defined in Rte_Type.h]
                      t_FIPLaneWidthClass : Lane width classification [FIP_t_LaneWidthClass as defined in fip_ext.h]
                      t_FIPLaneWidthSource : Source for lane width [FIP_t_LaneWidthSource as defined in fip_ext.h]

  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC


  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.10.2016
  @changed         22.10.2016

  @todo            Remove this entire line if not needed

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_v_LM_InitPersistentData(void)
{
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
  FIPLaneMatrixGlobalData.f_LeftTimerUnknownCurrentNumLane = 0.f;
  FIPLaneMatrixGlobalData.f_RightTimerUnknownCurrentNumLane = 0.f;
  FIPLaneMatrixGlobalData.f_LeftTimerUnknownFiltNumLane = 0.f;
  FIPLaneMatrixGlobalData.f_RightTimerUnknownFiltNumLane = 0.f;
#if (FCT_CFG_ROAD_INPUT)
  FIPLaneMatrixGlobalData.f_FusedNumLaneLeftFilt = (float32)ROAD_GET_LANE_NO_LEFT;
  FIPLaneMatrixGlobalData.f_FusedNumLaneRightFilt = (float32)ROAD_GET_LANE_NO_RIGHT;
#else
  FIPLaneMatrixGlobalData.f_FusedNumLaneLeftFilt = -1.f;
  FIPLaneMatrixGlobalData.f_FusedNumLaneRightFilt = -1.f;
#endif /* FCT_CFG_ROAD_INPUT */
#endif /* FCT_CFG_FIP_LANE_MATRIX_FUSION */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_FIP_LM_Input->b_NaviPathPlausible = FALSE;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_FIP_LM_Input->t_SIT.pt_SITCamLaneMarkerCrossed = NULL;
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/ 
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_FIP_LM_Input->t_SIT.pt_SITLaneChangeCamPreMoveState = NULL;
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/ 
}

/*************************************************************************************************************************
  Functionname:    FIP_v_LM_InitEveryCycle                                                                        */ /*!

  @brief           Initialize non-persistent output data structures and variables in FIP Lane Matrix sub-module 

  @description     Initialize non-persistent output data structures and variables with the default values in FIP Lane Matrix,
                   This function uses local pointer to the sub module output instantiated in Frame.
  
  @startuml 
  Partition FIP_v_LM_InitEveryCycle
  Start
	  Note right: This function initializes non-persistent data structures and variables with the default values	
	  - Depending on the available sources default values to the non-persistent data structure 
  End
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_LM_Output : Reference to FIP Lane Matrix Output structure which covers the information of EM Road, NAVI and camera based on the FCT input preprocessing
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype]
  @glob_out        t_FIP_LM_Input : Reference to FIP Lane Matrix Input structure
                      f_NoLaneProbLeft : Probability that there is no lane on the left [0.f ... 1.f]
                      f_NoLaneProbRight : Probability that there is no lane on the right [0.f ... 1.f]
                   pt_FIP_LM_Output : Reference to FIP Lane Matrix Output structure which covers the information of EM Road, NAVI and camera based on the FCT input preprocessing
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype]
                      f_FIPLaneWidth : Lane width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_FIPLaneWidthClass : Lane width classification [FIP_t_LaneWidthClass as defined in fip_ext.h]
                      t_FIPLaneWidthSource : Source for lane width [FIP_t_LaneWidthSource as defined in fip_ext.h]

  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.09.2016
  @changed         27.09.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_v_LM_InitEveryCycle(void)
{
  /* Initialize inputs */
#if (FCT_CFG_ROAD_INPUT)
  pt_FIP_LM_Input->pf_NoLaneProbLeft = NULL;
  pt_FIP_LM_Input->pf_NoLaneProbRight = NULL;
#endif /* FCT_CFG_ROAD_INPUT */

  /* Initialize outputs */
  pt_FIP_LM_Output->s_NumOfLaneLeft = FIP_LM_INVALID_NUM_LANE;
  pt_FIP_LM_Output->s_NumOfLaneRight = FIP_LM_INVALID_NUM_LANE;
  pt_FIP_LM_Output->f_FIPLaneWidth = 0.f;
  pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_UNKNOWN;
  pt_FIP_LM_Output->t_FIPLaneWidthSource = FIP_SOURCE_0;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_LM_SetInput                                                                                */ /*!

  @brief           Set/assign values to Lane Matrix input structure

  @description     Set/assign values to Lane Matrix input structure

  @startuml 
  Partition FIP_v_LM_SetInput
  Start
	  Note right: This function assigns input values to Lane Matrix input structure
	  - Depending on the available sources set input for FIP Lane Matrix
  End
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None
  @glob_out        pt_FIP_LM_Input : Reference to FIP Lane Matrix Input structure
                      pf_NoLaneProbLeft : Probability that there is no lane on the left [0.f ... 1.f]
                      pf_NoLaneProbRight : Probability that there is no lane on the right [0.f ... 1.f]

  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.09.2016
  @changed         27.09.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_v_LM_SetInput(void)
{
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_FIP_LM_Input->b_NaviPathPlausible = FIP_pt_ND_GetNaviData()->b_NaviPathPlausible;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#if (FCT_CFG_ROAD_INPUT)
  pt_FIP_LM_Input->pf_NoLaneProbLeft = &(ROAD_GET_NO_LANE_MATRIX_PROB_LEFT);
  pt_FIP_LM_Input->pf_NoLaneProbRight = &(ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT);
#endif /* END IF FCT_CFG_ROAD_INPUT */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_FIP_LM_Input->t_SIT.pt_SITCamLaneMarkerCrossed = SIT_pt_CamLaneMarkerCrossed();
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/ 
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_FIP_LM_Input->t_SIT.pt_SITLaneChangeCamPreMoveState = SIT_pt_LaneChangeCamPreMoveState();
#endif /*FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE*/ 
}

/*************************************************************************************************************************
  Functionname:    FIP_v_SetLaneMatrix                                                                              */ /*!

  @brief           Set the Lane Matrix based on different input sources

  @description     Set the Lane Matrix based on different input sources: EM road, NAVI, camera

  @startuml 
  Partition FIP_v_SetLaneMatrix
  Start
  	Note right: This function sets the Lane Matrix based on different input sources road, navigation and camera
  	If (Fusion of different sources switch is enabled) then (True)
  		- Initialize local EM,Navi and Camera variables to invalid
  	Else(False)
	  Endif

	  If (Road input data switch is enabled) then (True)
  		- Assign local EM road variable with Road information i.e number of lanes
  	Else (False)
  	Endif
	
  	- Write EM data to output as default value before fusion
	
  	If (Fusion of different sources switch is enabled \n AND \n Simple Navigation data input switch is enabled) then (True)
	  	If (NAVI country road feature is enabled using external switch) then (True)
	  		- Assign local Navigation variable with Navi information
	  	Else (False)
	  	Endif
	  Else (False)
	  Endif
	
  	If (Fusion of different sources switch is enabled \n AND \n Camera Lane data input switch is enabled) then (True)
	  	- Assign local Camera variable with Camera information
  	Else (False)
  	Endif
	
  	If (Fusion of different sources switch is enabled) then (True)
  		- Fusion of the three input sources for determining the FIP lane matrix: EM Road, Navigation and Camera
  	Endif

  	- Determine the filtered fused lane matrix

  	If (Camera Lane data input switch is enabled) then (True)
  		- Consider lane change and update Lane matrix information accordingly
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_LM_Output : Reference to Lane matrix output data structure which contains the information from EM Road, NAVI and camera based on the FCT input preprocessing
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype] 
  @glob_out        pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo : Variable to store debug information
                      s_FusedNumLaneLeftBeforeFilt : Fused (EM, NAVI, camera) number of lanes left before filtering [full range of datatype as defined in fip_lane_matrix_plg.c]
                      s_FusedNumLaneRightBeforeFilt : Fused (EM, NAVI, camera) number of lanes right before filtering [full range of datatype as defined in fip_lane_matrix_plg.c]
  @glob_out        pt_FIP_LM_Output : Reference to Lane matrix output data structure which contains the information from EM Road, NAVI and camera based on the FCT input preprocessing
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype]

  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of ALGO parameters to the FCT component. This should be enabled, if the SW environment provides this information
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_SIMU : Simulation specific compiler switch
  @c_switch_part   BSW_ALGOPARAMETERS_INTFVER: Check if navi path fusion is enabled using external switch
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         22.01.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetLaneMatrix(void)
{
  sint8 s_NumLaneLeftEM, s_NumLaneRightEM;    /*!< Number of lanes left/right based on EM Road */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
  sint8 s_NumLaneNavi;                        /*!< Number of lanes (left + right + ego) based on the NAVI data */
  sint8 s_NumLaneLeftCam, s_NumLaneRightCam;  /*!< Number of lanes left/right based on the camera */
  boolean b_MultipleInputData;                /*!< Info if different input sources are available */
#endif

  /*! Default values of local variables */
  s_NumLaneLeftEM = FIP_LM_INVALID_NUM_LANE;
  s_NumLaneRightEM = FIP_LM_INVALID_NUM_LANE;
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
  s_NumLaneNavi = FIP_LM_INVALID_NUM_LANE;
  s_NumLaneLeftCam = FIP_LM_INVALID_NUM_LANE;
  s_NumLaneRightCam = FIP_LM_INVALID_NUM_LANE;
  b_MultipleInputData = FALSE;
#endif

  /*! Set number of lanes based on EM Road */
#if (FCT_CFG_ROAD_INPUT)
  FIP_v_SetLaneMatrixEM(&s_NumLaneLeftEM, &s_NumLaneRightEM);
#endif /* FCT_CFG_ROAD_INPUT */

  /* Write EM data to output as default value before fusion */
  pt_FIP_LM_Output->s_NumOfLaneLeft = s_NumLaneLeftEM;
  pt_FIP_LM_Output->s_NumOfLaneRight = s_NumLaneRightEM;

  /*! Set number of lanes based on the NAVI */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_SIMPLE_NAVI_INTERFACE)
#if ((FCT_CFG_BSW_ALGO_PARAMS) && (BSW_ALGOPARAMETERS_INTFVER >= 16u))
  /*! Check if NAVI country road feature is enabled using external switch -> then the NAVI information is to be used */
  if((FCT_BSW_ALGO_PARAM_PTR->Fct.Acc.NaviFusionPreselBits & ACC_NAV_FUSION_SEL_COUNTRY_ROAD) != 0)
  {
    FIP_v_SetLaneMatrixNavi(&s_NumLaneNavi);
  }
#endif
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Set number of lanes based on the camera */
  FIP_v_SetLaneMatrixCam(&s_NumLaneLeftCam, &s_NumLaneRightCam);
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_FIP_LM_Output->s_CamNumLaneLeft = s_NumLaneLeftCam;
  pt_FIP_LM_Output->s_CamNumLaneRight = s_NumLaneRightCam;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
  /*! Fusion of the three input sources for determining the FIP lane matrix: EM Road, NAVI, camera */
  FIP_v_LaneMatrixFusion(&b_MultipleInputData, s_NumLaneLeftEM, s_NumLaneRightEM, s_NumLaneNavi, s_NumLaneLeftCam, s_NumLaneRightCam);
#ifdef FCT_SIMU
  /*! Set debug info */
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_FusedNumLaneLeftBeforeFilt = pt_FIP_LM_Output->s_NumOfLaneLeft;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_FusedNumLaneRightBeforeFilt = pt_FIP_LM_Output->s_NumOfLaneRight;
#endif

  /*! Determine the filtered fused lane matrix */
  FIP_v_LaneMatrixFiltering(b_MultipleInputData, s_NumLaneLeftEM, s_NumLaneRightEM, s_NumLaneNavi, s_NumLaneLeftCam, s_NumLaneRightCam);

#if (SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Consider an ego lane change in FIP lane matrix */
  FIP_v_LaneMatrixLaneChange();
#endif
#endif

#ifdef FCT_SIMU
  /*! Set debug info */
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_EMNumLaneLeft = s_NumLaneLeftEM;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_EMNumLaneRight = s_NumLaneRightEM;
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_NaviNumLane = s_NumLaneNavi;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_CamNumLaneLeft = s_NumLaneLeftCam;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_CamNumLaneRight = s_NumLaneRightCam;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.f_FusedNumLaneLeftFilt = FIPLaneMatrixGlobalData.f_FusedNumLaneLeftFilt;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.f_FusedNumLaneRightFilt = FIPLaneMatrixGlobalData.f_FusedNumLaneRightFilt;
#endif
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_FIPNumLaneLeft = pt_FIP_LM_Output->s_NumOfLaneLeft;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_FIPNumLaneRight = pt_FIP_LM_Output->s_NumOfLaneRight;
#endif
}


/*************************************************************************************************************************
  Functionname:    FIP_v_SetLaneWidthInfo                                                                           */ /*!

  @brief           Map Lane Width values from EM/Cam/NAVI to FIP Lane Width Values

  @description     Get road estimation values from EM/Cam/NAVI depending on availability.
                   If no road estimation data available from EM/Cam/NAVI then use default initialized values.
                   Currently no input from Cam/NAVI is fused and ONLY EM data is mapped to FIP
  
  @startuml 
  Partition FIP_v_SetLaneWidthInfo 
  Start
  	Note right: This function maps Lane Width values from EM/Camera/Navigation to FIP Lane Width Values
	  If (Road input data switch is enabled) then (True)	
	  	- Map FIP Road Lane Class with EM Road Lane Class
  				   
  	: TYPE OF ROAD LANEWIDTH SOURCE)|
  		split
  		:Source0>
	  		- Assigne FIP lane width source to Source0
	  	split again
	  	:Source1>
  			- Assigne FIP lane width source to Source1
	  	Split again
		  :default>
			  - Assigne FIP lane width source to Source0
		  end split

  	- Assign FIP lane width infromation from Road data
	  
	  Else (False)
		  - Assigne FIP lane width class to MORE UNKNOWN
		  - Assigne FIP lane width source to Source0
		  - Assign FIP lane width infromation to 0
	  Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         ROAD_GET_LANE_CLASS : Lane classification as received from EM 
  @glob_in         ROAD_GET_LANEWIDTH_SOURCE : Lane width source as received from EM
  @glob_in         ROAD_GET_LANEWIDTH : Lane width as received from EM
  @glob_out        pt_FIP_LM_Output : Reference to FIP Lane Matrix Output structure which covers the information of EM Road, NAVI and camera based on the FCT input preprocessing
                        f_FIPLaneWidth : Lane width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        t_FIPLaneWidthClass : Lane width classification [FIP_t_LaneWidthClass as defined in fip_ext.h]
                        t_FIPLaneWidthSource : Source for lane width [FIP_t_LaneWidthSource as defined in fip_ext.h]
  
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None
  @post            No Change

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.06.2016
  @changed         29.09.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
static void FIP_v_SetLaneWidthInfo(void)
{
#if (FCT_CFG_ROAD_INPUT)

  switch(ROAD_GET_LANE_CLASS)
  {
    case  LANE_WIDTH_CLASS_UNKNOWN:
      pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_UNKNOWN;
      break;

    case LANE_WIDTH_CLASS_NORMAL:
      pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_NORMAL;
      break;

    case LANE_WIDTH_CLASS_NARROW:
      pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_NARROW;
      break;

    case LANE_WIDTH_CLASS_MORE_NARROW:
      pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_MORE_NARROW;
      break;

    default:
      pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_UNKNOWN;
      break;
  }

   switch(ROAD_GET_LANEWIDTH_SOURCE)
  {
    case Source0:
      pt_FIP_LM_Output->t_FIPLaneWidthSource = FIP_SOURCE_0;
      break;

    case Source1:
      pt_FIP_LM_Output->t_FIPLaneWidthSource = FIP_SOURCE_1;
      break;

    default:
       pt_FIP_LM_Output->t_FIPLaneWidthSource = FIP_SOURCE_0;
       break;
  }

   pt_FIP_LM_Output->f_FIPLaneWidth = ROAD_GET_LANEWIDTH;

#else
  pt_FIP_LM_Output->t_FIPLaneWidthClass = FIP_LANE_WIDTH_CLASS_UNKNOWN;
  pt_FIP_LM_Output->f_FIPLaneWidth = 0.f;
  pt_FIP_LM_Output->t_FIPLaneWidthSource = FIP_SOURCE_0;
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

}

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
/*************************************************************************************************************************
  Functionname:    FIP_v_LaneMatrixFusion                                                                           */ /*!

  @brief           Fusion of the lane matrix information from the different input sources (EM road, NAVI, camera)

  @description     Fusion of the lane matrix information from the different input sources (EM road, NAVI, camera)
                   The input from NAVI, Camera and EM are pairwise evaluated and fused together to achieve a FCT wide valid Lane matrix
                   The constraints for the different inputs are - 
                   NAVI: If the NAVI data is plausible, the number of lanes can be trusted (but the NAVI cannot distinguish between left and right lanes) 
                   Camera: The camera is only good in detecting no adjacent lanes (continuous camera lane marker)
                   EM Road: If the EM Road data reports two valid lanes, more trust is placed in the lower number of lanes
  
  @startuml 
  Partition FIP_v_LaneMatrixFusion  
  Start
  	Note right: This function fuses the lane matrix from different input sources EM road, navigation and camera
	
	  If (Road input data switch is enabled) then (True)	
  		- Assign local variable with distance of road border Right and Left from ROAD data
  	Endif
	
  	If (Camera number of lanes Right or Left is invalid \n OR \n Navi number of lanes greater than zero) then (True)
  	- Set multiple input TRUE
  	Else (False)
  	Endif

	  If (Number of lanes from Navigation greater than zero ) then (True)
	  	If (Number of lanes from Navigation greater than ONE) then (True)
  			If (Camera Number of Lanes Left Equal to Zero \n AND \n Camera Number of Lanes Right Not Equal to Zero) then (True)
				     - Assign FIP LM Output Number of Lanes Left with Zero
				     - Set FIP LM Output Number of Lanes Right to NAVI number of lans subtracted by one
				    - Assign local variable data fused to TRUE
			  Else (False)
		  	If (Camera Number of Lanes Right Equal to Zero \n AND \n Camera Number of Lanes Left Not Equal to Zero) then (True)
	  			   - Assign FIP LM Output Number of Lanes Right with Zero
  				   - Set FIP LM Output Number of Lanes Left to NAVI number of lans subtracted by one
  				   - Assign local variable data fused to TRUE
	  		Else (False)
  			Endif
			  Endif
			  Else (False)
			  If (Camera Number of Lanes Left Equal to Zero \n AND \n Camera Number of Lanes Right Equal to Zero) then (True)
		  		   - Assign FIP LM Output Number of Lanes Left with Zero
		  		   - Assign FIP LM Output Number of Lanes Right with Zero
		  		   - Assign local variable data fused to TRUE
		  	Else (False)
		  	Endif
		  Endif
			
	  	If (Data Fused is FALSE) then (True)
	  		If((EM Left number of lanes Not equal to Invalid \n AND \n EM Right number of lanes equal to Invalid) \n OR \n (EM Left number of lanes Not equal to Invalid \n AND \n EM Right number of lanes Not equal to Invalid \n AND \n EM Left number of lanes less than \n EM Right number of lanes)) then (True)
	  			   - Assign FIP LM Output Number of Left Lanes with EM number of Left Lanes
	  			   - Assign FIP LM Output Number of Right Lanes with NAVI number of lans subtracted by EM number of lans right and one;
	  		Else (False)
	  		If((EM Right number of lanes Not equal to Invalid \n AND \n EM Left number of lanes equal to Invalid) \n OR \n (EM Left number of lanes Not equal to Invalid \n AND \n EM Right number of lanes Not equal to Invalid \n AND \n EM Right number of lanes less than \n EM Left number of lanes)) then (True)
	  			   - Assign FIP LM Output Number of Right Lanes with EM number of Right Lanes
	  			   - Assign FIP LM Output Number of Left Lanes \n with NAVI number of lanes subtracted by EM number of lans left and one
	  		Else (False)
	  			   :<color:Green> ! Nothing </color>;
	  		Endif
	  		Endif
	  		Else (Flase)
	  		Endif
	  	Else (False)
  		If ((EM number of lanes Left invalid \n AND \n Camera Number of Lanes Left greater than Zero) \n OR \n (Camera Number of Lanes Left Zero \n AND \n Left border less than Maximal road border distance for camera lane fusion)) then (True)
	  		- Set FIP LM Output number of lanes left to Camera Number of Lanes Left
  		Else (False)
  		Endif
		
		  If ((EM number of lanes Right invalid AND Camera Number of Lanes Right greater than Zero)OR (Camera Number of Lanes Right Zero AND Right border less than Maximal road border distance for camera lane fusion)) then (True)
	  		- Set FIP Lane Matrix Output number of lanes Right to Camera Number of Lanes Right
	  	Else (False)
		  endif
	  	endif
  Stop
  @enduml

  @return          -

  @param[in,out]   pb_MultipleInputData : Boolean indicating if different input sources available are [TRUE, FALSE]
  @param[in]       s_EMNumLaneLeft : Number of lanes left based on EM Road [full range of datatype sint8]
  @param[in]       s_EMNumLaneRight : Number of lanes right based on EM Road [full range of datatype sint8]
  @param[in]       s_NaviNumLane : Number of lanes (left + right + ego) based on the NAVI [full range of datatype sint8]
  @param[in]       s_CamNumLaneLeft : Number of lanes left based on the camera [full range of datatype sint8]
  @param[in]       s_CamNumLaneRight : Number of lanes right based on the camera [full range of datatype sint8]

  @glob_in         None 
  @glob_out        pt_FIP_LM_Output : Reference to FIP Lane Matrix Output structure
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype]
  @glob_out        pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo : Variable to store debug information
                      b_MultipleInputSourceAvailable : Info if different input sources are available [TRUE, FALSE]
                      b_InputDataFused : Info if input sources are fused [TRUE, FALSE]

  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_SIMU : Simulation specific compiler switch
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC


  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_LaneMatrixFusion(boolean * pb_MultipleInputData, const sint8 s_EMNumLaneLeft, const sint8 s_EMNumLaneRight,
                                const sint8 s_NaviNumLane, const sint8 s_CamNumLaneLeft, const sint8 s_CamNumLaneRight)
{
  boolean b_InputDataFused;
  
  /* Get distance to road border */
#if FCT_CFG_ROAD_INPUT  
  const float32 f_DistLeftRoadBorder = ROAD_GET_BORDER_LEFT;
  const float32 f_DistRightRoadBorder = ROAD_GET_BORDER_RIGHT;
#endif /* FCT_CFG_ROAD_INPUT */

  /*! Determine if different input sources available are */
  *pb_MultipleInputData = FALSE;
  if( (s_CamNumLaneLeft != FIP_LM_INVALID_NUM_LANE) || (s_CamNumLaneRight != FIP_LM_INVALID_NUM_LANE) || (s_NaviNumLane > 0) )
  {
    *pb_MultipleInputData = TRUE;
  }

  /*! General remarks for combing the different input sources:
      NAVI: If the NAVI data is plausible, the number of lanes can be trusted (but the NAVI cannot distinguish between left and right lanes) 
      Camera: The camera is only good in detecting no adjacent lanes (continuous camera lane marker)
      EM Road: If the EM Road data reports two valid lanes, more trust is placed in the lower number of lanes */
  b_InputDataFused = FALSE; /*!< Info if input data is fused */
  /*! If the NAVI reports a valid number of lanes */
  if(s_NaviNumLane > 0)
  {
    /*! Combine the information from the NAVI and the camera (camera information is only considered if it tells that there is no adjacent lane) */
    if (s_NaviNumLane > 1)
    {
      /*! If the NAVI reports more than one lane and if the camera reports at only one side no adjacent lane, combine the information */
      if( (s_CamNumLaneLeft == 0) && (s_CamNumLaneRight != 0) )
      {
        pt_FIP_LM_Output->s_NumOfLaneLeft = 0;
        pt_FIP_LM_Output->s_NumOfLaneRight = s_NaviNumLane - 1;
        b_InputDataFused = TRUE;
      }
      else if( (s_CamNumLaneRight == 0) && (s_CamNumLaneLeft != 0) )
      {
        pt_FIP_LM_Output->s_NumOfLaneRight = 0;
        pt_FIP_LM_Output->s_NumOfLaneLeft = s_NaviNumLane - 1;
        b_InputDataFused = TRUE;
      }
      else
      {
        /*! Nothing */
      }
    }
    else if( (s_CamNumLaneLeft == 0) && (s_CamNumLaneRight == 0) )
    {
      /*! If the NAVI and the camera both report only one lane, use this info */
      pt_FIP_LM_Output->s_NumOfLaneLeft = 0;
      pt_FIP_LM_Output->s_NumOfLaneRight = 0;
      b_InputDataFused = TRUE;
    }
    else
    {
      /*! Nothing */
    }

    /*! If NAVI and camera data is not fused, consider EM and NAVI data */
    if(b_InputDataFused == FALSE)
    {
      /*! If EM road data is invalid for only one lane, the NAVI data and the EM road data based on the valid EM road info is combined */
      /*! If EM road data is valid for both sides, more trust is placed in the lower number of lanes and the info from this side is combined with the NAVI info */
      if( ( (s_EMNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && 
            (s_EMNumLaneRight == FIP_LM_INVALID_NUM_LANE) 
          ) ||
          ( (s_EMNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && 
            (s_EMNumLaneRight != FIP_LM_INVALID_NUM_LANE) &&
            (s_EMNumLaneLeft < s_EMNumLaneRight)
          )
        )
      {
        pt_FIP_LM_Output->s_NumOfLaneLeft = s_EMNumLaneLeft;
        pt_FIP_LM_Output->s_NumOfLaneRight = MAX(0, (s_NaviNumLane - s_EMNumLaneLeft) - 1);
        b_InputDataFused = TRUE;
      }
      else if ( ( (s_EMNumLaneLeft == FIP_LM_INVALID_NUM_LANE) &&
                  (s_EMNumLaneRight != FIP_LM_INVALID_NUM_LANE)
                ) || 
                ( (s_EMNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && 
                  (s_EMNumLaneRight != FIP_LM_INVALID_NUM_LANE) &&
                  (s_EMNumLaneRight < s_EMNumLaneLeft)
                )
              )
      {
        pt_FIP_LM_Output->s_NumOfLaneRight = s_EMNumLaneRight;
        pt_FIP_LM_Output->s_NumOfLaneLeft = MAX(0, (s_NaviNumLane - s_EMNumLaneRight) - 1);
        b_InputDataFused = TRUE;
      }
      else
      {
        /*! Nothing */
      }
    }
  }
  else
  {
    /*! If the NAVI doesn't report a valid number of lanes, combine EM road data and camera data. 
        -These input sources are only combined, if the camera tell that there is no adjacent lane and EM reports no valid lane.
        -If the distance to the road border is lower than a threshold, use the camera data */
    if( ((s_EMNumLaneLeft == FIP_LM_INVALID_NUM_LANE) && (s_CamNumLaneLeft >= 0))
#if (FCT_CFG_ROAD_INPUT)
        || ((s_CamNumLaneLeft == 0) && ((f_DistLeftRoadBorder < FIP_LM_MAX_ROAD_BORDER_DIST_FOR_CAM_FUSION) || (ROAD_GET_BORDER_LEFT_STD > 3.0f) || (ROAD_GET_BORDER_STAT_LEFT < 100u)))
#endif /* FCT_CFG_ROAD_INPUT */
      )
    {
      pt_FIP_LM_Output->s_NumOfLaneLeft = s_CamNumLaneLeft;
      b_InputDataFused = TRUE; 
    }
    if( ((s_EMNumLaneRight == FIP_LM_INVALID_NUM_LANE) && (s_CamNumLaneRight >= 0))
#if (FCT_CFG_ROAD_INPUT)
        || ((s_CamNumLaneRight == 0) && ((f_DistRightRoadBorder > -FIP_LM_MAX_ROAD_BORDER_DIST_FOR_CAM_FUSION) || (ROAD_GET_BORDER_RIGHT_STD > 3.0f) || (ROAD_GET_BORDER_STAT_RIGHT < 100u)))
#endif /* FCT_CFG_ROAD_INPUT */
      )
    {
      pt_FIP_LM_Output->s_NumOfLaneRight = s_CamNumLaneRight;
      b_InputDataFused = TRUE; 
    }
  }

  /*! Set debug info*/
#ifdef FCT_SIMU
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.b_MultipleInputSourceAvailable = *pb_MultipleInputData;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.b_InputDataFused = b_InputDataFused;
#else
  _PARAM_UNUSED(b_InputDataFused);
#endif
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
/*************************************************************************************************************************
  Functionname:    FIP_v_LaneMatrixFiltering                                                                        */ /*!

  @brief           Filtering of the fused number of lanes information

  @description     Filtering of the fused number of lanes information

  @startuml 
  Partition FIP_v_LaneMatrixFiltering
  Start
  	Note right: This function filters the fused number of lanes information	
  	If (Fusion of different sources switch is enabled \n AND \n Camera Lane data input switch is enabled) then (True)
  		- Assign local variable with Camera lane mark crossed information
  	Else (False)
  		- Assign local variable with Unknown crossing of the camera lane marker
  	Endif	
  	
  	- Identify Lane information from different source is identical
  	- Filter the right and left lanes based on \n if lane information is identical, multiple lane information \n source available and lane data is fused
  	- Assign FIP Number of lanes based on Filtered Number of lanes
  Stop
  @enduml

  @return          -

  @param[in,out]   
  @param[in,out]   pb_MultipleInputData : Boolean indicating if different input sources available are [TRUE, FALSE]
  @param[in]       s_EMNumLaneLeft : Number of lanes left based on EM Road [full range of datatype sint8]
  @param[in]       s_EMNumLaneRight : Number of lanes right based on EM Road [full range of datatype sint8]
  @param[in]       s_NaviNumLane : Number of lanes (left + right + ego) based on the NAVI [full range of datatype sint8]
  @param[in]       s_CamNumLaneLeft : Number of lanes left based on the camera [full range of datatype sint8]
  @param[in]       s_CamNumLaneRight : Number of lanes right based on the camera [full range of datatype sint8]

  @glob_in         - 
  @glob_in         FIPLaneMatrixGlobalData : Structure to store global data for determining the FIP lane matrix
                      f_FusedNumLaneLeftFilt : Filtered fused (EM, NAVI, camera) number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_FusedNumLaneRightFilt : Filtered fused (EM, NAVI, camera) number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_LeftTimerUnknownCurrentNumLane : Timer for the unknown current number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_RightTimerUnknownCurrentNumLane : Timer for the unknown current number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_LeftTimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_RightTimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
  @glob_out        pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo : Variable to store debug information
                      b_MultipleInputSourceAvailable : Info if different input sources are available [TRUE, FALSE]
                      b_InputDataFused : Info if input sources are fused [TRUE, FALSE]
  @glob_out        pt_FIP_LM_Output : Reference to FIP Lane Matrix Output structure which covers the information of EM Road, NAVI and camera based on the FCT input preprocessing
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype]
  @glob_out        pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo : Variable to store debug information
                      CamLaneMarkerCrossed : Info if camera lane marker is crossed [t_SILCStateCamLaneMarkerCrossed as defined in si_ext.h]
                      b_IsInfoIdenticalLeft : Boolean if the input sources for the left number of lanes give the same info [TRUE, FALSE]
                      b_IsInfoIdenticalRight : Boolean if the input sources for the right number of lanes give the same info [TRUE, FALSE]
                      f_LeftTimerUnknownCurrentNumLane : Timer for the unknown current number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_RightTimerUnknownCurrentNumLane : Timer for the unknown current number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_LeftTimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes left [full range of datatype as defined in fip_lane_matrix_plg.c]
                      f_RightTimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes right [full range of datatype as defined in fip_lane_matrix_plg.c]

  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_SIMU : Simulation specific compiler switch
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         29.09.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_LaneMatrixFiltering(const boolean b_MultipleInputData, const sint8 s_EMNumLaneLeft, const sint8 s_EMNumLaneRight,
                                      const sint8 s_NaviNumLane, const sint8 s_CamNumLaneLeft, const sint8 s_CamNumLaneRight)
{
  boolean b_IsInfoIdenticalLeft, b_IsInfoIdenticalRight;  /*!< Boolean if the different input sources give the same information */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  SITLCStateCamLaneMarkerCrossed_t CamLaneMarkerCrossed;   /*!< Info if camera lane markers are crossed */

  /*! Check if the camera lane markers are crossed;
      Remark: CamLaneMarkerCrossed from last cycle due to invocation order (FIP before si_lanechange.c) */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  CamLaneMarkerCrossed = *(pt_FIP_LM_Input->t_SIT.pt_SITCamLaneMarkerCrossed);
#else
  CamLaneMarkerCrossed = UNKNOWN_CROSS_CAMLANE;
#endif /* END IF (SLATE_CFG_CAM_LANE_INTERFACE) */

#endif /* END IF (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE) */

  /*! Check if the different input sources give the same information -> then this information can be trusted */
  FIP_v_IsLMInfoIdentical(&b_IsInfoIdenticalLeft, &b_IsInfoIdenticalRight, pt_FIP_LM_Output->s_NumOfLaneLeft, pt_FIP_LM_Output->s_NumOfLaneRight, 
    s_EMNumLaneLeft, s_EMNumLaneRight, s_NaviNumLane, s_CamNumLaneLeft, s_CamNumLaneRight);

  /*! Filtering of the numbers of lanes left */
  FIP_v_LaneMatrixFilteringOneSide(&(FIPLaneMatrixGlobalData.f_FusedNumLaneLeftFilt), &(FIPLaneMatrixGlobalData.f_LeftTimerUnknownCurrentNumLane), 
    &(FIPLaneMatrixGlobalData.f_LeftTimerUnknownFiltNumLane), pt_FIP_LM_Output->s_NumOfLaneLeft, b_MultipleInputData, 
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
    CamLaneMarkerCrossed, 
#endif
    b_IsInfoIdenticalLeft);
  /*! Filtering of the numbers of lanes right */
  FIP_v_LaneMatrixFilteringOneSide(&(FIPLaneMatrixGlobalData.f_FusedNumLaneRightFilt), &(FIPLaneMatrixGlobalData.f_RightTimerUnknownCurrentNumLane), 
    &(FIPLaneMatrixGlobalData.f_RightTimerUnknownFiltNumLane), pt_FIP_LM_Output->s_NumOfLaneRight, b_MultipleInputData, 
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
    CamLaneMarkerCrossed, 
#endif
    b_IsInfoIdenticalRight);

  /*! Set number of lanes based on filtered number of lanes values */
  pt_FIP_LM_Output->s_NumOfLaneLeft = (sint8)ROUND_TO_INT(FIPLaneMatrixGlobalData.f_FusedNumLaneLeftFilt);
  pt_FIP_LM_Output->s_NumOfLaneRight = (sint8)ROUND_TO_INT(FIPLaneMatrixGlobalData.f_FusedNumLaneRightFilt);

#ifdef FCT_SIMU
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.CamLaneMarkerCrossed = CamLaneMarkerCrossed;
#endif
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.b_IsInfoIdenticalLeft = b_IsInfoIdenticalLeft;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.b_IsInfoIdenticalRight = b_IsInfoIdenticalRight;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.f_LeftTimerUnknownCurrentNumLane = FIPLaneMatrixGlobalData.f_LeftTimerUnknownCurrentNumLane;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.f_LeftTimerUnknownFiltNumLane = FIPLaneMatrixGlobalData.f_LeftTimerUnknownFiltNumLane;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.f_RightTimerUnknownCurrentNumLane = FIPLaneMatrixGlobalData.f_RightTimerUnknownCurrentNumLane;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.f_RightTimerUnknownFiltNumLane = FIPLaneMatrixGlobalData.f_RightTimerUnknownFiltNumLane;
#endif
}
#endif


#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
/*************************************************************************************************************************
  Functionname:    FIP_v_LaneMatrixFilteringOneSide                                                                 */ /*!

  @brief           Filtering of the fused number of lanes information for one side

  @description     Filtering of the fused number of lanes information for one side. Under certain conditions, 
                   the current number of lanes is directly set and the filtering is not performed.
                   Conditions under which the filtering is ignored and the filtered number of lanes value is directly set to the current number of lanes:
                   > The camera lane markers are crossed -> filtering would cause the number of lanes to be too "slow"
                   > Only EM road as input available (b_MultipleInputData == FALSE) -> no second filtering necessary, use EM number of lanes (default) directly
                   > The information from the different input sources give the same info -> info can be trusted and the "correct" number of lanes is set directly
                   > Invalid filtered number of lanes or the current number -> no filtering since a wrong value may occure by filtering, 
                     either leave the old value (hysteresis) or set the invalid value directly (filtering from e.g. 1 with the value -1 may result in the wrong number of lanes 0)
  
  @startuml 
  Partition FIP_v_LaneMatrixFilteringOneSide
  Start
  	Note right: This function filters fused number of lanes information for one side	
  	If (Camera lane mark crossed not equal to Unknown \n OR \n Multiple Input Data is False \n OR \n Is Information from all source identical is True \n OR \n Current Number of Lanes is Invalid \n OR \n Filtered number of Lanes is having almost Invalid Value) then (True)
  		If (Current Number of Lanes equal to Invalid \n AND \n Timer Unknown Current number of lane is less \n than threshold for Invalid lane matrix timer \n AND \n Multiple Input Data is True \n AND \n Information from all source identical is False) then (True)
	  		- Add Timer for Unknown Current Number of Lanes with SLATE cycle time
  		Else (False)
	  	If (Current Number of Lanes not equal to Invalid \n AND \n Filtered number of Lanes is having almost Invalid Value \n AND \n Timer Unknown Filtered number of lane \n is less than threshold for Invalid lane matrix timer \n AND \n Multiple Input Data is True \n AND \n Information from all source identical is False) then (True)
	  		- Add Timer for Unknown Filtered Number of Lanes with Slate cycle time 
	  	Else (False)
	  		- Set the filtered number of lanes to the current number of lanes 
	  	Endif
	  	Endif
	  Else (False)
	  	- Filter number of lanes 
	  Endif
				   
  	If (Current Number of Lane Not Equal to Invalid) then (True)
  		- Timer for Unknown Current Number of Lanes is zero
  	Endif
  	If (Filtered Number of Lane Not Equal to Invalid) then (True)
  		- Reset the Timer for Unknown filtered Number of Lanes
  	Endif
  Stop
  @enduml

  @return          -

  @param[in,out]   pf_NumLaneFilt : Filtered fused (EM, NAVI, camera) number of lanes [full range of datatype]
  @param[in,out]   pf_TimerUnknownCurrentNumLane : Timer for the unknown current number of lanes [full range of datatype]
  @param[in,out]   pf_TimerUnknownFiltNumLane : Timer for the unknown filtered number of lanes [full range of datatype]
  @param[in]       s_NumLaneCurrent : Fused number of lanes of the current cycle [full range of datatype]
  @param[in]       b_MultipleInputData : Info if input sources are fused [TRUE, FALSE]
  @param[in]       CamLaneMarkerCrossed : Info if camera lane marker is crossed [t_SILCStateCamLaneMarkerCrossed as defined in sit_ext.h]
  @param[in]       b_IsInfoIdentical : Boolean if the different input sources give the same information [TRUE, FALSE]

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_LaneMatrixFilteringOneSide(float32 * pf_NumLaneFilt, float32 * pf_TimerUnknownCurrentNumLane, float32 * pf_TimerUnknownFiltNumLane, 
                                             sint8 const s_NumLaneCurrent, boolean const b_MultipleInputData, 
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
                                             SITLCStateCamLaneMarkerCrossed_t const CamLaneMarkerCrossed, 
#endif
                                             boolean const b_IsInfoIdentical)
{
  sint8 s_RoundNumLaneFilt;

  /*! Conditions under which the filtering is ignored and the filtered number of lanes value is directly set to the current number of lanes:
        the camera lane markers are crossed -> filtering would cause the number of lanes to be too "slow"
        only EM road as input available (b_MultipleInputData == FALSE) -> no second filtering necessary, use EM number of lanes (default) directly
        the information from the different input sources give the same info -> info can be trusted and the "correct" number of lanes is set directly
        invalid filtered number of lanes or the current number -> no filtering since a wrong value may occure by filtering, 
              either leave the old value (hysteresis) or set the invalid value directly 
              (filtering from e.g. 1 with the value -1 may result in the wrong number of lanes 0) */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  if( (CamLaneMarkerCrossed != UNKNOWN_CROSS_CAMLANE) || 
#else
  if( 
#endif
      (b_MultipleInputData == FALSE) ||
      (b_IsInfoIdentical == TRUE) ||
      (s_NumLaneCurrent == FIP_LM_INVALID_NUM_LANE) || 
      (*pf_NumLaneFilt < ((float32)FIP_LM_INVALID_NUM_LANE + C_F32_DELTA) )
    )
  {
    /*! If the current number of lanes is invalid, change the filtered number of lanes to invalid after a hysteresis */
    if( ( s_NumLaneCurrent == FIP_LM_INVALID_NUM_LANE ) && 
        (*pf_TimerUnknownCurrentNumLane < FIP_LM_TIMER_INVAILD_CURRENT_NUM_LANE) && 
        (b_MultipleInputData == TRUE) &&
        (b_IsInfoIdentical == FALSE)
      )
    {
      *pf_TimerUnknownCurrentNumLane += SLATE_f_GetCycleTime();
    }
    else if( ( s_NumLaneCurrent != FIP_LM_INVALID_NUM_LANE ) && 
      (*pf_NumLaneFilt < ((float32)FIP_LM_INVALID_NUM_LANE + C_F32_DELTA)) && 
      (*pf_TimerUnknownFiltNumLane < FIP_LM_TIMER_INVAILD_FILT_NUM_LANE) &&
      (b_MultipleInputData == TRUE) &&
      (b_IsInfoIdentical == FALSE)
      )
    {
      /*! If only the filtered number of lanes is invalid, change the filtered number of lanes to the new value after a hysteresis */
      *pf_TimerUnknownFiltNumLane += SLATE_f_GetCycleTime();
    }
    else
    {
      /*! Set the filtered number of lanes to the current number of lanes directly */
      *pf_NumLaneFilt = (float32)s_NumLaneCurrent;
    }
  }
  else
  {
    /*! Filtering of the number of lanes */
    *pf_NumLaneFilt = GDB_FILTER((float32)s_NumLaneCurrent, *pf_NumLaneFilt, FIP_LM_FILTER_CONSTANT);
  }

  /*! Reset the timer for the unknown current number of lanes if the current number of lanes is valid */
  if(s_NumLaneCurrent != FIP_LM_INVALID_NUM_LANE)
  {
    *pf_TimerUnknownCurrentNumLane = 0.f;
  }
  
  /*! Reset the timer for the unknown number of filtered lanes if the current number of lanes is invalid or the filtered value is valid */
  s_RoundNumLaneFilt = (sint8)ROUND_TO_INT(*pf_NumLaneFilt);
  if( (s_NumLaneCurrent == (sint8)FIP_LM_INVALID_NUM_LANE) || (s_RoundNumLaneFilt > (sint8)FIP_LM_INVALID_NUM_LANE ) )
  {
    *pf_TimerUnknownFiltNumLane = 0.f;
  }
}
#endif


#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
/*************************************************************************************************************************
  Functionname:    FIP_v_IsLMInfoIdentical                                                                          */ /*!

  @brief           Check if the different input sources give the same information

  @description     Check if the different input sources (EM Road, NAVI, camera) give the same information 
                   The information is deemed trustworthy if it is reported from more than one source. This aspect is evaluated in this function.
  
  @startuml 
  Partition FIP_v_IsLMInfoIdentical
  Start
  	Note right: This function checks if the different input sources give the same information	
  	if((((EM number of Lanes Left is Invalid) \n OR \n (Camera number of Lanes Left is Invalid) \n OR \n 
    ( (EM number of Lanes Left is Camera number of Lanes Left) \n AND \n 
    (FIP Fused number of Lane Left Equal EM number of Lanes Left) ) ) \n AND \n 
    ((EM number of Lanes Left is Invalid) \n OR \n (EM number of Lanes Right is Invalid) \n OR \n 
    (NAVI number of Lanes is Invalid) \n OR \n ( (NAVI number of Lanes equal to total camera number of lanes) \n AND \n 
    (FIP Fused number of Lane Left Equal EM number of Lanes Left) \n AND \n (FIP Fused number of Lane Right Equal EM number of Lanes Right))) \n AND \n 
    ((Camera number of Lanes Left is Invalid) \n OR \n (Camera number of Lanes Right is Invalid) \n OR \n (NAVI number of Lanes is Invalid) \n OR \n 
    (NAVI number of Lanes  equal to total Camera number of lanes) \n AND \n (FIP Fused number of Lane Left Equal Camera number of Lanes Left) \n AND \n 
    (FIP Fused number of Lane Right Equal Camera number of Lanes Right))) \n AND \n (((EM number of Lanes Left Not Equal to Invalid) \n AND \n 
    (Camera number of Lanes Left Not Equal to Invalid)) \n OR \n ((EM number of Lanes Left Not Equal to Invalid) \n AND \n 
    (EM number of Lanes Right Not Equal to Invalid) \n AND \n (NAVI number of Lanes Not Equal to Invalid)) \n OR \n 
    ((Camera number of Lanes Left Not Equal to Invalid) \n AND \n (Camera number of Lanes Right Not Equal to Invalid) \n AND \n 
    (NAVI number of Lanes Not Equal to Invalid))))) then (True)
  		- Assign : Is identical Left to TRUE
  	Else (False)
	  Endif
	
	  If ((((EM number of Lanes Right is Invalid) \n OR \n  (Camera number of Lanes Right is Invalid) \n OR \n 
    ((EM number of Lanes Right is Camera number of Lanes Right) \n AND \n (FIP Fused number of Lane Right Equal EM number of Lanes Right))) \n AND \n 
    ((EM number of Lanes Left is Invalid) \n OR \n (EM number of Lanes Right is Invalid) \n OR \n (NAVI number of Lanes is Invalid) \n OR \n 
    ((NAVI number of Lanes equal to total camera number of lanes)) \n AND \n (FIP Fused number of Lane Left Equal EM number of Lanes Left) \n AND \n 
    (FIP Fused number of Lane Right Equal EM number of Lanes Right))) \n AND \n ((Camera number of Lanes Left is Invalid) \n OR \n 
    (Camera number of Lanes Right is Invalid) \n OR \n (NAVI number of Lanes is Invalid) \n OR \n 
    (NAVI number of Lanes  equal to total Camera number of lanes) \n AND \n (FIP Fused number of Lane Left Equal Camera number of Lanes Left) \n AND \n 
    (FIP Fused number of Lane Right Equal Camera number of Lanes Right))) \n AND \n (((EM number of Lanes Right Not Equal to Invalid) \n AND \n
    (Camera number of Lanes Right Not Equal to Invalid)) \n OR \n ((EM number of Lanes Left Not Equal to Invalid) \n AND \n 
    (EM number of Lanes Right Not Equal to Invalid) \n AND \n (NAVI number of Lanes Not Equal to Invalid)) \n OR \n 
    ((Camera number of Lanes Left Not Equal to Invalid) \n AND \n (Camera number of Lanes Right Not Equal to Invalid) \n AND \n 
    (NAVI number of Lanes Not Equal to Invalid))))) then (True)
	  	- Assign : Is identical Right to TRUE
	  Else (False)
    Endif
  Stop
  @enduml

  @return          -

  @param[in,out]   pb_InfoIsIdenticalLeft : Boolean if the different input sources give the same information for left lanes [TRUE, FALSE]
  @param[in,out]   pb_InfoIsIdenticalRight : Boolean if the different input sources give the same information for right lanes [TRUE, FALSE]
  @param[in]       s_NumLaneLeft : Number of lanes on the left [full range of datatype]
  @param[in]       s_NumLaneRight : Number of lanes on the left [full range of datatype]
  @param[in]       s_EMNumLaneLeft : Number of lanes left based on EM Road [full range of datatype sint8]
  @param[in]       s_EMNumLaneRight : Number of lanes right based on EM Road [full range of datatype sint8]
  @param[in]       s_NaviNumLane : Number of lanes (left + right + ego) based on the NAVI [full range of datatype sint8]
  @param[in]       s_CamNumLaneLeft : Number of lanes left based on the camera [full range of datatype sint8]
  @param[in]       s_CamNumLaneRight : Number of lanes right based on the camera [full range of datatype sint8]

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_IsLMInfoIdentical(boolean * pb_InfoIsIdenticalLeft, boolean * pb_InfoIsIdenticalRight, 
                                 const sint8 s_NumLaneLeft, const sint8 s_NumLaneRight, const sint8 s_EMNumLaneLeft, const sint8 s_EMNumLaneRight, 
                                 const sint8 s_NaviNumLane, const sint8 s_CamNumLaneLeft, const sint8 s_CamNumLaneRight)
{
  /*! Set default: Different input sources give not the same information */
  *pb_InfoIsIdenticalLeft = FALSE;
  *pb_InfoIsIdenticalRight = FALSE;

  /*! Check if the different input sources give the same information -> then this information can be trusted */
  if( ( (s_EMNumLaneLeft == FIP_LM_INVALID_NUM_LANE) || (s_CamNumLaneLeft == FIP_LM_INVALID_NUM_LANE) || 
        ( (s_EMNumLaneLeft == s_CamNumLaneLeft) && (s_NumLaneLeft == s_EMNumLaneLeft) ) 
      ) && /*!< EM Road left and camera left identical + EM Road left and fused lane identical */
      ( (s_EMNumLaneLeft == FIP_LM_INVALID_NUM_LANE) || (s_EMNumLaneRight == FIP_LM_INVALID_NUM_LANE) || (s_NaviNumLane == FIP_LM_INVALID_NUM_LANE) || 
        ( (s_NaviNumLane == (s_EMNumLaneLeft + s_EMNumLaneRight + 1)) && (s_NumLaneLeft == s_EMNumLaneLeft) && (s_NumLaneRight == s_EMNumLaneRight) )
      ) && /*!< NAVI and EM Road identical + EM Road and fused lane identical */
      ( (s_CamNumLaneLeft == FIP_LM_INVALID_NUM_LANE) || (s_CamNumLaneRight == FIP_LM_INVALID_NUM_LANE) || (s_NaviNumLane == FIP_LM_INVALID_NUM_LANE) || 
        ( (s_NaviNumLane == (s_CamNumLaneLeft + s_CamNumLaneRight + 1)) && (s_NumLaneLeft == s_CamNumLaneLeft) && (s_NumLaneRight == s_CamNumLaneRight) )
      ) && /*!< NAVI and camera identical + Camera and fused lane identical */
      ( ( (s_EMNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && (s_CamNumLaneLeft != FIP_LM_INVALID_NUM_LANE) ) ||
        ( (s_EMNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && (s_EMNumLaneRight != FIP_LM_INVALID_NUM_LANE) && (s_NaviNumLane != FIP_LM_INVALID_NUM_LANE) ) ||
        ( (s_CamNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && (s_CamNumLaneRight != FIP_LM_INVALID_NUM_LANE) && (s_NaviNumLane != FIP_LM_INVALID_NUM_LANE) )
      ) /*!< Ensure that at least one of the three conditions above is fulfilled based on valid data */
    )
  {
    *pb_InfoIsIdenticalLeft = TRUE;
  }

  if( ( (s_EMNumLaneRight == FIP_LM_INVALID_NUM_LANE) || (s_CamNumLaneRight == FIP_LM_INVALID_NUM_LANE) || 
        ( (s_EMNumLaneRight == s_CamNumLaneRight) && (s_NumLaneRight == s_EMNumLaneRight) ) 
      ) && /*!< EM Road right and camera right identical + EM Road right and fused lane identical */
      ( (s_EMNumLaneLeft == FIP_LM_INVALID_NUM_LANE) || (s_EMNumLaneRight == FIP_LM_INVALID_NUM_LANE) || (s_NaviNumLane == FIP_LM_INVALID_NUM_LANE) || 
        ( (s_NaviNumLane == (s_EMNumLaneLeft + s_EMNumLaneRight + 1)) && (s_NumLaneLeft == s_EMNumLaneLeft) && (s_NumLaneRight == s_EMNumLaneRight) ) 
      ) && /*!< NAVI and EM Road identical + EM Road and fused lane identical */
      ( (s_CamNumLaneLeft == FIP_LM_INVALID_NUM_LANE) || (s_CamNumLaneRight == FIP_LM_INVALID_NUM_LANE) || (s_NaviNumLane == FIP_LM_INVALID_NUM_LANE) || 
        ( (s_NaviNumLane == (s_CamNumLaneLeft + s_CamNumLaneRight + 1)) && (s_NumLaneLeft == s_CamNumLaneLeft) && (s_NumLaneRight == s_CamNumLaneRight)) 
      ) && /*!< NAVI and camera identical + Camera and fused lane identical */
      ( ( (s_EMNumLaneRight != FIP_LM_INVALID_NUM_LANE) && (s_CamNumLaneRight != FIP_LM_INVALID_NUM_LANE) ) ||
        ( (s_EMNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && (s_EMNumLaneRight != FIP_LM_INVALID_NUM_LANE) && (s_NaviNumLane != FIP_LM_INVALID_NUM_LANE) )||
        ( (s_CamNumLaneLeft != FIP_LM_INVALID_NUM_LANE) && (s_CamNumLaneRight != FIP_LM_INVALID_NUM_LANE) && (s_NaviNumLane != FIP_LM_INVALID_NUM_LANE) )
      ) /*!< Ensure that at least one of the three conditions above is fulfilled based on valid data */
    )
  {
    *pb_InfoIsIdenticalRight = TRUE;
  }
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_LaneMatrixLaneChange                                                                       */ /*!

  @brief           Consider an ego lane change and update the lane matrix

  @description     Consider an ego lane change and update the lane matrix. The starting point for this function is the filtered lane matrix, 
                   thereafter ego lane change is taken into consideration before finalizing the LaneMatrix.
  
  @startuml 
  Partition FIP_v_LaneMatrixLaneChange
  Start
	  Note right: This function considers an ego lane change and update the lane matrix	
	  - Get the lane change direction
	
	  If (Direction is Left) then (True)
  		- Decrease the left number of lane and increase the right number of lane
  	Else (False)
  	If (Direction is right) then (YES)
  		- Decrease the right number of lane and increase the left number of lane
  	Else (False)
  		- No lane change
  	Endif
  	Endif
	
	  - Assign total number of lane with Invalid.;
	
  	If (Number of lanes left and right are greater than Invalid(-1)) then (True)
  		- Set Total number of lanes with Number of Lanes Left + Number of Lanes Right + 1
  	Else (False)
  	Endif
  		- Assign temporary number of lanes left and right variable with Invalid

  	If (Number of lanes left not equal to Invalid) then (True)
  		- Set Temporary number of lanes left under consideration of the lane change
  	Else (False)
	  Endif

  	If (Number of lanes right not equal to Invalid) then (True)
  		- Set Temporary number of lanes right under consideration of the lane change
  	Else (False)
	  Endif				   

	  If ((Number of left and right lanes is not equal to Invalid \n AND \n Total number of lanes is equal to sum of left and right lanes + 1) \n OR \n (Number of left lane is Invalid) \n AND \n (Number of right lane is not Invalid) \n OR \n (Number of left lane is not Invalid) \n AND \n (Number of right lane is Invalid)) then (True)
		  If (Number of lanes left not equal to Invalid) then (True)
		  	- Assign FIP output number of lane left with Temporary number of lanes left
		  Else (False)
		  Endif
	  	If (Number of lanes right not equals to Invalid) then (YES)
	  		- Assign FIP output number of lane right with Temporary number of lanes right
	  	Else (False)
  		Endif
  	Else (False)
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_LM_Output : Reference to the sub module output
                      s_NumOfLaneLeft : Number of lanes on the left [-1 ... Maximum range of datatype]
                      s_NumOfLaneRight : Number of lanes on the right [-1 ... Maximum range of datatype]
  @glob_out        pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo : Variable to store debug information
                      s_FusedNumLaneLeftBeforeLC : Fused number of lanes left before considering a lane change [full range of datatype as defined in fip_lane_matrix_plg.c]
                      s_FusedNumLaneRightBeforeLC : Fused number of lanes right before considering a lane change [full range of datatype as defined in fip_lane_matrix_plg.c]

  @c_switch_part   FCT_SIMU : Simulation specific compiler switch
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_LaneMatrixLaneChange(void) 
{
  sint8 s_ChangeLeftLaneLC, s_ChangeRightLaneLC, s_NumLane, s_NumLeftLaneTemp, s_NumRightLaneTemp;
  SITLaneChangeCamPreMove_t t_LaneChangeMovePreState;

  /*! Get the lane change direction. Remark: Information from last cycle */
  t_LaneChangeMovePreState = *(pt_FIP_LM_Input->t_SIT.pt_SITLaneChangeCamPreMoveState);

  /*! In case of a lane change adapt the number of lanes in advance */
  if(t_LaneChangeMovePreState == LANE_CHANGE_CAM_PRE_MOVE_LEFT)
  {
    s_ChangeLeftLaneLC = -1;  /*!< Lane change left: Decrease the left number of lanes by one */
    s_ChangeRightLaneLC = 1;  /*!< Lane change left: Increase the right number of lanes by one */
  }
  else if(t_LaneChangeMovePreState == LANE_CHANGE_CAM_PRE_MOVE_RIGHT)
  {
    s_ChangeLeftLaneLC = 1;   /*!< Lane change right: Increase the left number of lanes by one */
    s_ChangeRightLaneLC = -1; /*!< Lane change right: Decrease the right number of lanes by one */
  }
  else
  {
    /*! No lane change: No adaption of number of lanes */
    s_ChangeLeftLaneLC = 0; 
    s_ChangeRightLaneLC = 0;
  }

#ifdef FCT_SIMU
  /*! Set debug info */
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_FusedNumLaneLeftBeforeLC = pt_FIP_LM_Output->s_NumOfLaneLeft;
  pt_FIP_LM_Output->t_FIPLaneMatrixDebugInfo.s_FusedNumLaneRightBeforeLC = pt_FIP_LM_Output->s_NumOfLaneRight;
#endif


  /*! Change the number of lanes based on the ego lane change only if the number of lanes is not invalid. 
      Further, the total number of lanes must not be changed by the lane change consideration */

  /*! First, get the total number of lanes based on the filtered number of lanes for the left and right side 
      -> can only be determined if the number of lanes is available for both sides */
  s_NumLane = FIP_LM_INVALID_NUM_LANE;
  if( (pt_FIP_LM_Output->s_NumOfLaneLeft > FIP_LM_INVALID_NUM_LANE) && ( pt_FIP_LM_Output->s_NumOfLaneRight > FIP_LM_INVALID_NUM_LANE) )
  {
    s_NumLane = pt_FIP_LM_Output->s_NumOfLaneLeft + pt_FIP_LM_Output->s_NumOfLaneRight + 1;
  }
  /*! Second, determine the number of lanes under consideration of the lane change (only if the number of lanes is valid)*/
  s_NumLeftLaneTemp = FIP_LM_INVALID_NUM_LANE;
  s_NumRightLaneTemp = FIP_LM_INVALID_NUM_LANE;
  if(pt_FIP_LM_Output->s_NumOfLaneLeft != FIP_LM_INVALID_NUM_LANE) 
  {
    s_NumLeftLaneTemp = MAX(0, pt_FIP_LM_Output->s_NumOfLaneLeft + s_ChangeLeftLaneLC);
  }
  if(pt_FIP_LM_Output->s_NumOfLaneRight != FIP_LM_INVALID_NUM_LANE) 
  {
    s_NumRightLaneTemp = MAX(0, pt_FIP_LM_Output->s_NumOfLaneRight + s_ChangeRightLaneLC);
  }

  /*! Third, set the output value, only if the total number of lanes doesn't change by the lane change consideration.
      If the total number of lanes (s_NumLane) cannot be determined due to one invalid number of lane for one side, 
      set the new number of lane under consideration of the lane change only for the valid side. */
  if( ( (s_NumLeftLaneTemp > FIP_LM_INVALID_NUM_LANE) && 
        (s_NumRightLaneTemp > FIP_LM_INVALID_NUM_LANE) &&
        ((s_NumLeftLaneTemp + s_NumRightLaneTemp + 1) == s_NumLane)
      ) ||
      ( (pt_FIP_LM_Output->s_NumOfLaneLeft == FIP_LM_INVALID_NUM_LANE) &&
        (pt_FIP_LM_Output->s_NumOfLaneRight != FIP_LM_INVALID_NUM_LANE) 
      ) ||
      ( (pt_FIP_LM_Output->s_NumOfLaneLeft != FIP_LM_INVALID_NUM_LANE) &&
        (pt_FIP_LM_Output->s_NumOfLaneRight == FIP_LM_INVALID_NUM_LANE) 
      )
    )
  {
    if(pt_FIP_LM_Output->s_NumOfLaneLeft != FIP_LM_INVALID_NUM_LANE)
    {
      pt_FIP_LM_Output->s_NumOfLaneLeft = s_NumLeftLaneTemp;
    }
    if(pt_FIP_LM_Output->s_NumOfLaneRight != FIP_LM_INVALID_NUM_LANE)
    {
      pt_FIP_LM_Output->s_NumOfLaneRight = s_NumRightLaneTemp;
    }
  }
}
#endif

#if (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetLaneMatrixEM                                                                            */ /*!

  @brief           Set the lane matrix based on EM Road

  @description     Set the lane matrix based on EM Road

  @startuml 
  Partition FIP_v_SetLaneMatrixEM
  Start
  	Note right: This function sets the lane matrix based on EM Road	
  	- Assign Road lane matrix information
  Stop
  @enduml

  @return          -

  @param[in,out]   ps_NumLaneLeft : Number of lanes left based on EM Road [full range of datatype]
  @param[in,out]   ps_NumLaneRight : Number of lanes right based on EM Road [full range of datatype]

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_full   FCT_CFG_ROAD_INPUT : Road estimation input to FCT

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetLaneMatrixEM(sint8 * ps_NumLaneLeft, sint8 * ps_NumLaneRight)
{
  /*! Set values for the left and right side */
  *ps_NumLaneLeft = ROAD_GET_LANE_NO_LEFT;
  *ps_NumLaneRight = ROAD_GET_LANE_NO_RIGHT;
}

#endif /* FCT_CFG_ROAD_INPUT */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_SIMPLE_NAVI_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetLaneMatrixNavi                                                                          */ /*!

  @brief           Set the lane matrix based on the NAVI data

  @description     Set the lane matrix based on the NAVI data

  @startuml 
  Partition FIP_v_SetLaneMatrixNavi
  Start
  	Note right: This function sets the lane matrix based on the Navigation data	
  	If (Navigation data plausible is true) then (True)
  		- Assign local variable for number of Navigation lanes form Navigation data
  	Else (False)
  	Endif
  Stop
  @enduml

  @return          -

  @param[in,out]   ps_NumLane : Number of lanes (left + right + ego) based on the NAVI [full range of datatype sint8]

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetLaneMatrixNavi(sint8 * ps_NumLane)
{
  /*! Get info if NAVI data plausible */
  const boolean b_NaviDataPlausible = pt_FIP_LM_Input->b_NaviPathPlausible;

  /*! Set default value */
  *ps_NumLane = FIP_LM_INVALID_NUM_LANE;

  if(b_NaviDataPlausible == TRUE)
  {
    /*! Get the number of lanes reported by the NAVI. The NAVI cannot distinguish between the number of lanes left and right. */
    *ps_NumLane = 0; /* Set value to zero due to function declaration type of ps_NumLane */
    FIPGetNaviNumLaneAtDist((uint8*)ps_NumLane, 0.f);
  }
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetLaneMatrixCam                                                                           */ /*!

  @brief           Set the lane matrix based on the camera data

  @description     Set the lane matrix based on the camera data

  @startuml 
  Partition FIP_v_SetLaneMatrixCam
  Start
	  Note right: This function sets the lane matrix based on the Camera data
  	If (Visiblity distance is greter than zero) then (True)
  		- Process the Camera data and set the number of lanes for left and right side
  	Else (False)
  	Endif
  Stop
  @enduml

  @return          -

  @param[in,out]   ps_NumLaneLeft : Number of lanes left based on the camera data [full range of datatype]
  @param[in,out]   ps_NumLaneRight : Number of lanes right based on the camera data [full range of datatype]

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetLaneMatrixCam(sint8 * ps_NumLaneLeft, sint8 * ps_NumLaneRight)
{
  float32 const f_CamLaneVisibilityDist= (FIP_pt_CL_GetCamLaneData()->f_VisibilityDist);/*!< Visibility distance of camera lane */

  /*! Set default values */
  *ps_NumLaneLeft = FIP_LM_INVALID_NUM_LANE;
  *ps_NumLaneRight = FIP_LM_INVALID_NUM_LANE;

  /*! Consider camera information only if visibility higher than a threshold */
  if(f_CamLaneVisibilityDist > C_F32_DELTA)
  {
    /*! Set the number of lanes for the left side */
    FIP_v_SetLaneMatrixCamOneSide(ps_NumLaneLeft, FIP_CL_MK_LEFT, FIP_CL_MK_ADJ_LEFT);
    /*! Set the number of lanes for the right side */
    FIP_v_SetLaneMatrixCamOneSide(ps_NumLaneRight, FIP_CL_MK_RIGHT, FIP_CL_MK_ADJ_RIGHT);


  }
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetLaneMatrixCamOneSide                                                                    */ /*!

  @brief           Set the number of lanes based on the camera for one side

  @description     Set the number of lanes based on the camera for one side. The number of lanes reported by the camera can only be trusted 
                   if it equals zero -> Only the value zero is set or unknown/invalid
  
  @startuml 
  Partition FIP_v_SetLaneMatrixCamOneSide
  Start
  	Note right: This function sets the number of lanes based on the camera for one side	   
  	If (Camera Lane Is Road Edge True) Then (True)
  		- Assign Number of lanes to zero
  	Else (False)
  	if (Direct Lane Mark Existence Probability \n greater than or equal to Threshold \n AND \n Adjacent Lane Mark Existence Probability \n greater than or equal to Threshold \n AND \n All signal status are OK) then (True)
  		:Direct Lane Marker Type|
  		split
  		:Left Mark>
	  		- Set Lane Width subtracting Distance to the Adjacent Lane \n mark from Distance to the Direct Lane Mark
	  	split again
  		:Right Mark>
  			- Set Lane Width subtracting Distance to the Direct Lane \n mark from Distance to the Adjacent Lane Mark
	  	end split
  		If (Lane Width greater than Zero \n AND \n Less than Adjacent Camera Lane Width) then (Yes)
  			- Assign Number of lanes zero.;
  		elseif (Lane Width greater than or equal to Minimum camera lane width \n and \n less than Maximum road border distance for camera fusion and Camera lane marker type is Dashed type marker \n and \n Fused Road type is Highway) then (Yes)
                -Assign Number of Lanes One;
        Else (False)
          - Nothing
	  	Endif
  	Endif
  	Endif
  Stop  
  @enduml


  @return          -

  @param[in,out]   ps_NumLane : Number of lanes for one side based on the camera data [full range of datatype]
  @param[in]       DirectLaneMarker : Describes the direct lane marker for one side [t_CamLaneMarkerEnum as defined in Rte_Type.h]
  @param[in]       AdjLaneMarker : Describes the adjacent lane marker for one side [t_CamLaneMarkerEnum as defined in Rte_Type.h]

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Configuration switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         01.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_SetLaneMatrixCamOneSide(sint8 * ps_NumLane, t_CamLaneMarkerEnum const DirectLaneMarker, t_CamLaneMarkerEnum const AdjLaneMarker)
{
  float32 fLaneWidthAdj;
  boolean const b_CamLaneIsRoadEdge = (FIP_pt_CL_GetCamLaneData()->b_CamLaneIsRoadEdge[DirectLaneMarker]);/*!< Info if direct camera lane is road edge */
  FIP_t_FusedRoadType pt_FusedRoadType = FIP_pt_RT_GetRoadType()->t_FIPFusedRoadType;

  /*! Remark: The number of lanes reported by the camera can only be trusted if it equals zero -> Only the value zero is set or unknown/invalid */
  /*! Set the number of lanes to zeros for a continuous line */
  if(b_CamLaneIsRoadEdge == TRUE)
  {
    (*ps_NumLane) = 0;
  }
  else if (    (pSLATE_CamLaneData->LaneMarkerInfo[DirectLaneMarker].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) 
            && (pSLATE_CamLaneData->LaneMarkerInfo[AdjLaneMarker].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) 
            && (pSLATE_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) 
          )
  {
    /*! Determine the lane width of the adjacent lane */
    switch (DirectLaneMarker)
    {
    case FIP_CL_MK_LEFT:
      fLaneWidthAdj = pSLATE_CamLaneData->LaneMarkerInfo[AdjLaneMarker].f_MarkerDist - 
        pSLATE_CamLaneData->LaneMarkerInfo[DirectLaneMarker].f_MarkerDist;
      break;
    case FIP_CL_MK_RIGHT:
      fLaneWidthAdj = pSLATE_CamLaneData->LaneMarkerInfo[DirectLaneMarker].f_MarkerDist - 
        pSLATE_CamLaneData->LaneMarkerInfo[AdjLaneMarker].f_MarkerDist;
      break;
    default:
      fLaneWidthAdj = FIP_LM_DEFAULT_CAM_LANE_WIDTH; /*!< Invalid lane width value */
      break;
    }

    /*! If the lane width of the adjacent lane is smaller than a threshold consider it as no adjacent lane on this side */
    if( (fLaneWidthAdj > 0.f) && (fLaneWidthAdj < FIP_LM_MIN_ADJ_CAM_LANE_WIDTH))
    {
      (*ps_NumLane) = 0;
    }
    else if(   (fLaneWidthAdj >= FIP_LM_MIN_ADJ_CAM_LANE_WIDTH) 
            && (fLaneWidthAdj < FIP_LM_MAX_ROAD_BORDER_DIST_FOR_CAM_FUSION)
            && (pSLATE_CamLaneData->LaneMarkerInfo[DirectLaneMarker].MarkerType == CL_MARKER_TYPE_DASHED)
            && (pt_FusedRoadType == FIP_ROAD_TYPE_HIGHWAY)
            )
    {
      (*ps_NumLane) = 1;
    }
    else
    {
        /* Do Nothing */
    }
  }
  else
  {
    /*! Nothing */
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    FIP_v_InitGlobalLaneMatrixData                                                                   */ /*!

  @brief           Initialization of the global data for determining the FIP lane matrix

  @description     Initialization of the global data for determining the FIP lane matrix

  @startuml 
  Partition FIP_v_InitGlobalLaneMatrixData
  Start
  	Note right: This function initializes global data for determining the FIP lane matrix
	  - Depending on the available sources initialize persistent \n and non-persistent data in FIP Lane Matrix
  Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_LM_InputGlobal : Reference to FIP Lane Matrix input structure that is instantiated in Frame module
  @param[in]       pt_FIP_LM_OutputGlobal : Reference to FIP Lane Matrix output structure that is instantiated in Frame module

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2013
  @changed         20.10.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_InitGlobalLaneMatrixData(FIP_LM_InputConst_t * pt_FIP_LM_InputGlobal, FIP_LM_Output_t * pt_FIP_LM_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_LM_Input = pt_FIP_LM_InputGlobal;
  pt_FIP_LM_Output = pt_FIP_LM_OutputGlobal;

  /* Initialize persistent data in FIP Lane Matrix */
  FIP_v_LM_InitPersistentData();

  /* Initialize non-persistent data in FIP Lane Matrix */
  FIP_v_LM_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_LM_Input = NULL;
  pt_FIP_LM_Output = NULL;
}


/*************************************************************************************************************************
  Functionname:    FIP_v_LMSetMeasData                                                                              */ /*!

  @brief           Fill out Meas Freeze structure in LM sub-module

  @description     Fill out Meas Freeze structure in LM sub-module. Since Meas Freeze structures are visible only in FIP main,
                   this function is called from generic freeze function in FIP Main.
  
  @startuml 
  Partition FIP_v_LMSetMeasData
  Start
  	Note right: This function fills out Meas Freeze structure in Lane matrix sub-module	
  	- Freeze the Lane Width, Number of Lanes Left and Right for Measurement structure
  Stop
  @enduml

  @return          -

  @param[out]      pt_LMDebugMeasFreeze : Reference to LM freeze part in FIP freeze structure
  @param[in]       pt_FIP_LM_OutputLocal : Reference of LM output in FIP output structure

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC

  @pre             FIP_v_LaneMatrixProcess() 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.12.2016
  @changed         19.12.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_LMSetMeasData(FIPLM_DeviceMeasInfo_t * pt_LMDebugMeasFreeze, FIP_LM_Output_t const * pt_FIP_LM_OutputLocal)
{
  pt_LMDebugMeasFreeze->f_FIPLaneWidth = pt_FIP_LM_OutputLocal->f_FIPLaneWidth;
  pt_LMDebugMeasFreeze->s_NumOfLaneLeft = pt_FIP_LM_OutputLocal->s_NumOfLaneLeft;
  pt_LMDebugMeasFreeze->s_NumOfLaneRight = pt_FIP_LM_OutputLocal->s_NumOfLaneRight;
}
///@}
#endif /*!< FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
