/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_veh_main.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.3.1.8 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_veh_main.h  $
  CHANGES:                   Revision 1.3.1.8 2020/02/21 12:50:16CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.3.1.6 2020/01/23 08:19:03CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updated files after removing some QAF warnings
  CHANGES:                   Revision 1.3.1.5 2019/09/12 13:42:04CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrappers bugs:
  CHANGES:                   - signal headers LCF outputs are now set to StateOK in Running
  CHANGES:                   - use of IPCParams is safeguarded
  CHANGES:                   - corrected masks for PortCheck
  CHANGES:                   Revision 1.3.1.4 2019/08/21 13:11:55CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.3.1.3 2019/07/30 10:04:12CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.3.1.2 2019/07/26 07:46:43CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   follow up foe LCF workshop 1:
  CHANGES:                   	- Correct commens in the function headers
  CHANGES:                   	- add IPC protection for VEH cpar's
  CHANGES:                   	- Review comments for the Input checks Debug signals in iface header
  CHANGES:                   Revision 1.3.1.1 2019/07/25 10:24:44CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Update function PortsCheck, move checks into functions
  CHANGES:                   Revision 1.5 2019/07/16 14:18:53CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update PortsCheck function workshop 1:
  CHANGES:                   	- move check to functions
  CHANGES:                   	- move custom masks to main header
  CHANGES:                   	- sync ports position in all debug signals
  CHANGES:                   Revision 1.4 2019/07/10 11:32:59CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update LcfPortsCheck function, add inhibit mechanism for HLA
  CHANGES:                   Revision 1.3 2019/05/30 13:25:57CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.2 2019/05/28 09:36:46CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update wrappers, generic ports check
  CHANGES:                   Revision 1.1 2019/03/24 17:36:40CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:29CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.2 2019/02/20 14:03:08CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:56:08CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.16 2018/06/07 08:30:09CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   reorganize lcf_xxx_main wrapper files (*.c and *.h)
  CHANGES:                   replace defines for ports check in enums
  CHANGES:                   Revision 1.15 2018/03/27 12:49:47CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.14 2018/03/05 19:11:48CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implement interface headers
  CHANGES:                   Revision 1.13 2018/02/28 13:06:46CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   MFC431 R8.0/R8.1 bugfix5
  CHANGES:                   Revision 1.12 2018/02/02 12:45:01CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   MFC431 R8.0 bugfix2 - round 3 (fix pdo tags include, use LaDMC for TA19)
  CHANGES:                   Revision 1.11 2018/01/26 12:26:50CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Rework of LatDMC wrapper
  CHANGES:                   Revision 1.10 2017/12/22 10:02:18CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   R8.0 update
  CHANGES:                   Revision 1.8 2017/12/08 16:21:09CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implemented LCFSEN
  CHANGES:                   Revision 1.7 2017/12/04 15:59:02CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   - removed debug signal arrays from TRJPLN
  CHANGES:                   - integrated crash free CP of TJASA
  CHANGES:                   - add LCF_VehDbgData to veh debug structure
  CHANGES:                   Revision 1.6 2017/11/29 11:21:32CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   compile error fixes
  CHANGES:                   Revision 1.4 2017/11/01 12:08:05CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.2.2.2 2017/06/30 16:07:23CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.2.2.1 2017/06/16 17:11:56CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA2
  CHANGES:                   Revision 1.4.1.1 2017/05/29 10:09:21CEST Grosu, George (uidl9584) 
  CHANGES:                   code from Demo in Korea 26.05.2017
  CHANGES:                   Revision 1.2.1.1 2017/04/07 19:51:49CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R3.0
  CHANGES:                   Revision 1.2 2017/02/01 12:24:51CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   creation or R2.1 LCF functionality
  CHANGES:                   Revision 1.1 2016/11/25 12:50:02CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Common includes cleanup.
  CHANGES:                   Revision 1.0 2016/11/03 11:25:29CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/frame_veh/project.pj
  CHANGES:                   Initial revision

**************************************************************************** */

#ifndef lcf_veh_main_h__
#define lcf_veh_main_h__

