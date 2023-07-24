/*****************************************************************************/
/*                            CML Target Test Script                         */
/*****************************************************************************/
/*
*    Filename: test_cml_mtrx.cpp
*    Author: uidp1547
*    Generated on: 19-Sep-2016 15:43:28
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
                        

#define GET_CLOCK()  for(uint8 k = 0; k < 50; ++k){\
	start_clock = get_clock();\

#define CALCULATE_CYLES(name,row, col, test_case_num)  {   \
        stop_clock = get_clock();\
        fprintf(fpTest, "%s size %d X %d Test case %d", (name),row, col, (test_case_num));\
        total_cycles = stop_clock - start_clock - overhead;\
        check__PrintValue_to_File(total_cycles, fpTest);\
        fprintf(fpTest, "\n");\
}}
        
#else

#define PRINT_TEST_CASE(test_case_num)
#define GET_CLOCK()
#define CALCULATE_CYLES(name, row, col,test_case_num)

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
extern uint32 CML_u_Round2UintGen(float32 x);
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
extern CML_t_Matrix CML_a_InitMatrixHeader(uint32 u_ColNr, uint32 u_RowNr, float32* p_f_MtrxData);
extern void CML_v_InitMatrix(CML_t_Matrix* p_Matrix, uint32 u_RowNr, uint32 u_ColNr, float32 f_Val);
extern void CML_v_CreateIdentityMatrix(CML_t_Matrix* p_Matrix, uint32 u_Size);
extern void CML_v_AddMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);
extern void CML_v_SubtractMatrices(CML_t_Matrix* Res, const CML_t_Matrix* A, const CML_t_Matrix* B);
extern void CML_v_MultiplyMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);
extern void CML_v_MultiplyMatricesToSymResult(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);
extern void CML_v_MultiplyMatrixWithTranspose(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);
extern void CML_v_InvertMatrix(CML_t_Matrix* p_MatrixRes, CML_t_Matrix* p_MatrixA);
extern boolean b_InvertMatrixCramer2(float32* a_res, float32* a_in);
extern boolean b_InvertMatrixCramer3(float32* a_res, float32* a_in);
extern void CML_v_ScaleMatrix(CML_t_Matrix* p_MatrixA, float32 f_Val);
extern void CML_v_CopyMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);
extern void CML_v_CopyArrayToSymMatrix(CML_t_Matrix* p_MatrixRes, uint32 u_RowNr, uint32 u_ColNr, const float32* p_Data);
extern void CML_v_CholeskyMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);
extern void CML_v_LowTriaInvMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);
extern void CML_v_LowTriaSqrMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);
extern void CML_v_UppTriaSqrMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);
extern void CML_v_TransposeMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);
extern CML_INLINE void CML_v_multiplyMatrices2x2(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);
extern CML_INLINE void CML_v_multiplyMatrices3x3(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);
extern float32 CML_f_SqrtApprox(float32 x);
float32 CML_f_fastlog10(float32 x);
float32 CML_f_log10(float32 x);
/* Global data */

