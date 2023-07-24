/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_bayes.cpp
*    Author: uidr5428
*    Generated on: 30-Aug-2016 15:43:28
*    Generated from: test_cml_bayes.c
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
class TEST_CLASS_CML_BAYES
{
public:
  /* Prototypes for test functions */
  void run_tests_cml_bayes();
  void test_CML_Bayes2(int);
  void test_CML_Bayes3(int);
  void test_CML_Bayes4(int);
  void test_CML_Bayes5(int);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_bayes(void)
{
  TEST_CLASS_CML_BAYES test_object;

  std::cout << "******** Start Testing: CML Bayes functions ********\n\n";
  fprintf(fpTest, "******** Start Testing: CML Bayes functions ********\n\n");

  test_object.run_tests_cml_bayes();

  std::cout << "End of Testing: CML Bayes functions\n\n";
  fprintf(fpTest, "End of Testing: CML Bayes functions\n\n");

  return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_cml_bayes() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_BAYES::run_tests_cml_bayes()
{ 
  test_CML_Bayes2(1);
  test_CML_Bayes3(1);
  test_CML_Bayes4(1);
  test_CML_Bayes5(1);
}

/*****************************************************************************/
/*                           Test Cases                                      */
/*****************************************************************************/
void TEST_CLASS_CML_BAYES::test_CML_Bayes2(int doIt)
{
  if (doIt) {
  /* Test case data declarations */
  percentage_t u_ProbabilityA        = 0;
  percentage_t u_ProbabilityB       = 0;
  percentage_t a_CPT[4]             = {0};

  /* CSV parser return value for result values file */
  sint32 i_CsvRetOut                = -1;

  FILE *fp;
  percentage_t minValue			  = 0;
  percentage_t maxValue			  = 0;
  percentage_t stepSize			  = 0;
  
  csv_data_float_t p_CsvDataOut;

  int dataIndex = 0;

  /* Macros */
#ifdef TARGET_PLATFORM
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes2_1  "test_CML_Bayes2_out_target.csv"

#else
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes2_1  "test_CML_Bayes2_out_msvc.csv"

#endif
  
  /* **********************************************************************
   *                         Test case 1                                  *
   ********************************************************************** */

      /* Set global data */
      initialise_global_data();
      
      fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_Bayes2_1, "w+");
      minValue = 0;
      maxValue = 150;
      stepSize = 50;

      p_CsvDataOut.value = data_log_buffer;
      p_CsvDataOut.len = sizeof(float32);
      

      for(u_ProbabilityA = minValue; u_ProbabilityA <= maxValue; u_ProbabilityA+=stepSize)
      {
        for(u_ProbabilityB = minValue; u_ProbabilityB <= maxValue; u_ProbabilityB+=stepSize)
        {
          for(a_CPT[0] = minValue; a_CPT[0] <= maxValue; (a_CPT[0])+=stepSize)
          {						
            for(a_CPT[1] = minValue; a_CPT[1] <= maxValue; (a_CPT[1])+=stepSize)
            {
              for(a_CPT[2] = minValue; a_CPT[2] <= maxValue; (a_CPT[2])+=stepSize)
              {
                for(a_CPT[3] = minValue; a_CPT[3] <= maxValue; (a_CPT[3])+=stepSize)
                {	
                  /* Call SUT */
                  p_CsvDataOut.value[dataIndex] = CML_Bayes2(u_ProbabilityA, u_ProbabilityB, a_CPT);
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

void TEST_CLASS_CML_BAYES::test_CML_Bayes3(int doIt){
if (doIt){
  /* Test case data declarations */
  percentage_t u_ProbabilityA       = 0;
  percentage_t u_ProbabilityB       = 0;
  percentage_t u_ProbabilityC       = 0;
  percentage_t a_CPT[8]             = {0};


  /* CSV parser return value for result values file */
  sint32 i_CsvRetOut                = -1;

  FILE *fp;
  percentage_t minValue			  = 0;
  percentage_t maxValue			  = 0;
  percentage_t stepSize			  = 0;	
  percentage_t loopindex			  = 0;

  csv_data_float_t p_CsvDataOut;

  int dataIndex = 0;

  /* Macros */
#ifdef TARGET_PLATFORM
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes3_1  "test_CML_Bayes3_out_target.csv"

#else
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes3_1  "test_CML_Bayes3_out_msvc.csv"

#endif


  /* **********************************************************************
   *                         Test case 1                                  *
   ********************************************************************** */
      /* Set global data */
      initialise_global_data();
      
      fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_Bayes3_1, "w+");
      minValue = 0;
      maxValue = 150;
      stepSize = 50;

      p_CsvDataOut.value = data_log_buffer;
      p_CsvDataOut.len = sizeof(float32);

      for(loopindex = 0; loopindex < CML_BAYES3_CPT_SIZE; loopindex++)
      {
        a_CPT[loopindex] = 50;
      }
      
      for(u_ProbabilityA = minValue; u_ProbabilityA <= maxValue; u_ProbabilityA+=stepSize)
      {
        for(u_ProbabilityB = minValue; u_ProbabilityB <= maxValue; u_ProbabilityB+=stepSize)
        {
          for(u_ProbabilityC = minValue; u_ProbabilityC <= maxValue; u_ProbabilityC+=stepSize)
          {
            /* Call SUT */
            p_CsvDataOut.value[dataIndex] = CML_Bayes3(u_ProbabilityA, u_ProbabilityB, u_ProbabilityC, a_CPT);
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

void TEST_CLASS_CML_BAYES::test_CML_Bayes4(int doIt){
if (doIt){
  /* Test case data declarations */
  percentage_t u_ProbabilityA       = 0;
  percentage_t u_ProbabilityB       = 0;
  percentage_t u_ProbabilityC       = 0;
  percentage_t u_ProbabilityD       = 0;
  percentage_t a_CPT[16]            = {0};


  /* CSV parser return value for result values file */
  sint32 i_CsvRetOut                = -1;

  FILE *fp;

  percentage_t minValue			  = 0;
  percentage_t maxValue			  = 0;
  percentage_t stepSize			  = 0;
  percentage_t loopindex			  = 0;

  csv_data_float_t p_CsvDataOut;

  int dataIndex = 0;

#ifdef TARGET_PLATFORM
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes4_1   "test__CML_Bayes4_out_target.csv"

#else
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes4_1   "test_CML_Bayes4_out_msvc.csv"

#endif


  /* **********************************************************************
   *                         Test case 1                                  *
   ********************************************************************** */
  
      /* Set global data */
      initialise_global_data();
      
      fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_Bayes4_1, "w+");
      minValue = 0;
      maxValue = 100;
      stepSize = 50;

      p_CsvDataOut.value = data_log_buffer;
      p_CsvDataOut.len = sizeof(float32);

      for(loopindex = 0; loopindex < CML_BAYES4_CPT_SIZE; loopindex++)
      {
        a_CPT[loopindex] = 47;
      }
      
      for(u_ProbabilityA = minValue; u_ProbabilityA <= maxValue; u_ProbabilityA+=stepSize)
      {
        for(u_ProbabilityB = minValue; u_ProbabilityB <= maxValue; u_ProbabilityB+=stepSize)
        {
          for(u_ProbabilityC = minValue; u_ProbabilityC <= maxValue; u_ProbabilityC+=stepSize)
          {
            for(u_ProbabilityD = minValue; u_ProbabilityD <= maxValue; u_ProbabilityD+=stepSize)
            {
              /* Call SUT */
              p_CsvDataOut.value[dataIndex] = CML_Bayes4(u_ProbabilityA, u_ProbabilityB, u_ProbabilityC, u_ProbabilityD, a_CPT);
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

void TEST_CLASS_CML_BAYES::test_CML_Bayes5(int doIt){
if (doIt){
  /* Test case data declarations */
  percentage_t u_ProbabilityA       = 0;
  percentage_t u_ProbabilityB       = 0;
  percentage_t u_ProbabilityC       = 0;
  percentage_t u_ProbabilityD       = 0;
  percentage_t u_ProbabilityE       = 0;
  percentage_t a_CPT[32]            = {0};



  /* CSV parser return value for result values file */
  sint32 i_CsvRetOut                = -1;

  FILE *fp;
  
  percentage_t minValue       = 0;
  percentage_t maxValue       = 0;
  percentage_t stepSize       = 0;
  percentage_t loopindex      = 0;

  csv_data_float_t p_CsvDataOut;

  int dataIndex = 0;

  /* Macros */
#ifdef TARGET_PLATFORM
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes5_1  "test_CML_Bayes5_out_target.csv"

#else
  #define TEST_CML_VECTOR_CSVOUT_CML_Bayes5_1  "test_CML_Bayes5_out_msvc.csv"

#endif


 
  /* **********************************************************************
   *                         Test case 1                                  *
   ********************************************************************** */
      /* Set global data */
      initialise_global_data();
      
      fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_Bayes5_1, "w+");
      minValue = 67;
      maxValue = 67;
      stepSize = 1;

      p_CsvDataOut.value = data_log_buffer;
      p_CsvDataOut.len = sizeof(float32);

      for(loopindex = 0; loopindex < CML_BAYES5_CPT_SIZE; loopindex++)
      {
        a_CPT[loopindex] = 13;
      }
      
      for(u_ProbabilityA = minValue; u_ProbabilityA <= maxValue; u_ProbabilityA+=stepSize)
      {
        for(u_ProbabilityB = minValue; u_ProbabilityB <= maxValue; u_ProbabilityB+=stepSize)
        {
          for(u_ProbabilityC = minValue; u_ProbabilityC <= maxValue; u_ProbabilityC+=stepSize)
          {
            for(u_ProbabilityD = minValue; u_ProbabilityD <= maxValue; u_ProbabilityD+=stepSize)
            {
              for(u_ProbabilityE = minValue; u_ProbabilityE <= maxValue; u_ProbabilityE+=stepSize)
              {								
                /* Call SUT */
                p_CsvDataOut.value[dataIndex] = CML_Bayes5(u_ProbabilityA, u_ProbabilityB, u_ProbabilityC,u_ProbabilityD, u_ProbabilityE, a_CPT);
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

/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
