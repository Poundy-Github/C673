/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_main.c

DESCRIPTION:               Main process file for Course prediction module

AUTHOR:                    Norman Apel

CREATION DATE:             07.09.2011

VERSION:                   $Revision: 1.39 $

LEGACY VERSION:            Revision: 2.2.1.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_COURSE_PREDICTION)
#include "cp_customfunctions.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_main Main
@ingroup cp
@brief          This module provides amongst others the main function of the SLATE Component. \n\n

@description    The following functionalities are provided by this module:
                - Initializes the CP_t_TraceAddData structure containing Trace additional data: @ref CP_v_InitTraceAddData.
                - Calculate internal 'CPTraceScoreAddData_t' based on trace: @ref CP_v_CalcMovObjTraceAddData.
				- Get trace poly points in X and Y direction: @ref CP_s_GDVGetTracePolyPoints.
				- Proprocessing of trace data: @ref CP_v_TracePreProc.
				- Set inputs to CP module: @ref CP_v_PreProcess.
				- Main processing function of CP sub-component: @ref CP_v_Process.
				- Freeze CP Object data for simulation: @ref CP_v_MeasFreeze.
				- Initialize persistent memory structures in CP component: @ref CP_v_InitPersistentData.
				- Initialize input-output data structures for CP component: @ref CP_v_InitEveryCycle.
				- assign values to CP input structure: @ref CP_v_SetInput.
				- Set operation mode of CP sub-component: @ref CP_v_SetOperationMode.
@{
*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/*! @cond Doxygen_Suppress */
SET_MEMSEC_VAR(CP_State)
SLATECompState_t CP_State;
/*! @endcond Doxygen_Suppress */

/*! Definition of pointer to CP input structure for access within this component */
SET_MEMSEC_VAR(pt_CPInput)
CPInputConst_t * pt_CPInput;

/*! Definition of pointer to CP output structure for access within this component */
SET_MEMSEC_VAR(pt_CPOutput)
CPOutput_t * pt_CPOutput;

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

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief CP_TRACE_APPROX_FAR_DISTANCE */
#define CP_TRACE_APPROX_FAR_DISTANCE 200.0f
#if 0 /* Currently not used */

/*! @brief Constant value stored in uTraceLaneIdx when a trace has no lane assigned */
#define CP_LANE_INDEX_NONE            255u
/*! @brief Length of trace for maximal length based confidence */
#define CP_NUM_TRACE_MAX_CONF_NUM_POINTS        5u

/*! @brief Length based trace confidence multiplier when trace is CP__NUM_TRACE_MIN_NUMBER_OF_POINTS long */
#define CP_MIN_TRACE_LENGTH_CONFIDENCE          0.5f

/*! @brief Length based trace confidence multiplier when trace is CP_NUM_TRACE_MAX_CONF_NUM_POINTS long */
#define CP_MAX_TRACE_LENGTH_CONFIDENCE          1.f

#endif


#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FIP_CFG_USE_EGO_TRACE))
# if (FCT_CFG_NEW_TRACES_INTERFACE)

/*! @brief The basic multiplier to trace weigtht to use */
#define CP_PAR_BASE_TRACE_WEIGHT_WITH_OBJ 0.01f

/*! @brief The basic trace confidence to use for trace's where the trace head object doesn't exist */
#define CP_PAR_BASE_TRACE_WEIGHT_NO_OBJ   0.0f

# endif 

/*! @brief Default invalid value used by several functions */
#define CP_DEFAULT_INVALID_VALUE              999.0f

#endif

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*! Additional data stored for traces (one entry per trace) */
SET_MEMSEC_VAR(CP_TraceAdd)
CP_t_TraceAddData CP_TraceAdd[CP_NUM_TRACES];
#endif /* FCT_CFG_OBJECT_TRACE_PREPROCESSSING */

#if (FIP_CFG_USE_EGO_TRACE)
/*! Additional data stored for Ego trace*/
SET_MEMSEC_VAR(CP_EgoTraceAdd)
CP_t_EgoTraceAddData CP_EgoTraceAdd;
#endif

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FIP_CFG_USE_EGO_TRACE))
static void CP_v_TracePreProc( void );
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
static void CP_v_InitTraceAddData(CP_t_TraceAddData * const pTraceAdd);
static void CP_v_CalcMovObjTraceAddData(CP_t_TraceAddData * const pCurAddData, const TraceID_t iTrace);
#endif
#if (FIP_CFG_USE_EGO_TRACE)
static void CP_v_InitEgoTraceAddData(CP_t_EgoTraceAddData * const pEgoTraceAdd);
static void CP_v_CalcEgoTraceAddData(CP_t_EgoTraceAddData * const pEgoAddData);
#endif
static void CP_v_MeasFreeze(void);


