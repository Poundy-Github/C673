/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 SPM (System Performance Monitoring)

PACKAGENAME:               spm_customfunctions.c

DESCRIPTION:               Custom specific functions for SPM (System Performance Monitoring) purpose

AUTHOR:                     $Author: Pallo, Istvan (palloi) $

CREATION DATE:             19.10.2016

VERSION:                   $Revision: 1.4 $

---*/ /*---
CHANGES:                    $Log: spm_customfunctions.c  $
CHANGES:                    Revision 1.4 2020/06/23 12:52:39CEST Pallo, Istvan (palloi) 
CHANGES:                    Update config switches for SPM Split - SRR
CHANGES:                    Revision 1.3 2018/09/24 14:26:08CEST Pallo, Istvan (palloi) 
CHANGES:                    Add SRR config switch for SRR custom functions.
CHANGES:                    Revision 1.2 2017/11/22 08:03:15CET Pallo, Istvan (palloi) 
CHANGES:                    Add header for SetCustomOutput function
CHANGES:                    Revision 1.1 2017/07/04 09:14:44CEST Pallo, Istvan (palloi) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/00_Projects/ARS510/SPM/project.pj
CHANGES:                    Revision 1.2 2017/02/09 10:57:53CET Ehrlinspiel, Veronika (uidj4213) 
CHANGES:                    first inital version: 
CHANGES:                    - added SPM_v_SetCustomOuput and SPM_v_CustomProcess functions

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "spm.h"

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/// @brief Set SPM custom output based on internal data
///
/// @pre                None
/// @post               None
///
/// @param[out] p_SPMCustomOutput : Reference to Custom Output structure
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageState : Blockage state [SYSDampState_t as defined in Rte_Type.h]\n
///        SPMData.SPMSelftestState : Self test state [eGDBPDStates_t as defined in Rte_Type.h]\n
///        SPMData.SPMBlockageRange : Blockage range [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageRangeConf : Blockage range confidence [0.f ... 1.f]\n
///        SPMData.SPMBlockageRangeProb : Blockage range probability [0.f ... 1.f]\n
///        SPMData.SPMBlockageObjLossProb : Object loss probability [0.f ... 1.f]\n
///        SPMData.SPMBlockageObjLossConf : Object loss confidence [0.f ... 1.f]\n
///        SPMData.SPMBlockageProbability : Blockage probability [0.f ... 1.f]\n
///        SPMData.SPMBlockageConfidence : Blockage confidence [0.f ... 1.f]\n
///        SPMData.SPMBlockageTimeoutWayCounter : Timeout way counter [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageTimeoutTimeCounter : Timeout time counter [full range of float32]\n
///        SPMData.SPMBlockageTimeoutBlockProb : Timeout blockage probability [0.f ... 1.f]\n
///        SPMData.SPMBlockageTimeoutBlockConf : Timeout blockage confidence [0.f ... 1.f]\n
///        SPMData.SPMFullBlockageTimer : Full blockage timer [full range of float32]\n
///
/// @InOutCorrelation   Copy the SPMData to custom poutput pointer. For necessary values make the conversion to desired 
///                     unit.
/// @startuml "Call sequence for SPM_v_SetCustomOuput"
///
/// spm_output -> spm_output : SPM_v_CustomProcess calls SPM_v_SetCustomOuput(FCTCustomOutput_t)
/// activate spm_output
///   spm_output --> spm_output : 
/// deactivate spm_output
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)
static void SPM_v_SetCustomOuput(FCTCustomOutput_t * p_SPMCustomOutput);

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/


#if (FCT_CFG_CUSTOM_IO_INTERFACE)
void SPM_v_CustomProcess(void)
{
  /*! Set SPM custom output */
  SPM_v_SetCustomOuput(FCTSEN_pCustomOutput);
}


