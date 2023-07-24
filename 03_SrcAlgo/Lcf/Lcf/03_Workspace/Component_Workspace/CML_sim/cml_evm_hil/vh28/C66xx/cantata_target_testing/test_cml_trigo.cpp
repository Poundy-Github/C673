/*****************************************************************************/
/*                            Cantata Test Script                            */
/*****************************************************************************/
/*
*    Filename: test_cml_trigo.cpp
*    Author: uidp1547
*    Generated on: 23-Aug-2016 15:43:28
*    Generated from: test_cml_trigo.c
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
extern float32 GDB_cos32(float32 f_angle);
extern float32 GDB_sin32(float32 f_angle);
extern float32 GDB_tan32s(float32 f_angle);
extern float32 GDB_tan32(float32 f_angle);
extern float32 GDBcos_52(float32 f_angle);
extern float32 GDBsin_52(float32 f_angle);
extern float32 CML_f_tan66(float32 f_angle);
//extern float32 GDBatan_66(float32 x);
extern float32 GDBacos_66(float32 f_cos);
extern float32 GDBasin_66(float32 f_sin);
//extern float32 GDBatan2_66(float32 y, float32 x);
extern void GDBsincos(float32 f_val, float32* p_sin, float32* p_cos);
float32 CML_f_ModTrig(float32 x, float32 y);
extern float32 CML_f_Cos69Core(float32 x);

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

/* This function prints the data contained in the CArray object to a file. */
static void check__PrintValue_to_File(float Value, FILE *fpTest)
{
	fprintf(fpTest, ",%f,", Value);
}

static void check__PrintValue_to_File(int Value, FILE *fpTest)
{
	fprintf(fpTest, ",%i,", Value);
}

static void check__PrintValue_to_File(short Value, FILE *fpTest)
{
	fprintf(fpTest, ",%i,", Value);
}

static void check__PrintValue_to_File(char Value, FILE *fpTest)
{
	fprintf(fpTest, ",%i,", Value);
}

static void check__PrintValue_to_File(long long int Value, FILE *fpTest)
{
	fprintf(fpTest, ",%llu,", Value);
}


/* This function prints the data contained in the CArray object to console. */
static void check__PrintValue_to_console(float Value)
{
	std::cout << Value<<"\t\t";
}

static void check__PrintValue_to_console(int Value)
{
	std::cout <<Value<<"\t\t";
}

static void check__PrintValue_to_console(short Value)
{
	std::cout << Value<<"\t\t";
}

static void check__PrintValue_to_console(char Value)
{
	std::cout << Value<<"\t\t";
}

static void check__PrintValue_to_console(long long int Value)
{
	std::cout << Value<<"\t\t";
}



/*****************************************************************************/
/* Test class declaration                                                    */
/*****************************************************************************/
class TEST_CLASS_CML_TRIGO
{
public:
	
	/* Prototypes for test functions */
	void run_tests_cml_trigo();
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
	void test_CML_f_tan66(int);
	void test_GDBsincos(int);
	void test_GDBatan_66(int);
	void test_GDBacos_66(int);
	void test_GDBasin_66(int);
	void test_GDBatan2_66(int);
	void test_CML_sin66_Core(int);
	void test_CML_cos66_Core(int);
	void test_CML_sin66(int);
	void test_CML_cos66(int);
	void test_tanh58(int);
	void test_CML_sin33_Core(int);
	void test_CML_cos33_Core(int);
	void test_CML_atan18(int);
	void test_CML_f_Sine69Core(int);
	void test_CML_f_Cosine69Core(int);
};

/*****************************************************************************/
/* Program Entry Point                                                       */
/*****************************************************************************/
void test_cml_trigo(void)
{
	TEST_CLASS_CML_TRIGO test_object;

	std::cout << "******** Start Testing: CML Trigo functions ********\n\n";
	fprintf(fpTest, "******** Start Testing: CML Trigo functions ********\n\n");

	test_object.run_tests_cml_trigo();

	std::cout << "End of Testing: CML Trigo functions\n\n";
	fprintf(fpTest, "End of Testing: CML Trigo functions\n\n");

	return;

}

/*****************************************************************************/
/* Test Control                                                              */
/*****************************************************************************/
/* run_tests() contains calls to the individual test cases, you can turn test*/
/* cases off by adding comments*/
void TEST_CLASS_CML_TRIGO::run_tests_cml_trigo()
{
	test_CML_atan18(1);
    test_GDB_cos32(1);
	test_GDB_sin32(1);
	test_GDBcos_52(1);
	test_GDBsin_52(1);
    //test_GDB_tan32s(1);
	test_GDB_tan32(1);	
	test_CML_f_tan66(1);
	test_GDBsincos(1);   
	test_GDBacos_66(1);
	test_GDBasin_66(1);
	test_GDBatan_66(1);
	test_GDBatan2_66(1);
	test_CML_sin66(1);
	test_CML_cos66(1);
	test_CML_f_Sine69Core(1);
	test_CML_f_Cosine69Core(1);
	test_CML_sin66_Core(1);
	test_CML_cos66_Core(1);
	test_tanh58(1);
	test_CML_sin33_Core(1);
	test_CML_cos33_Core(1); 
}