#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_v_InitTraceAddData                                                                               */ /*!

  @brief           This function initializes the CP_t_TraceAddData structure containing Trace additional data

  @description     This function initializes the CP_t_TraceAddData structure containing Trace additional data

                   @startuml
                   Partition CP_v_InitTraceAddData{
                   Start 
                   : Initialize Object number, Number of trace points, Close distance, Far distance,\n Summed squared distance, Trace approximation, Flag;
                   End
				   }				   
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      pTraceAdd : pointer to the the structure containing object trace data
                      iObjNr : Object number of the trace                                                           [signed character as defined in Rte_Type.h] [0...+39]
                      uNumberOfPoints : Number of trace points we have already seen                                 [unit8 datatype as defined in Platform_Types.h]
                      uApproxUseLen : Number of indices to use for approximation                                    [unit8 datatype as defined in Platform_Types.h]
                      fApproxCloseDist : Close distance from where poly approx valid                                [Full range of float32  >= 0.F]
                      fApproxFarDist : Far distance till where poly approx valid                                    [Full range of float32  >= 0.F]
                      fCurSqDist : Summed squared distance of the sample points to the approximation polynomial     [Full range of float32  >= 0.F]
                      isValid : Flag to indicate whether the trace polynomial is valid                              [TRUE,FALSE]
                      bUseTraceForFusion : Flag to indicate whether the trace is used within the trajectory fusion  [TRUE,FALSE]
                      ApproxPoly.fC0 : Trace approximation polynomial                                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      ApproxPoly.fC1 : Trace approximation polynomial                                               [-1f ... +1f]
                      ApproxPoly.fC2 : Trace approximation polynomial                                               [-1f ... +1f]
                      ApproxPoly.isValid : Flag to indicate if trace polynomial is valid                            [TRUE,FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Switch to configure moving object traces component
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure CP sub-component in FCT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/11/2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void CP_v_InitTraceAddData(CP_t_TraceAddData * const pTraceAdd)
{
  pTraceAdd->iObjNr               = OBJ_INDEX_NO_OBJECT;
  pTraceAdd->uNumberOfPoints      = 0u;
  pTraceAdd->uApproxUseLen        = 0u;
  /*pTraceAdd->uTraceLaneIdx        = CP_LANE_INDEX_NONE;*/
  pTraceAdd->fApproxCloseDist     = 0.f;
  pTraceAdd->fApproxFarDist       = 0.f;
  pTraceAdd->fCurSqDist           = 0.f;

  pTraceAdd->ApproxPoly.fC0       = 0.f;
  pTraceAdd->ApproxPoly.fC1       = 0.f;
  pTraceAdd->ApproxPoly.fC2       = 0.f;
  pTraceAdd->ApproxPoly.isValid   = FALSE;
  pTraceAdd->isValid              = FALSE;
  pTraceAdd->bUseTraceForFusion   = FALSE;
}
#endif
#if (FIP_CFG_USE_EGO_TRACE)
/*************************************************************************************************************************
  Functionname:    CP_v_InitEgoTraceAddData                                                                               */ /*!

  @brief           This function initializes the CP_t_EgoTraceAddData structure containing Trace additional data

  @description     This function initializes the CP_t_EgoTraceAddData structure containing Trace additional data

                   @startuml
                   Partition CP_v_InitEgoTraceAddData{
                   Start 
                   : Initialize Number of trace points, Far distance, Summed squared distance,\n Trace approximation polynomial, Flag;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      pEgoTraceAdd : Pointer to the the structure containing ego trace data
                      uNumberOfPoints : Number of trace points we have already seen                                 [unit8 datatype as defined in Platform_Types.h]
                      fApproxFarDist : Far distance till where poly approx valid                                    [Full range of float32  >= 0.F]
                      fCurSqDist : Summed squared distance of the sample points to the approximation polynomial     [Full range of float32  >= 0.F]
                      ApproxPoly.fC0 : Trace approximation polynomial                                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      ApproxPoly.fC1 : Trace approximation polynomial                                               [-1f ... +1f]
                      ApproxPoly.fC2 : Trace approximation polynomial                                               [-1f ... +1f]
                      ApproxPoly.isValid : Flag to indicate if trace polynomial is valid                            [TRUE,FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_CFG_USE_EGO_TRACE     : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component in FCT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void CP_v_InitEgoTraceAddData(CP_t_EgoTraceAddData * const pEgoTraceAdd)
{
  pEgoTraceAdd->uNumberOfPoints      = 0u;
  pEgoTraceAdd->fApproxFarDist       = 0.0f;
  pEgoTraceAdd->fCurSqDist           = 0.0f;  
  pEgoTraceAdd->ApproxPoly.fC0       = 0.0f;
  pEgoTraceAdd->ApproxPoly.fC1       = 0.0f;
  pEgoTraceAdd->ApproxPoly.fC2       = 0.0f;
  pEgoTraceAdd->ApproxPoly.isValid   = FALSE;
}
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_NEW_TRACES_INTERFACE)
/*************************************************************************************************************************
  Functionname:    CP_v_CalcObjectTraceAddData                                                                      */ /*!

  @brief           Calculate internal 'SITraceScoreAddData_t' based on trace

  @description     Update/calculate the internally used SITraceScoreAddData_t
                   structure with the information from the trace 'pTrace'.
                   This includes calculation of a 2nd level polynomial
                   approximation of the relevant part of the trace.

                   @startuml
                   Partition CP_v_CalcObjectTraceAddData{
                   Start 
                   If (trace valid or deleted and not of unknown or ego type) then (TRUE)
                   If (trace has a valid object assigned) then (TRUE)
                   : Get the object number of the trace;
                   If (object associated with trace changed) then (TRUE)
                   : reset the trace and assign new object ID;
                   Else (FALSE)
                   Endif 
                   : Set base trace confidence value;
                   : Clamp base trace confidence for traces with objects to that of no objects;
                   Else (FALSE)
                   : Trace no longer has a valid object, set it's object number to no object;
                   : Set base trace confidence value;
                   Endif 
                   If (number of points increased) then (TRUE)
                   : increase used approximation length;
                   Else (FALSE)
                   Endif 
                   : Load number of points used in last iteration for approximation;
                   If (sufficient number of trace points for polynome extrapolation) then (TRUE)
                   : Calculate the trace approximation polynomial;
                   If (the points used for the poly approximation are sufficient) then (TRUE)
                   : Calculate the summed squared distance of the sample points\n to the approximation polynomial;
                   Else (FALSE)
                   : Insufficient number of points used for polynomial, set to invalid;
                   Endif 
                   Else (FALSE)
                   : Trace too short, set it to invalid;
                   : Update number of points;
                   Endif 
                   Else (FALSE)
                   : the trace is deleted - reset data on it;
                   Endif 
                   End 
                   }
                   @enduml

  @return          -

  @param[in,out]   pCurAddData : On input the currently stored state of the trace. This will be filled/updated 
                                 with the information from the new trace (based on changes of object ID/length)
                      iObjNr : Object number of the trace (Object ID)                                               [0 ... EM_N_OBJECTS-1]
                      isValid : Flag to indicate if trace polynomial is valid                                       [TRUE,FALSE]
                      bUseTraceForFusion : Flag to indicate whether the trace is used within the trajectory fusion  [TRUE,FALSE]
                      uNumberOfPoints : Number of trace points we have already seen                                 [unit8 datatype as defined in Platform_Types.h]
                      uApproxUseLen : Number of indices to use for approximation                                    [unit8 datatype as defined in Platform_Types.h]
                      ApproxPoly : Structure containing Trace approximation polynomial
                      fApproxCloseDist : Close distance from where poly approx valid                                [Full range of float32  >= 0.F]
                      fApproxFarDist : Far distance till where poly approx valid                                    [Full range of float32  >= 0.F]
  @param[in]       pTrace : The trace to use to update the data
                      ObjectTraceBasic.uiReferenceToFCTObject : Getting FCT Object ID                               [0 ... EM_N_OBJECTS-1]
                      ObjectTraceBasic.uiNumberOfPoints : Number of trace points we have already seen               [Full range of unsigned char]   
                      ObjectTraceAttributes.eTraceType : Trace type                                                 [Full range of eTraceType_t as defined in Rte_Type.h]

  @glob_in         pt_CPInput->t_RTE.pu_AccObjQuality(i) : Get pre-selection quality of given FCT object  [Full range of unsigned char]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_NEW_TRACES_INTERFACE        : Switch to configure new interface for moving object traces component
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure CP sub-component in FCT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void CP_v_CalcObjectTraceAddData(CP_t_TraceAddData * const pCurAddData, const ObjectTraces_t * const pTrace)
{
  /* First check if trace valid or deleted and not of unknown or ego type */
  if (  (pTrace->ObjectTraceBasic.uiReferenceToFCTObject <= TRACE_VALID_NO_OBJ_ID)
    &&  (pTrace->ObjectTraceBasic.uiNumberOfPoints >= CP_NUM_TRACE_MIN_NUMBER_OF_POINTS)
    &&  (pTrace->ObjectTraceAttributes.eTraceType != TRACE_TYPE_EGO)
    &&  (pTrace->ObjectTraceAttributes.eTraceType != TRACE_TYPE_UNKNOWN))
  {
    uint8     uNumApproxPts;      /*!< Number of trace points used for poly approx */
    float32   fBaseTraceWeight;

    /* Check if trace has a valid object assigned */
    if (pTrace->ObjectTraceBasic.uiReferenceToFCTObject < EM_N_OBJECTS)
    {
      /* Get the object number of the trace */
      const ObjNumber_t iTraceObjIdx = pTrace->ObjectTraceBasic.uiReferenceToFCTObject;

      /* Sanity check: if object associated with trace changed, then reset
      the trace, and assign new object ID */
      if (pCurAddData->iObjNr != iTraceObjIdx)
      {
        CP_v_InitTraceAddData(pCurAddData);
        pCurAddData->iObjNr = iTraceObjIdx;
      }

      /* Set base trace confidence value */
      fBaseTraceWeight  = CP_PAR_BASE_TRACE_WEIGHT_WITH_OBJ * (pt_CPInput->t_RTE.pu_AccObjQuality(iTraceObjIdx));

      /* Clamp base trace confidence for traces with objects to that of no objects (lower
      bound), and 1.f (maximal conf) */
      fBaseTraceWeight = MINMAX_FLOAT(CP_PAR_BASE_TRACE_WEIGHT_NO_OBJ, 1.f, fBaseTraceWeight);
    }
    else
    {
      /* Trace no longer has a valid object, set it's object number to no object */
      pCurAddData->iObjNr = OBJ_INDEX_NO_OBJECT;
      pCurAddData->isValid = FALSE;
      pCurAddData->bUseTraceForFusion = FALSE;
      /* Set base trace confidence value */
      fBaseTraceWeight  = CP_PAR_BASE_TRACE_WEIGHT_NO_OBJ;
    }

    /* If number of points increased, then increase used approximation length */
    if (pTrace->ObjectTraceBasic.uiNumberOfPoints > pCurAddData->uNumberOfPoints)
    {
      pCurAddData->uApproxUseLen = (pCurAddData->uApproxUseLen + (pTrace->ObjectTraceBasic.uiNumberOfPoints - pCurAddData->uNumberOfPoints));
    }

    /* Load number of points used in last iteration for approximation */
    uNumApproxPts = pCurAddData->uApproxUseLen;

    /* Verify that sufficient number of trace points for polynome extrapolation */
    if (uNumApproxPts >= CP_NUM_TRACE_MIN_NUMBER_OF_POINTS)
    {
      float32 fCurSqDist;
      uint8 uNumPtsSkipped;
      uint8 uNumPtsUsed;

      /* Calculate the trace approximation polynomial */
      uNumPtsUsed = CAL_u_CalcObjTraceApproxPolyL2(&pCurAddData->ApproxPoly, pTrace, &uNumPtsSkipped, uNumApproxPts);

      /* Verify that the points used for the poly approximation are sufficient */
      if (uNumPtsUsed >= CP_NUM_TRACE_MIN_NUMBER_OF_POINTS)
      {
        /* Calculate the summed squared distance of the sample points to the
        approximation polynomial (the residual) */
        fCurSqDist = CAL_f_CalcObjTraceSumSqDist(&pCurAddData->ApproxPoly, pTrace, &pCurAddData->fApproxCloseDist, &pCurAddData->fApproxFarDist, uNumPtsSkipped, uNumApproxPts);
      }
      else
      {
        /* Insufficient number of points used for polynomial, set to invalid */
        pCurAddData->fApproxCloseDist   = CP_DEFAULT_INVALID_VALUE;
        pCurAddData->fApproxFarDist     = CP_DEFAULT_INVALID_VALUE;
      }
    }
    else
    {
      /* Trace too short, set it to invalid */
      pCurAddData->fApproxCloseDist   = CP_DEFAULT_INVALID_VALUE;
      pCurAddData->fApproxFarDist     = CP_DEFAULT_INVALID_VALUE;
    }

    /* Update number of points */
    pCurAddData->uNumberOfPoints  = pTrace->ObjectTraceBasic.uiNumberOfPoints;
  }
  else
  {
    /* Trace seems to have a reference to object greater TRACE_VALID_NO_OBJ_ID,
    which means the trace is deleted - reset data on it */
    CP_v_InitTraceAddData(pCurAddData);
  }
}


