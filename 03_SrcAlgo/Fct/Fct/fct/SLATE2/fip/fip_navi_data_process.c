/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_navi_data_process.c

DESCRIPTION:               ACC FCT processing of Navi Data

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             21.08.2014

VERSION:                   $Revision: 1.26 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

// PRQA S 7013 STTLN_EXCEEDED
/* date: 2016-02-04, reviewer: Yvonne Strigel, reason: Number of lines exceeded per file, not safety critical */

#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip_navi_data_plg
@{ */


#ifdef FCT_SIMU
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#endif  /* FCT_SIMU */

#if (FCT_CFG_INPUT_PREPROCESSSING)
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
#if (FIP_EVAL_ROAD_JUNCTION)
#define FIP_NAVI_BRANCH_MAX_SEGMENT_ANGLE       (150.f)   /* maximum angle between exit segments [deg]
                                                            this value shall be always < 180 [deg]*/
#define INVALID_DISTANCE_TO_JUNCTION      (-1.f)          /*Distance to junction when navi path data is not of ADAS
                                                            quality or when no junction found in navi path */
#define DISTANCE_TO_ROAD_JUNCTION_ACTIVE  (60.f)          /*Distance from where junction detection flag is set to JUNCTION_WITHOUT_PRIORITY */
#endif

#if SLATE_CFG_NAVI_OBJ_LAT_DIST
#define FIP_MAX_NUM_NAVI_SEG               (8u)           /* Maximum number of Navi Segments */
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*! Information for FIP navi meas freeze */
static boolean b_ValidNaviDataMeas = FALSE;
static boolean b_ValidNumLanesMeas = FALSE;

/*!< Structure containing global NAVI path data (need to be available beyond one cycle) */
static FIPGlobalNaviInfo_t FIPGlobalNaviInfo;

/*!< Evaluated NAVI data which is used in cp_trajectory.c*/
static FIPNaviDataEvaluated_t FIPNaviDataEvaluated;

#if FIP_EVAL_SHAPE_POINTS
/*!< This is the main set of shape points in NAVI reference coordinates. This is used to compute shape points in EGO reference */
static FIPNaviReferenceShapePoint_t FIPShapePointsInNaviRef;
/*!< Accumulated EGO motion in current NAVI tree, relative to current origin in NAVI ref (SP0) */
static FIPNaviCummulativeEgoMotion_t FIPNaviEgoTreeCumul;    /* Used to update transformation matrix on each cycle */
/*!< Accumulated EGO motion in shape point buffer, relative to next new origin (usually SP3) */
static FIPNaviCummulativeEgoMotion_t FIPNaviEgoBufferCumul;  /* Used to update transformation matrix and FIPNaviEgoTreeCumul when NAVI origin is moved */
/*!< Accumulated EGO motion in current segment relative to beginning of the segment */
static FIPNaviCummulativeEgoMotion_t FIPNaviEgoSegmentCumul; /* Used to update FIPNaviEgoBufferCumul when NAVI origin is moved*/
#endif

#ifdef FCT_SIMU
static NaviDataSIM_t NaviDataPlot;
#endif /*!< FCT_SIMU */

#if ((FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON))
#ifdef FCT_SIMU
static boolean b_UseInterfaceWithoutSegmentID;
#endif /* FCT_SIMU */
#endif /* END IF ((FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON)) */

/*! Definition of local pointer to FIP_NAVI output structure for access within this sub-module */
SET_MEMSEC_VAR(pt_FIP_ND_Output)
FIP_ND_Output_t * pt_FIP_ND_Output;

/*! Definition of local pointer to FIP_NAVI input structure for access within this sub-module */
SET_MEMSEC_VAR(pt_FIP_ND_Input)
FIP_ND_InputConst_t * pt_FIP_ND_Input;
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_ND_InitEveryCycle(void);
static void FIP_v_ND_SetInput(void);

#if FIP_EVAL_SHAPE_POINTS
static void FIP_v_NaviInitInfoEgoSegment(FIPNaviEgoSegmentInfo_t * p_InfoEgoSegment);
static void FIP_v_NaviInitTrafoMatrix2D(GDBTrafoMatrix2D_t * p_TrafoMatrix);
#endif

#if (FIP_EVAL_SHAPE_POINTS)
static void FIPInitNaviRefShapePointData(FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef);
static void FIPInitShapePointsInEgoRef(FIPNaviShapePointEgo_t* pFIPShapePointsInEgoRef);
static void FIP_v_InitEgoCumulStructure(FIPNaviCummulativeEgoMotion_t* pFIPNaviEgoXCumul);
static void FIP_b_AdaptNaviShapePointData(const t_NaviInputData * pNaviInputData, const boolean b_NewSegment, boolean* pb_NewSegmentF, GDBTrafoMatrix2D_t * p_CON2COG_Matrix);
static void FIPShiftSPOriginInNaviRef(GDBTrafoMatrix2D_t * p_CON2COG_Matrix);
static void FIPSamplePosNaviPath(const FIPNaviShapePointEgo_t * p_NaviShapePoint, SLATE_t_PosSamples *pNaviPathPosSamples);
static void FIPFindPosSamplesInNaviPathShapePoint(SLATE_t_PosSamples *p_Samples, const FIPNaviShapePointEgo_t * p_NaviShapePoint);
static void FIP_v_NaviProcessNewTree(const t_NaviInputData * p_FCTSEN_pNaviData, GDBTrafoMatrix2D_t * p_CON2COG_Matrix, boolean b_ResetTree);
#else
static void FIPSamplePosNaviPath(const t_NaviInputData *p_NaviData, SLATE_t_PosSamples *pNaviPathPosSamples);
static void FIPFindPosSamplesInNaviPath(SLATE_t_PosSamples *pSamples, const t_NaviInputData *p_NaviData, const uint8 uiMaxNumSamples);
#endif
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
static float32 f_FIP_NaviSegmentStartX[FIP_MAX_NUM_NAVI_SEG];
static float32 f_FIP_NaviSegmentStartY[FIP_MAX_NUM_NAVI_SEG];
static float32 f_FIP_NaviAccumPrevSegAngle[FIP_MAX_NUM_NAVI_SEG];
static void FIP_v_LateralDistToNaviTraj(ObjNumber_t t_ObjNr);
#endif /*end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
static void FIPInitEvalNaviData(void);

#if FIP_EVAL_SHAPE_POINTS
#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
static void FIPInitNaviData(t_NaviInputData * pNaviData);
#else
#ifdef FCT_SIMU
static void FIPInitNaviData(t_NaviInputData * pNaviData);
#endif
#endif
#endif /* FIP_EVAL_SHAPE_POINTS */

static void FIPApproxNaviPath(const SLATE_t_PosSamples *pPosSamples);
static void FIPPropNaviPathBasedOnApprox(void);

#if FIP_EVAL_SHAPE_POINTS
static void FIPNaviUpdateCON2COG(GDBTrafoMatrix2D_t* pFIPNavi_CON2COG);
static void FIPGeneralPropNaviPath(const FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef, const FIPNaviShapePointEgo_t* pFIPShapePointsInEgoRef, const t_NaviInputData *p_NaviData);
#else
static void FIPGeneralPropNaviPath(const t_NaviInputData *p_NaviData);
#endif
static boolean FIP_b_NaviPathMapPlausible(const t_NaviInputData *p_NaviData, const boolean b_ValidNaviData);
static void FIP_v_SetNaviPathIsValid(boolean b_NaviDataValid);
#if (FIP_EVAL_ROAD_JUNCTION)
static float32 FIP_f_DistanceToNextRoadJunction(void);
#endif
/*************************************************************************************************************************
  Functionname:    FIP_v_ND_PreProcess                                                                              */ /*!

  @brief           Preprocess and set inputs for ND sub module

  @description     Preprocess and set inputs for ND sub module

  @startuml 
  Partition FIP_v_ND_PreProcess
  Start
  	Note right: This function preprocesses inputs to Navigation Data (ND) sub module
	  - Depending on the available sources set the inputs to Navigation Data sub module
  Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_ND_InputGlobal : Reference to input structure for ND sub module instantiated in Frame

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.10.2016
  @changed         24.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_ND_PreProcess(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal)
{
  /* Assign local pointers */
  pt_FIP_ND_Input = pt_FIP_ND_InputGlobal;

  /* Set inputs */
  FIP_v_ND_SetInput();

  /* Reset local pointers */
  pt_FIP_ND_Input = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIPNaviDataProcess                                                                               */ /*!

  @brief           FCT Navi Data Preprocessing Main

  @description     FCT Navi Data Preprocessing Main
                   - validity and plausibility are checked
                   - entry of ego vehicle to new segment is checked due to different sampling rates of radar and navi (optional)
                   - compensation of navi path based on ego movement (ego compensation) (optional)
                   - determine general properties of navi path which are accessed from other parts of the code, e.g. length of navi 
                     path, street type...
                   - cubic spline interpolation as basis for position samples (optional)
                   - determination of position samples either based on cubic spline or directly from navi input information
                   - polynom  approximation of navi path based on position samples for later determination of navi path properties
                   - determine properties of navi path based on the polynom approximation which are accessed from other parts of 
                     the code, e.g. difference between navi path and ego curve
  
  @startuml 
  Partition FIPNaviDataProcess
  Start
	  Note right: This function processes FCT Navigation Data
	  If(Navigation path is valid) then (True)
  		- Evaluate if the Navigation Path is plausible
  		- Determine if the ego vehicle enters a new segment of the NAVI path \n or new tree shall be created
  		If (New tree shall be created \n OR \n MppNew is True) then (True)
  			- Build new tree based on incoming Navi data
  			- Make forced new segment bit false
  		Else (False)
  		Endif
		
  		- Update Navi to Ego reference co-ordinates transformation matrix
  		- Check if EGO has entered a new segment using EGO motion information
  		- Adapt the Shape Points in navigation reference based \n on new segment information. The shape point buffer is updated \n and the ego segment is updated
  		- Determine if Navigation reference shape point data are valid
  		
		If(Difference between ego position \n and navigation path is more than \n threshold for maximum difference \n between EGO path estimated NAVI path) then (True)
  			- Reset navi tree
			- New tree has to be built based on incoming NAVI data
  		Else (False)
  		Endif

  		If (Shape point buffer is overflowing) then (True)
  			- Shift origin in navigation tree
  		Else (False)
  		Endif
  
		If (Navigation path is plausible AND tree is valid) then (True)
  			- Compute shape points in EGO reference coordinates
  			- Determine general properties of the navigation  path
  			- Determine the cubic splines based on the shape points
  			- Determine the sample points of the navigation  path
  			- Approximate the navigation path by a second order polynomial
  			If(Driving path and navi path is different) then (True)
  				- Make navi path not plausible
  			Else (False)
  			Endif
			- Determine properties of the NAVI path based on approximation

			If (Distance to road junction calculation switch is enabled) then (True)
				If (Is Navigation path ADAS Quality True) then (True)
  					- Calculate Distance to the next road junction
					If (Distance to the next road junction \n is less than or  equal to Distance from where \n junction detection flag is set to active \n AND \n Distance to the next road junction \n is greater than or eual to zero) then (True)
						- No information about Road junction
					Else (False)
						- Keep the junction information from MPP
					Endif
				Else (False)
					- Calculate distance to the next road junction when navigation path is not having ADAS quality
				Endif
			Else (False)
			Endif
  		Else (False)
  			- Initialise Navigation evaluted data
  		Endif
  	Else (False)
  		- Initialize persistent data in FIP Navigation Data \n sub module containing global navigation path data
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_ND_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_ND_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         pSLATE_NaviData : NAVI input data
                     Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
                        u_SegmentID : Segment ID [0...FCT_NAV_NUM_SEG[
                        b_MppNew                                                      [TRUE, FALSE]
  @glob_in         FIPGlobalNaviInfo : Structure containing global NAVI path data (need to be available beyond one cycle
                      NaviEGOSegment : reference to information about ego segment
                       b_ForcedNewSegment : Boolean indicating if the current segment was forced [TRUE, FALSE]
                      NaviPathValidPosSamples : Position samples of NAVI path, which indicate the future course
                      f_YOffsetEgoCompAtOrigLastCycle                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        FIPGlobalNaviInfo : Structure containing global NAVI path data (need to be available beyond one cycle
                      NaviDataSegmentChange : last cycle input data
                      au_SegmentIDSegmentChange : Segment IDs of the navi path when entering a new segment [0...FCT_NAV_NUM_SEG[
                      NaviEGOSegment : reference to information about ego segment
                      f_YOffsetEgoCompAtOrigLastCycle                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      NaviPathValidPosSamples : Position samples of NAVI path, which indicate the future course
                        fx : x-Position [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        fy : y-Position [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        nb_samples : Number of samples [0u ... CAL_MAX_NB_TRAJ_SAMPLES[
                      MotionParams_LastCycle : Vehicle motion parameters for last cycle
  @glob_out         NaviDataPlot : 
                      fPosXApprox : x-position approximation [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fPosYApprox : y-position approximation [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      fXPosShapeAll                                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fYPosShapeAll                                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      uiNumPoints : Number of samples [0u ... CAL_MAX_NB_TRAJ_SAMPLES[
                      NaviPathApprox : aproximated NAVI path by a second order polynom
                      uiNumShapePoints : Number of shape points in EGO reference coordinate system [0u ... FIP_NUM_NAVI_PATH_SHAPE_POINTS[
                      NaviInputData : Reference to incoming NAVI data
                        Segments[i] with i in [0u ... FIP_NAVI_MAXSEG_FORDATAVALIDITY[ and FIP_NAVI_MAXSEG_FORDATAVALIDITY in fip_par.h
  @glob_out         FIP_ND_Output_t : 
                      b_NaviPathPlausible                                             [TRUE, FALSE]

  @c_switch_part   FIP_NAV_USE_SEG_ID : Switch to enable usage of segment ID
  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_part   FCT_SIMU FCT simulation enabling switch
  @c_switch_part   FASTSIM simulation specific function switch
  @c_switch_part   FIP_CFG_PREPROCESS_NAVI_INPUT_FOR_FUSION FIP specific config switch for preprocessing of incoming NAVI data for use in path fusion activities
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC                 
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             FIP_v_ND_PreProcess(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         02.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIPNaviDataProcess(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal, FIP_ND_Output_t * pt_FIP_ND_OutputGlobal)
{
  /*! Declare and initialize local variables */
  boolean b_ValidNaviData = FALSE;
  ObjNumber_t t_ObjNr;
  uint8 u_NumLaneObj;
#if FIP_EVAL_SHAPE_POINTS
  boolean b_NewSegment = FALSE;
  boolean b_NewSegmentF= FALSE;
  boolean b_NewTree = FALSE;
  boolean b_ResetTree = FALSE;
  boolean b_DrivingDifferentFromNaviPath = FALSE;

  GDBTrafoMatrix2D_t t_CON2COG_Matrix;  /*!< Transformation matrix from NAVI reference coordinates to EGO reference coordinates */

  /*!< This is the set of shape points in EGO coordinate system are computed every cycle and used for trajectory fusion */
  FIPNaviShapePointEgo_t FIPShapePointsInEgoRef;
#endif
#if ((FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON))
#ifdef FCT_SIMU
  /* Following variables be removed when no old data need to be simulated anymore */
  uint8 u_NumSegmentIDZero = 0u;
  uint8 i;

  for(i = 0u; i < (uint8)FCT_NAV_NUM_SEG; i++)
  {
    if(pSLATE_NaviData->Segments[i].u_SegmentID == 0u)
    {
      u_NumSegmentIDZero++;
    }
  }

  b_UseInterfaceWithoutSegmentID = FALSE;
  if(u_NumSegmentIDZero == FCT_NAV_NUM_SEG)
  {
    b_UseInterfaceWithoutSegmentID = TRUE;
  }
#endif
#endif
  /* Assign local pointers */
  pt_FIP_ND_Input = pt_FIP_ND_InputGlobal;
  pt_FIP_ND_Output = pt_FIP_ND_OutputGlobal;

  /*! Initialize input-output structures for this component */
  FIP_v_ND_InitEveryCycle();
  
#ifdef FCT_SIMU
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.b_NewTreeYDiff = FALSE;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.b_ShiftOrigin = FALSE;
#endif
  /*! Initialize navi FIP meas freeze data */
  b_ValidNaviDataMeas = FALSE;
  b_ValidNumLanesMeas = FALSE;

#if FIP_EVAL_SHAPE_POINTS
  /*! Initialize local structure */
  FIP_v_NaviInitTrafoMatrix2D(&t_CON2COG_Matrix); // ego compensation
  FIPInitShapePointsInEgoRef(&FIPShapePointsInEgoRef);
#endif

  /*! Determine if NAVI path is valid: MAP Quality is acceptable,
                                       Number of lanes exceeds zero and 
                                       Street type valid for each segment */
  b_ValidNaviData = FIPCalcNaviDataValid(pSLATE_NaviData);

  FIP_v_SetNaviPathIsValid(b_ValidNaviData);

  if(b_ValidNaviData == TRUE)
  {
    /*! The NAVI path is plausible, if the map is plausible and if the ego vehicle doesn't drive different from the NAVI path. 
        If the ego vehicle drives different from the NAVI path can only be determined later 
        (see FIP_b_DrivingDifferentFromNaviPath())*/
    pt_FIP_ND_Output->b_NaviPathPlausible = FIP_b_NaviPathMapPlausible(pSLATE_NaviData, b_ValidNaviData);

    for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
    {
      FIPGetNaviNumLaneAtDist(&u_NumLaneObj, OBJ_LONG_DISPLACEMENT(t_ObjNr));
      pt_FIP_ND_Output->t_ObjList[t_ObjNr].u_NumLane = u_NumLaneObj;
    }
#if(FCT_CFG_CUSTOM_PASSING_STATE)
    pt_FIP_ND_Output->b_OvertakeLaneIsExitLane = FIP_b_OvertakeLaneIsExitLane();
#endif /*!< FCT_CFG_CUSTOM_PASSING_STATE */

    /* FIP specific config switch for preprocessing of incoming NAVI data for use in path fusion activities */
#if (FIP_CFG_PREPROCESS_NAVI_INPUT_FOR_FUSION)

#if FIP_EVAL_SHAPE_POINTS
    /*! Determine if the ego vehicle enters a new segment of the NAVI path: Consider this only if NAVI data is valid */
#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
    FIP_v_CheckNewTreeOrSegment(&(FIPGlobalNaviInfo.NaviDataSegmentChange), pSLATE_NaviData, &b_NewSegment, &b_NewTree);
#else
#ifdef FCT_SIMU
    if(b_UseInterfaceWithoutSegmentID == TRUE)
    {
      FIP_v_CheckNewTreeOrSegment(&(FIPGlobalNaviInfo.NaviDataSegmentChange), pSLATE_NaviData, &b_NewSegment, &b_NewTree);
    }
    else
    {
      FIP_v_CheckNewTreeOrSegmentWithSegID(FIPGlobalNaviInfo.au_SegmentIDSegmentChange, pSLATE_NaviData, &b_NewSegment, &b_NewTree);
    }
#else
    FIP_v_CheckNewTreeOrSegmentWithSegID(FIPGlobalNaviInfo.au_SegmentIDSegmentChange, pSLATE_NaviData, &b_NewSegment, &b_NewTree);
#endif  /* FCT_SIMU */
#endif /* IF ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF)) */
    
    if ( (pSLATE_NaviData->b_MppNew == TRUE) || (b_NewTree == TRUE) )
    {
      /* New tree has to be built based on incoming NAVI data */
      FIP_v_NaviProcessNewTree(pSLATE_NaviData, &t_CON2COG_Matrix, b_ResetTree);  // ego compensation
      FIPGlobalNaviInfo.NaviEGOSegment.b_ForcedNewSegment = FALSE;    /* In case this was set, it needs to be reset since new tree has been built */ // ego compensation
    }

    /* Update CON2COG transformation matrix */
    FIPNaviUpdateCON2COG(&t_CON2COG_Matrix); // ego compensation

    /* Check if Segment is forced */
    FIPCheckNaviSegmentForced(&(FIPGlobalNaviInfo.NaviEGOSegment), &b_NewSegmentF, &FIPShapePointsInNaviRef, &t_CON2COG_Matrix); // ego compensation

    /*! Adapt the NAVI reference shape points based on new segment information */
    FIP_b_AdaptNaviShapePointData(pSLATE_NaviData, b_NewSegment, &b_NewSegmentF, &t_CON2COG_Matrix); // ego compensation

    /*! Determine if FIPShapePointsInNaviRef contains valid data */
    FIPShapePointsInNaviRef.b_TreeValid = FIP_b_SetTreeValidShapePointsInNaviRef(&FIPShapePointsInNaviRef); // ego compensation

    /* Check average EGO path difference and current difference and determine if a reset is required */ // ego compensation
    if (fABS(FIPGlobalNaviInfo.f_YOffsetEgoCompAtOrigLastCycle) > FIP_NAVI_MAX_YCOMP_AT_ORIG)//(FIPShapePointsInNaviRef.f_AvgEGOPathDiff > FIP_NAVI_MAX_EGO_DIFF_AVG)
    {
      b_ResetTree = TRUE;
      /* New tree has to be built based on incoming NAVI data */
      FIP_v_NaviProcessNewTree(pSLATE_NaviData, &t_CON2COG_Matrix, b_ResetTree);
      FIPGlobalNaviInfo.NaviEGOSegment.b_ForcedNewSegment = FALSE;    /* In case this was set, it needs to be reset since new tree has been built */
#ifdef FCT_SIMU
      pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.b_NewTreeYDiff = TRUE;
#endif
    }
    /*! Monitor shape point buffer overflow, and build a new tree if required */
    /* Shape point buffer runs from 0-14, if IndexCurrentBuffer is 14 then it is time to reset the buffer (build a new tree) */
    if (FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer > ((FCT_NAV_NUM_SEG + FIP_NUM_HIST_SHAPE_POINTS + FIP_NUM_HIST_SHAPE_POINTS_BUFFER) - 1)) // ego compensation
    {
      FIPShiftSPOriginInNaviRef(&t_CON2COG_Matrix); // ego compensation
#ifdef FCT_SIMU
      pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.b_ShiftOrigin = TRUE;
#endif
    }

    /*! Process NAVI data only if NAVI path data are plausible */
    if( (pt_FIP_ND_Output->b_NaviPathPlausible == TRUE) && (FIPShapePointsInNaviRef.b_TreeValid == TRUE) )
    {
      /* Compute shape points in EGO reference coordinates */
      FIPGetEgoRefShapePoints(&FIPShapePointsInNaviRef, &t_CON2COG_Matrix, &FIPShapePointsInEgoRef, b_NewSegment, b_NewSegmentF); // ego compensation
#else /* !FIP_EVAL_SHAPE_POINTS */
    if(pt_FIP_ND_Output->b_NaviPathPlausible == TRUE)
    {
#endif /* IF FIP_EVAL_SHAPE_POINTS */

#if (FIP_EVAL_SHAPE_POINTS)
      /*! Determine general properties of the NAVI path */
      FIPGeneralPropNaviPath(&FIPShapePointsInNaviRef, &FIPShapePointsInEgoRef, pSLATE_NaviData);
#else
      FIPGeneralPropNaviPath(pSLATE_NaviData);
#endif

#if FIP_EVAL_SHAPE_POINTS
      /*! Determine the cubic splines based on the shape points -> used for generation of sample points between shape points */
      FIPGetCubicSplineBasedOnShapePoints(&FIPShapePointsInEgoRef);
#endif

      /*! Determine the sample points of the NAVI path */
#if (FIP_EVAL_SHAPE_POINTS)
      FIPSamplePosNaviPath(&FIPShapePointsInEgoRef, &(FIPGlobalNaviInfo.NaviPathValidPosSamples));
#else
      FIPSamplePosNaviPath(pSLATE_NaviData, &(FIPGlobalNaviInfo.NaviPathValidPosSamples));
#endif
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
/* calculate NUmber of lanes at object position and calculate Lateral Distance between Object and relevant position on Navi trajectory */
    for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
    {
      FIP_v_LateralDistToNaviTraj(t_ObjNr);
    }
#endif /* endof SLATE_CFG_NAVI_OBJ_LAT_DIST */

      /*! Approximation of the NAVI path by a second order polynom (f(x) = fC0 + fC1*x + fC2*x^2) */
      /*! Check if this is necessary if shape points are used!!!! since spline interpolation already done */
      FIPApproxNaviPath(&(FIPGlobalNaviInfo.NaviPathValidPosSamples)); /* no functional consequences anymore -> disabled in cp_fusion_navi.c */

#if (FIP_EVAL_SHAPE_POINTS)
      /*! The NAVI path is implausible, if the map is plausible and if the ego vehicle doesn't drive different from the NAVI path */
      /* CHECK f_AvgEGOPathDiff  */
      b_DrivingDifferentFromNaviPath = FIP_b_DrivingDifferentFromNaviPath(&(FIPShapePointsInNaviRef));
      if(b_DrivingDifferentFromNaviPath == TRUE)
      {
        pt_FIP_ND_Output->b_NaviPathPlausible = FALSE;
      }
#endif

      FIPPropNaviPathBasedOnApprox(); /* no functional consequences anymore -> disabled in cp_fusion_navi.c */
#if (FIP_EVAL_ROAD_JUNCTION)
      if(pt_FIP_ND_Output->b_NaviPathIsADASQuality != FALSE)
      {
        /*distance to the next road junction */
        pt_FIP_ND_Output->f_Dist2Junction = FIP_f_DistanceToNextRoadJunction();

        /*Update the information about the detection of road junction*/
        if((pt_FIP_ND_Output->f_Dist2Junction <= DISTANCE_TO_ROAD_JUNCTION_ACTIVE) && (pt_FIP_ND_Output->f_Dist2Junction >= 0.f))
        {
          /*No information about Road junction*/
          pt_FIP_ND_Output->e_JunctionDetection = JUNCTION_WITHOUT_PRIORITY;
        }
        else
        {
          /*Keep the junction information from MPP */ 
          pt_FIP_ND_Output->e_JunctionDetection = NO_JUCTION;
        }

      }else
      {
        /*distance to the next road junction when navi path is not having ADAS quality*/
        pt_FIP_ND_Output->f_Dist2Junction = INVALID_DISTANCE_TO_JUNCTION;
        pt_FIP_ND_Output->e_JunctionDetection = NO_JUCTION;
      }
#endif      

    } /* END IF( (pt_FIP_ND_Output->b_NaviPathPlausible == TRUE) && (FIPShapePointsInNaviRef.b_TreeValid == TRUE) ) */
    else
    {
      FIPInitEvalNaviData();
    }
#else
  /* Unused local variables generate a warning, which are treated as error in some projects, so suppress them */
  _PARAM_UNUSED(b_NewSegmentF);
  _PARAM_UNUSED(b_ResetTree);
#endif  /* FIP_CFG_PREPROCESS_NAVI_INPUT_FOR_FUSION */ 
  }else
  {
    /* Incoming data is not valid - Reset everything and wait for valid data */
    //FIPInitGlobalNaviData();
    FIP_v_ND_InitPersistentData();
  }

#if FIP_EVAL_SHAPE_POINTS
  /*! Set global parameters for next cycle -> motion parameters for next cycle */
  FIP_v_NaviSetLastCycleMotionParams(&FIPGlobalNaviInfo.MotionParams_LastCycle);
  FIPGlobalNaviInfo.f_YOffsetEgoCompAtOrigLastCycle = pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig;
#endif

  /*! Set navi FIP meas freeze data: valid navi data bit */
  b_ValidNaviDataMeas = b_ValidNaviData;

#if defined FCT_SIMU && !defined FASTSIM /* This code shall not be executed in the FASTSIM context */
#if FIP_EVAL_SHAPE_POINTS
  /*! Write debug data */
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.CON2COG_Matrix = t_CON2COG_Matrix;
  (void)memcpy(&(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.NaviEGOSegment), &(FIPGlobalNaviInfo.NaviEGOSegment), sizeof(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.NaviEGOSegment));

  (void)memcpy(&(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.FIPShapePointsInEgoRef), &(FIPShapePointsInEgoRef), sizeof(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.FIPShapePointsInEgoRef));

  (void)memcpy(&(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.CON2COG_Matrix), &(t_CON2COG_Matrix), sizeof(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.CON2COG_Matrix));
  (void)memcpy(&(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.FIPShapePointsInNaviRef), &(FIPShapePointsInNaviRef), sizeof(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.FIPShapePointsInNaviRef));

  (void)memcpy(&(pt_FIP_ND_Output->t_SIMNaviData.fXPosShapeAll), &(FIPShapePointsInEgoRef.af_XPosShapePointEgoRef), sizeof(pt_FIP_ND_Output->t_SIMNaviData.fXPosShapeAll));
  (void)memcpy(&(pt_FIP_ND_Output->t_SIMNaviData.fYPosShapeAll), &(FIPShapePointsInEgoRef.af_YPosShapePointEgoRef), sizeof(pt_FIP_ND_Output->t_SIMNaviData.fYPosShapeAll));
#endif /*!< FIP_EVAL_SHAPE_POINTS */
  (void)memcpy(&(pt_FIP_ND_Output->t_SIMNaviData.fPosXApprox), &(FIPGlobalNaviInfo.NaviPathValidPosSamples.fx), sizeof(pt_FIP_ND_Output->t_SIMNaviData.fPosXApprox));
  (void)memcpy(&(pt_FIP_ND_Output->t_SIMNaviData.fPosYApprox), &(FIPGlobalNaviInfo.NaviPathValidPosSamples.fy), sizeof(pt_FIP_ND_Output->t_SIMNaviData.fPosYApprox));

  (void)memcpy(&(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.NaviSamples.fx), &(FIPGlobalNaviInfo.NaviPathValidPosSamples.fx), sizeof(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.NaviSamples.fx));
  (void)memcpy(&(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.NaviSamples.fy), &(FIPGlobalNaviInfo.NaviPathValidPosSamples.fy), sizeof(pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.NaviSamples.fy));

  pt_FIP_ND_Output->t_SIMNaviData.uiNumPoints = FIPGlobalNaviInfo.NaviPathValidPosSamples.nb_samples;
#if FIP_EVAL_SHAPE_POINTS
  pt_FIP_ND_Output->t_SIMNaviData.NaviPathApprox = FIPNaviDataEvaluated.PolyNaviPathL2;
  pt_FIP_ND_Output->t_SIMNaviData.uiNumShapePoints = FIPShapePointsInEgoRef.ui_NumberOfShapePoints;
#endif

  //NaviDataPlot.NaviInputData = (*pSLATE_NaviData);
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData = (*pSLATE_NaviData);



  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.PlausiBits.b_ValidNaviData = b_ValidNaviData;
#if FIP_EVAL_SHAPE_POINTS
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.PlausiBits.b_DrivingDifferentFromNaviPath = b_DrivingDifferentFromNaviPath;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.b_NewSegment = b_NewSegment;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.b_NewTree = b_NewTree;
#endif
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.bNaviPathPlausible = pt_FIP_ND_Output->b_NaviPathPlausible;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.PlausiBits.b_QualityNavData = pt_FIP_ND_Output->b_NaviPathIsADASQuality;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.fSumLengthNaviPath = FIPNaviDataEvaluated.f_SumLengthNaviPath;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.fNaviPathToPolySumSqDistAvg =  FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.fEgoNaviPathErrDistAvg = pt_FIP_ND_Output->f_EgoNaviPathErrDistAvg;
#if FIP_EVAL_SHAPE_POINTS
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.f_YOffsetEgoCompAtOrig = pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.f_DiffAngleToFistShapePoint = FIPNaviDataEvaluated.f_DiffAngleToFistShapePoint;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.fApproxC0 = FIPNaviDataEvaluated.PolyNaviPathL2.fC0;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.fApproxC1 = FIPNaviDataEvaluated.PolyNaviPathL2.fC1;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.fApproxC2 = FIPNaviDataEvaluated.PolyNaviPathL2.fC2;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.uiCountHighDiffEgo2NaviPath = FIPGlobalNaviInfo.ui_CountHighDiffEgo2NaviPath;
#endif
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.bNaviPathApproxPlausible = FIPNaviDataEvaluated.b_NaviPathApproxPlausible;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.bNaviPathIsInCityLimits = pt_FIP_ND_Output->b_NaviPathIsInCityLimits;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.bNaviPathIsADASQuality = pt_FIP_ND_Output->b_NaviPathIsADASQuality;
  
#endif /*!< FCT_SIMU */

  /* Reset local pointers */
  pt_FIP_ND_Input = NULL;
  pt_FIP_ND_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_ND_InitPersistentData                                                                      */ /*!

  @brief           Initialize persistent data in FIP ND sub module

  @description     Initialize persistent data in FIP ND sub module

  @startuml 
  Partition FIP_v_ND_InitPersistentData
  Start
  	Note right: This function initializes persistent data in FIP Navigation Data sub module	
  	- Depending on the available sources set default values to the persistent data structure
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None
  @glob_out        FIPGlobalNaviInfo : struct containing global NAVI path data (need to be available beyond one cycle)
                      ui_CountHighDiffEgo2NaviPath : Number of cycles with high difference between ego path and NAVI path [0u]
                      f_LengthSeg0LastCycleAdapt : Length of the first segment adapted by the ego motion for the last cycle [0.f ... 400.f]
                      f_LengthSeg0LastCycleNavi : Length of the first segment sent by the NAVI for the last cycle [0.f ... 400.f]
                      f_YOffsetEgoCompAtOrigLastCycle : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      f_AccumDiffYSampleNaviPath : Maximal y-position difference in the NAVI path between the same sample points in two successive cycle [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      NaviDataSegmentChange : Navi input data when changing into a new segment (to compare if now in another segment
                      af_LengtSeg0Seg1SegmentChange[i] Length of the first two segments when entering a new segment i [0.f ... 400.f] with i in [SEGMENT_0, SEGMENT_1] and SEGMENT_0, SEGMENT_1 in fip_navi_data_process.h 
                      NaviPathValidPosSamples : Position samples of NAVI path, which indicate the future course
                      au_SegmentIDSegmentChange[i] Segment IDs of the navi path when entering a new segment i with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                      NaviEGOSegment
                      MotionParams_LastCycle . Vehicle motion parameters for last cycle
  @glob_out         FIP_ND_Output_t : 
                      b_NaviPathPlausible                                             [FALSE]
  @glob_out        FIPShapePointsInNaviRef : Main set of shape points in NAVI reference coordinates, used to compute shape points in EGO reference
  @glob_out        FIPNaviEgoTreeCumul : Accumulated EGO motion in current NAVI tree, relative to current origin in NAVI ref (SP0)
  @glob_out        FIPNaviEgoBufferCumul : Accumulated EGO motion in shape point buffer, relative to next new origin (usually SP3)
  @glob_out        FIPNaviEgoSegmentCumul : Accumulated EGO motion in current segment relative to beginning of the segment

  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component
  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_part   FCT_SIMU simulation enabling switch
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.10.2016
  @changed         23.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_ND_InitPersistentData(void)
{
#if FIP_EVAL_SHAPE_POINTS
  uint8 i;
#endif /* FIP_EVAL_SHAPE_POINTS */

  pt_FIP_ND_Output->f_CurvinessProbFar  = 0.0f;
  pt_FIP_ND_Output->f_CurvinessProbNear = 0.0f;

  /*! Initialize struct containing global NAVI path data (need to be available beyond one cycle) */
  pt_FIP_ND_Output->b_NaviPathPlausible = FALSE;
#if FIP_EVAL_SHAPE_POINTS
  FIPGlobalNaviInfo.ui_CountHighDiffEgo2NaviPath = 0u;
  FIPGlobalNaviInfo.f_LengthSeg0LastCycleAdapt = 0.f;
  FIPGlobalNaviInfo.f_LengthSeg0LastCycleNavi = 0.f;

  FIPGlobalNaviInfo.f_YOffsetEgoCompAtOrigLastCycle = 0.f;
  FIPGlobalNaviInfo.f_AccumDiffYSampleNaviPath = 0.f;
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_FIP_ND_Input->t_LAInput.pt_MovingObjPickUpRange = NULL;
#endif

#if FIP_EVAL_SHAPE_POINTS
#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
  FIPInitNaviData(&(FIPGlobalNaviInfo.NaviDataSegmentChange));
#else
#ifdef FCT_SIMU
  if (b_UseInterfaceWithoutSegmentID == TRUE)
  {
    FIPInitNaviData(&(FIPGlobalNaviInfo.NaviDataSegmentChange));
  }
  else
  {
    FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_0] = 0.f;
    FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_1] = 0.f;
  }
