/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 latdmc_wrp_custom.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: latdmc_wrp_custom.h  $
  CHANGES:                   Revision 1.1 2020/04/07 10:02:01CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Project_Specific/MFC431VA21/LCF/Src/LCF_DPU/project.pj
  CHANGES:                   Revision 1.1 2019/09/26 12:24:41CEST Feick, Stefan (uidw0691) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Project_Specific/MFC431VA10/LCF/Src/LCF_DPU/project.pj
  CHANGES:                   Revision 1.1 2019/03/31 23:35:57CEST Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/00_Projects/MFC431SW19/LCF/LCF_DPU/project.pj
  CHANGES:                   Revision 1.1.1.2 2019/03/20 10:02:35CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431SW19/LCF/LCF_VEH/wrp/project.pj
  CHANGES:                   Revision 1.1 2019/01/29 10:23:56CET Liu, Bingguo (uids3991) 
  CHANGES:                   copy the content from the DPU base
  CHANGES:                   Revision 1.4 2018/08/22 11:37:40CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Integrate lcf_veh/wrp into trunk for LO19
  CHANGES:                   Revision 1.3 2018/08/14 10:46:50CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Prepare for CP 03.18.11 checkpoint description:
  CHANGES:                   	- components generated 09.08.2018
  CHANGES:                   	- new modules in ODPR sub-components (ODPOOS, ODPOOK, ODPILE, ODPFOH)
  CHANGES:                   	- parameters update
  CHANGES:                   	- LATDMC wrappers and parameters
  CHANGES:                   	- remove HMIOC.c from algo_lib_file_list
  CHANGES:                   Revision 1.0.1.1 2018/08/10 12:27:50CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   [MFC431LO19] LCF integration for R3- Generic RO - Prepare CP 03.17.11 (LCF R3 Branch)
  CHANGES:                    - First R8.3 LCF CP for MFC431LO19 R3
  CHANGES:                   Revision 1.2 2018/06/20 11:13:08CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update latdmc_custom_wrapper
  CHANGES:                   Revision 1.1 2018/06/18 13:53:33CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Fill and update MFC431LO19 project specific files
  CHANGES:                   Revision 1.7 2018/03/27 13:12:52CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.6 2018/03/12 14:01:32CET Yoshida, Tadashi (uidd4679) 
  CHANGES:                   S_BUS_EPS_TOR_BAR_TORQUE_QF:
  CHANGES:                   changed from 1(Invalid) to 0(Valid), otherwise LatDMC state will be always permanent error
  CHANGES:                   Revision 1.5 2018/02/07 14:35:20CET Nastasa, Elena (uidt4846) 
  CHANGES:                   MFC431 bugfix 3 R8.0
  CHANGES:                   Revision 1.4 2018/02/02 08:54:24CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   MFC431 R8.0 - bugfix2 - round2
  CHANGES:                   Revision 1.2 2018/01/30 15:10:31CET Kuboyama, Michinobu (KuboyamaM) 
  CHANGES:                   What: define TA19 unique input to latDMC.
  CHANGES:                   Why: change structure as meinstream
  CHANGES:                   Revision 1.1 2018/01/26 12:09:44CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/00_Projects/MFC431TA19/LCF/lcf_veh/wrp/project.pj
  
**************************************************************************** */

#ifndef latdmc_wrp_custom_h__
#define latdmc_wrp_custom_h__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "LCFVEH/LCFVEH.h"

/*****************************************************************************
  MACROS
*****************************************************************************/

#define LATDMC_MERGED_ANG /* define LATDMC variant */
#define LADMC_STANGREQ_RES     (0.024416f)    /* LaDMC steering angle command resolution */
#define LADMC_STANGRATE_RES_LO19     (0.0078125f)    /* LaDMC steering angle command resolution */
#define CONV_RADPS2DEGPS    (57.2957795f)  /* conversion factor from rad/s to deg/s */

// Y.Kanamori(180530):Delete toyota unique specific because all of situation assessments are corresponded any case warning
/*
#ifndef	S_SSI_R_DMC_LAT_ACTVN_MOD
#define	S_SSI_R_DMC_LAT_ACTVN_MOD	(((GET_S_LCFRCV_LDPSwitch_bool() == 0u) && (GET_S_LCFRCV_LDWSwitch_bool() != 0u)) ? 0 : \
										((GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_REQUEST_nu) \
									||	 (GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_CONTROLLING_nu) \
									||	 (GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_RAMPOUT_nu)))
#endif
*/

#ifndef	S_SSI_R_DMC_STEER_WHL_VIBR
#define	S_SSI_R_DMC_STEER_WHL_VIBR	(0)
#endif

/* M.Kuboyama Set to 0 from IuC DMC since Application with SoC only for LO19 */
/* IuC torque request */
#ifndef	S_LAT_Eps_Torque_Request_nm
#define	S_LAT_Eps_Torque_Request_nm	(0)
#endif

/* IuC DMC status */
#ifndef	S_LAT_Dmc_Status_nu
#define	S_LAT_Dmc_Status_nu	(0)	/* do not change this default value */ //?? ClPr: TODO check if any loss of information
#endif


/* M.Kuboyama not used for LO19 LatDMC error -> abort condition, generic LCF failure condition will checked each SA, set status to error*/
/* ESC is finally disabled (ESC_SystemState) */
#ifndef	S_FINAL_FUNCTION_DISABLE_AYC
#define	S_FINAL_FUNCTION_DISABLE_AYC	(0)
#endif

/* ESC is temporary disabled (ESC_SystemState) */
#ifndef	S_FUNCTION_DISABLE_AYC
#define	S_FUNCTION_DISABLE_AYC	(0)
#endif

/* ESC warning lamp is active */
#ifndef	S_AYC_WARNING_LAMP
#define	S_AYC_WARNING_LAMP	(0)
#endif

/* Vehicle yaw rate qualifier, 0: signal is invalid, 1: signal is valid */
#ifndef	S_DMC_FILTERED_YAW_RATE_QF
#define	S_DMC_FILTERED_YAW_RATE_QF	(1)
#endif

/* Vehicle lateral acceleration qualifier, 0: signal is invalid, 1: signal is valid */
#ifndef	S_DMC_FILTERED_LATERAL_ACC_COG_QF
#define	S_DMC_FILTERED_LATERAL_ACC_COG_QF	(1)
#endif

/* EPS steering angle rate qualifier, 0: signal is invalid, 1: signal is valid */
#ifndef	S_DMC_FILTERED_STEER_ANGLE_RATE_QF
#define	S_DMC_FILTERED_STEER_ANGLE_RATE_QF	(1)
#endif



#endif // latdmc_wrp_custom_h__