#else /* FCT_CFG_NEW_TRACES_INTERFACE */

/*************************************************************************************************************************
  Functionname:    CP_v_CalcMovObjTraceAddData                                                                         */ /*!

  @brief           Calculate internal 'CPTraceScoreAddData_t' based on trace

  @description     Update/calculate the internally used SITraceScoreAddData_t
                   structure with the information from the trace 'pTrace'.
                   This includes calculation of a 2nd level polynomial
                   approximation of the relevant part of the trace.

                   @startuml
                   Partition CP_v_CalcMovObjTraceAddData{
                   Start 
                   : Get Reference to Object Id, Number of trace points;
                   If (trace valid or deleted?) then (TRUE)
                   If (trace has a valid object assigned) then (TRUE)	
                   : Get the object number of the trace;
                   If (object associated with trace changed) then (TRUE)
                   : reset the trace, and assign new object ID;
                   Else (FALSE)
                   Endif 
                   Else (FALSE)
                    : Trace no longer has a valid object,\n set it's object number to no object;
                   Endif 
                   If (number of points increased) then (TRUE)
                   : increase used approximation length;
                   Else (FALSE)
                   Endif 
                   : Find the number of samples with positive X coordinate;
                   : Get number of points used for poly approximation;
                   : Store the number of points used for poly approximation;
                   If (sufficient number of trace points for polynome extrapolation?) then (TRUE)
                   : Calculate the trace approximation polynomial;
                   : Calculate the summed squared distance of the sample points\n to the approximation polynomial;
                   : Store the estimated distance of the starting point;
                   Else (FALSE)
                   : Trace too short, set it to invalid;
                   Endif 
                   : Update number of points;
                   Else (FALSE)
                   : the trace is deleted - reset data on it;
                   : Trace no longer has a valid object, set it's object number to no object;
                   Endif 
                   End 
                   }
                   @enduml

  @return          -

  @param[in,out]   pCurAddData : On input the currently stored state of the trace. This will be filled/updated 
                                 with the information from the new trace (based on changes of object ID/length)
                      iObjNr : Object number of the trace (Object ID)                                                  [0 ... EM_N_OBJECTS-1]
                      uNumberOfPoints : Number of trace points we have already seen                                    [unit8 datatype as defined in Platform_Types.h]
                      uApproxUseLen : Number of indices to use for approximation                                       [unit8 datatype as defined in Platform_Types.h]
                      ApproxPoly : Structure containing Trace approximation polynomial
                      fCurSqDist : Summed squared distance of the sample points to the approximation polynomial        [Full range of float32  >= 0.F]
                      fApproxCloseDist : Close distance from where poly approx valid                                   [Full range of float32  >= 0.F]
                      fApproxFarDist : Far distance till where poly approx valid                                       [Full range of float32  >= 0.F]                    
  @param[in]       iTrace : Pointer to the object trace used to update the data                                        [TraceID_t type as defined in Rte_Type.h] [0......10]

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->uiReferenceToFCTObject : Reference to Object Id        [Full range of unsigned char]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->iNumberOfPoints : Number of trace points               [signed char data type] [0...+25]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->fTracePointX : array of x coordinates of trace points  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->fTracePointY : array of y coordinates of trace points  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
  @glob_out        -

  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_NEW_TRACES_INTERFACE        : Switch to configure new interface for moving object traces component
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure CP sub-component in FCT

  @c_switch_part   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/11/2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void CP_v_CalcMovObjTraceAddData(CP_t_TraceAddData * const pCurAddData, const TraceID_t iTrace)
{
  /* defining local variable from reference pointer */
  uint8 uiRefToFCTObj = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;
  sint8 i_NumberOfPoints = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].iNumberOfPoints;

  /* First check if trace valid or deleted */
  if (  (uiRefToFCTObj <= FIP_u_TRACE_VALID_NO_OBJ_ID)
    &&  ((uint8)i_NumberOfPoints >= CP_NUM_TRACE_MIN_NUMBER_OF_POINTS) )
  {
    uint8     uNumApproxPts;      /*!< Number of trace points used for poly approx */    

    /* Check if trace has a valid object assigned */
    if (uiRefToFCTObj < (uint8)EM_N_OBJECTS)
    {
      /* Get the object number of the trace */
      const ObjNumber_t iTraceObjIdx = (ObjNumber_t)(uiRefToFCTObj);

      /* Sanity check: if object associated with trace changed, then reset
      the trace, and assign new object ID */
      if (pCurAddData->iObjNr != iTraceObjIdx)
      {
        CP_v_InitTraceAddData(pCurAddData);
        pCurAddData->iObjNr = iTraceObjIdx;
      }
    }
    else
    {
      /* Trace no longer has a valid object, set it's object number to no object */
      pCurAddData->iObjNr = OBJ_INDEX_NO_OBJECT;
    }

    /* If number of points increased, then increase used approximation length */
    if ((uint8)i_NumberOfPoints > pCurAddData->uNumberOfPoints)
    {
      const uint8 uLengthIncrease = ((uint8)(i_NumberOfPoints) - pCurAddData->uNumberOfPoints);
      pCurAddData->uApproxUseLen += uLengthIncrease;
    }

    /* Find the number of samples with positive X coordinate */
    uNumApproxPts = (uint8)i_NumberOfPoints;
    while ((uNumApproxPts > 1u) && (pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[uNumApproxPts-2u] <= 0.f))
    {
      uNumApproxPts--;
    }

    /* Take smaller of the two possible values between used approximation length
    and number of samples with positive X coordinate */
    uNumApproxPts = MIN(pCurAddData->uApproxUseLen, uNumApproxPts);

    /* Store the number of points used for poly approximation */
    pCurAddData->uApproxUseLen = uNumApproxPts;

    /* Verify that sufficient number of trace points for polynome extrapolation and we
    have a real trace weight */
    if ((uNumApproxPts >= CP_NUM_TRACE_MIN_NUMBER_OF_POINTS) && (pCurAddData->iObjNr != OBJ_INDEX_NO_OBJECT))
    {
      /* Calculate the trace approximation polynomial */
      CAL_v_CalcPointApproxPolyL2(&pCurAddData->ApproxPoly, pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX, pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointY, uNumApproxPts);
      /* Alternatively one could use : SICalcPointApproxPolyL2Ext(&pCurAddData->ApproxPoly, pt_CPInput->t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->fTracePointX, pt_CPInput->t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->fTracePointY, pt_CPInput->t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->fTracePointYStdDev, uNumApproxPts); */

      /* Calculate the summed squared distance of the sample points to the
      approximation polynomial (the residual) */
      pCurAddData->fCurSqDist = CAL_f_CalcSumSqDistance(&pCurAddData->ApproxPoly, pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX, pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointY, uNumApproxPts);
      /* Alternatively one could use: fCurSqDist = SICalcSumSqDistanceExt(&pCurAddData->ApproxPoly, pTrace->fTracePointX, pTrace->fTracePointY, pTrace->fTracePointYStdDev, uNumApproxPts); */

      /* Store the estimated distance of the starting point (currently only take X offset
      into account) */
      pCurAddData->fApproxCloseDist = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].fTracePointX[uNumApproxPts-1u];
      pCurAddData->fApproxFarDist   = *(pt_CPInput->t_RTE.pf_ObjLongDisp((sint8)uiRefToFCTObj));/*Object Xdist*/ 
    }
    else
    {
      /* Trace too short, set it to invalid */
      pCurAddData->fApproxCloseDist = CP_DEFAULT_INVALID_VALUE;
      pCurAddData->fApproxFarDist   = CP_DEFAULT_INVALID_VALUE;      
    }
    /* Update number of points */
    pCurAddData->uNumberOfPoints  = (uint8)i_NumberOfPoints;
  }
  else
  {
    /* Trace seems to have a reference to object greater TRACE_VALID_NO_OBJ_ID,
    which means the trace is deleted - reset data on it */
    CP_v_InitTraceAddData(pCurAddData);
    /* Trace no longer has a valid object, set it's object number to no object */
    pCurAddData->iObjNr = OBJ_INDEX_NO_OBJECT;
  }
}
#endif /*(FCT_CFG_NEW_TRACES_INTERFACE)*/
#endif /*(FCT_CFG_OBJECT_TRACE_PREPROCESSSING)*/

