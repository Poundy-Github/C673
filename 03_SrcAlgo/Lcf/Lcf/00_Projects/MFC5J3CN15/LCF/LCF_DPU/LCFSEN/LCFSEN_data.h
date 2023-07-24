/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3CN15
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Sensor
  SUB-COMPONENTS : v1ABPR,v2ODPR,VDPR,MFJSCT,LDPSA,RDPSA,ALCASA,v1TJASA,MDCTR,CTRSC,HMIOC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFSEN_data.h
//! @brief    Lateral Control Functions - Sensor (LCFSEN) Task Data Header.

#ifndef LCFSEN_DATA_H_
#define LCFSEN_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPR/v1ABPRSEN_data.h"
#include "ODPR/v2ODPRSEN_data.h"
#include "VDPR/VDPRSEN_data.h"
#include "MFJSCT/MFJSCTSEN_data.h"
#include "LDPSA/LDPSASEN_data.h"
#include "RDPSA/RDPSASEN_data.h"
#include "ALCASA/ALCASASEN_data.h"
#include "TJASA/v1TJASASEN_data.h"
#include "MDCTR/MDCTRSEN_data.h"
#include "CTRSC/CTRSCSEN_data.h"
#include "HMIOC/HMIOCSEN_data.h"
#include "LCFRCV/LCFRCVSEN.h"
#include "LCFSND/LCFSNDSEN.h"
#include "LCFPRM/LCFPRM_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   S T U B B E D   I N P U T   M A C R O S
**-----------------------------------------------------*/
//ElNa, mising add defines used in wrapers(LCFSND_SenFillRTEOutputData) that were not defined in data.h
#ifndef S_DPRSMW_SysStateRDWRi_nu
#define S_DPRSMW_SysStateRDWRi_nu (0u)
#define GET_S_DPRSMW_SysStateRDWRi_nu() S_DPRSMW_SysStateRDWRi_nu
#endif 

#ifndef S_DPRSMW_SysStateRDWLe_nu 
#define S_DPRSMW_SysStateRDWLe_nu  (0u)
#define GET_S_DPRSMW_SysStateRDWLe_nu() S_DPRSMW_SysStateRDWLe_nu 
#endif 

#ifndef S_DPRSMW_SysStateRDW_nu
#define S_DPRSMW_SysStateRDW_nu (0u)
#define GET_S_DPRSMW_SysStateRDW_nu() S_DPRSMW_SysStateRDW_nu
#endif 

#ifndef S_DPOSTM_SysStateLDPOCRi_nu
#define S_DPOSTM_SysStateLDPOCRi_nu (0u)
#define GET_S_DPOSTM_SysStateLDPOCRi_nu() S_DPOSTM_SysStateLDPOCRi_nu
#endif 

#ifndef S_DPOSTM_SysStateLDPOCLe_nu
#define S_DPOSTM_SysStateLDPOCLe_nu (0u)
#define GET_S_DPOSTM_SysStateLDPOCLe_nu() S_DPOSTM_SysStateLDPOCLe_nu
#endif 

#ifndef S_DPOSTM_OcObjActSide_nu
#define S_DPOSTM_OcObjActSide_nu (0u)
#define GET_S_DPOSTM_OcObjActSide_nu() S_DPOSTM_OcObjActSide_nu
#endif

#ifndef D_DPOSTM_Cancel_btf
#define D_DPOSTM_Cancel_btf (0) //!< LCFSEN stubbed input macro.
#define GET_D_DPOSTM_Cancel_btf() D_DPOSTM_Cancel_btf //!< LCFSEN stubbed input macro getter.
#endif // D_DPOSTM_Cancel_btf

#ifndef D_DPOSTM_StrongReady_btf
#define D_DPOSTM_StrongReady_btf (0) //!< LCFSEN stubbed input macro.
#define GET_D_DPOSTM_StrongReady_btf() D_DPOSTM_StrongReady_btf //!< LCFSEN stubbed input macro getter.
#endif // D_DPOSTM_StrongReady_btf

#ifndef D_DPOSTM_WeakReady_btf
#define D_DPOSTM_WeakReady_btf (0) //!< LCFSEN stubbed input macro.
#define GET_D_DPOSTM_WeakReady_btf() D_DPOSTM_WeakReady_btf //!< LCFSEN stubbed input macro getter.
#endif // D_DPOSTM_WeakReady_btf

#ifndef S_DPOSIA_LnBndValidLDPOC_nu
#define S_DPOSIA_LnBndValidLDPOC_nu (0) //!< LCFSEN stubbed input macro.
#define GET_S_DPOSIA_LnBndValidLDPOC_nu() S_DPOSIA_LnBndValidLDPOC_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOSIA_LnBndValidLDPOC_nu

//END ElNa, mising add defines used in wrapers(LCFSND_SenFillRTEOutputData) that were not defined in data.h
/*MiCr add missing defines used in common wrappers*/

#ifndef S_LCRSMI_SysStateALCARi_nu
#define S_LCRSMI_SysStateALCARi_nu        (0u)   
#define GET_S_LCRSMI_SysStateALCARi_nu() (S_LCRSMI_SysStateALCARi_nu) 
#endif 

#ifndef S_LCRSMI_SysStateALCALe_nu
#define S_LCRSMI_SysStateALCALe_nu   (0u)
#define GET_S_LCRSMI_SysStateALCALe_nu() (S_LCRSMI_SysStateALCALe_nu) 
#endif 

#ifndef S_LCRSIA_LnBndValidALCA_nu
#define S_LCRSIA_LnBndValidALCA_nu (0u) 
#define GET_S_LCRSIA_LnBndValidALCA_nu() (S_LCRSIA_LnBndValidALCA_nu) 
#endif 

#ifndef S_LCRSMI_DangerousSide_nu
#define S_LCRSMI_DangerousSide_nu (0) 
#define GET_S_LCRSMI_DangerousSide_nu() (S_LCRSMI_DangerousSide_nu)
#endif 

#ifndef D_DPRSIA_RdBndLeCancelValid_bool
#define D_DPRSIA_RdBndLeCancelValid_bool (0) //!< LCFSEN stubbed input macro.
#define GET_D_DPRSIA_RdBndLeCancelValid_bool() D_DPRSIA_RdBndLeCancelValid_bool //!< LCFSEN stubbed input macro getter.
#endif // D_DPRSIA_RdBndLeCancelValid_bool

#ifndef D_DPRSIA_RdBndRiCancelValid_bool
#define D_DPRSIA_RdBndRiCancelValid_bool (0) //!< LCFSEN stubbed input macro.
#define GET_D_DPRSIA_RdBndRiCancelValid_bool() D_DPRSIA_RdBndRiCancelValid_bool //!< LCFSEN stubbed input macro getter.
#endif // D_DPRSIA_RdBndRiCancelValid_bool

#ifndef D_LCRSMI_StrongReady_btf
#define D_LCRSMI_StrongReady_btf (0) //!< LCFSEN stubbed input macro.
#define GET_D_LCRSMI_StrongReady_btf() D_LCRSMI_StrongReady_btf //!< LCFSEN stubbed input macro getter.
#endif // D_LCRSMI_StrongReady_btf

#ifndef D_LCRSMI_WeakReady_btf
#define D_LCRSMI_WeakReady_btf (0) //!< LCFSEN stubbed input macro.
#define GET_D_LCRSMI_WeakReady_btf() D_LCRSMI_WeakReady_btf //!< LCFSEN stubbed input macro getter.
#endif // D_LCRSMI_WeakReady_btf
/*End MiCr add missing defines used in common wrappers*/

#ifndef S_ABPALP_LeAdjLnClthCrvChng_1pm2
#define S_ABPALP_LeAdjLnClthCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_LeAdjLnClthCrvChng_1pm2() S_ABPALP_LeAdjLnClthCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_LeAdjLnClthCrvChng_1pm2

#ifndef S_ABPALP_LeAdjLnClthCrv_1pm
#define S_ABPALP_LeAdjLnClthCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_LeAdjLnClthCrv_1pm() S_ABPALP_LeAdjLnClthCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_LeAdjLnClthCrv_1pm

#ifndef S_ABPALP_LeAdjLnClthHeading_rad
#define S_ABPALP_LeAdjLnClthHeading_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_LeAdjLnClthHeading_rad() S_ABPALP_LeAdjLnClthHeading_rad //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_LeAdjLnClthHeading_rad

#ifndef S_ABPALP_LeAdjLnClthLength_met
#define S_ABPALP_LeAdjLnClthLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_LeAdjLnClthLength_met() S_ABPALP_LeAdjLnClthLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_LeAdjLnClthLength_met

#ifndef S_ABPALP_LeAdjLnClthPosX0_met
#define S_ABPALP_LeAdjLnClthPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_LeAdjLnClthPosX0_met() S_ABPALP_LeAdjLnClthPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_LeAdjLnClthPosX0_met

#ifndef S_ABPALP_LeAdjLnClthPosY0_met
#define S_ABPALP_LeAdjLnClthPosY0_met (15.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_LeAdjLnClthPosY0_met() S_ABPALP_LeAdjLnClthPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_LeAdjLnClthPosY0_met

#ifndef S_ABPALP_RiAdjLnClthCrvChng_1pm2
#define S_ABPALP_RiAdjLnClthCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_RiAdjLnClthCrvChng_1pm2() S_ABPALP_RiAdjLnClthCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_RiAdjLnClthCrvChng_1pm2

#ifndef S_ABPALP_RiAdjLnClthCrv_1pm
#define S_ABPALP_RiAdjLnClthCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_RiAdjLnClthCrv_1pm() S_ABPALP_RiAdjLnClthCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_RiAdjLnClthCrv_1pm

#ifndef S_ABPALP_RiAdjLnClthHeading_rad
#define S_ABPALP_RiAdjLnClthHeading_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_RiAdjLnClthHeading_rad() S_ABPALP_RiAdjLnClthHeading_rad //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_RiAdjLnClthHeading_rad

#ifndef S_ABPALP_RiAdjLnClthLength_met
#define S_ABPALP_RiAdjLnClthLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_RiAdjLnClthLength_met() S_ABPALP_RiAdjLnClthLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_RiAdjLnClthLength_met

#ifndef S_ABPALP_RiAdjLnClthPosX0_met
#define S_ABPALP_RiAdjLnClthPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_RiAdjLnClthPosX0_met() S_ABPALP_RiAdjLnClthPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_RiAdjLnClthPosX0_met

#ifndef S_ABPALP_RiAdjLnClthPosY0_met
#define S_ABPALP_RiAdjLnClthPosY0_met (-15.f) //!< LCFSEN stubbed input macro.
#define GET_S_ABPALP_RiAdjLnClthPosY0_met() S_ABPALP_RiAdjLnClthPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_ABPALP_RiAdjLnClthPosY0_met

#ifndef S_CUSTOM_ALCADlcLimitLe_met
#define S_CUSTOM_ALCADlcLimitLe_met (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_ALCADlcLimitLe_met() S_CUSTOM_ALCADlcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_ALCADlcLimitLe_met

#ifndef S_CUSTOM_ALCADlcLimitRi_met
#define S_CUSTOM_ALCADlcLimitRi_met (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_ALCADlcLimitRi_met() S_CUSTOM_ALCADlcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_ALCADlcLimitRi_met

#ifndef S_CUSTOM_ALCADlcTrgLe_met
#define S_CUSTOM_ALCADlcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_ALCADlcTrgLe_met() S_CUSTOM_ALCADlcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_ALCADlcTrgLe_met

#ifndef S_CUSTOM_ALCADlcTrgRi_met
#define S_CUSTOM_ALCADlcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_ALCADlcTrgRi_met() S_CUSTOM_ALCADlcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_ALCADlcTrgRi_met

