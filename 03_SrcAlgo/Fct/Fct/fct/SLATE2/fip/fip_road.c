/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_road.c

DESCRIPTION:               This file provides an abstraction layer for incoming road data 
                           for usage in different parts of FCT-ACC.

AUTHOR:                    Raval, Chintan (uidr6459)

CREATION DATE:             28.07.2016

VERSION:                   $Revision: 1.16 $

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
@addtogroup fip_road_type
@{ */

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

/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*! Definition of pointer to FIPRoad output structure for access within this sub module */
SET_MEMSEC_VAR(pt_FIP_RD_Output)
static FIP_RD_Output_t * pt_FIP_RD_Output; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to fill the data in to the sturcture representing component output */

/*! Definition of pointer to FIPRoad input structure for access within this sub module */
SET_MEMSEC_VAR(pt_FIP_RD_Input)
static FIP_RD_InputConst_t * pt_FIP_RD_Input; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to access the data which is input to the component */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_RD_InitPersistentData(void);
static void FIP_v_RD_InitEveryCycle(void);
static void FIP_v_RD_SetInput(void);

static void FIP_v_Init_FIPRoadEstimation(void);         /*! Initialize FIP Road Estimation Structure */
static void FIP_v_Init_FIPRoadBorder(void);             /*! Initialize FIP Road Fused Border Structure */

static void FIP_v_SetRoadEstimation(void);              /*! Set FIP Road Estimation structure with EM Road Estimation Values */
static void FIP_v_SetRoadBorder(void);                  /*! Set FIP Road Fused Border structure with EM Fused Road Border*/
#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
static void FIP_v_ComputeDistToHighCurvatureChangeRoad(void); /*! Compute FIP distance to high curvature change based on road estimation */
static void FIP_v_SetDistToHighCCValidFlagRoad(void);         /*! Set FIP distance to high curvature change valid flag based on road estimation */
#endif
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    FIP_v_Init_Road                                                                                  */ /*!

  @brief           Initialize FIP Road

  @description     Initialize the persistent data and the non-persistent data in the sub module

  @startuml 
    Partition FIP_v_Init_Road
    Start
    	Note right: This function initializes the persistent data and \n the non-persistent data in the FIP Road module	
    	- Depending on the available sources initialize persistent \n memory structures and non-persistent \n memory structures in FIP Road sub module
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_RD_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_RD_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.07.2016
  @changed         27.07.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
void FIP_v_Init_Road(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal, FIP_RD_Output_t * pt_FIP_RD_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_RD_Input = pt_FIP_RD_InputGlobal;
  pt_FIP_RD_Output = pt_FIP_RD_OutputGlobal;

  /* Initialize persistent memory structures in FIP Road sub module */
  FIP_v_RD_InitPersistentData();

  /* Initialize input-output structures for this sub-module */
  FIP_v_RD_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_RD_Input = NULL;
  pt_FIP_RD_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_RD_InitPersistentData                                                                      */ /*!

  @brief           Initialize the persistent memory structures in FIP Road module

  @description     Initialize the persistent memory structures in the sub module, both road estimation data and road border 
                   data are initilized.

  @startuml 
    Partition FIP_v_RD_InitPersistentData
    Start
    	Note right: This function initializes the persistent \n data in the FIP Road module	
    	- Depending on the available sources set \n default values to the persistent data structure
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP) 

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
static void FIP_v_RD_InitPersistentData(void)
{
  /*! Initialize FIP Road Estimation */
  FIP_v_Init_FIPRoadEstimation();
  /*! Initialize FIP Road Border */
  FIP_v_Init_FIPRoadBorder();

#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
  /*! Initialize valid flag for road-based FIP distance to next high curvature change (curve entry/exit) */
  pt_FIP_RD_Output->b_RoadPathIsValidForCC = FALSE;

  /*! Initialize road-based FIP distance to next high curvature change (curve entry/exit) */
  pt_FIP_RD_Output->f_DistToHighCC = 0.f;
#endif
}