#if (FIP_CFG_USE_EGO_TRACE)
/*************************************************************************************************************************
  Functionname:    CP_v_CalcEgoTraceAddData                                                                         */ /*!

  @brief           Calculate internal 'CPEgoTraceScoreAddData_t' based on trace

  @description     Update/calculate the internally used CPEgoTraceScoreAddData_t
                   structure with the information from the trace 'pTrace'.
                   This includes calculation of a 2nd level polynomial
                   approximation of the relevant part of the trace.

                   @startuml
                   Partition CP_v_CalcEgoTraceAddData{
                   Start 
                   : Get Number of trace points of ego trace;
                   If (sufficient number of trace points for polynome extrapolation) then (TRUE)
                   : Update number of points;
                   : Calculate the trace approximation polynomial;
                   : Calculate the summed squared distance of the sample points\n to the approximation polynomial;
                   : Store the estimated distance of the starting point;
                   Else (FALSE)
                   Endif 
                   End 
                   }
                   @enduml

  @return          -

  @param[in,out]   pEgoAddData : On input the currently stored state of the trace. This will be 
                                 filled/updated with the information from the new trace
                      uNumberOfPoints : Number of trace points we have already seen                             [unit8 datatype as defined in Platform_Types.h]
                      ApproxPoly : Structure containing Trace approximation polynomial
                      fCurSqDist : Summed squared distance of the sample points to the approximation polynomial [Full range of float32  >= 0.F]                       
                      fApproxFarDist : Far distance till where poly approx valid                                [Full range of float32  >= 0.F]

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.ps_EgoTraceNumberOfPoints : Number of trace points of ego trace                  [signed char data type] [0...+5]
                      t_FIPMOT.pf_EgoTracePointX0 : array of x coordinates of trace points                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_FIPMOT.pf_EgoTracePointY0 : array of y coordinates of trace points                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
  @glob_out        -

  @c_switch_full   FIP_CFG_USE_EGO_TRACE     : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component in FCT

  @c_switch_part   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void CP_v_CalcEgoTraceAddData(CP_t_EgoTraceAddData * const pEgoAddData)
{
  /* Defining local variable from reference pointer */
  uint8 uEgoTraceNumberOfPoints = (uint8)(pt_CPInput->pt_FIPMOT->t_EgoTrace.iNumberOfPoints);

  /* Verify that sufficient number of trace points for polynome extrapolation and we
    have a real trace weight */
  if (uEgoTraceNumberOfPoints >= CP_NUM_TRACE_MIN_NUMBER_OF_POINTS)
  {
    /* Update number of points */
    pEgoAddData->uNumberOfPoints  = uEgoTraceNumberOfPoints;

    /* Calculate the trace approximation polynomial */
    CAL_v_CalcPointApproxPolyL2(&pEgoAddData->ApproxPoly, pt_CPInput->pt_FIPMOT->t_EgoTrace.fTracePointX, pt_CPInput->pt_FIPMOT->t_EgoTrace.fTracePointY, pEgoAddData->uNumberOfPoints);
    /* Alternatively one could use : SICalcPointApproxPolyL2Ext(&pCurAddData->ApproxPoly, pTrace->fTracePointX, pTrace->fTracePointY, pTrace->fTracePointYStdDev, pEgoAddData->uApproxUseLen); */

    /* Calculate the summed squared distance of the sample points to the
    approximation polynomial (the residual) */
    pEgoAddData->fCurSqDist = CAL_f_CalcSumSqDistance(&pEgoAddData->ApproxPoly, pt_CPInput->pt_FIPMOT->t_EgoTrace.fTracePointX, pt_CPInput->pt_FIPMOT->t_EgoTrace.fTracePointY, pEgoAddData->uNumberOfPoints);
    /* Alternatively one could use: fCurSqDist = SICalcSumSqDistanceExt(&pCurAddData->ApproxPoly, pTrace->fTracePointX, pTrace->fTracePointY, pTrace->fTracePointYStdDev, pEgoAddData->uApproxUseLen); */

    /* Store the estimated distance of the starting point (currently only take X offset
    into account) */
    pEgoAddData->fApproxFarDist = (pt_CPInput->pt_FIPMOT->t_EgoTrace.fTracePointX[pEgoAddData->uNumberOfPoints-1u] * (-1));
  }
}
#endif

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    CP_s_GDVGetTracePolyPoints                                                                          */ /*!

  @brief           To get trace poly points in X and Y direction

  @description     To get trace poly points in X and Y direction 

                   @startuml
                   Partition CP_s_GDVGetTracePolyPoints{
                   Start 
                   : Get trace poly points in X and Y direction;
                   End 
                   }
                   @enduml

  @return          iRetint

  @param[in]       iTr : Trace Id Number                                                      [TraceID_t type as defined in Rte_Type.h] [0......10]
  @param[in]       iMaxPoints : Maximum number of Trace Points per trace                      [0...25]
  @param[out]      pfX : pointer to an array of x coordinate of trace points for trace        [0.f.....CP_TRACE_APPROX_FAR_DISTANCE]
  @param[out]      pfY : pointer to an array of y coordinate of trace points for trace        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
  @param[out]      pColor : color of the trace to be displayed on screen in simulation screen [GBVColor_t type as defined in sim_swc_em_gdv_interf.h] [0x000000u....0xFFFFFFu]

  @glob_in         CP_TraceAdd[iTr] : Structure used to store additional data for traces
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU                            : Switch to configure FCT Simulation 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Switch to configure moving object traces component
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure CP sub-component in FCT


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/18/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
int CP_s_GDVGetTracePolyPoints(TraceID_t iTr, float32 * pfX, float32 * pfY, int iMaxPoints, unsigned int * pColor)
{
  int iRet = 0;
  const unsigned int GEN_DARKGRAY = 0x787878u;
  *pColor = GEN_DARKGRAY;
  if ((iTr < CP_NUM_TRACES) && (iMaxPoints > 1))
  {
    const CP_t_TraceAddData * const pCurAddData = &CP_TraceAdd[iTr];
    const CAL_t_TracePolyL2 * const pTracePoly = &pCurAddData->ApproxPoly;
    if (pCurAddData->uNumberOfPoints > 0u)
    {      
      const float32 fXFar   = MIN_FLOAT((pCurAddData->fApproxFarDist), CP_TRACE_APPROX_FAR_DISTANCE);
      const float32 fXClose = MAX_FLOAT((pCurAddData->fApproxCloseDist), 0.f);
      const float32 fXStep  = (fXFar - fXClose) / (iMaxPoints-1);
      int i;      
      for (i=0; i<iMaxPoints; i++)
      {
        const float32 fX = fXClose + i*fXStep;
        const float32 fY = fX*fX*pTracePoly->fC2 + fX*pTracePoly->fC1 + pTracePoly->fC0;
        pfX[i] = fX;
        pfY[i] = fY;
      }
      iRet = iMaxPoints;         
    }
  }
  return iRet;
}
#endif /*FCT_SIMU*/
#endif /*FCT_CFG_OBJECT_TRACE_PREPROCESSSING*/

