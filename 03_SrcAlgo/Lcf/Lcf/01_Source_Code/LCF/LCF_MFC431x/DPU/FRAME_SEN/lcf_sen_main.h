/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_sen_main.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.6.1.8 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_sen_main.h  $
  CHANGES:                   Revision 1.6.1.8 2020/02/21 12:50:06CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.6.1.6 2020/01/23 08:18:46CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updated files after removing some QAF warnings
  CHANGES:                   Revision 1.6.1.5 2019/09/12 13:42:52CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrappers bugs:
  CHANGES:                   - signal headers LCF outputs are now set to StateOK in Running
  CHANGES:                   - use of IPCParams is safeguarded
  CHANGES:                   - corrected masks for PortCheck
  CHANGES:                   Revision 1.6.1.4 2019/08/21 13:11:56CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.6.1.3 2019/07/30 10:04:14CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.6.1.2 2019/07/26 07:46:44CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   follow up foe LCF workshop 1:
  CHANGES:                   	- Correct commens in the function headers
  CHANGES:                   	- add IPC protection for VEH cpar's
  CHANGES:                   	- Review comments for the Input checks Debug signals in iface header
  CHANGES:                   Revision 1.6.1.1 2019/07/25 10:22:51CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Update function PortsCheck, move checks into functions
  CHANGES:                   Revision 1.8 2019/07/16 14:18:53CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update PortsCheck function workshop 1:
  CHANGES:                   	- move check to functions
  CHANGES:                   	- move custom masks to main header
  CHANGES:                   	- sync ports position in all debug signals
  CHANGES:                   Revision 1.7 2019/07/10 11:32:58CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update LcfPortsCheck function, add inhibit mechanism for HLA
  CHANGES:                   Revision 1.6 2019/05/30 13:25:54CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.5 2019/05/28 09:36:47CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update wrappers, generic ports check
  CHANGES:                   Revision 1.4 2019/05/10 15:09:16CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   correct the LCF_ErrorEvents_btf setting
  CHANGES:                   Revision 1.3 2019/05/09 21:55:46CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update and fix ports check in wrappers:
  CHANGES:                   	- improve enums with counter of the ports
  CHANGES:                   	- fix the INTFVER defines for CB, HLA and LSD new ports
  CHANGES:                   Revision 1.2 2019/05/06 14:15:25CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   adapt sen wrappers for new GA:
  CHANGES:                   	- 2 new ports: pCbOutputs, pLsdEnvironmentData
  CHANGES:                   Revision 1.1 2019/03/24 17:36:10CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:25CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.2 2019/02/20 14:03:05CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:56:05CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.10 2018/06/07 08:30:10CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   reorganize lcf_xxx_main wrapper files (*.c and *.h)
  CHANGES:                   replace defines for ports check in enums
  CHANGES:                   Revision 1.9 2018/03/27 12:38:37CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.8 2018/03/05 19:11:51CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implement interface headers
  CHANGES:                   Revision 1.7 2018/01/15 15:22:13CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial quick merge with latest wrappers from R7.1
  CHANGES:                   Revision 1.6 2017/12/08 16:21:05CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implemented LCFSEN
  CHANGES:                   Revision 1.5 2017/12/01 17:30:42CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   removed unnecessary headers which led to compile errors in pdo
  CHANGES:                   Revision 1.4 2017/11/01 12:08:16CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.7.1.5.1.8.1.1 2017/09/22 16:07:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for new RTE
  CHANGES:                   Revision 1.7.1.5.1.8 2017/09/06 15:00:09CEST Grosu, George (uidl9584) 
  CHANGES:                   Use Tachometer speed from VDY
  CHANGES:                   Revision 1.7.1.5.1.7 2017/09/05 15:31:06CEST Grosu, George (uidl9584) 
  CHANGES:                   2 more debug signals
  CHANGES:                   Revision 1.7.1.5.1.6 2017/09/05 15:01:45CEST Grosu, George (uidl9584) 
  CHANGES:                   Add TJA debug signal
  CHANGES:                   Revision 1.7.1.5.1.5 2017/08/23 12:26:50CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.7.1.5.1.4 2017/08/16 07:14:25CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.7.1.5.1.3 2017/08/09 15:45:32CEST Grosu, George (uidl9584) 
  CHANGES:                   Merge with MFC431HI28
  CHANGES:                   Revision 1.7.1.5.1.2 2017/08/09 14:56:05CEST Grosu, George (uidl9584) 
  CHANGES:                   New LDPOC
  CHANGES:                   Revision 1.7.1.5.1.1 2017/08/03 14:33:57CEST Grosu, George (uidl9584) 
  CHANGES:                   debug error handler
  CHANGES:                   Revision 1.7.1.5 2017/07/06 16:57:35CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-8
  CHANGES:                   Revision 1.7.1.4 2017/07/05 14:10:37CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-6
  CHANGES:                   Revision 1.7.1.3 2017/06/30 16:07:11CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.7.1.2 2017/06/16 17:11:59CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA2
  CHANGES:                   Revision 1.7.1.1 2017/05/30 13:54:58CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA initial version
  CHANGES:                   Revision 1.8 2017/05/02 12:33:56CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Integration 3.1
  CHANGES:                   Revision 1.7 2017/04/07 19:51:51CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R3.0
  CHANGES:                   Revision 1.6 2017/03/17 13:20:08CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   New LCF algo in preparation for Hyundai R3.0
  CHANGES:                   Revision 1.5 2017/03/07 14:12:06CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   issue 570152: integrate new LCF features (reaction on road edges, LKA dead zone implementation, overall functionality prepared for Hyundai R3.0)
  CHANGES:                   Revision 1.4 2017/02/28 18:31:09CET Grosu, George (uidl9584) 
  CHANGES:                   BugFix for 2.1
  CHANGES:                   Revision 1.3 2017/02/01 12:24:55CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   creation or R2.1 LCF functionality
  CHANGES:                   Revision 1.2 2017/01/18 08:14:35CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Function and performance improvements during 2.0 demo in Korea
  CHANGES:                   Revision 1.1 2016/11/25 12:47:14CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Common includes cleanup.
  CHANGES:                   Revision 1.0 2016/11/03 11:24:59CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/frame_sen/project.pj

  CHANGES:                   Initial revision