/*! @defgroup lcf_wrp LCF RTE Wrapper 

LCF wrapper converts RTE types to LCF interface types and vice versa

@{ */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lcf_cfg_custom.h"
#include "lcf_ver.h"
#include "lcf_veh_iface.h"
#include "LCFERR/LCFERR_VehCustom.h"
#include "LCFERR/lcferr_veh.h"
#include "LCFERR/ERRIO_VehCustom.h"
#include "LCFERR/errio_veh.h"

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
	LCFVEH_PROVIDED_PORTS_NULL = (0u),
	ALGO_COMP_STATE_IS_NULL = (1u),
	LCF_LADMC_SOC_TO_IUC_IS_NULL = (2u),
	VEH_OUTPUT_DATA_IS_NULL = (3u),
	VEH_OUTPUT_TO_SEN_DATA_IS_NULL = (4u),
	NVM_LCF_LEARNING_DATA_IS_NULL = (5u),
	LCFVEH_PROVIDED_PORTS_COUNTER = (5u) /* Do not forget to update the counter */
} LCFVEH_proPorts_NullCheckFlags_t;

typedef enum {
	LCFVEH_REQUIRED_PORTS_NULL = (0u),
	BASE_CTRL_DATA_CHECK_BIT = (1u),
	ABD_OUTPUT_DATA_CHECK_BIT = (2u),
	CPAR_DMC_CHECK_BIT = (3u),
	CPAR_KMC_CHECK_BIT = (4u),
	LCF_INPUT_DATA_CHECK_BIT = (5u),
	LCF_LADMC_IUC_TO_SOC_CHECK_BIT = (6u),
	LCF_SEN_OUTPUT_DATA_CHECK_BIT = (7u),
	LCF_VEH_INPUT_FROM_SEN_DATA_CHECK_BIT = (8u),
	NVM_LCF_DATA_CHECK_BIT = (9u),
	VDY_OFFSETS_CHECK_BIT = (10u),
	VEH_DYN_CHECK_BIT = (11u),
	VEH_PAR_CHECK_BIT = (12u),
	VEH_SIG_CHECK_BIT = (13u),
	LCFVEH_REQUIRED_PORTS_COUNTER = (13u) /* Do not forget to update the counter */
} LCFVEH_reqPorts_NullCheckFlags_t;
	
typedef enum {
	LCFVEH_SERVICE_PORTS_NULL = (0u),
	MEAS_FREEZE_IS_NULL = (1u),
	DEM_SET_EVENT_STATUS_IS_NULL = (2u),
	DEM_SET_EVENT_STATUS_PRE_EXT_DATA_IS_NULL = (3u),
	RTA_ALGO_SERVICE_ADD_EVENT_IS_NULL = (4u),
	MEAS_START_FUNC_CYCLE_IS_NULL = (5u),
	LCFVEH_SERVICE_PORTS_COUNTER = (5u) /* Do not forget to update the counter */
} LCFVEH_services_NullCheckFlags_t;

typedef enum {
	SERVICE_PORT_IS_NULL_ERRFLAG = (0u),
	PROVIDED_PORT_IS_NULL_ERRFLAG = (1u),
	REQUIRED_PORT_IS_NULL_ERRFLAG = (2u),
	REQUIRED_PORT_INIT_ERRFLAG = (3u),
	REQUIRED_PORT_INVALID_ERRFLAG = (REQUIRED_PORT_INIT_ERRFLAG + LCFVEH_REQUIRED_PORTS_COUNTER), /* When update required port do not forget to update this too (REQUIRED_PORT_INIT_ERRFLAG + REQUIRED_PORTS_COUNTER) */
	REQUIRED_PORT_BAD_VERSION_NUMBER_ERRFLAG = (REQUIRED_PORT_INVALID_ERRFLAG + 1u) /* When update required port do not forget to update this too (REQUIRED_PORT_INVALID_ERRFLAG + 1) */
} LCFVEH_ErrFlags_t;	
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
#define LCF_ErrorEvents_btf (LCFVEH_ErrorEvents_btf) /* Change value in parenthesis with signal from LCFERR (error handler) */

/* Define positions for ignored required ports */
#if (!defined(USE_IPC_PARAMS) || (USE_IPC_PARAMS == 0))
	#define IGNORE_IPC_PARAMS				(uint16)((1u<<(uint16)CPAR_DMC_CHECK_BIT)|(1u<<(uint16)CPAR_KMC_CHECK_BIT))
#else
	#define IGNORE_IPC_PARAMS				(uint16)(0u)
#endif
#if (!defined(LCF_NVM_USED) || (LCF_NVM_USED == 0))
	#define IGNORE_RNVM_LCF_DATA				(uint16)(1u<<(uint16)NVM_LCF_DATA_CHECK_BIT)
#else
	#define IGNORE_RNVM_LCF_DATA				(uint16)(0u)
#endif
#if (!defined(LCF_IUC_USED) || (LCF_IUC_USED == 0))
	#define IGNORE_IUC_TO_SOC				(uint16)(1u<<(uint16)LCF_LADMC_IUC_TO_SOC_CHECK_BIT)