#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FIP_CFG_USE_EGO_TRACE))
/*************************************************************************************************************************
  Functionname:    CP_v_TracePreProc                                                                                   */ /*!

  @brief           Proprocessing of trace data

  @description     Proprocessing of trace data

                   @startuml
                   Partition CP_v_TracePreProc{
                   Start 
                   If (operating mode is Not Initialized OR Temporary OR Permanent Error) then (TRUE)
                   : Reset trace information for each trace;
                   : Reset trace information for ego;
                   Else (FALSE)
                   : Get utility pointer to current trace's additional data;
                   : Store values in output of CP;
                   : Get ego trace polynomials;
                   Endif 
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         CP_State : operating modes of CP sub-component                                          [enum as defined  in cp_ext.h]
  @glob_in         CP_TraceAdd[i] : Array of Structure used to store additional data of trace
                      ApproxPoly.fC0 : Trace approximation polynomial                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      ApproxPoly.fC1 : Trace approximation polynomial                                      [-1f...+1f]
                      ApproxPoly.fC2 : Trace approximation polynomial                                      [-1f...+1f]
                      ApproxPoly.isValid : Flag to indicate if trace polynomial is valid                   [TRUE,FALSE]
  @glob_in         CP_EgoTraceAdd : Array of Structure used to store additional data stored for Ego trace
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_TracePoly[i].fC0 : Trace approximation polynomial                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      CP_TracePoly[i].fC1 : Trace approximation polynomial                                 [-1f...+1f]
                      CP_TracePoly[i].fC2 : Trace approximation polynomial                                 [-1f...+1f]
                      CP_TracePoly[i].isValid : Flag to indicate if trace polynomial is valid              [TRUE,FALSE]

  @c_switch_part   FIP_CFG_USE_EGO_TRACE               : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Switch to configure moving object traces component
  @c_switch_full   FIP_CFG_USE_EGO_TRACE               : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Switch to configure moving object traces component
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure CP sub-component in FCT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/11/2015

  @author          Norman Apel | norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CP_v_TracePreProc(void)
{
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  TraceID_t uTrIdx;             /*!< Current trace ID (index) */
  /* TraceID_t uNumValidTr = 0u; */    /*!< Counter of valid traces */ /* currently not used, comment out to reduce misra issues */
#endif

  if (  (CP_State == COMP_STATE_NOT_INITIALIZED)
      ||(CP_State == COMP_STATE_TEMPORARY_ERROR)
      ||(CP_State == COMP_STATE_PERMANENT_ERROR) )
  {
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
    /* Reset trace information for each trace */
    for (uTrIdx = 0u; uTrIdx < (TraceID_t)CP_NUM_TRACES; uTrIdx++)
    {
      CP_v_InitTraceAddData(&CP_TraceAdd[uTrIdx]);
    }
#endif
#if (FIP_CFG_USE_EGO_TRACE)
    /* Reset trace information for ego */
    CP_v_InitEgoTraceAddData(&CP_EgoTraceAdd);
#endif
  }
  else
  {
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
    /* First pass: go through all traces, calculating the trace polynomials as needed */
    for (uTrIdx = 0u; uTrIdx < CP_NUM_TRACES; uTrIdx++)
    {
      /* Get utility pointer to current trace's additional data */
      CP_t_TraceAddData * const pCurTraceAddData = &CP_TraceAdd[uTrIdx];
      CP_v_CalcMovObjTraceAddData(pCurTraceAddData, uTrIdx);
    /* If the trace polynomial approximation uses at least the minimum required
      number of points and it has positive weight, then it is considered 'valid' */
      
      /*Storing values in output of CP*/
      pt_CPOutput->CP_TracePoly[uTrIdx].fC0 = CP_TraceAdd[uTrIdx].ApproxPoly.fC0;
      pt_CPOutput->CP_TracePoly[uTrIdx].fC1 = CP_TraceAdd[uTrIdx].ApproxPoly.fC1;
      pt_CPOutput->CP_TracePoly[uTrIdx].fC2 = CP_TraceAdd[uTrIdx].ApproxPoly.fC2;
      pt_CPOutput->CP_TracePoly[uTrIdx].isValid = CP_TraceAdd[uTrIdx].ApproxPoly.isValid;
    }
#endif
#if (FIP_CFG_USE_EGO_TRACE)
    /* calculating the ego trace polynomials*/
    CP_v_CalcEgoTraceAddData(&CP_EgoTraceAdd);
#endif
  }
}
#endif /*((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FIP_CFG_USE_EGO_TRACE))*/

/*************************************************************************************************************************
  Functionname:    CP_v_PreProcess                                                                                  */ /*!

  @brief           Preprocess/ Set inputs to CP module

  @description     Preprocess/ Set inputs to CP module

                   @startuml
                   Partition CP_v_PreProcess{
                   Start 
                   : Set inputs;
                   : Reset CP input structure;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       pt_CPInputGlob : Reference to CP input structure instantiated in Frame

  @glob_in         -
  @glob_out        pt_CPInput : Pointer to CP input structure

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component in FCT

  @pre             - 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.10.2016
  @changed         25.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void CP_v_PreProcess(CPInputConst_t * pt_CPInputGlob)
{
  /* Assign local pointers */
  pt_CPInput = pt_CPInputGlob;

  /* Set inputs */
  CP_v_SetInput();

  /* Reset local pointers */
  pt_CPInput = NULL;
}

