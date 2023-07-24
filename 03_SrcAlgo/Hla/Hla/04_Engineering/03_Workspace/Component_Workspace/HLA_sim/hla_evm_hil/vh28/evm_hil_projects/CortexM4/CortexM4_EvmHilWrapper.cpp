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
 |  Last Revision     $Revision: 1.2 $
 |  Last Author       $Author: Mutschler, Matthias (uidv7867) $
 |              
 +-------------------------------------------------------------------------*/
#ifdef EVM_HIL


#include "CortexM4_EvmHilWrapper.h"
#include "glob_type.h"
#include <stdio.h>
#ifdef __TI_ARM_V7M4__
#include <ti/sysbios/hal/unicache/Cache.h>
#else
#include <ti/sysbios/family/arm/a8/Cache.h>
#endif
#include "SharedRAM.h"


/*****************************************************************
* Begin: This are the ARM/DSP synchronization services (polling)
*****************************************************************/
void TriggerDSP()
{
  Cache_wbInvAll();
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
  /* Input from MTS: */
  AddReceivePort("mts2hil"      , simUI8_t, &PortBuffer_mts2hil       , sizeof(PortBuffer_mts2hil), 0);

  /* Output results to MTS: */
  AddProvidePort("hil2mts"      , simUI8_t, &PortBuffer_hil2mts       , sizeof(PortBuffer_hil2mts));

  /* Clean input/output buffers */
  memset(&PortBuffer_mts2hil, 0, sizeof(PortBuffer_mts2hil));
  memset(&PortBuffer_hil2mts, 0, sizeof(PortBuffer_hil2mts));
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
  // Begin: Do your ARM CortexA8 algorithm processing, here
  /////////////////////////////////////////////////////////////
  
  // ...no ARM-processing, so far

  /////////////////////////////////////////////////////////////
  // End: Do your ARM CortexA8 algorithm processing, here
  /////////////////////////////////////////////////////////////

  // Trigger DSP-processing:
  TriggerDSP();
  Wait4DSP();

  return;
}

// allocate the static instance to be tested
static C_HilSimulation m_c_Algo;

#endif /* #ifdef EVM_HIL */
