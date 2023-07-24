/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_object_traces.c

DESCRIPTION:               ACC FIP object traces processing module

AUTHOR:                    Wolfgang Borgs 

CREATION DATE:             02.09.2015

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip_object_traces.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_object_traces FIP Traces
@ingroup fip
@brief          Main file for processing of object traces. Functions to calculate static, dynamic, and ego
	            traces are called from this file.\n\n

@{

*/
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
LOCAL VARIABLES
*****************************************************************************/
#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE)
/*ego motion attributes structures*/
SET_MEMSEC_VAR(FIP_TrMat2DCOFFwdTgtSync)
static GDBTrafoMatrix2D_t FIP_TrMat2DCOFFwdTgtSync;

SET_MEMSEC_VAR(FIP_TrMat2DCOFForJitTgtSync)
static GDBTrafoMatrix2D_t FIP_TrMat2DCOFForJitTgtSync;

#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) */

#if (FCT_CFG_TJA_OBJECT_TRACE)
#ifdef FCT_SIMU
/* In case of simulation, for external visibility in sim_swc_fct_draw.cpp */
SET_MEMSEC_VAR(FIPObjTraceTrajectory)
FIP_ObjTraceTrajectory_t FIPObjTraceTrajectory; 
#else
SET_MEMSEC_VAR(FIPObjTraceTrajectory)
static FIP_ObjTraceTrajectory_t FIPObjTraceTrajectory;
#endif
#endif /* END IF (FCT_CFG_TJA_OBJECT_TRACE) */

/*! Definition of pointer to FIPMovingObjectTraces output structure for access within this sub module */
SET_MEMSEC_VAR(pt_FIP_MOT_Output)
FIP_MOT_Output_t * pt_FIP_MOT_Output;

/*****************************************************************************
FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_MOT_InitPersistentData(void);
#if (FCT_CFG_TJA_OBJECT_TRACE)
static void FIP_v_InitObjTraceTrajectory(FIP_ObjTraceTrajectory_t* const pObjTrajs);
static void FIP_v_ObjTraces2Trajectories(const MovingObjectTraces_t* const pObjTraces, const EM_t_GenObjectList* const pEmGenObjList, FIP_ObjTraceTrajectory_t* const pObjTrajs);
#endif /* END IF (FCT_CFG_TJA_OBJECT_TRACE) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE)
/*get Variance of Object depending on Distance*/
float32 FIP_f_GetObjObservationVariance ( ObjNumber_t iObj );	// PRQA S 3447
/* date: 2020-02-26, reviewer: Dhamodharan Subramanian, reason: Not safety critical. */
/* update the motion attributes for the Ego vehicle*/
static void FIP_v_UpdateEgoMotion            (void);
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
/*************************************************************************************************************************
  Functionname:    FIP_v_ObjTraceProcess                                                                             */ /*!

  @brief           FCT Object Traces Processing Main

  @description     FCT Object Traces Processing Main
                    - Evaluation of trajectories for all object traces
  
  @startuml 
    Partition FIP_v_ObjTraceProcess
    Start
  	Note right: This function processes FCT Object Traces
  	- Initialize non-persistent output data structures and variables with the default values
  
  	If (Config switch for using Traces computed in EM is enabled \n AND \n FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT switch is enabled) then (True)
  		- Update FCT local variables using data from RTE ports which contain data about traces computed in EM
  	Else (False)
  	Endif
  
  	If (FCT Computed Traces in FIP module \n OR \n FCT Computed Dynamic Traces in FIP module \n OR \n FCT Computed Ego Trace in FIP module switches are enabled) then (True)
  		- Update Ego motion Matrices
  	Endif
  
  	If (FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT switch is enabled) then (True)
  		If (FCT Computed Traces in FIP module switch is enabled) then (True)
  			- Compute moving object traces
  		Else (False)
  		Endif
  	Else (False)
  	Endif
  
  	If (FCT Computed Dynamic Trace in FIP module switch is enabled) then (True)
  			- Compute moving object dynamic traces
  	Else (False)
  	Endif
  
  	If (FCT Computed Ego Trace in FIP module switch is enabled) then (True)
  			- Compute ego trace
  	Else (False)
  	Endif
  	If (FCT support for TJA specific Object Trace Preprocessing switch is enabled) then (True)
  		- Initialization of whole trajectory structure
  		- Evaluation of trajectories for all object traces
  		- Update trajectories information via custom port
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_MOT_InputGlobal : Reference to input structure for MOT sub module instantiated in Frame
  @param[in]       pt_FIP_MOT_OutputGlobal : Reference to output structure for MOT sub module instantiated in Frame
  
  @glob_in         GET_MOV_OBJ_TRACE_DATA_PTR : Pointer to object traces
  @glob_in         GET_EM_PUB_OBJ_DATA_PTR : Pointer to EM object list
  @glob_out        FIPObjTraceTrajectory . trajectory structure
  
  @c_switch_part   FCT_CFG_TJA_OBJECT_TRACE : FCT support for TJA specific Object Trace Preprocessing
  @c_switch_part   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for enabling or disabling FCT Computed static Trace in FIP module
  @c_switch_part   SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES : Config switch for using Traces computed in EM, ATTENTION this is mutually exclusive with FCT_CFG_USE_FCT_STATIC_TRACES
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed! 
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed dynamic Trace in FIP module
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             FIP_v_MOT_PreProcess(FIP_MOT_InputConst_t * pt_FIP_MOT_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.09.2015
  @changed         05.04.2016

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com
*************************************************************************************************************************/
void FIP_v_ObjTraceProcess(FIP_MOT_Output_t * pt_FIP_MOT_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_MOT_Output = pt_FIP_MOT_OutputGlobal;

#if ((SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) && (FCT_CFG_OBJECT_TRACE_PREPROCESSSING))
  /* Update FCT local variables using data from RTE ports which contain data about traces computed in EM */
  FIP_v_PreProcessEMTraces();
#endif /* (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE)
  /*Update Ego motion Matrices*/
  FIP_v_UpdateEgoMotion();
#endif /*FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE*/

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
  FIP_v_CalculateMovingObjectStaticTraces();
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */
#endif

#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
  FIP_v_CalculateMovingObjectDynamicTraces();
#endif /* END IF (FCT_CFG_USE_FCT_DYNAMIC_TRACES) */

#if (FIP_CFG_USE_EGO_TRACE)
  FIP_v_CalculateEgoTrace();
#endif
#if (FCT_CFG_TJA_OBJECT_TRACE)

  /* Initialization of whole trajectory structure */
  FIP_v_InitObjTraceTrajectory(&FIPObjTraceTrajectory);

  /* Evaluation of trajectories for all object traces */
  FIP_v_ObjTraces2Trajectories(GET_MOV_OBJ_TRACE_DATA_PTR, GET_EM_PUB_OBJ_DATA_PTR, &FIPObjTraceTrajectory);

  /* Output of trajectories via custom port */
  FIP_v_OutputTrajectoryCustomData(&FIPObjTraceTrajectory, GET_MOV_OBJ_TRACE_DATA_PTR->sSigHeader.uiTimeStamp);
#endif /* END IF (FCT_CFG_TJA_OBJECT_TRACE) */
  
  /* Reset local pointers */
  pt_FIP_MOT_Output = NULL;
}
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE)) */