/*************************************************************************************************************************
  Functionname:    CP_v_Process                                                                                        */ /*!

  @brief           Main processing function of CP sub-component

  @description     Main processing function of CP sub-component

                   @startuml
                   Partition CP_v_Process{
                   Start 
                   : Call trace preprocessing;
                   : CP Measurement Freeze;
                   : Reset CP input structure;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       pt_CPInputGlob : Reference to global input struct to CP   [defined as per cp_ext.h]
  @param[in]       pt_CPOutputGlob : Reference to global output struct to CP [defined as per cp_ext.h]

  @glob_in         -
  @glob_out        pt_CPInput : Pointer to CP input structure
  @glob_out        pt_CPOutput : Pointer to CP output structure

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Switch to configure interface for old traces
  @c_switch_part   FCT_CFG_COLLISION_DETECTION         : Switch to configure FCT support for collision detection
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure CP sub-component in FCT

  @pre             CP_v_PreProcess (CPInputConst_t * pt_CPInputGlob)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    146: doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-146-00061542 \n
  
  @created         -
  @changed         12/11/2015

  @author          Norman Apel | norman.apel@contiautomotive.com
*************************************************************************************************************************/
void CP_v_Process(CPInputConst_t * pt_CPInputGlob, CPOutput_t * pt_CPOutputGlob)
{
  /* Assign local pointers */
  pt_CPInput = pt_CPInputGlob;
  pt_CPOutput = pt_CPOutputGlob;

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  /* Call trace preprocessing */
  CP_v_TracePreProc();
#endif /*FCT_CFG_OBJECT_TRACE_PREPROCESSSING*/

  CP_v_ACC_Process();

  /* CP Measurement Freeze */
  CP_v_MeasFreeze();

  /* Reset local pointers */
  pt_CPInput = NULL;
  pt_CPOutput = NULL;
}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    CP_v_MeasCallback                                                                                   */ /*!

  @brief           Central SI MEASFreezeDataMTS callback function

  @description     Central SI MEASFreezeDataMTS callback function. Since callback information is not used in SI, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

                   @startuml
                   Partition CP_v_MeasCallback{
                   : Return nothing;
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT           : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         07.03.2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
void CP_v_MeasCallback(void)
{
  return;
}
#endif


/*************************************************************************************************************************
  Functionname:    CP_v_MeasFreeze                                                                                  */ /*!

  @brief           Freeze CP Object data for simulation

  @description     Freeze CP Object data for simulation

                   @startuml
                   Partition CP_v_MeasFreeze{
                   Start 
                   : Get CP specific navi information;
                   : Fill in CP Trajectory information;
                   : Freeze device data;
                   : Get data for measurement freeze in simulation;
                   : Get Additional data stored for traces;
                   : Get Additional data stored for Ego trace;
                   : Freeze simulation data;
                   End 
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure 
                      t_FrameFreezes.pt_CP_DeviceMeasInfo->t_NaviMeasInfo : Structure for navi CP meas freeze
                      t_FrameFreezes.pt_CP_DeviceMeasInfo->UnFiltCourse
                      t_FrameFreezes.pt_CP_DeviceMeasInfo->Trajectory
                      t_FrameFreezes.pt_CP_DeviceMeasInfo->TraceTrajectory
                      t_FrameFreezes.pt_CP_DeviceMeasInfoFreeze : Structure for CP Device meas info freeze
                      t_FrameFreezes.pt_CP_DeviceMeasInfo : Sim Freeze of CP from Frame
                      t_FrameFreezes.pt_CP_SimMeasInfoFreeze : Structure for CP simulation meas info freeze
                      t_FrameFreezes.pt_CP_SimMeasInfo : Sim Freeze of SIT from Frame
  @glob_in         pt_CPOutput : Pointer to CP output structure 
                      CP_CourseData : Last cycle course data
                      CP_TrajectoryData : Data related to CP trajectory
  @glob_in         CP_TraceAdd[i] : Additional data stored for traces
  @glob_in         CP_EgoTraceAdd : Additional data stored for Ego trace
  @glob_out        pt_CPInput : Pointer to CP input structure                     
                      t_FrameFreezes.pt_CP_SimMeasInfo->t_CP_FreezeOutput : Structure used to store output of CP
                      t_FrameFreezes.pt_CP_SimMeasInfo->CP_TraceAdd[i] : Structure used to store trace additional data
                      t_FrameFreeze.pt_CP_SimMeasInfo->CP_EgoTraceAdd : Structure used to store ego trace additional data
  @glob_out        -

  @c_switch_part   FCT_SIMU                            : FCT support for ACC Simulation
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Switch to configure interface for old traces
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE   : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING        : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FIP_CFG_USE_EGO_TRACE               : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : Switch to configure FCT support for CP sub-component 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         3/8/2017
  @changed         3/8/2017

  @author          
*************************************************************************************************************************/
static void CP_v_MeasFreeze(void)
{
#ifdef FCT_SIMU
#if FCT_CFG_OBJECT_TRACE_PREPROCESSSING
  uint8 i;
#endif
#endif

  /*! Get data for measurement freeze in device */

  /*! Get CP specific navi information */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  CP_v_NaviSetMeasData(&(pt_CPInput->t_FrameFreezes.pt_CP_DeviceMeasInfo->t_NaviMeasInfo));
#endif

  /* Fill in CP Trajectory information */
  CP_v_CopyCourse2Meas(&(pt_CPOutput->CP_CourseData) , &(pt_CPInput->t_FrameFreezes.pt_CP_DeviceMeasInfo->UnFiltCourse));
  CP_v_CopyTraj2Meas(&(pt_CPOutput->CP_TrajectoryData) , &(pt_CPInput->t_FrameFreezes.pt_CP_DeviceMeasInfo->Trajectory));
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  CP_v_CopyTraceTraj2Meas(&CP_TraceTrajectory , &(pt_CPInput->t_FrameFreezes.pt_CP_DeviceMeasInfo->TraceTrajectory));
#endif
  /*! Freeze device data */
  FCT_FREEZE_DATA(pt_CPInput->t_FrameFreezes.pt_CP_DeviceMeasInfoFreeze, pt_CPInput->t_FrameFreezes.pt_CP_DeviceMeasInfo, &CP_v_MeasCallback); //PRQA S 3200
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Currently MEASFreezeDataMTS return value is not used */


#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  pt_CPInput->t_FrameFreezes.pt_CP_SimMeasInfo->t_CP_FreezeOutput = *(pt_CPOutput);

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  for(i = 0u; i < CP_NUM_TRACES; i++)
  {
    pt_CPInput->t_FrameFreezes.pt_CP_SimMeasInfo->CP_TraceAdd[i] = CP_TraceAdd[i];
  }
#endif

#if (FIP_CFG_USE_EGO_TRACE)
  pt_CPInput->t_FrameFreeze.pt_CP_SimMeasInfo->CP_EgoTraceAdd = CP_EgoTraceAdd;
#endif

  /*! Freeze simulation data */
  FCT_FREEZE_DATA(pt_CPInput->t_FrameFreezes.pt_CP_SimMeasInfoFreeze, pt_CPInput->t_FrameFreezes.pt_CP_SimMeasInfo, CP_v_MeasCallback);
#endif

}
/*************************************************************************************************************************
  Functionname:    CP_v_InitPersistentData                                                                          */ /*!

  @brief           Initialize persistent memory structures in CP component

  @description     Initialize persistent memory structures in CP component

                   @startuml
                   Partition CP_v_InitPersistentData{
                   Start
                   : Initialize Curve of the trajectory, Curvature variance and Curvature Gradient\n of ego vehicle path, Side slip angle, Side slip angle variance of ego vehicle,\n Trace approximation polynomial;
                   : Initialize Pick up range of moving object and\n base moving object,\n Road Type, Lane Matrix, Lane Change Info;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_CPOutput : Pointer to CP output structure
                      CP_CourseData : Structure containing last cycle course data
                      CP_TrajectoryData : Structure containing data related to CP trajectory
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_CourseData.fCurve : Curve of the trajectory                                                                [-1.f ... +1.f]m^-1
                      CP_CourseData.fCurveVar : Curvature variance of ego vehicle path                                              [-1.f ... +1.f]m^-1
                      CP_CourseData.fCurveGradient : Curvature Gradient of ego vehicle path                                         [-1.f ... +1.f]m^-2
                      CP_CourseData.SideSlipAngle : Side slip angle of ego vehicle                                                  [-PI ... +PI] rad
                      CP_CourseData.SideSlipAngleVariance : Side slip angle variance of ego vehicle                                 [-PI ... +PI] rad
                      CP_TracePoly[i].fC0 : Trace approximation polynomial                                                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      CP_TracePoly[i].fC1 : Trace approximation polynomial                                                          [-1.f...+1.f]
                      CP_TracePoly[i].fC2 : Trace approximation polynomial                                                          [-1f....+1.f]
                      CP_TracePoly[i].isValid : Flag to indicate if trace polynomial is valid                                       [TRUE,FALSE]
  @glob_out        pt_CPInput : Pointer to CP input structure
                      pt_CPInput->pt_FIPNaviData : Pointer to Fip Navi Data structure
                      pt_CPInput->t_OOI.pt_OOIRelObj : Structure containing information of OOI-0
                      t_LAInput.pt_ScaleBracketState : State of trace bracket adaption                                              [LA_t_ScaleBracketState defined in la_ext.h]
                      t_LAInput.pt_MovingObjPickUpRange : Pick up range of moving object                                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAInput.pt_MovingObjBasePickUpRange : Pick up range of base moving object                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_CPInput->pt_FIPRoadType : Pointer to Fip Road Type Data structure
                      pt_CPInput->pt_FIPRoad     : Pointer to Fip Road Data structure
                      t_SIT.ps_GetLaneChangeProbability : Lane change probability                                                   [-100 ... 100]
                      t_SIT.pt_LaneChangeTimeGap : Structure containing information for each lane change phase
                      pt_CPInput->pt_FIPCamLane  : Pointer to Fip Camera Lane Data structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace : Structure containing moving object static trace array
                      t_FIPMOT.ps_EgoTraceNumberOfPoints : Number of trace points of ego trace                                      [signed char data type] [0...+5] 
                      t_FIPMOT.pf_EgoTracePointX0 : array of x coordinates of trace points                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_FIPMOT.pf_EgoTracePointY0 : array of y coordinates of trace points                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_FIPMOT.b_Dummy : Dummy member so that structure is not empty                                                [TRUE, FALSE]

  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING                                : Switch to configure interface for old traces
  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE                                  : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Configuration switch which moves trace brackets in case of ego lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Configuration switch which moves trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch which moves trace brackets w.r.t. BLINKER FEATURE
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC 
  @c_switch_part   FCT_CFG_ACC_SITUATION                                              : FCT support for ACC SIT (situation) sub-component
  @c_switch_part   FCT_CFG_SEN_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_USE_FCT_DYNAMIC_TRACES                                     : Configuration switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_part   FIP_CFG_USE_EGO_TRACE                                              : Configuration switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_swtich_part   FCT_CFG_ACC_OOI                                                    : Configuration switch to configure OOI sub-component for FCT_ACC
  @c_swtich_part   SLATE_CFG_PARALLEL_LANE_CHANGE                                     : Configuration switch for enabling Parallel lane change detection
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                                          : Switch to configure FCT support for CP sub-component 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         25.10.2016
  @changed         25.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void CP_v_InitPersistentData(void)
{
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  TraceID_t iTr;
#endif

/*Initialising Output*/
  pt_CPOutput->CP_CourseData.fCurve                 = 0.0f;
  pt_CPOutput->CP_CourseData.fCurveVar              = 0.0f;
  pt_CPOutput->CP_CourseData.fCurveGradient         = 0.0f;
  pt_CPOutput->CP_CourseData.SideSlipAngle          = 0.0f;
  pt_CPOutput->CP_CourseData.SideSlipAngleVariance  = 0.0f;

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_CPOutput->TraceTrajectory.fCurve             = 0.f;
  pt_CPOutput->TraceTrajectory.fMaxDist           = 0.f;
  pt_CPOutput->TraceTrajectory.fMeanSquaredError  = CP_TRAJ_INVALID_VALUE;
  pt_CPOutput->TraceTrajectory.fWeight            = 0.f;
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  for (iTr=0u; iTr<CP_NUM_TRACES; iTr++)
  {
    pt_CPOutput->CP_TracePoly[iTr].fC0       = 0.f;
    pt_CPOutput->CP_TracePoly[iTr].fC1       = 0.f;
    pt_CPOutput->CP_TracePoly[iTr].fC2       = 0.f;
    pt_CPOutput->CP_TracePoly[iTr].isValid   = FALSE;

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTr].b_SetTraceLeftLaneCutOut      = FALSE;
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTr].b_SetTraceRightLaneCutOut     = FALSE;
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTr].b_SetLeftTurnIndicatorCutOut  = FALSE;
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTr].b_SetRightTurnIndicatorCutOut = FALSE;
#endif /*  (SLATE_CFG_PARALLEL_LANE_CHANGE) */
  }