/*************************************************************************************************************************
  Functionname:    SPM_v_SetCustomOuput                                                                             */ /*!

  @brief           Set SPM custom output based on internal data

  @description     Set SPM custom output based on internal data

  @return          -

  @param[ out]     p_SPMCustomOutput : Reference to Custom Output structure
                      p_SPMCustomOutput->BlockageInfo.eSPMBlockageState : Blockage state [SYSDampState_t as defined in Rte_Type.h]
                      p_SPMCustomOutput->BlockageInfo.eSPMSelfTestState : Self test state [eGDBPDStates_t as defined in Rte_Type.h]
                      p_SPMCustomOutput->BlockageInfo.ucEstiRange : Estimation range [full range of uint8]
                      p_SPMCustomOutput->BlockageInfo.ucEstiRangeConf : Estimation range confidence [ucConfidence_t as defined in Rte_Type.h]
                      p_SPMCustomOutput->BlockageInfo.ucEstiRangeProb : Estimation range probability [full range of uint8]
                      p_SPMCustomOutput->BlockageInfo.ucObjLossProb : Object loss probability [full range of uint8]
                      p_SPMCustomOutput->BlockageInfo.ucObjLossConf : Object loss confidence [ucConfidence_t as defined in Rte_Type.h]
                      p_SPMCustomOutput->BlockageInfo.ucOverallProb : Overall probability [full range of uint8]
                      p_SPMCustomOutput->BlockageInfo.ucOverallConf : Overall confidence [ucConfidence_t as defined in Rte_Type.h]
                      p_SPMCustomOutput->BlockageInfo.usRoadbeamTimeCnt : Roadbeam time counter [full range of uint16]
                      p_SPMCustomOutput->BlockageInfo.usTimeoutWayCnt :  Timeout way counter [full range of uint16]
                      p_SPMCustomOutput->BlockageInfo.ucTimeoutTimeCnt : Timeout time counter [full range of uint8]
                      p_SPMCustomOutput->BlockageInfo.ucTimeoutBlkProb : Timeout blockage probability [full range of uint8]
                      p_SPMCustomOutput->BlockageInfo.ucTimeoutBlkConf : Timeout blockage confidence [ucConfidence_t as defined in Rte_Type.h]
                      p_SPMCustomOutput->BlockageInfo.usFullBlkTimer : Full blockage timer [full range of uint16]

  @glob_in         SPMData.SPMBlockageState : Blockage state [SYSDampState_t as defined in Rte_Type.h]
  @glob_in         SPMData.SPMSelftestState : Self test state [eGDBPDStates_t as defined in Rte_Type.h]
  @glob_in         SPMData.SPMBlockageRange : Blockage range [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SPMData.SPMBlockageRangeConf : Blockage range confidence [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageRangeProb : Blockage range probability [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageObjLossProb : Object loss probability [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageObjLossConf : Object loss confidence [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageProbability : Blockage probability [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageConfidence : Blockage confidence [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageTimeoutWayCounter : Timeout way counter [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         SPMData.SPMBlockageTimeoutTimeCounter : Timeout time counter [full range of float32]
  @glob_in         SPMData.SPMBlockageTimeoutBlockProb : Timeout blockage probability [0.f ... 1.f]
  @glob_in         SPMData.SPMBlockageTimeoutBlockConf : Timeout blockage confidence [0.f ... 1.f]
  @glob_in         SPMData.SPMFullBlockageTimer : Full blockage timer [full range of float32]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             -
  @post            -

  @created         19.10.2016
  @changed         19.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void SPM_v_SetCustomOuput(FCTCustomOutput_t * p_SPMCustomOutput)
{
  float32 fScaleTemp;

  /* Fill blockage debug information for meas purposes */
  p_SPMCustomOutput->BlockageInfo.eSPMBlockageState  = SPMData.SPMBlockageState;
  p_SPMCustomOutput->BlockageInfo.eSPMSelfTestState  = SPMData.SPMSelftestState;
  p_SPMCustomOutput->BlockageInfo.ucEstiRange        = (uint8)SPMData.SPMBlockageRange;
  fScaleTemp = SPMData.SPMBlockageRangeConf * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucEstiRangeConf    = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageRangeProb * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucEstiRangeProb    = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageObjLossProb * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucObjLossProb      = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageObjLossConf * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucObjLossConf      = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageProbability * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucOverallProb      = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageConfidence * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucOverallConf      = (uint8)(fScaleTemp);
  p_SPMCustomOutput->BlockageInfo.usRoadbeamTimeCnt  = 0u;
  fScaleTemp = MIN(SPMData.SPMBlockageTimeoutWayCounter, 65535.f);
  p_SPMCustomOutput->BlockageInfo.usTimeoutWayCnt    = (uint16)(fScaleTemp);
  fScaleTemp = MIN(SPMData.SPMBlockageTimeoutTimeCounter, 255.f);
  p_SPMCustomOutput->BlockageInfo.ucTimeoutTimeCnt   = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageTimeoutBlockProb * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucTimeoutBlkProb   = (uint8)(fScaleTemp);
  fScaleTemp = SPMData.SPMBlockageTimeoutBlockConf * 100.f;
  p_SPMCustomOutput->BlockageInfo.ucTimeoutBlkConf   = (uint8)(fScaleTemp);
  fScaleTemp = MIN(SPMData.SPMFullBlockageTimer, 65535.f);
  p_SPMCustomOutput->BlockageInfo.usFullBlkTimer     = (uint16)(fScaleTemp);
}
#endif
#endif/*!< FCT_CFG_SIGNAL_PERF_MONITORING */

#endif/*SPM_SRR_TECHNOLOGY*/
