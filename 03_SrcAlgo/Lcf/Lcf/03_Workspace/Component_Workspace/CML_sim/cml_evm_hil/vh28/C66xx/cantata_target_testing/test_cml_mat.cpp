/*****************************************************************************/
/*                            CML Target Test Script                         */
/*****************************************************************************/
/*
*    Filename: test_cml_mat.cpp
*    Author: uidp1547
*    Generated on: 17-Sep-2016 15:43:28
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
                        fprintf(fpTest,"\n\n Function %s\n",(name));\
                        }
                        

#define GET_CLOCK()  for(uint8 k = 0; k < 5; ++k){\
						start_clock = get_clock();\

#define CALCULATE_CYLES(name, test_case_num)  {\
        stop_clock = get_clock();\
        fprintf(fpTest, "%s---> Test case %d", (name), (test_case_num));\
        total_cycles = stop_clock - start_clock - overhead;\
        check__PrintValue_to_File(total_cycles, fpTest);\
        fprintf(fpTest, "\n");\
		}}

uint32 Cut_Loop = 100;

#define CUT_LOOP() {\
		if(!(--::Cut_Loop)){\
			::Cut_Loop = 100;\
			break;\
		}\
		}
#else

#define PRINT_TEST_CASE(test_case_num)
#define GET_CLOCK()
#define CALCULATE_CYLES(name,test_case_num)
#define CUT_LOOP()

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

#define MIN_VAL 1
#define MAX_VAL 10
#define STEP_SIZE_VAL 1

/* Global Functions */
extern float32 CML_f_AbsGen(float32 x);
extern float32 CML_f_MinGen(float32 x, float32 y);
extern float32 CML_f_MaxGen(float32 x, float32 y);
extern float32 CML_f_Round2FloatGen(float32 x);
extern sint32 CML_s_Round2IntGen(float32 x);
extern uint32 CML_u_Round2UintGen(float32 x);
extern float32 CML_f_Floor2FloatGen(float32 f_x);
extern float32 CML_f_Ceil2FloatGen(float32 f_x);
extern float32 CML_f_MultAddGen(float32 a, float32 b, float32 d);
extern sint32 CML_f_Sign(float32 f_Input);
extern float32 CML_f_PowToDB(float32 f_ratio);
extern float32 CML_f_MagToDB(float32 f_ratio);
extern CML_t_Matrix CML_a_InitMatrixHeader(uint32 ColNr, uint32 RowNr, float32* p_f_MtrxData);
extern CML_t_TrafoMatrix2D CML_TrafoMatrix2DInvert(CML_t_TrafoMatrix2D MatrixA);
extern CML_t_TrafoMatrix2D CML_TrafoMatrix2DMult(CML_t_TrafoMatrix2D MatrixA, CML_t_TrafoMatrix2D MatrixB);
extern void CML_v_TransformPosition2D(const CML_t_TrafoMatrix2D* p_Matrix, float32* p_DistX, float32* p_DistY);
extern float32 CML_f_TransformXPosition2D(const CML_t_TrafoMatrix2D* p_Matrix, float32 f_DistX, float32 f_DistY);
extern float32 CML_f_TransformYPosition2D(const CML_t_TrafoMatrix2D* p_Matrix, float32 f_DistX, float32 f_DistY);
extern CML_t_TrafoMatrix2D CML_GetTrafoMatrixByAngle(float32 f_Angle);
extern CML_t_TrafoMatrix2D CML_GetTrafoMatrixByDisplacement(float32 f_XDisplacement, float32 f_YDisplacement);
extern uint8 CML_u_MatrixCopy(const float32* a_MatrixA, float32* a_MatrixCpy, uint8 u_dim_Ax, uint8 u_dim_Ay);
extern uint8 CML_u_MatrixTranspose(const float32* a_MatrixA, float32* a_ATranspose, uint8 u_dim_Ax, uint8 u_dim_Ay);
extern uint8 CML_u_MatrixMultiplication(const float32* a_MatrixA, const float32* a_MatrixB, float32* a_AxB, uint8 u_dim_Ax, uint8 u_dim_Ay, uint8 u_dim_Bx);
extern uint8 CML_u_MatrixInversion(const float32* a_MatrixA, float32* a_tempMatrix, float32* a_InverseA, uint8 u_dim_xy);
extern uint8 CML_u_MatrixAddition(const float32* a_MatrixA, const float32* a_MatrixB, float32* a_AplusB[], uint8 u_dim_x, uint8 u_dim_y);
extern uint8 CML_u_MatrixSubtraction(const float32* a_MatrixA, const float32* a_MatrixB, float32* a_AminusB, uint8 u_dim_x, uint8 u_dim_y);
float32 CML_f_fastlog10(float32 x);
void GDBsincos(float32 x, float32* s, float32* c);

/* Global data */
/* None */

/* Expected variables for global data */
/* None */

/* This function initialises global data to default values. This function       */
/* is called by every test case so must not contain test case specific settings */
static void initialise_global_data(){
    //TEST_SCRIPT_WARNING("Verify initialise_global_data()\n");
    /* No global data */
}

/* This function copies the global data settings into expected variables for */
/* use in check_global_data(). It is called by every test case so must not   */
/* contain test case specific settings.                                      */
static void initialise_expected_global_data(){
    //TEST_SCRIPT_WARNING("Verify initialise_expected_global_data()\n");
    /* No global data */
}