#ifndef S_CUSTOM_LDPDlcLimitLe_met
#define S_CUSTOM_LDPDlcLimitLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDPDlcLimitLe_met() S_CUSTOM_LDPDlcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDPDlcLimitLe_met

#ifndef S_CUSTOM_LDPDlcLimitRi_met
#define S_CUSTOM_LDPDlcLimitRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDPDlcLimitRi_met() S_CUSTOM_LDPDlcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDPDlcLimitRi_met

#ifndef S_CUSTOM_LDPDlcTrgLe_met
#define S_CUSTOM_LDPDlcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDPDlcTrgLe_met() S_CUSTOM_LDPDlcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDPDlcTrgLe_met

#ifndef S_CUSTOM_LDPDlcTrgRi_met
#define S_CUSTOM_LDPDlcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDPDlcTrgRi_met() S_CUSTOM_LDPDlcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDPDlcTrgRi_met

#ifndef S_CUSTOM_LDWDlcLimitLe_met
#define S_CUSTOM_LDWDlcLimitLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDWDlcLimitLe_met() S_CUSTOM_LDWDlcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDWDlcLimitLe_met

#ifndef S_CUSTOM_LDWDlcLimitRi_met
#define S_CUSTOM_LDWDlcLimitRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDWDlcLimitRi_met() S_CUSTOM_LDWDlcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDWDlcLimitRi_met

#ifndef S_CUSTOM_LDWDlcTrgLe_met
#define S_CUSTOM_LDWDlcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDWDlcTrgLe_met() S_CUSTOM_LDWDlcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDWDlcTrgLe_met

#ifndef S_CUSTOM_LDWDlcTrgRi_met
#define S_CUSTOM_LDWDlcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_LDWDlcTrgRi_met() S_CUSTOM_LDWDlcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_LDWDlcTrgRi_met

#ifndef S_CUSTOM_PrjSpecQu_btf
#define S_CUSTOM_PrjSpecQu_btf (0x0000u) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_PrjSpecQu_btf() S_CUSTOM_PrjSpecQu_btf //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_PrjSpecQu_btf

#ifndef S_CUSTOM_RDPDlcLimitLe_met
#define S_CUSTOM_RDPDlcLimitLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDlcLimitLe_met() S_CUSTOM_RDPDlcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDlcLimitLe_met

#ifndef S_CUSTOM_RDPDlcLimitRi_met
#define S_CUSTOM_RDPDlcLimitRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDlcLimitRi_met() S_CUSTOM_RDPDlcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDlcLimitRi_met

#ifndef S_CUSTOM_RDPDlcTrgLe_met
#define S_CUSTOM_RDPDlcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDlcTrgLe_met() S_CUSTOM_RDPDlcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDlcTrgLe_met

#ifndef S_CUSTOM_RDPDlcTrgRi_met
#define S_CUSTOM_RDPDlcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDlcTrgRi_met() S_CUSTOM_RDPDlcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDlcTrgRi_met

#ifndef S_CUSTOM_RDPDrcLimitLe_met
#define S_CUSTOM_RDPDrcLimitLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDrcLimitLe_met() S_CUSTOM_RDPDrcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDrcLimitLe_met

#ifndef S_CUSTOM_RDPDrcLimitRi_met
#define S_CUSTOM_RDPDrcLimitRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDrcLimitRi_met() S_CUSTOM_RDPDrcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDrcLimitRi_met

#ifndef S_CUSTOM_RDPDrcTrgLe_met
#define S_CUSTOM_RDPDrcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDrcTrgLe_met() S_CUSTOM_RDPDrcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDrcTrgLe_met

#ifndef S_CUSTOM_RDPDrcTrgRi_met
#define S_CUSTOM_RDPDrcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDPDrcTrgRi_met() S_CUSTOM_RDPDrcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDPDrcTrgRi_met

#ifndef S_CUSTOM_RDWDlcLimitLe_met
#define S_CUSTOM_RDWDlcLimitLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDlcLimitLe_met() S_CUSTOM_RDWDlcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDlcLimitLe_met

#ifndef S_CUSTOM_RDWDlcLimitRi_met
#define S_CUSTOM_RDWDlcLimitRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDlcLimitRi_met() S_CUSTOM_RDWDlcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDlcLimitRi_met

#ifndef S_CUSTOM_RDWDlcTrgLe_met
#define S_CUSTOM_RDWDlcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDlcTrgLe_met() S_CUSTOM_RDWDlcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDlcTrgLe_met

#ifndef S_CUSTOM_RDWDlcTrgRi_met
#define S_CUSTOM_RDWDlcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDlcTrgRi_met() S_CUSTOM_RDWDlcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDlcTrgRi_met

#ifndef S_CUSTOM_RDWDrcLimitLe_met
#define S_CUSTOM_RDWDrcLimitLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDrcLimitLe_met() S_CUSTOM_RDWDrcLimitLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDrcLimitLe_met

#ifndef S_CUSTOM_RDWDrcLimitRi_met
#define S_CUSTOM_RDWDrcLimitRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDrcLimitRi_met() S_CUSTOM_RDWDrcLimitRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDrcLimitRi_met

#ifndef S_CUSTOM_RDWDrcTrgLe_met
#define S_CUSTOM_RDWDrcTrgLe_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDrcTrgLe_met() S_CUSTOM_RDWDrcTrgLe_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDrcTrgLe_met

#ifndef S_CUSTOM_RDWDrcTrgRi_met
#define S_CUSTOM_RDWDrcTrgRi_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_CUSTOM_RDWDrcTrgRi_met() S_CUSTOM_RDWDrcTrgRi_met //!< LCFSEN stubbed input macro getter.
#endif // S_CUSTOM_RDWDrcTrgRi_met

#ifndef S_DPOSTM_SysStateLDPOC_nu
#define S_DPOSTM_SysStateLDPOC_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOSTM_SysStateLDPOC_nu() S_DPOSTM_SysStateLDPOC_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOSTM_SysStateLDPOC_nu

#ifndef S_DPOTTG_LeCridrBndCrvChng_1pm2
#define S_DPOTTG_LeCridrBndCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_LeCridrBndCrvChng_1pm2() S_DPOTTG_LeCridrBndCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_LeCridrBndCrvChng_1pm2

#ifndef S_DPOTTG_LeCridrBndCrv_1pm
#define S_DPOTTG_LeCridrBndCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_LeCridrBndCrv_1pm() S_DPOTTG_LeCridrBndCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_LeCridrBndCrv_1pm

#ifndef S_DPOTTG_LeCridrBndHeadAng_rad
#define S_DPOTTG_LeCridrBndHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_LeCridrBndHeadAng_rad() S_DPOTTG_LeCridrBndHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_LeCridrBndHeadAng_rad

#ifndef S_DPOTTG_LeCridrBndLength_met
#define S_DPOTTG_LeCridrBndLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_LeCridrBndLength_met() S_DPOTTG_LeCridrBndLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_LeCridrBndLength_met

#ifndef S_DPOTTG_LeCridrBndPosX0_met
#define S_DPOTTG_LeCridrBndPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_LeCridrBndPosX0_met() S_DPOTTG_LeCridrBndPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_LeCridrBndPosX0_met

#ifndef S_DPOTTG_LeCridrBndPosY0_met
#define S_DPOTTG_LeCridrBndPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_LeCridrBndPosY0_met() S_DPOTTG_LeCridrBndPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_LeCridrBndPosY0_met

#ifndef S_DPOTTG_RiCridrBndCrvChng_1pm2
#define S_DPOTTG_RiCridrBndCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_RiCridrBndCrvChng_1pm2() S_DPOTTG_RiCridrBndCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_RiCridrBndCrvChng_1pm2

#ifndef S_DPOTTG_RiCridrBndCrv_1pm
#define S_DPOTTG_RiCridrBndCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_RiCridrBndCrv_1pm() S_DPOTTG_RiCridrBndCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_RiCridrBndCrv_1pm

#ifndef S_DPOTTG_RiCridrBndHeadAng_rad
#define S_DPOTTG_RiCridrBndHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_RiCridrBndHeadAng_rad() S_DPOTTG_RiCridrBndHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_RiCridrBndHeadAng_rad

#ifndef S_DPOTTG_RiCridrBndLength_met
#define S_DPOTTG_RiCridrBndLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_RiCridrBndLength_met() S_DPOTTG_RiCridrBndLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_RiCridrBndLength_met

#ifndef S_DPOTTG_RiCridrBndPosX0_met
#define S_DPOTTG_RiCridrBndPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_RiCridrBndPosX0_met() S_DPOTTG_RiCridrBndPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_RiCridrBndPosX0_met

#ifndef S_DPOTTG_RiCridrBndPosY0_met
#define S_DPOTTG_RiCridrBndPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_RiCridrBndPosY0_met() S_DPOTTG_RiCridrBndPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_RiCridrBndPosY0_met

#ifndef S_DPOTTG_TgtTrajCrvChng_1pm2
#define S_DPOTTG_TgtTrajCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_TgtTrajCrvChng_1pm2() S_DPOTTG_TgtTrajCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_TgtTrajCrvChng_1pm2

#ifndef S_DPOTTG_TgtTrajCrv_1pm
#define S_DPOTTG_TgtTrajCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_TgtTrajCrv_1pm() S_DPOTTG_TgtTrajCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_TgtTrajCrv_1pm

#ifndef S_DPOTTG_TgtTrajHeadAng_rad
#define S_DPOTTG_TgtTrajHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_TgtTrajHeadAng_rad() S_DPOTTG_TgtTrajHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_TgtTrajHeadAng_rad

#ifndef S_DPOTTG_TgtTrajLength_met
#define S_DPOTTG_TgtTrajLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_TgtTrajLength_met() S_DPOTTG_TgtTrajLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_TgtTrajLength_met

#ifndef S_DPOTTG_TgtTrajPosX0_met
#define S_DPOTTG_TgtTrajPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_TgtTrajPosX0_met() S_DPOTTG_TgtTrajPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_TgtTrajPosX0_met

#ifndef S_DPOTTG_TgtTrajPosY0_met
#define S_DPOTTG_TgtTrajPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTTG_TgtTrajPosY0_met() S_DPOTTG_TgtTrajPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTTG_TgtTrajPosY0_met

#ifndef S_DPOTVG_DeratingLevel_nu
#define S_DPOTVG_DeratingLevel_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_DeratingLevel_nu() S_DPOTVG_DeratingLevel_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_DeratingLevel_nu

#ifndef S_DPOTVG_DistYTolLeTgtArea_met
#define S_DPOTVG_DistYTolLeTgtArea_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_DistYTolLeTgtArea_met() S_DPOTVG_DistYTolLeTgtArea_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_DistYTolLeTgtArea_met

#ifndef S_DPOTVG_DistYTolRiTgtArea_met
#define S_DPOTVG_DistYTolRiTgtArea_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_DistYTolRiTgtArea_met() S_DPOTVG_DistYTolRiTgtArea_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_DistYTolRiTgtArea_met

#ifndef S_DPOTVG_FTireAclMax_mps2
#define S_DPOTVG_FTireAclMax_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_FTireAclMax_mps2() S_DPOTVG_FTireAclMax_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_FTireAclMax_mps2

#ifndef S_DPOTVG_FTireAclMin_mps2
#define S_DPOTVG_FTireAclMin_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_FTireAclMin_mps2() S_DPOTVG_FTireAclMin_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_FTireAclMin_mps2

#ifndef S_DPOTVG_GrdLimitTgtCrvTGC_1pms
#define S_DPOTVG_GrdLimitTgtCrvTGC_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_GrdLimitTgtCrvTGC_1pms() S_DPOTVG_GrdLimitTgtCrvTGC_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_DPOTVG_HighStatAccu_bool
#define S_DPOTVG_HighStatAccu_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_HighStatAccu_bool() S_DPOTVG_HighStatAccu_bool //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_HighStatAccu_bool

