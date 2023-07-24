/*****************************************************************************/
/*                            CML Target Test Script                         */
/*****************************************************************************/
/*
*    Filename: test_cml_stl_cmath.cpp
*    Author: uidp1547
*    Generated on: 20-June-2016 15:43:28
*/
/*****************************************************************************/
/* Environment Definition                                                    */
/*****************************************************************************/

/* Include files from software under test */

extern "C" {
#include "cml_ext.h"
}

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
#include <cml_stl_cmath.h>




#define TEST_SCRIPT_GENERATOR 2


/* The default value used for test script variables and stub returns*/
#define DEFAULT_VALUE 0

#include "csv_parser.h"

/* Test Log file */
extern FILE *fpTest;

#ifndef LINKED_LIST_PARSER
extern float data_log_buffer[1000000];
#endif


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
//extern float32 CML_f_PowToDB(float32 f_ratio);
//extern float32 CML_f_MagToDB(float32 f_ratio);
extern CML_t_Matrix CML_a_InitMatrixHeader(uint32 ColNr, uint32 RowNr, float32* p_f_MtrxData);
//extern float32 GDB_cos32(float32 f_angle);
extern float32 GDB_sin32(float32 f_angle);
//extern float32 GDB_tan32s(float32 f_angle);
extern float32 GDB_tan32(float32 f_angle);
extern float32 GDBcos_52(float32 f_angle);
extern float32 GDBsin_52(float32 f_angle);
extern float32 GDBtan_56s(float32 f_angle);
extern float32 GDBtan_52(float32 f_angle);
//extern float32 GDBatan_66(float32 x);
extern float32 GDBacos_66(float32 f_cos);
extern float32 GDBasin_66(float32 f_sin);
extern float32 GDBexp_power(float32 f_base, uint32 u_power);
extern float32 GDBexp_100s(float32 f_power);
extern float32 GDBexp_100(float32 f_power);
//extern float32 GDBatan2_66(float32 y, float32 x);
extern float32 GDBexp(float32 f_power);
extern void GDBsincos(float32 f_val, float32* p_sin, float32* p_cos);
float32 CML_f_ModTrig(float32 x, float32 y);
//float32 CML_f_SqrtApprox(float32 x);
//float32 CML_f_fastlog10(float32 x);

extern void CSV_FreeCsvData (csv_data_t *a_Data);

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
	//* No global data */
}

/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_STL_CMATH
{
public:
	/* Prototypes for test functions */
	void run_tests_stl_cmath();
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
	void test_GDB_cos32(int);
	void test_GDB_sin32(int);
	void test_GDB_tan32s(int);
	void test_GDB_tan32(int);
	void test_GDBcos_52(int);
	void test_GDBsin_52(int);
	void test_GDBtan_56s(int);
	void test_GDBtan_52(int);
	void test_GDBsincos(int);
	void test_GDBatan_66(int);
	void test_GDBacos_66(int);
	void test_GDBasin_66(int);
	void test_GDBexp_power(int);
	void test_GDBexp_100s(int);
	void test_GDBexp_100(int);
	void test_GDBatan2_66(int);
	void test_GDBexp(int);
	void test_CML_sin66_Core(int);
	void test_CML_cos66_Core(int);
	void test_CML_sin66(int);
	void test_CML_cos66(int);
	void test_tanh58(int);
	void test_CML_sin33_Core(int);
	void test_CML_cos33_Core(int);

};


/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_stl_cmath(void)
{
	TEST_CLASS_STL_CMATH test_object;

	std::cout << "******** Start Testing: STL cmath Library functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: STL cmath Library functions ********\n\n");

	test_object.run_tests_stl_cmath();

	std::cout << "End of Testing: STL cmath Library functions\n\n";
	fprintf(fpTest, "End of Testing: STL cmath Library functions\n\n");

	return;

}