#else
	#define IGNORE_IUC_TO_SOC				(uint16)(0u)
#endif

#define IGNORE_VEH_REQPORTS_MASK			(uint16)(~(IGNORE_IPC_PARAMS | IGNORE_RNVM_LCF_DATA | IGNORE_IUC_TO_SOC))

/* Define positions for ignored provided ports */
#if (!defined(LCF_IUC_USED) || (LCF_IUC_USED == 0))
	#define IGNORE_SOC_TO_IUC				(uint16)(1u<<(uint16)LCF_LADMC_SOC_TO_IUC_IS_NULL)
#else
	#define IGNORE_SOC_TO_IUC				(uint16)(0u)
#endif
#if (!defined(LCF_NVM_USED) || (LCF_NVM_USED == 0))
	#define IGNORE_PNVM_LCF_DATA				(uint16)(1u<<(uint16)NVM_LCF_LEARNING_DATA_IS_NULL)
#else
	#define IGNORE_PNVM_LCF_DATA				(uint16)(0u)
#endif

#define IGNORE_VEH_PROPORTS_MASK			(uint16)(~(IGNORE_PNVM_LCF_DATA | IGNORE_SOC_TO_IUC))

/* If the override for these signals are needed, make it in LCF_Custom.h, project specific in "MACROS (CUSTOM MASKS FOR PORTS CHECKS)" section
   In case of these macros override in LCF_Custom.h, be careful not to access ports that are ignored for checking, especially in SyncRef functio */
/* Masks for all ports */
#ifndef LCFVEH_SERVICE_PORTS_NULL_CHECK_MASK
#define LCFVEH_SERVICE_PORTS_NULL_CHECK_MASK					(uint16)((1u<<((uint16)LCFVEH_SERVICE_PORTS_COUNTER+1u))-1u)
#endif

#ifndef LCFVEH_PROVIDED_PORTS_NULL_CHECK_MASK
#define LCFVEH_PROVIDED_PORTS_NULL_CHECK_MASK					(uint16)(((1u<<((uint16)LCFVEH_PROVIDED_PORTS_COUNTER+1u))-1u) & IGNORE_VEH_PROPORTS_MASK)
#endif

#ifndef LCFVEH_REQUIRED_PORTS_NULL_CHECK_MASK
#define LCFVEH_REQUIRED_PORTS_NULL_CHECK_MASK					(uint16)(((1u<<(uint16)((uint16)LCFVEH_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_VEH_REQPORTS_MASK)
#endif

#ifndef LCFVEH_REQUIRED_PORTS_SIGST_CHECK_MASK
#define LCFVEH_REQUIRED_PORTS_SIGST_CHECK_MASK					(uint16)(((1u<<((uint16)LCFVEH_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_VEH_REQPORTS_MASK)
#endif

#ifndef LCFVEH_REQUIRED_PORTS_VERNUM_CHECK_MASK
#define LCFVEH_REQUIRED_PORTS_VERNUM_CHECK_MASK					(uint16)(((1u<<((uint16)LCFVEH_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_VEH_REQPORTS_MASK)
#endif

/* Masks for BaseCtrlData */
#ifndef LCFVEH_BASECTRLDATA_CHECK_MASK
#define LCFVEH_BASECTRLDATA_CHECK_MASK							(uint16)(1u<<(uint16)BASE_CTRL_DATA_CHECK_BIT)
#endif

/* Masks for NvmLcfData */
#ifndef LCFVEH_NVM_LCF_DATA_CHECK_MASK
#define LCFVEH_NVM_LCF_DATA_CHECK_MASK							(uint16)((1u<<(uint16)NVM_LCF_DATA_CHECK_BIT) & IGNORE_VEH_REQPORTS_MASK)
#endif

/* Masks for Error Handler flags, in case of SignalStatus == Init OR SignalStatus == Invalid */
#ifndef LCFVEH_REQUIRED_PORTS_SIGSTATUS_INIT_MASK
#define LCFVEH_REQUIRED_PORTS_SIGSTATUS_INIT_MASK				(uint16)(((1u<<((uint16)LCFVEH_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_VEH_REQPORTS_MASK)
#endif

#ifndef LCFVEH_REQUIRED_PORTS_SIGSTATUS_INVALID_MASK
#define LCFVEH_REQUIRED_PORTS_SIGSTATUS_INVALID_MASK			(uint16)(((1u<<((uint16)LCFVEH_REQUIRED_PORTS_COUNTER+1u))-1u) & IGNORE_VEH_REQPORTS_MASK)
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

#endif /* lcf_veh_main_h__ */


