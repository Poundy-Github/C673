/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_veh_iface.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.11 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_veh_iface.h  $
  CHANGES:                   Revision 1.11 2020/02/21 12:50:15CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.9 2020/01/23 08:19:02CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updated files after removing some QAF warnings
  CHANGES:                   Revision 1.8 2019/11/29 08:46:39CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF code for new auxCodeGen 4.1
  CHANGES:                   Revision 1.7 2019/11/26 16:20:58CET Grosu, George (uidl9584) 
  CHANGES:                   bring LCFERR changes to trunk
  CHANGES:                   Revision 1.6 2019/08/21 13:11:54CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.5 2019/07/30 10:04:11CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.4 2019/07/26 07:46:43CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   follow up foe LCF workshop 1:
  CHANGES:                   	- Correct commens in the function headers
  CHANGES:                   	- add IPC protection for VEH cpar's
  CHANGES:                   	- Review comments for the Input checks Debug signals in iface header
  CHANGES:                   Revision 1.3 2019/07/17 12:10:35CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for Sprint 05.10.04
  CHANGES:                   Revision 1.2 2019/05/10 12:13:04CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Switch to ID's from RTA_t_GlobalIDs
  CHANGES:                   Revision 1.1 2019/03/24 17:36:40CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:28CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.2 2019/02/20 14:03:06CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:56:07CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.9 2018/08/02 14:01:11CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint17
  CHANGES:                   Revision 1.8 2018/06/29 13:43:46CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint15 - Round1
  CHANGES:                   Revision 1.7 2018/06/25 14:01:41CEST Grosu, George (uidl9584) 
  CHANGES:                   Update enum definition for RTA Analysis
  CHANGES:                   Revision 1.6 2018/06/11 16:30:35CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   check-in for sprint14
  CHANGES:                   Revision 1.5 2018/05/21 13:21:30CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint12
  CHANGES:                   Revision 1.4 2018/03/27 12:49:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.3 2018/03/16 12:55:04CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Updated for 8.2 RTE
  CHANGES:                   Revision 1.2 2018/03/05 19:11:47CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implement interface headers

**************************************************************************** */

#ifndef lcf_veh_iface_h__
#define lcf_veh_iface_h__

/*! @defgroup lcf_wrp LCF RTE Wrapper 

LCF wrapper converts RTE types to LCF interface types and vice versa

@{ */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* Include global architecture headers*/
#include <string.h> /* Library function needed */
#include "algo_glob.h"
#include "RTA_GlobalIDs.h"
#include "lcf_veh_ext.h"
#include "lcf_veh_cfg.h"

/* Includes for data types*/
#include "DMC_Soc_types.h"
#include "LCFVEH/LCFVEH_type.h"
#include "LCFERR/LCFERR_VehCustom.h"/* lcferr.h cannot include both LCFERR_SenCustom.h and LCFERR_VehCustom.h*/
#include "LCFERR/lcferr.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/

/* maximum number of errors that can be saved in the corresponding debug variables */
#define   NUM_DEBUG_ERR_POS_NORM    128u
#define   NUM_DEBUG_ERR_POS_VDY       8u
#define   NUM_DEBUG_ERR_POS_VSA       8u
#define   NUM_DEBUG_ERR_POS_VSM       8u
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* Enum type with RTA events in LCF_VEH component 
 * To interpret these RTA events please keep
 * \05_Testing\MTS\mts_measurement\cfg\LCF\RTA_ID_LCF_VEH.xml
 * up-to-date.
 */

 /*RTA events for LCF VEH*/
typedef enum {
	LCF_VEH_DRVMN,
	LCF_VEH_TRJPLN,
	LCF_VEH_TRJCTR,
	LCF_VEH_v1TRJCTR,
	LCF_VEH_LATDMC,
	LCF_VEH_DDROC,
	LCF_VEH_MEASF,
	LCF_VEH_TOTAL
} LCF_VEH_t_RTAEvents;

typedef struct {

    /* BitField Integer containing Ports check status */
    uint16 D_LCFVEH_proPorts_NullStatusCheck; /* Zero (0) means that corresponding port is not NULL */
    uint16 D_LCFVEH_reqPorts_NullStatusCheck; /* Zero (0) means that corresponding port is not NULL */
    uint16 D_LCFVEH_services_NullStatusCheck; /* Zero (0) means that corresponding port is not NULL */
    uint16 D_LCFVEH_reqPorts_SignalStatusOk; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK */
    uint16 D_LCFVEH_reqPorts_SignalStatusInit; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
    uint16 D_LCFVEH_reqPorts_SignalStatusInvalid; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
    uint16 D_LCFVEH_reqPorts_VersionNumberCheck; /* Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h */
  	uint8 uiTunParCopied;  
    uint8 uiVdyParCopied;
    uint8 uiNvmDataValid;
    uint8 reserved;// for 4bytes alignment

} FRAME_VehDbgType;