/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_STL_CMATH::run_tests_stl_cmath()
{
	test_GDB_cos32(1);
	test_GDB_sin32(1);
	test_GDB_tan32(1);
	test_GDBcos_52(1);
	test_GDBsin_52(1);	
	test_GDBtan_52(1);
	test_GDBsincos(1);
	test_GDBatan_66(1);
	test_GDBacos_66(1);
	test_GDBasin_66(1);
	test_GDBexp_power(1);
	test_GDBexp_100(1);
	test_GDBatan2_66(1);
	test_GDBexp(1);
	test_CML_sin66(1);
	test_CML_cos66(1);
	test_CML_sin66_Core(1);
	test_CML_cos66_Core(1);	
	test_CML_sin33_Core(1);
	test_CML_cos33_Core(1);	
	test_tanh58(1);
}

/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/
void TEST_CLASS_STL_CMATH::test_GDB_cos32(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM	
		#define TEST_CML_VECTOR_CSVOUT_GDB_cos32_ZERO    "test_stl_001_GDB_cos32_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_cos32_ZERO    "test_stl_001_GDB_cos32_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_cos32_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_cos32(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDB_cos32(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDB_sin32(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM	
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin32_ZERO    "test_stl_001_GDB_sin32_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin32_ZERO    "test_stl_001_GDB_sin32_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_sin32_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_sin32(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDB_sin32(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDB_tan32(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_TAN32_ZERO    "test_stl_001_GDB_tan32_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_TAN32_ZERO    "test_stl_001_GDB_tan32_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_TAN32_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_tan32(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDB_tan32(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBcos_52(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_cos52_ZERO    "test_stl_001_GDB_cos52_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_cos52_ZERO    "test_stl_001_GDB_cos52_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_cos52_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBcos_52(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBcos_52(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBsin_52(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin52_ZERO    "test_stl_001_GDB_sin52_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin52_ZERO    "test_stl_001_GDB_sin52_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_sin52_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBsin_52(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBsin_52(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBatan_66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_atan66_ZERO    "test_stl_001_GDB_atan66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_atan66_ZERO    "test_stl_001_GDB_atan66_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_atan66_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -10; angle <= 10; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBatan_66(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -10; angle <= 10; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBatan_66(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBexp(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_Exp_1   "test_stl_001_GDB_Exp_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDB_Exp_2   "test_stl_002_GDB_Exp_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDB_Exp_3   "test_stl_003_GDB_Exp_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_Exp_1   "test_stl_001_GDB_Exp_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDB_Exp_2   "test_stl_002_GDB_Exp_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDB_Exp_3   "test_stl_003_GDB_Exp_out_msvc.csv"
#endif

		#define FRACTIONAL_LIMIT 0.00000000001
		#define DECIMAL_LIMIT 10000000000
		#define STEP_SIZE 0.001

		{
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
			FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_Exp_1, "w+");
			/* input CSV data, linked list node*/
			/* CSV parser return value for result values file */
			sint32 i_CsvRetOut = -1;
			/* CSV parser return value for input values file */
			sint32 i_CsvRetIn = -1;
			float32 angle;		

			/* Set global data */
			initialise_global_data();
			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
			for ( angle = 0.1; angle >= FRACTIONAL_LIMIT; angle *= 0.1)
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);
				*(temp_p_CsvDataOut->value) = GDBexp(angle);
				temp_p_CsvDataOut->next = NULL;

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
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;
			for ( angle = 0.1; angle >= FRACTIONAL_LIMIT; angle *= 0.1)
			{			
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);
				p_CsvDataOut.value[dataIndex] = GDBexp(angle);
				dataIndex++;
			}

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

			fclose(fp);
			/* Checks on global data */
			check_global_data();		
		}

		{
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
			FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_Exp_2, "w+");
			/* input CSV data, linked list node*/
			/* CSV parser return value for result values file */
			sint32 i_CsvRetOut = -1;
			/* CSV parser return value for input values file */
			sint32 i_CsvRetIn = -1;
			float32 angle;		

			/* Set global data */
			initialise_global_data();
			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
			for ( angle = 1; angle < DECIMAL_LIMIT; angle *= 10)
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);
				*(temp_p_CsvDataOut->value) = GDBexp(angle);
				temp_p_CsvDataOut->next = NULL;

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
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;
			for ( angle = 1; angle < DECIMAL_LIMIT; angle *= 10)
			{			
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);
				p_CsvDataOut.value[dataIndex] = GDBexp(angle);
				dataIndex++;
			}

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

			fclose(fp);
			/* Checks on global data */
			check_global_data();		
		}

		{
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
			FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_Exp_3, "w+");
			/* input CSV data, linked list node*/
			/* CSV parser return value for result values file */
			sint32 i_CsvRetOut = -1;
			/* CSV parser return value for input values file */
			sint32 i_CsvRetIn = -1;
			float32 angle;		

			/* Set global data */
			initialise_global_data();
			/* Set expected values for global data checks */
			initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
			for ( angle = 0.001; angle < 1; angle += 0.001)
			{
				csv_data_float_t *temp_p_CsvDataOut = NULL;
				temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
				temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
				temp_p_CsvDataOut->len = sizeof(float32);
				*(temp_p_CsvDataOut->value) = GDBexp(angle);
				temp_p_CsvDataOut->next = NULL;

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
			i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

			while(p_CsvDataOut != NULL)
			{
				csv_data_float_t *temp_p_CsvDataOut_free = NULL;
				temp_p_CsvDataOut_free = p_CsvDataOut;
				p_CsvDataOut = p_CsvDataOut->next;
				free(temp_p_CsvDataOut_free);
			}
#else
			int dataIndex = 0;
			for ( angle = 0.001; angle < 1; angle += 0.001)
			{			
				p_CsvDataOut.value = data_log_buffer;
				p_CsvDataOut.len = sizeof(float32);
				p_CsvDataOut.value[dataIndex] = GDBexp(angle);
				dataIndex++;
			}

			p_CsvDataOut.dataBufferSize = dataIndex;

			/* parse CSV values for expected results */
			i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

			fclose(fp);
			/* Checks on global data */
			check_global_data();		
		}
	}
}

void TEST_CLASS_STL_CMATH::test_GDBtan_52(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_TAN52_ZERO    "test_stl_001_GDBtan_52_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_TAN52_ZERO    "test_stl_001_GDBtan_52_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_TAN52_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBtan_52(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBtan_52(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBsincos(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_SINCOS_ZERO    "test_stl_001_GDBsincos_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_SINCOS_ZERO    "test_stl_001_GDBsincos_out_msvc.csv"
#endif

		float32 tempSine, tempCos;

		float32 *p_sine = &tempSine;
        float32 *p_cos  = &tempCos;
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_SINCOS_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			GDBsincos(angle, p_sine, p_cos);
			*(temp_p_CsvDataOut->value) = *p_sine;
			temp_p_CsvDataOut->next = NULL;

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

			csv_data_float_t *temp_p_CsvDataOut2 = NULL;
			temp_p_CsvDataOut2 =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut2->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut2->len = sizeof(float32);
			*(temp_p_CsvDataOut2->value) = *p_cos;
			temp_p_CsvDataOut2->next = NULL;

			{
				current_p_CsvDataOut->next = temp_p_CsvDataOut2;
				current_p_CsvDataOut = current_p_CsvDataOut->next;
			}

		}
		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			GDBsincos(angle, p_sine, p_cos);
			p_CsvDataOut.value[dataIndex]   = *p_sine;
			p_CsvDataOut.value[++dataIndex] = *p_cos;
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBasin_66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_ASIN66_ZERO    "test_stl_001_GDBasin_66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_ASIN66_ZERO    "test_stl_001_GDBasin_66_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_ASIN66_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -10; angle <= 10; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBasin_66(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -10; angle <= 10; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBasin_66(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBacos_66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_ACOS66_ZERO    "test_stl_001_GDBacos_66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_ACOS66_ZERO    "test_stl_001_GDBacos_66_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_ACOS66_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -10; angle <= 10; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBacos_66(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -10; angle <= 10; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBacos_66(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBexp_100(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_EXP100_ZERO    "test_stl_001_GDBexp_100_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_EXP100_ZERO    "test_stl_001_GDBexp_100_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_EXP100_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -100; angle <= 75; angle += 1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBexp_100(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -100; angle <= 75; angle += 1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBexp_100(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBexp_power(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_EXPPOWER_ZERO    "test_stl_001_GDBexp_power_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_EXPPOWER_ZERO    "test_stl_001_GDBexp_power_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_EXPPOWER_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 f_angle;
		uint32  u_power;

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( f_angle = -500; f_angle <= 500; f_angle += 10)
		for ( u_power = 0; u_power <= 10; u_power += 1)	
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBexp_power(f_angle, u_power);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( f_angle = -500; f_angle <= 500; f_angle += 10)
		for ( u_power = 0; u_power <= 10; u_power += 1)	
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = GDBexp_power(f_angle, u_power);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_GDBatan2_66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_ATAN2_66_ZERO    "test_stl_001_GDBatan2_66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_ATAN2_66_ZERO    "test_stl_001_GDBatan2_66_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_ATAN2_66_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 f_xaxis, f_yaxis;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( f_yaxis = -100; f_yaxis <= 100; f_yaxis += 1)
		for ( f_xaxis = -100; f_xaxis <= 100; f_xaxis += 1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBatan2_66(f_yaxis, f_xaxis);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( f_yaxis = -100; f_yaxis <= 100; f_yaxis += 1)
		for ( f_xaxis = -100; f_xaxis <= 100; f_xaxis += 1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			//p_CsvDataOut.value[dataIndex] = GDBatan2_66(f_yaxis, f_xaxis);
			p_CsvDataOut.value[dataIndex] = cml::atan2(f_yaxis, f_xaxis);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_CML_sin66_Core(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_ZERO    "test_stl_001_CML_sin66_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_ZERO    "test_stl_001_CML_sin66_Core_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sin66_Core(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_sin66_Core(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_CML_sin66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_ZERO    "test_stl_001_CML_sin66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_ZERO    "test_stl_001_CML_sin66_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin66_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle, sine_result, Expected_sine_result;
				
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sin66(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_sin66(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
		
	}
}

void TEST_CLASS_STL_CMATH::test_CML_cos66_Core(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_ZERO    "test_stl_001_CML_cos66_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_ZERO    "test_stl_001_CML_cos66_Core_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos66_Core(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_cos66_Core(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_CML_cos66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_ZERO    "test_stl_001_CML_cos66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_ZERO    "test_stl_001_CML_cos66_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos66_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle, cos_result, Expected_cos_result;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos66(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_cos66(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_CML_sin33_Core(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_ZERO    "test_stl_001_CML_sin33_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_ZERO    "test_stl_001_CML_sin33_Core_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sin33_Core(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_sin33_Core(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_CML_cos33_Core(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_ZERO    "test_stl_001_CML_cos33_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_ZERO    "test_stl_001_CML_cos33_Core_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle;
		float32 val;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos33_Core(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -4*CML_f_Pi; angle <= 4*CML_f_Pi; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_cos33_Core(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);		
		check_global_data();		
	}
}

void TEST_CLASS_STL_CMATH::test_tanh58(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_tanh58_ZERO    "test_stl_001_CML_tanh58_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_tanh58_ZERO    "test_stl_001_CML_tanh58_out_msvc.csv"
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_tanh58_ZERO, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		float32 angle, sine_result, Expected_sine_result;		

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		for ( angle = -10; angle <= 10; angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_tanh58(angle);
			temp_p_CsvDataOut->next = NULL;

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
		i_CsvRetOut = CSV_WriteData_float32(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		for ( angle = -10; angle <= 10; angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			p_CsvDataOut.value[dataIndex] = CML_tanh58(angle);
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_float32(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();		
	}
}

/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
