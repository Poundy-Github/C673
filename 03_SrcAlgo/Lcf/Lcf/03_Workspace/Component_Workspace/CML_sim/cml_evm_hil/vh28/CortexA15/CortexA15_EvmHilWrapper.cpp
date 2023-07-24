/*
 *  ======== main.c ========
 */
#ifdef TARGET_PLATFORM

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/arm/a15/Cache.h>

#include <sys/time.h>

#endif /* #ifdef TARGET_PLATFORM */

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <functional>
#include <iostream>

/*
 * CML Test application
 */

/* External test function declarations */
extern void test_cml_stl_matrix(void);
extern void test_cml_stl_array(void);
extern void test_cml_stl_point(void);
extern void test_cml_stl_vector(void);
extern void test_cml_stl_algorithm(void);
extern void test_cml_stl_list(void);
extern void test_cml_stl_array2d(void);
extern void test_cml_stl_iterator(void);

/* Test Log file */
FILE *fpTest = NULL;

#ifdef ENABLE_PROFILER
int start_clock    = 0;
int stop_clock     = 0;
int overhead       = 0;
int total_cycles   = 0;

unsigned int get_clock (void)
{
    unsigned int value;
    // Read CCNT Register
    asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(value));
    return value;
}

static inline void init_perfcounters (int do_reset, int enable_divider)
{
    // in general enable all counters (including cycle counter)
    int value = 1;

    // peform reset:
    if (do_reset)
    {
    value |= 2;     // reset all counters to zero.
    value |= 4;     // reset cycle counter to zero.
    }

    if (enable_divider)
    value |= 8;     // enable "by 64" divider for CCNT.

    value |= 16;

    // program the performance-counter control-register:
    asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(value));

    // enable all counters:
    asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));

    // clear overflows:
    asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}
#endif /* #ifdef ENABLE_PROFILER */

#ifdef TARGET_PLATFORM
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

#endif /* #ifdef TARGET_PLATFORM */

/*
 *  ======== main ========
 */
int main()
{ 
    //BIOS_start();        /* enable interrupts and start SYS/BIOS */

	fpTest = fopen("D:/Sandboxes/CML/04_Engineering/04_Build/algo/cml_sim/ti_cortex_a15/release/TestLog.txt", "wb+");
	
#ifdef ENABLE_PROFILER

	/* enable user-mode access to the performance counter*/
	asm ("MCR p15, 0, %0, C9, C14, 0\n\t" :: "r"(1));

	/* disable counter overflow interrupts (just in case)*/
	asm ("MCR p15, 0, %0, C9, C14, 2\n\t" :: "r"(0x8000000f));

	init_perfcounters (1, 0);

	// measure the counting overhead:
	unsigned int overhead = get_clock();
	overhead = get_clock() - overhead;

	unsigned int t = get_clock();

	t = get_clock() - t;

	fprintf(fpTest, "%i\t\t", t);

	fprintf(fpTest, "%i\t\t", overhead);

#endif /* #ifdef ENABLE_PROFILER */

	/* Test STL Matrix */
	test_cml_stl_matrix();

	/* Test STL Array */
	test_cml_stl_array();

	/* Test STL Point */
	test_cml_stl_point();

	/* Test STL Vector */
	test_cml_stl_vector();

	/* Test STL Algorithm */
	test_cml_stl_algorithm();

	/* Test STL List */
	test_cml_stl_list();

	/* Test STL Array2d */
	test_cml_stl_array2d();

	/* Test STL Iterator */
	test_cml_stl_iterator();

	fclose(fpTest);

	//BIOS_exit(0);

	return 0;
}
