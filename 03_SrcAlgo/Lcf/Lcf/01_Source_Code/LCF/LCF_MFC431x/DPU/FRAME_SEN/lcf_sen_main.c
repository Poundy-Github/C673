/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_sen_main.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.8.1.14 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_sen_main.c  $
  CHANGES:                   Revision 1.8.1.14 2020/02/21 12:50:06CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.8.1.12 2020/01/29 13:44:05CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate new updates
  CHANGES:                   Revision 1.8.1.11 2020/01/23 08:18:46CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updated files after removing some QAF warnings
  CHANGES:                   Revision 1.8.1.10 2019/12/06 08:34:32CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Send DEM fussi error from main function when the required ports are NULL
  CHANGES:                   Revision 1.8.1.9 2019/10/18 16:09:41CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files after code gen
  CHANGES:                   Revision 1.8.1.8 2019/09/25 14:23:46CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint 10.09
  CHANGES:                   Revision 1.8.1.7 2019/09/12 13:42:52CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrappers bugs:
  CHANGES:                   - signal headers LCF outputs are now set to StateOK in Running
  CHANGES:                   - use of IPCParams is safeguarded
  CHANGES:                   - corrected masks for PortCheck
  CHANGES:                   Revision 1.8.1.6 2019/08/21 13:11:56CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.8.1.5 2019/08/01 13:19:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Move call of FillSyncRef to Running OpMode
  CHANGES:                   Revision 1.8.1.4 2019/07/30 10:04:13CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.8.1.3 2019/07/26 07:46:45CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   follow up foe LCF workshop 1:
  CHANGES:                   	- Correct commens in the function headers
  CHANGES:                   	- add IPC protection for VEH cpar's
  CHANGES:                   	- Review comments for the Input checks Debug signals in iface header
  CHANGES:                   Revision 1.8.1.2 2019/07/25 10:22:50CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Update function PortsCheck, move checks into functions
  CHANGES:                   Revision 1.12 2019/07/17 12:19:13CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update workshop 1:
  CHANGES:                   	- move check to functions
  CHANGES:                   	- move custom masks to main header
  CHANGES:                   	- sync ports position in all debug signals
  CHANGES:                   Revision 1.10 2019/07/10 11:32:58CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update LcfPortsCheck function, add inhibit mechanism for HLA
  CHANGES:                   Revision 1.9 2019/06/25 12:29:21CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Fixed compiler warnings
  CHANGES:                   Revision 1.8 2019/05/30 13:25:53CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.7 2019/05/28 09:36:47CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update wrappers, generic ports check
  CHANGES:                   Revision 1.4 2019/05/10 15:09:15CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   correct the LCF_ErrorEvents_btf setting
  CHANGES:                   Revision 1.3 2019/05/09 21:55:45CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update and fix ports check in wrappers:
  CHANGES:                   	- improve enums with counter of the ports
  CHANGES:                   	- fix the INTFVER defines for CB, HLA and LSD new ports
  CHANGES:                   Revision 1.2 2019/05/06 14:15:24CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   adapt sen wrappers for new GA:
  CHANGES:                   	- 2 new ports: pCbOutputs, pLsdEnvironmentData
  CHANGES:                   Revision 1.1 2019/03/24 17:36:10CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:25CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.2 2019/02/20 14:03:04CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:56:05CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.27 2018/06/29 13:43:47CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint15 - Round1
  CHANGES:                   Revision 1.26 2018/06/07 08:30:11CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   reorganize lcf_xxx_main wrapper files (*.c and *.h)
  CHANGES:                   replace defines for ports check in enums
  CHANGES:                   Revision 1.25 2018/05/24 13:07:00CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.24 2018/05/23 12:55:40CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.23 2018/05/18 17:08:24CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Update wrappers to meet requirement L3D_ALGO_22428
  CHANGES:                   Revision 1.19 2018/05/11 09:05:47CEST Grosu, George (uidl9584) 
  CHANGES:                   Error Handler v1
  CHANGES:                   Revision 1.18 2018/05/10 12:31:05CEST Grosu, George (uidl9584) 
  CHANGES:                   First version of LCFERR
  CHANGES:                   Revision 1.17 2018/04/20 09:27:57CEST Grosu, George (uidl9584) 
  CHANGES:                   Do not use IUC yet
  CHANGES:                   Revision 1.16 2018/04/19 15:52:52CEST Grosu, George (uidl9584) 
  CHANGES:                   Return to the new exec function
  CHANGES:                   Revision 1.15 2018/04/19 14:39:10CEST Grosu, George (uidl9584) 
  CHANGES:                   Initialize pointers
  CHANGES:                   Revision 1.14 2018/04/16 15:56:06CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix for old exec
  CHANGES:                   Revision 1.12 2018/04/11 12:06:41CEST Grosu, George (uidl9584) 
  CHANGES:                   Avoid unstable state
  CHANGES:                   Revision 1.11 2018/04/05 10:11:18CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix: Null pointer check
  CHANGES:                   Revision 1.10 2018/03/27 12:38:36CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.9 2018/01/15 15:22:13CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial quick merge with latest wrappers from R7.1
  CHANGES:                   Revision 1.8 2017/12/08 16:21:04CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implemented LCFSEN
  CHANGES:                   Revision 1.7 2017/12/07 09:32:10CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   bugfix: routine LCFRCV_SenProcess now called
  CHANGES:                   Revision 1.6 2017/11/24 18:32:05CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   first full integration of mainstream code
  CHANGES:                   Revision 1.5 2017/11/20 19:03:39CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   LCF MFC431 R7.1
  CHANGES:                   Revision 1.4 2017/11/01 12:08:12CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.23.1.24.2.1 2017/09/22 16:07:17CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for new RTE
  CHANGES:                   Revision 1.23.1.24 2017/09/06 15:00:10CEST Grosu, George (uidl9584) 
  CHANGES:                   Use Tachometer speed from VDY
  CHANGES:                   Revision 1.23.1.23 2017/09/05 15:31:05CEST Grosu, George (uidl9584) 
  CHANGES:                   2 more debug signals
  CHANGES:                   Revision 1.23.1.22 2017/09/05 15:03:28CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix
  CHANGES:                   Revision 1.23.1.20 2017/08/23 12:43:35CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.23.1.19 2017/08/23 12:26:52CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.23.1.18 2017/08/16 07:14:28CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.23.1.17 2017/08/09 15:45:32CEST Grosu, George (uidl9584) 
  CHANGES:                   Merge with MFC431HI28
  CHANGES:                   Revision 1.23.1.16 2017/08/09 14:56:04CEST Grosu, George (uidl9584) 
  CHANGES:                   New LDPOC
  CHANGES:                   Revision 1.23.1.15 2017/08/03 15:29:07CEST Grosu, George (uidl9584) 
  CHANGES:                   Use variables for array size
  CHANGES:                   Revision 1.23.1.14 2017/08/03 14:33:54CEST Grosu, George (uidl9584) 
  CHANGES:                   debug error handler
  CHANGES:                   Revision 1.23.1.13 2017/07/25 14:52:45CEST Grosu, George (uidl9584) 
  CHANGES:                   Generic
  CHANGES:                   Revision 1.23.1.12 2017/07/24 08:56:42CEST Grosu, George (uidl9584) 
  CHANGES:                   New CP
  CHANGES:                   Revision 1.23.1.11 2017/07/14 09:38:40CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.23.1.10 2017/07/13 17:59:24CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.23.1.9 2017/07/06 16:57:38CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-8
  CHANGES:                   Revision 1.23.1.8 2017/07/06 11:43:28CEST Grosu, George (uidl9584) 
  CHANGES:                   Fix QAC errors
  CHANGES:                   Revision 1.23.1.7 2017/07/05 14:10:36CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-6
  CHANGES:                   Revision 1.23.1.6 2017/06/30 16:29:36CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix
  CHANGES:                   Revision 1.23.1.5 2017/06/30 16:07:11CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.23.1.4 2017/06/16 17:11:55CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA2
  CHANGES:                   Revision 1.23.1.3 2017/06/13 15:33:02CEST Grosu, George (uidl9584) 
  CHANGES:                   Update TJA integration
  CHANGES:                   Revision 1.23.1.2 2017/05/31 14:38:19CEST Grosu, George (uidl9584) 
  CHANGES:                   Integrate TJASA
  CHANGES:                   Revision 1.23.1.1 2017/05/30 13:54:55CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA initial version
  CHANGES:                   Revision 1.24 2017/05/02 12:33:52CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Integration 3.1
  CHANGES:                   Revision 1.23 2017/04/07 19:51:48CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R3.0
  CHANGES:                   Revision 1.22 2017/03/21 10:05:27CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   VDPR update: turn signal debounced with turn off delay
  CHANGES:                   Revision 1.21 2017/03/17 13:20:09CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   New LCF algo in preparation for Hyundai R3.0
  CHANGES:                   Revision 1.20 2017/03/13 08:52:13CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Reduce number of critical and mandatory QAC warnings.
  CHANGES:                   Revision 1.19 2017/03/07 14:12:08CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   issue 570152: integrate new LCF features (reaction on road edges, LKA dead zone implementation, overall functionality prepared for Hyundai R3.0)
  CHANGES:                   Revision 1.18 2017/02/13 12:27:51CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Adapt for RTE 6.0
  CHANGES:                   Revision 1.17 2017/02/09 07:23:22CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update after code review. Implement new signals from HMIOC.
  CHANGES:                   Revision 1.16 2017/02/01 12:24:50CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   creation or R2.1 LCF functionality
  CHANGES:                   Revision 1.15 2017/01/19 11:20:38CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Function and performance improvements during 2.0 demo in Korea
  CHANGES:                   Revision 1.14 2017/01/18 08:14:36CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Function and performance improvements during 2.0 demo in Korea
  CHANGES:                   Revision 1.13 2016/12/08 15:15:17CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Fill CF_Lkas_LDWSSysState signal
  CHANGES:                   Revision 1.12 2016/11/25 14:42:07CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Adaption of ext headers to fit the generated ones
  CHANGES:                   Revision 1.11 2016/11/09 12:09:49CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   remove inclusion of algo_glob.h from ext headers (for compatibility with generated headers)
  CHANGES:                   Revision 1.10 2016/11/03 11:57:15CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R2.0
  CHANGES:                   Revision 1.9 2016/10/25 18:58:49CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Declared separate VehVelX variables for SEN and VEH. Rolled back to LCF cycle ids 23 and 90.
  CHANGES:                   Revision 1.8 2016/09/26 11:19:49CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Remove double declarations of variables
  CHANGES:                   Revision 1.7 2016/09/22 14:21:53CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Integrated LDW function. Removed EMT0OutputData.
  CHANGES:                   Revision 1.6 2016/09/08 08:49:55CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update LCF for R1.0 release
  CHANGES:                   Revision 1.5 2016/08/29 10:55:24CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Wrapper bugfixes during LKA demo
  CHANGES:                   Revision 1.4 2016/08/08 17:12:29CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   LCF TASK_IDs update
  CHANGES:                   Revision 1.3 2016/07/27 21:56:54CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Fill SigHeader information. Correct eOpMode values.
  CHANGES:                   Revision 1.2 2016/07/27 09:27:27CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Fill eCompState information
  CHANGES:                   Revision 1.1 2016/07/25 12:11:05CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Bugfix in LCF wrappers (added null pointer checks for all required ports before LCF Process functions)
  CHANGES:                   Revision 1.0 2016/07/01 06:44:49CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/frame_sen/project.pj
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lcf_sen_main.h"
#include "LCFSEN/LCFSEN.h"

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
/* L3D_ALGO_22283: Increment this version every time the list of required ports is modified */
/* Currently there is no usecase for this INTFVER, but it's safe to increment it every time SyncRef structure modifies */
#ifndef LCF_SEN_SYNCREF_INTFVER
#define LCF_SEN_SYNCREF_INTFVER ((AlgoInterfaceVersionNumber_t)1)
#endif