CML_t_Matrix temp_A;
CML_t_Matrix temp_B;
CML_t_Matrix temp_Res;
CML_t_Matrix tp_Res;
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
class TEST_CLASS_CML_MTRX
{
public:
	/* Prototypes for test functions */
	void run_tests_mtrx();
	void test_CML_f_AbsGen(int);
	void test_CML_f_MinGen(int);
	void test_CML_f_MaxGen(int);
	void test_CML_f_Round2FloatGen(int);
	void test_CML_s_Round2IntGen(int);
	void test_CML_u_Round2UintGen(int);
	void test_CML_f_Floor2FloatGen(int);
	void test_CML_f_Ceil2FloatGen(int);
	void test_CML_f_MultAddGen(int);
	void test_CML_f_Sign(int);
	void test_CML_f_PowToDB(int);
	void test_CML_f_MagToDB(int);
	void test_CML_a_InitMatrixHeader(int);	
	void test_CML_v_CreateIdentityMatrix(int);
	void test_CML_v_AddMatrices(int);
	void test_CML_v_SubtractMatrices(int);
	void test_CML_v_MultiplyMatrices(int);
	void test_CML_v_MultiplyMatricesToSymResult(int);
	void test_CML_v_MultiplyMatrixWithTranspose(int);
	void test_CML_v_InvertMatrix(int);
	void test_b_InvertMatrixCramer2(int);
	void test_b_InvertMatrixCramer3(int);
	void test_CML_v_ScaleMatrix(int);
	void test_CML_v_CopyMatrix(int);
	void test_CML_v_CopyArrayToSymMatrix(int);
	void test_CML_v_CholeskyMatrix(int);
	void test_CML_v_LowTriaInvMatrix(int);
	void test_CML_v_LowTriaSqrMatrix(int);
	void test_CML_v_UppTriaSqrMatrix(int);
	void test_CML_v_TransposeMatrix(int);
	void test_CML_f_SqrtApprox(int);	
	void test_CML_v_MultiplyMatrices2x2(int);	
	void test_CML_v_MultiplyMatrices3x3(int);	
	void test_static_assert(int);
};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_mtrx(void)
{
	TEST_CLASS_CML_MTRX test_object;

	std::cout << "******** Start Testing: CML Matrix functions using Matrix structure ********\n\n";
	fprintf(fpTest, "******** Start Testing: CML Matrix functions using Matrix structure ********\n\n");

	test_object.run_tests_mtrx();

	std::cout << "End of Testing: CML Matrix functions using Matrix structure\n\n";
	fprintf(fpTest, "End of Testing: CML Matrix functions using Matrix structure\n\n");

	return;
}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_MTRX::run_tests_mtrx()
{
	test_CML_a_InitMatrixHeader(0);
	test_CML_v_CopyMatrix(0);	
	test_CML_v_CreateIdentityMatrix(0);
	test_CML_v_ScaleMatrix(0);
	test_CML_v_CopyArrayToSymMatrix(0);	
	test_CML_v_AddMatrices(0);
	test_CML_v_SubtractMatrices(0);	
	test_CML_v_MultiplyMatrices(0);	
	test_CML_v_MultiplyMatrices2x2(0);	
	test_CML_v_MultiplyMatrices3x3(0);
	test_CML_v_MultiplyMatricesToSymResult(0);	
	test_CML_v_MultiplyMatrixWithTranspose(0);	
	test_CML_v_LowTriaSqrMatrix(0);
	test_CML_v_UppTriaSqrMatrix(0);
	test_CML_v_LowTriaInvMatrix(0);	
	test_CML_v_TransposeMatrix(0);	
	test_CML_v_InvertMatrix(0);	
	test_CML_v_CholeskyMatrix(0);		
	test_static_assert(1);
}


