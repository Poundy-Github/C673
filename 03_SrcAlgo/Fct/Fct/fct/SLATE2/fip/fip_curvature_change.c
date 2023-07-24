/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 FIP (FCT Input Preprocessing)

PACKAGENAME:               fip_curvature_change.c

DESCRIPTION:               FCT Preprocessing of information about curvature change of future course (fusion of different observers).
                           
                           Goal is differentiation of curve entry, exit and situation with constant curviness.

AUTHOR:                    Grant Davtjan (uidg3349)

CREATION DATE:             17.01.2017

VERSION:                   $Revision: 1.13 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_curvature_change FIP Curvature change
@ingroup fip
@brief          Preprocessing of information is done here, which is used to determine the curvature change of the future course.
	            Different observers are fused and is used to check curve entry, exit, etc.\n\n

@description    The following functionalities are provided by this module:
                - Preprocess and set inputs for Curvature change sub module.
                - Set the input for FIP curvature change.
				- Initialize persistent memory structures in FIP curvature change module.
				- Initialize Curvature change information.
				- Determine fused distance to high curvature change (Curve entry/exit).
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
/*! Definition of local pointer to FIP curvature change output structure for access within this sub-module */
SET_MEMSEC_VAR(pt_FIP_CC_Output)
static FIP_CC_Output_t * pt_FIP_CC_Output;  //PRQA S 3229
/* date: 2017-03-07, reviewer:Grant Davtjan, reason: Pointer is used to fill the data in to the sturcture representing component output */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_CC_SetInput(void);
static void FIP_v_CC_InitPersistentData(void);
static void FIP_v_CC_InitEveryCycle(void);
static void FIP_v_CC_SetInput(void);

/*************************************************************************************************************************
  Functionname:    FIP_v_CC_InitPersistentData                                                                      */ /*!

  @brief           Initialize persistent memory structures in FIP curvature change module

  @description     Initialize the persistent memory structures in the sub module.

  @startuml 
    Partition FIP_v_CC_InitPersistentData
    Start
    	Note right: This function initializes persistent memory structures in FIP curvature change module	
    	- Depending on the available sources set default values to the persistent data structure
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             None 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         17.01.2017
  @changed         24.02.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static void FIP_v_CC_InitPersistentData(void)
{
  /*! Init valid flag for fused distance to high curvature change */
  pt_FIP_CC_Output->b_FusedDistToHighCCValid = FALSE;

  /*! Init fused distance to high curvature change */
  pt_FIP_CC_Output->f_FusedDistToHighCC = 0.f;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CC_InitEveryCycle                                                                        */ /*!

  @brief           Initialize in enery cycle in FIP curvature change 

  @description     Initialize non-persistent output data structures and variables with the default values in the sub module,
                   This function uses local pointer to the sub module output instantiated in Frame.
  
  @startuml 
    Partition FIP_v_CC_InitEveryCycle
    Start
    	Note right: This function initializes non-persistent data structures and variables with the default values	
    	- Depending on the available sources set default values to the non-persistent data structure
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_CC_Output : Reference to FIP curvature change module output

  @c_switch_part   -
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             None 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         17.01.2017
  @changed         24.02.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static void FIP_v_CC_InitEveryCycle(void)
{
  /*! Init valid flag for fused distance to high curvature change */
  pt_FIP_CC_Output->b_FusedDistToHighCCValid = FALSE;

  /*! Init fused distance to high curvature change */
  pt_FIP_CC_Output->f_FusedDistToHighCC = 0.f;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_InitCurvatureChangeFusionData                                                           */ /*!

  @brief           Init Function

  @description     Initialize Curvature change information

  @startuml 
    Partition FIP_v_InitCurvatureChangeFusionData
    Start
  	  Note right: This function initializes Curvature change information	
  	  - Depending on the available sources set default values to the Curvature change persistent data structure
    Stop	
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_CC_Output->b_FusedDistToHighCCValid : Valid flag for fused distance to high curvature change [FALSE]
  @glob_out        pt_FIP_CC_Output->f_FusedDistToHighCC : Fused distance to high curvature change [0.0F]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             FIP Init
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         17.01.2017
  @changed         24.02.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void FIP_v_InitCurvatureChangeFusionData(FIP_CC_Output_t * pt_FIP_CC_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_CC_Output = pt_FIP_CC_OutputGlobal;

  /* Initialize persistent memory in FIP CC sub module */
  FIP_v_CC_InitPersistentData();

  /* Reset local pointers */
   pt_FIP_CC_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CurvatureChangeFusionProcess                                                                      */ /*!

  @brief           Determine fused distance to high curvature change (Curve entry/exit)

  @description     Determine FIP Fused distance to high curvature change (Curve entry/exit). This function fuses the distances 
                   to high curvature change based on navi and road information.
  
  @startuml 
    Partition FIP_v_CurvatureChangeFusionProcess
    Start
    	Note right: This function fuses the distances to high curvature change based on navi and road information	
    	If (Road based curvature change computation \n                          AND \n Navigation based curvature change \n computation are present) then (True)	
  	  	If (Road path information is present AND Navigation path information is absent) then (True)
  	  		- Only road based distance to curvature change available
  	  	Else (False)
  	  	If (Road path information is absent AND Navigation path information is present) then (True)
  	  		- Only navi based distance to curvature change available
  	  	Else (False)
  	  	If (Both road path information and navigation path information are present) then (True)
  	  		- Both navi and road deliver valid distances. Fuse them by a weighted sum
  	  	Else (False)
  	  		- None of the input signals available 
  	  		Note right: Both road path information and navigation path information are absent
    		Endif
    		Endif
    		Endif
    	Endif	
  
    	If (Road based curvature change \n computation is present \n                          AND \n Navigation based curvature change \n computation is absent) then (True)	
  	  	If (Road path information is present) then (True)
  	  		- Only road based distance to curvature change available
  	  	Else (False)
  	  		- None of the input signals available
    		Endif
    	Endif
  
    	If (Road based curvature change \n computation is absent \n                          AND \n Navigation based curvature change \n computation is present) then (True)	
    		If (Road path information is present) then (True)
  	  		- Only navigation based distance to curvature change available
  	  	Else (False)
  	  		- None of the input signals available
    		Endif
    	Endif
    Stop	
  @enduml

  @return          -

  @param[in]       pt_FIP_CC_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_CC_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        b_FusedDistToHighCCValid : Valid flag for fused distance to high curvature change
  @glob_out        f_FusedDistToHighCC : Fused distance to high curvature change [0.f ... FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX]

  @c_switch_part   FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION : FCT support for Road based Curvature Change Computation in FIP
  @c_switch_part   FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION : FCT support for Navi based Curvature Change Computation in FIP
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             Computation of navi based distance to curvature change finished. Computation of road based distance to curvature change finished.
                   FIP_v_CC_PreProcess(FIP_CC_InputConst_t * pt_FIP_CC_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         17.01.2017
  @changed         17.01.2017

  @todo            use better navi valid criteria (especially for BW projects)

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void FIP_v_CurvatureChangeFusionProcess(FIP_CC_Output_t * pt_FIP_CC_OutputGlobal)
{
#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  float32 const f_DistToHighCCNavi = FIP_pt_ND_GetNaviData()->f_DistToHighCC;      /* Distance to a high curvature change based on navi path */
  boolean const b_ValidNavi        = FIP_pt_ND_GetNaviData()->b_NaviPathIsValid;   /* Valid flag for distance to a high curvature change based on navi path */
