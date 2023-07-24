/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_interpol.cpp
*    Author: uidr5428
*    Generated on: 20-Sep-2016 15:43:28
*    Generated from: test_cml_interpol.c
*/
/*******************************************************************************/
/* Environment Definition                                                       */
/********************************************************************************/ 


/* Include files from software under test */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <float.h>
#include <math.h>

extern "C" {
#include "cml_ext.h"
}


/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0
#define DELIMITER ','

#include "csv_parser.h"

#ifdef ENABLE_PROFILER
#include <time.h>

#ifdef PROFILE_C6x_DSP

extern unsigned long long int  get_clock();
extern volatile long long int start_clock;
extern volatile long long int stop_clock;
extern long long int overhead;
extern long long int total_cycles;

#else

extern unsigned int get_clock();
extern int start_clock;
extern int stop_clock;
extern int overhead;
extern int total_cycles;

#endif /* #ifdef PROFILE_C6x_DSP */

static void check__PrintValue_to_File(int Value, FILE *fpTest)
{
	fprintf(fpTest, ",%i,", Value);
}

#define PRINT_TEST_CASE(name) {\
                        std::cout <<name;\
                        fprintf(fpTest, "Function %s \n", (name));\
                        }
                        

#define GET_CLOCK()   start_clock = get_clock();

#define CALCULATE_CYLES(name, test_case_num)  {   \
        stop_clock = get_clock();\
        fprintf(fpTest, "%s---> Test case %d", (name), (test_case_num));\
        total_cycles = stop_clock - start_clock - overhead;\
        check__PrintValue_to_File(total_cycles, fpTest);\
        fprintf(fpTest, "\n");\
        }
        
#else

#define PRINT_TEST_CASE(test_case_num)
#define GET_CLOCK()
#define CALCULATE_CYLES(name,test_case_num)

#endif /* ENABLE_PROFILER */

#ifndef LINKED_LIST_PARSER
extern float data_log_buffer[1000000];
#endif

/* Test Log file */
extern FILE *fpTest;

/* Global Functions */
/* None */

/* Global data */
/* None */

/* Expected variables for global data */
/* None */