#else
  FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_0] = 0.f;
  FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_1] = 0.f;
#endif
#endif
#endif /* FIP_EVAL_SHAPE_POINTS */

#if (FCT_CFG_COURSE_PREDICTION)
  CP_v_InitPosSamples(&(FIPGlobalNaviInfo.NaviPathValidPosSamples));
#endif
#if FIP_EVAL_SHAPE_POINTS
  for(i = 0u; i < (uint8)FCT_NAV_NUM_SEG; i++)
  {
#if ((FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON))
    FIPGlobalNaviInfo.au_SegmentIDSegmentChange[i] = 0u;
#endif
  }

  FIP_v_NaviInitInfoEgoSegment(&FIPGlobalNaviInfo.NaviEGOSegment);

  /* Last cycle motion parameters */
  FIP_v_NaviInitVehicleMotionParameters(&FIPGlobalNaviInfo.MotionParams_LastCycle);

  /* Initialize shape points in NAVI reference */
  FIPInitNaviRefShapePointData(&(FIPShapePointsInNaviRef));

  /* Initialize Ego motion cumulative structures */
  FIP_v_InitEgoCumulStructure(&FIPNaviEgoTreeCumul);
  FIP_v_InitEgoCumulStructure(&FIPNaviEgoBufferCumul);
  FIP_v_InitEgoCumulStructure(&FIPNaviEgoSegmentCumul);
#endif
  /*! Init global data, which is used in other modules */
  FIPInitEvalNaviData();
}
/*************************************************************************************************************************
  Functionname:    FIP_v_ND_InitEveryCycle                                                                        */ /*!

  @brief           Initialize in enery cycle in FIP Navi Data Process

  @description     Initialize non-persistent output data structures and variables with the default values in the sub module,
                   This function uses local pointer to the sub module output instantiated in Frame.
  
  @startuml 
  Partition FIP_v_ND_InitEveryCycle
  Start
  	Note right: This function initializes non-persistent \n output data structures and variables \n with the default values in FIP Navigation Data sub module	
	  - Depending on the available sources set default values to the non-persistent data structure
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_ND_Input : Reference to FIP Navi Data Process module input 
  @glob_out        pt_FIP_ND_Output : Reference to FIP Navi Data Process module outut

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

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
static void FIP_v_ND_InitEveryCycle(void)
{
  ObjNumber_t t_ObjNr;
  uint8 i;
#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  pt_FIP_ND_Output->f_DistToHighCC = FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX;
#endif
  pt_FIP_ND_Output->u_NaviBranchProb = 0U;
  for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
  {
    pt_FIP_ND_Output->t_ObjList[t_ObjNr].u_NumLane = 0u;
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
    pt_FIP_ND_Output->t_ObjList[t_ObjNr].f_NaviLatDist = FIP_MAX_DIST_TEN_HIGHWAY_LANES;
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST*/
  }
 
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
  for(i = 0u; i < FIP_MAX_NUM_NAVI_SEG; i++)
  {
    f_FIP_NaviSegmentStartX[i] = 0.0;
    f_FIP_NaviSegmentStartY[i] = 0.0;
    f_FIP_NaviAccumPrevSegAngle[i] = 0.0;
  }
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST*/

#if (FIP_EVAL_ROAD_JUNCTION)
  pt_FIP_ND_Output->f_Dist2Junction = INVALID_DISTANCE_TO_JUNCTION;
  pt_FIP_ND_Output->e_JunctionDetection = NO_JUCTION;
#endif
#if (FCT_CFG_CUSTOM_PASSING_STATE)
  pt_FIP_ND_Output->b_OvertakeLaneIsExitLane = FALSE;
  pt_FIP_ND_Output->b_NoPassingSign = FALSE;
#endif  /* #endif FCT_CFG_CUSTOM_PASSING_STATE */
#if (FIP_EVAL_SHAPE_POINTS) 
  for(i =0; i<FIP_NUM_NAVI_PATH_SHAPE_POINTS; i++)
  {
    if(i < FCT_NAV_NUM_SEG){
      pt_FIP_ND_Output->t_SIMNaviData.af_ParaA[i] = 0.0f;
      pt_FIP_ND_Output->t_SIMNaviData.af_ParaB[i] = 0.0f;
      pt_FIP_ND_Output->t_SIMNaviData.af_ParaC[i] = 0.0f;
      pt_FIP_ND_Output->t_SIMNaviData.af_ParaD[i] = 0.0f;
      pt_FIP_ND_Output->t_SIMNaviData.ab_SegmentSplineValid[i] = FALSE;
    }
	
    pt_FIP_ND_Output->t_SIMNaviData.fXPosShapeAll[i] = 0.0f;
    pt_FIP_ND_Output->t_SIMNaviData.fYPosShapeAll[i] = 0.0f;
  }
#endif /*END IF (FIP_EVAL_SHAPE_POINTS)*/
  for(i=0u; i < 20u; i++)
  {
    pt_FIP_ND_Output->t_SIMNaviData.fPosXApprox[i] = 0.0f;
    pt_FIP_ND_Output->t_SIMNaviData.fPosYApprox[i] = 0.0f;
  }
  pt_FIP_ND_Output->t_SIMNaviData.uiNumPoints = 0u;
  pt_FIP_ND_Output->t_SIMNaviData.uiNumShapePoints = 0u;

  pt_FIP_ND_Output->t_SIMNaviData.NaviPathApprox.fC0 = 0.0f;
  pt_FIP_ND_Output->t_SIMNaviData.NaviPathApprox.fC1 = 0.0f;
  pt_FIP_ND_Output->t_SIMNaviData.NaviPathApprox.fC2 = 0.0f;
  pt_FIP_ND_Output->t_SIMNaviData.NaviPathApprox.isValid = FALSE;

  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.b_MppNew = TRUE;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.f_AngleClothStart = 0.0f;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.NavRoutingActive = 0u;

  for(i=0u; i < (uint8)FCT_NAV_NUM_SEG; i++)
  {
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].f_AnglePrevBranch = 0.0f;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].f_AnglePrevSeg = 0.0f;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].f_Curvature = 0.0f;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].f_Length = 0.0f;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].TypStreet = NAV_STT_SIGNAL_UNFILLED;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].TypStreetBranch = NAV_STT_SIGNAL_UNFILLED;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].u_ProbEgoTakesBranch = 0u;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].u_QuanLanes = 0u;
    pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.Segments[i].u_SegmentID = 0u;
  }
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.sSigHeader.uiCycleCounter = 0u;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.sSigHeader.uiMeasurementCounter = 0u;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.sSigHeader.uiTimeStamp = 0u;

  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.uiVersionNumber = FCT_NAVI_INPUT_INTFVER;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextBridge = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextExitLaneEnd = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextExitLaneStart = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextRoundabout = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextTollbooth = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextTunnelEnd = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_DistNextTunnelStart = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_NumUsedSegments = 0u;
  pt_FIP_ND_Output->t_SIMNaviData.NaviInputData.u_QualityNavData = 0u;


}
/*************************************************************************************************************************
  Functionname:    FIP_v_ND_SetInput                                                                        */ /*!

  @brief           Set the input for FIP FIP Navi Data Process

  @description     Set the input for FIP FIP Navi Data Process

  @startuml 
  Partition FIP_v_CC_SetInput
  Start
  	Note right: This function sets the input for FIP Navigation data sub module	
	  If (ACC lane association switch is enabled) then (True)
	  	- Set Moving Object Pick up Range from Lane association sub module
  	Else (False)
  	Endif
  Stop
  @enduml
  
  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.10.2016
  @changed         03.10.2016

  @todo            Remove this entire line if not needed

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_ND_SetInput(void)
{
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_FIP_ND_Input->t_LAInput.pt_MovingObjPickUpRange = LA_pt_GetMovingObjPickupRange();
#endif
}

/*************************************************************************************************************************
  Functionname:    FIPInitGlobalNaviData                                                                            */ /*!

  @brief           Initialize struct containing global NAVI path data (need to be available beyond one cycle)

  @description     Initialize struct containing global NAVI path data (need to be available beyond one cycle)

  @startuml 
  Partition FIPInitGlobalNaviData
  Start
  	Note right: This function initializes structure containing global navigation path data	
  	- Depending on the available sources initialize persistent data and non-persistent data in Navigation Data sub module
  Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_ND_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_ND_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        -

  @c_switch_part   
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
  @changed         02.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIPInitGlobalNaviData(FIP_ND_InputConst_t * pt_FIP_ND_InputGlobal, FIP_ND_Output_t * pt_FIP_ND_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_ND_Input = pt_FIP_ND_InputGlobal;
  pt_FIP_ND_Output = pt_FIP_ND_OutputGlobal;

  /* Initialize persistent data in ND sub module */
  FIP_v_ND_InitPersistentData();
  
  /* Initialize non-persistent data in ND sub module */
  FIP_v_ND_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_ND_Input = NULL;
  pt_FIP_ND_Output = NULL;
}