/*************************************************************************************************************************
  Functionname:    FIP_v_RD_PreProcess                                                                              */ /*!

  @brief           Preprocess/ Set the input members for FIP Road module
  
  @description     Preprocess/ Set the input members for the sub module 

  @startuml 
    Partition FIP_v_RD_PreProcess
    Start
      	Note right: This function preprocesses the input \n members for FIP Road module	
      	- Depending on the available sources \n set all the FIP Road module inputs
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_RD_InputGlobal : Reference to the sub module óutput structure instantiated in Frame

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP) 

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
void FIP_v_RD_PreProcess(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal)
{
  /* Assign local pointers */
  pt_FIP_RD_Input = pt_FIP_RD_InputGlobal;

  /* Setup Inputs */
  FIP_v_RD_SetInput();

  /* Reset local pointers */
  pt_FIP_RD_Input = NULL;
}
/*************************************************************************************************************************
  Functionname:    FIP_v_RoadProcess                                                                                */ /*!

  @brief           Execute FIP Road Functions

  @description     Initialize the non-persistent data in every cycle, set FIP Road Estimation with EM Road Estimation values and 
                   set FIP Road Border with the EM Road Border values.
  
  @startuml 
    Partition FIP_v_RoadProcess
    Start
    	Note right: This function initializes the non-persistent data in every cycle	
    	- Initialize non-persistent output data structures \n and variables with the default values
    	- Set FIP Road Estimation with EM Road Estimation values
    	- Set FIP Road Border with EM Road Border values
    
    	If (Road curvature change computation switch is enabled) the (True)
    		- Determine the distance to next high \n curvature change (curve entry/exit)
    	Else (False)
    	Endif
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_RD_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_RD_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             FIP_v_RD_PreProcess(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.07.2016
  @changed         27.07.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
void FIP_v_RoadProcess(FIP_RD_InputConst_t * pt_FIP_RD_InputGlobal, FIP_RD_Output_t * pt_FIP_RD_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_RD_Input = pt_FIP_RD_InputGlobal;
  pt_FIP_RD_Output = pt_FIP_RD_OutputGlobal;

  /*! Initialize input-output structures for this component */
  FIP_v_RD_InitEveryCycle();
    
  /*! Set FIP Road Estimation with EM Road Estimation values */
  FIP_v_SetRoadEstimation();
  /*! Set FIP Road Border with EM Road Border values */
  FIP_v_SetRoadBorder();
  
#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
  /*! Determine the distance to next high curvature change (curve entry/exit) and set its valid flag */
  FIP_v_ComputeDistToHighCurvatureChangeRoad(); 
  FIP_v_SetDistToHighCCValidFlagRoad();
#endif

  /* Reset local pointers */
  pt_FIP_RD_Input = NULL;
  pt_FIP_RD_Output = NULL;
}
/*************************************************************************************************************************
  Functionname:    FIP_v_RD_InitEveryCycle                                                                          */ /*!

  @brief           Initialize in every cycle in FIP Road 

  @description     Initialize non-persistent output data structures and variables with the default values in the sub module,
                   This function uses local pointer to the sub module output instantiated in Frame.
  
  @startuml 
    Partition FIP_v_RD_InitEveryCycle
    Start
  	Note right: This function non-persistent output data \n structures and variables with the default values
  	- Depending on the available sources set default \n values to the non-persistent data structureStop
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_RD_Input: Reference to FIP Road module input

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

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
static void FIP_v_RD_InitEveryCycle(void)
{ 
#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
  /*! Initialize road-based FIP distance to next high curvature change (curve entry/exit) */
  pt_FIP_RD_Output->f_DistToHighCC = FIP_ROAD_CURVE_CHANGE_DIST_ON_TRAJ_MAX;