/*************************************************************************************************************************
  Functionname:    FIP_v_MOT_InitPersistentData                                                                     */ /*!

  @brief           Initialize persistent data in MOT sub module

  @description     Initialize persistent data in MOT sub module, FIP_v_Init_Static_Traces, FIP_v_Init_Dynamic_Traces, 
                   FIP_v_Init_Ego_Trace and FIP_v_InitObjTraceTrajectory are initialized.
  
  @startuml 
    Partition FIP_v_MOT_InitPersistentData 
    Start
    	Note right: This function initializes Moving Object Trace structure only once in the first cycle	
    	- Depending on the available switches/sources set default values to the persistent data structure
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   FCT_CFG_TJA_OBJECT_TRACE : FCT support for TJA specific Object Trace Preprocessing
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed! 
  @c_switch_part   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed dynamic Trace in FIP module
  @c_switch_part   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed! 

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
static void FIP_v_MOT_InitPersistentData(void)
{
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  /* Static traces either from EM or computed in FIP */
  FIP_v_Init_Static_Traces();
#endif

#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
  FIP_v_Init_Dynamic_Traces();
#endif /* END IF (FCT_CFG_USE_FCT_DYNAMIC_TRACES) */

#if (FIP_CFG_USE_EGO_TRACE)
  FIP_v_Init_Ego_Trace();