#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_NaviInitInfoEgoSegment                                                                     */ /*!

  @brief           Initialize ego segment information

  @description     Initialize ego segment information

  @startuml 
  Partition FIP_v_NaviInitInfoEgoSegment
  Start
  	Note right: This function initializes ego segment information
  	- Depending on the available sources initialize ego segment information to 0
  Stop
  @enduml

  @return          -

  @param[out]      p_InfoEgoSegment : Reference to data structure containing information about the segment where EGO currently is present
                      b_ForcedNewSegment        [TRUE, FALSE]
                      f_AnglePrevSeg            [-180.f ... 180.f] rad
                      f_Curvature: curvature [-1f  1f]
                      f_DistInNaviSeg0 : Driven distance of ego vehicle in the first segment (segment 0) [0.f ... 400.f] m
                      f_Length: length of near segment [0.f ... 400.f] m

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
  @changed         02.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_NaviInitInfoEgoSegment(FIPNaviEgoSegmentInfo_t * p_InfoEgoSegment)
{
  p_InfoEgoSegment->b_ForcedNewSegment = FALSE;
  p_InfoEgoSegment->f_AnglePrevSeg = 0.f;
  p_InfoEgoSegment->f_Curvature = 0.f;
  p_InfoEgoSegment->f_DistInNaviSeg0 = 0.f;
  p_InfoEgoSegment->f_Length = 0.f;
}
#endif

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_NaviInitTrafoMatrix2D                                                                      */ /*!

  @brief           Initialize GDBTrafoMatrix2D_t structure, transformation matrix for ego compensation

  @description     Initialize GDBTrafoMatrix2D_t structure, transformation matrix for ego compensation

  @startuml 
  Partition FIP_v_NaviInitTrafoMatrix2D
  Start
	  Note right: This function initializes 2D transformation matrix \n structure, transformation matrix for ego compensation
	  - Depending on the available sources initialize transformation matrix structure to 0
  Stop
  @enduml

  @return          -

  @param[out]      p_TrafoMatrix : Reference to transformation matrix
                      TrafoType    [DEFAULT_]
                      f00 : the elements of the matrix [-1.f ... 1.f]
                      f10 : the elements of the matrix [-1.f ... 1.f]
                      f02 : the elements of the matrix [-1.f ... 1.f]
                      f12 : the elements of the matrix [-1.f ... 1.f]
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
  @changed         02.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIP_v_NaviInitTrafoMatrix2D(GDBTrafoMatrix2D_t * p_TrafoMatrix)
{
  /*! Set identity matrix for rotation and no translation */
  /* At initialization theta = 0 -> cos(0) = 1 and sin(0) = 0 */
  p_TrafoMatrix->TrafoType = DEFAULT_;
  p_TrafoMatrix->f00 = 1.f;
  p_TrafoMatrix->f02 = 0.f;
  p_TrafoMatrix->f10 = 0.f;
  p_TrafoMatrix->f12 = 0.f;
}
#endif

#if (FIP_EVAL_SHAPE_POINTS)
/*************************************************************************************************************************
  Functionname:    FIPInitNaviRefShapePointData                                                                     */ /*!

  @brief           Initialize struct containing shape points in NAVI reference

  @description     Initialize struct containing shape points in NAVI reference

  @startuml 
  Partition FIPInitNaviRefShapePointData
  Start
	  Note right: This function initializes structure containing shape points in navigation reference
	  - Depending on the available sources initialize structure containing shape points in navigation reference to 0
  Stop
  @enduml

  @return          -

  @param[out]      pFIPShapePointsInNaviRef : Reference to data structure holding the shape points in NAVI reference
                        b_TreeValid : Info if there exists a valid tree [TRUE, FALSE]
                        b_TreeExtendable : Info if the tree can be extended by adding shape points [TRUE, FALSE]
                        ui_IndexCurrentSegEgo : Index indicating the position of the EGO in terms of segment [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                        ui_IndexLastSPInBuffer : Index indicating the last filled position in shape point array [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                        ui_IndexDiffPosHistorySPNaviRef : Index indicating the last filled position in difference between history SP and EGO array (af_DiffXPosHistorySPNaviRef, af_DiffYPosHistorySPNaviRef) [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                        ui_CountSegmentForced : Counter for number of consecutive forced segments [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                        af_AlphaShapePointNaviRef[i] : Angle  of segment i of current NAVI path [-180.f ... 180.f] rad
                          with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                        af_LengthShapePointNaviRef[i] : Length of segment i of current NAVI path [0.f ... 400.f] m
                          with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                        af_CurvatureShapePointNaviRef[i] : Curvature of segment i of current NAVI path  [-1.f ... 1.f]
                          with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                        au_ProbTakeBranchShapePointNaviRef[i] : Probability of segment i that EGO takes branch of current NAVI path [0u ... 100u] %
                          with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                        af_XPosShapePointNaviRef[i] : X-position of segment i in NAVI reference  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                          with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                        af_YPosShapePointNaviRef[i] : Y-position of segment i in NAVI reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          with i in [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[ and FIP_NUM_NAVI_REF_SHAPE_POINTS in fip_navi_data_process.h
                        af_DiffXPosHistorySPNaviRef[i] : X-position difference between EGO position and history shape points in NAVI reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                          with i in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                        af_DiffYPosHistorySPNaviRef[i] : Y-position difference between EGO position and history shape points in NAVI reference  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          with i in [0u ... FIP_NUM_HIST_SHAPE_POINTS[ and FIP_NUM_HIST_SHAPE_POINTS in fip_navi_data_process.h
                        f_AvgEGOPathDiff : average difference between navi and ego lane [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        CON2COGAtEgoBufferCumulReset : Transformation matrix from NAVI reference coordinates to EGO reference coordinates when shape point buffer is full

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
  @changed         02.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIPInitNaviRefShapePointData(FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef)
{
  uint8 i;

  pFIPShapePointsInNaviRef->b_TreeValid = FALSE;
  pFIPShapePointsInNaviRef->b_TreeExtendable = FALSE;

  pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo = 0u;
  pFIPShapePointsInNaviRef->ui_IndexLastSPInBuffer = 0u;
  pFIPShapePointsInNaviRef->ui_IndexDiffPosHistorySPNaviRef = 0u;
  pFIPShapePointsInNaviRef->ui_CountSegmentForced = 0u;


  for (i = 0; i < FIP_NUM_NAVI_REF_SEGMENTS; i++)
  {
      pFIPShapePointsInNaviRef->af_AlphaShapePointNaviRef[i] = 0.f;
      pFIPShapePointsInNaviRef->af_LengthShapePointNaviRef[i] = 0.f;
      pFIPShapePointsInNaviRef->af_CurvatureShapePointNaviRef[i] = 0.f;
      pFIPShapePointsInNaviRef->au_ProbTakeBranchShapePointNaviRef[i] = 0u;
  }

  for (i = 0; i < FIP_NUM_NAVI_REF_SHAPE_POINTS; i++)
  {
    pFIPShapePointsInNaviRef->af_XPosShapePointNaviRef[i] = 0.f;
    pFIPShapePointsInNaviRef->af_YPosShapePointNaviRef[i] = 0.f;
  }

  for (i = 0; i < FIP_NUM_HIST_SHAPE_POINTS; i++)
  {
    pFIPShapePointsInNaviRef->af_DiffXPosHistorySPNaviRef[i] = 0.f;
    pFIPShapePointsInNaviRef->af_DiffYPosHistorySPNaviRef[i] = 0.f;
  }

  pFIPShapePointsInNaviRef->f_AvgEGOPathDiff = 0.f; 

  FIP_v_NaviInitTrafoMatrix2D(&pFIPShapePointsInNaviRef->CON2COGAtEgoBufferCumulReset);
}
#endif /* FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPInitShapePointsInEgoRef                                                                       */ /*!

  @brief           Initialize struct containing NAVI path data in EGO reference coordinates

  @description     Initialize struct containing NAVI path data in EGO reference coordinates

  @startuml 
  Partition FIPInitShapePointsInEgoRef
  Start
  	Note right: This function initializes structure containing navigation path data in EGO reference coordinates
	  - Depending on the available sources initialize structure containing navigation path data in EGO reference coordinates to 0
  Stop
  @enduml

  @return          -

  @param[out]      pFIPShapePointsInEgoRef : Reference to structure containing NAVI path data in EGO reference coordinates
                        b_SplineValid : info if entire spline interpolation was valid [TRUE, FALSE]
                        ui_NumberOfShapePoints : Number of shape points in EGO reference coordinate system [0u ... FIP_NUM_NAVI_PATH_SHAPE_POINTS[
                        ab_SegmentSplineValid[i] : Info the interpolated spline for a single segment was valid [TRUE, FALSE]
                        af_ParaA[i] : Parameter for the spline of each segment [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        af_ParaB[i] : Parameter for the spline of each segment [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        af_ParaC[i] : Parameter for the spline of each segment [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        af_ParaD[i] : Parameter for the spline of each segment [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        af_XPosShapePointEgoRef[i] : X-position of point i all shape points in ego reference [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        with i in [0u ... FIP_NUM_NAVI_PATH_SHAPE_POINTS[ and FIP_NUM_NAVI_PATH_SHAPE_POINTS in fip_navi_data_process.h
                        af_YPosShapePointEgoRef[i] : Y-position of point i all shape points in ego reference [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        with i in [0u ... FIP_NUM_NAVI_PATH_SHAPE_POINTS[ and FIP_NUM_NAVI_PATH_SHAPE_POINTS in fip_navi_data_process.h
  

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
  @changed         02.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIPInitShapePointsInEgoRef(FIPNaviShapePointEgo_t* pFIPShapePointsInEgoRef)
{
  uint8 i;

  pFIPShapePointsInEgoRef->b_SplineValid = FALSE;
  pFIPShapePointsInEgoRef->ui_NumberOfShapePoints = 0u;

  for (i = 0; i < FIP_NUM_NAVI_PATH_SHAPE_POINTS; i++ )
  {
    if(i < FCT_NAV_NUM_SEG)
    {
      pFIPShapePointsInEgoRef->ab_SegmentSplineValid[i] = FALSE;
      pFIPShapePointsInEgoRef->af_ParaA[i] = 0.f;
      pFIPShapePointsInEgoRef->af_ParaB[i] = 0.f;
      pFIPShapePointsInEgoRef->af_ParaC[i] = 0.f;
      pFIPShapePointsInEgoRef->af_ParaD[i] = 0.f;
    }
    pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[i] = 0.f;
    pFIPShapePointsInEgoRef->af_YPosShapePointEgoRef[i] = 0.f;
  }
}
#endif /* FIP_EVAL_SHAPE_POINTS */

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_InitEgoCumulStructure                                                                      */ /*!

  @brief           Initialize struct containing Ego Motion cumulative info

  @description     Initialize struct containing Ego Motion cumulative info

  @startuml 
  Partition FIP_v_InitEgoCumulStructure
  Start
  	Note right: This function initializes structure containing Ego Motion cumulative info
	  - Depending on the available sources initialize structure containing Ego Motion cumulative info to 0
  Stop
  @enduml

  @return          -

  @param[out]      pFIPNaviEgoXCumul : Reference to data structure holding the cumulative EGO motion info
                      f_abs_angle : Angle representing orientation accumulated by EGO with reference to a given originAngle representing orientation accumulated by EGO with reference to a given origin [-PI ... PI] rad
                      f_abs_dist : Absolute distance traveled by the EGO with reference to a given origin [float] m
                      f_rel_dx : X-position of the EGO with reference to a given origin [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f_rel_dy : Y-position of the EGO with reference to a given origin [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

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
  @changed         02.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_v_InitEgoCumulStructure(FIPNaviCummulativeEgoMotion_t* pFIPNaviEgoXCumul)
{
  pFIPNaviEgoXCumul->f_abs_angle = 0.f;
  pFIPNaviEgoXCumul->f_abs_dist = 0.f;
  pFIPNaviEgoXCumul->f_rel_dx = 0.f;
  pFIPNaviEgoXCumul->f_rel_dy = 0.f;
}
#endif

/*************************************************************************************************************************
  Functionname:    FIPInitEvalNaviData                                                                              */ /*!

  @brief           Initialize struct containing global NAVI path data, which includes evaluated NAVI data and which 
                   is used in other modules

  @description     Initialize struct containing global NAVI path data, which includes evaluated NAVI data and which 
                   is used in other modules
  
  @startuml 
  Partition FIPInitEvalNaviData
  Start
  	Note right: This function initializes structure containing global navigation path data
  	- Depending on the available sources initialize structure containing global navigation path data to 0
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data structure
                      
                      
                      b_NaviPathApproxPlausible : Info if NAVI path approximation is plausible [TRUE FALSE]
                      f_SumLengthNaviPath : Entire length of NAVI path [0.f ... FCT_NAV_NUM_SEG*400.f] m
                      f_NaviPathToPolySumSqDistAvg : Measure how "close" the NAVI path is to the approximated NAVI path (by a polynomial) [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      f_DiffAngleToFistShapePoint : Angle to first shape point [-PI ... PI] rad
                      PolyNaviPathL2: Approximated NAVI path by a second order polynom
                       fC0 : C0 of 3 degree clothoid polynom                      [-100.f ... 100.f] m^-2
                       fC1 : C1 of 3 degree clothoid polynom                      [-100.f ... 100.f] m^-2
                       fC2 : C1 of 3 degree clothoid polynom                      [-100.f ... 100.f] m^-2
  @glob_out        FIP_ND_Output_t :
                      b_NaviPathIsValid : information if NAVI data is valid [TRUE, FALSE] 
                      b_NaviPathIsHighway : Info if driving on a highway [TRUE FALSE]
                      b_NaviPathIsCountryRoadOneLane : Info if driving on a country road with one lane [TRUE FALSE]
                      f_NaviPathApproxLength : Length of NAVI path which is used for approximation of the NAVI path [0.f ... FCT_NAV_NUM_SEG*400.f] m             [0.f]
                      f_YOffsetEgoCompAtOrig : Y-Offset of ego motion compensated navi path at the ego position [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      f_EgoNaviPathErrDistAvg : Difference between the approximated NAVI path and the ego curve [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m2
                      b_NaviPathIsInCityLimits : Info if current NAVI path indicates driving within city limits [TRUE FALSE]
                      b_NaviPathIsADASQuality . Info if the NAVI path is of ADAS quality [TRUE FALSE]
                      f_DistNextLeftExit : Distance to the next exit on the left side [0.f ... FCT_NAV_NUM_SEG*400.f] m
                      f_DistNextRightExit : Distance to the next exit on the right side [0.f ... FCT_NAV_NUM_SEG*400.f] m

  @c_switch_part   FCT_SIMU : Config switch for FCT simulation
  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
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
  @changed         02.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPInitEvalNaviData(void)
{

#if ((FCT_NAVI_INPUT_INTFVER > 4u) && (FIP_NAV_USE_SEG_ID == SWITCH_ON))
#ifdef FCT_SIMU
  b_UseInterfaceWithoutSegmentID = FALSE;
#endif
#endif

  pt_FIP_ND_Output->b_NaviPathIsHighway = FALSE;
  pt_FIP_ND_Output->b_NaviPathIsCountryRoadOneLane = FALSE;
  pt_FIP_ND_Output->b_NaviPathIsInCityLimits = FALSE;
  FIPNaviDataEvaluated.b_NaviPathApproxPlausible = FALSE;
  pt_FIP_ND_Output->b_NaviPathIsADASQuality = FALSE;
  FIPNaviDataEvaluated.f_SumLengthNaviPath = 0.f;
  FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg = 0.f;
  pt_FIP_ND_Output->f_EgoNaviPathErrDistAvg = 0.f;
  pt_FIP_ND_Output->f_NaviPathApproxLength = 0.f;
#if FIP_EVAL_SHAPE_POINTS
  pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig = 0.f;
#else
  pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig = 0.f;
#endif
  FIPNaviDataEvaluated.f_DiffAngleToFistShapePoint = 0.f;
#if FIP_EVAL_SHAPE_POINTS
  FIPNaviDataEvaluated.PolyNaviPathL2.fC0 = 0.f;
  FIPNaviDataEvaluated.PolyNaviPathL2.fC1 = 0.f;
  FIPNaviDataEvaluated.PolyNaviPathL2.fC2 = 0.f;
#endif
  pt_FIP_ND_Output->f_DistNextLeftExit = (float32)FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->f_DistNextRightExit = (float32)FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pt_FIP_ND_Output->b_NaviPathIsValid = FALSE;

}

#if FIP_EVAL_SHAPE_POINTS && ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
/*************************************************************************************************************************
  Functionname:    FIPInitNaviData                                                                                  */ /*!

  @brief           Initialize local copy of navi input data of type t_NaviInputData including custom data

  @description     Initialize local copy of navi input data of type t_NaviInputData including custom data

  @startuml 
  Partition FIPInitNaviData
  Start
  	Note right: This function initializes structure containing local copy of navigation input data including custom data
  	- Depending on the available sources initialize structure containing \n local copy of navigation input data including custom data to 0 and default values
  Stop
  @enduml

  @return          -

  @param[in,out]   pNaviData : Reference to incoming NAVI data
                        uiVersionNumber                     [FCT_NAVI_INPUT_INTFVER as in Rte_SWCFctSenAdapt_Type.h]
                        b_MppNew                            [TRUE, FALSE]
                        u_NumUsedSegments: number of the used segments [0u ... FCT_NAV_NUM_SEG[
                        u_QualityNavData                    [0u]
                        u_DistNextRoundabout                [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        u_DistNextTunnelStart               [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        u_DistNextTunnelEnd                 [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        u_DistNextTollbooth                 [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        u_DistNextExitLaneStart             [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        u_DistNextExitLaneEnd               [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        u_DistNextBridge                    [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                        NavRoutingActive                    [NAV_ROUNTING_SNA as in Rte_SWCFctSenAdapt_Type.h]
                        f_AngleClothStart                   [0.f]
                        Segments[i] : segement i
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                          u_QuanLanes : number of lanes [0u ... FIP_NAV_MAX_VALID_LANE_NUM[
                          u_ProbEgoTakesBranch              [0u  100] %
                          TypStreet : street type [NAV_STT_SIGNAL_UNFILLED as in Rte_SWCFctSenAdapt_Type.h]
                          f_Length                          [0.f ... 400.f] m
                          f_Curvature                       [-1f  1f]
                          f_AnglePrevSeg                    [-180.f ... 180.f] rad
                          TypStreetBranch : type of the street branch [NAV_STT_SIGNAL_UNFILLED as in Rte_SWCFctSenAdapt_Type.h]
                          f_AnglePrevBranch : branches angle to previous segment [0.f]
                        sSigHeader : signal header
                          eSigStatus : status [AL_SIG_STATE_INIT as in Rte_SWCAlnAdapt_Type.h]
                          uiCycleCounter : The FCT_VEH cycle counter [0u]
                          uiMeasurementCounter              [0u]
                          uiTimeStamp : time stamp to store [0u]

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
  @changed         02.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPInitNaviData(t_NaviInputData * pNaviData)
{
  uint8 i;

  pNaviData->uiVersionNumber = FCT_NAVI_INPUT_INTFVER;
  pNaviData->b_MppNew = TRUE;
  pNaviData->u_NumUsedSegments = 0u;
  pNaviData->u_QualityNavData = 0u;
  pNaviData->u_DistNextRoundabout = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextTunnelStart = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextTunnelEnd = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextTollbooth = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextExitLaneStart = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextExitLaneEnd = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT; 
  pNaviData->u_DistNextBridge = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->NavRoutingActive = NAV_ROUNTING_SNA;
  pNaviData->f_AngleClothStart = 0.f;
  for(i = 0u; i < (uint8)FCT_NAV_NUM_SEG; i++)
  {
    pNaviData->Segments[i].u_QuanLanes = 0u;
    pNaviData->Segments[i].u_ProbEgoTakesBranch = 0u;
    pNaviData->Segments[i].TypStreet = NAV_STT_SIGNAL_UNFILLED;
    pNaviData->Segments[i].f_Length = 0.f;
    pNaviData->Segments[i].f_Curvature = 0.f;
    pNaviData->Segments[i].f_AnglePrevSeg = 0.f;
    pNaviData->Segments[i].TypStreetBranch = NAV_STT_SIGNAL_UNFILLED;
    pNaviData->Segments[i].f_AnglePrevBranch = 0.f;
  } 
  pNaviData->sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  pNaviData->sSigHeader.uiCycleCounter = 0;
  pNaviData->sSigHeader.uiMeasurementCounter = 0;
  pNaviData->sSigHeader.uiTimeStamp = 0;

  FIP_v_InitNaviCustomData();
}
#else
#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    FIPInitNaviData                                                                                  */ /*!

  @brief           Initialize local copy of navi input data of type t_NaviInputData

  @description     Initialize local copy of navi input data of type t_NaviInputData

  @startuml 
  Partition FIPInitNaviData
  Start
  	Note right: This function initializes structure containing local copy of navigation input data including custom data
  	- Depending on the available sources initialize structure containing \n local copy of navigation input data including custom data to 0 and default values
  Stop
  @enduml

  @return          -

  @param[in,out]   pNaviData : Reference to incoming NAVI data
                      uiVersionNumber                    [FCT_NAVI_INPUT_INTFVER as in Rte_SWCFctSenAdapt_Type.h]
                      b_MppNew                           [TRUE, FALSE]
                      u_NumUsedSegments                  [0u ... FCT_NAV_NUM_SEG[
                      u_QualityNavData                   [0u]
                      u_DistNextRoundabout               [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                      u_DistNextTunnelStart              [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                      u_DistNextTunnelEnd                [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                      u_DistNextTollbooth                [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                      u_DistNextExitLaneStart            [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                      u_DistNextExitLaneEnd              [FIP_NAVI_DIST_NEXT_EVENT_DEFAULT as in fip_navi_data_process.h]
                      NavRoutingActive                   [NAV_ROUNTING_SNA as in Rte_SWCFctSenAdapt_Type.h]
                      f_AngleClothStart                  [0.f]
                      Segments[i]
                       u_QuanLanes            [0u ... FIP_NAV_MAX_VALID_LANE_NUM[
                       u_ProbEgoTakesBranch   [0u  100] %
                       TypStreet              [NAV_STT_SIGNAL_UNFILLED as in Rte_SWCFctSenAdapt_Type.h]
                          f_Length                          [0.f ... 400.f] m
                          f_Curvature                       [-1f  1f]
                          f_AnglePrevSeg                    [-180.f ... 180.f] rad
                       TypStreetBranch        [NAV_STT_SIGNAL_UNFILLED as in Rte_SWCFctSenAdapt_Type.h]
                       f_AnglePrevBranch      [0.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Config switch for FCT simulation
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
  @changed         16.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPInitNaviData(t_NaviInputData * pNaviData)
{
  uint8 i;

  pNaviData->uiVersionNumber = FCT_NAVI_INPUT_INTFVER;
  pNaviData->b_MppNew = TRUE;
  pNaviData->u_NumUsedSegments = 0u;
  pNaviData->u_QualityNavData = 0u;
  pNaviData->u_DistNextRoundabout = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextTunnelStart = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextTunnelEnd = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextTollbooth = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextExitLaneStart = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->u_DistNextExitLaneEnd = FIP_NAVI_DIST_NEXT_EVENT_DEFAULT;
  pNaviData->NavRoutingActive = NAV_ROUNTING_SNA;
  pNaviData->f_AngleClothStart = 0.f;
  for(i = 0u; i < (uint8)FCT_NAV_NUM_SEG; i++)
  {
    pNaviData->Segments[i].u_QuanLanes = 0u;
    pNaviData->Segments[i].u_ProbEgoTakesBranch = 0u;
    pNaviData->Segments[i].TypStreet = NAV_STT_SIGNAL_UNFILLED;
    pNaviData->Segments[i].f_Length = 0.f;
    pNaviData->Segments[i].f_Curvature = 0.f;
    pNaviData->Segments[i].f_AnglePrevSeg = 0.f;
    pNaviData->Segments[i].TypStreetBranch = NAV_STT_SIGNAL_UNFILLED;
    pNaviData->Segments[i].f_AnglePrevBranch = 0.f;
  }
}
#endif
#endif

#if (FIP_EVAL_SHAPE_POINTS)
/*************************************************************************************************************************
  Functionname:    FIP_b_AdaptNaviShapePointData                                                                    */ /*!

  @brief           Adapt the Shape Points in NAVI reference based on new segment information. The shape point buffer is updated and 
                   the ego segment is updated.

  @description     Adapt the Shape Points in NAVI reference based on new segment information. The shape point buffer is updated and 
                   the ego segment is updated. The detection if the ego vehicle entered a new segment based on ego motion without 
                   segment update of the navi is handled (= "forced segment").
                   Mainly three cases are handled here - 
                   A. Only forced segment during current cycle
                   B. Forced segment and new segment arriving during same cycle
                   C. Only new segment arriving based on incoming NAVI data. NO forced segment in current cycle but there 
                      may be residual forced segments, check ui_CountSegmentForced.
  
  @startuml 
  Partition FIP_b_AdaptNaviShapePointData
  Start
	Note right: This function adapts the Shape Points in navigation reference based on new segment information
	If (Only forced segment during current cycle) then (True)
  		- Compute the difference between EGO path and shape point in navigation reference
  		- Increment the index of the current segment 0
  		- make corrections to EGO segment data

  		If (Index of current segment 0 is less than \n Total number of segments in navigation reference coordinate system) then (True)
  			- Update navigation ego segmet structure for index of current segment 0
			- Set flag for forced new segment to True
  		Else (False)
			- Initialize ego segment information
  		Endif
  		- Set Forced new segment to False

  		If (IndexBuffer points to 10) then (True)
  			- Initialize structure containing Ego Motion cumulative info
  		Else (False)
  		Endif

		- Initialize structure containing Ego Segment cumulative info

	  Else (False)
	  If (Forced segment AND new segment arriving during same cycle AND Tree extendable True)then (True)
  		- Compute the difference between EGO path and shape point in NAVI reference
  		- Increment the index of the current buffer
		- decrement the counter segment of forced segment once 
  		- Increment the index of the current segment 0
  		- Add new shape point 
		- Decrement forced segment counter now that new segment has been added
  		- Store the current segment initial data
  		If (IndexBuffer points to 11) then (True)
  			- Initialize structure containing Ego Motion cumulative info
  		Else (False)
  		Endif
	  	- Initialize structure containing Ego Segment cumulative info
  	Else (False)
	  If(Only new segment arriving based on incoming NAVI data. NO forced segment in current cycle) then (True)
  		- Increment the index of the current buffer
  		If (Current segment is forced) then (True)
  			- Add new shape point
			- Reset the global flag for forced new segment
  		Else (False)
  			If (any residual forced segments are present) then (True)
  				- Adapt the navi to ego reference conversion matrix with remaining distance in the current segment based on EGO motion
  			Else (False)
  			Endif
  			- compute the difference between EGO path and shape point in NAVI reference
  			- Increment the index of the current segment 0
  			- Add new shape point 
  			- Store the current segment initial data
  			If (IndexBuffer points to 11) then (True)
  				- Initialize structure containing Ego Motion cumulative info
  			Else (False)
  			Endif
  			- Initialize structure containing Ego Segment cumulative info
  		Endif	
  	Else (False)
  	Endif
  	Endif
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       pNaviInputData : Reference to incoming NAVI data
  @param[in]       b_NewSegment : Info if a new segment is entered
  @param[in,out]   pb_NewSegmentF : Info if a new segment has to be forced
  @param[out]      p_CON2COG_Matrix : Reference to transformation matrix between NAVI reference coordinates and EGO reference 
                                      coordinates

  @glob_in         FIPShapePointsInNaviRef : data structure containing shape points in NAVI reference coordinate system
                      ui_IndexCurrentSegEgo             [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                      af_LengthShapePointNaviRef[i]     [0.f ... 400.f] m
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      af_AlphaShapePointNaviRef[i]      [-180.f ... 180.f] rad
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      af_CurvatureShapePointNaviRef[i]  [-1.f ... 1.f]
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      ui_IndexLastSPInBuffer            [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                      CON2COGAtEgoBufferCumulReset
                      b_TreeExtendable                  [TRUE, FALSE]
                      ui_CountSegmentForced             [0u ... FIP_NUM_NAVI_REF_SEGMENTS[

  @glob_in         FIPNaviEgoBufferCumul : Accumulated EGO motion in shape point buffer, relative to next new origin (usually SP3)
  @glob_out        FIPGlobalNaviInfo : struct containing global NAVI path data (need to be available beyond one cycle)
                      NaviEGOSegment
                        f_Length                        [0.f ... 400.f]
                        f_AnglePrevSeg                  [-180.f ... 180.f]
                        f_Curvature                     [-1.f ... 1.f]
                        f_DistInNaviSeg0                [0.f]
                        b_ForcedNewSegment              [TRUE, FALSE]

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
  @changed         02.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_b_AdaptNaviShapePointData(const t_NaviInputData * pNaviInputData, const boolean b_NewSegment, boolean* pb_NewSegmentF, GDBTrafoMatrix2D_t * p_CON2COG_Matrix)
{
  uint8 ui_IdxCurrentSeg0 = FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo;
  float32 f_XDiff;

  if ((*pb_NewSegmentF == TRUE) && (b_NewSegment == FALSE))
  {
    /* Case A : Only forced segment during current cycle 
    1. New segment forced, DO NOT add a shape point just yet. Only make corrections to EGO segment data. 
    2. Increments to ui_IndexCurrentSeg0 is handled here since EGO has moved into new segment. 
    3. Increments to ui_IndexLastSPInBuffer are handled only when new shape points are added.
    */

    /* Before updating anything compute the difference between EGO path and shape point in NAVI reference */
    FIP_b_ComputeEgoPathDifference(&FIPShapePointsInNaviRef, p_CON2COG_Matrix);

    /* Increment the index of the current segment 0 */
    FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo += 1u;
    ui_IdxCurrentSeg0 += 1u;

    if ( ui_IdxCurrentSeg0 < FIP_NUM_NAVI_REF_SEGMENTS )
    {
      FIPGlobalNaviInfo.NaviEGOSegment.f_Length = FIPShapePointsInNaviRef.af_LengthShapePointNaviRef[ui_IdxCurrentSeg0];
      FIPGlobalNaviInfo.NaviEGOSegment.f_AnglePrevSeg = FIPShapePointsInNaviRef.af_AlphaShapePointNaviRef[ui_IdxCurrentSeg0];
      FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature= FIPShapePointsInNaviRef.af_CurvatureShapePointNaviRef[ui_IdxCurrentSeg0];
      FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0 = 0.f;
      /* Set flag for forced segment in FIPGlobalNaviInfo.NaviEGOSegment */
      FIPGlobalNaviInfo.NaviEGOSegment.b_ForcedNewSegment = TRUE;
    }
    else
    {
      FIP_v_NaviInitInfoEgoSegment(&FIPGlobalNaviInfo.NaviEGOSegment);
    }

    /* reset cycle specific b_NewSegmentF, so it does not play further role in this cycle */
    *pb_NewSegmentF = FALSE;

    /* Check for buffer reset condition  - reset when indexBuffer points to 10 (NOT 11) since it can grow up to 14 (HISTORY SP = 3) 
    the ui_IndexCurrentBuffer is updated only when a new SP is added so at this point in time when new segment has been forced, the ui_IndexCurrentBuffer will be 10

    Additionally check if buffer reset was done when last SP was added. The since ui_IndexLastSPInBuffer is only updated when a new SP is added, 
    it remains at the same value when next segment is forced! */
    if (FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer == ((FIP_NUM_NAVI_PATH_SHAPE_POINTS + FIP_NUM_HIST_SHAPE_POINTS) - 2u)) 
    {
      FIP_v_InitEgoCumulStructure(&FIPNaviEgoBufferCumul);
      /* Store CON2COG here, will be used in computation of history differences during buffer reset */
      FIPShapePointsInNaviRef.CON2COGAtEgoBufferCumulReset = *p_CON2COG_Matrix;
    }

    /*Reset the EgoSegCummul, since it is Segment specific */
    FIP_v_InitEgoCumulStructure(&FIPNaviEgoSegmentCumul);
  } 
  else if((b_NewSegment == TRUE) && (*pb_NewSegmentF == TRUE) && (FIPShapePointsInNaviRef.b_TreeExtendable == TRUE))
  {
    /* Case B : Forced segment and new segment arriving during same cycle
    1. Incoming NAVI data indicates a new segment, add a new shape point 
    2. In case Segment Force and New Segment arrive together, the Segment Force will NOT be processed first  - if(*pb_NewSegmentF && !b_NewSegment) 
    Therefore do processing here!!!
    */
    /* Before updating anything compute the difference between EGO path and shape point in NAVI reference */
    FIP_b_ComputeEgoPathDifference(&FIPShapePointsInNaviRef, p_CON2COG_Matrix);

    /* Increment the index of the current buffer since a Shape Point will be added in this section */
    if(FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer < (FIP_NUM_NAVI_REF_SHAPE_POINTS - 1u))
    {
      FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer += 1u;
    }

    /* Segment forced and new Segment have arrived during the same cycle, decrement the counter once extra */
    FIPShapePointsInNaviRef.ui_CountSegmentForced -= 1u;

    /* Increment the index of the current segment 0 */
    FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo += 1u;
    ui_IdxCurrentSeg0 += 1u;

    /* Add new shape point */
    FIPAddNaviShapePoint(pNaviInputData, &FIPShapePointsInNaviRef);
    
    if (FIPShapePointsInNaviRef.ui_CountSegmentForced >= 1u)
    {
      /* Decrement forced segment counter now that new segment has been added */
      FIPShapePointsInNaviRef.ui_CountSegmentForced -= 1u;
    } /* IF (FIPShapePointsInNaviRef.ui_CountSegmentForced >= 1u) */

    /*! Store the current segment initial data */
    if ( ui_IdxCurrentSeg0 < FIP_NUM_NAVI_REF_SEGMENTS )
    {
      FIPGlobalNaviInfo.NaviEGOSegment.f_Length = FIPShapePointsInNaviRef.af_LengthShapePointNaviRef[ui_IdxCurrentSeg0];
      FIPGlobalNaviInfo.NaviEGOSegment.f_AnglePrevSeg = FIPShapePointsInNaviRef.af_AlphaShapePointNaviRef[ui_IdxCurrentSeg0];
      FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature= FIPShapePointsInNaviRef.af_CurvatureShapePointNaviRef[ui_IdxCurrentSeg0];
      FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0 = 0.f;
    }
    else
    {
      FIP_v_NaviInitInfoEgoSegment(&FIPGlobalNaviInfo.NaviEGOSegment);
    }

    /* Check for buffer reset condition  - reset when indexBuffer points to 11 since it can grow up to 14 (HISTORY SP = 3) */
    if (FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer == ((FIP_NUM_NAVI_PATH_SHAPE_POINTS + FIP_NUM_HIST_SHAPE_POINTS) - 1u))
    {
      FIP_v_InitEgoCumulStructure(&FIPNaviEgoBufferCumul);
      /* Store CON2COG here, will be used in computation of history differences during buffer reset */
      FIPShapePointsInNaviRef.CON2COGAtEgoBufferCumulReset = *p_CON2COG_Matrix;
    }

    /*Reset the EgoSegCummul, since it is Segment specific */
    FIP_v_InitEgoCumulStructure(&FIPNaviEgoSegmentCumul);

  } else if ((b_NewSegment == TRUE) && (*pb_NewSegmentF == FALSE) && (FIPShapePointsInNaviRef.b_TreeExtendable == TRUE))
  {
    /* Case C : Only new segment arriving based on incoming NAVI data. NO forced segment in current cycle but there may be residual forced segments, check ui_CountSegmentForced.
    1. Check if Segment Force computation (Case A) was done in previous cycles, i.e., current segment has been forced!
    2. Check for residual forced segments using ui_CountSegmentForced
    3. Decrement ui_CountSegmentForced only once at the end
    */

    /* Increment the index of the current buffer since a Shape Point will be added in this section */
    if(FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer < FIP_NUM_NAVI_REF_SHAPE_POINTS - 1u)
    {
      FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer += 1u;
    }

    if (FIPGlobalNaviInfo.NaviEGOSegment.b_ForcedNewSegment == TRUE) 
    {
      /* Current Segment Forced!!! DO NOT increment ui_IndexCurrentSegEgo, since it was done during Segment Force computation */

      /* Add new shape point */
      FIPAddNaviShapePoint(pNaviInputData, &FIPShapePointsInNaviRef);

      /* Incoming NAVI data indicates a new segment after the new segment was forced by EGO motion, shape point already added! */
      /* Reset the global flag for forced new segment */
      FIPGlobalNaviInfo.NaviEGOSegment.b_ForcedNewSegment = FALSE;
    } else 
    {
      /* New segment has arrived and current segment is NOT forced, however there may be residual forced segments */
      if (FIPShapePointsInNaviRef.ui_CountSegmentForced == 0u)
      {
        /* EGO motion does not indicate new segment and no residual forced segments are present, adapt the CON2COG matrix with remaining distance in the current segment based on EGO motion such that 
        further processing is seamless. This also precludes new tree scenarios.*/
        f_XDiff = FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0 - FIPGlobalNaviInfo.NaviEGOSegment.f_Length;
        p_CON2COG_Matrix->f02 += f_XDiff;

        /* Adapt FIPNaviEgoTreeCumul too since CON2COG is not a static variable and it uses FIPNaviEgo_x_Cumul to refresh itself next cycle */
        FIPNaviEgoTreeCumul.f_rel_dx += f_XDiff;
        FIPNaviEgoTreeCumul.f_abs_dist += f_XDiff;
        FIPNaviEgoBufferCumul.f_rel_dx += f_XDiff;
        FIPNaviEgoBufferCumul.f_abs_dist += f_XDiff;
        FIPNaviEgoSegmentCumul.f_rel_dx += f_XDiff;
        FIPNaviEgoSegmentCumul.f_abs_dist += f_XDiff;
      } /* IF (FIPShapePointsInNaviRef.ui_CountSegmentForced == 0u) */

      FIP_b_ComputeEgoPathDifference(&FIPShapePointsInNaviRef, p_CON2COG_Matrix);

      /* Increment the index of the current segment 0 */
      FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo += 1u;
      ui_IdxCurrentSeg0 += 1u;

      /* Add new shape point */
      FIPAddNaviShapePoint(pNaviInputData, &FIPShapePointsInNaviRef);

      /*! Store the current segment initial data */
      if ( ui_IdxCurrentSeg0 < FIP_NUM_NAVI_REF_SEGMENTS )
      {
        FIPGlobalNaviInfo.NaviEGOSegment.f_Length = FIPShapePointsInNaviRef.af_LengthShapePointNaviRef[ui_IdxCurrentSeg0];
        FIPGlobalNaviInfo.NaviEGOSegment.f_AnglePrevSeg = FIPShapePointsInNaviRef.af_AlphaShapePointNaviRef[ui_IdxCurrentSeg0];
        FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature= FIPShapePointsInNaviRef.af_CurvatureShapePointNaviRef[ui_IdxCurrentSeg0];
        FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0 = 0.f;
      }
      else
      {
        FIP_v_NaviInitInfoEgoSegment(&FIPGlobalNaviInfo.NaviEGOSegment);
      } /* IF ( ui_IdxCurrentSeg0 < FIP_NUM_NAVI_REF_SEGMENTS ) */

      /* Check for buffer reset condition - reset when indexBuffer points to 11 since it can grow up to 14 (HISTORY SP = 3) */
      if (FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer == ((FIP_NUM_NAVI_PATH_SHAPE_POINTS + FIP_NUM_HIST_SHAPE_POINTS) - 1u))
      {
        FIP_v_InitEgoCumulStructure(&FIPNaviEgoBufferCumul);
        /* Store CON2COG here, will be used in computation of history differences during buffer reset */
        FIPShapePointsInNaviRef.CON2COGAtEgoBufferCumulReset = *p_CON2COG_Matrix;
      } /* IF buffer reset condition   */

      /*Reset the EgoSegCummul, since it is Segment specific */
      FIP_v_InitEgoCumulStructure(&FIPNaviEgoSegmentCumul);
    } /* IF (FIPGlobalNaviInfo.NaviEGOSegment.b_ForcedNewSegment == TRUE) */

    if (FIPShapePointsInNaviRef.ui_CountSegmentForced >= 1u)
    {
      /* Incoming data is so slow that more than one segment was forced before new segment arrived, in such cases new segment does not mean EGO moves into new segment 
      (already updated in force operation) */
      FIPShapePointsInNaviRef.ui_CountSegmentForced -= 1u;
    } /* IF (FIPShapePointsInNaviRef.ui_CountSegmentForced >= 1u) */

  } else
  {
    /* Nothing */
  } /* IF-ELSE-IF-ELSE... for cases A,B and C  */


  FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo = MINMAX(0u, FIP_NUM_NAVI_REF_SEGMENTS, FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo); /*PRQA S 3356 1 */
  FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer = MINMAX(0u, FIP_NUM_NAVI_REF_SHAPE_POINTS, FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer);
  /* date: 2015-04-27, reviewer: Rachit Sharma (uidr5426), reason: Used in bounding the variable */
}
#endif /* FIP_EVAL_SHAPE_POINTS */