/*****************************************************************************
  STRUCTURES AND TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
#ifdef _LCF_SENOUTTYPE_T_
static LCF_SenOutType LCF_stSenOutData;
#endif /* _LCF_SENOUTTYPE_T_*/

/* Pointers to provided, required & service ports */
proLcfSenPrtList_t *pLcfSenProPorts = NULL;
const reqLcfSenPrtList_t *pLcfSenReqPorts = NULL;
const AS_t_ServiceFuncts *pLcfSenServices = NULL;

/* LCF_SEN debug data to be meas freezed */
#ifdef CM_SIM /*For Virtual Algo Simulation use non static Debug structure*/
LCF_SenDebugData_t LCFSen_pstDbgData;
#else
//static LCF_SenDebugData_t LCFSen_pstDbgData;
LCF_SenDebugData_t LCFSen_pstDbgData;
#endif


FRAME_SenDbgType*  const  pFRAME_SenDbgData = &LCFSen_pstDbgData.FRAME_SenDbgData;
LCFERR_SenDbgType* const pLCFERR_SenDbgData = &LCFSen_pstDbgData.LCFERR_SenDbgData;

/* Descriptors for meas freeze data */
/*Surpress QAC Messages (next 5 lines): File scope static, 'object_name', is only accessed in one function */
/*PRQA S 3218 6*/
static const AS_t_MeasInfo LCF_SenGenOutMTSDesc   = {(uint32)LCF_MEAS_ID_SEN_OUTPUT, sizeof(LCF_SenGenericOutputs_t), TASK_ID_LCF_SEN, TASK_ID_LCF_SEN};
static const AS_t_MeasInfo LCF_SenToVehOutMTSDesc = {(uint32)LCF_MEAS_ID_SEN2VEH,    sizeof(LCF_SenToVeh_t),          TASK_ID_LCF_SEN, TASK_ID_LCF_SEN}; 
static const AS_t_MeasInfo LCF_SenDebugMTSDesc    = {(uint32)LCF_MEAS_ID_DEBUG_SEN,  sizeof(LCF_SenDebugData_t),      TASK_ID_LCF_SEN, TASK_ID_LCF_SEN};
static const AS_t_MeasInfo LCF_SenCtrlMTSDesc     = {(uint32)LCF_SEN_MEAS_ID_CTRL_BSW_DATA,   sizeof(BaseCtrlData_t),  TASK_ID_LCF_SEN, TASK_ID_LCF_SEN};
static const AS_t_MeasInfo LCF_SenCompStMTSDesc   = {(uint32)LCF_SEN_MEAS_ID_ALGO_COMP_STATE, sizeof(AlgoCompState_t), TASK_ID_LCF_SEN, TASK_ID_LCF_SEN};
static const AS_t_MeasInfo LCF_SenSyncRefMTSDesc  = {(uint32)LCF_SEN_MEAS_ID_SYNC_REF, sizeof(LcfSen_SyncRef_t),      TASK_ID_LCF_SEN, TASK_ID_LCF_SEN};

