/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_traffic_orientation.c

DESCRIPTION:               ACC FCT Preprocessing of Traffic Orientation

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             30.03.2016

VERSION:                   $Revision: 1.18 $

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
@defgroup fip_traffic_orientation FIP Traffic Orientation
@ingroup fip
@brief          Proecessing of Traffic Orientation data from EM is done here.\n\n

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

/*! Definition of pointer to Traffic orientation output structure for access from other components */
SET_MEMSEC_VAR(pt_FIP_TO_Output)
static FIP_TO_Output_t * pt_FIP_TO_Output; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to fill the data in to the sturcture representing component output */

/*! Definition of Traffic orientation input structure */
SET_MEMSEC_VAR(pt_FIP_TO_Input)
static FIP_TO_InputConst_t * pt_FIP_TO_Input; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to access the data which is input to the component */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_TO_InitPersistentData(void);
static void FIP_v_TO_InitEveryCycle(void);
static void FIP_v_TO_SetInput(void);

/*************************************************************************************************************************
  Functionname:    FIP_v_InitGlobalLaneTrafficOrientation                                                           */ /*!

  @brief           Initialize FIP Global Lane Traffic Orientation Data

  @description     Initialize the persistent data and non-persistent data in the sub module.

  @startuml 
    Partition FIP_v_InitGlobalLaneTrafficOrientation
    Start
  	  Note right: This function initializes the persistent data \n and non-persistent data	
  	  - Depending on the available sources initialize \n persistent data and non-persistent data structure
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_TO_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_TO_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.04.2016
  @changed         07.04.2016

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 (69) 67869-6110
*************************************************************************************************************************/
void FIP_v_InitGlobalLaneTrafficOrientation(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal, FIP_TO_Output_t * pt_FIP_TO_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_TO_Input = pt_FIP_TO_InputGlobal;
  pt_FIP_TO_Output = pt_FIP_TO_OutputGlobal;

  /* Initialize persistent memory in FIP TO sub module */
  FIP_v_TO_InitPersistentData();

  /*Initializing the input/output structure members*/
  FIP_v_TO_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_TO_Input = NULL;
  pt_FIP_TO_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_TO_PreProcess                                                                              */ /*!

  @brief           Preprocess/ Set inputs for FIP Traffic Orientation module

  @description     Preprocess/ Set inputs for the sub module

  @startuml 
    Partition FIP_v_TO_PreProcess
    Start
  	  Note right: This function Preprocesses inputs \n for FIP Traffic Orientation module
  	  - Depending on the available sources set the \n input for Traffic Orientation PreProcess
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_TO_InputGlobal : Reference to the sub module input structure instantiated in Frame

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

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
void FIP_v_TO_PreProcess(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal)
{
  /* Assign local pointers */
  pt_FIP_TO_Input = pt_FIP_TO_InputGlobal;

  /* Set Inputs */
  FIP_v_TO_SetInput();

  /* Reset local pointers */
  pt_FIP_TO_Input = NULL;
}
/*************************************************************************************************************************
  Functionname:    FIP_v_TrafficOrientationProcess                                                                  */ /*!

  @brief           Determine FIP Traffic Orientation

  @description     Determine FIP Traffic Orientation. Use EM Traffic Orientation as default. In case of fusion with 
                   navi information, set navi value if case of valid information
  
  @startuml 
    Partition FIP_v_TrafficOrientationProcess
    Start
  	Note right: This function determines FIP Traffic Orientation
  	- Initialize FIP Traffic Orientation data
  
  	If (Road input data switch is enabled) then (True)
  		- Update Traffic orientation from \n Road traffic orientation Information
  	Else (False)
  		- Update Traffic orientation to Unknown
  	Endif
  
  	If (Fusion of navigation information in traffic orientation is enabled) then (True)
  		If (Navigation path is available) then (True)
  			If (Navigation path is Right OR Left) then (True)
  				- Update Traffic orientation from \n Navigation traffic orientation Information
  			Else (False)
  				-&lt;color:Green&gt; Navi Traffic orientation not set&lt;/color&gt;
  			Endif
  		Else (False)
  				-&lt;color:Green&gt; Navi data not available &lt;/color&gt;
  		Endif
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_TO_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_TO_OutputGlobal : Reference to the sub module output structure instantiated in Frame
                      t_FIPTrafficOrientation : FIP Traffic Orientation [full range of SLATE_t_TrafficOrientation as in slate_types.h]
  @glob_in         TRAFFIC_ORIENTATION : EM Traffic Orientation [full range of SLATE_t_TrafficOrientation as in slate_types.h]
  @glob_in         pSLATE_NaviData->e_NaviTrafficOrientation : Navi Traffic Orientation [full range of SLATE_t_TrafficOrientation as in slate_types.h]

  @c_switch_part   FCT_CFG_FUSION_NAVI_TRAF_ORIENT : Config switch for fusion of navi information in Traffic Orientation
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             FIP_v_TO_PreProcess(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.04.2016
  @changed         07.04.2016

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 (69) 67869-6110
*************************************************************************************************************************/
void FIP_v_TrafficOrientationProcess(FIP_TO_InputConst_t * pt_FIP_TO_InputGlobal, FIP_TO_Output_t * pt_FIP_TO_OutputGlobal)
{
#if (FCT_CFG_FUSION_NAVI_TRAF_ORIENT)
  SLATE_t_TrafficOrientation e_NaviTrafficOrientation;
#endif
  /* Assign local pointers */
  pt_FIP_TO_Input = pt_FIP_TO_InputGlobal;
  pt_FIP_TO_Output = pt_FIP_TO_OutputGlobal;

  /* Initializing the input/output structure members*/
  FIP_v_TO_InitEveryCycle();

  /* Get radar traffic orientation as default for FIP traffic estimation*/
#if (FCT_CFG_ROAD_INPUT) 
  pt_FIP_TO_Output->t_FIPTrafficOrientation = (SLATE_t_TrafficOrientation)ROAD_GET_TRAFFIC_ORIENTATION;//PRQA S 1482
/* date:2017-10-31, reviewer: Dyuthi Varier reason: cast type is valid */
#else
  pt_FIP_TO_Output->t_FIPTrafficOrientation = SLATE_TRAFFIC_ORIENTATION_UNKNOWN;
#endif /* FCT_CFG_ROAD_INPUT */

#if (FCT_CFG_FUSION_NAVI_TRAF_ORIENT)

  /* Check if the Navi data is valid - no PSD Degradation*/
  if( pt_FIP_TO_Input->b_NaviPathIsValid == TRUE )
  {
    /* In case of fusion with navi information, set navi value if case of valid information */
    e_NaviTrafficOrientation = (SLATE_t_TrafficOrientation)pSLATE_NaviData->e_NaviTrafficOrientation; //PRQA S 1482
    /* date: 2019-06-13, reviewer: Radhakrishna Vemula, reason: this cast to enum type is valid */
    if(   (e_NaviTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT) 
       || (e_NaviTrafficOrientation == SLATE_TRAFFIC_ORIENTATION_RIGHT) )
    {
      pt_FIP_TO_Output->t_FIPTrafficOrientation = e_NaviTrafficOrientation;
    }
    else
    {
      /* Navi Traffic orientation not set*/
    }
  }
  else
  {
    /* Navi data not valid */
  }
#endif

  /* Fill the Custom Traffic Orientation signals */
  FIP_v_Set_CustomTrafficOrientation(pt_FIP_TO_Output);

  /* Reset local pointers */
  pt_FIP_TO_Input = NULL;
  pt_FIP_TO_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_TO_InitPersistentData                                                                      */ /*!

  @brief           Initialize persistent memory structures in FIP Traffic Orientation module

  @description     Initialize the persistent memory structures in the sub module. The Custom Traffic Orientation is initialized

  @startuml 
    Partition FIP_v_TO_InitPersistentData
    Start
  	Note right: This function initializes persistent memory \n structures in FIP Traffic Orientation module	
  	- Initialize custom signals
  	- Assign FIP Input Navigation path is valid to NULL
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

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
static void FIP_v_TO_InitPersistentData(void)
{
  FIP_v_Init_CustomTrafficOrientation();
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_FIP_TO_Input->b_NaviPathIsValid = FALSE;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
}

/*************************************************************************************************************************
  Functionname:    FIP_v_TO_InitEveryCycle                                                                          */ /*!

  @brief           Initialize in every cycle in FIP Taffic Orientation

  @description     Initialize non-persistent output data structures and variables with the default values. This function uses 
                   local pointer to the sub module output instantiated in Frame

  @startuml 
    Partition FIP_v_TO_InitEveryCycle
    Start
  	  Note right: This function initializes non-persistent output data \n structures and variables with the default values	
  	  - Assign Traffic orientation to Unknown
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_TO_Input: Reference to Traffic Orientation module input
  @glob_out        pt_FIP_TO_Output: Reference to Traffic Orientation module output
                    t_FIPTrafficOrientation: FIP Traffic Orientation [full range of SLATE_t_TrafficOrientation as in slate_types.h]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

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
static void FIP_v_TO_InitEveryCycle(void)
{
  /* Initialize pointer to NULL*/
  pt_FIP_TO_Output->t_FIPTrafficOrientation = SLATE_TRAFFIC_ORIENTATION_UNKNOWN;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_TO_SetInput                                                                                */ /*!

  @brief           Set the inputs for FIP Traffic Orientation

  @description     Set the inputs for the sub module

  @startuml 
    Partition FIP_v_TO_SetInput
    Start
  	Note right: This function sets the inputs for FIP Traffic Orientation	
  	- Set to FIP Input if NAVI path is valid or not information
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

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
static void FIP_v_TO_SetInput(void)
{
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_FIP_TO_Input->b_NaviPathIsValid = FIP_pt_ND_GetNaviData()->b_NaviPathIsValid;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
}

/*************************************************************************************************************************
  Functionname:    FIP_v_TOSetMeasData                                                                              */ /*!

  @brief           Fill out Meas Freeze structure in TO sub-module

  @description     Fill out Meas Freeze structure in TO sub-module. Since Meas Freeze structures are visible only in FIP main,
                   this function is called from generic freeze function in FIP Main.
  
  @startuml 
    Partition FIP_v_TOSetMeasData
    Start
        Note right: This function fills out Meas Freeze \n structure in Lane matrix sub-module
        -Freeze the Traffic orientation information for Measurement structure
    Stop
  @enduml

  @return          -

  @param[out]      pt_TODebugMeasFreeze : Reference to TO freeze part in FIP freeze structure
  @param[in]       pt_FIP_TO_OutputLocal : Reference of TO output in FIP output structure

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : Config switch for FIP Traffic orientation: Need to be switched on for ACC

  @pre             FIP_v_TrafficOrientationProcess() 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.05.2019
  @changed         01.05.2019

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_TOSetMeasData(FIPTO_DeviceMeasInfo_t * pt_TODebugMeasFreeze, FIP_TO_Output_t const * pt_FIP_TO_OutputLocal)
{
  pt_TODebugMeasFreeze->t_FIPTrafficOrientation = pt_FIP_TO_OutputLocal->t_FIPTrafficOrientation;
}

///@}
#endif /* FCT_CFG_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