/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void TEST_CLASS_CML_MTRX::test_CML_a_InitMatrixHeader(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_a_InitMatrixHeader_1   "test_001_CML_a_InitMatrixHeader_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_a_InitMatrixHeader_1   "test_001_CML_a_InitMatrixHeader_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_a_InitMatrixHeader_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxData;
		CML_t_Matrix	CML_t_Matrix_struct;

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

			*(temp_p_CsvDataOut->value) = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);	
			
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

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
			
			p_f_MtrxData = &data_log_buffer[1000];

			for(int i = 0; i < u_RowNr*u_ColNr; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);		
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < u_RowNr*u_ColNr; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = CML_t_Matrix_struct.pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;
			
			p_f_MtrxData = &data_log_buffer[1000];

			for(int i = 0; i < u_RowNr*u_ColNr; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);	
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < u_RowNr*u_ColNr; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = CML_t_Matrix_struct.pData[i];
				}				
			}
		}

		/* Test Matrices: A = 6X8 */
		{
			u_RowNr = 6;
			u_ColNr = 8;
			
			p_f_MtrxData = &data_log_buffer[1000];

			for(int i = 0; i < u_RowNr*u_ColNr; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);	
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < u_RowNr*u_ColNr; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = CML_t_Matrix_struct.pData[i];
				}				
			}
		}

		/* Test Matrices: A = 64X64 */
		{
			u_RowNr = 64;
			u_ColNr = 64;
			
			p_f_MtrxData = &data_log_buffer[10000];

			for(int i = 0; i < u_RowNr*u_ColNr; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);	
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < u_RowNr*u_ColNr; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = CML_t_Matrix_struct.pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_CopyMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CopyMatrix_1   "test_001_CML_v_CopyMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CopyMatrix_1   "test_001_CML_v_CopyMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_CopyMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_CopyMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
					
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1009];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			for(int i = 0; i < p_MatrixA->Desc.row * p_MatrixA->Desc.col; i++)
			{
				p_f_MtrxDataA[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1025];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			for(int i = 0; i < p_MatrixA->Desc.row * p_MatrixA->Desc.col; i++)
			{
				p_f_MtrxDataA[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 6X8 */
		{
			u_RowNr = 6;
			u_ColNr = 8;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1048];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			for(int i = 0; i < p_MatrixA->Desc.row * p_MatrixA->Desc.col; i++)
			{
				p_f_MtrxDataA[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 64X64 */
		{
			u_RowNr = 64;
			u_ColNr = 64;

			p_f_MtrxDataA   = &data_log_buffer[10000];
			p_f_MtrxDataRes = &data_log_buffer[14096];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			for(int i = 0; i < p_MatrixA->Desc.row * p_MatrixA->Desc.col; i++)
			{
				p_f_MtrxDataA[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 4)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_CreateIdentityMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CreateIdentityMatrix_1   "test_001_CML_v_CreateIdentityMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CreateIdentityMatrix_1   "test_001_CML_v_CreateIdentityMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_CreateIdentityMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxData;
		CML_t_Matrix	*p_Matrix, CML_t_Matrix_struct;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_Matrix = &CML_t_Matrix_struct;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_CreateIdentityMatrix(p_Matrix, u_Size);
			
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

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
			
			p_f_MtrxData = &data_log_buffer[1000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CreateIdentityMatrix(p_Matrix, u_RowNr);	
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;
			
			p_f_MtrxData = &data_log_buffer[1000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CreateIdentityMatrix(p_Matrix, u_RowNr);	
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 6X8 */
		{
			u_RowNr = 6;
			u_ColNr = 8;
			
			p_f_MtrxData = &data_log_buffer[1000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CreateIdentityMatrix(p_Matrix, u_RowNr);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 64X64 */
		{
			u_RowNr = 64;
			u_ColNr = 64;
			
			p_f_MtrxData = &data_log_buffer[10000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = 9999;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CreateIdentityMatrix(p_Matrix, u_RowNr);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 4)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_ScaleMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_ScaleMatrix_1   "test_001_CML_v_ScaleMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_ScaleMatrix_1   "test_001_CML_v_ScaleMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_ScaleMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxData, f_scale_Val;
		CML_t_Matrix	*p_Matrix, CML_t_Matrix_struct;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_Matrix = &CML_t_Matrix_struct;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_CreateIdentityMatrix(p_Matrix, u_Size);
			
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

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;

			f_scale_Val = -0.004647;
			
			p_f_MtrxData = &data_log_buffer[1000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_ScaleMatrix(p_Matrix, f_scale_Val);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			f_scale_Val = 10.004647;
			
			p_f_MtrxData = &data_log_buffer[1000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = i*-2.5789;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_ScaleMatrix(p_Matrix, f_scale_Val);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 6X8 */
		{
			u_RowNr = 6;
			u_ColNr = 8;

			f_scale_Val = -560.004647;
			
			p_f_MtrxData = &data_log_buffer[1000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = i*7.8;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_ScaleMatrix(p_Matrix, f_scale_Val);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 64X64 */
		{
			u_RowNr = 64;
			u_ColNr = 64;

			f_scale_Val = 60.004647;
			
			p_f_MtrxData = &data_log_buffer[10000];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_f_MtrxData[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_ScaleMatrix(p_Matrix, f_scale_Val);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 4)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_CopyArrayToSymMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CopyArrayToSymMatrix_1   "test_001_CML_v_CopyArrayToSymMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CopyArrayToSymMatrix_1   "test_001_CML_v_CopyArrayToSymMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_CopyArrayToSymMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxData, *p_Data;
		CML_t_Matrix	*p_Matrix, CML_t_Matrix_struct;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_Matrix = &CML_t_Matrix_struct;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_CopyArrayToSymMatrix(p_Matrix, u_RowNr, u_ColNr, p_Data);
			
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

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
							
			p_Data		 = &data_log_buffer[1000];
			p_f_MtrxData = &data_log_buffer[1009];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_Data[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyArrayToSymMatrix(p_Matrix, u_RowNr, u_ColNr, p_Data);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_Data		 = &data_log_buffer[1000];
			p_f_MtrxData = &data_log_buffer[1025];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_Data[i] = i*-2.5789;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyArrayToSymMatrix(p_Matrix, u_RowNr, u_ColNr, p_Data);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 6X8 */
		{
			u_RowNr = 8;
			u_ColNr = 8;

			p_Data		 = &data_log_buffer[1000];
			p_f_MtrxData = &data_log_buffer[1064];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_Data[i] = i*7.8;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyArrayToSymMatrix(p_Matrix, u_RowNr, u_ColNr, p_Data);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 64X64 */
		{
			u_RowNr = 64;
			u_ColNr = 64;

			p_Data		 = &data_log_buffer[10000];
			p_f_MtrxData = &data_log_buffer[14096];

			CML_t_Matrix_struct = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxData);

			for(int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)
			{
				p_Data[i] = i;
			}
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CopyArrayToSymMatrix(p_Matrix, u_RowNr, u_ColNr, p_Data);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_Matrix->Desc.row * p_Matrix->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_Matrix->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_LowTriaSqrMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_LowTriaSqrMatrix_1   "test_001_CML_v_LowTriaSqrMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_LowTriaSqrMatrix_1   "test_001_CML_v_LowTriaSqrMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_LowTriaSqrMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_LowTriaSqrMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 4;
			u_ColNr = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f,   0.f,   0.f, 
				4.f,  32.f,   0.f,   0.f,
				5.f,  40.f,  75.f,   0.f,
				6.f,  48.f,  90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_LowTriaSqrMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				100,		0,		0,			0,		0,
				4000,		302,	0,			0,		0,
				-5.003,		40,		705,		0,		0,
				79879,		48,		90.001,		9144,	0,
				-806.8587,	748,	790,		144,	-156.789,
			}; 

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_LowTriaSqrMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_UppTriaSqrMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_UppTriaSqrMatrix_1   "test_001_CML_v_UppTriaSqrMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_UppTriaSqrMatrix_1   "test_001_CML_v_UppTriaSqrMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_UppTriaSqrMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_UppTriaSqrMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 4;
			u_ColNr = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 17.f, -30.f, 
				0.f,  32.f, -70.f,   0.8987f,
				0.f,   0.f,  75.f,   7.f,
				0.f,   0.f,   0.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			
				
				GET_CLOCK()
				CML_v_UppTriaSqrMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				100,	    440,	670,	  -34,		50,
				  0,		302,	-565,	0.045,	    330,
				  0,		0,		705,	   30,		-770,
				  0,		0,		0,		 -780,	    2330,
				  0,	    0,	    0,		    0,	- 156.789,
			}; 

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_UppTriaSqrMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_LowTriaInvMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_LowTriaInvMatrix_1   "test_001_CML_v_LowTriaInvMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_LowTriaInvMatrix_1   "test_001_CML_v_LowTriaInvMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_LowTriaInvMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_LowTriaInvMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 4;
			u_ColNr = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f,   0.f,   0.f, 
				4.f,  32.f,   0.f,   0.f,
				5.f,  40.f,  75.f,   0.f,
				6.f,  48.f,  90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_LowTriaInvMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				100,		0,		0,			0,		0,
				4000,		302,	0,			0,		0,
				-5.003,		40,		705,		0,		0,
				79879,		48,		90.001,		9144,	0,
				-806.8587,	748,	790,		144,	-156.789,
			}; 

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_LowTriaInvMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_TransposeMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_TransposeMatrix_1   "test_001_CML_v_TransposeMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_TransposeMatrix_1   "test_001_CML_v_TransposeMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_TransposeMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_TransposeMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 4;
			u_ColNr = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 17.f, -30.f, 
				0.f,  32.f, -70.f,   0.8987f,
				0.f,   0.f,  75.f,   7.f,
				0.f,   0.f,   0.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_TransposeMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				100,	    440,	670,	  -34,		50,
				  0,		302,	-565,	0.045,	    330,
				  0,		0,		705,	   30,		-770,
				  0,		0,		0,		 -780,	    2330,
				  0,	    0,	    0,		    0,	- 156.789,
			}; 

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_TransposeMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}		

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 6;
			u_ColNr = 8;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1048];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576,
				7906.8587,	   748,		  790,   144.6667,		   -6.789,           66.4,
				7906.8587,	   748,		  790,   144.6667,		    0.17896,          -.0000998
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_TransposeMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_InvertMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_InvertMatrix_1   "test_001_CML_v_InvertMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_InvertMatrix_1   "test_001_CML_v_InvertMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_InvertMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 2;
			u_ColNr = 2;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1004];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 
				0.f,  32.f
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1009];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 17.f, 
				0.f,  32.f, -70.f,  
				0.f,   0.f,  75.f
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: Hilbert A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1009];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			float32 A[9] = 
			{
				1.f,    1.f/2,   1.f/3,
                1.f/2,  1.f/3,   1.f/4,
                1.f/3,  1.f/4,   1.f/5
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}		

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 4;
			u_ColNr = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 17.f, -30.f, 
				0.f,  32.f, -70.f,   0.8987f,
				0.f,   0.f,  75.f,   7.f,
				0.f,   0.f,   0.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 4)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1025];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				100,	    440,	670,	  -34,		50,
				  0,		302,	-565,	0.045,	    330,
				  0,		0,		705,	   30,		-770,
				  0,		0,		0,		 -780,	    2330,
				  0,	    0,	    0,		    0,	- 156.789,
			}; 

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 5)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}		

		/* Test Matrices: Hilbert A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1025];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			float32 A[25] = {
				1.,    1./2,  1./3,  1./4,  1./5,
                1./2,  1./3,  1./4,  1./5,  1./6,  
                1./3,  1./4,  1./5,  1./6,  1./7,  
                1./4,  1./5,  1./6,  1./7,  1./8,  
                1./5,  1./6,  1./7,  1./8,  1./9  
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 6)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}	

		/* Test Matrices: A = 6X6 */
		{
			u_RowNr = 6;
			u_ColNr = 6;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1036];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576				
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_InvertMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 7)


				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_CholeskyMatrix(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CholeskyMatrix_1   "test_001_CML_v_CholeskyMatrix_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_CholeskyMatrix_1   "test_001_CML_v_CholeskyMatrix_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_CholeskyMatrix_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNr, u_RowNr;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
			
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

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 2;
			u_ColNr = 2;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1004];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 
				0.f,  32.f
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1009];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 17.f, 
				0.f,  32.f, -70.f,  
				0.f,   0.f,  75.f
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: Hilbert A = 3X3 */
		{
			u_RowNr = 3;
			u_ColNr = 3;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1009];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			float32 A[9] = 
			{
				1.f,    1.f/2,   1.f/3,
                1.f/2,  1.f/3,   1.f/4,
                1.f/3,  1.f/4,   1.f/5
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 3)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}		

		/* Test Matrices: A = 4X4 */
		{
			u_RowNr = 4;
			u_ColNr = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1016];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f, -910.f, 17.f, -30.f, 
				0.f,  32.f, -70.f,   0.8987f,
				0.f,   0.f,  75.f,   7.f,
				0.f,   0.f,   0.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 4)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1025];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				100,	    440,	670,	  -34,		50,
				  0,		302,	-565,	0.045,	    330,
				  0,		0,		705,	   30,		-770,
				  0,		0,		0,		 -780,	    2330,
				  0,	    0,	    0,		    0,	- 156.789,
			}; 

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 5)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}		

		/* Test Matrices: Hilbert A = 5X5 */
		{
			u_RowNr = 5;
			u_ColNr = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1025];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			float32 A[25] = {
				1.,    1./2,  1./3,  1./4,  1./5,
                1./2,  1./3,  1./4,  1./5,  1./6,  
                1./3,  1./4,  1./5,  1./6,  1./7,  
                1./4,  1./5,  1./6,  1./7,  1./8,  
                1./5,  1./6,  1./7,  1./8,  1./9  
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 6)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}	

		/* Test Matrices: A = 6X6 */
		{
			u_RowNr = 6;
			u_ColNr = 6;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataRes = &data_log_buffer[1036];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataA);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNr, u_RowNr, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576				
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_CholeskyMatrix(p_MatrixRes, p_MatrixA);
				CALCULATE_CYLES(__FUNCTION__,u_RowNr, u_ColNr, 7)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_AddMatrices(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_AddMatrices_1   "test_001_CML_v_AddMatrices_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_AddMatrices_1   "test_001_CML_v_AddMatrices_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_AddMatrices_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_AddMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
			
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

		/* Test Matrices: A = 4X4, B = 4X4, Res = 4X4 */
		{
			u_RowNrA = 4;
			u_ColNrA = 4;

			u_RowNrB = 4;
			u_ColNrB = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_AddMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

				/* Test Matrices: A = 2X2, B = 2X2, Res = 2X2 */
		{
			u_RowNrA = 2;
			u_ColNrA = 2;

			u_RowNrB = 2;
			u_ColNrB = 2;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_AddMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X6, B = 5X6, Res = 5X6 */
		{
			u_RowNrA = 5;
			u_ColNrA = 6;

			u_RowNrB = 5;
			u_ColNrB = 6;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998				
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_AddMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 3)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}		

		
		/* Test Matrices: A = 3X5, B = 5X5, Res = 3X5 */
		{
			u_RowNrA = 3;
			u_ColNrA = 5;

			u_RowNrB = 5;
			u_ColNrB = 5;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998				
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_AddMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 4)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_SubtractMatrices(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_SubtractMatrices_1   "test_001_CML_v_SubtractMatrices_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_SubtractMatrices_1   "test_001_CML_v_SubtractMatrices_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_SubtractMatrices_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_SubtractMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
			
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

		/* Test Matrices: A = 4X4, B = 4X4, Res = 4X4 */
		{
			u_RowNrA = 4;
			u_ColNrA = 4;

			u_RowNrB = 4;
			u_ColNrB = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			
				
				GET_CLOCK()
				CML_v_SubtractMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X6, B = 5X6, Res = 5X6 */
		{
			u_RowNrA = 5;
			u_ColNrA = 6;

			u_RowNrB = 5;
			u_ColNrB = 6;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998				
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_SubtractMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_MultiplyMatrices(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices_1   "test_001_CML_v_MultiplyMatrices_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices_1   "test_001_CML_v_MultiplyMatrices_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_MultiplyMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
			
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

		/* Test Matrices: A = 4X4, B = 4X4, Res = 4X4 */
		{
			u_RowNrA = 2;
			u_ColNrA = 2;

			u_RowNrB = 2;
			u_ColNrB = 2;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
		//			p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
		//			std::cout<<p_MatrixRes->pData[i]<<std::endl;
				}				
			}
		}

		
			/* Test Matrices: A = 3X3, B = 3X3, Res = 3X3*/
		{
			u_RowNrA = 3;
			u_ColNrA = 3;

			u_RowNrB = 3;
			u_ColNrB = 3;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
					std::cout<<p_MatrixRes->pData[i]<<std::endl;
				}				
			}
		}
#if 0
		/* Test Matrices: A = 4X4, B = 4X4, Res = 4X4 */
		{
			u_RowNrA = 4;
			u_ColNrA = 4;

			u_RowNrB = 4;
			u_ColNrB = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					//p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X6, B = 6X8, Res = 5X8 */
		{
			u_RowNrA = 5;
			u_ColNrA = 6;

			u_RowNrB = 6;
			u_ColNrB = 8;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576,
				7906.8587,	   748,		  790,   144.6667,		   -6.789,           66.4,
				7906.8587,	   748,		  790,   144.6667,		    0.17896,          -.0000998
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatrices(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					//p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}			
			}
		}		

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif
#endif

		fclose(fp);

		/* Checks on global data */
		check_global_data();			
			
		}
	}
}

