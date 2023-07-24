/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFRCVSEN_custom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.7 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

#ifndef LCFRCVSEN_CUSTOM_H_
#define LCFRCVSEN_CUSTOM_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/
 
#include "lcf_cfg_custom.h"

#ifdef PC_SIM
#ifdef LCF_SIL_MANIPULATE_INPUTS
#include "sim_swc_lcf_sen_manip.h"
#endif /*LCF_SIL_MANIPULATE_INPUTS*/
#endif /*PC_SIM*/

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

#define	LCFRCV_SenCustomReset()
#define	LCFRCV_SenCustomProcess()

/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/

/*---------------------------------------------------------*/
/* Override generic mapping*/
/*---------------------------------------------------------*/
/*MiCr add param def - as a fast solution to seting this params to const defines in LCFPRM_data.h*/
#ifndef P_VEH_OverhangFront_met
#define P_VEH_OverhangFront_met (pLcfSenReqPorts->pVehPar->VehParAdd.OverhangFront) /*!< LCF parameter macro.*/
#define GET_P_VEH_OverhangFront_met() (P_VEH_OverhangFront_met) /*!< LCF parameter macro getter.*/
#endif /*P_VEH_OverhangFront_met*/

#ifndef P_VEH_Wheelbase_met
#define P_VEH_Wheelbase_met (pLcfSenReqPorts->pVehPar->VehParMain.WheelBase) /*!< LCF parameter macro.*/
#define GET_P_VEH_Wheelbase_met() (P_VEH_Wheelbase_met) /*!< LCF parameter macro getter.*/
#endif /* P_VEH_Wheelbase_met*/

#ifndef P_VEH_Width_met
#define P_VEH_Width_met (pLcfSenReqPorts->pVehPar->VehParAdd.VehicleWidth) /*!< LCF parameter macro.*/
#define GET_P_VEH_Width_met() (P_VEH_Width_met) /*!< LCF parameter macro getter.*/
#endif /* P_VEH_Width_met */
/*end MiCr*/ 

#ifndef	S_CUSTOM_PrjSpecQu_btf
#define S_CUSTOM_PrjSpecQu_btf    	    S_JCNCTR_PrjSpecQu_btf // add MFC5J3 speical condtion bitfile
#define GET_S_CUSTOM_PrjSpecQu_btf()	S_CUSTOM_PrjSpecQu_btf
#endif
#ifndef	S_LCFRCV_ErrorStateLDW_bool
#define	S_LCFRCV_ErrorStateLDW_bool			((pLcfSenReqPorts->pLcfInputData->State_nu[49] == (uint8) LCF_IO_STATE_INVALID) || (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LDW]))
#define	GET_S_LCFRCV_ErrorStateLDW_bool()	S_LCFRCV_ErrorStateLDW_bool
#endif

#ifndef	S_LCFRCV_ErrorStateLDP_bool
#define	S_LCFRCV_ErrorStateLDP_bool			((pLcfSenReqPorts->pLcfInputData->State_nu[50] == (uint8) LCF_IO_STATE_INVALID) ||  (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LDP]))
#define	GET_S_LCFRCV_ErrorStateLDP_bool()	S_LCFRCV_ErrorStateLDP_bool
#endif

#ifndef	S_LCFRCV_ErrorStateTJA_bool
#define	S_LCFRCV_ErrorStateTJA_bool			((pLcfSenReqPorts->pLcfInputData->State_nu[51] == (uint8) LCF_IO_STATE_INVALID)  || (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_TJA_LC])|| (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_TJA_OF]))
#define	GET_S_LCFRCV_ErrorStateTJA_bool()	S_LCFRCV_ErrorStateTJA_bool
#endif

#ifndef	S_LCFRCV_ErrorStateALCA_bool
#define	S_LCFRCV_ErrorStateALCA_bool			((pLcfSenReqPorts->pLcfInputData->State_nu[52] == (uint8) LCF_IO_STATE_INVALID) || (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_ALCA]))
#define	GET_S_LCFRCV_ErrorStateALCA_bool()	S_LCFRCV_ErrorStateALCA_bool
#endif

#ifndef	S_LCFRCV_ErrorStateRDP_bool
#define	S_LCFRCV_ErrorStateRDP_bool			((pLcfSenReqPorts->pLcfInputData->State_nu[54] == (uint8) LCF_IO_STATE_INVALID) || (ERRIOSEN_ErrStateArray[LCF_ERRHNDL_RDP]))
#define	GET_S_LCFRCV_ErrorStateRDP_bool()	S_LCFRCV_ErrorStateRDP_bool
#endif
/*MiCr - add mapping to LD signals */
#ifndef S_LCFRCV_ABDSineWaveDtct_nu 
#define S_LCFRCV_ABDSineWaveDtct_nu             (pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[8].sGeometry.sParameters.sClothoidVertical.fCurvature)
#define GET_S_LCFRCV_ABDSineWaveDtct_nu()        S_LCFRCV_ABDSineWaveDtct_nu
#endif

#ifndef S_LCFRCV_ABDVertSlopeChange_nu
#define S_LCFRCV_ABDVertSlopeChange_nu          (pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[6].sGeometry.sParameters.sClothoidVertical.fCurvatureStd) 
#define GET_S_LCFRCV_ABDVertSlopeChange_nu()     S_LCFRCV_ABDVertSlopeChange_nu
#endif

#ifndef S_LCFRCV_HandsOffConfirmedExt_bool
#define S_LCFRCV_HandsOffConfirmedExt_bool      (pLcfSenReqPorts->pLcfInputData->DriverHandsOff_nu)
#define GET_S_LCFRCV_HandsOffConfirmedExt_bool()   S_LCFRCV_HandsOffConfirmedExt_bool
#endif /* S_LCFRCV_HandsOffConfirmedExt_bool */

#ifndef	S_LCFRCV_MainCylPressure_pa
#define S_LCFRCV_MainCylPressure_pa			((uint32)(pLcfSenReqPorts->pLcfInputData->MainCylPressure_pa))
#define GET_S_LCFRCV_MainCylPressure_pa()  S_LCFRCV_MainCylPressure_pa	
#endif
// # date: <2023-06-28>, author: <Jie, Tang>, reason: <C673 new requirement: brake pedal distance check>
#ifndef S_LCFRCV_BrakePedalPostion_mm
#define S_LCFRCV_BrakePedalPostion_mm (0)
#define GET_S_LCFRCV_BrakePedalPostion_mm() S_LCFRCV_BrakePedalPostion_mm
#endif

#ifndef	S_LCFRCV_SysStateIACC_nu
#define S_LCFRCV_SysStateIACC_nu			(pLcfSenReqPorts->pLcfInputData->IACCHWAMode_nu)
#define GET_S_LCFRCV_SysStateIACC_nu()  S_LCFRCV_SysStateIACC_nu	
#endif

#endif /* LCFRCVSEN_CUSTOM_H_ */