#endif
}
/*************************************************************************************************************************
  Functionname:    FIP_v_RD_SetInput                                                                                */ /*!

  @brief           Set the input for FIP Road module

  @description     Set the input for the sub module

  @startuml 
  Partition FIP_v_RD_SetInput
  Start
	Note right: This function sets the input for FIP Road Module	
	If (Road curvature change computation switch is enabled)
		If (Course prediction switch is enabled) then (True)
			- Update Trajectory State
		Else (False)
		Endif

		If (ACC Lane association switch is enabled) then (True)
			- Update Moving object base pickup range
		Else (False)
		Endif
	Else (False)
	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             None
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03.10.2016
  @changed         28.02.2017

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_RD_SetInput(void)
{
#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
#if (FCT_CFG_COURSE_PREDICTION)
  pt_FIP_RD_Input->pt_TrajectoryState = CP_pt_GetTrajectoryState();
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  pt_FIP_RD_Input->pt_MovingObjBasePickUpRange = LA_pt_GetMovingObjBasePickUpRange();
#endif
#endif
}

#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
  /*************************************************************************************************************************
  Functionname:    FIP_v_ComputeDistToHighCurvatureChangeRoad                                                                  */ /*!

  @brief           Calculates closest x-distance at which dy-offset between course of constant ego curvature
                   and course from road estimation exceeds a given threshold

  @description     Calculates closest x-distance at which dy-offset between course of constant ego curvature
                   and course from road estimation exceeds a given threshold. Starting from 0m x-distance the dY between
                   the ego course and the road trajectory is computed. The computation is performed with a constant step size 
                   FIP_ROAD_CURVE_CHANGE_DISTX_STEP for the x-distance until a given dY-threshold is exceeded or the maximum 
                   x-distance is reached.
  
  @startuml 
    Partition FIP_v_ComputeDistToHighCurvatureChangeRoad
    Start
  	Note right: This function calculates closest x-distance \n at which dy-offset between course of constant \n ego curvature and course from road estimation \n exceeds a given threshold	
  	- Get curvature and compute radius and its square
  	
  	If (X-distance less than maximum curvature \n change distance on trajectory AND \n X-distance found is equal to False) then (True)
  		- Determine y-position at a given \n x-distance of the road clothoid
  		- Calculate y-distance of the VDY trajectory \n with constant curvature for given x-position
  		If (Curvature value is low) then (True)
  			- Compute square of x-distance at which \n y-distance of circle is to be computed	
  			If (Computated square of x-distance is less \n than square of radius of circle) then (True)
  				If (Radius of circle is greater than 0) then (True)
  					- Compute y-distance of circle using \n Radius of circle - Square root of (sqaure of radius of circle – square of x-distance) 
  				Else (False)
  					- Compute y-distance of circle using \n Radius of circle + Square root of (sqaure of radius of circle – square of x-distance)	
  				Endif
  			Else (False)
  				- Set x-distance found to True
  				- Set y-distance of circle to radius
  			Endif
  		Else(False)
  		Endif
  
  		If (y-deviation between road course and \n course of constant curvature exceeds threshold) then (True)
  			- Increment x-distance value
  		Else (False)
  			- Set x-distance found to True
  			- Take current x-distance as distance \n with a high curvature change
  		Endif
  	Endif
  			
    Stop
  @enduml

  @return          -

  @param[in]       -

  @c_switch_full   FCT_CFG_ROAD_INPUT : Switch to configure Road estimation input to FCT
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.01.2017
  @changed         26.01.2017

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static void FIP_v_ComputeDistToHighCurvatureChangeRoad(void)
{
  boolean b_DistXFound;                 /* stop flag for both while loops */
  float32 f_DistX;                      /* current x-coordinate (longitudinal) in search loop */
  float32 f_DistXSqr;                   /* square of x-coordinate in search loop */
  float32 f_DistYRoad;                  /* y-coordinate (lateral) of position on road course */
  float32 f_DistYCircle;                /* y-coordinate (lateral) of position on circular course (given by VDY course) */
  float32 f_RadiusCircle;               /* radius of circle (given by VDY course ) */
  float32 f_RadiusCircleSqr;            /* square of radius of circle (given by VDY course) */
  float32 f_CurvatureCircle;            /* curvature of circle (given by VDY course) */
  float32 f_Abs_CurvatureCircle, f_AbsDiff_DistYCircleRoad;

  /* Initialization of variables */
  b_DistXFound                  = FALSE;
  f_DistX                       = 0.f;
  f_DistXSqr                    = 0.f;
  f_DistYRoad                   = 0.f;
  f_DistYCircle                 = 0.f;
  f_RadiusCircle                = 0.f;
  f_RadiusCircleSqr             = 0.f;
  f_CurvatureCircle             = EGO_CURVE_OBJ_SYNC;

  /* One-time computation of radius and its square of the constant-curvature trajectory in case needed for accuracy */
  f_Abs_CurvatureCircle = fABS(f_CurvatureCircle);
  if (f_Abs_CurvatureCircle > FIP_CURVATURE_USE_LINEAR_APPROX)
  {
    f_RadiusCircle    = (1.f/f_CurvatureCircle);
    f_RadiusCircleSqr = f_RadiusCircle * f_RadiusCircle;
  }

  /* Step through current segment as long as x-distance with high curvature change has not been found and maximum x-distance not been reached */
  while ( (f_DistX < FIP_ROAD_CURVE_CHANGE_DIST_ON_TRAJ_MAX) && (b_DistXFound == FALSE) )
  {
    /* Determine y-position at a given x-distance of the road clothoid */
    f_DistYRoad = GDBRoadClothoid(f_DistX, ROAD_GET_CR_CURVATURE, ROAD_GET_CR_CLOTHOID_PARAM, ROAD_GET_CR_YAWANGLE);

    /* Calculate y-distance of the VDY trajectory with constant curvature for given x-position */
    /* For very low curvature values of the circle (basically a straight trajectory) the y-distance is left unchanged at an initial value of zero */
    if (f_Abs_CurvatureCircle > FIP_CURVATURE_USE_LINEAR_APPROX)
    {
      /* Compute square of x-distance at which y-distance of circle is to be computed */
      f_DistXSqr = SQR(f_DistX);

      /* Computation of y-distance of circle according to formula only possible when absolute value of x-distance is smaller than radius of circle */
      if (f_DistXSqr < f_RadiusCircleSqr)
      {
        /* Y-distance of circle dependent on sign of radius */
        if (f_RadiusCircle > 0.0f)
        {
          f_DistYCircle = f_RadiusCircle - SQRT(f_RadiusCircleSqr - f_DistXSqr);
        }
        else
        {
          f_DistYCircle = f_RadiusCircle + SQRT(f_RadiusCircleSqr - f_DistXSqr);
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

    /* Check if y-deviation between road course and course of constant curvature exceeds threshold */
    f_AbsDiff_DistYCircleRoad = fABS(f_DistYCircle - f_DistYRoad);
    if(f_AbsDiff_DistYCircleRoad < FIP_ROAD_CURVE_CHANGE_DELTA_Y_THRES_PICKUP)
    {
      /* Increment x-distance value */
      f_DistX += FIP_ROAD_CURVE_CHANGE_DISTX_STEP;
    }
    else
    {
      /* End of search reached as x-distance found at which delta of y-distance passes threshold */
      b_DistXFound = TRUE;

      /* Take current x-distance as distance with a high curvature change */
      pt_FIP_RD_Output->f_DistToHighCC = f_DistX;
    }
  }
}
#endif

#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
/*************************************************************************************************************************
  Functionname:    FIP_v_SetDistToHighCCValidFlagRoad                                                             */ /*!

  @brief           Set info if road path is valid for curvature change computation

  @description     Set info if road path is valid for curvature change computation

  @startuml 
  Partition FIP_v_SetDistToHighCCValidFlagRoad
  Start
	Note right: This function sets info if road path is valid for curvature change computation	
	
	If (Tunnel probability is less than Tunnel probability threshild) then (True)
		If (ACC lane association switch is enabled) then (True)
			- Set threshold for road range
		Else(False)
		Endif
	Else(False)
	Endif
	
	- Set threshold for road confidence

	If (Road path is Valid for Curvature change is TRUE) then (True)
		- Update the threshold for road range and road confidence
	Else(False)
	Endif

	If (((Coupled Left Road confidence is greater than threshold road confidence) \n AND \n Coupled left road range is greater than threshold road range)) \n OR \n ((Coupled Right Road confidence is greater than threshold road confidence) \n AND \n Coupled right road range is greater than threshold road range)))
		If (Course prediction switch is enabled) then (True)
			- Get road trajectory fusion state
			If (Fusion Road Estimation is TRUE) then (True)
				- Set New Valid Flag Road to TRUE
			Else (False)
			Endif
		Else (False)
		Endif
	Endif

	- Store result in output structure

  Stop
  @enduml

  @return          b_RoadPathIsValid : information, if road path is valid  [TRUE, FALSE]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ROAD_INPUT : Switch to configure Road estimation input to FCT
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.01.2017
  @changed         28.02.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static void FIP_v_SetDistToHighCCValidFlagRoad(void)
{
  float32              f_RoadRangeThres;  /* Threshold for road range */
  float32              f_RoadConfThres;   /* Threshold for road confidence */
  CP_t_TrajectoryState t_TrajFusionState; /* fusion state of trajectory */
  boolean              b_NewValidFlagRoad = FALSE; /* Result of validity check with default value FALSE */
  float32              f_EgoVelocity = *pt_FIP_RTE_Input->pf_EgoVelObjSync; /* Get ego velocity */

  /* Compute distance to curvature change only outside of tunnel */
  if (TUNNEL_PROBABILITY < LA_TUNNEL_PROB_THRES)
  {
    /* Set threshold for road range */
    if( f_EgoVelocity >= FIP_ROAD_CURVE_CHANGE_EGO_VELOCITY)
    {
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  f_RoadRangeThres = *pt_FIP_RD_Input->pt_MovingObjBasePickUpRange;/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
#else
  f_RoadRangeThres = MAX_FLOAT(FIP_PICK_UP_RANGE_DEFAULT_MIN, FIP_ROAD_CURVE_CHANGE_MIN_ROAD_RANGE_TG * EGO_SPEED_X_OBJ_SYNC);
  f_RoadRangeThres = MIN_FLOAT(f_RoadRangeThres, RW_FCT_MAX);
#endif    /* (FCT_CFG_ACC_LANE_ASSOCIATION) */
    }
    else
    {
      f_RoadRangeThres = t_FIP_ALL_Output.t_FIP_CC_Output.f_FusedDistToHighCC;
    }
    
  /* Set threshold for road confidence */
  f_RoadConfThres  = FIP_ROAD_CURVE_CHANGE_MIN_ROAD_CONFIDENCE_PICKUP;

  /* Apply hysteresis for road range and confidence */
  if (pt_FIP_RD_Output->b_RoadPathIsValidForCC == TRUE)
  {
    if( f_EgoVelocity >= FIP_ROAD_CURVE_CHANGE_EGO_VELOCITY)
    {
      f_RoadRangeThres -= FIP_ROAD_CURVE_CHANGE_ROAD_RANGE_HYSTERESIS_HIGHWAY;
    }
    else
    {
      f_RoadRangeThres -= FIP_ROAD_CURVE_CHANGE_ROAD_RANGE_HYSTERESIS;
    }
    f_RoadConfThres   = FIP_ROAD_CURVE_CHANGE_MIN_ROAD_CONFIDENCE_DROP;
  }

  /* Check condition for road range and confidence */
  if ( ( ( ROAD_GET_CR_CONFIDENCE_LEFT > f_RoadConfThres)
      && ( ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED > f_RoadRangeThres) 
       && (ROAD_GET_CR_TRACKSTAT_LEFT > 5u))
    || ( ( ROAD_GET_CR_CONFIDENCE_RIGHT > f_RoadConfThres)
      && ( ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED > f_RoadRangeThres) 
      && (ROAD_GET_CR_TRACKSTAT_RIGHT > 5u))
     )
  {
#if (FCT_CFG_COURSE_PREDICTION)
    /* Get road trajectory fusion state */
    t_TrajFusionState = *pt_FIP_RD_Input->pt_TrajectoryState;
    /* Road path is valid only in case road trajectory fusion is active */
    /* Reason: the road fusion flag i.a. includes a parallelism criteria */
    if ((t_TrajFusionState.FusionRoadstimation == TRUE) || ( f_EgoVelocity < FIP_ROAD_CURVE_CHANGE_EGO_VELOCITY))
#else
    _PARAM_UNUSED(t_TrajFusionState)
#endif
    {
      b_NewValidFlagRoad = TRUE;
    }
  }
  }/* END IF (TUNNEL_PROBABILITY < LA_TUNNEL_PROB_THRES) */
  /* Store result in output structure */
  pt_FIP_RD_Output->b_RoadPathIsValidForCC = b_NewValidFlagRoad;
}
#endif

/*************************************************************************************************************************
  Functionname:    FIP_v_Init_FIPRoadEstimation                                                                     */ /*!

  @brief           Initialize FIP Road Estimation with default values

  @description     Initialize FIP Road Estimation with default values. This function uses local pointer to the sub module 
                   output instantiated in Frame.
  
  @startuml 
  Partition FIP_v_Init_FIPRoadEstimation
  Start
	Note right: This function initializes FIP Road Estimation	
	- Intialize all the FIP Road Estimation with default values
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_RD_Output : Reference to Road module output
                    t_FIPRoadEstimation.fC0 : Road Curvature [-1...+1] 1/m
                    t_FIPRoadEstimation.fC1 : Road Curvature Gradient [-1...+1] m-2
                    t_FIPRoadEstimation.fYawAngle : Road YawAngle [-PI … +PI] rad
                    t_FIPRoadEstimation.fRangeMaxRight : Estimated maximum range of road on right side [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fRangeMaxLeft : Estimated maximum range of road on left side [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fYLeft : Estimated Distance to left side road boundary [full range of data type float32 >= 0] m
                    t_FIPRoadEstimation.fYRight: Estimated Distance to right side road boundary [full range of data type float32 <= 0] m
                    t_FIPRoadEstimation.uiTrackingStatus : Road tracking status [full range of unsigned character]
                    t_FIPRoadEstimation.uiTrackingStatusLeft : Road left side tracking status [0u ... 7u]
                    t_FIPRoadEstimation.uiTrackingStatusRight : Road right side tracking status [0u ... 7u]
                    t_FIPRoadEstimation.uiConfidence : Confidence on Road estimation [0u ... 100u]
                    t_FIPRoadEstimation.fminXLeft : Minimal left side distance X from current cycle for road estimation [full range of data type float32] m
                    t_FIPRoadEstimation.fminXRight : Minimal right side distance X from current cycle for road estimation [full range of data type float32] m
                    t_FIPRoadEstimation.fmaxXLeftCompensated : Estimated Confident maximum range of road on left side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fmaxXRightCompensated : Estimated Confident maximum range of road on right side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fLatStdDevFiltered : Road filtered lateral standard deviation [full range of float >= 0.0f]
                    t_FIPRoadEstimation.fConfidenceLeft : Confidence of left side estimation of road [0.f ... 100.f]
                    t_FIPRoadEstimation.fConfidenceRight : Confidence of right side estimation of road [0.f ... 100.f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.06.2016
  @changed         29.06.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
static void FIP_v_Init_FIPRoadEstimation(void)
{
  pt_FIP_RD_Output->t_FIPRoadEstimation.fC0 = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fC1 = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYawAngle = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fRangeMaxRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fRangeMaxLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatus = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatusLeft = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatusRight = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiConfidence = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fminXLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fminXRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fmaxXLeftCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fmaxXRightCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fLatStdDevFiltered = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fConfidenceLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fConfidenceRight = 0.f;

#if SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fC0 = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fC1 = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fYawAngle = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fConfidence = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMinX = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMaxX = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMaxXCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.uiTrackingStatus = 0u;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fLateralOffset = 0.f;

  pt_FIP_RD_Output->t_FIPRightRoadBorder.fC0 = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fC1 = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fYawAngle = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fConfidence = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMinX = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMaxX = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMaxXCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.uiTrackingStatus = 0u;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fLateralOffset = 0.f;
  #endif /* end of SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT */

}