void TEST_CLASS_CML_MTRX::test_CML_v_MultiplyMatrices2x2(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices2x2_1   "test_001_CML_v_MultiplyMatrices2x2_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices2x2_1   "test_001_CML_v_MultiplyMatrices2x2_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices2x2_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;

		int dataIndex = 0;

		/* Test Matrices: A = 2X2, B = 2X2, Res = 2X2 */
		{
			u_RowNrA = 2;
			u_ColNrA = 2;

			u_RowNrB = 2;
			u_ColNrB = 2;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_multiplyMatrices2x2(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)
					
					std::cout<<"2X2"<<std::endl;
				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
					std::cout<<p_MatrixRes->pData[i]<<std::endl;
				}				
			}
		}

		/* Test Matrices: A = 2X2, B = 2X2, Res = 2X2 */
		{
			u_RowNrA = 2;
			u_ColNrA = 2;

			u_RowNrB = 2;
			u_ColNrB = 2;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576,
				7906.8587,	   748,		  790,   144.6667,		   -6.789,           66.4,
				7906.8587,	   748,		  790,   144.6667,		    0.17896,          -.0000998
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_multiplyMatrices2x2(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
					std::cout<<p_MatrixRes->pData[i]<<std::endl;
				}			
			}
		}		

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

		fclose(fp);

		/* Checks on global data */
		check_global_data();			
			
		}
	}
}