#endif

#if (FCT_CFG_TJA_OBJECT_TRACE)
  /* Initialization of whole trajectory structure */
  FIP_v_InitObjTraceTrajectory(&FIPObjTraceTrajectory);
#endif /* END IF (FCT_CFG_TJA_OBJECT_TRACE) */
}

#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
/*************************************************************************************************************************
  Functionname:    FIP_v_InitGlobalObjTraceData                                                                     */ /*!

  @brief           FCT Object Traces Processing Initialization

  @description     FCT Object Traces Processing Initialization. Both the persistent data and non-persistent data are initialized.
                 
  @startuml 
    Partition FIP_v_InitGlobalObjTraceData
    Start
    	Note right: This function initializes the persistent data in the Moving Obect Traces	
    	- Depending on the available sources/switches set default values to the persistent data structures
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_MOT_InputGlobal : Reference to FIP MOT module input
  @param[in]       pt_FIP_MOT_OutputGlobal : Reference to FIP MOT module output
  
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed! 
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed dynamic Trace in FIP module
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.09.2015
  @changed         -

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com
*************************************************************************************************************************/
void FIP_v_InitGlobalObjTraceData(FIP_MOT_Output_t * pt_FIP_MOT_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_MOT_Output = pt_FIP_MOT_OutputGlobal;

  /* Initialize persistent data structures in MOT sub module */
  FIP_v_MOT_InitPersistentData();

  /* Reset local pointers */
  pt_FIP_MOT_Output = NULL;
}
  
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE)) */