#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPShiftSPOriginInNaviRef                                                                        */ /*!

  @brief           Shift the tree to a new origin. Needs to be done if the shape point buffer is full. 
                   The transformation matrix CON2COG and the accumulated ego movement  for the ego 
                   compensation is updated.

  @description     Shift the tree to a new origin. Needs to be done if the shape point buffer is full. 
                   The transformation matrix CON2COG and the accumulated ego movement for the ego 
                   compensation is updated.
  
  @startuml 
  Partition FIPShiftSPOriginInNaviRef
  Start
  	Note right: This function shifts the tree to a new origin
	  - Moving current tree to new origin, history shape points to be considered. Start tree at SP4, EGO would have crossed SP7	
  	- Store the history shape points (SP3 - new origin, SP4, SP5, SP6) before shifting of origin
  	- Determine the shape points
  	- Reset ego tree cumulative corresponding to EGO motion cumulative from SP3
  	- Reset ego buffer cumulative
  	- Initialize navigation to ego transformation matrix with current state of EGO motion data
  	- Updates the difference between history shape points and EGO after shift of origin
  Stop
  @enduml

  @return          -

  @param[in,out]   p_CON2COG_Matrix : Reference to transformation matrix between NAVI reference coordinates and EGO reference coordinates
                      f00                                   [-1.f ... 1.f]
                      f10                                   [-1.f ... 1.f]
                      f02                                   [-1.f ... 1.f]
                      f12                                   [-1.f ... 1.f]

  @glob_in         FIPShapePointsInNaviRef : Data structure containing shape points in NAVI reference coordinate system
                      af_XPosShapePointNaviRef[i]     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_NUM_HIST_SHAPE_POINTS[
                      af_YPosShapePointNaviRef[i]     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_NUM_HIST_SHAPE_POINTS[
  @glob_in         FIPNaviEgoBufferCumul : Accumulated EGO motion in shape point buffer, relative to next new origin (usually SP3)
  @glob_in         FIPNaviEgoSegmentCumul : Accumulated EGO motion in current segment relative to beginning of the segment
  @glob_out        FIPShapePointsInNaviRef : Data structure containing shape points in NAVI reference coordinate system
                      FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo           [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                      FIPShapePointsInNaviRef.CON2COGAtEgoBufferCumulReset
  @glob_out        FIPNaviEgoTreeCumul : Accumulated EGO motion in current NAVI tree, relative to current origin in NAVI ref (SP0)
                      f_abs_angle                         [-PI ... PI] rad
                      f_rel_dx                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f_rel_dy                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        FIPNaviEgoBufferCumul : Accumulated EGO motion in shape point buffer, relative to next new origin (usually SP3)

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
  @changed         03.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIPShiftSPOriginInNaviRef(GDBTrafoMatrix2D_t * p_CON2COG_Matrix)
{
  uint8 i;
  float32 f_XPosOrigin, f_YPosOrigin;
  float32 af_XHistSPBT[FIP_NUM_HIST_SHAPE_POINTS], af_YHistSPBT[FIP_NUM_HIST_SHAPE_POINTS]; /* Holders for storing current history shape points before transformation (SPBT) */

  /* Moving current tree to new origin, history shape points to be considered. Start tree at SP4, EGO would have crossed SP7 */
  uint8 ui_IdxSegNaviOrig = FIP_NUM_HIST_SHAPE_POINTS_BUFFER;     /* SP3, counting starts at 0 */
  uint8 ui_IdxSegNaviEnd = FIP_NUM_NAVI_REF_SHAPE_POINTS - 1;     /* Segment reference is always one less than shape point */
  

  /* Store the history shape points (SP3 - new origin, SP4, SP5, SP6) before transformation/shifting of origin */
  for (i = 0; i < FIP_NUM_HIST_SHAPE_POINTS; i++)
  {
    af_XHistSPBT[i] = FIPShapePointsInNaviRef.af_XPosShapePointNaviRef[FIP_NUM_HIST_SHAPE_POINTS + 1 + i];
    af_YHistSPBT[i] = FIPShapePointsInNaviRef.af_YPosShapePointNaviRef[FIP_NUM_HIST_SHAPE_POINTS + 1 + i];
  }

  /* Since this is a shift of origin in the NAVI tree (setting a given shape point as the new origin), the origin will be by definition (0,0) */
  f_XPosOrigin = 0.f;
  f_YPosOrigin = 0.f;

  /*! Determine the shape points */
  FIPGetNaviRefShapePoints(ui_IdxSegNaviOrig, ui_IdxSegNaviEnd, &FIPShapePointsInNaviRef, f_XPosOrigin, f_YPosOrigin);

  /* Initialize indexCurrentSeg0 - CHECK: use current value */
  FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo = ui_IdxSegNaviOrig;

  /* Reset indexCurrentBuffer - handled in FIPGetNaviRefShapePoints - DO NOT modify here */

  /* Reset EgoTreeCummul  - corresponding to EGO motion cumulative from SP3 */
  FIPNaviEgoTreeCumul = FIPNaviEgoBufferCumul;

  /* Reset EgoBufferCummul */
  FIPNaviEgoBufferCumul = FIPNaviEgoSegmentCumul;  /* use - corresponding to EGO motion cumulative from SP3 */
  
  /* Initialize CON2COG with current state of EGO motion data - This section must be after FIPNaviEgoTreeCumul is updated from Buffer */
  p_CON2COG_Matrix->f00 = COS_HD_(-FIPNaviEgoTreeCumul.f_abs_angle);
  p_CON2COG_Matrix->f10 = SIN_HD_(-FIPNaviEgoTreeCumul.f_abs_angle);
  
  /* Translation matrix terms*/
  p_CON2COG_Matrix->f02 = FIPNaviEgoTreeCumul.f_rel_dx;
  p_CON2COG_Matrix->f12 = FIPNaviEgoTreeCumul.f_rel_dy;

  FIP_v_UpdateHistorySP(af_XHistSPBT, af_YHistSPBT, &FIPShapePointsInNaviRef, &FIPShapePointsInNaviRef.CON2COGAtEgoBufferCumulReset);

  /* Store CON2COG here, it will be used in computation of history differences during buffer reset */
  FIPShapePointsInNaviRef.CON2COGAtEgoBufferCumulReset = *p_CON2COG_Matrix;
}
#endif /* FIP_EVAL_SHAPE_POINTS */

/*************************************************************************************************************************
  Functionname:    FIP_b_NaviPathMapPlausible                                                                       */ /*!

  @brief           Evaluate if the NAVI Path is plausible

  @description     Evaluate if the NAVI Path is plausible. This meas that the NAVI data can be trusted 
                   (relevant for other FCT-functionality which considers the NAVI data as source of information). 
                   The NAVI Path might not be correct, since it is send by the navigation system and, hence, 
                   depends on the correctness of map in the navigation system. 
                   The plausibility of the number of lanes is determined based on the street type information.
  
  @startuml 
  Partition FIP_b_NaviPathMapPlausible
  Start
  	Note right: This function evaluates if the NAVI Path is plausible	
  	If (Number of lanes reported by the navigation is plausible) then (True)
  		- Navi path map is plausible
  	Else (False)
  		- Navi path map is not plausible
  	endif 
  Stop
  @enduml

  @return          b_NaviPathMapPlausible : information if reported NAVI path can be trusted    [TRUE, FALSE]

  @param[in]       *p_NaviData : Reference to incoming NAVI data
                      p_NaviData->b_MppNew                                                      [TRUE, FALSE]
  @param[in]       b_ValidNaviData : information if the NAVI data are valid                     [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SIMU : Config switch for FCT simulation
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
  @changed         03.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static boolean FIP_b_NaviPathMapPlausible(const t_NaviInputData *p_NaviData, const boolean b_ValidNaviData)
{
  /*! Set value to validity boolean (valid data means number of lanes exceeds zero and 
  valid street types for each segment). The plausibility bit, which is determined in this function, 
  considers more information and is more precise. Already checked in data validity part, now just recall results */
  boolean b_NaviPathMapPlausible = b_ValidNaviData;

  /*! Check if the number of lanes reported by the NAVI is plausible */
  boolean b_ValidNaviNumberLanes = FIPCheckNaviPathNumberLanes(p_NaviData);

  if(b_ValidNaviNumberLanes == FALSE)
  {
    b_NaviPathMapPlausible = FALSE;
  }

#ifdef FCT_SIMU
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.PlausiBits.b_MppNew = p_NaviData->b_MppNew;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.PlausiBits.b_QualityNavData = pt_FIP_ND_Output->b_NaviPathIsADASQuality;
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.PlausiBits.b_ValidNaviNumberLanes = b_ValidNaviNumberLanes;
#endif

  /*! Set meas freeze info */
  b_ValidNumLanesMeas = b_ValidNaviNumberLanes;

  return b_NaviPathMapPlausible;
}

#if (FIP_EVAL_SHAPE_POINTS)
/*************************************************************************************************************************
  Functionname:    FIPSamplePosNaviPath                                                                             */ /*!

  @brief           Determine the sample points of the NAVI path

  @description     Determine the sample points of the NAVI path (sample points for the entire NAVI path and sample points 
                   only for the edges of the NAVI path)
  
  @startuml 
  Partition FIPSamplePosNaviPath
  Start
  	Note right: This function determines the sample points of the navigation path
  	- Initialize the position samples in navigation path
  	- Initialize the length of the navigation path which is used for the approximation of the NAVI path
  	- Initialize the y-offset of the ego motion compensated navi path at the ego position
	  If (Length of navigation path is higher than zero) then (True)
  		- Find sample points for entire navigation path based on shape points
  	Else (False)
  	endif 
  Stop
  @enduml

  @return          -

  @param[in]       p_NaviShapePoint : Reference to structure containing the shape points and the spline interpolation 
                                      based on the shape points
  @param[in,out]   *pNaviPathPosSamples : Reference position samples of navi navi path

  @glob_in         -
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      FIPNaviDataEvaluated.f_SumLengthNaviPath        [0.f ... FCT_NAV_NUM_SEG*400.f]
  @glob_out        FIP_ND_Output_t : 
                      pt_FIP_ND_Output->f_NaviPathApproxLength              [0.f ... FCT_NAV_NUM_SEG*400.f]
                      pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]

  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             FIP_EVAL_SHAPE_POINTS == TRUE
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         03.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPSamplePosNaviPath(const FIPNaviShapePointEgo_t * p_NaviShapePoint, SLATE_t_PosSamples *pNaviPathPosSamples)
#else
/*************************************************************************************************************************
  Functionname:    FIPSamplePosNaviPath                                                                             */ /*!

  @brief           Determine the sample points of the NAVI path

  @description     Determine the sample points of the NAVI path (sample points for the entire NAVI path and sample points 
                   only for the edges of the NAVI path)
  
  @startuml 
  Partition FIPSamplePosNaviPath
  Start
  	Note right: This function determines the sample points of the navigation path
  	- Initialize the position samples in navigation path
  	- Initialize the length of the navigation path which is used for the approximation of the NAVI path
  	- Initialize the y-offset of the ego motion compensated navi path at the ego position
	  If (Length of navigation path is higher than zero) then (True)
  		- Find sample points for entire navigation path based on shape points
  	Else (False)
  	endif 
  Stop
  @enduml

  @return          -

  @param[in]       *p_NaviData : Reference to incoming NAVI data
  @param[in,out]   *pNaviPathPosSamples : Reference to position samples of navi path

  @glob_in         -
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      FIPNaviDataEvaluated.f_SumLengthNaviPath        [0.f ... FCT_NAV_NUM_SEG*400.f]
  @glob_out        FIP_ND_Output_t : 
                      pt_FIP_ND_Output->f_NaviPathApproxLength              [0.f ... FCT_NAV_NUM_SEG*400.f]
                      pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]

  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         05.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPSamplePosNaviPath(const t_NaviInputData *p_NaviData, SLATE_t_PosSamples *pNaviPathPosSamples)
#endif
{
#if (FCT_CFG_COURSE_PREDICTION)
  /*! Initialization of position samples in NAVI path (sample points for the entire NAVI path and 
      sample points only for the edges of the NAVI path) */
  CP_v_InitPosSamples(pNaviPathPosSamples);
#endif

  /*! Initialization of the length of the NAVI path which is used for the approximation of the NAVI path; 
  f_LengthNaviPathApprox is set in FIPFindPosSamplesInNaviPath(...)/FIPFindPosSamplesInNaviPathShapePoint(...) */
  pt_FIP_ND_Output->f_NaviPathApproxLength = 0.f;
#if FIP_EVAL_SHAPE_POINTS
  /*! Initialization of the y-offset of the ego motion compensated navi path at the ego position; 
      f_YOffsetEgoCompAtOrig is set in FIPFindPosSamplesInNaviPathShapePoint */
  pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig = 0.f;
#endif

  /*! Find sample points only, if length if NAVI path higher zeros */
  if(FIPNaviDataEvaluated.f_SumLengthNaviPath > C_F32_DELTA)
  {
#if (!FIP_EVAL_SHAPE_POINTS)
    /*! Sample points for entire NAVI path (equidistant sample points) */
    FIPFindPosSamplesInNaviPath(pNaviPathPosSamples, p_NaviData, FIP_NAVI_MAX_NB_SAMPLES);
#else
    /*! Sample points for entire NAVI path based on shape points (equidistant sample points) */
    FIPFindPosSamplesInNaviPathShapePoint(pNaviPathPosSamples, p_NaviShapePoint);
#endif
  }

  /*! Determine if the NAVI path "moves" much between two cycles, i.e. the NAVI path is unstable  - 
      This was to be used in evaluating FIPNaviDataEvaluated.b_NaviPathApproxPlausible in the function FIPPropNaviPathBasedOnApprox 
      *pbHighDiffYSampleNaviPath = FIPGetHighNaviPathMovement(pNaviPathPosSamples, &(LastNaviPathPosSamples)); */
}

#if (FIP_EVAL_SHAPE_POINTS)
/*************************************************************************************************************************
  Functionname:    FIPFindPosSamplesInNaviPathShapePoint                                                            */ /*!

  @brief           Find the sample points (position samples) in the NAVI path based on a given spline interpolation of 
                   shape points

  @description     Find the sample points (position samples) in the NAVI path based on a given spline interpolation of 
                   shape points
                   Spline representation: pf_ParaA, pf_ParaB, pf_ParaC, pf_ParaD: each parameter has an entry for each 
                   segment according to
                      y = pf_ParaA[i] + pf_ParaB[i] * (x - x_i) + pf_ParaC[i]*(x - x_i)^2 + pf_ParaD[i]*(x - x_i)^3 
                      for x in [x_i x_(i+1)]
                      i = 0 till (number of segments - 1)
  
  @startuml 
  Partition FIPFindPosSamplesInNaviPathShapePoint
  Start
	  Note right: This function finds the sample points (position samples) in the navigation path
	  - Determine the X-distance increment between the different sample points
  	- Set the distance to the first sample from the origin
  	- Consider only sample points below a distance threshold
  	- Set the first sample point to the displaced ego position
  	- Set X-Position of the sample point relative to the beginning of the segment
  	- Set Y-position of the sample point corresponding to x = 0 
  	- Set the index of the next sample to 1
  	- Initialize length of sampled navigation path
  
	  If (Spline is valid and have at leaset one shape point) then (True)
  		If(Spline of segment is valid) then (True)
			- Compute X-Position of the sample point relative to the beginning of the segment
			- Compute Y-position of the sample point
  			- Find the samples in each navigation path segment 
  		Else (False)
  		Endif
  	Else (False)
  	endif
  	
	  - Set the approximation length used in navigation path
	  - Set the number of sample points
	  - Set the y-offset of the ego motion compensated NAVI path at the ego position
  	- Shift the interpolated sample generated using the spline by Y displacement at x=0
  Stop
  @enduml

  @return          -

  @param[out]      p_Samples : Reference to structure that will hold the samples generated along the NAVI path in this function
  @param[in]       p_NaviShapePoint : Reference to structure containing the shape points and the spline interpolation based 
                                      on the shape points
                      af_XPosShapePointEgoRef[i] with i = 0           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      af_ParaA[i]                                     [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                      af_ParaB[i]                                     [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                      af_ParaC[i]                                     [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                      af_ParaD[i]                                     [-100.f ... 100.f]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                      b_SplineValid                                   [TRUE, FALSE]
                      ui_NumberOfShapePoints                          [0u ... FIP_NUM_NAVI_PATH_SHAPE_POINTS]
                      ab_SegmentSplineValid[i]                        [TRUE, FALSE]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h

  @glob_in         -
  @glob_out        FIP_ND_Output_t : 
                      pt_FIP_ND_Output->f_NaviPathApproxLength              [0.f ... FCT_NAV_NUM_SEG*400.f]
                      pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]

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
  @changed         03.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPFindPosSamplesInNaviPathShapePoint(SLATE_t_PosSamples * p_Samples, const FIPNaviShapePointEgo_t * p_NaviShapePoint)
{
  uint8 i, j;
  float32 f_DistMax, f_DeltaX;
  float32 f_XInc, f_XPosSample_j, f_YPosSample_j, f_XPosLocal;
  float32 f_LengthNaviPathApprox, f_DiffXSqr, f_DiffYSqr;

  /*! Determine the X-distance increment between the different sample points */
  f_XInc = FIP_NAVI_MAX_SAMPLEDIST / ((float32) FIP_NAVI_MAX_NB_SAMPLES);

  /*! Set the distance to the first sample from the origin 
      (x-position of the second sample point; the first sample point is the ego vehicle position at the point (0,0)) */
  f_XPosSample_j = f_XInc;

  /*! Consider only sample points below a distance threshold -> can be refined for example by a detected beginning of a s-curve 
    (s-curves can't be described by the current trajectory model) */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  f_DistMax = 2.f * (*(pt_FIP_ND_Input->t_LAInput.pt_MovingObjPickUpRange));
#else
  f_DistMax = 2.f * MAX_FLOAT(FIP_PICK_UP_RANGE_DEFAULT_MIN, FIP_PICK_UP_RANGE_DEFAULT_TIMEGAP * EGO_SPEED_X_OBJ_SYNC);
  f_DistMax = MIN_FLOAT(f_DistMax, RW_FCT_MAX);
#endif

  /*! Set the first sample point to the displaced ego position (x = 0, y = compute) */
  p_Samples->fx[0u] = 0.f;
  p_Samples->fy[0u] = 0.f;

  /*! X-Position of the sample point relative to the beginning of the segment */
  f_XPosLocal = p_Samples->fx[0u] - p_NaviShapePoint->af_XPosShapePointEgoRef[0u];

  /*! Y-position of the sample point corresponding to x = 0 */
  if (p_NaviShapePoint->af_XPosShapePointEgoRef[0u] > 0.f)
  {
    p_Samples->fy[0u] = p_NaviShapePoint->af_ParaA[0u];
  }
  else
  {
    p_Samples->fy[0u] = FIP_f_CalcSampleYPosForSpline(f_XPosLocal, p_NaviShapePoint->af_ParaA[0u], 
      p_NaviShapePoint->af_ParaB[0u], p_NaviShapePoint->af_ParaC[0u], p_NaviShapePoint->af_ParaD[0u]);
  }

  /*! Set the index of the next sample to 1 (first sample with index 0 is already computed ) */
  j = 1u;
  /*! Set x-Dist to next sample point as default to 1 */
  f_DeltaX = 1.f;

  /*! Initialize length of sampled NAVI path */
  f_LengthNaviPathApprox = 0.f;

  /*! Find the samples in each NAVI path segment 
      Condition for breaking up of the loop:
        X-Dist to next sample point is lower or equal zero
        Distance to sample point is lower than a threshold */
  if( (p_NaviShapePoint->b_SplineValid == TRUE) && (p_NaviShapePoint->ui_NumberOfShapePoints > 0u) )
  {
    /*! Loop starts in the segment where the ego vehicle is */
    for(i = 0u; i < p_NaviShapePoint->ui_NumberOfShapePoints - 1u; i++)
    {
      /*! Only if parameters of spline for this segment are valid. 
          Parameters are invalid if the x-distance between the corresponding sample points is <= 0 */
      if(p_NaviShapePoint->ab_SegmentSplineValid[i] == TRUE)
      {
        while ( (j < FIP_NAVI_MAX_NB_SAMPLES) &&
                (f_XPosSample_j >= p_NaviShapePoint->af_XPosShapePointEgoRef[i]) &&
                (f_XPosSample_j < p_NaviShapePoint->af_XPosShapePointEgoRef[i + 1u]) &&
                (f_XPosSample_j < f_DistMax) &&
                (f_DeltaX > C_F32_DELTA)
              )
        {
          /*! X-Position of the sample point relative to the beginning of the segment */
          f_XPosLocal = f_XPosSample_j - p_NaviShapePoint->af_XPosShapePointEgoRef[i];

          /*! Y-position of the sample point */
          f_YPosSample_j = FIP_f_CalcSampleYPosForSpline(f_XPosLocal, p_NaviShapePoint->af_ParaA[i], 
            p_NaviShapePoint->af_ParaB[i], p_NaviShapePoint->af_ParaC[i], p_NaviShapePoint->af_ParaD[i]);
          
          /*! Consider sample point only if x-distance between sample points higher zero */
          f_DeltaX = f_XPosSample_j - p_Samples->fx[j - 1u];
          if(f_DeltaX > C_F32_DELTA)
          {
            /*! Set new sample point */
            p_Samples->fx[j] = f_XPosSample_j;
            p_Samples->fy[j] = f_YPosSample_j;
            /*! Increment distance to next sample point */
            f_XPosSample_j += f_XInc;
            /*! Increment length of sampled NAVI path */
            f_DiffXSqr = SQR(p_Samples->fx[j] - p_Samples->fx[j - 1u]); /*!< Remark: j initialized to 1u */
            f_DiffYSqr = SQR(p_Samples->fy[j] - p_Samples->fy[j - 1u]); /*!< Remark: j initialized to 1u */
            if((f_DiffXSqr + f_DiffYSqr) > C_F32_DELTA) /*!< Only if length-increment higher zero */
            {
              f_LengthNaviPathApprox += SQRT(f_DiffXSqr + f_DiffYSqr); 
            }
            /*! Increment index of next sample point */
            j++;
          } /* END IF (f_DeltaX > C_F32_DELTA) */
        } /* END of WHILE */
      } /* END IF (p_NaviShapePoint->ab_SegmentSplineValid[i] == TRUE) */
    
      /* Condition for breaking up of the loop:
          X-Dist to next sample point is lower or equal zero
          Distance to sample point is greater than a threshold */
      if((f_DeltaX < C_F32_DELTA) || (f_XPosSample_j >= f_DistMax))
      {
        break;
      }

    } /* END FOR LOOP (i = 0u; i < p_NaviShapePoint->ui_NumberOfShapePoints - 1u; i++) */
  } /* END IF ( (p_NaviShapePoint->b_SplineValid == TRUE) && (p_NaviShapePoint->ui_NumberOfShapePoints > 0u) ) */

  /*! Length of the NAVI path which is used for the approximation of the NAVI path */
  pt_FIP_ND_Output->f_NaviPathApproxLength = f_LengthNaviPathApprox;

  /*! Set the number of sample points */
  p_Samples->nb_samples = j;

  /*! Set the y-offset of the ego motion compensated NAVI path at the ego position */
  pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig = p_Samples->fy[0];

  /* Shift the interpolated sample generated using the spline by Y displacement at x=0 */
  for (i = 0; i < p_Samples->nb_samples; i++)
  {
    p_Samples->fy[i] = p_Samples->fy[i] - pt_FIP_ND_Output->f_YOffsetEgoCompAtOrig;
  }
}
#endif 

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_v_NaviProcessNewTree                                                                         */ /*!

  @brief           If the MMP is rebuild or if the error in the ego compensated navi tree is too high, 
                   the internal navi tree needs to be rebuild. The Shape points are found using the incoming NAVI segment data 
                   and the new tree is build from it.

  @description     If the MMP is rebuild or if the error in the ego compensated navi tree is too high, 
                   the internal navi tree needs to be rebuild. The Shape points are found using the incoming NAVI segment data 
                   and the new tree is build from it.
                   In all cases just reset the shape points in NAVI reference shape point buffer and build afresh since we don't have 
                   intermediate cumulative motion to update CON2COG for using any history information. 
                   The ego motion transformation is initialized.
  
  @startuml 
  Partition FIP_v_NaviProcessNewTree
  Start
  	Note right: This function is used to build new navigation tree using shape points	
	  - Set ego to the 0th segment
  	- Repopulate shape point segment information in navi reference
  	
	  If (tree reset is being done on algorithm request) then (True)
  		- Use remaining distance in current segment for first segment length
  	Else (False)
  	Endif

  	- Set the new buffer index
  	- Store the current segment initial data
  	- Determine the shape points 
  	- Reset cumulative EGO motion data structures 
  	- Initialize navigation to ego reference matrix with current state of EGO motion data
  	- Reset shape point history difference buffer
  Stop
  @enduml

  @return          -

  @param[in]       p_FCTSEN_pNaviData : Reference to incoming NAVI segment data
                      u_NumUsedSegments                         [0u ... FCT_NAV_NUM_SEG[
                      Segments[i] with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        f_AnglePrevSeg                          [-180.f ... 180.f] rad
                        f_Length                                [0f  400f] m
                        f_Curvature                             [-1f  1f]
                        u_ProbEgoTakesBranch                    [0u  100] %
                        u_SegmentID                             [full range of uint8]
  @param[out]      p_CON2COG_Matrix : Reference to transformation matrix between NAVI reference coordinates and EGO reference coordinates
                      f00                                         [-1.f ... 1.f]
                      f10                                         [-1.f ... 1.f]
                      f02                                         [-1.f ... 1.f]
                      f12                                         [-1.f ... 1.f]
  @param[in]       b_ResetTree : Boolean indication if the new tree is being processed due to reset arising from algorithm
                                                                                    [TRUE, FALSE]

  @glob_in         FIPShapePointsInNaviRef : Data structure containing shape points in NAVI reference coordinate system
                      ui_IndexCurrentSegEgo                 [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                      af_AlphaShapePointNaviRef[i]          [-180.f ... 180.f] rad
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      af_LengthShapePointNaviRef[i]         [0.f ... 400.f] m
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      af_CurvatureShapePointNaviRef[i]      [-1.f ... 1.f]
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      au_ProbTakeBranchShapePointNaviRef[i] [0u ... 100u] %
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      ui_IndexLastSPInBuffer                [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                      ui_CountSegmentForced                 [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
  @glob_in         FIPGlobalNaviInfo : struct containing global NAVI path data (need to be available beyond one cycle)
                      NaviEGOSegment
                        f_Length                                  [0.f ... 400.f] m
                        f_DistInNaviSeg0                          [0.f ... 400.f] m
                      NaviDataSegmentChange
                      af_LengtSeg0Seg1SegmentChange[i]            [0.f ... 400.f] m
                        with i in [SEGMENT_0, SEGMENT_1] and SEGMENT_0, SEGMENT_1 in fip_navi_data_process.h
                      au_SegmentIDSegmentChange[i]                [full range of uint8]
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
  @glob_in         FIPNaviEgoTreeCumul : Accumulated EGO motion in current NAVI tree, relative to current origin in NAVI ref (SP0)
                      f_abs_angle                               [-PI ... PI] rad
                      f_rel_dx                                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f_rel_dy                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         FIPNaviEgoBufferCumul : Accumulated EGO motion in shape point buffer, relative to next new origin (usually SP3)
  @glob_out        FIPShapePointsInNaviRef : Data structure containing shape points in NAVI reference coordinate system
                      af_DiffXPosHistorySPNaviRef[i]        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      af_DiffYPosHistorySPNaviRef[i]        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        with i in [0u ... FIP_NUM_NAVI_REF_SEGMENTS[ and FIP_NUM_NAVI_REF_SEGMENTS in fip_navi_data_process.h
                      ui_IndexDiffPosHistorySPNaviRef       [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                      f_AvgEGOPathDiff                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @c_switch_part   FCT_SIMU : FCT simulation switch
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
  @changed         03.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIP_v_NaviProcessNewTree(const t_NaviInputData * p_FCTSEN_pNaviData, GDBTrafoMatrix2D_t * p_CON2COG_Matrix, boolean b_ResetTree)
{
  uint8 i;
  /* On initialization, or new tree indication or reset due to high difference between NAVI tree and EGO Path*/
  uint8 ui_IdxSegNaviOrig = 0u;
  uint8 ui_IdxSegNaviEnd = p_FCTSEN_pNaviData->u_NumUsedSegments;

  /* Origin at zero  - build a tree afresh */
  float32 f_XPosOrigin = 0.f;
  float32 f_YPosOrigin = 0.f; 

  /* This is going to be a new tree so EGO will be in 0th segment */
  FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo = 0u;
  
  /*! Repopulate FIPShapePointsInNaviRef segment information since a new TREE is being processed, this has to be done before shape point computation since it will be used there */
  for (i = 0; i < (ui_IdxSegNaviEnd); i++)
  {
    FIPShapePointsInNaviRef.af_AlphaShapePointNaviRef[i] = DEG2RAD(p_FCTSEN_pNaviData->Segments[i].f_AnglePrevSeg);
    FIPShapePointsInNaviRef.af_LengthShapePointNaviRef[i] = p_FCTSEN_pNaviData->Segments[i].f_Length;
    FIPShapePointsInNaviRef.af_CurvatureShapePointNaviRef[i] = p_FCTSEN_pNaviData->Segments[i].f_Curvature;
    FIPShapePointsInNaviRef.au_ProbTakeBranchShapePointNaviRef[i] = p_FCTSEN_pNaviData->Segments[i].u_ProbEgoTakesBranch;
  }

  if (b_ResetTree == TRUE)
  {
    /* In case tree reset is being done on algorithm request then use remaining distance in current segment for first segment length */
    FIPShapePointsInNaviRef.af_LengthShapePointNaviRef[0u] = FIPGlobalNaviInfo.NaviEGOSegment.f_Length - FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0;
  }
  /* Set the new buffer index */
  /* -1 since counting starts at 0 */
  FIPShapePointsInNaviRef.ui_IndexLastSPInBuffer = p_FCTSEN_pNaviData->u_NumUsedSegments + 1u;    /* Number of SPs is one more than number of segments */
  FIPShapePointsInNaviRef.ui_IndexCurrentSegEgo = 0u;
  FIPShapePointsInNaviRef.ui_CountSegmentForced = 0u;
  
  /*! Store the current segment initial data */
  FIPGlobalNaviInfo.NaviEGOSegment.f_AnglePrevSeg = p_FCTSEN_pNaviData->Segments[0u].f_AnglePrevSeg;
  FIPGlobalNaviInfo.NaviEGOSegment.f_Length = FIPShapePointsInNaviRef.af_LengthShapePointNaviRef[0u];
  FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature = p_FCTSEN_pNaviData->Segments[0u].f_Curvature;
  FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0 = 0.f;

  /*! Determine the shape points */
  FIPGetNaviRefShapePoints(ui_IdxSegNaviOrig, ui_IdxSegNaviEnd, &FIPShapePointsInNaviRef, f_XPosOrigin, f_YPosOrigin);

  /*! Set the NAVI data when entering the new tree */