**************************************************************************** */

#ifndef lcf_sen_main_h__
#define lcf_sen_main_h__


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lcf_cfg_custom.h"
#include "lcf_ver.h"
#include "lcf_sen_iface.h"
#include "LCFERR/LCFERR_SenCustom.h"
#include "LCFERR/lcferr_sen.h"
#include "LCFERR/ERRIO_SenCustom.h"
#include "LCFERR/errio_sen.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef enum {
	LCFSEN_PROVIDED_PORTS_NULL = (0u),
	ALGO_COMP_STATE_IS_NULL = (1u),
	SEN_OUTPUT_DATA_IS_NULL = (2u),
	SEN_OUTPUT_TO_VEH_DATA_IS_NULL = (3u),
	LCFSEN_PROVIDED_PORTS_COUNTER = (3u) /* Do not forget to update the counter */
} LCFSEN_proPorts_NullCheckFlags_t;

typedef enum {
	LCFSEN_REQUIRED_PORTS_NULL = (0u),
	BASE_CTRL_DATA_CHECK_BIT = (1u),
	ABD_OUTPUT_DATA_CHECK_BIT = (2u),
	CAM_OBJECT_LIST_CHECK_BIT = (3u),
	CPAR_LDP_CHECK_BIT = (4u),
	CPAR_LKA_CHECK_BIT = (5u),
	GEN_OBJECT_LIST_CHECK_BIT = (6u),
	LCF_INPUT_DATA_CHECK_BIT = (7u),
	LCF_LADMC_IUC_TO_SOC_CHECK_BIT = (8u),
	LCF_SEN_INPUT_FROM_VEH_DATA_CHECK_BIT = (9u),
	LCF_VEH_OUTPUT_DATA_CHECK_BIT = (10u),
	VEH_DYN_CHECK_BIT = (11u),
	VEH_PAR_CHECK_BIT = (12u),
	VEH_SIG_CHECK_BIT = (13u),
	CB_OUTPUTS_CHECK_BIT = (14u),
	LSD_ENVIRONMENT_DATA_CHECK_BIT = (15u),
	HLA_RADAR_OBJECT_LIST_CHECK_BIT = (16u),
	LCFSEN_REQUIRED_PORTS_COUNTER = (16u) /* Do not forget to update the counter */
} LCFSEN_reqPorts_NullCheckFlags_t;

