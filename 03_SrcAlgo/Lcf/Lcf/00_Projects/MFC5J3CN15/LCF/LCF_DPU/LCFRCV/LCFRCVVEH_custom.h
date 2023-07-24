/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFRCVVEH_custom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.4 $


  ---*/ /*--- 
  CHANGES:                   

**************************************************************************** */

#ifndef LCFRCVVEH_CUSTOM_H_
#define LCFRCVVEH_CUSTOM_H_

#include "lcf_cfg_custom.h"

#ifdef PC_SIM
#ifdef LCF_SIL_MANIPULATE_INPUTS
#include "sim_swc_lcf_veh_manip.h"
#endif //LCF_SIL_MANIPULATE_INPUTS
#endif //PC_SIM


#define LCF_MIRROR_OFFSET_MET    (0.25f)
/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

extern void LCFRCV_VehCustomReset(void);
extern void LCFRCV_VehCustomProcess(void);

/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/

/*---------------------------------------------------------*/
/* Override generic mapping*/
/*---------------------------------------------------------*/

#ifndef S_LCFRCV_ActualStWheelAngle_deg
#define S_LCFRCV_ActualStWheelAngle_deg         ((pLcfVehReqPorts->pVehSig->VehSigMain.StWheelAngle)*CONV_RAD2DEG)   // VCAN:SSA+SSAS, for LatDMC, EPS SWA Offset Compensation -> S_UNCALIBRATED_SWA_FIL
#define GET_S_LCFRCV_ActualStWheelAngle_deg()    S_LCFRCV_ActualStWheelAngle_deg
#endif

/*ElNa add param def - as a fast solution to seting this params to const defines in LCFPRM_data.h*/
#ifndef P_VEH_Length_met
#define P_VEH_Length_met (pLcfVehReqPorts->pVehPar->VehParAdd.VehicleLength)
#define GET_P_VEH_Length_met() (P_VEH_Length_met)
#endif /*P_VEH_Length_met*/

#ifndef P_VEH_WidthWithMirrors_met
#define P_VEH_WidthWithMirrors_met (pLcfVehReqPorts->pVehPar->VehParAdd.VehicleWidth + LCF_MIRROR_OFFSET_MET)
#define GET_P_VEH_WidthWithMirrors_met() (P_VEH_WidthWithMirrors_met)
#endif /*P_VEH_WidthWithMirrors_met*/

//DRVMN
#ifndef S_LCFRCV_HandsOffConfirmedExt_bool
#define S_LCFRCV_HandsOffConfirmedExt_bool   (pLcfVehReqPorts->pLcfInputData->DriverHandsOff_nu)
#define GET_S_LCFRCV_HandsOffConfirmedExt_bool()   S_LCFRCV_HandsOffConfirmedExt_bool
#endif /* S_LCFRCV_HandsOffConfirmedExt_bool */

#endif /* _LCFRCVVEH_CUSTOM_H_ */