#if ((FCT_NAVI_INPUT_INTFVER <= 4u) || (FIP_NAV_USE_SEG_ID == SWITCH_OFF))
  FIPGlobalNaviInfo.NaviDataSegmentChange = *p_FCTSEN_pNaviData;
#else
#ifdef FCT_SIMU
  if(b_UseInterfaceWithoutSegmentID == TRUE)
  {
    FIPGlobalNaviInfo.NaviDataSegmentChange = *p_FCTSEN_pNaviData;
  }
  else
  {
    FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_0] = p_FCTSEN_pNaviData->Segments[SEGMENT_0].f_Length;
    FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_1] = p_FCTSEN_pNaviData->Segments[SEGMENT_1].f_Length;
    for (i = 1u; i < (uint8)FCT_NAV_NUM_SEG; i++)
    { 
      FIPGlobalNaviInfo.au_SegmentIDSegmentChange[i] = p_FCTSEN_pNaviData->Segments[i].u_SegmentID;
    }
  }
#else
  FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_0] = p_FCTSEN_pNaviData->Segments[SEGMENT_0].f_Length;
  FIPGlobalNaviInfo.af_LengtSeg0Seg1SegmentChange[SEGMENT_1] = p_FCTSEN_pNaviData->Segments[SEGMENT_1].f_Length;
  for (i = 1u; i < (uint8)FCT_NAV_NUM_SEG; i++)
  { 
    FIPGlobalNaviInfo.au_SegmentIDSegmentChange[i] = p_FCTSEN_pNaviData->Segments[i].u_SegmentID;
  }