typedef enum {
	LCFSEN_SERVICE_PORTS_NULL = (0u),
	MEAS_FREEZE_IS_NULL = (1u),
	DEM_SET_EVENT_STATUS_IS_NULL = (2u),
	DEM_SET_EVENT_STATUS_PRE_EXT_DATA_IS_NULL = (3u),
	RTA_ALGO_SERVICE_ADD_EVENT_IS_NULL = (4u),
	MEAS_START_FUNC_CYCLE_IS_NULL = (5u),
	LCFSEN_SERVICE_PORTS_COUNTER = (5u) /* Do not forget to update the counter */
} LCFSEN_services_NullCheckFlags_t;

typedef enum {
	SERVICE_PORT_IS_NULL_ERRFLAG = (0u),
	PROVIDED_PORT_IS_NULL_ERRFLAG = (1u),
	REQUIRED_PORT_IS_NULL_ERRFLAG = (2u),
	REQUIRED_PORT_INIT_ERRFLAG = (3u),
	REQUIRED_PORT_INVALID_ERRFLAG = (REQUIRED_PORT_INIT_ERRFLAG + LCFSEN_REQUIRED_PORTS_COUNTER), /* When update required port do not forget to update this too (REQUIRED_PORT_INIT_ERRFLAG + REQUIRED_PORTS_COUNTER) */
	REQUIRED_PORT_BAD_VERSION_NUMBER_ERRFLAG = (REQUIRED_PORT_INVALID_ERRFLAG + 1) /* When update required port do not forget to update this too (REQUIRED_PORT_INVALID_ERRFLAG + 1) */
} LCFSEN_ErrFlags_t;

/*****************************************************************************
  MACROS (MASKS FOR PORTS CHECKS)
*****************************************************************************/
/* Defines for invalid signal status and invalid version number */
#define INVALID_INTFVER					(uint32)(0xFFFFFFFFU) /* (4294967295ul) */
#define INVALID_SIG_STATE				(uint8)(0xFFu) /* (255u) */
#define IRRELEVANT_CHECK_BIT			(uint8)(0xFFu) /* (255u) */
#define IGNORE_PORT						((uint8)(0x01u))
#define CHECK_PORT						((uint8)(0x00u))	
/* Macro getters for eSigStatus and uiVersionNumber */
#define GET_SIGNAL_STATUS(rqPort)		(rqPort!=NULL?rqPort->sSigHeader.eSigStatus:INVALID_SIG_STATE)
#define GET_VERSION_NUMBER(rqPort)		(rqPort!=NULL?rqPort->uiVersionNumber:INVALID_INTFVER)	
/* Definition for ErrorHandler signal, to be name independent when changed by ERRHDL component */
#define LCF_ErrorEvents_btf (LCFSEN_ErrorEvents_btf) /* Change value in parenthesis with signal from LCFERR (error handler) */

/* Define positions for ignored required ports */
#if (!defined(USE_IPC_PARAMS) || (USE_IPC_PARAMS == 0))
	#define IGNORE_IPC_PARAMS				(uint32)((1u<<(uint32)CPAR_LDP_CHECK_BIT)|(1u<<(uint32)CPAR_LKA_CHECK_BIT))
#else
	#define IGNORE_IPC_PARAMS				(uint32)(0u)
#endif
#if (!defined(HLA_RADAR_OBJECT_USED) || (HLA_RADAR_OBJECT_USED == 0))
	#define IGNORE_HLA_RADAR_OBJECT			(uint32)(1u<<(uint32)HLA_RADAR_OBJECT_LIST_CHECK_BIT)
#else
	#define IGNORE_HLA_RADAR_OBJECT			(uint32)(0u)
#endif
#if (!defined(LCF_IUC_USED) || (LCF_IUC_USED == 0))
	#define IGNORE_IUC_TO_SOC				(uint32)(1u<<(uint32)LCF_LADMC_IUC_TO_SOC_CHECK_BIT)
#else
	#define IGNORE_IUC_TO_SOC				(uint32)(0u)
#endif

/*Debug for hiding buserror caused by BSW inputs!!!*/
//
#if (!defined(LCF_EMCAM_USED) || (LCF_EMCAM_USED == 0))
	#define IGNORE_EM_CAM_OBJ				(uint32)(1u<<(uint32)CAM_OBJECT_LIST_CHECK_BIT)
#else
	#define IGNORE_EM_CAM_OBJ				(uint32)(0u)
#endif

#if (!defined(LCF_CB_USED) || (LCF_CB_USED == 0))
	#define IGNORE_CB_PRO_OUT				(uint32)(1u<<(uint32)CB_OUTPUTS_CHECK_BIT)
#else
	#define IGNORE_CB_PRO_OUT				(uint32)(0u)
#endif

