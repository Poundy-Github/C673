/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_veh_main.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.5.1.15 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_veh_main.c  $
  CHANGES:                   Revision 1.5.1.15 2020/02/21 12:50:16CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.5.1.13 2020/01/29 13:44:03CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate new updates
  CHANGES:                   Revision 1.5.1.12 2020/01/23 08:19:03CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Integrate updated files after removing some QAF warnings
  CHANGES:                   Revision 1.5.1.11 2019/12/06 08:34:28CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Send DEM fussi error from main function when the required ports are NULL
  CHANGES:                   Revision 1.5.1.10 2019/11/22 08:45:50CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF Veh for Error Handling Reset
  CHANGES:                   Revision 1.5.1.9 2019/09/25 14:23:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint 10.09
  CHANGES:                   Revision 1.5.1.8 2019/09/12 13:42:04CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrappers bugs:
  CHANGES:                   - signal headers LCF outputs are now set to StateOK in Running
  CHANGES:                   - use of IPCParams is safeguarded
  CHANGES:                   - corrected masks for PortCheck
  CHANGES:                   Revision 1.5.1.7 2019/08/21 13:11:55CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.5.1.6 2019/08/07 10:16:28CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   correct bug for Porvided ports Checks
  CHANGES:                   Revision 1.5.1.5 2019/08/01 13:19:14CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Move call of FillSyncRef to Running OpMode
  CHANGES:                   Revision 1.5.1.4 2019/07/30 10:04:12CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.5.1.3 2019/07/26 07:46:42CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   follow up foe LCF workshop 1:
  CHANGES:                   	- Correct commens in the function headers
  CHANGES:                   	- add IPC protection for VEH cpar's
  CHANGES:                   	- Review comments for the Input checks Debug signals in iface header
  CHANGES:                   Revision 1.5.1.2 2019/07/25 10:24:43CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Update function PortsCheck, move checks into functions
  CHANGES:                   Revision 1.10 2019/07/17 12:19:12CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update workshop 1:
  CHANGES:                   	- move check to functions
  CHANGES:                   	- move custom masks to main header
  CHANGES:                   	- sync ports position in all debug signals
  CHANGES:                   Revision 1.8 2019/07/16 14:18:54CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update PortsCheck function workshop 1:
  CHANGES:                   	- move check to functions
  CHANGES:                   	- move custom masks to main header
  CHANGES:                   	- sync ports position in all debug signals
  CHANGES:                   Revision 1.7 2019/07/10 11:32:59CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update LcfPortsCheck function, add inhibit mechanism for HLA
  CHANGES:                   Revision 1.6 2019/06/25 12:29:22CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Fixed compiler warnings
  CHANGES:                   Revision 1.5 2019/05/30 13:25:58CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.4 2019/05/28 09:36:45CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   update wrappers, generic ports check
  CHANGES:                   Revision 1.1 2019/03/24 17:36:40CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:28CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.2 2019/02/20 14:03:07CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   AuxCodeGen 4.0
  CHANGES:                   Revision 1.1 2019/01/31 18:56:08CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.36 2018/08/02 14:01:10CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint17
  CHANGES:                   Revision 1.35 2018/06/29 13:43:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint15 - Round1
  CHANGES:                   Revision 1.34 2018/06/11 16:30:34CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   check-in for sprint14
  CHANGES:                   Revision 1.33 2018/06/07 08:30:08CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   reorganize lcf_xxx_main wrapper files (*.c and *.h)
  CHANGES:                   replace defines for ports check in enums
  CHANGES:                   Revision 1.32 2018/05/21 13:21:30CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint12
  CHANGES:                   Revision 1.31 2018/05/18 17:08:12CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Update wrappers to meet requirement L3D_ALGO_22428
  CHANGES:                   Revision 1.27 2018/05/10 15:30:57CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint 11(round2)
  CHANGES:                   Revision 1.26 2018/05/08 15:57:10CEST Grosu, George (uidl9584) 
  CHANGES:                   Do not use nvm port
  CHANGES:                   Revision 1.25 2018/04/26 12:02:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for 8.2
  CHANGES:                   Revision 1.24 2018/04/25 14:04:53CEST Grosu, George (uidl9584) 
  CHANGES:                   Replace define for usage of nvm port
  CHANGES:                   Revision 1.23 2018/04/20 09:27:57CEST Grosu, George (uidl9584) 
  CHANGES:                   Do not use IUC yet
  CHANGES:                   Revision 1.22 2018/04/19 15:52:52CEST Grosu, George (uidl9584) 
  CHANGES:                   Return to the new exec function
  CHANGES:                   Revision 1.21 2018/04/19 14:39:10CEST Grosu, George (uidl9584) 
  CHANGES:                   Initialize pointers
  CHANGES:                   Revision 1.20 2018/04/16 15:56:13CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix for old exec
  CHANGES:                   Revision 1.18 2018/04/11 12:07:07CEST Grosu, George (uidl9584) 
  CHANGES:                   Avoid unstable state
  CHANGES:                   Revision 1.17 2018/04/05 10:11:25CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix: Null pointer check
  CHANGES:                   Revision 1.16 2018/03/27 12:49:46CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.14 2018/03/12 08:54:44CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Issue 790041: LCF_VEH not executed in TA19 (unused req port pLcfLaDmcIucToSoc is not received and should not be considered)
  CHANGES:                   Revision 1.13 2018/01/15 15:22:16CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial quick merge with latest wrappers from R7.1
  CHANGES:                   Revision 1.12 2017/12/22 10:02:18CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   R8.0 update
  CHANGES:                   Revision 1.11 2017/12/08 16:21:08CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   implemented LCFSEN
  CHANGES:                   Revision 1.10 2017/12/07 09:32:09CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   bugfix: routine LCFRCV_SenProcess now called
  CHANGES:                   Revision 1.9 2017/12/04 15:59:03CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   - removed debug signal arrays from TRJPLN
  CHANGES:                   - integrated crash free CP of TJASA
  CHANGES:                   - add LCF_VehDbgData to veh debug structure
  CHANGES:                   Revision 1.8 2017/11/29 11:21:31CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   compile error fixes
  CHANGES:                   Revision 1.6 2017/11/24 18:32:02CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   first full integration of mainstream code
  CHANGES:                   Revision 1.5 2017/11/20 19:03:41CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   LCF MFC431 R7.1
  CHANGES:                   Revision 1.4 2017/11/01 12:08:06CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.24.1.10.1.1 2017/09/22 16:07:28CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for new RTE
  CHANGES:                   Revision 1.24.1.10 2017/08/23 12:43:32CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.24.1.9 2017/08/23 12:26:49CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for MFC431HI28 R1.0
  CHANGES:                   Revision 1.24.1.8 2017/07/24 08:56:40CEST Grosu, George (uidl9584) 
  CHANGES:                   New CP
  CHANGES:                   Revision 1.24.1.7 2017/07/14 09:38:50CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.24.1.6 2017/07/13 17:59:33CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.24.1.5 2017/07/06 11:43:29CEST Grosu, George (uidl9584) 
  CHANGES:                   Fix QAC errors
  CHANGES:                   Revision 1.24.1.4 2017/07/05 14:10:50CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-6
  CHANGES:                   Revision 1.24.1.3 2017/06/30 16:07:23CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.24.1.2 2017/06/16 17:11:57CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA2
  CHANGES:                   Revision 1.24.1.1 2017/05/30 13:54:57CEST Grosu, George (uidl9584) 
  CHANGES:                   TJA initial version
  CHANGES:                   Revision 1.26 2017/05/08 13:07:09CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Move LCF_VEH (LaDMC) in 10ms task.
  CHANGES:                   Revision 1.25 2017/05/02 12:33:55CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Integration 3.1
  CHANGES:                   Revision 1.24 2017/04/07 20:10:02CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Solve QAC warning
  CHANGES:                   Revision 1.23 2017/04/07 19:51:50CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R3.0
  CHANGES:                   Revision 1.22 2017/03/17 13:20:07CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   New LCF algo in preparation for Hyundai R3.0
  CHANGES:                   Revision 1.20 2017/03/07 14:12:06CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   issue 570152: integrate new LCF features (reaction on road edges, LKA dead zone implementation, overall functionality prepared for Hyundai R3.0)
  CHANGES:                   Revision 1.19 2017/02/13 12:27:52CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Adapt for RTE 6.0
  CHANGES:                   Revision 1.18 2017/02/09 07:23:21CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update after code review. Implement new signals from HMIOC.
  CHANGES:                   Revision 1.17 2017/02/01 12:24:52CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   creation or R2.1 LCF functionality
  CHANGES:                   Revision 1.16 2017/01/19 11:20:39CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Function and performance improvements during 2.0 demo in Korea
  CHANGES:                   Revision 1.15 2017/01/18 08:14:34CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Function and performance improvements during 2.0 demo in Korea
  CHANGES:                   Revision 1.14 2017/01/10 20:02:41CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   issue 546865: LDP not functioning properly
  CHANGES:                   Revision 1.13 2016/11/25 14:41:59CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Adaption of ext headers to fit the generated ones
  CHANGES:                   Revision 1.12 2016/11/09 12:09:50CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   remove inclusion of algo_glob.h from ext headers (for compatibility with generated headers)
  CHANGES:                   Revision 1.11 2016/11/03 11:57:17CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R2.0
  CHANGES:                   Revision 1.10 2016/10/25 18:58:50CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Declared separate VehVelX variables for SEN and VEH. Rolled back to LCF cycle ids 23 and 90.
  CHANGES:                   Revision 1.9 2016/09/26 11:19:47CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Remove double declarations of variables
  CHANGES:                   Revision 1.8 2016/09/22 14:21:37CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Integrated LDW function. Removed EMT0OutputData.
  CHANGES:                   Revision 1.7 2016/09/08 08:49:49CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update LCF for R1.0 release
  CHANGES:                   Revision 1.6 2016/08/29 10:55:21CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Wrapper bugfixes during LKA demo
  CHANGES:                   Revision 1.5 2016/08/08 17:12:27CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   LCF TASK_IDs update
  CHANGES:                   Revision 1.4 2016/08/03 20:38:56CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Wrappers updated for new LaDMC algo code
  CHANGES:                   Revision 1.3 2016/07/27 21:56:54CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Fill SigHeader information. Correct eOpMode values.
  CHANGES:                   Revision 1.2 2016/07/27 09:27:26CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Fill eCompState information
  CHANGES:                   Revision 1.1 2016/07/25 12:09:37CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Bugfix in LCF wrappers (added null pointer checks for all required ports before LCF Process functions)
  CHANGES:                   Revision 1.0 2016/07/01 06:45:28CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/frame_veh/project.pj
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lcf_veh_main.h"
#include "LCFVEH/LCFVEH.h"
#include "lcf_veh_iface.h"  //MFC5J3

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
#ifndef LCF_VEH_SYNCREF_INTFVER
#define LCF_VEH_SYNCREF_INTFVER ((AlgoInterfaceVersionNumber_t)1)
#endif