#endif
#endif
  /* Reset cumulative EGO motion data structures */
  FIP_v_InitEgoCumulStructure(&FIPNaviEgoTreeCumul);
  FIP_v_InitEgoCumulStructure(&FIPNaviEgoBufferCumul);
  
  /* Initialize CON2COG with current state of EGO motion data - This section must be after FIPNaviEgoTreeCumul is updated from Buffer */
  p_CON2COG_Matrix->f00 = COS_HD_(-FIPNaviEgoTreeCumul.f_abs_angle);
  p_CON2COG_Matrix->f10 = SIN_HD_(-FIPNaviEgoTreeCumul.f_abs_angle);
  
  /* Translation matrix terms*/
  p_CON2COG_Matrix->f02 = FIPNaviEgoTreeCumul.f_rel_dx;
  p_CON2COG_Matrix->f12 = FIPNaviEgoTreeCumul.f_rel_dy;

  for (i = 0u; i < FIP_NUM_HIST_SHAPE_POINTS; i++)
  {
    /* Reset shape point history difference buffer */
    FIPShapePointsInNaviRef.af_DiffXPosHistorySPNaviRef[i] = 0.f;
    FIPShapePointsInNaviRef.af_DiffYPosHistorySPNaviRef[i] = 0.f;
  }
  FIPShapePointsInNaviRef.ui_IndexDiffPosHistorySPNaviRef = 0u;
  FIPShapePointsInNaviRef.f_AvgEGOPathDiff = 0.f;

}
#endif

#if (FIP_EVAL_SHAPE_POINTS == SWITCH_OFF)
/*************************************************************************************************************************
  Functionname:    FIPFindPosSamplesInNaviPath                                                                      */ /*!

  @brief           Find the sample points (position samples) in the NAVI path

  @description     Find the sample points (position samples) in the NAVI path. This is based on the shape points in the 
                   navi input data. The shape point information is transformed based on angle, length  and curvature. 
                   The length of the navi path is restricted to a multiple of the required pick up range.
  
  @startuml 
  Partition FIPFindPosSamplesInNaviPath
  Start
  	Note right: This function is used to find the sample points (position samples) in the NAVI path	
	  - Determine the length increment between the different sample points
  	- Set the distance to the first sample from the origin
  	- Set the length to the current segment start to 0
  	- Set the accumulated angle orientation to  current segment start
  	- Set start point of the first segment to the origin (x = 0, y = 0)
  	- Set the first sample point to the origin (x = 0, y = 0)
  	- Consider only sample points below a distance threshold
  	- Find the samples in each NAVI path segment 
  	- Determine the angle from the previous segment to the current segment in [rad]
  	- Calculate the sin/cos of the accumulated orientation of the starting point of the segment 
  	- Determine Navi path curvature type
  	- Find the next sample point 
  	- Determine the coordinates of the starting point of the next segment
	  - Determine the distance to the starting point of the next segment
  	- Determine the accumulated orientation of the starting point of the next segment
  	- Set angle to next segment to value for next cycle
  	- Use Length of the NAVI path for the approximation of the NAVI path
  	- Set the number of sample points; 
  Stop
  @enduml

  @return          -

  @param[in,out]   *pSamples : Reference to the position samples to fill
                      fx[0]                                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fy[0]                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      nb_samples                                  [0u ... CAL_MAX_NB_TRAJ_SAMPLES[
  @param[in]       *p_NaviData : Reference to incoming navi data
                      Segments[i] with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        f_AnglePrevSeg                            [-180.f ... 180.f] rad
                        f_Curvature                               [-1.f ... 1.f]
                      u_NumUsedSegments                           [0u ... FCT_NAV_NUM_SEG[
  @param[in]       uiMaxNumSamples : Maximal number of samples              [0u ... CAL_MAX_NB_TRAJ_SAMPLES[

  @glob_in         FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      f_SumLengthNaviPath                         [0.f ... FCT_NAV_NUM_SEG*400.f]
  @glob_out        FIP_ND_Output_t : 
                      f_NaviPathApproxLength              [0.f ... FCT_NAV_NUM_SEG*400.f]

  @c_switch_part   -
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             FIP_EVAL_SHAPE_POINTS == FALSE
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         03.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPFindPosSamplesInNaviPath(SLATE_t_PosSamples *pSamples, const t_NaviInputData *p_NaviData, const uint8 uiMaxNumSamples)
{
  uint8 i, j;
  float32 f_LengthNaviPathAccum;
  float32 fXPosTemp, fYPosTemp, fDeltaX;
  float32 fAlpha;
  float32 fAccumOrientPrevSegments, fSinAngleAccu, fCosAngleAccu;
  float32 fXSegmentStart, fYSegmentStart;
  float32 fLengthInc, fDistSample_j;
  float32 fXSegmentStartBefore, fYSegmentStartBefore;
  float32 fDistMax;
  float32 f_AnglePrevSeg;
  float32 f_Abs_AnglePrevSeg, f_AbsAnglePrevSeg;
  boolean b_ConditionsFullfilled; 

  FIPNaviPathCurvatureType_t t_NaviPathCurvatureType;

  float32 fLengthSampleRel_j;     /* distance of the next sample point relative to starting point of the segment */

  /*! Determine the length increment between the different sample points */
  fLengthInc = MINMAX(FIP_NAVI_MIN_SAMPLEDIST, FIP_NAVI_MAX_SAMPLEDIST, FIPNaviDataEvaluated.f_SumLengthNaviPath) / ((float32) FIP_NAVI_MAX_NB_SAMPLES);

  /*! Set the distance to the first sample from the origin */
  fDistSample_j = fLengthInc;

  /*! Set the length to the current segment start to 0 */
  f_LengthNaviPathAccum = 0.f;
  /*! Set the accumulated angle orientation to  current segment start */
  fAccumOrientPrevSegments = 0.f;
  /*! Set start point of the first segment to the origin (x = 0, y = 0) */
  fXSegmentStart = 0.f;
  fYSegmentStart = 0.f;
  /*! Set the first sample point to the origin (x = 0, y = 0) */
  pSamples->fx[0] = 0.f;
  pSamples->fy[0] = 0.f;

  /*! Set the index of the next sample to 1 (first sample with index 0 is the origin) */
  j = 1u;
  /*! Set x-Dist to next sample point as default to 1 */
  fDeltaX = 1.f;

  /*! Consider only sample points below a distance threshold -> can be refined for example by a detected beginning of a s-curve 
    (s-curves can't be described by the current trajectory model) */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  fDistMax = 2.f * (*(pt_FIP_ND_Input->t_LAInput.pt_MovingObjPickUpRange));
#else
  fDistMax = 2.f * MAX_FLOAT(FIP_PICK_UP_RANGE_DEFAULT_MIN, FIP_PICK_UP_RANGE_DEFAULT_TIMEGAP * EGO_SPEED_X_OBJ_SYNC);
  fDistMax = MIN_FLOAT(fDistMax, RW_FCT_MAX);
#endif

  /*! Find the samples in each NAVI path segment 
      Condition for breaking up of the loop:
        Angle between consecutive segments exceed threshold (it is very likely that the ego vehicle turns off from the road);
        X-Dist to next sample point is lower or equal zero
        Distance to sample point is lower than a threshold */
  
  f_AnglePrevSeg = p_NaviData->Segments[SEGMENT_0].f_AnglePrevSeg; /*!< Initialize angle to next segment for first segment */
  f_Abs_AnglePrevSeg = fABS(f_AnglePrevSeg);

  if((f_Abs_AnglePrevSeg < FIP_NAVI_VALID_PATH_MAX_ANGLE) && (fDeltaX > C_F32_DELTA) && (fDistSample_j < fDistMax))
  {
    b_ConditionsFullfilled = TRUE; 
  }
  else
  {
    b_ConditionsFullfilled = FALSE;
  }

  for(i = 0u; (i < p_NaviData->u_NumUsedSegments) && (b_ConditionsFullfilled == TRUE); i++)
  {
    /*! Determine the angle from the previous segment to the current segment in [rad] */
    fAlpha = DEG2RAD(f_AnglePrevSeg);

  
    /*! Calculate the sin/cos of the accumulated orientation of the starting point of the segment */
    fSinAngleAccu = SIN_HD_(fAccumOrientPrevSegments + fAlpha);
    fCosAngleAccu = COS_HD_(fAccumOrientPrevSegments + fAlpha);

    /* Determine Navi path curvature type */
    t_NaviPathCurvatureType = FIP_t_GetNaviPathCurvatureType(&p_NaviData->Segments[i]);

    /*! Find the next sample point as long as not the maximal number of sample points reached,
        the distance to the next sample point within the i-th segment,
        the x-dist to the next sample point exceeds zero,
        the distance to the sample point is lower than a threshold */
    while( (j < uiMaxNumSamples) && 
           (fDistSample_j > f_LengthNaviPathAccum) && 
           (fDistSample_j <= (f_LengthNaviPathAccum + p_NaviData->Segments[i].f_Length)) &&
           (fDeltaX > C_F32_DELTA) &&
           (fDistSample_j < fDistMax)
         ) 
    {
      /* determine the distance of the next sample point relative to starting point of the segment */
      fLengthSampleRel_j = fDistSample_j - f_LengthNaviPathAccum;

      /*! Find the coordinates of the sample point */
      FIPSamplePosAbsNaviPathArcRel(&fXPosTemp, &fYPosTemp, fLengthSampleRel_j, &p_NaviData->Segments[i], fCosAngleAccu, fSinAngleAccu, 
        fXSegmentStart, fYSegmentStart, t_NaviPathCurvatureType);
      /*! Consider sample point only, if distX further away than previous sample point (remark j >= 1) */
      fDeltaX = fXPosTemp - pSamples->fx[j - 1u];
      if(fDeltaX > C_F32_DELTA)
      {
        pSamples->fx[j] = fXPosTemp;
        pSamples->fy[j] = fYPosTemp;
        /*! Increment distance to next sample point */
        fDistSample_j += fLengthInc;
        /*! Increment index of next sample point */
        j++;
      }
    }

    /*! When all the sample points within a NAVI path segment are found, determine the coordinates of the starting point of the next segment */
    /*! First, determine the arc length of the starting point of the next segment (relative to the starting point of the last segment) */

    /*! Copy the stating point of the last segment to a local variable */
    fXSegmentStartBefore = fXSegmentStart;
    fYSegmentStartBefore = fYSegmentStart;

#if SLATE_CFG_NAVI_OBJ_LAT_DIST
    /*Store starting x,y-position of Each Segment in static variable*/
    f_FIP_NaviSegmentStartX[i] = fXSegmentStart;
    f_FIP_NaviSegmentStartY[i] = fYSegmentStart;
    f_FIP_NaviAccumPrevSegAngle[i] = fAccumOrientPrevSegments;
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST */

    /*! Determine the starting point of the next segment */
    FIPSamplePosAbsNaviPathArcRel(&fXSegmentStart, &fYSegmentStart, p_NaviData->Segments[i].f_Length, 
      &p_NaviData->Segments[i], fCosAngleAccu, fSinAngleAccu, fXSegmentStartBefore, fYSegmentStartBefore, t_NaviPathCurvatureType);

    /*! Determine the distance to the starting point of the next segment */
    f_LengthNaviPathAccum += p_NaviData->Segments[i].f_Length;

    /*! Determine the accumulated orientation of the starting point of the next segment */
    FIP_f_UpdateAccumOrientPrevSegments(&fAccumOrientPrevSegments, &p_NaviData->Segments[i], t_NaviPathCurvatureType);

    /*! Set angle to next segment to value for next cycle */
    if((i + 1u) < p_NaviData->u_NumUsedSegments)
    {
      f_AnglePrevSeg = p_NaviData->Segments[i + 1u].f_AnglePrevSeg;
    }

    f_AbsAnglePrevSeg = fABS(f_AnglePrevSeg);
    if((f_AbsAnglePrevSeg < FIP_NAVI_VALID_PATH_MAX_ANGLE) && (fDeltaX > C_F32_DELTA) && (fDistSample_j < fDistMax))
    {
      b_ConditionsFullfilled = TRUE; 
    }
    else
    {
      b_ConditionsFullfilled = FALSE;
    }
  }

  /*! Length of the NAVI path which is used for the approximation of the NAVI path */
  pt_FIP_ND_Output->f_NaviPathApproxLength = f_LengthNaviPathAccum;

  /*! Set the number of sample points */
  pSamples->nb_samples = j;
}
#endif /* FIP_EVAL_SHAPE_POINTS == SWITCH_OFF*/

/*************************************************************************************************************************
  Functionname:    FIPApproxNaviPath                                                                                */ /*!


  @brief           Approximation of the NAVI path by a second order polynomial

  @description     Approximation of the NAVI path by a second order polynomial (f(x) = fC0 + fC1*x + fC2*x^2)

  @startuml 
  Partition FIPApproxNaviPath
  Start
  	Note right: This function approximates the Navigation path by a second order polynomial	
  	- Approximation of the Navigation path by a second order polynomial 
  Stop
  @enduml

  @return          -

  @param[in]       *pPosSamples : reference to structure holding sample points of the NAVI path
                      fx                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fy                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      nb_samples               [0u ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         -
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      PolyNaviPathL2

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
  @changed         03.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPApproxNaviPath(const SLATE_t_PosSamples *pPosSamples)
{
  /*! Approximation of the NAVI path by a second order polynom (f(x) = fC0 + fC1*x + fC2*x^2) */
  CAL_v_CalcPointApproxPolyL2(&(FIPNaviDataEvaluated.PolyNaviPathL2), pPosSamples->fx, pPosSamples->fy, pPosSamples->nb_samples);
}

/*************************************************************************************************************************
  Functionname:    FIPPropNaviPathBasedOnApprox                                                                     */ /*!

  @brief           Determine properties of the NAVI path for which the approximated NAVI path is used

  @description     Determine properties of the NAVI path for which the approximated NAVI path is used,
                   e.g. the difference between the ego curve and the navi path and the error of the approximation.
  
  @startuml 
  Partition FIPPropNaviPathBasedOnApprox
  Start
	  Note right: This function determines properties of the navigation path for which the approximated navigation path is used	
	  - Find Difference between the approximated NAVI path and the ego curve
  	If (Average distance between ego and navi path \n is more than Maximum difference between the \n approximated NAVI path and EGO curve \n OR \n average of sum squared distance of navi path \n to polynomial is greater than Maximal mean \n difference between approximated and filtered NAVI path) then (True)
  		- Navi path approximation is not plausible
  	Else (False)	
  		- Navi path approximation is plausible
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      PolyNaviPathL2.
                       fC2             [-100.f ... 100.f]
                       fC1             [-100.f ... 100.f]
                      pt_FIP_RTE_Input->pf_EgoCurve                                  [-330.f ... 330.f]
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                       b_NaviPathApproxPlausible      [TRUE, FALSE]
                       f_NaviPathToPolySumSqDistAvg   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       b_NaviPathApproxPlausible      [TRUE, FALSE]
  @glob_out        FIP_ND_Output_t : 
                       f_EgoNaviPathErrDistAvg           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]

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
  @changed         05.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPPropNaviPathBasedOnApprox(void)
{
  float32 f_Abs_EgoNaviPathErrDistAvg;
  /*! Difference between the approximated NAVI path and the ego curve (Integral for x = 75m, FIP_NAVI_XDIST_APPROX_EGO_DIFF) normalized to x */
  pt_FIP_ND_Output->f_EgoNaviPathErrDistAvg = (((FIPNaviDataEvaluated.PolyNaviPathL2.fC2 - (0.5f * (*pt_FIP_RTE_Input->pf_EgoCurve))) * FIP_NAVI_XDIST_APPROX_EGO_DIFF * (2.f/3.f)) + 
                                                    FIPNaviDataEvaluated.PolyNaviPathL2.fC1) * FIP_NAVI_XDIST_APPROX_EGO_DIFF * 0.5f;

  /*! Difference between the NAVI path and the approximated NAVI path by a polynomial (relative to the length of NAVI path) */
  FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg = 0.f;