#ifndef S_DPOTVG_LimiterActivated_bool
#define S_DPOTVG_LimiterActivated_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_LimiterActivated_bool() S_DPOTVG_LimiterActivated_bool //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_LimiterActivated_bool

#ifndef S_DPOTVG_LimiterTimeDuration_sec
#define S_DPOTVG_LimiterTimeDuration_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_LimiterTimeDuration_sec() S_DPOTVG_LimiterTimeDuration_sec //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_LimiterTimeDuration_sec

#ifndef S_DPOTVG_LtcyCompActivated_bool
#define S_DPOTVG_LtcyCompActivated_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_LtcyCompActivated_bool() S_DPOTVG_LtcyCompActivated_bool //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_LtcyCompActivated_bool

#ifndef S_DPOTVG_MaxCrvGrdBuildup_1pms
#define S_DPOTVG_MaxCrvGrdBuildup_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_MaxCrvGrdBuildup_1pms() S_DPOTVG_MaxCrvGrdBuildup_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_MaxCrvGrdBuildup_1pms

#ifndef S_DPOTVG_MaxCrvGrdRed_1pms
#define S_DPOTVG_MaxCrvGrdRed_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_MaxCrvGrdRed_1pms() S_DPOTVG_MaxCrvGrdRed_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_MaxCrvGrdRed_1pms

#ifndef S_DPOTVG_MaxCrvTrajGuiCtrl_1pm
#define S_DPOTVG_MaxCrvTrajGuiCtrl_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_MaxCrvTrajGuiCtrl_1pm() S_DPOTVG_MaxCrvTrajGuiCtrl_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_DPOTVG_MaxJerkAllowed_mps3
#define S_DPOTVG_MaxJerkAllowed_mps3 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_MaxJerkAllowed_mps3() S_DPOTVG_MaxJerkAllowed_mps3 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_MaxJerkAllowed_mps3

#ifndef S_DPOTVG_MaxTrqScalGrad_1ps
#define S_DPOTVG_MaxTrqScalGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_MaxTrqScalGrad_1ps() S_DPOTVG_MaxTrqScalGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_MaxTrqScalGrad_1ps

#ifndef S_DPOTVG_MaxTrqScalLimit_nu
#define S_DPOTVG_MaxTrqScalLimit_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_MaxTrqScalLimit_nu() S_DPOTVG_MaxTrqScalLimit_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_MaxTrqScalLimit_nu

#ifndef S_DPOTVG_ObstacleAclX_mps2
#define S_DPOTVG_ObstacleAclX_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_ObstacleAclX_mps2() S_DPOTVG_ObstacleAclX_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_ObstacleAclX_mps2

#ifndef S_DPOTVG_ObstacleDistX_met
#define S_DPOTVG_ObstacleDistX_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_ObstacleDistX_met() S_DPOTVG_ObstacleDistX_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_ObstacleDistX_met

#ifndef S_DPOTVG_ObstacleDistY_met
#define S_DPOTVG_ObstacleDistY_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_ObstacleDistY_met() S_DPOTVG_ObstacleDistY_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_ObstacleDistY_met

#ifndef S_DPOTVG_ObstacleVelX_mps
#define S_DPOTVG_ObstacleVelX_mps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_ObstacleVelX_mps() S_DPOTVG_ObstacleVelX_mps //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_ObstacleVelX_mps

#ifndef S_DPOTVG_ObstacleWidth_met
#define S_DPOTVG_ObstacleWidth_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_ObstacleWidth_met() S_DPOTVG_ObstacleWidth_met //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_ObstacleWidth_met

#ifndef S_DPOTVG_PlanningHorizon_sec
#define S_DPOTVG_PlanningHorizon_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_PlanningHorizon_sec() S_DPOTVG_PlanningHorizon_sec //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_PlanningHorizon_sec

#ifndef S_DPOTVG_PredTimeCrv_sec
#define S_DPOTVG_PredTimeCrv_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_PredTimeCrv_sec() S_DPOTVG_PredTimeCrv_sec //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_PredTimeCrv_sec

#ifndef S_DPOTVG_PredTimeHeadAng_sec
#define S_DPOTVG_PredTimeHeadAng_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_PredTimeHeadAng_sec() S_DPOTVG_PredTimeHeadAng_sec //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_PredTimeHeadAng_sec

#ifndef S_DPOTVG_SensorTStamp_sec
#define S_DPOTVG_SensorTStamp_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_SensorTStamp_sec() S_DPOTVG_SensorTStamp_sec //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_SensorTStamp_sec

#ifndef S_DPOTVG_StrWhStifGrad_1ps
#define S_DPOTVG_StrWhStifGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_StrWhStifGrad_1ps() S_DPOTVG_StrWhStifGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_StrWhStifGrad_1ps

#ifndef S_DPOTVG_StrWhStifLimit_nu
#define S_DPOTVG_StrWhStifLimit_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_StrWhStifLimit_nu() S_DPOTVG_StrWhStifLimit_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_StrWhStifLimit_nu

#ifndef S_DPOTVG_TrajGuiQu_nu
#define S_DPOTVG_TrajGuiQu_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_TrajGuiQu_nu() S_DPOTVG_TrajGuiQu_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_TrajGuiQu_nu

#ifndef S_DPOTVG_TrajPlanServQu_nu
#define S_DPOTVG_TrajPlanServQu_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_TrajPlanServQu_nu() S_DPOTVG_TrajPlanServQu_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_TrajPlanServQu_nu

#ifndef S_DPOTVG_TriggerReplan_bool
#define S_DPOTVG_TriggerReplan_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_TriggerReplan_bool() S_DPOTVG_TriggerReplan_bool //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_TriggerReplan_bool

#ifndef S_DPOTVG_TrqRampGrad_1ps
#define S_DPOTVG_TrqRampGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_TrqRampGrad_1ps() S_DPOTVG_TrqRampGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_TrqRampGrad_1ps

#ifndef S_DPOTVG_WeightEndTime_nu
#define S_DPOTVG_WeightEndTime_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_WeightEndTime_nu() S_DPOTVG_WeightEndTime_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_WeightEndTime_nu

#ifndef S_DPOTVG_WeightTgtDistY_nu
#define S_DPOTVG_WeightTgtDistY_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_DPOTVG_WeightTgtDistY_nu() S_DPOTVG_WeightTgtDistY_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DPOTVG_WeightTgtDistY_nu

#ifndef S_DRMDAE_SysWarning_nu
#define S_DRMDAE_SysWarning_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_DRMDAE_SysWarning_nu() S_DRMDAE_SysWarning_nu //!< LCFSEN stubbed input macro getter.
#endif // S_DRMDAE_SysWarning_nu

#ifndef S_ESASTM_SysStateESA_nu
#define S_ESASTM_SysStateESA_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ESASTM_SysStateESA_nu() S_ESASTM_SysStateESA_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ESASTM_SysStateESA_nu

#ifndef S_LCFRCV_ABDFusionConfLeft_nu
#define S_LCFRCV_ABDFusionConfLeft_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDFusionConfLeft_nu() S_LCFRCV_ABDFusionConfLeft_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDFusionConfLeft_nu

#ifndef S_LCFRCV_ABDFusionConfRight_nu
#define S_LCFRCV_ABDFusionConfRight_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDFusionConfRight_nu() S_LCFRCV_ABDFusionConfRight_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDFusionConfRight_nu

#ifndef S_LCFRCV_ABDOverpassDtct_bool
#define S_LCFRCV_ABDOverpassDtct_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDOverpassDtct_bool() S_LCFRCV_ABDOverpassDtct_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDOverpassDtct_bool

#ifndef S_LCFRCV_ABDSineWaveDtct_nu
#define S_LCFRCV_ABDSineWaveDtct_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDSineWaveDtct_nu() S_LCFRCV_ABDSineWaveDtct_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDSineWaveDtct_nu

#ifndef S_LCFRCV_ABDVertAvailable_nu
#define S_LCFRCV_ABDVertAvailable_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDVertAvailable_nu() S_LCFRCV_ABDVertAvailable_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDVertAvailable_nu

#ifndef S_LCFRCV_ABDVertCurvatureRt_1pm2
#define S_LCFRCV_ABDVertCurvatureRt_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDVertCurvatureRt_1pm2() S_LCFRCV_ABDVertCurvatureRt_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDVertCurvatureRt_1pm2

#ifndef S_LCFRCV_ABDVertCurvature_1pm
#define S_LCFRCV_ABDVertCurvature_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDVertCurvature_1pm() S_LCFRCV_ABDVertCurvature_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDVertCurvature_1pm

#ifndef S_LCFRCV_ABDVertSlopeChange_nu
#define S_LCFRCV_ABDVertSlopeChange_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDVertSlopeChange_nu() S_LCFRCV_ABDVertSlopeChange_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDVertSlopeChange_nu

#ifndef S_LCFRCV_ABDVertValidLength_met
#define S_LCFRCV_ABDVertValidLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ABDVertValidLength_met() S_LCFRCV_ABDVertValidLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ABDVertValidLength_met

#ifndef S_LCFRCV_ALCASwitch_bool
#define S_LCFRCV_ALCASwitch_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ALCASwitch_bool() S_LCFRCV_ALCASwitch_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ALCASwitch_bool

#ifndef S_LCFRCV_AccFRObjClassType_nu
#define S_LCFRCV_AccFRObjClassType_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjClassType_nu() S_LCFRCV_AccFRObjClassType_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjClassType_nu

#ifndef S_LCFRCV_AccFRObjDetected_bool
#define S_LCFRCV_AccFRObjDetected_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjDetected_bool() S_LCFRCV_AccFRObjDetected_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjDetected_bool

#ifndef S_LCFRCV_AccFRObjID_nu
#define S_LCFRCV_AccFRObjID_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjID_nu() S_LCFRCV_AccFRObjID_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjID_nu

#ifndef S_LCFRCV_AccFRObjMeasState_nu
#define S_LCFRCV_AccFRObjMeasState_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjMeasState_nu() S_LCFRCV_AccFRObjMeasState_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjMeasState_nu

#ifndef S_LCFRCV_AccFRObjPosXStdDev_met
#define S_LCFRCV_AccFRObjPosXStdDev_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjPosXStdDev_met() S_LCFRCV_AccFRObjPosXStdDev_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjPosXStdDev_met

#ifndef S_LCFRCV_AccFRObjPosX_met
#define S_LCFRCV_AccFRObjPosX_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjPosX_met() S_LCFRCV_AccFRObjPosX_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjPosX_met

#ifndef S_LCFRCV_AccFRObjPosYStdDev_met
#define S_LCFRCV_AccFRObjPosYStdDev_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjPosYStdDev_met() S_LCFRCV_AccFRObjPosYStdDev_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjPosYStdDev_met

#ifndef S_LCFRCV_AccFRObjPosY_met
#define S_LCFRCV_AccFRObjPosY_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjPosY_met() S_LCFRCV_AccFRObjPosY_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjPosY_met

#ifndef S_LCFRCV_AccFRObjQuality_perc
#define S_LCFRCV_AccFRObjQuality_perc (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjQuality_perc() S_LCFRCV_AccFRObjQuality_perc //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjQuality_perc

#ifndef S_LCFRCV_AccFRObjRelAclX_mps2
#define S_LCFRCV_AccFRObjRelAclX_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjRelAclX_mps2() S_LCFRCV_AccFRObjRelAclX_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjRelAclX_mps2

#ifndef S_LCFRCV_AccFRObjRelAclY_mps2
#define S_LCFRCV_AccFRObjRelAclY_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjRelAclY_mps2() S_LCFRCV_AccFRObjRelAclY_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjRelAclY_mps2