#endif
#if (CP_SW_VERSION_NUMBER >= 0x203u)
  CP_v_TrajectoryInit(&(pt_CPOutput->CP_CourseData), CP_USE_ROADESTIM , CP_USE_OBJTRACES , (boolean)CP_USE_CAM_LANE_FUSION, CP_USE_NAVI_PATH_FUSION, &(pt_CPOutput->CP_TrajectoryData), &(pt_CPOutput->TraceTrajectory));
#elif (CP_SW_VERSION_NUMBER >= 0x200u)
  CP_v_TrajectoryInit(&(pt_CPOutput->CP_CourseData), CP_USE_ROADESTIM , CP_USE_OBJTRACES , (boolean)CP_USE_CAM_LANE_FUSION, &(pt_CPOutput->CP_TrajectoryData));
#else
  CP_v_TrajectoryInit(&(pt_CPOutput->CP_CourseData), CP_USE_ROADESTIM , CP_USE_OBJTRACES , &(pt_CPOutput->CP_TrajectoryData));
#endif

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_CPInput->pt_FIPNaviData = NULL;
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

  /* Initialize inputs, moved from CP_v_InitEveryCycle */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
    pt_CPInput->t_LAInput.pt_ScaleBracketState = NULL;
#endif
    pt_CPInput->t_LAInput.pt_MovingObjPickUpRange = NULL;
    pt_CPInput->t_LAInput.pt_MovingObjBasePickUpRange = NULL;
#endif
#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_CPInput->pt_FIPRoadType = NULL;
  pt_CPInput->pt_FIPRoad     = NULL;
  pt_CPInput->pt_FIPOA       = NULL;
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if ((FCT_CFG_USE_FCT_STATIC_TRACES) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
  pt_CPInput->pt_FIPMOT           = NULL;
#endif
#endif
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
   pt_CPInput->pt_FIPLaneMatrix             = NULL;
#endif /* FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */
#endif
  /* Initialize inputs */
  #if (FCT_CFG_ACC_SITUATION)
/*intialize lane change output pointer*/
  pt_CPInput->t_SIT.pt_GetLaneChangeInfo = NULL;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)  
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_CPInput->t_SIT.pf_CrossingDistTrace = NULL;
  pt_CPInput->pt_FIPTO                   = NULL;
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#endif /*END IF FCT_CFG_ACC_SITUATION */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_CPInput->pt_FIPCamLane = NULL;

#endif /*END IF SLATE_CFG_CAM_LANE_INTERFACE*/
#if (FCT_CFG_ACC_OOI)
  pt_CPInput->t_OOI.pt_OOIRelObj = NULL;
#endif

  /*Note: Pointers to Inputs from RTE Ports are not initialized because their value is reset every cycle from external inputs */

}
/*************************************************************************************************************************
  Functionname:    CP_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output data structures for CP component

  @description     Initialize input-output data structures for CP component

                   @startuml
                   Partition CP_v_InitEveryCycle{
                   : Initialize Curve of the trajectory, Max Dist, Weight;
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -  

  @glob_in         -
  @glob_out        pt_CPInput : Pointer to CP input structure
  					          b_Dummy : Dummy member so that structure is not empty [TRUE, FALSE]

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_swtich_part   SLATE_CFG_PARALLEL_LANE_CHANGE : Configuration switch for enabling Parallel lane change detection
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 1727277036-
*************************************************************************************************************************/
void CP_v_InitEveryCycle(void)
{
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  uint8 i;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  for (i = 0u; i < FIP_STATIC_TRACE_NO_OF_TRACES; i++)
  {
#ifdef FCT_SIMU
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[i].iObjNr            = OBJ_INDEX_NO_OBJECT;
#endif
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[i].t_TraceLaneChange = SLATE_LC_NONE;
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[i].f_AveragePathDifference = 0.f;
  }
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
}