#if 0
  fNaviPathToPolySumSqDist = CAL_f_CalcSumSqDistance(&(FIPNaviDataEvaluated.PolyNaviPathL2), pPosSamples->fx, pPosSamples->fy, pPosSamples->nb_samples);
  if(pPosSamples->nb_samples > 0u) 
  {
    /* Separating IF conditions to avoid QAC errors */
    if(fABS(pPosSamples->fx[pPosSamples->nb_samples - 1u]) > C_F32_DELTA)
    {
      FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg = fNaviPathToPolySumSqDist / pPosSamples->fx[pPosSamples->nb_samples - 1u];
    }
  }
#endif

  /*! Determine if approximation of NAVI path (i.e. the filtered NAVI path) is plausible */
  /*! Set default value */
  FIPNaviDataEvaluated.b_NaviPathApproxPlausible = TRUE;
  f_Abs_EgoNaviPathErrDistAvg = fABS(pt_FIP_ND_Output->f_EgoNaviPathErrDistAvg);
  if( (f_Abs_EgoNaviPathErrDistAvg > FIP_NAVI_MAX_APPROX_EGO_DIFF) ||
    /* (bHighDiffYSampleNaviPath == TRUE) || - This flag is not used at the moment instead an equivalent concept is realised using f_EgoNaviPathErrDistAvg */
      (FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg > FIP_NAVI_MAX_MEAN_DIFF_APPROX_FILT)
    )
  {
    FIPNaviDataEvaluated.b_NaviPathApproxPlausible = FALSE;
  }
}

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPGeneralPropNaviPath                                                                           */ /*!

  @brief           Determine general properties of the NAVI path

  @description     Determine general properties of the NAVI path if !FIP_EVAL_SHAPE_POINTS
                   such as total length of the navi path, information if street type of navi path is highway, a country
                   road with one lane, if navi path is within city limits or the distance to the next exit left/right
  
  @startuml 
  Partition FIPGeneralPropNaviPath
  Start
	  Note right: This function determines general properties of the NAVI path	
	  - Determine the length of the navigation path and the mean curvature of the navigation path
	  - Determine the starting and ending relevant indices
	  - Calculate the Remaining length in current segment length;
  	- Sum length of all segments
  	- Calculate the difference of angel to fist shape point
  	- Determine if driving on a highway
  	- Determine if driving on a country road with one lane
  	- Determine if current navigation path indicates if EGO is in city limits
  	- Determine the distance to the next exit left/right
  	- Determine curviness probability measure
  Stop
  @enduml

  @return          -

  @param[in]       pFIPShapePointsInNaviRef : Reference to data structure containing shape points in NAVI reference coordinate system
  @param[in]       pFIPShapePointsInEgoRef : Reference to data structure containing shape points in EGO reference coordinate system
  @param[in]       *p_NaviData : Reference to incoming NAVI data
                      u_NumUsedSegments                         [0u ... FCT_NAV_NUM_SEG[
                      Segments[i] with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        f_Length                                [0.f ... 400.f] m
                        f_AnglePrevSeg                          [-180.f ... 180.f] rad

  @glob_in         pFIPShapePointsInNaviRef : Reference to data structure holding the shape points in NAVI reference
                      ui_IndexCurrentSegEgo        [0u ... FIP_NUM_NAVI_REF_SEGMENTS[
                      ui_NumberOfShapePoints       [0u ... FIP_NUM_NAVI_REF_SHAPE_POINTS[
                      af_XPosShapePointEgoRef[i]   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                      af_YPosShapePointEgoRef[i]   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
  @glob_in         FIPGlobalNaviInfo : struct containing global NAVI path data (need to be available beyond one cycle)
                      NaviEGOSegment
                        f_Length                    [0.f ... 400.f] m
                        f_Curvature                 [-1.f ... 1.f]
                        f_DistInNaviSeg0            [0.f ... 400.f] m
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      f_SumLengthNaviPath              [0.f ... FCT_NAV_NUM_SEG*400.f] m
                      f_DiffAngleToFistShapePoint      [-PI ... PI] rad
  @glob_out        FIP_ND_Output_t : 
                      b_NaviPathIsHighway                 [TRUE, FALSE]
                      b_NaviPathIsCountryRoadOneLane      [TRUE, FALSE]
                      b_NaviPathIsInCityLimits            [TRUE, FALSE]

  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             FIP_EVAL_SHAPE_POINTS == TRUE
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         05.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPGeneralPropNaviPath(const FIPNaviReferenceShapePoint_t* pFIPShapePointsInNaviRef, const FIPNaviShapePointEgo_t* pFIPShapePointsInEgoRef, const t_NaviInputData *p_NaviData)
#else
/*************************************************************************************************************************
  Functionname:    FIPGeneralPropNaviPath                                                                           */ /*!

  @brief           Determine general properties of the NAVI path

  @description     Determine general properties of the NAVI path if !FIP_EVAL_SHAPE_POINTS
                   such as total length of the navi path, information if street type of navi path is highway, a country
                   road with one lane, if navi path is within city limits or the distance to the next exit left/right
  
  @startuml 
  Partition FIPGeneralPropNaviPath
  Start
	  Note right: This function determines general properties of the NAVI path	
	  - Determine the length of the navigation path and the mean curvature of the navigation path
	  - Determine the starting and ending relevant indices
	  - Calculate the Remaining length in current segment length;
  	- Sum length of all segments
  	- Calculate the difference of angel to fist shape point
  	- Determine if driving on a highway
  	- Determine if driving on a country road with one lane
  	- Determine if current navigation path indicates if EGO is in city limits
  	- Determine the distance to the next exit left/right
  	- Determine curviness probability measure
  Stop
  @enduml
  @return          -

  @param[in]       *p_NaviData : Referenece to incoming NAVI data
                      u_NumUsedSegments                                     [0u ... FCT_NAV_NUM_SEG[
                      Segments[i] with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        f_Length                                            [0.f ... 400.f]  m

  @glob_in         
  @glob_out        FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      f_SumLengthNaviPath                                   [0.f ... FCT_NAV_NUM_SEG*400.f] m
  @glob_out        FIP_ND_Output_t : 
                      b_NaviPathIsHighway                 [TRUE, FALSE]
                      b_NaviPathIsCountryRoadOneLane      [TRUE, FALSE]
                      b_NaviPathIsInCityLimits            [TRUE, FALSE]

  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
  @c_switch_part   FCT_SIMU : FCT simulation enabling switch
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             FIP_EVAL_SHAPE_POINTS == FALSE
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         05.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void FIPGeneralPropNaviPath(const t_NaviInputData *p_NaviData)
#endif
{
  uint8 j; 
  uint8 ui_ValidIndexStart = 0u;
  uint8 ui_ValidIndexEnd = 0u; 
  float32 f_LengthSeg0Adapted = 0.f;
#if FIP_EVAL_SHAPE_POINTS
  float32 f_LengthSeg0ArcLength = 0.f;
  float32 f_AngleSend, f_AngleCalc;
#endif

  /*! Determine the length of the NAVI path and the mean curvature of the NAVI path (mean value relative to length of NAVI path) */
  FIPNaviDataEvaluated.f_SumLengthNaviPath = 0.f;

  /*! Determine the starting and ending relevant indices */
#if FIP_EVAL_SHAPE_POINTS
  if (pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo >= FIP_NUM_HIST_SHAPE_POINTS)
  {
    ui_ValidIndexStart = pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo - FIP_NUM_HIST_SHAPE_POINTS;
  }
  else
  {
    ui_ValidIndexStart = pFIPShapePointsInNaviRef->ui_IndexCurrentSegEgo;
  }
#else
  ui_ValidIndexStart = 0u;
#endif
  
#if FIP_EVAL_SHAPE_POINTS
  if (pFIPShapePointsInEgoRef->ui_NumberOfShapePoints >= 1u)
  {
    ui_ValidIndexEnd = pFIPShapePointsInEgoRef->ui_NumberOfShapePoints - 1u;
  } 
  else
  {
    ui_ValidIndexEnd = 0u;
  }
#else
  ui_ValidIndexEnd = p_NaviData->u_NumUsedSegments;
#endif

#if FIP_EVAL_SHAPE_POINTS
  /* Remaining length in current segment length is given by */
  f_LengthSeg0ArcLength = FIP_f_NaviGetArcLengthSeg(FIPGlobalNaviInfo.NaviEGOSegment.f_Length, FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature);
  f_LengthSeg0Adapted = (f_LengthSeg0ArcLength - FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0);
#else
  /* remaining length in ego segment is length of 0th segment */
#endif 

#if FIP_EVAL_SHAPE_POINTS
  /*! Use length of each segment to value send by the NAVI */
  if (pFIPShapePointsInEgoRef->ui_NumberOfShapePoints > 0u)
  {
    /* Adapted length of first segment */
    FIPNaviDataEvaluated.f_SumLengthNaviPath = f_LengthSeg0Adapted;

    for(j = ui_ValidIndexStart + 1u; 
      (j < ui_ValidIndexEnd) && (j < FCT_NAV_NUM_SEG); j++)
    {
      /* This is fed from Input NAVI data */
      FIPNaviDataEvaluated.f_SumLengthNaviPath += p_NaviData->Segments[j].f_Length;
    }
  }
#else
  for (j = (ui_ValidIndexStart + 1u); (j < ui_ValidIndexEnd) && (j < (uint8)FCT_NAV_NUM_SEG); j++)
  {
    FIPNaviDataEvaluated.f_SumLengthNaviPath += p_NaviData->Segments[j].f_Length;
  }
#endif
  
#if FIP_EVAL_SHAPE_POINTS
  FIPNaviDataEvaluated.f_DiffAngleToFistShapePoint = 0.f;
  if( (pFIPShapePointsInEgoRef->ui_NumberOfShapePoints >= 1u) && 
      (fABS(pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[1u]- pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[0u]) > C_F32_DELTA) 
    )
  {
    f_AngleSend = DEG2RAD(p_NaviData->Segments[0u].f_AnglePrevSeg);
    f_AngleCalc = ATAN2_(pFIPShapePointsInEgoRef->af_YPosShapePointEgoRef[1u]- pFIPShapePointsInEgoRef->af_YPosShapePointEgoRef[0u], 
                  pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[1u]- pFIPShapePointsInEgoRef->af_XPosShapePointEgoRef[0u]);
    FIPNaviDataEvaluated.f_DiffAngleToFistShapePoint = f_AngleSend - f_AngleCalc;
  }
#else
  /* FIPNaviDataEvaluated.f_DiffAngleToFistShapePoint not used if !FIP_EVAL_SHAPE_POINTS */
#endif
  
  /*! Determine if driving on a highway */
#if 0
  pt_FIP_ND_Output->b_NaviPathIsHighway = FIPNaviPathIsHighway(ui_ValidIndexStart, ui_ValidIndexEnd, p_NaviData);
#endif
  pt_FIP_ND_Output->b_NaviPathIsHighway = FIPNaviPathIsHighway(p_NaviData);
  /*! Determine if driving on a country road with one lane */
#if 0
  pt_FIP_ND_Output->b_NaviPathIsCountryRoadOneLane = FIPNaviPathIsCountryRoadOneLane(ui_ValidIndexStart, ui_ValidIndexEnd, p_NaviData);
#endif
  pt_FIP_ND_Output->b_NaviPathIsCountryRoadOneLane = FIPNaviPathIsCountryRoadOneLane(p_NaviData);
  /*! Determine if current NAVI path indicates if EGO is in city limits */
#if 0
  pt_FIP_ND_Output->b_NaviPathIsInCityLimits = FIPNaviPathIsInCityLimits(ui_ValidIndexStart, ui_ValidIndexEnd, p_NaviData);
#endif
  pt_FIP_ND_Output->b_NaviPathIsInCityLimits = FIPNaviPathIsInCityLimits(p_NaviData);

  /*! Determine the distance to the next exit left/right */
  FIPNaviSetDistNextExit(f_LengthSeg0Adapted, ui_ValidIndexStart, ui_ValidIndexEnd, p_NaviData, pt_FIP_ND_Output);

  /*! Determine curviness probability measure */
  FIP_SetProbCurveDiffNaviNear();
  FIP_SetProbCurveDiffNaviFar();
#if FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY
  /* Check if there is probabilty ego takes branch */
  pt_FIP_ND_Output->u_NaviBranchProb = FIP_u_UpdateBranchProbability();
#endif
#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  /*! Determine the distance to next high curvature change (curve entry/exit) */
  FIP_v_SetDistToHighCurvatureChangeNavi();
#endif

#ifdef FCT_SIMU
#if FIP_EVAL_SHAPE_POINTS
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.f_LengthSeg0 = f_LengthSeg0Adapted;
#else
  pt_FIP_ND_Output->t_FIPNaviPathDebugInfo.f_LengthSeg0 = p_NaviData->Segments[0].f_Length;
#endif
#endif
}

/*************************************************************************************************************************
  Functionname:    FIP_f_GetEgoNaviPathErrDistAvg                                                                   */ /*!

  @brief           Get difference between the approximated NAVI path and the ego curve

  @description     Get difference between the approximated NAVI path and the ego curve

  @startuml 
  Partition FIP_f_GetEgoNaviPathErrDistAvg
  Start
  	- Returns the difference between the approximated navigation path and the ego curve	
  Stop
  @enduml

  @return          fEgoNaviPathErrDistAvg : Difference between the approximated NAVI path and the ego curve 
                                                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  
  @param[in]       -

  @glob_in         FIPNaviDataEvaluated.f_EgoNaviPathErrDistAvg : Evaluated NAVI data to be used in other modules
                      f_EgoNaviPathErrDistAvg                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             FIPNaviDataEvaluated.f_EgoNaviPathErrDistAvg has to be determined (FIPPropNaviPathBasedOnApprox())
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         05.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
float32 FIP_f_GetEgoNaviPathErrDistAvg(void)
{
  return FIPNaviDataEvaluated.f_EgoNaviPathErrDistAvg;
}

/*************************************************************************************************************************
  Functionname:    FIP_f_GetNaviPathToPolySumSqDistAvg                                                              */ /*!

  @brief           Get measure of how "close" the NAVI path is to the approximated NAVI path (by a polynomial)

  @description     Get measure of how "close" the NAVI path is to the approximated NAVI path (by a polynomial) from 
                   global variable FIPNaviDataEvaluated
  
  @startuml 
  Partition FIP_f_GetNaviPathToPolySumSqDistAvg
  Start
	  - Returns how "close" the NAVI path is to the approximated NAVI path (by a polynomial)
  Stop
  @enduml

  @return          FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg : Measure how "close" the NAVI path is to the 
                   approximated NAVI path (by a polynomial)               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       -

  @glob_in         FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules
                      f_NaviPathToPolySumSqDistAvg   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                                                       
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg has to be determined (FIPPropNaviPathBasedOnApprox())
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         10.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
float32 FIP_f_GetNaviPathToPolySumSqDistAvg(void)
{
  return FIPNaviDataEvaluated.f_NaviPathToPolySumSqDistAvg;
}

#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIP_t_GetApproxNaviPath                                                                          */ /*!

  @brief           Get approximated NAVI path by a second order polynom (y = f(x) = fC0 + fC1 * x + fC2 * x^2)

  @description     Get approximated NAVI path by a second order polynom (y = f(x) = fC0 + fC1 * x + fC2 * x^2)
                   from global variable for evaluated NAVI data
  
  @startuml 
  Partition FIP_t_GetApproxNaviPath
  Start
	  - Returns approximated NAVI path by a second order polynom 
  Stop
  @enduml
  
  @return          FIPNaviDataEvaluated.PolyNaviPathL2 : Structure storing the second degree polynomial approximation of a trace
                      fC0           [-100.f ... 100.f]
                      fC1           [-100.f ... 100.f]
                      fC2           [-100.f ... 100.f]
                      isValid : Flag to indicate whether the trace polynomial is valid [TRUE, FALSE]

  @param[in]       -

  @glob_in         FIPNaviDataEvaluated : Evaluated NAVI data to be used in other modules PolyNaviPathL2
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation

  @pre             FIPNaviDataEvaluated.PolyNaviPathL2 has to be determined (FIPApproxNaviPath(const SLATE_t_PosSamples *pPosSamples))
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         10.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
CAL_t_TracePolyL2 FIP_t_GetApproxNaviPath(void)
{
  return FIPNaviDataEvaluated.PolyNaviPathL2;
}
#endif

/*************************************************************************************************************************
  Functionname:    FIP_v_CalcNaviPathApproxPosSample                                                                */ /*!

  @brief           Determine/Copy the position samples based on the filtered NAVI path (used for updating the ACC-trajectory)

  @description     Determine/Copy the position samples based on the filtered NAVI path (used for updating the ACC-trajectory)

  @startuml 
  Partition FIP_v_CalcNaviPathApproxPosSample
  Start
	  Note right: This function determines/Copies the position samples based on the filtered NAVI path (used for updating the ACC-trajectory)
	  - Determine the position samples based on the filtered navigation path
  	- Position samples based on spline interpolation or direct from navigation input data
  Stop
  @enduml

  @return          -

  @param[out]      pOutput : Position samples of the filtered NAVI path (used for updating the ACC-trajectory)
                      nb_samples                                         [0u ... CAL_MAX_NB_TRAJ_SAMPLES[

  @glob_in         FIPGlobalNaviInfo : struct containing global NAVI path data
                      NaviPathValidPosSamples
                        nb_samples                                                [0u ... CAL_MAX_NB_TRAJ_SAMPLES[
                        fy[i]                                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          with i in [0u ... CAL_MAX_NB_TRAJ_SAMPLES[ and CAL_MAX_NB_TRAJ_SAMPLES in cp_ext.h
                        fx[i]                                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                          with i in [0u ... CAL_MAX_NB_TRAJ_SAMPLES[ and CAL_MAX_NB_TRAJ_SAMPLES in cp_ext.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             FIPGlobalNaviInfo.NaviPathValidPosSamples has to be determined before (FIPSamplePosNaviPath)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         10.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_CalcNaviPathApproxPosSample(SLATE_t_PosSamples * pOutput)
{
  uint8 i;

  /*! Determine the position samples based on the filtered NAVI path */
  for(i = 0u; i < FIPGlobalNaviInfo.NaviPathValidPosSamples.nb_samples; i++)
  {
    /*! Position samples based on spline interpolation or direct from navi input data. But since the 20 (only valid samples are used here) interpolated 
        samples from the cubic spline serve as input to polynomial approximation, we can directly use them here.*/
    pOutput->fy[i] = FIPGlobalNaviInfo.NaviPathValidPosSamples.fy[i];
    pOutput->fx[i] = FIPGlobalNaviInfo.NaviPathValidPosSamples.fx[i];
  }
  pOutput->nb_samples = FIPGlobalNaviInfo.NaviPathValidPosSamples.nb_samples;
}

/*************************************************************************************************************************
  Functionname:    FIPGetNaviNumLaneAtDist                                                                          */ /*!

  @brief           Get number of lanes of the NAVI path at a given distance

  @description     Get number of lanes of the NAVI path at a given distance determining the corresponding segment and
                   taking information of global NAVI input structure
  
  @startuml 
  Partition FIPGetNaviNumLaneAtDist
  Start
	Note right: This function is used to get the number of lanes of the navigation  path at a given distance
	  If (Navi path is plausible) then (True)
		  If (the distance is zeros, for which the number of lanes should be determined) then (True)
  			- Number of lane is equal to provided by first segment
  		Else (False)
  			- Search for the segment and the number if lanes of the segment with the given distance
			- Iterate over the segments
			- Set the accumulated length of the already "iterated" NAVI path to zero
  		
		  If (the given distance is between the accumulated length of the already "iterated" NAVI path and the end of the new segment) then (True)
  			- Get number of lane of that segment
  		Else (False)
  		Endif
  		- Increase the already "iterated" path length by the length of the new segment
  		Endif
  	Else (False)
  	Endif
  	- Check plausibility of number of lanes selected
  Stop
  @enduml

  @return          -

  @param[out]      pu_NumLane : Number of lanes at the given distance of the NAVI path reported by the NAVI
                                                                            [0u ... FIP_NAV_MAX_VALID_LANE_NUM]
  @param[in]       fDist : Distance at which the number of lanes is given   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         FIPGlobalNaviInfo : structure containing global NAVI path data
                      NaviEGOSegment
                          f_Length                                          [0.f ... 400.f] m
                          f_Curvature                                       [-1.f ... 1.f] rad
                          f_DistInNaviSeg0                                  [0.f ... 400.f]  m
  @glob_in         FIP_ND_Output_t : 
                      b_NaviPathPlausible                 [TRUE, FALSE]
  @glob_in         pSLATE_NaviData : NAVI input data
                      Segments[i] with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        u_QuanLanes                                         [0u ... FIP_NAV_MAX_VALID_LANE_NUM[
                        u_NumUsedSegments                                   [0u ... FCT_NAV_NUM_SEG[
                        f_Length                                            [0.f ... 400.f] m

  @glob_out        -

  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
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
  @changed         10.02.2016

  @todo            This get function to be replaced with output in FIP_ND module. Currently used in LA directly

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIPGetNaviNumLaneAtDist(uint8 * pu_NumLane, const float32 fDist)
{
#if FIP_EVAL_SHAPE_POINTS
  float32 f_LengthSeg0ArcLength = 0.f;
#endif /* FIP_EVAL_SHAPE_POINTS */
  boolean bSegDist;
  uint8 i;
  float32 fLengthAccu, fLengthSeg;

  /*! Set default value */
  (*pu_NumLane) = 0u;

  /*! Determine segment in NAVI path which corresponds to the given distance fDist */
  if(FIP_pt_ND_GetNaviData()->b_NaviPathPlausible == TRUE)
  {
    /* This function is gets called from la_corridor_navi.c and hence the access function has to be used instead of local pointer.
    TODO remove the function call from LA and replace it with an IO structure */
    /*! If the distance is zeros, for which the number of lanes should be determined, use the first segment */
    if (fDist < C_F32_DELTA)
    {
      (*pu_NumLane) = pSLATE_NaviData->Segments[SEGMENT_0].u_QuanLanes;
    }
    else
    {
      /*! Search for the segment and the number if lanes of the segment with the given distance fDist */

      /*! Iterate over the segments */
      /*! Set the accumulated length of the already "iterated" NAVI path to zero */
      fLengthAccu = 0.f;
      bSegDist = FALSE;
      for (i = 0u; (i < pSLATE_NaviData->u_NumUsedSegments) && (bSegDist == FALSE); i++)
      {
        if (i == 0u)
        {
#if FIP_EVAL_SHAPE_POINTS
          f_LengthSeg0ArcLength = FIP_f_NaviGetArcLengthSeg(FIPGlobalNaviInfo.NaviEGOSegment.f_Length, FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature);
          fLengthSeg = (f_LengthSeg0ArcLength - FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0);
#else
          fLengthSeg = pSLATE_NaviData->Segments[0].f_Length;
#endif
        }
        else
        {
          fLengthSeg = pSLATE_NaviData->Segments[i].f_Length;
        }
        /*! If the given distance fDist is between the accumulated length of the already "iterated" NAVI path and the end of the new segment, 
            get the number of lanes of this segment */
        if( (fLengthAccu < fDist) && (fDist <= (fLengthAccu + fLengthSeg)) )
        {
          bSegDist = TRUE;
          (*pu_NumLane) = pSLATE_NaviData->Segments[i].u_QuanLanes;
        }
        /*! Increase the already "iterated" path length by the length of the new segment */
        fLengthAccu += fLengthSeg;
      } /* END FOR LOOP */
    } /* END IF (fDist < C_F32_DELTA) ELSE */
  } /* END IF (FIPNaviDataEvaluated.f_LengthNaviPathApprox > C_F32_DELTA) */
  /*! Check plausibility */
  if((*pu_NumLane) > FIP_NAV_MAX_VALID_LANE_NUM)
  {
    (*pu_NumLane) = 0u;
  }
}