/*****************************************************************************/
/* Test Cases                                                                */
/*****************************************************************************/

void TEST_CLASS_CML_TRIGO::test_CML_atan18(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */	
#ifdef TARGET_PLATFORM
		#define	TEST_CML_VECTOR_CSVOUT_CML_atan18_1  "test_001_CML_atan18_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_atan18_2  "test_002_CML_atan18_out_target.csv"	
	    #define	TEST_CML_VECTOR_CSVOUT_CML_atan18_3  "test_003_CML_atan18_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_atan18_1  "test_001_CML_atan18_out_msvc.csv"	
	    #define	TEST_CML_VECTOR_CSVOUT_CML_atan18_2  "test_002_CML_atan18_out_msvc.csv"
		#define	TEST_CML_VECTOR_CSVOUT_CML_atan18_3  "test_003_CML_atan18_out_msvc.csv"		
#endif

		float32 f_power;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut;
#else
		csv_data_float_t p_CsvDataOut;
#endif
		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_atan18_1, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
	    float32 angle, angle_x, angle_y, sine_result, Expected_sine_result;
		int counter = 0;	

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();
			
#ifdef LINKED_LIST_PARSER
		for ( angle = 0.00001; angle <= 1-0.00001; angle += 0.00001) 
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_atan18(1, angle);
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
		float32 rel_err = 0;
		float32 max_err = 0;
		float32 input_err = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = 0.00001; angle <= 1-0.00001; angle += 0.00001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			float32 ref_fout = atan2(1,angle);
			float32 test_out = CML_atan18(1, angle);
			float32 abs_err = abs(ref_fout - test_out);
			rel_err = abs(abs_err/ref_fout);
			if (rel_err >= max_err)
			{
				max_err = rel_err;
				input_err = angle;
			}
			
			p_CsvDataOut.value[dataIndex] = test_out;

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_atan18 ---> ";		
		fprintf(fpTest, "CML_atan18 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(angle);
		check__PrintValue_to_File(angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif		
				
		fclose(fp);

        /* Checks on global data */
        check_global_data();


		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_atan18_2, "w+");
			
#ifdef LINKED_LIST_PARSER
		for ( angle = -100; angle <= 100; angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_atan18(1, angle);
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
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -100; angle <= 100; angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_atan18(1, angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_atan18 ---> ";		
		fprintf(fpTest, "CML_atan18 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(angle);
		check__PrintValue_to_File(angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif		
				
		fclose(fp);

        /* Checks on global data */
        check_global_data();


		/* **********************************************************************
		   *                         Test case 3                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_atan18_3, "w+");
		/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		counter = 0;

#ifdef LINKED_LIST_PARSER
		for ( angle_x = -100; angle_x <= 100; angle_x += 1)
		for ( angle_y = -100; angle_y <= 100; angle_y += 1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			if(angle_x == 0 && angle_y == 0)
			{
				*(temp_p_CsvDataOut->value) = 0;
			}
			else
			{
				*(temp_p_CsvDataOut->value) = CML_atan18(angle_x,angle_y);
			}

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
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 3 \n";		
		fprintf(fpTest, "Test case 3 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle_x = -100; angle_x <= 100; angle_x += 1)
		for ( angle_y = -100; angle_y <= 100; angle_y += 1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);			

			if(angle_x == 0 && angle_y == 0)
			{
				p_CsvDataOut.value[dataIndex] = 0;
			}
			else
			{

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

				p_CsvDataOut.value[dataIndex] = CML_atan18(angle_x,angle_y);


#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_atan18 ---> ";		
		fprintf(fpTest, "CML_atan18 ---> ");
		std::cout << "Test case 3---> ";
		fprintf(fpTest, "Test case 3 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(angle_y);
		check__PrintValue_to_File(angle_y, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			}

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_GDB_cos32(int doIt)
{
	if (doIt) 
	{
#ifdef TARGET_PLATFORM
		#define	TEST_CML_VECTOR_CSVOUT_GDB_cos32_1  "test_001_GDB_cos32_out_target.csv"
		#define	TEST_CML_VECTOR_CSVOUT_GDB_cos32_2  "test_002_GDB_cos32_out_target.csv"
#else
		#define	TEST_CML_VECTOR_CSVOUT_GDB_cos32_1  "test_001_GDB_cos32_out_msvc.csv"
		#define	TEST_CML_VECTOR_CSVOUT_GDB_cos32_2  "test_002_GDB_cos32_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_cos32_1, "w+");

		/* Test case data declarations */
		float32 f_angle;
		float32 expected_returnValue;
		float32 returnValue;

		/* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif
		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;   

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */
#ifdef LINKED_LIST_PARSER			
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_cos32(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDB_cos32(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDB_cos32 ---> ";		
		fprintf(fpTest, "GDB_cos32 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_cos32_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_cos32(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDB_cos32(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDB_cos32 ---> ";		
		fprintf(fpTest, "GDB_cos32 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_GDB_sin32(int doIt)
{
	if (doIt) 
	{    
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin32_1    "test_001_GDB_sin32_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin32_2    "test_002_GDB_sin32_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin32_1    "test_001_GDB_sin32_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDB_sin32_2    "test_002_GDB_sin32_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_sin32_1, "w+");

		float32 f_angle;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
		csv_data_t p_CsvDataOut_ref;

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif
		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;	  

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_sin32(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDB_sin32(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDB_sin32 ---> ";		
		fprintf(fpTest, "GDB_sin32 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */
		
		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDB_sin32_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_sin32(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDB_sin32(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDB_sin32 ---> ";		
		fprintf(fpTest, "GDB_sin32 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_GDBcos_52(int doIt)
{
	if (doIt) 
	{	  
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDBcos_52_1    "test_001_GDBcos_52_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBcos_52_2    "test_002_GDBcos_52_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDBcos_52_1    "test_001_GDBcos_52_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBcos_52_2    "test_002_GDBcos_52_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBcos_52_1, "w+");

		float32 f_angle;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
		csv_data_t p_CsvDataOut_ref;
	
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;	    

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBcos_52(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBcos_52(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBcos_52 ---> ";		
		fprintf(fpTest, "GDBcos_52 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		/* Test case 2 */
		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBcos_52_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBcos_52(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBcos_52(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBcos_52 ---> ";		
		fprintf(fpTest, "GDBcos_52 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_GDBsin_52(int doIt)
{
	if (doIt) 
	{	    
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDBsin_52_1    "test_001_GDBsin_52_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBsin_52_2    "test_002_GDBsin_52_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDBsin_52_1    "test_001_GDBsin_52_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBsin_52_2    "test_002_GDBsin_52_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBsin_52_1, "w+");

		float32 f_angle;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
		csv_data_t p_CsvDataOut_ref;
	
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;	    

		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBsin_52(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBsin_52(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBsin_52 ---> ";		
		fprintf(fpTest, "GDBsin_52 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */
		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBsin_52_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBsin_52(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBsin_52(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBsin_52 ---> ";		
		fprintf(fpTest, "GDBsin_52 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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





void TEST_CLASS_CML_TRIGO::test_GDB_tan32(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define	TEST_CML_TRIGO_CSVOUT_GDB_tan32_1  "test_001_GDB_tan32_out_target.csv"
		#define	TEST_CML_TRIGO_CSVOUT_GDB_tan32_2  "test_002_GDB_tan32_out_target.csv"
#else
		#define	TEST_CML_TRIGO_CSVOUT_GDB_tan32_1  "test_001_GDB_tan32_out_msvc.csv"
		#define	TEST_CML_TRIGO_CSVOUT_GDB_tan32_2  "test_002_GDB_tan32_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_TRIGO_CSVOUT_GDB_tan32_1, "w+");

		/* Test case data declarations */
		float32 f_angle;
		float32 expected_returnValue;
		float32 returnValue;
	
		/* floating point tolerance */
		float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);
		/* result CSV data, linked list node*/

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;	

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_tan32(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		int dataIndex = 0;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDB_tan32(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDB_tan32 ---> ";		
		fprintf(fpTest, "GDB_tan32 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_TRIGO_CSVOUT_GDB_tan32_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDB_tan32(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		dataIndex = 0;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDB_tan32(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */


#ifdef ENABLE_PROFILER
		std::cout << "GDB_tan32 ---> ";		
		fprintf(fpTest, "GDB_tan32 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_CML_f_tan66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define	TEST_CML_TRIGO_CSVOUT_CML_f_tan66_1  "test_001_CML_f_tan66_out_target.csv"
		#define	TEST_CML_TRIGO_CSVOUT_CML_f_tan66_2  "test_002_CML_f_tan662_out_target.csv"
#else
		#define	TEST_CML_TRIGO_CSVOUT_CML_f_tan66_1  "test_001_CML_f_tan66_out_msvc.csv"
		#define	TEST_CML_TRIGO_CSVOUT_CML_f_tan66_2  "test_002_CML_f_tan66_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_TRIGO_CSVOUT_CML_f_tan66_1, "w+");

		/* Test case data declarations */
		float32 f_angle;
		float32 expected_returnValue;
		float32 returnValue;

		/* floating point tolerance */
		float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);
		/* result CSV data, linked list node*/

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

#ifdef LINKED_LIST_PARSER			
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_f_tan66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		int dataIndex = 0;
		float32 rel_err_tan = 0;
        float32 max_err_tan = 0;
		float32 input_err_tan = 0;

		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{			
		 p_CsvDataOut.value = data_log_buffer;
		 p_CsvDataOut.len = sizeof(float32);

		 float32 ref_tan_fout = tan(f_angle);
		 float32 test_tan_out;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		 test_tan_out = CML_f_tan66(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

         p_CsvDataOut.value[dataIndex]  = test_tan_out;

		 float32 abs_err_tan = abs(ref_tan_fout - test_tan_out);
		 rel_err_tan = abs(abs_err_tan/ref_tan_fout);
		   if (rel_err_tan >= max_err_tan)
		   {
			max_err_tan = rel_err_tan;
			input_err_tan = f_angle;
		   }
#ifdef ENABLE_PROFILER
		std::cout << "CML_f_tan66 ---> ";		
		fprintf(fpTest, "CML_f_tan66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif
		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_TRIGO_CSVOUT_CML_f_tan66_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBtan_52(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */


		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

		    float32 ref_tan_fout = tan(f_angle);
		    float32 test_tan_out;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

		 test_tan_out = CML_f_tan66(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

         p_CsvDataOut.value[dataIndex]  = test_tan_out;

		 float32 abs_err_tan = abs(ref_tan_fout - test_tan_out);
		 rel_err_tan = abs(abs_err_tan/ref_tan_fout);
		   if (rel_err_tan >= max_err_tan)
		   {
			max_err_tan = rel_err_tan;
			input_err_tan = f_angle;
		   }

#ifdef ENABLE_PROFILER
		std::cout << "CML_f_tan66 ---> ";		
		fprintf(fpTest, "CML_f_tan66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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
           

void TEST_CLASS_CML_TRIGO::test_GDBsincos(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define	TEST_CML_TRIGO_CSVOUT_GDBsincos_1 "test_001_GDBsincos_out_target.csv"
		#define	TEST_CML_TRIGO_CSVOUT_GDBsincos_2 "test_002_GDBsincos_out_target.csv"
#else
		#define	TEST_CML_TRIGO_CSVOUT_GDBsincos_1 "test_001_GDBsincos_out_msvc.csv"
		#define	TEST_CML_TRIGO_CSVOUT_GDBsincos_2 "test_002_GDBsincos_out_msvc.csv"
#endif
		
		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_TRIGO_CSVOUT_GDBsincos_1, "w+");
		float32 f_angle;

		/* Test case data declarations */
		float32 f_val = 1;
		float32 temp_s;
		float32 temp_c;
		float32* p_sin = &temp_s;
		float32* p_cos = &temp_c;
		float32 expected_temp_s;
		float32 expected_temp_c;

		/* floating point tolerance */
		float32 f_Tolerance = (float32)pow (10., -1 * FLT_DIG);
		/* result CSV data, linked list node*/

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			GDBsincos(f_angle,p_sin, p_cos);
			*(temp_p_CsvDataOut->value) = *p_sin;
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

			temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);			
			*(temp_p_CsvDataOut->value) = *p_cos;
			temp_p_CsvDataOut->next = NULL;
			
			{
				current_p_CsvDataOut->next = temp_p_CsvDataOut;
				current_p_CsvDataOut = current_p_CsvDataOut->next;
			}
				
		}
	
		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err_sin =0;
		float32 rel_err_cos =0;
		float32 max_err_sin = 0;
		float32 input_err_sin = 0;
		float32 max_err_cos = 0;
		float32 input_err_cos = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -CML_f_Pi; f_angle <= CML_f_Pi; f_angle += 0.001F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

			float32 ref_sin_fout = sin(f_angle);
			float32 ref_cos_fout = cos(f_angle);
			float32 test_sin_out ;
			float32 test_cos_out ;
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			
			GDBsincos(f_angle,p_sin, p_cos);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			test_sin_out = *p_sin;
			test_cos_out = *p_cos;
#ifdef ENABLE_PROFILER
		std::cout << "GDBsincos ---> ";		
		fprintf(fpTest, "GDBsincos ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			float32 abs_err_sin = abs(ref_sin_fout - test_sin_out);
			rel_err_sin = abs(abs_err_sin/ref_sin_fout);
			if (rel_err_sin >= max_err_sin)
			{
				max_err_sin = rel_err_sin;
				input_err_sin = f_angle;
			}

			float32 abs_err_cos = abs(ref_cos_fout - test_cos_out);
			rel_err_cos = abs(abs_err_cos/ref_cos_fout);
			if (rel_err_cos >= max_err_cos)
			{
				max_err_cos = rel_err_cos;
				input_err_cos = f_angle;
			}
			p_CsvDataOut.value[dataIndex]   = *p_sin;
			p_CsvDataOut.value[++dataIndex] = *p_cos;
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif
	
		fclose(fp);
    
		/* Checks on global data */
		check_global_data();


		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */
		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_TRIGO_CSVOUT_GDBsincos_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			GDBsincos(f_angle,p_sin, p_cos);
			*(temp_p_CsvDataOut->value) = *p_sin;
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

			temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);			
			*(temp_p_CsvDataOut->value) = *p_cos;
			temp_p_CsvDataOut->next = NULL;
			
			{
				current_p_CsvDataOut->next = temp_p_CsvDataOut;
				current_p_CsvDataOut = current_p_CsvDataOut->next;
			}
				
		}
	
		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			GDBsincos(f_angle,p_sin, p_cos);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBsincos ---> ";		
		fprintf(fpTest, "GDBsincos ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
		
			p_CsvDataOut.value[dataIndex]   = *p_sin;
			p_CsvDataOut.value[++dataIndex] = *p_cos;
			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_GDBasin_66(int doIt)
{
	if (doIt) 
	{

		/* result CSV data, linked list node*/

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		/* Test case data declarations */
		float32 f_sin;
		float32 expected_returnValue;
		float32 returnValue;
		float32 tolerance = 0.00001f;
		uint8 index;
			
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDBasin_66_TestCase_1  "test_001_GDBasin_66_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBasin_66_TestCase_2  "test_002_GDBasin_66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDBasin_66_TestCase_1  "test_001_GDBasin_66_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBasin_66_TestCase_2  "test_002_GDBasin_66_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBasin_66_TestCase_1, "w+");
		float32 f_angle;

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBasin_66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			p_CsvDataOut.value[dataIndex] = GDBasin_66(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBasin_66 ---> ";		
		fprintf(fpTest, "GDBasin_66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBasin_66_TestCase_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -10; f_angle <= 10; f_angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBasin_66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -10; f_angle <= 10; f_angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBasin_66(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBasin_66 ---> ";		
		fprintf(fpTest, "GDBasin_66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_GDBacos_66(int doIt)
{
	if (doIt) 
	{

		/* result CSV data, linked list node*/

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		/* Test case data declarations */
		float32 f_sin;
		float32 expected_returnValue;
		float32 returnValue;
		float32 tolerance = 0.00001f;
		uint8 index;
			
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDBacos_66_TestCase_1  "test_001_GDBacos_66_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBacos_66_TestCase_2  "test_002_GDBacos_66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDBacos_66_TestCase_1  "test_001_GDBacos_66_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBacos_66_TestCase_2  "test_002_GDBacos_66_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBacos_66_TestCase_1, "w+");
		float32 f_angle;

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBacos_66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			p_CsvDataOut.value[dataIndex] = GDBacos_66(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBacos_66 ---> ";		
		fprintf(fpTest, "GDBacos_66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBacos_66_TestCase_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -10; f_angle <= 10; f_angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBacos_66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -10; f_angle <= 10; f_angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBacos_66(f_angle);
			
#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBacos_66 ---> ";		
		fprintf(fpTest, "GDBacos_66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_GDBatan_66(int doIt)
{
	if (doIt) 
	{

		/* result CSV data, linked list node*/

#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut = NULL;
#else
		csv_data_float_t p_CsvDataOut;
#endif

		/* input CSV data, linked list node*/
		csv_data_t *p_CsvDataIn = NULL;
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
		/* Test case data declarations */
		float32 f_sin;
		float32 expected_returnValue;
		float32 returnValue;
		float32 tolerance = 0.00001f;
		uint8 index;

#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_GDBatan_66_TestCase_1  "test_001_GDBatan_66_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBatan_66_TestCase_2  "test_002_GDBatan_66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_GDBatan_66_TestCase_1  "test_001_GDBatan_66_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_GDBatan_66_TestCase_2  "test_002_GDBatan_66_out_msvc.csv"
#endif

		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBatan_66_TestCase_1, "w+");
		float32 f_angle;

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBatan_66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -1; f_angle <= 1; f_angle += 0.0001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			p_CsvDataOut.value[dataIndex] = GDBatan_66(f_angle);


#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBatan_66 ---> ";		
		fprintf(fpTest, "GDBatan_66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
    
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_GDBatan_66_TestCase_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -10; f_angle <= 10; f_angle += 0.01)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBatan_66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -10; f_angle <= 10; f_angle += 0.01)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBatan_66(f_angle);


#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBatan_66 ---> ";		
		fprintf(fpTest, "GDBatan_66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_GDBatan2_66(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */	
#ifdef TARGET_PLATFORM
		#define	TEST_CML_VECTOR_CSVOUT_CML_atan2_66_1  "test_001_GDB_atan2_66_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_atan2_66_2  "test_002_GDB_atan2_66_out_target.csv"	
	    #define	TEST_CML_VECTOR_CSVOUT_CML_atan2_66_3  "test_003_GDB_atan2_66_out_target.csv"		
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_atan2_66_1  "atan2_66_out_msvc.csv"	
	    #define	TEST_CML_VECTOR_CSVOUT_CML_atan2_66_2  "test_002_GDB_atan2_66_out_msvc.csv"
		#define	TEST_CML_VECTOR_CSVOUT_CML_atan2_66_3  "test_003_GDB_atan2_66_out_msvc.csv"		
#endif

		float32 f_power;
		float32 expected_returnValue;
		float32 returnValue;
		/* result CSV data, linked list node*/
#ifdef LINKED_LIST_PARSER
		csv_data_float_t *p_CsvDataOut;
#else
		csv_data_float_t p_CsvDataOut;
#endif
		csv_data_float_t *current_p_CsvDataOut = NULL;
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_atan2_66_1, "w+");
		/* input CSV data, linked list node*/
		/* CSV parser return value for result values file */
		sint32 i_CsvRetOut = -1;
		/* CSV parser return value for input values file */
		sint32 i_CsvRetIn = -1;
	    float32 angle, angle_x, angle_y, sine_result, Expected_sine_result;
		int counter = 0;	

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();
			
#ifdef LINKED_LIST_PARSER
		for ( angle = 0.00001; angle <= 1-0.00001; angle += 0.00001) 
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBatan2_66(1, angle);
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
		double max_err = 0, rel_err = 0, input_err;
		float32 angle1 ;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -1000.0; angle <= 100.0; angle += 0.1F)
		for ( angle1 = -100.0; angle1 <= 100.0; angle1 += 0.1F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			double ref_fout = atan2(angle, angle1);
			double test_out = GDBatan2_66(angle, angle1);
            double abs_err = abs(ref_fout - test_out);
			p_CsvDataOut.value[dataIndex] = test_out;
			rel_err = abs(abs_err/ref_fout);
			if (rel_err >= max_err)
			{
				max_err = rel_err;
				input_err = angle;
			}
#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBatan2_66 ---> ";		
		fprintf(fpTest, "GDBatan2_66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(angle);
		check__PrintValue_to_File(angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif		
				
		fclose(fp);

        /* Checks on global data */
        check_global_data();


		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		/* Set global data */
		initialise_global_data();

		/* Set expected values for global data checks */
		initialise_expected_global_data();

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_atan2_66_2, "w+");
			
#ifdef LINKED_LIST_PARSER
		for ( angle = -100; angle <= 100; angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = GDBatan2_66(1, angle);
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
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -100; angle <= 100; angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBatan2_66(1, angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBatan2_66 ---> ";		
		fprintf(fpTest, "GDBatan2_66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(angle);
		check__PrintValue_to_File(angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif		
				
		fclose(fp);

        /* Checks on global data */
        check_global_data();


		/* **********************************************************************
		   *                         Test case 3                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_atan2_66_3, "w+");
		/* Set global data */
    	initialise_global_data();
    	/* Set expected values for global data checks */
    	initialise_expected_global_data();

		counter = 0;

#ifdef LINKED_LIST_PARSER
		for ( angle_x = -100; angle_x <= 100; angle_x += 1)
		for ( angle_y = -100; angle_y <= 100; angle_y += 1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);

			*(temp_p_CsvDataOut->value) = GDBatan2_66(angle_x,angle_y);
			
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
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 3 \n";		
		fprintf(fpTest, "Test case 3 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle_x = -100; angle_x <= 100; angle_x += 1)
		for ( angle_y = -100; angle_y <= 100; angle_y += 1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);			

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = GDBatan2_66(angle_x,angle_y);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "GDBatan2_66 ---> ";		
		fprintf(fpTest, "GDBatan2_66 ---> ");
		std::cout << "Test case 3 ---> ";
		fprintf(fpTest, "Test case 3 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(angle_y);
		check__PrintValue_to_File(angle_y, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */
	
			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_sin66_Core(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
	
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_1    "test_001_CML_sin66_Core_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_2    "test_002_CML_sin66_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_1    "test_001_CML_sin66_Core_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_2    "test_002_CML_sin66_Core_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err_sin =0;
		float32 max_err_sin = 0;
		float32 input_err_sin = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

			float32 ref_sin_fout = sin(angle);
			float32 test_sin_out ;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			
			test_sin_out = CML_sin66_Core(angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
		p_CsvDataOut.value[dataIndex]  = test_sin_out;
		
		float32 abs_err_sin = abs(ref_sin_fout - test_sin_out);
		rel_err_sin = abs(abs_err_sin/ref_sin_fout);
		if (rel_err_sin >= max_err_sin)
		{
			max_err_sin = rel_err_sin;
			input_err_sin = angle;
		}
#ifdef ENABLE_PROFILER
		std::cout << "CML_sin66_Core ---> ";		
		fprintf(fpTest, "CML_sin66_Core ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();
			
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin66_Core_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sin66_Core(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_sin66_Core(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_sin66_Core ---> ";		
		fprintf(fpTest, "CML_sin66_Core ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_sin66(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
	
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_1    "test_001_CML_sin66_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_2    "test_002_CML_sin66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_1    "test_001_CML_sin66_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_sin66_2    "test_002_CML_sin66_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin66_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err =0;
		float32 max_err = 0;
		float32 input_err = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -  2 * CML_f_Pi; angle <= 2 * CML_f_Pi; angle += 0.001F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#if 0
			p_CsvDataOut.value[dataIndex] = CML_sin66(angle);
#else
		    float32 ref_fout = sin(angle);
			
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			float32 test_out = CML_sin66(angle);
#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = test_out;
			float32 abs_err = abs(ref_fout - test_out);
			rel_err = abs(abs_err/ref_fout);
			if (rel_err >= max_err)
			{
				max_err = rel_err;
				input_err = angle;
			}
#endif
#ifdef ENABLE_PROFILER
		std::cout << "CML_sin66 ---> ";		
		fprintf(fpTest, "CML_sin66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);

#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();
			
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin66_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sin66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_sin66(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_sin66 ---> ";		
		fprintf(fpTest, "CML_sin66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_f_Sine69Core(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */	
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sine69_Core_1    "test_001_CML_sine69_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sine69_Core_1    "test_001_CML_sine69_Core_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sine69_Core_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sine69_Core(angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err =0;
		float32 max_err = 0;
		float32 input_err = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -CML_f_Pi/4; angle <= CML_f_Pi/4; angle += 0.001F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
		    float32 ref_fout = sin(angle);
#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			float32 test_out = CML_f_Sine69Core(angle);
#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = test_out;
			float32 abs_err = abs(ref_fout - test_out);
			rel_err = abs(abs_err/ref_fout);
			if (rel_err >= max_err)
			{
				max_err = rel_err;
				input_err = angle;
			}
			
#ifdef ENABLE_PROFILER
		std::cout << "CML_sine69_Core ---> ";		
		fprintf(fpTest, "CML_sine69_Core ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_f_Cosine69Core(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */	
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_cos69_Core_1    "test_001_CML_cos69_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos69_Core_1    "test_001_CML_cos69_Core_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos69_Core_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos69_Core(angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err =0;
		float32 max_err = 0;
		float32 input_err = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = - CML_f_Pi/4; angle <= CML_f_Pi/4; angle += 0.001F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
		    float32 ref_fout = cos(angle);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			float32 test_out = CML_f_Cos69Core(angle);
#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
			p_CsvDataOut.value[dataIndex] = test_out;
			float32 abs_err = abs(ref_fout - test_out);
			rel_err = abs(abs_err/ref_fout);
			if (rel_err >= max_err)
			{
				max_err = rel_err;
				input_err = angle;
			}

#ifdef ENABLE_PROFILER
		std::cout << "CML_cos69_Core ---> ";		
		fprintf(fpTest, "CML_cos69_Core ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_cos66_Core(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */	
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_1    "test_001_CML_cos66_Core_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_2    "test_002_CML_cos66_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_1    "test_001_CML_cos66_Core_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_2    "test_002_CML_cos66_Core_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err_cos =0;
		float32 max_err_cos = 0;
		float32 input_err_cos = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

			float32 ref_cos_fout = cos(angle);
			float32 test_cos_out ;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			test_cos_out = CML_cos66_Core(angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
			float32 abs_err_cos = abs(ref_cos_fout - test_cos_out);
			rel_err_cos = abs(abs_err_cos/ref_cos_fout);
			if (rel_err_cos >= max_err_cos)
			{
				max_err_cos = rel_err_cos;
				input_err_cos = angle;
			}
			p_CsvDataOut.value[dataIndex] = test_cos_out;

#ifdef ENABLE_PROFILER
		std::cout << "CML_cos66_Core ---> ";		
		fprintf(fpTest, "CML_cos66_Core ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();
			
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos66_Core_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle < 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos66_Core(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -4*CML_f_Pi; f_angle < 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_cos66_Core(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_cos66_Core ---> ";		
		fprintf(fpTest, "CML_cos66_Core ---> ");
		std::cout << "Test case 2---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_cos66(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_1    "test_001_CML_cos66_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_2    "test_002_CML_cos66_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_1    "test_001_CML_cos66_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_cos66_2    "test_002_CML_cos66_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos66_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;
		float32 rel_err;
		float32 max_err = 0;
		float32 input_err = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -2 *CML_f_Pi; angle <= 2 *CML_f_Pi; angle += 0.001F)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
		    float32 ref_fout = cos(angle);

#ifdef ENABLE_PROFILER
		    start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			float32 test_out = CML_cos66(angle);
#ifdef ENABLE_PROFILER
		    stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */
			p_CsvDataOut.value[dataIndex] = test_out;
			float32 abs_err = abs(ref_fout - test_out);
			rel_err = abs(abs_err/ref_fout);
			if (rel_err >= max_err)
			{
				max_err = rel_err;
				input_err = angle;
			}
			 
#ifdef ENABLE_PROFILER
		std::cout << "CML_cos66 ---> ";		
		fprintf(fpTest, "CML_cos66 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();
			
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos66_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos66(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_cos66(f_angle);


#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_cos66 ---> ";		
		fprintf(fpTest, "CML_cos66 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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

void TEST_CLASS_CML_TRIGO::test_CML_sin33_Core(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM
		#define TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_1    "test_001_CML_sin33_Core_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_2    "test_002_CML_sin33_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_1    "test_001_CML_sin33_Core_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_2    "test_002_CML_sin33_Core_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_sin33_Core(angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_sin33_Core ---> ";		
		fprintf(fpTest, "CML_sin33_Core ---> ");
		std::cout << "Test case 1---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		//check__PrintValue_to_console(stop_clock);
		//check__PrintValue_to_console(start_clock);
		//check__PrintValue_to_console(overhead);
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();
			
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_sin33_Core_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_sin33_Core(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_sin33_Core(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_sin33_Core ---> ";		
		fprintf(fpTest, "CML_sin33_Core ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_CML_cos33_Core(int doIt)
{
	if (doIt) 
	{

		/* Test case data declarations */
#ifdef TARGET_PLATFORM	
		#define TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_1    "test_001_CML_cos33_Core_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_2    "test_002_CML_cos33_Core_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_1    "test_001_CML_cos33_Core_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_2    "test_002_CML_cos33_Core_out_msvc.csv"
#endif
	
		float32 f_angle;

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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */

#ifdef LINKED_LIST_PARSER
		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -CML_f_Pi; angle <= CML_f_Pi; angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_cos33_Core(angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_cos33_Core ---> ";		
		fprintf(fpTest, "CML_cos33_Core ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();
			
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */

		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_cos33_Core_2, "w+");

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_cos33_Core(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -4*CML_f_Pi; f_angle <= 4*CML_f_Pi; f_angle += 0.1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_cos33_Core(f_angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_cos33_Core ---> ";		
		fprintf(fpTest, "CML_cos33_Core ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
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


void TEST_CLASS_CML_TRIGO::test_tanh58(int doIt)
{
	if (doIt) 
	{
		/* Test case data declarations */
#ifdef TARGET_PLATFORM	
		#define TEST_CML_VECTOR_CSVOUT_CML_tanh58_1    "test_001_CML_tanh58_out_target.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_tanh58_2    "test_002_CML_tanh58_out_target.csv"
#else
		#define TEST_CML_VECTOR_CSVOUT_CML_tanh58_1    "test_001_CML_tanh58_out_msvc.csv"
		#define TEST_CML_VECTOR_CSVOUT_CML_tanh58_2    "test_002_CML_tanh58_out_msvc.csv"
#endif
	
		float32 f_angle;
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
		FILE *fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_tanh58_1, "w+");
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

		/* **********************************************************************
		   *                         Test case 1                                *
		   ********************************************************************** */			

#ifdef LINKED_LIST_PARSER
		for ( angle = -10; angle <= 10; angle += 0.001)
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		int dataIndex = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 1 \n";		
		fprintf(fpTest, "Test case 1 \n");
#endif /* #ifdef ENABLE_PROFILER */

		for ( angle = -10; angle <= 10; angle += 0.001)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */

			p_CsvDataOut.value[dataIndex] = CML_tanh58(angle);

#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_tanh58 ---> ";		
		fprintf(fpTest, "CML_tanh58 ---> ");
		std::cout << "Test case 1 ---> ";
		fprintf(fpTest, "Test case 1 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

			dataIndex++;
		}

		p_CsvDataOut.dataBufferSize = dataIndex;

		/* parse CSV values for expected results */
		i_CsvRetOut = CSV_WriteData_hex(fp, &p_CsvDataOut);
#endif

		fclose(fp);
		/* Checks on global data */
		check_global_data();

		/* **********************************************************************
		   *                         Test case 2                                *
		   ********************************************************************** */
			
		current_p_CsvDataOut = NULL;
		fp = fopen (TEST_CML_VECTOR_CSVOUT_CML_tanh58_2, "w+");
 
		/* Set global data */
		initialise_global_data();
		/* Set expected values for global data checks */
		initialise_expected_global_data();

#ifdef LINKED_LIST_PARSER
		p_CsvDataOut = NULL;
		for ( f_angle = -1000; f_angle <= 1000; f_angle += 1)
		{
			csv_data_float_t *temp_p_CsvDataOut = NULL;
			temp_p_CsvDataOut =(csv_data_float_t *) malloc(sizeof(csv_data_float_t));
			temp_p_CsvDataOut->value = (float32 *)malloc(sizeof(float32));
			temp_p_CsvDataOut->len = sizeof(float32);
			*(temp_p_CsvDataOut->value) = CML_tanh58(f_angle);
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
		i_CsvRetOut = CSV_WriteData_hex(fp, p_CsvDataOut);

		while(p_CsvDataOut != NULL)
		{
			csv_data_float_t *temp_p_CsvDataOut_free = NULL;
			temp_p_CsvDataOut_free = p_CsvDataOut;
			p_CsvDataOut = p_CsvDataOut->next;
			free(temp_p_CsvDataOut_free);
		}
#else
		dataIndex = 0;
		float32 rel_err_tanh =0;
		float32 max_err_tanh = 0;
		float32 input_err_tanh = 0;

#ifdef ENABLE_PROFILER
		std::cout << "Test case 2 \n";		
		fprintf(fpTest, "Test case 2 \n");
#endif /* #ifdef ENABLE_PROFILER */
		for ( f_angle = -1000; f_angle <= 1000; f_angle += 1)
		{			
			p_CsvDataOut.value = data_log_buffer;
			p_CsvDataOut.len = sizeof(float32);
			float32 ref_tanh_out = tanh(f_angle);
			float32 test_tanh_out ;

#ifdef ENABLE_PROFILER
		start_clock = get_clock();
#endif /* #ifdef ENABLE_PROFILER */
			
			test_tanh_out = CML_tanh58(f_angle);
			p_CsvDataOut.value[dataIndex]  = test_tanh_out;
#ifdef ENABLE_PROFILER
		stop_clock = get_clock();			
#endif /* #ifdef ENABLE_PROFILER */

#ifdef ENABLE_PROFILER
		std::cout << "CML_tanh58 ---> ";		
		fprintf(fpTest, "CML_tanh58 ---> ");
		std::cout << "Test case 2 ---> ";
		fprintf(fpTest, "Test case 2 ---> ");

		total_cycles = stop_clock - start_clock - overhead;
		check__PrintValue_to_console(f_angle);
		check__PrintValue_to_File(f_angle, fpTest);
		std::cout << "\t";	
		fprintf(fpTest, "\t");
		check__PrintValue_to_console(total_cycles);
		check__PrintValue_to_File(total_cycles, fpTest);
		std::cout << "\n";	
		fprintf(fpTest, "\n");
#endif /* #ifdef ENABLE_PROFILER */

		
			float32 abs_err_tanh = abs(ref_tanh_out - test_tanh_out);
			rel_err_tanh = abs(abs_err_tanh/ref_tanh_out);
			if (rel_err_tanh >= max_err_tanh)
			{
				max_err_tanh = rel_err_tanh;
				input_err_tanh = angle;
			}

			dataIndex++;
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

/*****************************************************************************/
/* End of test script                                                        */
/*****************************************************************************/