/*****************************************************************************
  STRUCTURES AND TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

#ifdef _LCF_VEHOUTTYPE_T_
static LCF_VehOutType LCF_stVehOutData;
#endif /* _LCF_VEHOUTTYPE_T_*/

/* Pointers to required & service ports */
proLcfVehPrtList_t *pLcfVehProPorts = NULL;
const reqLcfVehPrtList_t *pLcfVehReqPorts = NULL;
const AS_t_ServiceFuncts *pLcfVehServices = NULL;

/* LCF_VEH debug data to be meas freezed */
#ifdef CM_SIM /*For Virtual Algo Simulation use non static Debug structure*/
LCF_VehDebugData_t LCFVeh_pstDbgData;
#else
//static LCF_VehDebugData_t LCFVeh_pstDbgData; //LCF_Debug
LCF_VehDebugData_t LCFVeh_pstDbgData; //LCF_Debug
#endif


FRAME_VehDbgType* const pFRAME_VehDbgData = &LCFVeh_pstDbgData.FRAME_VehDbgData;
LCFERR_VehDbgType* const pLCFERR_VehDbgData = &LCFVeh_pstDbgData.LCFERR_VehDbgData;
LaDMC_DebugBus_Type* const pLaDMC_DbgData = &LCFVeh_pstDbgData.LaDMC_DbgData;

/*Internal buffer of NVM data*/
static NVM_LcfLearningData_t nvmLcfInfo; 
NVM_LcfLearningData_t *pNvmLcfInfo = NULL; 

uint16 ui16_nvmLcfInfo_AdpCorrCounterPos_nu[LCF_NUM_ELEM_ADP_CORR_ARR];
uint16 ui16_nvmLcfInfo_AdpCorrCounterNeg_nu[LCF_NUM_ELEM_ADP_CORR_ARR];

/* Descriptors for meas freeze data */
/*Surpress QAC Messages (next 5 lines): File scope static, 'object_name', is only accessed in one function */
/*PRQA S 3218 7*/
static const AS_t_MeasInfo LCF_VehGenOutMTSDesc   = {(uint32)LCF_MEAS_ID_VEH_OUTPUT,       sizeof(LCF_VehGenericOutputs_t), TASK_ID_LCF_VEH, TASK_ID_LCF_VEH}; 
static const AS_t_MeasInfo LCF_VehToSenOutMTSDesc = {(uint32)LCF_MEAS_ID_VEH2SEN,          sizeof(LCF_VehToSen_t),          TASK_ID_LCF_VEH, TASK_ID_LCF_VEH}; 
#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
static const AS_t_MeasInfo LCF_SocToIucOutMTSDesc = {(uint32)LCF_MEAS_ID_SOC2IUC,          sizeof(LCF_LaDmcSocToIuc_t),     TASK_ID_LCF_VEH, TASK_ID_LCF_VEH};
#endif
static const AS_t_MeasInfo LCF_VehDebugMTSDesc    = {(uint32)LCF_MEAS_ID_DEBUG_VEH,        sizeof(LCF_VehDebugData_t),      TASK_ID_LCF_VEH, TASK_ID_LCF_VEH};
static const AS_t_MeasInfo LCF_VehCtrlMTSDesc     = {(uint32)LCF_VEH_MEAS_ID_CTRL_BSW_DATA,   sizeof(BaseCtrlData_t),       TASK_ID_LCF_VEH, TASK_ID_LCF_VEH};
static const AS_t_MeasInfo LCF_VehCompStMTSDesc   = {(uint32)LCF_VEH_MEAS_ID_ALGO_COMP_STATE, sizeof(AlgoCompState_t),      TASK_ID_LCF_VEH, TASK_ID_LCF_VEH};
static const AS_t_MeasInfo LCF_VehSyncRefMTSDesc  = {(uint32)LCF_VEH_MEAS_ID_SYNC_REF, sizeof(LcfVeh_SyncRef_t),      TASK_ID_LCF_VEH, TASK_ID_LCF_VEH};

