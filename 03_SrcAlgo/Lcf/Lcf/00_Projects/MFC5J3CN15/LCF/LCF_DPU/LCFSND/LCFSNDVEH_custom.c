/*! \file **********************************************************************

  TEMPLATE VERSION:          1.1
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFSNDVEH_custom.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */
//#ifndef LCFSNDVEH_CUSTOM_C_
//#define LCFSNDVEH_CUSTOM_C_
///*---------------------------------------------------------*
//   I N C L U D E S
//**---------------------------------------------------------*/
//#include "LCFVEH/LCFVEH_data.h" /* Need for LATDMC and ALCASysState signals overwrite*/
///*---------------------------------------------------------*
//   T Y P E S / D E F I N E S
//**---------------------------------------------------------*/
//
///*---------------------------------------------------------*
//   G L O B A L   V A R I A B L E S
//**---------------------------------------------------------*/
//
///*---------------------------------------------------------*
//   F U N C T I O N   P R O T O T Y P E S
//**---------------------------------------------------------*/
//
///*---------------------------------------------------------*
//   F U N C T I O N   D E F I N I T I O N S
//**---------------------------------------------------------*/
//#endif  /*LCFSNDVEH_CUSTOM_C_*/



/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
#include "LCFVEH/LCFVEH_data.h"
#include "cml_ext.h"
/*---------------------------------------------------------*
   T Y P E S / D E F I N E S
**---------------------------------------------------------*/

/*---------------------------------------------------------*
   G L O B A L   V A R I A B L E S
**---------------------------------------------------------*/
static uint8 MFC5J3_DrvOverrideTorqueAssement_nu = 1;
static uint8 MFC5J3_DrvOverrideTorqueRampoutFlag = 0;
static float32 LCFSND_EPSLastAngleReq_deg = 0.0f;

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/
static uint8 HoldTurnIndicator(uint8 ConfCycles);

/*---------------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**---------------------------------------------------------*/

 /* ***********************************************************************
  @fn               LCFSND_VehCustomProcess */ /*!

  @brief            Customer specific LCFSND process

  @description

  @param[in]
  @param[out]
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_VehCustomProcess(void)
{
	pLcfVehProPorts->pLcfVehOutputData->LaDMC_StrAngReq_deg = (float32)(LAT_Steer_Angle_Command_deg * LADMC_STANGREQ_RES);  //MFC5J3CN15
	pLcfVehProPorts->pLcfVehOutputData->LaDMC_StiffnessReq_nu = (float32)LAT_Stiffness_Request_per;  //MFC5J3CN15
	/*pLcfVehProPorts->pLcfVehOutputData->LaDMC_DeratingFactorReq_nu = (float32)LAT_Derating_Level_Request_per; */
	pLcfVehProPorts->pLcfVehOutputData->LaDMC_DeratingFactorReq_nu = (uint8)(TDF_Sac_Dos_Limit_Scale_dbg*100/1024);  /*HU XIAOHUI  Derating factor match to TDF factor*/

   // 02/02/2023 Test for MFC5J3 C385 optimize Driver override experience
   // 02/14/2023 Reduce RAMPOUT Control duration, pls verify
   if (LADMC_EPS_INTERFACE_ACTIVE_REQ == 0) /* LADMC_EPS_INTERFACE_ACTIVE_REQ range: 0..7 */
	{
		pLcfVehProPorts->pLcfVehOutputData->Lkas_ActToi_nu = (uint8)LCF_DEACTIVATE_TOI;
	}
	else
	{
		pLcfVehProPorts->pLcfVehOutputData->Lkas_ActToi_nu = (uint8)LCF_ACTIVATE_TOI;
      if (MFC5J3_DrvOverrideTorqueAssement_nu == 1 &&
          (CML_f_Abs(pLcfVehReqPorts->pLcfInputData->DrvSteerWheelTrq_nm) >= GET_P_VDPDRV_ManTrqOvrrdMaxTrq_Nm() ||
           MFC5J3_DrvOverrideTorqueRampoutFlag == 1)
      )
      {
         if (pLcfVehReqPorts->pLcfSenOutputData->TJASystemState_nu == E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu ||
             pLcfVehReqPorts->pLcfSenOutputData->LDPSystemState_nu == E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu ||
             pLcfVehReqPorts->pLcfSenOutputData->ALCASystemState_nu == E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu ||
             pLcfVehReqPorts->pLcfSenOutputData->RDPSystemState_nu == E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)
         {
            pLcfVehProPorts->pLcfVehOutputData->Lkas_ActToi_nu = (uint8)LCF_DEACTIVATE_TOI;
            // pLcfVehProPorts->pLcfVehOutputData->LaDMC_Status_nu = (uint8)LCF_LADMC_OFF;
            MFC5J3_DrvOverrideTorqueRampoutFlag = 1;
         }
      }
	}

   // for MFC5J3 clear MFC5J3_DrvOverrideTorqueRampoutFlag
   if (pLcfVehReqPorts->pLcfSenOutputData->TJASystemState_nu != E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu &&
       pLcfVehReqPorts->pLcfSenOutputData->LDPSystemState_nu != E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu &&
       pLcfVehReqPorts->pLcfSenOutputData->ALCASystemState_nu != E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu &&
       pLcfVehReqPorts->pLcfSenOutputData->RDPSystemState_nu != E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)
   {
      MFC5J3_DrvOverrideTorqueRampoutFlag = 0;
   }
}

/* ***********************************************************************
  @fn               LCFSND_VehCustomReset */ /*!

  @brief            Customer specific LCFRCV reset

  @description

  @param[in]
  @param[out]
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */
void LCFSND_VehCustomReset(void)
{

}

 /* ***********************************************************************
  @fn               HoldTurnIndicator */ /*!

  @brief            Hold TurnSignalLever_nu signal for x amount of cycles

  @description      -

  @param[in]
  @param[out]
  @return           void

  @pre              -
  @post             -
  **************************************************************************** */

