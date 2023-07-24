/*! \file **********************************************************************

  TEMPLATE VERSION:          1.1
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSNDSEN_custom.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.3 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include "LCFSEN/LCFSEN_data.h"

/*---------------------------------------------------------*
   T Y P E S / D E F I N E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   G L O B A L   V A R I A B L E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**---------------------------------------------------------*/

/* ***********************************************************************
  @fn               LCFSND_SenCustomProcess */ /*!

  @brief            Customer specific LCFSND process

  @description      

  @param[in]        
  @param[out]       
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_SenCustomProcess(void)
{
	pLcfSenProPorts->pLcfSenOutputData->VisualWrnDeviceLeftReq_nu = GET_S_HMODFL_LKAStatusChange_nu();
	
	// 2021.3.1 added, HMI lane marking display  //MFC5J3
	 pLcfSenProPorts->pLcfSenOutputData->TMC_SEN_Out.TMC_LaneDispLeft_nu     = (((GET_S_TJALKA_LnBndValid_nu() == 3) ? 1 : 0) || ((GET_S_TJALKA_LnBndValid_nu() == 1) ? 1 : 0));
     	pLcfSenProPorts->pLcfSenOutputData->TMC_SEN_Out.TMC_LaneDispRight_nu    = (((GET_S_TJALKA_LnBndValid_nu() == 3) ? 1 : 0) || ((GET_S_TJALKA_LnBndValid_nu() == 2) ? 1 : 0));
}

/* ***********************************************************************
  @fn               LCFRCV_SenCustomReset */ /*!

  @brief            Customer specific LCFRCV reset

  @description

  @param[in]
  @param[out]
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_SenCustomReset(void)
{

}