#ifndef S_LCFRCV_AccFRObjRelVelX_mps
#define S_LCFRCV_AccFRObjRelVelX_mps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjRelVelX_mps() S_LCFRCV_AccFRObjRelVelX_mps //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjRelVelX_mps

#ifndef S_LCFRCV_AccFRObjRelVelY_mps
#define S_LCFRCV_AccFRObjRelVelY_mps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjRelVelY_mps() S_LCFRCV_AccFRObjRelVelY_mps //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjRelVelY_mps

#ifndef S_LCFRCV_AccFRObjRelYawAng_rad
#define S_LCFRCV_AccFRObjRelYawAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjRelYawAng_rad() S_LCFRCV_AccFRObjRelYawAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjRelYawAng_rad

#ifndef S_LCFRCV_AccFRObjSensorSource_btf
#define S_LCFRCV_AccFRObjSensorSource_btf (0x0000u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjSensorSource_btf() S_LCFRCV_AccFRObjSensorSource_btf //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjSensorSource_btf

#ifndef S_LCFRCV_AccFRObjTStamp_usec
#define S_LCFRCV_AccFRObjTStamp_usec (0x00000000u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjTStamp_usec() S_LCFRCV_AccFRObjTStamp_usec //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjTStamp_usec

#ifndef S_LCFRCV_AccFRObjWidth_met
#define S_LCFRCV_AccFRObjWidth_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccFRObjWidth_met() S_LCFRCV_AccFRObjWidth_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccFRObjWidth_met

#ifndef S_LCFRCV_ALCASwitch_bool
#define S_LCFRCV_ALCASwitch_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ALCASwitch_bool() S_LCFRCV_ALCASwitch_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ALCASwitch_bool

#ifndef S_LCFRCV_AccelPedalPos_nu
#define S_LCFRCV_AccelPedalPos_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AccelPedalPos_nu() S_LCFRCV_AccelPedalPos_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AccelPedalPos_nu

#ifndef S_LCFRCV_ActiveStCtrlABS_bool
#define S_LCFRCV_ActiveStCtrlABS_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlABS_bool() S_LCFRCV_ActiveStCtrlABS_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlABS_bool

#ifndef S_LCFRCV_ActiveStCtrlACC_bool
#define S_LCFRCV_ActiveStCtrlACC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlACC_bool() S_LCFRCV_ActiveStCtrlACC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlACC_bool

#ifndef S_LCFRCV_ActiveStCtrlEBA_bool
#define S_LCFRCV_ActiveStCtrlEBA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlEBA_bool() S_LCFRCV_ActiveStCtrlEBA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlEBA_bool

#ifndef S_LCFRCV_ActiveStCtrlESC_bool
#define S_LCFRCV_ActiveStCtrlESC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlESC_bool() S_LCFRCV_ActiveStCtrlESC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlESC_bool

#ifndef S_LCFRCV_ActiveStCtrlTCS_bool
#define S_LCFRCV_ActiveStCtrlTCS_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlTCS_bool() S_LCFRCV_ActiveStCtrlTCS_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlTCS_bool

#ifndef S_LCFRCV_ActiveStCtrlTSA_bool
#define S_LCFRCV_ActiveStCtrlTSA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlTSA_bool() S_LCFRCV_ActiveStCtrlTSA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlTSA_bool

#ifndef S_LCFRCV_ActiveStCtrlVSM_bool
#define S_LCFRCV_ActiveStCtrlVSM_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ActiveStCtrlVSM_bool() S_LCFRCV_ActiveStCtrlVSM_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ActiveStCtrlVSM_bool

#ifndef S_LCFRCV_AnyBndRoadWorks_btf
#define S_LCFRCV_AnyBndRoadWorks_btf (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndRoadWorks_btf() S_LCFRCV_AnyBndRoadWorks_btf //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_AnyBndRoadWorks_btf

#ifndef S_LCFRCV_BSD_ActiveLeft_nu
#define S_LCFRCV_BSD_ActiveLeft_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_BSD_ActiveLeft_nu() S_LCFRCV_BSD_ActiveLeft_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_BSD_ActiveLeft_nu

#ifndef S_LCFRCV_BSD_ActiveRight_nu
#define S_LCFRCV_BSD_ActiveRight_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_BSD_ActiveRight_nu() S_LCFRCV_BSD_ActiveRight_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_BSD_ActiveRight_nu

#ifndef S_LCFRCV_BSD_WarningLeft_nu
#define S_LCFRCV_BSD_WarningLeft_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_BSD_WarningLeft_nu() S_LCFRCV_BSD_WarningLeft_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_BSD_WarningLeft_nu

#ifndef S_LCFRCV_BSD_WarningRight_nu
#define S_LCFRCV_BSD_WarningRight_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_BSD_WarningRight_nu() S_LCFRCV_BSD_WarningRight_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_BSD_WarningRight_nu

#ifndef S_LCFRCV_BrightnessState_nu
#define S_LCFRCV_BrightnessState_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_BrightnessState_nu() S_LCFRCV_BrightnessState_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_BrightnessState_nu

#ifndef S_LCFRCV_CBWeatherCond_enum
#define S_LCFRCV_CBWeatherCond_enum (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_CBWeatherCond_enum() S_LCFRCV_CBWeatherCond_enum //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_CBWeatherCond_enum

#ifndef S_LCFRCV_CurrentGearNeutral_bool
#define S_LCFRCV_CurrentGearNeutral_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_CurrentGearNeutral_bool() S_LCFRCV_CurrentGearNeutral_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_CurrentGearNeutral_bool

#ifndef S_LCFRCV_CurrentGearParking_bool
#define S_LCFRCV_CurrentGearParking_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_CurrentGearParking_bool() S_LCFRCV_CurrentGearParking_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_CurrentGearParking_bool

#ifndef S_LCFRCV_CurrentGearReverse_bool
#define S_LCFRCV_CurrentGearReverse_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_CurrentGearReverse_bool() S_LCFRCV_CurrentGearReverse_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_CurrentGearReverse_bool

#ifndef S_LCFRCV_DoorOpen_bool
#define S_LCFRCV_DoorOpen_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_DoorOpen_bool() S_LCFRCV_DoorOpen_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_DoorOpen_bool

#ifndef S_LCFRCV_DriverNotBuckledUp_bool
#define S_LCFRCV_DriverNotBuckledUp_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_DriverNotBuckledUp_bool() S_LCFRCV_DriverNotBuckledUp_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_DriverNotBuckledUp_bool

#ifndef S_LCFRCV_DrivingMode_nu
#define S_LCFRCV_DrivingMode_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_DrivingMode_nu() S_LCFRCV_DrivingMode_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_DrivingMode_nu

#ifndef S_LCFRCV_EPS_ManualTrqActualVal_Nm
#define S_LCFRCV_EPS_ManualTrqActualVal_Nm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm() S_LCFRCV_EPS_ManualTrqActualVal_Nm //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_EPS_ManualTrqActualVal_Nm

#ifndef S_LCFRCV_ErrorStateALCA_bool
#define S_LCFRCV_ErrorStateALCA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateALCA_bool() S_LCFRCV_ErrorStateALCA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateALCA_bool

#ifndef S_LCFRCV_ErrorStateLDP_bool
#define S_LCFRCV_ErrorStateLDP_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateLDP_bool() S_LCFRCV_ErrorStateLDP_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateLDP_bool

#ifndef S_LCFRCV_ErrorStateLDW_bool
#define S_LCFRCV_ErrorStateLDW_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateLDW_bool() S_LCFRCV_ErrorStateLDW_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateLDW_bool

#ifndef S_LCFRCV_ErrorStateLKA_bool
#define S_LCFRCV_ErrorStateLKA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateLKA_bool() S_LCFRCV_ErrorStateLKA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateLKA_bool

#ifndef S_LCFRCV_ErrorStateRDP_bool
#define S_LCFRCV_ErrorStateRDP_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateRDP_bool() S_LCFRCV_ErrorStateRDP_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateRDP_bool

#ifndef S_LCFRCV_ErrorStateRDW_bool
#define S_LCFRCV_ErrorStateRDW_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateRDW_bool() S_LCFRCV_ErrorStateRDW_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateRDW_bool

#ifndef S_LCFRCV_ErrorStateTJA_bool
#define S_LCFRCV_ErrorStateTJA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateTJA_bool() S_LCFRCV_ErrorStateTJA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateTJA_bool

#ifndef S_LCFRCV_LCA_ActiveLeft_nu
#define S_LCFRCV_LCA_ActiveLeft_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LCA_ActiveLeft_nu() S_LCFRCV_LCA_ActiveLeft_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LCA_ActiveLeft_nu

#ifndef S_LCFRCV_LCA_ActiveRight_nu
#define S_LCFRCV_LCA_ActiveRight_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LCA_ActiveRight_nu() S_LCFRCV_LCA_ActiveRight_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LCA_ActiveRight_nu

#ifndef S_LCFRCV_LCA_WarningLeft_nu
#define S_LCFRCV_LCA_WarningLeft_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LCA_WarningLeft_nu() S_LCFRCV_LCA_WarningLeft_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LCA_WarningLeft_nu

#ifndef S_LCFRCV_LCA_WarningRight_nu
#define S_LCFRCV_LCA_WarningRight_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LCA_WarningRight_nu() S_LCFRCV_LCA_WarningRight_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LCA_WarningRight_nu

#ifndef S_LCFRCV_ErrorStateTJA_bool
#define S_LCFRCV_ErrorStateTJA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_ErrorStateTJA_bool() S_LCFRCV_ErrorStateTJA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_ErrorStateTJA_bool

#ifndef S_LCFRCV_LDCompState_enum
#define S_LCFRCV_LDCompState_enum (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LDCompState_enum() S_LCFRCV_LDCompState_enum //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LDCompState_enum

#ifndef S_LCFRCV_LDPMode_nu
#define S_LCFRCV_LDPMode_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LDPMode_nu() S_LCFRCV_LDPMode_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LDPMode_nu

#ifndef S_LCFRCV_LDPSwitch_bool
#define S_LCFRCV_LDPSwitch_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LDPSwitch_bool() S_LCFRCV_LDPSwitch_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LDPSwitch_bool

#ifndef S_LCFRCV_LDWMode_nu
#define S_LCFRCV_LDWMode_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LDWMode_nu() S_LCFRCV_LDWMode_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LDWMode_nu

#ifndef S_LCFRCV_LDWSwitch_bool
#define S_LCFRCV_LDWSwitch_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LDWSwitch_bool() S_LCFRCV_LDWSwitch_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LDWSwitch_bool

#ifndef S_LCFRCV_LKASwitch_nu
#define S_LCFRCV_LKASwitch_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LKASwitch_nu() S_LCFRCV_LKASwitch_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LKASwitch_nu

#ifndef S_LCFRCV_LaneBoundariesTstamp_us
#define S_LCFRCV_LaneBoundariesTstamp_us (0x00000000u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LaneBoundariesTstamp_us() S_LCFRCV_LaneBoundariesTstamp_us //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LaneBoundariesTstamp_us

#ifndef S_LCFRCV_LaneChange_nu
#define S_LCFRCV_LaneChange_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LaneChange_nu() S_LCFRCV_LaneChange_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_LaneChange_nu

#ifndef S_LCFRCV_OversteeringDetected_bool
#define S_LCFRCV_OversteeringDetected_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_OversteeringDetected_bool() S_LCFRCV_OversteeringDetected_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_OversteeringDetected_bool

#ifndef S_LCFRCV_RDPMode_nu
#define S_LCFRCV_RDPMode_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_RDPMode_nu() S_LCFRCV_RDPMode_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_RDPMode_nu