/* BitField Integer containing Ports check status */
uint16 LCFVEH_proPorts_NullStatusCheck;
uint16 LCFVEH_reqPorts_NullStatusCheck;
uint16 LCFVEH_services_NullStatusCheck;
uint16 LCFVEH_reqPorts_SignalStatusOk; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK*/
uint16 LCFVEH_reqPorts_SignalStatusInit; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
uint16 LCFVEH_reqPorts_SignalStatusInvalid; /*Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status is AL_SIG_STATE_OK*/
uint16 LCFVEH_reqPorts_VersionNumberCheck; /*Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h*/

/* Create SyncRef structure and fill uiVersionNumber */
LcfVeh_SyncRef_t LcfVeh_SyncRef;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LcfVehProcess(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts);
static void LcfVehReset  (proLcfVehPrtList_t* const proPorts);
static void LcfVehSetSigHeader(SignalHeader_t* const psSigHeader, AlgoDataTimeStamp_t uiCtrlTmp, AlgoCycleCounter_t uiCtrlMeasCnt, AlgoCycleCounter_t uiCycleCnt);
static void LcfVehSetInfoDataProPorts(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts, AlgoCycleCounter_t uiCycleCnt);
static void LcfVehFillSyncRef(const reqLcfVehPrtList_t* const reqPorts, AlgoCycleCounter_t uiCycleCnt);
static void LcfVehMeasFreeze(const reqLcfVehPrtList_t* const reqPorts, const proLcfVehPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);
static void LcfVehPortsCheck(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* ****************************************************************************

  Functionname:     LcfVehProcess                                            */ /*!

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
static void LcfVehProcess(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts)
{
	uint8 i;
	
	LCFRCV_VehProcess();
	
#if defined(LCF_VEH_ERR_USED) && (LCF_VEH_ERR_USED == 1)	
    /* Check status of relevant inputs */ 		
    if (P_ERRIOVEH_EnableChecks_btf == 0u)
    {
        /*No error. Fill with 0 */
        for (i = 0u; i < ERRIOVEH_CHECKED_FUNCTIONS_NO; i++)
        {
            ERRIOVEH_ErrStateArray[i] = LCF_NO_ERROR;
        }
    }
    else
    {
        ERRIOVEH_InputsCheck(reqPorts);
    }
#endif
	
	LCF_VehProcess();
	LCFSND_VehProcess();
    
    /* Fill comp state */
	proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_RUNNING;
	proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK; /*L3D_ALGO_23757*/
	
	/* L3D_ALGO_23757: In case of successful execution the signal state in the signal header shall be 'AL_SIG_STATE_OK'*/
	proPorts->pLcfVehOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
    proPorts->pLcfVehOutputToSenData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
    proPorts->pLcfLaDmcSocToIuc->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
	#endif
	#if (defined(LCF_NVM_USED) && (LCF_NVM_USED == 1))
	proPorts->pNvmLcfData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
	#endif
	
#if defined(LCF_VEH_ERR_USED) && (LCF_VEH_ERR_USED == 1)	
    if(P_ERRIOVEH_EnableChecks_btf != 0u)
    {
		S_ERRVEH_ErrMatrix_btf[ERRVEH_enSenTask] = GET_S_LCFERR_SenErrorToVeh_btf();
        ERRVEH_Process();
    }
#endif
}

/* ****************************************************************************

  Functionname:     LcfVehReset                                         */ /*!

  @brief            Reset of the component

  @description      Initialization of all internal data storage.
                    Shall be called once before processing starts

  @param[in,out]    proPorts : pointer on the provided ports structure

  @return           -

  @pre              -
  @post             All internal values and all interfaces are initialized
                    to default values

  @author           

**************************************************************************** */
static void LcfVehReset(proLcfVehPrtList_t* const proPorts)
{    
	/* Init Errors */
	proPorts->pAlgoCompState->eErrorCode = (CompErrorCode_t)COMP_ERROR_NO_ERROR;
	proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_NOT_INITIALIZED;
	
	/* Ensure tunable parameters are copied at each startup */
	LCFVeh_pstDbgData.FRAME_VehDbgData.uiTunParCopied = 0u;
    LCFVeh_pstDbgData.FRAME_VehDbgData.uiVdyParCopied = 0u;
    LCFVeh_pstDbgData.FRAME_VehDbgData.uiNvmDataValid = 0u;

	/*! Initialize MeasFreeze */

	/*! Reset algo data to initial values */
	LCFRCV_VehReset();
	LCF_VehReset();
	#if defined(LCF_VEH_ERR_USED) && (LCF_VEH_ERR_USED == 1)
    ERRVEH_Reset();
	#endif
	LCFSND_VehReset();
    
    /* L3D_ALGO_23195: Except for the comp state and the NVM structure the signal state shall be set to 'AL_SIG_STATE_INIT'. */
	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
    proPorts->pLcfLaDmcSocToIuc->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INIT;
	#endif
    proPorts->pLcfVehOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INIT;
    proPorts->pLcfVehOutputToSenData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INIT;
    
	proPorts->pAlgoCompState->eShedulerSubModeRequest = (BaseSchedulingSubMode_t)BASE_SSM_NONE; /*L3D_ALGO_24374; LCF does not request GS mode changes*/
	proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK;
	proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_SUCCESS;	
}

/* ****************************************************************************

  Functionname:     LcfVehSetSigHeader                                         */ /*!

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
static void LcfVehSetSigHeader(SignalHeader_t* const psSigHeader, AlgoDataTimeStamp_t uiCtrlTmp, AlgoCycleCounter_t uiCtrlMeasCnt, AlgoCycleCounter_t uiCycleCnt)
{
    /* Fill signal header with the received arguments */
    psSigHeader->uiTimeStamp = uiCtrlTmp;
    psSigHeader->uiMeasurementCounter = uiCtrlMeasCnt;
    psSigHeader->uiCycleCounter = uiCycleCnt;
}

