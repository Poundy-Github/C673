/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_complex.cpp
*    Author: uidr5428
*    Generated on: 31-Aug-2016 15:43:28
*    Generated from: test_cml_complex.c
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


/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0
#define DELIMITER ','

#include "csv_parser.h"

#ifndef LINKED_LIST_PARSER
extern float data_log_buffer[1000000];
#endif

/* Test Log file */
extern FILE *fpTest;

/* pragma qas cantata testscript start */
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
class TEST_CLASS_CML_COMPLEX
{
public:
  /* Prototypes for test functions */
  void run_tests_cml_complex();
  void test_CML_v_Cartesian2Polar(int);
  void test_CML_v_Polar2Cartesian(int);
  void test_CML_v_PhaseUnwrapping(int);
  void test_CML_v_MultiplyComplex(int);
  void test_CML_v_DivideComplex(int);
  void test_CML_v_QuadraticEquationComplex(int);
};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_complex()
{
  TEST_CLASS_CML_COMPLEX test_object;

  std::cout << "******** Start Testing: CML Complex functions ********\n\n";
  fprintf(fpTest, "******** Start Testing: CML Complex functions ********\n\n");

  test_object.run_tests_cml_complex();

  std::cout << "End of Testing: CML Complex functions\n\n";
  fprintf(fpTest, "End of Testing: CML Complex functions\n\n");

  return;

}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_cml_complex() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_COMPLEX::run_tests_cml_complex()
{
  test_CML_v_Cartesian2Polar(1);
  test_CML_v_Polar2Cartesian(1);
  test_CML_v_PhaseUnwrapping(1);
  test_CML_v_MultiplyComplex(1);
  test_CML_v_DivideComplex(1);
  test_CML_v_QuadraticEquationComplex(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_COMPLEX::test_CML_v_Cartesian2Polar(int doIt){
  if (doIt) {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
  #define	TEST_CML_VECTOR_CSVOUT_Cartesian2Polar_1  "test_CML_v_Cartesian2Polar_out_target.csv"

#else
    #define	TEST_CML_VECTOR_CSVOUT_Cartesian2Polar_1  "test_CML_v_Cartesian2Polar_out_msvc.csv"

#endif


    t_Complexf32 cartesian;
    t_Complexf32* const_cartesian;
    t_ComplexPolarf32 temp_polar;
    t_ComplexPolarf32* p_polar;
    t_ComplexPolarf32 expected_temp_polar;

    /* floating point tolerance */
    float32 f_Tolerance      = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut       = -1;
    csv_data_float_t p_CsvDataOut;
    uint32 dataIndex = 0;

    float32 stepSize         = 0.0f;
    float32 maxValue		 = 0.0f;
    float32 minValue		 = 0.0f;
    FILE *fp;

    /* **********************************************************************
    *                         Test case 1                                  *
    ********************************************************************** */

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Cartesian2Polar_1,"w+");
    const_cartesian = &cartesian;
    p_polar         = &temp_polar;
    minValue        = -1e6;
    maxValue        = 1e6;
    stepSize        = 1e6;


    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(cartesian.f_Real = minValue; cartesian.f_Real <= maxValue; cartesian.f_Real += stepSize)
    {
      for(cartesian.f_Imag = minValue; cartesian.f_Imag <= maxValue; cartesian.f_Imag += stepSize)
      {
        /* Call SUT */
        CML_v_Cartesian2Polar(cartesian, p_polar);
        p_CsvDataOut.value[dataIndex] = p_polar->f_Phase;
        dataIndex++; 
        p_CsvDataOut.value[dataIndex] = p_polar->f_Amplitude;
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

void TEST_CLASS_CML_COMPLEX::test_CML_v_Polar2Cartesian(int doIt){
  if (doIt) {	
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
  #define TEST_CML_VECTOR_CSVOUT_Polar2Cartesian_1  "test_CML_v_Polar2Cartesian_out_target.csv"

#else
    #define TEST_CML_VECTOR_CSVOUT_Polar2Cartesian_1  "test_CML_v_Polar2Cartesian_out_msvc.csv"

#endif

    t_ComplexPolarf32 polar;
    t_ComplexPolarf32* const_polar;
    t_Complexf32 const_cartesian;
    t_Complexf32* p_cartesian;
    t_Complexf32 expected_const_cartesian;   
    /* floating point tolerance */
    float32 f_Tolerance       = (float32)pow(10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut        = -1;
    csv_data_float_t p_CsvDataOut;
    uint32 dataIndex = 0;

    float32 stepSizeAmplitude = 0.0f;
    float32 stepSizePhase     = 0.0f;
    float32 maxValueAmplitude = 0.0f;
    float32 minValueAmplitude = 0.0f;
    float32 maxValuePhase	  = 0.0f;
    float32 minValuePhase	  = 0.0f;
    FILE *fp;


    /* **********************************************************************
    *                         Test case 1                                  *
    ********************************************************************** */

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_Polar2Cartesian_1,"w+");
    p_cartesian       = &const_cartesian;
    const_polar       = &polar;
    minValueAmplitude = -1e6;
    maxValueAmplitude = 1e6;
    stepSizeAmplitude = 1e6;
    minValuePhase     = -CML_f_two_Pi;
    maxValuePhase     = CML_f_two_Pi;
    stepSizePhase     = CML_f_Half_Pi;


    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(polar.f_Amplitude = minValueAmplitude; polar.f_Amplitude <= maxValueAmplitude; polar.f_Amplitude+=stepSizeAmplitude)
    {
      for(polar.f_Phase = minValuePhase; polar.f_Phase <= maxValuePhase; polar.f_Phase+=stepSizePhase)
      {
        /* Call SUT */
        CML_v_Polar2Cartesian(polar, p_cartesian);
        p_CsvDataOut.value[dataIndex] = p_cartesian->f_Real;
        dataIndex++; 
        p_CsvDataOut.value[dataIndex] = p_cartesian->f_Imag;
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

void TEST_CLASS_CML_COMPLEX::test_CML_v_PhaseUnwrapping(int doIt){
  if (doIt) {

    /* Test case data declarations */
#define ARRSIZE 100

#ifdef TARGET_PLATFORM
  #define	TEST_CML_VECTOR_CSVOUT_PhaseUnwrapping_1  "test_CML_v_PhaseUnwrapping_out_target.csv"

#else
    #define	TEST_CML_VECTOR_CSVOUT_PhaseUnwrapping_1  "test_CML_v_PhaseUnwrapping_out_msvc.csv"

#endif

    t_ComplexPolarf32 temp_a_values[10];
    t_ComplexPolarf32 avalues[ARRSIZE] = {0};
    t_ComplexPolarf32* a_values;
    uint32 const_u_NofChannels ;
    uint32 u_NofChannels ;
    uint32 u_NofSubarrays;
    uint32 const_u_NofSubarrays;
    t_ComplexPolarf32 expected_temp_a_values[10];

    /* floating point tolerance */
    float32 f_Tolerance      = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut       = -1;
    csv_data_float_t p_CsvDataOut;
    uint32 dataIndex = 0;

    uint32 stepSize          = 0;
    uint32 maxValue		     = 0;
    uint32 minValue		     = 0;
    FILE *fp;

    uint8 u_ChannelCounter;
    uint32 loopindex   = 0;



    /* **********************************************************************
    *                         Test case 1                                  *
    ********************************************************************** */

      /* Set global data */
      initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_PhaseUnwrapping_1,"w+");
    a_values = avalues;
    memset(avalues,0,sizeof(t_ComplexPolarf32)*ARRSIZE);
    /* Populate avalues */		
    for(loopindex = 0; loopindex < ARRSIZE; loopindex++)
    {
      avalues[loopindex].f_Phase = (float32)(loopindex);
    }
    minValue = 2;
    maxValue = 102;
    stepSize = 50;


    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(u_NofChannels = minValue; u_NofChannels < maxValue; u_NofChannels+=stepSize)
    {
      for(u_NofSubarrays = minValue; u_NofSubarrays < maxValue; u_NofSubarrays+=stepSize)
      {				
        /* Call SUT */
        CML_v_PhaseUnwrapping(a_values, u_NofChannels, u_NofSubarrays);		
        for(u_ChannelCounter = 0u; u_ChannelCounter < u_NofChannels; u_ChannelCounter++)
        {
          p_CsvDataOut.value[dataIndex] = avalues[u_ChannelCounter].f_Phase;
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

void TEST_CLASS_CML_COMPLEX::test_CML_v_MultiplyComplex(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
  #define	TEST_CML_VECTOR_CSVOUT_MultiplyComplex_1  "test_CML_v_MultiplyComplex_out_target.csv"

#else
    #define	TEST_CML_VECTOR_CSVOUT_MultiplyComplex_1  "test_CML_v_MultiplyComplex_out_msvc.csv"

#endif


    t_Complexf32 const_p_Fac1;
    t_Complexf32* p_Fac1;
    t_Complexf32 const_p_Fac2;
    t_Complexf32* p_Fac2;
    boolean b_Conj = true;
    t_Complexf32 temp_p_Prod;
    t_Complexf32* p_Prod;
    t_Complexf32 expected_temp_p_Prod;
    t_Complexf32* expected_p_Prod;

    /* floating point tolerance */
    float32 f_Tolerance      = (float32)pow (10., -1 * FLT_DIG);

    sint32 i_CsvRetOut       = -1;
    csv_data_float_t p_CsvDataOut;
    uint32 dataIndex = 0;

    float32 stepSize         = 0.0f;
    float32 maxValue		 = 0.0f;
    float32 minValue		 = 0.0f;
    FILE *fp;




    /* **********************************************************************
    *                         Test case 1                                  *
    ********************************************************************** */

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_MultiplyComplex_1,"w+");
    p_Fac1 = &const_p_Fac1;
    p_Fac2 = &const_p_Fac2;
    p_Prod = &temp_p_Prod;
    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_Fac1->f_Real = minValue; p_Fac1->f_Real <= maxValue; p_Fac1->f_Real += stepSize)
    {
      for(p_Fac1->f_Imag = minValue; p_Fac1->f_Imag <= maxValue; p_Fac1->f_Imag += stepSize)
      {
        for(p_Fac2->f_Real = minValue; p_Fac2->f_Real <= maxValue; p_Fac2->f_Real += stepSize)
        {
          for(p_Fac2->f_Imag = minValue; p_Fac2->f_Imag <= maxValue; p_Fac2->f_Imag += stepSize)
          {
            for(b_Conj = FALSE; b_Conj <= TRUE; b_Conj++)
            {
              /* Call SUT */
              CML_v_MultiplyComplex(p_Fac1, p_Fac2, b_Conj, p_Prod);
              p_CsvDataOut.value[dataIndex] = p_Prod->f_Real;
              dataIndex++; 
              p_CsvDataOut.value[dataIndex] = p_Prod->f_Imag;
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

void TEST_CLASS_CML_COMPLEX::test_CML_v_DivideComplex(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
  #define	TEST_CML_VECTOR_CSVOUT_DivideComplex_1  "test_CML_v_DivideComplex_out_target.csv"

#else
    #define	TEST_CML_VECTOR_CSVOUT_DivideComplex_1  "test_CML_v_DivideComplex_out_msvc.csv"

#endif


    t_Complexf32 const_p_Num;
    t_Complexf32* p_Num;
    t_Complexf32 const_p_Denom;
    t_Complexf32* p_Denom;
    t_Complexf32 temp_p_Quot;
    t_Complexf32* p_Quot;
    t_Complexf32 expected_temp_p_Quot;
    t_Complexf32* expected_p_Quot;

    /* floating point tolerance */
    float32 f_Tolerance      = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut       = -1;
    csv_data_float_t p_CsvDataOut;
    uint32 dataIndex = 0;

    float32 stepSize         = 0.0f;
    float32 maxValue		 = 0.0f;
    float32 minValue		 = 0.0f;
    FILE *fp;

    float32 f_Mag2;


    /* **********************************************************************
    *                         Test case 1                                  *
    ********************************************************************** */

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_DivideComplex_1,"w+");
    p_Num    = &const_p_Num;
    p_Denom  = &const_p_Denom;
    p_Quot   = &temp_p_Quot;
    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_Num->f_Real = minValue; p_Num->f_Real <= maxValue; p_Num->f_Real += stepSize)
    {
      for(p_Num->f_Imag = minValue; p_Num->f_Imag <= maxValue; p_Num->f_Imag += stepSize)
      {
        for(p_Denom->f_Real = minValue; p_Denom->f_Real <= maxValue; p_Denom->f_Real += stepSize)
        {
          for(p_Denom->f_Imag = minValue; p_Denom->f_Imag <= maxValue; p_Denom->f_Imag += stepSize)
          {
            f_Mag2 = (p_Denom->f_Real*p_Denom->f_Real) + (p_Denom->f_Imag*p_Denom->f_Imag);
            if(f_Mag2!=0) /* Check To Ensure Div By Zero Doesnt Occur! */
            {
              /* Call SUT */
              CML_v_DivideComplex(p_Num, p_Denom, p_Quot);
              p_CsvDataOut.value[dataIndex] = p_Quot->f_Real;
              dataIndex++; 
              p_CsvDataOut.value[dataIndex] = p_Quot->f_Imag;
              dataIndex++;
            }
            else
            {
              //WRITE_LOG("warning:DIV BY ZERO!", cppth_ll_minimal,false); 
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

void TEST_CLASS_CML_COMPLEX::test_CML_v_QuadraticEquationComplex(int doIt){
  if (doIt) {
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
  #define	TEST_CML_VECTOR_CSVOUT_QuadraticEquationComplex_1  "test_CML_v_QuadraticEquationComplex_out_target.csv"

#else
    #define	TEST_CML_VECTOR_CSVOUT_QuadraticEquationComplex_1  "test_CML_v_QuadraticEquationComplex_out_msvc.csv"

#endif


    t_Complexf32 const_p_p;
    t_Complexf32* p_p;
    t_Complexf32 const_p_q;
    t_Complexf32* p_q;
    t_Complexf32 temp_p_z1;
    t_Complexf32 temp_p_z2;
    t_Complexf32* p_z1;
    t_Complexf32* p_z2;
    t_Complexf32 expected_temp_p_z1;
    t_Complexf32 expected_temp_p_z2;

    /* floating point tolerance */
    float32 f_Tolerance      = (float32)pow (10., -1 * FLT_DIG);

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut       = -1;
    csv_data_float_t p_CsvDataOut;
    uint32 dataIndex = 0;

    float32 stepSize         = 0.0f;
    float32 maxValue		 = 0.0f;
    float32 minValue		 = 0.0f;
    FILE *fp;



    /* **********************************************************************
    *                         Test case 1                                  *
    ********************************************************************** */

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_QuadraticEquationComplex_1,"w+");
    p_p = &const_p_p;
    p_q = &const_p_q;
    p_z1 = &temp_p_z1;
    p_z2 = &temp_p_z2;
    minValue = -1e6;
    maxValue = 1e6;
    stepSize = 1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    for(p_p->f_Real = minValue; p_p->f_Real <= maxValue; p_p->f_Real+=stepSize)
    {
      for(p_p->f_Imag = minValue; p_p->f_Imag <= maxValue; p_p->f_Imag+=stepSize)
      {
        for(p_q->f_Real = minValue; p_q->f_Real <= maxValue; p_q->f_Real+=stepSize)
        {
          for(p_q->f_Imag = minValue; p_q->f_Imag <= maxValue; p_q->f_Imag+=stepSize)
          {
            /* Call SUT */
            CML_v_QuadraticEquationComplex(p_p, p_q, p_z1, p_z2);
            p_CsvDataOut.value[dataIndex] = p_z1->f_Real;
            dataIndex++; 
            p_CsvDataOut.value[dataIndex] = p_z1->f_Imag;
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = p_z2->f_Real;
            dataIndex++; 
            p_CsvDataOut.value[dataIndex] = p_z2->f_Imag;
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


/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