/* This function checks global data against the expected values. */
static void check_global_data(){
    //TEST_SCRIPT_WARNING("Verify check_global_data()\n");
    /* No global data */
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_CML_MAT
{
public:
  /* Prototypes for test functions */
  void run_tests_cml_mat();
  void test_CML_TrafoMatrix2DInvert(int);
  void test_CML_TrafoMatrix2DMult(int);
  void test_CML_v_TransformPosition2D(int);
  void test_CML_f_TransformXPosition2D(int);
  void test_CML_f_TransformYPosition2D(int);
  void test_CML_GetTrafoMatrixByAngle(int);
  void test_CML_GetTrafoMatrixByDisplacement(int);
  void test_CML_u_MatrixCopy(int);
  void test_CML_u_MatrixTranspose(int);
  void test_CML_u_MatrixMultiplication(int);
  void test_CML_u_MatrixInversion(int);
  void test_CML_u_MatrixAddition(int);
  void test_CML_u_MatrixSubtraction(int);
	void test_memset_s(int);
	void test_memcpy_s(int);
	void test_CML_memcpy_aligned(int);
	void test_CML_memset_aligned(int);
};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_mat(void)
{
  TEST_CLASS_CML_MAT test_object;

  std::cout << "******** Start Testing: CML Matrix functions using linear arrays ********\n\n";
  fprintf(fpTest, "******** Start Testing: CML Matrix functions using linear arrays ********\n\n");

  test_object.run_tests_cml_mat();

  std::cout << "End of Testing: CML Matrix functions using linear arrays\n\n";
  fprintf(fpTest, "\nEnd of Testing: CML Matrix functions using linear arrays\n\n");

  return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_MAT::run_tests_cml_mat()
{
  test_CML_u_MatrixCopy(0);
  test_CML_u_MatrixAddition(0);
  test_CML_u_MatrixSubtraction(0);
  test_CML_u_MatrixMultiplication(0);
  test_CML_f_TransformXPosition2D(0);
  test_CML_f_TransformYPosition2D(0);
  test_CML_v_TransformPosition2D(0);
  test_CML_TrafoMatrix2DMult(0);
  test_CML_GetTrafoMatrixByDisplacement(0);
  test_CML_TrafoMatrix2DInvert(0);
  test_CML_GetTrafoMatrixByAngle(0);
  test_CML_u_MatrixTranspose(0);
  test_CML_u_MatrixInversion(0); 

	test_memset_s(1);
	test_memcpy_s(1);
	test_CML_memcpy_aligned(1);
	test_CML_memset_aligned(1);
}


/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_CML_MAT::test_memset_s(int doIt)
{
	using namespace std;
	if (doIt) 
	{
		uint8 arr[20] = {0};
		uint8 arr_std[20] = {0};
		uint32 count = 15;
		uint8 *ptr = arr, *std_ptr = arr_std;
		
		cout<<"\n test_memset_s:\n";

		CML_memset_s(ptr, 80, -45, count);
		for(uint32 i = 0; i < 10; ++i){
			std::cout<<ptr[i]<<"\t";
		}
		cout<<endl;
		memset(std_ptr, -45, count);
		for(uint32 i = 0; i < 10; ++i){
			std::cout<<std_ptr[i]<<"\t";
		}

		cout<<"\ntest_memset_s comparision : "<<memcmp(ptr, std_ptr, count);

	}
}
void TEST_CLASS_CML_MAT::test_memcpy_s(int doIt)
{
	using namespace std;
	if (doIt) 
	{
		uint8 arr[20] = {10};
		uint8 arr_res[20] = {0}, arr_std[20] = {0};
		uint32 count = 15;
		uint8 *ptr = arr;
		uint8 *dst = arr_res;
		uint8 *dst_std = arr_std;
		
		cout<<"\n test_memcpy_s:\n";
		for(uint32 i = 0; i < 10; ++i){
			arr[i] = i*(i + i)*(-i);
		}

		CML_memcpy_s(dst, 80, ptr, count);
		for(uint32 i = 0; i < 10; ++i){
			std::cout<<dst[i]<<"\t";
		}
		cout<<endl;
		 memcpy(dst_std, ptr, count);
		for(uint32 i = 0; i < 10; ++i){
			std::cout<<dst_std[i]<<"\t";
		}
				 
		cout<<"\ntest_memcpy_s comparision : "<<memcmp(dst, dst_std, count);
	}
}

void TEST_CLASS_CML_MAT::test_CML_memcpy_aligned(int doIt)
{
	using namespace std;
	if (doIt) 
	{
		sint32 arr[20] = {10};
		sint32 arr_res[20] = {0}, arr_std[20] = {0};
		uint32 count = 39;
		sint32 *ptr = arr;
		sint32 *dst = arr_res;
		sint32 *dst_std = arr_std;
		
		cout<<"\n test_memcpy_s_aligned:\n";
		for(uint32 i = 0; i < 10; ++i){
			arr[i] = i*(i + i)*(-i);
		}

		CML_memcpyAlign_s(dst, 80, ptr, count);
		for(uint32 i = 0; i < 10; ++i){
			std::cout<<dst[i]<<"\t";
		}
		cout<<endl;
		memcpy(dst_std, ptr, count);
		for(uint32 i = 0; i < 10; ++i){
			std::cout<<dst_std[i]<<"\t";
		}
		
		cout<<"\ntest_memcpy_s_aligned comparision : "<<memcmp(dst, dst_std, count);
	}
}
void TEST_CLASS_CML_MAT::test_CML_memset_aligned(int doIt)
{
	using namespace std;
	if (doIt) 
	{
		uint32 arr[20] = {0};
		uint32 arr_std[20] = {0};
		uint32 count = 39;
		uint32 *ptr, *std_ptr;
		
		cout<<"\n CML_memset_aligned:\n";
		
	PRINT_TEST_CASE("memset negative number, set : -15, count 39\n")

	{
		count = 39;
		uint32 *ptr = arr;
		uint32 *std_ptr = arr_std;

		GET_CLOCK()
		CML_memsetAlign_s(ptr, 80, -15, count);	
		CALCULATE_CYLES("CML_memset_aligned", 1)

		cout<<endl;

		GET_CLOCK()
		 memset(std_ptr, -15, count);
		CALCULATE_CYLES("memset", 1)

		for(uint32 i = 0; i < 10; ++i){
			std::cout<<std_ptr[i]<<"\t";
		}		
	    cout<<"\nCML_memset_aligned comparision : %d"<< memcmp(ptr, std_ptr, count);
		fprintf(fpTest, ", %d",memcmp(ptr, std_ptr, count));
	}

	PRINT_TEST_CASE("memset pos number, set : 16, count 30\n")

	{
		count = 30;
		uint32 *ptr = arr;
		uint32 *std_ptr = arr_std;

		GET_CLOCK()
		CML_memsetAlign_s(ptr, 80, 16, count);	
		CALCULATE_CYLES("CML_memset_aligned", 1)

		for(uint32 i = 0; i < 10; ++i){
			std::cout<<ptr[i]<<"\t";
		}
		
		cout<<endl;

		GET_CLOCK()
		 memset(std_ptr, 16, count);
		CALCULATE_CYLES("memset", 1)

		for(uint32 i = 0; i < 10; ++i){
			std::cout<<std_ptr[i]<<"\t";
		}		
	    cout<<"memset %d "<<memcmp(ptr, std_ptr, count);
		fprintf(fpTest, ", %d",memcmp(ptr, std_ptr, count));
	}

	
	PRINT_TEST_CASE("memset prime number, set : 3, count 1600\n")

	{
		uint32 arr[2000] = {0};
		uint32 arr_std[2000] = {0};
		count = 8000;
		uint32 *ptr = arr;
		uint32 *std_ptr = arr_std;

		GET_CLOCK()
		CML_memsetAlign_s(ptr, 8000, 3, count);	
		CALCULATE_CYLES("CML_memset_aligned", 1)

		cout<<endl;

		GET_CLOCK()
		 memset(std_ptr, 3, count);
		CALCULATE_CYLES("memset", 1)

		for(uint32 i = 0; i < 10; ++i){
			std::cout<<std_ptr[i]<<"\t";
		}		
	    cout<<"\nCML_memset_aligned comparision : %d"<< memcmp(ptr, std_ptr, count);
		fprintf(fpTest, ", %d",memcmp(ptr, std_ptr, count));
	}

	PRINT_TEST_CASE("memset biggest 1 byte prime number, set : 251, count 300\n")

	{
		uint32 arr[2000] = {0};
		uint32 arr_std[2000] = {0};
		count = 300;
		uint32 *ptr = arr;
		uint32 *std_ptr = arr_std;

		GET_CLOCK()
		CML_memsetAlign_s(ptr, 80, 251, count);	
		CALCULATE_CYLES("CML_memset_aligned", 1)

		for(uint32 i = 0; i < 10; ++i){
			std::cout<<ptr[i]<<"\t";
		}
		
		cout<<endl;

		GET_CLOCK()
		 memset(std_ptr, 251, count);
		CALCULATE_CYLES("memset", 1)

		for(uint32 i = 0; i < 10; ++i){
			std::cout<<std_ptr[i]<<"\t";
		}		
	    cout<<"\nCML_memset_aligned comparision : %d "<<memcmp(ptr, std_ptr, count);
		fprintf(fpTest, ", %d",memcmp(ptr, std_ptr, count));
	}
	}//if (doIt) 
}

void TEST_CLASS_CML_MAT::test_CML_u_MatrixCopy(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixCopy_1   "test_001_CML_u_MatrixCopy_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixCopy_1   "test_001_CML_u_MatrixCopy_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_u_MatrixCopy_1, "w+");	

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    float32 *p_MatrixA,*p_MatrixB, *p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx, u_dim_By;

	PRINT_TEST_CASE(__FUNCTION__)

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_u_MatrixCopy(p_MatrixA, p_MatrixB, u_dim_Ax, u_dim_Ay);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;
    /* Test Matrices: A = 3X3, B = 3X3 */
    {
      u_dim_Ax = 3;
      u_dim_Ay = 3;
      u_dim_Bx = 3;
      u_dim_By = 3;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1009];
      
      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*103.4567;
        p_MatrixA[i] +=  i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixCopy(p_MatrixA, p_MatrixB, u_dim_Ax, u_dim_Ay);	
		CALCULATE_CYLES(__FUNCTION__, 1)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_MatrixB[i];
        }				
      }
    }

    /* Test Matrices: A = 4X4, B = 4X4, AXB = 4X4 */
    {
      u_dim_Ax = 4;
      u_dim_Ay = 4;
      u_dim_Bx = 4;
      u_dim_By = 4;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1016];
      
      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*13.4567    ;
        p_MatrixA[i] +=  i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixCopy(p_MatrixA, p_MatrixB, u_dim_Ax, u_dim_Ay);		
		CALCULATE_CYLES(__FUNCTION__, 2)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_MatrixB[i];
        }				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 5;
      u_dim_Ay = 6;
      u_dim_Bx = 5;
      u_dim_By = 6;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1030];
      
      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*-7000.75474 ;
        p_MatrixA[i] += i;
      }

      for (int i = 0; i < u_dim_Bx*u_dim_By; i++)		
      {				
        p_MatrixB[i] = i*2045.4567 + 1033.4567;				
      }			

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);		
	{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixCopy(p_MatrixA, p_MatrixB, u_dim_Ax, u_dim_Ay);		
		CALCULATE_CYLES(__FUNCTION__, 3)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_MatrixB[i];
        }				
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_u_MatrixAddition(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixAddition_1   "test_001_CML_u_MatrixAddition_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixAddition_1   "test_001_CML_u_MatrixAddition_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif
	PRINT_TEST_CASE(__FUNCTION__)
    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_u_MatrixAddition_1, "w+");	

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    float32 *p_MatrixA,*p_MatrixB, *p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx, u_dim_By;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_u_MatrixAddition(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }

    int dataIndex = 0;

    /* Test Matrices: A = 3X3, B = 3X3, A+B = 3X3 */
    {
      u_dim_Ax = 3;
      u_dim_Ay = 3;
      u_dim_Bx = 3;
      u_dim_By = 3;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1009];
      p_AxB     = &data_log_buffer[1018];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*103.4567f;
        p_MatrixA[i] += i;
        p_MatrixB[i] = i*-133.4567f ;
        p_MatrixB[i] += 1033.4567f;
        p_AxB    [i] = 0;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
		for(uint32 k = 0; k < 50; k++){
			GET_CLOCK()
			p_CsvDataOut.value[dataIndex] = CML_u_MatrixAddition(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);		
			CALCULATE_CYLES(__FUNCTION__, 1)
			for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
			{
				p_CsvDataOut.value[dataIndex++] = p_AxB[i];
			}
		}
      }
    }

    /* Test Matrices: A = 4X4, B = 4X4, AXB = 4X4 */
    {
      u_dim_Ax = 4;
      u_dim_Ay = 4;
      u_dim_Bx = 4;
      u_dim_By = 4;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1016];
      p_AxB     = &data_log_buffer[1032];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*13.4567f;
        p_MatrixA[i] += i;
        p_MatrixB[i] = i*-1033.4567f ;
        p_MatrixB[i] += 1033.4567f;
        p_AxB    [i] = 0;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
		for(uint32 k = 0; k < 50; k++){
			GET_CLOCK()
			p_CsvDataOut.value[dataIndex] = CML_u_MatrixAddition(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);	
			CALCULATE_CYLES(__FUNCTION__, 2)
			for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
			{
			  p_CsvDataOut.value[dataIndex++] = p_AxB[i];
			}
		}
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 6;
      u_dim_Ay = 8;
      u_dim_Bx = 6;
      u_dim_By = 8;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1048];
      p_AxB     = &data_log_buffer[1096];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*-7000.75474f;
        p_MatrixA[i] += i;
      }

      for (int i = 0; i < u_dim_Bx*u_dim_By; i++)		
      {				
        p_MatrixB[i] = i*2045.4567;				
        p_MatrixB[i] += 1033.4567;
      }

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {				
        p_AxB[i] = 0;				
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
		for(uint32 k = 0; k < 50; k++){
			GET_CLOCK()
			p_CsvDataOut.value[dataIndex] = CML_u_MatrixAddition(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);		
			CALCULATE_CYLES(__FUNCTION__, 3)
			for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
			{
			  p_CsvDataOut.value[dataIndex++] = p_AxB[i];
			}
		}
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_u_MatrixSubtraction(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixSubtraction_1   "test_001_CML_u_MatrixSubtraction_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixSubtraction_1   "test_001_CML_u_MatrixSubtraction_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_u_MatrixSubtraction_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)
    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    float32 *p_MatrixA,*p_MatrixB, *p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx, u_dim_By;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_u_MatrixAddition(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: A = 3X3, B = 3X3, A+B = 3X3 */
    {
      u_dim_Ax = 3;
      u_dim_Ay = 3;
      u_dim_Bx = 3;
      u_dim_By = 3;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1009];
      p_AxB     = &data_log_buffer[1018];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*103.4567;
        p_MatrixA[i] += i;
        p_MatrixB[i] = i*-133.4567;
        p_MatrixB[i] += 1033.4567;
        p_AxB    [i] = 0;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	for(uint8 k = 0; k < 50; ++k)
	{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixSubtraction(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);	
		CALCULATE_CYLES(__FUNCTION__, 1)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_AxB[i];
        }				
      }
    }

    /* Test Matrices: A = 4X4, B = 4X4, AXB = 4X4 */
    {
      u_dim_Ax = 4;
      u_dim_Ay = 4;
      u_dim_Bx = 4;
      u_dim_By = 4;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1016];
      p_AxB     = &data_log_buffer[1032];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*13.4567;
        p_MatrixA[i] += i;
        p_MatrixB[i] = i*-1033.4567;
        p_MatrixB[i] += 1033.4567;
        p_AxB    [i] = 0;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	for(uint8 k = 0; k < 50; ++k)
	{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixSubtraction(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);	
		CALCULATE_CYLES(__FUNCTION__, 2)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_AxB[i];
        }				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 6;
      u_dim_Ay = 8;
      u_dim_Bx = 6;
      u_dim_By = 8;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1048];
      p_AxB     = &data_log_buffer[1096];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*-7000.75474;
        p_MatrixA[i] += i;
      }

      for (int i = 0; i < u_dim_Bx*u_dim_By; i++)		
      {				
        p_MatrixB[i] = i*2045.4567;
        p_MatrixB[i] += 1033.4567;
      }

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {				
        p_AxB[i] = 0;				
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	
	for(uint8 k = 0; k < 50; ++k)
	{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixSubtraction(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay);		
		CALCULATE_CYLES(__FUNCTION__, 3)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_AxB[i];
        }				
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_u_MatrixMultiplication(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixMultiplication_1   "test_001_CML_u_MatrixMultiplication_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixMultiplication_1   "test_001_CML_u_MatrixMultiplication_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_u_MatrixMultiplication_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    float32 *p_MatrixA,*p_MatrixB, *p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx, u_dim_By;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_u_MatrixMultiplication(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: A = 3X3, B = 3X3, AXB = 3X3 */
    {
      u_dim_Ax = 3;
      u_dim_Ay = 3;
      u_dim_Bx = 3;
      u_dim_By = 3;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1009];
      p_AxB     = &data_log_buffer[1018];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*103.4567f;
        p_MatrixA[i] += i;
        p_MatrixB[i] = i*-133.4567f ;
        p_MatrixB[i] += 1033.4567f;
        p_AxB    [i] = 0;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	for(uint8 k = 0; k < 50; ++k){
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixMultiplication(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx);	
		CALCULATE_CYLES(__FUNCTION__, 1)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_By; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_AxB[i];
        }				
      }
    }

    /* Test Matrices: A = 4X4, B = 4X4, AXB = 4X4 */
    {
      u_dim_Ax = 4;
      u_dim_Ay = 4;
      u_dim_Bx = 4;
      u_dim_By = 4;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1016];
      p_AxB     = &data_log_buffer[1032];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*13.4567f;
        p_MatrixA[i] += i;
        p_MatrixB[i] = i*-1033.4567f;
        p_MatrixB[i] += 1033.4567f;
        p_AxB    [i] = 0;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	for(uint8 k = 0; k < 50; ++k){
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixMultiplication(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx);	
		CALCULATE_CYLES(__FUNCTION__, 2)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_By; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_AxB[i];
        }				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ay = 5;
      u_dim_Ax = 6;
      u_dim_By = 6;
      u_dim_Bx = 8;

      p_MatrixA = &data_log_buffer[1000];
      p_MatrixB = &data_log_buffer[1030];
      p_AxB     = &data_log_buffer[1078];

      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*-7000.75474f;
        p_MatrixA[i] += i;
      }

      for (int i = 0; i < u_dim_Bx*u_dim_By; i++)		
      {				
        p_MatrixB[i] = i*2045.4567f;				
        p_MatrixB[i] += 1033.4567f;
      }

      for (int i = 0; i < u_dim_Ax*u_dim_By; i++)		
      {				
        p_AxB[i] = 0;				
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
	for(uint8 k = 0; k < 50; ++k){
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixMultiplication(p_MatrixA, p_MatrixB, p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx);	
		CALCULATE_CYLES(__FUNCTION__, 3)
	}
        for (int i = 0; i < u_dim_Ax*u_dim_By; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_AxB[i];
        }				
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_f_TransformXPosition2D(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_f_TransformXPosition2D_1   "test_001_CML_f_TransformXPosition2D_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_f_TransformXPosition2D_1   "test_001_CML_f_TransformXPosition2D_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_TransformXPosition2D_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_DistX, f_DistY;
    CML_t_TrafoMatrix2D *p_Matrix, MatrixBuffer;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */

    p_Matrix  = &MatrixBuffer;
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_f_TransformXPosition2D(p_Matrix, f_DistX, f_DistY);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      
      f_DistX = 5.3;
      f_DistY = 2.6;

      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      p_Matrix->TrafoType = TRANSLATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*103.4567f;
        pp_Matrix[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_TransformXPosition2D(p_Matrix, f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        dataIndex++;			
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      
      f_DistX = 5.3;
      f_DistY = 2.6;
      
      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      p_Matrix->TrafoType = ROTATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*13.4567f;
        pp_Matrix[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_TransformXPosition2D(p_Matrix, f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 2)

        dataIndex++;				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      f_DistX = 5.3;
      f_DistY = 2.6;
      
      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      p_Matrix->TrafoType = DEFAULT_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*-7000.75474f;
        pp_Matrix[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_TransformXPosition2D(p_Matrix, f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 3)

        dataIndex++;			
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_f_TransformYPosition2D(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_f_TransformYPosition2D_1   "test_001_CML_f_TransformYPosition2D_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_f_TransformYPosition2D_1   "test_001_CML_f_TransformYPosition2D_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_f_TransformYPosition2D_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_DistX, f_DistY;
    CML_t_TrafoMatrix2D *p_Matrix, MatrixBuffer;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
    p_Matrix  = &MatrixBuffer;
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_f_TransformYPosition2D(p_Matrix, f_DistX, f_DistY);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      f_DistX = 5.3;
      f_DistY = 2.6;

      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      p_Matrix->TrafoType = TRANSLATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*103.4567f;
        pp_Matrix[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_TransformYPosition2D(p_Matrix, f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        dataIndex++;			
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      f_DistX = 5.3;
      f_DistY = 2.6;
      
      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      p_Matrix->TrafoType = ROTATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*13.4567f;
        pp_Matrix[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_TransformYPosition2D(p_Matrix, f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 2)

        dataIndex++;				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      
      f_DistX = 5.3;
      f_DistY = 2.6;
      
      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      p_Matrix->TrafoType = DEFAULT_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*-7000.75474f;
        pp_Matrix[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_f_TransformYPosition2D(p_Matrix, f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 3)

        dataIndex++;			
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_v_TransformPosition2D(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_v_TransformPosition2D_1   "test_001_CML_v_TransformPosition2D_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_v_TransformPosition2D_1   "test_001_CML_v_TransformPosition2D_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_TransformPosition2D_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_DistX, f_DistY;
    CML_t_TrafoMatrix2D *p_Matrix, MatrixBuffer;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
    p_Matrix  = &MatrixBuffer;
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = TransformPosition2D(p_Matrix, &f_DistX, &f_DistY);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;


      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      f_DistX = 1300.4567f;
      f_DistY = -345.234f;

      //p_Matrix->TrafoType = TRANSLATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*103.4567f;
        pp_Matrix[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			
		
		GET_CLOCK()
        CML_v_TransformPosition2D(p_Matrix, &f_DistX, &f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = f_DistX;
        p_CsvDataOut.value[dataIndex]   = f_DistY;

        dataIndex++;			
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      
      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      f_DistX = -672.4567f;
      f_DistY = -1345.234f;

      //p_Matrix->TrafoType = ROTATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*13.4567f;
        pp_Matrix[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        CML_v_TransformPosition2D(p_Matrix, &f_DistX, &f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 2)

        p_CsvDataOut.value[dataIndex++] = f_DistX;
        p_CsvDataOut.value[dataIndex]   = f_DistY;		

        dataIndex++;				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      
      float32 *pp_Matrix = (float32*)&MatrixBuffer;

      f_DistX = -1672.4567f;
      f_DistY = 135.234f;

      //p_Matrix->TrafoType = DEFAULT_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_Matrix[i] = i*-7000.75474f;
        pp_Matrix[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        CML_v_TransformPosition2D(p_Matrix, &f_DistX, &f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 3)

        p_CsvDataOut.value[dataIndex++] = f_DistX;
        p_CsvDataOut.value[dataIndex]   = f_DistY;

        dataIndex++;			
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_TrafoMatrix2DMult(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_TrafoMatrix2DMult_1   "test_001_CML_TrafoMatrix2DMult_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_TrafoMatrix2DMult_1   "test_001_CML_TrafoMatrix2DMult_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_TrafoMatrix2DMult_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_DistX, f_DistY;
    CML_t_TrafoMatrix2D *p_MatrixA, *p_MatrixB, MatrixBufferA, MatrixBufferB, MatrixBufferResult;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */

    p_MatrixA = &MatrixBufferA;
    p_MatrixB = &MatrixBufferB;
            
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;

      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = TRANSLATION_;
      p_MatrixB->TrafoType = TRANSLATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = i*103.4567f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = -i*1213.4567f;
        pp_MatrixB[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = TRANSLATION_;
      p_MatrixB->TrafoType = ROTATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*113.4567f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = -i*229.4567f;
        pp_MatrixB[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 2)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = ROTATION_;
      p_MatrixB->TrafoType = TRANSLATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = i*7000.75474f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*-367.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);	
		CALCULATE_CYLES(__FUNCTION__, 3)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = ROTATION_;
      p_MatrixB->TrafoType = ROTATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*6878.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 4)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = ROTATION_;
      p_MatrixB->TrafoType = DEFAULT_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*6878.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 5)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = TRANSLATION_;
      p_MatrixB->TrafoType = DEFAULT_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*6878.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 6)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = DEFAULT_;
      p_MatrixB->TrafoType = ROTATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*6878.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 7)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = DEFAULT_;
      p_MatrixB->TrafoType = TRANSLATION_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*6878.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 8)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;
      float32 *pp_MatrixB = (float32*)&MatrixBufferB;			

      p_MatrixA->TrafoType = DEFAULT_;
      p_MatrixB->TrafoType = DEFAULT_;

      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
        pp_MatrixB[i] = i*6878.75474f;
        pp_MatrixB[i] += i;
      }
            
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DMult(MatrixBufferA, MatrixBufferB);
		CALCULATE_CYLES(__FUNCTION__, 9)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;	
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_GetTrafoMatrixByDisplacement(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_GetTrafoMatrixByDisplacement_1   "test_001_CML_GetTrafoMatrixByDisplacement_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_GetTrafoMatrixByDisplacement_1   "test_001_CML_GetTrafoMatrixByDisplacement_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_GetTrafoMatrixByDisplacement_1, "w+");	
	    PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_DistX, f_DistY;
    CML_t_TrafoMatrix2D *p_Matrix, MatrixBuffer;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */

    p_Matrix  = &MatrixBuffer;
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_GetTrafoMatrixByDisplacement(f_DistX, f_DistY);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {
      f_DistX = -3342.687;
      f_DistY = 342;			

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBuffer = CML_GetTrafoMatrixByDisplacement(f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f12;				
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      f_DistX = 2455.687;
      f_DistY = -1.0004;	
      
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBuffer = CML_GetTrafoMatrixByDisplacement(f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f12;			
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      f_DistX = -998;
      f_DistY = -9.0004;				
                
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBuffer = CML_GetTrafoMatrixByDisplacement(f_DistX, f_DistY);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBuffer.f12;			
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_TrafoMatrix2DInvert(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_TrafoMatrix2DInvert_1   "test_001_CML_TrafoMatrix2DInvert_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_TrafoMatrix2DInvert_1   "test_001_CML_TrafoMatrix2DInvert_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_TrafoMatrix2DInvert_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_DistX, f_DistY;
    CML_t_TrafoMatrix2D *p_MatrixA, MatrixBufferA, MatrixBufferResult;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */

    p_MatrixA  = &MatrixBufferA;
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_TrafoMatrix2DInvert(MatrixBufferA);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;			

      p_MatrixA->TrafoType = DEFAULT_;
      
      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*0.00001313f;
        pp_MatrixA[i] += i;
      }			

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DInvert(MatrixBufferA);	
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;				
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;			

      p_MatrixA->TrafoType = ROTATION_;
      
      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = -i*330.0313f;
        pp_MatrixA[i] += i;
      }
      
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DInvert(MatrixBufferA);	
		CALCULATE_CYLES(__FUNCTION__, 2)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;			
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 2;
      u_dim_Ay = 2;
      
      float32 *pp_MatrixA = (float32*)&MatrixBufferA;			

      p_MatrixA->TrafoType = TRANSLATION_;
      
      for (int i = 1; i <= u_dim_Ax*u_dim_Ay; i++)		
      {
        pp_MatrixA[i] = i*320.0313f;
        pp_MatrixA[i] += i;
      }			
                
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_TrafoMatrix2DInvert(MatrixBufferA);
		CALCULATE_CYLES(__FUNCTION__, 3)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;			
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_GetTrafoMatrixByAngle(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_GetTrafoMatrixByAngle_1   "test_001_CML_GetTrafoMatrixByAngle_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_GetTrafoMatrixByAngle_1   "test_001_CML_GetTrafoMatrixByAngle_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_GetTrafoMatrixByAngle_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)


    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    uint32 u_dim_Ax, u_dim_Ay;
    float32 f_Angle;
    CML_t_TrafoMatrix2D MatrixBufferResult;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */		
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_GetTrafoMatrixByAngle(f_Angle);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: Tansfo Matrix = 2X2 */
    {	
      for(f_Angle = -CML_f_Pi; f_Angle <= CML_f_Pi; f_Angle += 0.001)
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_GetTrafoMatrixByAngle(f_Angle);
		CALCULATE_CYLES(__FUNCTION__, 1)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;			
		CUT_LOOP()
      }
    }

    /* Test Matrices: Tansfo Matrix = 4X4 */
    {
      for(f_Angle = -4*CML_f_Pi; f_Angle <= 4*CML_f_Pi; f_Angle += 0.1)
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_GetTrafoMatrixByAngle(f_Angle);	
		CALCULATE_CYLES(__FUNCTION__, 2)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;	
		CUT_LOOP()
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      for(f_Angle = -CML_f_Pi/2; f_Angle <= CML_f_Pi/2; f_Angle += 0.0001)				
      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

		GET_CLOCK()
        MatrixBufferResult = CML_GetTrafoMatrixByAngle(f_Angle);	
		CALCULATE_CYLES(__FUNCTION__, 3)

        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.TrafoType;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f00;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f02;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f10;
        p_CsvDataOut.value[dataIndex++] = MatrixBufferResult.f12;		
		CUT_LOOP()
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_u_MatrixTranspose(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixTranspose_1   "test_001_CML_u_MatrixTranspose_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixTranspose_1   "test_001_CML_u_MatrixTranspose_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_u_MatrixTranspose_1, "w+");	
	PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    float32 *p_MatrixA,*p_MatrixTranspose, *p_AxB, u_dim_Ax, u_dim_Ay, u_dim_Bx, u_dim_By;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_u_MatrixTranspose(p_MatrixA, p_MatrixTranspose, u_dim_Ax, u_dim_Ay);	
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: A = 3X3, B = 3X3 */
    {
      u_dim_Ax = 3;
      u_dim_Ay = 3;
      u_dim_Bx = 3;
      u_dim_By = 3;
      
      p_MatrixA		  = &data_log_buffer[1000];
      p_MatrixTranspose = &data_log_buffer[1009];
      
      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)
      {
        p_MatrixA[i] = i*103.4567;
        p_MatrixA[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);
{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixTranspose(p_MatrixA, p_MatrixTranspose, u_dim_Ax, u_dim_Ay);
		CALCULATE_CYLES(__FUNCTION__, 1)
}
        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)
        {
          p_CsvDataOut.value[dataIndex++] = p_MatrixTranspose[i];
        }				
      }
    }

    /* Test Matrices: A = 4X4, B = 4X4, AXB = 4X4 */
    {
      u_dim_Ax = 4;
      u_dim_Ay = 4;
      u_dim_Bx = 4;
      u_dim_By = 4;

      p_MatrixA		  = &data_log_buffer[1000];
      p_MatrixTranspose = &data_log_buffer[1016];
      
      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*13.4567 ;						
        p_MatrixA[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixTranspose(p_MatrixA, p_MatrixTranspose, u_dim_Ax, u_dim_Ay);		
		CALCULATE_CYLES(__FUNCTION__, 2)
}

        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_MatrixTranspose[i];
        }				
      }
    }

    /* Test Matrices: A = 5X6, B = 6X8, AXB = 5X8 */
    {
      u_dim_Ax = 8;
      u_dim_Ay = 6;
      u_dim_Bx = 6;
      u_dim_By = 8;

      p_MatrixA		  = &data_log_buffer[1000];
      p_MatrixTranspose = &data_log_buffer[1048];
      
      for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
      {
        p_MatrixA[i] = i*-7000.75474 ;				
        p_MatrixA[i] += i;
      }					

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixTranspose(p_MatrixA, p_MatrixTranspose, u_dim_Ax, u_dim_Ay);	
		CALCULATE_CYLES(__FUNCTION__, 3)
}

        for (int i = 0; i < u_dim_Ax*u_dim_Ay; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_MatrixTranspose[i];
        }				
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();			
      
    }
  }
}

void TEST_CLASS_CML_MAT::test_CML_u_MatrixInversion(int doIt)
{
  if (doIt) 
  {

    /* Test case data declarations */
#ifdef TARGET_PLATFORM
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixInversion_1   "test_001_CML_u_MatrixInversion_out_target.csv"		
#else
    #define TEST_CML_VECTOR_CSVOUT_CML_u_MatrixInversion_1   "test_001_CML_u_MatrixInversion_out_msvc.csv"		
#endif

    float32 f_power;
    float32 expected_returnValue;
    float32 returnValue;
    /* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
    csv_data_float_t *p_CsvDataOut = NULL;
#else
    csv_data_float_t p_CsvDataOut;
#endif

    csv_data_float_t *current_p_CsvDataOut = NULL;
    FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_u_MatrixInversion_1, "w+");	
    PRINT_TEST_CASE(__FUNCTION__)

    /* input CSV data, linked list node*/
    /* CSV parser return value for result values file */
    sint32 i_CsvRetOut = -1;
    /* CSV parser return value for input values file */
    sint32 i_CsvRetIn = -1;
    float32 *p_MatrixA, *p_tempMatrix, *p_InverseA, u_dim_xy;

    {
      /* Set global data */
      initialise_global_data();
      /* Set expected values for global data checks */
      initialise_expected_global_data();

    /* **********************************************************************
       *                         Test case 1                                *
       ********************************************************************** */
        
#ifdef LINKED_LIST_PARSER
    {
      csv_data_float_t *temp_p_CsvDataOut = NULL;
      temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
      temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
      temp_p_CsvDataOut->len = sizeof(float32);

      *(temp_p_CsvDataOut->value) = CML_u_MatrixInversion(p_MatrixA, p_tempMatrix, p_InverseA, u_dim_xy);
      
      temp_p_CsvDataOut->next = NULL;

      counter++;
      if(p_CsvDataOut == NULL)
      {
        p_CsvDataOut = temp_p_CsvDataOut;				
        current_p_CsvDataOut = temp_p_CsvDataOut;
      }
      else
      {
        current_p_CsvDataOut->next = temp_p_CsvDataOut;
        current_p_CsvDataOut = current_p_CsvDataOut->next;
      }
        
    }
    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

    //printf("%d \t",counter);
    while(p_CsvDataOut != NULL)
    {
      csv_data_float_t *temp_p_CsvDataOut_free = NULL;
      temp_p_CsvDataOut_free = p_CsvDataOut;
      p_CsvDataOut = p_CsvDataOut->next;
      free(temp_p_CsvDataOut_free);
    }
#else
    int dataIndex = 0;

    /* Test Matrices: A = 3X3, InvA = 3X3 */
    {
      u_dim_xy = 3;

      float32 A[9] = 
      {
        1.f,    1.f/2,   1.f/3,
                1.f/2,  1.f/3,   1.f/4,
                1.f/3,  1.f/4,   1.f/5
      };

      p_MatrixA		  = &data_log_buffer[1000];
      p_tempMatrix      = &data_log_buffer[1009];
      p_InverseA        = &data_log_buffer[1018];
      
      p_MatrixA = A;

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixInversion(p_MatrixA, p_tempMatrix, p_InverseA, u_dim_xy);
		CALCULATE_CYLES(__FUNCTION__, 1)
}

        for (int i = 0; i < u_dim_xy*u_dim_xy; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_InverseA[i];
        }				
      }
    }

    /* Test Matrices: A = 4X4, InvA = 4X4 */
    {
      u_dim_xy = 4;

      p_MatrixA		  = &data_log_buffer[1000];
      p_tempMatrix      = &data_log_buffer[1016];
      p_InverseA        = &data_log_buffer[1032];
      
      for (int i = 0; i < u_dim_xy*u_dim_xy; i++)		
      {
        p_MatrixA[i] = i*13.4567 ;
        p_MatrixA[i] += i;
      }

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixInversion(p_MatrixA, p_tempMatrix, p_InverseA, u_dim_xy);		
		CALCULATE_CYLES(__FUNCTION__, 2)
}
        for (int i = 0; i < u_dim_xy*u_dim_xy; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_InverseA[i];
        }				
      }
    }

    /* Test Matrices: A = 5X5, InvA = 5X5 */
    {
      u_dim_xy = 5;

      p_MatrixA		  = &data_log_buffer[1000];
      p_tempMatrix      = &data_log_buffer[1025];
      p_InverseA        = &data_log_buffer[1050];
      
      for (int i = 0; i < u_dim_xy*u_dim_xy; i++)		
      {
        p_MatrixA[i] = i*-7000.75474f;
        p_MatrixA[i] += i;
      }					

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixInversion(p_MatrixA, p_tempMatrix, p_InverseA, u_dim_xy);	
		CALCULATE_CYLES(__FUNCTION__, 3)
}
        for (int i = 0; i < u_dim_xy*u_dim_xy; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_InverseA[i];
        }				
      }
    }

    /* Test Matrices: Hilbert_5-Matrix, A = 5X5, InvA = 5X5 */
    {
      u_dim_xy = 5;

      float32 A[25] = 
      {
        1.,    1./2,  1./3,  1./4,  1./5,
                1./2,  1./3,  1./4,  1./5,  1./6,  
                1./3,  1./4,  1./5,  1./6,  1./7,  
                1./4,  1./5,  1./6,  1./7,  1./8,  
                1./5,  1./6,  1./7,  1./8,  1./9  
      };	

      p_MatrixA		  = &data_log_buffer[1000];
      p_tempMatrix      = &data_log_buffer[1025];
      p_InverseA        = &data_log_buffer[1050];
      
      p_MatrixA = A;					

      {
        p_CsvDataOut.value = data_log_buffer;
        p_CsvDataOut.len = sizeof(float32);			

{
		GET_CLOCK()
        p_CsvDataOut.value[dataIndex] = CML_u_MatrixInversion(p_MatrixA, p_tempMatrix, p_InverseA, u_dim_xy);	
		CALCULATE_CYLES(__FUNCTION__, 4)
}

        for (int i = 0; i < u_dim_xy*u_dim_xy; i++)		
        {
          p_CsvDataOut.value[dataIndex++] = p_InverseA[i];
        }
      }
    }

    p_CsvDataOut.dataBufferSize = dataIndex;

    /* parse CSV values for expected results */
    i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

    fclose(fp);

    /* Checks on global data */
    check_global_data();
      
    }
  }
}

/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
