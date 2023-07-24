/*
 *  ======== main.c ========
 */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
//#include <xdc/runtime/Timestamp.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#ifdef _TMS320C6600
#include <ti/sysbios/family/c66/Cache.h>
#else
#include <ti/sysbios/family/c64p/Cache.h>
#endif
#include <stdio.h>
#include <string.h>

#include "lcf_sen_ext.h"
#include "lcf_veh_ext.h"
#include "SharedRAM.h"
#include "SharedRAM_EVE.h"
#include "rta_service.h"
#include "evm_algo_service_types.h"


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
  Cache_wbInvAll();
  while (0 == Flag_RunDSP)
  {
    Cache_wbInvAll();
  }
}
/*****************************************************************
* End: This are the ARM/DSP synchronization services (polling)
*****************************************************************/

static reqLcfSenPrtList_t req_Sen;
static proLcfSenPrtList_t pro_Sen;
static reqLcfVehPrtList_t req_Veh;
static proLcfVehPrtList_t pro_Veh;

/***********************************************************
 * Begin : Necessary variables for LCF Algo calling
 **********************************************************/


//volatile uint16 temp_size;

/***********************************************************
 * End : Necessary variables for Blockage Algo calling
 **********************************************************/

/* ****************************************************************************/

/*
 *  ======== taskFxn ========
 */
extern "C" Void taskFxn(UArg a0, UArg a1)
{
  evm::as::CServiceTypes::getInstance().InitEvmService_Eve(&EVEContainer, static_cast<void*>(&EVEParams), &Flag_RunEVE, &EVEReturnValue);
  InitEvmService_Rta(&PortBuffer_hil2mts.RtaBuffer, 12, 60000);

  while (1)
  {
    Wait4ARM();

    Rta_NewCycle();

    /*****************************************************************
      * Begin: Do your DSP-processing, here....
    *****************************************************************/
    reqLcfSenPrtList_t req_Sen;
    proLcfSenPrtList_t pro_Sen;
    reqLcfVehPrtList_t req_Veh;
	proLcfVehPrtList_t pro_Veh;

    // Request ports:
    // ==============
	req_Sen.pLcfSenCtrlData           = &PortBuffer_mts2hil.SenIn_LcfSenCtrlData;
    req_Sen.pLcfInputData             = &PortBuffer_mts2hil.SenIn_LcfInputData;
	req_Sen.pLcfSenInputFromVehData   = &PortBuffer_mts2hil.SenIn_LcfSenInputFromVehData;
	req_Sen.pLcfVehOutputData         = &PortBuffer_mts2hil.SenIn_LcfVehOutputData;
	req_Sen.pLcfCpar                  = &PortBuffer_mts2hil.SenIn_LcfCpar;
	req_Sen.pVehPar                   = &PortBuffer_mts2hil.SenIn_VehPar;
	req_Sen.pVehSig                   = &PortBuffer_mts2hil.SenIn_VehSig;
	req_Sen.pVehDyn                   = &PortBuffer_mts2hil.SenIn_VehDyn;
	req_Sen.pLDOutputData             = &PortBuffer_mts2hil.SenIn_LDOutputData;
	req_Sen.pHlaRadarObjectList       = &PortBuffer_mts2hil.SenIn_HlaRadarObjectList;
	req_Sen.pEMT0OutputData           = &PortBuffer_mts2hil.SenIn_EMT0OutputData;
	  
	req_Veh.pLcfVehCtrlData           = &PortBuffer_mts2hil.VehIn_LcfVehCtrlData;
	req_Veh.pLcfInputData             = &PortBuffer_mts2hil.VehIn_LcfInputData;
	req_Veh.pLcfVehInputFromSenData   = &PortBuffer_mts2hil.VehIn_LcfVehInputFromSenData;
	req_Veh.pLcfSenOutputData         = &PortBuffer_mts2hil.VehIn_LcfSenOutputData;
	req_Veh.pLcfCpar                  = &PortBuffer_mts2hil.VehIn_LcfCpar;
	req_Veh.pVehPar                   = &PortBuffer_mts2hil.VehIn_VehPar;
	req_Veh.pVehSig                   = &PortBuffer_mts2hil.VehIn_VehSig;
	req_Veh.pVehDyn                   = &PortBuffer_mts2hil.VehIn_VehDyn;
	req_Veh.pLDOutputData             = &PortBuffer_mts2hil.VehIn_LDOutputData;
	req_Veh.pEMT0OutputData           = &PortBuffer_mts2hil.VehIn_EMT0OutputData;


	// Provide ports:
	// ==============
	pro_Sen.pLcfAlgoCompState          = &PortBuffer_hil2mts.SenOut_LcfAlgoCompState;
	pro_Sen.pLcfBusDebugData           = &PortBuffer_hil2mts.SenOut_LcfBusDebugData;
	pro_Sen.pLcfSenOutputData          = &PortBuffer_hil2mts.SenOut_LcfSenOutputData;
	pro_Sen.pLcfSenOutputToVehData     = &PortBuffer_hil2mts.SenOut_LcfSenOutputToVehData;


	pro_Veh.pLcfAlgoCompState          = &PortBuffer_hil2mts.VehOut_LcfAlgoCompState;
	pro_Veh.pLcfBusDebugData           = &PortBuffer_hil2mts.VehOut_LcfBusDebugData;
	pro_Veh.pLcfVehOutputData          = &PortBuffer_hil2mts.VehOut_LcfVehOutputData;
	pro_Veh.pLcfVehOutputToSenData     = &PortBuffer_hil2mts.VehOut_LcfVehOutputToSenData;
	 
	  
	Rta_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, 165, TASK_ID_LCF60, 0);
	Rta_StartBandwidthMeasurement();
	LcfSenExec(&req_Sen, &pro_Sen, &evm::as::CServiceTypes::getInstance());
	LcfVehExec(&req_Veh, &pro_Veh, &evm::as::CServiceTypes::getInstance());
	Rta_StopBandwidthMeasurement();
	Rta_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, 165, TASK_ID_LCF60, 0);
	  
    /*****************************************************************
     * End: Do your DSP-processing, here....
     *****************************************************************/

    Return2ARM();
  }
}

/*
 *  ======== main ========
 */
int main()
{
  BIOS_start();
  return 0;
}