#ifndef S_LCFRCV_RDPSwitch_bool
#define S_LCFRCV_RDPSwitch_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_RDPSwitch_bool() S_LCFRCV_RDPSwitch_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_RDPSwitch_bool

#ifndef S_LCFRCV_RDWMode_nu
#define S_LCFRCV_RDWMode_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_RDWMode_nu() S_LCFRCV_RDWMode_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_RDWMode_nu

#ifndef S_LCFRCV_RDWSwitch_bool
#define S_LCFRCV_RDWSwitch_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_RDWSwitch_bool() S_LCFRCV_RDWSwitch_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_RDWSwitch_bool

#ifndef S_LCFRCV_RollerBenchDetected_bool
#define S_LCFRCV_RollerBenchDetected_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_RollerBenchDetected_bool() S_LCFRCV_RollerBenchDetected_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_RollerBenchDetected_bool

#ifndef S_LCFRCV_SteerWAngleRate_degps
#define S_LCFRCV_SteerWAngleRate_degps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SteerWAngleRate_degps() S_LCFRCV_SteerWAngleRate_degps //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SteerWAngleRate_degps

#ifndef S_LCFRCV_SteerWAngle_deg
#define S_LCFRCV_SteerWAngle_deg (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SteerWAngle_deg() S_LCFRCV_SteerWAngle_deg //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SteerWAngle_deg

#ifndef S_LCFRCV_SteeringAngleFrontAxleEff_rad
#define S_LCFRCV_SteeringAngleFrontAxleEff_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SteeringAngleFrontAxleEff_rad() S_LCFRCV_SteeringAngleFrontAxleEff_rad //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SteeringAngleFrontAxleEff_rad

#ifndef S_LCFRCV_SysCycleTimeSen_sec
#define S_LCFRCV_SysCycleTimeSen_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysCycleTimeSen_sec() S_LCFRCV_SysCycleTimeSen_sec //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysCycleTimeSen_sec

#ifndef S_LCFRCV_SysStAvailableABS_bool
#define S_LCFRCV_SysStAvailableABS_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableABS_bool() S_LCFRCV_SysStAvailableABS_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableABS_bool

#ifndef S_LCFRCV_SysStAvailableACC_bool
#define S_LCFRCV_SysStAvailableACC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableACC_bool() S_LCFRCV_SysStAvailableACC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableACC_bool

#ifndef S_LCFRCV_SysStAvailableEBA_bool
#define S_LCFRCV_SysStAvailableEBA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableEBA_bool() S_LCFRCV_SysStAvailableEBA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableEBA_bool

#ifndef S_LCFRCV_SysStAvailableESC_bool
#define S_LCFRCV_SysStAvailableESC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableESC_bool() S_LCFRCV_SysStAvailableESC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableESC_bool

#ifndef S_LCFRCV_SysStAvailableTCS_bool
#define S_LCFRCV_SysStAvailableTCS_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableTCS_bool() S_LCFRCV_SysStAvailableTCS_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableTCS_bool

#ifndef S_LCFRCV_SysStAvailableTSA_bool
#define S_LCFRCV_SysStAvailableTSA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableTSA_bool() S_LCFRCV_SysStAvailableTSA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableTSA_bool

#ifndef S_LCFRCV_SysStAvailableVSM_bool
#define S_LCFRCV_SysStAvailableVSM_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStAvailableVSM_bool() S_LCFRCV_SysStAvailableVSM_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStAvailableVSM_bool

#ifndef S_LCFRCV_SysStErrorABS_bool
#define S_LCFRCV_SysStErrorABS_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorABS_bool() S_LCFRCV_SysStErrorABS_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorABS_bool

#ifndef S_LCFRCV_SysStErrorACC_bool
#define S_LCFRCV_SysStErrorACC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorACC_bool() S_LCFRCV_SysStErrorACC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorACC_bool

#ifndef S_LCFRCV_SysStErrorEBA_bool
#define S_LCFRCV_SysStErrorEBA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorEBA_bool() S_LCFRCV_SysStErrorEBA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorEBA_bool

#ifndef S_LCFRCV_SysStErrorESC_bool
#define S_LCFRCV_SysStErrorESC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorESC_bool() S_LCFRCV_SysStErrorESC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorESC_bool

#ifndef S_LCFRCV_SysStErrorLatDMC_bool
#define S_LCFRCV_SysStErrorLatDMC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorLatDMC_bool() S_LCFRCV_SysStErrorLatDMC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorLatDMC_bool

#ifndef S_LCFRCV_SysStErrorTCS_bool
#define S_LCFRCV_SysStErrorTCS_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorTCS_bool() S_LCFRCV_SysStErrorTCS_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorTCS_bool

#ifndef S_LCFRCV_SysStErrorTSA_bool
#define S_LCFRCV_SysStErrorTSA_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorTSA_bool() S_LCFRCV_SysStErrorTSA_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorTSA_bool

#ifndef S_LCFRCV_SysStErrorVSM_bool
#define S_LCFRCV_SysStErrorVSM_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStErrorVSM_bool() S_LCFRCV_SysStErrorVSM_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStErrorVSM_bool

#ifndef S_LCFRCV_SysStOffLatDMC_bool
#define S_LCFRCV_SysStOffLatDMC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStOffLatDMC_bool() S_LCFRCV_SysStOffLatDMC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStOffLatDMC_bool

#ifndef S_LCFRCV_SysStOnLatDMC_bool
#define S_LCFRCV_SysStOnLatDMC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStOnLatDMC_bool() S_LCFRCV_SysStOnLatDMC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStOnLatDMC_bool

#ifndef S_LCFRCV_TJASwitch_nu
#define S_LCFRCV_TJASwitch_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TJASwitch_nu() S_LCFRCV_TJASwitch_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TJASwitch_nu

#ifndef S_LCFRCV_TrailerPresent_bool
#define S_LCFRCV_TrailerPresent_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TrailerPresent_bool() S_LCFRCV_TrailerPresent_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TrailerPresent_bool

#ifndef S_LCFRCV_TurnSignalHazard_bool
#define S_LCFRCV_TurnSignalHazard_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TurnSignalHazard_bool() S_LCFRCV_TurnSignalHazard_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TurnSignalHazard_bool

#ifndef S_LCFRCV_TurnSignalLeft_bool
#define S_LCFRCV_TurnSignalLeft_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TurnSignalLeft_bool() S_LCFRCV_TurnSignalLeft_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TurnSignalLeft_bool

#ifndef S_LCFRCV_TurnSignalLeverHold_bool
#define S_LCFRCV_TurnSignalLeverHold_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TurnSignalLeverHold_bool() S_LCFRCV_TurnSignalLeverHold_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TurnSignalLeverHold_bool

#ifndef S_LCFRCV_TurnSignalRight_bool
#define S_LCFRCV_TurnSignalRight_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TurnSignalRight_bool() S_LCFRCV_TurnSignalRight_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TurnSignalRight_bool

#ifndef S_LCFRCV_TurnSignalState_enum
#define S_LCFRCV_TurnSignalState_enum (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_TurnSignalState_enum() S_LCFRCV_TurnSignalState_enum //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_TurnSignalState_enum

#ifndef S_LCFRCV_UndersteeringDetected_bool
#define S_LCFRCV_UndersteeringDetected_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_UndersteeringDetected_bool() S_LCFRCV_UndersteeringDetected_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_UndersteeringDetected_bool

#ifndef S_LCFRCV_VDy_VehVelocity_kph
#define S_LCFRCV_VDy_VehVelocity_kph (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VDy_VehVelocity_kph() S_LCFRCV_VDy_VehVelocity_kph //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VDy_VehVelocity_kph

#ifndef S_LCFRCV_VehAclX_mps2
#define S_LCFRCV_VehAclX_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehAclX_mps2() S_LCFRCV_VehAclX_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehAclX_mps2

#ifndef S_LCFRCV_VehAclY_mps2
#define S_LCFRCV_VehAclY_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehAclY_mps2() S_LCFRCV_VehAclY_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehAclY_mps2

#ifndef S_LCFRCV_VehCrv_1pm
#define S_LCFRCV_VehCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehCrv_1pm() S_LCFRCV_VehCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehCrv_1pm

#ifndef S_LCFRCV_VehMovesBckwd_bool
#define S_LCFRCV_VehMovesBckwd_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehMovesBckwd_bool() S_LCFRCV_VehMovesBckwd_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehMovesBckwd_bool

#ifndef S_LCFRCV_VehReadyToStart_bool
#define S_LCFRCV_VehReadyToStart_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehReadyToStart_bool() S_LCFRCV_VehReadyToStart_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehReadyToStart_bool

#ifndef S_LCFRCV_VehStopped_nu
#define S_LCFRCV_VehStopped_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehStopped_nu() S_LCFRCV_VehStopped_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehStopped_nu

#ifndef S_LCFRCV_VehVelX_mps
#define S_LCFRCV_VehVelX_mps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehVelX_mps() S_LCFRCV_VehVelX_mps //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehVelX_mps

#ifndef S_LCFRCV_VehYawRateStd_radps
#define S_LCFRCV_VehYawRateStd_radps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehYawRateStd_radps() S_LCFRCV_VehYawRateStd_radps //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehYawRateStd_radps

#ifndef S_LCFRCV_VehYawRate_rps
#define S_LCFRCV_VehYawRate_rps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_VehYawRate_rps() S_LCFRCV_VehYawRate_rps //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_VehYawRate_rps

#ifndef S_LCFRCV_WiperStage_nu
#define S_LCFRCV_WiperStage_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_WiperStage_nu() S_LCFRCV_WiperStage_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_WiperStage_nu

#ifndef S_LCFRCV_WiperState_nu
#define S_LCFRCV_WiperState_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_WiperState_nu() S_LCFRCV_WiperState_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_WiperState_nu

#ifndef S_LCRSMI_SysStateALCA_nu
#define S_LCRSMI_SysStateALCA_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRSMI_SysStateALCA_nu() S_LCRSMI_SysStateALCA_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRSMI_SysStateALCA_nu

#ifndef S_LCSSTM_SysStateAOLC_nu
#define S_LCSSTM_SysStateAOLC_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCSSTM_SysStateAOLC_nu() S_LCSSTM_SysStateAOLC_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCSSTM_SysStateAOLC_nu

#ifndef S_ODPROP_DanRearObjFOV_RearLe_nu
#define S_ODPROP_DanRearObjFOV_RearLe_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPROP_DanRearObjFOV_RearLe_nu() S_ODPROP_DanRearObjFOV_RearLe_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPROP_DanRearObjFOV_RearLe_nu

#ifndef S_ODPROP_DanRearObjFOV_RearRi_nu
#define S_ODPROP_DanRearObjFOV_RearRi_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPROP_DanRearObjFOV_RearRi_nu() S_ODPROP_DanRearObjFOV_RearRi_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPROP_DanRearObjFOV_RearRi_nu

#ifndef S_ODPROP_OIQualifierFlag_RearLe_nu
#define S_ODPROP_OIQualifierFlag_RearLe_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPROP_OIQualifierFlag_RearLe_nu() S_ODPROP_OIQualifierFlag_RearLe_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPROP_OIQualifierFlag_RearLe_nu

#ifndef S_ODPROP_OIQualifierFlag_RearRi_nu
#define S_ODPROP_OIQualifierFlag_RearRi_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPROP_OIQualifierFlag_RearRi_nu() S_ODPROP_OIQualifierFlag_RearRi_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPROP_OIQualifierFlag_RearRi_nu