void TEST_CLASS_CML_MTRX::test_CML_v_MultiplyMatrices3x3(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices3x3_1   "test_001_CML_v_MultiplyMatrices3x3_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices3x3_1   "test_001_CML_v_MultiplyMatrices3x3_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrices3x3_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;

		int dataIndex = 0;

		/* Test Matrices: A = 3X3, B = 3X3, Res = 3X3 */
		{
			u_RowNrA = 3;
			u_ColNrA = 3;

			u_RowNrB = 3;
			u_ColNrB = 3;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

		     const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_multiplyMatrices3x3(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)
				
				float32 data[10];
				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					data[i] = p_MatrixRes->pData[i];
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
					std::cout<<p_MatrixRes->pData[i]<<std::endl;
				}				
			}
		}

		/* Test Matrices: A = 3X3, B = 3X3, Res = 3X3 */
		{
			u_RowNrA = 3;
			u_ColNrA = 3;

			u_RowNrB = 3;
			u_ColNrB = 3;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576,
				7906.8587,	   748,		  790,   144.6667,		   -6.789,           66.4,
				7906.8587,	   748,		  790,   144.6667,		    0.17896,          -.0000998
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_multiplyMatrices3x3(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)
					
				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
					std::cout<<p_MatrixRes->pData[i]<<std::endl;
				}			
			}
		}		

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

		fclose(fp);

		/* Checks on global data */
		check_global_data();			
			
		}
	}
}