/*************************************************************************************************************************
  Functionname:    FIP_v_Init_FIPRoadBorder                                                                         */ /*!

  @brief           Initialize FIP Road Border with default values

  @description     Initialize FIP Road Border with defualt values. This function uses local pointer to the sub module output 
                   instantiated in Frame
  
  @startuml 
  Partition FIP_v_Init_FIPRoadBorder
  Start
	Note right: This function initializes FIP Road Border	
	- Initialize FIP Road Border with default values
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_RD_Output : Reference to FIP Road module output
                    t_FIPRoadFusedBorder.fDistRight: Estimated Distance to right side fused road boundary [-30.f ... 0.f] m
                    t_FIPRoadFusedBorder.fDistRightStd: Standard Deviation of Estimated Distance to right side fused road boundary [ 0 ... 5*RW_FCT_MAX]
                    t_FIPRoadFusedBorder.fDistLeft: Estimated Distance to left side fused road boundary [0.f ... 30.f] m
                    t_FIPRoadFusedBorder.fDistLeftStd: Standard Deviation of Estimated Distance to left side fused road boundary [ 0 ... 5*RW_FCT_MAX]
                    t_FIPRoadFusedBorder.bStatusRight: Confidence of Right Border estimation [0u ... 100u]
                    t_FIPRoadFusedBorder.bStatusLeft: Confidence of Left Border estimation [0u ... 100u]
  
  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.07.2016
  @changed         05.07.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
static void FIP_v_Init_FIPRoadBorder(void)
{
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistRightStd = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistLeftStd = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.bStatusRight = 0u;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.bStatusLeft = 0u;

}

/*************************************************************************************************************************
  Functionname:    FIP_v_SetRoadEstimation                                                                          */ /*!

  @brief           Set values for FIP Road Estimation structure

  @description     Set FIP Road Estimation with Radar Road Estimation values. If no road input from radar is
                   available then use default initialization values for FIP Road Estimation
  
  @startuml 
    Partition FIP_v_SetRoadEstimation
    Start
  	Note right: This function sets FIP Road Estimation \n with Radar Road Estimation values	
  	if (Road input from radar is available) then (True)
      		- Set FIP Road Estimation with \n Radar Road Estimation values
    	else (False)
      		- Use default initialization values \n for FIP Road Estimation
    	endif
    Stop
  @enduml

  @return          -
 
  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_RD_Output: Reference to Road module output
                    t_FIPRoadEstimation.fC0 : Road Curvature [-1...+1] m-1
                    t_FIPRoadEstimation.fC1 : Road Curvature Gradient [-1...+1] m-2
                    t_FIPRoadEstimation.fYawAngle : Road YawAngle [-PI … +PI] rad
                    t_FIPRoadEstimation.fRangeMaxRight : Estimated maximum range of road on right side [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fRangeMaxLeft : Estimated maximum range of road on left side [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fYLeft : Estimated Distance to left side road boundary [full range of data type float32 >= 0] m
                    t_FIPRoadEstimation.fYRight: Estimated Distance to right side road boundary [full range of data type float32 <= 0] m
                    t_FIPRoadEstimation.uiTrackingStatus : Road tracking status [full range of unsigned character]
                    t_FIPRoadEstimation.uiTrackingStatusLeft : Road left side tracking status [0u ... 7u]
                    t_FIPRoadEstimation.uiTrackingStatusRight : Road right side tracking status [0u ... 7u]
                    t_FIPRoadEstimation.uiConfidence : Confidence on Road estimation [0u ... 100u]
                    t_FIPRoadEstimation.fminXLeft : Minimal left side distance X from current cycle for road estimation [full range of data type float32] m
                    t_FIPRoadEstimation.fminXRight : Minimal right side distance X from current cycle for road estimation [full range of data type float32] m
                    t_FIPRoadEstimation.fmaxXLeftCompensated : Estimated Confident maximum range of road on left side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fmaxXRightCompensated : Estimated Confident maximum range of road on right side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    t_FIPRoadEstimation.fLatStdDevFiltered : Road filtered lateral standard deviation [full range of float >= 0.0f]
                    t_FIPRoadEstimation.fConfidenceLeft : Confidence of left side estimation of road [0.f ... 100.f]
                    t_FIPRoadEstimation.fConfidenceRight : Confidence of right side estimation of road [0.f ... 100.f]

  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.06.2016
  @changed         29.06.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
static void FIP_v_SetRoadEstimation(void)
{
  /* Use Radar Road values if availble */