#if SLATE_CFG_NAVI_OBJ_LAT_DIST
/*************************************************************************************************************************
  Functionname:    FIP_v_LateralDistToNaviTraj                                                                          */ /*!

  @brief          Update the Orthogonal Lateral Distance between Object and corresponding postion on Navi Trajectory

  @description    Calculates the Orthogonal Lateral Distance from Object postion to corresponding position on Navi Trajectory
                  and update the value.

  @param[out]     f_NaviLatDist : Lateral Distance of Object to corresponding position on Navi Trajectory
                                                                            [0u ... FIP_MAX_DIST_TEN_HIGHWAY_LANES]
  @param[in]       t_ObjNr : Object ID whose dist 2 Navi trajectory to be calculated.

  @glob_in         FIPGlobalNaviInfo : structure containing global NAVI path data
                      NaviEGOSegment
                          f_Length                                          [0.f ... 400.f] m
                          f_Curvature                                       [-1.f ... 1.f] rad
                          f_DistInNaviSeg0                                  [0.f ... 400.f]  m
  @glob_in         FIP_ND_Output_t : 
                      b_NaviPathPlausible                 [TRUE, FALSE]
  @glob_in         pSLATE_NaviData : NAVI input data
                      Segments[i] with i in [0u ... FCT_NAV_NUM_SEG[ and FCT_NAV_NUM_SEG in Rte_SWCEmAdapt_Type.h
                        u_QuanLanes                                         [0u ... FIP_NAV_MAX_VALID_LANE_NUM[
                        u_NumUsedSegments                                   [0u ... FCT_NAV_NUM_SEG[
                        f_Length                                            [0.f ... 400.f] m

  @glob_out        -

  @c_switch_part   FIP_EVAL_SHAPE_POINTS : Switch to enable the shape point evaluation
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
  @changed         15.10.2019

  @todo            -

  @author          Dyamana Gouda |  Dyamana.gouda@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_LateralDistToNaviTraj(ObjNumber_t t_ObjNr)
{
#if FIP_EVAL_SHAPE_POINTS
  float32 f_LengthSeg0ArcLength = 0.f;
#endif /* FIP_EVAL_SHAPE_POINTS */
  boolean bSegDist;
  uint8 i;
  float32 fLengthAccu, fLengthSeg, fDistX, fDistY;
  float32 fNaviPointX = 0.0f, fNaviPointY = 0.0f;
  float32 fAlpha;
  FIPNaviPathCurvatureType_t t_NaviPathCurvatureType;
  float32  fSinAngleAccu, fCosAngleAccu;

  fDistX = OBJ_LONG_DISPLACEMENT(t_ObjNr);
  fDistY = OBJ_LAT_DISPLACEMENT(t_ObjNr);

  /*! Determine segment in NAVI path which corresponds to the given distance fDist */
  if(FIP_pt_ND_GetNaviData()->b_NaviPathPlausible == TRUE)
  {
    if (fDistX > C_F32_DELTA)
    {
      /*! Search for the segment and the number if lanes of the segment with the given distance fDist */
      /*! Iterate over the segments */
      /*! Set the accumulated length of the already "iterated" NAVI path to zero */
      fLengthAccu = 0.f;
      bSegDist = FALSE;
      for (i = 0u; (i < pSLATE_NaviData->u_NumUsedSegments) && (bSegDist == FALSE); i++)
      {
        if (i == 0u)
        {
#if FIP_EVAL_SHAPE_POINTS
          f_LengthSeg0ArcLength = FIP_f_NaviGetArcLengthSeg(FIPGlobalNaviInfo.NaviEGOSegment.f_Length, FIPGlobalNaviInfo.NaviEGOSegment.f_Curvature);
          fLengthSeg = (f_LengthSeg0ArcLength - FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0);
#else
          fLengthSeg = pSLATE_NaviData->Segments[0].f_Length;
#endif
        }
        else
        {
          fLengthSeg = pSLATE_NaviData->Segments[i].f_Length;
        }
        /*! If the given distance fDist is between the accumulated length of the already "iterated" NAVI path and the end of the new segment, 
            get the number of lanes of this segment */
        if( (fLengthAccu < fDistX) && (fDistX <= (fLengthAccu + fLengthSeg)) )
        {
          bSegDist = TRUE;
          /*! Determine the angle from the previous segment to the current segment in [rad] */
          fAlpha = DEG2RAD(f_FIP_NaviAccumPrevSegAngle[i]);
          /*! Calculate the sin/cos of the accumulated orientation of the starting point of the segment */
          fSinAngleAccu = SIN_HD_(fAlpha);
          fCosAngleAccu = COS_HD_(fAlpha);

          /* Determine Navi path curvature type */
          t_NaviPathCurvatureType = FIP_t_GetNaviPathCurvatureType(&pSLATE_NaviData->Segments[i]);

          FIPSamplePosAbsNaviPathArcRel(&fNaviPointX, &fNaviPointY, (fDistX-fLengthAccu), 
              &pSLATE_NaviData->Segments[i], fCosAngleAccu, fSinAngleAccu, f_FIP_NaviSegmentStartX[i], f_FIP_NaviSegmentStartY[i], t_NaviPathCurvatureType);

          pt_FIP_ND_Output->t_ObjList[t_ObjNr].f_NaviLatDist = SQRT ( (SQR(fDistY - fNaviPointY) + SQR(fDistX - fNaviPointX) ) );
        }
        /*! Increase the already "iterated" path length by the length of the new segment */
        fLengthAccu += fLengthSeg;
      } /* END FOR LOOP */

    }
    else 
    {
        /* Max limit of 10 Highway lane width */
        pt_FIP_ND_Output->t_ObjList[t_ObjNr].f_NaviLatDist = FIP_MAX_DIST_TEN_HIGHWAY_LANES;
    }/* END IF (fDist < C_F32_DELTA) ELSE */
  } /* END IF (FIPNaviDataEvaluated.f_LengthNaviPathApprox > C_F32_DELTA) */
}
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
#if FIP_EVAL_SHAPE_POINTS
/*************************************************************************************************************************
  Functionname:    FIPNaviUpdateCON2COG                                                                             */ /*!

  @brief           Update the transformation matrix between NAVI reference coordinates and EGO reference coordinates.
                  The transformation matrix CON2COG is updated and the accumulated movement for the ego compensation 
                  of the navi path.

  @description     Update the transformation matrix between NAVI reference coordinates and EGO reference coordinates.
                    The transformation matrix CON2COG is updated and the accumulated movement for the ego compensation 
                    of the navi path. The ego movement based on velocity, acceleration and yaw rate is integrated over 
                    cycle time.
  
  @startuml 
  Partition FIPNaviUpdateCON2COG
  Start
  	Note right: This function updates the transformation matrix between navigation reference coordinates and EGO reference coordinates	
	  - Calculate Translation-Vector
  	- Compensate the translation vector for distance between Sensor and COG
  	- Slip is taken as zero for now but included for completeness
  	- Update Accumulated EGO motion in current NAVI tree data structure
  	- Update Accumulated EGO motion in shape point buffer data structure
  	- Update Accumulated EGO motion in current segment structure
  	- Update transformation matrix between navigation reference coordinates and EGO reference coordinates structure
  Stop
  @enduml

  @return          -

  @param[out]      pFIPNavi_CON2COG : Reference to transformation matrix between NAVI reference coordinates and EGO 
                                      reference coordinates
                      f00                                   [-1.f ... 1.f]
                      f10                                   [-1.f ... 1.f]
                      f02                                   [-1.f ... 1.f]
                      f12                                   [-1.f ... 1.f]

  @glob_in         FIPGlobalNaviInfo : struct containing global NAVI path data
                     MotionParams_LastCycle
                       f_CycleTime : cycle time   [0.f ... 1.f] s
                       f_Slip : slip [-PI ... PI] 
                       f_YawRate : yawrate [-100.f ... 100.f] rad/s
                       f_Acceleration : acceleration [-100.f ... 100.f] m/s2
                       f_Velocity : velocity [-330.f ... 330.f] m/s
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
  @changed         10.02.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void FIPNaviUpdateCON2COG(GDBTrafoMatrix2D_t* pFIPNavi_CON2COG)
{
  /* Function specific variable naming convention - 
     LC - last cycle
     CC - current cycle */
  float32 f_LCCosYawAngle, f_LCSinYawAngle;   /* Sin and Cos of yaw angle */
  float32 f_cs_cp, f_ss_sp, f_ss_cp, f_cs_sp; /* Compensated angles using slips and yaw angles, used in computation of translation vectors */
  float32 f_LCdelta_x, f_LCdelta_y;           /* Intermediate translation vectors */
  float32 f_LCabs_dx, f_LCabs_dy;             /* Translation vectors after BumperToCOG compensation */

  float32 f_LCYawAngle, f_CCYawAngle;
  float32 f_LCdelta_s;

  float32 f_LCTime = FIPGlobalNaviInfo.MotionParams_LastCycle.f_CycleTime;
  float32 f_CCTime = SLATE_f_GetCycleTime();
  float32 f_LCSlip = FIPGlobalNaviInfo.MotionParams_LastCycle.f_Slip;

  float32 f_LCTimeSqrHalf = (f_LCTime*f_LCTime) * 0.5f;

  f_LCYawAngle = FIPGlobalNaviInfo.MotionParams_LastCycle.f_YawRate * f_LCTime;
  f_CCYawAngle = SLATE_f_GetEgoYawRateObjSync() * f_CCTime;

  /* Distance - vt + 1/2at^2 */
  f_LCdelta_s = (FIPGlobalNaviInfo.MotionParams_LastCycle.f_Acceleration*f_LCTimeSqrHalf) +
                (FIPGlobalNaviInfo.MotionParams_LastCycle.f_Velocity * f_LCTime);
  
  /* This section is taken from CML_v_CalculateCOFEgomotionMatrices in cml_misc.c */
  /* for small angles the SIN/COS-Approximation is poor!!!  */
  /* absolute error sin/cos_52: <= 6.70669e-6 */
  /* absolute error sin/cos_32: <= 5.98681e-4 */
  /* Therefore use the Approximation  */
  /* sin(x) = x, with abs. error e-6 for x > 0.03rad */
  /* cos(x) = 1-0.5*x*x, with abs. error e-6 for x > 0.003rad */
  if(f_LCYawAngle < CML_f_MaxAngleSinApprox_1)
  {
    f_LCSinYawAngle = f_LCYawAngle;
    if(f_LCYawAngle < CML_f_MaxAngleSinApprox_2)
    {
      f_LCCosYawAngle = 1.0f - ((0.5f * f_LCYawAngle) * f_LCYawAngle);
    }
    else
    {
      f_LCCosYawAngle = COS_HD_(f_LCYawAngle);
    }
  }
  else
  {
    f_LCSinYawAngle = SIN_HD_(f_LCYawAngle);
    f_LCCosYawAngle = COS_HD_(f_LCYawAngle);
  }

  /* calculate Translation-Vector */
  /* delta_x = (s/psi) * sin(psi)
     delta_y = (s/psi) * (1-cos(psi)) */
  if (!CML_f_IsZero(f_LCYawAngle))
  {
    /* <ln_offset:1to2 MISRA Rule 1.2: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: fYawAngle is checked for zero in the if statement */
    f_LCdelta_x = (f_LCdelta_s / f_LCYawAngle) * f_LCSinYawAngle;
    f_LCdelta_y = (f_LCdelta_s / f_LCYawAngle) * (1.0f - f_LCCosYawAngle);
  }
  else
  {
    f_LCdelta_x = f_LCdelta_s;
    f_LCdelta_y = 0.0f;
  }

  /* Compensate the translation vector for distance between Sensor and COG */
  /* Slip is taken as zero for now but included for completeness */
  f_cs_cp = COS_HD_(f_LCSlip) * f_LCCosYawAngle;
  f_ss_sp = SIN_HD_(f_LCSlip) * f_LCSinYawAngle;
  f_ss_cp = SIN_HD_(f_LCSlip) * f_LCCosYawAngle;
  f_cs_sp = COS_HD_(f_LCSlip) * f_LCSinYawAngle;

  f_LCabs_dx = FCT_fBumperToCoG * (f_LCCosYawAngle - 1.f) - (f_LCdelta_x * (f_cs_cp + f_ss_sp)) + (f_LCdelta_y * (f_ss_cp - f_cs_sp));
  f_LCabs_dy = -FCT_fBumperToCoG * f_LCSinYawAngle + (f_LCdelta_x * (f_cs_sp - f_ss_cp)) - (f_LCdelta_y * (f_cs_cp + f_ss_sp));

  /* Update FIPNaviEgoTreeCumul data structure */
  FIP_v_NaviUpdateEgoMotion(f_LCCosYawAngle, f_LCSinYawAngle, f_LCabs_dx, f_LCabs_dy, &FIPNaviEgoTreeCumul);
  FIPNaviEgoTreeCumul.f_abs_angle += f_CCYawAngle;
  FIPNaviEgoTreeCumul.f_abs_dist += f_LCdelta_s;

  /* Update FIPNaviEgoBufferCumul data structure */
  FIP_v_NaviUpdateEgoMotion(f_LCCosYawAngle, f_LCSinYawAngle, f_LCabs_dx, f_LCabs_dy, &FIPNaviEgoBufferCumul);
  FIPNaviEgoBufferCumul.f_abs_angle += f_CCYawAngle;
  FIPNaviEgoBufferCumul.f_abs_dist += f_LCdelta_s;

  /* Update FIPNaviEgoSegement data structure */
  FIP_v_NaviUpdateEgoMotion(f_LCCosYawAngle, f_LCSinYawAngle, f_LCabs_dx, f_LCabs_dy, &FIPNaviEgoSegmentCumul);
  FIPNaviEgoSegmentCumul.f_abs_angle += f_CCYawAngle;
  FIPNaviEgoSegmentCumul.f_abs_dist += f_LCdelta_s;
  FIPGlobalNaviInfo.NaviEGOSegment.f_DistInNaviSeg0 += f_LCdelta_s;

  /* Update CON2COG transformation matrix */
  pFIPNavi_CON2COG->f00 = COS_HD_(-FIPNaviEgoTreeCumul.f_abs_angle);
  pFIPNavi_CON2COG->f10 = SIN_HD_(-FIPNaviEgoTreeCumul.f_abs_angle);
  pFIPNavi_CON2COG->f02 = FIPNaviEgoTreeCumul.f_rel_dx;
  pFIPNavi_CON2COG->f12 = FIPNaviEgoTreeCumul.f_rel_dy;

}
#endif


/*************************************************************************************************************************
  Functionname:    FIPSet_MapIsADASQuality                                                                          */ /*!

  @brief           Set b_NaviPathIsADASQuality in FIP_ND_Output_t

  @description     Set b_NaviPathIsADASQuality in FIP_ND_Output_t

  @startuml 
  Partition FIPSet_MapIsADASQuality
  Start
  	- Set Is Navigation path ADAS quality using rom ADAS quality factor
  Stop
  @enduml

  @return          -

  @param[in]       mapADASIsQuality: ADAS quality factor [TRUE, FALSE]

  @glob_in         -
  @glob_out        FIP_ND_Output_t : 
                      b_NaviPathIsADASQuality [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple Navi input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.09.2014
  @changed         10.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIPSet_MapIsADASQuality(const boolean mapADASIsQuality)
{
  pt_FIP_ND_Output->b_NaviPathIsADASQuality = mapADASIsQuality;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_NaviSetMeasData                                                                            */ /*!

  @brief           Set NAVI FIP meas freeze data

  @description     Set NAVI FIP meas freeze data, this function is required since there are static variables in the module 
                   which have to be freezed in the device structure and these static variables are not visible from fip_main.c
  
  @startuml 
  Partition FIP_v_NaviSetMeasData
  Start
	  - Set Navigation FIP meas freeze data
  Stop
  @enduml

  @return          -

  @param[out]      p_NaviDebugMeasFreeze : Structure for NAVI FIP meas freeze
                      b_ValidNaviData                       [TRUE, FALSE]
                      b_NaviPathPlausible : Info if NAVI path seems plausible [TRUE, FALSE]
                      b_ValidNaviNumberLanes                [TRUE, FALSE]

  @glob_in         pt_FIP_ND_Output->b_NaviPathPlausible    [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple NAVI input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         10.02.2016

  @author          Marie-Theres Boll |  Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void FIP_v_NaviSetMeasData(FIP_NaviDebugMeasInfo_t * p_NaviDebugMeasFreeze, FIP_ND_Output_t * pt_FIP_ND_OutputLocal)
{
  /*! Set meas freeze data */
  p_NaviDebugMeasFreeze->b_ValidNaviData = b_ValidNaviDataMeas;
  p_NaviDebugMeasFreeze->b_NaviPathPlausible = pt_FIP_ND_OutputLocal->b_NaviPathPlausible;
  p_NaviDebugMeasFreeze->b_ValidNaviNumberLanes = b_ValidNumLanesMeas;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_SetNaviPathIsValid                                                                         */ /*!

  @brief           Set info if navi path is valid

  @description     Set info if navi path is valid in evaluated navi data structure

  @startuml 
  Partition FIP_v_SetNaviPathIsValid
  Start
	  - Set info if navi path is valid
  Stop
  @enduml

  @return          -

  @param[in]       b_NaviDataValid : information if NAVI data is valid

  @glob_in         -
  @glob_out        FIP_ND_Output_t : 
                      b_NaviPathIsValid  : information if NAVI data is valid [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @pre             FIPCalcNaviDataValid has to be invoked before to get the information which should be set.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         15.02.2016
  @changed         15.02.2016

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
static void FIP_v_SetNaviPathIsValid(boolean b_NaviDataValid)
{
  pt_FIP_ND_Output->b_NaviPathIsValid = b_NaviDataValid;
}

#endif /*!< SLATE_CFG_SIMPLE_NAVI_INTERFACE */
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */

#if (FIP_EVAL_ROAD_JUNCTION)
/*************************************************************************************************************************
  Functionname:    FIP_f_DistanceToNextRoadJunction                                                                         */ /*!

  @brief           Calculate distance to next available road junction on navi MPP.

  @description     Calculate distance to next available road junction on navi MPP.

  @startuml 
  Partition FIP_f_DistanceToNextRoadJunction
  Start
  	Note right: This functions calaculates distance to next available road junction on navi MPP
  	- Iterate through all navigation MPP segments
  	If (MPP segment has got an branch/exit with valid angle) then (True)
	  	- Set branch found to True
	  Else (False)
		  - Increase distance to branch by total length of segment
  	Endif

  	If (Branch found is False) then (True)
	  	- Set distance to branch to Invalid distance
  	Else (False)
  	Endif
	
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in          pSLATE_NaviData->u_NumUsedSegments                        : Number of navi segments [8]
                    pSLATE_NaviData->Segments[i].ExitSegments[0].u_SegmentID  : Segment ID of the exit segment if it is detected 
                                                                                  in current navi segment.
                    pSLATE_NaviData->Segments[i].ExitSegments[0].f_Length     : Length of the exit segment
                    pSLATE_NaviData->Segments[i].ExitSegments[0].f_Angle      : Angle in degrees of the exit segments with previous MPP segment [0,360]
                    pSLATE_NaviData->Segments[i].f_Length                     : Length of the current MPP segment

  @glob_out        f_distanceToBranch : 
                      Calculated distance to branch/road junction.

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_full   FIP_EVAL_ROAD_JUNCTION : flag to signal the if there is a junction inbetween the next 60m

  @pre             FIPCalcNaviDataValid has to be invoked before to get the information which should be set.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         19.07.2017
  @changed         19.07.2017

  @author          Kiran Patil | kiran.patil@continental-corporation.com | +91 (80) 6679-1904
*************************************************************************************************************************/
static float32 FIP_f_DistanceToNextRoadJunction(void)
{
  uint16  i;
  boolean b_branchFound = FALSE;                          /* set to true if branch/exit exists within f_branch_detection_range */
  float32 f_distanceToBranch= 0.f;                     /* distance to the next navi branch/exit [m]*/
  float32 fABS_Angle;		/* For calculating ABS value */


  /* for all navi mpp sgments */
  for(i = 0U; (i < pSLATE_NaviData->u_NumUsedSegments); i++)
  {
	fABS_Angle = fABS(pSLATE_NaviData->Segments[i].ExitSegments[0].f_Angle);
    /* if the mpp segment has got an branch/exit with valid angle */ 
    if(   (pSLATE_NaviData->Segments[i].ExitSegments[0].u_SegmentID != 0U )
      &&  (pSLATE_NaviData->Segments[i].ExitSegments[0].f_Length >  0.f )
      &&  (fABS_Angle < FIP_NAVI_BRANCH_MAX_SEGMENT_ANGLE))
    {
      b_branchFound = TRUE;
      break;
    }
    /* If the branch is not fount in current MPP segment increase distance to branch by total length of segment*/
    else
    {
      f_distanceToBranch += pSLATE_NaviData->Segments[i].f_Length;
    }
  }

  /*If the branch is not found in all MPP segments the set distance to exit/road junction as -1m*/
  if(FALSE == b_branchFound)
  {
    f_distanceToBranch = INVALID_DISTANCE_TO_JUNCTION;
  }

  return f_distanceToBranch;
}
///@}
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED
