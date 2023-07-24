/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: CortexM4_EvmHilWrapper.cpp $
 |
 | ------------------------------------------------------------------------
 |
 |  COPYRIGHT (C) Continental Automotive AG 2008
 |  ALLE RECHTE VORBEHALTEN. ALL RIGHTS RESERVED.
 |
 |   The  reproduction,  transmission or  use  of  this  document or  its
 |   contents  is  not   permitted  without  express  written  authority.
 |   Offenders will  be liable for damages. All  rights, including rights
 |   created  by patent  grant  or  registration of  a  utility model  or
 |   design, are reserved.
 |
 | ------------------------------------------------------------------------
 |
 |  Description : VME Evalboard-HIL simulation wrapper for CortexM4
 |
 |
 |
 |  Developer  :  Ulrich Wagner
 |
 |  Last Revision     $Revision: 1.1 $
 |  Last Author       $Author: Wang, David (Wangd3) $
 |              
 +-------------------------------------------------------------------------*/



#include <stdio.h>
#include <ti/sysbios/hal/unicache/Cache.h>
#include "CortexM4_EvmHilWrapper.h"
#include "SharedRAM.h"
#include "evm_algo_service_types.h"




/*****************************************************************
* Begin: This are the ARM/DSP synchronization services (polling)
*****************************************************************/
void TriggerDSP()
{
    Cache_wbInvAll();    // needed, to avoid possible race-condition, when Flag_RunDSP would be written back, first, before the actual shared data is written back
    Flag_RunDSP = 1;
    Cache_wbInvAll();
}

void Wait4DSP()
{
    while (1 == Flag_RunDSP)
    {
      Cache_wbInvAll();
    }
}
/*****************************************************************
* End: This are the ARM/DSP synchronization services (polling)
*****************************************************************/


C_HilSimulation::C_HilSimulation(void)
{ 
  Rta_EvmServiceParams_t params;

  // Input:
  AddReceivePort("mts2hil"      , simUI8_t, &PortBuffer_mts2hil       , sizeof(PortBuffer_mts2hil), 0);
  
  // Output results to MTS:
  AddProvidePort("hil2mts"      , simUI8_t, &PortBuffer_hil2mts       , sizeof(PortBuffer_hil2mts));

  memset(&PortBuffer_mts2hil, 0, sizeof(PortBuffer_mts2hil));
 // memset(&PortBuffer_hil2mts, 0, sizeof(PortBuffer_hil2mts));

  /* init RTA */
   InitEvmServiceParams_Rta(&params);
   params.pRtaBuffer = &PortBuffer_hil2mts.RtaBuffer;
   params.u_CoreID   = 12;
   params.BandwidthCntCfg[0].Enable  = PERF_COUNT_ENABLE;                 /* CortexM4 total access */
   params.BandwidthCntCfg[0].Config  = DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES;
   params.BandwidthCntCfg[0].MConnId = DDRCTRL_MCONNID_IPU1;
   params.BandwidthCntCfg[1].Enable  = PERF_COUNT_ENABLE;                 /* CortexM4 read access */
   params.BandwidthCntCfg[1].Config  = DDRCTRL_CNTRX_CFG_TOTAL_READS;
   params.BandwidthCntCfg[1].MConnId = DDRCTRL_MCONNID_IPU1;
   params.BandwidthCntCfg[2].Enable  = PERF_COUNT_ENABLE;                 /* CortexM4 write access */
   params.BandwidthCntCfg[2].Config  = DDRCTRL_CNTRX_CFG_TOTAL_WRITES;
   params.BandwidthCntCfg[2].MConnId = DDRCTRL_MCONNID_IPU1;
   params.BandwidthCntCfg[3].Enable  = PERF_COUNT_DISABLE;                 /* don't use all other counters */
   params.BandwidthCntCfg[4].Enable  = PERF_COUNT_DISABLE;
   params.BandwidthCntCfg[5].Enable  = PERF_COUNT_DISABLE;
   params.BandwidthCntCfg[6].Enable  = PERF_COUNT_DISABLE;
   params.BandwidthCntCfg[7].Enable  = PERF_COUNT_DISABLE;
   InitEvmServiceCustom_Rta(&params);
  
}

C_HilSimulation::~C_HilSimulation()
{
}


void C_HilSimulation::Init(int i32_Param)
{
 /* Clean input/output buffers */
 memset(&PortBuffer_mts2hil, 0, sizeof(PortBuffer_mts2hil));
 memset(&PortBuffer_hil2mts, 0, sizeof(PortBuffer_hil2mts));
}




void C_HilSimulation::Run(int)
{

  /////////////////////////////////////////////////////////////
  // Begin: Do your ARM CortexM4 algorithm processing, here
  /////////////////////////////////////////////////////////////
  
  // ...no ARM-processing, so far

  /////////////////////////////////////////////////////////////
  // End: Do your ARM CortexM4 algorithm processing, here
  /////////////////////////////////////////////////////////////


  // Trigger DSP-processing:
  TriggerDSP();
  Wait4DSP();

  return;
}

// allocate the static instance to be tested
static C_HilSimulation m_c_Algo;