#if (!defined(LCF_EMGEN_USED) || (LCF_EMGEN_USED == 0))
	#define IGNORE_EM_GEN_OBJ				(uint32)(1u<<(uint32)GEN_OBJECT_LIST_CHECK_BIT)
#else
	#define IGNORE_EM_GEN_OBJ				(uint32)(0u)
#endif

#if (!defined(LCF_LSDENV_USED) || (LCF_LSDENV_USED == 0))
	#define IGNORE_LSD_ENV_DAT				(uint32)(1u<<(uint32)LSD_ENVIRONMENT_DATA_CHECK_BIT)
#else
	#define IGNORE_LSD_ENV_DAT				(uint32)(0u)
#endif	
	
#define IGNORE_SEN_REQPORTS_MASK			(uint32)(~(IGNORE_IPC_PARAMS | IGNORE_HLA_RADAR_OBJECT | IGNORE_IUC_TO_SOC | IGNORE_EM_CAM_OBJ | IGNORE_CB_PRO_OUT | IGNORE_EM_GEN_OBJ | IGNORE_LSD_ENV_DAT))
//
/*Debug for hiding buserror caused by BSW inputs!!!*/

//#define IGNORE_SEN_REQPORTS_MASK			(uint32)(~(IGNORE_IPC_PARAMS | IGNORE_HLA_RADAR_OBJECT | IGNORE_IUC_TO_SOC))    Debug for hiding buserror caused by BSW inputs!!!

#define IGNORE_SEN_PROPORTS_MASK	        (uint16)(~0u) /* Currently there is no optional Provided port for SEN */

/* If the override for these signals are needed, make it in LCF_Custom.h, project specific in "MACROS (CUSTOM MASKS FOR PORTS CHECKS)" section
   In case of these macros override in LCF_Custom.h, be careful not to access ports that are ignored for checking, especially in SyncRef functio */
/* Masks for all ports */
#ifndef LCFSEN_SERVICE_PORTS_NULL_CHECK_MASK
#define LCFSEN_SERVICE_PORTS_NULL_CHECK_MASK					(uint16)((1u<<((uint16)LCFSEN_SERVICE_PORTS_COUNTER+1u))-1u)
#endif

#ifndef LCFSEN_PROVIDED_PORTS_NULL_CHECK_MASK
#define LCFSEN_PROVIDED_PORTS_NULL_CHECK_MASK					(uint16)(((1u<<((uint16)LCFSEN_PROVIDED_PORTS_COUNTER+1u))-1u) & IGNORE_SEN_PROPORTS_MASK)
#endif

#ifndef LCFSEN_REQUIRED_PORTS_NULL_CHECK_MASK
#define LCFSEN_REQUIRED_PORTS_NULL_CHECK_MASK					(uint32)(((1u<<(uint32)((uint32)LCFSEN_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_SEN_REQPORTS_MASK)
#endif

#ifndef LCFSEN_REQUIRED_PORTS_SIGST_CHECK_MASK
#define LCFSEN_REQUIRED_PORTS_SIGST_CHECK_MASK					(uint32)(((1u<<((uint32)LCFSEN_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_SEN_REQPORTS_MASK)
#endif

#ifndef LCFSEN_REQUIRED_PORTS_VERNUM_CHECK_MASK
#define LCFSEN_REQUIRED_PORTS_VERNUM_CHECK_MASK					(uint32)(((1u<<((uint32)LCFSEN_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_SEN_REQPORTS_MASK)
#endif

/* Masks for BaseCtrlData */
#ifndef LCFSEN_BASECTRLDATA_CHECK_MASK
#define LCFSEN_BASECTRLDATA_CHECK_MASK							(uint32)(1u<<(uint32)BASE_CTRL_DATA_CHECK_BIT)
#endif

/* Masks for Error Handler flags, in case of SignalStatus == Init OR SignalStatus == Invalid */
#ifndef LCFSEN_REQUIRED_PORTS_SIGSTATUS_INIT_MASK
#define LCFSEN_REQUIRED_PORTS_SIGSTATUS_INIT_MASK				(uint32)(((1u<<((uint32)LCFSEN_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_SEN_REQPORTS_MASK)
#endif

#ifndef LCFSEN_REQUIRED_PORTS_SIGSTATUS_INVALID_MASK
#define LCFSEN_REQUIRED_PORTS_SIGSTATUS_INVALID_MASK			(uint32)(((1u<<((uint32)LCFSEN_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_SEN_REQPORTS_MASK)
#endif

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/
/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* lcf_sen_main_h__ */



