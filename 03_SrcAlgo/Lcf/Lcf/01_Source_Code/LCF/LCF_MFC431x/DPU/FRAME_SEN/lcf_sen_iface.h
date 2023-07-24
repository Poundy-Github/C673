/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 lcf_sen_iface.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.11 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_sen_iface.h  $
  CHANGES:                   Revision 1.11 2020/07/16 18:53:33CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   new updates
  CHANGES:                   Revision 1.10 2020/02/21 12:50:05CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.8 2020/01/23 08:18:46CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updated files after removing some QAF warnings
  CHANGES:                   Revision 1.7 2019/11/29 08:46:38CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF code for new auxCodeGen 4.1
  CHANGES:                   Revision 1.6 2019/11/26 16:20:59CET Grosu, George (uidl9584) 
  CHANGES:                   bring LCFERR changes to trunk
  CHANGES:                   Revision 1.5 2019/07/30 10:04:14CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.4 2019/07/26 07:46:45CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   follow up foe LCF workshop 1:
  CHANGES:                   	- Correct commens in the function headers
  CHANGES:                   	- add IPC protection for VEH cpar's
  CHANGES:                   	- Review comments for the Input checks Debug signals in iface header
  CHANGES:                   Revision 1.3 2019/05/10 12:13:07CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Switch to ID's from RTA_t_GlobalIDs
  CHANGES:                   Revision 1.2 2019/05/06 14:15:24CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   adapt sen wrappers for new GA:
  CHANGES:                   	- 2 new ports: pCbOutputs, pLsdEnvironmentData
  CHANGES:                   Revision 1.1 2019/03/24 17:36:10CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:25CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.2 2019/02/20 14:03:03CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:56:04CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.8 2018/08/05 18:09:17CEST Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals for ERR
  CHANGES:                   Revision 1.7 2018/06/29 13:43:47CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint15 - Round1
  CHANGES:                   Revision 1.6 2018/06/25 14:01:42CEST Grosu, George (uidl9584) 
  CHANGES:                   Update enum definition for RTA Analysis
  CHANGES:                   Revision 1.5 2018/06/25 13:36:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Update value for LCF_MEAS_ID_DEBUG_SEN according to Rte_Algo_Type.h -> 0x32208000
  CHANGES:                   Revision 1.4 2018/04/19 09:39:07CEST Grosu, George (uidl9584) 
  CHANGES:                   8.2 Initial Revision
  CHANGES:                   Revision 1.3 2018/03/27 12:38:35CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.2 2018/03/05 19:11:51CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implement interface headers

**************************************************************************** */

#ifndef lcf_sen_iface_h__
#define lcf_sen_iface_h__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* Include global architecture headers*/
#include <string.h> /* Library function needed */
#include "algo_glob.h"
#include "RTA_GlobalIDs.h"
#include "lcf_sen_ext.h"
#include "lcf_sen_cfg.h"

/* Includes for data types*/
#include "LCFSEN/LCFSEN_type.h"
#include "LCFERR/LCFERR_SenCustom.h" /* lcferr.h cannot include both LCFERR_SenCustom.h and LCFERR_VehCustom.h*/
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
/* Enum type with RTA events in LCF_SEN component 
 * To interpret these RTA events please keep
 * \05_Testing\MTS\mts_measurement\cfg\LCF\RTA_ID_LCF_SEN.xml
 * up-to-date. 
 */
 
/* RTA_LOCAL_ID_FOR_XML_GENERATION */
typedef enum {
  LCF_SEN_ABPR,
  LCF_SEN_v1ABPR,
  LCF_SEN_v2ABPR,
  LCF_SEN_ODPR,
  LCF_SEN_v1ODPR,
  LCF_SEN_v2ODPR,
  LCF_SEN_VDPR,
  LCF_SEN_LTASA,
  LCF_SEN_TMCSCT,
  LCF_SEN_LCOSCT,
  LCF_SEN_SAICSCT,
  LCF_SEN_SGMWSCT,
  LCF_SEN_BYDSCT,
  LCF_SEN_LDPSA,
  LCF_SEN_ALCASA,
  LCF_SEN_LDPOCSA,
  LCF_SEN_v1LDPOCSA,
  LCF_SEN_RDPSA,
  LCF_SEN_v1RDPSA,
  LCF_SEN_TJASA,
  LCF_SEN_v1TJASA,
  LCF_SEN_v2TJASA,
  LCF_SEN_LKASA,
  LCF_SEN_LDWSA,
  LCF_SEN_MDCTR,
  LCF_SEN_CTRSC,
  LCF_SEN_HMIOC,
  LCF_SEN_MEASF,
  LCF_SEN_TOTAL
} LCF_SEN_t_RTAEvents;