#if (FCT_CFG_ROAD_INPUT)
  pt_FIP_RD_Output->t_FIPRoadEstimation.fC0 = ROAD_GET_CR_CURVATURE;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fC1 = ROAD_GET_CR_CLOTHOID_PARAM;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYawAngle = ROAD_GET_CR_YAWANGLE;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fRangeMaxRight = ROAD_GET_CR_MAX_X_RIGHT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fRangeMaxLeft = ROAD_GET_CR_MAX_X_LEFT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYLeft = ROAD_GET_CR_OFFSET_LEFT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYRight = ROAD_GET_CR_OFFSET_RIGHT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatus = ROAD_GET_CR_TRACKSTAT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatusLeft = ROAD_GET_CR_TRACKSTAT_LEFT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatusRight = ROAD_GET_CR_TRACKSTAT_RIGHT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiConfidence = ROAD_GET_CR_CONFIDENCE;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fminXLeft = ROAD_GET_CR_MIN_X_LEFT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fminXRight = ROAD_GET_CR_MIN_X_RIGHT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fmaxXLeftCompensated = ROAD_GET_CR_MAX_X_LEFT_COMPENSTATED;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fmaxXRightCompensated = ROAD_GET_CR_MAX_X_RIGHT_COMPENSTATED;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fLatStdDevFiltered = ROAD_GET_CR_EST_STDEV;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fConfidenceLeft = ROAD_GET_CR_CONFIDENCE_LEFT;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fConfidenceRight = ROAD_GET_CR_CONFIDENCE_RIGHT;

