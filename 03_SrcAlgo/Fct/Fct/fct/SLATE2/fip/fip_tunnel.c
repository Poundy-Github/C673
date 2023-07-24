/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 FIP (FCT Input Preprocessing)

PACKAGENAME:               fip_tunnel.c

DESCRIPTION:               FIP abstraction layer Tunnel information. Taken over from version 1.0

AUTHOR:                    Badiger Gangadhar (uidr5782)

CREATION DATE:             7/27/2016

VERSION:                   $Revision: 1.8 $

---*/ /*---
CHANGES:                    $Log: fip_tunnel.c  $
CHANGES:                    Revision 1.8 2020/09/02 12:24:51CEST Pathak, Praveen (uib42092) (uib42092) 
CHANGES:                    Placed FIp files after PlantUML updation.
CHANGES:                    Revision 1.7 2020/08/09 17:31:12CEST Ramesh, Sangeetha (uidn1528) 
CHANGES:                    Added Test methods in funtion headers
CHANGES:                    Revision 1.6 2019/07/30 13:45:23CEST Rajeev, Mekala (uia75188) (uia75188) 
CHANGES:                    [SLATE2] Adding Comments to QAF Rule 3 Warnings
CHANGES:                    Revision 1.5 2018/05/22 11:36:38CEST Kotra, Pavan (uidk2002) 
CHANGES:                    Added Doxygen tags for design documentation
CHANGES:                    Revision 1.4 2018/02/23 12:53:15CET Gobichettipalayam Sankar, Bharadwaj (uidk9952) 
CHANGES:                    [SLATE2] Frame Processing
CHANGES:                    Revision 1.3 2017/08/30 11:56:43CEST Raj, Rahul (uid41599) 
CHANGES:                    FIP PlantUML Updates
CHANGES:                    Revision 1.2 2017/04/25 15:37:05CEST Umesh Babu, Harsha (uidj3583) 
CHANGES:                    Update SLATE2 towards mainstream maturity
CHANGES:                    Revision 1.1 2017/03/02 08:33:58CET Koschalka, Mike (uidg3250) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/SLATE2_SituationLaneAssociationTrajectoryEstimation2/04_Engineering/01_Source_Code/SLATE2/fip/project.pj
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fip.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "fip_cfg.h"
#if (FCT_CFG_INPUT_PREPROCESSSING)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_tunnel FIP Tunnel
@ingroup fip
@brief          Processes Tunnel data from Navi interface.\n\n

@{

*/
#if(FIP_CFG_USE_TUNNEL)


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/
/*Tunnel probabality threshold*/
#define  FIP_TUNNEL_PROB_THRES         0.5f
/*Lenght of the worls longest road tunnel(Laerdal – Aurland) distance*/
#define  FIP_WORLDS_LONGEST_TUNNEL     24500
/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/
/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/
/* FIP_Tunnel structure variable*/
static FIP_Tunnel fTunnelInformation;
/* pointer to FIP_Tunnel structure variable*/
static FIP_Tunnel *pTunnelInformation;


/*************************************************************************************************************************
  Functionname:    fip_v_Init_TunnelInformation                                                                     */ /*!

  @brief           Initialize the tunnel information varaibles

  @description     Initialize the tunnel information varaibles i.e tunnel probabality and tunnel plausibality.

  @startuml 
    Partition FIP_v_Init_TunnelInformation
    Start
  	  Note right: This function initializes the tunnel related varaibles	
  	  - Set Tunnel probability to 0 and Tunnel plausibility to False
    Stop
  @enduml

  @return          void

  @param[in]       void : 
                    pTunnelInformation->fTunnelProbability      [0    1]
                    pTunnelInformation->b_Tunnelplausibility    [0    1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full    FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         7/27/2016
  @changed         7/27/2016

  @author          Gangadhar Badiger | gangadhar.badiger-ext@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
void fip_v_Init_TunnelInformation(void)
{ 
/* Storing address of fTunnelInformation variable in pointer variable */
pTunnelInformation = &fTunnelInformation;

pTunnelInformation->fTunnelProbability = 0.f;
pTunnelInformation->b_Tunnelplausibility = FALSE;
}