#ifndef S_ODPSOP_DanRearObjBS_RearLe_nu
#define S_ODPSOP_DanRearObjBS_RearLe_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPSOP_DanRearObjBS_RearLe_nu() S_ODPSOP_DanRearObjBS_RearLe_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPSOP_DanRearObjBS_RearLe_nu

#ifndef S_ODPSOP_DanRearObjBS_RearRi_nu
#define S_ODPSOP_DanRearObjBS_RearRi_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPSOP_DanRearObjBS_RearRi_nu() S_ODPSOP_DanRearObjBS_RearRi_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPSOP_DanRearObjBS_RearRi_nu

#ifndef S_ODPSOP_MSFlag_RearLeft_nu
#define S_ODPSOP_MSFlag_RearLeft_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPSOP_MSFlag_RearLeft_nu() S_ODPSOP_MSFlag_RearLeft_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPSOP_MSFlag_RearLeft_nu

#ifndef S_ODPSOP_MSFlag_RearRight_nu
#define S_ODPSOP_MSFlag_RearRight_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_ODPSOP_MSFlag_RearRight_nu() S_ODPSOP_MSFlag_RearRight_nu //!< LCFSEN stubbed input macro getter.
#endif // S_ODPSOP_MSFlag_RearRight_nu

#ifndef S_TCTCLM_QuServTrajCtr_nu
#define S_TCTCLM_QuServTrajCtr_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TCTCLM_QuServTrajCtr_nu() S_TCTCLM_QuServTrajCtr_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TCTCLM_QuServTrajCtr_nu

#ifndef S_TJASTM_SysStateTJA_nu
#define S_TJASTM_SysStateTJA_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASTM_SysStateTJA_nu() S_TJASTM_SysStateTJA_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJASTM_SysStateTJA_nu

#ifndef S_TJATTG_LeCridrBndCrvChng_1pm2
#define S_TJATTG_LeCridrBndCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_LeCridrBndCrvChng_1pm2() S_TJATTG_LeCridrBndCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_LeCridrBndCrvChng_1pm2

#ifndef S_TJATTG_LeCridrBndCrv_1pm
#define S_TJATTG_LeCridrBndCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_LeCridrBndCrv_1pm() S_TJATTG_LeCridrBndCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_LeCridrBndCrv_1pm

#ifndef S_TJATTG_LeCridrBndHeadAng_rad
#define S_TJATTG_LeCridrBndHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_LeCridrBndHeadAng_rad() S_TJATTG_LeCridrBndHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_LeCridrBndHeadAng_rad

#ifndef S_TJATTG_LeCridrBndLength_met
#define S_TJATTG_LeCridrBndLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_LeCridrBndLength_met() S_TJATTG_LeCridrBndLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_LeCridrBndLength_met

#ifndef S_TJATTG_LeCridrBndPosX0_met
#define S_TJATTG_LeCridrBndPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_LeCridrBndPosX0_met() S_TJATTG_LeCridrBndPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_LeCridrBndPosX0_met

#ifndef S_TJATTG_LeCridrBndPosY0_met
#define S_TJATTG_LeCridrBndPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_LeCridrBndPosY0_met() S_TJATTG_LeCridrBndPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_LeCridrBndPosY0_met

#ifndef S_TJATTG_RiCridrBndCrvChng_1pm2
#define S_TJATTG_RiCridrBndCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_RiCridrBndCrvChng_1pm2() S_TJATTG_RiCridrBndCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_RiCridrBndCrvChng_1pm2

#ifndef S_TJATTG_RiCridrBndCrv_1pm
#define S_TJATTG_RiCridrBndCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_RiCridrBndCrv_1pm() S_TJATTG_RiCridrBndCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_RiCridrBndCrv_1pm

#ifndef S_TJATTG_RiCridrBndHeadAng_rad
#define S_TJATTG_RiCridrBndHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_RiCridrBndHeadAng_rad() S_TJATTG_RiCridrBndHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_RiCridrBndHeadAng_rad

#ifndef S_TJATTG_RiCridrBndLength_met
#define S_TJATTG_RiCridrBndLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_RiCridrBndLength_met() S_TJATTG_RiCridrBndLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_RiCridrBndLength_met

#ifndef S_TJATTG_RiCridrBndPosX0_met
#define S_TJATTG_RiCridrBndPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_RiCridrBndPosX0_met() S_TJATTG_RiCridrBndPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_RiCridrBndPosX0_met

#ifndef S_TJATTG_RiCridrBndPosY0_met
#define S_TJATTG_RiCridrBndPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_RiCridrBndPosY0_met() S_TJATTG_RiCridrBndPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_RiCridrBndPosY0_met

#ifndef S_TJATTG_TgtTrajCrvChng_1pm2
#define S_TJATTG_TgtTrajCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_TgtTrajCrvChng_1pm2() S_TJATTG_TgtTrajCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_TgtTrajCrvChng_1pm2

#ifndef S_TJATTG_TgtTrajCrv_1pm
#define S_TJATTG_TgtTrajCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_TgtTrajCrv_1pm() S_TJATTG_TgtTrajCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_TgtTrajCrv_1pm

#ifndef S_TJATTG_TgtTrajHeadAng_rad
#define S_TJATTG_TgtTrajHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_TgtTrajHeadAng_rad() S_TJATTG_TgtTrajHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_TgtTrajHeadAng_rad

#ifndef S_TJATTG_TgtTrajLength_met
#define S_TJATTG_TgtTrajLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_TgtTrajLength_met() S_TJATTG_TgtTrajLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_TgtTrajLength_met

#ifndef S_TJATTG_TgtTrajPosX0_met
#define S_TJATTG_TgtTrajPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_TgtTrajPosX0_met() S_TJATTG_TgtTrajPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_TgtTrajPosX0_met

#ifndef S_TJATTG_TgtTrajPosY0_met
#define S_TJATTG_TgtTrajPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATTG_TgtTrajPosY0_met() S_TJATTG_TgtTrajPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATTG_TgtTrajPosY0_met

#ifndef S_TJATVG_DeratingLevel_nu
#define S_TJATVG_DeratingLevel_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_DeratingLevel_nu() S_TJATVG_DeratingLevel_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_DeratingLevel_nu

#ifndef S_TJATVG_DistYTolLeTgtArea_met
#define S_TJATVG_DistYTolLeTgtArea_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_DistYTolLeTgtArea_met() S_TJATVG_DistYTolLeTgtArea_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_DistYTolLeTgtArea_met

#ifndef S_TJATVG_DistYTolRiTgtArea_met
#define S_TJATVG_DistYTolRiTgtArea_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_DistYTolRiTgtArea_met() S_TJATVG_DistYTolRiTgtArea_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_DistYTolRiTgtArea_met

#ifndef S_TJATVG_FTireAclMax_mps2
#define S_TJATVG_FTireAclMax_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_FTireAclMax_mps2() S_TJATVG_FTireAclMax_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_FTireAclMax_mps2

#ifndef S_TJATVG_FTireAclMin_mps2
#define S_TJATVG_FTireAclMin_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_FTireAclMin_mps2() S_TJATVG_FTireAclMin_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_FTireAclMin_mps2

#ifndef S_TJATVG_GrdLimitTgtCrvTGC_1pms
#define S_TJATVG_GrdLimitTgtCrvTGC_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_GrdLimitTgtCrvTGC_1pms() S_TJATVG_GrdLimitTgtCrvTGC_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_TJATVG_HighStatAccu_bool
#define S_TJATVG_HighStatAccu_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_HighStatAccu_bool() S_TJATVG_HighStatAccu_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_HighStatAccu_bool

#ifndef S_TJATVG_LimiterActivated_nu
#define S_TJATVG_LimiterActivated_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_LimiterActivated_nu() S_TJATVG_LimiterActivated_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_LimiterActivated_nu

#ifndef S_TJATVG_LimiterTimeDuration_sec
#define S_TJATVG_LimiterTimeDuration_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_LimiterTimeDuration_sec() S_TJATVG_LimiterTimeDuration_sec //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_LimiterTimeDuration_sec

#ifndef S_TJATVG_LtcyCompActivated_nu
#define S_TJATVG_LtcyCompActivated_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_LtcyCompActivated_nu() S_TJATVG_LtcyCompActivated_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_LtcyCompActivated_nu

#ifndef S_TJATVG_MaxCrvGrdBuildup_1pms
#define S_TJATVG_MaxCrvGrdBuildup_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_MaxCrvGrdBuildup_1pms() S_TJATVG_MaxCrvGrdBuildup_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_MaxCrvGrdBuildup_1pms

#ifndef S_TJATVG_MaxCrvGrdRed_1pms
#define S_TJATVG_MaxCrvGrdRed_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_MaxCrvGrdRed_1pms() S_TJATVG_MaxCrvGrdRed_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_MaxCrvGrdRed_1pms

#ifndef S_TJATVG_MaxCrvTrajGuiCtrl_1pm
#define S_TJATVG_MaxCrvTrajGuiCtrl_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_MaxCrvTrajGuiCtrl_1pm() S_TJATVG_MaxCrvTrajGuiCtrl_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_TJATVG_MaxJerkAllowed_mps3
#define S_TJATVG_MaxJerkAllowed_mps3 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_MaxJerkAllowed_mps3() S_TJATVG_MaxJerkAllowed_mps3 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_MaxJerkAllowed_mps3

#ifndef S_TJATVG_MaxTrqScalGrad_1ps
#define S_TJATVG_MaxTrqScalGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_MaxTrqScalGrad_1ps() S_TJATVG_MaxTrqScalGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_MaxTrqScalGrad_1ps

#ifndef S_TJATVG_MaxTrqScalLimit_nu
#define S_TJATVG_MaxTrqScalLimit_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_MaxTrqScalLimit_nu() S_TJATVG_MaxTrqScalLimit_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_MaxTrqScalLimit_nu

#ifndef S_TJATVG_ObstacleAclX_mps2
#define S_TJATVG_ObstacleAclX_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_ObstacleAclX_mps2() S_TJATVG_ObstacleAclX_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_ObstacleAclX_mps2

#ifndef S_TJATVG_ObstacleDistX_met
#define S_TJATVG_ObstacleDistX_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_ObstacleDistX_met() S_TJATVG_ObstacleDistX_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_ObstacleDistX_met

#ifndef S_TJATVG_ObstacleDistY_met
#define S_TJATVG_ObstacleDistY_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_ObstacleDistY_met() S_TJATVG_ObstacleDistY_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_ObstacleDistY_met

#ifndef S_TJATVG_ObstacleVelX_mps
#define S_TJATVG_ObstacleVelX_mps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_ObstacleVelX_mps() S_TJATVG_ObstacleVelX_mps //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_ObstacleVelX_mps

#ifndef S_TJATVG_ObstacleWidth_met
#define S_TJATVG_ObstacleWidth_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_ObstacleWidth_met() S_TJATVG_ObstacleWidth_met //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_ObstacleWidth_met

#ifndef S_TJATVG_PlanningHorizon_sec
#define S_TJATVG_PlanningHorizon_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_PlanningHorizon_sec() S_TJATVG_PlanningHorizon_sec //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_PlanningHorizon_sec

#ifndef S_TJATVG_PredTimeCrv_sec
#define S_TJATVG_PredTimeCrv_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_PredTimeCrv_sec() S_TJATVG_PredTimeCrv_sec //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_PredTimeCrv_sec

#ifndef S_TJATVG_PredTimeHeadAng_sec
#define S_TJATVG_PredTimeHeadAng_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_PredTimeHeadAng_sec() S_TJATVG_PredTimeHeadAng_sec //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_PredTimeHeadAng_sec

#ifndef S_TJATVG_SensorTStamp_sec
#define S_TJATVG_SensorTStamp_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_SensorTStamp_sec() S_TJATVG_SensorTStamp_sec //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_SensorTStamp_sec