#if SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fC0 = ROAD_GET_BL_CURVATURE;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fC1 = ROAD_GET_BL_CLOTHOID_PARAM;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fYawAngle = ROAD_GET_BL_YAWANGLE;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fConfidence = ROAD_GET_BL_CONFIDENCE;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMinX = ROAD_GET_BL_MIN_X;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMaxX = ROAD_GET_BL_MAX_X;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMaxXCompensated = ROAD_GET_BL_MAX_X_COMPENSTATED;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.uiTrackingStatus = ROAD_GET_BL_TRACKSTAT;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fLateralOffset = ROAD_GET_BL_OFFSET;

  pt_FIP_RD_Output->t_FIPRightRoadBorder.fC0 = ROAD_GET_BR_CURVATURE;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fC1 = ROAD_GET_BR_CLOTHOID_PARAM;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fYawAngle = ROAD_GET_BR_YAWANGLE;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fConfidence = ROAD_GET_BR_CONFIDENCE;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMinX = ROAD_GET_BR_MIN_X;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMaxX = ROAD_GET_BR_MAX_X;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMaxXCompensated = ROAD_GET_BR_MAX_X_COMPENSTATED;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.uiTrackingStatus = ROAD_GET_BR_TRACKSTAT;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fLateralOffset = ROAD_GET_BR_OFFSET;