/* This function initialises global data to default values. This function       */
/* is called by every test case so must not contain test case specific settings */
static void initialise_global_data(){
  /* No global data */
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every test case so must not   */
/* contain test case specific settings.                                      */
static void initialise_expected_global_data(){
  /* No global data */
}

/* This function checks global data against the expected values. */
static void check_global_data(){
  /* No global data */
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_CML_STATISTICS
{
public:
  /* Prototypes for test functions */
  void run_tests_cml_stat();
  void test_CML_v_InitWeightedSample(int);
  void test_CML_v_AddSamplePoint(int);
  void test_CML_v_MultiplySampleWithFactor(int);
  void test_CML_v_ComputeMeanStd(int);
  void test_CML_f_CalcGaussErrorFunction(int);
  void test_CML_f_CalcStdGaussianCDF(int);
  void test_CML_v_Init_LSF(int);
  void test_CML_v_InitResults_LSF(int);
  void test_CML_v_AddData_LSF(int);
  void test_CML_f_CalculateSlope_LSF(int);
  void test_CML_f_CalculateCorrelation_LSF(int);
  void test_CML_f_CalculateYIntersection_LSF(int);
  void test_CML_f_CalculateSquareError_LSF(int);
  void test_CML_f_CalculateMeanSquareError_LSF(int);
  void test_CML_v_CalculateQuality_LSF(int);
  void test_CML_v_CalculateAll_LSF(int);
  void test_CML_f_Predict_LSF(int);
  void test_CML_v_Init_LSF_ForgetExponential(int);
  void test_CML_v_AddData_LSF_ForgetExponential(int);
  void test_CML_v_CalculateAll_LSF_ForgetExponential(int);
  void test_CML_f_CalcQuantile(int);
  void test_CML_f_StdGaussQuantile(int);
  void test_CML_f_GaussQuantile(int);
  void test_CML_v_Init_LSF_Quant(int);
  void test_CML_v_EncodeData_LSF_Quant(int);
  void test_CML_v_DecodeData_LSF_Quant(int);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stat(void)
{
  TEST_CLASS_CML_STATISTICS test_object;

  std::cout << "******** Start Testing: CML Statistics functions ********\n\n";
  fprintf(fpTest, "******** Start Testing: CML Statistics functions ********\n\n");

  test_object.run_tests_cml_stat();

  std::cout << "End of Testing: CML Statistics functions\n\n";
  fprintf(fpTest, "End of Testing: CML Statistics functions\n\n");

  return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_cml_interpol() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_STATISTICS::run_tests_cml_stat()
{
  test_CML_v_AddSamplePoint(1);
  test_CML_f_CalcGaussErrorFunction(1);
  test_CML_f_CalcStdGaussianCDF(1);
  test_CML_v_AddData_LSF(1);
  test_CML_f_CalculateSlope_LSF(1);
  test_CML_f_CalculateCorrelation_LSF(1);
  test_CML_f_CalculateYIntersection_LSF(1);
  test_CML_f_CalculateSquareError_LSF(1);
  test_CML_f_CalculateMeanSquareError_LSF(1);
  test_CML_v_CalculateAll_LSF(1);
  test_CML_f_Predict_LSF(1);
  test_CML_v_AddData_LSF_ForgetExponential(1);
  test_CML_f_CalcQuantile(1);
  test_CML_f_StdGaussQuantile(1);
  test_CML_f_GaussQuantile(1);
  test_CML_v_Init_LSF(1);
  test_CML_v_Init_LSF_ForgetExponential(1);
  test_CML_v_InitResults_LSF(1);
  test_CML_v_InitWeightedSample(1);
  test_CML_v_MultiplySampleWithFactor(1);
  test_CML_v_ComputeMeanStd(1);
  test_CML_v_CalculateAll_LSF_ForgetExponential(1);
  test_CML_v_CalculateQuality_LSF(1);
  test_CML_v_Init_LSF_Quant(1);
  test_CML_v_EncodeData_LSF_Quant(1);
  test_CML_v_DecodeData_LSF_Quant(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_STATISTICS::test_CML_v_AddSamplePoint(int doIt){
  if (doIt){
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_AddSamplePoint_Testcase_1  "test_CML_v_AddSamplePoint_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_AddSamplePoint_Testcase_1  "test_CML_v_AddSamplePoint_out_msvc.csv"

#endif

    CML_t_WeightedSample test_sample;
    CML_t_WeightedSample* p_sample ;

    float32 f_value;
    float32 f_weight;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return f_value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();	

    fp = fopen(TEST_CML_STAT_CSVOUT_AddSamplePoint_Testcase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_sample = &test_sample;

    minValue                 = -1e6;
    maxValue                 = 1e6;
    stepSize                 = 1e6;
    p_sample->dSumme         = 0.0f;       
    p_sample->dQuadSumme     = 0.0f;      
    p_sample->f_sumOfWeights = 0.0f;   

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(f_value = minValue; f_value <= maxValue; f_value+=stepSize)
    {
      for(f_weight = minValue; f_weight <= maxValue; f_weight+=stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        CML_v_AddSamplePoint(p_sample, f_value, f_weight);
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex] = p_sample->dSumme;
        dataIndex++;
        p_CsvDataOut.value[dataIndex] = p_sample->dQuadSumme;
        dataIndex++;
        p_CsvDataOut.value[dataIndex] = p_sample->f_sumOfWeights;
        dataIndex++;
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);

    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalcGaussErrorFunction(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_CalcGaussErrorFunction_T_001 "test_CML_f_CalcGaussErrorFunction_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_CalcGaussErrorFunction_T_001 "test_CML_f_CalcGaussErrorFunction_out_msvc.csv"

#endif


    float32 f_Value;


    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize[3] = {-1e6f, 0.015f, 1e5f};
    uint32 loopindex = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_CalcGaussErrorFunction_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    loopindex = 0;			

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(f_Value = minValue;f_Value <= maxValue;f_Value+=stepSize[loopindex])
    {
      /* Call SUT */
		GET_CLOCK()
      p_CsvDataOut.value[dataIndex] = CML_f_CalcGaussErrorFunction(f_Value);
		CALCULATE_CYLES(__FUNCTION__, 1)

      dataIndex++;
      loopindex++;
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalcStdGaussianCDF(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalcStdGaussianCDF_T_001 "test_CML_f_CalcStdGaussianCDF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalcStdGaussianCDF_T_001 "test_CML_f_CalcStdGaussianCDF_out_msvc.csv"

#endif

    float32 f_value;
    float32 f_avg;
    float32 fSigma;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalcStdGaussianCDF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(f_value = minValue; f_value <= maxValue;f_value+=stepSize)
    {
      for(f_avg = minValue; f_avg <= maxValue;f_avg+=stepSize)
      {
        for(fSigma = minValue; fSigma <= maxValue;fSigma+=stepSize)
        {
          /* Call SUT */
			GET_CLOCK()
          p_CsvDataOut.value[dataIndex]  = CML_f_CalcStdGaussianCDF(f_value, f_avg, fSigma);	
			CALCULATE_CYLES(__FUNCTION__, 1)

          dataIndex++;
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_AddData_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_v_AddData_LSF_T_001 "test_CML_v_AddData_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_v_AddData_LSF_T_001 "test_CML_v_AddData_LSF_out_msvc.csv"

#endif

    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF;
    CML_t_LeastSquareFit tt_LSF;

    float32 f_abscissae;
    float32 f_ordinate;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;

    float32 f_minValue = 0.0f;
    float32 f_maxValue = 0.0f;
    float32 fstepSize  = 0; 


    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_v_AddData_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF                = &test_LSF;			

    f_minValue           = -1e6;
    f_maxValue           = 1e6;
    fstepSize            = 1e6;

    p_LSF->fsumX         = 0.0f;
    p_LSF->fsumV         = 0.0f;
    p_LSF->fsumXX        = 0.0f;
    p_LSF->fsumXV        = 0.0f;
    p_LSF->fsumVV        = 0.0f;
    p_LSF->iData_Counter = 0;


    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(f_abscissae = f_minValue;f_abscissae <= f_maxValue;f_abscissae+=fstepSize)
    {
      for(f_ordinate = f_minValue;f_ordinate <= f_maxValue;f_ordinate+=fstepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        CML_v_AddData_LSF(p_LSF, f_abscissae, f_ordinate);
		  CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex]  = p_LSF->fsumX;
        dataIndex++;
        p_CsvDataOut.value[dataIndex]  = p_LSF->fsumV;
        dataIndex++;
        p_CsvDataOut.value[dataIndex]  = p_LSF->fsumXX;
        dataIndex++;
        p_CsvDataOut.value[dataIndex]  = p_LSF->fsumXV;
        dataIndex++;
        p_CsvDataOut.value[dataIndex]  = p_LSF->fsumVV;
        dataIndex++;
        p_CsvDataOut.value[dataIndex]  = p_LSF->iData_Counter;
        dataIndex++;
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);		

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalculateSlope_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalculateSlope_LSF_T_001 "test_CML_f_CalculateSlope_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalculateSlope_LSF_T_001 "test_CML_f_CalculateSlope_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF ;
    CML_t_LeastSquareFit tt_LSF;

    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    sint32 sminValue  = 0;
    sint32 smaxValue  = 0;
    float32 fstepSize = 0.0f;
    sint32 sstepSize  = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalculateSlope_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF = &test_LSF;
    fminValue = -1e6;
    fmaxValue = 1e6;
    sminValue = 2;
    smaxValue = 10;
    fstepSize = 1e6;
    sstepSize = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumX = fminValue;p_LSF->fsumX <= fmaxValue;p_LSF->fsumX+=fstepSize)
    {
      for(p_LSF->fsumV = fminValue;p_LSF->fsumV <= fmaxValue;p_LSF->fsumV+=fstepSize)
      {
        for(p_LSF->fsumXX = fminValue;p_LSF->fsumXX <= fmaxValue;p_LSF->fsumXX+=fstepSize)
        {
          for(p_LSF->fsumXV = fminValue;p_LSF->fsumXV <= fmaxValue;p_LSF->fsumXV+=fstepSize)
          {
            for(p_LSF->iData_Counter = sminValue;p_LSF->iData_Counter <= smaxValue;p_LSF->iData_Counter+=sstepSize)
            {					
              /* Call SUT */
				GET_CLOCK()
              p_CsvDataOut.value[dataIndex] = CML_f_CalculateSlope_LSF(p_LSF);
				CALCULATE_CYLES(__FUNCTION__, 1)

              dataIndex++;
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);			

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalculateCorrelation_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalculateCorrelation_LSF_T_001 "test_CML_f_CalculateCorrelation_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalculateCorrelation_LSF_T_001 "test_CML_f_CalculateCorrelation_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF ;
    CML_t_LeastSquareFit tt_LSF;

    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    sint32 sminValue  = 0;
    sint32 smaxValue  = 0;
    float32 fstepSize = 0.0f;
    sint32 sstepSize  = 0;
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalculateCorrelation_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF     = &test_LSF;			
    fminValue = -1e6;
    fmaxValue = 1e6;
    sminValue = -100;
    smaxValue = 100;
    fstepSize = 1e6;
    sstepSize = 100;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumX = fminValue;p_LSF->fsumX <= fmaxValue;p_LSF->fsumX+=fstepSize)
    {
      for(p_LSF->fsumV = fminValue;p_LSF->fsumV <= fmaxValue;p_LSF->fsumV+=fstepSize)
      {
        for(p_LSF->fsumXX = fminValue;p_LSF->fsumXX <= fmaxValue;p_LSF->fsumXX+=fstepSize)
        {
          for(p_LSF->fsumXV = fminValue;p_LSF->fsumXV <= fmaxValue;p_LSF->fsumXV+=fstepSize)
          {
            for(p_LSF->fsumVV = fminValue;p_LSF->fsumVV <= fmaxValue;p_LSF->fsumVV+=fstepSize)
            {
              for(p_LSF->iData_Counter = sminValue;p_LSF->iData_Counter <= smaxValue;p_LSF->iData_Counter+=sstepSize)
              {
                /* Call SUT */
				  
				GET_CLOCK()
                p_CsvDataOut.value[dataIndex]  = CML_f_CalculateCorrelation_LSF(p_LSF);
				CALCULATE_CYLES(__FUNCTION__, 1)

                dataIndex++;
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalculateYIntersection_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalculateYIntersection_LSF_T_001 "test_CML_f_CalculateYIntersection_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalculateYIntersection_LSF_T_001 "test_CML_f_CalculateYIntersection_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF ;
    CML_t_LeastSquareFit tt_LSF;

    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    sint32  sminValue = 0;
    sint32  smaxValue = 0;
    float32 fstepSize = 0.0f;
    sint32  sstepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalculateYIntersection_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF     = &test_LSF;
    fminValue = -1e6;
    fmaxValue = 1e6;
    sminValue = 2;
    smaxValue = 10;
    fstepSize = 1e6;
    sstepSize = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumX = fminValue;p_LSF->fsumX <= fmaxValue;p_LSF->fsumX+=fstepSize)
    {
      for(p_LSF->fsumV = fminValue;p_LSF->fsumV <= fmaxValue;p_LSF->fsumV+=fstepSize)
      {
        for(p_LSF->fsumXX = fminValue;p_LSF->fsumXX <= fmaxValue;p_LSF->fsumXX+=fstepSize)
        {
          for(p_LSF->fsumXV = fminValue;p_LSF->fsumXV <= fmaxValue;p_LSF->fsumXV+=fstepSize)
          {
            for(p_LSF->fsumVV = fminValue;p_LSF->fsumVV <= fmaxValue;p_LSF->fsumVV+=fstepSize)
            {
              for(p_LSF->iData_Counter = sminValue;p_LSF->iData_Counter <= smaxValue;p_LSF->iData_Counter+=sstepSize)
              {
                /* Call SUT */
				  GET_CLOCK()
                p_CsvDataOut.value[dataIndex] = CML_f_CalculateYIntersection_LSF(p_LSF);
				  CALCULATE_CYLES(__FUNCTION__, 1)

                dataIndex++;
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalculateSquareError_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalculateSquareError_LSF_T_001 "test_CML_f_CalculateSquareError_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalculateSquareError_LSF_T_001 "test_CML_f_CalculateSquareError_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF ;
    CML_t_LeastSquareFit tt_LSF;
    CML_t_LeastSquareFit* expected_LSF ;

    float32 f_LSFCorrelation;
    float32 expected_returnValue;
    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    sint32  sminValue = 0;
    sint32  smaxValue = 0;
    float32 fstepSize = 0.0f;
    sint32  sstepSize = 0;
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalculateSquareError_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF = &test_LSF;
    fminValue = -1e6;
    fmaxValue = 1e6;
    sminValue = 2;
    smaxValue = 10;
    fstepSize = 1e6;
    sstepSize = 2;



    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumV = fminValue;p_LSF->fsumV <= fmaxValue;p_LSF->fsumV+=fstepSize)
    {
      for(p_LSF->fsumVV = fminValue;p_LSF->fsumVV <= fmaxValue;p_LSF->fsumVV+=fstepSize)
      {
        for(p_LSF->iData_Counter = sminValue;p_LSF->iData_Counter <= smaxValue;p_LSF->iData_Counter+=sstepSize)
        {
          for(f_LSFCorrelation = fminValue;f_LSFCorrelation <= fmaxValue;f_LSFCorrelation+=fstepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            p_CsvDataOut.value[dataIndex] = CML_f_CalculateSquareError_LSF(p_LSF, f_LSFCorrelation);
			  CALCULATE_CYLES(__FUNCTION__, 1)

            dataIndex++;
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalculateMeanSquareError_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalculateMeanSquareError_LSF_T_001 "test_CML_f_CalculateMeanSquareError_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalculateMeanSquareError_LSF_T_001 "test_CML_f_CalculateMeanSquareError_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF ;
    CML_t_LeastSquareFit tt_LSF;


    float32 f_LSFCorrelation;

    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    sint32  sminValue = 0;
    sint32  smaxValue = 0;
    float32 fstepSize = 0.0f;
    sint32  sstepSize = 0;
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalculateMeanSquareError_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF = &test_LSF;
    fminValue = -1000;
    fmaxValue = 1000;
    sminValue = 2;
    smaxValue = 10;
    fstepSize = 1000;
    sstepSize = 2;			

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumV = fminValue;p_LSF->fsumV <= fmaxValue;p_LSF->fsumV+=fstepSize)
    {
      for(p_LSF->fsumVV = fminValue;p_LSF->fsumVV <= fmaxValue;p_LSF->fsumVV+=fstepSize)
      {
        for(p_LSF->iData_Counter = sminValue;p_LSF->iData_Counter <= smaxValue;p_LSF->iData_Counter+=sstepSize)
        {
          for(f_LSFCorrelation = fminValue;f_LSFCorrelation <= fmaxValue;f_LSFCorrelation+=fstepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            p_CsvDataOut.value[dataIndex] = CML_f_CalculateMeanSquareError_LSF(p_LSF, f_LSFCorrelation);	
			  CALCULATE_CYLES(__FUNCTION__, 1)

            dataIndex++;
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_CalculateAll_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_v_CalculateAll_LSF_T_001 "test_CML_v_CalculateAll_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_v_CalculateAll_LSF_T_001 "test_CML_v_CalculateAll_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFit test_LSF;
    CML_t_LeastSquareFit* p_LSF;
    CML_t_LeastSquareFitResults test_LSFRes;
    CML_t_LeastSquareFitResults* p_LSFRes;
    CML_t_LeastSquareFitResults t_LSFRes;


    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    sint32  sminValue = 0;
    sint32  smaxValue = 0;
    float32 fstepSize = 0.0f;
    sint32  sstepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_v_CalculateAll_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF     = &test_LSF;
    p_LSFRes  = &test_LSFRes;
    fminValue = -1e6;
    fmaxValue = 1e6;
    sminValue = 2;
    smaxValue = 10;
    fstepSize = 1e6;
    sstepSize = 2;			

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumX = fminValue;p_LSF->fsumX <= fmaxValue;p_LSF->fsumX+=fstepSize)
    {
      for(p_LSF->fsumV = fminValue;p_LSF->fsumV <= fmaxValue;p_LSF->fsumV+=fstepSize)
      {
        for(p_LSF->fsumXX = fminValue;p_LSF->fsumXX <= fmaxValue;p_LSF->fsumXX+=fstepSize)
        {
          for(p_LSF->fsumXV = fminValue;p_LSF->fsumXV <= fmaxValue;p_LSF->fsumXV+=fstepSize)
          {
            for(p_LSF->fsumVV = fminValue;p_LSF->fsumVV <= fmaxValue;p_LSF->fsumVV+=fstepSize)
            {
              for(p_LSF->iData_Counter = sminValue;p_LSF->iData_Counter <= smaxValue;p_LSF->iData_Counter+=sstepSize)
              {
                /* Call SUT */
				  GET_CLOCK()
                CML_v_CalculateAll_LSF(p_LSF, p_LSFRes);
				  CALCULATE_CYLES(__FUNCTION__, 1)

                p_CsvDataOut.value[dataIndex] =  p_LSFRes->fCorrelation;	
                dataIndex++;
                p_CsvDataOut.value[dataIndex] =  p_LSFRes->fChi2_Error;	
                dataIndex++;
                p_CsvDataOut.value[dataIndex] =  p_LSFRes->fSlope;	
                dataIndex++;
                p_CsvDataOut.value[dataIndex] =  p_LSFRes->fYIntersection;	
                dataIndex++;
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_Predict_LSF(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_Predict_LSF_T_001 "test_CML_f_Predict_LSF_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_Predict_LSF_T_001 "test_CML_f_Predict_LSF_out_msvc.csv"

#endif


    CML_t_LeastSquareFitResults test_LSFResults;
    CML_t_LeastSquareFitResults* p_LSFResults ;
    float32 f_xValue;
    float32 expected_returnValue;
    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    p_LSFResults = &test_LSFResults;
    fp = fopen(TEST_CML_STAT_CSVOUT_f_Predict_LSF_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSFResults->fSlope = minValue; p_LSFResults->fSlope <= maxValue; p_LSFResults->fSlope+=stepSize)
    {
      for(p_LSFResults->fYIntersection = minValue; p_LSFResults->fYIntersection <= maxValue; p_LSFResults->fYIntersection+=stepSize)
      {
        for(f_xValue = minValue; f_xValue <= maxValue; f_xValue+=stepSize)
        {
          /* Call SUT */
			GET_CLOCK()
          p_CsvDataOut.value[dataIndex] = CML_f_Predict_LSF(p_LSFResults, f_xValue);
		  CALCULATE_CYLES(__FUNCTION__, 1)

          dataIndex++;
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_AddData_LSF_ForgetExponential(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_v_AddData_LSF_ForgetExponential_T_001 "test_CML_v_AddData_LSF_ForgetExponential_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_v_AddData_LSF_ForgetExponential_T_001 "test_CML_v_AddData_LSF_ForgetExponential_out_msvc.csv"

#endif

    t_LeastSquareFit_ForgetExponential test_LSF;
    t_LeastSquareFit_ForgetExponential* p_LSF ;
    t_LeastSquareFit_ForgetExponential tt_LSF;
    t_LeastSquareFit_ForgetExponential* expected_LSF ;
    float32 f_abscissa;
    float32 f_ordinate;
    float32 f_MemoryWeight;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


    /* Set global data */
    initialise_global_data();

    p_LSF = &test_LSF;
    fp = fopen(TEST_CML_STAT_CSVOUT_v_AddData_LSF_ForgetExponential_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue             = -1e6;
    maxValue             = 1e6;
    stepSize             = 1e6;
    p_LSF->fsumX         = 0.0f;
    p_LSF->fsumV         = 0.0f;
    p_LSF->fsumXX        = 0.0f;
    p_LSF->fsumXV        = 0.0f;
    p_LSF->fsumVV        = 0.0f;
    p_LSF->fData_Counter = 0.0f;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);	

    for(f_abscissa = minValue; f_abscissa <= maxValue; f_abscissa+=stepSize)
    {
      for(f_ordinate = minValue; f_ordinate <= maxValue; f_ordinate+=stepSize)
      {
        for(f_MemoryWeight = minValue; f_MemoryWeight <= maxValue; f_MemoryWeight+=stepSize)
        {
          /* Call SUT */
			GET_CLOCK()
          CML_v_AddData_LSF_ForgetExponential(p_LSF, f_abscissa, f_ordinate, f_MemoryWeight);
			CALCULATE_CYLES(__FUNCTION__, 1)

          p_CsvDataOut.value[dataIndex] = p_LSF->fsumX;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = p_LSF->fsumV;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = p_LSF->fsumXX;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = p_LSF->fsumXV;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = p_LSF->fsumVV;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = p_LSF->fData_Counter;
          dataIndex++;
        }
      }
    }			
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_CalcQuantile(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_CalcQuantile_T_001 "test_CML_f_CalcQuantile_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_CalcQuantile_T_001 "test_CML_f_CalcQuantile_out_msvc.csv"

#endif

#define ARRSIZE 100
    float32 test_a_valuesDestroyed[ARRSIZE] = {0};
    float32* a_valuesDestroyed ;

    uint32 u_NofValues;
    uint32 u_NthSmallest;

    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    uint32 minValue  = 0;
    uint32 maxValue  = 0;
    uint32 stepSize  = 0;
    uint32 loopindex = 0;
    const float32 lookuptable[ARRSIZE] = {14.0f,48.0f,56.0f,75.0f,99.0f,99.0f,88.0f,62.0f,14.0f,58.0f,73.0f,79.0f,16.0f,22.0f,
      50.0f,46.0f,3.0f,28.0f,76.0f,73.0f,70.0f,6.0f,14.0f,35.0f,71.0f,59.0f,68.0f,55.0f,
      99.0f,7.0f,83.0f,2.0f,99.0f,33.0f,84.0f,9.0f,70.0f,54.0f,86.0f,64.0f,96.0f,75.0f,
      62.0f,83.0f,36.0f,20.0f,60.0f,33.0f,37.0f,85.0f,67.0f,42.0f,86.0f,75.0f,57.0f,
      51.0f,59.0f,48.0f,62.0f,30.0f,4.0f,29.0f,3.0f,77.0f,59.0f,9.0f,64.0f,45.0f,
      62.0f,95.0f,77.0f,84.0f,18.0f,86.0f,22.0f,17.0f,66.0f,11.0f,17.0f,35.0f,
      67.0f,70.0f,16.0f,26.0f,14.0f,57.0f,56.0f,96.0f,72.0f,81.0f,61.0f,77.0f,
      19.0f,67.0f,12.0f,31.0f,43.0f,79.0f,57.0f,80.0f};

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    a_valuesDestroyed = test_a_valuesDestroyed;
    fp = fopen(TEST_CML_STAT_CSVOUT_f_CalcQuantile_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue  = 1;
    maxValue  = 100;
    stepSize  = 50;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);	

    /* Populate a_valuesDestroyed */
    /* Give Random Numbers - lookup table */
    for(loopindex = 0; loopindex < ARRSIZE; loopindex++)
      test_a_valuesDestroyed[loopindex] = lookuptable[loopindex];

    for(u_NofValues = minValue; u_NofValues <= maxValue; u_NofValues+=stepSize)
    {
      for(u_NthSmallest = minValue; u_NthSmallest <= maxValue; u_NthSmallest+=stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_CalcQuantile(a_valuesDestroyed, u_NofValues, u_NthSmallest);
		  CALCULATE_CYLES(__FUNCTION__, 1)
        dataIndex++;
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_StdGaussQuantile(int doIt){
  if (doIt){

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_StdGaussQuantile_T_001 "test_CML_f_StdGaussQuantile_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_StdGaussQuantile_T_001 "test_CML_f_StdGaussQuantile_out_msvc.csv"

#endif

    float32 f_Prob;

    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp =  fopen(TEST_CML_STAT_CSVOUT_f_StdGaussQuantile_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -0.5f;
    maxValue = 1.0f;
    stepSize = 0.25f;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);	

    for(f_Prob = minValue; f_Prob <= maxValue; f_Prob+=stepSize)
    {
      /* Call SUT */
		GET_CLOCK()
      p_CsvDataOut.value[dataIndex] = CML_f_StdGaussQuantile(f_Prob);
		CALCULATE_CYLES(__FUNCTION__, 1)

      dataIndex++;
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_f_GaussQuantile(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_f_GaussQuantile_T_001 "test_CML_f_GaussQuantile_out_target.csv"

#else
#define TEST_CML_STAT_CSVOUT_f_GaussQuantile_T_001 "test_CML_f_GaussQuantile_out_msvc.csv"

#endif

    float32 f_Mean;
    float32 f_Std;
    float32 f_Prob;
    float32 expected_returnValue;
    float32 returnValue;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue1 = 0.0f;
    float32 maxValue1 = 0.0f;
    float32 stepSize1 = 0.0f;
    float32 minValue2 = 0.0f;
    float32 maxValue2 = 0.0f;
    float32 stepSize2 = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_f_GaussQuantile_T_001, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue1 = -1e6;
    maxValue1 = 1e6;
    stepSize1 = 1e6;
    minValue2 = -0.5f;
    maxValue2 = 1.0f;
    stepSize2 = 0.25f;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);	

    for(f_Mean = minValue1; f_Mean <= maxValue1; f_Mean+=stepSize1)
    {
      for(f_Std = minValue1; f_Std <= maxValue1; f_Std+=stepSize1)
      {
        for(f_Prob = minValue2; f_Prob <= maxValue2; f_Prob+=stepSize2)
        {
          /* Call SUT */
			GET_CLOCK()
          p_CsvDataOut.value[dataIndex] = CML_f_GaussQuantile(f_Mean, f_Std, f_Prob);
			CALCULATE_CYLES(__FUNCTION__, 1)

          dataIndex++;
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_Init_LSF(int doIt){
  if (doIt){

  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_Init_LSF_ForgetExponential(int doIt){
  if (doIt){
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_InitResults_LSF(int doIt){
  if (doIt){
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_InitWeightedSample(int doIt){
  if (doIt){
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_MultiplySampleWithFactor(int doIt){
  if (doIt){
    /* Test case data declarations */
    CML_t_WeightedSample test_LSF;
    CML_t_WeightedSample* p_sample ;
    CML_t_WeightedSample tt_LSF;
    CML_t_WeightedSample* expected_LSF;

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    float32 tolerance = 0.00001f;
    float32 input_testVectors[6];
    float32 output_testVectors[5];
    float32 f_factor;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_STAT_CSVOUT_CML_v_MultiplySampleWithFactor_TestCase_001 "test_CML_v_MultiplySampleWithFactor_out_target.csv"		

#else
#define TEST_CML_STAT_CSVOUT_CML_v_MultiplySampleWithFactor_TestCase_001 "test_CML_v_MultiplySampleWithFactor_out_msvc.csv"		

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_STAT_CSVOUT_CML_v_MultiplySampleWithFactor_TestCase_001,"w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_sample                 = &test_LSF;
    minValue                 = -1e6;
    maxValue                 = 1e6;
    stepSize                 = 1e6;
    p_sample->dSumme         = 1.0f;
    p_sample->dQuadSumme     = 1.0f;
    p_sample->f_sumOfWeights = 1.0f;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(f_factor = minValue; f_factor <= maxValue; f_factor+=stepSize)
    {
      /* Call SUT */
		GET_CLOCK()
      CML_v_MultiplySampleWithFactor(p_sample,f_factor);
		CALCULATE_CYLES(__FUNCTION__, 1)

      p_CsvDataOut.value[dataIndex] = p_sample->dSumme;
      dataIndex++;
      p_CsvDataOut.value[dataIndex] = p_sample->dQuadSumme;
      dataIndex++;
      p_CsvDataOut.value[dataIndex] = p_sample->f_sumOfWeights;
      dataIndex++;
    }		
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_ComputeMeanStd(int doIt){
  if (doIt){

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;


    /* Test case data declarations */
    CML_t_WeightedSample sample_ref;
    CML_t_WeightedSample* p_sample = &sample_ref;
    float32 test_vector_input[6];
    float32 test_vector_output[6];
    uint8 index;
    float32 tolerance = 0.00001f;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;
    float32 minValueQ = 0.0f;
    float32 maxValueQ = 0.0f;
    float32 stepSizeQ = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_v_ComputeMeanStd_TestCase_1  "test_CML_v_ComputeMeanStd_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_v_ComputeMeanStd_TestCase_1  "test_CML_v_ComputeMeanStd_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_v_ComputeMeanStd_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = 1;
    maxValue = 1000;
    stepSize = 500;
    minValueQ = 1;
    maxValueQ = 10000;
    stepSizeQ = 5000;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_sample->dSumme = minValue; p_sample->dSumme <= maxValue; p_sample->dSumme+=stepSize)
    {
      for(p_sample->dQuadSumme = minValueQ; p_sample->dQuadSumme <= maxValueQ; p_sample->dQuadSumme+=stepSizeQ)
      {
        for(p_sample->f_sumOfWeights = minValue; p_sample->f_sumOfWeights <= maxValue; p_sample->f_sumOfWeights+=stepSize)
        {
          /* Call SUT */
			GET_CLOCK()
          CML_v_ComputeMeanStd(p_sample);
			CALCULATE_CYLES(__FUNCTION__, 1)

          p_CsvDataOut.value[dataIndex] = p_sample->dMittel;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = p_sample->dStdAbw;
          dataIndex++;
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_CalculateAll_LSF_ForgetExponential(int doIt){
  if (doIt){
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_v_CalculateAll_LSF_ForgetExponential_TestCase_1  "test_CML_v_CalculateAll_LSF_ForgetExponential_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_v_CalculateAll_LSF_ForgetExponential_TestCase_1  "test_CML_v_CalculateAll_LSF_ForgetExponential_out_msvc.csv"

#endif


    t_LeastSquareFit_ForgetExponential LSF_ref;
    CML_t_LeastSquareFitResults LSFRes_ref;
    t_LeastSquareFit_ForgetExponential* p_LSF = &LSF_ref;
    CML_t_LeastSquareFitResults* p_LSFRes = &LSFRes_ref;

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    float32 test_vector_input[12];
    float32 test_vector_output[12];
    uint8 index;
    float32 tolerance = 0.00001f;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    float32 fstepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_v_CalculateAll_LSF_ForgetExponential_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    fminValue = 2;
    fmaxValue = 10;
    fstepSize = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumX = minValue; p_LSF->fsumX <= maxValue; p_LSF->fsumX+=stepSize)
    {
      for(p_LSF->fsumV = minValue; p_LSF->fsumV <= maxValue; p_LSF->fsumV+=stepSize)
      {
        for(p_LSF->fsumXX = minValue; p_LSF->fsumXX <= maxValue; p_LSF->fsumXX+=stepSize)
        {
          for(p_LSF->fsumVV = minValue; p_LSF->fsumVV <= maxValue; p_LSF->fsumVV+=stepSize)
          {
            for(p_LSF->fsumXV = minValue; p_LSF->fsumXV <= maxValue; p_LSF->fsumXV+=stepSize)
            {
              for(p_LSF->fData_Counter = fminValue; p_LSF->fData_Counter <= fmaxValue; p_LSF->fData_Counter+=fstepSize)
              {
                /* Call SUT */
				  GET_CLOCK()
                CML_v_CalculateAll_LSF_ForgetExponential(p_LSF, p_LSFRes);
				  CALCULATE_CYLES(__FUNCTION__, 1)

                p_CsvDataOut.value[dataIndex] = p_LSFRes->fCorrelation;
                dataIndex++;
                p_CsvDataOut.value[dataIndex] = p_LSFRes->fChi2_Error;
                dataIndex++;
                p_CsvDataOut.value[dataIndex] = p_LSFRes->fSlope;
                dataIndex++;
                p_CsvDataOut.value[dataIndex] = p_LSFRes->fYIntersection;
                dataIndex++;
                p_CsvDataOut.value[dataIndex] = p_LSFRes->fmse;
                dataIndex++;
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }} 

void TEST_CLASS_CML_STATISTICS::test_CML_v_CalculateQuality_LSF(int doIt){
  if (doIt) {

    /* Test case data declarations */ 
#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_v_CalculateQuality_LSF_1 "test_CML_v_CalculateQuality_LSF_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_v_CalculateQuality_LSF_1 "test_CML_v_CalculateQuality_LSF_out_msvc.csv"

#endif

    CML_t_LeastSquareFit temp_LSF;
    float32 temp_fLSFCorrelation;
    float32 temp_fLSFmse;
    CML_t_LeastSquareFit* p_LSF ;
    float32* f_LSFCorrelation;
    float32* f_LSFmse;
    float32 expected_returnValue;
    float32 expected_returnValue_1;
    /* result CSV data, linked list node*/
    csv_data_t p_CsvDataOut_ref;

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    float32 fstepSize = 0.0f;
    sint32 sminValue  = 0;
    sint32 smaxValue  = 0;
    sint32 sstepSize  = 0;


    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_v_CalculateQuality_LSF_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    p_LSF = &temp_LSF;
    f_LSFCorrelation = &temp_fLSFCorrelation;
    f_LSFmse = &temp_fLSFmse;
    fminValue = -1e6;
    fmaxValue = 1e6;
    fstepSize = 1e6;
    sminValue  = 2;
    smaxValue  = 10;
    sstepSize  = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_LSF->fsumX = fminValue; p_LSF->fsumX <= fmaxValue; p_LSF->fsumX+=fstepSize)
    {
      for(p_LSF->fsumV = fminValue; p_LSF->fsumV <= fmaxValue; p_LSF->fsumV+=fstepSize)
      {
        for(p_LSF->fsumXX = fminValue; p_LSF->fsumXX <= fmaxValue; p_LSF->fsumXX+=fstepSize)
        {
          for(p_LSF->fsumVV = fminValue; p_LSF->fsumVV <= fmaxValue; p_LSF->fsumVV+=fstepSize)
          {
            for(p_LSF->fsumXV = fminValue; p_LSF->fsumXV <= fmaxValue; p_LSF->fsumXV+=fstepSize)
            {
              for(p_LSF->iData_Counter = sminValue; p_LSF->iData_Counter <= smaxValue; p_LSF->iData_Counter+=sstepSize)
              {
                /* Call SUT */
				  GET_CLOCK()
                CML_v_CalculateQuality_LSF(p_LSF, f_LSFCorrelation, f_LSFmse);
				  CALCULATE_CYLES(__FUNCTION__, 1)

                p_CsvDataOut.value[dataIndex] = *f_LSFCorrelation;
                dataIndex++;
                p_CsvDataOut.value[dataIndex] = *f_LSFmse;
                dataIndex++;
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_Init_LSF_Quant(int doIt){
  if (doIt) {
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_EncodeData_LSF_Quant(int doIt){
  if (doIt) {
    /* Test case data declarations */ 
    CML_t_LeastSquareFit test_LSFNonQuant;
    CML_t_LeastSquareFit const *const p_LSFNonQuant = &test_LSFNonQuant;
    float32 f_encodeX;
    float32 f_encodeV;
    CML_t_LeastSquareFitQuant test_LSFQuant;
    CML_t_LeastSquareFitQuant *const p_LSFQuant = &test_LSFQuant;
    CML_t_LeastSquareFitQuant expected_p_LSFQuant;

  /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = FLT_MIN;
    float32 fmaxValue = FLT_MAX;
    float32 fstepSize = 0.0001f;
    sint32 sminValue  = INT_MIN;
    sint32 smaxValue  = INT_MAX;
    sint32 sstepSize  = 1;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_v_EncodeData_LSF_Quant_7	"test_CML_v_EncodeData_LSF_Quant_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_v_EncodeData_LSF_Quant_7	"test_CML_v_EncodeData_LSF_Quant_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    memset(&test_LSFNonQuant ,0 ,sizeof (test_LSFNonQuant));
    memset(&test_LSFQuant ,0 ,sizeof (test_LSFQuant));
    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_v_EncodeData_LSF_Quant_7, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    fminValue = -1e6;
    fmaxValue = 1e6+3;
    fstepSize = 1e6+1;
    sminValue  = 2;
    smaxValue  = 10;
    sstepSize  = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(test_LSFNonQuant.fsumX = fminValue; test_LSFNonQuant.fsumX <= fmaxValue; test_LSFNonQuant.fsumX+=fstepSize)
    {
      for(test_LSFNonQuant.fsumV = fminValue; test_LSFNonQuant.fsumV <= fmaxValue; test_LSFNonQuant.fsumV+=fstepSize)
      {
        for(test_LSFNonQuant.fsumXX = fminValue; test_LSFNonQuant.fsumXX <= fmaxValue; test_LSFNonQuant.fsumXX+=fstepSize)
        {
          for(test_LSFNonQuant.fsumVV = fminValue; test_LSFNonQuant.fsumVV <= fmaxValue; test_LSFNonQuant.fsumVV+=fstepSize)
          {
            for(test_LSFNonQuant.fsumXV = fminValue; test_LSFNonQuant.fsumXV <= fmaxValue; test_LSFNonQuant.fsumXV+=fstepSize)
            {
              for(test_LSFNonQuant.iData_Counter = sminValue; test_LSFNonQuant.iData_Counter <= smaxValue; test_LSFNonQuant.iData_Counter+=sstepSize)
              {
                for(f_encodeX = fminValue; f_encodeX <= fmaxValue; f_encodeX+=fstepSize)
                {
                  for(f_encodeV = fminValue; f_encodeV <= fmaxValue; f_encodeV+=fstepSize)
                  {
                    /* Call SUT */
					  GET_CLOCK()
                    CML_v_EncodeData_LSF_Quant(p_LSFNonQuant,f_encodeX, f_encodeV, p_LSFQuant);
					  CALCULATE_CYLES(__FUNCTION__, 1)
                    p_CsvDataOut.value[dataIndex] = p_LSFQuant->u_sumX;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFQuant->s_sumV;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFQuant->u_sumXX;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFQuant->s_sumXV;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFQuant->u_sumVV;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFQuant->u_Data_Counter;
                    dataIndex++;
                  }
                }
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}

void TEST_CLASS_CML_STATISTICS::test_CML_v_DecodeData_LSF_Quant(int doIt){
  if (doIt) {
    /* Test case data declarations */ 
    CML_t_LeastSquareFit test_LSFNonQuant;
    CML_t_LeastSquareFit *const p_LSFNonQuant = &test_LSFNonQuant;
    float32 f_encodeX;
    float32 f_encodeV;
    CML_t_LeastSquareFitQuant test_LSFQuant;
    CML_t_LeastSquareFitQuant const *const p_LSFQuant = &test_LSFQuant;
    CML_t_LeastSquareFitQuant expected_p_LSFQuant;
    float32 f_decodeX;
    float32 f_decodeV;
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 fminValue = 0;
    float32 fmaxValue = 0;
    float32 fstepSize = 0;
    uint16 sminValue  = 0;
    uint16 smaxValue  = 0;
    uint16 sstepSize  = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_v_DecodeData_LSF_Quant_3	"test_CML_v_DecodeData_LSF_Quant_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_v_DecodeData_LSF_Quant_3	"test_CML_v_DecodeData_LSF_Quant_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();
    memset(&test_LSFNonQuant ,0 ,sizeof (test_LSFNonQuant));
    memset(&test_LSFQuant ,0 ,sizeof (test_LSFQuant));
    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_v_DecodeData_LSF_Quant_3, "w+");
	PRINT_TEST_CASE(__FUNCTION__)
    fminValue = -1e6;
    fmaxValue = 1e6;
    fstepSize = 1e6;
    sminValue = 2;
    smaxValue = 10;
    sstepSize = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(test_LSFQuant.u_sumX = sminValue; test_LSFQuant.u_sumX <= smaxValue; test_LSFQuant.u_sumX+=sstepSize)
    {
      for(test_LSFQuant.s_sumV = sminValue; test_LSFQuant.s_sumV <= smaxValue; test_LSFQuant.s_sumV+=sstepSize)
      {
        for(test_LSFQuant.u_sumXX = sminValue; test_LSFQuant.u_sumXX <= smaxValue; test_LSFQuant.u_sumXX+=sstepSize)
        {
          for(test_LSFQuant.s_sumXV = sminValue; test_LSFQuant.s_sumXV <= smaxValue; test_LSFQuant.s_sumXV+=sstepSize)
          {
            for(test_LSFQuant.u_sumVV = sminValue; test_LSFQuant.u_sumVV <= smaxValue; test_LSFQuant.u_sumVV+=sstepSize)
            {
              for(test_LSFQuant.u_Data_Counter = sminValue; test_LSFQuant.u_Data_Counter <= smaxValue; test_LSFQuant.u_Data_Counter+=sstepSize)
              {
                for(f_decodeX = fminValue; f_decodeX <= fmaxValue; f_decodeX+=fstepSize)
                {
                  for(f_decodeV = fminValue; f_decodeV <= fmaxValue; f_decodeV+=fstepSize)
                  {
                    /* Call SUT */
					  GET_CLOCK()
                    CML_v_DecodeData_LSF_Quant(p_LSFQuant,f_decodeX, f_decodeV, p_LSFNonQuant);
					  CALCULATE_CYLES(__FUNCTION__, 1)

                    p_CsvDataOut.value[dataIndex] = p_LSFNonQuant->fsumX;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFNonQuant->fsumV;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFNonQuant->fsumXX;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFNonQuant->fsumXV;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFNonQuant->fsumVV;
                    dataIndex++;
                    p_CsvDataOut.value[dataIndex] = p_LSFNonQuant->iData_Counter;
                    dataIndex++;
                  }
                }
              }
            }
          }
        }
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
    check_global_data();
  }}


/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
