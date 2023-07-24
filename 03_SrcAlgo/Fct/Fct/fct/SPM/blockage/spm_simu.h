// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.6 $

/***********************************************************************
CHANGES:                   $Log: spm_simu.h  $
CHANGES:                   Revision 1.6 2019/05/28 09:58:36CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.5 2018/11/19 13:33:11CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   File header description has been deleted
CHANGES:                   Revision 1.4 2018/09/24 14:59:28CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config swithc for SRR technology
CHANGES:                   Revision 1.3 2018/04/04 10:22:06CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config swithc for init with rec data function header
CHANGES:                   Revision 1.2 2018/04/03 10:49:01CEST Pallo, Istvan (palloi) 
CHANGES:                   Add design for function header
CHANGES:                   Revision 1.1 2018/03/09 10:49:35CET Pallo, Istvan (palloi) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/blockage/project.pj


************************************************************************/

#ifndef SPM_SIMU_H_INCLUDED
#define SPM_SIMU_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_types.h"

#if(FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)

#ifdef __cplusplus
extern "C" {
#endif

#if((FCT_SIMU == SWITCH_ON) && (SPM_INIT_WITH_REC_DATA) && (SPM_SRR_TECHNOLOGY == SWITCH_OFF))
/// @brief Initialize SPM simulation data with data from recording
///
/// @pre                None
/// @post               None
///
/// @param[in] pSPMDataRec : SPM data took from recording
///
/// @return             void
///
/// @globals
///        SPMData.SPMSelftestState : Selftest current state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestStateLast : Selftest last state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestTimeCounter : Current time counter for selftest [full range of float32]\n
///
/// @InOutCorrelation   Initialize SPM simulation data with SPM data took from recording.
/// @startuml "Call sequence for InitSPMDataWithRecordingData"
///
/// sim_swc_fct_sen -> spm : FctSenExec() calls InitSPMDataWithRecordingData(SPMData_t)
/// activate spm
///   spm --> sim_swc_fct_sen : 
/// deactivate spm
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       
///
  void InitSPMDataWithRecordingData(SPMData_t * pSPMDataRec);
#endif

#ifdef __cplusplus
};
#endif

#endif //FCT_CFG_SIGNAL_PERF_MONITORING
#endif //_SPM_SIMU_H_INCLUDED