#if (FCT_CFG_TJA_OBJECT_TRACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_InitObjTraceTrajectory                                                                     */ /*!

  @brief           Initialization of trajectories

  @description     Initialization of whole trajectory structure

  @startuml 
    Partition FIP_v_InitObjTraceTrajectory
    Start
    	Note right: This function initializes the whole moving object trajectory structure
    	- Iterate through each of number of Traces	
    	- Initialize Object Trace Trajectory structure
    Stop
  @enduml

  @return          -

  @param[out]      pObjTrajs : Pointer to Object Trace Trajectory structure to be filled
                       uiTrajsCount : Number of valid trajectories in following array [0u]
                       ObjTrajects[i] : Array of Trace Trajectory structures with i in [0u ... TRACE_NO_OF_TRACES[
                         tObjNum : FCT ID of trajectory object [0u]
 	                       fLength : Valid length [0.0F] m
 	                       fPosX0 : Min X-Position [0.0F] m
 	                       fPosY0 : Y-Position at X=0 [0.0F] m
 	                       fAngle : Slope at X=0 [0.0F] rad
 	                       fCurveC0 : Curvature at X=0 [0.0F] 1/m
 	                       fCurveC1 : Change of Curvature [0.0F] 1/m^2
 	                       fPosY0Dev : Standard Deviation of Y-Position [0.0F]
 	                       fAngleDev : Standard Deviation of Slope [0.0F]
 	                       fCurveC0Dev : Standard Deviation of Curvature [0.0F]
 	                       fCurveC1Dev : Standard Deviation of Curvature change [0.0F]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!
  @c_switch_full   FCT_CFG_TJA_OBJECT_TRACE : FCT support for TJA specific Object Trace Preprocessing

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.04.2016
  @changed         05.04.2016

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void FIP_v_InitObjTraceTrajectory(FIP_ObjTraceTrajectory_t* const pObjTrajs)
{
  uint8 uiTraj;

  pObjTrajs->uiTrajsCount = 0u;
  for (uiTraj=0u; uiTraj<TRACE_NO_OF_TRACES; uiTraj++)
  {
    pObjTrajs->ObjTrajects[uiTraj].tObjNum = OBJ_INDEX_NO_OBJECT;
    pObjTrajs->ObjTrajects[uiTraj].fLength = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fPosX0 = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fPosY0 = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fAngle = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fCurveC0 = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fCurveC1 = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fPosY0Dev = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fAngleDev = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fCurveC0Dev = 0.0F;
    pObjTrajs->ObjTrajects[uiTraj].fCurveC1Dev = 0.0F;
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_ObjTraces2Trajectories                                                                     */ /*!

  @brief           FCT Transform Object Traces to Trajectories

  @description     Iterate over all traces and call the function CAL_v_CalcPointApproxPolyL3Ext to determine the 
                   3rd order polynomial of each trace. The output structure is filled.
  
  @startuml 
    Partition FIP_v_ObjTraces2Trajectories
    Start
  	Note right: This function transforms Object Traces to Trajectories
  	- Iterate through each of number of Traces
  	If(Trace has any sample) then (True)
    		If(Trace has valid object) then (True)
    			If(Last sample is more than Minimum length \n of 1st segment between object and trace far from \n current object position) then (True)
    				- Set useflag to TRUE in case of sufficient x-distance
    			Else (False)
    				- Set useflag to FALSE in case of insufficient x-distance
    			Endif
    		Else (False)
  		- Set useflag to FALSE in case of invalid object
  		- Set object id to 0 in order to prevent array out of bounds
  		Endif
  		- Calculate 3rd order polynomial by approximating sample points from trace and referenced object
  	
  		If (if polynomial is valid) then (True)
  			- Assign values from polynomial and trace to output trajectory structure
    		Else (False)
    		Endif
    	Else (False)
    	Endif
    Stop
  @enduml

  @return          -

  @param[in]       pObjTraces : Information about object traces
                       ObjectTrace[i]: Array of Trace Trajectory structures with i in [0u ... TRACE_NO_OF_TRACES[
                        iNumberOfPoints : Number of sample point [0u ... TRACE_NO_OF_POINTS[ for i in [0u ... TRACE_NO_OF_TRACES[
                        uiReferenceToFCTObject : FCT ID of trace object [0u ... EM_N_OBJECTS[ for i in [0u ... TRACE_NO_OF_TRACES[
                        fTracePointX : X-Position of trace point j [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m  
                           for i in [0u ... TRACE_NO_OF_TRACES] with j in [0u ... TRACE_NO_OF_POINTS[
                        fTracePointY : Y-Position of trace point j [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]m  
                           for i in [0u ... TRACE_NO_OF_TRACES] j in [0u ... TRACE_NO_OF_POINTS[
                         fTracePointYStdDev : Standard deviation of Y-Position [full range of datatype float32]
  @param[in]       pEmGenObjList : Pointer to EM generic object list
                       aObject[i].Kinematic.fDistX : Longitudinal distance to object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                           with i in [0u ... EM_N_OBJECTS[
  @param[out]      pObjTrajs : Pointer to Object Trace Trajectory structure to be filled
                       uiTrajsCount : Number of valid trajectories in following array [0u ... TRACE_NO_OF_TRACES[
                       ObjTrajects[i] : Array of Trace Trajectory structures with i in [0u ... TRACE_NO_OF_TRACES[
                         tObjNum : FCT ID of trajectory object [0u ... EM_N_OBJECTS[
 	                       fLength : Valid length [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
 	                       fPosX0 : Min X-Position [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
 	                       fPosY0 : Y-Position at X=0 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
 	                       fAngle : Slope at X=0 [-PI/2 ... PI/2] rad
 	                       fCurveC0 : Curvature at X=0 [-1.0 ... 1.0] 1/m
 	                       fCurveC1 : Change of Curvature [-1.0 ... 1.0] 1/m^2
 	                       fPosY0Dev : Standard Deviation of Y-Position [full range of datatype float32]
 	                       fAngleDev : Standard Deviation of Slope [full range of datatype float32]
 	                       fCurveC0Dev : Standard Deviation of Curvature [full range of datatype float32]
 	                       fCurveC1Dev : Standard Deviation of Curvature change [full range of datatype float32]
  
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!
  @c_switch_full   FCT_CFG_TJA_OBJECT_TRACE : FCT support for TJA specific Object Trace Preprocessing

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.09.2015
  @changed         04.04.2016

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void FIP_v_ObjTraces2Trajectories(const MovingObjectTraces_t* const pObjTraces, const EM_t_GenObjectList* const pEmGenObjList, FIP_ObjTraceTrajectory_t* const pObjTrajs)
{
  boolean bUseActObject; 
  uint8 uiTrace;
  uint8 uiTraj;

  /* operate on all traces of input trace structure */
  uiTraj = 0u;
  for (uiTrace=0u; uiTrace<TRACE_NO_OF_TRACES; uiTrace++)
  {
    CAL_t_TracePolyL3 Poly;
    uint8 uiObject;

    /* if trace is valid */
    if (pObjTraces->ObjectTrace[uiTrace].iNumberOfPoints > 0)
    {
      /* Find referenced object */
      uiObject = pObjTraces->ObjectTrace[uiTrace].uiReferenceToFCTObject;
      /* In case of valid object */
      if (uiObject < EM_N_OBJECTS)
      {
        /* Set useflag to TRUE in case of sufficient x-distance */
        if (pEmGenObjList->aObject[uiObject].Kinematic.fDistX > (pObjTraces->ObjectTrace[uiTrace].fTracePointX[0] + FIP_OBJECT_TRACE_SEG_LEN_MIN))
        {
          bUseActObject = TRUE;
        }
        /* Set useflag to FALSE in case of insufficient x-distance */
        else
        {
          bUseActObject = FALSE;
        }
      }
      else
      {
        /* Set useflag to FALSE in case of invalid object */
        bUseActObject = FALSE;
        uiObject = 0u;  /* Set object id to 0 in order to prevent array out of bounds in CAL_v_CalcPointApproxPolyL3Ext. 
                         pEmGenObjList->aObject[uiObject].Kinematic not used since bUseActObject == FALSE. */
      }

      /* Calculate 3-rd order polynomial by approximating sample points from trace and referenced object. 
         If bUseActObject == TRUE, the object uiObject position is added to the trace since current 
         object position not included in trace samples */
      CAL_v_CalcPointApproxPolyL3Ext(&Poly, &pObjTraces->ObjectTrace[uiTrace], &pEmGenObjList->aObject[uiObject].Kinematic, bUseActObject);

      /* if polynomial is valid */
      if (Poly.bValid == TRUE)
      {
        /* assign values from polynomial and trace to output trajectory structure */
        if (pObjTraces->ObjectTrace[uiTrace].uiReferenceToFCTObject < EM_N_OBJECTS)
        {
          pObjTrajs->ObjTrajects[uiTraj].tObjNum   = (ObjNumber_t)uiObject;
        }
        else
        {
          pObjTrajs->ObjTrajects[uiTraj].tObjNum   = OBJ_INDEX_NO_OBJECT;
        }
        pObjTrajs->ObjTrajects[uiTraj].fPosY0      = Poly.fC0;
        pObjTrajs->ObjTrajects[uiTraj].fAngle      = Poly.fC1;
        pObjTrajs->ObjTrajects[uiTraj].fCurveC0    = Poly.fC2 * 2.0F;
        pObjTrajs->ObjTrajects[uiTraj].fCurveC1    = Poly.fC3 * 6.0F;
        pObjTrajs->ObjTrajects[uiTraj].fPosY0Dev   = CML_f_Sqrt(CML_f_Max (Poly.fC0Var, 0.0F));
        pObjTrajs->ObjTrajects[uiTraj].fAngleDev   = CML_f_Sqrt(CML_f_Max (Poly.fC1Var, 0.0F));
        pObjTrajs->ObjTrajects[uiTraj].fCurveC0Dev = CML_f_Sqrt(CML_f_Max (Poly.fC2Var, 0.0F)) * 2.0F;
        pObjTrajs->ObjTrajects[uiTraj].fCurveC1Dev = CML_f_Sqrt(CML_f_Max (Poly.fC3Var, 0.0F)) * 6.0F;
        pObjTrajs->ObjTrajects[uiTraj].fLength     = Poly.fXmax - Poly.fXmin;
        pObjTrajs->ObjTrajects[uiTraj].fPosX0      = Poly.fXmin;

        /* increment trajectory index */
        uiTraj++;
      }
    }
  }

  /* assign values from trace loop to output trajectory structure header */
  pObjTrajs->uiTrajsCount = uiTraj;
}

#endif /* END IF (FCT_CFG_TJA_OBJECT_TRACE) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_f_GetObjObservationVariance                                                                  */ /*!

  @brief           get Variance of Object depending on Distance

  @description     get Variance of Object depending on Distance

  @startuml 
  Partition FIP_f_GetObjObservationVariance
  Start
  	Note right: This function is used to get Variance of Object depending on Distance	
  	- Assuming object Angle-Uncertainty of 1° approximate Y-Uncertainty with linear function => tan(0.5°)
  	- Compute the variance of object
  Stop
  @enduml

  @return          static float32 : variance value [float]

  @param[in]       iObj : Object ID [0, 40]

  @glob_in         OBJ_LONG_DISPLACEMENT : object's longitudinal displacement [float]
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [float]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!
  
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
float32 FIP_f_GetObjObservationVariance( ObjNumber_t iObj )
{
  /*assuming object Angle-Uncertainty of 1°
  approx of Y-Uncertainty with linear function => tan(0.5°)*/
  const float32 fTanUncAngle = 0.008726867790759f;
  float32 f_ret;
  float32 f_ObjDistYVar;

  f_ret = SQR(fTanUncAngle * (*(pt_FIP_RTE_Input->pf_ObjLongDisp( iObj ))));
  f_ObjDistYVar = SLATE_f_GetObjDistYVar( iObj );
  f_ret = MAX_FLOAT(f_ret , f_ObjDistYVar);
  return f_ret;
}

#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE)
/*************************************************************************************************************************
Functionname:     FIPGetTrafoMatrix2DCOFFwdTgtSync                                                                  */ /*!

  @brief           Get ego 2D forward transformation matrix target sync

  @description     Get ego target sync 2D forward transformation matrix.
                   It merely returns a pointer to the previously filled matrix.
  
  @startuml 
    Partition FIPGetTrafoMatrix2DCOFFwdTgtSync
    Start
  	  - Returns ego 2D forward transformation matrix target synchronized	
    Stop
  @enduml

  @return          static const GDBTrafoMatrix2D_t * : Const pointer to 2D transformation matrix [CML_t_TrafoMatrix2D as in Rte_Type.h]

  @param[in]       -

  @glob_in         FIPTrMat2DCOFFwdTgtSync : 2D transformation matrix for coefficient forward target sync [CML_t_TrafoMatrix2D as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Enable Interface for Traces
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             The global EMTrMat2DCOFFwdTgtSync has to be filled prior to calling this function.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

  @author          J. Spruck/G. Ungvary
*************************************************************************************************************************/
const GDBTrafoMatrix2D_t * FIPGetTrafoMatrix2DCOFFwdTgtSync(void)
{
  return &FIP_TrMat2DCOFFwdTgtSync;
}

#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE)
/*************************************************************************************************************************
  Functionname:    FIPGetTrafoMatrix2DCOFForJitTgtSync                                                              */ /*!

  @brief           Get ego 2D forward transformation jitter? matrix target sync

  @description     Get ego target sync 2D forward transformation jitter? matrix.
                   It merely returns a pointer to the previously filled matrix.
  
  @startuml 
    Partition FIPGetTrafoMatrix2DCOFForJitTgtSync
    Start
    	- Returns ego 2D forward transformation jitter matrix target synchronized	
    Stop
  @enduml

  @return          static const GDBTrafoMatrix2D_t * : Const pointer to 2D transformation matrix [CML_t_TrafoMatrix2D as in Rte_Type.h]

  @param[in]       -

  @glob_in         FIP_TrMat2DCOFForJitTgtSync : 2D transformation matrix for coefficient jitter target sync [CML_t_TrafoMatrix2D as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Enable Interface for Traces
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             The global EMTrMat2DCOFForJitTgtSync has to be filled prior to calling this function.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
                   
  @created         -
  @changed         12/18/2015

  @author          J. Spruck/G. Ungvary
*************************************************************************************************************************/
const GDBTrafoMatrix2D_t * FIPGetTrafoMatrix2DCOFForJitTgtSync(void)
{
  return &FIP_TrMat2DCOFForJitTgtSync;
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE)
/*************************************************************************************************************************
  Functionname:    FIP_v_UpdateEgoMotion                                                                            */ /*!

  @brief           Update Ego motion Matrices

  @description     Update Ego motion Matrices

  @startuml 
  Partition FIP_v_UpdateEgoMotion
  Start
	  - Updates Ego motion matrices
  Stop
  @enduml

  @return          static void

  @param[in]       void

  @glob_in         pt_FIP_RTE_Input->pf_EgoVelObjSync : longitudinal motion velocity [float]
  @glob_in         pt_FIP_RTE_Input->pf_EgoAccObjSync : longitudinal motion acceleration [float]
  @glob_in         SLATE_f_GetEgoYawRateObjSync() : yaw rate [float]
  @glob_in         EGO_YAW_RATE_VAR_OBJ_SYNC : yaw rate variance [float]
  @glob_in         EGO_YAW_RATE_MAX_JITTER_OBJ_SYNC : yaw rate max jitter [float]
  @glob_in         SLATE_f_GetSensorXPosToCOG() : Longitudinal position to Cog [float]
  @glob_in         SLATE_f_GetSensorYPosition() : latitudinal position [float]
  @glob_in         EGO_SIDE_SLIP_OBJ_SYNC : side slip angle [float]
  @glob_in         EGO_SIDE_SLIP_VAR_OBJ_SYNC :side slip angle variance [float]
  @glob_in         TASK_CYCLE_TIME : time of 1 cycle [fTime_t as in Rte_Type.h]

  @glob_out        FIPTrMat2DCOFFwdTgtSync : 2D Transformation matrix coefficient forward target sync [GDBTrafoMatrix2D_t as in cml_mapping.h]
  @glob_out        FIPTrMat2DCOFForJitTgtSync : 2D Transformation matrix coefficient jitter target sync [GDBTrafoMatrix2D_t as in cml_mapping.h]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Enable Interface for Traces
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

  @author          philippe.dintzer@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_UpdateEgoMotion(void)
{
  float32 f_EgoYawRateObjSync       = SLATE_f_GetEgoYawRateObjSync();
  float32 f_EgoYawRateVarObjSync    = SLATE_f_GetEgoYawRateVarObjSync();
  float32 f_EgoYawRateMaxJitterSync = SLATE_f_GetEgoYawRateMaxJitterSync();
  float32 f_SensorXPosToCOG         = SLATE_f_GetSensorXPosToCOG();
  float32 f_SensorYPosition         = SLATE_f_GetSensorYPosition();
  float32 f_EgoSideSlip             = *SLATE_pf_GetEgoSideSlip();
  float32 f_EgoSideSlipVar          = *SLATE_pf_GetEgoSideSlipVar();
  float32 f_CPCycleTime             = SLATE_f_GetCPCycleTime();
  
  /*!@todo adaption of all egomotion matrices to new ego functions*/
  GDBmathCalcCOFEgomotionMatrices(  &FIP_TrMat2DCOFFwdTgtSync,
    &FIP_TrMat2DCOFForJitTgtSync,
    *pt_FIP_RTE_Input->pf_EgoVelObjSync,
    *pt_FIP_RTE_Input->pf_EgoAccObjSync,
    f_EgoYawRateObjSync,
    f_EgoYawRateVarObjSync,
    f_EgoYawRateMaxJitterSync,
    f_SensorXPosToCOG,
    f_SensorYPosition,
    f_EgoSideSlip,
    f_EgoSideSlipVar,
    f_CPCycleTime);

}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES || FCT_CFG_USE_FCT_DYNAMIC_TRACES || FIP_CFG_USE_EGO_TRACE) */

///@}
#endif  /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES)) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
