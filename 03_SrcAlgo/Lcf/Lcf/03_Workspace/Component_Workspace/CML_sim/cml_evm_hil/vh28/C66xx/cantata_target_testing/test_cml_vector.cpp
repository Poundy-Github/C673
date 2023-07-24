/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_vector.cpp
*    Author: uidr5428
*    Generated on: 19-Sep-2016 15:43:28
*    Generated from: test_cml_vector.c
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/
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


/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0
#define DELIMITER ','

#include "csv_parser.h"

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
class TEST_CLASS_CML_VECTOR
{
public:
  /* Prototypes for test functions */
  void run_tests_cml_vector();
  void test_Vector2Add_f32(int);
  void test_Vector2GetSqrDistI16_f32(int);
  void test_Vector2AddI16_i32(int);
  void test_Vector2AddP_i16(int);
  void test_Vector2GetSqrDist_f32(int);
  void test_Vector2GetSqrDist_i16(int);
  void test_Vector2AngleToXAxis_f32(int);
  void test_Vector2AngleToXAxis_i16(int);
  void test_Vector2GetSqrDistI32_f32(int);
  void test_Vector2GetYPointOnLine_f32(int);
  void test_VectorWeightedPNorm(int);
  void test_Vector2YAxisIntersectionAdd_i32(int);
  void test_Vector2SubP_i16(int);
  void test_Vector2Init_i16(int);
  void test_Vector2Sub_f32(int);
  void test_Vector2ScalarProd_i32(int);
  void test_Vector2ScalarProd_i16(int);
  void test_Vector2Mull_i16(int);
  void test_Vector2MathRotate2D_i16(int);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_vector(void)
{
  TEST_CLASS_CML_VECTOR test_object;

  std::cout << "******** Start Testing: CML Vector functions ********\n\n";
  fprintf(fpTest, "******** Start Testing: CML Vector functions ********\n\n");

  test_object.run_tests_cml_vector();

  std::cout << "End of Testing: CML Vector functions\n\n";
  fprintf(fpTest, "End of Testing: CML Vector functions\n\n");

  return;
}


/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_cml_vector() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_VECTOR::run_tests_cml_vector()
{
  test_Vector2Add_f32(1);
  test_Vector2GetSqrDistI16_f32(1);
  test_Vector2AddI16_i32(1);
  test_Vector2AddP_i16(1);	
  test_Vector2GetSqrDist_i16(1);
  test_Vector2AngleToXAxis_f32(1);
  test_Vector2AngleToXAxis_i16(1);
  test_Vector2GetSqrDistI32_f32(1); 
  test_Vector2GetYPointOnLine_f32(1); 
  test_VectorWeightedPNorm(1);
  test_Vector2YAxisIntersectionAdd_i32(1);
  test_Vector2SubP_i16(1);
  test_Vector2Init_i16(1);
  test_Vector2Sub_f32(1);
  test_Vector2ScalarProd_i32(1);
  test_Vector2ScalarProd_i16(1);
  test_Vector2Mull_i16(1);
  test_Vector2MathRotate2D_i16(1);
  test_Vector2GetSqrDist_f32(1);
  test_VectorWeightedPNorm(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_VECTOR::test_Vector2Add_f32(int doIt){
  if (doIt) {
    /* Test case data declarations */
    Vector2_f32_t vector1;
    Vector2_f32_t vector2;
    Vector2_f32_t expected_returnValue;
    Vector2_f32_t returnValue;
    float32 testvector_input[4];
    float32 testvector_output[2];

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2Add_f32_TestCase_1  "test_Vector2Add_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2Add_f32_TestCase_1  "test_Vector2Add_f32_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2Add_f32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(vector1.fXDist = minValue; vector1.fXDist <= maxValue; vector1.fXDist+=stepSize)
    {
      for(vector1.fYDist = minValue; vector1.fYDist <= maxValue; vector1.fYDist+=stepSize)
      {
        for(vector2.fXDist = minValue; vector2.fXDist <= maxValue; vector2.fXDist+=stepSize)
        {
          for(vector2.fYDist = minValue; vector2.fYDist <= maxValue; vector2.fYDist+=stepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            returnValue = Vector2Add_f32(vector1, vector2);
			  CALCULATE_CYLES(__FUNCTION__, 1)

            p_CsvDataOut.value[dataIndex] = returnValue.fXDist; 
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = returnValue.fYDist; 
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

void TEST_CLASS_CML_VECTOR::test_Vector2GetSqrDistI16_f32(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDistI16_f32_ZERO    "test_Vector2GetSqrDistI16_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDistI16_f32_ZERO    "test_Vector2GetSqrDistI16_f32_out_msvc.csv"

#endif


    Vector2_i16_t input_vector = { 0, 0 };
    /* expected return value */
    float32 expected_returnValue = 0;
    /* SUT return value */
    float32 returnValue;
    /* floating point tolerance */
    float32 f_Tolerance = 0.1f;

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    signed short minValue = 0;
    signed short maxValue = 0;
    signed short stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDistI16_f32_ZERO, "w+");
	PRINT_TEST_CASE(__FUNCTION__)
    minValue = -10000;
    maxValue = 10000;
    stepSize = 10000;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(input_vector.nXDist = minValue; input_vector.nXDist <= maxValue; input_vector.nXDist+=stepSize)
    {
      for(input_vector.nYDist = minValue; input_vector.nYDist <= maxValue; input_vector.nYDist+=stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = Vector2GetSqrDistI16_f32(input_vector);
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

void TEST_CLASS_CML_VECTOR::test_Vector2AddI16_i32(int doIt){
  if (doIt){
    /* Test case data declarations */
    Vector2_i32_t input_vector1;
    Vector2_i16_t input_vector2;
    Vector2_i32_t expected_returnValue;
    Vector2_i32_t returnValue;
    signed long testvector_input_input_vector1[2];
    signed short testvector_input_input_vector2[2];
    signed long testvector_output[2];

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    signed short sminValue = 0;
    signed short smaxValue = 0;
    signed long  lminValue = 0;
    signed long  lmaxValue = 0;
    signed short sstepSize = 0;
    signed long lstepSize  = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2AddI16_i32_TestCase_1  "test_Vector2AddI16_i32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2AddI16_i32_TestCase_1  "test_Vector2AddI16_i32_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();			

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2AddI16_i32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)
    sminValue = -100;
    smaxValue = 100;
    lminValue = SHRT_MIN;
    lmaxValue = SHRT_MAX+1;
    sstepSize = 100;
    lstepSize = SHRT_MAX+1;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(input_vector1.nXDist = lminValue; input_vector1.nXDist <= lmaxValue; input_vector1.nXDist+=lstepSize)
    {
      for(input_vector1.nYDist = lminValue; input_vector1.nYDist <= lmaxValue; input_vector1.nYDist+=lstepSize)
      {
        for(input_vector2.nXDist = sminValue; input_vector2.nXDist <= smaxValue; input_vector2.nXDist+=sstepSize)
        {
          for(input_vector2.nYDist = sminValue; input_vector2.nYDist <= smaxValue; input_vector2.nYDist+=sstepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            returnValue = Vector2AddI16_i32(input_vector1, input_vector2);
			CALCULATE_CYLES(__FUNCTION__, 1)

            p_CsvDataOut.value[dataIndex] = returnValue.nXDist;
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = returnValue.nYDist;
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

void TEST_CLASS_CML_VECTOR::test_Vector2AddP_i16(int doIt){
  if (doIt){

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_i16_t p_vector1_ref,p_vector2_ref,exp_ref;
    Vector2_i16_t* p_vector1 = &p_vector1_ref;
    Vector2_i16_t* p_vector2 = &p_vector2_ref;
    Vector2_i16_t* expected_result = &exp_ref;
    signed short test_vector_input[4] = {0};
    signed short test_vector_output[2] = {0};

    FILE *fp;
    signed short minValue = 0;
    signed short maxValue = 0;
    signed short stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2AddP_i16_TestCase_1  "test_Vector2AddP_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2AddP_i16_TestCase_1  "test_Vector2AddP_i16_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2AddP_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -100;
    maxValue = 100;
    stepSize = 100;
    p_vector2->nXDist = 0;
    p_vector2->nYDist = 0;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_vector1->nXDist = minValue; p_vector1->nXDist <= maxValue; p_vector1->nXDist+=stepSize)
    {
      for(p_vector1->nYDist = minValue; p_vector1->nYDist <= maxValue; p_vector1->nYDist+=stepSize)
      {					
        /* Call SUT */
		  GET_CLOCK()
        Vector2AddP_i16(p_vector1, p_vector2);
		  CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex] = p_vector2->nXDist;
        dataIndex++;
        p_CsvDataOut.value[dataIndex] = p_vector2->nYDist;
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

void TEST_CLASS_CML_VECTOR::test_Vector2GetSqrDist_f32(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_f32_t input_vector;
    float test_vector_input[2] = {0};
    float32 test_vector_output[2] = {0};

    float32 returnValue;
    float32 tolerance = (float32)pow (10., -1 * FLT_DIG);

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDist_f32_TestCase_1  "test_Vector2GetSqrDist_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDist_f32_TestCase_1  "test_Vector2GetSqrDist_f32_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDist_f32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)
    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(input_vector.fXDist = minValue; input_vector.fXDist <= maxValue; input_vector.fXDist+=stepSize)
    {
      for(input_vector.fYDist = minValue; input_vector.fYDist <= maxValue; input_vector.fYDist+=stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = Vector2GetSqrDist_f32(input_vector);
		CALCULATE_CYLES(__FUNCTION__, 1)

        dataIndex++;
      }
    }
    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
    fclose(fp);

    /* Checks on global data */
  }}

void TEST_CLASS_CML_VECTOR::test_Vector2GetSqrDist_i16(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_i16_t input_vector;
    signed short test_vector_input[2] = {0};

    sint32 returnValue;

    FILE *fp;
    signed short minValue = 0;
    signed short maxValue = 0;
    signed short stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDist_i16_TestCase_1  "test_Vector2GetSqrDist_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDist_i16_TestCase_1  "test_Vector2GetSqrDist_i16_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDist_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -100;
    maxValue = 100;
    stepSize = 100;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(input_vector.nXDist = minValue; input_vector.nXDist <= maxValue; input_vector.nXDist+=stepSize)
    {
      for(input_vector.nYDist = minValue; input_vector.nYDist <= maxValue; input_vector.nYDist+=stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = Vector2GetSqrDist_i16(input_vector);
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

void TEST_CLASS_CML_VECTOR::test_Vector2AngleToXAxis_f32(int doIt){
  if (doIt){

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    float test_vector_input[2]= {0};
    /* Test case data declarations */
    Vector2_f32_t input_vector;

    float32 returnValue;
    float32 tolerance = (float32)pow (10., -1 * FLT_DIG);

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2AngleToXAxis_f32_TestCase_1  "test_Vector2AngleToXAxis_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2AngleToXAxis_f32_TestCase_1  "test_Vector2AngleToXAxis_f32_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2AngleToXAxis_f32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(input_vector.fXDist = minValue; input_vector.fXDist <= maxValue; input_vector.fXDist+= stepSize)
    {
      for(input_vector.fYDist = minValue; input_vector.fYDist <= maxValue; input_vector.fYDist+= stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = Vector2AngleToXAxis_f32(input_vector);
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

void TEST_CLASS_CML_VECTOR::test_Vector2AngleToXAxis_i16(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    signed short  test_vector_input[2]= {0};
    /* Test case data declarations */
    Vector2_i16_t input_vector;

    float32 returnValue;
    float32 tolerance = (float32)pow (10., -1 * FLT_DIG);

    FILE *fp;
    signed short minValue = 0;
    signed short maxValue = 0;
    signed short stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2AngleToXAxis_i16_TestCase_1  "test_Vector2AngleToXAxis_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2AngleToXAxis_i16_TestCase_1  "test_Vector2AngleToXAxis_i16_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2AngleToXAxis_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)
    minValue = -100;
    maxValue = 100;
    stepSize = 100;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(input_vector.nXDist = minValue; input_vector.nXDist <= maxValue; input_vector.nXDist+= stepSize)
    {
      for(input_vector.nYDist = minValue; input_vector.nYDist <= maxValue; input_vector.nYDist+= stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = Vector2AngleToXAxis_i16(input_vector);
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

void TEST_CLASS_CML_VECTOR::test_Vector2GetSqrDistI32_f32(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDistI32_f32_1    "test_Vector2GetSqrDistI32_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDistI32_f32_1    "test_Vector2GetSqrDistI32_f32_out_msvc.csv"

#endif


    Vector2_i32_t input_vector = { 0, 0 };

    /* floating point tolerance */
    float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;


    FILE *fp;
    signed long minValue = 0;
    signed long maxValue = 0;
    signed long stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2GetSqrDistI32_f32_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = SHRT_MIN;
    maxValue = SHRT_MAX+1;
    stepSize = SHRT_MAX+1;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(input_vector.nXDist = minValue; input_vector.nXDist <= maxValue; input_vector.nXDist+=stepSize)
    {
      for(input_vector.nYDist = minValue; input_vector.nYDist <= maxValue; input_vector.nYDist+=stepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = Vector2GetSqrDistI32_f32(input_vector);
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

void TEST_CLASS_CML_VECTOR::test_Vector2GetYPointOnLine_f32(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_f32_t Point ;
    Vector2_i16_t DirectionVector;
    Vector2_f32_t p_InOut_ref;
    Vector2_f32_t* p_InOut = &p_InOut_ref;

    boolean returnValue;
    float test_inputs_Vector2_f32_t[4]= {0};
    signed short test_inputs_Vector2_i16_t[2] = {0};

    FILE *fp;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    signed short sminValue = 0;
    signed short smaxValue = 0;
    signed short sStepSize = 0;
    float32 fStepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2GetYPointOnLine_f32_TestCase_1  "test_Vector2GetYPointOnLine_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2GetYPointOnLine_f32_TestCase_1  "test_Vector2GetYPointOnLine_f32_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2GetYPointOnLine_f32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    fminValue = -1e6;
    fmaxValue = 1e6;
    sminValue = -100;
    smaxValue = 100;
    sStepSize = 100;
    fStepSize = 1e6;
    p_InOut->fXDist = 1.0f;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(Point.fXDist = fminValue; Point.fXDist <= fmaxValue; Point.fXDist+=fStepSize)
    {
      for(Point.fYDist = fminValue; Point.fYDist <= fmaxValue; Point.fYDist+=fStepSize)
      {
        for(DirectionVector.nXDist = sminValue; DirectionVector.nXDist <= smaxValue; DirectionVector.nXDist+=sStepSize)
        {
          for(DirectionVector.nYDist = sminValue; DirectionVector.nYDist <= smaxValue; DirectionVector.nYDist+=sStepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            returnValue = Vector2GetYPointOnLine_f32(Point, DirectionVector, p_InOut);
			CALCULATE_CYLES(__FUNCTION__, 1)

            p_CsvDataOut.value[dataIndex] = returnValue;
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = p_InOut->fXDist;
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = p_InOut->fYDist;
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

void TEST_CLASS_CML_VECTOR::test_VectorWeightedPNorm(int doIt){
  if (doIt) {
#define ARRSIZE 100

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* floating point tolerance */
    float32 tolerance = 0.1f;
    /* Test case data declarations */
    float32 a_vector[ARRSIZE] = {0.0f};
    float32 a_weights[ARRSIZE] = {0.0f};
    uint32 u_length;
    uint32 u_exponent;

    float32 returnValue;
    float32 test_vector_input_float[6] = {1.0f};
    uint32  test_vector_input_int[2] = {0};
    uint32 loopindex = 0;
    uint32 uimaxValue = ARRSIZE;
    uint32 uiminValue = 0;
    uint32 uiStepsize = 0;

    FILE *fp;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_VectorWeightedPNorm_TestCase_1  "test_VectorWeightedPNorm_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_VectorWeightedPNorm_TestCase_1  "test_VectorWeightedPNorm_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_VectorWeightedPNorm_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    /* Populate a_vector */
    for(loopindex = 0; loopindex < ARRSIZE; loopindex++)
    {
      a_vector[loopindex] = (float32)loopindex;
    }
    /* Populate a_weights */
    for(loopindex = 0; loopindex < ARRSIZE; loopindex++)
    {
      a_weights[loopindex] = (float32)loopindex;
    }
    uimaxValue = ARRSIZE;
    uiminValue = 0;
    uiStepsize = 50;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(u_length = uiminValue; u_length < uimaxValue; u_length+=uiStepsize)
    {
      for(u_exponent = uiminValue; u_exponent < uimaxValue; u_exponent+=uiStepsize)
      {
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = VectorWeightedPNorm(a_vector, a_weights, u_length, u_exponent);
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

void TEST_CLASS_CML_VECTOR::test_Vector2YAxisIntersectionAdd_i32(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    FILE *fp;
    sint32 minValue = 0;
    sint32 maxValue = 0;
    sint32 stepSize = 0;

    /* Test case data declarations */
    Vector2_i32_t Point1;
    Vector2_i32_t Point2;
    sint32 p_YIntersection_ref;
    sint32* p_YIntersection = &p_YIntersection_ref;
    boolean expected_returnValue;
    boolean returnValue;
    signed long test_vector_input[4]= {0};

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2YAxisIntersectionAdd_i32_TestCase_1  "test_Vector2YAxisIntersectionAdd_i32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2YAxisIntersectionAdd_i32_TestCase_1  "test_Vector2YAxisIntersectionAdd_i32_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();		

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2YAxisIntersectionAdd_i32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = SHRT_MIN;
    maxValue = SHRT_MAX+1;
    stepSize = SHRT_MAX+1;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(Point1.nXDist = minValue; Point1.nXDist <= maxValue; Point1.nXDist+=stepSize)
    {
      for(Point1.nYDist = minValue; Point1.nYDist <= maxValue; Point1.nYDist+=stepSize)
      {
        for(Point2.nXDist = minValue; Point2.nXDist <= maxValue; Point2.nXDist+=stepSize)
        {
          for(Point2.nYDist = minValue; Point2.nYDist <= maxValue; Point2.nYDist+=stepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            returnValue = Vector2YAxisIntersectionAdd_i32(Point1, Point2, p_YIntersection);
			  CALCULATE_CYLES(__FUNCTION__, 1)

            p_CsvDataOut.value[dataIndex] = returnValue;
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = *p_YIntersection;
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

void TEST_CLASS_CML_VECTOR::test_Vector2SubP_i16(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_i16_t p_min_ref,p_sub_ref,exp_ref;
    Vector2_i16_t* p_min = &p_min_ref;
    Vector2_i16_t* p_sub = &p_sub_ref;
    Vector2_i16_t* expected_result = &exp_ref;
    signed short test_vector_input[4] = {0};
    signed short test_vector_output[2] = {0};

    FILE *fp;
    signed short minValue = 0;
    signed short maxValue = 0;
    signed short stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2SubP_i16_TestCase_1  "test_Vector2SubP_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2SubP_i16_TestCase_1  "test_Vector2SubP_i16_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();		

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2SubP_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -100;
    maxValue = 100;
    stepSize = 100;
    p_min->nXDist = 100;
    p_min->nYDist = 100;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_sub->nXDist = minValue; p_sub->nXDist <= maxValue; p_sub->nXDist+=stepSize)
    {
      for(p_sub->nYDist = minValue; p_sub->nYDist <= maxValue; p_sub->nYDist+=stepSize)
      {
        /* Call SUT */

		  GET_CLOCK()
        Vector2SubP_i16(p_min, p_sub);
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex] = p_min->nXDist;
        dataIndex++;
        p_CsvDataOut.value[dataIndex] = p_min->nYDist;
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

void TEST_CLASS_CML_VECTOR::test_Vector2Init_i16(int doIt){
  if (doIt) {
  }}

void TEST_CLASS_CML_VECTOR::test_Vector2Sub_f32(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_f32_t min;
    Vector2_f32_t sub;

    Vector2_f32_t returnValue;
    signed short test_vector_input[4] = {0};
    signed short test_vector_output[2] = {0};

    FILE *fp;
    float32 minValue = 0.0f;
    float32 maxValue = 0.0f;
    float32 stepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2Sub_f32_TestCase_1  "test_Vector2Sub_f32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2Sub_f32_TestCase_1  "test_Vector2Sub_f32_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();		

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2Sub_f32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(min.fXDist = minValue; min.fXDist <= maxValue; min.fXDist+=stepSize)
    {
      for(min.fYDist = minValue; min.fYDist <= maxValue; min.fYDist+=stepSize)
      {
        for(sub.fXDist = minValue; sub.fXDist <= maxValue; sub.fXDist+=stepSize)
        {
          for(sub.fYDist = minValue; sub.fYDist <= maxValue; sub.fYDist+=stepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            returnValue = Vector2Sub_f32(min, sub); 
			  CALCULATE_CYLES(__FUNCTION__, 1)

            p_CsvDataOut.value[dataIndex] = returnValue.fXDist;
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = returnValue.fYDist;
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

void TEST_CLASS_CML_VECTOR::test_Vector2ScalarProd_i32(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_i32_t Point1;
    Vector2_i32_t Point2;
    ;
    signed long test_vector_input[4] = {0};
    sint32 returnValue;

    FILE *fp;
    sint32 minValue = 0;
    sint32 maxValue = 0;
    sint32 stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2ScalarProd_i32_TestCase_1  "test_Vector2ScalarProd_i32_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2ScalarProd_i32_TestCase_1  "test_Vector2ScalarProd_i32_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2ScalarProd_i32_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = SHRT_MIN + 1;
    maxValue = SHRT_MAX;
    stepSize = SHRT_MAX - 1;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(Point1.nXDist = minValue; Point1.nXDist <= maxValue; Point1.nXDist+=stepSize)
    {
      for(Point1.nYDist = minValue; Point1.nYDist <= maxValue; Point1.nYDist+=stepSize)
      {
        for(Point2.nXDist = minValue; Point2.nXDist <= maxValue; Point2.nXDist+=stepSize)
        {
          for(Point2.nYDist = minValue; Point2.nYDist <= maxValue; Point2.nYDist+=stepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            p_CsvDataOut.value[dataIndex] = Vector2ScalarProd_i32(Point1, Point2);
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

void TEST_CLASS_CML_VECTOR::test_Vector2ScalarProd_i16(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_i16_t Point1;
    Vector2_i16_t Point2;

    signed short test_vector_input[4] = {0};
    sint32 returnValue;

    FILE *fp;
    signed short minValue = 0;
    signed short maxValue = 0;
    signed short stepSize = 0;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2ScalarProd_i16_TestCase_1  "test_Vector2ScalarProd_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2ScalarProd_i16_TestCase_1  "test_Vector2ScalarProd_i16_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();		

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2ScalarProd_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    minValue = SHRT_MIN+1;
    maxValue = SHRT_MAX;
    stepSize = SHRT_MAX;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(Point1.nXDist = minValue; Point1.nXDist < maxValue; Point1.nXDist+=stepSize)
    {
      for(Point1.nYDist = minValue; Point1.nYDist < maxValue; Point1.nYDist+=stepSize)
      {
        for(Point2.nXDist = minValue; Point2.nXDist < maxValue; Point2.nXDist+=stepSize)
        {
          for(Point2.nYDist = minValue; Point2.nYDist < maxValue; Point2.nYDist+=stepSize)
          {
            /* Call SUT */
			  GET_CLOCK()
            p_CsvDataOut.value[dataIndex] = Vector2ScalarProd_i16(Point1, Point2);
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

void TEST_CLASS_CML_VECTOR::test_Vector2Mull_i16(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    /* Test case data declarations */
    Vector2_i16_t Vec;	

    signed short test_vector_input[2] = {0};
    signed long test_vector_output[2] = {0};
    Vector2_f32_t returnValue;
    float32 f_Factor;

    FILE *fp;
    signed short sminValue = 0;
    signed short smaxValue = 0;
    signed short sStepsize = 0;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    float32 fStepsize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2Mull_i16_TestCase_1  "test_Vector2Mull_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2Mull_i16_TestCase_1  "test_Vector2Mull_i16_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();		

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2Mull_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    sminValue = SHRT_MIN+1;
    smaxValue = SHRT_MAX;
    sStepsize = SHRT_MAX;
    fminValue = -1e6;
    fmaxValue = 1e6;
    fStepsize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(Vec.nXDist = sminValue; Vec.nXDist < smaxValue; Vec.nXDist+=sStepsize)
    {
      for(Vec.nYDist = sminValue; Vec.nYDist < smaxValue; Vec.nYDist+=sStepsize)
      {
        for(f_Factor = fminValue; f_Factor <= fmaxValue; f_Factor+=fStepsize)
        {
          /* Call SUT */
			GET_CLOCK()
          returnValue = Vector2Mull_i16(Vec, f_Factor);
		  CALCULATE_CYLES(__FUNCTION__, 1)

          p_CsvDataOut.value[dataIndex] = returnValue.fXDist;
          dataIndex++;
          p_CsvDataOut.value[dataIndex] = returnValue.fYDist;
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

void TEST_CLASS_CML_VECTOR::test_Vector2MathRotate2D_i16(int doIt){
  if (doIt) {

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;


    /* Test case data declarations */
    CML_t_TrafoMatrix2D p_Transform_Matrix_ref;
    Vector2_i16_t p_input_vector_ref;
    CML_t_TrafoMatrix2D* p_Transform_Matrix = &p_Transform_Matrix_ref;
    Vector2_i16_t* p_input_vector = &p_input_vector_ref;
    signed short Vector2_i16_t_inputs[2]= {0};
    signed short Vector2_i16_t_outputs[2]= {0};
    float32 float32_inputs[4]= {0};
    float32 tolerance = 0.0001f;

    FILE *fp;
    signed short sminValue = 0;
    signed short smaxValue = 0;
    signed short sStepsize = 0;
    float32 fminValue = 0.0f;
    float32 fmaxValue = 0.0f;
    float32 fstepSize = 0.0f;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_Vector2MathRotate2D_i16_TestCase_1  "test_Vector2MathRotate2D_i16_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_Vector2MathRotate2D_i16_TestCase_1  "test_Vector2MathRotate2D_i16_out_msvc.csv"

#endif
    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Vector2MathRotate2D_i16_TestCase_1, "w+");
	PRINT_TEST_CASE(__FUNCTION__)

    fminValue = -1e6;
    fmaxValue = 1e6;
    fstepSize = 1e6;
    p_input_vector->nXDist = 1;
    p_input_vector->nYDist = 1;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_Transform_Matrix->f00 = fminValue; p_Transform_Matrix->f00 <= fmaxValue; p_Transform_Matrix->f00+=fstepSize)
    {
      for(p_Transform_Matrix->f10 = fminValue; p_Transform_Matrix->f10 <= fmaxValue; p_Transform_Matrix->f10+=fstepSize)
      {
        /* Call SUT */
		  GET_CLOCK()
        Vector2MathRotate2D_i16(p_Transform_Matrix, p_input_vector);
		  CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex] = p_input_vector->nXDist;
        dataIndex++;
        p_CsvDataOut.value[dataIndex] = p_input_vector->nYDist;
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

/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