/* ****************************************************************************

  Functionname:     LcfVehSetInfoDataProPorts                                         */ /*!

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
static void LcfVehSetInfoDataProPorts(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts, AlgoCycleCounter_t uiCycleCnt)
{
   	/* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* MiCr: Defensive programming */
    /* PRQA S 2981 3 */
	AlgoDataTimeStamp_t uiCtrlTimeStamp = 0U;
	AlgoCycleCounter_t uiCtrlMeasCounter = 0U;
    uint8 uiAlgoVerInfoFillSize = 0U;

    /* Fill version numbers of provided ports */
    proPorts->pAlgoCompState->uiVersionNumber         = (AlgoInterfaceVersionNumber_t)COMP_STATE_INTFVER;
    proPorts->pLcfVehOutputData->uiVersionNumber      = (AlgoInterfaceVersionNumber_t)LCF_VEH_OUTPUT_INTFVER;
    proPorts->pLcfVehOutputToSenData->uiVersionNumber = (AlgoInterfaceVersionNumber_t)LCF_VEH2SEN_INTFVER;

	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)) 
    proPorts->pLcfLaDmcSocToIuc->uiVersionNumber      = (AlgoInterfaceVersionNumber_t)LCF_SOC2IUC_INTFVER;
	#endif
	#if (defined(LCF_NVM_USED) && (LCF_NVM_USED == 1))
    proPorts->pNvmLcfData->uiVersionNumber            = (AlgoInterfaceVersionNumber_t)LCF_LEARNDATA_INTFVER;
	#endif
   
    /* Fill signal headers of provided ports */
    uiCtrlTimeStamp = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    uiCtrlMeasCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
    
    LcfVehSetSigHeader(&(proPorts->pAlgoCompState->sSigHeader),         uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
    LcfVehSetSigHeader(&(proPorts->pLcfVehOutputData->sSigHeader),      uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
    LcfVehSetSigHeader(&(proPorts->pLcfVehOutputToSenData->sSigHeader), uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
    LcfVehSetSigHeader(&(proPorts->pLcfLaDmcSocToIuc->sSigHeader),      uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt); 
	#endif
	#if (defined(LCF_NVM_USED) && (LCF_NVM_USED == 1))	
    LcfVehSetSigHeader(&(proPorts->pNvmLcfData->sSigHeader),            uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
	#endif

    /* Fill additional Algo comp state information */
    proPorts->pAlgoCompState->eShedulerSubModeRequest = (BaseSchedulingSubMode_t)BASE_SSM_NONE; /*L3D_ALGO_24374; LCF does not request GS mode changes*/
    proPorts->pAlgoCompState->uiAlgoVersionNumber     = (AlgoComponentVersionNumber_t)LCFALL_SW_VERSION_NUMBER;
    proPorts->pAlgoCompState->uiApplicationNumber     = (AlgoApplicationNumber_t)GET_LCF_PRJ_NR(); /*decided to use uiApplicationNumber to indicate the current project*/
    /*Surpress QAC Messages (next line): Using conditional operator in a macro.
    Conditional operator is strictly necessary for macro statement*/
    /*PRQA S 3491 1*/
    uiAlgoVerInfoFillSize =(uint8) MIN(sizeof(LCF_CHECKPOINT),(uint8)((uint8)ALGO_VERSION_INFO_LENGTH-1u));
    /*Surpress QAC Messages (next line): Implicit conversion from a pointer to object type to a pointer to void.
    Intentional cast to pointer to void with the purpose to match service function prototypes*/
    /*PRQA S 315 1*/
    (void)memcpy(proPorts->pAlgoCompState->AlgoVersionInfo, LCF_CHECKPOINT, (uint32)uiAlgoVerInfoFillSize);
    proPorts->pAlgoCompState->AlgoVersionInfo[uiAlgoVerInfoFillSize] = 0U;
}

/* ****************************************************************************

  Functionname:     LcfVehFillSyncRef                                         */ /*!

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
static void LcfVehFillSyncRef(const reqLcfVehPrtList_t* const reqPorts, AlgoCycleCounter_t const uiCycleCnt)
{
    /* QAF rule 3.9 : This initialization is redundant. The value of this object is never used before being modified */
    /* MiCr: Defensive programming */
    /* PRQA S 2981 2 */
	AlgoDataTimeStamp_t uiCtrlTimeStamp = 0U;
	AlgoCycleCounter_t uiCtrlMeasCounter = 0U;
    
    /* L3D_ALGO_22283: Fill LcfVeh_SyncRef */
    /* Fill version number of LcfVeh_SyncRef structure */
    LcfVeh_SyncRef.uiVersionNumber = LCF_VEH_SYNCREF_INTFVER;
    
    /* Fill signal header of LcfVeh_SyncRef structure */
    uiCtrlTimeStamp = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    uiCtrlMeasCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
    LcfVehSetSigHeader(&(LcfVeh_SyncRef.sSigHeader), uiCtrlTimeStamp, uiCtrlMeasCounter, uiCycleCnt);
    LcfVeh_SyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
	
    /* Fill sBaseCtrl of LcfVeh_SyncRef structure */
    LcfVeh_SyncRef.sBaseCtrl.uiVersionNumber = reqPorts->pBaseCtrlData->uiVersionNumber;
    LcfVeh_SyncRef.sBaseCtrl.sSigHeader.uiTimeStamp = reqPorts->pBaseCtrlData->sSigHeader.uiTimeStamp;
    LcfVeh_SyncRef.sBaseCtrl.sSigHeader.uiMeasurementCounter = reqPorts->pBaseCtrlData->sSigHeader.uiMeasurementCounter;
    LcfVeh_SyncRef.sBaseCtrl.sSigHeader.uiCycleCounter = reqPorts->pBaseCtrlData->sSigHeader.uiCycleCounter;
    LcfVeh_SyncRef.sBaseCtrl.sSigHeader.eSigStatus = reqPorts->pBaseCtrlData->sSigHeader.eSigStatus;
    LcfVeh_SyncRef.sBaseCtrl.eOpMode = reqPorts->pBaseCtrlData->eOpMode;
    LcfVeh_SyncRef.sBaseCtrl.eSchedulingMode = reqPorts->pBaseCtrlData->eSchedulingMode;
    LcfVeh_SyncRef.sBaseCtrl.eSchedulingSubMode = reqPorts->pBaseCtrlData->eSchedulingSubMode;
    
    /* Fill SyncRef signal header for every required port */	  
    LcfVeh_SyncRef.pAbdOutputData = reqPorts->pAbdOutputData->sSigHeader;
	#if (defined(USE_IPC_PARAMS) && (USE_IPC_PARAMS == 1))
    LcfVeh_SyncRef.pCParDmc = reqPorts->pCParDmc->sSigHeader;
    LcfVeh_SyncRef.pCParKmc = reqPorts->pCParKmc->sSigHeader;
	#endif
    LcfVeh_SyncRef.pLcfInputData = reqPorts->pLcfInputData->sSigHeader;
    LcfVeh_SyncRef.pLcfSenOutputData = reqPorts->pLcfSenOutputData->sSigHeader;
    LcfVeh_SyncRef.pLcfVehInputFromSenData = reqPorts->pLcfVehInputFromSenData->sSigHeader;
    LcfVeh_SyncRef.pVdyOffsets = reqPorts->pVdyOffsets->sSigHeader;
    LcfVeh_SyncRef.pVehDyn = reqPorts->pVehDyn->sSigHeader;
    LcfVeh_SyncRef.pVehPar = reqPorts->pVehPar->sSigHeader;
    LcfVeh_SyncRef.pVehSig = reqPorts->pVehSig->sSigHeader;		
	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
    LcfVeh_SyncRef.pLcfLaDmcIucToSoc = reqPorts->pLcfLaDmcIucToSoc->sSigHeader;
    #endif    
}

/* ****************************************************************************

  Functionname:     LcfVehMeasFreeze                                         */ /*!

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
static void LcfVehMeasFreeze(const reqLcfVehPrtList_t* const reqPorts, const proLcfVehPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
{
    /* Runtime measurement is done via sections of code in "lcf_veh_service.h" */
    #define	LCF_VEH_MEASF_START
	#include "lcf_veh_service.h"

    /* L3D_ALGO_24516: Meas freeze relevant data */
    /*Surpress QAC Message: Cast from a pointer to object type to a pointer to void.
    Intentional cast to pointer to void with the purpose to match service function prototypes*/
    /*PRQA S 314 7*/
    (void)services->pfMeasFreeze(&LCF_VehGenOutMTSDesc,  (const void *)proPorts->pLcfVehOutputData,     (MEAS_Callback_t) 0UL);
    (void)services->pfMeasFreeze(&LCF_VehToSenOutMTSDesc,(const void *)proPorts->pLcfVehOutputToSenData,(MEAS_Callback_t) 0UL);
	#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
    (void)services->pfMeasFreeze(&LCF_SocToIucOutMTSDesc,(const void *)proPorts->pLcfLaDmcSocToIuc,     (MEAS_Callback_t) 0UL);
	#endif
    (void)services->pfMeasFreeze(&LCF_VehDebugMTSDesc,   (const void *)&LCFVeh_pstDbgData,              (MEAS_Callback_t) 0UL); 
    (void)services->pfMeasFreeze(&LCF_VehCtrlMTSDesc,    (const void *)reqPorts->pBaseCtrlData,         (MEAS_Callback_t) 0UL); 
    (void)services->pfMeasFreeze(&LCF_VehCompStMTSDesc,  (const void *)proPorts->pAlgoCompState,        (MEAS_Callback_t) 0UL);
    (void)services->pfMeasFreeze(&LCF_VehSyncRefMTSDesc, (const void *)(&LcfVeh_SyncRef),               (MEAS_Callback_t) 0UL);

	#define	LCF_VEH_MEASF_STOP
	#include "lcf_veh_service.h"
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
	LCFVEH_reqPorts_NullCheckFlags_t portPos, AlgoInterfaceVersionNumber_t portRTEVersionNumber, uint16 * reqPortsNullStatusVar, 
	uint16 * reqPortsSigStOKStatusVar, uint16 * reqPortsSigStInitStatusVar, uint16 * reqPortsSigStInvStatusVar, uint16 * reqPortsVerNumStatusVar)
{
	uint8 isPortNull = (uint8)(portPtr == NULL);
	if (isPortNull !=0u)
	{
		*(reqPortsNullStatusVar) |= (uint16)(isPortNull) << (uint16)(portPos);
	}
	else
	{
		if (portSigStatus ==(AlgoSignalState_t)AL_SIG_STATE_INIT)
		{
			*(reqPortsSigStInitStatusVar) |= ((uint16)(1u)<< (uint16)(portPos));
			*(reqPortsSigStOKStatusVar) &= ~((uint16)(1u) << (uint16)(portPos));
		}
		else if (portSigStatus != (AlgoSignalState_t)AL_SIG_STATE_OK)
		{
			*(reqPortsSigStInvStatusVar) |= ((uint16)(1u) << (uint16)(portPos));
			*(reqPortsSigStOKStatusVar) &= ~((uint16)(1u) << (uint16)(portPos));
		}
		*(reqPortsVerNumStatusVar) |= ((uint16)(portActualVersionNumber != portRTEVersionNumber) << (uint16)(portPos));
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
static void CheckProPortsToCheckAttributes(void * portPtr, LCFVEH_proPorts_NullCheckFlags_t portPos, uint16 * proPortsNullStatusVar)
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
static void CheckServicesToCheckAttributes(void * portPtr, LCFVEH_services_NullCheckFlags_t portPos, uint16 * serviceNullStatusVar)
{
	*(serviceNullStatusVar) |= (uint16)(portPtr == NULL) << (uint16)(portPos);
}

/* ****************************************************************************

  Functionname:     LcfVehPortsCheck                                         */ /*!

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
static void LcfVehPortsCheck(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
{
	uint32 LCFVEH_ErrorEvents_btf = 0u;
	
	/* Reset check status variables (bit fields) */
	LCFVEH_proPorts_NullStatusCheck = 0u; /* Zero (0) means that corresponding port is not NULL */
	LCFVEH_reqPorts_NullStatusCheck = 0u; /* Zero (0) means that corresponding port is not NULL */
	LCFVEH_services_NullStatusCheck = 0u; /* Zero (0) means that corresponding port is not NULL */
	LCFVEH_reqPorts_SignalStatusOk =(uint16)(((uint16)1u << (uint16)((uint16)LCFVEH_REQUIRED_PORTS_COUNTER+1u))-1u); /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_OK and (1) - means that port's signal status == AL_SIG_STATE_OK */
	LCFVEH_reqPorts_SignalStatusInit = 0u; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INIT, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
	LCFVEH_reqPorts_SignalStatusInvalid = 0u; /* Zero (0) means that corresponding port's signal status != AL_SIG_STATE_INVALID, if LCFVEH_reqPorts_SignalStatusInit and LCFVEH_reqPorts_SignalStatusInvalid is (0) - means signal status might be AL_SIG_STATE_OK */
	LCFVEH_reqPorts_VersionNumberCheck = 0u; /* Zero (0) means that corresponding port's version number is equal (==) to the one in Rte_Algo_Types.h */
	
	/* Check proPorts, reqPorts and services if they are not NULL pointers */
	LCFVEH_proPorts_NullStatusCheck = (uint16)(proPorts == NULL);
	LCFVEH_reqPorts_NullStatusCheck = (uint16)(reqPorts == NULL);
	LCFVEH_services_NullStatusCheck = (uint16)(services == NULL);
	
	/* Check ALL services ports if they are not NULL pointers */
	if(LCFVEH_services_NullStatusCheck ==0u)
	{	
		CheckServicesToCheckAttributes((void*)services->pfMeasFreeze, MEAS_FREEZE_IS_NULL, &LCFVEH_services_NullStatusCheck );
		//CheckServicesToCheckAttributes((void*)services->pfDem_SetEventStatus, DEM_SET_EVENT_STATUS_IS_NULL, &LCFVEH_services_NullStatusCheck );   MFC5J3
		//CheckServicesToCheckAttributes((void*)services->pfDem_SetEventStatusPreExtData, DEM_SET_EVENT_STATUS_PRE_EXT_DATA_IS_NULL, &LCFVEH_services_NullStatusCheck );
		//CheckServicesToCheckAttributes((void*)services->pfRTAAlgoServiceAddEvent, RTA_ALGO_SERVICE_ADD_EVENT_IS_NULL, &LCFVEH_services_NullStatusCheck );
		//CheckServicesToCheckAttributes((void*)services->pfMeasStartFuncCycle, MEAS_START_FUNC_CYCLE_IS_NULL, &LCFVEH_services_NullStatusCheck );
	}
	else{/*null port was detected*/}
	
	/* Check ALL proPorts ports if they are not NULL pointers */
	if(LCFVEH_proPorts_NullStatusCheck ==0u)
	{
	/*Surpress QAC Messages (next line): Cast from a pointer type to a pointer to void.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0314 1*/
		CheckProPortsToCheckAttributes((void*)proPorts->pAlgoCompState, ALGO_COMP_STATE_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
	#if defined(LCF_VEH_PPORT_PLCFLADMCSOCTOIUC)/*Check if optional port is present in GA*/
	/*Surpress QAC Messages (next line): Cast from a pointer type to a pointer to void.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0314 1*/
		CheckProPortsToCheckAttributes((void*)proPorts->pLcfLaDmcSocToIuc, LCF_LADMC_SOC_TO_IUC_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
	#else
		CheckProPortsToCheckAttributes((void*)NULL, LCF_LADMC_SOC_TO_IUC_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
	#endif
	/*Surpress QAC Messages (next line): Cast from a pointer type to a pointer to void.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0314 1*/
		CheckProPortsToCheckAttributes((void*)proPorts->pLcfVehOutputData, VEH_OUTPUT_DATA_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
		CheckProPortsToCheckAttributes((void*)proPorts->pLcfVehOutputToSenData, VEH_OUTPUT_TO_SEN_DATA_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
	#if defined(LCF_VEH_PPORT_PNVMLCFDATA)/*Check if optional port is present in GA*/	
	/*Surpress QAC Messages (next line): Cast from a pointer type to a pointer to void.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0314 1*/
		CheckProPortsToCheckAttributes((void*)proPorts->pNvmLcfData, NVM_LCF_LEARNING_DATA_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
	#else
		CheckProPortsToCheckAttributes((void*)NULL, NVM_LCF_LEARNING_DATA_IS_NULL, &LCFVEH_proPorts_NullStatusCheck );
	#endif
	}
	else{/*null port was detected*/}
		
	/* Check ALL reqPorts ports */
	if(LCFVEH_reqPorts_NullStatusCheck ==0u)
	{		
	/* Check pBaseCtrlData reqPort */
	#if defined(LCF_VEH_RPORT_PBASECTRLDATA) 
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311, 2811 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pBaseCtrlData, GET_SIGNAL_STATUS(reqPorts->pBaseCtrlData), GET_VERSION_NUMBER(reqPorts->pBaseCtrlData), BASE_CTRL_DATA_CHECK_BIT, BASE_CTRL_DATA_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, BASE_CTRL_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pAbdOutputData reqPort */
	#if defined(LCF_VEH_RPORT_PABDOUTPUTDATA) 
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pAbdOutputData, GET_SIGNAL_STATUS(reqPorts->pAbdOutputData), GET_VERSION_NUMBER(reqPorts->pAbdOutputData), ABD_OUTPUT_DATA_CHECK_BIT, ABD_OUTPUT_DATA_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, ABD_OUTPUT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pCParDmc reqPort */
	#if defined(LCF_VEH_RPORT_PCPARDMC)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pCParDmc, GET_SIGNAL_STATUS(reqPorts->pCParDmc), GET_VERSION_NUMBER(reqPorts->pCParDmc), CPAR_DMC_CHECK_BIT, LCF_TUN_PAR_DMC_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, CPAR_DMC_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
		
	/* Check pCParKmc reqPort */
	#if defined(LCF_VEH_RPORT_PCPARKMC)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pCParKmc, GET_SIGNAL_STATUS(reqPorts->pCParKmc), GET_VERSION_NUMBER(reqPorts->pCParKmc), CPAR_KMC_CHECK_BIT, LCF_TUN_PAR_KMC_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, CPAR_KMC_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfInputData reqPort */
	#if defined(LCF_VEH_RPORT_PLCFINPUTDATA) 
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfInputData, GET_SIGNAL_STATUS(reqPorts->pLcfInputData), GET_VERSION_NUMBER(reqPorts->pLcfInputData), LCF_INPUT_DATA_CHECK_BIT, LCF_INPUT_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_INPUT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfLaDmcIucToSoc reqPort */
	#if defined(LCF_VEH_RPORT_PLCFLADMCIUCTOSOC)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfLaDmcIucToSoc, GET_SIGNAL_STATUS(reqPorts->pLcfLaDmcIucToSoc), GET_VERSION_NUMBER(reqPorts->pLcfLaDmcIucToSoc), LCF_LADMC_IUC_TO_SOC_CHECK_BIT, LCF_IUC2SOC_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_LADMC_IUC_TO_SOC_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfSenOutputData reqPort */
	#if defined(LCF_VEH_RPORT_PLCFSENOUTPUTDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfSenOutputData, GET_SIGNAL_STATUS(reqPorts->pLcfSenOutputData), GET_VERSION_NUMBER(reqPorts->pLcfSenOutputData), LCF_SEN_OUTPUT_DATA_CHECK_BIT, LCF_SEN_OUTPUT_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_SEN_OUTPUT_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pLcfVehInputFromSenData reqPort */
	#if defined(LCF_VEH_RPORT_PLCFVEHINPUTFROMSENDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pLcfVehInputFromSenData, GET_SIGNAL_STATUS(reqPorts->pLcfVehInputFromSenData), GET_VERSION_NUMBER(reqPorts->pLcfVehInputFromSenData), LCF_VEH_INPUT_FROM_SEN_DATA_CHECK_BIT, LCF_SEN2VEH_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, LCF_VEH_INPUT_FROM_SEN_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pNvmLcfData reqPort */
	#if defined(LCF_VEH_RPORT_PNVMLCFDATA)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pNvmLcfData, GET_SIGNAL_STATUS(reqPorts->pNvmLcfData), GET_VERSION_NUMBER(reqPorts->pNvmLcfData), NVM_LCF_DATA_CHECK_BIT, LCF_LEARNDATA_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, NVM_LCF_DATA_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pVdyOffsets reqPort */
	#if defined(LCF_VEH_RPORT_PVDYOFFSETS)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVdyOffsets, GET_SIGNAL_STATUS(reqPorts->pVdyOffsets), GET_VERSION_NUMBER(reqPorts->pVdyOffsets), VDY_OFFSETS_CHECK_BIT, VDY_OFFSETS_INTFVER,
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VDY_OFFSETS_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pVehDyn reqPort */
	#if defined(LCF_VEH_RPORT_PVEHDYN)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVehDyn, GET_SIGNAL_STATUS(reqPorts->pVehDyn), GET_VERSION_NUMBER(reqPorts->pVehDyn), VEH_DYN_CHECK_BIT, VDY_VEH_DYN_INTFVER_LCF,  //MFC5J3
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VEH_DYN_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pVehPar reqPort */
	#if defined(LCF_VEH_RPORT_PVEHPAR)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVehPar, GET_SIGNAL_STATUS(reqPorts->pVehPar), GET_VERSION_NUMBER(reqPorts->pVehPar), VEH_PAR_CHECK_BIT, BSW_VEH_PAR_INTFVER_LCF,  //MFC5J3
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VEH_PAR_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
	
	/* Check pVehSig reqPort */
	#if defined(LCF_VEH_RPORT_PVEHSIG)
	/*Surpress QAC Messages (next line): Dangerous pointer cast results in loss of const qualification.
	Intentional cast, pointer only used for null check*/
	/*PRQA S 0311 1*/
		CheckReqPortsToCheckAttributes((void*)reqPorts->pVehSig, GET_SIGNAL_STATUS(reqPorts->pVehSig), GET_VERSION_NUMBER(reqPorts->pVehSig), VEH_SIG_CHECK_BIT, BSW_VEH_SIG_INTFVER_LCF,  //MFC5J3
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#else
		CheckReqPortsToCheckAttributes((void*)NULL, INVALID_SIG_STATE, INVALID_INTFVER, VEH_SIG_CHECK_BIT, INVALID_INTFVER, 
			&LCFVEH_reqPorts_NullStatusCheck, &LCFVEH_reqPorts_SignalStatusOk, &LCFVEH_reqPorts_SignalStatusInit, &LCFVEH_reqPorts_SignalStatusInvalid, &LCFVEH_reqPorts_VersionNumberCheck);
	#endif
		
		/* Set error flags for Error Handler Component (LCFERR), write LCF_ErrorEvents_btf variable */
		/* Reset ErrorEvents bitfield */
		LCF_ErrorEvents_btf = 0u; /* 0 on all bits means no error event */
		/* Write ErrorEvents according to ports actual status */
		
		LCF_ErrorEvents_btf |= (uint16)((uint16)(((uint16)LCFVEH_services_NullStatusCheck & LCFVEH_SERVICE_PORTS_NULL_CHECK_MASK) != 0u) << (uint16)SERVICE_PORT_IS_NULL_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint16)((uint16)(((uint16)LCFVEH_proPorts_NullStatusCheck & LCFVEH_PROVIDED_PORTS_NULL_CHECK_MASK) != 0u) << (uint16)PROVIDED_PORT_IS_NULL_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint16)((uint16)(((uint16)LCFVEH_reqPorts_NullStatusCheck & LCFVEH_REQUIRED_PORTS_NULL_CHECK_MASK) != 0u) << (uint16)REQUIRED_PORT_IS_NULL_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint16)((uint16)((uint16)LCFVEH_reqPorts_SignalStatusInit & LCFVEH_REQUIRED_PORTS_SIGSTATUS_INIT_MASK) << (uint16)((uint16)REQUIRED_PORT_INIT_ERRFLAG-1u));
		LCF_ErrorEvents_btf |= (uint16)((uint16)(((uint16)LCFVEH_reqPorts_SignalStatusInvalid & LCFVEH_REQUIRED_PORTS_SIGSTATUS_INVALID_MASK) != 0u) << (uint16)REQUIRED_PORT_INVALID_ERRFLAG);
		LCF_ErrorEvents_btf |= (uint16)((uint16)(((uint16)LCFVEH_reqPorts_VersionNumberCheck & LCFVEH_REQUIRED_PORTS_VERNUM_CHECK_MASK) != 0u) << (uint16)REQUIRED_PORT_BAD_VERSION_NUMBER_ERRFLAG);
		
	}
	else{/*null port was detected*/}
 S_ERRVEH_ErrMatrix_btf[ERRVEH_enVEHWrapper] = LCF_ErrorEvents_btf;
}

/* ****************************************************************************

  Functionname:     LcfVehExec                                              */ /*!

  @brief            LCF_VEH main function with input and output parameters

  @description      -

  @param[in]        reqPorts : pointer on the required ports structure
  @param[in,out]    proPorts : pointer on the provided ports structure
  @param[in]        services : pointer on the services structure

  @return           -

  @pre              -
  @post             -

  @author           

**************************************************************************** */
BaseReturnCode_t LcfVehExec(const reqLcfVehPrtList_t* const reqPorts, proLcfVehPrtList_t* const proPorts, const AS_t_ServiceFuncts* const services)
{
	static uint8 ui8VehDataPtrUninit = TRUE;
	static AlgoCycleCounter_t uiCycleCnt = 0U;
	BaseReturnCode_t uiRetCode = (BaseReturnCode_t)BASE_RETURN_ERROR;
	
    /*GeGr: Initialize pointers before using*/
  	pLcfVehProPorts = proPorts;
	pLcfVehReqPorts = reqPorts;
	pLcfVehServices = services;
	pNvmLcfInfo = &nvmLcfInfo;
	
	if(ui8VehDataPtrUninit !=0u)
	{
		ui8VehDataPtrUninit = FALSE;
		
#ifdef _LCF_VEHDBGTYPE_T_
		LCF_VehInitDbgPtr(&LCFVeh_pstDbgData.LCF_pstVehDbgData);
#endif /*_LCF_VEHDBGTYPE_T_*/
#ifdef _LCF_VEHOUTTYPE_T_
		LCF_VehInitOutPtr(&LCF_stVehOutData);
#endif /* _LCF_VEHOUTTYPE_T_*/
	}

	LcfVehPortsCheck(reqPorts, proPorts, services);
	
	/*Update Debug signals with the results from the input checks*/
    pFRAME_VehDbgData->D_LCFVEH_proPorts_NullStatusCheck      = LCFVEH_proPorts_NullStatusCheck;
    pFRAME_VehDbgData->D_LCFVEH_reqPorts_NullStatusCheck      = LCFVEH_reqPorts_NullStatusCheck;
    pFRAME_VehDbgData->D_LCFVEH_services_NullStatusCheck      = LCFVEH_services_NullStatusCheck;
    pFRAME_VehDbgData->D_LCFVEH_reqPorts_SignalStatusOk       = LCFVEH_reqPorts_SignalStatusOk;
    pFRAME_VehDbgData->D_LCFVEH_reqPorts_SignalStatusInit     = LCFVEH_reqPorts_SignalStatusInit;
    pFRAME_VehDbgData->D_LCFVEH_reqPorts_SignalStatusInvalid  = LCFVEH_reqPorts_SignalStatusInvalid;
    pFRAME_VehDbgData->D_LCFVEH_reqPorts_VersionNumberCheck   = LCFVEH_reqPorts_VersionNumberCheck;
	
    /*L3D_ALGO_21600*/
	if  (((LCFVEH_proPorts_NullStatusCheck & LCFVEH_PROVIDED_PORTS_NULL_CHECK_MASK) == 0u) && ((LCFVEH_services_NullStatusCheck & LCFVEH_SERVICE_PORTS_NULL_CHECK_MASK) == 0u) 
		&& ((LCFVEH_reqPorts_NullStatusCheck & LCFVEH_BASECTRLDATA_CHECK_MASK) == 0u) 
		&& ((LCFVEH_reqPorts_SignalStatusOk & LCFVEH_BASECTRLDATA_CHECK_MASK) == (LCFVEH_BASECTRLDATA_CHECK_MASK)) && ((LCFVEH_reqPorts_VersionNumberCheck & LCFVEH_BASECTRLDATA_CHECK_MASK) == 0u))
    {
        /* We can proceed with the Exec function now */
                
        /* Runtime measurement is done via sections of code in "lcf_veh_service.h" */
        #define	VEH_WRP_VEHPROCESS_START
        #include "lcf_veh_service.h"
        
        /* Cycle counter incremented every time Exec normal behaviour is executed (no BASE_RETURN_ERROR) */
        uiCycleCnt++;

        /* Meas start service */
       // services->pfMeasStartFuncCycle(TASK_ID_LCF_VEH);  //MFC5J3

        /*! At this place it is necessary to test lcfOpMode directly to get an initialized component */
        switch (reqPorts->pBaseCtrlData->eOpMode)
        {
        case (uint8)BASE_OM_RESET:
            if (((LCFVEH_reqPorts_NullStatusCheck & LCFVEH_NVM_LCF_DATA_CHECK_MASK) == 0u)
				/* && ((LCFVEH_reqPorts_SignalStatusOk & LCFVEH_NVM_LCF_DATA_CHECK_MASK) == (1 << LCFVEH_NVM_LCF_DATA_CHECK_MASK)) 
				&& ((LCFVEH_reqPorts_VersionNumberCheck & LCFVEH_NVM_LCF_DATA_CHECK_MASK) == 0u)*/) /*TO DO: uncomment version number check */
            {
                LcfVehReset(proPorts);
            }
            break; /*L3D_ALGO_23195; no calculation should be done in RESET*/
        case (uint8)BASE_OM_IDLE:
            /*L3D_ALGO_24374; COMP_STATE_NOT_RUNNING shall be set if the algo is called in the idle op mode; L3D_ALGO_22628*/
            proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_NOT_RUNNING;
            proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK;
            /*L3D_ALGO_22628: Except for the comp state and the NVM structure the signal state shall be 'AL_SIG_STATE_INVALID'.*/
            proPorts->pLcfVehOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INVALID;
            proPorts->pLcfVehOutputToSenData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INVALID;
			#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
            proPorts->pLcfLaDmcSocToIuc->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INVALID;
			#endif
			#if (defined(LCF_NVM_USED) && (LCF_NVM_USED == 1))
			proPorts->pNvmLcfData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_INVALID;
			#endif
            break; /*L3D_ALGO_22628: no calculation shall be done in IDLE*/
        case (uint8)BASE_OM_DEMO:
            /*L3D_ALGO_22416*/
            proPorts->pAlgoCompState->eCompState = (CompState_t)COMP_STATE_SUCCESS;
            proPorts->pAlgoCompState->eGenAlgoQualifier = (GenAlgoQualifiers_t)ALGO_QUAL_OK;
			proPorts->pLcfVehOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
            proPorts->pLcfVehOutputToSenData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
			#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
            proPorts->pLcfLaDmcSocToIuc->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
			#endif
			#if (defined(LCF_NVM_USED) && (LCF_NVM_USED == 1))
			proPorts->pNvmLcfData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
			#endif
            /*TODO: fill demo values for all outputs*/
            break; /*L3D_ALGO_22416: no calculation shall be done in DEMO*/
        case (uint8)BASE_OM_RUN: /*TODO: check for other op modes*/
            if(((LCFVEH_reqPorts_NullStatusCheck & LCFVEH_REQUIRED_PORTS_NULL_CHECK_MASK) == 0u)
				/*&& ((LCFVEH_reqPorts_VersionNumberCheck & LCFVEH_REQUIRED_PORTS_VERNUM_CHECK_MASK) == 0u) 
				&& ((LCFVEH_reqPorts_SignalStatusOk & LCFVEH_REQUIRED_PORTS_SIGST_CHECK_MASK) == LCFVEH_REQUIRED_PORTS_SIGST_CHECK_MASK)*/) /*TO DO: uncomment version number check */
            {
				LcfVehFillSyncRef(reqPorts, uiCycleCnt);/* Call SyncRef only in Running mode to ensure that all the needed data is available */
                LcfVehProcess(reqPorts, proPorts);
            }
			else{
				//services->pfDem_SetEventStatus(LCF_VEH_FUSI_ERROR, DEM_EVENT_STATUS_FAILED);  //MFC5J3
			}
            break;
        default:
			proPorts->pLcfVehOutputData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
            proPorts->pLcfVehOutputToSenData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
			#if (defined(LCF_IUC_USED) && (LCF_IUC_USED == 1))
            proPorts->pLcfLaDmcSocToIuc->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
			#endif
			#if (defined(LCF_NVM_USED) && (LCF_NVM_USED == 1))
			proPorts->pNvmLcfData->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
			#endif
            break;
        }
		/* Fill basic information in provided ports */
        LcfVehSetInfoDataProPorts(reqPorts, proPorts, uiCycleCnt);
		
		#if defined(LCF_NVM_USED) && (LCF_NVM_USED == 1)
        /* L3D_ALGO_23195, L3D_ALGO_24516: Copy NVM data from internal one to provided port in all opModes */
        (void)memcpy((void*)proPorts->pNvmLcfData, (const void*)&(nvmLcfInfo), CML_Min(sizeof(nvmLcfInfo),sizeof(*(proPorts->pNvmLcfData))));
		#endif
        /* L3D_ALGO_24516: Meas freeze LCF relevant data */
        LcfVehMeasFreeze(reqPorts, proPorts, services);

        /* Runtime measurement is done via sections of code in "lcf_veh_service.h" */
        #define	VEH_WRP_VEHPROCESS_STOP
        #include "lcf_veh_service.h"

        uiRetCode = (BaseReturnCode_t)BASE_RETURN_OK;
	}
	else
	{
		(void)services->pfMeasFreeze(&LCF_VehDebugMTSDesc, (const void *)&LCFVeh_pstDbgData, (MEAS_Callback_t) 0UL);
	}
    
    /* L3D_ALGO_21600: in case error is returned, all provide ports are set to NULL pointer */
    if ((uiRetCode == (BaseReturnCode_t)BASE_RETURN_ERROR) && (proPorts != NULL))
    {
        proPorts->pAlgoCompState = NULL;
		#if defined(LCF_VEH_PPORT_PLCFLADMCSOCTOIUC)
        proPorts->pLcfLaDmcSocToIuc = NULL;
		#endif
		#if defined(LCF_VEH_PPORT_PNVMLCFDATA)
        proPorts->pNvmLcfData = NULL;
		#endif
        proPorts->pLcfVehOutputData = NULL;
        proPorts->pLcfVehOutputToSenData = NULL;
    }
    else{}
	
  	pLcfVehProPorts = NULL;
	pLcfVehReqPorts = NULL;
	pLcfVehServices = NULL;
	pNvmLcfInfo = NULL;

	return uiRetCode;
}