typedef struct {

    
    /* BitField Integer containing Ports check status */
    uint16 D_LCFSEN_proPorts_NullStatusCheck; /* Zero (0) means that corresponding port is not NULL */
    uint16 reserved1;// for 4 bytes alignment
    uint32 D_LCFSEN_reqPorts_NullStatusCheck; /* Zero (0) means that corresponding port is not NULL */
    uint16 D_LCFSEN_services_NullStatusCheck; /* Zero (0) means that corresponding port is not NULL */
    uint16 reserved2;// for 4 bytes alignment
    uint32 D_LCFSEN_reqPorts_SignalStatusOk; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK */
    uint32 D_LCFSEN_reqPorts_SignalStatusInit; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
    uint32 D_LCFSEN_reqPorts_SignalStatusInvalid; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
    uint32 D_LCFSEN_reqPorts_VersionNumberCheck; /* Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h */

	
    uint8 uiTunParCopied;
    uint8 uiVdyParCopied; 
} FRAME_SenDbgType;

typedef struct {    
	/*Error Handler */
    uint32 D_LCFERR_ErrorConfirmedNorm_btf[NUM_DEBUG_ERR_POS_NORM/32u];
    uint8 D_LCFERR_ErrorConfirmedVDY_btf;
    uint8 D_LCFERR_ErrorConfirmedVSA_btf;
    uint8 D_LCFERR_ErrorConfirmedVSM_btf;
    uint8 reserved1;//for 4 bytes alignment
    uint16 D_LCFERR_AlliveFailedTSMon_btf;
    uint16 D_LCFERR_AlliveFailedTSBcd_btf;
    uint16 D_LCFERR_AlliveFailedMC_btf;
    uint16 D_LCFERR_AlliveFailedCCMon_btf;
    uint16 D_LCFERR_AlliveFailedCCConst_btf;
    uint16 reserved2;//4 bytes alignment
    
    LCFERR_RingBufferType_t D_LCFERR_ErrBuff;
    uint8 D_LCFERR_FFtb[3][10];
	uint8 D_LCFERR_AlgoCompState;
	uint8 D_LCFERR_SenOutSigStatus;
	uint8 D_LCFERR_Sen2VehSigStatus;
	uint8 D_LCFERR_DemEvents_btf;
  uint8 reserved3[2];// for 4 bytes alignment
	uint8 D_ERRIOSEN_ErrStateArray[12];
	uint32 D_LCFERR_RngChkDbg_btf[8];/* GeGr: 6 used, 2 reserved */
} LCFERR_SenDbgType;

/*! Type definition for Debug data to be meas freezed */
typedef struct 
{
#ifdef _LCF_SENDBGTYPE_T_
	LCF_SenDbgType	LCF_stSenDbgData;
#endif /* _LCF_SENDBGTYPE_T_*/
	
	FRAME_SenDbgType FRAME_SenDbgData;
    
    /*Error Handler */
	LCFERR_SenDbgType LCFERR_SenDbgData;
    
	/*Surpress QAC Messages (next line): Number of members in 'struct' or 'union' exceeds 127 - program does not conform strictly to ISO:C90.
	All members of the structure are necessary*/
	/*PRQA S 639 1*/  
} LCF_SenDebugData_t; /*!< @vaddr:0x32208000 @vaddr_defs: LCF_MEAS_ID_DEBUG_SEN   @cycleid:LCF_SEN_ENV_PVT @vname:pLcfSenDebugData   */

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/

extern const reqLcfSenPrtList_t *pLcfSenReqPorts;
extern const AS_t_ServiceFuncts *pLcfSenServices;
extern proLcfSenPrtList_t *pLcfSenProPorts;
extern  FRAME_SenDbgType* const  pFRAME_SenDbgData;
extern LCFERR_SenDbgType* const pLCFERR_SenDbgData;
/* MiCr:add definition of BitField here, only to remove misra warnings */
/* Create SyncRef structure and fill uiVersionNumber */
extern LcfSen_SyncRef_t LcfSen_SyncRef;
/* BitField Integer containing Ports check status */
extern uint16 LCFSEN_proPorts_NullStatusCheck;
extern uint32 LCFSEN_reqPorts_NullStatusCheck;
extern uint16 LCFSEN_services_NullStatusCheck;
extern uint32 LCFSEN_reqPorts_SignalStatusOk; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK*/
extern uint32 LCFSEN_reqPorts_SignalStatusInit; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
extern uint32 LCFSEN_reqPorts_SignalStatusInvalid; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
extern uint32 LCFSEN_reqPorts_VersionNumberCheck; /*Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h*/

/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* lcf_sen_iface_h__ */

/** @} end defgroup */