#ifndef S_TJATVG_StrWhStifGrad_1ps
#define S_TJATVG_StrWhStifGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_StrWhStifGrad_1ps() S_TJATVG_StrWhStifGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_StrWhStifGrad_1ps

#ifndef S_TJATVG_StrWhStifLimit_nu
#define S_TJATVG_StrWhStifLimit_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_StrWhStifLimit_nu() S_TJATVG_StrWhStifLimit_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_StrWhStifLimit_nu

#ifndef S_TJATVG_TrajGuiQu_nu
#define S_TJATVG_TrajGuiQu_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_TrajGuiQu_nu() S_TJATVG_TrajGuiQu_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_TrajGuiQu_nu

#ifndef S_TJATVG_TrajPlanServQu_nu
#define S_TJATVG_TrajPlanServQu_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_TrajPlanServQu_nu() S_TJATVG_TrajPlanServQu_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_TrajPlanServQu_nu

#ifndef S_TJATVG_TriggerReplan_nu
#define S_TJATVG_TriggerReplan_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_TriggerReplan_nu() S_TJATVG_TriggerReplan_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_TriggerReplan_nu

#ifndef S_TJATVG_TrqRampGrad_1ps
#define S_TJATVG_TrqRampGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_TrqRampGrad_1ps() S_TJATVG_TrqRampGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_TrqRampGrad_1ps

#ifndef S_TJATVG_WeightEndTime_nu
#define S_TJATVG_WeightEndTime_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_WeightEndTime_nu() S_TJATVG_WeightEndTime_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_WeightEndTime_nu

#ifndef S_TJATVG_WeightTgtDistY_nu
#define S_TJATVG_WeightTgtDistY_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_TJATVG_WeightTgtDistY_nu() S_TJATVG_WeightTgtDistY_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJATVG_WeightTgtDistY_nu

#ifndef S_LCRTTG_LeCridrBndCrvChng_1pm2
#define S_LCRTTG_LeCridrBndCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_LeCridrBndCrvChng_1pm2() S_LCRTTG_LeCridrBndCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_LeCridrBndCrvChng_1pm2

#ifndef S_LCRTTG_LeCridrBndCrv_1pm
#define S_LCRTTG_LeCridrBndCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_LeCridrBndCrv_1pm() S_LCRTTG_LeCridrBndCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_LeCridrBndCrv_1pm

#ifndef S_LCRTTG_LeCridrBndHeadAng_rad
#define S_LCRTTG_LeCridrBndHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_LeCridrBndHeadAng_rad() S_LCRTTG_LeCridrBndHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_LeCridrBndHeadAng_rad

#ifndef S_LCRTTG_LeCridrBndLength_met
#define S_LCRTTG_LeCridrBndLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_LeCridrBndLength_met() S_LCRTTG_LeCridrBndLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_LeCridrBndLength_met

#ifndef S_LCRTTG_LeCridrBndPosX0_met
#define S_LCRTTG_LeCridrBndPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_LeCridrBndPosX0_met() S_LCRTTG_LeCridrBndPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_LeCridrBndPosX0_met

#ifndef S_LCRTTG_LeCridrBndPosY0_met
#define S_LCRTTG_LeCridrBndPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_LeCridrBndPosY0_met() S_LCRTTG_LeCridrBndPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_LeCridrBndPosY0_met

#ifndef S_LCRTTG_RiCridrBndCrvChng_1pm2
#define S_LCRTTG_RiCridrBndCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_RiCridrBndCrvChng_1pm2() S_LCRTTG_RiCridrBndCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_RiCridrBndCrvChng_1pm2

#ifndef S_LCRTTG_RiCridrBndCrv_1pm
#define S_LCRTTG_RiCridrBndCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_RiCridrBndCrv_1pm() S_LCRTTG_RiCridrBndCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_RiCridrBndCrv_1pm

#ifndef S_LCRTTG_RiCridrBndHeadAng_rad
#define S_LCRTTG_RiCridrBndHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_RiCridrBndHeadAng_rad() S_LCRTTG_RiCridrBndHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_RiCridrBndHeadAng_rad

#ifndef S_LCRTTG_RiCridrBndLength_met
#define S_LCRTTG_RiCridrBndLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_RiCridrBndLength_met() S_LCRTTG_RiCridrBndLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_RiCridrBndLength_met

#ifndef S_LCRTTG_RiCridrBndPosX0_met
#define S_LCRTTG_RiCridrBndPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_RiCridrBndPosX0_met() S_LCRTTG_RiCridrBndPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_RiCridrBndPosX0_met

#ifndef S_LCRTTG_RiCridrBndPosY0_met
#define S_LCRTTG_RiCridrBndPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_RiCridrBndPosY0_met() S_LCRTTG_RiCridrBndPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_RiCridrBndPosY0_met

#ifndef S_LCRTTG_TgtTrajCrvChng_1pm2
#define S_LCRTTG_TgtTrajCrvChng_1pm2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_TgtTrajCrvChng_1pm2() S_LCRTTG_TgtTrajCrvChng_1pm2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_TgtTrajCrvChng_1pm2

#ifndef S_LCRTTG_TgtTrajCrv_1pm
#define S_LCRTTG_TgtTrajCrv_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_TgtTrajCrv_1pm() S_LCRTTG_TgtTrajCrv_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_TgtTrajCrv_1pm

#ifndef S_LCRTTG_TgtTrajHeadAng_rad
#define S_LCRTTG_TgtTrajHeadAng_rad (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_TgtTrajHeadAng_rad() S_LCRTTG_TgtTrajHeadAng_rad //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_TgtTrajHeadAng_rad

#ifndef S_LCRTTG_TgtTrajLength_met
#define S_LCRTTG_TgtTrajLength_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_TgtTrajLength_met() S_LCRTTG_TgtTrajLength_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_TgtTrajLength_met

#ifndef S_LCRTTG_TgtTrajPosX0_met
#define S_LCRTTG_TgtTrajPosX0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_TgtTrajPosX0_met() S_LCRTTG_TgtTrajPosX0_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_TgtTrajPosX0_met

#ifndef S_LCRTTG_TgtTrajPosY0_met
#define S_LCRTTG_TgtTrajPosY0_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTTG_TgtTrajPosY0_met() S_LCRTTG_TgtTrajPosY0_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTTG_TgtTrajPosY0_met

#ifndef S_LCRTVG_DeratingLevel_nu
#define S_LCRTVG_DeratingLevel_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_DeratingLevel_nu() S_LCRTVG_DeratingLevel_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_DeratingLevel_nu

#ifndef S_LCRTVG_DistYTolLeTgtArea_met
#define S_LCRTVG_DistYTolLeTgtArea_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_DistYTolLeTgtArea_met() S_LCRTVG_DistYTolLeTgtArea_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_DistYTolLeTgtArea_met

#ifndef S_LCRTVG_DistYTolRiTgtArea_met
#define S_LCRTVG_DistYTolRiTgtArea_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_DistYTolRiTgtArea_met() S_LCRTVG_DistYTolRiTgtArea_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_DistYTolRiTgtArea_met

#ifndef S_LCRTVG_FTireAclMax_mps2
#define S_LCRTVG_FTireAclMax_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_FTireAclMax_mps2() S_LCRTVG_FTireAclMax_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_FTireAclMax_mps2

#ifndef S_LCRTVG_FTireAclMin_mps2
#define S_LCRTVG_FTireAclMin_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_FTireAclMin_mps2() S_LCRTVG_FTireAclMin_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_FTireAclMin_mps2

#ifndef S_LCRTVG_GrdLimitTgtCrvTGC_1pms
#define S_LCRTVG_GrdLimitTgtCrvTGC_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_GrdLimitTgtCrvTGC_1pms() S_LCRTVG_GrdLimitTgtCrvTGC_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_GrdLimitTgtCrvTGC_1pms

#ifndef S_LCRTVG_HighStatAccu_bool
#define S_LCRTVG_HighStatAccu_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_HighStatAccu_bool() S_LCRTVG_HighStatAccu_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_HighStatAccu_bool

#ifndef S_LCRTVG_LimiterActivated_bool
#define S_LCRTVG_LimiterActivated_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_LimiterActivated_bool() S_LCRTVG_LimiterActivated_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_LimiterActivated_bool

#ifndef S_LCRTVG_LimiterTimeDuration_sec
#define S_LCRTVG_LimiterTimeDuration_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_LimiterTimeDuration_sec() S_LCRTVG_LimiterTimeDuration_sec //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_LimiterTimeDuration_sec

#ifndef S_LCRTVG_LtcyCompActivated_bool
#define S_LCRTVG_LtcyCompActivated_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_LtcyCompActivated_bool() S_LCRTVG_LtcyCompActivated_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_LtcyCompActivated_bool

#ifndef S_LCRTVG_MaxCrvGrdBuildup_1pms
#define S_LCRTVG_MaxCrvGrdBuildup_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_MaxCrvGrdBuildup_1pms() S_LCRTVG_MaxCrvGrdBuildup_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_MaxCrvGrdBuildup_1pms

#ifndef S_LCRTVG_MaxCrvGrdRed_1pms
#define S_LCRTVG_MaxCrvGrdRed_1pms (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_MaxCrvGrdRed_1pms() S_LCRTVG_MaxCrvGrdRed_1pms //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_MaxCrvGrdRed_1pms

#ifndef S_LCRTVG_MaxCrvTrajGuiCtrl_1pm
#define S_LCRTVG_MaxCrvTrajGuiCtrl_1pm (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_MaxCrvTrajGuiCtrl_1pm() S_LCRTVG_MaxCrvTrajGuiCtrl_1pm //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_MaxCrvTrajGuiCtrl_1pm

#ifndef S_LCRTVG_MaxJerkAllowed_mps3
#define S_LCRTVG_MaxJerkAllowed_mps3 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_MaxJerkAllowed_mps3() S_LCRTVG_MaxJerkAllowed_mps3 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_MaxJerkAllowed_mps3

#ifndef S_LCRTVG_MaxTrqScalGrad_1ps
#define S_LCRTVG_MaxTrqScalGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_MaxTrqScalGrad_1ps() S_LCRTVG_MaxTrqScalGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_MaxTrqScalGrad_1ps

#ifndef S_LCRTVG_MaxTrqScalLimit_nu
#define S_LCRTVG_MaxTrqScalLimit_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_MaxTrqScalLimit_nu() S_LCRTVG_MaxTrqScalLimit_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_MaxTrqScalLimit_nu

#ifndef S_LCRTVG_ObstacleAclX_mps2
#define S_LCRTVG_ObstacleAclX_mps2 (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_ObstacleAclX_mps2() S_LCRTVG_ObstacleAclX_mps2 //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_ObstacleAclX_mps2

#ifndef S_LCRTVG_ObstacleDistX_met
#define S_LCRTVG_ObstacleDistX_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_ObstacleDistX_met() S_LCRTVG_ObstacleDistX_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_ObstacleDistX_met

#ifndef S_LCRTVG_ObstacleDistY_met
#define S_LCRTVG_ObstacleDistY_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_ObstacleDistY_met() S_LCRTVG_ObstacleDistY_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_ObstacleDistY_met

#ifndef S_LCRTVG_ObstacleVelX_mps
#define S_LCRTVG_ObstacleVelX_mps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_ObstacleVelX_mps() S_LCRTVG_ObstacleVelX_mps //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_ObstacleVelX_mps

#ifndef S_LCRTVG_ObstacleWidth_met
#define S_LCRTVG_ObstacleWidth_met (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_ObstacleWidth_met() S_LCRTVG_ObstacleWidth_met //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_ObstacleWidth_met

