/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_road_type.c

DESCRIPTION:               ACC FCT Preprocessing of Road Type

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             30.03.2016

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
@defgroup fip_road_type FIP Road Type
@ingroup fip
@brief          Processes Road and Navi data to update FIP road type.\n\n

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

/*! Definition of pointer to FIPRoadType output structure for access within this sub module */
SET_MEMSEC_VAR(pt_FIP_RT_Output)
static FIP_RT_Output_t * pt_FIP_RT_Output; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to fill the data in to the sturcture representing component output */

/*! Definition of pointer to FIPRoadType input structure for access within this sub module */
SET_MEMSEC_VAR(pt_FIP_RT_Input)
static FIP_RT_InputConst_t * pt_FIP_RT_Input; //PRQA S 3229
/* date: 2017-01-08, reviewer:Chintan Raval, reason: Pointer is used to access the data input to the component */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/* Initialize persistent memory structures in FIP RT sub module */
static void FIP_v_RT_InitPersistentData(void);
/*Initializing the input/output structure members*/
static void FIP_v_RT_InitEveryCycle(void);
/*Set the input members*/
static void FIP_v_RT_SetInput(void);

/*************************************************************************************************************************
  Functionname:    FIP_v_RT_PreProcess                                                                              */ /*!

  @brief           Preprocess/ Set input members for FIP Road Type

  @description     Preprocess/ Set input members for the sub module

  @startuml 
    Partition FIP_v_RT_PreProcess
    Start
  	Note right: This function Preprocesses input \n members for FIP Road Type	
  	- Depending on the available sources \n set all the FIP Road Type input
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_RT_InputGlobal : Reference to the sub module input structure instantiated in Frame 

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

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
void FIP_v_RT_PreProcess(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal)
{
  /* Assign local pointers */
  pt_FIP_RT_Input = pt_FIP_RT_InputGlobal;

  /* Set inputs */
  FIP_v_RT_SetInput();

  /* Reset local pointers */
  pt_FIP_RT_Input = NULL;
}
/*************************************************************************************************************************
  Functionname:    FIP_v_Init_FuseRoadType                                                                          */ /*!

  @brief           Initialize FIP Road Type

  @description     Initialize the persistent data and the non-persistent data in the sub module

  @startuml 
    Partition FIP_v_Init_FuseRoadType
    Start
  	Note right: This function initializes the persistent data and \n the non-persistent data in the FIP Road Type	
  	- Depending on the available sources initialize persistent memory structures \n and non-persistent memory structures in FIP Road Type
    Stop
  @enduml

  @return         -

  @param[in]      pt_FIP_RT_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]      pt_FIP_RT_OutputGlobal : Reference to the sub module output structure instantiated in Frame

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             FIP Init
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.04.2016
  @changed         27.04.2016

  @author          Martin Kress | martin.kress-ext@conti-engineering.com | +49 (69) 67869-6196
*************************************************************************************************************************/
void FIP_v_Init_FuseRoadType(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal, FIP_RT_Output_t * pt_FIP_RT_OutputGlobal)
{
  /* Assign local pointers */
  pt_FIP_RT_Input = pt_FIP_RT_InputGlobal;
  pt_FIP_RT_Output = pt_FIP_RT_OutputGlobal;

  /* Initialize persistent memory structures in FIP RT sub module */
  FIP_v_RT_InitPersistentData();

  /*Initializing the input/output structure members*/
  FIP_v_RT_InitEveryCycle();

  /* Reset local pointers */
  pt_FIP_RT_Input = NULL;
  pt_FIP_RT_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_Process_FuseRoadType                                                                       */ /*!

  @brief           Determine FIP Road Type.

  @description     Determine FIP road type. Use EM road type as default. In case of fusion with 
                   navi information, set Navi value in case of valid information (Navi road type can be mapped to EM road type)
                   Set flag in case of Navi road type is used for fusion.
  
  @startuml 
    Partition FIP_v_Process_FuseRoadType
    Start
  	Note right: This function determines FIP Road Type
  	if (Road input data switch is enabled) then (True)
  		- Initialize non-persistent memory \n structures in FIP Road Type
  		:EM road type|
  		Split
  		:ROAD_TYPE_UNKNOWN&gt;
  			- Set Fip road type to \n FIP_ROAD_TYPE_UNKNOWN
  		Split again 
  		:ROAD_TYPE_HIGHWAY&gt;
  			- Set Fip road type to \n FIP_ROAD_TYPE_HIGHWAY
  		Split again
  		:ROAD_TYPE_COUNTRY&gt;
  			- Set Fip road type to \n FIP_ROAD_TYPE_COUNTRY
  		Split again
  		:ROAD_TYPE_CITY&gt;
  			- Set Fip road type to \n FIP_ROAD_TYPE_CITY
  		Split End
  
  	if (Road work class is Road type Level2) then (True)
  		- Set fip road works \n to Deteteced;
  	else (False)
  		- Set fip road works \n to No information;
  	Endif
  
  	else (False)
  	: Set FIP Fused road type to Unknown and \n FIP road works to No information;
  	Endif
  	
  	If (Fusion of navi information in \n road type switch is enabled) then (True)
  		- set fusion bit to false;
  		If (Navigation path is valid) then (True)
  			If (segment type street is \n SLATE_LANE_CHANGE_UNKNOWN) then (True)
  				- Set fip road type to SLATE_LANE_CHANGE_UNKNOWN \n and fusion bit to true
  			Elseif (segment type street is INTERSTATE_HIGHWAY) then (True)
  				- Set fip road type to FIP_ROAD_TYPE_HIGHWAY \n and fusion bit to true
  			Elseif (segment type street is FEDERAL_HIGHWAY \n  FEDERAL_HIGHWAY_DIVIDER \n COUNTRY_ROAD \n COUNTRY_ROAD_DIVIDER) then (True)
  				- Set fip road type to COUNTRY \n and fusion bit to true
  			Elseif (segment type street is TRAFFICCALMZONE_BIDIRECTION \n TRAFFICCALMZONE_ONEWAY \n RESIDENTIAL_BIDIRECTION \n RESIDENTIAL_ONEWAY \n  URBAN_BIDIRECTION \n URBAN_ONEWAY \n URBAN_DIVIDER) then (True)
  				- Set fip road type to CITY \n and fusion bit to true
  			Else (False)
  				- Set fusion bit to false
  			Endif
  		Else (False)
  			- Set fusion bit to false
  		Endif
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       pt_FIP_RT_InputGlobal : Reference to the sub module input structure instantiated in Frame
  @param[in]       pt_FIP_RI_OutputGlobal : Reference to the sub module output structure instantiated in Frame
                     t_FIPFusedRoadType : FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
                     t_FIPRoadWorks : FIP road works type [full range of FIP_t_RoadWorks as in fip_ext.h]
                     b_FIPFusedRoadTypeFromNavi : fusion bit if the information from navi is fused [TRUE, FALSE
  @glob_in         pSLATE_NaviData->Segments[0].TypStreet : Navi road type [full range of t_NavStreetType as in Rte_Type.h]
  @glob_in         ROAD_GET_ROADTYPE : EM Road Type                         [full range of eRoadTypeLevel1_t as in Rte_Type.h]
  @glob_in         ROAD_GET_ROADWORKS : EM Road Works Type                  [full range of eRoadTypeLevel2_t as in Rte_Type.h]

  @c_switch_part   FCT_CFG_FUSION_NAVI_ROAD_TYPE : Config switch for fusion of navi information in road type
  @c_switch_part   FCT_CFG_ROAD_INPUT : Config switch for Road input
  @c_switch_part   FIP_CFG_CAM_WIDTH_ROAD_TYPE : Config switch to determine road type when EM and Navi road types mismatch
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             FIP_v_RT_PreProcess(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         27.04.2016
  @changed         22.07.2016

  @author          Martin Kress | martin.kress-ext@conti-engineering.com | +49 (69) 67869-6196
*************************************************************************************************************************/
void FIP_v_Process_FuseRoadType(FIP_RT_InputConst_t * pt_FIP_RT_InputGlobal, FIP_RT_Output_t * pt_FIP_RT_OutputGlobal)
{

#if (FCT_CFG_ROAD_INPUT)
#if (EM_ROAD_INTFVER == 1u)
  eRoadType_t t_EM_RoadType = ROAD_GET_ROADTYPE;
#else
  eRoadTypeClass_t t_EM_RoadType = ROAD_GET_ROADTYPE;
#endif /* END IF (EM_ROAD_INTFVER == 1u) */
#endif

  /* Assign local pointers */
  pt_FIP_RT_Input = pt_FIP_RT_InputGlobal;
  pt_FIP_RT_Output = pt_FIP_RT_OutputGlobal;

#if (FCT_CFG_ROAD_INPUT)

  /*Initializing the input/output structure members*/
  FIP_v_RT_InitEveryCycle();

/* Map FIP Road Type to Radar Road Type */
  switch(t_EM_RoadType)
  {
    case ROAD_TYPE_UNKNOWN:
      pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
      break;
    
    case ROAD_TYPE_HIGHWAY:
      pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_HIGHWAY;
      break;
    
    case ROAD_TYPE_COUNTRY:
      pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_COUNTRY;
      break;

    case ROAD_TYPE_CITY:
      pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_CITY;
      break;

    default: 
      pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
      break;
  }

  /* Map FIP Road Works to Radar Value */
  if(ROAD_GET_ROADWORKS == ROAD_TYPE_LEVEL2_ROADWORKS)
  {
    pt_FIP_RT_Output->t_FIPRoadWorks = FIP_ROADWORKS_DETECTED;
  }
  else
  {
    pt_FIP_RT_Output->t_FIPRoadWorks = FIP_NOINFO_ROADWORKS;
  }
#else
  _PARAM_UNUSED(pt_FIP_RT_InputGlobal);
  _PARAM_UNUSED(pt_FIP_RT_OutputGlobal);
  pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
  pt_FIP_RT_Output->t_FIPRoadWorks = FIP_NOINFO_ROADWORKS;
#endif /* END IF (FCT_CFG_ROAD_INPUT) */
  
#if (FCT_CFG_FUSION_NAVI_ROAD_TYPE)

  pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = FALSE; /*set fusion bit to false initially */

  /* Check if the Navi data is valid - no PSD Degradation*/
  if( pt_FIP_RT_Input->b_NaviPathIsValid == TRUE )
  {
    /* use Navi road type and map it to Radar road type */
    switch (pSLATE_NaviData->Segments[0].TypStreet)
    {
      case NAV_STT_UNKNOWN:
        pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
        pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = TRUE;
        break;

      case NAV_STT_INTERSTATE_HIGHWAY:
        pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_HIGHWAY;
        pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = TRUE;
        break;

      case NAV_STT_FEDERAL_HIGHWAY:
      case NAV_STT_FEDERAL_HIGHWAY_DIVIDER:
      case NAV_STT_COUNTRY_ROAD:
      case NAV_STT_COUNTRY_ROAD_DIVIDER:
        pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_COUNTRY;
        pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = TRUE;
        break;

      case NAV_STT_TRAFFICCALMZONE_BIDIRECTION:
      case NAV_STT_TRAFFICCALMZONE_ONEWAY:
      case NAV_STT_RESIDENTIAL_BIDIRECTION:
      case NAV_STT_RESIDENTIAL_ONEWAY:
      case NAV_STT_URBAN_BIDIRECTION:
      case NAV_STT_URBAN_ONEWAY:
      case NAV_STT_URBAN_DIVIDER:
        pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_CITY;
        pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = TRUE;
        break;

      case NAV_STT_RAILTRACK:
      case NAV_STT_FERRY:
      case NAV_STT_RACETRACK:
      case NAV_STT_SIGNAL_UNFILLED:
      case NAV_STT_URBAN_INTERSTATE_HIGHWAY: // TBD: ask Yvonne
      case NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER:
      case NAV_STT_FEDERAL_HIGHWAY_RAMP:
      case NAV_STT_FEDERAL_HIGHWAY_EXIT:
      case NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT:
      case NAV_STT_INTERSTATE_HIGHWAY_RAMP:
      case NAV_STT_INTERSTATE_HIGHWAY_EXIT:
      case NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT:
        /* use radar data */
        pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = FALSE;
        break;

      default:
        pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
        pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = FALSE;
        break;
    }
  }
  else
  {
    /* Navi data invalid */
    pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = FALSE;
  }

#if (FIP_CFG_CAM_WIDTH_ROAD_TYPE)
/* This is to be enabled only in ARS510VW19 project as the road types were wrong */
  pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_CamWidth_RoadType(pt_FIP_RT_Output);
#endif /* (FIP_CFG_CAM_WIDTH_ROAD_TYPE) */

#endif /* END IF (FCT_CFG_FUSION_NAVI_ROAD_TYPE) */

  /* Reset local pointers */
  pt_FIP_RT_Input = NULL;
  pt_FIP_RT_Output = NULL;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_RT_InitPersistentData                                                                      */ /*!

  @brief           Initialize persistent memory structures in FIP Road Type

  @description     Initialize persistent memory structures in the sub module

  @startuml 
    Partition FIP_v_RT_InitPersistentData
    Start
  	Note right: This function initializes persistent memory structures in FIP Road Type	
  	If (Simple navigation input data switch \n AND \n FCT Input processing switch is enabled) then (True)
  		- Set if Navigation path is valid to FALSE
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

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
static void FIP_v_RT_InitPersistentData(void)
{
  /* Input from other modules to FIP Road Type */
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_FIP_RT_Input->b_NaviPathIsValid = FALSE;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
}

/*************************************************************************************************************************
  Functionname:    FIP_v_RT_InitEveryCycle                                                                          */ /*!

  @brief           Initialize in every cycle in FIP Road Type

  @description     Initialize non-persistent output data structures and variables with the default values, This function uses 
                   local pointer to the sub module output instantiated in Frame
  
  @startuml 
    Partition FIP_v_RT_InitEveryCycle
    Start
  	Note right: This function non-persistent output data \n structures and variables with the default values
  	- Set FIP road works to No information \n and FIP Road Type to UNKNOWN
  
  	If (Fusion of navi information in \n road type switch is enabled) then (True)
  		- Set fusion bit to FALSE
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_RT_Output: Reference to Road Type module output
                    t_FIPFusedRoadType : FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
                    t_FIPRoadWorks : FIP road works type [full range of FIP_t_RoadWorks as in fip_ext.h]
                    b_FIPFusedRoadTypeFromNavi : fusion bit [TRUE, FALSE]

  @c_switch_part   FCT_CFG_FUSION_NAVI_ROAD_TYPE: Config switch for fusion of navi information in road type
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

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
static void FIP_v_RT_InitEveryCycle(void)
{

  /*! Initializing the output structure members, which don't have "history" */
  pt_FIP_RT_Output->t_FIPRoadWorks = FIP_NOINFO_ROADWORKS;
  pt_FIP_RT_Output->t_FIPFusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
#if (FCT_CFG_FUSION_NAVI_ROAD_TYPE)
  pt_FIP_RT_Output->b_FIPFusedRoadTypeFromNavi = FALSE;
#endif
}
/*************************************************************************************************************************
  Functionname:    FIP_v_RT_SetInput                                                                                */ /*!

  @brief           Set the input for FIP Road Type

  @description     Set the input for the sub module

  @startuml 
    Partition FIP_v_RT_SetInput
    Start
  	Note right: This function sets the input for FIP Road Type	
  	If (Simple navigation input data switch \n AND \n FCT Input processing switch is enabled) then (True)
  		- Update if the Navigation path is valid
  	Else (False)
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             None
  @post            No changes

  @created         03.10.2016
  @changed         03.10.2016

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
static void FIP_v_RT_SetInput(void)
{
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
  pt_FIP_RT_Input->b_NaviPathIsValid = FIP_pt_ND_GetNaviData()->b_NaviPathIsValid;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */
}
///@}
#endif /* FCT_CFG_INPUT_PREPROCESSSING */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