/*************************************************************************************************************************
  Functionname:    fip_b_TunnelProcessing                                                                     */ /*!

  @brief           Tunnel information based on the valid navi data and from Environmental model

  @description     Tunnel information based on the valid navi data and from Environmental model
                    when Ego vehicle is inside the tunnel, u_DistNextTunnelStart will become zero and remains zero till the end of the tunnel.
                    At the satrt of the tunnel u_DistNextTunnelEnd wll be having the value equivalent to length of the tunnel and decreases as 
                    ego is moving inside the tunnel and becomes zero when tunnel ends 
                    TUNNEL_PROBABILITY from EM will have value >=0.5 when it is inside the tunnel
                    combining these two information tunnel_plausibalization is determined.
  
  @startuml 
    Partition FIP_b_TunnelProcessing
    Start
  	Note right: This function updates tunnel information based on the valid navi data and from Environmental model
  
  	If (Signal performance monitoring switch is enabled) then (True)
  		- Accessing tunnel probability data from EM and storing in the local structure
  	Else (False)
  	Endif
  
  	If (Navigation input data switch is enabled) then (True)
  		If (Navigation path is Valid) then (True)
  			If (Distance of Next Tunnel Start is equal to 0 \n                     AND      \n Distance of Next Tunnel End is greater then 0 \n                      AND      \n Distance of Next Tunnel End is less than threshold) then (True)
  				- Set Navigation indicates Tunnel to True
  			Else (False)
  			Endif
  		Else (False)
  		Endif
  	Else (False)
  	Endif
  
  	If (Tunnel Probability is greater than or equal to threshold \n       AND       \n Navigation indicates tunnel is True)
  		- Set tunnel plausibility to True
  	Else (False)
  	Endif
  
    Stop
  @enduml

  @return          void

  @param[in,out]   


  @glob_in         TUNNEL_PROBABILITY                             [0       1]
                   pSLATE_NaviData-> u_DistNextTunnelStart       [0   65535] as defined in Rte_Type.h
                   pSLATE_NaviData->u_DistNextTunnelEnd          [0   65535] as defined in Rte_Type.h


  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING    : FCT signal performance monitoring
                   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN

  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         7/27/2016
  @changed         7/27/2016

  @author          Gangadhar Badiger | gangadhar.badiger-ext@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
void fip_b_TunnelProcessing(void)
{
  /*Local variable to indicate when vehicle is inside the tunnel*/
  boolean b_NaviIndicatesTunnel = FALSE;

#if (FCT_CFG_SIGNAL_PERF_MONITORING)

  /* Accessing tunnel probability data from EM and storing in the local structure*/
  pTunnelInformation->fTunnelProbability = *pt_FIP_RTE_Input->pf_TunnelProbability;

#endif /* END IF (FCT_CFG_SIGNAL_PERF_MONITORING) */

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
  if( FIP_b_GetNaviPathIsValid() == TRUE )
  {
    /* Check if NAVI data is valid, currently using path valid since it is more closer to reasoning */

        if ((pSLATE_NaviData->u_DistNextTunnelStart == 0u ) && ((pSLATE_NaviData->u_DistNextTunnelEnd > 0u) && (pSLATE_NaviData->u_DistNextTunnelEnd < FIP_WORLDS_LONGEST_TUNNEL)))
        {
              b_NaviIndicatesTunnel = TRUE;
              
        }
          
          
    
  } /* END IF ( FIP_b_GetNaviPathIsValid() == TRUE ) */

  /* Fusion of different information sources for tunnel information */
  if ((pTunnelInformation->fTunnelProbability >= FIP_TUNNEL_PROB_THRES) &&
      (b_NaviIndicatesTunnel == TRUE))
  {
    pTunnelInformation->b_Tunnelplausibility = TRUE;

  }
#endif /* END IF (SLATE_CFG_SIMPLE_NAVI_INTERFACE) */


}

/*************************************************************************************************************************
  Functionname:    FIP_t_GetTunnelproabality                                                                        */ /*!

  @brief           To get the tunnel probabality data

  @description     To get the tunnel probabality data
   
  @startuml 
  Partition FIP_t_GetTunnelproabality
  Start
	- Return tunnel probabality data	
  Stop
  @enduml

  @return          float pTunnelprobability->FIPTunnelProbability : Tunnel probabality data from EM     [0   1]

  @param[in]       void : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         7/27/2016
  @changed         7/27/2016

  @author          Gangadhar Badiger | gangadhar.badiger-ext@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
float32 fip_t_GetTunnelproabality(void)
{
  return pTunnelInformation->fTunnelProbability;
}

/*************************************************************************************************************************
  Functionname:    FIP_b_GetTunnelplausibality                                                                      */ /*!

  @brief           To get the Tunnel plausibality information

  @description     To get the Tunnel plausibality information

  @startuml 
  Partition FIP_b_GetTunnelplausibality
  Start
  	- Return Tunnel plausibality information	
  Stop
  @enduml

  @return          boolean  pTunnelprobability->b_Tunnelplausibility : Tunnel plausiabality decision based on valid navi and EM data    [0    1]

  @param[in]       void : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -FCT_CFG_INPUT_PREPROCESSSING: FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         7/27/2016
  @changed         7/27/2016

  @author          Gangadhar Badiger | gangadhar.badiger-ext@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
boolean fip_b_GetTunnelplausibality(void)
{
  return pTunnelInformation->b_Tunnelplausibility;
}

#endif/*ENDIF (FCT_CFG_USE_TUNNEL)*/
///@}
#endif/* END IF (FCT_CFG_INPUT_PREPROCESSSING) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
