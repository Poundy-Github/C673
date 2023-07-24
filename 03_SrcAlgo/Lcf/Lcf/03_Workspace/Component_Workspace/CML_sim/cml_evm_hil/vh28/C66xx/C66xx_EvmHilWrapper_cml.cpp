/*
 *  ======== main.c ========
 */
#ifdef TARGET_PLATFORM
#include <time.h>
#include <xdc/std.h>

#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>
#ifdef _TMS320C6600
#include <ti/sysbios/family/c66/Cache.h>
#else
#include <ti/sysbios/family/c64p/Cache.h>
#endif
#endif /* #ifdef TARGET_PLATFORM */

#include <stdio.h>
#include "string.h"

#include <algorithm>
#include <functional>
#include <iostream>

#if defined(_MSC_VER)
#include <fpieee.h>
#include <excpt.h>
#include <float.h>
#include <errno.h>
#include <atlstr.h>
#endif

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
extern void test_cml_stl_cmath(void);
extern void test_cml_kafi(void);
extern void test_cml_trigo(void);
extern void test_cml_misc(void);
extern void test_cml_mat(void);
extern void test_cml_mtrx(void);
extern void test_cml_fourier(void);
extern void test_cml_bayes(void);
extern void test_cml_complex(void);
extern void test_cml_interpol(void);
extern void test_cml_stat(void);
extern void test_cml_vector(void);


/* Test Log file */
FILE *fpTest = NULL;

#ifndef LINKED_LIST_PARSER
float data_log_buffer[1000000];
#endif

#ifdef ENABLE_PROFILER

#ifdef PROFILE_C6x_DSP
volatile long long int start_clock    = 0;
volatile long long int stop_clock     = 0;
long long int overhead       = 0;
volatile long long int total_cycles   = 0;
#else

int start_clock    = 0;
int stop_clock     = 0;
int overhead       = 0;
int total_cycles   = 0;
#endif

extern cregister volatile unsigned int TSCL;
extern cregister volatile unsigned int TSCH;

#ifdef PROFILE_C6x_DSP
unsigned long long int get_clock();

unsigned long long int get_clock()
{
	return(_itoll(TSCH, TSCL));
}
#else

clock_t get_clock();

clock_t get_clock()
{
	/* must read TSCL first! */
	unsigned int low  = TSCL;
	unsigned int high = TSCH;

	/* clock_t is only 32 bits, so if TSCH is
	   non-zero return -1 meaning "unrepresentable" */
	if (high)
		return (clock_t)-1;

	return low;
}
#endif

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

#if defined(_MSC_VER)
	// Floating point settings

    unsigned int stat;
    int err;
	const BOOL bExceptionsActiveFlag = TRUE;
    const BOOL bMantissa24ActiveFlag = TRUE;
    // Set the x86 floating-point control word according to what exceptions you want to trap.
    stat = _clearfp();      // Always call _clearfp before setting the control word

    // Because the second parameter in the following call is 0, it only returns the floating-point
    // control word. It's used in SimDbgRestoreFPU to set to original settings.

    //err = _controlfp_s(&m_cwOriginal, 0, 0);

    // Set the exception masks off for exceptions that you want to trap.  When a mask bit is set,
    // the corresponding floating-point exception is blocked from being generated.
    // Possible Exceptions are:
    // EM_INVALID
    // EM_DENORMAL
    // EM_ZERODIVIDE
    // EM_OVERFLOW
    // EM_UNDERFLOW
    // EM_INEXACT
    if (bExceptionsActiveFlag)
    {
      // FLOATING POINT EXCEPTIONS de/activation 
      err = _controlfp_s(&stat, _EM_INVALID | _EM_INEXACT | _EM_OVERFLOW | _EM_UNDERFLOW, _MCW_EM);
    }

    if (bMantissa24ActiveFlag)
    {
      // Set precision to 24 Bit Mantissa
      err = _controlfp_s(&stat, _PC_24, MCW_PC);
    }
    else
    {
      // (Re-) Set precission to ???:
      // Possible values:
      // _PC_64   64 bits */
      // _PC_53   53 bits - Default value on PC */
      // _PC_24   24 bits */
      err = _controlfp_s(&stat, _PC_53, MCW_PC);
    }
#endif

#ifdef ENABLE_PROFILER
	start_clock = get_clock();

	stop_clock = get_clock();

	overhead = stop_clock - start_clock;
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
	start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

	fpTest = fopen("TestLog.csv", "wb+");

#ifdef ENABLE_PROFILER
	stop_clock = get_clock();

	total_cycles = stop_clock - start_clock;
#endif /* #ifdef ENABLE_PROFILER */

	//System_printf("START CML Test Application\n");

	///* Test STL Matrix */
	//test_cml_stl_matrix();

	///* Test STL Array */
	//test_cml_stl_array();

	///* Test STL Point */
	//test_cml_stl_point();

	///* Test STL Vector */
	//test_cml_stl_vector();

	///* Test STL Algorithm */
	//test_cml_stl_algorithm();

	///* Test STL List */
	//test_cml_stl_list();

	///* Test STL Array2d */
	//test_cml_stl_array2d();

	///* Test STL Iterator */
	//test_cml_stl_iterator();

	///* Test STL cmath */
	//test_cml_stl_cmath();

	///* Test CML kafi */
	//test_cml_kafi();

	/* Test CML trigo */
	test_cml_trigo();
	
	///* Test CML misc */
	//test_cml_misc();

	///* Test CML mat */
	//test_cml_mat();

	///* Test CML mtrx */
	//test_cml_mtrx();

	///* Test CML fourier */
	//test_cml_fourier();	
	//
	///* Test CML bayes */
	//test_cml_bayes();
	//
	///* Test CML complex */
	//test_cml_complex();

	///* Test CML interpol */
	//test_cml_interpol();
	//
	///* Test CML stat */
	//test_cml_stat();
	//
	///* Test CML vector */
	//test_cml_vector();

	fclose(fpTest);

	//BIOS_exit(0);

	return 0;
}