#endif /* end of SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT*/

  /* If no Road Input from Radar is available use default values */
#else 
  pt_FIP_RD_Output->t_FIPRoadEstimation.fC0 = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fC1 = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYawAngle = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fRangeMaxRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fRangeMaxLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fYRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatus = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatusLeft = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiTrackingStatusRight = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.uiConfidence = 0u;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fminXLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fminXRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fmaxXLeftCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fmaxXRightCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fLatStdDevFiltered = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fConfidenceLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadEstimation.fConfidenceRight = 0.f;
  
#if SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fC0 = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fC1 = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fYawAngle = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fConfidence = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMinX = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMaxX = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fMaxXCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.uiTrackingStatus = 0.f;
  pt_FIP_RD_Output->t_FIPLeftRoadBorder.fLateralOffset = 0.f;

  pt_FIP_RD_Output->t_FIPRightRoadBorder.fC0 = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fC1 = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fYawAngle = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fConfidence = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMinX = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMaxX = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fMaxXCompensated = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.uiTrackingStatus = 0.f;
  pt_FIP_RD_Output->t_FIPRightRoadBorder.fLateralOffset = 0.f;
#endif /* end of SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT */
#endif /* END IF (FCT_CFG_ROAD_INPUT) */

}

/*************************************************************************************************************************
  Functionname:    FIP_v_SetRoadBorder                                                                              */ /*!

  @brief           Set values for FIP Road Border structure

  @description     Set FIP Road Border with the fused road border information. If no road input from the fused road border ( from EM)
                   information is available then use default initialization values for FIP Road Border
  
  @startuml 
    Partition FIP_v_SetRoadBorder
    Start
  	Note right: This function sets FIP Road Estimation \n with Radar Road Estimation values	
  	if (Road input from radar is available) then (True)
      		- Set FIP Road Border with \n Radar Road Border values
    	else (False)
      		- Use default initialization \n values for FIP Road Border
    	endif
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_RD_Output : Reference to Road module output
                    t_FIPRoadFusedBorder.fDistRight: Estimated Distance to right side fused road boundary [-30.f ... 0.f] m
                    t_FIPRoadFusedBorder.fDistRightStd: Standard Deviation of Estimated Distance to right side fused road boundary [ 0 ... 5*RW_FCT_MAX] m
                    t_FIPRoadFusedBorder.fDistLeft: Estimated Distance to left side fused road boundary [0.f ... 30.f] m
                    t_FIPRoadFusedBorder.fDistLeftStd: Standard Deviation of Estimated Distance to left side fused road boundary [ 0 ... 5*RW_FCT_MAX] m
                    t_FIPRoadFusedBorder.bStatusRight: Confidence of Right Border estimation [0u ... 100u]
                    t_FIPRoadFusedBorder.bStatusLeft: Confidence of Left Border estimation [0u ... 100u]

  @c_switch_part   FCT_CFG_ROAD_INPUT : Switch to configure Road estimation input to FCT
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Switch to configure FCT support for FCT Input Preprocessing (FIP)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         05.07.2016
  @changed         05.07.2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
static void FIP_v_SetRoadBorder(void)
{

#if (FCT_CFG_ROAD_INPUT)
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistRight = ROAD_GET_BORDER_RIGHT;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistRightStd = ROAD_GET_BORDER_RIGHT_STD;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistLeft = ROAD_GET_BORDER_LEFT;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistLeftStd = ROAD_GET_BORDER_LEFT_STD;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.bStatusRight = ROAD_GET_BORDER_STAT_RIGHT;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.bStatusLeft = ROAD_GET_BORDER_STAT_LEFT;
#else 
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistRight = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistRightStd = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistLeft = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.fDistLeftStd = 0.f;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.bStatusRight = 0u;
  pt_FIP_RD_Output->t_FIPRoadFusedBorder.bStatusLeft = 0u;
#endif

/* Access functions are not defined for variables fDistLeftStd and fDistRightStd as they are not used anywhere */

}
///@}
#endif /* FCT_CFG_INPUT_PREPROCESSSING */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
