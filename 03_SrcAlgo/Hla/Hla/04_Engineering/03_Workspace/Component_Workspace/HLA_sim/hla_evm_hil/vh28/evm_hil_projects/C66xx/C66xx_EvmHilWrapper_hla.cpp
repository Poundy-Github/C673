/*-------------------------------------------------------------------------
 |
 |  File Name   :  $Source: C66xx_EvmHilWrapper_hla.cpp $
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
 |  Description : VH28 Evalboard-HIL simulation wrapper for HLA on EVE.
 |
 |
 |
 |  Developer  :  Matthias Mutschler
 |
 |  Last Revision     $Revision: 1.7 $
 |  Last Author       $Author: Mutschler, Matthias (uidv7867) $
 |
 +-------------------------------------------------------------------------*/
 
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifdef EVM_HIL
#include <stdio.h>
#include <string.h>
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/family/c66/Cache.h>


#include "hla_defs.h"
#include "hla_main.h"
#include "hla_outputs.h"
#include "hla_measfreeze_data.h"
#include "SharedRAM.h"
#include "rta_service.h"
#include "evm_algo_service_types.h"

#include "sim_hla_common.h"

/*****************************************************************************
  MACROS
*****************************************************************************/
//#define HLA_ENABLE_HOT_PIXELS_SIMULATION

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/
static AS_t_ServiceFuncts frameSWServices;


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static AS_t_MeasReturn HLAMeasHandler (const AS_t_MeasInfo *p_MeasInfo, void *p_Buff, AS_t_MeasCallback pf_MeasCallback);

/*****************************************************************
* Begin: This are the ARM/DSP synchronization services (polling)
*****************************************************************/

void Return2ARM()
{
  Cache_wbInvAll();
  Flag_RunDSP = 0;
  Cache_wbInvAll();
}

void Wait4ARM()
{
  while( 0 == Flag_RunDSP )
  {
    Cache_wbInvAll();
  }
}
/*****************************************************************
* End: This are the ARM/DSP synchronization services (polling)
*****************************************************************/

/*
 *  ======== main ========
 */
int main()
{
    BIOS_start();        /* enable interrupts and start SYS/BIOS */
    return 0;
}

/*
 *  ======== taskFxn ========
 */