typedef struct {
    /*Error Handler */
    uint32 D_LCFERR_ErrorConfirmedNorm_btf[NUM_DEBUG_ERR_POS_NORM/32u];
    LCFERR_RingBufferType_t D_LCFERR_ErrBuff;
    uint32 D_LCFERR_RngChkDbg_btf[8];/* GeGr: 6 used, 2 reserved */
    uint16 D_LCFERR_AlliveFailedTSMon_btf;
    uint16 D_LCFERR_AlliveFailedTSBcd_btf;
    uint16 D_LCFERR_AlliveFailedMC_btf;
    uint16 D_LCFERR_AlliveFailedCCMon_btf;
    uint16 D_LCFERR_AlliveFailedCCConst_btf;
    uint8 D_LCFERR_ErrorConfirmedVDY_btf;
    uint8 D_LCFERR_ErrorConfirmedVSA_btf;
    uint8 D_LCFERR_ErrorConfirmedVSM_btf;
    uint8 D_LCFERR_FFtb[3][10];
	  uint8 D_LCFERR_AlgoCompState;
	  uint8 D_LCFERR_VehOutSigStatus;
	  uint8 D_LCFERR_Veh2SenSigStatus;
	  uint8 D_LCFERR_Soc2IucSigStatus;
	  uint8 D_LCFERR_DemEvents_btf;
    uint8 D_ERRIOVEH_ErrStateArray[12];
	
} LCFERR_VehDbgType;

/*! Type definition for Debug data to be meas freezed */
typedef struct 
{  
#ifdef _LCF_VEHDBGTYPE_T_
	LCF_VehDbgType LCF_pstVehDbgData;
#endif /* _LCF_VEHDBGTYPE_T_*/
	
	FRAME_VehDbgType FRAME_VehDbgData;
	
	LCFERR_VehDbgType LCFERR_VehDbgData;

	LaDMC_DebugBus_Type LaDMC_DbgData;
    
	/*Surpress QAC Messages (next line): Number of members in 'struct' or 'union' exceeds 127 - program does not conform strictly to ISO:C90.
	All members of the structure are necessary*/
	/*PRQA S 639 1  */
} LCF_VehDebugData_t; /*!< @vaddr:0x32120000 @vaddr_defs: LCF_MEAS_ID_DEBUG_VEH   @cycleid:LCF_VEH_ENV_PVT @vname:pLcfVehDebugData   */

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/
extern const reqLcfVehPrtList_t *pLcfVehReqPorts;
extern const AS_t_ServiceFuncts *pLcfVehServices;
extern proLcfVehPrtList_t *pLcfVehProPorts;
extern FRAME_VehDbgType* const pFRAME_VehDbgData;
extern LCFERR_VehDbgType* const pLCFERR_VehDbgData;
extern LaDMC_DebugBus_Type* const pLaDMC_DbgData;
extern NVM_LcfLearningData_t *pNvmLcfInfo; /*Internal buffer of NVM data*/

/*MiCr: add definition of BitField, only to remove misra warnings */
/* BitField Integer containing Ports check status */
extern uint16 LCFVEH_proPorts_NullStatusCheck;
extern uint16 LCFVEH_reqPorts_NullStatusCheck;
extern uint16 LCFVEH_services_NullStatusCheck;
extern uint16 LCFVEH_reqPorts_SignalStatusOk; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK*/
extern uint16 LCFVEH_reqPorts_SignalStatusInit; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
extern uint16 LCFVEH_reqPorts_SignalStatusInvalid; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
extern uint16 LCFVEH_reqPorts_VersionNumberCheck; /*Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h*/
/* Create SyncRef structure and fill uiVersionNumber */
extern LcfVeh_SyncRef_t LcfVeh_SyncRef;

/*Temporary workaround*/
#ifndef LCF_NUM_ELEM_ADP_CORR_ARR
#define LCF_NUM_ELEM_ADP_CORR_ARR  20u /*TODO: it's better to place this define in RTE excel (sheets NVM_LcfLearningData and Static Variables)*/
#endif
extern uint16 ui16_nvmLcfInfo_AdpCorrCounterPos_nu[LCF_NUM_ELEM_ADP_CORR_ARR];
extern uint16 ui16_nvmLcfInfo_AdpCorrCounterNeg_nu[LCF_NUM_ELEM_ADP_CORR_ARR];
/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* lcf_veh_iface_h__ */

/** @} end defgroup */