#ifndef S_LCRTVG_PlanningHorizon_sec
#define S_LCRTVG_PlanningHorizon_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_PlanningHorizon_sec() S_LCRTVG_PlanningHorizon_sec //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_PlanningHorizon_sec

#ifndef S_LCRTVG_PredTimeCrv_sec
#define S_LCRTVG_PredTimeCrv_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_PredTimeCrv_sec() S_LCRTVG_PredTimeCrv_sec //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_PredTimeCrv_sec

#ifndef S_LCRTVG_PredTimeHeadAng_sec
#define S_LCRTVG_PredTimeHeadAng_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_PredTimeHeadAng_sec() S_LCRTVG_PredTimeHeadAng_sec //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_PredTimeHeadAng_sec

#ifndef S_LCRTVG_SensorTStamp_sec
#define S_LCRTVG_SensorTStamp_sec (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_SensorTStamp_sec() S_LCRTVG_SensorTStamp_sec //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_SensorTStamp_sec

#ifndef S_LCRTVG_StrWhStifGrad_1ps
#define S_LCRTVG_StrWhStifGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_StrWhStifGrad_1ps() S_LCRTVG_StrWhStifGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_StrWhStifGrad_1ps

#ifndef S_LCRTVG_StrWhStifLimit_nu
#define S_LCRTVG_StrWhStifLimit_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_StrWhStifLimit_nu() S_LCRTVG_StrWhStifLimit_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_StrWhStifLimit_nu

#ifndef S_LCRTVG_TrajGuiQu_nu
#define S_LCRTVG_TrajGuiQu_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_TrajGuiQu_nu() S_LCRTVG_TrajGuiQu_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_TrajGuiQu_nu

#ifndef S_LCRTVG_TrajPlanServQu_nu
#define S_LCRTVG_TrajPlanServQu_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_TrajPlanServQu_nu() S_LCRTVG_TrajPlanServQu_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_TrajPlanServQu_nu

#ifndef S_LCRTVG_TriggerReplan_bool
#define S_LCRTVG_TriggerReplan_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_TriggerReplan_bool() S_LCRTVG_TriggerReplan_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_TriggerReplan_bool

#ifndef S_LCRTVG_TrqRampGrad_1ps
#define S_LCRTVG_TrqRampGrad_1ps (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_TrqRampGrad_1ps() S_LCRTVG_TrqRampGrad_1ps //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_TrqRampGrad_1ps

#ifndef S_LCRTVG_WeightEndTime_nu
#define S_LCRTVG_WeightEndTime_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_WeightEndTime_nu() S_LCRTVG_WeightEndTime_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_WeightEndTime_nu

#ifndef S_LCRTVG_WeightTgtDistY_nu
#define S_LCRTVG_WeightTgtDistY_nu (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCRTVG_WeightTgtDistY_nu() S_LCRTVG_WeightTgtDistY_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCRTVG_WeightTgtDistY_nu

#ifndef S_LCSSTM_SysStateAOLC_nu
#define S_LCSSTM_SysStateAOLC_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCSSTM_SysStateAOLC_nu() S_LCSSTM_SysStateAOLC_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCSSTM_SysStateAOLC_nu

#ifndef S_TCTCLM_QuServTrajCtr_nu
#define S_TCTCLM_QuServTrajCtr_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TCTCLM_QuServTrajCtr_nu() S_TCTCLM_QuServTrajCtr_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TCTCLM_QuServTrajCtr_nu

#ifndef S_TJAOBS_CancelLC_bool
#define S_TJAOBS_CancelLC_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJAOBS_CancelLC_bool() S_TJAOBS_CancelLC_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJAOBS_CancelLC_bool

#ifndef S_TJAOBS_CancelOF_bool
#define S_TJAOBS_CancelOF_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJAOBS_CancelOF_bool() S_TJAOBS_CancelOF_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJAOBS_CancelOF_bool

#ifndef S_TJASLC_Cancel_bool
#define S_TJASLC_Cancel_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASLC_Cancel_bool() S_TJASLC_Cancel_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJASLC_Cancel_bool

#ifndef S_TJASLC_LaneChangeTrig_nu
#define S_TJASLC_LaneChangeTrig_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASLC_LaneChangeTrig_nu() S_TJASLC_LaneChangeTrig_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJASLC_LaneChangeTrig_nu

#ifndef S_TJASLC_ManeuverState_nu
#define S_TJASLC_ManeuverState_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASLC_ManeuverState_nu() S_TJASLC_ManeuverState_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TJASLC_ManeuverState_nu

#ifndef S_TJASLC_StrongReady_bool
#define S_TJASLC_StrongReady_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASLC_StrongReady_bool() S_TJASLC_StrongReady_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJASLC_StrongReady_bool

#ifndef S_TJASLC_TakeOverValid_bool
#define S_TJASLC_TakeOverValid_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASLC_TakeOverValid_bool() S_TJASLC_TakeOverValid_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJASLC_TakeOverValid_bool

#ifndef S_TJASLC_WeakReady_bool
#define S_TJASLC_WeakReady_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_TJASLC_WeakReady_bool() S_TJASLC_WeakReady_bool //!< LCFSEN stubbed input macro getter.
#endif // S_TJASLC_WeakReady_bool

#ifndef S_TPLFBT_QuStatusTrajPlan_nu
#define S_TPLFBT_QuStatusTrajPlan_nu (0x0000u) //!< LCFSEN stubbed input macro.
#define GET_S_TPLFBT_QuStatusTrajPlan_nu() S_TPLFBT_QuStatusTrajPlan_nu //!< LCFSEN stubbed input macro getter.
#endif // S_TPLFBT_QuStatusTrajPlan_nu

#ifndef S_LCFRCV_AnyBndAvailable_bool
#define S_LCFRCV_AnyBndAvailable_bool(i) (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndAvailable_bool(i) S_LCFRCV_AnyBndAvailable_bool(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndAvailable_bool() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndAvailable_bool

#ifndef S_LCFRCV_AnyBndColor_nu
#define S_LCFRCV_AnyBndColor_nu(i) (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndColor_nu(i) S_LCFRCV_AnyBndColor_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndColor_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndColor_nu

#ifndef S_LCFRCV_AnyBndCrvRateStd_1pm2
#define S_LCFRCV_AnyBndCrvRateStd_1pm2(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndCrvRateStd_1pm2(i) S_LCFRCV_AnyBndCrvRateStd_1pm2(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndCrvRateStd_1pm2() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndCrvRateStd_1pm2

#ifndef S_LCFRCV_AnyBndCrvRate_1pm2
#define S_LCFRCV_AnyBndCrvRate_1pm2(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndCrvRate_1pm2(i) S_LCFRCV_AnyBndCrvRate_1pm2(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndCrvRate_1pm2() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndCrvRate_1pm2

#ifndef S_LCFRCV_AnyBndCurvatureStd_1pm
#define S_LCFRCV_AnyBndCurvatureStd_1pm(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndCurvatureStd_1pm(i) S_LCFRCV_AnyBndCurvatureStd_1pm(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndCurvatureStd_1pm() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndCurvatureStd_1pm

#ifndef S_LCFRCV_AnyBndCurvature_1pm
#define S_LCFRCV_AnyBndCurvature_1pm(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndCurvature_1pm(i) S_LCFRCV_AnyBndCurvature_1pm(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndCurvature_1pm() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndCurvature_1pm

#ifndef S_LCFRCV_AnyBndDistanceStd_met
#define S_LCFRCV_AnyBndDistanceStd_met(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndDistanceStd_met(i) S_LCFRCV_AnyBndDistanceStd_met(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndDistanceStd_met() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndDistanceStd_met

#ifndef S_LCFRCV_AnyBndDistance_met
#define S_LCFRCV_AnyBndDistance_met(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndDistance_met(i) S_LCFRCV_AnyBndDistance_met(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndDistance_met() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndDistance_met

#ifndef S_LCFRCV_AnyBndLeftIndex_nu
#define S_LCFRCV_AnyBndLeftIndex_nu(i) (0) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndLeftIndex_nu(i) S_LCFRCV_AnyBndLeftIndex_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndLeftIndex_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndLeftIndex_nu

#ifndef S_LCFRCV_AnyBndMarkerType_nu
#define S_LCFRCV_AnyBndMarkerType_nu(i) (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndMarkerType_nu(i) S_LCFRCV_AnyBndMarkerType_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndMarkerType_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndMarkerType_nu

#ifndef S_LCFRCV_AnyBndQuality_nu
#define S_LCFRCV_AnyBndQuality_nu(i) (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndQuality_nu(i) S_LCFRCV_AnyBndQuality_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndQuality_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndQuality_nu

#ifndef S_LCFRCV_AnyBndRightIndex_nu
#define S_LCFRCV_AnyBndRightIndex_nu(i) (0) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndRightIndex_nu(i) S_LCFRCV_AnyBndRightIndex_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndRightIndex_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndRightIndex_nu

#ifndef S_LCFRCV_AnyBndValidLength_met
#define S_LCFRCV_AnyBndValidLength_met(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndValidLength_met(i) S_LCFRCV_AnyBndValidLength_met(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndValidLength_met() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndValidLength_met

#ifndef S_LCFRCV_AnyBndYawAngleStd_rad
#define S_LCFRCV_AnyBndYawAngleStd_rad(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndYawAngleStd_rad(i) S_LCFRCV_AnyBndYawAngleStd_rad(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndYawAngleStd_rad() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndYawAngleStd_rad

#ifndef S_LCFRCV_AnyBndYawAngle_rad
#define S_LCFRCV_AnyBndYawAngle_rad(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_AnyBndYawAngle_rad(i) S_LCFRCV_AnyBndYawAngle_rad(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_AnyBndYawAngle_rad() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_AnyBndYawAngle_rad

#ifndef S_LCFRCV_LaneEventDistance_met
#define S_LCFRCV_LaneEventDistance_met(i) (0.f) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LaneEventDistance_met(i) S_LCFRCV_LaneEventDistance_met(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_LaneEventDistance_met() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_LaneEventDistance_met

#ifndef S_LCFRCV_LaneEventQuality_nu
#define S_LCFRCV_LaneEventQuality_nu(i) (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LaneEventQuality_nu(i) S_LCFRCV_LaneEventQuality_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_LaneEventQuality_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_LaneEventQuality_nu

#ifndef S_LCFRCV_LaneEventType_nu
#define S_LCFRCV_LaneEventType_nu(i) (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_LaneEventType_nu(i) S_LCFRCV_LaneEventType_nu(i) //!< LCFSEN stubbed input macro getter.
#define GETA_S_LCFRCV_LaneEventType_nu() (NULL) //!< LCFSEN stubbed input pointer macro getter.
#endif // S_LCFRCV_LaneEventType_nu

#ifndef S_LCFRCV_MainCylPressure_pa
#define S_LCFRCV_MainCylPressure_pa (0x00000000u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_MainCylPressure_pa() S_LCFRCV_MainCylPressure_pa //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_MainCylPressure_pa

#ifndef S_LCFRCV_SysStateIACC_nu
#define S_LCFRCV_SysStateIACC_nu (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_SysStateIACC_nu() S_LCFRCV_SysStateIACC_nu //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_SysStateIACC_nu

#ifndef S_LCFRCV_BrkPedlPressed_bool
#define S_LCFRCV_BrkPedlPressed_bool (0x00u) //!< LCFSEN stubbed input macro.
#define GET_S_LCFRCV_BrkPedlPressed_bool() S_LCFRCV_BrkPedlPressed_bool //!< LCFSEN stubbed input macro getter.
#endif // S_LCFRCV_BrkPedlPressed_bool

#ifdef __cplusplus
}
#endif

#endif /* LCFSEN_DATA_H_ */