/*************************************************************************************************************************
  Functionname:    CP_v_SetInput                                                                                    */ /*!

  @brief           Set/assign values to CP input structure

  @description     Set/assign values to CP input structure

                   @startuml
                   Partition CP_v_SetInput{
                   Start
                   : Get FIP Road Type, Fip Road Data, Lane Matrix,\n Lane Change Info, Pick up range of moving object and base moving object;
                   : Get Inputs from RTE Input Ports;
                   : Get Tunnel Probability;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        pt_CPInput : Pointer to CP input structure
                      pt_CPInput->pt_FIPNaviData : Pointer to Fip Navi Data structure
                      pt_CPInput->pt_FIPRoadType : Pointer to Fip Road Type Data structure
                      pt_CPInput->pt_FIPRoad     : Pointer to Fip Road Data structure
                      pt_CPInput->pt_FIPCamLane  : Pointer to Fip Camera Lane Data structure
                      pt_CPInput->t_OOI.pt_OOIRelObj : Structure containing information of OOI-0

                      t_SIT.ps_GetLaneChangeProbability : Lane change probability                                                   [-100 ... 100]
                      t_SIT.pt_LaneChangeTimeGap : Structure containing information for each lane change phase
                      t_LAInput.b_Dummy : Dummy member so that structure is not empty                                               [TRUE, FALSE]
                      t_LAInput.pt_ScaleBracketState : State of trace bracket adaption                                              [LA_t_ScaleBracketState defined in la_ext.h]
                      t_LAInput.pt_MovingObjPickUpRange : Pick up range of moving object                                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAInput.pt_MovingObjBasePickUpRange : Pick up range of base moving object                                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

                      t_FIPMOT.pt_FIPMovObjStaticTrace : Structure containing moving object static trace array
                      t_FIPMOT.ps_EgoTraceNumberOfPoints : Number of trace points of ego trace                                      [signed char data type] [0...+5] 
                      t_FIPMOT.pf_EgoTracePointX0 : array of x coordinates of trace points                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_FIPMOT.pf_EgoTracePointY0 : array of y coordinates of trace points                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      t_RTE.pf_ObjLongDisp : Longitudinal displacement of an object i                                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m                
                      t_RTE.pf_ObjLatDisp : Lateral distance of object i                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m             
                      t_RTE.pu_AccObjQuality : Get pre-selection quality of given FCT object                                        [Full range of unsigned char]              
                      t_RTE.pu_ObjExistProbability : Object probability of existence                                                [0 ... 100] as mentioned in algo_glob.h v1.53    
                      t_RTE.pf_EgoLongVel : Ego velocity provided by VDY                                                            [-330.f ... 330.f] m/s   
                      t_RTE.pf_EgoSideSlip : Side slip angle of ego vehicle                                                         [-PI +PI] rad             
                      t_RTE.pf_EgoSideSlipVar : Side slip angle variance of ego vehicle                                             [-PI +PI] rad    
                      t_RTE.pf_EgoCurve : Curvature of ego vehicle path                                                             [-1.f ... +1.f]m^-1         
                      t_RTE.pf_EgoCurveGrad : Curvature Gradient of ego vehicle path                                                [-1.f ... +1.f]m^-2 
                      t_RTE.pf_EgoCurveVar : Curvature variance of ego vehicle path                                                 [-1.f ... +1.f]m^-1
                      t_RTE.pf_EgoDrvIntCurve : Curvature of ego vehicle path driving into a curve                                  [-1.f ... +1.f]m^-1   
                      t_RTE.pf_SensorYPos : Lateral position of sensor mounting                                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m              
                      t_RTE.pf_FCTBumperToCoG : distance from Bumper to Center of Gravity                                           [Full range of float32  >= 0.F] 

                      pb_ObjIsShadow : Boolean indicating if object is shadow                                                       [TRUE,FALSE]

  @c_switch_part   FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE                                  : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING                                       : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   FCT_CFG_ACC_SITUATION                                              : FCT support for ACC SIT (situation) sub-component
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION                                       : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM              : Configuration switch which moves trace brackets in case of ego lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM            : Configuration switch which moves trace brackets in case of no lane change
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch which moves trace brackets w.r.t. BLINKER FEATURE
  @c_switch_part   FCT_CFG_SEN_CAM_LANE_INTERFACE                                     : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING                                : Switch to configure interface for old traces
  @c_switch_part   FIP_CFG_USE_EGO_TRACE                                              : Configuration switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_swtich_part   FCT_CFG_ACC_OOI                                                    : Configuration switch to configure OOI sub-component for FCT_ACC
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST                                    : Configuration switch that enables ARS-technology specific object list
  @c_swtich_part   SLATE_CFG_PARALLEL_LANE_CHANGE                                     : Configuration switch for enabling Parallel lane change detection
  @c_switch_full   FCT_CFG_COURSE_PREDICTION                                          : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 1727277036-
*************************************************************************************************************************/
void CP_v_SetInput(void)
{
  /* Dummy to be deleted when no switches are required */


#if (FCT_CFG_INPUT_PREPROCESSSING)
  pt_CPInput->pt_FIPRoadType              = FIP_pt_RT_GetRoadType();
  pt_CPInput->pt_FIPRoad                  = FIP_pt_RD_GetRoadData();
  pt_CPInput->pt_FIPOA                    = FIP_pt_GetObjAttributes();
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  pt_CPInput->pt_FIPNaviData              = FIP_pt_ND_GetNaviData();
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
  pt_CPInput->pt_FIPMOT                     = FIP_pt_GetMOTData();
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
   pt_CPInput->pt_FIPLaneMatrix             = FIP_pt_LM_GetLaneMatrixData();
#endif /* FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */

#endif /*FCT_CFG_INPUT_PREPROCESSING*/
#if (FCT_CFG_ACC_SITUATION)
/* set lane change info*/
    pt_CPInput->t_SIT.pt_GetLaneChangeInfo = SIT_pt_GetLaneChangePhase();
#endif /* END IF FCT_CFG_ACC_SITUATION */
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  pt_CPInput->t_SIT.pf_CrossingDistTrace = &SIT_pf_GetCrossingDistTrace;
  pt_CPInput->pt_FIPTO                   = FIP_pt_TO_GetTrafficOrientation();
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  pt_CPInput->t_LAInput.pt_ScaleBracketState = LA_pt_ScaleBracketState();
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
         LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
         LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
  pt_CPInput->t_LAInput.pt_MovingObjPickUpRange = LA_pt_GetMovingObjPickupRange();
  pt_CPInput->t_LAInput.pt_MovingObjBasePickUpRange = LA_pt_GetMovingObjBasePickUpRange();

#endif /* FCT_CFG_ACC_LANE_ASSOCIATION */

#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_CPInput->pt_FIPCamLane                = FIP_pt_CL_GetCamLaneData();
#endif /*END IF SLATE_CFG_CAM_LANE_INTERFACE*/

/*! Inputs from RTE Input Ports */
  pt_CPInput->t_RTE.pf_ObjLongDisp                = &SLATE_pf_GetObjLongDisp;
  pt_CPInput->t_RTE.pf_ObjLatDisp                 = &SLATE_pf_GetObjLatDisp;
  pt_CPInput->t_RTE.pu_AccObjQuality              = &SLATE_u_GetAccQuality;
  pt_CPInput->t_RTE.pu_ObjExistProbability        = &SLATE_pu_GetObjExistProbability;
  pt_CPInput->t_RTE.pf_EgoLongVel                 = SLATE_pf_GetEgoLongVel();
  pt_CPInput->t_RTE.pf_EgoSideSlip                = SLATE_pf_GetEgoSideSlip();
  pt_CPInput->t_RTE.pf_EgoSideSlipVar             = SLATE_pf_GetEgoSideSlipVar();
  pt_CPInput->t_RTE.pf_EgoCurve                   = SLATE_pf_GetEgoCurve();
  pt_CPInput->t_RTE.pf_EgoCurveGrad               = SLATE_pf_GetEgoCurveGrad();
  pt_CPInput->t_RTE.pf_EgoCurveVar                = SLATE_pf_GetEgoCurveVar();
  pt_CPInput->t_RTE.pf_EgoDrvIntCurve             = SLATE_pf_GetEgoDrvIntCurve();
  pt_CPInput->t_RTE.pf_SensorYPos                 = SLATE_pf_GetSensorYPos();
  pt_CPInput->t_RTE.pf_FCTBumperToCoG             = SLATE_pf_GetBumperToCoG();
#if (SLATE_CFG_CAM_LANE_INTERFACE)
  pt_CPInput->t_RTE.pt_CamLaneData                = SLATE_pt_GetCamLaneData();
#endif
#if (FCT_CFG_ACC_OOI)
  pt_CPInput->t_OOI.pt_OOIRelObj                 = OOI_pt_GetRelObj();
#endif
  pt_CPInput->t_RTE.pb_ObjIsShadow                = &SLATE_b_GetObjIsShadow;
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  pt_CPInput->t_RTE.pf_TunnelProbability = (const float32 *) &(SLATE_p_GetPerfDegr()->fTunnelProbability);
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
   pt_CPInput->t_RTE.pt_TurnIndicator             = SLATE_pt_GetTurnIndicator();
#endif/* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT */
}
/*************************************************************************************************************************
  Functionname:    CP_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of CP sub-component

  @description     Set operation mode of CP sub-component based on given value

                   @startuml
                   Partition CP_v_SetOperationMode{
                   Start
                   : Get Operation Mode;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       t_CPOpModeValue : Operation mode that will be set for CP [full range of datatype SLATECompState_t as in slate_types.h]

  @glob_in         -
  @glob_out        @ref CP_State

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void CP_v_SetOperationMode(SLATECompState_t const t_CPOpModeValue)
{
  CP_State = t_CPOpModeValue;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
/** @} end defgroup */
#endif /*FCT_CFG_COURSE_PREDICTION*/