/* Create SyncRef structure and fill uiVersionNumber */
LcfSen_SyncRef_t LcfSen_SyncRef;

/* BitField Integer containing Ports check status */
uint16 LCFSEN_proPorts_NullStatusCheck;
uint32 LCFSEN_reqPorts_NullStatusCheck;
uint16 LCFSEN_services_NullStatusCheck;
uint32 LCFSEN_reqPorts_SignalStatusOk; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK*/
uint32 LCFSEN_reqPorts_SignalStatusInit; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
uint32 LCFSEN_reqPorts_SignalStatusInvalid; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
uint32 LCFSEN_reqPorts_VersionNumberCheck; /*Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h*/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LcfSenProcess(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts);
static void LcfSenReset  (proLcfSenPrtList_t* const proPorts);
static void LcfSenSetSigHeader(SignalHeader_t* const psSigHeader, AlgoDataTimeStamp_t uiCtrlTmp, AlgoCycleCounter_t uiCtrlMeasCnt, AlgoCycleCounter_t uiCycleCnt);
static void LcfSenSetInfoDataProPorts(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts, AlgoCycleCounter_t uiCycleCnt);
static void LcfSenFillSyncRef(const reqLcfSenPrtList_t* const reqPorts, AlgoCycleCounter_t uiCycleCnt);
static void LcfSenMeasFreeze(const reqLcfSenPrtList_t* const reqPorts, const proLcfSenPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);
static void LcfSenPortsCheck(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************

  Functionname:     LcfSenProcess                                            */ /*!

  @brief            Template Main processing

  @description      Calls all processing functions of lcf and sub-components

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in,out]    proPorts : pointer on the provided ports structure

  @return           -

  @pre              All states must be set
  @post             -

  @todo             review for unused code

  @author           

**************************************************************************** */
static void LcfSenProcess(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts)
{
	uint8 i;
	
	LCFRCV_SenProcess();
	
#if defined(LCF_SEN_ERR_USED) && (LCF_SEN_ERR_USED == 1)	
    /* Check status of relevant inputs */ 		
    if (P_ERRIOSEN_EnableChecks_btf == 0u)
    {
        /*No error. Fill with 0 */
        for (i = 0u; i < ERRIOSEN_CHECKED_FUNCTIONS_NO; i++)
        {
            ERRIOSEN_ErrStateArray[i] = LCF_NO_ERROR;
        }
    }
    else
    {
        ERRIOSEN_InputsCheck(reqPorts);
    }
#endif	
	
	LCF_SenProcess();
    /* Fill comp state before Error Handler */
	proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_RUNNING;
	proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK; /*L3D_ALGO_23757*/
	
	/* L3D_ALGO_23757: In case of successful execution the signal state in the signal header shall be 'AL_SIG_STATE_OK'*/
	proPorts->pLcfSenOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
    proPorts->pLcfSenOutputToVehData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
    
#if defined(LCF_SEN_ERR_USED) && (LCF_SEN_ERR_USED == 1)	
    if(P_ERRIOSEN_EnableChecks_btf != 0u)
    {
		S_ERRSEN_ErrMatrix_btf[ERRSEN_enVehTask] = GET_S_LCFERR_VehErrorToSen_btf();
        ERRSEN_Process();
    }
#endif
	LCFSND_SenProcess();
	
}

/* ****************************************************************************

  Functionname:     LcfSenReset                                         */ /*!

  @brief            Reset of the component

  @description      Initialization of all internal data storage.
                    Shall be called once before processing starts

  @param[in]        
  @param[in,out]    proPorts : pointer on the provided ports structure

  @return           -

  @pre              -
  @post             All internal values and all interfaces are initialized
                    to default values

  @author           

**************************************************************************** */
static void LcfSenReset(proLcfSenPrtList_t* const proPorts)
{
	/* Init Errors */
	proPorts->pAlgoCompState->eErrorCode = (CompErrorCode_t)COMP_ERROR_NO_ERROR;
	proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_NOT_INITIALIZED;
	
	/* Ensure tunable and vehicle parameters are copied at each startup */
	LCFSen_pstDbgData.FRAME_SenDbgData.uiTunParCopied = 0u;
    LCFSen_pstDbgData.FRAME_SenDbgData.uiVdyParCopied = 0u;

	/*! Initialize MeasFreeze */

	/*! Reset algo data to initial values */
	LCFRCV_SenReset();
	LCF_SenReset();
#if defined(LCF_SEN_ERR_USED) && (LCF_SEN_ERR_USED == 1)
    ERRSEN_Reset();
#endif
	LCFSND_SenReset();
    
    /* L3D_ALGO_23195: Except for the comp state and the NVM structure the signal state shall be set to 'AL_SIG_STATE_INIT'. */
    proPorts->pLcfSenOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INIT;
    proPorts->pLcfSenOutputToVehData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INIT;
    	
	proPorts->pAlgoCompState->eShedulerSubModeRequest = (BaseSchedulingSubMode_t)BASE_SSM_NONE; /*L3D_ALGO_24374; LCF does not request GS mode changes*/
	proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK;
	proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_SUCCESS;	
}

/* ****************************************************************************

  Functionname:     LcfSenSetSigHeader                                         */ /*!

  @brief            Fill a signal header

  @description      Fill a signal header
                    Shall be called in normal behaviour Exec function
                    
  @param[in,out]    psSigHeader : pointer on the signal header to be filled
  @param[in]        uiSigState : signal state
  @param[in]        uiCtrlTmp : timestamp
  @param[in]        uiCtrlMeasCnt : measurement counter
  @param[in]        uiCycleCnt : cycle counter of Exec function

  @return           -

  @pre              -
  @post             Signal header is filled

  @author           

**************************************************************************** */
static void LcfSenSetSigHeader(SignalHeader_t* const psSigHeader, AlgoDataTimeStamp_t uiCtrlTmp, AlgoCycleCounter_t uiCtrlMeasCnt, AlgoCycleCounter_t uiCycleCnt)
{
    /* Fill signal header with the received arguments */
    psSigHeader->uiTimeStamp = uiCtrlTmp;
    psSigHeader->uiMeasurementCounter = uiCtrlMeasCnt;
    psSigHeader->uiCycleCounter = uiCycleCnt;
}

/* ****************************************************************************

  Functionname:     LcfSenSetInfoDataProPorts                                         */ /*!

  @brief            Fill provided ports

  @description      Fills version number and signal header for all provide ports
                    Shall be called in normal behaviour Exec function

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in,out]    proPorts : pointer on the provided ports structure
  @param[in]        uiCycleCnt : cycle counter of Exec function

  @return           -

  @pre              -
  @post             Provided ports filled with version number and signal header

  @author           

**************************************************************************** */
static void LcfSenSetInfoDataProPorts(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts, AlgoCycleCounter_t uiCycleCnt)
{
   	/* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* Defensive programming */
    /* PRQA S 2981 3 */
	AlgoDataTimeStamp_t uiCtrlTimeStamp = 0U;
	AlgoCycleCounter_t uiCtrlMeasCounter = 0U;
    uint8 uiAlgoVerInfoFillSize = 0U;

    /* Fill version numbers of provided ports */
    proPorts->pAlgoCompState->uiVersionNumber         = (AlgoInterfaceVersionNumber_t)COMP_STATE_INTFVER;
    proPorts->pLcfSenOutputData->uiVersionNumber      = (AlgoInterfaceVersionNumber_t)LCF_SEN_OUTPUT_INTFVER;
    proPorts->pLcfSenOutputToVehData->uiVersionNumber = (AlgoInterfaceVersionNumber_t)LCF_SEN2VEH_INTFVER; 

    /* Fill signal headers of provided ports */
    uiCtrlTimeStamp = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    uiCtrlMeasCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
	
	LcfSenSetSigHeader(&(proPorts->pAlgoCompState->sSigHeader),    uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
	LcfSenSetSigHeader(&(proPorts->pLcfSenOutputData->sSigHeader), uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
	LcfSenSetSigHeader(&(proPorts->pLcfSenOutputToVehData->sSigHeader), uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);

    /* Fill additional Algo comp state information */	
    proPorts->pAlgoCompState->eShedulerSubModeRequest = (BaseSchedulingSubMode_t)BASE_SSM_NONE; /*L3D_ALGO_24374; LCF does not request GS mode changes*/
    proPorts->pAlgoCompState->uiAlgoVersionNumber     = (AlgoComponentVersionNumber_t)LCFALL_SW_VERSION_NUMBER;
    proPorts->pAlgoCompState->uiApplicationNumber     = (AlgoApplicationNumber_t)GET_LCF_PRJ_NR(); /*decided to use uiApplicationNumber to indicate the current project*/
    /*Surpress QAC Messages (next line): Using conditional operator in a macro.
    Conditional operator is strictly necessary for macro statement*/
    /*PRQA S 3491 1*/
    uiAlgoVerInfoFillSize = (uint8)MIN(sizeof(LCF_CHECKPOINT),(uint8)((uint8)ALGO_VERSION_INFO_LENGTH-1u));
    /*Surpress QAC Messages (next line): Implicit conversion from a pointer to object type to a pointer to void.
    Intentional cast to pointer to void with the purpose to match service function prototypes*/
    /*PRQA S 315 1*/
    (void)memcpy(proPorts->pAlgoCompState->AlgoVersionInfo, LCF_CHECKPOINT, (uint32)uiAlgoVerInfoFillSize);
    proPorts->pAlgoCompState->AlgoVersionInfo[uiAlgoVerInfoFillSize] = 0U;
}

/* ****************************************************************************

  Functionname:     LcfSenFillSyncRef                                         */ /*!

  @brief            Fill SyncRef

  @description      Fills SyncRef data structure
                    Shall be called in normal behaviour Exec function

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in]        uiCycleCnt : cycle counter of Exec function

  @return           -

  @pre              -
  @post             SyncRef filled 

  @author           

**************************************************************************** */
static void LcfSenFillSyncRef(const reqLcfSenPrtList_t* const reqPorts, AlgoCycleCounter_t uiCycleCnt)
{
    /* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* Defensive programming */
    /* PRQA S 2981 2 */
	AlgoDataTimeStamp_t uiCtrlTimeStamp = 0U;
	AlgoCycleCounter_t uiCtrlMeasCounter = 0U;
    
    /* Fill LcfVeh_SyncRef; L3D_ALGO_22283 */
    LcfSen_SyncRef.uiVersionNumber = (AlgoInterfaceVersionNumber_t)LCF_SEN_SYNCREF_INTFVER;
    
    /* Fill signal header of LcfVeh_SyncRef structure */
	uiCtrlTimeStamp = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    uiCtrlMeasCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
    LcfSenSetSigHeader(&(LcfSen_SyncRef.sSigHeader), uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
	LcfSen_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
    
    /* Fill sBaseCtrl of LcfVeh_SyncRef structure */
    LcfSen_SyncRef.sBaseCtrl.uiVersionNumber = reqPorts->pBaseCtrlData->uiVersionNumber;
    LcfSen_SyncRef.sBaseCtrl.sSigHeader.uiTimeStamp = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    LcfSen_SyncRef.sBaseCtrl.sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
    LcfSen_SyncRef.sBaseCtrl.sSigHeader.uiCycleCounter = reqPorts->pBaseCtrlData->sSigHeader.uiCycleCounter;
    LcfSen_SyncRef.sBaseCtrl.sSigHeader.eSigStatus = reqPorts->pBaseCtrlData->sSigHeader.eSigStatus;
    LcfSen_SyncRef.sBaseCtrl.eOpMode = reqPorts->pBaseCtrlData->eOpMode;
    LcfSen_SyncRef.sBaseCtrl.eSchedulingMode = reqPorts->pBaseCtrlData->eSchedulingMode;
    LcfSen_SyncRef.sBaseCtrl.eSchedulingSubMode = reqPorts->pBaseCtrlData->eSchedulingSubMode;
    
    /* Fill SyncRef signal header for every required port */  
    LcfSen_SyncRef.pAbdOutputData = reqPorts->pAbdOutputData->sSigHeader;
    LcfSen_SyncRef.pCamObjectList = reqPorts->pCamObjectList->sSigHeader;
	#if (defined(USE_IPC_PARAMS) && (USE_IPC_PARAMS == 1))
    LcfSen_SyncRef.pCParLdp = reqPorts->pCParLdp->sSigHeader;
    LcfSen_SyncRef.pCParLka = reqPorts->pCParLka->sSigHeader;
	#endif
    LcfSen_SyncRef.pGenObjectList = reqPorts->pGenObjectList->sSigHeader;
    LcfSen_SyncRef.pLcfInputData = reqPorts->pLcfInputData->sSigHeader;
    LcfSen_SyncRef.pLcfSenInputFromVehData = reqPorts->pLcfSenInputFromVehData->sSigHeader;
    LcfSen_SyncRef.pLcfVehOutputData = reqPorts->pLcfVehOutputData->sSigHeader;
    LcfSen_SyncRef.pVehDyn = reqPorts->pVehDyn->sSigHeader;
    LcfSen_SyncRef.pVehPar = reqPorts->pVehPar->sSigHeader;
    LcfSen_SyncRef.pVehSig = reqPorts->pVehSig->sSigHeader;		
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
    LcfSen_SyncRef.pLcfLaDmcIucToSoc = reqPorts->pLcfLaDmcIucToSoc->sSigHeader;
#endif    

#if defined(HLA_RADAR_OBJECT_USED) && (HLA_RADAR_OBJECT_USED == 1)
	LcfSen_SyncRef.pHlaRadarObjectList = reqPorts->pHlaRadarObjectList->sSigHeader;		
#endif

	LcfSen_SyncRef.pCbOutputs = reqPorts->pCbOutputs->sSigHeader;       
	LcfSen_SyncRef.pLsdEnvironmentData = reqPorts->pLsdEnvironmentData->sSigHeader;
}

/* ****************************************************************************

  Functionname:     LcfSenMeasFreeze                                         */ /*!

  @brief            Meas freeze LCF data

  @description      Meas freeze LCF data
                    Shall be called in normal behaviour Exec function

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in]        proPorts : pointer on the provided ports structure
  @param[in]        services : pointer on the services structure

  @return           -

  @pre              -
  @post             

  @author           

**************************************************************************** */
static void LcfSenMeasFreeze(const reqLcfSenPrtList_t* const reqPorts, const proLcfSenPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
{
    /* Runtime measurement is done via sections of code in "lcf_sen_service.h" */
    #define	LCF_SEN_MEASF_START
    #include "lcf_sen_service.h"

    /* L3D_ALGO_24516: Meas freeze relevant data */
    /*Surpress QAC Message: Cast from a pointer to object type to a pointer to void.
    Intentional cast to pointer to void with the purpose to match service function prototypes*/
    /*PRQA S 314 6*/
    (void)services->pfMeasFreeze(&LCF_SenGenOutMTSDesc,  (const void *)proPorts->pLcfSenOutputData,     (MEAS_Callback_t) 0UL);
    (void)services->pfMeasFreeze(&LCF_SenToVehOutMTSDesc,(const void *)proPorts->pLcfSenOutputToVehData,(MEAS_Callback_t) 0UL);
    (void)services->pfMeasFreeze(&LCF_SenDebugMTSDesc,   (const void *)&LCFSen_pstDbgData,              (MEAS_Callback_t) 0UL);
    (void)services->pfMeasFreeze(&LCF_SenCtrlMTSDesc,    (const void *)reqPorts->pBaseCtrlData,         (MEAS_Callback_t) 0UL); 
    (void)services->pfMeasFreeze(&LCF_SenCompStMTSDesc,  (const void *)proPorts->pAlgoCompState,        (MEAS_Callback_t) 0UL); 
    (void)services->pfMeasFreeze(&LCF_SenSyncRefMTSDesc, (const void *)(&LcfSen_SyncRef),               (MEAS_Callback_t) 0UL);
    
    #define	LCF_SEN_MEASF_STOP
    #include "lcf_sen_service.h"
}

/* ****************************************************************************

  Functionname:     CheckReqPortsToCheckAttributes                                         */ /*!

  @brief            Perform null, signals status and version number checks on reqPorts

  @description      Perform null, signals status and version number checks on reqPorts

  @param[in]        portPtr : pointer of the port (required)
  @param[in]        portSigStatus : actual signal status of the required port
  @param[in]        portActualVersionNumber : actual version number of the required port
  @param[in]        portPos : required port bit position in reported checks results (enums in lcf_xxx_main.h)
  @param[in]		portRTEVersionNumber : the RTE version number which portActualVersionNumber is tested against
  @param[in]		reqPortsNullStatusVar : the variable in which the null check result of checks will be written, given as an address or pointer
  @param[in]		reqPortsSigStOKStatusVar : the variable in which the signal status == OK check result of checks will be written, given as an address or pointer
  @param[in]		reqPortsSigStInitStatusVar : the variable in which the signal status == INIT check result of checks will be written, given as an address or pointer
  @param[in]		reqPortsSigStInvStatusVar : the variable in which the signal status == INVALID check result of checks will be written, given as an address or pointer
  @param[in]		reqPortsVerNumStatusVar : the variable in which the version number check result of checks will be written, given as an address or pointer

  @return           -

  @pre              -
  @post             

  @author           

**************************************************************************** */
static void CheckReqPortsToCheckAttributes(void * portPtr, AlgoSignalState_t portSigStatus, AlgoInterfaceVersionNumber_t portActualVersionNumber,
	LCFSEN_reqPorts_NullCheckFlags_t portPos, AlgoInterfaceVersionNumber_t portRTEVersionNumber, uint32 * reqPortsNullStatusVar, 
	uint32 * reqPortsSigStOKStatusVar, uint32 * reqPortsSigStInitStatusVar, uint32 * reqPortsSigStInvStatusVar, uint32 * reqPortsVerNumStatusVar)
{
	uint8 isPortNull = (uint8)(portPtr == NULL);
	if (isPortNull !=0u)
	{
		*(reqPortsNullStatusVar) |= (uint32)(isPortNull) << (uint32)(portPos);
	}
	else
	{
		if (portSigStatus == (AlgoSignalState_t)AL_SIG_STATE_INIT)
		{
			*(reqPortsSigStInitStatusVar) |= ((uint32)(1u) << (uint32)(portPos));
			//*(reqPortsSigStOKStatusVar) &=(uint32)(~((uint32)(1u) << (uint32)(portPos)));   Debug for hiding buserror caused by BSW inputs!!!
			*(reqPortsSigStOKStatusVar)=2;
		}
		else if (portSigStatus != (AlgoSignalState_t) AL_SIG_STATE_OK)
		{
			*(reqPortsSigStInvStatusVar) |= ((uint32)(1u) << (uint32)(portPos));
			//*(reqPortsSigStOKStatusVar) &= (uint32)(~((uint32)(1u) << (uint32)(portPos)));   Debug for hiding buserror caused by BSW inputs!!!
			*(reqPortsSigStOKStatusVar)=2;
		}
		*(reqPortsVerNumStatusVar) |= ((uint32)(portActualVersionNumber != portRTEVersionNumber) << (uint32)(portPos));
	}
}

/* ****************************************************************************

  Functionname:     CheckProPortsToCheckAttributes                                         */ /*!

  @brief            Perform null on proPorts

  @description      Perform null on proPorts

  @param[in]        portPtr : pointer of the port (provided)
  @param[in]        portPos : provided port bit position in reported checks results (enums in lcf_xxx_main.h)
  @param[in]		proPortsNullStatusVar : the variable in which the null check result of checks will be written, given as an address or pointer

  @return           -

  @pre              -
  @post             

  @author           

**************************************************************************** */
static void CheckProPortsToCheckAttributes(void * portPtr, LCFSEN_proPorts_NullCheckFlags_t portPos, uint16 * proPortsNullStatusVar)
{
	*(proPortsNullStatusVar) |= (uint16)(portPtr == NULL) << (uint16)(portPos);
}

/* ****************************************************************************

  Functionname:     CheckServicesToCheckAttributes                                         */ /*!

  @brief            Perform null on services ports (functions)

  @description      Perform null on services ports (functions)

  @param[in]        portPtr : pointer of the port (service)
  @param[in]        portPos : service port bit position in reported checks results (enums in lcf_xxx_main.h)
  @param[in]		serviceNullStatusVar : the variable in which the null check result of checks will be written, given as an address or pointer

  @return           -

  @pre              -
  @post             

  @author           

**************************************************************************** */
static void CheckServicesToCheckAttributes(void * portPtr, LCFSEN_services_NullCheckFlags_t portPos, uint16 * serviceNullStatusVar)
{
	*(serviceNullStatusVar) |= (uint16)(portPtr == NULL) << (uint16)(portPos);
}

/* ****************************************************************************

  Functionname:     LcfSenPortsCheck                                         */ /*!

  @brief            Check and record NULL status for reqPorts, proPorts and services, SignalStatus and VersionNumber of reqPorts.

  @description      Check and record NULL status for reqPorts, proPorts and services, SignalStatus and VersionNumber of reqPorts.
							Record status in bits of uint32 variables.

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in]        proPorts : pointer on the provided ports structure
  @param[in]        services : pointer on the services structure

  @return           -

  @pre              -
  @post             

  @author           

**************************************************************************** */
static void LcfSenPortsCheck(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
{
	uint32 LCFSEN_ErrorEvents_btf = 0u; 
	
	/* Reset check status variables (bit fields) */
	LCFSEN_proPorts_NullStatusCheck = 0u; /* Zero (0) means that corresponding port is not NULL */
	LCFSEN_reqPorts_NullStatusCheck = 0u; /* Zero (0) means that corresponding port is not NULL */
	LCFSEN_services_NullStatusCheck = 0u; /* Zero (0) means that corresponding port is not NULL */
	LCFSEN_reqPorts_SignalStatusOk = (uint32)(((uint32)(1u) << (uint32)((uint32)LCFSEN_REQUIRED_PORTS_COUNTER+1u))-1u); /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK */
	LCFSEN_reqPorts_SignalStatusInit = 0u; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
	LCFSEN_reqPorts_SignalStatusInvalid = 0u; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFSEN_reqPorts_SignalStatusInit and LCFSEN_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
	LCFSEN_reqPorts_VersionNumberCheck = 0u; /* Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h */
	
	/* Check proPorts, reqPorts and services if they are not NULL pointers */
	LCFSEN_proPorts_NullStatusCheck = (uint16)(proPorts == NULL);
	LCFSEN_reqPorts_NullStatusCheck = (uint32)(reqPorts == NULL);
	LCFSEN_services_NullStatusCheck = (uint16)(services == NULL);
	
	/* Check ALL services ports if they are not NULL pointers */
	if(LCFSEN_services_NullStatusCheck ==0u)
	{		
		CheckServicesToCheckAttributes((void*)services->pfMeasFreeze, MEAS_FREEZE_IS_NULL, &LCFSEN_services_NullStatusCheck );
		//CheckServicesToCheckAttributes((void*)services->pfDem_SetEventStatus, DEM_SET_EVENT_STATUS_IS_NULL, &LCFSEN_services_NullStatusCheck );  //MFC5J3
		//CheckServicesToCheckAttributes((void*)services->pfDem_SetEventStatusPreExtData, DEM_SET_EVENT_STATUS_PRE_EXT_DATA_IS_NULL, &LCFSEN_services_NullStatusCheck );
		//CheckServicesToCheckAttributes((void*)services->pfRTAAlgoServiceAddEvent, RTA_ALGO_SERVICE_ADD_EVENT_IS_NULL, &LCFSEN_services_NullStatusCheck );
		//CheckServicesToCheckAttributes((void*)services->pfMeasStartFuncCycle, MEAS_START_FUNC_CYCLE_IS_NULL, &LCFSEN_services_NullStatusCheck );
	}
	else{/*null port was detected*/}
	
	/* Check ALL proPorts ports if they are not NULL pointers */
	if(LCFSEN_proPorts_NullStatusCheck ==0u)
	{
		CheckProPortsToCheckAttributes((void*)proPorts->pAlgoCompState, ALGO_COMP_STATE_IS_NULL, &LCFSEN_proPorts_NullStatusCheck );
		CheckProPortsToCheckAttributes((void*)proPorts->pLcfSenOutputData, SEN_OUTPUT_DATA_IS_NULL, &LCFSEN_proPorts_NullStatusCheck );
		CheckProPortsToCheckAttributes((void*)proPorts->pLcfSenOutputToVehData, SEN_OUTPUT_TO_VEH_DATA_IS_NULL, &LCFSEN_proPorts_NullStatusCheck );
	}
	else{/*null port was detected*/}
		
	/* Check ALL reqPorts ports */
	if(LCFSEN_reqPorts_NullStatusCheck ==0u)
	{
	/* Check pBaseCtrlData reqPort */
	#if defined(LCF_SEN_RPORT_PBASECTRLDATA) 
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pBaseCtrlData, GET_SIGNAL_STATUS(reqPorts->pBaseCtrlData), GET_VERSION_NUMBER(reqPorts->pBaseCtrlData), BASE_CTRL_DATA_CHECK_BIT, BASE_CTRL_DATA_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, BASE_CTRL_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pAbdOutputData reqPort */	
	#if defined(LCF_SEN_RPORT_PABDOUTPUTDATA) 
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pAbdOutputData, GET_SIGNAL_STATUS(reqPorts->pAbdOutputData), GET_VERSION_NUMBER(reqPorts->pAbdOutputData), ABD_OUTPUT_DATA_CHECK_BIT, ABD_OUTPUT_DATA_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, ABD_OUTPUT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pCamObjectList reqPort */
	#if defined(LCF_SEN_RPORT_PCAMOBJECTLIST)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pCamObjectList, GET_SIGNAL_STATUS(reqPorts->pCamObjectList), GET_VERSION_NUMBER(reqPorts->pCamObjectList), CAM_OBJECT_LIST_CHECK_BIT, EM_CAM_OBJECT_LIST_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, CAM_OBJECT_LIST_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif	
		
	 /* Check pCParLdp reqPort */
	#if defined(LCF_SEN_RPORT_PCPARLDP)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pCParLdp, GET_SIGNAL_STATUS(reqPorts->pCParLdp), GET_VERSION_NUMBER(reqPorts->pCParLdp), CPAR_LDP_CHECK_BIT, LCF_TUN_PAR_LDP_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, CPAR_LDP_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pCParLka reqPort */
	#if defined(LCF_SEN_RPORT_PCPARLKA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pCParLka, GET_SIGNAL_STATUS(reqPorts->pCParLka), GET_VERSION_NUMBER(reqPorts->pCParLka), CPAR_LKA_CHECK_BIT, LCF_TUN_PAR_LKA_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, CPAR_LKA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pGenObjectList reqPort */
	#if defined(LCF_SEN_RPORT_PGENOBJECTLIST)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pGenObjectList, GET_SIGNAL_STATUS(reqPorts->pGenObjectList), GET_VERSION_NUMBER(reqPorts->pGenObjectList), GEN_OBJECT_LIST_CHECK_BIT, EM_GEN_OBJECT_LIST_INTFVER_LCF, //MFC5J3
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, GEN_OBJECT_LIST_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfInputData reqPort */
	#if defined(LCF_SEN_RPORT_PLCFINPUTDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfInputData, GET_SIGNAL_STATUS(reqPorts->pLcfInputData), GET_VERSION_NUMBER(reqPorts->pLcfInputData), LCF_INPUT_DATA_CHECK_BIT, LCF_INPUT_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_INPUT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfLaDmcIucToSoc reqPort */
	#if defined(LCF_SEN_RPORT_PLCFLADMCIUCTOSOC)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfLaDmcIucToSoc, GET_SIGNAL_STATUS(reqPorts->pLcfLaDmcIucToSoc), GET_VERSION_NUMBER(reqPorts->pLcfLaDmcIucToSoc), LCF_LADMC_IUC_TO_SOC_CHECK_BIT, LCF_IUC2SOC_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_LADMC_IUC_TO_SOC_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfSenInputFromVehData reqPort */
	#if defined(LCF_SEN_RPORT_PLCFSENINPUTFROMVEHDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfSenInputFromVehData, GET_SIGNAL_STATUS(reqPorts->pLcfSenInputFromVehData), GET_VERSION_NUMBER(reqPorts->pLcfSenInputFromVehData), LCF_SEN_INPUT_FROM_VEH_DATA_CHECK_BIT, LCF_VEH2SEN_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_SEN_INPUT_FROM_VEH_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfVehOutputData reqPort */
	#if defined(LCF_SEN_RPORT_PLCFVEHOUTPUTDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfVehOutputData, GET_SIGNAL_STATUS(reqPorts->pLcfVehOutputData), GET_VERSION_NUMBER(reqPorts->pLcfVehOutputData), LCF_VEH_OUTPUT_DATA_CHECK_BIT, LCF_VEH_OUTPUT_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_VEH_OUTPUT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pVehDyn reqPort */
	#if defined(LCF_SEN_RPORT_PVEHDYN)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVehDyn, GET_SIGNAL_STATUS(reqPorts->pVehDyn), GET_VERSION_NUMBER(reqPorts->pVehDyn), VEH_DYN_CHECK_BIT, VDY_VEH_DYN_INTFVER_LCF,   //MFC5J3
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VEH_DYN_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pVehPar reqPort */
	#if defined(LCF_SEN_RPORT_PVEHPAR)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVehPar, GET_SIGNAL_STATUS(reqPorts->pVehPar), GET_VERSION_NUMBER(reqPorts->pVehPar), VEH_PAR_CHECK_BIT, BSW_VEH_PAR_INTFVER_LCF,   //MFC5J3
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VEH_PAR_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif		
		
	/* Check pVehSig reqPort */
	#if defined(LCF_SEN_RPORT_PVEHSIG)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVehSig, GET_SIGNAL_STATUS(reqPorts->pVehSig), GET_VERSION_NUMBER(reqPorts->pVehSig), VEH_SIG_CHECK_BIT, BSW_VEH_SIG_INTFVER_LCF,   //MFC5J3
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VEH_SIG_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif		
	
	/* Check pCbOutputs reqPort */	
	#if defined(LCF_SEN_RPORT_PCBOUTPUTS)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pCbOutputs, GET_SIGNAL_STATUS(reqPorts->pCbOutputs), GET_VERSION_NUMBER(reqPorts->pCbOutputs), CB_OUTPUTS_CHECK_BIT, CB_PROVIDED_OUTPUTS_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, CB_OUTPUTS_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLsdEnvironmentData reqPort */
	#if defined(LCF_SEN_RPORT_PLSDENVIRONMENTDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLsdEnvironmentData, GET_SIGNAL_STATUS(reqPorts->pLsdEnvironmentData), GET_VERSION_NUMBER(reqPorts->pLsdEnvironmentData), LSD_ENVIRONMENT_DATA_CHECK_BIT, LSD_ENVIRONMENT_DATA_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LSD_ENVIRONMENT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pHlaRadarObjectList reqPort */
	#if defined(LCF_SEN_RPORT_PHLARADAROBJECTLIST)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pHlaRadarObjectList, GET_SIGNAL_STATUS(reqPorts->pHlaRadarObjectList), GET_VERSION_NUMBER(reqPorts->pHlaRadarObjectList), HLA_RADAR_OBJECT_LIST_CHECK_BIT, HLA_RADAR_OBJECT_LIST_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, HLA_RADAR_OBJECT_LIST_CHECK_BIT, INVALID_INTFVER, 
			&LCFSEN_reqPorts_NullStatusCheck, &LCFSEN_reqPorts_SignalStatusOk, &LCFSEN_reqPorts_SignalStatusInit, &LCFSEN_reqPorts_SignalStatusInvalid, &LCFSEN_reqPorts_VersionNumberCheck);
	#endif
			
		/* Set error flags for Error Handler Component (LCFERR), write LCF_ErrorEvents_btf variable */
		/* Reset ErrorEvents bitfield */
		LCF_ErrorEvents_btf = 0u; /* 0 on all bits means no error event */
		/* Write ErrorEvents according to ports actual status */
		LCF_ErrorEvents_btf |= (uint32)((uint32)(((uint32)LCFSEN_services_NullStatusCheck & LCFSEN_SERVICE_PORTS_NULL_CHECK_MASK) != 0u) << (uint32)SERVICE_PORT_IS_NULL_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint32)((uint32)(((uint32)LCFSEN_proPorts_NullStatusCheck & LCFSEN_PROVIDED_PORTS_NULL_CHECK_MASK) != 0u) << (uint32)PROVIDED_PORT_IS_NULL_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint32)((uint32)(((uint32)LCFSEN_reqPorts_NullStatusCheck & LCFSEN_REQUIRED_PORTS_NULL_CHECK_MASK) != 0u) << (uint32)REQUIRED_PORT_IS_NULL_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint32)((uint32)((uint32)LCFSEN_reqPorts_SignalStatusInit & LCFSEN_REQUIRED_PORTS_SIGSTATUS_INIT_MASK) << (uint32)((uint32)REQUIRED_PORT_INIT_ERRFLAG-1u));
		LCF_ErrorEvents_btf |= (uint32)((uint32)(((uint32)LCFSEN_reqPorts_SignalStatusInvalid & LCFSEN_REQUIRED_PORTS_SIGSTATUS_INVALID_MASK) != 0u) << (uint32)REQUIRED_PORT_INVALID_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint32)(((uint32)((uint32)LCFSEN_reqPorts_VersionNumberCheck & LCFSEN_REQUIRED_PORTS_VERNUM_CHECK_MASK) != 0u) << (uint32)REQUIRED_PORT_BAD_VERSION_NUMBER_ERRFLAG);
	}
	else{/*null port was detected*/}
    S_ERRSEN_ErrMatrix_btf[ERRSEN_enSENWrapper] = LCF_ErrorEvents_btf;
}

/* ****************************************************************************

  Functionname:     LcfSenExec                                              */ /*!

  @brief            LCF_SEN main function with input and output parameters

  @description      -

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in,out]    proPorts : pointer on the provided ports structure
  @param[in]        services : pointer on the services structure

  @return           -

  @pre              -
  @post             -

  @author           

**************************************************************************** */
BaseReturnCode_t LcfSenExec(const reqLcfSenPrtList_t* const reqPorts, proLcfSenPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
{
	static uint8 ui8SenDataPtrUninit = TRUE;
	static AlgoCycleCounter_t uiCycleCnt = 0U;
	BaseReturnCode_t uiRetCode = (BaseReturnCode_t)BASE_RETURN_ERROR;
	
	/*GeGr: Initialize pointer before using*/
  	pLcfSenProPorts = proPorts;
	pLcfSenReqPorts = reqPorts;
	pLcfSenServices = services;
	
	if(ui8SenDataPtrUninit !=0u)
	{
		ui8SenDataPtrUninit = FALSE;
		
#ifdef _LCF_SENDBGTYPE_T_
		LCF_SenInitDbgPtr(&LCFSen_pstDbgData.LCF_stSenDbgData);
#endif /* _LCF_SENDBGTYPE_T_*/
#ifdef _LCF_SENOUTTYPE_T_
		LCF_SenInitOutPtr(&LCF_stSenOutData);
#endif /* _LCF_SENOUTTYPE_T_*/
	}
	
	LcfSenPortsCheck(reqPorts, proPorts, services);
	
	/*Update Debug signals with the results from the input checks*/
	pFRAME_SenDbgData->D_LCFSEN_proPorts_NullStatusCheck      = LCFSEN_proPorts_NullStatusCheck;
    pFRAME_SenDbgData->D_LCFSEN_reqPorts_NullStatusCheck      = LCFSEN_reqPorts_NullStatusCheck;
    pFRAME_SenDbgData->D_LCFSEN_services_NullStatusCheck      = LCFSEN_services_NullStatusCheck;
    pFRAME_SenDbgData->D_LCFSEN_reqPorts_SignalStatusOk       = LCFSEN_reqPorts_SignalStatusOk;
    pFRAME_SenDbgData->D_LCFSEN_reqPorts_SignalStatusInit     = LCFSEN_reqPorts_SignalStatusInit;
    pFRAME_SenDbgData->D_LCFSEN_reqPorts_SignalStatusInvalid  = LCFSEN_reqPorts_SignalStatusInvalid;
    pFRAME_SenDbgData->D_LCFSEN_reqPorts_VersionNumberCheck   = LCFSEN_reqPorts_VersionNumberCheck;
		
    /*L3D_ALGO_21600*/
	if (((LCFSEN_proPorts_NullStatusCheck & LCFSEN_PROVIDED_PORTS_NULL_CHECK_MASK) == 0u) && ((LCFSEN_services_NullStatusCheck & LCFSEN_SERVICE_PORTS_NULL_CHECK_MASK) == 0u) 
		&& ((LCFSEN_reqPorts_NullStatusCheck & LCFSEN_BASECTRLDATA_CHECK_MASK) == 0u) 
		&& ((LCFSEN_reqPorts_SignalStatusOk & LCFSEN_BASECTRLDATA_CHECK_MASK) == (LCFSEN_BASECTRLDATA_CHECK_MASK)) && ((LCFSEN_reqPorts_VersionNumberCheck & LCFSEN_BASECTRLDATA_CHECK_MASK) == 0u))
	{
        /* We can proceed with the Exec function now */
                
        /* Runtime measurement is done via sections of code in "lcf_sen_service.h" */
        #define	SEN_WRP_SENPROCESS_START
        #include "lcf_sen_service.h"
        
        /* Cycle counter incremented every time Exec normal behaviour is executed (no BASE_RETURN_ERROR) */
        uiCycleCnt++;

		/* Meas start service */
        //services->pfMeasStartFuncCycle(TASK_ID_LCF_SEN);  //MFC5J3
            
        /*! At this place it is necessary to test lcfOpMode directly to get an initialized component */
        switch (reqPorts->pBaseCtrlData->eOpMode)
        {
        case (uint8)BASE_OM_RESET:
			LcfSenReset(proPorts);
			break; /*L3D_ALGO_23195; no calculation should be done in RESET*/
        case (uint8)BASE_OM_IDLE:
            /*L3D_ALGO_24374; COMP_STATE_NOT_RUNNING shall be set if the algo is called in the idle op mode; L3D_ALGO_22628*/
			proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_NOT_RUNNING;
			proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK;
            /*L3D_ALGO_22628: Except for the comp state and the NVM structure the signal state shall be 'AL_SIG_STATE_INVALID'.*/
            proPorts->pLcfSenOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INVALID;
            proPorts->pLcfSenOutputToVehData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INVALID;
            break; /*L3D_ALGO_22628: no calculation shall be done in IDLE*/
        case (uint8)BASE_OM_DEMO:
            /*L3D_ALGO_22416*/
			proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_SUCCESS;
			proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK;
			proPorts->pLcfSenOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
            proPorts->pLcfSenOutputToVehData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
            /*TODO: fill demo values for all outputs*/
            break; /*L3D_ALGO_22416: no calculation shall be done in DEMO*/
        case (uint8)BASE_OM_RUN: /*TODO: check for other op modes*/
            if(((LCFSEN_reqPorts_NullStatusCheck & LCFSEN_REQUIRED_PORTS_NULL_CHECK_MASK) == 0u)
				/*&& ((LCFSEN_reqPorts_VersionNumberCheck & LCFSEN_REQUIRED_PORTS_VERNUM_CHECK_MASK) == 0u) 
				&& ((LCFSEN_reqPorts_SignalStatusOk & LCFSEN_REQUIRED_PORTS_SIGST_CHECK_MASK) == LCFSEN_REQUIRED_PORTS_SIGST_CHECK_MASK)*/) /*TO DO: uncomment version number check */
			{
				LcfSenFillSyncRef(reqPorts, uiCycleCnt);
                LcfSenProcess(reqPorts, proPorts);
			}
			else{
				//services->pfDem_SetEventStatus(LCF_SEN_FUSI_ERROR, DEM_EVENT_STATUS_FAILED);  //MFC5J3
			}
            break;
        default:
			proPorts->pLcfSenOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
            proPorts->pLcfSenOutputToVehData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
            break;
        }

		/* Fill basic information in provided ports */
        LcfSenSetInfoDataProPorts(reqPorts, proPorts, uiCycleCnt);
		
        /* L3D_ALGO_24516: Meas freeze LCF relevant data */
        LcfSenMeasFreeze(reqPorts, proPorts, services);

        /* Runtime measurement is done via sections of code in "lcf_sen_service.h" */
        #define	SEN_WRP_SENPROCESS_STOP
        #include "lcf_sen_service.h"

        uiRetCode = (BaseReturnCode_t)BASE_RETURN_OK;
	}
	else 
	{
		(void)services->pfMeasFreeze(&LCF_SenDebugMTSDesc, (const void *)&LCFSen_pstDbgData, (MEAS_Callback_t) 0UL);
	}
    
    /* L3D_ALGO_21600: in case error is returned, all provide ports are set to NULL pointer */
    if ((uiRetCode == (BaseReturnCode_t)BASE_RETURN_ERROR) && (proPorts != NULL))
    {
        proPorts->pAlgoCompState = NULL;
        proPorts->pLcfSenOutputData = NULL;
        proPorts->pLcfSenOutputToVehData = NULL;
    }
    else{}
	
  	pLcfSenProPorts = NULL;
	pLcfSenReqPorts = NULL;
	pLcfSenServices = NULL;

	return uiRetCode;
}

