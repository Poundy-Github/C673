/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_interpol.cpp
*    Author: uidr5428
*    Generated on: 08-Sep-2016 15:43:28
*    Generated from: test_cml_interpol.c
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

/* Test Log file */
extern FILE *fpTest;

#ifdef ENABLE_PROFILER


#endif

/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0
#define DELIMITER ','

#include "csv_parser.h"



#ifndef LINKED_LIST_PARSER
extern float data_log_buffer[1000000];
#endif




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
class TEST_CLASS_CML_INTERPOL
{
public:
  /* Prototypes for test functions */
  void run_tests_cml_interpol();
  void test_CML_f_LinearInterpolation(int);
  void test_CML_f_BoundedLinInterpol(int);
  void test_CML_f_BoundedLinInterpol2(int);
  void test_CML_f_BoundedLinInterpol3(int);
  void test_CML_f_BoundedLinInterpol4(int);
  void test_CML_f_BoundedLinInterpol5(int);
  void test_CML_f_CalculatePolygonValue(int);
  void test_CML_CalculateCubicSplineClamped(int);
};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_interpol(void)
{
  TEST_CLASS_CML_INTERPOL test_object;

  std::cout << "******** Start Testing: CML Interpolation functions ********\n\n";
  fprintf(fpTest, "******** Start Testing: CML Interpolation functions ********\n\n");

  test_object.run_tests_cml_interpol();

  std::cout << "End of Testing: CML Interpolation functions\n\n";
  fprintf(fpTest, "End of Testing: CML Interpolation functions\n\n");

  return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests_cml_interpol() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_INTERPOL::run_tests_cml_interpol()
{
  test_CML_f_LinearInterpolation(1);
  test_CML_f_BoundedLinInterpol(1);
  test_CML_f_CalculatePolygonValue(1);
  test_CML_f_BoundedLinInterpol3(1);
  test_CML_f_BoundedLinInterpol4(1);
  test_CML_f_BoundedLinInterpol5(1);
  test_CML_f_BoundedLinInterpol2(1);
  test_CML_CalculateCubicSplineClamped(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_INTERPOL::test_CML_f_LinearInterpolation(int doIt)
{
  if (doIt) 
  {
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;


    /* Test case data declarations */
    float32 f_X1;
    float32 f_Y1;
    float32 f_X2;
    float32 f_Y2;
    float32 f_XPos;

    float32 tolerance = 0.00001f;
    float32 stepSize         = 0.0f;
    float32 maxValue		 = 0.0f;
    float32 minValue		 = 0.0f;
    FILE *fp;

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM

#define TEST_CML_VECTOR_CSVOUT_CML_f_LinearInterpolation_TestCase_1  "test_CML_f_LinearInterpolation_out_target.csv"

#else

#define TEST_CML_VECTOR_CSVOUT_CML_f_LinearInterpolation_TestCase_1  "test_CML_f_LinearInterpolation_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_LinearInterpolation_TestCase_1,"w+");
    stepSize = 1e6;
    maxValue = 1e6;
    minValue = -1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);
	
    PRINT_TEST_CASE(__FUNCTION__)

    for(f_X1 = minValue; f_X1 <= maxValue; f_X1+=stepSize)
    {
      for(f_Y1 = minValue; f_Y1 <= maxValue; f_Y1+=stepSize)
      {
        for(f_X2 = minValue; f_X2 <= maxValue; f_X2+=stepSize)
        {
          for(f_Y2 = minValue; f_Y2 <= maxValue; f_Y2+=stepSize)
          {
            for(f_XPos = minValue; f_XPos <= maxValue; f_XPos+=stepSize)
            {
              GET_CLOCK()
              /* Call SUT */
              p_CsvDataOut.value[dataIndex] = CML_f_LinearInterpolation(f_X1, f_Y1, f_X2, f_Y2, f_XPos);
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

void TEST_CLASS_CML_INTERPOL::test_CML_f_BoundedLinInterpol2(int doIt){
  if (doIt){
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut       = -1;

    float32 f_IVal;
    float32 f_Imin;
    float32 f_Imax;
    float32 f_Omin;
    float32 f_Omax;

    float32 tolerance = 0.00001f;
    float32 stepSize  = 0.0001f;
    float32 maxValue  = FLT_MAX;
    float32 minValue  = FLT_MIN;
    FILE *fp;		

    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol2_TestCase_1  "test_CML_f_BoundedLinInterpol2_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol2_TestCase_1  "test_CML_f_BoundedLinInterpol2_out_msvc.csv"

#endif



    /* Set global data */
    initialise_global_data();		

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol2_TestCase_1,"w+");
    stepSize  = 1e6;
    maxValue  = 1e6;
    minValue  = -1e6;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

	PRINT_TEST_CASE(__FUNCTION__)
    for(f_IVal = minValue; f_IVal <= maxValue; f_IVal+=stepSize)
    {
      for(f_Imin = minValue; f_Imin <= maxValue; f_Imin+=stepSize)
      {
        for(f_Imax = minValue; f_Imax <= maxValue; f_Imax+=stepSize)
        {
          for(f_Omin = minValue; f_Omin <= maxValue; f_Omin+=stepSize)
          {
            for(f_Omax = minValue; f_Omax <= maxValue; f_Omax+=stepSize)
            {
			  GET_CLOCK()
              /* Call SUT */
              p_CsvDataOut.value[dataIndex] = CML_f_BoundedLinInterpol2(f_IVal, f_Imin, f_Imax, f_Omin, f_Omax);	
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

void TEST_CLASS_CML_INTERPOL::test_CML_f_BoundedLinInterpol5(int doIt){
  if (doIt){
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    Vector2_i32_t Point1;
    Vector2_i32_t Point2;
    float32 f_In;

    float32 test_vector_input[5];
    float32 tolerance       = 0.00001f;
    signed long slStepSize  = 0;
    float32 fStepSize		= 0.0f;
    signed long slmaxValue  = 0;
    signed long slminValue  = 0;
    float32 fmaxValue       = 0.0f;
    float32 fminValue       = 0.0f;
    FILE *fp;		
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol5_TestCase_1  "test_CML_f_BoundedLinInterpol5_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol5_TestCase_1  "test_CML_f_BoundedLinInterpol5_out_msvc.csv"

#endif

    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol5_TestCase_1,"w+");
    slStepSize = 100;
    fStepSize  = 100.0f;
    slmaxValue = 100;
    slminValue = -100;
    fmaxValue  = 200.0f;
    fminValue  = -200.0f;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    PRINT_TEST_CASE(__FUNCTION__)
    for(Point1.nXDist = slminValue; Point1.nXDist <= slmaxValue; Point1.nXDist+=slStepSize)
    {
      for(Point1.nYDist = slminValue; Point1.nYDist <= slmaxValue; Point1.nYDist+=slStepSize)
      {
        for(Point2.nXDist = slminValue; Point2.nXDist <= slmaxValue; Point2.nXDist+=slStepSize)
        {
          for(Point2.nYDist = slminValue; Point2.nYDist <= slmaxValue; Point2.nYDist+=slStepSize)
          {
            for(f_In = fminValue; f_In <= fmaxValue; f_In+=fStepSize)
            {
              GET_CLOCK()
              /* Call SUT */
              p_CsvDataOut.value[dataIndex] = CML_f_BoundedLinInterpol5(Point1, Point2, f_In);
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

void TEST_CLASS_CML_INTERPOL::test_CML_f_BoundedLinInterpol4(int doIt){
  if (doIt){
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    Vector2_f32_t Point1;
    Vector2_f32_t Point2;
    float32 f_In;

    float32 test_vector_input[5];
    float32 tolerance = 0.00001f;
    float32 stepSize  = 0.0f;
    float32 maxValue  = 0.0f;
    float32 minValue  = 0.0f;
    FILE *fp;		
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol4_TestCase_1  "test_CML_f_BoundedLinInterpol4_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol4_TestCase_1  "test_CML_f_BoundedLinInterpol4_out_msvc.csv"

#endif





    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol4_TestCase_1,"w+");
    stepSize  = 1e6;
    maxValue  = 1e6;
    minValue  = -1e6;
    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    PRINT_TEST_CASE(__FUNCTION__)
    for(Point1.fXDist = minValue; Point1.fXDist <= maxValue; Point1.fXDist+=stepSize)
    {
      for(Point1.fYDist = minValue; Point1.fYDist <= maxValue; Point1.fYDist+=stepSize)
      {
        for(Point2.fXDist = minValue; Point2.fXDist <= maxValue; Point2.fXDist+=stepSize)
        {
          for(Point2.fYDist = minValue; Point2.fYDist <= maxValue; Point2.fYDist+=stepSize)
          {
            for(f_In = minValue; f_In <= maxValue; f_In+=stepSize)
            {
              GET_CLOCK()
              /* Call SUT */
              p_CsvDataOut.value[dataIndex] = CML_f_BoundedLinInterpol4(Point1, Point2, f_In);
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

void TEST_CLASS_CML_INTERPOL::test_CML_f_BoundedLinInterpol3(int doIt){
  if (doIt){

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    CML_t_Point2D Point1;
    CML_t_Point2D Point2;
    float32 f_In;
    float32 expected_returnValue;
    float32 returnValue;
    float32 test_vector_input[5];
    float32 tolerance = 0.00001f;
    float32 stepSize  = 0.0f;
    float32 maxValue  = 0.0f;
    float32 minValue  = 0.0f;
    FILE *fp;		
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol3_TestCase_1  "test_CML_f_BoundedLinInterpol3_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol3_TestCase_1  "test_CML_f_BoundedLinInterpol3_out_msvc.csv"

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol3_TestCase_1,"w+");
    stepSize  = 1e6;
    maxValue  = 1e6;
    minValue  = -1e6;
    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);
    PRINT_TEST_CASE(__FUNCTION__)
    for(Point1.X = minValue; Point1.X <= maxValue; Point1.X+=stepSize)
    {
      for(Point1.Y = minValue; Point1.Y <= maxValue; Point1.Y+=stepSize)
      {
        for(Point2.X = minValue; Point2.X <= maxValue; Point2.X+=stepSize)
        {
          for(Point2.Y = minValue; Point2.Y <= maxValue; Point2.Y+=stepSize)
          {
            for(f_In = minValue; f_In <= maxValue; f_In+=stepSize)
            {
              /* Call SUT */
              GET_CLOCK()
              p_CsvDataOut.value[dataIndex] = CML_f_BoundedLinInterpol3(Point1, Point2, f_In);
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

void TEST_CLASS_CML_INTERPOL::test_CML_f_CalculatePolygonValue(int doIt){
  if (doIt){
    /* Test case data declarations */	
#define ARRSIZE1 100

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    sint32 s_NrOfTableRows;
    CML_t_Vector2D a_Table[ARRSIZE1] = {0};
    float32 f_InputValue;

    float32 test_vector_input[11]={0};
    float32 tolerance = 0.0001f;
    float32 stepSize  = 0.0f;
    float32 maxValue  = 0.0f;
    float32 minValue  = 0.0f;
    FILE *fp;		
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

    uint32 loopindex  = 0;

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_f_CalculatePolygonValue_TestCase_1  "test_CML_f_CalculatePolygonValue_out_target.csv"		

#else
#define TEST_CML_VECTOR_CSVOUT_CML_f_CalculatePolygonValue_TestCase_1  "test_CML_f_CalculatePolygonValue_out_msvc.csv"		

#endif


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_CalculatePolygonValue_TestCase_1,"w+");
    stepSize  = 1e6;
    maxValue  = 1e6;
    minValue  = -1e6;
    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

    memset(a_Table,0,sizeof(CML_t_Vector2D));
    for(loopindex = 0; loopindex < ARRSIZE1; loopindex++)
    {
      a_Table[loopindex].f0 = (float32)loopindex;
      a_Table[loopindex].f1 = (float32)loopindex;
    }
    a_Table[ARRSIZE1-1].f0 = maxValue;	
	    PRINT_TEST_CASE(__FUNCTION__)
    /* s_NrOfTableRows : 1,5,9 */
    for(s_NrOfTableRows = 1; s_NrOfTableRows <= 9; s_NrOfTableRows+=4)
    {
      for(f_InputValue = minValue; f_InputValue <= maxValue; f_InputValue+=stepSize)
      {			
        /* Call SUT */
		  GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_CalculatePolygonValue(s_NrOfTableRows, a_Table, f_InputValue);
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

void TEST_CLASS_CML_INTERPOL::test_CML_CalculateCubicSplineClamped(int doIt){
  if (doIt) {
    /* Test case data declarations */	
#define ARRSIZE 100

#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_CalculateCubicSplineClamped_1   "test_CML_CalculateCubicSplineClamped_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_CalculateCubicSplineClamped_1   "test_CML_CalculateCubicSplineClamped_out_msvc.csv"

#endif


    uint32 u_NrOfShapePoints;
    Vector2_f32_t ta_ShapePointTable[6];
    float32 f_SlopeStart;
    float32 f_SlopeEnd;
    float32* a_BMatrix ;
    float32* a_BMatrixInv ;
    float32* a_Temp;
    float32* a_YVector;
    float32* a_BInvXYVec ;
    float32* a_ParaA ;
    float32* a_ParaB;
    float32* a_ParaC;
    float32* a_ParaD ;
    boolean* a_SegmentSplineValid;	


    Vector2_f32_t* a_ShapePointTable;
    /* floating point tolerance */
    float32 f_Tolerance=0.01;

    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    float32 fstepSize  = 0.0001f;
    float32 fmaxValue  = FLT_MAX;
    float32 fminValue  = FLT_MIN;
    uint32 umaxValue  = 100;
    uint32 uminValue  = 0;
    uint32 ustepSize  = 0;
    FILE *fp;		
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;

	void *temp_buffers = (void *)(&(data_log_buffer[200000]));

	/*
	In Memory the arrays are placed one after the other
	aShapePointTable -> aBMatrix -> aBMatrixInv -> aYVector -> aTemp -> aBInvXYVec -> 
	aParaA -> aParaB -> aParaC -> aParaD -> aSegmentSplineValid
	*/
	Vector2_f32_t *aShapePointTable = (Vector2_f32_t *)temp_buffers;
	float32 *aBMatrix               = (float *)(aShapePointTable + (sizeof(Vector2_f32_t)*ARRSIZE));
    float32 *aBMatrixInv            = (float *)(aBMatrix + (sizeof(float)*ARRSIZE));
    float32 *aYVector				= (float *)(aBMatrixInv + (sizeof(float)*ARRSIZE));
    float32 *aTemp					= (float *)(aYVector + (sizeof(float)*ARRSIZE));
    float32 *aBInvXYVec				= (float *)(aTemp + (sizeof(float)*ARRSIZE));
    float32 *aParaA					= (float *)(aBInvXYVec + (sizeof(float)*ARRSIZE));
    float32 *aParaB					= (float *)(aParaA + (sizeof(float)*ARRSIZE));
    float32 *aParaC					= (float *)(aParaB + (sizeof(float)*ARRSIZE));
    float32 *aParaD					= (float *)(aParaC + (sizeof(float)*ARRSIZE));
    boolean *aSegmentSplineValid    = (boolean *)(aParaD + (sizeof(float)*ARRSIZE));
	uint32 aShapePointTableIndex    = 0;
    uint32 aBMatrixIndex    = 0;
    uint32 aBMatrixInvIndex = 0;
    uint32 aTempIndex       = 0;
    uint32 aYVectorIndex    = 0;
    uint32 aBInvXYVecIndex  = 0;
    uint32 aParaAIndex      = 0;
    uint32 aParaBIndex      = 0;
    uint32 aParaCIndex      = 0;
    uint32 aParaDIndex      = 0;
    uint32 loopindex		= 0;
    float32 returnValue;

    /* Set global data */
    initialise_global_data();

    a_ShapePointTable = aShapePointTable;
    a_BMatrix         = aBMatrix;
    a_BMatrixInv      = aBMatrixInv;
    a_YVector         = aYVector;
    a_BInvXYVec       = aBInvXYVec;
    a_ParaA           = aParaA;
    a_ParaB           = aParaB;
    a_ParaC           = aParaC;
    a_ParaD           = aParaD;
    a_Temp			  = aTemp;
    a_SegmentSplineValid = aSegmentSplineValid;
    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_CalculateCubicSplineClamped_1, "w+");
    fstepSize  = 1e6;
    fmaxValue  = 1e6;
    fminValue  = -1e6;
    umaxValue  = 10;
    uminValue  = 2;
    ustepSize  = 2;

    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);


    for(aShapePointTableIndex = uminValue; aShapePointTableIndex < umaxValue; aShapePointTableIndex++)
    {
      aShapePointTable[aShapePointTableIndex].fXDist = (float32)aShapePointTableIndex;
      aShapePointTable[aShapePointTableIndex].fYDist = (float32)aShapePointTableIndex;
    }
	PRINT_TEST_CASE(__FUNCTION__)
    for(u_NrOfShapePoints = 1; u_NrOfShapePoints <= umaxValue; u_NrOfShapePoints+=ustepSize)
    {				
      for(aTempIndex = 0; aTempIndex < (u_NrOfShapePoints*u_NrOfShapePoints); aTempIndex++)
      {
        aTemp[aTempIndex] = (float32)aTempIndex;
      }

      for(f_SlopeStart = fminValue; f_SlopeStart <= fmaxValue; f_SlopeStart+=fstepSize)
      {
        for(f_SlopeEnd = fminValue; f_SlopeEnd <= fmaxValue; f_SlopeEnd+=fstepSize)
        {
          /* Call SUT */
			GET_CLOCK()
          returnValue = CML_CalculateCubicSplineClamped(u_NrOfShapePoints, a_ShapePointTable, f_SlopeStart, f_SlopeEnd, a_BMatrix, a_BMatrixInv, a_Temp, a_YVector, a_BInvXYVec, a_ParaA, a_ParaB, a_ParaC, a_ParaD, a_SegmentSplineValid);
		  CALCULATE_CYLES(__FUNCTION__, 1)
          for(loopindex = 0u; loopindex < (u_NrOfShapePoints - 1u); loopindex++)
          {
            p_CsvDataOut.value[dataIndex] = a_ParaA[loopindex];
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = a_ParaB[loopindex];
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = a_ParaC[loopindex];
            dataIndex++;
            p_CsvDataOut.value[dataIndex] = a_ParaD[loopindex];
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

void TEST_CLASS_CML_INTERPOL::test_CML_f_BoundedLinInterpol(int doIt){
  if (doIt){
    /* Test case data declarations */
#ifdef TARGET_PLATFORM
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol_1    "test_CML_f_BoundedLinInterpol_out_target.csv"

#else
#define TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol_1    "test_CML_f_BoundedLinInterpol_out_msvc.csv"

#endif


    CML_t_LinFunctionArgs temp_p_Params;
    CML_t_LinFunctionArgs* p_Params = &temp_p_Params;
    float32 f_Value ;



    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;

    float32 stepSize  = 0.0f;
    float32 maxValue  = 0.0f;
    float32 minValue  = 0.0f;
    FILE *fp;		
    csv_data_float_t p_CsvDataOut;
    int dataIndex = 0;


    /* Set global data */
    initialise_global_data();

    fp = fopen(TEST_CML_VECTOR_CSVOUT_CML_f_BoundedLinInterpol_1,"w+");
    stepSize = 1e6;
    maxValue = 1e6;
    minValue = -1e6;
    p_CsvDataOut.value = data_log_buffer;
    p_CsvDataOut.len = sizeof(float32);

	PRINT_TEST_CASE(__FUNCTION__)
    for(p_Params->dAmax = minValue; p_Params->dAmax <= maxValue; p_Params->dAmax+=stepSize)
    {
      for(p_Params->dAmin = minValue; p_Params->dAmin <= maxValue; p_Params->dAmin+=stepSize)
      {
        for(p_Params->dB = minValue; p_Params->dB <= maxValue; p_Params->dB+=stepSize)
        {
          for(p_Params->dM = minValue; p_Params->dM <= maxValue; p_Params->dM+=stepSize)
          {
            for(f_Value = minValue; f_Value <= maxValue; f_Value+=stepSize)
            {
              /* Call SUT */
				GET_CLOCK()
              p_CsvDataOut.value[dataIndex] = CML_f_BoundedLinInterpol(p_Params, f_Value);
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


/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