extern "C" Void taskFxn(UArg a0, UArg a1)
{
  SimHlaReqPrtList_t reqPorts;
  proHlaPrtList_t proPorts;
  Rta_EvmServiceParams_t rtaServiceParams;

  /*
   * INIT
   */
  (void)memset((void*)&reqPorts, 0, sizeof(reqPorts));
  (void)memset((void*)&proPorts, 0, sizeof(proPorts));
  /* Get instance from frame software services */
  frameSWServices = evm::as::CServiceTypes::getInstance();
  /* Overwrite measfreeze service since we have to save our internal measfreezes during algo run (additionally some of them live in L2Cache) */
  frameSWServices.pfMeasFreeze = (AS_t_MeasHdlr)HLAMeasHandler;

  /* Init RTA service */
  (void)memset((void*)&rtaServiceParams, 0, sizeof(rtaServiceParams));
  rtaServiceParams.pRtaBuffer        = &PortBuffer_hil2mts.rtaBuffer;
  rtaServiceParams.pRtaBufferEve     = NULL;
  rtaServiceParams.u_TaskID          = TASK_ID_HLA;
  rtaServiceParams.u_EventIDEveTotal = 0u;
  rtaServiceParams.uFakeCycleTime_us = 25000;
  Rta_InitEvmService(&rtaServiceParams);


  /* Following ports are static, i.e. it can be done only once */
  /* Fill request ports with corresponding pointers/addresses */
  reqPorts.pBaseCtrlData                  = &PortBuffer_mts2hil.reqPortBuffers.BaseCtrlData;
  reqPorts.pCPar_HlafPar                  = &PortBuffer_mts2hil.reqPortBuffers.CPar_HlafPar;
  reqPorts.pSig_MonoCalibration           = &PortBuffer_mts2hil.reqPortBuffers.Sig_MonoCalibration;
  reqPorts.pHlaBusInputSignals            = &PortBuffer_mts2hil.reqPortBuffers.HlaBusInputSignals;
  reqPorts.pSigVeh_VehSig                 = &PortBuffer_mts2hil.reqPortBuffers.SigVeh_VehSig;
  reqPorts.pSigVeh_VDYData                = &PortBuffer_mts2hil.reqPortBuffers.SigVeh_VDYData;
  reqPorts.pSig_Blockage                  = &PortBuffer_mts2hil.reqPortBuffers.Sig_Blockage;
  reqPorts.pSig_EMObjectsList             = &PortBuffer_mts2hil.reqPortBuffers.Sig_EMObjectsList;
  reqPorts.pLsdEnvironmentData            = &PortBuffer_mts2hil.reqPortBuffers.LsdEnvironmentData;
  reqPorts.pLsdLightObjectList            = &PortBuffer_mts2hil.reqPortBuffers.LsdLightObjectList;
  reqPorts.pLsdLightList                  = &PortBuffer_mts2hil.reqPortBuffers.LsdLightList;
  /* Fill provide ports with corresponding pointers/addresses */
  proPorts.pAlgoCompState                 = &PortBuffer_hil2mts.proPortBuffers.AlgoCompState;
  proPorts.pHlaf_HeadlightControl         = &PortBuffer_hil2mts.proPortBuffers.Hlaf_HeadlightControl;

  /*
   * MAIN LOOP
   */
  while( 1 )
  {
    Wait4ARM();

    /*
     * PROLOG
     */

    /* Reset algo internal stuff if needed, e.g. after loading a new recording */
    if(PortBuffer_mts2hil.isHilResetNeeded == b_TRUE)
    {
      Hla_SyncRef_t SyncRefDummy;

      /* Clean algo internal buffers */
      HLA_FirstStatupState();
      HLA_SetOutputDefaults( COMP_STATE_NOT_INITIALIZED,
                             COMP_ERROR_NO_ERROR,
                             ALGO_QUAL_OK,
                             AL_SIG_STATE_INIT,
                             PortBuffer_mts2hil.reqPortBuffers.BaseCtrlData.sSigHeader.uiTimeStamp,
                             PortBuffer_mts2hil.reqPortBuffers.BaseCtrlData.sSigHeader.uiMeasurementCounter,
                             0u,
                             &SyncRefDummy,
                             (proHlaPrtList_t *)&PortBuffer_hil2mts.proPortBuffers
                            );
    }


    /* Reset hil outputs in case of run mode */
    if(PortBuffer_mts2hil.reqPortBuffers.BaseCtrlData.eOpMode != BASE_OM_RESET)
    {
      /* But preserve RTA buffer time stamp */
      const uint64 tempTimestamp = PortBuffer_hil2mts.rtaBuffer.u_RefTs_us;
      memset((void*)&PortBuffer_hil2mts, 0, sizeof(PortBuffer_hil2mts));
      PortBuffer_hil2mts.rtaBuffer.u_RefTs_us = tempTimestamp;
    }

    /*
     * MAIN CALL
     * call algo execution
     */
    /* Start a new cycle on DSP. Switch task context and start bandwidth measurement. */
    Rta_CycleStart();

    /* Call algo execution */
    Rta_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, RTA_GLOBALID_HLA, HLA_RTA_TOTAL, 0);
    HlaExec((const reqHlaPrtList_t*)&reqPorts, &proPorts, &frameSWServices);
    Rta_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, RTA_GLOBALID_HLA, HLA_RTA_TOTAL, 0);

    /* Switch back to idle task and stop bandwidth measurement. */
    Rta_CycleEnd();


    /*
     * EPILOG
     */

    Return2ARM();
  }
}



/* Overwrite measfreeze handler to be able to "freeze" internal measfreezes */
static AS_t_MeasReturn HLAMeasHandler (const AS_t_MeasInfo *p_MeasInfo, void *p_Buff, AS_t_MeasCallback pf_MeasCallback)
{
  AS_t_MeasReturn retVal = MEAS_OK;
  /* MeasFreeze taken at dll side.
   * Every measfreeze has to be sent from eval board to pc (dll) and to be populated there.
   * Note that we do a task switch for those measfreezes that are not performed on ECU. RTA should be similar compare to ECU.
   */
  if(   (p_MeasInfo != NULL)
     && (p_Buff != NULL)
    )
  {
    /* Copy only those buffers that use L2 cache */
    switch(p_MeasInfo->VirtualAddress)
    {
    case HLA_MEAS_VADDR_ERROR_STACK:
      memcpy((void*)&PortBuffer_hil2mts.hlaErrorStack, p_Buff, p_MeasInfo->Length);
      break;
    default:
      retVal = MEAS_BAD_GROUP_ID;
      break;
    }
  }
  else
  {
    retVal = MEAS_FULL_BUFFER;
  }

  return retVal;
}

#endif /* #ifdef EVM_HIL */