#endif

#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
  float32 const f_DistToHighCCRoad = FIP_pt_RD_GetRoadData()->f_DistToHighCC;          /* Distance to a high curvature change based on road path */
  boolean const b_ValidRoad        = FIP_pt_RD_GetRoadData()->b_RoadPathIsValidForCC; /* Valid flag for distance to a high curvature change based on road path */
#endif

  /* Assign local pointers */
  pt_FIP_CC_Output = pt_FIP_CC_OutputGlobal;

  /*Initializing the input/output structure members*/
  FIP_v_CC_InitEveryCycle();

  /* Set fused valid flag and fuse distances dependent on availability of information */
#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION) && (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  if ( (b_ValidNavi == FALSE) && (b_ValidRoad == TRUE) )
  {
    /* Only road based distance to curvature change available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = TRUE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = f_DistToHighCCRoad;
  } 
  else if ( (b_ValidNavi == TRUE) && (b_ValidRoad == FALSE) )
  {
    /* Only navi based distance to curvature change available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = TRUE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = f_DistToHighCCNavi;
  } 
  else if ( (b_ValidNavi == TRUE) && (b_ValidRoad == TRUE) )
  {  
    /* Both navi and road deliver valid distances. Fuse them by a weighted sum. */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = TRUE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = ((1.f - FIP_DIST_TO_HIGH_CURVATURE_CHANGE_FUS_WEIGHT) * (f_DistToHighCCRoad)) + ((FIP_DIST_TO_HIGH_CURVATURE_CHANGE_FUS_WEIGHT) * (f_DistToHighCCNavi));
  } 
  else /* case ( (b_ValidNavi == FALSE) && (b_ValidRoad == FALSE) ) */
  { 
    /* None of the input signals available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = FALSE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = 0.f;
  }
#endif

#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION) && (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION == SWITCH_OFF)
  if (b_ValidRoad == TRUE)
  {
    /* Only road based distance to curvature change available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = TRUE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = f_DistToHighCCRoad;
  } 
  else /* case (b_ValidRoad == FALSE) */
  { 
    /* None of the input signals available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = FALSE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = 0.f;
  }
#endif

#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION == SWITCH_OFF) && (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  if (b_ValidNavi == TRUE) 
  {
    /* Only navi based distance to curvature change available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = TRUE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = f_DistToHighCCNavi;
  } 
  else /* case (b_ValidNavi == FALSE) */
  { 
    /* None of the input signals available */
    pt_FIP_CC_Output->b_FusedDistToHighCCValid  = FALSE;
    pt_FIP_CC_Output->f_FusedDistToHighCC       = 0.f;
  }
#endif	/* END IF (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION) && (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION) */

  /* Reset local pointers */
  pt_FIP_CC_Output = NULL;
}
///@}
#endif /* FCT_CFG_CURVATURE_CHANGE_COMPUTATION */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