void TEST_CLASS_CML_MTRX::test_CML_v_MultiplyMatricesToSymResult(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatricesToSymResult_1   "test_001_CML_v_MultiplyMatricesToSymResult_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatricesToSymResult_1   "test_001_CML_v_MultiplyMatricesToSymResult_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatricesToSymResult_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_MultiplyMatricesToSymResult(p_MatrixRes, p_MatrixA, p_MatrixB);
			
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

		/* Test Matrices: A = 4X4, B = 4X4, Res = 4X4 */
		{
			u_RowNrA = 4;
			u_ColNrA = 4;

			u_RowNrB = 4;
			u_ColNrB = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatricesToSymResult(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X6, B = 6X8, Res = 5X8 */
		{
			u_RowNrA = 5;
			u_ColNrA = 6;

			u_RowNrB = 6;
			u_ColNrB = 8;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576,
				7906.8587,	   748,		  790,   144.6667,		   -6.789,           66.4,
				7906.8587,	   748,		  790,   144.6667,		    0.17896,          -.0000998
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatricesToSymResult(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_CML_v_MultiplyMatrixWithTranspose(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrixWithTranspose_1   "test_001_CML_v_MultiplyMatrixWithTranspose_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrixWithTranspose_1   "test_001_CML_v_MultiplyMatrixWithTranspose_out_msvc.csv"		
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_v_MultiplyMatrixWithTranspose_1, "w+");	
		PRINT_TEST_CASE(__FUNCTION__)

		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		uint32			u_ColNrA, u_RowNrA, u_ColNrB, u_RowNrB;
		float32			*p_f_MtrxDataA, *p_f_MtrxDataB, *p_f_MtrxDataRes;
		CML_t_Matrix	*p_MatrixA, *p_MatrixB, *p_MatrixRes, CML_t_Matrix_structA, CML_t_Matrix_structB, CML_t_Matrix_structRes;

		{
			/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		p_MatrixA   = &CML_t_Matrix_structA;
		p_MatrixB   = &CML_t_Matrix_structB;
		p_MatrixRes = &CML_t_Matrix_structRes;
				
#ifdef LINKED_LIST_PARSER
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = CML_v_MultiplyMatrixWithTranspose(p_MatrixRes, p_MatrixA, p_MatrixB);
			
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

		/* Test Matrices: A = 4X4, B = 4X4, Res = 4X4 */
		{
			u_RowNrA = 4;
			u_ColNrA = 4;

			u_RowNrB = 4;
			u_ColNrB = 4;
							
			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataB   = &data_log_buffer[1016];
			p_f_MtrxDataRes = &data_log_buffer[1032];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				1.f,   0.f, 134.f,   0.f, 
				4.f,  32.f, -80.f,   6.f,
				5.f,  40.f,  75.f,  -7.f,
				6.f,  48.f,  90.f, 144.f,
			};

			const float B[]  = 
			{  
				 -16.f,     0.f,    30.f, 670.f, 
				47.88f,  -732.f,   -10.f,   0.f,
				   5.f,   340.f,  -275.f, 105.f,
				   6.f,  -148.f,    90.f, 144.f,
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatrixWithTranspose(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 1)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
				}				
			}
		}

		/* Test Matrices: A = 5X6, B = 6X8, Res = 5X8 */
		{
			u_RowNrA = 5;
			u_ColNrA = 6;

			u_RowNrB = 6;
			u_ColNrB = 6;

			p_f_MtrxDataA   = &data_log_buffer[1000];
			p_f_MtrxDataA   = &data_log_buffer[1030];
			p_f_MtrxDataRes = &data_log_buffer[1078];

			CML_t_Matrix_structA   = CML_a_InitMatrixHeader(u_ColNrA, u_RowNrA, p_f_MtrxDataA);
			CML_t_Matrix_structB   = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrB, p_f_MtrxDataB);
			CML_t_Matrix_structRes = CML_a_InitMatrixHeader(u_ColNrB, u_RowNrA, p_f_MtrxDataRes);

			const float A[]  = 
			{  
				      100,	 70.99,		   53,		  467,			   0,			  34.897,	
				     4000,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			   0,		   553.12345,
				    79879,		48,	   90.001,		 9144,		       0,			 0.00035,
				-806.8587,	   748,		  790,		  144,		-156.789,           66.00998
			}; 

			const float B[]  = 
			{  
				      430,	 70.99,		   53,		 4467,			   0,			  34.897,	
				     4450,	  -302,			0,			0,		     685,			-7.00033,
				   -5.003,		40,		  705,	      230,			9880,		   553.12345,
				     7679,		48,	 -950.001,		 9144,		    1340,		 -1230.00035,
				7906.8587,	   748,		  790,   144.6667,		-156.789,          666.00998,
				7906.8587,	   748,		  790,   144.6667,		    8.79,         -445.34576				
			};

			memcpy(p_MatrixA->pData, A, (p_MatrixA->Desc.row*p_MatrixA->Desc.col)*4);
			memcpy(p_MatrixB->pData, B, (p_MatrixB->Desc.row*p_MatrixB->Desc.col)*4);
						
			{
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);			

				GET_CLOCK()
				CML_v_MultiplyMatrixWithTranspose(p_MatrixRes, p_MatrixA, p_MatrixB);
				CALCULATE_CYLES(__FUNCTION__,u_RowNrA, u_ColNrA, 2)

				for (int i = 0; i < p_MatrixRes->Desc.row * p_MatrixRes->Desc.col; i++)		
				{
					p_CsvDataOut.value[dataIndex++] = p_MatrixRes->pData[i];
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

void TEST_CLASS_CML_MTRX::test_static_assert(int doIt)
{
	if (doIt) 
	{
		float32 x, result;
		result = 0.0f;
		x = 100.0f;
		float32 y = 10.0f;	// assigning 0 to induce error, to check for static asserts.

		printf("static assert");
		CML_STATIC_ASSERT( sizeof(y) < 5, size_mismatch);
#if 0
		CML_STATIC_ASSERT( sizeof(y) < 4, size_mismatch_0);	// induce compile time error
#endif
		result = x/y;
	}
}




/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
