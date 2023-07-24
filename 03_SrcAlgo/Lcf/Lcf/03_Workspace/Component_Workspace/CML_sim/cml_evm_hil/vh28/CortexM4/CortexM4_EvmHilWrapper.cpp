/*
 *  ======== main.c ========
 */

#include <stdio.h>
#include <string.h>
#include "CortexM4_EvmHilWrapper.h"
#include "glob_type.h"

#include <ti/sysbios/hal/unicache/Cache.h>





#include <algorithm>
#include <functional>
#include <iostream>

/*
 * CML Test application
 */

/* External test function declarations */
extern void test_cml_stl_matrix(void);
extern void test_cml_stl_point(void);
extern void test_cml_stl_vector(void);

/* Test Log file */
FILE *fpTest = NULL;


//#include "cml_ext.h"
//#include "SharedRAM.h"
//#include "SharedRAM_EVE.h"
//#include "evm_algo_service_types.h"


/*****************************************************************
* Begin: This are the ARM/DSP synchronization services (polling)
*****************************************************************/


void Return2ARM()
{
  Cache_wbInvAll();	// needed, to avoid possible race-condition, when Flag_RunDSP would be written back, first, before the actual shared data is written back
  //Flag_RunDSP = 0;
  Cache_wbInvAll();
}
#if 0
void Wait4ARM()
{
  while (0 == Flag_RunDSP) {
    Cache_wbInvAll();
  }
}
#endif
/*****************************************************************
* End: This are the ARM/DSP synchronization services (polling)
*****************************************************************/

/*
 *  ======== taskFxn ========
 */
extern "C" Void taskFxn(UArg a0, UArg a1)
{
  #if 0 
  evm::as::CServiceTypes::getInstance().InitEvmService_Eve(&EVEContainer, static_cast<void*>(&EVEParams), &Flag_RunEVE, &EVEReturnValue);
 
  InitEvmService_Rta(&PortBuffer_hil2mts.RtaBuffer, 12, 60000);

  while (1) {
      Wait4ARM();


      Rta_NewCycle();

      /*****************************************************************
      * Begin: Do your DSP-processing, here....
      *****************************************************************/
      reqCippPrtList_t req;
      proCippPrtList_t pro;

      // Request ports:
      // ==============
      req.pCtrl                                               = &PortBuffer_mts2hil.Ctrl;

      req.pInputImageOdd                                      = &PortBuffer_mts2hil.InputImageOdd.image();
      req.pInputImageEven                                     = &PortBuffer_mts2hil.InputImageEven.image();
      req.pIcImageCharacteristics                             = &PortBuffer_mts2hil.IcImageCharacteristics;
      req.pFLSPProductionIntrinsic                            = &PortBuffer_mts2hil.FLSPProductionIntrinsic;
      req.pMonoCalibrationEolRight                            = &PortBuffer_mts2hil.MonoCalibrationEol;

      pro.pOddYP0Image                                        = &PortBuffer_hil2mts.OddYP0Image.image();
      pro.pOddYP1Image                                        = &PortBuffer_hil2mts.OddYP1Image.image();
      pro.pOddYP2Image                                        = &PortBuffer_hil2mts.OddYP2Image.image();
      pro.pOddYP3Image                                        = &PortBuffer_hil2mts.OddYP3Image.image();
      pro.pOddYP4Image                                        = &PortBuffer_hil2mts.OddYP4Image.image();

      pro.pOddUImage                                          = &PortBuffer_hil2mts.OddUImage.image();
      pro.pOddUP2Image                                        = &PortBuffer_hil2mts.OddUP2Image.image();
      pro.pOddUP3Image                                        = &PortBuffer_hil2mts.OddUP3Image.image();
      pro.pOddUP4Image                                        = &PortBuffer_hil2mts.OddUP4Image.image();

      pro.pOddVImage                                          = &PortBuffer_hil2mts.OddVImage.image();
      pro.pOddVP2Image                                        = &PortBuffer_hil2mts.OddVP2Image.image();
      pro.pOddVP3Image                                        = &PortBuffer_hil2mts.OddVP3Image.image();
      pro.pOddVP4Image                                        = &PortBuffer_hil2mts.OddVP4Image.image();

      pro.pOddSatImage                                        = &PortBuffer_hil2mts.OddSatImage.image();
      pro.pOddSatP1Image                                      = &PortBuffer_hil2mts.OddSatP1Image.image();
      pro.pOddSatP2Image                                      = &PortBuffer_hil2mts.OddSatP2Image.image();
      pro.pOddSatP3Image                                      = &PortBuffer_hil2mts.OddSatP3Image.image();
      pro.pOddSatP4Image                                      = &PortBuffer_hil2mts.OddSatP4Image.image();

      pro.pOddGradientP1Image                                 = &PortBuffer_hil2mts.OddGradientP1Image.image();
      pro.pOddGradientP2Image                                 = &PortBuffer_hil2mts.OddGradientP2Image.image();

      pro.pEvenYP0Image                                       = &PortBuffer_hil2mts.EvenYP0Image.image();
      pro.pEvenYP1Image                                       = &PortBuffer_hil2mts.EvenYP1Image.image();
      pro.pEvenUImage                                         = &PortBuffer_hil2mts.EvenUImage.image();
      pro.pEvenVImage                                         = &PortBuffer_hil2mts.EvenVImage.image();
      pro.pEvenGradientP1Image                                = &PortBuffer_hil2mts.EvenGradientP1Image.image();
      pro.pEvenGradientP2Image                                = &PortBuffer_hil2mts.EvenGradientP2Image.image();

      pro.pComponentState                                     = &PortBuffer_hil2mts.ComponentState;
      pro.pCippWhiteBalanceResult                             = &PortBuffer_hil2mts.CippWhiteBalanceResult;
      pro.pCippRteImageStatistics                             = &PortBuffer_hil2mts.CippRteImageStatistics;

      Rta_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, 165, TASK_ID_CIPP, 0);
      Rta_StartBandwidthMeasurement();
      CippExec(&req, &pro, &evm::as::CServiceTypes::getInstance());
      Rta_StopBandwidthMeasurement();
      Rta_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, 165, TASK_ID_CIPP, 0);

      /*****************************************************************
      * End: Do your DSP-processing, here....
      *****************************************************************/

      Return2ARM();
  }
  #endif
  
}

/*
 *  ======== main ========
 */
int main()
{ 
    //BIOS_start();        /* enable interrupts and start SYS/BIOS */

	fpTest = fopen("TestLog.txt", "wb+");

	//System_printf("START CML Test Application\n");

	/* Test STL Matrix */
	test_cml_stl_matrix();

	/* Test STL Point */
	test_cml_stl_point();

	/* Test STL Vector */
	test_cml_stl_vector();

	fclose(fpTest);

	//BIOS_exit(0);

	return 0;
}
